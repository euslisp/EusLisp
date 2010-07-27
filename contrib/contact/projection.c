/* projection.c :  entry=projection */
/* compiled by EusLisp 8.16 for Solaris2  created on Fri Oct 4 14:23:40 JST 1996 */
#include "eus.h"
#include "projection.h"
#pragma init (register_projection)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___projection();
extern pointer build_quote_vector();
static register_projection()
  { add_module_initializer("___projection", ___projection);}

static pointer F59();
static pointer F60();
static pointer F61();
static pointer F62();
static pointer F63();
static pointer F64();
static pointer F65();

/*eqmotion*/
static pointer F59(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORM(ctx,1,local+0); /*norm*/
	local[0]= w;
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
blk66:
	ctx->vsp=local; return(local[0]);}

/*norm-difv*/
static pointer F60(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(0.00000000e+00);
	local[1]= makeflt(2.00000000e+04);
	local[2]= makeflt(2.00000000e+01);
	local[3]= makeint(0);
	local[4]= makeint(3);
whl69:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto whx70;
	local[5]= local[0];
	local[6]= argv[0];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[0] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto whl69;
whx70:
	local[5]= NIL;
blk71:
	w = NIL;
	local[3]= makeint(0);
	local[4]= makeint(3);
whl73:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto whx74;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= argv[0];
	local[8]= local[3];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[8]= (pointer)((integer_t)local[8] + (integer_t)w);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= local[3];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9]= (pointer)((integer_t)local[9] + (integer_t)w);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[0] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto whl73;
whx74:
	local[5]= NIL;
blk75:
	w = NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SQRT(ctx,1,local+3); /*sqrt*/
	local[0] = w;
	local[3]= makeint(1);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0] = w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[0]= w;
blk67:
	ctx->vsp=local; return(local[0]);}

/*make-jacobian-world-pos*/
static pointer F61(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(3);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[1]); /*unit-matrix*/
	local[0]= w;
	local[1]= makeint(6);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[1]); /*unit-matrix*/
	local[1]= w;
	local[2]= loadglobal(fqv[2]);
	local[3]= makeint(0);
	local[4]= makeint(3);
whl78:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto whx79;
	local[5]= *(ovafptr(local[1],fqv[3]));
	local[6]= local[2];
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[4]); /*matrix-column*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+7); /*v**/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[6]= w;
	local[7]= fqv[5];
	local[8]= local[3];
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[8]= (pointer)((integer_t)local[8] + (integer_t)w);
	local[9]= fqv[6];
	local[10]= local[3];
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[10]);
		local[10]=(makeint(i * j));}
	w = makeint(6);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[10]= (pointer)((integer_t)local[10] + (integer_t)w);
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,6,local+5,&ftab[2],fqv[7]); /*replace*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto whl78;
whx79:
	local[5]= NIL;
blk80:
	w = NIL;
	local[3]= local[1];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[8]); /*matrix-row*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[8]); /*matrix-row*/
	local[4]= w;
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,2,local+5,&ftab[3],fqv[8]); /*matrix-row*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,3,local+3,&ftab[4],fqv[9]); /*matrix*/
	local[0]= w;
blk76:
	ctx->vsp=local; return(local[0]);}

/*make-jacobian-world*/
static pointer F62(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(3);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[1]); /*unit-matrix*/
	local[0]= w;
	local[1]= makeint(6);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[1]); /*unit-matrix*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= makeint(3);
whl83:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto whx84;
	local[4]= *(ovafptr(local[1],fqv[3]));
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,2,local+6,&ftab[1],fqv[4]); /*matrix-column*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	local[6]= fqv[5];
	local[7]= local[2];
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[7]= (pointer)((integer_t)local[7] + (integer_t)w);
	local[8]= fqv[6];
	local[9]= local[2];
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[9]);
		local[9]=(makeint(i * j));}
	w = makeint(6);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9]= (pointer)((integer_t)local[9] + (integer_t)w);
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,6,local+4,&ftab[2],fqv[7]); /*replace*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto whl83;
whx84:
	local[4]= NIL;
blk85:
	w = NIL;
	w = local[1];
	local[0]= w;
blk81:
	ctx->vsp=local; return(local[0]);}

/*make-inequalities*/
static pointer F63(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
whl88:
	if (local[3]==NIL) goto whx89;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2]->c.obj.iv[2];
whl93:
	if (local[5]==NIL) goto whx94;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= local[4]->c.obj.iv[4];
whl98:
	if (local[7]==NIL) goto whx99;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[6];
whl103:
	if (local[9]==NIL) goto whx104;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	if (local[8]==NIL) goto if107;
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,1,local+10,&ftab[4],fqv[9]); /*matrix*/
	local[10]= w;
	local[11]= local[4]->c.obj.iv[0];
	ctx->vsp=local+12;
	w=(pointer)F61(ctx,1,local+11); /*make-jacobian-world-pos*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,2,local+10); /*m**/
	local[10]= w->c.obj.iv[1];
	w = local[1];
	ctx->vsp=local+11;
	local[1] = cons(ctx,local[10],w);
	local[10]= local[1];
	goto if108;
