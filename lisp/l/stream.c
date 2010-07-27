/* stream.c :  entry=stream */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 30日 金曜日 18:13:31 JST */
#include "eus.h"
#include "stream.h"
#pragma init (register_stream)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___stream();
extern pointer build_quote_vector();
static register_stream()
  { add_module_initializer("___stream", ___stream);}

static pointer F58();
static pointer F59();
static pointer F60();
static pointer F61();
static pointer F62();
static pointer F63();
static pointer F64();
static pointer F65();
static pointer F66();
static pointer F67();
static pointer F68();
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

/*:instream*/
static pointer M80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT83;}
	local[0]= NIL;
ENT83:
ENT82:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*input-stream-p*/
	if (w==NIL) goto IF84;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF85;
IF84:
	local[1]= NIL;
IF85:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK81:
	ctx->vsp=local; return(local[0]);}

/*:outstream*/
static pointer M86(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT89;}
	local[0]= NIL;
ENT89:
ENT88:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*output-stream-p*/
	if (w==NIL) goto IF90;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF91;
IF90:
	local[1]= NIL;
IF91:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK87:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M92(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK93:
	ctx->vsp=local; return(local[0]);}

/*:outfd*/
static pointer M94(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK95:
	ctx->vsp=local; return(local[0]);}

/*:in*/
static pointer M96(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST98:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK97:
	ctx->vsp=local; return(local[0]);}

/*:out*/
static pointer M99(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST101:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK100:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M102(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK103:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M104(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[6];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK105:
	ctx->vsp=local; return(local[0]);}

/*:fname*/
static pointer M106(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK107:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M108(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = argv[3];
	w = argv[0];
	local[0]= w;
BLK109:
	ctx->vsp=local; return(local[0]);}

/*:reset*/
static pointer M110(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT113;}
	local[0]= NIL;
ENT113:
ENT112:
	if (n>3) maerror();
	argv[0]->c.obj.iv[3] = makeint(0);
	if (local[0]==NIL) goto IF114;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	goto IF115;
IF114:
	local[1]= makeint(0);
IF115:
	argv[0]->c.obj.iv[4] = local[1];
	w = argv[0];
	local[0]= w;
BLK111:
	ctx->vsp=local; return(local[0]);}

/*:discard*/
static pointer M116(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT119;}
	local[0]= makeint(1);
ENT119:
ENT118:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK117:
	ctx->vsp=local; return(local[0]);}

/*:count*/
static pointer M120(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK121:
	ctx->vsp=local; return(local[0]);}

/*:tail*/
static pointer M122(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT125;}
	local[0]= NIL;
ENT125:
ENT124:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF126;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	goto IF127;
IF126:
	local[1]= NIL;
IF127:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK123:
	ctx->vsp=local; return(local[0]);}

/*:chars-left*/
static pointer M128(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
BLK129:
	ctx->vsp=local; return(local[0]);}

/*:tail-string*/
static pointer M130(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK131:
	ctx->vsp=local; return(local[0]);}

/*:buffer*/
static pointer M132(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT136;}
	local[0]= NIL;
ENT136:
	if (n>=4) { local[1]=(argv[3]); goto ENT135;}
	local[1]= NIL;
ENT135:
ENT134:
	if (n>4) maerror();
	if (local[1]==NIL) goto CON138;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	goto CON137;
CON138:
	w = local[0];
	if (!isstring(w)) goto CON139;
	argv[0]->c.obj.iv[2] = local[0];
	local[2]= argv[0]->c.obj.iv[2];
	goto CON137;
CON139:
	w = local[0];
	if (!isint(w)) goto CON140;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,1,local+2,&ftab[2],fqv[8]); /*make-string*/
	argv[0]->c.obj.iv[2] = w;
	local[2]= argv[0]->c.obj.iv[2];
	goto CON137;
CON140:
	local[2]= argv[0]->c.obj.iv[2];
	goto CON137;
CON141:
	local[2]= NIL;
CON137:
	w = local[2];
	local[0]= w;
BLK133:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M142(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT146;}
	local[0]= NIL;
ENT146:
	if (n>=6) { local[1]=(argv[5]); goto ENT145;}
	local[1]= NIL;
ENT145:
ENT144:
	if (n>6) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[3];
	if (!isstring(w)) goto IF147;
	local[2]= argv[3];
	goto IF148;
IF147:
	local[2]= loadglobal(fqv[9]);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
IF148:
	argv[0]->c.obj.iv[2] = local[2];
	w = local[0];
	if (!isint(w)) goto IF149;
	local[2]= local[0];
	goto IF150;
IF149:
	local[2]= makeint(0);
IF150:
	argv[0]->c.obj.iv[3] = local[2];
	w = local[1];
	if (!isint(w)) goto IF151;
	local[2]= local[1];
	goto IF152;
IF151:
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
IF152:
	argv[0]->c.obj.iv[4] = local[2];
	w = argv[0];
	local[0]= w;
BLK143:
	ctx->vsp=local; return(local[0]);}

/*reset-stream*/
static pointer F58(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[10];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK153:
	ctx->vsp=local; return(local[0]);}

/*:fd*/
static pointer M154(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK155:
	ctx->vsp=local; return(local[0]);}

/*:instream*/
static pointer M156(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[11]!=local[0]) goto IF158;
	local[0]= argv[0];
	goto IF159;
IF158:
	local[0]= NIL;
