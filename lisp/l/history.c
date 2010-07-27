/* history.c :  entry=history */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "history.h"
#pragma init (register_history)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___history();
extern pointer build_quote_vector();
static register_history()
  { add_module_initializer("___history", ___history);}

static pointer F72806();
static pointer F72807();
static pointer F72808();
static pointer F72809();
static pointer F72810();
static pointer F72811();
static pointer F72812();
static pointer F72813();
static pointer F72814();
static pointer F72815();
static pointer F72816();
static pointer F72817();
static pointer F72818();
static pointer F72821();
static pointer F72822();
static pointer F72823();
static pointer F72824();
static pointer F72825();
static pointer F72826();
static pointer F72827();

/*refresh-line*/
static pointer F72806(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[1]); /*erase-eol*/
	local[0]= makeint(0);
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
WHL72916:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX72917;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)WRTBYTE(ctx,2,local+2); /*write-byte*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL72916;
WHX72917:
	local[2]= NIL;
BLK72918:
	w = NIL;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= w;
BLK72865:
	ctx->vsp=local; return(local[0]);}

/*line-head*/
static pointer F72807(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= makeint(0);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK72957:
	ctx->vsp=local; return(local[0]);}

/*line-left*/
static pointer F72808(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF72997;
	ctx->vsp=local+0;
	w=(*ftab[2])(ctx,0,local+0,&ftab[2],fqv[3]); /*cursor-backward*/
	local[0]= w;
	goto IF72998;
IF72997:
	local[0]= NIL;
IF72998:
	local[0]= argv[1];
	local[1]= makeint(0);
	local[2]= (pointer)((integer_t)(argv[2])-4);
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK72981:
	ctx->vsp=local; return(local[0]);}

/*line-right*/
static pointer F72809(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF73035;
	ctx->vsp=local+0;
	w=(*ftab[3])(ctx,0,local+0,&ftab[3],fqv[4]); /*cursor-forward*/
	argv[2] = (pointer)((integer_t)(argv[2])+4);
	local[0]= argv[2];
	goto IF73036;
IF73035:
	local[0]= NIL;
IF73036:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73018:
	ctx->vsp=local; return(local[0]);}

/*line-delch*/
static pointer F72810(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF73083;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[5]); /*list-delete*/
	argv[1] = w;
	argv[3] = (pointer)((integer_t)(argv[3])-4);
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F72806(ctx,3,local+0); /*refresh-line*/
	local[0]= w;
	goto IF73084;
IF73083:
	local[0]= NIL;
IF73084:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73066:
	ctx->vsp=local; return(local[0]);}

/*line-delch-previous*/
static pointer F72811(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF73144;
	argv[2] = (pointer)((integer_t)(argv[2])-4);
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[5]); /*list-delete*/
	argv[1] = w;
	argv[3] = (pointer)((integer_t)(argv[3])-4);
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F72806(ctx,3,local+0); /*refresh-line*/
	local[0]= w;
	goto IF73145;
IF73144:
	local[0]= NIL;
IF73145:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73127:
	ctx->vsp=local; return(local[0]);}

/*line-tail*/
static pointer F72812(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= argv[3];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73197:
	ctx->vsp=local; return(local[0]);}

/*line-refresh*/
static pointer F72813(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= makeint(0);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F72806(ctx,3,local+0); /*refresh-line*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= argv[3];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73223:
	ctx->vsp=local; return(local[0]);}

/*line-insert*/
static pointer F72814(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[6]); /*list-insert*/
	argv[1] = w;
	argv[3] = (pointer)((integer_t)(argv[3])+4);
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F72806(ctx,3,local+0); /*refresh-line*/
	argv[2] = (pointer)((integer_t)(argv[2])+4);
	ctx->vsp=local+0;
	w=(*ftab[3])(ctx,0,local+0,&ftab[3],fqv[4]); /*cursor-forward*/
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73254:
	ctx->vsp=local; return(local[0]);}

/*line-clear*/
static pointer F72815(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[1]); /*erase-eol*/
	local[0]= fqv[7];
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73319:
	ctx->vsp=local; return(local[0]);}

/*line-null*/
static pointer F72816(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK73346:
	ctx->vsp=local; return(local[0]);}

/*line-abort*/
static pointer F72817(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	w = NIL;
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[0];
	local[0]= w;
BLK73368:
	ctx->vsp=local; return(local[0]);}

/*line-end*/
static pointer F72818(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	w = argv[1];
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[0];
	local[0]= w;
BLK73390:
	ctx->vsp=local; return(local[0]);}

