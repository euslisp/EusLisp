/* toplevel.c :  entry=toplevel */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "toplevel.h"
#pragma init (register_toplevel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___toplevel();
extern pointer build_quote_vector();
static register_toplevel()
  { add_module_initializer("___toplevel", ___toplevel);}

static pointer F68571();
static pointer F68573();
static pointer F68576();
static pointer F68578();
static pointer F68581();
static pointer F68583();
static pointer F68585();
static pointer F68587();
static pointer F68589();
static pointer F68591();
static pointer F68593();
static pointer F68595();
static pointer F68597();
static pointer F68599();
static pointer F68601();
static pointer F68603();

/*count-up-timer*/
static pointer F68571(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= (pointer)((integer_t)(loadglobal(fqv[0]))+4);
	storeglobal(fqv[0],local[0]);
	w = local[0];
	local[0]= w;
BLK68675:
	ctx->vsp=local; return(local[0]);}

/*skip-blank*/
static pointer F68573(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT68698;}
	ctx->vsp=local+0;
	w=(pointer)GENSYM(ctx,0,local+0); /*gensym*/
	local[0]= w;
ENT68698:
ENT68697:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	local[1]= w;
	local[2]= local[1];
	if (local[0]!=local[2]) goto IF68728;
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK68695;
	goto IF68729;
IF68728:
	local[2]= NIL;
IF68729:
WHL68740:
	local[2]= local[1];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[2]); /*position*/
	if (w==NIL) goto WHX68741;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READCH(ctx,1,local+2); /*read-char*/
	local[1] = w;
	goto WHL68740;
WHX68741:
	local[2]= NIL;
BLK68742:
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)UNREADCH(ctx,2,local+2); /*unread-char*/
	w = local[1];
	local[0]= w;
BLK68695:
	ctx->vsp=local; return(local[0]);}

/*read-list-from-line*/
static pointer F68576(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT68775;}
	local[0]= loadglobal(fqv[3]);
ENT68775:
	if (n>=2) { local[1]=(argv[1]); goto ENT68774;}
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
ENT68774:
ENT68773:
	if (n>2) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F68573(ctx,2,local+6); /*skip-blank*/
	local[2] = w;
	local[6]= NIL;
	storeglobal(fqv[4],local[6]);
	local[6]= local[2];
	if (local[1]!=local[6]) goto CON68823;
	local[6]= local[1];
	goto CON68821;
CON68823:
	local[6]= local[2];
	if (makeint(40)!=local[6]) goto CON68830;
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[4] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[2] = w;
	local[6]= local[2];
	local[7]= makeint(10);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto IF68856;
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)UNREADCH(ctx,2,local+6); /*unread-char*/
	local[6]= w;
	goto IF68857;
IF68856:
	local[6]= NIL;
IF68857:
	local[6]= local[4];
	goto CON68821;
CON68830:
	local[6]= local[2];
	if (makeint(44)!=local[6]) goto CON68872;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READ(ctx,1,local+6); /*read*/
	local[4] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= local[4];
	goto CON68821;
CON68872:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[6]= w;
	storeglobal(fqv[4],w);
	local[6]= loadglobal(fqv[4]);
	if (local[1]!=local[6]) goto IF68908;
	w = local[1];
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK68771;
	goto IF68909;
IF68908:
	local[6]= NIL;
IF68909:
	local[6]= loadglobal(fqv[4]);
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[5]); /*make-string-input-stream*/
	local[6]= w;
	goto CON68821;
CON68895:
	local[6]= NIL;
CON68821:
	w = local[6];
	local[0]= w;
BLK68771:
	ctx->vsp=local; return(local[0]);}

/*sigint-handler*/
static pointer F68578(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(1);
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[7]); /*warning-message*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto IF68943;
	local[0]= makeint(0);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[8]); /*unix:ualarm*/
	local[0]= w;
	goto IF68944;
IF68943:
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(pointer)ALARM(ctx,1,local+0); /*unix:alarm*/
	local[0]= w;
IF68944:
	local[0]= (pointer)((integer_t)(loadglobal(fqv[9]))+4);
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[9],w);
	local[3]= fqv[10];
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[11],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT68975;}
	local[12]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+13;
	w=(pointer)F68597(ctx,1,local+12); /*reploop*/
