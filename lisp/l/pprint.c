/* pprint.c :  entry=pprint */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "pprint.h"
#pragma init (register_pprint)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___pprint();
extern pointer build_quote_vector();
static register_pprint()
  { add_module_initializer("___pprint", ___pprint);}

static pointer F20402();
static pointer F20405();
static pointer F20408();
static pointer F20410();
static pointer F20412();
static pointer F20414();
static pointer F20416();
static pointer F20417();
static pointer F20420();

/*spaces*/
static pointer F20402(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20449;}
	local[0]= T;
ENT20449:
ENT20448:
	if (n>2) maerror();
	local[1]= makeint(0);
	local[2]= argv[0];
WHL20486:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX20487;
	local[3]= fqv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRINC(ctx,2,local+3); /*princ*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL20486;
WHX20487:
	local[3]= NIL;
BLK20488:
	w = NIL;
	local[0]= w;
BLK20446:
	ctx->vsp=local; return(local[0]);}

/*px*/
static pointer F20405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20517;}
	local[0]= T;
ENT20517:
ENT20516:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= fqv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK20514:
	ctx->vsp=local; return(local[0]);}

/*pf*/
static pointer F20537(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20541;}
	local[0]= loadglobal(fqv[2]);
ENT20541:
ENT20540:
	if (n>2) maerror();
	local[1]= fqv[3];
	local[2]= fqv[4];
	local[3]= fqv[5];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[6];
	local[4]= fqv[7];
	local[5]= fqv[5];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[5];
	local[5]= fqv[8];
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
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK20538:
	ctx->vsp=local; return(local[0]);}

/*pp-method*/
static pointer F20408(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT20619;}
	local[0]= loadglobal(fqv[2]);
ENT20619:
ENT20618:
	if (n>3) maerror();
	local[1]= argv[1];
	local[2]= *(ovafptr(argv[0],fqv[9]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[10]); /*assoc*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F20410(ctx,2,local+1); /*pprint*/
	local[0]= w;
BLK20616:
	ctx->vsp=local; return(local[0]);}

/*pprint*/
static pointer F20410(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20652;}
	local[0]= loadglobal(fqv[2]);
ENT20652:
	if (n>=3) { local[1]=(argv[2]); goto ENT20651;}
	local[1]= makeint(0);
ENT20651:
	if (n>=4) { local[2]=(argv[3]); goto ENT20650;}
	local[2]= makeint(75);
ENT20650:
ENT20649:
	if (n>4) maerror();
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F20414(ctx,4,local+3); /*pprint1*/
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TERPRI(ctx,1,local+3); /*terpri*/
	local[0]= w;
BLK20647:
	ctx->vsp=local; return(local[0]);}

/*pprint-file*/
static pointer F20412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[11];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[13]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP20718,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F20410(ctx,2,local+3); /*pprint*/
	ctx->vsp=local+3;
	UWP20718(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK20687:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP20718(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*pprint1*/
static pointer F20414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[0];
	if (issymbol(w)) goto OR20763;
	w = argv[0];
	if (isnum(w)) goto OR20763;
	w = argv[0];
	if (isstring(w)) goto OR20763;
	local[0]= argv[0];
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PRNTSIZE(ctx,2,local+0); /*print-size*/
	local[0]= w;
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w!=NIL) goto OR20763;
	goto CON20762;
OR20763:
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRIN1(ctx,2,local+0); /*prin1*/
	local[0]= w;
	goto CON20760;
CON20762:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON20796;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[5]!=local[0]) goto CON20796;
	local[0]= fqv[14];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20414(ctx,4,local+0); /*pprint1*/
	local[0]= w;
	goto CON20760;
CON20796:
	local[0]= argv[0];
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON20836;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[16]); /*array-rank*/
	local[0]= w;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON20836;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[17]); /*array-total-size*/
	local[0]= w;
	local[1]= makeint(100);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON20836;
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F20417(ctx,3,local+0); /*pprint-array*/
	local[0]= w;
	goto CON20760;
CON20836:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)VECTORP(ctx,1,local+0); /*vectorp*/
	if (w==NIL) goto CON20863;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[18]); /*float-vector-p*/
	if (w==NIL) goto CON20873;
	local[0]= fqv[19];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= argv[2];
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[2] = w;
	local[0]= argv[2];
	goto CON20871;
CON20873:
	local[0]= fqv[20];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= argv[2];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[2] = w;
	local[0]= argv[2];
	goto CON20871;
