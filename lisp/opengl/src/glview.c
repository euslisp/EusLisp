/* glview.c :  entry=glview */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "glview.h"
#pragma init (register_glview)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glview();
extern pointer build_quote_vector();
static register_glview()
  { add_module_initializer("___glview", ___glview);}

static pointer F181();
static pointer F182();
static pointer F183();
static pointer F184();
static pointer F185();

/*:create*/
static pointer M186(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY188;
	local[0] = NIL;
KEY188:
	if (n & (1<<1)) goto KEY189;
	local[8]= makeflt(2.99999952e-01);
	local[9]= makeflt(5.00000000e-01);
	local[10]= makeflt(6.99999809e-01);
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,4,local+8); /*float-vector*/
	local[1] = w;
KEY189:
	if (n & (1<<2)) goto KEY190;
	local[8]= makeflt(9.99999940e-02);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[2] = w;
KEY190:
	if (n & (1<<3)) goto KEY191;
	local[8]= makeflt(1.00000000e+00);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[3] = w;
KEY191:
	if (n & (1<<4)) goto KEY192;
	local[8]= makeflt(1.99999988e-01);
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[4] = w;
KEY192:
	if (n & (1<<5)) goto KEY193;
	local[8]= makeflt(9.99999940e-02);
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[5] = w;
KEY193:
	if (n & (1<<6)) goto KEY194;
	local[6] = makeflt(2.00000000e+01);
KEY194:
	if (n & (1<<7)) goto KEY195;
	local[7] = makeflt(0.00000000e+00);
KEY195:
	if (local[0]==NIL) goto IF196;
	local[8]= argv[0];
	local[9]= fqv[1];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto IF197;
IF196:
	local[8]= NIL;
IF197:
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[2] = w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[3] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[4] = w;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[5] = w;
	argv[0]->c.obj.iv[6] = local[6];
	argv[0]->c.obj.iv[7] = local[7];
	w = argv[0];
	local[0]= w;
BLK187:
	ctx->vsp=local; return(local[0]);}

/*:ambient*/
static pointer M198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT204;}
	local[0]= NIL;
ENT204:
	if (n>=4) { local[1]=(argv[3]); goto ENT203;}
	local[1]= local[0];
ENT203:
	if (n>=5) { local[2]=(argv[4]); goto ENT202;}
	local[2]= local[0];
ENT202:
	if (n>=6) { local[3]=(argv[5]); goto ENT201;}
	local[3]= makeint(1);
ENT201:
ENT200:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON206;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON205;
CON206:
	w = local[0];
	if (!isnum(w)) goto CON207;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON205;
CON207:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON208;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON205;
CON208:
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON205;
CON209:
	local[4]= NIL;
CON205:
	w = local[4];
	local[0]= w;
BLK199:
	ctx->vsp=local; return(local[0]);}

/*:diffuse*/
static pointer M210(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT216;}
	local[0]= NIL;
ENT216:
	if (n>=4) { local[1]=(argv[3]); goto ENT215;}
	local[1]= local[0];
ENT215:
	if (n>=5) { local[2]=(argv[4]); goto ENT214;}
	local[2]= local[0];
ENT214:
	if (n>=6) { local[3]=(argv[5]); goto ENT213;}
	local[3]= makeint(1);
ENT213:
ENT212:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON218;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON217;
CON218:
	w = local[0];
	if (!isnum(w)) goto CON219;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON217;
CON219:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON220;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON217;
CON220:
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON217;
CON221:
	local[4]= NIL;
CON217:
	w = local[4];
	local[0]= w;
BLK211:
	ctx->vsp=local; return(local[0]);}

/*:specular*/
static pointer M222(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT228;}
	local[0]= NIL;
ENT228:
	if (n>=4) { local[1]=(argv[3]); goto ENT227;}
	local[1]= local[0];
ENT227:
	if (n>=5) { local[2]=(argv[4]); goto ENT226;}
	local[2]= local[0];
ENT226:
	if (n>=6) { local[3]=(argv[5]); goto ENT225;}
	local[3]= makeint(1);
ENT225:
ENT224:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON230;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON229;
CON230:
	w = local[0];
	if (!isnum(w)) goto CON231;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON229;
CON231:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON232;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON229;
CON232:
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON229;
CON233:
	local[4]= NIL;
CON229:
	w = local[4];
	local[0]= w;
BLK223:
	ctx->vsp=local; return(local[0]);}

/*:emission*/
static pointer M234(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT240;}
	local[0]= NIL;
ENT240:
	if (n>=4) { local[1]=(argv[3]); goto ENT239;}
	local[1]= local[0];
ENT239:
	if (n>=5) { local[2]=(argv[4]); goto ENT238;}
	local[2]= local[0];
ENT238:
	if (n>=6) { local[3]=(argv[5]); goto ENT237;}
	local[3]= makeint(1);
ENT237:
ENT236:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON242;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON241;
CON242:
	w = local[0];
	if (!isnum(w)) goto CON243;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON241;
CON243:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON244;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON241;
CON244:
	local[4]= fqv[6];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON241;
CON245:
	local[4]= NIL;
CON241:
	w = local[4];
	local[0]= w;
BLK235:
	ctx->vsp=local; return(local[0]);}

