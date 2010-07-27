/* Xdecl.c :  entry=Xdecl */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xdecl.h"
#pragma init (register_Xdecl)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xdecl();
extern pointer build_quote_vector();
static register_Xdecl()
  { add_module_initializer("___Xdecl", ___Xdecl);}

static pointer F66();
static pointer F67();
static pointer F68();
static pointer F69();
static pointer F71();
static pointer F72();
static pointer F73();
static pointer F74();

/*c-long-long77*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= argv[1];
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	w = local[2];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1]= (pointer)((integer_t)local[1] + (integer_t)w);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK79:
	ctx->vsp=local; return(local[0]);}

/*set-c-long-long77*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= argv[1];
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	w = local[3];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[2]= (pointer)((integer_t)local[2] + (integer_t)w);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK81:
	ctx->vsp=local; return(local[0]);}

/*c-long*/
static pointer F68(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT84;}
	local[0]= makeint(0);
ENT84:
ENT83:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F78(ctx,2,local+1); /*c-long-long77*/
	local[0]= w;
BLK82:
	ctx->vsp=local; return(local[0]);}

/*set-c-long*/
static pointer F69(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT87;}
	local[0]= NIL;
ENT87:
ENT86:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF88;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F80(ctx,3,local+1); /*set-c-long-long77*/
	local[1]= w;
	goto IF89;
IF88:
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F80(ctx,3,local+1); /*set-c-long-long77*/
	local[1]= w;
IF89:
	w = local[1];
	local[0]= w;
BLK85:
	ctx->vsp=local; return(local[0]);}

/*c-int-integer90*/
static pointer F91(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= argv[1];
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	w = local[2];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[1]= (pointer)((integer_t)local[1] + (integer_t)w);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK92:
	ctx->vsp=local; return(local[0]);}

/*set-c-int-integer90*/
static pointer F93(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= argv[1];
	{ integer_t i,j;
		j=intval(makeint(4)); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	w = local[3];
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[2]= (pointer)((integer_t)local[2] + (integer_t)w);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK94:
	ctx->vsp=local; return(local[0]);}

/*c-int*/
static pointer F73(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT97;}
	local[0]= makeint(0);
ENT97:
ENT96:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F91(ctx,2,local+1); /*c-int-integer90*/
	local[0]= w;
BLK95:
	ctx->vsp=local; return(local[0]);}

/*set-c-int*/
static pointer F74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT100;}
	local[0]= NIL;
ENT100:
ENT99:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF101;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F93(ctx,3,local+1); /*set-c-int-integer90*/
	local[1]= w;
	goto IF102;
IF101:
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F93(ctx,3,local+1); /*set-c-int-integer90*/
	local[1]= w;
IF102:
	w = local[1];
	local[0]= w;
BLK98:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xdecl(ctx,n,argv,env)
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
	local[0]= fqv[2];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF103;
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[4],w);
	goto IF104;
IF103:
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF104:
	local[0]= fqv[6];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[9];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[11];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[12];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[14];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[15];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF105;
	local[0]= fqv[15];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[15];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF107;
	local[0]= fqv[15];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF108;
IF107:
	local[0]= NIL;
IF108:
	local[0]= fqv[15];
	goto IF106;
IF105:
	local[0]= NIL;
IF106:
	local[0]= fqv[18];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF109;
	local[0]= fqv[18];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF111;
	local[0]= fqv[18];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF112;
IF111:
	local[0]= NIL;
IF112:
	local[0]= fqv[18];
	goto IF110;
IF109:
	local[0]= NIL;
IF110:
	local[0]= fqv[19];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF113;
	local[0]= fqv[19];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF115;
	local[0]= fqv[19];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF116;
IF115:
	local[0]= NIL;
IF116:
	local[0]= fqv[19];
	goto IF114;
IF113:
	local[0]= NIL;
IF114:
	local[0]= fqv[20];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF117;
	local[0]= fqv[20];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[20];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF119;
	local[0]= fqv[20];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF120;
IF119:
	local[0]= NIL;
IF120:
	local[0]= fqv[20];
	goto IF118;
IF117:
	local[0]= NIL;
IF118:
	local[0]= fqv[21];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF121;
	local[0]= fqv[21];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[21];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF123;
	local[0]= fqv[21];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF124;
IF123:
	local[0]= NIL;
IF124:
	local[0]= fqv[21];
	goto IF122;
IF121:
	local[0]= NIL;
