/****************************************************************/
/* system management functions
/*	1986-Aug
/*	T.Matsui, ETL 
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"

#define p_marked(p) (bpointerof(p)->h.pmark)
#define p_mark_on(p) (bpointerof(p)->h.pmark=1)
#define p_mark_off(p) (bpointerof(p)->h.pmark=0)

extern long freeheap,totalheap;
extern struct chunk *chunklist;
extern long gccount,marktime,sweeptime;
extern pointer stacknlist(),stacklist();
extern jmp_buf topjbuf;
extern long alloccount[MAXBUDDY];

pointer GEESEE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ gc();
  return(cons(ctx,makeint(freeheap),
	      cons(ctx,makeint(totalheap),NIL)));}

pointer SBCOUNT(ctx,n,argv)
context *ctx;
int n; /* unused argument */
pointer *argv; /* unused argument */
{  return(makeint(ctx->special_bind_count));}

pointer GCTIME(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(cons(ctx,makeint(gccount),
	      cons(ctx,makeint(marktime),
	           cons(ctx,makeint(sweeptime),NIL))));}

pointer ALLOC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int ss,i=2;
  ckarg(1);
  ss=ckintval(argv[0]);
  while (buddysize[i]<ss) i++;
  if (i>=MAXBUDDY) error(E_ALLOCATION);
#if defined(RGC) && !defined(__HEAP_EXPANDABLE)
  /* heap isn't expandable */
#else
#if defined(RGC)
  lock_collector;
  DPRINT1("ALLOC: newchunk");
#endif
  i=newchunk(i);
#if defined(RGC)
  unlock_collector;
#endif
#endif
  if (i==ERR) error(E_ALLOCATION);
  else return(makeint(buddysize[i]));}

pointer NEWSTACK(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ eusinteger_t newsize;
  if (n==0) return(makeint((ctx->stacklimit+100-ctx->stack)));
  else {
    newsize=ckintval(argv[0]);
    if (newsize>1024*1024*256) error(E_USER,(pointer)"too big stack"); /*max 256MW*/
    allocate_stack(ctx,newsize);
    euslongjmp(topjbuf,newsize);}
  }

pointer DISPOSE_HOOK(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ 
#ifndef RGC
  pointer p;
  ckarg2(1,2);
  p=argv[0];
  if (!ispointer(p)) error(E_NOOBJECT);
  else {
    if (n==1) return((p->nodispose==0)?NIL:T);
    else {
      p->nodispose=((argv[1]==NIL)?0:1); 
      return(argv[1]); }
    }
#endif
  }

#if Solaris2
extern _end();
#else
extern eusinteger_t edata();
#endif

int xmark(ctx,p)
register context *ctx;
register pointer p;
{ register int s;
  register bpointer bp;
#if !alpha && system5
  if (p<(pointer)0x100000) return(NULL);
#endif
#if Solaris2
  if ((eusinteger_t)p<(eusinteger_t)_end) return(NULL);
#elif sun3 || sun4 || news || (i386 && (!Cygwin && !Darwin)) || alpha || mips /* Cygwin does not have edata */
  if ((eusinteger_t)p<(eusinteger_t)edata) return(NULL);
#endif
#if sun4 || vax || i386 
  if ((&ctx->stack[0]<=p) && (p<= &ctx->stack[MAXSTACK])) return(NULL);
#endif
  if (issymbol(p)) return((long int)NULL);
#if (WORD_SIZE == 64)
  bp=(bpointer)((eusinteger_t)p & ~3L);
#else
  bp=(bpointer)((eusinteger_t)p & ~3);
#endif
  if (marked(bp)) return(0);	/*already marked*/
  markon(bp);	/*mark it first to avoid endless marking*/
  if (bp->h.elmtype==ELM_FIXED) {	/*contents are all pointers*/
#ifdef RGC
    s=buddysize[bp->h.bix&TAGMASK]-1;
#else
    s=buddysize[bp->h.bix]-1;
#endif
    while (s>0) {
      p=bp->b.c[--s];
      if (ispointer(p)) xmark(ctx,p);}}
  else if (bp->h.elmtype==ELM_POINTER) { /*varing pointers*/
    s=intval(bp->b.c[0]);
    while (s>0) {
      p=bp->b.c[s--];
      if (ispointer(p)) xmark(ctx,p);}
    }
  }

