/* geopack.c :  entry=geopack */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "geopack.h"
#pragma init (register_geopack)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___geopack();
extern pointer build_quote_vector();
static register_geopack()
  { add_module_initializer("___geopack", ___geopack);}

static pointer F71();
static pointer F72();
static pointer F73();
static pointer F74();
static pointer F75();
static pointer F76();
static pointer F77();
static pointer F78();
static pointer F79();
static pointer F80();
static pointer F81();
static pointer F82();
static pointer F83();
static pointer F84();
static pointer F85();
static pointer F86();
static pointer F87();
static pointer F88();
static pointer F89();
static pointer F90();
static pointer F91();
static pointer F92();
static pointer F93();
static pointer F94();
static pointer F95();
static pointer F96();
static pointer F97();
static pointer F98();
static pointer F99();
static pointer F100();
static pointer F101();
static pointer F102();
static pointer F103();
static pointer F106();
static pointer F107();
static pointer F109();
static pointer F113();

/*vplus*/
static pointer F71(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL116:
	if (local[2]==NIL) goto WHX117;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	goto WHL116;
WHX117:
	local[3]= NIL;
BLK118:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK114:
	ctx->vsp=local; return(local[0]);}

/*vector-mean*/
static pointer F72(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F71(ctx,1,local+1); /*vplus*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
BLK120:
	ctx->vsp=local; return(local[0]);}

/*direction-vector*/
static pointer F73(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK121:
	ctx->vsp=local; return(local[0]);}

/*triangle*/
static pointer F74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT124;}
	local[0]= fqv[0];
ENT124:
ENT123:
	if (n>4) maerror();
	local[1]= argv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SCA3PROD(ctx,3,local+1); /*v.**/
	local[0]= w;
BLK122:
	ctx->vsp=local; return(local[0]);}

/*triangle-normal*/
static pointer F75(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK125:
	ctx->vsp=local; return(local[0]);}

/*vector-angle*/
static pointer F76(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT128;}
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
ENT128:
ENT127:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SCA3PROD(ctx,3,local+1); /*v.**/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,2,local+1); /*atan*/
	local[0]= w;
BLK126:
	ctx->vsp=local; return(local[0]);}

/*face-normal-vector*/
static pointer F77(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
WHL130:
	if (local[2]==NIL) goto WHX131;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[5];
	local[1] = w;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[0] = local[1];
	goto WHL130;
WHX131:
	local[5]= NIL;
BLK132:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[5]= local[4];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,2,local+5); /*normalize-vector*/
	local[0]= w;
BLK129:
	ctx->vsp=local; return(local[0]);}

/*farthest*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	local[3]= NIL;
	local[4]= argv[1];
WHL137:
	if (local[4]==NIL) goto WHX138;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VDISTANCE(ctx,2,local+5); /*distance*/
	local[2] = w;
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF141;
	local[0] = local[3];
	local[1] = local[2];
	local[5]= local[1];
	goto IF142;
IF141:
	local[5]= NIL;
IF142:
	goto WHL137;
WHX138:
	local[5]= NIL;
BLK139:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK134:
	ctx->vsp=local; return(local[0]);}

/*farthest-pair*/
static pointer F79(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F78(ctx,2,local+2); /*farthest*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL145:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX146;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[4] = w;
	local[7]= local[4];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)F78(ctx,2,local+7); /*farthest*/
	local[5] = w;
	local[7]= local[4];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)VDISTANCE(ctx,2,local+7); /*distance*/
	local[6] = w;
	local[7]= local[6];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF149;
	local[0] = local[4];
	local[2] = local[5];
	local[3] = local[6];
	local[7]= local[3];
	goto IF150;
IF149:
	local[7]= NIL;
IF150:
	goto WHL145;
WHX146:
	local[7]= NIL;
BLK147:
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[0]= w;
BLK143:
	ctx->vsp=local; return(local[0]);}

/*maxindex*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= argv[0];
	{ register integer_t i=intval(makeint(0));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF152;}
	local[0] = makeint(1);
	local[1]= local[0];
	goto IF153;
IF152:
	local[1]= NIL;
IF153:
	local[1]= argv[0];
	{ register integer_t i=intval(makeint(2));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= argv[0];
	{ register integer_t i=intval(local[0]);
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF154;}
	local[0] = makeint(2);
	local[1]= local[0];
	goto IF155;
IF154:
	local[1]= NIL;
IF155:
	w = local[0];
	local[0]= w;
BLK151:
	ctx->vsp=local; return(local[0]);}

/*random-vector*/
static pointer F81(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT158;}
	local[0]= makeflt(1.00000000e+00);
ENT158:
ENT157:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0]= w;
BLK156:
	ctx->vsp=local; return(local[0]);}

/*random-normalized-vector*/
static pointer F82(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeflt(1.00000000e+00);
	ctx->vsp=local+1;
	w=(pointer)RANDOM(ctx,1,local+0); /*random*/
	local[0]= w;
	local[1]= makeflt(1.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)RANDOM(ctx,1,local+1); /*random*/
	local[1]= w;
	local[2]= makeflt(1.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK159:
	ctx->vsp=local; return(local[0]);}

/*random-vector2*/
static pointer F83(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT162;}
	local[0]= makeflt(1.00000000e+00);
	ctx->vsp=local+1;
	w=(pointer)RANDOM(ctx,1,local+0); /*random*/
	local[0]= w;
ENT162:
ENT161:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint(1);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= makeflt(6.28318405e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(pointer)ROTVEC(ctx,3,local+2); /*rotate-vector*/
	local[2]= w;
	local[3]= makeflt(6.28318405e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)ROTVEC(ctx,3,local+2); /*rotate-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[0]= w;
BLK160:
	ctx->vsp=local; return(local[0]);}

/*random-vectors*/
static pointer F84(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF164;
	local[0]= NIL;
	goto IF165;
IF164:
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F81(ctx,1,local+0); /*random-vector*/
	local[0]= w;
	local[1]= (pointer)((integer_t)(argv[0])-4);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F84(ctx,2,local+1); /*random-vectors*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
IF165:
	w = local[0];
	local[0]= w;
BLK163:
	ctx->vsp=local; return(local[0]);}

/*edgep*/
static pointer F85(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK166:
	ctx->vsp=local; return(local[0]);}

/*facep*/
static pointer F86(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK167:
	ctx->vsp=local; return(local[0]);}

/*bodyp*/
static pointer F87(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK168:
	ctx->vsp=local; return(local[0]);}

/*primitive-body-p*/
static pointer F88(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F87(ctx,1,local+0); /*bodyp*/
	local[0]= w;
	if (w==NIL) goto AND170;
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND170:
	w = local[0];
	local[0]= w;
BLK169:
	ctx->vsp=local; return(local[0]);}

/*n^2*/
static pointer F89(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK171:
	ctx->vsp=local; return(local[0]);}

/*eps=*/
static pointer F90(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT174;}
	local[0]= loadglobal(fqv[7]);
ENT174:
ENT173:
	if (n>3) maerror();
	local[1]= argv[0];
	{ double x,y;
		y=fltval(argv[1]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	local[1]= makeflt((double)fabs(fltval(local[1])));
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK172:
	ctx->vsp=local; return(local[0]);}

/*eps<*/
static pointer F91(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT177;}
	local[0]= loadglobal(fqv[7]);
ENT177:
ENT176:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK175:
	ctx->vsp=local; return(local[0]);}

/*eps>*/
static pointer F92(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT180;}
	local[0]= loadglobal(fqv[7]);
ENT180:
ENT179:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	local[0]= w;
BLK178:
	ctx->vsp=local; return(local[0]);}

/*eps<=*/
static pointer F93(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT183;}
	local[0]= loadglobal(fqv[7]);
ENT183:
ENT182:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK181:
	ctx->vsp=local; return(local[0]);}

/*eps>=*/
static pointer F94(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT186;}
	local[0]= loadglobal(fqv[7]);
ENT186:
ENT185:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	local[0]= w;
BLK184:
	ctx->vsp=local; return(local[0]);}

/*eps<>*/
static pointer F95(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT189;}
	local[0]= loadglobal(fqv[7]);
ENT189:
ENT188:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90(ctx,3,local+1); /*eps=*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK187:
	ctx->vsp=local; return(local[0]);}

/*eps-zero*/
static pointer F96(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT192;}
	local[0]= loadglobal(fqv[7]);
ENT192:
ENT191:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK190:
	ctx->vsp=local; return(local[0]);}

/*eps-in-range*/
static pointer F97(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT195;}
	local[0]= loadglobal(fqv[7]);
ENT195:
ENT194:
	if (n>4) maerror();
	local[1]= argv[0];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	local[2]= argv[1];
	local[3]= argv[2];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	ctx->vsp=local+4;
	w=(pointer)LSEQP(ctx,3,local+1); /*<=*/
	local[0]= w;
BLK193:
	ctx->vsp=local; return(local[0]);}

/*eps-v=*/
static pointer F98(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT198;}
	local[0]= loadglobal(fqv[7]);
ENT198:
ENT197:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK196:
	ctx->vsp=local; return(local[0]);}

/*eps-coords=*/
static pointer F99(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT202;}
	local[0]= loadglobal(fqv[7]);
ENT202:
	if (n>=4) { local[1]=(argv[3]); goto ENT201;}
	local[1]= local[0];
ENT201:
ENT200:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[8]); /*coordinates-distance*/
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	local[4]= w;
	if (w==NIL) goto AND203;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (((w)->c.cons.car)==NIL?T:NIL);
	if (local[4]!=NIL) goto OR204;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	local[4]= w;
OR204:
AND203:
	w = local[4];
	local[0]= w;
BLK199:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M205(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT208;}
	local[0]= NIL;
ENT208:
ENT207:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF209;
	local[1]= argv[0];
	local[2]= fqv[9];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF210;
IF209:
	local[1]= argv[0];
IF210:
	w = local[1];
	local[0]= w;
BLK206:
	ctx->vsp=local; return(local[0]);}

/*:minpoint*/
static pointer M211(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK212:
	ctx->vsp=local; return(local[0]);}

/*:maxpoint*/
static pointer M213(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK214:
	ctx->vsp=local; return(local[0]);}

/*:center*/
static pointer M215(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(5.00000000e-01);
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[10]); /*midpoint*/
	local[0]= w;
BLK216:
	ctx->vsp=local; return(local[0]);}

/*:diagonal*/
static pointer M217(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
BLK218:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M219(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT222;}
	local[0]= T;
ENT222:
ENT221:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[11]));
	local[3]= fqv[12];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= fqv[13];
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK220:
	ctx->vsp=local; return(local[0]);}

/*:inner*/
static pointer M223(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VLESSP(ctx,2,local+0); /*v<*/
	local[0]= w;
	if (w==NIL) goto AND225;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VGREATERP(ctx,2,local+0); /*v>*/
	local[0]= w;
AND225:
	w = local[0];
	local[0]= w;
BLK224:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M226(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT229;}
	local[0]= NIL;
ENT229:
ENT228:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)VMAX(ctx,2,local+1); /*vmax*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMIN(ctx,2,local+2); /*vmin*/
	local[2]= w;
	if (local[0]==NIL) goto IF230;
	local[3]= local[0];
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
	local[3]= local[1];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,3,local+3); /*v-*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	local[3]= w;
	goto IF231;
IF230:
	local[3]= NIL;
IF231:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VLESSP(ctx,2,local+3); /*v<*/
	if (w==NIL) goto IF232;
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[15];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto IF233;
IF232:
	local[3]= NIL;
IF233:
	w = local[3];
	local[0]= w;
BLK227:
	ctx->vsp=local; return(local[0]);}

/*:union*/
static pointer M235(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT238;}
	local[0]= NIL;
ENT238:
ENT237:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[14]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[15];
	local[4]= argv[0]->c.obj.iv[0];
	local[5]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+6;
	w=(pointer)VMIN(ctx,2,local+4); /*vmin*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VMAX(ctx,2,local+5); /*vmax*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK236:
	ctx->vsp=local; return(local[0]);}

/*:intersection-p*/
static pointer M240(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMAX(ctx,2,local+0); /*vmax*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMIN(ctx,2,local+1); /*vmin*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VLESSP(ctx,2,local+0); /*v<*/
	local[0]= w;
BLK241:
	ctx->vsp=local; return(local[0]);}

/*:grow*/
static pointer M242(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT245;}
	local[0]= NIL;
