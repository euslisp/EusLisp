/* eusdebug.c :  entry=eusdebug */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "eusdebug.h"
#pragma init (register_eusdebug)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___eusdebug();
extern pointer build_quote_vector();
static register_eusdebug()
  { add_module_initializer("___eusdebug", ___eusdebug);}

static pointer F34277();
static pointer F34280();
static pointer F34282();
static pointer F34284();
static pointer F34287();
static pointer F34289();
static pointer F34292();
static pointer F34295();
static pointer F34297();
static pointer F34299();
static pointer F34302();
static pointer F34305();
static pointer F34307();
static pointer F34311();
static pointer F34313();
static pointer F34318();
static pointer F34320();
static pointer F34321();
static pointer F34322();
static pointer F34323();
static pointer F34324();
static pointer F34325();
static pointer F34326();
static pointer F34327();
static pointer F34328();
static pointer F34329();
static pointer F34330();
static pointer F34331();
static pointer F34332();
static pointer F34333();
static pointer F34334();
static pointer F34335();
static pointer F34336();
static pointer F34337();
static pointer F34338();
static pointer F34339();
static pointer F34340();

/*assert*/
static pointer F34398(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST34401:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= fqv[0];
	local[2]= fqv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[2];
	local[4]= fqv[3];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[5];
	local[6]= argv[2];
	local[7]= local[0];
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
	local[4]= fqv[6];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[7];
	local[6]= fqv[8];
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
BLK34399:
	ctx->vsp=local; return(local[0]);}

/*warning-message*/
static pointer F34277(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST34486:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[9];
	local[3]= makeint(27);
	local[4]= argv[0];
	local[5]= makeint(48);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= loadglobal(fqv[5]);
	local[3]= argv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[10];
	local[3]= makeint(27);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK34484:
	ctx->vsp=local; return(local[0]);}

/*warn*/
static pointer F34280(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST34530:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= loadglobal(fqv[5]);
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	if (loadglobal(fqv[11])==NIL) goto IF34553;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[7]); /*reploop*/
	local[1]= w;
	goto IF34554;
IF34553:
	local[1]= NIL;
IF34554:
	w = local[1];
	local[0]= w;
BLK34528:
	ctx->vsp=local; return(local[0]);}

/*describe*/
static pointer F34282(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT34570;}
	local[0]= loadglobal(fqv[13]);
ENT34570:
	if (n>=3) { local[1]=(argv[2]); goto ENT34569;}
	local[1]= NIL;
ENT34569:
	w = local[1];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[14],w);
	if (n>=4) { local[4]=(argv[3]); goto ENT34568;}
	local[4]= NIL;
ENT34568:
	w = local[4];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[15],w);
ENT34567:
	if (n>4) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF34597;
	local[7]= argv[0];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,2,local+7); /*print*/
	w = NIL;
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK34565;
	goto IF34598;
IF34597:
	local[7]= NIL;
IF34598:
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= NIL;
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[8] = local[7]->c.obj.iv[4];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[9] = w;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)VECTORP(ctx,1,local+11); /*vectorp*/
	if (w==NIL) goto IF34655;
	local[11]= argv[0];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,2,local+11,&ftab[1],fqv[16]); /*pprint*/
	local[11]= w;
	goto IF34656;
IF34655:
	local[11]= makeint(0);
	local[12]= local[9];
WHL34691:
	local[13]= local[11];
	w = local[12];
	if ((integer_t)local[13] >= (integer_t)w) goto WHX34692;
	local[13]= local[0];
	local[14]= fqv[17];
	local[15]= local[8];
	{ register integer_t i=intval(local[11]);
	  w=(local[15]->c.vec.v[i]);}
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,3,local+13); /*format*/
	local[13]= local[8];
	{ register integer_t i=intval(local[11]);
	  w=(local[13]->c.vec.v[i]);}
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRNTSIZE(ctx,1,local+13); /*print-size*/
	local[10] = w;
	local[13]= local[10];
	local[14]= makeint(20);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF34723;
	local[10] = makeint(5);
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)TERPRI(ctx,1,local+13); /*terpri*/
	local[13]= w;
	goto IF34724;
IF34723:
	local[13]= NIL;
IF34724:
	if (loadglobal(fqv[14])==NIL) goto IF34742;
	local[13]= argv[0];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SLOT(ctx,3,local+13); /*slot*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
	goto IF34743;
IF34742:
	local[13]= argv[0];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SLOT(ctx,3,local+13); /*slot*/
	local[13]= w;
	local[14]= local[0];
	local[15]= (pointer)((integer_t)(local[10])+4);
	local[16]= makeint(78);
	ctx->vsp=local+17;
	w=(*ftab[1])(ctx,4,local+13,&ftab[1],fqv[16]); /*pprint*/
	local[13]= w;
IF34743:
	local[11] = (pointer)((integer_t)(local[11])+4);
	goto WHL34691;
WHX34692:
	local[13]= NIL;
BLK34693:
	w = NIL;
	local[11]= w;
IF34656:
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)FINOUT(ctx,1,local+11); /*finish-output*/
	local[7]= w;
	ctx->vsp=local+8;
	unbindx(ctx,2);
	w = local[7];
	local[0]= w;
BLK34565:
	ctx->vsp=local; return(local[0]);}

/*describe-list*/
static pointer F34284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT34790;}
	local[0]= loadglobal(fqv[13]);
ENT34790:
ENT34789:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET34818,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w!=NIL) goto IF34822;
	local[3]= local[0];
	local[4]= fqv[18];
	local[5]= fqv[19];
	local[6]= fqv[20];
	local[7]= fqv[21];
	local[8]= fqv[22];
	local[9]= fqv[23];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,7,local+3,&ftab[2],fqv[24]); /*open*/
	local[1] = w;
	local[3]= local[1];
	goto IF34823;
IF34822:
	local[3]= NIL;
IF34823:
	local[3]= argv[0];
	w = local[2];
	ctx->vsp=local+4;
	w=FLET34818(ctx,1,local+3,w);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w!=NIL) goto IF34858;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)CLOSE(ctx,1,local+3); /*close*/
	local[3]= w;
	goto IF34859;
IF34858:
	local[3]= NIL;
IF34859:
	w = local[3];
	local[0]= w;
BLK34787:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET34818(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON34882;
	local[0]= NIL;
	local[1]= argv[0];
WHL34907:
	if (local[1]==NIL) goto WHX34908;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	w = env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=FLET34818(ctx,1,local+2,w);
	goto WHL34907;
WHX34908:
	local[2]= NIL;
BLK34909:
	w = NIL;
	local[0]= w;
	goto CON34880;
CON34882:
	local[0]= env->c.clo.env2[1];
	local[1]= fqv[25];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)F34282(ctx,2,local+0); /*describe*/
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= w;
	goto CON34880;
CON34963:
	local[0]= NIL;
CON34880:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*apropos*/
static pointer F34287(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT34990;}
	local[0]= NIL;
ENT34990:
ENT34989:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	argv[0] = w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET35016,env,argv,local);
	if (local[0]==NIL) goto CON35022;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FINDPACKAGE(ctx,1,local+3); /*find-package*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= *(ovafptr(local[3],fqv[27]));
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL35058:
	local[7]= local[4];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto WHX35059;
	local[7]= local[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[2] = w;
	local[4] = (pointer)((integer_t)(local[4])+4);
	w = local[2];
	if (!issymbol(w)) goto IF35089;
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[26]); /*string*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[28]); /*substringp*/
	if (w==NIL) goto IF35099;
	local[7]= local[2];
	w = local[1];
	ctx->vsp=local+8;
	w=FLET35016(ctx,1,local+7,w);
	local[7]= w;
	goto IF35100;
IF35099:
	local[7]= NIL;
IF35100:
	goto IF35090;
IF35089:
	local[7]= NIL;
IF35090:
	goto WHL35058;
WHX35059:
	local[7]= NIL;
BLK35060:
	w = NIL;
	local[2]= w;
	goto CON35020;
CON35022:
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
WHL35144:
	if (local[3]==NIL) goto WHX35145;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= *(ovafptr(local[5],fqv[27]));
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL35223:
	local[9]= local[6];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX35224;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[4] = w;
	local[6] = (pointer)((integer_t)(local[6])+4);
	w = local[4];
	if (!issymbol(w)) goto IF35254;
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[26]); /*string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[28]); /*substringp*/
	if (w==NIL) goto IF35264;
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	w=FLET35016(ctx,1,local+9,w);
	local[9]= w;
	goto IF35265;
IF35264:
	local[9]= NIL;
IF35265:
	goto IF35255;
IF35254:
	local[9]= NIL;
IF35255:
	goto WHL35223;
WHX35224:
	local[9]= NIL;
