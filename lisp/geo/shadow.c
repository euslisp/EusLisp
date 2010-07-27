/* shadow.c :  entry=shadow */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "shadow.h"
#pragma init (register_shadow)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___shadow();
extern pointer build_quote_vector();
static register_shadow()
  { add_module_initializer("___shadow", ___shadow);}

static pointer F4233();
static pointer F4234();
static pointer F4235();
static pointer F4236();
static pointer F4237();
static pointer F4238();
static pointer F4239();
static pointer F4240();
static pointer F4241();
static pointer F4242();
static pointer F4243();

/*do-combination*/
static pointer F4244(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4246:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,1,local+3); /*gensym*/
	local[3]= w;
	local[4]= fqv[1];
	local[5]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[2];
	local[7]= fqv[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[1];
	local[9]= local[1];
	local[10]= fqv[4];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[5];
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
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
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
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
	local[0]= w;
BLK4245:
	ctx->vsp=local; return(local[0]);}

/*polygon-in-contact-p*/
static pointer F4233(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[0];
WHL4249:
	if (local[3]==NIL) goto WHX4250;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[1];
WHL4254:
	if (local[5]==NIL) goto WHX4255;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[7];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF4258;
	local[6]= local[2];
	local[7]= fqv[8];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF4258;
	w = T;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK4247;
	goto IF4259;
IF4258:
	local[6]= NIL;
IF4259:
	goto WHL4254;
WHX4255:
	local[6]= NIL;
BLK4256:
	w = NIL;
	goto WHL4249;
WHX4250:
	local[4]= NIL;
BLK4251:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK4247:
	ctx->vsp=local; return(local[0]);}

/*make-edges-from-vertices*/
static pointer F4234(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL4261:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4262;
	local[2]= loadglobal(fqv[9]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[10];
	local[5]= fqv[11];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= fqv[12];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL4261;
WHX4262:
	local[2]= NIL;
BLK4263:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK4260:
	ctx->vsp=local; return(local[0]);}

/*orthogonally-visible-faces*/
static pointer F4235(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL4268:
	if (local[4]==NIL) goto WHX4269;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[1];
	local[6]= local[3]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4272;
	local[5]= local[3];
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[1];
	goto IF4273;
IF4272:
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
IF4273:
	goto WHL4268;
WHX4269:
	local[5]= NIL;
BLK4270:
	w = NIL;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[15]); /*values*/
	local[0]= w;
BLK4266:
	ctx->vsp=local; return(local[0]);}

/*make-polygon*/
static pointer F4236(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4275:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[10];
	local[4]= fqv[17];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK4274:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-edge-loop*/
static pointer F4237(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL4279:
	if (local[2]==NIL) goto WHX4280;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[3] = local[4];
	goto WHL4279;
WHX4280:
	local[3]= NIL;
BLK4281:
	w = NIL;
	local[1]= local[0];
	local[2]= fqv[10];
	local[3]= fqv[19];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4277:
	ctx->vsp=local; return(local[0]);}

/*change-to-hole*/
static pointer F4238(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[20]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[10];
	local[3]= fqv[17];
	local[4]= argv[0];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4283:
	ctx->vsp=local; return(local[0]);}

/*project-shadow1*/
static pointer F4239(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[21],w);
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= fqv[22];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,1,local+8); /*v-*/
	local[8]= w;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= local[2];
