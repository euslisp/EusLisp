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

#if 0 /* moved to eus.h */
#define nextbuddy(p) ((bpointer)((eusinteger_t)p+(buddysize[p->h.bix]*sizeof(pointer))))
#define marked(p)  (p->h.mark)
#define markon(p)  p->h.mark=1
#define markoff(p) p->h.mark=0
#endif
#define myctx (euscontexts[thr_self()])

/* Written by I.Hara 01/12/95 */
#if Solaris2 || Linux
extern eusinteger_t _end();
#elif SunOS4_1
extern edata;
#else
extern edata(),_end();
#endif

#if alpha
static eusinteger_t top_addr, bottom_addr;
#endif

extern pointer QPARAGC;
extern pointer K_DISPOSE;

char *maxmemory=(char *)0x0;
#if (WORD_SIZE == 64)
char *minmemory=(char *)0xffffffffffffffff;
#else
char *minmemory=(char *)0xffffffff;
#endif
long freeheap=0,totalheap=0;	/*size of heap left and allocated*/
struct chunk *chunklist=NULL;
/* timers */
long gccount,marktime,sweeptime;
long alloccount[MAXBUDDY];

/*disposal processing*/
#define MAXDISPOSE 256
static  pointer dispose[MAXDISPOSE];
static  int dispose_count;

int newchunk(k)
register int k;
{ register int s;
  register struct chunk *cp;  
  eusinteger_t tail;
#if defined(BIX_DEBUG) || defined(DEBUG_COUNT)
  static int count = 0;

  count++;
#endif
//      fprintf(stderr, "\x1b[1;31mnewchunk(%d)\x1b[0m\n", k);
  if (k<DEFAULTCHUNKINDEX) k=DEFAULTCHUNKINDEX;
  if (QDEBUG && debug) fprintf(stderr,";; newchunk: k=%d\n",k);
  s=buddysize[k];
  cp=(struct chunk *)((long)malloc((s+2)*sizeof(pointer)+(sizeof(pointer)-1)) & ~(sizeof(pointer)-1));
#if defined(RGC)
  set_heap_range((unsigned int)cp,
      (unsigned int)cp + (s+2)*sizeof(pointer)+(sizeof(pointer)-1));
#endif
#if Linux || Cygwin || Darwin
  if (minmemory > (char *)cp) minmemory = (char *)cp;
  if (maxmemory < (char *)sbrk(0)) maxmemory = (char *)sbrk(0);
  if (maxmemory < (char *)cp+(s+2)*sizeof(pointer)+(sizeof(pointer)-1)) maxmemory = ((char *)cp+(s+2)*sizeof(pointer)+(sizeof(pointer)-1));
#else
  maxmemory=(char *)sbrk(0);
#endif
  if (QDEBUG && debug) fprintf(stderr,";; maxmemory=%p\n",maxmemory);
  if (cp==NULL) return(ERR);	/*can't allocate new memory*/
#if alpha
  if( chunklist == NULL ) {
    top_addr = (eusinteger_t)cp;
/*printf( "first topaddr = 0x%lx\n", top_addr );*/
}
  if( (eusinteger_t)cp < top_addr ) {
    top_addr = (eusinteger_t)chunklist;
/*printf( "topaddr = 0x%lx\n", top_addr );*/
}
#endif
  
#if defined(RGC)// && !defined(__USE_MARK_BITMAP)
  /* sort by address */
  if (chunklist == NULL) {
    cp->nextchunk = NULL;
    chunklist = cp;
  } else {
    struct chunk *ccp;
    for (ccp = chunklist; ccp->nextchunk < cp && ccp->nextchunk != NULL; 
        ccp = ccp->nextchunk);
    cp->nextchunk = ccp->nextchunk;
    ccp->nextchunk = cp;
  }
#else
  cp->nextchunk=chunklist;	/*link to chunk list*/
  chunklist=cp;
#endif

  cp->chunkbix=k;
  cp->rootcell.h.mark=0;
  cp->rootcell.h.smark=0;
  cp->rootcell.h.pmark=0;
  cp->rootcell.h.b=1;		/*initial buddy marks*/
  cp->rootcell.h.m=0;
  cp->rootcell.h.nodispose=0;
  cp->rootcell.h.bix=k;
#ifndef RGC
  cp->rootcell.b.nextbcell=0;
#else
  cp->rootcell.b.nextbcell = buddy[k].bp;
#endif
#if alpha
  tail = (eusinteger_t)cp + (s+2)*sizeof(pointer);
  if( tail > bottom_addr ) {
    bottom_addr = tail;
/*printf( "bottom_addr = 0x%lx\n", bottom_addr );*/
}
#endif
#ifdef RGC
  /* the color of free cells are GRAY */
  cp->rootcell.h.bix |= FREETAG;
  cp->rootcell.h.cix = -1; /* free tag */
  if((char *)cp < minmemory)
    minmemory = (char *)cp;
#endif
  cp->rootcell.h.cix = -1; /* free tag */
  buddy[k].bp= &cp->rootcell;
  buddy[k].count++;
  totalheap += s; freeheap += s;
  return(k);
  }

