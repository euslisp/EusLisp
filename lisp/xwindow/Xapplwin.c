/* Xapplwin.c :  entry=Xapplwin */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xapplwin.h"
#pragma init (register_Xapplwin)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xapplwin();
extern pointer build_quote_vector();
static register_Xapplwin()
  { add_module_initializer("___Xapplwin", ___Xapplwin);}

static pointer F3412();

/*:create-buttons*/
static pointer M3413(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[2];
	local[4]= argv[0];
	local[5]= fqv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[4];
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[6];
	local[4]= argv[0];
	local[5]= fqv[7];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[8];
	local[4]= argv[0];
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[34] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[10];
	local[4]= argv[0];
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[33] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[12]);
	local[3]= fqv[13];
	local[4]= argv[0];
	local[5]= fqv[7];
	local[6]= fqv[14];
	local[7]= makeint(23);
	local[8]= fqv[15];
	local[9]= loadglobal(fqv[16]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[12]);
	local[3]= fqv[17];
	local[4]= argv[0];
	local[5]= fqv[7];
	local[6]= fqv[14];
	local[7]= makeint(46);
	local[8]= fqv[15];
	local[9]= loadglobal(fqv[16]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	argv[0]->c.obj.iv[27] = w;
	w = argv[0]->c.obj.iv[27];
	local[0]= w;
BLK3414:
	ctx->vsp=local; return(local[0]);}

/*:create-fileview*/
static pointer M3415(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[19];
	local[3]= fqv[20];
	local[4]= argv[0];
	local[5]= fqv[21];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(15);
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= fqv[22];
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= argv[0]->c.obj.iv[18];
	local[10]= makeint(40);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,3,local+8); /*-*/
	local[8]= w;
	local[9]= fqv[15];
	local[10]= argv[0];
	local[11]= fqv[15];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[23];
	local[12]= T;
	local[13]= fqv[24];
	local[14]= T;
	local[15]= fqv[25];
	local[16]= NIL;
	local[17]= fqv[26];
	local[18]= argv[0];
	local[19]= fqv[27];
	local[20]= fqv[28];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,20,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[29] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[29]); /*truename*/
	argv[0]->c.obj.iv[25] = w;
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[30];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F3412(ctx,1,local+2); /*ls-l*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[30] = argv[0]->c.obj.iv[18];
	local[0]= argv[0];
	local[1]= fqv[31];
	local[2]= argv[0]->c.obj.iv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[27];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,1,local+2,&ftab[1],fqv[33]); /*namestring*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3416:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3418(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3420:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[34], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3421;
	local[1] = loadglobal(fqv[16]);
KEY3421:
	if (n & (1<<1)) goto KEY3422;
	local[5]= loadglobal(fqv[35]);
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,0,local+6,&ftab[2],fqv[36]); /*pwd*/
	local[6]= w;
	local[7]= fqv[37];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[2] = w;
KEY3422:
	if (n & (1<<2)) goto KEY3423;
	local[3] = NIL;
KEY3423:
	if (n & (1<<3)) goto KEY3424;
	local[4] = local[3];
KEY3424:
	local[5]= (pointer)get_sym_func(fqv[38]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[39]));
	local[8]= fqv[19];
	local[9]= fqv[21];
	local[10]= makeint(380);
	local[11]= fqv[22];
	local[12]= makeint(330);
	local[13]= fqv[15];
	local[14]= local[1];
	local[15]= fqv[40];
	local[16]= fqv[41];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	local[5]= argv[0];
	local[6]= fqv[42];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[43];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[0]->c.obj.iv[35] = local[3];
	argv[0]->c.obj.iv[36] = local[4];
	w = argv[0];
	local[0]= w;
BLK3419:
	ctx->vsp=local; return(local[0]);}

/*:cwd*/
static pointer M3425(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[27];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3426:
	ctx->vsp=local; return(local[0]);}

/*:file-selected*/
static pointer M3427(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(32);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[45]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF3429;
	local[3]= local[0];
	local[4]= makeint(0);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= fqv[32];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[2];
	goto IF3430;
IF3429:
	local[3]= NIL;
IF3430:
	w = local[3];
	local[0]= w;
BLK3428:
	ctx->vsp=local; return(local[0]);}

