/****************************************************************/
/* memory.c:	memory manager for eulisp			*/
/*	Copyright(c) Toshihiro MATSUI
/*		     Electrotechnical Laboratory,1986.
/****************************************************************/

#if vxworks
#include	<sys/types.h>
#else
#include 	<sys/types.h>
#include	<sys/times.h>
#endif

#include	"eus.h"
#if Solaris2
#include	<synch.h>
#include	<thread.h>
#endif

#define nextbuddy(p) ((bpointer)((int)p+(buddysize[p->h.bix]*sizeof(pointer))))
#define marked(p)  (p->h.mark)
#define markon(p)  p->h.mark=1
#define markoff(p) p->h.mark=0
#define myctx (euscontexts[thr_self()])

#if Solaris2 
extern _end();
#else
extern edata();
#endif

extern pointer QPARAGC;

char *maxmemory=(char *)0x100000;
long freeheap=0,totalheap=0;	/*size of heap left and allocated*/
struct chunk *chunklist=NULL;
/* timers */
long gccount,marktime,sweeptime;
long alloccount[MAXBUDDY];

#if Solaris2
mutex_t alloc_lock;
#endif

newchunk(k)
register int k;
{ register int s;
  register struct chunk *cp;
  if (k<DEFAULTCHUNKINDEX) k=DEFAULTCHUNKINDEX;
  if (QDEBUG && debug) fprintf(stderr,";; newchunk: k=%d\n",k);
  s=buddysize[k];
  cp=(struct chunk *)(malloc((s+2)*sizeof(pointer)+3) & ~3);
  maxmemory=(char *)sbrk(0);
  if (cp==NULL) return(ERR);	/*can't allocate new memory*/
  cp->nextchunk=chunklist;	/*link to chunk list*/
  chunklist=cp;
  cp->chunkbix=k;
  cp->rootcell.h.mark=0;
  cp->rootcell.h.b=1;		/*initial buddy marks*/
  cp->rootcell.h.m=0;
  cp->rootcell.h.bix=k;
  cp->rootcell.b.nextbcell=0;
  buddy[k].bp= &cp->rootcell;
  buddy[k].count++;
  totalheap += s; freeheap += s;
  return(k);
  }

static void splitheap(k,buddy)	/*heart of the allocator*/
register int k;
register struct buddyfree *buddy;
{ register bpointer b1,b2,bnext;
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
    b2->h.bix= 1;}
  else {
    b1->b.nextbcell= buddy[k-1].bp;
    buddy[k-1].bp=b1;
    buddy[k-1].count++;
    b2->b.nextbcell=buddy[k-2].bp;
    buddy[k-2].bp=b2;
    buddy[k-2].count++;
    b2->h.bix= k-2;}
  b2->h.m=b1->h.m;
  b1->h.m=b1->h.b;
  b1->h.b=0; b1->h.bix= k-1; b2->h.b=1;
  b2->h.mark=b2->h.smark=b2->h.pmark=0;}

bpointer root_alloc_big(ctx, req)
register context *ctx;
register int req;	/*index to buddy: must be greater than 0*/
{ register int i, k;
  register bpointer b,b2;
  numunion nu;

#if Solaris2
  mutex_lock(&alloc_lock); 
#endif

  ctx->alloc_big_count++;

    k=req;
    while (buddy[k].bp==0) k++;	/*find blocks of adequate size*/
    if (k>=MAXBUDDY) {		/*no bigger free cell*/
      if (buddysize[req]<totalheap/8) {	/*relatively small cell is requested;*/
        gc();			/* then try garbage collection*/
        while (freeheap<(totalheap*min(5.0,fltval(spevalof(GCMARGIN)))))
	  newchunk(req); /*still not enough space*/
        for (k=req; buddy[k].bp==0; ) k++;}
      if (k>=MAXBUDDY) {
        k=newchunk(req);
        if (k==ERR) { 
#if Solaris2
	  mutex_unlock(&alloc_lock);
#endif
	  error(E_ALLOCATION);}}}

    while (req<k) { splitheap(k--,&buddy); if (k>req) k--;}
    k=buddysize[req]-1;
    b=buddy[req].bp;
    b2=b->b.nextbcell;
    for (i=0; i<k; i++) b->b.c[i]=0;
    ctx->lastalloc=makepointer(b);
    buddy[req].bp=b2;
    buddy[req].count--;
    freeheap -= buddysize[req];
    alloccount[req]++;
#if Solaris2
  mutex_unlock(&alloc_lock); 
#endif
  return(b);}

