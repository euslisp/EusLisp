/* xor.c :  entry=xor */
/* compiled by EusLisp 8.16 for SunOS 4.1  created on Wed Jul 3 22:33:58 JST 1996 */
#include "eus.h"
#include "xor.h"
#pragma init (register_xor)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___xor();
extern pointer build_quote_vector();
static register_xor()
  { add_module_initializer("___xor", ___xor);}

static pointer F142();
static pointer F143();
static pointer F144();
static pointer F145();
static pointer F146();
static pointer F147();
static pointer F148();

/*init-xor-net*/
static pointer F142(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	local[1]= makeflt(-5.00000000e-01);
	local[2]= makeflt(5.00000000e-01);
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[2]); /*init-layer*/
	local[0]= fqv[3];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	local[1]= makeflt(-5.00000000e-01);
	local[2]= makeflt(5.00000000e-01);
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[2]); /*init-layer*/
	local[0]= fqv[4];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[5]); /*get-link-by-name*/
	local[0]= w;
	local[1]= makeflt(-1.00000000e+00);
	local[2]= makeflt(1.00000000e+00);
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[6]); /*init-link*/
	local[0]= fqv[7];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[5]); /*get-link-by-name*/
	local[0]= w;
	local[1]= makeflt(-1.00000000e+00);
	local[2]= makeflt(1.00000000e+00);
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[6]); /*init-link*/
	local[0]= w;
blk149:
	ctx->vsp=local; return(local[0]);}

/*fp-xor-net*/
static pointer F143(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[8];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w->c.obj.iv[4];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[9]); /*v=*/
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[10]); /*f-propagate-sigmoid-layer*/
	local[0]= fqv[3];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[10]); /*f-propagate-sigmoid-layer*/
	local[0]= fqv[3];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	w = w->c.obj.iv[4];
	local[0]= w;
blk150:
	ctx->vsp=local; return(local[0]);}

/*bp-xor-net*/
static pointer F144(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[3];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[11]); /*b-propagate-sigmoid-output-layer*/
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[12]); /*b-propagate-sigmoid-hidden-layer*/
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,3,local+0,&ftab[8],fqv[13]); /*learn-layer*/
	local[0]= fqv[3];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,3,local+0,&ftab[8],fqv[13]); /*learn-layer*/
	local[0]= fqv[14];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[5]); /*get-link-by-name*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,3,local+0,&ftab[9],fqv[15]); /*learn-link*/
	local[0]= fqv[16];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[5]); /*get-link-by-name*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,3,local+0,&ftab[9],fqv[15]); /*learn-link*/
	local[0]= w;
blk151:
	ctx->vsp=local; return(local[0]);}

/*fbp-xor-net*/
static pointer F145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F143(ctx,2,local+0); /*fp-xor-net*/
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F144(ctx,2,local+0); /*bp-xor-net*/
	local[0]= w;
blk152:
	ctx->vsp=local; return(local[0]);}

/*cycle-fbp-xor-net*/
static pointer F146(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent156;}
	local[0]= NIL;
ent156:
	if (n>=3) { local[1]=(argv[2]); goto ent155;}
	local[1]= loadglobal(fqv[17]);
ent155:
ent154:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= local[1];
whl158:
	if (local[3]==NIL) goto whx159;
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
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)F145(ctx,3,local+4); /*fbp-xor-net*/
	if (local[0]!=NIL) goto if162;
	local[4]= T;
	local[5]= fqv[18];
	local[6]= fqv[8];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,2,local+6,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[6]= w->c.obj.iv[4];
	local[7]= fqv[3];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,2,local+7,&ftab[0],fqv[1]); /*get-layer-by-name*/
	local[7]= w->c.obj.iv[4];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,5,local+4); /*format*/
	local[4]= w;
	goto if163;
if162:
	local[4]= NIL;
if163:
	goto whl158;
whx159:
	local[4]= NIL;
blk160:
	w = NIL;
	local[0]= w;
blk153:
	ctx->vsp=local; return(local[0]);}

/*loop-fbp-xor-net*/
static pointer F147(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ent167;}
	local[0]= NIL;
ent167:
	if (n>=4) { local[1]=(argv[3]); goto ent166;}
	local[1]= loadglobal(fqv[17]);
ent166:
ent165:
	if (n>4) maerror();
	local[2]= makeint(0);
	local[3]= argv[1];
whl169:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto whx170;
	if (local[0]==NIL) goto or174;
	w = local[0];
	if (!isnum(w)) goto and175;
	local[4]= (pointer)((integer_t)(local[2])+4);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,1,local+4,&ftab[10],fqv[19]); /*zerop*/
	if (w==NIL) goto and175;
	goto or174;
and175:
	goto con173;
or174:
	local[4]= T;
	local[5]= fqv[20];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)F146(ctx,3,local+4); /*cycle-fbp-xor-net*/
	local[4]= w;
	goto con172;
con173:
	local[4]= argv[0];
	local[5]= T;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)F146(ctx,3,local+4); /*cycle-fbp-xor-net*/
	local[4]= w;
	goto con172;
con176:
	local[4]= NIL;
con172:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto whl169;
whx170:
	local[4]= NIL;
blk171:
	w = NIL;
	local[0]= w;
blk164:
	ctx->vsp=local; return(local[0]);}

/*foo*/
static pointer F148(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ent180;}
	local[0]= loadglobal(fqv[21]);
ent180:
	if (n>=2) { local[1]=(argv[1]); goto ent179;}
	local[1]= makeint(10000);
ent179:
ent178:
	if (n>2) maerror();
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F142(ctx,1,local+2); /*init-xor-net*/
	local[2]= local[0];
	local[3]= makeint(10000);
	local[4]= makeint(1000);
	ctx->vsp=local+5;
	w=(pointer)F147(ctx,3,local+2); /*loop-fbp-xor-net*/
	local[0]= w;
blk177:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___xor(ctx,n,argv,env)
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
	local[0]= fqv[22];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto if181;
	local[0]= fqv[22];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[23],w);
	goto if182;
if181:
	local[0]= fqv[24];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
if182:
	local[0]= fqv[21];
	local[1]= fqv[25];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[21];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if183;
	local[0]= fqv[21];
	local[1]= fqv[26];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto if184;
if183:
	local[0]= NIL;
if184:
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[28]); /*construct-layered-network*/
	local[0]= w;
	storeglobal(fqv[21],w);
	local[0]= fqv[17];
	local[1]= fqv[25];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[17];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if185;
	local[0]= fqv[17];
	local[1]= fqv[26];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto if186;
if185:
	local[0]= NIL;
if186:
	local[0]= fqv[29];
	storeglobal(fqv[17],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F142,fqv[31]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F143,fqv[33]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[34],module,F144,fqv[35]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[36],module,F145,fqv[37]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[38],module,F146,fqv[39]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[40],module,F147,fqv[41]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F148,fqv[43]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<12; i++) ftab[i]=fcallx;
}