ENT245:
ENT244:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF246;
	local[1]= argv[2];
	local[2]= argv[2];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	goto IF247;
IF246:
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
IF247:
	argv[2] = local[1];
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,3,local+1); /*v-*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	w = argv[0];
	local[0]= w;
BLK243:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M248(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,3,local+1); /***/
	local[0]= w;
BLK249:
	ctx->vsp=local; return(local[0]);}

/*:extream-point*/
static pointer M250(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= loadglobal(fqv[16]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= local[0];
WHL253:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX254;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF256;
	local[6]= argv[0]->c.obj.iv[1];
	goto IF257;
IF256:
	local[6]= argv[0]->c.obj.iv[0];
IF257:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL253;
WHX254:
	local[4]= NIL;
BLK255:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK251:
	ctx->vsp=local; return(local[0]);}

/*:below*/
static pointer M258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT261;}
	local[0]= fqv[17];
ENT261:
ENT260:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[18];
	local[4]= makeflt(-1.00000000e+00);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	local[0]= w;
BLK259:
	ctx->vsp=local; return(local[0]);}

/*:corners*/
static pointer M262(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(2);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[19]); /*expt*/
	local[4]= w;
WHL265:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX266;
	local[5]= loadglobal(fqv[16]);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[1] = w;
	local[5]= makeint(0);
	local[6]= local[2];
WHL269:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX270;
	local[7]= local[1];
	local[8]= local[5];
	local[9]= local[5];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LOGBITP(ctx,2,local+9); /*logbitp*/
	if (w==NIL) goto IF272;
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	goto IF273;
IF272:
	local[9]= argv[0]->c.obj.iv[0];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
IF273:
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,3,local+7); /*aset*/
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL269;
WHX270:
	local[7]= NIL;
BLK271:
	w = NIL;
	local[5]= local[1];
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL265;
WHX266:
	local[5]= NIL;
BLK267:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK263:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M274(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)COPYSEQ(ctx,1,local+1); /*copy-seq*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYSEQ(ctx,1,local+3); /*copy-seq*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(1);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	local[5]= makeint(1);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[3];
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[0];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[20]); /*make-prism*/
	local[0]= w;
BLK275:
	ctx->vsp=local; return(local[0]);}

/*:init2*/
static pointer M276(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT279;}
	local[0]= NIL;
ENT279:
ENT278:
	if (n>5) maerror();
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMIN(ctx,2,local+1); /*vmin*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMAX(ctx,2,local+1); /*vmax*/
	argv[0]->c.obj.iv[1] = w;
	if (local[0]==NIL) goto IF280;
	local[1]= argv[0];
	local[2]= fqv[9];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF281;
IF280:
	local[1]= NIL;
IF281:
	w = argv[0];
	local[0]= w;
BLK277:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M282(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT285;}
	local[0]= NIL;
ENT285:
ENT284:
	if (n>4) maerror();
	local[1]= (pointer)get_sym_func(fqv[21]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= (pointer)get_sym_func(fqv[22]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	argv[0]->c.obj.iv[1] = w;
	if (local[0]==NIL) goto IF286;
	local[1]= argv[0];
	local[2]= fqv[9];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF287;
IF286:
	local[1]= NIL;
IF287:
	w = argv[0];
	local[0]= w;
BLK283:
	ctx->vsp=local; return(local[0]);}

/*make-bounding-box*/
static pointer F100(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT290;}
	local[0]= loadglobal(fqv[23]);
ENT290:
ENT289:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[14]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK288:
	ctx->vsp=local; return(local[0]);}

/*make-big-bounding-box*/
static pointer F101(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeflt(-1.00000002e+20);
	local[1]= makeflt(-1.00000002e+20);
	local[2]= makeflt(-1.00000002e+20);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= makeflt(1.00000002e+20);
	local[2]= makeflt(1.00000002e+20);
	local[3]= makeflt(1.00000002e+20);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F100(ctx,1,local+0); /*make-bounding-box*/
	local[0]= w;
BLK292:
	ctx->vsp=local; return(local[0]);}

/*bounding-box-intersection*/
static pointer F102(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT295;}
	local[0]= loadglobal(fqv[23]);
ENT295:
ENT294:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= argv[0];
WHL298:
	if (local[4]==NIL) goto WHX299;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= fqv[26];
	local[7]= local[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF302;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK293;
	goto IF303;
IF302:
	local[5]= NIL;
IF303:
	goto WHL298;
WHX299:
	local[5]= NIL;
BLK300:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK293:
	ctx->vsp=local; return(local[0]);}

/*bounding-box-union*/
static pointer F103(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT306;}
	local[0]= loadglobal(fqv[23]);
ENT306:
ENT305:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= argv[0];
WHL309:
	if (local[4]==NIL) goto WHX310;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= fqv[27];
	local[7]= local[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	goto WHL309;
WHX310:
	local[5]= NIL;
BLK311:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK304:
	ctx->vsp=local; return(local[0]);}

/*:nvertex*/
static pointer M313(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT316;}
	local[0]= NIL;
ENT316:
ENT315:
	if (n>3) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK314:
	ctx->vsp=local; return(local[0]);}

/*:pvertex*/
static pointer M317(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT320;}
	local[0]= NIL;
ENT320:
ENT319:
	if (n>3) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK318:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M321(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK322:
	ctx->vsp=local; return(local[0]);}

/*:eq*/
static pointer M323(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND325;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
AND325:
	w = local[0];
	local[0]= w;
BLK324:
	ctx->vsp=local; return(local[0]);}

/*:eql*/
static pointer M326(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND329;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
AND329:
	if (local[0]!=NIL) goto OR328;
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND330;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
AND330:
OR328:
	w = local[0];
	local[0]= w;
BLK327:
	ctx->vsp=local; return(local[0]);}

/*:equall*/
static pointer M331(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	if (w==NIL) goto AND334;
	local[0]= argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
AND334:
	if (local[0]!=NIL) goto OR333;
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	if (w==NIL) goto AND335;
	local[0]= argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
AND335:
OR333:
	w = local[0];
	local[0]= w;
BLK332:
	ctx->vsp=local; return(local[0]);}

/*:parameter*/
static pointer M336(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK337:
	ctx->vsp=local; return(local[0]);}

/*:point*/
static pointer M338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[10]); /*midpoint*/
	local[0]= w;
BLK339:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT343;}
	local[0]= NIL;
ENT343:
ENT342:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[14]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[15];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK341:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M345(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT348;}
	local[0]= NIL;
ENT348:
ENT347:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[25];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[28];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)RECLTREE(ctx,1,local+3); /*system:reclaim-tree*/
	w = local[2];
	local[0]= w;
BLK346:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M349(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
BLK350:
	ctx->vsp=local; return(local[0]);}

/*:end-point*/
static pointer M351(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (argv[2]!=local[0]) goto IF353;
	local[0]= argv[2];
	goto IF354;
IF353:
	local[0]= argv[0]->c.obj.iv[2];
	if (argv[2]!=local[0]) goto IF355;
	local[0]= argv[2];
	goto IF356;
IF355:
	local[0]= NIL;
IF356:
IF354:
	w = local[0];
	local[0]= w;
BLK352:
	ctx->vsp=local; return(local[0]);}

/*:direction*/
static pointer M357(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK358:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M359(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET361,env,argv,local);
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[11]));
	local[3]= fqv[12];
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[1];
	w = local[0];
	ctx->vsp=local+6;
	w=FLET361(ctx,1,local+5,w);
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[2];
	w = local[0];
	ctx->vsp=local+7;
	w=FLET361(ctx,1,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK360:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M362(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[29], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY364;
	local[0] = NIL;
KEY364:
	if (n & (1<<1)) goto KEY365;
	local[1] = NIL;
KEY365:
	if (local[0]==NIL) goto IF366;
	argv[0]->c.obj.iv[1] = local[0];
	local[2]= argv[0]->c.obj.iv[1];
	goto IF367;
IF366:
	local[2]= NIL;
IF367:
	if (local[1]==NIL) goto IF368;
	argv[0]->c.obj.iv[2] = local[1];
	local[2]= argv[0]->c.obj.iv[2];
	goto IF369;
IF368:
	local[2]= NIL;
IF369:
	w = argv[0];
	local[0]= w;
BLK363:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET361(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(30);
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[30]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= fqv[31];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint(0);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL371:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX372;
	local[3]= local[0];
	local[4]= fqv[32];
	local[5]= argv[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL371;
WHX372:
	local[3]= NIL;
BLK373:
	w = NIL;
	local[1]= (pointer)((integer_t)(local[0]->c.obj.iv[3])-4);
	local[2]= local[1];
	w = local[0];
	w->c.obj.iv[3] = local[2];
	local[1]= fqv[33];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[34]); /*get-output-stream-string*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:foot*/
static pointer M376(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK377:
	ctx->vsp=local; return(local[0]);}

/*:common-perpendicular*/
static pointer M378(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= argv[2]->c.obj.iv[2];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[1] = w;
	local[9]= local[1];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[1] = w;
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[2];
	local[11]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[2] = w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[3] = w;
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[4] = w;
	local[9]= local[4];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[4] = w;
	local[9]= local[2];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[0] = w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)ABS(ctx,1,local+9); /*abs*/
	local[9]= w;
	local[10]= loadglobal(fqv[35]);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto IF380;
	w = fqv[36];
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK379;
	goto IF381;
IF380:
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[5] = w;
	local[9]= argv[2]->c.obj.iv[2];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[6] = w;
	local[9]= argv[0];
	local[10]= fqv[37];
	local[11]= local[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[7] = w;
	local[9]= argv[2];
	local[10]= fqv[37];
	local[11]= local[3];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[4];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[8] = w;
	local[9]= local[7];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK379;
IF381:
	w = local[9];
	local[0]= w;
BLK379:
	ctx->vsp=local; return(local[0]);}

/*:distance-point*/
static pointer M382(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON385;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON384;
CON385:
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto CON386;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON384;
CON386:
	local[2]= argv[0];
	local[3]= fqv[37];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON384;
CON387:
	local[2]= NIL;
CON384:
	w = local[2];
	local[0]= w;
BLK383:
	ctx->vsp=local; return(local[0]);}

/*:distance-line*/
static pointer M388(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= *(ovafptr(argv[2],fqv[39]));
	local[1]= *(ovafptr(argv[2],fqv[40]));
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= argv[0]->c.obj.iv[2];
	local[15]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+16;
	w=(pointer)VMINUS(ctx,2,local+14); /*v-*/
	local[14]= w;
	local[15]= local[1];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,2,local+15); /*v-*/
	local[15]= w;
	local[16]= local[14];
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	local[17]= local[14];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)VINNERPRODUCT(ctx,2,local+17); /*v.*/
	local[17]= w;
	local[18]= local[15];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	local[19]= argv[0]->c.obj.iv[1];
	local[20]= local[0];
	ctx->vsp=local+21;
	w=(pointer)VMINUS(ctx,2,local+19); /*v-*/
	local[19]= w;
	local[20]= local[16];
	{ double x,y;
		y=fltval(local[16]); x=fltval(local[20]);
		local[20]=(makeflt(x * y));}
	local[21]= local[17];
	{ double x,y;
		y=fltval(local[18]); x=fltval(local[21]);
		local[21]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[21]); x=fltval(local[20]);
		local[20]=(makeflt(x - y));}
	local[7] = local[20];
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)ABS(ctx,1,local+20); /*abs*/
	local[20]= w;
	local[21]= makeflt(9.99999756e-05);
	ctx->vsp=local+22;
	w=(pointer)GREATERP(ctx,2,local+20); /*>*/
	if (w==NIL) goto IF390;
	local[20]= local[19];
	local[21]= local[14];
	ctx->vsp=local+22;
	w=(pointer)VINNERPRODUCT(ctx,2,local+20); /*v.*/
	local[12] = w;
	local[20]= local[19];
	local[21]= local[15];
	ctx->vsp=local+22;
	w=(pointer)VINNERPRODUCT(ctx,2,local+20); /*v.*/
	local[13] = w;
	local[20]= local[18];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= local[16];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[2] = w;
	local[20]= local[16];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= local[17];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[3] = w;
	local[20]= makeflt(0.00000000e+00);
	local[21]= local[2];
	local[22]= makeflt(1.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,3,local+20); /*<*/
	if (w==NIL) goto IF392;
	local[20]= makeflt(0.00000000e+00);
	local[21]= local[3];
	local[22]= makeflt(1.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,3,local+20); /*<*/
	if (w==NIL) goto IF392;
	local[20]= argv[0];
	local[21]= fqv[37];
	local[22]= local[2];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	local[21]= argv[2];
	local[22]= fqv[37];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)VDISTANCE(ctx,2,local+20); /*distance*/
	ctx->vsp=local+20;
	local[0]=w;
	goto BLK389;
	goto IF393;
