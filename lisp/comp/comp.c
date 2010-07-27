/* comp.c :  entry=comp */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "comp.h"
#pragma init (register_comp)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___comp();
extern pointer build_quote_vector();
static register_comp()
  { add_module_initializer("___comp", ___comp);}

static pointer F6907();
static pointer F6923();
static pointer F6925();
static pointer F6927();
static pointer F6929();
static pointer F6931();
static pointer F6933();
static pointer F6935();
static pointer F6937();
static pointer F6939();
static pointer F6941();
static pointer F6996();
static pointer F6998();
static pointer F7000();
static pointer F7002();
static pointer F7004();
static pointer F7006();

/*compiled-code-p*/
static pointer F6907(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK7033:
	ctx->vsp=local; return(local[0]);}

/*ovafp*/
static pointer F6923(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	if (local[0]==NIL) goto AND7087;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= (issymbol(w)?T:NIL);
AND7087:
	w = local[0];
	local[0]= w;
BLK7077:
	ctx->vsp=local; return(local[0]);}

/*class-symbolp*/
static pointer F6925(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND7117;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND7117;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	local[0]= w;
AND7117:
	w = local[0];
	local[0]= w;
BLK7107:
	ctx->vsp=local; return(local[0]);}

/*quoted-symbolp*/
static pointer F6927(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (iscons(w)?T:NIL);
	if (local[0]==NIL) goto AND7148;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[0]= ((fqv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND7148;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= (issymbol(w)?T:NIL);
AND7148:
	w = local[0];
	local[0]= w;
BLK7138:
	ctx->vsp=local; return(local[0]);}

/*proclaimed-special-p*/
static pointer F6929(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
OR7197:
	w = local[0];
	local[0]= w;
BLK7181:
	ctx->vsp=local; return(local[0]);}

/*proclaimed-global-p*/
static pointer F6931(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
BLK7206:
	ctx->vsp=local; return(local[0]);}

/*object-variable-names*/
static pointer F6933(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!issymbol(w)) goto IF7253;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SYMVALUE(ctx,1,local+4); /*symbol-value*/
	local[0] = w;
	local[4]= local[0];
	goto IF7254;
IF7253:
	local[0] = argv[0];
	local[4]= local[0];
IF7254:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)CLASSP(ctx,1,local+4); /*classp*/
	if (w==NIL) goto IF7275;
	local[1] = *(ovafptr(local[0],fqv[2]));
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[2] = w;
WHL7299:
	local[2] = (pointer)((integer_t)(local[2])-4);
	local[4]= local[2];
	w = makeint(0);
	if ((integer_t)local[4] < (integer_t)w) goto WHX7300;
	local[4]= local[1];
	{ register integer_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[4]= w;
	w = local[3];
	ctx->vsp=local+5;
	local[3] = cons(ctx,local[4],w);
	goto WHL7299;
WHX7300:
	local[4]= NIL;
BLK7301:
	goto IF7276;
IF7275:
	local[4]= NIL;
IF7276:
	w = local[3];
	local[0]= w;
BLK7228:
	ctx->vsp=local; return(local[0]);}

/*object-variable-type*/
static pointer F6935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w!=NIL) goto IF7355;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F6925(ctx,1,local+0); /*class-symbolp*/
	if (w==NIL) goto IF7366;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0] = w;
	local[0]= argv[0];
	goto IF7367;
IF7366:
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF7367:
	goto IF7356;
IF7355:
	local[0]= NIL;
IF7356:
	w = argv[1];
	if (!isnum(w)) goto IF7385;
	local[0]= argv[0]->c.obj.iv[5];
	{ register integer_t i=intval(argv[1]);
	  w=(local[0]->c.vec.v[i]);}
	argv[1] = w;
	local[0]= argv[1];
	goto IF7386;
IF7385:
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[4]); /*position*/
	local[0]= w;
	if (local[0]!=NIL) goto IF7418;
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[6];
	local[3]= fqv[7];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF7419;
IF7418:
	local[1]= argv[0]->c.obj.iv[5];
	{ register integer_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	argv[1] = w;
	local[1]= argv[1];
IF7419:
	w = local[1];
	local[0]= w;
IF7386:
	w = argv[1];
	if (!iscons(w)) goto IF7444;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF7445;
IF7444:
	local[0]= argv[1];
IF7445:
	w = local[0];
	local[0]= w;
BLK7336:
	ctx->vsp=local; return(local[0]);}

/*coerce-type*/
static pointer F6937(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[8];
	if (memq(local[0],w)==NIL) goto CON7470;
	local[0]= fqv[9];
	goto CON7468;
CON7470:
	local[0]= argv[0];
	w = fqv[10];
	if (memq(local[0],w)==NIL) goto CON7482;
	local[0]= fqv[11];
	goto CON7468;
CON7482:
	local[0]= argv[0];
	goto CON7468;
CON7494:
	local[0]= NIL;
CON7468:
	w = local[0];
	local[0]= w;
BLK7458:
	ctx->vsp=local; return(local[0]);}

/*check-arg*/
static pointer F6939(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7504;}
	local[0]= fqv[12];
ENT7504:
ENT7503:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto IF7520;
	local[1]= fqv[13];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[14]); /*warn*/
	local[1]= w;
	goto IF7521;
IF7520:
	local[1]= NIL;
IF7521:
	w = local[1];
	local[0]= w;
BLK7501:
	ctx->vsp=local; return(local[0]);}

/*def-function-type*/
static pointer F6941(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL7562:
	if (local[1]==NIL) goto WHX7563;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= fqv[15];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	goto WHL7562;
WHX7563:
	local[2]= NIL;
BLK7564:
	w = NIL;
	local[0]= w;
BLK7533:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M7649(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7653;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7653:
ENT7652:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F6937(ctx,1,local+1); /*coerce-type*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK7650:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M7679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7683;}
	local[0]= argv[0]->c.obj.iv[4];
ENT7683:
ENT7682:
	if (n>3) maerror();
	argv[0]->c.obj.iv[4] = local[0];
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK7680:
	ctx->vsp=local; return(local[0]);}

/*:binding*/
static pointer M7707(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7711;}
	local[0]= argv[0]->c.obj.iv[2];
ENT7711:
ENT7710:
	if (n>3) maerror();
	argv[0]->c.obj.iv[2] = local[0];
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK7708:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M7735(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	argv[0]->c.obj.iv[1] = T;
	argv[0]->c.obj.iv[2] = argv[3];
	argv[0]->c.obj.iv[3] = argv[4];
	argv[0]->c.obj.iv[4] = argv[5];
	w = argv[0];
	local[0]= w;
BLK7736:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M7796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7800;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7800:
ENT7799:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7797:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M7832(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7836;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7836:
ENT7835:
	if (n>4) maerror();
	local[1]= NIL;
WHL7864:
	local[2]= local[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto WHX7865;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[0]);
	  w=(local[3]->c.vec.v[i]);}
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	local[1] = w;
	if (local[1]==NIL) goto IF7886;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK7833;
	goto IF7887;
IF7886:
	local[0] = (pointer)((integer_t)(local[0])-4);
	local[2]= local[0];
IF7887:
	goto WHL7864;
WHX7865:
	local[2]= NIL;
BLK7866:
	w = local[2];
	local[0]= w;
BLK7833:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M7911(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7915;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7915:
ENT7914:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	w = argv[2];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[0]);
	  w=(local[4]->c.vec.v[i]);}
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	w = argv[2];
	local[0]= w;
BLK7912:
	ctx->vsp=local; return(local[0]);}

/*:enter-special*/
static pointer M7955(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK7956:
	ctx->vsp=local; return(local[0]);}

/*:create-frame*/
static pointer M7976(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = (pointer)((integer_t)(argv[0]->c.obj.iv[1])+4);
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK7977:
	ctx->vsp=local; return(local[0]);}

/*:pop-frame*/
static pointer M8000(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = NIL;
	{ register integer_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.vec.v[i]=w;}
	argv[0]->c.obj.iv[1] = (pointer)((integer_t)(argv[0]->c.obj.iv[1])-4);
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8001:
	ctx->vsp=local; return(local[0]);}

/*:clear-frame*/
static pointer M8030(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = NIL;
	{ register integer_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.vec.v[i]=w;}
	local[0]= w;
BLK8031:
	ctx->vsp=local; return(local[0]);}

/*:level*/
static pointer M8048(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8052;}
	local[0]= argv[0]->c.obj.iv[1];
ENT8052:
ENT8051:
	if (n>3) maerror();
	argv[0]->c.obj.iv[1] = local[0];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8049:
	ctx->vsp=local; return(local[0]);}

/*:frame*/
static pointer M8076(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8080;}
	local[0]= argv[0]->c.obj.iv[1];
ENT8080:
ENT8079:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	{ register integer_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	local[0]= w;
BLK8077:
	ctx->vsp=local; return(local[0]);}

/*:init-frames*/
static pointer M8102(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[2];
WHL8138:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX8139;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = NIL;
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL8138;
WHX8139:
	local[2]= NIL;
BLK8140:
	w = NIL;
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK8103:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M8174(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8178;}
	local[0]= makeint(20);
ENT8178:
ENT8177:
	if (n>3) maerror();
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[18]); /*make-array*/
	argv[0]->c.obj.iv[0] = w;
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK8175:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M8231(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8235;}
	local[0]= NIL;
ENT8235:
ENT8234:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF8251;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF8252;
IF8251:
	local[1]= NIL;
IF8252:
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK8232:
	ctx->vsp=local; return(local[0]);}

/*:special*/
static pointer M8266(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8270;}
	local[0]= makeint(0);
ENT8270:
ENT8269:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8267:
	ctx->vsp=local; return(local[0]);}

/*:local*/
static pointer M8296(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8300;}
	local[0]= makeint(0);
ENT8300:
ENT8299:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK8297:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M8326(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = makeint(0);
	argv[0]->c.obj.iv[2] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK8327:
	ctx->vsp=local; return(local[0]);}

/*:genlabel*/
static pointer M8385(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,1,local+0); /*gensym*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[19]); /*string*/
	local[0]= w;
BLK8386:
	ctx->vsp=local; return(local[0]);}

/*:progn*/
static pointer M8406(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto IF8421;
WHL8427:
	if (argv[2]==NIL) goto WHX8428;
	local[0]= argv[0];
	local[1]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	if (local[0]==NIL) goto AND8476;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[22];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
AND8476:
	goto WHL8427;
WHX8428:
	local[0]= NIL;
BLK8429:
	goto IF8422;
IF8421:
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[23];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF8422:
	w = local[0];
	local[0]= w;
BLK8407:
	ctx->vsp=local; return(local[0]);}

/*:eval*/
static pointer M8493(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF8508;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[24]); /*constantp*/
	if (w==NIL) goto IF8508;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	w = local[0];
	if (!isnum(w)) goto CON8536;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8534;
CON8536:
	local[1]= local[0];
	w = fqv[25];
	if (memq(local[1],w)==NIL) goto CON8547;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8534;
CON8547:
	w = local[0];
	if (!issymbol(w)) goto CON8563;
	local[1]= fqv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[2] = w;
	local[1]= argv[2];
	goto CON8534;
CON8563:
	w = local[0];
	if (!isstring(w)) goto CON8578;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8534;
CON8578:
	local[1]= NIL;
CON8534:
	w = local[1];
	local[0]= w;
	goto IF8509;
IF8508:
	local[0]= NIL;
IF8509:
	local[0]= argv[2];
	if (T!=local[0]) goto CON8594;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= fqv[27];
	goto CON8592;
CON8594:
	local[0]= argv[2];
	if (NIL!=local[0]) goto CON8607;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[23];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	goto CON8592;
CON8607:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[28]); /*keywordp*/
	if (w==NIL) goto CON8618;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[29];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[27];
	goto CON8592;
CON8618:
	w = argv[2];
	if (!issymbol(w)) goto CON8635;
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON8592;
CON8635:
	w = argv[2];
	if (!isint(w)) goto CON8646;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[9];
	goto CON8592;
CON8646:
	w = argv[2];
	if (!isflt(w)) goto CON8660;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[32];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[11];
	goto CON8592;
CON8660:
	w = argv[2];
	if (!!iscons(w)) goto CON8674;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[29];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= T;
	goto CON8592;
CON8674:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F6923(ctx,1,local+0); /*ovafp*/
	if (w==NIL) goto CON8686;
	local[0]= argv[0];
	local[1]= fqv[33];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON8592;
CON8686:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON8708;
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= fqv[34];
	local[3]= fqv[35];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON8592;
CON8708:
	local[0]= argv[0];
	local[1]= fqv[36];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= local[2];
	if (fqv[37]!=local[3]) goto IF8793;
	local[3]= argv[0];
	local[4]= fqv[38];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8794;
IF8793:
	local[3]= local[2];
	if (fqv[39]!=local[3]) goto IF8816;
	local[3]= argv[0];
	local[4]= fqv[40];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8817;
IF8816:
	local[3]= local[2];
	if (fqv[41]!=local[3]) goto IF8839;
	local[3]= argv[0];
	local[4]= fqv[20];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[42]); /*macroexpand*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF8840;
IF8839:
	local[3]= local[2];
	if (fqv[43]!=local[3]) goto IF8856;
	local[3]= argv[0];
	local[4]= fqv[44];
	local[5]= local[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8857;
IF8856:
	if (T==NIL) goto IF8875;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[45];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8876;
IF8875:
	local[3]= NIL;
IF8876:
IF8857:
IF8840:
IF8817:
IF8794:
	w = local[3];
	local[0]= w;
	goto CON8592;
CON8749:
	local[0]= NIL;
CON8592:
	w = local[0];
	local[0]= w;
BLK8494:
	ctx->vsp=local; return(local[0]);}

/*:get-function*/
static pointer M8888(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF8903;
	local[0]= argv[0];
	local[1]= fqv[6];
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF8904;
IF8903:
	local[0]= NIL;
IF8904:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF8929;
	local[1]= local[0];
	goto IF8930;
IF8929:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto CON8938;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[47]); /*compiled-function-p*/
	if (w==NIL) goto IF8955;
	local[1]= argv[2];
	local[2]= local[0]->c.obj.iv[2];
	local[3]= fqv[48];
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	goto IF8956;
IF8955:
	local[1]= argv[2];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF8956:
	goto CON8936;
CON8938:
	local[1]= argv[2];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	goto CON8936;
CON8985:
	local[1]= NIL;
CON8936:
IF8930:
	w = local[1];
	local[0]= w;
BLK8889:
	ctx->vsp=local; return(local[0]);}

/*:call-closure*/
static pointer M8995(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[49])==NIL) goto IF9012;
	local[0]= fqv[44];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
	goto IF9013;
IF9012:
	local[0]= NIL;
IF9013:
	local[0]= NIL;
	local[1]= argv[3];
WHL9045:
	if (local[1]==NIL) goto WHX9046;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[20];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL9045;
WHX9046:
	local[2]= NIL;
