/* compose.c :  entry=compose */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "compose.h"
#pragma init (register_compose)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___compose();
extern pointer build_quote_vector();
static register_compose()
  { add_module_initializer("___compose", ___compose);}

static pointer F2387();
static pointer F2388();
static pointer F2389();
static pointer F2390();
static pointer F2391();
static pointer F2392();
static pointer F2393();
static pointer F2394();
static pointer F2395();
static pointer F2396();
static pointer F2397();
static pointer F2398();
static pointer F2399();
static pointer F2400();
static pointer F2401();
static pointer F2402();
static pointer F2403();
static pointer F2404();
static pointer F2405();
static pointer F2406();
static pointer F2407();
static pointer F2408();
static pointer F2409();
static pointer F2410();
static pointer F2411();
static pointer F2412();
static pointer F2413();
static pointer F2414();
static pointer F2415();

/*intersecting-edges*/
static pointer F2387(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL2419:
	if (local[3]==NIL) goto WHX2420;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto IF2423;
	local[4]= makeflt(0.00000000e+00);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= makeflt(1.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)LSEQP(ctx,3,local+4); /*<=*/
	if (w==NIL) goto IF2423;
	local[4]= local[2];
	w = local[1];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= local[0];
	goto IF2424;
IF2423:
	local[4]= NIL;
IF2424:
	goto WHL2419;
WHX2420:
	local[4]= NIL;
BLK2421:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2417:
	ctx->vsp=local; return(local[0]);}

/*cut-body*/
static pointer F2388(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= argv[0];
	local[9]= fqv[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F2387(ctx,2,local+7); /*intersecting-edges*/
	local[1] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F2392(ctx,1,local+7); /*sort-edges-by-face*/
	local[0] = w;
	local[7]= NIL;
	local[8]= local[0];
WHL2427:
	if (local[8]==NIL) goto WHX2428;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[2]); /*oddp*/
	if (w==NIL) goto IF2431;
	local[9]= fqv[3];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF2432;
IF2431:
	local[9]= NIL;
IF2432:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	local[9]= local[5];
	local[10]= fqv[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= argv[1];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+9); /*v**/
	local[3] = w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,1,local+9,&ftab[1],fqv[5]); /*maxindex*/
	local[2] = w;
	local[9]= local[1];
	local[10]= local[3];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	local[11]= makeflt(0.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)GREATERP(ctx,2,local+10); /*>*/
	if (w==NIL) goto IF2433;
	local[10]= (pointer)get_sym_func(fqv[6]);
	goto IF2434;
IF2433:
	local[10]= (pointer)get_sym_func(fqv[7]);
IF2434:
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO2435,env,argv,local);
	ctx->vsp=local+12;
	w=(pointer)SORT(ctx,3,local+9); /*sort*/
	local[1] = w;
WHL2436:
	if (local[1]==NIL) goto WHX2437;
	local[9]= loadglobal(fqv[8]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[9];
	local[12]= fqv[10];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[11];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[12];
	local[17]= argv[1];
	local[18]= fqv[13];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,10,local+10); /*send*/
	w = local[9];
	local[9]= w;
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	goto WHL2436;
WHX2437:
	local[9]= NIL;
BLK2438:
	goto WHL2427;
WHX2428:
	local[9]= NIL;
BLK2429:
	w = NIL;
	local[7]= argv[1];
	w = local[4];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)F2397(ctx,1,local+7); /*construct-faces*/
	local[0]= w;
BLK2425:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2435(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*insert-intersections*/
static pointer F2389(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET2441,env,argv,local);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[1];
WHL2443:
	if (local[5]==NIL) goto WHX2444;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[14];
	local[8]= makeflt(9.99999791e-03);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[15];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF2447;
	local[6]= NIL;
	local[7]= argv[0];
WHL2450:
	if (local[7]==NIL) goto WHX2451;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[4];
	local[9]= fqv[0];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
	w = local[1];
	if (!iscons(w)) goto IF2454;
	local[8]= local[4];
	local[9]= fqv[16];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	if (w!=NIL) goto IF2454;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
WHL2456:
	if (local[3]==NIL) goto WHX2457;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2460;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[4];
	w = local[0];
	ctx->vsp=local+11;
	w=FLET2441(ctx,3,local+8,w);
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2458;
	goto CON2459;
CON2460:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2461;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto IF2462;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[4];
	w = local[0];
	ctx->vsp=local+11;
	w=FLET2441(ctx,3,local+8,w);
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2458;
	goto IF2463;
IF2462:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
IF2463:
	goto CON2459;
CON2461:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto CON2465;
	local[8]= local[3];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)RPLACD(ctx,2,local+8); /*rplacd*/
	local[8]= local[3];
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NCONC(ctx,2,local+9); /*nconc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RPLACA(ctx,2,local+8); /*rplaca*/
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2458;
	goto CON2459;
CON2465:
	local[8]= NIL;
CON2459:
	goto WHL2456;
WHX2457:
	local[8]= NIL;
BLK2458:
	goto IF2455;
IF2454:
	local[8]= NIL;
IF2455:
	goto WHL2450;
WHX2451:
	local[8]= NIL;
BLK2452:
	w = argv[0];
	local[6]= w;
	goto IF2448;
IF2447:
	local[6]= NIL;
IF2448:
	goto WHL2443;
WHX2444:
	local[6]= NIL;
BLK2445:
	w = NIL;
	local[0]= w;
BLK2440:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2441(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2466;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto IF2467;
IF2466:
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF2468;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)RPLACA(ctx,2,local+1); /*rplaca*/
	local[1]= w;
	goto IF2469;
IF2468:
	local[1]= NIL;
IF2469:
	w = local[1];
	local[0]= w;
IF2467:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-edge-segments*/
static pointer F2390(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
WHL2472:
	if (local[10]==NIL) goto WHX2473;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[11];
	local[6] = w;
WHL2477:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2478;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[11];
	local[3] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[11]= makeflt(5.00000000e-01);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,4,local+11,&ftab[3],fqv[19]); /*midpoint*/
	local[11]= argv[1];
	local[12]= fqv[20];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[5] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	local[11]= local[5];
	if (argv[2]==local[11]) goto OR2483;
	local[11]= local[5];
	if (fqv[21]==local[11]) goto OR2483;
	goto IF2481;
OR2483:
	local[11]= loadglobal(fqv[8]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[9];
	local[14]= fqv[10];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[11];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	local[18]= fqv[12];
	local[19]= local[6]->c.obj.iv[3];
	local[20]= fqv[13];
	local[21]= local[6]->c.obj.iv[4];
	local[22]= fqv[22];
	local[23]= local[6]->c.obj.iv[6];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,12,local+12); /*send*/
	w = local[11];
	local[1] = w;
	local[11]= local[6];
	local[12]= local[1];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[5];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,7,local+11); /*list*/
	local[11]= w;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[0];
	goto IF2482;
IF2481:
	local[11]= NIL;
IF2482:
	goto WHL2477;
WHX2478:
	local[11]= NIL;
BLK2479:
	goto WHL2472;
WHX2473:
	local[11]= NIL;
BLK2474:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2470:
	ctx->vsp=local; return(local[0]);}

/*intersecting-segments*/
static pointer F2391(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2486,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2485:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2486(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=NIL) goto OR2489;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[23]); /*fourth*/
	if (w!=NIL) goto OR2489;
	goto IF2487;
OR2489:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[24]); /*fifth*/
	local[0]= w;
	if (fqv[21]==local[0]) goto IF2487;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2488;
IF2487:
	local[0]= NIL;