root_alloc_small(ctx, req)
register context *ctx;
register int req;	/*index to buddy: must be greater than 0*/
{ register int i, j, k,kk;
  register bpointer b, b2;
  register struct buddyfree *tb=ctx->thr_buddy;
  static long buddyfill[MAXTHRBUDDY+1]={0,500,300,50,25,20,0};
  numunion nu;
  int collected=0;

#if Solaris2
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
			freeheap, totalheap, fltval(spevalof(GCMARGIN))); */
	    gc(); collected=1;
	    goto alloc_again;}
          while (freeheap<(totalheap*min(5.0,fltval(spevalof(GCMARGIN))))) {
	    j=newchunk(DEFAULTCHUNKINDEX); /*still not enough space*/
	    if (j==ERR) { mutex_unlock(&alloc_lock); error(E_ALLOCATION);}} }
	if (j>=MAXBUDDY) {	/*hard fragmentation seen*/
	  j=newchunk(DEFAULTCHUNKINDEX);
	  if (j==ERR) { mutex_unlock(&alloc_lock); error(E_ALLOCATION);}} 
	splitheap(j, &buddy);}
    /*sufficient free cells collected in the root free list*/
    if (k>0) {
      b=buddy[i].bp;
      while (k>0) { b2=b; b=b->b.nextbcell; k--;}
      b2->b.nextbcell=tb[i].bp;
      tb[i].bp=buddy[i].bp;
      buddy[i].bp=b;
      buddy[i].count -= kk;
      tb[i].count=buddyfill[i];
      freeheap -= buddysize[i]*kk;
      alloccount[i] += kk;
      }}
#if Solaris2
  mutex_unlock(&alloc_lock); 
#endif
  /*return(b);*/
  }

pointer halloc(req,e,cid)	/*heap alloc*/
register int req;	/*index to buddy: must be greater than 0*/
int e;			/*element type*/
int cid;		/*class id*/
{ register bpointer b;
  register pointer p;
  context *ctx=myctx;
  register struct buddyfree *tb= ctx->thr_buddy;

  if (/*req>=MAXTHRBUDDY*/ 1)  b=root_alloc_big(ctx, req);
  else { /*small cell is requested*/
    if (tb[req].count==0) /*find a cell in the local free list*/
      root_alloc_small(ctx, req);
    b=tb[req].bp;
    ctx->lastalloc=makepointer(b);
    tb[req].bp=b->b.nextbcell;
    tb[req].count--;}
  b->h.elmtype=e;
  b->h.cix=cid;
  p=makepointer(b);
  return(p);}

pointer allocx(s,e,cid,nils)	/*allocate heap of 's' longwords*/
register int s,nils;
int e,cid;
{ register int bs=1,i,ss;
  register cell *c;
  register pointer *v;
  register bpointer b;
  ss=max(3,s+1);	 /*one more word for the allocation information*/
  while (buddysize[bs]<ss) bs++;
  if (bs>=MAXBUDDY) return(NULL);

/*  c=halloc(bs,e,cid); */

  b=root_alloc_big(myctx, bs);
  b->h.elmtype=e;
  b->h.cix=cid;
  c=makepointer(b);

  i=buddysize[bs]-1;
  v=c->c.obj.iv;
  while (nils<s) v[nils++]=NIL;	/*fill NILs in user's  slots*/
  while (s<i) v[s++]=NULL;	/*fill NULLs in buddy-cells extra slots*/
  return(c);}

