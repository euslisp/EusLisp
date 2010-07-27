/* toiv.c :  entry=toiv */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "toiv.h"
#pragma init (register_toiv)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___toiv();
extern pointer build_quote_vector();
static register_toiv()
  { add_module_initializer("___toiv", ___toiv);}

static pointer F631();

/*toiv*/
static pointer F631(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST633:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= argv[0];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= argv[0];
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= NIL;
	local[2]= local[0];
WHL635:
	if (local[2]==NIL) goto WHX636;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET639,env,argv,local);
	local[4]= local[1];
	w = local[3];
	ctx->vsp=local+5;
	w=FLET639(ctx,1,local+4,w);
	local[4]= w;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO640,env,argv,local);
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO641,env,argv,local);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[5];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= local[1];
	local[9]= loadglobal(fqv[6]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF642;
	local[8]= local[1];
	local[9]= fqv[7];
	ctx->vsp=local+10;
	w=(pointer)GETPROP(ctx,2,local+8); /*get*/
	local[7] = w;
	if (local[7]==NIL) goto IF642;
	local[8]= local[7]->c.obj.iv[2];
	local[9]= local[7]->c.obj.iv[3];
	local[10]= local[7]->c.obj.iv[4];
	local[11]= local[7]->c.obj.iv[5];
	local[12]= local[7]->c.obj.iv[6];
	local[13]= argv[0];
	local[14]= fqv[8];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,2,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[9];
	local[15]= local[8];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	local[16]= local[8];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,2,local+16); /*aref*/
	local[16]= w;
	local[17]= local[8];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[10];
	local[15]= local[9];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	local[16]= local[9];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,2,local+16); /*aref*/
	local[16]= w;
	local[17]= local[9];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[11];
	local[15]= local[10];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	local[16]= local[10];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,2,local+16); /*aref*/
	local[16]= w;
	local[17]= local[10];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[12];
	local[15]= local[11];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	local[16]= local[11];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,2,local+16); /*aref*/
	local[16]= w;
	local[17]= local[11];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[13];
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,3,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[14];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,3,local+13); /*format*/
	local[13]= argv[0];
	local[14]= fqv[15];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,2,local+13); /*format*/
	local[8]= w;
	goto IF643;
IF642:
	local[8]= NIL;
IF643:
	local[8]= argv[0];
	local[9]= fqv[16];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[17];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= NIL;
	local[9]= local[5];
WHL645:
	if (local[9]==NIL) goto WHX646;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= local[8];
WHL650:
	if (local[11]==NIL) goto WHX651;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= argv[0];
	local[13]= fqv[18];
	local[14]= local[10];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= loadglobal(fqv[19]);
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	local[15]= local[10];
	local[16]= makeint(1);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= loadglobal(fqv[19]);
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= local[10];
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= loadglobal(fqv[19]);
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)XFORMAT(ctx,5,local+12); /*format*/
	goto WHL650;
WHX651:
	local[12]= NIL;
BLK652:
	w = NIL;
	goto WHL645;
WHX646:
	local[10]= NIL;
BLK647:
	w = NIL;
	local[8]= argv[0];
	local[9]= fqv[20];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[21];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[22];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[23];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= NIL;
	local[9]= local[6];
WHL655:
	if (local[9]==NIL) goto WHX656;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= fqv[24];
	local[12]= local[8];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[8];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[8];
	local[15]= makeint(2);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,5,local+10); /*format*/
	goto WHL655;
WHX656:
	local[10]= NIL;
BLK657:
	w = NIL;
	local[8]= argv[0];
	local[9]= fqv[25];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[26];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[27];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[28];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[29];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[30];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[31];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= makeint(0);
	local[9]= NIL;
	local[10]= local[5];
WHL660:
	if (local[10]==NIL) goto WHX661;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= NIL;
	local[12]= local[9];
WHL665:
	if (local[12]==NIL) goto WHX666;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= argv[0];
	local[14]= fqv[32];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,3,local+13); /*format*/
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL665;
WHX666:
	local[13]= NIL;
BLK667:
	w = NIL;
	local[11]= argv[0];
	local[12]= fqv[33];
	local[13]= makeint(-1);
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	goto WHL660;
WHX661:
	local[11]= NIL;
BLK662:
	w = NIL;
	local[8]= argv[0];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[35];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= argv[0];
	local[9]= fqv[36];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	goto WHL635;
WHX636:
	local[3]= NIL;
BLK637:
	w = NIL;
	local[1]= argv[0];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[0]= w;
BLK632:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET639(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON670;
	local[0]= (pointer)get_sym_func(fqv[38]);
	local[1]= env->c.clo.env2[3];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	goto CON669;
CON670:
	local[0]= argv[0];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[40]); /*find-method*/
	if (w==NIL) goto CON671;
	local[0]= argv[0];
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[40]); /*find-method*/
	if (w==NIL) goto IF672;
	local[0]= argv[0];
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF673;
IF672:
	local[0]= NIL;
IF673:
	local[0]= (pointer)get_sym_func(fqv[38]);
	local[1]= env->c.clo.env2[3];
	local[2]= argv[0];
	local[3]= fqv[39];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	goto CON669;
CON671:
	local[0]= argv[0];
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[40]); /*find-method*/
	if (w==NIL) goto IF675;
	local[0]= argv[0];
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF676;
IF675:
	local[0]= NIL;
IF676:
	local[0]= argv[0];
	local[1]= fqv[42];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON669;
CON674:
	local[0]= NIL;
CON669:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO640(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[43];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO641(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___toiv(ctx,n,argv,env)
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
	local[0]= fqv[45];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[47]); /*require*/
	local[0]= fqv[48];
	local[1]= fqv[49];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[47]); /*require*/
	local[0]= fqv[19];
	local[1]= fqv[50];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF677;
	local[0]= fqv[19];
	local[1]= fqv[50];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF679;
	local[0]= fqv[19];
	local[1]= fqv[51];
	local[2]= makeflt(1.00000000e+00);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF680;
IF679:
	local[0]= NIL;
IF680:
	local[0]= fqv[19];
	goto IF678;
IF677:
	local[0]= NIL;
IF678:
	ctx->vsp=local+0;
	compfun(ctx,fqv[52],module,F631,fqv[53]);
	local[0]= fqv[54];
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[55]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<3; i++) ftab[i]=fcallx;
}
