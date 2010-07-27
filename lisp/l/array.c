/* array.c :  entry=array */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "array.h"
#pragma init (register_array)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___array();
extern pointer build_quote_vector();
static register_array()
  { add_module_initializer("___array", ___array);}

static pointer F55735();
static pointer F55737();
static pointer F55739();
static pointer F55741();
static pointer F55743();
static pointer F55745();
static pointer F55747();
static pointer F55749();
static pointer F55751();
static pointer F55753();
static pointer F55755();
static pointer F55757();
static pointer F55759();
static pointer F55767();
static pointer F55769();
static pointer F55771();
static pointer F55773();
static pointer F55775();
static pointer F55777();
static pointer F55779();
static pointer F55781();
static pointer F55783();
static pointer F55785();
static pointer F55787();
static pointer F55789();
static pointer F55791();
static pointer F55793();
static pointer F55795();
static pointer F55797();
static pointer F55799();
static pointer F55801();
static pointer F55803();
static pointer F55805();
static pointer F55807();
static pointer F55809();
static pointer F55811();
static pointer F55813();
static pointer F55815();

/*:elmtype*/
static pointer M55896(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK55897:
	ctx->vsp=local; return(local[0]);}

/*:element-type*/
static pointer M55911(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK55912:
	ctx->vsp=local; return(local[0]);}

/*:elmtype*/
static pointer M55945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK55946:
	ctx->vsp=local; return(local[0]);}

/*:element-type*/
static pointer M55965(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK55966:
	ctx->vsp=local; return(local[0]);}

/*:element-type*/
static pointer M56015(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)F55767(ctx,1,local+0); /*float-vector-p*/
	if (w==NIL) goto CON56030;
	local[0]= fqv[4];
	goto CON56028;
CON56030:
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)F55769(ctx,1,local+0); /*integer-vector-p*/
	if (w==NIL) goto CON56039;
	local[0]= fqv[5];
	goto CON56028;
CON56039:
	w = argv[0]->c.obj.iv[1];
	if (!isstring(w)) goto CON56048;
	local[0]= fqv[6];
	goto CON56028;
CON56048:
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)F55771(ctx,1,local+0); /*bit-vector-p*/
	if (w==NIL) goto CON56055;
	local[0]= fqv[7];
	goto CON56028;
CON56055:
	local[0]= T;
	goto CON56028;
CON56064:
	local[0]= NIL;
CON56028:
	w = local[0];
	local[0]= w;
BLK56016:
	ctx->vsp=local; return(local[0]);}

