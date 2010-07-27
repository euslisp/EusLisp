/* time.c :  entry=time */
/* compiled by EusLisp 8.26 for Linux  created on 2003年 12月 29日 月曜日 09:13:31 JST */
#include "eus.h"
#include "time.h"
#pragma init (register_time)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___time();
extern pointer build_quote_vector();
static register_time()
  { add_module_initializer("___time", ___time);}

static pointer F793();
static pointer F794();
static pointer F795();
static pointer F796();
static pointer F797();
static pointer F798();
static pointer F799();
static pointer F800();
static pointer F801();
static pointer F802();
static pointer F803();

/*year-day*/
static pointer F793(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT806;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
	local[1]= makeint(5);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
ENT806:
ENT805:
	if (n>3) maerror();
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[0]);
	local[3]= makeint(1);
	local[4]= local[0];
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF807;
	local[4]= makeint(29);
	goto IF808;
IF807:
	local[4]= makeint(28);
IF808:
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
WHL809:
	local[2]= argv[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto WHX810;
	argv[0] = (pointer)((integer_t)(argv[0])-4);
	local[2]= local[1];
	local[3]= loadglobal(fqv[0]);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[1] = w;
	goto WHL809;
WHX810:
	local[2]= NIL;
BLK811:
	local[2]= local[1];
	local[3]= (pointer)((integer_t)(argv[1])-4);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[0]= w;
BLK804:
	ctx->vsp=local; return(local[0]);}

/*leap-year-p*/
static pointer F794(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
	if (w==NIL) goto AND814;
	local[0]= argv[0];
	local[1]= makeint(100);
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*/=*/
	local[0]= w;
AND814:
	if (local[0]!=NIL) goto OR813;
	local[0]= argv[0];
	local[1]= makeint(400);
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
OR813:
	w = local[0];
	local[0]= w;
BLK812:
	ctx->vsp=local; return(local[0]);}

/*secs-since-1970*/
static pointer F795(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[2], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY816;
	local[0] = NIL;
KEY816:
	if (n & (1<<1)) goto KEY817;
	local[1] = NIL;
KEY817:
	if (n & (1<<2)) goto KEY818;
	local[2] = NIL;
KEY818:
	if (n & (1<<3)) goto KEY819;
	local[3] = makeint(0);
KEY819:
	if (n & (1<<4)) goto KEY820;
	local[4] = makeint(0);
KEY820:
	if (n & (1<<5)) goto KEY821;
	local[5] = makeint(0);
KEY821:
	local[6]= local[0];
	local[7]= makeint(1900);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF822;
	local[6]= local[0];
	local[7]= makeint(1900);
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[0] = w;
	local[6]= local[0];
	goto IF823;
IF822:
	local[6]= NIL;
IF823:
	local[6]= NIL;
	local[7]= NIL;
	local[8]= makeint(0);
	local[9]= local[0];
	local[10]= makeint(70);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[6] = w;
	local[9]= local[6];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[7] = w;
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F793(ctx,2,local+9); /*year-day*/
	local[8] = w;
	local[9]= local[5];
	local[10]= makeint(60);
	local[11]= local[4];
	local[12]= makeint(60);
	local[13]= local[3];
	local[14]= makeint(24);
	local[15]= local[6];
	local[16]= makeint(365);
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= local[7];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)PLUS(ctx,3,local+15); /*+*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[0]= w;
BLK815:
	ctx->vsp=local; return(local[0]);}

/*month-index*/
static pointer F796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto CON826;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto CON825;
CON826:
	w = argv[0];
	if (!isstring(w)) goto CON827;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[3]);
	local[2]= fqv[5];
	local[3]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,4,local+0,&ftab[1],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto CON825;
CON827:
	w = argv[0];
	if (!isint(w)) goto CON828;
	local[0]= (pointer)((integer_t)(argv[0])-4);
	goto CON825;
CON828:
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON825;
CON829:
	local[0]= NIL;
CON825:
	w = local[0];
	local[0]= w;
BLK824:
	ctx->vsp=local; return(local[0]);}

/*weekday-index*/
static pointer F797(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto CON832;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto CON831;
CON832:
	w = argv[0];
	if (!isstring(w)) goto CON833;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[8]);
	local[2]= fqv[5];
	local[3]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,4,local+0,&ftab[1],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto CON831;
CON833:
	w = argv[0];
	if (!isint(w)) goto CON834;
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w!=NIL) goto OR837;
	local[0]= argv[0];
	local[1]= makeint(11);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w!=NIL) goto OR837;
	goto IF835;
OR837:
	local[0]= fqv[9];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF836;
