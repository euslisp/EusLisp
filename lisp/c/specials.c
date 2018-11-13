/*****************************************************************
/*	specials.c
/*	special-forms (let,let*,catch,throw,unwind-protect,...)
/*	control structures,
/*	macros ...
/*
/*	Copyright: Toshihiro Matsui  ETL, Umezono, Sakura-mura
/*        
/*	1986
/*	1986-Dec	let*
/*	1987-Mar	special binding declaration
*****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"
extern pointer MACRO,LAMBDA,LAMCLOSURE;
extern pointer K_FUNCTION_DOCUMENTATION;
extern struct bindframe  *declare();

#ifdef EVAL_DEBUG
extern int evaldebug;
#endif

/*gensym*/
static pointer genhead;
static int     genindex,tempindex=0;
static pointer QRETFROM,QEVAL,QPROGN,QIF;

/****************************************************************/
/* special forms
/****************************************************************/

pointer quote(ctx,arg)
register context *ctx;
register pointer arg;
{
#ifdef SPEC_DEBUG
    printf( "quote:" ); hoge_print(arg);
#endif
 return(carof(arg,E_MISMATCHARG));
}

pointer EVAL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer env;
  ckarg2(1,2);
  if (n==2) env=argv[1]; else env=NULL;
#ifdef SPEC_DEBUG
  printf( "EVAL:" );
  hoge_print_sub(argv[0]);
  if( env != NULL )
    hoge_print_sub( env );
  printf( "\n" );
#endif
  return(eval2(ctx,argv[0],env));}

pointer PROGN(ctx,arg)
register context *ctx;
register pointer arg;
{
#ifdef SPEC_DEBUG
    printf( "PROGN:" );	hoge_print( arg );
#endif
 return(progn(ctx,arg));}

pointer PROG1(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{
#ifdef SPEC_DEBUG
    printf( "PROG1:" );
    if( n >= 0 ) hoge_print_sub( argv[0] );
    printf( "\n" );
#endif
 return((n>=1)?argv[0]:NIL);}

pointer APPLY(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a,*spsave=ctx->vsp,fun=argv[0];
  register int i=1,argc=n-2;

  if (n<2) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "APPLY:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  if (issymbol(fun)) {
    if (fun->c.sym.spefunc==UNBOUND) error(E_UNDEF,argv[0]);}
  while (i<n-1) ckpush(argv[i++]);
  a=argv[i];
  while (islist(a)) {
    ckpush(ccar(a));
    a=ccdr(a);
    argc++;}
  a=(pointer)ufuncall(ctx,(ctx->callfp?ctx->callfp->form:NIL),
			fun,(pointer)spsave,NULL,argc);
  ctx->vsp=spsave;
#ifdef SAFETY
  take_care(a);
#endif
  return(a);}

pointer FUNCALL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer fun=argv[0];
  if (n<1) error(E_MISMATCHARG);
#if SPEC_DEBUG
  printf( "FUNCALL:" );
  {
      int i;
      for( i = 0; i < n; i++ )
	hoge_print_sub( argv[i] );
  }
  printf( "\n" );
#endif
  if (issymbol(fun)) {
    if (fun->c.sym.spefunc==UNBOUND) error(E_UNDEF,fun);}
  pointer_update(Spevalof(QEVALHOOK),NIL);
  return((pointer)ufuncall(ctx,ctx->callfp->form,fun,(pointer)&argv[1],NULL,n-1));}

pointer FUNCTION_CLOSURE(ctx,arg)
register context *ctx;
pointer arg;
{ pointer funcname;
  if (!islist(arg)) error(E_MISMATCHARG);
  if (ccdr(arg)!=NIL) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "FUNCTION_CLOSURE:" );
  hoge_print( arg );
#endif
  arg=ccar(arg);
  if (issymbol(arg)) { funcname=arg; arg=getfunc(ctx,arg);}
  else funcname=NIL;
  if (iscode(arg)) return(arg);
  else if (ccar(arg)==LAMCLOSURE) return(arg);
  else if (ccar(arg)==LAMBDA) {
    arg=cons(ctx,makeint(hide_ptr((pointer)(ctx->fletfp))),ccdr(arg));
    arg=cons(ctx,makeint(hide_ptr((pointer)(ctx->bindfp))),arg);
    arg=cons(ctx,funcname,arg);
    return(cons(ctx,LAMCLOSURE,arg));}
  else error(E_ILLFUNC);}

pointer MACEXPAND2(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer mac,args,expander,*argp,result;
  int noarg=0;
  ckarg(1);
#ifdef SPEC_DEBUG
  printf( "MACEXPAND2:" ); hoge_print( argv[0] );
#endif
  if (!islist(argv[0])) return(argv[0]);
  mac=ccar(argv[0]); args=ccdr(argv[0]);
  if (issymbol(mac)) mac=getfunc(ctx,mac);
  if (iscode(mac)) {
#if ARM
    eusinteger_t addr = (eusinteger_t)(mac->c.code.entry);
#if (WORD_SIZE == 64)
    addr &= ~3L;  /*0xfffffffc; ???? */
#else
    addr &= ~3;  /*0xfffffffc; ???? */
#endif
#if (WORD_SIZE == 64)
    addr = addr | (intval(mac->c.code.entry2)&0x00000000ffffffff);
#else
    addr = addr | (intval(mac->c.code.entry2)&0x0000ffff);
#endif
#endif // ARM
    if (mac->c.code.subrtype!=(pointer)SUBR_MACRO) return(argv[0]);
#if ARM
    expander=makecode(mac,(pointer (*)())addr,SUBR_FUNCTION);
    pointer_update(expander->c.code.entry2,mac->c.code.entry2)
#else
    expander=makecode(mac,(pointer (*)())mac->c.code.entry,SUBR_FUNCTION);
#endif
    pointer_update(expander->c.code.entry,mac->c.code.entry);}
  else if (carof(mac,E_NOLIST)==MACRO) expander=cons(ctx,LAMBDA,ccdr(mac));
  else return(argv[0]);
  vpush(expander);
  argp=ctx->vsp; 
  while (islist(args)) { vpush(ccar(args)); args=ccdr(args); noarg++;}
  GC_POINT;
  mac=ufuncall(ctx,ctx->callfp->form,expander,(pointer)argp,NULL,noarg);
  /* ???? ctx->lastalloc=mac; ????*/
  ctx->vsp=argp-1;
  return(mac);}