WHL4286:
	if (local[15]==NIL) goto WHX4287;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[7];
	local[17]= local[14]->c.obj.iv[1];
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	local[17]= makeflt(0.00000000e+00);
	ctx->vsp=local+18;
	w=(*ftab[0])(ctx,2,local+16,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4290;
	local[16]= local[14];
	w = local[0];
	ctx->vsp=local+17;
	local[0] = cons(ctx,local[16],w);
	local[16]= local[0];
	goto IF4291;
IF4290:
	local[16]= local[14];
	w = local[1];
	ctx->vsp=local+17;
	local[1] = cons(ctx,local[16],w);
	local[16]= local[1];
IF4291:
	goto WHL4286;
WHX4287:
	local[16]= NIL;
BLK4288:
	w = NIL;
	local[14]= NIL;
	local[15]= local[0];
WHL4293:
	if (local[15]==NIL) goto WHX4294;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= local[14];
	local[23]= fqv[17];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
WHL4298:
	if (local[22]==NIL) goto WHX4299;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= argv[1];
	local[24]= fqv[23];
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[23]= w;
	w = local[16];
	ctx->vsp=local+24;
	local[16] = cons(ctx,local[23],w);
	goto WHL4298;
WHX4299:
	local[23]= NIL;
BLK4300:
	w = NIL;
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[16] = w;
	local[21]= NIL;
	local[22]= local[14];
	local[23]= fqv[24];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
WHL4303:
	if (local[22]==NIL) goto WHX4304;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= NIL;
	local[24]= local[21];
	local[25]= fqv[17];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.cdr;
WHL4308:
	if (local[24]==NIL) goto WHX4309;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24] = (w)->c.cons.cdr;
	w = local[25];
	local[23] = w;
	local[25]= argv[1];
	local[26]= fqv[23];
	local[27]= local[23];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	w = local[17];
	ctx->vsp=local+26;
	local[17] = cons(ctx,local[25],w);
	goto WHL4308;
WHX4309:
	local[25]= NIL;
BLK4310:
	w = NIL;
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= w;
	w = local[18];
	ctx->vsp=local+24;
	local[18] = cons(ctx,local[23],w);
	goto WHL4303;
WHX4304:
	local[23]= NIL;
BLK4305:
	w = NIL;
	local[21]= local[18];
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[18] = w;
	local[21]= NIL;
	local[22]= local[18];
WHL4313:
	if (local[22]==NIL) goto WHX4314;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= loadglobal(fqv[20]);
	ctx->vsp=local+24;
	w=(pointer)INSTANTIATE(ctx,1,local+23); /*instantiate*/
	local[23]= w;
	local[24]= local[23];
	local[25]= fqv[10];
	local[26]= fqv[17];
	local[27]= local[21];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,4,local+24); /*send*/
	w = local[23];
	local[23]= w;
	w = local[19];
	ctx->vsp=local+24;
	local[19] = cons(ctx,local[23],w);
	goto WHL4313;
WHX4314:
	local[23]= NIL;
BLK4315:
	w = NIL;
	local[21]= loadglobal(fqv[18]);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,1,local+21); /*instantiate*/
	local[21]= w;
	local[22]= local[21];
	local[23]= fqv[10];
	local[24]= fqv[17];
	local[25]= local[16];
	local[26]= fqv[24];
	local[27]= local[19];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,6,local+22); /*send*/
	w = local[21];
	local[21]= w;
	w = local[6];
	ctx->vsp=local+22;
	local[6] = cons(ctx,local[21],w);
	w = local[6];
	goto WHL4293;
WHX4294:
	local[16]= NIL;
BLK4295:
	w = NIL;
	local[14]= local[6];
	local[15]= (pointer)get_sym_func(fqv[25]);
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4319,env,argv,local);
	ctx->vsp=local+17;
	w=(pointer)SORT(ctx,3,local+14); /*sort*/
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
WHL4320:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4321;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[19];
	local[15] = w;
	local[14] = NIL;
WHL4325:
	if (local[6]==NIL) goto WHX4326;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[19];
	local[16] = w;
	storeglobal(fqv[26],local[15]);
	local[19]= local[16];
	storeglobal(fqv[27],local[19]);
	local[19]= local[15];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(*ftab[2])(ctx,2,local+19,&ftab[2],fqv[28]); /*face+*/
	local[17] = w;
	ctx->vsp=local+19;
	local[19]= makeclosure(codevec,quotevec,CLO4331,env,argv,local);
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(*ftab[3])(ctx,2,local+19,&ftab[3],fqv[29]); /*member-if*/
	if (w==NIL) goto IF4329;
	local[19]= fqv[30];
	ctx->vsp=local+20;
	w=(*ftab[4])(ctx,1,local+19,&ftab[4],fqv[31]); /*break*/
	local[19]= w;
	goto IF4330;
