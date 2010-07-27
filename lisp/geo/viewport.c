/* viewport.c :  entry=viewport */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "viewport.h"
#pragma init (register_viewport)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewport();
extern pointer build_quote_vector();
static register_viewport()
  { add_module_initializer("___viewport", ___viewport);}

static pointer F3658();
static pointer F3659();
static pointer F3660();
static pointer F3661();
static pointer F3662();
static pointer F3663();
static pointer F3664();
static pointer F3665();
static pointer F3666();
static pointer F3667();
static pointer F3668();
static pointer F3669();

/*:xcenter*/
static pointer M3671(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3674;}
	local[0]= NIL;
ENT3674:
ENT3673:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3675;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= w;
	goto IF3676;
IF3675:
	local[1]= NIL;
IF3676:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[0]= w;
BLK3672:
	ctx->vsp=local; return(local[0]);}

/*:ycenter*/
static pointer M3677(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3680;}
	local[0]= NIL;
ENT3680:
ENT3679:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3681;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(1);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= w;
	goto IF3682;
IF3681:
	local[1]= NIL;
IF3682:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[0]= w;
BLK3678:
	ctx->vsp=local; return(local[0]);}

/*:center*/
static pointer M3683(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3687;}
	local[0]= NIL;
ENT3687:
	if (n>=4) { local[1]=(argv[3]); goto ENT3686;}
	local[1]= local[0];
ENT3686:
ENT3685:
	if (n>4) maerror();
	w = local[0];
	if (!isnum(w)) goto CON3689;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(1);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= w;
	goto CON3688;
CON3689:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3690;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[0];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(1);
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= w;
	goto CON3688;
CON3690:
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	goto CON3688;
CON3691:
	local[2]= NIL;
CON3688:
	w = local[2];
	local[0]= w;
BLK3684:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M3692(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3695;}
	local[0]= NIL;
ENT3695:
ENT3694:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3696;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= local[0];
	local[5]= makeflt(2.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= w;
	goto IF3697;
IF3696:
	local[1]= NIL;
IF3697:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK3693:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M3698(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3701;}
	local[0]= NIL;
ENT3701:
ENT3700:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3702;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(1);
	local[3]= makeint(1);
	local[4]= local[0];
	local[5]= makeflt(2.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= w;
	goto IF3703;
IF3702:
	local[1]= NIL;
IF3703:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(1);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK3699:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M3704(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3708;}
	local[0]= NIL;
ENT3708:
	if (n>=4) { local[1]=(argv[3]); goto ENT3707;}
	local[1]= local[0];
ENT3707:
ENT3706:
	if (n>4) maerror();
	w = local[0];
	if (!isnum(w)) goto CON3710;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(1);
	local[4]= makeint(1);
	local[5]= local[1];
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= w;
	goto CON3709;
CON3710:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3711;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(1);
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= w;
	goto CON3709;
CON3711:
	local[2]= makeflt(2.00000000e+00);
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= makeint(0);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(2.00000000e+00);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= makeint(1);
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,3,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	goto CON3709;
CON3712:
	local[2]= NIL;
CON3709:
	w = local[2];
	local[0]= w;
BLK3705:
	ctx->vsp=local; return(local[0]);}

/*:screen-point-to-ndc*/
static pointer M3713(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*inverse-matrix*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,3,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[0]= w;
BLK3714:
	ctx->vsp=local; return(local[0]);}

/*:ndc-width-to-screen*/
static pointer M3715(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
BLK3716:
	ctx->vsp=local; return(local[0]);}

/*:ndc-height-to-screen*/
static pointer M3717(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(1);
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
BLK3718:
	ctx->vsp=local; return(local[0]);}

/*:ndc-point-to-screen*/
static pointer M3719(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF3721;
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	goto IF3722;
IF3721:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
IF3722:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[0]= w;
BLK3720:
	ctx->vsp=local; return(local[0]);}

/*:ndc-line-to-screen*/
static pointer M3723(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3726;}
	local[0]= T;
ENT3726:
ENT3725:
	if (n>5) maerror();
	if (local[0]==NIL) goto IF3727;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[2]); /*homo-viewport-clip*/
	argv[2] = w;
	if (argv[2]!=NIL) goto IF3729;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK3724;
	goto IF3730;
IF3729:
	local[1]= NIL;
IF3730:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[3] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.car;
	local[1]= argv[2];
	goto IF3728;
IF3727:
	local[1]= NIL;
IF3728:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(3);
	if ((integer_t)local[1] <= (integer_t)w) goto IF3731;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[3]); /*homo2normal*/
	argv[2] = w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[3]); /*homo2normal*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF3732;
IF3731:
	local[1]= NIL;
IF3732:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(3);
	if ((integer_t)local[1] >= (integer_t)w) goto IF3733;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[4]); /*homogenize*/
	argv[2] = w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[4]); /*homogenize*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF3734;
IF3733:
	local[1]= NIL;
IF3734:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= loadglobal(fqv[5]);
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= loadglobal(fqv[5]);
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[3];
	local[3]= loadglobal(fqv[6]);
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= loadglobal(fqv[6]);
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= loadglobal(fqv[5]);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= loadglobal(fqv[5]);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,2,local+1); /*float-vector*/
	local[1]= w;
	local[2]= loadglobal(fqv[6]);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= loadglobal(fqv[6]);
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0]= w;
BLK3724:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3735(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3737:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[7], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3738;
	local[1] = NIL;
KEY3738:
	if (n & (1<<1)) goto KEY3739;
	local[2] = NIL;
KEY3739:
	if (n & (1<<2)) goto KEY3740;
	local[3] = NIL;
KEY3740:
	if (n & (1<<3)) goto KEY3741;
	local[4] = NIL;
KEY3741:
	if (local[3]==NIL) goto IF3742;
	local[5]= argv[0];
	local[6]= fqv[8];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3743;
IF3742:
	local[5]= NIL;
IF3743:
	if (local[4]==NIL) goto IF3744;
	local[5]= argv[0];
	local[6]= fqv[9];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3745;
IF3744:
	local[5]= NIL;
IF3745:
	if (local[1]==NIL) goto IF3746;
	local[5]= argv[0];
	local[6]= fqv[10];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3747;
IF3746:
	local[5]= NIL;
IF3747:
	if (local[2]==NIL) goto IF3748;
	local[5]= argv[0];
	local[6]= fqv[11];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3749;
IF3748:
	local[5]= NIL;
IF3749:
	local[5]= argv[0];
	local[6]= fqv[12];
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK3736:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3750(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3752:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[13], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3753;
	local[1] = makeint(3);
KEY3753:
	if (n & (1<<1)) goto KEY3754;
	local[2] = makeint(100);
KEY3754:
	if (n & (1<<2)) goto KEY3755;
	local[3] = makeint(100);
KEY3755:
	if (n & (1<<3)) goto KEY3756;
	local[4] = makeint(200);
KEY3756:
	if (n & (1<<4)) goto KEY3757;
	local[5] = makeint(200);
KEY3757:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[14]));
	local[8]= fqv[15];
	local[9]= fqv[16];
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)SENDMESSAGE(ctx,5,local+6); /*send-message*/
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[9];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[10];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[11];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[12];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK3751:
	ctx->vsp=local; return(local[0]);}

