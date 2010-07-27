/*
 *Header:
 *Title: Subroutines for Neural Networks
 *Author: Itsuki Noda
 *Date: 1996/07/07
 *File: nnsub.c
 *EndHeader:
 */

/*
 *======================================================================
 * Includes 
 *----------------------------------------------------------------------
 */
#include "eus.h"
#include <stdio.h>
#include <math.h>

/*
 *======================================================================
 * Tables
 *----------------------------------------------------------------------
 */
typedef struct _NNsubFuncTable {
     char*	lispname ;
     pointer	(*funcname)() ;
     char*	args ;
} NNsubFuncTable ;
#define NNSUBFUNCTABLE {\
 {"v=",		Vlet,		"\"(r-fltvec fltvec)\""},\
 {"v+=",	Vinc,		"\"(r-fltvec fltvec)\""},\
 {"v-=",	Vdec,		"\"(r-fltvec fltvec)\""},\
 {"v*=",	Vmul,		"\"(r-fltvec fltvec)\""},\
 {"v/=",	Vdiv,		"\"(r-fltvec fltvec)\""},\
 {"v=s",	VletScalar,	"\"(r-fltvec scalar)\""},\
 {"v=sigmoid",	VletSigmoid,	"\"(r-fltvec fltvec temperature)\""},\
 {"v=dsigdx_o",	VletDsigDx_O,	"\"(r-fltvec fltvec temperature)\""},\
 {"v*=dsigdx_o",VmulDsigDx_O,	"\"(r-fltvec fltvec temperature)\""},\
 {"v=noise",	VletNoise,	"\"(r-fltvec min max)\""},\
 {"v+=noise",	VincNoise,	"\"(r-fltvec min max)\""},\
 {"v+=m*v",	VincMxV,	"\"(r-fltvec fltmat fltvec)\""},\
 {"v+=v*m",	VincVxM,	"\"(r-fltvec fltvec fltmat)\""},\
 {"v+=delta_sig_out", VletDeltaSigOut, "\"(delta target output temp)\""},\
 {"m=",		Mlet,		"\"(r-fltmat fltmat)\""},\
 {"m+=",	Minc,		"\"(r-fltmat fltmat)\""},\
 {"m-=",	Minc,		"\"(r-fltmat fltmat)\""},\
 {"m*=",	Mmul,		"\"(r-fltmat fltmat)\""},\
 {"m/=",	Mdiv,		"\"(r-fltmat fltmat)\""},\
 {"m=s",	MletScalar,	"\"(r-fltmat scalar)\""},\
 {"m=noise",	MletNoise,	"\"(r-fltmat min max)\""},\
 {"m+=noise",	MincNoise,	"\"(r-fltmat min max)\""},\
 {"m=v**v",	MletVxxV,	"\"(r-fltmat fltvec fltvec)\""},\
 {"m+=v**v",	MincVxxV,	"\"(r-fltmat fltvec fltvec)\""},\
 {"v=a*v+e*v",	VmulincAV,	"\"(r-fltvec alpha eta delta)\""},\
 {"m=a*m+e*v**v",MmulincAVxxV,	"\"(r-fltmat alpha eta delta output)\""},\
 {NULL},\
 }


/*
 *======================================================================
 * for EusLisp
 *----------------------------------------------------------------------
 */
extern double fabs();
extern pointer fcallx();
static void init_ftab();
#define loadglobal(s) s->c.sym.speval
#define storeglobal(s,val) s->c.sym.speval=(val)
static pointer module,*qv,codevec,quotevec;
extern pointer ___nnsub();
extern pointer build_quote_vector();
static register_nnsub()
  { add_module_initializer("___nnsub", ___nnsub);}


/*
 *======================================================================
 * Definitions
 *----------------------------------------------------------------------
 */
#define sigmoid(x,t) (1.0/(1.0 + exp(-((double)x)/((double)t))))
#define DsigDx_O(o,t) (((double)o * (1.0 - (double)o))/((double)t))
#define ismatrix(p) ((isarray(p) && \
                      p->c.ary.rank==makeint(2) && \
                      elmtypeof(p->c.ary.entity)==ELM_FLOAT))
#define rowsize(p) (intval(p->c.ary.dim[0]))
#define colsize(p) (intval(p->c.ary.dim[1]))
#define matrixval(p)  (p->c.ary.entity->c.fvec.fv)
#define ckvsize(a,b) ((a->c.vec.size==b->c.vec.size)?vecsize(a):(int)(integer_t)error(E_VECINDEX))
#define vectorval(p) (p->c.fvec.fv)

extern pointer RANDSTATE;
#if news || sanyo
long random() ;
#define RVAL(state)	random()
#else
#if alpha
double erand48() ;
#define RVAL(state)	erand48((unsigned short *)state->c.ivec.iv)
#else
double erand48() ;
#define RVAL(state)	erand48(state->c.ivec.iv)
#endif
#endif

