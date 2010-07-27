/* eusforeign.c :  entry=eusforeign */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "eusforeign.h"
#pragma init (register_eusforeign)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___eusforeign();
extern pointer build_quote_vector();
static register_eusforeign()
  { add_module_initializer("___eusforeign", ___eusforeign);}

static pointer F61920();
static pointer F61921();
static pointer F61922();
static pointer F61923();
static pointer F61924();
static pointer F61960();

/*:find*/
static pointer M62002(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[0]); /*system::find-entry*/
	local[0]= w;
BLK62003:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M62039(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT62044;}
	local[0]= NIL;
ENT62044:
	if (n>=5) { local[1]=(argv[4]); goto ENT62043;}
	local[1]= fqv[1];
ENT62043:
ENT62042:
	if (n>5) maerror();
	argv[0]->c.obj.iv[0] = makeint(0);
	argv[0]->c.obj.iv[1] = NIL;
	argv[0]->c.obj.iv[3] = argv[2];
	argv[0]->c.obj.iv[4] = local[0];
	argv[0]->c.obj.iv[5] = local[1];
	argv[0]->c.obj.iv[2] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK62040:
	ctx->vsp=local; return(local[0]);}

/*make-foreign-code*/
static pointer F61920(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT62096;}
	local[0]= NIL;
ENT62096:
	if (n>=3) { local[1]=(argv[2]); goto ENT62095;}
	local[1]= fqv[1];
ENT62095:
	if (n>=4) { local[2]=(argv[3]); goto ENT62094;}
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,0,local+2,&ftab[1],fqv[2]); /*system::sysmod*/
	local[2]= w;
ENT62094:
ENT62093:
	if (n>4) maerror();
	w = argv[0];
	local[3]= (isnum(w)?T:NIL);
	if (local[3]!=NIL) goto CON62123;
CON62125:
	local[3]= argv[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[0]); /*system::find-entry*/
	if (w==NIL) goto CON62132;
	local[3]= argv[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[0]); /*system::find-entry*/
	argv[0] = w;
	local[3]= argv[0];
	goto CON62123;
CON62132:
	local[3]= fqv[3];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto CON62123;
CON62149:
	local[3]= NIL;
CON62123:
	local[3]= loadglobal(fqv[4]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[5];
	local[6]= argv[0];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK62091:
	ctx->vsp=local; return(local[0]);}

/*load-foreign*/
static pointer F61921(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	local[2]= fqv[7];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,3,local+0,&ftab[2],fqv[8]); /*load*/
	local[0]= w;
BLK62186:
	ctx->vsp=local; return(local[0]);}

/*defforeign*/
static pointer F62203(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= fqv[9];
	local[1]= fqv[10];
	local[2]= fqv[11];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[12];
	local[3]= argv[2];
	local[4]= fqv[11];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[11];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[1];
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
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK62204:
	ctx->vsp=local; return(local[0]);}

/*defvoidforeigns*/
static pointer F62277(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST62280:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[13];
	local[2]= fqv[14];
	local[3]= fqv[11];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[9];
	local[4]= fqv[10];
	local[5]= fqv[15];
	local[6]= fqv[16];
	local[7]= fqv[14];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[12];
	local[6]= fqv[14];
	local[7]= fqv[17];
	local[8]= fqv[1];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
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
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK62278:
	ctx->vsp=local; return(local[0]);}

/*byte-string*/
static pointer F61922(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST62368:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= fqv[18];
	local[3]= fqv[19];
	local[4]= fqv[20];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,5,local+1,&ftab[3],fqv[21]); /*make-array*/
	local[0]= w;
BLK62366:
	ctx->vsp=local; return(local[0]);}

