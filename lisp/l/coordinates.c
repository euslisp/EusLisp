/* coordinates.c :  entry=coordinates */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "coordinates.h"
#pragma init (register_coordinates)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___coordinates();
extern pointer build_quote_vector();
static register_coordinates()
  { add_module_initializer("___coordinates", ___coordinates);}

static pointer F77018();
static pointer F77037();
static pointer F77038();
static pointer F77039();
static pointer F77040();
static pointer F77041();
static pointer F77042();
static pointer F77043();
static pointer F77044();
static pointer F77048();

/*coordinates-p*/
static pointer F77018(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK77094:
	ctx->vsp=local; return(local[0]);}

/*:dimension*/
static pointer M77119(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK77120:
	ctx->vsp=local; return(local[0]);}

/*:rot*/
static pointer M77135(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK77136:
	ctx->vsp=local; return(local[0]);}

/*:pos*/
static pointer M77150(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK77151:
	ctx->vsp=local; return(local[0]);}

/*:x-axis*/
static pointer M77165(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK77166:
	ctx->vsp=local; return(local[0]);}

/*:y-axis*/
static pointer M77182(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK77183:
	ctx->vsp=local; return(local[0]);}

/*:z-axis*/
static pointer M77198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK77199:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M77214(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77218;}
	local[0]= NIL;
ENT77218:
ENT77217:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF77234;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF77235;
IF77234:
	local[1]= NIL;
IF77235:
	local[1]= argv[0];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0]= w;
BLK77215:
	ctx->vsp=local; return(local[0]);}

/*:newcoords*/
static pointer M77253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT77257;}
	local[0]= NIL;
ENT77257:
ENT77256:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF77275;
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF77276;
IF77275:
	argv[0]->c.obj.iv[1] = argv[2]->c.obj.iv[1];
	argv[0]->c.obj.iv[2] = argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
IF77276:
	w = argv[0];
	local[0]= w;
BLK77254:
	ctx->vsp=local; return(local[0]);}

/*:replace-rot*/
static pointer M77310(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*replace-matrix*/
	local[0]= w;
BLK77311:
	ctx->vsp=local; return(local[0]);}

/*:replace-pos*/
static pointer M77330(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[4]); /*replace*/
	local[0]= w;
BLK77331:
	ctx->vsp=local; return(local[0]);}

/*:replace-coords*/
static pointer M77350(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT77354;}
	local[0]= NIL;
ENT77354:
ENT77353:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F77018(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto IF77373;
	local[0] = argv[2]->c.obj.iv[2];
	argv[2] = argv[2]->c.obj.iv[1];
	local[1]= argv[2];
	goto IF77374;
IF77373:
	local[1]= NIL;
IF77374:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK77351:
	ctx->vsp=local; return(local[0]);}

/*:copy-rot*/
static pointer M77414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[5]); /*copy-matrix*/
	local[0]= w;
BLK77415:
	ctx->vsp=local; return(local[0]);}

/*:copy-pos*/
static pointer M77431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
BLK77432:
	ctx->vsp=local; return(local[0]);}

/*:copy-coords*/
static pointer M77447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77451;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT77451:
ENT77450:
	if (n>3) maerror();
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK77448:
	ctx->vsp=local; return(local[0]);}

/*:coords*/
static pointer M77514(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77518;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT77518:
ENT77517:
	if (n>3) maerror();
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK77515:
	ctx->vsp=local; return(local[0]);}

/*:worldrot*/
static pointer M77581(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK77582:
	ctx->vsp=local; return(local[0]);}

/*:worldpos*/
static pointer M77596(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK77597:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M77611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK77612:
	ctx->vsp=local; return(local[0]);}

/*:copy-worldcoords*/
static pointer M77626(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK77627:
	ctx->vsp=local; return(local[0]);}

