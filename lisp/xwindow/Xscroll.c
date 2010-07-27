/* Xscroll.c :  entry=Xscroll */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xscroll.h"
#pragma init (register_Xscroll)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xscroll();
extern pointer build_quote_vector();
static register_Xscroll()
  { add_module_initializer("___Xscroll", ___Xscroll);}


/*:create*/
static pointer M3188(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3190:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3191;
	local[1] = NIL;
KEY3191:
	if (n & (1<<1)) goto KEY3192;
	local[2] = NIL;
KEY3192:
	if (n & (1<<2)) goto KEY3193;
	local[3] = NIL;
KEY3193:
	if (local[2]!=NIL) goto IF3194;
	if (local[1]==NIL) goto IF3196;
	local[4]= local[1];
	local[5]= fqv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(15);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	goto IF3197;
IF3196:
	local[4]= makeint(150);
IF3197:
	local[2] = local[4];
	local[4]= local[2];
	goto IF3195;
IF3194:
	local[4]= NIL;
IF3195:
	local[4]= (pointer)get_sym_func(fqv[2]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[3]));
	local[7]= fqv[4];
	local[8]= fqv[5];
	local[9]= makeint(1);
	local[10]= fqv[6];
	local[11]= makeint(3855);
	local[12]= fqv[7];
	local[13]= local[1];
	local[14]= fqv[1];
	local[15]= local[2];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,13,local+4); /*apply*/
	local[4]= argv[0];
	local[5]= fqv[8];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0];
	local[5]= fqv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	argv[0]->c.obj.iv[6] = w;
	local[4]= makeint(3);
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	argv[0]->c.obj.iv[12] = w;
	argv[0]->c.obj.iv[13] = argv[0]->c.obj.iv[12];
	argv[0]->c.obj.iv[14] = argv[0]->c.obj.iv[12];
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	argv[0]->c.obj.iv[15] = w;
	if (local[1]==NIL) goto IF3198;
	local[4]= argv[0];
	local[5]= fqv[9];
	if (argv[0]->c.obj.iv[15]==NIL) goto IF3200;
	local[6]= local[1];
	local[7]= fqv[8];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,3,local+6); /*-*/
	local[6]= w;
	goto IF3201;
IF3200:
	local[6]= makeint(0);
IF3201:
	if (argv[0]->c.obj.iv[15]==NIL) goto IF3202;
	local[7]= makeint(0);
	goto IF3203;
IF3202:
	local[7]= local[1];
	local[8]= fqv[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,3,local+7); /*-*/
	local[7]= w;
IF3203:
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF3199;
IF3198:
	local[4]= NIL;
IF3199:
	local[4]= argv[0];
	local[5]= fqv[10];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[11];
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(9.99999940e-02);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK3189:
	ctx->vsp=local; return(local[0]);}

/*:draw-pattern*/
static pointer M3204(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= local[0];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= makeint(0);
	local[4]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[0]= w;
BLK3205:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3206(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[3]));
	local[2]= fqv[13];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0];
	local[1]= fqv[10];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3207:
	ctx->vsp=local; return(local[0]);}

/*:move-handle*/
static pointer M3208(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3212;}
	local[0]= makeflt(0.00000000e+00);
ENT3212:
	if (n>=4) { local[1]=(argv[3]); goto ENT3211;}
	local[1]= makeflt(9.99999940e-02);
ENT3211:
ENT3210:
	if (n>4) maerror();
	if (argv[0]->c.obj.iv[15]==NIL) goto IF3213;
	local[2]= argv[0];
	local[3]= fqv[15];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[13];
	local[6]= fqv[1];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= w;
	goto IF3214;
IF3213:
	local[2]= argv[0];
	local[3]= fqv[15];
	local[4]= fqv[17];
	local[5]= argv[0]->c.obj.iv[13];
	local[6]= fqv[8];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= w;
IF3214:
	if (argv[0]->c.obj.iv[15]==NIL) goto IF3215;
	local[2]= argv[0]->c.obj.iv[6];
	goto IF3216;
IF3215:
	local[2]= argv[0]->c.obj.iv[5];