/*:selected-fname*/
static pointer M3431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[28];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(0);
	if ((integer_t)local[1] <= (integer_t)w) goto IF3433;
	local[1]= argv[0]->c.obj.iv[28];
	local[2]= fqv[32];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,2,local+1,&ftab[4],fqv[47]); /*merge-pathnames*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[29]); /*truename*/
	local[1]= w;
	goto IF3434;
IF3433:
	local[1]= argv[0];
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[29]); /*truename*/
	local[1]= w;
IF3434:
	w = local[1];
	local[0]= w;
BLK3432:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3435(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[50]); /*probe-file*/
	if (w==NIL) goto IF3437;
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[19];
	local[6]= fqv[52];
	local[7]= argv[0];
	local[8]= fqv[49];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[21];
	local[9]= makeint(500);
	local[10]= fqv[22];
	local[11]= makeint(500);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,8,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto IF3438;
IF3437:
	local[3]= NIL;
IF3438:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3436:
	ctx->vsp=local; return(local[0]);}

/*:ok*/
static pointer M3440(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (argv[0]->c.obj.iv[35]==NIL) goto IF3442;
	local[3]= (pointer)get_sym_func(fqv[54]);
	w=argv[0]->c.obj.iv[35];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[35];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[0];
	local[7]= fqv[49];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	w=argv[0]->c.obj.iv[35];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	local[3]= w;
	goto IF3443;
IF3442:
	local[3]= NIL;
IF3443:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3441:
	ctx->vsp=local; return(local[0]);}

/*:cancel*/
static pointer M3444(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (argv[0]->c.obj.iv[36]==NIL) goto IF3446;
	w=argv[0]->c.obj.iv[36];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[36];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[36];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF3447;
IF3446:
	local[3]= NIL;
IF3447:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3445:
	ctx->vsp=local; return(local[0]);}

/*:open*/
static pointer M3448(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[33]); /*namestring*/
	local[3] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[55]); /*lisp::directory-p*/
	if (w==NIL) goto IF3450;
	local[4]= loadglobal(fqv[35]);
	local[5]= local[3];
	local[6]= fqv[56];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,3,local+4); /*concatenate*/
	argv[0]->c.obj.iv[25] = w;
	local[4]= argv[0]->c.obj.iv[28];
	local[5]= fqv[32];
	local[6]= fqv[57];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= fqv[30];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F3412(ctx,1,local+6); /*ls-l*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[27];
	local[5]= fqv[32];
	local[6]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[33]); /*namestring*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3451;
IF3450:
	local[4]= NIL;
IF3451:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3449:
	ctx->vsp=local; return(local[0]);}

/*:go-up*/
static pointer M3452(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[29]); /*truename*/
	local[3]= w;
	local[4]= fqv[59];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,1,local+5,&ftab[7],fqv[60]); /*pathname-directory*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)BUTLAST(ctx,1,local+5); /*butlast*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,2,local+4,&ftab[8],fqv[61]); /*make-pathname*/
	local[4]= w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,1,local+5,&ftab[1],fqv[33]); /*namestring*/
	local[4] = w;
	argv[0]->c.obj.iv[25] = local[4];
	local[5]= argv[0]->c.obj.iv[27];
	local[6]= fqv[32];
	local[7]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[33]); /*namestring*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= fqv[58];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= fqv[30];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F3412(ctx,1,local+7); /*ls-l*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[28];
	local[6]= fqv[32];
	local[7]= fqv[62];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3453:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3454(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[63];
	local[2]= argv[2];
	local[3]= makeint(15);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= makeint(40);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3455:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3456(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3460;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3460;
	goto IF3458;
OR3460:
	local[5]= argv[0];
	local[6]= fqv[63];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3459;
IF3458:
	local[5]= NIL;
IF3459:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3457:
	ctx->vsp=local; return(local[0]);}

/*:create-buttons*/
static pointer M3461(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[39]));
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[65];
	local[4]= argv[0];
	local[5]= fqv[66];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[40] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[67];
	local[4]= argv[0];
	local[5]= fqv[68];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[38] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[69];
	local[4]= argv[0];
	local[5]= fqv[70];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[37] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[71];
	local[4]= argv[0];
	local[5]= fqv[72];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[41] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[12]);
	local[3]= fqv[73];
	local[4]= argv[0];
	local[5]= fqv[74];
	local[6]= fqv[14];
	local[7]= makeint(47);
	local[8]= fqv[15];
	local[9]= loadglobal(fqv[16]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	argv[0]->c.obj.iv[42] = w;
	w = argv[0]->c.obj.iv[42];
	local[0]= w;
BLK3462:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3463(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3465:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[39]));
	local[4]= fqv[19];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= loadglobal(fqv[75]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[19];
	local[4]= fqv[25];
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[43] = w;
	w = argv[0];
	local[0]= w;
BLK3464:
	ctx->vsp=local; return(local[0]);}

