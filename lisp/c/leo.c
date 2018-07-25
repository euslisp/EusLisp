/****************************************************************/
/* LEO.C
/*	Object Oriented Programming Facilities
/*	Every data structures in EUS is defined as an object.
/*	Refer to eus.h and makes.c for the detail of the structures
/*	of objects.
/*
/*	Copyright: Toshihiro Matsui, Electrotechnical Laboratory
/*	Original: 1986-May
/*	*/
static char *rcsid="@(#)$Id$";

#include "eus.h"

extern pointer K_METHOD_DOCUMENTATION;

#if THREADED
/* static mutex_t mcache_lock; */ /* This variable is not used. */
#endif

int mchit=0, mcmiss=0, trycache=1;	/*statistic for method cacheing*/

pointer GETCLASS(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer v;
  ckarg(1);
  if (isnum(argv[0])) return(NIL);
  return(classof(argv[0]));}

pointer CLASSP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ 
  if (n!=1) error(E_MISMATCHARG);
  return(isclass(argv[0])?T:NIL);}

pointer SUBCLASSP(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register int k,s;
  ckarg(2);
  if (!isclass(argv[0])) error(E_NOCLASS,argv[0]);
  if (!isclass(argv[1])) error(E_NOCLASS,argv[1]);
  k=intval(argv[0]->c.cls.cix);
  s=intval(argv[1]->c.cls.cix);
  if  (k>=s && k<=classtab[s].subcix) return(T); else return(NIL); }

pointer DERIVEDP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer obj,klass;
  register int objcix,klasscix;
  ckarg(2);
  obj=argv[0]; klass=argv[1];
  if (isnum(obj)) {
    if ((klass==QFLOAT || klass==K_FLOAT)&& isflt(obj)) return(T);
    else if ((klass==QINTEGER || klass==K_INTEGER) && isint(obj)) return(T);
    else return(NIL);}
  if (!isclass(klass)) error(E_NOCLASS,klass);
  objcix=obj->cix;
  klasscix=intval(klass->c.cls.cix);
  if (objcix>=klasscix && objcix<=classtab[klasscix].subcix) return(T);
  else return(NIL);}


/****************************************************************/
/* define new class
/****************************************************************/

pointer ENTERCLASS(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  if (!isclass(argv[0])) error(E_NOCLASS,argv[0]);
  enterclass(argv[0]);
  return(argv[0]);}

/****************************************************************/
/* add new method definition to a class
/****************************************************************/
	
extern pointer K_CLASS;

void addmethod(ctx,meth,class,doc)
register context *ctx;
register pointer meth,class,doc;
{ extern pointer putprop(), assq();
  register pointer selector,methods,classes,medoc,medoc2;
  register int i,j;
  vpush(meth);
  selector=ccar(meth); methods=class->c.cls.methods;
  if (!issymbol(selector)) error(E_NOSYMBOL);
  classes=assq(K_CLASS,selector->c.sym.plist);
  if (classes!=NIL) classes=ccdr(classes);
  putprop(ctx,selector,cons(ctx,class,classes),K_CLASS);
/* */
  if (doc!=NIL) {
    medoc=assq(K_METHOD_DOCUMENTATION, selector->c.sym.plist);
/*    prinx(medoc,STDOUT); */
    if (medoc==NIL) putprop(ctx,selector,cons(ctx,cons(ctx,class,doc),NIL),
				     K_METHOD_DOCUMENTATION);
    else {
      medoc2=assq(class,ccdr(medoc));
      if (medoc2==NIL)
      {pointer_update(medoc->c.cons.cdr,cons(ctx,cons(ctx,class,doc),ccdr(medoc)));}
      else pointer_update(medoc2->c.cons.cdr,doc); } }
/* */
  if (methods==NIL) {pointer_update(class->c.cls.methods,cons(ctx,meth,NIL));}
  else if (ccar(ccar(methods))==selector) {pointer_update(ccar(methods),meth);}
  else {
    while(ccdr(methods)!=NIL) {
      methods=ccdr(methods);
      if (ccar(ccar(methods))==selector) {
	ccar(methods)=meth;
	goto purgecache; } }
    pointer_update(ccdr(methods),cons(ctx,meth,NIL)); }
  /*nullify method cache for this selctor*/
purgecache:
  vpop();
  for (j=0; j<MAXTHREAD; j++) {
    if ((ctx=euscontexts[j]))
      for (i=0; i<MAXMETHCACHE; i++) 
        if (ctx->methcache[i].selector==selector)
          pointer_update(ctx->methcache[i].selector,NIL); }
  }
  
