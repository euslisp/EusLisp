/* 
 * rgc_mem.c
 */

#include 	<sys/types.h>
#include	<sys/times.h>
#include	"eus.h"

#define myctx (euscontexts[thr_self()])

// defined in "memory.c"
extern long freeheap, totalheap; /* size of heap left and allocated */

/* timers */
//long gccount;
long alloccount[MAXBUDDY];

/* disposal processing */
//#define MAXDISPOSE 256
//static  pointer dispose[MAXDISPOSE];
//static  int dispose_count;

bpointer rgc_root_alloc_big(ctx, req)
     register context *ctx;
     register int req;	/*index to buddy: must be greater than 0*/
{ 
  register int i, k;
  register bpointer b,b2;
  numunion nu;
  pointer gcm;
#ifdef THREADED
#ifdef SIGB
  blockSignal();
#endif /* SIGB */
  GC_REGION(mutex_lock(&alloc_lock););
#endif /* THREADED */

  ctx->alloc_big_count++;

 alloc_again:
  k=req;
  while(buddy[k].bp==0) k++;	/*find blocks of adequate size*/
  if(k>=MAXBUDDY) {		/*no bigger free cell*/
    if(buddysize[req]<totalheap/8){	/*relatively small cell is requested;*/
      gcm=speval(GCMARGIN);
#ifdef __HEAP_EXPANDABLE
      mutex_unlock(&alloc_lock);
      lock_collector;
      GC_REGION(mutex_lock(&alloc_lock););
      newchunk(req); 
      fprintf(stderr, "\x1b[1;31mstarved(alloc_big:1, free/total=%d/%d)\x1b[0m\n",
	      freeheap, totalheap);
      unlock_collector;
#else
      fprintf(stderr, "\x1b[1;31mstarved(alloc_big:1, free/total=%d/%d)\x1b[0m\n",
	      freeheap, totalheap);
      mutex_unlock(&alloc_lock);
      if (gc_phase == PHASE_NOGC) {
        DPRINT("start GC: free rate = %lf", (double)freeheap / (double)totalheap);
        notify_gc();
      }
      lock_collector;
      while (gc_phase != PHASE_NOGC) {
        do_a_little_gc_work();
      }
      unlock_collector;
      mutex_lock(&alloc_lock);
      goto alloc_again;
#endif
      /*
	#else
	while(freeheap < (totalheap*min(5.0,fltval(gcm))))
	newchunk(req); 
	#endif
      */
      for(k=req; buddy[k].bp==0;) k++;
    }
    if(k>=MAXBUDDY){
#ifdef __HEAP_EXPANDABLE
      mutex_unlock(&alloc_lock);
      lock_collector;
      mutex_lock(&alloc_lock);
      k = newchunk(req);
      fprintf(stderr, "\x1b[1;31mstarved(alloc_big:2, free/total=%d/%d)\x1b[0m\n",
	      freeheap, totalheap);
      unlock_collector;
#else
      fprintf(stderr, "\x1b[1;31mstarved(alloc_big:2, free/total=%d/%d)\x1b[0m\n",
	      freeheap, totalheap);
      mutex_unlock(&alloc_lock);
      if (gc_phase == PHASE_NOGC) {
        DPRINT("start GC: free rate = %lf", (double)freeheap / (double)totalheap);
        notify_gc();
      }
      lock_collector;
      while (gc_phase != PHASE_NOGC) {
        do_a_little_gc_work();
      }
      unlock_collector;
      mutex_lock(&alloc_lock);
      goto alloc_again;
#endif
      if (k == ERR) {
#if THREADED
	mutex_unlock(&alloc_lock);
#ifdef SIGB
	unBlockSignal();
#endif /* SIGB */
#endif
	error(E_ALLOCATION);
      }
    }
  }
  while (req<k) {
    splitheap(k--,buddy); 
    if (k>req) k--;
  }
  k=buddysize[req]-1;
  b=buddy[req].bp;
  b2=b->b.nextbcell;
  for(i=0; i<k; i++) b->b.c[i]=0;
#ifdef RGC
  //  take_care(ctx->lastalloc);
#endif
  ctx->lastalloc=makepointer(b);
  buddy[req].bp=b2;
  buddy[req].count--;
#ifdef DEBUG
  printf( "root_alloc_big: alloc 1 block (%d), 0x%lx\n", req, b );
#endif
  freeheap -= buddysize[req];
  alloccount[req]++;

#if THREADED
  mutex_unlock(&alloc_lock); 
#ifdef SIGB
  unBlockSignal();
#endif /* SIGB */
#endif

  if (freeheap < (double)totalheap * DEFAULT_GC_THRESHOLD && gc_phase == PHASE_NOGC) {
    DPRINT("start GC: free rate = %lf", (double)freeheap / (double)totalheap);
    notify_gc();
  }
  
#ifdef __GC_ALLOC_DRIVEN
  lock_collector;
  if (gc_phase != PHASE_NOGC) do_a_little_gc_work();
  unlock_collector;
#endif

  return(b);
}