IF122:
	local[0]= fqv[22];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF125;
	local[0]= fqv[22];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[22];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF127;
	local[0]= fqv[22];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF128;
IF127:
	local[0]= NIL;
IF128:
	local[0]= fqv[22];
	goto IF126;
IF125:
	local[0]= NIL;
IF126:
	local[0]= fqv[23];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF129;
	local[0]= fqv[23];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF131;
	local[0]= fqv[23];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF132;
IF131:
	local[0]= NIL;
IF132:
	local[0]= fqv[23];
	goto IF130;
IF129:
	local[0]= NIL;
IF130:
	local[0]= fqv[24];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF133;
	local[0]= fqv[24];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[24];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF135;
	local[0]= fqv[24];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF136;
IF135:
	local[0]= NIL;
IF136:
	local[0]= fqv[24];
	goto IF134;
IF133:
	local[0]= NIL;
IF134:
	local[0]= fqv[25];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF137;
	local[0]= fqv[25];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[25];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF139;
	local[0]= fqv[25];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF140;
IF139:
	local[0]= NIL;
IF140:
	local[0]= fqv[25];
	goto IF138;
IF137:
	local[0]= NIL;
IF138:
	local[0]= fqv[26];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF141;
	local[0]= fqv[26];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF143;
	local[0]= fqv[26];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF144;
IF143:
	local[0]= NIL;
IF144:
	local[0]= fqv[26];
	goto IF142;
IF141:
	local[0]= NIL;
IF142:
	local[0]= fqv[27];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF145;
	local[0]= fqv[27];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF147;
	local[0]= fqv[27];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF148;
IF147:
	local[0]= NIL;
IF148:
	local[0]= fqv[27];
	goto IF146;
IF145:
	local[0]= NIL;
IF146:
	local[0]= fqv[28];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF149;
	local[0]= fqv[28];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF151;
	local[0]= fqv[28];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF152;
IF151:
	local[0]= NIL;
IF152:
	local[0]= fqv[28];
	goto IF150;
IF149:
	local[0]= NIL;
IF150:
	local[0]= fqv[29];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF153;
	local[0]= fqv[29];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[29];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF155;
	local[0]= fqv[29];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF156;
IF155:
	local[0]= NIL;
IF156:
	local[0]= fqv[29];
	goto IF154;
IF153:
	local[0]= NIL;
IF154:
	local[0]= fqv[30];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF157;
	local[0]= fqv[30];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF159;
	local[0]= fqv[30];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF160;
IF159:
	local[0]= NIL;
IF160:
	local[0]= fqv[30];
	goto IF158;
IF157:
	local[0]= NIL;
IF158:
	local[0]= fqv[31];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF161;
	local[0]= fqv[31];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[31];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF163;
	local[0]= fqv[31];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF164;
IF163:
	local[0]= NIL;
IF164:
	local[0]= fqv[31];
	goto IF162;
IF161:
	local[0]= NIL;
IF162:
	local[0]= fqv[32];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF165;
	local[0]= fqv[32];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[32];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF167;
	local[0]= fqv[32];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF168;
IF167:
	local[0]= NIL;
IF168:
	local[0]= fqv[32];
	goto IF166;
IF165:
	local[0]= NIL;
IF166:
	local[0]= fqv[33];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF169;
	local[0]= fqv[33];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF171;
	local[0]= fqv[33];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF172;
IF171:
	local[0]= NIL;
IF172:
	local[0]= fqv[33];
	goto IF170;
IF169:
	local[0]= NIL;
IF170:
	local[0]= fqv[34];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF173;
	local[0]= fqv[34];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[34];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF175;
	local[0]= fqv[34];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF176;
IF175:
	local[0]= NIL;
IF176:
	local[0]= fqv[34];
	goto IF174;
IF173:
	local[0]= NIL;
IF174:
	local[0]= fqv[35];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF177;
	local[0]= fqv[35];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF179;
	local[0]= fqv[35];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF180;
IF179:
	local[0]= NIL;
IF180:
	local[0]= fqv[35];
	goto IF178;
IF177:
	local[0]= NIL;
IF178:
	local[0]= fqv[36];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF181;
	local[0]= fqv[36];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[36];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF183;
	local[0]= fqv[36];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF184;
IF183:
	local[0]= NIL;
IF184:
	local[0]= fqv[36];
	goto IF182;
IF181:
	local[0]= NIL;
IF182:
	local[0]= fqv[37];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF185;
	local[0]= fqv[37];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF187;
	local[0]= fqv[37];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF188;