/*:pod-address*/
static pointer M62412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(8);
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)ADDRESS(ctx,1,local+1); /*system:address*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK62413:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M62433(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ADDRESS(ctx,1,local+0); /*system:address*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= makeint(141);
	local[3]= makeint(84);
	local[4]= makeint(36);
	local[5]= makeint(4);
	local[6]= makeint(82);
	local[7]= makeint(104);
	local[8]= local[0];
	local[9]= makeint(0);
	local[10]= makeint(8);
	ctx->vsp=local+11;
	w=(pointer)LDB(ctx,3,local+8); /*ldb*/
	local[8]= w;
	local[9]= local[0];
	local[10]= makeint(8);
	local[11]= makeint(8);
	ctx->vsp=local+12;
	w=(pointer)LDB(ctx,3,local+9); /*ldb*/
	local[9]= w;
	local[10]= local[0];
	local[11]= makeint(16);
	local[12]= makeint(8);
	ctx->vsp=local+13;
	w=(pointer)LDB(ctx,3,local+10); /*ldb*/
	local[10]= w;
	local[11]= local[0];
	local[12]= makeint(24);
	local[13]= makeint(8);
	ctx->vsp=local+14;
	w=(pointer)LDB(ctx,3,local+11); /*ldb*/
	local[11]= w;
	local[12]= makeint(232);
	local[13]= makeint(0);
	local[14]= makeint(0);
	local[15]= makeint(0);
	local[16]= makeint(0);
	local[17]= makeint(90);
	local[18]= makeint(90);
	local[19]= makeint(195);
	ctx->vsp=local+20;
	w=(pointer)F61922(ctx,18,local+2); /*byte-string*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= loadglobal(fqv[22]);
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	local[4]= makeint(8);
	local[5]= makeint(15);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,3,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[1] = w;
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)LDB(ctx,3,local+3); /*ldb*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(8);
	local[6]= makeint(8);
	ctx->vsp=local+7;
	w=(pointer)LDB(ctx,3,local+4); /*ldb*/
	local[4]= w;
	local[5]= local[1];
	local[6]= makeint(16);
	local[7]= makeint(8);
	ctx->vsp=local+8;
	w=(pointer)LDB(ctx,3,local+5); /*ldb*/
	local[5]= w;
	local[6]= local[1];
	local[7]= makeint(24);
	local[8]= makeint(8);
	ctx->vsp=local+9;
	w=(pointer)LDB(ctx,3,local+6); /*ldb*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,4,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[23];
	local[5]= makeint(11);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,4,local+2,&ftab[4],fqv[24]); /*replace*/
	w = argv[0]->c.obj.iv[6];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON62541;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[25]!=local[1]) goto IF62549;
	local[1]= fqv[26];
	local[2]= makeint(4);
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)NTHCDR(ctx,2,local+2); /*nthcdr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	argv[4] = w;
	local[1]= argv[4];
	goto IF62550;
IF62549:
	local[1]= NIL;
IF62550:
	goto CON62539;
CON62541:
	local[1]= argv[4];
	local[2]= loadglobal(fqv[27]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON62572;
	argv[4] = *(ovafptr(argv[4],fqv[28]));
	local[1]= argv[4];
	goto CON62539;
CON62572:
	local[1]= NIL;
CON62539:
	argv[0]->c.obj.iv[3] = argv[4];
	argv[0]->c.obj.iv[7] = argv[2];
	argv[0]->c.obj.iv[8] = argv[3];
	w = argv[0];
	local[0]= w;
BLK62434:
	ctx->vsp=local; return(local[0]);}

/*defun-c-callable*/
static pointer F62612(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST62615:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO62636,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO62645,env,argv,local);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[29]); /*keywordp*/
	if (w==NIL) goto IF62653;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF62654;
IF62653:
	local[3]= fqv[1];
IF62654:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,1,local+4,&ftab[5],fqv[29]); /*keywordp*/
	if (w==NIL) goto IF62676;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	goto IF62677;
IF62676:
	local[4]= local[0];
