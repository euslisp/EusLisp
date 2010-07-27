/* viewsurface.c :  entry=viewsurface */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "viewsurface.h"
#pragma init (register_viewsurface)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewsurface();
extern pointer build_quote_vector();
static register_viewsurface()
  { add_module_initializer("___viewsurface", ___viewsurface);}

static pointer F3533();
static pointer F3534();
static pointer F3535();
static pointer F3536();
static pointer F3537();

/*hls2rgb*/
static pointer F3533(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3540;}
	local[0]= makeint(255);
ENT3540:
ENT3539:
	if (n>4) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET3541,env,argv,local);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	local[5]= makeflt(5.00000000e-01);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF3542;
	local[4]= argv[1];
	local[5]= makeint(1);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[3] = w;
	local[4]= local[3];
	goto IF3543;
IF3542:
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= argv[1];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,3,local+4); /*+*/
	local[3] = w;
	local[4]= local[3];
IF3543:
	local[4]= makeint(2);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,1,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[2] = w;
	local[4]= argv[2];
	local[5]= makeflt(0.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto CON3545;
	if (argv[0]!=NIL) goto IF3546;
	local[4]= argv[1];
	local[5]= argv[1];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	goto IF3547;
IF3546:
	local[4]= NIL;
IF3547:
	goto CON3544;
CON3545:
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= makeint(120);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	w = local[1];
	ctx->vsp=local+8;
	w=FLET3541(ctx,3,local+5,w);
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[3];
	local[8]= argv[0];
	w = local[1];
	ctx->vsp=local+9;
	w=FLET3541(ctx,3,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= local[0];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= makeint(120);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	w = local[1];
	ctx->vsp=local+10;
	w=FLET3541(ctx,3,local+7,w);
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	goto CON3544;
CON3548:
	local[4]= NIL;
CON3544:
	w = local[4];
	local[0]= w;
BLK3538:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET3541(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[2] = w;
	local[0]= argv[2];
	local[1]= makeint(360);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF3549;
	local[0]= argv[2];
	local[1]= makeint(360);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3550;
IF3549:
	local[0]= NIL;
IF3550:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF3551;
	local[0]= argv[2];
	local[1]= makeint(360);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3552;
IF3551:
	local[0]= NIL;
IF3552:
	local[0]= argv[2];
	local[1]= makeint(60);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[0];
	if (memq(local[1],w)==NIL) goto IF3554;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(6.00000000e+01);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	goto IF3555;
IF3554:
	local[1]= local[0];
	w = fqv[1];
	if (memq(local[1],w)==NIL) goto IF3556;
	local[1]= argv[1];
	goto IF3557;
IF3556:
	local[1]= local[0];
	w = fqv[2];
	if (memq(local[1],w)==NIL) goto IF3558;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= makeint(240);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(6.00000000e+01);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	goto IF3559;
IF3558:
	local[1]= local[0];
	w = fqv[3];
	if (memq(local[1],w)==NIL) goto IF3560;
	local[1]= argv[0];
	goto IF3561;
IF3560:
	local[1]= NIL;
IF3561:
IF3559:
IF3557:
IF3555:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*rgb2hls*/
static pointer F3534(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3564;}
	local[0]= makeflt(2.55000000e+02);
ENT3564:
ENT3563:
	if (n>4) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0] = w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[1] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[2] = w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MAX(ctx,3,local+10); /*max*/
	local[4] = w;
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MIN(ctx,3,local+10); /*min*/
	local[5] = w;
	local[10]= local[5];
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[2] = w;
	local[10]= local[2];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[10]);
	if (left >= right) goto IF3565;}
	local[10]= makeflt(0.00000000e+00);
	local[11]= makeflt(0.00000000e+00);
	local[12]= makeflt(0.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3562;
	goto IF3566;
IF3565:
	local[10]= NIL;
IF3566:
	local[10]= local[4];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
	local[9] = local[10];
	local[3] = local[9];
	local[10]= local[3];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[10]);
	if (left > right) goto IF3567;}
	local[10]= makeflt(0.00000000e+00);
	local[11]= local[2];
	local[12]= makeflt(0.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3562;
	goto IF3568;
IF3567:
	local[10]= NIL;
IF3568:
	local[10]= local[3];
	local[11]= local[2];
	{ double left,right;
		right=fltval(makeflt(5.00000000e-01)); left=fltval(local[11]);
	if (left >= right) goto IF3569;}
	local[11]= local[4];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[11]);
		local[11]=(makeflt(x + y));}
	goto IF3570;
IF3569:
	local[11]= makeflt(2.00000000e+00);
	local[12]= local[4];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[12]);
		local[12]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[12])))); x=fltval(local[11]);
		local[11]=(makeflt(x + y));}