IF4329:
	local[19]= loadglobal(fqv[16]);
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(*ftab[5])(ctx,2,local+19,&ftab[5],fqv[32]); /*collect-instances*/
	local[17] = w;
	local[19]= local[17];
IF4330:
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON4333;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)NCONC(ctx,2,local+19); /*nconc*/
	w = NIL;
	ctx->vsp=local+19;
	local[19]=w;
	goto BLK4324;
	goto CON4332;
CON4333:
	local[19]= local[16];
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
	goto CON4332;
CON4334:
	local[19]= NIL;
CON4332:
	goto WHL4325;
WHX4326:
	local[19]= NIL;
BLK4327:
	local[19]= fqv[33];
	ctx->vsp=local+20;
	w=(pointer)SIGERROR(ctx,1,local+19); /*error*/
	local[19]= w;
BLK4324:
	local[6] = local[14];
	goto WHL4320;
WHX4321:
	local[19]= NIL;
BLK4322:
	w = local[19];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	unbindx(ctx,1);
	w = local[14];
	local[0]= w;
BLK4284:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4319(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4331(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[35]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*remove-inner-loop*/
static pointer F4240(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL4337:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4338;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= NIL;
	local[5]= local[2];
WHL4342:
	if (local[5]==NIL) goto WHX4343;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[3];
	local[7]= local[3];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4348;
	local[6]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4348;
	local[6]= local[4];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,1,local+7,&ftab[7],fqv[37]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4348;
	goto IF4346;
OR4348:
	local[6]= local[3]->c.obj.iv[1];
	local[7]= local[3]->c.obj.iv[2];
	local[8]= local[4]->c.obj.iv[1];
	local[9]= local[4]->c.obj.iv[2];
	local[10]= makeflt(9.99999698e-04);
	ctx->vsp=local+11;
	w=(*ftab[8])(ctx,5,local+6,&ftab[8],fqv[38]); /*line-intersection3*/
	local[6]= w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	if (local[6]==NIL) goto IF4349;
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4349;
	local[9]= local[7];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4349;
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4349;
	local[9]= local[8];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4349;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= local[3];
	local[12]= fqv[39];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= local[7];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,5,local+9); /*list*/
	local[9]= w;
	w = local[0];
	ctx->vsp=local+10;
	local[0] = cons(ctx,local[9],w);
	local[9]= local[3];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
	goto IF4350;
IF4349:
	local[9]= NIL;
IF4350:
	w = local[9];
	local[6]= w;
	goto IF4347;
IF4346:
	local[6]= NIL;
IF4347:
	goto WHL4342;
WHX4343:
	local[6]= NIL;
BLK4344:
	w = NIL;
	goto WHL4337;
WHX4338:
	local[3]= NIL;
BLK4339:
	w = local[3];
	local[2]= NIL;
	local[3]= local[0];
WHL4352:
	if (local[3]==NIL) goto WHX4353;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[4]->c.obj.iv[2];
	local[7]= local[4]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	local[7]= local[5]->c.obj.iv[2];
	local[8]= local[5]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[7]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= NIL;
	local[10]= argv[1];
	local[11]= local[6];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)SCA3PROD(ctx,3,local+10); /*v.**/
	local[10]= w;
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)LESSP(ctx,2,local+10); /*<*/
	if (w==NIL) goto IF4356;
	local[10]= local[5];
	local[11]= local[4];
	local[4] = local[10];
	local[5] = local[11];
	w = NIL;
	local[10]= w;
	goto IF4357;
IF4356:
	local[10]= NIL;
IF4357:
	local[10]= local[4];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	if (local[9]!=NIL) goto IF4360;
	local[9] = argv[0];
	local[10]= local[9];
	goto IF4361;
IF4360:
	local[10]= NIL;
IF4361:
WHL4362:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	if (local[5]==local[10]) goto WHX4363;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[36]); /*member*/
	if (w==NIL) goto IF4365;
	local[10]= fqv[40];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF4366;
IF4365:
	local[10]= NIL;
