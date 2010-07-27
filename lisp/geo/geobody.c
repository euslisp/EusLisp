/* geobody.c :  entry=geobody */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "geobody.h"
#pragma init (register_geobody)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___geobody();
extern pointer build_quote_vector();
static register_geobody()
  { add_module_initializer("___geobody", ___geobody);}

static pointer F1240();

/*:update*/
static pointer M1241(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (loadglobal(fqv[0])==NIL) goto IF1243;
	local[0]= loadglobal(fqv[1]);
	local[1]= fqv[2];
	local[2]= argv[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF1244;
IF1243:
	local[0]= NIL;
IF1244:
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1246:
	if (local[1]==NIL) goto WHX1247;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	goto WHL1246;
WHX1247:
	local[2]= NIL;
BLK1248:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[7]); /*remprop*/
	w = argv[0];
	local[0]= w;
BLK1242:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M1250(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK1251:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M1252(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1254:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto CON1256;
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= argv[0];
	local[3]= fqv[9];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= w;
	goto CON1255;
CON1256:
	local[1]= argv[0]->c.obj.iv[9];
	goto CON1255;
CON1257:
	local[1]= NIL;
CON1255:
	w = local[1];
	local[0]= w;
BLK1253:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1259:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M1260(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1261:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M1262(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1263:
	ctx->vsp=local; return(local[0]);}

/*:edge*/
static pointer M1264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1265:
	ctx->vsp=local; return(local[0]);}

/*:vertex*/
static pointer M1266(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1267:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M1268(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1269:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1273;}
	local[0]= NIL;
ENT1273:
ENT1272:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1274;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1275;
IF1274:
	local[1]= argv[0];
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
IF1275:
	w = local[1];
	local[0]= w;
BLK1271:
	ctx->vsp=local; return(local[0]);}

/*:reflectance*/
static pointer M1276(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1279;}
	local[0]= NIL;
ENT1279:
ENT1278:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1280;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1281;
IF1280:
	local[3]= argv[0];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1282;
	local[3]= local[2];
	goto IF1283;
IF1282:
	local[3]= makeflt(5.00000000e-01);
IF1283:
IF1281:
	w = local[3];
	local[0]= w;
BLK1277:
	ctx->vsp=local; return(local[0]);}

/*:diffusion*/
static pointer M1284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1287;}
	local[0]= NIL;
ENT1287:
ENT1286:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1288;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1289;
IF1288:
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1290;
	local[3]= local[2];
	goto IF1291;
IF1290:
	local[3]= makeflt(5.00000000e-01);
IF1291:
IF1289:
	w = local[3];
	local[0]= w;
BLK1285:
	ctx->vsp=local; return(local[0]);}

/*:holes*/
static pointer M1292(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[13]);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[14];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1293:
	ctx->vsp=local; return(local[0]);}

/*:visible-faces*/
static pointer M1294(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF1296;
	local[0]= argv[2];
	local[1]= fqv[17];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF1297;
IF1296:
	local[0]= NIL;
IF1297:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1298,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1295:
	ctx->vsp=local; return(local[0]);}

/*:visible-edges*/
static pointer M1299(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= loadglobal(fqv[16]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF1301;
	local[3]= argv[2];
	local[4]= fqv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	argv[2] = w;
	local[3]= argv[2];
	goto IF1302;
IF1301:
	local[3]= NIL;
IF1302:
	local[3]= argv[0];
	local[4]= fqv[6];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto IF1303;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	goto IF1304;
IF1303:
	local[3]= fqv[18];
	local[4]= makeflt(1.50000000e+00);
	local[5]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= fqv[19];
	local[6]= (pointer)get_sym_func(fqv[20]);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[21]); /*make-hash-table*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
WHL1306:
	if (local[5]==NIL) goto WHX1307;
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
	local[8]= fqv[23];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1311:
	if (local[7]==NIL) goto WHX1312;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= local[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,3,local+8,&ftab[3],fqv[24]); /*sethash*/
	goto WHL1311;
WHX1312:
	local[8]= NIL;
BLK1313:
	w = NIL;
	goto WHL1306;
WHX1307:
	local[6]= NIL;
BLK1308:
	w = NIL;
	local[4]= local[3];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[2] = w;
	local[4]= argv[0];
	local[5]= argv[2];
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[6];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= local[3]->c.obj.iv[0];
	ctx->vsp=local+5;
	w=(pointer)RECLAIM(ctx,1,local+4); /*system:reclaim*/
	local[4]= local[3]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)RECLAIM(ctx,1,local+4); /*system:reclaim*/
	w = local[2];
	local[3]= w;
IF1304:
	w = local[3];
	local[0]= w;
BLK1300:
	ctx->vsp=local; return(local[0]);}

/*:contour-edges*/
static pointer M1315(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL1318:
	if (local[4]==NIL) goto WHX1319;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1323;
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w!=NIL) goto IF1324;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1325;
IF1324:
	local[5]= NIL;
IF1325:
	goto CON1322;
CON1323:
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1326;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w!=NIL) goto IF1327;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1328;
IF1327:
	local[5]= NIL;
IF1328:
	goto CON1322;
CON1326:
	local[5]= NIL;
CON1322:
	goto WHL1318;
WHX1319:
	local[5]= NIL;
BLK1320:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1316:
	ctx->vsp=local; return(local[0]);}

/*:non-contour-edges*/
static pointer M1329(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL1332:
	if (local[4]==NIL) goto WHX1333;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1336;
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1336;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1337;
IF1336:
	local[5]= NIL;
IF1337:
	goto WHL1332;
WHX1333:
	local[5]= NIL;
BLK1334:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1330:
	ctx->vsp=local; return(local[0]);}

/*:common-box*/
static pointer M1338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1341;}
	local[0]= NIL;
ENT1341:
ENT1340:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[27];
	local[3]= argv[2];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1339:
	ctx->vsp=local; return(local[0]);}

/*:newbox*/
static pointer M1342(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1345;}
	local[0]= loadglobal(fqv[29]);
ENT1345:
ENT1344:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[11];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,2,local+1,&ftab[5],fqv[30]); /*make-bounding-box*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1343:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1298(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[31];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1346;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1347;
IF1346:
	local[0]= NIL;
IF1347:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:reset-vertices*/
static pointer M1348(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[11];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
WHL1350:
	if (local[0]==NIL) goto WHX1351;
	local[4]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= local[3];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	goto WHL1350;
WHX1351:
	local[4]= NIL;
BLK1352:
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[32];
	local[6]= argv[0]->c.obj.iv[11];
	local[7]= loadglobal(fqv[29]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK1349:
	ctx->vsp=local; return(local[0]);}

/*:translate-vertices*/
static pointer M1355(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[12];
WHL1358:
	if (local[1]==NIL) goto WHX1359;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,3,local+2); /*v+*/
	goto WHL1358;
WHX1359:
	local[2]= NIL;
BLK1360:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK1356:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vertices*/
static pointer M1362(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto IF1364;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,2,local+1,&ftab[7],fqv[35]); /*rotation*/
	local[0] = w;
	local[1]= local[0];
	goto IF1365;
IF1364:
	local[1]= NIL;
IF1365:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1367:
	if (local[2]==NIL) goto WHX1368;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto IF1371;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)TRANSFORM(ctx,3,local+3); /*transform*/
	local[3]= w;
	goto IF1372;
IF1371:
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ROTVEC(ctx,4,local+3); /*rotate-vector*/
	local[3]= w;
IF1372:
	goto WHL1367;
WHX1368:
	local[3]= NIL;
BLK1369:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK1363:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M1373(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1376;}
	local[0]= NIL;
ENT1376:
ENT1375:
	if (n>4) maerror();
	if (local[0]==NIL) goto CON1378;
	local[1]= local[0];
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1380;
	local[1]= fqv[37];
	goto CON1379;
