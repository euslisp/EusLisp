/* 
 * 2003-
 * collector.c : R.Hanai
 * parallel root scanning, concurrent snapshot collector 
 * with return barrier for eulisp
 *
 * memo
 * BUGS: newpgcstack(), gc request from mutators.
 * NEED IMPROVEMENT: 
 *       memory barrier instructions
 *       heap expansion
 *       write-barriers (copyobj() etc.)
 *         => remove checks when read/write the mark-bitmap.
 *       collector-thread controll
 *       allocator's(heap management) pausing times
 *       polling / scanning other threads' stacks
 *       mutexes => real-time locks
 *       make thr_self() faster
 *       
 *       lock and unlock in insert_local_roots have no need
 *
 *       <how to start GC cycles>
 *       <write barrier>
 *       collector mutator
 *       signal => in handler (set gcreq_flag)
 *                 -> return and scan_my_roots() after assignment
 *       scan_global_roots()
 *
 *       <return barrier>
 *       may be OK if returns as follows
 *       recover sp -> recover bp -> check_return_barrier 
 *
 *       <stack manipulation>
 *       pop is OK, 1 useless object may be took as alive
 *
 *       <problematic functions>
 *       bindspecial: increment stack collectively
 */

#include <sys/times.h>
#include "eus.h"
#include <sys/param.h>
#include "time.h"
#include "rgc_utils.h"
#include "xccmem.h"

#ifdef __ART_LINUX
#include <linux/art_task.h>
#endif

extern struct {
  char using;
  mutex_t *lock;
  thread_t tid;
} thread_table[]; /* defined in "mthread_posix.c" */

struct _gc_data gc_data;
barrier_t startup_barrier;

//#define GCDEBUG
#undef GCDEBUG
#ifdef GCDEBUG
static int white_cells, black_cells, free_cells;
#endif

#ifdef __PROFILE_GC
static int gctime = 0;
int allocd_words = 0;
#endif
unsigned gs, ge;

static void do_scan_roots();
static void init_sync_data();
static void insert_local_roots(int);

#define gcpush(v) (*lgcsp++=((pointer)v))
#define gcpop() (*--lgcsp)

extern char *minmemory;

void do_mark_a_little(register pointer p)
{
  extern _end();
  register int i, s;
  register bpointer bp;
  register pointer p2;
  register pointer *lgcsp = collector_stack;
  register pointer *gcstack = collector_stack;

  goto start_mark;

 markloop:
  if(lgcsp <= gcstack) return;
  p = gcpop();

 start_mark:
  /* p may be an immediate */
  if(!ispointer(p)) goto markloop;
  //if(!ispointer(p) || !p){ p = gcpop(); goto markloop; }

  /* these checks aren't normally needed, 
     since this is not conservative collector */
#ifndef Cygwin
  if((int)p < (int)_end) goto markloop;
#endif

  if(maxmemory < (char *)p) goto markloop;
  if((char *)p < minmemory) goto markloop;

  /* Here, p is a pointer to a live object */
  bp = bpointerof(p);

  if(blacked(bp)) goto markloop; /* already marked */

  markon(bp); /* mark it first to avoid endless marking */

  if(pisclosure(p)){
    /*
      if (p->c.clo.env1>minmemory && p->c.clo.env1<maxmemory)
      fprintf(stderr, "Mark: closure %x's env1 points into heap %x\n", 
      p, p->c.clo.env1);
      if (p->c.clo.env2>minmemory && p->c.clo.env2<maxmemory)
      fprintf(stderr, "Mark: closure %x's env2 points into heap %x\n", 
      p, p->c.clo.env2);
    */
    goto markloop; /* avoid marking contents of closure */
  }
  if(bp->h.elmtype == ELM_FIXED){ /* contents are all pointers */
    s = buddysize[bp->h.bix & TAGMASK] - 1;

    if(s > 300){
      printf ("do_mark: too big object s=%d, header=%x at %x\n", s, bp->h,
	      bp);
      goto markloop;
    }
    while(lgcsp + s > collector_stacklimit){
      pnewgcstack(lgcsp);
      gcstack = collector_stack;
      lgcsp = collector_sp;
    }
    for(i = 0; i < s; i++){
      p2 = p->c.obj.iv[i];
      if(ispointer(p2))
	gcpush(p2);
    }
    goto markloop;
  }
  else if(bp->h.elmtype == ELM_POINTER){ /* varing number of pointers */
    s = buddysize[bp->h.bix & TAGMASK] - 2;
    while (lgcsp + s > collector_stacklimit){
      pnewgcstack(lgcsp);
      gcstack = collector_stack;
      lgcsp = collector_sp; /* 961003 kagami */
    }
    for(i = 0; i < s; i++){
      p2 = p->c.vec.v[i];
      if(ispointer(p2))
	gcpush(p2);
    }
    goto markloop;
  }
  else{ 
    goto markloop;
  }
}

