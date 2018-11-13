/*****************************************************************/
/* eval.c
/	interpreted evaluation of lisp forms
/*	1986-Jun-6
/*	Copyright Toshihiro Matsui, ETL Umezono Sakuramura
/*	0298-54-5459
*****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"
#define FALSE 0
#define TRUE 1

extern pointer ALLOWOTHERKEYS,K_ALLOWOTHERKEYS;
extern pointer OPTIONAL,REST,KEY,AUX,MACRO,LAMBDA,LAMCLOSURE;
extern char *maxmemory;

#ifdef EVAL_DEBUG
int evaldebug;
#endif

pointer *getobjv(sym,varvec,obj)
register pointer sym;
pointer  varvec,obj;
{ register pointer *vv=varvec->c.vec.v;
  register int i=0,n;
  n=intval(varvec->c.vec.size);
  while (i<n)
    if (vv[i]==sym) return(&(obj->c.obj.iv[i]));
    else i++;
  return(NULL);}

pointer getval(ctx,sym)
register context *ctx;
register pointer sym;
{ register struct bindframe *bf=ctx->bindfp;
  register pointer var,val;
  pointer  *vaddr;
  int vt;
  if (sym->c.sym.vtype>=V_SPECIAL) {
    vt=intval(sym->c.sym.vtype);
    val=ctx->specials->c.vec.v[vt]; /*sym->c.sym.speval;*/
    if (val==UNBOUND) {
      val=sym->c.sym.speval;
      if (val==UNBOUND) error(E_UNBOUND,sym);
      else return(val); }
    else return(val);}
  if (sym->c.sym.vtype==V_CONSTANT) return(sym->c.sym.speval);
  GC_POINT;
  while (bf!=NULL) {
    var=bf->sym;
    val=bf->val;
    if (sym==var) {		/*found in bind-frame*/
      if (val==UNBOUND) goto getspecial;
      return(val);}
    else if (var->cix==vectorcp.cix) {
      vaddr=getobjv(sym,var,val);
      if (vaddr) return(*vaddr);}
    if (bf==bf->lexblink) break;
    bf=bf->lexblink;}
  /*get special value from the symbol cell*/
  /*if (sym->c.sym.vtype==V_GLOBAL) goto getspecial;*/
getspecial:
  val=sym->c.sym.speval;
  if (val==UNBOUND) error(E_UNBOUND,sym);
  else return(val);}

pointer setval(ctx,sym,val)
register context *ctx;
register pointer sym,val;
{ register struct bindframe *bf=ctx->bindfp;
  register pointer var;
  pointer  *vaddr;
  int vt;
  if (sym->c.sym.vtype>=V_SPECIAL) {
    vt=intval(sym->c.sym.vtype);
    pointer_update(ctx->specials->c.vec.v[vt],val);
    return(val);}
  while (bf!=NULL) {
    var=bf->sym;
    if (sym==var) {
      if (bf->val==UNBOUND) goto setspecial;
      pointer_update(bf->val,val); return(val);}
    else if (var->cix==vectorcp.cix) {
      vaddr=getobjv(sym,var,bf->val);
      if (vaddr) {pointer_update(*vaddr,val); return(val);}}
    bf=bf->lexblink; GC_POINT;}
  /* no local var found. try global binding */
  if (sym->c.sym.vtype==V_CONSTANT) error(E_SETCONST,sym);
  if (sym->c.sym.vtype==V_GLOBAL) goto setspecial;
  setspecial:
  pointer_update(sym->c.sym.speval,val);  /* global val*/
  return(val);
  }


pointer getfunc(ctx,f)
register context *ctx;
register pointer f;	/*must be a symbol*/
{ register struct fletframe *ffp=ctx->fletfp;
  while (ffp!=NULL) {
    if (ffp->name==f) {  return(ffp->fclosure);}
    else ffp=ffp->lexlink;}
  if (f->c.sym.spefunc==UNBOUND) error(E_UNDEF,f);
  else {	/*global function definition is taken, context changes*/
    return(f->c.sym.spefunc);}}

/* called from compiled code*/
pointer get_sym_func(s)
pointer s;
{ register pointer f;
  if ((f=s->c.sym.spefunc)==UNBOUND) error(E_UNDEF,s);
  else return(f);}


void setfunc(sym,func)
register pointer sym,func;
{ pointer_update(sym->c.sym.spefunc,func);}

pointer *ovafptr(o,v)
register pointer o,v;
{ register pointer c,*vaddr;
  if (!ispointer(o)) error(E_NOOBJ,o,v);
  c=classof(o);
  vaddr=getobjv(v,c->c.cls.vars,o);
  if (vaddr) return(vaddr);
  else error(E_NOOBJVAR,o,v);}

/***** special variable binding *****/

void bindspecial(ctx,sym,newval)
register context *ctx;
pointer sym,newval;
{ register struct specialbindframe *sbf=(struct specialbindframe *)(ctx->vsp);
  int vt;
  GC_POINT;
  vt=intval(sym->c.sym.vtype);
  ctx->vsp += (sizeof(struct specialbindframe)/sizeof(pointer));
  sbf->sblink=ctx->sbindfp;
  sbf->sym=sym;

  if (sym->c.sym.vtype==V_GLOBAL){
    sbf->oldval=speval(sym); speval(sym)=newval;}
  else { sbf->oldval=spevalof(sym,vt);  spevalof(sym,vt)=newval;}

  ctx->sbindfp=sbf;
  ctx->special_bind_count++;}

/* called by compiled code */
void unbindx(ctx,count)
register context *ctx;
register int count;
{ register pointer s;
  register struct specialbindframe *sbfp=ctx->sbindfp;
  if (ctx->special_bind_count<count) error(E_USER,(pointer)"inconsistent special binding");
  ctx->special_bind_count -= count;
  while (count-- >0) {
    s=sbfp->sym;
    /***/
   if (s->c.sym.vtype==V_GLOBAL) {pointer_update(speval(s),sbfp->oldval);}
   else pointer_update(Spevalof(s),sbfp->oldval); 
    sbfp=sbfp->sblink;}
  ctx->sbindfp=sbfp;}

void unbindspecial(ctx,limit)
register context *ctx;
register struct specialbindframe *limit;
{ register pointer s;
  register struct specialbindframe *sbfp=ctx->sbindfp;
  if (sbfp) {
    while (limit<=sbfp) {	/* < is harmful to unwind in eus.c */
      s=sbfp->sym;
      /***/
      if (s->c.sym.vtype==V_GLOBAL) {pointer_update(speval(s),sbfp->oldval);}
      else pointer_update(Spevalof(s),sbfp->oldval);
      sbfp=sbfp->sblink;
      ctx->special_bind_count--;}
    ctx->sbindfp=sbfp;}}

struct bindframe *fastbind(ctx,var,val,lex)
register context *ctx;
register pointer var,val;
struct bindframe *lex;
{ register struct bindframe *bf;
  bf=(struct bindframe *)(ctx->vsp);
  ctx->vsp += sizeof(struct bindframe)/sizeof(eusinteger_t);
  bf->lexblink=lex;
  bf->dynblink=ctx->bindfp;
  bf->sym=var;
  bf->val=val;
  ctx->bindfp=bf;	/*update bindfp*/
  return(bf);	 }

