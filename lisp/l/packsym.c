/* packsym.c :  entry=packsym */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "packsym.h"
#pragma init (register_packsym)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___packsym();
extern pointer build_quote_vector();
static register_packsym()
  { add_module_initializer("___packsym", ___packsym);}

static pointer F45606();
static pointer F45609();
static pointer F45611();
static pointer F45613();
static pointer F45615();
static pointer F45617();
static pointer F45619();
static pointer F45622();
static pointer F45626();
static pointer F45628();
static pointer F45630();
static pointer F45632();
static pointer F45634();
static pointer F45636();
static pointer F45638();
static pointer F45640();
static pointer F45643();
static pointer F45645();
static pointer F45647();
static pointer F45649();
static pointer F45651();
static pointer F45652();

/*metaclass-name*/
static pointer F45606(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[0]));
	local[0]= w;
BLK45692:
	ctx->vsp=local; return(local[0]);}

/*:home-package*/
static pointer M45721(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK45722:
	ctx->vsp=local; return(local[0]);}

/*:pname*/
static pointer M45736(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK45737:
	ctx->vsp=local; return(local[0]);}

/*:func*/
static pointer M45751(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK45752:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M45766(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF45781;
	local[0]= makeint(11);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF45782;
IF45781:
	local[0]= NIL;
IF45782:
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK45767:
	ctx->vsp=local; return(local[0]);}

/*:constant*/
static pointer M45798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT45802;}
	local[0]= NIL;
ENT45802:
ENT45801:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF45820;
	local[1]= loadglobal(fqv[1]);
	local[2]= fqv[2];
	local[3]= argv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= w;
	goto IF45821;
IF45820:
	local[1]= NIL;
IF45821:
	if (local[0]==NIL) goto IF45834;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF45835;
IF45834:
	local[1]= NIL;
IF45835:
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[0];
	local[0]= w;
BLK45799:
	ctx->vsp=local; return(local[0]);}

/*:special*/
static pointer M45858(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT45862;}
	local[0]= NIL;
ENT45862:
ENT45861:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF45880;
	local[1]= makeint(11);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF45881;
IF45880:
	local[1]= NIL;
IF45881:
	if (local[0]==NIL) goto IF45890;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF45891;
IF45890:
	local[1]= NIL;
IF45891:
	ctx->vsp=local+1;
	w=(pointer)NEXT_SPECIAL_INDEX(ctx,0,local+1); /*system::next-special-index*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SETSPECIAL(ctx,2,local+1); /*set*/
	w = argv[0];
	local[0]= w;
BLK45859:
	ctx->vsp=local; return(local[0]);}

/*:global*/
static pointer M45918(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT45922;}
	local[0]= NIL;
ENT45922:
ENT45921:
	if (n>4) maerror();
	argv[0]->c.obj.iv[2] = makeint(2);
	argv[0]->c.obj.iv[1] = argv[2];
	if (local[0]==NIL) goto IF45953;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF45954;
IF45953:
	local[1]= NIL;
IF45954:
	w = argv[2];
	local[0]= w;
BLK45919:
	ctx->vsp=local; return(local[0]);}

/*:vtype*/
static pointer M45968(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT45972;}
	local[0]= NIL;
ENT45972:
ENT45971:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF45988;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF45989;
IF45988:
	local[1]= NIL;
IF45989:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK45969:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M46003(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46007;}
	local[0]= makeint(1);
ENT46007:
ENT46006:
	if (n>4) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	w = argv[0];
	local[0]= w;
BLK46004:
	ctx->vsp=local; return(local[0]);}

/*symbol-plist*/
static pointer F45609(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK46041:
	ctx->vsp=local; return(local[0]);}

/*remprop*/
static pointer F45611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[5];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK46058:
	ctx->vsp=local; return(local[0]);}

/*symbol-package*/
static pointer F45613(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK46078:
	ctx->vsp=local; return(local[0]);}

