/* tty.c :  entry=tty */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "tty.h"
#pragma init (register_tty)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___tty();
extern pointer build_quote_vector();
static register_tty()
  { add_module_initializer("___tty", ___tty);}

static pointer F72250();
static pointer F72251();
static pointer F72252();
static pointer F72253();
static pointer F72254();
static pointer F72255();
static pointer F72256();
static pointer F72257();
static pointer F72258();
static pointer F72259();

/*tty-raw*/
static pointer F72250(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72288;}
	local[0]= makeint(0);
ENT72288:
ENT72287:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)COPYSEQ(ctx,1,local+1); /*copy-seq*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(7);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(12);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(13);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(14);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(15);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(21);
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(22);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*unix:tcsets*/
	local[0]= w;
BLK72285:
	ctx->vsp=local; return(local[0]);}

/*tty-cooked*/
static pointer F72251(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72361;}
	local[0]= makeint(0);
ENT72361:
ENT72360:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*unix:tcsets*/
	local[0]= w;
BLK72358:
	ctx->vsp=local; return(local[0]);}

/*backspace*/
static pointer F72252(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72381;}
	local[0]= makeint(1);
ENT72381:
ENT72380:
	if (n>1) maerror();
	local[1]= makeint(0);
	local[2]= local[0];
WHL72416:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX72417;
	local[3]= makeint(8);
	local[4]= loadglobal(fqv[2]);
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL72416;
WHX72417:
	local[3]= NIL;
BLK72418:
	w = NIL;
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK72378:
	ctx->vsp=local; return(local[0]);}

/*cursor-up*/
static pointer F72253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72450;}
	local[0]= makeint(1);
ENT72450:
ENT72449:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[3];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK72447:
	ctx->vsp=local; return(local[0]);}

/*cursor-down*/
static pointer F72254(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72474;}
	local[0]= makeint(1);
ENT72474:
ENT72473:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[4];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK72471:
	ctx->vsp=local; return(local[0]);}

/*cursor-forward*/
static pointer F72255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72498;}
	local[0]= makeint(1);
ENT72498:
ENT72497:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[5];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK72495:
	ctx->vsp=local; return(local[0]);}

/*cursor-backward*/
static pointer F72256(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72522;}
	local[0]= makeint(1);
ENT72522:
ENT72521:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[6];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK72519:
	ctx->vsp=local; return(local[0]);}

/*cursor-return*/
static pointer F72257(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[7];
	local[2]= makeint(13);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK72543:
	ctx->vsp=local; return(local[0]);}

/*cursor-pos*/
static pointer F72258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF72569;
	ctx->vsp=local+0;
	w=(pointer)F72257(ctx,0,local+0); /*cursor-return*/
	local[0]= w;
	goto IF72570;
IF72569:
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[8];
	local[2]= makeint(13);
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
IF72570:
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK72559:
	ctx->vsp=local; return(local[0]);}

/*erase-eol*/
static pointer F72259(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[9];
	local[2]= makeint(27);
	local[3]= makeint(91);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK72586:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___tty(ctx,n,argv,env)
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
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[11],module,F72250,fqv[12]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[13],module,F72251,fqv[14]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[15],module,F72252,fqv[16]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[17],module,F72253,fqv[18]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[19],module,F72254,fqv[20]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[21],module,F72255,fqv[22]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F72256,fqv[24]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F72257,fqv[26]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F72258,fqv[28]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[29],module,F72259,fqv[30]);
	local[0]= fqv[31];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[33]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<2; i++) ftab[i]=fcallx;
}