/*:parentcoords*/
static pointer M77644(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = loadglobal(fqv[8]);
	local[0]= w;
BLK77645:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M77660(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK77661:
	ctx->vsp=local; return(local[0]);}

/*:reset-coords*/
static pointer M77674(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[9]); /*array-dimension*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[10]); /*unit-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[11]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK77675:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M77727(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT77731;}
	local[0]= fqv[13];
ENT77731:
ENT77730:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F77018(ctx,1,local+3); /*coordinates-p*/
	if (w!=NIL) goto IF77756;
	local[3]= fqv[14];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF77757;
IF77756:
	local[3]= NIL;
IF77757:
	local[3]= local[0];
	w = fqv[15];
	if (memq(local[3],w)!=NIL) goto OR77773;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR77773;
	goto CON77772;
OR77773:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON77770;
CON77772:
	local[3]= local[0];
	w = fqv[17];
	if (memq(local[3],w)!=NIL) goto OR77805;
	local[3]= local[0];
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR77805;
	goto CON77804;
OR77805:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON77770;
CON77804:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F77018(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto CON77829;
	local[3]= local[0];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F77037(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON77770;
CON77829:
	local[3]= NIL;
CON77770:
	w = local[3];
	local[0]= w;
BLK77728:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M77871(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK77872:
	ctx->vsp=local; return(local[0]);}

/*:transform-vector*/
static pointer M77890(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK77891:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M77912(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)TRANSPOSE(ctx,1,local+0); /*transpose*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK77913:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transformation*/
static pointer M77951(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77955;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT77955:
ENT77954:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,2,local+1); /*transpose*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= makeflt(-1.00000000e+00);
	local[2]= local[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,3,local+1); /*scale*/
	w = local[0];
	local[0]= w;
BLK77952:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M78036(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT78040;}
	local[0]= fqv[13];
ENT78040:
ENT78039:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	w = fqv[21];
	if (memq(local[4],w)!=NIL) goto OR78096;
	local[4]= local[0];
	if (argv[0]==local[4]) goto OR78096;
	goto CON78095;
OR78096:
	local[4]= local[2];
	local[5]= argv[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F77037(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON78093;
CON78095:
	local[4]= local[0];
	w = fqv[22];
	if (memq(local[4],w)!=NIL) goto OR78117;
	local[4]= local[0];
	if (loadglobal(fqv[8])==local[4]) goto OR78117;
	goto CON78116;
OR78117:
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F77037(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON78093;
CON78116:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F77018(ctx,1,local+4); /*coordinates-p*/
	if (w==NIL) goto CON78138;
	local[4]= local[0];
	local[5]= fqv[18];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[3] = w;
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F77037(ctx,3,local+4); /*transform-coords*/
	local[4]= local[3];
	local[5]= fqv[20];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F77037(ctx,3,local+4); /*transform-coords*/
	local[4]= local[2];
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F77037(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON78093;
CON78138:
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= fqv[24];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON78093;
CON78177:
	local[4]= NIL;
CON78093:
	w = local[2];
	local[0]= w;
BLK78037:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M78191(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT78195;}
	local[0]= fqv[13];
ENT78195:
ENT78194:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[25];
	if (memq(local[1],w)!=NIL) goto OR78218;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR78218;
	goto CON78217;
OR78218:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON78215;
CON78217:
	local[1]= local[0];
	w = fqv[26];
	if (memq(local[1],w)!=NIL) goto OR78239;
	local[1]= local[0];
	if (loadglobal(fqv[8])==local[1]) goto OR78239;
	goto CON78238;
OR78239:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON78215;
CON78238:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F77018(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON78260;
	local[1]= local[0];
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= local[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON78215;
CON78260:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[27];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON78215;
CON78292:
	local[1]= NIL;
CON78215:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK78192:
	ctx->vsp=local; return(local[0]);}

/*:rotate-with-matrix*/
static pointer M78310(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[28];
	if (memq(local[0],w)!=NIL) goto OR78330;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR78330;
	goto CON78329;
OR78330:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON78327;
CON78329:
	local[0]= argv[3];
	w = fqv[29];
	if (memq(local[0],w)!=NIL) goto OR78351;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR78351;
	goto CON78350;
OR78351:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON78327;
CON78350:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F77018(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON78372;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[0]= w;
	goto CON78327;
CON78372:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON78327;
CON78417:
	local[0]= NIL;
CON78327:
	w = local[0];
	local[0]= w;
BLK78311:
	ctx->vsp=local; return(local[0]);}

/*:rotate*/
static pointer M78426(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT78431;}
	local[0]= NIL;
ENT78431:
	if (n>=5) { local[1]=(argv[4]); goto ENT78430;}
	local[1]= fqv[13];
ENT78430:
ENT78429:
	if (n>5) maerror();
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	if (makeint(2)!=local[2]) goto CON78457;
	w = argv[2];
	if (!isnum(w)) goto CON78467;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON78465;
CON78467:
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON78477;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,3,local+2); /*m**/
	local[2]= w;
	goto CON78465;
CON78477:
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto CON78465;
CON78490:
	local[2]= NIL;
CON78465:
	goto CON78455;
CON78457:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON78495;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON78455;
CON78495:
	if (local[0]!=NIL) goto CON78513;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON78455;
CON78513:
	local[2]= local[1];
	w = fqv[36];
	if (memq(local[2],w)!=NIL) goto OR78532;
	local[2]= local[1];
	if (argv[0]==local[2]) goto OR78532;
	goto CON78531;
OR78532:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON78529;
CON78531:
	local[2]= local[1];
	w = fqv[37];
	if (memq(local[2],w)!=NIL) goto OR78554;
	local[2]= local[1];
	if (loadglobal(fqv[8])==local[2]) goto OR78554;
	goto CON78553;
OR78554:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= T;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON78529;
CON78553:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F77018(ctx,1,local+2); /*coordinates-p*/
	if (w==NIL) goto CON78576;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON78529;
CON78576:
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= fqv[38];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON78529;
CON78593:
	local[2]= NIL;
CON78529:
	goto CON78455;
CON78525:
	local[2]= NIL;
CON78455:
	local[2]= argv[0];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0]= w;
BLK78427:
	ctx->vsp=local; return(local[0]);}

/*:orient-with-matrix*/
static pointer M78611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[39];
	if (memq(local[0],w)!=NIL) goto OR78631;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR78631;
	goto CON78630;
OR78631:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON78628;
CON78630:
	local[0]= argv[3];
	w = fqv[40];
	if (memq(local[0],w)!=NIL) goto OR78652;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR78652;
	goto CON78651;
OR78652:
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[0]->c.obj.iv[1];
	goto CON78628;
CON78651:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F77018(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON78675;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	local[0]= w;
	goto CON78628;
CON78675:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON78628;
CON78701:
	local[0]= NIL;
CON78628:
	w = local[0];
	local[0]= w;
BLK78612:
	ctx->vsp=local; return(local[0]);}

/*:orient*/
static pointer M78710(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT78714;}
	local[0]= fqv[13];
ENT78714:
ENT78713:
	if (n>5) maerror();
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON78738;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON78736;
CON78738:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON78755;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON78736;
CON78755:
	local[1]= local[0];
	w = fqv[43];
	if (memq(local[1],w)!=NIL) goto OR78776;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR78776;
	goto CON78775;
OR78776:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= w;
	goto CON78773;
CON78775:
	local[1]= local[0];
	w = fqv[44];
	if (memq(local[1],w)!=NIL) goto OR78798;
	local[1]= local[0];
	if (loadglobal(fqv[8])==local[1]) goto OR78798;
	goto CON78797;
OR78798:
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+1); /*rotation-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto CON78773;
CON78797:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F77018(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON78824;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON78773;
CON78824:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[45];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON78773;
CON78841:
	local[1]= NIL;
CON78773:
	goto CON78736;
CON78769:
	local[1]= NIL;
CON78736:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK78711:
	ctx->vsp=local; return(local[0]);}

/*:parent-vector*/
static pointer M78859(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[46];
	if (memq(local[0],w)!=NIL) goto OR78879;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR78879;
	goto CON78878;
OR78879:
	local[0]= argv[0];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON78876;
CON78878:
	local[0]= argv[3];
	w = fqv[48];
	if (memq(local[0],w)!=NIL) goto OR78901;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR78901;
	goto CON78900;
OR78901:
	local[0]= argv[2];
	goto CON78876;
CON78900:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F77018(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON78918;
	local[0]= argv[3];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON78876;
CON78918:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[49];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON78876;
CON78931:
	local[0]= NIL;
CON78876:
	w = local[0];
	local[0]= w;
BLK78860:
	ctx->vsp=local; return(local[0]);}

/*:parent-orientation*/
static pointer M78941(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[50];
	if (memq(local[0],w)!=NIL) goto OR78961;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR78961;
	goto CON78960;
OR78961:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON78958;
CON78960:
	local[0]= argv[3];
	w = fqv[51];
	if (memq(local[0],w)!=NIL) goto OR78981;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR78981;
	goto CON78980;
OR78981:
	local[0]= argv[2];
	goto CON78958;
CON78980:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F77018(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON78998;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON78958;
CON78998:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[52];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON78958;
CON79013:
	local[0]= NIL;
CON78958:
	w = local[0];
	local[0]= w;
BLK78942:
	ctx->vsp=local; return(local[0]);}

/*:translate*/
static pointer M79023(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT79027;}
	local[0]= fqv[13];
ENT79027:
ENT79026:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0];
	local[5]= fqv[53];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK79024:
	ctx->vsp=local; return(local[0]);}

/*:locate*/
static pointer M79064(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT79068;}
	local[0]= fqv[13];
ENT79068:
ENT79067:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= argv[0];
	local[6]= fqv[54];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[4]); /*replace*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK79065:
	ctx->vsp=local; return(local[0]);}

/*:scale*/
static pointer M79104(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT79108;}
	local[0]= NIL;
ENT79108:
ENT79107:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF79124;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[55]); /*scale-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF79125;
IF79124:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*matrix-row*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORM(ctx,1,local+1); /*norm*/
	local[1]= w;
IF79125:
	w = local[1];
	local[0]= w;
BLK79105:
	ctx->vsp=local; return(local[0]);}

/*:euler*/
static pointer M79151(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,3,local+2,&ftab[9],fqv[56]); /*euler-matrix*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK79152:
	ctx->vsp=local; return(local[0]);}

/*:euler-angle*/
static pointer M79182(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)INV_EULER(ctx,1,local+0); /*euler-angle*/
	local[0]= w;
BLK79183:
	ctx->vsp=local; return(local[0]);}

/*:rpy*/
static pointer M79198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,3,local+2,&ftab[10],fqv[57]); /*rpy-matrix*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK79199:
	ctx->vsp=local; return(local[0]);}

/*:rpy-angle*/
static pointer M79229(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)INV_RPY(ctx,1,local+0); /*rpy-angle*/
	local[0]= w;
BLK79230:
	ctx->vsp=local; return(local[0]);}