int xcollect(ctx,p)
register context *ctx;
register pointer p;
{ register int s,r=0;
  register bpointer bp;
#if !alpha && system5
 if (p<(pointer)0x100000) return(NULL);
#endif
#if sun
  if (p<(pointer)0x10000) return(NULL);
#endif
#if (WORD_SIZE == 64)
  bp=(bpointer)((eusinteger_t)p & ~3L/*0xfffffffc*/);/* ???? */
#else
  bp=(bpointer)((eusinteger_t)p & ~3/*0xfffffffc*/);/* ???? */
#endif
  if (marked(bp)) {
    markoff(bp);
    reclaim(bp);
    if (bp->h.elmtype==ELM_FIXED) {	/*contents are all pointers*/
#ifdef RGC
      s=buddysize[bp->h.bix&TAGMASK]-1;
#else
      s=buddysize[bp->h.bix]-1;
#endif
      r=s;
      while (s>0) {
        p=bp->b.c[--s];
        if (ispointer(p)) r+=xcollect(ctx,p);}}   /* ???? */
    else if (bp->h.elmtype==ELM_POINTER) { /*varing pointers*/
      s=intval(bp->b.c[0]);
      r=s+1;
      while (s>0) {
        p=bp->b.c[s--];
        if (ispointer(p)) r+=xcollect(ctx,p);}   /* ???? */
      }
    return(r);}
  else return(0); }

#ifndef RGC
pointer RECLAIM(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer p;
  bpointer bp;
  ckarg(1);
  p=argv[0];
  if (!ispointer(p)) return(0);
  bp=bpointerof(p);
#if THREADED
  mutex_lock(&alloc_lock);
#endif
  reclaim(bp);
#if THREADED
  mutex_unlock(&alloc_lock);
#endif
#ifdef RGC
  return(makeint(buddysize[bp->h.bix&TAGMASK]-1));
#else
  return(makeint(buddysize[bp->h.bix]-1));
#endif
}

pointer RECLTREE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer p;
  ckarg(1);
  p=argv[0];
  if (!ispointer(p)) return(0);
#if THREADED
  mutex_lock(&mark_lock);
  mark_locking="RECLTREE";
#endif
  xmark(ctx,p);
  n=xcollect(ctx,p);
#if THREADED
  mutex_unlock(&mark_lock);
#endif
  return(makeint(n));}