void addcmethod(ctx,mod,cfunc,sel,class,doc)
register context *ctx;
pointer sel,mod,class,doc;
pointer (*cfunc)();
{ if (!issymbol(class)) error(E_NOCLASS,class);
  class=speval(class);
  if (class==UNBOUND || !isclass(class)) error(E_NOCLASS,class);
  addmethod(ctx,cons(ctx,sel,
			cons(ctx,makecode(mod,cfunc,SUBR_FUNCTION),NIL)),
		class,doc);}

pointer DEFMETHOD(ctx,arg)	/*special form*/
register context *ctx;
pointer arg;
{ register pointer class,selector,classsym,body,doc;
  classsym=carof(arg,E_MISMATCHARG); arg=ccdr(arg);
  if (!issymbol(classsym)) error(E_NOSYMBOL);
  class=speval(classsym);
  if (class==UNBOUND) error(E_UNBOUND,classsym);
  if (!isclass(class)) error(E_NOCLASS,class);
  while (islist(arg)) {
    body=ccar(arg);	/* (:selector (args) . body) */
    if (!iscons(body)) error(E_NOLIST);
    doc=ccdr(ccdr(body));
    if (isstring(ccar(doc))) doc=ccar(doc); else doc=NIL;
    addmethod(ctx,body,class,doc); arg=ccdr(arg);}
  return(classsym);}

pointer INSTANTIATE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a;
  int s;
  extern pointer makeobject();
  a=argv[0];
  if (isvecclass(a)) {
    s=intval(a->c.vcls.size);
    if (s<0) { ckarg(2); s=ckintval(argv[1]);}
    else ckarg(1);
#ifdef SAFETY
    {
      pointer tmp = makevector(a,s);
      take_care(tmp);
      return(tmp);
    }
#else
    return(makevector(a,s));
#endif
  }
  else if (isclass(a)) {
    ckarg(1);
#ifdef SAFETY
    {
      pointer tmp = makeobject(a);
      take_care(tmp);
      return(tmp);
    }
#else
    return(makeobject(a));
#endif
  }
  else error(E_NOCLASS,a);}


/****************************************************************/
/* send a message to an object
/*	method is searched by method-cache
/*****************************************************************/

pointer findmethod(ctx,sel,search, curclass)
register context *ctx;
register pointer sel,search, *curclass;
{ register pointer meths,klass=search;
  register struct methdef *mt;
  register int h;

  if (trycache) {
    h=(((eusinteger_t)sel+(eusinteger_t)klass)>>3) & (MAXMETHCACHE-1);/* ???? */
    mt= &ctx->methcache[h];
    if (mt->selector==sel && mt->class==search) {
      /* hit! */
      mchit++;
      *curclass = mt->ownerclass;
      return(mt->method);}}
  while (isclass(klass) || isvecclass(klass)) {
    mcmiss++;
    meths=klass->c.cls.methods;
    while (islist(meths))	/*find the method in this class*/
      if (ccar(ccar(meths))==sel) {
	if (trycache) {
	    pointer_update(mt->selector,sel);
	    pointer_update(mt->class,search);
	    pointer_update(mt->ownerclass,klass);
	    pointer_update(mt->method,ccar(meths));
	  }
        *curclass = klass; return(ccar(meths));}
      else meths=ccdr(meths);
    klass= /*spevalof*/ (klass->c.cls.super);} /*try superclass*/
  return(NIL);}

