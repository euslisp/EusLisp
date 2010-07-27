/* trans.c :  entry=trans */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "trans.h"
#pragma init (register_trans)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___trans();
extern pointer build_quote_vector();
static register_trans()
  { add_module_initializer("___trans", ___trans);}

static pointer F102();
static pointer F110();

/*c-stringize*/
static pointer F102(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*prin1-to-string*/
	local[0]= w;
	local[1]= NIL;
	local[2]= makeint(10);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,2,local+2,&ftab[1],fqv[1]); /*position*/
	if (w==NIL) goto CON153;
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL187:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX188;
	local[4]= local[0];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	local[5]= makeint(10);
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto IF196;
	local[4]= makeint(92);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= makeint(110);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF197;
IF196:
	local[4]= local[0];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
IF197:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL187;
WHX188:
	local[4]= NIL;
BLK189:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[2]= w;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	goto CON151;
CON153:
	local[2]= local[0];
	goto CON151;
CON267:
	local[2]= NIL;
CON151:
	w = local[2];
	local[0]= w;
BLK125:
	ctx->vsp=local; return(local[0]);}

/*ftab-index*/
static pointer F110(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	if (local[0]!=NIL) goto IF310;
	local[1]= argv[0];
	local[2]= loadglobal(fqv[4]);
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	local[2]= argv[0];
	w = loadglobal(fqv[5]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[5],local[2]);
	local[2]= (pointer)((integer_t)(loadglobal(fqv[4]))+4);
	storeglobal(fqv[4],local[2]);
	w = local[1];
	local[1]= w;
	goto IF311;
IF310:
	local[1]= local[0];
IF311:
	w = local[1];
	local[0]= w;
BLK285:
	ctx->vsp=local; return(local[0]);}

/*:label*/
static pointer M381(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[7];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK382:
	ctx->vsp=local; return(local[0]);}

/*:comment*/
static pointer M406(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST409:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[8];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
WHL426:
	if (local[0]==NIL) goto WHX427;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	goto WHL426;
WHX427:
	local[1]= NIL;
BLK428:
	local[1]= fqv[9];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[0]= w;
BLK407:
	ctx->vsp=local; return(local[0]);}

/*:pop*/
static pointer M480(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF493;
	local[0]= argv[0]->c.obj.iv[2];
	argv[0]->c.obj.iv[2] = NIL;
	w = local[0];
	local[0]= w;
	goto IF494;
IF493:
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])-4);
	local[0]= NIL;
	local[1]= fqv[10];
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF494:
	w = local[0];
	local[0]= w;
BLK481:
	ctx->vsp=local; return(local[0]);}

/*:store*/
static pointer M541(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto OR558;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto OR558;
	goto IF556;
OR558:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[11];
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF557;
IF556:
	argv[0]->c.obj.iv[2] = NIL;
	local[0]= argv[0]->c.obj.iv[2];
IF557:
	w = local[0];
	local[0]= w;
BLK542:
	ctx->vsp=local; return(local[0]);}

/*:push*/
static pointer M584(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[2] = argv[2];
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK585:
	ctx->vsp=local; return(local[0]);}

/*:clearpush*/
static pointer M612(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF626;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[13];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	local[0]= argv[0]->c.obj.iv[3];
	goto IF627;
IF626:
	local[0]= NIL;
IF627:
	argv[0]->c.obj.iv[2] = NIL;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK613:
	ctx->vsp=local; return(local[0]);}

/*:quote-entry*/
static pointer M674(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	w = argv[2];
	if (!issymbol(w)) goto CON700;
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	local[0] = memq(local[1],w);
	if (local[0]==NIL) goto CON700;
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0] = (pointer)((integer_t)local[1] - (integer_t)w);
	local[1]= local[0];
	goto CON698;
CON700:
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[0] = (pointer)((integer_t)(w)-4);
	local[1]= local[0];
	goto CON698;
CON732:
	local[1]= NIL;
CON698:
	w = local[0];
	local[0]= w;
BLK675:
	ctx->vsp=local; return(local[0]);}

/*:dupe*/
static pointer M777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto CON792;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[16];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON790;
CON792:
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[17];
	local[4]= (pointer)((integer_t)(argv[0]->c.obj.iv[3])-4);
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON790;
CON804:
	local[0]= NIL;
CON790:
	w = local[0];
	local[0]= w;
BLK778:
	ctx->vsp=local; return(local[0]);}