void pmark()
{
  register int i, pcount = 0;
  register context *ctx;
  register pointer p;

  for(i = 0; i < MAXTHREAD; i++)
    if(euscontexts[i]){
      ctx = euscontexts[i];
      while(ctx->gsp > ctx->gcstack){
	p = pgcpop();
	do_mark_a_little(p);
      }
    }
  
  mutex_lock(&pstack_lock);
#ifdef NOTICE_CHECK
  pstack_max = psp - pstack;
#endif
  while(psp > pstack){
#ifdef COLLECTCACHE
#define COLCACHE 10
    int i, ii;
    pointer array[COLCACHE];
    for(i = 0; i < COLCACHE; i++){
      array[i] = pointerpop();
      if(psp > pstack)
	continue;
      break;
    }
    pcount = pcount + COLCACHE;
    mutex_unlock(&pstack_lock);
    for(ii = 0; ii < i; ii++){
      do_mark_a_little(array[ii]);
    }
    mutex_lock(&pstack_lock);
#else
    p = pointerpop();
    pcount++;
    mutex_unlock(&pstack_lock);
    do_mark_a_little(p);
    mutex_lock(&pstack_lock);
#endif
  }
  mutex_unlock(&pstack_lock);

#ifdef NOTICE_CHECK_EXP
  /* NOTICE_CHECK Log output */
  fprintf (stderr, "pstack_max:%d\n", pstack_max);
  fprintf (stderr, "pstack_hitcount:%d:%d\n", pstack_count,
	   pstack_totalcount);
  /*  fprintf(stderr,"pstack_ave:%f\n",pstack_ave); */
#endif
}

int reclaim(bpointer p)
{
  register int rbix, stat;
  register pointer s;

  s = makepointer(p);
  if(pisfilestream(s)){
    if(!isint (s->c.fstream.fname) && s->c.fstream.direction != NIL){
      if(s->c.fstream.fd == makeint (0)
	 || s->c.fstream.fd == makeint (1)){
	fprintf(stderr, ";; gc! bogus stream at %x fd=%d\n",
		(int) s, intval (s->c.fstream.fd));
      }else if((closestream (s) == 0) && debug)
	fprintf (stderr,
		 ";; gc: dangling stream(address=%x fd=%d) is closed\n",
		 (int) s, intval (s->c.fstream.fd));
    }
  }
  p->h.cix = -1; /* free tag */
  rbix = p->h.bix & TAGMASK;

  mutex_lock(&alloc_lock);

  p->b.nextbcell = buddy[rbix].bp;
  buddy[rbix].bp = p;
  buddy[rbix].count++;

  freeheap += buddysize[rbix];
  sweepheap += buddysize[rbix];

  mutex_unlock(&alloc_lock);
  return 0;
}

/* the cell pointed by 'p' must not be marked */
/* mergecell kindly returns next uncollectable cell address */
static bpointer mergecell(register bpointer p, int cbix)
{
  register bpointer np, p2;

  np = nextbuddy(p);
  while(p->h.b == 0 && ((int) (p->h.bix & TAGMASK)) < cbix)
    {
      //      if(colored(np))
      if(blacked(np) || np->h.cix == -1) return np;

      if(np->h.nodispose == 1) return np;

      p2 = mergecell(np, cbix);	/* merge neighbor cell */
      if(np->h.b == 1){	/* can be merged */
	p->h.b = p->h.m; /* merge them into bigger cell */
	p->h.m = np->h.m;
	p->h.bix++;
	np = p2;
#ifdef GCDEBUG
	white_cells++;
#endif
      }else{
	reclaim(np);
	return p2;
      }
    }
  return np;
}