IF159:
	w = local[0];
	local[0]= w;
BLK157:
	ctx->vsp=local; return(local[0]);}

/*:outstream*/
static pointer M160(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[12]!=local[0]) goto IF162;
	local[0]= argv[0];
	goto IF163;
IF162:
	local[0]= NIL;
IF163:
	w = local[0];
	local[0]= w;
BLK161:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M164(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[11]!=local[0]) goto IF166;
	local[0]= argv[0]->c.obj.iv[5];
	goto IF167;
IF166:
	local[0]= NIL;
IF167:
	w = local[0];
	local[0]= w;
BLK165:
	ctx->vsp=local; return(local[0]);}

/*:outfd*/
static pointer M168(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[12]!=local[0]) goto IF170;
	local[0]= argv[0]->c.obj.iv[5];
	goto IF171;
IF170:
	local[0]= NIL;
IF171:
	w = local[0];
	local[0]= w;
BLK169:
	ctx->vsp=local; return(local[0]);}

/*:fname*/
static pointer M172(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK173:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M174(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(3);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
BLK175:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M176(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON179;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON178;
CON179:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON178;
CON180:
	local[0]= NIL;
CON178:
	w = local[0];
	local[0]= w;
BLK177:
	ctx->vsp=local; return(local[0]);}

/*:nonblock*/
static pointer M181(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON184;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[13]);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON183;
CON184:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[13]);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON183;
CON185:
	local[0]= NIL;
CON183:
	w = local[0];
	local[0]= w;
BLK182:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M186(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT189;}
	local[0]= T;
ENT189:
ENT188:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[14]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[15]));
	local[5]= fqv[16];
	local[6]= local[0];
	local[7]= NIL;
	local[8]= fqv[17];
	local[9]= argv[0]->c.obj.iv[6];
	local[10]= argv[0]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,5,local+7); /*format*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK187:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M190(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT193;}
	local[0]= makeint(128);
ENT193:
ENT192:
	if (n>6) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[15]));
	local[3]= fqv[18];
	local[4]= argv[4];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	argv[0]->c.obj.iv[4] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK191:
	ctx->vsp=local; return(local[0]);}

/*:read-bytes*/
static pointer M194(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT198;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[8]); /*make-string*/
	local[0]= w;
ENT198:
	if (n>=5) { local[1]=(argv[4]); goto ENT197;}
	local[1]= makeint(0);
ENT197:
ENT196:
	if (n>5) maerror();
	local[2]= NIL;
	w = local[0];
	if (isstring(w)) goto IF199;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF199;
	local[3]= fqv[19];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF200;
IF199:
	local[3]= NIL;
IF200:
	local[3]= argv[0];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto IF201;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[23]); /*replace*/
	local[3]= argv[0];
	local[4]= fqv[24];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	local[3]= local[1];
	goto IF202;
IF201:
	local[3]= NIL;
IF202:
WHL203:
	local[3]= local[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto WHX204;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,4,local+3); /*unix:uread*/
	local[2] = w;
	local[3]= local[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)LSEQP(ctx,2,local+3); /*<=*/
	if (w==NIL) goto IF206;
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF207;
IF206:
	local[3]= NIL;
IF207:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	goto WHL203;
WHX204:
	local[3]= NIL;
BLK205:
	w = local[0];
	local[0]= w;
BLK195:
	ctx->vsp=local; return(local[0]);}

/*:read-bytes-eof*/
static pointer M208(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto IF210;
	local[2]= argv[0];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[24];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF211;
IF210:
	local[2]= NIL;
IF211:
WHL212:
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)UNIXREAD(ctx,2,local+2); /*unix:uread*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto WHX213;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	goto WHL212;
WHX213:
	local[2]= NIL;
BLK214:
	local[2]= (pointer)get_sym_func(fqv[26]);
	local[3]= loadglobal(fqv[9]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK209:
	ctx->vsp=local; return(local[0]);}

/*make-two-way-stream*/
static pointer F59(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[27]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[18];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK215:
	ctx->vsp=local; return(local[0]);}

/*make-msgq-input-stream*/
static pointer F60(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT219;}
	local[0]= makeint(128);
ENT219:
ENT218:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[28]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MSGGET(ctx,1,local+4); /*unix:msgget*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK217:
	ctx->vsp=local; return(local[0]);}

/*make-msgq-output-stream*/
static pointer F61(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT223;}
	local[0]= makeint(128);
ENT223:
ENT222:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[28]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MSGGET(ctx,1,local+4); /*unix:msgget*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[12];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK221:
	ctx->vsp=local; return(local[0]);}

/*make-string-input-stream*/
static pointer F62(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT228;}
	local[0]= NIL;
ENT228:
	if (n>=3) { local[1]=(argv[2]); goto ENT227;}
	local[1]= NIL;
ENT227:
ENT226:
	if (n>3) maerror();
	w = argv[0];
	if (isstring(w)) goto IF229;
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF230;
IF229:
	local[2]= NIL;
IF230:
	local[2]= loadglobal(fqv[30]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[18];
	local[5]= fqv[11];
	local[6]= argv[0];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0] = w;
	w = argv[0];
	local[0]= w;
BLK225:
	ctx->vsp=local; return(local[0]);}

/*make-string-output-stream*/
static pointer F63(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT236;}
	local[0]= makeint(64);
ENT236:
	if (n>=2) { local[1]=(argv[1]); goto ENT235;}
	local[1]= NIL;
