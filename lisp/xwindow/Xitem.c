/* Xitem.c :  entry=Xitem */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xitem.h"
#pragma init (register_Xitem)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xitem();
extern pointer build_quote_vector();
static register_Xitem()
  { add_module_initializer("___Xitem", ___Xitem);}

static pointer F2125();
static pointer F2126();
static pointer F2127();

/*clump*/
static pointer F2125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAX(ctx,2,local+0); /*max*/
	local[0]= w;
BLK2129:
	ctx->vsp=local; return(local[0]);}

/*replace-key-arg*/
static pointer F2126(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
WHL2131:
	if (argv[2]==NIL) goto WHX2132;
	local[1]= argv[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF2134;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[1]= argv[2];
	goto IF2135;
IF2134:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	local[1]= local[0];
IF2135:
	goto WHL2131;
WHX2132:
	local[1]= NIL;
BLK2133:
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST_STAR(ctx,3,local+1); /*list**/
	local[0]= w;
BLK2130:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2138(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2140:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2141;
	local[1] = makeint(100);
KEY2141:
	if (n & (1<<1)) goto KEY2142;
	local[2] = local[1];
KEY2142:
	if (n & (1<<2)) goto KEY2143;
	local[3] = local[2];
KEY2143:
	if (n & (1<<3)) goto KEY2144;
	local[4] = loadglobal(fqv[1]);
KEY2144:
	argv[0]->c.obj.iv[5] = local[2];
	argv[0]->c.obj.iv[6] = local[3];
	argv[0]->c.obj.iv[15] = local[4];
	argv[0]->c.obj.iv[16] = argv[2];
	argv[0]->c.obj.iv[14] = argv[4];
	if (argv[3]==NIL) goto IF2145;
	local[5]= argv[3];
	goto IF2146;
IF2145:
	local[5]= argv[0]->c.obj.iv[7];
IF2146:
	argv[0]->c.obj.iv[13] = local[5];
	local[5]= (pointer)get_sym_func(fqv[2]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[3]));
	local[8]= fqv[4];
	local[9]= fqv[5];
	local[10]= argv[2];
	local[11]= fqv[6];
	local[12]= local[2];
	local[13]= fqv[7];
	local[14]= local[3];
	local[15]= fqv[8];
	local[16]= local[4];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	local[5]= argv[0];
	local[6]= fqv[5];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK2139:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2147(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[10];
	local[2]= fqv[11];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[17];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2148:
	ctx->vsp=local; return(local[0]);}

/*:notify*/
static pointer M2149(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2151:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (argv[0]->c.obj.iv[13]==NIL) goto IF2152;
	if (argv[0]->c.obj.iv[14]==NIL) goto IF2152;
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF2154;
	local[1]= (pointer)get_sym_func(fqv[13]);
	local[2]= argv[0]->c.obj.iv[13];
	w=argv[0]->c.obj.iv[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,6,local+1); /*apply*/
	local[1]= w;
	goto IF2155;
IF2154:
	local[1]= (pointer)get_sym_func(fqv[13]);
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= argv[0]->c.obj.iv[14];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= w;
IF2155:
	goto IF2153;
IF2152:
	local[1]= NIL;
IF2153:
	w = local[1];
	local[0]= w;
BLK2150:
	ctx->vsp=local; return(local[0]);}

/*:keypress*/
static pointer M2156(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2157:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M2158(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2159:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2160(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2161:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2162(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2163:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2164(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2165:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2166(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2167:
	ctx->vsp=local; return(local[0]);}

/*make-topleft-edge-polygon*/
static pointer F2127(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= loadglobal(fqv[15]);
	local[1]= makeint(2);
	local[2]= makeint(2);
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	{ integer_t i,j;
		j=intval(local[2]); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[16];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= makeint(0);
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[4];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= argv[4];
	local[11]= argv[4];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,3,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= makeint(0);
	local[12]= argv[3];
	local[13]= argv[4];
	local[14]= argv[4];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	local[13]= argv[4];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	local[14]= argv[4];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,12,local+3); /*list*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK2168:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2169(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2171:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[18], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2172;
	local[1] = NIL;
KEY2172:
	if (n & (1<<1)) goto KEY2173;
	local[2] = NIL;
KEY2173:
	if (n & (1<<2)) goto KEY2174;
	local[3] = loadglobal(fqv[19]);
KEY2174:
	if (n & (1<<3)) goto KEY2175;
	local[4] = fqv[20];
KEY2175:
	if (n & (1<<4)) goto KEY2176;
	local[5] = loadglobal(fqv[21]);
KEY2176:
	if (n & (1<<5)) goto KEY2177;
	local[6] = loadglobal(fqv[22]);
KEY2177:
	if (n & (1<<6)) goto KEY2178;
	local[7] = makeint(0);
KEY2178:
	if (n & (1<<7)) goto KEY2179;
	local[11]= local[3];
	local[12]= loadglobal(fqv[23]);
	ctx->vsp=local+13;
	w=(pointer)DERIVEDP(ctx,2,local+11); /*derivedp*/
	if (w==NIL) goto IF2180;
	local[11]= fqv[24];
	goto IF2181;
IF2180:
	local[11]= fqv[25];
IF2181:
	local[8] = local[11];
KEY2179:
	if (n & (1<<8)) goto KEY2182;
	local[9] = NIL;
KEY2182:
	if (n & (1<<9)) goto KEY2183;
	local[10] = NIL;
KEY2183:
	local[11]= NIL;
	local[12]= NIL;
	local[13]= argv[2];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(*ftab[0])(ctx,2,local+13,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	if (local[1]==NIL) goto IF2184;
	local[13]= local[1];
	goto IF2185;
IF2184:
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= makeint(10);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
IF2185:
	local[11] = local[13];
	if (local[2]==NIL) goto IF2186;
	local[13]= local[2];
	goto IF2187;
IF2186:
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[17];
	local[15]= makeint(1);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	local[15]= makeint(6);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,3,local+13); /*+*/
	local[13]= w;
IF2187:
	local[12] = local[13];
	local[13]= (pointer)get_sym_func(fqv[2]);
	local[14]= argv[0];
	local[15]= *(ovafptr(argv[1],fqv[3]));
	local[16]= fqv[4];
	local[17]= argv[2];
	local[18]= argv[3];
	local[19]= argv[4];
	local[20]= fqv[6];
	local[21]= local[11];
	local[22]= fqv[7];
	local[23]= local[12];
	local[24]= fqv[26];
	local[25]= local[7];
	local[26]= fqv[27];
	local[27]= local[3];
	local[28]= fqv[28];
	local[29]= local[6];
	local[30]= fqv[29];
	local[31]= local[4];
	local[32]= local[0];
	ctx->vsp=local+33;
	w=(pointer)APPLY(ctx,20,local+13); /*apply*/
	local[13]= argv[0]->c.obj.iv[4];
	local[14]= makeflt(1.39999962e+00);
	local[15]= argv[0];
	local[16]= fqv[30];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,3,local+13,&ftab[1],fqv[31]); /*get-lighter-pixel*/
	argv[0]->c.obj.iv[23] = w;
	local[13]= argv[0]->c.obj.iv[4];
	local[14]= makeflt(5.99999905e-01);
	local[15]= argv[0];
	local[16]= fqv[30];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,3,local+13,&ftab[1],fqv[31]); /*get-lighter-pixel*/
	argv[0]->c.obj.iv[22] = w;
	local[13]= makeint(0);
	local[14]= makeint(0);
	local[15]= argv[0]->c.obj.iv[5];
	local[16]= argv[0]->c.obj.iv[6];
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)F2127(ctx,5,local+13); /*make-topleft-edge-polygon*/
	argv[0]->c.obj.iv[24] = w;
	argv[0]->c.obj.iv[21] = local[8];
	argv[0]->c.obj.iv[20] = local[9];
	local[13]= argv[0]->c.obj.iv[3];
	local[14]= fqv[8];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= argv[2];
	local[14]= local[13];
	w = argv[0];
	w->c.obj.iv[16] = local[14];
	local[13]= argv[0];
	local[14]= fqv[32];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[11]= local[10];
	local[12]= local[11];
	w = argv[0];
	w->c.obj.iv[19] = local[12];
	local[11]= argv[0]->c.obj.iv[3];
	local[12]= fqv[10];
	local[13]= fqv[11];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	w = argv[0];
	local[0]= w;
BLK2170:
	ctx->vsp=local; return(local[0]);}

/*:submenu*/
static pointer M2188(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2191;}
	local[0]= NIL;
ENT2191:
ENT2190:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF2192;
	argv[0]->c.obj.iv[19] = local[0];
	local[1]= argv[0]->c.obj.iv[19];
	goto IF2193;
IF2192:
	local[1]= NIL;
IF2193:
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK2189:
	ctx->vsp=local; return(local[0]);}

/*:active-color*/
static pointer M2194(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2197;}
	local[0]= NIL;
ENT2197:
ENT2196:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF2198;
	argv[0]->c.obj.iv[20] = local[0];
	local[1]= argv[0]->c.obj.iv[20];
	goto IF2199;
IF2198:
	local[1]= NIL;
IF2199:
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK2195:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M2200(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[3]));
	local[2]= fqv[33];
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
	w=(pointer)F2127(ctx,5,local+0); /*make-topleft-edge-polygon*/
	argv[0]->c.obj.iv[24] = w;
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2201:
	ctx->vsp=local; return(local[0]);}

/*:label*/
static pointer M2202(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2206;}
	local[0]= NIL;
ENT2206:
	if (n>=4) { local[1]=(argv[3]); goto ENT2205;}
	local[1]= makeint(10);
ENT2205:
ENT2204:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF2207;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,2,local+4,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(10);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,2,local+4); /*max*/
	local[2] = w;
	local[4]= argv[0]->c.obj.iv[17];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(6);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,3,local+4); /*+*/
	local[3] = w;
	argv[0]->c.obj.iv[16] = local[0];
	local[4]= argv[0];
	local[5]= fqv[33];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[2]= w;
	goto IF2208;
