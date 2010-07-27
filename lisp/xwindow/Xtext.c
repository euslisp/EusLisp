/* Xtext.c :  entry=Xtext */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xtext.h"
#pragma init (register_Xtext)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xtext();
extern pointer build_quote_vector();
static register_Xtext()
  { add_module_initializer("___Xtext", ___Xtext);}

static pointer F2517();
static pointer F2518();

/*:create*/
static pointer M2519(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2521:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2522;
	local[1] = makeint(256);
KEY2522:
	if (n & (1<<1)) goto KEY2523;
	local[2] = makeint(256);
KEY2523:
	if (n & (1<<2)) goto KEY2524;
	local[3] = NIL;
KEY2524:
	if (n & (1<<3)) goto KEY2525;
	local[4] = NIL;
KEY2525:
	if (n & (1<<4)) goto KEY2526;
	local[5] = NIL;
KEY2526:
	if (n & (1<<5)) goto KEY2527;
	local[6] = fqv[1];
KEY2527:
	if (n & (1<<6)) goto KEY2528;
	local[7] = loadglobal(fqv[2]);
KEY2528:
	w = local[3];
	if (!isstring(w)) goto CON2530;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,1,local+8,&ftab[0],fqv[3]); /*font-id*/
	local[8]= w;
	goto CON2529;
CON2530:
	w = local[3];
	if (!isnum(w)) goto CON2531;
	local[8]= local[3];
	goto CON2529;
CON2531:
	local[8]= local[7];
	local[9]= loadglobal(fqv[2]);
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w!=NIL) goto CON2532;
	local[8]= local[7];
	local[9]= loadglobal(fqv[4]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto CON2532;
	local[8]= local[7];
	local[9]= fqv[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	goto CON2529;
CON2532:
	local[8]= loadglobal(fqv[6]);
	goto CON2529;
CON2533:
	local[8]= NIL;
CON2529:
	argv[0]->c.obj.iv[12] = local[8];
	local[8]= fqv[7];
	local[9]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[8]); /*textdots*/
	local[8]= w;
	local[9]= local[8];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[8];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	argv[0]->c.obj.iv[14] = w;
	local[9]= local[8];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	argv[0]->c.obj.iv[13] = w;
	local[9]= local[8];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	argv[0]->c.obj.iv[15] = w;
	w = argv[0]->c.obj.iv[15];
	if (local[5]==NIL) goto CON2535;
	local[8]= makeint(4);
	local[9]= argv[0]->c.obj.iv[13];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[1] = w;
	local[8]= local[1];
	goto CON2534;
CON2535:
	if (local[1]==NIL) goto CON2536;
	local[8]= local[1];
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[5] = w;
	local[8]= local[5];
	goto CON2534;
CON2536:
	local[8]= NIL;
CON2534:
	if (local[4]==NIL) goto CON2538;
	local[8]= makeint(4);
	local[9]= argv[0]->c.obj.iv[14];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[2] = w;
	local[8]= local[2];
	goto CON2537;
CON2538:
	if (local[2]==NIL) goto CON2539;
	local[8]= local[2];
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[4] = w;
	local[8]= local[4];
	goto CON2537;
CON2539:
	local[8]= NIL;
CON2537:
	argv[0]->c.obj.iv[16] = local[4];
	argv[0]->c.obj.iv[17] = local[5];
	local[8]= (pointer)get_sym_func(fqv[9]);
	local[9]= argv[0];
	local[10]= *(ovafptr(argv[1],fqv[10]));
	local[11]= fqv[11];
	local[12]= fqv[12];
	local[13]= local[1];
	local[14]= fqv[13];
	local[15]= local[2];
	local[16]= fqv[14];
	local[17]= local[6];
	local[18]= fqv[5];
	local[19]= local[3];
	local[20]= fqv[15];
	local[21]= local[7];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)APPLY(ctx,15,local+8); /*apply*/
	local[8]= argv[0]->c.obj.iv[3];
	local[9]= fqv[5];
	local[10]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK2520:
	ctx->vsp=local; return(local[0]);}

/*:xy*/
static pointer M2540(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2544;}
	local[0]= makeint(0);
ENT2544:
	if (n>=4) { local[1]=(argv[3]); goto ENT2543;}
	local[1]= makeint(0);
ENT2543:
ENT2542:
	if (n>4) maerror();
	local[2]= makeint(2);
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[0]->c.obj.iv[18] = w;
	local[2]= makeint(2);
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	argv[0]->c.obj.iv[19] = w;
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK2541:
	ctx->vsp=local; return(local[0]);}

/*:clear-lines*/
static pointer M2545(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= fqv[17];
	local[3]= makeint(0);
	local[4]= fqv[18];
	local[5]= makeint(2);
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= fqv[12];
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= fqv[13];
	local[9]= argv[0]->c.obj.iv[14];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	w = argv[3];
	local[0]= w;
BLK2546:
	ctx->vsp=local; return(local[0]);}

/*:put-line*/
static pointer M2547(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[0]->c.obj.iv[18];
	local[3]= argv[0]->c.obj.iv[19];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK2548:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2549(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2551:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[21], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2552;
	local[1] = NIL;
KEY2552:
	if (n & (1<<1)) goto KEY2553;
	local[2] = NIL;
KEY2553:
	if (n & (1<<2)) goto KEY2554;
	local[3] = NIL;
KEY2554:
	if (n & (1<<3)) goto KEY2555;
	local[4] = NIL;
KEY2555:
	if (n & (1<<4)) goto KEY2556;
	local[5] = fqv[22];
KEY2556:
	if (n & (1<<5)) goto KEY2557;
	local[6] = NIL;
KEY2557:
	if (n & (1<<6)) goto KEY2558;
	local[7] = NIL;
KEY2558:
	if (n & (1<<7)) goto KEY2559;
	local[8] = NIL;
KEY2559:
	local[9]= (pointer)get_sym_func(fqv[9]);
	local[10]= argv[0];
	local[11]= *(ovafptr(argv[1],fqv[10]));
	local[12]= fqv[11];
	local[13]= fqv[14];
	local[14]= local[5];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,7,local+9); /*apply*/
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,1,local+9,&ftab[2],fqv[23]); /*make-string*/
	argv[0]->c.obj.iv[22] = w;
	local[9]= argv[0];
	local[10]= fqv[24];
	local[11]= local[7];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[25];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	argv[0]->c.obj.iv[27] = NIL;
	local[9]= argv[0]->c.obj.iv[3];
	local[10]= fqv[5];
	local[11]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[26];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[27];
	local[11]= fqv[28];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = argv[0];
	local[0]= w;
BLK2550:
	ctx->vsp=local; return(local[0]);}

/*:set-notify*/
static pointer M2560(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[28] = argv[2];
	argv[0]->c.obj.iv[29] = argv[3];
	w = argv[0];
	local[0]= w;
BLK2561:
	ctx->vsp=local; return(local[0]);}

/*:show-cursor*/
static pointer M2562(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[26] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[27];
	if (argv[0]->c.obj.iv[27]==NIL) goto IF2564;
	local[2]= fqv[28];
	goto IF2565;
IF2564:
	local[2]= fqv[29];
IF2565:
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2563:
	ctx->vsp=local; return(local[0]);}

/*:cursor*/
static pointer M2566(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2569;}
	local[0]= fqv[30];
ENT2569:
ENT2568:
	if (n>3) maerror();
	if (argv[0]->c.obj.iv[26]==NIL) goto IF2570;
	local[1]= local[0];
	if (fqv[30]==local[1]) goto OR2572;
	local[1]= local[0];
	if (fqv[28]!=local[1]) goto AND2573;
	if (argv[0]->c.obj.iv[27]!=NIL) goto AND2573;
	goto OR2572;
