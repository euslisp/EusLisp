/* pprolog.c :  entry=pprolog */
/* compiled by EusLisp 8.0 beta for Solaris  Wed Jan 25 09:59:26 JST 1995 */
#include "eus.h"
#include "pprolog.h"
#pragma init (init_object_module)
extern double fabs();
extern pointer fcallx();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer pprolog();
extern pointer build_quote_vector();
static init_object_module()
  { add_module_initializer("pprolog", pprolog);}


/*init-prolog*/
static pointer F393(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= NIL;
	local[1]= loadglobal(fqv[0]);
whl396:
	if (local[1]==NIL) goto whx397;
	local[2]= xcar(local[1]);
	local[1] = xcdr(local[1]);
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[2]); /*remprop*/
	goto whl396;
whx397:
	local[2]= NIL;
blk398:
	w = NIL;
	local[0]= NIL;
	storeglobal(fqv[0],local[0]);
	w = local[0];
	local[0]= w;
blk394:
	ctx->vsp=local; return(local[0]);}

/*newsubst*/
static pointer F400(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	w = fqv[3];
	local[0]= w;
blk401:
	ctx->vsp=local; return(local[0]);}

/*var?*/
static pointer F402(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto and404;
	local[0]= argv[0]->c.obj.iv[4];
	{ register int i=intval(makeint(0));
	  w=makeint(local[0]->c.str.chars[i]);}
	local[0]= w;
	local[0]= ((makeint(42))==(local[0])?T:NIL);
and404:
	w = local[0];
	local[0]= w;
blk403:
	ctx->vsp=local; return(local[0]);}

/*assigned?*/
static pointer F405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= xcdr(argv[1]);
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
blk406:
	ctx->vsp=local; return(local[0]);}

/*link*/
static pointer F407(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,2,local+2,&ftab[1],fqv[4]); /*fetch*/
	local[2]= w;
	w = loadglobal(fqv[5]);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w = xcdr(argv[1]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)RPLACD(ctx,2,local+0); /*rplacd*/
	local[0]= w;
	w = loadglobal(fqv[6]);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	storeglobal(fqv[6],local[0]);
	w = local[0];
	local[0]= w;
blk408:
	ctx->vsp=local; return(local[0]);}

/*unify*/
static pointer F409(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F402(ctx,1,local+0); /*var?*/
	if (w==NIL) goto con412;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F405(ctx,2,local+0); /*assigned?*/
	if (w==NIL) goto con414;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[4]); /*fetch*/
	local[0]= w;
	local[1]= loadglobal(fqv[5]);
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	local[0]= w;
	goto con413;
con414:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F407(ctx,4,local+0); /*link*/
	local[0]= w;
	goto con413;
con415:
	local[0]= NIL;
con413:
	goto con411;
con412:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F402(ctx,1,local+0); /*var?*/
	if (w==NIL) goto con416;
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	local[0]= w;
	goto con411;
con416:
	w = argv[0];
	if (!!iscons(w)) goto con417;
	local[0]= argv[0];
	local[0]= ((argv[2])==(local[0])?T:NIL);
	goto con411;
con417:
	w = argv[2];
	if (!!iscons(w)) goto con418;
	local[0]= NIL;
	goto con411;
con418:
	local[0]= xcar(argv[0]);
	local[1]= argv[1];
	local[2]= xcar(argv[2]);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	if (w==NIL) goto con419;
	local[0]= xcdr(argv[0]);
	local[1]= argv[1];
	local[2]= xcdr(argv[2]);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	local[0]= w;
	goto con411;
con419:
	local[0]= NIL;
	goto con411;
con420:
	local[0]= NIL;
con411:
	w = local[0];
	local[0]= w;
blk410:
	ctx->vsp=local; return(local[0]);}