BLK35225:
	w = NIL;
	goto WHL35144;
WHX35145:
	local[4]= NIL;
BLK35146:
	w = NIL;
	local[2]= w;
	goto CON35020;
CON35121:
	local[2]= NIL;
CON35020:
	w = NIL;
	local[0]= w;
BLK34987:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET35016(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)FBOUNDP(ctx,1,local+3); /*fboundp*/
	if (w==NIL) goto IF35303;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[30]); /*special-form-p*/
	if (w==NIL) goto IF35311;
	local[3]= fqv[31];
	goto IF35312;
IF35311:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[32]); /*macro-function*/
	if (w==NIL) goto IF35320;
	local[3]= fqv[33];
	goto IF35321;
IF35320:
	local[3]= fqv[34];
IF35321:
IF35312:
	goto IF35304;
IF35303:
	local[3]= fqv[35];
IF35304:
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)BOUNDP(ctx,1,local+4); /*boundp*/
	if (w==NIL) goto IF35329;
	local[4]= argv[0];
	local[5]= fqv[36];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[37]!=local[5]) goto IF35354;
	local[5]= fqv[38];
	goto IF35355;
IF35354:
	local[5]= local[4];
	if (fqv[39]!=local[5]) goto IF35362;
	local[5]= fqv[40];
	goto IF35363;
IF35362:
	local[5]= local[4];
	if (fqv[41]!=local[5]) goto IF35370;
	local[5]= fqv[42];
	goto IF35371;
IF35370:
	if (T==NIL) goto IF35378;
	local[5]= fqv[43];
	goto IF35379;
IF35378:
	local[5]= NIL;
IF35379:
IF35371:
IF35363:
IF35355:
	w = local[5];
	local[4]= w;
	goto IF35330;
IF35329:
	local[4]= fqv[44];
IF35330:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)BOUNDP(ctx,1,local+5); /*boundp*/
	if (w==NIL) goto IF35384;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SYMBNDVALUE(ctx,1,local+5); /*symbol-bound-value*/
	local[5]= w;
	goto IF35385;
IF35384:
	local[5]= fqv[45];
IF35385:
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*apropos-list*/
static pointer F34289(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35401;}
	local[0]= NIL;
ENT35401:
ENT35400:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[26]); /*string*/
	argv[0] = w;
	if (local[0]==NIL) goto CON35435;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FINDPACKAGE(ctx,1,local+3); /*find-package*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= *(ovafptr(local[3],fqv[27]));
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL35471:
	local[7]= local[4];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto WHX35472;
	local[7]= local[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[2] = w;
	local[4] = (pointer)((integer_t)(local[4])+4);
	w = local[2];
	if (!issymbol(w)) goto IF35502;
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[26]); /*string*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[28]); /*substringp*/
	if (w==NIL) goto IF35512;
	local[7]= local[2];
	w = local[1];
	ctx->vsp=local+8;
	local[1] = cons(ctx,local[7],w);
	local[7]= local[1];
	goto IF35513;
IF35512:
	local[7]= NIL;
IF35513:
	goto IF35503;
IF35502:
	local[7]= NIL;
IF35503:
	goto WHL35471;
WHX35472:
	local[7]= NIL;
BLK35473:
	w = NIL;
	local[2]= w;
	goto CON35433;
CON35435:
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
WHL35561:
	if (local[3]==NIL) goto WHX35562;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= *(ovafptr(local[5],fqv[27]));
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL35640:
	local[9]= local[6];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX35641;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[4] = w;
	local[6] = (pointer)((integer_t)(local[6])+4);
	w = local[4];
	if (!issymbol(w)) goto IF35671;
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[26]); /*string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[28]); /*substringp*/
	if (w==NIL) goto IF35681;
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
	goto IF35682;
IF35681:
	local[9]= NIL;
IF35682:
	goto IF35672;
IF35671:
	local[9]= NIL;
IF35672:
	goto WHL35640;
WHX35641:
	local[9]= NIL;
BLK35642:
	w = NIL;
	goto WHL35561;
WHX35562:
	local[4]= NIL;
BLK35563:
	w = NIL;
	local[2]= w;
	goto CON35433;
CON35538:
	local[2]= NIL;
CON35433:
	w = local[1];
	local[0]= w;
BLK35398:
	ctx->vsp=local; return(local[0]);}

/*dump-string*/
static pointer F34292(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35723;}
	local[0]= loadglobal(fqv[13]);
ENT35723:
	if (n>=3) { local[1]=(argv[2]); goto ENT35722;}
	local[1]= fqv[46];
ENT35722:
	if (n>=4) { local[2]=(argv[3]); goto ENT35721;}
	local[2]= makeint(16);
ENT35721:
ENT35720:
	if (n>4) maerror();
	local[3]= makeint(0);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[1];
	local[7]= fqv[47];
	local[8]= fqv[48];
	local[9]= (pointer)get_sym_func(fqv[49]);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,4,local+6,&ftab[7],fqv[50]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
WHL35789:
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX35790;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MOD(ctx,2,local+6); /*mod*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF35798;
	local[6]= local[0];
	local[7]= fqv[51];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF35799;
IF35798:
	local[6]= NIL;
IF35799:
	local[6]= local[5];
	local[7]= local[6];
	if (fqv[52]!=local[7]) goto IF35825;
	local[7]= local[0];
	local[8]= fqv[53];
	local[9]= argv[0];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF35826;
IF35825:
	local[7]= local[6];
	if (fqv[54]!=local[7]) goto IF35840;
	local[7]= local[0];
	local[8]= fqv[55];
	local[9]= makeint(65535);
	local[10]= argv[0];
	local[11]= local[3];
	local[12]= fqv[56];
	ctx->vsp=local+13;
	w=(pointer)PEEK(ctx,3,local+10); /*system:peek*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LOGAND(ctx,2,local+9); /*logand*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF35841;
IF35840:
	local[7]= local[6];
	if (fqv[57]!=local[7]) goto IF35862;
	local[7]= local[0];
	local[8]= fqv[58];
	local[9]= argv[0];
	local[10]= local[3];
	local[11]= fqv[59];
	ctx->vsp=local+12;
	w=(pointer)PEEK(ctx,3,local+9); /*system:peek*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF35863;
IF35862:
	local[7]= NIL;
IF35863:
IF35841:
IF35826:
	w = local[7];
	local[6]= local[3];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MOD(ctx,2,local+6); /*mod*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF35894;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)TERPRI(ctx,1,local+6); /*terpri*/
	local[6]= w;
	goto IF35895;
IF35894:
	local[6]= NIL;
IF35895:
	goto WHL35789;
WHX35790:
	local[6]= NIL;
BLK35791:
	w = local[6];
	local[0]= w;
BLK35718:
	ctx->vsp=local; return(local[0]);}

/*break*/
static pointer F34295(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT35913;}
	local[0]= NIL;
	local[1]= fqv[60];
	local[2]= (pointer)((integer_t)(loadglobal(fqv[61]))+4);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
ENT35913:
ENT35912:
	if (n>1) maerror();
	local[1]= (pointer)((integer_t)(loadglobal(fqv[61]))+4);
	w = local[1];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[61],w);
	{jmp_buf jb;
	w = loadglobal(fqv[61]);
	ctx->vsp=local+5;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT35949;}
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[0])(ctx,1,local+11,&ftab[0],fqv[7]); /*reploop*/
CAT35949:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK35910:
	ctx->vsp=local; return(local[0]);}

/*setbreak*/
static pointer F34297(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w!=NIL) goto IF35973;
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF35974;
IF35973:
	local[0]= NIL;
IF35974:
	local[0]= argv[0];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w!=NIL) goto IF35988;
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	local[2]= fqv[63];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= argv[0];
	local[1]= fqv[64];
	local[2]= fqv[65];
	local[3]= fqv[66];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[67];
	local[4]= fqv[68];
	local[5]= fqv[69];
	local[6]= fqv[70];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[70];
	local[8]= fqv[63];
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
	local[6]= fqv[66];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[71];
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
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	local[0]= argv[0];
	goto IF35989;
IF35988:
	local[0]= NIL;
IF35989:
	w = local[0];
	local[0]= w;
BLK35962:
	ctx->vsp=local; return(local[0]);}

/*unbreak*/
static pointer F34299(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w==NIL) goto IF36095;
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[63];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[63];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= w;
	goto IF36096;
IF36095:
	local[0]= NIL;
IF36096:
	w = local[0];
	local[0]= w;
BLK36084:
	ctx->vsp=local; return(local[0]);}