AND2573:
	local[1]= local[0];
	if (fqv[29]!=local[1]) goto AND2574;
	if (argv[0]->c.obj.iv[27]==NIL) goto AND2574;
	goto OR2572;
AND2574:
	goto IF2570;
OR2572:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[31];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[33]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[4]= argv[0]->c.obj.iv[18];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(2);
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,7,local+1,&ftab[3],fqv[34]); /*fillrectangle*/
	argv[0]->c.obj.iv[27] = ((argv[0]->c.obj.iv[27])==NIL?T:NIL);
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[31];
	local[3]= fqv[35];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF2571;
IF2570:
	local[1]= NIL;
IF2571:
	w = local[1];
	local[0]= w;
BLK2567:
	ctx->vsp=local; return(local[0]);}

/*:win-row*/
static pointer M2575(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK2576:
	ctx->vsp=local; return(local[0]);}

/*:win-col*/
static pointer M2577(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2578:
	ctx->vsp=local; return(local[0]);}

/*:win-row-max*/
static pointer M2579(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2580:
	ctx->vsp=local; return(local[0]);}

/*:win-col-max*/
static pointer M2581(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK2582:
	ctx->vsp=local; return(local[0]);}

/*:xy*/
static pointer M2583(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2587;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2587:
	if (n>=4) { local[1]=(argv[3]); goto ENT2586;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2586:
ENT2585:
	if (n>4) maerror();
	local[2]= makeint(2);
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[0]->c.obj.iv[18] = w;
	local[2]= makeint(2);
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	argv[0]->c.obj.iv[19] = w;
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK2584:
	ctx->vsp=local; return(local[0]);}

/*:goto*/
static pointer M2588(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2591;}
	local[0]= fqv[28];
ENT2591:
ENT2590:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= (pointer)((integer_t)(argv[0]->c.obj.iv[16])-4);
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	argv[0]->c.obj.iv[20] = w;
	local[1]= (pointer)((integer_t)(argv[0]->c.obj.iv[17])-4);
	local[2]= argv[3];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	argv[0]->c.obj.iv[21] = w;
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK2589:
	ctx->vsp=local; return(local[0]);}

/*:goback*/
static pointer M2592(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2595;}
	local[0]= fqv[28];
ENT2595:
ENT2594:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= makeint(0);
	local[5]= (pointer)((integer_t)(argv[0]->c.obj.iv[21])-4);
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,2,local+4); /*max*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2593:
	ctx->vsp=local; return(local[0]);}

/*:advance*/
static pointer M2596(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2599;}
	local[0]= makeint(1);
ENT2599:
ENT2598:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[21] = w;
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[21];
	local[3]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[20] = w;
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	argv[0]->c.obj.iv[21] = w;
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2597:
	ctx->vsp=local; return(local[0]);}

/*:scroll*/
static pointer M2600(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2603;}
	local[0]= makeint(1);
ENT2603:
ENT2602:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON2605;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK2601;
	goto CON2604;
CON2605:
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto CON2606;
	local[2] = local[0];
	local[3] = makeint(0);
	local[5]= argv[0]->c.obj.iv[16];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[4];
	goto CON2604;
CON2606:
	local[2] = makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[3] = w;
	local[4] = makeint(0);
	local[5]= local[4];
	goto CON2604;
CON2607:
	local[5]= NIL;
CON2604:
	local[5]= argv[0]->c.obj.iv[16];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[0] = w;
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[9]= makeint(2);
	local[10]= makeint(2);
	local[11]= local[2];
	local[12]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[5];
	local[12]= argv[0]->c.obj.iv[16];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= makeint(2);
	local[14]= makeint(2);
	local[15]= local[3];
	local[16]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(*ftab[4])(ctx,10,local+5,&ftab[4],fqv[37]); /*copyarea*/
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= makeint(2);
	local[8]= makeint(2);
	local[9]= local[4];
	local[10]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= local[0];
	local[11]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,7,local+5,&ftab[5],fqv[38]); /*cleararea*/
	local[0]= w;
BLK2601:
	ctx->vsp=local; return(local[0]);}

/*:horizontal-scroll*/
static pointer M2608(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2611;}
	local[0]= makeint(1);
ENT2611:
ENT2610:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON2613;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK2609;
	goto CON2612;
CON2613:
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto CON2614;
	local[2] = local[0];
	local[3] = makeint(0);
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[4];
	goto CON2612;
CON2614:
	local[2] = makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[3] = w;
	local[4] = makeint(0);
	local[5]= local[4];
	goto CON2612;
CON2615:
	local[5]= NIL;
CON2612:
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[0] = w;
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[9]= makeint(2);
	local[10]= local[2];
	local[11]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(2);
	local[11]= argv[0]->c.obj.iv[17];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[6];
	local[13]= makeint(2);
	local[14]= local[3];
	local[15]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(*ftab[4])(ctx,10,local+5,&ftab[4],fqv[37]); /*copyarea*/
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= makeint(2);
	local[8]= local[4];
	local[9]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(2);
	local[9]= local[0];
	local[10]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= argv[0]->c.obj.iv[6];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,7,local+5,&ftab[5],fqv[38]); /*cleararea*/
	local[0]= w;
BLK2609:
	ctx->vsp=local; return(local[0]);}

/*:newline*/
static pointer M2616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[21] = makeint(0);
	argv[0]->c.obj.iv[20] = (pointer)((integer_t)(argv[0]->c.obj.iv[20])+4);
	local[0]= argv[0]->c.obj.iv[20];
	local[1]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2618;
	local[0]= argv[0];
	local[1]= fqv[39];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[20] = (pointer)((integer_t)(argv[0]->c.obj.iv[20])-4);
	local[0]= argv[0]->c.obj.iv[20];
	goto IF2619;
IF2618:
	local[0]= NIL;
IF2619:
	w = local[0];
	local[0]= w;
BLK2617:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M2620(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[20] = makeint(0);
	argv[0]->c.obj.iv[21] = makeint(0);
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK2621:
	ctx->vsp=local; return(local[0]);}