IF392:
	local[20]= NIL;
IF393:
	goto IF391;
IF390:
	local[20]= NIL;
IF391:
	local[20]= argv[0];
	local[21]= fqv[41];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[8] = w;
	local[20]= argv[0];
	local[21]= fqv[41];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[9] = w;
	local[20]= argv[2];
	local[21]= fqv[41];
	local[22]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[10] = w;
	local[20]= argv[2];
	local[21]= fqv[41];
	local[22]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[11] = w;
	local[20]= local[8];
	local[21]= local[9];
	local[22]= local[10];
	local[23]= local[11];
	ctx->vsp=local+24;
	w=(pointer)MIN(ctx,4,local+20); /*min*/
	local[0]= w;
BLK389:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M394(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= argv[0];
	local[4]= fqv[38];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
BLK395:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M396(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto CON399;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON398;
CON399:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[43]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON400;
	local[0]= argv[0];
	local[1]= fqv[44];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON398;
CON400:
	local[0]= NIL;
CON398:
	w = local[0];
	local[0]= w;
BLK397:
	ctx->vsp=local; return(local[0]);}

/*:colinear-point*/
static pointer M401(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT404;}
	local[0]= loadglobal(fqv[45]);
ENT404:
ENT403:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,4,local+1,&ftab[7],fqv[46]); /*colinear-p*/
	local[0]= w;
BLK402:
	ctx->vsp=local; return(local[0]);}

/*:on-line-point*/
static pointer M405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT408;}
	local[0]= loadglobal(fqv[45]);
ENT408:
ENT407:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	{ double x,y;
		y=fltval(w); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F93(ctx,3,local+3); /*eps<=*/
	local[0]= w;
BLK406:
	ctx->vsp=local; return(local[0]);}

/*:colinear-line*/
static pointer M409(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT412;}
	local[0]= loadglobal(fqv[45]);
ENT412:
ENT411:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	if (local[3]==NIL) goto AND413;
	local[3]= local[2];
	if (local[3]==NIL) goto AND413;
	local[3]= T;
AND413:
	w = local[3];
	local[0]= w;
BLK410:
	ctx->vsp=local; return(local[0]);}

/*:colinear-line-intersection*/
static pointer M414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[2]->c.obj.iv[2];
	local[2]= argv[0];
	local[3]= fqv[48];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[48];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF416;
	local[6]= local[2];
	local[7]= local[3];
	local[3] = local[6];
	local[2] = local[7];
	w = NIL;
	local[6]= w;
	goto IF417;
IF416:
	local[6]= NIL;
IF417:
	local[6]= local[3];
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w!=NIL) goto OR422;
	local[6]= local[2];
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w!=NIL) goto OR422;
	goto CON421;
OR422:
	local[6]= NIL;
	goto CON420;
CON421:
	local[6]= makeflt(0.00000000e+00);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAX(ctx,2,local+6); /*max*/
	local[4] = w;
	local[6]= makeflt(1.00000000e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[5] = w;
	local[6]= argv[0];
	local[7]= fqv[37];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[37];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F106(ctx,2,local+6); /*make-line*/
	local[6]= w;
	goto CON420;
CON423:
	local[6]= NIL;
CON420:
	w = local[6];
	local[0]= w;
BLK415:
	ctx->vsp=local; return(local[0]);}

/*:coplanar*/
static pointer M424(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT427;}
	local[0]= loadglobal(fqv[45]);
ENT427:
ENT426:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,5,local+1,&ftab[8],fqv[49]); /*coplanar-p*/
	local[0]= w;
BLK425:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M428(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[50];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[50];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK429:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M430(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,4,local+0,&ftab[9],fqv[51]); /*line-intersection3*/
	local[0]= w;
BLK431:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M432(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT435;}
	local[0]= loadglobal(fqv[35]);
ENT435:
ENT434:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,5,local+1,&ftab[9],fqv[51]); /*line-intersection3*/
	local[1]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	if (local[1]!=NIL) goto CON437;
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF438;
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF439;
IF438:
	local[8]= NIL;
IF439:
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[3] = w;
	if (local[3]!=NIL) goto IF440;
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF441;
IF440:
	local[8]= NIL;
IF441:
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF442;
	local[8]= local[3];
	local[9]= local[2];
	local[2] = local[8];
	local[3] = local[9];
	w = NIL;
	local[8]= w;
	goto IF443;
IF442:
	local[8]= NIL;
IF443:
	local[8]= local[3];
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)F91(ctx,2,local+8); /*eps<*/
	if (w!=NIL) goto OR448;
	local[8]= local[2];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)F92(ctx,2,local+8); /*eps>*/
	if (w!=NIL) goto OR448;
	goto IF446;
OR448:
	w = fqv[52];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF447;
IF446:
	local[8]= NIL;
IF447:
	local[8]= argv[2];
	local[9]= fqv[47];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[6] = w;
	local[8]= argv[2];
	local[9]= fqv[47];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[7] = w;
	local[8]= local[7];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF449;
	local[8]= local[7];
	local[9]= local[6];
	local[6] = local[8];
	local[7] = local[9];
	w = NIL;
	local[8]= w;
	goto IF450;
IF449:
	local[8]= NIL;
IF450:
	local[8]= fqv[53];
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MAX(ctx,2,local+9); /*max*/
	local[9]= w;
	local[10]= makeflt(1.00000000e+00);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MIN(ctx,2,local+10); /*min*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	local[10]= makeflt(0.00000000e+00);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MAX(ctx,2,local+10); /*max*/
	local[10]= w;
	local[11]= makeflt(1.00000000e+00);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MIN(ctx,2,local+11); /*min*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	goto CON436;
CON437:
	local[8]= makeflt(0.00000000e+00);
	local[9]= local[2];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)F97(ctx,3,local+8); /*eps-in-range*/
	if (w==NIL) goto CON453;
	local[8]= makeflt(0.00000000e+00);
	local[9]= local[3];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)F97(ctx,3,local+8); /*eps-in-range*/
	if (w==NIL) goto CON453;
	local[8]= fqv[54];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	goto CON436;
CON453:
	local[8]= NIL;
	goto CON436;
CON454:
	local[8]= NIL;
CON436:
	w = local[8];
	local[0]= w;
BLK433:
	ctx->vsp=local; return(local[0]);}

/*make-line*/
static pointer F106(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[43]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[24];
	local[3]= fqv[55];
	local[4]= argv[0];
	local[5]= fqv[56];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK455:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M457(ctx,n,argv,env)
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
BLK458:
	ctx->vsp=local; return(local[0]);}

/*:pvertex*/
static pointer M459(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON462;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON461;
CON462:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON463;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON461;
CON463:
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON461;
CON464:
	local[0]= NIL;
CON461:
	w = local[0];
	local[0]= w;
BLK460:
	ctx->vsp=local; return(local[0]);}

/*:nvertex*/
static pointer M465(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON468;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON467;
CON468:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON469;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON467;
CON469:
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON467;
CON470:
	local[0]= NIL;
CON467:
	w = local[0];
	local[0]= w;
BLK466:
	ctx->vsp=local; return(local[0]);}

/*:next-edge*/
static pointer M471(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[59];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK472:
	ctx->vsp=local; return(local[0]);}

/*:next-vertex*/
static pointer M473(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[59];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[56];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK474:
	ctx->vsp=local; return(local[0]);}

/*:direction*/
static pointer M475(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT478;}
	local[0]= argv[0]->c.obj.iv[3];
ENT478:
ENT477:
	if (n>3) maerror();
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]!=local[1]) goto CON480;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON479;
CON480:
	local[1]= local[0];
	if (argv[0]->c.obj.iv[4]!=local[1]) goto CON481;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON479;
CON481:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F86(ctx,1,local+1); /*facep*/
	if (w==NIL) goto CON482;
	local[1]= NIL;
	local[2]= local[0];
	local[3]= fqv[60];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL484:
	if (local[2]==NIL) goto WHX485;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= local[1];
	local[5]= fqv[61];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (memq(local[3],w)==NIL) goto IF488;
	local[3]= argv[0];
	local[4]= fqv[62];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK476;
	goto IF489;
IF488:
	local[3]= NIL;
IF489:
	goto WHL484;
WHX485:
	local[3]= NIL;
BLK486:
	w = NIL;
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON479;
CON482:
	local[1]= fqv[64];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON479;
CON490:
	local[1]= NIL;
CON479:
	w = local[1];
	local[0]= w;
BLK476:
	ctx->vsp=local; return(local[0]);}

/*:next-edge-angle*/
static pointer M491(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[59];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76(ctx,3,local+0); /*vector-angle*/
	local[0]= w;
BLK492:
	ctx->vsp=local; return(local[0]);}

/*:previous-edge-angle*/
static pointer M493(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[66];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76(ctx,3,local+0); /*vector-angle*/
	local[0]= w;
BLK494:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M495(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto CON498;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON497;
CON498:
	if (argv[0]->c.obj.iv[4]==NIL) goto CON499;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON497;
CON499:
	local[0]= NIL;
CON497:
	w = local[0];
	local[0]= w;
BLK496:
	ctx->vsp=local; return(local[0]);}

/*:pface*/
static pointer M500(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON503;
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON503;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON502;
CON503:
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON504;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON504;
	local[0]= argv[0]->c.obj.iv[4];
	goto CON502;
CON504:
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON502;
CON505:
	local[0]= NIL;
CON502:
	w = local[0];
	local[0]= w;
BLK501:
	ctx->vsp=local; return(local[0]);}

/*:nface*/
static pointer M506(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON509;
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON509;
	local[0]= argv[0]->c.obj.iv[4];
	goto CON508;
CON509:
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON510;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON510;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON508;
CON510:
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON508;
CON511:
	local[0]= NIL;
CON508:
	w = local[0];
	local[0]= w;
BLK507:
	ctx->vsp=local; return(local[0]);}

/*:another-face*/
static pointer M512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto IF514;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF515;
IF514:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto IF516;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF517;
IF516:
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[71]); /*warn*/
	local[0]= w;
IF517:
IF515:
	w = local[0];
	local[0]= w;
BLK513:
	ctx->vsp=local; return(local[0]);}

/*:binormal*/
static pointer M518(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON521;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	goto CON520;
CON521:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON522;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	goto CON520;
CON522:
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= fqv[73];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON520;
CON523:
	local[0]= NIL;
CON520:
	local[1]= argv[2];
	local[2]= fqv[65];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK519:
	ctx->vsp=local; return(local[0]);}

/*:angle*/
static pointer M524(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK525:
	ctx->vsp=local; return(local[0]);}

/*:approximated-p*/
static pointer M526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	w = makeint(1);
	local[0]= (pointer)((integer_t)local[0] & (integer_t)w);
	w = ((makeint(1))==(local[0])?T:NIL);
	local[0]= w;
BLK527:
	ctx->vsp=local; return(local[0]);}

/*:flags*/
static pointer M528(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK529:
	ctx->vsp=local; return(local[0]);}

/*:contourp*/
static pointer M530(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF532;
	if (argv[0]->c.obj.iv[4]==NIL) goto IF532;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[74];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	local[2]= w;
	if (w==NIL) goto AND535;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	local[2]= w;
AND535:
	if (local[2]!=NIL) goto OR534;
	local[2]= local[0];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	local[2]= w;
	if (w==NIL) goto AND536;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	local[2]= w;
AND536:
OR534:
	w = local[2];
	local[0]= w;
	goto IF533;
IF532:
	local[0]= T;
IF533:
	w = local[0];
	local[0]= w;
BLK531:
	ctx->vsp=local; return(local[0]);}

/*:set-approximated-flag*/
static pointer M537(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT540;}
	local[0]= makeflt(6.99999809e-01);
ENT540:
ENT539:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,1,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,3,local+1); /*<*/
	if (w==NIL) goto IF541;
	local[1]= argv[0]->c.obj.iv[6];
	w = makeint(1);
	argv[0]->c.obj.iv[6] = (pointer)((integer_t)local[1] | (integer_t)w);
	local[1]= argv[0]->c.obj.iv[6];
	goto IF542;