ENT235:
	if (n>=3) { local[2]=(argv[2]); goto ENT234;}
	local[2]= NIL;
ENT234:
ENT233:
	if (n>3) maerror();
	local[3]= loadglobal(fqv[30]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[18];
	local[6]= fqv[12];
	local[7]= local[0];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	local[0] = w;
	w = local[0];
	local[0]= w;
BLK232:
	ctx->vsp=local; return(local[0]);}

/*with-input-from-string*/
static pointer F238(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST240:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[31];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[32];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[33];
	local[6]= fqv[34];
	local[7]= fqv[35];
	local[8]= fqv[36];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[37];
	local[8]= fqv[34];
	local[9]= fqv[35];
	local[10]= fqv[36];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[38];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[34];
	local[8]= fqv[39];
	local[9]= fqv[36];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[37];
	local[9]= fqv[34];
	local[10]= fqv[39];
	local[11]= fqv[36];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[38];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK239:
	ctx->vsp=local; return(local[0]);}

/*with-output-to-string*/
static pointer F241(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST243:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[31];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[40];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK242:
	ctx->vsp=local; return(local[0]);}

/*get-output-stream-string*/
static pointer F64(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK244:
	ctx->vsp=local; return(local[0]);}

/*read-from-string*/
static pointer F65(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT248;}
	local[0]= T;
ENT248:
	if (n>=3) { local[1]=(argv[2]); goto ENT247;}
	local[1]= NIL;
ENT247:
ENT246:
	if (n>3) maerror();
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F62(ctx,1,local+2); /*make-string-input-stream*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)READ(ctx,3,local+2); /*read*/
	local[0]= w;
BLK245:
	ctx->vsp=local; return(local[0]);}

/*princ-to-string*/
static pointer F66(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT251;}
	local[0]= makeint(16);
ENT251:
ENT250:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F63(ctx,1,local+1); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F64(ctx,1,local+2); /*get-output-stream-string*/
	local[0]= w;
BLK249:
	ctx->vsp=local; return(local[0]);}

/*prin1-to-string*/
static pointer F67(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT254;}
	local[0]= makeint(16);
ENT254:
ENT253:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F63(ctx,1,local+1); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PRIN1(ctx,2,local+2); /*prin1*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F64(ctx,1,local+2); /*get-output-stream-string*/
	local[0]= w;
BLK252:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK256:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M257(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(2);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[42]); /*unix::ntohs*/
	local[0]= w;
BLK258:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M259(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK260:
	ctx->vsp=local; return(local[0]);}

/*:next-port*/
static pointer M261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[43];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= (pointer)((integer_t)(w)+4);
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[44]); /*unix::htons*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(2);
	local[3]= fqv[41];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK262:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M263(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT266;}
	local[0]= T;
ENT266:
ENT265:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[15]));
	local[3]= fqv[16];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= fqv[45];
	local[7]= argv[0];
	{ register integer_t i=intval(makeint(4));
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0];
	{ register integer_t i=intval(makeint(5));
	  w=makeint(local[8]->c.str.chars[i]);}
	local[8]= w;
	local[9]= argv[0];
	{ register integer_t i=intval(makeint(6));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	local[10]= argv[0];
	{ register integer_t i=intval(makeint(7));
	  w=makeint(local[10]->c.str.chars[i]);}
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[43];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,7,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK264:
	ctx->vsp=local; return(local[0]);}

/*make-socket-address*/
static pointer F68(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[46], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY268;
	local[0] = makeint(2);
KEY268:
	if (n & (1<<1)) goto KEY269;
	local[1] = NIL;
KEY269:
	if (n & (1<<2)) goto KEY270;
	local[2] = fqv[47];
KEY270:
	if (n & (1<<3)) goto KEY271;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)GETSERVBYNAME(ctx,1,local+6); /*unix:getservbyname*/
	local[3] = w;
KEY271:
	if (n & (1<<4)) goto KEY272;
	local[6]= fqv[48];
	ctx->vsp=local+7;
	w=(pointer)GETENV(ctx,1,local+6); /*unix:getenv*/
	local[4] = w;
KEY272:
	if (n & (1<<5)) goto KEY273;
	local[5] = NIL;
KEY273:
	local[6]= local[0];
	if (makeint(1)!=local[6]) goto CON275;
	local[6]= loadglobal(fqv[49]);
	local[7]= makeint(16);
	local[8]= makeint(2);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[8]= (pointer)((integer_t)local[8] + (integer_t)w);
	ctx->vsp=local+9;
	w=(pointer)MAX(ctx,2,local+7); /*max*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[1];
	local[9]= fqv[50];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,4,local+7,&ftab[4],fqv[23]); /*replace*/
	local[7]= local[0];
	local[8]= local[6];
	local[9]= makeint(0);
	local[10]= fqv[41];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	w = local[6];
	local[6]= w;
	goto CON274;
CON275:
	local[6]= local[0];
	if (makeint(2)!=local[6]) goto CON276;
	local[6]= loadglobal(fqv[49]);
	local[7]= makeint(16);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[6];
	local[9]= makeint(0);
	local[10]= fqv[41];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	if (local[4]==NIL) goto IF277;
	local[7]= local[4];
	if (fqv[51]!=local[7]) goto IF279;
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKINTVECTOR(ctx,4,local+7); /*integer-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[4] = w;
	local[7]= local[4];
	goto IF280;
IF279:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)GETHOSTBYNAME(ctx,1,local+7); /*unix:gethostbyname*/
	local[4] = w;
	local[7]= local[4];