pointer findforward(ctx,selector,klass,obj,component,classfound)
context *ctx;
register pointer selector,klass,obj, *component, *classfound;
{ register pointer forwards=klass->c.cls.forwards,flist,meth;
  register int i=0,vcount=vecsize(forwards);
  while (i<vcount) {
    flist=forwards->c.vec.v[i];
    if (flist==T || memq(selector,flist)!=NIL) {
      *component = obj->c.obj.iv[i];
      if (!isnum(*component)) {
	meth=findmethod(ctx,selector,classof(*component),classfound);
	if (meth!=NIL) return(meth);}
      else error(E_NOOBJECT);}
    i++;}
  return(NIL);}

pointer SEND(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer receiver,klass,selector,meth,result;
  register pointer *spsave=ctx->vsp, *altargv;
  pointer curclass, component;
  struct bindframe *bf,*bfsave=ctx->bindfp;
  struct specialbindframe *sbfpsave=ctx->sbindfp;
  int sbcount=ctx->special_bind_count;
  int i,argoffset;
#if defined(DEBUG_COUNT) || defined(SEND_DEBUG)
  static int count = 0;

  count++;
#endif

#ifdef SEND_DEBUG
  printf( "SEND:%d\n", count );
#endif

  if (n<2) error(E_MISMATCHARG);
  receiver=argv[0];
  selector=argv[1];
  if (isnum(receiver)) error(E_NOOBJECT);
  klass=classof(receiver);
  meth=findmethod(ctx,selector,klass, &curclass);
  if (meth==NIL) {
    /*try forwarding*/
    meth=findforward(ctx,selector,klass,receiver, &component, &curclass);
    if (meth!=NIL) { argv[0]=component; receiver=component; argoffset=2;}
    else {
      meth=findmethod(ctx,K_NOMETHOD,klass, &curclass);
      if (meth==NIL) error(E_NOMETHOD,selector);
      if (iscode(ccar(ccdr(meth)))) {
        altargv=ctx->vsp;
        vpush(receiver);  vpush(selector);
        i=1;
        while (i<n) ckpush(argv[i++]);
        argv=altargv;
        n++;}
      else argoffset=1;} }
  else argoffset=2;

  if (iscode(ccar(ccdr(meth)))) {
    argv[1]=curclass;
    result=funcode(ctx,ccar(ccdr(meth)),(pointer)argv,n);
    }
  else {
    bf=fastbind(ctx,classof(receiver)->c.cls.vars,receiver,NULL);
#if SunOS4_1
    bf=fastbind(ctx,QSELF,receiver,bf); /* SunOS 4.1 already use SELF */ 
#else
    bf=fastbind(ctx,SELF,receiver,bf);
#endif
    bf=fastbind(ctx,CLASS,curclass,bf);
    result=funlambda(ctx,ccar(meth),ccar(ccdr(meth)),ccdr(ccdr(meth)),
		     &argv[argoffset],bf,n-argoffset);
    ctx->bindfp=bfsave;
    /* while (sbfpsave<ctx->sbindfp) unbindx(ctx,1); */
    unbindspecial(ctx,sbfpsave+1);
    } 
  ctx->vsp=spsave;
  return(result);}

