/* string.c :  entry=string */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "string.h"
#pragma init (register_string)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___string();
extern pointer build_quote_vector();
static register_string()
  { add_module_initializer("___string", ___string);}

static pointer F50706();
static pointer F50709();
static pointer F50711();
static pointer F50713();
static pointer F50715();
static pointer F50717();
static pointer F50719();
static pointer F50721();
static pointer F50723();
static pointer F50725();
static pointer F50727();
static pointer F50729();
static pointer F50731();
static pointer F50733();
static pointer F50742();
static pointer F50745();
static pointer F50747();
static pointer F50749();
static pointer F50751();
static pointer F50753();
static pointer F50755();
static pointer F50757();
static pointer F50759();
static pointer F50761();
static pointer F50764();
static pointer F50766();
static pointer F50768();
static pointer F50770();
static pointer F50788();
static pointer F50789();
static pointer F50790();
static pointer F50791();
static pointer F50792();
static pointer F50793();

/*read_sharp_backslash*/
static pointer F50706(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,1,local+3); /*read-char*/
	local[0] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ALPHAP(ctx,1,local+3); /*alpha-char-p*/
	if (w==NIL) goto CON50883;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)UNREADCH(ctx,2,local+3); /*unread-char*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[1] = w;
	local[3]= *(ovafptr(local[1],fqv[0]));
	local[4]= fqv[1];
	local[5]= fqv[2];
	local[6]= (pointer)get_sym_func(fqv[3]);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,4,local+3,&ftab[0],fqv[4]); /*assoc*/
	local[2] = w;
	if (local[2]==NIL) goto IF50922;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF50923;
IF50922:
	local[3]= *(ovafptr(local[1],fqv[0]));
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	if (makeint(1)!=local[3]) goto IF50935;
	local[3]= local[0];
	goto IF50936;
IF50935:
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
IF50936:
IF50923:
	goto CON50881;
CON50883:
	local[3]= local[0];
	goto CON50881;
CON50946:
	local[3]= NIL;
CON50881:
	w = local[3];
	local[0]= w;
BLK50845:
	ctx->vsp=local; return(local[0]);}

/*true-string*/
static pointer F50709(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF50966;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF50967;
IF50966:
	local[0]= argv[0];
IF50967:
	w = local[0];
	local[0]= w;
BLK50956:
	ctx->vsp=local; return(local[0]);}

/*string*/
static pointer F50711(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto CON50992;
	local[0]= argv[0];
	goto CON50990;
CON50992:
	w = argv[0];
	if (!issymbol(w)) goto CON50998;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	goto CON50990;
CON50998:
	w = argv[0];
	if (!isnum(w)) goto CON51010;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[6]); /*princ-to-string*/
	local[0]= w;
	goto CON50990;
CON51010:
	local[0]= fqv[7];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON50990;
CON51019:
	local[0]= NIL;
CON50990:
	w = local[0];
	local[0]= w;
BLK50980:
	ctx->vsp=local; return(local[0]);}

/*make-string*/
static pointer F50713(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[8]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
BLK51028:
	ctx->vsp=local; return(local[0]);}

