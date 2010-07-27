/* hid.c :  entry=hid */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "hid.h"
#pragma init (register_hid)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___hid();
extern pointer build_quote_vector();
static register_hid()
  { add_module_initializer("___hid", ___hid);}

static pointer F3122();
static pointer F3124();
static pointer F3125();
static pointer F3126();
static pointer F3127();
static pointer F3128();

/*check-visibility*/
static pointer F3122(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= makeflt(0.00000000e+00);
	w = local[1];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[0],w);
	local[5]= NIL;
	local[6]= loadglobal(fqv[1]);
WHL3132:
	if (local[6]==NIL) goto WHX3133;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[0] = local[5]->c.obj.iv[2];
	local[7]= local[0];
	if (argv[0]==local[7]) goto IF3136;
	local[7]= local[0];
	if (argv[1]==local[7]) goto IF3136;
	local[7]= local[5];
	local[8]= fqv[2];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto IF3136;
	local[7]= local[0];
	local[8]= fqv[3];
	local[9]= argv[2];
	local[10]= argv[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w==NIL) goto IF3136;
	w = NIL;
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK3130;
	goto IF3137;
IF3136:
	local[7]= NIL;
IF3137:
	goto WHL3132;
WHX3133:
	local[7]= NIL;
BLK3134:
	w = NIL;
	local[5]= T;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK3130:
	ctx->vsp=local; return(local[0]);}

/*:edge3*/
static pointer M3139(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK3140:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M3141(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK3142:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M3143(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3144:
	ctx->vsp=local; return(local[0]);}

/*:homo2real*/
static pointer M3145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(makeint(3));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	{ double x,y;
		y=fltval(w); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	local[1]= local[0];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	{ register integer_t i=intval(makeint(3));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	local[4]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[3]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK3146:
	ctx->vsp=local; return(local[0]);}

/*:add-segment*/
static pointer M3147(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3150;}
	local[0]= NIL;
ENT3150:
ENT3149:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(makeint(3));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	local[2]= local[1];
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[2];
	{ register integer_t i=intval(makeint(3));
	  w=makeflt(local[4]->c.fvec.fv[i]);}
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[2])))); x=fltval(local[5]);
		local[5]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[4]);
		local[4]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[1] = w;
	local[2]= local[1];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[2]);
	if (left < right) goto IF3151;}
	local[2]= local[1];
	{ double left,right;
		right=fltval(makeflt(1.00000000e+00)); left=fltval(local[2]);
	if (left > right) goto IF3151;}
	local[2]= argv[2];
	local[3]= local[1];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[5] = cons(ctx,local[2],w);
	local[2]= argv[0]->c.obj.iv[5];
	goto IF3152;
IF3151:
	local[2]= NIL;
IF3152:
	w = local[2];
	local[0]= w;
BLK3148:
	ctx->vsp=local; return(local[0]);}

/*:projected-point*/
static pointer M3153(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK3154:
	ctx->vsp=local; return(local[0]);}

/*:projected-homo-point*/
static pointer M3155(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK3156:
	ctx->vsp=local; return(local[0]);}

/*:intersecting-point*/
static pointer M3157(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2]->c.obj.iv[3];
	local[3]= argv[2]->c.obj.iv[4];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,5,local+0,&ftab[0],fqv[5]); /*line-intersection*/
	local[0]= w;
	if (local[0]==NIL) goto IF3159;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[6];
	local[3]= argv[0];
	local[4]= fqv[7];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3160;
IF3159:
	local[1]= NIL;
IF3160:
	w = local[1];
	local[0]= w;
BLK3158:
	ctx->vsp=local; return(local[0]);}