/*:clear-eol*/
static pointer M2622(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2627;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2627:
	if (n>=4) { local[1]=(argv[3]); goto ENT2626;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2626:
	if (n>=5) { local[2]=(argv[4]); goto ENT2625;}
	local[2]= fqv[28];
ENT2625:
ENT2624:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= fqv[17];
	local[6]= makeint(2);
	local[7]= local[1];
	local[8]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= fqv[18];
	local[8]= makeint(2);
	local[9]= local[0];
	local[10]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= fqv[12];
	local[10]= argv[0]->c.obj.iv[13];
	local[11]= argv[0]->c.obj.iv[17];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= fqv[13];
	local[12]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,10,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK2623:
	ctx->vsp=local; return(local[0]);}

/*:clear-lines*/
static pointer M2628(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2631;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2631:
ENT2630:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= fqv[17];
	local[4]= makeint(0);
	local[5]= fqv[18];
	local[6]= makeint(2);
	local[7]= local[0];
	local[8]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= fqv[12];
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= fqv[13];
	local[10]= argv[0]->c.obj.iv[14];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,10,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK2629:
	ctx->vsp=local; return(local[0]);}

/*:clear-eos*/
static pointer M2632(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2636;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2636:
	if (n>=4) { local[1]=(argv[3]); goto ENT2635;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2635:
ENT2634:
	if (n>4) maerror();
	local[2]= argv[0];
	local[3]= fqv[27];
	local[4]= fqv[29];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[40];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[16];
	local[4]= fqv[17];
	local[5]= makeint(0);
	local[6]= fqv[18];
	local[7]= makeint(2);
	local[8]= (pointer)((integer_t)(local[0])+4);
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= fqv[12];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= fqv[13];
	local[11]= argv[0]->c.obj.iv[14];
	local[12]= argv[0]->c.obj.iv[16];
	local[13]= local[0];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,10,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[27];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK2633:
	ctx->vsp=local; return(local[0]);}

/*:clear-in-line*/
static pointer M2637(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= fqv[17];
	local[3]= makeint(2);
	local[4]= argv[0]->c.obj.iv[13];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= fqv[18];
	local[5]= makeint(2);
	local[6]= argv[0]->c.obj.iv[14];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= fqv[12];
	local[7]= argv[0]->c.obj.iv[13];
	local[8]= argv[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= fqv[13];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	local[0]= w;
BLK2638:
	ctx->vsp=local; return(local[0]);}

/*:clear-text-area*/
static pointer M2639(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF2641;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2642;
IF2641:
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
IF2642:
	local[0]= argv[2];
	local[1]= (pointer)((integer_t)(argv[4])-4);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2643;
	local[0]= argv[0];
	local[1]= fqv[42];
	local[2]= argv[4];
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= (pointer)((integer_t)(argv[2])+4);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2644;
IF2643:
	local[0]= NIL;
IF2644:
	local[0]= argv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF2645;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[4];
	local[3]= makeint(0);
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2646;
IF2645:
	local[0]= NIL;
IF2646:
	w = local[0];
	local[0]= w;
BLK2640:
	ctx->vsp=local; return(local[0]);}

/*:putch*/
static pointer M2647(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	local[1]= local[0];
	if (fqv[43]!=local[1]) goto IF2650;
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF2651;
IF2650:
	local[1]= local[0];
	if (fqv[45]!=local[1]) goto IF2652;
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF2653;
IF2652:
	if (T==NIL) goto IF2654;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[22];
	local[2]= makeint(0);
	w = argv[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.str.chars[i]=intval(w);}
	local[1]= argv[0];
	local[2]= fqv[46];
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF2656;
	local[1]= argv[0];
	local[2]= fqv[39];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[20] = (pointer)((integer_t)(argv[0]->c.obj.iv[20])-4);
	local[1]= argv[0]->c.obj.iv[20];
	goto IF2657;
IF2656:
	local[1]= NIL;
IF2657:
	local[1]= argv[2];
	goto IF2655;
IF2654:
	local[1]= NIL;
IF2655:
IF2653:
IF2651:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2648:
	ctx->vsp=local; return(local[0]);}

/*:putstring*/
static pointer M2658(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2661;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT2661:
ENT2660:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[27];
	local[8]= fqv[29];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
WHL2662:
	local[6]= local[3];
	w = local[0];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX2663;
	local[6]= argv[0]->c.obj.iv[17];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[1] = w;
	local[6]= makeint(10);
	local[7]= argv[2];
	local[8]= fqv[48];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,4,local+6,&ftab[6],fqv[49]); /*position*/
	local[2] = w;
	local[6]= argv[0]->c.obj.iv[17];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	if (local[2]==NIL) goto IF2665;
	local[7]= local[2];
	goto IF2666;
IF2665:
	local[7]= local[0];
IF2666:
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[40];
	local[8]= argv[0]->c.obj.iv[20];
	local[9]= argv[0]->c.obj.iv[21];
	local[10]= fqv[29];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[19];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[20];
	local[8]= argv[0]->c.obj.iv[18];
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= argv[2];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,7,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[47];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (local[2]==NIL) goto IF2667;
	local[4] = (pointer)((integer_t)(local[4])+4);
	local[6]= argv[0];
	local[7]= fqv[44];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF2668;
IF2667:
	local[6]= NIL;
IF2668:
	local[3] = local[4];
	goto WHL2662;
WHX2663:
	local[6]= NIL;
BLK2664:
	local[6]= argv[0];
	local[7]= fqv[27];
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0]= w;
BLK2659:
	ctx->vsp=local; return(local[0]);}

/*:insert*/
static pointer M2669(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2670:
	ctx->vsp=local; return(local[0]);}

/*:event-row*/
static pointer M2671(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[52]); /*event-y*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2672:
	ctx->vsp=local; return(local[0]);}

/*:event-col*/
static pointer M2673(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[53]); /*event-x*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2674:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2675(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2676:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2677(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[36];
	local[5]= argv[0];
	local[6]= fqv[54];
	local[7]= loadglobal(fqv[51]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[55];
	local[8]= loadglobal(fqv[51]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2678:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M2679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[56];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[17] = w;
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[16] = w;
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK2680:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M2681(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR2685;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR2685;
	goto IF2683;
OR2685:
	local[5]= argv[0];
	local[6]= fqv[56];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF2684;
IF2683:
	local[5]= NIL;
IF2684:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2682:
	ctx->vsp=local; return(local[0]);}

/*:echo*/
static pointer M2686(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[25] = argv[2];
	w = argv[0]->c.obj.iv[25];
	local[0]= w;
BLK2687:
	ctx->vsp=local; return(local[0]);}

/*:getstring*/
static pointer M2688(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[23];
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[24];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
	argv[0]->c.obj.iv[24] = makeint(0);
	w = local[0];
	local[0]= w;
BLK2689:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2691(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	if (argv[0]->c.obj.iv[2]==NIL) goto IF2693;
	local[3]= loadglobal(fqv[33]);
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= makeint(1);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,4,local+3,&ftab[10],fqv[58]); /*setinputfocus*/
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2694;
IF2693:
	local[3]= NIL;
IF2694:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2692:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2695(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2696:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M2697(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2698:
	ctx->vsp=local; return(local[0]);}

/*:lineenter*/
static pointer M2699(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2702;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT2702:
ENT2701:
	if (n>4) maerror();
	local[1]= argv[2];
	if (argv[0]->c.obj.iv[23]==local[1]) goto IF2703;
	local[1]= argv[0]->c.obj.iv[23];
	local[2]= argv[2];
	local[3]= fqv[59];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,4,local+1,&ftab[11],fqv[60]); /*replace*/
	local[1]= w;
	goto IF2704;
IF2703:
	local[1]= NIL;
IF2704:
	w = local[1];
	local[0]= w;
BLK2700:
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M2705(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2708;}
	local[0]= NIL;
ENT2708:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
ENT2707:
	if (n>4) maerror();
	local[3]= argv[0];
	local[4]= fqv[61];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[2];
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF2709;
	if (argv[0]->c.obj.iv[28]==NIL) goto IF2709;
	if (argv[0]->c.obj.iv[29]==NIL) goto IF2709;
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2710;
IF2709:
	local[3]= NIL;
IF2710:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2706:
	ctx->vsp=local; return(local[0]);}

/*:fill*/
static pointer M2711(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2712:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M2713(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[3];
WHL2716:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX2717;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= fqv[50];
	local[4]= argv[0]->c.obj.iv[2];
	{ register integer_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL2716;
WHX2717:
	local[2]= NIL;
BLK2718:
	w = NIL;
	ctx->vsp=local+0;
	w=(*ftab[12])(ctx,0,local+0,&ftab[12],fqv[63]); /*xflush*/
	argv[0]->c.obj.iv[3] = makeint(0);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK2714:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M2719(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[64];
	local[3]= argv[3];
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	w = argv[0];
	local[0]= w;
BLK2720:
	ctx->vsp=local; return(local[0]);}

/*make-textwindow-stream*/
static pointer F2517(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[65]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[64];
	local[3]= argv[0];
	local[4]= fqv[66];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[64];
	local[4]= argv[0];
	local[5]= fqv[67];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[68]); /*make-two-way-stream*/
	local[0]= w;
BLK2721:
	ctx->vsp=local; return(local[0]);}

/*expand-tab*/
static pointer F2518(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2726;}
	local[0]= makeint(0);
ENT2726:
ENT2725:
	if (n>2) maerror();
	local[1]= makeint(9);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[69]); /*count*/
	local[1]= w;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= NIL;
	local[6]= local[1];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF2727;
	local[6]= argv[0];
	goto IF2728;
IF2727:
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeint(8);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,1,local+6,&ftab[2],fqv[23]); /*make-string*/
	local[5] = w;
	local[6]= makeint(0);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL2730:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX2731;
	local[8]= argv[0];
	{ register integer_t i=intval(local[6]);
	  w=makeint(local[8]->c.str.chars[i]);}
	local[2] = w;
	local[8]= local[2];
	local[9]= makeint(9);
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2734;
	local[8]= makeint(8);
	local[9]= local[0];
	w = local[3];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[9]= (pointer)((integer_t)local[9] + (integer_t)w);
	local[10]= makeint(8);
	ctx->vsp=local+11;
	w=(pointer)MOD(ctx,2,local+9); /*mod*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[4] = w;
	local[8]= local[5];
	local[9]= makeint(32);
	local[10]= fqv[48];
	local[11]= local[3];
	local[12]= fqv[70];
	local[13]= local[3];
	w = local[4];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[13]= (pointer)((integer_t)local[13] + (integer_t)w);
	ctx->vsp=local+14;
	w=(*ftab[15])(ctx,6,local+8,&ftab[15],fqv[71]); /*fill*/
	local[8]= local[3];
	w = local[4];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[3] = (pointer)((integer_t)local[8] + (integer_t)w);
	local[8]= local[3];
	goto CON2733;
CON2734:
	local[8]= local[5];
	local[9]= local[3];
	w = local[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[8]= local[3];
	goto CON2733;
CON2735:
	local[8]= NIL;
CON2733:
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL2730;
WHX2731:
	local[8]= NIL;
BLK2732:
	w = NIL;
	local[6]= local[5];
	local[7]= makeint(0);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[6]= w;
IF2728:
	w = local[6];
	local[0]= w;
BLK2724:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2736(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2738:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[9]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[10]));
	local[4]= fqv[11];
	local[5]= fqv[14];
	local[6]= fqv[72];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK2737:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2739(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2740:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M2741(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	w = argv[0];
	local[0]= w;
BLK2742:
	ctx->vsp=local; return(local[0]);}

/*:refresh-line*/
static pointer M2743(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2747;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2747:
	if (n>=4) { local[1]=(argv[3]); goto ENT2746;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2746:
ENT2745:
	if (n>4) maerror();
	local[2]= argv[0];
	local[3]= fqv[40];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[19];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[18];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= argv[0]->c.obj.iv[32];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK2744:
	ctx->vsp=local; return(local[0]);}

/*:refresh*/
static pointer M2748(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2751;}
	local[0]= makeint(0);
ENT2751:
ENT2750:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[21];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
WHL2753:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX2754;
	local[5]= argv[0];
	local[6]= fqv[76];
	local[7]= local[3];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL2753;
WHX2754:
	local[5]= NIL;
BLK2755:
	w = NIL;
	argv[0]->c.obj.iv[20] = local[1];
	argv[0]->c.obj.iv[21] = local[2];
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2749:
	ctx->vsp=local; return(local[0]);}

/*:refresh-in-line*/
static pointer M2756(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[32];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[4];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	argv[4] = w;
	local[1]= argv[0];
	local[2]= fqv[46];
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= local[0];
	local[6]= argv[3];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK2757:
	ctx->vsp=local; return(local[0]);}

/*:refresh-lines*/
static pointer M2758(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
WHL2761:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX2762;
	local[2]= argv[0];
	local[3]= fqv[19];
	local[4]= argv[3];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[18];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= argv[0]->c.obj.iv[32];
	local[7]= argv[3];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL2761;
WHX2762:
	local[2]= NIL;
BLK2763:
	w = NIL;
	local[0]= w;
BLK2759:
	ctx->vsp=local; return(local[0]);}

/*:refresh-area*/
static pointer M2764(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w!=NIL) goto OR2768;
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto AND2769;
	local[0]= argv[3];
	local[1]= argv[5];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto AND2769;
	goto OR2768;
AND2769:
	goto IF2766;
OR2768:
	local[0]= argv[4];
	local[1]= argv[5];
	local[2]= argv[2];
	local[3]= argv[3];
	argv[2] = local[0];
	argv[3] = local[1];
	argv[4] = local[2];
	argv[5] = local[3];
	w = NIL;
	local[0]= w;
	goto IF2767;
IF2766:
	local[0]= NIL;
IF2767:
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF2774;
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2775;
IF2774:
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
IF2775:
	local[0]= argv[2];
	local[1]= (pointer)((integer_t)(argv[4])-4);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2776;
	local[0]= argv[0];
	local[1]= fqv[78];
	local[2]= argv[4];
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= (pointer)((integer_t)(argv[2])+4);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2777;
IF2776:
	local[0]= NIL;
IF2777:
	local[0]= argv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF2778;
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[4];
	local[3]= makeint(0);
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2779;
IF2778:
	local[0]= NIL;
IF2779:
	w = local[0];
	local[0]= w;
BLK2765:
	ctx->vsp=local; return(local[0]);}

/*:highlight*/
static pointer M2780(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	if (argv[2]==NIL) goto IF2782;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2783;
IF2782:
	local[0]= NIL;
IF2783:
	local[0]= argv[0];
	local[1]= fqv[80];
	local[2]= argv[3];
	local[3]= argv[4];
	local[4]= argv[5];
	local[5]= argv[6];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	if (argv[2]==NIL) goto IF2784;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2785;
IF2784:
	local[0]= NIL;
IF2785:
	w = local[0];
	local[0]= w;
BLK2781:
	ctx->vsp=local; return(local[0]);}

/*:goto*/
static pointer M2786(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2789;}
	local[0]= fqv[28];
ENT2789:
ENT2788:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF2790;
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	goto IF2791;
IF2790:
	local[1]= makeint(0);
IF2791:
	argv[3] = local[1];
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[10]));
	local[3]= fqv[36];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK2787:
	ctx->vsp=local; return(local[0]);}