/****************************************************************/
/* mapping
/****************************************************************/
pointer MAPC(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register pointer a;
  register int i;
  if (n<2) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "MAPC:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  while (islist(argv[1])) {
    i=1;
    while (i<n) {
      a=argv[i];
      if (!islist(a)) error(E_NOLIST);
      ckpush(ccar(a));
      argv[i]=ccdr(a);
      i++;}
    i--;
    GC_POINT;
    ufuncall(ctx,ctx->callfp->form,argv[0],(pointer)(ctx->vsp - i),NULL,i);
    ctx->vsp -= i;}
  return(argv[1]);}

pointer MAPCAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ register pointer a,r;
  register int rcount=0,i;
  pointer (*subr)();

  if (n<2) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "MAPCAR:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  while (islist(argv[1])) {
    i=1;
    while (i<n) {
      a=argv[i];
      if (!islist(a)) error(E_NOLIST);
      ckpush(ccar(a));
      argv[i]=ccdr(a);
      i++;}
    i--;
    GC_POINT;
    r=ufuncall(ctx,ctx->callfp->form,argv[0],(pointer)(ctx->vsp - i),NULL,i);
    ctx->vsp -=i;
    vpush(r);
    rcount++;}
    GC_POINT;
  r=(pointer)stacknlist(ctx,rcount);
  return(r);}

pointer MAPCAN(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register pointer a,r;
  register int i,rcount=0;
  pointer *spsave=ctx->vsp;
  if (n<2) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "MAPCAN:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  while (islist(argv[1])) {
    i=1;
    while (i<n) {
      a=argv[i];
      if (!islist(a)) error(E_NOLIST);
      ckpush(ccar(a));
      argv[i]=ccdr(a);
      i++;}
    i--;
    GC_POINT;
    r=ufuncall(ctx,ctx->callfp->form,argv[0],(pointer)(ctx->vsp -i),NULL,i);
    ctx->vsp -=i;
    vpush(r);
    rcount++;}
    GC_POINT;
  a=(pointer)NCONC(ctx,rcount,spsave);
  ctx->vsp=spsave;
  return(a);}

/****************************************************************/
/* SETQ
/****************************************************************/
pointer SETQ(ctx,arg)
register context *ctx;
register pointer arg;
{ register pointer var,val=NIL, *p;
#ifdef SPEC_DEBUG
  printf( "SETQ:" );  hoge_print( arg );
#endif
  while (iscons(arg)) {
    var=ccar(arg); arg=ccdr(arg);
    if (!islist(arg)) error(E_MISMATCHARG);
    GC_POINT;
    val=eval(ctx,ccar(arg)); arg=ccdr(arg);
    if (issymbol(var)) setval(ctx,var,val);
    else if (islist(var) && issymbol(ccdr(var)) && ccdr(var)!=NIL) {
      vpush(val);
      p=(pointer *)ovafptr(eval(ctx,ccar(var)),ccdr(var)); pointer_update(*p,vpop());}
    else error(E_NOSYMBOL,var);}
  return(val);}


/****************************************************************/
/* control structures
/****************************************************************/

pointer IF(ctx,arg)
register context *ctx;
register pointer arg;
{ register pointer rest;
  rest=cdrof(arg, E_MISMATCHARG);
  if (!iscons(rest)) return(NIL);
#ifdef SPEC_DEBUG
  printf( "IF:" ); hoge_print( arg );
#endif
  GC_POINT;
  if (eval(ctx,ccar(arg))!=NIL) return(eval(ctx,ccar(rest)));
  else {
    rest=ccdr(rest);
    if (iscons(rest)) return(eval(ctx,ccar(rest)));
    else return(NIL);  } }

pointer WHEN(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer form=NIL;
  int i;
  if (n<1) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "WHEN:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  while (n>1) form=cons(ctx,argv[--n],form);
  form=cons(ctx,QPROGN,form);
  form=cons(ctx,argv[0],cons(ctx,form,NIL));
  return(cons(ctx,QIF,form));}

pointer WHILE(ctx,arg)
register context *ctx;
pointer arg;
{ pointer cond,body,*spsave=ctx->vsp,result;
  struct blockframe *myblock;
  struct bindframe *bfp=ctx->bindfp;
  jmp_buf whilejmp;
  int i;

#ifdef SPEC_DEBUG
  printf( "WHILE:" );	hoge_print(arg);
#endif
  if (!islist(arg)) return(NIL);
  cond=ccar(arg); body=ccdr(arg);
  myblock=(struct blockframe *)
		makeblock(ctx,BLOCKFRAME,NIL,&whilejmp,ctx->blkfp); /* ???? */
  if ((result=(pointer)eussetjmp(whilejmp))==0) {
    while (eval(ctx,cond)!=NIL) {GC_POINT;progn(ctx,body);}
    result=NIL;}
  else if ((eusinteger_t)result==1) result=makeint(0);
  ctx->blkfp=myblock->dynklink;
  ctx->vsp=spsave;
  ctx->bindfp=bfp;
  return(result);}