BLK9047:
	w = NIL;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[50];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[51]); /*fourth*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[44];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[52]); /*fifth*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK8996:
	ctx->vsp=local; return(local[0]);}

/*:variable*/
static pointer M9138(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[53];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF9170;
	w = local[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK9139;
	goto IF9171;
IF9170:
	local[1]= NIL;
IF9171:
	local[1]= loadglobal(fqv[54]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[55];
	local[4]= argv[2];
	local[5]= fqv[39];
	local[6]= makeint(0);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6929(ctx,1,local+1); /*proclaimed-special-p*/
	if (w==NIL) goto CON9217;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[56];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9215;
CON9217:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6931(ctx,1,local+1); /*proclaimed-global-p*/
	if (w==NIL) goto CON9230;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[56];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9215;
CON9230:
	local[1]= T;
	local[2]= fqv[57];
	local[3]= makeint(27);
	local[4]= argv[2];
	local[5]= makeint(27);
	local[6]= makeint(27);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[17];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9215;
CON9243:
	local[1]= NIL;
CON9215:
	w = local[0];
	local[0]= w;
BLK9139:
	ctx->vsp=local; return(local[0]);}

/*:var-binding*/
static pointer M9261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF9276;
	local[0]= fqv[58];
	goto IF9277;
IF9276:
	local[0]= argv[0];
	local[1]= fqv[59];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[60];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF9277:
	w = local[0];
	local[0]= w;
BLK9262:
	ctx->vsp=local; return(local[0]);}

/*:special-variable-p*/
static pointer M9294(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[61];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]!=NIL) goto IF9325;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6929(ctx,1,local+1); /*proclaimed-special-p*/
	local[1]= w;
	if (w!=NIL) goto OR9331;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6931(ctx,1,local+1); /*proclaimed-global-p*/
	local[1]= w;
OR9331:
	goto IF9326;
IF9325:
	local[1]= local[0];
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[1]= ((fqv[39])==(local[1])?T:NIL);
IF9326:
	w = local[1];
	local[0]= w;
BLK9295:
	ctx->vsp=local; return(local[0]);}

/*:enter-variable*/
static pointer M9353(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[61];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]!=NIL) goto IF9385;
	local[1]= loadglobal(fqv[54]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[55];
	local[4]= argv[2];
	local[5]= fqv[62];
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[17];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6929(ctx,1,local+1); /*proclaimed-special-p*/
	if (w!=NIL) goto OR9438;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6931(ctx,1,local+1); /*proclaimed-global-p*/
	if (w!=NIL) goto OR9438;
	goto IF9436;
OR9438:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[24]); /*constantp*/
	if (w==NIL) goto IF9454;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[63];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF9455;
IF9454:
	local[1]= NIL;
IF9455:
	local[1]= local[0];
	local[2]= fqv[60];
	local[3]= fqv[39];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF9437;
IF9436:
	local[1]= NIL;
IF9437:
	goto IF9386;
IF9385:
	local[1]= NIL;
IF9386:
	w = local[0];
	local[0]= w;
BLK9354:
	ctx->vsp=local; return(local[0]);}

/*:bind*/
static pointer M9480(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT9484;}
	local[0]= NIL;
ENT9484:
ENT9483:
	if (n>6) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF9507;
	local[1]= fqv[64];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF9508;
IF9507:
	local[1]= NIL;
IF9508:
	local[1]= argv[0];
	local[2]= fqv[65];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[2];
	if (fqv[39]!=local[2]) goto CON9544;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[66];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[3];
	local[3]= local[2];
	if (fqv[67]!=local[3]) goto IF9576;
	if (local[0]==NIL) goto IF9584;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[68];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF9585;
IF9584:
	local[3]= NIL;
IF9585:
	goto IF9577;
IF9576:
	local[3]= local[2];
	if (fqv[69]!=local[3]) goto IF9599;
	local[3]= loadglobal(fqv[21]);
	local[4]= fqv[70];
	local[5]= argv[4];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF9600;
IF9599:
	if (T==NIL) goto IF9613;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[71];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF9614;
IF9613:
	local[3]= NIL;
IF9614:
IF9600:
IF9577:
	w = local[3];
	local[2]= argv[4];
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[9] = cons(ctx,local[2],w);
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[72];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto CON9542;
CON9544:
	local[2]= argv[3];
	if (fqv[67]!=local[2]) goto IF9646;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[68];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9647;
IF9646:
	local[2]= NIL;
IF9647:
	local[2]= argv[3];
	w = local[1];
	w->c.obj.iv[2] = local[2];
	local[2]= argv[4];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[4] = local[3];
	goto CON9542;
CON9642:
	local[2]= NIL;
CON9542:
	w = local[1];
	local[0]= w;
BLK9481:
	ctx->vsp=local; return(local[0]);}

/*:create-frame*/
static pointer M9676(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[73]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[55];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
	w = argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[3] = cons(ctx,local[0],w);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[75];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK9677:
	ctx->vsp=local; return(local[0]);}