IF2488:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*sort-edges-by-face*/
static pointer F2392(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL2492:
	if (local[5]==NIL) goto WHX2493;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[6]= local[3]->c.obj.iv[3];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	local[1] = w;
	if (local[1]!=NIL) goto IF2496;
	local[6]= local[3]->c.obj.iv[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[0];
	goto IF2497;
IF2496:
	local[6]= local[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
IF2497:
	local[6]= local[3]->c.obj.iv[4];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	local[1] = w;
	if (local[1]!=NIL) goto IF2498;
	local[6]= local[3]->c.obj.iv[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[0];
	goto IF2499;
IF2498:
	local[6]= local[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
IF2499:
	goto WHL2492;
WHX2493:
	local[6]= NIL;
BLK2494:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2490:
	ctx->vsp=local; return(local[0]);}

/*make-crossing-edges*/
static pointer F2393(ctx,n,argv,env)
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
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= argv[0];
WHL2502:
	if (local[18]==NIL) goto WHX2503;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	w = local[17];
	if (iscons(w)) goto IF2506;
	local[19]= fqv[25];
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(pointer)SIGERROR(ctx,2,local+19); /*error*/
	local[19]= w;
	goto IF2507;
IF2506:
	local[19]= NIL;
IF2507:
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	local[19]= local[0];
	local[20]= fqv[4];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[13] = w;
	local[1] = NIL;
	local[19]= NIL;
	local[20]= local[2];
WHL2509:
	if (local[20]==NIL) goto WHX2510;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w = local[19];
	if (iscons(w)) goto IF2513;
	local[21]= fqv[26];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)SIGERROR(ctx,2,local+21); /*error*/
	local[21]= w;
	goto IF2514;
IF2513:
	local[21]= NIL;
IF2514:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF2515;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto IF2515;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[1];
	goto IF2516;
IF2515:
	local[21]= NIL;
IF2516:
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	if (w==NIL) goto IF2517;
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	local[21]= w;
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto IF2517;
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	local[21]= w;
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[1];
	goto IF2518;
IF2517:
	local[21]= NIL;
IF2518:
	goto WHL2509;
WHX2510:
	local[21]= NIL;
BLK2511:
	w = NIL;
	local[19]= NIL;
	local[20]= local[1];
WHL2520:
	if (local[20]==NIL) goto WHX2521;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[9] = NIL;
	local[10] = NIL;
	local[21]= NIL;
	local[22]= local[2];
WHL2525:
	if (local[22]==NIL) goto WHX2526;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	if (local[19]!=local[23]) goto CON2530;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[7])(ctx,1,local+23,&ftab[7],fqv[28]); /*sixth*/
	local[23]= w;
	local[24]= makeflt(0.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2530;
	local[23]= local[4]->c.obj.iv[1];
	w = local[9];
	ctx->vsp=local+24;
	local[9] = cons(ctx,local[23],w);
	local[23]= local[9];
	goto CON2529;
CON2530:
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[4])(ctx,1,local+23,&ftab[4],fqv[23]); /*fourth*/
	local[23]= w;
	if (local[19]!=local[23]) goto CON2531;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[9])(ctx,1,local+23,&ftab[9],fqv[30]); /*seventh*/
	local[23]= w;
	local[24]= makeflt(1.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2531;
	local[23]= local[4]->c.obj.iv[2];
	w = local[9];
	ctx->vsp=local+24;
	local[9] = cons(ctx,local[23],w);
	local[23]= local[9];
	goto CON2529;
CON2531:
	local[23]= NIL;
CON2529:
	goto WHL2525;
WHX2526:
	local[23]= NIL;
BLK2527:
	w = NIL;
	local[21]= NIL;
	local[22]= local[19];
	local[23]= argv[1];
	ctx->vsp=local+24;
	w=(pointer)ASSQ(ctx,2,local+22); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
WHL2533:
	if (local[22]==NIL) goto WHX2534;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	if (local[0]!=local[23]) goto CON2538;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[7])(ctx,1,local+23,&ftab[7],fqv[28]); /*sixth*/
	local[23]= w;
	local[24]= makeflt(0.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2538;
	local[23]= local[4]->c.obj.iv[1];
	w = local[10];
	ctx->vsp=local+24;
	local[10] = cons(ctx,local[23],w);
	local[23]= local[10];
	goto CON2537;
CON2538:
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[4])(ctx,1,local+23,&ftab[4],fqv[23]); /*fourth*/
	local[23]= w;
	if (local[0]!=local[23]) goto CON2539;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[9])(ctx,1,local+23,&ftab[9],fqv[30]); /*seventh*/
	local[23]= w;
	local[24]= makeflt(1.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2539;
	local[23]= local[4]->c.obj.iv[2];
	w = local[10];
	ctx->vsp=local+24;
	local[10] = cons(ctx,local[23],w);
	local[23]= local[10];
	goto CON2537;
CON2539:
	local[23]= NIL;
CON2537:
	goto WHL2533;
WHX2534:
	local[23]= NIL;
BLK2535:
	w = NIL;
	local[21]= *(ovafptr(local[19],fqv[31]));
	local[22]= *(ovafptr(local[0],fqv[31]));
	ctx->vsp=local+23;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+21); /*v**/
	local[5] = w;
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[1])(ctx,1,local+21,&ftab[1],fqv[5]); /*maxindex*/
	local[6] = w;
	local[21]= argv[3];
	if (fqv[32]!=local[21]) goto IF2540;
	local[21]= local[5];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)AREF(ctx,2,local+21); /*aref*/
	local[21]= w;
	local[22]= makeflt(0.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,2,local+21); /*<*/
	if (w==NIL) goto IF2542;
	local[21]= (pointer)get_sym_func(fqv[33]);
	goto IF2543;
IF2542:
	local[21]= (pointer)get_sym_func(fqv[34]);
IF2543:
	goto IF2541;
IF2540:
	local[21]= local[5];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)AREF(ctx,2,local+21); /*aref*/
	local[21]= w;
	local[22]= makeflt(0.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,2,local+21); /*<*/
	if (w==NIL) goto IF2544;
	local[21]= (pointer)get_sym_func(fqv[34]);
	goto IF2545;
IF2544:
	local[21]= (pointer)get_sym_func(fqv[33]);
IF2545:
IF2541:
	local[7] = local[21];
	local[21]= local[9];
	local[22]= local[10];
	ctx->vsp=local+23;
	w=(pointer)APPEND(ctx,2,local+21); /*append*/
	local[21]= w;
	local[22]= local[7];
	ctx->vsp=local+23;
	local[23]= makeclosure(codevec,quotevec,CLO2546,env,argv,local);
	ctx->vsp=local+24;
	w=(pointer)SORT(ctx,3,local+21); /*sort*/
	local[8] = w;
	local[21]= local[8];
	local[22]= fqv[35];
	local[23]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+24;
	w=(*ftab[10])(ctx,3,local+21,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[8] = w;
	local[14] = NIL;
WHL2547:
	if (local[8]==NIL) goto WHX2548;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[21];
	local[11] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[21];
	local[12] = w;
	if (local[11]==NIL) goto IF2552;
	if (local[12]==NIL) goto IF2552;
	local[21]= local[0];
	local[22]= fqv[38];
	local[23]= makeflt(5.00000000e-01);
	local[24]= local[11];
	local[25]= local[12];
	ctx->vsp=local+26;
	w=(*ftab[3])(ctx,3,local+23,&ftab[3],fqv[19]); /*midpoint*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	if (w!=NIL) goto IF2552;
	local[21]= local[19];
	local[22]= fqv[38];
	local[23]= makeflt(5.00000000e-01);
	local[24]= local[11];
	local[25]= local[12];
	ctx->vsp=local+26;
	w=(*ftab[3])(ctx,3,local+23,&ftab[3],fqv[19]); /*midpoint*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	if (w!=NIL) goto IF2552;
	if (argv[2]!=NIL) goto OR2554;
	local[21]= local[11];
	w = local[9];
	if (memq(local[21],w)==NIL) goto AND2555;
	local[21]= local[12];
	w = local[9];
	if (memq(local[21],w)==NIL) goto AND2555;
	goto OR2554;
AND2555:
	goto IF2552;
OR2554:
	local[21]= loadglobal(fqv[8]);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,1,local+21); /*instantiate*/
	local[21]= w;
	local[22]= local[21];
	local[23]= fqv[9];
	local[24]= fqv[10];
	local[25]= local[11];
	local[26]= fqv[11];
	local[27]= local[12];
	local[28]= fqv[12];
	local[29]= local[0];
	local[30]= fqv[13];
	local[31]= local[19];
	local[32]= fqv[39];
	local[33]= NIL;
	ctx->vsp=local+34;
	w=(pointer)SEND(ctx,12,local+22); /*send*/
	w = local[21];
	local[4] = w;
	local[21]= local[4];
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto IF2553;
IF2552:
	local[21]= NIL;
IF2553:
	goto WHL2547;
WHX2548:
	local[21]= NIL;
BLK2549:
	if (local[14]==NIL) goto IF2557;
	local[21]= local[0];
	w = local[14];
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	w = local[15];
	ctx->vsp=local+22;
	local[15] = cons(ctx,local[21],w);
	local[21]= local[19];
	local[22]= local[14];
	ctx->vsp=local+23;
	w=(pointer)COPYSEQ(ctx,1,local+22); /*copy-seq*/
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	goto IF2558;
IF2557:
	local[21]= NIL;
IF2558:
	goto WHL2520;
WHX2521:
	local[21]= NIL;
BLK2522:
	w = NIL;
	goto WHL2502;
WHX2503:
	local[19]= NIL;
BLK2504:
	w = NIL;
	local[17]= local[15];
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,2,local+17); /*list*/
	local[0]= w;