CAT68975:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,2);
	w = local[6];
	local[0]= w;
BLK68927:
	ctx->vsp=local; return(local[0]);}

/*eussig*/
static pointer F68581(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST68993:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= loadglobal(fqv[13]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	if (local[2]==NIL) goto CON69015;
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[3]= w;
	goto CON69013;
CON69015:
	local[3]= fqv[8];
	ctx->vsp=local+4;
	w=(pointer)FBOUNDP(ctx,1,local+3); /*fboundp*/
	if (w==NIL) goto IF69029;
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[8]); /*unix:ualarm*/
	local[3]= w;
	goto IF69030;
IF69029:
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ALARM(ctx,2,local+3); /*unix:alarm*/
	local[3]= w;
IF69030:
	local[3]= makeint(1);
	local[4]= fqv[14];
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[7]); /*warning-message*/
	local[3]= (pointer)((integer_t)(loadglobal(fqv[9]))+4);
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[9],w);
	local[6]= fqv[15];
	w = local[6];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[11],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT69064;}
	local[15]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+16;
	w=(pointer)F68597(ctx,1,local+15); /*reploop*/
CAT69064:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,2);
	w = local[9];
	local[3]= w;
	goto CON69013;
CON69025:
	local[3]= NIL;
CON69013:
	w = local[3];
	local[0]= w;
BLK68991:
	ctx->vsp=local; return(local[0]);}

/*evaluate-stream*/
static pointer F68583(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,3,local+1); /*read*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[1];
	local[5]= ((local[0])==(local[5])?T:NIL);
	if (local[5]!=NIL) goto CON69111;
CON69113:
	w = local[1];
	if (!issymbol(w)) goto CON69121;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)FBOUNDP(ctx,1,local+5); /*fboundp*/
	if (w==NIL) goto CON69129;
	local[2] = NIL;
WHL69143:
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,3,local+5); /*read*/
	local[3] = w;
	local[5]= local[3];
	if (local[0]==local[5]) goto WHX69144;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL69143;
WHX69144:
	local[5]= NIL;
BLK69145:
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	storeglobal(fqv[16],local[5]);
	local[5]= loadglobal(fqv[16]);
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON69127;
CON69129:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)BOUNDP(ctx,1,local+5); /*boundp*/
	if (w==NIL) goto CON69191;
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,3,local+5); /*read*/
	local[5]= w;
	if (local[0]!=local[5]) goto CON69191;
	local[5]= local[1];
	storeglobal(fqv[16],local[5]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON69127;
CON69191:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	if (w==NIL) goto CON69220;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	if (w==NIL) goto IF69232;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	storeglobal(fqv[18],w);
	goto IF69233;
IF69232:
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,1,local+5); /*error*/
	local[5]= w;
IF69233:
	goto CON69127;
CON69220:
	if (loadglobal(fqv[20])==NIL) goto CON69253;
	local[5]= fqv[21];
	local[6]= *(ovafptr(argv[0],fqv[22]));
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	storeglobal(fqv[16],w);
	local[5]= *(ovafptr(argv[0],fqv[22]));
	ctx->vsp=local+6;
	w=(pointer)SYSTEM(ctx,1,local+5); /*unix:system*/
	local[4] = w;
	local[5]= local[4];
	goto CON69127;
CON69253:
	local[5]= fqv[23];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,1,local+5,&ftab[5],fqv[24]); /*warn*/
	local[5]= w;
	goto CON69127;
CON69279:
	local[5]= NIL;
CON69127:
	goto CON69111;
CON69121:
	local[5]= local[1];
	storeglobal(fqv[16],local[5]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON69111;
CON69285:
	local[5]= NIL;
CON69111:
	w = local[4];
	local[0]= w;
BLK69078:
	ctx->vsp=local; return(local[0]);}