/*:delete-frame*/
static pointer M9742(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= local[0]->c.obj.iv[1];
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF9810;
	if (argv[2]==NIL) goto IF9816;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[76];
	local[4]= local[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9817;
IF9816:
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[78];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF9817:
	goto IF9811;
IF9810:
	local[2]= NIL;
IF9811:
	if (argv[2]==NIL) goto IF9835;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[79];
	local[4]= local[0]->c.obj.iv[1];
	local[5]= local[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF9836;
IF9835:
	local[2]= NIL;
IF9836:
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[80];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[75];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK9743:
	ctx->vsp=local; return(local[0]);}

/*:load-ovaf*/
static pointer M9869(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= local[0];
	w = fqv[81];
	if (memq(local[2],w)!=NIL) goto IF9905;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[0] = w;
	local[2]= local[0];
	goto IF9906;
IF9905:
	local[2]= NIL;
IF9906:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLASSP(ctx,1,local+2); /*classp*/
	if (w==NIL) goto CON9927;
	local[2]= argv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F6933(ctx,1,local+3); /*object-variable-names*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[4]); /*position*/
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto IF9947;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[82];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9948;
IF9947:
	local[2]= argv[0];
	local[3]= fqv[6];
	local[4]= fqv[83];
	local[5]= argv[2];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
IF9948:
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F6935(ctx,2,local+2); /*object-variable-type*/
	local[2]= w;
	goto CON9925;
CON9927:
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[33];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= T;
	goto CON9925;
CON9970:
	local[2]= NIL;
CON9925:
	w = local[2];
	local[0]= w;
BLK9870:
	ctx->vsp=local; return(local[0]);}

/*:load-var*/
static pointer M9982(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF9998;
	local[0]= argv[0];
	local[1]= fqv[33];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	w = T;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK9983;
	goto IF9999;
IF9998:
	local[0]= NIL;
IF9999:
	local[0]= argv[0];
	local[1]= fqv[59];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= *(ovafptr(argv[2],fqv[84]));
	local[1]= local[0];
	w = fqv[85];
	if (memq(local[1],w)==NIL) goto IF10053;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[86];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF10054;
IF10053:
	local[1]= local[0];
	w = fqv[87];
	if (memq(local[1],w)==NIL) goto IF10071;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[50];
	local[3]= *(ovafptr(argv[2],fqv[88]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[89]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10072;
IF10071:
	local[1]= local[0];
	w = fqv[90];
	if (memq(local[1],w)==NIL) goto IF10094;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[70];
	local[3]= *(ovafptr(argv[2],fqv[88]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[89]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10095;
IF10094:
	local[1]= local[0];
	w = fqv[91];
	if (memq(local[1],w)==NIL) goto IF10117;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[92];
	local[3]= *(ovafptr(argv[2],fqv[88]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[89]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10118;
IF10117:
	local[1]= local[0];
	if (fqv[62]!=local[1]) goto IF10140;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[93];
	local[4]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10141;
IF10140:
	local[1]= NIL;
IF10141:
IF10118:
IF10095:
IF10072:
IF10054:
	w = local[1];
	local[0]= argv[2];
	local[1]= fqv[94];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK9983:
	ctx->vsp=local; return(local[0]);}

/*:store-ovaf*/
static pointer M10162(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[95];
	if (memq(local[1],w)!=NIL) goto IF10195;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)SYMVALUE(ctx,1,local+1); /*symbol-value*/
	local[0] = w;
	local[1]= local[0];
	goto IF10196;
IF10195:
	local[1]= NIL;
IF10196:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)CLASSP(ctx,1,local+1); /*classp*/
	if (w==NIL) goto IF10215;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[96];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F6933(ctx,1,local+4); /*object-variable-names*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[4]); /*position*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF10216;
IF10215:
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[97];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF10216:
	w = local[1];
	local[0]= w;
BLK10163:
	ctx->vsp=local; return(local[0]);}

/*:store-var*/
static pointer M10245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[59];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= *(ovafptr(argv[2],fqv[84]));
	local[1]= local[0];
	w = fqv[98];
	if (memq(local[1],w)==NIL) goto IF10286;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[99];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF10287;
IF10286:
	local[1]= local[0];
	w = fqv[100];
	if (memq(local[1],w)==NIL) goto IF10304;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[101];
	local[3]= *(ovafptr(argv[2],fqv[88]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[89]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10305;
IF10304:
	local[1]= local[0];
	w = fqv[102];
	if (memq(local[1],w)==NIL) goto IF10327;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[103];
	local[3]= *(ovafptr(argv[2],fqv[88]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[89]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10328;
IF10327:
	local[1]= local[0];
	w = fqv[104];
	if (memq(local[1],w)==NIL) goto IF10350;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[105];
	local[3]= *(ovafptr(argv[2],fqv[88]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[89]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10351;
IF10350:
	local[1]= NIL;
IF10351:
IF10328:
IF10305:
IF10287:
	w = local[1];
	local[0]= w;
BLK10246:
	ctx->vsp=local; return(local[0]);}

/*:funcall*/
static pointer M10401(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	w = fqv[106];
	if (memq(local[3],w)!=NIL) goto IF10443;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO10457,env,argv,local);
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[1] = w;
	local[3]= local[1];
	goto IF10444;
IF10443:
	local[3]= NIL;
IF10444:
	local[3]= argv[2];
	local[4]= local[3];
	w = fqv[107];
	if (memq(local[4],w)==NIL) goto IF10479;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[108];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[109];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[27];
	goto IF10480;
IF10479:
	local[4]= local[3];
	w = fqv[110];
	if (memq(local[4],w)==NIL) goto IF10507;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[111];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[112];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[27];
	goto IF10508;
IF10507:
	local[4]= local[3];
	w = fqv[113];
	if (memq(local[4],w)==NIL) goto IF10535;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[114];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[115];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10536;
IF10535:
	local[4]= local[3];
	w = fqv[116];
	if (memq(local[4],w)==NIL) goto IF10561;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[117];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[118];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto IF10562;
IF10561:
	local[4]= local[3];
	w = fqv[119];
	if (memq(local[4],w)==NIL) goto IF10589;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[120];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto IF10590;
IF10589:
	local[4]= local[3];
	w = fqv[122];
	if (memq(local[4],w)==NIL) goto IF10617;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[123];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10618;
IF10617:
	local[4]= local[3];
	w = fqv[124];
	if (memq(local[4],w)==NIL) goto IF10642;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[125];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10643;
IF10642:
	local[4]= local[3];
	w = fqv[126];
	if (memq(local[4],w)==NIL) goto IF10667;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[127];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10668;
IF10667:
	local[4]= local[3];
	w = fqv[128];
	if (memq(local[4],w)==NIL) goto IF10692;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[129];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10693;
IF10692:
	local[4]= local[3];
	w = fqv[130];
	if (memq(local[4],w)==NIL) goto IF10717;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[131];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10718;
IF10717:
	local[4]= local[3];
	w = fqv[132];
	if (memq(local[4],w)==NIL) goto IF10742;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10743;
IF10742:
	local[4]= local[3];
	w = fqv[134];
	if (memq(local[4],w)==NIL) goto IF10767;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[135];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10768;
IF10767:
	local[4]= local[3];
	w = fqv[136];
	if (memq(local[4],w)==NIL) goto IF10792;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[137];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[138];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10793;
IF10792:
	local[4]= local[3];
	w = fqv[139];
	if (memq(local[4],w)==NIL) goto IF10818;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[140];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= T;
	goto IF10819;
IF10818:
	local[4]= local[3];
	w = fqv[141];
	if (memq(local[4],w)==NIL) goto IF10844;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[142];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[143];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10845;
IF10844:
	local[4]= local[3];
	w = fqv[144];
	if (memq(local[4],w)==NIL) goto IF10870;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= fqv[145];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[146];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10871;
IF10870:
	local[4]= local[3];
	w = fqv[147];
	if (memq(local[4],w)==NIL) goto IF10896;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[148];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF10897;
IF10896:
	local[4]= local[3];
	w = fqv[149];
	if (memq(local[4],w)==NIL) goto IF10920;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[150];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF10921;
IF10920:
	local[4]= local[3];
	w = fqv[151];
	if (memq(local[4],w)==NIL) goto IF10944;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[152];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF10945;
IF10944:
	local[4]= local[3];
	w = fqv[153];
	if (memq(local[4],w)==NIL) goto IF10968;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[154];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF10969;
IF10968:
	local[4]= local[3];
	w = fqv[155];
	if (memq(local[4],w)==NIL) goto IF10992;
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= fqv[156];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF11003;
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[157];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF11004;
IF11003:
	local[4]= argv[0];
	local[5]= fqv[158];
	local[6]= argv[2];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
IF11004:
	goto IF10993;
IF10992:
	local[4]= local[3];
	w = fqv[159];
	if (memq(local[4],w)==NIL) goto IF11033;
	local[4]= argv[0];
	local[5]= fqv[160];
	local[6]= argv[2];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF11034;
IF11033:
	local[4]= local[3];
	w = fqv[161];
	if (memq(local[4],w)==NIL) goto IF11052;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= fqv[162];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= argv[0];
	local[5]= fqv[163];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF11053;
IF11052:
	local[4]= local[3];
	w = fqv[164];
	if (memq(local[4],w)==NIL) goto IF11098;
	local[4]= makeint(4);
	local[5]= local[0];
	local[6]= fqv[165];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	local[4]= argv[0];
	local[5]= fqv[166];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,1,local+9,&ftab[8],fqv[51]); /*fourth*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= w;
	goto IF11099;
IF11098:
	local[4]= local[3];
	w = fqv[167];
	if (memq(local[4],w)==NIL) goto IF11147;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[168];
	ctx->vsp=local+7;
	w=(pointer)F6939(ctx,3,local+4); /*check-arg*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6937(ctx,1,local+4); /*coerce-type*/
	local[4]= w;
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON11169;
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[169];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto CON11167;
CON11169:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6937(ctx,1,local+4); /*coerce-type*/
	local[4]= w;
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON11192;
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[170];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[11];
	goto CON11167;
CON11192:
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[157];
	local[6]= argv[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= T;
	goto CON11167;
CON11215:
	local[4]= NIL;
CON11167:
	goto IF11148;
IF11147:
	if (T==NIL) goto IF11226;
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[157];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[2];
	if (!issymbol(w)) goto IF11242;
	local[4]= argv[2];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	goto IF11243;
IF11242:
	local[4]= T;
IF11243:
	goto IF11227;
IF11226:
	local[4]= NIL;
IF11227:
IF11148:
IF11099:
IF11053:
IF11034:
IF10993:
IF10969:
IF10945:
IF10921:
IF10897:
IF10871:
IF10845:
IF10819:
IF10793:
IF10768:
IF10743:
IF10718:
IF10693:
IF10668:
IF10643:
IF10618:
IF10590:
IF10562:
IF10536:
IF10508:
IF10480:
	w = local[4];
	local[0]= w;
BLK10402:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO10457(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[20];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:vector-op*/
static pointer M11298(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[2];
	local[2]= fqv[171];
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w = local[0];
	if (!issymbol(w)) goto IF11344;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)BOUNDP(ctx,1,local+2); /*boundp*/
	if (w==NIL) goto IF11344;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLASSP(ctx,1,local+2); /*classp*/
	if (w==NIL) goto IF11344;
	local[2]= local[0];
	local[3]= loadglobal(fqv[172]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11370;
	local[2]= loadglobal(fqv[21]);
	local[3]= local[1];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11368;
CON11370:
	local[2]= local[0];
	local[3]= loadglobal(fqv[19]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11388;
	local[2]= loadglobal(fqv[21]);
	local[3]= local[1];
	local[4]= fqv[173];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11368;
CON11388:
	local[2]= local[0];
	local[3]= loadglobal(fqv[174]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11406;
	local[2]= loadglobal(fqv[21]);
	local[3]= local[1];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[11];
	goto CON11368;
CON11406:
	local[2]= local[0];
	local[3]= loadglobal(fqv[175]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11424;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[157];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11368;
CON11424:
	local[2]= local[0];
	local[3]= loadglobal(fqv[176]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11443;
	local[2]= loadglobal(fqv[21]);
	local[3]= local[1];
	local[4]= fqv[177];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= T;
	goto CON11368;
CON11443:
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[157];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= T;
	goto CON11368;
CON11459:
	local[2]= NIL;
CON11368:
	goto IF11345;
IF11344:
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[157];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
IF11345:
	w = local[2];
	local[0]= w;
BLK11299:
	ctx->vsp=local; return(local[0]);}

/*:slot*/
static pointer M11479(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = argv[4];
	if (isnum(w)) goto IF11515;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)F6925(ctx,1,local+1); /*class-symbolp*/
	if (w==NIL) goto IF11515;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)F6927(ctx,1,local+1); /*quoted-symbolp*/
	if (w==NIL) goto IF11515;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= *(ovafptr(w,fqv[2]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[4]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF11515;
	argv[4] = local[0];
	local[1]= argv[4];
	goto IF11516;
IF11515:
	local[1]= NIL;
IF11516:
	w = argv[4];
	if (!isnum(w)) goto CON11564;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[82];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[3];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F6935(ctx,2,local+1); /*object-variable-type*/
	local[1]= w;
	goto CON11562;
CON11564:
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[157];
	local[3]= fqv[162];
	local[4]= makeint(3);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto CON11562;
CON11580:
	local[1]= NIL;
CON11562:
	w = local[1];
	local[0]= w;
BLK11480:
	ctx->vsp=local; return(local[0]);}

/*:setslot*/
static pointer M11607(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= NIL;
	w = argv[4];
	if (isnum(w)) goto IF11638;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)F6925(ctx,1,local+1); /*class-symbolp*/
	if (w==NIL) goto IF11638;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)F6927(ctx,1,local+1); /*quoted-symbolp*/
	if (w==NIL) goto IF11638;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= *(ovafptr(w,fqv[2]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[4]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF11638;
	argv[4] = local[0];
	local[1]= argv[4];
	goto IF11639;
IF11638:
	local[1]= NIL;
IF11639:
	w = argv[4];
	if (!isnum(w)) goto CON11687;
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[178];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[96];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[3];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F6935(ctx,2,local+1); /*object-variable-type*/
	local[1]= w;
	goto CON11685;
CON11687:
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[157];
	local[3]= fqv[165];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto CON11685;
CON11723:
	local[1]= NIL;
CON11685:
	w = local[1];
	local[0]= w;
BLK11608:
	ctx->vsp=local; return(local[0]);}

/*:arithmetic*/
static pointer M11791(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= loadglobal(fqv[179]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF11810;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[157];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto IF11811;
IF11810:
	local[0]= argv[2];
	if (fqv[180]!=local[0]) goto CON11830;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO11844,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[181]); /*every*/
	if (w==NIL) goto CON11840;
	local[0]= argv[3];
	local[1]= local[0];
	w = fqv[182];
	if (memq(local[1],w)==NIL) goto IF11865;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[183];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF11866;
IF11865:
	local[1]= local[0];
	w = fqv[184];
	if (memq(local[1],w)==NIL) goto IF11881;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[185];
	local[3]= fqv[180];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF11882;
IF11881:
	if (T==NIL) goto IF11899;
WHL11907:
	argv[3] = (pointer)((integer_t)(argv[3])-4);
	local[1]= argv[3];
	w = makeint(1);
	if ((integer_t)local[1] <= (integer_t)w) goto WHX11908;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[185];
	local[3]= fqv[186];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL11907;
WHX11908:
	local[1]= NIL;
BLK11909:
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[183];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[185];
	local[3]= fqv[186];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF11900;
IF11899:
	local[1]= NIL;
IF11900:
IF11882:
IF11866:
	w = local[1];
	local[0]= fqv[9];
	goto CON11838;
CON11840:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO11952,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[181]); /*every*/
	if (w==NIL) goto CON11948;
	local[0]= argv[3];
	local[1]= local[0];
	w = fqv[187];
	if (memq(local[1],w)==NIL) goto IF11972;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[188];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF11973;
IF11972:
	local[1]= local[0];
	w = fqv[189];
	if (memq(local[1],w)==NIL) goto IF11988;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[190];
	local[3]= fqv[180];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF11989;
IF11988:
	if (T==NIL) goto IF12006;
WHL12014:
	argv[3] = (pointer)((integer_t)(argv[3])-4);
	local[1]= argv[3];
	w = makeint(1);
	if ((integer_t)local[1] <= (integer_t)w) goto WHX12015;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[190];
	local[3]= fqv[186];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL12014;
WHX12015:
	local[1]= NIL;
BLK12016:
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[188];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[190];
	local[3]= fqv[186];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12007;
IF12006:
	local[1]= NIL;
IF12007:
IF11989:
IF11973:
	w = local[1];
	local[0]= fqv[11];
	goto CON11838;
CON11948:
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[157];
	local[2]= fqv[180];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto CON11838;
CON12055:
	local[0]= NIL;
CON11838:
	goto CON11828;
CON11830:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12077,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[181]); /*every*/
	if (w==NIL) goto CON12073;
WHL12084:
	argv[3] = (pointer)((integer_t)(argv[3])-4);
	local[0]= argv[3];
	w = makeint(0);
	if ((integer_t)local[0] <= (integer_t)w) goto WHX12085;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[185];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	goto WHL12084;
WHX12085:
	local[0]= NIL;
BLK12086:
	local[0]= fqv[9];
	goto CON12071;
CON12073:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12113,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[181]); /*every*/
	if (w==NIL) goto CON12109;
WHL12120:
	argv[3] = (pointer)((integer_t)(argv[3])-4);
	local[0]= argv[3];
	w = makeint(0);
	if ((integer_t)local[0] <= (integer_t)w) goto WHX12121;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[190];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	goto WHL12120;
WHX12121:
	local[0]= NIL;
BLK12122:
	local[0]= fqv[11];
	goto CON12071;
CON12109:
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[157];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto CON12071;
CON12145:
	local[0]= NIL;
CON12071:
	goto CON11828;
CON12067:
	local[0]= NIL;
CON11828:
IF11811:
	w = local[0];
	local[0]= w;
BLK11792:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11844(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[191];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11952(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[192];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12077(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[193];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12113(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[194];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:special-form*/
static pointer M12252(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= local[0];
	w = fqv[195];
	if (memq(local[1],w)==NIL) goto IF12282;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[29];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12283;
IF12282:
	local[1]= local[0];
	w = fqv[196];
	if (memq(local[1],w)==NIL) goto IF12307;
	local[1]= argv[0];
	local[2]= fqv[197];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12308;
IF12307:
	local[1]= local[0];
	w = fqv[198];
	if (memq(local[1],w)==NIL) goto IF12324;
	local[1]= argv[0];
	local[2]= fqv[199];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12325;
IF12324:
	local[1]= local[0];
	w = fqv[200];
	if (memq(local[1],w)==NIL) goto IF12345;
	local[1]= argv[0];
	local[2]= fqv[201];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12346;
IF12345:
	local[1]= local[0];
	w = fqv[202];
	if (memq(local[1],w)==NIL) goto IF12366;
	local[1]= argv[0];
	local[2]= fqv[203];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12367;
IF12366:
	local[1]= local[0];
	w = fqv[204];
	if (memq(local[1],w)==NIL) goto IF12387;
	local[1]= argv[0];
	local[2]= fqv[205];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12388;
IF12387:
	local[1]= local[0];
	w = fqv[206];
	if (memq(local[1],w)==NIL) goto IF12408;
	local[1]= argv[0];
	local[2]= fqv[207];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12409;
IF12408:
	local[1]= local[0];
	w = fqv[208];
	if (memq(local[1],w)==NIL) goto IF12429;
	local[1]= argv[0];
	local[2]= fqv[209];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12430;
IF12429:
	local[1]= local[0];
	w = fqv[210];
	if (memq(local[1],w)==NIL) goto IF12450;
	local[1]= argv[0];
	local[2]= fqv[211];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12451;
IF12450:
	local[1]= local[0];
	w = fqv[212];
	if (memq(local[1],w)==NIL) goto IF12471;
	local[1]= argv[0];
	local[2]= fqv[213];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12472;
IF12471:
	local[1]= local[0];
	w = fqv[214];
	if (memq(local[1],w)==NIL) goto IF12501;
	local[1]= argv[0];
	local[2]= fqv[215];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12502;
IF12501:
	local[1]= local[0];
	w = fqv[216];
	if (memq(local[1],w)==NIL) goto IF12533;
	local[1]= argv[0];
	local[2]= fqv[217];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12534;
IF12533:
	local[1]= local[0];
	w = fqv[218];
	if (memq(local[1],w)==NIL) goto IF12563;
	local[1]= argv[0];
	local[2]= fqv[219];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12564;
IF12563:
	local[1]= local[0];
	w = fqv[220];
	if (memq(local[1],w)==NIL) goto IF12595;
	local[1]= argv[0];
	local[2]= fqv[221];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12596;
IF12595:
	local[1]= local[0];
	w = fqv[222];
	if (memq(local[1],w)==NIL) goto IF12616;
	local[1]= argv[0];
	local[2]= fqv[223];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12617;
IF12616:
	local[1]= local[0];
	w = fqv[224];
	if (memq(local[1],w)==NIL) goto IF12641;
	local[1]= argv[0];
	local[2]= fqv[225];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= T;
	goto IF12642;
IF12641:
	local[1]= local[0];
	w = fqv[226];
	if (memq(local[1],w)==NIL) goto IF12671;
	local[1]= argv[0];
	local[2]= fqv[225];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= T;
	goto IF12672;
IF12671:
	local[1]= local[0];
	w = fqv[227];
	if (memq(local[1],w)==NIL) goto IF12701;
	local[1]= argv[0];
	local[2]= fqv[228];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12702;
IF12701:
	local[1]= local[0];
	w = fqv[229];
	if (memq(local[1],w)==NIL) goto IF12731;
	local[1]= argv[0];
	local[2]= fqv[230];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12732;
IF12731:
	local[1]= local[0];
	w = fqv[231];
	if (memq(local[1],w)==NIL) goto IF12752;
	local[1]= argv[0];
	local[2]= fqv[232];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12753;
IF12752:
	local[1]= local[0];
	w = fqv[233];
	if (memq(local[1],w)==NIL) goto IF12777;
	local[1]= argv[0];
	local[2]= fqv[20];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F6937(ctx,1,local+1); /*coerce-type*/
	local[1]= w;
	goto IF12778;
IF12777:
	local[1]= local[0];
	w = fqv[234];
	if (memq(local[1],w)==NIL) goto IF12811;
	local[1]= argv[0];
	local[2]= fqv[77];
	local[3]= fqv[235];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12812;
IF12811:
	local[1]= local[0];
	w = fqv[236];
	if (memq(local[1],w)==NIL) goto IF12831;
	local[1]= argv[0];
	local[2]= fqv[77];
	local[3]= fqv[237];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12832;
IF12831:
	local[1]= local[0];
	w = fqv[238];
	if (memq(local[1],w)==NIL) goto IF12851;
	local[1]= argv[0];
	local[2]= fqv[77];
	local[3]= fqv[239];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12852;
IF12851:
	local[1]= local[0];
	w = fqv[240];
	if (memq(local[1],w)==NIL) goto IF12871;
	local[1]= argv[0];
	local[2]= fqv[77];
	local[3]= fqv[241];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12872;
IF12871:
	if (T==NIL) goto IF12891;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[242];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF12892;
IF12891:
	local[1]= NIL;
IF12892:
IF12872:
IF12852:
IF12832:
IF12812:
IF12778:
IF12753:
IF12732:
IF12702:
IF12672:
IF12642:
IF12617:
IF12596:
IF12564:
IF12534:
IF12502:
IF12472:
IF12451:
IF12430:
IF12409:
IF12388:
IF12367:
IF12346:
IF12325:
IF12308:
IF12283:
	w = local[1];
	local[0]= w;
BLK12253:
	ctx->vsp=local; return(local[0]);}

/*:conditional-jump*/
static pointer M12930(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[3]==NIL) goto IF12947;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[243];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF12948;
IF12947:
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[244];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF12948:
	w = local[0];
	local[0]= w;
BLK12931:
	ctx->vsp=local; return(local[0]);}

/*:evcon*/
static pointer M12965(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[4];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LISTP(ctx,1,local+5); /*listp*/
	if (w==NIL) goto IF13001;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	local[5]= local[1];
	goto IF13002;
IF13001:
	local[5]= NIL;
IF13002:
	w = argv[2];
	if (!iscons(w)) goto OR13030;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w = makeint(1);
	if ((integer_t)local[5] <= (integer_t)w) goto OR13030;
	goto CON13029;
OR13030:
	local[5]= argv[0];
	local[6]= fqv[20];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[245];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13027;
CON13029:
	local[5]= local[0];
	if (fqv[111]!=local[5]) goto CON13055;
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6939(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[20];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[20];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[4]==NIL) goto IF13094;
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[246];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13095;
IF13094:
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[247];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
IF13095:
	goto CON13027;
CON13055:
	local[5]= local[0];
	w = fqv[248];
	if (memq(local[5],w)==NIL) goto CON13111;
	local[5]= makeint(1);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6939(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[249];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= argv[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON13027;
CON13111:
	local[5]= local[0];
	if (fqv[250]!=local[5]) goto CON13140;
	if (argv[4]!=NIL) goto IF13148;
	local[5]= argv[0];
	local[6]= fqv[251];
	local[7]= fqv[252];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= local[4];
	goto IF13149;
IF13148:
	local[5]= NIL;
IF13149:
WHL13165:
	if (local[1]==NIL) goto WHX13166;
	local[5]= argv[0];
	local[6]= fqv[249];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	local[8]= NIL;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	goto WHL13165;
WHX13166:
	local[5]= NIL;
BLK13167:
	if (argv[4]!=NIL) goto IF13216;
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[253];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13217;
IF13216:
	local[5]= NIL;
IF13217:
	goto CON13027;
CON13140:
	local[5]= local[0];
	if (fqv[255]!=local[5]) goto CON13237;
	if (argv[3]!=NIL) goto IF13245;
	local[5]= argv[0];
	local[6]= fqv[251];
	local[7]= fqv[256];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= local[4];
	goto IF13246;
IF13245:
	local[4] = argv[3];
	local[5]= local[4];
IF13246:
WHL13268:
	if (local[1]==NIL) goto WHX13269;
	local[5]= argv[0];
	local[6]= fqv[249];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	local[8]= local[4];
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	goto WHL13268;
WHX13269:
	local[5]= NIL;
BLK13270:
	if (argv[3]!=NIL) goto IF13319;
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[253];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13320;
IF13319:
	local[5]= NIL;
IF13320:
	goto CON13027;
CON13237:
	local[5]= local[0];
	w = fqv[257];
	if (memq(local[5],w)==NIL) goto CON13340;
	local[5]= makeint(1);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6939(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[20];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[4]==NIL) goto IF13369;
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[258];
	local[7]= local[0];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF13370;
IF13369:
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[259];
	local[7]= local[0];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
IF13370:
	goto CON13027;
CON13340:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	if (makeint(2)!=local[5]) goto CON13388;
	local[5]= local[0];
	w = fqv[260];
	if (memq(local[5],w)==NIL) goto CON13388;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO13408,env,argv,local);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[261];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,2,local+5,&ftab[11],fqv[262]); /*member*/
	if (w==NIL) goto CON13419;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto CON13419;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[263];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	if (argv[3]==NIL) goto CON13472;
	local[4] = argv[3];
	local[5]= local[4];
	goto CON13470;
CON13472:
	local[5]= local[0];
	local[6]= fqv[264];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[5]= local[0];
	goto CON13470;
CON13483:
	local[5]= NIL;
CON13470:
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[265];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON13417;
CON13419:
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[157];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[245];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13417;
CON13509:
	local[5]= NIL;
CON13417:
	goto CON13027;
CON13388:
	local[5]= argv[0];
	local[6]= fqv[20];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[245];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13027;
CON13529:
	local[5]= NIL;
CON13027:
	w = local[5];
	local[0]= w;
BLK12966:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO13408(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[20];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:if*/
static pointer M13591(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[251];
	local[2]= fqv[266];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[251];
	local[3]= fqv[267];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[249];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[253];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[268];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[254];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[254];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK13592:
	ctx->vsp=local; return(local[0]);}

/*:setq*/
static pointer M13696(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto IF13712;
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[23];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = T;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK13697;
	goto IF13713;
IF13712:
	local[0]= NIL;
IF13713:
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL13750:
	if (argv[2]==NIL) goto WHX13751;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[2] = NIL;
	local[4]= argv[0];
	local[5]= fqv[20];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	if (argv[2]!=NIL) goto IF13802;
	local[4]= argv[0];
	local[5]= fqv[269];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = fqv[270];
	if (memq(local[4],w)==NIL) goto IF13802;
	local[2] = T;
	local[4]= loadglobal(fqv[21]);
	local[5]= fqv[178];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF13803;
IF13802:
	local[4]= NIL;
IF13803:
	w = local[0];
	if (!issymbol(w)) goto IF13837;
	local[4]= argv[0];
	local[5]= fqv[271];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF13838;
IF13837:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (issymbol(w)) goto IF13852;
	local[4]= argv[0];
	local[5]= fqv[6];
	local[6]= fqv[272];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF13853;
IF13852:
	local[4]= NIL;
IF13853:
	local[4]= argv[0];
	local[5]= fqv[97];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
IF13838:
	local[4]= ((argv[2])==NIL?T:NIL);
	if (local[4]==NIL) goto AND13885;
	local[4]= ((local[2])==NIL?T:NIL);
	if (local[4]==NIL) goto AND13885;
	local[4]= argv[0];
	local[5]= fqv[30];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
AND13885:
	goto WHL13750;
WHX13751:
	local[4]= NIL;
BLK13752:
	w = local[3];
	local[0]= w;
BLK13697:
	ctx->vsp=local; return(local[0]);}

/*:let**/
static pointer M13910(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= argv[0];
	local[3]= fqv[74];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
WHL13980:
	if (argv[2]==NIL) goto WHX13981;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX13981;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[273]!=local[2]) goto WHX13981;
	local[2]= argv[0];
	local[3]= fqv[274];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL13980;
WHX13981:
	local[2]= NIL;
BLK13982:
	local[2]= NIL;
	local[3]= local[0];
WHL14069:
	if (local[3]==NIL) goto WHX14070;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[20];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF14122;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF14123;
IF14122:
	local[6]= NIL;
IF14123:
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[275];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF14143;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF14144;
IF14143:
	local[6]= local[2];
IF14144:
	local[7]= fqv[67];
	local[8]= loadglobal(fqv[21]);
	local[9]= fqv[276];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= (pointer)((integer_t)(w)-4);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	goto WHL14069;
WHX14070:
	local[4]= NIL;
BLK14071:
	w = NIL;
	local[2]= argv[0];
	local[3]= fqv[230];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[0]->c.obj.iv[9] = local[1];
	local[2]= argv[0];
	local[3]= fqv[277];
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK13911:
	ctx->vsp=local; return(local[0]);}

/*:let*/
static pointer M14192(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= argv[0];
	local[6]= fqv[74];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
WHL14268:
	if (argv[2]==NIL) goto WHX14269;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX14269;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	if (fqv[273]!=local[5]) goto WHX14269;
	local[5]= argv[0];
	local[6]= fqv[274];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL14268;
WHX14269:
	local[5]= NIL;
BLK14270:
	local[5]= NIL;
	local[6]= local[0];
WHL14357:
	if (local[6]==NIL) goto WHX14358;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= fqv[75];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	argv[0]->c.obj.iv[2] = (pointer)((integer_t)(w)-4);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LISTP(ctx,1,local+7); /*listp*/
	if (w==NIL) goto IF14422;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	goto IF14423;
IF14422:
	local[7]= local[5];
IF14423:
	local[1] = local[7];
	local[7]= argv[0];
	local[8]= fqv[20];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)LISTP(ctx,1,local+9); /*listp*/
	if (w==NIL) goto IF14473;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	goto IF14474;
IF14473:
	local[9]= NIL;
IF14474:
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= loadglobal(fqv[21]);
	local[8]= fqv[276];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = (pointer)((integer_t)(w)-4);
	local[7]= argv[0];
	local[8]= fqv[278];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto CON14504;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[68];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto CON14502;
CON14504:
	local[7]= argv[0];
	local[8]= fqv[275];
	local[9]= local[1];
	local[10]= fqv[67];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	goto CON14502;
CON14538:
	local[7]= NIL;
CON14502:
	goto WHL14357;
WHX14358:
	local[7]= NIL;
BLK14359:
	w = NIL;
	local[5]= NIL;
	local[6]= local[2];
WHL14572:
	if (local[6]==NIL) goto WHX14573;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= loadglobal(fqv[21]);
	local[8]= fqv[276];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = w;
	local[7]= loadglobal(fqv[21]);
	local[8]= fqv[50];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[275];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[67];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	goto WHL14572;
WHX14573:
	local[7]= NIL;
BLK14574:
	w = NIL;
	local[5]= argv[0]->c.obj.iv[0];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0];
	local[6]= fqv[230];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[0]->c.obj.iv[9] = local[4];
	local[5]= argv[0];
	local[6]= fqv[277];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK14193:
	ctx->vsp=local; return(local[0]);}

/*:cond*/
static pointer M14693(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[251];
	local[6]= fqv[279];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
WHL14731:
	if (argv[2]==NIL) goto WHX14732;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[5];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[5]= argv[0];
	local[6]= fqv[251];
	local[7]= fqv[280];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON14796;
	local[5]= argv[0];
	local[6]= fqv[20];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[178];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[244];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[22];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto CON14794;
CON14796:
	local[5]= local[1];
	if (T!=local[5]) goto CON14830;
	local[3] = T;
	local[5]= local[3];
	goto CON14794;
CON14830:
	local[5]= argv[0];
	local[6]= fqv[249];
	local[7]= local[1];
	local[8]= NIL;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON14794;
CON14840:
	local[5]= NIL;
CON14794:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF14853;
	local[5]= argv[0];
	local[6]= fqv[230];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[253];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[268];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF14854;
IF14853:
	local[5]= NIL;
IF14854:
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL14731;
WHX14732:
	local[5]= NIL;
BLK14733:
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK14694:
	ctx->vsp=local; return(local[0]);}

/*:while*/
static pointer M14910(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[0];
	local[3]= fqv[251];
	local[4]= fqv[281];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[251];
	local[5]= fqv[282];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[283];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[249];
	local[7]= local[0];
	local[8]= NIL;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[230];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[22];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[253];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[21]);
	local[6]= fqv[254];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[284];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[0]= w;
BLK14911:
	ctx->vsp=local; return(local[0]);}

/*:and*/
static pointer M15033(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[251];
	local[2]= fqv[285];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
WHL15063:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15064;
	local[1]= argv[0];
	local[2]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[178];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[243];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[22];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL15063;
WHX15064:
	local[1]= NIL;
BLK15065:
	local[1]= argv[0];
	local[2]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[254];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15034:
	ctx->vsp=local; return(local[0]);}

/*:or*/
static pointer M15153(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[251];
	local[2]= fqv[286];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
WHL15183:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15184;
	local[1]= argv[0];
	local[2]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[178];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[244];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[22];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL15183;
WHX15184:
	local[1]= NIL;
BLK15185:
	local[1]= argv[0];
	local[2]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[254];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15154:
	ctx->vsp=local; return(local[0]);}

/*:catch*/
static pointer M15273(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[251];
	local[2]= fqv[287];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[276];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[9] = cons(ctx,local[1],w);
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[288];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[230];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[289];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15274:
	ctx->vsp=local; return(local[0]);}

/*:throw*/
static pointer M15385(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[219];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK15386:
	ctx->vsp=local; return(local[0]);}

/*:unwind-protect*/
static pointer M15421(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[251];
	local[2]= fqv[290];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[276];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[9] = cons(ctx,local[2],w);
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[291];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[292];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[293];
	local[4]= local[0];
	local[5]= fqv[37];
	local[6]= NIL;
	w = argv[3];
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[294];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[295];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.cdr;
	w = local[2];
	local[0]= w;
BLK15422:
	ctx->vsp=local; return(local[0]);}

/*:enter-block*/
static pointer M15592(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[276];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[251];
	local[3]= fqv[296];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	w = argv[2];
	if (issymbol(w)) goto IF15630;
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[297];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF15631;
IF15630:
	local[2]= NIL;
IF15631:
	local[2]= argv[2];
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[4] = cons(ctx,local[2],w);
	w = local[1];
	local[0]= w;
BLK15593:
	ctx->vsp=local; return(local[0]);}

/*:leave-block*/
static pointer M15662(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[4] = (w)->c.cons.cdr;
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK15663:
	ctx->vsp=local; return(local[0]);}

/*:block*/
static pointer M15686(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[283];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[0];
	local[1]= fqv[230];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[21]);
	local[1]= fqv[254];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[284];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK15687:
	ctx->vsp=local; return(local[0]);}

/*:return-from*/
static pointer M15734(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF15771;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[298];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF15772;
IF15771:
	local[3]= NIL;
IF15772:
	local[3]= argv[0];
	local[4]= fqv[20];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF15791;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[299];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF15792;
IF15791:
	local[3]= NIL;
IF15792:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[51]); /*fourth*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[9];
	if (local[3]==NIL) goto AND15823;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	local[3]= w;
AND15823:
	local[1] = local[3];
	local[3]= loadglobal(fqv[21]);
	local[4]= fqv[215];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= loadglobal(fqv[21]);
	local[4]= fqv[253];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK15735:
	ctx->vsp=local; return(local[0]);}

/*:tagbody*/
static pointer M15861(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[276];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
WHL15905:
	if (local[2]==NIL) goto WHX15906;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w = local[3];
	if (!!iscons(w)) goto IF15914;
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= fqv[251];
	local[9]= fqv[300];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	argv[0]->c.obj.iv[5] = cons(ctx,local[6],w);
	local[6]= argv[0]->c.obj.iv[5];
	goto IF15915;
IF15914:
	local[6]= NIL;
IF15915:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	goto WHL15905;
WHX15906:
	local[6]= NIL;
BLK15907:
WHL15963:
	if (argv[2]==NIL) goto WHX15964;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[6];
	local[5] = w;
	w = local[5];
	if (!!iscons(w)) goto CON16014;
	local[6]= loadglobal(fqv[21]);
	local[7]= fqv[254];
	local[8]= local[5];
	local[9]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+10;
	w=(pointer)ASSQ(ctx,2,local+8); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON16012;
CON16014:
	local[6]= argv[0];
	local[7]= fqv[20];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= loadglobal(fqv[21]);
	local[7]= fqv[22];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON16012;
CON16034:
	local[6]= NIL;
CON16012:
	goto WHL15963;
WHX15964:
	local[6]= NIL;
BLK15965:
	local[6]= loadglobal(fqv[21]);
	local[7]= fqv[23];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	argv[0]->c.obj.iv[5] = local[0];
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK15862:
	ctx->vsp=local; return(local[0]);}

/*:go*/
static pointer M16065(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF16100;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[301];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF16101;
IF16100:
	local[3]= NIL;
IF16101:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= argv[0]->c.obj.iv[9];
	if (local[3]==NIL) goto AND16130;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	local[3]= w;
AND16130:
	local[2] = local[3];
	local[3]= loadglobal(fqv[21]);
	local[4]= fqv[302];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= loadglobal(fqv[21]);
	local[4]= fqv[253];
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK16066:
	ctx->vsp=local; return(local[0]);}

/*:function*/
static pointer M16164(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF16179;
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[43]!=local[1]) goto IF16201;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[50];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[51]); /*fourth*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF16202;
IF16201:
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[303];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF16202:
	w = local[1];
	local[0]= w;
	goto IF16180;
IF16179:
	local[0]= argv[0];
	local[1]= fqv[251];
	local[2]= fqv[304];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[291];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[292];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[293];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
IF16180:
	w = local[0];
	local[0]= w;
BLK16165:
	ctx->vsp=local; return(local[0]);}

/*:flet*/
static pointer M16289(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL16345:
	if (local[7]==NIL) goto WHX16346;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[0];
	local[9]= fqv[251];
	local[10]= fqv[305];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
	local[8]= loadglobal(fqv[21]);
	local[9]= fqv[291];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[43];
	local[10]= loadglobal(fqv[21]);
	local[11]= fqv[276];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= (pointer)((integer_t)(w)-4);
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,5,local+8); /*list*/
	local[8]= w;
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	argv[0]->c.obj.iv[8] = cons(ctx,local[8],w);
	local[8]= argv[0];
	local[9]= fqv[292];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[3] = w;
	local[8]= local[3];
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= argv[0];
	local[9]= fqv[293];
	local[10]= local[2];
	local[11]= fqv[37];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	goto WHL16345;
WHX16346:
	local[8]= NIL;
BLK16347:
	w = NIL;
	if (argv[4]==NIL) goto IF16488;
	local[6]= local[4];
	local[7]= fqv[306];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(*ftab[12])(ctx,3,local+6,&ftab[12],fqv[307]); /*send-all*/
	local[6]= w;
	goto IF16489;
IF16488:
	local[6]= NIL;
IF16489:
	local[6]= argv[0];
	local[7]= fqv[230];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[0]->c.obj.iv[8] = w;
	local[6]= loadglobal(fqv[21]);
	local[7]= fqv[79];
	local[8]= makeint(0);
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[0]= w;
BLK16290:
	ctx->vsp=local; return(local[0]);}

/*:change-flets*/
static pointer M16530(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[8] = argv[2];
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK16531:
	ctx->vsp=local; return(local[0]);}

/*:declare*/
static pointer M16552(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[2];
WHL16599:
	if (local[2]==NIL) goto WHX16600;
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
	if (fqv[39]!=local[4]) goto IF16665;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16694:
	if (local[5]==NIL) goto WHX16695;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[65];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= fqv[39];
	local[7]= local[6];
	w = local[0];
	w->c.obj.iv[2] = local[7];
	goto WHL16694;
WHX16695:
	local[6]= NIL;
BLK16696:
	w = NIL;
	local[4]= w;
	goto IF16666;
IF16665:
	local[4]= local[3];
	if (fqv[308]!=local[4]) goto IF16764;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16795:
	if (local[5]==NIL) goto WHX16796;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[65];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[94];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL16795;
WHX16796:
	local[6]= NIL;
BLK16797:
	w = NIL;
	local[4]= w;
	goto IF16765;
IF16764:
	local[4]= local[3];
	if (fqv[309]!=local[4]) goto IF16871;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)F6941(ctx,2,local+4); /*def-function-type*/
	local[4]= w;
	goto IF16872;
IF16871:
	local[4]= local[3];
	w = fqv[310];
	if (memq(local[4],w)==NIL) goto IF16895;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16927:
	if (local[5]==NIL) goto WHX16928;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[65];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[94];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL16927;
WHX16928:
	local[6]= NIL;
BLK16929:
	w = NIL;
	local[4]= w;
	goto IF16896;
IF16895:
	local[4]= local[3];
	if (fqv[311]!=local[4]) goto IF17001;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[312],local[4]);
	goto IF17002;
IF17001:
	local[4]= local[3];
	if (fqv[313]!=local[4]) goto IF17021;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[179],local[4]);
	goto IF17022;
IF17021:
	local[4]= local[3];
	if (fqv[314]!=local[4]) goto IF17040;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[315],local[4]);
	goto IF17041;
IF17040:
	local[4]= local[3];
	if (fqv[316]!=local[4]) goto IF17060;
	local[4]= NIL;
	goto IF17061;
IF17060:
	local[4]= local[3];
	if (fqv[317]!=local[4]) goto IF17068;
	local[4]= NIL;
	goto IF17069;
IF17068:
	if (T==NIL) goto IF17076;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6925(ctx,1,local+4); /*class-symbolp*/
	if (w==NIL) goto CON17083;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL17116:
	if (local[5]==NIL) goto WHX17117;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[65];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[94];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL17116;
WHX17117:
	local[6]= NIL;
BLK17118:
	w = NIL;
	local[4]= w;
	goto CON17081;
CON17083:
	local[4]= argv[0];
	local[5]= fqv[77];
	local[6]= fqv[318];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON17081;
CON17189:
	local[4]= NIL;
CON17081:
	goto IF17077;
IF17076:
	local[4]= NIL;
IF17077:
IF17069:
IF17061:
IF17041:
IF17022:
IF17002:
IF16896:
IF16872:
IF16765:
IF16666:
	w = local[4];
	goto WHL16599;
WHX16600:
	local[3]= NIL;
BLK16601:
	w = NIL;
	local[0]= w;
BLK16553:
	ctx->vsp=local; return(local[0]);}

/*:lambda*/
static pointer M17204(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= fqv[319];
	w = argv[2];
	local[5]= memq(local[5],w);
	local[6]= fqv[320];
	w = argv[2];
	local[6]= memq(local[6],w);
	local[7]= fqv[321];
	w = argv[2];
	local[7]= memq(local[7],w);
	local[8]= fqv[322];
	w = argv[2];
	local[8]= memq(local[8],w);
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= makeint(0);
	local[15]= NIL;
	local[16]= fqv[323];
	w = argv[2];
	local[16]= memq(local[16],w);
	local[17]= argv[0]->c.obj.iv[9];
	local[18]= NIL;
	local[19]= NIL;
	local[20]= local[5];
	if (local[20]!=NIL) goto CON17324;
CON17326:
	local[20]= local[6];
	if (local[20]!=NIL) goto CON17324;
CON17330:
	local[20]= local[7];
	if (local[20]!=NIL) goto CON17324;
CON17334:
	local[20]= local[8];
	if (local[20]!=NIL) goto CON17324;
CON17338:
	local[20]= NIL;
CON17324:
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[20]= w;
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)NTHCDR(ctx,2,local+20); /*nthcdr*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	local[10] = w;
	local[20]= local[6];
	if (local[20]!=NIL) goto CON17359;
CON17361:
	local[20]= local[7];
	if (local[20]!=NIL) goto CON17359;
CON17365:
	local[20]= local[8];
	if (local[20]!=NIL) goto CON17359;
CON17369:
	local[20]= NIL;
CON17359:
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[20]= w;
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)NTHCDR(ctx,2,local+20); /*nthcdr*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[6]==NIL) goto CON17387;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	goto CON17385;
CON17387:
	local[20]= NIL;
CON17385:
	local[6] = local[20];
	local[20]= local[10];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[2] = w;
	local[20]= local[5];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[3] = w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO17412,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[11] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[4] = w;
	if (local[16]==NIL) goto IF17434;
	local[20]= local[7];
	local[21]= makeint(0);
	local[4] = (pointer)((integer_t)(local[4])-4);
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)SUBSEQ(ctx,3,local+20); /*subseq*/
	local[7] = w;
	local[20]= local[7];
	goto IF17435;
IF17434:
	local[20]= NIL;
IF17435:
	if (local[5]==NIL) goto IF17462;
WHL17468:
	local[20]= local[1];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)LSEQP(ctx,2,local+20); /*<=*/
	if (w==NIL) goto WHX17469;
	local[20]= argv[0];
	local[21]= fqv[251];
	local[22]= fqv[324];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	w = local[0];
	ctx->vsp=local+21;
	local[0] = cons(ctx,local[20],w);
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL17468;
WHX17469:
	local[20]= NIL;
BLK17470:
	goto IF17463;
IF17462:
	if (local[6]==NIL) goto IF17503;
	local[20]= argv[0];
	local[21]= fqv[251];
	local[22]= fqv[325];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[0] = w;
	local[20]= local[0];
	goto IF17504;
IF17503:
	local[20]= NIL;
IF17504:
IF17463:
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO17525,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[5] = w;
	local[20]= argv[0];
	local[21]= fqv[74];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	if (local[7]==NIL) goto IF17540;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	local[23]= NIL;
	local[24]= local[7];
WHL17576:
	if (local[24]==NIL) goto WHX17577;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24] = (w)->c.cons.cdr;
	w = local[25];
	local[23] = w;
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)LISTP(ctx,1,local+25); /*listp*/
	if (w==NIL) goto CON17627;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23] = (w)->c.cons.car;
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)LISTP(ctx,1,local+25); /*listp*/
	if (w==NIL) goto CON17657;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.car;
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(*ftab[5])(ctx,1,local+25,&ftab[5],fqv[28]); /*keywordp*/
	if (w!=NIL) goto IF17685;
	local[25]= argv[0];
	local[26]= fqv[6];
	local[27]= fqv[326];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	goto IF17686;
IF17685:
	local[25]= NIL;
IF17686:
	if (local[22]==NIL) goto AND17701;
	w = local[22];
	if (!issymbol(w)) goto AND17701;
	goto IF17699;
AND17701:
	local[25]= argv[0];
	local[26]= fqv[6];
	local[27]= fqv[327];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	goto IF17700;
IF17699:
	local[25]= NIL;
IF17700:
	goto CON17655;
CON17657:
	local[22] = local[23];
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(*ftab[13])(ctx,1,local+25,&ftab[13],fqv[328]); /*symbol-name*/
	local[25]= w;
	local[26]= loadglobal(fqv[329]);
	ctx->vsp=local+27;
	w=(pointer)INTERN(ctx,2,local+25); /*intern*/
	local[21] = w;
	local[25]= local[21];
	goto CON17655;
CON17714:
	local[25]= NIL;
CON17655:
	goto CON17625;
CON17627:
	local[20] = NIL;
	local[22] = local[23];
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(*ftab[13])(ctx,1,local+25,&ftab[13],fqv[328]); /*symbol-name*/
	local[25]= w;
	local[26]= loadglobal(fqv[329]);
	ctx->vsp=local+27;
	w=(pointer)INTERN(ctx,2,local+25); /*intern*/
	local[21] = w;
	local[25]= local[21];
	goto CON17625;
CON17733:
	local[25]= NIL;
CON17625:
	local[25]= local[21];
	w = local[12];
	ctx->vsp=local+26;
	local[12] = cons(ctx,local[25],w);
	local[25]= local[22];
	w = local[9];
	ctx->vsp=local+26;
	local[9] = cons(ctx,local[25],w);
	local[25]= local[20];
	w = local[13];
	ctx->vsp=local+26;
	local[13] = cons(ctx,local[25],w);
	goto WHL17576;
WHX17577:
	local[25]= NIL;
BLK17578:
	w = NIL;
	local[23]= local[12];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[9];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[13];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[12];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	w = makeint(32);
	if ((integer_t)local[23] < (integer_t)w) goto IF17794;
	local[23]= argv[0];
	local[24]= fqv[6];
	local[25]= fqv[330];
	local[26]= local[12];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,4,local+23); /*send*/
	local[23]= w;
	goto IF17795;
IF17794:
	local[23]= NIL;
IF17795:
	w = local[23];
	local[20]= w;
	goto IF17541;
IF17540:
	local[20]= NIL;
IF17541:
WHL17810:
	if (argv[3]==NIL) goto WHX17811;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX17811;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	if (fqv[273]!=local[20]) goto WHX17811;
	local[20]= argv[0];
	local[21]= fqv[274];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[3] = (w)->c.cons.cdr;
	w = local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	goto WHL17810;
WHX17811:
	local[20]= NIL;
BLK17812:
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[331];
	local[22]= local[2];
	local[23]= local[3];
	if (local[6]==NIL) goto IF17889;
	local[24]= makeint(1);
	goto IF17890;
IF17889:
	if (local[7]==NIL) goto IF17895;
	local[24]= local[4];
	goto IF17896;
IF17895:
	local[24]= makeint(0);
IF17896:
IF17890:
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	local[1] = makeint(0);
	local[20]= NIL;
	local[21]= local[10];
WHL17928:
	if (local[21]==NIL) goto WHX17929;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= argv[0];
	local[23]= fqv[275];
	local[24]= local[20];
	local[25]= fqv[69];
	local[26]= local[1];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL17928;
WHX17929:
	local[22]= NIL;
BLK17930:
	w = NIL;
WHL18001:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX18002;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[332];
	local[22]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[20];
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[254];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[275];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	local[23]= fqv[67];
	local[24]= loadglobal(fqv[21]);
	local[25]= fqv[276];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= (pointer)((integer_t)(w)-4);
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL18001;
WHX18002:
	local[20]= NIL;
BLK18003:
	if (local[0]==NIL) goto IF18170;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[254];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	goto IF18171;
IF18170:
	local[20]= NIL;
IF18171:
	if (local[6]==NIL) goto CON18222;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[333];
	local[22]= local[2];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,2,local+22); /*+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[275];
	local[22]= local[6];
	local[23]= fqv[67];
	local[24]= loadglobal(fqv[21]);
	local[25]= fqv[276];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= (pointer)((integer_t)(w)-4);
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	local[20]= w;
	goto CON18220;
CON18222:
	local[20]= local[3];
	local[21]= makeint(0);
	ctx->vsp=local+22;
	w=(pointer)GREATERP(ctx,2,local+20); /*>*/
	if (w==NIL) goto CON18253;
	if (local[7]!=NIL) goto CON18253;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[334];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	goto CON18220;
CON18253:
	local[20]= NIL;
CON18220:
	if (local[7]==NIL) goto IF18271;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[276];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[14] = w;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[335];
	local[22]= local[12];
	local[23]= loadglobal(fqv[176]);
	ctx->vsp=local+24;
	w=(pointer)COERCE(ctx,2,local+22); /*coerce*/
	local[22]= w;
	local[23]= local[2];
	local[24]= local[3];
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	local[24]= local[4];
	local[25]= local[16];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,6,local+20); /*send*/
	local[20]= makeint(0);
	local[21]= local[4];
WHL18330:
	local[22]= local[20];
	w = local[21];
	if ((integer_t)local[22] >= (integer_t)w) goto WHX18331;
	local[22]= argv[0];
	local[23]= fqv[251];
	local[24]= fqv[336];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[0] = w;
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[337];
	local[24]= local[20];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= argv[0];
	local[23]= fqv[20];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[24];
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[22];
	local[18] = w;
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[18];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	if (w==NIL) goto CON18442;
	local[22]= argv[0];
	local[23]= fqv[251];
	local[24]= fqv[338];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[19] = w;
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[253];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[254];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[268];
	local[24]= makeint(1);
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[50];
	local[24]= local[20];
	local[25]= local[14];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= makeint(0);
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[254];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= argv[0];
	local[23]= fqv[275];
	local[24]= local[18];
	local[25]= fqv[67];
	local[26]= local[14];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	local[27]= T;
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,6,local+22); /*send*/
	local[22]= w;
	goto CON18440;