BLK2500:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2546(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[6];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*add-alist*/
static pointer F2394(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]!=NIL) goto IF2560;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,3,local+1,&ftab[11],fqv[40]); /*acons*/
	local[1]= w;
	goto IF2561;
IF2560:
	local[1]= local[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	local[1]= argv[2];
IF2561:
	w = local[1];
	local[0]= w;
BLK2559:
	ctx->vsp=local; return(local[0]);}

/*merge-segments*/
static pointer F2395(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
WHL2564:
	if (local[1]==NIL) goto WHX2565;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= (pointer)get_sym_func(fqv[41]);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)RPLACD(ctx,2,local+2); /*rplacd*/
	goto WHL2564;
WHX2565:
	local[2]= NIL;
BLK2566:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[1];
WHL2569:
	if (local[1]==NIL) goto WHX2570;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F2394(ctx,3,local+2); /*add-alist*/
	argv[0] = w;
	goto WHL2569;
WHX2570:
	local[2]= NIL;
BLK2571:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[2];
WHL2574:
	if (local[1]==NIL) goto WHX2575;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F2394(ctx,3,local+2); /*add-alist*/
	argv[0] = w;
	goto WHL2574;
WHX2575:
	local[2]= NIL;
BLK2576:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK2562:
	ctx->vsp=local; return(local[0]);}

/*find-connecting-edge*/
static pointer F2396(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2580;}
	local[0]= (pointer)get_sym_func(fqv[42]);
ENT2580:
ENT2579:
	if (n>3) maerror();
	local[1]= local[0];
	if ((pointer)get_sym_func(fqv[42])!=local[1]) goto IF2581;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2583,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[43]); /*find-if*/
	local[1]= w;
	goto IF2582;
IF2581:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2584,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[43]); /*find-if*/
	local[1]= w;
IF2582:
	w = local[1];
	local[0]= w;
BLK2578:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2583(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((env->c.clo.env1[0])==(local[0])?T:NIL);
	if (local[0]!=NIL) goto OR2585;
	local[0]= argv[0]->c.obj.iv[2];
	local[0]= ((env->c.clo.env1[0])==(local[0])?T:NIL);
OR2585:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2584(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,3,local+0); /*funcall*/
	local[0]= w;
	if (w!=NIL) goto OR2586;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
OR2586:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*construct-faces*/
static pointer F2397(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	storeglobal(fqv[44],w);
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2588:
	if (local[4]==NIL) goto WHX2589;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[10];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	local[8]= NIL;
	local[9]= NIL;
	local[10]= loadglobal(fqv[45]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= NIL;
WHL2592:
	if (local[5]==NIL) goto WHX2593;
	local[12]= local[5];
	local[13]= fqv[11];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[8] = w;
	local[12]= local[5];
	local[13]= fqv[46];
	local[14]= local[7];
	local[15]= local[8];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	local[12]= local[5];
	w = local[9];
	ctx->vsp=local+13;
	local[9] = cons(ctx,local[12],w);
	local[12]= local[5];
	local[13]= local[4];
	local[14]= fqv[47];
	local[15]= makeint(1);
	ctx->vsp=local+16;
	w=(*ftab[13])(ctx,4,local+12,&ftab[13],fqv[48]); /*delete*/
	local[4] = w;
	local[12]= local[8];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)F2396(ctx,2,local+12); /*find-connecting-edge*/
	local[5] = w;
	local[7] = local[8];
	goto WHL2592;
WHX2593:
	local[12]= NIL;
BLK2594:
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)NREVERSE(ctx,1,local+12); /*nreverse*/
	local[9] = w;
	local[12]= local[3];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(*ftab[14])(ctx,2,local+12,&ftab[14],fqv[50]); /*find-method*/
	if (w==NIL) goto IF2595;
	local[12]= local[3];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[11] = w;
	local[12]= local[11];
	goto IF2596;
IF2595:
	local[12]= NIL;
IF2596:
	local[12]= local[10];
	local[13]= fqv[9];
	local[14]= fqv[1];
	local[15]= local[9];
	local[16]= fqv[49];
	local[17]= local[11];
	local[18]= fqv[51];
	if (local[11]==NIL) goto IF2597;
	local[19]= local[11];
	local[20]= fqv[51];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	goto IF2598;
IF2597:
	local[19]= NIL;
IF2598:
	local[20]= fqv[52];
	local[21]= local[3];
	local[22]= fqv[52];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,10,local+12); /*send*/
	local[12]= local[3];
	local[13]= fqv[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[10];
	local[14]= fqv[4];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)VINNERPRODUCT(ctx,2,local+12); /*v.*/
	local[12]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[12]);
	if (left >= right) goto CON2600;}
	local[12]= local[10];
	w = local[9];
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	w = local[1];
	ctx->vsp=local+13;
	local[1] = cons(ctx,local[12],w);
	local[12]= local[1];
	goto CON2599;
CON2600:
	local[12]= local[10];
	w = local[0];
	ctx->vsp=local+13;
	local[0] = cons(ctx,local[12],w);
	local[12]= local[0];
	goto CON2599;
CON2601:
	local[12]= NIL;
CON2599:
	w = local[12];
	goto WHL2588;
WHX2589:
	local[5]= NIL;
BLK2590:
	if (local[1]==NIL) goto IF2602;
	if (loadglobal(fqv[53])==NIL) goto IF2604;
	local[5]= T;
	local[6]= fqv[54];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	goto IF2605;
IF2604:
	local[5]= NIL;
IF2605:
	local[5]= NIL;
	local[6]= local[1];
WHL2607:
	if (local[6]==NIL) goto WHX2608;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= NIL;
	local[8]= local[0];
WHL2613:
	if (local[8]==NIL) goto WHX2614;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[20];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= *(ovafptr((w)->c.cons.car,fqv[55]));
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	if (fqv[56]!=local[9]) goto IF2617;
	local[9]= NIL;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
WHL2620:
	if (local[10]==NIL) goto WHX2621;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= fqv[46];
	local[13]= local[9];
	local[14]= fqv[10];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	local[14]= local[9];
	local[15]= fqv[11];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	goto WHL2620;
WHX2621:
	local[11]= NIL;
BLK2622:
	w = NIL;
	local[9]= loadglobal(fqv[57]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[9];
	local[12]= fqv[1];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	local[14]= fqv[58];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,6,local+10); /*send*/
	w = local[9];
	local[2] = w;
	local[9]= local[7];
	local[10]= fqv[59];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = NIL;
	ctx->vsp=local+9;
	local[7]=w;
	goto BLK2611;
	goto IF2618;
IF2617:
	local[9]= NIL;
IF2618:
	goto WHL2613;
WHX2614:
	local[9]= NIL;
BLK2615:
	w = NIL;
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	storeglobal(fqv[60],w);
	local[7]= fqv[61];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
BLK2611:
	goto WHL2607;
WHX2608:
	local[7]= NIL;
BLK2609:
	w = NIL;
	local[5]= w;
	goto IF2603;
IF2602:
	local[5]= NIL;
