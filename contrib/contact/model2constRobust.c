/* model2constRobust.c :  entry=model2constRobust */
/* compiled by EusLisp 8.18 for Solaris2  created on Fri Jan 24 10:30:35 JST 1997 */
#include "eus.h"
#include "model2constRobust.h"
#pragma init (register_model2constRobust)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___model2constRobust();
extern pointer build_quote_vector();
static register_model2constRobust()
  { add_module_initializer("___model2constRobust", ___model2constRobust);}

static pointer F59();
static pointer F60();
static pointer F61();
static pointer F62();
static pointer F63();
static pointer F64();
static pointer F65();

/*:contact*/
static pointer M66(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[1]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORM(ctx,1,local+2); /*norm*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= loadglobal(fqv[1]);
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= local[0];
	if (fqv[2]==local[3]) goto if68;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= loadglobal(fqv[3]);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto if70;
	local[3]= local[1];
	local[4]= argv[0];
	local[5]= fqv[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto if70;
	local[3]= makeflt(-1.00000000e+00);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto if70;
	local[3]= local[0];
	goto if71;
if70:
	local[3]= NIL;
if71:
	goto if69;
if68:
	local[3]= NIL;
if69:
	w = local[3];
	local[0]= w;
blk67:
	ctx->vsp=local; return(local[0]);}

/*:separation*/
static pointer M72(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[3];
whl75:
	if (local[5]==NIL) goto whx76;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= loadglobal(fqv[3]);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto if79;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[6]); /*minusp*/
	if (w==NIL) goto if81;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto blk73;
	goto if82;
if81:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto if83;
	local[1] = local[0];
	local[6]= local[1];
	goto if84;
if83:
	local[6]= NIL;
if84:
if82:
	goto if80;
if79:
	local[6]= NIL;
if80:
	goto whl75;
whx76:
	local[6]= NIL;
blk77:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[4];
whl86:
	if (local[5]==NIL) goto whx87;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= loadglobal(fqv[3]);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto if90;
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[6]); /*minusp*/
	if (w==NIL) goto if92;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto blk73;
	goto if93;
if92:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto if94;
	local[2] = local[0];
	local[6]= local[2];
	goto if95;
if94:
	local[6]= NIL;
if95:
if93:
	goto if91;
if90:
	local[6]= NIL;
if91:
	goto whl86;
whx87:
	local[6]= NIL;
blk88:
	w = NIL;
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[6]); /*minusp*/
	if (w==NIL) goto if96;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[1] = w;
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[3] = w;
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[0] = w;
	local[4]= argv[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[0] = w;
	local[4]= makeflt(-1.00000000e+00);
	local[5]= loadglobal(fqv[3]);
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto if98;
	local[4]= local[0];
	local[5]= loadglobal(fqv[1]);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto if98;
	local[4]= local[3];
	goto if99;
if98:
	local[4]= NIL;
if99:
	goto if97;
if96:
	local[4]= NIL;
if97:
	w = local[4];
	local[0]= w;
blk73:
	ctx->vsp=local; return(local[0]);}

/*:eps-insidep*/
static pointer M100(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ent103;}
	local[0]= loadglobal(fqv[7]);
ent103:
ent102:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt(0.00000000e+00);
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	if (argv[0]->c.obj.iv[3]==NIL) goto con105;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[7]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
whl107:
	if (local[8]==NIL) goto whx108;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[2];
	local[10]= local[7];
	local[11]= argv[2];
	local[12]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,4,local+9,&ftab[1],fqv[8]); /*triangle*/
	local[5] = w;
	local[9]= local[5];
	local[10]= local[2];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)VDISTANCE(ctx,2,local+10); /*distance*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,2,local+9,&ftab[2],fqv[9]); /*eps-zero*/
	if (w==NIL) goto con112;
	local[9]= local[7];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	local[11]= local[9];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)VINNERPRODUCT(ctx,2,local+11); /*v.*/
	local[11]= w;
	local[12]= local[9];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)VINNERPRODUCT(ctx,2,local+12); /*v.*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[4] = w;
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[4];
	local[11]= makeflt(1.00000000e+00);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[3])(ctx,4,local+9,&ftab[3],fqv[10]); /*eps-in-range*/
	if (w==NIL) goto if113;
	w = fqv[11];
	ctx->vsp=local+9;
	local[0]=w;
	goto blk101;
	goto if114;
if113:
	local[9]= NIL;
if114:
	goto con111;
con112:
	local[9]= local[5];
	local[10]= local[2];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)VDISTANCE(ctx,2,local+10); /*distance*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeflt(-1.00000000e+00);
	local[11]= loadglobal(fqv[1]);
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto con115;
	w = fqv[12];
	ctx->vsp=local+9;
	local[0]=w;
	goto blk101;
	goto con111;
con115:
	local[9]= NIL;
con111:
	local[2] = local[7];
	goto whl107;
whx108:
	local[9]= NIL;
blk109:
	w = NIL;
	local[7]= fqv[13];
	goto con104;
con105:
	local[7]= argv[0];
	local[8]= fqv[14];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto if117;
	w = fqv[11];
	ctx->vsp=local+7;
	local[0]=w;
	goto blk101;
	goto if118;
if117:
	local[7]= NIL;
if118:
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo119,env,argv,local);
	local[8]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[2] = w;
whl121:
	if (local[6]==NIL) goto whx122;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[1] = w;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,3,local+7,&ftab[4],fqv[15]); /*vector-angle*/
	local[5] = w;
	local[7]= makeflt((double)fabs(fltval(local[5])));
	local[8]= makeflt(3.14159203e+00);
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,3,local+7,&ftab[5],fqv[16]); /*eps=*/
	if (w==NIL) goto if125;
	w = fqv[11];
	ctx->vsp=local+7;
	local[0]=w;
	goto blk101;
	goto if126;
