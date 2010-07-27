/* bodyrel.c :  entry=bodyrel */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "bodyrel.h"
#pragma init (register_bodyrel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___bodyrel();
extern pointer build_quote_vector();
static register_bodyrel()
  { add_module_initializer("___bodyrel", ___bodyrel);}

static pointer F4456();
static pointer F4457();
static pointer F4458();
static pointer F4459();
static pointer F4460();
static pointer F4461();
static pointer F4462();
static pointer F4463();
static pointer F4464();
static pointer F4465();
static pointer F4466();
static pointer F4467();
static pointer F4468();
static pointer F4469();

/*coplanar-fe-intersection*/
static pointer F4456(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4473;}
	local[0]= fqv[0];
ENT4473:
	if (n>=4) { local[1]=(argv[3]); goto ENT4472;}
	local[1]= loadglobal(fqv[1]);
ENT4472:
ENT4471:
	if (n>4) maerror();
	local[2]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)COPYSEQ(ctx,1,local+3); /*copy-seq*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SQRT(ctx,1,local+10); /*sqrt*/
	local[10]= w;
	local[11]= NIL;
	local[12]= argv[0];
	local[13]= fqv[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
WHL4475:
	if (local[12]==NIL) goto WHX4476;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= local[11];
	local[14]= fqv[3];
	local[15]= argv[1];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,4,local+13); /*send*/
	local[5] = w;
	w = local[5];
	if (!iscons(w)) goto IF4479;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[4];
	ctx->vsp=local+15;
	w=(pointer)EQ(ctx,2,local+13); /*eql*/
	if (w==NIL) goto IF4481;
	local[13]= local[11];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	w = local[4];
	ctx->vsp=local+14;
	local[4] = cons(ctx,local[13],w);
	local[13]= local[4];
	goto IF4482;
IF4481:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w = local[4];
	ctx->vsp=local+14;
	local[4] = cons(ctx,local[13],w);
	local[13]= local[4];
IF4482:
	goto IF4480;
IF4479:
	local[13]= NIL;
IF4480:
	goto WHL4475;
WHX4476:
	local[13]= NIL;
BLK4477:
	w = NIL;
	if (local[4]!=NIL) goto IF4483;
	local[11]= argv[0];
	local[12]= fqv[5];
	local[13]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[5] = w;
	local[11]= NIL;
	local[12]= local[5];
	if (local[0]!=local[12]) goto IF4485;
	local[12]= NIL;
	local[13]= local[2];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	goto IF4486;
IF4485:
	local[12]= NIL;
IF4486:
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	ctx->vsp=local+11;
	local[0]=w;
	goto BLK4470;
	goto IF4484;
IF4483:
	local[11]= NIL;
IF4484:
	local[11]= local[4];
	local[12]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4487,env,argv,local);
	ctx->vsp=local+14;
	w=(pointer)SORT(ctx,3,local+11); /*sort*/
	local[4] = w;
	local[11]= local[4];
	local[12]= makeflt(1.00000000e+00);
	w = NIL;
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)NCONC(ctx,2,local+11); /*nconc*/
	local[6] = makeflt(0.00000000e+00);
	local[11]= NIL;
	local[12]= local[4];
WHL4489:
	if (local[12]==NIL) goto WHX4490;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	w = local[11];
	if (!iscons(w)) goto IF4493;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	goto IF4494;
IF4493:
	local[13]= local[11];
IF4494:
	local[7] = local[13];
	local[13]= local[6];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[0])(ctx,3,local+13,&ftab[0],fqv[7]); /*eps<*/
	if (w==NIL) goto IF4495;
	local[13]= argv[0];
	local[14]= fqv[5];
	local[15]= argv[1];
	local[16]= fqv[8];
	local[17]= local[6];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)PLUS(ctx,2,local+17); /*+*/
	local[17]= w;
	local[18]= makeflt(2.00000000e+00);
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[5] = w;
	local[13]= local[5];
	if (local[0]!=local[13]) goto IF4497;
	local[13]= T;
	local[14]= argv[1];
	local[15]= fqv[8];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= argv[1];
	local[16]= fqv[8];
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	w = local[9];
	ctx->vsp=local+14;
	local[9] = cons(ctx,local[13],w);
	local[13]= local[9];
	goto IF4498;
