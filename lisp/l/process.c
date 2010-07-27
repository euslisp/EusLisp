/* process.c :  entry=process */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "process.h"
#pragma init (register_process)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___process();
extern pointer build_quote_vector();
static register_process()
  { add_module_initializer("___process", ___process);}

static pointer F43258();
static pointer F43260();
static pointer F43262();
static pointer F43264();
static pointer F43266();
static pointer F43269();
static pointer F43271();
static pointer F43273();

/*cd*/
static pointer F43303(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT43307;}
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT43307:
ENT43306:
	if (n>1) maerror();
	w = local[0];
	if (!issymbol(w)) goto IF43321;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[1]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[2]); /*string-downcase*/
	local[0] = w;
	local[1]= local[0];
	goto IF43322;
IF43321:
	local[1]= NIL;
IF43322:
	local[1]= fqv[3];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK43304:
	ctx->vsp=local; return(local[0]);}

/*pwd*/
static pointer F43258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)GETWD(ctx,0,local+0); /*unix:getwd*/
	local[0]= w;
BLK43350:
	ctx->vsp=local; return(local[0]);}

/*ez*/
static pointer F43260(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT43365;}
	local[0]= fqv[4];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[5]); /*read-from-string*/
	local[0]= w;
ENT43365:
ENT43364:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint(327680);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MSGGET(ctx,1,local+1); /*unix:msgget*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(393216);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MSGGET(ctx,1,local+2); /*unix:msgget*/
	local[2]= w;
	local[3]= loadglobal(fqv[1]);
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[1];
	local[7]= fqv[6];
	local[8]= makeint(0);
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)MSGSND(ctx,4,local+6); /*unix:msgsnd*/
WHL43426:
	local[6]= local[2];
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)MSGRCV(ctx,3,local+6); /*unix:msgrcv*/
	local[5] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= makeint(99);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto WHX43427;
	local[6]= local[4];
	local[7]= local[3];
	local[8]= makeint(0);
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[4] = w;
	goto WHL43426;
WHX43427:
	local[6]= NIL;
BLK43428:
	if (local[4]!=NIL) goto IF43469;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK43362;
	goto IF43470;
IF43469:
	local[6]= NIL;
IF43470:
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[1]);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[8]); /*make-string-input-stream*/
	local[4] = w;
WHL43494:
	local[6]= local[4];
	local[7]= NIL;
	local[8]= fqv[9];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[5] = w;
	local[6]= local[5];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto WHX43495;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)EVAL(ctx,1,local+6); /*eval*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	goto WHL43494;
WHX43495:
	local[6]= NIL;
BLK43496:
	w = local[6];
	local[0]= w;
BLK43362:
	ctx->vsp=local; return(local[0]);}

/*piped-fork*/
static pointer F43262(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT43526;}
	local[0]= NIL;
ENT43526:
ENT43525:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+2;
	w=(pointer)PIPE(ctx,0,local+2); /*unix:pipe*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PIPE(ctx,0,local+3); /*unix:pipe*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FORK(ctx,0,local+4); /*unix:fork*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)STREAMP(ctx,1,local+11); /*streamp*/
	if (w!=NIL) goto IF43574;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SYSERRLIST(ctx,1,local+11); /*unix:syserrlist*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,1,local+11); /*error*/
	local[11]= w;
	goto IF43575;
IF43574:
	local[11]= NIL;
IF43575:
	local[11]= local[4];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF43595;
	local[11]= loadglobal(fqv[10]);
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= loadglobal(fqv[11]);
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= *(ovafptr(local[2],fqv[12]));
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= *(ovafptr(local[3],fqv[13]));
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= local[2];
	local[12]= fqv[14];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)DUP(ctx,1,local+11); /*unix:dup*/
	local[5] = w;
	local[11]= local[3];
	local[12]= fqv[15];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)DUP(ctx,1,local+11); /*unix:dup*/
	local[6] = w;
	local[11]= makeint(2);
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(pointer)SIGNAL(ctx,2,local+11); /*unix:signal*/
	local[11]= loadglobal(fqv[16]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[17];
	local[14]= local[5];
	local[15]= fqv[18];
	local[16]= fqv[19];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	w = local[11];
	storeglobal(fqv[10],w);
	local[11]= loadglobal(fqv[16]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[17];
	local[14]= local[6];
	local[15]= fqv[20];
	local[16]= fqv[21];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	w = local[11];
	storeglobal(fqv[11],w);
	local[11]= loadglobal(fqv[10]);
	local[12]= loadglobal(fqv[11]);
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,2,local+11,&ftab[4],fqv[22]); /*make-two-way-stream*/
	local[11]= w;
	storeglobal(fqv[23],w);
	w = local[0];
	if (!isstring(w)) goto CON43721;
	local[11]= makeint(32);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*position*/
	if (w==NIL) goto IF43727;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SYSTEM(ctx,1,local+11); /*unix:system*/
	local[11]= w;
	goto IF43728;
IF43727:
	local[11]= (pointer)get_sym_func(fqv[25]);
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,3,local+11); /*apply*/
	local[11]= w;
