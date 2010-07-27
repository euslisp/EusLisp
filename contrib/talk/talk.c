/* talk.c :  entry=talk */
/* compiled by EusLisp 8.01 beta for Solaris  Thu May 11 10:44:56 JST 1995 */
#include "eus.h"
#include "talk.h"
#pragma init (init_object_module)
extern double fabs();
extern pointer fcallx();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer talk();
extern pointer build_quote_vector();
static init_object_module()
  { add_module_initializer("talk", talk);}


/*freq*/
static pointer F51(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(27);
	local[1]= fqv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,3,local+0,&ftab[0],fqv[2]); /*make-array*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[3]); /*string-downcase*/
	argv[0] = w;
	local[1]= makeint(0);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
whl54:
	local[3]= local[1];
	w = local[2];
	if ((int)local[3] >= (int)w) goto whx55;
	local[3]= argv[0];
	{ register int i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[5]); /*member*/
	if (w==NIL) goto con58;
	local[4]= local[0];
	local[5]= makeint(0);
	local[6]= local[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= (pointer)((int)(w)+4);
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= w;
	goto con57;
con58:
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)ALPHAP(ctx,1,local+4); /*alpha-char-p*/
	if (w==NIL) goto con59;
	local[4]= local[0];
	local[5]= local[3];
	local[6]= makeint(97);
	local[7]= makeint(-1);
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,3,local+5); /*-*/
	local[5]= w;
	local[6]= local[0];
	local[7]= local[3];
	local[8]= makeint(97);
	local[9]= makeint(-1);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,3,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= (pointer)((int)(w)+4);
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= w;
	goto con57;
con59:
	local[4]= NIL;
con57:
	w = local[4];
	local[1] = (pointer)((int)(local[1])+4);
	goto whl54;
whx55:
	local[3]= NIL;
blk56:
	w = NIL;
	w = local[0];
	local[0]= w;
blk52:
	ctx->vsp=local; return(local[0]);}

/*hamming*/
static pointer F63(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(27);
whl66:
	local[3]= local[1];
	w = local[2];
	if ((int)local[3] >= (int)w) goto whx67;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[1];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,1,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ABS(ctx,1,local+4); /*abs*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[0] = w;
	local[1] = (pointer)((int)(local[1])+4);
	goto whl66;
whx67:
	local[3]= NIL;
blk68:
	w = NIL;
	w = local[0];
	local[0]= w;
blk64:
	ctx->vsp=local; return(local[0]);}

/*write-database*/
static pointer F69(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ent73;}
	local[0]= fqv[6];
ent73:
	if (n>=2) { local[1]=(argv[1]); goto ent72;}
	local[1]= loadglobal(fqv[7]);
ent72:
ent71:
	if (n>2) maerror();
	local[2]= local[0];
	local[3]= fqv[8];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,3,local+2,&ftab[3],fqv[10]); /*open*/
	local[2]= w;
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,uwp74,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,2,local+5); /*print*/
	local[5]= NIL;
	local[6]= local[1];
whl76:
	if (local[6]==NIL) goto whx77;
	local[7]= xcar(local[6]);
	local[6] = xcdr(local[6]);
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,2,local+7); /*print*/
	goto whl76;
whx77:
	local[7]= NIL;
blk78:
	w = NIL;
	ctx->vsp=local+5;
	uwp74(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
blk70:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer uwp74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[2];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-database*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ent83;}
	local[0]= fqv[11];
ent83:
ent82:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = NIL;
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,1,local+5,&ftab[3],fqv[10]); /*open*/
	local[5]= w;
	ctx->vsp=local+6;
	w = makeclosure(codevec,quotevec,uwp84,argv,local);
	local[6]=(pointer)(ctx->protfp); local[7]=w;
	ctx->protfp=(struct protectframe *)(local+6);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,1,local+8); /*read*/
	local[4] = w;
	local[8]= makeint(0);
	local[9]= local[4];