void splitheap(k,buddy)	/*heart of the allocator*/
register int k;
register struct buddyfree *buddy;
{ register bpointer b1,b2,bnext;
#if defined(BIX_DEBUG) || defined(DEBUG_COUNT)
  static int count;

  count++;
#endif

  b1= buddy[k].bp;	/*root buddy pointer*/
  bnext=b1->b.nextbcell;
  buddy[k].bp= bnext;	/*remove first element*/
  buddy[k].count--;
  b2= (bpointer)((long)b1+buddysize[k-1]*sizeof(pointer));
  if (k==2) {	/*b1 and b2 are of the same size*/
    b1->b.nextbcell=b2;
    b2->b.nextbcell=buddy[k-1].bp;
    buddy[k-1].bp=b1;
    buddy[k-1].count +=2;
#ifdef RGC
    b2->h.bix = 1 | FREETAG;
    b2->h.cix = -1; /* free tag */
#else
    b2->h.bix= 1;
    b2->h.cix = -1; /* free tag */
#endif
  } else {
    b1->b.nextbcell= buddy[k-1].bp;
    buddy[k-1].bp=b1;
    buddy[k-1].count++;
    b2->b.nextbcell=buddy[k-2].bp;
    buddy[k-2].bp=b2;
    buddy[k-2].count++;
#ifdef RGC
    b2->h.bix = (k-2 | FREETAG);
    b2->h.cix = -1; /* free tag */
#else
    b2->h.bix= k-2;
    b2->h.cix = -1; /* free tag */
#endif
  }
  b2->h.m=b1->h.m;
  b1->h.m=b1->h.b;
  b1->h.b=0; 
#ifdef RGC
  b1->h.bix = (k-1 | FREETAG);
#else
  b1->h.bix= k-1; 
#endif
  b2->h.b=1;
  b2->h.mark=b2->h.smark=b2->h.pmark=0;
  b1->h.nodispose=b2->h.nodispose=0;}

bpointer root_alloc_big(ctx, req)
register context *ctx;
register int req;	/*index to buddy: must be greater than 0*/
{ register int i, k;
  register bpointer b,b2;
  numunion nu;
  pointer gcm;

#if THREADED
  mutex_lock(&alloc_lock); 
#endif

  ctx->alloc_big_count++;

    k=req;
    while (buddy[k].bp==0) k++;	/*find blocks of adequate size*/
    if (k>=MAXBUDDY) {		/*no bigger free cell*/
      if (buddysize[req]<totalheap/8) {	/*relatively small cell is requested;*/
        gc();			/* then try garbage collection*/
	gcm=speval(GCMARGIN);
        while (freeheap < (totalheap*min(5.0,fltval(gcm))))
	  newchunk(req); /*still not enough space*/
        for (k=req; buddy[k].bp==0; ) k++;}
      if (k>=MAXBUDDY) {
        k=newchunk(req);
        if (k==ERR) { 
#if THREADED
	  mutex_unlock(&alloc_lock);
#endif
	  error(E_ALLOCATION);}}}

    while (req<k) { splitheap(k--,buddy); if (k>req) k--;}
    k=buddysize[req]-1;
    b=buddy[req].bp;
    b2=b->b.nextbcell;
    for (i=0; i<k; i++) b->b.c[i]=0;
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
#endif
  return(b);}