IF2603:
	w = local[0];
	local[0]= w;
BLK2587:
	ctx->vsp=local; return(local[0]);}

/*initial-intersection-list*/
static pointer F2398(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
WHL2627:
	if (local[3]==NIL) goto WHX2628;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= makeflt(0.00000000e+00);
	local[6]= local[2]->c.obj.iv[1];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,2,local+6,&ftab[15],fqv[62]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	local[6]= makeflt(1.00000000e+00);
	local[7]= local[2]->c.obj.iv[2];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(*ftab[15])(ctx,2,local+7,&ftab[15],fqv[62]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL2627;
WHX2628:
	local[4]= NIL;
BLK2629:
	w = local[1];
	local[0]= w;
BLK2625:
	ctx->vsp=local; return(local[0]);}

/*make-vertex-edge-htab*/
static pointer F2399(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[63]); /*bodyp*/
	if (w==NIL) goto CON2633;
	local[1] = argv[0]->c.obj.iv[11];
	local[0] = argv[0]->c.obj.iv[10];
	local[5]= local[0];
	goto CON2632;
CON2633:
	local[5]= (pointer)get_sym_func(fqv[64]);
	local[6]= argv[0];
	local[7]= fqv[65];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[66]); /*send-all*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[1] = w;
	local[5]= (pointer)get_sym_func(fqv[64]);
	local[6]= argv[0];
	local[7]= fqv[67];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[66]); /*send-all*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[0] = w;
	local[5]= local[0];
	goto CON2632;
CON2634:
	local[5]= NIL;
CON2632:
	local[5]= fqv[68];
	local[6]= makeint(2);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	{ integer_t i,j;
		j=intval(w); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	local[6]= (pointer)((integer_t)(local[6])+4);
	ctx->vsp=local+7;
	w=(*ftab[18])(ctx,2,local+5,&ftab[18],fqv[69]); /*make-hash-table*/
	local[2] = w;
	local[5]= NIL;
	local[6]= local[0];
WHL2636:
	if (local[6]==NIL) goto WHX2637;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[3] = local[5]->c.obj.iv[1];
	local[4] = local[5]->c.obj.iv[2];
	local[7]= local[3];
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[3];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[62]); /*gethash*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[70]); /*sethash*/
	local[7]= local[4];
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[4];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[62]); /*gethash*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[70]); /*sethash*/
	goto WHL2636;
WHX2637:
	local[7]= NIL;
BLK2638:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK2631:
	ctx->vsp=local; return(local[0]);}

/*copy-add-vertex*/
static pointer F2400(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2641,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[71]); /*maphash*/
	local[0]= w;
BLK2640:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2641(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	w = argv[1];
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,3,local+0,&ftab[19],fqv[70]); /*sethash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-colinear-int*/
static pointer F2401(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL2644:
	if (local[2]==NIL) goto WHX2645;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2649:
	if (local[4]==NIL) goto WHX2650;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[72];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto IF2653;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,2,local+5); /*list**/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2654;
IF2653:
	local[5]= NIL;
IF2654:
	goto WHL2649;
WHX2650:
	local[5]= NIL;
BLK2651:
	w = NIL;
	goto WHL2644;
WHX2645:
	local[3]= NIL;
BLK2646:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2642:
	ctx->vsp=local; return(local[0]);}

/*contacting-faces*/
static pointer F2402(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= loadglobal(fqv[73]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF2656;
	local[0] = argv[0]->c.obj.iv[9];
	local[8]= local[0];
	goto IF2657;
IF2656:
	local[8]= NIL;
IF2657:
	local[8]= argv[1];
	local[9]= loadglobal(fqv[73]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF2658;
	local[1] = argv[1]->c.obj.iv[9];
	local[8]= local[1];
	goto IF2659;
IF2658:
	local[8]= NIL;
IF2659:
	local[8]= NIL;
	local[9]= local[0];
WHL2661:
	if (local[9]==NIL) goto WHX2662;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= local[1];
WHL2666:
	if (local[11]==NIL) goto WHX2667;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[8];
	local[13]= fqv[74];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto IF2670;
	local[12]= (pointer)get_sym_func(fqv[75]);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[6] = w;
	local[12]= (pointer)get_sym_func(fqv[75]);
	local[13]= (pointer)get_sym_func(fqv[64]);
	local[14]= (pointer)get_sym_func(fqv[76]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,2,local+14); /*mapcar*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,2,local+13); /*apply*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[10])(ctx,1,local+12,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[7] = w;
	local[12]= local[2];
	w = fqv[77];
	if (memq(local[12],w)==NIL) goto CON2673;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2672;
CON2673:
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint(1)==local[12]) goto OR2675;
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint(1)==local[12]) goto OR2675;
	goto CON2674;
OR2675:
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)F2401(ctx,1,local+12); /*find-colinear-int*/
	local[4] = w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint(1)!=local[12]) goto IF2676;
	local[12]= T;
	local[13]= fqv[78];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[23]); /*fourth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(0.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2679;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[23]); /*fourth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2679;
	local[12]= local[10];
	local[13]= fqv[20];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[79];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[56];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w==NIL) goto CON2679;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2678;
CON2679:
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,1,local+12,&ftab[5],fqv[24]); /*fifth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(0.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2680;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,1,local+12,&ftab[5],fqv[24]); /*fifth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2680;
	local[12]= local[8];
	local[13]= fqv[20];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[79];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[56];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w==NIL) goto CON2680;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2678;
CON2680:
	local[12]= NIL;
CON2678:
	goto IF2677;
IF2676:
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
IF2677:
	goto CON2672;
CON2674:
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2672;
CON2681:
	local[12]= NIL;
CON2672:
	goto IF2671;
IF2670:
	local[12]= NIL;
IF2671:
	goto WHL2666;
WHX2667:
	local[12]= NIL;
BLK2668:
	w = NIL;
	goto WHL2661;
WHX2662:
	local[10]= NIL;
BLK2663:
	w = NIL;
	w = local[5];
	local[0]= w;
BLK2655:
	ctx->vsp=local; return(local[0]);}

/*aligned-faces*/
static pointer F2403(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[0];
	local[8]= loadglobal(fqv[73]);
	ctx->vsp=local+9;
	w=(pointer)DERIVEDP(ctx,2,local+7); /*derivedp*/
	if (w==NIL) goto IF2683;
	local[0] = argv[0]->c.obj.iv[9];
	local[7]= local[0];
	goto IF2684;
IF2683:
	local[7]= NIL;
IF2684:
	local[7]= argv[1];
	local[8]= loadglobal(fqv[73]);
	ctx->vsp=local+9;
	w=(pointer)DERIVEDP(ctx,2,local+7); /*derivedp*/
	if (w==NIL) goto IF2685;
	local[1] = argv[1]->c.obj.iv[9];
	local[7]= local[1];
	goto IF2686;
IF2685:
	local[7]= NIL;
IF2686:
	local[7]= NIL;
	local[8]= local[0];
WHL2688:
	if (local[8]==NIL) goto WHX2689;
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
WHL2693:
	if (local[10]==NIL) goto WHX2694;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= fqv[80];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto IF2697;
	local[11]= local[7];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[11]= w;
	w = local[4];
	ctx->vsp=local+12;
	local[4] = cons(ctx,local[11],w);
	local[11]= local[4];
	goto IF2698;
IF2697:
	local[11]= NIL;
IF2698:
	goto WHL2693;
WHX2694:
	local[11]= NIL;
BLK2695:
	w = NIL;
	goto WHL2688;
WHX2689:
	local[9]= NIL;
BLK2690:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK2682:
	ctx->vsp=local; return(local[0]);}

/*find-equivalent-edge*/
static pointer F2404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL2701:
	if (local[1]==NIL) goto WHX2702;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2708;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2708;
	goto OR2707;
AND2708:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2709;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2709;
	goto OR2707;
AND2709:
	goto IF2705;
OR2707:
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK2699;
	goto IF2706;
IF2705:
	local[2]= NIL;
IF2706:
	goto WHL2701;
WHX2702:
	local[2]= NIL;
BLK2703:
	w = NIL;
	local[0]= w;
BLK2699:
	ctx->vsp=local; return(local[0]);}