/*:line*/
static pointer M2792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2794;
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	goto IF2795;
IF2794:
	local[0]= NIL;
IF2795:
	w = local[0];
	local[0]= w;
BLK2793:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M2796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2797:
	ctx->vsp=local; return(local[0]);}

/*:nlines*/
static pointer M2798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK2799:
	ctx->vsp=local; return(local[0]);}

/*:all-lines*/
static pointer M2800(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2801:
	ctx->vsp=local; return(local[0]);}

/*:max-line-length*/
static pointer M2802(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[81]);
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[82]);
	local[3]= (pointer)get_sym_func(fqv[83]);
	local[4]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	argv[0]->c.obj.iv[33] = w;
	w = argv[0]->c.obj.iv[33];
	local[0]= w;
BLK2803:
	ctx->vsp=local; return(local[0]);}

/*:read-file*/
static pointer M2804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[84]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP2806,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= makeint(0);
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[0];
	local[6]= NIL;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)READLINE(ctx,3,local+5); /*read-line*/
	local[5]= w;
TAG2809:
	local[6]= local[5];
	if (local[4]!=local[6]) goto IF2810;
	w = NIL;
	ctx->vsp=local+6;
	local[3]=w;
	goto BLK2808;
	goto IF2811;
IF2810:
	local[6]= NIL;
