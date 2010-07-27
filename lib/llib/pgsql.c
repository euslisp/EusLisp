/* pgsql.c :  entry=pgsql */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "pgsql.h"
#pragma init (register_pgsql)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___pgsql();
extern pointer build_quote_vector();
static register_pgsql()
  { add_module_initializer("___pgsql", ___pgsql);}

static pointer F76();
static pointer F77();
static pointer F78();
static pointer F79();
static pointer F80();
static pointer F81();
static pointer F82();
static pointer F83();
static pointer F84();
static pointer F85();
static pointer F86();
static pointer F87();
static pointer F88();
static pointer F89();
static pointer F90();
static pointer F91();

/*pq-handler*/
static pointer F76(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[1];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK92:
	ctx->vsp=local; return(local[0]);}

/*pgsql-field*/
static pointer F77(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[2]);
	w = local[0];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[3],w);
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,3,local+4,&ftab[0],fqv[4]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK93:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M94(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[5], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY96;
	local[0] = fqv[6];
KEY96:
	if (n & (1<<1)) goto KEY97;
	local[1] = makeint(0);
KEY97:
	if (n & (1<<2)) goto KEY98;
	local[2] = makeint(0);
KEY98:
	if (n & (1<<3)) goto KEY99;
	local[3] = makeint(0);
KEY99:
	if (n & (1<<4)) goto KEY100;
	local[7]= fqv[7];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	if (w!=NIL) goto CON101;
CON102:
	local[7]= fqv[8];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	goto CON101;
CON103:
	local[7]= NIL;
CON101:
	local[4] = local[7];
KEY100:
	if (n & (1<<5)) goto KEY104;
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	if (w!=NIL) goto CON105;
CON106:
	local[7]= fqv[10];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	goto CON105;
CON107:
	local[7]= NIL;
CON105:
	local[5] = local[7];
KEY104:
	if (n & (1<<6)) goto KEY108;
	local[6] = makeint(0);
KEY108:
	local[7]= local[0];
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[1])(ctx,7,local+7,&ftab[1],fqv[11]); /*setdblogin*/
	argv[0]->c.obj.iv[1] = w;
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,1,local+7,&ftab[2],fqv[12]); /*pqstatus*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[13]); /*zerop*/
	if (w==NIL) goto CON110;
	if (loadglobal(fqv[14])==NIL) goto IF111;
	local[7]= makeint(4);
	local[8]= fqv[15];
	local[9]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[16]); /*pqhost*/
	local[9]= w;
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(*ftab[5])(ctx,1,local+10,&ftab[5],fqv[17]); /*pqport*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,1,local+11,&ftab[6],fqv[18]); /*pqdb*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,1,local+12,&ftab[7],fqv[19]); /*pquser*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[8])(ctx,6,local+7,&ftab[8],fqv[20]); /*warning-message*/
	local[7]= w;
	goto IF112;
IF111:
	local[7]= NIL;
IF112:
	goto CON109;
CON110:
	local[7]= fqv[21];
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,1,local+8,&ftab[9],fqv[22]); /*errormessage*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,2,local+7); /*error*/
	w = NIL;
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK95;
	goto CON109;
CON113:
	local[7]= NIL;
CON109:
	local[7]= argv[0];
	local[8]= fqv[23];
	local[9]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,1,local+9,&ftab[6],fqv[18]); /*pqdb*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[0]->c.obj.iv[1];
	storeglobal(fqv[24],local[7]);
	local[7]= loadglobal(fqv[25]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[26];
	local[10]= fqv[27];
	local[11]= makeint(100);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	w = local[7];
	argv[0]->c.obj.iv[9] = w;
	local[7]= argv[0];
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[29]); /*socket*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= loadglobal(fqv[30]);
	local[8]= fqv[31];
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= fqv[32];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[33];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	argv[0]->c.obj.iv[10] = T;
	w = argv[0];
	local[0]= w;
BLK95:
	ctx->vsp=local; return(local[0]);}

/*:finish*/
static pointer M115(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[35]); /*finish*/
	local[0]= loadglobal(fqv[30]);
	local[1]= fqv[36];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK116:
	ctx->vsp=local; return(local[0]);}

/*:dbname*/
static pointer M117(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[18]); /*pqdb*/
	local[0]= w;
BLK118:
	ctx->vsp=local; return(local[0]);}

/*:user*/
static pointer M119(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[19]); /*pquser*/
	local[0]= w;
BLK120:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M121(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[16]); /*pqhost*/
	local[0]= w;
BLK122:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M123(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[17]); /*pqport*/
	local[0]= w;
BLK124:
	ctx->vsp=local; return(local[0]);}

/*:password*/
static pointer M125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[37]); /*pqpass*/
	local[0]= w;
BLK126:
	ctx->vsp=local; return(local[0]);}

/*:type-conversion*/
static pointer M127(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[10] = argv[2];
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK128:
	ctx->vsp=local; return(local[0]);}

