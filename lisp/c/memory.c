/****************************************************************/
/* memory.c:	memory manager for eulisp			*/
/*	Copyright(c) Toshihiro MATSUI
/*		     Electrotechnical Laboratory,1986.
/****************************************************************/
static char *rcsid="@(#)$Id$";

#if vxworks
#include	<sys/types.h>
#else
#include 	<sys/types.h>
#include	<sys/times.h>
#endif

#if alpha
#include	<stdlib.h>
#include	<unistd.h>
#endif

#include	"eus.h"
#if Solaris2
#include	<synch.h>
#include	<thread.h>
#endif

extern int threadstate[MAXTHREAD];


#if 0 /* moved to eus.h */
#define nextbuddy(p) ((bpointer)((integer_t)p+(buddysize[p->h.bix]*sizeof(pointer))))
#define marked(p)  (p->h.mark)
#define markon(p)  p->h.mark=1
#define markoff(p) p->h.mark=0
#endif
#define myctx (euscontexts[thr_self()])

/* Written by I.Hara 01/12/95 */
#if Solaris2 || Linux
extern _end();
#elif SunOS4_1
extern edata;
#else
extern edata(),_end();
#endif

#if alpha
static integer_t top_addr, bottom_addr;
#endif

extern pointer QPARAGC;
extern pointer K_DISPOSE;

char *minmemory=(char *)0x1000000; /* T.IWAI 1->2 */
#ifdef RGC
volatile long sweepheap = 0;
volatile long newheap = 0;
volatile long pastfree = 0;
#endif

char *maxmemory=(char *)0x100000;
long freeheap=0,totalheap=0;	/* size of heap left and allocated */
struct chunk *chunklist=NULL;
/* timers */
long gccount,marktime,sweeptime;
long alloccount[MAXBUDDY];

/* disposal processing */
#define MAXDISPOSE 256
static  pointer dispose[MAXDISPOSE];
static  int dispose_count;

newchunk(k)
     register int k;
{ register int s;
 register struct chunk *cp;  
 integer_t tail;
#if defined(BIX_DEBUG) || defined(DEBUG_COUNT)
 static int count = 0;
 count++;
#endif
 if(k<DEFAULTCHUNKINDEX) k=DEFAULTCHUNKINDEX;
 if(QDEBUG && debug) fprintf(stderr,";; newchunk: k=%d\n",k);
 s=buddysize[k];
 cp=(struct chunk *)((long)malloc((s+2)*sizeof(pointer)+(sizeof(pointer)-1)) & ~(sizeof(pointer)-1));
#ifdef __USE_MARK_BITMAP
 set_heap_range((unsigned int)cp, 
		(unsigned int)cp+ (s+2)*sizeof(pointer)+(sizeof(pointer)-1));
#endif
 maxmemory=(char *)sbrk(0);
 if (QDEBUG && debug) fprintf(stderr,";; maxmemory=0x%x\n",maxmemory);
 if (cp==NULL) return(ERR);	/*can't allocate new memory*/
#if alpha
 if(chunklist == NULL){
   top_addr = (integer_t)cp;
   /*printf( "first topaddr = 0x%lx\n", top_addr );*/
 }
 if((integer_t)cp < top_addr){
   top_addr = (integer_t)chunklist;
   /*printf( "topaddr = 0x%lx\n", top_addr );*/
 }
#endif
 cp->chunkbix=k;
 cp->rootcell.h.mark=0;
 cp->rootcell.h.smark=0;
 cp->rootcell.h.pmark=0;
 cp->rootcell.h.b=1;		/*initial buddy marks*/
 cp->rootcell.h.m=0;
 cp->rootcell.h.nodispose=0;
#if defined(BIX_DEBUG)
 printf( "newchunk:%d:new chunk=0x%lx:bix=%d\n", count, cp, k );
#endif
 cp->rootcell.h.bix=k;
 // cp->rootcell.b.nextbcell=0; 
 cp->rootcell.b.nextbcell = buddy[k].bp; /* R.Hanai */
#if alpha
 tail = (integer_t)cp + (s+2)*sizeof(pointer);
 if( tail > bottom_addr ) {
   bottom_addr = tail;
   /*printf( "bottom_addr = 0x%lx\n", bottom_addr );*/
 }
#endif
#ifdef RGC
 /* the color of free cells are GRAY */
 cp->rootcell.h.bix |= FREETAG;
 cp->rootcell.h.cix = -1;   /* free tag */
#endif
 buddy[k].bp= &cp->rootcell;
 buddy[k].count++;
 totalheap += s; freeheap += s;
#ifdef RGC
 newheap += s;
#endif
 /* Shift down the position for RGC */
 cp->nextchunk=chunklist;	/* link to chunk list */
 chunklist=cp;
#ifdef RGC
 if ((char *)cp < minmemory)
   minmemory = (char *)cp;
#endif

 return(k);
}