/*:load*/
static pointer M3467(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,1,local+3,&ftab[10],fqv[76]); /*load*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3468:
	ctx->vsp=local; return(local[0]);}

/*:eval*/
static pointer M3469(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[42];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,1,local+3,&ftab[11],fqv[77]); /*read-from-string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3470:
	ctx->vsp=local; return(local[0]);}

/*:print*/
static pointer M3471(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF3473;
	local[4]= NIL;
	local[5]= fqv[78];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[33]); /*namestring*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SYSTEM(ctx,1,local+4); /*unix:system*/
	local[4]= w;
	goto IF3474;
IF3473:
	local[4]= NIL;
IF3474:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3472:
	ctx->vsp=local; return(local[0]);}

/*:compile*/
static pointer M3475(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF3477;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[33]); /*namestring*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,1,local+4,&ftab[12],fqv[79]); /*compiler:compile-file*/
	local[4]= w;
	goto IF3478;
IF3477:
	local[4]= NIL;
IF3478:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3476:
	ctx->vsp=local; return(local[0]);}

/*:remove*/
static pointer M3479(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[33]); /*namestring*/
	argv[0]->c.obj.iv[44] = w;
	local[3]= argv[0]->c.obj.iv[43];
	local[4]= fqv[80];
	local[5]= argv[0];
	local[6]= fqv[81];
	local[7]= fqv[82];
	local[8]= loadglobal(fqv[35]);
	local[9]= argv[0]->c.obj.iv[44];
	local[10]= fqv[83];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3480:
	ctx->vsp=local; return(local[0]);}

/*:remove-confirm*/
static pointer M3481(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (fqv[84]!=local[0]) goto IF3483;
	local[0]= argv[0]->c.obj.iv[44];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= argv[0]->c.obj.iv[44];
	ctx->vsp=local+1;
	w=(pointer)UNLINK(ctx,1,local+0); /*unix:unlink*/
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[30];
	local[2]= argv[0];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F3412(ctx,1,local+2); /*ls-l*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF3484;
IF3483:
	local[0]= NIL;
IF3484:
	argv[0]->c.obj.iv[44] = NIL;
	w = argv[0]->c.obj.iv[44];
	local[0]= w;
BLK3482:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3485(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3487:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[85], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3488;
	local[1] = NIL;
KEY3488:
	if (n & (1<<1)) goto KEY3489;
	local[2] = NIL;
KEY3489:
	if (n & (1<<2)) goto KEY3490;
	local[3] = NIL;
KEY3490:
	if (n & (1<<3)) goto KEY3491;
	local[4] = NIL;
KEY3491:
	if (n & (1<<4)) goto KEY3492;
	local[5] = makeint(400);
KEY3492:
	local[6]= (pointer)get_sym_func(fqv[38]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[39]));
	local[9]= fqv[19];
	local[10]= fqv[21];
	local[11]= local[5];
	local[12]= fqv[15];
	local[13]= local[1];
	local[14]= fqv[40];
	local[15]= fqv[86];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,11,local+6); /*apply*/
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[1]);
	local[9]= fqv[87];
	local[10]= argv[0];
	local[11]= fqv[88];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[1]);
	local[9]= fqv[89];
	local[10]= argv[0];
	local[11]= fqv[70];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[27] = w;
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[1]);
	local[9]= fqv[90];
	local[10]= argv[0];
	local[11]= fqv[91];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[12]);
	local[9]= fqv[92];
	local[10]= argv[0];
	local[11]= fqv[91];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[30] = w;
	local[6]= argv[0];
	local[7]= fqv[31];
	local[8]= loadglobal(fqv[18]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[19];
	local[11]= fqv[21];
	local[12]= argv[0];
	local[13]= fqv[21];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= makeint(10);
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[5] = w;
	local[12]= local[5];
	local[13]= fqv[22];
	local[14]= argv[0];
	local[15]= fqv[22];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	argv[0]->c.obj.iv[6] = w;
	local[14]= argv[0]->c.obj.iv[6];
	local[15]= makeint(60);
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,2,local+14); /*-*/
	local[14]= w;
	local[15]= fqv[23];
	local[16]= T;
	local[17]= fqv[24];
	local[18]= T;
	local[19]= fqv[25];
	local[20]= NIL;
	local[21]= fqv[15];
	local[22]= local[1];
	local[23]= fqv[20];
	local[24]= argv[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,16,local+9); /*send*/
	w = local[8];
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	argv[0]->c.obj.iv[31] = w;
	if (local[2]==NIL) goto CON3495;
	argv[0]->c.obj.iv[28] = local[2];
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[93];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON3494;
CON3495:
	if (local[4]==NIL) goto CON3496;
	local[6]= NIL;
	goto CON3494;
