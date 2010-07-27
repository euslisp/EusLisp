/* Xcolor.c :  entry=Xcolor */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xcolor.h"
#pragma init (register_Xcolor)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xcolor();
extern pointer build_quote_vector();
static register_Xcolor()
  { add_module_initializer("___Xcolor", ___Xcolor);}

static pointer F1422();
static pointer F1423();
static pointer F1424();
static pointer F1425();
static pointer F1426();
static pointer F1427();
static pointer F1428();
static pointer F1429();
static pointer F1430();
static pointer F1431();
static pointer F1432();
static pointer F1433();
static pointer F1434();
static pointer F1435();
static pointer F1436();
static pointer F1437();
static pointer F1438();
static pointer F1439();
static pointer F1440();
static pointer F1441();
static pointer F1442();
static pointer F1443();
static pointer F1444();
static pointer F1445();
static pointer F1446();
static pointer F1447();

/*list-visuals*/
static pointer F1422(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT1450;}
	local[0]= makeint(0);
ENT1450:
ENT1449:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= makeint(64);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*make-string*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= fqv[1];
WHL1452:
	if (local[7]==NIL) goto WHX1453;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= makeint(0);
	local[9]= makeint(3);
WHL1457:
	local[10]= local[8];
	w = local[9];
	if ((integer_t)local[10] >= (integer_t)w) goto WHX1458;
	local[10]= local[8];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1] = (pointer)((integer_t)local[10] + (integer_t)w);
	local[10]= loadglobal(fqv[2]);
	local[11]= local[0];
	local[12]= local[6];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,5,local+10,&ftab[1],fqv[3]); /*matchvisualinfo*/
	local[3] = w;
	local[10]= T;
	local[11]= fqv[4];
	local[12]= local[6];
	local[13]= local[1];
	local[14]= local[13];
	if (fqv[5]!=local[14]) goto IF1461;
	local[14]= fqv[6];
	goto IF1462;
IF1461:
	local[14]= local[13];
	if (fqv[7]!=local[14]) goto IF1463;
	local[14]= fqv[8];
	goto IF1464;
IF1463:
	local[14]= local[13];
	if (fqv[9]!=local[14]) goto IF1465;
	local[14]= fqv[10];
	goto IF1466;
IF1465:
	local[14]= NIL;
IF1466:
IF1464:
IF1462:
	w = local[14];
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,4,local+10); /*format*/
	local[10]= local[3];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON1468;
	local[10]= T;
	local[11]= fqv[11];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,2,local+10); /*format*/
	local[10]= w;
	goto CON1467;
CON1468:
	local[10]= local[2];
	local[11]= makeint(0);
	local[12]= fqv[12];
	ctx->vsp=local+13;
	w=(pointer)PEEK(ctx,3,local+10); /*system:peek*/
	local[4] = w;
	local[10]= local[2];
	local[11]= makeint(4);
	local[12]= fqv[12];
	ctx->vsp=local+13;
	w=(pointer)PEEK(ctx,3,local+10); /*system:peek*/
	local[5] = w;
	local[10]= T;
	local[11]= fqv[13];
	local[12]= local[4];
	local[13]= local[5];
	local[14]= local[4];
	local[15]= loadglobal(fqv[14]);
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w==NIL) goto IF1470;
	local[14]= fqv[15];
	goto IF1471;
IF1470:
	local[14]= fqv[16];
IF1471:
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,5,local+10); /*format*/
	local[10]= w;
	goto CON1467;
CON1469:
	local[10]= NIL;
CON1467:
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL1457;
WHX1458:
	local[10]= NIL;
BLK1459:
	w = NIL;
	goto WHL1452;
WHX1453:
	local[8]= NIL;
BLK1454:
	w = NIL;
	local[0]= w;
BLK1448:
	ctx->vsp=local; return(local[0]);}

/*visual-type*/
static pointer F1423(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isint(w)) goto CON1474;
	local[0]= argv[0];
	goto CON1473;
CON1474:
	w = argv[0];
	if (!issymbol(w)) goto CON1475;
	local[0]= argv[0];
	local[1]= fqv[17];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[18]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	goto CON1473;
CON1475:
	local[0]= NIL;
CON1473:
	w = local[0];
	local[0]= w;
BLK1472:
	ctx->vsp=local; return(local[0]);}

/*find-visual*/
static pointer F1424(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1478;}
	local[0]= makeint(0);
ENT1478:
ENT1477:
	if (n>3) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1423(ctx,1,local+1); /*visual-type*/
	argv[0] = w;
	w = argv[0];
	if (isint(w)) goto IF1479;
	local[1]= fqv[19];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF1480;
IF1479:
	local[1]= NIL;
IF1480:
	local[1]= makeint(16);
	local[2]= fqv[20];
	local[3]= fqv[21];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,3,local+1,&ftab[3],fqv[22]); /*make-array*/
	local[1]= w;
	local[2]= loadglobal(fqv[2]);
	local[3]= local[0];
	local[4]= argv[1];
	local[5]= argv[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,5,local+2,&ftab[1],fqv[3]); /*matchvisualinfo*/
	local[2]= w;
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1481;
	local[2]= NIL;
	goto IF1482;