IF280:
	w = local[4];
	if (!isnum(w)) goto IF281;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SYSERRLIST(ctx,1,local+7); /*unix:syserrlist*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK267;
	goto IF282;
IF281:
	local[7]= NIL;
IF282:
	local[7]= local[6];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[50];
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,4,local+7,&ftab[4],fqv[23]); /*replace*/
	local[7]= w;
	goto IF278;
IF277:
	local[7]= NIL;
IF278:
	if (local[2]==NIL) goto IF283;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)GETSERVBYNAME(ctx,2,local+7); /*unix:getservbyname*/
	local[2] = w;
	w = local[2];
	if (!isnum(w)) goto IF285;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SYSERRLIST(ctx,1,local+7); /*unix:syserrlist*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK267;
	goto IF286;
IF285:
	local[7]= NIL;
IF286:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[6];
	local[9]= makeint(2);
	local[10]= fqv[41];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	local[7]= w;
	goto IF284;
IF283:
	local[7]= NIL;
IF284:
	if (local[3]==NIL) goto IF287;
	w = local[3];
	if (!isstring(w)) goto IF289;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)GETSERVBYNAME(ctx,1,local+7); /*unix:getservbyname*/
	local[3] = w;
	local[7]= local[3];
	goto IF290;
IF289:
	local[7]= NIL;
IF290:
	w = local[3];
	if (!isint(w)) goto IF291;
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)GREQP(ctx,2,local+7); /*>=*/
	if (w==NIL) goto IF291;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,1,local+7,&ftab[6],fqv[44]); /*unix::htons*/
	local[7]= w;
	local[8]= local[6];
	local[9]= makeint(2);
	local[10]= fqv[41];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	local[7]= w;
	goto IF292;
IF291:
	local[7]= NIL;
IF292:
	goto IF288;
IF287:
	local[7]= NIL;
IF288:
	w = local[6];
	local[6]= w;
	goto CON274;
CON276:
	local[6]= NIL;
CON274:
	w = local[6];
	local[0]= w;
BLK267:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M293(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK294:
	ctx->vsp=local; return(local[0]);}

