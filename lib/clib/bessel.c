#include <math.h>
#include "eus.h"

extern double jn(), yn();

pointer BESSEL(ctx,n,argv)
int n;
pointer argv[];
{ int i=ckintval(argv[0]);
  numunion nu;
  float f = ckfltval(argv[1]);
  ckarg(2);
  f=jn(i,f);
  return(makeflt(f));}

bessel(ctx,n,argv,env)
context *ctx;
int n;
pointer argv[], *env;
{ defun(ctx, "BESSEL", argv[0], BESSEL,NULL);}
