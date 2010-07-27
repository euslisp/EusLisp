/* Xcanvas.c :  entry=Xcanvas */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xcanvas.h"
#pragma init (register_Xcanvas)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xcanvas();
extern pointer build_quote_vector();
static register_Xcanvas()
  { add_module_initializer("___Xcanvas", ___Xcanvas);}


/*:create*/
static pointer M3029(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3031:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[0]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[1]));
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[15] = w;
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[6];
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(65535);
	local[10]= makeint(4096);
	local[11]= makeint(4096);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[10];
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(4096);
	local[10]= makeint(4096);
	local[11]= makeint(65535);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[11];
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(4096);
	local[10]= makeint(65535);
	local[11]= makeint(4096);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[12];
	local[5]= argv[0];
	local[6]= fqv[13];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[14];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(65535);
	local[10]= makeint(65535);
	local[11]= makeint(65535);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[16];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(49152);
	local[10]= makeint(49152);
	local[11]= makeint(49152);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[17];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(16384);
	local[10]= makeint(16384);
	local[11]= makeint(16384);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[18];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK3030:
	ctx->vsp=local; return(local[0]);}

/*:selection*/
static pointer M3033(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK3034:
	ctx->vsp=local; return(local[0]);}

/*:adjust-corners*/
static pointer M3035(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[12];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[13];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKINTVECTOR(ctx,2,local+1); /*integer-vector*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	argv[0]->c.obj.iv[13] = local[2];
	argv[0]->c.obj.iv[12] = local[3];
	w = NIL;
	local[0]= w;
BLK3036:
	ctx->vsp=local; return(local[0]);}

/*:draw-selection-rectangle*/
static pointer M3039(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[19];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[13];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[12];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ABS(ctx,1,local+4); /*abs*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[13];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[12];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3040:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M3041(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[20],w);
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[21]); /*event-button*/
	local[3]= w;
	local[4]= local[3];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)LSEQP(ctx,2,local+4); /*<=*/
	if (w==NIL) goto CON3044;
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[24];
	local[6]= makeint(127);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= loadglobal(fqv[20]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[25]); /*event-pos*/
	argv[0]->c.obj.iv[12] = w;
	local[4]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[13] = w;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	argv[0]->c.obj.iv[14] = T;
	local[4]= argv[0]->c.obj.iv[14];
	goto CON3043;
CON3044:
	local[4]= local[3];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON3045;
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= fqv[27];
	local[6]= loadglobal(fqv[20]);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,1,local+6,&ftab[2],fqv[28]); /*event-x-root*/
	local[6]= w;
	local[7]= loadglobal(fqv[20]);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[29]); /*event-y-root*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON3043;
CON3045:
	local[4]= NIL;
CON3043:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3042:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M3046(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[20],w);
	if (argv[0]->c.obj.iv[14]==NIL) goto IF3048;
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[30]); /*event-state*/
	local[3]= w;
	local[4]= fqv[31];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3051;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= loadglobal(fqv[20]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[25]); /*event-pos*/
	argv[0]->c.obj.iv[13] = w;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto CON3050;
CON3051:
	local[4]= fqv[33];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3052;
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= fqv[34];
	local[6]= loadglobal(fqv[20]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON3050;
CON3052:
	local[4]= NIL;
CON3050:
	w = local[4];
	local[3]= w;
	goto IF3049;
IF3048:
	local[3]= NIL;
IF3049:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3047:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3053(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[20],w);
	if (argv[0]->c.obj.iv[14]==NIL) goto CON3056;
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[30]); /*event-state*/
	local[3]= w;
	local[4]= fqv[35];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3058;
	local[4]= fqv[33];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3058;
	local[4]= argv[0];
	local[5]= fqv[36];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= fqv[37];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON3057;
CON3058:
	local[4]= fqv[33];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3059;
	local[4]= argv[0]->c.obj.iv[15];
	storeglobal(fqv[38],local[4]);
	goto CON3057;
CON3059:
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= fqv[37];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= loadglobal(fqv[20]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[25]); /*event-pos*/
	argv[0]->c.obj.iv[13] = w;
	argv[0]->c.obj.iv[14] = NIL;
	local[4]= argv[0]->c.obj.iv[14];
	goto CON3057;
CON3060:
	local[4]= NIL;
CON3057:
	w = local[4];
	local[3]= w;
	goto CON3055;
CON3056:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[1]));
	local[5]= fqv[39];
	local[6]= loadglobal(fqv[20]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
	goto CON3055;
CON3061:
	local[3]= NIL;
CON3055:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3054:
	ctx->vsp=local; return(local[0]);}