/*:address*/
static pointer M295(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK296:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M297(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK298:
	ctx->vsp=local; return(local[0]);}

/*:fd*/
static pointer M299(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK300:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M301(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK302:
	ctx->vsp=local; return(local[0]);}

/*:listen*/
static pointer M303(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT306;}
	local[0]= makeint(3);
ENT306:
ENT305:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LISTEN(ctx,2,local+1); /*unix:listen*/
	local[0]= w;
BLK304:
	ctx->vsp=local; return(local[0]);}

/*:accept*/
static pointer M307(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)ACCEPT(ctx,1,local+0); /*unix:accept*/
	local[0]= w;
BLK308:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M309(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(3);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
BLK310:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M311(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON314;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON313;
CON314:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON313;
CON315:
	local[0]= NIL;
CON313:
	w = local[0];
	local[0]= w;
BLK312:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M316(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[52];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(1);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SOCKET(ctx,3,local+1); /*unix:socket*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF318;
	w = argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK317;
	goto IF319;
IF318:
	local[1]= NIL;
IF319:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)BIND(ctx,2,local+1); /*unix:bind*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON321;
	local[1]= local[0];
	goto CON320;
CON321:
	local[1]= argv[0];
	local[2]= fqv[53];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF323;
	local[1]= argv[0];
	goto IF324;
IF323:
	local[1]= local[0];
IF324:
	goto CON320;
CON322:
	local[1]= NIL;
CON320:
	w = local[1];
	local[0]= w;
BLK317:
	ctx->vsp=local; return(local[0]);}

/*make-socket-port*/
static pointer F69(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[54]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= fqv[18];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK325:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M326(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(0);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK327:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M328(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT331;}
	local[0]= makeint(128);
ENT331:
ENT330:
	if (n>5) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	local[1]= loadglobal(fqv[28]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= fqv[55];
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[28]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= fqv[56];
	local[6]= fqv[12];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[2] = w;
	argv[0]->c.obj.iv[3] = argv[3];
	w = argv[0];
	local[0]= w;
BLK329:
	ctx->vsp=local; return(local[0]);}

/*make-server-socket-stream*/
static pointer F70(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT336;}
	local[0]= makeint(512);
ENT336:
ENT335:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[57];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto IF337;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF337;
	w = local[1];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK334;
	goto IF338;
IF337:
	local[2]= NIL;
IF338:
	local[2]= loadglobal(fqv[58]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[18];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[0];
	local[7]= fqv[59];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK334:
	ctx->vsp=local; return(local[0]);}

/*connect-sigalarm-handler*/
static pointer F71(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[60];
	local[1]= loadglobal(fqv[61]);
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[62]); /*warn*/
	local[0]= w;
BLK340:
	ctx->vsp=local; return(local[0]);}

/*make-client-socket-stream*/
static pointer F72(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT344;}
	local[0]= makeint(5);
ENT344:
	if (n>=3) { local[1]=(argv[2]); goto ENT343;}
	local[1]= makeint(512);
ENT343:
ENT342:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[52];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(1);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SOCKET(ctx,3,local+4); /*unix:socket*/
	local[2] = w;
	local[4]= local[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF345;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)UNIXCLOSE(ctx,1,local+4); /*unix:uclose*/
	w = local[2];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK341;
	goto IF346;
IF345:
	local[4]= NIL;
IF346:
	local[4]= makeint(14);
	local[5]= fqv[63];
	ctx->vsp=local+6;
	w=(pointer)SIGNAL(ctx,2,local+4); /*unix:signal*/
	local[4]= w;
	storeglobal(fqv[64],w);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ALARM(ctx,1,local+4); /*unix:alarm*/
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP347,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)CONNECT(ctx,2,local+6); /*unix:connect*/
	local[3] = w;
	w = local[3];
	ctx->vsp=local+6;
	UWP347(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[4]= local[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF348;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)UNIXCLOSE(ctx,1,local+4); /*unix:uclose*/
	w = local[3];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK341;
	goto IF349;
IF348:
	local[4]= NIL;
IF349:
	local[4]= loadglobal(fqv[58]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[18];
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK341:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP347(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(pointer)ALARM(ctx,1,local+0); /*unix:alarm*/
	local[0]= makeint(14);
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(pointer)SIGNAL(ctx,2,local+0); /*unix:signal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-dgram-socket*/
static pointer F73(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[52];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SOCKET(ctx,3,local+1); /*unix:socket*/
	local[0] = w;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)BIND(ctx,2,local+1); /*unix:bind*/
	w = local[0];
	local[0]= w;
BLK351:
	ctx->vsp=local; return(local[0]);}

/*connect-server*/
static pointer F74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT354;}
	local[0]= makeint(5);
ENT354:
ENT353:
	if (n>3) maerror();
	local[1]= fqv[52];
	local[2]= makeint(2);
	local[3]= fqv[65];
	local[4]= argv[0];
	local[5]= fqv[43];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F68(ctx,6,local+1); /*make-socket-address*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F72(ctx,2,local+1); /*make-client-socket-stream*/
	local[0]= w;
BLK352:
	ctx->vsp=local; return(local[0]);}

/*select-stream*/
static pointer F75(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT357;}
	local[0]= makeflt(0.00000000e+00);
ENT357:
ENT356:
	if (n>2) maerror();
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
WHL359:
	if (local[6]==NIL) goto WHX360;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w = local[5];
	if (!isint(w)) goto CON364;
	local[7]= local[5];
	goto CON363;
CON364:
	local[7]= local[5];
	local[8]= fqv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	goto CON363;
CON365:
	local[7]= NIL;
CON363:
	local[4] = local[7];
	local[7]= makeint(1);
	local[8]= local[1];
	local[9]= local[4];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)DPB(ctx,4,local+7); /*dpb*/
	local[1] = w;
	local[7]= loadglobal(fqv[66]);
	local[8]= local[4];
	w = local[5];
	{ register integer_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.vec.v[i]=w;}
	goto WHL359;
WHX360:
	local[7]= NIL;
BLK361:
	w = NIL;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SELECT_READ(ctx,2,local+5); /*unix:select-read-fd*/
	local[1] = w;
WHL366:
	local[5]= local[1];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto WHX367;
	local[5]= local[1];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)LOGTEST(ctx,2,local+5); /*logtest*/
	if (w==NIL) goto IF369;
	local[5]= loadglobal(fqv[66]);
	{ register integer_t i=intval(local[3]);
	  w=(local[5]->c.vec.v[i]);}
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF370;
IF369:
	local[5]= NIL;
IF370:
	local[5]= local[1];
	local[6]= makeint(-1);
	ctx->vsp=local+7;
	w=(pointer)ASH(ctx,2,local+5); /*ash*/
	local[1] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL366;
WHX367:
	local[5]= NIL;
BLK368:
	w = local[2];
	local[0]= w;
BLK355:
	ctx->vsp=local; return(local[0]);}

/*sigio-handler*/
static pointer F76(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= loadglobal(fqv[67]);
	ctx->vsp=local+2;
	w=(pointer)F75(ctx,1,local+1); /*select-stream*/
	local[1]= w;
WHL373:
	if (local[1]==NIL) goto WHX374;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= loadglobal(fqv[68]);
	w = local[0];
	if (!isint(w)) goto IF377;
	local[3]= local[0];
	goto IF378;
IF377:
	local[3]= local[0];
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF378:
	{ register integer_t i=intval(local[3]);
	  w=(local[2]->c.vec.v[i]);}
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	goto WHL373;
WHX374:
	local[2]= NIL;
BLK375:
	w = NIL;
	local[0]= w;
BLK371:
	ctx->vsp=local; return(local[0]);}

/*def-async*/
static pointer F379(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST381:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto CON383;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[2] = w;
	local[3]= fqv[69];
	local[4]= local[2];
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto CON382;
CON383:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[0] = NIL;
	local[3]= local[0];
	goto CON382;
CON384:
	local[3]= NIL;
CON382:
	local[3]= fqv[70];
	local[4]= fqv[71];
	local[5]= argv[0];
	local[6]= fqv[67];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[72];
	local[6]= fqv[73];
	local[7]= fqv[36];
	local[8]= fqv[74];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[75];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[70];
	local[9]= fqv[76];
	local[10]= argv[0];
	local[11]= fqv[77];
	local[12]= fqv[78];
	local[13]= fqv[76];
	local[14]= argv[0];
	local[15]= fqv[79];
	local[16]= fqv[80];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[81];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[76];
	local[11]= argv[0];
	local[12]= fqv[82];
	local[13]= fqv[83];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[4];
	local[10]= argv[0];
	local[11]= fqv[6];
	local[12]= fqv[84];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[85];
	local[8]= fqv[86];
	local[9]= fqv[68];
	local[10]= fqv[33];
	local[11]= fqv[75];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= argv[0];
	local[13]= fqv[4];
	local[14]= argv[0];
	local[15]= fqv[2];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK380:
	ctx->vsp=local; return(local[0]);}

/*:destinations*/
static pointer M385(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT388;}
	local[0]= NIL;
ENT388:
ENT387:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF389;
	local[1]= local[0];
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[5] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[5];
	goto IF390;
IF389:
	local[1]= NIL;
IF390:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK386:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M391(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[15]));
	local[2]= fqv[18];
	local[3]= fqv[12];
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	w = argv[0];
	local[0]= w;