/*:discard*/
static pointer M825(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF841;
	argv[0]->c.obj.iv[2] = NIL;
	argv[2] = (pointer)((integer_t)(argv[2])-4);
	local[0]= argv[2];
	goto IF842;
IF841:
	local[0]= NIL;
IF842:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF868;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF869;
IF868:
	local[0]= NIL;
IF869:
	w = local[0];
	local[0]= w;
BLK826:
	ctx->vsp=local; return(local[0]);}

/*:adjust*/
static pointer M887(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK888:
	ctx->vsp=local; return(local[0]);}

/*:setpushcount*/
static pointer M913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[3] = argv[2];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK914:
	ctx->vsp=local; return(local[0]);}

/*:offset-from-fp*/
static pointer M935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK936:
	ctx->vsp=local; return(local[0]);}

/*:reset-vsp*/
static pointer M956(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[18];
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK957:
	ctx->vsp=local; return(local[0]);}

/*:bind-special*/
static pointer M973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[22];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK974:
	ctx->vsp=local; return(local[0]);}

/*:unbind-special*/
static pointer M1020(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK1021:
	ctx->vsp=local; return(local[0]);}

/*:pushenv*/
static pointer M1051(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1052:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M1081(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[3] = makeint(0);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[27];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[28];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK1082:
	ctx->vsp=local; return(local[0]);}

/*:check-req-arg*/
static pointer M1135(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1152;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto IF1153;
IF1152:
	local[0]= NIL;
IF1153:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1163;
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF1169;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[34];
	local[2]= argv[3];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1177;
	local[2]= fqv[35];
	goto IF1178;
IF1177:
	local[2]= fqv[36];
IF1178:
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF1170;
IF1169:
	local[0]= NIL;
IF1170:
	goto IF1164;
IF1163:
	local[0]= NIL;
IF1164:
	w = local[0];
	local[0]= w;
BLK1136:
	ctx->vsp=local; return(local[0]);}

/*:check-opt-arg*/
static pointer M1185(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[37];
	local[2]= (pointer)((integer_t)(argv[2])+4);
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK1186:
	ctx->vsp=local; return(local[0]);}

/*:check-rest-arg*/
static pointer M1212(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1227;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[38];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF1228;
IF1227:
	local[0]= NIL;
IF1228:
	w = local[0];
	local[0]= w;
BLK1213:
	ctx->vsp=local; return(local[0]);}

/*:rest*/
static pointer M1237(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[39];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1238:
	ctx->vsp=local; return(local[0]);}

/*:parse-key-params*/
static pointer M1272(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[40];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[3];
	if (argv[5]==NIL) goto IF1316;
	local[6]= makeint(1);
	goto IF1317;
IF1316:
	local[6]= makeint(0);
IF1317:
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,7,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1273:
	ctx->vsp=local; return(local[0]);}

/*:check-key-arg*/
static pointer M1335(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK1336:
	ctx->vsp=local; return(local[0]);}

/*:getbase*/
static pointer M1357(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON1376;
	if (argv[3]==NIL) goto IF1382;
	local[0]= fqv[42];
	goto IF1383;
IF1382:
	local[0]= fqv[43];
IF1383:
	goto CON1374;
CON1376:
	local[0]= fqv[44];
WHL1399:
	local[1]= argv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto WHX1400;
	local[1]= loadglobal(fqv[2]);
	local[2]= local[0];
	local[3]= fqv[45];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[0] = w;
	argv[2] = (pointer)((integer_t)(argv[2])-4);
	goto WHL1399;
WHX1400:
	local[1]= NIL;
BLK1401:
	local[1]= loadglobal(fqv[2]);
	local[2]= local[0];
	if (argv[3]==NIL) goto IF1433;
	local[3]= fqv[46];
	goto IF1434;
IF1433:
	local[3]= fqv[47];
IF1434:
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[0] = w;
	w = local[0];
	local[0]= w;
	goto CON1374;
CON1387:
	local[0]= NIL;
CON1374:
	w = local[0];
	local[0]= w;
BLK1358:
	ctx->vsp=local; return(local[0]);}

/*:load-t*/
static pointer M1447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1448:
	ctx->vsp=local; return(local[0]);}

/*:load-nil*/
static pointer M1465(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[49];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1466:
	ctx->vsp=local; return(local[0]);}

/*:load-int*/
static pointer M1483(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[50];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1484:
	ctx->vsp=local; return(local[0]);}

/*:load-float*/
static pointer M1506(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[51];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1507:
	ctx->vsp=local; return(local[0]);}