pointer COND(ctx,arg)
register context *ctx;
pointer arg;
{ register pointer clause,cond;

#ifdef SPEC_DEBUG
  printf( "COND:" );	hoge_print(arg);
#endif
  while (islist(arg)) {
    clause=ccar(arg);
    if (!islist(clause)) error(E_NOLIST);
    GC_POINT;
    cond=eval(ctx,ccar(clause));
    if (cond!=NIL) if (islist(ccdr(clause))) return(progn(ctx,ccdr(clause)));
		   else return(cond);
    arg=ccdr(arg);}
  return(NIL);}

pointer PARLET(ctx,args)	/*let special form*/
register context *ctx;
pointer args;
{ pointer vlist,vlistsave,var,init,body,result,decl,*spsave=ctx->vsp,*vinits;
  register struct bindframe *env, *bfsave=ctx->bindfp, *declenv;
  struct specialbindframe *sbfps=ctx->sbindfp;
  int i=0,vcount=0;
#if defined(PARLET_DEBUG) || defined(DEBUG_COUNT)
  static int count = 0;

  count++;
#endif

#if defined(SPEC_DEBUG) || defined(PARLET_DEBUG)
  printf( "PARLET:%d",count );	hoge_print(args);
#endif

  vlist=carof(args,E_MISMATCHARG);
  body=ccdr(args);
  env=bfsave;

  /*declaration*/
  while (islist(body)) {
    decl=ccar(body);
    if (!islist(decl) || (ccar(decl)!=QDECLARE)) break;
    env=declare(ctx,ccdr(decl),env);	/*add special decl. to current env*/
    body=ccdr(body);}

  GC_POINT;
  /*evaluate variable initializers*/
  vlistsave=vlist;
  vinits=ctx->vsp;
  while (islist(vlist)) {
    var=ccar(vlist); vlist=ccdr(vlist);
    if (islist(var)) {
      init=ccdr(var); var=ccar(var);
      if (islist(init)) init=eval(ctx,ccar(init));
      else init=NIL;}
    else init=NIL;
    vpush(init); vcount++;}
  /*update bindings at once*/
  GC_POINT;
  vlist=vlistsave;
  while (i<vcount)  {
    var=ccar(vlist); vlist=ccdr(vlist);
    if (islist(var)) var=ccar(var);
    env=vbind(ctx,var,vinits[i++],env,bfsave);}

  result=progn(ctx,body);	/*evaluate body*/
  ctx->bindfp=bfsave; 		/*restore environments*/
  ctx->vsp=spsave;
  unbindspecial(ctx,(struct specialbindframe *)ctx->vsp);
  /* unbindspecial(ctx,sbfps+1); */
  return(result);}

pointer SEQLET(ctx,args)	/* let* special form*/
register context *ctx;
pointer args;
{ pointer vlist,var,init,body,result,decl,*spsave=ctx->vsp;
  register struct bindframe *bf=ctx->bindfp, *env;
  struct specialbindframe *sbfps=ctx->sbindfp;

#ifdef SPEC_DEBUG
  printf( "SEQLET:" );	hoge_print(args);
#endif

  GC_POINT;
  vlist=carof(args,E_MISMATCHARG);
  body=ccdr(args);
  env=bf;	/*inherit lexical variable scope*/

  /*declaration*/
  while (islist(body)) {
    decl=ccar(body);
    if (!islist(decl) || (ccar(decl)!=QDECLARE)) break;
    env=declare(ctx,ccdr(decl),env);
    body=ccdr(body);}

  /*bind let* variables*/
  while (islist(vlist)) {
    GC_POINT;
    var=ccar(vlist); vlist=ccdr(vlist);
    if (islist(var)) {
      init=ccdr(var); var=ccar(var);
      if (islist(init)) init=eval(ctx,ccar(init));
      else init=NIL;}
    else init=NIL;
    env=vbind(ctx,var,init,env,bf);
    }

  /*evaluate body*/
  result=progn(ctx,body);
  /*restore environments*/
  ctx->bindfp=bf;
  ctx->vsp=spsave;
  unbindspecial(ctx,(struct specialbindframe *)ctx->vsp); 
/*  unbindspecial(ctx,sbfps+1); */
  return(result);}

pointer CATCH(ctx,arg)	/*special form*/
register context *ctx;
pointer arg;
{ pointer tag,body,val;
  jmp_buf catchbuf;
  int i;

#ifdef SPEC_DEBUG
  printf( "CATCH:" );	hoge_print(arg);
#endif

  tag=carof(arg,E_MISMATCHARG); tag=eval(ctx,tag);
  body=ccdr(arg);
  mkcatchframe(ctx,tag,&catchbuf);
  if ((val=(pointer)eussetjmp(catchbuf))==0) val=progn(ctx,body);
  else if ((eusinteger_t)val==1) val=makeint(0);	/*longjmp cannot return 0*/
  ctx->callfp=ctx->catchfp->cf;
  ctx->bindfp=ctx->catchfp->bf;
  ctx->fletfp=ctx->catchfp->ff;
  ctx->vsp=(pointer *)ctx->catchfp;
  ctx->catchfp=(struct catchframe *)*ctx->vsp;
#ifdef __RETURN_BARRIER
  check_return_barrier(ctx);
#endif
  return(val);}

void throw(ctx,tag,result)
register context *ctx;
register pointer tag,result;
{ register struct catchframe *cfp=ctx->catchfp;
  while (cfp!=NULL) 
    if (cfp->label==tag) {
      ctx->catchfp=cfp;
      unwind(ctx,(pointer *)ctx->catchfp);
      euslongjmp(*(ctx->catchfp->jbp),result);}
    else cfp=cfp->nextcatch;}