IF187:
	local[0]= NIL;
IF188:
	local[0]= fqv[37];
	goto IF186;
IF185:
	local[0]= NIL;
IF186:
	local[0]= fqv[38];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF189;
	local[0]= fqv[38];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF191;
	local[0]= fqv[38];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF192;
IF191:
	local[0]= NIL;
IF192:
	local[0]= fqv[38];
	goto IF190;
IF189:
	local[0]= NIL;
IF190:
	local[0]= fqv[39];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF193;
	local[0]= fqv[39];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF195;
	local[0]= fqv[39];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF196;
IF195:
	local[0]= NIL;
IF196:
	local[0]= fqv[39];
	goto IF194;
IF193:
	local[0]= NIL;
IF194:
	local[0]= fqv[40];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF197;
	local[0]= fqv[40];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF199;
	local[0]= fqv[40];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF200;
IF199:
	local[0]= NIL;
IF200:
	local[0]= fqv[40];
	goto IF198;
IF197:
	local[0]= NIL;
IF198:
	local[0]= fqv[41];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF201;
	local[0]= fqv[41];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF203;
	local[0]= fqv[41];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF204;
IF203:
	local[0]= NIL;
IF204:
	local[0]= fqv[41];
	goto IF202;
IF201:
	local[0]= NIL;
IF202:
	local[0]= fqv[42];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF205;
	local[0]= fqv[42];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF207;
	local[0]= fqv[42];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF208;
IF207:
	local[0]= NIL;
IF208:
	local[0]= fqv[42];
	goto IF206;
IF205:
	local[0]= NIL;
IF206:
	local[0]= fqv[43];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF209;
	local[0]= fqv[43];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF211;
	local[0]= fqv[43];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF212;
IF211:
	local[0]= NIL;
IF212:
	local[0]= fqv[43];
	goto IF210;
IF209:
	local[0]= NIL;
IF210:
	local[0]= fqv[44];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF213;
	local[0]= fqv[44];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF215;
	local[0]= fqv[44];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF216;
IF215:
	local[0]= NIL;
IF216:
	local[0]= fqv[44];
	goto IF214;
IF213:
	local[0]= NIL;