IF1481:
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
IF1482:
	w = local[2];
	local[0]= w;
BLK1476:
	ctx->vsp=local; return(local[0]);}

/*visual-id*/
static pointer F1425(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1483:
	ctx->vsp=local; return(local[0]);}

/*visual-class*/
static pointer F1426(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1484:
	ctx->vsp=local; return(local[0]);}

/*visual-red-mask*/
static pointer F1427(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(12);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1485:
	ctx->vsp=local; return(local[0]);}

/*visual-green-mask*/
static pointer F1428(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(16);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1486:
	ctx->vsp=local; return(local[0]);}

/*visual-blue-mask*/
static pointer F1429(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(20);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1487:
	ctx->vsp=local; return(local[0]);}

/*visual-masks*/
static pointer F1430(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(12);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(16);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,2,local+1); /*system:peek*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint(20);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)PEEK(ctx,2,local+2); /*system:peek*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK1488:
	ctx->vsp=local; return(local[0]);}

/*visual-bits-per-rgb*/
static pointer F1431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(24);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1489:
	ctx->vsp=local; return(local[0]);}

/*visual-depth*/
static pointer F1432(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[23]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[18]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (local[0]==NIL) goto IF1491;
	local[1]= local[0];
	goto IF1492;
IF1491:
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
IF1492:
	w = local[1];
	local[0]= w;
BLK1490:
	ctx->vsp=local; return(local[0]);}

/*best-visual*/
static pointer F1433(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT1497;}
	local[0]= fqv[25];
ENT1497:
	if (n>=2) { local[1]=(argv[1]); goto ENT1496;}
	local[1]= fqv[26];
ENT1496:
	if (n>=3) { local[2]=(argv[2]); goto ENT1495;}
	local[2]= makeint(0);
ENT1495:
ENT1494:
	if (n>3) maerror();
	local[3]= NIL;
	local[4]= makeint(64);
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[0]); /*make-string*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= (pointer)get_sym_func(fqv[27]);
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[0] = w;
	local[8]= NIL;
	local[9]= local[1];
WHL1499:
	if (local[9]==NIL) goto WHX1500;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= local[0];
WHL1504:
	if (local[11]==NIL) goto WHX1505;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= loadglobal(fqv[2]);
	local[13]= local[2];
	local[14]= local[8];
	local[15]= local[10];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(*ftab[1])(ctx,5,local+12,&ftab[1],fqv[3]); /*matchvisualinfo*/
	local[12]= w;
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(*ftab[4])(ctx,2,local+12,&ftab[4],fqv[28]); /*/=*/
	local[5] = w;
	if (local[5]==NIL) goto IF1508;
	local[12]= local[4];
	local[13]= makeint(0);
	local[14]= fqv[12];
	ctx->vsp=local+15;
	w=(pointer)PEEK(ctx,3,local+12); /*system:peek*/
	local[6] = w;
	local[12]= local[6];
	local[13]= local[8];
	local[14]= local[10];
	local[15]= local[14];
	if (fqv[29]!=local[15]) goto IF1511;
	local[15]= fqv[30];
	goto IF1512;
IF1511:
	local[15]= local[14];
	if (fqv[31]!=local[15]) goto IF1513;
	local[15]= fqv[32];
	goto IF1514;
IF1513:
	local[15]= local[14];
	if (fqv[33]!=local[15]) goto IF1515;
	local[15]= fqv[34];
	goto IF1516;
IF1515:
	local[15]= NIL;
IF1516:
IF1514:
IF1512:
	w = local[15];
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	ctx->vsp=local+12;
	local[0]=w;
	goto BLK1493;
	goto IF1509;
IF1508:
	local[12]= NIL;
IF1509:
	goto WHL1504;
WHX1505:
	local[12]= NIL;
BLK1506:
	w = NIL;
	goto WHL1499;
WHX1500:
	local[10]= NIL;
BLK1501:
	w = NIL;
	local[0]= w;
BLK1493:
	ctx->vsp=local; return(local[0]);}

/*xcolor-pixel*/
static pointer F1434(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1517:
	ctx->vsp=local; return(local[0]);}

/*set-xcolor-pixel*/
static pointer F1435(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1518:
	ctx->vsp=local; return(local[0]);}

/*xcolor-red*/
static pointer F1436(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	local[2]= fqv[35];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1519:
	ctx->vsp=local; return(local[0]);}

/*set-xcolor-red*/
static pointer F1437(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(4);
	local[3]= fqv[35];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1520:
	ctx->vsp=local; return(local[0]);}

/*xcolor-green*/
static pointer F1438(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(6);
	local[2]= fqv[35];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1521:
	ctx->vsp=local; return(local[0]);}

/*set-xcolor-green*/
static pointer F1439(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(6);
	local[3]= fqv[35];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1522:
	ctx->vsp=local; return(local[0]);}

/*xcolor-blue*/
static pointer F1440(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(8);
	local[2]= fqv[35];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1523:
	ctx->vsp=local; return(local[0]);}

/*set-xcolor-blue*/
static pointer F1441(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(8);
	local[3]= fqv[35];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1524:
	ctx->vsp=local; return(local[0]);}

/*xcolor-flags*/
static pointer F1442(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(10);
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1525:
	ctx->vsp=local; return(local[0]);}