IF835:
	local[0]= argv[0];
IF836:
	goto CON831;
CON834:
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON831;
CON838:
	local[0]= NIL;
CON831:
	w = local[0];
	local[0]= w;
BLK830:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M839(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[11];
	local[2]= fqv[12];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK840:
	ctx->vsp=local; return(local[0]);}

/*:make*/
static pointer M841(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[13], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY843;
	local[0] = makeint(0);
KEY843:
	if (n & (1<<1)) goto KEY844;
	local[1] = makeint(0);
KEY844:
	if (n & (1<<2)) goto KEY845;
	local[2] = makeint(0);
KEY845:
	if (n & (1<<3)) goto KEY846;
	local[3] = makeint(0);
KEY846:
	if (n & (1<<4)) goto KEY847;
	local[4] = makeint(0);
KEY847:
	if (n & (1<<5)) goto KEY848;
	local[5] = makeint(0);
KEY848:
	if (n & (1<<6)) goto KEY849;
	local[6] = makeint(0);
KEY849:
	argv[0]->c.obj.iv[3] = local[6];
	local[7]= local[5];
	local[8]= makeint(60);
	local[9]= local[4];
	local[10]= makeint(60);
	local[11]= local[3];
	local[12]= makeint(24);
	local[13]= local[2];
	local[14]= makeint(30);
	local[15]= local[1];
	local[16]= makeint(12);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	argv[0]->c.obj.iv[1] = w;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= makeint(60);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	argv[0]->c.obj.iv[6] = w;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= argv[0]->c.obj.iv[6];
	{ integer_t i,j;
		j=intval(makeint(60)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(60);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	argv[0]->c.obj.iv[5] = w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= argv[0]->c.obj.iv[5];
	{ integer_t i,j;
		j=intval(makeint(60)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	w = local[8];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	argv[0]->c.obj.iv[6] = (pointer)((integer_t)local[7] - (integer_t)w);
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= makeint(60);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	argv[0]->c.obj.iv[4] = w;
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= makeint(60);
	ctx->vsp=local+9;
	w=(pointer)MOD(ctx,2,local+7); /*mod*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0];
	local[0]= w;
BLK842:
	ctx->vsp=local; return(local[0]);}

/*:string*/
static pointer M850(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[14]);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[15]); /*minusp*/
	if (w==NIL) goto IF852;
	local[1]= fqv[16];
	goto IF853;
IF852:
	local[1]= NIL;
IF853:
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[17]); /*zerop*/
	if (w==NIL) goto IF854;
	local[2]= fqv[18];
	goto IF855;
IF854:
	local[2]= NIL;
	local[3]= fqv[19];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
IF855:
	local[3]= NIL;
	local[4]= fqv[20];
	local[5]= makeint(abs(intval(argv[0]->c.obj.iv[5])));
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[21]); /*digits-string*/
	local[5]= w;
	local[6]= makeint(abs(intval(argv[0]->c.obj.iv[6])));
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[21]); /*digits-string*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[21]); /*digits-string*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,5,local+3); /*format*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,1,local+4,&ftab[3],fqv[17]); /*zerop*/
	if (w==NIL) goto IF856;
	local[4]= fqv[22];
	goto IF857;
IF856:
	local[4]= NIL;
	local[5]= fqv[23];
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= makeint(1000);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
IF857:
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,5,local+0); /*concatenate*/
	local[0]= w;
BLK851:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M858(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST860:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[24]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[25]));
	local[4]= fqv[26];
	local[5]= argv[2];
	local[6]= argv[0];
	local[7]= fqv[27];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[0]= w;
BLK859:
	ctx->vsp=local; return(local[0]);}

/*:micro*/
static pointer M861(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK862:
	ctx->vsp=local; return(local[0]);}

/*:total-seconds*/
static pointer M863(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK864:
	ctx->vsp=local; return(local[0]);}

/*:seconds*/
static pointer M865(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK866:
	ctx->vsp=local; return(local[0]);}

/*:total-minutes*/
static pointer M867(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeflt(6.00000000e+01);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK868:
	ctx->vsp=local; return(local[0]);}

/*:minutes*/
static pointer M869(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK870:
	ctx->vsp=local; return(local[0]);}

/*:total-hours*/
static pointer M871(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeflt(3.60000000e+03);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK872:
	ctx->vsp=local; return(local[0]);}

/*:hours*/
static pointer M873(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK874:
	ctx->vsp=local; return(local[0]);}

/*:days*/
static pointer M875(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK876:
	ctx->vsp=local; return(local[0]);}