pointer SEND_IF_FOUND(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer receiver,klass,selector,meth,result;
  register pointer *spsave=ctx->vsp,*altargv;
  pointer curclass, component;
  struct bindframe *bf,*bfsave=ctx->bindfp;
  struct specialbindframe *sbfpsave=ctx->sbindfp;
  int argoffset;

  if (n<3) error(E_MISMATCHARG);
  receiver=argv[1];
  selector=argv[2];
  if (isnum(receiver)) return(argv[0]);
  klass=classof(receiver);
  meth=findmethod(ctx,selector,klass, &curclass);
  if (meth==NIL) {
    /*try forwarding*/
    meth=findforward(ctx,selector,klass,receiver, &component, NULL);
    if (meth!=NIL) { argv[1]=component; receiver=component; argoffset=3;}
    else return(argv[0]); }
  else argoffset=3;

  if (iscode(ccar(ccdr(meth)))) {
    argv[2]=curclass;
    result=funcode(ctx,ccar(ccdr(meth)), (pointer)&argv[1],n-1);
    }
  else {
    bf=fastbind(ctx,classof(receiver)->c.cls.vars,receiver,NULL);
#if SunOS4_1
    bf=fastbind(ctx,QSELF,receiver,bf); /* SunOS 4.1 already use SELF */
#else
    bf=fastbind(ctx,SELF,receiver,bf);
#endif
    bf=fastbind(ctx,CLASS,curclass,bf);
    result=funlambda(ctx,ccar(meth),ccar(ccdr(meth)),ccdr(ccdr(meth)),
		     &argv[argoffset],bf,n-argoffset);
    ctx->bindfp=bfsave;
    /* while (sbfpsave<ctx->sbindfp) unbindx(ctx,1); */
    unbindspecial(ctx,sbfpsave+1);
    }
  ctx->vsp=spsave;
#ifdef SAFETY
  take_care(result);
#endif
  return(result);}

pointer SENDMESSAGE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
/* (send-message obj search selector [args]) */
{ pointer receiver,search,selector,meth,form,result,*spsave, curclass;
  struct bindframe *bf,*bfsave=ctx->bindfp;
  struct specialbindframe *sbfpsave=ctx->sbindfp;

  if (n<3) error(E_MISMATCHARG);
  receiver=argv[0]; search=argv[1]; selector=argv[2];
  if (issymbol(search)) search=speval(search);
  if (search==UNBOUND || (!isclass(search) && !isvecclass(search)))
    error(E_NOCLASS,search);

  meth=findmethod(ctx,selector,search, &curclass);
  if (meth==NIL) error(E_NOMETHOD);
  form=ctx->callfp->form;
  if (iscode(ccar(ccdr(meth)))) {
    argv[1]=receiver; argv[2]=curclass;
    result=ufuncall(ctx,form,ccar(ccdr(meth)),(pointer)&argv[1],NULL,n-1);}
  else {
    spsave=ctx->vsp;
    bf=fastbind(ctx,classof(receiver)->c.cls.vars,receiver,NULL);
#if SunOS4_1
    bf=fastbind(ctx,QSELF,receiver,bf); /* SunOS 4.1 already use SELF */
#else
    bf=fastbind(ctx,SELF,receiver,bf);
#endif
    bf=fastbind(ctx,CLASS,curclass,bf);
    result=ufuncall(ctx,form,meth,(pointer)&argv[3],bf,n-3);
    ctx->bindfp=bfsave;
    /* while (sbfpsave<ctx->sbindfp) unbindx(ctx,1); */
    unbindspecial(ctx,sbfpsave+1);
    ctx->vsp=spsave;}
#ifdef SAFETY
  take_care(result);
#endif
  return(result);}

pointer CLONE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a=argv[0],klass,x;
  register int i,s;
  int etype;
  ckarg(1);
  if (ispointer(a)) {
    klass=classof(a);
    if (isvecclass(klass)) {
      etype=intval(klass->c.vcls.elmtype);
      s=vecsize(a);
      switch(etype) {
	case ELM_BIT: n=(s+WORD_SIZE-1)/WORD_SIZE; break;
	case ELM_CHAR: case ELM_BYTE: n=(s+sizeof(eusinteger_t))/sizeof(eusinteger_t); break;
	default: n=s; break;}
      n++;
      x=makevector(klass,s);
      }
    else {
      n=vecsize(klass->c.cls.vars);
      x=makeobject(klass);}
    for (i=0; i<n; i++) x->c.obj.iv[i]=a->c.obj.iv[i];
#ifdef SAFETY
    take_care(x);
#endif
    return(x);}
  else error(E_INSTANTIATE);}

