/* common.c :  entry=common */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "common.h"
#pragma init (register_common)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___common();
extern pointer build_quote_vector();
static register_common()
  { add_module_initializer("___common", ___common);}

static pointer F4522();
static pointer F4523();
static pointer F4526();
static pointer F4554();
static pointer F4556();
static pointer F4558();
static pointer F4561();
static pointer F4563();
static pointer F4565();
static pointer F4568();
static pointer F4573();
static pointer F4575();
static pointer F4577();
static pointer F4579();
static pointer F4581();
static pointer F4583();
static pointer F4585();
static pointer F4590();
static pointer F4592();
static pointer F4594();
static pointer F4596();
static pointer F4598();
static pointer F4600();
static pointer F4602();
static pointer F4604();
static pointer F4606();
static pointer F4608();
static pointer F4610();
static pointer F4612();
static pointer F4614();
static pointer F4616();
static pointer F4618();
static pointer F4620();
static pointer F4622();
static pointer F4624();
static pointer F4626();
static pointer F4628();
static pointer F4630();
static pointer F4632();
static pointer F4634();
static pointer F4636();
static pointer F4638();
static pointer F4640();
static pointer F4642();
static pointer F4644();
static pointer F4646();
static pointer F4648();
static pointer F4650();
static pointer F4652();
static pointer F4654();
static pointer F4656();
static pointer F4658();
static pointer F4660();
static pointer F4662();
static pointer F4664();
static pointer F4666();
static pointer F4668();
static pointer F4670();
static pointer F4672();
static pointer F4674();
static pointer F4676();
static pointer F4678();
static pointer F4680();
static pointer F4682();
static pointer F4684();
static pointer F4686();
static pointer F4688();
static pointer F4690();
static pointer F4692();
static pointer F4694();
static pointer F4696();
static pointer F4698();
static pointer F4700();
static pointer F4702();
static pointer F4704();
static pointer F4706();
static pointer F4708();
static pointer F4710();
static pointer F4712();
static pointer F4714();
static pointer F4716();
static pointer F4724();
static pointer F4726();
static pointer F4730();
static pointer F4733();
static pointer F4735();
static pointer F4741();
static pointer F4743();
static pointer F4745();
static pointer F4749();
static pointer F4751();
static pointer F4753();
static pointer F4755();
static pointer F4757();
static pointer F4759();
static pointer F4761();
static pointer F4763();
static pointer F4765();
static pointer F4767();
static pointer F4769();
static pointer F4771();
static pointer F4773();
static pointer F4775();
static pointer F4777();
static pointer F4779();
static pointer F4781();
static pointer F4783();
static pointer F4786();
static pointer F4788();
static pointer F4792();
static pointer F4794();
static pointer F4796();
static pointer F4798();
static pointer F4800();
static pointer F4802();
static pointer F4804();
static pointer F4805();
static pointer F4806();

/*lisp-implementation-type*/
static pointer F4522(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	w = fqv[0];
	local[0]= w;
BLK4949:
	ctx->vsp=local; return(local[0]);}

/*lisp-implementation-version*/
static pointer F4523(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= NIL;
	local[1]= fqv[1];
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= loadglobal(fqv[3]);
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK4959:
	ctx->vsp=local; return(local[0]);}

/*macroexpand*/
static pointer F4526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)MACEXPAND2(ctx,1,local+0); /*macroexpand2*/
	local[0]= w;
WHL5011:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto WHX5012;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4767(ctx,1,local+1); /*macro-function*/
	if (w==NIL) goto WHX5012;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MACEXPAND2(ctx,1,local+1); /*macroexpand2*/
	local[0] = w;
	goto WHL5011;
WHX5012:
	local[1]= NIL;
BLK5013:
	w = local[0];
	local[0]= w;
BLK4988:
	ctx->vsp=local; return(local[0]);}

/*prog1*/
static pointer F5045(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST5048:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5046:
	ctx->vsp=local; return(local[0]);}

/*loop*/
static pointer F5108(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST5111:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[8];
	local[3]= fqv[9];
	local[4]= fqv[10];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= fqv[11];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
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
	local[0]= w;
BLK5109:
	ctx->vsp=local; return(local[0]);}

/*unless*/
static pointer F5167(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5170:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[12];
	local[2]= fqv[13];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5168:
	ctx->vsp=local; return(local[0]);}

/*until*/
static pointer F5200(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5203:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[14];
	local[2]= fqv[13];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5201:
	ctx->vsp=local; return(local[0]);}

/*pop*/
static pointer F5234(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[15];
	local[1]= fqv[16];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[17];
	local[3]= argv[0];
	local[4]= fqv[18];
	local[5]= argv[0];
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
BLK5235:
	ctx->vsp=local; return(local[0]);}

/*push*/
static pointer F5281(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[17];
	local[1]= argv[1];
	local[2]= fqv[19];
	local[3]= argv[0];
	local[4]= argv[1];
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
BLK5282:
	ctx->vsp=local; return(local[0]);}

/*pushnew*/
static pointer F5318(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[20], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY5332;
	local[0] = NIL;
KEY5332:
	if (n & (1<<1)) goto KEY5337;
	local[1] = NIL;
KEY5337:
	if (n & (1<<2)) goto KEY5342;
	local[2] = NIL;
KEY5342:
	local[3]= fqv[6];
	local[4]= fqv[21];
	local[5]= fqv[13];
	local[6]= fqv[22];
	local[7]= argv[0];
	local[8]= argv[1];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
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
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[17];
	local[7]= argv[1];
	local[8]= fqv[19];
	local[9]= argv[0];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK5319:
	ctx->vsp=local; return(local[0]);}

/*inc*/
static pointer F5439(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5443;}
	local[0]= NIL;
ENT5443:
ENT5442:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5457;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5458;
IF5457:
	local[1]= fqv[27];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5458:
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5440:
	ctx->vsp=local; return(local[0]);}

/*dec*/
static pointer F5493(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5497;}
	local[0]= NIL;
ENT5497:
ENT5496:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5511;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5512;
IF5511:
	local[1]= fqv[30];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5512:
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5494:
	ctx->vsp=local; return(local[0]);}

/*incf*/
static pointer F5547(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5551;}
	local[0]= NIL;
ENT5551:
ENT5550:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5565;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5566;
IF5565:
	local[1]= fqv[27];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5566:
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5548:
	ctx->vsp=local; return(local[0]);}

/*decf*/
static pointer F5601(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5605;}
	local[0]= NIL;
ENT5605:
ENT5604:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5619;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5620;
IF5619:
	local[1]= fqv[30];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5620:
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5602:
	ctx->vsp=local; return(local[0]);}

/*defvar*/
static pointer F5655(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5660;}
	local[0]= NIL;
ENT5660:
	if (n>=3) { local[1]=(argv[2]); goto ENT5659;}
	local[1]= NIL;
ENT5659:
ENT5658:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5679;
	local[2]= makeint(20);
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF5680;
IF5679:
	local[2]= NIL;
IF5680:
	local[2]= fqv[12];
	local[3]= fqv[31];
	local[4]= fqv[32];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[32];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[36];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[21];
	local[6]= fqv[13];
	local[7]= fqv[37];
	local[8]= fqv[33];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[32];
	local[8]= fqv[33];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[38];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5656:
	ctx->vsp=local; return(local[0]);}

/*deflocal*/
static pointer F5822(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5827;}
	local[0]= NIL;
ENT5827:
	if (n>=3) { local[1]=(argv[2]); goto ENT5826;}
	local[1]= NIL;
ENT5826:
ENT5825:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5846;
	local[2]= makeint(20);
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF5847;
IF5846:
	local[2]= NIL;
IF5847:
	local[2]= fqv[6];
	local[3]= fqv[32];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[39];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5823:
	ctx->vsp=local; return(local[0]);}

/*defparameter*/
static pointer F5903(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5907;}
	local[0]= NIL;
ENT5907:
ENT5906:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5924;
	local[1]= makeint(20);
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF5925;
IF5924:
	local[1]= NIL;
IF5925:
	local[1]= fqv[32];
	local[2]= fqv[33];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[38];
	local[4]= argv[1];
	local[5]= local[0];
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
	local[0]= w;
BLK5904:
	ctx->vsp=local; return(local[0]);}

/*defconstant*/
static pointer F5965(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5969;}
	local[0]= NIL;
ENT5969:
ENT5968:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5986;
	local[1]= makeint(20);
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF5987;
IF5986:
	local[1]= NIL;
IF5987:
	local[1]= fqv[32];
	local[2]= fqv[33];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[40];
	local[4]= argv[1];
	local[5]= local[0];
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
	local[0]= w;
BLK5966:
	ctx->vsp=local; return(local[0]);}

/*dotimes*/
static pointer F6027(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6030:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[42];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[43];
	local[5]= fqv[44];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[1];
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
	local[5]= fqv[14];
	local[6]= fqv[45];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[0];
	local[8]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[27];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK6028:
	ctx->vsp=local; return(local[0]);}

/*dolist*/
static pointer F6181(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6184:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w = local[2];
	if (!iscons(w)) goto IF6215;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF6215;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF6216;
IF6215:
	local[2] = NIL;
	local[3]= local[2];
IF6216:
	local[3]= fqv[5];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[2];
	local[6]= fqv[14];
	local[7]= local[1];
	local[8]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[47];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[0];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK6182:
	ctx->vsp=local; return(local[0]);}

/*do-symbols*/
static pointer F6338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6341:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF6369;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF6370;
IF6369:
	local[3]= fqv[49];
IF6370:
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,0,local+6); /*gensym*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GENSYM(ctx,0,local+7); /*gensym*/
	local[7]= w;
	local[8]= fqv[50];
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[4];
	local[11]= fqv[51];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[5];
	local[12]= fqv[52];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[7];
	local[13]= local[4];
	w = fqv[53];
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[6];
	local[14]= fqv[54];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
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
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[14];
	local[11]= fqv[45];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[28];
	local[13]= local[2];
	local[14]= fqv[55];
	local[15]= local[7];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[56];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[12];
	local[15]= fqv[57];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	w = local[0];
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
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
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	local[0]= w;
BLK6339:
	ctx->vsp=local; return(local[0]);}

/*do-external-symbols*/
static pointer F6565(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6568:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF6596;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF6597;
IF6596:
	local[3]= fqv[49];
IF6597:
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,0,local+6); /*gensym*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GENSYM(ctx,0,local+7); /*gensym*/
	local[7]= w;
	local[8]= fqv[50];
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[4];
	local[11]= fqv[51];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[5];
	local[12]= fqv[59];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[7];
	local[13]= local[4];
	w = fqv[60];
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[6];
	local[14]= fqv[54];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
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
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[14];
	local[11]= fqv[45];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[28];
	local[13]= local[2];
	local[14]= fqv[55];
	local[15]= local[7];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[56];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[12];
	local[15]= fqv[57];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	w = local[0];
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
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
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	local[0]= w;
BLK6566:
	ctx->vsp=local; return(local[0]);}

/*do-all-symbols*/
static pointer F6792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6795:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= local[1];
	local[4]= fqv[63];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[64];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
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
	local[0]= w;
BLK6793:
	ctx->vsp=local; return(local[0]);}

/*psetq*/
static pointer F6869(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST6872:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL6893:
	if (local[0]==NIL) goto WHX6894;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,1,local+4); /*gensym*/
	local[4]= w;
	w = local[3];
	ctx->vsp=local+5;
	local[3] = cons(ctx,local[4],w);
	goto WHL6893;
WHX6894:
	local[4]= NIL;