/*timing*/
static pointer F36128(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST36131:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[72];
	local[2]= fqv[73];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[74];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[75];
	local[5]= fqv[76];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[77];
	local[6]= fqv[78];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[79];
	local[7]= fqv[80];
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
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[0];
	local[4]= fqv[81];
	local[5]= fqv[73];
	local[6]= fqv[82];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[83];
	local[6]= fqv[73];
	local[7]= fqv[84];
	local[8]= fqv[73];
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
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[83];
	local[5]= fqv[79];
	local[6]= fqv[76];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[0];
	local[6]= fqv[81];
	local[7]= fqv[74];
	local[8]= fqv[85];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[83];
	local[8]= fqv[74];
	local[9]= fqv[84];
	local[10]= fqv[74];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
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
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[83];
	local[7]= fqv[77];
	local[8]= fqv[86];
	local[9]= fqv[76];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[79];
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
	local[7]= fqv[4];
	local[8]= fqv[87];
	local[9]= fqv[88];
	local[10]= fqv[89];
	local[11]= fqv[90];
	local[12]= fqv[89];
	local[13]= fqv[91];
	local[14]= fqv[92];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[86];
	local[14]= fqv[79];
	local[15]= fqv[75];
	local[16]= fqv[77];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
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
BLK36129:
	ctx->vsp=local; return(local[0]);}

/*btrace*/
static pointer F34302(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT36414;}
	local[0]= makeint(10);
ENT36414:
ENT36413:
	if (n>1) maerror();
	local[1]= (pointer)get_sym_func(fqv[93]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)BKTRACE(ctx,1,local+2); /*system::bktrace*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)MAPC(ctx,2,local+1); /*mapc*/
	w = T;
	local[0]= w;
BLK36411:
	ctx->vsp=local; return(local[0]);}

/*eval-dynamic*/
static pointer F34305(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT36446;}
	ctx->vsp=local+0;
	w=(pointer)LISTBINDINGS(ctx,0,local+0); /*system:list-all-bindings*/
	local[0]= w;
ENT36446:
ENT36445:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL36488:
	if (local[3]==NIL) goto WHX36489;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=local[4]) goto IF36537;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK36443;
	goto IF36538;
IF36537:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VECTORP(ctx,1,local+4); /*vectorp*/
	if (w==NIL) goto IF36556;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,2,local+4,&ftab[8],fqv[94]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF36556;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)GETCLASS(ctx,1,local+5); /*class*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SLOT(ctx,3,local+4); /*slot*/
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK36443;
	goto IF36557;
IF36556:
	local[4]= NIL;
IF36557:
IF36538:
	goto WHL36488;
WHX36489:
	local[4]= NIL;
BLK36490:
	w = NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)BOUNDP(ctx,1,local+2); /*boundp*/
	if (w==NIL) goto IF36606;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= w;
	goto IF36607;
IF36606:
	local[2]= fqv[95];
IF36607:
	w = local[2];
	local[0]= w;
BLK36443:
	ctx->vsp=local; return(local[0]);}

/*step-hook*/
static pointer F34307(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= T;
	local[3]= makeint(10);
	local[4]= makeint(5);
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[14],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[15],w);
	local[11]= (pointer)((integer_t)(loadglobal(fqv[96]))+4);
	storeglobal(fqv[96],local[11]);
	local[11]= loadglobal(fqv[96]);
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,1,local+11,&ftab[9],fqv[97]); /*spaces*/
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)PRINT(ctx,1,local+11); /*print*/
WHL36682:
	if (local[2]==NIL) goto WHX36683;
	local[11]= T;
	local[12]= fqv[98];
	local[13]= loadglobal(fqv[96]);
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	ctx->vsp=local+11;
	w=(pointer)FINOUT(ctx,0,local+11); /*finish-output*/
	local[11]= loadglobal(fqv[99]);
	w = local[11];
	ctx->vsp=local+12;
	bindspecial(ctx,fqv[100],w);
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,0,local+15); /*read*/
	local[15]= w;
	ctx->vsp=local+16;
	unbindx(ctx,1);
	w = local[15];
	local[0] = w;
	local[11]= local[0];
	local[12]= local[11];
	w = fqv[101];
	if (memq(local[12],w)==NIL) goto IF36734;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,1,local+12,&ftab[1],fqv[16]); /*pprint*/
	local[12]= w;
	goto IF36735;
IF36734:
	local[12]= local[11];
	w = fqv[102];
	if (memq(local[12],w)==NIL) goto IF36748;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto IF36749;
IF36748:
	local[12]= local[11];
	w = fqv[103];
	if (memq(local[12],w)==NIL) goto IF36762;
	local[12]= argv[0];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)EVAL(ctx,2,local+12); /*eval*/
	local[1] = w;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= T;
	local[13]= fqv[104];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[2] = NIL;
	local[12]= local[2];
	goto IF36763;
IF36762:
	local[12]= local[11];
	w = fqv[105];
	if (memq(local[12],w)==NIL) goto IF36799;
	local[12]= argv[0];
	local[13]= (pointer)get_sym_func(fqv[67]);
	local[14]= argv[1];
	ctx->vsp=local+15;
	w=(pointer)EVALHOOK(ctx,3,local+12); /*evalhook*/
	local[1] = w;
	local[12]= T;
	local[13]= fqv[106];
	local[14]= argv[0];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,4,local+12); /*format*/
	local[2] = NIL;
	local[12]= local[2];
	goto IF36800;
IF36799:
	local[12]= local[11];
	w = fqv[107];
	if (memq(local[12],w)==NIL) goto IF36835;
	local[12]= fqv[108];
	w = fqv[109];
	ctx->vsp=local+13;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF36836;
IF36835:
	local[12]= local[11];
	w = fqv[110];
	if (memq(local[12],w)==NIL) goto IF36853;
	local[12]= T;
	local[13]= fqv[111];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[112];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[113];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[114];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[115];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= w;
	goto IF36854;
IF36853:
	local[12]= local[11];
	if (fqv[116]!=local[12]) goto IF36881;
	ctx->vsp=local+12;
	w=(pointer)READ(ctx,0,local+12); /*read*/
	local[0] = w;
	w = local[0];
	if (!issymbol(w)) goto CON36902;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)F34305(ctx,1,local+12); /*eval-dynamic*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto CON36900;
CON36902:
	{jmp_buf jb;
	w = fqv[117];
	ctx->vsp=local+12;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT36916;}
	local[18]= fqv[118];
	w = local[18];
	ctx->vsp=local+19;
	bindspecial(ctx,fqv[119],w);
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)EVAL(ctx,1,local+22); /*eval*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)PRINT(ctx,1,local+22); /*print*/
	local[22]= w;
	ctx->vsp=local+23;
	unbindx(ctx,1);
	w = local[22];
CAT36916:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[12]= w;
	goto CON36900;
CON36912:
	local[12]= NIL;
CON36900:
	goto IF36882;
IF36881:
	if (T==NIL) goto IF36945;
	local[12]= T;
	local[13]= fqv[120];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= w;
	goto IF36946;
IF36945:
	local[12]= NIL;
IF36946:
IF36882:
IF36854:
IF36836:
IF36800:
IF36763:
IF36749:
IF36735:
	w = local[12];
	goto WHL36682;
WHX36683:
	local[11]= NIL;
BLK36684:
	local[11]= (pointer)((integer_t)(loadglobal(fqv[96]))-4);
	storeglobal(fqv[96],local[11]);
	local[11]= local[1];
	ctx->vsp=local+12;
	unbindx(ctx,2);
	w = local[11];
	local[0]= w;
BLK36622:
	ctx->vsp=local; return(local[0]);}

/*step*/
static pointer F36968(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[121];
	local[1]= fqv[83];
	local[2]= fqv[96];
	local[3]= fqv[122];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[123];
	local[3]= fqv[70];
	local[4]= fqv[108];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[124];
	local[5]= fqv[70];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[125];
	local[7]= fqv[70];
	local[8]= fqv[67];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
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
BLK36969:
	ctx->vsp=local; return(local[0]);}

/*tracex*/
static pointer F34311(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= (pointer)((integer_t)(loadglobal(fqv[96]))+4);
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[96],w);
	local[6]= T;
	local[7]= fqv[126];
	local[8]= loadglobal(fqv[96]);
	local[9]= argv[0];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= argv[0];
	local[7]= fqv[127];
	ctx->vsp=local+8;
	w=(pointer)GETPROP(ctx,2,local+6); /*get*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[0] = w;
	local[6]= T;
	local[7]= fqv[128];
	local[8]= loadglobal(fqv[96]);
	local[9]= local[0];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= loadglobal(fqv[96]);
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	local[6]= w;
	if (w==NIL) goto AND37112;
	ctx->vsp=local+6;
	w=(pointer)TERPRI(ctx,0,local+6); /*terpri*/
	local[6]= w;
AND37112:
	local[6]= local[0];
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK37053:
	ctx->vsp=local; return(local[0]);}