/*:shininess*/
static pointer M246(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT249;}
	local[0]= NIL;
ENT249:
ENT248:
	if (n>3) maerror();
	if (local[0]!=NIL) goto CON251;
	local[1]= argv[0]->c.obj.iv[6];
	goto CON250;
CON251:
	w = local[0];
	if (!isnum(w)) goto CON252;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto CON250;
CON252:
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON250;
CON253:
	local[1]= NIL;
CON250:
	w = local[1];
	local[0]= w;
BLK247:
	ctx->vsp=local; return(local[0]);}

/*:transparency*/
static pointer M254(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT257;}
	local[0]= NIL;
ENT257:
ENT256:
	if (n>3) maerror();
	if (local[0]!=NIL) goto CON259;
	local[1]= argv[0]->c.obj.iv[7];
	goto CON258;
CON259:
	w = local[0];
	if (!isnum(w)) goto CON260;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto CON258;
CON260:
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON258;
CON261:
	local[1]= NIL;
CON258:
	w = local[1];
	local[0]= w;
BLK255:
	ctx->vsp=local; return(local[0]);}

/*:opengl*/
static pointer M262(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(1032);
	local[1]= makeint(4608);
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(4609);
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(4610);
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(5632);
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(5633);
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,1,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= w;
BLK263:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY266;
	local[4]= makeflt(5.00000000e-01);
	local[5]= makeflt(5.00000000e-01);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[0] = w;
KEY266:
	if (n & (1<<1)) goto KEY267;
	local[4]= makeflt(7.99999952e-01);
	local[5]= makeflt(7.99999952e-01);
	local[6]= makeflt(7.99999952e-01);
	local[7]= makeflt(7.99999952e-01);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[1] = w;
KEY267:
	if (n & (1<<2)) goto KEY268;
	local[4]= makeflt(6.99999809e-01);
	local[5]= makeflt(6.99999809e-01);
	local[6]= makeflt(6.99999809e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[2] = w;
KEY268:
	if (n & (1<<3)) goto KEY269;
	local[4]= makeflt(1.00000000e+03);
	local[5]= makeflt(2.00000000e+03);
	local[6]= makeflt(1.00000000e+05);
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[3] = w;
KEY269:
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	argv[0]->c.obj.iv[3] = local[1];
	argv[0]->c.obj.iv[4] = local[2];
	argv[0]->c.obj.iv[5] = local[3];
	w = argv[0];
	local[0]= w;
BLK265:
	ctx->vsp=local; return(local[0]);}

/*:light-id*/
static pointer M270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16384);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK271:
	ctx->vsp=local; return(local[0]);}

/*:ambient*/
static pointer M272(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT278;}
	local[0]= NIL;
ENT278:
	if (n>=4) { local[1]=(argv[3]); goto ENT277;}
	local[1]= local[0];
ENT277:
	if (n>=5) { local[2]=(argv[4]); goto ENT276;}
	local[2]= local[0];
ENT276:
	if (n>=6) { local[3]=(argv[5]); goto ENT275;}
	local[3]= makeint(1);
ENT275:
ENT274:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON280;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON279;
CON280:
	w = local[0];
	if (!isnum(w)) goto CON281;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON279;
CON281:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON282;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON279;
CON282:
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON279;
CON283:
	local[4]= NIL;
CON279:
	w = local[4];
	local[0]= w;
BLK273:
	ctx->vsp=local; return(local[0]);}

/*:diffuse*/
static pointer M284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT290;}
	local[0]= NIL;
ENT290:
	if (n>=4) { local[1]=(argv[3]); goto ENT289;}
	local[1]= local[0];
ENT289:
	if (n>=5) { local[2]=(argv[4]); goto ENT288;}
	local[2]= local[0];
ENT288:
	if (n>=6) { local[3]=(argv[5]); goto ENT287;}
	local[3]= makeint(1);
ENT287:
ENT286:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON292;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON291;
CON292:
	w = local[0];
	if (!isnum(w)) goto CON293;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON291;
CON293:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON294;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON291;
CON294:
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON291;
CON295:
	local[4]= NIL;
CON291:
	w = local[4];
	local[0]= w;
BLK285:
	ctx->vsp=local; return(local[0]);}

/*:specular*/
static pointer M296(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT302;}
	local[0]= NIL;
ENT302:
	if (n>=4) { local[1]=(argv[3]); goto ENT301;}
	local[1]= local[0];
ENT301:
	if (n>=5) { local[2]=(argv[4]); goto ENT300;}
	local[2]= local[0];
ENT300:
	if (n>=6) { local[3]=(argv[5]); goto ENT299;}
	local[3]= makeint(1);
ENT299:
ENT298:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON304;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON303;
CON304:
	w = local[0];
	if (!isnum(w)) goto CON305;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON303;
CON305:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON306;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON303;
CON306:
	local[4]= fqv[13];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON303;
CON307:
	local[4]= NIL;
CON303:
	w = local[4];
	local[0]= w;
BLK297:
	ctx->vsp=local; return(local[0]);}

/*:position*/
static pointer M308(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT311;}
	local[0]= NIL;
ENT311:
ENT310:
	if (n>3) maerror();
	if (local[0]!=NIL) goto CON313;
	local[1]= argv[0]->c.obj.iv[5];
	goto CON312;