/*:clear-event*/
static pointer M3062(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3063:
	ctx->vsp=local; return(local[0]);}

/*:color-event*/
static pointer M3064(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3065:
	ctx->vsp=local; return(local[0]);}

/*:background-event*/
static pointer M3066(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[40];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3067:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3068(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3070:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[41], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3071;
	local[1] = makeflt(1.00000000e+00);
KEY3071:
	if (n & (1<<1)) goto KEY3072;
	local[2] = makeflt(-1.00000000e+00);
KEY3072:
	if (n & (1<<2)) goto KEY3073;
	local[3] = loadglobal(fqv[42]);
KEY3073:
	if (n & (1<<3)) goto KEY3074;
	local[4] = makeint(1);
KEY3074:
	if (n & (1<<4)) goto KEY3075;
	local[5] = NIL;
KEY3075:
	if (n & (1<<5)) goto KEY3076;
	local[6] = loadglobal(fqv[43]);
KEY3076:
	local[7]= (pointer)get_sym_func(fqv[0]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[1]));
	local[10]= fqv[2];
	local[11]= fqv[40];
	local[12]= local[3];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,7,local+7); /*apply*/
	local[7]= argv[0];
	local[8]= fqv[44];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[45];
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[46];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (local[5]==NIL) goto CON3078;
	local[7]= argv[0];
	local[8]= fqv[47];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto CON3077;
CON3078:
	if (local[6]==NIL) goto CON3079;
	local[7]= local[4];
	local[8]= fqv[48];
	local[9]= local[6];
	local[10]= loadglobal(fqv[49]);
	ctx->vsp=local+11;
	w=(pointer)DERIVEDP(ctx,2,local+9); /*derivedp*/
	if (w==NIL) goto IF3080;
	local[9]= local[6];
	goto IF3081;
IF3080:
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,1,local+9,&ftab[6],fqv[50]); /*make-color-gc*/
	local[9]= w;
IF3081:
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,3,local+7,&ftab[7],fqv[51]); /*make-array*/
	argv[0]->c.obj.iv[23] = w;
	local[7]= argv[0]->c.obj.iv[23];
	goto CON3077;
CON3079:
	local[7]= NIL;
CON3077:
	argv[0]->c.obj.iv[24] = makeint(0);
	local[7]= argv[0];
	local[8]= fqv[36];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK3069:
	ctx->vsp=local; return(local[0]);}

/*:new-pixmap*/
static pointer M3082(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3086;}
	local[0]= argv[0]->c.obj.iv[5];
ENT3086:
	if (n>=4) { local[1]=(argv[3]); goto ENT3085;}
	local[1]= argv[0]->c.obj.iv[6];
ENT3085:
ENT3084:
	if (n>4) maerror();
	local[2]= loadglobal(fqv[52]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[53];
	local[6]= local[0];
	local[7]= fqv[54];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[16] = w;
	w = argv[0];
	local[0]= w;
BLK3083:
	ctx->vsp=local; return(local[0]);}

/*:range*/
static pointer M3088(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3091;}
	local[0]= makeflt(0.00000000e+00);
ENT3091:
ENT3090:
	if (n>4) maerror();
	argv[0]->c.obj.iv[17] = argv[2];
	argv[0]->c.obj.iv[18] = local[0];
	w = argv[0];
	local[0]= w;
BLK3089:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M3092(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[48];
	local[2]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,3,local+0,&ftab[7],fqv[51]); /*make-array*/
	argv[0]->c.obj.iv[19] = w;
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK3093:
	ctx->vsp=local; return(local[0]);}

/*:colors*/
static pointer M3094(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[51]); /*make-array*/
	argv[0]->c.obj.iv[23] = w;
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL3097:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX3098;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[0] = w;
	local[3]= argv[0]->c.obj.iv[23];
	local[4]= local[1];
	local[5]= local[0];
	local[6]= loadglobal(fqv[49]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF3101;
	local[5]= local[0];
	goto IF3102;
IF3101:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[50]); /*make-color-gc*/
	local[5]= w;
IF3102:
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL3097;
WHX3098:
	local[3]= NIL;
BLK3099:
	w = NIL;
	local[0]= w;
BLK3095:
	ctx->vsp=local; return(local[0]);}

/*:graph*/
static pointer M3103(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3105:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	argv[0]->c.obj.iv[20] = local[0];
	local[1]= (pointer)get_sym_func(fqv[0]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[1]));
	local[4]= fqv[55];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= argv[0]->c.obj.iv[16];
	local[2]= fqv[56];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK3104:
	ctx->vsp=local; return(local[0]);}