/*:viewing*/
static pointer M3758(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3760:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3761;
	local[1]= (pointer)get_sym_func(fqv[17]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3762;
IF3761:
	local[1]= argv[0]->c.obj.iv[1];
IF3762:
	w = local[1];
	local[0]= w;
BLK3759:
	ctx->vsp=local; return(local[0]);}

/*:viewsurface*/
static pointer M3763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3765:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3766;
	local[1]= (pointer)get_sym_func(fqv[17]);
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3767;
IF3766:
	local[1]= argv[0]->c.obj.iv[3];
IF3767:
	w = local[1];
	local[0]= w;
BLK3764:
	ctx->vsp=local; return(local[0]);}

/*:viewport*/
static pointer M3768(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3770:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3771;
	local[1]= (pointer)get_sym_func(fqv[17]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3772;
IF3771:
	local[1]= argv[0]->c.obj.iv[2];
IF3772:
	w = local[1];
	local[0]= w;
BLK3769:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M3773(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3774:
	ctx->vsp=local; return(local[0]);}

/*:point-to-screen*/
static pointer M3775(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[19];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[3]); /*homo2normal*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3776:
	ctx->vsp=local; return(local[0]);}

/*:draw-point-ndc*/
static pointer M3777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3780;}
	local[0]= NIL;
ENT3780:
ENT3779:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3781;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3782;
IF3781:
	local[1]= NIL;
IF3782:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3778:
	ctx->vsp=local; return(local[0]);}

/*:draw-line-ndc*/
static pointer M3783(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3787;}
	local[0]= T;
ENT3787:
	if (n>=6) { local[1]=(argv[5]); goto ENT3786;}
	local[1]= NIL;
ENT3786:
ENT3785:
	if (n>6) maerror();
	if (local[1]==NIL) goto IF3788;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[21];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3789;
IF3788:
	local[2]= NIL;
IF3789:
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[23];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	argv[2] = w;
	if (argv[2]==NIL) goto IF3790;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[24];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF3791;
IF3790:
	local[2]= NIL;
IF3791:
	w = NIL;
	local[0]= w;
BLK3784:
	ctx->vsp=local; return(local[0]);}

/*:draw-string-ndc*/
static pointer M3792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[25],w);
	if (n>=5) { local[3]=(argv[4]); goto ENT3795;}
	local[3]= NIL;
ENT3795:
ENT3794:
	if (n>5) maerror();
	if (local[3]==NIL) goto IF3796;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[21];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3797;
IF3796:
	local[4]= NIL;
IF3797:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[19];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	argv[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[26];
	local[6]= argv[2];
	local[7]= loadglobal(fqv[25]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK3793:
	ctx->vsp=local; return(local[0]);}

/*:draw-image-string-ndc*/
static pointer M3798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[25],w);
	if (n>=5) { local[3]=(argv[4]); goto ENT3801;}
	local[3]= NIL;
ENT3801:
ENT3800:
	if (n>5) maerror();
	if (local[3]==NIL) goto IF3802;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[21];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3803;
IF3802:
	local[4]= NIL;
IF3803:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[19];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	argv[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[27];
	local[6]= argv[2];
	local[7]= loadglobal(fqv[25]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK3799:
	ctx->vsp=local; return(local[0]);}

/*:draw-rectangle-ndc*/
static pointer M3804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3807;}
	local[0]= NIL;
ENT3807:
ENT3806:
	if (n>6) maerror();
	if (local[0]==NIL) goto IF3808;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3809;
IF3808:
	local[1]= NIL;
IF3809:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[28];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[29];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[30];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3805:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-rectangle-ndc*/
static pointer M3810(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3813;}
	local[0]= NIL;
ENT3813:
ENT3812:
	if (n>6) maerror();
	if (local[0]==NIL) goto IF3814;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3815;
IF3814:
	local[1]= NIL;
IF3815:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[28];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[29];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[31];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3811:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc-ndc*/
static pointer M3816(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3821;}
	local[0]= makeint(0);
ENT3821:
	if (n>=7) { local[1]=(argv[6]); goto ENT3820;}
	local[1]= makeflt(6.28318405e+00);
ENT3820:
	if (n>=8) { local[2]=(argv[7]); goto ENT3819;}
	local[2]= NIL;
ENT3819:
ENT3818:
	if (n>8) maerror();
	if (local[2]==NIL) goto IF3822;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[21];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF3823;
IF3822:
	local[3]= NIL;
IF3823:
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[19];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[2] = w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[28];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[3] = w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[29];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[4] = w;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[32];
	local[5]= argv[2];
	local[6]= argv[3];
	local[7]= argv[4];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[0]= w;
BLK3817:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc-ndc*/
static pointer M3824(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<7) maerror();
	if (n>=8) { local[0]=(argv[7]); goto ENT3827;}
	local[0]= NIL;
ENT3827:
ENT3826:
	if (n>8) maerror();
	if (local[0]==NIL) goto IF3828;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3829;
IF3828:
	local[1]= NIL;
IF3829:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[28];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[29];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[33];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= argv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK3825:
	ctx->vsp=local; return(local[0]);}

/*:draw-polyline-ndc*/
static pointer M3830(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= NIL;
WHL3833:
	if (argv[2]==NIL) goto WHX3834;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[2];
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[34];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= T;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0] = local[1];
	goto WHL3833;
WHX3834:
	local[2]= NIL;
BLK3835:
	w = local[2];
	local[0]= w;
BLK3831:
	ctx->vsp=local; return(local[0]);}

/*:draw-box-ndc*/
static pointer M3837(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	{ register integer_t i=intval(makeint(0));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
	local[1]= argv[2];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= w;
	local[2]= argv[3];
	{ register integer_t i=intval(makeint(0));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	local[2]= w;
	local[3]= argv[3];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[35];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[2];
	local[8]= local[1];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[3];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	local[9]= local[0];
	local[10]= local[3];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,5,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK3838:
	ctx->vsp=local; return(local[0]);}

/*:draw-star-ndc*/
static pointer M3839(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3842;}
	local[0]= makeflt(1.99999958e-02);
ENT3842:
ENT3841:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[34];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[34];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3840:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M3843(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3847;}
	local[0]= T;
ENT3847:
	if (n>=6) { local[1]=(argv[5]); goto ENT3846;}
	local[1]= NIL;
ENT3846:
ENT3845:
	if (n>6) maerror();
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[2] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[3] = w;
	local[2]= argv[0];
	local[3]= fqv[34];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)RECLAIM(ctx,1,local+2); /*system:reclaim*/
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)RECLAIM(ctx,1,local+2); /*system:reclaim*/
	local[0]= w;
BLK3844:
	ctx->vsp=local; return(local[0]);}

/*:draw-box*/
static pointer M3848(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3851;}
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(3.00000000e+02);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
ENT3851:
ENT3850:
	if (n>4) maerror();
	local[1]= local[0];
	local[2]= local[0];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[20];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[3]); /*homo2normal*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3849:
	ctx->vsp=local; return(local[0]);}

/*:draw-polyline*/
static pointer M3852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO3854,env,argv,local);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3853:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc*/
static pointer M3855(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3860;}
	local[0]= makeint(0);
ENT3860:
	if (n>=7) { local[1]=(argv[6]); goto ENT3859;}
	local[1]= makeflt(6.28318405e+00);
ENT3859:
	if (n>=8) { local[2]=(argv[7]); goto ENT3858;}
	local[2]= NIL;