rgc_root_alloc_small(ctx, req)
     register context *ctx;
     register int req;	/*index to buddy: must be greater than 0*/
{ 
  register int i, j, k, kk;
  register bpointer b, b2;
  register struct buddyfree *tb=ctx->thr_buddy;
  static long buddyfill[MAXTHRBUDDY+1]={0,500,300,20,15,10,0};
  numunion nu;

  GC_REGION(mutex_lock(&alloc_lock);); 
  ctx->alloc_small_count++;

 alloc_again:
  for(i=1; i<MAXTHRBUDDY; i++){
    k=kk=buddyfill[i] - tb[i].count; /*how many cells are needed*/
    while(buddy[i].count < k){   /*Do we have enough free in the root?*/
      /*	fprintf(stderr, "free_count=%d; k=%d\n",buddy[i].count,k);  */
      j=i+1;
      while(buddy[j].bp==0) j++;
      if(j>=MAXBUDDY){	/*no free cell*/
#ifdef __HEAP_EXPANDABLE
	mutex_unlock(&alloc_lock);
	lock_collector;
	GC_REGION(mutex_lock(&alloc_lock););
	fprintf(stderr, "\x1b[1;31mstarved(alloc_small:1, free/total=%d/%d)\x1b[0m\n",
		freeheap, totalheap);
	//	j = newchunk(DEFAULTCHUNKINDEX);
	j = newchunk(DEFAULT_EXPAND_SIZE_INDEX);
	unlock_collector;
	if (j == ERR) { 
	  mutex_unlock(&alloc_lock); 
	  error(E_ALLOCATION);
	}
#else
	fprintf(stderr, "\x1b[1;31mstarved(alloc_small:1, free/total=%d/%d)\x1b[0m\n",
		freeheap, totalheap);
	mutex_unlock(&alloc_lock);
    if (gc_phase == PHASE_NOGC) {
      DPRINT("start GC: free rate = %lf", (double)freeheap / (double)totalheap);
      notify_gc();
    }
    lock_collector;
	while (gc_phase != PHASE_NOGC) {
	  do_a_little_gc_work();
	}
	unlock_collector;
	mutex_lock(&alloc_lock);
	goto alloc_again;
#endif
      }
      splitheap(j, buddy);
    }
    /* sufficient free cells collected in the root free list */
    if(k>0){
      b=buddy[i].bp;
      while(k>0){
	b2=b; b->h.cix=-1; b=b->b.nextbcell; k--;
      }
      b2->b.nextbcell=tb[i].bp;
      tb[i].bp=buddy[i].bp;
      buddy[i].bp=b;
      buddy[i].count -= kk;
      tb[i].count=buddyfill[i];
      freeheap -= buddysize[i]*kk;
      alloccount[i] += kk;
#ifdef DEBUG
      printf( "root_alloc_small: alloc %d block(s) (%d)\n", kk, i);
#endif
    }
  }

#if THREADED
  mutex_unlock(&alloc_lock); 
#ifdef SIGB
  unBlockSignal();
#endif /* SIGB */
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

  if (freeheap < (double)totalheap * DEFAULT_GC_THRESHOLD && gc_phase == PHASE_NOGC) {
    DPRINT("start GC: free rate = %lf", (double)freeheap / (double)totalheap);
    notify_gc();
  }
  
#ifdef __GC_ALLOC_DRIVEN
  lock_collector;
  if (gc_phase != PHASE_NOGC) do_a_little_gc_work();
  unlock_collector;
#endif

  /*return(b);*/
}