BLK6895:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[2] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[3] = w;
	local[4]= fqv[50];
	local[5]= (pointer)get_sym_func(fqv[66]);
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,3,local+5); /*mapcar*/
	local[5]= w;
	local[6]= fqv[28];
	local[7]= (pointer)get_sym_func(fqv[66]);
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MAPCAN(ctx,3,local+7); /*mapcan*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK6870:
	ctx->vsp=local; return(local[0]);}

/*do*/
static pointer F7059(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST7062:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	if (!iscons(w)) goto IF7095;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF7095;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF7096;
IF7095:
	local[1] = NIL;
	local[3]= local[1];
IF7096:
	local[3]= fqv[8];
	local[4]= fqv[9];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO7139,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[1];
	local[8]= fqv[10];
	local[9]= local[2];
	local[10]= fqv[21];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[68];
	local[13]= fqv[6];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[0];
	local[12]= fqv[69];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO7190,env,argv,local);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)APPEND(ctx,2,local+11); /*append*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
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
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK7060:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7139(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7190(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7258;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF7259;
IF7258:
	local[0]= NIL;
IF7259:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*do**/
static pointer F7288(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST7291:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[70];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	if (!iscons(w)) goto IF7324;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF7324;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF7325;
IF7324:
	local[1] = NIL;
	local[3]= local[1];
IF7325:
	local[3]= fqv[8];
	local[4]= fqv[9];
	local[5]= fqv[50];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO7368,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[1];
	local[8]= fqv[10];
	local[9]= local[2];
	local[10]= fqv[21];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[68];
	local[13]= fqv[6];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[0];
	local[12]= fqv[28];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO7419,env,argv,local);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)APPEND(ctx,2,local+11); /*append*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
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
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK7289:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7368(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7419(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7487;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF7488;
IF7487:
	local[0]= NIL;
IF7488:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*prog*/
static pointer F7517(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7520:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[8];
	local[2]= fqv[9];
	local[3]= fqv[5];
	local[4]= argv[0];
	local[5]= fqv[10];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK7518:
	ctx->vsp=local; return(local[0]);}

/*prog**/
static pointer F7562(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7565:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[8];
	local[2]= fqv[9];
	local[3]= fqv[50];
	local[4]= argv[0];
	local[5]= fqv[10];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK7563:
	ctx->vsp=local; return(local[0]);}

/*casebody*/
static pointer F4554(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7618;
	local[0]= fqv[6];
	w = argv[0];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF7619;
IF7618:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF7619:
	w = local[0];
	local[0]= w;
BLK7608:
	ctx->vsp=local; return(local[0]);}

/*casehead*/
static pointer F4556(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7653;
	local[0]= argv[1];
	w = fqv[71];
	if (memq(local[0],w)==NIL) goto IF7659;
	local[0]= T;
	goto IF7660;
IF7659:
	local[0]= fqv[72];
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF7660:
	goto IF7654;
IF7653:
	local[0]= fqv[73];
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF7654:
	w = local[0];
	local[0]= w;
BLK7641:
	ctx->vsp=local; return(local[0]);}

/*case1*/
static pointer F4558(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7704;
	local[0]= NIL;
	goto IF7705;
IF7704:
	local[0]= fqv[21];
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4556(ctx,2,local+1); /*casehead*/
	local[1]= w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F4554(ctx,1,local+2); /*casebody*/
	local[2]= w;
	local[3]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F4558(ctx,2,local+3); /*case1*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,5,local+0); /*list*/
	local[0]= w;
IF7705:
	w = local[0];
	local[0]= w;
BLK7692:
	ctx->vsp=local; return(local[0]);}