pointer METHCACHE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ /* return method cache hit ratio*/
  register int i;
  if (n==1) {
    trycache=(argv[0]!=NIL);
    for (i=0; i<MAXMETHCACHE; i++) {
       pointer_update(ctx->methcache[i].class,NIL);
       pointer_update(ctx->methcache[i].selector,NIL);
    }
  }
#ifdef SAFETY
  {
    pointer tmp = cons(ctx,makeint(mchit),cons(ctx,makeint(mcmiss),NIL));
    take_care(tmp);
    return(tmp);
  }
#else
  return(cons(ctx,makeint(mchit),cons(ctx,makeint(mcmiss),NIL)));
#endif
}

pointer FINDMETHOD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a;
  pointer curclass;
  ckarg(2);
  a=argv[0];
  if (isnum(a)) error(E_NOOBJECT);
  a=findmethod(ctx,argv[1],classof(a), &curclass);
  if (a!=NIL)  a=cons(ctx,curclass,cons(ctx,a,NIL));
#ifdef SAFETY
  take_care(a);
#endif
  return(a);}

int getslotindex(obj,klass,varid)
register pointer obj,klass,varid;
{ 
  register int objcix,klasscix,index;
  register pointer vvec;
  extern pointer equal();

  if (!isclass(klass)) error(E_NOCLASS,klass);
  objcix=obj->cix;
  klasscix=intval(klass->c.cls.cix);
  if (objcix>=klasscix && objcix<=classtab[klasscix].subcix) {
    vvec=klass->c.cls.vars;
    if (isint(varid)) index=intval(varid);
    else if (issymbol(varid)) {
      index=0;
      while (index<vecsize(vvec))
	if (vvec->c.vec.v[index]==varid) break;  else index++;}
    else if (isstring(varid)) {
      index=0;
      while (index<vecsize(vvec))
	if (equal(vvec->c.vec.v[index]->c.sym.pname, varid)==T) break;
	else index++;}
    else error(E_NOINT);
    if (index>=vecsize(vvec)) error(E_NOOBJVAR,varid);
    return(index);}
  else error(E_NOOBJVAR,varid);}

pointer SLOT(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a;
  ckarg(3);	/* (slot obj class index) */
  n=getslotindex(argv[0],argv[1],argv[2]);
  a=argv[0]->c.obj.iv[n];
  if (a==UNBOUND) return(QUNBOUND);
  else return(a);}

pointer SETSLOT(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ ckarg(4);	/* (setslot obj class index newval) */
  n=getslotindex(argv[0],argv[1],argv[2]);
  pointer_update(argv[0]->c.obj.iv[n],argv[3]);
  return(argv[3]);}

/* test methods*/
pointer CONSCAR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer self=argv[0];
  if (n>=3) pointer_update(self->c.cons.car,argv[2]);
  return(self->c.cons.car);}

pointer CONSCDR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer self=argv[0];
  if (n>=3) pointer_update(self->c.cons.cdr,argv[2]);
  return(self->c.cons.cdr);}

/****************************************************************/
/* copy complex objects preserving reference topology
/****************************************************************/

#define p_marked(p) (bpointerof(p)->h.pmark)
#define p_mark_on(p) (bpointerof(p)->h.pmark=1)
#define p_mark_off(p) (bpointerof(p)->h.pmark=0)

static pointer *cpvec;
static int cpx;
static jmp_buf cpyjmp;

