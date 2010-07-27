/* eushelp.c :  entry=eushelp */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "eushelp.h"
#pragma init (register_eushelp)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___eushelp();
extern pointer build_quote_vector();
static register_eushelp()
  { add_module_initializer("___eushelp", ___eushelp);}

static pointer F74913();
static pointer F74914();
static pointer F74915();
static pointer F74916();
static pointer F74917();
static pointer F74918();
static pointer F74919();
static pointer F74920();

/*:init*/
static pointer M74998(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT75002;}
	local[0]= NIL;
ENT75002:
ENT75001:
	if (n>7) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	argv[0]->c.obj.iv[1] = argv[3];
	argv[0]->c.obj.iv[2] = argv[4];
	argv[0]->c.obj.iv[3] = argv[5];
	local[1]= argv[2];
	if (makeint(1)!=local[1]) goto IF75058;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF75059;
IF75058:
	local[1]= NIL;
IF75059:
	local[1]= argv[2];
	if (makeint(0)!=local[1]) goto IF75072;
	local[1]= fqv[0];
	local[2]= (pointer)get_sym_func(fqv[1]);
	local[3]= fqv[2];
	local[4]= makeflt(1.39999962e+00);
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,4,local+1,&ftab[0],fqv[3]); /*make-hash-table*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= argv[0]->c.obj.iv[5];
	w = loadglobal(fqv[4]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[4],local[1]);
	goto IF75073;
IF75072:
	local[1]= NIL;
IF75073:
	w = local[1];
	local[0]= w;
BLK74999:
	ctx->vsp=local; return(local[0]);}

/*:read-help*/
static pointer M75107(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[5];
	local[1]= loadglobal(fqv[6]);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[7]); /*pathname*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[8]); /*pathname-directory*/
	local[1]= w;
	local[2]= fqv[9];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[10];
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,6,local+0,&ftab[3],fqv[12]); /*make-pathname*/
	local[0]= w;
	local[1]= fqv[13];
	local[2]= fqv[14];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,3,local+0,&ftab[4],fqv[15]); /*open*/
	local[0]= w;
	local[1]= fqv[16];
	local[2]= fqv[17];
	local[3]= fqv[18];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[19]); /*read-tex*/
	local[1] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF75176;
	local[4]= local[0];
	local[5]= makeint(-1);
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[19]); /*read-tex*/
	local[2] = w;
	local[4]= local[2];
	goto IF75177;
IF75176:
	local[4]= NIL;
IF75177:
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF75192;
	local[4]= local[0];
	local[5]= makeint(-1);
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[19]); /*read-tex*/
	local[3] = w;
	local[4]= local[3];
	goto IF75193;
IF75192:
	local[4]= NIL;
IF75193:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[0]= w;
BLK75108:
	ctx->vsp=local; return(local[0]);}

/*help*/
static pointer F74913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT75225;}
	local[0]= NIL;
ENT75225:
	if (n>=2) { local[1]=(argv[1]); goto ENT75224;}
	local[1]= NIL;
ENT75224:
	if (n>=3) { local[2]=(argv[2]); goto ENT75223;}
	local[2]= T;
ENT75223:
ENT75222:
	if (n>3) maerror();
	if (loadglobal(fqv[20])!=NIL) goto IF75246;
	local[3]= fqv[0];
	local[4]= (pointer)get_sym_func(fqv[1]);
	local[5]= fqv[21];
	local[6]= makeint(1000);
	local[7]= fqv[2];
	local[8]= makeflt(1.59999990e+00);
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,6,local+3,&ftab[0],fqv[3]); /*make-hash-table*/
	local[3]= w;
	storeglobal(fqv[20],w);
	local[3]= NIL;
	local[4]= fqv[22];
	local[5]= loadglobal(fqv[6]);
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F74920(ctx,1,local+3); /*load-help*/
	local[3]= w;
	goto IF75247;
IF75246:
	local[3]= NIL;
IF75247:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= fqv[23];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[24];
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,2,local+6,&ftab[6],fqv[1]); /*string-equal*/
	if (w!=NIL) goto OR75302;
	local[6]= local[0];
	local[7]= fqv[25];
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,2,local+6,&ftab[6],fqv[1]); /*string-equal*/
	if (w!=NIL) goto OR75302;
	goto IF75300;
OR75302:
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F74918(ctx,1,local+6); /*help-usage*/
	local[6]= w;
	goto IF75301;