pointer THROW(ctx,arg)
register context *ctx;
register pointer arg;
{
  pointer tag,result;
#ifdef SPEC_DEBUG
  printf( "THROW:" ); hoge_print(arg);
#endif
  tag=carof(arg,E_MISMATCHARG);
  arg=ccdr(arg);
  result=carof(arg,E_MISMATCHARG);
  GC_POINT;
  tag=eval(ctx,tag); 
  GC_POINT;
  result=eval(ctx,result);
  throw(ctx,tag,result);
  error(E_NOCATCHER,tag);}

pointer FLET(ctx,arg)
register context *ctx;
register pointer arg;
{ register pointer fns, fn;
  register struct fletframe *ffp=ctx->fletfp;
  pointer result;
#ifdef SPEC_DEBUG
  printf( "FLET:" ); hoge_print(arg);
#endif
  GC_POINT;
  fns=ccar(arg);
  while (iscons(fns)) {
    fn=ccar(fns); fns=ccdr(fns);
    makeflet(ctx,ccar(fn),ccdr(fn),ffp,ctx->fletfp);}
  result=progn(ctx,ccdr(arg));
  ctx->fletfp=ffp;
  return(result);}

pointer LABELS(ctx,arg)
register context *ctx;
register pointer arg;
{ register pointer fns, fn;
  register struct fletframe *ffp=ctx->fletfp, *ffpp;
  pointer result;
#ifdef SPEC_DEBUG
  printf( "LABELS:" ); hoge_print(arg);
#endif
  GC_POINT;
  fns=ccar(arg);
  while (iscons(fns)) {
    fn=ccar(fns); fns=ccdr(fns);
    makeflet(ctx,ccar(fn),ccdr(fn),ctx->fletfp,ctx->fletfp);}
  fns=ccar(arg); ffpp=ctx->fletfp;
  while (iscons(fns)) {	/*allow mutual references between labels functions*/
    fn=ffpp->fclosure;
    fn=ccdr(fn); fn=ccdr(fn); fn=ccdr(fn); ccar(fn)=makeint(hide_ptr((pointer)(ctx->fletfp)));
    fns=ccdr(fns); ffpp=ffpp->lexlink;}
  result=progn(ctx,ccdr(arg));
  ctx->fletfp=ffp;
  return(result);}

pointer RESET(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{
#ifdef SPEC_DEBUG
  printf( "RESET:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub(argv[i] );
}
  printf( "\n" );
#endif
 throw(ctx,makeint(0),T);
  error(E_USER,(pointer)"cannot reset");}

pointer EVALHOOK(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer form,val,env, *vspsave=ctx->vsp;
  struct specialbindframe *sbfps=ctx->sbindfp;

  ckarg2(2,3);
#ifdef SPEC_DEBUG
  printf( "EVALHOOK:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub(argv[i] );
}
  printf( "\n" );
#endif
  if (n==3) env=argv[2]; else env=NULL;
  form=argv[0];
  GC_POINT;
  if (islist(form)) {
    ehbypass=1;
    bindspecial(ctx,QEVALHOOK,argv[1]);
    val=eval2(ctx,form,env);
    unbindspecial(ctx,(struct specialbindframe *)vspsave);
/*    unbindspecial(ctx,sbfps+1); */
    return(val);}
  else return(eval2(ctx,form,env));}

pointer BLOCK(ctx,arg)	/*special form*/
register context *ctx;
register pointer arg;		/*must be called via ufuncall*/
{ pointer name,result,*spsave=ctx->vsp;
  struct blockframe *myblock;
  struct bindframe *bfp=ctx->bindfp;
  jmp_buf blkjmp;
#ifdef SPEC_DEBUG
  printf( "BLOCK:" ); hoge_print(arg);
#endif

  GC_POINT;
  name=carof(arg,E_MISMATCHARG); arg=ccdr(arg);
  if (!issymbol(name)) error(E_NOSYMBOL);
  myblock=(struct blockframe *)makeblock(ctx,BLOCKFRAME,name,&blkjmp,ctx->blkfp); /* ???? */
  if ((result=(pointer)eussetjmp(blkjmp))==0) result=progn(ctx,arg);
  else if ((eusinteger_t)result==1) result=makeint(0);
  ctx->blkfp=myblock->dynklink;
  /*restorations of bindfp and callfp are caller's responsibility???*/
  ctx->bindfp=bfp;
  ctx->vsp=spsave;
  return(result);}

pointer RETFROM(ctx,arg)	/*special-form*/
register context *ctx;
pointer arg;
{ pointer name,result;
 struct blockframe *blkfp_old, *blkfp_new; 
#ifdef SPEC_DEBUG
  printf( "RETFROM:" ); hoge_print(arg);
#endif
  GC_POINT;
  name=carof(arg,E_MISMATCHARG); arg=ccdr(arg);
  blkfp_old = ctx->blkfp;
  while (ctx->blkfp!=NULL) 
    if (ctx->blkfp->kind==BLOCKFRAME && ctx->blkfp->name==name) {
      blkfp_new = ctx->blkfp;
      ctx->blkfp = blkfp_old;
      if (islist(arg)) result=eval(ctx,ccar(arg)); else result=NIL;
      if (result==makeint(0)) result=(pointer)1;
      ctx->blkfp = blkfp_new;
      unwind(ctx,(pointer *)ctx->blkfp);
      euslongjmp(*ctx->blkfp->jbp,result);}
    else ctx->blkfp=ctx->blkfp->lexklink;
  error(E_NOBLOCK);}
  
pointer RETURN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer result=NIL;
  if (n==1) result=argv[0];
  if (n>1) error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "RETURN:" ); hoge_print(result);
#endif
  return(cons(ctx,QRETFROM,cons(ctx,NIL,cons(ctx,result,NIL))));}

