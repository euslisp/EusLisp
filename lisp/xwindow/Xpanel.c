/* Xpanel.c :  entry=Xpanel */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xpanel.h"
#pragma init (register_Xpanel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xpanel();
extern pointer build_quote_vector();
static register_Xpanel()
  { add_module_initializer("___Xpanel", ___Xpanel);}


/*:create*/
static pointer M2032(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2034:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2035;
	local[1] = makeint(28);
KEY2035:
	if (n & (1<<1)) goto KEY2036;
	local[2] = makeint(50);
KEY2036:
	if (n & (1<<2)) goto KEY2037;
	local[3] = loadglobal(fqv[1]);
KEY2037:
	if (n & (1<<3)) goto KEY2038;
	local[4] = NIL;
KEY2038:
	if (n & (1<<4)) goto KEY2039;
	local[5] = NIL;
KEY2039:
	if (n & (1<<5)) goto KEY2040;
	local[6] = NIL;
KEY2040:
	if (local[4]!=NIL) goto IF2041;
	if (local[5]==NIL) goto IF2043;
	local[7]= argv[0];
	local[8]= fqv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	goto IF2044;
IF2043:
	local[7]= loadglobal(fqv[3]);
IF2044:
	local[4] = local[7];
	local[7]= local[4];
	goto IF2042;
IF2041:
	local[7]= NIL;
IF2042:
	local[7]= (pointer)get_sym_func(fqv[4]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[5]));
	local[10]= fqv[6];
	local[11]= fqv[7];
	local[12]= makeint(1);
	local[13]= fqv[2];
	local[14]= local[4];
	local[15]= fqv[8];
	local[16]= local[5];
	local[17]= fqv[9];
	local[18]= local[6];
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)APPLY(ctx,13,local+7); /*apply*/
	w = local[3];
	if (!isnum(w)) goto IF2045;
	local[7]= local[3];
	goto IF2046;
IF2045:
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,1,local+7,&ftab[0],fqv[10]); /*font-id*/
	local[7]= w;
IF2046:
	argv[0]->c.obj.iv[14] = local[7];
	local[7]= argv[0]->c.obj.iv[3];
	local[8]= fqv[11];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	argv[0]->c.obj.iv[19] = local[2];
	argv[0]->c.obj.iv[20] = local[1];
	local[7]= argv[0];
	local[8]= fqv[12];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	argv[0]->c.obj.iv[15] = w;
	local[7]= argv[0];
	local[8]= fqv[13];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	argv[0]->c.obj.iv[16] = w;
	argv[0]->c.obj.iv[13] = NIL;
	argv[0]->c.obj.iv[17] = makeint(0);
	argv[0]->c.obj.iv[18] = makeint(0);
	local[7]= argv[0]->c.obj.iv[4];
	local[8]= makeflt(1.39999962e+00);
	local[9]= argv[0];
	local[10]= fqv[14];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,3,local+7,&ftab[1],fqv[15]); /*get-lighter-pixel*/
	argv[0]->c.obj.iv[22] = w;
	local[7]= argv[0]->c.obj.iv[4];
	local[8]= makeflt(5.99999905e-01);
	local[9]= argv[0];
	local[10]= fqv[14];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,3,local+7,&ftab[1],fqv[15]); /*get-lighter-pixel*/
	argv[0]->c.obj.iv[21] = w;
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= argv[0]->c.obj.iv[6];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,5,local+7,&ftab[2],fqv[16]); /*make-topleft-edge-polygon*/
	argv[0]->c.obj.iv[23] = w;
	local[7]= argv[0];
	local[8]= fqv[17];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK2033:
	ctx->vsp=local; return(local[0]);}

/*:expose*/
static pointer M2047(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[18],w);
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2048:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2049(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK2050:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M2051(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[5]));
	local[2]= fqv[20];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,5,local+0,&ftab[2],fqv[16]); /*make-topleft-edge-polygon*/
	argv[0]->c.obj.iv[23] = w;
	w = argv[0];
	local[0]= w;
BLK2052:
	ctx->vsp=local; return(local[0]);}

/*:items*/
static pointer M2053(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK2054:
	ctx->vsp=local; return(local[0]);}

/*:locate-item*/
static pointer M2055(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2059;}
	local[0]= NIL;
ENT2059:
	if (n>=5) { local[1]=(argv[4]); goto ENT2058;}
	local[1]= NIL;
