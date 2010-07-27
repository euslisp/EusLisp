/* nn.c :  entry=nn */
/* compiled by EusLisp 8.16 for Solaris2  created on Thu Jul 18 13:18:29 JST 1996 */
#include "eus.h"
#include "nn.h"
#pragma init (register_nn)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___nn();
extern pointer build_quote_vector();
static register_nn()
  { add_module_initializer("___nn", ___nn);}

static pointer F64();
static pointer F65();
static pointer F66();
static pointer F67();
static pointer F68();
static pointer F69();
static pointer F70();
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

/*sigmoid*/
static pointer F102(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[0];
	local[1]= fqv[1];
	local[2]= fqv[2];
	local[3]= fqv[3];
	local[4]= fqv[4];
	local[5]= fqv[0];
	local[6]= fqv[5];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk103:
	ctx->vsp=local; return(local[0]);}

/*v=m*v*/
static pointer F104(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[6];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk105:
	ctx->vsp=local; return(local[0]);}

/*v=v*m*/
static pointer F106(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[6];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk107:
	ctx->vsp=local; return(local[0]);}

/*v=v+v*/
static pointer F108(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[7];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk109:
	ctx->vsp=local; return(local[0]);}

/*v=v-v*/
static pointer F110(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[8];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk111:
	ctx->vsp=local; return(local[0]);}

/*v*=s*/
static pointer F112(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[9];
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk113:
	ctx->vsp=local; return(local[0]);}

/*create-layer*/
static pointer F64(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto key115;
	local[0] = makeflt(1.00000000e+00);
key115:
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[12]); /*make-instance*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[0] = local[3];
	local[2]= argv[1];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[1] = local[3];
	local[2]= argv[1];
	local[3]= fqv[13];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[2] = local[3];
	local[2]= argv[1];
	local[3]= fqv[13];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[3] = local[3];
	local[2]= argv[1];
	local[3]= fqv[13];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[4] = local[3];
	local[2]= argv[1];
	local[3]= fqv[13];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[5] = local[3];
	local[2]= argv[1];
	local[3]= fqv[13];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[6] = local[3];
	local[2]= local[0];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[7] = local[3];
	local[2]= NIL;
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[8] = local[3];
	local[2]= NIL;
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[9] = local[3];
	w = local[1];
	local[0]= w;
blk114:
	ctx->vsp=local; return(local[0]);}

/*init-layer*/
static pointer F65(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent119;}
	local[0]= makeflt(-1.00000000e+00);
ent119:
	if (n>=3) { local[1]=(argv[2]); goto ent118;}
	local[1]= makeflt(1.00000000e+00);
ent118:
ent117:
	if (n>3) maerror();
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[16]); /*v=noise*/
	local[0]= w;
blk116:
	ctx->vsp=local; return(local[0]);}

/*create-link*/
static pointer F66(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[17]);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[12]); /*make-instance*/
	local[0]= w;
	local[1]= argv[1]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0];
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[0] = local[4];
	local[3]= argv[1];
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[1] = local[4];
	local[3]= local[1];
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[2] = local[4];
	local[3]= local[2];
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[3] = local[4];
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
	local[4]= w;
	w = local[0];
	w->c.obj.iv[4] = local[4];
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
	local[4]= w;
	w = local[0];
	w->c.obj.iv[5] = local[4];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[3];
	w = argv[0];
	w->c.obj.iv[9] = local[4];
	local[3]= local[0];
	w = argv[1]->c.obj.iv[8];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[3];
	w = argv[1];
	w->c.obj.iv[8] = local[4];
	w = local[0];
	local[0]= w;
blk120:
	ctx->vsp=local; return(local[0]);}

/*init-link*/
static pointer F67(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent124;}
	local[0]= makeflt(-1.00000000e+00);
ent124:
	if (n>=3) { local[1]=(argv[2]); goto ent123;}
	local[1]= makeflt(1.00000000e+00);
ent123:
ent122:
	if (n>3) maerror();
	local[2]= argv[0]->c.obj.iv[4];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,3,local+2,&ftab[3],fqv[18]); /*m=noise*/
	local[0]= w;
blk121:
	ctx->vsp=local; return(local[0]);}

/*save-layer-array*/
static pointer F125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[19];
	local[1]= fqv[20];
	local[2]= argv[3];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[21];
	local[3]= argv[2];
	local[4]= fqv[22];
	local[5]= fqv[23];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[24];
	local[4]= fqv[25];
	local[5]= argv[0];
	local[6]= fqv[26];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[23];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[27];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[21];
	local[5]= argv[2];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk126:
	ctx->vsp=local; return(local[0]);}

/*save-layer*/
static pointer F68(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent131;}
	local[0]= T;