CON3496:
	if (local[3]==NIL) goto CON3497;
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[30];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON3494;
CON3497:
	local[6]= NIL;
CON3494:
	w = argv[0];
	local[0]= w;
BLK3486:
	ctx->vsp=local; return(local[0]);}

/*:quit*/
static pointer M3498(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[94];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3499:
	ctx->vsp=local; return(local[0]);}

/*:finish*/
static pointer M3500(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= fqv[95];
	w = argv[0];
	ctx->vsp=local+4;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3501:
	ctx->vsp=local; return(local[0]);}

/*:print*/
static pointer M3502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= NIL;
	if (argv[0]->c.obj.iv[28]!=NIL) goto IF3504;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= fqv[96];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[4] = w;
	local[5]= NIL;
	local[6]= fqv[97];
	local[7]= argv[0];
	local[8]= fqv[98];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)GETPID(ctx,0,local+8); /*unix:getpid*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[99];
	local[7]= fqv[100];
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,3,local+5,&ftab[13],fqv[101]); /*open*/
	local[5]= w;
	ctx->vsp=local+6;
	w = makeclosure(codevec,quotevec,UWP3506,env,argv,local);
	local[6]=(pointer)(ctx->protfp); local[7]=w;
	ctx->protfp=(struct protectframe *)(local+6);
	local[8]= makeint(0);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
WHL3508:
	local[10]= local[8];
	w = local[9];
	if ((integer_t)local[10] >= (integer_t)w) goto WHX3509;
	local[10]= local[5];
	local[11]= fqv[102];
	local[12]= local[4];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL3508;
WHX3509:
	local[10]= NIL;
BLK3510:
	w = NIL;
	ctx->vsp=local+8;
	UWP3506(ctx,0,local+8,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[5]= w;
	goto IF3505;
IF3504:
	local[5]= NIL;
IF3505:
	local[5]= NIL;
	local[6]= fqv[103];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[33]); /*namestring*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SYSTEM(ctx,1,local+5); /*unix:system*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3503:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M3511(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= fqv[104];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(0);
TAG3515:
	local[7]= local[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)GREQP(ctx,2,local+7); /*>=*/
	if (w!=NIL) goto OR3518;
	if (local[4]!=NIL) goto OR3518;
	goto IF3516;
OR3518:
	w = NIL;
	ctx->vsp=local+7;
	local[6]=w;
	goto BLK3514;
	goto IF3517;
IF3516:
	local[7]= NIL;
IF3517:
	local[7]= local[3];
	local[8]= argv[0]->c.obj.iv[31];
	local[9]= fqv[105];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[14])(ctx,2,local+7,&ftab[14],fqv[106]); /*substringp*/
	if (w==NIL) goto IF3519;
	local[4] = local[6];
	local[7]= local[4];
	goto IF3520;
IF3519:
	local[7]= NIL;
IF3520:
	local[7]= (pointer)((integer_t)(local[6])+4);
	local[6] = local[7];
	w = NIL;
	ctx->vsp=local+7;
	goto TAG3515;
	w = NIL;
	local[6]= w;
BLK3514:
	if (local[4]==NIL) goto IF3522;
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[107];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[108];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF3523;
IF3522:
	local[6]= NIL;
