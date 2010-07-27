/* piximage.c :  entry=piximage */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "piximage.h"
#pragma init (register_piximage)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___piximage();
extern pointer build_quote_vector();
static register_piximage()
  { add_module_initializer("___piximage", ___piximage);}

static pointer F191();
static pointer F192();
static pointer F193();
static pointer F194();
static pointer F195();
static pointer F196();
static pointer F197();
static pointer F198();
static pointer F199();
static pointer F200();
static pointer F201();
static pointer F202();
static pointer F203();
static pointer F204();
static pointer F205();
static pointer F206();
static pointer F207();

/*make-equilevel-lut*/
static pointer F191(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT210;}
	local[0]= makeint(256);
ENT210:
ENT209:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[0]);
	local[2]= makeint(256);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= argv[0];
WHL212:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX213;
	local[6]= makeint(0);
	local[7]= local[2];
WHL216:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX217;
	local[8]= local[1];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL216;
WHX217:
	local[8]= NIL;
BLK218:
	w = NIL;
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL212;
WHX213:
	local[6]= NIL;
BLK214:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK208:
	ctx->vsp=local; return(local[0]);}

/*look-up2*/
static pointer F192(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[1]!=NIL) goto IF220;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*make-sequence*/
	argv[1] = w;
	local[0]= argv[1];
	goto IF221;
IF220:
	local[0]= NIL;
IF221:
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL223:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX224;
	local[2]= argv[1];
	local[3]= local[0];
	local[4]= argv[3];
	local[5]= argv[2];
	local[6]= argv[0];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL223;
WHX224:
	local[2]= NIL;
BLK225:
	w = NIL;
	w = argv[1];
	local[0]= w;
BLK219:
	ctx->vsp=local; return(local[0]);}

/*look-up**/
static pointer F193(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	if (argv[1]!=NIL) goto IF227;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*make-sequence*/
	argv[1] = w;
	local[2]= argv[1];
	goto IF228;
IF227:
	local[2]= NIL;
IF228:
	local[2]= makeint(0);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL230:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX231;
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[1] = w;
	local[4]= NIL;
	local[5]= argv[2];
WHL234:
	if (local[5]==NIL) goto WHX235;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[1] = w;
	goto WHL234;
WHX235:
	local[6]= NIL;
BLK236:
	w = NIL;
	local[4]= argv[1];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL230;
WHX231:
	local[4]= NIL;
BLK232:
	w = NIL;
	w = argv[1];
	local[0]= w;
BLK226:
	ctx->vsp=local; return(local[0]);}

/*concatenate-lut*/
static pointer F194(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT240;}
	local[0]= makeint(256);
ENT240:
ENT239:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[0]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*make-sequence*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= makeint(256);
WHL242:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX243;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[1];
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL242;
WHX243:
	local[4]= NIL;
BLK244:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK238:
	ctx->vsp=local; return(local[0]);}

/*:entity*/
static pointer M245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK246:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M247(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK248:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M249(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK250:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M251(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK252:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
BLK254:
	ctx->vsp=local; return(local[0]);}

/*:set-pixel*/
static pointer M255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[3];
	local[2]= argv[2];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= w;
BLK256:
	ctx->vsp=local; return(local[0]);}

/*:duplicate*/
static pointer M257(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST259:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[2]);
	local[3]= local[1];
	local[4]= fqv[3];
	local[5]= argv[0];
	local[6]= fqv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,6,local+2); /*apply*/
	w = local[1];
	local[0]= w;
BLK258:
	ctx->vsp=local; return(local[0]);}

/*:copy-from*/
static pointer M261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[6]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK262:
	ctx->vsp=local; return(local[0]);}

/*:copy*/
static pointer M263(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYOBJ(ctx,1,local+0); /*copy-object*/
	local[0]= w;
BLK264:
	ctx->vsp=local; return(local[0]);}

/*:hex*/
static pointer M265(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT272;}
	local[0]= makeint(0);
ENT272:
	if (n>=4) { local[1]=(argv[3]); goto ENT271;}
	local[1]= makeint(0);
ENT271:
	if (n>=5) { local[2]=(argv[4]); goto ENT270;}
	local[2]= makeint(8);
ENT270:
	if (n>=6) { local[3]=(argv[5]); goto ENT269;}
	local[3]= makeint(8);
ENT269:
	if (n>=7) { local[4]=(argv[6]); goto ENT268;}
	local[4]= T;
ENT268:
ENT267:
	if (n>7) maerror();
	local[5]= makeint(0);
	local[6]= local[3];
WHL274:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX275;
	local[7]= local[4];
	local[8]= fqv[7];
	local[9]= local[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= makeint(0);
	local[8]= local[2];
WHL278:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX279;
	local[9]= local[4];
	local[10]= fqv[8];
	local[11]= argv[0];
	local[12]= fqv[9];
	local[13]= local[0];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[1];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL278;
WHX279:
	local[9]= NIL;
BLK280:
	w = NIL;
	local[7]= local[4];
	local[8]= fqv[10];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL274;
WHX275:
	local[7]= NIL;
BLK276:
	w = NIL;
	local[0]= w;
BLK266:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M281(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST283:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[11]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[12]));
	local[4]= fqv[13];
	local[5]= argv[2];
	local[6]= NIL;
	local[7]= fqv[14];
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[5];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,4,local+6); /*format*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[0]= w;
BLK282:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT288;}
	local[0]= NIL;
ENT288:
	if (n>=6) { local[1]=(argv[5]); goto ENT287;}
	local[1]= makeint(8);
ENT287:
ENT286:
	if (n>6) maerror();
	if (local[0]!=NIL) goto IF289;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= fqv[15];
	local[4]= local[1];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto CON292;
	local[4]= fqv[16];
	goto CON291;
CON292:
	local[4]= local[1];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)LSEQP(ctx,2,local+4); /*<=*/
	if (w==NIL) goto CON293;
	local[4]= fqv[17];
	goto CON291;
CON293:
	local[4]= local[1];
	local[5]= makeint(32);
	ctx->vsp=local+6;
	w=(pointer)LSEQP(ctx,2,local+4); /*<=*/
	if (w==NIL) goto CON294;
	local[4]= fqv[18];
	goto CON291;
CON294:
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON291;
CON295:
	local[4]= NIL;
CON291:
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[20]); /*make-array*/
	local[0] = w;
	local[2]= local[0];
	goto IF290;
IF289:
	local[2]= NIL;
IF290:
	argv[0]->c.obj.iv[2] = makeint(2);
	argv[0]->c.obj.iv[4] = makeint(0);
	argv[0]->c.obj.iv[12] = local[1];
	argv[0]->c.obj.iv[6] = argv[2];
	argv[0]->c.obj.iv[5] = argv[3];
	argv[0]->c.obj.iv[1] = local[0];
	w = argv[0];
	local[0]= w;
BLK285:
	ctx->vsp=local; return(local[0]);}

/*:fill*/
static pointer M296(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[21]); /*fill*/
	w = argv[2];
	local[0]= w;
BLK297:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M298(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK299:
	ctx->vsp=local; return(local[0]);}

/*:transpose*/
static pointer M300(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT303;}
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT303:
ENT302:
	if (n>3) maerror();
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[6];
WHL306:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX307;
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[5];
WHL310:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX311;
	local[5]= local[0];
	local[6]= fqv[23];
	local[7]= local[1];
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= fqv[24];
	local[11]= local[3];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL310;
WHX311:
	local[5]= NIL;
BLK312:
	w = NIL;
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL306;
WHX307:
	local[3]= NIL;
BLK308:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK301:
	ctx->vsp=local; return(local[0]);}

/*:map-picture*/
static pointer M313(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT316;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT316:
ENT315:
	if (n>4) maerror();
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL318:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX319;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	{ register integer_t i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL318;
WHX319:
	local[4]= NIL;
BLK320:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK314:
	ctx->vsp=local; return(local[0]);}

/*:map*/
static pointer M321(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT324;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT324:
ENT323:
	if (n>4) maerror();
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL326:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX327;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	{ register integer_t i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL326;
WHX327:
	local[4]= NIL;
BLK328:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK322:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M329(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
BLK330:
	ctx->vsp=local; return(local[0]);}

/*:set-pixel*/
static pointer M331(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	local[2]= argv[2];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= w;
BLK332:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M333(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK334:
	ctx->vsp=local; return(local[0]);}

/*:halve*/
static pointer M335(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT338;}
	local[0]= NIL;
ENT338:
ENT337:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	if (local[0]!=NIL) goto IF339;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF340;
IF339:
	local[3]= NIL;
IF340:
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[27]); /*halve-image*/
	w = local[0];
	local[0]= w;
BLK336:
	ctx->vsp=local; return(local[0]);}

/*:double*/
static pointer M342(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT345;}
	local[0]= NIL;
ENT345:
ENT344:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	if (local[0]!=NIL) goto IF346;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF347;
IF346:
	local[3]= NIL;
IF347:
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[28]); /*double-image*/
	w = local[0];
	local[0]= w;
BLK343:
	ctx->vsp=local; return(local[0]);}