ent131:
	if (n>=3) { local[1]=(argv[2]); goto ent130;}
	local[1]= makeint(0);
ent130:
	if (n>=4) { local[2]=(argv[3]); goto ent129;}
	local[2]= NIL;
ent129:
ent128:
	if (n>4) maerror();
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[29];
	local[5]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[0];
	local[4]= fqv[30];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[0];
	local[4]= fqv[31];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[0];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[33];
	local[5]= fqv[34];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[34];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRIN1(ctx,2,local+3); /*prin1*/
	local[3]= local[0];
	local[4]= fqv[35];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	if (local[2]==NIL) goto if132;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[36];
	local[5]= fqv[37];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[37];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRIN1(ctx,2,local+3); /*prin1*/
	local[3]= local[0];
	local[4]= fqv[38];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[39];
	local[5]= fqv[40];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[40];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRIN1(ctx,2,local+3); /*prin1*/
	local[3]= local[0];
	local[4]= fqv[41];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[42];
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRIN1(ctx,2,local+3); /*prin1*/
	local[3]= local[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[45];
	local[5]= fqv[46];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[46];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRIN1(ctx,2,local+3); /*prin1*/
	local[3]= local[0];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[48];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[49];
	local[5]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto if133;
if132:
	local[3]= NIL;
if133:
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[50];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	w = argv[0];
	local[0]= w;
blk127:
	ctx->vsp=local; return(local[0]);}

/*load-layer*/
static pointer F69(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ent136;}
	local[0]= T;
ent136:
ent135:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F71(ctx,1,local+1); /*construct-layer0*/
	local[0]= w;
blk134:
	ctx->vsp=local; return(local[0]);}

/*construct-layer-array*/
static pointer F137(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[51];
	local[1]= fqv[52];
	local[2]= fqv[53];
	local[3]= fqv[23];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[15];
	local[3]= argv[2];
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk138:
	ctx->vsp=local; return(local[0]);}

/*construct-layer*/
static pointer F70(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent141;}
	local[0]= T;
ent141:
ent140:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F71(ctx,1,local+1); /*construct-layer0*/
	local[1]= w;
	w = local[0];
	if (!iscons(w)) goto con143;
	local[2]= local[0];
	local[3]= local[1]->c.obj.iv[0];
	w = local[1];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[2]= w;
	goto con142;
con143:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[54]); /*hash-table-p*/
	if (w==NIL) goto con144;
	local[2]= local[1]->c.obj.iv[0];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,3,local+2,&ftab[6],fqv[55]); /*sethash*/
	local[2]= w;
	goto con142;
con144:
	local[2]= T;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	if (w==NIL) goto con145;
	local[2]= local[1];
	local[3]= local[2];
	w = local[1]->c.obj.iv[0];
	w->c.obj.iv[1] = local[3];
	goto con142;
con145:
	local[2]= NIL;
	goto con142;
con146:
	local[2]= NIL;
con142:
	w = local[1];
	local[0]= w;
blk139:
	ctx->vsp=local; return(local[0]);}

/*construct-layer0*/
static pointer F71(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[11];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto if148;
	local[0]= loadglobal(fqv[11]);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[12]); /*make-instance*/
	local[0]= w;
	local[1]= fqv[56];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,2,local+1,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	if (local[1]!=NIL) goto or150;
	local[1]= makeint(1);
or150:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[0] = local[4];
	local[3]= local[1];
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[1] = local[4];
	local[3]= fqv[57];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	if (local[3]!=NIL) goto or151;
	local[3]= makeflt(1.00000000e+00);
or151:
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[7] = local[4];
	local[3]= fqv[34];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	if (local[3]!=NIL) goto or152;
	local[3]= local[1];
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
or152:
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[2] = local[4];
	local[3]= fqv[37];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	if (local[3]!=NIL) goto or153;
	local[3]= local[1];
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
or153:
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[3] = local[4];
	local[3]= fqv[40];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	if (local[3]!=NIL) goto or154;
	local[3]= local[1];
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
or154:
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[4] = local[4];
	local[3]= fqv[43];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	if (local[3]!=NIL) goto or155;
	local[3]= local[1];
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
or155:
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[5] = local[4];
	local[3]= fqv[46];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	if (local[3]!=NIL) goto or156;
	local[3]= local[1];
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[15]); /*make-array*/
	local[3]= w;
or156:
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[6] = local[4];
	local[3]= NIL;
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[8] = local[4];
	local[3]= NIL;
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[9] = local[4];
	w = local[0];
	local[0]= w;
	goto if149;
if148:
	local[0]= fqv[58];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
if149:
	w = local[0];
	local[0]= w;
blk147:
	ctx->vsp=local; return(local[0]);}