static void sweep(register struct chunk *cp, register int gcmerge)
{
  register int s;
  register bpointer p, np, tail;

  s = buddysize[cp->chunkbix];
  p = &cp->rootcell;
  tail = (bpointer)((int)p + (s << 2));
  while(p < tail){
    if(p->h.cix == -1){ /* free object */
#ifdef GCDEBUG
      free_cells++;
#endif
      p = nextbuddy(p);
      continue;
    }
    if(blacked(p)){ /* (possibly) live object */
#ifdef GCDEBUG
      black_cells++;
#endif
      markoff(p);
      p = nextbuddy(p);
      continue;
    }
    if(gcmerge > freeheap){ /* reclaim and no merge */
#ifdef GCDEBUG
      white_cells++;
#endif
      np = nextbuddy(p);
      reclaim(p);
      p = np;
    }else{ /* reclaim and merge *//* update free buddy list */
      np = mergecell(p, cp->chunkbix);
      reclaim(p);
      p = np;
    }
  }
}

void psweep(){
  context *ctx;
  register struct chunk *chp;
  register int i, gcmerge;
  numunion nu;

  ctx = euscontexts[thr_self ()];
  gcmerge = totalheap * min(1.0, fltval(speval(GCMARGIN)))
    * max(0.1, fltval(speval(GCMERGE))); 
  /* default: GCMERGIN=0.25, GCMERGE=0.2 
     ==> no merge if heap occupancy rate is over 95% */

#ifdef GCDEBUG
  white_cells = black_cells = free_cells = 0;
#endif

 i = 0; 
  for(chp = chunklist; chp != 0; chp = chp->nextchunk){
    sweep(chp, gcmerge);
    i++;
  }

#ifdef GCDEBUG
  fprintf(stderr, "white = %d, black = %d, free = %d\n", 
	  white_cells, black_cells, free_cells);
#endif
}

#ifdef __USE_SIGNAL
static void send_root_insertion_signals()
{
  int i;
  thread_t self = pthread_self();

  for (i = 0; i < MAXTHREAD; i++)
    if (!pthread_equal(thread_table[i].tid, self) && euscontexts[i]) {
      if (pthread_kill(thread_table[i].tid, SIGUSR1) != 0) {
	    perror("pthread_kill");
      }
    }
}
#endif

void init_rgc(){
  void collect();
  thread_t gc_thread;
  active_mutator_num = 1;
  gc_region_sync = 0;
  startup_barrier = barrier_init(2); /* mainthread and collector thread */
  gc_phase = PHASE_NOGC;
  gc_wakeup_cnt = gc_cmp_cnt = 0;
#ifdef __USE_POLLING
  gc_request_flag = 0;
#endif
  init_sync_data();

  initmemory_rgc(); /* initialize object heap. define in "eus.c" */
  allocate_bit_table(); /* allocate mark bit table */

  collector_stack = collector_sp = 
    (pointer *)malloc(sizeof(pointer) * DEFAULT_MAX_RGCSTACK);
  collector_stacklimit = collector_stack + DEFAULT_MAX_RGCSTACK - 10;
 
  thr_create(0, 0, collect, 0, 0, &gc_thread);
  barrier_wait(startup_barrier);
}

static void scan_global_roots()
{
  int i;
  pointerpush(sysobj);
  pointerpush(pkglist);
  for(i = 0; i < MAXCLASS; i++){
    if(ispointer(classtab[i].def)){
      pointerpush (classtab[i].def);
    }
  }
}