IF4366:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= argv[0];
	local[12]= fqv[41];
	local[13]= makeint(1);
	ctx->vsp=local+14;
	w=(*ftab[9])(ctx,4,local+10,&ftab[9],fqv[42]); /*delete*/
	argv[0] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	if (local[9]!=NIL) goto IF4367;
	local[9] = argv[0];
	local[10]= local[9];
	goto IF4368;
IF4367:
	local[10]= NIL;
IF4368:
	goto WHL4362;
WHX4363:
	local[10]= NIL;
BLK4364:
	local[10]= local[8];
	local[11]= local[10];
	w = local[4];
	w->c.obj.iv[2] = local[11];
	local[10]= local[8];
	local[11]= local[10];
	w = local[5];
	w->c.obj.iv[1] = local[11];
	w = local[10];
	goto WHL4352;
WHX4353:
	local[4]= NIL;
BLK4354:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK4335:
	ctx->vsp=local; return(local[0]);}

/*project-shadow*/
static pointer F4241(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[1];
	local[7]= fqv[22];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,1,local+7); /*v-*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= local[2];
WHL4371:
	if (local[17]==NIL) goto WHX4372;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[6];
	local[19]= local[16]->c.obj.iv[1];
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	local[19]= makeflt(0.00000000e+00);
	ctx->vsp=local+20;
	w=(*ftab[0])(ctx,2,local+18,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4375;
	local[18]= local[16];
	w = local[0];
	ctx->vsp=local+19;
	local[0] = cons(ctx,local[18],w);
	local[18]= local[0];
	goto IF4376;
IF4375:
	local[18]= local[16];
	w = local[1];
	ctx->vsp=local+19;
	local[1] = cons(ctx,local[18],w);
	local[18]= local[1];
IF4376:
	goto WHL4371;
WHX4372:
	local[18]= NIL;
BLK4373:
	w = NIL;
	local[16]= NIL;
	local[17]= argv[0];
	local[18]= fqv[19];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
WHL4378:
	if (local[17]==NIL) goto WHX4379;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16]->c.obj.iv[3];
	local[19]= local[16]->c.obj.iv[4];
	local[20]= local[18];
	local[21]= local[0];
	ctx->vsp=local+22;
	w=(*ftab[6])(ctx,2,local+20,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= local[19];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= NIL;
	if (local[20]==NIL) goto CON4383;
	if (local[21]!=NIL) goto CON4383;
	local[22] = local[20];
	local[23]= local[22];
	goto CON4382;
CON4383:
	if (local[20]!=NIL) goto CON4384;
	if (local[21]==NIL) goto CON4384;
	local[22] = local[21];
	local[23]= local[22];
	goto CON4382;
CON4384:
	local[22] = NIL;
	local[23]= local[22];
	goto CON4382;
CON4385:
	local[23]= NIL;
CON4382:
	if (local[22]==NIL) goto IF4386;
	local[23]= local[16];
	local[24]= local[22];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,2,local+23); /*list*/
	local[23]= w;
	w = local[3];
	ctx->vsp=local+24;
	local[3] = cons(ctx,local[23],w);
	local[23]= local[3];
	goto IF4387;
IF4386:
	local[23]= NIL;
IF4387:
	w = local[23];
	goto WHL4378;
WHX4379:
	local[18]= NIL;
BLK4380:
	w = NIL;
	local[16]= NIL;
	local[17]= local[3];
WHL4389:
	if (local[17]==NIL) goto WHX4390;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[11];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[12];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= local[18];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[10])(ctx,2,local+20,&ftab[10],fqv[43]); /*assoc*/
	if (w!=NIL) goto IF4393;
	local[20]= local[18];
	local[21]= argv[1];
	local[22]= fqv[23];
	local[23]= local[18];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	w = local[5];
	ctx->vsp=local+21;
	local[5] = cons(ctx,local[20],w);
	local[20]= local[5];
	goto IF4394;
IF4393:
	local[20]= NIL;
IF4394:
	local[20]= local[19];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[10])(ctx,2,local+20,&ftab[10],fqv[43]); /*assoc*/
	if (w!=NIL) goto IF4395;
	local[20]= local[19];
	local[21]= argv[1];
	local[22]= fqv[23];
	local[23]= local[19];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	w = local[5];
	ctx->vsp=local+21;
	local[5] = cons(ctx,local[20],w);
	local[20]= local[5];
	goto IF4396;