IF2811:
	local[6]= local[5];
	local[7]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+8;
	w=(pointer)VECTOREXPUSH(ctx,2,local+6); /*vector-push-extend*/
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)F2518(ctx,1,local+6); /*expand-tab*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+8;
	w=(pointer)VECTOREXPUSH(ctx,2,local+6); /*vector-push-extend*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[5] = w;
	ctx->vsp=local+6;
	goto TAG2809;
	w = NIL;
	local[3]= w;
BLK2808:
	w = local[3];
	ctx->vsp=local+3;
	UWP2806(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = T;
	local[0]= w;
BLK2805:
	ctx->vsp=local; return(local[0]);}

/*:display-line-string*/
static pointer M2812(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[86],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= T;
WHL2814:
	if (local[6]==NIL) goto WHX2815;
	local[7]= makeint(10);
	local[8]= loadglobal(fqv[86]);
	local[9]= fqv[48];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,4,local+7,&ftab[6],fqv[49]); /*position*/
	local[4] = w;
	if (local[4]!=NIL) goto CON2818;
	local[7]= loadglobal(fqv[86]);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[6] = NIL;
	local[7]= local[6];
	goto CON2817;
CON2818:
	local[7]= loadglobal(fqv[86]);
	local[8]= local[5];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[5] = (pointer)((integer_t)(local[4])+4);
	local[7]= local[5];
	goto CON2817;
CON2819:
	local[7]= NIL;
CON2817:
	goto WHL2814;
WHX2815:
	local[7]= NIL;
BLK2816:
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[87];
	local[9]= local[3];
	local[10]= fqv[74];
	local[11]= T;
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,5,local+7,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[87];
	local[9]= local[3];
	local[10]= fqv[74];
	local[11]= T;
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,5,local+7,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	argv[0]->c.obj.iv[34] = NIL;
	local[7]= argv[0];
	local[8]= fqv[85];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[73];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3]= T;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2813:
	ctx->vsp=local; return(local[0]);}

/*:display-strings*/
static pointer M2820(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	local[3]= fqv[74];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,5,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	local[3]= fqv[74];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,5,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= makeint(0);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2823:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX2824;
	local[2]= argv[0]->c.obj.iv[32];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[32];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F2518(ctx,1,local+4); /*expand-tab*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL2823;
WHX2824:
	local[2]= NIL;
BLK2825:
	w = NIL;
	argv[0]->c.obj.iv[34] = NIL;
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2821:
	ctx->vsp=local; return(local[0]);}

/*:insert-string*/
static pointer M2826(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2829;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT2829:
ENT2828:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[23]); /*make-string*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= local[3];
	local[5]= local[1];
	local[6]= fqv[59];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,4,local+4,&ftab[11],fqv[60]); /*replace*/
	local[4]= local[3];
	local[5]= argv[2];
	local[6]= fqv[88];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,4,local+4,&ftab[11],fqv[60]); /*replace*/
	local[4]= local[3];
	local[5]= local[1];
	local[6]= fqv[88];
	local[7]= argv[0]->c.obj.iv[21];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= fqv[89];
	local[9]= argv[0]->c.obj.iv[21];
	local[10]= fqv[59];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[11])(ctx,8,local+4,&ftab[11],fqv[60]); /*replace*/
	local[4]= argv[0]->c.obj.iv[31];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[0]->c.obj.iv[32];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F2518(ctx,1,local+6); /*expand-tab*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[0]->c.obj.iv[20];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK2827:
	ctx->vsp=local; return(local[0]);}

/*:insert*/
static pointer M2830(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= (pointer)((integer_t)(local[1])+4);
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,1,local+2,&ftab[2],fqv[23]); /*make-string*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= fqv[59];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,4,local+3,&ftab[11],fqv[60]); /*replace*/
	local[3]= local[2];
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= fqv[88];
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[21])+4);
	local[7]= fqv[89];
	local[8]= argv[0]->c.obj.iv[21];
	local[9]= fqv[59];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[11])(ctx,8,local+3,&ftab[11],fqv[60]); /*replace*/
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F2518(ctx,1,local+5); /*expand-tab*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= argv[0];
	local[4]= fqv[47];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[76];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= (pointer)((integer_t)(argv[0]->c.obj.iv[21])-4);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK2831:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M2832(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[21];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2834;
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= local[0];
	local[3]= fqv[88];
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= fqv[89];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,6,local+1,&ftab[11],fqv[60]); /*replace*/
	local[1]= local[0];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[32];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F2518(ctx,1,local+3); /*expand-tab*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	argv[0]->c.obj.iv[21] = w;
	local[1]= argv[0];
	local[2]= fqv[76];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
	goto IF2835;
IF2834:
	local[0]= NIL;
IF2835:
	w = local[0];
	local[0]= w;
BLK2833:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2806(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M2836(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2839;}
	local[0]= NIL;
ENT2839:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
ENT2838:
	if (n>4) maerror();
	local[3]= argv[2];
	local[4]= local[3];
	w = fqv[90];
	if (memq(local[4],w)==NIL) goto IF2841;
	local[4]= argv[0];
	local[5]= fqv[91];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF2842;
IF2841:
	local[4]= local[3];
	if (fqv[92]!=local[4]) goto IF2843;
	local[4]= argv[0];
	local[5]= fqv[93];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2844;
IF2843:
	local[4]= local[3];
	if (fqv[94]!=local[4]) goto IF2845;
	local[4]= argv[0];
	local[5]= fqv[73];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF2846;
IF2845:
	local[4]= local[3];
	if (fqv[95]!=local[4]) goto IF2847;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= fqv[96];
	w = NIL;
	ctx->vsp=local+5;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF2848;
IF2847:
	local[4]= local[3];
	w = fqv[97];
	if (memq(local[4],w)==NIL) goto IF2849;
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto CON2852;
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[93];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON2851;
CON2852:
	local[4]= NIL;
CON2851:
	goto IF2850;
IF2849:
	local[4]= local[3];
	if (fqv[98]!=local[4]) goto IF2853;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2854;
IF2853:
	local[4]= local[3];
	w = fqv[99];
	if (memq(local[4],w)==NIL) goto IF2855;
	if (argv[0]->c.obj.iv[28]==NIL) goto IF2857;
	if (argv[0]->c.obj.iv[29]==NIL) goto IF2857;
	local[4]= argv[0]->c.obj.iv[28];
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2858;
IF2857:
	local[4]= NIL;
IF2858:
	goto IF2856;
IF2855:
	if (T==NIL) goto IF2859;
	local[4]= argv[2];
	local[5]= makeint(32);
	ctx->vsp=local+6;
	w=(pointer)GREQP(ctx,2,local+4); /*>=*/
	if (w==NIL) goto IF2861;
	local[4]= argv[0];
	local[5]= fqv[61];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2862;
IF2861:
	local[4]= NIL;
IF2862:
	goto IF2860;
IF2859:
	local[4]= NIL;
