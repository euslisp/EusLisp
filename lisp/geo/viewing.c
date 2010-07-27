/* viewing.c :  entry=viewing */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "viewing.h"
#pragma init (register_viewing)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewing();
extern pointer build_quote_vector();
static register_viewing()
  { add_module_initializer("___viewing", ___viewing);}


/*:update*/
static pointer M3366(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,2,local+0); /*transpose*/
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint(3)!=local[0]) goto IF3368;
	local[0]= fqv[2];
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto IF3369;
IF3368:
	local[0]= NIL;
IF3369:
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[8]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK3367:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M3370(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3371:
	ctx->vsp=local; return(local[0]);}

/*:viewpoint*/
static pointer M3372(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3373:
	ctx->vsp=local; return(local[0]);}

/*:view-direction*/
static pointer M3374(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3375:
	ctx->vsp=local; return(local[0]);}

/*:view-up*/
static pointer M3376(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3377:
	ctx->vsp=local; return(local[0]);}

/*:view-right*/
static pointer M3378(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3379:
	ctx->vsp=local; return(local[0]);}

/*:sendviewcoords*/
static pointer M3380(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK3381:
	ctx->vsp=local; return(local[0]);}

/*:look*/
static pointer M3382(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3385;}
	local[0]= fqv[8];
ENT3385:
ENT3384:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[9];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,3,local+1); /*send-message*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ATAN(ctx,2,local+3); /*atan*/
	local[3]= makeflt(-(fltval(w)));
	local[4]= fqv[11];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ATAN(ctx,2,local+3); /*atan*/
	local[3]= w;
	{ double x,y;
		y=fltval(makeflt(3.14159203e+00)); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[3]= makeflt(-(fltval(local[3])));
	local[4]= fqv[13];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= makeflt(-(fltval(makeflt(3.14159203e+00))));
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= fqv[11];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[14];
	local[4]= argv[2];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK3383:
	ctx->vsp=local; return(local[0]);}

/*:makeviewcoords*/
static pointer M3386(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[15];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= makeflt(1.57079601e+00);
	local[3]= fqv[11];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= makeflt(1.57079601e+00);
	local[3]= fqv[16];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[2];
	local[3]= fqv[11];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[3];
	local[3]= fqv[13];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[4];
	local[3]= fqv[16];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[14];
	local[2]= argv[5];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3387:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3388(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3390:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[17], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3391;
	local[1] = makeint(3);
KEY3391:
	if (n & (1<<1)) goto KEY3392;
	local[2] = NIL;
KEY3392:
	if (n & (1<<2)) goto KEY3393;
	local[3] = NIL;
KEY3393:
	if (n & (1<<3)) goto KEY3394;
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= makeflt(1.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[4] = w;
KEY3394:
	if (n & (1<<4)) goto KEY3395;
	local[5] = NIL;
KEY3395:
	local[6]= (pointer)get_sym_func(fqv[18]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[0]));
	local[9]= fqv[9];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	local[6]= fqv[19];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,2,local+6,&ftab[1],fqv[20]); /*coords*/
	argv[0]->c.obj.iv[8] = w;
	if (local[2]!=NIL) goto OR3398;
	if (local[3]!=NIL) goto OR3398;
	goto IF3396;
OR3398:
	if (local[3]!=NIL) goto IF3399;
	local[6]= local[2];
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[3] = w;
	local[6]= local[3];
	goto IF3400;
IF3399:
	local[6]= NIL;
IF3400:
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[3] = w;
	if (local[5]!=NIL) goto IF3401;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[5] = w;
	local[6]= local[5];
	goto IF3402;
IF3401:
	local[6]= NIL;
IF3402:
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[5] = w;
	local[6]= local[5];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[4] = w;
	local[6]= makeflt(-1.00000000e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[3] = w;
	local[6]= loadglobal(fqv[21]);
	local[7]= local[5];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)CONCATENATE(ctx,4,local+6); /*concatenate*/
	local[6]= w;
	local[7]= w;
	w = argv[0]->c.obj.iv[1];
	w->c.obj.iv[1] = local[7];
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,2,local+6); /*transpose*/
	local[6]= w;
	goto IF3397;
IF3396:
	local[6]= NIL;
IF3397:
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK3389:
	ctx->vsp=local; return(local[0]);}

/*:projection*/
static pointer M3403(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3404:
	ctx->vsp=local; return(local[0]);}

/*:newprojection*/
static pointer M3405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[13] = argv[2];
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3406:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3407(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3408:
	ctx->vsp=local; return(local[0]);}

/*:project3*/
static pointer M3409(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[22]); /*homogenize*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3410:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3411(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[24];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3412:
	ctx->vsp=local; return(local[0]);}

/*:screen*/
static pointer M3413(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3417;}
	local[0]= NIL;