ENT2058:
ENT2057:
	if (n>5) maerror();
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[21];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[2];
	local[4]= argv[2];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF2060;
	argv[0]->c.obj.iv[17] = makeint(0);
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= (pointer)get_sym_func(fqv[22]);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO2062,env,argv,local);
	local[7]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,3,local+4); /*apply*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	argv[0]->c.obj.iv[18] = w;
	local[3]= argv[0]->c.obj.iv[18];
	goto IF2061;
IF2060:
	local[3]= NIL;
IF2061:
	if (local[0]!=NIL) goto IF2063;
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(5);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[0] = w;
	local[3]= local[0];
	goto IF2064;
IF2063:
	local[3]= NIL;
IF2064:
	if (local[1]!=NIL) goto IF2065;
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= makeint(5);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	local[3]= local[1];
	goto IF2066;
IF2065:
	local[3]= NIL;
IF2066:
	local[3]= argv[2];
	local[4]= fqv[23];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= argv[2];
	local[6]= fqv[13];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(5);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,2,local+4); /*max*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[0]->c.obj.iv[17] = w;
	local[3]= argv[2];
	local[4]= fqv[24];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(5);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	argv[0]->c.obj.iv[18] = w;
	local[3]= argv[2];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[2];
	w = argv[0]->c.obj.iv[13];
	ctx->vsp=local+4;
	argv[0]->c.obj.iv[13] = cons(ctx,local[3],w);
	w = argv[2];
	local[0]= w;
BLK2056:
	ctx->vsp=local; return(local[0]);}

/*:create-item*/
static pointer M2067(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
RST2069:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-6);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[26], &argv[6], n-6, local+1, 1);
	if (n & (1<<0)) goto KEY2070;
	local[1] = NIL;
KEY2070:
	if (n & (1<<1)) goto KEY2071;
	local[2] = NIL;
KEY2071:
	if (n & (1<<2)) goto KEY2072;
	local[3] = argv[0]->c.obj.iv[14];
KEY2072:
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= (pointer)get_sym_func(fqv[28]);
	local[8]= local[6];
	local[9]= fqv[6];
	local[10]= argv[3];
	local[11]= argv[4];
	local[12]= argv[5];
	local[13]= fqv[11];
	local[14]= local[3];
	local[15]= fqv[8];
	local[16]= argv[0];
	local[17]= fqv[25];
	local[18]= NIL;
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)APPLY(ctx,13,local+7); /*apply*/
	w = local[6];
	local[6]= w;
	local[7]= local[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[0]= w;
BLK2068:
	ctx->vsp=local; return(local[0]);}

/*:create-menubar*/
static pointer M2074(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2076:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[29], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2077;
	local[1] = makeint(0);
KEY2077:
	if (n & (1<<1)) goto KEY2078;
	local[2] = makeint(0);
KEY2078:
	if (n & (1<<2)) goto KEY2079;
	local[3] = argv[0]->c.obj.iv[14];
KEY2079:
	local[4]= NIL;
	local[5]= loadglobal(fqv[30]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= (pointer)get_sym_func(fqv[28]);
	local[7]= local[5];
	local[8]= fqv[6];
	local[9]= fqv[11];
	local[10]= local[3];
	local[11]= fqv[8];
	local[12]= argv[0];
	local[13]= fqv[25];
	local[14]= NIL;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,10,local+6); /*apply*/
	w = local[5];
	local[4] = w;
	local[5]= local[4];
	local[6]= fqv[12];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	argv[0]->c.obj.iv[18] = w;
	local[5]= argv[0];
	local[6]= fqv[27];
	local[7]= local[4];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[0]= w;
BLK2075:
	ctx->vsp=local; return(local[0]);}

/*:active-menu*/
static pointer M2081(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[24]==NIL) goto IF2083;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[24];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w!=NIL) goto IF2083;
	local[0]= argv[0]->c.obj.iv[24];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2084;
IF2083:
	local[0]= NIL;
IF2084:
	argv[0]->c.obj.iv[24] = argv[2];
	local[0]= argv[0]->c.obj.iv[24];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2082:
	ctx->vsp=local; return(local[0]);}

