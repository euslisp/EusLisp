/****************************************************************/
/* EUSLISP vector and array functions
/*
/*	1987-Sep-24
/*	1996-Jan  Bignum return
/*	Copyright Toshihiro MATSUI,Electrotechinical Laboratory,1988.
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "../c/eus.h"

pointer MKVECTOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer v;
  register int i;
  v=makevector(C_VECTOR,n);
  for (i=0; i<n; i++) v->c.vec.v[i]=argv[i];
#ifdef SAFETY
  take_care(v);
#endif
  return(v);}

pointer MKINTVECTOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer v;
  register int i;
  v=makevector(C_INTVECTOR,n);
  for (i=0; i<n; i++) v->c.ivec.iv[i]=bigintval(argv[i]);
#ifdef SAFETY
  take_care(v);
#endif
  return(v);}

pointer vref(a,n)
	/*simple but not general vector (one dimensional) reference*/
register pointer a;
register int n;
{ register eusinteger_t x;
  numunion nu;
  if (n<0 || vecsize(a)<=n ) error(E_ARRAYINDEX);
  switch(elmtypeof(a)) {
    case ELM_FIXED: error(E_NOVECTOR);
    case ELM_CHAR:
    case ELM_BYTE:  return(makeint(a->c.str.chars[n]));
    case ELM_FLOAT: return(makeflt(a->c.fvec.fv[n]));
    case ELM_INT:  x=a->c.ivec.iv[n];  return(mkbigint(x));
#if (WORD_SIZE == 64)
    /*
			hanai: 32 was hard coded.
			This size must be equal to that of eusinteger_t.
			Constant 1 must be written as 1L.
			Otherwise 1 << 32 becomes 1, meaning 0x00000001.
			*/
    case ELM_BIT:  x=1L<<(n % 64); 
	            if (a->c.ivec.iv[n/64] & x) return(makeint(1));
		    else return(makeint(0));
#else
    case ELM_BIT:  x=1<<(n % 32); 
	            if (a->c.ivec.iv[n/32] & x) return(makeint(1));
		    else return(makeint(0));
#endif
    case ELM_FOREIGN: return(makeint(((byte *)(a->c.ivec.iv[0]))[n]));
    case ELM_POINTER:
    default: return(a->c.vec.v[n]);}}

pointer SVREF(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a=argv[0];
  ckarg(2);
  n=ckintval(argv[1]);
  if (n<0) error(E_ARRAYINDEX);
  if (isvector(a)) {
    if (elmtypeof(a)==ELM_POINTER) {
      if (vecsize(a)<=n) error(E_ARRAYINDEX);
      return(a->c.vec.v[n]);}
    else error(E_NOVECTOR);}
  else if (isnum(a)) error(E_NOVECTOR);
  else if (objsize(a)<=n) error(E_ARRAYINDEX);
  a=a->c.obj.iv[n];
  if (a==UNBOUND) return(QUNBOUND);
  return(a);}
 
pointer vset(a,n,newval)
register pointer a;
register int n;
pointer newval;
{ register int x,y;
  numunion nu;
  extern eusinteger_t coerceintval(pointer);

  if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
  switch(elmtypeof(a)) {
#if (WORD_SIZE == 64)
	case ELM_BIT:
		x=1L<<(n % 64);
		y=(ckintval(newval) & 1L)<<(n % 64);
		a->c.ivec.iv[n/64]=(a->c.ivec.iv[n/64] & (~ x)) | y;
	        return(newval);
#else
	case ELM_BIT:
		x=1<<(n % 32);
		y=(ckintval(newval) & 1)<<(n % 32);
		a->c.ivec.iv[n/32]=a->c.ivec.iv[n/32] & (~ x) | y;
	        return(newval);
#endif
	case ELM_BYTE: case ELM_CHAR:
		a->c.str.chars[n]=ckintval(newval); return(newval);
	case ELM_INT:
		a->c.ivec.iv[n]=coerceintval(newval);
		return(newval);
	case ELM_FLOAT:
		a->c.fvec.fv[n]=ckfltval(newval);  return(newval);
	case ELM_FOREIGN:
		((byte *)(a->c.ivec.iv[0]))[n]=ckintval(newval);
		return(newval);
	case ELM_POINTER:
        pointer_update(a->c.vec.v[n],newval);
		return(newval);} }