/*unify-vertex*/
static pointer F2405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[64]);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2711,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	local[1]= fqv[35];
	local[2]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,3,local+0,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL2713:
	if (local[2]==NIL) goto WHX2714;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= local[0];
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,4,local+3,&ftab[6],fqv[27]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[1] = local[4];
	local[3]= local[1]->c.obj.iv[2];
	local[4]= local[0];
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,4,local+3,&ftab[6],fqv[27]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[2] = local[4];
	goto WHL2713;
WHX2714:
	local[3]= NIL;
BLK2715:
	w = NIL;
	local[0]= w;
BLK2710:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2711(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*merge-edges-if-colinear*/
static pointer F2406(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]==NIL) goto IF2718;
	if (argv[1]==NIL) goto IF2718;
	local[0]= argv[0];
	local[1]= fqv[82];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF2718;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2721;
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[1] = local[1];
	goto CON2720;
CON2721:
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2722;
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[2] = local[1];
	goto CON2720;
CON2722:
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2723;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[1] = local[1];
	goto CON2720;
CON2723:
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2724;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[2] = local[1];
	goto CON2720;
CON2724:
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2717;
	goto CON2720;
CON2725:
	local[0]= NIL;
CON2720:
	local[0]= NIL;
	local[1]= argv[3];
WHL2727:
	if (local[1]==NIL) goto WHX2728;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[48]); /*delete*/
	goto WHL2727;
WHX2728:
	local[2]= NIL;
BLK2729:
	w = NIL;
	local[0]= argv[1];
	goto IF2719;
IF2718:
	local[0]= NIL;
IF2719:
	w = local[0];
	local[0]= w;
BLK2717:
	ctx->vsp=local; return(local[0]);}

/*merge-contacting-faces*/
static pointer F2407(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[83]); /*assoc*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[83]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL2733:
	if (local[9]==NIL) goto WHX2734;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)F2404(ctx,2,local+10); /*find-equivalent-edge*/
	local[2] = w;
	if (local[2]==NIL) goto CON2738;
	local[10]= local[2];
	local[11]= fqv[84];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	local[10]= local[8];
	local[11]= fqv[84];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[3];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[4];
	local[12]= fqv[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2740;
	local[10]= local[3];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[5] = w;
	local[10]= local[4];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[6] = w;
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8]->c.obj.iv[1];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)F2396(ctx,2,local+10); /*find-connecting-edge*/
	local[10]= w;
	local[11]= local[8]->c.obj.iv[2];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	ctx->vsp=local+13;
	w=(pointer)F2396(ctx,2,local+11); /*find-connecting-edge*/
	local[11]= w;
	local[12]= local[2]->c.obj.iv[1];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)F2396(ctx,2,local+12); /*find-connecting-edge*/
	local[12]= w;
	local[13]= local[2]->c.obj.iv[2];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.cdr;
	ctx->vsp=local+15;
	w=(pointer)F2396(ctx,2,local+13); /*find-connecting-edge*/
	local[13]= w;
	local[14]= local[12];
	local[15]= local[10];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2406(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[12];
	local[15]= local[11];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2406(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[13];
	local[15]= local[10];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2406(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[13];
	local[15]= local[11];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2406(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[10]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
WHL2742:
	if (local[11]==NIL) goto WHX2743;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10]->c.obj.iv[3];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w!=NIL) goto OR2748;
	local[12]= local[10]->c.obj.iv[4];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w!=NIL) goto OR2748;
	goto IF2746;
OR2748:
	local[12]= local[10];
	local[13]= fqv[85];
	local[14]= local[4];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	local[12]= w;
	goto IF2747;
IF2746:
	local[12]= NIL;
IF2747:
	goto WHL2742;
WHX2743:
	local[12]= NIL;
BLK2744:
	w = NIL;
	local[10]= local[5];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[6];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	argv[3] = w;
	local[10]= local[5];
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto CON2739;
CON2740:
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= fqv[85];
	local[12]= argv[0];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	goto CON2739;
CON2749:
	local[10]= NIL;
CON2739:
	goto CON2737;
CON2738:
	local[10]= argv[0];
	local[11]= fqv[20];
	local[12]= local[8];
	local[13]= fqv[86];
	local[14]= makeflt(5.00000000e-01);
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[32];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	local[10]= w;
	if (w!=NIL) goto CON2737;
CON2750:
	local[10]= local[8];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto CON2751;
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[0];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[8];
	local[11]= fqv[85];
	local[12]= argv[1];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	goto CON2737;
CON2751:
	local[10]= fqv[87];
	local[11]= argv[0];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[88]); /*warn*/
	local[10]= w;
	goto CON2737;
CON2752:
	local[10]= NIL;
CON2737:
	goto WHL2733;
WHX2734:
	local[10]= NIL;
BLK2735:
	w = NIL;
	local[8]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL2754:
	if (local[9]==NIL) goto WHX2755;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[1];
	local[11]= fqv[20];
	local[12]= local[8];
	local[13]= fqv[86];
	local[14]= makeflt(5.00000000e-01);
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[56];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON2759;
	local[10]= local[8];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[1];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[8];
	local[11]= fqv[85];
	local[12]= argv[0];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	local[11]= fqv[84];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[10]= w;
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto CON2758;
CON2759:
	local[10]= NIL;
CON2758:
	goto WHL2754;
WHX2755:
	local[10]= NIL;
BLK2756:
	w = NIL;
	local[8]= (pointer)get_sym_func(fqv[64]);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	local[11]= (pointer)get_sym_func(fqv[76]);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,4,local+8); /*apply*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F2405(ctx,1,local+8); /*unify-vertex*/
	w = argv[3];
	local[0]= w;
BLK2731:
	ctx->vsp=local; return(local[0]);}

/*merge-aligned-faces*/
static pointer F2408(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[83]); /*assoc*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[83]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	storeglobal(fqv[89],local[0]);
	local[6]= local[1];
	storeglobal(fqv[90],local[6]);
	if (loadglobal(fqv[53])==NIL) goto IF2761;
	local[6]= fqv[91];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,1,local+6,&ftab[24],fqv[92]); /*break*/
	local[6]= w;
	goto IF2762;
IF2761:
	local[6]= NIL;
IF2762:
	local[6]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2764:
	if (local[7]==NIL) goto WHX2765;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)F2404(ctx,2,local+8); /*find-equivalent-edge*/
	local[2] = w;
	if (local[2]==NIL) goto CON2769;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2768;
CON2769:
	local[8]= argv[0];
	local[9]= fqv[20];
	local[10]= local[6];
	local[11]= fqv[86];
	local[12]= makeflt(5.00000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2770;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2768;
CON2770:
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[0];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= local[6];
	local[9]= fqv[85];
	local[10]= argv[1];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto CON2768;
CON2771:
	local[8]= NIL;
CON2768:
	goto WHL2764;
WHX2765:
	local[8]= NIL;
BLK2766:
	w = NIL;
	local[6]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2773:
	if (local[7]==NIL) goto WHX2774;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[1];
	local[9]= fqv[20];
	local[10]= local[6];
	local[11]= fqv[86];
	local[12]= makeflt(5.00000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2778;
	local[8]= local[6];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2777;
CON2778:
	local[8]= NIL;
CON2777:
	goto WHL2773;
WHX2774:
	local[8]= NIL;
BLK2775:
	w = NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF2779;
	local[6]= fqv[93];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF2780;
IF2779:
	local[6]= NIL;
IF2780:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[4] = local[3];
WHL2781:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2782;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[6];
	local[2] = w;
	local[6]= NIL;
	local[7]= NIL;
TAG2786:
	local[7] = local[3];
TAG2787:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[6]!=NIL) goto CON2790;
	w = NIL;
	ctx->vsp=local+8;
	local[6]=w;
	goto BLK2785;
	goto CON2789;
CON2790:
	local[8]= local[2];
	local[9]= local[6];
	local[10]= argv[2];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(pointer)F2406(ctx,4,local+8); /*merge-edges-if-colinear*/
	if (w==NIL) goto CON2791;
	local[8]= local[6];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[3] = w;
	local[8]= NIL;
	local[9]= argv[2];
WHL2793:
	if (local[9]==NIL) goto WHX2794;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[6];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	goto WHL2793;
WHX2794:
	local[10]= NIL;
BLK2795:
	w = NIL;
	ctx->vsp=local+8;
	goto TAG2786;
	goto CON2789;
CON2791:
	ctx->vsp=local+8;
	goto TAG2787;
	goto CON2789;
CON2797:
	local[8]= NIL;
CON2789:
	w = NIL;
	local[6]= w;
BLK2785:
	goto WHL2781;
WHX2782:
	local[6]= NIL;
BLK2783:
	local[6]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2799:
	if (local[7]==NIL) goto WHX2800;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[84];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[4] = w;
	local[8]= local[4];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,2,local+8,&ftab[22],fqv[83]); /*assoc*/
	local[4] = w;
	if (local[4]==NIL) goto IF2803;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2804;