if125:
	local[7]= NIL;
if126:
	local[7]= local[3];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[7]);
		local[7]=(makeflt(x + y));}
	local[3] = local[7];
	local[2] = local[1];
	goto whl121;
whx122:
	local[7]= NIL;
blk123:
	local[7]= makeflt((double)fabs(fltval(local[3])));
	local[8]= makeflt(3.14159203e+00);
	local[9]= loadglobal(fqv[1]);
	local[10]= makeflt(1.00000000e+02);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto if127;
	local[7]= fqv[13];
	goto if128;
if127:
	local[7]= fqv[12];
if128:
	goto con104;
con116:
	local[7]= NIL;
con104:
	w = local[7];
	local[0]= w;
blk101:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M129(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ent132;}
	local[0]= loadglobal(fqv[1]);
ent132:
ent131:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[17];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeflt(-1.00000000e+00);
	local[4]= loadglobal(fqv[3]);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w!=NIL) goto or135;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w!=NIL) goto or135;
	goto if133;
or135:
	local[2]= fqv[12];
	goto if134;
if133:
	local[2]= argv[0];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= local[1];
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeflt(1.00000000e+01);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
if134:
	w = local[2];
	local[0]= w;
blk130:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo119(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[19]); /*direction-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M136(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[0],fqv[20]));
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= loadglobal(fqv[21]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto if138;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto blk137;
	goto if139;
if138:
	local[1]= NIL;
if139:
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
whl141:
	if (local[2]==NIL) goto whx142;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[23];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto if145;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto blk137;
	goto if146;
if145:
	local[3]= NIL;
if146:
	goto whl141;
whx142:
	local[3]= NIL;
blk143:
	w = NIL;
	local[0]= w;
blk137:
	ctx->vsp=local; return(local[0]);}

/*:eps-insidep*/
static pointer M147(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ent150;}
	local[0]= loadglobal(fqv[7]);
ent150:
ent149:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[24]));
	local[3]= fqv[18];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,4,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[13]==local[2]) goto if151;
	local[2]= local[1];
	goto if152;
if151:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
whl154:
	if (local[3]==NIL) goto whx155;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[18];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[13]!=local[4]) goto if158;
	w = fqv[12];
	ctx->vsp=local+4;
	local[0]=w;
	goto blk148;
	goto if159;
if158:
	local[4]= local[1];
	if (fqv[11]!=local[4]) goto if160;
	w = fqv[11];
	ctx->vsp=local+4;
	local[0]=w;
	goto blk148;
	goto if161;
if160:
	local[4]= NIL;
if161:
if159:
	goto whl154;
whx155:
	local[4]= NIL;
blk156:
	w = NIL;
	local[2]= fqv[13];
if152:
	w = local[2];
	local[0]= w;
blk148:
	ctx->vsp=local; return(local[0]);}

/*:contact-vertices*/
static pointer M162(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[25];
	local[2]= argv[2];
	local[3]= fqv[26];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto if164;
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[28];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
whl167:
	if (local[7]==NIL) goto whx168;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[2];
whl172:
	if (local[9]==NIL) goto whx173;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[29];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	if (fqv[12]==local[10]) goto if176;
	local[10]= loadglobal(fqv[30]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[31];
	local[13]= fqv[32];
	local[14]= local[6];
	local[15]= fqv[33];
	local[16]= local[8];
	local[17]= fqv[34];
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	local[16]= w;
	local[17]= fqv[35];
	local[18]= local[8];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[3];
	ctx->vsp=local+11;
	local[3] = cons(ctx,local[10],w);
	w = local[3];
	ctx->vsp=local+10;
	local[10]=w;
	goto blk174;
	goto if177;
if176:
	local[10]= NIL;
if177:
	goto whl172;
whx173:
	local[10]= NIL;
blk174:
	w = NIL;
	goto whl167;
whx168:
	local[8]= NIL;
blk169:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
whl180:
	if (local[7]==NIL) goto whx181;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= argv[0]->c.obj.iv[10];
whl185:
	if (local[9]==NIL) goto whx186;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto or191;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto or191;
	goto if189;
or191:
	local[10]= local[8];
	w = local[6]->c.obj.iv[3];
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[10];
	w = local[6];
	w->c.obj.iv[3] = local[11];
	goto if190;
if189:
	local[10]= NIL;
if190:
	goto whl185;
whx186:
	local[10]= NIL;
blk187:
	w = NIL;
	goto whl180;
whx181:
	local[8]= NIL;
blk182:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
whl193:
	if (local[7]==NIL) goto whx194;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[36];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	goto whl193;
whx194:
	local[8]= NIL;
blk195:
	w = NIL;
	w = local[3];
	local[1]= w;
	goto if165;
if164:
	local[1]= NIL;
if165:
	w = local[1];
	local[0]= w;
blk163:
	ctx->vsp=local; return(local[0]);}

/*:contact-edges*/
static pointer M197(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[25];
	local[2]= argv[2];
	local[3]= fqv[26];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto if199;
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[28];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
whl202:
	if (local[7]==NIL) goto whx203;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[2];
whl207:
	if (local[9]==NIL) goto whx208;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[38];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto if211;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[4];
	local[12]= fqv[39];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,clo213,env,argv,local);
	ctx->vsp=local+14;
	w=(*ftab[7])(ctx,4,local+10,&ftab[7],fqv[40]); /*find*/
	if (w!=NIL) goto if211;
	local[10]= local[6]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(*ftab[8])(ctx,1,local+10,&ftab[8],fqv[41]); /*plusp*/
	if (w==NIL) goto if214;
	local[10]= loadglobal(fqv[30]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[31];
	local[13]= fqv[32];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[33];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[35];
	local[18]= local[8];
	local[19]= fqv[42];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,10,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
	goto if215;
if214:
	local[10]= loadglobal(fqv[30]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[31];
	local[13]= fqv[32];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[33];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[35];
	local[18]= local[8];
	local[19]= fqv[42];
	local[20]= local[6]->c.obj.iv[3];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[20]= w;
	local[21]= local[6]->c.obj.iv[4];
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,1,local+21); /*list*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,10,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
if215:
	goto if212;
if211:
	local[10]= NIL;
if212:
	goto whl207;
whx208:
	local[10]= NIL;
blk209:
	w = NIL;
	goto whl202;
whx203:
	local[8]= NIL;
blk204:
	w = NIL;
	w = local[4];
	local[1]= w;
	goto if200;
if199:
	local[1]= NIL;
if200:
	w = local[1];
	local[0]= w;
blk198:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo213(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1]->c.obj.iv[0];
	local[2]= loadglobal(fqv[1]);
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,3,local+0,&ftab[9],fqv[43]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eq-or-cond*/
static pointer F59(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[44]); /*float-vector-p*/
	if (w==NIL) goto if219;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[44]); /*float-vector-p*/
	if (w==NIL) goto if219;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[43]); /*eps-v=*/
	local[0]= w;
	goto if220;