/*set-xcolor-flags*/
static pointer F1443(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(10);
	local[3]= fqv[36];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1526:
	ctx->vsp=local; return(local[0]);}

/*xcolor-pad*/
static pointer F1444(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(11);
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1527:
	ctx->vsp=local; return(local[0]);}

/*set-xcolor-pad*/
static pointer F1445(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(11);
	local[3]= fqv[36];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1528:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M1529(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1434(ctx,1,local+0); /*xcolor-pixel*/
	local[0]= w;
BLK1530:
	ctx->vsp=local; return(local[0]);}

/*:red*/
static pointer M1531(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F1436(ctx,1,local+2); /*xcolor-red*/
	local[1] = w;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1533;
	local[2]= makeint(65536);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	goto IF1534;
IF1533:
	local[2]= local[1];
IF1534:
	w = local[2];
	local[0]= w;
BLK1532:
	ctx->vsp=local; return(local[0]);}

/*:green*/
static pointer M1535(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F1438(ctx,1,local+2); /*xcolor-green*/
	local[1] = w;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1537;
	local[2]= makeint(65536);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	goto IF1538;
IF1537:
	local[2]= local[1];
IF1538:
	w = local[2];
	local[0]= w;
BLK1536:
	ctx->vsp=local; return(local[0]);}

/*:blue*/
static pointer M1539(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F1440(ctx,1,local+2); /*xcolor-blue*/
	local[1] = w;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1541;
	local[2]= makeint(65536);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	goto IF1542;
IF1541:
	local[2]= local[1];
IF1542:
	w = local[2];
	local[0]= w;
BLK1540:
	ctx->vsp=local; return(local[0]);}

/*:rgb*/
static pointer M1543(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[39];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK1544:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1545(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT1548;}
	local[0]= makeint(7);
ENT1548:
ENT1547:
	if (n>7) maerror();
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F1435(ctx,2,local+1); /*set-xcolor-pixel*/
	local[1]= argv[0];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F1437(ctx,2,local+1); /*set-xcolor-red*/
	local[1]= argv[0];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F1439(ctx,2,local+1); /*set-xcolor-green*/
	local[1]= argv[0];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)F1441(ctx,2,local+1); /*set-xcolor-blue*/
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F1443(ctx,2,local+1); /*set-xcolor-flags*/
	w = argv[0];
	local[0]= w;
BLK1546:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M1549(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1550:
	ctx->vsp=local; return(local[0]);}

/*:query*/
static pointer M1551(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= loadglobal(fqv[40]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[41];
	local[5]= argv[2];
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[1] = w;
	local[2]= loadglobal(fqv[2]);
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,3,local+2,&ftab[5],fqv[42]); /*querycolor*/
	local[2]= local[1];
	local[3]= fqv[43];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0]= w;
BLK1552:
	ctx->vsp=local; return(local[0]);}

/*:set-window*/
static pointer M1554(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= argv[2];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,3,local+0,&ftab[6],fqv[45]); /*setwindowcolormap*/
	local[0]= w;
BLK1555:
	ctx->vsp=local; return(local[0]);}

/*:destroy*/
static pointer M1556(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[46]); /*freecolormap*/
	local[0]= w;
BLK1557:
	ctx->vsp=local; return(local[0]);}

/*:alloc*/
static pointer M1558(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1562;}
	local[0]= NIL;
ENT1562:
	if (n>=5) { local[1]=(argv[4]); goto ENT1561;}
	local[1]= NIL;
ENT1561:
ENT1560:
	if (n>5) maerror();
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= NIL;
	local[5]= argv[2];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK1559:
	ctx->vsp=local; return(local[0]);}

/*:store*/
static pointer M1563(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1567;}
	local[0]= NIL;
ENT1567:
	if (n>=6) { local[1]=(argv[5]); goto ENT1566;}
	local[1]= NIL;
ENT1566:
ENT1565:
	if (n>6) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[3];
	local[7]= loadglobal(fqv[40]);
	ctx->vsp=local+8;
	w=(pointer)DERIVEDP(ctx,2,local+6); /*derivedp*/
	if (w==NIL) goto CON1569;
	local[4] = argv[3];
	local[6]= local[4];
	goto CON1568;
CON1569:
	w = argv[3];
	if (issymbol(w)) goto OR1571;
	w = argv[3];
	if (isstring(w)) goto OR1571;
	goto CON1570;