/*:projected-intersection*/
static pointer M3161(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2]->c.obj.iv[3];
	local[3]= argv[2]->c.obj.iv[4];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,5,local+0,&ftab[0],fqv[5]); /*line-intersection*/
	local[0]= w;
	if (local[0]==NIL) goto IF3163;
	local[1]= argv[0];
	local[2]= fqv[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	if (argv[3]==NIL) goto IF3165;
	local[1]= argv[2];
	local[2]= fqv[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF3166;
IF3165:
	local[1]= NIL;
IF3166:
	goto IF3164;
IF3163:
	local[1]= NIL;
IF3164:
	w = local[1];
	local[0]= w;
BLK3162:
	ctx->vsp=local; return(local[0]);}

/*:sort-segments*/
static pointer M3167(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= (pointer)get_sym_func(fqv[9]);
	local[2]= (pointer)get_sym_func(fqv[10]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,3,local+0); /*sort*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK3168:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M3169(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[11]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3170:
	ctx->vsp=local; return(local[0]);}

/*:contourp*/
static pointer M3172(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK3173:
	ctx->vsp=local; return(local[0]);}

/*:mark-visible-segments*/
static pointer M3174(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[6]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL3177:
	if (local[7]==NIL) goto WHX3178;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[0];
	local[9]= fqv[13];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	{ double x,y;
		y=fltval((w)->c.cons.car); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[3] = w;
	local[8]= argv[0]->c.obj.iv[0];
	local[9]= fqv[6];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	{ double x,y;
		y=fltval((w)->c.cons.car); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	local[9]= local[4];
	local[10]= local[5];
	local[11]= local[1];
	local[12]= local[3];
	local[13]= argv[2];
	ctx->vsp=local+14;
	w=(pointer)F3122(ctx,5,local+9); /*check-visibility*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RPLACA2(ctx,2,local+8); /*rplaca2*/
	local[0] = local[6];
	goto WHL3177;
WHX3178:
	local[8]= NIL;
BLK3179:
	w = NIL;
	local[0]= w;
BLK3175:
	ctx->vsp=local; return(local[0]);}

/*:visible-face*/
static pointer M3181(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[2]= local[0];
	w = loadglobal(fqv[14]);
	if (memq(local[2],w)==NIL) goto IF3183;
	local[2]= local[0];
	goto IF3184;
IF3183:
	local[2]= local[1];
IF3184:
	w = local[2];
	local[0]= w;
BLK3182:
	ctx->vsp=local; return(local[0]);}

/*:collect-segments*/
static pointer M3185(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
WHL3188:
	if (local[6]==NIL) goto WHX3189;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	if (argv[2]!=local[7]) goto IF3192;
	local[7]= argv[0];
	local[8]= fqv[15];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[2] = w;
	local[7]= argv[0];
	local[8]= fqv[15];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[3] = w;
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,2,local+7,&ftab[1],fqv[16]); /*homo-viewport-clip*/
	local[4] = w;
	if (local[4]==NIL) goto IF3194;
	local[7]= local[4];
	w = local[0];
	ctx->vsp=local+8;
	local[0] = cons(ctx,local[7],w);
	local[7]= local[0];
	goto IF3195;
IF3194:
	local[7]= NIL;
IF3195:
	goto IF3193;
IF3192:
	local[7]= NIL;
IF3193:
	local[1] = local[5];
	goto WHL3188;
WHX3189:
	local[7]= NIL;
BLK3190:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK3186:
	ctx->vsp=local; return(local[0]);}

/*:visible-segments*/
static pointer M3196(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= T;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3197:
	ctx->vsp=local; return(local[0]);}

/*:invisible-segments*/
static pointer M3198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3199:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3200(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3203;}
	local[0]= argv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT3203:
ENT3202:
	if (n>5) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	local[1]= argv[3];
	local[2]= fqv[19];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[3];
	local[2]= fqv[19];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[20]); /*homo2normal*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[20]); /*homo2normal*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= makeflt(0.00000000e+00);
	local[2]= makeflt(0.00000000e+00);
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	local[2]= makeflt(1.00000000e+00);
	local[3]= makeflt(1.00000000e+00);
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= argv[2];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[6] = w;
	w = argv[0];
	local[0]= w;
BLK3201:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3204(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[22], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3206;
	local[0] = NIL;
KEY3206:
	if (n & (1<<1)) goto KEY3207;
	local[1] = NIL;
KEY3207:
	if (n & (1<<2)) goto KEY3208;
	local[2] = NIL;
KEY3208:
	if (n & (1<<3)) goto KEY3209;
	local[3] = NIL;
KEY3209:
	if (n & (1<<4)) goto KEY3210;
	local[4] = NIL;
KEY3210:
	if (local[0]==NIL) goto IF3211;
	argv[0]->c.obj.iv[0] = local[0];
	local[5]= argv[0]->c.obj.iv[0];
	goto IF3212;
IF3211:
	local[5]= NIL;
IF3212:
	if (local[1]==NIL) goto IF3213;
	argv[0]->c.obj.iv[1] = local[1];
	local[5]= argv[0]->c.obj.iv[1];
	goto IF3214;
IF3213:
	local[5]= NIL;
IF3214:
	if (local[2]==NIL) goto IF3215;
	argv[0]->c.obj.iv[2] = local[2];
	local[5]= argv[0]->c.obj.iv[2];
	goto IF3216;
IF3215:
	local[5]= NIL;
IF3216:
	if (local[3]==NIL) goto IF3217;
	argv[0]->c.obj.iv[3] = local[3];
	local[5]= argv[0]->c.obj.iv[3];
	goto IF3218;
IF3217:
	local[5]= NIL;
IF3218:
	if (local[4]==NIL) goto IF3219;
	argv[0]->c.obj.iv[4] = local[4];
	local[5]= argv[0]->c.obj.iv[4];
	goto IF3220;
IF3219:
	local[5]= NIL;
IF3220:
	w = argv[0];
	local[0]= w;
BLK3205:
	ctx->vsp=local; return(local[0]);}

/*:face3d*/
static pointer M3221(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK3222:
	ctx->vsp=local; return(local[0]);}

/*:possibly-hiding*/
static pointer M3223(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[23];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3224:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M3225(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3226:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3227(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[3];
WHL3230:
	if (local[2]==NIL) goto WHX3231;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[1]==NIL) goto IF3234;
	local[3]= local[1];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF3235;
IF3234:
	local[3]= NIL;
IF3235:
	goto WHL3230;
WHX3231:
	local[3]= NIL;
BLK3232:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*flatten*/
	local[0] = w;
	argv[0]->c.obj.iv[2] = argv[2];
	argv[0]->c.obj.iv[1] = argv[3];
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[27];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[28];
	local[3]= makeflt(9.99999791e-03);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[0]->c.obj.iv[1];
	local[2]= makeint(2);
	local[3]= makeflt(1.00000002e+20);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	w = argv[0];
	local[0]= w;
BLK3228:
	ctx->vsp=local; return(local[0]);}

/*make-face-image*/
static pointer F3124(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[29]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[27];
	local[3]= argv[0];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3239,env,argv,local);
	local[5]= argv[0];
	local[6]= fqv[30];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3237:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3239(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[31]); /*gethash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*set-contour-intersections*/
static pointer F3125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
WHL3241:
	if (argv[0]==NIL) goto WHX3242;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= local[0]->c.obj.iv[0];
	local[2]= local[1]->c.obj.iv[3];
	local[3]= local[1]->c.obj.iv[4];
	if (local[2]==NIL) goto IF3245;
	local[4]= local[2]->c.obj.iv[4];
	goto IF3246;
IF3245:
	local[4]= NIL;
IF3246:
	if (local[3]==NIL) goto IF3247;
	local[5]= local[3]->c.obj.iv[4];
	goto IF3248;
IF3247:
	local[5]= NIL;
IF3248:
	local[6]= NIL;
	local[7]= argv[0];
WHL3250:
	if (local[7]==NIL) goto WHX3251;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6]->c.obj.iv[0];
	w = local[4];
	if (memq(local[8],w)!=NIL) goto IF3254;
	local[8]= local[6]->c.obj.iv[0];
	w = local[5];
	if (memq(local[8],w)!=NIL) goto IF3254;
	local[8]= local[0];
	local[9]= fqv[32];
	local[10]= local[6];
	local[11]= T;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto IF3255;
IF3254:
	local[8]= NIL;
IF3255:
	goto WHL3250;
WHX3251:
	local[8]= NIL;
BLK3252:
	w = NIL;
	goto WHL3241;
WHX3242:
	local[0]= NIL;
BLK3243:
	w = local[0];
	local[0]= w;
BLK3240:
	ctx->vsp=local; return(local[0]);}

/*set-non-contour-intersections*/
static pointer F3126(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
WHL3258:
	if (local[1]==NIL) goto WHX3259;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0]->c.obj.iv[0];
	local[3]= local[2]->c.obj.iv[3];
	local[4]= local[2]->c.obj.iv[4];
	if (local[3]==NIL) goto IF3262;
	local[5]= local[3]->c.obj.iv[4];
	goto IF3263;
IF3262:
	local[5]= NIL;
IF3263:
	if (local[4]==NIL) goto IF3264;
	local[6]= local[4]->c.obj.iv[4];
	goto IF3265;
IF3264:
	local[6]= NIL;
IF3265:
	local[7]= NIL;
	local[8]= argv[1];
WHL3267:
	if (local[8]==NIL) goto WHX3268;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7]->c.obj.iv[0];
	w = local[5];
	if (memq(local[9],w)!=NIL) goto IF3271;
	local[9]= local[7]->c.obj.iv[0];
	w = local[6];
	if (memq(local[9],w)!=NIL) goto IF3271;
	local[9]= local[0];
	local[10]= fqv[32];
	local[11]= local[7];
	local[12]= NIL;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	goto IF3272;