CON18442:
	local[22]= argv[0];
	local[23]= fqv[275];
	local[24]= local[18];
	local[25]= fqv[67];
	local[26]= local[14];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[101];
	local[24]= local[14];
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= makeint(0);
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[254];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	goto CON18440;
CON18512:
	local[22]= NIL;
CON18440:
	local[20] = (pointer)((integer_t)(local[20])+4);
	goto WHL18330;
WHX18331:
	local[22]= NIL;
BLK18332:
	w = NIL;
	local[20]= w;
	goto IF18272;
IF18271:
	local[20]= NIL;
IF18272:
	local[20]= NIL;
	local[21]= local[8];
WHL18576:
	if (local[21]==NIL) goto WHX18577;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	w = local[20];
	if (!iscons(w)) goto IF18625;
	local[22]= argv[0];
	local[23]= fqv[20];
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	goto IF18626;
IF18625:
	local[22]= argv[0];
	local[23]= fqv[20];
	local[24]= NIL;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
IF18626:
	local[22]= argv[0];
	local[23]= fqv[275];
	local[24]= local[20];
	ctx->vsp=local+25;
	w=(pointer)LISTP(ctx,1,local+24); /*listp*/
	if (w==NIL) goto IF18653;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	goto IF18654;
IF18653:
	local[24]= local[20];