/*:types*/
static pointer M129(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK130:
	ctx->vsp=local; return(local[0]);}

/*:oid*/
static pointer M131(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK132:
	ctx->vsp=local; return(local[0]);}

/*:make-type-hashtab*/
static pointer M133(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[33];
	local[4]= fqv[39];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
WHL136:
	if (local[2]==NIL) goto WHX137;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= loadglobal(fqv[40]);
	w = local[3];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[41],w);
	local[7]= (pointer)get_sym_func(fqv[4]);
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	w = local[0];
	ctx->vsp=local+8;
	local[0] = cons(ctx,local[7],w);
	local[7]= local[0];
	ctx->vsp=local+8;
	unbindx(ctx,1);
	w = local[7];
	goto WHL136;
WHX137:
	local[3]= NIL;
BLK138:
	w = NIL;
	local[1]= NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[2]= w;
WHL141:
	if (local[2]==NIL) goto WHX142;
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
	local[4]= argv[0]->c.obj.iv[9];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,3,local+3,&ftab[13],fqv[42]); /*sethash*/
	goto WHL141;
WHX142:
	local[3]= NIL;
BLK143:
	w = NIL;
	local[0]= w;
BLK134:
	ctx->vsp=local; return(local[0]);}

/*:type-name*/
static pointer M145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[43]); /*gethash*/
	local[0]= w;
	if (local[0]!=NIL) goto CON148;
	local[1]= fqv[44];
	goto CON147;
CON148:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[13]); /*zerop*/
	if (w==NIL) goto CON149;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON147;
CON149:
	local[1]= fqv[45];
	goto CON147;
CON150:
	local[1]= NIL;
CON147:
	w = local[1];
	local[0]= w;
BLK146:
	ctx->vsp=local; return(local[0]);}

/*:records*/
static pointer M151(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK152:
	ctx->vsp=local; return(local[0]);}

/*:fields*/
static pointer M153(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK154:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M155(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[4] = NIL;
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK156:
	ctx->vsp=local; return(local[0]);}

/*:notify*/
static pointer M157(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST159:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	argv[0]->c.obj.iv[5] = local[0];
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK158:
	ctx->vsp=local; return(local[0]);}

/*:sendquery*/
static pointer M160(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST162:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	argv[0]->c.obj.iv[4] = NIL;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,2,local+1,&ftab[15],fqv[46]); /*sendquery*/
	local[0]= w;
BLK161:
	ctx->vsp=local; return(local[0]);}

/*:consume*/
static pointer M163(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[47]); /*consumeinput*/
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[48]); /*isbusy*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[13]); /*zerop*/
	if (w!=NIL) goto IF165;
	local[0]= fqv[49];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF166;
IF165:
	local[0]= NIL;
IF166:
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,1,local+2,&ftab[18],fqv[51]); /*getresult*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,1,local+2,&ftab[19],fqv[52]); /*functionp*/
	if (w==NIL) goto IF167;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[2]= w;
	goto IF168;
IF167:
	local[2]= (pointer)get_sym_func(fqv[53]);
	local[3]= local[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= argv[0]->c.obj.iv[4];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	local[2]= w;
IF168:
	w = local[2];
	local[0]= w;
BLK164:
	ctx->vsp=local; return(local[0]);}

/*:getfields*/
static pointer M169(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[3] = NIL;
	local[0]= makeint(0);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[54]); /*nfields*/
	local[1]= w;
WHL172:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX173;
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[55]); /*fname*/
	local[2]= w;
	w = argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[3] = cons(ctx,local[2],w);
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL172;
WHX173:
	local[2]= NIL;
BLK174:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
BLK170:
	ctx->vsp=local; return(local[0]);}

/*:ntuples*/
static pointer M175(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK176:
	ctx->vsp=local; return(local[0]);}

/*:nfields*/
static pointer M177(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK178:
	ctx->vsp=local; return(local[0]);}

/*:getvalues*/
static pointer M179(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	argv[0]->c.obj.iv[4] = NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,1,local+3,&ftab[22],fqv[56]); /*ntuples*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[54]); /*nfields*/
	argv[0]->c.obj.iv[8] = w;
	local[3]= loadglobal(fqv[57]);
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	argv[0]->c.obj.iv[6] = w;
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[8];
WHL182:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX183;
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= fqv[58];
	local[9]= argv[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[23])(ctx,2,local+9,&ftab[23],fqv[59]); /*ftype*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL182;
WHX183:
	local[5]= NIL;
BLK184:
	w = NIL;
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[7];
WHL186:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX187;
	local[2] = NIL;
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[8];
WHL190:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX191;
	local[7]= argv[2];
	local[8]= local[3];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[24])(ctx,3,local+7,&ftab[24],fqv[60]); /*getvalue*/
	local[1] = w;
	if (argv[0]->c.obj.iv[10]==NIL) goto IF193;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= local[7];
	w = fqv[61];
	if (memq(local[8],w)==NIL) goto IF196;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	local[8]= w;
	goto IF197;