/*toplevel-prompt*/
static pointer F68585(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (loadglobal(fqv[25])==NIL) goto IF69319;
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= (pointer)((integer_t)(loadglobal(fqv[27]))+4);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF69320;
IF69319:
	local[0]= NIL;
IF69320:
	local[0]= loadglobal(fqv[9]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF69335;
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= loadglobal(fqv[11]);
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF69336;
IF69335:
	local[0]= NIL;
IF69336:
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w!=NIL) goto IF69348;
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= loadglobal(fqv[18]);
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[31]); /*package-name*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF69349;
IF69348:
	local[0]= NIL;
IF69349:
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK69309:
	ctx->vsp=local; return(local[0]);}

/*rep1*/
static pointer F68587(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT69376;}
	local[0]= T;
ENT69376:
ENT69375:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F68576(ctx,2,local+1); /*read-list-from-line*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[1];
	if (argv[1]!=local[3]) goto IF69410;
	w = argv[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK69373;
	goto IF69411;
IF69410:
	local[3]= NIL;
IF69411:
	if (local[1]==NIL) goto IF69423;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto OR69429;
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint(0);
	if ((integer_t)local[3] > (integer_t)w) goto OR69429;
	goto IF69423;
OR69429:
	if (loadglobal(fqv[25])==NIL) goto IF69450;
	w = local[1];
	if (!iscons(w)) goto CON69462;
	local[3]= NIL;
	local[4]= fqv[35];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto CON69460;
CON69462:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto CON69470;
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	goto CON69460;
CON69470:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[17]); /*string*/
	local[3]= w;
	goto CON69460;
CON69482:
	local[3]= NIL;
CON69460:
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[36]); /*add-history*/
	local[3]= w;
	goto IF69451;
IF69450:
	local[3]= NIL;
IF69451:
	if (loadglobal(fqv[37])==NIL) goto IF69492;
	local[3]= loadglobal(fqv[37]);
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,1,local+3); /*funcall*/
	local[3]= w;
	goto IF69493;
IF69492:
	local[3]= NIL;
IF69493:
	goto IF69424;
IF69423:
	local[3]= NIL;
IF69424:
	if (local[1]!=NIL) goto CON69505;
	local[3]= NIL;
	goto CON69503;
CON69505:
	w = local[1];
	if (!issymbol(w)) goto CON69510;
	storeglobal(fqv[16],local[1]);
	local[3]= loadglobal(fqv[9]);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto CON69523;
	local[3]= local[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[38]); /*eval-dynamic*/
	local[3]= w;
	goto CON69521;
CON69523:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)BOUNDP(ctx,1,local+3); /*boundp*/
	if (w==NIL) goto CON69533;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	goto CON69521;
CON69533:
	local[3]= fqv[39];
	goto CON69521;
CON69543:
	local[3]= NIL;
CON69521:
	local[2] = local[3];
	if (local[0]==NIL) goto IF69552;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto IF69553;
IF69552:
	local[3]= NIL;
IF69553:
	goto CON69503;
CON69510:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto OR69562;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LISTP(ctx,1,local+3); /*listp*/
	if (w!=NIL) goto OR69562;
	goto CON69561;
OR69562:
	local[3]= local[1];
	storeglobal(fqv[16],local[3]);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[2] = w;
	if (local[0]==NIL) goto IF69591;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto IF69592;
IF69591:
	local[3]= NIL;
IF69592:
	goto CON69503;
CON69561:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto CON69600;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F68583(ctx,1,local+3); /*evaluate-stream*/
	local[2] = w;
	if (local[0]==NIL) goto IF69617;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto IF69618;
IF69617:
	local[3]= NIL;
IF69618:
	goto CON69503;
CON69600:
	local[3]= fqv[40];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON69503;
CON69626:
	local[3]= NIL;
CON69503:
	storeglobal(fqv[42],loadglobal(fqv[41]));
	storeglobal(fqv[41],loadglobal(fqv[43]));
	local[3]= loadglobal(fqv[16]);
	storeglobal(fqv[43],local[3]);
	storeglobal(fqv[45],loadglobal(fqv[44]));
	storeglobal(fqv[44],loadglobal(fqv[46]));
	local[3]= local[2];
	storeglobal(fqv[46],local[3]);
	w = local[3];
	local[0]= w;
BLK69373:
	ctx->vsp=local; return(local[0]);}