IF541:
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)LOGNOT(ctx,1,local+2); /*lognot*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LOGAND(ctx,2,local+1); /*logand*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= argv[0]->c.obj.iv[6];
IF542:
	w = local[1];
	local[0]= w;
BLK538:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M543(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[0] = argv[0]->c.obj.iv[4];
	argv[0]->c.obj.iv[4] = argv[0]->c.obj.iv[3];
	argv[0]->c.obj.iv[3] = local[0];
	w = argv[0]->c.obj.iv[3];
	w = argv[0];
	local[0]= w;
BLK544:
	ctx->vsp=local; return(local[0]);}

/*:set-angle*/
static pointer M545(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[4]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76(ctx,3,local+0); /*vector-angle*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK546:
	ctx->vsp=local; return(local[0]);}

/*:set-face*/
static pointer M547(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON550;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON550;
	argv[0]->c.obj.iv[3] = argv[4];
	local[0]= argv[0]->c.obj.iv[3];
	goto CON549;
CON550:
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON551;
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON551;
	argv[0]->c.obj.iv[4] = argv[4];
	local[0]= argv[0]->c.obj.iv[4];
	goto CON549;
CON551:
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON549;
CON552:
	local[0]= NIL;
CON549:
	w = local[0];
	local[0]= w;
BLK548:
	ctx->vsp=local; return(local[0]);}

/*:contact*/
static pointer M553(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[23]);
	local[2]= loadglobal(fqv[77]);
	local[3]= local[0];
	if (fqv[36]==local[3]) goto IF555;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF557;
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= fqv[48];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto IF557;
	local[3]= makeflt(-1.00000000e+00);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[48];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto IF557;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF558;
IF557:
	local[3]= NIL;
IF558:
	goto IF556;
IF555:
	local[3]= NIL;
IF556:
	w = local[3];
	local[0]= w;
BLK554:
	ctx->vsp=local; return(local[0]);}

/*:neighborpoints*/
static pointer M559(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[78];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(2.00000000e+00);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[78];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= *(ovafptr(argv[0]->c.obj.iv[3],fqv[79]));
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= *(ovafptr(argv[0]->c.obj.iv[4],fqv[79]));
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+4); /*v**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,4,local+0); /*list*/
	local[0]= w;
BLK560:
	ctx->vsp=local; return(local[0]);}

/*:anothervertex*/
static pointer M561(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORM(ctx,1,local+0); /*norm*/
	local[0]= makeflt((double)fabs(fltval(w)));
	local[1]= loadglobal(fqv[80]);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF563;
	local[0]= argv[0]->c.obj.iv[1];
	goto IF564;
IF563:
	local[0]= argv[0]->c.obj.iv[2];
IF564:
	w = local[0];
	local[0]= w;
BLK562:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M565(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT568;}
	local[0]= NIL;
ENT568:
ENT567:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF569;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF570;
IF569:
	local[1]= argv[0];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF571;
	local[1]= local[0];
	goto IF572;
IF571:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
IF572:
IF570:
	w = local[1];
	local[0]= w;
BLK566:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M573(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST575:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[82], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY576;
	local[1] = NIL;
KEY576:
	if (n & (1<<1)) goto KEY577;
	local[2] = NIL;
KEY577:
	if (n & (1<<2)) goto KEY578;
	local[3] = NIL;
KEY578:
	if (n & (1<<3)) goto KEY579;
	local[4] = NIL;
KEY579:
	if (n & (1<<4)) goto KEY580;
	local[5] = makeint(0);
KEY580:
	local[6]= (pointer)get_sym_func(fqv[83]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[11]));
	local[9]= fqv[24];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	if (local[1]==NIL) goto IF581;
	argv[0]->c.obj.iv[3] = local[1];
	local[6]= argv[0]->c.obj.iv[3];
	goto IF582;
IF581:
	local[6]= NIL;
IF582:
	if (local[2]==NIL) goto IF583;
	argv[0]->c.obj.iv[4] = local[2];
	local[6]= argv[0]->c.obj.iv[4];
	goto IF584;
IF583:
	local[6]= NIL;
IF584:
	if (local[3]==NIL) goto IF585;
	argv[0]->c.obj.iv[5] = local[3];
	local[6]= argv[0]->c.obj.iv[5];
	goto IF586;
IF585:
	local[6]= NIL;
IF586:
	argv[0]->c.obj.iv[6] = local[5];
	if (local[4]==NIL) goto IF587;
	local[6]= argv[0];
	local[7]= fqv[84];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF588;
IF587:
	local[6]= NIL;
IF588:
	w = argv[0];
	local[0]= w;
BLK574:
	ctx->vsp=local; return(local[0]);}

/*:center-coordinates*/
static pointer M589(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[85];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	{ double left,right;
		right=fltval(makeflt(9.99999756e-05)); left=fltval(local[1]);
	if (left >= right) goto IF591;}
	local[1]= fqv[86];
	goto IF592;
IF591:
	local[1]= fqv[87];
IF592:
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+2); /*v**/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[1] = w;
	local[3]= loadglobal(fqv[88]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= fqv[89];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,3,local+7,&ftab[11],fqv[90]); /*matrix*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= fqv[91];
	local[9]= makeflt(5.00000000e-01);
	local[10]= argv[0]->c.obj.iv[2];
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)VPLUS(ctx,3,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK590:
	ctx->vsp=local; return(local[0]);}

/*:pwing*/
static pointer M594(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL597:
	if (local[2]==NIL) goto WHX598;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF601;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR603;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR603;
	goto IF601;
OR603:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK595;
	goto IF602;
IF601:
	local[3]= NIL;
IF602:
	goto WHL597;
WHX598:
	local[3]= NIL;
BLK599:
	w = NIL;
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK595:
	ctx->vsp=local; return(local[0]);}

/*:pcwing*/
static pointer M604(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL607:
	if (local[2]==NIL) goto WHX608;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF611;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR613;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR613;
	goto IF611;
OR613:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK605;
	goto IF612;
IF611:
	local[3]= NIL;
IF612:
	goto WHL607;
WHX608:
	local[3]= NIL;
BLK609:
	w = NIL;
	local[1]= fqv[94];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK605:
	ctx->vsp=local; return(local[0]);}

/*:nwing*/
static pointer M614(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL617:
	if (local[2]==NIL) goto WHX618;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF621;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR623;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR623;
	goto IF621;
OR623:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK615;
	goto IF622;
IF621:
	local[3]= NIL;
IF622:
	goto WHL617;
WHX618:
	local[3]= NIL;
BLK619:
	w = NIL;
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK615:
	ctx->vsp=local; return(local[0]);}

/*:ncwing*/
static pointer M624(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL627:
	if (local[2]==NIL) goto WHX628;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF631;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR633;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR633;
	goto IF631;
OR633:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK625;
	goto IF632;
IF631:
	local[3]= NIL;
IF632:
	goto WHL627;
WHX628:
	local[3]= NIL;
BLK629:
	w = NIL;
	local[1]= fqv[96];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK625:
	ctx->vsp=local; return(local[0]);}

/*:connected-vertex*/
static pointer M634(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON637;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON636;
CON637:
	local[0]= argv[2]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON638;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON636;
CON638:
	local[0]= argv[2]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON639;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON636;
CON639:
	local[0]= argv[2]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON640;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON636;
CON640:
	local[0]= fqv[97];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON636;
CON641:
	local[0]= NIL;
CON636:
	w = local[0];
	local[0]= w;
BLK635:
	ctx->vsp=local; return(local[0]);}

/*:replace-face*/
static pointer M642(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON645;
	argv[0]->c.obj.iv[3] = argv[3];
	local[0]= argv[0]->c.obj.iv[3];
	goto CON644;
CON645:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON646;
	argv[0]->c.obj.iv[4] = argv[3];
	local[0]= argv[0]->c.obj.iv[4];
	goto CON644;
CON646:
	local[0]= fqv[98];
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,3,local+0); /*error*/
	local[0]= w;
	goto CON644;
CON647:
	local[0]= NIL;
CON644:
	w = local[0];
	local[0]= w;
BLK643:
	ctx->vsp=local; return(local[0]);}

/*winged-edge-p*/
static pointer F107(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[99]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK648:
	ctx->vsp=local; return(local[0]);}

/*:set-wings*/
static pointer M649(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[100];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[7] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[103];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0];
	local[0]= w;
BLK650:
	ctx->vsp=local; return(local[0]);}

/*:pwing*/
static pointer M651(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK652:
	ctx->vsp=local; return(local[0]);}

/*:nwing*/
static pointer M653(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK654:
	ctx->vsp=local; return(local[0]);}

/*:pcwing*/
static pointer M655(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK656:
	ctx->vsp=local; return(local[0]);}

/*:ncwing*/
static pointer M657(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK658:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M659(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST661:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[104], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY662;
	local[1] = NIL;
KEY662:
	if (n & (1<<1)) goto KEY663;
	local[2] = NIL;
KEY663:
	if (n & (1<<2)) goto KEY664;
	local[3] = NIL;
KEY664:
	if (n & (1<<3)) goto KEY665;
	local[4] = NIL;
KEY665:
	local[5]= (pointer)get_sym_func(fqv[83]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[11]));
	local[8]= fqv[24];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,5,local+5); /*apply*/
	if (local[1]==NIL) goto IF666;
	argv[0]->c.obj.iv[7] = local[1];
	local[5]= argv[0]->c.obj.iv[7];
	goto IF667;
IF666:
	local[5]= NIL;
IF667:
	if (local[2]==NIL) goto IF668;
	argv[0]->c.obj.iv[9] = local[2];
	local[5]= argv[0]->c.obj.iv[9];
	goto IF669;
IF668:
	local[5]= NIL;
IF669:
	if (local[3]==NIL) goto IF670;
	argv[0]->c.obj.iv[8] = local[3];
	local[5]= argv[0]->c.obj.iv[8];
	goto IF671;
IF670:
	local[5]= NIL;
IF671:
	if (local[4]==NIL) goto IF672;
	argv[0]->c.obj.iv[10] = local[4];
	local[5]= argv[0]->c.obj.iv[10];
	goto IF673;
IF672:
	local[5]= NIL;
IF673:
	w = argv[0];
	local[0]= w;
BLK660:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M675(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK676:
	ctx->vsp=local; return(local[0]);}

/*:normal*/
static pointer M677(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK678:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	w = local[0];
	local[0]= w;
BLK680:
	ctx->vsp=local; return(local[0]);}

/*:plane-distance*/
static pointer M681(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	w = local[0];
	local[0]= w;
BLK682:
	ctx->vsp=local; return(local[0]);}

/*:on-plane-p*/
static pointer M683(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT686;}
	local[0]= loadglobal(fqv[7]);
ENT686:
ENT685:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F93(ctx,2,local+1); /*eps<=*/
	local[0]= w;
BLK684:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-point*/
static pointer M687(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT690;}
	local[0]= loadglobal(fqv[45]);
ENT690:
ENT689:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK688:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-line*/
static pointer M691(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT694;}
	local[0]= loadglobal(fqv[45]);
ENT694:
ENT693:
	if (n>4) maerror();
	local[1]= argv[2]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90(ctx,3,local+1); /*eps=*/
	local[1]= w;
	if (w==NIL) goto AND695;
	local[1]= argv[2]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90(ctx,3,local+1); /*eps=*/
	local[1]= w;
AND695:
	w = local[1];
	local[0]= w;
BLK692:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M696(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= local[1];
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[0])))); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= argv[0]->c.obj.iv[2];
	{ double x,y;
		y=fltval(local[1]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0]= w;
BLK697:
	ctx->vsp=local; return(local[0]);}

/*:intersect-edge*/
static pointer M698(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[0];
	local[3]= makeflt(1.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)F97(ctx,3,local+1); /*eps-in-range*/
	if (w==NIL) goto IF700;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[37];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	goto IF701;
IF700:
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR704;
	local[1]= makeflt(1.00000000e+00);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR704;
	goto IF702;
OR704:
	local[1]= T;
	local[2]= fqv[106];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF703;
IF702:
	local[1]= NIL;
IF703:
IF701:
	w = local[1];
	local[0]= w;
BLK699:
	ctx->vsp=local; return(local[0]);}

/*:foot*/
static pointer M705(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	local[1]= argv[2];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK706:
	ctx->vsp=local; return(local[0]);}