if219:
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
if220:
	w = local[0];
	local[0]= w;
blk218:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M221(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[46], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto key223;
	local[0] = NIL;
key223:
	if (n & (1<<1)) goto key224;
	local[1] = NIL;
key224:
	if (n & (1<<2)) goto key225;
	local[2] = NIL;
key225:
	if (n & (1<<3)) goto key226;
	local[3] = NIL;
key226:
	if (n & (1<<4)) goto key227;
	local[4] = NIL;
key227:
	if (local[0]==NIL) goto if228;
	argv[0]->c.obj.iv[0] = local[0];
	local[5]= argv[0]->c.obj.iv[0];
	goto if229;
if228:
	local[5]= NIL;
if229:
	if (local[1]==NIL) goto if230;
	argv[0]->c.obj.iv[1] = local[1];
	local[5]= argv[0]->c.obj.iv[1];
	goto if231;
if230:
	local[5]= NIL;
if231:
	if (local[2]==NIL) goto if232;
	argv[0]->c.obj.iv[2] = local[2];
	local[5]= argv[0]->c.obj.iv[2];
	goto if233;
if232:
	local[5]= NIL;
if233:
	if (local[3]==NIL) goto if234;
	argv[0]->c.obj.iv[3] = local[3];
	local[5]= argv[0]->c.obj.iv[3];
	goto if235;
if234:
	local[5]= NIL;
if235:
	if (local[4]==NIL) goto if236;
	argv[0]->c.obj.iv[4] = local[4];
	local[5]= argv[0]->c.obj.iv[4];
	goto if237;
if236:
	local[5]= NIL;
if237:
	w = argv[0];
	local[0]= w;
blk222:
	ctx->vsp=local; return(local[0]);}

/*:to-convex*/
static pointer M238(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[3];
whl241:
	if (local[5]==NIL) goto whx242;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[6]); /*minusp*/
	if (w==NIL) goto if245;
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[1] = local[4];
	local[6]= local[1];
	goto if246;
if245:
	local[6]= NIL;
if246:
	goto whl241;
whx242:
	local[6]= NIL;
blk243:
	w = NIL;
	local[4]= local[0];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto con248;
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto con247;
con248:
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto con249;
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto con247;
con249:
	local[4]= local[0];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)GREQP(ctx,2,local+4); /*>=*/
	if (w==NIL) goto con250;
	local[4]= argv[0];
	local[5]= fqv[48];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto con247;
con250:
	local[4]= NIL;
con247:
	w = local[4];
	local[0]= w;
blk239:
	ctx->vsp=local; return(local[0]);}

