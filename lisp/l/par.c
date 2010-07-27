/* par.c :  entry=par */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "par.h"
#pragma init (register_par)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___par();
extern pointer build_quote_vector();
static register_par()
  { add_module_initializer("___par", ___par);}

static pointer F84481();
static pointer F84482();
static pointer F84483();
static pointer F84484();

/*:id*/
static pointer M84531(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK84532:
	ctx->vsp=local; return(local[0]);}

/*:priority*/
static pointer M84546(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT84550;}
	local[0]= NIL;
ENT84550:
ENT84549:
	if (n>3) maerror();
	w = local[0];
	if (!isint(w)) goto IF84566;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[0]); /*unix:thr-setprio*/
	local[1]= w;
	goto IF84567;
IF84566:
	local[1]= NIL;
IF84567:
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*unix:thr-getprio*/
	local[0]= w;
BLK84547:
	ctx->vsp=local; return(local[0]);}

/*plist*/
static pointer F84584(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST84587:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL84622:
	if (local[3]==NIL) goto WHX84623;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[2];
	local[5]= fqv[3];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL84622;
WHX84623:
	local[4]= NIL;
BLK84624:
	w = NIL;
	local[2]= fqv[4];
	local[3]= fqv[3];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[6];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK84585:
	ctx->vsp=local; return(local[0]);}

/*mutex*/
static pointer F84736(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST84739:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[7];
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[8];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[9];
	local[6]= fqv[10];
	w = local[0];
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[11];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
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
	local[0]= w;
BLK84737:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M84851(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[3] = makeint(0);
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[1] = NIL;
	ctx->vsp=local+0;
	w=(*ftab[2])(ctx,0,local+0,&ftab[2],fqv[12]); /*make-mutex-lock*/
	argv[0]->c.obj.iv[6] = w;
	ctx->vsp=local+0;
	w=(*ftab[2])(ctx,0,local+0,&ftab[2],fqv[12]); /*make-mutex-lock*/
	argv[0]->c.obj.iv[5] = w;
	argv[0]->c.obj.iv[4] = NIL;
	w = argv[0];
	local[0]= w;
BLK84852:
	ctx->vsp=local; return(local[0]);}

/*:add*/
static pointer M84887(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[13]); /*member*/
	if (w!=NIL) goto IF84903;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[8]); /*mutex-lock*/
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP84934,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[2] = (pointer)((integer_t)(argv[0]->c.obj.iv[2])+4);
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	UWP84934(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
	goto IF84904;
IF84903:
	local[0]= NIL;
IF84904:
	w = local[0];
	local[0]= w;
BLK84888:
	ctx->vsp=local; return(local[0]);}

/*:remove*/
static pointer M84964(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[8]); /*mutex-lock*/
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP84996,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= argv[2];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[14]); /*delete*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	UWP84996(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK84965:
	ctx->vsp=local; return(local[0]);}

/*:wait*/
static pointer M85016(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[8]); /*mutex-lock*/
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP85046,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF85064;
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[15]); /*cond-signal*/
	argv[0]->c.obj.iv[3] = makeint(0);
	local[3]= argv[0]->c.obj.iv[3];
	goto IF85065;
IF85064:
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[16]); /*cond-wait*/
	local[3]= w;
IF85065:
	w = local[3];
	ctx->vsp=local+3;
	UWP85046(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK85017:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP84934(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[11]); /*mutex-unlock*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP84996(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[11]); /*mutex-unlock*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP85046(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[11]); /*mutex-unlock*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:read*/
static pointer M85160(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[17]); /*sema-wait*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[18]); /*sema-post*/
	w = local[0];
	local[0]= w;
BLK85161:
	ctx->vsp=local; return(local[0]);}

/*:write*/
static pointer M85202(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[17]); /*sema-wait*/
	argv[0]->c.obj.iv[3] = argv[2];
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[18]); /*sema-post*/
	local[0]= w;
BLK85203:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M85231(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(*ftab[11])(ctx,0,local+0,&ftab[11],fqv[19]); /*make-semaphore*/
	argv[0]->c.obj.iv[1] = w;
	ctx->vsp=local+0;
	w=(*ftab[11])(ctx,0,local+0,&ftab[11],fqv[19]); /*make-semaphore*/
	argv[0]->c.obj.iv[2] = w;
	argv[0]->c.obj.iv[4] = T;
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[18]); /*sema-post*/
	w = argv[0];
	local[0]= w;
BLK85232:
	ctx->vsp=local; return(local[0]);}