IF214:
	local[0]= fqv[45];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[46];
	local[1]= fqv[17];
	local[2]= fqv[47];
	local[3]= makeint(20);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[48]); /*make-hash-table*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[49];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[50];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF217;
	local[0]= fqv[50];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[50];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF219;
	local[0]= fqv[50];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF220;
IF219:
	local[0]= NIL;
IF220:
	local[0]= fqv[50];
	goto IF218;
IF217:
	local[0]= NIL;
IF218:
	local[0]= fqv[51];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF221;
	local[0]= fqv[51];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[51];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF223;
	local[0]= fqv[51];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF224;
IF223:
	local[0]= NIL;
IF224:
	local[0]= fqv[51];
	goto IF222;
IF221:
	local[0]= NIL;
IF222:
	local[0]= fqv[52];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF225;
	local[0]= fqv[52];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[52];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF227;
	local[0]= fqv[52];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF228;
IF227:
	local[0]= NIL;
IF228:
	local[0]= fqv[52];
	goto IF226;
IF225:
	local[0]= NIL;
IF226:
	local[0]= fqv[53];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF229;
	local[0]= fqv[53];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[53];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF231;
	local[0]= fqv[53];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF232;
IF231:
	local[0]= NIL;
IF232:
	local[0]= fqv[53];
	goto IF230;
IF229:
	local[0]= NIL;
IF230:
	local[0]= fqv[54];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF233;
	local[0]= fqv[54];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[54];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF235;
	local[0]= fqv[54];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF236;
IF235:
	local[0]= NIL;
IF236:
	local[0]= fqv[54];
	goto IF234;
IF233:
	local[0]= NIL;
IF234:
	local[0]= fqv[55];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF237;
	local[0]= fqv[55];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF239;
	local[0]= fqv[55];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF240;
IF239:
	local[0]= NIL;
IF240:
	local[0]= fqv[55];
	goto IF238;
IF237:
	local[0]= NIL;
IF238:
	local[0]= fqv[56];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF241;
	local[0]= fqv[56];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[56];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF243;
	local[0]= fqv[56];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF244;
IF243:
	local[0]= NIL;
IF244:
	local[0]= fqv[56];
	goto IF242;
IF241:
	local[0]= NIL;
IF242:
	local[0]= fqv[57];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF245;
	local[0]= fqv[57];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF247;
	local[0]= fqv[57];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF248;
IF247:
	local[0]= NIL;
IF248:
	local[0]= fqv[57];
	goto IF246;
IF245:
	local[0]= NIL;
IF246:
	local[0]= fqv[58];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF249;
	local[0]= fqv[58];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF251;
	local[0]= fqv[58];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF252;
IF251:
	local[0]= NIL;
IF252:
	local[0]= fqv[58];
	goto IF250;
IF249:
	local[0]= NIL;
IF250:
	local[0]= fqv[59];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF253;
	local[0]= fqv[59];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[59];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF255;
	local[0]= fqv[59];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF256;
IF255:
	local[0]= NIL;
IF256:
	local[0]= fqv[59];
	goto IF254;
IF253:
	local[0]= NIL;
IF254:
	local[0]= fqv[60];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF257;
	local[0]= fqv[60];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF259;
	local[0]= fqv[60];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF260;
IF259:
	local[0]= NIL;
IF260:
	local[0]= fqv[60];
	goto IF258;
IF257:
	local[0]= NIL;
IF258:
	local[0]= fqv[61];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF261;
	local[0]= fqv[61];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF263;
	local[0]= fqv[61];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF264;
IF263:
	local[0]= NIL;
IF264:
	local[0]= fqv[61];
	goto IF262;
IF261:
	local[0]= NIL;
IF262:
	local[0]= fqv[62];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF265;
	local[0]= fqv[62];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF267;
	local[0]= fqv[62];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF268;
IF267:
	local[0]= NIL;
IF268:
	local[0]= fqv[62];
	goto IF266;
IF265:
	local[0]= NIL;
IF266:
	local[0]= fqv[63];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF269;
	local[0]= fqv[63];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[63];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF271;
	local[0]= fqv[63];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF272;
IF271:
	local[0]= NIL;
IF272:
	local[0]= fqv[63];
	goto IF270;
IF269:
	local[0]= NIL;
IF270:
	local[0]= fqv[64];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF273;
	local[0]= fqv[64];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF275;
	local[0]= fqv[64];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF276;
IF275:
	local[0]= NIL;
IF276:
	local[0]= fqv[64];
	goto IF274;
IF273:
	local[0]= NIL;
IF274:
	local[0]= fqv[65];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF277;
	local[0]= fqv[65];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[65];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF279;
	local[0]= fqv[65];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF280;
IF279:
	local[0]= NIL;
IF280:
	local[0]= fqv[65];
	goto IF278;
IF277:
	local[0]= NIL;
IF278:
	local[0]= fqv[66];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF281;
	local[0]= fqv[66];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[66];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF283;
	local[0]= fqv[66];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF284;
IF283:
	local[0]= NIL;
IF284:
	local[0]= fqv[66];
	goto IF282;
IF281:
	local[0]= NIL;
IF282:
	local[0]= fqv[67];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF285;
	local[0]= fqv[67];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF287;
	local[0]= fqv[67];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF288;
IF287:
	local[0]= NIL;
IF288:
	local[0]= fqv[67];
	goto IF286;
IF285:
	local[0]= NIL;
IF286:
	local[0]= fqv[68];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF289;
	local[0]= fqv[68];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF291;
	local[0]= fqv[68];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF292;
IF291:
	local[0]= NIL;
IF292:
	local[0]= fqv[68];
	goto IF290;
IF289:
	local[0]= NIL;
IF290:
	local[0]= fqv[69];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF293;
	local[0]= fqv[69];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF295;
	local[0]= fqv[69];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF296;
IF295:
	local[0]= NIL;
IF296:
	local[0]= fqv[69];
	goto IF294;
IF293:
	local[0]= NIL;
IF294:
	local[0]= fqv[70];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF297;
	local[0]= fqv[70];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF299;
	local[0]= fqv[70];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF300;
IF299:
	local[0]= NIL;
IF300:
	local[0]= fqv[70];
	goto IF298;
IF297:
	local[0]= NIL;
IF298:
	local[0]= fqv[71];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF301;
	local[0]= fqv[71];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF303;
	local[0]= fqv[71];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF304;
IF303:
	local[0]= NIL;
IF304:
	local[0]= fqv[71];
	goto IF302;
IF301:
	local[0]= NIL;
IF302:
	local[0]= fqv[72];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF305;
	local[0]= fqv[72];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF307;
	local[0]= fqv[72];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF308;
IF307:
	local[0]= NIL;
IF308:
	local[0]= fqv[72];
	goto IF306;
IF305:
	local[0]= NIL;
IF306:
	local[0]= fqv[73];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF309;
	local[0]= fqv[73];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF311;
	local[0]= fqv[73];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF312;
IF311:
	local[0]= NIL;
IF312:
	local[0]= fqv[73];
	goto IF310;
IF309:
	local[0]= NIL;
IF310:
	local[0]= fqv[74];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF313;
	local[0]= fqv[74];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF315;
	local[0]= fqv[74];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF316;
IF315:
	local[0]= NIL;
IF316:
	local[0]= fqv[74];
	goto IF314;
IF313:
	local[0]= NIL;
IF314:
	local[0]= fqv[33];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF317;
	local[0]= fqv[33];
	local[1]= fqv[16];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF319;
	local[0]= fqv[33];
	local[1]= fqv[17];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF320;
IF319:
	local[0]= NIL;
IF320:
	local[0]= fqv[33];
	goto IF318;
IF317:
	local[0]= NIL;
IF318:
	local[0]= fqv[75];
	local[1]= fqv[17];
	local[2]= fqv[75];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[77]);
	local[5]= fqv[78];
	local[6]= fqv[79];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[84];
	local[1]= fqv[17];
	local[2]= fqv[84];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[85]);
	local[5]= fqv[78];
	local[6]= fqv[86];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[87];
	local[1]= fqv[17];
	local[2]= fqv[87];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[75]);
	local[5]= fqv[78];
	local[6]= fqv[88];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[89];
	local[1]= fqv[17];
	local[2]= fqv[89];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[75]);
	local[5]= fqv[78];
	local[6]= fqv[90];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[91];
	local[1]= fqv[17];
	local[2]= fqv[91];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[89]);
	local[5]= fqv[78];
	local[6]= fqv[92];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[93];
	local[1]= fqv[17];
	local[2]= fqv[93];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[89]);
	local[5]= fqv[78];
	local[6]= fqv[94];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[95];
	local[1]= fqv[17];
	local[2]= fqv[95];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[93]);
	local[5]= fqv[78];
	local[6]= fqv[96];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[97];
	local[1]= fqv[17];
	local[2]= fqv[97];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[93]);
	local[5]= fqv[78];
	local[6]= fqv[98];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[99];
	local[1]= fqv[17];
	local[2]= fqv[99];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[93]);
	local[5]= fqv[78];
	local[6]= fqv[100];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[101];
	local[1]= fqv[17];
	local[2]= fqv[101];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[99]);
	local[5]= fqv[78];
	local[6]= fqv[102];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[103];
	local[1]= fqv[17];
	local[2]= fqv[103];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[99]);
	local[5]= fqv[78];
	local[6]= fqv[104];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[105];
	local[1]= fqv[17];
	local[2]= fqv[105];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[99]);
	local[5]= fqv[78];
	local[6]= fqv[106];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[107];
	local[1]= fqv[17];
	local[2]= fqv[107];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[101]);
	local[5]= fqv[78];
	local[6]= fqv[108];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[109];
	local[1]= fqv[17];
	local[2]= fqv[109];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[99]);
	local[5]= fqv[78];
	local[6]= fqv[110];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[111];
	local[1]= fqv[17];
	local[2]= fqv[111];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[99]);
	local[5]= fqv[78];
	local[6]= fqv[112];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[113];
	local[1]= fqv[17];
	local[2]= fqv[113];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[95]);
	local[5]= fqv[78];
	local[6]= fqv[114];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[115];
	local[1]= fqv[17];
	local[2]= fqv[115];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[93]);
	local[5]= fqv[78];
	local[6]= fqv[116];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[117];
	local[1]= fqv[17];
	local[2]= fqv[117];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[115]);
	local[5]= fqv[78];
	local[6]= fqv[92];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[118];
	local[1]= fqv[17];
	local[2]= fqv[118];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[93]);
	local[5]= fqv[78];
	local[6]= fqv[119];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[120];
	local[1]= fqv[17];
	local[2]= fqv[120];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[118]);
	local[5]= fqv[78];
	local[6]= fqv[121];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[122];
	local[1]= fqv[17];
	local[2]= fqv[122];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[120]);
	local[5]= fqv[78];
	local[6]= fqv[123];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[124];
	local[1]= fqv[17];
	local[2]= fqv[124];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[122]);
	local[5]= fqv[78];
	local[6]= fqv[125];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[126];
	local[1]= fqv[17];
	local[2]= fqv[126];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[127]);
	local[5]= fqv[78];
	local[6]= fqv[128];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[129];
	local[1]= fqv[17];
	local[2]= fqv[129];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[95]);
	local[5]= fqv[78];
	local[6]= fqv[92];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[130];
	local[1]= fqv[17];
	local[2]= fqv[130];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[101]);
	local[5]= fqv[78];
	local[6]= fqv[131];
	local[7]= fqv[80];
	local[8]= NIL;
	local[9]= fqv[81];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[132];
	local[1]= fqv[133];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[134];
	local[1]= fqv[133];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[135];
	local[1]= fqv[133];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[136];
	local[1]= fqv[133];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[137];
	local[1]= fqv[133];
	local[2]= makeint(8);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[138];
	local[1]= fqv[133];
	local[2]= makeint(16);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[139];
	local[1]= fqv[133];
	local[2]= makeint(32);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[140];
	local[1]= fqv[133];
	local[2]= makeint(64);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[141];
	local[1]= fqv[133];
	local[2]= makeint(128);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[142];
	local[1]= fqv[133];
	local[2]= makeint(256);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[143];
	local[1]= fqv[133];
	local[2]= makeint(512);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[144];
	local[1]= fqv[133];
	local[2]= makeint(1024);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[145];
	local[1]= fqv[133];
	local[2]= makeint(2048);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[146];
	local[1]= fqv[133];
	local[2]= makeint(4096);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[147];
	local[1]= fqv[133];
	local[2]= makeint(8192);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[148];
	local[1]= fqv[133];
	local[2]= makeint(16384);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[149];
	local[1]= fqv[133];
	local[2]= makeint(32768);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[150];
	local[1]= fqv[133];
	local[2]= makeint(65536);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[151];
	local[1]= fqv[133];
	local[2]= makeint(131072);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[152];
	local[1]= fqv[133];
	local[2]= makeint(262144);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[153];
	local[1]= fqv[133];
	local[2]= makeint(524288);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[154];
	local[1]= fqv[133];
	local[2]= makeint(1048576);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[155];
	local[1]= fqv[133];
	local[2]= makeint(2097152);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[156];
	local[1]= fqv[133];
	local[2]= makeint(4194304);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[157];
	local[1]= fqv[133];
	local[2]= makeint(8388608);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[158];
	local[1]= fqv[133];
	local[2]= makeint(16777216);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[159];
	local[1]= fqv[17];
	local[2]= fqv[159];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[160]);
	local[5]= fqv[78];
	local[6]= fqv[92];
	local[7]= fqv[80];
	local[8]= loadglobal(fqv[161]);
	local[9]= fqv[81];
	local[10]= fqv[162];
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[159]);
	local[1]= fqv[163];
	local[2]= fqv[164];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F78,fqv[166]);
	local[0]= fqv[165];
	local[1]= fqv[167];
	local[2]= fqv[168];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[165];
	local[1]= fqv[169];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[165];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[165];
	local[1]= NIL;
	local[2]= fqv[172];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F80,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F68,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F69,fqv[176]);
	local[0]= fqv[159];
	local[1]= fqv[175];
	local[2]= fqv[168];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[159];
	local[1]= fqv[169];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[159];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[159];
	local[1]= NIL;
	local[2]= fqv[172];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[177];
	local[1]= fqv[17];
	local[2]= fqv[177];
	local[3]= fqv[76];
	local[4]= loadglobal(fqv[160]);
	local[5]= fqv[78];
	local[6]= fqv[92];
	local[7]= fqv[80];
	local[8]= loadglobal(fqv[161]);
	local[9]= fqv[81];
	local[10]= fqv[162];
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[82];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[83]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[177]);
	local[1]= fqv[163];
	local[2]= fqv[178];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F91,fqv[180]);
	local[0]= fqv[179];
	local[1]= fqv[181];
	local[2]= fqv[168];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[179];
	local[1]= fqv[169];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[179];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[179];
	local[1]= NIL;
	local[2]= fqv[172];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F93,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F73,fqv[183]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[184],module,F74,fqv[185]);
	local[0]= fqv[177];
	local[1]= fqv[184];
	local[2]= fqv[168];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[177];
	local[1]= fqv[169];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[177];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[170]); /*remprop*/
	local[0]= fqv[177];
	local[1]= NIL;
	local[2]= fqv[172];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[186];
	local[1]= fqv[187];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[188]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
