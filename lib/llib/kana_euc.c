/* kana_euc.c :  entry=kana_euc */
/* compiled by EusLisp 8.26 for Linux  created on 2003年 12月 29日 月曜日 09:13:31 JST */
#include "eus.h"
#include "kana_euc.h"
#pragma init (register_kana_euc)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___kana_euc();
extern pointer build_quote_vector();
static register_kana_euc()
  { add_module_initializer("___kana_euc", ___kana_euc);}

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
static pointer F80();
static pointer F81();
static pointer F82();

/*vowelp*/
static pointer F58(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*member*/
	local[0]= w;
BLK83:
	ctx->vsp=local; return(local[0]);}

/*vowel-ord*/
static pointer F59(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (local[0]==NIL) goto IF85;
	local[1]= local[0];
	goto IF86;
IF85:
	local[1]= makeint(0);
IF86:
	w = local[1];
	local[0]= w;
BLK84:
	ctx->vsp=local; return(local[0]);}

/*vowel-ord3*/
static pointer F60(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (local[0]!=NIL) goto CON88;
CON89:
	local[0]= makeint(1);
	goto CON88;
CON90:
	local[0]= NIL;
CON88:
	w = local[0];
	local[0]= w;
BLK87:
	ctx->vsp=local; return(local[0]);}

/*char-string*/
static pointer F61(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(1);
	local[1]= fqv[5];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[6];
	local[4]= fqv[7];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,5,local+0,&ftab[2],fqv[8]); /*make-array*/
	local[0]= w;
BLK91:
	ctx->vsp=local; return(local[0]);}

/*kana-decimal*/
static pointer F62(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT94;}
	local[0]= T;
ENT94:
ENT93:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON96;
	local[1]= loadglobal(fqv[9]);
	local[2]= fqv[10];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F62(ctx,1,local+3); /*kana-decimal*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
	goto CON95;
CON96:
	local[1]= argv[0];
	local[2]= makeint(10);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON97;
	local[1]= argv[0];
	local[2]= local[1];
	if (fqv[11]!=local[2]) goto IF99;
	local[2]= fqv[12];
	goto IF100;
IF99:
	local[2]= local[1];
	if (fqv[13]!=local[2]) goto IF101;
	if (local[0]==NIL) goto IF103;
	local[2]= fqv[14];
	goto IF104;
IF103:
	local[2]= fqv[15];
IF104:
	goto IF102;
IF101:
	local[2]= local[1];
	if (fqv[16]!=local[2]) goto IF105;
	local[2]= fqv[17];
	goto IF106;
IF105:
	local[2]= local[1];
	if (fqv[18]!=local[2]) goto IF107;
	local[2]= fqv[19];
	goto IF108;
IF107:
	local[2]= local[1];
	if (fqv[20]!=local[2]) goto IF109;
	local[2]= fqv[21];
	goto IF110;
IF109:
	local[2]= local[1];
	if (fqv[22]!=local[2]) goto IF111;
	local[2]= fqv[23];
	goto IF112;
IF111:
	local[2]= local[1];
	if (fqv[24]!=local[2]) goto IF113;
	local[2]= fqv[25];
	goto IF114;
IF113:
	local[2]= local[1];
	if (fqv[26]!=local[2]) goto IF115;
	local[2]= fqv[27];
	goto IF116;
IF115:
	local[2]= local[1];
	if (fqv[28]!=local[2]) goto IF117;
	local[2]= fqv[29];
	goto IF118;
IF117:
	local[2]= local[1];
	if (fqv[30]!=local[2]) goto IF119;
	local[2]= fqv[31];
	goto IF120;
IF119:
	local[2]= NIL;
IF120:
IF118:
IF116:
IF114:
IF112:
IF110:
IF108:
IF106:
IF102:
IF100:
	w = local[2];
	local[1]= w;
	goto CON95;
CON97:
	local[1]= argv[0];
	local[2]= makeint(100);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON121;
	local[1]= loadglobal(fqv[9]);
	local[2]= argv[0];
	local[3]= makeint(10);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)F62(ctx,2,local+2); /*kana-decimal*/
	local[2]= w;
	local[3]= fqv[32];
	local[4]= argv[0];
	local[5]= makeint(10);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF122;
	local[4]= fqv[33];
	goto IF123;
IF122:
	local[4]= argv[0];
	local[5]= makeint(10);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F62(ctx,1,local+4); /*kana-decimal*/
	local[4]= w;
IF123:
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,4,local+1); /*concatenate*/
	local[1]= w;
	goto CON95;
CON121:
	local[1]= argv[0];
	local[2]= makeint(1000);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON124;
	local[1]= loadglobal(fqv[9]);
	local[2]= argv[0];
	local[3]= makeint(100);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)F62(ctx,2,local+2); /*kana-decimal*/
	local[2]= w;
	local[3]= fqv[34];
	local[4]= argv[0];
	local[5]= makeint(100);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF125;
	local[4]= fqv[35];
	goto IF126;
IF125:
	local[4]= argv[0];
	local[5]= makeint(100);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F62(ctx,1,local+4); /*kana-decimal*/
	local[4]= w;
IF126:
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,4,local+1); /*concatenate*/
	local[1]= w;
	goto CON95;
CON124:
	local[1]= argv[0];
	local[2]= makeint(10000);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON127;
	local[1]= loadglobal(fqv[9]);
	local[2]= argv[0];
	local[3]= makeint(1000);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)F62(ctx,2,local+2); /*kana-decimal*/
	local[2]= w;
	local[3]= fqv[36];
	local[4]= argv[0];
	local[5]= makeint(1000);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF128;
	local[4]= fqv[37];
	goto IF129;
IF128:
	local[4]= argv[0];
	local[5]= makeint(1000);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F62(ctx,1,local+4); /*kana-decimal*/
	local[4]= w;
IF129:
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,4,local+1); /*concatenate*/
	local[1]= w;
	goto CON95;
CON127:
	local[1]= argv[0];
	local[2]= makeint(100000);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON130;
	local[1]= loadglobal(fqv[9]);
	local[2]= argv[0];
	local[3]= makeint(10000);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)F62(ctx,2,local+2); /*kana-decimal*/
	local[2]= w;
	local[3]= fqv[38];
	local[4]= argv[0];
	local[5]= makeint(10000);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF131;
	local[4]= fqv[39];
	goto IF132;
IF131:
	local[4]= argv[0];
	local[5]= makeint(10000);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F62(ctx,1,local+4); /*kana-decimal*/
	local[4]= w;
IF132:
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,4,local+1); /*concatenate*/
	local[1]= w;
	goto CON95;
CON130:
	local[1]= fqv[40];
	goto CON95;
CON133:
	local[1]= NIL;
CON95:
	w = local[1];
	local[0]= w;
BLK92:
	ctx->vsp=local; return(local[0]);}

/*romnum1*/
static pointer F63(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	local[1]= w;
	if (local[1]!=NIL) goto IF135;
	w = fqv[41];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK134;
	goto IF136;
IF135:
	local[2]= NIL;
IF136:
WHL137:
	if (local[1]==NIL) goto WHX138;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)DIGITP(ctx,1,local+2); /*digit-char-p*/
	if (w==NIL) goto WHX138;
	local[2]= local[1];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= argv[0];
	local[3]= NIL;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,3,local+2); /*read-char*/
	local[1] = w;
	goto WHL137;