/*:divide1*/
static pointer M251(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[3];
	local[1]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
whl253:
	if (local[0]==NIL) goto whx254;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[4]= argv[2];
	local[5]= argv[2];
	local[6]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,2,local+5,&ftab[11],fqv[49]); /*remove*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	local[7]= NIL;
	local[8]= NIL;
tag258:
	local[9]= loadglobal(fqv[7]);
	local[10]= local[1];
	local[11]= fqv[5];
	local[12]= local[4]->c.obj.iv[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w!=NIL) goto or261;
	local[9]= loadglobal(fqv[7]);
	local[10]= local[1];
	local[11]= fqv[5];
	local[12]= local[4]->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w!=NIL) goto or261;
	goto if259;
or261:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	local[9]= makeint(2);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	if ((integer_t)local[9] >= (integer_t)w) goto if262;
	local[9]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car->c.obj.iv[4];
whl265:
	if (local[10]==NIL) goto whx266;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9]->c.obj.iv[1];
	local[12]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+13;
	w=(pointer)EQUAL(ctx,2,local+11); /*equal*/
	if (w!=NIL) goto if269;
	local[11]= local[9]->c.obj.iv[2];
	local[12]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+13;
	w=(pointer)EQUAL(ctx,2,local+11); /*equal*/
	if (w!=NIL) goto if269;
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[9]->c.obj.iv[1];
	local[14]= local[9]->c.obj.iv[2];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[3] = w;
	local[11]= makeflt(0.00000000e+00);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto if271;
	local[11]= local[3];
	local[12]= makeflt(1.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto if271;
	local[11]= loadglobal(fqv[7]);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(*ftab[12])(ctx,1,local+12,&ftab[12],fqv[50]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[5];
	local[14]= local[9];
	local[15]= fqv[51];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto if273;
	local[11]= loadglobal(fqv[52]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[31];
	local[14]= fqv[53];
	local[15]= argv[0]->c.obj.iv[0];
	local[16]= fqv[54];
	local[17]= local[9];
	local[18]= fqv[51];
	local[19]= local[3];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[17]= w;
	local[18]= fqv[55];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[56];
	local[21]= local[1];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,10,local+12); /*send*/
	w = local[11];
	local[11]= w;
	w = local[7];
	ctx->vsp=local+12;
	local[7] = cons(ctx,local[11],w);
	local[11]= local[7];
	goto if274;
if273:
	local[11]= NIL;
if274:
	w = local[11];
	ctx->vsp=local+11;
	local[11]=w;
	goto blk267;
	goto if272;
if271:
	local[11]= NIL;
if272:
	goto if270;
if269:
	local[11]= NIL;
if270:
	goto whl265;
whx266:
	local[11]= NIL;
blk267:
	w = NIL;
	local[9]= w;
	goto if263;
if262:
	local[9]= NIL;
if263:
	local[9]= local[7];
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	w = local[2];
	ctx->vsp=local+9;
	local[4]=w;
	goto blk257;
	goto if260;
if259:
	local[9]= NIL;
if260:
	local[9]= NIL;
	local[10]= local[5];
whl277:
	if (local[10]==NIL) goto whx278;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[9]->c.obj.iv[3];
	ctx->vsp=local+13;
	w=(pointer)EQUAL(ctx,2,local+11); /*equal*/
	if (w==NIL) goto con282;
	local[8] = local[9]->c.obj.iv[4];
	local[11]= local[8];
	goto con281;
con282:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[9]->c.obj.iv[4];
	ctx->vsp=local+13;
	w=(pointer)EQUAL(ctx,2,local+11); /*equal*/
	if (w==NIL) goto con283;
	local[8] = local[9]->c.obj.iv[3];
	local[11]= local[8];
	goto con281;
con283:
	local[11]= NIL;
con281:
	if (local[8]==NIL) goto if284;
	local[11]= local[8];
	w = local[6];
	ctx->vsp=local+12;
	local[6] = cons(ctx,local[11],w);
	local[11]= local[9];
	w = local[7];
	ctx->vsp=local+12;
	local[7] = cons(ctx,local[11],w);
	local[4] = local[9];
	w = local[4];
	ctx->vsp=local+11;
	local[11]=w;
	goto blk279;
	goto if285;
if284:
	local[11]= NIL;
if285:
	goto whl277;
whx278:
	local[11]= NIL;
blk279:
	w = NIL;
	local[9]= local[4];
	local[10]= local[4];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[11])(ctx,2,local+10,&ftab[11],fqv[49]); /*remove*/
	local[10]= w;
	local[11]= local[6];
	local[12]= local[7];
	local[13]= NIL;
	local[4] = local[9];
	local[5] = local[10];
	local[6] = local[11];
	local[7] = local[12];
	local[8] = local[13];
	w = NIL;
	ctx->vsp=local+9;
	goto tag258;
	w = NIL;
	local[4]= w;
blk257:
	goto whl253;
whx254:
	local[4]= NIL;
blk255:
	argv[0]->c.obj.iv[3] = local[2];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
blk252:
	ctx->vsp=local; return(local[0]);}

/*:dividen*/
static pointer M291(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,2,local+4,&ftab[11],fqv[49]); /*remove*/
	local[4]= w;
	local[5]= argv[2]->c.obj.iv[3];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
tag295:
	if (local[4]!=NIL) goto if296;
	if (local[6]==NIL) goto if298;
	local[8]= local[6];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[8]= local[0];
	goto if299;
if298:
	local[8]= local[5];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[8]= local[0];
if299:
	w = local[0];
	ctx->vsp=local+8;
	local[4]=w;
	goto blk294;
	goto if297;
if296:
	local[8]= NIL;
if297:
	local[8]= NIL;
	local[9]= local[4];
whl301:
	if (local[9]==NIL) goto whx302;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[8]->c.obj.iv[3];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w==NIL) goto con306;
	local[7] = local[8]->c.obj.iv[4];
	local[10]= local[7];
	goto con305;
con306:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[8]->c.obj.iv[4];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w==NIL) goto con307;
	local[7] = local[8]->c.obj.iv[3];
	local[10]= local[7];
	goto con305;
con307:
	local[10]= NIL;
