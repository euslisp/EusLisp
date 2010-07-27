/* primt.c :  entry=primt */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "primt.h"
#pragma init (register_primt)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___primt();
extern pointer build_quote_vector();
static register_primt()
  { add_module_initializer("___primt", ___primt);}

static pointer F2020();
static pointer F2021();
static pointer F2022();
static pointer F2023();
static pointer F2024();
static pointer F2025();
static pointer F2026();
static pointer F2027();
static pointer F2028();
static pointer F2029();
static pointer F2030();
static pointer F2031();
static pointer F2032();
static pointer F2033();
static pointer F2034();
static pointer F2035();
static pointer F2036();
static pointer F2037();
static pointer F2038();
static pointer F2039();
static pointer F2040();
static pointer F2041();
static pointer F2042();
static pointer F2043();
static pointer F2044();
static pointer F2045();
static pointer F2046();
static pointer F2047();
static pointer F2048();
static pointer F2049();
static pointer F2050();
static pointer F2051();
static pointer F2052();
static pointer F2053();

/*find-extream*/
static pointer F2020(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	local[1]= w;
	local[2]= NIL;
	local[3]= argv[0];
WHL2057:
	if (local[3]==NIL) goto WHX2058;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[2];
	local[5]= argv[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,2,local+5); /*funcall*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,3,local+4); /*funcall*/
	if (w==NIL) goto IF2061;
	local[0] = local[2];
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,2,local+4); /*funcall*/
	local[1] = w;
	local[4]= local[1];
	goto IF2062;
IF2061:
	local[4]= NIL;
IF2062:
	goto WHL2057;
WHX2058:
	local[4]= NIL;
BLK2059:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2054:
	ctx->vsp=local; return(local[0]);}

/*leftmost-point*/
static pointer F2021(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2064,env,argv,local);
	local[2]= (pointer)get_sym_func(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)F2020(ctx,3,local+0); /*find-extream*/
	local[0]= w;
BLK2063:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2064(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*rightmost-point*/
static pointer F2022(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2066,env,argv,local);
	local[2]= (pointer)get_sym_func(fqv[2]);
	ctx->vsp=local+3;
	w=(pointer)F2020(ctx,3,local+0); /*find-extream*/
	local[0]= w;
BLK2065:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2066(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*left-points*/
static pointer F2023(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2068,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2067:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2068(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[1];
	local[1]= argv[0];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2069;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2070;
IF2069:
	local[0]= NIL;
IF2070:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*right-points*/
static pointer F2024(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2072,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2071:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2072(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[1];
	local[1]= argv[0];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF2073;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2074;
IF2073:
	local[0]= NIL;
IF2074:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*quickhull-left*/
static pointer F2025(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]!=NIL) goto CON2077;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2075;
	goto CON2076;
CON2077:
	local[0]= NIL;
CON2076:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F2021(ctx,4,local+0); /*leftmost-point*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F2023(ctx,4,local+1); /*left-points*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)F2023(ctx,4,local+2); /*left-points*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[1];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)F2025(ctx,4,local+4); /*quickhull-left*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[0];
	local[8]= argv[2];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)F2025(ctx,4,local+6); /*quickhull-left*/
	local[6]= w;
	local[7]= fqv[3];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,4,local+5,&ftab[1],fqv[4]); /*delete*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[3] = w;
	w = local[3];
	local[0]= w;
BLK2075:
	ctx->vsp=local; return(local[0]);}

/*quickhull-right*/
static pointer F2026(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]!=NIL) goto CON2080;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2078;
	goto CON2079;
CON2080:
	local[0]= NIL;
CON2079:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F2022(ctx,4,local+0); /*rightmost-point*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F2024(ctx,4,local+1); /*right-points*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)F2024(ctx,4,local+2); /*right-points*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[0];
	local[7]= argv[2];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)F2026(ctx,4,local+5); /*quickhull-right*/
	local[5]= w;
	local[6]= fqv[3];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,4,local+4,&ftab[1],fqv[4]); /*delete*/
	local[4]= w;
	local[5]= local[1];
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)F2026(ctx,4,local+5); /*quickhull-right*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[3] = w;
	w = local[3];
	local[0]= w;
BLK2078:
	ctx->vsp=local; return(local[0]);}

/*quickhull*/
static pointer F2027(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2083;}
	local[0]= fqv[5];
ENT2083:
ENT2082:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= local[0];
	{ register integer_t i=intval(makeint(0));
	  w=makeflt(local[6]->c.fvec.fv[i]);}
	local[6]= makeflt((double)fabs(fltval(w)));
	local[7]= local[0];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[7]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[6]);
	if (left <= right) goto IF2084;}
	local[5] = makeint(1);
	local[6]= local[5];
	goto IF2085;
IF2084:
	local[6]= NIL;
IF2085:
	local[6]= argv[0];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO2086,env,argv,local);
	local[8]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+9;
	w=(pointer)F2020(ctx,3,local+6); /*find-extream*/
	local[1] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO2087,env,argv,local);
	local[8]= (pointer)get_sym_func(fqv[7]);
	ctx->vsp=local+9;
	w=(pointer)F2020(ctx,3,local+6); /*find-extream*/
	local[2] = w;
	local[6]= argv[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2023(ctx,4,local+6); /*left-points*/
	local[6]= w;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2025(ctx,4,local+6); /*quickhull-left*/
	local[3] = w;
	local[6]= argv[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2024(ctx,4,local+6); /*right-points*/
	local[6]= w;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2026(ctx,4,local+6); /*quickhull-right*/
	local[4] = w;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= fqv[3];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,4,local+6,&ftab[1],fqv[4]); /*delete*/
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	local[8]= fqv[3];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,4,local+6,&ftab[1],fqv[4]); /*delete*/
	local[4] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[0]= w;