/*case*/
static pointer F7743(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7746:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= fqv[5];
	local[4]= local[1];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F4558(ctx,2,local+5); /*case1*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[0]= w;
BLK7744:
	ctx->vsp=local; return(local[0]);}

/*classcasehead*/
static pointer F4561(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	w = fqv[75];
	if (memq(local[0],w)==NIL) goto IF7801;
	local[0]= T;
	goto IF7802;
IF7801:
	w = argv[1];
	if (!!iscons(w)) goto IF7812;
	local[0]= fqv[76];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF7813;
IF7812:
	local[0]= fqv[77];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO7833,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
IF7813:
IF7802:
	w = local[0];
	local[0]= w;
BLK7789:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7833(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[76];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*classcase1*/
static pointer F4563(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7875;
	local[0]= NIL;
	goto IF7876;
IF7875:
	local[0]= fqv[21];
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4561(ctx,2,local+1); /*classcasehead*/
	local[1]= w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F4554(ctx,1,local+2); /*casebody*/
	local[2]= w;
	local[3]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F4563(ctx,2,local+3); /*classcase1*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,5,local+0); /*list*/
	local[0]= w;
IF7876:
	w = local[0];
	local[0]= w;
BLK7863:
	ctx->vsp=local; return(local[0]);}

/*classcase*/
static pointer F7914(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7917:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F4563(ctx,2,local+4); /*classcase1*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK7915:
	ctx->vsp=local; return(local[0]);}

/*string*/
static pointer F4565(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto IF7974;
	local[0]= argv[0];
	goto IF7975;
IF7974:
	w = argv[0];
	if (!issymbol(w)) goto IF7981;
	local[0]= *(ovafptr(argv[0],fqv[79]));
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	goto IF7982;
IF7981:
	w = argv[0];
	if (!isnum(w)) goto IF7991;
	local[0]= NIL;
	local[1]= fqv[80];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF7992;
IF7991:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF7992:
IF7982:
IF7975:
	w = local[0];
	local[0]= w;
BLK7964:
	ctx->vsp=local; return(local[0]);}

/*alias*/
static pointer F4568(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	local[1]= w;
	w = argv[0];
	w->c.obj.iv[3] = local[1];
	w = local[0];
	local[0]= w;
BLK8006:
	ctx->vsp=local; return(local[0]);}

/*caaar*/
static pointer F4573(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8032:
	ctx->vsp=local; return(local[0]);}

/*caadr*/
static pointer F4575(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8056:
	ctx->vsp=local; return(local[0]);}

/*cadar*/
static pointer F4577(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8080:
	ctx->vsp=local; return(local[0]);}

/*cdaar*/
static pointer F4579(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8104:
	ctx->vsp=local; return(local[0]);}

/*cdadr*/
static pointer F4581(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8128:
	ctx->vsp=local; return(local[0]);}

/*cddar*/
static pointer F4583(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8152:
	ctx->vsp=local; return(local[0]);}

/*cdddr*/
static pointer F4585(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8176:
	ctx->vsp=local; return(local[0]);}

/*fourth*/
static pointer F4590(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8206:
	ctx->vsp=local; return(local[0]);}

/*fifth*/
static pointer F4592(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8232:
	ctx->vsp=local; return(local[0]);}

/*sixth*/
static pointer F4594(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4585(ctx,1,local+0); /*cdddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8260:
	ctx->vsp=local; return(local[0]);}

/*seventh*/
static pointer F4596(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4600(ctx,1,local+0); /*cddddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8284:
	ctx->vsp=local; return(local[0]);}

/*eighth*/
static pointer F4598(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4600(ctx,1,local+0); /*cddddr*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F4602(ctx,1,local+0); /*cadddr*/
	local[0]= w;
BLK8308:
	ctx->vsp=local; return(local[0]);}

/*cddddr*/
static pointer F4600(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8325:
	ctx->vsp=local; return(local[0]);}

/*cadddr*/
static pointer F4602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8351:
	ctx->vsp=local; return(local[0]);}

/*caaddr*/
static pointer F4604(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8377:
	ctx->vsp=local; return(local[0]);}

/*cdaddr*/
static pointer F4606(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8403:
	ctx->vsp=local; return(local[0]);}

/*caddddr*/
static pointer F4608(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4585(ctx,1,local+0); /*cdddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8429:
	ctx->vsp=local; return(local[0]);}

/*flatten*/
static pointer F4610(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT8454;}
	local[0]= NIL;
ENT8454:
ENT8453:
	if (n>2) maerror();
	if (argv[0]!=NIL) goto CON8470;
	local[1]= local[0];
	goto CON8468;
CON8470:
	w = argv[0];
	if (!!iscons(w)) goto CON8476;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON8468;
CON8476:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F4610(ctx,2,local+2); /*flatten*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F4610(ctx,2,local+1); /*flatten*/
	local[1]= w;
	goto CON8468;
CON8486:
	local[1]= NIL;
CON8468:
	w = local[1];
	local[0]= w;
BLK8451:
	ctx->vsp=local; return(local[0]);}

/*list-insert*/
static pointer F4612(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto CON8524;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON8522;
CON8524:
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON8532;
	local[0]= argv[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON8522;
CON8532:
	local[0]= argv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON8546;
	local[0]= argv[0];
	w = argv[2];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON8522;
CON8546:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= (pointer)((integer_t)(argv[1])-4);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)RPLACD(ctx,2,local+1); /*rplacd*/
	w = argv[2];
	local[0]= w;
	goto CON8522;
CON8556:
	local[0]= NIL;
CON8522:
	w = local[0];
	local[0]= w;
BLK8508:
	ctx->vsp=local; return(local[0]);}

/*list-delete*/
static pointer F4614(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF8606;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[0]= argv[0];
	goto IF8607;
IF8606:
	local[0]= (pointer)((integer_t)(argv[1])-4);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)NTHCDR(ctx,2,local+0); /*nthcdr*/
	local[0]= w;
	local[1]= (pointer)((integer_t)(argv[1])+4);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)RPLACD(ctx,2,local+0); /*rplacd*/
	local[0]= w;
IF8607:
	w = argv[0];
	local[0]= w;
BLK8594:
	ctx->vsp=local; return(local[0]);}

/*adjoin*/
static pointer F4616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[81], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8656;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8656:
	if (n & (1<<1)) goto KEY8663;
	local[1] = NIL;
KEY8663:
	if (n & (1<<2)) goto KEY8668;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8668:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[23];
	local[6]= local[0];
	local[7]= fqv[24];
	local[8]= local[1];
	local[9]= fqv[25];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F4640(ctx,8,local+3); /*member*/
	if (w==NIL) goto IF8679;
	local[3]= argv[1];
	goto IF8680;
IF8679:
	local[3]= argv[0];
	w = argv[1];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
IF8680:
	w = local[3];
	local[0]= w;
BLK8643:
	ctx->vsp=local; return(local[0]);}

/*union*/
static pointer F4618(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[83], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8718;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8718:
	if (n & (1<<1)) goto KEY8725;
	local[1] = NIL;
KEY8725:
	if (n & (1<<2)) goto KEY8730;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8730:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL8767:
	if (local[5]==NIL) goto WHX8768;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= local[3];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4640(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8817;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8818;
IF8817:
	local[6]= NIL;
IF8818:
	goto WHL8767;
WHX8768:
	local[6]= NIL;
BLK8769:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[1];
WHL8872:
	if (local[5]==NIL) goto WHX8873;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= local[3];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4640(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8922;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8923;
IF8922:
	local[6]= NIL;
IF8923:
	goto WHL8872;
WHX8873:
	local[6]= NIL;
BLK8874:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	local[0]= w;
BLK8705:
	ctx->vsp=local; return(local[0]);}

/*intersection*/
static pointer F4620(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[84], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8979;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8979:
	if (n & (1<<1)) goto KEY8986;
	local[1] = NIL;
KEY8986:
	if (n & (1<<2)) goto KEY8991;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8991:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL9028:
	if (local[5]==NIL) goto WHX9029;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4640(ctx,8,local+6); /*member*/
	if (w==NIL) goto IF9077;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF9078;
IF9077:
	local[6]= NIL;
IF9078:
	goto WHL9028;
WHX9029:
	local[6]= NIL;
BLK9030:
	w = NIL;
	w = local[3];
	local[0]= w;
BLK8966:
	ctx->vsp=local; return(local[0]);}

/*set-difference*/
static pointer F4622(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[85], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9130;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY9130:
	if (n & (1<<1)) goto KEY9137;
	local[1] = NIL;
KEY9137:
	if (n & (1<<2)) goto KEY9142;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY9142:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL9179:
	if (local[5]==NIL) goto WHX9180;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4640(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF9229;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF9230;
IF9229:
	local[6]= NIL;
IF9230:
	goto WHL9179;
WHX9180:
	local[6]= NIL;
BLK9181:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0]= w;
BLK9117:
	ctx->vsp=local; return(local[0]);}

/*set-exclusive-or*/
static pointer F4624(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[86], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9287;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY9287:
	if (n & (1<<1)) goto KEY9294;
	local[1] = NIL;
KEY9294:
	if (n & (1<<2)) goto KEY9299;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY9299:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
WHL9338:
	if (local[6]==NIL) goto WHX9339;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[1];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)F4640(ctx,8,local+7); /*member*/
	if (w!=NIL) goto IF9398;
	local[7]= local[5];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
	goto IF9399;
IF9398:
	local[7]= NIL;
IF9399:
	goto WHL9338;
WHX9339:
	local[7]= NIL;
BLK9340:
	w = NIL;
	local[5]= NIL;
	local[6]= argv[1];
WHL9451:
	if (local[6]==NIL) goto WHX9452;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[0];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)F4640(ctx,8,local+7); /*member*/
	if (w!=NIL) goto IF9511;
	local[7]= local[5];
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF9512;
IF9511:
	local[7]= NIL;
IF9512:
	goto WHL9451;
WHX9452:
	local[7]= NIL;
BLK9453:
	w = NIL;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[0]= w;
BLK9274:
	ctx->vsp=local; return(local[0]);}

/*rotate-list*/
static pointer F4626(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK9554:
	ctx->vsp=local; return(local[0]);}

/*last*/
static pointer F4628(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
WHL9590:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (!iscons(w)) goto WHX9591;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL9590;
WHX9591:
	local[0]= NIL;
BLK9592:
	w = argv[0];
	local[0]= w;
BLK9580:
	ctx->vsp=local; return(local[0]);}

/*copy-tree*/
static pointer F4630(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= T;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SUBST(ctx,3,local+0); /*subst*/
	local[0]= w;
BLK9617:
	ctx->vsp=local; return(local[0]);}

/*copy-list*/
static pointer F4632(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
BLK9632:
	ctx->vsp=local; return(local[0]);}

/*nreconc*/
static pointer F4634(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
BLK9649:
	ctx->vsp=local; return(local[0]);}

/*rassoc*/
static pointer F4636(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL9698:
	if (local[1]==NIL) goto WHX9699;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)EQUAL(ctx,2,local+2); /*equal*/
	if (w==NIL) goto IF9747;
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK9669;
	goto IF9748;
IF9747:
	local[2]= NIL;
IF9748:
	goto WHL9698;
WHX9699:
	local[2]= NIL;
BLK9700:
	w = NIL;
	local[0]= w;
BLK9669:
	ctx->vsp=local; return(local[0]);}

/*acons*/
static pointer F4638(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	w = argv[1];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	w = argv[2];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK9769:
	ctx->vsp=local; return(local[0]);}

/*member*/
static pointer F4640(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[87], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9808;
	local[0] = NIL;
KEY9808:
	if (n & (1<<1)) goto KEY9813;
	local[1] = NIL;
KEY9813:
	if (n & (1<<2)) goto KEY9818;
	local[2] = NIL;
KEY9818:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUPERMEMBER(ctx,5,local+3); /*supermember*/
	local[0]= w;
BLK9795:
	ctx->vsp=local; return(local[0]);}

/*assoc*/
static pointer F4642(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[88], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9849;
	local[0] = NIL;
KEY9849:
	if (n & (1<<1)) goto KEY9854;
	local[1] = NIL;
KEY9854:
	if (n & (1<<2)) goto KEY9859;
	local[2] = NIL;
KEY9859:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUPERASSOC(ctx,5,local+3); /*superassoc*/
	local[0]= w;
BLK9836:
	ctx->vsp=local; return(local[0]);}

/*subsetp*/
static pointer F4644(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[89], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9890;
	local[0] = NIL;
KEY9890:
	if (n & (1<<1)) goto KEY9895;
	local[1] = NIL;
KEY9895:
	if (n & (1<<2)) goto KEY9900;
	local[2] = NIL;
KEY9900:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO9910,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F4786(ctx,2,local+3); /*every*/
	local[0]= w;
BLK9877:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO9910(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= fqv[25];
	local[3]= env->c.clo.env2[0];
	local[4]= fqv[23];
	local[5]= env->c.clo.env2[1];
	local[6]= fqv[24];
	local[7]= env->c.clo.env2[2];
	ctx->vsp=local+8;
	w=(pointer)F4640(ctx,8,local+0); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*maplist*/
static pointer F4646(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST9942:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF9959;
	local[3]= NIL;
	local[4]= NIL;
WHL9976:
	if (argv[1]==NIL) goto WHX9977;
	local[3] = NIL;
	local[5]= argv[1];
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[4] = local[0];
WHL10020:
	if (local[4]==NIL) goto WHX10021;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	local[5]= local[4];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)RPLACA2(ctx,2,local+5); /*rplaca2*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	goto WHL10020;
WHX10021:
	local[5]= NIL;
BLK10022:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL9976;
WHX9977:
	local[5]= NIL;
BLK9978:
	w = local[5];
	local[3]= w;
	goto IF9960;
IF9959:
WHL10084:
	if (argv[1]==NIL) goto WHX10085;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	goto WHL10084;
WHX10085:
	local[3]= NIL;
BLK10086:
IF9960:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK9940:
	ctx->vsp=local; return(local[0]);}

/*mapcon*/
static pointer F4648(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST10125:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF10142;
	local[3]= NIL;
	local[4]= NIL;
WHL10159:
	if (argv[1]==NIL) goto WHX10160;
	local[3] = NIL;
	local[5]= argv[1];
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[4] = local[0];
WHL10203:
	if (local[4]==NIL) goto WHX10204;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	local[5]= local[4];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)RPLACA2(ctx,2,local+5); /*rplaca2*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	goto WHL10203;
WHX10204:
	local[5]= NIL;
BLK10205:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[2] = w;
	goto WHL10159;
WHX10160:
	local[5]= NIL;
BLK10161:
	w = local[5];
	local[3]= w;
	goto IF10143;
IF10142:
WHL10265:
	if (argv[1]==NIL) goto WHX10266;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	local[2] = w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	goto WHL10265;
WHX10266:
	local[3]= NIL;
BLK10267:
IF10143:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK10123:
	ctx->vsp=local; return(local[0]);}

/*find*/
static pointer F4650(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[90], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10317;
	local[0] = makeint(0);
KEY10317:
	if (n & (1<<1)) goto KEY10322;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10322:
	if (n & (1<<2)) goto KEY10330;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10330:
	if (n & (1<<3)) goto KEY10337;
	local[3] = NIL;
KEY10337:
	if (n & (1<<4)) goto KEY10342;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10342:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)FIND(ctx,9,local+5); /*system::raw-find*/
	local[0]= w;
BLK10302:
	ctx->vsp=local; return(local[0]);}

/*find-if*/
static pointer F4652(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[91], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10377;
	local[0] = makeint(0);
KEY10377:
	if (n & (1<<1)) goto KEY10382;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10382:
	if (n & (1<<2)) goto KEY10390;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10390:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)FIND(ctx,9,local+3); /*system::raw-find*/
	local[0]= w;
BLK10364:
	ctx->vsp=local; return(local[0]);}

/*find-if-not*/
static pointer F4654(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[92], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10423;
	local[0] = makeint(0);
KEY10423:
	if (n & (1<<1)) goto KEY10428;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10428:
	if (n & (1<<2)) goto KEY10436;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10436:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)FIND(ctx,9,local+3); /*system::raw-find*/
	local[0]= w;
BLK10410:
	ctx->vsp=local; return(local[0]);}

/*position*/
static pointer F4656(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[93], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10471;
	local[0] = makeint(0);
KEY10471:
	if (n & (1<<1)) goto KEY10476;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10476:
	if (n & (1<<2)) goto KEY10484;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10484:
	if (n & (1<<3)) goto KEY10491;
	local[3] = NIL;
KEY10491:
	if (n & (1<<4)) goto KEY10496;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10496:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)POSITION(ctx,9,local+5); /*system::raw-position*/
	local[0]= w;
BLK10456:
	ctx->vsp=local; return(local[0]);}

/*position-if*/
static pointer F4658(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[94], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10531;
	local[0] = makeint(0);
KEY10531:
	if (n & (1<<1)) goto KEY10536;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10536:
	if (n & (1<<2)) goto KEY10544;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10544:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)POSITION(ctx,9,local+3); /*system::raw-position*/
	local[0]= w;
BLK10518:
	ctx->vsp=local; return(local[0]);}

/*position-if-not*/
static pointer F4660(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[95], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10577;
	local[0] = makeint(0);
KEY10577:
	if (n & (1<<1)) goto KEY10582;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10582:
	if (n & (1<<2)) goto KEY10590;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10590:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)POSITION(ctx,9,local+3); /*system::raw-position*/
	local[0]= w;
BLK10564:
	ctx->vsp=local; return(local[0]);}

/*count*/
static pointer F4662(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[96], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10625;
	local[0] = makeint(0);
KEY10625:
	if (n & (1<<1)) goto KEY10630;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10630:
	if (n & (1<<2)) goto KEY10638;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10638:
	if (n & (1<<3)) goto KEY10645;
	local[3] = NIL;
KEY10645:
	if (n & (1<<4)) goto KEY10650;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10650:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)COUNT(ctx,9,local+5); /*system::raw-count*/
	local[0]= w;
BLK10610:
	ctx->vsp=local; return(local[0]);}

/*count-if*/
static pointer F4664(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[97], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10685;
	local[0] = makeint(0);
KEY10685:
	if (n & (1<<1)) goto KEY10690;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10690:
	if (n & (1<<2)) goto KEY10698;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10698:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)COUNT(ctx,9,local+3); /*system::raw-count*/
	local[0]= w;
BLK10672:
	ctx->vsp=local; return(local[0]);}

/*count-if-not*/
static pointer F4666(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[98], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10731;
	local[0] = makeint(0);
KEY10731:
	if (n & (1<<1)) goto KEY10736;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10736:
	if (n & (1<<2)) goto KEY10744;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10744:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)COUNT(ctx,9,local+3); /*system::raw-count*/
	local[0]= w;
BLK10718:
	ctx->vsp=local; return(local[0]);}

/*member-if*/
static pointer F4668(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[99], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10775;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY10775:
WHL10786:
	if (argv[1]==NIL) goto WHX10787;
	local[1]= argv[0];
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w==NIL) goto IF10794;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK10764;
	goto IF10795;
IF10794:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[1]= argv[1];
IF10795:
	goto WHL10786;
WHX10787:
	local[1]= NIL;
BLK10788:
	w = local[1];
	local[0]= w;
BLK10764:
	ctx->vsp=local; return(local[0]);}