struct bindframe *vbind(ctx,var,val,lex,declscope)
register context *ctx;
register pointer var,val;
struct bindframe *lex,*declscope;
{ register struct bindframe *p;
  if (!issymbol(var)) error(E_NOSYMBOL);
  if (var->c.sym.vtype==V_CONSTANT) error(E_NOVARIABLE,var);
  p=ctx->bindfp;
  while (p>declscope) {
    if (p->sym==var) 
      if (p->val==UNBOUND) { bindspecial(ctx,var,val); return(ctx->bindfp);}
      else error(E_MULTIDECL);
    if (p==p->lexblink) break;
    p=p->lexblink;}
  /*not found in declare scope*/
  if (var->c.sym.vtype>= /* V_SPECIAL */  V_GLOBAL ) {
	/* For defun-c-callable in eusforeign.l to create a foreign-pod,
		global value of SYMBOL must be replaced with FOREIGN-POD
		by let binding.  Since SYMBOL is V_GLOBAL, special binding
		(global binding) must be made for V_GLOBAL.  Proclaiming
		symbol as SPECIAL is no use, since INTERN does not refer
		thread local binding. */		
    bindspecial(ctx,var,val);
    return(ctx->bindfp);}
  return(fastbind(ctx,var,val,lex));}

struct bindframe *declare(ctx,decllist,env)
register context *ctx;
pointer decllist;
struct bindframe *env;
{ register pointer decl,var;

  while (iscons(decllist)) {
    decl=ccar(decllist); decllist=ccdr(decllist);
    if (!iscons(decl)) error(E_DECLARE);
    if (ccar(decl)==QSPECIAL) {	/*special binding*/
      decl=ccdr(decl);
      while (iscons(decl)) {
	var=ccar(decl);
	if (var->c.sym.vtype < V_SPECIAL) env=vbind(ctx,var,UNBOUND,env,ctx->bindfp);
        decl=ccdr(decl); } }  }
  return(env);}

int parsekeyparams(keyvec,actuals,noarg,results,allowotherkeys)
 /*for compiled codes*/
register pointer keyvec, *actuals, *results;
int noarg,allowotherkeys;
{ register int i=0,n=0,suppliedbits=0,keysize, bitpos;
  register pointer akeyvar, *keys;
  
  if (noarg<=0) return(suppliedbits);
  if (noarg & 1) error(E_KEYPARAM);
  keysize=vecsize(keyvec);
  for (i=0; i<keysize; i++) {
#ifdef SAFETY
      take_care(results[i]);
#endif
      results[i]=NIL;
  }
  while (n<noarg) {
    akeyvar=actuals[n++];
    if (!issymbol(akeyvar)) error(E_KEYPARAM);
    if (akeyvar->c.sym.homepkg!=keywordpkg) error(E_KEYPARAM);
    i=0;	/*search for keyword*/
    keys=keyvec->c.vec.v;
    if (akeyvar==K_ALLOWOTHERKEYS) allowotherkeys=(actuals[n]!=NIL);
    while (i<keysize && keys[i]!=akeyvar) i++;
    if (i<keysize) {	/*keyword found*/
      bitpos = 1<<i;
      if ((suppliedbits & bitpos) ==0) {	/*already supplied-->ignore*/
        pointer_update(results[i],actuals[n]);
        suppliedbits |= bitpos;} }
    else if (!allowotherkeys) error(E_NOKEYPARAM,akeyvar);
    n++;} 
  return(suppliedbits);}

struct bindframe *bindkeyparams(ctx,formal,argp,noarg,env,bf)
register context *ctx;
pointer formal;
pointer *argp;
int noarg;
struct bindframe *env,*bf;
{ pointer fvar,initform;
  register pointer fkeyvar,akeyvar;
  pointer keys[KEYWORDPARAMETERLIMIT],
	  vars[KEYWORDPARAMETERLIMIT],
	  inits[KEYWORDPARAMETERLIMIT];
  register int nokeys=0,i,n,allowotherkeys=0;

  /*parse lambda list and make keyword tables*/
  while (iscons(formal)) {
      fkeyvar=ccar(formal); formal=ccdr(formal);
      if (iscons(fkeyvar)) {
	fvar=ccar(fkeyvar);
        initform=ccdr(fkeyvar);
	if (iscons(initform)) initform=ccar(initform); else initform=NIL;
	if (iscons(fvar)) {
	  fkeyvar=ccar(fvar); fvar=ccdr(fvar);
	  if (!iscons(fvar)) error(E_KEYPARAM);
	  fvar=ccar(fvar);
	  if (!issymbol(fkeyvar)) error(E_NOSYMBOL);
	  if (fkeyvar->c.sym.homepkg!=keywordpkg) error(E_KEYPARAM);}
	else {
	  if (!issymbol(fvar)) error(E_NOSYMBOL);
	  fkeyvar=fvar->c.sym.pname;
	  fkeyvar=intern(ctx,(char *)fkeyvar->c.str.chars,
				vecsize(fkeyvar),keywordpkg);}}
      else if (fkeyvar==ALLOWOTHERKEYS) {
	allowotherkeys=1;
	if (islist(formal)) {
	  fkeyvar=ccar(formal); formal=ccdr(formal);
	  if (fkeyvar==AUX) break;
	  else  error(E_USER,(pointer)"something after &allow-other-keys"); }
	break;}
      else if (fkeyvar==AUX) break;
      else {
	initform=NIL;
	fvar=fkeyvar;
        if (!issymbol(fvar)) error(E_NOSYMBOL);
        fkeyvar=fvar->c.sym.pname;
        fkeyvar=intern(ctx,(char *)fkeyvar->c.str.chars,
				vecsize(fkeyvar),keywordpkg);}
      /**/
      keys[nokeys]=fkeyvar;
      vars[nokeys]=fvar;
      inits[nokeys]=initform;
      nokeys++;
      if (nokeys>=KEYWORDPARAMETERLIMIT) {
	error(E_USER, "Too many keyword parameters >%d",KEYWORDPARAMETERLIMIT);
	}
      }	
  n=0;
  while (n<noarg) {
      akeyvar=argp[n++];
      if (!issymbol(akeyvar)) error(E_KEYPARAM);
      if (akeyvar->c.sym.homepkg!=keywordpkg) error(E_KEYPARAM);
      if (akeyvar==K_ALLOWOTHERKEYS) allowotherkeys=(argp[n]!=NIL);
      i=0;	/*search for keyword*/
      while (i<nokeys && keys[i]!=akeyvar) i++;
      if (n>=noarg) error(E_KEYPARAM);	/*not paired*/
      if (i<nokeys) {
	if (inits[i]!=UNBOUND) {
          env=vbind(ctx,vars[i],argp[n],env,bf);
	  inits[i]=UNBOUND;} }
      else if (!allowotherkeys) error(E_NOKEYPARAM,akeyvar);
      n++;  }
  i=0;
  while (i<nokeys) {
    if (inits[i]!=UNBOUND) env=vbind(ctx,vars[i],eval(ctx,inits[i]),env,bf);
    i++;}
  return(env);}