IF3271:
	local[9]= NIL;
IF3272:
	goto WHL3267;
WHX3268:
	local[9]= NIL;
BLK3269:
	w = NIL;
	goto WHL3258;
WHX3259:
	local[2]= NIL;
BLK3260:
	w = NIL;
	local[0]= w;
BLK3256:
	ctx->vsp=local; return(local[0]);}

/*curved-edge-image-p*/
static pointer F3127(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[33]);
	if (local[0]==NIL) goto AND3274;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND3274:
	w = local[0];
	local[0]= w;
BLK3273:
	ctx->vsp=local; return(local[0]);}

/*hid2*/
static pointer F3128(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3277;}
	local[0]= NIL;
ENT3277:
ENT3276:
	if (n>3) maerror();
	local[1]= fqv[35];
	local[2]= makeint(100);
	local[3]= fqv[36];
	local[4]= (pointer)get_sym_func(fqv[37]);
	local[5]= fqv[38];
	local[6]= (pointer)get_sym_func(fqv[39]);
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,6,local+1,&ftab[5],fqv[40]); /*make-hash-table*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)RUNTIME(ctx,0,local+3); /*unix:runtime*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	storeglobal(fqv[14],NIL);
	storeglobal(fqv[1],NIL);
	storeglobal(fqv[41],NIL);
	storeglobal(fqv[42],NIL);
	storeglobal(fqv[43],NIL);
	storeglobal(fqv[44],NIL);
	storeglobal(fqv[45],NIL);
	local[8]= NIL;
	storeglobal(fqv[46],local[8]);
	local[8]= NIL;
	local[9]= argv[0];
WHL3279:
	if (local[9]==NIL) goto WHX3280;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[8];
	local[13]= loadglobal(fqv[47]);
	ctx->vsp=local+14;
	w=(pointer)DERIVEDP(ctx,2,local+12); /*derivedp*/
	if (w==NIL) goto IF3283;
	local[12]= local[8];
	local[13]= fqv[48];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	goto IF3284;