pointer UNWINDPROTECT(ctx,arg)
register context *ctx;
pointer arg;
{ pointer *spsave=ctx->vsp;
  struct protectframe *oldprotfp=ctx->protfp;
  pointer protform,cleanupform,cleaner,result;

  if (!islist(arg)) error(E_NOLIST);
#ifdef SPEC_DEBUG
  printf( "UNWINDPROTECT:" );	hoge_print(arg);
#endif
  GC_POINT;
  protform=ccar(arg);
  if (islist(arg)) cleanupform=ccdr(arg); else cleanupform=NIL;
  cleaner=cons(ctx,NIL,cleanupform);
  cleaner=cons(ctx,makeint(hide_ptr((pointer)(ctx->fletfp))),cleaner);
  cleaner=cons(ctx,makeint(hide_ptr((pointer)(ctx->bindfp))),cleaner);
  cleaner=cons(ctx,NIL,cleaner);
  cleaner=cons(ctx,LAMCLOSURE,cleaner);
  /*(LAMDA-CLOSURE bindfp fletfp () . body) */
  /*bug...blocks and special variable bindings are not saved*/
  vpush(ctx->protfp); vpush(cleaner);
  ctx->protfp=(struct protectframe *)spsave;
  GC_POINT;
  result=eval(ctx,protform);
  ctx->vsp=spsave;
  ctx->protfp=oldprotfp;
  progn(ctx,cleanupform);
  return(result);
}

pointer TAGBODY(ctx,arg)
register context *ctx;
pointer arg;
{ pointer p,golist=NIL,forms;
  jmp_buf tagjmp;
  struct blockframe *tagblock;
  pointer *spsave=ctx->vsp, *tagspsave;
  struct bindframe *bfpsave=ctx->bindfp;
#ifdef SPEC_DEBUG
  printf( "TAGBODY:" ); hoge_print(arg);
#endif
  GC_POINT;
  p=forms=arg;
  while (iscons(p)) {
    if (!iscons(ccar(p))) golist=cons(ctx,p,golist);
    p=ccdr(p);}
  tagblock=(struct blockframe *)
	makeblock(ctx,TAGBODYFRAME,golist,&tagjmp,ctx->blkfp); /* ???? */
  tagspsave=ctx->vsp;
repeat:
  if ((p=(pointer)eussetjmp(tagjmp))==0) 
    {
    ctx->vsp=tagspsave;
    ctx->bindfp=bfpsave;
    while (iscons(forms)) {
      GC_POINT;
      p=ccar(forms);
      if (iscons(p)) eval(ctx,p);
      forms=ccdr(forms);} }
  else { forms=ccdr(p); goto repeat;}
  ctx->blkfp=tagblock->dynklink;
  ctx->vsp=spsave;
  return(NIL);}

pointer GO(ctx,arg)
register context *ctx;
pointer arg;
{ pointer tag,body;
#ifdef SPEC_DEBUG
  printf( "GO:" ); hoge_print( arg );
#endif
  tag=carof(arg,"GO TAG?");
  while (ctx->blkfp!=NULL) {
    if (ctx->blkfp->kind==TAGBODYFRAME &&
	(body=(pointer)assq(tag,ctx->blkfp->name))!=NIL) {
      unwind(ctx,(pointer *)ctx->blkfp);
      euslongjmp(*(ctx->blkfp->jbp),body);}/* ???? */
      /* euslongjmp(*(ctx->blkfp->jbp),body);} *//* ??? eus_rbar */
    ctx->blkfp=ctx->blkfp->lexklink;}
  error(E_USER,(pointer)"go tag not found");}

pointer EVALWHEN(ctx,arg)
register context *ctx;
pointer arg;
{ pointer situation,forms;
#ifdef SPEC_DEBUG
  printf( "EVALWHEN:" ); hoge_print( arg );
#endif
  situation=carof(arg,E_MISMATCHARG); forms=ccdr(arg);
  while (islist(situation)) 
    if (ccar(situation)==QEVAL) return(progn(ctx,forms));
    else situation=ccdr(situation);
  return(NIL);}

pointer THE(ctx,arg)
register context *ctx;
pointer arg;
{ pointer typeid,form,result;
#ifdef SPEC_DEBUG
  printf( "THE:" ); hoge_print( arg );
#endif
  typeid=carof(arg,E_MISMATCHARG); arg=ccdr(arg);
  form=carof(arg,E_MISMATCHARG);
  if (islist(ccdr(arg))) error(E_MISMATCHARG);
  GC_POINT;
  result=eval(ctx,form);
  if (typeid==QINTEGER || typeid==QFIXNUM)
    if (!isint(result)) error(E_NOINT);
    else return(result);
  else if (typeid==QFLOAT)
    if (!isflt(result)) error(E_NONUMBER);
    else return(result);
  else if (typeid==QNUMBER)
    if (!isnum(result)) error(E_NONUMBER);
    else return(result);
  else {
    if (isnum(result)) error(E_NOOBJECT);
    if (speval(typeid)!=classof(result)) error(E_TYPEMISMATCH);
    else return(result);} }

pointer AND(ctx,arg)	/*special form (should be macro)*/
register context *ctx;
register pointer arg;
{ register pointer r;
#ifdef SPEC_DEBUG
  printf( "AND:" ); hoge_print( arg );
#endif
  while (islist(arg)) {
    GC_POINT;
    if ((r=eval(ctx,ccar(arg)))==NIL) return(r);
    arg=ccdr(arg); }
  return(r);}

pointer OR(ctx,arg)	/*special form (should be macro)*/
register context *ctx;
register pointer arg;
{ register pointer r;
#ifdef SPEC_DEBUG
  printf( "OR:" );	hoge_print( arg );
#endif
  while (islist(arg)) {
    GC_POINT;
    if ((r=eval(ctx,ccar(arg)))!=NIL) return(r);
    arg=ccdr(arg);    }
  return(NIL);}