WHX138:
	local[2]= NIL;
BLK139:
	if (local[1]==NIL) goto IF140;
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)UNREADCH(ctx,2,local+2); /*unread-char*/
	local[2]= w;
	goto IF141;
IF140:
	local[2]= NIL;
IF141:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[2]= w;
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[42]); /*read-from-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F62(ctx,1,local+2); /*kana-decimal*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F65(ctx,1,local+2); /*romkan*/
	local[0]= w;
BLK134:
	ctx->vsp=local; return(local[0]);}

/*romnum*/
static pointer F64(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= NIL;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,3,local+2); /*read-char*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[2];
	local[6]= makeint(43);
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto CON144;
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)F65(ctx,1,local+5); /*romkan*/
	local[5]= w;
	goto CON143;
CON144:
	local[5]= local[2];
	local[6]= makeint(45);
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto CON145;
	local[5]= fqv[44];
	ctx->vsp=local+6;
	w=(pointer)F65(ctx,1,local+5); /*romkan*/
	local[5]= w;
	goto CON143;
CON145:
	local[5]= local[2];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)UNREADCH(ctx,2,local+5); /*unread-char*/
	local[5]= fqv[45];
	goto CON143;
CON146:
	local[5]= NIL;
CON143:
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F63(ctx,1,local+5); /*romnum1*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,3,local+5); /*read-char*/
	local[2] = w;
WHL147:
	local[5]= local[2];
	local[6]= makeint(46);
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto WHX148;
	local[5]= fqv[46];
	ctx->vsp=local+6;
	w=(pointer)F65(ctx,1,local+5); /*romkan*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F63(ctx,1,local+5); /*romnum1*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,3,local+5); /*read-char*/
	local[2] = w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)PRINT(ctx,1,local+5); /*print*/
	goto WHL147;
WHX148:
	local[5]= NIL;
BLK149:
	if (local[2]==NIL) goto IF150;
	local[5]= local[2];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)UNREADCH(ctx,2,local+5); /*unread-char*/
	local[5]= w;
	goto IF151;
IF150:
	local[5]= NIL;
IF151:
	local[5]= (pointer)get_sym_func(fqv[47]);
	local[6]= loadglobal(fqv[9]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,3,local+5); /*apply*/
	local[0]= w;
BLK142:
	ctx->vsp=local; return(local[0]);}

/*romkan*/
static pointer F65(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	{jmp_buf jb;
	w = fqv[48];
	ctx->vsp=local+0;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT153;}
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,1,local+6,&ftab[4],fqv[49]); /*string-upcase*/
	local[6]= w;
	local[7]= fqv[50];
	local[8]= fqv[51];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,2,local+7,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF154;
	local[7]= fqv[50];
	local[8]= fqv[52];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,2,local+7,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	goto IF155;
IF154:
	local[7]= NIL;
IF155:
	local[8]= fqv[53];
	local[9]= fqv[54];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,2,local+8,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF156;
	local[8]= fqv[53];
	local[9]= fqv[55];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,2,local+8,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	goto IF157;
IF156:
	local[8]= NIL;
IF157:
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,3,local+6,&ftab[5],fqv[56]); /*make-string-input-stream*/
	local[6]= w;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,FLET158,env,argv,local);
WHL159:
	local[14]= local[6];
	local[15]= NIL;
	local[16]= fqv[57];
	ctx->vsp=local+17;
	w=(pointer)READCH(ctx,3,local+14); /*read-char*/
	local[7] = w;
	local[14]= local[7];
	local[15]= fqv[57];
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w!=NIL) goto WHX160;
	local[14]= local[7];
	local[15]= fqv[58];
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,2,local+14,&ftab[1],fqv[3]); /*assoc*/
	local[10] = w;
	if (local[10]==NIL) goto CON163;
	local[12] = local[7];
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON162;
CON163:
	local[14]= local[7];
	local[15]= makeint(45);
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w==NIL) goto CON164;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= makeint(32);
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w!=NIL) goto CON164;
	local[14]= local[12];
	local[15]= fqv[59];
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,2,local+14,&ftab[1],fqv[3]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON162;
CON164:
	local[14]= local[7];
	local[15]= makeint(43);
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w!=NIL) goto OR166;
	local[14]= local[7];
	local[15]= makeint(45);
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w!=NIL) goto OR166;
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)DIGITP(ctx,1,local+14); /*digit-char-p*/
	if (w!=NIL) goto OR166;
	goto CON165;
OR166:
	local[14]= local[7];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)UNREADCH(ctx,2,local+14); /*unread-char*/
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(pointer)F64(ctx,1,local+14); /*romnum*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON162;
CON165:
	local[14]= local[7];
	if (makeint(39)==local[14]) goto OR168;
	local[14]= local[7];
	if (makeint(92)==local[14]) goto OR168;
	goto CON167;
OR168:
	w = local[13];
	ctx->vsp=local+14;
	w=FLET158(ctx,0,local+14,w);
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)F61(ctx,1,local+14); /*char-string*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON162;
CON167:
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)ALPHAP(ctx,1,local+14); /*alpha-char-p*/
	if (w!=NIL) goto CON169;
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)F61(ctx,1,local+14); /*char-string*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON162;
CON169:
	w = local[13];
	ctx->vsp=local+14;
	w=FLET158(ctx,0,local+14,w);
	local[8] = w;
	local[12] = local[8];
	local[14]= local[8];
	ctx->vsp=local+15;
	w=(pointer)F58(ctx,1,local+14); /*vowelp*/
	if (w==NIL) goto CON172;
	local[14]= loadglobal(fqv[60]);
	local[15]= local[7];
	local[16]= makeint(65);
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,2,local+15); /*-*/
	local[15]= w;
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)F59(ctx,1,local+16); /*vowel-ord*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,3,local+14); /*aref*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON172:
	local[14]= local[8];
	if (makeint(89)!=local[14]) goto CON173;
	w = local[13];
	ctx->vsp=local+14;
	w=FLET158(ctx,0,local+14,w);
	local[9] = w;
	local[12] = local[9];
	local[14]= loadglobal(fqv[61]);
	local[15]= local[7];
	local[16]= makeint(65);
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,2,local+15); /*-*/
	local[15]= w;
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)F60(ctx,1,local+16); /*vowel-ord3*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,3,local+14); /*aref*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON173:
	local[14]= local[7];
	if (makeint(84)!=local[14]) goto CON174;
	local[14]= local[8];
	if (makeint(83)!=local[14]) goto CON174;
	w = local[13];
	ctx->vsp=local+14;
	w=FLET158(ctx,0,local+14,w);
	local[9] = w;
	local[12] = local[9];
	local[14]= loadglobal(fqv[62]);
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)F59(ctx,1,local+15); /*vowel-ord*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON174:
	local[14]= local[7];
	if (makeint(67)!=local[14]) goto CON175;
	local[14]= local[8];
	if (makeint(72)!=local[14]) goto CON175;
	w = local[13];
	ctx->vsp=local+14;
	w=FLET158(ctx,0,local+14,w);
	local[9] = w;
	local[12] = local[9];
	local[14]= loadglobal(fqv[63]);
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)F59(ctx,1,local+15); /*vowel-ord*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON175:
	local[14]= local[7];
	if (makeint(83)!=local[14]) goto CON176;
	local[14]= local[8];
	if (makeint(72)!=local[14]) goto CON176;
	w = local[13];
	ctx->vsp=local+14;
	w=FLET158(ctx,0,local+14,w);
	local[9] = w;
	local[12] = local[9];
	local[14]= loadglobal(fqv[64]);
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)F59(ctx,1,local+15); /*vowel-ord*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON176:
	local[14]= local[7];
	if (makeint(78)!=local[14]) goto CON177;
	local[14]= local[8];
	if (makeint(78)!=local[14]) goto CON177;
	local[14]= fqv[65];
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON177:
	local[14]= local[7];
	if (makeint(78)!=local[14]) goto CON178;
	local[14]= local[8];
	ctx->vsp=local+15;
	w=(pointer)F58(ctx,1,local+14); /*vowelp*/
	if (w!=NIL) goto CON178;
	local[14]= local[8];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)UNREADCH(ctx,2,local+14); /*unread-char*/
	local[14]= fqv[66];
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON178:
	local[14]= local[7];
	if (local[8]!=local[14]) goto CON179;
	local[14]= fqv[67];
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[8];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)UNREADCH(ctx,2,local+14); /*unread-char*/
	local[14]= w;
	goto CON171;