OR1571:
	local[6]= loadglobal(fqv[40]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[41];
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= makeint(0);
	local[12]= makeint(0);
	local[13]= makeint(7);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,7,local+7); /*send*/
	w = local[6];
	local[4] = w;
	local[6]= loadglobal(fqv[40]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[41];
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= makeint(0);
	local[12]= makeint(0);
	local[13]= makeint(7);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,7,local+7); /*send*/
	w = local[6];
	local[3] = w;
	local[6]= loadglobal(fqv[2]);
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(*ftab[8])(ctx,1,local+8,&ftab[8],fqv[48]); /*string*/
	local[8]= w;
	local[9]= local[4];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[9])(ctx,5,local+6,&ftab[9],fqv[49]); /*lookupcolor*/
	local[5] = w;
	local[6]= local[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF1574;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK1564;
	goto IF1575;
IF1574:
	local[6]= NIL;
IF1575:
	goto CON1568;
CON1570:
	w = argv[3];
	if (!isint(w)) goto CON1576;
	w = local[0];
	if (!isint(w)) goto CON1576;
	w = local[1];
	if (!isint(w)) goto CON1576;
	local[6]= loadglobal(fqv[40]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[41];
	local[9]= makeint(0);
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	goto CON1568;
CON1576:
	local[6]= fqv[50];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto CON1568;
CON1578:
	local[6]= NIL;
CON1568:
	if (argv[2]!=NIL) goto CON1580;
	local[6]= loadglobal(fqv[2]);
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(*ftab[10])(ctx,3,local+6,&ftab[10],fqv[51]); /*alloccolor*/
	local[6]= local[4];
	local[7]= fqv[52];
	local[8]= fqv[53];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON1579;
CON1580:
	w = argv[2];
	if (!isint(w)) goto CON1581;
	local[6]= local[4];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)F1435(ctx,2,local+6); /*set-xcolor-pixel*/
	local[6]= makeint(0);
	local[7]= loadglobal(fqv[2]);
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,3,local+7,&ftab[11],fqv[54]); /*storecolor*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF1582;
	local[6]= NIL;
	goto IF1583;
IF1582:
	local[6]= argv[2];
IF1583:
	goto CON1579;
CON1581:
	local[6]= fqv[55];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto CON1579;
CON1584:
	local[6]= NIL;
CON1579:
	w = local[6];
	local[0]= w;
BLK1564:
	ctx->vsp=local; return(local[0]);}

/*:store-hls*/
static pointer M1585(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[3];
	local[1]= argv[4];
	local[2]= argv[5];
	local[3]= makeint(65536);
	ctx->vsp=local+4;
	w=(*ftab[12])(ctx,4,local+0,&ftab[12],fqv[56]); /*geometry:hls2rgb*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= argv[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[0]= w;
BLK1586:
	ctx->vsp=local; return(local[0]);}

/*:lut-list*/
static pointer M1587(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK1588:
	ctx->vsp=local; return(local[0]);}

/*:lut-names*/
static pointer M1589(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[57]);
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK1590:
	ctx->vsp=local; return(local[0]);}

/*:lut*/
static pointer M1591(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[18]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK1592:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M1593(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[18]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
BLK1594:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M1595(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK1596:
	ctx->vsp=local; return(local[0]);}

/*:planes*/
static pointer M1597(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK1598:
	ctx->vsp=local; return(local[0]);}

/*:plane-bits*/
static pointer M1599(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL1602:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX1603;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LOGIOR(ctx,2,local+3); /*logior*/
	local[0] = w;
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL1602;
WHX1603:
	local[3]= NIL;
BLK1604:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1600:
	ctx->vsp=local; return(local[0]);}

/*:plane-shifts*/
static pointer M1605(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
WHL1607:
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LOGBITP(ctx,2,local+1); /*logbitp*/
	if (w!=NIL) goto WHX1608;
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL1607;
WHX1608:
	local[1]= NIL;
BLK1609:
	w = local[0];
	local[0]= w;
BLK1606:
	ctx->vsp=local; return(local[0]);}

/*:free*/
static pointer M1610(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1613;}
	local[0]= NIL;
ENT1613:
ENT1612:
	if (n>3) maerror();
	w = local[0];
	if (!isint(w)) goto CON1615;
	local[1]= loadglobal(fqv[2]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MKINTVECTOR(ctx,1,local+3); /*integer-vector*/
	local[3]= w;
	local[4]= makeint(1);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKINTVECTOR(ctx,1,local+5); /*integer-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,5,local+1,&ftab[13],fqv[59]); /*freecolors*/
	local[1]= w;
	goto CON1614;
CON1615:
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[18]); /*assoc*/
	if (w==NIL) goto CON1616;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[18]); /*assoc*/
	local[0] = w;
	local[1]= loadglobal(fqv[2]);
	local[2]= argv[0]->c.obj.iv[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKINTVECTOR(ctx,1,local+5); /*integer-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,5,local+1,&ftab[13],fqv[59]); /*freecolors*/
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[60]); /*delete*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	goto CON1614;
CON1616:
	w = local[0];
	if (iscons(w)) goto OR1618;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)VECTORP(ctx,1,local+1); /*vectorp*/
	if (w!=NIL) goto OR1618;
	goto CON1617;
OR1618:
	local[1]= makeint(0);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL1620:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX1621;
	local[3]= loadglobal(fqv[2]);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKINTVECTOR(ctx,1,local+5); /*integer-vector*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKINTVECTOR(ctx,1,local+6); /*integer-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[13])(ctx,4,local+3,&ftab[13],fqv[59]); /*freecolors*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL1620;
WHX1621:
	local[3]= NIL;
BLK1622:
	w = NIL;
	local[1]= w;
	goto CON1614;
CON1617:
	local[1]= local[0];
	if (T!=local[1]) goto CON1623;
	local[1]= loadglobal(fqv[2]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[61];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,5,local+1,&ftab[13],fqv[59]); /*freecolors*/
	local[1]= w;
	goto CON1614;
CON1623:
	local[1]= NIL;
CON1614:
	w = local[1];
	local[0]= w;
BLK1611:
	ctx->vsp=local; return(local[0]);}