/*:rotation-angle*/
static pointer M79245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ROTANGLE(ctx,1,local+0); /*rotation-angle*/
	local[0]= w;
BLK79246:
	ctx->vsp=local; return(local[0]);}

/*:4x4*/
static pointer M79261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT79265;}
	local[0]= NIL;
ENT79265:
ENT79264:
	if (n>3) maerror();
	if (local[0]==NIL) goto CON79283;
	local[1]= makeint(0);
	local[2]= makeint(3);
WHL79311:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX79312;
	local[3]= makeint(0);
	local[4]= makeint(3);
WHL79342:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX79343;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL79342;
WHX79343:
	local[5]= NIL;
BLK79344:
	w = NIL;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= makeint(3);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	{ register integer_t i; register pointer v;
	  i=intval(local[4]); v=local[3];
	  v->c.fvec.fv[i]=fltval(w);}
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL79311;
WHX79312:
	local[3]= NIL;
BLK79313:
	w = NIL;
	local[1]= argv[0];
	goto CON79281;
CON79283:
	local[1]= makeint(4);
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,2,local+1,&ftab[11],fqv[58]); /*make-matrix*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint(3);
	local[3]= makeint(3);
	local[4]= makeflt(1.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= makeint(0);
	local[2]= makeint(3);
WHL79440:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX79441;
	local[3]= makeint(0);
	local[4]= makeint(3);
WHL79471:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX79472;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL79471;
WHX79472:
	local[5]= NIL;
BLK79473:
	w = NIL;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint(3);
	local[6]= argv[0]->c.obj.iv[2];
	{ register integer_t i=intval(local[1]);
	  w=makeflt(local[6]->c.fvec.fv[i]);}
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,4,local+3); /*aset*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL79440;
WHX79441:
	local[3]= NIL;
BLK79442:
	w = NIL;
	local[1]= local[0];
	goto CON79281;
CON79400:
	local[1]= NIL;
CON79281:
	w = local[1];
	local[0]= w;
BLK79262:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M79531(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT79535;}
	local[0]= T;
ENT79535:
ENT79534:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[59];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w = makeint(2);
	if ((integer_t)local[5] <= (integer_t)w) goto CON79570;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)INV_RPY(ctx,1,local+5); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[62];
	if (local[1]==NIL) goto IF79600;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF79601;
IF79600:
	local[11]= fqv[63];
IF79601:
	local[12]= local[4];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[4];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= local[4];
	local[15]= makeint(2);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,9,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON79568;
CON79570:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	if (makeint(2)!=local[5]) goto CON79642;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[64];
	if (local[1]==NIL) goto IF79659;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF79660;
IF79659:
	local[11]= fqv[65];
IF79660:
	local[12]= local[4];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[4];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)ROTANGLE(ctx,1,local+14); /*rotation-angle*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,6,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON79568;
CON79642:
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON79568;
CON79680:
	local[5]= NIL;
CON79568:
	w = local[5];
	local[0]= w;
BLK79532:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M79694(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT79698;}
	local[0]= makeint(3);
ENT79698:
ENT79697:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[10]); /*unit-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[11]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0];
	local[0]= w;
BLK79695:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M79731(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[66], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY79755;
	local[0] = makeint(3);
KEY79755:
	if (n & (1<<1)) goto KEY79760;
	local[13]= loadglobal(fqv[11]);
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[1] = w;
KEY79760:
	if (n & (1<<2)) goto KEY79769;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(*ftab[5])(ctx,1,local+13,&ftab[5],fqv[10]); /*unit-matrix*/
	local[2] = w;