CON1380:
	local[1]= local[0];
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1381;
	local[1]= fqv[39];
	goto CON1379;
CON1381:
	local[1]= local[0];
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1382;
	local[1]= fqv[41];
	goto CON1379;
CON1382:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON1379;
CON1383:
	local[1]= NIL;
CON1379:
	local[0] = local[1];
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1385:
	if (local[2]==NIL) goto WHX1386;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= makeflt(1.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	goto WHL1385;
WHX1386:
	local[3]= NIL;
BLK1387:
	w = NIL;
	local[1]= w;
	goto CON1377;
CON1378:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1391:
	if (local[2]==NIL) goto WHX1392;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,3,local+3); /*scale*/
	goto WHL1391;
WHX1392:
	local[3]= NIL;
BLK1393:
	w = NIL;
	local[1]= w;
	goto CON1377;
CON1389:
	local[1]= NIL;
CON1377:
	local[1]= argv[0];
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK1374:
	ctx->vsp=local; return(local[0]);}

/*:faces-intersect-with-point-vector*/
static pointer M1395(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[42],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1398:
	if (local[6]==NIL) goto WHX1399;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[42]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	if (fqv[44]!=local[7]) goto IF1402;
	local[7]= local[5];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
	goto IF1403;
IF1402:
	local[7]= NIL;
IF1403:
	goto WHL1398;
WHX1399:
	local[7]= NIL;
BLK1400:
	w = NIL;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1396:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M1404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= loadglobal(fqv[45]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON1407;
	local[0] = makeflt(9.99999864e+29);
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
WHL1409:
	if (local[4]==NIL) goto WHX1410;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[46];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF1413;
	local[0] = local[2];
	local[1] = local[3];
	local[5]= local[1];
	goto IF1414;
IF1413:
	local[5]= NIL;
IF1414:
	goto WHL1409;
WHX1410:
	local[5]= NIL;
BLK1411:
	w = NIL;
	local[3]= w;
	goto CON1406;
CON1407:
	local[3]= argv[2];
	local[4]= loadglobal(fqv[47]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON1415;
	local[3]= argv[2];
	local[4]= fqv[46];
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= NIL;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1417:
	if (local[4]==NIL) goto WHX1418;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[2];
	local[6]= fqv[46];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF1421;
	local[0] = local[2];
	local[1] = local[3];
	local[5]= local[1];
	goto IF1422;
IF1421:
	local[5]= NIL;
IF1422:
	goto WHL1417;
WHX1418:
	local[5]= NIL;
BLK1419:
	w = NIL;
	local[3]= w;
	goto CON1406;
CON1415:
	local[3]= NIL;
CON1406:
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[48]); /*values*/
	local[0]= w;
BLK1405:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1423(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1425:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[49], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1426;
	local[1] = NIL;
KEY1426:
	if (n & (1<<1)) goto KEY1427;
	local[2] = NIL;
KEY1427:
	if (n & (1<<2)) goto KEY1428;
	local[3] = NIL;
KEY1428:
	if (n & (1<<3)) goto KEY1429;
	local[4] = NIL;
KEY1429:
	if (n & (1<<4)) goto KEY1430;
	local[5] = NIL;
KEY1430:
	if (n & (1<<5)) goto KEY1431;
	local[6] = NIL;
KEY1431:
	if (local[1]==NIL) goto IF1432;
	argv[0]->c.obj.iv[9] = local[1];
	if (local[2]!=NIL) goto IF1434;
	local[7]= (pointer)get_sym_func(fqv[13]);
	local[8]= local[1];
	local[9]= fqv[23];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[15]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,2,local+7); /*apply*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[50]); /*remove-duplicates*/
	argv[0]->c.obj.iv[10] = w;
	local[7]= argv[0]->c.obj.iv[10];
	goto IF1435;
IF1434:
	local[7]= NIL;
IF1435:
	if (local[3]!=NIL) goto IF1436;
	local[7]= (pointer)get_sym_func(fqv[13]);
	local[8]= local[1];
	local[9]= fqv[51];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[15]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,2,local+7); /*apply*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[50]); /*remove-duplicates*/
	argv[0]->c.obj.iv[11] = w;
	local[7]= argv[0]->c.obj.iv[11];
	goto IF1437;
IF1436:
	local[7]= NIL;
IF1437:
	goto IF1433;
IF1432:
	local[7]= NIL;
IF1433:
	local[7]= (pointer)get_sym_func(fqv[52]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[53]));
	local[10]= fqv[32];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,5,local+7); /*apply*/
	if (local[2]==NIL) goto IF1438;
	argv[0]->c.obj.iv[10] = local[2];
	local[7]= argv[0]->c.obj.iv[10];
	goto IF1439;
IF1438:
	local[7]= NIL;
IF1439:
	if (local[3]==NIL) goto IF1440;
	argv[0]->c.obj.iv[11] = local[3];
	local[7]= argv[0]->c.obj.iv[11];
	goto IF1441;
IF1440:
	local[7]= NIL;
IF1441:
	local[7]= loadglobal(fqv[54]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[32];
	local[10]= argv[0]->c.obj.iv[11];
	local[11]= loadglobal(fqv[29]);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	w = local[7];
	argv[0]->c.obj.iv[8] = w;
	if (argv[0]->c.obj.iv[12]!=NIL) goto IF1443;
	local[7]= NIL;
	goto IF1444;
IF1443:
	local[7]= NIL;
IF1444:
	local[7]= (pointer)get_sym_func(fqv[55]);
	local[8]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	argv[0]->c.obj.iv[12] = w;
	if (local[4]==NIL) goto IF1445;
	local[7]= argv[0];
	local[8]= local[4];
	local[9]= fqv[10];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1446;
IF1445:
	local[7]= NIL;
IF1446:
	if (local[5]==NIL) goto IF1447;
	local[7]= argv[0];
	local[8]= local[5];
	local[9]= fqv[11];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1448;
IF1447:
	local[7]= NIL;
IF1448:
	if (local[6]==NIL) goto IF1449;
	local[7]= argv[0];
	local[8]= local[6];
	local[9]= fqv[12];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1450;
IF1449:
	local[7]= NIL;
IF1450:
	w = argv[0];
	local[0]= w;
BLK1424:
	ctx->vsp=local; return(local[0]);}

/*:translate-vertices*/
static pointer M1451(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[56];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[15];
	local[1]= fqv[56];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1452:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vertices*/
static pointer M1453(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[57];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[15];
	local[1]= fqv[57];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1454:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M1455(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1458;}
	local[0]= NIL;
ENT1458:
ENT1457:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[53]));
	local[3]= fqv[58];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[58];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1456:
	ctx->vsp=local; return(local[0]);}

/*:euler*/
static pointer M1459(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(-(intval(local[2])));
	local[6]= makeint(-(intval(local[0])));
	local[7]= makeint(2);
	w = local[3];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[7] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[6] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	w = (pointer)((integer_t)local[5] + (integer_t)w);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[4]= (pointer)((integer_t)local[4] + (integer_t)w);
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[0]= w;
BLK1460:
	ctx->vsp=local; return(local[0]);}

/*:perimeter*/
static pointer M1461(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[59]);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1462:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M1463(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1466;}
	local[0]= fqv[61];
ENT1466:
ENT1465:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[59]);
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= fqv[62];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK1464:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1467(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1470;}
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
ENT1470:
ENT1469:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[63];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,3,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[59]);
	local[3]= (pointer)get_sym_func(fqv[64]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1471,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[3];
WHL1473:
	if (local[6]==NIL) goto WHX1474;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= local[4];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	goto WHL1473;
WHX1474:
	local[7]= NIL;
BLK1475:
	w = NIL;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,3,local+5); /*scale*/
	w = local[4];
	local[0]= w;
BLK1468:
	ctx->vsp=local; return(local[0]);}

