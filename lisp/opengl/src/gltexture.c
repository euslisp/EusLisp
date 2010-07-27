/* gltexture.c :  entry=gltexture */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "gltexture.h"
#pragma init (register_gltexture)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___gltexture();
extern pointer build_quote_vector();
static register_gltexture()
  { add_module_initializer("___gltexture", ___gltexture);}

static pointer F532();
static pointer F533();
static pointer F534();
static pointer F535();

/*transpose-rows*/
static pointer F532(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,3,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[4]); /*make-string*/
	local[4]= w;
	local[5]= local[2];
	local[6]= makeint(3);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w!=NIL) goto IF538;
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,1,local+5); /*error*/
	local[5]= w;
	goto IF539;
IF538:
	local[5]= NIL;
IF539:
	local[5]= makeint(0);
	local[6]= local[0];
WHL541:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX542;
	local[7]= makeint(0);
	local[8]= local[1];
WHL545:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX546;
	local[9]= makeint(0);
	local[10]= local[2];
WHL549:
	local[11]= local[9];
	w = local[10];
	if ((integer_t)local[11] >= (integer_t)w) goto WHX550;
	local[11]= local[4];
	local[12]= local[1];
	local[13]= local[7];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	local[13]= local[0];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,3,local+12); /***/
	local[12]= w;
	local[13]= local[5];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,3,local+12); /*+*/
	local[12]= w;
	local[13]= local[3];
	local[14]= local[7];
	local[15]= local[0];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,3,local+14); /***/
	local[14]= w;
	local[15]= local[5];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,3,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[9] = (pointer)((integer_t)(local[9])+4);
	goto WHL549;
WHX550:
	local[11]= NIL;
BLK551:
	w = NIL;
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL545;
WHX546:
	local[9]= NIL;
BLK547:
	w = NIL;
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL541;
WHX542:
	local[7]= NIL;
BLK543:
	w = NIL;
	local[5]= loadglobal(fqv[6]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[7];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	w = local[5];
	local[0]= w;
BLK537:
	ctx->vsp=local; return(local[0]);}

/*load-texture-file*/
static pointer F533(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*image:read-pnm-file*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[9]); /*image:color-to-deep*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F532(ctx,1,local+0); /*transpose-rows*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(1);
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)LOG(ctx,2,local+5); /*log*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CEILING(ctx,1,local+5); /*ceiling*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASH(ctx,2,local+4); /*ash*/
	local[4]= w;
	local[5]= makeint(1);
	local[6]= local[2];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)LOG(ctx,2,local+6); /*log*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CEILING(ctx,1,local+6); /*ceiling*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASH(ctx,2,local+5); /*ash*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[3];
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w!=NIL) goto IF554;
	local[7]= fqv[10];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF555;
IF554:
	local[7]= NIL;
IF555:
	local[7]= local[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto AND558;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto AND558;
	goto CON557;
AND558:
	local[7]= local[4];
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,3,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,1,local+7,&ftab[0],fqv[4]); /*make-string*/
	local[7]= w;
	local[8]= makeint(6407);
	local[9]= local[1];
	local[10]= local[2];
	local[11]= makeint(5121);
	local[12]= local[0];
	local[13]= fqv[3];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[4];
	local[14]= local[5];
	local[15]= makeint(5121);
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(*ftab[3])(ctx,9,local+8,&ftab[3],fqv[11]); /*gluscaleimage*/
	local[8]= loadglobal(fqv[6]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[7];
	local[11]= local[4];
	local[12]= local[5];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	w = local[8];
	local[7]= w;
	goto CON556;
CON557:
	local[7]= local[0];
	goto CON556;
CON560:
	local[7]= NIL;
CON556:
	w = local[7];
	local[0]= w;
BLK553:
	ctx->vsp=local; return(local[0]);}