static void scan_local_roots(int i)
{
  register pointer *p;
  register bpointer q;
  register context *ctx = euscontexts[i];

  pgcpush(ctx->threadobj);
  pgcpush(ctx->specials);
  
  q = bpointerof(ctx->lastalloc);
  /* garbage might be pushed 
   * if lastalloc doesn't correctly point to the start address of an object */
  if(q && ispointer(q)) pgcpush(ctx->lastalloc);

#ifdef __RETURN_BARRIER
  {
    pointer *frame_base, *p;

    //DPRINT2("start scanning current frame: %d ",i);
    mutex_lock(&ctx->rbar.lock); /* <-- this lock wouldn't be needed */

    if(ctx->callfp != NULL) 
      frame_base = (pointer *)ctx->callfp;
    else 
      frame_base = ctx->stack;

    for(p = ctx->vsp - 1; p >= frame_base; p--){
      if((((int)(*p) & 3) == 0) 
	 && ((ctx->stack > (pointer *)*p) 
	     || ((pointer *)*p > ctx->stacklimit)))
	pgcpush(*p);    
    }

    if(frame_base == ctx->stack){
      ctx->rbar.pointer = NULL;
    }else 
      ctx->rbar.pointer = frame_base;
    mutex_unlock(&ctx->rbar.lock); /* <-- this lock wouldn't be needed */
    //DPRINT1("scanning current frame completed");
  }

#else /* original snapshot gc */

  /* push roots in thread's stack */
  for(p = ctx->vsp - 1; p >= ctx->stack; p--){
    // for(p = ctx->stack; p < ctx->vsp; p++){
    if((((int)(*p) & 3)==0) 
       && ((ctx->stack>(pointer *)*p) 
	   || ((pointer *)*p>ctx->stacklimit)))
      pgcpush(*p);
  }
#endif 
}

#if 0
static void scan_suspending_thread_roots()
{
  int id, c;
  for(id = 0; id < MAXTHREAD; id++){
    if(thread_table[id].using){
      mutex_lock(&mut_stat_table[id].lock); 
      if(mut_stat_table[id].stat == 0x3){ /* 'suspended' & 'need_scan' */
        mut_stat_table[id].stat = 0x5; /* 'suspended' & 'scanning' */
        mutex_unlock(&mut_stat_table[id].lock); 
        scan_local_roots(id);
        finish_access_before_read();
        do{
          c = read_volatile_int(frame_scan_sync);
        }while(cas_int(frame_scan_sync, c, c + 1));
        mutex_lock(&mut_stat_table[id].lock);
        mut_stat_table[id].stat = 0x1; /* 'suspended' */
      }
      mutex_unlock(&mut_stat_table[id].lock); 
    }
  }
}
#endif

#ifdef __RETURN_BARRIER
#define INSERT_UNIT 4 /* 2 or 4 will be good */

static void scan_remaining_roots()
{
  int i, local_root_count, inserted_root_count;
  static char idx[MAXTHREAD];

  local_root_count = 0;

  for(i = 0; i < MAXTHREAD; i++){
    if (euscontexts[i] && euscontexts[i]->rbar.pointer){
      idx[local_root_count] = i;
      local_root_count++;
    }
  }

  inserted_root_count = local_root_count;
  
  do{
    for(i = 0; i < local_root_count; i++){
      context *ctx;
      register pointer *p;
      int counter, tid;

      tid = idx[i];
      ctx = euscontexts[tid];
      if((ctx)->rbar.pointer == NULL) continue;
      
      mutex_lock(&((ctx)->rbar.lock));
      //DPRINT2("scheduler inserting thread : %d's local roots", i);
      p = (ctx)->rbar.pointer - 1;
      counter = INSERT_UNIT;

      while(1){
	if(p < ctx->stack) break;
	if((((int)(*p) & 3) == 0)
	   && ((ctx->stack > (pointer *)*p)
	       || ((pointer *)*p > ctx->stacklimit)))
	  pgcpush(*p);
	p--;
	counter--;
	if(counter == 0) break;
      }
      (ctx)->rbar.pointer = p + 1;
	  
      if(p < ctx->stack){
	(ctx)->rbar.pointer = NULL;
	inserted_root_count--;
      }
      mutex_unlock(&(ctx)->rbar.lock);
    }
  }
  while(inserted_root_count != 0);
}
#endif /* __RETURN_BARRIER */