IF43728:
	goto CON43719;
CON43721:
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,1,local+11,&ftab[6],fqv[26]); /*functionp*/
	if (w==NIL) goto CON43744;
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)APPLY(ctx,2,local+11); /*apply*/
	local[11]= fqv[27];
	w = T;
	ctx->vsp=local+12;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto CON43719;
CON43744:
WHL43766:
	if (T==NIL) goto WHX43767;
	{jmp_buf jb;
	w = makeint(0);
	ctx->vsp=local+11;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT43773;}
	local[17]= makeint(0);
	storeglobal(fqv[28],local[17]);
	local[17]= fqv[29];
	ctx->vsp=local+18;
	w=(*ftab[7])(ctx,1,local+17,&ftab[7],fqv[30]); /*reploop*/
	local[17]= fqv[27];
	w = NIL;
	ctx->vsp=local+18;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[17];
CAT43773:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL43766;
WHX43767:
	local[11]= NIL;
BLK43768:
	goto CON43719;
CON43762:
	local[11]= NIL;
CON43719:
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)EXIT(ctx,1,local+11); /*unix::exit*/
	local[11]= w;
	goto IF43596;
IF43595:
	local[11]= loadglobal(fqv[31]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= NIL;
	local[13]= NIL;
	if (loadglobal(fqv[32])==NIL) goto IF43815;
	local[14]= T;
	local[15]= fqv[33];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)XFORMAT(ctx,3,local+14); /*format*/
	local[14]= w;
	goto IF43816;
IF43815:
	local[14]= NIL;
IF43816:
	local[14]= local[11];
	local[15]= local[4];
	local[16]= fqv[34];
	ctx->vsp=local+17;
	w=(pointer)PUTPROP(ctx,3,local+14); /*putprop*/
	local[12] = *(ovafptr(local[3],fqv[13]));
	local[13] = *(ovafptr(local[2],fqv[12]));
	local[14]= local[12];
	*(ovafptr(local[11],fqv[13])) = local[14];
	local[14]= local[13];
	local[15]= local[14];
	*(ovafptr(local[11],fqv[12])) = local[15];
	local[14]= local[12];
	local[15]= local[4];
	local[16]= fqv[34];
	ctx->vsp=local+17;
	w=(pointer)PUTPROP(ctx,3,local+14); /*putprop*/
	local[14]= *(ovafptr(local[2],fqv[13]));
	ctx->vsp=local+15;
	w=(pointer)CLOSE(ctx,1,local+14); /*close*/
	local[14]= *(ovafptr(local[3],fqv[12]));
	ctx->vsp=local+15;
	w=(pointer)CLOSE(ctx,1,local+14); /*close*/
	w = local[11];
	local[11]= w;
IF43596:
	w = local[11];
	local[0]= w;
BLK43523:
	ctx->vsp=local; return(local[0]);}

/*popen*/
static pointer F43264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST43881:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)PIPE(ctx,0,local+1); /*unix:pipe*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PIPE(ctx,0,local+2); /*unix:pipe*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)FORK(ctx,0,local+4); /*unix:fork*/
	local[3] = w;
	local[4]= local[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF43911;
	local[4]= loadglobal(fqv[10]);
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= loadglobal(fqv[11]);
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= *(ovafptr(local[1],fqv[12]));
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= *(ovafptr(local[2],fqv[13]));
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= local[1];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)DUP(ctx,1,local+4); /*unix:dup*/
	local[4]= local[2];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)DUP(ctx,1,local+4); /*unix:dup*/
	local[4]= makeint(32);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[24]); /*position*/
	if (w==NIL) goto IF43960;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SYSTEM(ctx,1,local+4); /*unix:system*/
	local[4]= w;
	goto IF43961;