pointer PROCLAIM(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer decl,var,curval;
  int i=0,vt;
#ifdef SPEC_DEBUG
  printf( "PROCLAIM:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );}
  printf( "\n" );
#endif
  GC_POINT;
  while (i<n) {
    decl=argv[i++];
    if (!islist(decl)) error(E_DECLFORM);
    if (ccar(decl)==QSPECIAL) {
      decl=ccdr(decl);
      while (islist(decl)) {
        var=ccar(decl); decl=ccdr(decl);
        if (!issymbol(var)) error(E_NOSYMBOL);
        if (var->c.sym.vtype==V_CONSTANT) error(E_SETCONST);
	else if (var->c.sym.vtype>=V_SPECIAL) {
	  if (debug)
	     fprintf(stderr, "%s has already been declared as special\n",
			var->c.sym.pname->c.str.chars);}
        else {
	  /*first time to change to a special var*/
	  curval=speval(var);
          var->c.sym.vtype=makeint(special_index());
	  vt=intval(var->c.sym.vtype);
          ctx->specials->c.vec.v[vt]=curval;}
	/*V_SPECIAL*/}
      } } 
  return(NIL);}

pointer DECLARE(arg)
pointer arg;
{ error(E_DECLARE); }		/*just ignore when interpretting*/

/****************************************************************/
/* package
/****************************************************************/
pointer ALLPACKAGES(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(0);
#ifdef SPEC_DEBUG
  printf( "ALLPACKAGES:\n" );
#endif
 return(pkglist);}

pointer FINDPACKAGE(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ pointer pkg;
  ckarg(1);
#ifdef SPEC_DEBUG
  printf( "FINDPACKAGE:" ); hoge_print( argv[0] );
#endif
  pkg=findpkg(argv[0]);
  if (pkg) return(pkg); else return(NIL);}

pointer MAKEPACKAGE(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer pkg,name,nick,use;
  int i=0;
  ckarg2(1,3);
#ifdef SPEC_DEBUG
  printf( "MAKEPACKAGE:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
#endif
  name=argv[0];
  if (n>1) nick=argv[1]; else nick=NIL;
  if (n>2) use=argv[2]; else use=NIL;
  pkg=makepkg(ctx,name,nick,use);	/*pkg is protected from gc in pkglist*/
  return(pkg);}

eusinteger_t sxhash(x)
pointer x;
{ 
  eusinteger_t h=0;
  int s,i;
  numunion nu;

  if (isstring(x)) return(rehash(x));
  else if (issymbol(x)) return(rehash(x->c.sym.pname));
  else if (isint(x)) return(intval(x));
  else if (isflt(x)) {
    nu.fval=fltval(x);  return(nu.ival);}
  else if (islist(x)) {
    while (islist(x)) { h += sxhash(ccar(x)); x=ccdr(x);}}
  else if (isvector(x)) {
    s=vecsize(x);
    switch( elmtypeof(x)) {
      case ELM_BIT:  s /= 8*sizeof(pointer); break;
      case ELM_CHAR:
      case ELM_BYTE: s /= sizeof(pointer); break;
      case ELM_POINTER: 
        for (i=0; i<s; i++) h += sxhash(x->c.vec.v[i]);
	return(h);}
    for (i=0; i<s; i++) h += x->c.ivec.iv[i]; } 
  else {  h=(eusinteger_t)x >> 2;}
  return(h);}  


pointer SXHASH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer h;
  eusinteger_t m;
  if (n==1) m=(eusinteger_t)1  << (WORD_SIZE-3);
  else if (n==2) m=ckintval(argv[1]);
  else error(E_MISMATCHARG);
#ifdef SPEC_DEBUG
  printf( "SXHASH:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  m=(sxhash(argv[0]) & MAXPOSFIXNUM) % m;
  return(makeint(m));}

/****************************************************************/
/* symbol attributes
/****************************************************************/
pointer SYMVALUE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer sy=argv[0],val;
  ckarg(1);
  if (!issymbol(sy)) error(E_NOSYMBOL);
  val=speval(sy);
  if (val==UNBOUND) error(E_UNBOUND,sy);
#ifdef SPEC_DEBUG
  printf( "SYMVALUE:" );
  { int i;
    for( i =0; i < n; i++ )
      hoge_print_sub(argv[i] );
}
  printf( "\n" );
#endif
  return(val);}

pointer SYMBNDVALUE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer sy=argv[0],val;
  ckarg(1);
  if (!issymbol(sy)) error(E_NOSYMBOL);
  val=SPEVALOF(sy);
  if (val==UNBOUND) error(E_UNBOUND,sy);
  return(val);}

pointer SETFUNC(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ if (n!=2) error(E_MISMATCHARG);
  if (!issymbol(argv[0])) error(E_NOSYMBOL);
#ifdef SPEC_DEBUG
  printf( "SETFUNC:" ); hoge_print_sub(argv[0]); hoge_print(argv[1]);
#endif
  setfunc(argv[0],argv[1]);
  return(argv[1]);}

pointer SYMFUNC(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(1);
  if (!issymbol(argv[0])) error(E_NOSYMBOL);
#ifdef SPEC_DEBUG
  printf( "SYMFUNC:" ); hoge_print( argv[0] );
#endif
  return(getfunc(ctx,argv[0]));}

pointer MAKUNBOUND(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(1);
  if (!issymbol(argv[0])) error(E_NOSYMBOL);
#ifdef SPEC_DEBUG
  printf( "MAKEUNBOUND:" ); hoge_print( argv[0] );
#endif
  pointer_update(argv[0]->c.sym.speval,UNBOUND);
  return(T);}