CON179:
	local[14]= makeint(2);
	local[15]= fqv[6];
	local[16]= fqv[68];
	local[17]= fqv[5];
	local[18]= local[7];
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,2,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[2])(ctx,5,local+14,&ftab[2],fqv[8]); /*make-array*/
	local[14]= w;
	w = local[11];
	ctx->vsp=local+15;
	local[11] = cons(ctx,local[14],w);
	local[14]= local[11];
	goto CON171;
CON180:
	local[14]= NIL;
CON171:
	goto CON162;
CON170:
	local[14]= NIL;
CON162:
	goto WHL159;
WHX160:
	local[14]= NIL;
BLK161:
	local[14]= fqv[48];
	local[15]= (pointer)get_sym_func(fqv[47]);
	local[16]= loadglobal(fqv[9]);
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)NREVERSE(ctx,1,local+17); /*nreverse*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,3,local+15); /*apply*/
	ctx->vsp=local+15;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[14];
CAT153:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK152:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET158(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[6];
	local[1]= NIL;
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)READCH(ctx,3,local+0); /*read-char*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF181;
	local[1]= fqv[48];
	local[2]= (pointer)get_sym_func(fqv[47]);
	local[3]= loadglobal(fqv[9]);
	local[4]= env->c.clo.env2[11];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF182;
IF181:
	local[1]= local[0];
IF182:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*romanji-date*/
static pointer F66(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT185;}
	local[0]= T;
ENT185:
ENT184:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= fqv[69];
	if (local[0]==NIL) goto IF186;
	local[3]= (pointer)((integer_t)(argv[0])+4);
	ctx->vsp=local+4;
	w=(pointer)F62(ctx,1,local+3); /*kana-decimal*/
	local[3]= w;
	goto IF187;
IF186:
	local[3]= (pointer)((integer_t)(argv[0])+4);
IF187:
	local[4]= argv[1];
	local[5]= local[4];
	if (fqv[70]!=local[5]) goto IF189;
	local[5]= fqv[71];
	goto IF190;
IF189:
	local[5]= local[4];
	if (fqv[72]!=local[5]) goto IF191;
	local[5]= fqv[73];
	goto IF192;
IF191:
	local[5]= local[4];
	if (fqv[74]!=local[5]) goto IF193;
	local[5]= fqv[75];
	goto IF194;
IF193:
	local[5]= local[4];
	if (fqv[76]!=local[5]) goto IF195;
	local[5]= fqv[77];
	goto IF196;
IF195:
	local[5]= local[4];
	if (fqv[78]!=local[5]) goto IF197;
	local[5]= fqv[79];
	goto IF198;
IF197:
	local[5]= local[4];
	if (fqv[80]!=local[5]) goto IF199;
	local[5]= fqv[81];
	goto IF200;
IF199:
	local[5]= local[4];
	if (fqv[82]!=local[5]) goto IF201;
	local[5]= fqv[83];
	goto IF202;
IF201:
	local[5]= local[4];
	if (fqv[84]!=local[5]) goto IF203;
	local[5]= fqv[85];
	goto IF204;
IF203:
	local[5]= local[4];
	if (fqv[86]!=local[5]) goto IF205;
	local[5]= fqv[87];
	goto IF206;
IF205:
	local[5]= local[4];
	if (fqv[88]!=local[5]) goto IF207;
	local[5]= fqv[89];
	goto IF208;
IF207:
	local[5]= local[4];
	if (fqv[90]!=local[5]) goto IF209;
	local[5]= fqv[91];
	goto IF210;
IF209:
	if (T==NIL) goto IF211;
	local[5]= NIL;
	local[6]= fqv[92];
	if (local[0]==NIL) goto IF213;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)F62(ctx,1,local+7); /*kana-decimal*/
	local[7]= w;
	goto IF214;
IF213:
	local[7]= argv[1];
IF214:
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	goto IF212;
IF211:
	local[5]= NIL;
IF212:
IF210:
IF208:
IF206:
IF204:
IF202:
IF200:
IF198:
IF196:
IF194:
IF192:
IF190:
	w = local[5];
	local[4]= w;
	local[5]= fqv[93];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[0]= w;
BLK183:
	ctx->vsp=local; return(local[0]);}

/*kana-date*/
static pointer F67(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT218;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT218:
	if (n>=2) { local[1]=(argv[1]); goto ENT217;}
	local[1]= T;
ENT217:
ENT216:
	if (n>2) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	local[7]= fqv[94];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto IF219;
	local[6]= loadglobal(fqv[95]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[94];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = local[6];
	local[0] = w;
	local[6]= local[0];
	goto IF220;
IF219:
	local[6]= NIL;
IF220:
	local[6]= local[0];
	local[7]= loadglobal(fqv[95]);
	ctx->vsp=local+8;
	w=(pointer)DERIVEDP(ctx,2,local+6); /*derivedp*/
	if (w==NIL) goto CON223;
	local[6]= local[0];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[2] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[3] = w;
	local[6]= local[0];
	local[7]= fqv[98];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[4] = w;
	local[6]= local[0];
	local[7]= fqv[99];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[5] = w;
	local[6]= local[5];
	goto CON222;
CON223:
	local[6]= local[0];
	local[7]= loadglobal(fqv[100]);
	ctx->vsp=local+8;
	w=(pointer)DERIVEDP(ctx,2,local+6); /*derivedp*/
	if (w==NIL) goto CON224;
	local[6]= local[0];
	local[7]= makeint(5);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[2] = w;
	local[6]= local[0];
	local[7]= makeint(4);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[3] = w;
	local[6]= local[0];
	local[7]= makeint(3);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[4] = w;
	local[6]= local[0];
	local[7]= makeint(6);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[5] = w;
	local[6]= local[5];
	goto CON222;
CON224:
	local[6]= fqv[101];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto CON222;
CON225:
	local[6]= NIL;
CON222:
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)F66(ctx,3,local+6); /*romanji-date*/
	local[0]= w;
BLK215:
	ctx->vsp=local; return(local[0]);}

