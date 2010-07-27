/* loader.c :  entry=loader */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "loader.h"
#pragma init (register_loader)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___loader();
extern pointer build_quote_vector();
static register_loader()
  { add_module_initializer("___loader", ___loader);}

static pointer F28984();
static pointer F28986();
static pointer F28988();
static pointer F28992();
static pointer F28995();
static pointer F28997();
static pointer F28999();
static pointer F29001();
static pointer F29010();
static pointer F29012();
static pointer F29014();
static pointer F29016();
static pointer F29018();
static pointer F29020();
static pointer F29022();
static pointer F29024();
static pointer F29026();
static pointer F29030();
static pointer F29032();
static pointer F29034();
static pointer F29037();
static pointer F29039();
static pointer F29041();
static pointer F29042();
static pointer F29043();

/*file-write-date*/
static pointer F28984(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(9);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*namestring*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)STAT(ctx,1,local+1); /*unix:stat*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK29090:
	ctx->vsp=local; return(local[0]);}

/*file-newer*/
static pointer F28986(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F28992(ctx,1,local+0); /*probe-file*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]!=NIL) goto OR29122;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28992(ctx,1,local+0); /*probe-file*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]!=NIL) goto OR29122;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28984(ctx,1,local+0); /*file-write-date*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F28984(ctx,1,local+1); /*file-write-date*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
OR29122:
	w = local[0];
	local[0]= w;
BLK29110:
	ctx->vsp=local; return(local[0]);}

/*open*/
static pointer F28988(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[1], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY29164;
	local[0] = fqv[2];
KEY29164:
	if (n & (1<<1)) goto KEY29171;
	local[1] = fqv[3];
KEY29171:
	if (n & (1<<2)) goto KEY29178;
	local[2] = fqv[4];
KEY29178:
	if (n & (1<<3)) goto KEY29185;
	local[3] = makeint(420);
KEY29185:
	if (n & (1<<4)) goto KEY29190;
	local[4] = makeint(512);
KEY29190:
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)STREAMP(ctx,1,local+8); /*streamp*/
	if (w==NIL) goto IF29215;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,1,local+8,&ftab[1],fqv[5]); /*io-stream-p*/
	if (w==NIL) goto IF29223;
	local[7] = *(ovafptr(*(ovafptr(argv[0],fqv[6])),fqv[7]));
	local[8]= local[7];
	goto IF29224;
IF29223:
	local[7] = *(ovafptr(argv[0],fqv[7]));
	local[8]= local[7];
IF29224:
	goto IF29216;
IF29215:
	local[7] = argv[0];
	local[8]= local[7];
IF29216:
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,1,local+8,&ftab[0],fqv[0]); /*namestring*/
	local[7] = w;
	local[8]= local[0];
	local[9]= local[8];
	if (fqv[2]!=local[9]) goto IF29276;
	local[5] = makeint(0);
	local[9]= local[2];
	if (fqv[4]!=local[9]) goto IF29293;
	local[2] = fqv[8];
	local[9]= local[2];
	goto IF29294;
IF29293:
	local[9]= NIL;
IF29294:
	local[9]= local[2];
	if (fqv[9]!=local[9]) goto IF29309;
	local[9]= local[5];
	local[10]= makeint(64);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[5] = w;
	local[9]= local[5];
	goto IF29310;
IF29309:
	local[9]= NIL;
IF29310:
	local[9]= local[7];
	local[10]= local[5];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[10]); /*system:openfile*/
	local[6] = w;
	local[9]= local[6];
	goto IF29277;
IF29276:
	local[9]= local[8];
	w = fqv[11];
	if (memq(local[9],w)==NIL) goto IF29341;
	local[9]= local[0];
	if (fqv[12]!=local[9]) goto IF29355;
	local[5] = makeint(2);
	local[9]= local[5];
	goto IF29356;
IF29355:
	local[5] = makeint(1);
	local[9]= local[5];
IF29356:
	local[9]= local[1];
	local[10]= local[9];
	if (fqv[13]!=local[10]) goto IF29387;
	local[10]= local[5];
	local[11]= makeint(1024);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29388;
IF29387:
	local[10]= local[9];
	w = fqv[14];
	if (memq(local[10],w)==NIL) goto IF29406;
	local[10]= local[5];
	local[11]= makeint(64);
	local[12]= makeint(512);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,3,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29407;
IF29406:
	local[10]= local[9];
	if (fqv[15]!=local[10]) goto IF29427;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29428;
IF29427:
	local[10]= local[9];
	w = fqv[16];
	if (memq(local[10],w)==NIL) goto IF29446;
	local[10]= local[5];
	local[11]= makeint(64);
	local[12]= makeint(128);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,3,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29447;
IF29446:
	if (T==NIL) goto IF29467;
	local[10]= fqv[17];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF29468;
IF29467:
	local[10]= NIL;
