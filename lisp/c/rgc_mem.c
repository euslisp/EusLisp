/* 
 * rgc_mem.c
 */

#include <sys/types.h>
#include <sys/times.h>
#include "eus.h"

#define myctx (euscontexts[thr_self()])

// defined in "memory.c"
extern long freeheap, totalheap, marked_words;
/* size of heap left and allocated */

/* timers */
long alloccount[MAXBUDDY];

/* disposal processing */
//#define MAXDISPOSE 256
//static  pointer dispose[MAXDISPOSE];
//static  int dispose_count;

/* 
 * suppose that we have allocate lock
 */
static int rgc_expand_heap_or_complete_gc(int req)
{
  int idx = ERR;

#ifdef __HEAP_EXPANDABLE
  /* acquire locks again in the correct order */
  mutex_unlock(&alloc_lock);
  lock_collector;
  mutex_lock(&alloc_lock);

  idx = newchunk(req); 
  unlock_collector;
#else
  /* this case is under construction */
  mutex_unlock(&alloc_lock);
  if (gc_phase == PHASE_NOGC) {
    DPRINT1("\x1b[0;32mstart GC: free rate = %lf\x1b[0m", (double)freeheap / (double)totalheap);
    notify_gc();
  }

  lock_collector;
  while (gc_phase != PHASE_NOGC) {
    do_a_little_gc_work(AM_UNIT, AS_UNIT);
  }
  unlock_collector;
  mutex_lock(&alloc_lock);
#endif

  return idx;
}

static inline unsigned long net_free(int req) {
  unsigned long total = 0;
  register int idx;

  for (idx = (req < REALTIME_ALLOC_LIMIT_IDX ? req : REALTIME_ALLOC_LIMIT_IDX);
          idx < MAXBUDDY; idx++)
      total += buddysize[idx] * buddy[idx].count;

  return total;
}

static int km[10] = {4096, 4800, 6000, 8192};
static int ks[10] = {256, 256, 384, 512};

static int recalc_gc_priority(int req) {
  /* now, return a value between 0 to 3 
   * 0: no gc
   * 1: gc thread
   * 2: normal thread
   * greater: realtime thread
   */
  long estimation;
  int i;

#if 0
  for (i = 0; i < 4; i++) {
    if (gc_phase == PHASE_NOGC || gc_phase >= PHASE_MARK) { 
      estimation = (totalheap - freeheap - marked_words) / km[i]
        + (totalheap >> 4) / ks[i];
    } else {
      estimation = (totalheap >> 4) / ks[i];
    }
    estimation *= 1024;
    if (net_free(req) > estimation)
     break;
  }
//  DPRINT1("estimation = %ld", estimation);
  return i;
#endif

  {
    unsigned long nfree = net_free(req);
    for (i = 0; i < 4; i++) {
      if (nfree < totalheap * DEFAULT_GC_THRESHOLD)
        nfree *= 2;
      else
        break;
    }
  }    

#if 0
  i = (net_free(req) < totalheap * DEFAULT_GC_THRESHOLD); 
#endif 

  return i; 
}


volatile static int rem_cnt = 0;
volatile static int gc_pri = 0;
#define my_gc_pri ctx->my_gc_pri

/* suppose we have collector lock */
static int should_start_gc(int req) {
  static int gc_cushion = GC_ACTIVATE_CUSHION;
  register int idx;

//  if (net_free(req) < (double)totalheap * DEFAULT_GC_THRESHOLD)
  if (recalc_gc_priority(req) > 0)
    gc_cushion--;
  
  return gc_cushion <= 0 
    ? (gc_cushion = GC_ACTIVATE_CUSHION, 1) : 0;
}