pointer copyobj(ctx,org)
register context *ctx;
register pointer org;
{ register pointer clone;
  pointer klass,x;
  register int i,s;
  int etype;

  if (isnum(org) || issymbol(org) || isclass(org)) return(org);
  /* eus_rbar *//* if ((org==0) || isnum(org) || issymbol(org) || isclass(org)) return(org); */
  x=org->c.obj.iv[1];
  if (p_marked(org)) return(cpvec[intval(x)]);
  p_mark_on(org);
  klass=classof(org);
  if (isvecclass(klass)) {
    etype=elmtypeof(org);
    s=vecsize(org);
    clone=makevector(klass,s);
    elmtypeof(clone)=etype;
    switch(etype) {
      case ELM_BIT: s=(s+WORD_SIZE-1)/WORD_SIZE; break;
      case ELM_BYTE: case ELM_CHAR: s=(s+sizeof(eusinteger_t))/sizeof(eusinteger_t); break;
	case ELM_FOREIGN: s=1; break; }}
  else {
    etype=ELM_FIXED;
    s=objsize(org);
    clone=(pointer)makeobject(klass);}

  if (ctx->vsp>ctx->stacklimit)
    { p_mark_off(org);
      fprintf(stderr,"cannot copy\n"); euslongjmp(cpyjmp,ERR);}
#ifdef RGC /* R.Hanai */
  if (etype == ELM_FIXED || etype == ELM_POINTER) {
    pointer_update(org->c.obj.iv[1],makeint(cpx));
  } else {
    org->c.obj.iv[1] = makeint(cpx);
  }
#else
  pointer_update(org->c.obj.iv[1],makeint(cpx));
#endif
  vpush(clone);
  vpush(x);
  cpx += 2;
  switch (etype) {
    case ELM_FIXED:
	    clone->c.obj.iv[1]=copyobj(ctx,x);
	    if (s>0) clone->c.obj.iv[0]=copyobj(ctx,org->c.obj.iv[0]);
	    for (i=2; i<s; i++) clone->c.obj.iv[i]=copyobj(ctx,org->c.obj.iv[i]);
	    break;
    case ELM_POINTER:
	    clone->c.vec.v[0]=copyobj(ctx,x);
	    for (i=1; i<s; i++) clone->c.vec.v[i]=copyobj(ctx,org->c.vec.v[i]);
	    break;
    default:
	    clone->c.vec.v[0]=x; /*copyobj(ctx,x) fails */
	    for (i=1; i<s; i++) clone->c.ivec.iv[i]=org->c.ivec.iv[i];
	    break;}
#ifdef SAFETY
  take_care(clone);
#endif
  return(clone);}

void copyunmark(obj)
register pointer obj;
{ pointer x,klass;
  register int i,s;

  if (isnum(obj) || pissymbol(obj) || pisclass(obj)) return;
  x=obj->c.obj.iv[1];
  if (p_marked(obj)) {
    pointer_update(obj->c.obj.iv[1],cpvec[intval(x)+1]);
    p_mark_off(obj);
    if (pisvector(obj)) {
      if (elmtypeof(obj)<ELM_POINTER) return;
      s=vecsize(obj);
      for (i=0; i<s; i++) copyunmark(obj->c.vec.v[i]); }
    else { /* struct object */
      s=objsize(obj);
      for (i=0; i<s; i++) copyunmark(obj->c.obj.iv[i]); }
    }
  }

pointer COPYOBJ(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a=argv[0],b;
  pointer *spsave=ctx->vsp;
  ckarg(1);
#if THREADED
  mutex_lock(&mark_lock);
#endif
  cpx=0;
  cpvec= ctx->vsp;
  if ((b=(pointer)eussetjmp(cpyjmp))==0) b=copyobj(ctx,a); 
  copyunmark(a);
  ctx->vsp=spsave;
#if THREADED
  mutex_unlock(&mark_lock);
#endif
  ctx->vsp=spsave;
  if (b==(pointer)ERR) error(E_USER,(pointer)"too big to copy");
  else return(b);
  }