/*:allocate-private-colors*/
static pointer M1624(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1627;}
	local[0]= makeint(0);
ENT1627:
ENT1626:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[20];
	local[3]= fqv[21];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,3,local+1,&ftab[3],fqv[22]); /*make-array*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= local[0];
	local[2]= fqv[20];
	local[3]= fqv[21];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,3,local+1,&ftab[3],fqv[22]); /*make-array*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint(0);
	local[5]= loadglobal(fqv[2]);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(0);
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= local[0];
	local[10]= argv[0]->c.obj.iv[3];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,7,local+5,&ftab[15],fqv[62]); /*alloccolorcells*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF1628;
	local[4]= fqv[63];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,2,local+4,&ftab[16],fqv[64]); /*warn*/
	local[4]= NIL;
	goto IF1629;
IF1628:
	local[4]= NIL;
	local[5]= loadglobal(fqv[65]);
	local[6]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,2,local+5); /*concatenate*/
	local[5]= w;
WHL1631:
	if (local[5]==NIL) goto WHX1632;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= makeint(0);
	local[7]= makeint(2);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[66]); /*expt*/
	local[7]= w;
WHL1636:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX1637;
	local[2] = local[6];
	local[3] = makeint(0);
	local[8]= makeint(0);
	local[9]= local[0];
WHL1640:
	local[10]= local[8];
	w = local[9];
	if ((integer_t)local[10] >= (integer_t)w) goto WHX1641;
	local[10]= local[2];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)LOGAND(ctx,2,local+10); /*logand*/
	local[10]= w;
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)NUMEQUAL(ctx,2,local+10); /*=*/
	if (w==NIL) goto IF1643;
	local[10]= local[3];
	local[11]= argv[0]->c.obj.iv[2];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[3] = w;
	local[10]= local[3];
	goto IF1644;
IF1643:
	local[10]= NIL;
IF1644:
	local[10]= local[2];
	local[11]= makeint(-1);
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[2] = w;
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL1640;
WHX1641:
	local[10]= NIL;
BLK1642:
	w = NIL;
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LOGIOR(ctx,2,local+8); /*logior*/
	local[8]= w;
	w = local[1];
	ctx->vsp=local+9;
	local[1] = cons(ctx,local[8],w);
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL1636;
WHX1637:
	local[8]= NIL;
BLK1638:
	w = NIL;
	goto WHL1631;
WHX1632:
	local[6]= NIL;
BLK1633:
	local[6]= local[1];
	local[7]= loadglobal(fqv[67]);
	ctx->vsp=local+8;
	w=(pointer)COERCE(ctx,2,local+6); /*coerce*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[4]= w;
IF1629:
	w = local[4];
	local[0]= w;
BLK1625:
	ctx->vsp=local; return(local[0]);}

/*:allocate-colors*/
static pointer M1645(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1649;}
	local[0]= NIL;
ENT1649:
	if (n>=5) { local[1]=(argv[4]); goto ENT1648;}
	local[1]= makeint(0);
ENT1648:
ENT1647:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= NIL;
	if (local[0]==NIL) goto CON1651;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	if (local[2]!=NIL) goto IF1652;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK1646;
	goto IF1653;
IF1652:
	local[6]= NIL;
IF1653:
	goto CON1650;
CON1651:
	local[6]= local[4];
	local[7]= fqv[20];
	local[8]= fqv[21];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,3,local+6,&ftab[3],fqv[22]); /*make-array*/
	local[2] = w;
	local[6]= local[2];
	goto CON1650;
CON1654:
	local[6]= NIL;
CON1650:
	local[6]= NIL;
	local[7]= argv[2];
WHL1656:
	if (local[7]==NIL) goto WHX1657;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[0]==NIL) goto CON1661;
	w = local[6];
	if (!iscons(w)) goto IF1662;
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= w;
	goto IF1663;
IF1662:
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
IF1663:
	goto CON1660;
CON1661:
	w = local[6];
	if (!iscons(w)) goto IF1665;
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= w;
	goto IF1666;
IF1665:
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= NIL;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
IF1666:
	local[5] = local[8];
	if (local[5]!=NIL) goto IF1667;
	local[8]= argv[0];
	local[9]= fqv[69];
	local[10]= local[2];
	local[11]= makeint(0);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SUBSEQ(ctx,3,local+10); /*subseq*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= fqv[70];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF1668;
IF1667:
	local[8]= NIL;
IF1668:
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[8]= w;
	goto CON1660;
CON1664:
	local[8]= NIL;
CON1660:
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL1656;
WHX1657:
	local[8]= NIL;
BLK1658:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1646:
	ctx->vsp=local; return(local[0]);}

/*:define-lut*/
static pointer M1669(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1672;}
	local[0]= NIL;
ENT1672:
ENT1671:
	if (n>5) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[18]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	if (local[1]!=NIL) goto CON1674;
	local[3]= argv[0];
	local[4]= fqv[71];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF1675;
	local[3]= fqv[72];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF1676;
IF1675:
	local[3]= NIL;
