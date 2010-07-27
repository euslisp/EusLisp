/*
  Arguments converter for C programming of EUSLISP
  By M.Inaba
  */
#include "../c/eus.h"
#include "euslocal.h"
#define TRUE 1
#define NULL 0
#define is_view_num(v) \
  (isnum(v)|| isstring(v) || ((v)== T) || ((v) == NIL))   

cknumtoint(v)
     pointer v;
{
  if (isint(v)) return(intval(v));
  else if (isflt(v)) return(fltval(v));
  else if (isstring(v)) return((int)(v->c.str.chars));
  else if (T == v) return(TRUE);
  else if (NIL == v) return(NULL);
  else error(E_NONUMBER);
}
float cknumtoflt(v)
     pointer v;
{
  if (isint(v)) return((float)intval(v));
  else if (isflt(v)) return(fltval(v));
  else error(E_NONUMBER);
}

pointer makebool(v)
     long v;
{
  if (v) return(T);
  else return(NIL);
}

pointer makebnum(v)
     register long v;
{
  pointer b;
  int w;
  w = -v;
  if ((v > 0) && (v > 0x1fffffff)) {
    b = makevector(C_INTVECTOR,1);
    b -> c.ivec.iv[0] = v;
  }
  else if ((w > 0) && (w > 0x1fffffff)) {
    b = makevector(C_INTVECTOR,1);
    b -> c.ivec.iv[0] = v;
  }
  else b = makeint(v);
  return(b);
}

  
static int argc;
static float *fargv;
static int *iargv;

trans_argv_iargv(n,argv,main_iargv)
     register int n;
     register pointer argv[];
     register int main_iargv[];
{
  iargv = main_iargv;
  argc = 0;
  while (n-- >0) trans_argv_iargv_aux(*argv++);
  return(argc);
}
trans_argv_iargv_aux(a)
     register pointer a;
{
  register int j,size;
  if (is_view_num(a)) { *iargv++ = cknumtoint(a); argc++;}
  else if (T == a) { *iargv++ = TRUE; argc++; }
  else if (NIL == a) { *iargv++ = NULL; argc++; }
  else if (isfltvector(a)) {
    size=vecsize(a); argc+= size;
    for (j=0; j<size; j++) *iargv++ = (int)a->c.fvec.fv[j];
  }
  else if (isintvector(a)) {
    size=vecsize(a); argc+= size;
    for (j=0; j<size; j++) *iargv++ = (int)a->c.ivec.iv[j];
  }
  else if (isarray(a)) {
    trans_argv_iargv_aux(a->c.ary.entity);
  }
  else if (isvector(a)) {
    size=vecsize(a);
    for (j=0; j<size; j++) trans_argv_iargv_aux(a->c.vec.v[j]);
  }
  else if (islist(a)) {
    while (islist(a)) {
      trans_argv_iargv_aux(ccar(a));
      a=ccdr(a);}
  }
  else error(E_NOINT);
}

trans_argv_fargv(n,argv,main_fargv)
     register int n;
     register pointer argv[];
     register float main_fargv[];
{
  fargv = main_fargv;
  argc = 0;
  while (n-- >0) trans_argv_fargv_aux(*argv++);
  return(argc);
}
trans_argv_fargv_aux(a)
     register pointer a;
{
  register int j,size;
  if (is_view_num(a)) {
    *fargv++ = (float)cknumtoflt(a); argc++;
  }
  else if (isfltvector(a)) {
    size=vecsize(a); argc += size;
    for (j=0; j<size; j++) *fargv++ = a->c.fvec.fv[j];
  }
  else if (isintvector(a)) {
    size=vecsize(a); argc+= size;
    for (j=0; j<size; j++) *fargv++ = (float)a->c.ivec.iv[j];
  }
  else if (isarray(a)) {
    trans_argv_fargv_aux(a->c.ary.entity);
  }
  else if (isvector(a)) {
    size=vecsize(a);
    for (j=0; j<size; j++) trans_argv_fargv_aux(a->c.vec.v[j]);
  }
  else if (islist(a)) {
    while (islist(a)) {
      trans_argv_fargv_aux(ccar(a));
      a=ccdr(a);
    }
  }
  else error(E_NONUMBER);
}

trans_argv_farrayargv(n,argv,dimension,farrayargv)
     register int n;
     register pointer *argv;
     register float *farrayargv;
     register int dimension;
{
  register float fargv[3*256];
  register int i,j,size,rem;
  size=trans_argv_fargv(n,argv,fargv);
  /*
    printf("size=%d,dim=%d,amari=%d\n",size,dimension,size%dimension);
    */
  if ((size % dimension) != 0) error(E_MISMATCHARG);
  size /= dimension;
  for (j=0; j<dimension; j++) {
    for (i=0; i<size; i++)
      *farrayargv++ = fargv[i*dimension + j];
  }
  return(size);
}

largv2cargv(n,argv,cargv,from,to)
     register int n;
     register pointer argv[];
     register long cargv[];
     int from,to;
{
  register int i,cargc=0;
  register pointer l;
  cargc = trans_argv_iargv(n,argv,cargv);
  if ((cargc<from) || (cargc>to)) error(E_MISMATCHARG);
  return(cargc);
}