con305:
	if (local[7]==NIL) goto if308;
	local[10]= local[8]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(*ftab[8])(ctx,1,local+10,&ftab[8],fqv[41]); /*plusp*/
	if (w==NIL) goto con311;
	local[10]= local[7];
	w = local[5];
	ctx->vsp=local+11;
	local[5] = cons(ctx,local[10],w);
	local[10]= local[8];
	w = local[6];
	ctx->vsp=local+11;
	local[6] = cons(ctx,local[10],w);
	local[1] = local[8];
	w = local[1];
	ctx->vsp=local+10;
	local[10]=w;
	goto blk303;
	goto con310;
con311:
	if (local[6]==NIL) goto if313;
	local[10]= makeint(2);
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	if ((integer_t)local[10] >= (integer_t)w) goto if315;
	local[10]= argv[0]->c.obj.iv[0];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car->c.obj.iv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(*ftab[12])(ctx,1,local+12,&ftab[12],fqv[50]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+11); /*v**/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[2] = w;
	local[10]= NIL;
	local[11]= local[5];
whl318:
	if (local[11]==NIL) goto whx319;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[3];
	local[13]= local[10];
	local[14]= fqv[5];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[3] = w;
	goto whl318;
whx319:
	local[12]= NIL;
blk320:
	w = NIL;
	local[10]= loadglobal(fqv[52]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[31];
	local[13]= fqv[53];
	local[14]= argv[0]->c.obj.iv[0];
	local[15]= fqv[54];
	local[16]= local[3];
	local[17]= local[2];
	ctx->vsp=local+18;
	w=(pointer)SCALEVEC(ctx,2,local+16); /*scale*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)VNORMALIZE(ctx,1,local+16); /*normalize-vector*/
	local[16]= w;
	local[17]= fqv[55];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[56];
	local[20]= local[5];
	ctx->vsp=local+21;
	w=(*ftab[12])(ctx,1,local+20,&ftab[12],fqv[50]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,10,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[6];
	ctx->vsp=local+11;
	local[6] = cons(ctx,local[10],w);
	local[10]= local[6];
	goto if316;
if315:
	local[10]= NIL;
if316:
	local[10]= local[6];
	w = local[0];
	ctx->vsp=local+11;
	local[0] = cons(ctx,local[10],w);
	local[10]= local[0];
	goto if314;
if313:
	local[10]= local[5];
	w = local[0];
	ctx->vsp=local+11;
	local[0] = cons(ctx,local[10],w);
	local[10]= local[0];
if314:
	local[6] = NIL;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[5] = w;
	local[1] = local[8];
	w = local[1];
	ctx->vsp=local+10;
	local[10]=w;
	goto blk303;
	goto con310;
con312:
	local[10]= NIL;
con310:
	goto if309;
if308:
	local[10]= NIL;
if309:
	goto whl301;
whx302:
	local[10]= NIL;
blk303:
	w = NIL;
	local[8]= local[1];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,2,local+8,&ftab[11],fqv[49]); /*remove*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[6];
	local[11]= NIL;
	local[4] = local[8];
	local[5] = local[9];
	local[6] = local[10];
	local[7] = local[11];
	w = NIL;
	ctx->vsp=local+8;
	goto tag295;
	w = NIL;
	local[4]= w;
blk294:
	argv[0]->c.obj.iv[3] = local[0];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
blk292:
	ctx->vsp=local; return(local[0]);}

/*:analyse-contact*/
static pointer M327(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[2]->c.obj.iv[3];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[0];
whl330:
	if (local[8]==NIL) goto whx331;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= NIL;
	local[10]= local[1];
whl335:
	if (local[10]==NIL) goto whx336;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,1,local+11,&ftab[13],fqv[57]); /*facep*/
	if (w==NIL) goto if339;
	local[11]= local[7];
	local[12]= makeflt(-1.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)F62(ctx,2,local+11); /*face-contact*/
	local[11]= w;
	local[12]= local[2];
	local[13]= fqv[39];
	local[14]= (pointer)get_sym_func(fqv[58]);
	local[15]= fqv[59];
	local[16]= NIL;
	local[17]= fqv[60];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(*ftab[14])(ctx,8,local+11,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if341;
	local[11]= local[7];
	local[12]= makeflt(-1.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)F62(ctx,2,local+11); /*face-contact*/
	local[11]= w;
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	local[11]= local[2];
	goto if342;
if341:
	local[11]= NIL;
if342:
	local[11]= NIL;
	goto if340;
if339:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,1,local+11,&ftab[13],fqv[57]); /*facep*/
	if (w==NIL) goto if343;
	local[11]= local[9];
	local[12]= makeflt(1.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)F62(ctx,2,local+11); /*face-contact*/
	local[11]= w;
	local[12]= local[2];
	local[13]= fqv[39];
	local[14]= (pointer)get_sym_func(fqv[58]);
	local[15]= fqv[59];
	local[16]= NIL;
	local[17]= fqv[60];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(*ftab[14])(ctx,8,local+11,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if345;
	local[11]= local[9];
	local[12]= makeflt(1.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)F62(ctx,2,local+11); /*face-contact*/
	local[11]= w;
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	local[11]= local[2];
	goto if346;
if345:
	local[11]= NIL;
if346:
	local[11]= NIL;
	goto if344;
if343:
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	if (makeint(1)!=local[11]) goto if347;
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	if (makeint(1)!=local[11]) goto if349;
	local[11]= argv[0]->c.obj.iv[0];
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[7];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)F63(ctx,4,local+11); /*edge-edge-contact*/
	local[4] = w;
	if (local[4]==NIL) goto if351;
	local[11]= local[4];
	local[12]= local[2];
	local[13]= fqv[39];
	local[14]= (pointer)get_sym_func(fqv[58]);
	local[15]= fqv[59];
	local[16]= NIL;
	local[17]= fqv[60];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(*ftab[14])(ctx,8,local+11,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if353;
	local[11]= local[4];
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	local[11]= local[2];
	goto if354;
if353:
	local[11]= NIL;
if354:
	local[11]= NIL;
	goto if352;
if351:
	local[11]= NIL;
if352:
	goto if350;
if349:
	local[11]= argv[0]->c.obj.iv[0];
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[7];
	local[14]= local[9];
	local[15]= makeflt(1.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)F64(ctx,5,local+11); /*edge-vertex-contact*/
	local[5] = w;
	if (local[5]==NIL) goto if355;
	local[11]= local[5];
	local[12]= local[2];
	local[13]= fqv[39];
	local[14]= (pointer)get_sym_func(fqv[58]);
	local[15]= fqv[59];
	local[16]= NIL;
	local[17]= fqv[60];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(*ftab[14])(ctx,8,local+11,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if357;
	local[11]= local[5];
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	local[11]= local[2];
	goto if358;
if357:
	local[11]= NIL;
if358:
	local[11]= NIL;
	goto if356;
if355:
	local[11]= NIL;
if356:
if350:
	goto if348;
if347:
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	if (makeint(1)!=local[11]) goto if359;
	local[11]= argv[0]->c.obj.iv[0];
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[9];
	local[14]= local[7];
	local[15]= makeflt(-1.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)F64(ctx,5,local+11); /*edge-vertex-contact*/
	local[5] = w;
	if (local[5]==NIL) goto if361;
	local[11]= local[5];
	local[12]= local[2];
	local[13]= fqv[39];
	local[14]= (pointer)get_sym_func(fqv[58]);
	local[15]= fqv[59];
	local[16]= NIL;
	local[17]= fqv[60];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(*ftab[14])(ctx,8,local+11,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if363;
	local[11]= local[5];
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	local[11]= local[2];
	goto if364;
if363:
	local[11]= NIL;
if364:
	local[11]= NIL;
	goto if362;
if361:
	local[11]= NIL;
if362:
	goto if360;
if359:
	local[11]= argv[0]->c.obj.iv[0];
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[7];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)F65(ctx,4,local+11); /*vertex-vertex-contact*/
	local[6] = w;
	if (local[6]==NIL) goto if365;
	local[11]= local[6];
	local[12]= local[2];
	local[13]= fqv[39];
	local[14]= (pointer)get_sym_func(fqv[58]);
	local[15]= fqv[59];
	local[16]= NIL;
	local[17]= fqv[60];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(*ftab[14])(ctx,8,local+11,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if367;
	local[11]= local[6];
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	local[11]= local[2];
	goto if368;
if367:
	local[11]= NIL;
if368:
	local[11]= NIL;
	goto if366;
if365:
	local[11]= NIL;
if366:
if360:
if348:
if344:
if340:
	goto whl335;
whx336:
	local[11]= NIL;
blk337:
	w = NIL;
	goto whl330;
whx331:
	local[9]= NIL;
blk332:
	w = NIL;
	local[7]= loadglobal(fqv[30]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[31];
	local[10]= fqv[32];
	local[11]= argv[0]->c.obj.iv[0];
	local[12]= fqv[62];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	w = local[7];
	ctx->vsp=local+7;
	local[0]=w;
	goto blk328;
	w = local[7];
	local[0]= w;
blk328:
	ctx->vsp=local; return(local[0]);}

/*:draw-constraint*/
static pointer M370(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ent375;}
	local[0]= NIL;
ent375:
	if (n>=4) { local[1]=(argv[3]); goto ent374;}
	local[1]= makeint(30);
ent374:
	if (n>=5) { local[2]=(argv[4]); goto ent373;}
	local[2]= NIL;
ent373:
ent372:
	if (n>5) maerror();
	if (local[0]==NIL) goto if376;
	local[3]= local[0];
	storeglobal(fqv[63],local[3]);
	goto if377;
if376:
	local[3]= NIL;
if377:
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
whl379:
	if (local[4]==NIL) goto whx380;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= local[3];
whl384:
	if (local[6]==NIL) goto whx385;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= argv[0]->c.obj.iv[0];
	local[9]= local[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,2,local+8); /*v+*/
	local[8]= w;
	local[9]= T;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F60(ctx,4,local+7); /*draw-arrow*/
	goto whl384;
whx385:
	local[7]= NIL;
blk386:
	w = NIL;
	goto whl379;
whx380:
	local[5]= NIL;
blk381:
	w = NIL;
	local[0]= w;
blk371:
	ctx->vsp=local; return(local[0]);}

/*draw-arrow*/
static pointer F60(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ent391;}
	local[0]= NIL;
ent391:
	if (n>=4) { local[1]=(argv[3]); goto ent390;}
	local[1]= NIL;
ent390:
ent389:
	if (n>4) maerror();
	local[2]= loadglobal(fqv[63]);
	local[3]= fqv[64];
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
blk388:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M392(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[65], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto key394;
	local[0] = NIL;
key394:
	if (n & (1<<1)) goto key395;
	local[1] = NIL;
key395:
	if (n & (1<<2)) goto key396;
	local[2] = NIL;
key396:
	if (local[0]==NIL) goto if397;
	argv[0]->c.obj.iv[1] = local[0];
	local[3]= argv[0]->c.obj.iv[1];
	goto if398;
if397:
	local[3]= NIL;
if398:
	if (local[1]==NIL) goto if399;
	argv[0]->c.obj.iv[0] = local[1];
	local[3]= argv[0]->c.obj.iv[0];
	goto if400;
if399:
	local[3]= NIL;
if400:
	if (local[2]==NIL) goto if401;
	argv[0]->c.obj.iv[2] = local[2];
	local[3]= argv[0]->c.obj.iv[2];
	goto if402;
if401:
	local[3]= NIL;
if402:
	w = argv[0];
	local[0]= w;
blk393:
	ctx->vsp=local; return(local[0]);}

/*:constrained-body*/
static pointer M403(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
blk404:
	ctx->vsp=local; return(local[0]);}

/*:constraining-body*/
static pointer M405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
blk406:
	ctx->vsp=local; return(local[0]);}

/*contact-to-constraint*/
static pointer F61(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
whl409:
	if (local[3]==NIL) goto whx410;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= argv[1];
	local[6]= fqv[39];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo413,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,4,local+4,&ftab[7],fqv[40]); /*find*/
	local[0] = w;
	if (local[0]==NIL) goto if414;
	local[4]= local[2];
	local[5]= fqv[66];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[0];
	local[5]= argv[1];
	local[6]= fqv[39];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo416,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,4,local+4,&ftab[15],fqv[67]); /*delete*/
	argv[1] = w;
	local[4]= argv[1];
	goto if415;
if414:
	local[4]= loadglobal(fqv[30]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[31];
	local[7]= fqv[32];
	local[8]= local[2]->c.obj.iv[0];
	local[9]= fqv[62];
	local[10]= local[2]->c.obj.iv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,6,local+5); /*send*/
	w = local[4];
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
if415:
	goto whl409;
whx410:
	local[4]= NIL;
blk411:
	w = NIL;
	if (argv[1]==NIL) goto if418;
	local[2]= NIL;
	local[3]= argv[1];
whl421:
	if (local[3]==NIL) goto whx422;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= loadglobal(fqv[30]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[31];
	local[7]= fqv[32];
	local[8]= local[2]->c.obj.iv[0];
	local[9]= fqv[62];
	local[10]= makeflt(-1.00000000e+00);
	local[11]= local[2]->c.obj.iv[2]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,6,local+5); /*send*/
	w = local[4];
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto whl421;
whx422:
	local[4]= NIL;
blk423:
	w = NIL;
	local[2]= w;
	goto if419;
if418:
	local[2]= NIL;
if419:
	w = local[1];
	local[0]= w;
blk407:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo413(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[1]->c.obj.iv[0];
	local[2]= loadglobal(fqv[3]);
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,3,local+0,&ftab[9],fqv[43]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo416(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[1]->c.obj.iv[0];
	local[2]= loadglobal(fqv[3]);
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,3,local+0,&ftab[9],fqv[43]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*face-contact*/
static pointer F62(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
blk426:
	ctx->vsp=local; return(local[0]);}

/*edge-edge-contact*/
static pointer F63(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= fqv[68];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[1];
	local[6]= fqv[68];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3] = w;
	local[5]= local[0]->c.obj.iv[2];
	local[6]= local[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	local[5]= w;
	local[6]= local[1]->c.obj.iv[2];
	local[7]= local[1]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	{ double x,y;
		y=fltval(w); x=fltval(local[5]);
		local[5]=(makeflt(x * y));}
	local[6]= local[0]->c.obj.iv[2];
	local[7]= local[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	local[7]= local[1]->c.obj.iv[2];
	local[8]= local[1]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VINNERPRODUCT(ctx,2,local+6); /*v.*/
	{ double x,y;
		y=fltval(makeflt((double)fabs(fltval(w)))); x=fltval(local[5]);
		local[5]=(makeflt(x - y));}
	local[6]= loadglobal(fqv[3]);
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto if428;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto blk427;
	goto if429;
if428:
	local[5]= NIL;
if429:
	local[5]= fqv[69];
	local[6]= local[0]->c.obj.iv[2];
	local[7]= local[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	local[7]= local[1]->c.obj.iv[2];
	local[8]= local[1]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	local[7]= fqv[51];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[16])(ctx,4,local+5,&ftab[16],fqv[70]); /*make-plane*/
	local[4] = w;
	local[5]= local[4];
	local[6]= fqv[71];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[0]= w;
blk427:
	ctx->vsp=local; return(local[0]);}

/*edge-vertex-contact*/
static pointer F64(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	local[8]= fqv[68];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[1] = w;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo431,env,argv,local);
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[2] = w;
	local[7]= local[0]->c.obj.iv[3];
	local[8]= fqv[71];
	local[9]= argv[1];
	local[10]= local[1];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto if432;
	local[7]= local[3];
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto if433;
if432:
	local[7]= NIL;
if433:
	local[7]= local[0]->c.obj.iv[4];
	local[8]= fqv[71];
	local[9]= argv[1];
	local[10]= local[1];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto if434;
	local[7]= local[3];
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto if435;
if434:
	local[7]= NIL;
if435:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[7]= NIL;
	local[8]= local[2];
whl437:
	if (local[8]==NIL) goto whx438;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= fqv[69];
	local[10]= local[4];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	local[11]= local[7];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+10); /*v**/
	local[10]= w;
	local[11]= fqv[51];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[16])(ctx,4,local+9,&ftab[16],fqv[70]); /*make-plane*/
	local[6] = w;
	local[9]= local[6];
	local[10]= fqv[71];
	local[11]= argv[1];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto if441;
	local[9]= local[3];
	local[10]= local[5];
	local[11]= fqv[39];
	local[12]= (pointer)get_sym_func(fqv[43]);
	local[13]= fqv[59];
	local[14]= NIL;
	local[15]= fqv[60];
	local[16]= NIL;
	ctx->vsp=local+17;
	w=(*ftab[14])(ctx,8,local+9,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if443;
	local[9]= local[3];
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto if444;
if443:
	local[9]= NIL;
if444:
	local[9]= NIL;
	goto if442;
if441:
	local[9]= NIL;
if442:
	goto whl437;
whx438:
	local[9]= NIL;
blk439:
	w = NIL;
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,1,local+7,&ftab[0],fqv[6]); /*minusp*/
	if (w==NIL) goto if445;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo447,env,argv,local);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[5] = w;
	local[7]= local[5];
	goto if446;
if445:
	local[7]= NIL;
if446:
	w = local[5];
	local[0]= w;
blk430:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*vertex-vertex-contact*/
static pointer F65(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo449,env,argv,local);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[0] = w;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,clo450,env,argv,local);
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[1] = w;
	local[2] = local[1];
	local[7]= NIL;
	local[8]= local[0];