IF196:
	local[8]= local[7];
	if (fqv[62]!=local[8]) goto IF198;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[25])(ctx,1,local+8,&ftab[25],fqv[63]); /*read-iso-date*/
	local[8]= w;
	goto IF199;
IF198:
	local[8]= local[7];
	if (fqv[64]!=local[8]) goto IF200;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[26])(ctx,1,local+8,&ftab[26],fqv[65]); /*read-iso-time*/
	local[8]= w;
	goto IF201;
IF200:
	local[8]= local[7];
	w = fqv[66];
	if (memq(local[8],w)==NIL) goto IF202;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[27])(ctx,1,local+8,&ftab[27],fqv[67]); /*read-iso-datetime*/
	local[8]= w;
	goto IF203;
IF202:
	local[8]= local[7];
	if (fqv[45]!=local[8]) goto IF204;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)F77(ctx,1,local+8); /*pgsql-field*/
	local[8]= w;
	goto IF205;
IF204:
	if (T==NIL) goto IF206;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)F77(ctx,1,local+8); /*pgsql-field*/
	local[8]= w;
	goto IF207;
IF206:
	local[8]= NIL;
IF207:
IF205:
IF203:
IF201:
IF199:
IF197:
	w = local[8];
	local[7]= w;
	goto IF194;
IF193:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)COPYSEQ(ctx,1,local+7); /*copy-seq*/
	local[7]= w;
IF194:
	local[1] = local[7];
	local[7]= local[1];
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL190;
WHX191:
	local[7]= NIL;
BLK192:
	w = NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[5]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+6;
	argv[0]->c.obj.iv[4] = cons(ctx,local[5],w);
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL186;
WHX187:
	local[5]= NIL;
BLK188:
	w = NIL;
	local[3]= argv[0];
	local[4]= fqv[68];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[28])(ctx,1,local+3,&ftab[28],fqv[69]); /*clear*/
	argv[2] = NIL;
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK180:
	ctx->vsp=local; return(local[0]);}

/*:process-result*/
static pointer M208(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[70]); /*resultstatus*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[71]!=local[1]) goto IF211;
	local[1]= makeint(4);
	local[2]= fqv[72];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,2,local+1,&ftab[8],fqv[20]); /*warning-message*/
	local[1]= NIL;
	goto IF212;
IF211:
	local[1]= local[0];
	if (fqv[73]!=local[1]) goto IF213;
	if (loadglobal(fqv[14])==NIL) goto IF215;
	local[1]= makeint(4);
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,2,local+1,&ftab[8],fqv[20]); /*warning-message*/
	local[1]= w;
	goto IF216;
IF215:
	local[1]= NIL;
IF216:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,1,local+1,&ftab[30],fqv[75]); /*oidstatus*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[4]); /*read-from-string*/
	argv[0]->c.obj.iv[11] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[28])(ctx,1,local+1,&ftab[28],fqv[69]); /*clear*/
	local[1]= argv[0]->c.obj.iv[11];
	goto IF214;
IF213:
	local[1]= local[0];
	if (fqv[76]!=local[1]) goto IF217;
	local[1]= argv[0];
	local[2]= fqv[77];
	local[3]= argv[2];
	local[4]= makeint(92);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,2,local+3,&ftab[31],fqv[78]); /*make-foreign-string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF218;
IF217:
	local[1]= local[0];
	w = fqv[79];
	if (memq(local[1],w)==NIL) goto IF219;
	local[1]= makeint(5);
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,2,local+1,&ftab[8],fqv[20]); /*warning-message*/
	local[1]= NIL;
	goto IF220;
IF219:
	local[1]= local[0];
	if (fqv[81]!=local[1]) goto IF221;
	local[1]= makeint(5);
	local[2]= fqv[82];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,2,local+1,&ftab[8],fqv[20]); /*warning-message*/
	local[1]= NIL;
	goto IF222;
IF221:
	local[1]= local[0];
	if (fqv[83]!=local[1]) goto IF223;
	local[1]= fqv[84];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF224;
IF223:
	local[1]= local[0];
	if (fqv[85]!=local[1]) goto IF225;
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF226;
IF225:
	local[1]= NIL;
IF226:
IF224:
IF222:
IF220:
IF218:
IF214:
IF212:
	w = local[1];
	local[0]= w;
BLK209:
	ctx->vsp=local; return(local[0]);}

/*:exec*/
static pointer M227(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[32])(ctx,2,local+2,&ftab[32],fqv[87]); /*pqexec*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK228:
	ctx->vsp=local; return(local[0]);}

/*:lo-creat*/
static pointer M229(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT232;}
	local[0]= makeint(262144);
	w = makeint(131072);
	local[0]= (pointer)((integer_t)local[0] | (integer_t)w);
ENT232:
ENT231:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[33])(ctx,2,local+1,&ftab[33],fqv[88]); /*lo_creat*/
	local[0]= w;
BLK230:
	ctx->vsp=local; return(local[0]);}