IF3523:
	w = local[6];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3512:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3524(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[63];
	local[2]= argv[2];
	local[3]= makeint(10);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= makeint(38);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3525:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3530;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3530;
	goto IF3528;
OR3530:
	local[5]= argv[0];
	local[6]= fqv[63];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3529;
IF3528:
	local[5]= NIL;
IF3529:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3527:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP3506(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[5];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*ls-l*/
static pointer F3412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT3533;}
	local[0]= fqv[109];
ENT3533:
ENT3532:
	if (n>1) maerror();
	local[1]= fqv[110];
	local[2]= fqv[111];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[33]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,3,local+1,&ftab[15],fqv[112]); /*piped-fork*/
	local[1]= w;
	local[2]= NIL;
	w = NIL;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[1];
	local[9]= NIL;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)READLINE(ctx,3,local+8); /*read-line*/
WHL3534:
	local[8]= local[1];
	local[9]= NIL;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)READLINE(ctx,3,local+8); /*read-line*/
	local[5] = w;
	local[8]= local[5];
	if (local[2]==local[8]) goto WHX3535;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= makeint(32);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,2,local+8,&ftab[3],fqv[45]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto IF3537;
	local[8]= local[5];
	local[9]= makeint(0);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	goto IF3538;
IF3537:
	local[8]= fqv[113];
IF3538:
	local[3] = local[8];
	if (local[6]==NIL) goto IF3539;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,2,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	goto IF3540;
IF3539:
	local[8]= fqv[114];
IF3540:
	local[5] = local[8];
	local[8]= NIL;
	local[9]= fqv[115];
	local[10]= local[3];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	goto WHL3534;
WHX3535:
	local[8]= NIL;
BLK3536:
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)CLOSE(ctx,1,local+8); /*close*/
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[0]= w;
BLK3531:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3541(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3543:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[39]));
	local[4]= fqv[19];
	local[5]= fqv[21];
	local[6]= makeint(400);
	local[7]= fqv[22];
	local[8]= makeint(260);
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[116]);
	local[11]= fqv[117];
	local[12]= fqv[118];
	local[13]= fqv[25];
	local[14]= NIL;
	local[15]= fqv[40];
	local[16]= NIL;
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,17,local+1); /*apply*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[119];
	local[5]= argv[0];
	local[6]= fqv[84];
	local[7]= fqv[15];
	local[8]= loadglobal(fqv[116]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[120];
	local[5]= argv[0];
	local[6]= fqv[121];
	local[7]= fqv[15];
	local[8]= loadglobal(fqv[116]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[1]= argv[0]->c.obj.iv[25];
	local[2]= fqv[122];
	local[3]= makeint(70);
	local[4]= makeint(200);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[122];
	local[3]= makeint(270);
	local[4]= makeint(200);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK3542:
	ctx->vsp=local; return(local[0]);}

/*:draw-message*/
static pointer M3544(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(20);
	local[1]= makeint(50);
	local[2]= argv[0];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[28];
WHL3547:
	if (local[3]==NIL) goto WHX3548;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[123];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= local[1];
	local[5]= makeint(30);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[1] = w;
	goto WHL3547;
WHX3548:
	local[4]= NIL;
BLK3549:
	w = NIL;
	local[0]= w;
BLK3545:
	ctx->vsp=local; return(local[0]);}

/*:ask*/
static pointer M3551(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST3553:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	argv[0]->c.obj.iv[27] = NIL;
	argv[0]->c.obj.iv[28] = local[0];
	local[1]= argv[0];
	local[2]= fqv[124];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[0]->c.obj.iv[29] = argv[2];
	argv[0]->c.obj.iv[30] = argv[3];
	w = argv[0];
	local[0]= w;
BLK3552:
	ctx->vsp=local; return(local[0]);}

/*:yes*/
static pointer M3554(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	argv[0]->c.obj.iv[27] = fqv[84];
	local[3]= argv[0];
	local[4]= fqv[125];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= fqv[84];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3555:
	ctx->vsp=local; return(local[0]);}

