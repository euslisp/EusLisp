/* 
 * 2003-
 * collector.c : R.Hanai
 * parallel root scanning, concurrent snapshot garbage collector 
 * with return barrier
 *
 * memos
 * BUGS: 
 * FIXED: copyobj in leo.c
 * TODO:
 *       memory barrier instructions
 *       heap expansion function
 *       write-barriers (copyobj() etc.)
 *       memory management (BIBOP/Lazy Buddy/etc.)
 *       polling / how to scan stacks of suspending threads
 *       mutexes => real-time locks
 *       make thr_self() faster => caching ids.
 *       scan large objects incrementally.
 *       
 *       mark stack overflow
 *       parallel marking (scalability)
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

#if Linux
char *minmemory=(char *)1000000;
#endif
extern pointer K_DISPOSE;
#define MAXDISPOSE 256
static pointer dispose[MAXDISPOSE];
static int gcmerge, dispose_count;

extern struct {
  char using;
  mutex_t *lock;
  thread_t tid;
} thread_table[]; /* defined in "mthread_posix.c" */

struct _gc_data gc_data;
barrier_t startup_barrier;

#define GCDEBUG
//#undef GCDEBUG
#ifdef GCDEBUG
static int white_cells, black_cells, free_cells;
#endif

#ifdef __PROFILE_GC
static int gctime = 0;
int allocd_words = 0;
#endif

static void do_scan_roots();
static void init_sync_data();

#define gcpush(v, off) \
{ \
  lgcsp->addr = (pointer)v; \
  lgcsp->offset = off; \
  lgcsp++; \
}

static pnewgcstack(oldsp)
     register ms_entry *oldsp;
{
  register ms_entry *oldstack, *stk, *newstack, *newgcsp;
  long top, oldsize, newsize;

  oldstack=stk=collector_stack;
  oldsize=collector_stacklimit-oldstack;
  newsize=oldsize*2;
  top=oldsp-collector_stack;
  //  newgcsp=newstack=(pointer *)malloc(newsize * sizeof(pointer)+16);
  newgcsp=newstack=(ms_entry *)malloc(newsize * sizeof(ms_entry)+16);
  fprintf(stderr, "\n\x1b[1;31m;; extending pgcstack 0x%x[%d] --> 0x%x[%d] top=%x\x1b[0m\n",
	  oldstack, oldsize, newstack, newsize, top);
  while (stk<oldsp) *newgcsp++= *stk++;
  collector_stack=newstack;
  collector_stacklimit= &(collector_stack[newsize-10]);
  collector_sp = &(collector_stack[top]);
  cfree(oldstack);
}

static call_disposers()
{ int i;
 context *ctx=current_ctx;
 pointer p,a,curclass;
 /*if (debug) fprintf(stderr, ";; disposal call=%d\n", dispose_count);*/
 for (i=0; i<dispose_count; i++) {
   p=dispose[i];
   p->nodispose=0;
   a=(pointer)findmethod(ctx,K_DISPOSE,classof(p), &curclass); 
   if (debug) fprintf(stderr, ";; (send %x :dispose)\n", p);
   if (a!=NIL) csend(ctx,p,K_DISPOSE,0);
 }}

static struct _marking_state {
  int is_checking_pstack;
  int cur_mut_num;
} marking_state;

struct _sweeping_state sweeping_state;

static inline void go_on_to_sweep_phase()
{
  numunion nu;
  DPRINT2("mark->sweep: free rate = %lf", (double)freeheap / totalheap);
  gcmerge = totalheap * min(1.0, fltval(speval(GCMARGIN)))
    * max(0.1, fltval(speval(GCMERGE))); 
  /* default: GCMERGIN=0.25, GCMERGE=0.2 
     ==> no merge if heap occupancy rate is over 95% */
  dispose_count = 0; /* <= Is this O.K.? */

  sweeping_state.chp = chunklist;
  sweeping_state.p = &chunklist->rootcell;
  sweeping_state.tail = 
    (bpointer)((int)sweeping_state.p + (buddysize[sweeping_state.chp->chunkbix] << 2));
  gc_phase = PHASE_SWEEP; 
}