/*:lo-import*/
static pointer M233(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[89];
	ctx->vsp=local+3;
	w=(*ftab[32])(ctx,2,local+1,&ftab[32],fqv[87]); /*pqexec*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[34])(ctx,2,local+1,&ftab[34],fqv[90]); /*lo_import*/
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[91];
	ctx->vsp=local+3;
	w=(*ftab[32])(ctx,2,local+1,&ftab[32],fqv[87]); /*pqexec*/
	w = local[0];
	local[0]= w;
BLK234:
	ctx->vsp=local; return(local[0]);}

/*:lo-export*/
static pointer M235(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[87]); /*pqexec*/
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[35])(ctx,3,local+0,&ftab[35],fqv[93]); /*lo_export*/
	argv[2] = w;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[94];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[87]); /*pqexec*/
	w = argv[2];
	local[0]= w;
BLK236:
	ctx->vsp=local; return(local[0]);}

/*:lo-open*/
static pointer M237(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT240;}
	local[0]= makeint(262144);
	w = makeint(131072);
	local[0]= (pointer)((integer_t)local[0] | (integer_t)w);
ENT240:
ENT239:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[36])(ctx,3,local+1,&ftab[36],fqv[95]); /*lo_open*/
	local[0]= w;
BLK238:
	ctx->vsp=local; return(local[0]);}

/*:lo-write*/
static pointer M241(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT244;}
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT244:
ENT243:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[37])(ctx,4,local+1,&ftab[37],fqv[96]); /*lo_write*/
	local[0]= w;
BLK242:
	ctx->vsp=local; return(local[0]);}

/*:lo-read*/
static pointer M245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(*ftab[38])(ctx,4,local+0,&ftab[38],fqv[97]); /*lo_read*/
	local[0]= w;
BLK246:
	ctx->vsp=local; return(local[0]);}

/*:lo-lseek*/
static pointer M247(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT250;}
	local[0]= makeint(0);
ENT250:
ENT249:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[39])(ctx,4,local+1,&ftab[39],fqv[98]); /*lo_lseek*/
	local[0]= w;
BLK248:
	ctx->vsp=local; return(local[0]);}

/*:lo-close*/
static pointer M251(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[99]); /*lo_close*/
	local[0]= w;
BLK252:
	ctx->vsp=local; return(local[0]);}

/*:lo-unlink*/
static pointer M253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[41])(ctx,2,local+0,&ftab[41],fqv[100]); /*lo_unlink*/
	local[0]= w;
BLK254:
	ctx->vsp=local; return(local[0]);}

/*:lo-test*/
static pointer M255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT258;}
	local[0]= makeint(262144);
	w = makeint(131072);
	local[0]= (pointer)((integer_t)local[0] | (integer_t)w);
ENT258:
ENT257:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[101];
	ctx->vsp=local+5;
	w=(*ftab[32])(ctx,2,local+3,&ftab[32],fqv[87]); /*pqexec*/
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP259,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[36])(ctx,3,local+5,&ftab[36],fqv[95]); /*lo_open*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREQP(ctx,2,local+5); /*>=*/
	local[2] = w;
	w = local[2];
	ctx->vsp=local+5;
	UWP259(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[2];
	local[0]= w;
BLK256:
	ctx->vsp=local; return(local[0]);}

/*:lo-put*/
static pointer M260(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT263;}
	local[0]= NIL;
ENT263:
ENT262:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[102];
	ctx->vsp=local+5;
	w=(*ftab[32])(ctx,2,local+3,&ftab[32],fqv[87]); /*pqexec*/
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP264,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	w = local[0];
	if (!isint(w)) goto IF265;
	local[1] = local[0];
	local[5]= local[1];
	goto IF266;
IF265:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= makeint(131072);
	ctx->vsp=local+7;
	w=(*ftab[33])(ctx,2,local+5,&ftab[33],fqv[88]); /*lo_creat*/
	local[1] = w;
	local[5]= local[1];
IF266:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= local[1];
	local[7]= makeint(131072);
	ctx->vsp=local+8;
	w=(*ftab[36])(ctx,3,local+5,&ftab[36],fqv[95]); /*lo_open*/
	local[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= local[2];
	local[7]= argv[2];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[37])(ctx,4,local+5,&ftab[37],fqv[96]); /*lo_write*/
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[40])(ctx,2,local+5,&ftab[40],fqv[99]); /*lo_close*/
	ctx->vsp=local+5;
	UWP264(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[1];
	local[0]= w;
BLK261:
	ctx->vsp=local; return(local[0]);}

