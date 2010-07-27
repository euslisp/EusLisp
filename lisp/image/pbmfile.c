/* pbmfile.c :  entry=pbmfile */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "pbmfile.h"
#pragma init (register_pbmfile)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___pbmfile();
extern pointer build_quote_vector();
static register_pbmfile()
  { add_module_initializer("___pbmfile", ___pbmfile);}

static pointer F69();
static pointer F70();
static pointer F71();
static pointer F72();
static pointer F73();
static pointer F74();
static pointer F75();
static pointer F76();
static pointer F77();
static pointer F78();
static pointer F79();
static pointer F80();
static pointer F81();
static pointer F82();
static pointer F83();

/*read-raw-image*/
static pointer F69(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT87;}
	local[0]= makeint(256);
ENT87:
	if (n>=3) { local[1]=(argv[2]); goto ENT86;}
	local[1]= local[0];
ENT86:
ENT85:
	if (n>3) maerror();
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= fqv[0];
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,3,local+2,&ftab[0],fqv[2]); /*make-array*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[3]); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP88,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[3];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)UNIXREAD(ctx,2,local+6); /*unix:uread*/
	ctx->vsp=local+6;
	UWP88(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[2];
	local[0]= w;
BLK84:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP88(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*write-raw-image*/
static pointer F70(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[3]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP90,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)UNIXWRITE(ctx,2,local+3); /*unix:write*/
	ctx->vsp=local+3;
	UWP90(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = argv[1];
	local[0]= w;
BLK89:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP90(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-pbm-token*/
static pointer F71(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
TAG93:
WHL94:
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	local[0] = w;
	local[1]= local[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[7]); /*member*/
	if (w==NIL) goto WHX95;
	goto WHL94;
WHX95:
	local[1]= NIL;
BLK96:
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)UNREADCH(ctx,2,local+1); /*unread-char*/
	local[1]= local[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON98;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK92;
	goto CON97;
CON98:
	local[1]= local[0];
	local[2]= makeint(35);
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON99;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READLINE(ctx,1,local+1); /*read-line*/
	ctx->vsp=local+1;
	goto TAG93;
	goto CON97;
CON99:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK92;
	goto CON97;
CON100:
	local[1]= NIL;
CON97:
	w = NIL;
	local[0]= w;
BLK92:
	w = local[0];
	local[0]= w;
BLK91:
	ctx->vsp=local; return(local[0]);}

/*read-ascii-pbm*/
static pointer F72(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK101:
	ctx->vsp=local; return(local[0]);}

/*read-binary-pbm*/
static pointer F73(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[9];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK102:
	ctx->vsp=local; return(local[0]);}

/*write-pgm*/
static pointer F74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT107;}
	local[0]= makeint(255);
ENT107:
	if (n>=4) { local[1]=(argv[3]); goto ENT106;}
	local[1]= argv[1];
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
ENT106:
	if (n>=5) { local[2]=(argv[4]); goto ENT105;}
	local[2]= argv[1];
	local[3]= fqv[11];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
ENT105:
ENT104:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[12];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,5,local+3); /*format*/
	local[3]= argv[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)UNIXWRITE(ctx,2,local+3); /*unix:write*/
	local[0]= w;
BLK103:
	ctx->vsp=local; return(local[0]);}

/*read-ascii-pgm*/
static pointer F75(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F71(ctx,2,local+2); /*read-pbm-token*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= local[3];
WHL110:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX111;
	local[6]= argv[0];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F71(ctx,2,local+6); /*read-pbm-token*/
	local[1] = w;
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto IF113;
	local[6]= fqv[13];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF114;
IF113:
	local[6]= NIL;
IF114:
	local[6]= argv[1];
	local[7]= local[4];
	w = local[1];
	{ register integer_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL110;
WHX111:
	local[6]= NIL;
BLK112:
	w = NIL;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[15];
	local[7]= argv[2];
	local[8]= argv[3];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	argv[1] = w;
	local[4]= argv[1];
	local[5]= fqv[16];
	local[6]= argv[0];
	local[7]= fqv[17];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[18]); /*pathname-name*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = argv[1];
	local[0]= w;
BLK108:
	ctx->vsp=local; return(local[0]);}

/*read-binary-pgm*/
static pointer F76(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[0];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)F71(ctx,2,local+5); /*read-pbm-token*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,1,local+6,&ftab[4],fqv[19]); /*make-string*/
	argv[1] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= argv[1];
	local[7]= argv[0];
	local[8]= fqv[20];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[21];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[0] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[22]); /*replace*/
	local[6]= argv[0];
	local[7]= fqv[20];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[23];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
WHL117:
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX118;
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)UNIXREAD(ctx,4,local+6); /*unix:uread*/
	local[3] = w;
	local[6]= local[3];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)LSEQP(ctx,2,local+6); /*<=*/
	if (w==NIL) goto IF120;
	local[6]= fqv[24];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF121;