/*:delete-items*/
static pointer M2085(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[17] = makeint(0);
	argv[0]->c.obj.iv[18] = makeint(0);
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[34]); /*send-all*/
	argv[0]->c.obj.iv[13] = NIL;
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK2086:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2062(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:quit*/
static pointer M2087(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2089:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[35];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK2088:
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M2090(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2091:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2092(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2093:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2094(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2095:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2096(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2097:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2098(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[18],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2099:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2100(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2101:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2102(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2104:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[36], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2105;
	local[1] = loadglobal(fqv[1]);
KEY2105:
	if (n & (1<<1)) goto KEY2106;
	local[2] = NIL;
KEY2106:
	if (n & (1<<2)) goto KEY2107;
	local[3] = NIL;
KEY2107:
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= fqv[37];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[38]); /*textdots*/
	local[6] = w;
	if (local[2]!=NIL) goto IF2108;
	local[7]= makeint(60);
	goto IF2109;
IF2108:
	local[7]= local[2];
IF2109:
	local[4] = local[7];
	if (local[3]==NIL) goto IF2110;
	local[7]= local[3];
	goto IF2111;
IF2110:
	local[7]= local[6];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= local[6];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= makeint(6);
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,3,local+7); /*+*/
	local[7]= w;
IF2111:
	local[5] = local[7];
	local[7]= (pointer)get_sym_func(fqv[4]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[5]));
	local[10]= fqv[6];
	local[11]= fqv[13];
	local[12]= local[4];
	local[13]= fqv[12];
	local[14]= local[5];
	local[15]= fqv[7];
	local[16]= makeint(0);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,11,local+7); /*apply*/
	local[7]= argv[0];
	local[8]= fqv[39];
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= local[2];
	local[12]= local[3];
	local[13]= makeint(2);
	local[14]= argv[0]->c.obj.iv[22];
	local[15]= argv[0]->c.obj.iv[21];
	local[16]= argv[0]->c.obj.iv[4];
	local[17]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,11,local+7); /*send*/
	argv[0]->c.obj.iv[17] = makeint(3);
	argv[0]->c.obj.iv[18] = makeint(2);
	local[7]= argv[0];
	local[8]= fqv[17];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK2103:
	ctx->vsp=local; return(local[0]);}

/*:locate-item*/
static pointer M2112(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2116;}
	local[0]= NIL;
ENT2116:
	if (n>=5) { local[1]=(argv[4]); goto ENT2115;}
	local[1]= NIL;
ENT2115:
ENT2114:
	if (n>5) maerror();
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= local[2];
	local[4]= argv[2];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF2117;
	argv[0]->c.obj.iv[17] = makeint(3);
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[0]->c.obj.iv[18] = w;
	local[3]= argv[0]->c.obj.iv[18];
	goto IF2118;
IF2117:
	local[3]= NIL;
IF2118:
	local[3]= argv[2];
	local[4]= fqv[23];
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[2];
	local[4]= fqv[40];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[0]->c.obj.iv[17] = w;
	local[3]= argv[2];
	local[4]= fqv[24];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	argv[0]->c.obj.iv[18] = w;
	local[3]= argv[2];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[2];
	w = argv[0]->c.obj.iv[13];
	ctx->vsp=local+4;
	argv[0]->c.obj.iv[13] = cons(ctx,local[3],w);
	w = argv[2];
	local[0]= w;
BLK2113:
	ctx->vsp=local; return(local[0]);}

/*:popup-all-menus*/
static pointer M2119(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[34]); /*send-all*/
	local[0]= w;
BLK2120:
	ctx->vsp=local; return(local[0]);}

/*:unmap-all-menus*/
static pointer M2121(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[34]); /*send-all*/
	local[0]= w;
BLK2122:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xpanel(ctx,n,argv,env)
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
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2123;
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[43],w);
	goto IF2124;
IF2123:
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2124:
	local[0]= fqv[45];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[47]); /*require*/
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2032,fqv[6],fqv[49],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2047,fqv[51],fqv[49],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2049,fqv[19],fqv[49],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2051,fqv[20],fqv[49],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2053,fqv[55],fqv[49],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2055,fqv[27],fqv[49],fqv[57]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2067,fqv[58],fqv[49],fqv[59]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2074,fqv[60],fqv[49],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2081,fqv[62],fqv[49],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2085,fqv[64],fqv[49],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2087,fqv[66],fqv[49],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2090,fqv[68],fqv[49],fqv[69]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2092,fqv[70],fqv[49],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2094,fqv[72],fqv[49],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2096,fqv[74],fqv[49],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2098,fqv[76],fqv[49],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2100,fqv[78],fqv[49],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2102,fqv[6],fqv[30],fqv[80]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2112,fqv[27],fqv[30],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2119,fqv[82],fqv[30],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2121,fqv[84],fqv[30],fqv[85]);
	local[0]= fqv[86];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[88]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