IF62677:
	local[5]= fqv[30];
	local[6]= fqv[31];
	local[7]= fqv[11];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[32];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[33];
	local[8]= fqv[34];
	local[9]= fqv[35];
	local[10]= fqv[36];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[15];
	local[11]= fqv[11];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,1,local+12,&ftab[6],fqv[37]); /*string*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[32];
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
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[5];
	local[10]= fqv[11];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[11];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[38];
	local[13]= fqv[39];
	local[14]= local[2];
	w = local[4];
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
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
	w = cons(ctx,local[5],w);
	local[0]= w;
BLK62613:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO62636(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!!iscons(w)) goto IF62826;
	local[0]= fqv[1];
	goto IF62827;
IF62826:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF62827:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO62645(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!!iscons(w)) goto IF62851;
	local[0]= argv[0];
	goto IF62852;
IF62851:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF62852:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*pod-address*/
static pointer F61923(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK62864:
	ctx->vsp=local; return(local[0]);}

/*byte-size*/
static pointer F61924(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[41]);
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK62881:
	ctx->vsp=local; return(local[0]);}

/*:slotlist*/
static pointer M62948(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT62952;}
	local[0]= NIL;
ENT62952:
ENT62951:
	if (n>3) maerror();
	if (local[0]!=NIL) goto IF62968;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK62949;
	goto IF62969;
IF62968:
	local[1]= NIL;
IF62969:
	argv[0]->c.obj.iv[10] = NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(1);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= local[0];
WHL63032:
	if (local[10]==NIL) goto WHX63033;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w = local[3];
	if (!issymbol(w)) goto CON63096;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,1,local+11,&ftab[5],fqv[29]); /*keywordp*/
	if (w!=NIL) goto CON63096;
	local[11]= NIL;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)SYMVALUE(ctx,1,local+12); /*symbol-value*/
	local[12]= w;
	local[13]= fqv[42];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
WHL63137:
	if (local[12]==NIL) goto WHX63138;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= loadglobal(fqv[37]);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(*ftab[6])(ctx,1,local+14,&ftab[6],fqv[37]); /*string*/
	local[14]= w;
	local[15]= fqv[43];
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	ctx->vsp=local+17;
	w=(*ftab[6])(ctx,1,local+16,&ftab[6],fqv[37]); /*string*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)CONCATENATE(ctx,4,local+13); /*concatenate*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)INTERN(ctx,1,local+13); /*intern*/
	local[13]= w;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	w = local[8];
	ctx->vsp=local+14;
	local[8] = cons(ctx,local[13],w);
	goto WHL63137;
WHX63138:
	local[13]= NIL;
BLK63139:
	w = NIL;
	local[11]= w;
	goto CON63094;
CON63096:
	local[11]= local[9];
	w = local[8];
	ctx->vsp=local+12;
	local[8] = cons(ctx,local[11],w);
	local[11]= local[8];
	goto CON63094;
CON63226:
	local[11]= NIL;
CON63094:
	goto WHL63032;
WHX63033:
	local[11]= NIL;
BLK63034:
	w = NIL;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	local[8] = w;
	local[9]= NIL;
	local[10]= local[8];
WHL63271:
	if (local[10]==NIL) goto WHX63272;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)F61924(ctx,1,local+11); /*byte-size*/
	local[4] = w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,1,local+11,&ftab[5],fqv[29]); /*keywordp*/
	if (w!=NIL) goto IF63355;
	local[11]= fqv[44];
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,1,local+11); /*error*/
	local[11]= w;
	goto IF63356;
IF63355:
	local[11]= NIL;
IF63356:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	if (fqv[45]!=local[11]) goto IF63370;
	local[3] = fqv[46];
	local[4] = makeint(4);
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	goto IF63371;
IF63370:
	local[11]= NIL;
IF63371:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF63433;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF63434;
IF63433:
	local[11]= makeint(1);
