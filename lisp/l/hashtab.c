/* hashtab.c :  entry=hashtab */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "hashtab.h"
#pragma init (register_hashtab)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___hashtab();
extern pointer build_quote_vector();
static register_hashtab()
  { add_module_initializer("___hashtab", ___hashtab);}

static pointer F59225();
static pointer F59227();
static pointer F59229();
static pointer F59231();
static pointer F59233();
static pointer F59235();
static pointer F59237();

/*:size*/
static pointer M59321(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK59322:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M59336(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
WHL59372:
	if (T==NIL) goto WHX59373;
	local[3]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[0]);
	  w=(local[3]->c.vec.v[i]);}
	local[1] = w;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	if (w==NIL) goto IF59390;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK59337;
	goto IF59391;
IF59390:
	local[3]= NIL;
IF59391:
	local[3]= local[1];
	if (argv[0]->c.obj.iv[7]!=local[3]) goto IF59406;
	if (local[2]!=NIL) goto IF59416;
	local[2] = local[0];
	local[3]= local[2];
	goto IF59417;
IF59416:
	local[3]= NIL;
IF59417:
	local[3]= local[2];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK59337;
	goto IF59407;
IF59406:
	local[3]= NIL;
IF59407:
	local[3]= local[1];
	if (argv[0]->c.obj.iv[8]!=local[3]) goto IF59439;
	if (local[2]!=NIL) goto IF59449;
	local[2] = local[0];
	local[3]= local[2];
	goto IF59450;
IF59449:
	local[3]= NIL;
IF59450:
	goto IF59440;
IF59439:
	local[3]= NIL;
IF59440:
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[3]= local[0];
	w = argv[0]->c.obj.iv[2];
	if ((integer_t)local[3] < (integer_t)w) goto IF59462;
	local[0] = makeint(0);
	local[3]= local[0];
	goto IF59463;
IF59462:
	local[3]= NIL;
IF59463:
	goto WHL59372;
WHX59373:
	local[3]= NIL;
BLK59374:
	w = NIL;
	local[0]= w;
BLK59337:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M59486(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF59517;
	local[1]= argv[0]->c.obj.iv[9];
	goto IF59518;
IF59517:
	local[1]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	local[1]= w;
IF59518:
	w = local[1];
	local[0]= w;
BLK59487:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M59531(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF59565;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF59576;
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF59577;
IF59576:
	local[1]= NIL;
IF59577:
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[0] = w;
	local[1]= local[0];
	goto IF59566;
IF59565:
	local[1]= NIL;
IF59566:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	w = argv[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	w = argv[3];
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	w = argv[3];
	local[0]= w;
BLK59532:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M59647(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF59682;
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])-4);
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[8];
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	w = NIL;
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= w;
	goto IF59683;
IF59682:
	local[2]= NIL;
IF59683:
	w = local[2];
	local[0]= w;
BLK59648:
	ctx->vsp=local; return(local[0]);}