IF3283:
	local[12]= NIL;
IF3284:
	local[12]= NIL;
	local[13]= local[8];
	local[14]= loadglobal(fqv[47]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto IF3286;
	local[13]= local[8];
	local[14]= fqv[49];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	goto IF3287;
IF3286:
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
IF3287:
WHL3288:
	if (local[13]==NIL) goto WHX3289;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[12];
	local[15]= fqv[50];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(0.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF3292;
	local[14]= local[12];
	w = local[10];
	ctx->vsp=local+15;
	local[10] = cons(ctx,local[14],w);
	local[14]= local[10];
	goto IF3293;
IF3292:
	local[14]= NIL;
IF3293:
	goto WHL3288;
WHX3289:
	local[14]= NIL;
BLK3290:
	w = NIL;
	local[12]= (pointer)get_sym_func(fqv[51]);
	local[13]= local[10];
	local[14]= fqv[52];
	ctx->vsp=local+15;
	w=(*ftab[6])(ctx,2,local+13,&ftab[6],fqv[53]); /*send-all*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,2,local+12); /*apply*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,1,local+12,&ftab[7],fqv[54]); /*remove-duplicates*/
	local[11] = w;
	local[12]= loadglobal(fqv[42]);
	local[13]= local[8];
	local[14]= fqv[52];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,2,local+13,&ftab[8],fqv[55]); /*set-difference*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	storeglobal(fqv[42],w);
	local[12]= local[11];
	local[13]= loadglobal(fqv[41]);
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	storeglobal(fqv[41],w);
	local[12]= local[10];
	local[13]= loadglobal(fqv[14]);
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	local[12]= w;
	storeglobal(fqv[14],w);
	w = local[12];
	goto WHL3279;
WHX3280:
	local[10]= NIL;
BLK3281:
	w = NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[41]);
WHL3295:
	if (local[9]==NIL) goto WHX3296;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= loadglobal(fqv[56]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[57];
	local[13]= local[8];
	local[14]= argv[1];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	w = local[10];
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[21];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (w==NIL) goto IF3300;
	local[11]= local[10];
	w = loadglobal(fqv[44]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[44],local[11]);
	goto IF3301;
IF3300:
	local[11]= local[10];
	ctx->vsp=local+12;
	w=(pointer)F3127(ctx,1,local+11); /*curved-edge-image-p*/
	if (w!=NIL) goto IF3302;
	local[11]= local[10];
	w = loadglobal(fqv[45]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[45],local[11]);
	goto IF3303;
IF3302:
	local[11]= NIL;
IF3303:
IF3301:
	local[11]= local[8];
	local[12]= local[1];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[9])(ctx,3,local+11,&ftab[9],fqv[58]); /*sethash*/
	goto WHL3295;