IF75300:
	local[6]= local[1];
	if (NIL!=local[6]) goto IF75319;
	local[6]= local[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	if (makeint(58)!=local[6]) goto IF75325;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F74919(ctx,1,local+6); /*help-method-list*/
	local[6]= w;
	goto IF75326;
IF75325:
	local[6]= local[0];
	local[7]= loadglobal(fqv[20]);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[26]); /*gethash*/
	local[4] = w;
	local[6]= local[4];
	if (NIL!=local[6]) goto IF75336;
	local[6]= local[2];
	local[7]= fqv[27];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[28]); /*apropos-list*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,2,local+6,&ftab[9],fqv[29]); /*pprint*/
	local[6]= w;
	goto IF75337;
IF75336:
	local[6]= local[2];
	local[7]= fqv[30];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= local[4];
	local[7]= fqv[31];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[3] = w;
	local[6]= local[4]->c.obj.iv[0];
	local[7]= local[6];
	if (fqv[32]!=local[7]) goto IF75405;
	local[7]= local[2];
	local[8]= fqv[33];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[4];
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)F74916(ctx,3,local+7); /*print-class*/
	local[7]= w;
	goto IF75406;
IF75405:
	local[7]= local[6];
	if (fqv[34]!=local[7]) goto IF75425;
	local[7]= local[2];
	local[8]= fqv[35];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[0];
	local[8]= local[4];
	local[9]= local[3];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F74914(ctx,4,local+7); /*print-item*/
	local[7]= w;
	goto IF75426;
IF75425:
	local[7]= local[6];
	if (fqv[36]!=local[7]) goto IF75446;
	local[7]= local[2];
	local[8]= fqv[37];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[0];
	local[8]= local[4];
	local[9]= local[3];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F74914(ctx,4,local+7); /*print-item*/
	local[7]= w;
	goto IF75447;
IF75446:
	local[7]= local[6];
	if (fqv[38]!=local[7]) goto IF75467;
	local[7]= local[2];
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[0];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)F74915(ctx,3,local+7); /*print-item2*/
	local[7]= w;
	goto IF75468;
IF75467:
	local[7]= local[6];
	if (fqv[40]!=local[7]) goto IF75487;
	local[7]= local[2];
	local[8]= fqv[41];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[0];
	local[8]= local[4];
	local[9]= local[3];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F74915(ctx,4,local+7); /*print-item2*/
	local[7]= w;
	goto IF75488;
IF75487:
	local[7]= local[6];
	if (fqv[42]!=local[7]) goto IF75508;
	local[7]= local[2];
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[0];
	local[8]= local[4];
	local[9]= local[3];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F74914(ctx,4,local+7); /*print-item*/
	local[7]= w;
	goto IF75509;
IF75508:
	local[7]= NIL;
IF75509:
IF75488:
IF75468:
IF75447:
IF75426:
IF75406:
	w = local[7];
	local[6]= w;
IF75337:
IF75326:
	goto IF75320;
IF75319:
	local[6]= NIL;
	local[7]= fqv[44];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= loadglobal(fqv[20]);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[26]); /*gethash*/
	local[5] = w;
	local[6]= local[5];
	if (NIL!=local[6]) goto IF75530;
	local[6]= local[2];
	local[7]= fqv[45];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF75531;
IF75530:
	local[6]= local[0];
	local[7]= local[5]->c.obj.iv[5];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[26]); /*gethash*/
	local[4] = w;
	local[6]= local[4];
	if (NIL!=local[6]) goto IF75551;
	local[6]= local[2];
	local[7]= fqv[46];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF75552;
IF75551:
	local[6]= local[2];
	local[7]= fqv[47];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= local[2];
	local[7]= fqv[48];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= local[4];
	local[7]= fqv[31];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[3] = w;
	local[6]= local[0];
	local[7]= local[4];
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)F74914(ctx,4,local+6); /*print-item*/
	local[6]= w;
IF75552:
IF75531:
IF75320:
IF75301:
	w = local[6];
	local[0]= w;
BLK75220:
	ctx->vsp=local; return(local[0]);}