IF2207:
	local[2]= NIL;
IF2208:
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2203:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2209(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2215;}
	local[0]= fqv[25];
ENT2215:
	if (n>=4) { local[1]=(argv[3]); goto ENT2214;}
	local[1]= argv[0]->c.obj.iv[4];
ENT2214:
	if (n>=5) { local[2]=(argv[4]); goto ENT2213;}
	local[2]= makeint(2);
ENT2213:
	if (n>=6) { local[3]=(argv[5]); goto ENT2212;}
	local[3]= NIL;
ENT2212:
ENT2211:
	if (n>6) maerror();
	local[4]= argv[0];
	local[5]= fqv[34];
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= argv[0]->c.obj.iv[6];
	local[10]= local[2];
	local[11]= argv[0]->c.obj.iv[23];
	local[12]= argv[0]->c.obj.iv[22];
	local[13]= argv[0]->c.obj.iv[4];
	local[14]= argv[0]->c.obj.iv[24];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	if (local[3]!=NIL) goto IF2216;
	local[4]= local[0];
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[36]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[4]= local[3];
	goto IF2217;
IF2216:
	local[4]= NIL;
IF2217:
	if (local[3]!=NIL) goto IF2218;
	local[3] = makeint(0);
	local[4]= local[3];
	goto IF2219;
IF2218:
	local[4]= NIL;
IF2219:
	local[4]= argv[0];
	local[5]= fqv[37];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[17];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,3,local+6); /*+*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[17];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[17];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0]->c.obj.iv[17];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,4,local+7); /*+*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[38];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[0]= w;
BLK2210:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2220(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2221:
	ctx->vsp=local; return(local[0]);}

/*:keypress*/
static pointer M2222(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2223:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M2224(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2225:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2226(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	local[4]= fqv[32];
	local[5]= fqv[39];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[18] = T;
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2227:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2228(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[40]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[41]); /*event-y*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[32];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[0]->c.obj.iv[18]!=NIL) goto OR2232;
	local[5]= argv[0]->c.obj.iv[7];
	local[6]= loadglobal(fqv[23]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w!=NIL) goto OR2232;
	goto IF2230;
OR2232:
	local[5]= makeint(0);
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,3,local+5); /*<*/
	if (w==NIL) goto IF2230;
	local[5]= makeint(0);
	local[6]= local[4];
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,3,local+5); /*<*/
	if (w==NIL) goto IF2230;
	argv[0]->c.obj.iv[18] = NIL;
	if (argv[0]->c.obj.iv[19]==NIL) goto IF2233;
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= fqv[42];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[43]); /*event-x-root*/
	local[7]= w;
	local[8]= loadglobal(fqv[14]);
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,1,local+8,&ftab[6],fqv[44]); /*event-y-root*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF2234;
IF2233:
	local[5]= argv[0];
	local[6]= fqv[45];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
IF2234:
	goto IF2231;
IF2230:
	local[5]= NIL;
IF2231:
	w = local[5];
	if (argv[0]->c.obj.iv[7]==NIL) goto IF2235;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[46];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2236;
IF2235:
	local[3]= NIL;
IF2236:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2229:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2237(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[20]==NIL) goto IF2239;
	local[3]= argv[0];
	local[4]= fqv[32];
	local[5]= fqv[25];
	local[6]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2240;
IF2239:
	local[3]= NIL;
IF2240:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2238:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2241(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[20]==NIL) goto IF2243;
	local[3]= argv[0];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2244;
IF2243:
	local[3]= NIL;
IF2244:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2242:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2247:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[47], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2248;
	local[1] = NIL;
KEY2248:
	if (n & (1<<1)) goto KEY2249;
	local[2] = NIL;
KEY2249:
	if (n & (1<<2)) goto KEY2250;
	local[3] = fqv[24];
KEY2250:
	local[4]= (pointer)get_sym_func(fqv[2]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[3]));
	local[7]= fqv[4];
	local[8]= argv[2];
	local[9]= argv[3];
	local[10]= argv[4];
	local[11]= fqv[48];
	local[12]= local[3];
	local[13]= fqv[29];
	local[14]= fqv[49];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,12,local+4); /*apply*/
	argv[0]->c.obj.iv[30] = local[1];
	w = argv[0];
	local[0]= w;