IF120:
	local[6]= NIL;
IF121:
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[1] = w;
	goto WHL117;
WHX118:
	local[6]= NIL;
BLK119:
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[15];
	local[9]= argv[2];
	local[10]= argv[3];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	argv[1] = w;
	local[6]= argv[1];
	local[7]= fqv[16];
	local[8]= argv[0];
	local[9]= fqv[17];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[18]); /*pathname-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = argv[1];
	local[0]= w;
BLK116:
	ctx->vsp=local; return(local[0]);}

/*read-binary-ppm*/
static pointer F77(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= NIL;
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F71(ctx,2,local+2); /*read-pbm-token*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(512);
	{ integer_t i,j;
		j=intval(makeint(3)); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	local[7]= NIL;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)READCH(ctx,1,local+8); /*read-char*/
	local[8]= argv[1];
	local[9]= argv[0];
	local[10]= fqv[20];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[21];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[4] = w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[22]); /*replace*/
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[5] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= makeint(3);
	ctx->vsp=local+10;
	w=(pointer)MOD(ctx,2,local+8); /*mod*/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF124;
	local[8]= makeint(3);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)MOD(ctx,2,local+9); /*mod*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[7] = w;
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= local[7];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)UNIXREAD(ctx,4,local+8); /*unix:uread*/
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[5] = w;
	local[8]= local[5];
	goto IF125;
IF124:
	local[8]= NIL;
IF125:
WHL126:
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= local[6];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)UNIXREAD(ctx,4,local+8); /*unix:uread*/
	local[7] = w;
	local[8]= local[7];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto WHX127;
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[5] = w;
	goto WHL126;
WHX127:
	local[8]= NIL;
BLK128:
	local[8]= loadglobal(fqv[25]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[15];
	local[11]= argv[2];
	local[12]= argv[3];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	w = local[8];
	local[3] = w;
	local[8]= local[3];
	local[9]= fqv[16];
	local[10]= argv[0];
	local[11]= fqv[17];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[18]); /*pathname-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = local[3];
	local[0]= w;
BLK123:
	ctx->vsp=local; return(local[0]);}

/*read-ascii-ppm*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F71(ctx,2,local+3); /*read-pbm-token*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= local[4];
WHL132:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX133;
	local[8]= local[6];
	{ integer_t i,j;
		j=intval(makeint(3)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	local[5] = local[8];
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F71(ctx,2,local+8); /*read-pbm-token*/
	local[2] = w;
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto IF135;
	local[8]= fqv[26];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF136;
IF135:
	local[8]= NIL;
IF136:
	local[8]= argv[1];
	local[9]= local[5];
	w = local[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F71(ctx,2,local+8); /*read-pbm-token*/
	local[2] = w;
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto IF137;
	local[8]= fqv[27];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF138;
IF137:
	local[8]= NIL;
IF138:
	local[8]= argv[1];
	local[9]= (pointer)((integer_t)(local[5])+4);
	w = local[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F71(ctx,2,local+8); /*read-pbm-token*/
	local[2] = w;
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto IF139;
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF140;
IF139:
	local[8]= NIL;
IF140:
	local[8]= argv[1];
	local[9]= local[5];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	w = local[2];
	{ register integer_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL132;
WHX133:
	local[8]= NIL;
BLK134:
	w = NIL;
	local[6]= loadglobal(fqv[25]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[15];
	local[9]= argv[2];
	local[10]= argv[3];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[16];
	local[8]= argv[0];
	local[9]= fqv[17];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[18]); /*pathname-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[0];
	local[0]= w;
BLK130:
	ctx->vsp=local; return(local[0]);}

/*write-ppm*/
static pointer F79(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[1] = w;
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= argv[1];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(255);
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)UNIXWRITE(ctx,2,local+0); /*unix:write*/
	local[0]= w;
BLK142:
	ctx->vsp=local; return(local[0]);}

/*read-pnm*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT145;}
	local[0]= NIL;
ENT145:
ENT144:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)CHUPCASE(ctx,1,local+6); /*char-upcase*/
	local[6]= w;
	local[7]= makeint(80);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto IF146;
	local[6]= fqv[32];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF147;
IF146:
	local[6]= NIL;
IF147:
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F71(ctx,2,local+6); /*read-pbm-token*/
	local[2] = w;
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F71(ctx,2,local+6); /*read-pbm-token*/
	local[3] = w;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[5] = w;
	local[6]= local[5];
	local[7]= makeint(4096);
	{ integer_t i,j;
		j=intval(makeint(4096)); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w!=NIL) goto OR150;
	local[6]= local[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w!=NIL) goto OR150;
	goto IF148;
OR150:
	local[6]= fqv[33];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF149;
IF148:
	local[6]= NIL;
IF149:
	if (local[0]!=NIL) goto IF151;
	local[6]= local[1];
	local[7]= local[6];
	w = fqv[34];
	if (memq(local[7],w)==NIL) goto IF154;
	local[7]= local[5];
	local[8]= makeint(7);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(8);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[19]); /*make-string*/
	local[0] = w;
	local[7]= local[0];
	goto IF155;
IF154:
	local[7]= local[6];
	w = fqv[35];
	if (memq(local[7],w)==NIL) goto IF156;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[19]); /*make-string*/
	local[0] = w;
	local[7]= local[0];
	goto IF157;