/*save-link-matrix*/
static pointer F157(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[19];
	local[1]= fqv[20];
	local[2]= argv[3];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[21];
	local[3]= argv[2];
	local[4]= fqv[59];
	local[5]= fqv[23];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[20];
	local[4]= fqv[2];
	local[5]= argv[3];
	local[6]= fqv[60];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[61];
	local[5]= fqv[25];
	local[6]= argv[0];
	local[7]= fqv[26];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[23];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[27];
	local[7]= fqv[2];
	local[8]= fqv[62];
	local[9]= fqv[63];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[21];
	local[6]= argv[2];
	local[7]= fqv[64];
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
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk158:
	ctx->vsp=local; return(local[0]);}

/*save-link*/
static pointer F72(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent163;}
	local[0]= T;
ent163:
	if (n>=3) { local[1]=(argv[2]); goto ent162;}
	local[1]= makeint(0);
ent162:
	if (n>=4) { local[2]=(argv[3]); goto ent161;}
	local[2]= NIL;
ent161:
ent160:
	if (n>4) maerror();
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[65];
	local[5]= argv[0]->c.obj.iv[0]->c.obj.iv[0];
	local[6]= argv[0]->c.obj.iv[1]->c.obj.iv[0];
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,6,local+3); /*format*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[66];
	local[5]= fqv[67];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[67];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,3,local+3,&ftab[8],fqv[61]); /*pprint*/
	local[3]= local[0];
	local[4]= fqv[68];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	if (local[2]==NIL) goto if164;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[69];
	local[5]= fqv[70];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	local[5]= fqv[70];
	ctx->vsp=local+6;
	w=(pointer)SLOT(ctx,3,local+3); /*slot*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,3,local+3,&ftab[8],fqv[61]); /*pprint*/
	local[3]= local[0];
	local[4]= fqv[71];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= w;
	goto if165;
if164:
	local[3]= NIL;
if165:
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[72];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	w = argv[0];
	local[0]= w;
blk159:
	ctx->vsp=local; return(local[0]);}

/*load-link*/
static pointer F73(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ent168;}
	local[0]= T;
ent168:
ent167:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F74(ctx,1,local+1); /*construct-link0*/
	local[0]= w;
blk166:
	ctx->vsp=local; return(local[0]);}

/*construct-link-matrix*/
static pointer F169(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[51];
	local[1]= fqv[52];
	local[2]= fqv[53];
	local[3]= fqv[23];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[15];
	local[3]= fqv[73];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[13];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
blk170:
	ctx->vsp=local; return(local[0]);}

/*construct-link0*/
static pointer F74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[17];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto if172;
	local[0]= loadglobal(fqv[17]);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[12]); /*make-instance*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[74]); /*cdddr*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[8];
	w = local[0];
	w->c.obj.iv[0] = local[9];
	local[8]= local[3];
	local[9]= local[8];
	w = local[0];
	w->c.obj.iv[1] = local[9];
	local[8]= local[5];
	local[9]= local[8];
	w = local[0];
	w->c.obj.iv[2] = local[9];
	local[8]= local[6];
	local[9]= local[8];
	w = local[0];
	w->c.obj.iv[3] = local[9];
	local[8]= fqv[67];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	if (local[8]!=NIL) goto or174;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
	local[9]= fqv[13];
	local[10]= fqv[14];
	ctx->vsp=local+11;
	w=(*ftab[1])(ctx,3,local+8,&ftab[1],fqv[15]); /*make-array*/
	local[8]= w;
or174:
	local[9]= local[8];
	w = local[0];
	w->c.obj.iv[4] = local[9];
	local[8]= fqv[70];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	if (local[8]!=NIL) goto or175;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
	local[9]= fqv[13];
	local[10]= fqv[14];
	ctx->vsp=local+11;
	w=(*ftab[1])(ctx,3,local+8,&ftab[1],fqv[15]); /*make-array*/
	local[8]= w;
or175:
	local[9]= local[8];
	w = local[0];
	w->c.obj.iv[5] = local[9];
	w = local[0];
	local[0]= w;
	goto if173;
if172:
	local[0]= fqv[75];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
if173:
	w = local[0];
	local[0]= w;
blk171:
	ctx->vsp=local; return(local[0]);}

/*wire-link*/
static pointer F75(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = argv[1];
	if (!iscons(w)) goto con178;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,clo179,env,argv,local);
	goto con177;
con178:
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[54]); /*hash-table-p*/
	if (w==NIL) goto con180;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,clo181,env,argv,local);
	goto con177;
con180:
	local[2]= argv[1];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	if (w==NIL) goto con182;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,clo183,env,argv,local);
	goto con177;
con182:
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,clo185,env,argv,local);
	goto con177;
con184:
	local[2]= NIL;