/*:no*/
static pointer M3556(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	argv[0]->c.obj.iv[27] = fqv[121];
	local[3]= argv[0];
	local[4]= fqv[125];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3557:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3558(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= loadglobal(fqv[48]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,1,local+3,&ftab[16],fqv[126]); /*event-width*/
	local[3]= w;
	local[4]= loadglobal(fqv[48]);
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,1,local+4,&ftab[17],fqv[127]); /*event-height*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3562;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3562;
	goto IF3560;
OR3562:
	local[5]= argv[0];
	local[6]= fqv[124];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	goto IF3561;
IF3560:
	local[5]= NIL;
IF3561:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3559:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3563(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3565:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[39]));
	local[4]= fqv[19];
	local[5]= fqv[21];
	local[6]= makeint(300);
	local[7]= fqv[22];
	local[8]= makeint(300);
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[128]);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,11,local+1); /*apply*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[129];
	local[5]= argv[0];
	local[6]= fqv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[130];
	local[5]= argv[0];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[131];
	local[5]= argv[0];
	local[6]= fqv[132];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[27] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[133];
	local[5]= argv[0];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[135];
	local[5]= argv[0];
	local[6]= fqv[136];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[29] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[137];
	local[5]= argv[0];
	local[6]= fqv[138];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[30] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[139];
	local[5]= argv[0];
	local[6]= fqv[140];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[34] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[141];
	local[5]= argv[0];
	local[6]= fqv[142];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[35] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[143]);
	local[4]= fqv[144];
	local[5]= argv[0];
	local[6]= fqv[145];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[143]);
	local[4]= fqv[146];
	local[5]= argv[0];
	local[6]= fqv[147];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[32] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[143]);
	local[4]= fqv[148];
	local[5]= argv[0];
	local[6]= fqv[149];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[33] = w;
	local[1]= makeflt(2.99999952e-01);
	local[2]= makeflt(3.99999976e-01);
	local[3]= makeflt(5.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[36] = w;
	local[1]= makeflt(5.00000000e-01);
	local[2]= makeflt(3.99999976e-01);
	local[3]= makeflt(2.99999952e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[37] = w;
	local[1]= makeflt(1.99999988e-01);
	local[2]= makeflt(1.99999988e-01);
	local[3]= makeflt(1.99999988e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[38] = w;
	local[1]= makeflt(9.99999940e-02);
	local[2]= makeflt(9.99999940e-02);
	local[3]= makeflt(9.99999940e-02);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[39] = w;
	argv[0]->c.obj.iv[40] = makeflt(1.00000000e+01);
	argv[0]->c.obj.iv[41] = makeflt(0.00000000e+00);
	argv[0]->c.obj.iv[42] = NIL;
	argv[0]->c.obj.iv[43] = NIL;
	w = argv[0];
	local[0]= w;
BLK3564:
	ctx->vsp=local; return(local[0]);}

/*:init-value*/
static pointer M3566(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[36] = w;
	local[0]= argv[2];
	local[1]= fqv[134];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[37] = w;
	local[0]= argv[2];
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[38] = w;
	local[0]= argv[2];
	local[1]= fqv[138];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[39] = w;
	local[0]= argv[2];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[40] = w;
	local[0]= argv[2];
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[41] = w;
	w = NIL;
	local[0]= w;
BLK3567:
	ctx->vsp=local; return(local[0]);}

/*:value1*/
static pointer M3568(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
BLK3569:
	ctx->vsp=local; return(local[0]);}

/*:value2*/
static pointer M3570(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
BLK3571:
	ctx->vsp=local; return(local[0]);}

/*:value3*/
static pointer M3572(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
BLK3573:
	ctx->vsp=local; return(local[0]);}

/*:ambient*/
static pointer M3574(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[36];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[36];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[36];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3575:
	ctx->vsp=local; return(local[0]);}

/*:diffuse*/
static pointer M3576(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[37];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[37];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[37];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3577:
	ctx->vsp=local; return(local[0]);}

/*:specular*/
static pointer M3578(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[38];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[38];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[38];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3579:
	ctx->vsp=local; return(local[0]);}

/*:emission*/
static pointer M3580(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[39];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[39];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[39];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3581:
	ctx->vsp=local; return(local[0]);}

/*:shininess*/
static pointer M3582(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[40];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3583:
	ctx->vsp=local; return(local[0]);}

/*:transparency*/
static pointer M3584(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[41];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3585:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3586(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3588:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[150], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3589;
	local[1] = makeint(350);
KEY3589:
	if (n & (1<<1)) goto KEY3590;
	local[2] = makeint(500);
KEY3590:
	local[3]= (pointer)get_sym_func(fqv[38]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[39]));
	local[6]= fqv[19];
	local[7]= fqv[21];
	local[8]= local[1];
	local[9]= fqv[22];
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,9,local+3); /*apply*/
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[12]);
	local[6]= fqv[151];
	local[7]= argv[0];
	local[8]= fqv[152];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[16]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[12]);
	local[6]= fqv[153];
	local[7]= argv[0];
	local[8]= fqv[154];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[16]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[1]);
	local[6]= fqv[155];
	local[7]= argv[0];
	local[8]= fqv[156];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[116]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[1]);
	local[6]= fqv[157];
	local[7]= argv[0];
	local[8]= fqv[158];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[116]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[27] = w;
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[19];
	local[6]= fqv[20];
	local[7]= argv[0];
	local[8]= fqv[21];
	local[9]= argv[0];
	local[10]= fqv[21];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[22];
	local[11]= argv[0];
	local[12]= fqv[22];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= makeint(120);
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= fqv[159];
	local[13]= makeint(120);
	local[14]= fqv[15];
	local[15]= loadglobal(fqv[16]);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[29] = w;
	local[3]= loadglobal(fqv[160]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[19];
	local[6]= fqv[21];
	local[7]= local[1];
	local[8]= fqv[22];
	local[9]= makeint(60);
	local[10]= fqv[159];
	local[11]= makeint(60);
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	local[14]= fqv[20];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[30] = w;
	local[3]= argv[0]->c.obj.iv[30];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,1,local+3,&ftab[18],fqv[161]); /*make-textwindow-stream*/
	argv[0]->c.obj.iv[31] = w;
	w = argv[0];
	local[0]= w;