IF63434:
	local[5] = local[11];
	local[11]= local[4];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[2] = w;
	local[11]= local[1];
	local[12]= local[4];
	local[13]= makeint(-1);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,3,local+11); /*+*/
	local[11]= w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[1] = w;
	local[11]= local[7];
	local[12]= local[3];
	local[13]= local[5];
	local[14]= local[4];
	local[15]= local[1];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,6,local+11); /*list*/
	local[11]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+12;
	argv[0]->c.obj.iv[10] = cons(ctx,local[11],w);
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[1] = w;
	goto WHL63271;
WHX63272:
	local[11]= NIL;
BLK63273:
	w = NIL;
	local[9]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	argv[0]->c.obj.iv[10] = w;
	argv[0]->c.obj.iv[9] = local[1];
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK62949:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M63537(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK63538:
	ctx->vsp=local; return(local[0]);}

/*:slot*/
static pointer M63552(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto IF63567;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	goto IF63568;
IF63567:
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF63568:
	w = local[0];
	local[0]= w;
BLK63553:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M63582(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT63586;}
	local[0]= NIL;
ENT63586:
ENT63585:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	if (local[1]!=NIL) goto IF63621;
	local[2]= fqv[48];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	local[2]= w;
	goto IF63622;
IF63621:
	local[2]= NIL;
IF63622:
	if (local[0]==NIL) goto CON63636;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF63642;
	local[2]= fqv[49];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF63643;
IF63642:
	local[2]= NIL;
IF63643:
	local[2]= local[1];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	goto CON63634;
CON63636:
	local[2]= local[1];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	goto CON63634;
CON63668:
	local[2]= NIL;
CON63634:
	w = local[2];
	local[0]= w;
BLK63583:
	ctx->vsp=local; return(local[0]);}

/*:access*/
static pointer M63676(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT63680;}
	local[0]= NIL;
ENT63680:
ENT63679:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	if (local[1]!=NIL) goto IF63718;
	local[3]= fqv[50];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF63719;
IF63718:
	local[3]= NIL;
IF63719:
	if (local[0]==NIL) goto CON63732;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF63738;
	local[3]= fqv[51];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF63739;
IF63738:
	local[3]= NIL;
IF63739:
	local[3]= local[1];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= makeint(3);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[2] = w;
	local[3]= local[2];
	goto CON63730;
CON63732:
	local[3]= local[1];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[2] = w;
	local[3]= local[2];
	goto CON63730;
CON63769:
	local[3]= NIL;
CON63730:
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK63677:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M63804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT63808;}
	local[0]= NIL;
ENT63808:
ENT63807:
	if (n>4) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= fqv[52];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)PEEK(ctx,3,local+2); /*system:peek*/
	local[0]= w;
BLK63805:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M63861(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT63865;}
	local[0]= NIL;
ENT63865:
ENT63864:
	if (n>5) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= fqv[52];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)POKE(ctx,4,local+2); /*system:poke*/
	local[0]= w;
BLK63862:
	ctx->vsp=local; return(local[0]);}

/*defcstruct*/
static pointer F63923(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST63926:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= makeint(0);
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(*ftab[6])(ctx,1,local+17,&ftab[6],fqv[37]); /*string*/
	local[17]= w;
	local[18]= fqv[53];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	if (fqv[54]!=local[19]) goto IF63989;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[19]= local[0];
	goto IF63990;
IF63989:
	local[19]= NIL;
IF63990:
	local[19]= NIL;
	local[20]= local[0];
WHL64047:
	if (local[20]==NIL) goto WHX64048;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	w = local[6];
	if (!issymbol(w)) goto IF64109;
	local[21]= local[6];
	ctx->vsp=local+22;
	w=(*ftab[5])(ctx,1,local+21,&ftab[5],fqv[29]); /*keywordp*/
	if (w!=NIL) goto IF64109;
	local[21]= NIL;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	ctx->vsp=local+23;
	w=(pointer)SYMVALUE(ctx,1,local+22); /*symbol-value*/
	local[22]= w;
	local[23]= fqv[42];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
WHL64150:
	if (local[22]==NIL) goto WHX64151;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= loadglobal(fqv[37]);
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(*ftab[6])(ctx,1,local+24,&ftab[6],fqv[37]); /*string*/
	local[24]= w;
	local[25]= fqv[55];
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(*ftab[6])(ctx,1,local+26,&ftab[6],fqv[37]); /*string*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)CONCATENATE(ctx,4,local+23); /*concatenate*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)INTERN(ctx,1,local+23); /*intern*/
	local[23]= w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,2,local+23); /*list*/
	local[23]= w;
	w = local[11];
	ctx->vsp=local+24;
	local[11] = cons(ctx,local[23],w);
	goto WHL64150;