ENT3858:
ENT3857:
	if (n>8) maerror();
	local[3]= NIL;
	local[4]= NIL;
	if (local[2]==NIL) goto IF3861;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= fqv[21];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3862;
IF3861:
	local[5]= NIL;
IF3862:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[20];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[37];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[38];
	local[7]= argv[2];
	local[8]= local[4];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= local[4];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[0]= w;
BLK3856:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc*/
static pointer M3863(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3868;}
	local[0]= makeint(0);
ENT3868:
	if (n>=7) { local[1]=(argv[6]); goto ENT3867;}
	local[1]= makeflt(6.28318405e+00);
ENT3867:
	if (n>=8) { local[2]=(argv[7]); goto ENT3866;}
	local[2]= NIL;
ENT3866:
ENT3865:
	if (n>8) maerror();
	local[3]= NIL;
	local[4]= NIL;
	if (local[2]==NIL) goto IF3869;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= fqv[21];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3870;
IF3869:
	local[5]= NIL;
IF3870:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[20];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[37];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[39];
	local[7]= argv[2];
	local[8]= local[4];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= local[4];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[0]= w;
BLK3864:
	ctx->vsp=local; return(local[0]);}

/*:draw-arrow*/
static pointer M3871(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3875;}
	local[0]= T;
ENT3875:
	if (n>=6) { local[1]=(argv[5]); goto ENT3874;}
	local[1]= NIL;
ENT3874:
ENT3873:
	if (n>6) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= fqv[20];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	argv[2] = w;
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= fqv[20];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	argv[3] = w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[3]); /*homo2normal*/
	argv[2] = w;
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[3]); /*homo2normal*/
	argv[3] = w;
	local[6]= argv[2];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[2] = w;
	local[6]= makeflt(2.99999952e-01);
	local[7]= local[2];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,3,local+6); /*scale*/
	local[6]= local[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= local[2];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[3] = w;
	local[6]= local[2];
	local[7]= makeint(2);
	local[8]= makeflt(0.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= argv[3];
	local[7]= makeflt(5.00000000e-01);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,2,local+6); /*v+*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,2,local+6); /*v+*/
	local[4] = w;
	local[6]= argv[3];
	local[7]= makeflt(-5.00000000e-01);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,2,local+6); /*v+*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,2,local+6); /*v+*/
	local[5] = w;
	local[6]= argv[0];
	local[7]= fqv[34];
	local[8]= argv[2];
	local[9]= argv[3];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,6,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[34];
	local[8]= local[4];
	local[9]= argv[3];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,6,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[34];
	local[8]= local[5];
	local[9]= argv[3];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,6,local+6); /*send*/
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[0]= w;
BLK3872:
	ctx->vsp=local; return(local[0]);}

/*:pane*/
static pointer M3876(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= fqv[40];
	local[3]= fqv[41];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3877:
	ctx->vsp=local; return(local[0]);}

/*:draw-star*/
static pointer M3878(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3881;}
	local[0]= NIL;
ENT3881:
ENT3880:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF3882;
	local[0] = makeflt(1.99999958e-02);
	local[1]= local[0];
	goto IF3883;
IF3882:
	local[1]= NIL;
IF3883:
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[20];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[3]); /*homo2normal*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3879:
	ctx->vsp=local; return(local[0]);}

/*:draw-2dlnseg*/
static pointer M3884(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	local[3]= fqv[43];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3885:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3854(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= fqv[20];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:draw-edge-image*/
static pointer M3886(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3890;}
	local[0]= NIL;
ENT3890:
	if (n>=5) { local[1]=(argv[4]); goto ENT3889;}
	local[1]= argv[2];
	local[2]= fqv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
ENT3889:
ENT3888:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL3892:
	if (local[3]==NIL) goto WHX3893;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[34];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	goto WHL3892;
WHX3893:
	local[4]= NIL;
BLK3894:
	w = NIL;
	if (local[0]==NIL) goto IF3896;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[46];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL3899:
	if (local[3]==NIL) goto WHX3900;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[34];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	goto WHL3899;
WHX3900:
	local[4]= NIL;
BLK3901:
	w = NIL;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[46];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3897;
IF3896:
	local[2]= NIL;
IF3897:
	w = local[2];
	local[0]= w;
BLK3887:
	ctx->vsp=local; return(local[0]);}

/*:draw-edge*/
static pointer M3903(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3906;}
	local[0]= NIL;
ENT3906:
ENT3905:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3907;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3908;
IF3907:
	local[1]= NIL;
IF3908:
	local[1]= argv[0];
	local[2]= fqv[24];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3904:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M3909(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3913;}
	local[0]= NIL;
ENT3913:
	if (n>=5) { local[1]=(argv[4]); goto ENT3912;}
	local[1]= NIL;
ENT3912:
ENT3911:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[48];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL3915:
	if (local[7]==NIL) goto WHX3916;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[0]==NIL) goto AND3921;
	local[8]= local[6];
	local[9]= fqv[49];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto AND3921;
	goto IF3919;
AND3921:
	if (local[1]==NIL) goto IF3922;
	local[8]= local[1];
	goto IF3923;
IF3922:
	local[8]= local[6];
	local[9]= fqv[21];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
IF3923:
	local[5] = local[8];
	local[8]= NIL;
	local[9]= local[6];
	local[10]= fqv[50];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL3925:
	if (local[9]==NIL) goto WHX3926;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	w = local[2];
	if (memq(local[10],w)!=NIL) goto IF3929;
	local[10]= argv[0];
	local[11]= fqv[51];
	local[12]= local[8];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	w = local[2];
	ctx->vsp=local+11;
	local[2] = cons(ctx,local[10],w);
	local[10]= local[2];
	goto IF3930;
IF3929:
	local[10]= NIL;
IF3930:
	goto WHL3925;
WHX3926:
	local[10]= NIL;
BLK3927:
	w = NIL;
	local[8]= w;
	goto IF3920;
IF3919:
	local[8]= NIL;
IF3920:
	goto WHL3915;
WHX3916:
	local[8]= NIL;
BLK3917:
	w = NIL;
WHL3931:
	if (local[2]==NIL) goto WHX3932;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[2] = local[4];
	goto WHL3931;
WHX3932:
	local[6]= NIL;
BLK3933:
	w = local[6];
	local[0]= w;
BLK3910:
	ctx->vsp=local; return(local[0]);}

/*:draw-body*/
static pointer M3934(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3937;}
	local[0]= T;
ENT3937:
ENT3936:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[52];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[53];
	local[3]= argv[2];
	local[4]= fqv[54];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= fqv[21];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3935:
	ctx->vsp=local; return(local[0]);}

/*:draw-axis*/
static pointer M3938(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3941;}
	local[0]= NIL;
ENT3941:
ENT3940:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF3942;
	local[0] = makeflt(1.00000000e+00);
	local[1]= local[0];
	goto IF3943;
IF3942:
	local[1]= NIL;
IF3943:
	local[1]= argv[2];
	local[2]= fqv[55];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeflt(2.99999952e-01);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[55];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= fqv[55];
	local[10]= local[0];
	local[11]= makeint(0);
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= fqv[55];
	local[10]= makeint(0);
	local[11]= local[0];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= fqv[55];
	local[10]= local[3];
	local[11]= local[2];
	local[12]= makeint(0);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= fqv[55];
	local[10]= local[3];
	local[11]= makeint(0);
	local[12]= local[2];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[0]= w;
