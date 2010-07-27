/* mathtran.c :  entry=mathtran */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "mathtran.h"
#pragma init (register_mathtran)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___mathtran();
extern pointer build_quote_vector();
static register_mathtran()
  { add_module_initializer("___mathtran", ___mathtran);}

static pointer F66464();
static pointer F66465();
static pointer F66466();

/*expression*/
static pointer F66464(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT66488;}
	local[0]= NIL;
ENT66488:
ENT66487:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,FLET66510,env,argv,local);
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,FLET66512,env,argv,local);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,FLET66514,env,argv,local);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,FLET66516,env,argv,local);
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,FLET66518,env,argv,local);
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,FLET66520,env,argv,local);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,FLET66522,env,argv,local);
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,FLET66524,env,argv,local);
	local[12]= argv[0];
	w = local[10];
	ctx->vsp=local+13;
	w=FLET66522(ctx,1,local+12,w);
	local[12]= w;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	if (argv[0]==NIL) goto IF66570;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)SIGERROR(ctx,1,local+12); /*error*/
	local[12]= w;
	goto IF66571;
IF66570:
	local[12]= NIL;
IF66571:
	local[12]= local[2];
	w = local[11];
	ctx->vsp=local+13;
	w=FLET66524(ctx,1,local+12,w);
	local[0]= w;