/*:total-days*/
static pointer M877(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeflt(6.00000000e+01);
	local[2]= makeflt(6.00000000e+01);
	local[3]= makeflt(2.40000000e+01);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,4,local+0); /*/*/
	local[0]= w;
BLK878:
	ctx->vsp=local; return(local[0]);}

/*:add*/
static pointer M879(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[28];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK880:
	ctx->vsp=local; return(local[0]);}

/*:subtract*/
static pointer M882(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[28];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK883:
	ctx->vsp=local; return(local[0]);}

/*:iso-time-string*/
static pointer M885(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[30];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[21]); /*digits-string*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[21]); /*digits-string*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[21]); /*digits-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK886:
	ctx->vsp=local; return(local[0]);}

/*:iso-string*/
static pointer M887(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK888:
	ctx->vsp=local; return(local[0]);}

/*parse-time-string*/
static pointer F798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[32]); /*make-string-input-stream*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= loadglobal(fqv[33]);
	w = local[10];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[34],w);
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)F797(ctx,1,local+14); /*weekday-index*/
	local[4] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[3] = w;
	w = local[3];
	if (!isint(w)) goto CON891;
	local[5] = local[3];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)F796(ctx,1,local+14); /*month-index*/
	local[3] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[2] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[6] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[7] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[8] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[9] = w;
	local[14]= local[9];
	goto CON890;
CON891:
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)F796(ctx,1,local+14); /*month-index*/
	local[3] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[5] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[6] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[7] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[8] = w;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[9] = w;
	w = local[9];
	if (!isnum(w)) goto IF893;
	local[2] = local[9];
	local[9] = fqv[35];
	local[14]= local[9];
	goto IF894;
IF893:
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,1,local+14); /*read*/
	local[2] = w;
	local[14]= local[2];
IF894:
	goto CON890;
CON892:
	local[14]= NIL;
CON890:
	local[14]= local[8];
	local[15]= local[7];
	local[16]= local[6];
	local[17]= local[5];
	local[18]= local[3];
	local[19]= local[2];
	local[20]= local[4];
	local[21]= local[9];
	ctx->vsp=local+22;
	w=(pointer)MKVECTOR(ctx,8,local+14); /*vector*/
	local[0] = w;
	local[14]= local[0];
	ctx->vsp=local+15;
	unbindx(ctx,1);
	w = local[14];
	local[0]= w;
BLK889:
	ctx->vsp=local; return(local[0]);}

/*read-iso-date*/
static pointer F799(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[33]);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = local[0];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[34],w);
	w = argv[0];
	if (!isstring(w)) goto IF896;
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[32]); /*make-string-input-stream*/
	argv[0] = w;
	local[7]= argv[0];
	goto IF897;
IF896:
	local[7]= NIL;
IF897:
	local[7]= argv[0];
	local[8]= NIL;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[1] = w;
	local[7]= argv[0];
	local[8]= NIL;
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[2] = w;
	local[7]= argv[0];
	local[8]= NIL;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[3] = w;
	local[7]= loadglobal(fqv[36]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[11];
	local[10]= fqv[37];
	local[11]= local[1];
	local[12]= fqv[38];
	local[13]= local[2];
	local[14]= fqv[39];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,8,local+8); /*send*/
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	unbindx(ctx,1);
	w = local[7];
	local[0]= w;
BLK895:
	ctx->vsp=local; return(local[0]);}

/*read-iso-time*/
static pointer F800(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[33]);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = local[0];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[34],w);
	w = argv[0];
	if (!isstring(w)) goto IF900;
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[32]); /*make-string-input-stream*/
	argv[0] = w;
	local[7]= argv[0];
	goto IF901;
IF900:
	local[7]= NIL;
IF901:
	local[7]= argv[0];
	local[8]= NIL;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[1] = w;
	local[7]= argv[0];
	local[8]= NIL;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[2] = w;
	local[7]= argv[0];
	local[8]= NIL;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[3] = w;
	local[7]= loadglobal(fqv[40]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[11];
	local[10]= fqv[41];
	local[11]= local[1];
	local[12]= fqv[42];
	local[13]= local[2];
	local[14]= fqv[12];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,8,local+8); /*send*/
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	unbindx(ctx,1);
	w = local[7];
	local[0]= w;
BLK899:
	ctx->vsp=local; return(local[0]);}

/*read-iso-datetime*/
static pointer F801(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto IF904;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[32]); /*make-string-input-stream*/
	argv[0] = w;
	local[0]= argv[0];
	goto IF905;
IF904:
	local[0]= NIL;