void notify_gc()
{
  int id, phase, c;

  // suppose that we have alloc_lock
  /* reset synchronization variables */
  lock_collector;
//  DPRINT1("gc started.\n");
  gc_point_sync = 0;
  phase = ri_core_phase;
#ifdef __USE_POLLING
  for(id = 0; id < MAXTHREAD; id++){
    if(thread_table[id].using){
      mutex_lock(&mut_stat_table[id].lock);    
      mut_stat_table[id].stat |= 0x2; /* set 'need_scan' flag */
      if(mut_stat_table[id].stat & 0x1){ /* 'suspended'? */
        do{
          c = gc_point_sync;
        }while(cas_int(gc_point_sync, c, c + 1));
      }
      mutex_unlock(&mut_stat_table[id].lock);    
    }
  }
#endif
#ifdef __USE_SIGNAL
  send_root_insertion_signals();
#else /* __USE_POLLING */
  gc_request_flag = 1;
#endif
  unlock_collector;
  do{
    c = gc_point_sync;
  }while(cas_int(gc_point_sync, c, c + 1));

  if(gc_point_sync + gc_region_sync < active_mutator_num){
    sched_yield(); // nanosleep(0) might be better
  }else{
    lock_collector;
    if(phase == ri_core_phase){
      do_scan_roots(); 
    }
    unlock_collector;
  }
  
  /* wait until root scanning(core) is finished */
  mutex_lock(&ri_end_lock); 
  while(ri_core_phase == phase) 
    cond_wait(&ri_end_cv, &ri_end_lock); 
  mutex_unlock(&ri_end_lock);
}


/* suppose we have collector lock */
static void do_scan_roots()
{ 
  int tid;

//  gs = current_utime();
  scan_global_roots();
  for(tid = 0; tid < MAXTHREAD; tid++){
    if(euscontexts[tid]){
      scan_local_roots(tid);
      mutex_lock(&mut_stat_table[tid].lock);
      mut_stat_table[tid].stat = 0x0; /* 'running' */
      mutex_unlock(&mut_stat_table[tid].lock);
    }
  }
//  ge = current_utime();
//  fprintf(stderr, "stopped: %d\n", ge - gs);

  gc_request_flag = 0;
  gc_phase = PHASE_MARK; /* write barriers get activated */
  ri_core_phase = 1 - ri_core_phase; /* release other mutator threads */
  cond_broadcast(&ri_end_cv);
  gc_wakeup_cnt++; /* now, we release collector threads */
  cond_broadcast(&gc_wakeup_cv);
}


static void wait_until_next_gc_cycle()
{
  /*
  numunion nu;
  int thr;
  double threshold;
  static long used;

  used += pastfree + newheap + sweepheap - freeheap;
  newheap = 0;
  threshold = max(DEFAULT_GC_THRESHOLD, fltval(speval(GCMARGIN)));
  thr = (int)((double)totalheap * threshold);
  used = freeheap;
  while(freeheap > thr && gc_counter >= gc_request_counter){
    nanosleep(&treq, NULL); // take a rest
  }
  used = used - freeheap;
  pastfree = freeheap;
  */

  /*
  mutex_lock(&gc_state_lock);
  while(gc_counter >= gc_request_counter){
    cond_wait(&wake_up_gc_thread_cv, &gc_state_lock);
  }
  mutex_unlock(&gc_state_lock);
  */
}


void collect()
{
  int i;
  unsigned s, e;
#ifdef __PROFILE_GC
  int tmp_free;
  struct tms buf1, buf2;
  reset_utime(); /* for rdtsc */
#endif

  /* synchronize with mainthread */
  barrier_wait(startup_barrier);

  /* initialize data used by collector */
//  init_collector();

#ifdef __USE_MARK_BITMAP
  clear_bit_table();
#endif

#ifdef __PROFILE_GC
//  times(&buf1);
#endif
  /* gc main loop */
  for(;;){ 

    //sweepheap = 0;
    // mutex_lock(&qthread_lock); /* delay thread creation *//* needed? */

    lock_collector;
    while(gc_cmp_cnt == gc_wakeup_cnt){
      cond_wait(&gc_wakeup_cv, &collector_lock);
    }
    unlock_collector;
#ifdef __USE_POLLING
    /* push roots of all threads in gc-regions */
    /* this can be done lazily, maybe */
//    scan_suspending_thread_roots(); /* this is done by "do_scan_roots()" */
#endif

#ifdef __RETURN_BARRIER
    scan_remaining_roots();
#endif
    //mutex_unlock(&qthread_lock); /* delay thread creation */

    /* mark phase */
    pmark();

    lock_collector;
    gc_phase = PHASE_SWEEP; 
    unlock_collector;

    /* sweep phase */
    psweep();

    /* gc epilogue */
#ifdef __USE_MARK_BITMAP
    clear_bit_table();
#endif

    lock_collector;
    gc_phase = PHASE_NOGC;
    if(gc_cmp_cnt < gc_wakeup_cnt)
    gc_cmp_cnt++;
    unlock_collector;

#ifdef __PROFILE_GC
//    times(&buf2);
//    gctime = buf2.tms_utime+buf2.tms_stime-buf1.tms_utime-buf1.tms_stime;
//    fprintf(stderr, "gc thread time = %d\n", gctime*1000/HZ);
//    fprintf(stderr, "freeheap=%d\n", freeheap*4);
//    tmp_free = freeheap;
#endif

#ifdef __ALWAYS_COLLECTING
    /* go on to the next gc cycle */
#else
//    wait_until_next_gc_cycle();
#endif

//    DPRINT3("took %d micro, not gc consump_rate %f", 
//            e-s, (float)(tmp_free-freeheap)/(e-s));
  }
  
  /* never come here */

}