IF4497:
	local[13]= NIL;
IF4498:
	local[6] = local[7];
	local[13]= local[6];
	goto IF4496;
IF4495:
	local[13]= NIL;
IF4496:
	w = local[11];
	if (!iscons(w)) goto IF4499;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	local[13]= local[6];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,3,local+13,&ftab[1],fqv[9]); /*eps<>*/
	if (w==NIL) goto IF4501;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= argv[1];
	local[15]= argv[1];
	local[16]= fqv[8];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	local[16]= argv[1];
	local[17]= fqv[8];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,4,local+13); /*list*/
	local[13]= w;
	w = local[8];
	ctx->vsp=local+14;
	local[8] = cons(ctx,local[13],w);
	local[13]= local[8];
	goto IF4502;
IF4501:
	local[13]= NIL;
IF4502:
	local[6] = local[7];
	local[13]= local[6];
	goto IF4500;
IF4499:
	local[13]= NIL;
IF4500:
	goto WHL4489;
WHX4490:
	local[13]= NIL;
BLK4491:
	w = NIL;
	local[11]= local[8];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[0]= w;
BLK4470:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4487(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF4503;
	local[0]= argv[0];
	goto IF4504;
IF4503:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= makeflt(2.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
IF4504:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-next-segment*/
static pointer F4457(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000002e+20);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL4507:
	if (local[3]==NIL) goto WHX4508;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VDISTANCE(ctx,2,local+5); /*distance*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF4511;
	local[1] = local[2];
	local[0] = local[6];
	local[7]= local[0];
	goto IF4512;
IF4511:
	local[7]= NIL;
IF4512:
	w = local[7];
	goto WHL4507;
WHX4508:
	local[4]= NIL;
BLK4509:
	w = NIL;
	local[2]= local[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF4513;
	local[2]= local[1];
	goto IF4514;
IF4513:
	local[2]= NIL;
IF4514:
	w = local[2];
	local[0]= w;
BLK4505:
	ctx->vsp=local; return(local[0]);}

/*find-loop*/
static pointer F4458(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4517;}
	local[0]= loadglobal(fqv[10]);
ENT4517:
ENT4516:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= loadglobal(fqv[11]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[9];
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[1] = w;
WHL4519:
	local[9]= local[5];
	local[10]= argv[0];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F4457(ctx,3,local+9); /*find-next-segment*/
	local[6] = w;
	if (local[6]==NIL) goto WHX4520;
	local[9]= local[6];
	local[10]= argv[0];
	local[11]= fqv[12];
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[13]); /*delete*/
	argv[0] = w;
	local[3] = local[5];
	local[9]= local[5];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[14]); /*eps-v=*/
	if (w==NIL) goto IF4522;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	local[9]= local[5];
	goto IF4523;
IF4522:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	local[9]= local[5];
IF4523:
	local[9]= local[3];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	goto WHL4519;
WHX4520:
	local[9]= NIL;
BLK4521:
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	local[1] = w;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[14]); /*eps-v=*/
	if (w!=NIL) goto CON4525;
	local[9]= NIL;
	local[10]= local[1];
WHL4527:
	if (local[10]==NIL) goto WHX4528;
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,2,local+11,&ftab[4],fqv[15]); /*make-line*/
	local[11]= w;
	w = local[8];
	ctx->vsp=local+12;
	local[8] = cons(ctx,local[11],w);
	goto WHL4527;
WHX4528:
	local[11]= NIL;
BLK4529:
	w = NIL;
	local[9]= local[8];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto CON4524;
CON4525:
	local[9]= (pointer)get_sym_func(fqv[16]);
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[1] = w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,1,local+9,&ftab[5],fqv[17]); /*face-normal-vector*/
	local[9]= w;
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[9]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[9]);
	if (left >= right) goto IF4532;}
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	local[1] = w;
	local[9]= local[1];
	goto IF4533;
IF4532:
	local[9]= NIL;