/*print-item*/
static pointer F74914(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	local[1]= fqv[49];
	local[2]= argv[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[3];
	local[1]= fqv[50];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK75607:
	ctx->vsp=local; return(local[0]);}

/*print-item2*/
static pointer F74915(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	local[1]= fqv[51];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK75644:
	ctx->vsp=local; return(local[0]);}

/*print-class*/
static pointer F74916(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[52];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[2];
	local[1]= fqv[53];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[2];
	local[1]= fqv[54];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK75669:
	ctx->vsp=local; return(local[0]);}

/*help-method*/
static pointer F74917(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= fqv[55];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= loadglobal(fqv[20]);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[26]); /*gethash*/
	local[1] = w;
	local[6]= local[1];
	if (NIL!=local[6]) goto IF75747;
	local[6]= argv[1];
	local[7]= fqv[56];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF75748;
IF75747:
	local[6]= local[1]->c.obj.iv[0];
	if (makeint(0)!=local[6]) goto IF75768;
	local[6]= argv[1];
	local[7]= fqv[57];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[2] = local[1]->c.obj.iv[5]->c.obj.iv[0];
	local[6]= makeint(0);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL75827:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX75828;
	local[8]= local[2];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[3] = w;
	w = local[3];
	if (!isstring(w)) goto IF75847;
	local[8]= T;
	local[9]= fqv[58];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	goto IF75848;
IF75847:
	local[8]= NIL;
IF75848:
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL75827;
WHX75828:
	local[8]= NIL;
BLK75829:
	w = NIL;
	local[6]= w;
	goto IF75769;
IF75768:
	local[6]= argv[1];
	local[7]= fqv[59];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
IF75769:
IF75748:
	w = local[6];
	local[0]= w;
BLK75716:
	ctx->vsp=local; return(local[0]);}

/*help-usage*/
static pointer F74918(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[60];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK75875:
	ctx->vsp=local; return(local[0]);}

/*help-method-list*/
static pointer F74919(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[4]);
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL75943:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX75944;
	local[3]= argv[0];
	local[4]= local[1];
	local[5]= loadglobal(fqv[4]);
	ctx->vsp=local+6;
	w=(pointer)NTH(ctx,2,local+4); /*nth*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[26]); /*gethash*/
	local[0] = w;
	local[3]= local[0];
	if (NIL==local[3]) goto IF75952;
	local[3]= argv[1];
	local[4]= fqv[63];
	local[5]= local[0]->c.obj.iv[4];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	goto IF75953;
IF75952:
	local[3]= NIL;
IF75953:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL75943;
WHX75944:
	local[3]= NIL;
BLK75945:
	w = NIL;
	local[0]= w;
BLK75893:
	ctx->vsp=local; return(local[0]);}

/*load-help*/
static pointer F74920(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	if (loadglobal(fqv[20])!=NIL) goto IF76025;
	local[7]= fqv[0];
	local[8]= (pointer)get_sym_func(fqv[1]);
	local[9]= fqv[21];
	local[10]= makeint(1000);
	local[11]= fqv[2];
	local[12]= makeflt(1.59999990e+00);
	ctx->vsp=local+13;
	w=(*ftab[0])(ctx,6,local+7,&ftab[0],fqv[3]); /*make-hash-table*/
	local[7]= w;
	storeglobal(fqv[20],w);
	goto IF76026;
IF76025:
	local[7]= NIL;
IF76026:
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[15]); /*open*/
	local[0] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,1,local+7); /*read*/
TAG76068:
	local[7]= local[0];
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,2,local+7); /*read*/
	local[1] = w;
	local[7]= local[1];
	if (NIL!=local[7]) goto IF76082;
	w = NIL;
	ctx->vsp=local+7;
	local[7]=w;
	goto BLK76064;
	goto IF76083;
IF76082:
	local[7]= NIL;
IF76083:
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,1,local+7); /*read*/
	local[2] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,1,local+7); /*read*/
	local[3] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,1,local+7); /*read*/
	local[4] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,1,local+7); /*read*/
	local[5] = w;
	local[7]= local[2];
	if (makeint(0)!=local[7]) goto IF76129;
	local[6] = local[1];
	local[7]= local[6];
	goto IF76130;
IF76129:
	local[7]= NIL;
IF76130:
	local[7]= local[2];
	if (makeint(1)!=local[7]) goto IF76142;
	local[7]= local[1];
	local[8]= local[6];
	local[9]= loadglobal(fqv[20]);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[26]); /*gethash*/
	local[8]= w->c.obj.iv[5];
	local[9]= loadglobal(fqv[64]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[65];
	local[12]= local[2];
	local[13]= local[3];
	local[14]= local[4];
	local[15]= local[5];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,7,local+10); /*send*/
	w = local[9];
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,3,local+7,&ftab[10],fqv[66]); /*sethash*/
	local[7]= w;
	goto IF76143;
