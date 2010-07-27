/* gldecl.c :  entry=gldecl */
/* compiled by EusLisp 8.26 for Linux  created on 2006年 12月 13日 水曜日 13:10:00 JST */
#include "eus.h"
#include "gldecl.h"
#pragma init (register_gldecl)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___gldecl();
extern pointer build_quote_vector();
static register_gldecl()
  { add_module_initializer("___gldecl", ___gldecl);}


/* initializer*/
pointer ___gldecl(ctx,n,argv,env)
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
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF80;
	local[0]= fqv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[2]); /*make-package*/
	local[0]= w;
	goto IF81;
IF80:
	local[0]= NIL;
IF81:
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF82;
	local[0]= fqv[4];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[5],w);
	goto IF83;
IF82:
	local[0]= fqv[6];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF83:
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[8];
	local[1]= fqv[9];
	local[2]= fqv[8];
	local[3]= fqv[10];
	local[4]= loadglobal(fqv[11]);
	local[5]= fqv[12];
	local[6]= fqv[13];
	local[7]= fqv[14];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[16];
	local[12]= makeint(-1);
	local[13]= fqv[17];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	local[1]= fqv[9];
	local[2]= fqv[19];
	local[3]= fqv[10];
	local[4]= loadglobal(fqv[20]);
	local[5]= fqv[12];
	local[6]= fqv[21];
	local[7]= fqv[14];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[16];
	local[12]= makeint(-1);
	local[13]= fqv[17];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[22];
	local[1]= fqv[9];
	local[2]= fqv[22];
	local[3]= fqv[10];
	local[4]= loadglobal(fqv[20]);
	local[5]= fqv[12];
	local[6]= fqv[23];
	local[7]= fqv[14];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[16];
	local[12]= makeint(-1);
	local[13]= fqv[17];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[24];
	local[1]= fqv[9];
	local[2]= fqv[24];
	local[3]= fqv[12];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF84;
	local[0]= fqv[26];
	local[1]= fqv[27];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF86;
	local[0]= fqv[26];
	local[1]= fqv[9];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF87;
IF86:
	local[0]= NIL;
IF87:
	local[0]= fqv[26];
	goto IF85;
IF84:
	local[0]= NIL;
IF85:
	local[0]= fqv[28];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF88;
	local[0]= fqv[28];
	local[1]= fqv[27];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF90;
	local[0]= fqv[28];
	local[1]= fqv[9];
	local[2]= makeint(4);
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,2,local+2,&ftab[2],fqv[29]); /*make-matrix*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF91;
IF90:
	local[0]= NIL;
IF91:
	local[0]= fqv[28];
	goto IF89;
IF88:
	local[0]= NIL;
IF89:
	local[0]= fqv[30];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF92;
	local[0]= fqv[30];
	local[1]= fqv[27];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF94;
	local[0]= fqv[30];
	local[1]= fqv[9];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF95;
IF94:
	local[0]= NIL;
IF95:
	local[0]= fqv[30];
	goto IF93;
IF92:
	local[0]= NIL;
IF93:
	local[0]= fqv[31];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[32];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[34]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
