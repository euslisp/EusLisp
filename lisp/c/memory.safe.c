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
#include	<synch.h>
#include	<thread.h>

#define nextbuddy(p) ((bpointer)((int)p+(buddy[p->h.bix].size<<2)))
#define marked(p)  (p->h.mark)
#define markon(p)  p->h.mark=1
#define markoff(p) p->h.mark=0

extern _end();

char *maxmemory=(char *)0x100000;
long freeheap=0,totalheap=0;	/*size of heap left and allocated*/
struct chunk *chunklist=NULL;
/* timers */
long gccount,marktime,sweeptime;
long alloccount[MAXBUDDY];

mutex_t alloc_lock;

newchunk(k)
register int k;
{ register int s;
  register struct chunk *cp;
  if (k<DEFAULTCHUNKINDEX) k=DEFAULTCHUNKINDEX;
  if (QDEBUG && debug) fprintf(stderr,";; newchunk: k=%d\n",k);
  s=buddy[k].size;
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
  totalheap += s; freeheap += s;
  return(k);
  }

static void splitheap(k)	/*heart of the allocator*/
register int k;
{ register bpointer b1,b2,bnext;
  b1= buddy[k].bp;	/*root buddy pointer*/
  bnext=b1->b.nextbcell;
  buddy[k].bp= bnext;	/*remove first element*/
  b2= (bpointer)((long)b1+buddy[k-1].size*sizeof(pointer));
  if (k==2) {	/*b1 and b2 are of the same size*/
    b1->b.nextbcell=b2;
    b2->b.nextbcell=buddy[k-1].bp;
    buddy[k-1].bp=b1;
    b2->h.bix= 1;}
  else {
    b1->b.nextbcell= buddy[k-1].bp;
    buddy[k-1].bp=b1;
    b2->b.nextbcell=buddy[k-2].bp;
    buddy[k-2].bp=b2;
    b2->h.bix= k-2;}
  b2->h.m=b1->h.m;
  b1->h.m=b1->h.b;
  b1->h.b=0; b1->h.bix= k-1; b2->h.b=1;
  b2->h.mark=b2->h.smark=b2->h.pmark=0;}

pointer halloc(req,e,cid)
register int req;	/*index to buddy: must be greater than 0*/
int e;			/*element type*/
int cid;		/*class id*/
{ register int k=req;
  register struct buddybase *bbreq= &buddy[req];
  register bpointer b;
  register pointer p;
  numunion nu;

  mutex_lock(&alloc_lock);
  while (buddy[k].bp==0) k++;	/*find blocks of adequate size*/
  if (k>=MAXBUDDY) {		/*no enough room*/
    if (bbreq->size<totalheap/8) {	/*relatively small cell is requested;*/
      gc();			/* then try garbage collection*/
      while (freeheap<(totalheap*min(5.0,fltval(spevalof(GCMARGIN)))))
	newchunk(req); /*still not enough space*/
      for (k=req; buddy[k].bp==0; ) k++;}
    if (k>=MAXBUDDY) {
      k=newchunk(req);
      if (k==ERR) { mutex_unlock(&alloc_lock); error(E_ALLOCATION);}}}
  while (req<k) { splitheap(k--); if (k>req) k--;}
  b=bbreq->bp;
  b->h.elmtype=e;
  b->h.cix=cid;
  bbreq->bp=b->b.nextbcell;
  freeheap -= bbreq->size;
  alloccount[k]++;
  p=makepointer(b);
  euscontexts[thr_self()]->lastalloc=p;
  mutex_unlock(&alloc_lock);
  return(p);}

pointer alloc(s,e,cid,nils)	/*allocate heap of 's' longwords*/
register int s,nils;
int e,cid;
{ register int i=1,ss;
  register cell *c;
  register pointer *v;
  ss=max(3,s+1);	 /*one more word for the allocation information*/
  while (buddy[i].size<ss) i++;
  if (i>=MAXBUDDY) return(NULL);
  c=halloc(i,e,cid);
  i=buddy[i].size-1;
  v=c->c.obj.iv;
  while (nils<s) v[nils++]=NIL;	/*fill NILs in user's  slots*/
  while (s<i) v[s++]=NULL;	/*fill NULLs in buddy-cells extra slots*/
  return(c);}