KEY79769:
	if (n & (1<<3)) goto KEY79777;
	local[3] = NIL;
KEY79777:
	if (n & (1<<4)) goto KEY79782;
	local[4] = NIL;
KEY79782:
	if (n & (1<<5)) goto KEY79787;
	local[5] = NIL;
KEY79787:
	if (n & (1<<6)) goto KEY79792;
	local[6] = NIL;
KEY79792:
	if (n & (1<<7)) goto KEY79797;
	local[7] = NIL;
KEY79797:
	if (n & (1<<8)) goto KEY79802;
	local[8] = local[7];
KEY79802:
	if (n & (1<<9)) goto KEY79808;
	local[9] = NIL;
KEY79808:
	if (n & (1<<10)) goto KEY79813;
	local[10] = fqv[13];
KEY79813:
	if (n & (1<<11)) goto KEY79820;
	local[11] = NIL;
KEY79820:
	if (n & (1<<12)) goto KEY79825;
	local[12] = NIL;
KEY79825:
	argv[0]->c.obj.iv[1] = local[2];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)F77018(ctx,1,local+13); /*coordinates-p*/
	if (w==NIL) goto IF79843;
	local[13]= local[10];
	local[14]= fqv[47];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF79844;
IF79843:
	local[13]= local[1];
IF79844:
	argv[0]->c.obj.iv[2] = local[13];
	if (local[3]==NIL) goto CON79863;
	local[13]= argv[0];
	local[14]= fqv[67];
	local[15]= local[3];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[3];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[3];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON79861;
CON79863:
	if (local[4]==NIL) goto CON79882;
	local[13]= argv[0];
	local[14]= fqv[68];
	local[15]= local[4];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[4];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[4];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON79861;
CON79882:
	if (local[8]==NIL) goto CON79901;
	local[13]= argv[0];
	local[14]= fqv[69];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto CON79861;
CON79901:
	w = local[6];
	if (!iscons(w)) goto CON79912;
	local[13]= NIL;
	local[14]= local[6];
WHL79935:
	if (local[14]==NIL) goto WHX79936;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	local[16]= fqv[70];
	local[17]= local[13];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[18];
	local[18]= w;
	local[19]= local[10];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,5,local+15); /*send*/
	goto WHL79935;
WHX79936:
	local[15]= NIL;
BLK79937:
	w = NIL;
	local[13]= w;
	goto CON79861;
CON79912:
	w = local[6];
	if (!isnum(w)) goto CON80028;
	local[13]= argv[0];
	local[14]= fqv[70];
	local[15]= local[6];
	local[16]= local[5];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON79861;
CON80028:
	if (local[9]==NIL) goto CON80041;
	local[13]= argv[0];
	local[14]= fqv[71];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto CON79861;
CON80041:
	local[13]= NIL;
CON79861:
	if (local[11]==NIL) goto IF80054;
	local[13]= argv[0];
	local[14]= fqv[2];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF80055;
IF80054:
	local[13]= NIL;
IF80055:
	local[13]= NIL;
	local[14]= local[12];
WHL80084:
	if (local[14]==NIL) goto WHX80085;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)PUTPROP(ctx,3,local+15); /*putprop*/
	goto WHL80084;
WHX80085:
	local[15]= NIL;
BLK80086:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK79732:
	ctx->vsp=local; return(local[0]);}

/*:parent*/
static pointer M80196(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK80197:
	ctx->vsp=local; return(local[0]);}

/*:descendants*/
static pointer M80211(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK80212:
	ctx->vsp=local; return(local[0]);}

/*:inheritance*/
static pointer M80226(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO80240,env,argv,local);
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK80227:
	ctx->vsp=local; return(local[0]);}