IF156:
	local[7]= local[6];
	w = fqv[36];
	if (memq(local[7],w)==NIL) goto IF158;
	local[7]= local[5];
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[19]); /*make-string*/
	local[0] = w;
	local[7]= local[0];
	goto IF159;
IF158:
	local[7]= NIL;
IF159:
IF157:
IF155:
	w = local[7];
	local[6]= w;
	goto IF152;
IF151:
	local[6]= NIL;
IF152:
	local[6]= local[1];
	local[7]= local[6];
	if (fqv[37]!=local[7]) goto IF161;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F72(ctx,4,local+7); /*read-ascii-pbm*/
	local[7]= w;
	goto IF162;
IF161:
	local[7]= local[6];
	if (fqv[38]!=local[7]) goto IF163;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F75(ctx,4,local+7); /*read-ascii-pgm*/
	local[7]= w;
	goto IF164;
IF163:
	local[7]= local[6];
	if (fqv[39]!=local[7]) goto IF165;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F78(ctx,4,local+7); /*read-ascii-ppm*/
	local[7]= w;
	goto IF166;
IF165:
	local[7]= local[6];
	if (fqv[40]!=local[7]) goto IF167;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F73(ctx,4,local+7); /*read-binary-pbm*/
	local[7]= w;
	goto IF168;
IF167:
	local[7]= local[6];
	if (fqv[41]!=local[7]) goto IF169;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F76(ctx,4,local+7); /*read-binary-pgm*/
	local[7]= w;
	goto IF170;
IF169:
	local[7]= local[6];
	if (fqv[42]!=local[7]) goto IF171;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F77(ctx,4,local+7); /*read-binary-ppm*/
	local[7]= w;
	goto IF172;
IF171:
	if (T==NIL) goto IF173;
	local[7]= fqv[43];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF174;
IF173:
	local[7]= NIL;
IF174:
IF172:
IF170:
IF168:
IF166:
IF164:
IF162:
	w = local[7];
	local[0]= w;
BLK143:
	ctx->vsp=local; return(local[0]);}

/*read-pnm-file*/
static pointer F81(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT177;}
	local[0]= NIL;
ENT177:
ENT176:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[3]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP178,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F80(ctx,2,local+4); /*read-pnm*/
	ctx->vsp=local+4;
	UWP178(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK175:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP178(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*write-pnm*/
static pointer F82(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= loadglobal(fqv[44]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON181;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F79(ctx,2,local+0); /*write-ppm*/
	local[0]= w;
	goto CON180;
CON181:
	local[0]= argv[1];
	local[1]= loadglobal(fqv[44]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON182;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F79(ctx,2,local+0); /*write-ppm*/
	local[0]= w;
	goto CON180;
CON182:
	local[0]= argv[1];
	local[1]= loadglobal(fqv[45]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON183;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F79(ctx,2,local+0); /*write-ppm*/
	local[0]= w;
	goto CON180;
CON183:
	local[0]= argv[1];
	local[1]= loadglobal(fqv[14]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON184;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F74(ctx,2,local+0); /*write-pgm*/
	local[0]= w;
	goto CON180;
CON184:
	local[0]= NIL;
CON180:
	w = local[0];
	local[0]= w;
BLK179:
	ctx->vsp=local; return(local[0]);}

/*write-pnm-file*/
static pointer F83(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[47];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[3]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP186,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F82(ctx,2,local+3); /*write-pnm*/
	ctx->vsp=local+3;
	UWP186(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK185:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP186(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___pbmfile(ctx,n,argv,env)
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
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF187;
	local[0]= fqv[49];
	local[1]= fqv[50];
	local[2]= fqv[51];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,3,local+0,&ftab[6],fqv[52]); /*make-package*/
	local[0]= w;
	goto IF188;
IF187:
	local[0]= NIL;
IF188:
	local[0]= fqv[53];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF189;
	local[0]= fqv[54];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[55],w);
	goto IF190;
IF189:
	local[0]= fqv[56];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF190:
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F69,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F70,fqv[61]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[62],module,F71,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F72,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F73,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F74,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F75,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F76,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F77,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F78,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F79,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F80,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F81,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F82,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F83,fqv[87]);
	local[0]= fqv[88];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[90]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<8; i++) ftab[i]=fcallx;
}