/*member-if-not*/
static pointer F4670(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[100], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10837;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY10837:
WHL10848:
	if (argv[1]==NIL) goto WHX10849;
	local[1]= argv[0];
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w!=NIL) goto IF10856;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK10826;
	goto IF10857;
IF10856:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[1]= argv[1];
IF10857:
	goto WHL10848;
WHX10849:
	local[1]= NIL;
BLK10850:
	w = local[1];
	local[0]= w;
BLK10826:
	ctx->vsp=local; return(local[0]);}

/*collect-if*/
static pointer F4672(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL10921:
	if (local[3]==NIL) goto WHX10922;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,2,local+4); /*funcall*/
	if (w==NIL) goto IF10970;
	local[4]= local[2];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF10971;
IF10970:
	local[4]= NIL;
IF10971:
	goto WHL10921;
WHX10922:
	local[4]= NIL;
BLK10923:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK10888:
	ctx->vsp=local; return(local[0]);}

/*collect-instances*/
static pointer F4674(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO11012,env,argv,local);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F4610(ctx,1,local+1); /*flatten*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F4672(ctx,2,local+0); /*collect-if*/
	local[0]= w;
BLK10999:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11012(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*pairlis*/
static pointer F4676(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT11038;}
	local[0]= NIL;
ENT11038:
ENT11037:
	if (n>3) maerror();
	if (argv[0]==NIL) goto IF11054;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4676(ctx,3,local+2); /*pairlis*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF11055;
IF11054:
	local[1]= local[0];
IF11055:
	w = local[1];
	local[0]= w;
BLK11035:
	ctx->vsp=local; return(local[0]);}

/*transpose-list*/
static pointer F4678(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL11139:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX11140;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO11153,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL11139;
WHX11140:
	local[3]= NIL;
BLK11141:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK11091:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11153(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-list*/
static pointer F4680(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[101], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY11207;
	local[0] = NIL;
KEY11207:
	local[1]= NIL;
	w = argv[0];
	if (isint(w)) goto IF11226;
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF11227;
IF11226:
	local[2]= NIL;
IF11227:
	local[2]= makeint(0);
	local[3]= argv[0];
WHL11261:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX11262;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL11261;
WHX11262:
	local[4]= NIL;
BLK11263:
	w = local[1];
	local[0]= w;
BLK11198:
	ctx->vsp=local; return(local[0]);}

/*make-sequence*/
static pointer F4682(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[103], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11309;
	local[0] = NIL;
KEY11309:
	local[1]= argv[0];
	w = fqv[104];
	if (memq(local[1],w)!=NIL) goto OR11320;
	local[1]= argv[0];
	if (loadglobal(fqv[19])==local[1]) goto OR11320;
	goto IF11318;
OR11320:
	local[1]= argv[1];
	local[2]= fqv[105];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F4680(ctx,3,local+1); /*make-list*/
	local[1]= w;
	goto IF11319;
IF11318:
	local[1]= argv[1];
	local[2]= fqv[106];
	local[3]= argv[0];
	local[4]= fqv[105];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,5,local+1,&ftab[0],fqv[107]); /*make-array*/
	local[1]= w;
IF11319:
	w = local[1];
	local[0]= w;
BLK11298:
	ctx->vsp=local; return(local[0]);}

/*fill*/
static pointer F4684(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[108], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11366;
	local[0] = makeint(0);
KEY11366:
	if (n & (1<<1)) goto KEY11371;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY11371:
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)FILL(ctx,4,local+2); /*system::raw-fill*/
	local[0]= w;
BLK11354:
	ctx->vsp=local; return(local[0]);}

/*replace*/
static pointer F4686(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[109], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11405;
	local[0] = makeint(0);
KEY11405:
	if (n & (1<<1)) goto KEY11410;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11410:
	if (n & (1<<2)) goto KEY11418;
	local[2] = makeint(0);
KEY11418:
	if (n & (1<<3)) goto KEY11423;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[3] = w;
KEY11423:
	local[4]= argv[0];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[5]= w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11465;
	local[6]= local[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[0] = w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11485;
	local[6]= local[2];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[1] = w;
	local[6]= makeint(0);
	local[7]= local[5];
WHL11526:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX11527;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= w;
	*(ovafptr(argv[0],fqv[16])) = local[9];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL11526;
WHX11527:
	local[8]= NIL;
BLK11528:
	w = NIL;
	local[6]= w;
	goto CON11483;
CON11485:
	local[6]= makeint(0);
	local[7]= local[5];
WHL11649:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX11650;
	local[8]= argv[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= w;
	*(ovafptr(argv[0],fqv[16])) = local[9];
	local[2] = (pointer)((integer_t)(local[2])+4);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL11649;
WHX11650:
	local[8]= NIL;
BLK11651:
	w = NIL;
	local[6]= w;
	goto CON11483;
CON11622:
	local[6]= NIL;
CON11483:
	goto CON11463;
CON11465:
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11725;
	local[6]= local[2];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[1] = w;
	local[6]= makeint(0);
	local[7]= local[5];
WHL11766:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX11767;
	local[8]= argv[0];
	local[9]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[10];
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL11766;
WHX11767:
	local[8]= NIL;
BLK11768:
	w = NIL;
	local[6]= w;
	goto CON11463;
CON11725:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)VECREPLACE(ctx,6,local+6); /*system::vector-replace*/
	local[6]= w;
	goto CON11463;
CON11837:
	local[6]= NIL;
CON11463:
	w = local[4];
	local[0]= w;
BLK11391:
	ctx->vsp=local; return(local[0]);}

/*remove*/
static pointer F4688(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[110], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11871;
	local[0] = makeint(0);
KEY11871:
	if (n & (1<<1)) goto KEY11876;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY11876:
	if (n & (1<<2)) goto KEY11884;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY11884:
	if (n & (1<<3)) goto KEY11891;
	local[3] = NIL;
KEY11891:
	if (n & (1<<4)) goto KEY11896;
	local[4] = makeint(1000000);
KEY11896:
	if (n & (1<<5)) goto KEY11901;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY11901:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)UNIREMOVE(ctx,10,local+6); /*system::universal-remove*/
	local[0]= w;
BLK11855:
	ctx->vsp=local; return(local[0]);}

/*remove-if*/
static pointer F4690(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[111], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11938;
	local[0] = makeint(0);
KEY11938:
	if (n & (1<<1)) goto KEY11943;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11943:
	if (n & (1<<2)) goto KEY11951;
	local[2] = makeint(1000000);
KEY11951:
	if (n & (1<<3)) goto KEY11956;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11956:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)UNIREMOVE(ctx,10,local+4); /*system::universal-remove*/
	local[0]= w;
BLK11924:
	ctx->vsp=local; return(local[0]);}

/*remove-if-not*/
static pointer F4692(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[112], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11991;
	local[0] = makeint(0);
KEY11991:
	if (n & (1<<1)) goto KEY11996;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11996:
	if (n & (1<<2)) goto KEY12004;
	local[2] = makeint(1000000);
KEY12004:
	if (n & (1<<3)) goto KEY12009;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12009:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)UNIREMOVE(ctx,10,local+4); /*system::universal-remove*/
	local[0]= w;
BLK11977:
	ctx->vsp=local; return(local[0]);}

/*delete*/
static pointer F4694(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[113], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY12046;
	local[0] = makeint(0);
KEY12046:
	if (n & (1<<1)) goto KEY12051;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY12051:
	if (n & (1<<2)) goto KEY12059;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY12059:
	if (n & (1<<3)) goto KEY12066;
	local[3] = NIL;
KEY12066:
	if (n & (1<<4)) goto KEY12071;
	local[4] = makeint(1000000);
KEY12071:
	if (n & (1<<5)) goto KEY12076;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12076:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)DELETE(ctx,10,local+6); /*system::raw-delete*/
	local[0]= w;
BLK12030:
	ctx->vsp=local; return(local[0]);}

/*delete-if*/
static pointer F4696(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[114], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY12113;
	local[0] = makeint(0);
KEY12113:
	if (n & (1<<1)) goto KEY12118;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12118:
	if (n & (1<<2)) goto KEY12126;
	local[2] = makeint(1000000);
KEY12126:
	if (n & (1<<3)) goto KEY12131;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12131:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)DELETE(ctx,10,local+4); /*system::raw-delete*/
	local[0]= w;
BLK12099:
	ctx->vsp=local; return(local[0]);}

/*delete-if-not*/
static pointer F4698(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[115], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY12166;
	local[0] = makeint(0);
KEY12166:
	if (n & (1<<1)) goto KEY12171;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12171:
	if (n & (1<<2)) goto KEY12179;
	local[2] = makeint(1000000);
KEY12179:
	if (n & (1<<3)) goto KEY12184;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12184:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)DELETE(ctx,10,local+4); /*system::raw-delete*/
	local[0]= w;
BLK12152:
	ctx->vsp=local; return(local[0]);}

/*substitute*/
static pointer F4700(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[116], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12223;
	local[0] = makeint(0);
KEY12223:
	if (n & (1<<1)) goto KEY12228;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY12228:
	if (n & (1<<2)) goto KEY12236;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY12236:
	if (n & (1<<3)) goto KEY12243;
	local[3] = NIL;
KEY12243:
	if (n & (1<<4)) goto KEY12248;
	local[4] = makeint(1000000);
KEY12248:
	if (n & (1<<5)) goto KEY12253;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12253:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[5];
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SUBSTITUTE(ctx,11,local+6); /*system::raw-substitute*/
	local[0]= w;
BLK12205:
	ctx->vsp=local; return(local[0]);}

/*substitute-if*/
static pointer F4702(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[117], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12293;
	local[0] = makeint(0);
KEY12293:
	if (n & (1<<1)) goto KEY12298;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12298:
	if (n & (1<<2)) goto KEY12306;
	local[2] = makeint(1000000);
KEY12306:
	if (n & (1<<3)) goto KEY12311;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12311:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= argv[1];
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)SUBSTITUTE(ctx,11,local+4); /*system::raw-substitute*/
	local[0]= w;
BLK12277:
	ctx->vsp=local; return(local[0]);}

/*substitute-if-not*/
static pointer F4704(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[118], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12349;
	local[0] = makeint(0);
KEY12349:
	if (n & (1<<1)) goto KEY12354;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12354:
	if (n & (1<<2)) goto KEY12362;
	local[2] = makeint(1000000);
KEY12362:
	if (n & (1<<3)) goto KEY12367;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12367:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= NIL;
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)SUBSTITUTE(ctx,11,local+4); /*system::raw-substitute*/
	local[0]= w;
BLK12333:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute*/
static pointer F4706(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[119], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12407;
	local[0] = makeint(0);
KEY12407:
	if (n & (1<<1)) goto KEY12412;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY12412:
	if (n & (1<<2)) goto KEY12420;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY12420:
	if (n & (1<<3)) goto KEY12427;
	local[3] = NIL;
KEY12427:
	if (n & (1<<4)) goto KEY12432;
	local[4] = makeint(1000000);
KEY12432:
	if (n & (1<<5)) goto KEY12437;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12437:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[5];
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)NSUBSTITUTE(ctx,11,local+6); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12389:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute-if*/
static pointer F4708(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[120], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12477;
	local[0] = makeint(0);
KEY12477:
	if (n & (1<<1)) goto KEY12482;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12482:
	if (n & (1<<2)) goto KEY12490;
	local[2] = makeint(1000000);
KEY12490:
	if (n & (1<<3)) goto KEY12495;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12495:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= argv[1];
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)NSUBSTITUTE(ctx,11,local+4); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12461:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute-if-not*/
static pointer F4710(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[121], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12533;
	local[0] = makeint(0);
KEY12533:
	if (n & (1<<1)) goto KEY12538;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12538:
	if (n & (1<<2)) goto KEY12546;
	local[2] = makeint(1000000);
KEY12546:
	if (n & (1<<3)) goto KEY12551;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12551:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= NIL;
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)NSUBSTITUTE(ctx,11,local+4); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12517:
	ctx->vsp=local; return(local[0]);}