/*:extend*/
static pointer M59716(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(2);
	{ integer_t i,j;
		j=intval(argv[0]->c.obj.iv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[2]); /*make-array*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[2]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	local[4]= makeint(0);
	local[5]= local[0];
WHL59779:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX59780;
	local[6]= local[1];
	local[7]= local[4];
	w = argv[0]->c.obj.iv[7];
	{ register integer_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.vec.v[i]=w;}
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL59779;
WHX59780:
	local[6]= NIL;
BLK59781:
	w = NIL;
	local[3] = argv[0]->c.obj.iv[0];
	argv[0]->c.obj.iv[0] = local[1];
	local[1] = local[3];
	local[3] = argv[0]->c.obj.iv[1];
	argv[0]->c.obj.iv[1] = local[2];
	local[2] = local[3];
	local[3] = argv[0]->c.obj.iv[2];
	argv[0]->c.obj.iv[2] = local[0];
	local[0] = local[3];
	argv[0]->c.obj.iv[3] = makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
WHL59864:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX59865;
	local[6]= local[1];
	{ register integer_t i=intval(local[4]);
	  w=(local[6]->c.vec.v[i]);}
	local[3] = w;
	local[6]= local[3];
	if (argv[0]->c.obj.iv[7]==local[6]) goto IF59884;
	local[6]= local[3];
	if (argv[0]->c.obj.iv[8]==local[6]) goto IF59884;
	local[6]= argv[0];
	local[7]= fqv[3];
	local[8]= local[3];
	local[9]= local[2];
	{ register integer_t i=intval(local[4]);
	  w=(local[9]->c.vec.v[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto IF59885;
IF59884:
	local[6]= NIL;
IF59885:
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL59864;
WHX59865:
	local[6]= NIL;
BLK59866:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK59717:
	ctx->vsp=local; return(local[0]);}

/*:hash*/
static pointer M59924(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[4]); /*string*/
	argv[2] = w;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[4]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
BLK59925:
	ctx->vsp=local; return(local[0]);}

/*:map*/
static pointer M59958(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL60008:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX60009;
	local[4]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60029;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60029;
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[2]);
	  w=(local[6]->c.vec.v[i]);}
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,3,local+4); /*funcall*/
	local[4]= w;
	goto IF60030;
IF60029:
	local[4]= NIL;
IF60030:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL60008;
WHX60009:
	local[4]= NIL;
BLK60010:
	w = NIL;
	local[0]= w;
BLK59960:
	ctx->vsp=local; return(local[0]);}

/*:list-values*/
static pointer M60071(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL60118:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX60119;
	local[4]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60139;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60139;
	local[4]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF60140;
IF60139:
	local[4]= NIL;
IF60140:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL60118;
WHX60119:
	local[4]= NIL;
BLK60120:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK60072:
	ctx->vsp=local; return(local[0]);}

/*:list-keys*/
static pointer M60190(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL60237:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX60238;
	local[4]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60258;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60258;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF60259;
IF60258:
	local[4]= NIL;
IF60259:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL60237;
WHX60238:
	local[4]= NIL;
BLK60239:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK60191:
	ctx->vsp=local; return(local[0]);}

/*:list*/
static pointer M60305(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL60352:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX60353;
	local[4]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60373;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF60373;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[1];
	{ register integer_t i=intval(local[2]);
	  w=(local[5]->c.vec.v[i]);}
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF60374;
IF60373:
	local[4]= NIL;
IF60374:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL60352;
WHX60353:
	local[4]= NIL;
BLK60354:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK60306:
	ctx->vsp=local; return(local[0]);}

/*:hash-function*/
static pointer M60427(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT60431;}
	local[0]= NIL;
ENT60431:
ENT60430:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF60447;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF60448;
IF60447:
	local[1]= NIL;
IF60448:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK60428:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M60462(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[2];
WHL60498:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX60499;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[7];
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	w = NIL;
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL60498;
WHX60499:
	local[2]= NIL;
BLK60500:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK60463:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M60541(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT60545;}
	local[0]= T;
ENT60545:
ENT60544:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[5]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[6]));
	local[5]= fqv[7];
	local[6]= local[0];
	local[7]= NIL;
	local[8]= fqv[8];
	local[9]= argv[0]->c.obj.iv[3];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,4,local+7); /*format*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK60542:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M60578(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[9], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY60594;
	local[0] = NIL;
KEY60594:
	if (n & (1<<1)) goto KEY60599;
	local[1] = makeint(10);
KEY60599:
	if (n & (1<<2)) goto KEY60604;
	local[2] = (pointer)get_sym_func(fqv[10]);
KEY60604:
	if (n & (1<<3)) goto KEY60611;
	local[3] = makeflt(2.00000000e+00);
KEY60611:
	if (n & (1<<4)) goto KEY60616;
	local[4] = (pointer)get_sym_func(fqv[11]);
KEY60616:
	argv[0]->c.obj.iv[2] = local[1];
	local[5]= loadglobal(fqv[12]);
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	argv[0]->c.obj.iv[0] = w;
	local[5]= loadglobal(fqv[12]);
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[4] = local[4];
	argv[0]->c.obj.iv[5] = local[2];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,1,local+5); /*gensym*/
	argv[0]->c.obj.iv[7] = w;
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,1,local+5); /*gensym*/
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[9] = local[0];
	argv[0]->c.obj.iv[3] = makeint(0);
	argv[0]->c.obj.iv[6] = local[3];
	local[5]= makeint(0);
	local[6]= local[1];