CON20896:
	local[0]= NIL;
CON20871:
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL20939:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX20940;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)F20414(ctx,4,local+2); /*pprint1*/
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)TERPRI(ctx,1,local+2); /*terpri*/
	local[2]= argv[2];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F20402(ctx,2,local+2); /*spaces*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL20939;
WHX20940:
	local[2]= NIL;
BLK20941:
	local[2]= fqv[21];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	local[0]= w;
	goto CON20760;
CON20863:
	w = argv[0];
	if (!!iscons(w)) goto CON20981;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRIN1(ctx,2,local+0); /*prin1*/
	local[0]= w;
	goto CON20760;
CON20981:
	local[0]= fqv[22];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LISTP(ctx,1,local+2); /*listp*/
	if (w==NIL) goto IF21005;
	local[2]= (pointer)((integer_t)(argv[2])+4);
	goto IF21006;
IF21005:
	local[2]= argv[2];
IF21006:
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20414(ctx,4,local+0); /*pprint1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	w = fqv[23];
	if (memq(local[1],w)==NIL) goto IF21042;
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20402(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20402(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[2] = w;
	local[2]= argv[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)PRNTSIZE(ctx,1,local+3); /*print-size*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F20416(ctx,4,local+1); /*pparg*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	goto IF21043;
IF21042:
	local[1]= local[0];
	w = fqv[24];
	if (memq(local[1],w)==NIL) goto IF21124;
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20402(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[2] = w;
	local[2]= argv[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)PRNTSIZE(ctx,1,local+3); /*print-size*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F20416(ctx,4,local+1); /*pparg*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	goto IF21125;
IF21124:
	local[1]= local[0];
	w = fqv[25];
	if (memq(local[1],w)==NIL) goto IF21185;
WHL21199:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	if (argv[0]==NIL) goto WHX21200;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX21200;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= argv[2];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20402(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20402(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	local[3]= argv[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)PRNTSIZE(ctx,1,local+4); /*print-size*/
	local[4]= w;
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,3,local+3); /*+*/
	local[3]= w;
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F20414(ctx,4,local+1); /*pprint1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL21199;
WHX21200:
	local[1]= NIL;
BLK21201:
	argv[0] = fqv[26];
	local[1]= argv[0];
	goto IF21186;
IF21185:
	if (T==NIL) goto IF21292;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto IF21297;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto IF21297;
	local[1]= argv[2];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[2] = w;
	local[1]= argv[2];
	goto IF21298;
IF21297:
	argv[2] = (pointer)((integer_t)(argv[2])+4);
	local[1]= argv[2];
IF21298:
	goto IF21293;
IF21292:
	local[1]= NIL;
IF21293:
IF21186:
IF21125:
IF21043:
	w = local[1];
WHL21339:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto WHX21340;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	if (argv[0]==NIL) goto WHX21340;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= argv[2];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F20402(ctx,2,local+0); /*spaces*/
	w = argv[0];
	if (!!iscons(w)) goto CON21373;
	local[0]= fqv[27];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= makeint(2);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20414(ctx,4,local+0); /*pprint1*/
	local[0]= w;
	goto CON21371;
CON21373:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20414(ctx,4,local+0); /*pprint1*/
	local[0]= w;
	goto CON21371;
CON21393:
	local[0]= NIL;
CON21371:
	goto WHL21339;
WHX21340:
	local[0]= NIL;
BLK21341:
	local[0]= fqv[28];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= w;
	goto CON20760;
CON20990:
	local[0]= NIL;
CON20760:
	w = local[0];
	local[0]= w;
BLK20744:
	ctx->vsp=local; return(local[0]);}

/*pparg*/
static pointer F20416(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[0];
	if (!iscons(w)) goto OR21432;
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PRNTSIZE(ctx,2,local+0); /*print-size*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w!=NIL) goto OR21432;
	goto CON21431;
OR21432:
	local[0]= argv[0];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)PRIN1(ctx,2,local+0); /*prin1*/
	local[0]= w;
	goto CON21429;
CON21431:
	local[0]= NIL;
	local[1]= fqv[29];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[0] = argv[1];
WHL21484:
	if (argv[0]==NIL) goto WHX21485;
	local[1]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)PRNTSIZE(ctx,1,local+2); /*print-size*/
	local[2]= w;
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,3,local+1); /*+*/
	local[0] = w;
	local[1]= local[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON21494;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRIN1(ctx,2,local+1); /*prin1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	if (local[1]==NIL) goto AND21526;
	local[1]= fqv[30];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= w;
AND21526:
	goto CON21492;
CON21494:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F20402(ctx,2,local+1); /*spaces*/
	local[0] = argv[1];
	local[1]= local[0];
	goto CON21492;
CON21543:
	local[1]= NIL;
CON21492:
	goto WHL21484;
WHX21485:
	local[1]= NIL;
BLK21486:
	local[1]= fqv[31];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[0]= w;
	goto CON21429;
CON21459:
	local[0]= NIL;
CON21429:
	w = local[0];
	local[0]= w;
BLK21413:
	ctx->vsp=local; return(local[0]);}