IF2803:
	local[8]= local[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,2,local+8,&ftab[22],fqv[83]); /*assoc*/
	local[4] = w;
	if (local[4]==NIL) goto IF2805;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2806;
IF2805:
	local[8]= NIL;
IF2806:
IF2804:
	goto WHL2799;
WHX2800:
	local[8]= NIL;
BLK2801:
	w = NIL;
	local[6]= (pointer)get_sym_func(fqv[64]);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,1,local+6,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F2405(ctx,1,local+6); /*unify-vertex*/
	if (loadglobal(fqv[53])==NIL) goto IF2807;
	local[6]= fqv[94];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,1,local+6,&ftab[24],fqv[92]); /*break*/
	local[6]= w;
	goto IF2808;
IF2807:
	local[6]= NIL;
IF2808:
	w = local[6];
	w = argv[3];
	local[0]= w;
BLK2760:
	ctx->vsp=local; return(local[0]);}

/*compose-body*/
static pointer F2409(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[1];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[50]); /*find-method*/
	if (w==NIL) goto IF2810;
	local[0]= argv[1];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2811;
IF2810:
	local[0]= NIL;
IF2811:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F2399(ctx,1,local+0); /*make-vertex-edge-htab*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F2399(ctx,1,local+1); /*make-vertex-edge-htab*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[96];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[96];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[1];
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[97];
	local[10]= argv[1];
	local[11]= makeflt(9.99999791e-03);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	local[23]= NIL;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[16] = w;
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)F2400(ctx,1,local+24); /*copy-add-vertex*/
	local[24]= local[1];
	ctx->vsp=local+25;
	w=(pointer)F2400(ctx,1,local+24); /*copy-add-vertex*/
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[17] = w;
	local[24]= local[4];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)F2398(ctx,2,local+24); /*initial-intersection-list*/
	local[6] = w;
	local[24]= local[5];
	local[25]= local[1];
	ctx->vsp=local+26;
	w=(pointer)F2398(ctx,2,local+24); /*initial-intersection-list*/
	local[7] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[18] = w;
	local[24]= local[6];
	local[25]= local[3];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(pointer)F2389(ctx,3,local+24); /*insert-intersections*/
	local[24]= local[7];
	local[25]= local[2];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(pointer)F2389(ctx,3,local+24); /*insert-intersections*/
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[19] = w;
	storeglobal(fqv[98],local[6]);
	local[24]= local[7];
	storeglobal(fqv[99],local[24]);
	local[24]= local[6];
	local[25]= argv[1];
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)F2390(ctx,3,local+24); /*make-edge-segments*/
	local[9] = w;
	local[24]= local[7];
	local[25]= argv[0];
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)F2390(ctx,3,local+24); /*make-edge-segments*/
	local[10] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[20] = w;
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(pointer)F2391(ctx,1,local+24); /*intersecting-segments*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)F2392(ctx,1,local+24); /*sort-edges-by-face*/
	local[6] = w;
	local[24]= local[10];
	ctx->vsp=local+25;
	w=(pointer)F2391(ctx,1,local+24); /*intersecting-segments*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)F2392(ctx,1,local+24); /*sort-edges-by-face*/
	local[7] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[21] = w;
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(pointer)F2392(ctx,1,local+24); /*sort-edges-by-face*/
	local[9] = w;
	local[24]= local[10];
	ctx->vsp=local+25;
	w=(pointer)F2392(ctx,1,local+24); /*sort-edges-by-face*/
	local[10] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[22] = w;
	local[24]= local[6];
	local[25]= local[10];
	local[26]= T;
	local[27]= argv[2];
	ctx->vsp=local+28;
	w=(pointer)F2393(ctx,4,local+24); /*make-crossing-edges*/
	local[12] = w;
	local[24]= local[7];
	local[25]= local[9];
	local[26]= NIL;
	local[27]= argv[2];
	ctx->vsp=local+28;
	w=(pointer)F2393(ctx,4,local+24); /*make-crossing-edges*/
	local[13] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	storeglobal(fqv[102],local[12]);
	local[24]= local[13];
	storeglobal(fqv[103],local[24]);
	if (loadglobal(fqv[53])==NIL) goto IF2812;
	local[24]= T;
	local[25]= fqv[104];
	ctx->vsp=local+26;
	w=(pointer)XFORMAT(ctx,2,local+24); /*format*/
	local[24]= fqv[105];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2813;
IF2812:
	local[24]= NIL;
IF2813:
	local[24]= local[9];
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)F2395(ctx,3,local+24); /*merge-segments*/
	local[9] = w;
	local[24]= local[10];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)F2395(ctx,3,local+24); /*merge-segments*/
	local[10] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	local[24]= argv[1];
	local[25]= loadglobal(fqv[73]);
	ctx->vsp=local+26;
	w=(pointer)DERIVEDP(ctx,2,local+24); /*derivedp*/
	if (w==NIL) goto IF2814;
	local[24]= argv[0];
	local[25]= argv[1];
	ctx->vsp=local+26;
	w=(pointer)F2402(ctx,2,local+24); /*contacting-faces*/
	local[14] = w;
	local[24]= local[14];
	goto IF2815;
IF2814:
	local[24]= NIL;
IF2815:
	if (local[14]==NIL) goto IF2816;
	local[24]= T;
	local[25]= fqv[106];
	local[26]= local[14];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)XFORMAT(ctx,3,local+24); /*format*/
	if (loadglobal(fqv[53])==NIL) goto IF2818;
	local[24]= fqv[107];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2819;
IF2818:
	local[24]= NIL;
IF2819:
	local[24]= NIL;
	local[25]= local[14];
WHL2821:
	if (local[25]==NIL) goto WHX2822;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	local[28]= local[9];
	local[29]= local[10];
	ctx->vsp=local+30;
	w=(pointer)F2407(ctx,4,local+26); /*merge-contacting-faces*/
	local[10] = w;
	goto WHL2821;
WHX2822:
	local[26]= NIL;
BLK2823:
	w = NIL;
	local[24]= w;
	goto IF2817;
IF2816:
	local[24]= NIL;