BLK66485:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66510(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	local[2]= fqv[1];
	local[3]= (pointer)get_sym_func(fqv[2]);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[3]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto CON66615;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (pointer)((integer_t)((w)->c.cons.car)+4);
	ctx->vsp=local+3;
	w=(pointer)RPLACA2(ctx,2,local+1); /*rplaca2*/
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON66613;
CON66615:
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	w = env->c.clo.env2[3];
	ctx->vsp=local+2;
	env->c.clo.env2[3] = cons(ctx,local[1],w);
	local[1]= local[0];
	goto CON66613;
CON66650:
	local[1]= NIL;
CON66613:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	w = local[0];
	if (!iscons(w)) goto CON66739;
	local[3]= local[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET66518(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	if (local[2]==NIL) goto IF66787;
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF66788;
IF66787:
	local[3]= NIL;
IF66788:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON66737;
CON66739:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto CON66800;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[6]!=local[3]) goto CON66854;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[9];
	ctx->vsp=local+4;
	w=FLET66520(ctx,1,local+3,w);
	local[1] = w;
	local[3]= fqv[6];
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	if (env->c.clo.env2[0]!=NIL) goto IF66900;
	local[3]= local[2];
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET66510(ctx,1,local+3,w);
	local[2] = w;
	local[3]= local[2];
	goto IF66901;
IF66900:
	local[3]= NIL;
IF66901:
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON66852;
CON66854:
	local[3]= local[0];
	local[4]= local[1];
	w = env->c.clo.env2[9];
	ctx->vsp=local+5;
	w=FLET66520(ctx,1,local+4,w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET66510(ctx,1,local+3,w);
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON66852;
CON66924:
	local[3]= NIL;
CON66852:
	goto CON66737;
CON66800:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON66737;
CON66942:
	local[3]= NIL;
CON66737:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66514(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[5];
	ctx->vsp=local+4;
	w=FLET66512(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[7]!=local[3]) goto CON67017;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[5];
	ctx->vsp=local+4;
	w=FLET66512(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w = local[1];
	w = local[1];
	if (!isint(w)) goto CON67077;
	local[3]= local[1];
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto CON67077;
	local[3]= fqv[8];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[2] = w;
	w = local[0];
	if (!!iscons(w)) goto CON67100;
	local[3]= makeint(0);
	local[4]= local[1];
WHL67129:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX67130;
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL67129;
WHX67130:
	local[5]= NIL;
BLK67131:
	w = NIL;
	local[3]= local[2];
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET66510(ctx,1,local+3,w);
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67098;
CON67100:
	local[3]= makeint(0);
	local[4]= local[1];
WHL67192:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX67193;
	local[5]= local[2];
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL67192;
WHX67193:
	local[5]= NIL;
BLK67194:
	w = NIL;
	local[3]= fqv[10];
	local[4]= fqv[9];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67098;
CON67165:
	local[3]= NIL;
CON67098:
	goto CON67075;
CON67077:
	local[3]= fqv[11];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67075;
CON67243:
	local[3]= NIL;
CON67075:
	goto CON67015;
CON67017:
	w = local[0];
	if (!isnum(w)) goto CON67255;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67015;
CON67255:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67015;
CON67264:
	local[3]= NIL;
CON67015:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66516(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[6];
	ctx->vsp=local+4;
	w=FLET66514(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= local[1];
	w = fqv[12];
	if (memq(local[3],w)==NIL) goto CON67351;
WHL67362:
	local[3]= local[1];
	w = fqv[13];
	if (memq(local[3],w)==NIL) goto WHX67363;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0] = w;
WHL67386:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (local[1]!=local[3]) goto WHX67387;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[6];
	ctx->vsp=local+4;
	w=FLET66514(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL67386;
WHX67387:
	local[3]= NIL;
BLK67388:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	goto WHL67362;
WHX67363:
	local[3]= NIL;
BLK67364:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67349;
CON67351:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON67349;
CON67467:
	local[3]= NIL;
CON67349:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66518(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
	w = fqv[14];
	if (memq(local[3],w)==NIL) goto IF67503;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[3]= argv[0];
	goto IF67504;
IF67503:
	local[3]= NIL;
IF67504:
	local[3]= argv[0];
	w = env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET66516(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w = local[1];
	local[3]= local[0];
	if (fqv[15]!=local[3]) goto IF67568;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
	local[3]= local[1];
	goto IF67569;
IF67568:
	local[3]= NIL;
IF67569:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w = fqv[16];
	if (memq(local[3],w)==NIL) goto IF67588;
	local[3]= fqv[17];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
WHL67618:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	local[3]= local[0];
	w = fqv[18];
	if (memq(local[3],w)==NIL) goto WHX67619;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET66516(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[0];
	if (fqv[15]!=local[3]) goto IF67687;
	local[3]= fqv[15];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF67688;
IF67687:
	local[3]= NIL;
IF67688:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL67618;
WHX67619:
	local[3]= NIL;
BLK67620:
	goto IF67589;
IF67588:
	local[3]= NIL;
IF67589:
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66520(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL67740:
	if (argv[0]==NIL) goto WHX67741;
	local[2]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+3;
	w=FLET66518(ctx,1,local+2,w);
	local[2]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL67740;
WHX67741:
	local[2]= NIL;
BLK67742:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66522(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET66518(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	w = fqv[19];
	if (memq(local[3],w)==NIL) goto IF67917;
	local[3]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET66518(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[1];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[3]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[0] = w;
	local[3]= local[0];
	goto IF67918;
IF67917:
	local[3]= NIL;
IF67918:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET66524(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[0] = w;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= env->c.clo.env2[3];
WHL68047:
	if (local[2]==NIL) goto WHX68048;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF68096;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF68097;
IF68096:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)NSUBST(ctx,3,local+3); /*nsubst*/
	local[3]= w;
IF68097:
	goto WHL68047;
WHX68048:
	local[3]= NIL;
BLK68049:
	w = NIL;
	if (local[0]==NIL) goto IF68153;
	local[1]= fqv[21];
	local[2]= local[0];
	w = argv[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF68154;
IF68153:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
IF68154:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*infix2prefix*/
static pointer F66465(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT68179;}
	local[0]= NIL;
ENT68179:
ENT68178:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	w = local[1];
	if (!issymbol(w)) goto CON68208;
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)F66464(ctx,2,local+2); /*expression*/
	local[2]= w;
	goto CON68206;
CON68208:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[22]!=local[2]) goto CON68221;
	local[2]= fqv[23];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)F66464(ctx,2,local+4); /*expression*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON68206;
CON68221:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[22]!=local[2]) goto CON68252;
	local[2]= fqv[24];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)F66464(ctx,2,local+3); /*expression*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[25]); /*cdddr*/
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)F66464(ctx,2,local+4); /*expression*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON68206;
CON68252:
	local[2]= local[1];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)F66464(ctx,2,local+2); /*expression*/
	local[2]= w;
	goto CON68206;
CON68293:
	local[2]= NIL;
CON68206:
	w = local[2];
	local[0]= w;
BLK68176:
	ctx->vsp=local; return(local[0]);}

/*read-aref*/
static pointer F66466(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT68305;}
	local[0]= NIL;
ENT68305:
ENT68304:
	if (n>2) maerror();
	local[1]= fqv[6];
	local[2]= makeint(93);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[26]); /*read-delimited-list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK68302:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___mathtran(ctx,n,argv,env)
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
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF68337;
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[29],w);
	goto IF68338;
IF68337:
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF68338:
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F66464,fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F66465,fqv[34]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[35],module,F66466,fqv[36]);
	local[0]= makeint(37);
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint(91);
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint(93);
	local[1]= makeint(41);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[37]); /*set-syntax-from-char*/
	local[0]= fqv[38];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[40]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<6; i++) ftab[i]=fcallx;
}