#else /* RGC */
pointer RECLAIM(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{

}

pointer RECLTREE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{

}
#endif /* RGC */

static int cell_count, object_size, cell_size, count_symbol;

pointer objsize1(x)
pointer x;
{ int etype,s,i;
  if (isnum(x) || x==UNBOUND || (!count_symbol && pissymbol(x))
      || p_marked(x)) return(0);
  p_mark_on(x);
  etype=elmtypeof(x);
  cell_count++;
  if (isvector(x)) s=vecsize(x);  else s=objsize(x);
  cell_size+=buddysize[bixof(x)];
  switch(etype) {
    case ELM_FIXED: object_size+= s;
		for (i=0; i<s; i++) objsize1(x->c.obj.iv[i]);
		break;
    case ELM_BIT: object_size+=1+(s+WORD_SIZE-1)/WORD_SIZE; break;
    case ELM_BYTE: case ELM_CHAR:
      object_size += 1+(s+sizeof(eusinteger_t))/sizeof(eusinteger_t); break;
    case ELM_POINTER: object_size+=1+s; 
		for (i=0; i<s; i++) objsize1(x->c.vec.v[i]);
		break;
    case ELM_INT: case ELM_FLOAT: object_size+=1+s; break;}
  }

void objsize2(x)
pointer x;
{ int etype,s,i;
  pointer y;
  if (isnum(x) || x==UNBOUND || (!count_symbol && pissymbol(x)) ||
      !p_marked(x)) return;
  p_mark_off(x);
  etype=elmtypeof(x);
  if (isvector(x)) s=vecsize(x); else s=objsize(x);
  switch(etype) {
    case ELM_FIXED:
		for (i=0; i<s; i++) objsize2(x->c.obj.iv[i]);
		break;
    case ELM_POINTER:
		for (i=0; i<s; i++) objsize2(x->c.vec.v[i]);
		break;}
  }

pointer OBJSIZE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  ckarg2(1,2);
  if (n==2) count_symbol=(argv[1]!=NIL); else count_symbol=0;
  cell_count=object_size=cell_size=0;
#if THREADED
  mutex_lock(&mark_lock);
  mark_locking="OBJSIZE";
#endif
  objsize1(a);
  objsize2(a);
#if THREADED
  mutex_unlock(&mark_lock);
#endif
  return(cons(ctx,makeint(cell_count),
	      cons(ctx,makeint(object_size),
			cons(ctx,makeint(cell_size),NIL))));}

pointer BKTRACE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int i,j;
  pointer r=NIL;
  struct callframe *cfp=ctx->callfp;
  ckarg(1);
  i=j=ckintval(argv[0]);
  while (i-->0) {
    if (cfp==NULL) break;
    vpush(cfp->form); cfp=cfp->vlink;}
  while (--j>i) r=cons(ctx,vpop(),r);
  return(r);}