/*symbol-name*/
static pointer F45615(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF46111;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF46112;
IF46111:
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF46112:
	w = local[0];
	local[0]= w;
BLK46095:
	ctx->vsp=local; return(local[0]);}

/*make-symbol*/
static pointer F45617(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT46126;}
	local[0]= loadglobal(fqv[8]);
ENT46126:
ENT46125:
	if (n>2) maerror();
	w = argv[0];
	if (isstring(w)) goto IF46142;
	local[1]= fqv[9];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF46143;
IF46142:
	local[1]= NIL;
IF46143:
	local[1]= loadglobal(fqv[10]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= argv[0];
	w = local[1];
	w->c.obj.iv[4] = local[2];
	local[2]= makeint(1);
	w = local[1];
	w->c.obj.iv[2] = local[2];
	local[2]= local[0];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[5] = local[3];
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)MAKUNBOUND(ctx,1,local+2); /*makunbound*/
	w = local[1];
	local[0]= w;
BLK46123:
	ctx->vsp=local; return(local[0]);}

/*documentation*/
static pointer F45619(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT46194;}
	local[0]= NIL;
ENT46194:
ENT46193:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= local[1];
	w = fqv[11];
	if (memq(local[2],w)==NIL) goto IF46221;
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46222;
IF46221:
	local[2]= local[1];
	w = fqv[13];
	if (memq(local[2],w)==NIL) goto IF46237;
	local[2]= argv[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46238;
IF46237:
	local[2]= local[1];
	w = fqv[14];
	if (memq(local[2],w)==NIL) goto IF46253;
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46254;
IF46253:
	local[2]= local[1];
	w = fqv[16];
	if (memq(local[2],w)==NIL) goto IF46269;
	local[2]= argv[0];
	local[3]= fqv[17];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46270;
IF46269:
	if (T==NIL) goto IF46285;
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46290;
CON46292:
	local[2]= argv[0];
	local[3]= fqv[17];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46290;
CON46300:
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46290;
CON46308:
	local[2]= argv[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46290;
CON46316:
	local[2]= NIL;
CON46290:
	goto IF46286;
IF46285:
	local[2]= NIL;
IF46286:
IF46270:
IF46254:
IF46238:
IF46222:
	w = local[2];
	local[0]= w;
BLK46191:
	ctx->vsp=local; return(local[0]);}

/*gentemp*/
static pointer F45622(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT46334;}
	local[0]= fqv[18];
ENT46334:
	if (n>=2) { local[1]=(argv[1]); goto ENT46333;}
	local[1]= loadglobal(fqv[8]);
ENT46333:
ENT46332:
	if (n>2) maerror();
	local[2]= NIL;
WHL46360:
	local[3]= loadglobal(fqv[19]);
	local[4]= local[0];
	local[5]= loadglobal(fqv[20]);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,1,local+5,&ftab[0],fqv[19]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[2] = w;
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)FINDSYMBOL(ctx,2,local+3); /*find-symbol*/
	if (w==NIL) goto WHX46361;
	local[3]= (pointer)((integer_t)(loadglobal(fqv[20]))+4);
	storeglobal(fqv[20],local[3]);
	goto WHL46360;
WHX46361:
	local[3]= NIL;
BLK46362:
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,2,local+3); /*intern*/
	local[0]= w;
BLK46330:
	ctx->vsp=local; return(local[0]);}

/*:use-list*/
static pointer M46423(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK46424:
	ctx->vsp=local; return(local[0]);}

/*:used-by-list*/
static pointer M46438(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46439:
	ctx->vsp=local; return(local[0]);}