IF43960:
	local[4]= (pointer)get_sym_func(fqv[25]);
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,3,local+4); /*apply*/
	local[4]= w;
IF43961:
	goto IF43912;
IF43911:
	local[4]= loadglobal(fqv[31]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	if (loadglobal(fqv[32])==NIL) goto IF43994;
	local[7]= T;
	local[8]= fqv[35];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF43995;
IF43994:
	local[7]= NIL;
IF43995:
	local[7]= local[4];
	local[8]= local[3];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[5] = *(ovafptr(local[2],fqv[13]));
	local[6] = *(ovafptr(local[1],fqv[12]));
	local[7]= local[5];
	*(ovafptr(local[4],fqv[13])) = local[7];
	local[7]= local[6];
	local[8]= local[7];
	*(ovafptr(local[4],fqv[12])) = local[8];
	local[7]= local[5];
	local[8]= local[3];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= *(ovafptr(local[1],fqv[13]));
	ctx->vsp=local+8;
	w=(pointer)CLOSE(ctx,1,local+7); /*close*/
	local[7]= *(ovafptr(local[2],fqv[12]));
	ctx->vsp=local+8;
	w=(pointer)CLOSE(ctx,1,local+7); /*close*/
	w = local[4];
	local[4]= w;
IF43912:
	w = local[4];
	local[0]= w;
BLK43879:
	ctx->vsp=local; return(local[0]);}

/*xfork*/
static pointer F43266(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[36], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY44069;
	local[0] = loadglobal(fqv[10]);
KEY44069:
	if (n & (1<<1)) goto KEY44075;
	local[1] = loadglobal(fqv[11]);
KEY44075:
	if (n & (1<<2)) goto KEY44081;
	local[2] = loadglobal(fqv[37]);
KEY44081:
	if (n & (1<<3)) goto KEY44088;
	local[3] = NIL;
KEY44088:
	ctx->vsp=local+4;
	w=(pointer)FORK(ctx,0,local+4); /*unix:fork*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[4];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto CON44114;
	local[6]= local[0];
	local[7]= fqv[14];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF44121;
	local[6]= local[0];
	local[7]= fqv[14];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)DUP2(ctx,2,local+6); /*unix:dup2*/
	local[6]= w;
	goto IF44122;
IF44121:
	local[6]= NIL;
IF44122:
	local[6]= local[1];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF44143;
	local[6]= local[1];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)DUP2(ctx,2,local+6); /*unix:dup2*/
	local[6]= w;
	goto IF44144;
IF44143:
	local[6]= NIL;
IF44144:
	local[6]= local[2];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF44165;
	local[6]= local[2];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)DUP2(ctx,2,local+6); /*unix:dup2*/
	local[6]= w;
	goto IF44166;
IF44165:
	local[6]= NIL;
IF44166:
	local[6]= makeint(32);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*position*/
	if (w==NIL) goto IF44186;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SYSTEM(ctx,1,local+6); /*unix:system*/
	local[6]= w;
	goto IF44187;
IF44186:
	local[6]= (pointer)get_sym_func(fqv[25]);
	local[7]= argv[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
IF44187:
	local[6]= fqv[38];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[39]); /*exit*/
	local[6]= w;
	goto CON44112;
CON44114:
	if (loadglobal(fqv[32])==NIL) goto IF44213;
	local[6]= T;
	local[7]= fqv[40];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF44214;
IF44213:
	local[6]= NIL;
IF44214:
	goto CON44112;
CON44209:
	local[6]= NIL;
CON44112:
	local[6]= loadglobal(fqv[31]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[17];
	local[9]= local[1];
	local[10]= fqv[41];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[0];
	local[11]= fqv[42];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	w = local[6];
	local[5] = w;
	w = local[5];
	local[0]= w;
BLK44057:
	ctx->vsp=local; return(local[0]);}

/*dir*/
static pointer F43269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT44273;}
	local[0]= fqv[43];