/*prompt*/
static pointer F68589(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = loadglobal(fqv[47]);
	if (!isstring(w)) goto CON69678;
	local[0]= loadglobal(fqv[47]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= w;
	goto CON69676;
CON69678:
	local[0]= loadglobal(fqv[47]);
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto CON69688;
	local[0]= loadglobal(fqv[47]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	goto CON69676;
CON69688:
	local[0]= argv[0];
	local[1]= fqv[49];
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON69676;
CON69700:
	local[0]= NIL;
CON69676:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK69666:
	ctx->vsp=local; return(local[0]);}

/*reploop-non-select*/
static pointer F68591(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT69718;}
	local[0]= loadglobal(fqv[50]);
ENT69718:
	if (n>=2) { local[1]=(argv[1]); goto ENT69717;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT69717:
ENT69716:
	if (n>2) maerror();
	local[2]= fqv[51];
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[52],w);
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[9]);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF69760;
	ctx->vsp=local+9;
	w=(pointer)LISTBINDINGS(ctx,0,local+9); /*system:list-all-bindings*/
	local[7] = w;
	local[9]= local[7];
	goto IF69761;
IF69760:
	local[9]= NIL;
IF69761:
WHL69774:
	if (T==NIL) goto WHX69775;
	{jmp_buf jb;
	w = fqv[53];
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT69781;}
	if (local[1]==NIL) goto IF69788;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)F68589(ctx,1,local+15); /*prompt*/
	local[15]= w;
	goto IF69789;
IF69788:
	local[15]= NIL;
IF69789:
	local[15]= local[0];
	local[16]= local[5];
	local[17]= local[7];
	local[18]= local[1];
	ctx->vsp=local+19;
	w=(pointer)F68587(ctx,4,local+15); /*rep1*/
	local[15]= w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)EQ(ctx,2,local+15); /*eql*/
	if (w==NIL) goto IF69798;
	w = NIL;
	ctx->vsp=local+15;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK69714;
	goto IF69799;
IF69798:
	local[15]= NIL;
IF69799:
	w = local[15];
CAT69781:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL69774;
WHX69775:
	local[9]= NIL;
BLK69776:
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK69714:
	ctx->vsp=local; return(local[0]);}

/*repsel*/
static pointer F68593(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[3];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F68587(ctx,4,local+0); /*rep1*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF69835;
	local[0]= fqv[54];
	w = NIL;
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF69836;
IF69835:
	local[0]= NIL;
IF69836:
	if (argv[2]==NIL) goto IF69855;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F68589(ctx,1,local+0); /*prompt*/
	local[0]= w;
	goto IF69856;
IF69855:
	local[0]= NIL;
IF69856:
	w = local[0];
	local[0]= w;
BLK69819:
	ctx->vsp=local; return(local[0]);}

/*reploop-select*/
static pointer F68595(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT69870;}
	local[0]= loadglobal(fqv[50]);
ENT69870:
	if (n>=2) { local[1]=(argv[1]); goto ENT69869;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT69869:
ENT69868:
	if (n>2) maerror();
	local[2]= fqv[51];
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[52],w);
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (local[1]==NIL) goto IF69911;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F68589(ctx,1,local+9); /*prompt*/
	local[9]= w;
	goto IF69912;
IF69911:
	local[9]= NIL;
IF69912:
	local[9]= loadglobal(fqv[9]);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF69921;
	ctx->vsp=local+9;
	w=(pointer)LISTBINDINGS(ctx,0,local+9); /*system:list-all-bindings*/
	local[7] = w;
	local[9]= local[7];
	goto IF69922;
IF69921:
	local[9]= NIL;