/*:load-quote*/
static pointer M1545(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[52];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1546:
	ctx->vsp=local; return(local[0]);}

/*:load-arg*/
static pointer M1589(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[53];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1590:
	ctx->vsp=local; return(local[0]);}

/*:load-local*/
static pointer M1622(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[56];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1623:
	ctx->vsp=local; return(local[0]);}

/*:load-obj*/
static pointer M1653(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[57];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1654:
	ctx->vsp=local; return(local[0]);}

/*:load-global*/
static pointer M1686(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[58];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1687:
	ctx->vsp=local; return(local[0]);}

/*:store-arg*/
static pointer M1714(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[59];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1715:
	ctx->vsp=local; return(local[0]);}

/*:store-local*/
static pointer M1747(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[60];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1748:
	ctx->vsp=local; return(local[0]);}

/*:store-obj*/
static pointer M1778(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[61];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1779:
	ctx->vsp=local; return(local[0]);}

/*:store-global*/
static pointer M1811(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[62];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK1812:
	ctx->vsp=local; return(local[0]);}

/*:load-ovaf*/
static pointer M1840(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[63];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[23];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1841:
	ctx->vsp=local; return(local[0]);}

/*:load-indexed-ov*/
static pointer M1873(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[64];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1874:
	ctx->vsp=local; return(local[0]);}

/*:store-ovaf*/
static pointer M1901(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[65];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[23];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1902:
	ctx->vsp=local; return(local[0]);}

/*:store-indexed-ov*/
static pointer M1934(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[66];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[67];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1935:
	ctx->vsp=local; return(local[0]);}

/*:call*/
static pointer M1963(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[68];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]!=NIL) goto IF2001;
	local[1]= argv[2];
	local[2]= fqv[69];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	local[1]= local[0];
	goto IF2002;
IF2001:
	local[1]= NIL;
IF2002:
	local[1]= argv[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (local[0]==NIL) goto IF2030;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[70];
	local[3]= local[0];
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[1]= w;
	goto IF2031;
IF2030:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[71];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F110(ctx,1,local+3); /*ftab-index*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F110(ctx,1,local+6); /*ftab-index*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[23];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,8,local+1); /*format*/
	local[1]= w;
IF2031:
	local[1]= argv[0];
	local[2]= fqv[72];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1964:
	ctx->vsp=local; return(local[0]);}

/*:call-closure*/
static pointer M2081(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[75];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[76];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2082:
	ctx->vsp=local; return(local[0]);}

/*:getfunc*/
static pointer M2132(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[77];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2133:
	ctx->vsp=local; return(local[0]);}

/*:1-*/
static pointer M2176(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[78];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2177:
	ctx->vsp=local; return(local[0]);}

/*:1+*/
static pointer M2201(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[79];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2202:
	ctx->vsp=local; return(local[0]);}

/*:check-cons-nil*/
static pointer M2226(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[80];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto IF2239;
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2240;
IF2239:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[81];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF2240:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[83];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2227:
	ctx->vsp=local; return(local[0]);}

/*:car*/
static pointer M2270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2283;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[85];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF2284;
IF2283:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2306;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2307;
IF2306:
	local[0]= NIL;
IF2307:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[87];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF2284:
	w = local[0];
	local[0]= w;
BLK2271:
	ctx->vsp=local; return(local[0]);}

/*:cdr*/
static pointer M2333(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2346;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[88];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF2347;
IF2346:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2368;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2369;
IF2368:
	local[0]= NIL;
IF2369:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[89];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF2347:
	w = local[0];
	local[0]= w;
BLK2334:
	ctx->vsp=local; return(local[0]);}

/*:caar*/
static pointer M2395(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2410;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[90];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2408;
CON2410:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2427;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[91];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[92];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2408;
CON2427:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[93];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2408;
CON2469:
	local[0]= NIL;
CON2408:
	w = local[0];
	local[0]= w;
BLK2396:
	ctx->vsp=local; return(local[0]);}

/*:cddr*/
static pointer M2485(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2500;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[94];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2498;
CON2500:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2517;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[95];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[96];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2498;
CON2517:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[97];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2498;
CON2559:
	local[0]= NIL;
CON2498:
	w = local[0];
	local[0]= w;
BLK2486:
	ctx->vsp=local; return(local[0]);}