pointer funlambda(ctx,fn,formal,body,argp,env,noarg)
register context *ctx;
pointer fn,formal,body,*argp;
struct bindframe *env;
int noarg;
{ pointer ftype,fvar,result,decl,aval,initform,fkeyvar,akeyvar;
  pointer *vspsave= ctx->vsp;
  struct specialbindframe *sbfps=ctx->sbindfp;
  struct bindframe *bf=ctx->bindfp;
  struct blockframe *myblock;
  int n=0,keyno=0,i;
  jmp_buf funjmp;

    ctx->bindfp=env;   /*****?????*****/

    /*declaration*/
    while (iscons(body)) {
      decl=ccar(body);
      if (!iscons(decl) || (ccar(decl)!=QDECLARE)) break;
      env=declare(ctx,ccdr(decl),env);
      body=ccdr(body); GC_POINT;}

    /* make a new bind frame */
    while (iscons(formal)) {
      fvar=ccar(formal); formal=ccdr(formal);
      if (fvar==OPTIONAL) goto bindopt;
      if (fvar==REST) goto bindrest;
      if (fvar==KEY) { keyno=n; goto bindkey;}
      if (fvar==AUX) goto bindaux;
      if (n>=noarg) error(E_MISMATCHARG);
      env=vbind(ctx,fvar,argp[n],env,bf);
      n++;}
    if (n!=noarg) error(E_MISMATCHARG);
    goto evbody;
bindopt:
    while (iscons(formal)) {
      fvar=ccar(formal); formal=ccdr(formal);	/*take one formal*/
      if (fvar==REST) goto bindrest;
      if (fvar==KEY) { keyno=n; goto bindkey;}
      if (fvar==AUX) goto bindaux;
      if (n<noarg) { /*an actual arg is supplied*/
        aval=argp[n];
        if (iscons(fvar)) fvar=ccar(fvar);}
      else if (iscons(fvar)) {
        initform=ccdr(fvar);
        fvar=ccar(fvar);
        if (iscons(initform)) {GC_POINT;aval=eval(ctx,ccar(initform));}
        else aval=NIL;}
      else aval=NIL;
      env=vbind(ctx,fvar,aval,env,bf);
      n++;}
    if (n<noarg) error(E_MISMATCHARG);
    goto evbody;
bindrest:
    keyno=n;
    fvar=carof(formal,E_PARAMETER);
    formal=ccdr(formal);
    /*list up all rest arguments*/
    result=NIL;
    i=noarg;
    while (n<i) result=cons(ctx,argp[--i],result);
    env=vbind(ctx,fvar,result,env,bf);
    n++;
    if (!iscons(formal)) goto evbody;
    fvar=ccar(formal); formal=ccdr(formal);
    if (fvar==KEY) goto bindkey;
    else if (fvar==AUX) goto bindaux;
    else error(E_PARAMETER);
bindkey:
    env=bindkeyparams(ctx,formal,&argp[keyno],noarg-keyno,env,bf);
    while (iscons(formal)) {
      fvar=ccar(formal);  formal=ccdr(formal);
      if (fvar==AUX) goto bindaux;}
    goto evbody;
bindaux:
    while (iscons(formal)) {
      fvar=ccar(formal); formal=ccdr(formal);
      if (iscons(fvar)) {
        initform=ccdr(fvar);
        fvar=ccar(fvar);
        if (iscons(initform)) {GC_POINT;aval=eval(ctx,ccar(initform));}
        else aval=NIL;}
      else aval=NIL;
      env=vbind(ctx,fvar,aval,env,bf); }
evbody:
    GC_POINT;
    /*create block around lambda*/
    myblock=(struct blockframe *)makeblock(ctx,BLOCKFRAME,fn,&funjmp,NULL);
    /*evaluate body*/
    if ((result=(pointer)eussetjmp(funjmp))==0) {GC_POINT;result=progn(ctx,body);}
    else if (result==(pointer)1) result=makeint(0);
    /*end of body evaluation: clean up stack frames*/
    ctx->blkfp=myblock->dynklink;
    ctx->bindfp=bf;
    ctx->vsp=vspsave;

#ifdef __RETURN_BARRIER
    check_return_barrier(ctx);
    /* check return barrier */
#endif
/*    unbindspecial(ctx,(struct specialbindframe *)ctx->vsp); */
    unbindspecial(ctx,sbfps+1);
    return(result);}

#if IRIX6

#include <alloca.h>

extern long   i_call_foreign(eusinteger_t (*)(),int,numunion *);
extern double f_call_foreign(eusinteger_t (*)(),int,numunion *);

pointer call_foreign(func,code,n,args)
eusinteger_t (*func)();
pointer code;
int n;
pointer args[];
{ pointer paramtypes=code->c.fcode.paramtypes;
  pointer resulttype=code->c.fcode.resulttype;
  pointer p,lisparg;
  numunion nu,*cargv;
  eusinteger_t i=0;
  double f;

  cargv=(numunion *)alloca(n*sizeof(numunion));
  while (iscons(paramtypes)) {
    p=ccar(paramtypes); paramtypes=ccdr(paramtypes);
    lisparg=args[i];
    if (p==K_INTEGER)
	cargv[i++].ival=isint(lisparg)?intval(lisparg):bigintval(lisparg);
    else if (p==K_FLOAT) cargv[i++].fval=ckfltval(lisparg);
    else if (p==K_STRING)
      if (elmtypeof(lisparg)==ELM_FOREIGN)
        cargv[i++].ival=lisparg->c.ivec.iv[0];
      else cargv[i++].ival=(eusinteger_t)(lisparg->c.str.chars);
    else error(E_USER,(pointer)"unknown type specifier");}
  /* &rest arguments?  */
  while (i<n) {	/* i is the counter for the actual arguments*/
    lisparg=args[i];
    if (isint(lisparg)) cargv[i++].ival=intval(lisparg);
    else if (isflt(lisparg)) cargv[i++].fval=ckfltval(lisparg);
    else if (isvector(lisparg)) {
      if (elmtypeof(lisparg)==ELM_FOREIGN)
	cargv[i++].ival=lisparg->c.ivec.iv[0];
      else cargv[i++].ival=(eusinteger_t)(lisparg->c.str.chars);}
    else cargv[i++].ival=(eusinteger_t)(lisparg->c.obj.iv);}
  /**/
  if (resulttype==K_FLOAT) return(makeflt(f_call_foreign(func,n,cargv)));
  else {
    i=i_call_foreign(func,n,cargv);
    if (resulttype==K_INTEGER) return(mkbigint(i));
    else if (resulttype==K_STRING) {
      p=makepointer(i-2*sizeof(pointer));
      if (isvector(p)) return(p);
      else error(E_USER,(pointer)"illegal foreign string"); }
    else if (iscons(resulttype)) {
	/* (:string [10]) (:foreign-string [20]) */
      if (ccar(resulttype)==K_STRING) {
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)i);
	return(makestring((char *)i, j)); }
      else if (ccar(resulttype)==K_FOREIGN_STRING) {
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)i);
	return(make_foreign_string(i, j)); }
      error(E_USER,(pointer)"unknown result type"); }
    else error(E_USER,(pointer)"result type?"); 
    }}

#else /* IRIX6 */

#if IRIX

#include <alloca.h>

extern int    i_call_foreign(eusinteger_t (*)(),int,int *);
extern double f_call_foreign(eusinteger_t (*)(),int,int *);