IF69922:
	local[9]= loadglobal(fqv[55]);
	local[10]= fqv[56];
	local[11]= local[0];
	local[12]= fqv[57];
	local[13]= local[0];
	local[14]= local[5];
	local[15]= local[1];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,8,local+9); /*send*/
	{jmp_buf jb;
	w = fqv[54];
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT69949;}
WHL69956:
	if (T==NIL) goto WHX69957;
	local[15]= loadglobal(fqv[55]);
	local[16]= fqv[58];
	local[17]= loadglobal(fqv[59]);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	if (w!=NIL) goto IF69964;
	local[15]= loadglobal(fqv[60]);
	ctx->vsp=local+16;
	w=(*ftab[9])(ctx,1,local+15,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto IF69979;
	local[15]= loadglobal(fqv[60]);
	ctx->vsp=local+16;
	w=(pointer)FUNCALL(ctx,1,local+15); /*funcall*/
	local[15]= w;
	goto IF69980;
IF69979:
	local[15]= NIL;
	local[16]= loadglobal(fqv[60]);
WHL70008:
	if (local[16]==NIL) goto WHX70009;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16] = (w)->c.cons.cdr;
	w = local[17];
	local[15] = w;
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(*ftab[9])(ctx,1,local+17,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto IF70057;
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)FUNCALL(ctx,1,local+17); /*funcall*/
	local[17]= w;
	goto IF70058;
IF70057:
	local[17]= NIL;
IF70058:
	goto WHL70008;
WHX70009:
	local[17]= NIL;
BLK70010:
	w = NIL;
	local[15]= w;
IF69980:
	goto IF69965;
IF69964:
	local[15]= NIL;
IF69965:
	goto WHL69956;
WHX69957:
	local[15]= NIL;
BLK69958:
	w = local[15];
CAT69949:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK69866:
	ctx->vsp=local; return(local[0]);}

/*reploop*/
static pointer F68597(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT70079;}
	local[0]= loadglobal(fqv[50]);
ENT70079:
	if (n>=3) { local[1]=(argv[2]); goto ENT70078;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT70078:
ENT70077:
	if (n>3) maerror();
	local[2]= argv[0];
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[47],w);
	if (loadglobal(fqv[61])==NIL) goto IF70115;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F68595(ctx,2,local+6); /*reploop-select*/
	local[6]= w;
	goto IF70116;
IF70115:
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F68591(ctx,2,local+6); /*reploop-non-select*/
	local[6]= w;
IF70116:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK70075:
	ctx->vsp=local; return(local[0]);}

/*euserror*/
static pointer F68599(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT70136;}
	local[0]= NIL;
ENT70136:
ENT70135:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[63];
	local[3]= makeint(27);
	local[4]= makeint(1);
	w = makeint(48);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[4]= (pointer)((integer_t)local[4] + (integer_t)w);
	local[5]= loadglobal(fqv[64]);
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	if (local[0]==NIL) goto IF70167;
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[65];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF70168;
IF70167:
	local[1]= NIL;
IF70168:
	if (argv[2]==NIL) goto IF70178;
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[66];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF70179;
IF70178:
	local[1]= NIL;
IF70179:
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[67];
	local[3]= makeint(27);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= (pointer)((integer_t)(loadglobal(fqv[9]))+4);
	local[2]= fqv[68];
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[11],w);
	w = local[1];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[9],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT70216;}
	local[15]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+16;
	w=(pointer)F68597(ctx,1,local+15); /*reploop*/
CAT70216:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,2);
	w = local[9];
	local[1]= loadglobal(fqv[9]);
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK70133:
	ctx->vsp=local; return(local[0]);}

/*eustop*/
static pointer F68601(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST70237:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	if (w==NIL) goto IF70247;
	local[1]= makeint(4);
	local[2]= fqv[69];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,0,local+3,&ftab[10],fqv[70]); /*lisp-implementation-version*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,3,local+1,&ftab[2],fqv[7]); /*warning-message*/
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,0,local+1); /*terpri*/
	local[1]= makeint(2);
	local[2]= fqv[71];
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)SIGNAL(ctx,3,local+1); /*unix:signal*/
	local[1]= makeint(13);
	local[2]= fqv[72];
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,2,local+1); /*unix:signal*/
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto IF70278;
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[73]); /*unix:tcgets*/
	local[1]= w;
	storeglobal(fqv[74],w);
	local[1]= loadglobal(fqv[75]);
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[76]); /*new-history*/
	local[1]= w;
	goto IF70279;
IF70278:
	local[1]= NIL;
IF70279:
	goto IF70248;
IF70247:
	local[1]= NIL;
IF70248:
	if (local[0]==NIL) goto IF70306;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[77]); /*find-executable*/
	local[1]= w;
	storeglobal(fqv[78],w);
	goto IF70307;