IF905:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F799(ctx,1,local+0); /*read-iso-date*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F800(ctx,1,local+1); /*read-iso-time*/
	local[1]= w;
	if (local[0]==NIL) goto IF906;
	if (local[1]==NIL) goto IF906;
	local[2]= local[0];
	local[3]= fqv[43];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF907;
IF906:
	local[2]= local[0];
	if (local[2]!=NIL) goto OR908;
	local[2]= local[1];
OR908:
IF907:
	w = local[2];
	local[0]= w;
BLK903:
	ctx->vsp=local; return(local[0]);}

/*parse-iso-time-string*/
static pointer F802(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto IF910;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[32]); /*make-string-input-stream*/
	argv[0] = w;
	local[0]= argv[0];
	goto IF911;
IF910:
	local[0]= NIL;
IF911:
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[33]);
	w = local[9];
	ctx->vsp=local+10;
	bindspecial(ctx,fqv[34],w);
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[1] = w;
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)F796(ctx,1,local+13); /*month-index*/
	local[2] = w;
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[4] = w;
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[5] = w;
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[6] = w;
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[7] = w;
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[8] = w;
	local[13]= local[7];
	local[14]= local[6];
	local[15]= local[5];
	local[16]= local[4];
	local[17]= local[2];
	local[18]= local[1];
	local[19]= local[3];
	local[20]= local[8];
	ctx->vsp=local+21;
	w=(pointer)MKVECTOR(ctx,8,local+13); /*vector*/
	local[0] = w;
	local[13]= local[0];
	ctx->vsp=local+14;
	unbindx(ctx,1);
	w = local[13];
	local[0]= w;
BLK909:
	ctx->vsp=local; return(local[0]);}