IF29468:
IF29447:
IF29428:
IF29407:
IF29388:
	w = local[10];
	local[9]= local[2];
	local[10]= local[9];
	if (fqv[8]!=local[10]) goto IF29489;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)LOGNOT(ctx,1,local+11); /*lognot*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LOGAND(ctx,2,local+10); /*logand*/
	local[5] = w;
	local[10]= local[5];
	goto IF29490;
IF29489:
	local[10]= local[9];
	if (fqv[9]!=local[10]) goto IF29509;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)LOGIOR(ctx,2,local+10); /*logior*/
	local[5] = w;
	local[10]= local[5];
	goto IF29510;
IF29509:
	local[10]= local[9];
	if (fqv[4]!=local[10]) goto IF29527;
	local[10]= local[1];
	w = fqv[18];
	if (memq(local[10],w)!=NIL) goto IF29535;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)LOGIOR(ctx,2,local+10); /*logior*/
	local[5] = w;
	local[10]= local[5];
	goto IF29536;
IF29535:
	local[10]= NIL;
IF29536:
	goto IF29528;
IF29527:
	local[10]= local[9];
	if (fqv[19]!=local[10]) goto IF29556;
	local[10]= NIL;
	goto IF29557;
IF29556:
	if (T==NIL) goto IF29564;
	local[10]= fqv[20];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF29565;
IF29564:
	local[10]= NIL;
IF29565:
IF29557:
IF29528:
IF29510:
IF29490:
	w = local[10];
	local[9]= local[7];
	local[10]= local[5];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[10]); /*system:openfile*/
	local[6] = w;
	local[9]= local[6];
	goto IF29342;
IF29341:
	if (T==NIL) goto IF29584;
	local[9]= fqv[21];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF29585;
IF29584:
	local[9]= NIL;
IF29585:
IF29342:
IF29277:
	w = local[9];
	w = local[6];
	if (!isnum(w)) goto IF29594;
	if (local[2]!=NIL) goto IF29603;
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK29151;
	goto IF29604;
IF29603:
	local[8]= loadglobal(fqv[22]);
	local[9]= fqv[23];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
IF29604:
	goto IF29595;
IF29594:
	local[8]= NIL;
IF29595:
	w = local[6];
	local[0]= w;
BLK29151:
	ctx->vsp=local; return(local[0]);}

/*with-open-file*/
static pointer F29626(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST29629:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[24];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[25];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[26];
	local[4]= fqv[27];
	local[5]= local[0];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK29627:
	ctx->vsp=local; return(local[0]);}

/*probe-file*/
static pointer F28992(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)STAT(ctx,1,local+1); /*unix:stat*/
	local[1]= w;
	w = local[1];
	if (!iscons(w)) goto IF29727;
	local[2]= makeint(61440);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	local[3]= local[2];
	if (fqv[29]!=local[3]) goto IF29755;
	local[3]= fqv[30];
	goto IF29756;
IF29755:
	local[3]= local[2];
	if (fqv[31]!=local[3]) goto IF29765;
	local[3]= fqv[32];
	goto IF29766;
IF29765:
	local[3]= local[2];
	if (fqv[33]!=local[3]) goto IF29775;
	local[3]= fqv[34];
	goto IF29776;
IF29775:
	local[3]= local[2];
	if (fqv[35]!=local[3]) goto IF29785;
	local[3]= fqv[36];
	goto IF29786;
IF29785:
	local[3]= local[2];
	if (fqv[37]!=local[3]) goto IF29795;
	local[3]= fqv[38];
	goto IF29796;
IF29795:
	local[3]= local[2];
	if (fqv[39]!=local[3]) goto IF29805;
	local[3]= fqv[40];
	goto IF29806;
IF29805:
	local[3]= local[2];
	if (fqv[41]!=local[3]) goto IF29815;
	local[3]= fqv[42];
	goto IF29816;
IF29815:
	local[3]= NIL;
IF29816:
IF29806:
IF29796:
IF29786:
IF29776:
IF29766:
IF29756:
	w = local[3];
	local[2]= w;
	goto IF29728;
IF29727:
	local[2]= NIL;
IF29728:
	w = local[2];
	local[0]= w;
BLK29701:
	ctx->vsp=local; return(local[0]);}

/*object-file-p*/
static pointer F28995(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET29843,env,argv,local);
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET29843(ctx,1,local+1,w);
	local[1]= w;
	local[2]= loadglobal(fqv[43]);
	local[3]= local[1];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeint(1);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= T;
	local[8]= NIL;
TAG29940:
	if (local[2]==NIL) goto OR29947;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)GREQP(ctx,2,local+9); /*>=*/
	if (w!=NIL) goto OR29947;
	if (local[8]!=NIL) goto OR29947;
	goto IF29945;