WHX64151:
	local[23]= NIL;
BLK64152:
	w = NIL;
	local[21]= w;
	goto IF64110;
IF64109:
	local[21]= local[19];
	w = local[11];
	ctx->vsp=local+22;
	local[11] = cons(ctx,local[21],w);
	local[21]= local[11];
IF64110:
	goto WHL64047;
WHX64048:
	local[21]= NIL;
BLK64049:
	w = NIL;
	local[19]= NIL;
	local[20]= local[11];
	ctx->vsp=local+21;
	w=(pointer)NREVERSE(ctx,1,local+20); /*nreverse*/
	local[20]= w;
WHL64274:
	if (local[20]==NIL) goto WHX64275;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(*ftab[6])(ctx,1,local+21,&ftab[6],fqv[37]); /*string*/
	local[2] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	local[21]= loadglobal(fqv[37]);
	local[22]= local[17];
	local[23]= fqv[56];
	local[24]= local[2];
	ctx->vsp=local+25;
	w=(pointer)CONCATENATE(ctx,4,local+21); /*concatenate*/
	local[16] = w;
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[14] = w;
	local[21]= loadglobal(fqv[37]);
	local[22]= fqv[57];
	local[23]= local[16];
	ctx->vsp=local+24;
	w=(pointer)CONCATENATE(ctx,3,local+21); /*concatenate*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[15] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	if (local[19]!=NIL) goto CON64376;
	local[21]= local[6];
	ctx->vsp=local+22;
	w=(pointer)F61924(ctx,1,local+21); /*byte-size*/
	local[9] = w;
	local[21]= local[7];
	local[22]= local[9];
	local[23]= makeint(-1);
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,3,local+21); /*+*/
	local[21]= w;
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[7] = w;
	local[21]= fqv[58];
	local[22]= local[14];
	local[23]= fqv[59];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	local[24]= fqv[60];
	local[25]= fqv[59];
	local[26]= local[7];
	local[27]= local[6];
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[3] = cons(ctx,local[21],w);
	local[21]= fqv[61];
	local[22]= local[14];
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[4] = cons(ctx,local[21],w);
	local[21]= fqv[58];
	local[22]= local[15];
	local[23]= fqv[59];
	local[24]= fqv[62];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[63];
	local[25]= fqv[62];
	local[26]= fqv[59];
	local[27]= local[7];
	local[28]= local[6];
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[5] = cons(ctx,local[21],w);
	local[21]= local[5];
	goto CON64374;
CON64376:
	local[12] = local[6];
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	if (fqv[45]!=local[21]) goto IF64509;
	local[12] = fqv[64];
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	w = local[21];
	local[21]= w;
	goto IF64510;
IF64509:
	local[21]= NIL;
IF64510:
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)F61924(ctx,1,local+21); /*byte-size*/
	local[13] = w;
	local[21]= local[13];
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF64577;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	goto IF64578;
IF64577:
	local[22]= makeint(1);