/*trace1*/
static pointer F34313(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[129]); /*functionp*/
	if (w!=NIL) goto IF37148;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK37127;
	goto IF37149;
IF37148:
	local[1]= NIL;
IF37149:
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[127];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= argv[0];
	local[2]= fqv[64];
	local[3]= fqv[130];
	local[4]= fqv[131];
	local[5]= fqv[70];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[132];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*setfunc*/
	w = argv[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK37127;
	w = local[1];
	local[0]= w;
BLK37127:
	ctx->vsp=local; return(local[0]);}

/*trace*/
static pointer F37204(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST37207:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[133];
	local[2]= fqv[134];
	local[3]= fqv[70];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[135];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[136];
	local[4]= fqv[49];
	local[5]= fqv[134];
	local[6]= fqv[135];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[137];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[138];
	local[6]= fqv[139];
	local[7]= fqv[134];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[140];
	local[7]= fqv[141];
	local[8]= fqv[134];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[87];
	local[7]= fqv[142];
	local[8]= fqv[134];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[143];
	local[9]= fqv[134];
	local[10]= fqv[135];
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
BLK37205:
	ctx->vsp=local; return(local[0]);}

/*untrace*/
static pointer F37338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST37341:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]!=NIL) goto IF37351;
	local[0] = loadglobal(fqv[135]);
	local[1]= local[0];
	goto IF37352;
IF37351:
	local[1]= NIL;
IF37352:
	local[1]= fqv[133];
	local[2]= fqv[134];
	local[3]= fqv[70];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[135];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[136];
	local[4]= fqv[49];
	local[5]= fqv[134];
	local[6]= fqv[135];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[144];
	local[6]= fqv[125];
	local[7]= fqv[134];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[69];
	local[8]= fqv[134];
	local[9]= fqv[70];
	local[10]= fqv[127];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
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
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[83];
	local[7]= fqv[135];
	local[8]= fqv[145];
	local[9]= fqv[134];
	local[10]= fqv[135];
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
BLK37339:
	ctx->vsp=local; return(local[0]);}

/*inspect1*/
static pointer F34318(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT37488;}
	local[0]= NIL;
ENT37488:
ENT37487:
	if (n>2) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET37504,env,argv,local);
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	w=FLET37504(ctx,1,local+2,w);
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= *(ovafptr(w,fqv[146]));
	local[4]= NIL;
TAG37536:
	if (NIL==NIL) goto IF37541;
	w = NIL;
	ctx->vsp=local+5;
	local[2]=w;
	goto BLK37510;
	goto IF37542;
IF37541:
	local[5]= NIL;
IF37542:
	w = local[2];
	if (!issymbol(w)) goto IF37562;
	local[5]= local[2]->c.obj.iv[4];
	{ register integer_t i=intval(makeint(0));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CHUPCASE(ctx,1,local+5); /*char-upcase*/
	local[5]= w;
	goto IF37563;
IF37562:
	local[5]= local[2];
IF37563:
	local[6]= local[5];
	if (fqv[147]!=local[6]) goto IF37582;
	local[6]= argv[0];
	local[7]= loadglobal(fqv[148]);
	local[8]= makeint(2);
	local[9]= makeint(3);
	ctx->vsp=local+10;
	w=(pointer)F34282(ctx,4,local+6); /*describe*/
	local[6]= w;
	goto IF37583;
IF37582:
	local[6]= local[5];
	if (fqv[149]!=local[6]) goto IF37595;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[16]); /*pprint*/
	local[6]= w;
	goto IF37596;
IF37595:
	local[6]= local[5];
	if (fqv[150]!=local[6]) goto IF37606;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[2] = w;
	local[6]= loadglobal(fqv[26]);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[26]); /*string*/
	local[7]= w;
	local[8]= fqv[151];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,1,local+9,&ftab[3],fqv[26]); /*string*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)CONCATENATE(ctx,4,local+6); /*concatenate*/
	local[4] = w;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[152]); /*find*/
	if (w!=NIL) goto OR37643;
	w = local[2];
	if (!isint(w)) goto AND37652;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR37657;
	w = argv[0];
	if (iscons(w)) goto OR37657;
	goto AND37652;
OR37657:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto AND37652;
	goto OR37643;
AND37652:
	goto IF37641;
OR37643:
	w = local[2];
	if (!isint(w)) goto IF37675;
	local[6]= argv[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	goto IF37676;
IF37675:
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SLOT(ctx,3,local+6); /*slot*/
	local[6]= w;
IF37676:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F34318(ctx,2,local+6); /*inspect1*/
	local[6]= w;
	goto IF37642;
IF37641:
	local[6]= makeint(4);
	local[7]= fqv[153];
	ctx->vsp=local+8;
	w=(pointer)F34277(ctx,2,local+6); /*warning-message*/
	local[6]= w;
IF37642:
	goto IF37607;
IF37606:
	local[6]= local[5];
	if (fqv[154]!=local[6]) goto IF37696;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK37485;
	goto IF37697;
IF37696:
	local[6]= local[5];
	if (fqv[155]!=local[6]) goto IF37707;
	local[6]= fqv[156];
	w = NIL;
	ctx->vsp=local+7;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF37708;
IF37707:
	local[6]= local[5];
	if (fqv[157]!=local[6]) goto IF37720;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[2] = w;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[4] = w;
	w = local[2];
	if (!isint(w)) goto IF37743;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR37749;
	w = argv[0];
	if (iscons(w)) goto OR37749;
	goto IF37743;
OR37749:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto IF37743;
	local[6]= argv[0];
	local[7]= local[2];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= w;
	goto IF37744;
IF37743:
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[152]); /*find*/
	if (w==NIL) goto IF37772;
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SETSLOT(ctx,4,local+6); /*setslot*/
	local[6]= w;
	goto IF37773;
IF37772:
	local[6]= NIL;
IF37773:
IF37744:
	goto IF37721;
IF37720:
	local[6]= local[5];
	w = fqv[158];
	if (memq(local[6],w)==NIL) goto IF37790;
	local[6]= T;
	local[7]= fqv[159];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,2,local+6); /*format*/
	local[6]= w;
	goto IF37791;
IF37790:
	if (T==NIL) goto IF37803;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[152]); /*find*/
	if (w==NIL) goto CON37810;
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SLOT(ctx,3,local+6); /*slot*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F34282(ctx,1,local+6); /*describe*/
	local[6]= w;
	goto CON37808;
CON37810:
	w = local[2];
	if (!isint(w)) goto CON37827;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR37832;
	w = argv[0];
	if (iscons(w)) goto OR37832;
	goto CON37827;
OR37832:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto CON37827;
	local[6]= argv[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	local[6]= w;
	goto CON37808;
CON37827:
	{jmp_buf jb;
	w = fqv[160];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT37859;}
	local[12]= fqv[161];
	w = local[12];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[119],w);
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)EVAL(ctx,1,local+16); /*eval*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PRINT(ctx,1,local+16); /*print*/
	local[16]= w;
	ctx->vsp=local+17;
	unbindx(ctx,1);
	w = local[16];
CAT37859:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= w;
	goto CON37808;
CON37855:
	local[6]= NIL;
CON37808:
	goto IF37804;
IF37803:
	local[6]= NIL;
IF37804:
IF37791:
IF37721:
IF37708:
IF37697:
IF37607:
IF37596:
IF37583:
	w = local[6];
	local[5]= local[0];
	w = local[1];
	ctx->vsp=local+6;
	w=FLET37504(ctx,1,local+5,w);
	local[2] = w;
	local[4] = NIL;
	ctx->vsp=local+5;
	goto TAG37536;
	w = NIL;
	local[2]= w;
BLK37510:
	w = local[2];
	local[0]= w;