whl452:
	if (local[8]==NIL) goto whx453;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= local[1];
	local[11]= fqv[39];
	local[12]= (pointer)get_sym_func(fqv[43]);
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,4,local+9,&ftab[7],fqv[40]); /*find*/
	if (w!=NIL) goto if456;
	local[9]= local[7];
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	local[9]= local[2];
	goto if457;
if456:
	local[9]= NIL;
if457:
	goto whl452;
whx453:
	local[9]= NIL;
blk454:
	w = NIL;
whl458:
	if (local[2]==NIL) goto whx459;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	local[7]= NIL;
	local[8]= local[2];
whl462:
	if (local[8]==NIL) goto whx463;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= fqv[69];
	local[10]= local[4];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	local[11]= local[7];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+10); /*v**/
	local[10]= w;
	local[11]= fqv[51];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[16])(ctx,4,local+9,&ftab[16],fqv[70]); /*make-plane*/
	local[6] = w;
	local[9]= local[6];
	local[10]= fqv[71];
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto if466;
	local[9]= local[3];
	local[10]= local[5];
	local[11]= fqv[39];
	local[12]= (pointer)get_sym_func(fqv[43]);
	local[13]= fqv[59];
	local[14]= NIL;
	local[15]= fqv[60];
	local[16]= NIL;
	ctx->vsp=local+17;
	w=(*ftab[14])(ctx,8,local+9,&ftab[14],fqv[61]); /*member*/
	if (w!=NIL) goto if468;
	local[9]= local[3];
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto if469;
if468:
	local[9]= NIL;