/*:lo-get*/
static pointer M267(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(4096);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[103];
	ctx->vsp=local+6;
	w=(*ftab[32])(ctx,2,local+4,&ftab[32],fqv[87]); /*pqexec*/
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP269,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= argv[2];
	local[8]= makeint(262144);
	ctx->vsp=local+9;
	w=(*ftab[36])(ctx,3,local+6,&ftab[36],fqv[95]); /*lo_open*/
	local[0] = w;
WHL270:
	local[6]= local[3];
	local[7]= makeint(4096);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto WHX271;
	local[6]= makeint(4096);
	ctx->vsp=local+7;
	w=(*ftab[42])(ctx,1,local+6,&ftab[42],fqv[104]); /*make-string*/
	local[1] = w;
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= local[0];
	local[8]= local[1];
	local[9]= makeint(4096);
	ctx->vsp=local+10;
	w=(*ftab[38])(ctx,4,local+6,&ftab[38],fqv[97]); /*lo_read*/
	local[3] = w;
	local[6]= local[3];
	local[7]= makeint(4096);
	ctx->vsp=local+8;
	w=(*ftab[43])(ctx,2,local+6,&ftab[43],fqv[105]); /*/=*/
	if (w==NIL) goto IF273;
	local[6]= local[1];
	local[7]= makeint(0);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= local[1];
	goto IF274;
IF273:
	local[6]= NIL;
IF274:
	local[6]= local[1];
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	goto WHL270;
WHX271:
	local[6]= NIL;
BLK272:
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[40])(ctx,2,local+6,&ftab[40],fqv[99]); /*lo_close*/
	ctx->vsp=local+6;
	UWP269(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[4]= (pointer)get_sym_func(fqv[106]);
	local[5]= loadglobal(fqv[107]);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,3,local+4); /*apply*/
	local[0]= w;
BLK268:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP259(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= fqv[108];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[87]); /*pqexec*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[87]); /*pqexec*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= fqv[110];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[87]); /*pqexec*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*table-fields*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[111];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F82(ctx,4,local+0); /*query*/
	local[0]= w;
BLK275:
	ctx->vsp=local; return(local[0]);}

/*table-attributes*/
static pointer F79(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[112];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F82(ctx,4,local+0); /*query*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK276:
	ctx->vsp=local; return(local[0]);}

/*table-pkey*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[113];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F82(ctx,4,local+0); /*query*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK277:
	ctx->vsp=local; return(local[0]);}

/*escape-quote*/
static pointer F81(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	w=(*ftab[44])(ctx,0,local+0,&ftab[44],fqv[114]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL280:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX281;
	local[3]= argv[0];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= makeint(39);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF283;
	local[3]= makeint(92);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[3]= w;
	goto IF284;
IF283:
	local[3]= NIL;
IF284:
	local[3]= argv[0];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL280;
WHX281:
	local[3]= NIL;
BLK282:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[45])(ctx,1,local+1,&ftab[45],fqv[115]); /*get-output-stream-string*/
	local[0]= w;
BLK278:
	ctx->vsp=local; return(local[0]);}

/*query*/
static pointer F82(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST286:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[116]);
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0] = w;
	if (loadglobal(fqv[117])==NIL) goto IF287;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)PRINT(ctx,1,local+1); /*print*/
	local[1]= w;
	goto IF288;
IF287:
	local[1]= NIL;
IF288:
	if (argv[1]==NIL) goto IF289;
	local[1]= argv[0];
	local[2]= fqv[118];
	local[3]= local[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF290;
IF289:
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF290:
	w = local[1];
	local[0]= w;
BLK285:
	ctx->vsp=local; return(local[0]);}

/*tables*/
static pointer F83(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[119]);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= fqv[120];
	ctx->vsp=local+4;
	w=(pointer)F82(ctx,3,local+1); /*query*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK291:
	ctx->vsp=local; return(local[0]);}

/*delimit-list*/
static pointer F84(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT294;}
	local[0]= NIL;
ENT294:
ENT293:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
WHL296:
	if (local[3]==NIL) goto WHX297;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	if (local[0]==NIL) goto IF300;
	local[4]= NIL;
	local[5]= fqv[121];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	goto IF301;
IF300:
	local[4]= NIL;
	local[5]= fqv[122];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
IF301:
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= argv[1];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL296;
WHX297:
	local[4]= NIL;
BLK298:
	w = NIL;
	local[2]= (pointer)get_sym_func(fqv[106]);
	local[3]= loadglobal(fqv[107]);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK292:
	ctx->vsp=local; return(local[0]);}

