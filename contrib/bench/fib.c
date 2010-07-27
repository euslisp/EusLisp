/* fib.c :  entry=fib */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "fib.h"
#pragma init (register_fib)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___fib();
extern pointer build_quote_vector();
static register_fib()
  { add_module_initializer("___fib", ___fib);}

static pointer F58();
static pointer F59();
static pointer F60();
static pointer F61();
static pointer F62();

/*fib*/
static pointer F58(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF64;
	local[0]= argv[0];
	goto IF65;
IF64:
	local[0]= (pointer)((integer_t)(argv[0])-4);
	ctx->vsp=local+1;
	w=(pointer)F58(ctx,1,local+0); /*fib*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F58(ctx,1,local+1); /*fib*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
IF65:
	w = local[0];
	local[0]= w;
BLK63:
	ctx->vsp=local; return(local[0]);}

/*ifib*/
static pointer F59(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = makeint(2);
	if ((integer_t)local[0] >= (integer_t)w) goto IF67;
	local[0]= argv[0];
	goto IF68;
IF67:
	local[0]= (pointer)((integer_t)(argv[0])-4);
	ctx->vsp=local+1;
	w=(pointer)F59(ctx,1,local+0); /*ifib*/
	local[0]= w;
	local[1]= argv[0];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1]= (pointer)((integer_t)local[1] - (integer_t)w);
	ctx->vsp=local+2;
	w=(pointer)F59(ctx,1,local+1); /*ifib*/
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] + (integer_t)w);
IF68:
	w = local[0];
	local[0]= w;
BLK66:
	ctx->vsp=local; return(local[0]);}

/*ffib*/
static pointer F60(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = makeint(2);
	if ((integer_t)local[0] >= (integer_t)w) goto IF70;
	local[0]= argv[0];
	goto IF71;
IF70:
	local[0]= (pointer)((integer_t)(argv[0])-4);
	ctx->vsp=local+1;
	w=(pointer)F60(ctx,1,local+0); /*ffib*/
	local[0]= w;
	local[1]= argv[0];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1]= (pointer)((integer_t)local[1] - (integer_t)w);
	ctx->vsp=local+2;
	w=(pointer)F60(ctx,1,local+1); /*ffib*/
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] + (integer_t)w);
IF71:
	w = local[0];
	local[0]= w;
BLK69:
	ctx->vsp=local; return(local[0]);}

/*xfib*/
static pointer F61(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)((integer_t)(argv[2])+4);
	local[1]= fqv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,3,local+0,&ftab[0],fqv[1]); /*make-array*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(0);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint(1);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= makeint(2);
TAG75:
	local[2]= local[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF76;
	w = NIL;
	ctx->vsp=local+2;
	local[1]=w;
	goto BLK74;
	goto IF77;
IF76:
	local[2]= NIL;
IF77:
	local[2]= local[0];
	local[3]= local[1];
	local[4]= local[0];
	local[5]= (pointer)((integer_t)(local[1])-4);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= (pointer)((integer_t)(local[1])+4);
	local[1] = local[2];
	w = NIL;
	ctx->vsp=local+2;
	goto TAG75;
	w = NIL;
	local[1]= w;
BLK74:
	w = local[0];
	local[0]= w;
BLK72:
	ctx->vsp=local; return(local[0]);}

/*etafib*/
static pointer F62(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF80;
	local[0]= argv[0];
	goto IF81;
IF80:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[2]); /*sub1*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F62(ctx,1,local+0); /*etafib*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F62(ctx,1,local+1); /*etafib*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
IF81:
	w = local[0];
	local[0]= w;
BLK79:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___fib(ctx,n,argv,env)
register context *ctx; int n; pointer *argv; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;
  module=argv[0];
  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();
	ctx->vsp=local+0;
	compfun(ctx,fqv[3],module,F58,fqv[4]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[5],module,F59,fqv[6]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[7],module,F60,fqv[8]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[9],module,F61,fqv[10]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[11],module,F62,fqv[12]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<2; i++) ftab[i]=fcallx;
}