WHL60692:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX60693;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= local[5];
	w = argv[0]->c.obj.iv[7];
	{ register integer_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.vec.v[i]=w;}
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL60692;
WHX60693:
	local[7]= NIL;
BLK60694:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK60579:
	ctx->vsp=local; return(local[0]);}

/*make-hash-table*/
static pointer F59225(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[15], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY60738;
	local[0] = makeint(10);
KEY60738:
	if (n & (1<<1)) goto KEY60743;
	local[1] = (pointer)get_sym_func(fqv[10]);
KEY60743:
	if (n & (1<<2)) goto KEY60750;
	local[2] = makeflt(1.69999981e+00);
KEY60750:
	if (n & (1<<3)) goto KEY60755;
	local[3] = (pointer)get_sym_func(fqv[11]);
KEY60755:
	if (n & (1<<4)) goto KEY60762;
	local[4] = NIL;
KEY60762:
	local[5]= loadglobal(fqv[16]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[17];
	local[8]= fqv[18];
	local[9]= local[0];
	local[10]= fqv[19];
	local[11]= local[1];
	local[12]= fqv[20];
	local[13]= local[2];
	local[14]= fqv[21];
	local[15]= local[3];
	local[16]= fqv[22];
	local[17]= local[4];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,12,local+6); /*send*/
	w = local[5];
	local[0]= w;
BLK60727:
	ctx->vsp=local; return(local[0]);}

/*gethash*/
static pointer F59227(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[23];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK60813:
	ctx->vsp=local; return(local[0]);}

/*sethash*/
static pointer F59229(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	local[1]= fqv[3];
	local[2]= argv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK60833:
	ctx->vsp=local; return(local[0]);}

/*remhash*/
static pointer F59231(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK60856:
	ctx->vsp=local; return(local[0]);}

/*hash-table-p*/
static pointer F59233(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK60876:
	ctx->vsp=local; return(local[0]);}

/*maphash*/
static pointer F59235(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[25];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK60892:
	ctx->vsp=local; return(local[0]);}

/*clrhash*/
static pointer F59237(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK60912:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M60944(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[0];
	local[0]= w;
BLK60945:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M60967(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK60968:
	ctx->vsp=local; return(local[0]);}

/*:empty?*/
static pointer M60983(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = ((argv[0]->c.obj.iv[0])==NIL?T:NIL);
	local[0]= w;
BLK60984:
	ctx->vsp=local; return(local[0]);}

/*:trim*/
static pointer M61001(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
WHL61046:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX61047;
	local[2]= argv[0];
	local[3]= fqv[27];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL61046;
WHX61047:
	local[2]= NIL;
BLK61048:
	w = NIL;
	local[0]= w;
BLK61002:
	ctx->vsp=local; return(local[0]);}

/*:dequeue*/
static pointer M61073(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT61077;}
	local[0]= NIL;
ENT61077:
ENT61076:
	if (n>3) maerror();
	if (argv[0]->c.obj.iv[0]!=NIL) goto CON61095;
	if (local[0]==NIL) goto IF61101;
	local[1]= fqv[28];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF61102;
IF61101:
	local[1]= NIL;
IF61102:
	goto CON61093;
CON61095:
	local[1]= argv[0]->c.obj.iv[0];
	if (argv[0]->c.obj.iv[1]!=local[1]) goto CON61109;
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = NIL;
	w = local[1];
	local[1]= w;
	goto CON61093;
CON61109:
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	goto CON61093;
CON61146:
	local[1]= NIL;
CON61093:
	w = local[1];
	local[0]= w;
BLK61074:
	ctx->vsp=local; return(local[0]);}

/*:enqueue*/
static pointer M61184(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[1]==NIL) goto CON61201;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)RPLACD2(ctx,2,local+0); /*rplacd2*/
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[1] = (w)->c.cons.cdr;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON61199;
CON61201:
	local[0]= argv[2];
	w = NIL;
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	argv[0]->c.obj.iv[0] = argv[0]->c.obj.iv[1];
	local[0]= argv[0]->c.obj.iv[0];
	goto CON61199;