if107:
	w = NIL;
	ctx->vsp=local+10;
	local[0]=w;
	goto blk86;
if108:
	goto whl103;
whx104:
	local[10]= NIL;
blk105:
	w = NIL;
	local[8]= local[1];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[1] = NIL;
	goto whl98;
whx99:
	local[8]= NIL;
blk100:
	w = NIL;
	goto whl93;
whx94:
	local[6]= NIL;
blk95:
	w = NIL;
	goto whl88;
whx89:
	local[4]= NIL;
blk90:
	w = NIL;
	w = local[0];
	local[0]= w;
blk86:
	ctx->vsp=local; return(local[0]);}

/*find-projection*/
static pointer F64(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= loadglobal(fqv[10]);
	local[5]= loadglobal(fqv[11]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	if (argv[1]!=NIL) goto if110;
	w = argv[0];
	ctx->vsp=local+5;
	local[0]=w;
	goto blk109;
	goto if111;
if110:
	local[5]= NIL;
if111:
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[0] = w;
	local[5]= local[0];
	local[6]= makeint(32);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto if112;
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)PRINT(ctx,1,local+5); /*print*/
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,6,local+5); /*float-vector*/
	ctx->vsp=local+5;
	local[0]=w;
	goto blk109;
	goto if113;
if112:
	local[5]= NIL;
if113:
	local[5]= makeint(0);
	local[6]= local[0];
whl115:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto whx116;
	local[7]= argv[1];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	w = makeint(1);
	if ((integer_t)local[7] <= (integer_t)w) goto if118;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)COPYSEQ(ctx,1,local+7); /*copy-seq*/
	local[1] = w;
	local[7]= argv[1];
	local[8]= local[5];
	local[9]= argv[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[1];
	local[8]= local[5];
	local[9]= local[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= argv[0];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)F64(ctx,2,local+7); /*find-projection*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F64(ctx,2,local+8); /*find-projection*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	local[0]=w;
	goto blk109;
	goto if119;
if118:
	local[7]= NIL;
if119:
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto whl115;
whx116:
	local[7]= NIL;
blk117:
	w = NIL;
	local[5]= (pointer)get_sym_func(fqv[13]);
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	argv[1] = w;
	local[5]= (pointer)get_sym_func(fqv[9]);
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	argv[1] = w;
	local[5]= *(ovafptr(argv[1],fqv[3]));
	local[6]= local[0];
	local[7]= argv[0];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,4,local+5,&ftab[5],fqv[14]); /*projection*/
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[0]= w;
blk109:
	ctx->vsp=local; return(local[0]);}

/*possible-motion*/
static pointer F65(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,6,local+1); /*float-vector*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F63(ctx,1,local+3); /*make-inequalities*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F64(ctx,2,local+2); /*find-projection*/
	local[0] = w;
	local[2]= NIL;
	local[3]= local[0];
whl122:
	if (local[3]==NIL) goto whx123;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VNORM(ctx,1,local+4); /*norm*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	{ double left,right;
		right=fltval(w); left=fltval(local[4]);
	if (left >= right) goto if126;}
	local[1] = local[2];
	local[4]= local[1];
	goto if127;
if126:
	local[4]= NIL;
if127:
	goto whl122;
whx123:
	local[4]= NIL;
blk124:
	w = NIL;
	w = local[1];
	local[0]= w;
blk120:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___projection(ctx,n,argv,env)
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
	local[0]= fqv[15];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto if128;
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[17],w);
	goto if129;
if128:
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
if129:
	local[0]= fqv[19];
	local[1]= fqv[20];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[21]); /*require*/
	local[0]= T;
	local[1]= fqv[22];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[11];
	local[1]= fqv[24];
	local[2]= makeint(6);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[25];
	local[1]= fqv[24];
	local[2]= makeint(100);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[0];
	local[1]= fqv[24];
	local[2]= makeflt(9.99999940e-02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[2];
	local[1]= fqv[24];
	local[2]= makeflt(9.99999698e-04);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[26],module,F59,fqv[27]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[28],module,F60,fqv[29]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F61,fqv[31]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F62,fqv[33]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[34],module,F63,fqv[35]);
	local[0]= fqv[36];
	local[1]= fqv[24];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[38]); /*load-foreign*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[14];
	local[1]= fqv[39];
	local[2]= fqv[40];
	local[3]= fqv[41];
	local[4]= loadglobal(fqv[36]);
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,4,local+1,&ftab[8],fqv[42]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[43],module,F64,fqv[44]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[45],module,F65,fqv[46]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<9; i++) ftab[i]=fcallx;
}