IF2817:
	local[24]= (pointer)get_sym_func(fqv[76]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(*ftab[25])(ctx,2,local+24,&ftab[25],fqv[108]); /*delete-if-not*/
	local[9] = w;
	local[24]= (pointer)get_sym_func(fqv[76]);
	local[25]= local[10];
	ctx->vsp=local+26;
	w=(*ftab[25])(ctx,2,local+24,&ftab[25],fqv[108]); /*delete-if-not*/
	local[10] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	local[24]= (pointer)get_sym_func(fqv[75]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(pointer)MAPCAR(ctx,2,local+24); /*mapcar*/
	local[24]= w;
	local[25]= (pointer)get_sym_func(fqv[75]);
	local[26]= local[10];
	ctx->vsp=local+27;
	w=(pointer)MAPCAR(ctx,2,local+25); /*mapcar*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)F2403(ctx,2,local+24); /*aligned-faces*/
	local[15] = w;
	if (local[15]==NIL) goto IF2825;
	local[24]= T;
	local[25]= fqv[109];
	local[26]= local[15];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)XFORMAT(ctx,3,local+24); /*format*/
	local[24]= NIL;
	local[25]= local[15];
WHL2828:
	if (local[25]==NIL) goto WHX2829;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	local[28]= local[9];
	local[29]= local[10];
	ctx->vsp=local+30;
	w=(pointer)F2408(ctx,4,local+26); /*merge-aligned-faces*/
	goto WHL2828;
WHX2829:
	local[26]= NIL;
BLK2830:
	w = NIL;
	local[24]= w;
	goto IF2826;
IF2825:
	local[24]= NIL;
IF2826:
	local[24]= NIL;
	storeglobal(fqv[110],local[24]);
	if (loadglobal(fqv[53])==NIL) goto IF2832;
	local[24]= T;
	local[25]= fqv[111];
	ctx->vsp=local+26;
	w=(pointer)XFORMAT(ctx,2,local+24); /*format*/
	local[24]= fqv[112];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2833;
IF2832:
	local[24]= NIL;
IF2833:
	local[24]= NIL;
	local[25]= local[9];
WHL2835:
	if (local[25]==NIL) goto WHX2836;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2839;
	local[26]= T;
	local[27]= fqv[113];
	local[28]= loadglobal(fqv[110]);
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,3,local+26); /*format*/
	local[26]= w;
	goto IF2840;
IF2839:
	local[26]= NIL;
IF2840:
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)F2397(ctx,1,local+26); /*construct-faces*/
	local[26]= w;
	w = loadglobal(fqv[110]);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	storeglobal(fqv[110],local[26]);
	goto WHL2835;
WHX2836:
	local[26]= NIL;
BLK2837:
	w = NIL;
	local[24]= NIL;
	local[25]= local[10];
WHL2842:
	if (local[25]==NIL) goto WHX2843;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2846;
	local[26]= T;
	local[27]= fqv[114];
	local[28]= loadglobal(fqv[110]);
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,3,local+26); /*format*/
	local[26]= w;
	goto IF2847;
IF2846:
	local[26]= NIL;
IF2847:
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)F2397(ctx,1,local+26); /*construct-faces*/
	local[26]= w;
	w = loadglobal(fqv[110]);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	storeglobal(fqv[110],local[26]);
	goto WHL2842;
WHX2843:
	local[26]= NIL;
BLK2844:
	w = NIL;
	local[24]= loadglobal(fqv[110]);
	ctx->vsp=local+25;
	w=(pointer)NREVERSE(ctx,1,local+24); /*nreverse*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(*ftab[26])(ctx,1,local+24,&ftab[26],fqv[115]); /*flatten*/
	local[24]= w;
	storeglobal(fqv[110],w);
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[23] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2848;
	local[24]= T;
	local[25]= fqv[116];
	local[26]= makeflt(1.66999996e-02);
	local[27]= local[17];
	local[28]= local[16];
	ctx->vsp=local+29;
	w=(pointer)MINUS(ctx,2,local+27); /*-*/
	local[27]= w;
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,2,local+26); /***/
	local[26]= w;
	local[27]= makeflt(1.66999996e-02);
	local[28]= local[18];
	local[29]= local[17];
	ctx->vsp=local+30;
	w=(pointer)MINUS(ctx,2,local+28); /*-*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)TIMES(ctx,2,local+27); /***/
	local[27]= w;
	local[28]= makeflt(1.66999996e-02);
	local[29]= local[19];
	local[30]= local[18];
	ctx->vsp=local+31;
	w=(pointer)MINUS(ctx,2,local+29); /*-*/
	local[29]= w;
	ctx->vsp=local+30;
	w=(pointer)TIMES(ctx,2,local+28); /***/
	local[28]= w;
	local[29]= makeflt(1.66999996e-02);
	local[30]= local[20];
	local[31]= local[19];
	ctx->vsp=local+32;
	w=(pointer)MINUS(ctx,2,local+30); /*-*/
	local[30]= w;
	ctx->vsp=local+31;
	w=(pointer)TIMES(ctx,2,local+29); /***/
	local[29]= w;
	local[30]= makeflt(1.66999996e-02);
	local[31]= local[21];
	local[32]= local[20];
	ctx->vsp=local+33;
	w=(pointer)MINUS(ctx,2,local+31); /*-*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)TIMES(ctx,2,local+30); /***/
	local[30]= w;
	local[31]= makeflt(1.66999996e-02);
	local[32]= local[22];
	local[33]= local[21];
	ctx->vsp=local+34;
	w=(pointer)MINUS(ctx,2,local+32); /*-*/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)TIMES(ctx,2,local+31); /***/
	local[31]= w;
	local[32]= makeflt(1.66999996e-02);
	local[33]= local[23];
	local[34]= local[22];
	ctx->vsp=local+35;
	w=(pointer)MINUS(ctx,2,local+33); /*-*/
	local[33]= w;
	ctx->vsp=local+34;
	w=(pointer)TIMES(ctx,2,local+32); /***/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)XFORMAT(ctx,9,local+24); /*format*/
	local[24]= w;
	goto IF2849;
IF2848:
	local[24]= NIL;
IF2849:
	local[24]= loadglobal(fqv[117]);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,1,local+24); /*instantiate*/
	local[24]= w;
	local[25]= local[24];
	local[26]= fqv[9];
	local[27]= fqv[96];
	local[28]= loadglobal(fqv[110]);
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,4,local+25); /*send*/
	w = local[24];
	local[0]= w;
BLK2809:
	ctx->vsp=local; return(local[0]);}

/*set-original-face*/
static pointer F2410(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2852,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL2854:
	if (local[6]==NIL) goto WHX2855;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[51];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[27])(ctx,1,local+7,&ftab[27],fqv[120]); /*primitive-body-p*/
	if (w==NIL) goto CON2859;
	local[7]= local[3];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,2,local+7,&ftab[28],fqv[121]); /*position*/
	local[4] = w;
	if (local[4]==NIL) goto IF2860;
	local[7]= local[5];
	local[8]= fqv[49];
	local[9]= local[5];
	local[10]= fqv[49];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[3];
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[28])(ctx,2,local+9,&ftab[28],fqv[121]); /*position*/
	local[9]= w;
	local[10]= local[4];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)NTH(ctx,2,local+10); /*nth*/
	local[10]= w;
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NTH(ctx,2,local+9); /*nth*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF2861;
IF2860:
	local[7]= NIL;
IF2861:
	goto CON2858;
CON2859:
	local[7]= fqv[122];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[23])(ctx,2,local+7,&ftab[23],fqv[88]); /*warn*/
	local[7]= w;
	goto CON2858;
CON2862:
	local[7]= NIL;
CON2858:
	local[7]= local[5];
	local[8]= fqv[51];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	goto WHL2854;
WHX2855:
	local[7]= NIL;
BLK2856:
	w = NIL;
	local[5]= NIL;
	local[6]= local[1];
WHL2864:
	if (local[6]==NIL) goto WHX2865;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= T;
	local[9]= fqv[123];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= argv[0];
	local[8]= fqv[124];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	goto WHL2864;
WHX2865:
	local[7]= NIL;
BLK2866:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK2851:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[123];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body+*/
static pointer F2411(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2869:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2871:
	if (local[4]==NIL) goto WHX2872;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)F2409(ctx,3,local+5); /*compose-body*/
	local[1] = w;
	local[5]= local[3];
	local[6]= fqv[125];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL2871;
WHX2872:
	local[5]= NIL;
BLK2873:
	w = NIL;
	local[3]= local[1];
	local[4]= fqv[118];
	local[5]= fqv[126];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2410(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2868:
	ctx->vsp=local; return(local[0]);}

/*body**/
static pointer F2412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2876:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
WHL2878:
	if (local[0]==NIL) goto WHX2879;
	local[3]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[56];
	ctx->vsp=local+6;
	w=(pointer)F2409(ctx,3,local+3); /*compose-body*/
	local[1] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[125];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	goto WHL2878;
WHX2879:
	local[3]= NIL;
BLK2880:
	local[3]= local[1];
	local[4]= fqv[118];
	local[5]= fqv[127];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2410(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2875:
	ctx->vsp=local; return(local[0]);}