/*:world-centroid*/
static pointer M1477(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[66];
	local[2]= argv[0];
	local[3]= fqv[63];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1478:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M1479(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[59]);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1480:
	ctx->vsp=local; return(local[0]);}

/*:extream-point*/
static pointer M1481(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1484:
	if (local[4]==NIL) goto WHX1485;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[2] = w;
	local[5]= local[2];
	{ double left,right;
		right=fltval(local[1]); left=fltval(local[5]);
	if (left <= right) goto IF1488;}
	local[1] = local[2];
	local[0] = local[3];
	local[5]= local[0];
	goto IF1489;
IF1488:
	local[5]= NIL;
IF1489:
	goto WHL1484;
WHX1485:
	local[5]= NIL;
BLK1486:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1482:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M1490(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[68];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= fqv[68];
	local[4]= makeflt(-1.00000000e+00);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	w = local[0];
	local[0]= w;
BLK1491:
	ctx->vsp=local; return(local[0]);}

/*:supporting-faces*/
static pointer M1492(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1495;}
	local[0]= makeflt(0.00000000e+00);
	local[1]= makeflt(0.00000000e+00);
	local[2]= makeflt(-1.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*floatvector*/
	local[0]= w;
ENT1495:
ENT1494:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[69];
	local[3]= argv[0];
	local[4]= fqv[63];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1493:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1471(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[70]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:possibly-interfering-faces*/
static pointer M1496(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1498,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1497:
	ctx->vsp=local; return(local[0]);}

/*:possibly-interfering-edges*/
static pointer M1499(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1501,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1500:
	ctx->vsp=local; return(local[0]);}

/*:intersect-face*/
static pointer M1502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1505:
	if (local[1]==NIL) goto WHX1506;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[71];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto OR1511;
	local[2]= argv[2];
	local[3]= fqv[71];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto OR1511;
	goto IF1509;
OR1511:
	w = T;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1503;
	goto IF1510;
IF1509:
	local[2]= NIL;
IF1510:
	goto WHL1505;
WHX1506:
	local[2]= NIL;
BLK1507:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK1503:
	ctx->vsp=local; return(local[0]);}

/*:intersectp*/
static pointer M1512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1514;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[72];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[1];
WHL1517:
	if (local[4]==NIL) goto WHX1518;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= local[2];
WHL1522:
	if (local[6]==NIL) goto WHX1523;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[3];
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[27];
	local[9]= local[5];
	local[10]= fqv[28];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0] = w;
	local[7]= local[3];
	local[8]= fqv[71];
	local[9]= local[5];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w!=NIL) goto OR1528;
	local[7]= local[5];
	local[8]= fqv[71];
	local[9]= local[3];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w!=NIL) goto OR1528;
	goto IF1526;
OR1528:
	w = T;
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1513;
	goto IF1527;
IF1526:
	local[7]= NIL;
IF1527:
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)RECLTREE(ctx,1,local+7); /*system:reclaim-tree*/
	goto WHL1522;
WHX1523:
	local[7]= NIL;
BLK1524:
	w = NIL;
	goto WHL1517;
WHX1518:
	local[5]= NIL;
BLK1519:
	w = NIL;
	local[3]= w;
	goto IF1515;
IF1514:
	local[3]= NIL;
IF1515:
	w = local[3];
	local[0]= w;
BLK1513:
	ctx->vsp=local; return(local[0]);}

/*:intersectp2*/
static pointer M1529(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1532;}
	local[0]= loadglobal(fqv[73]);
ENT1532:
ENT1531:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	if (local[1]==NIL) goto IF1533;
	local[10]= argv[0];
	local[11]= fqv[72];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[2] = w;
	local[10]= argv[2];
	local[11]= fqv[72];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	local[10]= argv[0];
	local[11]= fqv[75];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= argv[2];
	local[11]= fqv[75];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[5] = w;
	local[10]= NIL;
	local[11]= local[2];
WHL1536:
	if (local[11]==NIL) goto WHX1537;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[5];
WHL1541:
	if (local[13]==NIL) goto WHX1542;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= fqv[76];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto CON1546;
	if (local[8]!=NIL) goto IF1547;
	local[14]= NIL;
	local[15]= local[10];
	local[16]= fqv[23];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
WHL1550:
	if (local[15]==NIL) goto WHX1551;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[77];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (!iscons(w)) goto IF1554;
	local[16]= local[10];
	local[17]= fqv[78];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[3];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1558;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[4];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1558;
	goto IF1556;
OR1558:
	w = fqv[80];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK1530;
	goto IF1557;
IF1556:
	local[8] = fqv[81];
	w = local[8];
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK1552;
IF1557:
	w = local[17];
	local[16]= w;
	goto IF1555;
IF1554:
	local[16]= NIL;
IF1555:
	goto WHL1550;
WHX1551:
	local[16]= NIL;