/*:patch-in*/
static pointer M349(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[4]->c.obj.iv[1];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL352:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX353;
	local[8]= argv[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[4] = w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[3];
	local[10]= fqv[29];
	local[11]= local[4];
	local[12]= fqv[30];
	local[13]= local[4];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[31];
	local[15]= local[6];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,8,local+8,&ftab[1],fqv[6]); /*replace*/
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL352;
WHX353:
	local[8]= NIL;
BLK354:
	w = NIL;
	local[0]= w;
BLK350:
	ctx->vsp=local; return(local[0]);}

/*:xpicture*/
static pointer M355(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT358;}
	local[0]= NIL;
ENT358:
ENT357:
	if (n>3) maerror();
	if (loadglobal(fqv[32])!=NIL) goto IF359;
	local[1]= loadglobal(fqv[33]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[32],w);
	goto IF360;
IF359:
	local[1]= NIL;
IF360:
	if (local[0]!=NIL) goto IF362;
	local[1]= argv[0];
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF363;
IF362:
	local[1]= NIL;
IF363:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= loadglobal(fqv[32])->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,3,local+1,&ftab[6],fqv[35]); /*look-up*/
	w = loadglobal(fqv[32]);
	local[0]= w;
BLK356:
	ctx->vsp=local; return(local[0]);}

/*:display-lut*/
static pointer M364(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT367;}
	local[0]= NIL;
ENT367:
ENT366:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)VECTORP(ctx,1,local+1); /*vectorp*/
	if (w==NIL) goto IF368;
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= local[0];
	storeglobal(fqv[37],local[3]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF369;
IF368:
	local[1]= NIL;
IF369:
	if (loadglobal(fqv[37])==NIL) goto IF370;
	local[1]= loadglobal(fqv[37]);
	goto IF371;
IF370:
	local[1]= loadglobal(fqv[38]);
IF371:
	w = local[1];
	local[0]= w;
BLK365:
	ctx->vsp=local; return(local[0]);}

/*:display*/
static pointer M372(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT378;}
	local[0]= loadglobal(fqv[39]);
ENT378:
	if (n>=4) { local[1]=(argv[3]); goto ENT377;}
	local[1]= NIL;
ENT377:
	if (n>=5) { local[2]=(argv[4]); goto ENT376;}
	local[2]= makeint(0);
ENT376:
	if (n>=6) { local[3]=(argv[5]); goto ENT375;}
	local[3]= makeint(0);
ENT375:
ENT374:
	if (n>6) maerror();
	local[4]= local[0];
	local[5]= fqv[40];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	local[6]= local[5];
	if (fqv[41]!=local[6]) goto IF380;
	local[6]= local[0];
	local[7]= fqv[42];
	if (loadglobal(fqv[32])==NIL) goto IF382;
	local[8]= argv[0];
	local[9]= fqv[36];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w->c.obj.iv[1];
	goto IF383;
IF382:
	local[8]= argv[0]->c.obj.iv[1];
IF383:
	local[9]= fqv[43];
	local[10]= local[2];
	local[11]= fqv[44];
	local[12]= local[3];
	local[13]= fqv[4];
	local[14]= argv[0]->c.obj.iv[6];
	local[15]= fqv[5];
	local[16]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,11,local+6); /*send*/
	local[6]= w;
	goto IF381;
IF380:
	local[6]= local[5];
	if (fqv[45]!=local[6]) goto IF384;
	local[6]= local[0];
	local[7]= fqv[42];
	local[8]= argv[0];
	local[9]= fqv[46];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF385;
IF384:
	local[6]= local[5];
	if (fqv[47]!=local[6]) goto IF386;
	local[6]= local[0];
	local[7]= fqv[42];
	local[8]= argv[0];
	local[9]= fqv[48];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF387;
IF386:
	local[6]= local[5];
	if (fqv[49]!=local[6]) goto IF388;
	local[6]= local[0];
	local[7]= fqv[42];
	local[8]= argv[0];
	local[9]= fqv[50];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF389;
IF388:
	if (T==NIL) goto IF390;
	local[6]= fqv[51];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[52]); /*warn*/
	local[6]= w;
	goto IF391;
IF390:
	local[6]= NIL;
IF391:
IF389:
IF387:
IF385:
IF381:
	w = local[6];
	w = argv[0];
	local[0]= w;
BLK373:
	ctx->vsp=local; return(local[0]);}

/*:subimage*/
static pointer M392(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[4];
	local[1]= argv[5];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[5];
WHL395:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX396;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[29];
	local[6]= local[1];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= fqv[30];
	local[8]= (pointer)((integer_t)(local[1])+4);
	local[9]= argv[4];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= fqv[31];
	local[10]= argv[3];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[1])(ctx,8,local+3,&ftab[1],fqv[6]); /*replace*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL395;
WHX396:
	local[3]= NIL;
BLK397:
	w = NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[4];
	local[5]= argv[5];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK393:
	ctx->vsp=local; return(local[0]);}

/*:patch-in*/
static pointer M399(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[4]->c.obj.iv[1];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL402:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX403;
	local[8]= argv[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[4] = w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[3];
	local[10]= fqv[29];
	local[11]= local[4];
	local[12]= fqv[30];
	local[13]= local[4];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[31];
	local[15]= local[6];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,8,local+8,&ftab[1],fqv[6]); /*replace*/
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL402;
WHX403:
	local[8]= NIL;
BLK404:
	w = NIL;
	local[0]= w;
BLK400:
	ctx->vsp=local; return(local[0]);}

/*:brightest-pixel*/
static pointer M405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL408:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX409;
	local[3]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF411;
	local[3]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[0] = w;
	local[3]= local[0];
	goto IF412;
IF411:
	local[3]= NIL;
IF412:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL408;
WHX409:
	local[3]= NIL;
BLK410:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK406:
	ctx->vsp=local; return(local[0]);}

/*:darkest-pixel*/
static pointer M413(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(256);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL416:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX417;
	local[3]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF419;
	local[3]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[0] = w;
	local[3]= local[0];
	goto IF420;
IF419:
	local[3]= NIL;
IF420:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL416;
WHX417:
	local[3]= NIL;
BLK418:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK414:
	ctx->vsp=local; return(local[0]);}

/*:average-pixel*/
static pointer M421(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[54]);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[55]); /*reduce*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)EUSFLOAT(ctx,1,local+0); /*float*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK422:
	ctx->vsp=local; return(local[0]);}

/*:amplify*/
static pointer M423(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT426;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT426:
ENT425:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= local[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL428:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX429;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= makeint(255);
	local[8]= argv[2];
	local[9]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[3]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL428;
WHX429:
	local[5]= NIL;
BLK430:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK424:
	ctx->vsp=local; return(local[0]);}

/*:compress-gray-scale*/
static pointer M431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT434;}
	local[0]= NIL;
ENT434:
ENT433:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF435;
	local[3]= argv[0];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= fqv[56];
	local[5]= NIL;
	local[6]= fqv[57];
	local[7]= argv[0];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF436;
IF435:
	local[3]= NIL;
IF436:
	local[2] = local[0]->c.obj.iv[1];
	local[3]= makeint(256);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	argv[2] = w;
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL438:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX439;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[3]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL438;
WHX439:
	local[5]= NIL;
BLK440:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK432:
	ctx->vsp=local; return(local[0]);}

/*:lut*/
static pointer M441(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT444;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT444:
ENT443:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,3,local+1,&ftab[6],fqv[35]); /*look-up*/
	w = local[0];
	local[0]= w;
BLK442:
	ctx->vsp=local; return(local[0]);}

/*:lut2*/
static pointer M445(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT448;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT448:
ENT447:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F192(ctx,4,local+1); /*look-up2*/
	w = local[0];
	local[0]= w;
BLK446:
	ctx->vsp=local; return(local[0]);}