pointer SVSET(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0],newval=argv[2];
  ckarg(3);
  n=ckintval(argv[1]);
  if (n<0) error(E_ARRAYINDEX);
  if (isvector(a)) {
    if (elmtypeof(a)==ELM_POINTER) {
      if (vecsize(a)<=n) error(E_ARRAYINDEX);
      pointer_update(a->c.vec.v[n],newval);
      return(newval);}
    else error(E_NOVECTOR);}
  else if (isnum(a)) error(E_NOVECTOR);
  else if (objsize(a)<=n) error(E_ARRAYINDEX);
  pointer_update(a->c.obj.iv[n],newval);
  return(newval);}


/****************************************************************/
/* A R R A Y
/****************************************************************/

int arrayindex(a,n,indices)
register pointer a;
register int n;
register pointer *indices;
{ register int index=0,i1,i2;
  register pointer *dim=a->c.ary.dim,p1,p2;

  if (n!=intval(a->c.ary.rank)) error(E_ARRAYDIMENSION);
  while (n-- >0) {
    p1= *indices++;
    p2= *dim++;
    i1= ckintval(p1);
    i2= intval(p2);
    if (i1>=i2) error(E_ARRAYINDEX);
    index=index*i2 + i1; }
  return(index+intval(a->c.ary.offset));}
    
pointer AREF(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  register int i;
  if (n<2) error(E_MISMATCHARG);
  i=ckintval(argv[1]);
#if 0
  printf("aref %d\n", i);
#endif
  if (isvector(a)){ return(vref(a,i));}
#if 0 
  printf("aref ok\n");
#endif 
  if (!isarray(a)) error(E_NOARRAY);
  else return((pointer)vref(a->c.ary.entity,arrayindex(a,n-1,&argv[1])));}

pointer ASET(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  register pointer val=argv[n-1];

  if (n<3) error(E_MISMATCHARG);
  if (isvector(a))  return(vset(a,ckintval(argv[1]),val));
  if (!isarray(a)) error(E_NOARRAY);
  return(vset(a->c.ary.entity,arrayindex(a,n-2,&argv[1]),val));}

pointer ARRAYP(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  if (isnum(argv[0])) return(NIL);
  else if (isarray(argv[0])) return(T);
  else if (isvector(argv[0])) return(T);
  else return(NIL);}

pointer VECTORPOP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0],r;
  register int fp;

  ckarg(1);
  printf("vectorpop\n");
  if (!isarray(a)) error(E_NOARRAY);
  if (intval(a->c.ary.rank)!=1) error(E_ARRAYDIMENSION);
  fp=intval(a->c.ary.fillpointer);
  if (fp==0) error(E_ARRAYINDEX);
  fp--;
  r=(pointer)vref(a->c.ary.entity,fp+intval(a->c.ary.offset));
  a->c.ary.fillpointer=makeint(fp);
  return(r);}

pointer VECTORPUSH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[1];
  register int fp;

  ckarg(2);
  if (!isarray(a)) error(E_NOARRAY);
  if (intval(a->c.ary.rank)!=1) error(E_ARRAYDIMENSION);
  fp=ckintval(a->c.ary.fillpointer);
  vset(a->c.ary.entity,fp+intval(a->c.ary.offset),argv[0]);
  a->c.ary.fillpointer=makeint(fp+1);
  return(argv[0]);}