/*append-image*/
static pointer F534(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST562:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]==NIL) goto IF563;
	local[1]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO565,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[13]);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO566,env,argv,local);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	local[3]= makeint(3);
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,3,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[4]); /*make-string*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= local[0];
WHL568:
	if (local[7]==NIL) goto WHX569;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[6];
	local[10]= fqv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[6];
	local[11]= fqv[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= makeint(0);
	local[12]= local[8];
WHL573:
	local[13]= local[11];
	w = local[12];
	if ((integer_t)local[13] >= (integer_t)w) goto WHX574;
	local[13]= makeint(0);
	local[14]= local[9];
WHL577:
	local[15]= local[13];
	w = local[14];
	if ((integer_t)local[15] >= (integer_t)w) goto WHX578;
	local[15]= makeint(0);
	local[16]= local[3];
WHL581:
	local[17]= local[15];
	w = local[16];
	if ((integer_t)local[17] >= (integer_t)w) goto WHX582;
	local[17]= local[4];
	local[18]= local[13];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[18]= w;
	local[19]= local[1];
	local[20]= local[3];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,3,local+18); /***/
	local[18]= w;
	local[19]= local[11];
	local[20]= local[3];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,2,local+19); /***/
	local[19]= w;
	local[20]= local[15];
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,3,local+18); /*+*/
	local[18]= w;
	local[19]= local[10];
	local[20]= local[13];
	local[21]= local[8];
	local[22]= local[3];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,3,local+20); /***/
	local[20]= w;
	local[21]= local[11];
	local[22]= local[3];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	local[22]= local[15];
	ctx->vsp=local+23;
	w=(pointer)PLUS(ctx,3,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SETELT(ctx,3,local+17); /*setelt*/
	local[15] = (pointer)((integer_t)(local[15])+4);
	goto WHL581;
WHX582:
	local[17]= NIL;
BLK583:
	w = NIL;
	local[13] = (pointer)((integer_t)(local[13])+4);
	goto WHL577;
WHX578:
	local[15]= NIL;
BLK579:
	w = NIL;
	local[11] = (pointer)((integer_t)(local[11])+4);
	goto WHL573;
WHX574:
	local[13]= NIL;
BLK575:
	w = NIL;
	local[11]= local[5];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[5] = w;
	w = local[5];
	goto WHL568;
WHX569:
	local[8]= NIL;
BLK570:
	w = NIL;
	local[6]= loadglobal(fqv[6]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[7];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	local[1]= w;
	goto IF564;
IF563:
	local[1]= NIL;
IF564:
	w = local[1];
	local[0]= w;
BLK561:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO565(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO566(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[1];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-cube-with-texture*/
static pointer F535(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST586:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[14], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY587;
	local[1] = NIL;
KEY587:
	if (n & (1<<1)) goto KEY588;
	local[2] = NIL;
KEY588:
	if (n & (1<<2)) goto KEY589;
	local[3] = NIL;
KEY589:
	if (n & (1<<3)) goto KEY590;
	local[4] = NIL;
KEY590:
	if (n & (1<<4)) goto KEY591;
	local[5] = NIL;
KEY591:
	if (n & (1<<5)) goto KEY592;
	local[6] = NIL;
KEY592:
	if (n & (1<<6)) goto KEY593;
	local[7] = NIL;
KEY593:
	if (n & (1<<7)) goto KEY594;
	local[8] = NIL;
KEY594:
	if (local[7]==NIL) goto AND598;
	local[9]= local[7];
	local[10]= makeint(1);
	local[11]= local[7];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)LOG(ctx,2,local+11); /*log*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)CEILING(ctx,1,local+11); /*ceiling*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NUMEQUAL(ctx,2,local+9); /*=*/
	if (w!=NIL) goto AND598;
	goto OR597;
AND598:
	if (local[8]==NIL) goto AND599;
	local[9]= local[8];
	local[10]= makeint(1);
	local[11]= local[8];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)LOG(ctx,2,local+11); /*log*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)CEILING(ctx,1,local+11); /*ceiling*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NUMEQUAL(ctx,2,local+9); /*=*/
	if (w!=NIL) goto AND599;
	goto OR597;
AND599:
	goto IF595;
OR597:
	local[9]= fqv[15];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF596;
IF595:
	local[9]= NIL;
IF596:
	local[9]= (pointer)get_sym_func(fqv[16]);
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[17];
	local[12]= NIL;
	local[13]= fqv[18];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[9];
	local[12]= fqv[17];
	local[13]= NIL;
	local[14]= fqv[19];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[9];
	local[13]= fqv[17];
	local[14]= NIL;
	local[15]= fqv[20];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[9];
	local[14]= fqv[17];
	local[15]= NIL;
	local[16]= fqv[20];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[9];
	local[15]= fqv[17];
	local[16]= NIL;
	local[17]= fqv[20];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,5,local+14); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[9];
	local[16]= fqv[17];
	local[17]= NIL;
	local[18]= fqv[20];
	local[19]= makeint(3);
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,5,local+15); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,6,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO600,env,argv,local);
	local[12]= local[1];
	local[13]= local[2];
	local[14]= local[3];
	local[15]= local[4];
	local[16]= local[5];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,6,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[11]= w;
	local[12]= makeflt(1.00000000e+00);
	local[13]= makeflt(1.00000000e+00);
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= (pointer)get_sym_func(fqv[21]);
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(*ftab[4])(ctx,2,local+17,&ftab[4],fqv[22]); /*remove-if*/
	if (w!=NIL) goto IF601;
	w = local[9];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK585;
	goto IF602;