IF4533:
	local[9]= loadglobal(fqv[11]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[18];
	local[12]= fqv[19];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto CON4524;
CON4531:
	local[9]= NIL;
CON4524:
	w = local[9];
	local[0]= w;
BLK4515:
	ctx->vsp=local; return(local[0]);}

/*punch-hole*/
static pointer F4459(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[19];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	local[1]= loadglobal(fqv[20]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= fqv[19];
	local[5]= local[0];
	local[6]= fqv[21];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK4535:
	ctx->vsp=local; return(local[0]);}

/*construct-polygon*/
static pointer F4460(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4538;}
	local[0]= loadglobal(fqv[10]);
ENT4538:
ENT4537:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL4539:
	if (argv[0]==NIL) goto WHX4540;
	local[7]= argv[0];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)F4458(ctx,2,local+7); /*find-loop*/
	local[4] = w;
	local[7]= NIL;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
WHL4543:
	if (local[8]==NIL) goto WHX4544;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= loadglobal(fqv[23]);
	ctx->vsp=local+11;
	w=(pointer)DERIVEDP(ctx,2,local+9); /*derivedp*/
	if (w==NIL) goto IF4547;
	local[9]= local[7];
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	local[9]= local[2];
	goto IF4548;
IF4547:
	local[9]= local[7];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
IF4548:
	goto WHL4543;
WHX4544:
	local[9]= NIL;
BLK4545:
	w = NIL;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	goto WHL4539;
WHX4540:
	local[7]= NIL;
BLK4541:
	local[7]= NIL;
	local[8]= local[1];
WHL4549:
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4550;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= NIL;
	local[10]= local[8];
WHL4554:
	if (local[10]==NIL) goto WHX4555;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= fqv[5];
	local[13]= local[9];
	local[14]= fqv[24];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto CON4559;
	local[11]= local[7];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)F4459(ctx,2,local+11); /*punch-hole*/
	local[11]= local[9];
	local[12]= local[1];
	local[13]= fqv[12];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,4,local+11,&ftab[2],fqv[13]); /*delete*/
	local[1] = w;
	local[11]= local[1];
	goto CON4558;
CON4559:
	local[11]= local[9];
	local[12]= fqv[5];
	local[13]= local[7];
	local[14]= fqv[24];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto CON4560;
	local[11]= local[9];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)F4459(ctx,2,local+11); /*punch-hole*/
	local[11]= local[7];
	local[12]= local[1];
	local[13]= fqv[12];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,4,local+11,&ftab[2],fqv[13]); /*delete*/
	local[1] = w;
	local[11]= local[1];
	goto CON4558;
CON4560:
	local[11]= NIL;
CON4558:
	goto WHL4554;
WHX4555:
	local[11]= NIL;
BLK4556:
	w = NIL;
	goto WHL4549;
WHX4550:
	local[9]= NIL;
BLK4551:
	w = local[9];
	local[7]= local[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)NCONC(ctx,2,local+7); /*nconc*/
	local[0]= w;
BLK4536:
	ctx->vsp=local; return(local[0]);}

/*remove-non-overlapping-border*/
static pointer F4461(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[2];
WHL4563:
	if (local[4]==NIL) goto WHX4564;
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
	local[5]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[5];
	local[8]= fqv[26];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+7); /*v**/
	local[7]= w;
	local[8]= local[6];
	local[9]= fqv[26];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+8); /*v**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VINNERPRODUCT(ctx,2,local+7); /*v.*/
	local[7]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[7]);
	if (left <= right) goto IF4567;}
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto IF4568;
IF4567:
	local[7]= NIL;
IF4568:
	w = local[7];
	goto WHL4563;
WHX4564:
	local[5]= NIL;
BLK4565:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK4561:
	ctx->vsp=local; return(local[0]);}

/*coplanar-ff-intersection*/
static pointer F4462(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4572;}
	local[0]= fqv[0];
ENT4572:
	if (n>=4) { local[1]=(argv[3]); goto ENT4571;}
	local[1]= loadglobal(fqv[1]);
ENT4571:
ENT4570:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= fqv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL4574:
	if (local[9]==NIL) goto WHX4575;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[1];
	local[11]= local[8];
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)F4456(ctx,4,local+10); /*coplanar-fe-intersection*/
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4578;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[4] = w;
	local[10]= local[4];
	goto IF4579;