/*string-left-trim*/
static pointer F50715(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F50709(ctx,1,local+1); /*true-string*/
	argv[1] = w;
WHL51088:
	local[1]= argv[1];
	{ register integer_t i=intval(local[0]);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[9]); /*position*/
	if (w==NIL) goto WHX51089;
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL51088;
WHX51089:
	local[1]= NIL;
BLK51090:
	local[1]= argv[1];
	local[2]= local[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK51045:
	ctx->vsp=local; return(local[0]);}

/*string-right-trim*/
static pointer F50717(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F50709(ctx,1,local+1); /*true-string*/
	argv[1] = w;
WHL51165:
	local[1]= argv[1];
	{ register integer_t i=intval((pointer)((integer_t)(local[0])-4));
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[9]); /*position*/
	if (w==NIL) goto WHX51166;
	local[0] = (pointer)((integer_t)(local[0])-4);
	goto WHL51165;
WHX51166:
	local[1]= NIL;
BLK51167:
	local[1]= argv[1];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK51125:
	ctx->vsp=local; return(local[0]);}

/*string-trim*/
static pointer F50719(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F50717(ctx,2,local+1); /*string-right-trim*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F50715(ctx,2,local+0); /*string-left-trim*/
	local[0]= w;
BLK51201:
	ctx->vsp=local; return(local[0]);}

/*nstring-downcase*/
static pointer F50721(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51245;
	local[0] = makeint(0);
KEY51245:
	if (n & (1<<1)) goto KEY51249;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY51249:
	w = argv[0];
	if (isstring(w)) goto IF51260;
	local[2]= fqv[11];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF51261;
IF51260:
	local[2]= NIL;
IF51261:
WHL51269:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX51270;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[0];
	{ register integer_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHDOWNCASE(ctx,1,local+4); /*char-downcase*/
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.str.chars[i]=intval(w);}
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL51269;
WHX51270:
	local[2]= NIL;
BLK51271:
	w = argv[0];
	local[0]= w;
BLK51222:
	ctx->vsp=local; return(local[0]);}

/*nstring-upcase*/
static pointer F50723(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[12], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51324;
	local[0] = makeint(0);
KEY51324:
	if (n & (1<<1)) goto KEY51328;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY51328:
	w = argv[0];
	if (isstring(w)) goto IF51339;
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF51340;
IF51339:
	local[2]= NIL;
IF51340:
WHL51348:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX51349;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[0];
	{ register integer_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHUPCASE(ctx,1,local+4); /*char-upcase*/
	{ register integer_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.str.chars[i]=intval(w);}
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL51348;
WHX51349:
	local[2]= NIL;
BLK51350:
	w = argv[0];
	local[0]= w;
BLK51305:
	ctx->vsp=local; return(local[0]);}

/*string-upcase*/
static pointer F50725(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[14], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51394;
	local[0] = makeint(0);
KEY51394:
	if (n & (1<<1)) goto KEY51399;
	local[1] = NIL;
KEY51399:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F50709(ctx,1,local+2); /*true-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[15];
	local[5]= local[0];
	local[6]= fqv[16];
	if (local[1]==NIL) goto IF51430;
	local[7]= local[1];
	goto IF51431;
IF51430:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
IF51431:
	ctx->vsp=local+8;
	w=(pointer)F50723(ctx,5,local+3); /*nstring-upcase*/
	local[0]= w;
BLK51384:
	ctx->vsp=local; return(local[0]);}

/*string-downcase*/
static pointer F50727(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[17], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51454;
	local[0] = makeint(0);
KEY51454:
	if (n & (1<<1)) goto KEY51459;
	local[1] = NIL;
KEY51459:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F50709(ctx,1,local+2); /*true-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[15];
	local[5]= local[0];
	local[6]= fqv[16];
	if (local[1]==NIL) goto IF51490;
	local[7]= local[1];
	goto IF51491;
IF51490:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
IF51491:
	ctx->vsp=local+8;
	w=(pointer)F50721(ctx,5,local+3); /*nstring-downcase*/
	local[0]= w;
BLK51444:
	ctx->vsp=local; return(local[0]);}

/*string=*/
static pointer F50729(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[18], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY51518;
	local[0] = makeint(0);
KEY51518:
	if (n & (1<<1)) goto KEY51523;
	local[1] = makeint(100000000);
KEY51523:
	if (n & (1<<2)) goto KEY51528;
	local[2] = makeint(0);
KEY51528:
	if (n & (1<<3)) goto KEY51533;
	local[3] = makeint(100000000);
KEY51533:
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,6,local+4,&ftab[3],fqv[19]); /*stringeq*/
	local[0]= w;
BLK51504:
	ctx->vsp=local; return(local[0]);}

/*string-equal*/
static pointer F50731(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[20], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY51567;
	local[0] = makeint(0);
KEY51567:
	if (n & (1<<1)) goto KEY51572;
	local[1] = makeint(100000000);
KEY51572:
	if (n & (1<<2)) goto KEY51577;
	local[2] = makeint(0);
KEY51577:
	if (n & (1<<3)) goto KEY51582;
	local[3] = makeint(100000000);
KEY51582:
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,6,local+4,&ftab[4],fqv[21]); /*stringequal*/
	local[0]= w;
BLK51553:
	ctx->vsp=local; return(local[0]);}

/*substringp*/
static pointer F50733(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[0]= (pointer)((integer_t)local[0] - (integer_t)w);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= makeint(0);
TAG51651:
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF51656;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK51616;
	goto IF51657;
IF51656:
	local[3]= NIL;
IF51657:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[22];
	local[6]= local[2];
	local[7]= fqv[23];
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F50731(ctx,6,local+3); /*string-equal*/
	if (w==NIL) goto IF51672;
	w = T;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK51602;
	goto IF51673;
IF51672:
	local[3]= NIL;
IF51673:
	local[3]= (pointer)((integer_t)(local[2])+4);
	local[2] = local[3];
	w = NIL;
	ctx->vsp=local+3;
	goto TAG51651;
	w = NIL;
	local[0]= w;
BLK51616:
	w = local[0];
	local[0]= w;
BLK51602:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M51736(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK51737:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M51758(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w = argv[2];
	if (!isnum(w)) goto IF51777;
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
	goto IF51778;
IF51777:
	local[0]= argv[4];
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[25]); /*flatten*/
	local[2]= w;
WHL51828:
	if (local[2]==NIL) goto WHX51829;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto CON51879;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= argv[3];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[3] = w;
	local[3]= argv[3];
	goto CON51877;
CON51879:
	local[3]= makeint(0);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL51934:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX51935;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)POKE(ctx,4,local+5); /*system:poke*/
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	argv[3] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL51934;
WHX51935:
	local[5]= NIL;
BLK51936:
	w = NIL;
	local[3]= w;
	goto CON51877;
CON51905:
	local[3]= NIL;
CON51877:
	goto WHL51828;
WHX51829:
	local[3]= NIL;
BLK51830:
	w = NIL;
	local[0]= w;
IF51778:
	w = local[0];
	local[0]= w;
BLK51759:
	ctx->vsp=local; return(local[0]);}