/*:original-body*/
static pointer M707(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK708:
	ctx->vsp=local; return(local[0]);}

/*:brightness*/
static pointer M709(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK710:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M711(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT714;}
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
ENT714:
ENT713:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK712:
	ctx->vsp=local; return(local[0]);}

/*:separation*/
static pointer M715(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= argv[2];
WHL718:
	if (local[4]==NIL) goto WHX719;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[74];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= loadglobal(fqv[80]);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF722;
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[107]); /*minusp*/
	if (w==NIL) goto IF724;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK716;
	goto IF725;
IF724:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF726;
	local[1] = local[0];
	local[5]= local[1];
	goto IF727;
IF726:
	local[5]= NIL;
IF727:
IF725:
	goto IF723;
IF722:
	local[5]= NIL;
IF723:
	goto WHL718;
WHX719:
	local[5]= NIL;
BLK720:
	w = NIL;
	local[3]= NIL;
	local[4]= argv[3];
WHL729:
	if (local[4]==NIL) goto WHX730;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[74];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= loadglobal(fqv[80]);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF733;
	local[5]= local[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[107]); /*minusp*/
	if (w==NIL) goto IF735;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK716;
	goto IF736;
IF735:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF737;
	local[2] = local[0];
	local[5]= local[2];
	goto IF738;
IF737:
	local[5]= NIL;
IF738:
IF736:
	goto IF734;
IF733:
	local[5]= NIL;
IF734:
	goto WHL729;
WHX730:
	local[5]= NIL;
BLK731:
	w = NIL;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[12])(ctx,1,local+3,&ftab[12],fqv[107]); /*minusp*/
	if (w==NIL) goto IF739;
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,1,local+3); /*normalize-vector*/
	local[3]= w;
	goto IF740;
IF739:
	local[3]= NIL;
IF740:
	w = local[3];
	local[0]= w;
BLK716:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M741(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto IF743;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	argv[0]->c.obj.iv[2] = makeflt(-(fltval(w)));
	local[0]= argv[0]->c.obj.iv[2];
	goto IF744;
IF743:
	w = argv[3];
	if (!isnum(w)) goto IF745;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)EUSFLOAT(ctx,1,local+0); /*float*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[0]->c.obj.iv[2];
	goto IF746;
IF745:
	local[0]= fqv[108];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF746:
IF744:
	w = argv[0];
	local[0]= w;
BLK742:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M747(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK748:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M749(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK750:
	ctx->vsp=local; return(local[0]);}

/*:edge*/
static pointer M751(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK752:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK754:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M755(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK756:
	ctx->vsp=local; return(local[0]);}

/*:vertex*/
static pointer M757(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK758:
	ctx->vsp=local; return(local[0]);}

/*:next-edge*/
static pointer M759(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[4];
	argv[2] = memq(local[0],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF761;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF762;
IF761:
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF762:
	w = local[0];
	local[0]= w;
BLK760:
	ctx->vsp=local; return(local[0]);}

/*:previous-edge*/
static pointer M763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (argv[2]!=local[0]) goto IF765;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[109]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF766;
IF765:
	local[0]= argv[0]->c.obj.iv[4];
WHL767:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX768;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF770;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK764;
	goto IF771;
IF770:
	local[1]= NIL;
IF771:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	goto WHL767;
WHX768:
	local[1]= NIL;
BLK769:
	w = local[1];
	local[0]= w;
IF766:
	w = local[0];
	local[0]= w;
BLK764:
	ctx->vsp=local; return(local[0]);}

/*:adjacent-faces*/
static pointer M773(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[4];
WHL776:
	if (local[5]==NIL) goto WHX777;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[2] = local[4]->c.obj.iv[3];
	local[3] = local[4]->c.obj.iv[4];
	local[6]= local[2];
	if (argv[0]!=local[6]) goto IF780;
	local[6]= local[3];
	goto IF781;
IF780:
	local[6]= local[2];
IF781:
	w = local[1];
	ctx->vsp=local+7;
	local[1] = cons(ctx,local[6],w);
	goto WHL776;
WHX777:
	local[6]= NIL;
BLK778:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK774:
	ctx->vsp=local; return(local[0]);}

/*:convexp*/
static pointer M782(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK783:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M784(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT787;}
	local[0]= NIL;
ENT787:
ENT786:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[14]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= argv[0]->c.obj.iv[5];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK785:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M789(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT792;}
	local[0]= NIL;
ENT792:
ENT791:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[25];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[26];
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK790:
	ctx->vsp=local; return(local[0]);}

/*:vertices-mean*/
static pointer M794(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F72(ctx,1,local+0); /*vector-mean*/
	local[0]= w;
BLK795:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[110]); /*signum*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF798;
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = fqv[112];
	if (memq(local[2],w)==NIL) goto IF800;
	local[2]= makeflt(0.00000000e+00);
	goto IF801;
IF800:
	local[2]= (pointer)get_sym_func(fqv[113]);
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= fqv[74];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,3,local+3,&ftab[15],fqv[114]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
IF801:
	goto IF799;
IF798:
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[115];
	if (memq(local[3],w)==NIL) goto IF802;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	goto IF803;
IF802:
	local[3]= (pointer)get_sym_func(fqv[113]);
	local[4]= argv[0]->c.obj.iv[4];
	local[5]= fqv[74];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,3,local+4,&ftab[15],fqv[114]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
IF803:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
IF799:
	w = local[2];
	local[0]= w;
BLK797:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F72(ctx,1,local+1); /*vector-mean*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
WHL806:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX807;
	local[3]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)F74(ctx,4,local+4); /*triangle*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	goto WHL806;
WHX807:
	local[3]= NIL;
BLK808:
	local[3]= local[2];
	local[4]= makeflt(2.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0]= w;
BLK805:
	ctx->vsp=local; return(local[0]);}

/*:perimeter*/
static pointer M810(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[116]);
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,2,local+1,&ftab[15],fqv[114]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK811:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M812(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT815;}
	local[0]= fqv[118];
ENT815:
ENT814:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[119];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeflt(-3.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK813:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M816(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT819;}
	local[0]= NIL;
ENT819:
ENT818:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F72(ctx,1,local+4); /*vector-mean*/
	local[4]= w;
	local[5]= makeflt(0.00000000e+00);
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
WHL820:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX821;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[9];
	local[2] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	local[12]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(pointer)F74(ctx,4,local+9); /*triangle*/
	local[5] = w;
	local[9]= local[6];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	local[9]= local[4];
	local[10]= local[8];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	local[9]= local[7];
	local[10]= local[5];
	local[11]= makeflt(3.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	goto WHL820;
WHX821:
	local[9]= NIL;
BLK822:
	local[9]= makeflt(1.00000000e+00);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[7] = w;
	local[9]= local[6];
	local[10]= makeflt(2.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[6] = w;
	if (local[0]==NIL) goto IF824;
	local[9]= local[6];
	local[10]= argv[0];
	local[11]= fqv[105];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= makeflt(-3.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeflt(7.50000000e-01);
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= makeflt(2.50000000e-01);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto IF825;
IF824:
	local[9]= local[6];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
IF825:
	w = local[9];
	local[0]= w;
BLK817:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M826(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT829;}
	local[0]= NIL;
ENT829:
ENT828:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF830;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF831;
IF830:
	local[1]= NIL;
IF831:
	local[1]= argv[0];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0]= w;
BLK827:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M832(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT835;}
	local[0]= loadglobal(fqv[7]);
ENT835:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[7],w);
ENT834:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeflt(0.00000000e+00);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (argv[0]->c.obj.iv[3]==NIL) goto CON837;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[9]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
WHL839:
	if (local[10]==NIL) goto WHX840;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[4];
	local[12]= local[9];
	local[13]= argv[2];
	local[14]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+15;
	w=(pointer)F74(ctx,4,local+11); /*triangle*/
	local[7] = w;
	local[11]= local[7];
	local[12]= local[4];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)VDISTANCE(ctx,2,local+12); /*distance*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)F96(ctx,1,local+11); /*eps-zero*/
	if (w==NIL) goto CON844;
	local[11]= local[9];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)VMINUS(ctx,2,local+12); /*v-*/
	local[12]= w;
	local[13]= local[11];
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= local[11];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)VINNERPRODUCT(ctx,2,local+14); /*v.*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[6] = w;
	local[11]= makeflt(0.00000000e+00);
	local[12]= local[6];
	local[13]= makeflt(1.00000000e+00);
	ctx->vsp=local+14;
	w=(pointer)F97(ctx,3,local+11); /*eps-in-range*/
	if (w==NIL) goto IF845;
	w = fqv[120];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK833;
	goto IF846;
IF845:
	local[11]= NIL;
IF846:
	goto CON843;
CON844:
	local[11]= local[7];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[11]);
	if (left >= right) goto CON847;}
	w = fqv[52];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK833;
	goto CON843;
CON847:
	local[11]= NIL;
CON843:
	local[4] = local[9];
	goto WHL839;
WHX840:
	local[11]= NIL;
BLK841:
	w = NIL;
	local[9]= fqv[121];
	goto CON836;
CON837:
	local[9]= argv[0];
	local[10]= fqv[122];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (w==NIL) goto IF849;
	w = fqv[120];
	ctx->vsp=local+9;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK833;
	goto IF850;
IF849:
	local[9]= NIL;
IF850:
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO851,env,argv,local);
	local[10]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[4] = w;
WHL853:
	if (local[8]==NIL) goto WHX854;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[3] = w;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)F76(ctx,3,local+9); /*vector-angle*/
	local[7] = w;
	local[9]= makeflt((double)fabs(fltval(local[7])));
	local[10]= makeflt(3.14159203e+00);
	ctx->vsp=local+11;
	w=(pointer)F90(ctx,2,local+9); /*eps=*/
	if (w==NIL) goto IF857;
	w = fqv[120];
	ctx->vsp=local+9;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK833;
	goto IF858;
IF857:
	local[9]= NIL;
IF858:
	local[9]= local[5];
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[9]);
		local[9]=(makeflt(x + y));}
	local[5] = local[9];
	local[4] = local[3];
	goto WHL853;
WHX854:
	local[9]= NIL;
BLK855:
	local[9]= makeflt((double)fabs(fltval(local[5])));
	{ double left,right;
		right=fltval(makeflt(3.14159203e+00)); left=fltval(local[9]);
	if (left <= right) goto IF859;}
	local[9]= fqv[121];
	goto IF860;
IF859:
	local[9]= fqv[52];
IF860:
	goto CON836;
CON848:
	local[9]= NIL;
CON836:
	w = local[9];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK833:
	ctx->vsp=local; return(local[0]);}

/*:intersect-point-vector*/
static pointer M861(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt((double)fabs(fltval(local[0])));
	local[4]= loadglobal(fqv[35]);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF863;
	w = fqv[123];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK862;
	goto IF864;
IF863:
	local[3]= NIL;
IF864:
	local[3]= makeflt(0.00000000e+00);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[4]);
		local[4]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[4])))); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[1] = w;
	local[3]= local[1];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF865;}
	w = fqv[124];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK862;
	goto IF866;
IF865:
	local[3]= NIL;
IF866:
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK862:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M867(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt(0.00000000e+00);
	local[4]= local[0];
	local[5]= makeflt(1.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)F97(ctx,3,local+3); /*eps-in-range*/
	if (w==NIL) goto IF869;
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[0];
	local[6]= argv[2];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,3,local+5,&ftab[1],fqv[10]); /*midpoint*/
	local[1] = w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[125];
	if (memq(local[3],w)==NIL) goto IF869;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	goto IF870;
IF869:
	local[3]= NIL;
IF870:
	w = local[3];
	local[0]= w;
BLK868:
	ctx->vsp=local; return(local[0]);}

/*:intersect-edge*/
static pointer M871(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[126];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK872:
	ctx->vsp=local; return(local[0]);}

/*:intersect-face*/
static pointer M873(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT876;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[26];
	local[2]= argv[2];
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
ENT876:
ENT875:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[4];
WHL878:
	if (local[2]==NIL) goto WHX879;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[0]==NIL) goto IF882;
	local[3]= local[0];
	local[4]= fqv[28];
	local[5]= local[1];
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF882;
	local[3]= argv[2];
	local[4]= fqv[127];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF882;
	w = T;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK874;
	goto IF883;
IF882:
	local[3]= NIL;
IF883:
	goto WHL878;
WHX879:
	local[3]= NIL;