pointer call_foreign(func,code,n,args)
eusinteger_t (*func)();
pointer code;
int n;
pointer args[];
{ pointer paramtypes=code->c.fcode.paramtypes;
  pointer resulttype=code->c.fcode.resulttype;
  pointer p,lisparg;
  numunion nu,*cargs;
  eusinteger_t i=0;
  unsigned int *offset,*isfloat,m=0;
  int *cargv;
  union {
    double d;
    struct {
      int i1,i2;} i;
    } numbox;
  double f;

  cargs=(numunion *)alloca(n*sizeof(numunion));
  offset=(unsigned int *)alloca(n*sizeof(unsigned int));
  isfloat=(unsigned int *)alloca(n*sizeof(unsigned int));
  while (iscons(paramtypes)) {
    p=ccar(paramtypes); paramtypes=ccdr(paramtypes);
    lisparg=args[i];
    if (isfloat[i]=(p==K_FLOAT)) {
      cargs[i].fval=ckfltval(lisparg);
      offset[i]=(m+1)&~1; m=offset[i++]+2;}
    else if (p==K_INTEGER) {
      cargs[i++].ival=isint(lisparg)?intval(lisparg):bigintval(lisparg);
      offset[i++]=m++;}
    else if (p==K_STRING) {
      if (elmtypeof(lisparg)==ELM_FOREIGN)
        cargs[i].ival=lisparg->c.ivec.iv[0];
      else cargs[i].ival=(eusinteger_t)(lisparg->c.str.chars);
      offset[i++]=m++;}
    else error(E_USER,(pointer)"unknown type specifier");}
  /* &rest arguments?  */
  while (i<n) {	/* i is the counter for the actual arguments*/
    lisparg=args[i];
    if (isfloat[i]=isflt(lisparg)) {
      cargs[i].fval=ckfltval(lisparg);
      offset[i]=(m+1)&~1; m=offset[i++]+2;}
    else if (isint(lisparg)) {
      cargs[i].ival=intval(lisparg);
      offset[i++]=m++;}
    else if (isvector(lisparg)) {
      if (elmtypeof(lisparg)==ELM_FOREIGN)
	cargs[i].ival=lisparg->c.ivec.iv[0];
      else cargs[i].ival=(eusinteger_t)(lisparg->c.str.chars);
      offset[i++]=m++;}
    else {
      cargs[i++].ival=(eusinteger_t)(lisparg->c.obj.iv);
      offset[i++]=m++;}}
  cargv=(int *)alloca(m*sizeof(int));
  for (i=0; i<n; ++i) {
    if (isfloat[i]) {
      numbox.d=(double)cargs[i].fval;
      cargv[offset[i]]=numbox.i.i1; cargv[offset[i]+1]=numbox.i.i2;}
    else cargv[offset[i]]=cargs[i].ival;}
  /**/
  if (resulttype==K_FLOAT) return(makeflt(f_call_foreign(func,m,cargv)));
  else {
    i=i_call_foreign(func,m,cargv);
    if (resulttype==K_INTEGER) return(mkbigint(i));
    else if (resulttype==K_STRING) {
      p=makepointer(i-2*sizeof(pointer));
      if (isvector(p)) return(p);
      else error(E_USER,(pointer)"illegal foreign string"); }
    else if (iscons(resulttype)) {
	/* (:string [10]) (:foreign-string [20]) */
      if (ccar(resulttype)=K_STRING) {
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)i);
	return(makestring((char *)i, j)); }
      else if (ccar(resulttype)=K_FOREIGN_STRING) {
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)i);
	return(make_foreign_string(i, j)); }
      error(E_USER,(pointer)"unknown result type"); }
    else error(E_USER,(pointer)"result type?"); 
    }}

#else /* IRIX */

/* not IRIS */
#if (defined(x86_64) || defined(aarch64))
extern long exec_function_i(void (*)(), long *, long *, long, long *);
extern long exec_function_f(void (*)(), long *, long *, long, long *);

#if x86_64
// func  %rdi
// iargv %rsi
// fargv %rdx
// vargc %rcx
// vargv %r8
__asm__ (".align 8\n"
#if Darwin
         "_exec_function_i:\n\t"
#else
         "exec_function_i:\n\t"
#endif
         "push %rbx\n\t"
         "sub  $0x120, %rsp\n\t"
         "mov %rdx, %rax\n\t"
         "movsd 0x00(%rax), %xmm0\n\t"
         "movsd 0x08(%rax), %xmm1\n\t"
         "movsd 0x10(%rax), %xmm2\n\t"
         "movsd 0x18(%rax), %xmm3\n\t"
         "movsd 0x20(%rax), %xmm4\n\t"
         "movsd 0x28(%rax), %xmm5\n\t"
         "movsd 0x30(%rax), %xmm6\n\t"
         "movsd 0x38(%rax), %xmm7\n\t"
         "mov %rsp, %rax\n\t"
         "mov  $0, %r10\n\t"
         "cmpl %ecx, %r10d\n\t"
         "jge  .LENDLP\n"
         ".LNEXTLP:\n\t"
         "mov (%r8), %rbx\n\t"
         "mov %rbx, (%rax)\n\t"
         "add  $8, %rax\n\t"
         "add  $8, %r8\n\t"
         "add  $1, %r10d\n\t"
         "cmpl %r10d, %ecx\n\t"
         "jg   .LNEXTLP\n"
         ".LENDLP:\n\t"
         "mov %rdi, %rbx\n\t"
         "mov %rsi, %rax\n\t"
         "mov 0x00(%rax), %rdi\n\t"
         "mov 0x08(%rax), %rsi\n\t"
         "mov 0x10(%rax), %rdx\n\t"
         "mov 0x18(%rax), %rcx\n\t"
         "mov 0x20(%rax), %r8\n\t"
         "mov 0x28(%rax), %r9\n\t"
         "mov $0x00, %eax\n\t"
         "call *%rbx\n\t"
         "add $0x120, %rsp\n\t"
         "pop %rbx\n\t"
         "retq"
         );
__asm__ (".align 8\n"
#if Darwin
         "_exec_function_f:\n\t"
#else
         "exec_function_f:\n\t"
#endif
         "push %rbx\n\t"
         "sub  $0x120, %rsp\n\t"
         "mov %rdx, %rax\n\t"
         "movsd 0x00(%rax), %xmm0\n\t"
         "movsd 0x08(%rax), %xmm1\n\t"
         "movsd 0x10(%rax), %xmm2\n\t"
         "movsd 0x18(%rax), %xmm3\n\t"
         "movsd 0x20(%rax), %xmm4\n\t"
         "movsd 0x28(%rax), %xmm5\n\t"
         "movsd 0x30(%rax), %xmm6\n\t"
         "movsd 0x38(%rax), %xmm7\n\t"
         "mov %rsp, %rax\n\t"
         "mov  $0, %r10\n\t"
         "cmpl %ecx, %r10d\n\t"
         "jge  .LENDLPF\n"
         ".LNEXTLPF:\n\t"
         "mov (%r8), %rbx\n\t"
         "mov %rbx, (%rax)\n\t"
         "add  $8, %rax\n\t"
         "add  $8, %r8\n\t"
         "add  $1, %r10d\n\t"
         "cmpl %r10d, %ecx\n\t"
         "jg   .LNEXTLPF\n"
         ".LENDLPF:\n\t"
         "mov %rdi, %rbx\n\t"
         "mov %rsi, %rax\n\t"
         "mov 0x00(%rax), %rdi\n\t"
         "mov 0x08(%rax), %rsi\n\t"
         "mov 0x10(%rax), %rdx\n\t"
         "mov 0x18(%rax), %rcx\n\t"
         "mov 0x20(%rax), %r8\n\t"
         "mov 0x28(%rax), %r9\n\t"
         "mov $0x00, %eax\n\t"
         "call *%rbx\n\t"
         "movsd %xmm0, (%rsp)\n\t"
         "mov   (%rsp), %rax\n\t"
         "add $0x120, %rsp\n\t"
         "pop %rbx\n\t"
         "retq"
         );
#endif