/*:to24*/
static pointer M449(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[0];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL452:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX453;
	local[3]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[1];
	{ integer_t i,j;
		j=intval(makeint(3)); i=intval(local[4]);
		local[4]=(makeint(i * j));}
	local[5]= local[0];
	local[6]= local[4];
	w = local[3];
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= (pointer)((integer_t)(local[4])+4);
	w = local[3];
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[4];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	w = local[3];
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL452;
WHX453:
	local[3]= NIL;
BLK454:
	w = NIL;
	local[1]= loadglobal(fqv[59]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[0];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK450:
	ctx->vsp=local; return(local[0]);}

/*:to32*/
static pointer M456(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[50];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK457:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M458(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK459:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M460(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT463;}
	local[0]= NIL;
ENT463:
ENT462:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,7,local+1); /*send-message*/
	local[0]= w;
BLK461:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M464(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[60];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK465:
	ctx->vsp=local; return(local[0]);}

/*color-32to24*/
static pointer F195(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT468;}
	local[0]= argv[1];
	local[1]= argv[2];
	{ integer_t i,j;
		j=intval(makeint(3)); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	{ integer_t i,j;
		j=intval(local[1]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT468:
ENT467:
	if (n>4) maerror();
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[4]);
		local[4]=(makeint(i * j));}
WHL470:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX471;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[8] + (integer_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= (pointer)((integer_t)(local[2])+4);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[8] + (integer_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[6]= (pointer)((integer_t)local[6] + (integer_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[8] + (integer_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[1];
	w = makeint(4);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1] = (pointer)((integer_t)local[5] + (integer_t)w);
	local[5]= local[2];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[2] = (pointer)((integer_t)local[5] + (integer_t)w);
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL470;
WHX471:
	local[5]= NIL;
BLK472:
	w = NIL;
	local[0]= w;
BLK466:
	ctx->vsp=local; return(local[0]);}

/*color-24to32*/
static pointer F196(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT475;}
	local[0]= argv[1];
	local[1]= argv[2];
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	{ integer_t i,j;
		j=intval(local[1]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT475:
ENT474:
	if (n>4) maerror();
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[4]);
		local[4]=(makeint(i * j));}
WHL477:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX478;
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[6]= (pointer)((integer_t)local[6] + (integer_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[8] + (integer_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[6]= (pointer)((integer_t)local[6] + (integer_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[8] + (integer_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(0);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[6]= (pointer)((integer_t)local[6] + (integer_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(0);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[8] + (integer_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[1];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1] = (pointer)((integer_t)local[5] + (integer_t)w);
	local[5]= local[2];
	w = makeint(4);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[2] = (pointer)((integer_t)local[5] + (integer_t)w);
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL477;
WHX478:
	local[5]= NIL;
BLK479:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK473:
	ctx->vsp=local; return(local[0]);}

/*color-24to8*/
static pointer F197(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT483;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[61]); /**w*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT483:
	if (n>=5) { local[1]=(argv[4]); goto ENT482;}
	local[1]= fqv[62];
ENT482:
ENT481:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
WHL484:
	local[16]= local[6];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX485;
	local[3] = (pointer)((integer_t)(local[3])-4);
	local[16]= local[6];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[6] = w;
	goto WHL484;
WHX485:
	local[16]= NIL;
BLK486:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.car;
WHL487:
	local[16]= local[9];
	local[17]= makeint(128);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX488;
	local[16]= local[9];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[9] = w;
	goto WHL487;
WHX488:
	local[16]= NIL;
BLK489:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
WHL490:
	local[16]= local[7];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX491;
	local[4] = (pointer)((integer_t)(local[4])-4);
	local[16]= local[7];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[7] = w;
	goto WHL490;
WHX491:
	local[16]= NIL;
BLK492:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.car;
WHL493:
	local[16]= local[10];
	local[17]= makeint(128);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX494;
	local[16]= local[10];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[10] = w;
	goto WHL493;
WHX494:
	local[16]= NIL;
BLK495:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
WHL496:
	local[16]= local[8];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX497;
	local[5] = (pointer)((integer_t)(local[5])-4);
	local[16]= local[8];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[8] = w;
	goto WHL496;
WHX497:
	local[16]= NIL;
BLK498:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.car;
WHL499:
	local[16]= local[11];
	local[17]= makeint(128);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX500;
	local[16]= local[11];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[11] = w;
	goto WHL499;
WHX500:
	local[16]= NIL;
BLK501:
	local[15] = makeint(0);
	local[16]= makeint(0);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
WHL503:
	local[18]= local[16];
	w = local[17];
	if ((integer_t)local[18] >= (integer_t)w) goto WHX504;
	local[18]= local[9];
	local[19]= argv[0];
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[19]->c.str.chars[i]);}
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LOGAND(ctx,2,local+18); /*logand*/
	local[12] = w;
	local[18]= local[10];
	local[19]= argv[0];
	local[15] = (pointer)((integer_t)(local[15])+4);
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[19]->c.str.chars[i]);}
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LOGAND(ctx,2,local+18); /*logand*/
	local[13] = w;
	local[18]= local[11];
	local[19]= argv[0];
	local[15] = (pointer)((integer_t)(local[15])+4);
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[19]->c.str.chars[i]);}
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LOGAND(ctx,2,local+18); /*logand*/
	local[14] = w;
	local[15] = (pointer)((integer_t)(local[15])+4);
	local[18]= local[0];
	local[19]= local[16];
	local[20]= local[12];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)ASH(ctx,2,local+20); /*ash*/
	local[20]= w;
	local[21]= local[13];
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
	local[22]= local[14];
	local[23]= local[5];
	ctx->vsp=local+24;
	w=(pointer)ASH(ctx,2,local+22); /*ash*/
	w = (pointer)((integer_t)local[21] | (integer_t)w);
	w = (pointer)((integer_t)local[20] | (integer_t)w);
	{ register integer_t i; register pointer v;
	  i=intval(local[19]); v=local[18];
	  v->c.str.chars[i]=intval(w);}
	local[16] = (pointer)((integer_t)(local[16])+4);
	goto WHL503;
WHX504:
	local[18]= NIL;
BLK505:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK480:
	ctx->vsp=local; return(local[0]);}

/*color-24to16*/
static pointer F198(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT509;}
	local[0]= NIL;
ENT509:
	if (n>=5) { local[1]=(argv[4]); goto ENT508;}
	local[1]= fqv[63];
ENT508:
ENT507:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF510;
	local[2]= makeint(2);
	local[3]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	{ integer_t i,j;
		j=intval(local[3]); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[53]); /*make-string*/
	local[0] = w;
	local[2]= local[0];
	goto IF511;
IF510:
	local[2]= NIL;
IF511:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
WHL512:
	local[16]= local[2];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX513;
	local[5] = (pointer)((integer_t)(local[5])+4);
	local[16]= local[2];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[2] = w;
	goto WHL512;
WHX513:
	local[16]= NIL;
BLK514:
WHL515:
	local[16]= local[2];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w==NIL) goto WHX516;
	local[8] = (pointer)((integer_t)(local[8])+4);
	local[16]= local[2];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[2] = w;
	goto WHL515;
WHX516:
	local[16]= NIL;
BLK517:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
WHL518:
	local[16]= local[3];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX519;
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[16]= local[3];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[3] = w;
	goto WHL518;
WHX519:
	local[16]= NIL;
BLK520:
WHL521:
	local[16]= local[3];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w==NIL) goto WHX522;
	local[9] = (pointer)((integer_t)(local[9])+4);
	local[16]= local[3];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[3] = w;
	goto WHL521;
WHX522:
	local[16]= NIL;
BLK523:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
WHL524:
	local[16]= local[4];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX525;
	local[7] = (pointer)((integer_t)(local[7])+4);
	local[16]= local[4];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[4] = w;
	goto WHL524;
WHX525:
	local[16]= NIL;
BLK526:
WHL527:
	local[16]= local[4];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w==NIL) goto WHX528;
	local[10] = (pointer)((integer_t)(local[10])+4);
	local[16]= local[4];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[4] = w;
	goto WHL527;
WHX528:
	local[16]= NIL;
BLK529:
	local[15] = makeint(0);
	local[16]= local[8];
	w = makeint(8);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[8] = (pointer)((integer_t)local[16] - (integer_t)w);
	local[16]= local[9];
	w = makeint(8);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9] = (pointer)((integer_t)local[16] - (integer_t)w);
	local[16]= local[10];
	w = makeint(8);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[10] = (pointer)((integer_t)local[16] - (integer_t)w);
	local[16]= makeint(0);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
WHL531:
	local[18]= local[16];
	w = local[17];
	if ((integer_t)local[18] >= (integer_t)w) goto WHX532;
	local[18]= argv[0];
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[18]->c.str.chars[i]);}
	local[18]= w;
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[12] = w;
	local[18]= argv[0];
	local[15] = (pointer)((integer_t)(local[15])+4);
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[18]->c.str.chars[i]);}
	local[18]= w;
	local[19]= local[9];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[13] = w;
	local[18]= argv[0];
	local[15] = (pointer)((integer_t)(local[15])+4);
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[18]->c.str.chars[i]);}
	local[18]= w;
	local[19]= local[10];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[14] = w;
	local[15] = (pointer)((integer_t)(local[15])+4);
	local[18]= local[12];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[18]= w;
	local[19]= local[13];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)ASH(ctx,2,local+19); /*ash*/
	local[19]= w;
	local[20]= local[14];
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)ASH(ctx,2,local+20); /*ash*/
	w = (pointer)((integer_t)local[19] | (integer_t)w);
	local[11] = (pointer)((integer_t)local[18] | (integer_t)w);
	local[18]= local[11];
	local[19]= local[0];
	local[20]= local[16];
	{ integer_t i,j;
		j=intval(makeint(2)); i=intval(local[20]);
		local[20]=(makeint(i * j));}
	local[21]= fqv[64];
	ctx->vsp=local+22;
	w=(pointer)POKE(ctx,4,local+18); /*system:poke*/
	local[16] = (pointer)((integer_t)(local[16])+4);
	goto WHL531;