OR29947:
	w = local[7];
	ctx->vsp=local+9;
	local[3]=w;
	goto BLK29869;
	goto IF29946;
IF29945:
	local[9]= NIL;
IF29946:
	if (local[6]==NIL) goto IF29969;
	local[9]= local[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)EQ(ctx,2,local+9); /*eql*/
	if (w!=NIL) goto IF29969;
	local[7] = NIL;
	local[8] = T;
	local[9]= local[8];
	goto IF29970;
IF29969:
	local[9]= NIL;
IF29970:
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= (pointer)((integer_t)(local[4])+4);
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	local[3] = local[9];
	local[4] = local[10];
	local[6] = local[11];
	w = NIL;
	ctx->vsp=local+9;
	goto TAG29940;
	w = NIL;
	local[3]= w;
BLK29869:
	w = local[3];
	local[0]= w;
BLK29831:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET29843(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(4);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[44]); /*make-string*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F28988(ctx,1,local+1); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP30113,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1]->c.obj.iv[5];
	local[5]= local[0];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,3,local+4); /*unix:uread*/
	ctx->vsp=local+4;
	UWP30113(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP30113(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*path-list*/
static pointer F28997(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT30150;}
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT30150:
ENT30149:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
WHL30180:
	local[5]= makeint(58);
	local[6]= local[0];
	local[7]= fqv[46];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,4,local+5,&ftab[4],fqv[47]); /*position*/
	local[3] = w;
	if (local[3]==NIL) goto WHX30181;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[4] = w;
	local[5]= loadglobal(fqv[22]);
	local[6]= local[4];
	local[7]= fqv[48];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[2] = (pointer)((integer_t)(local[3])+4);
	goto WHL30180;
WHX30181:
	local[5]= NIL;
BLK30182:
	local[5]= loadglobal(fqv[22]);
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	local[7]= fqv[49];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
BLK30147:
	ctx->vsp=local; return(local[0]);}

/*find-executable*/
static pointer F28999(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28992(ctx,1,local+0); /*probe-file*/
	if (w==NIL) goto IF30269;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[50]); /*truename*/
	local[0]= w;
	goto IF30270;
IF30269:
	ctx->vsp=local+0;
	w=(pointer)F28997(ctx,0,local+0); /*path-list*/
	local[0]= w;
	local[1]= NIL;
WHL30293:
	if (local[0]==NIL) goto WHX30294;
	local[2]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*namestring*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F28992(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto IF30346;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[50]); /*truename*/
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK30259;
	goto IF30347;
IF30346:
	local[2]= NIL;
IF30347:
	goto WHL30293;
WHX30294:
	local[2]= NIL;
BLK30295:
	w = NIL;
	local[0]= w;
IF30270:
	w = local[0];
	local[0]= w;
BLK30259:
	ctx->vsp=local; return(local[0]);}

/*system::txtload*/
static pointer F29001(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT30369;}
	local[0]= NIL;
ENT30369:
ENT30368:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F28988(ctx,1,local+4); /*open*/
	local[4]= w;
	ctx->vsp=local+5;
	w = makeclosure(codevec,quotevec,UWP30413,env,argv,local);
	local[5]=(pointer)(ctx->protfp); local[6]=w;
	ctx->protfp=(struct protectframe *)(local+5);
WHL30420:
	local[7]= local[4];
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[2] = w;
	local[7]= local[2];
	if (local[1]==local[7]) goto WHX30421;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)EVAL(ctx,1,local+7); /*eval*/
	local[3] = w;
	if (local[0]==NIL) goto IF30446;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PRINT(ctx,1,local+7); /*print*/
	local[7]= w;
	goto IF30447;
IF30446:
	local[7]= NIL;
IF30447:
	goto WHL30420;
WHX30421:
	local[7]= NIL;
