/*
/* FLOAT-VECTOR  <---> DOUBLE-VECTOR conversion 
/* (c)1990 MATSUI Toshihiro, Electrotechnical Laboratory
/*
/* gcc -c -Di386 -DLinux -w -DGCC  -fpic  -I/usr/local/eus/include -O sync.c 
/* ld -shared -o floatdouble.so floatdouble.o
*/

#include "eus.h"
extern pointer makefvector();

static pointer F2D(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer f=argv[0],d;
  float  *fp;
  register int i,len;
  union doublefloat {
    struct {float low,high;} fval;
    double dval;
  } f2d;

  ckarg2(1,2);
  if (!isfltvector(f)) error(E_FLOATVECTOR);
  len=vecsize(f);
  if (n==1) d=makefvector(len*2);
  else {
    d=argv[1];
    if (!isfltvector(d)) error(E_FLOATVECTOR);
    if (vecsize(d)<2*len) error(E_ARRAYINDEX);}
  for (i=0; i<len*2; i++) d->c.fvec.fv[i] = 0.0;
  fp=d->c.fvec.fv;
  for (i=0; i<len; i++) {
    f2d.dval = (double)f->c.fvec.fv[i]; 
    *fp++ = f2d.fval.low; *fp++ = f2d.fval.high;}
  return(d);}

static pointer D2F(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer d=argv[0],f;
  float *fp;
  register int i,len;
  union doublefloat {
    struct {float low,high;} fval;
    double dval;
  } f2d;

  ckarg2(1,2);
  if (!isfltvector(d)) error(E_FLOATVECTOR);
  len=(vecsize(d)+1)/2;
  if (n==1) f=makefvector(len);
  else {
    f=argv[1];
    if (!isfltvector(f)) error(E_FLOATVECTOR);
    if (vecsize(f)<len) error(E_ARRAYINDEX);}
  fp=d->c.fvec.fv;
  for (i=0; i<len; i++) {
    f2d.fval.low = *fp++; f2d.fval.high = *fp++;
    f->c.fvec.fv[i]= (float)f2d.dval;}
  return(f);}

pointer S2F(ctx,n,argv)	/*short word to float*/
context *ctx;
int n;
pointer argv[];
{ pointer s=argv[0],f;
  register float *fp;
  register short *sp;
  register int i,len,v;
  register float factor;
  numunion nu;

  ckarg2(1,3);
  if (!isstring(s)) error(E_NOSTRING);
  len=(vecsize(s)+1)/2;
  if (n>=2) factor=ckfltval(argv[1]); else factor=1.0;
  if (n<3) f=makefvector(len);
  else {
    f=argv[2];
    if (!isfltvector(f)) error(E_FLOATVECTOR);
    if (vecsize(f)<len) error(E_ARRAYINDEX);}
  fp=f->c.fvec.fv;
  sp=(short *)s->c.str.chars;
  for (i=0; i<len; i++) fp[i]= sp[i] * factor;
  return(f);}

floatdouble(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
  defun(ctx,"FLOAT2DOUBLE",mod,F2D,NULL);
  defun(ctx,"DOUBLE2FLOAT",mod,D2F,NULL);
  defun(ctx,"SHORT2FLOAT",mod,S2F,NULL);
  }