IF2860:
IF2856:
IF2854:
IF2850:
IF2848:
IF2846:
IF2844:
IF2842:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2837:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2863(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	if (argv[0]->c.obj.iv[30]==NIL) goto IF2865;
	if (argv[0]->c.obj.iv[34]==NIL) goto IF2865;
	local[3]= argv[0];
	local[4]= fqv[100];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[30];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[30];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[34];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[34];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[3]= w;
	goto IF2866;
IF2865:
	local[3]= NIL;
IF2866:
	local[3]= argv[0];
	local[4]= fqv[54];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)MKINTVECTOR(ctx,2,local+5); /*integer-vector*/
	argv[0]->c.obj.iv[30] = w;
	argv[0]->c.obj.iv[34] = argv[0]->c.obj.iv[30];
	w = argv[0]->c.obj.iv[34];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2864:
	ctx->vsp=local; return(local[0]);}

/*:region-direction*/
static pointer M2867(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2870;
	local[0]= fqv[101];
	goto CON2869;
CON2870:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON2871;
	local[0]= fqv[102];
	goto CON2869;
CON2871:
	local[0]= argv[2];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2872;
	local[0]= fqv[101];
	goto CON2869;
CON2872:
	local[0]= fqv[102];
	goto CON2869;
CON2873:
	local[0]= NIL;
CON2869:
	w = local[0];
	local[0]= w;
BLK2868:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2874(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[54];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[103];
	local[7]= argv[0]->c.obj.iv[34];
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[103];
	local[8]= argv[0]->c.obj.iv[34];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[100];
	local[9]= NIL;
	local[10]= argv[0]->c.obj.iv[30];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[30];
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[34];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[34];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,7,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[100];
	local[9]= T;
	local[10]= argv[0]->c.obj.iv[30];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[30];
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[3];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,7,local+7); /*send*/
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)MKINTVECTOR(ctx,2,local+7); /*integer-vector*/
	argv[0]->c.obj.iv[34] = w;
	w = argv[0]->c.obj.iv[34];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2875:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2876(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[54];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[36];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[27];
	local[7]= fqv[28];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2877:
	ctx->vsp=local; return(local[0]);}

/*:selection*/
static pointer M2878(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[30]==NIL) goto IF2880;
	if (argv[0]->c.obj.iv[34]==NIL) goto IF2880;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[30];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[34];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[34];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR2884;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto AND2885;
	local[5]= local[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto AND2885;
	goto OR2884;
AND2885:
	goto IF2882;
OR2884:
	local[5]= local[3];
	local[6]= local[4];
	local[7]= local[1];
	local[8]= local[2];
	local[1] = local[5];
	local[2] = local[6];
	local[3] = local[7];
	local[4] = local[8];
	w = NIL;
	local[5]= w;
	goto IF2883;
IF2882:
	local[5]= NIL;
IF2883:
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF2890;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2891;
IF2890:
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,2,local+5); /*subseq*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
IF2891:
	local[5]= local[1];
	local[6]= (pointer)((integer_t)(local[3])-4);
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF2892;
	local[5]= makeint(0);
	local[6]= local[3];
	local[7]= local[1];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,3,local+6); /*-*/
	local[6]= w;
WHL2895:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX2896;
	local[7]= argv[0]->c.obj.iv[31];
	local[8]= local[1];
	local[9]= local[5];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,3,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	w = local[0];
	ctx->vsp=local+8;
	local[0] = cons(ctx,local[7],w);
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL2895;
WHX2896:
	local[7]= NIL;
BLK2897:
	w = NIL;
	local[5]= w;
	goto IF2893;
IF2892:
	local[5]= NIL;
IF2893:
	local[5]= local[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF2898;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2899;
IF2898:
	local[5]= NIL;
IF2899:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
	goto IF2881;
IF2880:
	local[0]= NIL;
IF2881:
	w = local[0];
	local[0]= w;
BLK2879:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2900(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2902:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[104], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2903;
	local[1] = NIL;
KEY2903:
	if (n & (1<<1)) goto KEY2904;
	local[2] = NIL;
KEY2904:
	local[3]= (pointer)get_sym_func(fqv[9]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[10]));
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	if (local[1]==NIL) goto IF2905;
	local[3]= loadglobal(fqv[105]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[11];
	local[6]= fqv[12];
	local[7]= makeint(12);
	local[8]= fqv[13];
	local[9]= (pointer)((integer_t)(argv[0]->c.obj.iv[6])-4);
	local[10]= fqv[15];
	local[11]= argv[0];
	local[12]= fqv[106];
	local[13]= fqv[107];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,10,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[39] = w;
	local[3]= argv[0]->c.obj.iv[39];
	goto IF2906;
IF2905:
	local[3]= NIL;
IF2906:
	if (local[2]==NIL) goto IF2908;
	local[3]= loadglobal(fqv[108]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[11];
	local[6]= fqv[12];
	if (local[1]==NIL) goto IF2911;
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= argv[0]->c.obj.iv[39];
	local[9]= fqv[12];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,3,local+7); /*-*/
	local[7]= w;
	goto IF2912;
IF2911:
	local[7]= argv[0]->c.obj.iv[5];
IF2912:
	local[8]= fqv[13];
	local[9]= makeint(12);
	local[10]= fqv[15];
	local[11]= argv[0];
	local[12]= fqv[106];
	local[13]= fqv[109];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,10,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[40] = w;
	local[3]= argv[0]->c.obj.iv[40];
	goto IF2909;
IF2908:
	local[3]= NIL;
IF2909:
	local[3]= argv[0];
	local[4]= fqv[110];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = argv[0];
	local[0]= w;
BLK2901:
	ctx->vsp=local; return(local[0]);}

/*:locate-scroll-bar*/
static pointer M2913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[39]==NIL) goto IF2915;
	local[0]= argv[0]->c.obj.iv[39];
	local[1]= fqv[56];
	local[2]= makeint(12);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[39];
	local[1]= fqv[111];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[39];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[39];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,3,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[17] = w;
	local[0]= argv[0]->c.obj.iv[17];
	goto IF2916;
IF2915:
	local[0]= NIL;
IF2916:
	if (argv[0]->c.obj.iv[40]==NIL) goto IF2917;
	local[0]= argv[0]->c.obj.iv[40];
	local[1]= fqv[56];
	if (argv[0]->c.obj.iv[39]==NIL) goto IF2919;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[39];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	goto IF2920;
IF2919:
	local[2]= argv[0]->c.obj.iv[5];
IF2920:
	local[3]= makeint(12);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[40];
	local[1]= fqv[111];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= argv[0]->c.obj.iv[40];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[40];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,3,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[16] = w;
	local[0]= argv[0]->c.obj.iv[16];
	goto IF2918;
IF2917:
	local[0]= NIL;
IF2918:
	w = local[0];
	local[0]= w;
BLK2914:
	ctx->vsp=local; return(local[0]);}

/*:goto*/
static pointer M2921(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2924;}
	local[0]= fqv[28];
ENT2924:
ENT2923:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[10]));
	local[3]= fqv[36];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[35] = w;
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[36] = w;
	w = argv[0]->c.obj.iv[36];
	local[0]= w;
BLK2922:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M2925(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[37] = makeint(0);
	argv[0]->c.obj.iv[38] = makeint(0);
	argv[0]->c.obj.iv[35] = makeint(0);
	argv[0]->c.obj.iv[36] = makeint(0);
	local[0]= fqv[112];
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= fqv[113];
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	argv[0]->c.obj.iv[41] = NIL;
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK2926:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M2927(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2928:
	ctx->vsp=local; return(local[0]);}

/*:refresh*/
static pointer M2929(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2933;}
	local[0]= makeint(0);
ENT2933:
	if (n>=4) { local[1]=(argv[3]); goto ENT2932;}
	local[1]= argv[0]->c.obj.iv[16];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
ENT2932:
ENT2931:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= argv[0]->c.obj.iv[21];
	local[4]= argv[0];
	local[5]= fqv[36];
	local[6]= local[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[10]));
	local[6]= fqv[42];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,4,local+4); /*send-message*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= local[0];
	local[7]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,3,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	local[7]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,3,local+5); /*min*/
	local[5]= w;