IF4395:
	local[20]= NIL;
IF4396:
	w = local[20];
	goto WHL4389;
WHX4390:
	local[18]= NIL;
BLK4391:
	w = NIL;
	local[16]= NIL;
	local[17]= local[3];
WHL4398:
	if (local[17]==NIL) goto WHX4399;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[11];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[12];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= loadglobal(fqv[9]);
	ctx->vsp=local+21;
	w=(pointer)INSTANTIATE(ctx,1,local+20); /*instantiate*/
	local[20]= w;
	local[21]= local[20];
	local[22]= fqv[10];
	local[23]= fqv[11];
	local[24]= local[18];
	local[25]= local[5];
	ctx->vsp=local+26;
	w=(*ftab[10])(ctx,2,local+24,&ftab[10],fqv[43]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	local[25]= fqv[12];
	local[26]= local[19];
	local[27]= local[5];
	ctx->vsp=local+28;
	w=(*ftab[10])(ctx,2,local+26,&ftab[10],fqv[43]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,6,local+21); /*send*/
	w = local[20];
	local[20]= w;
	w = local[8];
	ctx->vsp=local+21;
	local[8] = cons(ctx,local[20],w);
	w = local[8];
	goto WHL4398;
WHX4399:
	local[18]= NIL;
BLK4400:
	w = NIL;
WHL4403:
	if (local[8]==NIL) goto WHX4404;
	local[13] = NIL;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[16];
	local[11] = w;
	local[16]= local[11];
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	local[11] = local[11]->c.obj.iv[2];
WHL4407:
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4410,env,argv,local);
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,2,local+16,&ftab[11],fqv[44]); /*find-if*/
	local[12] = w;
	if (local[12]==NIL) goto WHX4408;
	local[16]= local[12];
	local[17]= local[8];
	local[18]= fqv[41];
	local[19]= makeint(1);
	ctx->vsp=local+20;
	w=(*ftab[9])(ctx,4,local+16,&ftab[9],fqv[42]); /*delete*/
	local[8] = w;
	local[11] = local[12]->c.obj.iv[2];
	local[16]= local[12];
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	goto WHL4407;
WHX4408:
	local[16]= NIL;
BLK4409:
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)NREVERSE(ctx,1,local+16); /*nreverse*/
	local[16]= w;
	w = local[4];
	ctx->vsp=local+17;
	local[4] = cons(ctx,local[16],w);
	goto WHL4403;
WHX4404:
	local[16]= NIL;
BLK4405:
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)NREVERSE(ctx,1,local+16); /*nreverse*/
	local[4] = w;
	local[16]= NIL;
	local[17]= local[4];
WHL4412:
	if (local[17]==NIL) goto WHX4413;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)F4240(ctx,2,local+18); /*remove-inner-loop*/
	local[18]= w;
	w = local[9];
	ctx->vsp=local+19;
	local[9] = cons(ctx,local[18],w);
	goto WHL4412;
WHX4413:
	local[18]= NIL;
BLK4414:
	w = NIL;
	local[4] = local[9];
	local[16]= local[4];
	storeglobal(fqv[45],local[16]);
	local[14] = NIL;
	local[15] = NIL;
	local[16]= NIL;
	local[17]= local[4];
WHL4417:
	if (local[17]==NIL) goto WHX4418;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)F4237(ctx,1,local+18); /*make-face-from-edge-loop*/
	local[18]= w;
	local[19]= local[6];
	local[20]= local[18];
	local[21]= fqv[22];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)VINNERPRODUCT(ctx,2,local+19); /*v.*/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[19]);
	if (left >= right) goto IF4421;}
	local[19]= local[18];
	w = local[15];
	ctx->vsp=local+20;
	local[15] = cons(ctx,local[19],w);
	local[19]= local[15];
	goto IF4422;
IF4421:
	local[19]= local[18];
	ctx->vsp=local+20;
	w=(pointer)F4238(ctx,1,local+19); /*change-to-hole*/
	local[19]= w;
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
IF4422:
	w = local[19];
	goto WHL4417;