CON313:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON314;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto CON312;
CON314:
	local[1]= NIL;
CON312:
	w = local[1];
	local[0]= w;
BLK309:
	ctx->vsp=local; return(local[0]);}

/*:move*/
static pointer M315(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)VPLUS(ctx,3,local+0); /*v+*/
	local[0]= w;
BLK316:
	ctx->vsp=local; return(local[0]);}

/*:enable*/
static pointer M317(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= w;
BLK318:
	ctx->vsp=local; return(local[0]);}

/*:disable*/
static pointer M319(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= w;
BLK320:
	ctx->vsp=local; return(local[0]);}

/*:opengl*/
static pointer M321(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16384);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(4608);
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	local[2]= makeint(4609);
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	local[2]= makeint(4610);
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	local[2]= makeint(4611);
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[15]); /*glenable*/
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK322:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M323(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST325:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[18], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY326;
	local[1] = makeint(0);
KEY326:
	if (n & (1<<1)) goto KEY327;
	local[2] = makeint(0);
KEY327:
	if (n & (1<<2)) goto KEY328;
	local[3] = makeint(256);
KEY328:
	if (n & (1<<3)) goto KEY329;
	local[4] = local[3];
KEY329:
	if (n & (1<<4)) goto KEY330;
	local[5] = local[3];
KEY330:
	if (n & (1<<5)) goto KEY331;
	local[7]= fqv[19];
	ctx->vsp=local+8;
	w=(pointer)GENSYM(ctx,1,local+7); /*gensym*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[20]); /*string*/
	local[6] = w;
KEY331:
	local[7]= argv[0];
	local[8]= fqv[21];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[22];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[23];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[24];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= loadglobal(fqv[25]);
	local[8]= loadglobal(fqv[25]);
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,1,local+8,&ftab[6],fqv[26]); /*x:defaultscreen*/
	local[8]= w;
	local[9]= loadglobal(fqv[27]);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,3,local+7,&ftab[7],fqv[28]); /*glxchoosevisual*/
	argv[0]->c.obj.iv[14] = w;
	local[7]= loadglobal(fqv[25]);
	local[8]= argv[0]->c.obj.iv[14];
	local[9]= makeint(0);
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(*ftab[8])(ctx,4,local+7,&ftab[8],fqv[29]); /*glxcreatecontext*/
	argv[0]->c.obj.iv[15] = w;
	local[7]= (pointer)get_sym_func(fqv[30]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[31]));
	local[10]= fqv[32];
	local[11]= fqv[33];
	local[12]= argv[0]->c.obj.iv[14];
	local[13]= makeint(12);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[13]= fqv[34];
	ctx->vsp=local+14;
	w=(pointer)PEEK(ctx,2,local+12); /*system:peek*/
	local[12]= w;
	local[13]= fqv[35];
	local[14]= argv[0]->c.obj.iv[14];
	local[15]= fqv[34];
	ctx->vsp=local+16;
	w=(pointer)PEEK(ctx,2,local+14); /*system:peek*/
	local[14]= w;
	local[15]= fqv[36];
	local[16]= local[6];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,11,local+7); /*apply*/
	local[7]= loadglobal(fqv[25]);
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+10;
	w=(*ftab[9])(ctx,3,local+7,&ftab[9],fqv[37]); /*glxmakecurrent*/
	local[7]= argv[0];
	local[8]= fqv[38];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= loadglobal(fqv[39]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[32];
	local[10]= makeint(0);
	local[11]= fqv[40];
	local[12]= makeflt(1.99999988e-01);
	local[13]= makeflt(1.99999988e-01);
	local[14]= makeflt(1.99999988e-01);
	local[15]= makeflt(0.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,4,local+12); /*float-vector*/
	local[12]= w;
	local[13]= fqv[41];
	local[14]= makeflt(5.00000000e-01);
	local[15]= makeflt(5.00000000e-01);
	local[16]= makeflt(5.00000000e-01);
	local[17]= makeflt(0.00000000e+00);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,4,local+14); /*float-vector*/
	local[14]= w;
	local[15]= fqv[42];
	local[16]= makeflt(2.99999952e-01);
	local[17]= makeflt(2.99999952e-01);
	local[18]= makeflt(2.99999952e-01);
	local[19]= makeflt(0.00000000e+00);
	ctx->vsp=local+20;
	w=(pointer)MKFLTVEC(ctx,4,local+16); /*float-vector*/
	local[16]= w;
	local[17]= fqv[43];
	local[18]= makeflt(0.00000000e+00);
	local[19]= makeflt(0.00000000e+00);
	local[20]= makeflt(1.00000000e+00);
	local[21]= makeflt(0.00000000e+00);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,11,local+8); /*send*/
	w = local[7];
	local[7]= w;
	storeglobal(fqv[44],w);
	local[7]= loadglobal(fqv[39]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[32];
	local[10]= makeint(1);
	local[11]= fqv[40];
	local[12]= makeflt(2.99999952e-01);
	local[13]= makeflt(2.99999952e-01);
	local[14]= makeflt(2.99999952e-01);
	local[15]= makeflt(1.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,4,local+12); /*float-vector*/
	local[12]= w;
	local[13]= fqv[41];
	local[14]= makeflt(5.99999905e-01);
	local[15]= makeflt(9.99999940e-02);
	local[16]= makeflt(9.99999940e-02);
	local[17]= makeflt(7.99999952e-01);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,4,local+14); /*float-vector*/
	local[14]= w;
	local[15]= fqv[42];
	local[16]= makeflt(2.99999952e-01);
	local[17]= makeflt(2.99999952e-01);
	local[18]= makeflt(2.99999952e-01);
	local[19]= makeflt(1.00000000e+00);
	ctx->vsp=local+20;
	w=(pointer)MKFLTVEC(ctx,4,local+16); /*float-vector*/
	local[16]= w;
	local[17]= fqv[43];
	local[18]= makeflt(5.00000000e+03);
	local[19]= makeflt(1.00000000e+03);
	local[20]= makeflt(7.00000000e+03);
	local[21]= makeflt(1.00000000e+00);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,11,local+8); /*send*/
	w = local[7];
	local[7]= w;
	storeglobal(fqv[45],w);
	local[7]= loadglobal(fqv[39]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[32];
	local[10]= makeint(2);
	local[11]= fqv[40];
	local[12]= makeflt(2.99999952e-01);
	local[13]= makeflt(2.99999952e-01);
	local[14]= makeflt(2.99999952e-01);
	local[15]= makeflt(1.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,4,local+12); /*float-vector*/
	local[12]= w;
	local[13]= fqv[41];
	local[14]= makeflt(9.99999940e-02);
	local[15]= makeflt(9.99999940e-02);
	local[16]= makeflt(6.99999809e-01);
	local[17]= makeflt(0.00000000e+00);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,4,local+14); /*float-vector*/
	local[14]= w;
	local[15]= fqv[42];
	local[16]= makeflt(2.99999952e-01);
	local[17]= makeflt(2.99999952e-01);
	local[18]= makeflt(2.99999952e-01);
	local[19]= makeflt(1.00000000e+00);
	ctx->vsp=local+20;
	w=(pointer)MKFLTVEC(ctx,4,local+16); /*float-vector*/
	local[16]= w;
	local[17]= fqv[43];
	local[18]= makeflt(-1.50000000e+04);
	local[19]= makeflt(0.00000000e+00);
	local[20]= makeflt(2.00000000e+03);
	local[21]= makeflt(1.00000000e+00);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,11,local+8); /*send*/
	w = local[7];
	local[7]= w;
	storeglobal(fqv[46],w);
	local[7]= makeint(2896);
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,1,local+7,&ftab[2],fqv[15]); /*glenable*/
	local[7]= loadglobal(fqv[44]);
	local[8]= fqv[47];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= loadglobal(fqv[45]);
	local[8]= fqv[47];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= loadglobal(fqv[46]);
	local[8]= fqv[47];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= makeint(2304);
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[48]); /*glfrontface*/
	local[7]= makeint(3456);
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,1,local+7,&ftab[2],fqv[15]); /*glenable*/
	local[7]= makeint(2977);
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,1,local+7,&ftab[2],fqv[15]); /*glenable*/
	local[7]= makeint(513);
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,1,local+7,&ftab[11],fqv[49]); /*gldepthfunc*/
	local[7]= makeint(2929);
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,1,local+7,&ftab[2],fqv[15]); /*glenable*/
	local[7]= makeint(7425);
	ctx->vsp=local+8;
	w=(*ftab[12])(ctx,1,local+7,&ftab[12],fqv[50]); /*glshademodel*/
	local[7]= makeint(3317);
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[51]); /*glpixelstorei*/
	local[7]= makeint(3553);
	local[8]= makeint(10242);
	local[9]= makeint(10497);
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,3,local+7,&ftab[14],fqv[52]); /*gltexparameteri*/
	local[7]= makeint(3553);
	local[8]= makeint(10243);
	local[9]= makeint(10497);
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,3,local+7,&ftab[14],fqv[52]); /*gltexparameteri*/
	local[7]= makeint(3553);
	local[8]= makeint(10240);
	local[9]= makeint(9728);
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,3,local+7,&ftab[14],fqv[52]); /*gltexparameteri*/
	local[7]= makeint(3553);
	local[8]= makeint(10241);
	local[9]= makeint(9728);
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,3,local+7,&ftab[14],fqv[52]); /*gltexparameteri*/
	local[7]= makeint(8960);
	local[8]= makeint(8704);
	local[9]= makeint(8448);
	ctx->vsp=local+10;
	w=(*ftab[15])(ctx,3,local+7,&ftab[15],fqv[53]); /*gltexenvi*/
	local[7]= makeint(16384);
	w = makeint(256);
	local[7]= (pointer)((integer_t)local[7] | (integer_t)w);
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[54]); /*glclear*/
	local[7]= loadglobal(fqv[25]);
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[55]); /*glxswapbuffers*/
	local[7]= makeint(16384);
	w = makeint(256);
	local[7]= (pointer)((integer_t)local[7] | (integer_t)w);
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[54]); /*glclear*/
	local[7]= loadglobal(fqv[25]);
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[55]); /*glxswapbuffers*/
	ctx->vsp=local+7;
	w=(*ftab[18])(ctx,0,local+7,&ftab[18],fqv[56]); /*glunewtess*/
	local[7]= w;
	storeglobal(fqv[57],w);
	local[7]= loadglobal(fqv[57]);
	local[8]= makeint(100100);
	local[9]= *(ovafptr((pointer)get_sym_func(fqv[58]),fqv[59]));
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[60]); /*glutesscallbackl*/
	local[7]= loadglobal(fqv[57]);
	local[8]= makeint(100101);
	local[9]= *(ovafptr((pointer)get_sym_func(fqv[61]),fqv[59]));
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[60]); /*glutesscallbackl*/
	local[7]= loadglobal(fqv[57]);
	local[8]= makeint(100102);
	local[9]= *(ovafptr((pointer)get_sym_func(fqv[62]),fqv[59]));
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[60]); /*glutesscallbackl*/
	w = argv[0];
	local[0]= w;