BLK3939:
	ctx->vsp=local; return(local[0]);}

/*:draw-one*/
static pointer M3944(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[2];
	if (!isnum(w)) goto CON3947;
	local[0]= NIL;
	goto CON3946;
CON3947:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON3948;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3950;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[57];
	if (memq(local[1],w)==NIL) goto IF3952;
	local[1]= argv[0];
	local[2]= fqv[24];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF3953;
IF3952:
	local[1]= local[0];
	if (fqv[58]!=local[1]) goto IF3954;
	local[1]= argv[0];
	local[2]= fqv[34];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF3955;
IF3954:
	if (T==NIL) goto IF3956;
	local[1]= fqv[59];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF3957;
IF3956:
	local[1]= NIL;
IF3957:
IF3955:
IF3953:
	w = local[1];
	local[0]= w;
	goto CON3949;
CON3950:
	local[0]= NIL;
	local[1]= argv[2];
WHL3960:
	if (local[1]==NIL) goto WHX3961;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[60];
	local[4]= local[0];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL3960;
WHX3961:
	local[2]= NIL;
BLK3962:
	w = NIL;
	local[0]= w;
	goto CON3949;
CON3958:
	local[0]= NIL;
CON3949:
	goto CON3946;
CON3948:
	local[0]= argv[2];
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[62]); /*find-method*/
	if (w==NIL) goto CON3964;
	local[0]= argv[2];
	local[1]= fqv[61];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3964:
	local[0]= argv[2];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[62]); /*find-method*/
	if (w==NIL) goto CON3965;
	local[0]= argv[2];
	local[1]= fqv[52];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[62]); /*find-method*/
	if (w==NIL) goto IF3966;
	local[0]= argv[2];
	local[1]= fqv[52];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF3967;
IF3966:
	local[0]= NIL;
IF3967:
	local[0]= argv[0];
	local[1]= fqv[60];
	local[2]= argv[2];
	local[3]= fqv[63];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3965:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3968;
	local[0]= argv[0];
	local[1]= fqv[51];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3968:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3969;
	local[0]= argv[0];
	local[1]= fqv[66];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3969:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[67]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3970;
	local[0]= argv[2];
	local[1]= fqv[52];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[2];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[68];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
WHL3972:
	if (local[2]==NIL) goto WHX3973;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[51];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL3972;
WHX3973:
	local[3]= NIL;
BLK3974:
	w = NIL;
	local[0]= w;
	goto CON3946;
CON3970:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[69]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3976;
	local[0]= argv[2];
	local[1]= fqv[52];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[2];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[70];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL3978:
	if (local[2]==NIL) goto WHX3979;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[51];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL3978;
WHX3979:
	local[3]= NIL;
BLK3980:
	w = NIL;
	local[0]= w;
	goto CON3946;
CON3976:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[71]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3982;
	local[0]= argv[0];
	local[1]= fqv[53];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3982:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[72]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3983;
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[70];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL3985:
	if (local[1]==NIL) goto WHX3986;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[51];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL3985;
WHX3986:
	local[2]= NIL;
BLK3987:
	w = NIL;
	local[0]= w;
	goto CON3946;
CON3983:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3989;
	local[0]= argv[0];
	local[1]= fqv[73];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[3];
	goto CON3946;
CON3989:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[74]); /*coordinates-p*/
	if (w==NIL) goto CON3990;
	local[0]= argv[0];
	local[1]= fqv[75];
	local[2]= argv[2];
	local[3]= fqv[52];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3990:
	local[0]= fqv[76];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON3991;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[76]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3991;
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3991:
	local[0]= fqv[78];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON3992;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[78]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3992;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[79];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3992:
	local[0]= fqv[80];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON3993;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[80]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON3993;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[21];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3946;
CON3993:
	local[0]= NIL;
CON3946:
	w = local[0];
	local[0]= w;
BLK3945:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3994(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3997;}
	local[0]= NIL;
ENT3997:
ENT3996:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON3999;
	local[1]= NIL;
	local[2]= argv[2];
WHL4001:
	if (local[2]==NIL) goto WHX4002;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[60];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4001;
WHX4002:
	local[3]= NIL;
BLK4003:
	w = NIL;
	local[1]= w;
	goto CON3998;
CON3999:
	if (argv[2]==NIL) goto CON4005;
	local[1]= argv[0];
	local[2]= fqv[60];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON3998;
CON4005:
	local[1]= NIL;
CON3998:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = T;
	local[0]= w;
BLK3995:
	ctx->vsp=local; return(local[0]);}

/*:erase*/
static pointer M4006(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[61];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4007:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M4008(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[83];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4009:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4010(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[84], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4012;
	local[0] = NIL;
KEY4012:
	if (n & (1<<1)) goto KEY4013;
	local[1] = NIL;
KEY4013:
	if (n & (1<<2)) goto KEY4014;
	local[2] = NIL;
KEY4014:
	if (n & (1<<3)) goto KEY4015;
	local[3] = NIL;
KEY4015:
	if (n & (1<<4)) goto KEY4016;
	local[4] = NIL;
KEY4016:
	local[5]= argv[0];
	local[6]= local[4];
	local[7]= fqv[85];
	ctx->vsp=local+8;
	w=(pointer)PUTPROP(ctx,3,local+5); /*putprop*/
	argv[0]->c.obj.iv[1] = local[0];
	argv[0]->c.obj.iv[2] = local[1];
	argv[0]->c.obj.iv[3] = local[2];
	local[5]= local[3];
	storeglobal(fqv[86],local[5]);
	local[5]= argv[0];
	w = loadglobal(fqv[87]);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	storeglobal(fqv[87],local[5]);
	w = argv[0];
	local[0]= w;
BLK4011:
	ctx->vsp=local; return(local[0]);}

/*:adjust-viewport*/
static pointer M4017(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4023;}
	local[0]= NIL;
ENT4023:
	if (n>=4) { local[1]=(argv[3]); goto ENT4022;}
	local[1]= NIL;
ENT4022:
	if (n>=5) { local[2]=(argv[4]); goto ENT4021;}
	local[2]= local[0];
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
ENT4021:
	if (n>=6) { local[3]=(argv[5]); goto ENT4020;}
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
ENT4020:
ENT4019:
	if (n>6) maerror();
	if (local[0]!=NIL) goto IF4024;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[8];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[0] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	goto IF4025;
IF4024:
	local[4]= NIL;
IF4025:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[88];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[89];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[0]= w;
BLK4018:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M4026(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4029;}
	local[0]= argv[2];
ENT4029:
ENT4028:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[90];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[91];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[92];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK4027:
	ctx->vsp=local; return(local[0]);}

/*draw*/
static pointer F3658(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4031:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[93]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4032;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	goto IF4033;
IF4032:
	local[4]= loadglobal(fqv[94]);
IF4033:
	local[2] = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4035;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[95];
	local[6]= fqv[96];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4036;
IF4035:
	local[4]= NIL;
IF4036:
	local[4]= NIL;
	local[5]= local[0];
WHL4039:
	if (local[5]==NIL) goto WHX4040;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[61];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL4039;
WHX4040:
	local[6]= NIL;
BLK4041:
	w = NIL;
	w = local[3];
	if (!isint(w)) goto IF4043;
	local[4]= local[2];
	local[5]= fqv[95];
	local[6]= fqv[96];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4044;
IF4043:
	local[4]= NIL;
IF4044:
	w = local[4];
	local[0]= w;
BLK4030:
	ctx->vsp=local; return(local[0]);}

/*draw-tree*/
static pointer F3659(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4046:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
WHL4047:
	if (local[0]==NIL) goto WHX4048;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= loadglobal(fqv[69]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF4051;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F3658(ctx,1,local+3); /*draw*/
	local[3]= w;
	goto IF4052;
IF4051:
	local[3]= NIL;
IF4052:
	local[3]= local[1];
	local[4]= fqv[97];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[2];
WHL4054:
	if (local[4]==NIL) goto WHX4055;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	goto WHL4054;
WHX4055:
	local[5]= NIL;
BLK4056:
	w = NIL;
	goto WHL4047;
WHX4048:
	local[3]= NIL;
BLK4049:
	w = local[3];
	local[0]= w;
BLK4045:
	ctx->vsp=local; return(local[0]);}

/*erase*/
static pointer F3660(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4059:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[94]);
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[93]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4060;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF4061;
IF4060:
	local[4]= NIL;
IF4061:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4063;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[95];
	local[6]= fqv[96];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4064;
IF4063:
	local[4]= NIL;
IF4064:
	local[4]= local[2];
	local[5]= fqv[98];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	if (!isint(w)) goto IF4066;
	local[4]= local[2];
	local[5]= fqv[95];
	local[6]= fqv[96];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4067;
IF4066:
	local[4]= NIL;
IF4067:
	w = local[4];
	local[0]= w;
BLK4058:
	ctx->vsp=local; return(local[0]);}

/*draw-axis*/
static pointer F3661(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4069:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[94]);
	local[3]= makeflt(1.00000000e+01);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[93]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4070;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF4071;
IF4070:
	local[4]= NIL;
IF4071:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isnum(w)) goto IF4073;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[3];
	goto IF4074;