bpointer rgc_root_alloc_big(register context *ctx, register int req)
{ /* req: index to buddy: must be greater than 0 */
  register int i, k;
  register bpointer b, b2;
  numunion nu;
  pointer gcm;

  mutex_lock(&alloc_lock);
  ctx->alloc_big_count++;

 alloc_again:

  for (k = req; buddy[k].bp == 0; )
    k++; /* find blocks of adequate size */

  if (k >= MAXBUDDY) { /* no bigger free cell */
    if (buddysize[req] < totalheap / 8) { /*relatively small cell is requested;*/
      gcm = speval(GCMARGIN);
      DPRINT1("\x1b[1;31mstarved(alloc_big:1, free/total=%d/%d)\x1b[0m",
	      freeheap, totalheap);
      rgc_expand_heap_or_complete_gc(req);
      for (k = req; buddy[k].bp == 0;) k++;
    }
    if (k >= MAXBUDDY) {
      DPRINT1("\x1b[1;31mstarved(alloc_big:1, free/total=%d/%d)\x1b[0m",
	      freeheap, totalheap);
      rgc_expand_heap_or_complete_gc(req);
      for (k = req; buddy[k].bp == 0;) k++;

      if (k == ERR) {
	mutex_unlock(&alloc_lock);
	error(E_ALLOCATION);
      }
    }
  }
  while (req < k) {
    splitheap(k--, buddy); 
    if (k > req) k--;
  }
  k = buddysize[req] - 1;
  b = buddy[req].bp;
  b2 = b->b.nextbcell;
  for (i = 0; i < k; i++) b->b.c[i] = 0;
#ifdef RGC
  //  take_care(ctx->lastalloc);
#endif
  ctx->lastalloc = makepointer(b);
  buddy[req].bp = b2;
  buddy[req].count--;
#ifdef DEBUG
  printf( "root_alloc_big: alloc 1 block (%d), 0x%lx\n", req, b );
#endif
  freeheap -= buddysize[req];
  alloccount[req]++;

#if THREADED
  mutex_unlock(&alloc_lock); 
#endif

  /* work other than allocation */
  rem_cnt--;
  if (rem_cnt < 0) {
      lock_collector;
      switch(gc_phase) {
        case PHASE_NOGC:
	  /* start a new GC cycle or not? */
          if (should_start_gc(req)) {
            DPRINT2("\x1b[0;32mstart GC: free rate = %lf, frag rate[%d] = %lf\x1b[0m", 
              (double)freeheap / (double)totalheap, req, (double)net_free(req) / (double)freeheap);
	    
            notify_gc();
            gc_pri = 1;
          }
          break;
        default:
#ifdef __GC_ALLOC_DRIVEN
	  /* change GC priority */
          gc_pri = recalc_gc_priority(req);
#endif
      }

      rem_cnt = GC_GRANULARITY;
      unlock_collector;
  } else {
#ifdef __GC_ALLOC_DRIVEN
    /* do a little gc work if needed */
    if (gc_phase != PHASE_NOGC) {
      lock_collector;
      if (gc_phase != PHASE_NOGC) {
	if (my_gc_pri <= gc_pri) {
//      DPRINT1("alloc gc[%d]", gc_pri);
	  do_a_little_gc_work(AM_UNIT, AS_UNIT);
	}
      }
      unlock_collector;
    }
#endif
  }

  return b;
}


