/*
  FLOAT-VECTOR  <---> DOUBLE-VECTOR conversion in x86_64
*/

#include "eus.h"
#if (WORD_SIZE == 64)
extern pointer makefvector();
/*
  string converted by DV2FSTRING convert to float-vector(vector of 64bit float)
  float-bytestring2dvector str [ fvec ]
  str  : string or address of float[]
  fvec : float-vector. If str is address, fvec should be set
*/
static pointer FSTRING2DV(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer f=argv[0],d;
  double *fp;
  float *src=NULL;
  register int i,len=-1;

  ckarg2(1,2);
  if (isint (f)) {
    src = (float *)(intval(f));
  } else {
    if (!isstring(f)) error(E_NOSTRING);
    len = strlength(f)/4;
    src = (float *)f->c.str.chars;
  }

  if (n == 1) {
    if(len < 0) error(E_FLOATVECTOR);
    d = makefvector(len);
    vpush(d);
  } else {
    d = argv[1];
    if (len < 0) len = vecsize(d);
    if (!isfltvector(d)) error(E_FLOATVECTOR);
    if (vecsize(d)<len) error(E_ARRAYINDEX);
  }
  //for (i=0; i<len; i++) d->c.fvec.fv[i] = 0.0;
  fp = d->c.fvec.fv;
  for (i=0; i<len; i++) {
    *fp++ = (double)src[i];
  }
  if(n != 1) return (d);
  return (vpop());
}
/*
   float-vector in x86_64 (vector of 64bit float) convert to float[] as string
   dvector2float-bytestring fvec [ str ]
   fvec : float-vector
   str  : string or address of float[]
*/
static pointer DV2FSTRING(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer d=argv[0],f;
  double *fp;
  char *buf=NULL;
  register int i,len;
  union doublefloat {
    struct {char a,b,c,d;} cval;
    float fval;
  } f2d;

  ckarg2(1,2);
  if (!isfltvector(d)) error(E_FLOATVECTOR);
  len=vecsize(d)*4;
  fp = d->c.fvec.fv;

  if (n != 1) {
    f=argv[1];
    if (isint(f)) {
      buf = (char *)intval(f);
    } else {
      if (!isstring(f)) error(E_NOSTRING);
      if (strlength(f)<len) error(E_ARRAYINDEX);
    }
  } else {
    // makestring
    f=alloc((len+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR,
            stringcp.cix, (len+2*sizeof(eusinteger_t))>>WORDSHIFT );
    vpush(f);
    f->c.str.length=makeint(len);
    f->c.ivec.iv[len/sizeof(eusinteger_t)] = 0; /*terminator*/
    // memcpy((void *)p->c.str.chars, (void *)s, l);
  }

  if(buf == NULL) buf = f->c.str.chars;
  for (i=0; i<len/4; i++) {
    f2d.fval = (float)*fp++;
    *buf++ = f2d.cval.a;
    *buf++ = f2d.cval.b;
    *buf++ = f2d.cval.c;
    *buf++ = f2d.cval.d;
  }
  if(n != 1) return(f);
  return(vpop());
}
/*
  string converted by LV2ISTRING convert to integer-vector(vector of 64bit integer)
  integer-bytestring2lvector str [ ivec ]
  str  : string or address of int[]
  ivec : integer-vector. If str is address, ivec should be set
*/
static pointer ISTRING2LV(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer f=argv[0],d;
  long *fp;
  int *src=NULL;
  register int i,len=-1;

  ckarg2(1,2);
  if (isint (f)) {
    src = (int *)(intval(f));
  } else {
    if (!isstring(f)) error(E_NOSTRING);
    len = strlength(f)/4;
    src = (int *)f->c.str.chars;
  }

  if (n == 1) {
    if(len < 0) error(E_NOINTVECTOR);
    d = makevector(C_INTVECTOR,len);
    vpush(d);
  } else {
    d = argv[1];
    if (len < 0) len = vecsize(d);
    if (!isintvector(d)) error(E_NOINTVECTOR);
    if (vecsize(d)<len) error(E_ARRAYINDEX);
  }
  //for (i=0; i<len; i++) d->c.fvec.fv[i] = 0.0;
  fp = d->c.ivec.iv;
  for (i=0; i<len; i++) {
    *fp++ = (long)src[i];
  }
  if(n != 1) return d;
  return(vpop());
}
/*
   integer-vector in x86_64 (vector of 64bit integer) convert to int[] as string
   lvector2integer-bytestring ivec [ str ]
   ivec : integer-vector
   str  : string or address of int[]
*/
static pointer LV2ISTRING(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer d=argv[0],f;
  long *fp;
  char *buf = NULL;
  register int i,len;
  union intchar {
    struct {char a,b,c,d;} cval;
    int ival;
  } i2l;

  ckarg2(1,2);
  if (!isintvector(d)) error(E_NOINTVECTOR);
  len=vecsize(d)*4;
  fp = d->c.ivec.iv;

  if (n != 1) {
    f=argv[1];
    if (isint(f)) {
      buf = (char *)intval(f);
    } else {
      if (!isstring(f)) error(E_NOSTRING);
      if (strlength(f)<len) error(E_ARRAYINDEX);
    }
  } else {
    // makestring
    f=alloc((len+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR,
            stringcp.cix, (len+2*sizeof(eusinteger_t))>>WORDSHIFT );
    vpush(f);
    f->c.str.length=makeint(len);
    f->c.ivec.iv[len/sizeof(eusinteger_t)] = 0; /*terminator*/
    // memcpy((void *)p->c.str.chars, (void *)s, l);
  }
  if(buf == NULL) buf = f->c.str.chars;
  for (i=0; i<len/4; i++) {
    i2l.ival = (int)*fp++;
    *buf++ = i2l.cval.a;
    *buf++ = i2l.cval.b;
    *buf++ = i2l.cval.c;
    *buf++ = i2l.cval.d;
  }
  if(n != 1) return f;
  return(vpop());
}
#endif
#ifdef i386
extern pointer makefvector();
/*
  string converted by FV2DSTRING convert to float-vector(vector of 32bit float)
  double-bytestring2fvector str [ fvec ]
  str  : string or address of double[]
  fvec : float-vector. If str is address, fvec should be set.
*/
static pointer DSTRING2FV(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer f=argv[0], d;
  float *fp;
  double *src=NULL;
  register int i, len=-1;

  ckarg2(1,2);
  if (isint (f)) {
    src = (double *)(intval(f));
  } else {
    if (!isstring(f)) error(E_NOSTRING);
    len = strlength(f)/8;
    src = (double *)f->c.str.chars;
  }

  if (n == 1) {
    if(len < 0) error(E_FLOATVECTOR);
    d = makefvector(len);
    vpush (d);
  } else {
    d = argv[1];
    if (len < 0) len = vecsize(d);
    if (!isfltvector(d)) error(E_FLOATVECTOR);
    if (vecsize(d)<len) error(E_ARRAYINDEX);
  }
  //for (i=0; i<len; i++) d->c.fvec.fv[i] = 0.0;
  fp = d->c.fvec.fv;
  for (i = 0; i < len; i++) {
    *fp++ = (float)src[i];
  }
  if(n != 1) return (d);
  return (vpop());
}
/*
   float-vector in i386 (vector of 32bit float) convert to double[] as string
   fvector2double-bytestring fvec [ str ]
   fvec : float-vector
   str  : string or address of double[]
*/
static pointer FV2DSTRING(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer d=argv[0], f;
  float *fp;
  char *buf = NULL;
  register int i, len;
  union doublefloat {
    struct {char a,b,c,d,e,f,g,h;} cval;
    double fval;
  } f2d;

  ckarg2(1,2);
  if (!isfltvector(d)) error(E_FLOATVECTOR);
  len = vecsize(d) * 8;
  fp = d->c.fvec.fv;

  if (n != 1) {
    f=argv[1];
    if (isint(f)) {
      buf = (char *)intval(f);
    } else {
      if (!isstring(f)) error(E_NOSTRING);
      if (strlength(f)<len) error(E_ARRAYINDEX);
    }
  } else {
    f=alloc((len+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR,
            stringcp.cix, (len+2*sizeof(eusinteger_t))>>WORDSHIFT);
    vpush(f);
    f->c.str.length = makeint(len);
    f->c.ivec.iv[len/sizeof(eusinteger_t)] = 0; /*terminator*/
    // memcpy((void *)p->c.str.chars, (void *)s, l);
  }

  if(buf == NULL) buf = f->c.str.chars;
  for (i=0; i < len/8; i++) {
    f2d.fval = (double)*fp++;
    *buf++ = f2d.cval.a;
    *buf++ = f2d.cval.b;
    *buf++ = f2d.cval.c;
    *buf++ = f2d.cval.d;
    *buf++ = f2d.cval.e;
    *buf++ = f2d.cval.f;
    *buf++ = f2d.cval.g;
    *buf++ = f2d.cval.h;
  }
  if(n != 1) return(f);
  return(vpop());
}
/*
  string converted by IV2LSTRING convert to integer-vector(vector of 32bit integer)
  long-long-bytestring2ivector str [ ivec ]
  str  : string or address of int[]
  ivec : integer-vector. If str is address, ivec should be set
*/
static pointer LSTRING2IV(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer f=argv[0],d;
  int *fp;
  long long *src=NULL;
  register int i, len=-1;

  ckarg2(1,2);
  if (isint (f)) {
    src = (long long *)(intval(f));
  } else {
    if (!isstring(f)) error(E_NOSTRING);
    len = strlength(f) / 8;
    src = (long long *)f->c.str.chars;
  }

  if (n == 1) {
    if(len < 0) error(E_NOINTVECTOR);
    d = makevector(C_INTVECTOR, len);
    vpush(d);
  } else {
    d = argv[1];
    if (len < 0) len = vecsize(d);
    if (!isintvector(d)) error(E_NOINTVECTOR);
    if (vecsize(d)<len) error(E_ARRAYINDEX);
  }
  fp = d->c.ivec.iv;
  for (i = 0; i < len; i++) {
    *fp++ = (int)src[i];
  }
  if(n != 1) return d;
  return (vpop());
}
/*
   integer-vector in i386 (vector of 32bit integer) convert to long long[] as string
   ivector2long-long-bytestring ivec [ str ]
   ivec : integer-vector
   str  : string or address of long long[]
*/
static pointer IV2LSTRING(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer d = argv[0],f;
  int *fp;
  char *buf = NULL;
  register int i, len;
  union intchar {
    struct {char a,b,c,d,e,f,g,h;} cval;
    long long ival;
  } i2l;

  ckarg2(1,2);
  if (!isintvector(d)) error(E_NOINTVECTOR);
  len = vecsize(d) * 8;
  fp = d->c.ivec.iv;

  if (n != 1) {
    f = argv[1];
    if (isint(f)) {
      buf = (char *)intval(f);
    } else {
      if (!isstring(f)) error(E_NOSTRING);
      if (strlength(f)<len) error(E_ARRAYINDEX);
    }
  } else {
    // makestring
    f=alloc((len+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR,
            stringcp.cix, (len+2*sizeof(eusinteger_t))>>WORDSHIFT);
    vpush(f);
    f->c.str.length = makeint(len);
    f->c.ivec.iv[len/sizeof(eusinteger_t)] = 0; /*terminator*/
    // memcpy((void *)p->c.str.chars, (void *)s, l);
  }
  if(buf == NULL) buf = f->c.str.chars;
  for (i=0; i<len/4; i++) {
    i2l.ival = (int)*fp++;
    *buf++ = i2l.cval.a;
    *buf++ = i2l.cval.b;
    *buf++ = i2l.cval.c;
    *buf++ = i2l.cval.d;
    *buf++ = i2l.cval.e;
    *buf++ = i2l.cval.f;
    *buf++ = i2l.cval.g;
    *buf++ = i2l.cval.h;
  }
  if(n != 1) return f;
  return (vpop());
}
#endif
int fstringdouble(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
#if (WORD_SIZE == 64)
  defun(ctx,"FLOAT-BYTESTRING2DVECTOR",mod,FSTRING2DV,NULL);
  defun(ctx,"DVECTOR2FLOAT-BYTESTRING",mod,DV2FSTRING,NULL);
  defun(ctx,"INTEGER-BYTESTRING2LVECTOR",mod,ISTRING2LV,NULL);
  defun(ctx,"LVECTOR2INTEGER-BYTESTRING",mod,LV2ISTRING,NULL);
#endif
#ifdef i386
  defun(ctx,"DOUBLE-BYTESTRING2FVECTOR",mod,DSTRING2FV,NULL);
  defun(ctx,"FVECTOR2DOUBLE-BYTESTRING",mod,FV2DSTRING,NULL);
  defun(ctx,"LONG-LONG-BYTESTRING2IVECTOR",mod,LSTRING2IV,NULL);
  defun(ctx,"IVECTOR2LONG-LONG-BYTESTRING",mod,IV2LSTRING,NULL);
#endif
  }