/*:used-by*/
static pointer M46453(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[21]); /*adjoin*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46454:
	ctx->vsp=local; return(local[0]);}

/*:use*/
static pointer M46479(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF46494;
WHL46505:
	if (argv[2]==NIL) goto WHX46506;
	local[0]= argv[0];
	local[1]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	goto WHL46505;
WHX46506:
	local[0]= NIL;
BLK46507:
	local[0]= argv[0]->c.obj.iv[2];
	goto IF46495;
IF46494:
	local[0]= NIL;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	argv[2] = w;
	local[1]= argv[2];
	if (argv[0]==local[1]) goto IF46556;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F45634(ctx,1,local+1); /*packagep*/
	if (w==NIL) goto IF46556;
	local[1]= NIL;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)FINDPACKAGE(ctx,1,local+2); /*find-package*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= *(ovafptr(local[2],fqv[23]));
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL46602:
	local[6]= local[3];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX46603;
	local[6]= local[4];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[1] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	w = local[1];
	if (!issymbol(w)) goto IF46633;
	local[6]= argv[0];
	local[7]= fqv[24];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF46654;
	local[6]= argv[0]->c.obj.iv[5];
	{ register integer_t i=intval(local[0]);
	  w=(local[6]->c.vec.v[i]);}
	local[6]= w;
	if (local[1]==local[6]) goto IF46654;
	local[6]= fqv[25];
	local[7]= local[1];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,3,local+6); /*error*/
	local[6]= w;
	goto IF46655;
IF46654:
	local[6]= NIL;
IF46655:
	goto IF46634;
IF46633:
	local[6]= NIL;
IF46634:
	goto WHL46602;
WHX46603:
	local[6]= NIL;
BLK46604:
	w = NIL;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[21]); /*adjoin*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[2];
	local[2]= fqv[26];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF46557;
IF46556:
	local[1]= NIL;
IF46557:
	w = local[1];
	local[0]= w;
IF46495:
	w = local[0];
	local[0]= w;
BLK46480:
	ctx->vsp=local; return(local[0]);}

/*:unuse*/
static pointer M46694(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	argv[2] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F45634(ctx,1,local+0); /*packagep*/
	if (w==NIL) goto IF46719;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[27]); /*delete*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[2];
	local[1]= fqv[28];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF46720;
IF46719:
	local[0]= NIL;
IF46720:
	w = local[0];
	local[0]= w;
BLK46695:
	ctx->vsp=local; return(local[0]);}

/*:unused*/
static pointer M46747(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[27]); /*delete*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46748:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M46772(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK46773:
	ctx->vsp=local; return(local[0]);}

/*:rename*/
static pointer M46791(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[19]); /*string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK46792:
	ctx->vsp=local; return(local[0]);}

/*:nicknames*/
static pointer M46817(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT46821;}
	local[0]= NIL;
