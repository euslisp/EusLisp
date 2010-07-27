/* inequalities.c :  entry=inequalities */
/* compiled by EusLisp 8.16 for Solaris2  created on Fri Oct 4 14:23:40 JST 1996 */
#include "eus.h"
#include "inequalities.h"
#pragma init (register_inequalities)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___inequalities();
extern pointer build_quote_vector();
static register_inequalities()
  { add_module_initializer("___inequalities", ___inequalities);}

static pointer F468();
static pointer F469();
static pointer F470();
static pointer F471();
static pointer F472();
static pointer F473();
static pointer F474();
static pointer F475();

/*eqmotion*/
static pointer F468(ctx,n,argv,env)
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
blk476:
	ctx->vsp=local; return(local[0]);}

/*norm-difv*/
static pointer F469(ctx,n,argv,env)
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
whl479:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto whx480;
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
	goto whl479;
whx480:
	local[5]= NIL;
blk481:
	w = NIL;
	local[3]= makeint(0);
	local[4]= makeint(3);
whl483:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto whx484;
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
	goto whl483;
whx484:
	local[5]= NIL;
blk485:
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
blk477:
	ctx->vsp=local; return(local[0]);}

/*make-jacobian-world-pos*/
static pointer F470(ctx,n,argv,env)
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
whl488:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto whx489;
	local[4]= *(ovafptr(local[1],fqv[2]));
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,2,local+6,&ftab[1],fqv[3]); /*matrix-column*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	local[6]= fqv[4];
	local[7]= local[2];
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[7]= (pointer)((integer_t)local[7] + (integer_t)w);
	local[8]= fqv[5];
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
	w=(*ftab[2])(ctx,6,local+4,&ftab[2],fqv[6]); /*replace*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto whl488;
whx489:
	local[4]= NIL;
blk490:
	w = NIL;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[7]); /*matrix-row*/
	local[2]= w;
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[7]); /*matrix-row*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[7]); /*matrix-row*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,3,local+2,&ftab[4],fqv[8]); /*matrix*/
	local[0]= w;
blk486:
	ctx->vsp=local; return(local[0]);}

/*make-jacobian-world*/
static pointer F471(ctx,n,argv,env)
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
whl493:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto whx494;
	local[4]= *(ovafptr(local[1],fqv[2]));
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,2,local+6,&ftab[1],fqv[3]); /*matrix-column*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	local[6]= fqv[4];
	local[7]= local[2];
	{ integer_t i,j;
		j=intval(makeint(6)); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[7]= (pointer)((integer_t)local[7] + (integer_t)w);
	local[8]= fqv[5];
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
	w=(*ftab[2])(ctx,6,local+4,&ftab[2],fqv[6]); /*replace*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto whl493;
whx494:
	local[4]= NIL;
blk495:
	w = NIL;
	w = local[1];
	local[0]= w;
blk491:
	ctx->vsp=local; return(local[0]);}

/*make-inequalities*/
static pointer F472(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
whl498:
	if (local[3]==NIL) goto whx499;
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
whl503:
	if (local[5]==NIL) goto whx504;
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
whl508:
	if (local[7]==NIL) goto whx509;
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
whl513:
	if (local[9]==NIL) goto whx514;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	if (local[8]==NIL) goto if517;
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,1,local+10,&ftab[4],fqv[8]); /*matrix*/
	local[10]= w;
	local[11]= local[4]->c.obj.iv[0];
	ctx->vsp=local+12;
	w=(pointer)F470(ctx,1,local+11); /*make-jacobian-world-pos*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,2,local+10); /*m**/
	local[10]= w->c.obj.iv[1];
	w = local[1];
	ctx->vsp=local+11;
	local[1] = cons(ctx,local[10],w);
	local[10]= local[1];
	goto if518;
if517:
	w = NIL;
	ctx->vsp=local+10;
	local[0]=w;
	goto blk496;
if518:
	goto whl513;
whx514:
	local[10]= NIL;
blk515:
	w = NIL;
	local[8]= local[1];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[1] = NIL;
	goto whl508;
whx509:
	local[8]= NIL;
blk510:
	w = NIL;
	goto whl503;
whx504:
	local[6]= NIL;
blk505:
	w = NIL;
	goto whl498;
whx499:
	local[4]= NIL;
blk500:
	w = NIL;
	w = local[0];
	local[0]= w;
blk496:
	ctx->vsp=local; return(local[0]);}