/*:cdar*/
static pointer M2575(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2590;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[98];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2588;
CON2590:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2607;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[99];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[100];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2588;
CON2607:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[101];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2588;
CON2649:
	local[0]= NIL;
CON2588:
	w = local[0];
	local[0]= w;
BLK2576:
	ctx->vsp=local; return(local[0]);}

/*:cadr*/
static pointer M2665(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2680;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[102];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2678;
CON2680:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2697;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[103];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[104];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2678;
CON2697:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[105];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2678;
CON2739:
	local[0]= NIL;
CON2678:
	w = local[0];
	local[0]= w;
BLK2666:
	ctx->vsp=local; return(local[0]);}

/*:caddr*/
static pointer M2755(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2770;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[106];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2768;
CON2770:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2787;
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[107];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[108];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[109];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2768;
CON2787:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[110];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2768;
CON2848:
	local[0]= NIL;
CON2768:
	w = local[0];
	local[0]= w;
BLK2756:
	ctx->vsp=local; return(local[0]);}

/*:cons*/
static pointer M2864(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[111];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[112];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2865:
	ctx->vsp=local; return(local[0]);}

/*:svref*/
static pointer M2901(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[113];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[114];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2902:
	ctx->vsp=local; return(local[0]);}

/*:svset*/
static pointer M2949(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[116];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[117];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[118];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[119];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[120];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2950:
	ctx->vsp=local; return(local[0]);}

/*:char*/
static pointer M2995(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[121];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[122];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2996:
	ctx->vsp=local; return(local[0]);}

/*:setchar*/
static pointer M3043(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[124];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[125];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[126];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[128];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3044:
	ctx->vsp=local; return(local[0]);}

/*:bit*/
static pointer M3089(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[129];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[130];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[131];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3090:
	ctx->vsp=local; return(local[0]);}

/*:setbit*/
static pointer M3137(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[132];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[133];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[134];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[135];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[137];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3138:
	ctx->vsp=local; return(local[0]);}

/*:vref*/
static pointer M3187(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[138];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= local[1];
	if (fqv[139]!=local[2]) goto IF3239;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[140];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3240;
IF3239:
	local[2]= local[1];
	if (fqv[141]!=local[2]) goto IF3251;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[142];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3252;
IF3251:
	local[2]= local[1];
	if (fqv[143]!=local[2]) goto IF3263;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[144];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3264;
IF3263:
	local[2]= local[1];
	if (fqv[145]!=local[2]) goto IF3275;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[146];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3276;
IF3275:
	if (T==NIL) goto IF3287;
	local[2]= argv[0];
	local[3]= fqv[147];
	local[4]= fqv[148];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3288;
IF3287:
	local[2]= NIL;
IF3288:
IF3276:
IF3264:
IF3252:
IF3240:
	w = local[2];
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[149];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3188:
	ctx->vsp=local; return(local[0]);}

/*:vset*/
static pointer M3305(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[150];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[151];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[152];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[2];
	local[1]= local[0];
	if (fqv[139]!=local[1]) goto IF3357;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[153];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3358;
IF3357:
	local[1]= local[0];
	if (fqv[141]!=local[1]) goto IF3368;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[154];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3369;
IF3368:
	local[1]= local[0];
	if (fqv[143]!=local[1]) goto IF3379;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[155];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3380;
IF3379:
	local[1]= local[0];
	if (fqv[145]!=local[1]) goto IF3390;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[156];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3391;
IF3390:
	if (T==NIL) goto IF3401;
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= fqv[157];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3402;
IF3401:
	local[1]= NIL;
IF3402:
IF3391:
IF3380:
IF3369:
IF3358:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[158];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3306:
	ctx->vsp=local; return(local[0]);}

/*:nullx*/
static pointer M3418(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[159];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3419:
	ctx->vsp=local; return(local[0]);}

/*:eqx*/
static pointer M3443(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[160];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[12];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3444:
	ctx->vsp=local; return(local[0]);}

/*:memqx*/
static pointer M3473(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[161];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[162];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3474:
	ctx->vsp=local; return(local[0]);}

/*:type-check-predicate*/
static pointer M3504(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[163];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[164];
	local[4]= argv[2];
	local[5]= fqv[165];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[166]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3505:
	ctx->vsp=local; return(local[0]);}

/*:if-nil*/
static pointer M3542(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[167];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK3543:
	ctx->vsp=local; return(local[0]);}

/*:if-t*/
static pointer M3566(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[168];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK3567:
	ctx->vsp=local; return(local[0]);}

/*:if-eq*/
static pointer M3590(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[169];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK3591:
	ctx->vsp=local; return(local[0]);}