/*
 *==================================================
 * v=
 *--------------------------------------------------
 */
static pointer Vlet(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;

  ckarg(2);
  result = argv[0] ; xv = argv[1] ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] = x[i] ;
  }
  return result ;
}

/*
 *==================================================
 * v+=
 *--------------------------------------------------
 */
static pointer Vinc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;

  ckarg(2);
  result = argv[0] ; xv = argv[1] ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] += x[i] ;
  }
  return result ;
}

/*
 *==================================================
 * v-=
 *--------------------------------------------------
 */
static pointer Vdec(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;

  ckarg(2);
  result = argv[0] ; xv = argv[1] ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] -= x[i] ;
  }
  return result ;
}

/*
 *==================================================
 * v*=
 *--------------------------------------------------
 */
static pointer Vmul(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;

  ckarg(2);
  result = argv[0] ; xv = argv[1] ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] *= x[i] ;
  }
  return result ;
}

/*
 *==================================================
 * v/=
 *--------------------------------------------------
 */
static pointer Vdiv(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;

  ckarg(2);
  result = argv[0] ; xv = argv[1] ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] /= x[i] ;
  }
  return result ;
}

/*
 *==================================================
 * v=s
 *--------------------------------------------------
 */
static pointer VletScalar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result ;
  float_t scalar ;
  int i,size ;
  float_t *r ;
  
  ckarg(2);
  result = argv[0] ;
  scalar = ckfltval(argv[1]) ;
  size = vecsize(result) ;
  r = vectorval(result) ;

  for(i = 0 ; i < size ; i++) {
       r[i] = scalar ;
  }
  return result ;
}

/*
 *==================================================
 * v=sigmoid
 *--------------------------------------------------
 */
static pointer VletSigmoid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;
  float_t t ;

  ckarg(3);
  result = argv[0] ; xv = argv[1] ;
  t = ckfltval(argv[2]) ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] = (float_t)sigmoid(x[i],t) ;
  }
  return result ;
}

/*
 *==================================================
 * v=dsigdx_o (r = o * (1-o) / t) 
 *--------------------------------------------------
 */
static pointer VletDsigDx_O(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;
  float_t t ;

  ckarg(3);
  result = argv[0] ; xv = argv[1] ;
  t = ckfltval(argv[2]) ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] = (float_t)(DsigDx_O(x[i],t)) ;
  }
  return result ;
}

/*
 *==================================================
 * v*=dsigdx_o (r *= o * (1-o) / t) 
 *--------------------------------------------------
 */
static pointer VmulDsigDx_O(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,xv ;
  int i,size ;
  float_t *x, *r ;
  float_t t ;

  ckarg(3);
  result = argv[0] ; xv = argv[1] ;
  t = ckfltval(argv[2]) ;

  size = min(vecsize(result),vecsize(xv)) ;
  r = vectorval(result) ;  x = vectorval(xv) ; 
  
  for(i = 0 ; i < size ; i++) {
       r[i] *= (float_t)(DsigDx_O(x[i],t)) ;
  }
  return result ;
}

/*
 *==================================================
 * v=noise
 *--------------------------------------------------
 */
static pointer VletNoise(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,state ;
  float_t minval,maxval ;
  int i,size ;
  float_t *r ;
  double offset, width ;

  ckarg(3);
  result = argv[0] ;
  minval = ckfltval(argv[1]) ;
  maxval = ckfltval(argv[2]) ;
  size = vecsize(result) ;
  r = vectorval(result) ;

  offset = (double)minval ;
  width = (double)(maxval-minval) ;

  state=Spevalof(RANDSTATE);
  if (state==UNBOUND) state=speval(RANDSTATE);

  for(i = 0 ; i < size ; i++) {
       r[i] = (float_t)(offset + RVAL(state) * width) ;
  }
  return result ;
}

/*
 *==================================================
 * v+=noise
 *--------------------------------------------------
 */
static pointer VincNoise(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,state ;
  float_t minval, maxval ;
  int i,size ;
  float_t *r ;
  double offset, width ;
  
  ckarg(3);
  result = argv[0] ;
  minval = ckfltval(argv[1]) ;
  maxval = ckfltval(argv[2]) ;
  size = vecsize(result) ;
  r = vectorval(result) ;

  offset = (double)minval ;
  width = (double)(maxval-minval) ;

  state=Spevalof(RANDSTATE);
  if (state==UNBOUND) state=speval(RANDSTATE);

  for(i = 0 ; i < size ; i++) {
       r[i] += (float_t)(offset + RVAL(state) * width) ;
  }
  return result ;
}

/*
 *==================================================
 * v+=m*v
 *--------------------------------------------------
 */