WHX3296:
	local[10]= NIL;
BLK3297:
	w = NIL;
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[5] = w;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3304,env,argv,local);
	local[9]= loadglobal(fqv[14]);
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	storeglobal(fqv[1],w);
	local[8]= loadglobal(fqv[44]);
	ctx->vsp=local+9;
	w=(pointer)F3125(ctx,1,local+8); /*set-contour-intersections*/
	local[8]= loadglobal(fqv[45]);
	local[9]= loadglobal(fqv[44]);
	ctx->vsp=local+10;
	w=(pointer)F3126(ctx,2,local+8); /*set-non-contour-intersections*/
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[60];
	local[13]= fqv[61];
	local[14]= fqv[62];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[63];
	local[13]= fqv[61];
	local[14]= fqv[64];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[65];
	local[13]= fqv[61];
	local[14]= fqv[66];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[67];
	local[13]= fqv[61];
	local[14]= fqv[68];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= NIL;
	local[9]= local[4];
WHL3310:
	if (local[9]==NIL) goto WHX3311;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= loadglobal(fqv[44]);
WHL3315:
	if (local[11]==NIL) goto WHX3316;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= fqv[32];
	local[14]= local[8];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	goto WHL3315;
WHX3316:
	local[12]= NIL;
BLK3317:
	w = NIL;
	local[10]= NIL;
	local[11]= loadglobal(fqv[45]);
WHL3320:
	if (local[11]==NIL) goto WHX3321;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= fqv[32];
	local[14]= local[8];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	goto WHL3320;
WHX3321:
	local[12]= NIL;
BLK3322:
	w = NIL;
	goto WHL3310;
WHX3311:
	local[10]= NIL;
BLK3312:
	w = NIL;
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[6] = w;
	local[8]= loadglobal(fqv[44]);
	local[9]= loadglobal(fqv[45]);
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	storeglobal(fqv[69],w);
	local[8]= loadglobal(fqv[69]);
	local[9]= fqv[70];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,2,local+8,&ftab[6],fqv[53]); /*send-all*/
	local[8]= loadglobal(fqv[69]);
	local[9]= fqv[71];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,3,local+8,&ftab[6],fqv[53]); /*send-all*/
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[7] = w;
	local[8]= local[5];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[6];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= local[7];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,1,local+8); /*print*/
	local[0]= w;