void rgc_root_alloc_small(register context *ctx, register int req)
{ /* index to buddy: must be greater than 0 */
  register int i, j, k, kk;
  register bpointer b, b2;
  register struct buddyfree *tb = ctx->thr_buddy;
  static long buddyfill[MAXTHRBUDDY + 1] = {0, 500, 300, 20, 15, 10, 0};
  numunion nu;

  mutex_lock(&alloc_lock); 
  ctx->alloc_small_count++;

 alloc_again:
  for (i = 1; i < MAXTHRBUDDY; i++) {
    k = kk = buddyfill[i] - tb[i].count; /* how many cells are needed? */
    while (buddy[i].count < k) { /* do we have enough free in the root? */
      /* fprintf(stderr, "free_count = %d; k = %d\n", buddy[i].count, k); */
      j = i + 1;
      while (buddy[j].bp == 0) j++;

      if (j >= MAXBUDDY) {/* no free cell */
	DPRINT1("\x1b[1;31mstarved(alloc_small:1, free/total=%d/%d)\x1b[0m",
		freeheap, totalheap);
	j = rgc_expand_heap_or_complete_gc(DEFAULT_EXPAND_SIZE_IDX);
	//unlock_collector;
	if (j == ERR) { 
	  mutex_unlock(&alloc_lock); 
	  error(E_ALLOCATION);
	}
      }
      splitheap(j, buddy);
    }

    /* sufficient free cells are collected in the root free list */
    if (k > 0) {
      b = buddy[i].bp;
      while (k > 0) {
	b2 = b;
	b->h.cix = -1;
	b = b->b.nextbcell;
	k--;
      }
      b2->b.nextbcell = tb[i].bp;
      tb[i].bp = buddy[i].bp;
      buddy[i].bp = b;
      buddy[i].count -= kk;
      tb[i].count = buddyfill[i];
      freeheap -= buddysize[i] * kk;
      alloccount[i] += kk;
#ifdef DEBUG
      printf("root_alloc_small: alloc %d block(s) (%d)\n", kk, i);
#endif
    }
  }

#if THREADED
  mutex_unlock(&alloc_lock); 
#endif
  /*
  {
    int j;
    bpointer p;
    for (i = 1; i < MAXTHRBUDDY; i++) {
      //    fprintf(stderr, "tb[i].count = %d\n", tb[i].count);
      for (j = 0, p = tb[i].bp; p != 0; p = p->b.nextbcell) j++;
      //    fprintf(stderr, "real list length is = %d\n", j);
      ASSERT(tb[i].count == j);
    }
  }
  */

  /* work other than allocation */
  rem_cnt--;
  if (rem_cnt < 0) {
      lock_collector;
      switch(gc_phase) {
        case PHASE_NOGC:
	  /* start a new GC cycle or not? */
          if (should_start_gc(req)) {
            DPRINT2("\x1b[0;32mstart GC: free rate = %lf, frag rate[%d] = %lf\x1b[0m", 
              (double)freeheap / (double)totalheap, req, (double)net_free(req) / (double)freeheap);
            notify_gc();
            gc_pri = 1;
          }
          break;
        default:
#ifdef __GC_ALLOC_DRIVEN
	  /* change GC priority */
          gc_pri = recalc_gc_priority(req);
#endif
      }

      rem_cnt = GC_GRANULARITY;
      unlock_collector;
  } else {
#ifdef __GC_ALLOC_DRIVEN
    /* do a little gc work if needed */
    if (gc_phase != PHASE_NOGC) {
      lock_collector;
      if (gc_phase != PHASE_NOGC) {
	if (my_gc_pri <= gc_pri) {
	  do_a_little_gc_work(AM_UNIT, AS_UNIT);
	}
      }
      unlock_collector;
    }
#endif
  }

  /*return(b);*/
}