WHX532:
	local[18]= NIL;
BLK533:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK506:
	ctx->vsp=local; return(local[0]);}

/*color-32to8*/
static pointer F199(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT537;}
	local[0]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT537:
	if (n>=5) { local[1]=(argv[4]); goto ENT536;}
	local[1]= fqv[65];
ENT536:
ENT535:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.car;
WHL538:
	local[17]= local[9];
	local[18]= makeint(128);
	ctx->vsp=local+19;
	w=(pointer)LOGTEST(ctx,2,local+17); /*logtest*/
	if (w!=NIL) goto WHX539;
	local[17]= local[9];
	local[18]= makeint(1);
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[9] = w;
	goto WHL538;
WHX539:
	local[17]= NIL;
BLK540:
WHL541:
	local[17]= local[10];
	local[18]= makeint(128);
	ctx->vsp=local+19;
	w=(pointer)LOGTEST(ctx,2,local+17); /*logtest*/
	if (w!=NIL) goto WHX542;
	local[17]= local[10];
	local[18]= makeint(1);
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[10] = w;
	goto WHL541;
WHX542:
	local[17]= NIL;
BLK543:
WHL544:
	local[17]= local[11];
	local[18]= makeint(128);
	ctx->vsp=local+19;
	w=(pointer)LOGTEST(ctx,2,local+17); /*logtest*/
	if (w!=NIL) goto WHX545;
	local[17]= local[11];
	local[18]= makeint(1);
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[11] = w;
	goto WHL544;
WHX545:
	local[17]= NIL;
BLK546:
WHL547:
	local[17]= local[9];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[17]= w;
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)EQ(ctx,2,local+17); /*eql*/
	if (w!=NIL) goto WHX548;
	local[3] = (pointer)((integer_t)(local[3])-4);
	goto WHL547;
WHX548:
	local[17]= NIL;
BLK549:
WHL550:
	local[17]= local[10];
	local[18]= local[4];
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[17]= w;
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)EQ(ctx,2,local+17); /*eql*/
	if (w!=NIL) goto WHX551;
	local[4] = (pointer)((integer_t)(local[4])-4);
	goto WHL550;
WHX551:
	local[17]= NIL;
BLK552:
WHL553:
	local[17]= local[11];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[17]= w;
	local[18]= local[8];
	ctx->vsp=local+19;
	w=(pointer)EQ(ctx,2,local+17); /*eql*/
	if (w!=NIL) goto WHX554;
	local[5] = (pointer)((integer_t)(local[5])-4);
	goto WHL553;
WHX554:
	local[17]= NIL;
BLK555:
	local[17]= T;
	local[18]= fqv[66];
	local[19]= local[3];
	local[20]= local[9];
	local[21]= local[4];
	local[22]= local[10];
	local[23]= local[5];
	local[24]= local[11];
	ctx->vsp=local+25;
	w=(pointer)XFORMAT(ctx,8,local+17); /*format*/
	local[15] = makeint(0);
	local[17]= makeint(0);
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)LENGTH(ctx,1,local+18); /*length*/
	local[18]= w;
WHL557:
	local[19]= local[17];
	w = local[18];
	if ((integer_t)local[19] >= (integer_t)w) goto WHX558;
	local[19]= local[15];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[15] = (pointer)((integer_t)local[19] + (integer_t)w);
	local[19]= local[11];
	local[20]= argv[0];
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[20]->c.str.chars[i]);}
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LOGAND(ctx,2,local+19); /*logand*/
	local[14] = w;
	local[19]= local[10];
	local[20]= argv[0];
	local[15] = (pointer)((integer_t)(local[15])+4);
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[20]->c.str.chars[i]);}
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LOGAND(ctx,2,local+19); /*logand*/
	local[13] = w;
	local[19]= local[9];
	local[20]= argv[0];
	local[15] = (pointer)((integer_t)(local[15])+4);
	{ register integer_t i=intval(local[15]);
	  w=makeint(local[20]->c.str.chars[i]);}
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LOGAND(ctx,2,local+19); /*logand*/
	local[12] = w;
	local[19]= local[15];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[15] = (pointer)((integer_t)local[19] + (integer_t)w);
	local[19]= local[0];
	local[20]= local[17];
	local[21]= local[12];
	local[22]= local[3];
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
	local[22]= local[13];
	local[23]= local[4];
	ctx->vsp=local+24;
	w=(pointer)ASH(ctx,2,local+22); /*ash*/
	local[22]= w;
	local[23]= local[14];
	local[24]= local[5];
	ctx->vsp=local+25;
	w=(pointer)ASH(ctx,2,local+23); /*ash*/
	w = (pointer)((integer_t)local[22] | (integer_t)w);
	w = (pointer)((integer_t)local[21] | (integer_t)w);
	{ register integer_t i; register pointer v;
	  i=intval(local[20]); v=local[19];
	  v->c.str.chars[i]=intval(w);}
	local[17] = (pointer)((integer_t)(local[17])+4);
	goto WHL557;
WHX558:
	local[19]= NIL;
BLK559:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK534:
	ctx->vsp=local; return(local[0]);}

/*color-24to6*/
static pointer F200(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT562;}
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT562:
ENT561:
	if (n>4) maerror();
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[1];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
WHL564:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX565;
	local[8]= argv[0];
	local[9]= local[1];
	w = makeint(0);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9]= (pointer)((integer_t)local[9] + (integer_t)w);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[3] = w;
	local[8]= argv[0];
	local[9]= local[1];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9]= (pointer)((integer_t)local[9] + (integer_t)w);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[4] = w;
	local[8]= argv[0];
	local[9]= local[1];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9]= (pointer)((integer_t)local[9] + (integer_t)w);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[5] = w;
	local[8]= local[1];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1] = (pointer)((integer_t)local[8] + (integer_t)w);
	local[8]= local[3];
	local[9]= makeint(-2);
	ctx->vsp=local+10;
	w=(pointer)ASH(ctx,2,local+8); /*ash*/
	local[8]= w;
	w = makeint(48);
	local[8]= (pointer)((integer_t)local[8] & (integer_t)w);
	local[9]= local[4];
	local[10]= makeint(-4);
	ctx->vsp=local+11;
	w=(pointer)ASH(ctx,2,local+9); /*ash*/
	local[9]= w;
	w = makeint(12);
	local[9]= (pointer)((integer_t)local[9] & (integer_t)w);
	local[10]= local[5];
	local[11]= makeint(-6);
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[10]= w;
	w = makeint(3);
	w = (pointer)((integer_t)local[10] & (integer_t)w);
	w = (pointer)((integer_t)local[9] | (integer_t)w);
	local[2] = (pointer)((integer_t)local[8] | (integer_t)w);
	local[8]= local[0];
	local[9]= local[6];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL564;
WHX565:
	local[8]= NIL;
BLK566:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK560:
	ctx->vsp=local; return(local[0]);}

/*color-32to8x3*/
static pointer F201(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT571;}
	local[0]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT571:
	if (n>=5) { local[1]=(argv[4]); goto ENT570;}
	local[1]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[53]); /*make-string*/
	local[1]= w;
ENT570:
	if (n>=6) { local[2]=(argv[5]); goto ENT569;}
	local[2]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[53]); /*make-string*/
	local[2]= w;
ENT569:
ENT568:
	if (n>6) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[8]);
		local[8]=(makeint(i * j));}
WHL573:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX574;
	local[9]= argv[0];
	{ register integer_t i=intval(local[6]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[3] = w;
	local[9]= argv[0];
	{ register integer_t i=intval((pointer)((integer_t)(local[6])+4));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[4] = w;
	local[9]= argv[0];
	local[10]= local[6];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[5] = w;
	local[9]= local[2];
	local[10]= local[7];
	w = local[5];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[1];
	local[10]= local[7];
	w = local[4];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[0];
	local[10]= local[7];
	w = local[3];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[6];
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL573;
WHX574:
	local[9]= NIL;
BLK575:
	w = NIL;
	local[0]= w;
BLK567:
	ctx->vsp=local; return(local[0]);}

/*color-24to8x3*/
static pointer F202(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT580;}
	local[0]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT580:
	if (n>=5) { local[1]=(argv[4]); goto ENT579;}
	local[1]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[53]); /*make-string*/
	local[1]= w;
ENT579:
	if (n>=6) { local[2]=(argv[5]); goto ENT578;}
	local[2]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[53]); /*make-string*/
	local[2]= w;