BLK37485:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET37504(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[162];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= T;
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= loadglobal(fqv[163]);
	local[1]= NIL;
	local[2]= fqv[164];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,3,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*inspect*/
static pointer F37932(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[123];
	local[1]= fqv[70];
	local[2]= fqv[156];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[165];
	local[3]= argv[0];
	local[4]= fqv[4];
	local[5]= fqv[137];
	local[6]= fqv[166];
	local[7]= fqv[70];
	local[8]= argv[0];
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
BLK37933:
	ctx->vsp=local; return(local[0]);}

/*time-func*/
static pointer F34320(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[64];
	local[1]= fqv[65];
	local[2]= fqv[66];
	local[3]= fqv[167];
	local[4]= fqv[168];
	local[5]= fqv[169];
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
	local[2]= fqv[170];
	local[3]= fqv[69];
	local[4]= fqv[70];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[171];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[83];
	local[4]= fqv[168];
	local[5]= fqv[172];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[169];
	local[7]= fqv[2];
	local[8]= fqv[69];
	local[9]= fqv[70];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[173];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[66];
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
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[170];
	local[5]= fqv[69];
	local[6]= fqv[70];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[174];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[86];
	local[7]= fqv[172];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[168];
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
	local[5]= fqv[169];
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
BLK37996:
	ctx->vsp=local; return(local[0]);}

/*time*/
static pointer F38169(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT38173;}
	local[0]= NIL;
ENT38173:
ENT38172:
	if (n>2) maerror();
	local[1]= fqv[121];
	local[2]= fqv[136];
	local[3]= fqv[69];
	local[4]= fqv[70];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[173];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[175];
	local[5]= fqv[176];
	local[6]= fqv[70];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[70];
	local[8]= fqv[177];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[70];
	local[9]= fqv[178];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[69];
	local[10]= fqv[70];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[171];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[70];
	local[11]= fqv[179];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[70];
	local[12]= fqv[180];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[70];
	local[13]= fqv[181];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[90];
	local[14]= fqv[182];
	local[15]= fqv[69];
	local[16]= fqv[70];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[174];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[70];
	local[15]= fqv[183];
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
	local[6]= fqv[184];
	local[7]= local[0];
	local[8]= fqv[144];
	local[9]= fqv[69];
	local[10]= fqv[70];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[171];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[185];
	local[11]= fqv[69];
	local[12]= fqv[70];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[174];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[186];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
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
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[187];
	local[5]= fqv[1];
	local[6]= fqv[139];
	local[7]= fqv[70];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[32];
	local[7]= fqv[70];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
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
	local[5]= fqv[188];
	local[6]= fqv[189];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[87];
	local[6]= fqv[72];
	local[7]= fqv[190];
	local[8]= fqv[125];
	local[9]= fqv[70];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
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
	local[7]= w;
	local[8]= fqv[144];
	local[9]= fqv[69];
	local[10]= fqv[70];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[171];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[191];
	local[11]= fqv[69];
	local[12]= fqv[70];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[174];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[192];
	local[13]= fqv[69];
	local[14]= fqv[70];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[173];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[190];
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
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[193];
	local[10]= fqv[70];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[194];
	local[12]= fqv[70];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
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
	local[10]= fqv[143];
	local[11]= fqv[70];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[195];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[176];
	local[12]= fqv[70];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[70];
	local[14]= fqv[177];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[70];
	local[15]= fqv[196];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[70];
	local[16]= fqv[197];
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
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
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
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK38170:
	ctx->vsp=local; return(local[0]);}

/*untime*/
static pointer F38707(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[121];
	local[1]= fqv[198];
	local[2]= fqv[69];
	local[3]= fqv[70];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[173];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[83];
	local[4]= fqv[195];
	local[5]= fqv[145];
	local[6]= fqv[70];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[195];
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
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[193];
	local[5]= fqv[70];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[69];
	local[7]= fqv[70];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[173];
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
	local[5]= fqv[70];
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
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK38708:
	ctx->vsp=local; return(local[0]);}

/*list-symbols*/
static pointer F34321(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[1];
WHL38867:
	if (local[2]==NIL) goto WHX38868;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)FINDPACKAGE(ctx,1,local+4); /*find-package*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= *(ovafptr(local[4],fqv[27]));
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL38946:
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto WHX38947;
	local[8]= local[6];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[3] = w;
	local[5] = (pointer)((integer_t)(local[5])+4);
	w = local[3];
	if (!issymbol(w)) goto IF38977;
	local[8]= argv[0];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	if (w==NIL) goto IF38986;
	local[8]= local[3];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[8]= local[0];
	goto IF38987;
IF38986:
	local[8]= NIL;
IF38987:
	goto IF38978;
IF38977:
	local[8]= NIL;
IF38978:
	goto WHL38946;
WHX38947:
	local[8]= NIL;
BLK38948:
	w = NIL;
	goto WHL38867;
WHX38868:
	local[3]= NIL;
BLK38869:
	w = NIL;
	local[1]= local[0];
	local[2]= (pointer)get_sym_func(fqv[199]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,2,local+1); /*sort*/
	local[0]= w;
BLK38829:
	ctx->vsp=local; return(local[0]);}

/*functions*/
static pointer F34322(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39024;}
	local[0]= fqv[200];
ENT39024:
ENT39023:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[26]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39047,env,argv,local);
	if (local[1]==NIL) goto IF39050;
	local[3]= local[1];
	goto IF39051;
IF39050:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39051:
	ctx->vsp=local+4;
	w=(pointer)F34321(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39021:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39047(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND39070;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[28]); /*substringp*/
	local[0]= w;
AND39070:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*special-variables*/
static pointer F34323(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39089;}
	local[0]= fqv[201];
ENT39089:
ENT39088:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[26]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39112,env,argv,local);
	if (local[1]==NIL) goto IF39115;
	local[3]= local[1];
	goto IF39116;
IF39115:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39116:
	ctx->vsp=local+4;
	w=(pointer)F34321(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39086:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39112(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39135;
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
	if (w==NIL) goto AND39135;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[28]); /*substringp*/
	local[0]= w;
AND39135:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*global-variables*/
static pointer F34324(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39163;}
	local[0]= fqv[202];
ENT39163:
ENT39162:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[26]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39186,env,argv,local);
	if (local[1]==NIL) goto IF39189;
	local[3]= local[1];
	goto IF39190;
IF39189:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39190:
	ctx->vsp=local+4;
	w=(pointer)F34321(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39160:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39186(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39209;
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
	if (w==NIL) goto AND39209;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[28]); /*substringp*/
	local[0]= w;
AND39209:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*variables*/
static pointer F34325(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39237;}
	local[0]= fqv[203];
ENT39237:
ENT39236:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[26]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39260,env,argv,local);
	if (local[1]==NIL) goto IF39263;
	local[3]= local[1];
	goto IF39264;
IF39263:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39264:
	ctx->vsp=local+4;
	w=(pointer)F34321(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39234:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39260(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39283;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[204]); /*constantp*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]==NIL) goto AND39283;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[28]); /*substringp*/
	local[0]= w;
AND39283:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*constants*/
static pointer F34326(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39310;}
	local[0]= fqv[205];
ENT39310:
ENT39309:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39324,env,argv,local);
	if (local[1]==NIL) goto IF39327;
	local[3]= local[1];
	goto IF39328;
IF39327:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39328:
	ctx->vsp=local+4;
	w=(pointer)F34321(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39307:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39324(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[204]); /*constantp*/
	local[0]= w;
	if (w==NIL) goto AND39347;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[28]); /*substringp*/
	local[0]= w;
AND39347:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*methods*/
static pointer F34327(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39367;}
	local[0]= fqv[206];
ENT39367:
	if (n>=2) { local[1]=(argv[1]); goto ENT39366;}
	local[1]= fqv[207];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	local[1]= w;
ENT39366:
ENT39365:
	if (n>2) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39386,env,argv,local);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO39390,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F34321(ctx,2,local+3); /*list-symbols*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[0]= w;
BLK39363:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39386(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[208];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	local[2]= fqv[209];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[210]); /*send-all*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39390(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[28]); /*substringp*/
	local[0]= w;
	if (w==NIL) goto AND39432;
	local[0]= argv[0];
	local[1]= fqv[208];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
AND39432:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*method-list*/
static pointer F34328(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39453;}
	local[0]= T;
ENT39453:
	if (n>=2) { local[1]=(argv[1]); goto ENT39452;}
	local[1]= NIL;
ENT39452:
ENT39451:
	ctx->vsp=local+2;
	local[2]= minilist(ctx,&argv[n],n-2);
	if (local[2]!=NIL) goto IF39471;
	ctx->vsp=local+3;
	w=(pointer)LISTALLCLASSES(ctx,0,local+3); /*system:list-all-classes*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[2] = w;
	local[3]= local[2];
	goto IF39472;
IF39471:
	local[3]= NIL;
IF39472:
	local[3]= NIL;
	local[4]= local[2];
WHL39507:
	if (local[4]==NIL) goto WHX39508;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	local[8]= fqv[211];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,1,local+9,&ftab[14],fqv[212]); /*metaclass-name*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= (pointer)get_sym_func(fqv[213]);
	local[8]= local[3]->c.obj.iv[7];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[6] = w;
	local[7]= NIL;
	local[8]= local[6];
	local[9]= (pointer)get_sym_func(fqv[199]);
	ctx->vsp=local+10;
	w=(pointer)SORT(ctx,2,local+8); /*sort*/
	local[8]= w;
