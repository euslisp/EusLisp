/* readmacro.c :  entry=readmacro */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "readmacro.h"
#pragma init (register_readmacro)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___readmacro();
extern pointer build_quote_vector();
static register_readmacro()
  { add_module_initializer("___readmacro", ___readmacro);}

static pointer F3655();
static pointer F3657();
static pointer F3659();
static pointer F3661();
static pointer F3665();
static pointer F3667();
static pointer F3672();
static pointer F3675();
static pointer F3678();

/*read-backquote*/
static pointer F3655(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT3713;}
	local[0]= NIL;
ENT3713:
ENT3712:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3657(ctx,1,local+1); /*conv-bq*/
	local[0]= w;
BLK3710:
	ctx->vsp=local; return(local[0]);}

/*conv-bq*/
static pointer F3657(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]!=NIL) goto CON3746;
	local[0]= NIL;
	goto CON3744;
CON3746:
	w = argv[0];
	if (!!iscons(w)) goto CON3751;
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON3744;
CON3751:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto CON3761;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[1]!=local[0]) goto CON3773;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	goto CON3771;
CON3773:
	local[0]= fqv[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3657(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3659(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3771;
CON3789:
	local[0]= NIL;
CON3771:
	goto CON3744;
CON3761:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[1]!=local[0]) goto CON3810;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3657(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3659(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3744;
CON3810:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[2]!=local[0]) goto CON3839;
	local[0]= fqv[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F3657(ctx,1,local+2); /*conv-bq*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	goto CON3744;
CON3839:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)F3657(ctx,1,local+0); /*conv-bq*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3657(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3659(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3744;
CON3870:
	local[0]= NIL;
CON3744:
	w = local[0];
	local[0]= w;
BLK3734:
	ctx->vsp=local; return(local[0]);}

/*conscons*/
static pointer F3659(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[1]!=NIL) goto IF3904;
	local[0]= fqv[4];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF3905;
IF3904:
	local[0]= fqv[5];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF3905:
	w = local[0];
	local[0]= w;
BLK3892:
	ctx->vsp=local; return(local[0]);}

/*read-comma*/
static pointer F3661(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT3926;}
	local[0]= NIL;
ENT3926:
ENT3925:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)PEEKCH(ctx,1,local+1); /*peek-char*/
	local[1]= w;
	if (makeint(64)!=local[1]) goto CON3942;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	local[1]= fqv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON3940;
CON3942:
	local[1]= fqv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON3940;
CON3960:
	local[1]= NIL;
CON3940:
	w = local[1];
	local[0]= w;
BLK3923:
	ctx->vsp=local; return(local[0]);}

/*read-binary*/
static pointer F3665(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	argv[2] = w;
WHL4010:
	local[1]= argv[2];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[7]); /*find*/
	if (w==NIL) goto WHX4011;
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint(48);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	argv[2] = w;
	goto WHL4010;
WHX4011:
	local[1]= NIL;
BLK4012:
	w = argv[2];
	if (!isint(w)) goto IF4050;
	local[1]= argv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)UNREADCH(ctx,2,local+1); /*unread-char*/
	local[1]= w;
	goto IF4051;
IF4050:
	local[1]= NIL;
IF4051:
	w = local[0];
	local[0]= w;
BLK3977:
	ctx->vsp=local; return(local[0]);}

/*read-bit-vector*/
static pointer F3667(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[8];
	local[1]= fqv[9];
	local[2]= fqv[10];
	local[3]= fqv[11];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,5,local+0,&ftab[1],fqv[12]); /*make-array*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	argv[2] = w;
WHL4110:
	local[1]= argv[2];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[7]); /*find*/
	if (w==NIL) goto WHX4111;
	local[1]= argv[2];
	local[2]= makeint(48);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VECTOREXPUSH(ctx,2,local+1); /*vector-push-extend*/
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	argv[2] = w;
	goto WHL4110;
WHX4111:
	local[1]= NIL;
BLK4112:
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[14]); /*fill-pointer*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK4066:
	ctx->vsp=local; return(local[0]);}

/*read-pathname*/
static pointer F3672(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[15]); /*pathname*/
	local[0]= w;
BLK4158:
	ctx->vsp=local; return(local[0]);}

/*read-radian*/
static pointer F3675(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[16]); /*deg2rad*/
	local[0]= w;
BLK4182:
	ctx->vsp=local; return(local[0]);}

/*read-degree*/
static pointer F3678(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[17]); /*rad2deg*/
	local[0]= w;
BLK4206:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___readmacro(ctx,n,argv,env)
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
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4237;
	local[0]= fqv[20];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[21],w);
	goto IF4238;
IF4237:
	local[0]= fqv[22];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4238:
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[24],module,F3655,fqv[25]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[26],module,F3657,fqv[27]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[28],module,F3659,fqv[29]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F3661,fqv[31]);
	local[0]= makeint(44);
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint(96);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F3665,fqv[33]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[34],module,F3667,fqv[35]);
	local[0]= makeint(35);
	local[1]= makeint(66);
	local[2]= fqv[32];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(42);
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(33);
	local[2]= makeint(59);
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[36]); /*get-macro-character*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F3672,fqv[38]);
	local[0]= makeint(35);
	local[1]= makeint(80);
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[39],module,F3675,fqv[40]);
	local[0]= makeint(35);
	local[1]= makeint(68);
	local[2]= fqv[39];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F3678,fqv[42]);
	local[0]= makeint(35);
	local[1]= makeint(82);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