BLK1552:
	w = NIL;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[12]->c.obj.iv[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto IF1559;
	local[14]= local[10];
	local[15]= fqv[78];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[3];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1563;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[4];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1563;
	goto IF1561;
OR1563:
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1530;
	goto IF1562;
IF1561:
	local[8] = fqv[81];
	local[15]= local[8];
IF1562:
	w = local[15];
	local[14]= w;
	goto IF1560;
IF1559:
	local[14]= NIL;
IF1560:
	goto IF1548;
IF1547:
	local[14]= NIL;
IF1548:
	goto CON1545;
CON1546:
	local[14]= local[10];
	local[15]= fqv[27];
	local[16]= local[12]->c.obj.iv[1];
	local[17]= local[12]->c.obj.iv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[6] = w;
	local[14]= local[6];
	if (loadglobal(fqv[83])==local[14]) goto IF1565;
	local[14]= makeflt(0.00000000e+00);
	local[15]= local[6];
	local[16]= makeflt(1.00000000e+00);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,4,local+14,&ftab[11],fqv[84]); /*eps-in-range*/
	if (w==NIL) goto IF1565;
	local[14]= local[12];
	local[15]= fqv[85];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[7] = w;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[6];
	local[15]= makeflt(0.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1569;
	local[14]= local[6];
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1569;
	goto CON1568;
OR1569:
	local[14]= local[9];
	local[15]= fqv[86];
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,2,local+14,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1568;
	local[8] = fqv[81];
	local[14]= local[8];
	goto CON1567;
CON1568:
	local[14]= local[9];
	local[15]= local[14];
	if (fqv[44]!=local[15]) goto IF1572;
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1530;
	goto IF1573;
IF1572:
	local[15]= local[14];
	if (fqv[87]!=local[15]) goto IF1574;
	local[8] = fqv[81];
	local[15]= local[8];
	goto IF1575;
IF1574:
	local[15]= NIL;
IF1575:
IF1573:
	w = local[15];
	local[14]= w;
	goto CON1567;
CON1570:
	local[14]= NIL;
CON1567:
	goto IF1566;
IF1565:
	local[14]= NIL;
IF1566:
	goto CON1545;
CON1564:
	local[14]= NIL;
CON1545:
	goto WHL1541;
WHX1542:
	local[14]= NIL;
BLK1543:
	w = NIL;
	goto WHL1536;
WHX1537:
	local[12]= NIL;
BLK1538:
	w = NIL;
	local[10]= NIL;
	local[11]= local[3];
WHL1577:
	if (local[11]==NIL) goto WHX1578;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[5];
WHL1582:
	if (local[13]==NIL) goto WHX1583;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= fqv[76];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto CON1587;
	if (local[8]!=NIL) goto IF1588;
	local[14]= NIL;
	local[15]= local[10];
	local[16]= fqv[23];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
WHL1591:
	if (local[15]==NIL) goto WHX1592;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[77];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (!iscons(w)) goto IF1595;
	local[16]= local[10];
	local[17]= fqv[78];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[3];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1599;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[4];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1599;
	goto IF1597;
OR1599:
	w = fqv[80];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK1530;
	goto IF1598;
IF1597:
	local[8] = fqv[81];
	w = local[8];
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK1593;
IF1598:
	w = local[17];
	local[16]= w;
	goto IF1596;
IF1595:
	local[16]= NIL;
IF1596:
	goto WHL1591;
WHX1592:
	local[16]= NIL;
BLK1593:
	w = NIL;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[12]->c.obj.iv[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto IF1600;
	local[14]= local[10];
	local[15]= fqv[78];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[3];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1604;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[4];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1604;
	goto IF1602;
OR1604:
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1530;
	goto IF1603;
IF1602:
	local[8] = fqv[81];
	local[15]= local[8];
IF1603:
	w = local[15];
	local[14]= w;
	goto IF1601;
IF1600:
	local[14]= NIL;
IF1601:
	goto IF1589;
IF1588:
	local[14]= NIL;
IF1589:
	goto CON1586;
CON1587:
	local[14]= local[10];
	local[15]= fqv[27];
	local[16]= local[12]->c.obj.iv[1];
	local[17]= local[12]->c.obj.iv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[6] = w;
	local[14]= local[6];
	if (loadglobal(fqv[83])==local[14]) goto IF1606;
	local[14]= makeflt(0.00000000e+00);
	local[15]= local[6];
	local[16]= makeflt(1.00000000e+00);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,4,local+14,&ftab[11],fqv[84]); /*eps-in-range*/
	if (w==NIL) goto IF1606;
	local[14]= local[12];
	local[15]= fqv[85];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[7] = w;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[6];
	local[15]= makeflt(0.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1610;
	local[14]= local[6];
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1610;
	goto CON1609;
OR1610:
	local[14]= local[9];
	local[15]= fqv[88];
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,2,local+14,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1609;
	local[8] = fqv[81];
	local[14]= local[8];
	goto CON1608;
CON1609:
	local[14]= local[9];
	local[15]= local[14];
	if (fqv[44]!=local[15]) goto IF1613;
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1530;
	goto IF1614;
IF1613:
	local[15]= local[14];
	if (fqv[87]!=local[15]) goto IF1615;
	local[8] = fqv[81];
	local[15]= local[8];
	goto IF1616;
IF1615:
	local[15]= NIL;
IF1616:
IF1614:
	w = local[15];
	local[14]= w;
	goto CON1608;
CON1611:
	local[14]= NIL;
CON1608:
	goto IF1607;
IF1606:
	local[14]= NIL;
IF1607:
	goto CON1586;
CON1605:
	local[14]= NIL;
CON1586:
	goto WHL1582;
WHX1583:
	local[14]= NIL;
BLK1584:
	w = NIL;
	goto WHL1577;
WHX1578:
	local[12]= NIL;
BLK1579:
	w = NIL;
	local[10]= local[8];
	goto IF1534;
IF1533:
	local[10]= NIL;
IF1534:
	w = local[10];
	local[0]= w;
BLK1530:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M1617(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1620;}
	local[0]= loadglobal(fqv[89]);
ENT1620:
ENT1619:
	if (n>4) maerror();
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF1621;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[90];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w!=NIL) goto IF1621;
	w = fqv[91];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1618;
	goto IF1622;
IF1621:
	local[1]= NIL;
IF1622:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	if (argv[0]->c.obj.iv[13]==NIL) goto CON1624;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1626:
	if (local[6]==NIL) goto WHX1627;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[92];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[1] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON1631;
	local[7]= local[5];
	local[8]= fqv[82];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[3] = w;
	local[7]= local[3];
	if (fqv[91]!=local[7]) goto IF1632;
	w = fqv[91];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1618;
	goto IF1633;
IF1632:
	w = fqv[87];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1618;
IF1633:
	goto CON1630;
CON1631:
	local[7]= local[1];
	local[8]= makeflt(0.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto CON1634;
	w = fqv[91];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1618;
	goto CON1630;
CON1634:
	local[7]= NIL;
CON1630:
	goto WHL1626;
WHX1627:
	local[7]= NIL;
BLK1628:
	w = NIL;
	local[5]= fqv[44];
	goto CON1623;
CON1624:
	local[3] = NIL;
WHL1636:
	if (local[3]!=NIL) goto WHX1637;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,0,local+5,&ftab[12],fqv[93]); /*random-normalized-vector*/
	local[2] = w;
	local[4] = makeint(0);
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1640:
	if (local[6]==NIL) goto WHX1641;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[92];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF1644;
	local[7]= local[5];
	local[8]= fqv[82];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	if (fqv[91]==local[7]) goto IF1644;
	w = fqv[87];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1618;
	goto IF1645;
IF1644:
	local[7]= NIL;
IF1645:
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= argv[2];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[7];
	if (fqv[44]!=local[8]) goto IF1647;
	local[4] = (pointer)((integer_t)(local[4])+4);
	local[8]= local[4];
	goto IF1648;
IF1647:
	local[8]= local[7];
	if (fqv[91]!=local[8]) goto IF1649;
	local[8]= NIL;
	goto IF1650;
IF1649:
	if (T==NIL) goto IF1651;
	local[3] = NIL;
	w = NIL;
	ctx->vsp=local+8;
	local[7]=w;
	goto BLK1642;
	goto IF1652;
IF1651:
	local[8]= NIL;
IF1652:
IF1650:
IF1648:
	w = local[8];
	goto WHL1640;
WHX1641:
	local[7]= NIL;
BLK1642:
	w = NIL;
	goto WHL1636;
WHX1637:
	local[5]= NIL;
BLK1638:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF1653;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[94]); /*oddp*/
	if (w==NIL) goto IF1655;
	local[5]= fqv[44];
	goto IF1656;
IF1655:
	local[5]= fqv[91];
IF1656:
	goto IF1654;
IF1653:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[94]); /*oddp*/
	if (w==NIL) goto IF1657;
	local[5]= fqv[91];
	goto IF1658;
IF1657:
	local[5]= fqv[44];
IF1658:
IF1654:
	goto CON1623;
CON1635:
	local[5]= NIL;
CON1623:
	w = local[5];
	local[0]= w;
BLK1618:
	ctx->vsp=local; return(local[0]);}