/*:if-neq*/
static pointer M3619(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[170];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK3620:
	ctx->vsp=local; return(local[0]);}

/*:int-op2*/
static pointer M3648(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = fqv[171];
	if (memq(local[0],w)==NIL) goto CON3665;
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[172];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	w = fqv[173];
	if (memq(local[0],w)==NIL) goto IF3683;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[174];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto IF3684;
IF3683:
	local[0]= NIL;
IF3684:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[175];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= fqv[176];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3663;
CON3665:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[178];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[179];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[2];
	local[4]= fqv[180];
	ctx->vsp=local+5;
	w=(pointer)ASSQ(ctx,2,local+3); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	local[0]= argv[0]->c.obj.iv[3];
	goto CON3663;
CON3721:
	local[0]= NIL;
CON3663:
	w = local[0];
	local[0]= w;
BLK3649:
	ctx->vsp=local; return(local[0]);}

/*:int-neg*/
static pointer M3767(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[181];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3768:
	ctx->vsp=local; return(local[0]);}

/*:int-abs*/
static pointer M3792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[182];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3793:
	ctx->vsp=local; return(local[0]);}

/*:flt-abs*/
static pointer M3817(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[183];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3818:
	ctx->vsp=local; return(local[0]);}

/*:compare*/
static pointer M3842(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[3];
	if (fqv[184]!=local[0]) goto CON3863;
	local[0]= argv[0];
	local[1]= fqv[185];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3861;
CON3863:
	local[0]= argv[3];
	if (fqv[186]!=local[0]) goto CON3876;
	local[0]= argv[0];
	local[1]= fqv[187];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3861;
CON3876:
	local[0]= argv[2];
	if (fqv[188]!=local[0]) goto CON3889;
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[189];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[190];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
	goto CON3861;
CON3889:
	local[0]= argv[2];
	if (fqv[143]!=local[0]) goto CON3912;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[191];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[192];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[193];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto CON3861;
CON3912:
	local[0]= argv[0];
	local[1]= fqv[147];
	local[2]= fqv[194];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3861;
CON3942:
	local[0]= NIL;
CON3861:
	w = local[0];
	local[0]= w;
BLK3843:
	ctx->vsp=local; return(local[0]);}

/*:flt-op2*/
static pointer M3951(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[195];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[196];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[197];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[2];
	local[4]= fqv[198];
	ctx->vsp=local+5;
	w=(pointer)ASSQ(ctx,2,local+3); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK3952:
	ctx->vsp=local; return(local[0]);}

/*:flt-neg*/
static pointer M4009(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[199];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4010:
	ctx->vsp=local; return(local[0]);}

/*:type-checker*/
static pointer M4034(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[200];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK4035:
	ctx->vsp=local; return(local[0]);}

/*:if-type*/
static pointer M4059(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[201];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[202];
	local[2]= argv[0];
	local[3]= fqv[203];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK4060:
	ctx->vsp=local; return(local[0]);}

/*:if-not-type*/
static pointer M4092(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[204];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[205];
	local[2]= argv[0];
	local[3]= fqv[203];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK4093:
	ctx->vsp=local; return(local[0]);}

/*:jump*/
static pointer M4125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[206];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK4126:
	ctx->vsp=local; return(local[0]);}

/*:return*/
static pointer M4150(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[207];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])-4);
	local[0]= argv[0]->c.obj.iv[3];
	if (makeint(0)==local[0]) goto IF4173;
	local[0]= fqv[208];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[209]); /*warn*/
	local[0]= w;
	goto IF4174;
IF4173:
	local[0]= NIL;
IF4174:
	w = local[0];
	local[0]= w;
BLK4151:
	ctx->vsp=local; return(local[0]);}

/*:del-frame*/
static pointer M4192(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[210];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= makeint(3);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[211];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4193:
	ctx->vsp=local; return(local[0]);}

/*:entercatch*/
static pointer M4232(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[215];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(6);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4233:
	ctx->vsp=local; return(local[0]);}

/*:exitcatch*/
static pointer M4282(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[216];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[217];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[218];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[219];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(6);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[220];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4283:
	ctx->vsp=local; return(local[0]);}

/*:throw*/
static pointer M4333(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[221];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[222];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[223];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK4334:
	ctx->vsp=local; return(local[0]);}

/*:bind-cleaner*/
static pointer M4365(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[224];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[225];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4366:
	ctx->vsp=local; return(local[0]);}