con177:
	local[3]= local[2];
	local[4]= local[0];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[3]= w;
	local[4]= w;
	w = argv[0];
	w->c.obj.iv[0] = local[4];
	local[0] = local[3];
	local[3]= local[2];
	local[4]= local[1];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[3]= w;
	local[4]= w;
	w = argv[0];
	w->c.obj.iv[1] = local[4];
	local[1] = local[3];
	local[3]= argv[0];
	w = local[0]->c.obj.iv[9];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[3];
	w = local[0];
	w->c.obj.iv[9] = local[4];
	local[3]= argv[0];
	w = local[1]->c.obj.iv[8];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[8] = local[4];
	w = argv[0];
	local[0]= w;
blk176:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo179(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	if (local[0]!=NIL) goto or186;
	local[0]= argv[0];
or186:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo181(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[76]); /*gethash*/
	local[0]= w;
	if (w!=NIL) goto or187;
	local[0]= argv[0];
or187:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo183(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo185(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*construct-link*/
static pointer F76(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent190;}
	local[0]= T;
ent190:
ent189:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F74(ctx,1,local+1); /*construct-link0*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F75(ctx,2,local+2); /*wire-link*/
	local[0]= w;
blk188:
	ctx->vsp=local; return(local[0]);}

/*f-propagate-link*/
static pointer F77(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[1]->c.obj.iv[3];
	local[2]= local[1];
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,3,local+2,&ftab[11],fqv[77]); /*v+=m*v*/
	local[0]= w;
blk191:
	ctx->vsp=local; return(local[0]);}

/*f-propagate-sigmoid-layer*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[78]); /*v=*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
whl194:
	if (local[1]==NIL) goto whx195;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F77(ctx,1,local+2); /*f-propagate-link*/
	goto whl194;
whx195:
	local[2]= NIL;
blk196:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,3,local+0,&ftab[13],fqv[79]); /*v=sigmoid*/
	local[0]= w;
blk192:
	ctx->vsp=local; return(local[0]);}

/*f-propagate-liner-layer*/
static pointer F79(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[78]); /*v=*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
whl200:
	if (local[1]==NIL) goto whx201;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F77(ctx,1,local+2); /*f-propagate-link*/
	goto whl200;
whx201:
	local[2]= NIL;
blk202:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= w;
blk198:
	ctx->vsp=local; return(local[0]);}

/*b-propagate-link*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[1]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[4];
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,3,local+3,&ftab[14],fqv[80]); /*v+=v*m*/
	local[0]= w;
blk204:
	ctx->vsp=local; return(local[0]);}

/*b-propagate-sigmoid-output-layer*/
static pointer F81(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,3,local+0); /*v-*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,3,local+0,&ftab[15],fqv[81]); /*v*=dsigdx_o*/
	local[0]= w;
blk205:
	ctx->vsp=local; return(local[0]);}

/*b-propagate-liner-output-layer*/
static pointer F82(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,3,local+0); /*v-*/
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= w;
blk206:
	ctx->vsp=local; return(local[0]);}

/*b-propagate-sigmoid-hidden-layer*/
static pointer F83(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,2,local+1,&ftab[16],fqv[82]); /*v=s*/
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[9];
whl209:
	if (local[2]==NIL) goto whx210;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F80(ctx,1,local+3); /*b-propagate-link*/
	goto whl209;
whx210:
	local[3]= NIL;
blk211:
	w = NIL;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[4];
	local[3]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,3,local+1,&ftab[15],fqv[81]); /*v*=dsigdx_o*/
	local[0]= w;
blk207:
	ctx->vsp=local; return(local[0]);}

/*b-propagate-liner-hidden-layer*/
static pointer F84(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,2,local+1,&ftab[16],fqv[82]); /*v=s*/
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[9];
whl215:
	if (local[2]==NIL) goto whx216;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F80(ctx,1,local+3); /*b-propagate-link*/
	goto whl215;
whx216:
	local[3]= NIL;
blk217:
	w = NIL;
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= local[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,3,local+1); /*scale*/
	local[0]= w;
blk213:
	ctx->vsp=local; return(local[0]);}

/*learn-layer*/
static pointer F85(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,4,local+0,&ftab[17],fqv[83]); /*v=a*v+e*v*/
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[84]); /*v+=*/
	local[0]= w;
blk219:
	ctx->vsp=local; return(local[0]);}

/*learn-link*/
static pointer F86(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1]->c.obj.iv[5];
	local[4]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,5,local+0,&ftab[19],fqv[85]); /*m=a*m+e*v**v*/
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[86]); /*m+=*/
	local[0]= w;
blk220:
	ctx->vsp=local; return(local[0]);}