IF3216:
	local[3]= makeint(2);
	local[4]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	argv[0]->c.obj.iv[14] = w;
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[12];
	local[4]= local[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[0]->c.obj.iv[13] = w;
	if (argv[0]->c.obj.iv[15]==NIL) goto IF3217;
	local[3]= argv[0];
	local[4]= fqv[18];
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[13];
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= argv[0]->c.obj.iv[14];
	local[9]= loadglobal(fqv[19]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[3]= w;
	goto IF3218;
IF3217:
	local[3]= argv[0];
	local[4]= fqv[18];
	local[5]= argv[0]->c.obj.iv[13];
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[14];
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= loadglobal(fqv[19]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[3]= w;
IF3218:
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,0,local+3,&ftab[0],fqv[20]); /*xflush*/
	local[0]= w;
BLK3209:
	ctx->vsp=local; return(local[0]);}

/*:hit-region*/
static pointer M3219(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[21],w);
	local[3]= loadglobal(fqv[21]);
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[22]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[21]);
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[23]); /*event-y*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	if (argv[0]->c.obj.iv[15]==NIL) goto IF3221;
	local[5] = local[4];
	local[6] = argv[0]->c.obj.iv[6];
	local[7]= local[6];
	goto IF3222;
IF3221:
	local[5] = local[3];
	local[6] = argv[0]->c.obj.iv[5];
	local[7]= local[6];
IF3222:
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto OR3225;
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto OR3225;
	local[7]= local[4];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto OR3225;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto OR3225;
	goto CON3224;
OR3225:
	local[7]= fqv[24];
	goto CON3223;
CON3224:
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON3226;
	local[7]= fqv[25];
	goto CON3223;
CON3226:
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON3227;
	local[7]= fqv[26];
	goto CON3223;
CON3227:
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[13];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON3228;
	local[7]= fqv[27];
	goto CON3223;
CON3228:
	local[7]= local[5];
	local[8]= local[6];
	local[9]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON3229;
	local[7]= fqv[28];
	goto CON3223;
CON3229:
	local[7]= local[5];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON3230;
	local[7]= fqv[29];
	goto CON3223;
CON3230:
	local[7]= NIL;
	goto CON3223;
CON3231:
	local[7]= NIL;
CON3223:
	w = local[7];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3220:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M3232(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[21],w);
	local[3]= argv[0];
	local[4]= fqv[10];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[30];
	local[5]= loadglobal(fqv[21]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	if (fqv[27]!=local[4]) goto IF3235;
	local[4]= loadglobal(fqv[21]);
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[23]); /*event-y*/
	argv[0]->c.obj.iv[16] = w;
	local[4]= argv[0]->c.obj.iv[16];
	goto IF3236;
IF3235:
	local[4]= local[3];
	if (fqv[25]!=local[4]) goto IF3237;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[31];
	local[6]= makeint(-1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3238;
IF3237:
	local[4]= local[3];
	if (fqv[29]!=local[4]) goto IF3239;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[31];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3240;
IF3239:
	local[4]= local[3];
	if (fqv[26]!=local[4]) goto IF3241;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[31];
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3242;
IF3241:
	local[4]= local[3];
	if (fqv[28]!=local[4]) goto IF3243;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[31];
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3244;
IF3243:
	if (T==NIL) goto IF3245;
	local[4]= NIL;
	goto IF3246;
IF3245:
	local[4]= NIL;
IF3246:
IF3244:
IF3242:
IF3240:
IF3238:
IF3236:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3233:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M3247(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[21],w);
	if (argv[0]->c.obj.iv[16]==NIL) goto IF3249;
	local[3]= loadglobal(fqv[21]);
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[22]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[21]);
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[23]); /*event-y*/
	local[4]= w;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= makeint(2);
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[7];
	local[8]= fqv[33];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)GREQP(ctx,2,local+6); /*>=*/
	if (w==NIL) goto IF3251;
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[31];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	argv[0]->c.obj.iv[16] = local[4];
	local[6]= argv[0]->c.obj.iv[16];
	goto IF3252;
IF3251:
	local[6]= NIL;