/*:leaves*/
static pointer M80245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[4]==NIL) goto IF80258;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[72];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[73]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[74]); /*flatten*/
	local[0]= w;
	goto IF80259;
IF80258:
	local[0]= argv[0];
IF80259:
	w = local[0];
	local[0]= w;
BLK80246:
	ctx->vsp=local; return(local[0]);}

/*:assoc*/
static pointer M80274(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT80278;}
	local[0]= NIL;
ENT80278:
ENT80277:
	if (n>4) maerror();
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	if (memq(local[1],w)!=NIL) goto IF80297;
	if (local[0]!=NIL) goto IF80311;
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[75];
	local[3]= argv[2];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF80312;
IF80311:
	local[1]= NIL;
IF80312:
	local[1]= argv[2];
	local[2]= fqv[76];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[16];
	local[3]= local[0]->c.obj.iv[1];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[4] = cons(ctx,local[1],w);
	local[1]= argv[2];
	goto IF80298;
IF80297:
	local[1]= NIL;
IF80298:
	w = local[1];
	local[0]= w;
BLK80275:
	ctx->vsp=local; return(local[0]);}

/*:dissoc*/
static pointer M80376(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[4];
	if (memq(local[0],w)==NIL) goto IF80392;
	local[0]= argv[2];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[78]); /*delete*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[2];
	local[2]= fqv[79];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[16];
	local[3]= local[0]->c.obj.iv[1];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = argv[2];
	local[0]= w;
	goto IF80393;
IF80392:
	local[0]= NIL;
IF80393:
	w = local[0];
	local[0]= w;
BLK80377:
	ctx->vsp=local; return(local[0]);}

/*:clear-assoc*/
static pointer M80461(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL80491:
	if (local[1]==NIL) goto WHX80492;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL80491;
WHX80492:
	local[2]= NIL;
BLK80493:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK80462:
	ctx->vsp=local; return(local[0]);}

/*:obey*/
static pointer M80551(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF80566;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[80];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF80567;
IF80566:
	local[0]= NIL;
IF80567:
	argv[0]->c.obj.iv[3] = argv[2];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK80552:
	ctx->vsp=local; return(local[0]);}

/*:disobey*/
static pointer M80587(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto IF80602;
	argv[0]->c.obj.iv[3] = NIL;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF80603;
IF80602:
	local[0]= NIL;
IF80603:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK80588:
	ctx->vsp=local; return(local[0]);}

/*:newcoords*/
static pointer M80617(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT80621;}
	local[0]= NIL;
ENT80621:
ENT80620:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[60]));
	local[3]= fqv[16];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK80618:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M80658(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]!=NIL) goto IF80672;
	argv[0]->c.obj.iv[7] = T;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[73]); /*send-all*/
	local[0]= w;
	goto IF80673;
IF80672:
	local[0]= NIL;
IF80673:
	w = local[0];
	local[0]= w;
BLK80659:
	ctx->vsp=local; return(local[0]);}

/*:worldrot*/
static pointer M80693(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = w->c.obj.iv[1];
	local[0]= w;
BLK80694:
	ctx->vsp=local; return(local[0]);}