BLK324:
	ctx->vsp=local; return(local[0]);}

/*:material*/
static pointer M335(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT341;}
	local[0]= NIL;
ENT341:
	if (n>=5) { local[1]=(argv[4]); goto ENT340;}
	local[1]= NIL;
ENT340:
	if (n>=6) { local[2]=(argv[5]); goto ENT339;}
	local[2]= NIL;
ENT339:
	if (n>=7) { local[3]=(argv[6]); goto ENT338;}
	local[3]= NIL;
ENT338:
ENT337:
	if (n>7) maerror();
	if (local[0]!=NIL) goto IF342;
	local[0] = argv[2]->c.obj.iv[3];
	local[1] = argv[2]->c.obj.iv[4];
	local[2] = argv[2]->c.obj.iv[5];
	local[3] = argv[2]->c.obj.iv[6];
	argv[2] = argv[2]->c.obj.iv[2];
	local[4]= argv[2];
	goto IF343;
IF342:
	local[4]= NIL;
IF343:
	local[4]= makeint(1032);
	local[5]= makeint(4609);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(4609);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(4610);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(4610);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(5633);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,1,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= w;
BLK336:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M344(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[63]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF346;
	argv[2] = argv[2]->c.obj.iv[0];
	local[0]= argv[2];
	goto IF347;
IF346:
	local[0]= NIL;
IF347:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[64]!=local[1]) goto IF349;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[65]); /*glcolor3fv*/
	local[1]= w;
	goto IF350;