/*unique*/
static pointer F4712(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (!!iscons(w)) goto CON12585;
	local[0]= argv[0];
	goto CON12583;
CON12585:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (memq(local[0],w)==NIL) goto CON12595;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F4712(ctx,1,local+0); /*unique*/
	local[0]= w;
	goto CON12583;
CON12595:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F4712(ctx,1,local+1); /*unique*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON12583;
CON12619:
	local[0]= NIL;
CON12583:
	w = local[0];
	local[0]= w;
BLK12573:
	ctx->vsp=local; return(local[0]);}

/*remove-duplicates*/
static pointer F4714(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[122], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY12652;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY12652:
	if (n & (1<<1)) goto KEY12659;
	local[1] = NIL;
KEY12659:
	if (n & (1<<2)) goto KEY12664;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY12664:
	if (n & (1<<3)) goto KEY12671;
	local[3] = makeint(0);
KEY12671:
	if (n & (1<<4)) goto KEY12676;
	local[4] = makeint(1000000);
KEY12676:
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)REMOVE_DUPLICATES(ctx,6,local+5); /*system::raw-remove-duplicates*/
	local[0]= w;
BLK12639:
	ctx->vsp=local; return(local[0]);}

/*extream*/
static pointer F4716(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT12698;}
	local[0]= (pointer)get_sym_func(fqv[82]);
ENT12698:
ENT12697:
	if (n>3) maerror();
	if (argv[0]!=NIL) goto IF12716;
	local[1]= NIL;
	goto IF12717;
IF12716:
	local[1]= argv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto IF12741;
	local[4]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL12768:
	if (local[5]==NIL) goto WHX12769;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,3,local+6); /*funcall*/
	if (w==NIL) goto IF12818;
	local[1] = local[4];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[2] = w;
	local[6]= local[2];
	goto IF12819;
IF12818:
	local[6]= NIL;
IF12819:
	goto WHL12768;
WHX12769:
	local[6]= NIL;
BLK12770:
	w = NIL;
	local[4]= w;
	goto IF12742;
IF12741:
	local[4]= makeint(0);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL12874:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX12875;
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= argv[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[3] = w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,3,local+6); /*funcall*/
	if (w==NIL) goto IF12884;
	local[1] = local[3];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[2] = w;
	local[6]= local[2];
	goto IF12885;
IF12884:
	local[6]= NIL;
IF12885:
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL12874;
WHX12875:
	local[6]= NIL;
BLK12876:
	w = NIL;
	local[4]= w;
IF12742:
	w = local[1];
	local[1]= w;
IF12717:
	w = local[1];
	local[0]= w;
BLK12695:
	ctx->vsp=local; return(local[0]);}

/*send-super-lexpr*/
static pointer F12940(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST12943:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[126];
	local[4]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[0];
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12941:
	ctx->vsp=local; return(local[0]);}

/*send-super**/
static pointer F13000(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST13003:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[126];
	local[4]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13001:
	ctx->vsp=local; return(local[0]);}

/*send-lexpr*/
static pointer F13054(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST13057:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= argv[0];
	local[4]= argv[1];
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13055:
	ctx->vsp=local; return(local[0]);}

/*send**/
static pointer F13098(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST13101:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13099:
	ctx->vsp=local; return(local[0]);}

/*send-super*/
static pointer F13130(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13133:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[125];
	local[2]= fqv[126];
	local[3]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13131:
	ctx->vsp=local; return(local[0]);}

/*send-all*/
static pointer F4724(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13182:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO13194,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK13180:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO13194(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[32];
	local[1]= argv[0];
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*resend*/
static pointer F4726(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[32];
	local[1]= argv[0];
	w = argv[1];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	local[0]= w;
BLK13217:
	ctx->vsp=local; return(local[0]);}

/*instance*/
static pointer F13243(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13246:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	if (local[0]==NIL) goto IF13257;
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= fqv[130];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[32];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF13258;
IF13257:
	local[1]= fqv[130];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF13258:
	w = local[1];
	local[0]= w;
BLK13244:
	ctx->vsp=local; return(local[0]);}

/*instance**/
static pointer F13324(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13327:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	if (local[0]==NIL) goto IF13338;
	local[1]= fqv[131];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= fqv[130];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[132];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF13339;
IF13338:
	local[1]= fqv[130];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF13339:
	w = local[1];
	local[0]= w;
BLK13325:
	ctx->vsp=local; return(local[0]);}

/*make-instance*/
static pointer F4730(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13407:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
WHL13431:
	if (local[0]==NIL) goto WHX13432;
	local[2]= local[1];
	local[3]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F4565(ctx,1,local+4); /*string*/
	local[4]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SETSLOT(ctx,4,local+2); /*setslot*/
	goto WHL13431;
WHX13432:
	local[2]= NIL;
BLK13433:
	w = local[1];
	local[0]= w;
BLK13405:
	ctx->vsp=local; return(local[0]);}

/*defclassmethod*/
static pointer F13521(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13524:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[133];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,1,local+2,&ftab[1],fqv[134]); /*metaclass-name*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13522:
	ctx->vsp=local; return(local[0]);}

/*delete-method*/
static pointer F4733(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= fqv[25];
	local[3]= (pointer)get_sym_func(fqv[16]);
	ctx->vsp=local+4;
	w=(pointer)F4694(ctx,4,local+0); /*delete*/
	local[0]= w;
	local[1]= w;
	w = argv[0];
	w->c.obj.iv[7] = local[1];
	local[0]= T;
	ctx->vsp=local+1;
	w=(pointer)METHCACHE(ctx,1,local+0); /*system::method-cache*/
	local[0]= w;
BLK13555:
	ctx->vsp=local; return(local[0]);}

/*make-class*/
static pointer F4735(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[135], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY13608;
	local[0] = loadglobal(fqv[136]);
KEY13608:
	if (n & (1<<1)) goto KEY13615;
	local[1] = loadglobal(fqv[136]);
KEY13615:
	if (n & (1<<2)) goto KEY13621;
	local[2] = NIL;
KEY13621:
	if (n & (1<<3)) goto KEY13626;
	local[3] = NIL;
KEY13626:
	if (n & (1<<4)) goto KEY13631;
	local[4] = NIL;
KEY13631:
	if (n & (1<<5)) goto KEY13636;
	local[5] = NIL;
KEY13636:
	if (n & (1<<6)) goto KEY13641;
	local[6] = NIL;
KEY13641:
	if (n & (1<<7)) goto KEY13646;
	local[7] = NIL;
KEY13646:
	if (n & (1<<8)) goto KEY13651;
	local[8] = makeint(-1);
KEY13651:
	if (n & (1<<9)) goto KEY13656;
	local[9] = NIL;
KEY13656:
	if (n & (1<<10)) goto KEY13661;
	local[10] = NIL;
KEY13661:
	w = local[0];
	if (!issymbol(w)) goto IF13670;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SYMVALUE(ctx,1,local+11); /*symbol-value*/
	local[0] = w;
	local[11]= local[0];
	goto IF13671;
IF13670:
	local[11]= NIL;
IF13671:
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)BOUNDP(ctx,1,local+11); /*boundp*/
	if (w==NIL) goto IF13692;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SYMVALUE(ctx,1,local+11); /*symbol-value*/
	local[11]= w;
	goto IF13693;
IF13692:
	local[11]= NIL;
IF13693:
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= makeint(0);
	local[17]= NIL;
	local[18]= NIL;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)CLASSP(ctx,1,local+19); /*classp*/
	if (w!=NIL) goto CON13729;
	local[19]= local[6];
	if (local[19]!=NIL) goto CON13737;
CON13739:
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)CLASSP(ctx,1,local+19); /*classp*/
	local[19]= w;
	if (w!=NIL) goto CON13737;
CON13743:
	if (local[0]==NIL) goto CON13749;
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)GETCLASS(ctx,1,local+19); /*class*/
	local[6] = w;
	local[19]= local[6];
	goto CON13737;
CON13749:
	local[19]= fqv[137];
	ctx->vsp=local+20;
	w=(pointer)SYMVALUE(ctx,1,local+19); /*symbol-value*/
	local[6] = w;
	local[19]= local[6];
	goto CON13737;
CON13762:
	local[19]= NIL;
CON13737:
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,1,local+19); /*instantiate*/
	local[11] = w;
	local[19]= local[11];
	goto CON13727;
CON13729:
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)GETCLASS(ctx,1,local+19); /*class*/
	local[6] = w;
	local[19]= local[6];
	goto CON13727;
CON13783:
	local[19]= NIL;