#if aarch64
__asm__ (".align 8\n"
         "exec_function_i:\n\t"
	 "sub	sp, sp, #192\n\t" // 128(8x16) + 64
	 "stp	x29, x30, [sp, 128]\n\t"
	 "add	x29, sp, 128\n\t"
	 "str	x0, [x29, 56]\n\t" // fc
	 "str	x1, [x29, 48]\n\t" // iargv
	 "str	x2, [x29, 40]\n\t" // fargv
	 "str	x3, [x29, 32]\n\t" // vargc
	 "str	x4, [x29, 24]\n\t" // vargv
	 // vargv -> stack
	 "mov	x1, 0\n\t"
	 "ldr	x2, [x29, 24]\n\t"
	 "b	.FUNCII_LPCK\n\t"
	 ".FUNCII_LP:\n\t"
	 "lsl	x0, x1, 3\n\t"
	 "add	x3, x2, x0\n\t" // vargv[i]
	 "add	x4, sp, x0\n\t" // stack[i]
	 "ldr	x0, [x3]\n\t"
	 "str	x0, [x4]\n\t" // push stack
	 "add	x1, x1, 1\n\t"
	 ".FUNCII_LPCK:\n\t"
	 "ldr	x5, [x29, 32]\n\t"
	 "cmp	x1, x5\n\t"
	 "blt	.FUNCII_LP\n\t"
	 // fargv -> register
	 "ldr	x0, [x29, 40]\n\t" // fargv
	 "ldr	d0, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d1, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d2, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d3, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d4, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d5, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d6, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d7, [x0]\n\t"
	 // iargv -> register
	 "ldr	x0, [x29, 48]\n\t" // iargv
	 "ldr	x9, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x1, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x2, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x3, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x4, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x5, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x6, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x7, [x0]\n\t"
	 // function call
	 "ldr	x8, [x29, 56]\n\t"
	 "mov	x0, x9\n\t"
	 "blr	x8\n\t"
	 "add	sp, x29, 0\n\t"
	 "ldp	x29, x30, [sp], 64\n\t"
	 "ret"
	 );

__asm__ (".align 8\n"
         "exec_function_f:\n\t"
	 "sub	sp, sp, #192\n\t" // 128(8x16) + 64
	 "stp	x29, x30, [sp, 128]\n\t"
	 "add	x29, sp, 128\n\t"
	 "str	x0, [x29, 56]\n\t" // fc
	 "str	x1, [x29, 48]\n\t" // iargv
	 "str	x2, [x29, 40]\n\t" // fargv
	 "str	x3, [x29, 32]\n\t" // vargc
	 "str	x4, [x29, 24]\n\t" // vargv
	 // vargv -> stack
	 "mov	x1, 0\n\t"
	 "ldr	x2, [x29, 24]\n\t"
	 "b	.FUNCFF_LPCK\n\t"
	 ".FUNCFF_LP:\n\t"
	 "lsl	x0, x1, 3\n\t"
	 "add	x3, x2, x0\n\t" // vargv[i]
	 "add	x4, sp, x0\n\t" // stack[i]
	 "ldr	x0, [x3]\n\t"
	 "str	x0, [x4]\n\t" // push stack
	 "add	x1, x1, 1\n\t"
	 ".FUNCFF_LPCK:\n\t"
	 "ldr	x5, [x29, 32]\n\t"
	 "cmp	x1, x5\n\t"
	 "blt	.FUNCFF_LP\n\t"
	 // fargv -> register
	 "ldr	x0, [x29, 40]\n\t" // fargv
	 "ldr	d0, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d1, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d2, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d3, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d4, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d5, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d6, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	d7, [x0]\n\t"
	 // iargv -> register
	 "ldr	x0, [x29, 48]\n\t" // iargv
	 "ldr	x9, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x1, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x2, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x3, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x4, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x5, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x6, [x0]\n\t"
	 "add	x0, x0, 8\n\t"
	 "ldr	x7, [x0]\n\t"
	 // function call
	 "ldr	x8, [x29, 56]\n\t"
	 "mov	x0, x9\n\t"
	 "blr	x8\n\t"
	 "str	d0, [x29, 56]\n\t"
	 "ldr	x0, [x29, 56]\n\t"
	 "add	sp, x29, 0\n\t"
	 "ldp	x29, x30, [sp], 64\n\t"
	 "ret"
	 );
#endif

#if x86_64
#define NUM_INT_ARGUMENTS 6
#define NUM_FLT_ARGUMENTS 8
#define NUM_EXTRA_ARGUMENTS 16
#elif aarch64
#define NUM_INT_ARGUMENTS 8
#define NUM_FLT_ARGUMENTS 8
#define NUM_EXTRA_ARGUMENTS 16
#endif