/*where*/
static pointer F85(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto CON304;
	local[0]= NIL;
	local[1]= fqv[123];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON303;
CON304:
	w = argv[0];
	if (!!iscons(w)) goto CON305;
	local[0]= NIL;
	local[1]= fqv[124];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON303;
CON305:
	w = argv[0];
	if (!iscons(w)) goto CON306;
	local[0]= NIL;
	local[1]= fqv[125];
	local[2]= (pointer)get_sym_func(fqv[126]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= NIL;
	local[4]= fqv[127];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F84(ctx,2,local+2); /*delimit-list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON303;
CON306:
	local[0]= NIL;
CON303:
	w = local[0];
	local[0]= w;
BLK302:
	ctx->vsp=local; return(local[0]);}

/*select*/
static pointer F86(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[128], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY308;
	local[0] = NIL;
KEY308:
	if (n & (1<<1)) goto KEY309;
	local[1] = NIL;
KEY309:
	if (n & (1<<2)) goto KEY310;
	local[2] = NIL;
KEY310:
	if (n & (1<<3)) goto KEY311;
	local[3] = NIL;
KEY311:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= fqv[129];
	w = argv[1];
	if (!iscons(w)) goto IF312;
	local[7]= argv[1];
	local[8]= fqv[130];
	ctx->vsp=local+9;
	w=(pointer)F84(ctx,2,local+7); /*delimit-list*/
	local[7]= w;
	goto IF313;
IF312:
	local[7]= argv[1];
IF313:
	w = argv[2];
	if (!iscons(w)) goto IF314;
	local[8]= argv[2];
	local[9]= fqv[131];
	ctx->vsp=local+10;
	w=(pointer)F84(ctx,2,local+8); /*delimit-list*/
	local[8]= w;
	goto IF315;
IF314:
	local[8]= argv[2];
IF315:
	if (local[0]==NIL) goto IF316;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[46])(ctx,1,local+9,&ftab[46],fqv[132]); /*plusp*/
	if (w==NIL) goto IF316;
	local[9]= NIL;
	local[10]= fqv[133];
	w = local[0];
	if (!iscons(w)) goto IF318;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F85(ctx,1,local+11); /*where*/
	local[11]= w;
	goto IF319;
IF318:
	local[11]= local[0];
IF319:
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
	goto IF317;
IF316:
	local[9]= fqv[134];
IF317:
	if (local[3]==NIL) goto IF320;
	local[10]= NIL;
	local[11]= fqv[135];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= w;
	goto IF321;
IF320:
	local[10]= fqv[136];
IF321:
	if (local[1]==NIL) goto IF322;
	if (local[2]==NIL) goto IF324;
	local[11]= NIL;
	local[12]= fqv[137];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,4,local+11); /*format*/
	local[11]= w;
	goto IF325;
IF324:
	local[11]= NIL;
	local[12]= fqv[138];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
IF325:
	goto IF323;
IF322:
	local[11]= fqv[139];
IF323:
	ctx->vsp=local+12;
	w=(pointer)F82(ctx,8,local+4); /*query*/
	local[0]= w;
BLK307:
	ctx->vsp=local; return(local[0]);}

/*update-record*/
static pointer F87(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[140], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY327;
	local[0] = NIL;
KEY327:
	local[1]= NIL;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO328,env,argv,local);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= fqv[141];
	ctx->vsp=local+4;
	w=(pointer)F84(ctx,2,local+2); /*delimit-list*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[33];
	if (local[0]==NIL) goto IF329;
	local[4]= NIL;
	local[5]= fqv[142];
	local[6]= argv[1];
	local[7]= local[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)F85(ctx,1,local+8); /*where*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,5,local+4); /*format*/
	local[4]= w;
	goto IF330;
IF329:
	local[4]= NIL;
	local[5]= fqv[143];
	local[6]= argv[1];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,4,local+4); /*format*/
	local[4]= w;