/*fill-initial-contents*/
static pointer F55735(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= makeint(0);
	if (argv[2]==NIL) goto CON56137;
	local[2]= (pointer)get_sym_func(fqv[8]);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[1] = w;
	local[2]= makeint(0);
	local[3]= local[0];
WHL56177:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX56178;
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= argv[2];
	local[7]= argv[3];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F55735(ctx,4,local+4); /*fill-initial-contents*/
	local[4]= argv[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	argv[1] = w;
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL56177;
WHX56178:
	local[4]= NIL;
BLK56179:
	w = NIL;
	local[2]= w;
	goto CON56135;
CON56137:
	local[2]= makeint(0);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL56249:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX56250;
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= argv[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	argv[1] = (pointer)((integer_t)(argv[1])+4);
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF56290;
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto IF56291;
IF56290:
	local[4]= NIL;
IF56291:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL56249;
WHX56250:
	local[4]= NIL;
BLK56251:
	w = NIL;
	local[2]= w;
	goto CON56135;
CON56220:
	local[2]= NIL;
CON56135:
	w = argv[0];
	local[0]= w;
BLK56071:
	ctx->vsp=local; return(local[0]);}

/*make-array*/
static pointer F55737(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY56336;
	local[0] = loadglobal(fqv[11]);
KEY56336:
	if (n & (1<<1)) goto KEY56343;
	local[1] = NIL;
KEY56343:
	if (n & (1<<2)) goto KEY56348;
	local[2] = NIL;
KEY56348:
	if (n & (1<<3)) goto KEY56353;
	local[3] = makeint(0);
KEY56353:
	if (n & (1<<4)) goto KEY56358;
	local[4] = NIL;
KEY56358:
	if (n & (1<<5)) goto KEY56363;
	local[5] = NIL;
KEY56363:
	if (n & (1<<6)) goto KEY56368;
	local[6] = NIL;
KEY56368:
	if (n & (1<<7)) goto KEY56373;
	local[7] = NIL;
KEY56373:
	if (n & (1<<8)) goto KEY56378;
	local[8] = NIL;
KEY56378:
	if (n & (1<<9)) goto KEY56383;
	local[9] = NIL;
KEY56383:
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)CLASSP(ctx,1,local+13); /*classp*/
	if (w!=NIL) goto IF56396;
	local[13]= local[0];
	local[14]= local[13];
	w = fqv[12];
	if (memq(local[14],w)==NIL) goto IF56422;
	local[14]= loadglobal(fqv[13]);
	goto IF56423;
IF56422:
	local[14]= local[13];
	w = fqv[14];
	if (memq(local[14],w)==NIL) goto IF56435;
	local[14]= loadglobal(fqv[15]);
	goto IF56436;
IF56435:
	local[14]= local[13];
	w = fqv[16];
	if (memq(local[14],w)==NIL) goto IF56448;
	local[14]= loadglobal(fqv[17]);
	goto IF56449;
IF56448:
	local[14]= local[13];
	w = fqv[18];
	if (memq(local[14],w)==NIL) goto IF56461;
	local[14]= loadglobal(fqv[19]);
	goto IF56462;
IF56461:
	if (T==NIL) goto IF56474;
	local[14]= loadglobal(fqv[11]);
	goto IF56475;
IF56474:
	local[14]= NIL;
IF56475:
IF56462:
IF56449:
IF56436:
IF56423:
	w = local[14];
	local[0] = w;
	local[13]= local[0];
	goto IF56397;
IF56396:
	local[13]= NIL;
IF56397:
	w = argv[0];
	if (!isint(w)) goto CON56487;
	local[13]= local[0];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[11] = w;
	local[12] = local[11];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	argv[0] = w;
	local[13]= argv[0];
	goto CON56485;
CON56487:
	local[13]= loadglobal(fqv[20]);
	ctx->vsp=local+14;
	w=(pointer)INSTANTIATE(ctx,1,local+13); /*instantiate*/
	local[12] = w;
	local[13]= makeint(0);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)LENGTH(ctx,1,local+14); /*length*/
	local[14]= w;
	local[15]= (pointer)get_sym_func(fqv[8]);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,2,local+15); /*apply*/
	local[15]= w;
	local[16]= local[14];
	local[17]= makeint(7);
	ctx->vsp=local+18;
	w=(pointer)GREATERP(ctx,2,local+16); /*>*/
	if (w==NIL) goto IF56551;
	local[16]= fqv[21];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
	goto IF56552;
IF56551:
	local[16]= NIL;
IF56552:
	local[16]= (pointer)get_sym_func(fqv[22]);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(*ftab[1])(ctx,2,local+16,&ftab[1],fqv[23]); /*every*/
	if (w!=NIL) goto IF56561;
	local[16]= fqv[24];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
	goto IF56562;
IF56561:
	local[16]= NIL;
IF56562:
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)VECTORP(ctx,1,local+16); /*vectorp*/
	if (w==NIL) goto CON56582;
	local[16]= local[2];
	goto CON56580;
CON56582:
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)ARRAYP(ctx,1,local+16); /*arrayp*/
	if (w==NIL) goto CON56590;
	local[16]= local[2]->c.obj.iv[1];
	goto CON56580;
CON56590:
	local[16]= local[0];
	local[17]= makeint(1);
	local[18]= local[15];
	ctx->vsp=local+19;
	w=(pointer)MAX(ctx,2,local+17); /*max*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[16]= w;
	goto CON56580;
CON56602:
	local[16]= NIL;
CON56580:
	local[11] = local[16];
	local[16]= local[14];
	local[17]= local[16];
	*(ovafptr(local[12],fqv[25])) = local[17];
	local[16]= local[11];
	local[17]= local[16];
	w = local[12];
	w->c.obj.iv[1] = local[17];
	w = local[1];
	if (!isnum(w)) goto IF56631;
	local[16]= local[1];
	goto IF56632;
IF56631:
	if (local[1]==NIL) goto IF56638;
	local[16]= local[15];
	goto IF56639;
IF56638:
	local[16]= NIL;
IF56639:
IF56632:
	local[17]= local[16];
	w = local[12];
	w->c.obj.iv[3] = local[17];
	local[16]= local[3];
	local[17]= local[16];
	w = local[12];
	w->c.obj.iv[4] = local[17];
	local[16]= makeint(0);
TAG56672:
	local[17]= local[16];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)GREQP(ctx,2,local+17); /*>=*/
	if (w==NIL) goto IF56677;
	w = NIL;
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK56657;
	goto IF56678;