pointer MEMORY_REPORT(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{
  int fcount[MAXBUDDY],tcount[MAXBUDDY];
  eusfloat_t loss[MAXBUDDY];
  register int i,j;
  int s;
  bpointer bp,p,tail;
  struct chunk *cp;
  char cbuf[100];
  pointer outs;

  outs=(pointer)getoutstream(ctx,n+1,argv[0]);
  for (i=1; i<MAXBUDDY; i++) {
    s=0;
    bp=buddy[i].bp;
    while (0 < (eusinteger_t)bp) { s++; bp=bp->b.nextbcell;}
    fcount[i]=s; tcount[i]=0;}
  cp=chunklist;
  while (cp) {
    s=buddysize[cp->chunkbix];
    p= &cp->rootcell;
    tail=(bpointer)((eusinteger_t)p+(s<<WORDSHIFT));/* ???? */
    while (p<tail) {
#ifdef RGC
      i=p->h.bix&TAGMASK;
#else
      i=p->h.bix;
#endif
      tcount[i]++;
      p=(bpointer)((eusinteger_t)p+(buddysize[i]<<WORDSHIFT));}/* ???? */
    cp=cp->nextchunk;}

  sprintf(cbuf,"buddy   size  free   total   total-size  wanted   wanted-size\n");
  writestr(outs,(byte *)cbuf,strlen(cbuf));
  
  for(i=1; i<MAXBUDDY; i++) {
    sprintf(cbuf,"%4d %7ld %5d  %6d  %8ld  %8ld %10ld\n",
	    i,buddysize[i],fcount[i],tcount[i], tcount[i]*buddysize[i],
	    alloccount[i],alloccount[i]*buddysize[i]);
    writestr(outs,(byte *)cbuf,strlen(cbuf)); }

  sprintf(cbuf, "\ncontext  big_alloc   small_alloc\n");
  writestr(outs,(byte *)cbuf,strlen(cbuf));
  for (i=1; i<MAXTHREAD; i++) {
    if (euscontexts[i]) {
      sprintf(cbuf,"%4d %12d %12d\n",
	    i, euscontexts[i]->alloc_big_count, euscontexts[i]->alloc_small_count);
      writestr(outs,(byte *)cbuf,strlen(cbuf)); }
    }
  return(T);
  }

pointer CLEAR_ALLOCCOUNT(ctx,n,argv)
register context *ctx;
int n; /* unused argument */
pointer *argv; /* unused argument */
{ register int i;
  for (i=1; i<MAXBUDDY; i++) alloccount[i]=0; 
  for (i=1; i<MAXTHREAD; i++) {
    if (euscontexts[i]) {
      euscontexts[i]->alloc_big_count=euscontexts[i]->alloc_small_count;}}
  return(NIL);}

pointer ROOM(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int counts[MAXCLASS],sizes[MAXCLASS];
  int holecount=0,holesize=0;
  register int i,s;
  char buf[256];
  struct chunk *chp;
  pointer klass,strm;
  bpointer b,tail;

  strm=(pointer)getoutstream(ctx,n+1,argv[0]);
  for(i=0; i<MAXCLASS; i++) counts[i]=sizes[i]=0;
#if THREADED
  mutex_lock(&mark_lock);
  rw_wrlock(&gc_lock);
  mark_locking="ROOM";
#endif
  markall();
  for (chp=chunklist; chp!=0; chp=chp->nextchunk) {
    s=buddysize[chp->chunkbix];
    b= &chp->rootcell;
    tail=(bpointer)((eusinteger_t)b+(s<<WORDSHIFT));/* ???? */
    while (b<tail) {
      if (marked(b)) {
	i=b->h.cix;
	if (i<0 || i>=MAXCLASS)
	  fprintf(stderr,"bad cid %d at %p, bix=%d\n",i,b,b->h.bix);
        else {
	  counts[i]++;
#ifdef RGC
	  sizes[i]+=buddysize[b->h.bix&TAGMASK]; 
#else
	  sizes[i]+=buddysize[b->h.bix]; 
#endif
        }}
      else {
	holecount++;
#ifdef RGC
	holesize+=buddysize[b->h.bix&TAGMASK];
#else
	holesize+=buddysize[b->h.bix];
#endif
      }
      b=nextbuddy(b);} }
  sweepall();
#if THREADED
  rw_unlock(&gc_lock);
  mutex_unlock(&mark_lock);
#endif
  for (i=0; i<MAXCLASS; i++) {
    klass=classtab[i].def;
    if (klass && isclass(klass)) {
      sprintf(buf,"%32s%7d cells %7d words %6ldKB\n", 
	     klass->c.cls.name->c.sym.pname->c.str.chars,
	     counts[i],sizes[i],sizes[i]*sizeof(pointer)/1024);
      writestr(strm,(byte *)buf,strlen(buf)); } }
  sprintf(buf,"%32s%7d cells %7d words %6ldKB\n","holes",holecount,
	  holesize,holesize*sizeof(pointer)/1024);
  writestr(strm,(byte *)buf,strlen(buf));
  return(NIL);}

pointer FREE_COUNTS(ctx,n,argv)
register context *ctx;
int n; /* unused argument */
pointer *argv; /* unused argument */
{ int i;
  char buf[256];
  pointer strm;
  extern pointer QTERMIO;
  strm=Spevalof(QTERMIO);
  strm=strm->c.iostream.out;
  for (i=0; i<MAXBUDDY; i++) {
    sprintf(buf, "%3d %10ld * %6d = %10ld\n",
	 i, buddysize[i], buddy[i].count, buddysize[i]*buddy[i].count);
    writestr(strm,(byte *)buf,strlen(buf));
    }
  return(T);}

pointer LIST_ALL_CHUNKS(ctx,n,argv)
register context *ctx;
int n; /* unused argument */
pointer *argv; /* unused argument */
{ pointer r=NIL,p;
  struct chunk *cnk;
  ckarg(0);
  for (cnk=chunklist; cnk!=NULL; cnk=cnk->nextchunk) {
    vpush(r);
    p=cons(ctx,makeint((eusinteger_t)cnk),cons(ctx,makeint(buddysize[cnk->chunkbix]),NIL));
    r=cons(ctx,p,vpop());}
  return(r);}

pointer INSTANCELIST(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer klass;
  register pointer r=NIL;
  register short cid;
  struct chunk *chp;
  pointer *spsave=ctx->vsp;
  int s,sub=0,objcid;
  bpointer b,tail;

  ckarg2(1,2);
  if (n==2) sub=(argv[1]!=NIL);
  klass=argv[0];
  if (!isclass(klass)) error(E_NOCLASS);
  cid=intval(klass->c.cls.cix);
#if THREADED
  mutex_lock(&mark_lock);
  mark_locking="INSTANCELIST";
#endif
  markall();
  for (chp=chunklist; chp!=0; chp=chp->nextchunk) {
    s=buddysize[chp->chunkbix];
    b= &chp->rootcell;
    tail=(bpointer)((eusinteger_t)b+(s<<WORDSHIFT));/* ???? */
    while (b<tail) {
      if (marked(b)) {
	objcid=b->h.cix;
	if (objcid==cid || 
	    (sub && (objcid>=cid && objcid<=classtab[cid].subcix))) {
	  vpush(makepointer(b));
          if (ctx->vsp >= ctx->stacklimit) {
	    sweepall();
	    error(E_USER,(pointer)"not enough stack space");}} }
      b=nextbuddy(b);} }
  sweepall();
#if THREADED
  mutex_unlock(&mark_lock);
#endif
  while (ctx->vsp > spsave) r=cons(ctx,vpop(),r);
  return(r);}

pointer LISTALLREFERENCES(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer target=argv[0],p,r=NIL;
  struct chunk *chp;
  pointer *spsave=ctx->vsp;
  register int s,bsize,size;
  bpointer b,tail;

  ckarg(1);
#if THREADED
  mutex_lock(&mark_lock);
  mark_locking="LISTALLREF";
#endif
  markall();
  for (chp=chunklist; chp!=0; chp=chp->nextchunk) {
    bsize=buddysize[chp->chunkbix];
    b= &chp->rootcell;
    tail=(bpointer)((eusinteger_t)b+(bsize<<WORDSHIFT));/* ???? */
    while (b<tail) {
      if (marked(b)) {
	  p=makepointer(b);
	  switch(elmtypeof(p)) {
	    case ELM_POINTER:
			size=vecsize(p);
			for (s=0; s<size; s++)
			  if (p->c.vec.v[s]==target) goto found;
			break;
	    case ELM_FIXED:
			size=objsize(p);
			for (s=0; s<size; s++)
			  if (p->c.obj.iv[s]==target) goto found;
			break;
	    default: break;}
	  goto next_buddy;
  found:
	  vpush(p);
          if (ctx->vsp>=ctx->stacklimit) {
	    sweepall();
	    error(E_USER,(pointer)"not enough stack space");}	  }
  next_buddy:
      b=nextbuddy(b);} }
  sweepall();
#if THREADED
  mutex_unlock(&mark_lock);
#endif
  while (ctx->vsp>spsave) r=cons(ctx,vpop(),r);  
  return(r);}


/****************************************************************/
/* direct access to memory */
/****************************************************************/

pointer ADDRESS(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ eusinteger_t p;/* ???? */
  ckarg(1);
  p=(eusinteger_t)bpointerof(argv[0]);/* ???? */
  return(mkbigint(p));}

pointer PEEK(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ union un {
    byte b;
    short s;
    int i;
    long l;
    float f;
    double d;
    void *p;} *u;
  long x,etype;
  unsigned long y;
  pointer p,size;
  numunion nu;

  ckarg2(1,3);
  p=argv[0];
  if (isvector(p)) {
    etype=elmtypeof(p);
    if (etype==ELM_CHAR || etype==ELM_BYTE) {
      u= (union un *)&p->c.str.chars[ckintval(argv[1])];
      if (n==3) size=argv[2]; else size=K_LONG;}
    else if (etype==ELM_FOREIGN) {
      u= (union un *)&((byte *)(p->c.ivec.iv[0]))[ckintval(argv[1])];
      if (n==3) size=argv[2]; else size=K_LONG;}
    else error(E_NOSTRING);}
  else{
    x=bigintval(argv[0]);
    u=(union un *)x;
    if (n==2) size=argv[1]; else size=K_LONG;}
#if (WORD_SIZE == 64)
  if (size==K_LONG) return mkbigint(u->l);
  if (size==K_INTEGER) return makeint(u->i);
#else
  if (size==K_LONG || size==K_INTEGER) {
    y=u->l;
    return(mkbigint(y));}
#endif
  if (size==K_BYTE || size==K_CHAR) return(makeint(u->b));
  if (size==K_SHORT) return(makeint(u->s));
  if (size==K_FLOAT) return(makeflt(u->f));
  if (size==K_DOUBLE) return(makeflt(u->d));
  if (size==K_POINTER) return(mkbigint((eusinteger_t)(u->p))); /* ???? */
  else error(E_USER,(pointer)"unknown access mode");}

pointer POKE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ union un {
    byte b;
    short s;
    int i;
    long l;
    float f;
    double d;
    void *p;} *u;
  eusinteger_t x;
  int etype;
  pointer p,size,val;
  numunion nu;
  
  ckarg2(2,4);
  val=argv[0];
  p=argv[1];
  if (isvector(p)) {
    etype=elmtypeof(p);
    if (etype==ELM_CHAR || etype==ELM_BYTE) {
      u= (union un *)&p->c.str.chars[ckintval(argv[2])];
      if (n==4) size=argv[3]; else size=K_LONG;}
    else if (etype==ELM_FOREIGN) {
      u= (union un *)&((byte *)(p->c.ivec.iv[0]))[ckintval(argv[2])];
      if (n==4) size=argv[3]; else size=K_LONG;}
    else error(E_NOSTRING);}
  else{
    x=bigintval(argv[1]);
    u=(union un *)x;
    if (n==3) size=argv[2]; else size=K_LONG;}
#if (WORD_SIZE == 64)
  if (size==K_LONG) u->l=bigintval(val);
  else if (size==K_INTEGER) u->i=ckintval(val);
#else
  if (size==K_LONG || size==K_INTEGER)  u->l=bigintval(val);
#endif
  else if (size==K_BYTE || size==K_CHAR) u->b=ckintval(val);
  else if (size==K_SHORT) u->s=ckintval(val);
  else if (size==K_FLOAT) u->f=ckfltval(val);
  else if (size==K_DOUBLE) u->d=ckfltval(val);
  else if (size==K_POINTER) u->p=(void*)ckintval(val);
  else error(E_USER,(pointer)"unknown access mode");
  return(val);}