ENT578:
ENT577:
	if (n>6) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[1];
	{ integer_t i,j;
		j=intval(argv[2]); i=intval(local[8]);
		local[8]=(makeint(i * j));}
WHL582:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX583;
	local[9]= argv[0];
	{ register integer_t i=intval(local[6]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[3] = w;
	local[9]= argv[0];
	{ register integer_t i=intval((pointer)((integer_t)(local[6])+4));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[4] = w;
	local[9]= argv[0];
	local[10]= local[6];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[5] = w;
	local[9]= local[2];
	local[10]= local[7];
	w = local[5];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[1];
	local[10]= local[7];
	w = local[4];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[0];
	local[10]= local[7];
	w = local[3];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[6];
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL582;
WHX583:
	local[9]= NIL;
BLK584:
	w = NIL;
	local[0]= w;
BLK576:
	ctx->vsp=local; return(local[0]);}

/*swap-rgb*/
static pointer F203(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT587;}
	local[0]= makeint(3);
ENT587:
ENT586:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[1] = argv[0]->c.obj.iv[1];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[2] = w;
	local[7]= makeint(0);
	local[8]= local[2];
WHL589:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX590;
	local[9]= local[7];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[3] = w;
	local[9]= local[1];
	{ register integer_t i=intval(local[3]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[4] = w;
	local[9]= local[1];
	local[10]= local[3];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[10] + (integer_t)w));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[6] = w;
	local[9]= local[1];
	local[10]= local[3];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[10]= (pointer)((integer_t)local[10] + (integer_t)w);
	w = local[4];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[1];
	local[10]= local[3];
	w = local[6];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL589;
WHX590:
	local[9]= NIL;
BLK591:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK585:
	ctx->vsp=local; return(local[0]);}

/*:components*/
static pointer M592(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK593:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M594(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT599;}
	local[0]= NIL;
ENT599:
	if (n>=6) { local[1]=(argv[5]); goto ENT598;}
	local[1]= makeint(24);
ENT598:
	if (n>=7) { local[2]=(argv[6]); goto ENT597;}
	local[2]= makeint(3);
ENT597:
ENT596:
	if (n>7) maerror();
	argv[0]->c.obj.iv[12] = local[1];
	argv[0]->c.obj.iv[13] = local[2];
	local[3]= argv[0]->c.obj.iv[12];
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	argv[0]->c.obj.iv[14] = w;
	if (local[0]!=NIL) goto IF600;
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,3,local+3); /***/
	local[3]= w;
	local[4]= fqv[15];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,3,local+3,&ftab[2],fqv[20]); /*make-array*/
	local[0] = w;
	local[3]= local[0];
	goto IF601;
IF600:
	local[3]= NIL;
IF601:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[12]));
	local[5]= fqv[3];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= argv[3];
	local[8]= local[0];
	local[9]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,7,local+3); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK595:
	ctx->vsp=local; return(local[0]);}

/*:depth*/
static pointer M602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK603:
	ctx->vsp=local; return(local[0]);}

/*:byte-depth*/
static pointer M604(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK605:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M606(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK607:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M608(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[13];
WHL611:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX612;
	local[4]= local[1];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)ASH(ctx,2,local+4); /*ash*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[3];
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LOGIOR(ctx,2,local+4); /*logior*/
	local[1] = w;
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL611;
WHX612:
	local[4]= NIL;
BLK613:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK609:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M614(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[67];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK615:
	ctx->vsp=local; return(local[0]);}

/*:pixel-list*/
static pointer M616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[14];
WHL619:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX620;
	local[3]= argv[0];
	local[4]= argv[3];
	local[5]= local[1];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL619;
WHX620:
	local[3]= NIL;
BLK621:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK617:
	ctx->vsp=local; return(local[0]);}

/*:patch-in*/
static pointer M622(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[4]->c.obj.iv[1];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL625:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX626;
	local[8]= argv[0]->c.obj.iv[12];
	local[9]= argv[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[4] = w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[3];
	local[10]= fqv[29];
	local[11]= local[4];
	local[12]= fqv[30];
	local[13]= local[4];
	local[14]= argv[0]->c.obj.iv[12];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[31];
	local[15]= argv[0]->c.obj.iv[12];
	local[16]= local[6];
	local[17]= local[2];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,3,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,8,local+8,&ftab[1],fqv[6]); /*replace*/
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL625;
WHX626:
	local[8]= NIL;
BLK627:
	w = NIL;
	local[0]= w;
BLK623:
	ctx->vsp=local; return(local[0]);}

/*:subimage*/
static pointer M628(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[4];
	local[1]= argv[5];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,3,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[5];
WHL631:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX632;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[29];
	local[6]= local[1];
	local[7]= argv[4];
	local[8]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	local[7]= fqv[30];
	local[8]= (pointer)((integer_t)(local[1])+4);
	local[9]= argv[4];
	local[10]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,3,local+8); /***/
	local[8]= w;
	local[9]= fqv[31];
	local[10]= argv[3];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[14];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[1])(ctx,8,local+3,&ftab[1],fqv[6]); /*replace*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL631;
WHX632:
	local[3]= NIL;
BLK633:
	w = NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[4];
	local[5]= argv[5];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK629:
	ctx->vsp=local; return(local[0]);}

/*:halve*/
static pointer M635(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT638;}
	local[0]= NIL;
ENT638:
ENT637:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	if (local[0]!=NIL) goto IF639;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF640;
IF639:
	local[3]= NIL;
IF640:
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,3,local+3,&ftab[4],fqv[27]); /*halve-image*/
	w = local[0];
	local[0]= w;
BLK636:
	ctx->vsp=local; return(local[0]);}

/*:double*/
static pointer M642(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT645;}
	local[0]= NIL;
ENT645:
ENT644:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	if (local[0]!=NIL) goto IF646;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF647;
IF646:
	local[3]= NIL;
IF647:
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,3,local+3,&ftab[5],fqv[28]); /*double-image*/
	w = local[0];
	local[0]= w;
BLK643:
	ctx->vsp=local; return(local[0]);}

/*:display*/
static pointer M649(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT654;}
	local[0]= loadglobal(fqv[39]);
ENT654:
	if (n>=4) { local[1]=(argv[3]); goto ENT653;}
	local[1]= makeint(0);
ENT653:
	if (n>=5) { local[2]=(argv[4]); goto ENT652;}
	local[2]= makeint(0);
ENT652:
ENT651:
	if (n>5) maerror();
	local[3]= local[0];
	local[4]= fqv[40];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	local[5]= local[4];
	if (fqv[68]!=local[5]) goto IF656;
	local[5]= local[0];
	local[6]= fqv[42];
	if (loadglobal(fqv[32])==NIL) goto IF658;
	local[7]= argv[0];
	local[8]= fqv[36];
	local[9]= loadglobal(fqv[69]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w->c.obj.iv[1];
	goto IF659;
IF658:
	local[7]= argv[0]->c.obj.iv[1];
IF659:
	local[8]= fqv[43];
	local[9]= local[1];
	local[10]= fqv[44];
	local[11]= local[2];
	local[12]= fqv[4];
	local[13]= argv[0]->c.obj.iv[6];
	local[14]= fqv[5];
	local[15]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,11,local+5); /*send*/
	local[5]= w;
	goto IF657;
IF656:
	local[5]= local[4];
	if (fqv[70]!=local[5]) goto IF660;
	local[5]= local[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[46];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF661;
IF660:
	local[5]= local[4];
	if (fqv[71]!=local[5]) goto IF662;
	local[5]= local[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[48];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF663;
IF662:
	local[5]= local[4];
	if (fqv[72]!=local[5]) goto IF664;
	local[5]= local[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[50];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF665;
IF664:
	if (T==NIL) goto IF666;
	local[5]= fqv[73];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,2,local+5,&ftab[7],fqv[52]); /*warn*/
	local[5]= w;
	goto IF667;
IF666:
	local[5]= NIL;
IF667:
IF665:
IF663:
IF661:
IF657:
	w = local[5];
	w = argv[0];
	local[0]= w;
BLK650:
	ctx->vsp=local; return(local[0]);}

/*:component*/
static pointer M668(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT671;}
	local[0]= NIL;
ENT671:
ENT670:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	if (local[0]!=NIL) goto IF672;
	local[5]= loadglobal(fqv[74]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[3];
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = local[5];
	local[0] = w;
	local[5]= local[0];
	goto IF673;
IF672:
	local[5]= NIL;
IF673:
	local[5]= local[0];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[1] = w;
	local[5]= makeint(0);
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
WHL676:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX677;
	local[7]= local[1];
	local[8]= local[5];
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	local[11]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.str.chars[i]=intval(w);}
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL676;
WHX677:
	local[7]= NIL;
BLK678:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK669:
	ctx->vsp=local; return(local[0]);}