ENT46821:
ENT46820:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF46837;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= (pointer)get_sym_func(fqv[19]);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= fqv[29];
	local[4]= (pointer)get_sym_func(fqv[30]);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,4,local+1,&ftab[3],fqv[31]); /*union*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto IF46838;
IF46837:
	local[1]= NIL;
IF46838:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK46818:
	ctx->vsp=local; return(local[0]);}

/*:hash*/
static pointer M46864(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[19]); /*string*/
	argv[2] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SXHASH(ctx,1,local+0); /*sxhash*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
BLK46865:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M46896(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF46911;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK46897;
	goto IF46912;
IF46911:
	local[0]= NIL;
IF46912:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SXHASH(ctx,1,local+0); /*sxhash*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL46945:
	local[2]= argv[0]->c.obj.iv[5];
	{ register integer_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	if (!issymbol(w)) goto WHX46946;
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF46956;
	local[0] = makeint(0);
	local[2]= local[0];
	goto IF46957;
IF46956:
	local[2]= NIL;
IF46957:
	goto WHL46945;
WHX46946:
	local[2]= NIL;
BLK46947:
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	w = argv[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	argv[0]->c.obj.iv[6] = (pointer)((integer_t)(argv[0]->c.obj.iv[6])+4);
	w = argv[2];
	local[0]= w;
BLK46897:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M46997(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47018;
	local[0]= fqv[32];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF47019;
IF47018:
	local[0]= NIL;
IF47019:
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SXHASH(ctx,1,local+1); /*sxhash*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	local[1]= w;
	local[2]= NIL;
WHL47054:
	if (T==NIL) goto WHX47055;
	local[3]= argv[0]->c.obj.iv[5];
	{ register integer_t i=intval(local[1]);
	  w=(local[3]->c.vec.v[i]);}
	local[2] = w;
	local[3]= local[2];
	if (makeint(0)!=local[3]) goto CON47074;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK46998;
	goto CON47072;
CON47074:
	local[3]= local[2];
	local[3]= ((makeint(1))==(local[3])?T:NIL);
	if (local[3]!=NIL) goto CON47072;
CON47082:
	local[3]= local[2]->c.obj.iv[4];
	local[4]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto CON47089;
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK46998;
	goto CON47072;
CON47089:
	local[3]= NIL;
CON47072:
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF47105;
	local[1] = makeint(0);
	local[3]= local[1];
	goto IF47106;
IF47105:
	local[3]= NIL;
IF47106:
	goto WHL47054;
WHX47055:
	local[3]= NIL;
BLK47056:
	w = NIL;
	local[0]= w;
BLK46998:
	ctx->vsp=local; return(local[0]);}

/*:shadow*/
static pointer M47128(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w!=NIL) goto IF47144;
	local[0]= argv[0];
	local[1]= fqv[33];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[19]); /*string*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F45617(ctx,2,local+2); /*make-symbol*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF47145;
IF47144:
	local[0]= NIL;
IF47145:
	w = local[0];
	local[0]= w;
BLK47129:
	ctx->vsp=local; return(local[0]);}

/*:import*/
static pointer M47169(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF47200;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[5];
	{ register integer_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	if (w==local[1]) goto IF47200;
	local[1]= fqv[34];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF47201;
IF47200:
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF47201:
	w = local[1];
	local[0]= w;
BLK47170:
	ctx->vsp=local; return(local[0]);}

/*:unintern*/
static pointer M47225(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[2],fqv[35]));
	if (argv[0]!=local[1]) goto IF47250;
	local[1]= NIL;
	local[2]= local[1];
	*(ovafptr(argv[2],fqv[35])) = local[2];
	goto IF47251;
IF47250:
	local[1]= NIL;
IF47251:
	local[1]= argv[0];
	local[2]= fqv[24];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47276;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= local[0];
	w = makeint(1);
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	argv[0]->c.obj.iv[6] = (pointer)((integer_t)(argv[0]->c.obj.iv[6])-4);
	local[1]= argv[0]->c.obj.iv[6];
	goto IF47277;
IF47276:
	local[1]= NIL;
IF47277:
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47314;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	w = makeint(1);
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	argv[0]->c.obj.iv[4] = (pointer)((integer_t)(argv[0]->c.obj.iv[4])-4);
	local[1]= argv[0]->c.obj.iv[4];
	goto IF47315;
IF47314:
	local[1]= NIL;
IF47315:
	w = local[1];
	local[0]= w;
BLK47226:
	ctx->vsp=local; return(local[0]);}