IF4578:
	local[10]= NIL;
IF4579:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4580;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[2] = w;
	local[10]= local[2];
	goto IF4581;
IF4580:
	local[10]= NIL;
IF4581:
	goto WHL4574;
WHX4575:
	local[10]= NIL;
BLK4576:
	w = NIL;
	if (local[4]==NIL) goto IF4582;
	local[7] = T;
	local[8]= local[7];
	goto IF4583;
IF4582:
	local[8]= NIL;
IF4583:
	if (T==NIL) goto IF4584;
	local[8]= argv[1];
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)F4461(ctx,3,local+8); /*remove-non-overlapping-border*/
	local[4] = w;
	local[8]= local[4];
	goto IF4585;
IF4584:
	local[8]= (pointer)get_sym_func(fqv[27]);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[4] = w;
	local[8]= local[4];
IF4585:
	local[8]= NIL;
	local[9]= argv[1];
	local[10]= fqv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL4587:
	if (local[9]==NIL) goto WHX4588;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= local[8];
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)F4456(ctx,4,local+10); /*coplanar-fe-intersection*/
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4591;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[5] = w;
	local[10]= local[5];
	goto IF4592;
IF4591:
	local[10]= NIL;
IF4592:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4593;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[2] = w;
	local[10]= local[2];
	goto IF4594;
IF4593:
	local[10]= NIL;
IF4594:
	goto WHL4587;
WHX4588:
	local[10]= NIL;
BLK4589:
	w = NIL;
	if (local[5]==NIL) goto IF4595;
	local[7] = T;
	local[8]= local[7];
	goto IF4596;
IF4595:
	local[8]= NIL;
IF4596:
	if (T==NIL) goto IF4597;
	local[8]= argv[0];
	local[9]= argv[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)F4461(ctx,3,local+8); /*remove-non-overlapping-border*/
	local[5] = w;
	local[8]= local[5];
	goto IF4598;
IF4597:
	local[8]= (pointer)get_sym_func(fqv[27]);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[5] = w;
	local[8]= local[5];
IF4598:
	local[8]= local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[3] = w;
	local[8]= local[3];
	local[9]= fqv[28];
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4599,env,argv,local);
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,3,local+8,&ftab[6],fqv[29]); /*remove-duplicates*/
	local[3] = w;
	if (local[7]!=NIL) goto CON4601;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO4602,env,argv,local);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[30]); /*every*/
	if (w==NIL) goto CON4601;
	local[8]= argv[0];
	local[9]= fqv[5];
	local[10]= argv[1];
	local[11]= fqv[24];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= makeflt(9.99999698e-04);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= fqv[5];
	local[11]= argv[0];
	local[12]= fqv[24];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeflt(9.99999698e-04);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	local[10]= local[0];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4604;
	local[10]= local[8];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4606;
	local[10]= argv[1];
	goto CON4605;
CON4606:
	local[10]= local[9];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4607;
	local[10]= argv[0];
	goto CON4605;
CON4607:
	local[10]= NIL;
	goto CON4605;
CON4608:
	local[10]= NIL;
CON4605:
	goto CON4603;
CON4604:
	local[10]= local[0];
	local[11]= fqv[31];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4609;
	local[10]= local[8];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4611;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	goto CON4610;
CON4611:
	local[10]= local[9];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4612;
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	goto CON4610;
CON4612:
	local[10]= argv[0];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	goto CON4610;
CON4613:
	local[10]= NIL;
CON4610:
	goto CON4603;
CON4609:
	local[10]= NIL;
CON4603:
	w = local[10];
	local[8]= w;
	goto CON4600;
CON4601:
	local[8]= (pointer)get_sym_func(fqv[32]);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[25];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)F4460(ctx,2,local+8); /*construct-polygon*/
	local[8]= w;
	goto CON4600;
CON4614:
	local[8]= NIL;
CON4600:
	w = local[8];
	local[0]= w;