/*get-layer-by-name*/
static pointer F87(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
blk221:
	ctx->vsp=local; return(local[0]);}

/*get-link-by-name*/
static pointer F88(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1]->c.obj.iv[2];
	local[2]= fqv[87];
	local[3]= fqv[88];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,4,local+0,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
blk222:
	ctx->vsp=local; return(local[0]);}

/*construct-layered-network-parameters*/
static pointer F89(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
whl225:
	if (local[1]==NIL) goto whx226;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= local[2];
	if (fqv[57]!=local[3]) goto if230;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = argv[0];
	w->c.obj.iv[4] = local[4];
	goto if231;
if230:
	local[3]= local[2];
	if (fqv[89]!=local[3]) goto if232;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = argv[0];
	w->c.obj.iv[5] = local[4];
	goto if233;
if232:
	local[3]= local[2];
	if (fqv[90]!=local[3]) goto if234;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = argv[0];
	w->c.obj.iv[6] = local[4];
	goto if235;
if234:
	if (T==NIL) goto if236;
	local[3]= argv[0]->c.obj.iv[3];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)RPLACD2(ctx,2,local+3); /*rplacd2*/
	local[3]= w;
	goto if237;
if236:
	local[3]= NIL;
if237:
if235:
if233:
if231:
	w = local[3];
	goto whl225;
whx226:
	local[2]= NIL;
blk227:
	w = NIL;
	local[0]= w;
blk223:
	ctx->vsp=local; return(local[0]);}

/*construct-layered-network-layers*/
static pointer F90(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
whl240:
	if (local[1]==NIL) goto whx241;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= local[2];
	if (fqv[91]!=local[3]) goto if245;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)F70(ctx,2,local+3); /*construct-layer*/
	local[3]= w;
	goto if246;
if245:
	if (T==NIL) goto if247;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[92];
	local[6]= fqv[92];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[53]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	if (local[6]!=NIL) goto or249;
	local[6]= argv[0]->c.obj.iv[4];
or249:
	ctx->vsp=local+7;
	w=(pointer)F64(ctx,4,local+3); /*create-layer*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[3]= w;
	goto if248;
if247:
	local[3]= NIL;
if248:
if246:
	w = local[3];
	goto whl240;
whx241:
	local[2]= NIL;
blk242:
	w = NIL;
	local[0]= w;
blk238:
	ctx->vsp=local; return(local[0]);}

/*construct-layered-network-links*/
static pointer F91(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
whl252:
	if (local[1]==NIL) goto whx253;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= local[2];
	if (fqv[91]!=local[3]) goto if257;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)F76(ctx,2,local+3); /*construct-link*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= local[3]->c.obj.iv[0]->c.obj.iv[0];
	local[6]= local[3]->c.obj.iv[1]->c.obj.iv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	w = local[3];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[3]= w;
	goto if258;
if257:
	if (T==NIL) goto if259;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F87(ctx,2,local+4); /*get-layer-by-name*/
	local[4]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F87(ctx,2,local+5); /*get-layer-by-name*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)F66(ctx,2,local+6); /*create-link*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= local[6]->c.obj.iv[0]->c.obj.iv[0];
	local[9]= local[6]->c.obj.iv[1]->c.obj.iv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
	w = local[6];
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NCONC(ctx,2,local+7); /*nconc*/
	local[3]= w;
	goto if260;
if259:
	local[3]= NIL;
if260:
if258:
	w = local[3];
	goto whl252;
whx253:
	local[2]= NIL;
blk254:
	w = NIL;
	local[0]= w;
blk250:
	ctx->vsp=local; return(local[0]);}

/*construct-layered-network*/
static pointer F92(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w!=NIL) goto if262;
	local[0]= fqv[94];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto if263;
if262:
	local[0]= NIL;
if263:
	local[0]= loadglobal(fqv[93]);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[12]); /*make-instance*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	w = local[0];
	w->c.obj.iv[0] = local[2];
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	local[2]= w;
	w = local[0];
	w->c.obj.iv[1] = local[2];
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	local[2]= w;
	w = local[0];
	w->c.obj.iv[2] = local[2];
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	local[2]= w;
	w = local[0];
	w->c.obj.iv[3] = local[2];
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[1];
	w = local[0];
	w->c.obj.iv[4] = local[2];
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[1];
	w = local[0];
	w->c.obj.iv[5] = local[2];
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[1];
	w = local[0];
	w->c.obj.iv[6] = local[2];
	local[1]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
whl265:
	if (local[2]==NIL) goto whx266;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	if (fqv[95]!=local[4]) goto if270;
	local[4]= local[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)F89(ctx,2,local+4); /*construct-layered-network-parameters*/
	local[4]= w;
	goto if271;