void set_special(ctx, var, val)
context *ctx;
pointer var, val;
{ pointer vt;
  int x;
  vt=var->c.sym.vtype;
  if (vt==V_CONSTANT) error(E_SETCONST);
  else if (vt==V_VARIABLE || vt==V_GLOBAL) {pointer_update(speval(var),val);}
  else {
    x=intval(vt);
    pointer_update(ctx->specials->c.vec.v[x],val);} }

pointer SETSPECIAL(ctx,n,argv)
context *ctx;
int n;
pointer *argv;
{ pointer var, val;
  ckarg(2);
  var=argv[0]; val=argv[1];
  if (!issymbol(var)) error(E_NOSYMBOL);
#ifdef SPEC_DEBUG
  printf( "SETSPECIAL:" ); hoge_print_sub(var); hoge_print(val);
#endif
  set_special(ctx, var, val);
  return(val);}

pointer DEFUN(ctx,arg)
register context *ctx;
pointer arg;
{ pointer funcname;
  extern pointer putprop();
#ifdef SPEC_DEBUG
  printf( "DEFUN:" ); hoge_print( arg );
#endif
  funcname=carof(arg,E_MISMATCHARG);
  arg=ccdr(arg);
  if (issymbol(funcname)) {pointer_update(funcname->c.sym.spefunc,cons(ctx,LAMBDA,arg));}
  else error(E_NOSYMBOL);
  putprop(ctx,funcname,
	 (isstring(ccar(ccdr(arg))))?(ccar(ccdr(arg))):(ccar(arg)),
	 K_FUNCTION_DOCUMENTATION);
  return(funcname);}
 
pointer DEFMACRO(ctx,arg)
register context *ctx;
pointer arg;
{ pointer macname;
#ifdef SPEC_DEBUG
  printf("DEFMACRO:" ); hoge_print(arg);
#endif
  macname=carof(arg,E_MISMATCHARG);
  arg=ccdr(arg);
  if (issymbol(macname)) {pointer_update(macname->c.sym.spefunc,cons(ctx,MACRO,arg));}
  else error(E_NOSYMBOL);
  return(macname);}

pointer FINDSYMBOL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer str,sym,pkg;
  ckarg2(1,2);
  str=argv[0];
  if (n==2) {
    pkg=findpkg(argv[1]);
    if (pkg==NULL)  error(E_NOPACKAGE);}
  else pkg=Spevalof(PACKAGE);
  if (!ispackage(pkg)) error(E_NOPACKAGE);
  if (!isstring(str)) error(E_NOSTRING);
#ifdef SPEC_DEBUG
  printf( "FINDSYMBOL:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  sym=(pointer)findsymbol(str->c.str.chars,intval(str->c.str.length),
			  pkg->c.pkg.intsymvector,&n);
  if (sym) return(sym);
  else return(NIL);}

pointer INTERN(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer str,sym,pkg;
  int x;
  ckarg2(1,3);
  str=argv[0];
  if (n>=2) pkg=findpkg(argv[1]);
  else pkg=Spevalof(PACKAGE);
  if (!isstring(str)) error(E_NOSTRING);
#ifdef SPEC_DEBUG
  printf( "INTERN:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub( argv[i] );
}
  printf( "\n" );
#endif
  return((pointer)intern(ctx,(char *)str->c.str.chars, strlength(str),pkg));}

pointer gensym(ctx)
register context *ctx;
{ byte buf[64];
  sprintf((char *)buf,"%s%d",genhead->c.str.chars,genindex++);
  return(makesymbol(ctx,(char *)buf,strlen(buf),NIL));}

pointer GENSYM(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ 
#ifdef SPEC_DEBUG
    printf( "GENSYM:" );
    { int i;
      for( i =0 ; i<n; i++ )
	hoge_print_sub(argv[i] );
  }
    printf( "\n" );
#endif

    if (n==1) {
    n--;
    if (isstring(argv[0])) {
      if (intval(argv[0]->c.str.length)>50) error(E_LONGSTRING);
      genhead=argv[0];}
    else if (isint(argv[0])) genindex=intval(argv[0]);
    else error(E_NOSTRING);
    }
  ckarg(0);
  return(gensym(ctx));}

pointer GETPROP(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer p,attr=argv[1];
  ckarg2(2,3);
  if (!ispropobj(argv[0]) || !ispropobj(attr)) error(E_NOSYMBOL);
#ifdef SPEC_DEBUG
  printf( "GETPROP:" );
  { int i;
    for( i = 0; i < n; i++ )
      hoge_print_sub(argv[i] );
}
  printf( "\n" );
#endif
  p=argv[0]->c.sym.plist;
  while (iscons(p))
    if (ccar(ccar(p))==attr) return(ccdr(ccar(p)));
    else p=ccdr(p);
  if (n==3) return(argv[2]); else return(NIL);}

pointer EXPORT (ctx,n,argv)	/*further name conflict checks should be
				  performed by EusLisp*/
register context *ctx;
int n;
register pointer argv[];
{ pointer sym, pkg;
  ckarg2(1,2);
#ifdef SPEC_DEBUG
  printf( "EXPORT:" );
  { int i;
    for( i =0; i< n; i++ )
      hoge_print_sub(argv[i]);
}
  printf( "\n" );
#endif
  sym=argv[0];
  if (n==2)  pkg = findpkg(argv[1]);
  else pkg=Spevalof(PACKAGE);
  if (!ispackage(pkg)) error(E_NOPACKAGE);
  if (issymbol(sym)) export(sym,pkg);
  else if (iscons(sym)) 
    while (iscons(sym)) {
      export(ccar(sym),pkg); sym=ccdr(sym);}
  else error(E_NOSYMBOL);
  return(T);}