ENT44273:
ENT44272:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,1,local+1,&ftab[9],fqv[44]); /*directory*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[45]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,2,local+1); /*sort*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(16);
	local[4]= (pointer)get_sym_func(fqv[46]);
	local[5]= (pointer)get_sym_func(fqv[47]);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,2,local+4); /*apply*/
	local[4]= (pointer)((integer_t)(w)+4);
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= makeint(80);
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,4,local+2,&ftab[10],fqv[48]); /*tprint*/
	local[0]= w;
BLK44270:
	ctx->vsp=local; return(local[0]);}

/*rusage*/
static pointer F43271(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT44328;}
	local[0]= makeint(0);
ENT44328:
	if (n>=2) { local[1]=(argv[1]); goto ENT44327;}
	local[1]= T;
ENT44327:
ENT44326:
	if (n>2) maerror();
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)GETRUSAGE(ctx,1,local+2); /*unix:getrusage*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GETPAGESIZE(ctx,0,local+3); /*unix:getpagesize*/
	local[3]= w;
	local[4]= makeint(1024);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= local[1];
	local[5]= fqv[49];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,4,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[50];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= local[1];
	local[5]= fqv[51];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= local[1];
	local[5]= fqv[52];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[53];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[54];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[55];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[56];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[57];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[58];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[59];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[60];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[61];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[0]= w;
BLK44324:
	ctx->vsp=local; return(local[0]);}

/*xterm-window*/
static pointer F43273(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT44994;}
	local[0]= fqv[62];
ENT44994:
	if (n>=2) { local[1]=(argv[1]); goto ENT44993;}
	local[1]= NIL;
ENT44993:
ENT44992:
	if (n>2) maerror();
	local[2]= NIL;
	local[3]= makeint(112);
	local[4]= makeint(0);
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
WHL45035:
	if (local[5]!=NIL) goto WHX45036;
	local[8]= NIL;
	local[9]= fqv[63];
	local[10]= local[3];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[2] = w;
	local[8]= local[2];
	local[9]= fqv[64];
	local[10]= NIL;
	local[11]= fqv[65];
	local[12]= fqv[66];
	ctx->vsp=local+13;
	w=(*ftab[11])(ctx,5,local+8,&ftab[11],fqv[67]); /*open*/
	local[5] = w;
	if (local[5]!=NIL) goto IF45070;
	local[4] = (pointer)((integer_t)(local[4])+4);
	local[8]= local[4];
	local[9]= makeint(16);
	ctx->vsp=local+10;
	w=(pointer)NUMEQUAL(ctx,2,local+8); /*=*/
	if (w==NIL) goto IF45091;
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[4] = makeint(0);
	local[8]= local[3];
	local[9]= makeint(122);
	ctx->vsp=local+10;
	w=(pointer)NUMEQUAL(ctx,2,local+8); /*=*/
	if (w==NIL) goto IF45117;
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK44990;
	goto IF45118;
IF45117:
	local[8]= NIL;
IF45118:
	goto IF45092;
IF45091:
	local[8]= NIL;
IF45092:
	goto IF45071;
IF45070:
	local[8]= NIL;
IF45071:
	goto WHL45035;
WHX45036:
	local[8]= NIL;
BLK45037:
	local[8]= local[5];
	local[9]= fqv[14];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[6] = w;
	local[8]= local[6];
	local[9]= makeint(9);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF45128;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)CLOSE(ctx,1,local+8); /*close*/
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK44990;
	goto IF45129;
IF45128:
	local[8]= NIL;
IF45129:
	local[8]= local[5];
	local[9]= fqv[68];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[69];
	local[11]= local[3];
	local[12]= local[4];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,5,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)F43262(ctx,2,local+8); /*piped-fork*/
	local[7] = w;
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[0]= w;
BLK44990:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___process(ctx,n,argv,env)
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
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF45186;
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[72],w);
	goto IF45187;
IF45186:
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF45187:
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[75],module,F43303,fqv[76]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F43258,fqv[78]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F43260,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F43262,fqv[82]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F43264,fqv[84]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[85],module,F43266,fqv[86]);
	local[0]= fqv[44];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F43269,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F43271,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F43273,fqv[93]);
	local[0]= fqv[94];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[96]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<13; i++) ftab[i]=fcallx;
}