WHX4418:
	local[18]= NIL;
BLK4419:
	w = NIL;
	local[16]= NIL;
	local[17]= local[14];
WHL4424:
	if (local[17]==NIL) goto WHX4425;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= NIL;
	local[19]= local[15];
WHL4430:
	if (local[19]==NIL) goto WHX4431;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	w = local[20];
	local[18] = w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO4436,env,argv,local);
	local[21]= local[16];
	local[22]= fqv[17];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[12])(ctx,2,local+20,&ftab[12],fqv[46]); /*every*/
	if (w==NIL) goto IF4434;
	local[20]= local[18];
	local[21]= fqv[47];
	local[22]= local[16];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= local[16];
	local[21]= fqv[48];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	w = NIL;
	ctx->vsp=local+20;
	local[18]=w;
	goto BLK4428;
	goto IF4435;
IF4434:
	local[20]= NIL;
IF4435:
	goto WHL4430;
WHX4431:
	local[20]= NIL;
BLK4432:
	w = NIL;
	local[18]= w;
BLK4428:
	goto WHL4424;
WHX4425:
	local[18]= NIL;
BLK4426:
	w = NIL;
	local[10] = local[15];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)COPYSEQ(ctx,1,local+16); /*copy-seq*/
	local[16]= w;
	storeglobal(fqv[49],w);
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
WHL4437:
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4438;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[21];
	local[17] = w;
	local[16] = NIL;
WHL4442:
	if (local[10]==NIL) goto WHX4443;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[21];
	local[18] = w;
	storeglobal(fqv[26],local[17]);
	local[21]= local[18];
	storeglobal(fqv[27],local[21]);
	local[21]= local[17];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(*ftab[2])(ctx,2,local+21,&ftab[2],fqv[28]); /*face+*/
	local[19] = w;
	ctx->vsp=local+21;
	local[21]= makeclosure(codevec,quotevec,CLO4448,env,argv,local);
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[3])(ctx,2,local+21,&ftab[3],fqv[29]); /*member-if*/
	if (w==NIL) goto IF4446;
	local[21]= fqv[50];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[31]); /*break*/
	local[21]= w;
	goto IF4447;
IF4446:
	local[21]= loadglobal(fqv[16]);
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[5])(ctx,2,local+21,&ftab[5],fqv[32]); /*collect-instances*/
	local[19] = w;
	local[21]= local[19];
IF4447:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON4450;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	local[22]= local[10];
	ctx->vsp=local+23;
	w=(pointer)NCONC(ctx,2,local+21); /*nconc*/
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK4441;
	goto CON4449;
CON4450:
	local[21]= local[18];
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	goto CON4449;
CON4451:
	local[21]= NIL;
CON4449:
	goto WHL4442;
WHX4443:
	local[21]= NIL;
BLK4444:
	local[21]= fqv[51];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
BLK4441:
	local[10] = local[16];
	goto WHL4437;
WHX4438:
	local[21]= NIL;
BLK4439:
	w = local[21];
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK4369:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4410(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	w = ((env->c.clo.env2[11])==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4436(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[18];
	local[1]= fqv[52];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4448(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[35]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*shadow-intersection*/
static pointer F4242(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F4241(ctx,2,local+0); /*project-shadow*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F4241(ctx,2,local+1); /*project-shadow*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[54]); /*face**/
	local[0]= w;
BLK4452:
	ctx->vsp=local; return(local[0]);}

/*closest-shadow*/
static pointer F4243(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[55];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[1];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,1,local+3); /*v-*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= NIL;
	w = NIL;
	local[0]= w;
BLK4453:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___shadow(ctx,n,argv,env)
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
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4454;
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[59],w);
	goto IF4455;
IF4454:
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4455:
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[62],module,F4244,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F4233,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F4234,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F4235,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F4236,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F4237,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F4238,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F4239,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F4240,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F4241,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F4242,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F4243,fqv[85]);
	local[0]= fqv[86];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[88]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<15; i++) ftab[i]=fcallx;
}