/*explode-directory-names*/
static pointer F50742(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= NIL;
WHL52024:
	local[4]= makeint(47);
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,4,local+4,&ftab[2],fqv[9]); /*position*/
	local[3] = w;
	if (local[3]==NIL) goto WHX52025;
	local[4]= argv[0];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[0] = w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint(0);
	if ((integer_t)local[4] <= (integer_t)w) goto IF52053;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF52054;
IF52053:
	local[4]= NIL;
IF52054:
	local[2] = (pointer)((integer_t)(local[3])+4);
	goto WHL52024;
WHX52025:
	local[4]= NIL;
BLK52026:
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,2,local+4); /*subseq*/
	local[0] = w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint(0);
	if ((integer_t)local[4] <= (integer_t)w) goto IF52093;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF52094;
IF52093:
	local[4]= NIL;
IF52094:
	w = local[1];
	local[0]= w;
BLK51996:
	ctx->vsp=local; return(local[0]);}

/*:parse-namestring*/
static pointer M52133(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	argv[0]->c.obj.iv[2] = NIL;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,1,local+7,&ftab[6],fqv[26]); /*zerop*/
	if (w==NIL) goto IF52175;
	argv[0]->c.obj.iv[0] = fqv[27];
	argv[0]->c.obj.iv[1] = fqv[28];
	w = argv[0];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK52134;
	goto IF52176;
IF52175:
	local[7]= NIL;
IF52176:
	local[7]= makeint(58);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto IF52203;
	local[0] = local[6];
	local[7]= argv[2];
	local[8]= makeint(0);
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	argv[0]->c.obj.iv[0] = w;
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[7]= local[0];
	goto IF52204;
IF52203:
	local[7]= NIL;
IF52204:
	local[1] = local[0];
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint(47);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON52247;
	local[7]= fqv[29];
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[2] = cons(ctx,local[7],w);
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[7]= local[1];
	goto CON52245;
CON52247:
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint(126);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON52280;
	local[7]= fqv[30];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F50742(ctx,1,local+7); /*explode-directory-names*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= fqv[29];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NCONC(ctx,2,local+7); /*nconc*/
	argv[0]->c.obj.iv[2] = w;
	local[1] = (pointer)((integer_t)(local[1])+4);
	local[7]= local[1];
	goto CON52245;
CON52280:
	local[7]= NIL;
CON52245:
WHL52325:
	local[7]= makeint(47);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto WHX52326;
	local[7]= argv[2];
	local[8]= local[1];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	w = makeint(0);
	if ((integer_t)local[7] <= (integer_t)w) goto IF52354;
	local[7]= local[3];
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[2] = cons(ctx,local[7],w);
	local[7]= argv[0]->c.obj.iv[2];
	goto IF52355;
IF52354:
	local[7]= NIL;
IF52355:
	local[1] = (pointer)((integer_t)(local[6])+4);
	local[2] = local[1];
	goto WHL52325;
WHX52326:
	local[7]= NIL;
BLK52327:
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[4] = w;
	local[7]= local[4];
	local[8]= fqv[31];
	ctx->vsp=local+9;
	w=(pointer)EQUAL(ctx,2,local+7); /*equal*/
	if (w==NIL) goto CON52408;
	argv[0]->c.obj.iv[3] = local[4];
	argv[0]->c.obj.iv[4] = NIL;
	local[7]= argv[0]->c.obj.iv[4];
	goto CON52406;
CON52408:
	local[7]= makeint(46);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[2] = w;
	if (local[2]!=NIL) goto CON52441;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF52447;
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	argv[0]->c.obj.iv[3] = w;
	local[7]= argv[0]->c.obj.iv[3];
	goto IF52448;
IF52447:
	local[7]= NIL;
IF52448:
	goto CON52439;
CON52441:
	local[2] = (pointer)((integer_t)(local[2])+4);
WHL52478:
	local[7]= makeint(46);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto WHX52479;
	local[2] = (pointer)((integer_t)(local[6])+4);
	goto WHL52478;
WHX52479:
	local[7]= NIL;
BLK52480:
	local[7]= argv[2];
	local[8]= local[1];
	local[9]= (pointer)((integer_t)(local[2])-4);
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	argv[0]->c.obj.iv[3] = w;
	local[7]= argv[2];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	argv[0]->c.obj.iv[4] = w;
	local[7]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+8;
	w=(pointer)F50764(ctx,1,local+7); /*null-string-p*/
	if (w==NIL) goto IF52526;
	argv[0]->c.obj.iv[3] = NIL;
	local[7]= argv[0]->c.obj.iv[3];
	goto IF52527;
IF52526:
	local[7]= NIL;
IF52527:
	goto CON52439;
CON52464:
	local[7]= NIL;
CON52439:
	goto CON52406;
CON52423:
	local[7]= NIL;
CON52406:
	w = argv[0];
	local[0]= w;
BLK52134:
	ctx->vsp=local; return(local[0]);}