/*:worldpos*/
static pointer M80716(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = w->c.obj.iv[2];
	local[0]= w;
BLK80717:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M80739(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto IF80753;
	if (argv[0]->c.obj.iv[3]==NIL) goto IF80762;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)F77037(ctx,3,local+0); /*transform-coords*/
	local[0]= w;
	goto IF80763;
IF80762:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= fqv[69];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF80763:
	local[0]= argv[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= argv[0]->c.obj.iv[7];
	goto IF80754;
IF80753:
	local[0]= NIL;
IF80754:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK80740:
	ctx->vsp=local; return(local[0]);}

/*:copy-worldcoords*/
static pointer M80799(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT80803;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT80803:
ENT80802:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK80800:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M80880(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK80881:
	ctx->vsp=local; return(local[0]);}

/*:parentcoords*/
static pointer M80893(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF80906;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF80907;
IF80906:
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[83]!=local[1]) goto IF80934;
	local[1]= loadglobal(fqv[8]);
	goto IF80935;
IF80934:
	local[1]= local[0];
	if (fqv[84]!=local[1]) goto IF80944;
	local[1]= loadglobal(fqv[85]);
	goto IF80945;
IF80944:
	if (T==NIL) goto IF80954;
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF80955;
IF80954:
	local[1]= NIL;
IF80955:
IF80945:
IF80935:
	w = local[1];
	local[0]= w;
IF80907:
	w = local[0];
	local[0]= w;
BLK80894:
	ctx->vsp=local; return(local[0]);}

/*:transform-vector*/
static pointer M80962(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK80963:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M80987(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK80988:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M81012(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[88];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK81013:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transformation*/
static pointer M81037(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT81041;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT81041:
ENT81040:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK81038:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M81091(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81095;}
	local[0]= fqv[13];
ENT81095:
ENT81094:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	w = fqv[89];
	if (memq(local[6],w)!=NIL) goto OR81149;
	local[6]= local[0];
	if (argv[0]==local[6]) goto OR81149;
	goto CON81148;
OR81149:
	local[6]= local[3];
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON81146;
CON81148:
	local[6]= local[0];
	w = fqv[90];
	if (memq(local[6],w)!=NIL) goto OR81170;
	local[6]= local[0];
	if (argv[0]->c.obj.iv[3]==local[6]) goto OR81170;
	goto CON81169;
OR81170:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[60]));
	local[8]= fqv[20];
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,3,local+6); /*send-message*/
	local[4] = w;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= argv[0];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON81146;
CON81169:
	local[6]= local[0];
	w = fqv[91];
	if (memq(local[6],w)!=NIL) goto OR81217;
	local[6]= local[0];
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto OR81217;
	goto CON81216;
OR81217:
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON81146;
CON81216:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F77018(ctx,1,local+6); /*coordinates-p*/
	if (w==NIL) goto CON81240;
	local[6]= local[0];
	local[7]= fqv[18];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[5] = w;
	local[6]= local[3];
	local[7]= local[5];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= local[5];
	local[7]= fqv[20];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F77037(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON81146;
CON81240:
	local[6]= argv[0];
	local[7]= fqv[23];
	local[8]= fqv[92];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto CON81146;
CON81279:
	local[6]= NIL;
CON81146:
	w = local[6];
	local[0]= w;
BLK81092:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M81290(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81294;}
	local[0]= fqv[13];
ENT81294:
ENT81293:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[93];
	if (memq(local[1],w)!=NIL) goto OR81317;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR81317;
	goto CON81316;
OR81317:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON81314;
CON81316:
	local[1]= local[0];
	w = fqv[94];
	if (memq(local[1],w)!=NIL) goto OR81338;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR81338;
	goto CON81337;
OR81338:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F77037(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON81314;
CON81337:
	local[1]= local[0];
	w = fqv[95];
	if (memq(local[1],w)!=NIL) goto OR81359;
	local[1]= local[0];
	local[2]= loadglobal(fqv[8]);
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w!=NIL) goto OR81359;
	goto CON81358;
OR81359:
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON81314;
CON81358:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F77018(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON81414;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON81314;
CON81414:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[96];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81314;
CON81478:
	local[1]= NIL;
CON81314:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK81291:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M81496(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81500;}
	local[0]= fqv[13];
ENT81500:
ENT81499:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F77018(ctx,1,local+3); /*coordinates-p*/
	if (w!=NIL) goto IF81525;
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF81526;
IF81525:
	local[3]= NIL;
IF81526:
	local[3]= local[0];
	w = fqv[98];
	if (memq(local[3],w)!=NIL) goto OR81542;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR81542;
	goto CON81541;
OR81542:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81539;
CON81541:
	local[3]= local[0];
	w = fqv[99];
	if (memq(local[3],w)!=NIL) goto OR81574;
	local[3]= local[0];
	if (argv[0]->c.obj.iv[3]==local[3]) goto OR81574;
	goto CON81573;
OR81574:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81539;
CON81573:
	local[3]= local[0];
	w = fqv[100];
	if (memq(local[3],w)!=NIL) goto OR81596;
	local[3]= local[0];
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR81596;
	goto CON81595;
OR81596:
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81539;
CON81595:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F77018(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto CON81638;
	local[3]= local[0];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F77037(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81539;
CON81638:
	local[3]= NIL;
CON81539:
	w = local[3];
	local[0]= w;
BLK81497:
	ctx->vsp=local; return(local[0]);}

/*:rotate-with-matrix*/
static pointer M81680(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[101];
	if (memq(local[0],w)!=NIL) goto OR81700;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR81700;
	goto CON81699;
OR81700:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON81697;
CON81699:
	local[0]= argv[3];
	w = fqv[102];
	if (memq(local[0],w)!=NIL) goto OR81729;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR81729;
	goto CON81728;
OR81729:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON81697;
CON81728:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[1];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F77018(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto IF81784;
	local[3]= argv[3];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	argv[2] = w;
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,1,local+4); /*transpose*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= w;
	goto IF81785;
IF81784:
	local[3]= NIL;
IF81785:
	local[3]= argv[2];
	local[4]= local[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[2];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0]= w;
	goto CON81697;
CON81757:
	local[0]= NIL;
CON81697:
	w = local[0];
	local[0]= w;
BLK81681:
	ctx->vsp=local; return(local[0]);}

/*:rotate*/
static pointer M81852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT81856;}
	local[0]= fqv[13];
ENT81856:
ENT81855:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	if (makeint(2)!=local[1]) goto CON81880;
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[60]));
	local[3]= fqv[70];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	goto CON81878;
CON81880:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON81897;
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81878;
CON81897:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON81914;
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81878;
CON81914:
	local[1]= local[0];
	w = fqv[103];
	if (memq(local[1],w)!=NIL) goto OR81935;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR81935;
	goto CON81934;
OR81935:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81932;
CON81934:
	local[1]= local[0];
	w = fqv[104];
	if (memq(local[1],w)!=NIL) goto OR81965;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR81965;
	goto CON81964;
OR81965:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= T;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81932;
CON81964:
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81932;
CON81994:
	local[1]= NIL;
CON81932:
	goto CON81878;
CON81928:
	local[1]= NIL;
CON81878:
	w = local[1];
	local[0]= w;
BLK81853:
	ctx->vsp=local; return(local[0]);}

/*:orient-with-matrix*/
static pointer M82008(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[105];
	if (memq(local[0],w)!=NIL) goto OR82028;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82028;
	goto CON82027;
OR82028:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON82025;
CON82027:
	local[0]= argv[3];
	w = fqv[106];
	if (memq(local[0],w)!=NIL) goto OR82057;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR82057;
	goto CON82056;
OR82057:
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON82025;
CON82056:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[1];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F77018(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto IF82114;
	local[3]= argv[3];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	argv[2] = w;
	local[3]= argv[2];
	goto IF82115;
IF82114:
	local[3]= NIL;
IF82115:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0]= w;
	goto CON82025;
CON82087:
	local[0]= NIL;
CON82025:
	w = local[0];
	local[0]= w;
BLK82009:
	ctx->vsp=local; return(local[0]);}

/*:orient*/
static pointer M82164(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT82168;}
	local[0]= fqv[13];
ENT82168:
ENT82167:
	if (n>5) maerror();
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON82192;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82190;
CON82192:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON82209;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82190;
CON82209:
	local[1]= local[0];
	w = fqv[107];
	if (memq(local[1],w)!=NIL) goto OR82230;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR82230;
	goto CON82229;
OR82230:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82227;
CON82229:
	local[1]= local[0];
	w = fqv[108];
	if (memq(local[1],w)!=NIL) goto OR82260;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR82260;
	goto CON82259;
OR82260:
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+1); /*rotation-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82227;
CON82259:
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82227;
CON82293:
	local[1]= NIL;
CON82227:
	goto CON82190;
CON82223:
	local[1]= NIL;
CON82190:
	w = local[1];
	local[0]= w;
BLK82165:
	ctx->vsp=local; return(local[0]);}

/*:parent-vector*/
static pointer M82307(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[109];
	if (memq(local[0],w)!=NIL) goto OR82327;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82327;
	goto CON82326;
OR82327:
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[60]));
	local[2]= fqv[47];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= w;
	goto CON82324;