WHL39613:
	if (local[8]==NIL) goto WHX39614;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= local[7];
	local[11]= fqv[214];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[215]); /*documentation*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,2,local+9,&ftab[7],fqv[50]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[5]==NIL) goto IF39682;
	local[9]= local[5];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= makeint(40);
	ctx->vsp=local+11;
	w=(pointer)EQUAL(ctx,2,local+9); /*equal*/
	if (w==NIL) goto IF39682;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,1,local+9,&ftab[16],fqv[216]); /*read-from-string*/
	local[5] = w;
	w = local[5];
	if (!iscons(w)) goto IF39710;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (fqv[217]!=local[9]) goto IF39719;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[9];
	local[9]= w;
	goto IF39720;
IF39719:
	local[9]= NIL;
IF39720:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (fqv[218]!=local[9]) goto IF39767;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[9];
	local[9]= w;
	goto IF39768;
IF39767:
	local[9]= NIL;
IF39768:
	goto IF39711;
IF39710:
	local[9]= NIL;
IF39711:
	goto IF39683;
IF39682:
	local[9]= NIL;
IF39683:
	local[9]= local[0];
	local[10]= fqv[219];
	local[11]= makeint(9);
	local[12]= local[7];
	if (local[1]==NIL) goto IF39818;
	if (local[5]==NIL) goto IF39818;
	local[13]= local[5];
	goto IF39819;
IF39818:
	local[13]= fqv[220];
IF39819:
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,5,local+9); /*format*/
	goto WHL39613;
WHX39614:
	local[9]= NIL;
BLK39615:
	w = NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)TERPRI(ctx,1,local+7); /*terpri*/
	goto WHL39507;
WHX39508:
	local[5]= NIL;
BLK39509:
	w = NIL;
	local[0]= w;
BLK39449:
	ctx->vsp=local; return(local[0]);}

/*more*/
static pointer F39842(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[221];
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[222];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	local[2]= fqv[223];
	local[3]= fqv[121];
	local[4]= fqv[224];
	local[5]= fqv[13];
	local[6]= local[0];
	local[7]= fqv[18];
	local[8]= fqv[19];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[225];
	local[6]= local[1];
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
	local[4]= fqv[226];
	local[5]= local[0];
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
BLK39843:
	ctx->vsp=local; return(local[0]);}

/*y-or-n-p*/
static pointer F34329(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39935;}
	local[0]= NIL;
ENT39935:
ENT39934:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= NIL;
	local[3]= NIL;
TAG39952:
	if (local[0]==NIL) goto IF39958;
	local[4]= (pointer)get_sym_func(fqv[4]);
	local[5]= T;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto IF39959;
IF39958:
	local[4]= NIL;
IF39959:
	local[4]= T;
	local[5]= fqv[227];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)READLINE(ctx,1,local+4); /*read-line*/
	local[3] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	if (makeint(0)!=local[4]) goto IF39988;
	ctx->vsp=local+4;
	goto TAG39952;
	goto IF39989;
IF39988:
	local[4]= NIL;
IF39989:
	local[4]= local[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHUPCASE(ctx,1,local+4); /*char-upcase*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[228]!=local[5]) goto IF40016;
	w = T;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK39932;
	goto IF40017;
IF40016:
	local[5]= local[4];
	if (fqv[229]!=local[5]) goto IF40027;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK39932;
	goto IF40028;
IF40027:
	if (T==NIL) goto IF40038;
	ctx->vsp=local+5;
	goto TAG39952;
	goto IF40039;
IF40038:
	local[5]= NIL;
IF40039:
IF40028:
IF40017:
	w = local[5];
	w = NIL;
	local[0]= w;
BLK39932:
	ctx->vsp=local; return(local[0]);}

/*yes-or-no-p*/
static pointer F34330(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40051;}
	local[0]= NIL;
ENT40051:
ENT40050:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= NIL;
	local[3]= NIL;
TAG40068:
	if (local[0]==NIL) goto IF40074;
	local[4]= (pointer)get_sym_func(fqv[4]);
	local[5]= T;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto IF40075;
IF40074:
	local[4]= NIL;
IF40075:
	local[4]= T;
	local[5]= fqv[230];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)READLINE(ctx,1,local+4); /*read-line*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,1,local+4,&ftab[17],fqv[231]); /*string-upcase*/
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[232];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[233]); /*string=*/
	if (w==NIL) goto CON40109;
	w = T;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK40048;
	goto CON40107;
CON40109:
	local[4]= local[3];
	local[5]= fqv[234];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[233]); /*string=*/
	if (w==NIL) goto CON40120;
	w = NIL;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK40048;
	goto CON40107;
CON40120:
	ctx->vsp=local+4;
	goto TAG40068;
	goto CON40107;
CON40130:
	local[4]= NIL;
CON40107:
	w = NIL;
	local[0]= w;
BLK40048:
	ctx->vsp=local; return(local[0]);}

/*bell*/
static pointer F34331(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT40141;}
	local[0]= T;
ENT40141:
ENT40140:
	if (n>2) maerror();
	local[1]= makeint(0);
	local[2]= argv[0];
WHL40178:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX40179;
	local[3]= local[0];
	local[4]= fqv[235];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL40178;
WHX40179:
	local[3]= NIL;
BLK40180:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK40138:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M40219(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= local[0];
	if (fqv[236]!=local[1]) goto IF40245;
	local[1]= fqv[3];
	goto IF40246;
IF40245:
	local[1]= local[0];
	if (fqv[237]!=local[1]) goto IF40255;
	local[1]= fqv[238];
	goto IF40256;
IF40255:
	local[1]= local[0];
	if (fqv[239]!=local[1]) goto IF40265;
	local[1]= fqv[240];
	goto IF40266;
IF40265:
	local[1]= local[0];
	if (fqv[241]!=local[1]) goto IF40275;
	local[1]= fqv[242];
	goto IF40276;
IF40275:
	local[1]= NIL;
IF40276:
IF40266:
IF40256:
IF40246:
	w = local[1];
	local[0]= w;
BLK40220:
	ctx->vsp=local; return(local[0]);}

/*check-methods*/
static pointer F34332(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)LISTALLCLASSES(ctx,0,local+0); /*system:list-all-classes*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[243]);
	local[2]= local[0];
	local[3]= fqv[244];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[210]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[245]);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[213]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,1,local+4,&ftab[19],fqv[246]); /*remove-duplicates*/
	local[4]= w;
	local[5]= T;
	local[6]= fqv[247];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= (pointer)get_sym_func(fqv[248]);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[20])(ctx,2,local+10,&ftab[20],fqv[249]); /*count-if*/
	local[10]= w;
	local[11]= (pointer)get_sym_func(fqv[248]);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(*ftab[21])(ctx,2,local+11,&ftab[21],fqv[250]); /*count-if-not*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,7,local+5); /*format*/
	local[0]= w;
BLK40288:
	ctx->vsp=local; return(local[0]);}

/*pfuncs*/
static pointer F34333(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT40366;}
	ctx->vsp=local+0;
	w=(pointer)F34322(ctx,0,local+0); /*functions*/
	local[0]= w;
ENT40366:
	if (n>=3) { local[1]=(argv[2]); goto ENT40365;}
	local[1]= NIL;
ENT40365:
ENT40364:
	if (n>3) maerror();
	local[2]= argv[0];
	local[3]= fqv[18];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[24]); /*open*/
	local[2]= w;
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP40404,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
WHL40437:
	if (local[7]==NIL) goto WHX40438;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)SYMFUNC(ctx,1,local+8); /*symbol-function*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[22])(ctx,1,local+8,&ftab[22],fqv[248]); /*compiled-function-p*/
	if (w!=NIL) goto OR40489;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,1,local+8,&ftab[6],fqv[32]); /*macro-function*/
	if (w==NIL) goto OR40489;
	goto IF40487;
OR40489:
	local[8]= local[2];
	local[9]= fqv[251];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[23])(ctx,1,local+10,&ftab[23],fqv[252]); /*symbol-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,1,local+10,&ftab[24],fqv[253]); /*string-downcase*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= makeint(40);
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PRNTSIZE(ctx,1,local+9); /*print-size*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[9])(ctx,2,local+8,&ftab[9],fqv[97]); /*spaces*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[25])(ctx,1,local+8,&ftab[25],fqv[254]); /*symbol-package*/
	local[5] = w;
	local[8]= local[2];
	local[9]= fqv[255];
	local[10]= local[5];
	local[11]= fqv[256];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	if (w==NIL) goto IF40543;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,1,local+10,&ftab[26],fqv[257]); /*package-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,1,local+10,&ftab[24],fqv[253]); /*string-downcase*/
	local[10]= w;
	goto IF40544;
IF40543:
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,1,local+10,&ftab[26],fqv[257]); /*package-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,1,local+10,&ftab[17],fqv[231]); /*string-upcase*/
	local[10]= w;