BLK880:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK874:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO851(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F73(ctx,2,local+0); /*direction-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:visible*/
static pointer M884(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[105];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF886;
	local[0]= argv[0];
	goto IF887;
IF886:
	local[0]= NIL;
IF887:
	w = local[0];
	local[0]= w;
BLK885:
	ctx->vsp=local; return(local[0]);}

/*:transform-normal*/
static pointer M888(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[128];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	argv[0]->c.obj.iv[2] = local[1];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK889:
	ctx->vsp=local; return(local[0]);}

/*:reset-normal*/
static pointer M890(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F77(ctx,1,local+0); /*face-normal-vector*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[1];
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	argv[0]->c.obj.iv[2] = makeflt(-(fltval(w)));
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK891:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M892(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	w=argv[0]->c.obj.iv[5];
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
	argv[0]->c.obj.iv[3] = T;
WHL894:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX895;
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
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)F74(ctx,4,local+1); /*triangle*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF897;
	argv[0]->c.obj.iv[3] = NIL;
	local[0] = NIL;
	local[1]= local[0];
	goto IF898;
IF897:
	local[1]= NIL;
IF898:
	goto WHL894;
WHX895:
	local[1]= NIL;
BLK896:
	w = local[1];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK893:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M900(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	argv[0]->c.obj.iv[5] = w;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	argv[0]->c.obj.iv[4] = w;
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= makeflt(-1.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	argv[0]->c.obj.iv[2] = local[0];
	local[0]= makeflt(-1.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[7]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	argv[0]->c.obj.iv[7] = local[0];
	local[0]= argv[0];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK901:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M902(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[130], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY904;
	local[0] = NIL;
KEY904:
	if (n & (1<<1)) goto KEY905;
	local[1] = NIL;
KEY905:
	if (n & (1<<2)) goto KEY906;
	local[2] = NIL;
KEY906:
	if (n & (1<<3)) goto KEY907;
	local[3] = NIL;
KEY907:
	if (local[1]==NIL) goto CON909;
	argv[0]->c.obj.iv[4] = local[1];
	if (local[0]!=NIL) goto CON911;
	local[4]= NIL;
	local[5]= local[1];
WHL913:
	if (local[5]==NIL) goto WHX914;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[56];
	local[8]= argv[0];
	local[9]= fqv[131];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	goto WHL913;
WHX914:
	local[6]= NIL;
BLK915:
	w = NIL;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[55];
	local[6]= argv[0];
	local[7]= fqv[131];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = local[0];
	ctx->vsp=local+5;
	argv[0]->c.obj.iv[5] = cons(ctx,local[4],w);
	local[4]= argv[0]->c.obj.iv[5];
	goto CON910;
CON911:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[109]); /*last*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON910;
CON917:
	local[4]= NIL;
CON910:
	goto CON908;
CON909:
	if (local[0]==NIL) goto CON918;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[109]); /*last*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	argv[0]->c.obj.iv[5] = w;
WHL919:
	if (local[0]==NIL) goto WHX920;
	local[4]= loadglobal(fqv[132]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[24];
	local[7]= fqv[55];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= fqv[56];
	if (local[0]==NIL) goto IF924;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF925;
IF924:
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
IF925:
	local[11]= fqv[133];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	w = local[4];
	local[4]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	argv[0]->c.obj.iv[4] = cons(ctx,local[4],w);
	goto WHL919;
WHX920:
	local[4]= NIL;
BLK921:
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON908;
CON918:
	local[4]= NIL;
CON908:
	if (local[2]==NIL) goto IF926;
	argv[0]->c.obj.iv[1] = local[2];
	local[4]= argv[0]->c.obj.iv[1];
	goto IF927;
IF926:
	local[4]= argv[0];
	local[5]= fqv[134];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
IF927:
	if (local[3]==NIL) goto IF928;
	argv[0]->c.obj.iv[2] = local[3];
	local[4]= argv[0]->c.obj.iv[2];
	goto IF929;
IF928:
	local[4]= NIL;
IF929:
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[6] = w;
	argv[0]->c.obj.iv[7] = argv[0]->c.obj.iv[2];
	local[4]= argv[0];
	local[5]= fqv[129];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK903:
	ctx->vsp=local; return(local[0]);}

/*:on-vertex*/
static pointer M930(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT933;}
	local[0]= loadglobal(fqv[23]);
ENT933:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[7],w);
ENT932:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
WHL935:
	if (local[6]==NIL) goto WHX936;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)F98(ctx,2,local+7); /*eps-v=*/
	if (w==NIL) goto IF939;
	local[7]= local[5];
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF940;
IF939:
	local[7]= NIL;
IF940:
	goto WHL935;
WHX936:
	local[7]= NIL;
BLK937:
	w = NIL;
	local[5]= local[4];
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK931:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M941(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT944;}
	local[0]= loadglobal(fqv[23]);
ENT944:
ENT943:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
WHL946:
	if (local[4]==NIL) goto WHX947;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[135];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto IF950;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF951;
IF950:
	local[5]= NIL;
IF951:
	goto WHL946;
WHX947:
	local[5]= NIL;
BLK948:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK942:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-distance*/
static pointer M952(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[111];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[137]); /*member*/
	if (w==NIL) goto IF954;
	local[0]= fqv[121];
	goto IF955;
IF954:
	local[0]= (pointer)get_sym_func(fqv[113]);
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,3,local+1,&ftab[15],fqv[114]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
IF955:
	w = local[0];
	local[0]= w;
BLK953:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-intersections*/
static pointer M956(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT959;}
	local[0]= loadglobal(fqv[45]);
ENT959:
ENT958:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F102(ctx,2,local+1); /*bounding-box-intersection*/
	local[1]= w;
	local[2]= NIL;
	if (local[1]!=NIL) goto IF960;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK957;
	goto IF961;
IF960:
	local[3]= NIL;
IF961:
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
WHL963:
	if (local[4]==NIL) goto WHX964;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[2];
	local[9]= fqv[61];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
WHL968:
	if (local[8]==NIL) goto WHX969;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= fqv[126];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[6] = w;
	w = local[6];
	if (!iscons(w)) goto IF972;
	local[9]= local[7];
	w = local[6];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto IF973;
IF972:
	local[9]= NIL;
IF973:
	goto WHL968;
WHX969:
	local[9]= NIL;
BLK970:
	w = NIL;
	if (local[5]==NIL) goto IF974;
	local[7]= local[3];
	w = local[5];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto IF975;
IF974:
	local[7]= NIL;
IF975:
	w = local[7];
	goto WHL963;
WHX964:
	local[5]= NIL;
BLK965:
	w = NIL;
	if (local[2]==NIL) goto IF976;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK957;
	goto IF977;
IF976:
	local[3]= NIL;
IF977:
	local[3]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL979:
	if (local[4]==NIL) goto WHX980;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= fqv[138];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF983;
	local[5]= argv[2];
	local[6]= fqv[111];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	w = fqv[139];
	if (memq(local[5],w)==NIL) goto IF983;
	w = fqv[140];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK957;
	goto IF984;
IF983:
	local[5]= NIL;
IF984:
	goto WHL979;
WHX980:
	local[5]= NIL;
BLK981:
	w = NIL;
	local[3]= NIL;
	local[4]= argv[2];
	local[5]= fqv[141];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL986:
	if (local[4]==NIL) goto WHX987;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= fqv[138];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF990;
	local[5]= argv[0];
	local[6]= fqv[111];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	w = fqv[142];
	if (memq(local[5],w)==NIL) goto IF990;
	w = fqv[143];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK957;
	goto IF991;
IF990:
	local[5]= NIL;
IF991:
	goto WHL986;
WHX987:
	local[5]= NIL;
BLK988:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK957:
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M992(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT995;}
	local[0]= loadglobal(fqv[23]);
ENT995:
ENT994:
	if (n>4) maerror();
	local[1]= argv[2]->c.obj.iv[1];
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[0];
	local[4]= fqv[105];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[105];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR998;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR998;
	local[5]= argv[0];
	local[6]= fqv[144];
	local[7]= argv[2];
	local[8]= makeflt(9.99999698e-04);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto OR998;
	goto CON997;
OR998:
	local[5]= fqv[52];
	goto CON996;
CON997:
	local[5]= argv[0];
	local[6]= fqv[111];
	local[7]= local[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[121];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w!=NIL) goto OR1000;
	local[5]= argv[0];
	local[6]= fqv[111];
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,1,local+5); /*eql*/
	if (w!=NIL) goto OR1000;
	goto CON999;
OR1000:
	local[5]= T;
	goto CON996;
CON999:
	local[5]= NIL;
CON996:
	w = local[5];
	local[0]= w;
BLK993:
	ctx->vsp=local; return(local[0]);}

/*:contact-plane*/
static pointer M1001(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1004;}
	local[0]= loadglobal(fqv[23]);
ENT1004:
ENT1003:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= makeflt(-1.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)F90(ctx,2,local+1); /*eps=*/
	if (w==NIL) goto IF1005;
	local[1]= makeflt(-(fltval(argv[0]->c.obj.iv[2])));
	local[2]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)F90(ctx,2,local+1); /*eps=*/
	if (w==NIL) goto IF1005;
	local[1]= argv[0];
	local[2]= fqv[145];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1006;
IF1005:
	local[1]= NIL;
IF1006:
	w = local[1];
	local[0]= w;
BLK1002:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M1007(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1010;}
	local[0]= loadglobal(fqv[23]);
ENT1010:
ENT1009:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1011;
	local[2]= fqv[52];
	goto IF1012;
IF1011:
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= argv[2];
	local[5]= local[1];
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF1012:
	w = local[2];
	local[0]= w;
BLK1008:
	ctx->vsp=local; return(local[0]);}

/*:contactp*/
static pointer M1013(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1016;}
	local[0]= loadglobal(fqv[23]);
ENT1016:
ENT1015:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto CON1018;
	local[1]= argv[0];
	local[2]= fqv[146];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1017;
CON1018:
	local[1]= argv[2];
	local[2]= loadglobal(fqv[43]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON1019;
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1017;
CON1019:
	local[1]= argv[2];
	local[2]= loadglobal(fqv[148]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON1020;
	local[1]= argv[0];
	local[2]= fqv[149];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1017;
CON1020:
	local[1]= NIL;
CON1017:
	w = local[1];
	local[0]= w;
BLK1014:
	ctx->vsp=local; return(local[0]);}

/*:aligned-plane*/
static pointer M1021(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= fqv[65];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= makeflt(1.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)F90(ctx,2,local+0); /*eps=*/
	if (w==NIL) goto IF1023;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)F90(ctx,2,local+0); /*eps=*/
	if (w==NIL) goto IF1023;
	local[0]= argv[0];
	local[1]= fqv[145];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF1024;
IF1023:
	local[0]= NIL;
IF1024:
	w = local[0];
	local[0]= w;
BLK1022:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M1025(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1028;}
	local[0]= makeflt(9.99999698e-04);
ENT1028:
ENT1027:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[11]));
	local[3]= fqv[111];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[121]==local[2]) goto IF1029;
	local[2]= local[1];
	goto IF1030;
IF1029:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL1032:
	if (local[3]==NIL) goto WHX1033;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[111];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[121]!=local[4]) goto IF1036;
	w = fqv[52];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1026;
	goto IF1037;
IF1036:
	local[4]= local[1];
	if (fqv[120]!=local[4]) goto IF1038;
	w = fqv[120];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1026;
	goto IF1039;
IF1038:
	local[4]= NIL;
IF1039:
IF1037:
	goto WHL1032;
WHX1033:
	local[4]= NIL;
BLK1034:
	w = NIL;
	local[2]= fqv[121];
IF1030:
	w = local[2];
	local[0]= w;
BLK1026:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M1040(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[110]); /*signum*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[150];
	if (memq(local[3],w)==NIL) goto IF1042;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	goto IF1043;
IF1042:
	local[3]= (pointer)get_sym_func(fqv[113]);
	local[4]= argv[0];
	local[5]= fqv[92];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[74];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,3,local+4,&ftab[15],fqv[114]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
IF1043:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[0]= w;
BLK1041:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M1044(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[116]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[119];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
BLK1045:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1046(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1049;}
	local[0]= NIL;
ENT1049:
ENT1048:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[11]));
	local[3]= fqv[151];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,4,local+1); /*send-message*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[151];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,3,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[152]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= (pointer)get_sym_func(fqv[116]);
	local[6]= (pointer)get_sym_func(fqv[153]);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[2];
WHL1051:
	if (local[6]==NIL) goto WHX1052;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[3];
	local[8]= (pointer)get_sym_func(fqv[152]);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,2,local+8); /*apply*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,3,local+7); /*v-*/
	goto WHL1051;
