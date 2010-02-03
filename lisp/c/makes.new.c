/****************************************************************/
/* make eulisp objects 
/*	Copyright Toshihiro MATSUI, ETL, 1987
/****************************************************************/
static char *rcsid="@(#)$Id$";

#if Solaris2
#include <errno.h>
#include <synch.h>
#include <thread.h>
#endif

#include "eus.h"

#if 0 /* move to eus.h */
#define nextbuddy(p) ((bpointer)((eusinteger_t)p+(buddysize[p->h.bix]*sizeof(pointer))))
#endif

extern pointer LAMCLOSURE, K_FUNCTION_DOCUMENTATION;

/****************************************************************/
/* boxing and unboxing
/****************************************************************/
#if vax
float ckfltval(p)
register int p;
{ numunion nu;
  if (isflt(p)) {
    nu.ival = p & 0xfffffffc;
#if vax
    { register short s;
      s=nu.sval.low; nu.sval.low=nu.sval.high; nu.sval.high=s;}
#endif
    return(nu.fval);}
  else if (isint(p)) { nu.fval=intval(p); return(nu.fval);} /*coerce to float*/
  else error(E_NONUMBER);}

float fltval(p)
int p;
{ numunion nu;
  nu.ival= p & 0xfffffffc;
#if vax
  { register short s;
    s=nu.sval.low; nu.sval.low=nu.sval.high; nu.sval.high=s;}
#endif
  return(nu.fval);}

pointer makeflt(d)
double d;
{ numunion u;
  u.fval=d;	/*double to short float*/
#if vax
  { register short s;
    s=u.sval.low;		/*swap upper and lower short*/
    u.sval.low=u.sval.high;
    u.sval.high=s;}
#endif
  return((pointer)((u.ival & 0xfffffffc) | 1));}
#endif
  
pointer Getstring(s)
register pointer s;
{ if (issymbol(s)) s=s->c.sym.pname;
  if (!isstring(s)) error(E_NOSTRING);
  return(s);}

byte *get_string(s)
register pointer s;
{ if (isstring(s)) return(s->c.str.chars);
  if (issymbol(s)) return(s->c.sym.pname->c.str.chars);
  else error(E_NOSTRING);}

/****************************************************************/
/* cons & list
/****************************************************************/

#define allocobj(class,builtin,cid)  \
 ((class)? \
    alloc(vecsize(speval(class)->c.cls.vars), ELM_FIXED, \
	  intval(speval(class)->c.cls.cix), \
	  wordsizeof(struct builtin)): \
    alloc(wordsizeof(struct builtin), ELM_FIXED, cid, \
	  wordsizeof(struct builtin)))

pointer rawcons(ctx,a,d)
register context *ctx;
register pointer a,d;
{ register pointer c;
  vpush(a); vpush(d);
  c = alloc(wordsizeof(struct cons), ELM_FIXED, conscp.cix,
	    wordsizeof(struct cons));
  c->c.cons.cdr=vpop();
  c->c.cons.car=vpop();
  return(c);}

pointer cons(ctx,a,d)
register context *ctx;
register pointer a,d;
{
  register pointer c;
  register bpointer b;
  /*
  if ((speval(QCONS)==C_CONS) && (b=buddy[1].bp)) {
    b->h.elmtype=ELM_FIXED;
    buddy[1].bp=b->b.nextbcell;
    freeheap -= 3;
    alloccount[1]++;
    c=makepointer(b);
    cixof(c)=conscp.cix;}
  else*/
   { 
    vpush(a); vpush(d);	/*protect args from garbage collection*/
    c=alloc(vecsize(speval(QCONS)->c.cls.vars), ELM_FIXED, 
	    intval(speval(QCONS)->c.cls.cix), 
	    wordsizeof(struct cons)); 
    ctx->vsp-=2;  } 
  c->c.cons.car=a; c->c.cons.cdr=d;
  return(c);}

pointer stackrawlist(ctx,n)	/*make a list out of elements pushed on vstack*/
register context *ctx;
register int n;
{ register pointer r=NIL, *fsp=ctx->vsp;
  while (n-->0) r=rawcons(ctx,*--fsp,r);
  ctx->vsp=fsp;
  return(r);}