pointer alloc(s,e,cid,nils)	/*allocate heap of 's' longwords*/
register int s,nils;
int e,cid;
{ register int req=1,i,ss,k;
  register cell *c;
  register pointer *v;
  register bpointer b,b2;
  register context *ctx=myctx;
  numunion nu;

  ss=max(3,s+1);	 /*one more word for the allocation information*/
  while (buddysize[req]<ss) req++;
  if (req>=MAXBUDDY) return(NULL);

  k=req;
  mutex_lock(&alloc_lock); 

    while (buddy[k].bp==0) k++;	/*find blocks of adequate size*/
    if (k>=MAXBUDDY) {		/*no bigger free cell*/
      if (buddysize[req]<totalheap/8) {	/*relatively small cell is requested;*/
        gc();			/* then try garbage collection*/
        while (freeheap<(totalheap*min(5.0,fltval(spevalof(GCMARGIN)))))
	  newchunk(req); /*still not enough space*/
        for (k=req; buddy[k].bp==0; ) k++;}
      if (k>=MAXBUDDY) {
        k=newchunk(req);
        if (k==ERR) {  mutex_unlock(&alloc_lock); error(E_ALLOCATION);}}}
    while (req<k) { splitheap(k--,&buddy); if (k>req) k--;}
    k=buddysize[req]-1;
    b=buddy[req].bp;
    b2=b->b.nextbcell;
    for (i=0; i<k; i++) b->b.c[i]=0;
    b->h.elmtype=e;
    b->h.cix=cid;
    c=makepointer(b);
    ctx->lastalloc=c;
    buddy[req].bp=b2;
    buddy[req].count--;
    freeheap -= buddysize[req];
    alloccount[req]++;
  mutex_unlock(&alloc_lock); 

  i=buddysize[req]-1;
  v=c->c.obj.iv;
  while (nils<s) v[nils++]=NIL;	/*fill NILs in user's  slots*/
  return(c);}



/****************************************************************/
/* gc: garbage collector
/****************************************************************/

#define DEFAULT_MAX_GCSTACK 65536*2
pointer *gcstack, *gcsplimit, *gcsp;
#define gcpush(v) (*lgcsp++=((pointer)v))
#define gcpop() (*--lgcsp)

pointer mark_root, marking, marking2;

mark(p)
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
#if Solaris2
  if ((int)p<(int)_end || (pointer)0x20000000<p) goto markloop;
#else
  if ((int)p<(int)edata || (pointer)0x20000000<p) goto markloop;