/*solve-inequalities*/
static pointer F473(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= loadglobal(fqv[9]);
	local[3]= loadglobal(fqv[10]);
	local[4]= loadglobal(fqv[11]);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	if (argv[0]!=NIL) goto if520;
	local[6]= fqv[12];
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto blk519;
	goto if521;
if520:
	local[6]= NIL;
if521:
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[0] = w;
	local[6]= local[0];
	local[7]= makeint(32);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto if522;
	local[6]= fqv[13];
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto blk519;
	goto if523;
if522:
	local[6]= NIL;
if523:
	local[6]= makeint(0);
	local[7]= local[0];
whl525:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto whx526;
	local[8]= argv[0];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	w = makeint(1);
	if ((integer_t)local[8] <= (integer_t)w) goto if528;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	local[1] = w;
	local[8]= argv[0];
	local[9]= local[6];
	local[10]= argv[0];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SETELT(ctx,3,local+8); /*setelt*/
	local[8]= local[1];
	local[9]= local[6];
	local[10]= local[1];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w=(pointer)SETELT(ctx,3,local+8); /*setelt*/
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)F473(ctx,1,local+8); /*solve-inequalities*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F473(ctx,1,local+9); /*solve-inequalities*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	ctx->vsp=local+8;
	local[0]=w;
	goto blk519;
	goto if529;
if528:
	local[8]= NIL;
if529:
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto whl525;
whx526:
	local[8]= NIL;
blk527:
	w = NIL;
	local[6]= (pointer)get_sym_func(fqv[14]);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	argv[0] = w;
	local[6]= (pointer)get_sym_func(fqv[8]);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	argv[0] = w;
	local[6]= *(ovafptr(argv[0],fqv[2]));
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,3,local+6,&ftab[5],fqv[15]); /*solve-cone*/
	local[3] = w;
	local[6]= makeint(0);
	local[7]= local[3];
whl531:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto whx532;
	local[8]= local[2];
	local[9]= loadglobal(fqv[10]);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= loadglobal(fqv[10]);
	local[11]= local[6];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[11]= (pointer)((integer_t)local[11] + (integer_t)w);
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F469(ctx,1,local+8); /*norm-difv*/
	local[8]= w;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto whl531;
whx532:
	local[8]= NIL;
blk533:
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[0]= w;
blk519:
	ctx->vsp=local; return(local[0]);}

/*constrained-motion*/
static pointer F474(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F472(ctx,1,local+0); /*make-inequalities*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F473(ctx,1,local+0); /*solve-inequalities*/
	local[0]= w;
blk534:
	ctx->vsp=local; return(local[0]);}

/*constrained-force*/
static pointer F475(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= loadglobal(fqv[9]);
	local[4]= loadglobal(fqv[10]);
	local[5]= loadglobal(fqv[11]);
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= NIL;
	if (argv[0]!=NIL) goto if536;
	local[5]= fqv[16];
	ctx->vsp=local+6;
	w=(pointer)PRINT(ctx,1,local+5); /*print*/
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto blk535;
	goto if537;
if536:
	local[5]= NIL;
if537:
	local[5]= NIL;
	local[6]= argv[0];
whl539:
	if (local[6]==NIL) goto whx540;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= NIL;
	local[8]= local[5];
whl544:
	if (local[8]==NIL) goto whx545;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= makeflt(-1.00000000e+00);
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	local[10]= local[0];
	local[11]= fqv[17];
	local[12]= (pointer)get_sym_func(fqv[18]);
	local[13]= fqv[19];
	local[14]= NIL;
	local[15]= fqv[20];
	local[16]= NIL;
	ctx->vsp=local+17;
	w=(*ftab[6])(ctx,8,local+9,&ftab[6],fqv[21]); /*member*/
	if (w!=NIL) goto if548;
	local[9]= makeflt(-1.00000000e+00);
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	w = local[0];
	ctx->vsp=local+10;
	local[0] = cons(ctx,local[9],w);
	local[9]= local[0];
	goto if549;
if548:
	local[9]= NIL;
if549:
	goto whl544;
whx545:
	local[9]= NIL;
blk546:
	w = NIL;
	goto whl539;
whx540:
	local[7]= NIL;
blk541:
	w = NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[2] = w;
	local[5]= (pointer)get_sym_func(fqv[8]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[0] = w;
	local[5]= *(ovafptr(local[0],fqv[2]));
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,3,local+5,&ftab[5],fqv[15]); /*solve-cone*/
	local[1] = w;
	local[5]= makeint(0);
	local[6]= local[1];
whl551:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto whx552;
	local[7]= local[3];
	local[8]= loadglobal(fqv[10]);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= loadglobal(fqv[10]);
	local[10]= (pointer)((integer_t)(local[5])+4);
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F469(ctx,1,local+7); /*norm-difv*/
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto whl551;
whx552:
	local[7]= NIL;
blk553:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[0]= w;
blk535:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___inequalities(ctx,n,argv,env)
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
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[23]); /*provide*/
	local[0]= fqv[24];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto if554;
	local[0]= fqv[25];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[26],w);
	goto if555;
if554:
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
if555:
	local[0]= fqv[28];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[30]); /*require*/
	local[0]= T;
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= fqv[32];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[10];
	local[1]= fqv[33];
	local[2]= makeint(6);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[11];
	local[1]= fqv[33];
	local[2]= makeint(100);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[0];
	local[1]= fqv[33];
	local[2]= makeflt(9.99999940e-02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[18],module,F468,fqv[34]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[35],module,F469,fqv[36]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F470,fqv[38]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[39],module,F471,fqv[40]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F472,fqv[42]);
	local[0]= fqv[43];
	local[1]= fqv[33];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[45]); /*load-foreign*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[15];
	local[1]= fqv[46];
	local[2]= fqv[47];
	local[3]= fqv[48];
	local[4]= loadglobal(fqv[43]);
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,4,local+1,&ftab[10],fqv[49]); /*make-foreign-code*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F473,fqv[51]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[52],module,F474,fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F475,fqv[55]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