WHL2935:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX2936;
	local[6]= argv[0];
	local[7]= fqv[19];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[20];
	local[8]= argv[0]->c.obj.iv[18];
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= argv[0]->c.obj.iv[32];
	local[11]= local[0];
	local[12]= local[4];
	local[13]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,3,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,6,local+6); /*send*/
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL2935;
WHX2936:
	local[6]= NIL;
BLK2937:
	w = NIL;
	argv[0]->c.obj.iv[20] = local[2];
	argv[0]->c.obj.iv[21] = local[3];
	local[4]= argv[0];
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (argv[0]->c.obj.iv[41]==NIL) goto IF2938;
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[0]->c.obj.iv[41];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF2939;
IF2938:
	local[4]= NIL;
IF2939:
	if (argv[0]->c.obj.iv[39]==NIL) goto IF2940;
	local[4]= argv[0]->c.obj.iv[39];
	local[5]= fqv[114];
	local[6]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+7;
	w=(pointer)EUSFLOAT(ctx,1,local+6); /*float*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(1.00000000e+00);
	local[8]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+9;
	w=(pointer)EUSFLOAT(ctx,1,local+8); /*float*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF2941;
IF2940:
	local[4]= NIL;
IF2941:
	if (argv[0]->c.obj.iv[40]==NIL) goto IF2942;
	local[4]= argv[0]->c.obj.iv[40];
	local[5]= fqv[114];
	local[6]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+7;
	w=(pointer)EUSFLOAT(ctx,1,local+6); /*float*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(1.00000000e+00);
	local[8]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+9;
	w=(pointer)EUSFLOAT(ctx,1,local+8); /*float*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF2943;
IF2942:
	local[4]= NIL;
IF2943:
	w = local[4];
	local[0]= w;
BLK2930:
	ctx->vsp=local; return(local[0]);}

/*:line-in-window-p*/
static pointer M2944(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[37];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[37];
	local[3]= argv[0]->c.obj.iv[16];
	local[4]= makeint(-1);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
BLK2945:
	ctx->vsp=local; return(local[0]);}

/*:refresh-line*/
static pointer M2946(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2949;}
	local[0]= NIL;
ENT2949:
ENT2948:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[115];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (w==NIL) goto IF2950;
	local[4]= argv[0];
	local[5]= fqv[36];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[40];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (local[0]==NIL) goto CON2953;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[116];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[117];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[116];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[117];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[46];
	local[6]= argv[0]->c.obj.iv[18];
	local[7]= argv[0]->c.obj.iv[19];
	local[8]= argv[0]->c.obj.iv[32];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[116];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[117];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON2952;
CON2953:
	local[4]= argv[0];
	local[5]= fqv[46];
	local[6]= argv[0]->c.obj.iv[18];
	local[7]= argv[0]->c.obj.iv[19];
	local[8]= argv[0]->c.obj.iv[32];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= w;
	goto CON2952;
CON2954:
	local[4]= NIL;
CON2952:
	goto IF2951;
IF2950:
	local[4]= NIL;
IF2951:
	w = local[4];
	local[0]= w;
BLK2947:
	ctx->vsp=local; return(local[0]);}

/*:locate*/
static pointer M2955(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= (pointer)((integer_t)(w)-4);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	if (w==NIL) goto IF2957;
	argv[0]->c.obj.iv[37] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2958;
IF2957:
	local[0]= NIL;
IF2958:
	w = local[0];
	local[0]= w;
BLK2956:
	ctx->vsp=local; return(local[0]);}

/*:display-selection*/
static pointer M2959(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[41]==NIL) goto IF2961;
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[0]->c.obj.iv[41];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2962;
IF2961:
	local[0]= NIL;
IF2962:
	if (argv[2]==NIL) goto IF2963;
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[2];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2964;
IF2963:
	local[0]= NIL;
IF2964:
	argv[0]->c.obj.iv[41] = argv[2];
	w = argv[0]->c.obj.iv[41];
	local[0]= w;
BLK2960:
	ctx->vsp=local; return(local[0]);}

/*:selection*/
static pointer M2965(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[41]==NIL) goto IF2967;
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[0]->c.obj.iv[41];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	goto IF2968;
IF2967:
	local[0]= NIL;
IF2968:
	w = local[0];
	local[0]= w;
BLK2966:
	ctx->vsp=local; return(local[0]);}

/*:scroll-fraction*/
static pointer M2969(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK2970:
	ctx->vsp=local; return(local[0]);}

/*:horizontal-scroll-fraction*/
static pointer M2971(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK2972:
	ctx->vsp=local; return(local[0]);}

/*:scroll*/
static pointer M2973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[2];
	if (!isflt(w)) goto IF2975;
	local[0]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF2976;
IF2975:
	local[0]= NIL;
IF2976:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2977;
	local[0]= argv[0]->c.obj.iv[37];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)MINUS(ctx,1,local+0); /*-*/
	local[0]= w;
	goto IF2978;
IF2977:
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[37];
	local[3]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,3,local+1); /*-*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAX(ctx,2,local+0); /*max*/
	local[0]= w;
IF2978:
	argv[2] = local[0];
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[39];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[37];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[37] = w;
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2980;
	local[0]= argv[0];
	local[1]= fqv[73];
	local[2]= makeint(0);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON2979;
CON2980:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON2981;
	local[0]= argv[0];
	local[1]= fqv[73];
	local[2]= argv[0]->c.obj.iv[16];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON2979;
CON2981:
	local[0]= NIL;
CON2979:
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2974:
	ctx->vsp=local; return(local[0]);}

/*:horizontal-scroll*/
static pointer M2982(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[2];
	if (!isflt(w)) goto IF2984;
	local[0]= argv[0]->c.obj.iv[33];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF2985;
IF2984:
	local[0]= NIL;
IF2985:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2986;
	local[0]= argv[0]->c.obj.iv[38];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)MINUS(ctx,1,local+0); /*-*/
	local[0]= w;
	goto IF2987;
IF2986:
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[33];
	local[2]= argv[0]->c.obj.iv[38];
	local[3]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,3,local+1); /*-*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAX(ctx,2,local+0); /*max*/
	local[0]= w;
IF2987:
	argv[2] = local[0];
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[118];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[38];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[38] = w;
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2983:
	ctx->vsp=local; return(local[0]);}

/*:insert-char*/
static pointer M2988(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2991;}
	local[0]= T;
ENT2991:
ENT2990:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[0]->c.obj.iv[35];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[23]); /*make-string*/
	local[3]= w;
	local[4]= local[3];
	local[5]= makeint(0);
	w = argv[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[4]= loadglobal(fqv[86]);
	local[5]= local[1];
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[36];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[1];
	local[8]= argv[0]->c.obj.iv[36];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,4,local+4); /*concatenate*/
	local[1] = w;
	local[4]= argv[0]->c.obj.iv[31];
	local[5]= argv[0]->c.obj.iv[35];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[0]->c.obj.iv[32];
	local[5]= argv[0]->c.obj.iv[35];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)F2518(ctx,1,local+6); /*expand-tab*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	if (local[0]==NIL) goto IF2992;
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[0]->c.obj.iv[35];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2993;
IF2992:
	local[4]= NIL;
IF2993:
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (local[0]==NIL) goto IF2994;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2995;
IF2994:
	local[4]= NIL;
IF2995:
	w = local[4];
	local[0]= w;
BLK2989:
	ctx->vsp=local; return(local[0]);}

/*:insert-newline*/
static pointer M2996(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2999;}
	local[0]= T;