#endif
  bp=bpointerof(p);
  if (marked(bp)) goto markloop;	/*already marked*/
  markon(bp);			/*mark it first to avoid endless marking*/
  if (pisclosure(p)) goto markloop;	/*avoid marking contents of closure*/
  marking=p;
  if (bp->h.elmtype==ELM_FIXED) {	/*contents are all pointers*/
    s=buddysize[bp->h.bix]-1;
    while (lgcsp+s>gcsplimit) { newgcstack(lgcsp); lgcsp=gcsp;}
    for (i=0; i<s; i++) {
	p2=p->c.obj.iv[i];
	if (ispointer(p2)) /* && !marked(bpointerof(p2)))*/  gcpush(p2); }
    goto markloop;}
  else if (bp->h.elmtype==ELM_POINTER) { /*varing number of pointers*/
    s=vecsize(p);
    while (lgcsp+s>gcsplimit) { newgcstack(lgcsp); lgcsp=gcsp;}
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

int mark_state;

markall()
{ register pointer *p,*spsave;
  register int i,j;
  register context *ctx;
  register bpointer q;

  mark_state=1;
  mark(sysobj);		/*mark internally reachable objects*/
  mark_state=2;
  mark(pkglist);	/*mark all packages*/
  for (i=0; i<MAXTHREAD; i++) {
    /*mark everything reachable from stacks in euscontexts*/
    if (ctx=euscontexts[i]) {
      mark_state=ctx;
      for (p=ctx->stack; p<ctx->vsp; p++) {
	mark_state==(int)p;
	if ((((int)(*p) & 3)==0) && 
	    ((ctx->stack>(pointer *)*p) || ((pointer *)*p>ctx->stacklimit)))
		{  mark(*p); } ;}
      mark_state++;
      mark(ctx->lastalloc);
      mark_state=0x10000;
      for (j=1; j<MAXTHRBUDDY; j++) {
	q=ctx->thr_buddy[j].bp;
	while (q) { markon(q); q=q->b.nextbcell; mark_state++;}
        }
      }}
  mark_state=5;
  for (i=0; i<MAXCLASS; i++) {
    if (ispointer(classtab[i].def)) mark(classtab[i].def); }
  mark_state=0;
  }

reclaim(p)
register bpointer p;
{ register int rbix,stat;
  register pointer s;
  s=makepointer(p);
  if (pisfilestream(s)) {
    if (!isint(s->c.fstream.fname) && s->c.fstream.direction!=NIL) {
      if (s->c.fstream.fd==makeint(0) || s->c.fstream.fd==makeint(1)) {
	fprintf(stderr,";; gc! bogus stream at %x fd=%d\n",
		(int)s,intval(s->c.fstream.fd));}
      else if ((closestream(s)==0) && debug)
        fprintf(stderr,";; gc: dangling stream(address=%x fd=%d) is closed\n",
	        (int)s,intval(s->c.fstream.fd)); } }
  p->h.cix= -1;
  rbix=p->h.bix;
  p->b.nextbcell=buddy[rbix].bp;
  buddy[rbix].bp=p; buddy[rbix].count++;
  freeheap+=buddysize[rbix];}

static bpointer mergecell(p,cbix)
register bpointer p;
int cbix;
/*the cell pointed by 'p' must not be marked*/
/*mergecell kindly returns next uncollectable cell address*/
{ register bpointer np,p2;
  np=nextbuddy(p);
  while (p->h.b==0 && (int)p->h.bix<cbix) {
    if (marked(np)) return(np);
    p2=mergecell(np,cbix);	/*merge neighbor cell*/
    if (np->h.b==1) {		/*can be merged*/
      p->h.b=p->h.m;		/*merge them into bigger cell*/
      p->h.m=np->h.m;
      p->h.bix++;
      np=p2;}
    else {
      reclaim(np);
      return(p2);}}
  return(np);}
  
static void sweep(cp,gcmerge)
register struct chunk *cp;
register int gcmerge;
{ register int s;
  register bpointer p,np,tail;

  s=buddysize[cp->chunkbix];
  p= &cp->rootcell;
  tail=(bpointer)((int)p+(s<<2));
  while (p<tail) {
    if (marked(p)) { markoff(p); p=nextbuddy(p);}	/*don't collect*/
    else if (gcmerge>freeheap) { /* no merge */
	np=nextbuddy(p);
        reclaim(p);
	p=np;} 
    else {
	np=mergecell(p,cp->chunkbix);	/*update free buddy list*/
        reclaim(p);
        p=np;} }
  }  

void sweepall()
{ 
  register struct chunk *chp;
  register int i, gcmerge;
  numunion nu;
  gcmerge=totalheap * min(1.0,fltval(spevalof(GCMARGIN)))
		    * max(0.1,fltval(spevalof(GCMERGE)));

  for (i=0; i<MAXBUDDY-1; i++) {
    buddy[i].bp=0;	/*purge buddies*/
    buddy[i].count=0;	/*clear free cell count*/
    }
  freeheap=0;
  for (chp=chunklist; chp!=0; chp=chp->nextchunk) sweep(chp,gcmerge);
  }

#if vxworks
gc()
{ if (debug)  fprintf(stderr,"\n;; gc:");
  breakck;
  gccount++;
  markall();
  sweepall();
  if (debug) {
    fprintf(stderr," free/total=%d/%d stack=%d ",
        	freeheap,totalheap,markctx->vsp-markctx->stack);
    }
  breakck;
  }

#else 

gc()
{ struct tms tbuf1,tbuf2,tbuf3;

  if (debug)  fprintf(stderr,"\n;; gc: thread=%d ",thr_self());
  breakck;
  gccount++;
  times(&tbuf1);

#if Solaris2
  mutex_unlock(&mark_lock);
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

#if Solaris2
  mutex_unlock(&mark_lock);
#endif
  breakck;
}
#endif