IF349:
	local[1]= local[0];
	if (fqv[66]!=local[1]) goto IF351;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[67]); /*glcolor4fv*/
	local[1]= w;
	goto IF352;
IF351:
	if (T==NIL) goto IF353;
	local[1]= fqv[68];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF354;
IF353:
	local[1]= NIL;
IF354:
IF352:
IF350:
	w = local[1];
	local[0]= w;
BLK345:
	ctx->vsp=local; return(local[0]);}

/*:window*/
static pointer M355(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK356:
	ctx->vsp=local; return(local[0]);}

/*:3d-mode*/
static pointer M357(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF359;
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,1,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,4,local+0,&ftab[22],fqv[69]); /*glviewport*/
	local[0]= w;
	goto IF360;
IF359:
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)MINUS(ctx,1,local+0); /*-*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,4,local+0,&ftab[22],fqv[69]); /*glviewport*/
	local[0]= w;
IF360:
	local[0]= makeint(5889);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[70]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[71]); /*glloadidentity*/
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= makeint(5888);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[70]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[71]); /*glloadidentity*/
	local[0]= w;
BLK358:
	ctx->vsp=local; return(local[0]);}

/*:2d-mode*/
static pointer M361(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,4,local+0,&ftab[22],fqv[69]); /*glviewport*/
	local[0]= makeint(5889);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[70]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[71]); /*glloadidentity*/
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeflt(-1.00000000e+00);
	local[5]= makeflt(1.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,6,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[25])(ctx,1,local+0,&ftab[25],fqv[72]); /*glorthofv*/
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(5888);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[70]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[71]); /*glloadidentity*/
	local[0]= w;
BLK362:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M363(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT366;}
	local[0]= NIL;
ENT366:
ENT365:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF367;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF368;
IF367:
	local[1]= NIL;
IF368:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK364:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M369(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT372;}
	local[0]= NIL;
ENT372:
ENT371:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF373;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto IF374;
IF373:
	local[1]= NIL;
IF374:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK370:
	ctx->vsp=local; return(local[0]);}

/*:pos*/
static pointer M375(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK376:
	ctx->vsp=local; return(local[0]);}

/*:x*/
static pointer M377(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT380;}
	local[0]= NIL;
ENT380:
ENT379:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF381;
	argv[0]->c.obj.iv[12] = local[0];
	local[1]= argv[0]->c.obj.iv[12];
	goto IF382;
IF381:
	local[1]= NIL;
IF382:
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK378:
	ctx->vsp=local; return(local[0]);}

/*:y*/
static pointer M383(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT386;}
	local[0]= NIL;
ENT386:
ENT385:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF387;
	argv[0]->c.obj.iv[13] = local[0];
	local[1]= argv[0]->c.obj.iv[13];
	goto IF388;
IF387:
	local[1]= NIL;
IF388:
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK384:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M389(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16384);
	w = makeint(256);
	local[0]= (pointer)((integer_t)local[0] | (integer_t)w);
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[54]); /*glclear*/
	local[0]= w;
BLK390:
	ctx->vsp=local; return(local[0]);}

/*:glflush*/
static pointer M391(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(*ftab[26])(ctx,0,local+0,&ftab[26],fqv[73]); /*glflush*/
	local[0]= loadglobal(fqv[25]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[55]); /*glxswapbuffers*/
	local[0]= w;
BLK392:
	ctx->vsp=local; return(local[0]);}