/*body-*/
static pointer F2413(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2883:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[128];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP2884,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
WHL2885:
	if (local[0]==NIL) goto WHX2886;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[125];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)F2409(ctx,3,local+5); /*compose-body*/
	local[1] = w;
	local[5]= T;
	local[6]= local[5];
	*(ovafptr(local[1],fqv[129])) = local[6];
	goto WHL2885;
WHX2886:
	local[5]= NIL;
BLK2887:
	w = local[5];
	ctx->vsp=local+5;
	UWP2884(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[3]= local[1];
	local[4]= fqv[128];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= fqv[118];
	local[5]= fqv[130];
	local[6]= argv[0];
	local[7]= fqv[125];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2410(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2882:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2884(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[128];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body-interference*/
static pointer F2414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2890:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	local[2]= fqv[95];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[66]); /*send-all*/
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL2891:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2892;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[1] = w;
	local[4]= NIL;
	local[5]= local[0];
WHL2896:
	if (local[5]==NIL) goto WHX2897;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[1];
	local[7]= fqv[131];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF2900;
	local[6]= local[4];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF2901;
IF2900:
	local[6]= NIL;
IF2901:
	goto WHL2896;
WHX2897:
	local[6]= NIL;
BLK2898:
	w = NIL;
	goto WHL2891;
WHX2892:
	local[4]= NIL;
BLK2893:
	w = local[3];
	local[0]= w;
BLK2889:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2902(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[132]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[9];
	local[3]= makeflt(-9.99999864e+29);
	local[4]= makeflt(-9.99999864e+29);
	local[5]= makeflt(-9.99999864e+29);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeflt(9.99999864e+29);
	local[5]= makeflt(9.99999864e+29);
	local[6]= makeflt(9.99999864e+29);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK2903:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M2905(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK2906:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M2907(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
BLK2908:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2909(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2912;}
	local[0]= makeflt(0.00000000e+00);
ENT2912:
ENT2911:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[132]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[133];
	local[4]= makeflt(-9.99999864e+29);
	local[5]= makeflt(-9.99999864e+29);
	local[6]= makeflt(-9.99999864e+29);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeflt(9.99999864e+29);
	local[6]= makeflt(9.99999864e+29);
	local[7]= makeflt(9.99999864e+29);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK2910:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M2914(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[134];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2916;
	local[0]= fqv[56];
	goto IF2917;
IF2916:
	local[0]= fqv[32];
IF2917:
	w = local[0];
	local[0]= w;
BLK2915:
	ctx->vsp=local; return(local[0]);}

/*:primitive-face*/
static pointer M2918(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2921;}
	local[0]= NIL;
ENT2921:
ENT2920:
	if (n>3) maerror();
	w = argv[0];
	local[0]= w;
BLK2919:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M2922(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2925;}
	local[0]= NIL;
ENT2925:
ENT2924:
	if (n>3) maerror();
	w = NIL;
	local[0]= w;
BLK2923:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M2926(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2929;}
	local[0]= NIL;
ENT2929:
ENT2928:
	if (n>3) maerror();
	w = NIL;
	local[0]= w;
BLK2927:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M2930(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2933;}
	local[0]= NIL;
ENT2933:
ENT2932:
	if (n>4) maerror();
	w = NIL;
	local[0]= w;
BLK2931:
	ctx->vsp=local; return(local[0]);}

/*body/*/
static pointer F2415(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[135]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[9];
	local[3]= *(ovafptr(argv[1],fqv[31]));
	local[4]= *(ovafptr(argv[1],fqv[136]));
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)F2409(ctx,3,local+1); /*compose-body*/
	local[0]= w;
BLK2934:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___compose(ctx,n,argv,env)
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
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2936;
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[139],w);
	goto IF2937;
IF2936:
	local[0]= fqv[140];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2937:
	local[0]= fqv[141];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[142];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[143];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2938;
	local[0]= fqv[143];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[143];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2940;
	local[0]= fqv[143];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2941;
IF2940:
	local[0]= NIL;
IF2941:
	local[0]= fqv[143];
	goto IF2939;
IF2938:
	local[0]= NIL;
IF2939:
	local[0]= fqv[146];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2942;
	local[0]= fqv[146];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[146];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2944;
	local[0]= fqv[146];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2945;
IF2944:
	local[0]= NIL;
IF2945:
	local[0]= fqv[146];
	goto IF2943;
IF2942:
	local[0]= NIL;
IF2943:
	local[0]= fqv[110];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2946;
	local[0]= fqv[110];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[110];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2948;
	local[0]= fqv[110];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2949;
IF2948:
	local[0]= NIL;
IF2949:
	local[0]= fqv[110];
	goto IF2947;
IF2946:
	local[0]= NIL;
IF2947:
	local[0]= fqv[147];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2950;
	local[0]= fqv[147];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[147];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2952;
	local[0]= fqv[147];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2953;
IF2952:
	local[0]= NIL;
IF2953:
	local[0]= fqv[147];
	goto IF2951;
IF2950:
	local[0]= NIL;
IF2951:
	local[0]= fqv[8];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2954;
	local[0]= fqv[8];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2956;
	local[0]= fqv[8];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2957;
IF2956:
	local[0]= NIL;
IF2957:
	local[0]= fqv[8];
	goto IF2955;
IF2954:
	local[0]= NIL;
IF2955:
	local[0]= fqv[45];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2958;
	local[0]= fqv[45];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2960;
	local[0]= fqv[45];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2961;
IF2960:
	local[0]= NIL;
IF2961:
	local[0]= fqv[45];
	goto IF2959;
IF2958:
	local[0]= NIL;
IF2959:
	local[0]= fqv[57];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2962;
	local[0]= fqv[57];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2964;
	local[0]= fqv[57];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2965;
IF2964:
	local[0]= NIL;
IF2965:
	local[0]= fqv[57];
	goto IF2963;
IF2962:
	local[0]= NIL;
IF2963:
	local[0]= fqv[117];
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2966;
	local[0]= fqv[117];
	local[1]= fqv[144];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[117];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2968;
	local[0]= fqv[117];
	local[1]= fqv[145];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2969;
IF2968:
	local[0]= NIL;
IF2969:
	local[0]= fqv[117];
	goto IF2967;
IF2966:
	local[0]= NIL;
IF2967:
	ctx->vsp=local+0;
	compfun(ctx,fqv[148],module,F2387,fqv[149]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[150],module,F2388,fqv[151]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[152],module,F2389,fqv[153]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[154],module,F2390,fqv[155]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F2391,fqv[157]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[158],module,F2392,fqv[159]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F2393,fqv[161]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[162],module,F2394,fqv[163]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F2395,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F2396,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F2397,fqv[169]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[170],module,F2398,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F2399,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F2400,fqv[175]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[176],module,F2401,fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F2402,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F2403,fqv[181]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[182],module,F2404,fqv[183]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[184],module,F2405,fqv[185]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F2406,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F2407,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F2408,fqv[191]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[192],module,F2409,fqv[193]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F2410,fqv[195]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[196],module,F2411,fqv[197]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[198],module,F2412,fqv[199]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[200],module,F2413,fqv[201]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[202],module,F2414,fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2902,fqv[14],fqv[204],fqv[205]);
	local[0]= fqv[135];
	local[1]= fqv[145];
	local[2]= fqv[135];
	local[3]= fqv[206];
	local[4]= loadglobal(fqv[204]);
	local[5]= fqv[207];
	local[6]= fqv[208];
	local[7]= fqv[209];
	local[8]= NIL;
	local[9]= fqv[210];
	local[10]= NIL;
	local[11]= fqv[68];
	local[12]= makeint(-1);
	local[13]= fqv[211];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[29])(ctx,13,local+2,&ftab[29],fqv[212]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2905,fqv[1],fqv[135],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2907,fqv[96],fqv[135],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2909,fqv[14],fqv[135],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2914,fqv[20],fqv[135],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2918,fqv[49],fqv[135],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2922,fqv[51],fqv[135],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2926,fqv[52],fqv[135],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2930,fqv[38],fqv[135],fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F2415,fqv[222]);
	local[0]= fqv[223];
	local[1]= fqv[224];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[225]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