BLK2246:
	ctx->vsp=local; return(local[0]);}

/*:label*/
static pointer M2251(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2254;}
	local[0]= NIL;
ENT2254:
ENT2253:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF2255;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[3]));
	local[4]= fqv[50];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,4,local+2); /*send-message*/
	local[2]= local[1];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,2,local+2,&ftab[7],fqv[51]); /*/=*/
	if (w==NIL) goto IF2257;
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= fqv[52];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF2258;
IF2257:
	local[2]= NIL;
IF2258:
	w = local[2];
	local[1]= w;
	goto IF2256;
IF2255:
	local[1]= NIL;
IF2256:
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2252:
	ctx->vsp=local; return(local[0]);}

/*:popup-menu*/
static pointer M2259(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= fqv[25];
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= fqv[42];
	local[3]= local[0];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[7];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[7];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2260:
	ctx->vsp=local; return(local[0]);}

/*:unmap-menu*/
static pointer M2261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[30];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2262:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2263(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	storeglobal(fqv[55],local[3]);
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[56];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[57];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2264:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2265(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[55]);
	if (argv[0]!=local[3]) goto IF2267;
	local[3]= NIL;
	storeglobal(fqv[55],local[3]);
	local[3]= argv[0];
	local[4]= fqv[58];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	goto IF2268;
IF2267:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[46];
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
IF2268:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2266:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[59]); /*event-pressed*/
	if (w==NIL) goto IF2271;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[56];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2272;
IF2271:
	local[3]= NIL;
IF2272:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2270:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2273(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2275:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[60], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2276;
	local[1] = loadglobal(fqv[1]);
KEY2276:
	if (n & (1<<1)) goto KEY2277;
	local[2] = makeint(20);
KEY2277:
	if (n & (1<<2)) goto KEY2278;
	local[3] = NIL;
KEY2278:
	if (n & (1<<3)) goto KEY2279;
	local[4] = makeint(0);
KEY2279:
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[5]= fqv[61];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[9]); /*textdots*/
	local[5]= w;
	local[6]= local[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[5];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= local[5];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= (pointer)get_sym_func(fqv[2]);
	local[10]= argv[0];
	local[11]= *(ovafptr(argv[1],fqv[3]));
	local[12]= fqv[4];
	local[13]= argv[2];
	local[14]= argv[3];
	local[15]= argv[4];
	local[16]= fqv[6];
	local[17]= argv[0]->c.obj.iv[17];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[17]= w;
	local[18]= makeint(8);
	local[19]= local[8];
	local[20]= makeint(4);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,4,local+17); /*+*/
	local[17]= w;
	local[18]= fqv[7];
	local[19]= local[6];
	local[20]= makeint(6);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= local[0];
	ctx->vsp=local+21;
	w=(pointer)APPLY(ctx,12,local+9); /*apply*/
	local[9]= fqv[27];
	local[10]= argv[0];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F2126(ctx,3,local+9); /*replace-key-arg*/
	local[0] = w;
	local[9]= fqv[26];
	local[10]= makeint(1);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F2126(ctx,3,local+9); /*replace-key-arg*/
	local[0] = w;
	local[9]= loadglobal(fqv[62]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= (pointer)get_sym_func(fqv[13]);
	local[11]= local[9];
	local[12]= fqv[4];
	local[13]= fqv[27];
	local[14]= argv[0];
	local[15]= fqv[63];
	local[16]= T;
	local[17]= fqv[8];
	local[18]= local[1];
	local[19]= fqv[64];
	local[20]= local[2];
	local[21]= fqv[65];
	local[22]= makeint(1);
	local[23]= fqv[29];
	local[24]= fqv[66];
	local[25]= fqv[67];
	local[26]= argv[3];
	local[27]= fqv[68];
	local[28]= argv[4];
	local[29]= local[0];
	ctx->vsp=local+30;
	w=(pointer)APPLY(ctx,20,local+10); /*apply*/
	w = local[9];
	argv[0]->c.obj.iv[19] = w;
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= fqv[69];
	local[11]= argv[0]->c.obj.iv[17];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= fqv[70];
	local[11]= fqv[71];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (local[3]==NIL) goto IF2281;
	local[9]= argv[0];
	local[10]= fqv[72];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	goto IF2282;
IF2281:
	local[9]= NIL;
IF2282:
	local[9]= argv[0];
	local[10]= fqv[73];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	w = argv[0];
	local[0]= w;
BLK2274:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2283(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= makeint(1);
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[19];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2284:
	ctx->vsp=local; return(local[0]);}

/*:getstring*/
static pointer M2285(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[19];
	local[1]= fqv[74];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2286:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2287(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2291;}
	local[0]= NIL;
ENT2291:
	if (n>=4) { local[1]=(argv[3]); goto ENT2290;}
	local[1]= NIL;
ENT2290:
ENT2289:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= NIL;
	w = local[0];
	if (!isstring(w)) goto IF2292;
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= fqv[76];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2293;
IF2292:
	local[4]= NIL;
IF2293:
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= fqv[74];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	if (local[1]==NIL) goto IF2294;
	local[4]= argv[0];
	local[5]= fqv[45];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2295;
IF2294:
	local[4]= NIL;
IF2295:
	w = local[3];
	local[0]= w;
BLK2288:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2296(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0]->c.obj.iv[19];
	local[4]= fqv[77];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2297:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2298(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0]->c.obj.iv[19];
	local[4]= fqv[78];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2299:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2300(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2302:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[79], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2303;
	local[1] = makeflt(0.00000000e+00);
KEY2303:
	if (n & (1<<1)) goto KEY2304;
	local[2] = makeflt(1.00000000e+00);
KEY2304:
	if (n & (1<<2)) goto KEY2305;
	local[3] = NIL;
KEY2305:
	if (n & (1<<3)) goto KEY2306;
	local[4] = NIL;
KEY2306:
	if (n & (1<<4)) goto KEY2307;
	local[5] = NIL;
KEY2307:
	if (n & (1<<5)) goto KEY2308;
	local[6] = fqv[80];
KEY2308:
	if (n & (1<<6)) goto KEY2309;
	local[7] = loadglobal(fqv[1]);
KEY2309:
	if (n & (1<<7)) goto KEY2310;
	local[8] = makeint(100);
KEY2310:
	if (n & (1<<8)) goto KEY2311;
	local[9] = makeint(0);
KEY2311:
	if (n & (1<<9)) goto KEY2312;
	local[10] = local[1];
KEY2312:
	if (n & (1<<10)) goto KEY2313;
	local[11] = T;
KEY2313:
	argv[0]->c.obj.iv[21] = local[10];
	argv[0]->c.obj.iv[24] = local[6];
	argv[0]->c.obj.iv[32] = NIL;
	local[12]= argv[0];
	local[13]= fqv[81];
	local[14]= local[1];
	local[15]= local[4];
	local[16]= local[2];
	local[17]= local[5];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,6,local+12); /*send*/
	local[12]= argv[2];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[12]= NIL;
	local[13]= local[6];
	local[14]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[0])(ctx,1,local+12,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[29] = w;
	local[12]= fqv[82];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[33] = w;
	local[12]= argv[0]->c.obj.iv[33];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	argv[0]->c.obj.iv[33] = w;
	local[12]= (pointer)get_sym_func(fqv[2]);
	local[13]= argv[0];
	local[14]= *(ovafptr(argv[1],fqv[3]));
	local[15]= fqv[4];
	local[16]= argv[2];
	local[17]= argv[3];
	local[18]= argv[4];
	local[19]= fqv[26];
	local[20]= local[9];
	local[21]= fqv[6];
	local[22]= argv[0]->c.obj.iv[17];
	local[23]= makeint(2);
	ctx->vsp=local+24;
	w=(pointer)AREF(ctx,2,local+22); /*aref*/
	local[22]= w;
	local[23]= argv[0]->c.obj.iv[33];
	local[24]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+25;
	w=(pointer)LENGTH(ctx,1,local+24); /*length*/
	local[24]= w;
	local[25]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+26;
	w=(pointer)LENGTH(ctx,1,local+25); /*length*/
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[24]= (pointer)((integer_t)local[24] + (integer_t)w);
	ctx->vsp=local+25;
	w=(pointer)TIMES(ctx,2,local+23); /***/
	local[23]= w;
	local[24]= argv[0]->c.obj.iv[29];
	local[25]= makeint(2);
	ctx->vsp=local+26;
	w=(pointer)AREF(ctx,2,local+24); /*aref*/
	local[24]= w;
	local[25]= local[8];
	local[26]= makeint(60);
	ctx->vsp=local+27;
	w=(pointer)PLUS(ctx,5,local+22); /*+*/
	local[22]= w;
	local[23]= fqv[7];
	local[24]= makeint(10);
	local[25]= argv[0]->c.obj.iv[17];
	local[26]= makeint(0);
	ctx->vsp=local+27;
	w=(pointer)AREF(ctx,2,local+25); /*aref*/
	local[25]= w;
	local[26]= argv[0]->c.obj.iv[17];
	local[27]= makeint(1);
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,2,local+26); /*aref*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)PLUS(ctx,3,local+24); /*+*/
	local[24]= w;
	local[25]= fqv[8];
	local[26]= local[7];
	local[27]= local[0];
	ctx->vsp=local+28;
	w=(pointer)APPLY(ctx,16,local+12); /*apply*/
	local[12]= argv[0]->c.obj.iv[17];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[29];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[33];
	local[15]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+16;
	w=(pointer)LENGTH(ctx,1,local+15); /*length*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	local[15]= makeint(17);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,4,local+12); /*+*/
	argv[0]->c.obj.iv[25] = w;
	local[12]= makeint(3);
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[17];
	local[15]= makeint(1);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	argv[0]->c.obj.iv[26] = w;
	argv[0]->c.obj.iv[27] = local[8];
	argv[0]->c.obj.iv[28] = makeint(3);
	local[12]= argv[0];
	local[13]= fqv[83];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[12]= makeint(5);
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	argv[0]->c.obj.iv[30] = w;
	local[12]= argv[0];
	local[13]= fqv[84];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= argv[0];
	local[13]= fqv[73];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	w = argv[0];
	local[0]= w;
BLK2301:
	ctx->vsp=local; return(local[0]);}