CON82326:
	local[0]= argv[3];
	w = fqv[110];
	if (memq(local[0],w)!=NIL) goto OR82352;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR82352;
	goto CON82351;
OR82352:
	local[0]= argv[2];
	goto CON82324;
CON82351:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F77018(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto IF82372;
	local[0]= argv[3];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF82373;
IF82372:
	local[0]= NIL;
IF82373:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF82392;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[88];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF82393;
IF82392:
	local[0]= argv[2];
IF82393:
	goto CON82324;
CON82368:
	local[0]= NIL;
CON82324:
	w = local[0];
	local[0]= w;
BLK82308:
	ctx->vsp=local; return(local[0]);}

/*:parent-orientation*/
static pointer M82405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[111];
	if (memq(local[0],w)!=NIL) goto OR82425;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82425;
	goto CON82424;
OR82425:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON82422;
CON82424:
	local[0]= argv[3];
	w = fqv[112];
	if (memq(local[0],w)!=NIL) goto OR82445;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR82445;
	goto CON82444;
OR82445:
	local[0]= argv[2];
	goto CON82422;
CON82444:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F77018(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto IF82465;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF82466;
IF82465:
	local[0]= NIL;
IF82466:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF82491;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)TRANSPOSE(ctx,1,local+0); /*transpose*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto IF82492;
IF82491:
	local[0]= argv[2];
IF82492:
	goto CON82422;
CON82461:
	local[0]= NIL;
CON82422:
	w = local[0];
	local[0]= w;
BLK82406:
	ctx->vsp=local; return(local[0]);}

/*:manager*/
static pointer M82508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT82512;}
	local[0]= NIL;
ENT82512:
ENT82511:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF82528;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF82529;
IF82528:
	local[1]= NIL;
IF82529:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK82509:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M82543(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST82546:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[113], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY82559;
	local[1] = NIL;
KEY82559:
	if (n & (1<<1)) goto KEY82564;
	local[2] = NIL;
KEY82564:
	local[3]= (pointer)get_sym_func(fqv[114]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[60]));
	local[6]= fqv[115];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	argv[0]->c.obj.iv[6] = argv[0];
	argv[0]->c.obj.iv[7] = T;
	local[3]= loadglobal(fqv[0]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[115];
	local[6]= fqv[116];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)COPYOBJ(ctx,1,local+7); /*copy-object*/
	local[7]= w;
	local[8]= fqv[117];
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)COPYOBJ(ctx,1,local+9); /*copy-object*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[5] = w;
	if (local[1]==NIL) goto IF82642;
	local[3]= local[1];
	local[4]= fqv[118];
	local[5]= argv[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF82643;
IF82642:
	local[3]= NIL;
IF82643:
	w = argv[0];
	local[0]= w;
BLK82544:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO80240(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*transform-coords*/
static pointer F77037(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT82682;}
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,1,local+4,&ftab[5],fqv[10]); /*unit-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[11]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
ENT82682:
ENT82681:
	if (n>3) maerror();
	local[1]= argv[0];
	if (local[0]!=local[1]) goto IF82745;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= w;
	goto IF82746;
IF82745:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[1]->c.obj.iv[2];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)TRANSFORM(ctx,3,local+2); /*transform*/
	local[2]= w;
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= w;
IF82746:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	w = local[0];
	local[0]= w;
BLK82679:
	ctx->vsp=local; return(local[0]);}

/*transform-coords**/
static pointer F77038(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST82829:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F77037(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[0];
WHL82873:
	if (local[4]==NIL) goto WHX82874;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)F77037(ctx,3,local+5); /*transform-coords*/
	goto WHL82873;
WHX82874:
	local[5]= NIL;
BLK82875:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK82827:
	ctx->vsp=local; return(local[0]);}

/*transform-vector*/
static pointer F77039(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK82934:
	ctx->vsp=local; return(local[0]);}

/*make-coords*/
static pointer F77040(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST82970:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK82968:
	ctx->vsp=local; return(local[0]);}

/*make-cascoords*/
static pointer F77041(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST82993:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK82991:
	ctx->vsp=local; return(local[0]);}

/*coords*/
static pointer F77042(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST83017:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK83015:
	ctx->vsp=local; return(local[0]);}

/*cascoords*/
static pointer F77043(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST83040:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK83038:
	ctx->vsp=local; return(local[0]);}