#ifdef __EAGER_GC_CONTROL
static int change_collector_thread_sched_policy(int t_sect_length)
{
#ifdef __ART_LINUX
  if(art_enter(ART_PRIO_MAX, ART_TASK_PERIODIC, t_sect_length) == -1){
    DPRINT1("collector error: art_enter");
    return -1;    
  }
#else /* LINUX */
#endif
  return 0;
}
static int restore_collector_thread_sched_policy()
{
#ifdef __ART_LINUX
  if(art_exit() == -1){
    DPRINT1("collector error: art_exit");
    return -1;    
  }
#else /* LINUX */
#endif
  return 0;
}
#endif /* __EAGER_GC_CONTROL */

#ifdef __USE_POLLING
void enter_gc_region(int id)
{
  int c;
  mutex_lock(&mut_stat_table[id].lock);    
  mut_stat_table[id].stat |= 0x1; /* set 'suspended' flag */
  if(mut_stat_table[id].stat & 0x2){ /* 'need_scan'? */
    do{
      c = gc_region_sync;
    }while(cas_int(gc_region_sync, c, c + 1));
  }
  mutex_unlock(&mut_stat_table[id].lock);    
}

void exit_gc_region(int id)
{
  mutex_lock(&mut_stat_table[id].lock);
  if(mut_stat_table[id].stat & 0x2){ /* 'need_scan'? */
    mut_stat_table[id].stat = 0x4; /* set 'scanning' and clear 'need_scan' */
    mutex_unlock(&mut_stat_table[id].lock);
//    insert_my_roots();
  }else{
    mut_stat_table[id].stat &= 0x0; /* clear 'suspended' flag */
    mutex_unlock(&mut_stat_table[id].lock);
  }
}

#endif /* __USE_POLLING */

/* initialize data for syncronization */
static void init_sync_data()
{
  int i;
  mutex_init(&pstack_lock, NULL);
  mutex_init(&collector_lock, NULL);
  cond_init(&gc_wakeup_cv, NULL);
  mutex_init(&ri_end_lock, NULL);
  cond_init(&ri_end_cv, NULL);
  mutex_init(&gc_state_lock, NULL);
  for(i = 0; i < MAXTHREAD; i++){
    mutex_init(&mut_stat_table[i].lock, NULL);
  }
}

/**********************************************************
  mutator interface routines
*********************************************************/

void request_gc(){
  notify_gc();
}


/* wait until this gc cycle ends */
void wait_until_gc_cycle_ends(){
#if 0
  mutex_lock(&gc_state_lock);
  while(gc_counter < gc_request_counter){
    cond_wait(&gc_end_cv, &gc_state_lock);
  }
  mutex_unlock(&gc_state_lock);
#endif
}

#ifdef __USE_POLLING
void scan_roots()
{
  int c;
  int myid = thr_self();
  int phase = ri_core_phase;

  do{
    c = gc_point_sync;
  }while(cas_int(gc_point_sync, c, c + 1));

  if(gc_point_sync + gc_region_sync < active_mutator_num){
    sched_yield(); // nanosleep(0) might be better
  }else{
    lock_collector;
    if(phase == ri_core_phase)
      do_scan_roots(); 
    unlock_collector;
  }
  
  /* wait until root scanning(core) is finished */
  mutex_lock(&ri_end_lock); \
  while(ri_core_phase == phase) \
    cond_wait(&ri_end_cv, &ri_end_lock); \
  mutex_unlock(&ri_end_lock);
  
  return;
}