whl86:
	local[10]= local[8];
	w = local[9];
	if ((int)local[10] >= (int)w) goto whx87;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)READ(ctx,1,local+10); /*read*/
	local[10]= w;
	w = local[1];
	ctx->vsp=local+11;
	local[1] = cons(ctx,local[10],w);
	local[8] = (pointer)((int)(local[8])+4);
	goto whl86;
whx87:
	local[10]= NIL;
blk88:
	w = NIL;
	ctx->vsp=local+8;
	uwp84(ctx,0,local+8,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
blk81:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer uwp84(ctx,n,argv,env)
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

/*answer*/
static pointer F89(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(1000000);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= loadglobal(fqv[7]);
whl92:
	if (local[4]==NIL) goto whx93;
	local[5]= xcar(local[4]);
	local[4] = xcdr(local[4]);
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= xcar(local[3]);
	ctx->vsp=local+7;
	w=(pointer)F63(ctx,2,local+5); /*hamming*/
	local[1] = w;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto con97;
	local[0] = local[1];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[2] = w;
	local[5]= local[2];
	goto con96;
con97:
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto con98;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto con96;
con98:
	local[5]= NIL;
con96:
	goto whl92;
whx93:
	local[5]= NIL;
blk94:
	w = NIL;
	local[3]= local[2];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[0]= w;
blk90:
	ctx->vsp=local; return(local[0]);}

/*remember*/
static pointer F99(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51(ctx,1,local+0); /*freq*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	w = loadglobal(fqv[7]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[7],local[1]);
	w = local[1];
	local[0]= w;
blk100:
	ctx->vsp=local; return(local[0]);}

/*talk*/
static pointer F101(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F80(ctx,0,local+0); /*read-database*/
	local[0]= w;
	storeglobal(fqv[7],w);
	local[0]= T;
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= makeint(0);
	local[1]= NIL;
	local[2]= fqv[13];
tag105:
	local[3]= T;
	local[4]= fqv[14];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)FINOUT(ctx,1,local+3); /*finish-output*/
	ctx->vsp=local+3;
	w=(pointer)READLINE(ctx,0,local+3); /*read-line*/
	local[3]= w;
	storeglobal(fqv[15],w);
	local[3]= loadglobal(fqv[15]);
	local[4]= fqv[16];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[17]); /*string-equal*/
	if (w==NIL) goto if106;
	w = local[0];
	ctx->vsp=local+3;
	local[3]=w;
	goto blk104;
	goto if107;
if106:
	local[3]= NIL;
if107:
	local[3]= local[2];
	local[4]= loadglobal(fqv[15]);
	ctx->vsp=local+5;
	w=(pointer)F99(ctx,2,local+3); /*remember*/
	local[3]= loadglobal(fqv[15]);
	ctx->vsp=local+4;
	w=(pointer)F51(ctx,1,local+3); /*freq*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F89(ctx,1,local+3); /*answer*/
	local[1] = w;
	local[2] = xcadr(xcdr(local[1]));
	local[0] = (pointer)((int)(local[0])+4);
	ctx->vsp=local+3;
	goto tag105;
	local[3]= NIL;
blk104:
	w = local[3];
	ctx->vsp=local+0;
	w=(pointer)F69(ctx,0,local+0); /*write-database*/
	local[0]= w;
blk102:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer talk(ctx,n,argv)
register context *ctx; int n; pointer *argv;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;
  module=argv[0];
  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if108;
	local[0]= fqv[7];
	local[1]= fqv[18];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	local[0]= fqv[7];
	goto if109;
if108:
	local[0]= NIL;
if109:
	local[0]= fqv[15];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto if110;
	local[0]= fqv[15];
	local[1]= fqv[18];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[20];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	local[0]= fqv[15];
	goto if111;
if110:
	local[0]= NIL;
if111:
	ctx->vsp=local+0;
	compfun(ctx,fqv[21],module,F51,fqv[22]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F63,fqv[24]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F69,fqv[26]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F80,fqv[28]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[29],module,F89,fqv[30]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F99,fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F101,fqv[34]);
	ctx->vsp=local+0;
	w=(pointer)F101(ctx,0,local+0); /*talk*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static init_ftab()
{  register int i;
  for (i=0; i<5; i++) ftab[i]=fcallx;
}