/*wrt*/
static pointer F77044(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[47];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK83061:
	ctx->vsp=local; return(local[0]);}

/*coordinates-distance*/
static pointer F77048(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[75];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[59];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORM(ctx,1,local+2); /*norm*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROTANGLE(ctx,1,local+3); /*rotation-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK83085:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___coordinates(ctx,n,argv,env)
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
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF83133;
	local[0]= fqv[123];
	local[1]= fqv[124];
	local[2]= fqv[125];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,3,local+0,&ftab[15],fqv[126]); /*make-package*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF83152;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF83153;
IF83152:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF83153:
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[132]); /*use-package*/
	local[0]= w;
	goto IF83134;
IF83133:
	local[0]= NIL;
IF83134:
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF83174;
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF83175;
IF83174:
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF83175:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[139];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[140];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[0];
	local[1]= fqv[141];
	local[2]= fqv[0];
	local[3]= fqv[142];
	local[4]= loadglobal(fqv[143]);
	local[5]= fqv[144];
	local[6]= fqv[145];
	local[7]= fqv[146];
	local[8]= NIL;
	local[9]= fqv[147];
	local[10]= NIL;
	local[11]= fqv[148];
	local[12]= makeint(-1);
	local[13]= fqv[149];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[150]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F77018,fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77119,fqv[82],fqv[0],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77135,fqv[116],fqv[0],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77150,fqv[117],fqv[0],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77165,fqv[156],fqv[0],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77182,fqv[158],fqv[0],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77198,fqv[160],fqv[0],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77214,fqv[2],fqv[0],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77253,fqv[16],fqv[0],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77310,fqv[164],fqv[0],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77330,fqv[166],fqv[0],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77350,fqv[69],fqv[0],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77414,fqv[169],fqv[0],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77431,fqv[171],fqv[0],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77447,fqv[77],fqv[0],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77514,fqv[7],fqv[0],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77581,fqv[30],fqv[0],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77596,fqv[59],fqv[0],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77611,fqv[18],fqv[0],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77626,fqv[178],fqv[0],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77644,fqv[19],fqv[0],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77660,fqv[12],fqv[0],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77674,fqv[182],fqv[0],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77727,fqv[184],fqv[0],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77871,fqv[87],fqv[0],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77890,fqv[47],fqv[0],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77912,fqv[88],fqv[0],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77951,fqv[20],fqv[0],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78036,fqv[75],fqv[0],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78191,fqv[191],fqv[0],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78310,fqv[35],fqv[0],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78426,fqv[70],fqv[0],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78611,fqv[42],fqv[0],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78710,fqv[196],fqv[0],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78859,fqv[54],fqv[0],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78941,fqv[53],fqv[0],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79023,fqv[200],fqv[0],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79064,fqv[202],fqv[0],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79104,fqv[204],fqv[0],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79151,fqv[67],fqv[0],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79182,fqv[207],fqv[0],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79198,fqv[68],fqv[0],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79229,fqv[210],fqv[0],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79245,fqv[212],fqv[0],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79261,fqv[71],fqv[0],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79531,fqv[61],fqv[0],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79694,fqv[6],fqv[0],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M79731,fqv[115],fqv[0],fqv[217]);
	local[0]= fqv[121];
	local[1]= fqv[141];
	local[2]= fqv[121];
	local[3]= fqv[142];
	local[4]= loadglobal(fqv[0]);
	local[5]= fqv[144];
	local[6]= fqv[218];
	local[7]= fqv[146];
	local[8]= NIL;
	local[9]= fqv[147];
	local[10]= NIL;
	local[11]= fqv[148];
	local[12]= makeint(-1);
	local[13]= fqv[149];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[150]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80196,fqv[219],fqv[121],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80211,fqv[221],fqv[121],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80226,fqv[119],fqv[121],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80245,fqv[72],fqv[121],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80274,fqv[118],fqv[121],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80376,fqv[80],fqv[121],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80461,fqv[227],fqv[121],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80551,fqv[76],fqv[121],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80587,fqv[79],fqv[121],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80617,fqv[16],fqv[121],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80658,fqv[12],fqv[121],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80693,fqv[30],fqv[121],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80716,fqv[59],fqv[121],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80739,fqv[18],fqv[121],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80799,fqv[178],fqv[121],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80880,fqv[81],fqv[121],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80893,fqv[19],fqv[121],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80962,fqv[47],fqv[121],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80987,fqv[87],fqv[121],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81012,fqv[88],fqv[121],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81037,fqv[20],fqv[121],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81091,fqv[75],fqv[121],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81290,fqv[191],fqv[121],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81496,fqv[184],fqv[121],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81680,fqv[35],fqv[121],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81852,fqv[70],fqv[121],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82008,fqv[42],fqv[121],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82164,fqv[196],fqv[121],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82307,fqv[54],fqv[121],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82405,fqv[53],fqv[121],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82508,fqv[252],fqv[121],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82543,fqv[115],fqv[121],fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F77037,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F77038,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F77039,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F77040,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F77041,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F77042,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F77043,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F77044,fqv[270]);
	local[0]= fqv[8];
	local[1]= fqv[271];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[115];
	local[5]= fqv[2];
	local[6]= fqv[8];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[85];
	local[1]= fqv[271];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[115];
	local[5]= fqv[82];
	local[6]= makeint(2);
	local[7]= fqv[2];
	local[8]= fqv[85];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F77048,fqv[273]);
	local[0]= fqv[274];
	local[1]= fqv[275];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[276]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<19; i++) ftab[i]=fcallx;
}