/****************************************************************/
/* stack frame access
/* 1988-Apr-26
/****************************************************************/
pointer LISTALLCATCHERS(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer catchers=NIL;
  struct catchframe *cfp=ctx->catchfp;
  int i=0;
  while (cfp) {
    vpush(cfp->label);
    i++;
    cfp=cfp->nextcatch;}
  return(stacknlist(ctx,i));}

pointer LISTBINDINGS(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ struct bindframe *bfp=ctx->bindfp, *nextbfp;
  int i=0;
  while (bfp) {
    vpush(cons(ctx,bfp->sym,bfp->val));
    i++;
    nextbfp=bfp->dynblink;
    if (nextbfp==NULL) nextbfp=bfp->lexblink;
    bfp=nextbfp;}
  return(stacknlist(ctx,i));}

pointer LISTSPECIALBINDINGS(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ struct specialbindframe *sbfp=ctx->sbindfp;
  int i=0;
  while (sbfp) {
    vpush(cons(ctx,sbfp->sym,sbfp->oldval));
    i++;
    sbfp=sbfp->sblink;}
  return(stacknlist(ctx,i));}
    	
pointer LISTALLCLASSES(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ for (n=nextcix; n>0; ) ckpush(classtab[--n].def);
  return(stacknlist(ctx,nextcix));}