if270:
	local[4]= local[3];
	if (fqv[96]!=local[4]) goto if272;
	local[4]= local[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)F90(ctx,2,local+4); /*construct-layered-network-layers*/
	local[4]= w;
	goto if273;
if272:
	local[4]= local[3];
	if (fqv[97]!=local[4]) goto if274;
	local[4]= local[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)F91(ctx,2,local+4); /*construct-layered-network-links*/
	local[4]= w;
	goto if275;
if274:
	if (T==NIL) goto if276;
	local[4]= fqv[98];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,2,local+4); /*error*/
	local[4]= w;
	goto if277;
if276:
	local[4]= NIL;
if277:
if275:
if273:
if271:
	w = local[4];
	goto whl265;
whx266:
	local[3]= NIL;
blk267:
	w = NIL;
	w = local[0];
	local[0]= w;
blk261:
	ctx->vsp=local; return(local[0]);}

/*layered-network*/
static pointer F278(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
rst280:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[99];
	local[2]= fqv[23];
	local[3]= fqv[93];
	w = local[0];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
blk279:
	ctx->vsp=local; return(local[0]);}

/*save-layered-network-parameters*/
static pointer F93(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent285;}
	local[0]= T;
ent285:
	if (n>=3) { local[1]=(argv[2]); goto ent284;}
	local[1]= makeint(0);
ent284:
	if (n>=4) { local[2]=(argv[3]); goto ent283;}
	local[2]= NIL;
ent283:
ent282:
	if (n>4) maerror();
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[100];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[101];
	local[5]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[102];
	local[5]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[103];
	local[5]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= NIL;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
whl287:
	if (local[4]==NIL) goto whx288;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= fqv[104];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[20]); /*spaces*/
	local[5]= local[0];
	local[6]= fqv[105];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(*ftab[21])(ctx,0,local+8,&ftab[21],fqv[106]); /*param-val*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	goto whl287;
whx288:
	local[5]= NIL;
blk289:
	w = NIL;
	local[3]= local[0];
	local[4]= fqv[107];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[0]= w;
blk281:
	ctx->vsp=local; return(local[0]);}

/*save-layered-network-layers*/
static pointer F94(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent295;}
	local[0]= T;
ent295:
	if (n>=3) { local[1]=(argv[2]); goto ent294;}
	local[1]= makeint(0);
ent294:
	if (n>=4) { local[2]=(argv[3]); goto ent293;}
	local[2]= NIL;
ent293:
ent292:
	if (n>4) maerror();
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[108];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= NIL;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
whl297:
	if (local[4]==NIL) goto whx298;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= fqv[109];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[20]); /*spaces*/
	local[5]= local[0];
	local[6]= fqv[110];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	local[6]= local[0];
	local[7]= local[1];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)F68(ctx,4,local+5); /*save-layer*/
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[20]); /*spaces*/
	local[5]= local[0];
	local[6]= fqv[111];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	goto whl297;
whx298:
	local[5]= NIL;
blk299:
	w = NIL;
	local[3]= local[0];
	local[4]= fqv[112];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[0]= w;
blk291:
	ctx->vsp=local; return(local[0]);}

/*save-layered-network-links*/
static pointer F95(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent305;}
	local[0]= T;
ent305:
	if (n>=3) { local[1]=(argv[2]); goto ent304;}
	local[1]= makeint(0);
ent304:
	if (n>=4) { local[2]=(argv[3]); goto ent303;}
	local[2]= NIL;
ent303:
ent302:
	if (n>4) maerror();
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[113];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= NIL;
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
whl307:
	if (local[4]==NIL) goto whx308;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= fqv[114];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[20]); /*spaces*/
	local[5]= local[0];
	local[6]= fqv[115];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	local[6]= local[0];
	local[7]= local[1];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)F72(ctx,4,local+5); /*save-link*/
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[20]); /*spaces*/
	local[5]= local[0];
	local[6]= fqv[116];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	goto whl307;
whx308:
	local[5]= NIL;
blk309:
	w = NIL;
	local[3]= local[0];
	local[4]= fqv[117];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[0]= w;
blk301:
	ctx->vsp=local; return(local[0]);}

/*save-layered-network*/
static pointer F96(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent315;}
	local[0]= T;
ent315:
	if (n>=3) { local[1]=(argv[2]); goto ent314;}
	local[1]= makeint(0);
ent314:
	if (n>=4) { local[2]=(argv[3]); goto ent313;}
	local[2]= NIL;
ent313:
ent312:
	if (n>4) maerror();
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[118];
	local[5]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F93(ctx,4,local+3); /*save-layered-network-parameters*/
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F94(ctx,4,local+3); /*save-layered-network-layers*/
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F95(ctx,4,local+3); /*save-layered-network-links*/
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[20]); /*spaces*/
	local[3]= local[0];
	local[4]= fqv[119];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[0]= w;