static pointer VincMxV(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,mat,vec ;
  int i,j,k,M,N ;
  float_t *W,*v,*r,x;

  ckarg(3);
  result = argv[0] ; mat = argv[1] ; vec = argv[2] ;
  N = rowsize(mat);
  M = colsize(mat);
  W = matrixval(mat) ;
  v = vectorval(vec) ;
  r = vectorval(result) ;

  for(i=0 ; i < N ; i++) {
       x = 0.0 ; k = i * M ;
       for(j = 0 ; j < M ; j++) x += W[k+j]*v[j] ;
       r[i] += x ;
  }
  return result ;
}

/*
 *==================================================
 * v+=v*m
 *--------------------------------------------------
 */
static pointer VincVxM(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,mat,vec ;
  int i,j,k,M,N ;
  float_t *W,*v,*r,x;

  ckarg(3);
  result = argv[0] ; vec = argv[1] ; mat = argv[2] ;
  N = rowsize(mat) ;
  M = colsize(mat) ;
  W = matrixval(mat) ;
  v = vectorval(vec) ;
  r = vectorval(result) ;

  for(j=0 ; j < M ; j++) {
       x = 0.0 ; 
       for(i = 0 ; i < N ; i++) x += v[i]*W[i*M+j] ;
       r[j] += x ;
  }
  return result ;
}


/*
 *======================================================================
 * Neural Specifics
 *----------------------------------------------------------------------
 */
/*
 *==================================================
 * v=delta_sig_out (delta = (target - output) * output * (1-output) / t) 
 *--------------------------------------------------
 */
static pointer VletDeltaSigOut(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer delta,target,output ;
  int i,size ;
  float_t *dlt, *tgt, *out ;
  float_t t ;

  ckarg(3);
  delta = argv[0] ; 
  target = argv[1] ; 
  output = argv[2] ; 
  t = ckfltval(argv[2]) ;

  size = min(vecsize(delta),vecsize(target)) ;
  dlt = vectorval(delta) ;  
  tgt = vectorval(target) ; 
  out = vectorval(output) ; 
  
  for(i = 0 ; i < size ; i++) {
       *dlt += (*tgt - *out) * (float_t)DsigDx_O(*out,t) ;
       dlt++ ; tgt++ ; out++ ;
  }
  return delta ;
}

/*
 *==================================================
 * m=
 *--------------------------------------------------
 */
static pointer Mlet(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,src;
  int i,j,k,M,N ;
  float_t *W,*Ws ;

  ckarg(2);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  src = argv[1] ; 
  Ws = matrixval(src) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] = Ws[k+j] ;
  }
  return result ;
}

/*
 *==================================================
 * m+=
 *--------------------------------------------------
 */
static pointer Minc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,src;
  int i,j,k,M,N ;
  float_t *W,*Ws ;

  ckarg(2);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  src = argv[1] ; 
  Ws = matrixval(src) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] += Ws[k+j] ;
  }
  return result ;
}

/*
 *==================================================
 * m-=
 *--------------------------------------------------
 */
static pointer Mdec(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,src;
  int i,j,k,M,N ;
  float_t *W,*Ws ;

  ckarg(2);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  src = argv[1] ; 
  Ws = matrixval(src) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] -= Ws[k+j] ;
  }
  return result ;
}

/*
 *==================================================
 * m*=
 *--------------------------------------------------
 */
static pointer Mmul(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,src;
  int i,j,k,M,N ;
  float_t *W,*Ws ;

  ckarg(2);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  src = argv[1] ; 
  Ws = matrixval(src) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] *= Ws[k+j] ;
  }
  return result ;
}

/*
 *==================================================
 * m/=
 *--------------------------------------------------
 */
static pointer Mdiv(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,src;
  int i,j,k,M,N ;
  float_t *W,*Ws ;

  ckarg(2);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  src = argv[1] ; 
  Ws = matrixval(src) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] /= Ws[k+j] ;
  }
  return result ;
}

/*
 *==================================================
 * m=s
 *--------------------------------------------------
 */
static pointer MletScalar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result;
  int i,j,k,M,N ;
  float_t *W;
  float_t scalar ;

  ckarg(2);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  scalar = ckfltval(argv[1]) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] = scalar ;
  }
  return result ;
}

/*
 *==================================================
 * m=noise
 *--------------------------------------------------
 */
static pointer MletNoise(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result;
  int i,j,k,M,N ;
  float_t *W ;
  float_t minval,maxval ;
  double offset, width ;
  pointer state ;

  ckarg(3);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  minval = ckfltval(argv[1]) ;
  maxval = ckfltval(argv[2]) ;
  offset = (double)minval ;
  width = (double)(maxval-minval) ;

  state=Spevalof(RANDSTATE);
  if (state==UNBOUND) state=speval(RANDSTATE);

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) {
	    W[k+j] = (float_t)(offset + RVAL(state) * width) ; 
       }
  }
  return result ;
}