/*:new-range*/
static pointer M2314(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	argv[0]->c.obj.iv[19] = argv[2];
	argv[0]->c.obj.iv[20] = argv[4];
	w = argv[3];
	if (isstring(w)) goto IF2316;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	argv[3] = w;
	local[0]= argv[3];
	goto IF2317;
IF2316:
	local[0]= NIL;
IF2317:
	argv[0]->c.obj.iv[22] = argv[3];
	w = argv[5];
	if (isstring(w)) goto IF2318;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[24];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	argv[5] = w;
	local[0]= argv[5];
	goto IF2319;
IF2318:
	local[0]= NIL;
IF2319:
	argv[0]->c.obj.iv[23] = argv[5];
	w = argv[0]->c.obj.iv[23];
	local[0]= w;
BLK2315:
	ctx->vsp=local; return(local[0]);}

/*:continuous-notify*/
static pointer M2320(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[34];
	argv[0]->c.obj.iv[34] = argv[2];
	w = local[0];
	local[0]= w;
BLK2321:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2323(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= makeint(3);
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= makeint(13);
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= makeint(23);
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[33];
	local[6]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,5,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[87];
	local[2]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2324:
	ctx->vsp=local; return(local[0]);}

/*:display-value*/
static pointer M2325(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2328;}
	local[0]= argv[0]->c.obj.iv[21];
ENT2328:
ENT2327:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[19];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MIN(ctx,2,local+2); /*min*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[0] = w;
	w = argv[0]->c.obj.iv[20];
	if (!isint(w)) goto IF2329;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ROUND(ctx,1,local+1); /*round*/
	local[0] = w;
	local[1]= local[0];
	goto IF2330;
IF2329:
	local[1]= NIL;
IF2330:
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= makeint(7);
	local[4]= argv[0]->c.obj.iv[17];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[24];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2326:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2331(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2335;}
	local[0]= NIL;
ENT2335:
	if (n>=4) { local[1]=(argv[3]); goto ENT2334;}
	local[1]= NIL;
ENT2334:
ENT2333:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF2336;
	local[2]= argv[0];
	local[3]= fqv[87];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[86];
	local[4]= argv[0]->c.obj.iv[31];
	local[5]= argv[0];
	local[6]= fqv[83];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[83];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[0]->c.obj.iv[31] = w;
	argv[0]->c.obj.iv[21] = local[0];
	local[2]= argv[0]->c.obj.iv[21];
	goto IF2337;
IF2336:
	local[2]= NIL;
IF2337:
	if (local[1]==NIL) goto IF2338;
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[3]));
	local[4]= fqv[45];
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,4,local+2); /*send-message*/
	local[2]= w;
	goto IF2339;