BLK4569:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4599(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
	if (w==NIL) goto AND4616;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
AND4616:
	if (local[0]!=NIL) goto OR4615;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
	if (w==NIL) goto AND4617;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
AND4617:
OR4615:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (((w)->c.cons.car)==NIL?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*face**/
static pointer F4463(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4620;}
	local[0]= loadglobal(fqv[1]);
ENT4620:
ENT4619:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4462(ctx,4,local+1); /*coplanar-ff-intersection*/
	local[0]= w;
BLK4618:
	ctx->vsp=local; return(local[0]);}

/*face+*/
static pointer F4464(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4623;}
	local[0]= loadglobal(fqv[1]);
ENT4623:
ENT4622:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[31];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4462(ctx,4,local+1); /*coplanar-ff-intersection*/
	local[0]= w;
BLK4621:
	ctx->vsp=local; return(local[0]);}

/*non-coplanar-fe-relation*/
static pointer F4465(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4626;}
	local[0]= loadglobal(fqv[1]);
ENT4626:
ENT4625:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1]->c.obj.iv[1];
	local[4]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[8];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[1];
	local[5]= makeflt(0.00000000e+00);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,3,local+4,&ftab[8],fqv[34]); /*eps=*/
	if (w!=NIL) goto OR4629;
	local[4]= local[1];
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,3,local+4,&ftab[8],fqv[34]); /*eps=*/
	if (w!=NIL) goto OR4629;
	goto CON4628;
OR4629:
	local[4]= argv[0];
	local[5]= fqv[5];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,2,local+4,&ftab[9],fqv[36]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	goto CON4627;
CON4628:
	local[4]= makeflt(0.00000000e+00);
	local[5]= local[1];
	local[6]= makeflt(1.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,3,local+4); /*<*/
	if (w==NIL) goto CON4630;
	local[4]= argv[0];
	local[5]= fqv[5];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[3];
	local[5]= local[4];
	if (fqv[0]!=local[5]) goto IF4632;
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF4634;
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF4634;
	local[5]= fqv[38];
	goto IF4635;
IF4634:
	local[5]= fqv[39];
IF4635:
	goto IF4633;
IF4632:
	local[5]= local[4];
	if (fqv[40]!=local[5]) goto IF4636;
	local[5]= fqv[38];
	goto IF4637;
IF4636:
	local[5]= local[4];
	if (fqv[31]!=local[5]) goto IF4638;
	local[5]= NIL;
	goto IF4639;
IF4638:
	local[5]= NIL;
IF4639:
IF4637:
IF4633:
	w = local[5];
	local[4]= w;
	goto CON4627;
CON4630:
	local[4]= NIL;
	goto CON4627;
CON4640:
	local[4]= NIL;
CON4627:
	w = local[4];
	local[0]= w;
BLK4624:
	ctx->vsp=local; return(local[0]);}

/*ff-relation*/
static pointer F4466(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4643;}
	local[0]= loadglobal(fqv[1]);
ENT4643:
ENT4642:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= argv[1]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= argv[1]->c.obj.iv[4];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= makeflt(1.00000000e+00);
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,3,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto CON4645;
	local[13]= local[3];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,2,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto IF4646;
	local[13]= fqv[41];
	local[14]= fqv[42];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	local[9] = w;
	local[13]= local[9];
	goto IF4647;
IF4646:
	w = NIL;
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4641;
IF4647:
	goto CON4644;
CON4645:
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= makeflt(-1.00000000e+00);
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,2,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto CON4648;
	local[13]= local[3];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,3,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto IF4649;
	local[13]= fqv[41];
	local[14]= fqv[43];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	local[9] = w;
	local[13]= local[9];
	goto IF4650;
IF4649:
	w = NIL;
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4641;
IF4650:
	goto CON4644;
CON4648:
	local[13]= NIL;
CON4644:
	if (local[9]==NIL) goto IF4651;
	local[13]= argv[0];
	local[14]= argv[1];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)F4463(ctx,3,local+13); /*face**/
	local[10] = w;
	local[13]= local[10];
	local[14]= loadglobal(fqv[11]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto CON4654;
	local[13]= local[9];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPEND(ctx,2,local+13); /*append*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4641;
	goto CON4653;
CON4654:
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4656,env,argv,local);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(*ftab[10])(ctx,2,local+13,&ftab[10],fqv[44]); /*some*/
	if (w==NIL) goto CON4655;
	local[13]= local[9];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)APPEND(ctx,2,local+13); /*append*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4641;
	goto CON4653;
CON4655:
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4658,env,argv,local);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,2,local+13,&ftab[7],fqv[30]); /*every*/
	if (w==NIL) goto CON4657;
	local[13]= fqv[45];
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4641;
	goto CON4653;