/*
 *==================================================
 * m+=noise
 *--------------------------------------------------
 */
static pointer MincNoise(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result;
  int i,j,k,M,N ;
  float_t *W ;
  float_t minval,maxval ;
  double offset, width ;
  pointer state ;

  ckarg(3);
  result = argv[0] ; 
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  minval = ckfltval(argv[1]) ;
  maxval = ckfltval(argv[2]) ;
  offset = (double)minval ;
  width = (double)(maxval-minval) ;

  state=Spevalof(RANDSTATE);
  if (state==UNBOUND) state=speval(RANDSTATE);

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] += (float_t)(offset + RVAL(state) * width) ; 
  }
  return result ;
}

/*
 *==================================================
 * m=v**v
 *--------------------------------------------------
 */
static pointer MletVxxV(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,vec1,vec2 ;
  int i,j,k,M,N ;
  float_t *W,*v1,*v2;

  ckarg(3);
  result = argv[0] ; vec1 = argv[1] ; vec2 = argv[2] ;
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  v1 = vectorval(vec1) ;
  v2 = vectorval(vec2) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] = v1[i] * v2[j] ;
  }
  return result ;
}

/*
 *==================================================
 * m+=v**v
 *--------------------------------------------------
 */
static pointer MincVxxV(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,vec1,vec2 ;
  int i,j,k,M,N ;
  float_t *W,*v1,*v2;

  ckarg(3);
  result = argv[0] ; vec1 = argv[1] ; vec2 = argv[2] ;
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  v1 = vectorval(vec1) ;
  v2 = vectorval(vec2) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] += v1[i] * v2[j] ;
  }
  return result ;
}

/*
 *==================================================
 * v= a*v+e*v (V = alpha * V + eta * V1)
 *--------------------------------------------------
 */
static pointer VmulincAV(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,vec1,alpha,eta ;
  int i,N ;
  float_t *v0,*v1;
  float_t a,e ;

  ckarg(4);
  result = argv[0] ; 	
  alpha = argv[1] ;
  eta = argv[2] ;
  vec1 = argv[3] ; 
  N = min(vecsize(result),vecsize(vec1)) ;
  v0 = vectorval(result) ;
  v1 = vectorval(vec1) ;
  a = ckfltval(alpha) ;
  e = ckfltval(eta) ;


  for(i=0 ; i < N ; i++) {
       v0[i] = a * v0[i] + e * v1[i] ;
  }
  return result ;
}

/*
 *==================================================
 * m=a*m+v**v (M = alpha * M + eta * V1 ** V2)
 *--------------------------------------------------
 */
static pointer MmulincAVxxV(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ numunion nu;

  pointer result,alpha,vec1,vec2,eta ;
  int i,j,k,M,N ;
  float_t *W,*v1,*v2,a,e;

  ckarg(5);
  result = argv[0] ; 
  alpha = argv[1] ;
  eta = argv[2] ;
  vec1 = argv[3] ; vec2 = argv[4] ;
  
  N = rowsize(result) ;
  M = colsize(result) ;
  W = matrixval(result) ;
  a = ckfltval(alpha) ;
  v1 = vectorval(vec1) ;
  v2 = vectorval(vec2) ;
  e = ckfltval(eta) ;

  for(i=0 ; i < N ; i++) {
       k = i * M ;
       for(j = 0 ; j < M ; j++) 
	    W[k+j] = a * W[k+j] + e * v1[i] * v2[j] ;
  }
  return result ;
}

/*
 *======================================================================
 * Initializer
 *----------------------------------------------------------------------
 */

pointer ___nnsub(ctx,n,argv,env)
register context *ctx; int n; pointer *argv; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;

  int N ;
  char **quote_strings ;
  NNsubFuncTable nftab[] = NNSUBFUNCTABLE ;

  module=argv[0];
  
  for(N = 0 ; nftab[N].lispname != NULL ; N++) ;
  quote_strings = malloc(2 * N * sizeof(char*)) ;
{ int I ; 
  for(I = 0 ;  I < N ; I++) {  
       quote_strings[2 * I] = nftab[I].lispname ;
       quote_strings[2 * I + 1] = nftab[I].args ;
  }
}
  quotevec=build_quote_vector(ctx, 2 * N, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();

{ 
     int I ;

     for(I = 0 ; I < N ; I++) {
	  ctx->vsp=local+0;
	  compfun(ctx,fqv[2*I+0],module,nftab[I].funcname,fqv[2*I+1]);
     }
}

	local[0]= NIL;
	ctx->vsp=local; 
     return(local[0]);
}
static void init_ftab()
{}
