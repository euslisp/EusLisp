/* polygon.c :  entry=polygon */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "polygon.h"
#pragma init (register_polygon)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___polygon();
extern pointer build_quote_vector();
static register_polygon()
  { add_module_initializer("___polygon", ___polygon);}

static pointer F2970();
static pointer F2971();
static pointer F2972();

/*:vertices*/
static pointer M2973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK2974:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M2975(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK2976:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M2977(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL2979:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2980;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	goto WHL2979;
WHX2980:
	local[2]= NIL;
BLK2981:
	w = local[0];
	local[0]= w;
BLK2978:
	ctx->vsp=local; return(local[0]);}

/*:drawners*/
static pointer M2983(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2984:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2985(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK2986:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M2987(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[1]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w!=NIL) goto IF2989;
	local[0]= argv[2];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF2990;
IF2989:
	local[0]= NIL;
IF2990:
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= fqv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2988:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M2991(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
WHL2993:
	if (local[0]==NIL) goto WHX2994;
	local[4]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= local[3];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	goto WHL2993;
WHX2994:
	local[4]= NIL;
BLK2995:
	local[4]= argv[0]->c.obj.iv[12];
	local[5]= fqv[4];
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK2992:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M2998(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[6]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0] = w;
	argv[0]->c.obj.iv[11] = T;
WHL3000:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3001;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[7]); /*triangle*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF3003;
	argv[0]->c.obj.iv[11] = NIL;
	local[0] = NIL;
	local[1]= local[0];
	goto IF3004;
IF3003:
	local[1]= NIL;
IF3004:
	goto WHL3000;
WHX3001:
	local[1]= NIL;
BLK3002:
	w = local[1];
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK2999:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3006(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[8]));
	local[2]= fqv[4];
	local[3]= fqv[9];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[2];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= (pointer)get_sym_func(fqv[10]);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= makeflt(9.99999791e-03);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[11]); /*make-bounding-box*/
	argv[0]->c.obj.iv[12] = w;
	local[0]= argv[0]->c.obj.iv[9];
	argv[0]->c.obj.iv[10] = NIL;
WHL3008:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3009;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[12]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	goto WHL3008;
WHX3009:
	local[1]= NIL;
BLK3010:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK3007:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M3012(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3015;}
	local[0]= NIL;
ENT3015:
ENT3014:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF3016;
	local[0] = argv[2]->c.obj.iv[2];
	argv[2] = argv[2]->c.obj.iv[1];
	local[1]= argv[2];
	goto IF3017;
IF3016:
	local[1]= NIL;
IF3017:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[10];
WHL3019:
	if (local[6]==NIL) goto WHX3020;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5]->c.obj.iv[1];
	local[8]= local[5]->c.obj.iv[2];
	local[9]= argv[2];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,4,local+7,&ftab[3],fqv[14]); /*line-intersection*/
	local[1] = w;
	if (local[1]==NIL) goto IF3023;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[7]= makeflt(0.00000000e+00);
	local[8]= local[2];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,3,local+7); /*<=*/
	if (w==NIL) goto IF3025;
	local[7]= makeflt(0.00000000e+00);
	local[8]= local[3];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,3,local+7); /*<=*/
	if (w==NIL) goto IF3025;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF3026;
IF3025:
	local[7]= NIL;
IF3026:
	goto IF3024;
IF3023:
	local[7]= NIL;
IF3024:
	goto WHL3019;
WHX3020:
	local[7]= NIL;
BLK3021:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK3013:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M3027(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3030;}
	local[0]= loadglobal(fqv[5]);
ENT3030:
ENT3029:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL3032:
	if (local[4]==NIL) goto WHX3033;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[15];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto IF3036;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF3037;
IF3036:
	local[5]= NIL;
IF3037:
	goto WHL3032;
WHX3033:
	local[5]= NIL;
BLK3034:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK3028:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M3038(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF3040;
	local[0]= fqv[17];
	goto IF3041;
IF3040:
	local[0]= argv[0];
	local[1]= fqv[18];
	local[2]= argv[2];
	local[3]= makeflt(9.99999898e+09);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= makeflt(9.99999898e+09);
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,2,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[19]); /*evenp*/
	local[0]= ((w)==NIL?T:NIL);