CON4657:
	local[13]= NIL;
CON4653:
	goto IF4652;
IF4651:
	local[13]= NIL;
IF4652:
	local[13]= NIL;
	local[14]= local[5];
WHL4660:
	if (local[14]==NIL) goto WHX4661;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[1];
	local[16]= local[13];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)F4465(ctx,3,local+15); /*non-coplanar-fe-relation*/
	local[11] = w;
	local[15]= local[11];
	if (fqv[39]!=local[15]) goto IF4664;
	local[15]= T;
	local[16]= fqv[46];
	local[17]= argv[1];
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,4,local+15); /*format*/
	local[15]= fqv[39];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK4641;
	goto IF4665;
IF4664:
	local[15]= NIL;
IF4665:
	if (local[11]==NIL) goto IF4666;
	local[15]= local[11];
	w = local[10];
	ctx->vsp=local+16;
	local[10] = cons(ctx,local[15],w);
	local[15]= local[10];
	goto IF4667;
IF4666:
	local[15]= NIL;
IF4667:
	goto WHL4660;
WHX4661:
	local[15]= NIL;
BLK4662:
	w = NIL;
	local[13]= NIL;
	local[14]= local[6];
WHL4669:
	if (local[14]==NIL) goto WHX4670;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	local[16]= local[13];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)F4465(ctx,3,local+15); /*non-coplanar-fe-relation*/
	local[11] = w;
	local[15]= local[11];
	if (fqv[39]!=local[15]) goto IF4673;
	local[15]= T;
	local[16]= fqv[47];
	local[17]= argv[0];
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,4,local+15); /*format*/
	local[15]= fqv[39];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK4641;
	goto IF4674;
IF4673:
	local[15]= NIL;
IF4674:
	if (local[11]==NIL) goto IF4675;
	local[15]= local[11];
	w = local[10];
	ctx->vsp=local+16;
	local[10] = cons(ctx,local[15],w);
	local[15]= local[10];
	goto IF4676;
IF4675:
	local[15]= NIL;
IF4676:
	goto WHL4669;
WHX4670:
	local[15]= NIL;
BLK4671:
	w = NIL;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4679,env,argv,local);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,2,local+13,&ftab[7],fqv[30]); /*every*/
	if (w==NIL) goto CON4678;
	local[13]= fqv[48];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	goto CON4677;
CON4678:
	local[13]= local[10];
	goto CON4677;
CON4680:
	local[13]= NIL;
CON4677:
	w = local[13];
	local[0]= w;
BLK4641:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4656(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4658(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[23]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = ((fqv[38])==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*bb-relation*/
static pointer F4467(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4683;}
	local[0]= loadglobal(fqv[49]);
ENT4683:
ENT4682:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[50];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[51];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= fqv[51];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= NIL;
	if (local[1]==NIL) goto IF4684;
	local[12]= argv[0];
	local[13]= fqv[52];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[2] = w;
	local[12]= argv[1];
	local[13]= fqv[52];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[3] = w;
	local[12]= local[8];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(*ftab[11])(ctx,2,local+12,&ftab[11],fqv[53]); /*intersection*/
	local[8] = w;
	local[12]= local[9];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(*ftab[11])(ctx,2,local+12,&ftab[11],fqv[53]); /*intersection*/
	local[9] = w;
	local[12]= argv[0];
	local[13]= fqv[54];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[4] = w;
	local[12]= argv[1];
	local[13]= fqv[54];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[5] = w;
	local[12]= NIL;
	local[13]= local[2];
WHL4687:
	if (local[13]==NIL) goto WHX4688;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[12];
	local[15]= fqv[55];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[11] = w;
	local[14]= local[11];
	local[15]= fqv[56];
	local[16]= local[0];
	local[17]= T;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[14]= NIL;
	local[15]= local[3];
WHL4692:
	if (local[15]==NIL) goto WHX4693;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[55];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	local[16]= w;
	local[17]= fqv[57];
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (w==NIL) goto OR4698;
	goto IF4696;
OR4698:
	local[7] = NIL;
	local[16]= local[7];
	goto IF4697;
IF4696:
	local[16]= local[12];
	local[17]= local[14];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)F4466(ctx,3,local+16); /*ff-relation*/
	local[7] = w;
	local[16]= local[7];
IF4697:
	if (local[7]!=NIL) goto CON4700;
	local[16]= NIL;
	goto CON4699;
CON4700:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[48]!=local[16]) goto CON4701;
	local[16]= NIL;
	goto CON4699;
CON4701:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[41]!=local[16]) goto CON4702;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[43]!=local[16]) goto CON4702;
	local[16]= fqv[58];
	local[17]= local[12];
	local[18]= local[14];
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.cdr;
	ctx->vsp=local+20;
	w=(pointer)LIST_STAR(ctx,4,local+16); /*list**/
	local[16]= w;
	w = local[6];
	ctx->vsp=local+17;
	local[6] = cons(ctx,local[16],w);
	local[16]= local[6];
	goto CON4699;