CON13727:
	local[19]= *(ovafptr(local[0],fqv[138]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[12] = w;
	local[19]= *(ovafptr(local[0],fqv[139]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[13] = w;
	local[19]= *(ovafptr(local[0],fqv[140]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[14] = w;
	local[19]= NIL;
	local[20]= local[9];
WHL13844:
	if (local[20]==NIL) goto WHX13845;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w = local[19];
	if (!iscons(w)) goto CON13895;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= local[12];
	ctx->vsp=local+23;
	w=(pointer)F4640(ctx,2,local+21); /*member*/
	if (w==NIL) goto IF13901;
	local[21]= fqv[141];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto IF13902;
IF13901:
	local[21]= NIL;
IF13902:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[12];
	ctx->vsp=local+22;
	local[12] = cons(ctx,local[21],w);
	local[21]= fqv[142];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)F4656(ctx,2,local+21); /*position*/
	local[18] = w;
	if (local[18]==NIL) goto IF13948;
	local[21]= local[19];
	local[22]= (pointer)((integer_t)(local[18])+4);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	goto IF13949;
IF13948:
	local[21]= T;
IF13949:
	w = local[13];
	ctx->vsp=local+22;
	local[13] = cons(ctx,local[21],w);
	local[21]= fqv[143];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)F4656(ctx,2,local+21); /*position*/
	local[18] = w;
	if (local[18]==NIL) goto IF13983;
	local[21]= local[19];
	local[22]= (pointer)((integer_t)(local[18])+4);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	goto IF13984;
IF13983:
	local[21]= NIL;
IF13984:
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto CON13893;
CON13895:
	w = local[19];
	if (!issymbol(w)) goto CON14001;
	local[21]= local[19];
	local[22]= local[12];
	ctx->vsp=local+23;
	w=(pointer)F4640(ctx,2,local+21); /*member*/
	if (w==NIL) goto IF14007;
	local[21]= fqv[144];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto IF14008;
IF14007:
	local[21]= NIL;
IF14008:
	local[21]= local[19];
	w = local[12];
	ctx->vsp=local+22;
	local[12] = cons(ctx,local[21],w);
	local[21]= T;
	w = local[13];
	ctx->vsp=local+22;
	local[13] = cons(ctx,local[21],w);
	local[21]= NIL;
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto CON13893;
CON14001:
	local[21]= fqv[145];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto CON13893;
CON14051:
	local[21]= NIL;
CON13893:
	goto WHL13844;
WHX13845:
	local[21]= NIL;
BLK13846:
	w = NIL;
	local[19]= local[12];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[12] = w;
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[13] = w;
	local[19]= local[14];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[14] = w;
	local[19]= local[7];
	local[20]= fqv[147];
	ctx->vsp=local+21;
	w=(pointer)ASSQ(ctx,2,local+19); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	if (local[15]!=NIL) goto IF14105;
	local[19]= local[6];
	local[20]= loadglobal(fqv[148]);
	ctx->vsp=local+21;
	w=(pointer)SUBCLASSP(ctx,2,local+19); /*subclassp*/
	if (w==NIL) goto IF14113;
	local[19]= local[0]->c.obj.iv[8];
	goto IF14114;
IF14113:
	local[19]= makeint(0);
IF14114:
	local[15] = local[19];
	local[19]= local[15];
	goto IF14106;
IF14105:
	local[19]= NIL;
IF14106:
	local[19]= argv[0];
	*(ovafptr(local[11],fqv[149])) = local[19];
	local[19]= local[12];
	*(ovafptr(local[11],fqv[138])) = local[19];
	local[19]= local[13];
	*(ovafptr(local[11],fqv[139])) = local[19];
	local[19]= local[14];
	*(ovafptr(local[11],fqv[140])) = local[19];
	local[19]= local[0];
	local[20]= local[19];
	*(ovafptr(local[11],fqv[128])) = local[20];
	local[19]= local[6];
	local[20]= loadglobal(fqv[148]);
	ctx->vsp=local+21;
	w=(pointer)SUBCLASSP(ctx,2,local+19); /*subclassp*/
	if (w==NIL) goto IF14149;
	local[19]= local[15];
	*(ovafptr(local[11],fqv[150])) = local[19];
	local[19]= local[8];
	local[20]= local[19];
	*(ovafptr(local[11],fqv[151])) = local[20];
	goto IF14150;
IF14149:
	local[19]= NIL;
IF14150:
	if (*(ovafptr(local[11],fqv[152]))!=NIL) goto IF14167;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(*ftab[2])(ctx,1,local+19,&ftab[2],fqv[153]); /*enter-class*/
	local[19]= w;
	goto IF14168;
IF14167:
	local[19]= NIL;
IF14168:
	local[19]= argv[0];
	local[20]= local[10];
	local[21]= fqv[154];
	ctx->vsp=local+22;
	w=(pointer)PUTPROP(ctx,3,local+19); /*putprop*/
	local[19]= local[12];
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[12] = w;
	local[19]= NIL;
	local[20]= local[12];
WHL14213:
	if (local[20]==NIL) goto WHX14214;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[21]= loadglobal(fqv[155]);
	local[22]= argv[0];
	ctx->vsp=local+23;
	w=(pointer)F4565(ctx,1,local+22); /*string*/
	local[22]= w;
	local[23]= fqv[156];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)F4565(ctx,1,local+24); /*string*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)CONCATENATE(ctx,4,local+21); /*concatenate*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[17] = w;
	local[21]= local[17];
	local[22]= fqv[157];
	local[23]= fqv[158];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	local[24]= fqv[66];
	local[25]= fqv[33];
	local[26]= fqv[159];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	local[26]= fqv[158];
	local[27]= fqv[33];
	local[28]= argv[0];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= local[16];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	local[22]= cons(ctx,local[22],w);
	ctx->vsp=local+23;
	w=(pointer)SETFUNC(ctx,2,local+21); /*setfunc*/
	local[16] = (pointer)((integer_t)(local[16])+4);
	goto WHL14213;
WHX14214:
	local[21]= NIL;
BLK14215:
	w = NIL;
	w = local[11];
	local[0]= w;
BLK13589:
	ctx->vsp=local; return(local[0]);}

/*defstruct*/
static pointer F14350(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST14353:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[6];
	local[2]= fqv[32];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[38];
	local[5]= fqv[160];
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[161];
	local[8]= fqv[33];
	local[9]= local[0];
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
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK14351:
	ctx->vsp=local; return(local[0]);}

/*defclass*/
static pointer F14432(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[162], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY14448;
	local[0] = NIL;
KEY14448:
	if (n & (1<<1)) goto KEY14453;
	local[1] = fqv[136];
KEY14453:
	if (n & (1<<2)) goto KEY14460;
	local[2] = makeint(-1);
KEY14460:
	if (n & (1<<3)) goto KEY14465;
	local[3] = NIL;
KEY14465:
	if (n & (1<<4)) goto KEY14470;
	local[4] = NIL;
KEY14470:
	if (n & (1<<5)) goto KEY14475;
	local[5] = NIL;
KEY14475:
	if (n & (1<<6)) goto KEY14480;
	local[6] = local[5];
KEY14480:
	local[7]= fqv[6];
	local[8]= fqv[32];
	local[9]= fqv[33];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[38];
	local[11]= fqv[160];
	local[12]= fqv[33];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[163];
	local[14]= local[1];
	local[15]= fqv[161];
	local[16]= fqv[33];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[164];
	local[18]= local[3];
	local[19]= fqv[106];
	local[20]= local[4];
	local[21]= fqv[165];
	local[22]= local[2];
	local[23]= fqv[166];
	local[24]= local[6];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[33];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	local[0]= w;
BLK14433:
	ctx->vsp=local; return(local[0]);}

/*readtablep*/
static pointer F4741(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[167]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14605:
	ctx->vsp=local; return(local[0]);}

/*copy-readtable*/
static pointer F4743(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT14626;}
	local[0]= loadglobal(fqv[168]);
ENT14626:
	if (n>=2) { local[1]=(argv[1]); goto ENT14625;}
	local[1]= NIL;
ENT14625:
ENT14624:
	if (n>2) maerror();
	if (local[0]!=NIL) goto IF14645;
	local[0] = loadglobal(fqv[169]);
	local[2]= local[0];
	goto IF14646;
IF14645:
	local[2]= NIL;
IF14646:
	if (local[1]!=NIL) goto IF14663;
	local[2]= loadglobal(fqv[167]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[1] = w;
	local[2]= loadglobal(fqv[155]);
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[1] = local[3];
	local[2]= loadglobal(fqv[146]);
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[2] = local[3];
	local[2]= loadglobal(fqv[146]);
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[3] = local[3];
	goto IF14664;
IF14663:
	local[2]= NIL;
IF14664:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F4741(ctx,1,local+2); /*readtablep*/
	if (w==NIL) goto OR14711;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F4741(ctx,1,local+2); /*readtablep*/
	if (w==NIL) goto OR14711;
	goto IF14709;
OR14711:
	local[2]= fqv[170];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF14710;
IF14709:
	local[2]= NIL;
IF14710:
	local[2]= local[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F4686(ctx,2,local+2); /*replace*/
	local[2]= local[1]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)F4686(ctx,2,local+2); /*replace*/
	local[2]= local[1]->c.obj.iv[3];
	local[3]= local[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)F4686(ctx,2,local+2); /*replace*/
	local[2]= local[0]->c.obj.iv[4];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[4] = local[3];
	w = local[1];
	local[0]= w;
BLK14622:
	ctx->vsp=local; return(local[0]);}

/*set-syntax-from-char*/
static pointer F4745(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT14785;}
	local[0]= loadglobal(fqv[168]);
ENT14785:
	if (n>=4) { local[1]=(argv[3]); goto ENT14784;}
	local[1]= loadglobal(fqv[169]);
ENT14784:
ENT14783:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[2] = w;
	local[3]= local[0]->c.obj.iv[1];
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= local[2];
	if (makeint(7)==local[3]) goto OR14843;
	local[3]= local[2];
	if (makeint(8)==local[3]) goto OR14843;
	goto IF14841;
OR14843:
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[0];
	local[5]= local[1]->c.obj.iv[2];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= w;
	goto IF14842;
IF14841:
	local[3]= NIL;
IF14842:
	w = local[2];
	local[0]= w;
BLK14781:
	ctx->vsp=local; return(local[0]);}

/*keywordp*/
static pointer F4749(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND14892;
	local[0]= argv[0]->c.obj.iv[5];
	local[0]= ((loadglobal(fqv[171]))==(local[0])?T:NIL);
AND14892:
	w = local[0];
	local[0]= w;
BLK14876:
	ctx->vsp=local; return(local[0]);}

/*constantp*/
static pointer F4751(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF14926;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4749(ctx,1,local+0); /*keywordp*/
	if (w!=NIL) goto OR14934;
	local[0]= argv[0]->c.obj.iv[2];
	if (makeint(0)==local[0]) goto OR14934;
	goto IF14932;
OR14934:
	local[0]= T;
	goto IF14933;
IF14932:
	local[0]= NIL;
IF14933:
	goto IF14927;
IF14926:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF14946;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[33]!=local[0]) goto IF14954;
	local[0]= T;
	goto IF14955;
IF14954:
	local[0]= NIL;
IF14955:
	goto IF14947;
IF14946:
	w = argv[0];
	if (!!iscons(w)) goto IF14966;
	local[0]= T;
	goto IF14967;
IF14966:
	local[0]= NIL;
IF14967:
IF14947:
IF14927:
	w = local[0];
	local[0]= w;
BLK14910:
	ctx->vsp=local; return(local[0]);}

/*functionp*/
static pointer F4753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto CON14986;
	local[0]= NIL;
	goto CON14984;
CON14986:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON14991;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w = fqv[172];
	if (memq(local[0],w)!=NIL) goto OR15001;
	goto IF14999;
OR15001:
	local[0]= T;
	goto IF15000;
IF14999:
	local[0]= NIL;
IF15000:
	goto CON14984;
CON14991:
	local[0]= argv[0];
	local[1]= loadglobal(fqv[173]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON15015;
	local[0]= argv[0]->c.obj.iv[2];
	local[0]= ((makeint(0))==(local[0])?T:NIL);
	goto CON14984;
CON15015:
	w = argv[0];
	if (!issymbol(w)) goto CON15032;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto CON15032;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F4753(ctx,1,local+0); /*functionp*/
	local[0]= w;
	goto CON14984;
CON15032:
	local[0]= NIL;
	goto CON14984;
CON15048:
	local[0]= NIL;
CON14984:
	w = local[0];
	local[0]= w;
BLK14974:
	ctx->vsp=local; return(local[0]);}

/*vector-class-p*/
static pointer F4755(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[148]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK15054:
	ctx->vsp=local; return(local[0]);}

/*compiled-function-p*/
static pointer F4757(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[173]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK15070:
	ctx->vsp=local; return(local[0]);}

/*input-stream-p*/
static pointer F4759(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[174]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND15106;
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((fqv[175])==(local[0])?T:NIL);
AND15106:
	if (local[0]!=NIL) goto OR15102;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
OR15102:
	w = local[0];
	local[0]= w;
BLK15086:
	ctx->vsp=local; return(local[0]);}

/*output-stream-p*/
static pointer F4761(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[174]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND15151;
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((fqv[177])==(local[0])?T:NIL);
AND15151:
	if (local[0]!=NIL) goto OR15147;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
OR15147:
	w = local[0];
	local[0]= w;
BLK15131:
	ctx->vsp=local; return(local[0]);}

/*io-stream-p*/
static pointer F4763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK15174:
	ctx->vsp=local; return(local[0]);}

/*special-form-p*/
static pointer F4765(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND15200;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND15200;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	argv[0] = w;
	local[0]= argv[0];
	if (local[0]==NIL) goto AND15200;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4757(ctx,1,local+0); /*compiled-function-p*/
	local[0]= w;
	if (w==NIL) goto AND15200;
	local[0]= *(ovafptr(argv[0],fqv[178]));
	local[0]= ((makeint(2))==(local[0])?T:NIL);
AND15200:
	w = local[0];
	local[0]= w;
BLK15190:
	ctx->vsp=local; return(local[0]);}