IF18654:
	local[25]= fqv[67];
	local[26]= loadglobal(fqv[21]);
	local[27]= fqv[276];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= (pointer)((integer_t)(w)-4);
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	goto WHL18576;
WHX18577:
	local[22]= NIL;
BLK18578:
	w = NIL;
	local[20]= argv[0];
	local[21]= fqv[230];
	local[22]= argv[3];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	argv[0]->c.obj.iv[9] = local[17];
	local[20]= argv[0];
	local[21]= fqv[277];
	local[22]= T;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[0]= w;
BLK17205:
	ctx->vsp=local; return(local[0]);}

/*:lambda-block*/
static pointer M18702(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	ctx->vsp=local+0;
	w=(pointer)RUNTIME(ctx,0,local+0); /*unix:runtime*/
	local[0]= w;
	local[1]= NIL;
	if (loadglobal(fqv[339])==NIL) goto IF18737;
	local[2]= T;
	local[3]= fqv[340];
	local[4]= makeint(27);
	local[5]= argv[2];
	local[6]= makeint(27);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,5,local+2); /*format*/
	local[2]= w;
	goto IF18738;
IF18737:
	local[2]= NIL;
IF18738:
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,0,local+2); /*finish-output*/
	local[2]= argv[0];
	local[3]= fqv[283];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[1] = w;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[17];
	local[4]= argv[5];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[341];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[254];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[342];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[284];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (loadglobal(fqv[339])==NIL) goto IF18798;
	local[2]= T;
	local[3]= fqv[343];
	local[4]= makeflt(1.66699961e-02);
	ctx->vsp=local+5;
	w=(pointer)RUNTIME(ctx,0,local+5); /*unix:runtime*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF18799;
IF18798:
	local[2]= NIL;
IF18799:
	w = argv[5];
	local[0]= w;
BLK18703:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO17412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF18828;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF18829;
IF18828:
	local[0]= NIL;
IF18829:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO17525(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF18853;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF18854;
IF18853:
	local[0]= argv[0];
IF18854:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:def-user-entry*/
static pointer M18893(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[344]!=local[0]) goto IF18908;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= fqv[251];
	local[3]= fqv[345];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= fqv[346];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= local[0];
	w = loadglobal(fqv[347]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[347],local[2]);
	w = local[2];
	local[0]= w;
	goto IF18909;
IF18908:
	local[0]= NIL;
IF18909:
	w = local[0];
	local[0]= w;
BLK18894:
	ctx->vsp=local; return(local[0]);}