pointer rgc_alloc(s,e,cid,nils)	/*allocate heap of 's' longwords*/
     register int s,nils;
     int e,cid;
{ register int req=1,i,ss;
 register pointer p;
 register pointer *v;
 register bpointer b,b2;
 register context *ctx=myctx;
 register struct buddyfree *tb= ctx->thr_buddy;
#if defined(DEBUG) || defined(DEBUG_COUNT)
 static int count=0;

 count++;

 if( nils > s ) {
   printf( "alloc:%d:nils(=%d) > s(=%d)!!\n", count, nils, s );
 }
#endif
 ss=max(3,s+1);	 /*one more word for the allocation information*/
 while (buddysize[req]<ss) req++;
#ifdef DEBUG
 printf( "alloc:%d:s=%d, e=%d, cid=%d, nils=%d\n",
	 count, s, e, cid, nils );
#endif
 if (req>=MAXTHRBUDDY)  b=rgc_root_alloc_big(ctx, req);
 else { /*small cell is requested*/
   if (tb[req].count==0) {/*find a cell in the local free list*/
     rgc_root_alloc_small(ctx, req);
#ifdef DEBUG
     printf( "alloc:" );
     dump_bcell(req,ctx->thr_buddy);
#endif
   }
   ASSERT(tb[req].bp != 0);
#if THREADED
   rw_rdlock(&gc_lock);
#endif
#ifdef DEBUG
   fflush( stdout );
   printf( "alloc:%d:", count );
   dump_bcell( req, tb );
#endif
   b=tb[req].bp;
#ifdef RGC
   //    take_care(ctx->lastalloc);
#endif
   ctx->lastalloc=makepointer(b);
   ss=buddysize[req]-1;
   tb[req].bp=b->b.nextbcell;
#if defined(DEBUG) || defined(UALLOC_DEBUG)
   printf( "alloc:%d:allocate for user[%d(buddysize=%d)] = 0x%lx: new list top = 0x%lx\n",
	   count, req, buddysize[req], b, tb[req].bp );
#endif
   for (i=0; i<ss; i++) b->b.c[i]=0;
   tb[req].count--;
#if THREADED
   rw_unlock(&gc_lock);
#endif
 }

#ifdef __USE_MARK_BITMAP
 /* PHASE_ROOT_REM or PHASE_MARK or PHASE_SWEEP */
 //lock_collector;
 if (gc_phase >= PHASE_SWEEP) {
   markon(b);
 }
 //unlock_collector;
 //  fprintf(stderr, "tag=%x\n", b->h.bix&0xff);
#else
 if (gc_phase >= PHASE_SWEEP) {
   lock_collector;
   if (gc_phase >= PHASE_MARK)
     markon(b);
   else if (gc_phase == PHASE_SWEEP && b > sweeping_state.p)
     markon(b);
   b->h.cix=cid;
   unlock_collector;
 }
#endif

 b->h.cix=cid;
 b->h.elmtype=e;
#ifndef RGC
 b->h.extra=0;
#endif
 b->h.nodispose=0;
 p=makepointer(b);
 v=p->c.obj.iv;
#ifdef DEBUG
 printf( "alloc:%d:fill NIL:nils = %d, s = %d\n",
	 count, nils, s );
#endif
 i=0;
 while (i<nils) v[i++]=NIL;	/*fill NILs in user's  slots*/
 /* while (nils<s) v[nils++]=NIL; */
 i=buddysize[req]-1;
 while (s<i) v[s++]=NULL;	/*fill NULLs in buddy-cells extra slots*/
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
 return(p);}