/****************************************************************/
/* gc: garbage collector
/****************************************************************/

context *markctx;

mark(p)
register pointer p;
{ register int s;
  register bpointer bp;

  if ((int)p<(int)_end || (pointer)0x20000000<p) return(NULL);
markagain:
  bp=bpointerof(p);
  if (marked(bp)) return;	/*already marked*/
  markon(bp);			/*mark it first to avoid endless marking*/
  if (pisclosure(p)) return;	/*avoid marking contents of closure*/
  if (bp->h.elmtype==ELM_FIXED) {	/*contents are all pointers*/
    if (bp->h.cix==conscp.cix) {	/*save stack when cons*/
      p=bp->b.c[0];
      if ((int)p>(int)_end && (int)p<0x20000000 && ispointer(p)) mark(p);
      p=bp->b.c[1];
      if ((int)p>(int)_end && (int)p<0x20000000 && ispointer(p)) goto markagain; 
      }
    else {
      s=buddy[bp->h.bix].size-1;
      while (s>0) {
        p=bp->b.c[--s];
        if (ispointer(p)) mark(p);}}}
  else if (bp->h.elmtype==ELM_POINTER) { /*varing number of pointers*/
    s=buddy[bp->h.bix].size-1;
    while (--s>0) {
      p=bp->b.c[s];
      if (ispointer(p)) mark(p);}
    }
  }

markall()
{ register pointer *p,*spsave;
  register int i,j;
  register context *ctx;
  markctx=euscontexts[thr_self()];
  mark(sysobj);		/*mark internally reachable objects*/
  mark(pkglist);	/*mark all packages*/
  for (i=0; i<MAXTHREAD; i++) {
    /*mark everything reachable from stacks in euscontexts*/
    if (ctx=euscontexts[i]) {
      markctx=ctx;
      for (p=ctx->stack; p<ctx->vsp; p++)
        if (ispointer(*p) && ((ctx->stack>(pointer *)*p)
	    || ((pointer *)*p>ctx->stacklimit)))  {  mark(*p); } ;
      mark(ctx->lastalloc);}}
  for (i=0; i<MAXCLASS; i++) {
    markctx=euscontexts[thr_self()];
    if (ispointer(classtab[i].def)) mark(classtab[i].def); }
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
  buddy[rbix].bp=p;
  freeheap+=buddy[rbix].size;}

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
  
static void sweep(cp)
struct chunk *cp;
{ register int s,gcmerge;
  register bpointer p,np,tail;
  numunion nu;

  gcmerge=totalheap * min(1.0,fltval(spevalof(GCMARGIN)))
		    * max(0.1,fltval(spevalof(GCMERGE)));
  s=buddy[cp->chunkbix].size;
  p= &cp->rootcell;
  tail=(bpointer)((int)p+(s<<2));
  while (p<tail) {
    if (marked(p)) { markoff(p); p=nextbuddy(p);}	/*don't collect*/
    else if (gcmerge<freeheap) { /* no merge */
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
  register int i;
  for (i=0; i<MAXBUDDY-1; i++) buddy[i].bp=0;	/*purge buddies*/
  freeheap=0;
  for (chp=chunklist; chp!=0; chp=chp->nextchunk) sweep(chp);
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

  if (debug)  fprintf(stderr,"\n;; gc:");
  breakck;
  mutex_lock(&mark_lock);
  gccount++;
  times(&tbuf1);
  markall();
  times(&tbuf2);
  marktime+=(tbuf2.tms_utime-tbuf1.tms_utime);
  sweepall();
  times(&tbuf3);
  sweeptime+=(tbuf3.tms_utime-tbuf2.tms_utime);
  if (debug) {
    fprintf(stderr," thread=%d free/total=%d/%d stack=%d ",
		thr_self(),
		freeheap,totalheap,markctx->vsp - markctx->stack);
    fprintf(stderr," mark=%d sweep=%d\n", marktime,sweeptime);}
  mutex_unlock(&mark_lock);
  breakck;
}
#endif