long marked_words = 0;

static int mark_a_little(int m_unit)
{
  extern _end();
  register ms_entry *lgcsp = collector_sp;
  register ms_entry *gcstack = collector_stack;
  register int credit = m_unit;
  unsigned int offset;
  register pointer p, p2;
  register bpointer bp;
  register int i, s;
  context *ctx;

 markloop:
  if(credit <= 0){ 
    /* write back the value of lgcsp */
  //fprintf(stderr, "GC stack size = %d\n", lgcsp - gcstack);
    collector_sp = lgcsp;
    marked_words -= m_unit - credit;
    return 1; /* still marking work is left */
  }
  if(lgcsp > gcstack){
    /* mark from mark stack */
//    lgcsp -= (sizeof(ms_entry)/sizeof(pointer));
    lgcsp--;
    p = lgcsp->addr;
    offset = lgcsp->offset;

  start_mark:
    if(offset == 0){
//      if(!ispointer(p)) goto markloop;  /* p may be an immediate */
      if(!ispointer(p) || !p) goto markloop;

      ASSERT((unsigned)p >= mingcheap);
      ASSERT((unsigned)p < maxgcheap);

      /* these checks aren't normally needed, 
         since this is not a conservative collector */
//      if((int)p < (int)_end) goto markloop;
//
      if(maxmemory < (char *)p) goto markloop;
//      if((char *)p < minmemory) goto markloop;
    }

    /* here, p is a pointer to a live object */
    bp = bpointerof(p);

    if(marked(bp)) goto markloop; /* already marked */
//    if(blacked(bp)) goto markloop; /* already marked */

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
        fprintf (stderr, "do_mark: too big object s=%d, header=%x at %x\n", 
		s, bp->h, bp);
        //goto markloop;
      }
      while(lgcsp + s > collector_stacklimit){
        pnewgcstack(lgcsp);
        gcstack = collector_stack;
        lgcsp = collector_sp;
      }
      credit -= (s + 1);
      for(i = 0; i < s; i++){
        p2 = p->c.obj.iv[i];
        if(ispointer(p2)) 
          gcpush(p2, 0);
      }
      goto markloop;
    } else if (bp->h.elmtype == ELM_POINTER) { /* varing number of pointers */
      s = buddysize[bp->h.bix & TAGMASK] - 2;
      while (lgcsp + s > collector_stacklimit) {
        pnewgcstack(lgcsp);
        gcstack = collector_stack;
        lgcsp = collector_sp; /* 961003 kagami */
      }
      credit -= (s + 2);
      for (i = 0; i < s; i++) {
        p2 = p->c.vec.v[i];
        if (ispointer(p2))
          gcpush(p2, 0);
      }
      goto markloop;
    } 

    credit -= buddysize[bp->h.bix & TAGMASK];
    goto markloop;

  } else {

  /* get another root */
  next_root:
    credit--;
    if (!marking_state.is_checking_pstack) {
      for (i = marking_state.cur_mut_num; i < MAXTHREAD; i++) {
        ctx = euscontexts[i];
        if (ctx) {
          if (ctx->gsp > ctx->gcstack) {
            p = *--(ctx->gsp);

            ASSERT((unsigned)p >= mingcheap);
            ASSERT((unsigned)p < maxgcheap);

            offset = 0;
            marking_state.cur_mut_num = i;
/*
  if(credit <= 0){ 
    // write back the value of lgcsp
    gcpush(p, 0);
    collector_sp = lgcsp;
    marked_words -= m_unit - credit;
    return 1; // still marking work is left
  }
          */
            goto start_mark;
          }
        }
      }
      marking_state.is_checking_pstack = 1;
      goto next_root;
    } else {
      mutex_lock(&pstack_lock);
      if(psp > pstack) {
#ifdef COLLECTCACHE /* this is not yet correctly implemented */
#define COLCACHE 10
        int i, ii;
        pointer array[COLCACHE];
        for (i = 0; i < COLCACHE; i++) {
          pointerpop(array[i]);
          if(psp > pstack)
        continue;
          break;
        }
        pcount = pcount + COLCACHE;
        mutex_unlock(&pstack_lock);
        for(ii = 0; ii < i; ii++){
//          mark_a_little(array[ii], 0);
        }
        mutex_lock(&pstack_lock);
#else
        pointerpop(p);
        offset = 0;
        mutex_unlock(&pstack_lock);
/*
  if (credit <= 0) { 
    // write back the value of lgcsp
    gcpush(p, 0);
    collector_sp = lgcsp;
    marked_words -= m_unit - credit;
    return 1; // still marking work is left
  }
  */
        goto start_mark;
#endif
      }
      mutex_unlock(&pstack_lock);
    }
  }

  /* marking finished, now we prepare for following sweeping */
  go_on_to_sweep_phase();
  return 0; 
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
  rw_rdlock(&gc_lock);

  p->b.nextbcell = buddy[rbix].bp;
  buddy[rbix].bp = p;
  buddy[rbix].count++;

  freeheap += buddysize[rbix];
  //  sweepheap += buddysize[rbix];

  rw_unlock(&gc_lock);
  mutex_unlock(&alloc_lock);
  return 0;
}