/*:directory-string*/
static pointer M52543(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[2];
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	if (w==NIL) goto IF52570;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= fqv[32];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= local[0];
	goto IF52571;
IF52570:
	local[2]= NIL;
IF52571:
	local[2]= NIL;
	local[3]= local[1];
WHL52651:
	if (local[3]==NIL) goto WHX52652;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= fqv[33];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	goto WHL52651;
WHX52652:
	local[4]= NIL;
BLK52653:
	w = NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0] = w;
	local[2]= (pointer)get_sym_func(fqv[34]);
	local[3]= loadglobal(fqv[8]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK52544:
	ctx->vsp=local; return(local[0]);}

/*:namestring*/
static pointer M52742(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	if (argv[0]->c.obj.iv[4]==NIL) goto IF52770;
	local[1]= loadglobal(fqv[8]);
	local[2]= fqv[36];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
	goto IF52771;
IF52770:
	local[1]= NIL;
IF52771:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF52783;
	local[2]= loadglobal(fqv[8]);
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,6,local+2); /*concatenate*/
	local[2]= w;
	goto IF52784;
IF52783:
	local[2]= loadglobal(fqv[8]);
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,5,local+2); /*concatenate*/
	local[2]= w;
IF52784:
	w = local[2];
	local[0]= w;
BLK52743:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M52805(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52809;}
	local[0]= NIL;
ENT52809:
ENT52808:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF52825;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF52826;
IF52825:
	local[1]= argv[0]->c.obj.iv[0];
IF52826:
	w = local[1];
	local[0]= w;
BLK52806:
	ctx->vsp=local; return(local[0]);}

/*:device*/
static pointer M52838(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52842;}
	local[0]= NIL;
ENT52842:
ENT52841:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF52858;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF52859;
IF52858:
	local[1]= argv[0]->c.obj.iv[1];
IF52859:
	w = local[1];
	local[0]= w;
BLK52839:
	ctx->vsp=local; return(local[0]);}

/*:directory*/
static pointer M52871(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52875;}
	local[0]= NIL;
ENT52875:
ENT52874:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF52891;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF52892;
IF52891:
	local[1]= argv[0]->c.obj.iv[2];
IF52892:
	w = local[1];
	local[0]= w;
BLK52872:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M52904(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52908;}
	local[0]= NIL;
ENT52908:
ENT52907:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF52924;
	argv[0]->c.obj.iv[3] = local[0];
	local[1]= argv[0]->c.obj.iv[3];
	goto IF52925;
IF52924:
	local[1]= argv[0]->c.obj.iv[3];
IF52925:
	w = local[1];
	local[0]= w;
BLK52905:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M52937(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52941;}
	local[0]= NIL;
ENT52941:
ENT52940:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF52957;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF52958;
IF52957:
	local[1]= argv[0]->c.obj.iv[4];
IF52958:
	w = local[1];
	local[0]= w;
BLK52938:
	ctx->vsp=local; return(local[0]);}

/*:set-type*/
static pointer M52970(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK52971:
	ctx->vsp=local; return(local[0]);}

/*:version*/
static pointer M52992(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52996;}
	local[0]= NIL;
ENT52996:
ENT52995:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53012;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto IF53013;
IF53012:
	local[1]= argv[0]->c.obj.iv[5];
IF53013:
	w = local[1];
	local[0]= w;
BLK52993:
	ctx->vsp=local; return(local[0]);}

/*:merge*/
static pointer M53025(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[0]!=NIL) goto IF53040;
	argv[0]->c.obj.iv[0] = *(ovafptr(argv[2],fqv[37]));
	local[0]= argv[0]->c.obj.iv[0];
	goto IF53041;
IF53040:
	local[0]= NIL;
IF53041:
	if (argv[0]->c.obj.iv[1]!=NIL) goto IF53054;
	argv[0]->c.obj.iv[1] = *(ovafptr(argv[2],fqv[38]));
	local[0]= argv[0]->c.obj.iv[1];
	goto IF53055;
IF53054:
	local[0]= NIL;
IF53055:
	if (argv[0]->c.obj.iv[2]!=NIL) goto IF53068;
	argv[0]->c.obj.iv[2] = *(ovafptr(argv[2],fqv[39]));
	local[0]= argv[0]->c.obj.iv[2];
	goto IF53069;
IF53068:
	local[0]= NIL;
IF53069:
	if (argv[0]->c.obj.iv[3]!=NIL) goto IF53082;
	argv[0]->c.obj.iv[3] = *(ovafptr(argv[2],fqv[40]));
	local[0]= argv[0]->c.obj.iv[3];
	goto IF53083;
IF53082:
	local[0]= NIL;
IF53083:
	if (argv[0]->c.obj.iv[4]!=NIL) goto IF53096;
	argv[0]->c.obj.iv[4] = *(ovafptr(argv[2],fqv[41]));
	local[0]= argv[0]->c.obj.iv[4];
	goto IF53097;
IF53096:
	local[0]= NIL;
IF53097:
	if (argv[0]->c.obj.iv[5]!=NIL) goto IF53110;
	argv[0]->c.obj.iv[5] = *(ovafptr(argv[2],fqv[42]));
	local[0]= argv[0]->c.obj.iv[5];
	goto IF53111;
IF53110:
	local[0]= NIL;
