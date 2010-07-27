/* glxconst.c :  entry=glxconst */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "glxconst.h"
#pragma init (register_glxconst)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glxconst();
extern pointer build_quote_vector();
static register_glxconst()
  { add_module_initializer("___glxconst", ___glxconst);}


/* initializer*/
pointer ___glxconst(ctx,n,argv,env)
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
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[1]); /*provide*/
	local[0]= fqv[2];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF68;
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[4],w);
	goto IF69;
IF68:
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF69:
	local[0]= fqv[6];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[7];
	local[1]= fqv[8];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[9];
	local[1]= fqv[8];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[10];
	local[1]= fqv[8];
	local[2]= makeint(3);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[11];
	local[1]= fqv[8];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[12];
	local[1]= fqv[8];
	local[2]= makeint(5);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[13];
	local[1]= fqv[8];
	local[2]= makeint(6);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[14];
	local[1]= fqv[8];
	local[2]= makeint(7);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[15];
	local[1]= fqv[8];
	local[2]= makeint(8);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[16];
	local[1]= fqv[8];
	local[2]= makeint(9);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[17];
	local[1]= fqv[8];
	local[2]= makeint(10);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[18];
	local[1]= fqv[8];
	local[2]= makeint(11);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[19];
	local[1]= fqv[8];
	local[2]= makeint(12);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[20];
	local[1]= fqv[8];
	local[2]= makeint(13);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[21];
	local[1]= fqv[8];
	local[2]= makeint(14);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[22];
	local[1]= fqv[8];
	local[2]= makeint(15);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[23];
	local[1]= fqv[8];
	local[2]= makeint(16);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[24];
	local[1]= fqv[8];
	local[2]= makeint(17);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[25];
	local[1]= fqv[8];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[26];
	local[1]= fqv[8];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[27];
	local[1]= fqv[8];
	local[2]= makeint(3);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[28];
	local[1]= fqv[8];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[29];
	local[1]= fqv[8];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[30];
	local[1]= fqv[8];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[31];
	local[1]= fqv[8];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[32];
	local[1]= fqv[8];
	local[2]= makeint(3);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[33];
	local[1]= fqv[8];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[34];
	local[1]= fqv[8];
	local[2]= makeint(5);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[35];
	local[1]= fqv[8];
	local[2]= makeint(6);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[36];
	local[1]= fqv[8];
	local[2]= makeint(7);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[37];
	local[1]= fqv[8];
	local[2]= makeint(8);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<1; i++) ftab[i]=fcallx;
}