IF40544:
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SYMFUNC(ctx,1,local+11); /*symbol-function*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,1,local+11,&ftab[22],fqv[248]); /*compiled-function-p*/
	if (w==NIL) goto IF40565;
	local[11]= fqv[258];
	goto IF40566;
IF40565:
	local[11]= fqv[259];
IF40566:
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,1,local+12,&ftab[6],fqv[32]); /*macro-function*/
	if (w==NIL) goto IF40575;
	local[12]= fqv[260];
	goto IF40576;
IF40575:
	local[12]= fqv[261];
IF40576:
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,5,local+8); /*format*/
	if (local[1]==NIL) goto IF40585;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[15])(ctx,1,local+8,&ftab[15],fqv[215]); /*documentation*/
	if (w==NIL) goto IF40585;
	local[8]= local[2];
	local[9]= fqv[262];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,1,local+10,&ftab[15],fqv[215]); /*documentation*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	goto IF40586;
IF40585:
	local[8]= NIL;
IF40586:
	goto IF40488;
IF40487:
	local[8]= NIL;
IF40488:
	goto WHL40437;
WHX40438:
	local[8]= NIL;
BLK40439:
	w = NIL;
	ctx->vsp=local+5;
	UWP40404(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK40362:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP40404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[2];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*class-hierarchy*/
static pointer F34334(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40626;}
	local[0]= loadglobal(fqv[263]);
ENT40626:
	if (n>=2) { local[1]=(argv[1]); goto ENT40625;}
	local[1]= T;
ENT40625:
	if (n>=3) { local[2]=(argv[2]); goto ENT40624;}
	local[2]= NIL;
ENT40624:
ENT40623:
	if (n>3) maerror();
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET40650,env,argv,local);
	local[4]= local[0];
	local[5]= fqv[264];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(0);
	w = local[3];
	ctx->vsp=local+6;
	w=FLET40650(ctx,2,local+4,w);
	local[0]= w;
BLK40621:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET40650(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[1];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,2,local+1,&ftab[9],fqv[97]); /*spaces*/
	local[1]= env->c.clo.env2[1];
	local[2]= fqv[265];
	local[3]= local[0];
	local[4]= fqv[209];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[24])(ctx,1,local+3,&ftab[24],fqv[253]); /*string-downcase*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	if (env->c.clo.env2[2]==NIL) goto IF40718;
	local[1]= local[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[27])(ctx,1,local+2,&ftab[27],fqv[266]); /*metaclass-vars*/
	local[2]= w;
	local[3]= loadglobal(fqv[68]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	if (local[1]==NIL) goto IF40747;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[27])(ctx,1,local+3,&ftab[27],fqv[266]); /*metaclass-vars*/
	local[3]= w;
	local[4]= loadglobal(fqv[68]);
	ctx->vsp=local+5;
	w=(pointer)COERCE(ctx,2,local+3); /*coerce*/
	local[3]= w;
	goto IF40748;
IF40747:
	local[3]= NIL;
IF40748:
	local[4]= local[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[28])(ctx,2,local+4,&ftab[28],fqv[267]); /*set-difference*/
	local[2] = w;
	local[4]= (pointer)get_sym_func(fqv[253]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[2] = w;
	local[4]= env->c.clo.env2[1];
	local[5]= fqv[268];
	if (local[2]==NIL) goto IF40785;
	local[6]= local[2];
	goto IF40786;
IF40785:
	local[6]= fqv[269];
IF40786:
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[1]= w;
	goto IF40719;
IF40718:
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= w;
IF40719:
	w = local[1];
	local[0]= NIL;
	local[1]= argv[0];
WHL40816:
	if (local[1]==NIL) goto WHX40817;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[1];
	local[4]= makeint(3);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	w = env->c.clo.env2[3];
	ctx->vsp=local+4;
	w=FLET40650(ctx,2,local+2,w);
	goto WHL40816;
WHX40817:
	local[2]= NIL;
BLK40818:
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*classdef*/
static pointer F34335(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[270];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= fqv[271];
	local[4]= argv[0];
	local[5]= fqv[209];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[270];
	if (local[0]==NIL) goto IF40922;
	local[6]= local[0];
	local[7]= fqv[209];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF40923;
IF40922:
	local[6]= NIL;
IF40923:
	local[7]= fqv[272];
	local[8]= argv[0];
	local[9]= fqv[272];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= loadglobal(fqv[68]);
	ctx->vsp=local+10;
	w=(pointer)COERCE(ctx,2,local+8); /*coerce*/
	local[8]= w;
	if (local[0]==NIL) goto IF40948;
	local[9]= local[0];
	local[10]= fqv[272];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	goto IF40949;
IF40948:
	local[9]= NIL;
IF40949:
	local[10]= loadglobal(fqv[68]);
	ctx->vsp=local+11;
	w=(pointer)COERCE(ctx,2,local+9); /*coerce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,2,local+8,&ftab[28],fqv[267]); /*set-difference*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK40880:
	ctx->vsp=local; return(local[0]);}

/*classdefs*/
static pointer F34336(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40979;}
	local[0]= loadglobal(fqv[263]);
ENT40979:
	if (n>=2) { local[1]=(argv[1]); goto ENT40978;}
	local[1]= T;
ENT40978:
ENT40977:
	if (n>2) maerror();
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F34335(ctx,1,local+2); /*classdef*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,2,local+2,&ftab[1],fqv[16]); /*pprint*/
	local[2]= NIL;
	local[3]= local[0];
	local[4]= fqv[273];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL41024:
	if (local[3]==NIL) goto WHX41025;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)F34336(ctx,2,local+4); /*classdefs*/
	goto WHL41024;
WHX41025:
	local[4]= NIL;
BLK41026:
	w = NIL;
	local[0]= w;
BLK40975:
	ctx->vsp=local; return(local[0]);}

/*remote-error*/
static pointer F34337(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT41085;}
	local[0]= NIL;
ENT41085:
ENT41084:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[274];
	local[3]= loadglobal(fqv[275]);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	if (local[0]==NIL) goto IF41110;
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[276];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF41111;
IF41110:
	local[1]= NIL;
IF41111:
	if (argv[2]==NIL) goto IF41121;
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[277];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF41122;
IF41121:
	local[1]= NIL;
IF41122:
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= fqv[278];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK41082:
	ctx->vsp=local; return(local[0]);}

/*reval*/
static pointer F34338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[279];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[163],w);
	local[3]= argv[0];
	local[4]= fqv[280];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[13],w);
	local[6]= loadglobal(fqv[13]);
	w = local[6];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[5],w);
	local[9]= fqv[281];
	w = local[9];
	ctx->vsp=local+9;
	bindspecial(ctx,fqv[119],w);
	{jmp_buf jb;
	w = fqv[278];
	ctx->vsp=local+12;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT41183;}
	local[18]= argv[0];
	ctx->vsp=local+19;
	w=(pointer)READ(ctx,1,local+18); /*read*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)EVAL(ctx,1,local+18); /*eval*/
	local[18]= w;
	local[19]= argv[0];
	ctx->vsp=local+20;
	w=(pointer)PRINT(ctx,2,local+18); /*print*/
CAT41183:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[12]= w;
	ctx->vsp=local+13;
	unbindx(ctx,4);
	w = local[12];
	local[0]= w;
BLK41142:
	ctx->vsp=local; return(local[0]);}

/*install-remote-function*/
static pointer F34339(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[282];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= T;
	local[1]= fqv[283];
	local[2]= loadglobal(fqv[284]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[285]); /*make-server-socket-stream*/
	local[0]= w;
	local[1]= local[0];
	w = loadglobal(fqv[286]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[286],local[1]);
	local[1]= local[0];
	local[2]= loadglobal(fqv[287]);
	local[3]= fqv[48];
	local[4]= NIL;
	local[5]= fqv[288];
	local[6]= NIL;
	local[7]= fqv[289];
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(*ftab[30])(ctx,8,local+1,&ftab[30],fqv[49]); /*member*/
	if (w!=NIL) goto IF41255;
	local[1]= local[0];
	w = loadglobal(fqv[287]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[287],local[1]);
	goto IF41256;
IF41255:
	local[1]= NIL;
IF41256:
	local[1]= makeint(29);
	local[2]= fqv[290];
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,2,local+1); /*unix:signal*/
	w = local[0];
	if (!isint(w)) goto IF41289;
	local[1]= local[0];
	local[2]= makeint(4);
	local[3]= local[0];
	local[4]= makeint(3);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= w;
	local[4]= makeint(8192);
	ctx->vsp=local+5;
	w=(pointer)LOGIOR(ctx,2,local+3); /*logior*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FCNTL(ctx,3,local+1); /*unix:fcntl*/
	local[1]= local[0];
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)GETPID(ctx,0,local+3); /*unix:getpid*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FCNTL(ctx,3,local+1); /*unix:fcntl*/
	local[1]= w;
	goto IF41290;