pointer call_foreign(ifunc,code,n,args)
eusinteger_t (*ifunc)(); /* ???? */
pointer code;
int n;
pointer args[];
{   
  pointer paramtypes=code->c.fcode.paramtypes;
  pointer resulttype=code->c.fcode.resulttype;
  pointer p,lisparg;
  eusinteger_t iargv[NUM_INT_ARGUMENTS];
  eusinteger_t fargv[NUM_FLT_ARGUMENTS];
  eusinteger_t vargv[NUM_EXTRA_ARGUMENTS];
  int icntr = 0, fcntr = 0, vcntr = 0;

  numunion nu;
  eusinteger_t j=0; /*lisp argument counter*//* ???? */
  eusinteger_t c=0;
  union {
    double d;
    float f;
    long l;
    struct {
      int i1,i2;} i;
    } numbox;
  double f;

  if (code->c.fcode.entry2 != NIL) {
    ifunc = (eusinteger_t (*)())((((eusinteger_t)ifunc)&0xffffffff00000000)
      | (intval(code->c.fcode.entry2)&0x00000000ffffffff));
    /* R.Hanai 090726 */
  }
  
  while (iscons(paramtypes)) {
    p=ccar(paramtypes); paramtypes=ccdr(paramtypes);
    lisparg=args[j++];
    if (p==K_INTEGER) {
      c = isint(lisparg)?intval(lisparg):bigintval(lisparg); 
      if(icntr < NUM_INT_ARGUMENTS) iargv[icntr++] = c; else vargv[vcntr++] = c;
    }  else if (p==K_STRING) {
      if (elmtypeof(lisparg)==ELM_FOREIGN) c=lisparg->c.ivec.iv[0];
      else  c=(eusinteger_t)(lisparg->c.str.chars);
      if(icntr < NUM_INT_ARGUMENTS) iargv[icntr++] = c; else vargv[vcntr++] = c;
    } else if (p==K_FLOAT32) {
      numbox.f=(float)ckfltval(lisparg);
      c=((eusinteger_t)numbox.i.i1) & 0x00000000FFFFFFFF;
      if(fcntr < NUM_FLT_ARGUMENTS) fargv[fcntr++] = c; else vargv[vcntr++] = c;
    } else if (p==K_DOUBLE || p==K_FLOAT) {
      numbox.d=ckfltval(lisparg);
      c=numbox.l;
      if(fcntr < NUM_FLT_ARGUMENTS) fargv[fcntr++] = c; else vargv[vcntr++] = c;
    } else error(E_USER,(pointer)"unknown type specifier");
    if (vcntr >= NUM_EXTRA_ARGUMENTS) {
      error(E_USER,(pointer)"too many number of arguments");
    }
  }
  /* &rest arguments?  */
  while (j<n) {	/* j is the counter for the actual arguments*/
    lisparg=args[j++];
    if (isint(lisparg)) {
      c=intval(lisparg);
      if(icntr < NUM_INT_ARGUMENTS) iargv[icntr++] = c; else vargv[vcntr++] = c;
    } else if (isflt(lisparg)) {
      numbox.d=ckfltval(lisparg);	/* i advances independently */
      c=numbox.l;
      if(fcntr < NUM_FLT_ARGUMENTS) fargv[fcntr++] = c; else vargv[vcntr++] = c;
    } else if (isvector(lisparg)) {
      if (elmtypeof(lisparg)==ELM_FOREIGN) c=lisparg->c.ivec.iv[0];
      else c=(eusinteger_t)(lisparg->c.str.chars); 
      if(icntr < NUM_INT_ARGUMENTS) iargv[icntr++] = c; else vargv[vcntr++] = c;
    } else if (isbignum(lisparg)){
      if (bigsize(lisparg)==1){
	eusinteger_t *xv = bigvec(lisparg);
	c=(eusinteger_t)xv[0];
        if(icntr < NUM_INT_ARGUMENTS) iargv[icntr++] = c; else vargv[vcntr++] = c;
      }else{
	fprintf(stderr, "bignum size!=1\n");
      }
    } else {
      c=(eusinteger_t)(lisparg->c.obj.iv);
      if(icntr < NUM_INT_ARGUMENTS) iargv[icntr++] = c; else vargv[vcntr++] = c;
    }
    if (vcntr >= NUM_EXTRA_ARGUMENTS) {
      error(E_USER,(pointer)"too many number of arguments");
    }
  }
  /**/
  if (resulttype==K_FLOAT) {
    numbox.l = exec_function_f((void (*)())ifunc, iargv, fargv, vcntr, vargv);
    f = numbox.d;
    return(makeflt(f));
  } else if (resulttype==K_FLOAT32) {
    numbox.l = exec_function_f((void (*)())ifunc, iargv, fargv, vcntr, vargv);
    f = (double)numbox.f;
    return(makeflt(f));
  } else {
    c = exec_function_i((void (*)())ifunc, iargv, fargv, vcntr, vargv);
    if (resulttype==K_INTEGER) {
      return(mkbigint(c));
    } else if (resulttype==K_STRING) {
      p=makepointer(c-2*sizeof(pointer));
      if (isvector(p)) return(p);
      else error(E_USER,(pointer)"illegal foreign string");
    } else if (iscons(resulttype)) {
      /* (:string [10]) (:foreign-string [20]) */
      if (ccar(resulttype)==K_STRING) { /* R.Hanai 09/07/25 */
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)c);
	return(makestring((char *)c, j)); 
      } else if (ccar(resulttype)==K_FOREIGN_STRING) { /* R.Hanai 09/07/25 */
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)c);
	return(make_foreign_string(c, j)); }
      error(E_USER,(pointer)"unknown result type"); 
    } else error(E_USER,(pointer)"result type?"); 
  }
}
#else /* not x86_64 */
pointer call_foreign(ifunc,code,n,args)
eusinteger_t (*ifunc)(); /* ???? */
pointer code;
int n;
pointer args[];
{ double (*ffunc)();
  pointer paramtypes=code->c.fcode.paramtypes;
  pointer resulttype=code->c.fcode.resulttype;
  pointer p,lisparg;
  eusinteger_t cargv[100];
  numunion nu;
  eusinteger_t i=0; /*C argument counter*//* ???? */
  eusinteger_t j=0; /*lisp argument counter*//* ???? */
  union {
    double d;
    float f;
    struct {
      int i1,i2;} i;
    } numbox;
  double f;
  
  if (code->c.fcode.entry2 != NIL) {
#if (WORD_SIZE == 64)
    ifunc = (((eusinteger_t)ifunc)&0xffffffff00000000) | (intval(code->c.fcode.entry2)&0x00000000ffffffff);
#else
    ifunc = (eusinteger_t (*)())((((int)ifunc)&0xffff0000) | (intval(code->c.fcode.entry2)&0x0000ffff));    /* kanehiro's patch 2000.12.13 */
#endif
  }
  ffunc=(double (*)())ifunc;
  while (iscons(paramtypes)) {
    p=ccar(paramtypes); paramtypes=ccdr(paramtypes);
    lisparg=args[j++];
    if (p==K_INTEGER)
      cargv[i++]=isint(lisparg)?intval(lisparg):bigintval(lisparg);
    else if (p==K_STRING) {
      if (elmtypeof(lisparg)==ELM_FOREIGN) cargv[i++]=lisparg->c.ivec.iv[0];
      else  cargv[i++]=(eusinteger_t)(lisparg->c.str.chars);}
    else if (p==K_FLOAT32) {
      numbox.f=ckfltval(lisparg);
      cargv[i++]=(int)numbox.i.i1;}
    else if (p==K_DOUBLE || p==K_FLOAT) {
      numbox.d=ckfltval(lisparg);
      cargv[i++]=numbox.i.i1; cargv[i++]=numbox.i.i2;}
    else error(E_USER,(pointer)"unknown type specifier");}
  /* &rest arguments?  */
  while (j<n) {	/* j is the counter for the actual arguments*/
    lisparg=args[j++];
    if (isint(lisparg)) cargv[i++]=intval(lisparg);
    else if (isflt(lisparg)) {
      numbox.d=ckfltval(lisparg);	/* i advances independently */
      numbox.f=ckfltval(lisparg);
      cargv[i++]=numbox.i.i1; cargv[i++]=numbox.i.i2;}
    else if (isvector(lisparg)) {
      if (elmtypeof(lisparg)==ELM_FOREIGN)
	cargv[i++]=lisparg->c.ivec.iv[0];
      else cargv[i++]=(eusinteger_t)(lisparg->c.str.chars);}
#if 1    /* begin kanehiro's patch 2000.12.13 */
    else if (isbignum(lisparg)){
      if (bigsize(lisparg)==1){
	eusinteger_t *xv = bigvec(lisparg);
	cargv[i++]=(eusinteger_t)xv[0];
      }else{
	fprintf(stderr, "bignum size!=1\n");
      }
    }
#endif    /* end of kanehiro's patch 2000.12.13 */
    else cargv[i++]=(eusinteger_t)(lisparg->c.obj.iv);}
  /**/
  if (resulttype==K_FLOAT) {
    if (i<=8) 
      f=(*ffunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	         cargv[4],cargv[5],cargv[6],cargv[7]);
    else if (i<=32)
      f=(*ffunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	         cargv[4],cargv[5],cargv[6],cargv[7],
		 cargv[8],cargv[9],cargv[10],cargv[11],
	         cargv[12],cargv[13],cargv[14],cargv[15],
		 cargv[16],cargv[17],cargv[18],cargv[19],
	         cargv[20],cargv[21],cargv[22],cargv[23],
		 cargv[24],cargv[25],cargv[26],cargv[27],
	         cargv[28],cargv[29],cargv[30],cargv[31]);
#if (sun3 || sun4 || mips || alpha)
    else if (i>32) 
      f=(*ffunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	         cargv[4],cargv[5],cargv[6],cargv[7],
		 cargv[8],cargv[9],cargv[10],cargv[11],
	         cargv[12],cargv[13],cargv[14],cargv[15],
		 cargv[16],cargv[17],cargv[18],cargv[19],
	         cargv[20],cargv[21],cargv[22],cargv[23],
		 cargv[24],cargv[25],cargv[26],cargv[27],
	         cargv[28],cargv[29],cargv[30],cargv[31],
	         cargv[32],cargv[33],cargv[34],cargv[35],
		 cargv[36],cargv[37],cargv[38],cargv[39],
	         cargv[40],cargv[41],cargv[42],cargv[43],
		 cargv[44],cargv[45],cargv[46],cargv[47],
	         cargv[48],cargv[49],cargv[50],cargv[51],
	         cargv[52],cargv[53],cargv[54],cargv[55],
		 cargv[56],cargv[57],cargv[58],cargv[59],
	         cargv[60],cargv[61],cargv[62],cargv[63],
		 cargv[64],cargv[65],cargv[66],cargv[67],
	         cargv[68],cargv[69],cargv[70],cargv[71],
	         cargv[72],cargv[73],cargv[74],cargv[75],
	         cargv[76],cargv[77],cargv[78],cargv[79]);
#endif
    return(makeflt(f));}
  else {
    if (i<8) 
      i=(*ifunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	       cargv[4],cargv[5],cargv[6],cargv[7]);
    else if (i<=32)
      i=(*ifunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	         cargv[4],cargv[5],cargv[6],cargv[7],
		 cargv[8],cargv[9],cargv[10],cargv[11],
	         cargv[12],cargv[13],cargv[14],cargv[15],
		 cargv[16],cargv[17],cargv[18],cargv[19],
	         cargv[20],cargv[21],cargv[22],cargv[23],
		 cargv[24],cargv[25],cargv[26],cargv[27],
	         cargv[28],cargv[29],cargv[30],cargv[31]);
#if (sun3 || sun4 || mips || alpha)
    else if (i>32) 
      i=(*ifunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	         cargv[4],cargv[5],cargv[6],cargv[7],
		 cargv[8],cargv[9],cargv[10],cargv[11],
	         cargv[12],cargv[13],cargv[14],cargv[15],
		 cargv[16],cargv[17],cargv[18],cargv[19],
	         cargv[20],cargv[21],cargv[22],cargv[23],
		 cargv[24],cargv[25],cargv[26],cargv[27],
	         cargv[28],cargv[29],cargv[30],cargv[31],
	         cargv[32],cargv[33],cargv[34],cargv[35],
		 cargv[36],cargv[37],cargv[38],cargv[39],
	         cargv[40],cargv[41],cargv[42],cargv[43],
		 cargv[44],cargv[45],cargv[46],cargv[47],
	         cargv[48],cargv[49],cargv[50],cargv[51],
	         cargv[52],cargv[53],cargv[54],cargv[55],
		 cargv[56],cargv[57],cargv[58],cargv[59],
	         cargv[60],cargv[61],cargv[62],cargv[63],
		 cargv[64],cargv[65],cargv[66],cargv[67],
	         cargv[68],cargv[69],cargv[70],cargv[71],
	         cargv[72],cargv[73],cargv[74],cargv[75],
	         cargv[76],cargv[77],cargv[78],cargv[79]);
#endif
    if (resulttype==K_INTEGER) return(mkbigint(i));
    else if (resulttype==K_STRING) {
      p=makepointer(i-2*sizeof(pointer));
      if (isvector(p)) return(p);
      else error(E_USER,(pointer)"illegal foreign string"); }
    else if (iscons(resulttype)) {
	/* (:string [10]) (:foreign-string [20]) */
      if (ccar(resulttype)=K_STRING) {
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)i);
	return(makestring((char *)i, j)); }
      else if (ccar(resulttype)=K_FOREIGN_STRING) {
        resulttype=ccdr(resulttype);
        if (resulttype!=NIL) j=ckintval(ccar(resulttype));
	else j=strlen((char *)i);
	return(make_foreign_string(i, j)); }
      error(E_USER,(pointer)"unknown result type"); }
    else error(E_USER,(pointer)"result type?"); 
    }}