IF64578:
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[9] = w;
	local[21]= local[7];
	local[22]= local[13];
	local[23]= makeint(-1);
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,3,local+21); /*+*/
	local[21]= w;
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[7] = w;
	local[21]= local[12];
	w = fqv[65];
	if (memq(local[21],w)==NIL) goto CON64617;
	local[21]= fqv[58];
	local[22]= local[14];
	local[23]= fqv[59];
	local[24]= fqv[66];
	local[25]= fqv[67];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[68];
	local[25]= fqv[67];
	local[26]= fqv[60];
	local[27]= fqv[59];
	local[28]= fqv[69];
	local[29]= local[7];
	local[30]= fqv[67];
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	local[28]= cons(ctx,local[28],w);
	local[29]= fqv[70];
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	local[27]= fqv[71];
	local[28]= fqv[59];
	local[29]= local[7];
	local[30]= fqv[69];
	local[31]= local[7];
	local[32]= local[9];
	ctx->vsp=local+33;
	w=(pointer)LIST(ctx,1,local+32); /*list*/
	ctx->vsp=local+32;
	w = cons(ctx,local[31],w);
	ctx->vsp=local+31;
	local[30]= cons(ctx,local[30],w);
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[3] = cons(ctx,local[21],w);
	local[21]= fqv[61];
	local[22]= local[14];
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[4] = cons(ctx,local[21],w);
	local[21]= fqv[58];
	local[22]= local[15];
	local[23]= fqv[59];
	local[24]= fqv[67];
	local[25]= fqv[72];
	local[26]= fqv[62];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[68];
	local[25]= fqv[62];
	local[26]= fqv[63];
	local[27]= fqv[73];
	local[28]= fqv[62];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= fqv[69];
	local[29]= local[7];
	local[30]= fqv[67];
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	local[28]= cons(ctx,local[28],w);
	local[29]= fqv[70];
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	local[27]= fqv[24];
	local[28]= fqv[59];
	local[29]= fqv[67];
	local[30]= fqv[23];
	local[31]= local[7];
	local[32]= fqv[74];
	local[33]= fqv[75];
	local[34]= fqv[67];
	ctx->vsp=local+35;
	w=(pointer)LIST(ctx,1,local+34); /*list*/
	ctx->vsp=local+34;
	local[33]= cons(ctx,local[33],w);
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	ctx->vsp=local+33;
	w = cons(ctx,local[32],w);
	ctx->vsp=local+32;
	w = cons(ctx,local[31],w);
	ctx->vsp=local+31;
	w = cons(ctx,local[30],w);
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[5] = cons(ctx,local[21],w);
	local[21]= local[5];
	goto CON64615;
CON64617:
	local[21]= fqv[58];
	local[22]= local[14];
	local[23]= fqv[59];
	local[24]= fqv[67];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[76];
	local[25]= fqv[77];
	local[26]= fqv[67];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	local[25]= fqv[60];
	local[26]= fqv[59];
	local[27]= fqv[69];
	local[28]= local[7];
	local[29]= fqv[45];
	local[30]= fqv[67];
	local[31]= local[13];
	ctx->vsp=local+32;
	w=(pointer)LIST(ctx,1,local+31); /*list*/
	ctx->vsp=local+31;
	w = cons(ctx,local[30],w);
	ctx->vsp=local+30;
	local[29]= cons(ctx,local[29],w);
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= local[12];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[3] = cons(ctx,local[21],w);
	local[21]= fqv[61];
	local[22]= local[14];
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[4] = cons(ctx,local[21],w);
	local[21]= fqv[58];
	local[22]= local[15];
	local[23]= fqv[59];
	local[24]= fqv[67];
	local[25]= fqv[62];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[76];
	local[25]= fqv[77];
	local[26]= fqv[67];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	local[25]= fqv[63];
	local[26]= fqv[62];
	local[27]= fqv[59];
	local[28]= fqv[69];
	local[29]= local[7];
	local[30]= fqv[45];
	local[31]= fqv[67];
	local[32]= local[13];
	ctx->vsp=local+33;
	w=(pointer)LIST(ctx,1,local+32); /*list*/
	ctx->vsp=local+32;
	w = cons(ctx,local[31],w);
	ctx->vsp=local+31;
	local[30]= cons(ctx,local[30],w);
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	local[28]= cons(ctx,local[28],w);
	local[29]= local[12];
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[5] = cons(ctx,local[21],w);
	local[21]= local[5];
	goto CON64615;