BLK2081:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2086(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[5];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2087(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[5];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-coplanar-vertices*/
static pointer F2028(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,3,local+0,&ftab[2],fqv[8]); /*triangle-normal*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt(-(fltval(w)));
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2089,env,argv,local);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)MAPCAN(ctx,2,local+2); /*mapcan*/
	local[0]= w;
BLK2088:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2089(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[0];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2090;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2091;
IF2090:
	local[0]= NIL;
IF2091:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*colinear-p*/
static pointer F2029(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2094;}
	local[0]= loadglobal(fqv[9]);
ENT2094:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[10],w);
ENT2093:
	if (n>4) maerror();
	local[3]= argv[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	local[5]= w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	local[6]= w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAX(ctx,2,local+6); /*max*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[5];
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,2,local+6,&ftab[3],fqv[11]); /*eps=*/
	if (w==NIL) goto IF2095;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VINNERPRODUCT(ctx,2,local+6); /*v.*/
	local[6]= w;
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)VINNERPRODUCT(ctx,2,local+7); /*v.*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	goto IF2096;
IF2095:
	local[6]= NIL;
IF2096:
	w = local[6];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2092:
	ctx->vsp=local; return(local[0]);}

/*find-colinear-points*/
static pointer F2030(ctx,n,argv,env)
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
	local[5]= NIL;
WHL2098:
	if (argv[0]==NIL) goto WHX2099;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[6];
	local[0] = w;
	local[3] = argv[0];
WHL2102:
	if (local[3]==NIL) goto WHX2103;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[6];
	local[1] = w;
	local[6]= NIL;
	local[7]= local[3];
WHL2107:
	if (local[7]==NIL) goto WHX2108;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)F2029(ctx,3,local+8); /*colinear-p*/
	local[4] = w;
	if (local[4]==NIL) goto IF2111;
	local[8]= local[4];
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2114;
	local[8]= local[0];
	goto CON2113;
CON2114:
	local[8]= local[4];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2115;
	local[8]= local[1];
	goto CON2113;
CON2115:
	local[8]= local[6];
	goto CON2113;
CON2116:
	local[8]= NIL;
CON2113:
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2112;
IF2111:
	local[8]= NIL;
IF2112:
	goto WHL2107;
WHX2108:
	local[8]= NIL;
BLK2109:
	w = NIL;
	goto WHL2102;
WHX2103:
	local[6]= NIL;
BLK2104:
	goto WHL2098;
WHX2099:
	local[6]= NIL;
BLK2100:
	w = local[5];
	local[0]= w;
BLK2097:
	ctx->vsp=local; return(local[0]);}

/*remove-colinears-from-circuit*/
static pointer F2031(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	w = makeint(3);
	if ((integer_t)local[0] > (integer_t)w) goto CON2119;
	local[0]= argv[0];
	goto CON2118;
CON2119:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F2029(ctx,3,local+0); /*colinear-p*/
	if (w==NIL) goto CON2120;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F2031(ctx,1,local+1); /*remove-colinears-from-circuit*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON2118;
CON2120:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F2031(ctx,1,local+1); /*remove-colinears-from-circuit*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON2118;
CON2121:
	local[0]= NIL;
CON2118:
	w = local[0];
	local[0]= w;
BLK2117:
	ctx->vsp=local; return(local[0]);}

/*coplanar-p*/
static pointer F2032(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2124;}
	local[0]= loadglobal(fqv[9]);
ENT2124:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[10],w);
ENT2123:
	if (n>5) maerror();
	local[3]= argv[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)VINNERPRODUCT(ctx,2,local+7); /*v.*/
	local[7]= w;
	local[8]= makeflt(0.00000000e+00);
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,2,local+7,&ftab[3],fqv[11]); /*eps=*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2122:
	ctx->vsp=local; return(local[0]);}

/*gift-wrapping*/
static pointer F2033(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= loadglobal(fqv[13]);
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[4];
WHL2127:
	if (local[8]==NIL) goto WHX2128;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w = local[1];
	if (memq(local[9],w)!=NIL) goto IF2131;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= argv[1];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,3,local+9); /*v-*/
	local[9]= local[4];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[5] = w;
	local[9]= local[4];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[6] = w;
	local[9]= local[5];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[0] = w;
	local[9]= local[0];
	if (loadglobal(fqv[14])!=local[9]) goto IF2133;
	local[9]= T;
	local[10]= fqv[15];
	local[11]= local[0];
	local[12]= local[4];
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[5];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,7,local+9); /*format*/
	w = fqv[16];
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK2125;
	goto IF2134;
IF2133:
	local[9]= NIL;
IF2134:
	local[9]= local[0];
	local[10]= loadglobal(fqv[13]);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w!=NIL) goto IF2135;
	local[9]= local[0];
	{ double left,right;
		right=fltval(local[3]); left=fltval(local[9]);
	if (left < right) goto IF2135;}
	local[2] = local[7];
	local[3] = local[0];
	local[9]= local[3];
	goto IF2136;
IF2135:
	local[9]= NIL;
IF2136:
	goto IF2132;
IF2131:
	local[9]= NIL;
IF2132:
	goto WHL2127;
WHX2128:
	local[9]= NIL;
BLK2129:
	w = NIL;
	local[7]= local[3];
	storeglobal(fqv[17],local[7]);
	w = local[2];
	local[0]= w;
BLK2125:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-vertices*/
static pointer F2034(ctx,n,argv,env)
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
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[19]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= NIL;
	local[7]= argv[0];
WHL2139:
	if (local[7]==NIL) goto WHX2140;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[20]); /*intersection*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	if (local[2]!=NIL) goto CON2144;
	local[8]= loadglobal(fqv[21]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[2] = w;
	local[8]= local[2];
	local[9]= fqv[22];
	local[10]= fqv[23];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[24];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[25];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,8,local+8); /*send*/
	local[8]= local[5];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= local[6];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= w;
	goto CON2143;
CON2144:
	if (local[2]==NIL) goto CON2145;
	local[8]= local[2];
	local[9]= fqv[26];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	local[8]= w;
	goto CON2143;
CON2145:
	local[8]= NIL;
CON2143:
	local[8]= local[2];
	w = local[1];
	ctx->vsp=local+9;
	local[1] = cons(ctx,local[8],w);
	local[5] = local[6];
	goto WHL2139;
WHX2140:
	local[8]= NIL;
BLK2141:
	w = NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= local[0];
	local[7]= fqv[22];
	local[8]= fqv[27];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = local[0];
	local[0]= w;
BLK2137:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-coplanar-vertices*/
static pointer F2035(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,3,local+0,&ftab[2],fqv[8]); /*triangle-normal*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F2028(ctx,4,local+1); /*find-coplanar-vertices*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	w = makeint(3);
	if ((integer_t)local[6] <= (integer_t)w) goto CON2148;
	local[6]= (pointer)get_sym_func(fqv[28]);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[2] = w;
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F2027(ctx,2,local+6); /*quickhull*/
	local[3] = w;
	local[6]= local[3];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	local[3] = w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F2031(ctx,1,local+6); /*remove-colinears-from-circuit*/
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[6]= NIL;
	local[7]= local[1];
WHL2150:
	if (local[7]==NIL) goto WHX2151;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w = local[3];
	if (memq(local[8],w)!=NIL) goto IF2154;
	local[8]= local[6];
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2155;
IF2154:
	local[8]= NIL;
IF2155:
	goto WHL2150;
WHX2151:
	local[8]= NIL;
BLK2152:
	w = NIL;
	if (local[5]==NIL) goto IF2156;
	local[6]= NIL;
	local[7]= local[5];
WHL2159:
	if (local[7]==NIL) goto WHX2160;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= T;
	local[9]= fqv[29];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w = loadglobal(fqv[30]);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	storeglobal(fqv[30],local[8]);
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2163;
	local[8]= local[6];
	local[9]= loadglobal(fqv[31]);
	local[10]= fqv[3];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(*ftab[1])(ctx,4,local+8,&ftab[1],fqv[4]); /*delete*/
	local[8]= w;
	storeglobal(fqv[31],w);
	goto IF2164;