ENT3417:
	if (n>=4) { local[1]=(argv[3]); goto ENT3416;}
	local[1]= local[0];
ENT3416:
ENT3415:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3418;
	argv[0]->c.obj.iv[9] = local[0];
	argv[0]->c.obj.iv[10] = local[1];
	local[2]= argv[0];
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF3419;
IF3418:
	local[2]= NIL;
IF3419:
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK3414:
	ctx->vsp=local; return(local[0]);}

/*:hither*/
static pointer M3420(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3423;}
	local[0]= NIL;
ENT3423:
ENT3422:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3424;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[11] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3425;
IF3424:
	local[1]= NIL;
IF3425:
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK3421:
	ctx->vsp=local; return(local[0]);}

/*:yon*/
static pointer M3426(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3429;}
	local[0]= NIL;
ENT3429:
ENT3428:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3430;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[12] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3431;
IF3430:
	local[1]= NIL;
IF3431:
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK3427:
	ctx->vsp=local; return(local[0]);}

/*:aspect*/
static pointer M3432(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3435;}
	local[0]= NIL;
ENT3435:
ENT3434:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3436;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3437;
IF3436:
	local[1]= NIL;
IF3437:
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK3433:
	ctx->vsp=local; return(local[0]);}

/*:viewreference*/
static pointer M3438(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[11];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[12]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= makeflt(2.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3439:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3440(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3442:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK3441:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3443(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3445:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[27], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3446;
	local[1] = makeflt(1.00000000e+02);
KEY3446:
	if (n & (1<<1)) goto KEY3447;
	local[2] = makeflt(1.00000000e+04);
KEY3447:
	if (n & (1<<2)) goto KEY3448;
	local[3] = makeflt(1.00000000e+00);
KEY3448:
	if (n & (1<<3)) goto KEY3449;
	local[4] = makeflt(1.00000000e+02);
KEY3449:
	if (n & (1<<4)) goto KEY3450;
	local[5] = local[4];
KEY3450:
	if (n & (1<<5)) goto KEY3451;
	local[7]= local[3];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[6] = w;
KEY3451:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[11] = w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[12] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[9] = w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[10] = w;
	local[7]= (pointer)get_sym_func(fqv[18]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[0]));
	local[10]= fqv[9];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,5,local+7); /*apply*/
	local[7]= argv[0];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK3444:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3452(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3453:
	ctx->vsp=local; return(local[0]);}

/*:project2*/
static pointer M3454(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[22]); /*homogenize*/
	local[0]= w;
BLK3455:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3456(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[24];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3457:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3458(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(2);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[29]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeflt(2.00000000e+00);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(1);
	local[2]= makeint(1);
	local[3]= makeflt(2.00000000e+00);
	local[4]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3459:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3460(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3462:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[30], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3463;
	local[1] = makeflt(1.00000000e+00);
KEY3463:
	if (n & (1<<1)) goto KEY3464;
	local[2] = local[1];
KEY3464:
	if (n & (1<<2)) goto KEY3465;
	local[3] = local[2];
KEY3465:
	local[4]= (pointer)get_sym_func(fqv[18]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[0]));
	local[7]= fqv[9];
	local[8]= fqv[19];
	local[9]= makeint(2);
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[10] = local[3];
	local[4]= argv[0];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK3461:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3466(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(4);
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[29]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeflt(1.00000000e+00);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(1);
	local[2]= makeint(1);
	local[3]= makeflt(1.00000000e+00);
	local[4]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(2);
	local[2]= makeint(2);
	local[3]= makeflt(1.00000000e+00);
	local[4]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(2);
	local[2]= makeint(3);
	local[3]= argv[0]->c.obj.iv[11];
	local[4]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(3);
	local[2]= makeint(3);
	local[3]= makeflt(1.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	w = argv[0];
	local[0]= w;
BLK3467:
	ctx->vsp=local; return(local[0]);}

/*:ray*/
static pointer M3470(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[0]->c.obj.iv[9];
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[10];
	{ double x,y;
		y=fltval(argv[3]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= makeflt(-(fltval(argv[0]->c.obj.iv[14])));
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK3471:
	ctx->vsp=local; return(local[0]);}

/*:view-plane*/
static pointer M3472(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3475;}
	local[0]= makeflt(0.00000000e+00);
ENT3475:
ENT3474:
	if (n>3) maerror();
	local[1]= fqv[31];
	local[2]= argv[0];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[33];
	local[4]= argv[0];
	local[5]= fqv[24];
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= local[0];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,4,local+1,&ftab[4],fqv[34]); /*make-plane*/
	local[0]= w;
BLK3473:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3476(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(2.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= makeflt(2.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[12]); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,1,local+5,&ftab[5],fqv[35]); /*unit-matrix*/
	local[3] = w;
	local[5]= local[3];
	local[6]= makeint(2);
	local[7]= makeint(2);
	local[8]= makeflt(2.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint(3);
	local[7]= makeint(2);
	local[8]= makeflt(1.00000000e+00);
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint(2);
	local[7]= makeint(3);
	local[8]= makeflt(-(fltval(argv[0]->c.obj.iv[14])));
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint(3);
	local[7]= makeint(3);
	local[8]= makeflt(0.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= makeint(4);
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,2,local+5,&ftab[3],fqv[29]); /*make-matrix*/
	local[4] = w;
	local[5]= local[4];
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= makeflt(1.00000000e+00);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(1);
	local[7]= makeint(1);
	local[8]= makeflt(1.00000000e+00);
	local[9]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(2);
	local[7]= makeint(2);
	local[8]= makeflt(1.00000000e+00);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(2);
	local[7]= makeint(3);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(3);
	local[7]= makeint(3);
	local[8]= makeflt(1.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,3,local+5); /*m**/
	local[0]= w;
BLK3477:
	ctx->vsp=local; return(local[0]);}

/*:viewdistance*/
static pointer M3478(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3481;}
	local[0]= NIL;
ENT3481:
ENT3480:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3482;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[14] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3483;
IF3482:
	local[1]= NIL;
IF3483:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK3479:
	ctx->vsp=local; return(local[0]);}

/*:view-angle*/
static pointer M3484(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3487;}
	local[0]= NIL;
ENT3487:
ENT3486:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3488;
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[14];
	local[3]= local[0];
	local[4]= makeflt(2.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TAN(ctx,1,local+3); /*tan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= NIL;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[1];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[3] = w;
	local[4]= argv[0];
	local[5]= fqv[36];
	local[6]= local[3];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = local[0];
	local[1]= w;
	goto IF3489;
IF3488:
	local[1]= makeint(2);
	local[2]= argv[0]->c.obj.iv[9];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[9]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[10];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[10]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[3]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)SQRT(ctx,1,local+2); /*sqrt*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+4;
	w=(pointer)ATAN(ctx,2,local+2); /*atan*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
IF3489:
	w = local[1];
	local[0]= w;
BLK3485:
	ctx->vsp=local; return(local[0]);}

/*:fovy*/
static pointer M3490(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(2);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,2,local+1); /*atan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK3491:
	ctx->vsp=local; return(local[0]);}

/*:zoom*/
static pointer M3492(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3495;}
	local[0]= NIL;
ENT3495:
ENT3494:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3496;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0]->c.obj.iv[9] = w;
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3497;
IF3496:
	local[1]= NIL;
IF3497:
	local[1]= argv[0];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK3493:
	ctx->vsp=local; return(local[0]);}

/*:lookaround*/
static pointer M3498(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= makeflt(2.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[14];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,1,local+3); /*v-*/
	local[3]= w;
	local[4]= fqv[38];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= argv[2];
	local[4]= fqv[16];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= argv[3];
	local[4]= fqv[11];
	local[5]= fqv[38];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[14];
	local[3]= local[0];
	local[4]= fqv[38];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3499:
	ctx->vsp=local; return(local[0]);}

/*:look-body*/
static pointer M3500(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3502:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[39]); /*flatten*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[40]); /*bounding-box-union*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[1];
	local[6]= fqv[41];
	local[7]= makeflt(9.99999940e-02);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	local[9]= fqv[44];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= loadglobal(fqv[45]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3504,env,argv,local);
	local[9]= local[1];
	local[10]= fqv[46];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[1] = w;
	local[5]= local[1];
	local[6]= fqv[47];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORMALIZE(ctx,1,local+5); /*normalize-vector*/
	local[2] = w;
	local[5]= local[1];
	local[6]= fqv[48];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORMALIZE(ctx,1,local+5); /*normalize-vector*/
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[49]); /*acos*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[50];
	local[7]= makeflt(5.00000000e-01);
	local[8]= local[1];
	local[9]= fqv[51];
	local[10]= fqv[52];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[53];
	local[7]= makeflt(2.00000000e+00);
	local[8]= local[1];
	local[9]= fqv[51];
	local[10]= fqv[54];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK3501:
	ctx->vsp=local; return(local[0]);}

/*:look-body2*/
static pointer M3505(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3507:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[39]); /*flatten*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[40]); /*bounding-box-union*/
	local[1]= w;
	local[2]= fqv[41];
	local[3]= makeflt(9.99999940e-02);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= *(ovafptr(local[1],fqv[55]));
	local[3]= *(ovafptr(local[1],fqv[56]));
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[42];
	local[10]= argv[0];
	local[11]= fqv[43];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= makeflt(2.00000000e+00);
	local[9]= local[2];
	local[10]= makeflt(2.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ATAN(ctx,2,local+9); /*atan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[8]);
		local[8]=(makeflt(x * y));}
	local[7] = local[8];
	local[8]= local[2];
	local[9]= local[4];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,1,local+8); /*print*/
	local[8]= argv[0];
	local[9]= fqv[50];
	local[10]= makeflt(5.00000000e-01);
	local[11]= local[1];
	local[12]= fqv[51];
	local[13]= fqv[57];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[53];
	local[10]= makeflt(2.00000000e+00);
	local[11]= local[1];
	local[12]= fqv[51];
	local[13]= fqv[58];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[37];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK3506:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M3508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3511;}
	local[0]= NIL;
ENT3511:
ENT3510:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[59];
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= fqv[60];
	local[7]= argv[0];
	local[8]= fqv[37];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[61]); /*rad2deg*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK3509:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3514:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[62], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3515;
	local[1] = NIL;
KEY3515:
	if (local[1]==NIL) goto IF3516;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[14] = w;
	local[2]= argv[0]->c.obj.iv[14];
	goto IF3517;
IF3516:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF3518;
	argv[0]->c.obj.iv[14] = makeflt(1.00000000e+02);
	local[2]= argv[0]->c.obj.iv[14];
	goto IF3519;
IF3518:
	local[2]= NIL;
IF3519:
IF3517:
	if (argv[0]->c.obj.iv[13]!=NIL) goto IF3520;
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[35]); /*unit-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[2]= argv[0]->c.obj.iv[13];
	goto IF3521;
IF3520:
	local[2]= NIL;
IF3521:
	local[2]= (pointer)get_sym_func(fqv[18]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[0]));
	local[5]= fqv[9];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3513:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3504(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[8];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:view-orient*/
static pointer M3522(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3525;}
	local[0]= makeint(0);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
ENT3525:
ENT3524:
	if (n>3) maerror();
	local[1]= *(ovafptr(argv[0]->c.obj.iv[8],fqv[63]));
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= local[0];
	{ register integer_t i=intval(makeint(0));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	local[2]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[9]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= local[0];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[10]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[0]= w;
BLK3523:
	ctx->vsp=local; return(local[0]);}

/*:view-line*/
static pointer M3526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3529;}
	local[0]= fqv[64];
ENT3529:
ENT3528:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[9];
	local[4]= argv[0];
	local[5]= fqv[66];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[43];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK3527:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewing(ctx,n,argv,env)
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
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3531;
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[69],w);
	goto IF3532;
IF3531:
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3532:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3366,fqv[1],fqv[71],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3370,fqv[3],fqv[71],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3372,fqv[43],fqv[71],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3374,fqv[32],fqv[71],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3376,fqv[76],fqv[71],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3378,fqv[78],fqv[71],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3380,fqv[80],fqv[71],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3382,fqv[42],fqv[71],fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3386,fqv[83],fqv[71],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3388,fqv[9],fqv[71],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3403,fqv[86],fqv[87],fqv[88]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3405,fqv[89],fqv[87],fqv[90]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3407,fqv[91],fqv[87],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3409,fqv[23],fqv[87],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3411,fqv[94],fqv[87],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3413,fqv[36],fqv[87],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3420,fqv[50],fqv[87],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3426,fqv[53],fqv[87],fqv[98]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3432,fqv[99],fqv[87],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3438,fqv[101],fqv[87],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3440,fqv[25],fqv[87],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3443,fqv[9],fqv[87],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3452,fqv[91],fqv[105],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3454,fqv[28],fqv[105],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3456,fqv[94],fqv[105],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3458,fqv[25],fqv[105],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3460,fqv[9],fqv[105],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3466,fqv[25],fqv[111],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3470,fqv[113],fqv[114],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3472,fqv[116],fqv[114],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3476,fqv[25],fqv[114],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3478,fqv[119],fqv[114],fqv[120]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3484,fqv[37],fqv[114],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3490,fqv[122],fqv[114],fqv[123]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3492,fqv[124],fqv[114],fqv[125]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3498,fqv[126],fqv[114],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3500,fqv[128],fqv[114],fqv[129]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3505,fqv[130],fqv[114],fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3508,fqv[59],fqv[114],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3512,fqv[9],fqv[114],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3522,fqv[66],fqv[114],fqv[134]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3526,fqv[135],fqv[114],fqv[136]);
	local[0]= fqv[137];
	local[1]= fqv[138];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[139]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