IF53111:
	w = argv[0];
	local[0]= w;
BLK53026:
	ctx->vsp=local; return(local[0]);}

/*:add-directory*/
static pointer M53126(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK53127:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M53155(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53159;}
	local[0]= T;
ENT53159:
ENT53158:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= fqv[43];
	local[3]= argv[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK53156:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M53183(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[45], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY53200;
	local[0] = NIL;
KEY53200:
	if (n & (1<<1)) goto KEY53205;
	local[1] = NIL;
KEY53205:
	if (n & (1<<2)) goto KEY53210;
	local[2] = NIL;
KEY53210:
	if (n & (1<<3)) goto KEY53215;
	local[3] = NIL;
KEY53215:
	if (n & (1<<4)) goto KEY53220;
	local[4] = NIL;
KEY53220:
	if (n & (1<<5)) goto KEY53225;
	local[5] = NIL;
KEY53225:
	if (local[0]==NIL) goto IF53234;
	argv[0]->c.obj.iv[0] = local[0];
	local[6]= argv[0]->c.obj.iv[0];
	goto IF53235;
IF53234:
	local[6]= NIL;
IF53235:
	if (local[1]==NIL) goto IF53247;
	argv[0]->c.obj.iv[1] = local[1];
	local[6]= argv[0]->c.obj.iv[1];
	goto IF53248;
IF53247:
	local[6]= NIL;
IF53248:
	if (local[2]==NIL) goto IF53260;
	argv[0]->c.obj.iv[2] = local[2];
	local[6]= argv[0]->c.obj.iv[2];
	goto IF53261;
IF53260:
	local[6]= NIL;
IF53261:
	if (local[3]==NIL) goto IF53273;
	argv[0]->c.obj.iv[3] = local[3];
	local[6]= argv[0]->c.obj.iv[3];
	goto IF53274;
IF53273:
	local[6]= NIL;
IF53274:
	if (local[4]==NIL) goto IF53286;
	argv[0]->c.obj.iv[4] = local[4];
	local[6]= argv[0]->c.obj.iv[4];
	goto IF53287;
IF53286:
	local[6]= NIL;
IF53287:
	if (local[5]==NIL) goto IF53299;
	argv[0]->c.obj.iv[5] = local[5];
	local[6]= argv[0]->c.obj.iv[5];
	goto IF53300;
IF53299:
	local[6]= NIL;
IF53300:
	w = argv[0];
	local[0]= w;
BLK53184:
	ctx->vsp=local; return(local[0]);}

/*pathnamep*/
static pointer F50745(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[46]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK53317:
	ctx->vsp=local; return(local[0]);}

/*pathname*/
static pointer F50747(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[46]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF53344;
	local[0]= argv[0];
	goto IF53345;
IF53344:
	if (argv[0]==NIL) goto IF53354;
	local[0]= loadglobal(fqv[46]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[47];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F50711(ctx,1,local+3); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF53355;
IF53354:
	local[0]= loadglobal(fqv[46]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
IF53355:
IF53345:
	w = local[0];
	local[0]= w;
BLK53334:
	ctx->vsp=local; return(local[0]);}

/*namestring*/
static pointer F50749(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto CON53404;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50711(ctx,1,local+0); /*string*/
	local[0]= w;
	goto CON53402;
CON53404:
	w = argv[0];
	if (!isstring(w)) goto CON53412;
	local[0]= argv[0];
	goto CON53402;
CON53412:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50745(ctx,1,local+0); /*pathnamep*/
	if (w==NIL) goto CON53418;
	local[0]= argv[0];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON53402;
CON53418:
	local[0]= fqv[48];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON53402;
CON53430:
	local[0]= NIL;
CON53402:
	w = local[0];
	local[0]= w;
BLK53392:
	ctx->vsp=local; return(local[0]);}

/*pathname-directory*/
static pointer F50751(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50747(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[39]));
	local[0]= w;
BLK53439:
	ctx->vsp=local; return(local[0]);}

/*pathname-name*/
static pointer F50753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50747(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[40]));
	local[0]= w;
BLK53456:
	ctx->vsp=local; return(local[0]);}

/*pathname-type*/
static pointer F50755(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50747(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[41]));
	local[0]= w;
BLK53473:
	ctx->vsp=local; return(local[0]);}

/*directory-namestring*/
static pointer F50757(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50747(ctx,1,local+0); /*pathname*/
	local[0]= w;
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK53490:
	ctx->vsp=local; return(local[0]);}