IF2163:
	local[8]= NIL;
IF2164:
	goto WHL2159;
WHX2160:
	local[8]= NIL;
BLK2161:
	w = NIL;
	local[6]= w;
	goto IF2157;
IF2156:
	local[6]= NIL;
IF2157:
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO2165,env,argv,local);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MAPCAN(ctx,2,local+6); /*mapcan*/
	local[4] = w;
	local[6]= local[4];
	goto CON2147;
CON2148:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[4] = w;
	local[6]= local[4];
	goto CON2147;
CON2166:
	local[6]= NIL;
CON2147:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)F2034(ctx,1,local+6); /*make-face-from-vertices*/
	local[0]= w;
BLK2146:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2165(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-initial-hull*/
static pointer F2036(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2168,env,argv,local);
	local[2]= (pointer)get_sym_func(fqv[7]);
	ctx->vsp=local+3;
	w=(pointer)F2020(ctx,3,local+0); /*find-extream*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[18]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= makeflt(0.00000000e+00);
	local[11]= makeflt(0.00000000e+00);
	local[12]= makeflt(1.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= w;
	*(ovafptr(local[9],fqv[32])) = local[12];
WHL2169:
	local[11]= local[9];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[10];
	local[14]= makeflt(1.00000000e+00);
	ctx->vsp=local+15;
	w=(pointer)RANDOM(ctx,1,local+14); /*random*/
	local[14]= w;
	local[15]= makeflt(1.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)RANDOM(ctx,1,local+15); /*random*/
	local[15]= w;
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)F2033(ctx,5,local+11); /*gift-wrapping*/
	local[1] = w;
	local[11]= local[1];
	if (fqv[16]!=local[11]) goto WHX2170;
	goto WHL2169;
WHX2170:
	local[11]= NIL;
BLK2171:
	local[5] = loadglobal(fqv[17]);
	if (loadglobal(fqv[33])==NIL) goto IF2172;
	local[11]= T;
	local[12]= fqv[34];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,5,local+11); /*format*/
	local[11]= w;
	goto IF2173;
IF2172:
	local[11]= NIL;
IF2173:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[4] = w;
	local[11]= local[10];
	local[12]= makeint(1);
	local[13]= local[4];
	{ register integer_t i=intval(makeint(2));
	  w=makeflt(local[13]->c.fvec.fv[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.fvec.fv[i]=fltval(w);}
	local[11]= local[10];
	local[12]= makeint(2);
	local[13]= local[4];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[13]->c.fvec.fv[i]);}
	w = makeflt(-(fltval(w)));
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.fvec.fv[i]=fltval(w);}
	local[11]= local[10];
	{ register integer_t i=intval(makeint(2));
	  w=makeflt(local[11]->c.fvec.fv[i]);}
	local[11]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[11]);
	if (left >= right) goto IF2174;}
	local[11]= local[10];
	local[12]= makeint(1);
	local[13]= local[4];
	{ register integer_t i=intval(makeint(2));
	  w=makeflt(local[13]->c.fvec.fv[i]);}
	w = makeflt(-(fltval(w)));
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.fvec.fv[i]=fltval(w);}
	local[11]= local[10];
	local[12]= makeint(2);
	local[13]= local[4];
	{ register integer_t i=intval(makeint(1));
	  w=makeflt(local[13]->c.fvec.fv[i]);}
	{ register integer_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.fvec.fv[i]=fltval(w);}
	local[11]= w;
	goto IF2175;
IF2174:
	local[11]= NIL;
IF2175:
	local[11]= local[10];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)VNORMALIZE(ctx,2,local+11); /*normalize-vector*/
	local[11]= local[4];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+11); /*v**/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VNORMALIZE(ctx,1,local+11); /*normalize-vector*/
	local[8] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[11]= w;
	*(ovafptr(local[9],fqv[32])) = local[11];
	local[11]= local[9];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[10];
	local[14]= local[8];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)F2033(ctx,5,local+11); /*gift-wrapping*/
	local[2] = w;
	local[6] = loadglobal(fqv[17]);
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,1,local+11); /*v-*/
	local[8] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	*(ovafptr(local[9],fqv[32])) = local[11];
	local[11]= local[9];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[10];
	local[14]= local[8];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)F2033(ctx,5,local+11); /*gift-wrapping*/
	local[3] = w;
	local[7] = loadglobal(fqv[17]);
	local[11]= local[7];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)GREATERP(ctx,2,local+11); /*>*/
	if (w==NIL) goto IF2176;
	local[2] = local[3];
	local[11]= local[2];
	goto IF2177;
IF2176:
	local[11]= NIL;
IF2177:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,3,local+11,&ftab[0],fqv[1]); /*triangle*/
	local[11]= w;
	local[12]= makeflt(0.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF2178;
	local[4] = local[1];
	local[1] = local[2];
	local[2] = local[4];
	local[11]= local[2];
	goto IF2179;
IF2178:
	local[11]= NIL;
IF2179:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,3,local+11,&ftab[2],fqv[8]); /*triangle-normal*/
	local[11]= w;
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	local[12]= makeflt(0.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF2180;
	local[11]= fqv[35];
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,1,local+11); /*error*/
	local[11]= w;
	goto IF2181;
IF2180:
	local[11]= NIL;
IF2181:
	if (loadglobal(fqv[33])==NIL) goto IF2182;
	local[11]= T;
	local[12]= fqv[36];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
	goto IF2183;
IF2182:
	local[11]= NIL;
IF2183:
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)F2035(ctx,4,local+11); /*make-face-from-coplanar-vertices*/
	local[0]= w;
BLK2167:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2168(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*convex-hull-3d*/
static pointer F2037(ctx,n,argv,env)
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
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	storeglobal(fqv[37],argv[0]);
	local[15]= (pointer)get_sym_func(fqv[38]);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(pointer)MAPCAR(ctx,2,local+15); /*mapcar*/
	storeglobal(fqv[31],w);
	storeglobal(fqv[39],NIL);
	storeglobal(fqv[30],NIL);
	local[15]= loadglobal(fqv[31]);
	ctx->vsp=local+16;
	w=(pointer)F2036(ctx,1,local+15); /*find-initial-hull*/
	local[0] = w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	storeglobal(fqv[40],w);
	local[15]= local[0];
	local[16]= fqv[27];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)COPYSEQ(ctx,1,local+15); /*copy-seq*/
	local[14] = w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	local[13] = w;
	local[15]= NIL;
	local[16]= loadglobal(fqv[37]);