BLK30422:
	w = local[7];
	ctx->vsp=local+7;
	UWP30413(ctx,0,local+7,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK30366:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP30413(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[4];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-module-file-name*/
static pointer F29010(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[52]); /*pathname-name*/
	local[0]= w;
BLK30483:
	ctx->vsp=local; return(local[0]);}

/*load*/
static pointer F29012(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[53], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY30519;
	local[0] = NIL;
KEY30519:
	if (n & (1<<1)) goto KEY30524;
	local[8]= loadglobal(fqv[22]);
	local[9]= fqv[54];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,1,local+10,&ftab[7],fqv[52]); /*pathname-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[1] = w;
KEY30524:
	if (n & (1<<2)) goto KEY30535;
	local[2] = NIL;
KEY30535:
	if (n & (1<<3)) goto KEY30540;
	local[3] = fqv[55];
KEY30540:
	if (n & (1<<4)) goto KEY30545;
	local[4] = fqv[56];
KEY30545:
	if (n & (1<<5)) goto KEY30550;
	local[5] = loadglobal(fqv[57]);
KEY30550:
	if (n & (1<<6)) goto KEY30557;
	local[6] = NIL;
KEY30557:
	if (n & (1<<7)) goto KEY30562;
	local[7] = loadglobal(fqv[58]);
KEY30562:
	local[8]= loadglobal(fqv[58]);
	w = local[8];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[58],w);
	local[11]= NIL;
	local[12]= NIL;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,FLET30589,env,argv,local);
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,FLET30591,env,argv,local);
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,FLET30593,env,argv,local);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[8])(ctx,1,local+16,&ftab[8],fqv[59]); /*pathname*/
	argv[0] = w;
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	local[16]= w;
	storeglobal(fqv[58],w);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[9])(ctx,1,local+16,&ftab[9],fqv[60]); /*pathname-directory*/
	if (w==NIL) goto IF30615;
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[9])(ctx,1,local+16,&ftab[9],fqv[60]); /*pathname-directory*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[61];
	ctx->vsp=local+18;
	w=(pointer)EQ(ctx,2,local+16); /*eql*/
	if (w==NIL) goto IF30615;
	local[16]= argv[0];
	w = local[15];
	ctx->vsp=local+17;
	w=FLET30593(ctx,1,local+16,w);
	local[12] = w;
	if (local[12]!=NIL) goto IF30638;
	local[16]= fqv[62];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,2,local+16); /*error*/
	local[16]= w;
	goto IF30639;
IF30638:
	local[16]= local[12];
IF30639:
	goto IF30616;
IF30615:
	local[16]= NIL;
	local[17]= loadglobal(fqv[63]);
	local[18]= loadglobal(fqv[64]);
	local[19]= fqv[65];
	local[20]= (pointer)get_sym_func(fqv[66]);
	ctx->vsp=local+21;
	w=(*ftab[10])(ctx,4,local+17,&ftab[10],fqv[67]); /*union*/
	local[17]= w;
WHL30687:
	if (local[17]==NIL) goto WHX30688;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= argv[0];
	ctx->vsp=local+20;
	w=(*ftab[11])(ctx,2,local+18,&ftab[11],fqv[68]); /*concatenate-pathnames*/
	local[11] = w;
	local[18]= local[11];
	w = local[15];
	ctx->vsp=local+19;
	w=FLET30593(ctx,1,local+18,w);
	local[12] = w;
	if (local[12]==NIL) goto IF30758;
	w = local[12];
	ctx->vsp=local+18;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK30503;
	goto IF30759;
IF30758:
	local[18]= NIL;
IF30759:
	goto WHL30687;
WHX30688:
	local[18]= NIL;
BLK30689:
	w = NIL;
	local[16]= fqv[69];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,2,local+16); /*error*/
	local[16]= w;
IF30616:
	w = local[16];
	local[13]= w;
	ctx->vsp=local+14;
	unbindx(ctx,1);
	w = local[13];
	local[0]= w;
BLK30503:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30589(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (env->c.clo.env2[5]==NIL) goto IF30788;
	local[0]= T;
	local[1]= fqv[70];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[0]); /*namestring*/
	local[3]= w;
	local[4]= loadglobal(fqv[58]);
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
	goto IF30789;
IF30788:
	local[0]= NIL;
IF30789:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30591(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[71]); /*directory-namestring*/
	local[0]= w;
	w = loadglobal(fqv[63]);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= NIL;
	w = local[0];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[63],w);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[0]); /*namestring*/
	argv[0] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F28995(ctx,1,local+6); /*object-file-p*/
	if (w==NIL) goto CON30850;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[52]); /*pathname-name*/
	local[6]= w;
	local[7]= loadglobal(fqv[72]);
	local[8]= fqv[73];
	local[9]= (pointer)get_sym_func(fqv[74]);
	local[10]= fqv[65];
	local[11]= (pointer)get_sym_func(fqv[75]);
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,6,local+6,&ftab[13],fqv[76]); /*find*/
	local[1] = w;
	if (local[1]==NIL) goto IF30859;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,1,local+6,&ftab[14],fqv[77]); /*system::unbinload*/
	local[6]= T;
	local[7]= fqv[78];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF30860;
IF30859:
	local[6]= NIL;
IF30860:
	local[6]= fqv[79];
	local[7]= argv[0];
	w = env->c.clo.env2[13];
	ctx->vsp=local+8;
	w=FLET30589(ctx,2,local+6,w);
	local[6]= argv[0];
	local[7]= env->c.clo.env2[1];
	ctx->vsp=local+8;
	w=(pointer)BINLOAD(ctx,2,local+6); /*system:binload*/
	local[2] = w;
	if (local[2]==NIL) goto IF30915;
	local[6]= local[2];
	w = loadglobal(fqv[72]);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	storeglobal(fqv[72],local[6]);
	goto IF30916;
IF30915:
	local[6]= NIL;