/*kana-time*/
static pointer F68(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT229;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT229:
	if (n>=2) { local[1]=(argv[1]); goto ENT228;}
	local[1]= NIL;
ENT228:
ENT227:
	if (n>2) maerror();
	local[2]= local[0];
	local[3]= fqv[94];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	if (w==NIL) goto IF230;
	local[2]= loadglobal(fqv[95]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[94];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	goto IF231;
IF230:
	local[2]= NIL;
IF231:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= loadglobal(fqv[95]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto CON234;
	local[5]= local[0];
	local[6]= fqv[102];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[2] = w;
	local[5]= local[0];
	local[6]= fqv[103];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[3] = w;
	local[5]= local[3];
	goto CON233;
CON234:
	local[5]= local[0];
	local[6]= loadglobal(fqv[100]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto CON235;
	local[5]= local[0];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[2] = w;
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[3] = w;
	local[5]= local[3];
	goto CON233;
CON235:
	local[5]= fqv[104];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,1,local+5); /*error*/
	local[5]= w;
	goto CON233;
CON236:
	local[5]= NIL;
CON233:
	local[5]= local[2];
	local[6]= makeint(12);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF237;
	local[5]= local[2];
	local[6]= makeint(12);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	goto IF238;
IF237:
	local[5]= local[2];
IF238:
	local[4] = local[5];
	local[5]= NIL;
	local[6]= fqv[105];
	local[7]= local[2];
	local[8]= makeint(12);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF239;
	local[7]= fqv[106];
	goto IF240;
IF239:
	local[7]= fqv[107];
IF240:
	if (local[1]==NIL) goto IF241;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F62(ctx,1,local+8); /*kana-decimal*/
	local[8]= w;
	goto IF242;
IF241:
	local[8]= local[4];
IF242:
	if (local[1]==NIL) goto IF243;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)F62(ctx,1,local+9); /*kana-decimal*/
	local[9]= w;
	goto IF244;
IF243:
	local[9]= local[3];
IF244:
	local[10]= local[3];
	local[11]= makeint(10);
	ctx->vsp=local+12;
	w=(pointer)MOD(ctx,2,local+10); /*mod*/
	local[10]= w;
	local[11]= fqv[108];
	ctx->vsp=local+12;
	w=(*ftab[0])(ctx,2,local+10,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF245;
	local[10]= fqv[109];
	goto IF246;
IF245:
	local[10]= fqv[110];
IF246:
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,6,local+5); /*format*/
	local[0]= w;
BLK226:
	ctx->vsp=local; return(local[0]);}

/*sjis2euc-char*/
static pointer F69(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= makeint(159);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	if (w==NIL) goto IF248;
	local[0]= argv[1];
	local[1]= makeint(159);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF250;
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)ASH(ctx,2,local+0); /*ash*/
	local[0]= w;
	w = makeint(225);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] - (integer_t)w);
	goto IF251;
IF250:
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)ASH(ctx,2,local+0); /*ash*/
	local[0]= w;
	w = makeint(224);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] - (integer_t)w);
IF251:
	argv[0] = local[0];
	local[0]= argv[0];
	goto IF249;
IF248:
	local[0]= argv[1];
	local[1]= makeint(159);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF252;
	local[0]= argv[1];
	local[1]= makeint(159);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF254;
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)ASH(ctx,2,local+0); /*ash*/
	local[0]= w;
	w = makeint(353);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] - (integer_t)w);
	goto IF255;
IF254:
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)ASH(ctx,2,local+0); /*ash*/
	local[0]= w;
	w = makeint(352);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] - (integer_t)w);
IF255:
	argv[0] = local[0];
	local[0]= argv[0];
	goto IF253;
IF252:
	local[0]= NIL;
IF253:
IF249:
	local[0]= argv[1];
	local[1]= makeint(127);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF256;
	local[0]= argv[1];
	local[1]= makeint(31);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[1] = w;
	local[0]= argv[1];
	goto IF257;
IF256:
	local[0]= argv[1];
	local[1]= makeint(159);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF258;
	local[0]= argv[1];
	local[1]= makeint(32);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[1] = w;
	local[0]= argv[1];
	goto IF259;
IF258:
	local[0]= argv[1];
	local[1]= makeint(126);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[1] = w;
	local[0]= argv[1];
IF259:
IF257:
	local[0]= makeint(128);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGIOR(ctx,2,local+0); /*logior*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)WRTBYTE(ctx,2,local+0); /*write-byte*/
	local[0]= makeint(128);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGIOR(ctx,2,local+0); /*logior*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)WRTBYTE(ctx,2,local+0); /*write-byte*/
	local[0]= w;
BLK247:
	ctx->vsp=local; return(local[0]);}

/*sjis2euc*/
static pointer F70(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= fqv[111];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF261;
	local[1]= fqv[50];
	local[2]= fqv[112];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto IF262;
IF261:
	local[1]= NIL;
IF262:
	local[2]= fqv[53];
	local[3]= fqv[113];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF263;
	local[2]= fqv[53];
	local[3]= fqv[114];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF264;
IF263:
	local[2]= NIL;
IF264:
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[56]); /*make-string-input-stream*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,0,local+1,&ftab[6],fqv[115]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= NIL;
WHL265:
	local[5]= local[0];
	local[6]= NIL;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,3,local+5); /*read-char*/
	local[2] = w;
	w = local[2];
	if (!isint(w)) goto WHX266;
	if (local[4]!=NIL) goto OR270;
	local[5]= local[2];
	w = makeint(128);
	if ((integer_t)local[5] < (integer_t)w) goto OR270;
	goto CON269;
OR270:
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)WRTBYTE(ctx,2,local+5); /*write-byte*/
	local[5]= w;
	goto CON268;
CON269:
	local[5]= makeint(128);
	local[6]= local[2];
	local[7]= makeint(160);
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,3,local+5); /*<*/
	if (w!=NIL) goto OR272;
	local[5]= makeint(224);
	local[6]= local[2];
	local[7]= makeint(239);
	ctx->vsp=local+8;
	w=(pointer)LSEQP(ctx,3,local+5); /*<=*/
	if (w!=NIL) goto OR272;
	goto CON271;
OR272:
	local[5]= local[0];
	local[6]= NIL;
	local[7]= makeint(-1);
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,3,local+5); /*read-char*/
	local[3] = w;
	local[5]= makeint(64);
	local[6]= local[3];
	local[7]= makeint(252);
	ctx->vsp=local+8;
	w=(pointer)LSEQP(ctx,3,local+5); /*<=*/
	if (w==NIL) goto CON274;
	local[5]= local[3];
	local[6]= makeint(127);
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,2,local+5,&ftab[7],fqv[116]); /*/=*/
	if (w==NIL) goto CON274;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F69(ctx,3,local+5); /*sjis2euc-char*/
	local[5]= w;
	goto CON273;