IF2338:
	local[2]= NIL;
IF2339:
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2332:
	ctx->vsp=local; return(local[0]);}

/*:nob-x*/
static pointer M2340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2343;}
	local[0]= argv[0]->c.obj.iv[21];
ENT2343:
ENT2342:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[25];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0]= w;
BLK2341:
	ctx->vsp=local; return(local[0]);}

/*:inside-nob-p*/
static pointer M2344(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[31];
	local[3]= makeint(7);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND2346;
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= makeint(5);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[26];
	local[3]= makeint(5);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
AND2346:
	w = local[0];
	local[0]= w;
BLK2345:
	ctx->vsp=local; return(local[0]);}

/*:draw-bar-rectangle*/
static pointer M2347(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[88];
	local[2]= argv[0]->c.obj.iv[25];
	local[3]= argv[0]->c.obj.iv[26];
	local[4]= makeint(5);
	local[5]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK2348:
	ctx->vsp=local; return(local[0]);}

/*:draw-nob-rectangle*/
static pointer M2349(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2353;}
	local[0]= argv[0]->c.obj.iv[31];
ENT2353:
	if (n>=4) { local[1]=(argv[3]); goto ENT2352;}
	local[1]= argv[0]->c.obj.iv[31];
ENT2352:
ENT2351:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[89];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= makeint(5);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(7);
	local[7]= makeint(13);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= loadglobal(fqv[90]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[89];
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= makeint(5);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(7);
	local[7]= makeint(13);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK2350:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2354(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[91]); /*event-pos*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[92];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (w==NIL) goto IF2356;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,1,local+4,&ftab[9],fqv[91]); /*event-pos*/
	argv[0]->c.obj.iv[32] = w;
	local[4]= argv[0]->c.obj.iv[32];
	goto IF2357;
IF2356:
	local[4]= NIL;
IF2357:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2355:
	ctx->vsp=local; return(local[0]);}

/*:compute-value*/
static pointer M2358(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[91]); /*event-pos*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[25];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[20];
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+7;
	w=(pointer)F2125(ctx,3,local+4); /*clump*/
	local[4]= w;
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2359:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2360(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[32]==NIL) goto IF2362;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= argv[0];
	local[6]= fqv[93];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[34];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2363;
IF2362:
	local[3]= NIL;
IF2363:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2361:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2364(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[32]==NIL) goto IF2366;
	argv[0]->c.obj.iv[32] = NIL;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= argv[0];
	local[6]= fqv[93];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= T;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2367;
IF2366:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[46];
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
IF2367:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2365:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2368(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2370:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[94], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2371;
	local[1] = loadglobal(fqv[19]);
KEY2371:
	if (n & (1<<1)) goto KEY2372;
	local[2] = fqv[95];
KEY2372:
	if (n & (1<<2)) goto KEY2373;
	local[3] = NIL;
KEY2373:
	if (n & (1<<3)) goto KEY2374;
	local[4] = makeint(0);
KEY2374:
	if (n & (1<<4)) goto KEY2375;
	local[5] = makeint(13);
KEY2375:
	if (n & (1<<5)) goto KEY2376;
	local[6] = makeint(0);
KEY2376:
	if (n & (1<<6)) goto KEY2377;
	local[7] = NIL;
KEY2377:
	if (n & (1<<7)) goto KEY2378;
	local[8] = NIL;
KEY2378:
	if (n & (1<<8)) goto KEY2379;
	local[9] = NIL;
KEY2379:
	if (n & (1<<9)) goto KEY2380;
	local[10] = NIL;
KEY2380:
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= (pointer)get_sym_func(fqv[96]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,2,local+14); /*mapcar*/
	argv[0]->c.obj.iv[19] = w;
	argv[0]->c.obj.iv[20] = local[4];
	local[14]= local[5];
	local[15]= local[14];
	w = argv[0];
	w->c.obj.iv[23] = local[15];
	if (local[3]!=NIL) goto IF2381;
	local[14]= local[1];
	local[15]= fqv[97];
	local[16]= fqv[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[3] = w;
	local[14]= local[3];
	goto IF2382;
IF2381:
	local[14]= NIL;
IF2382:
	local[14]= argv[2];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(*ftab[0])(ctx,2,local+14,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[14]= NIL;
	local[15]= local[2];
WHL2384:
	if (local[15]==NIL) goto WHX2385;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(*ftab[0])(ctx,2,local+16,&ftab[0],fqv[9]); /*textdots*/
	local[16]= w;
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,2,local+16); /*aref*/
	local[16]= w;
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	goto WHL2384;
WHX2385:
	local[16]= NIL;
BLK2386:
	w = NIL;
	local[14]= local[13];
	ctx->vsp=local+15;
	w=(pointer)NREVERSE(ctx,1,local+14); /*nreverse*/
	local[14]= (pointer)get_sym_func(fqv[2]);
	local[15]= argv[0];
	local[16]= *(ovafptr(argv[1],fqv[3]));
	local[17]= fqv[4];
	local[18]= argv[2];
	local[19]= argv[3];
	local[20]= argv[4];
	local[21]= fqv[27];
	local[22]= local[1];
	local[23]= fqv[26];
	local[24]= local[6];
	local[25]= fqv[6];
	local[26]= argv[0]->c.obj.iv[17];
	local[27]= makeint(2);
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,2,local+26); /*aref*/
	local[26]= w;
	local[27]= (pointer)get_sym_func(fqv[98]);
	local[28]= local[13];
	ctx->vsp=local+29;
	w=(pointer)APPLY(ctx,2,local+27); /*apply*/
	local[27]= w;
	local[28]= local[2];
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	{ integer_t i,j;
		j=intval(makeint(5)); i=intval(local[28]);
		local[28]=(makeint(i * j));}
	local[29]= makeint(20);
	ctx->vsp=local+30;
	w=(pointer)PLUS(ctx,4,local+26); /*+*/
	local[26]= w;
	local[27]= fqv[7];
	local[28]= makeint(10);
	local[29]= local[5];
	local[30]= argv[0]->c.obj.iv[17];
	local[31]= makeint(0);
	ctx->vsp=local+32;
	w=(pointer)AREF(ctx,2,local+30); /*aref*/
	local[30]= w;
	local[31]= argv[0]->c.obj.iv[17];
	local[32]= makeint(1);
	ctx->vsp=local+33;
	w=(pointer)AREF(ctx,2,local+31); /*aref*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)PLUS(ctx,4,local+28); /*+*/
	local[28]= w;
	local[29]= fqv[8];
	local[30]= local[3];
	local[31]= fqv[29];
	local[32]= local[7];
	local[33]= fqv[99];
	ctx->vsp=local+34;
	w=(*ftab[10])(ctx,2,local+32,&ftab[10],fqv[100]); /*union*/
	local[32]= w;
	local[33]= local[0];
	ctx->vsp=local+34;
	w=(pointer)APPLY(ctx,20,local+14); /*apply*/
	local[14]= argv[0]->c.obj.iv[17];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	local[15]= argv[0]->c.obj.iv[17];
	local[16]= makeint(1);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	local[16]= local[5];
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,2,local+16); /*/*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,3,local+14); /*+*/
	local[12] = w;
	local[14]= makeint(5);
	local[15]= argv[0]->c.obj.iv[17];
	local[16]= makeint(2);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= argv[0]->c.obj.iv[19];