IF4073:
	local[4]= NIL;
IF4074:
	local[4]= NIL;
	local[5]= local[0];
WHL4077:
	if (local[5]==NIL) goto WHX4078;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[75];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	goto WHL4077;
WHX4078:
	local[6]= NIL;
BLK4079:
	w = NIL;
	local[4]= local[2];
	local[5]= fqv[95];
	local[6]= fqv[18];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK4068:
	ctx->vsp=local; return(local[0]);}

/*draw-arrow*/
static pointer F3662(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[94]);
	local[1]= fqv[99];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[100]);
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4081:
	ctx->vsp=local; return(local[0]);}

/*hid*/
static pointer F3663(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4083:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[94]);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= T;
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= makeflt(0.00000000e+00);
	local[9]= makeflt(0.00000000e+00);
	w = local[9];
	ctx->vsp=local+10;
	bindspecial(ctx,fqv[101],w);
	w = local[8];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[102],w);
	w = local[7];
	ctx->vsp=local+16;
	bindspecial(ctx,fqv[103],w);
	w = local[6];
	ctx->vsp=local+19;
	bindspecial(ctx,fqv[104],w);
	w = local[5];
	ctx->vsp=local+22;
	bindspecial(ctx,fqv[105],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	local[26]= loadglobal(fqv[93]);
	ctx->vsp=local+27;
	w=(pointer)DERIVEDP(ctx,2,local+25); /*derivedp*/
	if (w==NIL) goto IF4084;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[25];
	local[2] = w;
	local[25]= local[2];
	goto IF4085;
IF4084:
	local[25]= NIL;
IF4085:
	local[25]= NIL;
	local[26]= local[0];
	ctx->vsp=local+27;
	w=(*ftab[7])(ctx,1,local+26,&ftab[7],fqv[106]); /*flatten*/
	local[26]= w;
WHL4088:
	if (local[26]==NIL) goto WHX4089;
	w=local[26];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	w=local[26];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26] = (w)->c.cons.cdr;
	w = local[27];
	local[25] = w;
	local[27]= local[25];
	local[28]= fqv[63];
	ctx->vsp=local+29;
	w=(*ftab[5])(ctx,2,local+27,&ftab[5],fqv[62]); /*find-method*/
	if (w==NIL) goto IF4092;
	local[27]= local[25];
	local[28]= fqv[63];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,2,local+27); /*send*/
	local[27]= w;
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)APPEND(ctx,2,local+27); /*append*/
	local[3] = w;
	local[27]= local[3];
	goto IF4093;
IF4092:
	local[27]= local[25];
	w = local[3];
	ctx->vsp=local+28;
	local[3] = cons(ctx,local[27],w);
	local[27]= local[3];
IF4093:
	goto WHL4088;
WHX4089:
	local[27]= NIL;
BLK4090:
	w = NIL;
	local[25]= local[3];
	local[26]= local[2];
	local[27]= fqv[107];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(*ftab[8])(ctx,2,local+25,&ftab[8],fqv[108]); /*hid2*/
	local[25]= local[2];
	local[26]= fqv[61];
	local[27]= loadglobal(fqv[109]);
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	ctx->vsp=local+26;
	unbindx(ctx,5);
	w = local[25];
	local[0]= w;
BLK4082:
	ctx->vsp=local; return(local[0]);}

/*hidd*/
static pointer F3664(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4095:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[94]);
	local[3]= NIL;
	local[4]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= loadglobal(fqv[93]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF4096;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[2] = w;
	local[5]= local[2];
	goto IF4097;
IF4096:
	local[5]= NIL;
IF4097:
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[106]); /*flatten*/
	local[6]= w;
WHL4100:
	if (local[6]==NIL) goto WHX4101;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[63];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,2,local+7,&ftab[5],fqv[62]); /*find-method*/
	if (w==NIL) goto IF4104;
	local[7]= local[5];
	local[8]= fqv[63];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[3] = w;
	local[7]= local[3];
	goto IF4105;
IF4104:
	local[7]= local[5];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
IF4105:
	goto WHL4100;
WHX4101:
	local[7]= NIL;
BLK4102:
	w = NIL;
	local[5]= makeflt(0.00000000e+00);
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= makeflt(0.00000000e+00);
	w = local[8];
	ctx->vsp=local+9;
	bindspecial(ctx,fqv[101],w);
	w = local[7];
	ctx->vsp=local+12;
	bindspecial(ctx,fqv[102],w);
	w = local[6];
	ctx->vsp=local+15;
	bindspecial(ctx,fqv[103],w);
	w = local[5];
	ctx->vsp=local+18;
	bindspecial(ctx,fqv[104],w);
	local[21]= local[3];
	local[22]= local[2];
	local[23]= fqv[107];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(*ftab[8])(ctx,2,local+21,&ftab[8],fqv[108]); /*hid2*/
	local[21]= w;
	ctx->vsp=local+22;
	unbindx(ctx,4);
	w = local[21];
	local[5]= NIL;
	local[6]= loadglobal(fqv[109]);
WHL4107:
	if (local[6]==NIL) goto WHX4108;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= fqv[66];
	local[9]= local[5];
	local[10]= T;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	goto WHL4107;
WHX4108:
	local[7]= NIL;