/*:incremental-graph*/
static pointer M3106(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[57]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[4]= makeint(1);
	local[5]= makeint(0);
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[5])-4);
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(0);
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,10,local+0,&ftab[8],fqv[58]); /*copyarea*/
	local[0]= loadglobal(fqv[57]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= (pointer)((integer_t)(argv[0]->c.obj.iv[5])-4);
	local[3]= makeint(0);
	local[4]= makeint(1);
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,7,local+0,&ftab[9],fqv[59]); /*cleararea*/
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint(0);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL3109:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX3110;
	local[6]= argv[0]->c.obj.iv[19];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[2] = w;
	local[6]= argv[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[0] = w;
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)EUSFLOAT(ctx,1,local+8); /*float*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[17];
	local[10]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[1] = w;
	local[6]= argv[0]->c.obj.iv[23];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[3] = w;
	local[6]= argv[0];
	local[7]= fqv[60];
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	local[10]= argv[0]->c.obj.iv[5];
	local[11]= local[1];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,7,local+6); /*send*/
	local[6]= argv[0]->c.obj.iv[19];
	local[7]= local[4];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,3,local+6); /*aset*/
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL3109;
WHX3110:
	local[6]= NIL;
BLK3111:
	w = NIL;
	argv[0]->c.obj.iv[24] = (pointer)((integer_t)(argv[0]->c.obj.iv[24])+4);
	local[4]= argv[0]->c.obj.iv[24];
	local[5]= makeint(10);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,1,local+4,&ftab[10],fqv[61]); /*zerop*/
	if (w==NIL) goto IF3112;
	local[4]= argv[0]->c.obj.iv[16];
	local[5]= fqv[56];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3113;
IF3112:
	local[4]= NIL;
IF3113:
	w = local[4];
	local[0]= w;
BLK3107:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M3114(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[20] = NIL;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[1]));
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[16];
	local[1]= fqv[56];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3115:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3116(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[44];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[1]));
	local[2]= fqv[62];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3117:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M3118(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[20]==NIL) goto IF3120;
	local[0]= (pointer)get_sym_func(fqv[64]);
	local[1]= argv[0];
	local[2]= fqv[55];
	local[3]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,4,local+0); /*apply*/
	local[0]= w;
	goto IF3121;
IF3120:
	local[0]= NIL;
IF3121:
	w = local[0];
	local[0]= w;