static int rgc_credit = 0;

/* the cell pointed by 'p' must not be marked */
/* mergecell kindly returns next uncollectable cell address */
static bpointer mergecell(register bpointer p, int cbix)
{
  register bpointer np, p2;

  np = nextbuddy(p);
  while (p->h.b == 0 && ((int) (p->h.bix & TAGMASK)) < cbix) {
//     if (colored(np)) return np;
//    if (marked(np)) return np;
    rgc_credit--;
    if (marked(np) || np->h.cix == -1) return np;
    if (np->h.nodispose == 1) return np;

    p2 = mergecell(np, cbix); /* merge neighbor cell */
    if (np->h.b == 1 && rgc_credit >= 0) { /* can be merged */
	  p->h.b = p->h.m; /* merge them into bigger cell */
      p->h.m = np->h.m;
      p->h.bix++;
      np = p2;
#ifdef GCDEBUG
      white_cells++;
#endif
    } else {
	  reclaim(np);
      return p2;
    }
  }
  return np;
}

/*
 * suppose that { sweeping_state.p, 
 *                sweeping_state.chp,
 *                sweeping_state.tail } are correctly set.
 */
static int sweep_a_little(int gcmerge, int s_unit)
{
  register struct chunk *chp;
  register bpointer p, np, tail;
  
  rgc_credit = s_unit;
  /* restore the state of sweeper */
  chp = sweeping_state.chp;
  p = sweeping_state.p;
  tail = sweeping_state.tail;
  
  if (p == NULL) {
    goto next_chunk;
  }
  //ASSERT( tail && chp );

cont_sweep:
  /* continue sweeping */
  while (p < tail) {
    if (rgc_credit <= 0) {
      sweeping_state.p = p;
      sweeping_state.tail = tail;
      return 1;
    }
//#ifndef __USE_MARK_BITMAP
//    sweeping_state.p = p;
//#endif
    rgc_credit--;
    if (p->h.cix == -1) { /* free object */
#ifdef GCDEBUG
      free_cells++;
#endif
      p = nextbuddy(p);
      continue;
    }
    if (marked(p)) { /* (possibly) live object */
//    if (blacked(p)) { /* (possibly) live object */
#ifdef GCDEBUG
      black_cells++;
#endif
      markoff(p);
      p = nextbuddy(p);
      continue;
    }
    if (p->h.nodispose == 1) {
      if(dispose_count >= MAXDISPOSE)
	fprintf(stderr, "no more space for disposal processing\n");
      else
	dispose[dispose_count++] = makepointer(p);
      p = nextbuddy(p);
    }
    if (gcmerge > freeheap) { /* reclaim and no merge */
#ifdef GCDEBUG
      white_cells++;
#endif
      np = nextbuddy(p);
      reclaim(p);
      p = np;
    } else { /* reclaim and merge *//* update free buddy list */
      np = mergecell(p, chp->chunkbix);
      reclaim(p);
      p = np;
    }
  }
  
next_chunk:
  chp = sweeping_state.chp->nextchunk;
  if (chp == NULL) {
    DPRINT2("sweeping finished: free rate = %lf", (double)freeheap / totalheap);
    DPRINT2("white: %d black: %d free: %d", white_cells, black_cells, free_cells);
    gc_phase = PHASE_EPILOGUE;
    return 0; /* sweeping finished */
  }
  sweeping_state.chp = chp;
  p = &chp->rootcell;
  tail = (bpointer)((int)p + (buddysize[chp->chunkbix] << 2));
  goto cont_sweep;

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
  unsigned int gc_thread;

  active_mutator_num = 1;
  gc_region_sync = 0;
  startup_barrier = barrier_init(2); /* mainthread and collector thread */
  gc_phase = PHASE_NOGC;
  ri_core_phase = 0;
  mut_stat_phase = 0x2;
  gc_wakeup_cnt = gc_cmp_cnt = 0;
#ifdef __USE_POLLING
  gc_request_flag = 0;
#endif
  init_sync_data();
  initmemory_rgc(); /* initialize object heap. define in "eus.c" */
  init_utils();
#ifdef __USE_MARK_BITMAP
  allocate_bit_table(); /* allocate mark bit table */
  clear_bit_table();
#endif

  collector_stack = collector_sp = 
    (ms_entry *)malloc(sizeof(ms_entry) * DEFAULT_MAX_RGCSTACK);
  collector_stacklimit = collector_stack + DEFAULT_MAX_RGCSTACK - 10;
   
#ifdef __GC_SEPARATE_THREAD
  thr_create(0, 0, collect, 0, 0, &gc_thread);
  barrier_wait(startup_barrier);
#endif
}