IF601:
	local[17]= NIL;
IF602:
	local[17]= (pointer)get_sym_func(fqv[23]);
	local[18]= (pointer)get_sym_func(fqv[21]);
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(*ftab[4])(ctx,2,local+18,&ftab[4],fqv[22]); /*remove-if*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,2,local+17); /*apply*/
	local[14] = w;
	local[17]= local[14];
	local[18]= fqv[0];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= local[14];
	local[19]= fqv[1];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
	local[19]= local[14];
	local[20]= fqv[2];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	local[20]= local[14];
	local[21]= fqv[3];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	if (local[7]==NIL) goto IF603;
	local[21]= local[7];
	goto IF604;
IF603:
	local[21]= makeint(1);
	local[22]= local[17];
	local[23]= makeint(2);
	ctx->vsp=local+24;
	w=(pointer)LOG(ctx,2,local+22); /*log*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)CEILING(ctx,1,local+22); /*ceiling*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
IF604:
	if (local[8]==NIL) goto IF605;
	local[22]= local[8];
	goto IF606;
IF605:
	local[22]= makeint(1);
	local[23]= local[18];
	local[24]= makeint(2);
	ctx->vsp=local+25;
	w=(pointer)LOG(ctx,2,local+23); /*log*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)CEILING(ctx,1,local+23); /*ceiling*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)ASH(ctx,2,local+22); /*ash*/
	local[22]= w;
IF606:
	local[23]= local[19];
	local[24]= local[20];
	local[25]= local[18];
	local[26]= local[22];
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto OR609;
	local[25]= local[17];
	local[26]= local[21];
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto OR609;
	goto IF607;
OR609:
	local[25]= fqv[24];
	local[26]= local[21];
	local[27]= local[22];
	local[28]= local[17];
	local[29]= local[18];
	ctx->vsp=local+30;
	w=(*ftab[5])(ctx,5,local+25,&ftab[5],fqv[25]); /*warn*/
	local[25]= local[21];
	local[26]= local[22];
	local[27]= local[19];
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,3,local+25); /***/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[0])(ctx,1,local+25,&ftab[0],fqv[4]); /*make-string*/
	local[24] = w;
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)EUSFLOAT(ctx,1,local+25); /*float*/
	local[25]= w;
	local[26]= local[17];
	ctx->vsp=local+27;
	w=(pointer)EUSFLOAT(ctx,1,local+26); /*float*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)QUOTIENT(ctx,2,local+25); /*/*/
	local[12] = w;
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(pointer)EUSFLOAT(ctx,1,local+25); /*float*/
	local[25]= w;
	local[26]= local[18];
	ctx->vsp=local+27;
	w=(pointer)EUSFLOAT(ctx,1,local+26); /*float*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)QUOTIENT(ctx,2,local+25); /*/*/
	local[13] = w;
	local[25]= local[19];
	local[26]= makeint(3);
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto IF610;
	local[25]= makeint(6407);
	goto IF611;
IF610:
	local[25]= makeint(6409);
IF611:
	local[26]= local[25];
	local[27]= local[17];
	local[28]= local[18];
	local[29]= makeint(5121);
	local[30]= local[20];
	local[31]= local[21];
	local[32]= local[22];
	local[33]= makeint(5121);
	local[34]= local[24];
	ctx->vsp=local+35;
	w=(*ftab[3])(ctx,9,local+26,&ftab[3],fqv[11]); /*gluscaleimage*/
	local[25]= loadglobal(fqv[6]);
	ctx->vsp=local+26;
	w=(pointer)INSTANTIATE(ctx,1,local+25); /*instantiate*/
	local[25]= w;
	local[26]= local[25];
	local[27]= fqv[7];
	local[28]= local[21];
	local[29]= local[22];
	local[30]= local[24];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,5,local+26); /*send*/
	w = local[25];
	local[14] = w;
	local[25]= local[14];
	goto IF608;
IF607:
	local[25]= NIL;