ENT2999:
ENT2998:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = NIL;
	local[0]= w;
BLK2997:
	ctx->vsp=local; return(local[0]);}

/*:insert*/
static pointer M3000(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3003;}
	local[0]= T;
ENT3003:
ENT3002:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[120]); /*member*/
	if (w==NIL) goto CON3005;
	local[1]= argv[0];
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON3004;
CON3005:
	w = argv[2];
	if (!isnum(w)) goto CON3006;
	local[1]= argv[0];
	local[2]= fqv[122];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON3004;
CON3006:
	w = argv[2];
	if (!isstring(w)) goto CON3007;
	local[1]= makeint(0);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL3009:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX3010;
	local[3]= argv[0];
	local[4]= fqv[61];
	local[5]= argv[2];
	{ register integer_t i=intval(local[1]);
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL3009;
WHX3010:
	local[3]= NIL;
BLK3011:
	w = NIL;
	local[1]= w;
	goto CON3004;
CON3007:
	local[1]= NIL;
CON3004:
	w = local[1];
	local[0]= w;
BLK3001:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M3012(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[10]));
	local[5]= fqv[123];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= argv[0]->c.obj.iv[37];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[38];
	local[5]= argv[0];
	local[6]= fqv[55];
	local[7]= loadglobal(fqv[51]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= (pointer)((integer_t)(w)-4);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	argv[0]->c.obj.iv[35] = w;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= argv[0]->c.obj.iv[35];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	argv[0]->c.obj.iv[36] = w;
	local[5]= argv[0];
	local[6]= fqv[124];
	local[7]= argv[0]->c.obj.iv[35];
	local[8]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF3014;
	local[7]= argv[0]->c.obj.iv[35];
	goto IF3015;
IF3014:
	local[7]= NIL;
IF3015:
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3013:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3016(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0]->c.obj.iv[37];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[38];
	local[5]= argv[0];
	local[6]= fqv[55];
	local[7]= loadglobal(fqv[51]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[41];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto IF3018;
	if (argv[0]->c.obj.iv[28]==NIL) goto IF3018;
	if (argv[0]->c.obj.iv[29]==NIL) goto IF3018;
	local[5]= argv[0]->c.obj.iv[28];
	local[6]= argv[0]->c.obj.iv[29];
	local[7]= argv[0];
	local[8]= fqv[125];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3019;
IF3018:
	local[5]= NIL;
IF3019:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3017:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3020(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[56];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[110];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3021:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3022(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR3026;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR3026;
	goto IF3024;
OR3026:
	local[5]= argv[0];
	local[6]= fqv[56];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3025;
IF3024:
	local[5]= NIL;
IF3025:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3023:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xtext(ctx,n,argv,env)
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
	local[0]= fqv[126];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3027;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF3028;
IF3027:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3028:
	local[0]= fqv[131];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[133]); /*require*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[135];
	local[1]= fqv[136];
	local[2]= fqv[135];
	local[3]= fqv[137];
	local[4]= loadglobal(fqv[138]);
	local[5]= fqv[139];
	local[6]= fqv[140];
	local[7]= fqv[141];
	local[8]= NIL;
	local[9]= fqv[142];
	local[10]= NIL;
	local[11]= fqv[143];
	local[12]= makeint(-1);
	local[13]= fqv[144];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[145]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2519,fqv[11],fqv[146],fqv[147]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2540,fqv[19],fqv[146],fqv[148]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2545,fqv[42],fqv[146],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2547,fqv[150],fqv[146],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2549,fqv[11],fqv[138],fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2560,fqv[24],fqv[138],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2562,fqv[25],fqv[138],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2566,fqv[27],fqv[138],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2575,fqv[156],fqv[138],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2577,fqv[158],fqv[138],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2579,fqv[160],fqv[138],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2581,fqv[162],fqv[138],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2583,fqv[19],fqv[138],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2588,fqv[36],fqv[138],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2592,fqv[91],fqv[138],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2596,fqv[47],fqv[138],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2600,fqv[39],fqv[138],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2608,fqv[118],fqv[138],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2616,fqv[44],fqv[138],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2620,fqv[26],fqv[138],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2622,fqv[40],fqv[138],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2628,fqv[42],fqv[138],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2632,fqv[174],fqv[138],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2637,fqv[41],fqv[138],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2639,fqv[177],fqv[138],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2647,fqv[50],fqv[138],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2658,fqv[180],fqv[138],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2669,fqv[61],fqv[138],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2671,fqv[54],fqv[138],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2673,fqv[55],fqv[138],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2675,fqv[123],fqv[138],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2677,fqv[186],fqv[138],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2679,fqv[56],fqv[138],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2681,fqv[189],fqv[138],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2686,fqv[191],fqv[138],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2688,fqv[62],fqv[138],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2691,fqv[194],fqv[138],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2695,fqv[196],fqv[138],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2697,fqv[198],fqv[138],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2699,fqv[200],fqv[138],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2705,fqv[202],fqv[138],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2711,fqv[204],fqv[65],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2713,fqv[206],fqv[65],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2719,fqv[64],fqv[65],fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F2517,fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F2518,fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2736,fqv[11],fqv[213],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2739,fqv[215],fqv[213],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2741,fqv[26],fqv[213],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2743,fqv[76],fqv[213],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2748,fqv[73],fqv[213],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2756,fqv[77],fqv[213],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2758,fqv[78],fqv[213],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2764,fqv[80],fqv[213],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2780,fqv[100],fqv[213],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2786,fqv[36],fqv[213],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2792,fqv[225],fqv[213],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2796,fqv[227],fqv[213],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2798,fqv[229],fqv[213],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2800,fqv[231],fqv[213],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2802,fqv[85],fqv[213],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2804,fqv[234],fqv[213],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2812,fqv[236],fqv[213],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2820,fqv[238],fqv[213],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2826,fqv[240],fqv[213],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2830,fqv[61],fqv[213],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2832,fqv[93],fqv[213],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2836,fqv[202],fqv[213],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2863,fqv[123],fqv[213],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2867,fqv[103],fqv[213],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2874,fqv[247],fqv[213],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2876,fqv[186],fqv[213],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2878,fqv[125],fqv[213],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2900,fqv[11],fqv[251],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2913,fqv[110],fqv[251],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2921,fqv[36],fqv[251],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2925,fqv[26],fqv[251],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2927,fqv[227],fqv[251],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2929,fqv[73],fqv[251],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2944,fqv[115],fqv[251],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2946,fqv[76],fqv[251],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2955,fqv[260],fqv[251],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2959,fqv[124],fqv[251],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2965,fqv[125],fqv[251],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2969,fqv[264],fqv[251],fqv[265]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2971,fqv[266],fqv[251],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2973,fqv[39],fqv[251],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2982,fqv[118],fqv[251],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2988,fqv[122],fqv[251],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2996,fqv[121],fqv[251],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3000,fqv[61],fqv[251],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3012,fqv[123],fqv[251],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3016,fqv[186],fqv[251],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3020,fqv[56],fqv[251],fqv[275]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3022,fqv[189],fqv[251],fqv[276]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