/*thread-eval*/
static pointer F84481(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
TAG85285:
	local[0]= argv[1];
	local[1]= fqv[20];
	local[2]= argv[0];
	local[3]= fqv[21];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)EVAL(ctx,1,local+2); /*eval*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	goto TAG85285;
	local[0]= NIL;
BLK85281:
	w = local[0];
	local[0]= w;
BLK85267:
	ctx->vsp=local; return(local[0]);}

/*thread-error*/
static pointer F84482(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT85309;}
	local[0]= NIL;
ENT85309:
ENT85308:
	if (n>4) maerror();
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,0,local+1,&ftab[12],fqv[22]); /*thread-self*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[23];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[24];
	local[5]= loadglobal(fqv[25]);
	local[6]= local[1];
	local[7]= fqv[26];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,5,local+3); /*format*/
	if (local[0]==NIL) goto IF85357;
	local[3]= local[2];
	local[4]= fqv[27];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto IF85358;
IF85357:
	local[3]= NIL;
IF85358:
	if (argv[2]==NIL) goto IF85368;
	local[3]= local[2];
	local[4]= fqv[28];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto IF85369;
IF85368:
	local[3]= NIL;
IF85369:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TERPRI(ctx,1,local+3); /*terpri*/
	local[3]= fqv[29];
	w = NIL;
	ctx->vsp=local+4;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[3];
	local[0]= w;
BLK85306:
	ctx->vsp=local; return(local[0]);}

/*thread-top*/
static pointer F84483(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	w=(*ftab[12])(ctx,0,local+0,&ftab[12],fqv[22]); /*thread-self*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= fqv[23];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= fqv[30];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,1,local+2,&ftab[13],fqv[31]); /*lisp::install-error-handler*/
	{jmp_buf jb;
	w = fqv[32];
	ctx->vsp=local+2;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT85431;}
WHL85438:
	if (T==NIL) goto WHX85439;
	{jmp_buf jb;
	w = fqv[29];
	ctx->vsp=local+8;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT85445;}
	local[14]= NIL;
	local[15]= fqv[33];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)XFORMAT(ctx,3,local+14); /*format*/
	local[14]= w;
	local[15]= argv[0];
	local[16]= T;
	ctx->vsp=local+17;
	w=(*ftab[14])(ctx,3,local+14,&ftab[14],fqv[34]); /*reploop*/
CAT85445:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL85438;
WHX85439:
	local[8]= NIL;
BLK85440:
	w = local[8];
CAT85431:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[2]= fqv[35];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[36]); /*warn*/
	local[0]= w;
BLK85390:
	ctx->vsp=local; return(local[0]);}

/*repwin*/
static pointer F84484(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT85471;}
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT85471:
ENT85470:
	if (n>2) maerror();
	local[1]= fqv[38];
	local[2]= argv[0];
	local[3]= fqv[39];
	local[4]= local[0];
	local[5]= fqv[40];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(*ftab[16])(ctx,6,local+1,&ftab[16],fqv[41]); /*make-socket-address*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,1,local+3,&ftab[17],fqv[42]); /*make-client-socket-stream*/
	local[3]= w;
	local[4]= fqv[43];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[44]); /*thread-no-wait*/
	local[0]= w;
BLK85468:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___par(ctx,n,argv,env)
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
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF85527;
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[47],w);
	goto IF85528;
IF85527:
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF85528:
	local[0]= fqv[49];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[50];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84531,fqv[26],fqv[2],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84546,fqv[52],fqv[2],fqv[53]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[54],module,F84584,fqv[55]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[56],module,F84736,fqv[57]);
	local[0]= fqv[58];
	local[1]= fqv[59];
	local[2]= fqv[58];
	local[3]= fqv[60];
	local[4]= loadglobal(fqv[61]);
	local[5]= fqv[62];
	local[6]= fqv[63];
	local[7]= fqv[64];
	local[8]= NIL;
	local[9]= fqv[65];
	local[10]= NIL;
	local[11]= fqv[66];
	local[12]= makeint(-1);
	local[13]= fqv[67];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[68]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84851,fqv[69],fqv[58],fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84887,fqv[71],fqv[58],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84964,fqv[73],fqv[58],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85016,fqv[75],fqv[58],fqv[76]);
	local[0]= fqv[77];
	local[1]= fqv[59];
	local[2]= fqv[77];
	local[3]= fqv[60];
	local[4]= loadglobal(fqv[61]);
	local[5]= fqv[62];
	local[6]= fqv[78];
	local[7]= fqv[64];
	local[8]= NIL;
	local[9]= fqv[65];
	local[10]= NIL;
	local[11]= fqv[66];
	local[12]= makeint(-1);
	local[13]= fqv[67];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[68]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85160,fqv[21],fqv[77],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85202,fqv[20],fqv[77],fqv[80]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85231,fqv[69],fqv[77],fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F84481,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F84482,fqv[84]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[43],module,F84483,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F84484,fqv[87]);
	local[0]= fqv[88];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[90]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