/*:red*/
static pointer M679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK680:
	ctx->vsp=local; return(local[0]);}

/*:green*/
static pointer M681(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK682:
	ctx->vsp=local; return(local[0]);}

/*:blue*/
static pointer M683(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK684:
	ctx->vsp=local; return(local[0]);}

/*:pseudo2true*/
static pointer M685(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[75];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= local[0];
WHL688:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX689;
	local[7]= local[2];
	{ register integer_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[1] = w;
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[4] = w;
	local[7]= makeint(0);
	local[8]= argv[0]->c.obj.iv[12];
WHL692:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX693;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	w = local[1];
	{ register integer_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL692;
WHX693:
	local[9]= NIL;
BLK694:
	w = NIL;
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL688;
WHX689:
	local[7]= NIL;
BLK690:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK686:
	ctx->vsp=local; return(local[0]);}

/*:monochromize*/
static pointer M695(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT698;}
	local[0]= NIL;
ENT698:
ENT697:
	if (n>3) maerror();
	if (local[0]!=NIL) goto IF699;
	local[1]= loadglobal(fqv[74]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[0];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= local[0];
	goto IF700;
IF699:
	local[1]= NIL;
IF700:
	local[1]= local[0];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
WHL703:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX704;
	local[4]= makeint(0);
	local[5]= local[2];
	local[6]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[14];
WHL707:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX708;
	local[8]= local[4];
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	w = local[6];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[10] + (integer_t)w));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[4] = w;
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL707;
WHX708:
	local[8]= NIL;
BLK709:
	w = NIL;
	local[6]= local[1];
	local[7]= local[2];
	local[8]= local[4];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	{ register integer_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL703;
WHX704:
	local[4]= NIL;
BLK705:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK696:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M710(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT713;}
	local[0]= NIL;
ENT713:
ENT712:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= makeint(16);
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,8,local+1); /*send-message*/
	local[0]= w;
BLK711:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M714(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[3];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= fqv[64];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK715:
	ctx->vsp=local; return(local[0]);}

/*:set-pixel*/
static pointer M716(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[4];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO718,env,argv,local);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,0,local+3,&ftab[11],fqv[64]); /*:short*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)POKE(ctx,3,local+0); /*system:poke*/
	local[0]= w;
BLK717:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M719(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[77];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK720:
	ctx->vsp=local; return(local[0]);}

/*:pixel-list*/
static pointer M721(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(11);
	local[3]= makeint(5);
	ctx->vsp=local+4;
	w=(pointer)LDB(ctx,3,local+1); /*ldb*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(5);
	local[4]= makeint(6);
	ctx->vsp=local+5;
	w=(pointer)LDB(ctx,3,local+2); /*ldb*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint(0);
	local[5]= makeint(5);
	ctx->vsp=local+6;
	w=(pointer)LDB(ctx,3,local+3); /*ldb*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK722:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M723(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK724:
	ctx->vsp=local; return(local[0]);}

/*:component*/
static pointer M725(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[78];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK726:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO718(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[79],w);
	local[3]= env->c.clo.env1[3];
	local[4]= env->c.clo.env1[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:pixel-list*/
static pointer M727(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[14];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[0]);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[0])+4));
	  w=makeint(local[2]->c.str.chars[i]);}
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= local[0];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ register integer_t i=intval((pointer)((integer_t)local[4] + (integer_t)w));
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK728:
	ctx->vsp=local; return(local[0]);}

/*:to24*/
static pointer M729(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK730:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M731(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[80]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F198(ctx,3,local+5); /*color-24to16*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK732:
	ctx->vsp=local; return(local[0]);}

/*:from32*/
static pointer M734(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F195(ctx,4,local+0); /*color-32to24*/
	w = argv[0];
	local[0]= w;
BLK735:
	ctx->vsp=local; return(local[0]);}

/*:to32*/
static pointer M736(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT739;}
	local[0]= NIL;
ENT739:
ENT738:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F196(ctx,3,local+4); /*color-24to32*/
	local[3] = w;
	local[4]= loadglobal(fqv[81]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[3];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK737:
	ctx->vsp=local; return(local[0]);}

/*:hls*/
static pointer M741(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT744;}
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT744:
ENT743:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[75];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
WHL747:
	local[12]= local[10];
	w = local[11];
	if ((integer_t)local[12] >= (integer_t)w) goto WHX748;
	local[12]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[9]);
	  w=makeint(local[12]->c.str.chars[i]);}
	local[7] = w;
	local[12]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[9])+4));
	  w=makeint(local[12]->c.str.chars[i]);}
	local[6] = w;
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[9];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[12]->c.str.chars[i]);}
	local[5] = w;
	local[12]= local[5];
	local[13]= local[6];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,3,local+12,&ftab[12],fqv[82]); /*rgb-to-hls*/
	local[8] = w;
	local[12]= local[3];
	local[13]= local[9];
	local[14]= local[8];
	local[15]= makeint(16);
	local[16]= makeint(8);
	ctx->vsp=local+17;
	w=(pointer)LDB(ctx,3,local+14); /*ldb*/
	{ register integer_t i; register pointer v;
	  i=intval(local[13]); v=local[12];
	  v->c.str.chars[i]=intval(w);}
	local[12]= local[3];
	local[13]= (pointer)((integer_t)(local[9])+4);
	local[14]= local[8];
	local[15]= makeint(8);
	local[16]= makeint(8);
	ctx->vsp=local+17;
	w=(pointer)LDB(ctx,3,local+14); /*ldb*/
	{ register integer_t i; register pointer v;
	  i=intval(local[13]); v=local[12];
	  v->c.str.chars[i]=intval(w);}
	local[12]= local[3];
	local[13]= local[9];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[8];
	local[15]= makeint(0);
	local[16]= makeint(8);
	ctx->vsp=local+17;
	w=(pointer)LDB(ctx,3,local+14); /*ldb*/
	{ register integer_t i; register pointer v;
	  i=intval(local[13]); v=local[12];
	  v->c.str.chars[i]=intval(w);}
	local[12]= local[9];
	local[13]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[9] = w;
	local[10] = (pointer)((integer_t)(local[10])+4);
	goto WHL747;
WHX748:
	local[12]= NIL;
BLK749:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK742:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M750(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT753;}
	local[0]= NIL;
ENT753:
ENT752:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= makeint(32);
	local[8]= makeint(4);
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,8,local+1); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK751:
	ctx->vsp=local; return(local[0]);}

/*:from24*/
static pointer M754(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F196(ctx,4,local+0); /*color-24to32*/
	w = argv[0];
	local[0]= w;
BLK755:
	ctx->vsp=local; return(local[0]);}

/*:to24*/
static pointer M756(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT759;}
	local[0]= NIL;
ENT759:
ENT758:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F195(ctx,3,local+4); /*color-32to24*/
	local[3] = w;
	local[4]= loadglobal(fqv[59]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[3];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK757:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M761(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK762:
	ctx->vsp=local; return(local[0]);}

/*:to8*/
static pointer M763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT766;}
	local[0]= NIL;
ENT766:
ENT765:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[0];
	local[7]= loadglobal(fqv[83]);
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,1,local+7,&ftab[13],fqv[84]); /*x::visual-masks*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F199(ctx,5,local+3); /*color-32to8*/
	local[0] = w;
	local[3]= loadglobal(fqv[74]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK764:
	ctx->vsp=local; return(local[0]);}

/*:hls*/
static pointer M768(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT771;}
	local[0]= loadglobal(fqv[81]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT771:
ENT770:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[75];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= local[1];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
WHL774:
	local[11]= local[9];
	w = local[10];
	if ((integer_t)local[11] >= (integer_t)w) goto WHX775;
	local[11]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[8]);
	  w=makeint(local[11]->c.str.chars[i]);}
	local[6] = w;
	local[11]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[8])+4));
	  w=makeint(local[11]->c.str.chars[i]);}
	local[5] = w;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[8];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[11]->c.str.chars[i]);}
	local[4] = w;
	local[11]= local[4];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[12])(ctx,3,local+11,&ftab[12],fqv[82]); /*rgb-to-hls*/
	local[7] = w;
	local[11]= local[3];
	local[12]= local[8];
	local[13]= local[7];
	local[14]= makeint(16);
	local[15]= makeint(8);
	ctx->vsp=local+16;
	w=(pointer)LDB(ctx,3,local+13); /*ldb*/
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.str.chars[i]=intval(w);}
	local[11]= local[3];
	local[12]= (pointer)((integer_t)(local[8])+4);
	local[13]= local[7];
	local[14]= makeint(8);
	local[15]= makeint(8);
	ctx->vsp=local+16;
	w=(pointer)LDB(ctx,3,local+13); /*ldb*/
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.str.chars[i]=intval(w);}
	local[11]= local[3];
	local[12]= local[8];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint(0);
	local[15]= makeint(8);
	ctx->vsp=local+16;
	w=(pointer)LDB(ctx,3,local+13); /*ldb*/
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.str.chars[i]=intval(w);}
	local[11]= local[8];
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[8] = w;
	local[9] = (pointer)((integer_t)(local[9])+4);
	goto WHL774;