/*line-edit*/
static pointer F72821(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)COERCE(ctx,2,local+0); /*coerce*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[3];
	local[5]= NIL;
	local[6]= T;
	local[7]= fqv[10];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,0,local+6,&ftab[6],fqv[11]); /*tty-raw*/
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+6;
	w=(pointer)FINOUT(ctx,0,local+6); /*finish-output*/
	ctx->vsp=local+6;
	w=(pointer)READCH(ctx,0,local+6); /*read-char*/
	local[2] = w;
	{jmp_buf jb;
	w = fqv[8];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT73494;}
WHL73501:
	if (T==NIL) goto WHX73502;
	local[12]= loadglobal(fqv[12]);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[2];
	local[14]= local[0];
	local[15]= local[4];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)FUNCALL(ctx,5,local+12); /*funcall*/
	local[1] = w;
	local[12]= loadglobal(fqv[2]);
	ctx->vsp=local+13;
	w=(pointer)FINOUT(ctx,1,local+12); /*finish-output*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)READCH(ctx,0,local+12); /*read-char*/
	local[2] = w;
	goto WHL73501;
WHX73502:
	local[12]= NIL;
BLK73503:
	w = local[12];
CAT73494:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[1] = w;
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,0,local+6,&ftab[7],fqv[13]); /*tty-cooked*/
	if (local[1]==NIL) goto IF73576;
	local[6]= local[0];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)COERCE(ctx,2,local+6); /*coerce*/
	local[6]= w;
	goto IF73577;
IF73576:
	local[6]= NIL;
IF73577:
	w = local[6];
	local[0]= w;
BLK73432:
	ctx->vsp=local; return(local[0]);}

/*new-history*/
static pointer F72822(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[15]); /*make-array*/
	local[0]= w;
	storeglobal(fqv[16],w);
	local[0]= argv[0];
	storeglobal(fqv[17],local[0]);
	local[0]= makeint(0);
	storeglobal(fqv[18],local[0]);
	local[0]= loadglobal(fqv[16]);
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[19]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= w;
BLK73593:
	ctx->vsp=local; return(local[0]);}

/*add-history*/
static pointer F72823(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)((integer_t)(loadglobal(fqv[19]))+4);
	storeglobal(fqv[19],local[0]);
	local[0]= (pointer)((integer_t)(loadglobal(fqv[18]))+4);
	storeglobal(fqv[18],local[0]);
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[17]);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF73666;
	local[0]= (pointer)((integer_t)(loadglobal(fqv[17]))-4);
	storeglobal(fqv[18],local[0]);
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[16]);
	local[2]= fqv[20];
	local[3]= makeint(0);
	local[4]= fqv[21];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,6,local+0,&ftab[9],fqv[22]); /*replace*/
	local[0]= w;
	goto IF73667;
IF73666:
	local[0]= NIL;
IF73667:
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= loadglobal(fqv[19]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto IF73706;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[25]); /*find-method*/
	if (w==NIL) goto IF73706;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF73707;
IF73706:
	local[0]= NIL;
IF73707:
	w = loadglobal(fqv[16]);
	local[0]= w;
BLK73635:
	ctx->vsp=local; return(local[0]);}

/*print-history*/
static pointer F72824(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73737;}
	local[0]= loadglobal(fqv[2]);
ENT73737:
ENT73736:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= (pointer)((integer_t)(loadglobal(fqv[18]))+4);
WHL73780:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX73781;
	local[5]= loadglobal(fqv[16]);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[2] = w;
	w = local[2];
	if (!iscons(w)) goto IF73799;
	local[5]= local[0];
	local[6]= fqv[26];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	goto IF73800;
IF73799:
	local[5]= NIL;
IF73800:
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL73780;
WHX73781:
	local[5]= NIL;
BLK73782:
	w = NIL;
	local[0]= w;
BLK73734:
	ctx->vsp=local; return(local[0]);}

/*h*/
static pointer F72825(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F72824(ctx,0,local+0); /*print-history*/
	local[0]= w;
BLK73835:
	ctx->vsp=local; return(local[0]);}

/*get-history*/
static pointer F72826(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF73856;
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	if (w==NIL) goto IF73862;
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= argv[0];
	local[3]= makeint(-1);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,3,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF73863;
IF73862:
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= makeint(0);
	local[3]= argv[0];
	local[4]= loadglobal(fqv[16]);
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= makeint(-1);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF73863:
	goto IF73857;
IF73856:
	local[0]= (pointer)((integer_t)(loadglobal(fqv[18]))-4);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[14]); /*string*/
	local[1]= w;
	local[2]= NIL;
TAG73940:
	local[3]= local[0];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)LSEQP(ctx,2,local+3); /*<=*/
	if (w==NIL) goto IF73945;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK73911;
	goto IF73946;
IF73945:
	local[3]= NIL;
IF73946:
	local[3]= local[1];
	local[4]= loadglobal(fqv[16]);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[14]); /*string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[27]); /*substringp*/
	if (w==NIL) goto IF73959;
	w = local[2];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK73846;
	goto IF73960;
