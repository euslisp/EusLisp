/* drawconst.c :  entry=drawconst */
/* compiled by EusLisp 8.16 for Solaris2  created on Fri Oct 4 14:23:40 JST 1996 */
#include "eus.h"
#include "drawconst.h"
#pragma init (register_drawconst)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___drawconst();
extern pointer build_quote_vector();
static register_drawconst()
  { add_module_initializer("___drawconst", ___drawconst);}

static pointer F556();
static pointer F557();
static pointer F558();
static pointer F559();

/*draw-constraint*/
static pointer F556(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent565;}
	local[0]= NIL;
ent565:
	if (n>=3) { local[1]=(argv[2]); goto ent564;}
	local[1]= NIL;
ent564:
	if (n>=4) { local[2]=(argv[3]); goto ent563;}
	local[2]= loadglobal(fqv[0]);
ent563:
	if (n>=5) { local[3]=(argv[4]); goto ent562;}
	local[3]= makeint(30);
ent562:
ent561:
	if (n>5) maerror();
	if (local[0]==NIL) goto if566;
	if (local[1]==NIL) goto if566;
	local[4]= NIL;
	local[5]= argv[0];
whl569:
	if (local[5]==NIL) goto whx570;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4]->c.obj.iv[1];
	if (local[0]!=local[6]) goto if573;
	local[6]= local[4]->c.obj.iv[0];
	if (local[1]!=local[6]) goto if573;
	local[6]= NIL;
	local[7]= local[4]->c.obj.iv[2];
whl576:
	if (local[7]==NIL) goto whx577;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	goto whl576;
whx577:
	local[8]= NIL;
blk578:
	w = NIL;
	local[6]= w;
	goto if574;
if573:
	local[6]= NIL;
if574:
	goto whl569;
whx570:
	local[6]= NIL;
blk571:
	w = NIL;
	local[4]= w;
	goto if567;
if566:
	local[4]= NIL;
	local[5]= argv[0];
whl581:
	if (local[5]==NIL) goto whx582;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= local[4]->c.obj.iv[2];
whl586:
	if (local[7]==NIL) goto whx587;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	goto whl586;
whx587:
	local[8]= NIL;
blk588:
	w = NIL;
	goto whl581;
whx582:
	local[6]= NIL;
blk583:
	w = NIL;
	local[4]= w;
if567:
	w = local[4];
	local[0]= w;
blk560:
	ctx->vsp=local; return(local[0]);}

/*draw-cbodies*/
static pointer F557(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ent592;}
	local[0]= makeflt(5.00000000e+00);
ent592:
ent591:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
whl594:
	if (local[2]==NIL) goto whx595;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= local[1]->c.obj.iv[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[2]); /*draw*/
	local[3]= NIL;
	local[4]= local[1]->c.obj.iv[2];
whl599:
	if (local[4]==NIL) goto whx600;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto whl599;
whx600:
	local[5]= NIL;
blk601:
	w = NIL;
	goto whl594;
whx595:
	local[3]= NIL;
blk596:
	w = NIL;
	local[0]= w;
blk590:
	ctx->vsp=local; return(local[0]);}

/*draw-motion*/
static pointer F558(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
rst604:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
whl606:
	if (local[6]==NIL) goto whx607;
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
whl611:
	if (local[8]==NIL) goto whx612;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= fqv[3];
	local[10]= makeint(3);
	local[11]= makeint(3);
	local[12]= makeflt(1.00000000e+00);
	local[13]= local[7];
	local[14]= makeint(5);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	local[14]= local[7];
	local[15]= makeint(4);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint(5);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= makeflt(1.00000000e+00);
	local[15]= local[7];
	local[16]= makeint(3);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,1,local+15); /*-*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	local[14]= local[7];
	local[15]= makeint(4);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= local[7];
	local[16]= makeint(3);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= makeflt(1.00000000e+00);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,3,local+14); /*list*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,3,local+10,&ftab[1],fqv[4]); /*make-matrix*/
	local[10]= w;
	local[11]= fqv[5];
	local[12]= local[7];
	local[13]= makeint(0);
	local[14]= makeint(3);
	ctx->vsp=local+15;
	w=(pointer)SUBSEQ(ctx,3,local+12); /*subseq*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[6]); /*make-coords*/
	local[1] = w;
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)COPYOBJ(ctx,1,local+9); /*copy-object*/
	local[2] = w;
	local[9]= local[2];
	local[10]= fqv[7];
	local[11]= local[1];
	local[12]= fqv[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	ctx->vsp=local+9;
	w=(pointer)READCH(ctx,0,local+9); /*read-char*/
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,0,local+9,&ftab[3],fqv[10]); /*cls*/
	local[9]= argv[1];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[11]); /*hidd*/
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)SLEEP(ctx,1,local+9); /*unix:sleep*/
	local[9]= local[2];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[11]); /*hidd*/
	local[9]= local[2];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	goto whl611;