BLK4109:
	w = NIL;
	if (loadglobal(fqv[110])==NIL) goto IF4111;
	local[5]= local[2];
	local[6]= fqv[95];
	local[7]= fqv[46];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= NIL;
	local[6]= loadglobal(fqv[111]);
WHL4114:
	if (local[6]==NIL) goto WHX4115;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	if (loadglobal(fqv[105])==NIL) goto AND4120;
	local[7]= local[5];
	local[8]= fqv[112];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (w==NIL) goto AND4120;
	goto IF4118;
AND4120:
	local[7]= local[2];
	local[8]= fqv[51];
	local[9]= local[5];
	local[10]= local[5];
	local[11]= fqv[21];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= w;
	goto IF4119;
IF4118:
	local[7]= NIL;
IF4119:
	goto WHL4114;
WHX4115:
	local[7]= NIL;
BLK4116:
	w = NIL;
	local[5]= local[2];
	local[6]= fqv[95];
	local[7]= fqv[46];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF4112;
IF4111:
	local[5]= NIL;
IF4112:
	local[5]= local[2];
	local[6]= fqv[95];
	local[7]= fqv[18];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK4094:
	ctx->vsp=local; return(local[0]);}

/*cls*/
static pointer F3665(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT4123;}
	local[0]= loadglobal(fqv[94]);
ENT4123:
ENT4122:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= fqv[95];
	local[3]= fqv[83];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[95];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK4121:
	ctx->vsp=local; return(local[0]);}

/*draw-hid*/
static pointer F3666(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT4126;}
	local[0]= loadglobal(fqv[94]);
ENT4126:
ENT4125:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
WHL4128:
	if (local[2]==NIL) goto WHX4129;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= fqv[34];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	goto WHL4128;
WHX4129:
	local[3]= NIL;
BLK4130:
	w = NIL;
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,0,local+1,&ftab[9],fqv[113]); /*xflush*/
	local[0]= w;
BLK4124:
	ctx->vsp=local; return(local[0]);}

/*draw-step*/
static pointer F3667(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4133:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[94]);
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[94],w);
	local[5]= makeint(3);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= loadglobal(fqv[93]);
	ctx->vsp=local+8;
	w=(pointer)DERIVEDP(ctx,2,local+6); /*derivedp*/
	if (w==NIL) goto IF4134;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	storeglobal(fqv[94],w);
	goto IF4135;
IF4134:
	local[6]= NIL;
IF4135:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4137;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[5] = w;
	local[6]= local[5];
	goto IF4138;
IF4137:
	local[6]= NIL;
IF4138:
	ctx->vsp=local+6;
	w = makeclosure(codevec,quotevec,UWP4140,env,argv,local);
	local[6]=(pointer)(ctx->protfp); local[7]=w;
	ctx->protfp=(struct protectframe *)(local+6);
	local[8]= NIL;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,1,local+9,&ftab[7],fqv[106]); /*flatten*/
	local[9]= w;
WHL4142:
	if (local[9]==NIL) goto WHX4143;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[95];
	local[12]= fqv[96];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[95];
	local[12]= fqv[114];
	local[13]= makeint(6);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)PRINT(ctx,1,local+10); /*print*/
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[61];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	ctx->vsp=local+10;
	w=(pointer)READCH(ctx,0,local+10); /*read-char*/
	local[10]= w;
	local[11]= local[10];
	local[12]= makeint(113);
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto IF4146;
	w = local[8];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK4132;
	goto IF4147;
IF4146:
	local[11]= NIL;
IF4147:
	w = local[11];
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[61];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[95];
	local[12]= fqv[96];
	local[13]= makeint(1);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[95];
	local[12]= fqv[114];
	local[13]= makeint(15);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[94]);
	local[11]= fqv[61];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)F3658(ctx,3,local+10); /*draw*/
	goto WHL4142;
WHX4143:
	local[10]= NIL;
BLK4144:
	w = NIL;
	ctx->vsp=local+8;
	UWP4140(ctx,0,local+8,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK4132:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP4140(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[94]);
	local[1]= fqv[95];
	local[2]= fqv[96];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[94]);
	local[1]= fqv[95];
	local[2]= fqv[114];
	local[3]= makeint(15);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-viewer*/
static pointer F3668(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4149,env,argv,local);
	local[1]= loadglobal(fqv[87]);
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[115]); /*find-if*/
	local[0]= w;
BLK4148:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4149(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[85];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[116]); /*string-equal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*view*/
static pointer F3669(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4151:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[117], &argv[0], n-0, local+1, 1);
	if (n & (1<<0)) goto KEY4152;
	local[1] = NIL;
KEY4152:
	if (n & (1<<1)) goto KEY4153;
	local[2] = NIL;
KEY4153:
	if (n & (1<<2)) goto KEY4154;
	local[3] = NIL;
KEY4154:
	if (n & (1<<3)) goto KEY4155;
	local[4] = makeint(3);
KEY4155:
	if (n & (1<<4)) goto KEY4156;
	local[5] = makeint(500);
KEY4156:
	if (n & (1<<5)) goto KEY4157;
	local[6] = local[5];
KEY4157:
	if (n & (1<<6)) goto KEY4158;
	local[7] = local[5];
KEY4158:
	if (n & (1<<7)) goto KEY4159;
	local[8] = makeint(100);
KEY4159:
	if (n & (1<<8)) goto KEY4160;
	local[9] = makeint(100);
KEY4160:
	if (n & (1<<9)) goto KEY4161;
	local[10] = fqv[118];
KEY4161:
	if (n & (1<<10)) goto KEY4162;
	local[11] = local[10];
KEY4162:
	if (n & (1<<11)) goto KEY4163;
	local[12] = NIL;
KEY4163:
	if (n & (1<<12)) goto KEY4164;
	local[13] = makeint(3);
KEY4164:
	if (n & (1<<13)) goto KEY4165;
	local[14] = NIL;
KEY4165:
	if (n & (1<<14)) goto KEY4166;
	local[28]= makeint(300);
	local[29]= makeint(200);
	local[30]= makeint(100);
	ctx->vsp=local+31;
	w=(pointer)MKFLTVEC(ctx,3,local+28); /*float-vector*/
	local[15] = w;
KEY4166:
	if (n & (1<<15)) goto KEY4167;
	local[28]= makeint(0);
	local[29]= makeint(0);
	local[30]= makeint(0);
	ctx->vsp=local+31;
	w=(pointer)MKFLTVEC(ctx,3,local+28); /*float-vector*/
	local[16] = w;
KEY4167:
	if (n & (1<<16)) goto KEY4168;
	local[17] = makeflt(5.00000000e+00);
KEY4168:
	if (n & (1<<17)) goto KEY4169;
	local[18] = makeflt(1.00000000e+02);
KEY4169:
	if (n & (1<<18)) goto KEY4170;
	local[19] = makeflt(1.00000000e+04);
KEY4170:
	if (n & (1<<19)) goto KEY4171;
	local[20] = makeflt(1.00000000e+00);
KEY4171:
	if (n & (1<<20)) goto KEY4172;
	local[21] = local[20];
KEY4172:
	if (n & (1<<21)) goto KEY4173;
	local[22] = local[20];
KEY4173:
	if (n & (1<<22)) goto KEY4174;
	local[28]= local[6];
	local[29]= makeflt(2.00000000e+00);
	ctx->vsp=local+30;
	w=(pointer)QUOTIENT(ctx,2,local+28); /*/*/
	local[23] = w;