static pointer rgc_classtable = NULL;

void rgc_add_to_classtable(pointer newclass) {
  static int clsidx = 0;
  int i;
  /* allocate class table for marking */
  if (rgc_classtable == NULL) {
    rgc_classtable = 
      rgc_alloc((MAXCLASS + 1), ELM_POINTER, vectorcp.cix, MAXCLASS + 1);
    rgc_classtable->c.vec.size = makeint(MAXCLASS);
    for (i = 0; i < MAXCLASS; i++)
      rgc_classtable->c.vec.v[i] = NIL;
  }
  rgc_classtable->c.vec.v[clsidx++] = newclass;
}

static void scan_global_roots()
{
  int i;
  pointerpush(sysobj);
  pointerpush(pkglist);
  /* minimize scanning time for class table */
  pointerpush(rgc_classtable);
  /*
  for(i = 0; i < MAXCLASS; i++){
    if(ispointer(classtab[i].def)){
      pointerpush (classtab[i].def);
//      ASSERT((unsigned)(classtab[i].def == 0) || 
//      (unsigned)(classtab[i].def) >= mingcheap);
//      ASSERT((unsigned)(classtab[i].def) < maxgcheap);
    }
  }
  */
}

static void scan_local_roots(int i)
{
  register pointer *p;
  register bpointer q;
  register context *ctx = euscontexts[i];

  pgcpush(ctx->threadobj);
  pgcpush(ctx->specials);
  
  q = bpointerof(ctx->lastalloc);
  if (q && ispointer(q)) {
      pgcpush(ctx->lastalloc);
      ASSERT((unsigned)q >= mingcheap);
      ASSERT((unsigned)q < maxgcheap);
  }

#ifdef __RETURN_BARRIER
  {
    pointer *frame_base, *p;

    //DPRINT3("start scanning current frame: %d ",i);
    mutex_lock(&ctx->rbar.lock); /* <-- this lock wouldn't be needed */

    if (ctx->callfp != NULL) 
      frame_base = (pointer *)ctx->callfp;
    else 
      frame_base = ctx->stack;

    for (p = ctx->vsp - 1; p >= frame_base; p--) {
        /*
         * stack frame can contain
         * 1, immediates
         * 2, references to the words in this LISP stack (static links, dynamic links)
         * 3, this would be a bug: references to the words in a native stack.
         *    (jmp_buf in blockframe and catchframe. 
         *    See "makeblock", "eussetjmp", "funlambda", "mkcatchframe")  
         */
      if (*p == NULL) continue;
      if (((int)(*p) & 3)) continue; 
      if ((ctx->stack <= (pointer *)*p) && ((pointer *)*p <= ctx->stacklimit)) 
        continue;
      if ((pointer *)*p >= (pointer *)maxgcheap) continue;
      if ((pointer *)*p < (pointer *)mingcheap) continue;

	  pgcpush(*p);    
      ASSERT((unsigned)(*p) >= mingcheap);
      ASSERT((unsigned)(*p) < maxgcheap);
    }

    if (frame_base == ctx->stack) {
      ctx->rbar.pointer = NULL;
    } else {
      ctx->rbar.pointer = frame_base;
    }
    mutex_unlock(&ctx->rbar.lock); /* <-- this lock wouldn't be needed */
    //DPRINT3("scanning current frame completed");
  }

#else /* original snapshot gc */

  /* push roots in thread's stack */
  for (p = ctx->vsp - 1; p >= ctx->stack; p--) {
    // for(p = ctx->stack; p < ctx->vsp; p++) {
    if (*p == NULL) continue;
    if (((int)(*p) & 3)) continue; 
    if ((ctx->stack <= (pointer *)*p) && ((pointer *)*p <= ctx->stacklimit)) 
      continue;
    if ((pointer *)*p >= (pointer *)maxgcheap) continue;
    if ((pointer *)*p < (pointer *)mingcheap) continue;

	pgcpush(*p);    
    ASSERT((unsigned)(*p) >= mingcheap);
    ASSERT((unsigned)(*p) < maxgcheap);
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

  for (i = 0; i < MAXTHREAD; i++) {
    if (euscontexts[i] && euscontexts[i]->rbar.pointer) {
      idx[local_root_count] = i;
      local_root_count++;
    }
  }

  inserted_root_count = local_root_count;
  
  do {
    for (i = 0; i < local_root_count; i++) {
      context *ctx;
      register pointer *p;
      int counter, tid;

      tid = idx[i];
      ctx = euscontexts[tid];
      if ((ctx)->rbar.pointer == NULL) continue;
      
      mutex_lock(&((ctx)->rbar.lock));
      //DPRINT3("scheduler inserting thread : %d's local roots", i);
      p = (ctx)->rbar.pointer - 1;
      counter = INSERT_UNIT;

      while (1) {
        if (p < ctx->stack) break;
        if ((((int)(*p) & 3) == 0)
            && ((ctx->stack > (pointer *)*p) || ((pointer *)*p > ctx->stacklimit))
            && (((pointer *)*p >= (pointer *)mingcheap && (pointer *)*p < (pointer *)maxgcheap))) {
	      pgcpush(*p);
      ASSERT((unsigned)(*p) >= mingcheap);
      ASSERT((unsigned)(*p) < maxgcheap);
        }
    	p--;
        counter--;
    	if(counter == 0) break;
      }
      (ctx)->rbar.pointer = p + 1;
	  
      if (p < ctx->stack) {
	(ctx)->rbar.pointer = NULL;
	inserted_root_count--;
      }
      mutex_unlock(&(ctx)->rbar.lock);
    }
  }
  while (inserted_root_count != 0);
}
#endif /* __RETURN_BARRIER */

unsigned int gs[MAXTHREAD];
/*
 * suppose that we don't have collector_lock
 */
void notify_gc()
{
  int id, phase, c;
  unsigned int s, e;
//  unlock_collector;
  /* reset synchronization variables */
//  lock_collector;
/*  if (gc_phase != PHASE_NOGC) {
    unlock_collector;
    return;
  }
*/
  id = thr_self(); 
//  gs[id] = current_utime();

  gc_phase = PHASE_PROLOGUE;
  gc_point_sync = 0;
  phase = ri_core_phase;
  mut_stat_phase = mut_stat_phase ^ 0x2;
#ifdef __USE_POLLING
  //  for(id = 0; id < MAXTHREAD; id++){
  //    if(thread_table[id].using){
  //      mutex_lock(&mut_stat_table[id].lock);    
  //      mut_stat_table[id].stat |= 0x2; /* set 'need_scan' flag */
  //      if(mut_stat_table[id].stat & 0x1){ /* 'suspended'? */
  //        do{
  //          c = gc_point_sync;
  //        }while(cas_int(gc_point_sync, c, c + 1));
  //      }
  //      mutex_unlock(&mut_stat_table[id].lock);    
  //    }
  //  }
#endif
#ifdef __USE_SIGNAL
  send_root_insertion_signals();
#else /* __USE_POLLING */
  gc_request_flag = 1;
#endif
  marking_state.is_checking_pstack = 0;
  marking_state.cur_mut_num = 0;
  marked_words = 0;
  unlock_collector;
  
  do {
    c = gc_point_sync;
  } while(cas_int(gc_point_sync, c, c + 1));

  if (gc_point_sync + gc_region_sync < active_mutator_num) {
    sched_yield(); // nanosleep(0) might be better
  } else {
    lock_collector;
    if (phase == ri_core_phase) {
      do_scan_roots(); 
    }
    unlock_collector;
  }
  
  /* wait until root scanning(core) is finished */
  lock_collector;
  while (phase == ri_core_phase) 
    cond_wait(&ri_end_cv, &collector_lock); 
//  unlock_collector;
//  e = current_utime();
//  if(id == 0)fprintf(stderr, " (%d:%d) ", e - gs[id], id);
}


/* suppose that we have collector lock */
static void do_scan_roots()
{ 
  int tid;
  unsigned int s, e;

    //s = current_utime();
  scan_global_roots();

  /* write barriers get activated */
  /* objects are allocated as black after here */
  gc_phase = PHASE_ROOT_CORE; 
  for (tid = 0; tid < MAXTHREAD; tid++) {
    if (euscontexts[tid]) {
      mutex_lock(&mut_stat_table[tid].lock);
      scan_local_roots(tid);
      //      mut_stat_table[tid].stat = 0x0; /* 'running' */
      mut_stat_table[tid].stat = 
        (mut_stat_table[tid].stat ^ 0x2) & 0xfffffffd; /* 'running' */
      mutex_unlock(&mut_stat_table[tid].lock);
    }
  }
    //e = current_utime();
    //fprintf(stderr, "stopped: %d\n", e - s);

  gc_request_flag = 0;
  ri_core_phase = 1 - ri_core_phase; /* release other mutator threads */
  gc_phase = PHASE_ROOT_REM; 
  cond_broadcast(&ri_end_cv);
  gc_wakeup_cnt++; /* now, we release collector threads */
  cond_broadcast(&gc_wakeup_cv);
  DPRINT2("root scan finished: free rate = %lf", (double)freeheap / totalheap);
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

//#define myctx (euscontexts[thr_self()])
//static long rgc_marktime, rgc_sweeptime;

static int do_gc_epilogue()
{
  /*
    if (gc_net_free < 0.8) { // hard external fragmentation
      DPRINT1("\x1b[1;31mexpand heap(do_gc_epilogue, free/total=%d/%d)\x1b[0m",
	      freeheap, totalheap);
      newchunk(DEFAULT_EXPAND_SIZE_IDX);
      //do_allocate_heap(totalheap * (0.9 - gc_net_free));
    }
  */
#ifdef __USE_MARK_BITMAP
    clear_bit_table();
#endif
    if (gc_cmp_cnt < gc_wakeup_cnt)
      gc_cmp_cnt++;
    gc_phase = PHASE_NOGC;

    if (debug) {
      fprintf(stderr, " free/total=%d/%d\n",
          freeheap, totalheap);
//      fprintf(stderr, " mark=%d sweep%d\n", rgc_marktime, rgc_sweeptime);
    }
/* GC thread doesn't have its own context.
    if (speval(QGCHOOK) != NIL) {
      pointer gchook=speval(QGCHOOK);
      vpush(makeint(freeheap)); vpush(makeint(totalheap));
      ufuncall(ctx,gchook,gchook,(pointer)(ctx->vsp-2),ctx->bindfp,2);
      ctx->vsp -= 2;
    }
    breakck;
*/

    DPRINT2("GC cycle finished: free rate = %lf", (double)freeheap / totalheap);
    return 0;
}

void do_a_little_gc_work(int m_unit, int s_unit)
{
  unsigned int s, e;
//  s = current_utime();
  switch (gc_phase) {
    case PHASE_ROOT_REM:
#ifdef __RETURN_BARRIER
      scan_remaining_roots();
#endif
      gc_phase = PHASE_MARK;
      break;
    case PHASE_MARK:
      mark_a_little(m_unit);
    break;
    case PHASE_SWEEP:
      sweep_a_little(gcmerge, s_unit);
    break;
    case PHASE_EPILOGUE:
      do_gc_epilogue();
    default: 
      ;
  }
//  e = current_utime();
//  if(e-s > 100) printf("<<%d, %d::%d, %d>>\n", e-s, gc_phase,
//      rgc_credit, marking_state.is_checking_pstack);
}

void collect()
{
  int i;
  unsigned s, e;

#ifdef __PROFILE_GC
  int tmp_free;
  reset_utime(); /* for rdtsc */
#endif

  /* synchronize with mainthread */
  barrier_wait(startup_barrier);

#ifdef __PROFILE_GC
  //  times(&buf1);
#endif

  /* gc main loop */
  for (;;) { 

    /* gc thread waits until the core of root scanning is finished. */
    lock_collector;
    while (gc_cmp_cnt == gc_wakeup_cnt) {
      cond_wait(&gc_wakeup_cv, &collector_lock);
    }

    while (gc_phase != PHASE_NOGC) {
     // printf(".");fflush(stdout);
      do_a_little_gc_work(M_UNIT, S_UNIT);
      unlock_collector;
      //usleep(0);
      lock_collector;
    };
    unlock_collector;
      
#ifdef __PROFILE_GC
    //    times(&buf2);
    //    gctime = buf2.tms_utime+buf2.tms_stime-buf1.tms_utime-buf1.tms_stime;
    //    fprintf(stderr, "gc thread time = %d\n", gctime*1000/HZ);
    //    fprintf(stderr, "freeheap=%d\n", freeheap*4);
    //    tmp_free = freeheap;
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
    DPRINT2("collector error: art_enter");
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
    DPRINT2("collector error: art_exit");
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
  int c, phase;
  mutex_lock(&mut_stat_table[id].lock);    
  //  mut_stat_table[id].stat |= 0x1; /* set 'suspended' flag */
  //  if(mut_stat_table[id].stat & 0x2){ /* 'need_scan'? */
  do {
    c = gc_region_sync;
  } while (cas_int(gc_region_sync, c, c + 1));
  mutex_unlock(&mut_stat_table[id].lock);    

  if (gc_request_flag) {
    phase = ri_core_phase;
    if (gc_point_sync + gc_region_sync == active_mutator_num) {
      lock_collector;
      if (phase == ri_core_phase)
        do_scan_roots(); 
      unlock_collector;
    }
  }
  //  }
}

void exit_gc_region(int id)
{
  int c;
 try_exit:
  mutex_lock(&mut_stat_table[id].lock);
  if (mut_stat_table[id].stat & 0x2 == mut_stat_phase) { /* 'need_scan'? */
    //    mut_stat_table[id].stat = 0x4; /* set 'scanning' and clear 'need_scan' */
    //    mutex_unlock(&mut_stat_table[id].lock);
    //    insert_my_roots();
    mutex_unlock(&mut_stat_table[id].lock);
    sched_yield(); /* this wouldn't go well on ART-Linux */
    goto try_exit;
  } else {
    //    mut_stat_table[id].stat &= 0x0; /* clear 'suspended' flag */
    do {
      c = gc_region_sync;
    } while (cas_int(gc_region_sync, c, c - 1));
    mutex_unlock(&mut_stat_table[id].lock);
  }
}

#endif /* __USE_POLLING */

int ps_sem = 1;
/* initialize data for syncronization */
static void init_sync_data()
{
  int i;
  mutex_init(&pstack_lock, NULL);
  mutex_init(&collector_lock, NULL);
  cond_init(&gc_wakeup_cv, NULL);
  cond_init(&ri_end_cv, NULL);
  mutex_init(&gc_state_lock, NULL);
  for (i = 0; i < MAXTHREAD; i++) {
    mutex_init(&mut_stat_table[i].lock, NULL);
  }
}

/**********************************************************
  mutator interface routines
*********************************************************/

#ifdef __USE_POLLING
void scan_roots()
{
  int c;
  unsigned int e;
  int myid = thr_self();
  int phase = ri_core_phase;

  myid = thr_self();
  //gs[myid] = current_utime();

  do {
    c = gc_point_sync;
  } while (cas_int(gc_point_sync, c, c + 1));

  if (gc_point_sync + gc_region_sync < active_mutator_num) {
    sched_yield(); // nanosleep(0) might be better
  } else {
    lock_collector;
    if (phase == ri_core_phase)
      do_scan_roots(); 
    unlock_collector;
  }
  
  /* wait until root scanning(core) is finished */
  lock_collector;
  while (phase == ri_core_phase)
    cond_wait(&ri_end_cv, &collector_lock);
  unlock_collector;
  //e = current_utime();
  //if(myid == 0)fprintf(stderr, " (%d:%d) ", e-gs[myid], myid);
  
  return;
}

/* function-version polling code */
int check_gc_request()
{
  if (!gc_request_flag) 
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
  DPRINT2("start root scanning");
  notify_ri_start();
  idx = thr_self();
  scan_local_roots(thr_self());
  barrier_wait(end_ri_barrier);
  DPRINT2("mutators restart");
}
#endif

/* MAXSTACK 65536 */
#define PMAXSTACK (MAXSTACK * 110)
pointer pstack[PMAXSTACK];
volatile pointer *psp = pstack;
pointer *pstacklimit = pstack + PMAXSTACK;
mutex_t pstack_lock;

/***********************************************************
    barrier-synchronization functions
***********************************************************/

barrier_t barrier_init(int n_clients)
{
  barrier_t barrier = (barrier_t)malloc(sizeof(struct barrier_struct));
  if (barrier != NULL) {
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
  if (barrier->n_waiting == barrier->n_clients) {
    barrier->n_waiting = 0;
    barrier->phase = 1 - my_phase;
    cond_broadcast(&barrier->wait_cv);
  }
  while (barrier->phase == my_phase) {
    cond_wait(&barrier->wait_cv, &barrier->lock);
  }
  mutex_unlock(&barrier->lock);
}

/***********************************************************
  other functions
***********************************************************/


unsigned int do_allocate_heap(unsigned int req_words)
{
  int i, k; 
  unsigned int rem_words = req_words;

  while (buddysize[MAXBUDDY-1] <= rem_words) {
    k = newchunk(MAXBUDDY-1);
    rem_words -= buddysize[k];
  }
  for (i = MAXBUDDY - 2; i >= 20/* or DEFAULTCHUNKINDEX */; i--) {
    if (buddysize[i] < rem_words){
      k = newchunk(i);
      rem_words -= buddysize[k];
    }
  }
  return req_words - rem_words;
}

unsigned int allocate_heap()
{ /*
   * k  buddy[k]
   * 22 85971 word 343884 byte
   * 23 139104 word 556416 byte
   * 24 225075 word 900300 byte
   * 25 364179 word 1456716 byte
   * 26 589254 word 2357016 byte
   * 27 953433 word 3813732 byte
   * 28 1542687 word 6170748 byte
   * 29 2496120 word 9984480 byte
   * 30 4038807 word 16155228 byte
   */
    return do_allocate_heap(INITIAL_HEAP_SIZE * 1000);
}

extern long long values[];

pointer RGCCOUNT(register context *ctx, int n, pointer argv[])
{
  ckarg(0);
  return makeint(gc_cmp_cnt);
}

pointer RGC_GCTIME(register context *ctx, int n, pointer argv[])
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
  defun(ctx, "RGCCOUNT", mod, RGCCOUNT,NULL);
  defun(ctx, "RGCTIME", mod, RGC_GCTIME,NULL);
#ifdef __PROFILE_GC
  defun(ctx, "RGCALLOCATED", mod, RGCALLOCATED,NULL);
#endif
  pointer_update(Spevalof(PACKAGE), p);
}