/*fetch*/
static pointer F421(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	storeglobal(fqv[5],local[0]);
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F402(ctx,1,local+0); /*var?*/
	if (w==NIL) goto con424;
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F405(ctx,2,local+1); /*assigned?*/
	local[0] = w;
	if (local[0]!=NIL) goto con426;
	local[1]= argv[0];
	goto con425;
con426:
	local[1]= xcadr(local[0]);
	local[2]= xcdr(xcdr(local[0]));
	ctx->vsp=local+3;
	w=(pointer)F421(ctx,2,local+1); /*fetch*/
	local[1]= w;
	goto con425;
con427:
	local[1]= NIL;
con425:
	w = local[1];
	local[0]= w;
	goto con423;
con424:
	local[0]= argv[0];
	goto con423;
con428:
	local[0]= NIL;
con423:
	w = local[0];
	local[0]= w;
blk422:
	ctx->vsp=local; return(local[0]);}

/*fetch-value*/
static pointer F429(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F402(ctx,1,local+0); /*var?*/
	if (w==NIL) goto con432;
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F405(ctx,2,local+1); /*assigned?*/
	local[0] = w;
	if (local[0]!=NIL) goto con434;
	local[1]= argv[0];
	goto con433;
con434:
	local[1]= xcadr(local[0]);
	local[2]= xcdr(xcdr(local[0]));
	ctx->vsp=local+3;
	w=(pointer)F429(ctx,2,local+1); /*fetch-value*/
	local[1]= w;
	goto con433;
con435:
	local[1]= NIL;
con433:
	w = local[1];
	local[0]= w;
	goto con431;
con432:
	w = argv[0];
	if (!!iscons(w)) goto con436;
	local[0]= argv[0];
	goto con431;
con436:
	local[0]= xcar(argv[0]);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	local[1]= xcdr(argv[0]);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F429(ctx,2,local+1); /*fetch-value*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto con431;
con437:
	local[0]= NIL;
con431:
	w = local[0];
	local[0]= w;
blk430:
	ctx->vsp=local; return(local[0]);}

/*undo*/
static pointer F438(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
whl440:
	if (loadglobal(fqv[6])==NIL) goto whx441;
	local[0]= xcar(loadglobal(fqv[6]));
	local[1]= loadglobal(fqv[6]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[7]); /*cddar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)RPLACD(ctx,2,local+0); /*rplacd*/
	local[0]= xcdr(loadglobal(fqv[6]));
	storeglobal(fqv[6],local[0]);
	goto whl440;
whx441:
	local[0]= NIL;
blk442:
	w = local[0];
	local[0]= w;
blk439:
	ctx->vsp=local; return(local[0]);}

/*try-sys*/
static pointer F443(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(argv[0]);
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	if (local[0]==NIL) goto if445;
	local[1]= local[0];
	local[2]= xcdr(argv[0]);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,3,local+1); /*funcall*/
	local[1]= w;
	goto if446;
if445:
	local[1]= NIL;
if446:
	w = local[1];
	local[0]= w;
blk444:
	ctx->vsp=local; return(local[0]);}

/*refutes*/
static pointer F447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[1];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[9],w);
	w = argv[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[10],w);
	w = argv[3];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[11],w);
	if (argv[0]==NIL) goto if449;
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,1,local+9,&ftab[3],fqv[12]); /*refute*/
	local[9]= w;
	goto if450;
if449:
	if (loadglobal(fqv[11])==NIL) goto if451;
	local[9]= xcar(xcar(loadglobal(fqv[11])));
	local[10]= NIL;
	w = NIL;
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= xcdr(xcar(loadglobal(fqv[11])));
	local[12]= xcdr(loadglobal(fqv[11]));
	ctx->vsp=local+13;
	w=(pointer)F447(ctx,4,local+9); /*refutes*/
	local[9]= w;
	goto if452;
if451:
	local[9]= fqv[13];
if452:
if450:
	ctx->vsp=local+10;
	unbindx(ctx,3);
	w = local[9];
	local[0]= w;
blk448:
	ctx->vsp=local; return(local[0]);}