pointer BECOME(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int e1,e2, newsize;
  ckarg(2);
  if (isnum(argv[0])) error(E_NOOBJECT);
  if (isvecclass(argv[1])) {
    e1=elmtypeof(argv[0]); e2=intval(argv[1]->c.vcls.elmtype);
    if (e1==ELM_FIXED) error(E_USER,(pointer)"a record type object cannot become a vector");
    if (e1==ELM_POINTER && e1!=e2) error(E_USER,(pointer)"element type mismatch");
    /*chage length field*/
    n=vecsize(argv[0]);
    switch(e1) {
    case ELM_BIT: switch(e2) {
		    case ELM_CHAR: case ELM_BYTE: n=(n+7)/8; break;
		    case ELM_BIT: break;
		    default: n=(n+WORD_SIZE-1)/WORD_SIZE; break;} break;
    case ELM_CHAR: case ELM_BYTE:
		  switch(e2) {
		    case ELM_CHAR: case ELM_BYTE: break;
		    case ELM_BIT: n*=8; break;
		    default: n=(n+sizeof(eusinteger_t)-1)/sizeof(eusinteger_t); break;} break;
    default:	  switch(e2) {
		    case ELM_CHAR: case ELM_BYTE: n*=sizeof(pointer); break;
		    case ELM_BIT: n*=WORD_SIZE; break;
		    default: break;} break; }
    argv[0]->c.vec.size=makeint(n);
    /*change class index*/
    argv[0]->cix=intval(argv[1]->c.vcls.cix);
    elmtypeof(argv[0])=e2;
    return(argv[0]);}
  else if (isint(argv[1])) {
    newsize=ckintval(argv[1]);
    /* get word count to accomodate the newsize of object*/ 
    switch(elmtypeof(argv[0])) {
      case ELM_BIT: n=(newsize+WORD_SIZE-1)/WORD_SIZE; break;
      case ELM_BYTE: case ELM_CHAR:
		n=(newsize+(WORD_SIZE/8)-1)/(WORD_SIZE/8); break; 
      default: n=newsize; }
    if (buddysize[bixof(argv[0])]>=n+2)  argv[0]->c.vec.size=makeint(newsize);
    else error(E_ARRAYINDEX);
    return(argv[0]);
    }
  else error(E_USER,(pointer)"vector class or number expected");
  }

pointer REPLACEOBJECT(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ register pointer dest=argv[0],src=argv[1];
  int nsrc,ndest;
  ckarg(2);
  if (isnum(src) || isnum(dest)) return(src);
  nsrc=objsize(src); ndest=objsize(dest);
  n=min(nsrc,ndest);
  while (n-->0) pointer_update(dest->c.obj.iv[n],src->c.obj.iv[n]);
  return(dest);}

void leo(ctx,mod)
register context *ctx;
pointer mod;
{
  defun(ctx,"CLASS",mod,GETCLASS,NULL);
  defun(ctx,"ENTER-CLASS",mod,ENTERCLASS,NULL);
/*  defspecial("DEFCLASS",mod,DEFCLASS); */
  defspecial(ctx,"DEFMETHOD",mod,DEFMETHOD);
  defun(ctx,"SEND",mod,SEND,NULL);
  defun(ctx,"SEND-MSG",mod,SEND,NULL);
  defun(ctx,"SEND-IF-FOUND",mod,SEND_IF_FOUND,NULL);
  defun(ctx,"SEND-MESSAGE",mod,SENDMESSAGE,NULL);
  defun(ctx,"INSTANTIATE",mod,INSTANTIATE,NULL);
  defun(ctx,"CLASSP",mod,CLASSP,NULL);
  defun(ctx,"SUBCLASSP",mod,SUBCLASSP,NULL);
  defun(ctx,"DERIVEDP",mod,DERIVEDP,NULL);
  defun(ctx,"CLONE",mod,CLONE,NULL);
  defun(ctx,"SLOT",mod,SLOT,NULL);
  defun(ctx,"SETSLOT",mod,SETSLOT,NULL);
  defun(ctx,"FIND-METHOD",mod,FINDMETHOD,NULL);
  defunpkg(ctx,"METHOD-CACHE",mod,METHCACHE,syspkg);
  addcmethod(ctx,mod,CONSCAR,defkeyword(ctx,"CAR"),QCONS,NIL);
  addcmethod(ctx,mod,CONSCDR,defkeyword(ctx,"CDR"),QCONS,NIL);
  defun(ctx,"COPY-OBJECT",mod,COPYOBJ,NULL);
  defun(ctx,"BECOME",mod,BECOME,NULL);
  defun(ctx,"REPLACE-OBJECT",mod,REPLACEOBJECT,NULL);
  }