/*:point*/
static pointer M393(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[27])(ctx,1,local+0,&ftab[27],fqv[58]); /*glbegin*/
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	ctx->vsp=local+0;
	w=(*ftab[29])(ctx,0,local+0,&ftab[29],fqv[62]); /*glend*/
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK394:
	ctx->vsp=local; return(local[0]);}

/*:line*/
static pointer M395(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= makeint(1);
	ctx->vsp=local+1;
	w=(*ftab[27])(ctx,1,local+0,&ftab[27],fqv[58]); /*glbegin*/
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	local[0]= argv[4];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	ctx->vsp=local+0;
	w=(*ftab[29])(ctx,0,local+0,&ftab[29],fqv[62]); /*glend*/
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK396:
	ctx->vsp=local; return(local[0]);}

/*:3d-point*/
static pointer M397(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[27])(ctx,1,local+0,&ftab[27],fqv[58]); /*glbegin*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[76]); /*glvertex3fv*/
	ctx->vsp=local+0;
	w=(*ftab[29])(ctx,0,local+0,&ftab[29],fqv[62]); /*glend*/
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= w;
BLK398:
	ctx->vsp=local; return(local[0]);}

/*:3d-line*/
static pointer M399(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(1);
	ctx->vsp=local+1;
	w=(*ftab[27])(ctx,1,local+0,&ftab[27],fqv[58]); /*glbegin*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[76]); /*glvertex3fv*/
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[76]); /*glvertex3fv*/
	ctx->vsp=local+0;
	w=(*ftab[29])(ctx,0,local+0,&ftab[29],fqv[62]); /*glend*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= w;
BLK400:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M401(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO403,env,argv,local);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MAPC(ctx,2,local+0); /*mapc*/
	local[0]= w;
BLK402:
	ctx->vsp=local; return(local[0]);}

/*:rectangle*/
static pointer M404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= makeint(9);
	ctx->vsp=local+1;
	w=(*ftab[27])(ctx,1,local+0,&ftab[27],fqv[58]); /*glbegin*/
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[3];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[28])(ctx,1,local+0,&ftab[28],fqv[75]); /*glvertex2fv*/
	ctx->vsp=local+0;
	w=(*ftab[29])(ctx,0,local+0,&ftab[29],fqv[62]); /*glend*/
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK405:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO403(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(*ftab[31])(ctx,3,local+0,&ftab[31],fqv[77]); /*draw-face*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*geometry::default-viewsurface*/
static pointer F181(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST407:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[78]);
	local[2]= loadglobal(fqv[79]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[32];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK406:
	ctx->vsp=local; return(local[0]);}

/*:draw-point*/
static pointer M408(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[80];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK409:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M410(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[81];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK411:
	ctx->vsp=local; return(local[0]);}

/*:draw-rectangle*/
static pointer M412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[82];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK413:
	ctx->vsp=local; return(local[0]);}

/*:draw-one*/
static pointer M414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[2];
	if (!isnum(w)) goto CON417;
	local[0]= NIL;
	goto CON416;
CON417:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON418;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON420;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[83]!=local[1]) goto IF422;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[81];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= w;
	goto IF423;
IF422:
	local[1]= local[0];
	if (fqv[84]!=local[1]) goto IF424;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[85];
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
	goto IF425;
IF424:
	if (T==NIL) goto IF426;
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF427;
IF426:
	local[1]= NIL;
IF427:
IF425:
IF423:
	w = local[1];
	local[0]= w;
	goto CON419;
CON420:
	local[0]= NIL;
	local[1]= argv[2];
WHL430:
	if (local[1]==NIL) goto WHX431;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[87];
	local[4]= local[0];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL430;
WHX431:
	local[2]= NIL;
BLK432:
	w = NIL;
	local[0]= w;
	goto CON419;
CON428:
	local[0]= NIL;
CON419:
	goto CON416;
CON418:
	local[0]= argv[2];
	local[1]= fqv[88];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[89]); /*find-method*/
	if (w==NIL) goto CON434;
	local[0]= argv[2];
	local[1]= fqv[88];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON434:
	local[0]= argv[2];
	local[1]= fqv[90];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[89]); /*find-method*/
	if (w==NIL) goto CON435;
	local[0]= argv[2];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[89]); /*find-method*/
	if (w==NIL) goto IF436;
	local[0]= argv[2];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF437;
IF436:
	local[0]= NIL;
IF437:
	local[0]= argv[0];
	local[1]= fqv[87];
	local[2]= argv[2];
	local[3]= fqv[90];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON435:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[92]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON438;
	local[0]= argv[2];
	local[1]= fqv[47];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON438:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[63]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON439;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[93];
	local[2]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON439:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[94]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON440;
	local[0]= argv[0];
	local[1]= fqv[95];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON440:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[96]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON441;
	local[0]= argv[0];
	local[1]= fqv[97];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON441:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[39]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON442;
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= argv[2];
	local[1]= fqv[47];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON442:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[98]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON443;
	local[0]= argv[2];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= loadglobal(fqv[79]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF444;
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[99]); /*draw-body*/
	local[0]= w;
	goto IF445;