IF73959:
	local[3]= NIL;
IF73960:
	local[3]= (pointer)((integer_t)(local[0])-4);
	local[0] = local[3];
	w = NIL;
	ctx->vsp=local+3;
	goto TAG73940;
	w = NIL;
	local[0]= w;
BLK73911:
IF73857:
	w = local[0];
	local[0]= w;
BLK73846:
	ctx->vsp=local; return(local[0]);}

/*!*/
static pointer F72827(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74024;}
	local[0]= makeint(0);
ENT74024:
ENT74023:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F72826(ctx,1,local+1); /*get-history*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F72821(ctx,1,local+2); /*line-edit*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TERPRI(ctx,0,local+3); /*terpri*/
	if (local[2]==NIL) goto CON74057;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F72823(ctx,1,local+3); /*add-history*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,1,local+3,&ftab[13],fqv[28]); /*make-string-input-stream*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,1,local+3,&ftab[14],fqv[29]); /*evaluate-stream*/
	local[3]= w;
	goto CON74055;
CON74057:
	local[3]= NIL;
	goto CON74055;
CON74073:
	local[3]= NIL;
CON74055:
	w = local[3];
	local[0]= w;
BLK74021:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___history(ctx,n,argv,env)
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
	local[0]= fqv[30];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[32]); /*require*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[12];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF74097;
	local[0]= fqv[12];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[12];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF74120;
	local[0]= fqv[12];
	local[1]= fqv[35];
	local[2]= makeint(128);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF74121;
IF74120:
	local[0]= NIL;
IF74121:
	local[0]= fqv[12];
	goto IF74098;
IF74097:
	local[0]= NIL;
IF74098:
	ctx->vsp=local+0;
	compfun(ctx,fqv[36],module,F72806,fqv[37]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[38],module,F72807,fqv[39]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[40],module,F72808,fqv[41]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F72809,fqv[43]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[44],module,F72810,fqv[45]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F72811,fqv[47]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[48],module,F72812,fqv[49]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F72813,fqv[51]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[52],module,F72814,fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F72815,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[56],module,F72816,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F72817,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F72818,fqv[61]);
	local[0]= makeint(0);
	local[1]= makeint(128);
WHL74188:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX74189;
	local[2]= loadglobal(fqv[12]);
	local[3]= local[0];
	local[4]= fqv[52];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL74188;
WHX74189:
	local[2]= NIL;
BLK74190:
	w = NIL;
	local[0]= makeint(0);
	local[1]= makeint(32);
WHL74239:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX74240;
	local[2]= loadglobal(fqv[12]);
	local[3]= local[0];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL74239;
WHX74240:
	local[2]= NIL;
BLK74241:
	w = NIL;
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(1);
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(2);
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(3);
	local[2]= fqv[58];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(4);
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(6);
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(7);
	local[2]= fqv[50];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(8);
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(10);
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(11);
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(12);
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(13);
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(18);
	local[2]= fqv[50];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(21);
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(127);
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[8],module,F72821,fqv[62]);
	local[0]= fqv[17];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF74370;
	local[0]= fqv[17];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[17];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF74393;
	local[0]= fqv[17];
	local[1]= fqv[35];
	local[2]= makeint(50);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF74394;
IF74393:
	local[0]= NIL;
IF74394:
	local[0]= fqv[17];
	goto IF74371;
IF74370:
	local[0]= NIL;
IF74371:
	local[0]= fqv[16];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF74413;
	local[0]= fqv[16];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF74436;
	local[0]= fqv[16];
	local[1]= fqv[35];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF74437;
IF74436:
	local[0]= NIL;
IF74437:
	local[0]= fqv[16];
	goto IF74414;
IF74413:
	local[0]= NIL;
IF74414:
	local[0]= fqv[18];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF74456;
	local[0]= fqv[18];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF74479;
	local[0]= fqv[18];
	local[1]= fqv[35];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF74480;
IF74479:
	local[0]= NIL;
IF74480:
	local[0]= fqv[18];
	goto IF74457;
IF74456:
	local[0]= NIL;
IF74457:
	local[0]= fqv[19];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF74499;
	local[0]= fqv[19];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF74522;
	local[0]= fqv[19];
	local[1]= fqv[35];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF74523;
IF74522:
	local[0]= NIL;
IF74523:
	local[0]= fqv[19];
	goto IF74500;
IF74499:
	local[0]= NIL;
IF74500:
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F72822,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F72823,fqv[66]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F72824,fqv[68]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F72825,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F72826,fqv[72]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F72827,fqv[74]);
	local[0]= fqv[75];
	local[1]= fqv[76];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[77]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<17; i++) ftab[i]=fcallx;
}