IF56677:
	local[17]= NIL;
IF56678:
	local[17]= local[12];
	local[18]= loadglobal(fqv[20]);
	local[19]= local[16];
	local[20]= makeint(5);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= argv[0];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)ELT(ctx,2,local+20); /*elt*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SETSLOT(ctx,4,local+17); /*setslot*/
	local[17]= (pointer)((integer_t)(local[16])+4);
	local[16] = local[17];
	w = NIL;
	ctx->vsp=local+17;
	goto TAG56672;
	w = NIL;
	local[16]= w;
BLK56657:
	w = local[16];
	local[13]= w;
	goto CON56485;
CON56517:
	local[13]= NIL;
CON56485:
	if (local[6]==NIL) goto IF56738;
	local[13]= local[11];
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,2,local+13,&ftab[2],fqv[26]); /*fill*/
	local[13]= w;
	goto IF56739;
IF56738:
	local[13]= NIL;
IF56739:
	if (local[5]==NIL) goto IF56754;
	local[13]= local[11];
	local[14]= makeint(0);
	local[15]= argv[0];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)F55735(ctx,4,local+13); /*fill-initial-contents*/
	local[13]= w;
	goto IF56755;
IF56754:
	local[13]= NIL;
IF56755:
	w = local[12];
	local[0]= w;
BLK56318:
	ctx->vsp=local; return(local[0]);}

/*array-total-size*/
static pointer F55739(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[25]));
	local[1]= makeint(1);
	local[2]= makeint(0);
	local[3]= local[0];
WHL56821:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX56822;
	local[4]= local[1];
	local[5]= argv[0];
	local[6]= loadglobal(fqv[20]);
	local[7]= makeint(5);
	w = local[2];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[7]= (pointer)((integer_t)local[7] + (integer_t)w);
	ctx->vsp=local+8;
	w=(pointer)SLOT(ctx,3,local+5); /*slot*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[1] = w;
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL56821;
WHX56822:
	local[4]= NIL;
BLK56823:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK56773:
	ctx->vsp=local; return(local[0]);}

/*fill-pointer*/
static pointer F55741(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ARRAYP(ctx,1,local+0); /*arrayp*/
	if (w==NIL) goto IF56879;
	local[0]= *(ovafptr(argv[0],fqv[27]));
	goto IF56880;
IF56879:
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF56880:
	w = local[0];
	local[0]= w;
BLK56869:
	ctx->vsp=local; return(local[0]);}

/*array-rank*/
static pointer F55743(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[25]));
	local[0]= w;
BLK56893:
	ctx->vsp=local; return(local[0]);}

/*array-dimensions*/
static pointer F55745(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[25]));
	local[1]= NIL;
WHL56932:
	local[2]= local[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto WHX56933;
	local[2]= argv[0];
	local[3]= loadglobal(fqv[20]);
	local[4]= makeint(5);
	local[0] = (pointer)((integer_t)(local[0])-4);
	w = local[0];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[4]= (pointer)((integer_t)local[4] + (integer_t)w);
	ctx->vsp=local+5;
	w=(pointer)SLOT(ctx,3,local+2); /*slot*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL56932;
WHX56933:
	local[2]= NIL;
BLK56934:
	w = local[1];
	local[0]= w;
BLK56908:
	ctx->vsp=local; return(local[0]);}

/*array-dimension*/
static pointer F55747(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ARRAYP(ctx,1,local+0); /*arrayp*/
	if (w==NIL) goto IF56986;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[20]);
	local[2]= makeint(5);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SLOT(ctx,3,local+0); /*slot*/
	local[0]= w;
	goto IF56987;
IF56986:
	local[0]= NIL;
IF56987:
	w = local[0];
	local[0]= w;
BLK56974:
	ctx->vsp=local; return(local[0]);}

/*array-vector*/
static pointer F55749(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)VECTORP(ctx,1,local+0); /*vectorp*/
	if (w==NIL) goto CON57018;
	local[0]= argv[0];
	goto CON57016;
