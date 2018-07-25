/*****************************************************************
/* sigmoid function for neural network simulator
/* 1989Mar	Matsui T., ETL
/* 1990Apr	sigmoidx is added,
/*		load with :ld-option "-lm" to link tanh
/****************************************************************/

#include "eus.h"

static pointer SIGMOID(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ float x;
  double exp();
  x=fltval(argv[0]);
  return(makeflt(1.0/(1.0+exp(-x))));}

pointer SIGMOIDX(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ double x,u,s,th1,th2;
  double exp(), tanh();
  x=ckfltval(argv[0]); u=ckfltval(argv[1]);
  th1=ckfltval(argv[2]); th2=ckfltval(argv[3]);
  s=0.5*(1.0+tanh(x/u));
  if (s<th1) return(makeflt(th1));
  else if (s>th2) return(makeflt(th2));
  else return(makeflt(s));}

pointer OFFSET_VECTOR(ctx,n,argv)
context *ctx;
register int n;
register pointer argv[];
{ pointer v=argv[0];
  float x=ckfltval(argv[1]), *f;
  ckarg(2);
  if (!isfltvector(v)) error(E_FLOATVECTOR);
  f=v->c.fvec.fv;
  n=vecsize(v);
  while (--n>=0) f[n]+=x;
  return(v);}

pointer sigmoid(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
  defun(ctx,"SIGMOID",mod,SIGMOID,NULL);
  defun(ctx,"SIGMOIDX",mod,SIGMOIDX,NULL);
  defun(ctx,"OFFSET-VECTOR",mod,OFFSET_VECTOR,NULL);}