static void splitheap(k,buddy)	/* heart of the allocator */
register int k;
register struct buddyfree *buddy;
{ register bpointer b1,b2,bnext;
#if defined(BIX_DEBUG) || defined(DEBUG_COUNT)
  static int count;

  count++;
#endif

  b1= buddy[k].bp;	/* root buddy pointer */
  bnext=b1->b.nextbcell;
  buddy[k].bp= bnext;	/* remove first element */
  buddy[k].count--;
  b2= (bpointer)((long)b1+buddysize[k-1]*sizeof(pointer));
#ifdef DEBUG
 printf( "splitheap(%d,...):buddysize{k,k-1,k-2}={%d,%d,%d}, b1=0x%lx, b2=0x%lx\n",
     k, buddysize[k], buddysize[k-1], buddysize[k-2], b1, b2 );
#endif
  if (k==2) {	/*b1 and b2 are of the same size*/
    b1->b.nextbcell=b2;
    b2->b.nextbcell=buddy[k-1].bp;
    buddy[k-1].bp=b1;
    buddy[k-1].count +=2;
#ifdef RGC
   b2->h.cix = -1;  /* free tag */
   b2->h.bix = 1 | FREETAG;
#else
    b2->h.bix= 1;
#endif
  } else {
    b1->b.nextbcell= buddy[k-1].bp;
    buddy[k-1].bp=b1;
    buddy[k-1].count++;
    b2->b.nextbcell=buddy[k-2].bp;
    buddy[k-2].bp=b2;
    buddy[k-2].count++;
#if defined(BIX_DEBUG)
   printf( "splitheap:%d:b2=0x%lx, bix=%d\n", count, b2, k-2 );
#endif
#ifdef RGC
   b2->h.cix = -1;  /* free tag */
   b2->h.bix= (k-2 | FREETAG);
#else
   b2->h.bix= k-2;
#endif
  }

#ifdef DEBUG
 dump_bcell( k, buddy );
 dump_bcell( k-1, buddy );
 dump_bcell( k-2, buddy );
#endif

#if defined(BIX_DEBUG)
 printf( "splitheap:%d:b1=0x%lx, bix=%d\n", count, b1, k-1 );
#endif
 b2->h.m=b1->h.m;
  b1->h.m=b1->h.b;
  b1->h.b=0; 
#ifdef RGC
  b1->h.bix= (k-1|FREETAG);
#else
  b1->h.bix= k-1;
#endif
  b2->h.b=1;
  b2->h.mark=b2->h.smark=b2->h.pmark=0;
  b1->h.nodispose=b2->h.nodispose=0;}

bpointer root_alloc_big(ctx, req)
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
  mutex_lock(&alloc_lock);