IF76142:
	local[7]= local[1];
	local[8]= loadglobal(fqv[20]);
	local[9]= loadglobal(fqv[64]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[65];
	local[12]= local[2];
	local[13]= local[3];
	local[14]= local[4];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,6,local+10); /*send*/
	w = local[9];
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,3,local+7,&ftab[10],fqv[66]); /*sethash*/
	local[7]= w;
IF76143:
	ctx->vsp=local+7;
	goto TAG76068;
	local[7]= NIL;
BLK76064:
	w = local[7];
	local[0]= w;
BLK75993:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___eushelp(ctx,n,argv,env)
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
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF76239;
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[69],w);
	goto IF76240;
IF76239:
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF76240:
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[72];
	local[1]= fqv[73];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[74];
	local[1]= fqv[73];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[75];
	local[1]= fqv[73];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[76];
	local[1]= fqv[73];
	local[2]= makeint(3);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[77];
	local[1]= fqv[73];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[78];
	local[1]= fqv[73];
	local[2]= makeint(5);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[79];
	local[1]= fqv[73];
	local[2]= makeint(6);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[20];
	local[1]= fqv[80];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76319;
	local[0]= fqv[20];
	local[1]= fqv[80];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[20];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76342;
	local[0]= fqv[20];
	local[1]= fqv[81];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76343;
IF76342:
	local[0]= NIL;
IF76343:
	local[0]= fqv[20];
	goto IF76320;
IF76319:
	local[0]= NIL;
IF76320:
	local[0]= fqv[82];
	local[1]= fqv[80];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76362;
	local[0]= fqv[82];
	local[1]= fqv[80];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[82];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76385;
	local[0]= fqv[82];
	local[1]= fqv[81];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76386;
IF76385:
	local[0]= NIL;
IF76386:
	local[0]= fqv[82];
	goto IF76363;
IF76362:
	local[0]= NIL;
IF76363:
	local[0]= fqv[6];
	local[1]= fqv[81];
	local[2]= NIL;
	local[3]= fqv[83];
	local[4]= loadglobal(fqv[84]);
	local[5]= fqv[85];
	local[6]= fqv[86];
	ctx->vsp=local+7;
	w=(pointer)GETENV(ctx,1,local+6); /*unix:getenv*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,2,local+5,&ftab[11],fqv[87]); /*substringp*/
	if (w!=NIL) goto OR76415;
	local[5]= fqv[88];
	local[6]= fqv[89];
	ctx->vsp=local+7;
	w=(pointer)GETENV(ctx,1,local+6); /*unix:getenv*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,2,local+5,&ftab[11],fqv[87]); /*substringp*/
	if (w!=NIL) goto OR76415;
	goto IF76413;
OR76415:
	local[5]= fqv[90];
	goto IF76414;
IF76413:
	local[5]= fqv[91];
IF76414:
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[80];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76435;
	local[0]= fqv[4];
	local[1]= fqv[80];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[4];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76458;
	local[0]= fqv[4];
	local[1]= fqv[81];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76459;
IF76458:
	local[0]= NIL;
IF76459:
	local[0]= fqv[4];
	goto IF76436;
IF76435:
	local[0]= NIL;
IF76436:
	local[0]= fqv[64];
	local[1]= fqv[81];
	local[2]= fqv[64];
	local[3]= fqv[92];
	local[4]= loadglobal(fqv[93]);
	local[5]= fqv[94];
	local[6]= fqv[95];
	local[7]= fqv[96];
	local[8]= NIL;
	local[9]= fqv[97];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint(-1);
	local[13]= fqv[98];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[99]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M74998,fqv[65],fqv[64],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M75107,fqv[31],fqv[64],fqv[101]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[102],module,F74913,fqv[103]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[104],module,F74914,fqv[105]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[106],module,F74915,fqv[107]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[108],module,F74916,fqv[109]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[110],module,F74917,fqv[111]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[112],module,F74918,fqv[113]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F74919,fqv[115]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[116],module,F74920,fqv[117]);
	local[0]= fqv[118];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF76527;
	local[0]= fqv[119];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[69],w);
	goto IF76528;
IF76527:
	local[0]= fqv[120];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF76528:
	local[0]= fqv[121];
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[122]); /*use-package*/
	local[0]= fqv[123];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[125]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<15; i++) ftab[i]=fcallx;
}