IF1676:
	local[3]= argv[2];
	w = local[2];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	argv[0]->c.obj.iv[4] = cons(ctx,local[3],w);
	local[3]= local[2];
	goto CON1673;
CON1674:
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	if (w!=local[3]) goto CON1677;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	goto CON1673;
CON1677:
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto CON1673;
CON1678:
	local[3]= NIL;
CON1673:
	w = local[3];
	local[0]= w;
BLK1670:
	ctx->vsp=local; return(local[0]);}

/*:define-gray-scale-lut*/
static pointer M1679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1682;}
	local[0]= NIL;
ENT1682:
ENT1681:
	if (n>5) maerror();
	local[1]= NIL;
	local[2]= makeint(65536);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= (pointer)((integer_t)(local[2])-4);
	local[4]= makeint(0);
	local[5]= argv[3];
WHL1684:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX1685;
	local[6]= local[3];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	w = local[1];
	ctx->vsp=local+7;
	local[1] = cons(ctx,local[6],w);
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[3] = w;
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL1684;
WHX1685:
	local[6]= NIL;
BLK1686:
	w = NIL;
	local[4]= argv[0];
	local[5]= fqv[74];
	local[6]= argv[2];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[0]= w;
BLK1680:
	ctx->vsp=local; return(local[0]);}

/*:define-rgb-lut*/
static pointer M1687(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1692;}
	local[0]= argv[3];
ENT1692:
	if (n>=6) { local[1]=(argv[5]); goto ENT1691;}
	local[1]= local[0];
ENT1691:
	if (n>=7) { local[2]=(argv[6]); goto ENT1690;}
	local[2]= NIL;
ENT1690:
ENT1689:
	if (n>7) maerror();
	local[3]= argv[3];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,3,local+3); /*+*/
	local[3]= w;
	local[4]= makeint(2);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[66]); /*expt*/
	local[4]= w;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= makeint(2);
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[66]); /*expt*/
	argv[3] = w;
	local[7]= makeint(2);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[66]); /*expt*/
	local[0] = w;
	local[7]= makeint(2);
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[66]); /*expt*/
	local[1] = w;
	local[7]= makeint(0);
	local[8]= argv[3];
WHL1694:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX1695;
	local[9]= makeint(0);
	local[10]= local[0];
WHL1698:
	local[11]= local[9];
	w = local[10];
	if ((integer_t)local[11] >= (integer_t)w) goto WHX1699;
	local[11]= makeint(0);
	local[12]= local[1];
WHL1702:
	local[13]= local[11];
	w = local[12];
	if ((integer_t)local[13] >= (integer_t)w) goto WHX1703;
	local[13]= makeint(65535);
	local[14]= (pointer)((integer_t)(local[7])+4);
	local[15]= argv[3];
	ctx->vsp=local+16;
	w=(pointer)EUSFLOAT(ctx,1,local+15); /*float*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)ROUND(ctx,1,local+13); /*round*/
	local[13]= w;
	local[14]= makeint(65535);
	local[15]= (pointer)((integer_t)(local[9])+4);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)EUSFLOAT(ctx,1,local+16); /*float*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)QUOTIENT(ctx,2,local+15); /*/*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ROUND(ctx,1,local+14); /*round*/
	local[14]= w;
	local[15]= makeint(65535);
	local[16]= (pointer)((integer_t)(local[11])+4);
	local[17]= local[1];
	ctx->vsp=local+18;
	w=(pointer)EUSFLOAT(ctx,1,local+17); /*float*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,2,local+16); /*/*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)ROUND(ctx,1,local+15); /*round*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	w = local[5];
	ctx->vsp=local+14;
	local[5] = cons(ctx,local[13],w);
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[11] = (pointer)((integer_t)(local[11])+4);
	goto WHL1702;
WHX1703:
	local[13]= NIL;
BLK1704:
	w = NIL;
	local[9] = (pointer)((integer_t)(local[9])+4);
	goto WHL1698;
WHX1699:
	local[11]= NIL;
BLK1700:
	w = NIL;
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL1694;
WHX1695:
	local[9]= NIL;
BLK1696:
	w = NIL;
	local[7]= argv[0];
	local[8]= fqv[74];
	local[9]= argv[2];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)NREVERSE(ctx,1,local+10); /*nreverse*/
	local[10]= w;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[0]= w;
BLK1688:
	ctx->vsp=local; return(local[0]);}

/*:define-hls-lut*/
static pointer M1705(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<8) maerror();
	if (n>=9) { local[0]=(argv[8]); goto ENT1708;}
	local[0]= NIL;
ENT1708:
ENT1707:
	if (n>9) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[5];
	local[4]= argv[6];
	local[5]= argv[5];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= argv[3];
WHL1710:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX1711;
	local[7]= argv[4];
	local[8]= local[3];
	local[9]= argv[7];
	local[10]= makeint(65535);
	ctx->vsp=local+11;
	w=(*ftab[12])(ctx,4,local+7,&ftab[12],fqv[56]); /*geometry:hls2rgb*/
	local[1] = w;
	local[7]= local[1];
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[3] = w;
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL1710;
WHX1711:
	local[7]= NIL;