/*:defun*/
static pointer M18964(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[3];
	local[1]= fqv[346];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	local[1]= NIL;
	if (local[0]!=NIL) goto IF19002;
	local[2]= argv[0];
	local[3]= fqv[251];
	local[4]= fqv[348];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[0];
	goto IF19003;
IF19002:
	local[2]= NIL;
IF19003:
	local[2]= loadglobal(fqv[312]);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF19020;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= fqv[346];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= argv[3];
	w = loadglobal(fqv[347]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[347],local[2]);
	goto IF19021;
IF19020:
	local[2]= NIL;
IF19021:
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF19049;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF19049;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[5] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	goto IF19050;
IF19049:
	local[2]= NIL;
	local[3]= fqv[349];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
IF19050:
	local[1] = local[2];
	local[2]= argv[0];
	local[3]= fqv[350];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[351];
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK18965:
	ctx->vsp=local; return(local[0]);}

/*:defmethod*/
static pointer M19130(ctx,n,argv,env)
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
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)F6933(ctx,1,local+7); /*object-variable-names*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= NIL;
	local[10]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[11]= argv[0];
	local[12]= fqv[74];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= NIL;
	local[12]= local[7];
WHL19215:
	if (local[12]==NIL) goto WHX19216;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= argv[0];
	local[14]= fqv[65];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[9] = w;
	local[13]= fqv[352];
	*(ovafptr(local[9],fqv[84])) = local[13];
	local[13]= local[8];
	*(ovafptr(local[9],fqv[88])) = local[13];
	local[13]= argv[0]->c.obj.iv[1];
	*(ovafptr(local[9],fqv[89])) = local[13];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)SYMVALUE(ctx,1,local+13); /*symbol-value*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)F6935(ctx,2,local+13); /*object-variable-type*/
	local[13]= w;
	local[14]= w;
	*(ovafptr(local[9],fqv[308])) = local[14];
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL19215;
WHX19216:
	local[13]= NIL;
BLK19217:
	w = NIL;
WHL19307:
	if (argv[2]==NIL) goto WHX19308;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[11];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[11]= fqv[353];
	local[12]= fqv[354];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[11]= argv[0];
	local[12]= fqv[251];
	local[13]= fqv[355];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[4] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF19404;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF19404;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	goto IF19405;
IF19404:
	local[11]= NIL;
	local[12]= fqv[356];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
IF19405:
	local[10] = local[11];
	local[11]= argv[0];
	local[12]= fqv[350];
	local[13]= local[1];
	local[14]= local[2];
	local[15]= local[3];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,6,local+11); /*send*/
	local[11]= argv[0];
	local[12]= fqv[351];
	local[13]= fqv[357];
	local[14]= local[6];
	local[15]= local[1];
	local[16]= local[4];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,5,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	goto WHL19307;
WHX19308:
	local[11]= NIL;
BLK19309:
	local[6] = NIL;
	local[11]= argv[0];
	local[12]= fqv[277];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[0]= w;
BLK19131:
	ctx->vsp=local; return(local[0]);}

/*:add-initcode*/
static pointer M19526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[7];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[7] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK19527:
	ctx->vsp=local; return(local[0]);}

/*:add-closure*/
static pointer M19552(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[6];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[6] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK19553:
	ctx->vsp=local; return(local[0]);}

/*:closure-level*/
static pointer M19578(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK19579:
	ctx->vsp=local; return(local[0]);}

/*:compile-a-closure*/
static pointer M19604(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[49])==NIL) goto IF19621;
	local[0]= T;
	local[1]= fqv[358];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF19622;
IF19621:
	local[0]= NIL;
IF19622:
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	argv[0]->c.obj.iv[6] = NIL;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[359];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[17];
	local[4]= argv[2];
	local[5]= fqv[360];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[341];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[342];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[361];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0]= w;
BLK19605:
	ctx->vsp=local; return(local[0]);}

/*:compile-closures*/
static pointer M19695(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)REVERSE(ctx,1,local+1); /*reverse*/
	local[1]= w;
WHL19727:
	if (local[1]==NIL) goto WHX19728;
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[362];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL19727;
WHX19728:
	local[2]= NIL;
BLK19729:
	w = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK19696:
	ctx->vsp=local; return(local[0]);}

/*:toplevel-eval*/
static pointer M19811(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[6] = NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	local[2]= local[1];
	w = fqv[363];
	if (memq(local[2],w)==NIL) goto IF19858;
	local[2]= argv[0];
	local[3]= fqv[364];
	local[4]= local[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[14])(ctx,1,local+7,&ftab[14],fqv[365]); /*cdddr*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[361];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF19859;
IF19858:
	local[2]= local[1];
	w = fqv[366];
	if (memq(local[2],w)==NIL) goto IF19904;
	local[2]= argv[0];
	local[3]= fqv[367];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[361];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF19905;
IF19904:
	local[2]= local[1];
	w = fqv[368];
	if (memq(local[2],w)==NIL) goto IF19934;
	local[2]= NIL;
	goto IF19935;
IF19934:
	if (T==NIL) goto IF19945;
	local[2]= argv[0];
	local[3]= fqv[351];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF19946;
IF19945:
	local[2]= NIL;
IF19946:
IF19935:
IF19905:
IF19859:
	w = local[2];
	local[0]= w;
BLK19812:
	ctx->vsp=local; return(local[0]);}

/*:toplevel*/
static pointer M19958(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT19962;}
	local[0]= NIL;
ENT19962:
ENT19961:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF19982;
	local[1]= loadglobal(fqv[21]);
	local[2]= fqv[55];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF19983;
IF19982:
	local[1]= NIL;
IF19983:
	w = argv[2];
	if (!!iscons(w)) goto IF19994;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK19959;
	goto IF19995;
IF19994:
	local[1]= NIL;
IF19995:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,1,local+1,&ftab[15],fqv[369]); /*macro-function*/
	if (w==NIL) goto IF20004;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[42]); /*macroexpand*/
	argv[2] = w;
	local[1]= argv[2];
	goto IF20005;
IF20004:
	local[1]= NIL;
IF20005:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[370]!=local[1]) goto CON20028;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
WHL20080:
	if (local[3]==NIL) goto WHX20081;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[371];
	w = local[1];
	if (memq(local[4],w)==NIL) goto IF20130;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	goto IF20131;
IF20130:
	local[4]= NIL;
IF20131:
	local[4]= fqv[372];
	w = local[1];
	if (memq(local[4],w)==NIL) goto IF20149;
	local[4]= argv[0];
	local[5]= fqv[373];
	local[6]= local[2];
	local[7]= NIL;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF20150;
IF20149:
	local[4]= NIL;
IF20150:
	goto WHL20080;
WHX20081:
	local[4]= NIL;
BLK20082:
	w = NIL;
	local[1]= w;
	goto CON20026;
CON20028:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[374]!=local[1]) goto CON20173;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
WHL20221:
	if (argv[2]==NIL) goto WHX20222;
	local[1]= argv[0];
	local[2]= fqv[373];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= argv[3];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	goto WHL20221;
WHX20222:
	local[1]= NIL;
BLK20223:
	goto CON20026;
CON20173:
	if (argv[3]==NIL) goto IF20274;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EVAL(ctx,1,local+1); /*eval*/
	local[1]= w;
	goto IF20275;
IF20274:
	local[1]= NIL;
IF20275:
	if (local[0]==NIL) goto IF20284;
	local[1]= argv[0];
	local[2]= fqv[375];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF20285;
IF20284:
	local[1]= argv[0];
	local[2]= fqv[376];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF20285:
	goto CON20026;
CON20270:
	local[1]= NIL;
CON20026:
	w = local[1];
	local[0]= w;
BLK19959:
	ctx->vsp=local; return(local[0]);}

/*:toplevel-execution*/
static pointer M20302(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	local[2]= local[1];
	if (fqv[344]!=local[2]) goto IF20343;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[364];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[51]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	goto IF20344;
IF20343:
	local[2]= local[1];
	if (fqv[377]!=local[2]) goto IF20375;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[378];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[51]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	goto IF20376;
IF20375:
	local[2]= local[1];
	if (fqv[357]!=local[2]) goto IF20407;
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[367];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[51]); /*fourth*/
	local[6]= w;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[52]); /*fifth*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= w;
	goto IF20408;
IF20407:
	if (T==NIL) goto IF20442;
	local[2]= argv[0];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[21]);
	local[3]= fqv[22];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF20443;
IF20442:
	local[2]= NIL;
IF20443:
IF20408:
IF20376:
IF20344:
	w = local[2];
	local[0]= w;
BLK20303:
	ctx->vsp=local; return(local[0]);}

/*:compile-file*/
static pointer M20464(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[379], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY20486;
	local[0] = fqv[380];
KEY20486:
	if (n & (1<<1)) goto KEY20491;
	local[1] = loadglobal(fqv[312]);
KEY20491:
	if (n & (1<<2)) goto KEY20497;
	local[2] = makeint(1);
KEY20497:
	if (n & (1<<3)) goto KEY20502;
	local[3] = loadglobal(fqv[179]);
KEY20502:
	if (n & (1<<4)) goto KEY20508;
	local[4] = loadglobal(fqv[381]);
KEY20508:
	if (n & (1<<5)) goto KEY20515;
	local[5] = loadglobal(fqv[382]);
KEY20515:
	if (n & (1<<6)) goto KEY20522;
	local[6] = loadglobal(fqv[339]);
KEY20522:
	if (n & (1<<7)) goto KEY20528;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,1,local+9,&ftab[16],fqv[383]); /*pathname-name*/
	local[7] = w;
KEY20528:
	if (n & (1<<8)) goto KEY20537;
	local[8] = NIL;
KEY20537:
	w = local[2];
	if (!isint(w)) goto IF20546;
	local[9]= local[2];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF20546;
	local[9]= NIL;
	local[10]= fqv[384];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,2,local+9); /*format*/
	local[9]= w;
	storeglobal(fqv[385],w);
	goto IF20547;
IF20546:
	local[9]= fqv[386];
	storeglobal(fqv[385],local[9]);