/*make-pathname*/
static pointer F50759(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[49], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY53522;
	local[0] = NIL;
KEY53522:
	if (n & (1<<1)) goto KEY53527;
	local[1] = NIL;
KEY53527:
	if (n & (1<<2)) goto KEY53532;
	local[2] = NIL;
KEY53532:
	if (n & (1<<3)) goto KEY53537;
	local[3] = NIL;
KEY53537:
	if (n & (1<<4)) goto KEY53542;
	local[4] = NIL;
KEY53542:
	if (n & (1<<5)) goto KEY53547;
	local[5] = NIL;
KEY53547:
	if (n & (1<<6)) goto KEY53552;
	local[6] = NIL;
KEY53552:
	local[7]= loadglobal(fqv[46]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[50];
	local[10]= fqv[51];
	local[11]= local[0];
	local[12]= fqv[52];
	local[13]= local[1];
	local[14]= fqv[53];
	local[15]= local[2];
	local[16]= fqv[54];
	local[17]= local[3];
	local[18]= fqv[55];
	local[19]= local[4];
	local[20]= fqv[56];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,14,local+8); /*send*/
	w = local[7];
	local[7]= w;
	local[8]= fqv[57];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F50747(ctx,1,local+9); /*pathname*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0]= w;
BLK53509:
	ctx->vsp=local; return(local[0]);}

/*parse-namestring*/
static pointer F50761(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50747(ctx,1,local+0); /*pathname*/
	local[0]= w;
BLK53612:
	ctx->vsp=local; return(local[0]);}

/*null-string-p*/
static pointer F50764(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
BLK53629:
	ctx->vsp=local; return(local[0]);}

/*merge-pathnames*/
static pointer F50766(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT53647;}
	local[0]= loadglobal(fqv[59]);
ENT53647:
ENT53646:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F50745(ctx,1,local+1); /*pathnamep*/
	if (w==NIL) goto IF53665;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)COPYOBJ(ctx,1,local+1); /*copy-object*/
	local[1]= w;
	goto IF53666;
IF53665:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F50747(ctx,1,local+1); /*pathname*/
	local[1]= w;
IF53666:
	argv[0] = local[1];
	local[1]= argv[0];
	local[2]= fqv[57];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F50747(ctx,1,local+3); /*pathname*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK53644:
	ctx->vsp=local; return(local[0]);}

/*concatenate-pathnames*/
static pointer F50768(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST53694:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[34]);
	local[2]= loadglobal(fqv[8]);
	local[3]= (pointer)get_sym_func(fqv[60]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F50747(ctx,1,local+1); /*pathname*/
	local[0]= w;
BLK53692:
	ctx->vsp=local; return(local[0]);}

/*truename*/
static pointer F50770(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F50747(ctx,1,local+0); /*pathname*/
	argv[0] = w;
	ctx->vsp=local+0;
	w=(pointer)GETWD(ctx,0,local+0); /*unix:getwd*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[35];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= T;
	if (local[1]==NIL) goto IF53756;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)CHDIR(ctx,1,local+3); /*unix:chdir*/
	local[2] = w;
	local[3]= local[2];
	goto IF53757;
IF53756:
	local[3]= NIL;
IF53757:
	local[3]= local[2];
	if (T!=local[3]) goto CON53773;
	ctx->vsp=local+3;
	w=(pointer)GETWD(ctx,0,local+3); /*unix:getwd*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint(1);
	if ((integer_t)local[3] <= (integer_t)w) goto IF53787;
	local[3]= loadglobal(fqv[8]);
	local[4]= local[2];
	local[5]= fqv[61];
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[2] = w;
	local[3]= local[2];
	goto IF53788;
IF53787:
	local[3]= NIL;
IF53788:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)CHDIR(ctx,1,local+3); /*unix:chdir*/
	local[3]= fqv[54];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F50753(ctx,1,local+4); /*pathname-name*/
	local[4]= w;
	local[5]= fqv[55];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F50755(ctx,1,local+6); /*pathname-type*/
	local[6]= w;
	local[7]= fqv[53];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)F50751(ctx,1,local+8); /*pathname-directory*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F50759(ctx,6,local+3); /*make-pathname*/
	local[3]= w;
	goto CON53771;
CON53773:
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto CON53771;
CON53825:
	local[3]= NIL;
CON53771:
	w = local[3];
	local[0]= w;
BLK53718:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M53873(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[63];
	local[2]= argv[1];
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[64];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK53874:
	ctx->vsp=local; return(local[0]);}

/*:string*/
static pointer M53904(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[65];
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F50749(ctx,1,local+5); /*namestring*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK53905:
	ctx->vsp=local; return(local[0]);}

/*:string2*/
static pointer M53925(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[66];
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F50749(ctx,1,local+4); /*namestring*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK53926:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M53945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53949;}
	local[0]= NIL;
ENT53949:
ENT53948:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53965;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF53966;
IF53965:
	local[1]= NIL;
IF53966:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK53946:
	ctx->vsp=local; return(local[0]);}

/*:server*/
static pointer M53980(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53984;}
	local[0]= NIL;
ENT53984:
ENT53983:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54000;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF54001;
IF54000:
	local[1]= NIL;
IF54001:
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK53981:
	ctx->vsp=local; return(local[0]);}

/*:connect*/
static pointer M54015(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54019;}
	local[0]= makeint(5);
ENT54019:
ENT54018:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,3,local+1,&ftab[7],fqv[67]); /*connect-server*/
	local[0]= w;
BLK54016:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M54041(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54045;}
	local[0]= NIL;
ENT54045:
ENT54044:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54061;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF54062;
IF54061:
	local[1]= NIL;
IF54062:
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK54042:
	ctx->vsp=local; return(local[0]);}

