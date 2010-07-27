/* gleus.c :  entry=gleus */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "gleus.h"
#pragma init (register_gleus)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___gleus();
extern pointer build_quote_vector();
static register_gleus()
  { add_module_initializer("___gleus", ___gleus);}

static pointer F177();

/*probe-extension*/
static pointer F177(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*symbol-string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INTERN(ctx,1,local+0); /*intern*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[1];
	local[3]= makeint(7939);
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[2]); /*eglgetstring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[3]); /*read-from-string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[4]); /*member*/
	local[0]= w;
BLK178:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___gleus(ctx,n,argv,env)
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
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[6]); /*provide*/
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF179;
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[9],w);
	goto IF180;
IF179:
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF180:
	local[0]= fqv[11];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[12],module,F177,fqv[13]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<5; i++) ftab[i]=fcallx;
}