IF444:
	local[0]= argv[2];
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[100];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
WHL447:
	if (local[2]==NIL) goto WHX448;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[95];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL447;
WHX448:
	local[3]= NIL;
BLK449:
	w = NIL;
	local[0]= w;
IF445:
	goto CON416;
CON443:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[101]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON451;
	local[0]= argv[2];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= loadglobal(fqv[79]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF452;
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[99]); /*draw-body*/
	local[0]= w;
	goto IF453;
IF452:
	local[0]= argv[2];
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[102];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL455:
	if (local[2]==NIL) goto WHX456;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[95];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL455;
WHX456:
	local[3]= NIL;
BLK457:
	w = NIL;
	local[0]= w;
IF453:
	goto CON416;
CON451:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[103]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON459;
	local[0]= argv[0];
	local[1]= fqv[104];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON459:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[105]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON460;
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL462:
	if (local[1]==NIL) goto WHX463;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[95];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL462;
WHX463:
	local[2]= NIL;
BLK464:
	w = NIL;
	local[0]= w;
	goto CON416;
CON460:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON466;
	local[0]= argv[0];
	local[1]= fqv[106];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[3];
	goto CON416;
CON466:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[107]); /*coordinates-p*/
	if (w==NIL) goto CON467;
	local[0]= argv[0];
	local[1]= fqv[108];
	local[2]= argv[2];
	local[3]= fqv[91];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON467:
	local[0]= fqv[109];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON468;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[109]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON468;
	local[0]= argv[0];
	local[1]= fqv[110];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON416;
CON468:
	local[0]= NIL;
CON416:
	w = local[0];
	local[0]= w;
BLK415:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M469(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT473;}
	local[0]= NIL;
ENT473:
	if (n>=5) { local[1]=(argv[4]); goto ENT472;}
	local[1]= NIL;
ENT472:
ENT471:
	if (n>5) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO474,env,argv,local);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPC(ctx,2,local+2); /*mapc*/
	local[0]= w;
BLK470:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO474(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(*ftab[31])(ctx,3,local+0,&ftab[31],fqv[77]); /*draw-face*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*resetperspective*/
static pointer F182(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(5889);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[70]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[71]); /*glloadidentity*/
	local[0]= argv[0];
	local[1]= fqv[111];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[112];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VPLUS(ctx,2,local+1); /*v+*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[113];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[114];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[35])(ctx,1,local+3,&ftab[35],fqv[115]); /*rad2deg*/
	local[3]= w;
	local[4]= makeflt(1.00000000e+00);
	local[5]= loadglobal(fqv[116]);
	local[6]= loadglobal(fqv[117]);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[36])(ctx,1,local+3,&ftab[36],fqv[118]); /*gluperspectivefv*/
	local[3]= loadglobal(fqv[119]);
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,4,local+3); /*concatenate*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[37])(ctx,1,local+3,&ftab[37],fqv[120]); /*glulookatfv*/
	local[0]= makeint(5888);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[70]); /*glmatrixmode*/
	local[0]= w;
BLK475:
	ctx->vsp=local; return(local[0]);}

/*gldraw*/
static pointer F183(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST477:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto IF478;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto IF479;
IF478:
	local[1]= loadglobal(fqv[122]);
IF479:
	local[2]= local[1];
	local[3]= fqv[123];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[124];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F182(ctx,2,local+2); /*resetperspective*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[38])(ctx,1,local+2,&ftab[38],fqv[125]); /*cls*/
	local[2]= (pointer)get_sym_func(fqv[126]);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= local[1]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)F184(ctx,1,local+2); /*swapb*/
	local[0]= w;
BLK476:
	ctx->vsp=local; return(local[0]);}

/*swapb*/
static pointer F184(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT482;}
	local[0]= loadglobal(fqv[127]);
ENT482:
ENT481:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= fqv[128];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK480:
	ctx->vsp=local; return(local[0]);}

/*position-light*/
static pointer F185(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= local[0];
	if (fqv[129]!=local[1]) goto IF485;
	local[1]= makeint(16384);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF486;
IF485:
	local[1]= local[0];
	if (fqv[130]!=local[1]) goto IF487;
	local[1]= makeint(16385);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF488;
IF487:
	local[1]= local[0];
	if (fqv[131]!=local[1]) goto IF489;
	local[1]= makeint(16386);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF490;
IF489:
	local[1]= local[0];
	if (fqv[132]!=local[1]) goto IF491;
	local[1]= makeint(16387);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF492;
IF491:
	local[1]= local[0];
	if (fqv[133]!=local[1]) goto IF493;
	local[1]= makeint(16388);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF494;
IF493:
	local[1]= local[0];
	if (fqv[134]!=local[1]) goto IF495;
	local[1]= makeint(16389);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF496;
IF495:
	local[1]= local[0];
	if (fqv[135]!=local[1]) goto IF497;
	local[1]= makeint(16390);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF498;
IF497:
	local[1]= local[0];
	if (fqv[136]!=local[1]) goto IF499;
	local[1]= makeint(16391);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF500;
IF499:
	if (T==NIL) goto IF501;
	local[1]= NIL;
	local[2]= fqv[137];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF502;
IF501:
	local[1]= NIL;
IF502:
IF500:
IF498:
IF496:
IF494:
IF492:
IF490:
IF488:
IF486:
	w = local[1];
	local[0]= w;
BLK483:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___glview(ctx,n,argv,env)
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
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF503;
	local[0]= fqv[139];
	ctx->vsp=local+1;
	w=(*ftab[39])(ctx,1,local+0,&ftab[39],fqv[140]); /*make-package*/
	local[0]= w;
	goto IF504;
IF503:
	local[0]= NIL;
IF504:
	local[0]= fqv[141];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF505;
	local[0]= fqv[142];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[143],w);
	goto IF506;