/*:evert*/
static pointer M1659(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	argv[0]->c.obj.iv[14] = ((argv[0]->c.obj.iv[14])==NIL?T:NIL);
	if (argv[0]->c.obj.iv[14]==NIL) goto CON1662;
	local[0]= loadglobal(fqv[54]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[96];
	local[3]= makeflt(-9.99999898e+09);
	local[4]= makeflt(-9.99999898e+09);
	local[5]= makeflt(-9.99999898e+09);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeflt(9.99999898e+09);
	local[5]= makeflt(9.99999898e+09);
	local[6]= makeflt(9.99999898e+09);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[13] = NIL;
	local[0]= argv[0]->c.obj.iv[13];
	goto CON1661;
CON1662:
	local[0]= argv[0];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON1661;
CON1664:
	local[0]= NIL;
CON1661:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK1660:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M1665(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1669,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[99];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[100]); /*every*/
	if (w==NIL) goto IF1667;
	argv[0]->c.obj.iv[13] = T;
	local[0]= argv[0]->c.obj.iv[13];
	goto IF1668;
IF1667:
	local[0]= NIL;
IF1668:
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	w = argv[0];
	local[0]= w;
BLK1666:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1498(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1670;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1671;
IF1670:
	local[0]= NIL;
IF1671:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1501(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1672;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1673;
IF1672:
	local[0]= NIL;
IF1673:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1669(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:get-face*/
static pointer M1674(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1679;}
	local[0]= NIL;
ENT1679:
	if (n>=4) { local[1]=(argv[3]); goto ENT1678;}
	local[1]= NIL;
ENT1678:
	if (n>=5) { local[2]=(argv[4]); goto ENT1677;}
	local[2]= NIL;
ENT1677:
ENT1676:
	if (n>5) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,1,local+7,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1681;
	local[7]= NIL;
	local[8]= argv[0]->c.obj.iv[9];
WHL1683:
	if (local[8]==NIL) goto WHX1684;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[103];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	if (local[0]!=local[9]) goto IF1687;
	local[9]= local[7];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	local[9]= local[3];
	goto IF1688;
IF1687:
	local[9]= NIL;
IF1688:
	goto WHL1683;
WHX1684:
	local[9]= NIL;
BLK1685:
	w = NIL;
	local[7]= w;
	goto CON1680;
CON1681:
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[104]); /*keywordp*/
	if (w==NIL) goto CON1689;
	local[7]= NIL;
	local[8]= argv[0]->c.obj.iv[9];
WHL1691:
	if (local[8]==NIL) goto WHX1692;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[105];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (local[0]!=local[9]) goto IF1695;
	local[9]= local[7];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	local[9]= local[3];
	goto IF1696;
IF1695:
	local[9]= NIL;
IF1696:
	goto WHL1691;
WHX1692:
	local[9]= NIL;
BLK1693:
	w = NIL;
	local[7]= w;
	goto CON1680;
CON1689:
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)COPYSEQ(ctx,1,local+7); /*copy-seq*/
	local[3] = w;
	local[7]= local[3];
	goto CON1680;
CON1697:
	local[7]= NIL;
CON1680:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,1,local+7,&ftab[17],fqv[106]); /*facep*/
	if (w==NIL) goto CON1699;
	local[7]= NIL;
	local[8]= local[3];
WHL1701:
	if (local[8]==NIL) goto WHX1702;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[107];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	if (local[1]!=local[9]) goto IF1705;
	local[9]= local[7];
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	local[9]= local[4];
	goto IF1706;
IF1705:
	local[9]= NIL;
IF1706:
	goto WHL1701;
WHX1702:
	local[9]= NIL;
BLK1703:
	w = NIL;
	local[7]= w;
	goto CON1698;
CON1699:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[104]); /*keywordp*/
	if (w==NIL) goto CON1707;
	local[7]= NIL;
	local[8]= local[3];
WHL1709:
	if (local[8]==NIL) goto WHX1710;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[108];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	local[9]= local[6];
	if (local[1]==local[9]) goto OR1715;
	local[9]= local[1];
	if (fqv[109]!=local[9]) goto AND1716;
	local[9]= local[6];
	local[10]= fqv[110];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto AND1716;
	goto OR1715;
AND1716:
	goto IF1713;
OR1715:
	local[9]= local[7];
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	local[9]= local[4];
	goto IF1714;
IF1713:
	local[9]= NIL;
IF1714:
	goto WHL1709;
WHX1710:
	local[9]= NIL;
BLK1711:
	w = NIL;
	local[7]= w;
	goto CON1698;
CON1707:
	local[4] = local[3];
	local[7]= local[4];
	goto CON1698;
CON1717:
	local[7]= NIL;
CON1698:
	if (local[2]==NIL) goto CON1719;
	local[7]= NIL;
	local[8]= local[4];
WHL1721:
	if (local[8]==NIL) goto WHX1722;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[108];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (local[2]!=local[9]) goto IF1725;
	local[9]= local[7];
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto IF1726;
IF1725:
	local[9]= NIL;
IF1726:
	goto WHL1721;
WHX1722:
	local[9]= NIL;
BLK1723:
	w = NIL;
	local[7]= local[5];
	goto CON1718;
CON1719:
	local[7]= local[4];
	goto CON1718;
CON1727:
	local[7]= NIL;
CON1718:
	w = local[7];
	local[0]= w;
BLK1675:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body-p*/
static pointer M1728(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= (iscons(w)?T:NIL);
	if (local[0]==NIL) goto AND1730;
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[104]); /*keywordp*/
	local[0]= w;
AND1730:
	w = local[0];
	local[0]= w;
BLK1729:
	ctx->vsp=local; return(local[0]);}

/*:primitive-bodies*/
static pointer M1731(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1735;}
	local[0]= NIL;
ENT1735:
	if (n>=4) { local[1]=(argv[3]); goto ENT1734;}
	local[1]= NIL;
ENT1734:
ENT1733:
	if (n>4) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET1736,env,argv,local);
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[4];
	if (fqv[111]!=local[5]) goto IF1738;
	local[5]= argv[0];
	local[6]= fqv[112];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= local[3];
	goto IF1739;
IF1738:
	local[5]= local[4];
	if (fqv[113]!=local[5]) goto IF1740;
	local[5]= argv[0];
	local[6]= fqv[112];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= local[3];
	goto IF1741;
IF1740:
	if (T==NIL) goto IF1742;
	local[5]= argv[0];
	w = local[2];
	ctx->vsp=local+6;
	w=FLET1736(ctx,1,local+5,w);
	local[3] = w;
	local[5]= local[3];
	goto IF1743;
IF1742:
	local[5]= NIL;
IF1743:
IF1741:
IF1739:
	w = local[5];
	if (local[1]==NIL) goto CON1745;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO1746,env,argv,local);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[114]); /*collect-if*/
	local[4]= w;
	goto CON1744;
CON1745:
	local[4]= local[3];
	goto CON1744;
CON1747:
	local[4]= NIL;
CON1744:
	w = local[4];
	local[0]= w;
BLK1732:
	ctx->vsp=local; return(local[0]);}

/*:csg*/
static pointer M1748(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1751;}
	local[0]= NIL;
ENT1751:
ENT1750:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1752;
	argv[0]->c.obj.iv[15] = local[0];
	local[1]= argv[0]->c.obj.iv[15];
	goto IF1753;
IF1752:
	local[1]= argv[0]->c.obj.iv[15];
IF1753:
	w = local[1];
	local[0]= w;
BLK1749:
	ctx->vsp=local; return(local[0]);}

/*:copy-csg*/
static pointer M1754(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1756,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1757;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1756(ctx,1,local+1,w);
	local[1]= w;
	goto IF1758;
IF1757:
	local[1]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1756(ctx,1,local+1,w);
	local[1]= w;
IF1758:
	w = local[1];
	local[0]= w;
BLK1755:
	ctx->vsp=local; return(local[0]);}

/*:body-type*/
static pointer M1759(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1761;
	local[0]= fqv[117];
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF1762;
IF1761:
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF1762:
	w = local[0];
	local[0]= w;
BLK1760:
	ctx->vsp=local; return(local[0]);}

/*:creation-form*/
static pointer M1763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1765,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1766;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1765(ctx,1,local+1,w);
	local[1]= w;
	goto IF1767;
IF1766:
	local[1]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1765(ctx,1,local+1,w);
	local[1]= w;
IF1767:
	w = local[1];
	local[0]= w;
BLK1764:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M1768(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[118];
	local[3]= argv[2];
	local[4]= argv[0];
	local[5]= fqv[119];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= w;
BLK1769:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1770(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1772:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[120], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1773;
	local[1] = NIL;
KEY1773:
	if (n & (1<<1)) goto KEY1774;
	local[2] = NIL;
KEY1774:
	if (n & (1<<2)) goto KEY1775;
	local[3] = NIL;
KEY1775:
	local[4]= (pointer)get_sym_func(fqv[52]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[53]));
	local[7]= fqv[32];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,5,local+4); /*apply*/
	local[4]= argv[0]->c.obj.iv[10];
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[15]); /*send-all*/
	if (local[1]==NIL) goto IF1776;
	local[4]= argv[0]->c.obj.iv[10];
	local[5]= fqv[122];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[15]); /*send-all*/
	local[4]= w;
	goto IF1777;
IF1776:
	local[4]= NIL;