BLK3275:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3304(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	local[2]= env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=(pointer)F3124(ctx,3,local+0); /*make-face-image*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___hid(ctx,n,argv,env)
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
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3324;
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[74],w);
	goto IF3325;
IF3324:
	local[0]= fqv[75];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3325:
	local[0]= fqv[76];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[14];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3326;
	local[0]= fqv[14];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[14];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3328;
	local[0]= fqv[14];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3329;
IF3328:
	local[0]= NIL;
IF3329:
	local[0]= fqv[14];
	goto IF3327;
IF3326:
	local[0]= NIL;
IF3327:
	local[0]= fqv[1];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3330;
	local[0]= fqv[1];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[1];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3332;
	local[0]= fqv[1];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3333;
IF3332:
	local[0]= NIL;
IF3333:
	local[0]= fqv[1];
	goto IF3331;
IF3330:
	local[0]= NIL;
IF3331:
	local[0]= fqv[41];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3334;
	local[0]= fqv[41];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3336;
	local[0]= fqv[41];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3337;
IF3336:
	local[0]= NIL;
IF3337:
	local[0]= fqv[41];
	goto IF3335;
IF3334:
	local[0]= NIL;
IF3335:
	local[0]= fqv[44];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3338;
	local[0]= fqv[44];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3340;
	local[0]= fqv[44];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3341;
IF3340:
	local[0]= NIL;
IF3341:
	local[0]= fqv[44];
	goto IF3339;
IF3338:
	local[0]= NIL;
IF3339:
	local[0]= fqv[69];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3342;
	local[0]= fqv[69];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3344;
	local[0]= fqv[69];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3345;
IF3344:
	local[0]= NIL;
IF3345:
	local[0]= fqv[69];
	goto IF3343;
IF3342:
	local[0]= NIL;
IF3343:
	local[0]= fqv[46];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3346;
	local[0]= fqv[46];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3348;
	local[0]= fqv[46];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3349;
IF3348:
	local[0]= NIL;
IF3349:
	local[0]= fqv[46];
	goto IF3347;
IF3346:
	local[0]= NIL;
IF3347:
	local[0]= fqv[45];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3350;
	local[0]= fqv[45];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3352;
	local[0]= fqv[45];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3353;
IF3352:
	local[0]= NIL;
IF3353:
	local[0]= fqv[45];
	goto IF3351;
IF3350:
	local[0]= NIL;
IF3351:
	local[0]= fqv[42];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3354;
	local[0]= fqv[42];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3356;
	local[0]= fqv[42];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3357;
IF3356:
	local[0]= NIL;
IF3357:
	local[0]= fqv[42];
	goto IF3355;
IF3354:
	local[0]= NIL;
IF3355:
	local[0]= fqv[43];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3358;
	local[0]= fqv[43];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3360;
	local[0]= fqv[43];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3361;
IF3360:
	local[0]= NIL;
IF3361:
	local[0]= fqv[43];
	goto IF3359;
IF3358:
	local[0]= NIL;
IF3359:
	local[0]= fqv[33];
	local[1]= fqv[79];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F3122,fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3139,fqv[82],fqv[56],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3141,fqv[25],fqv[56],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3143,fqv[4],fqv[56],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3145,fqv[7],fqv[56],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3147,fqv[8],fqv[56],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3153,fqv[13],fqv[56],fqv[88]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3155,fqv[15],fqv[56],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3157,fqv[90],fqv[56],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3161,fqv[32],fqv[56],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3167,fqv[70],fqv[56],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3169,fqv[94],fqv[56],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3172,fqv[21],fqv[56],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3174,fqv[71],fqv[56],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3181,fqv[98],fqv[56],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3185,fqv[17],fqv[56],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3196,fqv[101],fqv[56],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3198,fqv[103],fqv[56],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3200,fqv[57],fqv[56],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3204,fqv[27],fqv[56],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3221,fqv[107],fqv[29],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3223,fqv[2],fqv[29],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3225,fqv[110],fqv[29],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3227,fqv[27],fqv[29],fqv[112]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[113],module,F3124,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F3125,fqv[116]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[117],module,F3126,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F3127,fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F3128,fqv[122]);
	local[0]= fqv[123];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[125]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