/*macro-function*/
static pointer F4767(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND15246;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND15246;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	argv[0] = w;
	local[0]= argv[0];
	if (local[0]==NIL) goto AND15246;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4757(ctx,1,local+0); /*compiled-function-p*/
	if (w==NIL) goto IF15270;
	local[0]= *(ovafptr(argv[0],fqv[178]));
	if (makeint(1)!=local[0]) goto IF15270;
	local[0]= argv[0];
	goto IF15271;
IF15270:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF15284;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[157]!=local[0]) goto IF15284;
	local[0]= argv[0];
	goto IF15285;
IF15284:
	local[0]= NIL;
IF15285:
IF15271:
AND15246:
	w = local[0];
	local[0]= w;
BLK15236:
	ctx->vsp=local; return(local[0]);}

/*zerop*/
static pointer F4769(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
BLK15305:
	ctx->vsp=local; return(local[0]);}

/*plusp*/
static pointer F4771(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
BLK15320:
	ctx->vsp=local; return(local[0]);}

/*minusp*/
static pointer F4773(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
BLK15335:
	ctx->vsp=local; return(local[0]);}

/*oddp*/
static pointer F4775(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGBITP(ctx,2,local+0); /*logbitp*/
	local[0]= w;
BLK15350:
	ctx->vsp=local; return(local[0]);}

/*evenp*/
static pointer F4777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGBITP(ctx,2,local+0); /*logbitp*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK15365:
	ctx->vsp=local; return(local[0]);}

/*/=*/
static pointer F4779(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK15384:
	ctx->vsp=local; return(local[0]);}

/*logandc1*/
static pointer F4781(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LOGNOT(ctx,1,local+0); /*lognot*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	local[0]= w;
BLK15406:
	ctx->vsp=local; return(local[0]);}

/*logandc2*/
static pointer F4783(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGNOT(ctx,1,local+1); /*lognot*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	local[0]= w;
BLK15428:
	ctx->vsp=local; return(local[0]);}

/*ecase*/
static pointer F15450(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST15453:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[179];
	w = local[0];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK15451:
	ctx->vsp=local; return(local[0]);}

/*every*/
static pointer F4786(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST15473:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto CON15488;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON15488;
WHL15500:
	if (argv[1]==NIL) goto WHX15501;
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w!=NIL) goto IF15509;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK15471;
	goto IF15510;
IF15509:
	local[1]= NIL;
IF15510:
	goto WHL15500;
WHX15501:
	local[1]= NIL;
BLK15502:
	goto CON15486;
CON15488:
	local[1]= argv[1];
	w = local[0];
	ctx->vsp=local+2;
	argv[1] = cons(ctx,local[1],w);
	local[1]= makeint(0);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL15601:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX15602;
	local[3]= argv[0];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO15618,env,argv,local);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	if (w!=NIL) goto IF15611;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK15471;
	goto IF15612;
IF15611:
	local[3]= NIL;
IF15612:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL15601;
WHX15602:
	local[3]= NIL;
BLK15603:
	w = NIL;
	local[1]= w;
	goto CON15486;
CON15557:
	local[1]= NIL;
CON15486:
	w = T;
	local[0]= w;
BLK15471:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO15618(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*some*/
static pointer F4788(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST15664:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
	w = local[0];
	ctx->vsp=local+4;
	argv[1] = cons(ctx,local[3],w);
	local[3]= makeint(0);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL15721:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX15722;
	local[5]= argv[0];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO15739,env,argv,local);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[2] = w;
	if (local[2]==NIL) goto IF15730;
	w = local[2];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK15662;
	goto IF15731;
IF15730:
	local[5]= NIL;
IF15731:
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL15721;
WHX15722:
	local[5]= NIL;
BLK15723:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK15662:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO15739(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*reduce*/
static pointer F4792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[180], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY15800;
	local[0] = makeint(0);
KEY15800:
	if (n & (1<<1)) goto KEY15805;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY15805:
	if (n & (1<<2)) goto KEY15813;
	local[2] = NIL;
KEY15813:
	if (n & (1<<3)) goto KEY15818;
	local[3] = NIL;
KEY15818:
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	if (local[2]==NIL) goto IF15844;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	argv[1] = w;
	local[5]= argv[1];
	goto IF15845;
IF15844:
	local[5]= NIL;
IF15845:
	local[5]= local[4];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON15864;
	if (local[3]!=NIL) goto CON15864;
	local[5]= argv[1];
	goto CON15862;
CON15864:
	local[5]= local[4];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON15874;
	if (local[3]==NIL) goto IF15880;
	local[5]= local[3];
	goto IF15881;
IF15880:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,1,local+5); /*funcall*/
	local[5]= w;
IF15881:
	goto CON15862;
CON15874:
	if (local[3]!=NIL) goto IF15894;
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= argv[1];
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,3,local+5); /*funcall*/
	local[3] = w;
	local[5]= local[4];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[5]= local[0];
	goto IF15895;
IF15894:
	local[5]= NIL;
IF15895:
	local[5]= makeint(0);
	local[6]= local[4];
WHL15975:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX15976;
	local[7]= argv[0];
	local[8]= local[3];
	local[9]= argv[1];
	local[10]= local[0];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	local[3] = w;
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL15975;
WHX15976:
	local[7]= NIL;
BLK15977:
	w = NIL;
	local[5]= local[3];
	goto CON15862;
CON15889:
	local[5]= NIL;
CON15862:
	w = local[5];
	local[0]= w;
BLK15786:
	ctx->vsp=local; return(local[0]);}

/*merge-list*/
static pointer F4794(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL16050:
	if (argv[1]==NIL) goto WHX16051;
	local[7]= argv[2];
	local[8]= argv[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= argv[3];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)FUNCALL(ctx,2,local+9); /*funcall*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	if (w!=NIL) goto WHX16051;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	w = local[1];
	ctx->vsp=local+8;
	local[1] = cons(ctx,local[7],w);
	goto WHL16050;
WHX16051:
	local[7]= NIL;
BLK16052:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[1] = w;
	local[2] = argv[0];
WHL16142:
	if (argv[1]==NIL) goto WHX16143;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX16143;
	local[7]= argv[3];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[4] = w;
WHL16172:
	if (local[2]==NIL) goto WHX16173;
	local[7]= argv[2];
	local[8]= argv[3];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	if (w==NIL) goto WHX16173;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	goto WHL16172;
WHX16173:
	local[7]= NIL;
BLK16174:
	if (local[2]==NIL) goto IF16234;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	local[7]= local[2];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)RPLACD2(ctx,2,local+7); /*rplacd2*/
	local[7]= argv[1];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)RPLACD2(ctx,2,local+7); /*rplacd2*/
	local[2] = argv[1];
	argv[1] = local[6];
	local[7]= argv[1];
	goto IF16235;
IF16234:
	local[7]= NIL;
IF16235:
	goto WHL16142;
WHX16143:
	local[7]= NIL;
BLK16144:
	local[7]= local[1];
	local[8]= argv[0];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,3,local+7); /*nconc*/
	local[0]= w;
BLK16020:
	ctx->vsp=local; return(local[0]);}

/*merge*/
static pointer F4796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[181], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY16315;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY16315:
	local[1]= argv[0];
	if (loadglobal(fqv[19])!=local[1]) goto IF16326;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF16326;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF16326;
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4794(ctx,4,local+1); /*merge-list*/
	local[1]= w;
	goto IF16327;
IF16326:
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)F4682(ctx,2,local+4); /*make-sequence*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
WHL16392:
	local[11]= local[7];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto WHX16393;
	local[11]= local[5];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto CON16403;
	local[11]= argv[2];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[10] = w;
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[11]= local[6];
	goto CON16401;
CON16403:
	local[11]= local[6];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto CON16429;
	local[11]= argv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[10] = w;
	local[5] = (pointer)((integer_t)(local[5])+4);
	local[11]= local[5];
	goto CON16401;
CON16429:
	local[11]= argv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[8] = w;
	local[11]= argv[2];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[9] = w;
	local[11]= argv[3];
	local[12]= local[0];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)FUNCALL(ctx,2,local+12); /*funcall*/
	local[12]= w;
	local[13]= local[0];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)FUNCALL(ctx,2,local+13); /*funcall*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)FUNCALL(ctx,3,local+11); /*funcall*/
	if (w==NIL) goto IF16475;
	local[5] = (pointer)((integer_t)(local[5])+4);
	local[10] = local[8];
	local[11]= local[10];
	goto IF16476;
IF16475:
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[10] = local[9];
	local[11]= local[10];
IF16476:
	goto CON16401;
CON16455:
	local[11]= NIL;
CON16401:
	local[11]= local[4];
	local[12]= local[7];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL16392;
WHX16393:
	local[11]= NIL;
BLK16394:
	w = local[4];
	local[1]= w;
IF16327:
	w = local[1];
	local[0]= w;
BLK16300:
	ctx->vsp=local; return(local[0]);}

/*expt*/
static pointer F4798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!isint(w)) goto CON16569;
	local[0]= argv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON16569;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F4769(ctx,1,local+0); /*zerop*/
	if (w==NIL) goto IF16579;
	local[0]= makeint(1);
	goto IF16580;
IF16579:
	local[0]= argv[0];
	local[1]= makeint(1);
	local[2]= (pointer)((integer_t)(argv[1])-4);
WHL16615:
	local[3]= local[2];
	w = makeint(0);
	if ((integer_t)local[3] <= (integer_t)w) goto WHX16616;
	local[3]= local[2];
	w = local[1];
	if ((integer_t)local[3] <= (integer_t)w) goto CON16625;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[3]= local[2];
	w = local[1];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[2] = (pointer)((integer_t)local[3] - (integer_t)w);
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ASH(ctx,2,local+3); /*ash*/
	local[1] = w;
	local[3]= local[1];
	goto CON16623;
CON16625:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[2] = (pointer)((integer_t)(local[2])-4);
	local[3]= local[2];
	goto CON16623;
CON16657:
	local[3]= NIL;
CON16623:
	goto WHL16615;
WHX16616:
	local[3]= NIL;
BLK16617:
	w = local[0];
	local[0]= w;
IF16580:
	goto CON16567;
CON16569:
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOG(ctx,1,local+1); /*log*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)EXP(ctx,1,local+0); /*exp*/
	local[0]= w;
	goto CON16567;
CON16681:
	local[0]= NIL;
CON16567:
	w = local[0];
	local[0]= w;
BLK16555:
	ctx->vsp=local; return(local[0]);}

/*signum*/
static pointer F4800(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4769(ctx,1,local+0); /*zerop*/
	if (w==NIL) goto IF16707;
	local[0]= argv[0];
	goto IF16708;
IF16707:
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
IF16708:
	w = local[0];
	local[0]= w;
BLK16697:
	ctx->vsp=local; return(local[0]);}

/*rad2deg*/
static pointer F4802(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(3.60000000e+02);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(6.28318405e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK16724:
	ctx->vsp=local; return(local[0]);}

/*deg2rad*/
static pointer F4804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(6.28318405e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(3.60000000e+02);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK16744:
	ctx->vsp=local; return(local[0]);}

/*defsetf*/
static pointer F16763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST16766:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON16779;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (issymbol(w)) goto OR16788;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4753(ctx,1,local+1); /*functionp*/
	if (w!=NIL) goto OR16788;
	goto CON16779;
OR16788:
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[183];
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
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[186];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[182];
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)ENDP(ctx,1,local+7); /*endp*/
	if (w!=NIL) goto IF16914;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (isstring(w)) goto IF16930;
	local[7]= fqv[187];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF16931;