CON274:
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)WRTBYTE(ctx,2,local+5); /*write-byte*/
	local[5]= local[3];
	local[6]= makeint(-1);
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,2,local+5,&ftab[7],fqv[116]); /*/=*/
	if (w==NIL) goto IF276;
	local[5]= local[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)WRTBYTE(ctx,2,local+5); /*write-byte*/
	local[5]= w;
	goto IF277;
IF276:
	local[5]= NIL;
IF277:
	goto CON273;
CON275:
	local[5]= NIL;
CON273:
	goto CON268;
CON271:
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)WRTBYTE(ctx,2,local+5); /*write-byte*/
	local[4] = T;
	local[5]= local[4];
	goto CON268;
CON278:
	local[5]= NIL;
CON268:
	goto WHL265;
WHX266:
	local[5]= NIL;
BLK267:
	w = local[5];
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[117]); /*get-output-stream-string*/
	local[0]= w;
BLK260:
	ctx->vsp=local; return(local[0]);}

/*euc2sjis-char*/
static pointer F71(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(127);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	argv[0] = w;
	local[0]= makeint(127);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	argv[1] = w;
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= makeint(-1);
	ctx->vsp=local+2;
	w=(pointer)ASH(ctx,2,local+0); /*ash*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(94);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,2,local+1); /*<=*/
	if (w==NIL) goto IF280;
	local[1]= makeint(113);
	goto IF281;
IF280:
	local[1]= makeint(177);
IF281:
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)WRTBYTE(ctx,2,local+0); /*write-byte*/
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)LOGTEST(ctx,2,local+1); /*logtest*/
	if (w==NIL) goto IF282;
	local[1]= argv[1];
	local[2]= makeint(96);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF284;
	local[1]= makeint(31);
	goto IF285;
IF284:
	local[1]= makeint(32);
IF285:
	goto IF283;
IF282:
	local[1]= makeint(126);
IF283:
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)WRTBYTE(ctx,2,local+0); /*write-byte*/
	local[0]= w;
BLK279:
	ctx->vsp=local; return(local[0]);}

/*euc2sjis*/
static pointer F72(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= fqv[118];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF287;
	local[1]= fqv[50];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto IF288;
IF287:
	local[1]= NIL;
IF288:
	local[2]= fqv[53];
	local[3]= fqv[120];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF289;
	local[2]= fqv[53];
	local[3]= fqv[121];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF290;
IF289:
	local[2]= NIL;
IF290:
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[56]); /*make-string-input-stream*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,0,local+1,&ftab[6],fqv[115]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= makeint(0);
WHL291:
	local[4]= local[0];
	local[5]= NIL;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,3,local+4); /*read-char*/
	local[2] = w;
	w = local[2];
	if (!isint(w)) goto WHX292;
	local[4]= makeint(129);
	local[5]= local[2];
	local[6]= makeint(240);
	ctx->vsp=local+7;
	w=(pointer)LSEQP(ctx,3,local+4); /*<=*/
	if (w==NIL) goto CON295;
	local[4]= local[0];
	local[5]= NIL;
	local[6]= makeint(-1);
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,3,local+4); /*read-char*/
	local[3] = w;
	local[4]= makeint(129);
	local[5]= local[3];
	local[6]= makeint(254);
	ctx->vsp=local+7;
	w=(pointer)LSEQP(ctx,3,local+4); /*<=*/
	if (w==NIL) goto CON297;
	local[4]= local[2];
	local[5]= local[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)F71(ctx,3,local+4); /*euc2sjis-char*/
	local[4]= w;
	goto CON296;
CON297:
	local[4]= local[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= local[3];
	local[5]= makeint(-1);
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,2,local+4,&ftab[7],fqv[116]); /*/=*/
	if (w==NIL) goto IF299;
	local[4]= local[3];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF300;
IF299:
	local[4]= NIL;
IF300:
	goto CON296;
CON298:
	local[4]= NIL;
CON296:
	goto CON294;
CON295:
	local[4]= local[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto CON294;
CON301:
	local[4]= NIL;
CON294:
	goto WHL291;
WHX292:
	local[4]= NIL;
BLK293:
	w = local[4];
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[117]); /*get-output-stream-string*/
	local[0]= w;
BLK286:
	ctx->vsp=local; return(local[0]);}

/*jis2euc*/
static pointer F73(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[122]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,FLET303,env,argv,local);
	local[8]= makeint(0);
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
WHL305:
	local[10]= local[8];
	w = local[9];
	if ((integer_t)local[10] >= (integer_t)w) goto WHX306;
	local[10]= argv[0];
	{ register integer_t i=intval(local[8]);
	  w=makeint(local[10]->c.str.chars[i]);}
	local[2] = w;
	local[10]= local[4];
	local[11]= local[10];
	if (fqv[123]!=local[11]) goto IF309;
	local[11]= local[2];
	local[12]= makeint(27);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF311;
	local[4] = makeint(1);
	local[11]= local[4];
	goto IF312;
IF311:
	if (local[3]==NIL) goto IF313;
	local[11]= makeint(128);
	goto IF314;
IF313:
	local[11]= makeint(0);
IF314:
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)LOGIOR(ctx,2,local+11); /*logior*/
	local[11]= w;
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= w;
IF312:
	goto IF310;
IF309:
	local[11]= local[10];
	if (fqv[124]!=local[11]) goto IF315;
	local[5] = local[2];
	local[11]= local[2];
	local[12]= makeint(36);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF317;
	local[4] = makeint(2);
	local[11]= local[4];
	goto IF318;
IF317:
	local[11]= local[2];
	local[12]= makeint(40);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF319;
	local[4] = makeint(4);
	local[11]= local[4];
	goto IF320;
IF319:
	local[11]= makeint(27);
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= local[2];
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= w;
IF320:
IF318:
	goto IF316;