pointer VECTOREXPUSH(ctx,n,argv)	/*vector-push-extend*/
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[1],entity,new;
  register int i,fp,vsize;

  ckarg(2);
  if (!isarray(a)) error(E_NOARRAY);
  if (intval(a->c.ary.rank)!=1) error(E_ARRAYDIMENSION);
  fp=ckintval(a->c.ary.fillpointer);
  entity=a->c.ary.entity;
  vsize=vecsize(entity);
  if (fp>=vsize) {	/*extend vector*/
    new=makevector(classof(entity),fp*2);
    switch(elmtypeof(entity)) {
      case ELM_BIT: n=(vsize+WORD_SIZE-1)/WORD_SIZE; break;
      case ELM_CHAR: case ELM_BYTE: n=(vsize+sizeof(eusinteger_t))/sizeof(eusinteger_t); break;
      default: n=vsize;}
    for (i=0; i<n; i++) pointer_update(new->c.vec.v[i],entity->c.vec.v[i]);
    entity=new;
    pointer_update(a->c.ary.entity,entity);
    a->c.ary.dim[0]=makeint(fp*2);}
  vset(entity,fp,argv[0]);
  a->c.ary.fillpointer=makeint(fp+1);
  return(argv[0]);}

pointer VECTORP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  ckarg(1);
  if (ispointer(a)) return(elmtypeof(a)?T:NIL);
  else return(NIL);}

/****************************************************************/
/* bit vector
/****************************************************************/

#define isbitvector(p) (isvector(p) && (elmtypeof(p)==ELM_BIT))

pointer BIT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a=argv[0];
  eusinteger_t x;
  ckarg(2);
  n=ckintval(argv[1]);
#if (WORD_SIZE == 64)
  if (isbitvector(a)) {
    if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
    x=(a->c.ivec.iv[n/64]) & (1L<<(n % 64));
    return(makeint(x?1L:0L));}
#else
  if (isbitvector(a)) {
    if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
    x=(a->c.ivec.iv[n/32]) & (1<<(n % 32));
    return(makeint(x?1:0));}
#endif
  else error(E_BITVECTOR);}

pointer SETBIT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a=argv[0];
  int val;
  ckarg(3);
  n=ckintval(argv[1]);
  val=ckintval(argv[2]) & 1;
#if (WORD_SIZE == 64)
  if (isbitvector(a)) {
    if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
    if (val) a->c.ivec.iv[n/64]|=  (1L<<(n%64));
    else     a->c.ivec.iv[n/64]&= ~(1L<<(n%64));
    return(makeint(val));}
#else
  if (isbitvector(a)) {
    if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
    if (val) a->c.ivec.iv[n/32]|=  (1<<(n%32));
    else     a->c.ivec.iv[n/32]&= ~(1<<(n%32));
    return(makeint(val));}
#endif
  else error(E_BITVECTOR);}