WHX1052:
	local[7]= NIL;
BLK1053:
	w = NIL;
	if (local[0]==NIL) goto IF1055;
	local[5]= local[4];
	local[6]= argv[0];
	local[7]= fqv[105];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= makeflt(-3.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeflt(2.50000000e-01);
	local[7]= makeflt(1.00000000e+00);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,3,local+6,&ftab[1],fqv[10]); /*midpoint*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	goto IF1056;
IF1055:
	local[5]= local[4];
	local[6]= makeflt(1.00000000e+00);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
IF1056:
	w = local[5];
	local[0]= w;
BLK1047:
	ctx->vsp=local; return(local[0]);}

/*:on-vertex*/
static pointer M1057(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1060;}
	local[0]= loadglobal(fqv[23]);
ENT1060:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[7],w);
ENT1059:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= (pointer)get_sym_func(fqv[154]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[11]));
	local[8]= fqv[122];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[7]);
	ctx->vsp=local+11;
	w=(pointer)SENDMESSAGE(ctx,5,local+6); /*send-message*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= fqv[122];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[7]);
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,4,local+7,&ftab[15],fqv[114]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,3,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK1058:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M1061(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1064;}
	local[0]= loadglobal(fqv[23]);
ENT1064:
ENT1063:
	if (n>4) maerror();
	local[1]= (pointer)get_sym_func(fqv[154]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[11]));
	local[4]= fqv[155];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,5,local+2); /*send-message*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[155];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,4,local+3,&ftab[15],fqv[114]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK1062:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M1065(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[156];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[156];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[114]); /*send-all*/
	local[0]= w;
BLK1066:
	ctx->vsp=local; return(local[0]);}

/*:holes*/
static pointer M1067(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1068:
	ctx->vsp=local; return(local[0]);}

/*:enter-hole*/
static pointer M1069(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[8] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1070:
	ctx->vsp=local; return(local[0]);}

/*:transform-normal*/
static pointer M1071(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[157];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[157];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,3,local+0,&ftab[15],fqv[114]); /*send-all*/
	local[0]= w;
BLK1072:
	ctx->vsp=local; return(local[0]);}

/*:reset-normal*/
static pointer M1073(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[11]));
	local[2]= fqv[134];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[134];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[114]); /*send-all*/
	local[0]= w;
BLK1074:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1075(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK1076:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M1077(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= (pointer)get_sym_func(fqv[158]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[61];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK1078:
	ctx->vsp=local; return(local[0]);}

/*:all-vertices*/
static pointer M1079(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= (pointer)get_sym_func(fqv[158]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[141];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK1080:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M1081(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1084;}
	local[0]= NIL;
ENT1084:
ENT1083:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1085;
	argv[0]->c.obj.iv[9] = local[0];
	local[1]= argv[0]->c.obj.iv[9];
	goto IF1086;
IF1085:
	local[1]= argv[0]->c.obj.iv[9];
IF1086:
	w = local[1];
	local[0]= w;
BLK1082:
	ctx->vsp=local; return(local[0]);}

/*:primitive-face*/
static pointer M1087(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1090;}
	local[0]= NIL;
ENT1090:
ENT1089:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1091;
	argv[0]->c.obj.iv[10] = local[0];
	local[1]= argv[0]->c.obj.iv[10];
	goto IF1092;
IF1091:
	local[1]= NIL;
IF1092:
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1088:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body*/
static pointer M1093(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1094:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M1095(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1098;}
	local[0]= NIL;
ENT1098:
ENT1097:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1099;
	argv[0]->c.obj.iv[11] = local[0];
	local[1]= argv[0]->c.obj.iv[11];
	goto IF1100;
IF1099:
	local[1]= argv[0]->c.obj.iv[11];
IF1100:
	w = local[1];
	local[0]= w;
BLK1096:
	ctx->vsp=local; return(local[0]);}

/*:face-id*/
static pointer M1101(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[159];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK1102:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body-type*/
static pointer M1103(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1104:
	ctx->vsp=local; return(local[0]);}

/*:body-type*/
static pointer M1105(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1106:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M1107(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[83]);
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[11]));
	local[3]= fqv[12];
	local[4]= argv[2];
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1109;
	local[5]= argv[0]->c.obj.iv[9];
	local[6]= fqv[160];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	goto IF1110;
IF1109:
	local[5]= fqv[161];
IF1110:
	local[6]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,7,local+0); /*apply*/
	local[0]= w;
BLK1108:
	ctx->vsp=local; return(local[0]);}

/*:copied-primitive-face-p*/
static pointer M1111(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[162];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
BLK1112:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body*/
static pointer M1113(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1114:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1115(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[163], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1117;
	local[0] = NIL;
KEY1117:
	if (n & (1<<1)) goto KEY1118;
	local[1] = NIL;
KEY1118:
	if (n & (1<<2)) goto KEY1119;
	local[2] = NIL;
KEY1119:
	if (n & (1<<3)) goto KEY1120;
	local[3] = NIL;
KEY1120:
	if (n & (1<<4)) goto KEY1121;
	local[4] = NIL;
KEY1121:
	if (n & (1<<5)) goto KEY1122;
	local[5] = NIL;
KEY1122:
	if (n & (1<<6)) goto KEY1123;
	local[6] = NIL;
KEY1123:
	if (n & (1<<7)) goto KEY1124;
	local[7] = argv[0];
KEY1124:
	argv[0]->c.obj.iv[8] = local[4];
	local[8]= local[4];
	local[9]= fqv[131];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,3,local+8,&ftab[15],fqv[114]); /*send-all*/
	if (local[5]==NIL) goto IF1125;
	argv[0]->c.obj.iv[11] = local[5];
	local[8]= argv[0]->c.obj.iv[11];
	goto IF1126;
IF1125:
	local[8]= NIL;
IF1126:
	argv[0]->c.obj.iv[10] = local[7];
	if (local[6]==NIL) goto IF1127;
	argv[0]->c.obj.iv[9] = local[6];
	local[8]= argv[0]->c.obj.iv[9];
	goto IF1128;
IF1127:
	local[8]= NIL;
IF1128:
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[11]));
	local[10]= fqv[24];
	local[11]= fqv[65];
	local[12]= local[0];
	local[13]= fqv[74];
	local[14]= local[1];
	local[15]= fqv[61];
	local[16]= local[2];
	local[17]= fqv[141];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)SENDMESSAGE(ctx,11,local+8); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1116:
	ctx->vsp=local; return(local[0]);}

/*:reflectance*/
static pointer M1129(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1132;}
	local[0]= NIL;
ENT1132:
ENT1131:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1133;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[164];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1134;
IF1133:
	local[3]= argv[0];
	local[4]= fqv[164];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1135;
	local[3]= local[2];
	goto IF1136;
IF1135:
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= fqv[164];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF1136:
IF1134:
	w = local[3];
	local[0]= w;
BLK1130:
	ctx->vsp=local; return(local[0]);}

/*:diffusion*/
static pointer M1137(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1140;}
	local[0]= NIL;
ENT1140:
ENT1139:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1141;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[165];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1142;
IF1141:
	local[3]= argv[0];
	local[4]= fqv[165];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1143;
	local[3]= local[2];
	goto IF1144;
IF1143:
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= fqv[165];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF1144:
IF1142:
	w = local[3];
	local[0]= w;
BLK1138:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1148;}
	local[0]= NIL;
ENT1148:
ENT1147:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1149;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1150;
IF1149:
	local[1]= argv[0];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF1151;
	local[1]= local[0];
	goto IF1152;
IF1151:
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1153;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF1154;
IF1153:
	local[1]= NIL;
IF1154:
IF1152:
IF1150:
	w = local[1];
	local[0]= w;
BLK1146:
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M1155(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[0],fqv[79]));
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= loadglobal(fqv[23]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF1157;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1156;
	goto IF1158;
IF1157:
	local[1]= NIL;
IF1158:
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[92];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL1160:
	if (local[2]==NIL) goto WHX1161;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[166];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF1164;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK1156;
	goto IF1165;
IF1164:
	local[3]= NIL;
IF1165:
	goto WHL1160;
WHX1161:
	local[3]= NIL;
BLK1162:
	w = NIL;
	local[0]= w;
BLK1156:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M1166(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1169;}
	local[0]= loadglobal(fqv[23]);
ENT1169:
ENT1168:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[11]));
	local[3]= fqv[146];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[121]==local[2]) goto IF1170;
	local[2]= local[1];
	goto IF1171;
IF1170:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL1173:
	if (local[3]==NIL) goto WHX1174;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[146];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[121]!=local[4]) goto IF1177;
	w = fqv[52];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1167;
	goto IF1178;
IF1177:
	local[4]= local[1];
	if (fqv[120]!=local[4]) goto IF1179;
	w = fqv[120];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1167;
	goto IF1180;
IF1179:
	local[4]= NIL;
IF1180:
IF1178:
	goto WHL1173;
WHX1174:
	local[4]= NIL;
BLK1175:
	w = NIL;
	local[2]= fqv[121];
IF1171:
	w = local[2];
	local[0]= w;
BLK1167:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1181(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1184;}
	local[0]= NIL;
ENT1184:
ENT1183:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F86(ctx,1,local+1); /*facep*/
	if (w==NIL) goto IF1185;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF1186;
IF1185:
	local[1]= NIL;
IF1186:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1182:
	ctx->vsp=local; return(local[0]);}

/*:hollowed-faces*/
static pointer M1187(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[4];
WHL1190:
	if (local[2]==NIL) goto WHX1191;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[3];
	local[4]= local[1]->c.obj.iv[4];
	local[5]= local[3];
	if (argv[0]->c.obj.iv[8]==local[5]) goto IF1194;
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[167]); /*adjoin*/
	local[0] = w;
	local[5]= local[0];
	goto IF1195;
IF1194:
	local[5]= NIL;
IF1195:
	local[5]= local[4];
	if (argv[0]->c.obj.iv[8]==local[5]) goto IF1196;
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[167]); /*adjoin*/
	local[0] = w;
	local[5]= local[0];
	goto IF1197;
IF1196:
	local[5]= NIL;
IF1197:
	w = local[5];
	goto WHL1190;
WHX1191:
	local[3]= NIL;
BLK1192:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1188:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[168], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1200;
	local[0] = NIL;
KEY1200:
	if (n & (1<<1)) goto KEY1201;
	local[1] = NIL;
KEY1201:
	if (n & (1<<2)) goto KEY1202;
	local[2] = NIL;
KEY1202:
	if (n & (1<<3)) goto KEY1203;
	local[3] = NIL;
KEY1203:
	if (n & (1<<4)) goto KEY1204;
	local[4] = NIL;
KEY1204:
	argv[0]->c.obj.iv[8] = local[4];
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[11]));
	local[7]= fqv[24];
	local[8]= fqv[65];
	local[9]= local[0];
	local[10]= fqv[74];
	local[11]= local[1];
	local[12]= fqv[61];
	local[13]= local[2];
	local[14]= fqv[141];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SENDMESSAGE(ctx,11,local+5); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1199:
	ctx->vsp=local; return(local[0]);}

/*make-plane*/
static pointer F109(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[169], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY1206;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
KEY1206:
	if (n & (1<<1)) goto KEY1207;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[1] = w;
KEY1207:
	if (n & (1<<2)) goto KEY1208;
	local[2] = NIL;
KEY1208:
	w = local[1];
	if (!iscons(w)) goto IF1209;
	local[3]= local[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F77(ctx,2,local+3); /*face-normal-vector*/
	local[0] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= local[1];
	goto IF1210;
IF1209:
	local[3]= NIL;
IF1210:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,1,local+3); /*normalize-vector*/
	local[0] = w;
	if (local[2]==NIL) goto IF1211;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[1] = w;
	local[3]= local[1];
	goto IF1212;
IF1211:
	local[3]= NIL;
IF1212:
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK1205:
	ctx->vsp=local; return(local[0]);}

/*make-polygon*/
static pointer F113(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST1218:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[170]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= fqv[141];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK1217:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___geopack(ctx,n,argv,env)
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
	local[0]= fqv[171];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1220;
	local[0]= fqv[172];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[173],w);
	goto IF1221;