whx612:
	local[9]= NIL;
blk613:
	w = NIL;
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,0,local+7); /*read-char*/
	local[7]= NIL;
	local[8]= local[3];
whl616:
	if (local[8]==NIL) goto whx617;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[11]); /*hidd*/
	goto whl616;
whx617:
	local[9]= NIL;
blk618:
	w = NIL;
	goto whl606;
whx607:
	local[7]= NIL;
blk608:
	w = NIL;
	local[0]= w;
blk603:
	ctx->vsp=local; return(local[0]);}

/*draw-force*/
static pointer F559(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
whl622:
	if (local[5]==NIL) goto whx623;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= local[4];
whl627:
	if (local[7]==NIL) goto whx628;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= fqv[3];
	local[9]= makeint(3);
	local[10]= makeint(3);
	local[11]= makeflt(1.00000000e+00);
	local[12]= local[6];
	local[13]= makeint(5);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,1,local+12); /*-*/
	local[12]= w;
	local[13]= local[6];
	local[14]= makeint(4);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	local[12]= local[6];
	local[13]= makeint(5);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= makeflt(1.00000000e+00);
	local[14]= local[6];
	local[15]= makeint(3);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	local[13]= local[6];
	local[14]= makeint(4);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	local[14]= local[6];
	local[15]= makeint(3);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= makeflt(1.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[1])(ctx,3,local+9,&ftab[1],fqv[4]); /*make-matrix*/
	local[9]= w;
	local[10]= fqv[5];
	local[11]= local[6];
	local[12]= makeint(0);
	local[13]= makeint(3);
	ctx->vsp=local+14;
	w=(pointer)SUBSEQ(ctx,3,local+11); /*subseq*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,4,local+8,&ftab[2],fqv[6]); /*make-coords*/
	local[0] = w;
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)COPYOBJ(ctx,1,local+8); /*copy-object*/
	local[1] = w;
	local[8]= local[1];
	local[9]= fqv[7];
	local[10]= local[0];
	local[11]= fqv[8];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= local[1];
	local[9]= fqv[9];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,0,local+8); /*read-char*/
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,0,local+8,&ftab[3],fqv[10]); /*cls*/
	local[8]= argv[1];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,2,local+8,&ftab[4],fqv[11]); /*hidd*/
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)SLEEP(ctx,1,local+8); /*unix:sleep*/
	local[8]= local[1];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,2,local+8,&ftab[4],fqv[11]); /*hidd*/
	local[8]= local[1];
	w = local[2];
	ctx->vsp=local+9;
	local[2] = cons(ctx,local[8],w);
	goto whl627;
whx628:
	local[8]= NIL;
blk629:
	w = NIL;
	ctx->vsp=local+6;
	w=(pointer)READCH(ctx,0,local+6); /*read-char*/
	local[6]= NIL;
	local[7]= local[2];
whl632:
	if (local[7]==NIL) goto whx633;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,1,local+8,&ftab[4],fqv[11]); /*hidd*/
	goto whl632;
whx633:
	local[8]= NIL;
blk634:
	w = NIL;
	goto whl622;
whx623:
	local[6]= NIL;
blk624:
	w = NIL;
	local[0]= w;
blk620:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___drawconst(ctx,n,argv,env)
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
	local[0]= fqv[12];
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[14]); /*require*/
	local[0]= fqv[15];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[16]); /*provide*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[17],module,F556,fqv[18]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[19],module,F557,fqv[20]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[21],module,F558,fqv[22]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F559,fqv[24]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