BLK3119:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3122(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3124:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[65], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3125;
	local[1] = NIL;
KEY3125:
	local[2]= (pointer)get_sym_func(fqv[0]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[1]));
	local[5]= fqv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PRINT(ctx,1,local+2); /*print*/
	local[2]= loadglobal(fqv[66]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[67];
	local[6]= argv[0];
	local[7]= fqv[53];
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= makeint(15);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= fqv[54];
	local[10]= argv[0]->c.obj.iv[6];
	local[11]= makeint(15);
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[25] = w;
	local[2]= loadglobal(fqv[68]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[67];
	local[6]= argv[0];
	local[7]= fqv[53];
	local[8]= makeint(10);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[26] = w;
	local[2]= loadglobal(fqv[69]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[67];
	local[6]= argv[0];
	local[7]= fqv[54];
	local[8]= makeint(10);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[27] = w;
	local[2]= argv[0];
	local[3]= fqv[70];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (local[1]==NIL) goto IF3129;
	local[2]= argv[0];
	local[3]= fqv[71];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3130;
IF3129:
	local[2]= NIL;
IF3130:
	w = argv[0];
	local[0]= w;
BLK3123:
	ctx->vsp=local; return(local[0]);}

/*:reset-subwindows*/
static pointer M3131(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= fqv[62];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(15);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(15);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[72];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(13);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[27];
	local[1]= fqv[72];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(13);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK3132:
	ctx->vsp=local; return(local[0]);}

/*:set-pixmap*/
static pointer M3133(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[28] = argv[2];
	argv[0]->c.obj.iv[29] = makeint(0);
	argv[0]->c.obj.iv[30] = makeint(0);
	local[0]= argv[2];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[2];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= fqv[56];
	local[2]= argv[0]->c.obj.iv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[0]->c.obj.iv[28];
	local[0]= w;
BLK3134:
	ctx->vsp=local; return(local[0]);}

/*:scroll*/
static pointer M3135(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3138;}
	local[0]= makeint(1);
ENT3138:
ENT3137:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON3140;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK3136;
	goto CON3139;
CON3140:
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto CON3141;
	local[2] = local[0];
	local[3] = makeint(0);
	local[5]= argv[0];
	local[6]= fqv[54];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(16);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[4];
	goto CON3139;
CON3141:
	local[2] = makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[3] = w;
	local[4] = makeint(0);
	local[5]= local[4];
	goto CON3139;
CON3142:
	local[5]= NIL;
CON3139:
	local[5]= argv[0];
	local[6]= fqv[54];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(16);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[0] = w;
	local[5]= T;
	local[6]= fqv[73];
	local[7]= local[0];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,6,local+5); /*format*/
	local[5]= argv[0]->c.obj.iv[25];
	local[6]= fqv[56];
	local[7]= argv[0]->c.obj.iv[25];
	local[8]= fqv[74];
	local[9]= makeint(2);
	local[10]= fqv[75];
	local[11]= makeint(2);
	local[12]= local[2];
	local[13]= makeint(12);
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= fqv[53];
	local[13]= argv[0]->c.obj.iv[5];
	local[14]= fqv[54];
	local[15]= argv[0];
	local[16]= fqv[54];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= makeint(16);
	ctx->vsp=local+17;
	w=(pointer)QUOTIENT(ctx,2,local+15); /*/*/
	local[15]= w;
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,2,local+15); /*-*/
	local[15]= w;
	local[16]= makeint(12);
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= fqv[76];
	local[17]= makeint(2);
	local[18]= fqv[77];
	local[19]= makeint(2);
	local[20]= local[3];
	local[21]= makeint(12);
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,15,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[25];
	local[6]= fqv[78];
	local[7]= fqv[76];
	local[8]= makeint(2);
	local[9]= fqv[77];
	local[10]= makeint(2);
	local[11]= local[4];
	local[12]= makeint(12);
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= fqv[53];
	local[12]= argv[0]->c.obj.iv[5];
	local[13]= fqv[54];
	local[14]= local[0];
	local[15]= makeint(12);
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,10,local+5); /*send*/
	local[0]= w;
BLK3136:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xcanvas(ctx,n,argv,env)
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
	local[0]= fqv[79];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3143;
	local[0]= fqv[80];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[81],w);
	goto IF3144;
IF3143:
	local[0]= fqv[82];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3144:
	local[0]= fqv[83];
	local[1]= fqv[84];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[85]); /*require*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3029,fqv[2],fqv[86],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3033,fqv[88],fqv[86],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3035,fqv[90],fqv[86],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3039,fqv[26],fqv[86],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3041,fqv[93],fqv[86],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3046,fqv[34],fqv[86],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3053,fqv[39],fqv[86],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3062,fqv[13],fqv[86],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3064,fqv[7],fqv[86],fqv[98]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3066,fqv[15],fqv[86],fqv[99]);
	local[0]= fqv[100];
	local[1]= fqv[101];
	local[2]= fqv[100];
	local[3]= fqv[102];
	local[4]= loadglobal(fqv[86]);
	local[5]= fqv[103];
	local[6]= fqv[104];
	local[7]= fqv[105];
	local[8]= NIL;
	local[9]= fqv[106];
	local[10]= NIL;
	local[11]= fqv[107];
	local[12]= makeint(-1);
	local[13]= fqv[108];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[109]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3068,fqv[2],fqv[100],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3082,fqv[44],fqv[100],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3088,fqv[45],fqv[100],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3092,fqv[46],fqv[100],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3094,fqv[47],fqv[100],fqv[114]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3103,fqv[55],fqv[100],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3106,fqv[116],fqv[100],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3114,fqv[36],fqv[100],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3116,fqv[62],fqv[100],fqv[119]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3118,fqv[120],fqv[100],fqv[121]);
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[123];
	local[1]= fqv[101];
	local[2]= fqv[123];
	local[3]= fqv[102];
	local[4]= loadglobal(fqv[124]);
	local[5]= fqv[103];
	local[6]= fqv[125];
	local[7]= fqv[105];
	local[8]= NIL;
	local[9]= fqv[106];
	local[10]= NIL;
	local[11]= fqv[107];
	local[12]= makeint(-1);
	local[13]= fqv[108];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[109]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3122,fqv[2],fqv[123],fqv[126]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3131,fqv[70],fqv[123],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3133,fqv[71],fqv[123],fqv[128]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3135,fqv[129],fqv[123],fqv[130]);
	local[0]= fqv[131];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[133]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<14; i++) ftab[i]=fcallx;
}