blk311:
	ctx->vsp=local; return(local[0]);}

/*match*/
static pointer F97(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F98(ctx,3,local+0); /*match-sub*/
	local[0]= w;
blk316:
	ctx->vsp=local; return(local[0]);}

/*match-sub*/
static pointer F98(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto con319;
	local[0]= argv[2];
	goto con318;
con319:
	w = argv[0];
	if (!iscons(w)) goto con320;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto con320;
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= fqv[87];
	local[3]= fqv[88];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,4,local+0,&ftab[7],fqv[53]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto if321;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F98(ctx,3,local+1); /*match-sub*/
	local[1]= w;
	goto if322;
if321:
	local[1]= argv[2];
	local[2]= argv[0];
	w = argv[1];
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)RPLACD2(ctx,2,local+1); /*rplacd2*/
	local[1]= argv[2];
if322:
	w = local[1];
	local[0]= w;
	goto con318;
con320:
	w = argv[1];
	if (!iscons(w)) goto con323;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto con323;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= fqv[87];
	local[3]= fqv[88];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,4,local+0,&ftab[7],fqv[53]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto if324;
	local[1]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F98(ctx,3,local+1); /*match-sub*/
	local[1]= w;
	goto if325;
if324:
	local[1]= argv[2];
	local[2]= argv[1];
	w = argv[0];
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)RPLACD2(ctx,2,local+1); /*rplacd2*/
	local[1]= argv[2];
if325:
	w = local[1];
	local[0]= w;
	goto con318;
con323:
	w = argv[0];
	if (!iscons(w)) goto con326;
	w = argv[1];
	if (!iscons(w)) goto con326;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F98(ctx,3,local+0); /*match-sub*/
	local[0]= w;
	if (w==NIL) goto and327;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F98(ctx,3,local+0); /*match-sub*/
	local[0]= w;
and327:
	goto con318;
con326:
	local[0]= NIL;
con318:
	w = local[0];
	local[0]= w;
blk317:
	ctx->vsp=local; return(local[0]);}

/*subst-multi*/
static pointer F99(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= fqv[87];
	local[3]= fqv[88];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,4,local+0,&ftab[7],fqv[53]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto if329;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	goto if330;
if329:
	w = argv[0];
	if (!iscons(w)) goto if331;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F99(ctx,2,local+1); /*subst-multi*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F99(ctx,2,local+2); /*subst-multi*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto if332;
if331:
	local[1]= argv[0];
if332:
if330:
	w = local[1];
	local[0]= w;
blk328:
	ctx->vsp=local; return(local[0]);}

/*assoc-by-match*/
static pointer F100(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[1]!=NIL) goto if334;
	local[0]= NIL;
	goto if335;
if334:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F97(ctx,2,local+1); /*match*/
	local[1]= w;
	if (local[1]==NIL) goto if336;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F99(ctx,2,local+3); /*subst-multi*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	goto if337;
if336:
	local[2]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)F100(ctx,2,local+2); /*assoc-by-match*/
	local[2]= w;
if337:
	w = local[2];
	local[0]= w;
if335:
	w = local[0];
	local[0]= w;
blk333:
	ctx->vsp=local; return(local[0]);}