CON64862:
	local[21]= NIL;
CON64615:
	goto CON64374;
CON64497:
	local[21]= fqv[78];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto CON64374;
CON65049:
	local[21]= NIL;
CON64374:
	local[21]= local[3];
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[4];
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[5];
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[7];
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(pointer)PLUS(ctx,2,local+21); /*+*/
	local[7] = w;
	goto WHL64274;
WHX64275:
	local[21]= NIL;
BLK64276:
	w = NIL;
	local[19]= fqv[30];
	local[20]= fqv[79];
	local[21]= argv[0];
	local[22]= fqv[54];
	local[23]= local[18];
	local[24]= fqv[18];
	local[25]= fqv[70];
	local[26]= fqv[80];
	local[27]= fqv[81];
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	local[20]= cons(ctx,local[20],w);
	local[21]= fqv[33];
	local[22]= argv[0];
	local[23]= fqv[42];
	local[24]= fqv[11];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)NREVERSE(ctx,1,local+22); /*nreverse*/
	local[22]= w;
	local[23]= fqv[11];
	local[24]= argv[0];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)APPEND(ctx,2,local+22); /*append*/
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	local[0]= w;
BLK63924:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M65206(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT65210;}
	local[0]= makeint(0);
ENT65210:
ENT65209:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[82]));
	local[3]= fqv[83];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK65207:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M65235(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT65239;}
	local[0]= makeint(0);
ENT65239:
ENT65238:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[82]));
	local[3]= fqv[84];
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK65236:
	ctx->vsp=local; return(local[0]);}

/*defcarray*/
static pointer F65269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT65273;}
	local[0]= makeint(1);
ENT65273:
ENT65272:
	if (n>3) maerror();
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[85]); /*symbol-name*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[85]); /*symbol-name*/
	local[2]= w;
	local[3]= loadglobal(fqv[37]);
	local[4]= local[2];
	local[5]= fqv[86];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[85]); /*symbol-name*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,4,local+3); /*concatenate*/
	local[3]= w;
	local[4]= loadglobal(fqv[37]);
	local[5]= fqv[87];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,3,local+4); /*concatenate*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,1,local+4); /*intern*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)INTERN(ctx,1,local+5); /*intern*/
	local[5]= w;
	local[6]= loadglobal(fqv[37]);
	local[7]= fqv[88];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)CONCATENATE(ctx,3,local+6); /*concatenate*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)INTERN(ctx,1,local+6); /*intern*/
	local[6]= w;
	local[7]= fqv[30];
	local[8]= fqv[89];
	local[9]= argv[0];
	local[10]= fqv[54];
	local[11]= fqv[90];
	local[12]= local[1];
	local[13]= argv[1];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
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
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[58];
	local[10]= argv[0];
	local[11]= fqv[59];
	local[12]= fqv[66];
	local[13]= fqv[67];
	local[14]= fqv[91];
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
	local[12]= local[5];
	local[13]= fqv[59];
	local[14]= fqv[67];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
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
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[58];
	local[11]= local[4];
	local[12]= fqv[59];
	local[13]= fqv[67];
	local[14]= fqv[66];
	local[15]= fqv[62];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[68];
	local[14]= fqv[62];
	local[15]= local[6];
	local[16]= fqv[59];
	local[17]= fqv[67];
	local[18]= fqv[62];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	local[16]= local[6];
	local[17]= fqv[59];
	local[18]= fqv[92];
	local[19]= fqv[67];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
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
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[61];
	local[12]= argv[0];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[11];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
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
	local[0]= w;