IF1777:
	local[4]= (pointer)get_sym_func(fqv[123]);
	local[5]= argv[0]->c.obj.iv[10];
	local[6]= fqv[99];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,2,local+5,&ftab[1],fqv[15]); /*send-all*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,2,local+4,&ftab[14],fqv[100]); /*every*/
	if (w==NIL) goto IF1778;
	argv[0]->c.obj.iv[13] = T;
	local[4]= argv[0]->c.obj.iv[13];
	goto IF1779;
IF1778:
	local[4]= NIL;
IF1779:
	if (argv[0]->c.obj.iv[11]==NIL) goto IF1780;
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1780;
	local[4]= argv[0];
	local[5]= argv[0];
	local[6]= fqv[63];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[63];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= argv[0];
	local[5]= argv[0];
	local[6]= fqv[62];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[62];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= w;
	goto IF1781;
IF1780:
	local[4]= NIL;
IF1781:
	if (local[2]==NIL) goto IF1782;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= fqv[124];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[15]); /*send-all*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	argv[0]->c.obj.iv[15] = w;
	local[4]= argv[0]->c.obj.iv[15];
	goto IF1783;
IF1782:
	local[4]= NIL;
IF1783:
	w = argv[0];
	local[0]= w;
BLK1771:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1736(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[125]); /*primitive-body-p*/
	if (w==NIL) goto CON1785;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON1784;