void root_alloc_small(ctx, req)
register context *ctx;
register int req;	/*index to buddy: must be greater than 0*/
{ register int i, j, k,kk;
  register bpointer b, b2;
  register struct buddyfree *tb=ctx->thr_buddy;
  static long buddyfill[MAXTHRBUDDY+1]={0,500,300,20,15,10,0};
  numunion nu;
  int collected=0;

#if THREADED
  mutex_lock(&alloc_lock); 
#endif
  
  ctx->alloc_small_count++;

  alloc_again:
  for (i=1; i<MAXTHRBUDDY; i++) {
    k=kk=buddyfill[i] - tb[i].count; /*how many cells are needed*/
    while (buddy[i].count < k) {   /*Do we have enough free in the root?*/
/*	fprintf(stderr, "free_count=%d; k=%d\n",buddy[i].count,k);  */
        j=i+1;
	while (buddy[j].bp==0) j++;
	if (j>=MAXBUDDY) {	/*no free cell*/
	  if (!collected) {
	    /* fprintf(stderr, "GC: free=%d total=%d, margin=%f\n",
			freeheap, totalheap, fltval(speval(GCMARGIN))); */
	    gc(); collected=1;
	    goto alloc_again;}
          while (freeheap<(totalheap*min(5.0,fltval(speval(GCMARGIN))))) {
	    j=newchunk(DEFAULTCHUNKINDEX); /*still not enough space*/
	    if (j==ERR) { 
#if THREADED
	      mutex_unlock(&alloc_lock); 
#endif
	      error(E_ALLOCATION);}} }
	if (j>=MAXBUDDY) {	/*hard fragmentation seen*/
	  j=newchunk(DEFAULTCHUNKINDEX);
	  if (j==ERR) { 
#if THREADED
	    mutex_unlock(&alloc_lock);
#endif
	    error(E_ALLOCATION);}} 
	splitheap(j, buddy);}
    /*sufficient free cells collected in the root free list*/
    if (k>0) {
      b=buddy[i].bp;
      while (k>0) { b2=b; b->h.cix=0; b=b->b.nextbcell; k--;}
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
      }}
#if THREADED
  mutex_unlock(&alloc_lock); 
#endif
  /*return(b);*/
  }

#ifndef RGC
pointer gc_alloc(s,e,cid,nils)	/*allocate heap of 's' longwords*/
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
  b->h.elmtype=e;
  b->h.cix=cid;
  b->h.extra=0;
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

  return(p);}

#endif /* RGC */


/****************************************************************/
/* gc: garbage collector
/****************************************************************/

#define DEFAULT_MAX_GCSTACK 65536*2
pointer *gcstack, *gcsplimit, *gcsp;
#define gcpush(v) (*lgcsp++=((pointer)v))
#define gcpop() (*--lgcsp)
#if Solaris2 
#define out_of_heap(p) ((int)p<(int)_end || (pointer)0x20000000<p)
#else /* Solaris2 */
#if Linux || Cygwin || Darwin
#if (WORD_SIZE == 64)
#define out_of_heap(p) ((unsigned long)p<(unsigned long)minmemory || (pointer)maxmemory <p)
#else
#define out_of_heap(p) ((unsigned int)p<(unsigned int)minmemory || (pointer)maxmemory <p)
#endif
#else /* Linux || Cygwin || Darwin */
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
#endif /* Linux || Cygwin || Darwin */
#endif /* Solaris2 */


pointer mark_root, marking, marking2;

void mark(p)
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