/*now*/
static pointer F803(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[36]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK912:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M914(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT920;}
	local[0]= makeint(0);
ENT920:
	if (n>=4) { local[1]=(argv[3]); goto ENT919;}
	local[1]= makeint(0);
ENT919:
	if (n>=5) { local[2]=(argv[4]); goto ENT918;}
	local[2]= makeint(0);
ENT918:
	if (n>=6) { local[3]=(argv[5]); goto ENT917;}
	local[3]= makeint(0);
ENT917:
ENT916:
	if (n>6) maerror();
	argv[0]->c.obj.iv[10] = local[2];
	argv[0]->c.obj.iv[11] = local[3];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[0] = w;
	local[4]= makeint(0);
	argv[0]->c.obj.iv[3] = local[1];
	argv[0]->c.obj.iv[1] = local[0];
	argv[0]->c.obj.iv[2] = local[0];
	local[5]= local[0];
	local[6]= makeint(86400);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	argv[0]->c.obj.iv[4] = w;
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[4];
	local[7]= makeint(86400);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= makeint(3600);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	argv[0]->c.obj.iv[5] = w;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= makeint(7);
	ctx->vsp=local+7;
	w=(pointer)MOD(ctx,2,local+5); /*mod*/
	argv[0]->c.obj.iv[7] = w;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(365);
	local[7]= makeint(365);
	local[8]= makeint(365);
	w = makeint(366);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[8] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[7] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[6]= (pointer)((integer_t)local[6] + (integer_t)w);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[4] = w;
	local[5]= makeint(4);
	{ integer_t i,j;
		j=intval(local[4]); i=intval(local[5]);
		local[5]=(makeint(i * j));}
	argv[0]->c.obj.iv[9] = local[5];
	argv[0]->c.obj.iv[8] = makeint(0);
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= local[4];
	local[7]= makeint(365);
	local[8]= makeint(365);
	local[9]= makeint(365);
	w = makeint(366);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[9] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[8] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ integer_t i,j;
		j=intval((pointer)((integer_t)local[7] + (integer_t)w)); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[4] = w;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(365);
	ctx->vsp=local+7;
	w=(pointer)GREQP(ctx,2,local+5); /*>=*/
	if (w==NIL) goto IF921;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(365);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[4] = w;
	argv[0]->c.obj.iv[9] = (pointer)((integer_t)(argv[0]->c.obj.iv[9])+4);
	local[5]= argv[0]->c.obj.iv[9];
	goto IF922;
IF921:
	local[5]= NIL;
IF922:
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(365);
	ctx->vsp=local+7;
	w=(pointer)GREQP(ctx,2,local+5); /*>=*/
	if (w==NIL) goto IF923;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(365);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[4] = w;
	argv[0]->c.obj.iv[9] = (pointer)((integer_t)(argv[0]->c.obj.iv[9])+4);
	local[5]= argv[0]->c.obj.iv[9];
	goto IF924;
IF923:
	local[5]= NIL;
IF924:
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(366);
	ctx->vsp=local+7;
	w=(pointer)GREQP(ctx,2,local+5); /*>=*/
	if (w==NIL) goto IF925;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(366);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[4] = w;
	argv[0]->c.obj.iv[9] = (pointer)((integer_t)(argv[0]->c.obj.iv[9])+4);
	local[5]= argv[0]->c.obj.iv[9];
	goto IF926;
IF925:
	local[5]= NIL;
IF926:
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[5];
	{ integer_t i,j;
		j=intval(makeint(3600)); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= makeint(60);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	argv[0]->c.obj.iv[6] = w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[6];
	{ integer_t i,j;
		j=intval(makeint(60)); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0]->c.obj.iv[9];
	local[6]= makeint(1970);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	argv[0]->c.obj.iv[9] = w;
	local[5]= loadglobal(fqv[0]);
	local[6]= makeint(1);
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)F794(ctx,1,local+7); /*leap-year-p*/
	if (w==NIL) goto IF927;
	local[7]= makeint(29);
	goto IF928;
IF927:
	local[7]= makeint(28);
IF928:
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	argv[0]->c.obj.iv[4] = (pointer)((integer_t)(argv[0]->c.obj.iv[4])+4);
WHL929:
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= loadglobal(fqv[0]);
	local[7]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto WHX930;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= loadglobal(fqv[0]);
	local[7]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	argv[0]->c.obj.iv[4] = w;
	argv[0]->c.obj.iv[8] = (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	goto WHL929;
WHX930:
	local[5]= NIL;
BLK931:
	w = local[5];
	w = argv[0];
	local[0]= w;
BLK915:
	ctx->vsp=local; return(local[0]);}

/*:make*/
static pointer M932(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[45], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY934;
	local[0] = makeint(0);
KEY934:
	if (n & (1<<1)) goto KEY935;
	local[1] = makeint(0);
KEY935:
	if (n & (1<<2)) goto KEY936;
	local[2] = makeint(0);
KEY936:
	if (n & (1<<3)) goto KEY937;
	local[3] = makeint(0);
KEY937:
	if (n & (1<<4)) goto KEY938;
	local[4] = makeint(0);
KEY938:
	if (n & (1<<5)) goto KEY939;
	local[5] = makeint(0);
KEY939:
	if (n & (1<<6)) goto KEY940;
	local[6] = makeint(0);
KEY940:
	argv[0]->c.obj.iv[9] = local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F796(ctx,1,local+7); /*month-index*/
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[4] = local[2];
	argv[0]->c.obj.iv[5] = local[3];
	argv[0]->c.obj.iv[6] = local[4];
	argv[0]->c.obj.iv[2] = local[5];
	argv[0]->c.obj.iv[3] = local[6];
	local[7]= argv[0];
	local[8]= fqv[46];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	argv[0]->c.obj.iv[1] = w;
	if (argv[0]->c.obj.iv[7]==NIL) goto IF941;
	local[7]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+8;
	w=(pointer)F797(ctx,1,local+7); /*weekday-index*/
	local[7]= w;
	local[8]= w;
	w = argv[0];
	w->c.obj.iv[7] = local[8];
	goto IF942;
IF941:
	local[7]= fqv[37];
	local[8]= local[0];
	local[9]= fqv[38];
	local[10]= local[1];
	local[11]= fqv[39];
	local[12]= local[2];
	local[13]= fqv[41];
	local[14]= local[3];
	local[15]= fqv[42];
	local[16]= local[4];
	local[17]= fqv[12];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(pointer)F795(ctx,12,local+7); /*secs-since-1970*/
	local[7]= w;
	local[8]= makeint(4);
	local[9]= local[7];
	local[10]= makeint(86400);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeint(7);
	ctx->vsp=local+10;
	w=(pointer)MOD(ctx,2,local+8); /*mod*/
	local[8]= w;
	local[9]= local[8];
	local[10]= local[9];
	w = argv[0];
	w->c.obj.iv[7] = local[10];
	w = local[9];
	local[7]= w;
IF942:
	w = argv[0];
	local[0]= w;
BLK933:
	ctx->vsp=local; return(local[0]);}

/*:make-localtime*/
static pointer M943(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[11];
	local[2]= fqv[12];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= fqv[42];
	local[5]= argv[2];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= fqv[41];
	local[7]= argv[2];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= fqv[39];
	local[9]= argv[2];
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= fqv[38];
	local[11]= argv[2];
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= (pointer)((integer_t)(w)+4);
	local[12]= fqv[37];
	local[13]= makeint(1900);
	local[14]= argv[2];
	local[15]= makeint(5);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,14,local+0); /*send*/
	local[0]= w;
BLK944:
	ctx->vsp=local; return(local[0]);}