IF505:
	local[0]= fqv[144];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF506:
	local[0]= fqv[145];
	local[1]= fqv[146];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[148];
	local[1]= fqv[149];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[150];
	local[1]= fqv[151];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[152];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[154];
	local[1]= fqv[155];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[156];
	local[1]= fqv[157];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[158];
	local[1]= fqv[159];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[160];
	local[1]= fqv[161];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[147]); /*require*/
	local[0]= fqv[162];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[117];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF507;
	local[0]= fqv[117];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[117];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF509;
	local[0]= fqv[117];
	local[1]= fqv[164];
	local[2]= makeflt(3.00000000e+04);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF510;
IF509:
	local[0]= NIL;
IF510:
	local[0]= fqv[117];
	goto IF508;
IF507:
	local[0]= NIL;
IF508:
	local[0]= fqv[116];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF511;
	local[0]= fqv[116];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[116];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF513;
	local[0]= fqv[116];
	local[1]= fqv[164];
	local[2]= makeflt(2.00000000e+02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF514;
IF513:
	local[0]= NIL;
IF514:
	local[0]= fqv[116];
	goto IF512;
IF511:
	local[0]= NIL;
IF512:
	local[0]= fqv[44];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF515;
	local[0]= fqv[44];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF517;
	local[0]= fqv[44];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF518;
IF517:
	local[0]= NIL;
IF518:
	local[0]= fqv[44];
	goto IF516;
IF515:
	local[0]= NIL;
IF516:
	local[0]= fqv[45];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF519;
	local[0]= fqv[45];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF521;
	local[0]= fqv[45];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF522;
IF521:
	local[0]= NIL;
IF522:
	local[0]= fqv[45];
	goto IF520;
IF519:
	local[0]= NIL;
IF520:
	local[0]= fqv[46];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF523;
	local[0]= fqv[46];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF525;
	local[0]= fqv[46];
	local[1]= fqv[164];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF526;
IF525:
	local[0]= NIL;
IF526:
	local[0]= fqv[46];
	goto IF524;
IF523:
	local[0]= NIL;
IF524:
	local[0]= fqv[27];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF527;
	local[0]= fqv[27];
	local[1]= fqv[163];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF529;
	local[0]= fqv[27];
	local[1]= fqv[164];
	local[2]= makeint(4);
	local[3]= makeint(8);
	local[4]= makeint(1);
	local[5]= makeint(9);
	local[6]= makeint(1);
	local[7]= makeint(10);
	local[8]= makeint(1);
	local[9]= makeint(5);
	local[10]= makeint(12);
	local[11]= makeint(1);
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKINTVECTOR(ctx,11,local+2); /*integer-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF530;
IF529:
	local[0]= NIL;
IF530:
	local[0]= fqv[27];
	goto IF528;
IF527:
	local[0]= NIL;
IF528:
	local[0]= fqv[165];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M186,fqv[32],fqv[92],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M198,fqv[40],fqv[92],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M210,fqv[41],fqv[92],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M222,fqv[42],fqv[92],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M234,fqv[170],fqv[92],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M246,fqv[172],fqv[92],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M254,fqv[174],fqv[92],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M262,fqv[47],fqv[92],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M264,fqv[32],fqv[39],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M270,fqv[14],fqv[39],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M272,fqv[40],fqv[39],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M284,fqv[41],fqv[39],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M296,fqv[42],fqv[39],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M308,fqv[43],fqv[39],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M315,fqv[183],fqv[39],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M317,fqv[185],fqv[39],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M319,fqv[187],fqv[39],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M321,fqv[47],fqv[39],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M323,fqv[32],fqv[79],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M335,fqv[191],fqv[79],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M344,fqv[93],fqv[79],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M355,fqv[194],fqv[79],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M357,fqv[38],fqv[79],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M361,fqv[74],fqv[79],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M363,fqv[24],fqv[79],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M369,fqv[23],fqv[79],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M375,fqv[200],fqv[79],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M377,fqv[21],fqv[79],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M383,fqv[22],fqv[79],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M389,fqv[204],fqv[79],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M391,fqv[128],fqv[79],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M393,fqv[80],fqv[79],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M395,fqv[81],fqv[79],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M397,fqv[209],fqv[79],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M399,fqv[85],fqv[79],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M401,fqv[104],fqv[79],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M404,fqv[82],fqv[79],fqv[213]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F181,fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M408,fqv[216],fqv[79],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M410,fqv[218],fqv[79],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M412,fqv[220],fqv[79],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M414,fqv[87],fqv[121],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M469,fqv[104],fqv[121],fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F182,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F183,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F184,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F185,fqv[231]);
	local[0]= fqv[232];
	local[1]= fqv[233];
	ctx->vsp=local+2;
	w=(*ftab[41])(ctx,2,local+0,&ftab[41],fqv[234]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<42; i++) ftab[i]=fcallx;
}