/*:protocol*/
static pointer M54076(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54080;}
	local[0]= NIL;
ENT54080:
ENT54079:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54096;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF54097;
IF54096:
	local[1]= NIL;
IF54097:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK54077:
	ctx->vsp=local; return(local[0]);}

/*:parse-namestring*/
static pointer M54111(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(58);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[9]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF54142;
	local[3]= argv[2];
	local[4]= makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[6] = w;
	local[0] = (pointer)((integer_t)(local[0])+4);
	local[3]= local[0];
	goto IF54143;
IF54142:
	argv[0]->c.obj.iv[6] = fqv[68];
	local[0] = makeint(0);
	local[3]= local[0];
IF54143:
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint(47);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON54180;
	local[3]= argv[2];
	local[4]= (pointer)((integer_t)(local[0])+4);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint(47);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON54180;
	local[3]= makeint(47);
	local[4]= argv[2];
	local[5]= fqv[15];
	local[6]= makeint(3);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[9]); /*position*/
	local[2] = w;
	if (local[2]!=NIL) goto IF54221;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[2] = w;
	local[3]= local[2];
	goto IF54222;
IF54221:
	local[3]= NIL;
IF54222:
	local[3]= argv[2];
	local[4]= makeint(2);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= makeint(58);
	local[4]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[9]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF54255;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= (pointer)((integer_t)(local[1])+4);
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,2,local+3); /*subseq*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[69]); /*read-from-string*/
	argv[0]->c.obj.iv[8] = w;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= makeint(0);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= argv[0]->c.obj.iv[7];
	goto IF54256;
IF54255:
	argv[0]->c.obj.iv[8] = makeint(80);
	local[3]= argv[0]->c.obj.iv[8];
IF54256:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[70]));
	local[5]= fqv[47];
	local[6]= argv[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= fqv[71];
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	argv[0]->c.obj.iv[2] = w;
	local[3]= argv[0];
	goto CON54178;
CON54180:
	local[3]= fqv[72];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto CON54178;
CON54323:
	local[3]= NIL;
CON54178:
	w = local[3];
	local[0]= w;
BLK54112:
	ctx->vsp=local; return(local[0]);}

/*url-pathname*/
static pointer F50788(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[73]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF54343;
	local[0]= argv[0];
	goto IF54344;
IF54343:
	if (argv[0]==NIL) goto IF54354;
	local[0]= loadglobal(fqv[73]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[47];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F50711(ctx,1,local+3); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF54355;
IF54354:
	local[0]= loadglobal(fqv[73]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
IF54355:
IF54344:
	w = local[0];
	local[0]= w;
BLK54333:
	ctx->vsp=local; return(local[0]);}

/*parse-url*/
static pointer F50789(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[74];
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(80);
	local[4]= makeint(0);
	local[5]= NIL;
	local[6]= makeint(58);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,2,local+6,&ftab[2],fqv[9]); /*position*/
	local[4] = w;
	if (local[4]==NIL) goto IF54426;
	local[6]= argv[0];
	local[7]= makeint(0);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[0] = w;
	local[4] = (pointer)((integer_t)(local[4])+4);
	local[6]= local[4];
	goto IF54427;
IF54426:
	local[4] = makeint(0);
	local[6]= local[4];
IF54427:
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(47);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto CON54462;
	local[6]= argv[0];
	local[7]= (pointer)((integer_t)(local[4])+4);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(47);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto CON54462;
	local[6]= argv[0];
	local[7]= makeint(2);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(47);
	local[9]= argv[0];
	local[10]= fqv[15];
	local[11]= makeint(3);
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,4,local+8,&ftab[2],fqv[9]); /*position*/
	local[4] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= makeint(58);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,2,local+6,&ftab[2],fqv[9]); /*position*/
	local[5] = w;
	if (local[5]==NIL) goto IF54516;
	local[6]= local[1];
	local[7]= (pointer)((integer_t)(local[5])+4);
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[69]); /*read-from-string*/
	local[3] = w;
	local[6]= local[1];
	local[7]= makeint(0);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= local[1];
	goto IF54517;
IF54516:
	local[3] = makeint(80);
	local[6]= local[3];
IF54517:
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F50747(ctx,1,local+6); /*pathname*/
	local[2] = w;
	local[6]= local[2];
	local[7]= fqv[53];
	local[8]= fqv[75];
	local[9]= local[2];
	local[10]= fqv[53];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,4,local+6); /*list*/
	local[6]= w;
	goto CON54460;
CON54462:
	local[6]= fqv[76];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto CON54460;
CON54591:
	local[6]= NIL;
CON54460:
	w = local[6];
	local[0]= w;
BLK54391:
	ctx->vsp=local; return(local[0]);}

/*digits-string*/
static pointer F50790(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54603;}
	local[0]= makeint(10);
ENT54603:
ENT54602:
	if (n>3) maerror();
	local[1]= argv[1];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,2,local+1); /*<=*/
	if (w==NIL) goto IF54619;
	local[1]= NIL;
	local[2]= fqv[77];
	local[3]= argv[0];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF54620;