BLK1712:
	w = NIL;
	local[5]= argv[0];
	local[6]= fqv[74];
	local[7]= argv[2];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[0]= w;
BLK1706:
	ctx->vsp=local; return(local[0]);}

/*:define-rainbow-lut*/
static pointer M1713(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1721;}
	local[0]= makeint(32);
ENT1721:
	if (n>=5) { local[1]=(argv[4]); goto ENT1720;}
	local[1]= makeint(0);
ENT1720:
	if (n>=6) { local[2]=(argv[5]); goto ENT1719;}
	local[2]= makeint(360);
ENT1719:
	if (n>=7) { local[3]=(argv[6]); goto ENT1718;}
	local[3]= makeflt(5.00000000e-01);
ENT1718:
	if (n>=8) { local[4]=(argv[7]); goto ENT1717;}
	local[4]= makeflt(1.00000000e+00);
ENT1717:
	if (n>=9) { local[5]=(argv[8]); goto ENT1716;}
	local[5]= NIL;
ENT1716:
ENT1715:
	if (n>9) maerror();
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)EUSFLOAT(ctx,1,local+10); /*float*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= local[0];
WHL1723:
	local[12]= local[10];
	w = local[11];
	if ((integer_t)local[12] >= (integer_t)w) goto WHX1724;
	local[12]= local[8];
	local[13]= local[3];
	local[14]= local[4];
	local[15]= makeint(65535);
	ctx->vsp=local+16;
	w=(*ftab[12])(ctx,4,local+12,&ftab[12],fqv[56]); /*geometry:hls2rgb*/
	local[6] = w;
	local[12]= local[6];
	w = local[7];
	ctx->vsp=local+13;
	local[7] = cons(ctx,local[12],w);
	local[12]= local[8];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[8] = w;
	local[10] = (pointer)((integer_t)(local[10])+4);
	goto WHL1723;
WHX1724:
	local[12]= NIL;
BLK1725:
	w = NIL;
	local[10]= argv[0];
	local[11]= fqv[74];
	local[12]= argv[2];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)NREVERSE(ctx,1,local+13); /*nreverse*/
	local[13]= w;
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,5,local+10); /*send*/
	local[0]= w;
BLK1714:
	ctx->vsp=local; return(local[0]);}

/*:install*/
static pointer M1726(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[75]); /*installcolormap*/
	local[0]= w;
BLK1727:
	ctx->vsp=local; return(local[0]);}

/*:uninstall*/
static pointer M1728(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[76]); /*uninstallcolormap*/
	local[0]= w;
BLK1729:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1730(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1733;}
	local[0]= NIL;
ENT1733:
ENT1732:
	if (n>3) maerror();
	argv[0]->c.obj.iv[1] = local[0];
	argv[0]->c.obj.iv[4] = NIL;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= loadglobal(fqv[77]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,3,local+1,&ftab[20],fqv[78]); /*sethash*/
	w = argv[0];
	local[0]= w;
BLK1731:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M1734(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[79], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1736;
	local[0] = makeint(0);
KEY1736:
	if (n & (1<<1)) goto KEY1737;
	local[1] = makeint(1);
KEY1737:
	if (n & (1<<2)) goto KEY1738;
	local[2] = loadglobal(fqv[14]);
KEY1738:
	if (n & (1<<3)) goto KEY1739;
	local[3] = NIL;
KEY1739:
	local[4]= argv[0];
	local[5]= fqv[41];
	local[6]= loadglobal(fqv[2]);
	local[7]= loadglobal(fqv[80]);
	local[8]= fqv[44];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[2];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(*ftab[21])(ctx,4,local+6,&ftab[21],fqv[81]); /*createcolormap*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK1735:
	ctx->vsp=local; return(local[0]);}

/*:get-pixel*/
static pointer M1740(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!isnum(w)) goto IF1742;
	local[0]= argv[2];
	goto IF1743;
IF1742:
	local[0]= argv[0];
	local[1]= fqv[82];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF1743:
	w = local[0];
	local[0]= w;
BLK1741:
	ctx->vsp=local; return(local[0]);}

/*:copy-colors*/
static pointer M1744(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1747;}
	local[0]= (pointer)((integer_t)(argv[3])+4);
ENT1747:
ENT1746:
	if (n>5) maerror();
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= local[0];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
WHL1749:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX1750;
	local[4]= (pointer)get_sym_func(fqv[83]);
	local[5]= argv[0];
	local[6]= fqv[82];
	local[7]= argv[2];
	local[8]= fqv[84];
	local[9]= argv[3];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL1749;
WHX1750:
	local[4]= NIL;
BLK1751:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK1745:
	ctx->vsp=local; return(local[0]);}

/*get-lighter-pixel*/
static pointer F1446(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1755;}
	local[0]= makeflt(1.39999962e+00);
ENT1755:
	if (n>=3) { local[1]=(argv[2]); goto ENT1754;}
	local[1]= loadglobal(fqv[85]);