IF20547:
	storeglobal(fqv[312],local[1]);
	storeglobal(fqv[179],local[3]);
	local[9]= local[6];
	storeglobal(fqv[339],local[9]);
	if (local[8]==NIL) goto IF20581;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,1,local+9,&ftab[17],fqv[387]); /*pathname*/
	local[8] = w;
	local[9]= local[8];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[18])(ctx,2,local+9,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[8] = w;
	local[9]= fqv[389];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[18])(ctx,2,local+9,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[8] = w;
	local[9]= local[8];
	goto IF20582;
IF20581:
	local[9]= NIL;
IF20582:
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= fqv[390];
	local[15]= argv[2];
	ctx->vsp=local+16;
	w=(*ftab[18])(ctx,2,local+14,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[14]= w;
	local[15]= fqv[391];
	local[16]= argv[2];
	ctx->vsp=local+17;
	w=(*ftab[18])(ctx,2,local+15,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[15]= w;
	local[16]= fqv[392];
	local[17]= argv[2];
	ctx->vsp=local+18;
	w=(*ftab[18])(ctx,2,local+16,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[16]= w;
	if (local[8]==NIL) goto IF20660;
	local[17]= local[8];
	goto IF20661;
IF20660:
	local[17]= fqv[393];
	local[18]= argv[2];
	ctx->vsp=local+19;
	w=(*ftab[18])(ctx,2,local+17,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[17]= w;
IF20661:
	if (local[8]==NIL) goto IF20673;
	local[18]= fqv[394];
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(*ftab[18])(ctx,2,local+18,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[18]= w;
	goto IF20674;
IF20673:
	local[18]= fqv[395];
	local[19]= argv[2];
	ctx->vsp=local+20;
	w=(*ftab[18])(ctx,2,local+18,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[18]= w;
IF20674:
	local[19]= loadglobal(fqv[396]);
	local[20]= argv[2];
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,1,local+20,&ftab[19],fqv[397]); /*probe-file*/
	if (w!=NIL) goto IF20694;
	local[20]= fqv[398];
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[18])(ctx,2,local+20,&ftab[18],fqv[388]); /*merge-pathnames*/
	argv[2] = w;
	local[20]= argv[2];
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,1,local+20,&ftab[19],fqv[397]); /*probe-file*/
	if (w!=NIL) goto IF20715;
	local[20]= fqv[399];
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,2,local+20); /*error*/
	local[20]= w;
	goto IF20716;
IF20715:
	local[20]= NIL;
IF20716:
	goto IF20695;
IF20694:
	local[20]= NIL;
IF20695:
	local[20]= fqv[400];
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[20])(ctx,1,local+21,&ftab[20],fqv[401]); /*namestring*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[1])(ctx,2,local+20,&ftab[1],fqv[14]); /*warn*/
	local[20]= argv[2];
	ctx->vsp=local+21;
	w=(*ftab[21])(ctx,1,local+20,&ftab[21],fqv[402]); /*open*/
	local[12] = w;
	local[20]= NIL;
	storeglobal(fqv[347],local[20]);
	if (loadglobal(fqv[403])==NIL) goto IF20750;
WHL20760:
	if (T==NIL) goto WHX20761;
	local[20]= local[12];
	local[21]= NIL;
	local[22]= fqv[404];
	ctx->vsp=local+23;
	w=(pointer)READ(ctx,3,local+20); /*read*/
	local[11] = w;
	local[20]= local[11];
	if (fqv[404]!=local[20]) goto IF20778;
	w = NIL;
	ctx->vsp=local+20;
	local[20]=w;
	goto BLK20762;
	goto IF20779;
IF20778:
	local[20]= NIL;
IF20779:
	local[20]= argv[0];
	local[21]= fqv[373];
	local[22]= local[11];
	local[23]= T;
	local[24]= T;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	goto WHL20760;
WHX20761:
	local[20]= NIL;
BLK20762:
	local[20]= local[12];
	local[21]= makeint(0);
	ctx->vsp=local+22;
	w=(pointer)LSEEK(ctx,2,local+20); /*unix:lseek*/
	local[20]= w;
	goto IF20751;
IF20750:
	local[20]= NIL;
IF20751:
	local[20]= loadglobal(fqv[347]);
	ctx->vsp=local+21;
	w=(pointer)NREVERSE(ctx,1,local+20); /*nreverse*/
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[405];
	local[22]= argv[2];
	local[23]= local[14];
	local[24]= local[15];
	local[25]= local[7];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,6,local+20); /*send*/
	local[20]= argv[0]->c.obj.iv[0];
	local[21]= fqv[406];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	argv[0]->c.obj.iv[3] = NIL;
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[4] = NIL;
	argv[0]->c.obj.iv[7] = NIL;
WHL20834:
	if (T==NIL) goto WHX20835;
	local[20]= local[12];
	local[21]= NIL;
	local[22]= fqv[404];
	ctx->vsp=local+23;
	w=(pointer)READ(ctx,3,local+20); /*read*/
	local[11] = w;
	local[20]= local[11];
	if (fqv[404]!=local[20]) goto IF20852;
	w = NIL;
	ctx->vsp=local+20;
	local[20]=w;
	goto BLK20836;
	goto IF20853;
IF20852:
	local[20]= NIL;
IF20853:
	local[20]= argv[0];
	local[21]= fqv[373];
	local[22]= local[11];
	local[23]= T;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	goto WHL20834;
WHX20835:
	local[20]= NIL;
BLK20836:
	local[20]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	argv[0]->c.obj.iv[7] = w;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[407];
	local[22]= local[7];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= NIL;
	local[21]= argv[0]->c.obj.iv[7];
WHL20905:
	if (local[21]==NIL) goto WHX20906;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= argv[0];
	local[23]= fqv[408];
	local[24]= local[20];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	goto WHL20905;
WHX20906:
	local[22]= NIL;
BLK20907:
	w = NIL;
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[23];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[342];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[361];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[409];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[410];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= *(ovafptr(local[19],fqv[411]));
	local[21]= *(ovafptr(local[19],fqv[412]));
	local[22]= makeint(0);
	ctx->vsp=local+23;
	w=(*ftab[2])(ctx,1,local+22,&ftab[2],fqv[18]); /*make-array*/
	local[22]= w;
	*(ovafptr(local[19],fqv[411])) = local[22];
	local[22]= makeint(1);
	local[23]= local[22];
	*(ovafptr(local[19],fqv[412])) = local[23];
	local[22]= loadglobal(fqv[21]);
	local[23]= fqv[413];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= local[20];
	*(ovafptr(local[19],fqv[411])) = local[22];
	local[22]= local[21];
	local[23]= local[22];
	*(ovafptr(local[19],fqv[412])) = local[23];
	w = local[22];
	local[20]= loadglobal(fqv[21]);
	local[21]= fqv[414];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(pointer)CLOSE(ctx,1,local+20); /*close*/
	local[20]= loadglobal(fqv[19]);
	local[21]= loadglobal(fqv[415]);
	local[22]= fqv[416];
	if (local[8]==NIL) goto IF21052;
	local[23]= loadglobal(fqv[19]);
	local[24]= fqv[417];
	local[25]= local[8];
	ctx->vsp=local+26;
	w=(*ftab[20])(ctx,1,local+25,&ftab[20],fqv[401]); /*namestring*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)CONCATENATE(ctx,3,local+23); /*concatenate*/
	local[23]= w;
	goto IF21053;
IF21052:
	local[23]= NIL;
IF21053:
	local[24]= fqv[418];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21066;
	local[24]= fqv[420];
	goto CON21064;
CON21066:
	local[24]= fqv[421];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21077;
	local[24]= fqv[422];
	goto CON21064;
CON21077:
	local[24]= fqv[423];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21087;
	local[24]= fqv[424];
	goto CON21064;
CON21087:
	local[24]= fqv[425];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21097;
	local[24]= fqv[426];
	goto CON21064;
CON21097:
	local[24]= fqv[427];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21107;
	local[24]= fqv[428];
	goto CON21064;
CON21107:
	local[24]= fqv[429];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21117;
	local[24]= fqv[430];
	goto CON21064;
CON21117:
	local[24]= fqv[431];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21127;
	local[24]= fqv[432];
	goto CON21064;
CON21127:
	local[24]= fqv[433];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21137;
	local[24]= fqv[434];
	goto CON21064;
CON21137:
	local[24]= fqv[435];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21147;
	local[24]= fqv[436];
	goto CON21064;
CON21147:
	local[24]= fqv[437];
	w = loadglobal(fqv[419]);
	if (memq(local[24],w)==NIL) goto CON21157;
	local[24]= fqv[438];
	goto CON21064;
CON21157:
	local[24]= fqv[439];
	ctx->vsp=local+25;
	w=(*ftab[1])(ctx,1,local+24,&ftab[1],fqv[14]); /*warn*/
	local[24]= w;
	goto CON21064;
CON21167:
	local[24]= NIL;
CON21064:
	local[25]= fqv[440];
	w = loadglobal(fqv[419]);
	if (memq(local[25],w)==NIL) goto CON21175;
	local[25]= fqv[441];
	goto CON21173;
CON21175:
	local[25]= fqv[442];
	w = loadglobal(fqv[419]);
	if (memq(local[25],w)==NIL) goto CON21185;
	local[25]= fqv[443];
	goto CON21173;
CON21185:
	local[25]= fqv[444];
	w = loadglobal(fqv[419]);
	if (memq(local[25],w)==NIL) goto CON21195;
	local[25]= fqv[445];
	goto CON21173;
CON21195:
	local[25]= fqv[446];
	goto CON21173;
CON21205:
	local[25]= NIL;
CON21173:
	local[26]= fqv[447];
	w = loadglobal(fqv[419]);
	if (memq(local[26],w)==NIL) goto IF21209;
	local[26]= fqv[448];
	goto IF21210;
IF21209:
	local[26]= NIL;
IF21210:
	local[27]= fqv[449];
	w = loadglobal(fqv[419]);
	if (memq(local[27],w)==NIL) goto IF21220;
	local[27]= fqv[450];
	goto IF21221;
IF21220:
	local[27]= NIL;
IF21221:
	local[28]= fqv[451];
	w = loadglobal(fqv[419]);
	if (memq(local[28],w)==NIL) goto IF21231;
	local[28]= fqv[452];
	goto IF21232;
IF21231:
	local[28]= NIL;
IF21232:
	if (local[5]==NIL) goto IF21242;
	local[29]= fqv[442];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21250;
	local[29]= fqv[453];
	goto CON21248;
CON21250:
	local[29]= fqv[447];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21260;
	local[29]= fqv[454];
	goto CON21248;
CON21260:
	local[29]= fqv[444];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21270;
	local[29]= fqv[455];
	goto CON21248;
CON21270:
	local[29]= fqv[433];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21280;
	local[29]= fqv[456];
	goto CON21248;
CON21280:
	local[29]= fqv[423];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21290;
	local[29]= fqv[457];
	goto CON21248;
CON21290:
	local[29]= fqv[425];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21300;
	local[29]= fqv[458];
	goto CON21248;
CON21300:
	local[29]= fqv[435];
	w = loadglobal(fqv[419]);
	if (memq(local[29],w)==NIL) goto CON21310;
	local[29]= fqv[459];
	goto CON21248;
CON21310:
	local[29]= fqv[460];
	goto CON21248;
CON21320:
	local[29]= NIL;
CON21248:
	goto IF21243;
IF21242:
	local[29]= NIL;
IF21243:
	local[30]= local[0];
	local[31]= fqv[461];
	local[32]= loadglobal(fqv[462]);
	ctx->vsp=local+33;
	w=(*ftab[20])(ctx,1,local+32,&ftab[20],fqv[401]); /*namestring*/
	local[32]= w;
	local[33]= fqv[463];
	local[34]= loadglobal(fqv[385]);
	local[35]= loadglobal(fqv[464]);
	local[36]= fqv[465];
	local[37]= local[14];
	ctx->vsp=local+38;
	w=(*ftab[20])(ctx,1,local+37,&ftab[20],fqv[401]); /*namestring*/
	local[37]= w;
	local[38]= fqv[442];
	w = loadglobal(fqv[419]);
	if (memq(local[38],w)==NIL) goto IF21335;
	if (local[5]==NIL) goto IF21335;
	local[38]= loadglobal(fqv[19]);
	local[39]= fqv[466];
	local[40]= local[18];
	ctx->vsp=local+41;
	w=(*ftab[20])(ctx,1,local+40,&ftab[20],fqv[401]); /*namestring*/
	local[40]= w;
	local[41]= fqv[467];
	local[42]= local[17];
	ctx->vsp=local+43;
	w=(*ftab[20])(ctx,1,local+42,&ftab[20],fqv[401]); /*namestring*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(pointer)CONCATENATE(ctx,5,local+38); /*concatenate*/
	local[38]= w;
	goto IF21336;
IF21335:
	local[38]= NIL;
IF21336:
	local[39]= fqv[423];
	w = loadglobal(fqv[419]);
	if (memq(local[39],w)!=NIL) goto OR21362;
	local[39]= fqv[425];
	w = loadglobal(fqv[419]);
	if (memq(local[39],w)!=NIL) goto OR21362;
	goto IF21359;
OR21362:
	if (local[5]==NIL) goto IF21359;
	local[39]= loadglobal(fqv[19]);
	local[40]= fqv[468];
	local[41]= local[18];
	ctx->vsp=local+42;
	w=(*ftab[20])(ctx,1,local+41,&ftab[20],fqv[401]); /*namestring*/
	local[41]= w;
	local[42]= fqv[469];
	local[43]= local[17];
	ctx->vsp=local+44;
	w=(*ftab[20])(ctx,1,local+43,&ftab[20],fqv[401]); /*namestring*/
	local[43]= w;
	ctx->vsp=local+44;
	w=(pointer)CONCATENATE(ctx,5,local+39); /*concatenate*/
	local[39]= w;
	goto IF21360;
IF21359:
	local[39]= NIL;
IF21360:
	local[40]= fqv[433];
	w = loadglobal(fqv[419]);
	if (memq(local[40],w)==NIL) goto IF21393;
	if (local[5]==NIL) goto IF21393;
	local[40]= loadglobal(fqv[19]);
	local[41]= fqv[470];
	local[42]= local[18];
	ctx->vsp=local+43;
	w=(*ftab[20])(ctx,1,local+42,&ftab[20],fqv[401]); /*namestring*/
	local[42]= w;
	local[43]= fqv[471];
	local[44]= local[17];
	ctx->vsp=local+45;
	w=(*ftab[20])(ctx,1,local+44,&ftab[20],fqv[401]); /*namestring*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)CONCATENATE(ctx,5,local+40); /*concatenate*/
	local[40]= w;
	goto IF21394;
IF21393:
	local[40]= fqv[472];
IF21394:
	local[41]= fqv[435];
	w = loadglobal(fqv[419]);
	if (memq(local[41],w)==NIL) goto IF21417;
	if (local[5]==NIL) goto IF21417;
	local[41]= loadglobal(fqv[19]);
	local[42]= fqv[473];
	local[43]= local[18];
	ctx->vsp=local+44;
	w=(*ftab[20])(ctx,1,local+43,&ftab[20],fqv[401]); /*namestring*/
	local[43]= w;
	local[44]= fqv[474];
	local[45]= local[17];
	ctx->vsp=local+46;
	w=(*ftab[20])(ctx,1,local+45,&ftab[20],fqv[401]); /*namestring*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)CONCATENATE(ctx,5,local+41); /*concatenate*/
	local[41]= w;
	goto IF21418;
IF21417:
	local[41]= fqv[475];
IF21418:
	ctx->vsp=local+42;
	w=(pointer)CONCATENATE(ctx,22,local+20); /*concatenate*/
	local[13] = w;
	if (local[4]==NIL) goto IF21447;
	local[20]= fqv[476];
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(*ftab[1])(ctx,2,local+20,&ftab[1],fqv[14]); /*warn*/
	local[20]= local[13];
	ctx->vsp=local+21;
	w=(pointer)SYSTEM(ctx,1,local+20); /*unix:system*/
	local[20]= w;
	goto IF21448;
IF21447:
	local[20]= NIL;
IF21448:
	local[20]= NIL;
	local[21]= loadglobal(fqv[347]);
WHL21481:
	if (local[21]==NIL) goto WHX21482;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= fqv[346];
	ctx->vsp=local+24;
	w=(*ftab[22])(ctx,2,local+22,&ftab[22],fqv[477]); /*remprop*/
	goto WHL21481;
WHX21482:
	local[22]= NIL;
BLK21483:
	w = NIL;
	local[20]= loadglobal(fqv[478]);
	ctx->vsp=local+21;
	w=(pointer)TERPRI(ctx,1,local+20); /*terpri*/
	local[0]= w;
BLK20465:
	ctx->vsp=local; return(local[0]);}

/*:specials*/
static pointer M21545(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[479];
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[480];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK21546:
	ctx->vsp=local; return(local[0]);}

/*:copy-compiler*/
static pointer M21567(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[6];
	argv[0]->c.obj.iv[7] = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[0] = w;
	local[3]= local[0];
	local[4]= fqv[481];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[7] = local[1];
	argv[0]->c.obj.iv[6] = local[2];
	w = local[0];
	local[0]= w;
BLK21568:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M21634(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[482]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	storeglobal(fqv[21],w);
	local[0]= loadglobal(fqv[483]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[55];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[0] = w;
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK21635:
	ctx->vsp=local; return(local[0]);}

/*dump-function*/
static pointer F6996(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST21701:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= fqv[484];
	local[3]= fqv[485];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,3,local+1,&ftab[21],fqv[402]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP21730,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= NIL;
	local[5]= local[0];
WHL21754:
	if (local[5]==NIL) goto WHX21755;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)SYMFUNC(ctx,1,local+6); /*symbol-function*/
	local[6]= w;
	local[7]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[8];
	if (fqv[37]!=local[9]) goto IF21837;
	local[9]= fqv[344];
	local[10]= local[4];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	goto IF21838;
IF21837:
	local[9]= local[8];
	if (fqv[41]!=local[9]) goto IF21859;
	local[9]= fqv[344];
	local[10]= local[4];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	goto IF21860;
IF21859:
	local[9]= NIL;
IF21860:
IF21838:
	w = local[9];
	local[7] = w;
	local[8]= local[7];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[23])(ctx,2,local+8,&ftab[23],fqv[486]); /*pprint*/
	goto WHL21754;
WHX21755:
	local[6]= NIL;
BLK21756:
	w = NIL;
	ctx->vsp=local+4;
	UWP21730(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK21699:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP21730(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*comfile*/
static pointer F6998(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST21912:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= local[0];
WHL21938:
	if (local[2]==NIL) goto WHX21939;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[487];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	goto WHL21938;
WHX21939:
	local[3]= NIL;
BLK21940:
	w = NIL;
	local[0]= w;
BLK21910:
	ctx->vsp=local; return(local[0]);}

/*compile-file*/
static pointer F7000(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST22000:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[488]);
	local[2]= loadglobal(fqv[5]);
	local[3]= fqv[487];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK21998:
	ctx->vsp=local; return(local[0]);}

/*compile*/
static pointer F7002(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22025:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= fqv[489];
	ctx->vsp=local+3;
	w=(pointer)GETPID(ctx,0,local+3); /*unix:getpid*/
	local[3]= w;
	local[4]= fqv[490];
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,1,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[328]); /*symbol-name*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	local[2]= NIL;
	local[3]= (pointer)get_sym_func(fqv[491]);
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F7000(ctx,1,local+3); /*compile-file*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[492];
	local[4]= local[1];
	local[5]= fqv[94];
	local[6]= fqv[493];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,4,local+3,&ftab[24],fqv[494]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[401]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[492];
	local[4]= local[1];
	local[5]= fqv[94];
	local[6]= fqv[495];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,4,local+3,&ftab[24],fqv[494]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[401]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[492];
	local[4]= local[1];
	local[5]= fqv[94];
	local[6]= fqv[496];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,4,local+3,&ftab[24],fqv[494]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[25])(ctx,1,local+3,&ftab[25],fqv[372]); /*load*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[401]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[492];
	local[4]= local[1];
	local[5]= fqv[94];
	local[6]= fqv[497];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,4,local+3,&ftab[24],fqv[494]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[401]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	w = local[0];
	local[0]= w;
BLK22023:
	ctx->vsp=local; return(local[0]);}

/*compile-file-if-src-newer*/
static pointer F7004(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT22160;}
	local[0]= fqv[498];
ENT22160:
ENT22159:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-2);
	local[2]= argv[0];
	local[3]= fqv[499];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,2,local+2,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[2]= w;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,1,local+4,&ftab[17],fqv[387]); /*pathname*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,2,local+3,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[3]= w;
	local[4]= fqv[500];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,1,local+5,&ftab[17],fqv[387]); /*pathname*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[388]); /*merge-pathnames*/
	local[4]= w;
	local[5]= local[3];
	local[6]= fqv[94];
	local[7]= fqv[501];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[19])(ctx,1,local+5,&ftab[19],fqv[397]); /*probe-file*/
	if (w==NIL) goto OR22214;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[26])(ctx,2,local+5,&ftab[26],fqv[502]); /*file-newer*/
	if (w!=NIL) goto OR22214;
	goto IF22212;
OR22214:
	local[5]= (pointer)get_sym_func(fqv[503]);
	local[6]= argv[0];
	local[7]= fqv[504];
	local[8]= local[3];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,5,local+5); /*apply*/
	local[5]= w;
	goto IF22213;
IF22212:
	local[5]= NIL;
IF22213:
	w = argv[0];
	local[0]= w;
BLK22157:
	ctx->vsp=local; return(local[0]);}