IF70306:
	local[1]= NIL;
IF70307:
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	local[1]= w;
	storeglobal(fqv[80],w);
	local[1]= local[0];
	storeglobal(fqv[81],local[1]);
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[82]); /*pathname-name*/
	local[1]= w;
	storeglobal(fqv[33],w);
	local[1]= fqv[83];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	local[1]= w;
	if (local[1]!=NIL) goto IF70361;
	local[2]= loadglobal(fqv[17]);
	local[3]= fqv[84];
	ctx->vsp=local+4;
	w=(pointer)GETENV(ctx,1,local+3); /*unix:getenv*/
	local[3]= w;
	local[4]= fqv[85];
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[1] = w;
	local[2]= local[1];
	goto IF70362;
IF70361:
	local[2]= NIL;
IF70362:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,1,local+2,&ftab[15],fqv[86]); /*probe-file*/
	if (w==NIL) goto IF70382;
	local[2]= local[1];
	local[3]= fqv[87];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,3,local+2,&ftab[16],fqv[88]); /*load*/
	local[2]= w;
	goto IF70383;
IF70382:
	local[2]= NIL;
IF70383:
	w = local[2];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,1,local+1,&ftab[15],fqv[86]); /*probe-file*/
	if (w==NIL) goto IF70400;
	local[1]= fqv[90];
	local[2]= fqv[87];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,3,local+1,&ftab[16],fqv[88]); /*load*/
	local[1]= w;
	goto IF70401;
IF70400:
	local[1]= NIL;
IF70401:
	if (local[0]==NIL) goto IF70416;
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[82]); /*pathname-name*/
	local[1]= w;
	local[2]= fqv[91];
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w==NIL) goto IF70416;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(2);
	if ((integer_t)local[1] < (integer_t)w) goto IF70416;
	local[1]= (pointer)get_sym_func(fqv[92]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[93]); /*exit*/
	local[1]= w;
	goto IF70417;
IF70416:
	local[1]= NIL;
IF70417:
	if (loadglobal(fqv[94])==NIL) goto IF70448;
	local[1]= loadglobal(fqv[94]);
	local[2]= loadglobal(fqv[81]);
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	local[1]= w;
	goto IF70449;
IF70448:
	local[1]= NIL;
IF70449:
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= loadglobal(fqv[81]);
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= (pointer)((integer_t)(w)-4);
WHL70497:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX70498;
	local[4]= loadglobal(fqv[81]);
	local[5]= (pointer)((integer_t)(local[2])+4);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[1] = w;
	local[4]= local[1];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	if (makeint(40)!=local[4]) goto CON70521;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,1,local+4,&ftab[18],fqv[95]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	goto CON70519;
CON70521:
	local[4]= local[1];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[4]= ((makeint(45))==(local[4])?T:NIL);
	if (local[4]!=NIL) goto CON70519;
CON70534:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,1,local+4,&ftab[16],fqv[88]); /*load*/
	local[4]= w;
	goto CON70519;
CON70543:
	local[4]= NIL;
CON70519:
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL70497;
WHX70498:
	local[4]= NIL;
BLK70499:
	w = NIL;
	{jmp_buf jb;
	w = fqv[96];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT70565;}
WHL70572:
	if (T==NIL) goto WHX70573;
	{jmp_buf jb;
	w = makeint(0);
	ctx->vsp=local+7;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT70579;}
	local[13]= makeint(0);
	local[14]= fqv[97];
	w = local[14];
	ctx->vsp=local+15;
	bindspecial(ctx,fqv[11],w);
	w = local[13];
	ctx->vsp=local+18;
	bindspecial(ctx,fqv[9],w);
	local[21]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+22;
	w=(pointer)F68597(ctx,1,local+21); /*reploop*/
	local[21]= w;
	ctx->vsp=local+22;
	unbindx(ctx,2);
	w = local[21];
	local[13]= fqv[96];
	w = NIL;
	ctx->vsp=local+14;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[13];
CAT70579:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL70572;
WHX70573:
	local[7]= NIL;
BLK70574:
	w = local[7];
CAT70565:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK70235:
	ctx->vsp=local; return(local[0]);}