/*refuten*/
static pointer F453(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(argv[0]);
	local[1]= loadglobal(fqv[10]);
	local[2]= xcar(argv[1]);
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	local[0]= w;
	if (w==NIL) goto and455;
	local[0]= xcdr(argv[1]);
	local[1]= NIL;
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= loadglobal(fqv[9]);
	local[3]= xcdr(argv[0]);
	w = loadglobal(fqv[10]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w = loadglobal(fqv[11]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)F447(ctx,4,local+0); /*refutes*/
	local[0]= w;
and455:
	w = local[0];
	local[0]= w;
blk454:
	ctx->vsp=local; return(local[0]);}

/*refute*/
static pointer F456(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[6],w);
	if (loadglobal(fqv[14])==NIL) goto if458;
	local[6]= xcar(argv[0]);
	local[7]= loadglobal(fqv[10]);
	ctx->vsp=local+8;
	w=(pointer)F429(ctx,2,local+6); /*fetch-value*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	ctx->vsp=local+6;
	w=(pointer)READCH(ctx,0,local+6); /*read-char*/
	local[6]= w;
	goto if459;
if458:
	local[6]= NIL;
if459:
	local[6]= xcar(argv[0]);
	ctx->vsp=local+7;
	w=(pointer)F402(ctx,1,local+6); /*var?*/
	if (w==NIL) goto if460;
	local[6]= xcar(argv[0]);
	local[7]= loadglobal(fqv[10]);
	ctx->vsp=local+8;
	w=(pointer)F421(ctx,2,local+6); /*fetch*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	argv[0] = w;
	local[6]= argv[0];
	goto if461;
if460:
	local[6]= NIL;
if461:
	local[6]= xcar(xcar(argv[0]));
	local[7]= fqv[1];
	ctx->vsp=local+8;
	w=(pointer)GETPROP(ctx,2,local+6); /*get*/
	local[0] = w;
whl462:
	if (local[0]==NIL) goto whx463;
	local[6]= argv[0];
	local[7]= xcar(local[0]);
	local[0] = xcdr(local[0]);
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F453(ctx,2,local+6); /*refuten*/
	if (w==NIL) goto if465;
	w = fqv[13];
	ctx->vsp=local+6;
	unwind(ctx,local+0);
	local[0]=w;
	goto blk457;
	goto if466;
if465:
	ctx->vsp=local+6;
	w=(pointer)F438(ctx,0,local+6); /*undo*/
	local[6]= w;
if466:
	goto whl462;
whx463:
	local[6]= NIL;
blk464:
	local[6]= xcar(argv[0]);
	local[7]= loadglobal(fqv[10]);
	ctx->vsp=local+8;
	w=(pointer)F443(ctx,2,local+6); /*try-sys*/
	local[2] = w;
	if (local[2]==NIL) goto if468;
	local[6]= xcdr(argv[0]);
	local[7]= NIL;
	w = NIL;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= loadglobal(fqv[10]);
	local[9]= loadglobal(fqv[11]);
	ctx->vsp=local+10;
	w=(pointer)F447(ctx,4,local+6); /*refutes*/
	if (w==NIL) goto if468;
	local[6]= local[2];
	goto if469;
if468:
	ctx->vsp=local+6;
	w=(pointer)F438(ctx,0,local+6); /*undo*/
	local[6]= w;
if469:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
blk457:
	ctx->vsp=local; return(local[0]);}

/*define-clause*/
static pointer F470(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= xcar(xcar(argv[0]));
	local[1]= local[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	local[2]= local[0];
	w = loadglobal(fqv[0]);
	if (memq(local[2],w)!=NIL) goto if472;
	local[2]= local[0];
	w = loadglobal(fqv[0]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[0],local[2]);
	goto if473;
if472:
	local[2]= NIL;
if473:
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[15]); /*member*/
	if (w!=NIL) goto if474;
	if (local[1]==NIL) goto if476;
	local[2]= local[1];
	local[3]= argv[0];
	w = NIL;
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[2]= w;
	goto if477;
if476:
	local[2]= xcar(xcar(argv[0]));
	local[3]= argv[0];
	w = NIL;
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= w;
if477:
	goto if475;
if474:
	local[2]= NIL;
if475:
	w = local[2];
	local[0]= w;
blk471:
	ctx->vsp=local; return(local[0]);}