KEY4174:
	if (n & (1<<23)) goto KEY4175;
	local[28]= local[7];
	local[29]= makeflt(2.00000000e+00);
	ctx->vsp=local+30;
	w=(pointer)QUOTIENT(ctx,2,local+28); /*/*/
	local[24] = w;
KEY4175:
	if (n & (1<<24)) goto KEY4176;
	local[25] = makeint(2);
KEY4176:
	if (n & (1<<25)) goto KEY4177;
	local[26] = makeint(0);
KEY4177:
	if (n & (1<<26)) goto KEY4178;
	local[27] = NIL;
KEY4178:
	local[28]= NIL;
	local[29]= NIL;
	local[30]= NIL;
	local[31]= NIL;
	if (local[2]==NIL) goto IF4179;
	local[28] = local[2];
	local[32]= local[28];
	goto IF4180;
IF4179:
	local[32]= (pointer)get_sym_func(fqv[119]);
	local[33]= fqv[120];
	local[34]= local[8];
	local[35]= fqv[121];
	local[36]= local[9];
	local[37]= fqv[8];
	local[38]= local[6];
	local[39]= fqv[9];
	local[40]= local[7];
	local[41]= fqv[122];
	local[42]= local[10];
	local[43]= fqv[123];
	local[44]= local[12];
	local[45]= fqv[124];
	local[46]= local[13];
	local[47]= fqv[125];
	local[48]= local[14];
	local[49]= fqv[126];
	local[50]= local[25];
	local[51]= fqv[127];
	local[52]= local[26];
	local[53]= fqv[85];
	local[54]= local[11];
	local[55]= local[0];
	ctx->vsp=local+56;
	w=(pointer)APPLY(ctx,24,local+32); /*apply*/
	local[28] = w;
	local[32]= local[28];
IF4180:
	if (local[1]==NIL) goto IF4181;
	local[29] = local[1];
	local[32]= local[29];
	goto IF4182;