#endif /* x86_64 */
#endif /* IRIX */
#endif /* IRIX6 */
  
pointer funcode(ctx,func,args,noarg)
register context *ctx;
register pointer func,args;
register int noarg;
{ register pointer (*subr)();
  register pointer *argp=ctx->vsp;
  register int n=0;
  register eusinteger_t addr;
  pointer tmp;
  addr=(eusinteger_t)(func->c.code.entry);
#if (WORD_SIZE == 64)
  addr &= ~3L;  /*0xfffffffffffffffc; ???? */
#else
  addr &= ~3;  /*0xfffffffc; ???? */
#endif
#if ARM
  if (func->c.code.entry2 != NIL) {
#if (WORD_SIZE == 64)
    addr = addr | (intval(func->c.code.entry2)&0x00000000ffffffff);
#else
    addr = addr | (intval(func->c.code.entry2)&0x0000ffff);
#endif
  }
#endif
  subr=(pointer (*)())(addr);
#ifdef FUNCODE_DEBUG
  printf( "funcode:func = " ); hoge_print( func );
  printf( "funcode:args = " ); hoge_print( args );
#endif
  GC_POINT;
  switch((eusinteger_t)(func->c.code.subrtype)) {	/*func,macro or special form*//* ???? */
      case (eusinteger_t)SUBR_FUNCTION:/* ???? */
	      if (noarg<0) {
		while (piscons(args)) {
		  vpush(eval(ctx,ccar(args))); args=ccdr(args); n++; GC_POINT;}
	        if (pisfcode(func))	/*foreign function?*/
		  return(call_foreign((eusinteger_t (*)())subr,func,n,argp));
		else return((*subr)(ctx,n,argp));}
	      else if (pisfcode(func))
		return(call_foreign((eusinteger_t (*)())subr,func,noarg,(pointer *)args));
	      else return((*subr)(ctx,noarg,args,0));
	      break;
      case (eusinteger_t)SUBR_MACRO:/* ???? */
	      if (noarg>=0) error(E_ILLFUNC);
	      while (iscons(args)) { vpush(ccar(args)); args=ccdr(args); n++;}
          GC_POINT;
          tmp = (*subr)(ctx,n,argp);
          GC_POINT;
	      return(eval(ctx,tmp));
      case (eusinteger_t)SUBR_SPECIAL: /* ???? */
	      if (noarg>=0) error(E_ILLFUNC);
	      else return((*subr)(ctx,args));
/*      case (int)SUBR_ENTRY:
	      func=(*subr)(func);
	      return(makeint(func)); */
      default: error(E_ILLFUNC); break;}
  }