CON57018:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ARRAYP(ctx,1,local+0); /*arrayp*/
	if (w==NIL) goto CON57026;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON57016;
CON57026:
	local[0]= fqv[29];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON57016;
CON57038:
	local[0]= NIL;
CON57016:
	w = local[0];
	local[0]= w;
BLK57006:
	ctx->vsp=local; return(local[0]);}

/*row-major-aref*/
static pointer F55751(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
BLK57046:
	ctx->vsp=local; return(local[0]);}

/*list-dimensions*/
static pointer F55753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto CON57080;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F55753(ctx,1,local+1); /*list-dimensions*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON57078;
CON57080:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON57078;
CON57101:
	local[0]= NIL;
CON57078:
	w = local[0];
	local[0]= w;
BLK57068:
	ctx->vsp=local; return(local[0]);}

/*read-array*/
static pointer F55755(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= T;
	local[2]= T;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,4,local+0); /*read*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F55753(ctx,1,local+1); /*list-dimensions*/
	local[1]= w;
	local[2]= fqv[30];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F55737(ctx,3,local+1); /*make-array*/
	local[0]= w;
BLK57112:
	ctx->vsp=local; return(local[0]);}

/*read-float-array*/
static pointer F55757(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= T;
	local[2]= T;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,4,local+0); /*read*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF57177;
	local[1]= fqv[17];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	goto IF57178;
IF57177:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F55753(ctx,1,local+1); /*list-dimensions*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= fqv[4];
	local[4]= fqv[30];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F55737(ctx,5,local+1); /*make-array*/
	local[1]= w;
IF57178:
	w = local[1];
	local[0]= w;
BLK57150:
	ctx->vsp=local; return(local[0]);}

/*read-integer-array*/
static pointer F55759(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= T;
	local[2]= T;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,4,local+0); /*read*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF57230;
	local[1]= loadglobal(fqv[19]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F55735(ctx,4,local+1); /*fill-initial-contents*/
	local[1]= w;
	goto IF57231;
IF57230:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F55753(ctx,1,local+1); /*list-dimensions*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= fqv[5];
	local[4]= fqv[30];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F55737(ctx,5,local+1); /*make-array*/
	local[1]= w;
IF57231:
	w = local[1];
	local[0]= w;
BLK57203:
	ctx->vsp=local; return(local[0]);}

/*float-vector-p*/
static pointer F55767(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[17]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK57273:
	ctx->vsp=local; return(local[0]);}

/*integer-vector-p*/
static pointer F55769(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[19]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK57289:
	ctx->vsp=local; return(local[0]);}

/*bit-vector-p*/
static pointer F55771(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK57305:
	ctx->vsp=local; return(local[0]);}

/*matrixp*/
static pointer F55773(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[20]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND57331;
	local[0]= *(ovafptr(argv[0],fqv[31]));
	ctx->vsp=local+1;
	w=(pointer)F55767(ctx,1,local+0); /*float-vector-p*/
	local[0]= w;
AND57331:
	w = local[0];
	local[0]= w;
BLK57321:
	ctx->vsp=local; return(local[0]);}

/*make-matrix*/
static pointer F55775(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT57349;}
	local[0]= NIL;
ENT57349:
ENT57348:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= fqv[4];
	local[4]= fqv[30];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F55737(ctx,5,local+1); /*make-array*/
	local[0]= w;
BLK57346:
	ctx->vsp=local; return(local[0]);}

/*matrix-row*/
static pointer F55777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F55743(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF57393;
	local[0]= *(ovafptr(argv[0],fqv[31]));
	local[1]= *(ovafptr(argv[0],fqv[32]));
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= *(ovafptr(argv[0],fqv[32]));
	local[3]= (pointer)((integer_t)(argv[1])+4);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
	goto IF57394;
IF57393:
	local[0]= NIL;
IF57394:
	w = local[0];
	local[0]= w;
BLK57380:
	ctx->vsp=local; return(local[0]);}

/*matrix-column*/
static pointer F55779(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F55743(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF57440;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= local[0];
WHL57513:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX57514;
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[2];
	local[9]= argv[1];
	local[10]= local[4];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,3,local+6); /*aset*/
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL57513;
WHX57514:
	local[6]= NIL;
BLK57515:
	w = NIL;
	w = local[3];
	local[0]= w;
	goto IF57441;
IF57440:
	local[0]= NIL;
IF57441:
	w = local[0];
	local[0]= w;
BLK57427:
	ctx->vsp=local; return(local[0]);}