WHL2186:
	if (local[16]==NIL) goto WHX2187;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16] = (w)->c.cons.cdr;
	w = local[17];
	local[15] = w;
	local[17]= local[0];
	local[18]= fqv[41];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[17]= w;
	local[18]= makeflt(9.99999756e-05);
	ctx->vsp=local+19;
	w=(pointer)GREATERP(ctx,2,local+17); /*>*/
	if (w==NIL) goto IF2190;
	local[17]= loadglobal(fqv[42]);
	local[18]= fqv[43];
	local[19]= local[15];
	local[20]= local[0];
	local[21]= fqv[41];
	local[22]= local[15];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)XFORMAT(ctx,4,local+17); /*format*/
	local[17]= local[15];
	local[18]= loadglobal(fqv[37]);
	local[19]= fqv[3];
	local[20]= makeint(1);
	ctx->vsp=local+21;
	w=(*ftab[6])(ctx,4,local+17,&ftab[6],fqv[44]); /*remove*/
	local[17]= w;
	storeglobal(fqv[37],w);
	goto IF2191;
IF2190:
	local[17]= NIL;
IF2191:
	goto WHL2186;
WHX2187:
	local[17]= NIL;
BLK2188:
	w = NIL;
WHL2192:
	if (local[13]==NIL) goto WHX2193;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[15];
	local[0] = w;
	local[15]= NIL;
	local[16]= local[0];
	local[17]= fqv[27];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
WHL2197:
	if (local[16]==NIL) goto WHX2198;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16] = (w)->c.cons.cdr;
	w = local[17];
	local[15] = w;
	local[17]= local[15];
	w = local[14];
	if (memq(local[17],w)==NIL) goto CON2202;
	local[17]= local[15];
	local[18]= fqv[23];
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[17]= w;
	local[18]= loadglobal(fqv[31]);
	ctx->vsp=local+19;
	w=(pointer)ASSQ(ctx,2,local+17); /*assq*/
	local[6] = w;
	local[17]= local[15];
	local[18]= fqv[24];
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[17]= w;
	local[18]= loadglobal(fqv[31]);
	ctx->vsp=local+19;
	w=(pointer)ASSQ(ctx,2,local+17); /*assq*/
	local[7] = w;
	if (local[6]==NIL) goto OR2205;
	if (local[7]==NIL) goto OR2205;
	goto IF2203;
OR2205:
	storeglobal(fqv[45],local[15]);
	local[17]= local[0];
	storeglobal(fqv[46],local[17]);
	local[17]= fqv[47];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,1,local+17); /*error*/
	local[17]= w;
	goto IF2204;
IF2203:
	local[17]= NIL;
IF2204:
	local[17]= local[0];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= local[0];
	local[20]= fqv[48];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	local[20]= local[15];
	local[21]= fqv[49];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	local[21]= loadglobal(fqv[31]);
	ctx->vsp=local+22;
	w=(pointer)F2033(ctx,5,local+17); /*gift-wrapping*/
	local[8] = w;
	local[17]= local[0];
	local[18]= fqv[48];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(*ftab[2])(ctx,3,local+18,&ftab[2],fqv[8]); /*triangle-normal*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+17); /*v**/
	local[17]= w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	ctx->vsp=local+20;
	w=(pointer)VMINUS(ctx,2,local+18); /*v-*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)VINNERPRODUCT(ctx,2,local+17); /*v.*/
	local[17]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[17]);
	if (left >= right) goto IF2206;}
	local[9] = local[7];
	local[7] = local[8];
	local[8] = local[9];
	local[17]= local[8];
	goto IF2207;
IF2206:
	local[17]= NIL;
IF2207:
	local[17]= local[6];
	local[18]= local[7];
	local[19]= local[8];
	local[20]= loadglobal(fqv[31]);
	ctx->vsp=local+21;
	w=(pointer)F2035(ctx,4,local+17); /*make-face-from-coplanar-vertices*/
	local[11] = w;
	local[17]= local[11];
	local[18]= fqv[27];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[10] = w;
	local[17]= NIL;
	local[18]= local[10];
WHL2209:
	if (local[18]==NIL) goto WHX2210;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	w = local[14];
	if (memq(local[19],w)==NIL) goto IF2213;
	local[19]= local[17];
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(*ftab[1])(ctx,2,local+19,&ftab[1],fqv[4]); /*delete*/
	local[14] = w;
	local[19]= local[14];
	goto IF2214;
IF2213:
	local[19]= local[17];
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
IF2214:
	goto WHL2209;
WHX2210:
	local[19]= NIL;
BLK2211:
	w = NIL;
	local[17]= local[11];
	w = local[13];
	ctx->vsp=local+18;
	local[13] = cons(ctx,local[17],w);
	local[17]= loadglobal(fqv[40]);
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)NCONC(ctx,2,local+17); /*nconc*/
	if (loadglobal(fqv[33])==NIL) goto IF2215;
	local[17]= loadglobal(fqv[40]);
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)PRINT(ctx,1,local+17); /*print*/
	local[17]= w;
	goto IF2216;
IF2215:
	local[17]= NIL;
IF2216:
	goto CON2201;
CON2202:
	local[17]= NIL;
CON2201:
	goto WHL2197;
WHX2198:
	local[17]= NIL;
BLK2199:
	w = NIL;
	goto WHL2192;
WHX2193:
	local[15]= NIL;
BLK2194:
	local[15]= (pointer)get_sym_func(fqv[50]);
	local[16]= loadglobal(fqv[40]);
	local[17]= fqv[27];
	ctx->vsp=local+18;
	w=(*ftab[7])(ctx,2,local+16,&ftab[7],fqv[51]); /*send-all*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,2,local+15); /*apply*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,1,local+15,&ftab[8],fqv[52]); /*remove-duplicates*/
	local[15]= w;
	storeglobal(fqv[53],w);
	local[15]= (pointer)get_sym_func(fqv[50]);
	local[16]= loadglobal(fqv[40]);
	local[17]= fqv[12];
	ctx->vsp=local+18;
	w=(*ftab[7])(ctx,2,local+16,&ftab[7],fqv[51]); /*send-all*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,2,local+15); /*apply*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,1,local+15,&ftab[8],fqv[52]); /*remove-duplicates*/
	local[15]= w;
	storeglobal(fqv[31],w);
	local[15]= loadglobal(fqv[54]);
	ctx->vsp=local+16;
	w=(pointer)INSTANTIATE(ctx,1,local+15); /*instantiate*/
	local[15]= w;
	local[16]= local[15];
	local[17]= fqv[22];
	local[18]= fqv[55];
	local[19]= loadglobal(fqv[40]);
	local[20]= fqv[27];
	local[21]= loadglobal(fqv[53]);
	local[22]= fqv[12];
	local[23]= loadglobal(fqv[31]);
	local[24]= fqv[56];
	local[25]= fqv[57];
	local[26]= loadglobal(fqv[31]);
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,2,local+25); /*list*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,10,local+16); /*send*/
	w = local[15];
	local[15]= w;
	storeglobal(fqv[58],w);
	w = local[15];
	local[0]= w;
BLK2184:
	ctx->vsp=local; return(local[0]);}