CON61226:
	local[0]= NIL;
CON61199:
	w = argv[2];
	local[0]= w;
BLK61185:
	ctx->vsp=local; return(local[0]);}

/*:search*/
static pointer M61249(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT61253;}
	local[0]= (pointer)get_sym_func(fqv[29]);
ENT61253:
ENT61252:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[19];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,4,local+1,&ftab[2],fqv[30]); /*find*/
	local[0]= w;
BLK61250:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M61281(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT61286;}
	local[0]= (pointer)get_sym_func(fqv[29]);
ENT61286:
	if (n>=5) { local[1]=(argv[4]); goto ENT61285;}
	local[1]= makeint(1);
ENT61285:
ENT61284:
	if (n>5) maerror();
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= fqv[19];
	local[5]= local[0];
	local[6]= fqv[31];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,6,local+2,&ftab[3],fqv[32]); /*delete*/
	argv[0]->c.obj.iv[0] = w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,1,local+2,&ftab[4],fqv[33]); /*last*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK61282:
	ctx->vsp=local; return(local[0]);}

/*:first*/
static pointer M61339(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK61340:
	ctx->vsp=local; return(local[0]);}

/*:last*/
static pointer M61358(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK61359:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___hashtab(ctx,n,argv,env)
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
	local[0]= fqv[34];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF61384;
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[36],w);
	goto IF61385;
IF61384:
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF61385:
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[16];
	local[1]= fqv[39];
	local[2]= fqv[16];
	local[3]= fqv[40];
	local[4]= loadglobal(fqv[41]);
	local[5]= fqv[42];
	local[6]= fqv[43];
	local[7]= fqv[44];
	local[8]= NIL;
	local[9]= fqv[45];
	local[10]= NIL;
	local[11]= fqv[18];
	local[12]= makeint(-1);
	local[13]= fqv[46];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,13,local+2,&ftab[5],fqv[47]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59321,fqv[18],fqv[16],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59336,fqv[0],fqv[16],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59486,fqv[23],fqv[16],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59531,fqv[3],fqv[16],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59647,fqv[24],fqv[16],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59716,fqv[1],fqv[16],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59924,fqv[21],fqv[16],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M59958,fqv[25],fqv[16],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60071,fqv[57],fqv[16],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60190,fqv[59],fqv[16],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60305,fqv[61],fqv[16],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60427,fqv[63],fqv[16],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60462,fqv[26],fqv[16],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60541,fqv[7],fqv[16],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60578,fqv[17],fqv[16],fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F59225,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F59227,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F59229,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F59231,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F59233,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F59235,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F59237,fqv[81]);
	local[0]= fqv[82];
	local[1]= fqv[39];
	local[2]= fqv[82];
	local[3]= fqv[40];
	local[4]= loadglobal(fqv[83]);
	local[5]= fqv[42];
	local[6]= fqv[84];
	local[7]= fqv[44];
	local[8]= NIL;
	local[9]= fqv[45];
	local[10]= NIL;
	local[11]= fqv[18];
	local[12]= makeint(-1);
	local[13]= fqv[46];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,13,local+2,&ftab[5],fqv[47]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60944,fqv[17],fqv[82],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60967,fqv[86],fqv[82],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60983,fqv[88],fqv[82],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61001,fqv[90],fqv[82],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61073,fqv[27],fqv[82],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61184,fqv[93],fqv[82],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61249,fqv[95],fqv[82],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61281,fqv[24],fqv[82],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61339,fqv[98],fqv[82],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61358,fqv[100],fqv[82],fqv[101]);
	local[0]= fqv[102];
	local[1]= fqv[103];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[104]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