/*reset*/
static pointer F68603(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT70621;}
	local[0]= makeint(0);
ENT70621:
ENT70620:
	if (n>1) maerror();
	local[1]= local[0];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK70618:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___toplevel(ctx,n,argv,env)
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
	local[0]= fqv[98];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF70643;
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[18],w);
	goto IF70644;
IF70643:
	local[0]= fqv[100];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF70644:
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[16];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70666;
	local[0]= fqv[16];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70689;
	local[0]= fqv[16];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70690;
IF70689:
	local[0]= NIL;
IF70690:
	local[0]= fqv[16];
	goto IF70667;
IF70666:
	local[0]= NIL;
IF70667:
	local[0]= fqv[46];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70709;
	local[0]= fqv[46];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70732;
	local[0]= fqv[46];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70733;
IF70732:
	local[0]= NIL;
IF70733:
	local[0]= fqv[46];
	goto IF70710;
IF70709:
	local[0]= NIL;
IF70710:
	local[0]= fqv[44];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70752;
	local[0]= fqv[44];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70775;
	local[0]= fqv[44];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70776;
IF70775:
	local[0]= NIL;
IF70776:
	local[0]= fqv[44];
	goto IF70753;
IF70752:
	local[0]= NIL;
IF70753:
	local[0]= fqv[45];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70795;
	local[0]= fqv[45];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70818;
	local[0]= fqv[45];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70819;
IF70818:
	local[0]= NIL;
IF70819:
	local[0]= fqv[45];
	goto IF70796;
IF70795:
	local[0]= NIL;
IF70796:
	local[0]= fqv[43];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70838;
	local[0]= fqv[43];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70861;
	local[0]= fqv[43];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70862;
IF70861:
	local[0]= NIL;
IF70862:
	local[0]= fqv[43];
	goto IF70839;
IF70838:
	local[0]= NIL;
IF70839:
	local[0]= fqv[41];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70881;
	local[0]= fqv[41];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70904;
	local[0]= fqv[41];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70905;
IF70904:
	local[0]= NIL;
IF70905:
	local[0]= fqv[41];
	goto IF70882;
IF70881:
	local[0]= NIL;
IF70882:
	local[0]= fqv[42];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70924;
	local[0]= fqv[42];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70947;
	local[0]= fqv[42];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70948;
IF70947:
	local[0]= NIL;
IF70948:
	local[0]= fqv[42];
	goto IF70925;
IF70924:
	local[0]= NIL;
IF70925:
	local[0]= fqv[104];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF70967;
	local[0]= fqv[104];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[104];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF70990;
	local[0]= fqv[104];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[3]);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF70991;
IF70990:
	local[0]= NIL;
IF70991:
	local[0]= fqv[104];
	goto IF70968;
IF70967:
	local[0]= NIL;
IF70968:
	local[0]= fqv[105];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71013;
	local[0]= fqv[105];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[105];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71036;
	local[0]= fqv[105];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71037;
IF71036:
	local[0]= NIL;
IF71037:
	local[0]= fqv[105];
	goto IF71014;
IF71013:
	local[0]= NIL;
IF71014:
	local[0]= fqv[94];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71056;
	local[0]= fqv[94];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[94];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71079;
	local[0]= fqv[94];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71080;
IF71079:
	local[0]= NIL;
IF71080:
	local[0]= fqv[94];
	goto IF71057;
IF71056:
	local[0]= NIL;
IF71057:
	local[0]= fqv[47];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71099;
	local[0]= fqv[47];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71122;
	local[0]= fqv[47];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71123;
IF71122:
	local[0]= NIL;
IF71123:
	local[0]= fqv[47];
	goto IF71100;
IF71099:
	local[0]= NIL;
IF71100:
	local[0]= fqv[37];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71142;
	local[0]= fqv[37];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71165;
	local[0]= fqv[37];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71166;
IF71165:
	local[0]= NIL;
IF71166:
	local[0]= fqv[37];
	goto IF71143;
IF71142:
	local[0]= NIL;