/*pprint-array*/
static pointer F20417(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[10]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,2,local+1,&ftab[5],fqv[34]); /*array-dimension*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,2,local+2,&ftab[5],fqv[34]); /*array-dimension*/
	local[2]= w;
	if (local[0]!=NIL) goto IF21619;
	local[0] = fqv[35];
	local[3]= local[0];
	goto IF21620;
IF21619:
	local[3]= NIL;
IF21620:
	local[3]= argv[1];
	local[4]= fqv[36];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= makeint(0);
	local[4]= local[1];
WHL21662:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX21663;
	local[5]= argv[1];
	local[6]= fqv[37];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= makeint(0);
	local[6]= local[2];
WHL21698:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX21699;
	local[7]= argv[1];
	local[8]= fqv[38];
	local[9]= argv[0];
	local[10]= local[3];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= (pointer)((integer_t)(local[5])+4);
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON21718;
	local[7]= argv[1];
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON21716;
CON21718:
	local[7]= argv[1];
	local[8]= fqv[40];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON21716;
CON21730:
	local[7]= NIL;
CON21716:
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL21698;
WHX21699:
	local[7]= NIL;
BLK21700:
	w = NIL;
	local[5]= (pointer)((integer_t)(local[3])+4);
	local[6]= argv[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[34]); /*array-dimension*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF21752;
	local[5]= argv[1];
	local[6]= fqv[41];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= argv[2];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F20402(ctx,2,local+5); /*spaces*/
	local[5]= w;
	goto IF21753;
IF21752:
	local[5]= NIL;
IF21753:
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL21662;
WHX21663:
	local[5]= NIL;
BLK21664:
	w = NIL;
	local[3]= argv[1];
	local[4]= fqv[42];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[0]= w;
BLK21568:
	ctx->vsp=local; return(local[0]);}

/*tprint*/
static pointer F20420(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT21806;}
	local[0]= makeint(0);
ENT21806:
	if (n>=4) { local[1]=(argv[3]); goto ENT21805;}
	local[1]= makeint(79);
ENT21805:
	if (n>=5) { local[2]=(argv[4]); goto ENT21804;}
	local[2]= makeint(0);
ENT21804:
ENT21803:
	if (n>5) maerror();
	local[3]= local[2];
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= makeint(0);
	local[8]= local[0];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F20402(ctx,1,local+8); /*spaces*/
WHL21868:
	if (argv[0]==NIL) goto WHX21869;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PRNTSIZE(ctx,1,local+8); /*print-size*/
	local[7] = w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[8]= argv[1];
	local[9]= local[7];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= (pointer)((integer_t)(w)+4);
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[5] = w;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto CON21927;
	ctx->vsp=local+8;
	w=(pointer)TERPRI(ctx,0,local+8); /*terpri*/
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)F20402(ctx,1,local+8); /*spaces*/
	local[3] = local[0];
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[6] = w;
	local[8]= local[6];
	goto CON21925;
CON21927:
	local[8]= NIL;
CON21925:
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PRINC(ctx,1,local+8); /*princ*/
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F20402(ctx,1,local+8); /*spaces*/
	local[8]= local[6];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[6] = w;
	local[8]= local[3];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[3] = w;
	goto WHL21868;
WHX21869:
	local[8]= NIL;
BLK21870:
	w = local[8];
	local[0]= w;
BLK21801:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___pprint(ctx,n,argv,env)
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
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF21995;
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[45],w);
	goto IF21996;
IF21995:
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF21996:
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[48],module,F20402,fqv[49]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F20405,fqv[51]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[52],module,F20537,fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F20408,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[6],module,F20410,fqv[56]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[57],module,F20412,fqv[58]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[59],module,F20414,fqv[60]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[61],module,F20416,fqv[62]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F20417,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F20420,fqv[66]);
	local[0]= fqv[67];
	local[1]= fqv[68];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[69]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