IF608:
	local[25]= makeint(0);
	local[26]= local[14];
	local[27]= fqv[0];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= local[14];
	local[28]= fqv[1];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,2,local+27); /*send*/
	local[27]= w;
	ctx->vsp=local+28;
	local[28]= makeclosure(codevec,quotevec,CLO613,env,argv,local);
	local[29]= local[11];
	ctx->vsp=local+30;
	w=(pointer)MAPCAR(ctx,2,local+28); /*mapcar*/
	local[15] = w;
	local[25]= fqv[26];
	local[26]= (pointer)get_sym_func(fqv[27]);
	ctx->vsp=local+27;
	w=(*ftab[6])(ctx,2,local+25,&ftab[6],fqv[28]); /*make-hash-table*/
	local[16] = w;
	local[25]= makeint(0);
	local[26]= makeint(6);
WHL615:
	local[27]= local[25];
	w = local[26];
	if ((integer_t)local[27] >= (integer_t)w) goto WHX616;
	local[27]= local[10];
	local[28]= local[25];
	ctx->vsp=local+29;
	w=(pointer)ELT(ctx,2,local+27); /*elt*/
	local[27]= w;
	local[28]= local[15];
	local[29]= local[25];
	ctx->vsp=local+30;
	w=(pointer)ELT(ctx,2,local+28); /*elt*/
	local[28]= w;
	local[29]= local[27];
	local[30]= fqv[29];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,2,local+29); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[29]= (w)->c.cons.cdr;
	if (local[28]==NIL) goto IF618;
	local[30]= makeint(0);
	local[31]= makeint(4);
WHL621:
	local[32]= local[30];
	w = local[31];
	if ((integer_t)local[32] >= (integer_t)w) goto WHX622;
	local[32]= local[29];
	local[33]= local[30];
	ctx->vsp=local+34;
	w=(pointer)ELT(ctx,2,local+32); /*elt*/
	local[32]= w;
	local[33]= local[29];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,2,local+32); /*list*/
	local[32]= w;
	local[33]= local[16];
	local[34]= local[28];
	local[35]= local[30];
	ctx->vsp=local+36;
	w=(pointer)ELT(ctx,2,local+34); /*elt*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(*ftab[7])(ctx,3,local+32,&ftab[7],fqv[30]); /*sethash*/
	local[30] = (pointer)((integer_t)(local[30])+4);
	goto WHL621;
WHX622:
	local[32]= NIL;
BLK623:
	w = NIL;
	local[30]= w;
	goto IF619;
IF618:
	local[30]= NIL;
IF619:
	w = local[30];
	local[25] = (pointer)((integer_t)(local[25])+4);
	goto WHL615;
WHX616:
	local[27]= NIL;
BLK617:
	w = NIL;
	local[25]= local[9];
	local[26]= fqv[31];
	ctx->vsp=local+27;
	w=(pointer)GENSYM(ctx,1,local+26); /*gensym*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(*ftab[8])(ctx,1,local+26,&ftab[8],fqv[32]); /*symbol-string*/
	local[26]= w;
	local[27]= fqv[33];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[0];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[34];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[1];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[35];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[2];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[36];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[3];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[37];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[16];
	local[27]= fqv[38];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	w = local[9];
	local[0]= w;
BLK585:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO600(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF624;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F533(ctx,1,local+0); /*load-texture-file*/
	local[0]= w;
	goto IF625;
IF624:
	local[0]= NIL;
IF625:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO613(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF626;
	local[0]= env->c.clo.env2[12];
	local[1]= argv[0];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= env->c.clo.env2[13];
	local[2]= argv[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	local[2]= w;
	local[3]= env->c.clo.env2[26];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= env->c.clo.env2[25];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= env->c.clo.env2[27];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= env->c.clo.env2[26];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= env->c.clo.env2[25];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)EUSFLOAT(ctx,1,local+4); /*float*/
	local[4]= w;
	local[5]= env->c.clo.env2[27];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,2,local+3); /*float-vector*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)EUSFLOAT(ctx,1,local+4); /*float*/
	local[4]= w;
	local[5]= env->c.clo.env2[26];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= env->c.clo.env2[25];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= env->c.clo.env2[27];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,2,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= env->c.clo.env2[26];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= env->c.clo.env2[25];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)EUSFLOAT(ctx,1,local+6); /*float*/
	local[6]= w;
	local[7]= env->c.clo.env2[27];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	local[3]= env->c.clo.env2[25];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	env->c.clo.env2[25] = w;
	w = local[2];
	local[0]= w;
	goto IF627;
IF626:
	local[0]= NIL;
IF627:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___gltexture(ctx,n,argv,env)
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
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF629;
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[41],w);
	goto IF630;
IF629:
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF630:
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[44],module,F532,fqv[45]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F533,fqv[47]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F534,fqv[48]);
	local[0]= fqv[49];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F535,fqv[51]);
	local[0]= fqv[52];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[54]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