IF30916:
	local[6]= local[2];
	goto CON30848;
CON30850:
	local[6]= fqv[80];
	local[7]= argv[0];
	w = env->c.clo.env2[13];
	ctx->vsp=local+8;
	w=FLET30589(ctx,2,local+6,w);
	local[6]= argv[0];
	local[7]= env->c.clo.env2[6];
	ctx->vsp=local+8;
	w=(pointer)F29001(ctx,2,local+6); /*system::txtload*/
	local[6]= T;
	goto CON30848;
CON30935:
	local[6]= NIL;
CON30848:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30593(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F28992(ctx,1,local+2); /*probe-file*/
	local[2]= w;
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON30977;
	local[2]= argv[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30591(ctx,1,local+2,w);
	local[2]= w;
	goto CON30975;
CON30977:
	local[2]= fqv[83];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F28992(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON30994;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30591(ctx,1,local+2,w);
	local[2]= w;
	goto CON30975;
CON30994:
	local[2]= fqv[84];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F28992(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31013;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30591(ctx,1,local+2,w);
	local[2]= w;
	goto CON30975;
CON31013:
	local[2]= fqv[85];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F28992(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31032;
	local[2]= local[1];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30591(ctx,1,local+2,w);
	local[2]= w;
	goto CON30975;
CON31032:
	local[2]= NIL;
CON30975:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-files*/
static pointer F29014(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST31057:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= local[0];
WHL31083:
	if (local[2]==NIL) goto WHX31084;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[86];
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)F29012(ctx,3,local+3); /*load*/
	goto WHL31083;
WHX31084:
	local[3]= NIL;
BLK31085:
	w = NIL;
	w = T;
	local[0]= w;
BLK31055:
	ctx->vsp=local; return(local[0]);}

/*read-file*/
static pointer F29016(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28988(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31168,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	ctx->vsp=local+3;
	UWP31168(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31144:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31168(ctx,n,argv,env)
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

/*read-strings*/
static pointer F29018(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28988(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31217,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
WHL31242:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31243;
	local[6]= local[3];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	local[6]= fqv[87];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	goto WHL31242;
WHX31243:
	local[6]= NIL;
BLK31244:
	local[6]= (pointer)get_sym_func(fqv[88]);
	local[7]= loadglobal(fqv[22]);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	ctx->vsp=local+3;
	UWP31217(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31193:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31217(ctx,n,argv,env)
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

/*read-lines*/
static pointer F29020(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28988(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31332,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
WHL31357:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31358;
	local[6]= local[3];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	goto WHL31357;
WHX31358:
	local[6]= NIL;
BLK31359:
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	ctx->vsp=local+3;
	UWP31332(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31308:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31332(ctx,n,argv,env)
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

/*read-lists*/
static pointer F29022(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F28988(ctx,1,local+3); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP31450,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
WHL31457:
	local[6]= local[3];
	local[7]= NIL;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[1] = w;
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31458;
	local[6]= local[1];
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	goto WHL31457;
WHX31458:
	local[6]= NIL;
BLK31459:
	w = local[6];
	ctx->vsp=local+6;
	UWP31450(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK31407:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31450(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-binary-file*/
static pointer F29024(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F29037(ctx,1,local+0); /*file-size*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[44]); /*make-string*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F28988(ctx,1,local+3); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP31551,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[3];
	local[7]= fqv[89];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)UNIXREAD(ctx,3,local+6); /*unix:uread*/
	local[1] = w;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,2,local+6,&ftab[16],fqv[90]); /*/=*/
	if (w==NIL) goto IF31573;
	local[6]= fqv[91];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF31574;
IF31573:
	local[6]= NIL;
IF31574:
	w = local[6];
	ctx->vsp=local+6;
	UWP31551(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[2];
	local[0]= w;
BLK31507:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31551(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lines-till-eof*/
static pointer F29026(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w = NIL;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
WHL31633:
	local[3]= argv[0];
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)READLINE(ctx,3,local+3); /*read-line*/
	local[1] = w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto WHX31634;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL31633;
WHX31634:
	local[3]= NIL;
BLK31635:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK31604:
	ctx->vsp=local; return(local[0]);}

/*do-file-line*/
static pointer F31670(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST31673:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[92],w);
	local[6]= fqv[93];
	local[7]= loadglobal(fqv[92]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[24];
	local[9]= local[2];
	local[10]= fqv[94];
	local[11]= fqv[19];
	local[12]= fqv[19];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[95];
	local[11]= fqv[96];
	local[12]= fqv[97];
	local[13]= local[2];
	local[14]= fqv[98];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[99];
	local[17]= loadglobal(fqv[92]);
	local[18]= fqv[19];
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK31671:
	ctx->vsp=local; return(local[0]);}

/*do-file-form*/
static pointer F31818(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST31821:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[92],w);
	local[6]= fqv[93];
	local[7]= loadglobal(fqv[92]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[24];
	local[9]= local[2];
	local[10]= fqv[94];
	local[11]= fqv[19];
	local[12]= fqv[19];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[95];
	local[11]= fqv[96];
	local[12]= fqv[97];
	local[13]= local[2];
	local[14]= fqv[98];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[100];
	local[17]= loadglobal(fqv[92]);
	local[18]= fqv[19];
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK31819:
	ctx->vsp=local; return(local[0]);}

/*load-library*/
static pointer F29030(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST31968:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[101]);
	local[2]= argv[0];
	local[3]= fqv[102];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,2,local+2,&ftab[17],fqv[103]); /*system::list-module-initializers*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[2];
WHL32023:
	if (local[5]==NIL) goto WHX32024;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= T;
	local[7]= fqv[104];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= loadglobal(fqv[105]);
	ctx->vsp=local+7;
	w=(pointer)FINOUT(ctx,1,local+6); /*finish-output*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	goto WHL32023;
WHX32024:
	local[6]= NIL;
BLK32025:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0]= w;
BLK31966:
	ctx->vsp=local; return(local[0]);}

/*dump-object*/
static pointer F29032(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32129:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= T;
	local[2]= T;
	local[3]= NIL;
	local[4]= NIL;
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[106],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[107],w);
	w = local[2];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[108],w);
	w = local[1];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[109],w);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)STREAMP(ctx,1,local+17); /*streamp*/
	if (w==NIL) goto IF32171;
	local[17]= NIL;
	local[18]= local[0];
WHL32196:
	if (local[18]==NIL) goto WHX32197;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= argv[0];
	ctx->vsp=local+21;
	w=(pointer)PRINT(ctx,2,local+19); /*print*/
	goto WHL32196;
WHX32197:
	local[19]= NIL;
BLK32198:
	w = NIL;
	local[17]= w;
	goto IF32172;
IF32171:
	local[17]= argv[0];
	local[18]= fqv[110];
	local[19]= fqv[111];
	ctx->vsp=local+20;
	w=(pointer)F28988(ctx,3,local+17); /*open*/
	local[17]= w;
	ctx->vsp=local+18;
	w = makeclosure(codevec,quotevec,UWP32270,env,argv,local);
	local[18]=(pointer)(ctx->protfp); local[19]=w;
	ctx->protfp=(struct protectframe *)(local+18);
	local[20]= NIL;
	local[21]= local[0];
WHL32294:
	if (local[21]==NIL) goto WHX32295;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PRINT(ctx,2,local+22); /*print*/
	goto WHL32294;
WHX32295:
	local[22]= NIL;
BLK32296:
	w = NIL;
	ctx->vsp=local+20;
	UWP32270(ctx,0,local+20,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[17]= w;
IF32172:
	ctx->vsp=local+18;
	unbindx(ctx,4);
	w = local[17];
	local[0]= w;
BLK32127:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP32270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[17];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*dump-structure*/
static pointer F29034(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32368:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= T;
	local[2]= T;
	local[3]= NIL;
	local[4]= NIL;
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[106],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[107],w);
	w = local[2];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[108],w);
	w = local[1];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[112],w);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)STREAMP(ctx,1,local+17); /*streamp*/
	if (w==NIL) goto IF32410;
	local[17]= NIL;
	local[18]= local[0];
WHL32435:
	if (local[18]==NIL) goto WHX32436;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= argv[0];
	ctx->vsp=local+21;
	w=(pointer)PRINT(ctx,2,local+19); /*print*/
	goto WHL32435;
WHX32436:
	local[19]= NIL;
BLK32437:
	w = NIL;
	local[17]= w;
	goto IF32411;
IF32410:
	local[17]= argv[0];
	local[18]= fqv[110];
	local[19]= fqv[111];
	ctx->vsp=local+20;
	w=(pointer)F28988(ctx,3,local+17); /*open*/
	local[17]= w;
	ctx->vsp=local+18;
	w = makeclosure(codevec,quotevec,UWP32509,env,argv,local);
	local[18]=(pointer)(ctx->protfp); local[19]=w;
	ctx->protfp=(struct protectframe *)(local+18);
	local[20]= NIL;
	local[21]= local[0];
WHL32533:
	if (local[21]==NIL) goto WHX32534;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PRINT(ctx,2,local+22); /*print*/
	goto WHL32533;
WHX32534:
	local[22]= NIL;
BLK32535:
	w = NIL;
	ctx->vsp=local+20;
	UWP32509(ctx,0,local+20,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[17]= w;
IF32411:
	ctx->vsp=local+18;
	unbindx(ctx,4);
	w = local[17];
	local[0]= w;
BLK32366:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP32509(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[17];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*dump-loadable-structure*/
static pointer F32605(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32608:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL32646:
	if (local[3]==NIL) goto WHX32647;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[113];
	local[5]= fqv[98];
	local[6]= local[2];
	local[7]= fqv[113];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SYMVALUE(ctx,1,local+8); /*symbol-value*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,3,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL32646;
WHX32647:
	local[4]= NIL;
BLK32648:
	w = NIL;
	local[2]= fqv[114];
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK32606:
	ctx->vsp=local; return(local[0]);}

/*file-size*/
static pointer F29037(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	argv[0] = w;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28992(ctx,1,local+0); /*probe-file*/
	if (w==NIL) goto IF32759;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)STAT(ctx,1,local+0); /*unix:stat*/
	local[0]= w;
	local[1]= makeint(7);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	goto IF32760;
IF32759:
	local[0]= fqv[115];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
IF32760:
	w = local[0];
	local[0]= w;
BLK32740:
	ctx->vsp=local; return(local[0]);}

/*directory-p*/
static pointer F29039(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)STAT(ctx,1,local+2); /*unix:stat*/
	local[1] = w;
	w = local[1];
	if (!iscons(w)) goto IF32793;
	local[2]= makeint(16384);
	local[3]= local[1];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	local[3]= makeint(16384);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	local[2]= w;
	goto IF32794;
IF32793:
	local[2]= NIL;
IF32794:
	w = local[2];
	local[0]= w;
BLK32779:
	ctx->vsp=local; return(local[0]);}

/*map-file*/
static pointer F29041(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[116], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY32833;
	local[0] = fqv[2];
KEY32833:
	if (n & (1<<1)) goto KEY32840;
	local[1] = makeint(0);
KEY32840:
	if (n & (1<<2)) goto KEY32845;
	local[2] = NIL;
KEY32845:
	if (n & (1<<3)) goto KEY32850;
	local[3] = NIL;
KEY32850:
	if (n & (1<<4)) goto KEY32855;
	local[4] = T;
KEY32855:
	if (n & (1<<5)) goto KEY32860;
	local[5] = NIL;
KEY32860:
	if (n & (1<<6)) goto KEY32865;
	local[6] = makeint(0);
KEY32865:
	local[7]= NIL;
	local[8]= makeint(0);
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= fqv[110];
	local[12]= local[0];
	local[13]= fqv[117];
	local[14]= fqv[13];
	ctx->vsp=local+15;
	w=(pointer)F28988(ctx,5,local+10); /*open*/
	local[7] = w;
	if (local[2]!=NIL) goto IF32903;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)F29037(ctx,1,local+10); /*file-size*/
	local[2] = w;
	local[10]= local[2];
	goto IF32904;
IF32903:
	local[10]= NIL;
IF32904:
	if (local[3]!=NIL) goto IF32922;
	local[10]= local[0];
	local[11]= fqv[118];
	ctx->vsp=local+12;
	w=(pointer)ASSQ(ctx,2,local+10); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[10]= local[3];
	goto IF32923;
IF32922:
	local[10]= NIL;
IF32923:
	if (local[4]==NIL) goto IF32946;
	local[8] = makeint(1);
	local[10]= local[8];
	goto IF32947;
IF32946:
	local[10]= NIL;
IF32947:
	if (local[5]==NIL) goto IF32958;
	local[8] = makeint(2);
	local[10]= local[8];
	goto IF32959;
IF32958:
	local[10]= NIL;
IF32959:
	local[10]= local[6];
	local[11]= local[2];
	local[12]= local[3];
	local[13]= local[8];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[18])(ctx,6,local+10,&ftab[18],fqv[119]); /*unix:mmap*/
	local[9] = w;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)CLOSE(ctx,1,local+10); /*close*/
	w = local[9];
	local[0]= w;
BLK32818:
	ctx->vsp=local; return(local[0]);}

/*provide*/
static pointer F29042(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32996:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,1,local+1,&ftab[19],fqv[120]); /*keywordp*/
	if (w!=NIL) goto IF33008;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[121]); /*string-upcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[122]);
	ctx->vsp=local+3;
	w=(pointer)INTERN(ctx,2,local+1); /*intern*/
	argv[0] = w;
	local[1]= argv[0];
	goto IF33009;
IF33008:
	local[1]= NIL;
IF33009:
	local[1]= argv[0];
	local[2]= loadglobal(fqv[123]);
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[124]); /*assoc*/
	if (w!=NIL) goto IF33038;
	local[1]= loadglobal(fqv[123]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST_STAR(ctx,2,local+2); /*list**/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	local[1]= w;
	storeglobal(fqv[123],w);
	goto IF33039;
IF33038:
	local[1]= NIL;
IF33039:
	w = argv[0];
	local[0]= w;
BLK32994:
	ctx->vsp=local; return(local[0]);}

/*require*/
static pointer F29043(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST33071:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,1,local+1,&ftab[19],fqv[120]); /*keywordp*/
	if (w!=NIL) goto IF33083;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[121]); /*string-upcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[122]);
	ctx->vsp=local+3;
	w=(pointer)INTERN(ctx,2,local+1); /*intern*/
	argv[0] = w;
	local[1]= argv[0];
	goto IF33084;
IF33083:
	local[1]= NIL;
IF33084:
	local[1]= argv[0];
	local[2]= loadglobal(fqv[123]);
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[124]); /*assoc*/
	if (w!=NIL) goto IF33110;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (isstring(w)) goto IF33123;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,1,local+1,&ftab[23],fqv[125]); /*string-downcase*/
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	local[1]= local[0];
	goto IF33124;
IF33123:
	local[1]= NIL;
IF33124:
	local[1]= (pointer)get_sym_func(fqv[101]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F29042(ctx,1,local+1); /*provide*/
	local[1]= w;
	goto IF33111;
IF33110:
	local[1]= NIL;
IF33111:
	w = local[1];
	local[0]= w;
BLK33069:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___loader(ctx,n,argv,env)
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
	if (w==NIL) goto IF33171;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[58],w);
	goto IF33172;
IF33171:
	local[0]= fqv[129];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF33172:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F28984,fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F28986,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F28988,fqv[135]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[93],module,F29626,fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F28992,fqv[138]);
	local[0]= fqv[43];
	local[1]= fqv[139];
	local[2]= fqv[140];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33211;
	local[2]= makeint(7);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33211:
	local[2]= fqv[142];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33223;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33223:
	local[2]= fqv[143];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33234;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33234:
	local[2]= fqv[144];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33245;
	local[2]= makeint(98);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33245:
	local[2]= fqv[145];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33256;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33256:
	local[2]= fqv[146];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33267;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33267:
	local[2]= fqv[147];
	local[3]= loadglobal(fqv[141]);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[82]); /*member*/
	if (w==NIL) goto CON33278;
	local[2]= makeint(131);
	local[3]= makeint(1);
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33278:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint(1);
	local[5]= fqv[148];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33209;
CON33289:
	local[2]= NIL;
CON33209:
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F28995,fqv[150]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F28997,fqv[152]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F28999,fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F29001,fqv[156]);
	local[0]= fqv[64];
	local[1]= fqv[157];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33308;
	local[0]= fqv[64];
	local[1]= fqv[157];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33331;
	local[0]= fqv[64];
	local[1]= fqv[158];
	local[2]= fqv[159];
	local[3]= loadglobal(fqv[160]);
	local[4]= NIL;
	local[5]= fqv[161];
	local[6]= loadglobal(fqv[160]);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	local[5]= NIL;
	local[6]= fqv[162];
	local[7]= loadglobal(fqv[160]);
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	local[6]= NIL;
	local[7]= fqv[163];
	local[8]= loadglobal(fqv[160]);
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,5,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33332;
IF33331:
	local[0]= NIL;
IF33332:
	local[0]= fqv[64];
	goto IF33309;
IF33308:
	local[0]= NIL;
IF33309:
	local[0]= fqv[63];
	local[1]= fqv[164];
	local[2]= fqv[165];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[57];
	local[1]= fqv[157];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33374;
	local[0]= fqv[57];
	local[1]= fqv[157];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33397;
	local[0]= fqv[57];
	local[1]= fqv[158];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33398;
IF33397:
	local[0]= NIL;
IF33398:
	local[0]= fqv[57];
	goto IF33375;
IF33374:
	local[0]= NIL;
IF33375:
	local[0]= fqv[72];
	local[1]= fqv[157];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33417;
	local[0]= fqv[72];
	local[1]= fqv[157];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33440;
	local[0]= fqv[72];
	local[1]= fqv[158];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33441;
IF33440:
	local[0]= NIL;
IF33441:
	local[0]= fqv[72];
	goto IF33418;
IF33417:
	local[0]= NIL;
IF33418:
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F29010,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[101],module,F29012,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F29014,fqv[169]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[170],module,F29016,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F29018,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F29020,fqv[175]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[176],module,F29022,fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F29024,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F29026,fqv[181]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[182],module,F31670,fqv[183]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[184],module,F31818,fqv[185]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F29030,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F29032,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F29034,fqv[190]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[191],module,F32605,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F29037,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F29039,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F29041,fqv[198]);
	local[0]= fqv[123];
	local[1]= fqv[157];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33496;
	local[0]= fqv[123];
	local[1]= fqv[157];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[123];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33519;
	local[0]= fqv[123];
	local[1]= fqv[158];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33520;
IF33519:
	local[0]= NIL;
IF33520:
	local[0]= fqv[123];
	goto IF33497;
IF33496:
	local[0]= NIL;
IF33497:
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F29042,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F29043,fqv[202]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<24; i++) ftab[i]=fcallx;
}