IF41289:
	local[1]= local[0];
	local[2]= fqv[291];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF41290:
	local[1]= loadglobal(fqv[292]);
	w = local[0];
	if (!isint(w)) goto IF41324;
	local[2]= local[0];
	goto IF41325;
IF41324:
	local[2]= local[0];
	local[3]= fqv[293];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
IF41325:
	local[3]= loadglobal(fqv[284]);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[0]= w;
BLK41202:
	ctx->vsp=local; return(local[0]);}

/*open-server*/
static pointer F34340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT41344;}
	local[0]= makeint(2048);
ENT41344:
	if (n>=2) { local[1]=(argv[1]); goto ENT41343;}
	local[1]= (pointer)get_sym_func(fqv[278]);
ENT41343:
ENT41342:
	if (n>2) maerror();
	local[2]= fqv[294];
	local[3]= makeint(2);
	local[4]= fqv[295];
	ctx->vsp=local+5;
	w=(pointer)GETHOSTNAME(ctx,0,local+5); /*unix:gethostname*/
	local[5]= w;
	local[6]= fqv[296];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,6,local+2,&ftab[31],fqv[297]); /*make-socket-address*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[32])(ctx,1,local+3,&ftab[32],fqv[298]); /*make-socket-port*/
	local[3]= w;
	storeglobal(fqv[299],w);
	local[3]= loadglobal(fqv[299]);
	local[4]= loadglobal(fqv[300]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON41394;
	local[3]= fqv[301];
	ctx->vsp=local+4;
	w=(pointer)GETHOSTNAME(ctx,0,local+4); /*unix:gethostname*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F34280(ctx,3,local+3); /*warn*/
	local[3]= w;
	goto CON41392;
CON41394:
	local[3]= loadglobal(fqv[299]);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SYSERRLIST(ctx,1,local+3); /*unix:syserrlist*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK41340;
	goto CON41392;
CON41408:
	local[3]= NIL;
CON41392:
	local[3]= local[1];
	storeglobal(fqv[284],local[3]);
	local[3]= loadglobal(fqv[299]);
	local[4]= loadglobal(fqv[287]);
	local[5]= fqv[48];
	local[6]= NIL;
	local[7]= fqv[288];
	local[8]= NIL;
	local[9]= fqv[289];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(*ftab[30])(ctx,8,local+3,&ftab[30],fqv[49]); /*member*/
	if (w!=NIL) goto IF41437;
	local[3]= loadglobal(fqv[299]);
	w = loadglobal(fqv[287]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[287],local[3]);
	goto IF41438;
IF41437:
	local[3]= NIL;
IF41438:
	local[3]= makeint(29);
	local[4]= fqv[290];
	ctx->vsp=local+5;
	w=(pointer)SIGNAL(ctx,2,local+3); /*unix:signal*/
	w = loadglobal(fqv[299]);
	if (!isint(w)) goto IF41469;
	local[3]= loadglobal(fqv[299]);
	local[4]= makeint(4);
	local[5]= loadglobal(fqv[299]);
	local[6]= makeint(3);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)FCNTL(ctx,3,local+5); /*unix:fcntl*/
	local[5]= w;
	local[6]= makeint(8192);
	ctx->vsp=local+7;
	w=(pointer)LOGIOR(ctx,2,local+5); /*logior*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= loadglobal(fqv[299]);
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)GETPID(ctx,0,local+5); /*unix:getpid*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= w;
	goto IF41470;
IF41469:
	local[3]= loadglobal(fqv[299]);
	local[4]= fqv[291];
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
IF41470:
	local[3]= loadglobal(fqv[292]);
	w = loadglobal(fqv[299]);
	if (!isint(w)) goto IF41503;
	local[4]= loadglobal(fqv[299]);
	goto IF41504;
IF41503:
	local[4]= loadglobal(fqv[299]);
	local[5]= fqv[293];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
IF41504:
	local[5]= fqv[302];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[0]= w;
BLK41340:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___eusdebug(ctx,n,argv,env)
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
	local[0]= fqv[303];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF41525;
	local[0]= fqv[304];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[100],w);
	goto IF41526;
IF41525:
	local[0]= fqv[305];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF41526:
	local[0]= fqv[306];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[307],module,F34398,fqv[308]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[309],module,F34277,fqv[310]);
	local[0]= fqv[11];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41553;
	local[0]= fqv[11];
	local[1]= fqv[36];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[11];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41576;
	local[0]= fqv[11];
	local[1]= fqv[311];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41577;
IF41576:
	local[0]= NIL;
IF41577:
	local[0]= fqv[11];
	goto IF41554;
IF41553:
	local[0]= NIL;
IF41554:
	ctx->vsp=local+0;
	compfun(ctx,fqv[140],module,F34280,fqv[312]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[313],module,F34282,fqv[314]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[315],module,F34284,fqv[316]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[317],module,F34287,fqv[318]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[319],module,F34289,fqv[320]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[321],module,F34292,fqv[322]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[323],module,F34295,fqv[324]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[325],module,F34297,fqv[326]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[327],module,F34299,fqv[328]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[329],module,F36128,fqv[330]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[331],module,F34302,fqv[332]);
	local[0]= fqv[96];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41618;
	local[0]= fqv[96];
	local[1]= fqv[36];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41641;
	local[0]= fqv[96];
	local[1]= fqv[311];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41642;
IF41641:
	local[0]= NIL;
IF41642:
	local[0]= fqv[96];
	goto IF41619;
IF41618:
	local[0]= NIL;
IF41619:
	ctx->vsp=local+0;
	compfun(ctx,fqv[333],module,F34305,fqv[334]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F34307,fqv[335]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[336],module,F36968,fqv[337]);
	local[0]= fqv[135];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41667;
	local[0]= fqv[135];
	local[1]= fqv[36];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41690;
	local[0]= fqv[135];
	local[1]= fqv[311];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41691;
IF41690:
	local[0]= NIL;
IF41691:
	local[0]= fqv[135];
	goto IF41668;
IF41667:
	local[0]= NIL;
IF41668:
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F34311,fqv[338]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[142],module,F34313,fqv[339]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[340],module,F37204,fqv[341]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[342],module,F37338,fqv[343]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F34318,fqv[344]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[156],module,F37932,fqv[345]);
	local[0]= fqv[195];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41722;
	local[0]= fqv[195];
	local[1]= fqv[36];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[195];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41745;
	local[0]= fqv[195];
	local[1]= fqv[311];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41746;
IF41745:
	local[0]= NIL;
IF41746:
	local[0]= fqv[195];
	goto IF41723;
IF41722:
	local[0]= NIL;
IF41723:
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F34320,fqv[346]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[347],module,F38169,fqv[348]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[349],module,F38707,fqv[350]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[351],module,F34321,fqv[352]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[353],module,F34322,fqv[354]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[355],module,F34323,fqv[356]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[357],module,F34324,fqv[358]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[359],module,F34325,fqv[360]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[361],module,F34326,fqv[362]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[363],module,F34327,fqv[364]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[365],module,F34328,fqv[366]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[367],module,F39842,fqv[368]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[369],module,F34329,fqv[370]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[371],module,F34330,fqv[372]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[373],module,F34331,fqv[374]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M40219,fqv[375],fqv[376],fqv[377]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[378],module,F34332,fqv[379]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[380],module,F34333,fqv[381]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[382],module,F34334,fqv[383]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[384],module,F34335,fqv[385]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[386],module,F34336,fqv[387]);
	local[0]= fqv[299];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41807;
	local[0]= fqv[299];
	local[1]= fqv[36];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[299];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41830;
	local[0]= fqv[299];
	local[1]= fqv[311];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41831;
IF41830:
	local[0]= NIL;
IF41831:
	local[0]= fqv[299];
	goto IF41808;
IF41807:
	local[0]= NIL;
IF41808:
	ctx->vsp=local+0;
	compfun(ctx,fqv[281],module,F34337,fqv[388]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[278],module,F34338,fqv[389]);
	local[0]= fqv[286];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41854;
	local[0]= fqv[286];
	local[1]= fqv[36];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[286];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41877;
	local[0]= fqv[286];
	local[1]= fqv[311];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41878;
IF41877:
	local[0]= NIL;
IF41878:
	local[0]= fqv[286];
	goto IF41855;
IF41854:
	local[0]= NIL;
IF41855:
	ctx->vsp=local+0;
	compfun(ctx,fqv[302],module,F34339,fqv[390]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[391],module,F34340,fqv[392]);
	local[0]= fqv[393];
	local[1]= fqv[394];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[395]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<34; i++) ftab[i]=fcallx;
}