/*:now*/
static pointer M945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT948;}
	ctx->vsp=local+0;
	w=(pointer)GETTIMEOFDAY(ctx,0,local+0); /*unix:gettimeofday*/
	local[0]= w;
ENT948:
ENT947:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[28];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,1,local+6,&ftab[6],fqv[47]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK946:
	ctx->vsp=local; return(local[0]);}

/*:noon*/
static pointer M949(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[36]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[11];
	local[3]= fqv[37];
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= fqv[38];
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	local[7]= fqv[39];
	local[8]= argv[0]->c.obj.iv[4];
	local[9]= fqv[41];
	local[10]= makeint(12);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,10,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK950:
	ctx->vsp=local; return(local[0]);}

/*:midnight*/
static pointer M952(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[36]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[11];
	local[3]= fqv[37];
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= fqv[38];
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	local[7]= fqv[39];
	local[8]= argv[0]->c.obj.iv[4];
	local[9]= fqv[41];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,10,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK953:
	ctx->vsp=local; return(local[0]);}

/*:today*/
static pointer M955(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK956:
	ctx->vsp=local; return(local[0]);}

/*:offset-day*/
static pointer M957(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[49];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[43];
	local[2]= loadglobal(fqv[40]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[11];
	local[5]= fqv[39];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK958:
	ctx->vsp=local; return(local[0]);}

/*:offset-hour*/
static pointer M960(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[49];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[43];
	local[2]= loadglobal(fqv[40]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[11];
	local[5]= fqv[41];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK961:
	ctx->vsp=local; return(local[0]);}

/*:year-day*/
static pointer M963(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)F793(ctx,2,local+0); /*year-day*/
	local[0]= w;
BLK964:
	ctx->vsp=local; return(local[0]);}

/*:compute-seconds*/
static pointer M965(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= makeint(1970);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[50];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(60);
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= makeint(60);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(24);
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= makeint(1970);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= makeint(365);
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= local[0];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,3,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[0]= w;
BLK966:
	ctx->vsp=local; return(local[0]);}

/*:asctime*/
static pointer M967(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= makeint(1900);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF969;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= argv[0]->c.obj.iv[9];
	local[6]= makeint(1900);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+7;
	w=(pointer)MKVECTOR(ctx,7,local+0); /*vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ASCTIME(ctx,1,local+0); /*unix:asctime*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= (pointer)((integer_t)(w)-4);
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
	goto IF970;
IF969:
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[25]));
	local[2]= fqv[27];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
IF970:
	w = local[0];
	local[0]= w;
BLK968:
	ctx->vsp=local; return(local[0]);}

/*:string*/
static pointer M971(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST973:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto CON975;
	local[1]= argv[0];
	local[2]= fqv[51];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON974;
CON975:
	local[1]= fqv[52];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,2,local+1,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto CON976;
	local[1]= NIL;
	local[2]= fqv[54];
	local[3]= argv[0];
	local[4]= fqv[55];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[51];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	goto CON974;
CON976:
	if (local[0]==NIL) goto CON977;
	local[1]= NIL;
	local[2]= fqv[56];
	local[3]= fqv[37];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto IF978;
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[21]); /*digits-string*/
	local[3]= w;
	goto IF979;
IF978:
	local[3]= fqv[57];
IF979:
	local[4]= fqv[38];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,2,local+4,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto IF980;
	local[4]= (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[21]); /*digits-string*/
	local[4]= w;
	goto IF981;
IF980:
	local[4]= fqv[58];
IF981:
	local[5]= fqv[39];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,2,local+5,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto IF982;
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[21]); /*digits-string*/
	local[5]= w;
	goto IF983;
IF982:
	local[5]= fqv[59];
IF983:
	local[6]= fqv[41];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto IF984;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[21]); /*digits-string*/
	local[6]= w;
	goto IF985;
IF984:
	local[6]= fqv[60];
IF985:
	local[7]= fqv[42];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(*ftab[7])(ctx,2,local+7,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto IF986;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[21]); /*digits-string*/
	local[7]= w;
	goto IF987;
IF986:
	local[7]= fqv[61];
IF987:
	local[8]= fqv[12];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[53]); /*member*/
	if (w==NIL) goto IF988;
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,2,local+8,&ftab[4],fqv[21]); /*digits-string*/
	local[8]= w;
	goto IF989;
IF988:
	local[8]= fqv[62];
IF989:
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,8,local+1); /*format*/
	local[1]= w;
	goto CON974;
CON977:
	local[1]= NIL;
CON974:
	w = local[1];
	local[0]= w;
BLK972:
	ctx->vsp=local; return(local[0]);}