/*subst-multi-by-match*/
static pointer F101(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F100(ctx,2,local+0); /*assoc-by-match*/
	local[0]= w;
	if (local[0]==NIL) goto if339;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	goto if340;
if339:
	w = argv[0];
	if (!iscons(w)) goto if341;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F101(ctx,2,local+1); /*subst-multi-by-match*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F101(ctx,2,local+2); /*subst-multi-by-match*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto if342;
if341:
	local[1]= argv[0];
if342:
if340:
	w = local[1];
	local[0]= w;
blk338:
	ctx->vsp=local; return(local[0]);}

/*with-layered-network*/
static pointer F343(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
rst345:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[19];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= fqv[121];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[122];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= local[1];
	local[7]= fqv[57];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[123];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[1];
	local[8]= fqv[89];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[124];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= local[1];
	local[9]= fqv[90];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[125];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[1];
	local[10]= fqv[11];
	local[11]= fqv[120];
	local[12]= fqv[121];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[126];
	local[11]= fqv[23];
	local[12]= fqv[120];
	local[13]= fqv[121];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[1];
	local[11]= fqv[11];
	local[12]= fqv[120];
	local[13]= fqv[121];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[120];
	local[14]= fqv[25];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[25];
	local[12]= fqv[126];
	local[13]= fqv[23];
	local[14]= fqv[120];
	local[15]= fqv[121];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= fqv[23];
	local[15]= fqv[120];
	local[16]= fqv[25];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[1];
	local[12]= fqv[17];
	local[13]= fqv[120];
	local[14]= fqv[121];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[127];
	local[13]= fqv[23];
	local[14]= fqv[120];
	local[15]= fqv[121];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[1];
	local[13]= fqv[17];
	local[14]= fqv[120];
	local[15]= fqv[121];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[120];
	local[16]= fqv[25];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[25];
	local[14]= fqv[127];
	local[15]= fqv[23];
	local[16]= fqv[120];
	local[17]= fqv[121];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[17];
	local[16]= fqv[23];
	local[17]= fqv[120];
	local[18]= fqv[25];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	ctx->vsp=local+18;
	local[17]= cons(ctx,local[17],w);
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)F101(ctx,2,local+4); /*subst-multi-by-match*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
blk344:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___nn(ctx,n,argv,env)
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
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto if346;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto if347;
if346:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
if347:
	local[0]= fqv[131];
	local[1]= fqv[132];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if348;
	local[0]= fqv[131];
	local[1]= fqv[133];
	local[2]= makeflt(5.00000000e-01);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto if349;
if348:
	local[0]= NIL;
if349:
	local[0]= fqv[134];
	local[1]= fqv[132];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if350;
	local[0]= fqv[134];
	local[1]= fqv[133];
	local[2]= makeflt(9.99999791e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto if351;
if350:
	local[0]= NIL;
if351:
	ctx->vsp=local+0;
	compmacro(ctx,fqv[135],module,F102,fqv[136]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[137],module,F104,fqv[138]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[139],module,F106,fqv[140]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[141],module,F108,fqv[142]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[143],module,F110,fqv[144]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[145],module,F112,fqv[146]);
	local[0]= fqv[11];
	local[1]= fqv[147];
	local[2]= loadglobal(fqv[148]);
	local[3]= fqv[149];
	local[4]= fqv[150];
	local[5]= fqv[151];
	local[6]= NIL;
	local[7]= fqv[13];
	local[8]= NIL;
	local[9]= fqv[152];
	local[10]= makeint(-1);
	local[11]= fqv[153];
	local[12]= NIL;
	ctx->vsp=local+13;
	w=(*ftab[22])(ctx,13,local+0,&ftab[22],fqv[154]); /*make-class*/
	local[0]= fqv[17];
	local[1]= fqv[147];
	local[2]= loadglobal(fqv[148]);
	local[3]= fqv[149];
	local[4]= fqv[155];
	local[5]= fqv[151];
	local[6]= NIL;
	local[7]= fqv[13];
	local[8]= NIL;
	local[9]= fqv[152];
	local[10]= makeint(-1);
	local[11]= fqv[153];
	local[12]= NIL;
	ctx->vsp=local+13;
	w=(*ftab[22])(ctx,13,local+0,&ftab[22],fqv[154]); /*make-class*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F64,fqv[157]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[158],module,F65,fqv[159]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F66,fqv[161]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[162],module,F67,fqv[163]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[164],module,F125,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F68,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F69,fqv[169]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[170],module,F137,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F70,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F71,fqv[175]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[176],module,F157,fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F72,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F73,fqv[181]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[182],module,F169,fqv[183]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[184],module,F74,fqv[185]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F75,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F76,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F77,fqv[191]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[192],module,F78,fqv[193]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F79,fqv[195]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[196],module,F80,fqv[197]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[198],module,F81,fqv[199]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[200],module,F82,fqv[201]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[202],module,F83,fqv[203]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[204],module,F84,fqv[205]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[206],module,F85,fqv[207]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[208],module,F86,fqv[209]);
	local[0]= fqv[93];
	local[1]= fqv[147];
	local[2]= loadglobal(fqv[148]);
	local[3]= fqv[149];
	local[4]= fqv[210];
	local[5]= fqv[151];
	local[6]= NIL;
	local[7]= fqv[13];
	local[8]= NIL;
	local[9]= fqv[152];
	local[10]= makeint(-1);
	local[11]= fqv[153];
	local[12]= NIL;
	ctx->vsp=local+13;
	w=(*ftab[22])(ctx,13,local+0,&ftab[22],fqv[154]); /*make-class*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[126],module,F87,fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F88,fqv[212]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[213],module,F89,fqv[214]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F90,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[217],module,F91,fqv[218]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[99],module,F92,fqv[219]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[93],module,F278,fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F93,fqv[222]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[223],module,F94,fqv[224]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[225],module,F95,fqv[226]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[227],module,F96,fqv[228]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[229],module,F97,fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F98,fqv[232]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F99,fqv[234]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[235],module,F100,fqv[236]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[237],module,F101,fqv[238]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[239],module,F343,fqv[240]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<23; i++) ftab[i]=fcallx;
}