pointer rgc_alloc(register int s, int e, int cid, register int nils)
{  /* allocate heap of 's' longwords */
 register int req = 1, i, ss;
 register pointer p;
 register pointer *v;
 register bpointer b, b2;
 register context *ctx = myctx;
 register struct buddyfree *tb = ctx->thr_buddy;

#if defined(DEBUG) || defined(DEBUG_COUNT)
 static int count = 0;

 count++;

 if (nils > s) {
   printf("alloc:%d:nils(=%d) > s(=%d)!!\n", count, nils, s);
 }
#endif
 ss = max(3, s + 1);	 /* one more word for the allocation information */
 while (buddysize[req] < ss) req++;
#ifdef DEBUG
 printf("alloc:%d:s=%d, e=%d, cid=%d, nils=%d\n",
	 count, s, e, cid, nils);
#endif
 if (req >= MAXTHRBUDDY)
   b = rgc_root_alloc_big(ctx, req);
 else { /* small cell is requested */
   if (tb[req].count == 0) { /* find a cell in the local free list */
     rgc_root_alloc_small(ctx, req);
#ifdef DEBUG
     printf("alloc:");
     dump_bcell(req,ctx->thr_buddy);
#endif
   }
   ASSERT(tb[req].bp != 0);
#if THREADED
   rw_rdlock(&gc_lock);
#endif
#ifdef DEBUG
   fflush( stdout );
   printf("alloc:%d:", count);
   dump_bcell( req, tb );
#endif
   b = tb[req].bp;
#ifdef RGC
   //    take_care(ctx->lastalloc);
#endif
   ctx->lastalloc=makepointer(b);
   ss = buddysize[req]-1;
   tb[req].bp = b->b.nextbcell;
#if defined(DEBUG) || defined(UALLOC_DEBUG)
   printf("alloc:%d:allocate for user[%d(buddysize=%d)] = 0x%lx: new list top = 0x%lx\n",
	   count, req, buddysize[req], b, tb[req].bp);
#endif
   for (i = 0; i < ss; i++) 
     b->b.c[i] = 0;
   tb[req].count--;
#if THREADED
   rw_unlock(&gc_lock);
#endif
 }

#ifdef __USE_MARK_BITMAP
 /* PHASE_ROOT_REM or PHASE_MARK or PHASE_SWEEP */
 if (gc_phase >= PHASE_SWEEP) {
   markon(b);
 } else {
   b->h.cix = cid;
 }
 //  fprintf(stderr, "tag=%x\n", b->h.bix & 0xff);
#else
 /* sweeping_state.chp synchronization needs only memory barriers */
 /* sweeping_state.p synchronization needs collector_lock */
 if (gc_phase >= PHASE_SWEEP) { 
//   lock_collector;
   if (gc_phase >= PHASE_MARK) {
     /*** critical section start ***/
     markon(b);
     b->h.cix = cid;
     /*** critical section end ***/
     if (gc_phase < PHASE_MARK) {
       /* sweeper might hava passed, because gc_phase has changed. */
       lock_collector;
       /* we have locked collector, so sweeping_state is consistent. */
       if (sweeping_state.p > b) {
         markoff(b);
       }
       unlock_collector;
     }
   } else if (gc_phase == PHASE_SWEEP) {
     if (b >= (bpointer)sweeping_state.chp) {
     /*** critical section start ***/
       markon(b);
       b->h.cix = cid;
     /*** critical section end ***/
       if (b <= (bpointer)sweeping_state.chp->nextchunk) {
         if (b < (bpointer)sweeping_state.chp) /* correct memory barriers are needed. */  
           markoff(b); /* sweeper have passed. */
         else { /* sweeper may have passed or may not. */
           lock_collector;
           if (b < sweeping_state.p) {
             markoff(b);
           }
           unlock_collector;
         }
       }
     } 
//     unlock_collector;
   b->h.cix = cid;
   }
 } else { 
   b->h.cix = cid;
 }
#endif

 b->h.elmtype = e;
#ifndef RGC
 b->h.extra = 0;
#endif
 b->h.nodispose = 0;
 p = makepointer(b);
 v = p->c.obj.iv;
#ifdef DEBUG
 printf( "alloc:%d:fill NIL:nils = %d, s = %d\n",
	 count, nils, s );
#endif
 i = 0;
 while (i < nils) v[i++] = NIL;	/* fill NILs in user's  slots */
 /* while (nils<s) v[nils++]=NIL; */
 i = buddysize[req] - 1;
 while (s < i) v[s++] = NULL;	/* fill NULLs in buddy-cells extra slots */
#ifdef DEBUG
 printf( "alloc:%d:after filling NIL:", count );
 dump_bcell( req, tb );
#endif
#ifdef RGC
 //  take_care(ctx->lastalloc);
#endif
#ifdef __PROFILE_GC
 allocd_words += buddysize[req];
#endif
 return(p);
}