BLK392:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M393(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF395;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[1] = w;
	local[2]= local[1];
	goto IF396;
IF395:
	local[1] = argv[0]->c.obj.iv[2];
	local[2]= local[1];
IF396:
	argv[0]->c.obj.iv[3] = makeint(0);
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[5];
WHL398:
	if (local[3]==NIL) goto WHX399;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)PRINC(ctx,2,local+4); /*princ*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	goto WHL398;
WHX399:
	local[4]= NIL;
BLK400:
	w = NIL;
	w = T;
	local[0]= w;
BLK394:
	ctx->vsp=local; return(local[0]);}

/*:close*/
static pointer M402(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[5];
WHL405:
	if (local[1]==NIL) goto WHX406;
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
	w=(pointer)CLOSE(ctx,1,local+2); /*close*/
	goto WHL405;
WHX406:
	local[2]= NIL;
BLK407:
	w = NIL;
	local[0]= w;
BLK403:
	ctx->vsp=local; return(local[0]);}

/*make-broadcast-stream*/
static pointer F77(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST410:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
WHL412:
	if (local[4]==NIL) goto WHX413;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)STREAMP(ctx,1,local+5); /*streamp*/
	if (w==NIL) goto IF416;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF417;
IF416:
	local[5]= local[3];
	local[6]= fqv[87];
	local[7]= fqv[12];
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,3,local+5,&ftab[8],fqv[88]); /*open*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
IF417:
	goto WHL412;
WHX413:
	local[5]= NIL;
BLK414:
	w = NIL;
	local[3]= loadglobal(fqv[89]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[18];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK409:
	ctx->vsp=local; return(local[0]);}

/*read-buffer*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT421;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT421:
ENT420:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[87];
	local[3]= fqv[11];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[88]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP422,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= makeint(0);
WHL423:
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX424;
	local[5]= local[4];
	local[6]= local[1];
	local[7]= fqv[90];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)UNIXREAD(ctx,4,local+6); /*unix:uread*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[4] = w;
	goto WHL423;
WHX424:
	local[5]= NIL;
BLK425:
	w = local[5];
	w = argv[1];
	ctx->vsp=local+4;
	UWP422(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK419:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP422(ctx,n,argv,env)
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

/*write-buffer*/
static pointer F79(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT428;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT428:
ENT427:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[87];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[88]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP429,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1];
	local[5]= argv[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)UNIXWRITE(ctx,3,local+4); /*unix:write*/
	ctx->vsp=local+4;
	UWP429(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK426:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP429(ctx,n,argv,env)
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

/*:init*/
static pointer M430(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST432:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[91]);
	local[2]= fqv[92];
	local[3]= fqv[93];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[94]); /*make-array*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[91]);
	local[2]= fqv[92];
	local[3]= fqv[93];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[94]); /*make-array*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= loadglobal(fqv[91]);
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,1,local+1,&ftab[9],fqv[94]); /*make-array*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= NIL;
	local[2]= local[0];
WHL434:
	if (local[2]==NIL) goto WHX435;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= (pointer)get_sym_func(fqv[4]);
	local[4]= argv[0];
	local[5]= fqv[95];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,6,local+3); /*apply*/
	goto WHL434;
WHX435:
	local[3]= NIL;
BLK436:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK431:
	ctx->vsp=local; return(local[0]);}

/*:get-stream-fd*/
static pointer M438(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)STREAMP(ctx,1,local+1); /*streamp*/
	if (w==NIL) goto CON441;
	local[1]= argv[2];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON440;
CON441:
	w = argv[2];
	if (!isnum(w)) goto CON442;
	local[1]= argv[2];
	goto CON440;
CON442:
	local[1]= argv[2];
	local[2]= fqv[90];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[96]); /*find-method*/
	if (w==NIL) goto CON443;
	local[1]= argv[2];
	local[2]= fqv[90];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON440;
CON443:
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON440;
CON444:
	local[1]= NIL;
CON440:
	local[0] = local[1];
	local[1]= local[0];
	local[2]= loadglobal(fqv[91]);
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF445;
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF446;
IF445:
	local[1]= NIL;
IF446:
	w = local[0];
	local[0]= w;
BLK439:
	ctx->vsp=local; return(local[0]);}

/*:add-port*/
static pointer M447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST449:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	local[1]= argv[0];
	local[2]= fqv[99];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,3,local+4); /*list**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0]= w;
BLK448:
	ctx->vsp=local; return(local[0]);}

/*:remove-port*/
static pointer M450(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[99];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[0]= w;
BLK451:
	ctx->vsp=local; return(local[0]);}