pointer putprop(ctx,sym,val,attr)
register context *ctx;
register pointer sym,val,attr;
{ register pointer p;
  p=sym->c.sym.plist;
  while (iscons(p))
    if (ccar(ccar(p))==attr) { pointer_update(ccdr(ccar(p)),val); return(val);}
    else p=ccdr(p);
  /* no such a property; create it */
  p=cons(ctx,attr,val);
  pointer_update(sym->c.sym.plist,cons(ctx,p,sym->c.sym.plist));
  return(val);}

pointer PUTPROP(ctx,n,argv)	/*(putprop sym val attr)*/
register context *ctx;
int n;
register pointer argv[];
{ register pointer p,pp;
  ckarg(3);
  if (!ispropobj(argv[0]) || !ispropobj(argv[2])) error(E_NOSYMBOL);
#ifdef SPEC_DEBUG
  printf( "PUTPROP:" );
  { int i;
    for( i =0 ; i < n; i++ )
      hoge_print_sub(argv[i]);
}
  printf( "\n" );
#endif
  return(putprop(ctx,argv[0],argv[1],argv[2]));}

#ifdef EVAL_DEBUG
pointer EVALDEBUG(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{
    ckarg2(0,1);
    if( n == 1 ) {
	evaldebug = ( argv[0] != NIL );
    }
    return evaldebug ? T : NIL;
}
#endif



/****************************************************************/
/* initialize
/****************************************************************/
void specials(ctx,mod)
register context *ctx;
pointer mod;
{
  genindex=0;
  genhead=makestring("G",1);
  sysobj=cons(ctx,genhead,sysobj);

  QUOTE=defspecial(ctx,"QUOTE",mod,quote);
  QEVAL=defun(ctx,"EVAL",mod,EVAL,NULL);
  defun(ctx,"APPLY",mod,APPLY,NULL);
  defun(ctx,"FUNCALL",mod,FUNCALL,NULL);
  QPROGN=defspecial(ctx,"PROGN",mod,progn);
  defun(ctx,"PROG1",mod,PROG1,NULL);
  FUNCTION=defspecial(ctx,"FUNCTION",mod,FUNCTION_CLOSURE);
  defun(ctx,"MAPC",mod,MAPC,NULL);
  defun(ctx,"MAPCAR",mod,MAPCAR,NULL);
  defun(ctx,"MAPCAN",mod,MAPCAN,NULL);
  defspecial(ctx,"SETQ",mod,SETQ);
  QIF=defspecial(ctx,"IF",mod,IF);
  defmacro(ctx,"WHEN",mod,WHEN);
  defspecial(ctx,"COND",mod,COND);
  defspecial(ctx,"WHILE",mod,WHILE);
  defspecial(ctx,"LET",mod,PARLET);
  defspecial(ctx,"LET*",mod,SEQLET);
  defspecial(ctx,"UNWIND-PROTECT",mod,UNWINDPROTECT);
  defspecial(ctx,"CATCH",mod,CATCH);
  defspecial(ctx,"THROW",mod,THROW);
  defspecial(ctx,"FLET",mod,FLET);
  defspecial(ctx,"LABELS",mod,LABELS);
  defspecial(ctx,"BLOCK",mod,BLOCK);
  QRETFROM=defspecial(ctx,"RETURN-FROM",mod,RETFROM);
  defmacro(ctx,"RETURN",mod,RETURN);
  defspecial(ctx,"TAGBODY",mod,TAGBODY);
  defspecial(ctx,"GO",mod,GO);
  defun(ctx,"RESET",mod,RESET,NULL);
  defun(ctx,"EVALHOOK",mod,EVALHOOK,NULL);
  defun(ctx,"MACROEXPAND2",mod,MACEXPAND2,NULL);
  defspecial(ctx,"EVAL-WHEN",mod,EVALWHEN);
  defspecial(ctx,"THE",mod,THE);
  QAND=defspecial(ctx,"AND",mod,AND);
  QOR=defspecial(ctx,"OR",mod,OR);
  defun(ctx,"PROCLAIM",mod,PROCLAIM,NULL);
  defspecial(ctx,"DECLARE",mod,DECLARE);
  defun(ctx,"SETFUNC",mod,SETFUNC,NULL);
  defun(ctx,"SYMBOL-VALUE",mod,SYMVALUE,NULL);
  defun(ctx,"SYMBOL-BOUND-VALUE",mod,SYMBNDVALUE,NULL);
  defun(ctx,"SYMBOL-FUNCTION",mod,SYMFUNC,NULL);
  defun(ctx,"MAKUNBOUND",mod,MAKUNBOUND,NULL);
  defun(ctx,"SET",mod,SETSPECIAL,NULL);
  defspecial(ctx,"DEFUN",mod,DEFUN);
  defspecial(ctx,"DEFMACRO",mod,DEFMACRO);
  defun(ctx,"FIND-SYMBOL",mod,FINDSYMBOL,NULL);
  defun(ctx,"INTERN",mod,INTERN,NULL);
  defun(ctx,"GENSYM",mod,GENSYM,NULL);
  defun(ctx,"LIST-ALL-PACKAGES",mod,ALLPACKAGES,NULL);
  defun(ctx,"FIND-PACKAGE",mod,FINDPACKAGE,NULL);
  defunpkg(ctx,"MAKEPACKAGE",mod,MAKEPACKAGE,syspkg);
/*  defun(ctx,"IN-PACKAGE",mod,INPACKAGE,NULL); */
  defun(ctx,"SXHASH",mod,SXHASH,NULL);
  defun(ctx,"GET",mod,GETPROP,NULL);
  defun(ctx,"EXPORT",mod,EXPORT,NULL);
  defun(ctx,"PUTPROP",mod,PUTPROP,NULL);

#ifdef EVAL_DEBUG
  defun(ctx,"EVALDEBUG",mod,EVALDEBUG,NULL);
#endif
  }


