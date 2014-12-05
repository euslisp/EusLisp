#include "../eus.h"

pointer FFT(n,argv)
int n;
pointer argv[];
{ pointer a;
  int size;
  float *wsave;

  ckarg(1);
  a=argv[0];
  if (!isfltvector(a)) error(E_FLOATVECTOR);
  size=vecsize(a);
  wsave=(float *)malloc((size*3+15)*sizeof(float));
  rffti_(&size,wsave);
  rfftf_(&size,a->c.fvec.fv,wsave);
  free(wsave);
  return(a);}

pointer INVFFT(n,argv)
int n;
pointer argv[];
{ pointer a;
  int size;
  float *wsave;

  ckarg(1);
  a=argv[0];
  if (!isfltvector(a)) error(E_FLOATVECTOR);
  size=vecsize(a);
  wsave=(float *)malloc((size*3+15)*sizeof(float));
  rffti_(&size,wsave);
  rfftb_(&size,a->c.fvec.fv,wsave);
  free(wsave);
  return(a);}

eusmain(mod)
pointer mod;
{
  defun("FFT",mod,FFT,NULL);
  defun("INVERSE-FFT",mod,INVFFT,NULL);
  }