/*:find-external*/
static pointer M47339(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47360;
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF47361;
IF47360:
	local[0]= NIL;
IF47361:
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SXHASH(ctx,1,local+1); /*sxhash*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	local[1]= w;
	local[2]= NIL;
WHL47396:
	if (T==NIL) goto WHX47397;
	local[3]= argv[0]->c.obj.iv[3];
	{ register integer_t i=intval(local[1]);
	  w=(local[3]->c.vec.v[i]);}
	local[2] = w;
	local[3]= local[2];
	if (makeint(0)!=local[3]) goto CON47416;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47340;
	goto CON47414;
CON47416:
	local[3]= local[2];
	local[3]= ((makeint(1))==(local[3])?T:NIL);
	if (local[3]!=NIL) goto CON47414;
CON47424:
	local[3]= local[2]->c.obj.iv[4];
	local[4]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto CON47431;
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47340;
	goto CON47414;
CON47431:
	local[3]= NIL;
CON47414:
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF47447;
	local[1] = makeint(0);
	local[3]= local[1];
	goto IF47448;
IF47447:
	local[3]= NIL;
IF47448:
	goto WHL47396;
WHX47397:
	local[3]= NIL;
BLK47398:
	w = NIL;
	local[0]= w;
BLK47340:
	ctx->vsp=local; return(local[0]);}

/*:unexport*/
static pointer M47470(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF47501;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	w = makeint(0);
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= w;
	goto IF47502;
IF47501:
	local[1]= NIL;
IF47502:
	w = local[1];
	local[0]= w;
BLK47471:
	ctx->vsp=local; return(local[0]);}

/*package-name*/
static pointer F45626(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	argv[0] = w;
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47516:
	ctx->vsp=local; return(local[0]);}

/*package-nicknames*/
static pointer F45628(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47542:
	ctx->vsp=local; return(local[0]);}

/*package-use-list*/
static pointer F45630(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47561:
	ctx->vsp=local; return(local[0]);}

/*package-used-by-list*/
static pointer F45632(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47580:
	ctx->vsp=local; return(local[0]);}

/*packagep*/
static pointer F45634(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	w = ((loadglobal(fqv[42]))==(local[0])?T:NIL);
	local[0]= w;
BLK47599:
	ctx->vsp=local; return(local[0]);}

/*use-package*/
static pointer F45636(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT47623;}
	local[0]= loadglobal(fqv[8]);
ENT47623:
ENT47622:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= fqv[22];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = T;
	local[0]= w;
BLK47620:
	ctx->vsp=local; return(local[0]);}

/*unuse-package*/
static pointer F45638(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT47651;}
	local[0]= loadglobal(fqv[8]);
ENT47651:
ENT47650:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	local[1]= w;
	local[2]= fqv[43];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK47648:
	ctx->vsp=local; return(local[0]);}

/*make-package*/
static pointer F45640(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[44], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY47686;
	local[0] = NIL;
KEY47686:
	if (n & (1<<1)) goto KEY47691;
	local[2]= fqv[45];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[1] = w;
KEY47691:
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAKEPACKAGE(ctx,3,local+2); /*system::makepackage*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[22];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK47676:
	ctx->vsp=local; return(local[0]);}

/*in-package*/
static pointer F47729(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[46];
	local[1]= fqv[47];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[48];
	local[3]= fqv[8];
	local[4]= fqv[47];
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
	local[3]= fqv[49];
	local[4]= fqv[50];
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
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK47730:
	ctx->vsp=local; return(local[0]);}

/*rename-package*/
static pointer F45643(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT47791;}
	local[0]= NIL;
ENT47791:
ENT47790:
	if (n>3) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	argv[0] = w;
	local[1]= argv[0];
	local[2]= fqv[51];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (local[0]==NIL) goto IF47823;
	local[1]= argv[0];
	local[2]= fqv[39];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF47824;
IF47823:
	local[1]= NIL;
IF47824:
	w = local[1];
	local[0]= w;
BLK47788:
	ctx->vsp=local; return(local[0]);}

/*shadow*/
static pointer F45645(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT47840;}
	local[0]= loadglobal(fqv[8]);
ENT47840:
ENT47839:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF47855;
	local[1]= local[0];
	local[2]= fqv[52];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF47856;
IF47855:
WHL47867:
	if (argv[0]==NIL) goto WHX47868;
	local[1]= local[0];
	local[2]= fqv[52];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL47867;
WHX47868:
	local[1]= NIL;
BLK47869:
IF47856:
	w = local[1];
	local[0]= w;
BLK47837:
	ctx->vsp=local; return(local[0]);}

/*import*/
static pointer F45647(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT47901;}
	local[0]= loadglobal(fqv[8]);
ENT47901:
ENT47900:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF47916;
	local[1]= local[0];
	local[2]= fqv[53];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF47917;
IF47916:
WHL47928:
	if (argv[0]==NIL) goto WHX47929;
	local[1]= local[0];
	local[2]= fqv[53];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL47928;
WHX47929:
	local[1]= NIL;
BLK47930:
IF47917:
	w = T;
	local[0]= w;
BLK47898:
	ctx->vsp=local; return(local[0]);}