IF3041:
	w = local[0];
	local[0]= w;
BLK3039:
	ctx->vsp=local; return(local[0]);}

/*:intersect-polygon2d*/
static pointer M3042(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF3044;
	local[0]= argv[2];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[10];
WHL3047:
	if (local[5]==NIL) goto WHX3048;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[1] = local[4]->c.obj.iv[1];
	local[2] = local[4]->c.obj.iv[2];
	local[6]= NIL;
	local[7]= local[0];
WHL3052:
	if (local[7]==NIL) goto WHX3053;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[6]->c.obj.iv[1];
	local[11]= local[6]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(*ftab[3])(ctx,4,local+8,&ftab[3],fqv[14]); /*line-intersection*/
	local[3] = w;
	if (local[3]==NIL) goto IF3056;
	local[8]= makeflt(0.00000000e+00);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.00000000e+00);
	local[11]= makeflt(-9.99999698e-04);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,4,local+8,&ftab[5],fqv[22]); /*eps-in-range*/
	if (w==NIL) goto CON3059;
	local[8]= makeflt(0.00000000e+00);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.00000000e+00);
	local[11]= makeflt(-9.99999698e-04);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,4,local+8,&ftab[5],fqv[22]); /*eps-in-range*/
	if (w==NIL) goto CON3059;
	w = T;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK3043;
	goto CON3058;
CON3059:
	local[8]= NIL;
CON3058:
	goto IF3057;
IF3056:
	local[8]= NIL;
IF3057:
	goto WHL3052;
WHX3053:
	local[8]= NIL;
BLK3054:
	w = NIL;
	goto WHL3047;
WHX3048:
	local[6]= NIL;
BLK3049:
	w = NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= NIL;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL3061:
	if (local[9]==NIL) goto WHX3062;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[2];
	local[11]= fqv[23];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[4];
	if (T!=local[10]) goto CON3066;
	w = T;
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3043;
	goto CON3065;
CON3066:
	local[10]= local[4];
	if (NIL!=local[10]) goto CON3067;
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[10]= local[6];
	goto CON3065;
CON3067:
	local[10]= local[4];
	if (fqv[17]!=local[10]) goto CON3068;
	local[7] = (pointer)((integer_t)(local[7])+4);
	local[10]= local[7];
	goto CON3065;
CON3068:
	local[10]= NIL;
CON3065:
	goto WHL3061;
WHX3062:
	local[10]= NIL;
BLK3063:
	w = NIL;
	local[8]= NIL;
	local[9]= argv[2];
	local[10]= fqv[24];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL3070:
	if (local[9]==NIL) goto WHX3071;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= fqv[23];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[4];
	if (T!=local[10]) goto CON3075;
	w = T;
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3043;
	goto CON3074;
CON3075:
	local[10]= local[4];
	if (NIL!=local[10]) goto CON3076;
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[10]= local[6];
	goto CON3074;
CON3076:
	local[10]= local[4];
	if (fqv[17]!=local[10]) goto CON3077;
	local[7] = (pointer)((integer_t)(local[7])+4);
	local[10]= local[7];
	goto CON3074;
CON3077:
	local[10]= NIL;
CON3074:
	goto WHL3070;
WHX3071:
	local[10]= NIL;
BLK3072:
	w = NIL;
	local[8]= local[7];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF3078;
	local[8]= fqv[17];
	goto IF3079;
IF3078:
	local[8]= NIL;
IF3079:
	w = local[8];
	local[0]= w;
	goto IF3045;
IF3044:
	local[0]= NIL;
IF3045:
	w = local[0];
	local[0]= w;
BLK3043:
	ctx->vsp=local; return(local[0]);}

/*:distance-point*/
static pointer M3080(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[25]);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[26];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,3,local+1,&ftab[6],fqv[27]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK3081:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M3082(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= loadglobal(fqv[5]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON3085;
	local[1]= fqv[17];
	goto CON3084;
CON3085:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w==NIL) goto CON3086;
	local[1]= fqv[29];
	goto CON3084;
CON3086:
	local[1]= local[0];
	goto CON3084;
CON3087:
	local[1]= NIL;
CON3084:
	w = local[1];
	local[0]= w;
BLK3083:
	ctx->vsp=local; return(local[0]);}