BLK3587:
	ctx->vsp=local; return(local[0]);}

/*:update-method-names*/
static pointer M3593(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3596;}
	local[0]= argv[0]->c.obj.iv[33];
ENT3596:
ENT3595:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[35]);
	local[2]= (pointer)get_sym_func(fqv[162]);
	local[3]= local[0];
	local[4]= fqv[163];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	argv[0]->c.obj.iv[36] = w;
	local[1]= argv[0]->c.obj.iv[36];
	storeglobal(fqv[164],local[1]);
	local[1]= *(ovafptr(argv[0]->c.obj.iv[29],fqv[165]));
	local[2]= fqv[30];
	local[3]= argv[0]->c.obj.iv[36];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3594:
	ctx->vsp=local; return(local[0]);}

/*:set-object*/
static pointer M3597(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[77]); /*read-from-string*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON3600;
	local[0]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0];
	local[1]= fqv[154];
	local[2]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	argv[0]->c.obj.iv[33] = w;
	local[2]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[166];
	local[2]= argv[0]->c.obj.iv[32];
	local[3]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto CON3599;
CON3600:
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[167];
	local[2]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON3599;
CON3601:
	local[0]= NIL;
CON3599:
	w = local[0];
	local[0]= w;
BLK3598:
	ctx->vsp=local; return(local[0]);}

/*:set-class*/
static pointer M3602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w!=NIL) goto CON3605;
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[77]); /*read-from-string*/
	argv[0]->c.obj.iv[33] = w;
	local[0]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto IF3606;
	local[0]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0]->c.obj.iv[33] = w;
	local[0]= argv[0]->c.obj.iv[33];
	goto IF3607;
IF3606:
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[168];
	local[2]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF3607:
	goto CON3604;
CON3605:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w==NIL) goto CON3608;
	argv[0]->c.obj.iv[33] = argv[2];
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[32];
	local[2]= NIL;
	local[3]= fqv[169];
	local[4]= argv[0]->c.obj.iv[33];
	local[5]= fqv[98];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3604;
CON3608:
	local[0]= NIL;
CON3604:
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[33];
	local[3]= fqv[98];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,1,local+2,&ftab[19],fqv[35]); /*string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[33];
	local[1]= argv[0]->c.obj.iv[33];
	local[2]= fqv[170];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[34] = cons(ctx,local[0],w);
	local[0]= argv[0];
	local[1]= fqv[171];
	local[2]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3603:
	ctx->vsp=local; return(local[0]);}

/*:set-superclass*/
static pointer M3609(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[33];
	local[1]= argv[0]->c.obj.iv[34];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[172]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (local[0]==NIL) goto IF3611;
	argv[0]->c.obj.iv[33] = local[0];
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[32];
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[98];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,1,local+3,&ftab[19],fqv[35]); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[171];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3612;
IF3611:
	local[1]= NIL;