/*:streams*/
static pointer M452(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[91]);
WHL455:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX456;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	if (w==NIL) goto IF458;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF459;
IF458:
	local[3]= NIL;
IF459:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL455;
WHX456:
	local[3]= NIL;
BLK457:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK453:
	ctx->vsp=local; return(local[0]);}

/*:fds*/
static pointer M460(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[91]);
WHL463:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX464;
	local[3]= makeint(1);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF466;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF467;
IF466:
	local[3]= NIL;
IF467:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL463;
WHX464:
	local[3]= NIL;
BLK465:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK461:
	ctx->vsp=local; return(local[0]);}

/*:select*/
static pointer M468(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT471;}
	local[0]= makeflt(9.99999940e-02);
ENT471:
ENT470:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[23]); /*replace*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SELECT(ctx,4,local+4); /*unix:select*/
	local[1] = w;
	local[4]= local[1];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF472;
	local[4]= makeint(0);
	local[5]= loadglobal(fqv[91]);
WHL475:
	local[6]= local[4];
	w = local[5];
	if ((integer_t)local[6] >= (integer_t)w) goto WHX476;
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF478;
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,1,local+6,&ftab[11],fqv[100]); /*functionp*/
	if (w==NIL) goto IF480;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[6]= w;
	goto IF481;
IF480:
	local[6]= (pointer)get_sym_func(fqv[4]);
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
IF481:
	goto IF479;
IF478:
	local[6]= NIL;
IF479:
	local[4] = (pointer)((integer_t)(local[4])+4);
	goto WHL475;
WHX476:
	local[6]= NIL;
BLK477:
	w = T;
	local[4]= w;
	goto IF473;
IF472:
	local[4]= NIL;
IF473:
	w = local[4];
	local[0]= w;
BLK469:
	ctx->vsp=local; return(local[0]);}

/*:select-loop*/
static pointer M482(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT486;}
	local[0]= makeflt(9.99999940e-02);
ENT486:
	if (n>=4) { local[1]=(argv[3]); goto ENT485;}
	local[1]= NIL;
ENT485:
ENT484:
	ctx->vsp=local+2;
	local[2]= minilist(ctx,&argv[n],n-4);
	{jmp_buf jb;
	w = fqv[101];
	ctx->vsp=local+3;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT487;}
WHL488:
	if (T==NIL) goto WHX489;
	local[9]= argv[0];
	local[10]= fqv[102];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (local[1]==NIL) goto IF491;
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	goto IF492;
IF491:
	local[9]= NIL;
IF492:
	goto WHL488;
WHX489:
	local[9]= NIL;
BLK490:
	w = local[9];
CAT487:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK483:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___stream(ctx,n,argv,env)
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
	local[0]= fqv[103];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF493;
	local[0]= fqv[104];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[105],w);
	goto IF494;
IF493:
	local[0]= fqv[106];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF494:
	local[0]= fqv[107];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80,fqv[108],fqv[27],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86,fqv[110],fqv[27],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M92,fqv[2],fqv[27],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M94,fqv[3],fqv[27],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M96,fqv[114],fqv[27],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M99,fqv[116],fqv[27],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M102,fqv[5],fqv[27],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M104,fqv[6],fqv[27],fqv[119]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M106,fqv[7],fqv[27],fqv[120]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M108,fqv[18],fqv[27],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M110,fqv[10],fqv[30],fqv[122]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M116,fqv[24],fqv[30],fqv[123]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M120,fqv[124],fqv[30],fqv[125]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M122,fqv[126],fqv[30],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M128,fqv[20],fqv[30],fqv[128]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M130,fqv[22],fqv[30],fqv[129]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M132,fqv[130],fqv[30],fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M142,fqv[18],fqv[30],fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F58,fqv[134]);
	local[0]= fqv[81];
	local[1]= fqv[135];
	local[2]= makeint(8192);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[79];
	local[1]= fqv[135];
	local[2]= makeint(3);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[77];
	local[1]= fqv[135];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[82];
	local[1]= fqv[135];
	local[2]= makeint(8);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M154,fqv[90],fqv[28],fqv[136]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M156,fqv[108],fqv[28],fqv[137]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M160,fqv[110],fqv[28],fqv[138]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M164,fqv[2],fqv[28],fqv[139]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M168,fqv[3],fqv[28],fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M172,fqv[7],fqv[28],fqv[141]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M174,fqv[5],fqv[28],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M176,fqv[6],fqv[28],fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M181,fqv[144],fqv[28],fqv[145]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M186,fqv[16],fqv[28],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M190,fqv[18],fqv[28],fqv[147]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M194,fqv[148],fqv[28],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M208,fqv[150],fqv[28],fqv[151]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[152],module,F59,fqv[153]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[154],module,F60,fqv[155]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F61,fqv[157]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F62,fqv[158]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[40],module,F63,fqv[159]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[160],module,F238,fqv[161]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[162],module,F241,fqv[163]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F64,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F65,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F66,fqv[169]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[170],module,F67,fqv[171]);
	local[0]= fqv[49];
	local[1]= fqv[172];
	local[2]= fqv[49];
	local[3]= fqv[173];
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[174];
	local[6]= fqv[38];
	local[7]= fqv[175];
	local[8]= NIL;
	local[9]= fqv[92];
	local[10]= fqv[176];
	local[11]= fqv[177];
	local[12]= makeint(-1);
	local[13]= fqv[178];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[179]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M255,fqv[52],fqv[49],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M257,fqv[43],fqv[49],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M259,fqv[65],fqv[49],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M261,fqv[183],fqv[49],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M263,fqv[16],fqv[49],fqv[185]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F68,fqv[187]);
	local[0]= fqv[54];
	local[1]= fqv[172];
	local[2]= fqv[54];
	local[3]= fqv[173];
	local[4]= loadglobal(fqv[188]);
	local[5]= fqv[174];
	local[6]= fqv[189];
	local[7]= fqv[175];
	local[8]= NIL;
	local[9]= fqv[92];
	local[10]= NIL;
	local[11]= fqv[177];
	local[12]= makeint(-1);
	local[13]= fqv[178];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[179]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[190];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M293,fqv[52],fqv[54],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M295,fqv[59],fqv[54],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M297,fqv[193],fqv[54],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M299,fqv[90],fqv[54],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M301,fqv[2],fqv[54],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M303,fqv[53],fqv[54],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M307,fqv[57],fqv[54],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M309,fqv[5],fqv[54],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M311,fqv[6],fqv[54],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M316,fqv[18],fqv[54],fqv[201]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[202],module,F69,fqv[203]);
	local[0]= fqv[58];
	local[1]= fqv[172];
	local[2]= fqv[58];
	local[3]= fqv[173];
	local[4]= loadglobal(fqv[27]);
	local[5]= fqv[174];
	local[6]= fqv[204];
	local[7]= fqv[175];
	local[8]= NIL;
	local[9]= fqv[92];
	local[10]= NIL;
	local[11]= fqv[177];
	local[12]= makeint(-1);
	local[13]= fqv[178];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[179]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M326,fqv[52],fqv[58],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M328,fqv[18],fqv[58],fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F70,fqv[208]);
	local[0]= fqv[64];
	local[1]= fqv[209];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF495;
	local[0]= fqv[64];
	local[1]= fqv[209];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF497;
	local[0]= fqv[64];
	local[1]= fqv[172];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF498;