/*:3d*/
static pointer M3088(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3092;}
	local[0]= makeflt(0.00000000e+00);
ENT3092:
	if (n>=4) { local[1]=(argv[3]); goto ENT3091;}
	local[1]= loadglobal(fqv[30]);
ENT3091:
ENT3090:
	if (n>4) maerror();
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[4];
	local[5]= fqv[24];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO3094,env,argv,local);
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)BUTLAST(ctx,1,local+7); /*butlast*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK3089:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3094(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:radius*/
static pointer M3095(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK3096:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3097(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[31];
	local[2]= argv[0];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK3098:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3099(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST3101:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[8] = w;
	local[1]= (pointer)get_sym_func(fqv[33]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[8]));
	local[4]= fqv[4];
	local[5]= fqv[9];
	local[6]= makeint(2);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3100:
	ctx->vsp=local; return(local[0]);}

/*make-polygon2d*/
static pointer F2970(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST3103:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[34]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[4];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK3102:
	ctx->vsp=local; return(local[0]);}

/*make-rectangle*/
static pointer F2971(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeflt(2.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= loadglobal(fqv[34]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[4];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,1,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,2,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,2,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,4,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK3105:
	ctx->vsp=local; return(local[0]);}

/*make-circle*/
static pointer F2972(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST3108:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[35]);
	local[2]= loadglobal(fqv[36]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[4];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK3107:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3109(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3112;}
	local[0]= NIL;
ENT3112:
ENT3111:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3113;
	local[1]= argv[2];
	local[2]= fqv[37];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3114;
IF3113:
	local[1]= NIL;
IF3114:
	local[1]= argv[2];
	local[2]= fqv[38];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3110:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill*/
static pointer M3115(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3118;}
	local[0]= NIL;
ENT3118:
ENT3117:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3119;
	local[1]= argv[2];
	local[2]= fqv[37];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3120;
IF3119:
	local[1]= NIL;
IF3120:
	local[1]= argv[2];
	local[2]= fqv[39];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3116:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___polygon(ctx,n,argv,env)
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
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[34];
	local[1]= fqv[41];
	local[2]= fqv[34];
	local[3]= fqv[42];
	local[4]= loadglobal(fqv[43]);
	local[5]= fqv[44];
	local[6]= fqv[45];
	local[7]= fqv[46];
	local[8]= NIL;
	local[9]= fqv[47];
	local[10]= NIL;
	local[11]= fqv[48];
	local[12]= makeint(-1);
	local[13]= fqv[49];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,13,local+2,&ftab[7],fqv[50]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2973,fqv[24],fqv[34],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2975,fqv[21],fqv[34],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2977,fqv[0],fqv[34],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2983,fqv[54],fqv[34],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2985,fqv[2],fqv[34],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2987,fqv[20],fqv[34],fqv[57]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2991,fqv[58],fqv[34],fqv[59]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2998,fqv[13],fqv[34],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3006,fqv[4],fqv[34],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3012,fqv[18],fqv[34],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3027,fqv[16],fqv[34],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3038,fqv[23],fqv[34],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3042,fqv[65],fqv[34],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3080,fqv[28],fqv[34],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3082,fqv[26],fqv[34],fqv[68]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3088,fqv[69],fqv[34],fqv[70]);
	local[0]= fqv[36];
	local[1]= fqv[41];
	local[2]= fqv[36];
	local[3]= fqv[42];
	local[4]= loadglobal(fqv[43]);
	local[5]= fqv[44];
	local[6]= fqv[71];
	local[7]= fqv[46];
	local[8]= NIL;
	local[9]= fqv[47];
	local[10]= NIL;
	local[11]= fqv[48];
	local[12]= makeint(-1);
	local[13]= fqv[49];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,13,local+2,&ftab[7],fqv[50]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3095,fqv[72],fqv[36],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3097,fqv[74],fqv[36],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3099,fqv[4],fqv[36],fqv[76]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F2970,fqv[78]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F2971,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F2972,fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3109,fqv[74],fqv[34],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3115,fqv[84],fqv[34],fqv[85]);
	local[0]= fqv[86];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[88]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<9; i++) ftab[i]=fcallx;
}