pointer clofunc;
pointer ufuncall(ctx,form,fn,args,env,noarg)
register context *ctx;
pointer form,fn;
register pointer args;	/*or 'pointer *' */
struct bindframe *env;
int noarg;
{ pointer func,formal,aval,ftype,result,*argp,hook;
  register struct callframe *vf=(struct callframe *)(ctx->vsp);
  struct specialbindframe *sbfps=ctx->sbindfp;
  register int n=0,i;
  register pointer (*subr)();
  struct fletframe *oldfletfp=ctx->fletfp, *fenv;
  GC_POINT;
  /* evalhook */
  if (Spevalof(QEVALHOOK)!=NIL &&  ehbypass==0) {
      hook=Spevalof(QEVALHOOK);
      bindspecial(ctx,QEVALHOOK,NIL);
      if (noarg<0) vpush(cons(ctx,fn,args));
      else {
	argp=(pointer *)args;
	aval=NIL;
	i=noarg;
	while (--i>=0) aval=cons(ctx,argp[i],aval);
	vpush(cons(ctx,fn,aval));}
      vpush(env);
      GC_POINT;
      result=ufuncall(ctx,form,hook,(pointer)(ctx->vsp-2),env,2);	/*apply evalhook function*/
      ctx->vsp=(pointer *)vf;
      unbindspecial(ctx,sbfps+1);
#ifdef __RETURN_BARRIER
      check_return_barrier(ctx);
      /* check return barrier */
#endif
      return(result);}
  else ehbypass=0;

  if (issymbol(fn)) {
    func=getfunc(ctx,fn);
    }
  else {
    if (islist(fn)) env=ctx->bindfp;
    func=fn;}
  if (!ispointer(func)) error(E_ILLFUNC);

  /*make a new stack frame*/
  stackck;	/*stack overflow?*/
  breakck;	/*signal exists?*/
  vf->vlink=ctx->callfp;
  vf->form=form; 
  ctx->callfp=vf;
  ctx->vsp+=sizeof(struct callframe)/(sizeof(pointer));
  argp=ctx->vsp;

  if (pisclosure(func)) {
    clofunc=func;
    fn=func;
    if (fn->c.code.subrtype!=SUBR_FUNCTION) error(E_ILLFUNC);
#if (WORD_SIZE == 64)
    subr=(pointer (*)())((eusinteger_t)(fn->c.code.entry) & ~3L /*0xfffffffc ????*/);
#else
    subr=(pointer (*)())((eusinteger_t)(fn->c.code.entry) & ~3 /*0xfffffffc ????*/);
#endif
#if ARM
    register eusinteger_t addr;
    addr = (eusinteger_t)(fn->c.code.entry);
#if (WORD_SIZE == 64)
    addr &= ~3L;  /*0xfffffffc; ???? */
#else
    addr &= ~3;  /*0xfffffffc; ???? */
#endif
    if (fn->c.code.entry2 != NIL) {
#if (WORD_SIZE == 64)
      addr = addr | (intval(fn->c.code.entry2)&0x00000000ffffffff);
#else
      addr = addr | (intval(fn->c.code.entry2)&0x0000ffff);
#endif
    }
    subr=(pointer (*)())(addr);
#endif
#if !Solaris2 && !SunOS4_1 && !Linux && !IRIX && !IRIX6 && !alpha && !Cygwin
    if ((char *)subr>maxmemory) {
	prinx(ctx,clofunc, STDOUT);
	error(E_USER,(pointer)"garbage closure, fatal bug!"); }
#endif
    if (noarg<0) {
	while (iscons(args)) {
	  vpush(eval(ctx,ccar(args))); args=ccdr(args); n++; GC_POINT;}
	result=(*subr)(ctx,n,argp,func);}	/*call func with env*/
      else result=(*subr)(ctx,noarg,args,func);
    /*recover call frame and stack pointer*/
    ctx->vsp=(pointer *)vf;
    ctx->callfp= vf->vlink;
    ctx->fletfp=oldfletfp;
#ifdef __RETURN_BARRIER
    check_return_barrier(ctx);
    /* check return barrier */
#endif
    return(result);}

  else if (piscode(func)) {	/*call subr*/
    GC_POINT;
    result=funcode(ctx,func,args,noarg);
    ctx->vsp=(pointer *)vf;
    ctx->callfp= vf->vlink;
    ctx->fletfp=oldfletfp;
#ifdef __RETURN_BARRIER
    check_return_barrier(ctx);
#endif
    return(result);}
  else if (piscons(func)) {
    ftype=ccar(func);
    func=ccdr(func);
    if (!issymbol(ftype)) error(E_LAMBDA);
    if (ftype->c.sym.homepkg==keywordpkg) fn=ftype;	/*blockname=selector*/
    else if (ftype==LAMCLOSURE) {
      fn=ccar(func); func=ccdr(func);
      env=(struct bindframe *)intval(ccar(func));
      if (env < (struct bindframe *)ctx->stack ||
	  (struct bindframe *)ctx->stacklimit < env) env=0;
      func=ccdr(func);
      /* ctx->fletfp=(struct fletframe *)intval(ccar(func)); */
      fenv=(struct fletframe *)intval(ccar(func)); 
      func=ccdr(func);}
    else if (ftype!=LAMBDA && ftype!=MACRO) error(E_LAMBDA);
    else env=NULL /*0 ????*/; 
    formal=carof(func,E_LAMBDA);
    func=ccdr(func);
    if (noarg<0) {	/*spread args on stack*/
      noarg=0;
      while (iscons(args)) {
	aval=ccar(args);
	args=ccdr(args);
	if (ftype!=MACRO) {GC_POINT;aval=eval(ctx,aval);}
	vpush(aval); noarg++;}}
    else {
      argp=(pointer *)args;
      if (ftype==MACRO) error(E_ILLFUNC);}
    GC_POINT;
    if (ftype==LAMCLOSURE) { ctx->fletfp=fenv; }
    result=funlambda(ctx,fn,formal,func,argp,env,noarg);
    ctx->vsp=(pointer *)vf;
    ctx->callfp=vf->vlink;
    GC_POINT;
    if (ftype==MACRO) result=eval(ctx,result);
    ctx->fletfp=oldfletfp;
#ifdef __RETURN_BARRIER
    check_return_barrier(ctx);
    /* check return barrier */
#endif
    return(result);}
  else error(E_ILLFUNC);
  }

pointer eval(ctx,form)
register context *ctx;
register pointer form;
{ register pointer c;
  register pointer p;
#if defined(DEBUG_COUNT) || defined(EVAL_DEBUG)
  static int count=0;
  int save_count;

  count++;
  save_count = count;
#endif
#ifdef EVAL_DEBUG
  if( evaldebug ) {
      printf( "%d:", count );
      hoge_print(form);
  }
#endif
  GC_POINT;
  if (isnum(form)) p = form;
  else if (pissymbol(form)) p = getval(ctx,form);
  else if (!piscons(form)) p = form;
  else {
    c=ccdr(form);
    if (c!=NIL && issymbol(c)) p = (*ovafptr(eval(ctx,ccar(form)),c));
    else {
      p = ufuncall(ctx,form,ccar(form),c,NULL,-1);
#ifdef SAFETY
      take_care(p);
#endif
    }
  }

#ifdef EVAL_DEBUG
  if( evaldebug ) {
      printf( "%d:--- ", save_count );
      hoge_print(p);
  }
#endif
  return(p);
  }

pointer eval2(ctx,form,env)
register context *ctx;
register pointer form;
pointer env;
{ register pointer c;
  GC_POINT;
  if (isnum(form)) return(form);
  else if (pissymbol(form)) return(getval(ctx,form));
  else if (!piscons(form)) return(form);
  else {
    c=ccdr(form);
    if (c!=NIL && issymbol(c)) return(*ovafptr(eval(ctx,ccar(form)),c));
    else return(ufuncall(ctx,form,ccar(form),(pointer)c,(struct bindframe *)env,-1));}
  }

pointer progn(ctx,forms)
register context *ctx;
register pointer forms;
{ register pointer result=NIL;
  while (iscons(forms)) {
    GC_POINT;
    result=eval(ctx,ccar(forms)); forms=ccdr(forms);}
  return(result);}


/* csend(ctx,object,selector,argc,arg1,arg2,....) */
#ifdef USE_STDARG

pointer csend(context *ctx, ...)
{
  va_list ap;

  pointer rec,sel;
  int cnt;
  pointer res,*spsave;
  int i=0;

  va_start(ap, ctx);

  rec = va_arg(ap,pointer);
  sel = va_arg(ap,pointer);
  cnt = va_arg(ap,int);
  spsave=ctx->vsp;
  vpush(rec); vpush(sel);
  while (i++ < cnt) vpush(va_arg(ap,pointer));
  GC_POINT;
  res=(pointer)SEND(ctx,cnt+2, spsave);
  ctx->vsp=spsave;
  return(res);}

#else
pointer csend(va_alist)
va_dcl
{ va_list ap;
  pointer rec,sel;
  int cnt;
  pointer res,*spsave;
  int i=0;
  register context *ctx;

  va_start(ap);
  ctx = va_arg(ap,context *);
  rec = va_arg(ap,pointer);
  sel = va_arg(ap,pointer);
  cnt = va_arg(ap,int);
  spsave=ctx->vsp;
  vpush(rec); vpush(sel);
  while (i++ < cnt) vpush(va_arg(ap,pointer));
  GC_POINT;
  res=(pointer)SEND(ctx,cnt+2, spsave);
  ctx->vsp=spsave;
#ifdef SAFETY
  take_care(res);
#endif
  return(res);}
#endif