void newgcstack(oldsp)
register pointer *oldsp;
{ register pointer *oldstack, *stk, *newstack, *newgcsp;
  long top, oldsize, newsize;

  oldstack=stk=gcstack;
  oldsize=gcsplimit-gcstack;
  newsize=oldsize*2;
  top=oldsp-gcstack;
  newgcsp=newstack=(pointer *)malloc(newsize * sizeof(pointer)+16);
  if(isatty(0)) {
    fprintf(stderr, "\n;; extending gcstack %p[%ld] --> %p[%ld] top=%lx\n",
            oldstack, oldsize, newstack, newsize, top);}
  while (stk<oldsp) *newgcsp++= *stk++;
  gcstack=newstack;
  gcsplimit= &gcstack[newsize-10];
  gcsp= &gcstack[top];
  cfree(oldstack);
  }

int mark_state;
context *mark_ctx;
long mark_stack_root;
long mark_buddy_q;

void markall()
{ register pointer *p,*spsave;
  register int i,j;
  register context *ctx;
  register bpointer q;
/*#if defined(DEBUG_COUNT) || defined(MARK_DEBUG)*/
  static int count = 0;

  count++;
/*#endif*/

  mark_state=1;
#ifdef MARK_DEBUG
  printf( "markall:%d: mark(SYSTEM_OBJECTS)\n", count );
#endif
  mark(sysobj);		/*mark internally reachable objects*/
  mark_state=2;
#ifdef MARK_DEBUG
  printf( "markall:%d: mark(PACKAGE_LIST)\n", count );
#endif
  mark(pkglist);	/*mark all packages*/
  for (i=0; i<MAXTHREAD; i++) {
    /*mark everything reachable from stacks in euscontexts*/
    if ((ctx=euscontexts[i])) {
      mark_ctx=ctx; mark_state=3;
#ifdef MARK_DEBUG
      printf( "markall:%d: mark(threadobj %d)\n", count, i );
#endif
      mark(ctx->threadobj);
      mark_state=4;
      mark_stack_root=(long)ctx->stack;

      /* mark from thread's stack */
      for (p=ctx->stack; p<ctx->vsp; p++) {
	mark_state=(long)p;
#if (WORD_SIZE == 64)
	if ((((eusinteger_t)(*p) & 7L)==0L) && 
#else
	if ((((eusinteger_t)(*p) & 3)==0) && 
#endif
	    ((ctx->stack>(pointer *)*p) || ((pointer *)*p>ctx->stacklimit)))
		{ mark(*p); } ;}
      mark_state=0x10000;

      /* mark free list already acquired in local buddy list */
      for (j=1; j<MAXTHRBUDDY; j++) {
	q=ctx->thr_buddy[j].bp;
        mark_buddy_q=(long)q;
	while (q) { markon(q);
#ifdef MARK_DEBUG
		    printf( "markall:%d: markon 0x%ld\n", count, q );
#endif
 q=q->b.nextbcell; mark_state++;}
        }
      mark_state=0x20000;

      /* mark thread special variables */
#ifdef MARK_DEBUG
      printf( "markall:%d: mark(SPECIALS)\n", count );
#endif
      mark(ctx->specials);

      q=bpointerof(ctx->lastalloc);
      if (q && ispointer(q)) /* markon(q); */
#ifdef MARK_DEBUG
	printf( "markall:%d: mark(lastalloc)\n", count );
#endif
        mark(ctx->lastalloc);
      }}
  mark_state=5;
  for (i=0; i<MAXCLASS; i++) {
    if (ispointer(classtab[i].def)) mark(classtab[i].def); }
  mark_state=0;
  }

#ifndef RGC
void reclaim(p)
register bpointer p;
{ register int rbix,stat;
  register pointer s;
  s=makepointer(p);
  if (pisfilestream(s)) {
    if (!isint(s->c.fstream.fname) && s->c.fstream.direction!=NIL) {
      if (s->c.fstream.fd==makeint(0) || s->c.fstream.fd==makeint(1)) {
	fprintf(stderr,";; gc! bogus stream at %lx fd=%ld\n",
		(unsigned long int)s,intval(s->c.fstream.fd));}
#if (WORD_SIZE == 64)
      else if (s->c.fstream.fd == 0) {
        // Sometimes, s->c.fstream.fd is 0.
        // c.fstream.fd should be eus integer which least 2bits is 10.
        // So, the condition that s->c.fstream.fd is 0 is obviously bug.
        fprintf(stderr, ";; closing fstream was failed, %p, %d\n", s, s->cix);
      }
      else if ((s->c.stream.buffer == NULL) ||
               ((unsigned long)(s->c.stream.buffer) & 0x7L) != 0x0L ||
               s->c.stream.buffer->cix == -1) {
        // stream buffer already reclaimed?????
        // very dirty code for avoiding segmentation falut.
        // there are some bugs before here.
        fprintf(stderr, ";; bad stream buffer, %p\n", s->c.stream.buffer);
      }
#endif
      else if ((closestream(s)==0) && debug)
        fprintf(stderr,";; gc: dangling stream(address=%lx fd=%ld) is closed\n",
	        (unsigned long int)s,intval(s->c.fstream.fd)); } }
  p->h.cix= -1;
  rbix=p->h.bix;
  p->b.nextbcell=buddy[rbix].bp;
  buddy[rbix].bp=p; buddy[rbix].count++;
  freeheap+=buddysize[rbix];}
#endif

static bpointer mergecell(p,cbix)
register bpointer p;
int cbix;
/*the cell pointed by 'p' must not be marked*/
/*mergecell kindly returns next uncollectable cell address*/
{ register bpointer np,p2;
#if defined(DEBUG_COUNT) || defined(MERGE_DEBUG)
  static int count = 0;

  count++;
#endif
  np=nextbuddy(p);
  while (p->h.b==0 && (int)p->h.bix<cbix) {
    if (marked(np)) return(np);
    if (np->h.nodispose==1) return(np);
    p2=mergecell(np,cbix);	/*merge neighbor cell*/
    if (np->h.b==1) {		/*can be merged*/
      p->h.b=p->h.m;		/*merge them into bigger cell*/
      p->h.m=np->h.m;
      p->h.bix++;
#ifdef MERGE_DEBUG
      printf( "mergecell:%d:p=0x%lx, np=0x%lx\n", count, p, np );
#endif
      np=p2;}
    else {
#ifdef MERGE_DEBUG
	printf( "mergecell:%d:call reclaim:np=0x%lx\n", count, np );
#endif
      reclaim(np);
      return(p2);}}
  return(np);}
  
static void sweep(cp,gcmerge)
register struct chunk *cp;
register int gcmerge;
{ register int s;
  register bpointer p,np,tail;
#if defined(DEBUG_COUNT) || defined(SWEEP_DEBUG) || defined(MARK_DEBUG)
  static int count = 0;
  int count2 = 0;

  count++;
#endif
  s=buddysize[cp->chunkbix];
  p= &cp->rootcell;
  tail=(bpointer)((eusinteger_t)p+(s<<WORDSHIFT));/* ???? */
#ifdef SWEEP_DEBUG
  printf( "sweep:%d:top=0x%lx, tail=0x%lx\n", count, p, tail );
#endif
  while (p<tail) {
#ifdef SWEEP_DEBUG
      printf( "sweep:%d,%d:p=0x%lx:NIL->cix=%d\n", count, count2++, p, NIL->cix );
#endif
    if (marked(p)) {  /*don't reclaim*/
      markoff(p);
#ifdef MARK_DEBUG
		     printf( "sweep:%d,%d: markoff 0x%lx\n", count, count2, p );
#endif

 p=nextbuddy(p);}	/*don't collect*/
    else {
      if (p->h.nodispose==1) {
	/* fprintf(stderr,";; dispose %x\n", p); */
	if (dispose_count>=MAXDISPOSE) 
	  fprintf(stderr, "no more space for disposal processing\n");
        else dispose[dispose_count++]=makepointer(p);
	p=nextbuddy(p); }
      else if (gcmerge>freeheap) { /* no merge */
	np=nextbuddy(p);
        reclaim(p);
	p=np;} 
      else {
	np=mergecell(p,cp->chunkbix);	/*update free buddy list*/
        reclaim(p);
        p=np;} } }
  }  

void call_disposers()
{ int i;
  context *ctx=current_ctx;
  pointer p,a,curclass;
  /*if (debug) fprintf(stderr, ";; disposal call=%d\n", dispose_count);*/
  for (i=0; i<dispose_count; i++) {
    p=dispose[i];
    p->nodispose=0;
    a=(pointer)findmethod(ctx,K_DISPOSE,classof(p), &curclass); 
    if (debug) fprintf(stderr, ";; (send %p :dispose)\n", p);
    if (a!=NIL) csend(ctx,p,K_DISPOSE,0);
    }}

void sweepall()
{ 
  context *ctx;
  register struct chunk *chp;
  register int i, gcmerge;
  numunion nu;

  dispose_count=0;
  ctx=euscontexts[thr_self()];
  gcmerge=totalheap * min(1.0,fltval(speval(GCMARGIN)))
		    * max(0.1,fltval(speval(GCMERGE)));

  for (i=0; i<MAXBUDDY-1; i++) {
    buddy[i].bp=0;	/*purge buddies*/
    buddy[i].count=0;	/*clear free cell count*/
    }
  freeheap=0;
  for (chp=chunklist; chp!=0; chp=chp->nextchunk) sweep(chp,gcmerge);
  call_disposers();

  }

#if THREADED
void suspend_all_threads()
{ register int i, self, stat;
  
  self=thr_self();
  for (i=0; i<MAXTHREAD; i++) 
    if (i!=self && euscontexts[i]) {
      stat=thr_suspend(i);
      if (stat) fprintf(stderr, "gc cannot suspend thread %d\n",i);  }
  }

void resume_all_threads()
{ register int i, self, stat;
  
  self=thr_self();
  for (i=0; i<MAXTHREAD; i++) 
    if (i!=self && euscontexts[i]) {
      stat=thr_continue(i);
      if (stat) fprintf(stderr, "gc cannot resume thread %d\n",i);  }
  }

#endif

#if vxworks
void gc()
{ if (debug)  fprintf(stderr,"\n;; gc:");
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

void gc()
{ struct tms tbuf1,tbuf2,tbuf3;
  int i, r;
  context *ctx=euscontexts[thr_self()];

  if (debug)  fprintf(stderr,"\n;; gc: thread=%d ",thr_self());
  breakck;
  gccount++;
  times(&tbuf1);

#if THREADED
/*  mutex_lock(&alloc_lock);  is not needed since gc is assumed to be called
    from alloc_small or alloc_big and they have already locked alloc_lock.*/
  r = mutex_trylock(&mark_lock);
  if ( r != 0 ) {
    if (debug) fprintf(stderr, ";; gc:mutex_lock %d ", r);
    return;
  }
  rw_wrlock(&gc_lock);
  suspend_all_threads();
#endif

  markall();

  times(&tbuf2);
  marktime+=(tbuf2.tms_utime-tbuf1.tms_utime);
  sweepall();
  times(&tbuf3);
  sweeptime+=(tbuf3.tms_utime-tbuf2.tms_utime);

#if THREADED
  resume_all_threads();
  rw_unlock(&gc_lock);
  mutex_unlock(&mark_lock);
/*  mutex_unlock(&alloc_lock); */
#endif
  if (debug) {
    fprintf(stderr," free/total=%ld/%ld stack=%d ",
            freeheap,totalheap,(int)(myctx->vsp - myctx->stack));
    fprintf(stderr," mark=%ld sweep=%ld\n", marktime,sweeptime);
  }
  if (speval(QGCHOOK)!=NIL) {
    pointer gchook=speval(QGCHOOK);
    vpush(makeint(freeheap)); vpush(makeint(totalheap));
    ufuncall(ctx,gchook,gchook,(pointer)(ctx->vsp-2),ctx->bindfp,2);
    ctx->vsp -= 2;
    }
  breakck;
}
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