/*rotate-vertices*/
static pointer F2038(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(0);
	local[4]= (pointer)((integer_t)(argv[1])-4);
WHL2220:
	local[5]= local[3];
	w = local[4];
	if ((integer_t)local[5] >= (integer_t)w) goto WHX2221;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[2];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)ROTVEC(ctx,3,local+5); /*rotate-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[2] = w;
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL2220;
WHX2221:
	local[5]= NIL;
BLK2222:
	w = NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK2218:
	ctx->vsp=local; return(local[0]);}

/*make-side-faces*/
static pointer F2039(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2225;}
	local[0]= NIL;
ENT2225:
ENT2224:
	if (n>3) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= makeint(0);
WHL2226:
	if (argv[1]==NIL) goto WHX2227;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[10];
	local[4] = w;
	if (argv[1]==NIL) goto IF2230;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF2231;
IF2230:
	local[10]= local[2];
IF2231:
	local[5] = local[10];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[10];
	local[7] = w;
	if (argv[0]==NIL) goto IF2233;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF2234;
IF2233:
	local[10]= local[1];
IF2234:
	local[6] = local[10];
	local[10]= local[4];
	local[11]= local[5];
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,4,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)F2034(ctx,1,local+10); /*make-face-from-vertices*/
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[59];
	if (local[0]==NIL) goto IF2235;
	local[12]= fqv[60];
	local[13]= local[0];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	goto IF2236;
IF2235:
	local[12]= fqv[60];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
IF2236:
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[9] = (pointer)((integer_t)(local[9])+4);
	local[10]= local[8];
	w = local[3];
	ctx->vsp=local+11;
	local[3] = cons(ctx,local[10],w);
	goto WHL2226;
WHX2227:
	local[10]= NIL;
BLK2228:
	w = local[3];
	local[0]= w;
BLK2223:
	ctx->vsp=local; return(local[0]);}

/*make-prism*/
static pointer F2040(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2238:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[61], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2239;
	local[2]= fqv[62];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[1] = w;
KEY2239:
	w = argv[1];
	if (!isnum(w)) goto IF2240;
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	argv[1] = w;
	local[2]= argv[1];
	goto IF2241;
IF2240:
	local[2]= NIL;
IF2241:
	local[2]= (pointer)get_sym_func(fqv[38]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO2242,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F2034(ctx,1,local+5); /*make-face-from-vertices*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[59];
	local[7]= fqv[63];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= local[4];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)REVERSE(ctx,1,local+7); /*reverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F2039(ctx,2,local+6); /*make-side-faces*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F2034(ctx,1,local+5); /*make-face-from-vertices*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[59];
	local[7]= fqv[64];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= (pointer)get_sym_func(fqv[65]);
	local[6]= loadglobal(fqv[54]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= fqv[22];
	local[8]= fqv[55];
	local[9]= local[4];
	local[10]= fqv[66];
	local[11]= T;
	local[12]= fqv[56];
	local[13]= local[1];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,10,local+5); /*apply*/
	local[0]= w;
BLK2237:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2242(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-conic-side-faces*/
static pointer F2041(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2245;}
	local[0]= NIL;
ENT2245:
ENT2244:
	if (n>3) maerror();
	local[1]= NIL;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeint(0);
WHL2246:
	if (argv[1]==NIL) goto WHX2247;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= argv[0];
	if (argv[1]==NIL) goto IF2250;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF2251;
IF2250:
	local[6]= local[2];
IF2251:
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F2034(ctx,1,local+4); /*make-face-from-vertices*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[59];
	if (local[0]==NIL) goto IF2252;
	local[6]= fqv[60];
	local[7]= local[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	goto IF2253;
IF2252:
	local[6]= fqv[60];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
IF2253:
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = (pointer)((integer_t)(local[3])+4);
	goto WHL2246;
WHX2247:
	local[4]= NIL;
BLK2248:
	w = local[1];
	local[0]= w;
BLK2243:
	ctx->vsp=local; return(local[0]);}

/*make-cone*/
static pointer F2042(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2255:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[67], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2256;
	local[1] = makeint(16);
KEY2256:
	if (n & (1<<1)) goto KEY2257;
	local[2] = NIL;
KEY2257:
	if (n & (1<<2)) goto KEY2258;
	local[3] = NIL;
KEY2258:
	local[4]= NIL;
	local[5]= NIL;
	w = argv[1];
	if (!isnum(w)) goto IF2259;
	local[6]= argv[1];
	local[7]= makeint(0);
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeflt(6.28318405e+00);
	local[9]= fqv[68];
	ctx->vsp=local+10;
	w=(pointer)F2038(ctx,4,local+6); /*rotate-vertices*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	argv[1] = w;
	local[6]= argv[1];
	goto IF2260;
IF2259:
	local[6]= (pointer)get_sym_func(fqv[38]);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	argv[1] = w;
	local[6]= argv[1];
IF2260:
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F2034(ctx,1,local+6); /*make-face-from-vertices*/
	local[5] = w;
	local[6]= local[5];
	local[7]= fqv[59];
	local[8]= fqv[64];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= (pointer)get_sym_func(fqv[65]);
	local[7]= loadglobal(fqv[54]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= fqv[22];
	local[9]= fqv[55];
	local[10]= local[5];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)F2041(ctx,2,local+11); /*make-conic-side-faces*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[66];
	local[12]= T;
	local[13]= fqv[56];
	local[14]= fqv[69];
	local[15]= fqv[63];
	local[16]= (pointer)get_sym_func(fqv[28]);
	local[17]= argv[1];
	ctx->vsp=local+18;
	w=(pointer)MAPCAR(ctx,2,local+16); /*mapcar*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,3,local+14); /*list*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,10,local+6); /*apply*/
	local[0]= w;
BLK2254:
	ctx->vsp=local; return(local[0]);}

/*on-z-axis-p*/
static pointer F2261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[2];
	local[1]= fqv[70];
	local[2]= fqv[71];
	local[3]= argv[0];
	local[4]= fqv[72];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[73];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK2262:
	ctx->vsp=local; return(local[0]);}

/*make-solid-of-revolution*/
static pointer F2043(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2264:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[74], &argv[1], n-1, local+1, 1);
	if (n & (1<<0)) goto KEY2265;
	local[1] = makeint(16);
KEY2265:
	local[2]= (pointer)get_sym_func(fqv[38]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= makeflt(9.99999698e-04);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto IF2267;
	local[7]= local[3];
	local[8]= local[1];
	local[9]= makeflt(6.28318405e+00);
	local[10]= fqv[68];
	ctx->vsp=local+11;
	w=(pointer)F2038(ctx,4,local+7); /*rotate-vertices*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)F2034(ctx,1,local+7); /*make-face-from-vertices*/
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[59];
	local[9]= fqv[64];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF2268;
IF2267:
	local[7]= NIL;
IF2268:
WHL2269:
	if (local[2]==NIL) goto WHX2270;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= makeflt(9.99999698e-04);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto IF2273;
	local[7]= local[4];
	local[8]= local[1];
	local[9]= makeflt(6.28318405e+00);
	local[10]= fqv[68];
	ctx->vsp=local+11;
	w=(pointer)F2038(ctx,4,local+7); /*rotate-vertices*/
	local[4] = w;
	local[7]= local[4];
	goto IF2274;
IF2273:
	local[7]= NIL;
IF2274:
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON2276;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2277;
	local[7]= fqv[75];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF2278;
IF2277:
	local[7]= NIL;
IF2278:
	local[7]= local[4];
	local[8]= local[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F2041(ctx,3,local+7); /*make-conic-side-faces*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto CON2275;
CON2276:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON2279;
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)REVERSE(ctx,1,local+8); /*reverse*/
	local[8]= w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F2041(ctx,3,local+7); /*make-conic-side-faces*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto CON2275;
CON2279:
	local[7]= local[3];
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F2039(ctx,3,local+7); /*make-side-faces*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto CON2275;
CON2280:
	local[7]= NIL;
CON2275:
	local[6] = (pointer)((integer_t)(local[6])+4);
	local[3] = local[4];
	goto WHL2269;
WHX2270:
	local[7]= NIL;
BLK2271:
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF2281;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LISTP(ctx,1,local+7); /*listp*/
	if (w==NIL) goto IF2281;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)REVERSE(ctx,1,local+7); /*reverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F2034(ctx,1,local+7); /*make-face-from-vertices*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto IF2282;
IF2281:
	local[7]= NIL;
IF2282:
	local[7]= (pointer)get_sym_func(fqv[65]);
	local[8]= loadglobal(fqv[54]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= fqv[22];
	local[10]= fqv[55];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,1,local+11,&ftab[9],fqv[76]); /*flatten*/
	local[11]= w;
	local[12]= fqv[66];
	local[13]= T;
	local[14]= fqv[56];
	local[15]= fqv[77];
	local[16]= argv[0];
	local[17]= local[1];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,3,local+15); /*list*/
	local[15]= w;
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,10,local+7); /*apply*/
	local[0]= w;
BLK2263:
	ctx->vsp=local; return(local[0]);}