/* function-version polling code */
int check_gc_request()
{
  if(!gc_request_flag) 
    return 0;
  scan_roots();
  return 1;
}
#endif

#ifdef __USE_SIGNAL
/*
 * it is not recommended to use pthreads tools in signal handlers
 * (mutex, conditional variables,...)
 */
void sighandler(int x)
{
  int idx;
  DPRINT1("start root insersion");
  notify_ri_start();
  idx = thr_self();
  insert_local_roots(thr_self());
  barrier_wait(end_ri_barrier);
  DPRINT1("mutator restart");
}
#endif


pointer pstack[PMAXSTACK];
volatile pointer *psp = pstack;
pointer *pstacklimit = pstack + PMAXSTACK;
mutex_t pstack_lock;

/***********************************************************
    barrier-synchronization functions
***********************************************************/
barrier_t barrier_init(int n_clients)
{
  barrier_t barrier = (barrier_t) malloc(sizeof(struct barrier_struct));
  if(barrier != NULL){
    barrier->n_clients = n_clients;
    barrier->n_waiting = 0;
    barrier->phase = 0;
    mutex_init(&barrier->lock, NULL);
    cond_init(&barrier->wait_cv, NULL);
  }
  return barrier;
}

void barrier_reset(barrier_t barrier, int n_clients)
{
  /* called when active_mutator_num was changed */
  /* this implementation is not good */
  barrier->n_clients = n_clients;
}

void barrier_destroy(barrier_t barrier)
{
  mutex_destroy(&barrier->lock);
  cond_destroy(&barrier->wait_cv);
  free(barrier);
}

void barrier_wait(barrier_t barrier)
{
  int my_phase;
  mutex_lock(&barrier->lock);
  my_phase = barrier->phase;
  barrier->n_waiting++;
  if(barrier->n_waiting == barrier->n_clients){
    barrier->n_waiting = 0;
    barrier->phase = 1 - my_phase;
    cond_broadcast(&barrier->wait_cv);
  }
  while(barrier->phase == my_phase){
    cond_wait(&barrier->wait_cv, &barrier->lock);
  }
  mutex_unlock(&barrier->lock);
}

/***********************************************************
  other functions
***********************************************************/

unsigned int allocate_heap(unsigned int req_words)
{
  int i, k; 
  unsigned int rem_words = req_words;

  while(buddysize[MAXBUDDY-1] <= rem_words){
    k = newchunk(MAXBUDDY-1);
    rem_words -= buddysize[k];
  }
  for(i = MAXBUDDY - 2; i >= 20/* or DEFAULTCHUNKINDEX */; i--){
    if(buddysize[i] < rem_words){
      k = newchunk(i);
      rem_words -= buddysize[k];
    }
  }
  return req_words - rem_words;
}

extern long long values[];

pointer RGCCOUNT(register context *ctx, int n, pointer argv[])
{
    ckarg(0);
    return makeint(gc_counter);
}

pointer RGC_MUTTIME(register context *ctx, int n, pointer argv[])
{
    struct tms buf;
    ckarg(0);
    times(&buf);
    return makeint((buf.tms_utime + buf.tms_stime) * 1000/HZ );
}

#ifdef __PROFILE_GC
pointer RGCALLOCATED(register context *ctx, int n, pointer argv[])
{
    ckarg(0);
    return makeint(allocd_words);
}
#endif

void rgcfunc(register context *ctx, pointer mod)
{
    pointer p = Spevalof(PACKAGE);
    pointer_update(Spevalof(PACKAGE), syspkg);
    defun(ctx, "RGCCOUNT", mod, RGCCOUNT);
    defun(ctx, "RGCTIME", mod, RGC_MUTTIME);
    defun(ctx, "RGCALLOCATED", mod, RGCALLOCATED);
    pointer_update(Spevalof(PACKAGE), p);
}