WHX775:
	local[11]= NIL;
BLK776:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK769:
	ctx->vsp=local; return(local[0]);}

/*:component*/
static pointer M777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT780;}
	local[0]= loadglobal(fqv[74]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT780:
ENT779:
	if (n>4) maerror();
	local[1]= local[0];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint(0);
	local[4]= argv[0];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL783:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX784;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= local[3];
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL783;
WHX784:
	local[5]= NIL;
BLK785:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK778:
	ctx->vsp=local; return(local[0]);}

/*:red*/
static pointer M786(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK787:
	ctx->vsp=local; return(local[0]);}

/*:green*/
static pointer M788(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK789:
	ctx->vsp=local; return(local[0]);}

/*:blue*/
static pointer M790(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK791:
	ctx->vsp=local; return(local[0]);}

/*:monochromize*/
static pointer M792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT795;}
	local[0]= loadglobal(fqv[74]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT795:
ENT794:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(1);
	local[3]= makeint(0);
	local[4]= argv[0];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL798:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX799;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[2])+4));
	  w=makeint(local[8]->c.str.chars[i]);}
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[2];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register integer_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,3,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	{ register integer_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[2];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[2] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL798;
WHX799:
	local[5]= NIL;
BLK800:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK793:
	ctx->vsp=local; return(local[0]);}

/*color-to-deep*/
static pointer F204(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[59]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK801:
	ctx->vsp=local; return(local[0]);}

/*copy-color-map*/
static pointer F205(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
WHL805:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX806;
	local[2]= argv[0];
	local[3]= fqv[85];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[86];
	local[5]= NIL;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL805;
WHX806:
	local[2]= NIL;
BLK807:
	w = NIL;
	local[0]= w;
BLK803:
	ctx->vsp=local; return(local[0]);}

/*make-ximage*/
static pointer F206(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT810;}
	local[0]= loadglobal(fqv[38]);
ENT810:
ENT809:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[87];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[1] = w;
	local[2]= local[1];
	local[3]= fqv[88];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK808:
	ctx->vsp=local; return(local[0]);}

/*make-colors*/
static pointer F207(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF812;
	local[0]= loadglobal(fqv[89]);
	storeglobal(fqv[90],local[0]);
	goto IF813;
IF812:
	local[0]= loadglobal(fqv[91]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[92];
	local[3]= fqv[93];
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	storeglobal(fqv[90],w);
	local[0]= loadglobal(fqv[89]);
	local[1]= loadglobal(fqv[90]);
	local[2]= makeint(32);
	ctx->vsp=local+3;
	w=(pointer)F205(ctx,3,local+0); /*copy-color-map*/
	local[0]= w;
IF813:
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[94];
	local[2]= fqv[95];
	local[3]= makeint(16);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[96],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[94];
	local[2]= fqv[97];
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[98],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[99];
	local[2]= fqv[100];
	local[3]= makeint(32);
	local[4]= makeint(0);
	local[5]= makeint(360);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[101],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[99];
	local[2]= fqv[102];
	local[3]= makeint(16);
	local[4]= makeint(0);
	local[5]= makeint(360);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[103],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[104];
	local[2]= fqv[105];
	local[3]= makeint(16);
	local[4]= makeint(0);
	local[5]= makeflt(9.99999940e-02);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[106],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[104];
	local[2]= fqv[107];
	local[3]= makeint(16);
	local[4]= makeint(120);
	local[5]= makeflt(9.99999940e-02);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[108],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[104];
	local[2]= fqv[109];
	local[3]= makeint(16);
	local[4]= makeint(240);
	local[5]= makeflt(9.99999940e-02);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[110],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[111];
	local[2]= fqv[112];
	local[3]= fqv[113];
	local[4]= makeint(65535);
	local[5]= makeint(40000);
	local[6]= makeint(40000);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	local[5]= fqv[114];
	local[6]= fqv[115];
	local[7]= fqv[116];
	local[8]= fqv[117];
	local[9]= fqv[118];
	local[10]= fqv[119];
	local[11]= fqv[120];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,9,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[121],w);
	local[0]= makeint(8);
	ctx->vsp=local+1;
	w=(pointer)F191(ctx,1,local+0); /*make-equilevel-lut*/
	local[0]= w;
	storeglobal(fqv[122],w);
	local[0]= makeint(16);
	ctx->vsp=local+1;
	w=(pointer)F191(ctx,1,local+0); /*make-equilevel-lut*/
	local[0]= w;
	storeglobal(fqv[123],w);
	local[0]= makeint(32);
	ctx->vsp=local+1;
	w=(pointer)F191(ctx,1,local+0); /*make-equilevel-lut*/
	local[0]= w;
	storeglobal(fqv[124],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[96]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[125],w);
	local[0]= loadglobal(fqv[124]);
	local[1]= loadglobal(fqv[98]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[38],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[103]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[126],w);
	local[0]= loadglobal(fqv[124]);
	local[1]= loadglobal(fqv[101]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[127],w);
	local[0]= loadglobal(fqv[123]);
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	local[1]= loadglobal(fqv[101]);
	local[2]= makeint(8);
	local[3]= makeint(24);
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[128],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[106]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[129],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[108]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[130],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[110]);
	ctx->vsp=local+2;
	w=(pointer)F194(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[131],w);
	w = local[0];
	local[0]= w;
BLK811:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___piximage(ctx,n,argv,env)
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
	local[0]= fqv[132];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF815;
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[134],w);
	goto IF816;
IF815:
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF816:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(*ftab[14])(ctx,1,local+0,&ftab[14],fqv[139]); /*use-package*/
	local[0]= fqv[125];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF817;
	local[0]= fqv[125];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[125];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF819;
	local[0]= fqv[125];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF820;
IF819:
	local[0]= NIL;
IF820:
	local[0]= fqv[125];
	goto IF818;
IF817:
	local[0]= NIL;
IF818:
	local[0]= fqv[38];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF821;
	local[0]= fqv[38];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF823;
	local[0]= fqv[38];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF824;
IF823:
	local[0]= NIL;
IF824:
	local[0]= fqv[38];
	goto IF822;
IF821:
	local[0]= NIL;
IF822:
	local[0]= fqv[128];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF825;
	local[0]= fqv[128];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF827;
	local[0]= fqv[128];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF828;
IF827:
	local[0]= NIL;
IF828:
	local[0]= fqv[128];
	goto IF826;
IF825:
	local[0]= NIL;
IF826:
	local[0]= fqv[129];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF829;
	local[0]= fqv[129];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[129];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF831;
	local[0]= fqv[129];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF832;
IF831:
	local[0]= NIL;
IF832:
	local[0]= fqv[129];
	goto IF830;
IF829:
	local[0]= NIL;
IF830:
	local[0]= fqv[130];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF833;
	local[0]= fqv[130];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF835;
	local[0]= fqv[130];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF836;
IF835:
	local[0]= NIL;
IF836:
	local[0]= fqv[130];
	goto IF834;
IF833:
	local[0]= NIL;
IF834:
	local[0]= fqv[131];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF837;
	local[0]= fqv[131];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF839;
	local[0]= fqv[131];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF840;
IF839:
	local[0]= NIL;
IF840:
	local[0]= fqv[131];
	goto IF838;
IF837:
	local[0]= NIL;
IF838:
	local[0]= fqv[126];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF841;
	local[0]= fqv[126];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[126];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF843;
	local[0]= fqv[126];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF844;
IF843:
	local[0]= NIL;
IF844:
	local[0]= fqv[126];
	goto IF842;
IF841:
	local[0]= NIL;
IF842:
	local[0]= fqv[127];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF845;
	local[0]= fqv[127];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF847;
	local[0]= fqv[127];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF848;
IF847:
	local[0]= NIL;
IF848:
	local[0]= fqv[127];
	goto IF846;
IF845:
	local[0]= NIL;
IF846:
	local[0]= fqv[142];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF849;
	local[0]= fqv[142];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[142];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF851;
	local[0]= fqv[142];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF852;
IF851:
	local[0]= NIL;