IF71143:
	local[0]= fqv[9];
	local[1]= fqv[106];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[11];
	local[1]= fqv[106];
	local[2]= fqv[107];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[106];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[33];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71209;
	local[0]= fqv[33];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71232;
	local[0]= fqv[33];
	local[1]= fqv[103];
	local[2]= fqv[108];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71233;
IF71232:
	local[0]= NIL;
IF71233:
	local[0]= fqv[33];
	goto IF71210;
IF71209:
	local[0]= NIL;
IF71210:
	local[0]= fqv[25];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71252;
	local[0]= fqv[25];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[25];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71275;
	local[0]= fqv[25];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71276;
IF71275:
	local[0]= NIL;
IF71276:
	local[0]= fqv[25];
	goto IF71253;
IF71252:
	local[0]= NIL;
IF71253:
	local[0]= fqv[74];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71295;
	local[0]= fqv[74];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71318;
	local[0]= fqv[74];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71319;
IF71318:
	local[0]= NIL;
IF71319:
	local[0]= fqv[74];
	goto IF71296;
IF71295:
	local[0]= NIL;
IF71296:
	local[0]= fqv[81];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71338;
	local[0]= fqv[81];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[81];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71361;
	local[0]= fqv[81];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71362;
IF71361:
	local[0]= NIL;
IF71362:
	local[0]= fqv[81];
	goto IF71339;
IF71338:
	local[0]= NIL;
IF71339:
	local[0]= fqv[55];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71381;
	local[0]= fqv[55];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71404;
	local[0]= fqv[55];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[109]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[110];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71405;
IF71404:
	local[0]= NIL;
IF71405:
	local[0]= fqv[55];
	goto IF71382;
IF71381:
	local[0]= NIL;
IF71382:
	local[0]= fqv[60];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71449;
	local[0]= fqv[60];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71472;
	local[0]= fqv[60];
	local[1]= fqv[103];
	local[2]= fqv[111];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71473;
IF71472:
	local[0]= NIL;
IF71473:
	local[0]= fqv[60];
	goto IF71450;
IF71449:
	local[0]= NIL;
IF71450:
	local[0]= fqv[0];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71496;
	local[0]= fqv[0];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71519;
	local[0]= fqv[0];
	local[1]= fqv[103];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71520;
IF71519:
	local[0]= NIL;
IF71520:
	local[0]= fqv[0];
	goto IF71497;
IF71496:
	local[0]= NIL;
IF71497:
	local[0]= fqv[59];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71539;
	local[0]= fqv[59];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[59];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71562;
	local[0]= fqv[59];
	local[1]= fqv[103];
	local[2]= makeflt(1.00000000e+01);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71563;
IF71562:
	local[0]= NIL;
IF71563:
	local[0]= fqv[59];
	goto IF71540;
IF71539:
	local[0]= NIL;
IF71540:
	local[0]= fqv[61];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71582;
	local[0]= fqv[61];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71605;
	local[0]= fqv[61];
	local[1]= fqv[103];
	local[2]= fqv[112];
	ctx->vsp=local+3;
	w=(pointer)GETENV(ctx,1,local+2); /*unix:getenv*/
	local[2]= ((w)==NIL?T:NIL);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71606;
IF71605:
	local[0]= NIL;
IF71606:
	local[0]= fqv[61];
	goto IF71583;
IF71582:
	local[0]= NIL;
IF71583:
	local[0]= fqv[20];
	local[1]= fqv[103];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[111],module,F68571,fqv[113]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F68573,fqv[115]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[116],module,F68576,fqv[117]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F68578,fqv[118]);
	local[0]= fqv[13];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71646;
	local[0]= fqv[13];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF71669;
	local[0]= fqv[13];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[119]);
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,2,local+2,&ftab[19],fqv[120]); /*make-sequence*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF71670;
IF71669:
	local[0]= NIL;
IF71670:
	local[0]= fqv[13];
	goto IF71647;
IF71646:
	local[0]= NIL;
IF71647:
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F68581,fqv[121]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[122],module,F68583,fqv[123]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[12],module,F68585,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F68587,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F68589,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F68591,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[57],module,F68593,fqv[131]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F68595,fqv[133]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F68597,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[51],module,F68599,fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F68601,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F68603,fqv[140]);
	local[0]= fqv[141];
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[143]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