/*symbol-string*/
static pointer F45649(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF47971;
	local[0]= *(ovafptr(argv[0],fqv[54]));
	goto IF47972;
IF47971:
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF47972:
	w = local[0];
	local[0]= w;
BLK47961:
	ctx->vsp=local; return(local[0]);}

/*unintern*/
static pointer F45651(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT47986;}
	local[0]= loadglobal(fqv[8]);
ENT47986:
ENT47985:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48001;
	local[1]= local[0];
	local[2]= fqv[56];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48002;
IF48001:
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
IF48002:
	w = local[1];
	local[0]= w;
BLK47983:
	ctx->vsp=local; return(local[0]);}

/*package-stats*/
static pointer F45652(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT48019;}
	local[0]= T;
ENT48019:
ENT48018:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)ALLPACKAGES(ctx,0,local+5); /*list-all-packages*/
	local[5]= w;
WHL48055:
	if (local[5]==NIL) goto WHX48056;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= (pointer)get_sym_func(fqv[58]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F45630(ctx,1,local+7); /*package-use-list*/
	local[7]= w;
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[59]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[2] = w;
	local[6]= (pointer)get_sym_func(fqv[58]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F45632(ctx,1,local+7); /*package-used-by-list*/
	local[7]= w;
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[59]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[3] = w;
	local[6]= local[0];
	local[7]= fqv[60];
	local[8]= local[4];
	local[9]= fqv[39];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[4];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF48150;
	local[9]= local[4];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	goto IF48151;
IF48150:
	local[9]= fqv[61];
IF48151:
	local[10]= local[4]->c.obj.iv[4];
	if (local[2]==NIL) goto IF48178;
	local[11]= local[2];
	goto IF48179;
IF48178:
	local[11]= fqv[62];
IF48179:
	if (local[3]==NIL) goto IF48185;
	local[12]= local[3];
	goto IF48186;
IF48185:
	local[12]= fqv[63];
IF48186:
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,7,local+6); /*format*/
	goto WHL48055;
WHX48056:
	local[6]= NIL;
BLK48057:
	w = NIL;
	local[0]= w;
BLK48016:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___packsym(ctx,n,argv,env)
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
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[65];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF48205;
	local[0]= fqv[66];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[8],w);
	goto IF48206;
IF48205:
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF48206:
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F45606,fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45721,fqv[6],fqv[10],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45736,fqv[72],fqv[10],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45751,fqv[74],fqv[10],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45766,fqv[76],fqv[10],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45798,fqv[78],fqv[10],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45858,fqv[80],fqv[10],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45918,fqv[82],fqv[10],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M45968,fqv[84],fqv[10],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46003,fqv[86],fqv[10],fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F45609,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F45611,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F45613,fqv[93]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[94],module,F45615,fqv[95]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[96],module,F45617,fqv[97]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[98],module,F45619,fqv[99]);
	local[0]= makeint(0);
	storeglobal(fqv[20],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[100],module,F45622,fqv[101]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46423,fqv[40],fqv[42],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46438,fqv[41],fqv[42],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46453,fqv[26],fqv[42],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46479,fqv[22],fqv[42],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46694,fqv[43],fqv[42],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46747,fqv[28],fqv[42],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46772,fqv[38],fqv[42],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46791,fqv[51],fqv[42],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46817,fqv[39],fqv[42],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46864,fqv[111],fqv[42],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46896,fqv[33],fqv[42],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46997,fqv[24],fqv[42],fqv[114]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47128,fqv[52],fqv[42],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47169,fqv[53],fqv[42],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47225,fqv[56],fqv[42],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47339,fqv[36],fqv[42],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47470,fqv[119],fqv[42],fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F45626,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F45628,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F45630,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F45632,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F45634,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F45636,fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F45638,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F45640,fqv[136]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[137],module,F47729,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F45643,fqv[140]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F45645,fqv[142]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F45647,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F45649,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F45651,fqv[148]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F45652,fqv[150]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<5; i++) ftab[i]=fcallx;
}