WHL2389:
	if (local[17]==NIL) goto WHX2390;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= local[14];
	local[20]= argv[0]->c.obj.iv[17];
	local[21]= makeint(0);
	ctx->vsp=local+22;
	w=(pointer)AREF(ctx,2,local+20); /*aref*/
	local[20]= w;
	local[21]= makeint(3);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,2,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NCONC(ctx,2,local+18); /*nconc*/
	local[18]= makeint(4);
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[19];
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[15] = w;
	local[18]= local[16];
	local[19]= local[15];
	local[20]= makeint(2);
	ctx->vsp=local+21;
	w=(pointer)QUOTIENT(ctx,2,local+19); /*/*/
	local[19]= w;
	local[20]= local[14];
	local[21]= local[5];
	local[22]= makeint(2);
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,3,local+19); /*+*/
	local[19]= w;
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(pointer)MKINTVECTOR(ctx,2,local+19); /*integer-vector*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NCONC(ctx,2,local+18); /*nconc*/
	local[18]= local[14];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[14] = w;
	goto WHL2389;
WHX2390:
	local[18]= NIL;
BLK2391:
	w = NIL;
	local[14]= argv[0];
	local[15]= fqv[73];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= argv[0];
	local[15]= fqv[101];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	w = argv[0];
	local[0]= w;
BLK2369:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2394(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2397;}
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
ENT2397:
ENT2396:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= makeint(3);
	local[4]= argv[0];
	local[5]= fqv[7];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2395:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2398(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[19];
WHL2401:
	if (local[1]==NIL) goto WHX2402;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[37];
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
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[102];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[103]); /*fourth*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL2401;
WHX2402:
	local[2]= NIL;
BLK2403:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[101];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2399:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2409;}
	local[0]= NIL;
ENT2409:
	if (n>=4) { local[1]=(argv[3]); goto ENT2408;}
	local[1]= NIL;
ENT2408:
ENT2407:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF2410;
	local[2]= argv[0];
	local[3]= fqv[101];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	argv[0]->c.obj.iv[20] = local[0];
	local[2]= argv[0]->c.obj.iv[20];
	goto IF2411;
IF2410:
	local[2]= NIL;
IF2411:
	if (local[1]==NIL) goto IF2412;
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[3]));
	local[4]= fqv[45];
	local[5]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,4,local+2); /*send-message*/
	local[2]= w;
	goto IF2413;
IF2412:
	local[2]= NIL;
IF2413:
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK2406:
	ctx->vsp=local; return(local[0]);}

/*:draw-active-button*/
static pointer M2414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2418;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2418:
	if (n>=4) { local[1]=(argv[3]); goto ENT2417;}
	local[1]= argv[0]->c.obj.iv[20];
ENT2417:
ENT2416:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[104];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[103]); /*fourth*/
	local[4]= w;
	local[5]= fqv[105];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= loadglobal(fqv[90]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[104];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[103]); /*fourth*/
	local[4]= w;
	local[5]= fqv[106];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK2415:
	ctx->vsp=local; return(local[0]);}

/*:choice*/
static pointer M2419(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[40]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[41]); /*event-y*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= makeint(0);
WHL2421:
	if (local[5]==NIL) goto WHX2422;
	local[7]= local[3];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(*ftab[11])(ctx,1,local+8,&ftab[11],fqv[103]); /*fourth*/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF2424;
	w = local[6];
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK2420;
	goto IF2425;
IF2424:
	local[7]= NIL;
IF2425:
	local[6] = (pointer)((integer_t)(local[6])+4);
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[7];
	goto WHL2421;
WHX2422:
	local[7]= NIL;
BLK2423:
	w = NIL;
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2420:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2427(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	local[4]= fqv[107];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[21] = w;
	local[3]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2428:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2429(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	local[4]= fqv[107];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF2431;
	local[4]= local[3];
	if (argv[0]->c.obj.iv[21]!=local[4]) goto IF2431;
	local[4]= argv[0];
	local[5]= fqv[72];
	local[6]= argv[0]->c.obj.iv[21];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	argv[0]->c.obj.iv[21] = NIL;
	local[4]= argv[0]->c.obj.iv[21];
	goto IF2432;
IF2431:
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[3]));
	local[6]= fqv[46];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,4,local+4); /*send-message*/
	local[4]= w;