pointer stacknlist(ctx,n)	/*make a list out of elements pushed on vstack*/
register context *ctx;
register int n;
{ register pointer r=NIL, *fsp=ctx->vsp;
  while (n-->0) r=cons(ctx,*--fsp,r);
  ctx->vsp=fsp;
  return(r);}

pointer makebuffer(size)
register int size;
{ register pointer p;
  p = alloc((size+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR, stringcp.cix, (size+2*sizeof(eusinteger_t))>>WORDSHIFT);
  p->c.str.length=makeint(size);
  return(p);}

pointer makestring(s,l)
register char *s;
register int l;
{ register pointer p;
  p=alloc((l+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR, stringcp.cix, (l+2*sizeof(eusinteger_t))>>WORDSHIFT );
  p->c.str.length=makeint(l);
  p->c.ivec.iv[l/sizeof(long)]=0;	/*terminator*/
  memcpy((void *)p->c.str.chars, (void *)s, l);
  return(p);}

pointer make_foreign_string(eusinteger_t addr, int size)
{ register pointer p;
  p=alloc(2, ELM_FOREIGN, stringcp.cix, 2);
  p->c.str.length=makeint(size);
  p->c.ivec.iv[0]=addr;
  return(p);}

pointer makesymbol(ctx,str,leng,home)
register context *ctx;
char *str;
int leng;
pointer home;
{ register pointer sym;
  int cid;
  vpush(makestring(str,leng));
  sym=allocobj(SYMBOL,symbol,symbolcp.cix);
  sym->c.sym.speval=sym->c.sym.spefunc=UNBOUND;
  sym->c.sym.vtype=V_VARIABLE;
  sym->c.sym.homepkg=home;
  sym->c.sym.plist=NIL;
  sym->c.sym.pname=vpop();
  return(sym);}

pointer searchpkg(token,leng)
byte *token;
int leng;
{ pointer pkg,pkgs,names;
  pkgs=pkglist;
  while (pkgs && islist(pkgs)) {
    pkg=ccar(pkgs); pkgs=ccdr(pkgs);
    names=pkg->c.pkg.names;
    while (islist(names)) 
      if (strlength(ccar(names))==leng && 
	  !memcmp((char *)ccar(names)->c.str.chars, (char *)token, leng)) return(pkg);
      else names=ccdr(names);}
  return(NULL);}

pointer findpkg(pkgname)
register pointer pkgname;	/*string or symbol*/
{ register pointer pkg,pkgs,names;
  if (ispackage(pkgname)) return(pkgname);
  pkgname=Getstring(pkgname);
  return(searchpkg(pkgname->c.str.chars,strlength(pkgname)));} 

pointer makepkg(ctx,namestr,nicks,uses)
register context *ctx;
register pointer namestr,nicks,uses;
{ register pointer pkg,symvec,pkgs,names,p;
  register int i;
  /*check pkg name collision*/
  namestr=Getstring(namestr);
  if (findpkg(namestr)) error(E_PKGNAME,namestr);
  vpush(namestr); vpush(nicks); vpush(uses);
  i=0;
  while (islist(nicks)) {
    if (findpkg(ccar(nicks))) error(E_PKGNAME,ccar(nicks));
    vpush(Getstring(ccar(nicks))); i++;
    nicks=ccdr(nicks);}
  nicks=stackrawlist(ctx,i);	/*list up package nicknames*/
  i=0;
  while (islist(uses)) {
    if (p=findpkg(ccar(uses))) { vpush(p); i++; uses=ccdr(uses);}
    else error(E_PKGNAME,ccar(uses));}
  uses=stackrawlist(ctx,i);
  pkg=allocobj(PKGCLASS,package, packagecp.cix);
  pkg->c.pkg.names=pkg->c.pkg.symvector=pkg->c.pkg.intsymvector=NULL;
  pkg->c.pkg.symcount=pkg->c.pkg.intsymcount=makeint(0);
  pkg->c.pkg.use=uses;
  pkg->c.pkg.plist=NIL;
  pkg->c.pkg.shadows=NIL;
  pkg->c.pkg.used_by=NIL;
  vpush(pkg);
  pkg->c.pkg.names=rawcons(ctx,namestr,nicks);
  symvec=makevector(C_VECTOR,SYMBOLHASH);
  for (i=0; i<SYMBOLHASH; i++) symvec->c.vec.v[i]=makeint(0);
  pkg->c.pkg.symvector=symvec;
  symvec=makevector(C_VECTOR,SYMBOLHASH);
  for (i=0; i<SYMBOLHASH; i++) symvec->c.vec.v[i]=makeint(0);
  pkg->c.pkg.intsymvector=symvec;
  pkglist=rawcons(ctx,pkg,pkglist);
  ctx->lastalloc=pkg;
  ctx->vsp -= 4;
  return(pkg);}

pointer mkstream(ctx,dir,string)
register context *ctx;
pointer dir,string;
{ register pointer s;
  vpush(string);
  s=allocobj(STREAM, stream, streamcp.cix);
  s->c.stream.direction=dir;
  s->c.stream.count=s->c.stream.tail=makeint(0);
  s->c.stream.buffer=vpop();
  s->c.stream.plist=NIL;
  return(s);}

pointer mkfilestream(ctx,dir,string,fno,fname)
register context *ctx;
pointer dir,string,fname;
int fno;
{ register pointer s;
  if (dir!=K_IN && dir!=K_OUT) error(E_IODIRECTION);
  vpush(string); vpush(fname);
  s=allocobj(FILESTREAM, filestream, filestreamcp.cix);
  s->c.fstream.direction=dir;
  s->c.fstream.count=s->c.fstream.tail=makeint(0);
  s->c.fstream.fname=vpop();
  s->c.fstream.buffer=vpop();
  s->c.fstream.fd=makeint(fno);
  s->c.fstream.plist=NIL;
  return(s);}

pointer mkiostream(ctx,in,out)
register context *ctx;
register pointer in,out;
{ register pointer ios;
  if (!isstream(in) || !isstream(out)) error(E_STREAM);
  vpush(in); vpush(out);
  ios=allocobj(IOSTREAM, iostream, iostreamcp.cix);
  ios->c.iostream.out=out;
  ios->c.iostream.in=in;
  ios->c.iostream.plist=NIL;
  ctx->vsp -= 2;
  return(ios);}

pointer makecode(mod,f,ftype)
register pointer mod,ftype;
pointer (*f)();
/*actually, f is a pointer to a function returning a pointer*/
{ register pointer cd;
  eusinteger_t fentaddr;
  cd=allocobj(CODE, code, codecp.cix);
  cd->c.code.codevec=mod->c.code.codevec;
  cd->c.code.quotevec=mod->c.code.quotevec;
  cd->c.code.subrtype=ftype;
  fentaddr= (eusinteger_t)f>>2;
  cd->c.code.entry=makeint(fentaddr);
  return(cd);}


/*
/*	for DEFCLASS and INSTANTIATE
*/

bumpcix(m,n)
int m,n;
{ pointer super;
  if (classtab[m].subcix<n) {
    classtab[m].subcix=n;
    super=classtab[m].def->c.cls.super;
    if (isclass(super)) bumpcix(intval(super->c.cls.cix),n);}}

recixobj(newcix)
register int newcix;
{ register struct chunk *cp;
  register bpointer p,tail;
  register int s;
#if defined(BIX_DEBUG) || defined(DEBUG_COUNT)
  static int count = 0;

  count++;
#endif

  for (cp=chunklist; cp!=0; cp=cp->nextchunk) {
    s=buddysize[cp->chunkbix];
    p= &cp->rootcell;
    tail=(bpointer)((eusinteger_t)p+(s<<WORDSHIFT));
    while (p<tail) {
      if (p->h.cix>=newcix) p->h.cix++;
#ifdef BIX_DEBUG
      printf( "recixobj:%d:p=0x%lx, bix = %d\n",
	     count, p, p->h.bix );
#endif
      p=nextbuddy(p);}
    }  }

resetcix(class,p)
pointer class;
cixpair *p;
{ if (class) {
    p->cix=intval(class->c.cls.cix);
    p->sub=classtab[p->cix].subcix;} }

enterclass(classobj)
pointer classobj;
{ pointer super;
  register int i,newcix,temp,supercix;

  if (nextcix>=MAXCLASS) error(E_CLASSOVER);
  super= /*spevalof*/ (classobj->c.cls.super);
  if (isclass(super)) {
    supercix=intval(super->c.cls.cix);
    newcix=classtab[supercix].subcix+1;
    for (i=nextcix-1; i>=newcix; i--) {
      /*reconfigure class hierarchy*/
      bumpcix(i,i+1);
      classtab[i+1]=classtab[i];	/*bump classtab entry*/
      temp=intval(classtab[i].def->c.cls.cix);
      classtab[i].def->c.cls.cix=makeint(temp+1); }
    bumpcix(supercix,newcix);
    /*scan chunks and bumps object's cix which is greater than newcix*/
    if (newcix<nextcix)  recixobj(newcix);
    /*reset system defined class's cix*/
    for (i=0; i<nextbclass; i++)
      resetcix(builtinclass[i].cls, builtinclass[i].cp);
     }
  else newcix=nextcix;
  classobj->c.cls.cix=makeint(newcix);
  classtab[newcix].def=classobj;
  classtab[newcix].subcix=newcix; 
  nextcix++; }

pointer makeclass(ctx,name,superobj,vars,types,forwards,tag,metaclass)
register context *ctx;
pointer name,superobj,vars,types,metaclass,forwards;
int tag;
{ pointer class;
  extern pointer makeobject();

  /* make metaclass cell */
  vpush(vars); vpush(types);
  if (metaclass && isclass(metaclass)) class=makeobject(metaclass);
  else {
    if (tag==0)
      class=allocobj(METACLASS, _class, metaclasscp.cix);
    else 
      class=allocobj(VECCLASS, vecclass, vecclasscp.cix);} 
  class->c.cls.name=name;
  class->c.cls.super=superobj;
  class->c.cls.methods=NIL;
  class->c.cls.vars=vars;
  class->c.cls.types=types;
  class->c.cls.forwards=forwards;
  class->c.cls.plist=NIL;
  if (tag) {	/*vector type class*/
    class->c.vcls.elmtype=makeint(tag);
    class->c.vcls.size=makeint(-1);}
  name->c.sym.speval=class;
/*  name->c.sym.vtype=V_SPECIAL;  */
  name->c.sym.vtype=V_GLOBAL; 
  enterclass(class);	/*determine cix and fill it in the cix slot*/
  vpop(); vpop();
  return(class);  }

pointer makeobject(class)
register pointer class;
{ register pointer obj,*v;
  register int size;
  size=vecsize(class->c.cls.vars);
  obj=alloc(size, ELM_FIXED, intval(class->c.cls.cix), size);
  v=obj->c.obj.iv;
  while (size>0) v[--size]=NIL;
  return(obj);}

pointer makevector(vclass,size)
register pointer vclass;
register int size;
{ register pointer v,init,*vv;
  register int n,etype;

  etype=intval(vclass->c.vcls.elmtype);
  switch(etype) {
    case ELM_BIT: n=(size+WORD_SIZE-1)/WORD_SIZE; init=0; break;
    case ELM_CHAR:
    case ELM_BYTE: n=(size+sizeof(eusinteger_t))/sizeof(eusinteger_t); init=0; break;
    case ELM_FLOAT: n=size; init=(pointer)0; break;
    case ELM_INT: n=size; init=0; break;
    case ELM_FOREIGN: n=1; init=0; break;
    default: n=size; init=NIL;}
  v=alloc(n+1,etype, intval(vclass->c.vcls.cix),n+1);
  v->c.vec.size=makeint(size);
  vv=v->c.vec.v;
  while (--n>=0) vv[n]=init;
  return(v);}

pointer makefvector(s)
register int s;
{ register pointer v;
  register bpointer b;
  v=alloc(s+1,ELM_FLOAT, fltvectorcp.cix,s+1);
  v->c.vec.size=makeint(s);
  return(v);}

pointer defvector(ctx,name,super,elm,size)	/*define vector class*/
register context *ctx;
char *name;
pointer super;
int elm,size;
{ pointer classsym,class,varvector,typevector,forwardvector;
  int i;
  classsym=intern(ctx,name,strlen(name),lisppkg);
  varvector=makevector(C_VECTOR,1);
  vpush(varvector);
  typevector=makevector(C_VECTOR,1);
  typevector->c.vec.v[0]=QINTEGER;
  vpush(typevector);
  forwardvector=makevector(C_VECTOR,1);
  forwardvector->c.vec.v[0]=NIL;
  vpush(forwardvector);
  varvector->c.vec.v[0]=intern(ctx,"LENGTH",6,lisppkg);
  class=makeclass(ctx,classsym,super,varvector,typevector,forwardvector,elm,0); /*!!!*/
  ctx->vsp -= 3;
  return(classsym);}

pointer makematrix(ctx,row,column)
register context *ctx;
int row,column;
{ register pointer v,m;
  register int i;
  v=makefvector(row*column);
  vpush(v);
  m=allocobj(ARRAY, arrayheader, arraycp.cix);
  m->c.ary.entity=v;
  m->c.ary.fillpointer=NIL;
  m->c.ary.rank=makeint(2);
  m->c.ary.offset=makeint(0);
  m->c.ary.dim[0]=makeint(row);
  m->c.ary.dim[1]=makeint(column);
  m->c.ary.plist=NIL;
  for (i=2; i<ARRAYRANKLIMIT; i++) m->c.ary.dim[i]=NIL;
  vpop();
  return(m);}

pointer makemodule(ctx,size)	/*size in bytes*/
register context *ctx;
int size;
{ register pointer mod,cvec;
  cvec=makebuffer(size);
  elmtypeof(cvec)=ELM_BYTE;
  vpush(cvec);
  mod=allocobj(LDMODULE, ldmodule, ldmodulecp.cix);
  mod->c.ldmod.codevec=vpop();
  mod->c.ldmod.quotevec=NIL;
  mod->c.ldmod.entry=NIL;
  mod->c.ldmod.subrtype=NIL;
  mod->c.ldmod.symtab=NIL;
  mod->c.ldmod.objname=NIL;
  mod->c.ldmod.handle=NIL;
  return(mod);}

pointer makeclosure(code,quote,f,e0,e1,e2)
pointer code,quote,e0,*e1,*e2;
pointer (*f)();
{ register pointer clo;
  clo=allocobj(CLOSURE, closure, closurecp.cix);
  clo->c.clo.codevec=code;
  clo->c.clo.quotevec=quote;
  clo->c.clo.subrtype=SUBR_FUNCTION;
  clo->c.clo.entry=makeint((eusinteger_t)f>>2);
  clo->c.clo.env0=e0;
  clo->c.clo.env1=e1; /*makeint((int)e1>>2);*/
  clo->c.clo.env2=e2; /*makeint((int)e2>>2);*/
  return(clo);}

pointer makereadtable(ctx)
register context *ctx;
{ pointer rdtable,rdsyntax,rdmacro,rddispatch;
  vpush((rdsyntax=makebuffer(256)));
  vpush((rdmacro=makevector(C_VECTOR,256)));
  rddispatch=makevector(C_VECTOR,256);
  rdtable=allocobj(READTABLE, readtable, readtablecp.cix);
  vpush(rdtable);
  rdtable->c.rdtab.dispatch=rddispatch;
  rdtable->c.rdtab.macro=rdmacro;
  rdtable->c.rdtab.syntax=rdsyntax;
  rdtable->c.rdtab.plist=NIL;
  ctx->vsp -= 3;
  return(rdtable);}

pointer makelabref(n,v,nxt)
pointer n,v,nxt;
{ pointer l;
  l=alloc(wordsizeof(struct labref), ELM_FIXED, labrefcp.cix,
	  wordsizeof(struct labref));
  l->c.lab.label=n;
  l->c.lab.value=v;
  l->c.lab.next=nxt;
  l->c.lab.unsolved=NIL;
  return(l);}  

/****************************************************************
/* extended numbers
/****************************************************************/
pointer makeratio(num, denom)
int num, denom;
{ pointer r;
  r=allocobj(RATIO, ratio, ratiocp.cix);
  r->c.ratio.numerator=makeint(num);
  r->c.ratio.denominator=makeint(denom);
  /*  printf("ratio cid= %d  r=0x%x\n", ratiocp.cix, r); */
  return(r);}

pointer makebig(n)
int n;
{ register context *ctx=euscontexts[thr_self()];
  register pointer p,v;
  v=makevector(C_INTVECTOR, n);
  vpush(v);
  p=allocobj(BIGNUM, bignum, bignumcp.cix);
  p->c.bgnm.size=makeint(n);
  p->c.bgnm.bv=v;
  vpop();
  return(p);}

pointer makebig1(x)
long x;
{ register context *ctx=euscontexts[thr_self()];
  register pointer p,v;

  v=makevector(C_INTVECTOR, 1);
  vpush(v);
  p=allocobj(BIGNUM, bignum, bignumcp.cix);
  p->c.bgnm.size=makeint(1);
  p->c.bgnm.bv=v;
  v->c.ivec.iv[0]=x;
  vpop();
  return(p);}

pointer makebig2(hi,lo)
long hi, lo;
{ register context *ctx=euscontexts[thr_self()];
  register pointer p,v;

  v=makevector(C_INTVECTOR, 2);
  vpush(v);
  p=allocobj(BIGNUM, bignum, bignumcp.cix);
  p->c.bgnm.size=makeint(2);
  p->c.bgnm.bv=v;
  v->c.ivec.iv[0]=lo;
  v->c.ivec.iv[1]=hi;
  vpop();
  return(p);}


/****************************************************************/
/* defines
/****************************************************************/

pointer defun(ctx,name,mod,f)
register context *ctx;
char *name;
pointer mod;
pointer (*f)();
{ register pointer sym,pkg;
#if defined(DEFUN_DEBUG) || defined(DEBUG_COUNT)
  static int count=0;

  count++;
#endif
#ifdef DEFUN_DEBUG
  printf( "defun:%d:%s:", count, name );
#endif

  pkg=Spevalof(PACKAGE);
  sym=intern(ctx,name,strlen(name),pkg);
  sym->c.sym.spefunc=makecode(mod,f,SUBR_FUNCTION);
#ifdef DEFUN_DEBUG
  printf( "0x%lx\n", sym->c.sym.spefunc->c.code.entry );
#endif
  return(sym);}

pointer defunpkg(ctx,name,mod,f,pkg)
register context *ctx;
char *name;
pointer mod,pkg;
pointer (*f)();
{ pointer sym;
  sym=intern(ctx,name,strlen(name),pkg);
  sym->c.sym.spefunc=makecode(mod,f,SUBR_FUNCTION);
  return(sym);}

pointer defmacro(ctx,name,mod,f)
register context *ctx;
char *name;
pointer mod;
pointer (*f)();
{ register pointer sym,pkg;
  pkg=Spevalof(PACKAGE);
  sym=intern(ctx,name,strlen(name),pkg);
  sym->c.sym.spefunc=makecode(mod,f,SUBR_MACRO);
  return(sym);}

#if Solaris2
int next_special_index=3;
static mutex_t spex_lock;

int special_index()
{ int x;

  if (next_special_index==3) mutex_init(&spex_lock,USYNC_THREAD,NULL);
  mutex_lock(&spex_lock);
  x= next_special_index++;
  mutex_unlock(&spex_lock);
  if (x>=MAX_SPECIALS) { error(E_USER,(pointer)"too many special variables >=256"); }
  return(x);}
#else
int next_special_index=3;

int special_index()
{ int x;

  x= next_special_index++;
  if (x>=MAX_SPECIALS) { error(E_USER,(pointer)"too many special variables >=256"); }

  return(x);}
#endif

pointer defspecial(ctx,name,mod,f)	/*define special form*/
register context *ctx;
char *name;
pointer mod;
pointer (*f)();
{ register pointer sym,pkg;
  pkg=Spevalof(PACKAGE);
  sym=intern(ctx,name,strlen(name),pkg);
  sym->c.sym.spefunc=makecode(mod,f,SUBR_SPECIAL);
  return(sym);}

pointer defconst(ctx,name,val,pkg)
register context *ctx;
char *name;
pointer val,pkg;
{ register pointer sym;
  vpush(val);
  sym=intern(ctx,name,strlen(name),pkg);
  sym->c.sym.vtype=V_CONSTANT;
  sym->c.sym.speval=vpop();
  return(sym);}

pointer defvar(ctx,name,val,pkg)
register context *ctx;
char *name;
pointer val,pkg;
{ register pointer sym;
  int x;
  vpush(val);
  sym=intern(ctx,name,strlen(name),pkg);
  sym->c.sym.vtype=V_GLOBAL;
  sym->c.sym.speval=vpop();
  return(sym);}

pointer deflocal(ctx,name,val,pkg)
register context *ctx;
char *name;
pointer val,pkg;
{ register pointer sym;
  int x;
  vpush(val);
  sym=intern(ctx,name,strlen(name),pkg);
  x=special_index();
  sym->c.sym.vtype=makeint(x);
  /*sym->c.sym.speval=vpop();*/
  /* put the same value in the global symbol-value
	and in the thread's special binding table */
  ctx->specials->c.vec.v[x]=vpop();
  sym->c.sym.speval=val;
  return(sym);}

pointer defkeyword(ctx,name)
register context *ctx;
char *name;
{ register pointer sym;
  sym=intern(ctx,name,strlen(name),keywordpkg);
  return(sym);}

/* 
/* for making compiled function/macro 
*/

extern pointer putprop();

pointer compfun(ctx,sym,mod,entry,doc)
register context *ctx;
register pointer sym,mod,doc;
pointer (*entry)();
{ sym->c.sym.spefunc=makecode(mod,entry,SUBR_FUNCTION);
  if (doc!=NIL) putprop(ctx,sym,doc,K_FUNCTION_DOCUMENTATION); 
  return(sym);}

pointer compmacro(ctx,sym,mod,entry,doc)
register context *ctx;
register pointer sym,mod,doc;
pointer (* entry)();
{ sym->c.sym.spefunc=makecode(mod,entry,SUBR_MACRO);
  if (doc!=NIL) putprop(ctx,sym, doc, K_FUNCTION_DOCUMENTATION); 
  return(sym);}

/****************************************************************/
/* stack frames
/****************************************************************/

struct blockframe *makeblock(ctx,kind,name,jbuf,link)
register context *ctx;
pointer kind,name;
jmp_buf *jbuf;
struct blockframe *link;
{ register struct blockframe *blk=ctx->blkfp;
  *(ctx->vsp)=(pointer)ctx->blkfp; blk=(struct blockframe *)(ctx->vsp);
  (ctx->vsp) += wordsizeof(struct blockframe);
  blk->lexklink=link;
  blk->dynklink=ctx->blkfp;
  blk->kind=kind;
  blk->name=name;
  blk->jbp=jbuf;
  ctx->blkfp=blk;
  return(blk);}

struct fletframe *makeflet(ctx,nm,def,scp,link)
register context *ctx;
pointer nm,def;
struct fletframe *scp,*link;
{ register struct fletframe *ffp=(struct fletframe *)(ctx->vsp);
  register pointer p;
  int i;
  for (i=0; i<sizeof(struct fletframe)/sizeof(pointer); i++)
    vpush(makeint(0));
  ffp->name=nm;
  p=cons(ctx,makeint(scp),def);
  p=cons(ctx,makeint(ctx->bindfp),p);
  p=cons(ctx,nm,p);
  ffp->fclosure=cons(ctx,LAMCLOSURE,p);
  ffp->scope=scp;
  ffp->lexlink=link; ffp->dynlink=ctx->fletfp;	/*dynlink is not used*/
  ctx->fletfp=ffp;
  return(ffp);}

void mkcatchframe(ctx,lab,jbuf)
context *ctx;
pointer lab;
jmp_buf jbuf;
{ struct catchframe *cfp;
  cfp=(struct catchframe *)ctx->vsp;
  cfp->nextcatch=ctx->catchfp;
  cfp->cf=ctx->callfp;
  cfp->bf=ctx->bindfp;
/*  cfp->blkf=blkfp; */
  cfp->jbp=(jmp_buf *)jbuf;
  cfp->label=lab;
  cfp->ff=ctx->fletfp;
  ctx->vsp += (sizeof(struct catchframe)/sizeof(pointer));
  ctx->catchfp=cfp;}

/****************************************************************/
/* new thread context 
/****************************************************************/
extern context *mainctx;

allocate_stack(ctx,n)
context *ctx;
register int n;
{ register int i;
  if (ctx->stack) cfree(ctx->stack);
  n=max(1024,n);
#if 0 /* ???? */
  i=(int)malloc((n+1)*sizeof(pointer));
  if (i==NULL) error(E_STACKOVER);
  ctx->stack=(pointer *)i;
#else
  ctx->stack=(pointer *)malloc((n+1)*sizeof(pointer));
  if (i==NULL) error(E_STACKOVER);
#endif
  ctx->stacklimit= &ctx->stack[n-100]; 
#if STACK_DEBUG
  printf( "allocate_stack: 0x%lx -- 0x%lx\n", ctx->stack, ctx->stacklimit );
#endif
 }

context *makelispcontext(bs_size)
int bs_size;
{ pointer *stk, specialtab;
  context *cntx;
  int i;
  struct buddy_free *thrbuddy;

  cntx=(context *)malloc(sizeof(context));
  if (cntx==NULL) error(E_ALLOCATION);
  if (bs_size<4096) bs_size=4096;
  stk=(pointer *)malloc(sizeof(pointer) * bs_size);
  if (stk==NULL) error(E_ALLOCATION); 
  cntx->stack=stk;
  cntx->vsp=stk;
  cntx->stacklimit = stk+bs_size-64;
#if STACK_DEBUG
  printf( "makelispcontext: stack: 0x%lx -- 0x%lx\n", cntx->stack, cntx->stacklimit );
#endif
  cntx->callfp=NULL;
  cntx->catchfp=NULL;
  cntx->bindfp=NULL;
  cntx->sbindfp=NULL;
  cntx->blkfp=NULL;
  cntx->protfp=NULL;
  cntx->fletfp=NULL;
  cntx->newfletfp=NULL;
  cntx->lastalloc=NULL;
  cntx->errhandler=NULL;
  cntx->alloc_big_count=0;
  cntx->alloc_small_count=0;
  cntx->special_bind_count=0;
  cntx->threadobj=NIL;
  cntx->intsig=0;

 /* create a special variable table for this thread and link to specials slot*/
  if (C_VECTOR) {
    specialtab=makevector(C_VECTOR,MAX_SPECIALS);
    /* copy initial values of special variables from the main context*/
    for (i=0; i<MAX_SPECIALS; i++)
	specialtab->c.vec.v[i]=mainctx->specials->c.vec.v[i];
    cntx->specials=specialtab;}

  { register int i;
    register struct methdef *mc;
    mc=(struct methdef *)malloc(sizeof(struct methdef)*MAXMETHCACHE);
    if (mc==NULL) error(E_ALLOCATION);
    for (i=0; i<MAXMETHCACHE; i++) {
      mc[i].selector=mc[i].class=mc[i].ownerclass=mc[i].method=NULL;} 
    cntx->methcache=mc;
    thrbuddy=(struct buddyfree  *)
			malloc(sizeof(struct buddyfree) * (MAXTHRBUDDY+1));
    if (thrbuddy==NULL) error(E_ALLOCATION);
    cntx->thr_buddy=thrbuddy;
    for (i=0; i<MAXTHRBUDDY; i++) {
      cntx->thr_buddy[i].bp=0;
      cntx->thr_buddy[i].count=0;}
    cntx->thr_buddy[MAXTHRBUDDY].bp= (bpointer)-1;
    }
  return(cntx);}

void deletecontext(id,ctx)
register context *ctx;
{ if (id<MAXTHREAD) euscontexts[id]=NULL;
  cfree(ctx->stack);
  cfree(ctx);}

#if THREADED
pointer makethreadport(ctx)
context *ctx;
{ sema_t *sem;
  pointer s;
  pointer thrport;
  thrport=allocobj(THREAD, threadport, threadcp.cix);

  thrport->c.thrp.plist=NIL;
  thrport->c.thrp.requester=makeint(0);
  vpush(thrport);

  /* make three semaphores; reqsem, runsem, donesem */
  s=makevector(C_INTVECTOR, (sizeof(sema_t)+3)/sizeof(long));
  sema_init((sema_t *)s->c.ivec.iv, 0, USYNC_THREAD, 0);
  thrport->c.thrp.reqsem=s;

  s=makevector(C_INTVECTOR, (sizeof(sema_t)+3)/sizeof(long));
  sema_init((sema_t *)s->c.ivec.iv, 0, USYNC_THREAD, 0);
  thrport->c.thrp.runsem=s;

  s=makevector(C_INTVECTOR, (sizeof(sema_t)+3)/sizeof(long));
  sema_init((sema_t *)s->c.ivec.iv, 0, USYNC_THREAD, 0);
  thrport->c.thrp.donesem=s;

  sema_init(sem, 0, USYNC_THREAD, 0);
  thrport->c.thrp.donesem=makeint(sem); */

  thrport->c.thrp.contex=makeint((eusinteger_t)ctx>>2);
  thrport->c.thrp.func=NIL;
  thrport->c.thrp.args=NIL;
  thrport->c.thrp.result=NIL;
  thrport->c.thrp.idle=NIL;
  thrport->c.thrp.wait=NIL;
  ctx->threadobj=thrport;
  ctx->lastalloc=thrport;
  vpop();
  return(thrport);}
#endif