IF3570:
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[3] = w;
	local[10]= local[4];
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[0])))); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[6] = w;
	local[10]= local[4];
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[1])))); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[7] = w;
	local[10]= local[4];
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[2])))); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[8] = w;
	local[10]= argv[0];
	if (local[4]!=local[10]) goto CON3572;
	local[10]= argv[1];
	if (local[5]!=local[10]) goto IF3573;
	local[10]= makeflt(5.00000000e+00);
	{ double x,y;
		y=fltval(local[8]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	goto IF3574;
IF3573:
	local[10]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
IF3574:
	local[1] = local[10];
	local[10]= local[1];
	goto CON3571;
CON3572:
	local[10]= argv[1];
	if (local[4]!=local[10]) goto CON3575;
	local[10]= argv[2];
	if (local[5]!=local[10]) goto IF3576;
	local[10]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(local[6]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	goto IF3577;
IF3576:
	local[10]= makeflt(3.00000000e+00);
	{ double x,y;
		y=fltval(local[8]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
IF3577:
	local[1] = local[10];
	local[10]= local[1];
	goto CON3571;
CON3575:
	local[10]= argv[0];
	if (local[5]!=local[10]) goto IF3579;
	local[10]= makeflt(3.00000000e+00);
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	goto IF3580;
IF3579:
	local[10]= makeflt(5.00000000e+00);
	{ double x,y;
		y=fltval(local[6]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
IF3580:
	local[1] = local[10];
	local[10]= local[1];
	goto CON3571;
CON3578:
	local[10]= NIL;
CON3571:
	local[10]= local[1];
	local[11]= makeflt(6.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[1] = w;
	local[10]= makeflt(3.60000000e+02);
	{ double x,y;
		y=fltval(local[1]); x=fltval(local[10]);
		local[10]=(makeflt(x * y));}
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[0]= w;
BLK3562:
	ctx->vsp=local; return(local[0]);}

/*:drawline-primitive*/
static pointer M3581(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT3584;}
	local[0]= NIL;
ENT3584:
ENT3583:
	if (n>7) maerror();
	local[1]= T;
	local[2]= fqv[4];
	local[3]= argv[2];
	local[4]= argv[5];
	local[5]= argv[4];
	local[6]= argv[5];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[0]= w;
BLK3582:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M3585(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3588;}
	local[0]= NIL;
ENT3588:
ENT3587:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= fqv[5];
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
	local[5]= argv[3];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[3];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK3586:
	ctx->vsp=local; return(local[0]);}

/*:line-style*/
static pointer M3589(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= local[0];
	if (fqv[6]!=local[1]) goto IF3592;
	local[1]= fqv[7];
	goto IF3593;
IF3592:
	local[1]= local[0];
	if (fqv[8]!=local[1]) goto IF3594;
	local[1]= fqv[9];
	goto IF3595;
IF3594:
	local[1]= NIL;
IF3595:
IF3593:
	w = local[1];
	local[0]= w;
BLK3590:
	ctx->vsp=local; return(local[0]);}

/*:line-width*/
static pointer M3596(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= T;
	local[1]= fqv[10];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK3597:
	ctx->vsp=local; return(local[0]);}

/*:nomethod*/
static pointer M3598(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3600:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[11];
	local[2]= local[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[12]); /*warn*/
	local[0]= w;
BLK3599:
	ctx->vsp=local; return(local[0]);}

/*:set-erase-mode*/
static pointer M3601(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK3602:
	ctx->vsp=local; return(local[0]);}

/*:set-show-mode*/
static pointer M3603(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK3604:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M3605(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = T;
	local[0]= w;
BLK3606:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3607(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3609:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w = argv[0];
	local[0]= w;
BLK3608:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3610(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3612:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[13], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3613;
	local[1] = makeint(0);
KEY3613:
	if (n & (1<<1)) goto KEY3614;
	local[2] = makeint(768);
KEY3614:
	if (n & (1<<2)) goto KEY3615;
	local[3] = makeint(512);
KEY3615:
	argv[0]->c.obj.iv[3] = local[1];
	argv[0]->c.obj.iv[2] = local[3];
	argv[0]->c.obj.iv[1] = local[3];
	w = argv[0];
	local[0]= w;
BLK3611:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M3616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(pointer)F3536(ctx,0,local+0); /*tektro-clear*/
	local[0]= w;
BLK3617:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M3618(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3621;}
	local[0]= NIL;
ENT3621:
ENT3620:
	if (n>3) maerror();
	w = local[0];
	if (!isnum(w)) goto IF3622;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF3623;
IF3622:
	local[1]= NIL;
IF3623:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK3619:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M3624(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3627;}
	local[0]= NIL;
ENT3627:
ENT3626:
	if (n>3) maerror();
	w = local[0];
	if (!isnum(w)) goto IF3628;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF3629;
IF3628:
	local[1]= NIL;
IF3629:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK3625:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3630(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[14];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3631:
	ctx->vsp=local; return(local[0]);}

/*:drawline-primitive*/
static pointer M3632(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT3635;}
	local[0]= NIL;
ENT3635:
ENT3634:
	if (n>7) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ROUND(ctx,1,local+1); /*round*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	local[2]= w;
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F3535(ctx,4,local+1); /*tektro-showline*/
	local[0]= w;
BLK3633:
	ctx->vsp=local; return(local[0]);}

/*tektro-showline*/
static pointer F3535(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[16])==NIL) goto IF3637;
	local[0]= T;
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
	goto IF3638;
IF3637:
	local[0]= NIL;
IF3638:
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(1);
	local[2]= makeint(32);
	local[3]= argv[1];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(2);
	local[2]= makeint(96);
	local[3]= argv[1];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(3);
	local[2]= makeint(32);
	local[3]= argv[0];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(4);
	local[2]= makeint(64);
	local[3]= argv[0];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(5);
	local[2]= makeint(32);
	local[3]= argv[3];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(6);
	local[2]= makeint(96);
	local[3]= argv[3];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(7);
	local[2]= makeint(32);
	local[3]= argv[2];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(8);
	local[2]= makeint(64);
	local[3]= argv[2];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[19]);
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	w = T;
	local[0]= w;
BLK3636:
	ctx->vsp=local; return(local[0]);}

/*tektro-clear*/
static pointer F3536(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT3641;}
	local[0]= loadglobal(fqv[19]);
ENT3641:
ENT3640:
	if (n>1) maerror();
	local[1]= makeint(27);
	local[2]= makeint(12);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)WRTBYTE(ctx,2,local+1); /*write-byte*/
	local[0]= w;
BLK3639:
	ctx->vsp=local; return(local[0]);}

/*tektro*/
static pointer F3642(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST3644:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[20];
	local[2]= fqv[19];
	local[3]= argv[0];
	local[4]= fqv[21];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK3643:
	ctx->vsp=local; return(local[0]);}

/*default-viewsurface*/
static pointer F3537(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST3646:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[23]);
	local[2]= loadglobal(fqv[24]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[25];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK3645:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewsurface(ctx,n,argv,env)
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
	local[0]= fqv[26];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3647;
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[28],w);
	goto IF3648;
IF3647:
	local[0]= fqv[29];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3648:
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F3533,fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F3534,fqv[34]);
	local[0]= fqv[35];
	local[1]= fqv[36];
	local[2]= fqv[35];
	local[3]= fqv[37];
	local[4]= loadglobal(fqv[38]);
	local[5]= fqv[39];
	local[6]= fqv[40];
	local[7]= fqv[41];
	local[8]= NIL;
	local[9]= fqv[42];
	local[10]= NIL;
	local[11]= fqv[43];
	local[12]= makeint(-1);
	local[13]= fqv[44];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[45]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3581,fqv[5],fqv[35],fqv[46]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3585,fqv[47],fqv[35],fqv[48]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3589,fqv[49],fqv[35],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3596,fqv[51],fqv[35],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3598,fqv[53],fqv[35],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3601,fqv[55],fqv[35],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3603,fqv[57],fqv[35],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3605,fqv[59],fqv[35],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3607,fqv[25],fqv[35],fqv[61]);
	local[0]= fqv[24];
	local[1]= fqv[36];
	local[2]= fqv[24];
	local[3]= fqv[37];
	local[4]= loadglobal(fqv[35]);
	local[5]= fqv[39];
	local[6]= fqv[62];
	local[7]= fqv[41];
	local[8]= NIL;
	local[9]= fqv[42];
	local[10]= NIL;
	local[11]= fqv[43];
	local[12]= makeint(-1);
	local[13]= fqv[44];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[45]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3610,fqv[25],fqv[24],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3616,fqv[64],fqv[24],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3618,fqv[14],fqv[24],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3624,fqv[15],fqv[24],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3630,fqv[68],fqv[24],fqv[69]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3632,fqv[5],fqv[24],fqv[70]);
	local[0]= fqv[18];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3649;
	local[0]= fqv[18];
	local[1]= fqv[71];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3651;
	local[0]= fqv[18];
	local[1]= fqv[36];
	local[2]= fqv[72];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3652;
IF3651:
	local[0]= NIL;
IF3652:
	local[0]= fqv[18];
	goto IF3650;
IF3649:
	local[0]= NIL;
IF3650:
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(0);
	local[2]= makeint(29);
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(9);
	local[2]= makeint(31);
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= fqv[19];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3653;
	local[0]= fqv[19];
	local[1]= fqv[71];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3655;
	local[0]= fqv[19];
	local[1]= fqv[36];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3656;
IF3655:
	local[0]= NIL;
IF3656:
	local[0]= fqv[19];
	goto IF3654;
IF3653:
	local[0]= NIL;
IF3654:
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F3535,fqv[74]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[75],module,F3536,fqv[76]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[77],module,F3642,fqv[78]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F3537,fqv[80]);
	local[0]= fqv[81];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[83]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<3; i++) ftab[i]=fcallx;
}