IF497:
	local[0]= NIL;
IF498:
	local[0]= fqv[64];
	goto IF496;
IF495:
	local[0]= NIL;
IF496:
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F71,fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F72,fqv[212]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[213],module,F73,fqv[214]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F74,fqv[216]);
	local[0]= fqv[66];
	local[1]= fqv[209];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF499;
	local[0]= fqv[66];
	local[1]= fqv[209];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[66];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF501;
	local[0]= fqv[66];
	local[1]= fqv[172];
	local[2]= loadglobal(fqv[217]);
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF502;
IF501:
	local[0]= NIL;
IF502:
	local[0]= fqv[66];
	goto IF500;
IF499:
	local[0]= NIL;
IF500:
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F75,fqv[219]);
	local[0]= fqv[67];
	local[1]= fqv[209];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF503;
	local[0]= fqv[67];
	local[1]= fqv[209];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF505;
	local[0]= fqv[67];
	local[1]= fqv[172];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF506;
IF505:
	local[0]= NIL;
IF506:
	local[0]= fqv[67];
	goto IF504;
IF503:
	local[0]= NIL;
IF504:
	local[0]= fqv[68];
	local[1]= fqv[209];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF507;
	local[0]= fqv[68];
	local[1]= fqv[209];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF509;
	local[0]= fqv[68];
	local[1]= fqv[172];
	local[2]= loadglobal(fqv[217]);
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF510;
IF509:
	local[0]= NIL;
IF510:
	local[0]= fqv[68];
	goto IF508;
IF507:
	local[0]= NIL;
IF508:
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F76,fqv[220]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[221],module,F379,fqv[222]);
	local[0]= fqv[89];
	local[1]= fqv[172];
	local[2]= fqv[89];
	local[3]= fqv[173];
	local[4]= loadglobal(fqv[30]);
	local[5]= fqv[174];
	local[6]= fqv[223];
	local[7]= fqv[175];
	local[8]= NIL;
	local[9]= fqv[92];
	local[10]= NIL;
	local[11]= fqv[177];
	local[12]= makeint(-1);
	local[13]= fqv[178];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[179]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M385,fqv[224],fqv[89],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M391,fqv[18],fqv[89],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M393,fqv[227],fqv[89],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M402,fqv[229],fqv[89],fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F77,fqv[232]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F78,fqv[234]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[235],module,F79,fqv[236]);
	local[0]= fqv[91];
	local[1]= fqv[172];
	local[2]= makeint(64);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[237];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[238];
	local[1]= fqv[172];
	local[2]= fqv[238];
	local[3]= fqv[173];
	local[4]= loadglobal(fqv[239]);
	local[5]= fqv[174];
	local[6]= fqv[240];
	local[7]= fqv[175];
	local[8]= NIL;
	local[9]= fqv[92];
	local[10]= NIL;
	local[11]= fqv[177];
	local[12]= makeint(-1);
	local[13]= fqv[178];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[179]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M430,fqv[18],fqv[238],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M438,fqv[99],fqv[238],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M447,fqv[95],fqv[238],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M450,fqv[244],fqv[238],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M452,fqv[246],fqv[238],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M460,fqv[248],fqv[238],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M468,fqv[102],fqv[238],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M482,fqv[101],fqv[238],fqv[251]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<13; i++) ftab[i]=fcallx;
}
