/*
  FLOAT-VECTOR  <---> DOUBLE-VECTOR conversion in x86_64
*/

#include "eus.h"
#ifdef x86_64
extern pointer makefvector();
/*
  string converted by DV2FSTRING convert to float-vector(vector of 64bit float)
 */
static pointer FSTRING2DV(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer f=argv[0],d;
  double *fp;
  float *src;
  register int i,len;

  ckarg2(1,2);
  if (!isstring(f)) error(E_NOSTRING);
  len=strlength(f)/4;
  if (n==1) d=makefvector(len);
  else {
    d=argv[1];
    if (!isfltvector(d)) error(E_FLOATVECTOR);
    if (vecsize(d)<len) error(E_ARRAYINDEX);}
  for (i=0; i<len; i++) d->c.fvec.fv[i] = 0.0;
  fp = d->c.fvec.fv;
  src = (float *)f->c.str.chars;
  for (i=0; i<len; i++) {
    *fp++ = (double)src[i];
  }
  return(d);
}
/*
   float-vector in x86_64 (vector of 64bit float) convert to
   float[] as string
 */
static pointer DV2FSTRING(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer d=argv[0],f;
  double *fp;
  char *buf;
  register int i,len;
  union doublefloat {
    struct {char a,b,c,d;} cval;
    float fval;
  } f2d;

  ckarg2(1,2);
  if (!isfltvector(d)) error(E_FLOATVECTOR);
  len=vecsize(d)*4;
  if (n!=1) {
    f=argv[1];
    if (!isstring(f)) error(E_NOSTRING);
    if (strlength(f)<len) error(E_ARRAYINDEX);
  } else {
    // makestring
    f=alloc((len+2*sizeof(eusinteger_t))>>WORDSHIFT, ELM_CHAR,
            stringcp.cix, (len+2*sizeof(eusinteger_t))>>WORDSHIFT );
    f->c.str.length=makeint(len);
    f->c.ivec.iv[len/sizeof(long)]=0; /*terminator*/
    // memcpy((void *)p->c.str.chars, (void *)s, l);
  }
  fp=d->c.fvec.fv;
  buf = f->c.str.chars;
  for (i=0; i<len/4; i++) {
    f2d.fval = (float)*fp++;
    *buf++ = f2d.cval.a;
    *buf++ = f2d.cval.b;
    *buf++ = f2d.cval.c;
    *buf++ = f2d.cval.d;
  }
  return(f);
}
#endif
#if 0
pointer S2F(ctx,n,argv) /*short word to float*/
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
#endif
fstringdouble(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
#ifdef x86_64
  defun(ctx,"FSTRING2DOUBLE",mod,FSTRING2DV); 
  defun(ctx,"DOUBLE2FSTRING",mod,DV2FSTRING);
#endif
  //defun(ctx,"SHORT2FLOAT",mod,S2F);
  }