if469:
	local[9]= NIL;
	goto if467;
if466:
	local[9]= NIL;
if467:
	goto whl462;
whx463:
	local[9]= NIL;
blk464:
	w = NIL;
	goto whl458;
whx459:
	local[7]= NIL;
blk460:
	w = local[5];
	local[0]= w;
blk448:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo449(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo450(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___model2constRobust(ctx,n,argv,env)
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
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto if470;
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[75],w);
	goto if471;
if470:
	local[0]= fqv[76];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
if471:
	local[0]= fqv[77];
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[79]); /*require*/
	local[0]= fqv[80];
	ctx->vsp=local+1;
	w=(*ftab[18])(ctx,1,local+0,&ftab[18],fqv[81]); /*provide*/
	local[0]= T;
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= fqv[83];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[84];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= makeflt(5.00000000e+00);
	storeglobal(fqv[1],local[0]);
	local[0]= fqv[3];
	local[1]= fqv[85];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if472;
	local[0]= fqv[3];
	local[1]= fqv[86];
	local[2]= makeflt(5.00000000e+00);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto if473;
if472:
	local[0]= NIL;
if473:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M66,fqv[23],fqv[52],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M72,fqv[71],fqv[88],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M100,fqv[18],fqv[90],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M129,fqv[92],fqv[90],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M136,fqv[38],fqv[94],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M147,fqv[18],fqv[94],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M162,fqv[97],fqv[98],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M197,fqv[100],fqv[98],fqv[101]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F59,fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M221,fqv[31],fqv[30],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M238,fqv[36],fqv[30],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M251,fqv[47],fqv[30],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M291,fqv[48],fqv[30],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M327,fqv[66],fqv[30],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M370,fqv[108],fqv[30],fqv[109]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[110],module,F60,fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M392,fqv[31],fqv[112],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M403,fqv[114],fqv[112],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M405,fqv[116],fqv[112],fqv[117]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[118],module,F61,fqv[119]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[120],module,F62,fqv[121]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[122],module,F63,fqv[123]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[124],module,F64,fqv[125]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[126],module,F65,fqv[127]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<19; i++) ftab[i]=fcallx;
}