IF16930:
	local[7]= NIL;
IF16931:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)ENDP(ctx,1,local+7); /*endp*/
	if (w!=NIL) goto IF16949;
	local[7]= fqv[188];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF16950;
IF16949:
	local[7]= NIL;
IF16950:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	goto IF16915;
IF16914:
	local[7]= NIL;
IF16915:
	local[8]= fqv[33];
	local[9]= fqv[189];
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
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON16777;
CON16779:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[190]); /*list-length*/
	local[1]= w;
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto IF17013;
	local[1]= fqv[191];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF17014;
IF17013:
	local[1]= NIL;
IF17014:
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
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
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[183];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[186];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= argv[0];
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
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON16777;
CON17008:
	local[1]= NIL;
CON16777:
	w = local[1];
	local[0]= w;
BLK16764:
	ctx->vsp=local; return(local[0]);}

/*define-setf-method*/
static pointer F17139(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST17142:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[124];
	local[5]= fqv[192];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[186];
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
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[183];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= argv[0];
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
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK17140:
	ctx->vsp=local; return(local[0]);}

/*setf-expand-1*/
static pointer F4805(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F4526(ctx,1,local+1); /*macroexpand*/
	argv[0] = w;
	w = argv[0];
	if (!iscons(w)) goto CON17297;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[193]!=local[1]) goto CON17297;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[193];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)F4805(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17295;
CON17297:
	w = argv[0];
	if (!issymbol(w)) goto CON17340;
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17295;
CON17340:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON17356;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[183];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17356;
	local[1]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17295;
CON17356:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON17395;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[194];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17395;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	if (w==NIL) goto CON17395;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[66]==local[1]) goto CON17395;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[146]==local[1]) goto CON17395;
	local[1]= fqv[195];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17295;
CON17395:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4767(ctx,1,local+1); /*macro-function*/
	if (w==NIL) goto CON17489;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F4526(ctx,1,local+1); /*macroexpand*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F4805(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17295;
CON17489:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17506;
	local[1]= fqv[196];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,3,local+1); /*append*/
	local[1]= w;
	local[2]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto CON17295;
CON17506:
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON17295;
CON17559:
	local[1]= NIL;
CON17295:
	w = local[1];
	local[0]= w;
BLK17265:
	ctx->vsp=local; return(local[0]);}

/*setf-expand*/
static pointer F4806(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ENDP(ctx,1,local+0); /*endp*/
	if (w==NIL) goto CON17579;
	local[0]= NIL;
	goto CON17577;
CON17579:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)ENDP(ctx,1,local+0); /*endp*/
	if (w==NIL) goto CON17586;
	local[0]= fqv[198];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON17577;
CON17586:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4805(ctx,2,local+0); /*setf-expand-1*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F4806(ctx,1,local+1); /*setf-expand*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON17577;
CON17600:
	local[0]= NIL;
CON17577:
	w = local[0];
	local[0]= w;
BLK17567:
	ctx->vsp=local; return(local[0]);}

/*setf*/
static pointer F17630(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST17633:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17644;
	local[1]= NIL;
	goto CON17642;
CON17644:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17651;
	local[1]= fqv[199];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto CON17642;
CON17651:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17665;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4805(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17642;
CON17665:
	local[1]= fqv[6];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F4806(ctx,1,local+2); /*setf-expand*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17642;
CON17692:
	local[1]= NIL;
CON17642:
	w = local[1];
	local[0]= w;
BLK17631:
	ctx->vsp=local; return(local[0]);}

/*multiple-value-bind*/
static pointer F17704(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST17707:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[200];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= NIL;
	local[5]= argv[0];
WHL17751:
	if (local[5]==NIL) goto WHX17752;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[55];
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL17751;
WHX17752:
	local[6]= NIL;
BLK17753:
	w = NIL;
	local[4]= fqv[50];
	local[5]= local[1];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK17705:
	ctx->vsp=local; return(local[0]);}

/*multiple-value-setq*/
static pointer F17861(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= fqv[201];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
WHL17908:
	if (local[4]==NIL) goto WHX17909;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= fqv[202];
	ctx->vsp=local+7;
	w=(pointer)F4642(ctx,2,local+5); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL17908;
WHX17909:
	local[5]= NIL;
BLK17910:
	w = NIL;
	local[3]= fqv[5];
	local[4]= local[1];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= fqv[28];
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK17862:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___common(ctx,n,argv,env)
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
	local[0]= fqv[203];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF18039;
	local[0]= fqv[204];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[49],w);
	goto IF18040;
IF18039:
	local[0]= fqv[205];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF18040:
	local[0]= fqv[206];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[207];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[208];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[209];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[210];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[211];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[212];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[213];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[214];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F4522,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[2],module,F4523,fqv[217]);
	local[0]= NIL;
	storeglobal(fqv[218],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F4526,fqv[220]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[15],module,F5045,fqv[221]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[222],module,F5108,fqv[223]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[224],module,F5167,fqv[225]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[226],module,F5200,fqv[227]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[47],module,F5234,fqv[228]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[229],module,F5281,fqv[230]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[231],module,F5318,fqv[232]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[56],module,F5439,fqv[233]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[234],module,F5493,fqv[235]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[236],module,F5547,fqv[237]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[238],module,F5601,fqv[239]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[240],module,F5655,fqv[241]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[242],module,F5822,fqv[243]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[244],module,F5903,fqv[245]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[246],module,F5965,fqv[247]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[248],module,F6027,fqv[249]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[62],module,F6181,fqv[250]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[64],module,F6338,fqv[251]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[252],module,F6565,fqv[253]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[254],module,F6792,fqv[255]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[69],module,F6869,fqv[256]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[257],module,F7059,fqv[258]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[259],module,F7288,fqv[260]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[261],module,F7517,fqv[262]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[263],module,F7562,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F4554,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F4556,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F4558,fqv[270]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[179],module,F7743,fqv[271]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F4561,fqv[273]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[274],module,F4563,fqv[275]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[276],module,F7914,fqv[277]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F4565,fqv[278]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F4568,fqv[280]);
	local[0]= fqv[190];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)F4568(ctx,2,local+0); /*alias*/
	local[0]= fqv[281];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)F4568(ctx,2,local+0); /*alias*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F4573,fqv[283]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[284],module,F4575,fqv[285]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[286],module,F4577,fqv[287]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[288],module,F4579,fqv[289]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[290],module,F4581,fqv[291]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[292],module,F4583,fqv[293]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[294],module,F4585,fqv[295]);
	local[0]= fqv[296];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)F4568(ctx,2,local+0); /*alias*/
	local[0]= fqv[297];
	local[1]= fqv[298];
	ctx->vsp=local+2;
	w=(pointer)F4568(ctx,2,local+0); /*alias*/
	local[0]= fqv[299];
	local[1]= fqv[300];
	ctx->vsp=local+2;
	w=(pointer)F4568(ctx,2,local+0); /*alias*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[301],module,F4590,fqv[302]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F4592,fqv[304]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[305],module,F4594,fqv[306]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[307],module,F4596,fqv[308]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[309],module,F4598,fqv[310]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[311],module,F4600,fqv[312]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[313],module,F4602,fqv[314]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[315],module,F4604,fqv[316]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[317],module,F4606,fqv[318]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[319],module,F4608,fqv[320]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[321],module,F4610,fqv[322]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[323],module,F4612,fqv[324]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[325],module,F4614,fqv[326]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[327],module,F4616,fqv[328]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[329],module,F4618,fqv[330]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[331],module,F4620,fqv[332]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[333],module,F4622,fqv[334]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[335],module,F4624,fqv[336]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[337],module,F4626,fqv[338]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[339],module,F4628,fqv[340]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[341],module,F4630,fqv[342]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[343],module,F4632,fqv[344]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[345],module,F4634,fqv[346]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[347],module,F4636,fqv[348]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[349],module,F4638,fqv[350]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[22],module,F4640,fqv[351]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[352],module,F4642,fqv[353]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[354],module,F4644,fqv[355]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[356],module,F4646,fqv[357]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[358],module,F4648,fqv[359]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[360],module,F4650,fqv[361]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[362],module,F4652,fqv[363]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F4654,fqv[365]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[366],module,F4656,fqv[367]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[368],module,F4658,fqv[369]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[370],module,F4660,fqv[371]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[372],module,F4662,fqv[373]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F4664,fqv[375]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[376],module,F4666,fqv[377]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[378],module,F4668,fqv[379]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[380],module,F4670,fqv[381]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[382],module,F4672,fqv[383]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[384],module,F4674,fqv[385]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[386],module,F4676,fqv[387]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[388],module,F4678,fqv[389]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[390],module,F4680,fqv[391]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[392],module,F4682,fqv[393]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[394],module,F4684,fqv[395]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[396],module,F4686,fqv[397]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[398],module,F4688,fqv[399]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[400],module,F4690,fqv[401]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[402],module,F4692,fqv[403]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[404],module,F4694,fqv[405]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[406],module,F4696,fqv[407]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[408],module,F4698,fqv[409]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[410],module,F4700,fqv[411]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[412],module,F4702,fqv[413]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[414],module,F4704,fqv[415]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[416],module,F4706,fqv[417]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[418],module,F4708,fqv[419]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[420],module,F4710,fqv[421]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[422],module,F4712,fqv[423]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[424],module,F4714,fqv[425]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[426],module,F4716,fqv[427]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[428],module,F12940,fqv[429]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[430],module,F13000,fqv[431]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[432],module,F13054,fqv[433]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[132],module,F13098,fqv[434]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[435],module,F13130,fqv[436]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[437],module,F4724,fqv[438]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[439],module,F4726,fqv[440]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[441],module,F13243,fqv[442]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[443],module,F13324,fqv[444]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[445],module,F4730,fqv[446]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[447],module,F13521,fqv[448]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[449],module,F4733,fqv[450]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F4735,fqv[451]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[452],module,F14350,fqv[453]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[454],module,F14432,fqv[455]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[456],module,F4741,fqv[457]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[458],module,F4743,fqv[459]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[460],module,F4745,fqv[461]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[462],module,F4749,fqv[463]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[464],module,F4751,fqv[465]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[466],module,F4753,fqv[467]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[468],module,F4755,fqv[469]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[470],module,F4757,fqv[471]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[472],module,F4759,fqv[473]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[474],module,F4761,fqv[475]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[476],module,F4763,fqv[477]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[478],module,F4765,fqv[479]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[480],module,F4767,fqv[481]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[482],module,F4769,fqv[483]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[484],module,F4771,fqv[485]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[486],module,F4773,fqv[487]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[488],module,F4775,fqv[489]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[490],module,F4777,fqv[491]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[492],module,F4779,fqv[493]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[494],module,F4781,fqv[495]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[496],module,F4783,fqv[497]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[498],module,F15450,fqv[499]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[500],module,F4786,fqv[501]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[502],module,F4788,fqv[503]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[504],module,F4792,fqv[505]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[506],module,F4794,fqv[507]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[508],module,F4796,fqv[509]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[510],module,F4798,fqv[511]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[512],module,F4800,fqv[513]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[514],module,F4802,fqv[515]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[516],module,F4804,fqv[517]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[518],module,F16763,fqv[519]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[520],module,F17139,fqv[521]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[522],module,F4805,fqv[523]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[524],module,F4806,fqv[525]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[17],module,F17630,fqv[526]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[527],module,F17704,fqv[528]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[529],module,F17861,fqv[530]);
	local[0]= fqv[281];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)F4568(ctx,2,local+0); /*alias*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