IF852:
	local[0]= fqv[142];
	goto IF850;
IF849:
	local[0]= NIL;
IF850:
	local[0]= fqv[96];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF853;
	local[0]= fqv[96];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF855;
	local[0]= fqv[96];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF856;
IF855:
	local[0]= NIL;
IF856:
	local[0]= fqv[96];
	goto IF854;
IF853:
	local[0]= NIL;
IF854:
	local[0]= fqv[98];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF857;
	local[0]= fqv[98];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[98];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF859;
	local[0]= fqv[98];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF860;
IF859:
	local[0]= NIL;
IF860:
	local[0]= fqv[98];
	goto IF858;
IF857:
	local[0]= NIL;
IF858:
	local[0]= fqv[103];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF861;
	local[0]= fqv[103];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[103];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF863;
	local[0]= fqv[103];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF864;
IF863:
	local[0]= NIL;
IF864:
	local[0]= fqv[103];
	goto IF862;
IF861:
	local[0]= NIL;
IF862:
	local[0]= fqv[101];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF865;
	local[0]= fqv[101];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF867;
	local[0]= fqv[101];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF868;
IF867:
	local[0]= NIL;
IF868:
	local[0]= fqv[101];
	goto IF866;
IF865:
	local[0]= NIL;
IF866:
	local[0]= fqv[106];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF869;
	local[0]= fqv[106];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[106];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF871;
	local[0]= fqv[106];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF872;
IF871:
	local[0]= NIL;
IF872:
	local[0]= fqv[106];
	goto IF870;
IF869:
	local[0]= NIL;
IF870:
	local[0]= fqv[108];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF873;
	local[0]= fqv[108];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[108];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF875;
	local[0]= fqv[108];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF876;
IF875:
	local[0]= NIL;
IF876:
	local[0]= fqv[108];
	goto IF874;
IF873:
	local[0]= NIL;
IF874:
	local[0]= fqv[110];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF877;
	local[0]= fqv[110];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[110];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF879;
	local[0]= fqv[110];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF880;
IF879:
	local[0]= NIL;
IF880:
	local[0]= fqv[110];
	goto IF878;
IF877:
	local[0]= NIL;
IF878:
	local[0]= fqv[121];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF881;
	local[0]= fqv[121];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[121];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF883;
	local[0]= fqv[121];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF884;
IF883:
	local[0]= NIL;
IF884:
	local[0]= fqv[121];
	goto IF882;
IF881:
	local[0]= NIL;
IF882:
	local[0]= fqv[122];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF885;
	local[0]= fqv[122];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF887;
	local[0]= fqv[122];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF888;
IF887:
	local[0]= NIL;
IF888:
	local[0]= fqv[122];
	goto IF886;
IF885:
	local[0]= NIL;
IF886:
	local[0]= fqv[123];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF889;
	local[0]= fqv[123];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[123];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF891;
	local[0]= fqv[123];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF892;
IF891:
	local[0]= NIL;
IF892:
	local[0]= fqv[123];
	goto IF890;
IF889:
	local[0]= NIL;
IF890:
	local[0]= fqv[124];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF893;
	local[0]= fqv[124];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[124];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF895;
	local[0]= fqv[124];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF896;
IF895:
	local[0]= NIL;
IF896:
	local[0]= fqv[124];
	goto IF894;
IF893:
	local[0]= NIL;
IF894:
	local[0]= fqv[90];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF897;
	local[0]= fqv[90];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[90];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF899;
	local[0]= fqv[90];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF900;
IF899:
	local[0]= NIL;
IF900:
	local[0]= fqv[90];
	goto IF898;
IF897:
	local[0]= NIL;
IF898:
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F191,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F192,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F193,fqv[148]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F194,fqv[150]);
	local[0]= fqv[151];
	local[1]= fqv[141];
	local[2]= fqv[151];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[153]);
	local[5]= fqv[154];
	local[6]= fqv[155];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[159];
	local[1]= fqv[141];
	local[2]= fqv[159];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[151]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[161];
	local[1]= fqv[141];
	local[2]= fqv[161];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[159]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[74];
	local[1]= fqv[141];
	local[2]= fqv[74];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[159]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	local[1]= fqv[141];
	local[2]= fqv[33];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[159]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[162];
	local[1]= fqv[141];
	local[2]= fqv[162];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[151]);
	local[5]= fqv[154];
	local[6]= fqv[163];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[164];
	local[1]= fqv[141];
	local[2]= fqv[164];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[162]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[165];
	local[1]= fqv[141];
	local[2]= fqv[165];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[162]);
	local[5]= fqv[154];
	local[6]= fqv[166];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[80];
	local[1]= fqv[141];
	local[2]= fqv[80];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[165]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[59];
	local[1]= fqv[141];
	local[2]= fqv[59];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[165]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[81];
	local[1]= fqv[141];
	local[2]= fqv[81];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[165]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M245,fqv[75],fqv[151],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M247,fqv[4],fqv[151],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M249,fqv[5],fqv[151],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M251,fqv[58],fqv[151],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M253,fqv[24],fqv[151],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M255,fqv[23],fqv[151],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M257,fqv[25],fqv[151],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M261,fqv[174],fqv[151],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M263,fqv[176],fqv[151],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M265,fqv[178],fqv[151],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M281,fqv[13],fqv[151],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M284,fqv[3],fqv[151],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M296,fqv[22],fqv[151],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M298,fqv[183],fqv[151],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M300,fqv[185],fqv[151],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M313,fqv[187],fqv[151],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M321,fqv[189],fqv[151],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M329,fqv[24],fqv[159],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M331,fqv[23],fqv[159],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M333,fqv[9],fqv[159],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M335,fqv[194],fqv[159],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M342,fqv[196],fqv[159],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M349,fqv[198],fqv[159],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M355,fqv[36],fqv[159],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M364,fqv[34],fqv[159],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M372,fqv[88],fqv[159],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M392,fqv[203],fqv[159],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M399,fqv[198],fqv[159],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M405,fqv[206],fqv[159],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M413,fqv[208],fqv[159],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M421,fqv[210],fqv[159],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M423,fqv[212],fqv[159],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M431,fqv[214],fqv[159],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M441,fqv[87],fqv[159],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M445,fqv[217],fqv[159],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M449,fqv[48],fqv[159],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M456,fqv[50],fqv[159],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M458,fqv[46],fqv[159],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M460,fqv[3],fqv[161],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M464,fqv[9],fqv[161],fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F195,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F196,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F197,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F198,fqv[231]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[232],module,F199,fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F200,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F201,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F202,fqv[239]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[240],module,F203,fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M592,fqv[242],fqv[162],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M594,fqv[3],fqv[165],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M602,fqv[40],fqv[165],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M604,fqv[246],fqv[165],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M606,fqv[4],fqv[165],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M608,fqv[24],fqv[165],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M614,fqv[9],fqv[165],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M616,fqv[251],fqv[165],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M622,fqv[198],fqv[165],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M628,fqv[203],fqv[165],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M635,fqv[194],fqv[165],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M642,fqv[196],fqv[165],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M649,fqv[88],fqv[165],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M668,fqv[76],fqv[165],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M679,fqv[259],fqv[165],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M681,fqv[261],fqv[165],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M683,fqv[263],fqv[165],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M685,fqv[265],fqv[165],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M695,fqv[267],fqv[165],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M710,fqv[3],fqv[80],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M714,fqv[24],fqv[80],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M716,fqv[23],fqv[80],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M719,fqv[9],fqv[80],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M721,fqv[251],fqv[80],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M723,fqv[46],fqv[80],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M725,fqv[76],fqv[80],fqv[275]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M727,fqv[251],fqv[59],fqv[276]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M729,fqv[48],fqv[59],fqv[277]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M731,fqv[46],fqv[59],fqv[278]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M734,fqv[279],fqv[59],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M736,fqv[50],fqv[59],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M741,fqv[282],fqv[59],fqv[283]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M750,fqv[3],fqv[81],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M754,fqv[285],fqv[81],fqv[286]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M756,fqv[48],fqv[81],fqv[287]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M761,fqv[46],fqv[81],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M763,fqv[289],fqv[81],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M768,fqv[282],fqv[81],fqv[291]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M777,fqv[76],fqv[81],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M786,fqv[259],fqv[81],fqv[293]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M788,fqv[261],fqv[81],fqv[294]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M790,fqv[263],fqv[81],fqv[295]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M792,fqv[267],fqv[81],fqv[296]);
	local[0]= fqv[297];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[297],module,F204,fqv[298]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[299],module,F205,fqv[300]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[301],module,F206,fqv[302]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F207,fqv[304]);
	local[0]= fqv[305];
	local[1]= fqv[306];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[307]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<17; i++) ftab[i]=fcallx;
}