IF3252:
	w = local[6];
	local[3]= w;
	goto IF3250;
IF3249:
	local[3]= NIL;
IF3250:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3248:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[21],w);
	argv[0]->c.obj.iv[16] = NIL;
	local[3]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3254:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3257:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[34], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3258;
	local[1] = NIL;
KEY3258:
	if (n & (1<<1)) goto KEY3259;
	local[2] = NIL;
KEY3259:
	if (local[2]!=NIL) goto IF3260;
	if (local[1]==NIL) goto IF3262;
	local[3]= local[1];
	local[4]= fqv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(15);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	goto IF3263;
IF3262:
	local[3]= makeint(100);
IF3263:
	local[2] = local[3];
	local[3]= local[2];
	goto IF3261;
IF3260:
	local[3]= NIL;
IF3261:
	local[3]= (pointer)get_sym_func(fqv[2]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[3]));
	local[6]= fqv[4];
	local[7]= fqv[8];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,7,local+3); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3256:
	ctx->vsp=local; return(local[0]);}

/*:draw-pattern*/
static pointer M3264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= makeint(0);
	local[4]= local[0];
	local[5]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	local[4]= makeint(0);
	local[5]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= (pointer)((integer_t)(argv[0]->c.obj.iv[12])-4);
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= makeint(0);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[14];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK3265:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M3266(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[21],w);
	local[3]= argv[0];
	local[4]= fqv[10];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[30];
	local[5]= loadglobal(fqv[21]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	if (fqv[27]!=local[4]) goto IF3269;
	local[4]= loadglobal(fqv[21]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[22]); /*event-x*/
	argv[0]->c.obj.iv[16] = w;
	local[4]= argv[0]->c.obj.iv[16];
	goto IF3270;
IF3269:
	local[4]= local[3];
	if (fqv[25]!=local[4]) goto IF3271;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[35];
	local[6]= makeint(-1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3272;
IF3271:
	local[4]= local[3];
	if (fqv[29]!=local[4]) goto IF3273;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[35];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3274;
IF3273:
	local[4]= local[3];
	if (fqv[26]!=local[4]) goto IF3275;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[35];
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[36];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3276;
IF3275:
	local[4]= local[3];
	if (fqv[28]!=local[4]) goto IF3277;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= fqv[35];
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[36];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3278;
IF3277:
	if (T==NIL) goto IF3279;
	local[4]= NIL;
	goto IF3280;
IF3279:
	local[4]= NIL;
IF3280:
IF3278:
IF3276:
IF3274:
IF3272:
IF3270:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3267:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M3281(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[21],w);
	if (argv[0]->c.obj.iv[16]==NIL) goto IF3283;
	local[3]= loadglobal(fqv[21]);
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[22]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[21]);
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[23]); /*event-y*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(2);
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[7];
	local[8]= fqv[37];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)GREQP(ctx,2,local+6); /*>=*/
	if (w==NIL) goto IF3285;
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[35];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	argv[0]->c.obj.iv[16] = local[3];
	local[6]= argv[0]->c.obj.iv[16];
	goto IF3286;
IF3285:
	local[6]= NIL;
IF3286:
	w = local[6];
	local[3]= w;
	goto IF3284;
IF3283:
	local[3]= NIL;
IF3284:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3282:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xscroll(ctx,n,argv,env)
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
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3287;
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[40],w);
	goto IF3288;
IF3287:
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3288:
	local[0]= fqv[42];
	local[1]= fqv[43];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[44]); /*require*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3188,fqv[4],fqv[45],fqv[46]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3204,fqv[10],fqv[45],fqv[47]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3206,fqv[13],fqv[45],fqv[48]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3208,fqv[11],fqv[45],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3219,fqv[30],fqv[45],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3232,fqv[51],fqv[45],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3247,fqv[53],fqv[45],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3253,fqv[55],fqv[45],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3255,fqv[4],fqv[57],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3264,fqv[10],fqv[57],fqv[59]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3266,fqv[51],fqv[57],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3281,fqv[53],fqv[57],fqv[61]);
	local[0]= fqv[62];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[64]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<5; i++) ftab[i]=fcallx;
}