/*:call-cleaner*/
static pointer M4404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[226];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[227];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[228];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[229];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4405:
	ctx->vsp=local; return(local[0]);}

/*:return-from*/
static pointer M4456(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[230];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (argv[3]==NIL) goto IF4485;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[231];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF4486;
IF4485:
	local[0]= NIL;
IF4486:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[232];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4457:
	ctx->vsp=local; return(local[0]);}

/*:go-tag*/
static pointer M4512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (argv[3]==NIL) goto IF4535;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[233];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF4536;
IF4535:
	local[0]= NIL;
IF4536:
	argv[0]->c.obj.iv[3] = (pointer)((integer_t)(argv[0]->c.obj.iv[3])+4);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4513:
	ctx->vsp=local; return(local[0]);}

/*:closure*/
static pointer M4557(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[234];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4558:
	ctx->vsp=local; return(local[0]);}

/*:defun*/
static pointer M4592(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[235];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK4593:
	ctx->vsp=local; return(local[0]);}

/*:defmacro*/
static pointer M4639(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[236];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK4640:
	ctx->vsp=local; return(local[0]);}

/*:quote-fqv-entry*/
static pointer M4686(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto IF4701;
	local[0]= fqv[237];
	goto IF4702;
IF4701:
	local[0]= NIL;
	local[1]= fqv[238];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF4702:
	w = local[0];
	local[0]= w;
BLK4687:
	ctx->vsp=local; return(local[0]);}

/*:defmethod*/
static pointer M4715(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[239];
	local[2]= argv[4];
	local[3]= argv[0];
	local[4]= fqv[23];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[240];
	local[7]= argv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK4716:
	ctx->vsp=local; return(local[0]);}

/*:declare-forward-function*/
static pointer M4770(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[241];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK4771:
	ctx->vsp=local; return(local[0]);}

/*:quote*/
static pointer M4789(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK4790:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[2] = NIL;
	argv[0]->c.obj.iv[3] = makeint(0);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4805:
	ctx->vsp=local; return(local[0]);}

/*:init-file*/
static pointer M4825(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[3];
	local[1]= fqv[242];
	local[2]= fqv[243];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,3,local+0,&ftab[4],fqv[244]); /*open*/
	argv[0]->c.obj.iv[0] = w;
	local[0]= argv[4];
	local[1]= fqv[242];
	local[2]= fqv[243];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,3,local+0,&ftab[4],fqv[244]); /*open*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[4] = NIL;
	storeglobal(fqv[5],NIL);
	local[0]= makeint(0);
	storeglobal(fqv[4],local[0]);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[245];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[246]); /*namestring*/
	local[2]= w;
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[247];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,0,local+2,&ftab[6],fqv[248]); /*lisp-implementation-version*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[249];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[250];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[246]); /*namestring*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[251];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[253];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[254];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= loadglobal(fqv[84]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON4920;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[255];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[256];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto CON4918;
CON4920:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[257];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto CON4918;
CON4932:
	local[0]= NIL;
CON4918:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[258];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= fqv[259];
	w = loadglobal(fqv[260]);
	if (memq(local[0],w)==NIL) goto IF4944;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[261];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF4945;
IF4944:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[262];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF4945:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[263];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[264];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[265];
	local[2]= loadglobal(fqv[2]);
	local[3]= fqv[266];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,1,local+4,&ftab[7],fqv[267]); /*pathname-name*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[2]= w;
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= NIL;
	local[1]= loadglobal(fqv[268]);
WHL5004:
	if (local[1]==NIL) goto WHX5005;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[269];
	local[4]= local[0];
	local[5]= fqv[68];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	goto WHL5004;
WHX5005:
	local[2]= NIL;
BLK5006:
	w = NIL;
	local[0]= w;
BLK4826:
	ctx->vsp=local; return(local[0]);}

/*:eusmain*/
static pointer M5064(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[270];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[271];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[272];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[273];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[274];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[275];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[276];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[277];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[278];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK5065:
	ctx->vsp=local; return(local[0]);}