IF54619:
	local[1]= loadglobal(fqv[8]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= (pointer)((integer_t)(argv[1])-4);
	ctx->vsp=local+4;
	w=(pointer)F50790(ctx,2,local+2); /*digits-string*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)F50790(ctx,2,local+3); /*digits-string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
IF54620:
	w = local[1];
	local[0]= w;
BLK54600:
	ctx->vsp=local; return(local[0]);}

/*timed-file-name*/
static pointer F50791(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54661;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT54661:
ENT54660:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= fqv[78];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)F50790(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)F50790(ctx,2,local+5); /*digits-string*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)F50790(ctx,2,local+6); /*digits-string*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	local[0]= w;
BLK54658:
	ctx->vsp=local; return(local[0]);}

/*dated-file-name*/
static pointer F50792(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54702;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT54702:
ENT54701:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= fqv[79];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(5);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)F50790(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= fqv[80];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[0];
	local[7]= makeint(3);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)F50790(ctx,2,local+6); /*digits-string*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	local[0]= w;
BLK54699:
	ctx->vsp=local; return(local[0]);}

/*sequential-file-name*/
static pointer F50793(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT54751;}
	local[0]= makeint(4);
ENT54751:
ENT54750:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= fqv[81];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F50790(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[0]= w;
BLK54748:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___string(ctx,n,argv,env)
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
	local[0]= fqv[82];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[83];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF54786;
	local[0]= fqv[84];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[85],w);
	goto IF54787;
IF54786:
	local[0]= fqv[86];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF54787:
	local[0]= fqv[87];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F50706,fqv[89]);
	local[0]= makeint(35);
	local[1]= makeint(92);
	local[2]= fqv[88];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F50709,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[8],module,F50711,fqv[92]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[93],module,F50713,fqv[94]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F50715,fqv[96]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[97],module,F50717,fqv[98]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[99],module,F50719,fqv[100]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[101],module,F50721,fqv[102]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F50723,fqv[104]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[105],module,F50725,fqv[106]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[107],module,F50727,fqv[108]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[109],module,F50729,fqv[110]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[3],module,F50731,fqv[111]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[112],module,F50733,fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M51736,fqv[114],fqv[8],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M51758,fqv[116],fqv[8],fqv[117]);
	local[0]= fqv[46];
	local[1]= fqv[118];
	local[2]= fqv[46];
	local[3]= fqv[119];
	local[4]= loadglobal(fqv[120]);
	local[5]= fqv[121];
	local[6]= fqv[122];
	local[7]= fqv[123];
	local[8]= NIL;
	local[9]= fqv[124];
	local[10]= NIL;
	local[11]= fqv[125];
	local[12]= makeint(-1);
	local[13]= fqv[126];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[9])(ctx,13,local+2,&ftab[9],fqv[127]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F50742,fqv[130]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52133,fqv[47],fqv[46],fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52543,fqv[35],fqv[46],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52742,fqv[44],fqv[46],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52805,fqv[51],fqv[46],fqv[134]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52838,fqv[52],fqv[46],fqv[135]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52871,fqv[53],fqv[46],fqv[136]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52904,fqv[54],fqv[46],fqv[137]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52937,fqv[55],fqv[46],fqv[138]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52970,fqv[139],fqv[46],fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52992,fqv[56],fqv[46],fqv[141]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53025,fqv[57],fqv[46],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53126,fqv[143],fqv[46],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53155,fqv[145],fqv[46],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53183,fqv[50],fqv[46],fqv[147]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[148],module,F50745,fqv[149]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F50747,fqv[150]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F50749,fqv[151]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[152],module,F50751,fqv[153]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[154],module,F50753,fqv[155]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F50755,fqv[157]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[158],module,F50757,fqv[159]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F50759,fqv[161]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[162],module,F50761,fqv[163]);
	local[0]= fqv[59];
	local[1]= fqv[118];
	local[2]= fqv[164];
	local[3]= fqv[165];
	local[4]= fqv[166];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F50764,fqv[169]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[170],module,F50766,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F50768,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F50770,fqv[175]);
	local[0]= fqv[73];
	local[1]= fqv[118];
	local[2]= fqv[73];
	local[3]= fqv[119];
	local[4]= loadglobal(fqv[46]);
	local[5]= fqv[121];
	local[6]= fqv[176];
	local[7]= fqv[123];
	local[8]= NIL;
	local[9]= fqv[124];
	local[10]= NIL;
	local[11]= fqv[125];
	local[12]= makeint(-1);
	local[13]= fqv[126];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[9])(ctx,13,local+2,&ftab[9],fqv[127]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53873,fqv[145],fqv[73],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53904,fqv[64],fqv[73],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53925,fqv[179],fqv[73],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53945,fqv[181],fqv[73],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53980,fqv[183],fqv[73],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54015,fqv[185],fqv[73],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54041,fqv[51],fqv[73],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54076,fqv[188],fqv[73],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54111,fqv[47],fqv[73],fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F50788,fqv[191]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[192],module,F50789,fqv[193]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F50790,fqv[195]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[196],module,F50791,fqv[197]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[198],module,F50792,fqv[199]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[200],module,F50793,fqv[201]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