CON4702:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[45]!=local[16]) goto CON4703;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[42]!=local[16]) goto CON4703;
	local[16]= fqv[45];
	local[17]= local[12];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,3,local+16); /*list*/
	local[16]= w;
	w = local[6];
	ctx->vsp=local+17;
	local[6] = cons(ctx,local[16],w);
	local[16]= local[6];
	goto CON4699;
CON4703:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[41]!=local[16]) goto CON4704;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[42]!=local[16]) goto CON4704;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= loadglobal(fqv[11]);
	ctx->vsp=local+18;
	w=(pointer)DERIVEDP(ctx,2,local+16); /*derivedp*/
	if (w==NIL) goto CON4704;
	w = fqv[39];
	ctx->vsp=local+16;
	local[0]=w;
	goto BLK4681;
	goto CON4699;
CON4704:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[39]!=local[16]) goto CON4705;
	w = fqv[39];
	ctx->vsp=local+16;
	local[0]=w;
	goto BLK4681;
	goto CON4699;
CON4705:
	local[16]= local[12];
	local[17]= local[14];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)LIST_STAR(ctx,3,local+16); /*list**/
	local[16]= w;
	w = local[6];
	ctx->vsp=local+17;
	local[6] = cons(ctx,local[16],w);
	local[16]= local[6];
	goto CON4699;
CON4706:
	local[16]= NIL;
CON4699:
	goto WHL4692;
WHX4693:
	local[16]= NIL;
BLK4694:
	w = NIL;
	goto WHL4687;
WHX4688:
	local[14]= NIL;
BLK4689:
	w = NIL;
	local[12]= local[6];
	goto IF4685;
IF4684:
	local[12]= NIL;
IF4685:
	w = local[12];
	local[0]= w;
BLK4681:
	ctx->vsp=local; return(local[0]);}

/*make-lines*/
static pointer F4468(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4708,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK4707:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4708(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[15]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*copy-face*/
static pointer F4469(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET4710,env,argv,local);
	local[1]= loadglobal(fqv[59]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= fqv[19];
	local[5]= argv[0];
	w = local[0];
	ctx->vsp=local+6;
	w=FLET4710(ctx,1,local+5,w);
	local[5]= w;
	local[6]= fqv[60];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4712,env,argv,local);
	local[8]= local[0];
	local[9]= argv[0];
	local[10]= fqv[60];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK4709:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4710(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
WHL4714:
	if (local[3]==NIL) goto WHX4715;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL4714;
WHX4715:
	local[4]= NIL;
BLK4716:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4712(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[20]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[18];
	local[3]= fqv[19];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___bodyrel(ctx,n,argv,env)
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
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4719;
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[63],w);
	goto IF4720;
IF4719:
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4720:
	local[0]= fqv[65];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F4456,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F4457,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F4458,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F4459,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F4460,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F4461,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F4462,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F4463,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F4464,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F4465,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F4466,fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F4467,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F4468,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F4469,fqv[93]);
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