/*make-torus*/
static pointer F2044(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2284:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[78], &argv[1], n-1, local+1, 1);
	if (n & (1<<0)) goto KEY2285;
	local[1] = makeint(16);
KEY2285:
	local[2]= NIL;
	local[3]= (pointer)get_sym_func(fqv[38]);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= local[1];
	local[6]= makeflt(6.28318405e+00);
	local[7]= fqv[68];
	ctx->vsp=local+8;
	w=(pointer)F2038(ctx,4,local+4); /*rotate-vertices*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= makeint(0);
	local[5] = local[4];
WHL2287:
	if (local[3]==NIL) goto WHX2288;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= local[1];
	local[10]= makeflt(6.28318405e+00);
	local[11]= fqv[68];
	ctx->vsp=local+12;
	w=(pointer)F2038(ctx,4,local+8); /*rotate-vertices*/
	local[6] = w;
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[6];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)F2039(ctx,3,local+9); /*make-side-faces*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[2] = w;
	local[7] = (pointer)((integer_t)(local[7])+4);
	local[5] = local[6];
	goto WHL2287;
WHX2288:
	local[8]= NIL;
BLK2289:
	local[8]= local[2];
	local[9]= local[6];
	local[10]= local[4];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)F2039(ctx,3,local+9); /*make-side-faces*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= (pointer)get_sym_func(fqv[65]);
	local[9]= loadglobal(fqv[54]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= fqv[22];
	local[11]= fqv[55];
	local[12]= local[2];
	local[13]= fqv[56];
	local[14]= fqv[79];
	local[15]= argv[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,3,local+14); /*list*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,8,local+8); /*apply*/
	local[0]= w;
BLK2283:
	ctx->vsp=local; return(local[0]);}

/*make-cylinder*/
static pointer F2045(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2292:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[80], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2293;
	local[1] = makeint(12);
KEY2293:
	if (n & (1<<1)) goto KEY2294;
	local[2] = NIL;
KEY2294:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	argv[0] = w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	argv[1] = w;
	local[3]= makeflt(6.28318405e+00);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	if (local[2]==NIL) goto IF2295;
	local[4]= argv[0];
	local[5]= local[3];
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)COS(ctx,1,local+5); /*cos*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	goto IF2296;
IF2295:
	local[4]= argv[0];
IF2296:
	local[5]= local[4];
	local[6]= makeint(0);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	local[7]= NIL;
	local[8]= makeint(0);
	local[9]= (pointer)((integer_t)(local[1])-4);
WHL2298:
	local[10]= local[8];
	w = local[9];
	if ((integer_t)local[10] >= (integer_t)w) goto WHX2299;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[3];
	local[12]= fqv[68];
	ctx->vsp=local+13;
	w=(pointer)ROTVEC(ctx,3,local+10); /*rotate-vector*/
	local[10]= w;
	w = local[6];
	ctx->vsp=local+11;
	local[6] = cons(ctx,local[10],w);
	local[8] = (pointer)((integer_t)(local[8])+4);
	goto WHL2298;
WHX2299:
	local[10]= NIL;
BLK2300:
	w = NIL;
	local[8]= (pointer)get_sym_func(fqv[81]);
	local[9]= local[6];
	local[10]= argv[1];
	local[11]= fqv[56];
	local[12]= fqv[82];
	local[13]= local[4];
	local[14]= argv[1];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,4,local+12); /*list*/
	local[12]= w;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,6,local+8); /*apply*/
	local[7] = w;
	local[8]= local[7];
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= makeint(0);
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[10])(ctx,2,local+9,&ftab[10],fqv[83]); /*make-line*/
	local[9]= w;
	local[10]= fqv[84];
	ctx->vsp=local+11;
	w=(pointer)PUTPROP(ctx,3,local+8); /*putprop*/
	w = local[7];
	local[0]= w;
BLK2291:
	ctx->vsp=local; return(local[0]);}

/*make-cube*/
static pointer F2046(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST2302:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0] = w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[1] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= makeflt(2.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeflt(2.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[4] = w;
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[5] = w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[6] = w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[7] = w;
	local[9]= (pointer)get_sym_func(fqv[81]);
	local[10]= local[4];
	local[11]= local[5];
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,4,local+10); /*list*/
	local[10]= w;
	local[11]= argv[2];
	local[12]= fqv[56];
	local[13]= fqv[85];
	local[14]= argv[0];
	local[15]= argv[1];
	local[16]= argv[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,4,local+13); /*list*/
	local[13]= w;
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,6,local+9); /*apply*/
	local[8] = w;
	local[9]= NIL;
	local[10]= local[8];
	local[11]= fqv[86];
	local[12]= NIL;
	local[13]= fqv[60];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