IF2432:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2430:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2433(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2435:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[108], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2436;
	local[1] = makeint(5);
KEY2436:
	if (n & (1<<1)) goto KEY2437;
	local[2] = NIL;
KEY2437:
	if (n & (1<<2)) goto KEY2438;
	local[3] = T;
KEY2438:
	if (n & (1<<3)) goto KEY2439;
	local[4] = makeflt(-1.00000000e+00);
KEY2439:
	if (n & (1<<4)) goto KEY2440;
	local[5] = makeflt(1.00000000e+00);
KEY2440:
	if (n & (1<<5)) goto KEY2441;
	local[6] = makeflt(-1.00000000e+00);
KEY2441:
	if (n & (1<<6)) goto KEY2442;
	local[7] = makeflt(1.00000000e+00);
KEY2442:
	local[8]= (pointer)get_sym_func(fqv[2]);
	local[9]= argv[0];
	local[10]= *(ovafptr(argv[1],fqv[3]));
	local[11]= fqv[4];
	local[12]= argv[2];
	local[13]= argv[3];
	local[14]= argv[4];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,8,local+8); /*apply*/
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[24] = w;
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[25] = w;
	argv[0]->c.obj.iv[26] = argv[0]->c.obj.iv[24];
	argv[0]->c.obj.iv[27] = argv[0]->c.obj.iv[25];
	argv[0]->c.obj.iv[30] = local[2];
	local[8]= local[4];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[20] = local[9];
	local[8]= local[6];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[21] = local[9];
	local[8]= local[5];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[22] = local[9];
	local[8]= local[7];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[23] = local[9];
	local[8]= local[1];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[19] = local[9];
	local[8]= local[3];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[34] = local[9];
	local[8]= local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeflt(2.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[28] = w;
	local[8]= local[6];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeflt(2.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[29] = w;
	local[8]= local[5];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+10;
	w=(pointer)EUSFLOAT(ctx,1,local+9); /*float*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[32] = w;
	local[8]= local[7];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+10;
	w=(pointer)EUSFLOAT(ctx,1,local+9); /*float*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[33] = w;
	argv[0]->c.obj.iv[31] = NIL;
	local[8]= argv[0];
	local[9]= fqv[73];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK2434:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2443(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[110];
	local[2]= argv[0]->c.obj.iv[28];
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK2444:
	ctx->vsp=local; return(local[0]);}

/*:draw-circles*/
static pointer M2445(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[10];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(0);
	local[9]= makeflt(6.28318405e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeflt(7.50000000e-01);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeflt(7.50000000e-01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeflt(6.28318405e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= makeint(2);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeflt(5.19999981e-01);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CEILING(ctx,1,local+6); /*ceiling*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeflt(5.19999981e-01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CEILING(ctx,1,local+7); /*ceiling*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeflt(6.28318405e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= makeint(3);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeint(3);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeflt(2.69999981e-01);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CEILING(ctx,1,local+6); /*ceiling*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeflt(2.69999981e-01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CEILING(ctx,1,local+7); /*ceiling*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeflt(6.28318405e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= argv[0]->c.obj.iv[5];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = argv[0];
	local[0]= w;
BLK2446:
	ctx->vsp=local; return(local[0]);}

/*:xy*/
static pointer M2447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2451;}
	local[0]= argv[0]->c.obj.iv[28];
ENT2451:
	if (n>=4) { local[1]=(argv[3]); goto ENT2450;}
	local[1]= argv[0]->c.obj.iv[29];
ENT2450:
ENT2449:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[22];
	local[5]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[26] = w;
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[27] = w;
	w = argv[0]->c.obj.iv[27];
	local[0]= w;
BLK2448:
	ctx->vsp=local; return(local[0]);}

/*:draw-stick*/
static pointer M2452(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2457;}
	local[0]= argv[0]->c.obj.iv[28];
ENT2457:
	if (n>=4) { local[1]=(argv[3]); goto ENT2456;}
	local[1]= argv[0]->c.obj.iv[29];
ENT2456:
	if (n>=5) { local[2]=(argv[4]); goto ENT2455;}
	local[2]= T;
ENT2455:
ENT2454:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[75];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[109];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[112];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[113];
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[27];
	local[7]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[19];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[19];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= makeint(0);
	local[10]= makeflt(6.28318405e+00);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[28] = local[0];
	argv[0]->c.obj.iv[29] = local[1];
	w = argv[0]->c.obj.iv[29];
	local[0]= w;
BLK2453:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2458(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2463;}
	local[0]= NIL;
ENT2463:
	if (n>=4) { local[1]=(argv[3]); goto ENT2462;}
	local[1]= NIL;
ENT2462:
	if (n>=5) { local[2]=(argv[4]); goto ENT2461;}
	local[2]= NIL;
ENT2461:
ENT2460:
	if (n>5) maerror();
	if (local[0]==NIL) goto IF2464;
	if (local[1]==NIL) goto IF2464;
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[22];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MIN(ctx,2,local+4); /*min*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	local[0] = w;
	local[3]= argv[0]->c.obj.iv[21];
	local[4]= argv[0]->c.obj.iv[23];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MIN(ctx,2,local+4); /*min*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[110];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2465;
IF2464:
	local[3]= NIL;
IF2465:
	if (local[2]==NIL) goto IF2466;
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[45];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,5,local+3); /*send-message*/
	local[3]= w;
	goto IF2467;
IF2466:
	local[3]= NIL;
IF2467:
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= argv[0]->c.obj.iv[29];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK2459:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2469(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[40]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[41]); /*event-y*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[4];
	local[7]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[6];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SQRT(ctx,1,local+7); /*sqrt*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF2471;
	argv[0]->c.obj.iv[31] = T;
	local[7]= argv[0]->c.obj.iv[31];
	goto IF2472;
IF2471:
	local[7]= NIL;
IF2472:
	w = local[7];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2470:
	ctx->vsp=local; return(local[0]);}

/*:value-from-event*/
static pointer M2473(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (n>=4) { local[3]=(argv[3]); goto ENT2476;}
	local[3]= argv[0]->c.obj.iv[34];
ENT2476:
ENT2475:
	if (n>4) maerror();
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,1,local+4,&ftab[3],fqv[40]); /*event-x*/
	local[4]= w;
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[41]); /*event-y*/
	local[5]= w;
	local[6]= local[4];
	local[7]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[27];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0]->c.obj.iv[28];
	local[11]= local[6];
	local[12]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[8] = w;
	local[10]= argv[0]->c.obj.iv[29];
	local[11]= local[7];
	local[12]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[9] = w;
	local[10]= argv[0];
	local[11]= fqv[72];
	local[12]= local[8];
	local[13]= local[9];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,5,local+10); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK2474:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2477(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[31]==NIL) goto IF2479;
	local[3]= argv[0];
	local[4]= fqv[114];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2480;
IF2479:
	local[3]= NIL;
IF2480:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2478:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2481(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[31]==NIL) goto IF2483;
	argv[0]->c.obj.iv[31] = NIL;
	if (argv[0]->c.obj.iv[30]==NIL) goto CON2486;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[21];
	local[7]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeflt(2.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= w;
	goto CON2485;
CON2486:
	if (argv[0]->c.obj.iv[34]!=NIL) goto CON2487;
	local[3]= argv[0];
	local[4]= fqv[114];
	local[5]= loadglobal(fqv[14]);
	local[6]= T;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON2485;
CON2487:
	local[3]= NIL;
CON2485:
	goto IF2484;
IF2483:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[46];
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
IF2484:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2482:
	ctx->vsp=local; return(local[0]);}

/*:create-bitmap-from-file*/
static pointer M2488(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[115]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= loadglobal(fqv[115]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= loadglobal(fqv[116]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= loadglobal(fqv[115]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= loadglobal(fqv[115]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[117]); /*probe-file*/
	if (w!=NIL) goto IF2490;
	local[5]= NIL;
	local[6]= fqv[118];
	local[7]= loadglobal(fqv[119]);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	argv[2] = w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[117]); /*probe-file*/
	if (w!=NIL) goto IF2492;
	local[5]= fqv[120];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,2,local+5); /*error*/
	local[5]= w;
	goto IF2493;
IF2492:
	local[5]= NIL;
IF2493:
	goto IF2491;
IF2490:
	local[5]= NIL;
IF2491:
	local[5]= loadglobal(fqv[121]);
	local[6]= loadglobal(fqv[121]);
	ctx->vsp=local+7;
	w=(*ftab[13])(ctx,1,local+6,&ftab[13],fqv[122]); /*defaultrootwindow*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[14])(ctx,8,local+5,&ftab[14],fqv[123]); /*readbitmapfile*/
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,1,local+5,&ftab[15],fqv[115]); /*c-int*/
	argv[0]->c.obj.iv[26] = w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,1,local+5,&ftab[15],fqv[115]); /*c-int*/
	argv[0]->c.obj.iv[27] = w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[116]); /*c-long*/
	argv[0]->c.obj.iv[25] = w;
	w = argv[0]->c.obj.iv[25];
	local[0]= w;