#endif /* THREADED */

  ctx->alloc_big_count++;

 alloc_again:
  k=req;
  while(buddy[k].bp==0) k++;	/*find blocks of adequate size*/
  if(k>=MAXBUDDY) {		/*no bigger free cell*/
    if(buddysize[req]<totalheap/8){	/*relatively small cell is requested;*/
#ifndef RGC
      gc();          /* then try garbage collection*/
#endif
      gcm=speval(GCMARGIN);
#ifdef RGC
#ifdef __HEAP_EXPANDABLE
      newchunk(req); 
#else
      fprintf(stderr, "starved(alloc_big:1, freeheap/totalheap=%d/%d)", freeheap, totalheap);
#ifdef __USE_POLLING /* use polling to start gc */
	/* this code is not good, rewrite!!! */
	/* be careful not to be in deadlock. */
	mutex_unlock(&alloc_lock);
	request_gc();
    ENTER_GC_SAFE_REGION(thr_self());
	wait_until_gc_cycle_ends();
    EXIT_GC_SAFE_REGION(thr_self());
	mutex_lock(&alloc_lock);
	goto alloc_again;
#else /* __USE_SIGNAL */
	exit(1);
#endif

#endif
#else
      while(freeheap < (totalheap*min(5.0,fltval(gcm))))
	newchunk(req); /*still not enough space*/
#endif
      for(k=req; buddy[k].bp==0;) k++;
    }
    if(k>=MAXBUDDY){
#ifdef __HEAP_EXPANDABLE
      k=newchunk(req);
#else
      fprintf(stderr, "starved(alloc_big:2, freeheap/totalheap=%d/%d)", freeheap, totalheap);
#ifdef __USE_POLLING /* use polling to start gc */
	/* this code is not good, rewrite!!! */
	/* be careful not to be in deadlock. */
	mutex_unlock(&alloc_lock);
	request_gc();
    ENTER_GC_SAFE_REGION(thr_self());
	wait_until_gc_cycle_ends();
    EXIT_GC_SAFE_REGION(thr_self());
	mutex_lock(&alloc_lock);
	goto alloc_again;
#else /* __USE_SIGNAL */
	exit(1);
#endif

#endif
      if(k==ERR){
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
  while(req<k){
    splitheap(k--,buddy); 
    if(k>req) k--;
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
  return(b);
}

root_alloc_small(ctx, req)
     register context *ctx;
     register int req;	/*index to buddy: must be greater than 0*/
{ 
  register int i, j, k,kk;
  register bpointer b, b2;
  register struct buddyfree *tb=ctx->thr_buddy;
  static long buddyfill[MAXTHRBUDDY+1]={0,500,300,20,15,10,0};
  numunion nu;
  int collected=0;

#if THREADED
#ifdef SIGB
  blockSignal();
#endif /* SIGB */
  mutex_lock(&alloc_lock); 
#endif
  
  ctx->alloc_small_count++;

 alloc_again:
  for(i=1; i<MAXTHRBUDDY; i++){
    k=kk=buddyfill[i] - tb[i].count; /*how many cells are needed*/
    while(buddy[i].count < k){   /*Do we have enough free in the root?*/
      /*	fprintf(stderr, "free_count=%d; k=%d\n",buddy[i].count,k);  */
      j=i+1;
      while(buddy[j].bp==0) j++;
      if(j>=MAXBUDDY){	/*no free cell*/
	if(!collected){
	  /* fprintf(stderr, "GC: free=%d total=%d, margin=%f\n",
	     freeheap, totalheap, fltval(speval(GCMARGIN))); */
	  collected=1;
	  goto alloc_again;
	}
#ifdef __HEAP_EXPANDABLE
	j=newchunk(DEFAULTCHUNKINDEX);
#else
	fprintf(stderr, "starved(alloc_small:1, freeheap/totalheap=%d/%d)", freeheap, totalheap);
#ifdef __USE_POLLING /* use polling to start gc */
	/* this code is not good, rewrite!!! */
	/* be careful not to be in deadlock. */
	mutex_unlock(&alloc_lock);
	request_gc();
    ENTER_GC_SAFE_REGION(thr_self());
	wait_until_gc_cycle_ends();
    EXIT_GC_SAFE_REGION(thr_self());
	mutex_lock(&alloc_lock);
	goto alloc_again;
#else /* __USE_SIGNAL */
	exit(1);
#endif

#endif
	if(j==ERR){ 
	  mutex_unlock(&alloc_lock); 
#ifdef SIGB
	  unBlockSignal();
#endif /* SIGB */
	  error(E_ALLOCATION);
	}
      }
      if(j>=MAXBUDDY){ /* hard fragmentation seen */
#ifdef __HEAP_EXPANDABLE
	j=newchunk(DEFAULTCHUNKINDEX);
#else
	fprintf(stderr, "starved(alloc_small:2, freeheap/totalheap=%d/%d)", freeheap, totalheap);
	exit(1);
#endif
	if(j==ERR){ 
#if THREADED
	  mutex_unlock(&alloc_lock);
#ifdef SIGB
	  unBlockSignal();
#endif /* SIGB */
#endif
	  error(E_ALLOCATION);
	}
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
  if(freeheap < (double)totalheap * 0.3 && gc_phase == PHASE_NOGC)
    notify_gc();
#if THREADED
  mutex_unlock(&alloc_lock); 
#ifdef SIGB
  unBlockSignal();
#endif /* SIGB */
#endif
  /*return(b);*/
}

pointer alloc(s,e,cid,nils)	/*allocate heap of 's' longwords*/
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
  if (req>=MAXTHRBUDDY)  b=root_alloc_big(ctx, req);
  else { /*small cell is requested*/
    if (tb[req].count==0) {/*find a cell in the local free list*/
      root_alloc_small(ctx, req);
#ifdef DEBUG
      printf( "alloc:" );
      dump_bcell(req,ctx->thr_buddy);
#endif
  }
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

  //  mutex_lock(&gc_state_lock);
  if(gc_phase >= PHASE_MARK) /* PHASE_MARK or PHASE_SWEEP */
      markon(b);
  //  mutex_unlock(&gc_state_lock);
  //  fprintf(stderr, "tag=%x\n", b->h.bix&0xff);

  b->h.elmtype=e;
  b->h.cix=cid;
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

/****************************************************************/
/* gc: garbage collector
/****************************************************************/

pointer *gcstack, *gcsplimit, *gcsp;
#define gcpush(v) (*lgcsp++=((pointer)v))
#define gcpop() (*--lgcsp)
#if Solaris2 
#define out_of_heap(p) ((int)p<(int)_end || (pointer)0x20000000<p)
#else /* Solaris2 */
#if Linux
#define out_of_heap(p) ((int)p<(int)_end || (pointer)maxmemory <p)
#else /*Linux */
#if alpha
#if THREADED
#define out_of_heap(p) ((long)p<4 || bottom_addr<(long)p)
#else
#define out_of_heap(p) ((long)p<(long)edata || (pointer)0x000003ff00000000<p)
#endif
#else /* alpha */
#if SunOS4_1
#define out_of_heap(p) ((int)p<(int)edata || (pointer)0x20000000<p)
#else
#if (WORD_SIZE == 64)
#define out_of_heap(p) ((long)p<(long)edata || (pointer)0x20000000<p)
#else
#define out_of_heap(p) ((int)p<(int)edata || (pointer)0x20000000<p)
#endif
#endif /* SunOS4_1 */
#endif /* alpha */
#endif /* Linux */
#endif /* Solaris2 */

#if 0
pointer mark_root, marking, marking2;

static mark(p)
register pointer p;
{ register int i,s;
  register bpointer bp;
  register pointer p2;
  register pointer *lgcsp=gcstack;
  register pointer *lgcsplimit=gcsplimit;

  mark_root=p;
  gcpush(p);
markloop:
  if (lgcsp<=gcstack) return;
  p=gcpop();
markagain:
  if (out_of_heap(p)) goto markloop;

  bp=bpointerof(p);
  if (marked(bp)) goto markloop;	/*already marked*/
  markon(bp);			/*mark it first to avoid endless marking*/
#ifdef MARK_DEBUG
  printf( "mark: markon 0x%lx\n", bp );
#endif
  if (pisclosure(p)) goto markloop;	/*avoid marking contents of closure*/
  marking=p;
/*  printf("%x, %x, %d, %d, %d\n", p, bp, bp->h.elmtype, bp->h.bix, buddysize[bp->h.bix] );*/
  if (bp->h.elmtype==ELM_FIXED) {	/*contents are all pointers*/
    s=buddysize[bp->h.bix]-1;
    while (lgcsp+s>gcsplimit) { 
      newgcstack(lgcsp); lgcsp=gcsp;}
    for (i=0; i<s; i++) {
	p2=p->c.obj.iv[i];
	if (ispointer(p2)) /* && !marked(bpointerof(p2)))*/  gcpush(p2); }
    goto markloop;}
  else if (bp->h.elmtype==ELM_POINTER) { /*varing number of pointers*/
    s=buddysize[bp->h.bix]-2;
    while (lgcsp+s>gcsplimit) { 
      newgcstack(lgcsp); lgcsp=gcsp;}
    for (i=0; i<s; i++) {
	p2=p->c.vec.v[i];
	if (ispointer(p2)) /* && !marked(bpointerof(p2)))*/   gcpush(p2); }
      goto markloop;}
  else goto markloop;
  }

newgcstack(oldsp)
register pointer *oldsp;
{ register pointer *oldstack, *stk, *newstack, *newgcsp;
  long top, oldsize, newsize;

  oldstack=stk=gcstack;
  oldsize=gcsplimit-gcstack;
  newsize=oldsize*2;
  top=oldsp-gcstack;
  newgcsp=newstack=(pointer *)malloc(newsize * sizeof(pointer)+16);
  fprintf(stderr, "\n;; extending gcstack 0x%x[%d] --> 0x%x[%d] top=%x\n",
		oldstack, oldsize, newstack, newsize, top);
  while (stk<oldsp) *newgcsp++= *stk++;
  gcstack=newstack;
  gcsplimit= &gcstack[newsize-10];
  gcsp= &gcstack[top];
  cfree(oldstack);
}
#endif

pnewgcstack(cid, oldsp)
     register int cid;
     register pointer *oldsp;
{
  register pointer *oldstack, *stk, *newstack, *newgcsp;
  long top, oldsize, newsize;

  oldstack=stk=collector_stack;
  oldsize=collector_stacklimit-oldstack;
  newsize=oldsize*2;
  top=oldsp-collector_stack;
  newgcsp=newstack=(pointer *)malloc(newsize * sizeof(pointer)+16);
  fprintf(stderr, "\n;; extending pgcstack 0x%x[%d] --> 0x%x[%d] top=%x\n",
      oldstack, oldsize, newstack, newsize, top);
  while (stk<oldsp) *newgcsp++= *stk++;
  collector_stack=newstack;
  collector_stacklimit= &(collector_stack[newsize-10]);
  collector_sp = &(collector_stack[top]);
  cfree(oldstack);
}

/*
 * the next functions must be implemented to support explicit GC call.
 */
int markall(){};
void sweepall(){};
int gc(){};


call_disposers()
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

#if (Solaris2 || SunOS4_1) && THREADED
suspend_all_threads()
{ register int i, self, stat;
  
  self=thr_self();
  for (i=0; i<MAXTHREAD; i++) 
    if (i!=self && euscontexts[i]) {
      stat=thr_suspend(i);
      if (stat) fprintf(stderr, "gc cannot suspend thread %d\n",i);  }
  }
/* Solaris2_5 may not go well. R.Hanai */

resume_all_threads()
{ register int i, self, stat;
  
  self=thr_self();
  for (i=0; i<MAXTHREAD; i++) 
    if (i!=self && euscontexts[i]) {
      stat=thr_continue(i);
      if (stat) fprintf(stderr, "gc cannot resume thread %d\n",i);  }
  }

#endif

#if 0
#if vxworks
gc()
{ if (debug)  fprintf(stderr,"\n;; gc:");
#ifdef RGC
     fprintf(stderr, "Enter GC\n");
#endif
  breakck;
  gccount++;
  markall();
  sweepall();
  if (debug) {
    fprintf(stderr," free/total=%d/%d stack=%d ",
        	freeheap,totalheap,markctx->vsp-markctx->stack);
    }
  breakck;  }
#else 

gc()
{ struct tms tbuf1,tbuf2,tbuf3;
  int i;
  context *ctx=euscontexts[thr_self()];

  if (debug)  fprintf(stderr,"\n;; gc: thread=%d ",thr_self());
  breakck;
  gccount++;
  times(&tbuf1);

#if (Solaris2 || SunOS4_1) && THREADED
/*  mutex_lock(&alloc_lock);  is not needed since gc is assumed to be called
    from alloc_small or alloc_big and they have already locked alloc_lock.*/
  mutex_lock(&mark_lock);
  rw_wrlock(&gc_lock);
  suspend_all_threads();
#endif

  markall();

  times(&tbuf2);
  marktime+=(tbuf2.tms_utime-tbuf1.tms_utime);
  sweepall();
  times(&tbuf3);
  sweeptime+=(tbuf3.tms_utime-tbuf2.tms_utime);
  if (debug) {
    fprintf(stderr," free/total=%d/%d stack=%d ",
		freeheap,totalheap,myctx->vsp - myctx->stack);
    fprintf(stderr," mark=%d sweep=%d\n", marktime,sweeptime);}
#if (Solaris2 || SunOS4_1) && THREADED
  resume_all_threads();
  rw_unlock(&gc_lock);
  mutex_unlock(&mark_lock);
/*  mutex_unlock(&alloc_lock); */
#endif
  if (speval(QGCHOOK)!=NIL) {
    pointer gchook=speval(QGCHOOK);
    vpush(makeint(freeheap)); vpush(makeint(totalheap));
    ufuncall(ctx,gchook,gchook,(pointer)(ctx->vsp-2),ctx->bindfp,2);
    ctx->vsp -= 2;
    }
  breakck;
}
#endif
#endif

#ifdef DEBUG
dump_bcell( k, b )
int k;
struct buddyfree *b;
{
    bpointer bp;
    int i;

    printf( "buddy[%d] = { %d, (", k, b[k].count );
    bp = b[k].bp;
    for( i = 0; i < b[k].count; i++ ) {
	printf( "0x%lx ->", bp );
	bp = bp->b.nextbcell;
    }
    printf( ")}\n" );
}
#endif

#ifdef STACK_DEBUG
pointer p_print( v, ctx )
pointer v;
context *ctx;
{
    printf( "vpush:0x%lx->[0x%lx]\n", v, ctx->vsp );

    return v;
}
#endif