IF3612:
	w = local[1];
	local[0]= w;
BLK3610:
	ctx->vsp=local; return(local[0]);}

/*:set-subclass*/
static pointer M3613(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[34];
WHL3615:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3616;
	local[1]= argv[0]->c.obj.iv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w!=NIL) goto WHX3616;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	goto WHL3615;
WHX3616:
	local[1]= NIL;
BLK3617:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF3618;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[33] = (w)->c.cons.car;
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[32];
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[98];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,1,local+3,&ftab[19],fqv[35]); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[171];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3619;
IF3618:
	local[1]= NIL;
IF3619:
	w = local[1];
	w = argv[0]->c.obj.iv[33];
	local[0]= w;
BLK3614:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xapplwin(ctx,n,argv,env)
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
	local[0]= fqv[173];
	local[1]= fqv[174];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[175]); /*require*/
	local[0]= fqv[176];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[177];
	local[1]= fqv[178];
	local[2]= fqv[177];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[182];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3413,fqv[42],fqv[177],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3415,fqv[43],fqv[177],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3418,fqv[19],fqv[177],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3425,fqv[46],fqv[177],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3427,fqv[28],fqv[177],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3431,fqv[49],fqv[177],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3435,fqv[11],fqv[177],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3440,fqv[3],fqv[177],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3444,fqv[5],fqv[177],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3448,fqv[7],fqv[177],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3452,fqv[9],fqv[177],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3454,fqv[63],fqv[177],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3456,fqv[200],fqv[177],fqv[201]);
	local[0]= fqv[202];
	local[1]= fqv[178];
	local[2]= fqv[202];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[177]);
	local[5]= fqv[181];
	local[6]= fqv[203];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3461,fqv[42],fqv[202],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3463,fqv[19],fqv[202],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3467,fqv[66],fqv[202],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3469,fqv[74],fqv[202],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3471,fqv[70],fqv[202],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3475,fqv[72],fqv[202],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3479,fqv[68],fqv[202],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3481,fqv[81],fqv[202],fqv[211]);
	local[0]= fqv[51];
	local[1]= fqv[178];
	local[2]= fqv[51];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[212];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3485,fqv[19],fqv[51],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3498,fqv[88],fqv[51],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3500,fqv[215],fqv[51],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3502,fqv[70],fqv[51],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3511,fqv[91],fqv[51],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3524,fqv[63],fqv[51],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3526,fqv[200],fqv[51],fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F3412,fqv[222]);
	local[0]= fqv[75];
	local[1]= fqv[178];
	local[2]= fqv[75];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[223];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3541,fqv[19],fqv[75],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3544,fqv[124],fqv[75],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3551,fqv[80],fqv[75],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3554,fqv[84],fqv[75],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3556,fqv[121],fqv[75],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3558,fqv[200],fqv[75],fqv[229]);
	local[0]= fqv[230];
	local[1]= fqv[178];
	local[2]= fqv[230];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[231];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3563,fqv[19],fqv[230],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3566,fqv[233],fqv[230],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3568,fqv[145],fqv[230],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3570,fqv[147],fqv[230],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3572,fqv[149],fqv[230],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3574,fqv[132],fqv[230],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3576,fqv[134],fqv[230],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3578,fqv[136],fqv[230],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3580,fqv[138],fqv[230],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3582,fqv[140],fqv[230],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3584,fqv[142],fqv[230],fqv[243]);
	local[0]= fqv[244];
	local[1]= fqv[178];
	local[2]= fqv[244];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[245];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3586,fqv[19],fqv[244],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3593,fqv[171],fqv[244],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3597,fqv[152],fqv[244],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3602,fqv[154],fqv[244],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3609,fqv[158],fqv[244],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3613,fqv[156],fqv[244],fqv[251]);
	local[0]= fqv[252];
	local[1]= fqv[253];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[254]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<24; i++) ftab[i]=fcallx;
}