/*:parse-string*/
static pointer M990(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F798(ctx,1,local+0); /*parse-time-string*/
	local[0]= w;
	argv[0]->c.obj.iv[3] = makeint(0);
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= local[0];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= local[0];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= local[0];
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[8] = w;
	local[1]= local[0];
	local[2]= makeint(5);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[9] = w;
	local[1]= local[0];
	local[2]= makeint(6);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[7] = w;
	w = argv[0]->c.obj.iv[7];
	local[0]= argv[0];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK991:
	ctx->vsp=local; return(local[0]);}

/*:iso-string*/
static pointer M992(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[63];
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[21]); /*digits-string*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[4];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[21]); /*digits-string*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[21]); /*digits-string*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[21]); /*digits-string*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[21]); /*digits-string*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,8,local+0); /*format*/
	local[0]= w;
BLK993:
	ctx->vsp=local; return(local[0]);}

/*:iso-date-string*/
static pointer M994(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[64];
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[21]); /*digits-string*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[4];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[21]); /*digits-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK995:
	ctx->vsp=local; return(local[0]);}

/*:iso-time-string*/
static pointer M996(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[65];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[21]); /*digits-string*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[21]); /*digits-string*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[21]); /*digits-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK997:
	ctx->vsp=local; return(local[0]);}

/*:weekday-string*/
static pointer M998(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1002;}
	local[0]= fqv[66];
ENT1002:
	if (n>=4) { local[1]=(argv[3]); goto ENT1001;}
	local[1]= NIL;
ENT1001:
ENT1000:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[67];
	ctx->vsp=local+5;
	w=(pointer)NTH(ctx,2,local+3); /*nth*/
	local[2] = w;
	local[3]= local[0];
	local[4]= local[3];
	w = fqv[68];
	if (memq(local[4],w)==NIL) goto IF1004;
	if (local[1]==NIL) goto IF1006;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	goto IF1007;
IF1006:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[47]); /*fourth*/
	local[4]= w;
IF1007:
	goto IF1005;
IF1004:
	if (T==NIL) goto IF1008;
	if (local[1]==NIL) goto IF1010;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	goto IF1011;
IF1010:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
IF1011:
	goto IF1009;
IF1008:
	local[4]= NIL;
IF1009:
IF1005:
	w = local[4];
	local[0]= w;
BLK999:
	ctx->vsp=local; return(local[0]);}

/*:parse-iso-string*/
static pointer M1012(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F802(ctx,1,local+0); /*parse-iso-time-string*/
	local[0]= w;
	argv[0]->c.obj.iv[3] = makeint(0);
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= local[0];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= local[0];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= local[0];
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[8] = w;
	local[1]= local[0];
	local[2]= makeint(5);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	argv[0]->c.obj.iv[9] = w;
	local[1]= makeint(3600);
	local[2]= local[0];
	local[3]= makeint(7);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0]->c.obj.iv[10];
	local[0]= argv[0];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK1013:
	ctx->vsp=local; return(local[0]);}

/*:micro*/
static pointer M1014(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1015:
	ctx->vsp=local; return(local[0]);}

/*:second*/
static pointer M1016(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK1017:
	ctx->vsp=local; return(local[0]);}

/*:minute*/
static pointer M1018(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK1019:
	ctx->vsp=local; return(local[0]);}

/*:hour*/
static pointer M1020(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK1021:
	ctx->vsp=local; return(local[0]);}

/*:day*/
static pointer M1022(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK1023:
	ctx->vsp=local; return(local[0]);}

/*:weekday*/
static pointer M1024(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK1025:
	ctx->vsp=local; return(local[0]);}

/*:month*/
static pointer M1026(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = (pointer)((integer_t)(argv[0]->c.obj.iv[8])+4);
	local[0]= w;
BLK1027:
	ctx->vsp=local; return(local[0]);}

/*:year*/
static pointer M1028(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK1029:
	ctx->vsp=local; return(local[0]);}