/*:write-quote-vector*/
static pointer M5115(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[279];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[280];
	local[2]= fqv[281];
	w = loadglobal(fqv[260]);
	if (memq(local[2],w)==NIL) goto IF5137;
	local[2]= fqv[282];
	goto IF5138;
IF5137:
	local[2]= fqv[283];
IF5138:
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL5167:
	if (local[1]==NIL) goto WHX5168;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*prin1-to-string*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[284];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= makeint(0);
	local[6]= local[3];
WHL5261:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX5262;
	local[7]= local[2];
	{ register integer_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= makeint(92);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON5272;
	local[7]= makeint(92);
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= makeint(92);
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= w;
	goto CON5270;
CON5272:
	local[7]= local[2];
	{ register integer_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= makeint(34);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON5290;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[285];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON5270;
CON5290:
	local[7]= local[2];
	{ register integer_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= makeint(10);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON5304;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[286];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON5270;
CON5304:
	local[7]= local[2];
	{ register integer_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= w;
	goto CON5270;
CON5318:
	local[7]= NIL;
CON5270:
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL5261;
WHX5262:
	local[7]= NIL;
BLK5263:
	w = NIL;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[287];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	goto WHL5167;
WHX5168:
	local[2]= NIL;
BLK5169:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[288];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK5116:
	ctx->vsp=local; return(local[0]);}

/*:declare-ftab*/
static pointer M5355(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[4]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF5368;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[289];
	local[2]= loadglobal(fqv[4]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF5369;
IF5368:
	local[0]= NIL;
IF5369:
	w = local[0];
	local[0]= w;
BLK5356:
	ctx->vsp=local; return(local[0]);}

/*:ftab-initializer*/
static pointer M5378(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[290];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= loadglobal(fqv[4]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF5396;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[291];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[292];
	local[2]= loadglobal(fqv[4]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF5397;
IF5396:
	local[0]= NIL;
IF5397:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[293];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= NIL;
	local[1]= loadglobal(fqv[5]);
WHL5435:
	if (local[1]==NIL) goto WHX5436;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,2,local+2,&ftab[8],fqv[294]); /*remprop*/
	goto WHL5435;
WHX5436:
	local[2]= NIL;
BLK5437:
	w = NIL;
	local[0]= w;
BLK5379:
	ctx->vsp=local; return(local[0]);}

/*:close*/
static pointer M5493(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
BLK5494:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___trans(ctx,n,argv,env)
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
	local[0]= fqv[295];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5522;
	local[0]= fqv[296];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[297],w);
	goto IF5523;
IF5522:
	local[0]= fqv[298];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5523:
	local[0]= fqv[299];
	local[1]= fqv[300];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF5540;
	local[0]= fqv[299];
	local[1]= fqv[300];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[299];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF5563;
	local[0]= fqv[299];
	local[1]= fqv[301];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF5564;
IF5563:
	local[0]= NIL;
IF5564:
	local[0]= fqv[299];
	goto IF5541;
IF5540:
	local[0]= NIL;
IF5541:
	ctx->vsp=local+0;
	compfun(ctx,fqv[302],module,F102,fqv[303]);
	local[0]= fqv[304];
	local[1]= fqv[301];
	local[2]= fqv[304];
	local[3]= fqv[305];
	local[4]= loadglobal(fqv[306]);
	local[5]= fqv[307];
	local[6]= fqv[308];
	local[7]= fqv[309];
	local[8]= NIL;
	local[9]= fqv[310];
	local[10]= NIL;
	local[11]= fqv[311];
	local[12]= makeint(-1);
	local[13]= fqv[312];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[9])(ctx,13,local+2,&ftab[9],fqv[313]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[301];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[5];
	local[1]= fqv[301];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[314],module,F110,fqv[315]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M381,fqv[217],fqv[304],fqv[316]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M406,fqv[26],fqv[304],fqv[317]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M480,fqv[12],fqv[304],fqv[318]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M541,fqv[19],fqv[304],fqv[319]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M584,fqv[15],fqv[304],fqv[320]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M612,fqv[6],fqv[304],fqv[321]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M674,fqv[23],fqv[304],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M777,fqv[323],fqv[304],fqv[324]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M825,fqv[72],fqv[304],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M887,fqv[326],fqv[304],fqv[327]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M913,fqv[328],fqv[304],fqv[329]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M935,fqv[330],fqv[304],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M956,fqv[21],fqv[304],fqv[332]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M973,fqv[333],fqv[304],fqv[334]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1020,fqv[335],fqv[304],fqv[336]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1051,fqv[337],fqv[304],fqv[338]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1081,fqv[339],fqv[304],fqv[340]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1135,fqv[341],fqv[304],fqv[342]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1185,fqv[343],fqv[304],fqv[344]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1212,fqv[345],fqv[304],fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1237,fqv[347],fqv[304],fqv[348]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1272,fqv[349],fqv[304],fqv[350]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1335,fqv[351],fqv[304],fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1357,fqv[54],fqv[304],fqv[353]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1447,fqv[354],fqv[304],fqv[355]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1465,fqv[356],fqv[304],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1483,fqv[358],fqv[304],fqv[359]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1506,fqv[360],fqv[304],fqv[361]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1545,fqv[362],fqv[304],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1589,fqv[364],fqv[304],fqv[365]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1622,fqv[366],fqv[304],fqv[367]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1653,fqv[368],fqv[304],fqv[369]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1686,fqv[370],fqv[304],fqv[371]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1714,fqv[372],fqv[304],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1747,fqv[374],fqv[304],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1778,fqv[376],fqv[304],fqv[377]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1811,fqv[378],fqv[304],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1840,fqv[380],fqv[304],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1873,fqv[382],fqv[304],fqv[383]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1901,fqv[384],fqv[304],fqv[385]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1934,fqv[386],fqv[304],fqv[387]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1963,fqv[388],fqv[304],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2081,fqv[390],fqv[304],fqv[391]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2132,fqv[392],fqv[304],fqv[393]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2176,fqv[394],fqv[304],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2201,fqv[396],fqv[304],fqv[397]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2226,fqv[86],fqv[304],fqv[398]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2270,fqv[399],fqv[304],fqv[400]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2333,fqv[401],fqv[304],fqv[402]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2395,fqv[403],fqv[304],fqv[404]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2485,fqv[405],fqv[304],fqv[406]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2575,fqv[407],fqv[304],fqv[408]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2665,fqv[409],fqv[304],fqv[410]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2755,fqv[411],fqv[304],fqv[412]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2864,fqv[413],fqv[304],fqv[414]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2901,fqv[415],fqv[304],fqv[416]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2949,fqv[417],fqv[304],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2995,fqv[419],fqv[304],fqv[420]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3043,fqv[421],fqv[304],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3089,fqv[423],fqv[304],fqv[424]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3137,fqv[425],fqv[304],fqv[426]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3187,fqv[427],fqv[304],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3305,fqv[429],fqv[304],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3418,fqv[431],fqv[304],fqv[432]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3443,fqv[433],fqv[304],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3473,fqv[435],fqv[304],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3504,fqv[437],fqv[304],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3542,fqv[439],fqv[304],fqv[440]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3566,fqv[441],fqv[304],fqv[442]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3590,fqv[187],fqv[304],fqv[443]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3619,fqv[185],fqv[304],fqv[444]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3648,fqv[445],fqv[304],fqv[446]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3767,fqv[447],fqv[304],fqv[448]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3792,fqv[449],fqv[304],fqv[450]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3817,fqv[451],fqv[304],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3842,fqv[453],fqv[304],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3951,fqv[455],fqv[304],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4009,fqv[457],fqv[304],fqv[458]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4034,fqv[203],fqv[304],fqv[459]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4059,fqv[460],fqv[304],fqv[461]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4092,fqv[462],fqv[304],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4125,fqv[464],fqv[304],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4150,fqv[466],fqv[304],fqv[467]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4192,fqv[468],fqv[304],fqv[469]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4232,fqv[470],fqv[304],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4282,fqv[472],fqv[304],fqv[473]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4333,fqv[474],fqv[304],fqv[475]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4365,fqv[476],fqv[304],fqv[477]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4404,fqv[478],fqv[304],fqv[479]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4456,fqv[480],fqv[304],fqv[481]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4512,fqv[482],fqv[304],fqv[483]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4557,fqv[484],fqv[304],fqv[485]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4592,fqv[486],fqv[304],fqv[487]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4639,fqv[488],fqv[304],fqv[489]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4686,fqv[240],fqv[304],fqv[490]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4715,fqv[491],fqv[304],fqv[492]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4770,fqv[493],fqv[304],fqv[494]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4789,fqv[495],fqv[304],fqv[496]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4804,fqv[497],fqv[304],fqv[498]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4825,fqv[499],fqv[304],fqv[500]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5064,fqv[501],fqv[304],fqv[502]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5115,fqv[503],fqv[304],fqv[504]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5355,fqv[505],fqv[304],fqv[506]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5378,fqv[507],fqv[304],fqv[508]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5493,fqv[509],fqv[304],fqv[510]);
	local[0]= loadglobal(fqv[304]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	storeglobal(fqv[299],w);
	local[0]= fqv[511];
	local[1]= fqv[512];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[513]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