/*set-matrix-row*/
static pointer F55781(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F55743(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF57576;
	local[0]= *(ovafptr(argv[0],fqv[31]));
	local[1]= argv[2];
	local[2]= fqv[33];
	local[3]= *(ovafptr(argv[0],fqv[32]));
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= fqv[34];
	local[5]= *(ovafptr(argv[0],fqv[32]));
	local[6]= (pointer)((integer_t)(argv[1])+4);
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,6,local+0,&ftab[3],fqv[35]); /*replace*/
	local[0]= w;
	goto IF57577;
IF57576:
	local[0]= NIL;
IF57577:
	w = argv[0];
	local[0]= w;
BLK57561:
	ctx->vsp=local; return(local[0]);}

/*set-matrix-column*/
static pointer F55783(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F55743(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF57634;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= local[0];
WHL57695:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX57696;
	local[5]= local[2];
	local[6]= argv[1];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL57695;
WHX57696:
	local[5]= NIL;
BLK57697:
	w = NIL;
	local[0]= w;
	goto IF57635;
IF57634:
	local[0]= NIL;
IF57635:
	w = argv[0];
	local[0]= w;
BLK57619:
	ctx->vsp=local; return(local[0]);}

/*replace-matrix*/
static pointer F55785(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[35]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK57743:
	ctx->vsp=local; return(local[0]);}

/*copy-matrix*/
static pointer F55787(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)F55775(ctx,2,local+0); /*make-matrix*/
	local[0]= w;
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,2,local+1,&ftab[3],fqv[35]); /*replace*/
	w = local[0];
	local[0]= w;
BLK57772:
	ctx->vsp=local; return(local[0]);}

/*scale-matrix*/
static pointer F55789(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT57823;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F55787(ctx,1,local+0); /*copy-matrix*/
	local[0]= w;
ENT57823:
ENT57822:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,3,local+1); /*scale*/
	w = local[0];
	local[0]= w;
BLK57820:
	ctx->vsp=local; return(local[0]);}

/*matrix*/
static pointer F55791(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST57862:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[36]);
	local[3]= (pointer)get_sym_func(fqv[37]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F55775(ctx,3,local+1); /*make-matrix*/
	local[0]= w;
BLK57860:
	ctx->vsp=local; return(local[0]);}

/*acos*/
static pointer F55793(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)SQRT(ctx,1,local+0); /*sqrt*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)ATAN(ctx,2,local+0); /*atan*/
	local[0]= w;
BLK57888:
	ctx->vsp=local; return(local[0]);}

/*asin*/
static pointer F55795(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeflt(1.00000000e+00);
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SQRT(ctx,1,local+1); /*sqrt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ATAN(ctx,2,local+0); /*atan*/
	local[0]= w;
BLK57916:
	ctx->vsp=local; return(local[0]);}

/*unit-matrix*/
static pointer F55797(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT57947;}
	local[0]= makeint(3);
ENT57947:
ENT57946:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F55775(ctx,2,local+1); /*make-matrix*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= local[0];
WHL57996:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX57997;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[2];
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,4,local+4); /*aset*/
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL57996;
WHX57997:
	local[4]= NIL;
BLK57998:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK57944:
	ctx->vsp=local; return(local[0]);}

/*m***/
static pointer F55799(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST58031:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[0];
WHL58075:
	if (local[4]==NIL) goto WHX58076;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,3,local+5); /*m**/
	goto WHL58075;
WHX58076:
	local[5]= NIL;
BLK58077:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK58029:
	ctx->vsp=local; return(local[0]);}

/*simultaneous-equation*/
static pointer F55801(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)F55747(ctx,2,local+0); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F55797(ctx,1,local+0); /*unit-matrix*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LU_DECOMPOSE(ctx,2,local+1); /*lu-decompose*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LU_SOLVE(ctx,3,local+2); /*lu-solve*/
	local[0]= w;
BLK58137:
	ctx->vsp=local; return(local[0]);}