/*:day-seconds*/
static pointer M1030(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(60);
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= makeint(60);
	{ integer_t i,j;
		j=intval(argv[0]->c.obj.iv[5]); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	w = local[3];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	{ integer_t i,j;
		j=intval((pointer)((integer_t)local[2] + (integer_t)w)); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK1031:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___time(ctx,n,argv,env)
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
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1032;
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[70],w);
	goto IF1033;
IF1032:
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1033:
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[73];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)LOCALTIME(ctx,0,local+2); /*unix:localtime*/
	local[2]= w;
	local[3]= makeint(9);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[75]); /*read-from-string*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[76];
	local[1]= fqv[77];
	local[2]= makeint(24);
	{ integer_t i,j;
		j=intval(makeint(3600)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[0];
	local[1]= fqv[74];
	local[2]= fqv[78];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[3];
	local[1]= fqv[74];
	local[2]= fqv[79];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[8];
	local[1]= fqv[74];
	local[2]= fqv[80];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F793,fqv[82]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F794,fqv[84]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[85],module,F795,fqv[86]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[87],module,F796,fqv[88]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F797,fqv[90]);
	local[0]= fqv[40];
	local[1]= fqv[74];
	local[2]= fqv[40];
	local[3]= fqv[91];
	local[4]= loadglobal(fqv[92]);
	local[5]= fqv[93];
	local[6]= fqv[94];
	local[7]= fqv[95];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[97];
	local[12]= makeint(-1);
	local[13]= fqv[98];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[9])(ctx,13,local+2,&ftab[9],fqv[99]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M839,fqv[28],fqv[40],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M841,fqv[11],fqv[40],fqv[101]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M850,fqv[27],fqv[40],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M858,fqv[26],fqv[40],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M861,fqv[104],fqv[40],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M863,fqv[29],fqv[40],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M865,fqv[107],fqv[40],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M867,fqv[109],fqv[40],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M869,fqv[111],fqv[40],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M871,fqv[113],fqv[40],fqv[114]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M873,fqv[115],fqv[40],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M875,fqv[117],fqv[40],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M877,fqv[119],fqv[40],fqv[120]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M879,fqv[43],fqv[40],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M882,fqv[122],fqv[40],fqv[123]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M885,fqv[31],fqv[40],fqv[124]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M887,fqv[51],fqv[40],fqv[125]);
	local[0]= fqv[33];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1034;
	local[0]= fqv[33];
	local[1]= fqv[126];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1036;
	local[0]= fqv[33];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,0,local+2,&ftab[10],fqv[127]); /*copy-readtable*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1037;
IF1036:
	local[0]= NIL;
IF1037:
	local[0]= fqv[33];
	goto IF1035;
IF1034:
	local[0]= NIL;
IF1035:
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	local[0]= makeint(58);
	local[1]= makeint(32);
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,3,local+0,&ftab[11],fqv[129]); /*set-syntax-from-char*/
	local[0]= makeint(44);
	local[1]= makeint(32);
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,3,local+0,&ftab[11],fqv[129]); /*set-syntax-from-char*/
	local[0]= makeint(45);
	local[1]= makeint(32);
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,3,local+0,&ftab[11],fqv[129]); /*set-syntax-from-char*/
	local[0]= makeint(43);
	local[1]= makeint(32);
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,3,local+0,&ftab[11],fqv[129]); /*set-syntax-from-char*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[130],module,F798,fqv[131]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F799,fqv[133]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F800,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[136],module,F801,fqv[137]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[138],module,F802,fqv[139]);
	local[0]= fqv[36];
	local[1]= fqv[74];
	local[2]= fqv[36];
	local[3]= fqv[91];
	local[4]= loadglobal(fqv[40]);
	local[5]= fqv[93];
	local[6]= fqv[140];
	local[7]= fqv[95];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[97];
	local[12]= makeint(-1);
	local[13]= fqv[98];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[9])(ctx,13,local+2,&ftab[9],fqv[99]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F803,fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M914,fqv[28],fqv[36],fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M932,fqv[11],fqv[36],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M943,fqv[145],fqv[36],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M945,fqv[44],fqv[36],fqv[147]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M949,fqv[148],fqv[36],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M952,fqv[48],fqv[36],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M955,fqv[49],fqv[36],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M957,fqv[152],fqv[36],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M960,fqv[154],fqv[36],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M963,fqv[50],fqv[36],fqv[156]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M965,fqv[46],fqv[36],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M967,fqv[158],fqv[36],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M971,fqv[27],fqv[36],fqv[160]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M990,fqv[161],fqv[36],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M992,fqv[51],fqv[36],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M994,fqv[164],fqv[36],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M996,fqv[31],fqv[36],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M998,fqv[55],fqv[36],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1012,fqv[168],fqv[36],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1014,fqv[104],fqv[36],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1016,fqv[12],fqv[36],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1018,fqv[42],fqv[36],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1020,fqv[41],fqv[36],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1022,fqv[39],fqv[36],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1024,fqv[175],fqv[36],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1026,fqv[38],fqv[36],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1028,fqv[37],fqv[36],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1030,fqv[179],fqv[36],fqv[180]);
	local[0]= fqv[181];
	local[1]= fqv[182];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[183]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<13; i++) ftab[i]=fcallx;
}