BLK65270:
	ctx->vsp=local; return(local[0]);}

/*make-foreign-string*/
static pointer F61960(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[93]);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(2);
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,3,local+1); /*system:poke*/
	w = local[0];
	local[0]= w;
BLK65538:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___eusforeign(ctx,n,argv,env)
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
	local[0]= fqv[94];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF65591;
	local[0]= fqv[95];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[32],w);
	goto IF65592;
IF65591:
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF65592:
	local[0]= fqv[97];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62002,fqv[98],fqv[99],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62039,fqv[5],fqv[4],fqv[101]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[12],module,F61920,fqv[102]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F61921,fqv[104]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[105],module,F62203,fqv[106]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[107],module,F62277,fqv[108]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[109],module,F61922,fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62412,fqv[40],fqv[36],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62433,fqv[5],fqv[36],fqv[112]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[113],module,F62612,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F61923,fqv[116]);
	local[0]= fqv[41];
	local[1]= fqv[117];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF65637;
	local[0]= fqv[41];
	local[1]= fqv[117];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF65660;
	local[0]= fqv[41];
	local[1]= fqv[118];
	local[2]= fqv[46];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[64];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[119];
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[1];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[120];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[19];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[121];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[122];
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[123];
	local[11]= makeint(8);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[124];
	local[12]= fqv[125];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[70];
	local[13]= fqv[126];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
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
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF65661;
IF65660:
	local[0]= NIL;
IF65661:
	local[0]= fqv[41];
	goto IF65638;
IF65637:
	local[0]= NIL;
IF65638:
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F61924,fqv[128]);
	local[0]= fqv[81];
	local[1]= fqv[118];
	local[2]= fqv[81];
	local[3]= fqv[54];
	local[4]= loadglobal(fqv[129]);
	local[5]= fqv[130];
	local[6]= fqv[131];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[18];
	local[10]= NIL;
	local[11]= fqv[132];
	local[12]= makeint(-1);
	local[13]= fqv[133];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[134]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62948,fqv[42],fqv[81],fqv[135]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63537,fqv[132],fqv[81],fqv[136]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63552,fqv[47],fqv[81],fqv[137]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63582,fqv[138],fqv[81],fqv[139]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63676,fqv[52],fqv[81],fqv[140]);
	local[0]= fqv[53];
	local[1]= fqv[118];
	local[2]= fqv[53];
	local[3]= fqv[54];
	local[4]= loadglobal(fqv[37]);
	local[5]= fqv[130];
	local[6]= fqv[17];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[18];
	local[10]= fqv[70];
	local[11]= fqv[132];
	local[12]= makeint(-1);
	local[13]= fqv[133];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[134]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63804,fqv[83],fqv[53],fqv[141]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63861,fqv[84],fqv[53],fqv[142]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[89],module,F63923,fqv[143]);
	local[0]= fqv[90];
	local[1]= fqv[118];
	local[2]= fqv[90];
	local[3]= fqv[54];
	local[4]= loadglobal(fqv[53]);
	local[5]= fqv[130];
	local[6]= fqv[17];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[18];
	local[10]= NIL;
	local[11]= fqv[132];
	local[12]= makeint(-1);
	local[13]= fqv[133];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[134]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M65206,fqv[83],fqv[90],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M65235,fqv[84],fqv[90],fqv[145]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[146],module,F65269,fqv[147]);
	local[0]= fqv[93];
	local[1]= fqv[118];
	local[2]= fqv[93];
	local[3]= fqv[54];
	local[4]= loadglobal(fqv[148]);
	local[5]= fqv[130];
	local[6]= fqv[17];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[18];
	local[10]= fqv[149];
	local[11]= fqv[132];
	local[12]= makeint(-1);
	local[13]= fqv[133];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[134]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[150],module,F61960,fqv[151]);
	local[0]= fqv[152];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[154]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