pointer BITAND(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *bv2, *rbv, s; register long i=0;
  ckarg2(2,3);
  if (!isbitvector(argv[0]) || !isbitvector(argv[1])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (s!=vecsize(argv[1])) error(E_ARRAYINDEX);
  if (n==3) {
    result=argv[2];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; bv2=argv[1]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) {  rbv[i]=bv1[i] & bv2[i]; i++;}
  return(result);}

pointer BITIOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *bv2, *rbv, s; register long i=0;
  ckarg2(2,3);
  if (!isbitvector(argv[0]) || !isbitvector(argv[1])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (s!=vecsize(argv[1])) error(E_ARRAYINDEX);
  if (n==3) {
    result=argv[2];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; bv2=argv[1]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) {  rbv[i]=bv1[i] | bv2[i]; i++;}
  return(result);}

pointer BITXOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *bv2, *rbv, s; register long i=0;
  ckarg2(2,3);
  if (!isbitvector(argv[0]) || !isbitvector(argv[1])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (s!=vecsize(argv[1])) error(E_ARRAYINDEX);
  if (n==3) {
    result=argv[2];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; bv2=argv[1]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) {  rbv[i]=bv1[i] ^ bv2[i]; i++;}
  return(result);}

pointer BITEQV(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *bv2, *rbv, s; register long i=0;
  ckarg2(2,3);
  if (!isbitvector(argv[0]) || !isbitvector(argv[1])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (s!=vecsize(argv[1])) error(E_ARRAYINDEX);
  if (n==3) {
    result=argv[2];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; bv2=argv[1]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) {  rbv[i]= ~(bv1[i] ^ bv2[i]); i++;}
  return(result);}

pointer BITNAND(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *bv2, *rbv, s; register long i=0;
  ckarg2(2,3);
  if (!isbitvector(argv[0]) || !isbitvector(argv[1])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (s!=vecsize(argv[1])) error(E_ARRAYINDEX);
  if (n==3) {
    result=argv[2];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; bv2=argv[1]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) {  rbv[i]= ~(bv1[i] & bv2[i]); i++;}
  return(result);}

pointer BITNOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *bv2, *rbv, s; register long i=0;
  ckarg2(2,3);
  if (!isbitvector(argv[0]) || !isbitvector(argv[1])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (s!=vecsize(argv[1])) error(E_ARRAYINDEX);
  if (n==3) {
    result=argv[2];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; bv2=argv[1]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) {  rbv[i]= ~(bv1[i] | bv2[i]); i++;}
  return(result);}

pointer BITNOT(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer result;
  register eusinteger_t *bv1, *rbv, s; register long i=0;
  ckarg2(1,2);
  if (!isbitvector(argv[0])) error(E_BITVECTOR);
  s=vecsize(argv[0]);
  if (n==2) {
    result=argv[1];
    if (!isbitvector(result)) error(E_BITVECTOR);
    if (s!=vecsize(result)) error(E_ARRAYINDEX);}
  else result=makevector(C_BITVECTOR,s);
  bv1=argv[0]->c.ivec.iv; rbv=result->c.ivec.iv;
  while (i<(s+WORD_SIZE-1)/WORD_SIZE) { rbv[i]= ~bv1[i]; i++;}
  return(result);}

void vectorarray(ctx,mod)
register context *ctx;
pointer mod;
{
  defun(ctx,"AREF",mod,AREF,NULL);
  defun(ctx,"ASET",mod,ASET,NULL);
  defun(ctx,"VECTOR-POP",mod,VECTORPOP,NULL);
  defun(ctx,"VECTOR-PUSH",mod,VECTORPUSH,NULL);
  defun(ctx,"VECTOR-PUSH-EXTEND",mod,VECTOREXPUSH,NULL);
  defun(ctx,"ARRAYP",mod,ARRAYP,NULL);
  defun(ctx,"SVREF",mod,SVREF,NULL);
  defun(ctx,"SVSET",mod,SVSET,NULL);
  defun(ctx,"VECTOR",mod,MKVECTOR,NULL);
  defun(ctx,"VECTORP",mod,VECTORP,NULL);
  defun(ctx,"INTEGER-VECTOR",mod,MKINTVECTOR,NULL);
  defun(ctx,"BIT",mod,BIT,NULL);
  defun(ctx,"SBIT",mod,BIT,NULL);
  defun(ctx,"SETBIT",mod,SETBIT,NULL);
  defun(ctx,"BIT-AND",mod,BITAND,NULL);
  defun(ctx,"BIT-IOR",mod,BITIOR,NULL);
  defun(ctx,"BIT-XOR",mod,BITXOR,NULL);
  defun(ctx,"BIT-EQV",mod,BITEQV,NULL);
  defun(ctx,"BIT-NAND",mod,BITNAND,NULL);
  defun(ctx,"BIT-NOR",mod,BITNOR,NULL);
  defun(ctx,"BIT-NOT",mod,BITNOT,NULL);
  }