pointer EXPORTALL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(1);
  export_all = (argv[0]!=NIL);
  return(export_all?T:NIL);}

pointer NEXT_SPECIAL_INDEX(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ int x;
  x=special_index();	/*generate a new special value index*/
  return(makeint(x));}

pointer THREAD_SPECIALS(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ int x;
  context *con;
  pointer p;

  if (n==0) con=ctx;
  else {
    x=ckintval(argv[0]);
    if (x<0 || x>MAXTHREAD) error(E_USER,(pointer)"no such thread");
    if (x==0) con=ctx;
    else con=euscontexts[x];}
  p=con->specials;  
  if (p==NULL) return(NIL);
  if (n>1) {
    x=ckintval(argv[1]);
    return(p->c.vec.v[x]); }
  else return(p);}


void sysfunc(ctx,mod)
register context *ctx;
pointer mod;
{ pointer pkgname,pkgnick,p=Spevalof(PACKAGE);

  pointer_update(Spevalof(PACKAGE),syspkg);

  defun(ctx,"SBCOUNT",mod,SBCOUNT,NULL);
  defun(ctx,"GC",mod,GEESEE,NULL);
  defun(ctx,"GCTIME",mod,GCTIME,NULL);
  defun(ctx,"ALLOC",mod,ALLOC,NULL);
  defun(ctx,"NEWSTACK",mod,NEWSTACK,NULL);
  defun(ctx,"RECLAIM",mod,RECLAIM,NULL);
  defun(ctx,"RECLAIM-TREE",mod,RECLTREE,NULL);
  defun(ctx,"OBJECT-SIZE",mod,OBJSIZE,NULL);
  defun(ctx,"BKTRACE",mod,BKTRACE,NULL);
  defun(ctx,"MEMORY-REPORT",mod,MEMORY_REPORT,NULL);
  defun(ctx,"CLEAR-MEMORY-REPORT",mod,CLEAR_ALLOCCOUNT,NULL);
  defun(ctx,"ROOM",mod,ROOM,NULL);
  defun(ctx,"FREE-COUNT",mod,FREE_COUNTS,NULL);
  defun(ctx,"LIST-ALL-CHUNKS",mod,LIST_ALL_CHUNKS,NULL);
  defun(ctx,"LIST-ALL-INSTANCES",mod,INSTANCELIST,NULL);
  defun(ctx,"ADDRESS",mod,ADDRESS,NULL);
  defun(ctx,"PEEK",mod,PEEK,NULL);
  defun(ctx,"POKE",mod,POKE,NULL);
/*  defun(ctx,"MALLOC_DEBUG",mod,MALLOC_DEBUG,NULL);
/*  defun(ctx,"MALLOC_VERIFY",mod,MALLOC_VERIFY,NULL); */
  defun(ctx,"LIST-ALL-REFERENCES",mod,LISTALLREFERENCES,NULL);
  defun(ctx,"LIST-ALL-CATCHERS",mod,LISTALLCATCHERS,NULL);
  defun(ctx,"LIST-ALL-BINDINGS",mod,LISTBINDINGS,NULL);
  defun(ctx,"LIST-ALL-SPECIAL-BINDINGS",mod,LISTSPECIALBINDINGS,NULL);
  defun(ctx,"LIST-ALL-CLASSES",mod,LISTALLCLASSES,NULL);
  defun(ctx,"EXPORT-ALL-SYMBOLS", mod, EXPORTALL,NULL);
  defun(ctx,"NEXT-SPECIAL-INDEX", mod, NEXT_SPECIAL_INDEX,NULL);
  defun(ctx,"THREAD-SPECIALS", mod, THREAD_SPECIALS,NULL);
  defun(ctx,"DISPOSE-HOOK", mod, DISPOSE_HOOK,NULL);

/* restore package*/  pointer_update(Spevalof(PACKAGE),p);
}