IF4181:
	local[32]= loadglobal(fqv[128]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= local[32];
	local[34]= fqv[15];
	local[35]= fqv[16];
	local[36]= local[4];
	local[37]= fqv[10];
	local[38]= local[23];
	local[39]= fqv[11];
	local[40]= local[24];
	local[41]= fqv[8];
	local[42]= local[6];
	local[43]= fqv[9];
	local[44]= fqv[129];
	local[45]= loadglobal(fqv[130]);
	ctx->vsp=local+46;
	w=(*ftab[12])(ctx,2,local+44,&ftab[12],fqv[131]); /*member*/
	if (w!=NIL) goto OR4186;
	local[44]= fqv[132];
	local[45]= loadglobal(fqv[130]);
	ctx->vsp=local+46;
	w=(*ftab[12])(ctx,2,local+44,&ftab[12],fqv[131]); /*member*/
	if (w!=NIL) goto OR4186;
	goto IF4184;
OR4186:
	local[44]= local[7];
	ctx->vsp=local+45;
	w=(pointer)MINUS(ctx,1,local+44); /*-*/
	local[44]= w;
	goto IF4185;
IF4184:
	local[44]= local[7];
IF4185:
	ctx->vsp=local+45;
	w=(pointer)SEND(ctx,12,local+33); /*send*/
	w = local[32];
	local[29] = w;
	local[32]= local[29];
IF4182:
	if (local[3]==NIL) goto IF4187;
	local[32]= local[3];
	goto IF4188;
IF4187:
	local[32]= local[4];
	local[33]= makeint(2);
	ctx->vsp=local+34;
	w=(pointer)NUMEQUAL(ctx,2,local+32); /*=*/
	if (w==NIL) goto IF4189;
	local[32]= loadglobal(fqv[133]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= (pointer)get_sym_func(fqv[17]);
	local[34]= local[32];
	local[35]= fqv[15];
	local[36]= fqv[123];
	local[37]= NIL;
	local[38]= fqv[134];
	local[39]= local[15];
	local[40]= makeint(0);
	ctx->vsp=local+41;
	w=(pointer)AREF(ctx,2,local+39); /*aref*/
	local[39]= w;
	local[40]= local[15];
	local[41]= makeint(1);
	ctx->vsp=local+42;
	w=(pointer)AREF(ctx,2,local+40); /*aref*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(pointer)MKFLTVEC(ctx,2,local+39); /*float-vector*/
	local[39]= w;
	local[40]= local[0];
	ctx->vsp=local+41;
	w=(pointer)APPLY(ctx,8,local+33); /*apply*/
	w = local[32];
	local[32]= w;
	goto IF4190;
IF4189:
	local[32]= loadglobal(fqv[135]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= (pointer)get_sym_func(fqv[17]);
	local[34]= local[32];
	local[35]= fqv[15];
	local[36]= fqv[123];
	local[37]= NIL;
	local[38]= fqv[134];
	local[39]= local[15];
	local[40]= fqv[136];
	local[41]= local[16];
	local[42]= fqv[137];
	local[43]= local[17];
	local[44]= fqv[138];
	local[45]= local[18];
	local[46]= fqv[139];
	local[47]= local[19];
	local[48]= fqv[140];
	local[49]= local[21];
	local[50]= fqv[141];
	local[51]= local[22];
	local[52]= local[0];
	ctx->vsp=local+53;
	w=(pointer)APPLY(ctx,20,local+33); /*apply*/
	w = local[32];
	local[32]= w;
IF4190:
IF4188:
	local[30] = local[32];
	local[32]= local[11];
	ctx->vsp=local+33;
	w=(pointer)F3668(ctx,1,local+32); /*find-viewer*/
	local[31] = w;
	if (local[31]!=NIL) goto IF4193;
	local[32]= loadglobal(fqv[93]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[31] = w;
	local[32]= local[31];
	goto IF4194;
IF4193:
	local[32]= NIL;
IF4194:
	local[32]= fqv[142];
	ctx->vsp=local+33;
	w=(pointer)BOUNDP(ctx,1,local+32); /*boundp*/
	if (w==NIL) goto IF4195;
	w = loadglobal(fqv[142]);
	if (!isnum(w)) goto IF4195;
	if (local[27]==NIL) goto IF4195;
	local[32]= local[27];
	local[33]= loadglobal(fqv[143]);
	ctx->vsp=local+34;
	w=(pointer)DERIVEDP(ctx,2,local+32); /*derivedp*/
	if (w!=NIL) goto IF4195;
	local[32]= loadglobal(fqv[144]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= local[32];
	local[34]= fqv[145];
	local[35]= fqv[8];
	local[36]= local[6];
	local[37]= fqv[9];
	local[38]= local[7];
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,6,local+33); /*send*/
	w = local[32];
	local[27] = w;
	local[32]= local[27];
	goto IF4196;
IF4195:
	local[32]= NIL;
IF4196:
	local[32]= local[31];
	local[33]= fqv[15];
	local[34]= fqv[107];
	local[35]= local[30];
	local[36]= fqv[95];
	local[37]= local[28];
	local[38]= fqv[146];
	local[39]= local[29];
	local[40]= fqv[85];
	local[41]= local[11];
	local[42]= fqv[147];
	local[43]= local[27];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,12,local+32); /*send*/
	w = local[31];
	local[0]= w;
BLK4150:
	ctx->vsp=local; return(local[0]);}

/*with-gc*/
static pointer F4198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4200:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto CON4202;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[4]= fqv[148];
	local[5]= fqv[149];
	local[6]= fqv[145];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= fqv[17];
	local[5]= local[1];
	local[6]= fqv[150];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[3] = w;
	local[4]= local[3];
	goto CON4201;
CON4202:
	local[1] = argv[0];
	local[2] = argv[0];
	local[3] = NIL;
	local[4]= local[3];
	goto CON4201;
CON4203:
	local[4]= NIL;
CON4201:
	local[4]= fqv[151];
	local[5]= fqv[152];
	local[6]= fqv[17];
	local[7]= fqv[94];
	local[8]= fqv[95];
	local[9]= fqv[153];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[154];
	local[7]= fqv[155];
	local[8]= fqv[17];
	local[9]= fqv[94];
	local[10]= fqv[95];
	local[11]= fqv[153];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w = local[0];
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[17];
	local[9]= fqv[94];
	local[10]= fqv[95];
	local[11]= fqv[153];
	local[12]= fqv[152];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w = local[3];
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK4199:
	ctx->vsp=local; return(local[0]);}

/*with-viewsurface*/
static pointer F4204(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4206:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[151];
	local[2]= fqv[156];
	local[3]= fqv[157];
	local[4]= fqv[94];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[154];
	local[4]= fqv[155];
	local[5]= fqv[158];
	local[6]= fqv[157];
	local[7]= fqv[94];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[158];
	local[6]= fqv[157];
	local[7]= fqv[94];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[156];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK4205:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewport(ctx,n,argv,env)
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
	local[0]= fqv[159];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4207;
	local[0]= fqv[160];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[161],w);
	goto IF4208;
IF4207:
	local[0]= fqv[162];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4208:
	local[0]= fqv[94];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4209;
	local[0]= fqv[94];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[94];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4211;
	local[0]= fqv[94];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4212;
IF4211:
	local[0]= NIL;
IF4212:
	local[0]= fqv[94];
	goto IF4210;
IF4209:
	local[0]= NIL;
IF4210:
	local[0]= fqv[87];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4213;
	local[0]= fqv[87];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[87];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4215;
	local[0]= fqv[87];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4216;
IF4215:
	local[0]= NIL;
IF4216:
	local[0]= fqv[87];
	goto IF4214;
IF4213:
	local[0]= NIL;
IF4214:
	local[0]= fqv[165];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4217;
	local[0]= fqv[165];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[165];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4219;
	local[0]= fqv[165];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4220;
IF4219:
	local[0]= NIL;
IF4220:
	local[0]= fqv[165];
	goto IF4218;
IF4217:
	local[0]= NIL;
IF4218:
	local[0]= fqv[100];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4221;
	local[0]= fqv[100];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[100];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4223;
	local[0]= fqv[100];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4224;
IF4223:
	local[0]= NIL;
IF4224:
	local[0]= fqv[100];
	goto IF4222;
IF4221:
	local[0]= NIL;
IF4222:
	local[0]= fqv[166];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4225;
	local[0]= fqv[166];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[166];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4227;
	local[0]= fqv[166];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4228;
IF4227:
	local[0]= NIL;
IF4228:
	local[0]= fqv[166];
	goto IF4226;
IF4225:
	local[0]= NIL;
IF4226:
	local[0]= fqv[167];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[5];
	local[1]= fqv[164];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[6];
	local[1]= fqv[164];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[128];
	local[1]= fqv[164];
	local[2]= fqv[128];
	local[3]= fqv[168];
	local[4]= loadglobal(fqv[169]);
	local[5]= fqv[170];
	local[6]= fqv[171];
	local[7]= fqv[172];
	local[8]= NIL;
	local[9]= fqv[173];
	local[10]= NIL;
	local[11]= fqv[89];
	local[12]= makeint(-1);
	local[13]= fqv[174];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[175]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3671,fqv[10],fqv[128],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3677,fqv[11],fqv[128],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3683,fqv[88],fqv[128],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3692,fqv[8],fqv[128],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3698,fqv[9],fqv[128],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3704,fqv[89],fqv[128],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3713,fqv[182],fqv[128],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3715,fqv[28],fqv[128],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3717,fqv[29],fqv[128],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3719,fqv[19],fqv[128],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3723,fqv[23],fqv[128],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3735,fqv[90],fqv[128],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3750,fqv[15],fqv[128],fqv[189]);
	local[0]= fqv[93];
	local[1]= fqv[164];
	local[2]= fqv[93];
	local[3]= fqv[168];
	local[4]= loadglobal(fqv[190]);
	local[5]= fqv[170];
	local[6]= fqv[191];
	local[7]= fqv[172];
	local[8]= NIL;
	local[9]= fqv[173];
	local[10]= NIL;
	local[11]= fqv[89];
	local[12]= makeint(-1);
	local[13]= fqv[174];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[175]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3758,fqv[107],fqv[93],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3763,fqv[95],fqv[93],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3768,fqv[146],fqv[93],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3773,fqv[18],fqv[93],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3775,fqv[196],fqv[93],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3777,fqv[198],fqv[93],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3783,fqv[34],fqv[93],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3792,fqv[201],fqv[93],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3798,fqv[203],fqv[93],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3804,fqv[205],fqv[93],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3810,fqv[207],fqv[93],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3816,fqv[38],fqv[93],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3824,fqv[39],fqv[93],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3830,fqv[35],fqv[93],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3837,fqv[36],fqv[93],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3839,fqv[42],fqv[93],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3843,fqv[24],fqv[93],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3848,fqv[215],fqv[93],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3852,fqv[217],fqv[93],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3855,fqv[32],fqv[93],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3863,fqv[33],fqv[93],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3871,fqv[99],fqv[93],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3876,fqv[222],fqv[93],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3878,fqv[73],fqv[93],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3884,fqv[77],fqv[93],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3886,fqv[66],fqv[93],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3903,fqv[51],fqv[93],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3909,fqv[53],fqv[93],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3934,fqv[229],fqv[93],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3938,fqv[75],fqv[93],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3944,fqv[60],fqv[93],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3994,fqv[61],fqv[93],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4006,fqv[98],fqv[93],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4008,fqv[83],fqv[93],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4010,fqv[15],fqv[93],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4017,fqv[91],fqv[93],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4026,fqv[90],fqv[93],fqv[238]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[239],module,F3658,fqv[240]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[241],module,F3659,fqv[242]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[243],module,F3660,fqv[244]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[245],module,F3661,fqv[246]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[247],module,F3662,fqv[248]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[249],module,F3663,fqv[250]);
	local[0]= fqv[110];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4229;
	local[0]= fqv[110];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[110];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4231;
	local[0]= fqv[110];
	local[1]= fqv[164];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4232;
IF4231:
	local[0]= NIL;
IF4232:
	local[0]= fqv[110];
	goto IF4230;
IF4229:
	local[0]= NIL;
IF4230:
	ctx->vsp=local+0;
	compfun(ctx,fqv[251],module,F3664,fqv[252]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[253],module,F3665,fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F3666,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F3667,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F3668,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F3669,fqv[262]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[263],module,F4198,fqv[264]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[265],module,F4204,fqv[266]);
	local[0]= fqv[146];
	local[1]= fqv[267];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[268]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<15; i++) ftab[i]=fcallx;
}