/*inverse-matrix*/
static pointer F55803(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)F55747(ctx,2,local+0); /*array-dimension*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F55797(ctx,1,local+1); /*unit-matrix*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LU_DECOMPOSE(ctx,2,local+2); /*lu-decompose*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F55775(ctx,2,local+4); /*make-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[17]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	local[6]= makeint(0);
	if (local[2]!=NIL) goto IF58224;
	w = fqv[38];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK58176;
	goto IF58225;
IF58224:
	local[7]= NIL;
IF58225:
	local[7]= makeint(0);
	local[8]= local[0];
WHL58259:
	local[9]= local[7];
	w = local[8];
	if ((integer_t)local[9] >= (integer_t)w) goto WHX58260;
	local[9]= local[5];
	local[10]= local[7];
	local[11]= makeflt(1.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,3,local+9); /*aset*/
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)LU_SOLVE(ctx,3,local+9); /*lu-solve*/
	local[3] = w;
	local[9]= makeint(0);
	local[10]= local[0];
WHL58308:
	local[11]= local[9];
	w = local[10];
	if ((integer_t)local[11] >= (integer_t)w) goto WHX58309;
	local[11]= local[4];
	local[12]= local[9];
	local[13]= local[7];
	local[14]= local[3];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ASET(ctx,4,local+11); /*aset*/
	local[9] = (pointer)((integer_t)(local[9])+4);
	goto WHL58308;
WHX58309:
	local[11]= NIL;
BLK58310:
	w = NIL;
	local[9]= local[5];
	local[10]= local[7];
	local[11]= makeflt(0.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,3,local+9); /*aset*/
	local[7] = (pointer)((integer_t)(local[7])+4);
	goto WHL58259;
WHX58260:
	local[9]= NIL;
BLK58261:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK58176:
	ctx->vsp=local; return(local[0]);}

/*vector-x*/
static pointer F55805(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	{ register integer_t i=intval(makeint(0));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
BLK58364:
	ctx->vsp=local; return(local[0]);}

/*vector-y*/
static pointer F55807(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
BLK58383:
	ctx->vsp=local; return(local[0]);}

/*vector-z*/
static pointer F55809(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	{ register integer_t i=intval(makeint(2));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
BLK58402:
	ctx->vsp=local; return(local[0]);}

/*v=*/
static pointer F55811(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[39]); /*fzerop*/
	local[0]= w;
BLK58421:
	ctx->vsp=local; return(local[0]);}

/*euler-matrix*/
static pointer F55813(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+0); /*rotation-matrix*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[1];
	local[3]= fqv[41];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[40];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	w = local[0];
	local[0]= w;
BLK58443:
	ctx->vsp=local; return(local[0]);}

/*rpy-matrix*/
static pointer F55815(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[42];
	ctx->vsp=local+2;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+0); /*rotation-matrix*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[1];
	local[3]= fqv[41];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= local[0];
	local[2]= argv[0];
	local[3]= fqv[40];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	w = local[0];
	local[0]= w;
BLK58494:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___array(ctx,n,argv,env)
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
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF58549;
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[45],w);
	goto IF58550;
IF58549:
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF58550:
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55896,fqv[2],fqv[48],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55911,fqv[3],fqv[48],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55945,fqv[2],fqv[11],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55965,fqv[3],fqv[11],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M56015,fqv[3],fqv[20],fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F55735,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[56],module,F55737,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F55739,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F55741,fqv[60]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[61],module,F55743,fqv[62]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F55745,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F55747,fqv[66]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F55749,fqv[68]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F55751,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F55753,fqv[72]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F55755,fqv[74]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[75],module,F55757,fqv[76]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F55759,fqv[78]);
	local[0]= makeint(35);
	local[1]= makeint(65);
	local[2]= fqv[73];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(70);
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F55767,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F55769,fqv[82]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F55771,fqv[84]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[85],module,F55773,fqv[86]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[87],module,F55775,fqv[88]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F55777,fqv[90]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[91],module,F55779,fqv[92]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[93],module,F55781,fqv[94]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F55783,fqv[96]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[97],module,F55785,fqv[98]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[99],module,F55787,fqv[100]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[101],module,F55789,fqv[102]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F55791,fqv[104]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[105],module,F55793,fqv[106]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[107],module,F55795,fqv[108]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[109],module,F55797,fqv[110]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[111],module,F55799,fqv[112]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[113],module,F55801,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F55803,fqv[116]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[117],module,F55805,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F55807,fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F55809,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F55811,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F55813,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F55815,fqv[128]);
	local[0]= fqv[129];
	local[1]= fqv[130];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[131]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<6; i++) ftab[i]=fcallx;
}