WHL2304:
	if (local[10]==NIL) goto WHX2305;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= fqv[59];
	local[13]= local[9];
	local[14]= fqv[59];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= makeint(1);
	local[15]= local[9];
	local[16]= fqv[59];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)NTH(ctx,2,local+14); /*nth*/
	local[14]= w;
	local[15]= fqv[87];
	ctx->vsp=local+16;
	w=(pointer)NTH(ctx,2,local+14); /*nth*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPEND(ctx,2,local+13); /*append*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	goto WHL2304;
WHX2305:
	local[11]= NIL;
BLK2306:
	w = NIL;
	w = local[8];
	local[0]= w;
BLK2301:
	ctx->vsp=local; return(local[0]);}

/*icosahedron-points*/
static pointer F2047(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2310;}
	local[0]= makeflt(1.00000000e+00);
ENT2310:
ENT2309:
	if (n>1) maerror();
	local[1]= makeflt(1.00000000e+00);
	local[2]= makeflt(5.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)SQRT(ctx,1,local+2); /*sqrt*/
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)SQRT(ctx,1,local+3); /*sqrt*/
	local[3]= w;
	local[4]= makeflt(5.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeflt(1.00000000e+00);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SQRT(ctx,1,local+5); /*sqrt*/
	local[5]= w;
	local[6]= makeflt(5.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SQRT(ctx,1,local+6); /*sqrt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SQRT(ctx,1,local+6); /*sqrt*/
	{ double x,y;
		y=fltval(w); x=fltval(local[5]);
		local[5]=(makeflt(x * y));}
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= makeint(0);
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint(0);
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeint(0);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= makeint(0);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	local[12]= makeint(0);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[3];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)MKFLTVEC(ctx,3,local+12); /*float-vector*/
	local[12]= w;
	local[13]= local[2];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,3,local+13); /*float-vector*/
	local[13]= w;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= local[3];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,1,local+15); /*-*/
	local[15]= w;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,1,local+16); /*-*/
	local[16]= w;
	local[17]= makeint(0);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,3,local+15); /*float-vector*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,12,local+4); /*list*/
	local[0]= w;
BLK2308:
	ctx->vsp=local; return(local[0]);}

/*make-icosahedron*/
static pointer F2048(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2313;}
	local[0]= makeflt(1.00000000e+00);
ENT2313:
ENT2312:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F2047(ctx,1,local+3); /*icosahedron-points*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F2037(ctx,1,local+3); /*convex-hull-3d*/
	local[2] = w;
	local[3]= local[2];
	local[4]= fqv[88];
	local[5]= fqv[89];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK2311:
	ctx->vsp=local; return(local[0]);}

/*subdivide-facet*/
static pointer F2049(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2315;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2316;
IF2315:
	local[3]= NIL;
IF2316:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2034(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2317;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2318;
IF2317:
	local[3]= NIL;
IF2318:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2034(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2319;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2320;
IF2319:
	local[3]= NIL;
IF2320:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2034(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2321;}
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2322;
IF2321:
	local[3]= NIL;
IF2322:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2034(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w = local[1];
	local[0]= w;
BLK2314:
	ctx->vsp=local; return(local[0]);}

/*make-dodecahedron*/
static pointer F2050(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2325;}
	local[0]= makeflt(1.00000000e+00);
ENT2325:
ENT2324:
	if (n>1) maerror();
	ctx->vsp=local+1;
	w=(pointer)F2048(ctx,0,local+1); /*make-icosahedron*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[1]->c.obj.iv[9];
WHL2327:
	if (local[6]==NIL) goto WHX2328;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w=local[5]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,1,local+7,&ftab[11],fqv[90]); /*vector-mean*/
	local[2] = w;
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)VNORM(ctx,1,local+8); /*norm*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= local[2];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	goto WHL2327;
WHX2328:
	local[7]= NIL;
BLK2329:
	w = NIL;
	local[5]= local[3];
	storeglobal(fqv[91],local[5]);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)F2037(ctx,1,local+5); /*convex-hull-3d*/
	local[4] = w;
	local[5]= local[4];
	local[6]= fqv[88];
	local[7]= fqv[92];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK2323:
	ctx->vsp=local; return(local[0]);}

/*make-gdome*/
static pointer F2051(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[93];
	local[1]= (pointer)get_sym_func(fqv[94]);
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[95]); /*make-hash-table*/
	local[0]= w;
	local[1]= fqv[93];
	local[2]= (pointer)get_sym_func(fqv[94]);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[95]); /*make-hash-table*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	w=*(ovafptr(argv[0],fqv[32]));
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= *(ovafptr(argv[0],fqv[32]));
WHL2333:
	if (local[10]==NIL) goto WHX2334;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= local[0];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)COPYOBJ(ctx,1,local+13); /*copy-object*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[13])(ctx,3,local+11,&ftab[13],fqv[96]); /*sethash*/
	goto WHL2333;
WHX2334:
	local[11]= NIL;
BLK2335:
	w = NIL;
	local[9]= NIL;
	local[10]= *(ovafptr(argv[0],fqv[97]));
WHL2338:
	if (local[10]==NIL) goto WHX2339;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= *(ovafptr(local[9],fqv[98]));
	local[13]= *(ovafptr(local[9],fqv[99]));
	ctx->vsp=local+14;
	w=(pointer)VPLUS(ctx,2,local+12); /*v+*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)VNORMALIZE(ctx,1,local+12); /*normalize-vector*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[4] = w;
	local[11]= local[9];
	local[12]= local[1];
	local[13]= local[9];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(*ftab[13])(ctx,3,local+11,&ftab[13],fqv[96]); /*sethash*/
	goto WHL2338;
WHX2339:
	local[11]= NIL;
BLK2340:
	w = NIL;
	local[9]= NIL;
	local[10]= *(ovafptr(argv[0],fqv[100]));
WHL2343:
	if (local[10]==NIL) goto WHX2344;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[4] = *(ovafptr(local[9],fqv[32]));
	local[5] = *(ovafptr(local[9],fqv[97]));
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[14])(ctx,2,local+11,&ftab[14],fqv[101]); /*gethash*/
	local[11]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(*ftab[14])(ctx,2,local+12,&ftab[14],fqv[101]); /*gethash*/
	local[12]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(*ftab[14])(ctx,2,local+13,&ftab[14],fqv[101]); /*gethash*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[2] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(*ftab[14])(ctx,2,local+11,&ftab[14],fqv[101]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(*ftab[14])(ctx,2,local+12,&ftab[14],fqv[101]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(*ftab[14])(ctx,2,local+13,&ftab[14],fqv[101]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[3] = w;
	local[11]= *(ovafptr(local[9],fqv[102]));
	local[12]= local[2];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)F2049(ctx,3,local+11); /*subdivide-facet*/
	local[11]= w;
	w = local[6];
	ctx->vsp=local+12;
	local[6] = cons(ctx,local[11],w);
	goto WHL2343;