/*read-clauses*/
static pointer F478(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[16];
whl480:
	local[2]= local[1];
	if (fqv[16]!=local[2]) goto whx481;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	local[1] = w;
	goto whl480;
whx481:
	local[2]= NIL;
blk482:
	local[2]= local[1];
	if (fqv[17]==local[2]) goto if483;
	local[2]= T;
	local[3]= fqv[18];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= fqv[1];
	w = NIL;
	ctx->vsp=local+3;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER);
	goto if484;
if483:
	local[2]= NIL;
if484:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)REVERSE(ctx,1,local+2); /*reverse*/
	local[0]= w;
blk479:
	ctx->vsp=local; return(local[0]);}

/*prolog*/
static pointer F485(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ent488;}
	local[0]= T;
ent488:
ent487:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	if (T!=local[6]) goto if489;
	local[6]= T;
	local[7]= fqv[19];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,2,local+6); /*format*/
	local[6]= w;
	goto if490;
if489:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,1,local+6,&ftab[5],fqv[20]); /*open*/
	local[0] = w;
	local[6]= local[0];
if490:
whl491:
	if (T==NIL) goto whx492;
	local[6]= local[0];
	if (T!=local[6]) goto if494;
	local[6]= T;
	local[7]= fqv[21];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,2,local+6); /*format*/
	local[6]= T;
	ctx->vsp=local+7;
	w=(pointer)FINOUT(ctx,1,local+6); /*finish-output*/
	local[6]= w;
	goto if495;
if494:
	local[6]= NIL;
if495:
	{jmp_buf jb;
	w = fqv[1];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,jb);
	if ((w=(pointer)setjmp(jb))!=0) { /*fsp=vsp;*/ goto cat496;}
	local[12]= local[0];
	local[13]= NIL;
	local[14]= fqv[22];
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,3,local+12); /*read*/
	local[1] = w;
	local[12]= local[1];
	local[13]= local[12];
	if (fqv[23]!=local[13]) goto if498;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)F478(ctx,1,local+13); /*read-clauses*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)F470(ctx,1,local+13); /*define-clause*/
	local[13]= fqv[24];
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
	goto if499;
if498:
	local[13]= local[12];
	if (fqv[16]!=local[13]) goto if500;
	local[13]= NIL;
	w = NIL;
	ctx->vsp=local+14;
	local[4] = cons(ctx,local[13],w);
	local[13]= NIL;
	w = NIL;
	ctx->vsp=local+14;
	local[5] = cons(ctx,local[13],w);
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)F478(ctx,1,local+13); /*read-clauses*/
	local[2] = w;
	local[13]= local[2];
	local[14]= local[4];
	local[15]= local[5];
	local[16]= NIL;
	ctx->vsp=local+17;
	w=(pointer)F447(ctx,4,local+13); /*refutes*/
	local[3] = w;
	if (local[3]==NIL) goto if502;
	local[13]= local[2];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)F429(ctx,2,local+13); /*fetch-value*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
	goto if503;
if502:
	local[13]= fqv[25];
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
if503:
	goto if501;
if500:
	local[13]= local[12];
	w = fqv[26];
	if (memq(local[13],w)==NIL) goto if504;
	w = fqv[27];
	ctx->vsp=local+13;
	unwind(ctx,local+0);
	local[0]=w;
	goto blk486;
	goto if505;
if504:
	if (T==NIL) goto if506;
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)EVAL(ctx,1,local+13); /*eval*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
	goto if507;
if506:
	local[13]= NIL;
if507:
if505:
if501:
if499:
	w = local[13];
cat496:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto whl491;
whx492:
	local[6]= NIL;
blk493:
	w = local[6];
	local[0]= w;
blk486:
	ctx->vsp=local; return(local[0]);}

/*defsyspred*/
static pointer F508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
rst510:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= loadglobal(fqv[29]);
	local[4]= fqv[30];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[29]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INTERN(ctx,1,local+3); /*intern*/
	local[3]= w;
	local[4]= fqv[31];
	local[5]= fqv[32];
	local[6]= local[3];
	local[7]= argv[1];
	w = loadglobal(fqv[28]);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[34];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[34];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[34];
	local[10]= fqv[8];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
blk509:
	ctx->vsp=local; return(local[0]);}