BLK2489:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2494(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2495:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2496(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2501;}
	local[0]= fqv[24];
ENT2501:
	if (n>=4) { local[1]=(argv[3]); goto ENT2500;}
	local[1]= argv[0]->c.obj.iv[4];
ENT2500:
	if (n>=5) { local[2]=(argv[4]); goto ENT2499;}
	local[2]= makeint(2);
ENT2499:
ENT2498:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[34];
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= local[2];
	local[10]= argv[0]->c.obj.iv[23];
	local[11]= argv[0]->c.obj.iv[22];
	local[12]= argv[0]->c.obj.iv[4];
	local[13]= argv[0]->c.obj.iv[24];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,12,local+3); /*send*/
	local[3]= loadglobal(fqv[121]);
	local[4]= argv[0]->c.obj.iv[25];
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= argv[0]->c.obj.iv[26];
	local[10]= argv[0]->c.obj.iv[27];
	local[11]= makeint(2);
	local[12]= makeint(2);
	local[13]= makeint(1);
	ctx->vsp=local+14;
	w=(*ftab[17])(ctx,11,local+3,&ftab[17],fqv[124]); /*copyplane*/
	local[0]= w;
BLK2497:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2504:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[125], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2505;
	local[1] = NIL;
KEY2505:
	if (n & (1<<1)) goto KEY2506;
	local[2] = NIL;
KEY2506:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[126];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (local[1]!=NIL) goto IF2507;
	local[6]= argv[0]->c.obj.iv[26];
	local[7]= makeint(4);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	goto IF2508;
IF2507:
	local[6]= local[1];
IF2508:
	local[4] = local[6];
	if (local[2]!=NIL) goto IF2509;
	local[6]= argv[0]->c.obj.iv[27];
	local[7]= makeint(4);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	goto IF2510;
IF2509:
	local[6]= local[2];
IF2510:
	local[5] = local[6];
	local[6]= (pointer)get_sym_func(fqv[2]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[3]));
	local[9]= fqv[4];
	local[10]= argv[2];
	local[11]= argv[3];
	local[12]= argv[4];
	local[13]= fqv[6];
	local[14]= local[4];
	local[15]= fqv[7];
	local[16]= local[5];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,12,local+6); /*apply*/
	local[6]= argv[2];
	local[7]= local[6];
	w = argv[0];
	w->c.obj.iv[16] = local[7];
	w = local[6];
	w = argv[0];
	local[0]= w;
BLK2503:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xitem(ctx,n,argv,env)
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
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2511;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF2512;
IF2511:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2512:
	local[0]= fqv[131];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[133]); /*require*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[55];
	local[1]= fqv[135];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2513;
	local[0]= fqv[55];
	local[1]= fqv[135];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2515;
	local[0]= fqv[55];
	local[1]= fqv[136];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2516;
IF2515:
	local[0]= NIL;
IF2516:
	local[0]= fqv[55];
	goto IF2514;
IF2513:
	local[0]= NIL;
IF2514:
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F2125,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F2126,fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2138,fqv[4],fqv[141],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2147,fqv[32],fqv[141],fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2149,fqv[45],fqv[141],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2156,fqv[145],fqv[141],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2158,fqv[147],fqv[141],fqv[148]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2160,fqv[149],fqv[141],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2162,fqv[151],fqv[141],fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2164,fqv[78],fqv[141],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2166,fqv[77],fqv[141],fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F2127,fqv[156]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2169,fqv[4],fqv[157],fqv[158]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2188,fqv[159],fqv[157],fqv[160]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2194,fqv[161],fqv[157],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2200,fqv[33],fqv[157],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2202,fqv[50],fqv[157],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2209,fqv[32],fqv[157],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2220,fqv[73],fqv[157],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2222,fqv[145],fqv[157],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2224,fqv[147],fqv[157],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2226,fqv[149],fqv[157],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2228,fqv[46],fqv[157],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2237,fqv[78],fqv[157],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2241,fqv[77],fqv[157],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2245,fqv[4],fqv[173],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2251,fqv[50],fqv[173],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2259,fqv[57],fqv[173],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2261,fqv[58],fqv[173],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2263,fqv[149],fqv[173],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2265,fqv[46],fqv[173],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2269,fqv[78],fqv[173],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2273,fqv[4],fqv[181],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2283,fqv[73],fqv[181],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2285,fqv[184],fqv[181],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2287,fqv[72],fqv[181],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2296,fqv[77],fqv[181],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2298,fqv[78],fqv[181],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2300,fqv[4],fqv[189],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2314,fqv[81],fqv[189],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2320,fqv[84],fqv[189],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2323,fqv[73],fqv[189],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2325,fqv[87],fqv[189],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2331,fqv[72],fqv[189],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2340,fqv[83],fqv[189],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2344,fqv[92],fqv[189],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2347,fqv[85],fqv[189],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2349,fqv[86],fqv[189],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2354,fqv[149],fqv[189],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2358,fqv[93],fqv[189],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2360,fqv[151],fqv[189],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2364,fqv[46],fqv[189],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2368,fqv[4],fqv[204],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2394,fqv[32],fqv[204],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2398,fqv[73],fqv[204],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2405,fqv[72],fqv[204],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2414,fqv[101],fqv[204],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2419,fqv[107],fqv[204],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2427,fqv[149],fqv[204],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2429,fqv[46],fqv[204],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2433,fqv[4],fqv[213],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2443,fqv[73],fqv[213],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2445,fqv[109],fqv[213],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2447,fqv[112],fqv[213],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2452,fqv[110],fqv[213],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2458,fqv[72],fqv[213],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2469,fqv[149],fqv[213],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2473,fqv[114],fqv[213],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2477,fqv[151],fqv[213],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2481,fqv[46],fqv[213],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2488,fqv[126],fqv[224],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2494,fqv[73],fqv[224],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2496,fqv[32],fqv[224],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2502,fqv[4],fqv[224],fqv[228]);
	local[0]= fqv[229];
	local[1]= fqv[230];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[231]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<20; i++) ftab[i]=fcallx;
}