/*comp-file-toplevel*/
static pointer F7006(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22249:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[505];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[14]); /*warn*/
	local[1]= loadglobal(fqv[478]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= makeint(60000);
	ctx->vsp=local+2;
	w=(pointer)ALLOC(ctx,1,local+1); /*system:alloc*/
	local[1]= fqv[506];
	storeglobal(fqv[507],local[1]);
	local[1]= makeint(1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= fqv[508];
	w = local[5];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[509],w);
	local[9]= local[2];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto CON22306;
	local[9]= (pointer)get_sym_func(fqv[510]);
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	goto CON22304;
CON22306:
	local[9]= local[2];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto CON22316;
	local[9]= T;
	local[10]= fqv[511];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,2,local+9); /*format*/
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[27])(ctx,1,local+9,&ftab[27],fqv[512]); /*exit*/
	local[9]= w;
	goto CON22304;
CON22316:
WHL22331:
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX22332;
	{jmp_buf jb;
	w = makeint(0);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT22340;}
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[3] = w;
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(*ftab[28])(ctx,1,local+15,&ftab[28],fqv[513]); /*string-upcase*/
	local[4] = w;
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[15]= local[4];
	local[16]= fqv[514];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22378;
	local[15]= fqv[427];
	w = loadglobal(fqv[419]);
	if (memq(local[15],w)!=NIL) goto IF22386;
	local[15]= fqv[515];
	storeglobal(fqv[385],local[15]);
	goto IF22387;
IF22386:
	local[15]= NIL;
IF22387:
	goto CON22376;
CON22378:
	local[15]= local[4];
	local[16]= fqv[516];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22400;
	local[15]= makeint(1);
	storeglobal(fqv[312],local[15]);
	goto CON22376;
CON22400:
	local[15]= local[4];
	local[16]= fqv[517];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22411;
	local[15]= makeint(2);
	storeglobal(fqv[312],local[15]);
	goto CON22376;
CON22411:
	local[15]= local[4];
	local[16]= fqv[518];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22422;
	local[15]= makeint(3);
	storeglobal(fqv[312],local[15]);
	goto CON22376;
CON22422:
	local[15]= local[4];
	local[16]= fqv[519];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22433;
	local[15]= T;
	storeglobal(fqv[339],local[15]);
	goto CON22376;
CON22433:
	local[15]= local[4];
	local[16]= fqv[520];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22444;
	local[15]= makeint(0);
	storeglobal(fqv[179],local[15]);
	goto CON22376;
CON22444:
	local[15]= local[4];
	local[16]= fqv[521];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22455;
	local[15]= makeint(1);
	storeglobal(fqv[179],local[15]);
	goto CON22376;
CON22455:
	local[15]= local[4];
	local[16]= fqv[522];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22466;
	local[15]= makeint(2);
	storeglobal(fqv[179],local[15]);
	goto CON22376;
CON22466:
	local[15]= local[4];
	local[16]= fqv[523];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22477;
	local[15]= makeint(3);
	storeglobal(fqv[179],local[15]);
	goto CON22376;
CON22477:
	local[15]= local[4];
	local[16]= fqv[524];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22488;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[29])(ctx,1,local+15,&ftab[29],fqv[525]); /*read-from-string*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)EVAL(ctx,1,local+15); /*eval*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[15]= local[1];
	goto CON22376;
CON22488:
	local[15]= local[4];
	local[16]= fqv[526];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22515;
	local[15]= NIL;
	storeglobal(fqv[381],local[15]);
	goto CON22376;
CON22515:
	local[15]= local[4];
	local[16]= fqv[527];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22526;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[29])(ctx,1,local+15,&ftab[29],fqv[525]); /*read-from-string*/
	local[15]= w;
	w = loadglobal(fqv[419]);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	storeglobal(fqv[419],local[15]);
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[15]= local[1];
	goto CON22376;
CON22526:
	local[15]= local[4];
	local[16]= fqv[528];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22559;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[29])(ctx,1,local+15,&ftab[29],fqv[525]); /*read-from-string*/
	local[15]= w;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	if (w!=NIL) goto IF22584;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(*ftab[30])(ctx,1,local+16,&ftab[30],fqv[529]); /*make-package*/
	local[16]= w;
	goto IF22585;
IF22584:
	local[16]= NIL;
IF22585:
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	if (w==NIL) goto IF22601;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	local[16]= w;
	storeglobal(fqv[396],w);
	goto IF22602;
IF22601:
	local[16]= fqv[530];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
IF22602:
	w = local[16];
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[15]= local[1];
	goto CON22376;
CON22559:
	local[15]= local[4];
	local[16]= fqv[531];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22629;
	local[15]= T;
	storeglobal(fqv[382],local[15]);
	goto CON22376;
CON22629:
	local[15]= local[4];
	local[16]= fqv[532];
	ctx->vsp=local+17;
	w=(*ftab[31])(ctx,2,local+15,&ftab[31],fqv[533]); /*string-equal*/
	if (w==NIL) goto CON22640;
	local[15]= NIL;
	storeglobal(fqv[382],local[15]);
	goto CON22376;
CON22640:
	local[15]= loadglobal(fqv[5]);
	local[16]= fqv[487];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	goto CON22376;
CON22652:
	local[15]= NIL;
CON22376:
	w = local[15];
CAT22340:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL22331;
WHX22332:
	local[9]= NIL;
BLK22333:
	goto CON22304;
CON22327:
	local[9]= NIL;
CON22304:
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(*ftab[27])(ctx,1,local+9,&ftab[27],fqv[512]); /*exit*/
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK22247:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___comp(ctx,n,argv,env)
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
	local[0]= fqv[534];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF22673;
	local[0]= fqv[535];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[396],w);
	goto IF22674;
IF22673:
	local[0]= fqv[536];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF22674:
	local[0]= fqv[537];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[538];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[539],module,F6907,fqv[540]);
	local[0]= fqv[385];
	local[1]= fqv[541];
	local[2]= fqv[542];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[464];
	local[1]= fqv[541];
	local[2]= fqv[543];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[347];
	local[1]= fqv[541];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[339];
	local[1]= fqv[541];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[312];
	local[1]= fqv[541];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[179];
	local[1]= fqv[541];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[315];
	local[1]= fqv[541];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[381];
	local[1]= fqv[541];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[382];
	local[1]= fqv[541];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[415];
	local[1]= fqv[541];
	local[2]= fqv[447];
	local[3]= loadglobal(fqv[419]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[262]); /*member*/
	if (w==NIL) goto CON22783;
	local[2]= fqv[544];
	goto CON22781;
CON22783:
	local[2]= fqv[435];
	local[3]= loadglobal(fqv[419]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[262]); /*member*/
	if (w==NIL) goto CON22792;
	local[2]= fqv[545];
	goto CON22781;
CON22792:
	local[2]= fqv[546];
	goto CON22781;
CON22801:
	local[2]= NIL;
CON22781:
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[5];
	local[1]= fqv[547];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF22808;
	local[0]= fqv[5];
	local[1]= fqv[547];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF22831;
	local[0]= fqv[5];
	local[1]= fqv[541];
	local[2]= NIL;
	local[3]= fqv[548];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF22832;
IF22831:
	local[0]= NIL;
IF22832:
	local[0]= fqv[5];
	goto IF22809;
IF22808:
	local[0]= NIL;
IF22809:
	local[0]= fqv[21];
	local[1]= fqv[547];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF22851;
	local[0]= fqv[21];
	local[1]= fqv[547];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[21];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF22874;
	local[0]= fqv[21];
	local[1]= fqv[541];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF22875;
IF22874:
	local[0]= NIL;
IF22875:
	local[0]= fqv[21];
	goto IF22852;
IF22851:
	local[0]= NIL;
IF22852:
	local[0]= fqv[403];
	local[1]= fqv[547];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF22894;
	local[0]= fqv[403];
	local[1]= fqv[547];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[403];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF22917;
	local[0]= fqv[403];
	local[1]= fqv[541];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF22918;
IF22917:
	local[0]= NIL;
IF22918:
	local[0]= fqv[403];
	goto IF22895;
IF22894:
	local[0]= NIL;
IF22895:
	ctx->vsp=local+0;
	compfun(ctx,fqv[549],module,F6923,fqv[550]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[551],module,F6925,fqv[552]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[553],module,F6927,fqv[554]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[555],module,F6929,fqv[556]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[557],module,F6931,fqv[558]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[559],module,F6933,fqv[560]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[561],module,F6935,fqv[562]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[563],module,F6937,fqv[564]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[565],module,F6939,fqv[566]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[567],module,F6941,fqv[568]);
	local[0]= fqv[9];
	local[1]= fqv[569];
	ctx->vsp=local+2;
	w=(pointer)F6941(ctx,2,local+0); /*def-function-type*/
	local[0]= fqv[11];
	local[1]= fqv[570];
	ctx->vsp=local+2;
	w=(pointer)F6941(ctx,2,local+0); /*def-function-type*/
	local[0]= loadglobal(fqv[174]);
	local[1]= fqv[571];
	ctx->vsp=local+2;
	w=(pointer)F6941(ctx,2,local+0); /*def-function-type*/
	local[0]= fqv[54];
	local[1]= fqv[541];
	local[2]= fqv[54];
	local[3]= fqv[572];
	local[4]= loadglobal(fqv[352]);
	local[5]= fqv[573];
	local[6]= fqv[574];
	local[7]= fqv[575];
	local[8]= NIL;
	local[9]= fqv[576];
	local[10]= NIL;
	local[11]= fqv[577];
	local[12]= makeint(-1);
	local[13]= fqv[578];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[32])(ctx,13,local+2,&ftab[32],fqv[579]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7649,fqv[94],fqv[54],fqv[580]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7679,fqv[581],fqv[54],fqv[582]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7707,fqv[60],fqv[54],fqv[583]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7735,fqv[55],fqv[54],fqv[584]);
	local[0]= fqv[483];
	local[1]= fqv[541];
	local[2]= fqv[483];
	local[3]= fqv[572];
	local[4]= loadglobal(fqv[352]);
	local[5]= fqv[573];
	local[6]= fqv[585];
	local[7]= fqv[575];
	local[8]= NIL;
	local[9]= fqv[576];
	local[10]= NIL;
	local[11]= fqv[577];
	local[12]= makeint(-1);
	local[13]= fqv[578];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[32])(ctx,13,local+2,&ftab[32],fqv[579]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7796,fqv[61],fqv[483],fqv[586]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7832,fqv[53],fqv[483],fqv[587]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7911,fqv[17],fqv[483],fqv[588]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7955,fqv[56],fqv[483],fqv[589]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7976,fqv[74],fqv[483],fqv[590]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8000,fqv[80],fqv[483],fqv[591]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8030,fqv[592],fqv[483],fqv[593]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8048,fqv[75],fqv[483],fqv[594]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8076,fqv[480],fqv[483],fqv[595]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8102,fqv[406],fqv[483],fqv[596]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8174,fqv[55],fqv[483],fqv[597]);
	local[0]= fqv[73];
	local[1]= fqv[541];
	local[2]= fqv[73];
	local[3]= fqv[572];
	local[4]= loadglobal(fqv[352]);
	local[5]= fqv[573];
	local[6]= fqv[598];
	local[7]= fqv[575];
	local[8]= NIL;
	local[9]= fqv[576];
	local[10]= NIL;
	local[11]= fqv[577];
	local[12]= makeint(-1);
	local[13]= fqv[578];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[32])(ctx,13,local+2,&ftab[32],fqv[579]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8231,fqv[581],fqv[73],fqv[599]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8266,fqv[66],fqv[73],fqv[600]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8296,fqv[68],fqv[73],fqv[601]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8326,fqv[55],fqv[73],fqv[602]);
	local[0]= fqv[603];
	local[1]= fqv[541];
	local[2]= fqv[603];
	local[3]= fqv[572];
	local[4]= loadglobal(fqv[352]);
	local[5]= fqv[573];
	local[6]= fqv[604];
	local[7]= fqv[575];
	local[8]= NIL;
	local[9]= fqv[576];
	local[10]= NIL;
	local[11]= fqv[577];
	local[12]= makeint(-1);
	local[13]= fqv[578];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[32])(ctx,13,local+2,&ftab[32],fqv[579]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8385,fqv[251],fqv[603],fqv[605]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8406,fqv[230],fqv[603],fqv[606]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8493,fqv[20],fqv[603],fqv[607]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8888,fqv[36],fqv[603],fqv[608]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8995,fqv[44],fqv[603],fqv[609]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9138,fqv[59],fqv[603],fqv[610]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9261,fqv[269],fqv[603],fqv[611]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9294,fqv[278],fqv[603],fqv[612]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9353,fqv[65],fqv[603],fqv[613]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9480,fqv[275],fqv[603],fqv[614]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9676,fqv[74],fqv[603],fqv[615]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9742,fqv[277],fqv[603],fqv[616]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9869,fqv[33],fqv[603],fqv[617]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9982,fqv[30],fqv[603],fqv[618]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10162,fqv[97],fqv[603],fqv[619]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10245,fqv[271],fqv[603],fqv[620]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10401,fqv[38],fqv[603],fqv[621]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11298,fqv[158],fqv[603],fqv[622]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11479,fqv[163],fqv[603],fqv[623]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11607,fqv[166],fqv[603],fqv[624]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11791,fqv[160],fqv[603],fqv[625]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M12252,fqv[40],fqv[603],fqv[626]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M12930,fqv[245],fqv[603],fqv[627]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M12965,fqv[249],fqv[603],fqv[628]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13591,fqv[199],fqv[603],fqv[629]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13696,fqv[197],fqv[603],fqv[630]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13910,fqv[203],fqv[603],fqv[631]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14192,fqv[201],fqv[603],fqv[632]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14693,fqv[205],fqv[603],fqv[633]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14910,fqv[207],fqv[603],fqv[634]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15033,fqv[209],fqv[603],fqv[635]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15153,fqv[211],fqv[603],fqv[636]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15273,fqv[217],fqv[603],fqv[637]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15385,fqv[219],fqv[603],fqv[638]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15421,fqv[228],fqv[603],fqv[639]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15592,fqv[283],fqv[603],fqv[640]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15662,fqv[284],fqv[603],fqv[641]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15686,fqv[213],fqv[603],fqv[642]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15734,fqv[215],fqv[603],fqv[643]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15861,fqv[221],fqv[603],fqv[644]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16065,fqv[223],fqv[603],fqv[645]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16164,fqv[232],fqv[603],fqv[646]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16289,fqv[225],fqv[603],fqv[647]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16530,fqv[306],fqv[603],fqv[648]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16552,fqv[274],fqv[603],fqv[649]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M17204,fqv[341],fqv[603],fqv[650]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M18702,fqv[350],fqv[603],fqv[651]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M18893,fqv[375],fqv[603],fqv[652]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M18964,fqv[364],fqv[603],fqv[653]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19130,fqv[367],fqv[603],fqv[654]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19526,fqv[351],fqv[603],fqv[655]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19552,fqv[293],fqv[603],fqv[656]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19578,fqv[481],fqv[603],fqv[657]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19604,fqv[362],fqv[603],fqv[658]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19695,fqv[361],fqv[603],fqv[659]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19811,fqv[376],fqv[603],fqv[660]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19958,fqv[373],fqv[603],fqv[661]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20302,fqv[408],fqv[603],fqv[662]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20464,fqv[487],fqv[603],fqv[663]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21545,fqv[664],fqv[603],fqv[665]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21567,fqv[292],fqv[603],fqv[666]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21634,fqv[55],fqv[603],fqv[667]);
	local[0]= loadglobal(fqv[603]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	storeglobal(fqv[5],w);
	local[0]= loadglobal(fqv[5]);
	local[1]= fqv[55];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[491],module,F6996,fqv[668]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[669],module,F6998,fqv[670]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[503],module,F7000,fqv[671]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[371],module,F7002,fqv[672]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[673],module,F7004,fqv[674]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[675],module,F7006,fqv[676]);
	local[0]= fqv[677];
	local[1]= fqv[678];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[679]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<34; i++) ftab[i]=fcallx;
}