/*p_call*/
static pointer F511(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(argv[0]);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,clo513,argv,local);
	local[2]= xcdr(argv[0]);
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	w = fqv[13];
	local[0]= w;
blk512:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo513(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*p_evalq*/
static pointer F514(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(xcar(argv[0]));
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,clo518,argv,local);
	local[2]= xcdr(xcar(argv[0]));
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= xcadr(argv[0]);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	if (w==NIL) goto if516;
	local[0]= fqv[13];
	goto if517;
if516:
	local[0]= NIL;
if517:
	w = local[0];
	local[0]= w;
blk515:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo518(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*p_eval*/
static pointer F519(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(xcar(argv[0]));
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,clo523,argv,local);
	local[2]= xcdr(xcar(argv[0]));
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= xcadr(argv[0]);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F409(ctx,4,local+0); /*unify*/
	if (w==NIL) goto if521;
	local[0]= fqv[13];
	goto if522;
if521:
	local[0]= NIL;
if522:
	w = local[0];
	local[0]= w;
blk520:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo523(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*p_purge*/
static pointer F524(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,clo526,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	w = fqv[35];
	local[0]= w;
blk525:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer clo526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	local[1]= fqv[1];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[2]); /*remprop*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*p_load*/
static pointer F527(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(argv[0]);
	ctx->vsp=local+1;
	w=(pointer)F485(ctx,1,local+0); /*prolog*/
	w = T;
	local[0]= w;
blk528:
	ctx->vsp=local; return(local[0]);}

/*p_print*/
static pointer F529(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= xcar(argv[0]);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	w = fqv[13];
	local[0]= w;
blk530:
	ctx->vsp=local; return(local[0]);}

/*p_false*/
static pointer F531(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
blk532:
	ctx->vsp=local; return(local[0]);}

/*p_not*/
static pointer F533(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	w = local[0];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[11],w);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F456(ctx,1,local+4); /*refute*/
	local[4]= ((w)==NIL?T:NIL);
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
blk534:
	ctx->vsp=local; return(local[0]);}

/*p_assert*/
static pointer F535(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F429(ctx,2,local+0); /*fetch-value*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F470(ctx,1,local+0); /*define-clause*/
	w = T;
	local[0]= w;
blk536:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer pprolog(ctx,n,argv)
register context *ctx; int n; pointer *argv;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;
  module=argv[0];
  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();
	local[0]= fqv[36];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	local[0]= fqv[14];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if537;
	local[0]= fqv[14];
	local[1]= fqv[37];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	local[0]= fqv[14];
	goto if538;
if537:
	local[0]= NIL;
if538:
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if539;
	local[0]= fqv[0];
	local[1]= fqv[37];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	local[0]= fqv[0];
	goto if540;
if539:
	local[0]= NIL;
if540:
	ctx->vsp=local+0;
	compfun(ctx,fqv[40],module,F393,fqv[41]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[42],module,F400,fqv[43]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[44],module,F402,fqv[45]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F405,fqv[47]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[48],module,F407,fqv[49]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F409,fqv[51]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[4],module,F421,fqv[52]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[53],module,F429,fqv[54]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[55],module,F438,fqv[56]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[57],module,F443,fqv[58]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[59],module,F447,fqv[60]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[61],module,F453,fqv[62]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[12],module,F456,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F470,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F478,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[1],module,F485,fqv[68]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[69],module,F508,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F511,fqv[72]);
	local[0]= fqv[73];
	local[1]= fqv[71];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F514,fqv[75]);
	local[0]= fqv[76];
	local[1]= fqv[74];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F519,fqv[78]);
	local[0]= fqv[79];
	local[1]= fqv[77];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F524,fqv[81]);
	local[0]= fqv[82];
	local[1]= fqv[80];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F527,fqv[84]);
	local[0]= fqv[85];
	local[1]= fqv[83];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F529,fqv[87]);
	local[0]= fqv[88];
	local[1]= fqv[86];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F531,fqv[90]);
	local[0]= fqv[91];
	local[1]= fqv[89];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F533,fqv[93]);
	local[0]= fqv[94];
	local[1]= fqv[92];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F535,fqv[96]);
	local[0]= fqv[97];
	local[1]= fqv[95];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