ENT1754:
ENT1753:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
	local[5]= fqv[84];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[1];
	local[5]= fqv[82];
	local[6]= local[0];
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= loadglobal(fqv[86]);
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[3];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= loadglobal(fqv[86]);
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	local[7]= w;
	local[8]= local[0];
	local[9]= local[3];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	local[9]= loadglobal(fqv[86]);
	ctx->vsp=local+10;
	w=(pointer)MIN(ctx,2,local+8); /*min*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[0]= w;
BLK1752:
	ctx->vsp=local; return(local[0]);}

/*get-redish-pixel*/
static pointer F1447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1759;}
	local[0]= makeflt(1.09999990e+00);
ENT1759:
	if (n>=3) { local[1]=(argv[2]); goto ENT1758;}
	local[1]= loadglobal(fqv[85]);
ENT1758:
ENT1757:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
	local[5]= fqv[84];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[1];
	local[5]= fqv[82];
	local[6]= local[0];
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= loadglobal(fqv[86]);
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[6]= w;
	local[7]= local[3];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= loadglobal(fqv[86]);
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	local[9]= loadglobal(fqv[86]);
	ctx->vsp=local+10;
	w=(pointer)MIN(ctx,2,local+8); /*min*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[0]= w;
BLK1756:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xcolor(ctx,n,argv,env)
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
	local[0]= fqv[87];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F1422,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F1423,fqv[90]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[91],module,F1424,fqv[92]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[93],module,F1425,fqv[94]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F1426,fqv[96]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[97],module,F1427,fqv[98]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[99],module,F1428,fqv[100]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[101],module,F1429,fqv[102]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F1430,fqv[104]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[105],module,F1431,fqv[106]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[107],module,F1432,fqv[108]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[109],module,F1433,fqv[110]);
	local[0]= fqv[40];
	local[1]= fqv[111];
	local[2]= fqv[40];
	local[3]= fqv[112];
	local[4]= loadglobal(fqv[113]);
	local[5]= fqv[114];
	local[6]= fqv[115];
	local[7]= fqv[116];
	local[8]= loadglobal(fqv[117]);
	local[9]= fqv[20];
	local[10]= fqv[36];
	local[11]= fqv[118];
	local[12]= makeint(-1);
	local[13]= fqv[119];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[120]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[40]);
	local[1]= fqv[121];
	local[2]= fqv[122];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F1434,fqv[124]);
	local[0]= fqv[123];
	local[1]= fqv[125];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[123];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[123];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[123];
	local[1]= NIL;
	local[2]= fqv[130];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F1435,fqv[131]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F1436,fqv[133]);
	local[0]= fqv[132];
	local[1]= fqv[134];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[132];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[132];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[132];
	local[1]= NIL;
	local[2]= fqv[130];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F1437,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[136],module,F1438,fqv[137]);
	local[0]= fqv[136];
	local[1]= fqv[138];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[136];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[136];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[136];
	local[1]= NIL;
	local[2]= fqv[130];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[138],module,F1439,fqv[139]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[140],module,F1440,fqv[141]);
	local[0]= fqv[140];
	local[1]= fqv[142];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[140];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[140];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[140];
	local[1]= NIL;
	local[2]= fqv[130];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[142],module,F1441,fqv[143]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[144],module,F1442,fqv[145]);
	local[0]= fqv[144];
	local[1]= fqv[146];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[144];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[144];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[144];
	local[1]= NIL;
	local[2]= fqv[130];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[146],module,F1443,fqv[147]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[148],module,F1444,fqv[149]);
	local[0]= fqv[148];
	local[1]= fqv[150];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[148];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[148];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[128]); /*remprop*/
	local[0]= fqv[148];
	local[1]= NIL;
	local[2]= fqv[130];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[150],module,F1445,fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1529,fqv[152],fqv[40],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1531,fqv[37],fqv[40],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1535,fqv[38],fqv[40],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1539,fqv[39],fqv[40],fqv[156]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1543,fqv[43],fqv[40],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1545,fqv[41],fqv[40],fqv[158]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1549,fqv[159],fqv[160],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1551,fqv[84],fqv[160],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1554,fqv[163],fqv[160],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1556,fqv[165],fqv[160],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1558,fqv[82],fqv[160],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1563,fqv[47],fqv[160],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1585,fqv[169],fqv[160],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1587,fqv[171],fqv[160],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1589,fqv[173],fqv[160],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1591,fqv[58],fqv[160],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1593,fqv[152],fqv[160],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1595,fqv[118],fqv[160],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1597,fqv[178],fqv[160],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1599,fqv[61],fqv[160],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1605,fqv[181],fqv[160],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1610,fqv[69],fqv[160],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1624,fqv[68],fqv[160],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1645,fqv[71],fqv[160],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1669,fqv[74],fqv[160],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1679,fqv[187],fqv[160],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1687,fqv[189],fqv[160],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1705,fqv[191],fqv[160],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1713,fqv[193],fqv[160],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1726,fqv[195],fqv[160],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1728,fqv[197],fqv[160],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1730,fqv[41],fqv[160],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1734,fqv[200],fqv[160],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1740,fqv[202],fqv[160],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1744,fqv[204],fqv[160],fqv[205]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[206],module,F1446,fqv[207]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[208],module,F1447,fqv[209]);
	local[0]= fqv[210];
	ctx->vsp=local+1;
	w=(*ftab[24])(ctx,1,local+0,&ftab[24],fqv[211]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<25; i++) ftab[i]=fcallx;
}