IF330:
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK326:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO328(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[144];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF331;
	local[3]= NIL;
	local[4]= fqv[145];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto IF332;
IF331:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
IF332:
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*insert-record*/
static pointer F88(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[33];
	local[2]= NIL;
	local[3]= fqv[146];
	local[4]= argv[1];
	local[5]= (pointer)get_sym_func(fqv[147]);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	local[6]= fqv[148];
	ctx->vsp=local+7;
	w=(pointer)F84(ctx,2,local+5); /*delimit-list*/
	local[5]= w;
	local[6]= (pointer)get_sym_func(fqv[149]);
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= fqv[150];
	local[8]= T;
	ctx->vsp=local+9;
	w=(pointer)F84(ctx,3,local+6); /*delimit-list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,5,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK333:
	ctx->vsp=local; return(local[0]);}

/*insert-record2*/
static pointer F89(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[33];
	local[2]= NIL;
	local[3]= fqv[151];
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= fqv[152];
	ctx->vsp=local+7;
	w=(pointer)F84(ctx,2,local+5); /*delimit-list*/
	local[5]= w;
	local[6]= argv[3];
	local[7]= fqv[153];
	local[8]= T;
	ctx->vsp=local+9;
	w=(pointer)F84(ctx,3,local+6); /*delimit-list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,5,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK334:
	ctx->vsp=local; return(local[0]);}

/*delete-record*/
static pointer F90(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[154], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY336;
	local[0] = NIL;
KEY336:
	local[1]= argv[0];
	local[2]= fqv[33];
	if (local[0]==NIL) goto IF337;
	local[3]= NIL;
	local[4]= fqv[155];
	local[5]= argv[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F85(ctx,1,local+6); /*where*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	goto IF338;
IF337:
	local[3]= NIL;
	local[4]= fqv[156];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= w;
IF338:
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK335:
	ctx->vsp=local; return(local[0]);}

/*record-count*/
static pointer F91(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[157];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F86(ctx,3,local+0); /*select*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK339:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___pgsql(ctx,n,argv,env)
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
	local[0]= fqv[158];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	w = local[0];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[41],w);
	local[4]= fqv[64];
	local[5]= fqv[159];
	ctx->vsp=local+6;
	w=(*ftab[47])(ctx,2,local+4,&ftab[47],fqv[160]); /*require*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= fqv[161];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF340;
	local[0]= fqv[162];
	ctx->vsp=local+1;
	w=(*ftab[48])(ctx,1,local+0,&ftab[48],fqv[163]); /*make-package*/
	local[0]= w;
	goto IF341;
IF340:
	local[0]= NIL;
IF341:
	local[0]= fqv[164];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF342;
	local[0]= fqv[165];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[41],w);
	goto IF343;
IF342:
	local[0]= fqv[166];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF343:
	local[0]= fqv[167];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[168];
	ctx->vsp=local+1;
	w=(*ftab[49])(ctx,1,local+0,&ftab[49],fqv[169]); /*load*/
	local[0]= w;
	storeglobal(fqv[170],w);
	local[0]= fqv[11];
	local[1]= fqv[171];
	local[2]= fqv[172];
	local[3]= fqv[173];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[35];
	local[1]= fqv[175];
	local[2]= fqv[176];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[178];
	local[1]= fqv[179];
	local[2]= fqv[180];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[18];
	local[1]= fqv[181];
	local[2]= fqv[182];
	local[3]= fqv[183];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[19];
	local[1]= fqv[184];
	local[2]= fqv[185];
	local[3]= fqv[186];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[37];
	local[1]= fqv[187];
	local[2]= fqv[188];
	local[3]= fqv[189];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[16];
	local[1]= fqv[190];
	local[2]= fqv[191];
	local[3]= fqv[192];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[17];
	local[1]= fqv[193];
	local[2]= fqv[194];
	local[3]= fqv[195];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[196];
	local[1]= fqv[197];
	local[2]= fqv[198];
	local[3]= fqv[199];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[200];
	local[1]= fqv[201];
	local[2]= fqv[202];
	local[3]= fqv[203];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[12];
	local[1]= fqv[204];
	local[2]= fqv[205];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[22];
	local[1]= fqv[206];
	local[2]= fqv[207];
	local[3]= fqv[208];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[209];
	local[1]= fqv[210];
	local[2]= fqv[211];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[87];
	local[1]= fqv[212];
	local[2]= fqv[213];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[70];
	local[1]= fqv[214];
	local[2]= fqv[172];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[215];
	local[1]= fqv[216];
	local[2]= fqv[217];
	local[3]= fqv[218];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[56];
	local[1]= fqv[219];
	local[2]= fqv[220];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[54];
	local[1]= fqv[221];
	local[2]= fqv[222];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[223];
	local[1]= fqv[224];
	local[2]= fqv[225];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[55];
	local[1]= fqv[226];
	local[2]= fqv[227];
	local[3]= fqv[228];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[229];
	local[1]= fqv[230];
	local[2]= fqv[231];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[59];
	local[1]= fqv[232];
	local[2]= fqv[233];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[234];
	local[1]= fqv[235];
	local[2]= fqv[236];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[237];
	local[1]= fqv[238];
	local[2]= fqv[239];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[60];
	local[1]= fqv[240];
	local[2]= fqv[241];
	local[3]= fqv[242];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[243];
	local[1]= fqv[244];
	local[2]= fqv[245];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[246];
	local[1]= fqv[247];
	local[2]= fqv[248];
	local[3]= fqv[249];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[75];
	local[1]= fqv[250];
	local[2]= fqv[172];
	local[3]= fqv[251];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[69];
	local[1]= fqv[252];
	local[2]= fqv[172];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[46];
	local[1]= fqv[253];
	local[2]= fqv[254];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[51];
	local[1]= fqv[255];
	local[2]= fqv[256];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[47];
	local[1]= fqv[257];
	local[2]= fqv[258];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[48];
	local[1]= fqv[259];
	local[2]= fqv[260];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[29];
	local[1]= fqv[261];
	local[2]= fqv[262];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[88];
	local[1]= fqv[263];
	local[2]= fqv[264];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[90];
	local[1]= fqv[265];
	local[2]= fqv[266];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[93];
	local[1]= fqv[267];
	local[2]= fqv[268];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[95];
	local[1]= fqv[269];
	local[2]= fqv[270];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[96];
	local[1]= fqv[271];
	local[2]= fqv[272];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[97];
	local[1]= fqv[273];
	local[2]= fqv[274];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[98];
	local[1]= fqv[275];
	local[2]= fqv[276];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[99];
	local[1]= fqv[277];
	local[2]= fqv[278];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[100];
	local[1]= fqv[279];
	local[2]= fqv[280];
	local[3]= fqv[177];
	local[4]= loadglobal(fqv[170]);
	ctx->vsp=local+5;
	w=(*ftab[50])(ctx,4,local+1,&ftab[50],fqv[174]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[281];
	local[1]= fqv[282];
	local[2]= makeint(131072);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[283];
	local[1]= fqv[282];
	local[2]= makeint(262144);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[284];
	local[1]= fqv[282];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[285];
	local[1]= fqv[282];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[286];
	local[1]= fqv[282];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[2];
	local[1]= fqv[287];
	ctx->vsp=local+2;
	w=(*ftab[51])(ctx,0,local+2,&ftab[51],fqv[288]); /*copy-readtable*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint(123);
	local[1]= makeint(40);
	local[2]= loadglobal(fqv[2]);
	ctx->vsp=local+3;
	w=(*ftab[52])(ctx,3,local+0,&ftab[52],fqv[289]); /*set-syntax-from-char*/
	local[0]= makeint(125);
	local[1]= makeint(41);
	local[2]= loadglobal(fqv[2]);
	ctx->vsp=local+3;
	w=(*ftab[52])(ctx,3,local+0,&ftab[52],fqv[289]); /*set-syntax-from-char*/
	local[0]= makeint(44);
	local[1]= makeint(32);
	local[2]= loadglobal(fqv[2]);
	ctx->vsp=local+3;
	w=(*ftab[52])(ctx,3,local+0,&ftab[52],fqv[289]); /*set-syntax-from-char*/
	local[0]= fqv[117];
	local[1]= fqv[290];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF344;
	local[0]= fqv[117];
	local[1]= fqv[290];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[117];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF346;
	local[0]= fqv[117];
	local[1]= fqv[287];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF347;
IF346:
	local[0]= NIL;
IF347:
	local[0]= fqv[117];
	goto IF345;
IF344:
	local[0]= NIL;
IF345:
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F76,fqv[291]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[292],module,F77,fqv[293]);
	local[0]= fqv[294];
	local[1]= fqv[287];
	local[2]= fqv[294];
	local[3]= fqv[295];
	local[4]= loadglobal(fqv[296]);
	local[5]= fqv[297];
	local[6]= fqv[298];
	local[7]= fqv[299];
	local[8]= NIL;
	local[9]= fqv[300];
	local[10]= NIL;
	local[11]= fqv[27];
	local[12]= makeint(-1);
	local[13]= fqv[301];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[53])(ctx,13,local+2,&ftab[53],fqv[302]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M94,fqv[26],fqv[294],fqv[303]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M115,fqv[304],fqv[294],fqv[305]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M117,fqv[306],fqv[294],fqv[307]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M119,fqv[308],fqv[294],fqv[309]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M121,fqv[310],fqv[294],fqv[311]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M123,fqv[312],fqv[294],fqv[313]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M125,fqv[314],fqv[294],fqv[315]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M127,fqv[316],fqv[294],fqv[317]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M129,fqv[318],fqv[294],fqv[319]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M131,fqv[320],fqv[294],fqv[321]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M133,fqv[28],fqv[294],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M145,fqv[58],fqv[294],fqv[323]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M151,fqv[324],fqv[294],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M153,fqv[326],fqv[294],fqv[327]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M155,fqv[38],fqv[294],fqv[328]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M157,fqv[329],fqv[294],fqv[330]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M160,fqv[118],fqv[294],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M163,fqv[1],fqv[294],fqv[332]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M169,fqv[68],fqv[294],fqv[333]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M175,fqv[334],fqv[294],fqv[335]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M177,fqv[336],fqv[294],fqv[337]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M179,fqv[77],fqv[294],fqv[338]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M208,fqv[50],fqv[294],fqv[339]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M227,fqv[33],fqv[294],fqv[340]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M229,fqv[341],fqv[294],fqv[342]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M233,fqv[343],fqv[294],fqv[344]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M235,fqv[345],fqv[294],fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M237,fqv[347],fqv[294],fqv[348]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M241,fqv[349],fqv[294],fqv[350]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M245,fqv[351],fqv[294],fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M247,fqv[353],fqv[294],fqv[354]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M251,fqv[355],fqv[294],fqv[356]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M253,fqv[357],fqv[294],fqv[358]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M255,fqv[359],fqv[294],fqv[360]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M260,fqv[361],fqv[294],fqv[362]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M267,fqv[363],fqv[294],fqv[364]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[365],module,F78,fqv[366]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[367],module,F79,fqv[368]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[369],module,F80,fqv[370]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[371],module,F81,fqv[372]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[373],module,F82,fqv[374]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[375],module,F83,fqv[376]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[377],module,F84,fqv[378]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[126],module,F85,fqv[379]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[380],module,F86,fqv[381]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[382],module,F87,fqv[383]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[384],module,F88,fqv[385]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[386],module,F89,fqv[387]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[388],module,F90,fqv[389]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[390],module,F91,fqv[391]);
	local[0]= fqv[392];
	local[1]= fqv[393];
	ctx->vsp=local+2;
	w=(*ftab[54])(ctx,2,local+0,&ftab[54],fqv[394]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<55; i++) ftab[i]=fcallx;
}