IF1220:
	local[0]= fqv[174];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1221:
	local[0]= fqv[175];
	local[1]= fqv[176];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[177]); /*require*/
	local[0]= fqv[178];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[132];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1222;
	local[0]= fqv[132];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[132];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1224;
	local[0]= fqv[132];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1225;
IF1224:
	local[0]= NIL;
IF1225:
	local[0]= fqv[132];
	goto IF1223;
IF1222:
	local[0]= NIL;
IF1223:
	local[0]= fqv[181];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1226;
	local[0]= fqv[181];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[181];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1228;
	local[0]= fqv[181];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1229;
IF1228:
	local[0]= NIL;
IF1229:
	local[0]= fqv[181];
	goto IF1227;
IF1226:
	local[0]= NIL;
IF1227:
	local[0]= fqv[182];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1230;
	local[0]= fqv[182];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[182];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1232;
	local[0]= fqv[182];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1233;
IF1232:
	local[0]= NIL;
IF1233:
	local[0]= fqv[182];
	goto IF1231;
IF1230:
	local[0]= NIL;
IF1231:
	local[0]= fqv[183];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1234;
	local[0]= fqv[183];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[183];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1236;
	local[0]= fqv[183];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1237;
IF1236:
	local[0]= NIL;
IF1237:
	local[0]= fqv[183];
	goto IF1235;
IF1234:
	local[0]= NIL;
IF1235:
	local[0]= fqv[35];
	local[1]= fqv[184];
	local[2]= makeflt(9.99999791e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[45];
	local[1]= fqv[184];
	local[2]= makeflt(9.99999791e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[7];
	local[1]= fqv[184];
	local[2]= makeflt(4.99999896e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[23];
	local[1]= fqv[184];
	local[2]= makeflt(7.99999759e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[77];
	local[1]= fqv[184];
	local[2]= makeflt(9.99999698e-04);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[80];
	local[1]= fqv[184];
	local[2]= makeflt(9.99999940e-02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[185];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F71,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F72,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F73,fqv[191]);
	local[0]= fqv[192];
	local[1]= fqv[180];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[193];
	local[1]= fqv[180];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F74,fqv[195]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[196],module,F75,fqv[197]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[198],module,F76,fqv[199]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[200],module,F77,fqv[201]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[202],module,F78,fqv[203]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[204],module,F79,fqv[205]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[206],module,F80,fqv[207]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[208],module,F81,fqv[209]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F82,fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F83,fqv[213]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F84,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F85,fqv[217]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F86,fqv[219]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[220],module,F87,fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F88,fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F89,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F90,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F91,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F92,fqv[231]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[232],module,F93,fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F94,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F95,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F96,fqv[239]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[240],module,F97,fqv[241]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[242],module,F98,fqv[243]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[244],module,F99,fqv[245]);
	local[0]= loadglobal(fqv[14]);
	storeglobal(fqv[246],local[0]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M205,fqv[25],fqv[14],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M211,fqv[248],fqv[14],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M213,fqv[250],fqv[14],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M215,fqv[252],fqv[14],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M217,fqv[254],fqv[14],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M219,fqv[12],fqv[14],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M223,fqv[138],fqv[14],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M226,fqv[26],fqv[14],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M235,fqv[27],fqv[14],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M240,fqv[28],fqv[14],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M242,fqv[9],fqv[14],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M248,fqv[262],fqv[14],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M250,fqv[18],fqv[14],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M258,fqv[265],fqv[14],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M262,fqv[267],fqv[14],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M274,fqv[67],fqv[14],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M276,fqv[15],fqv[14],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M282,fqv[24],fqv[14],fqv[271]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F100,fqv[273]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[274],module,F101,fqv[275]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[276],module,F102,fqv[277]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[278],module,F103,fqv[279]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M313,fqv[56],fqv[43],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M317,fqv[55],fqv[43],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M321,fqv[141],fqv[43],fqv[282]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M323,fqv[283],fqv[43],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M326,fqv[285],fqv[43],fqv[286]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M331,fqv[287],fqv[43],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M336,fqv[48],fqv[43],fqv[289]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M338,fqv[37],fqv[43],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M340,fqv[25],fqv[43],fqv[291]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M345,fqv[144],fqv[43],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M349,fqv[117],fqv[43],fqv[293]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M351,fqv[294],fqv[43],fqv[295]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M357,fqv[62],fqv[43],fqv[296]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M359,fqv[12],fqv[43],fqv[297]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M362,fqv[24],fqv[43],fqv[298]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M376,fqv[38],fqv[43],fqv[299]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M378,fqv[76],fqv[43],fqv[300]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M382,fqv[41],fqv[43],fqv[301]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M388,fqv[44],fqv[43],fqv[302]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M394,fqv[74],fqv[43],fqv[303]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M396,fqv[74],fqv[43],fqv[304]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M401,fqv[47],fqv[43],fqv[305]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M405,fqv[135],fqv[43],fqv[306]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M409,fqv[307],fqv[43],fqv[308]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M414,fqv[309],fqv[43],fqv[310]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M424,fqv[311],fqv[43],fqv[312]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M428,fqv[50],fqv[43],fqv[313]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M430,fqv[26],fqv[43],fqv[314]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M432,fqv[126],fqv[43],fqv[315]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[316],module,F106,fqv[317]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M457,fqv[318],fqv[3],fqv[319]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M459,fqv[55],fqv[3],fqv[320]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M465,fqv[56],fqv[3],fqv[321]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M471,fqv[59],fqv[3],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M473,fqv[323],fqv[3],fqv[324]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M475,fqv[62],fqv[3],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M491,fqv[326],fqv[3],fqv[327]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M493,fqv[328],fqv[3],fqv[329]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M495,fqv[67],fqv[3],fqv[330]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M500,fqv[133],fqv[3],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M506,fqv[332],fqv[3],fqv[333]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M512,fqv[334],fqv[3],fqv[335]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M518,fqv[336],fqv[3],fqv[337]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M524,fqv[338],fqv[3],fqv[339]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M526,fqv[340],fqv[3],fqv[341]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M528,fqv[342],fqv[3],fqv[343]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M530,fqv[344],fqv[3],fqv[345]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M537,fqv[84],fqv[3],fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M543,fqv[156],fqv[3],fqv[347]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M545,fqv[348],fqv[3],fqv[349]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M547,fqv[350],fqv[3],fqv[351]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M553,fqv[166],fqv[3],fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M559,fqv[353],fqv[3],fqv[354]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M561,fqv[78],fqv[3],fqv[355]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M565,fqv[81],fqv[3],fqv[356]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M573,fqv[24],fqv[3],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M589,fqv[358],fqv[3],fqv[359]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M594,fqv[100],fqv[3],fqv[360]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M604,fqv[102],fqv[3],fqv[361]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M614,fqv[101],fqv[3],fqv[362]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M624,fqv[103],fqv[3],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M634,fqv[364],fqv[3],fqv[365]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M642,fqv[366],fqv[3],fqv[367]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[368],module,F107,fqv[369]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M649,fqv[370],fqv[99],fqv[371]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M651,fqv[100],fqv[99],fqv[372]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M653,fqv[101],fqv[99],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M655,fqv[102],fqv[99],fqv[374]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M657,fqv[103],fqv[99],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M659,fqv[24],fqv[99],fqv[376]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M675,fqv[377],fqv[148],fqv[378]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M677,fqv[65],fqv[148],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M679,fqv[74],fqv[148],fqv[380]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M681,fqv[105],fqv[148],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M683,fqv[382],fqv[148],fqv[383]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M687,fqv[384],fqv[148],fqv[385]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M691,fqv[386],fqv[148],fqv[387]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M696,fqv[26],fqv[148],fqv[388]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M698,fqv[127],fqv[148],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M705,fqv[38],fqv[148],fqv[390]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M707,fqv[391],fqv[148],fqv[392]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M709,fqv[393],fqv[148],fqv[394]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M711,fqv[50],fqv[148],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M715,fqv[396],fqv[148],fqv[397]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M741,fqv[24],fqv[148],fqv[398]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M747,fqv[131],fqv[170],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M749,fqv[61],fqv[170],fqv[400]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M751,fqv[401],fqv[170],fqv[402]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M753,fqv[92],fqv[170],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M755,fqv[141],fqv[170],fqv[404]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M757,fqv[405],fqv[170],fqv[406]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M759,fqv[59],fqv[170],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M763,fqv[66],fqv[170],fqv[408]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M773,fqv[409],fqv[170],fqv[410]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M782,fqv[411],fqv[170],fqv[412]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M784,fqv[25],fqv[170],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M789,fqv[144],fqv[170],fqv[414]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M794,fqv[415],fqv[170],fqv[416]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M796,fqv[74],fqv[170],fqv[417]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M804,fqv[119],fqv[170],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M810,fqv[419],fqv[170],fqv[420]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M812,fqv[262],fqv[170],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M816,fqv[151],fqv[170],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M826,fqv[81],fqv[170],fqv[423]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M832,fqv[111],fqv[170],fqv[424]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M861,fqv[425],fqv[170],fqv[426]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M867,fqv[126],fqv[170],fqv[427]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M871,fqv[127],fqv[170],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M873,fqv[429],fqv[170],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M884,fqv[431],fqv[170],fqv[432]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M888,fqv[157],fqv[170],fqv[433]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M890,fqv[134],fqv[170],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M892,fqv[129],fqv[170],fqv[435]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M900,fqv[156],fqv[170],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M902,fqv[24],fqv[170],fqv[437]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M930,fqv[122],fqv[170],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M941,fqv[155],fqv[170],fqv[439]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M952,fqv[440],fqv[170],fqv[441]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M956,fqv[145],fqv[170],fqv[442]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M992,fqv[147],fqv[170],fqv[443]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1001,fqv[149],fqv[170],fqv[444]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1007,fqv[146],fqv[170],fqv[445]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1013,fqv[446],fqv[170],fqv[447]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1021,fqv[448],fqv[170],fqv[449]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1025,fqv[111],fqv[4],fqv[450]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1040,fqv[74],fqv[4],fqv[451]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1044,fqv[119],fqv[4],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1046,fqv[151],fqv[4],fqv[453]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1057,fqv[122],fqv[4],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1061,fqv[155],fqv[4],fqv[455]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1065,fqv[156],fqv[4],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1067,fqv[60],fqv[4],fqv[457]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1069,fqv[458],fqv[4],fqv[459]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1071,fqv[157],fqv[4],fqv[460]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1073,fqv[134],fqv[4],fqv[461]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1075,fqv[131],fqv[4],fqv[462]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1077,fqv[92],fqv[4],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1079,fqv[464],fqv[4],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1081,fqv[67],fqv[4],fqv[466]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1087,fqv[467],fqv[4],fqv[468]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1093,fqv[469],fqv[4],fqv[470]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1095,fqv[377],fqv[4],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1101,fqv[472],fqv[4],fqv[473]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1103,fqv[474],fqv[4],fqv[475]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1105,fqv[160],fqv[4],fqv[476]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1107,fqv[12],fqv[4],fqv[477]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1111,fqv[478],fqv[4],fqv[479]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1113,fqv[469],fqv[4],fqv[480]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1115,fqv[24],fqv[4],fqv[481]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1129,fqv[164],fqv[4],fqv[482]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1137,fqv[165],fqv[4],fqv[483]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1145,fqv[81],fqv[4],fqv[484]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1155,fqv[147],fqv[4],fqv[485]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1166,fqv[146],fqv[4],fqv[486]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1181,fqv[131],fqv[487],fqv[488]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1187,fqv[489],fqv[487],fqv[490]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1198,fqv[24],fqv[487],fqv[491]);
	local[0]= fqv[132];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[3]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[181];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[4]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[492];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[487]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[182];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[5]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[493],module,F109,fqv[494]);
	local[0]= fqv[495];
	local[1]= fqv[496];
	ctx->vsp=local+2;
	w=(pointer)F109(ctx,0,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[497];
	local[1]= fqv[496];
	local[2]= fqv[65];
	local[3]= fqv[498];
	ctx->vsp=local+4;
	w=(pointer)F109(ctx,2,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[499];
	local[1]= fqv[496];
	local[2]= fqv[65];
	local[3]= fqv[500];
	ctx->vsp=local+4;
	w=(pointer)F109(ctx,2,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[501],module,F113,fqv[502]);
	local[0]= fqv[503];
	local[1]= fqv[504];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[505]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<20; i++) ftab[i]=fcallx;
}