WHX2344:
	local[11]= NIL;
BLK2345:
	w = NIL;
	local[9]= loadglobal(fqv[54]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[22];
	local[12]= fqv[55];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[9])(ctx,1,local+13,&ftab[9],fqv[76]); /*flatten*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	w = local[9];
	local[8] = w;
	local[9]= local[8];
	local[10]= fqv[88];
	local[11]= fqv[103];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = local[8];
	local[0]= w;
BLK2331:
	ctx->vsp=local; return(local[0]);}

/*make-body-from-vertices*/
static pointer F2052(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2350;}
	local[0]= loadglobal(fqv[54]);
ENT2350:
ENT2349:
	if (n>2) maerror();
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= (pointer)get_sym_func(fqv[50]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	local[3]= fqv[93];
	local[4]= (pointer)get_sym_func(fqv[94]);
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,3,local+2,&ftab[8],fqv[52]); /*remove-duplicates*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL2352:
	if (local[5]==NIL) goto WHX2353;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[4];
WHL2357:
	if (local[8]==NIL) goto WHX2358;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= local[1];
	local[11]= fqv[93];
	local[12]= (pointer)get_sym_func(fqv[94]);
	ctx->vsp=local+13;
	w=(*ftab[15])(ctx,4,local+9,&ftab[15],fqv[104]); /*assoc*/
	local[9]= w;
	w = local[6];
	ctx->vsp=local+10;
	local[6] = cons(ctx,local[9],w);
	goto WHL2357;
WHX2358:
	local[9]= NIL;
BLK2359:
	w = NIL;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F2034(ctx,1,local+7); /*make-face-from-vertices*/
	local[7]= w;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	w = local[2];
	goto WHL2352;
WHX2353:
	local[6]= NIL;
BLK2354:
	w = NIL;
	local[4]= loadglobal(fqv[54]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[22];
	local[7]= fqv[55];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	w = local[4];
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[88];
	local[6]= fqv[105];
	w = argv[0];
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK2348:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M2362(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2365:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX2366;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+4;
	w=(pointer)NTH(ctx,2,local+2); /*nth*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[106];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+7;
	w=(pointer)NTH(ctx,2,local+5); /*nth*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[107]); /*replace*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL2365;
WHX2366:
	local[2]= NIL;
BLK2367:
	w = NIL;
	local[0]= w;
BLK2363:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M2368(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2371:
	local[2]= local[0];
	w = local[1];
	if ((integer_t)local[2] >= (integer_t)w) goto WHX2372;
	local[2]= argv[2];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)NTH(ctx,2,local+3); /*nth*/
	local[3]= w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+6;
	w=(pointer)NTH(ctx,2,local+4); /*nth*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,3,local+2); /*scale*/
	local[0] = (pointer)((integer_t)(local[0])+4);
	goto WHL2371;
WHX2372:
	local[2]= NIL;
BLK2373:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[108];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK2369:
	ctx->vsp=local; return(local[0]);}

/*:drawners*/
static pointer M2374(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK2375:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M2376(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST2378:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	argv[0]->c.obj.iv[10] = NIL;
	argv[0]->c.obj.iv[11] = NIL;
	argv[0]->c.obj.iv[8] = argv[2];
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= argv[2];
	local[2]= makeint(0);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= makeint(0);
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= argv[2];
	local[2]= makeflt(5.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= argv[2];
	local[4]= makeflt(7.99999952e-01);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= makeint(0);
	local[2]= argv[2];
	local[3]= makeflt(5.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeflt(7.99999952e-01);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)COPYOBJ(ctx,1,local+1); /*copy-object*/
	argv[0]->c.obj.iv[9] = w;
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[83]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[83]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,1,local+2,&ftab[17],fqv[109]); /*fourth*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[83]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[109]); /*fourth*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,1,local+2,&ftab[18],fqv[110]); /*fifth*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[83]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[109]); /*fourth*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,1,local+2,&ftab[19],fqv[111]); /*sixth*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[83]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	local[1]= (pointer)get_sym_func(fqv[112]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[113]));
	local[4]= fqv[22];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK2377:
	ctx->vsp=local; return(local[0]);}

/*assoc-coordinates-axes*/
static pointer F2053(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2382;}
	local[0]= makeint(1);
ENT2382:
	if (n>=3) { local[1]=(argv[2]); goto ENT2381;}
	ctx->vsp=local+1;
	w=(*ftab[20])(ctx,0,local+1,&ftab[20],fqv[114]); /*coords*/
	local[1]= w;
ENT2381:
ENT2380:
	if (n>3) maerror();
	local[2]= loadglobal(fqv[115]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[22];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[116];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK2379:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___primt(ctx,n,argv,env)
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
	local[0]= fqv[117];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2384;
	local[0]= fqv[118];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[119],w);
	goto IF2385;
IF2384:
	local[0]= fqv[120];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2385:
	local[0]= fqv[121];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F2020,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F2021,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F2022,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F2023,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F2024,fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F2025,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F2026,fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F2027,fqv[138]);
	local[0]= makeflt(9.99999698e-04);
	storeglobal(fqv[9],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F2028,fqv[140]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F2029,fqv[142]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F2030,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F2031,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F2032,fqv[148]);
	local[0]= fqv[13];
	local[1]= fqv[149];
	local[2]= makeflt(-1.00000000e+00);
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[150];
	local[1]= fqv[149];
	local[2]= makeflt(1.00000000e+00);
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= fqv[14];
	local[4]= fqv[149];
	local[5]= makeflt(0.00000000e+00);
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F2033,fqv[152]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F2034,fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F2035,fqv[156]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[157],module,F2036,fqv[158]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F2037,fqv[160]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F2038,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F2039,fqv[164]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F2040,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F2041,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F2042,fqv[169]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[170],module,F2261,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F2043,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F2044,fqv[175]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[176],module,F2045,fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F2046,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F2047,fqv[181]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[182],module,F2048,fqv[183]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[184],module,F2049,fqv[185]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F2050,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F2051,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F2052,fqv[191]);
	local[0]= fqv[115];
	local[1]= fqv[149];
	local[2]= fqv[115];
	local[3]= fqv[192];
	local[4]= loadglobal(fqv[193]);
	local[5]= fqv[194];
	local[6]= fqv[195];
	local[7]= fqv[196];
	local[8]= NIL;
	local[9]= fqv[197];
	local[10]= NIL;
	local[11]= fqv[198];
	local[12]= makeint(-1);
	local[13]= fqv[199];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[21])(ctx,13,local+2,&ftab[21],fqv[200]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2362,fqv[108],fqv[115],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2368,fqv[202],fqv[115],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2374,fqv[204],fqv[115],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2376,fqv[22],fqv[115],fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F2053,fqv[208]);
	local[0]= fqv[209];
	local[1]= fqv[210];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[211]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<23; i++) ftab[i]=fcallx;
}