CON1785:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1786;
	local[0]= env->c.clo.env2[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON1788;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON1787;
CON1788:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON1787;
CON1789:
	local[1]= NIL;
CON1787:
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1784;
CON1786:
	local[0]= env->c.clo.env2[2];
	local[1]= argv[0];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1784;
CON1790:
	local[0]= NIL;
CON1784:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1746(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w = env->c.clo.env2[1];
	if (!iscons(w)) goto IF1791;
	local[2]= local[1];
	local[3]= env->c.clo.env2[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[26]); /*member*/
	local[2]= w;
	goto IF1792;
IF1791:
	local[2]= env->c.clo.env2[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	local[2]= w;
IF1792:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1756(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1794;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO1795,env,argv,local);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON1793;
CON1794:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1796;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[127];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto IF1797;
	local[3]= local[1];
	local[4]= fqv[128];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1798;
IF1797:
	local[3]= NIL;
IF1798:
	local[3]= argv[0];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[130];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[0] = w;
	if (local[1]==NIL) goto IF1799;
	local[3]= local[1];
	local[4]= fqv[131];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1800;
IF1799:
	local[3]= NIL;
IF1800:
	local[3]= NIL;
	local[4]= local[2];
WHL1802:
	if (local[4]==NIL) goto WHX1803;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[131];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL1802;
WHX1803:
	local[5]= NIL;
BLK1804:
	w = NIL;
	local[3]= local[0];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= NIL;
	local[4]= local[0]->c.obj.iv[9];
WHL1807:
	if (local[4]==NIL) goto WHX1808;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[107];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL1807;
WHX1808:
	local[5]= NIL;
BLK1809:
	w = NIL;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= fqv[132];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	w = local[0];
	local[0]= w;
	goto CON1793;
CON1796:
	local[0]= NIL;
CON1793:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1795(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env2[0];
	ctx->vsp=local+1;
	w=FLET1756(ctx,1,local+0,w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1765(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1812;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1814;
	local[0]= fqv[133];
	local[1]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST_STAR(ctx,2,local+0); /*list**/
	local[0]= w;
	goto CON1813;
CON1814:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1815;
	local[0]= fqv[135];
	local[1]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST_STAR(ctx,2,local+0); /*list**/
	local[0]= w;
	goto CON1813;
CON1815:
	local[0]= NIL;
CON1813:
	goto CON1811;
CON1812:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1816;
	local[0]= argv[0];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	if (fqv[136]!=local[2]) goto IF1818;
	local[2]= fqv[137];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	goto IF1819;
IF1818:
	local[2]= local[1];
	if (fqv[138]!=local[2]) goto IF1820;
	local[2]= fqv[139];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[140];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[20])(ctx,1,local+6,&ftab[20],fqv[141]); /*cdddr*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,5,local+2); /*list**/
	local[2]= w;
	goto IF1821;
IF1820:
	if (T==NIL) goto IF1822;
	local[2]= fqv[142];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	local[2]= w;
	goto IF1823;
IF1822:
	local[2]= NIL;
IF1823:
IF1821:
IF1819:
	w = local[2];
	local[0] = w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	local[1]= fqv[8];
	local[2]= local[0];
	local[3]= fqv[143];
	local[4]= argv[0];
	local[5]= fqv[65];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[144];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	goto CON1811;
CON1816:
	local[0]= NIL;
CON1811:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:replace-shape*/
static pointer M1824(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL1827:
	if (local[1]==NIL) goto WHX1828;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[132];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	if (w==NIL) goto IF1831;
	local[2]= argv[0];
	local[3]= fqv[128];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF1832;
IF1831:
	local[2]= NIL;
IF1832:
	goto WHL1827;
WHX1828:
	local[2]= NIL;
BLK1829:
	w = NIL;
	argv[0]->c.obj.iv[9] = argv[2]->c.obj.iv[9];
	argv[0]->c.obj.iv[10] = argv[2]->c.obj.iv[10];
	argv[0]->c.obj.iv[11] = argv[2]->c.obj.iv[11];
	argv[0]->c.obj.iv[12] = argv[2]->c.obj.iv[12];
	argv[0]->c.obj.iv[8] = argv[2]->c.obj.iv[8];
	argv[0]->c.obj.iv[13] = argv[2]->c.obj.iv[13];
	argv[0]->c.obj.iv[15] = argv[2]->c.obj.iv[15];
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
WHL1833:
	if (local[1]==NIL) goto WHX1834;
	local[2]= local[1];
	local[3]= local[0];
	local[4]= fqv[66];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)RPLACA2(ctx,2,local+2); /*rplaca2*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	goto WHL1833;
WHX1834:
	local[2]= NIL;
BLK1835:
	w = local[2];
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[124];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[15]); /*send-all*/
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[146];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1837:
	if (local[1]==NIL) goto WHX1838;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[131];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL1837;
WHX1838:
	local[2]= NIL;
BLK1839:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK1825:
	ctx->vsp=local; return(local[0]);}

/*:+*/
static pointer M1841(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1843:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[133]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1842:
	ctx->vsp=local; return(local[0]);}

/*:-*/
static pointer M1844(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1846:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[135]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1845:
	ctx->vsp=local; return(local[0]);}

/*:**/
static pointer M1847(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1849:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[148]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1848:
	ctx->vsp=local; return(local[0]);}

/*:primitive-groups*/
static pointer M1850(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1852,env,argv,local);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET1853,env,argv,local);
	local[2]= argv[0];
	local[3]= fqv[115];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (w==NIL) goto IF1854;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto IF1855;
IF1854:
	local[2]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET1852(ctx,1,local+2,w);
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[15];
	w = local[1];
	ctx->vsp=local+4;
	w=FLET1853(ctx,1,local+3,w);
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
IF1855:
	w = local[2];
	local[0]= w;
BLK1851:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1857;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1859;
	local[0]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1858;
CON1859:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1860;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[21])(ctx,1,local+0,&ftab[21],fqv[149]); /*caadr*/
	local[0]= w;
	w = env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=FLET1852(ctx,1,local+0,w);
	local[0]= w;
	local[1]= env->c.clo.env2[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[150]); /*cdadr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON1858;
CON1860:
	local[0]= NIL;
CON1858:
	goto CON1856;
CON1857:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[125]); /*primitive-body-p*/
	if (w==NIL) goto CON1861;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON1856;
CON1861:
	local[0]= NIL;
CON1856:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1853(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF1862;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1865;
	local[0]= env->c.clo.env2[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1864;
CON1865:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1866;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[21])(ctx,1,local+0,&ftab[21],fqv[149]); /*caadr*/
	local[0]= w;
	w = env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=FLET1853(ctx,1,local+0,w);
	local[0]= w;
	local[1]= env->c.clo.env2[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[150]); /*cdadr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON1864;
CON1866:
	local[0]= NIL;
CON1864:
	goto IF1863;
IF1862:
	local[0]= NIL;
IF1863:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:constraint*/
static pointer M1867(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[27];
	local[4]= argv[2];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto IF1869;
	local[2]= argv[0];
	local[3]= fqv[151];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[152];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[0] = w;
	local[2]= argv[2];
	local[3]= fqv[151];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[152];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[1] = w;
	local[2]= loadglobal(fqv[153]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[32];
	local[5]= fqv[154];
	local[6]= argv[0];
	local[7]= fqv[155];
	local[8]= argv[2];
	local[9]= fqv[156];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[23])(ctx,2,local+10,&ftab[23],fqv[157]); /*contact-to-constraint*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	w = local[2];
	local[2]= w;
	goto IF1870;
IF1869:
	local[2]= NIL;
IF1870:
	w = local[2];
	local[0]= w;
BLK1868:
	ctx->vsp=local; return(local[0]);}

/*:contact-vertices*/
static pointer M1872(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1874;
	local[1]= argv[0];
	local[2]= fqv[158];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[159];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
WHL1877:
	if (local[7]==NIL) goto WHX1878;
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
WHL1882:
	if (local[9]==NIL) goto WHX1883;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[160];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	if (fqv[91]==local[10]) goto IF1886;
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[6];
	local[15]= fqv[163];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,6,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[3];
	ctx->vsp=local+11;
	local[3] = cons(ctx,local[10],w);
	w = local[3];
	ctx->vsp=local+10;
	local[10]=w;
	goto BLK1884;
	goto IF1887;
IF1886:
	local[10]= NIL;
IF1887:
	goto WHL1882;
WHX1883:
	local[10]= NIL;
BLK1884:
	w = NIL;
	goto WHL1877;
WHX1878:
	local[8]= NIL;
BLK1879:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
WHL1890:
	if (local[7]==NIL) goto WHX1891;
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
WHL1895:
	if (local[9]==NIL) goto WHX1896;
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
	if (w!=NIL) goto OR1901;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto OR1901;
	goto IF1899;
OR1901:
	local[10]= local[8];
	w = local[6]->c.obj.iv[3];
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[10];
	w = local[6];
	w->c.obj.iv[3] = local[11];
	goto IF1900;
IF1899:
	local[10]= NIL;
IF1900:
	goto WHL1895;
WHX1896:
	local[10]= NIL;
BLK1897:
	w = NIL;
	goto WHL1890;
WHX1891:
	local[8]= NIL;
BLK1892:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
WHL1903:
	if (local[7]==NIL) goto WHX1904;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[164];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	goto WHL1903;
WHX1904:
	local[8]= NIL;
BLK1905:
	w = NIL;
	w = local[3];
	local[1]= w;
	goto IF1875;
IF1874:
	local[1]= NIL;
IF1875:
	w = local[1];
	local[0]= w;
BLK1873:
	ctx->vsp=local; return(local[0]);}

/*:contact-edges*/
static pointer M1907(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1909;
	local[1]= argv[0];
	local[2]= fqv[165];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[159];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
WHL1912:
	if (local[7]==NIL) goto WHX1913;
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
WHL1917:
	if (local[9]==NIL) goto WHX1918;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[166];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto IF1921;
	local[10]= local[3];
	local[11]= local[4];
	local[12]= fqv[167];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO1923,env,argv,local);
	ctx->vsp=local+14;
	w=(*ftab[24])(ctx,4,local+10,&ftab[24],fqv[168]); /*find*/
	if (w!=NIL) goto IF1921;
	local[10]= local[6]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(*ftab[25])(ctx,1,local+10,&ftab[25],fqv[123]); /*plusp*/
	if (w==NIL) goto IF1924;
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[3];
	local[15]= fqv[163];
	local[16]= local[8];
	local[17]= fqv[169];
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
	goto IF1925;
IF1924:
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[3];
	local[15]= fqv[163];
	local[16]= local[8];
	local[17]= fqv[169];
	local[18]= local[6]->c.obj.iv[3];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	local[19]= local[6]->c.obj.iv[4];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,2,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
IF1925:
	goto IF1922;
IF1921:
	local[10]= NIL;
IF1922:
	goto WHL1917;
WHX1918:
	local[10]= NIL;
BLK1919:
	w = NIL;
	goto WHL1912;
WHX1913:
	local[8]= NIL;
BLK1914:
	w = NIL;
	w = local[4];
	local[1]= w;
	goto IF1910;
IF1909:
	local[1]= NIL;
IF1910:
	w = local[1];
	local[0]= w;
BLK1908:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-vertices*/
static pointer M1928(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1930,env,argv,local);
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1929:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-edges*/
static pointer M1931(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1933,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1932:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-faces*/
static pointer M1934(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1936,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1935:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1923(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1]->c.obj.iv[0];
	local[2]= loadglobal(fqv[29]);
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,3,local+0,&ftab[26],fqv[170]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1930(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= fqv[90];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1937;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1938;
IF1937:
	local[0]= NIL;
IF1938:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1933(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	local[3]= loadglobal(fqv[29]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	if (w==NIL) goto IF1939;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1940;
IF1939:
	local[0]= NIL;
IF1940:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1936(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	local[3]= loadglobal(fqv[29]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	if (w==NIL) goto IF1941;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1942;
IF1941:
	local[0]= NIL;
IF1942:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:radius*/
static pointer M1945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1948;}
	local[0]= NIL;
ENT1948:
ENT1947:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1949;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF1950;
IF1949:
	local[1]= NIL;
IF1950:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1946:
	ctx->vsp=local; return(local[0]);}

/*:inner*/
static pointer M1951(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
BLK1952:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M1953(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(4.00000000e+00);
	local[1]= makeflt(3.14159203e+00);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,5,local+0); /***/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK1954:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M1955(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[171];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VINNERPRODUCT(ctx,2,local+6); /*v.*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= local[7];
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF1957;
	local[8]= NIL;
	goto IF1958;
IF1957:
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[27])(ctx,3,local+8,&ftab[27],fqv[172]); /*midpoint*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SQRT(ctx,1,local+10); /*sqrt*/
	local[10]= makeflt(-(fltval(w)));
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= argv[2];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[27])(ctx,3,local+9,&ftab[27],fqv[172]); /*midpoint*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
IF1958:
	w = local[8];
	local[0]= w;
BLK1956:
	ctx->vsp=local; return(local[0]);}

/*:closest-point*/
static pointer M1959(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[171];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK1960:
	ctx->vsp=local; return(local[0]);}

/*:intersect-with-body*/
static pointer M1961(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[173];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1964:
	if (local[1]==NIL) goto WHX1965;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1968;
	w = T;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1962;
	goto IF1969;
IF1968:
	local[2]= NIL;
IF1969:
	goto WHL1964;
WHX1965:
	local[2]= NIL;
BLK1966:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK1962:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1970(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[174], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1972;
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0] = w;
KEY1972:
	if (n & (1<<1)) goto KEY1973;
	local[1] = makeflt(1.00000000e+00);
KEY1973:
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[53]));
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	argv[0]->c.obj.iv[2] = local[0];
	argv[0]->c.obj.iv[8] = local[1];
	w = argv[0];
	local[0]= w;
BLK1971:
	ctx->vsp=local; return(local[0]);}

/*add-wings*/
static pointer F1240(ctx,n,argv,env)
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
	local[5]= argv[0]->c.obj.iv[10];
WHL1976:
	if (local[5]==NIL) goto WHX1977;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= loadglobal(fqv[175]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[32];
	local[9]= fqv[176];
	local[10]= local[4]->c.obj.iv[3];
	local[11]= fqv[177];
	local[12]= local[4]->c.obj.iv[4];
	local[13]= fqv[178];
	local[14]= local[4]->c.obj.iv[1];
	local[15]= fqv[179];
	local[16]= local[4]->c.obj.iv[2];
	local[17]= fqv[99];
	local[18]= local[4]->c.obj.iv[5];
	local[19]= fqv[180];
	local[20]= local[4];
	local[21]= fqv[180];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	local[21]= fqv[181];
	local[22]= local[4];
	local[23]= fqv[181];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	local[23]= fqv[182];
	local[24]= local[4];
	local[25]= fqv[182];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	local[25]= fqv[183];
	local[26]= local[4];
	local[27]= fqv[183];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,20,local+7); /*send*/
	w = local[6];
	local[3] = w;
	local[6]= local[4];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,3,local+6,&ftab[28],fqv[184]); /*acons*/
	local[1] = w;
	goto WHL1976;
WHX1977:
	local[6]= NIL;
BLK1978:
	w = NIL;
	local[4]= NIL;
	local[5]= local[1];
WHL1982:
	if (local[5]==NIL) goto WHX1983;
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
	local[2] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[6]= local[3];
	local[7]= fqv[32];
	local[8]= fqv[180];
	local[9]= local[3]->c.obj.iv[7];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)ASSQ(ctx,2,local+9); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	local[10]= fqv[182];
	local[11]= local[3]->c.obj.iv[9];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)ASSQ(ctx,2,local+11); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	local[12]= fqv[181];
	local[13]= local[3]->c.obj.iv[8];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)ASSQ(ctx,2,local+13); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	local[14]= fqv[183];
	local[15]= local[3]->c.obj.iv[10];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ASSQ(ctx,2,local+15); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.cdr;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,10,local+6); /*send*/
	goto WHL1982;
WHX1983:
	local[6]= NIL;
BLK1984:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
WHL1987:
	if (local[5]==NIL) goto WHX1988;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[0] = NIL;
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[186];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1992:
	if (local[7]==NIL) goto WHX1993;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)ASSQ(ctx,2,local+8); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	goto WHL1992;
WHX1993:
	local[8]= NIL;
BLK1994:
	w = NIL;
	local[6]= local[0];
	local[7]= local[6];
	w = local[4];
	w->c.obj.iv[4] = local[7];
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[14];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1997:
	if (local[7]==NIL) goto WHX1998;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[0] = NIL;
	local[8]= NIL;
	local[9]= local[6];
	local[10]= fqv[186];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL2002:
	if (local[9]==NIL) goto WHX2003;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ASSQ(ctx,2,local+10); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	w = local[0];
	ctx->vsp=local+11;
	local[0] = cons(ctx,local[10],w);
	goto WHL2002;
WHX2003:
	local[10]= NIL;
BLK2004:
	w = NIL;
	local[8]= local[0];
	local[9]= local[8];
	w = local[6];
	w->c.obj.iv[4] = local[9];
	goto WHL1997;
WHX1998:
	local[8]= NIL;
BLK1999:
	w = NIL;
	goto WHL1987;
WHX1988:
	local[6]= NIL;
BLK1989:
	w = NIL;
	local[4]= (pointer)get_sym_func(fqv[187]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= w;
	w = argv[0];
	w->c.obj.iv[10] = local[5];
	w = argv[0];
	local[0]= w;
BLK1974:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___geobody(ctx,n,argv,env)
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
	local[0]= fqv[188];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2006;
	local[0]= fqv[189];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[190],w);
	goto IF2007;
IF2006:
	local[0]= fqv[191];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2007:
	local[0]= fqv[192];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[193];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[195]); /*require*/
	local[0]= fqv[196];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2008;
	local[0]= fqv[196];
	local[1]= fqv[197];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[196];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2010;
	local[0]= fqv[196];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2011;
IF2010:
	local[0]= NIL;
IF2011:
	local[0]= fqv[196];
	goto IF2009;
IF2008:
	local[0]= NIL;
IF2009:
	local[0]= fqv[199];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2012;
	local[0]= fqv[199];
	local[1]= fqv[197];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[199];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2014;
	local[0]= fqv[199];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2015;
IF2014:
	local[0]= NIL;
IF2015:
	local[0]= fqv[199];
	goto IF2013;
IF2012:
	local[0]= NIL;
IF2013:
	local[0]= fqv[200];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2016;
	local[0]= fqv[200];
	local[1]= fqv[197];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[200];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2018;
	local[0]= fqv[200];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2019;
IF2018:
	local[0]= NIL;
IF2019:
	local[0]= fqv[200];
	goto IF2017;
IF2016:
	local[0]= NIL;
IF2017:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1241,fqv[33],fqv[201],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1250,fqv[173],fqv[201],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1252,fqv[185],fqv[201],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1258,fqv[205],fqv[201],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1260,fqv[23],fqv[201],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1262,fqv[186],fqv[201],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1264,fqv[209],fqv[201],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1266,fqv[211],fqv[201],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1268,fqv[28],fqv[201],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1270,fqv[10],fqv[201],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1276,fqv[11],fqv[201],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1284,fqv[12],fqv[201],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1292,fqv[14],fqv[201],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1294,fqv[22],fqv[201],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1299,fqv[6],fqv[201],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1315,fqv[220],fqv[201],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1329,fqv[222],fqv[201],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1338,fqv[74],fqv[201],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1342,fqv[97],fqv[201],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1348,fqv[4],fqv[201],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1355,fqv[56],fqv[201],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1362,fqv[57],fqv[201],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1373,fqv[58],fqv[201],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1395,fqv[69],fqv[201],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1404,fqv[46],fqv[201],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1423,fqv[32],fqv[201],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1451,fqv[56],fqv[233],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1453,fqv[57],fqv[233],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1455,fqv[58],fqv[233],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1459,fqv[237],fqv[233],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1461,fqv[239],fqv[233],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1463,fqv[62],fqv[233],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1467,fqv[63],fqv[233],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1477,fqv[243],fqv[233],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1479,fqv[67],fqv[233],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1481,fqv[68],fqv[233],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1490,fqv[60],fqv[233],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1492,fqv[248],fqv[233],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1496,fqv[72],fqv[233],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1499,fqv[75],fqv[233],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1502,fqv[71],fqv[233],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1512,fqv[253],fqv[233],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1529,fqv[255],fqv[233],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1617,fqv[82],fqv[233],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1659,fqv[258],fqv[233],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1665,fqv[98],fqv[233],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1674,fqv[9],fqv[233],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1728,fqv[115],fqv[233],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1731,fqv[146],fqv[233],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1748,fqv[126],fqv[233],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1754,fqv[265],fqv[233],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1759,fqv[119],fqv[233],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1763,fqv[268],fqv[233],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1768,fqv[118],fqv[233],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1770,fqv[32],fqv[233],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1824,fqv[147],fqv[233],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1841,fqv[111],fqv[233],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1844,fqv[113],fqv[233],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1847,fqv[275],fqv[233],fqv[276]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1850,fqv[112],fqv[233],fqv[277]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1867,fqv[278],fqv[233],fqv[279]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1872,fqv[151],fqv[233],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1907,fqv[152],fqv[233],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1928,fqv[158],fqv[233],fqv[282]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1931,fqv[165],fqv[233],fqv[283]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1934,fqv[159],fqv[233],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1945,fqv[285],fqv[286],fqv[287]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1951,fqv[90],fqv[286],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1953,fqv[62],fqv[286],fqv[289]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1955,fqv[77],fqv[286],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1959,fqv[291],fqv[286],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1961,fqv[293],fqv[286],fqv[294]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1970,fqv[32],fqv[286],fqv[295]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[296],module,F1240,fqv[297]);
	local[0]= fqv[298];
	local[1]= fqv[299];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[300]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