IF315:
	local[11]= local[10];
	if (fqv[125]!=local[11]) goto IF321;
	local[6] = local[2];
	local[11]= local[2];
	local[12]= fqv[126];
	ctx->vsp=local+13;
	w=(*ftab[0])(ctx,2,local+11,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF323;
	local[4] = makeint(0);
	local[3] = T;
	local[11]= local[3];
	goto IF324;
IF323:
	local[11]= makeint(27);
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= local[5];
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= local[2];
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= w;
IF324:
	goto IF322;
IF321:
	local[11]= local[10];
	if (fqv[127]!=local[11]) goto IF325;
	local[6] = local[2];
	local[11]= local[2];
	local[12]= makeint(74);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF327;
	local[4] = makeint(0);
	local[3] = NIL;
	local[11]= local[3];
	goto IF328;
IF327:
	local[11]= makeint(27);
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= local[5];
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= local[2];
	w = local[7];
	ctx->vsp=local+12;
	w=FLET303(ctx,1,local+11,w);
	local[11]= w;
IF328:
	goto IF326;
IF325:
	local[11]= NIL;
IF326:
IF322:
IF316:
IF310:
	w = local[11];
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL305;
WHX306:
	local[10]= NIL;
BLK307:
	w = NIL;
	local[8]= local[0];
	local[9]= makeint(0);
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[0]= w;
BLK302:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET303(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= env->c.clo.env2[1];
	w = argv[0];
	{ register integer_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.str.chars[i]=intval(w);}
	env->c.clo.env2[1] = (pointer)((integer_t)(env->c.clo.env2[1])+4);
	w = env->c.clo.env2[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*romanji*/
static pointer F74(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[56]); /*make-string-input-stream*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= fqv[128];
	local[7]= fqv[129];
	local[8]= NIL;
	local[9]= makeint(0);
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
TAG331:
	local[11]= local[9];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto IF333;
	local[11]= (pointer)get_sym_func(fqv[47]);
	local[12]= loadglobal(fqv[9]);
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)NREVERSE(ctx,1,local+13); /*nreverse*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,3,local+11); /*apply*/
	ctx->vsp=local+11;
	local[0]=w;
	goto BLK330;
	goto IF334;
IF333:
	local[11]= NIL;
IF334:
	local[11]= argv[0];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[2] = w;
	local[11]= local[2];
	local[12]= makeint(128);
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF335;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= loadglobal(fqv[9]);
	ctx->vsp=local+13;
	w=(pointer)COERCE(ctx,2,local+11); /*coerce*/
	local[11]= w;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[9] = (pointer)((integer_t)(local[9])+4);
	ctx->vsp=local+11;
	goto TAG331;
	goto IF336;
IF335:
	local[11]= NIL;
IF336:
	local[11]= (pointer)((integer_t)(local[9])+4);
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF337;
	local[11]= argv[0];
	local[12]= (pointer)((integer_t)(local[9])+4);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	goto IF338;
IF337:
	local[11]= makeint(32);
IF338:
	local[3] = local[11];
	local[11]= local[9];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF339;
	local[11]= argv[0];
	local[12]= local[9];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	goto IF340;
IF339:
	local[11]= makeint(32);
IF340:
	local[4] = local[11];
	local[11]= local[9];
	local[12]= makeint(3);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF341;
	local[11]= argv[0];
	local[12]= local[9];
	local[13]= makeint(3);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	goto IF342;
IF341:
	local[11]= makeint(32);
IF342:
	local[5] = local[11];
	local[11]= local[6];
	local[12]= makeint(0);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[6];
	local[12]= makeint(1);
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[7];
	local[12]= makeint(0);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[7];
	local[12]= makeint(1);
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[7];
	local[12]= makeint(2);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[7];
	local[12]= makeint(3);
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[6];
	local[12]= loadglobal(fqv[130]);
	local[13]= fqv[131];
	local[14]= (pointer)get_sym_func(fqv[132]);
	ctx->vsp=local+15;
	w=(*ftab[0])(ctx,4,local+11,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF343;
	local[11]= local[7];
	local[12]= loadglobal(fqv[133]);
	local[13]= fqv[131];
	local[14]= (pointer)get_sym_func(fqv[132]);
	local[15]= fqv[134];
	local[16]= (pointer)get_sym_func(fqv[135]);
	ctx->vsp=local+17;
	w=(*ftab[0])(ctx,6,local+11,&ftab[0],fqv[1]); /*member*/
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[9];
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[9] = w;
	ctx->vsp=local+11;
	goto TAG331;
	goto IF344;
IF343:
	local[11]= NIL;
IF344:
	local[11]= local[6];
	local[12]= loadglobal(fqv[136]);
	local[13]= fqv[131];
	local[14]= (pointer)get_sym_func(fqv[132]);
	ctx->vsp=local+15;
	w=(*ftab[0])(ctx,4,local+11,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF345;
	local[11]= local[7];
	local[12]= loadglobal(fqv[137]);
	local[13]= fqv[131];
	local[14]= (pointer)get_sym_func(fqv[132]);
	local[15]= fqv[134];
	local[16]= (pointer)get_sym_func(fqv[135]);
	ctx->vsp=local+17;
	w=(*ftab[0])(ctx,6,local+11,&ftab[0],fqv[1]); /*member*/
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[9];
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[9] = w;
	ctx->vsp=local+11;
	goto TAG331;
	goto IF346;
IF345:
	local[11]= NIL;
IF346:
	local[11]= local[6];
	local[12]= makeint(0);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[6];
	local[12]= makeint(1);
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[6];
	local[12]= loadglobal(fqv[138]);
	local[13]= fqv[131];
	local[14]= (pointer)get_sym_func(fqv[132]);
	ctx->vsp=local+15;
	w=(*ftab[0])(ctx,4,local+11,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF347;
	local[11]= local[6];
	local[12]= makeint(0);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[6];
	local[12]= makeint(1);
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,3,local+11); /*aset*/
	local[11]= local[6];
	local[12]= loadglobal(fqv[139]);
	local[13]= fqv[134];
	local[14]= (pointer)get_sym_func(fqv[135]);
	local[15]= fqv[131];
	local[16]= (pointer)get_sym_func(fqv[132]);
	ctx->vsp=local+17;
	w=(*ftab[0])(ctx,6,local+11,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	local[11]= local[8];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= loadglobal(fqv[9]);
	ctx->vsp=local+13;
	w=(pointer)COERCE(ctx,2,local+11); /*coerce*/
	local[11]= w;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[9];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[9] = w;
	ctx->vsp=local+11;
	goto TAG331;
	goto IF348;
IF347:
	local[11]= NIL;
IF348:
	local[11]= local[6];
	local[12]= loadglobal(fqv[139]);
	local[13]= fqv[134];
	local[14]= (pointer)get_sym_func(fqv[135]);
	local[15]= fqv[131];
	local[16]= (pointer)get_sym_func(fqv[132]);
	ctx->vsp=local+17;
	w=(*ftab[0])(ctx,6,local+11,&ftab[0],fqv[1]); /*member*/
	local[8] = w;
	if (local[8]==NIL) goto IF349;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[0];
	goto IF350;
IF349:
	local[11]= NIL;
IF350:
TAG332:
	local[11]= local[9];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[9] = w;
	ctx->vsp=local+11;
	goto TAG331;
	w = NIL;
	local[0]= w;
BLK330:
	w = local[0];
	local[0]= w;
BLK329:
	ctx->vsp=local; return(local[0]);}

/*hira2kata*/
static pointer F75(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,1,local+4,&ftab[9],fqv[122]); /*make-string*/
	local[4]= w;
WHL352:
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX353;
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[1] = w;
	local[5]= local[1];
	local[6]= makeint(128);
	ctx->vsp=local+7;
	w=(pointer)LOGTEST(ctx,2,local+5); /*logtest*/
	if (w==NIL) goto CON356;
	local[5]= local[1];
	local[6]= makeint(164);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF357;
	local[1] = makeint(165);
	local[5]= local[1];
	goto IF358;
IF357:
	local[5]= NIL;
IF358:
	local[5]= local[4];
	local[6]= local[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= local[4];
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= w;
	goto CON355;
CON356:
	local[5]= local[4];
	local[6]= local[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= w;
	goto CON355;
CON359:
	local[5]= NIL;
CON355:
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL352;
WHX353:
	local[5]= NIL;
BLK354:
	w = local[4];
	local[0]= w;
BLK351:
	ctx->vsp=local; return(local[0]);}

/*kata2hira*/
static pointer F76(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,1,local+4,&ftab[9],fqv[122]); /*make-string*/
	local[4]= w;
WHL361:
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX362;
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[1] = w;
	local[5]= local[1];
	local[6]= makeint(128);
	ctx->vsp=local+7;
	w=(pointer)LOGTEST(ctx,2,local+5); /*logtest*/
	if (w==NIL) goto CON365;
	local[5]= local[1];
	local[6]= makeint(165);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF366;
	local[1] = makeint(164);
	local[5]= local[1];
	goto IF367;
IF366:
	local[5]= NIL;
IF367:
	local[5]= local[4];
	local[6]= local[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= local[4];
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= w;
	goto CON364;
CON365:
	local[5]= local[4];
	local[6]= local[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= w;
	goto CON364;
CON368:
	local[5]= NIL;
CON364:
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL361;
WHX362:
	local[5]= NIL;
BLK363:
	w = local[4];
	local[0]= w;
BLK360:
	ctx->vsp=local; return(local[0]);}

/*string-match-at*/
static pointer F77(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= local[0];
WHL371:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX372;
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (w==local[3]) goto IF374;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK369;
	goto IF375;
IF374:
	local[3]= NIL;
IF375:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL371;
WHX372:
	local[3]= NIL;
BLK373:
	w = NIL;
	w = T;
	local[0]= w;
BLK369:
	ctx->vsp=local; return(local[0]);}

/*string-match*/
static pointer F78(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT378;}
	local[0]= makeint(0);
ENT378:
ENT377:
	if (n>3) maerror();
	local[1]= makeint(0);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(-1);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,4,local+2); /*-*/
	local[2]= w;
WHL380:
	local[3]= local[1];
	w = local[2];
	if ((integer_t)local[3] >= (integer_t)w) goto WHX381;
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F77(ctx,3,local+3); /*string-match-at*/
	if (w==NIL) goto IF383;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK376;
	goto IF384;
IF383:
	local[3]= NIL;
IF384:
	local[1] = (pointer)((integer_t)(local[1])+4);
	goto WHL380;
WHX381:
	local[3]= NIL;
BLK382:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK376:
	ctx->vsp=local; return(local[0]);}

/*euc-string-trim*/
static pointer F79(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,1,local+5,&ftab[9],fqv[122]); /*make-string*/
	local[5]= w;
WHL386:
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX387;
	local[6]= argv[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(128);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF389;
	local[6]= local[0];
	local[7]= argv[1];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[116]); /*/=*/
	if (w!=NIL) goto OR393;
	local[6]= local[1];
	local[7]= argv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[2])+4));
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[116]); /*/=*/
	if (w!=NIL) goto OR393;
	goto IF391;
OR393:
	local[6]= local[5];
	local[7]= local[4];
	local[8]= argv[1];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[8]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[6]= local[5];
	local[7]= (pointer)((integer_t)(local[4])+4);
	local[8]= argv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[2])+4));
	  w=makeint(local[8]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[6]= local[4];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[4] = w;
	local[6]= local[2];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[2] = w;
	local[6]= local[2];
	goto IF392;
IF391:
	local[6]= makeint(2);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[2] = w;
	local[6]= local[2];
IF392:
	goto IF390;
IF389:
	local[6]= local[5];
	local[7]= local[4];
	local[8]= argv[1];
	{ register integer_t i=intval(local[2]);
	  w=makeint(local[8]->c.str.chars[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[4] = (pointer)((integer_t)(local[4])+4);
	local[2] = (pointer)((integer_t)(local[2])+4);
	local[6]= local[2];
IF390:
	goto WHL386;
WHX387:
	local[6]= NIL;
BLK388:
	local[6]= local[5];
	local[7]= makeint(0);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[0]= w;
BLK385:
	ctx->vsp=local; return(local[0]);}

/*euc-digit*/
static pointer F80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	{ register integer_t i=intval(argv[1]);
	  w=makeint(local[0]->c.str.chars[i]);}
	local[0]= w;
	local[1]= makeint(48);
	local[2]= local[0];
	local[3]= makeint(57);
	ctx->vsp=local+4;
	w=(pointer)LSEQP(ctx,3,local+1); /*<=*/
	if (w==NIL) goto CON396;
	local[1]= local[0];
	local[2]= makeint(48);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	goto CON395;
CON396:
	local[1]= local[0];
	if (makeint(163)!=local[1]) goto CON397;
	local[1]= makeint(176);
	local[2]= argv[0];
	{ register integer_t i=intval((pointer)((integer_t)(argv[1])+4));
	  w=makeint(local[2]->c.str.chars[i]);}
	local[2]= w;
	local[3]= makeint(185);
	ctx->vsp=local+4;
	w=(pointer)LSEQP(ctx,3,local+1); /*<=*/
	if (w==NIL) goto CON397;
	local[1]= argv[0];
	{ register integer_t i=intval((pointer)((integer_t)(argv[1])+4));
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= makeint(176);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	goto CON395;
CON397:
	local[1]= NIL;
CON395:
	w = local[1];
	local[0]= w;
BLK394:
	ctx->vsp=local; return(local[0]);}

/*euc-number*/
static pointer F81(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(1);
WHL399:
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX400;
	local[5]= argv[0];
	{ register integer_t i=intval(local[3]);
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	if (makeint(32)!=local[5]) goto CON403;
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[5]= local[3];
	goto CON402;
CON403:
	local[5]= argv[0];
	{ register integer_t i=intval(local[3]);
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	if (makeint(160)!=local[5]) goto CON404;
	local[5]= argv[0];
	{ register integer_t i=intval((pointer)((integer_t)(local[3])+4));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	if (makeint(160)!=local[5]) goto CON404;
	local[5]= local[3];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[3] = w;
	local[5]= local[3];
	goto CON402;
CON404:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F80(ctx,2,local+5); /*euc-digit*/
	if (w==NIL) goto CON405;
	w = NIL;
	ctx->vsp=local+5;
	local[5]=w;
	goto BLK401;
	goto CON402;
CON405:
	w = NIL;
	ctx->vsp=local+5;
	local[5]=w;
	goto BLK401;
	goto CON402;
CON406:
	local[5]= NIL;
CON402:
	goto WHL399;
WHX400:
	local[5]= NIL;
BLK401:
	local[5]= argv[0];
	{ register integer_t i=intval(local[3]);
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	if (makeint(45)!=local[5]) goto CON408;
	local[4] = makeint(-1);
	local[3] = (pointer)((integer_t)(local[3])+4);
	local[5]= local[3];
	goto CON407;
CON408:
	local[5]= argv[0];
	local[6]= local[3];
	local[7]= local[3];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	local[6]= fqv[140];
	ctx->vsp=local+7;
	w=(pointer)EQUAL(ctx,2,local+5); /*equal*/
	if (w==NIL) goto CON409;
	local[4] = makeint(-1);
	local[5]= local[3];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[3] = w;
	local[5]= local[3];
	goto CON407;
CON409:
	local[5]= argv[0];
	local[6]= local[3];
	local[7]= local[3];
	local[8]= makeint(8);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	local[6]= fqv[141];
	ctx->vsp=local+7;
	w=(pointer)EQUAL(ctx,2,local+5); /*equal*/
	if (w==NIL) goto CON410;
	local[4] = makeint(-1);
	local[5]= local[3];
	local[6]= makeint(8);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[3] = w;
	local[5]= local[3];
	goto CON407;
CON410:
	local[5]= NIL;
CON407:
WHL411:
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX412;
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F80(ctx,2,local+5); /*euc-digit*/
	local[2] = w;
	if (local[2]==NIL) goto IF414;
	local[5]= local[1];
	local[6]= makeint(10);
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[1] = w;
	local[5]= local[1];
	goto IF415;
IF414:
	local[5]= local[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK398;
IF415:
	local[5]= local[3];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[3] = w;
	goto WHL411;
WHX412:
	local[5]= NIL;
BLK413:
	local[5]= local[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[0]= w;
BLK398:
	ctx->vsp=local; return(local[0]);}

/*percent-code-to-euc*/
static pointer F82(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,0,local+5,&ftab[6],fqv[115]); /*make-string-output-stream*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[50];
	local[8]= fqv[142];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,2,local+7,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF417;
	local[7]= fqv[50];
	local[8]= fqv[143];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,2,local+7,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	goto IF418;
IF417:
	local[7]= NIL;
IF418:
	local[8]= fqv[53];
	local[9]= fqv[144];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,2,local+8,&ftab[0],fqv[1]); /*member*/
	if (w==NIL) goto IF419;
	local[8]= fqv[53];
	local[9]= fqv[145];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,2,local+8,&ftab[0],fqv[1]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	goto IF420;
IF419:
	local[8]= NIL;
IF420:
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,3,local+6,&ftab[5],fqv[56]); /*make-string-input-stream*/
	local[6]= w;
WHL421:
	if (T==NIL) goto WHX422;
	local[7]= local[6];
	local[8]= NIL;
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)READCH(ctx,3,local+7); /*read-char*/
	local[2] = w;
	local[7]= local[2];
	local[8]= makeint(37);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w!=NIL) goto IF424;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[117]); /*get-output-stream-string*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK416;
	goto IF425;
IF424:
	local[7]= NIL;
IF425:
	local[7]= makeint(16);
	w = local[7];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[146],w);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)READ(ctx,1,local+11); /*read*/
	local[11]= w;
	ctx->vsp=local+12;
	unbindx(ctx,1);
	w = local[11];
	local[2] = w;
	local[7]= local[6];
	local[8]= NIL;
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)READCH(ctx,3,local+7); /*read-char*/
	local[3] = w;
	local[7]= local[3];
	local[8]= makeint(37);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w!=NIL) goto IF426;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[117]); /*get-output-stream-string*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK416;
	goto IF427;
IF426:
	local[7]= NIL;
IF427:
	local[7]= makeint(16);
	w = local[7];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[146],w);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)READ(ctx,1,local+11); /*read*/
	local[11]= w;
	ctx->vsp=local+12;
	unbindx(ctx,1);
	w = local[11];
	local[3] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= local[3];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	goto WHL421;
WHX422:
	local[7]= NIL;
BLK423:
	w = local[7];
	local[0]= w;
BLK416:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___kana_euc(ctx,n,argv,env)
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
	local[0]= fqv[147];
	local[1]= fqv[148];
	local[2]= fqv[149];
	local[3]= fqv[150];
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,4,local+0,&ftab[10],fqv[151]); /*require*/
	local[0]= fqv[152];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[60];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF428;
	local[0]= fqv[60];
	local[1]= fqv[153];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF430;
	local[0]= fqv[60];
	local[1]= fqv[154];
	local[2]= fqv[155];
	local[3]= fqv[5];
	local[4]= fqv[156];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[8]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF431;
IF430:
	local[0]= NIL;
IF431:
	local[0]= fqv[60];
	goto IF429;
IF428:
	local[0]= NIL;
IF429:
	local[0]= fqv[61];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF432;
	local[0]= fqv[61];
	local[1]= fqv[153];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF434;
	local[0]= fqv[61];
	local[1]= fqv[154];
	local[2]= fqv[157];
	local[3]= fqv[5];
	local[4]= fqv[158];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[8]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF435;
IF434:
	local[0]= NIL;
IF435:
	local[0]= fqv[61];
	goto IF433;
IF432:
	local[0]= NIL;
IF433:
	local[0]= fqv[62];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF436;
	local[0]= fqv[62];
	local[1]= fqv[153];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF438;
	local[0]= fqv[62];
	local[1]= fqv[154];
	local[2]= fqv[159];
	local[3]= fqv[5];
	local[4]= fqv[160];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[8]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF439;
IF438:
	local[0]= NIL;
IF439:
	local[0]= fqv[62];
	goto IF437;
IF436:
	local[0]= NIL;
IF437:
	local[0]= fqv[63];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF440;
	local[0]= fqv[63];
	local[1]= fqv[153];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[63];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF442;
	local[0]= fqv[63];
	local[1]= fqv[154];
	local[2]= fqv[161];
	local[3]= fqv[5];
	local[4]= fqv[162];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[8]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF443;
IF442:
	local[0]= NIL;
IF443:
	local[0]= fqv[63];
	goto IF441;
IF440:
	local[0]= NIL;
IF441:
	local[0]= fqv[64];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF444;
	local[0]= fqv[64];
	local[1]= fqv[153];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF446;
	local[0]= fqv[64];
	local[1]= fqv[154];
	local[2]= fqv[163];
	local[3]= fqv[5];
	local[4]= fqv[164];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[8]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF447;
IF446:
	local[0]= NIL;
IF447:
	local[0]= fqv[64];
	goto IF445;
IF444:
	local[0]= NIL;
IF445:
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F58,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F59,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F60,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F61,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F62,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F63,fqv[176]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F64,fqv[178]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F65,fqv[180]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F66,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F67,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F68,fqv[186]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F69,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F70,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F71,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F72,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F73,fqv[196]);
	local[0]= fqv[197];
	local[1]= fqv[154];
	local[2]= fqv[198];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[136];
	local[1]= fqv[154];
	local[2]= fqv[199];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[130];
	local[1]= fqv[154];
	local[2]= fqv[200];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[138];
	local[1]= fqv[154];
	local[2]= fqv[201];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[139];
	local[1]= fqv[154];
	local[2]= fqv[202];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[133];
	local[1]= fqv[154];
	local[2]= fqv[203];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[137];
	local[1]= fqv[154];
	local[2]= fqv[204];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F74,fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F75,fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F76,fqv[210]);
	local[0]= makeint(2);
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[122]); /*make-string*/
	local[0]= w;
	storeglobal(fqv[211],w);
	local[0]= loadglobal(fqv[211]);
	local[1]= makeint(0);
	w = makeint(161);
	{ register integer_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.str.chars[i]=intval(w);}
	local[0]= loadglobal(fqv[211]);
	local[1]= makeint(1);
	w = makeint(161);
	{ register integer_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.str.chars[i]=intval(w);}
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F77,fqv[213]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F78,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F79,fqv[217]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F80,fqv[219]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[220],module,F81,fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F82,fqv[223]);
	local[0]= fqv[224];
	local[1]= fqv[225];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[226]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<12; i++) ftab[i]=fcallx;
}
