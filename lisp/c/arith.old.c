/****************************************************************/
/* arith.c  EULISP arithmetic functions			
/* Copyright(c)1988 Toshihiro MATSUI, Electrotechnical Laboratory
/*	1986-May
.*	1988-Feb	boxing and unboxing recoded by macros
/****************************************************************/

static char *rcsid="@(#)$Id$";

#include "eus.h"
#include <math.h>
#if alpha
#include <limits.h>
#endif

extern pointer RANDSTATE;
extern int gcd();
extern pointer makeratio();

extern pointer copy_big(), big_plus(), big_minus();
extern         sub_int_big(), add_int_big();
extern pointer add_big_big(), big_times();
extern pointer makebig(), makebig1(), makebig2(), extend_big(pointer,int);
extern pointer normalize_bignum();
extern eusfloat_t big_to_float(pointer);
extern pointer eusfloat_to_big(float);
extern eusinteger_t big_sign(pointer);

/****************************************************************/
/* number predicates
/****************************************************************/
pointer NUMEQUAL(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusfloat_t fx,fy;
  register pointer a,x;
  numunion nu;

  if (n<=1) error(E_MISMATCHARG);
  x=argv[--n];
  if (isint(x)) {
    while (--n>=0) {
      a=argv[n];
      if (isflt(a)) { fx=intval(x); fy=fltval(a); goto flteqnum;}
      else if (isint(a)) { if (x!=a) return(NIL);}
      else if (pisratio(a)) { x=makeratio(intval(x),1); goto reqnum;}
      else  error(E_NONUMBER);}
    return(T);}
  else if (isratio(x)) {
    while (--n>=0) {
      a=argv[n];
      if (isflt(a)) { fx=ratio2flt(x); fy=fltval(a); goto flteqnum;}
      else if (isint(a)) a=makeratio(intval(a),1);
      else if (!pisratio(a))  error(E_NONUMBER);
reqnum:
      if ((a->c.ratio.numerator != x->c.ratio.numerator) ||
          (a->c.ratio.denominator != x->c.ratio.denominator))
        return(NIL);}
    return(T);}
  else  if (isflt(x)) {
    fx=fltval(x);
    while (--n>=0) {
      fy=ckfltval(argv[n]);
flteqnum:
      if (fx!=fy) return(NIL);}
    return(T); }
  else if (pisbignum(x)) 
    { eusinteger_t *xv, *av;
      int size,i;
      xv=bigvec(x); size=bigsize(x);
      while (--n >=0) {
        a=argv[n];
        if (!isbignum(a)) return(NIL);
	if (size != bigsize(a)) return(NIL);
	av=bigvec(a);
	for (i=0; i<size; i++) if (xv[i]!=av[i]) return(NIL);}
      return(T); }
  else error(E_NONUMBER);}


pointer GREATERP(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer left,right;
  register eusfloat_t fleft,fright;
  eusinteger_t ival;
  eusinteger_t sign;
  int comparison;
  numunion nu;

  if (n<=1) error(E_MISMATCHARG);
  right=argv[--n];

  if (isint(right)) goto INTGT;
  else if (isflt(right))  goto FLTGT;
  else if (pisratio(right)) goto RATGT;
  else if (pisbignum(right)) goto BIGGT;
  else error(E_NONUMBER);

INTGT:
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      if ((eusinteger_t)left <= (eusinteger_t)right) return(NIL); }
    else if (isflt(left)) { fright=intval(right); goto fltgt2;}
    else if (isbignum(left)) {
      if (big_sign(left)<0) return(NIL); 
      right=left; goto BIGGT; }
    if (!isint(left)) error(E_NONUMBER);
    right=left;}
  return(T);

BIGGT:
  sign=big_sign(right);
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      ival= intval(left);
      if (sign>=0) return(NIL);
      right=left;
      goto INTGT; }
    else if (isflt(left)) {
      fright=big_to_float(right);
      if (fltval(left)<=fright) return(NIL);
      goto FLTGT1;}
    else if (pisbignum(left)) {
      comparison=big_compare(left, right);
      if (comparison<=0) return(NIL);
      right=left;
      sign=big_sign(right);}
    else if (isratio(left)) goto RATGT; }
FLTGT:
  fright=fltval(right);
FLTGT1:
  while (--n>=0) {
    fltgt2:  fleft=ckfltval(argv[n]);
    if (fleft<=fright) return(NIL);
    fright=fleft; }
  return(T); 
RATGT:
  error(E_USER,(pointer)"sorry, comparison of ratios are not yet implemented");
  }

pointer LESSP(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer left,right;
  register eusfloat_t fleft,fright;
  eusinteger_t ival;
  eusinteger_t sign;
  int comparison;
  numunion nu;

  if (n<=1) error(E_MISMATCHARG);
  right=argv[--n];

  if (isint(right)) goto INTLT;
  else if (isflt(right))  goto FLTLT;
  else if (pisratio(right)) goto RATLT;
  else if (pisbignum(right)) goto BIGLT;
  else error(E_NONUMBER);

INTLT:
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      if ((eusinteger_t)left >= (eusinteger_t)right) return(NIL); }
    else if (isflt(left)) { fright=intval(right); goto FLTLT2;}
    else if (isbignum(left)) {
      if (big_sign(left)>0) return(NIL); 
      right=left; goto BIGLT; }
    if (!isint(left)) error(E_NONUMBER);
    right=left;}
  return(T);

BIGLT:
  sign=big_sign(right);
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      ival= intval(left);
      if (sign<0) return(NIL);
      right=left;
      goto INTLT; }
    else if (isflt(left)) {
      fright=big_to_float(right);
      if (fltval(left)>=fright) return(NIL);
      goto FLTLT1;}
    else if (pisbignum(left)) {
      comparison=big_compare(left, right);
      if (comparison>=0) return(NIL);
      right=left;
      sign=big_sign(right);}
    else if (isratio(left)) goto RATLT; }
FLTLT:
  fright=fltval(right);
FLTLT1:
  while (--n>=0) {
    FLTLT2:  fleft=ckfltval(argv[n]);
    if (fleft>=fright) return(NIL);
    fright=fleft; }
  return(T); 
RATLT:
  error(E_USER,(pointer)"sorry, comparison of ratios are not yet implemented");
  }

pointer GREQP(ctx,n,argv)	
register context *ctx;
register int n;
register pointer argv[];
{ register pointer left,right;
  register eusfloat_t fleft,fright;
  eusinteger_t ival;
  eusinteger_t sign;
  int comparison;
  numunion nu;

  if (n<=1) error(E_MISMATCHARG);
  right=argv[--n];

  if (isint(right)) goto INTGE;
  else if (isflt(right))  goto FLTGE;
  else if (pisratio(right)) goto RATGE;
  else if (pisbignum(right)) goto BIGGE;
  else error(E_NONUMBER);

INTGE:
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      if ((eusinteger_t)left < (eusinteger_t)right) return(NIL); }
    else if (isflt(left)) { fright=intval(right); goto FLTGE2;}
    else if (isbignum(left)) {
      if (sign=big_sign(left)<0) return(NIL);
      right=left; goto BIGGE; }
    if (!isint(left)) error(E_NONUMBER);
    right=left;}
  return(T);

BIGGE:
  sign=big_sign(right);
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      ival= intval(left);
      if (sign>0) return(NIL);
      right=left;
      goto INTGE; }
    else if (isflt(left)) {
      fright=big_to_float(right);
      if (fltval(left)<fright) return(NIL);
      goto FLTGE1;}
    else if (pisbignum(left)) {
      comparison=big_compare(left, right);
      if (comparison<0) return(NIL);
      right=left;
      sign=big_sign(right);}
    else if (isratio(left)) goto RATGE; }
FLTGE:
  fright=fltval(right);
FLTGE1:
  while (--n>=0) {
    FLTGE2:  fleft=ckfltval(argv[n]);
    if (fleft<fright) return(NIL);
    fright=fleft; }
  return(T); 
RATGE:
  error(E_USER,(pointer)"sorry, comparison of ratios are not yet implemented");
  }

pointer LSEQP(ctx,n,argv)	/*less-or-equalp*/
register context *ctx;
int n;
pointer argv[];
{ register pointer left,right;
  register eusfloat_t fleft,fright;
  eusinteger_t ival;
  eusinteger_t sign;
  int comparison;
  numunion nu;

  if (n<=1) error(E_MISMATCHARG);
  right=argv[--n];

  if (isint(right)) goto INTLE;
  else if (isflt(right))  goto FLTLE;
  else if (pisratio(right)) goto RATLE;
  else if (pisbignum(right)) goto BIGLE;
  else error(E_NONUMBER);

INTLE:
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      if ((eusinteger_t)left > (eusinteger_t)right) return(NIL); }
    else if (isflt(left)) { fright=intval(right); goto FLTLE2;}
    else if (isbignum(left)) {
      if (sign=big_sign(left)>0) return(NIL);
      right=left; goto BIGLE; }
    if (!isint(left)) error(E_NONUMBER);
    right=left;}
  return(T);

BIGLE:
  sign=big_sign(right);
  while (--n>=0) {
    left=argv[n];
    if (isint(left)) {
      ival= intval(left);
      if (sign<0) return(NIL);
      right=left;
      goto INTLE; }
    else if (isflt(left)) {
      fright=big_to_float(right);
      if (fltval(left) > fright) return(NIL);
      goto FLTLE1;}
    else if (pisbignum(left)) {
      comparison=big_compare(left, right);
      if (comparison > 0) return(NIL);
      right=left;
      sign=big_sign(right);}
    else if (isratio(left)) goto RATLE; }
FLTLE:
  fright=fltval(right);
FLTLE1:
  while (--n>=0) {
    FLTLE2:  fleft=ckfltval(argv[n]);
    if (fleft > fright) return(NIL);
    fright=fleft; }
  return(T); 
RATLE:
  error(E_USER,(pointer)"sorry, comparison of ratios are not yet implemented");
  }

pointer MOD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register eusinteger_t x,y;
  ckarg(2);
  x=ckintval(argv[0]); y=ckintval(argv[1]);
  return(makeint(x % y));}

pointer SUB1(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  eusfloat_t x;
  numunion nu;

  ckarg(1);
  if (a==makeint(MINNEGFIXNUM)) { return(makebig1(MINNEGFIXNUM-1));}
  if (isint(a)) return((pointer)((eusinteger_t)a-4));
  else if (isflt(a)) {
    x=fltval(a);
    return(makeflt(x-1.0)); }
  else if (isbignum(a)) {
    a=copy_big(a); sub_int_big(1,a); return(normalize_bignum(a));}
  else error(E_NOINT);
  }


pointer ADD1(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  float x;
  numunion nu;

  ckarg(1);
  if (a==makeint(MAXPOSFIXNUM)) { return(makebig1(MAXPOSFIXNUM+1));}
  if (isint(a)) return((pointer)((eusinteger_t)a+4));
  else if (isflt(a)) {
    x=fltval(a);
    return(makeflt(x+1.0)); }
  else if (isbignum(a)) {
    a=copy_big(a); add_int_big(1,a); return(a);}
  else error(E_NOINT);
  }

/* extended numbers */

pointer ratio_plus(x,y)
pointer x,y;
{
  register eusinteger_t x_num, x_den, y_num, y_den, z_num, z_den, d1,d2,t;

  x_num = intval(x->c.ratio.numerator);
  x_den = intval(x->c.ratio.denominator);
  y_num = intval(y->c.ratio.numerator);
  y_den = intval(y->c.ratio.denominator);
  
  d1=gcd(x_den,y_den);
  if(d1 == 1){
  z_num = x_num * y_den + x_den * y_num;
  z_den = x_den * y_den;
  return(makeratio(z_num,z_den));}
  else{
    t = x_num * (y_den / d1) + y_num * (x_den / d1);
    d2=gcd(t,d1);
    
    z_num = t / d2;
    z_den = (x_den / d1) * (y_den / d2);
    return(makeratio(z_num,z_den));}
}

pointer ratio_minus(x,y)
pointer x,y;
{
  register eusinteger_t x_num,x_den,y_num,y_den,z_num,z_den,d1,d2,t;

  x_num = intval(x->c.ratio.numerator);
  x_den = intval(x->c.ratio.denominator);
  y_num = intval(y->c.ratio.numerator);
  y_den = intval(y->c.ratio.denominator);
  d1 = gcd(x_den,y_den);
  if(d1 == 1){
    z_num = x_num * y_den - x_den * y_num;
    z_den = x_den * y_den;
  return(makeratio(z_num,z_den));}
  else{
    t = x_num * (y_den / d1) - y_num * (x_den / d1);
    d2=gcd(t,d1);
    z_num = t / d2;
    z_den = (x_den / d1) * (y_den / d2);
    return(makeratio(z_num,z_den));}
}

pointer ratio_times(x,y)
pointer x,y;
{
  register eusinteger_t x_num,x_den,y_num,y_den,z_num,z_den,d1,d2;

  x_num = intval(x->c.ratio.numerator);
  x_den = intval(x->c.ratio.denominator);
  y_num = intval(y->c.ratio.numerator);
  y_den = intval(y->c.ratio.denominator);
  d1=gcd(x_num,y_den);
  d2=gcd(x_den,y_num);

  z_num = (x_num / d1) * (y_num / d2);
  z_den = (x_den / d2) * (y_den / d1);

  return(makeratio(z_num,z_den));
}

pointer ratio_divide(x,y)
pointer x,y;
{
  register eusinteger_t x_num,x_den,y_num,y_den,z_num,z_den,d1,d2;
  register int sign;

  x_num = intval(x->c.ratio.numerator);
  x_den = intval(x->c.ratio.denominator);
  y_num = intval(y->c.ratio.numerator);
  y_den = intval(y->c.ratio.denominator);
   
  d1=gcd(x_num,y_num);
  d2=gcd(x_den,y_den);

  if(y_num >= 0) sign=1; else sign=-1;

  z_num = (x_num / d1) * (y_den  / d2) * sign;
  z_den = abs((x_den / d2) * (y_num / d1));

  return(makeratio(z_num,z_den));
}

pointer int2ratio(i)
eusinteger_t i;
{ return(makeratio(i,1));}

eusfloat_t ratio2flt(r)
pointer r;
{ pointer p,q;
  eusfloat_t num, den;
  p=r->c.ratio.numerator;
  q=r->c.ratio.denominator;
  if (isint(p)) num=intval(p);
  else if (isbignum(p)) num=big_to_float(p);
  else error(E_USER,(pointer)"illegal ratio numerator");

  if (isint(q)) den=intval(q);
  else if (isbignum(q)) den=big_to_float(q);
  else error(E_USER,(pointer)"illegal ratio denominator");

  return(num/den);}

pointer return_ratio(r)
pointer r;
{ if (intval(r->c.ratio.numerator)==0) return(makeint(0));
  else if (intval(r->c.ratio.denominator)==1) return(r->c.ratio.numerator);
  else return(r);}


pointer PLUS(ctx,n,argv)
register context *ctx;
register int  n;
register pointer argv[];
{ eusfloat_t fs;
  register eusinteger_t is=0,j;
  register int i=0;
  register pointer a, r, rs;
  pointer b;
  numunion nu;

  while (i<n) {
    a=argv[i];
    if (isint(a)) {
      j=intval(a);
      is+=j;
      if (((is >> 1) ^ is)&((eusinteger_t)1<<WORD_SIZE-3)) { /* fixnum overflow */
	b=makebig1(is); goto bigplus;} }
    else if (isflt(a)) { fs=is; goto fplus;}
    else if (pisratio(a)) { rs=makeratio(is,1);  goto rplus;}
    else if (pisbignum(a)) { b=copy_big(a); goto bigplus;}
    else error(E_NONUMBER);
    i++;}
  return(makeint(is));
rplus:
  while (i<n) {
    a=argv[i];
    if (isint(a)) a=makeratio(intval(a),1);
    else if (isflt(a)) {  fs=ratio2flt(rs);   goto fplus;}
    else if (!isratio(a)) error(E_NONUMBER);
    rs= ratio_plus(rs, a);
    i++;}
  return(return_ratio(rs));
fplus:
  while (i<n) {
    fs+=ckfltval(argv[i]);
    i++;}
  return(makeflt(fs));
bigplus:
  /*  fprintf(stderr, "big plus\n"); */
  i++;
  if (is >= 0)  add_int_big(is, b);
  else sub_int_big(is, b);
  vpush(b);
  while (i<n) {
    a=argv[i];
    if (isint(a)) {
      j=intval(a);
      if (j>0) add_int_big(j,b);
      else if (j<0) sub_int_big(-j,b); 
      b=normalize_bignum(b);}
    else if (isbignum(a)) {
      b=big_plus(a,b);
      vpop();
      vpush(b);
      b=normalize_bignum(b);
      }
    i++; }
  vpop();
  return(b);
  }

pointer MINUS(ctx,n,argv)
register context *ctx;
register int  n;
register pointer argv[];
{ float fs;
  register eusinteger_t is,ia;
  register int i;
  register pointer a=argv[0], rs, b, z;
  numunion nu;

  if (n<1) error(E_MISMATCHARG);
  else if (n==1) {	/*negate*/
    if (a==makeint(MINNEGFIXNUM)) return(makebig1(-MINNEGFIXNUM));
    if (isint(a)) return(makeint(-intval(a)));
    else if (isflt(a)) {
      fs= -fltval(a);
      return(makeflt(fs));}
    else if (isratio(a)) {	/* buggy when numerator == MINNEGFIXNUM */
      return(makeratio(-intval(a->c.ratio.numerator),
			intval(a->c.ratio.denominator)));}

    else if (isbignum(a)) {  return(big_minus(a));}
    else error(E_NONUMBER); }

  /* n>1 */

  i=1; 

  if (isint(a)) { is=intval(a); goto IMINUS;}
  else if (isflt(a)) { fs=fltval(a); goto FMINUS;}
  else if (pisratio(a)) { rs=a; goto RMINUS;}
  else if (isbignum(a)) { b=copy_big(a); goto BIGMINUS;}
  else error(E_NONUMBER);

IMINUS:
  while (i<n) {
    a=argv[i++];
    if (isint(a)) {
      is -= intval(a);
      if (((is >> 1) ^ is)&((eusinteger_t)1<<WORD_SIZE-3)) { /* fixnum overflow */
	b=makebig1(is); goto BIGMINUS;} }
    else if (isflt(a)) { fs=is; goto FMINUS1;}
    else if (pisratio(a)) { rs=makeratio(is,1); goto RMINUS1;}
    else if (isbignum(a)) {
      z=big_minus(a);  /* bignum -a is copied to z */
      vpush(z);
      if (is>0)  add_int_big(is, z);
      else if (is<0) sub_int_big(-is, z);
      z=normalize_bignum(z);
      if (isint(z)) { vpop(); is= intval(z);}
      else { b=z; goto BIGMINUS1;} }
    else error(E_NONUMBER);    } 
  return(makeint(is));

RMINUS:
  while (i<n) {
    a=argv[i++];
RMINUS1:
    if (isint(a)) a=makeratio(intval(a),1);
    else if (isflt(a)) {  fs=ratio2flt(rs);   goto FMINUS;}
    else if (!isratio(a)) error(E_NONUMBER);
    rs= ratio_minus(rs, a);
    }
  return(return_ratio(rs));

FMINUS:
  while (i<n) {
    a=argv[i++];
FMINUS1:
    fs -= ckfltval(a);    }
  return(makeflt(fs));

BIGMINUS:
   vpush(b);
BIGMINUS1:
   while (i<n) {
     a=argv[i++];
     if (isint(a)) {
	ia=intval(a);
	if (ia>0) sub_int_big(intval(a), b);
	else if (ia<0) add_int_big(-ia, b);
	b=normalize_bignum(b);
	if (isint(b)) { vpop(); goto IMINUS;}
        }
     else if (isflt(a)) {
	is= big_to_float(b); vpop(); goto FMINUS;}
     else if (isbignum(a)) {
        z= big_minus(a);
	vpush(z);
	b=big_plus(b,z);
	ctx->vsp[-2]=b;	/*replace b on the stack*/
	vpop();
	b=normalize_bignum(b);
	if (isint(b)) { vpop(); is=intval(b); goto IMINUS;}
	}
     else if (isratio(a)) error(E_USER,(pointer)"BIG-RATIO not supported");
     else error(E_NONUMBER);}
    return(b);}

pointer TIMES(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusfloat_t fs;
  register eusinteger_t is,s;
  register int i;
  register eusinteger_t sign=1;
  register pointer a, rs, b;
  eusinteger_t hi, lo;
  numunion nu;

/*  fprintf(stderr, "TIMES ");
  for (i=0; i<n; i++) fprintf(stderr, "%x ", argv[i]);
  fprintf(stderr, "\n"); */
  
  i=1;  
  a=argv[0];
  if (isint(a)) { is=intval(a); goto ITIMES;}
  else if (isflt(a)) { fs=fltval(a); goto FTIMES;}
  else if (isratio(a)) { rs=a; vpush(rs); goto RTIMES;}
  else if (isbignum(a)) { b=copy_big(a); vpush(b); goto BIGTIMES;}
  else error(E_NONUMBER);

ITIMES:
  while (i<n) {
    a=argv[i++];
ITIMES1:

    if (isint(a)) {
      s=intval(a);
      if (s==0 || is==0) { is=0; break;}
      if (is<0) { sign= -1; is = -is;}
      if (s<0) { sign= -sign; s = -s;}
      extended_mul(is, s, 0, &hi, &lo);
      if( hi !=0 || (lo & ((eusinteger_t)7 << WORD_SIZE-3))!=0) { /*overflow -->bignum */
	b=makebig2(hi, lo & MASK);
	vpush(b);
	if (sign<0) complement_big(b);
        goto BIGTIMES;}
      else is= lo*sign;}
    else if (isflt(a)) { fs=is; goto FTIMES1;}
    else if (pisbignum(a)) { /* fixnum times bignum */
      b=copy_big(a);
      vpush(b);
      goto BIGTIMES1;}
    else if (pisratio(a)) {
      rs=makeratio(is,1);
      vpush(rs);
      goto RTIMES1;}
    else error(E_NONUMBER);}
  return(makeint(is));

RTIMES:
  while (i<n) {
    a=argv[i++];
RTIMES1:
    if (isint(a)) a=makeratio(intval(a),1);
    else if (isflt(a)) {  fs=ratio2flt(rs);   goto FTIMES1;}
    else if (!isratio(a)) error(E_NONUMBER);
    rs= ratio_times(rs, a); 
    ctx->vsp[-1]=rs;
    }
  ctx->lastalloc=rs;
  vpop();
  return(return_ratio(rs));

BIGTIMES:
  while (i<n) {
    a=argv[i++];
    if (isint(a)) {
      is=intval(a);
BIGTIMES1:
      /* Here, b is saved, (b * is) is going to be performed */
      sign=big_sign(b);
      if (sign<0) { complement_big(b);}
      if (is<0) { sign = -sign; is= -is;}
      mul_int_big(is, b);
      if (sign<0) complement_big(b);
      b=normalize_bignum(b);
      if (isint(b)) { is=intval(b); vpop(); goto ITIMES;}
      }
    else if (isflt(a)) {
      fs = big_to_float(b); vpop(); goto FTIMES1;}
    else if (pisbignum(a)) {
      sign=big_sign(b);
      if (sign<0) complement_big(b);
      if (big_sign(a)<0) { sign= -sign; a=big_minus(a);}
      vpush(a);
      b=big_times(a,b);
      ctx->vsp[-2]=b;
      vpop();
      b=normalize_bignum(b);
      if (isint(b)) { is=intval(b); vpop(); goto ITIMES;}
      }
    else if (pisratio(a)) {
      error(E_USER,(pointer)"sorry, big * ratio is not yet implemented.");}
    else error(E_NONUMBER);
    }
  ctx->lastalloc= vpop();
  return(b);

FTIMES:
  while (i<n) {
    a=argv[i++];
FTIMES1:
    fs*=ckfltval(a);}
  return(makeflt(fs));}

pointer QUOTIENT(ctx, n,argv)
register context *ctx;
register int  n;
pointer argv[];
{ register float fs;
  register eusinteger_t is;
  register int i=1;
  register pointer a, rs;
  numunion nu;
  int sign;

  if (n<1) error(E_MISMATCHARG);
  a=argv[0];
  if (isint(a)) is=intval(a);
  else if (isflt(a)) { fs=fltval(a); goto fquo;}
  else if (pisratio(a)) {rs=a; goto rquo;}
  else if (pisbignum(a)) { rs=copy_big(a); goto bquo;}
  else error(E_NONUMBER);

  if (n==1) {
    fs=fltval(a);
    return(makeflt(1.0/fs));}

  while (i<n) {
    a=argv[i];
    if (isflt(a)) { fs=is; goto fquo2;}
    else if (isint(a)) is/=intval(a);
    else if (pisratio(a)) { rs=makeratio(is,1); goto rquo;}
    else if (pisbignum(a)) error(E_USER,(pointer)"int div big?");
    else error(E_NONUMBER);
    i++;}
  return(makeint(is));

rquo:	/*quotient of ratios*/
  while (i<n) {
    a=argv[i];
    if (isint(a)) a=makeratio(intval(a),1);
    else if (isflt(a)) {  fs=ratio2flt(rs);   goto fquo;}
    else if (!isratio(a)) error(E_NONUMBER);
    rs= ratio_divide(rs, a);
    i++;}
  return(return_ratio(rs));
fquo:
  if (n==1) return(makeflt(1.0/fs));
fquo2:
  while (i<n) {
    a=argv[i];
    fs/=ckfltval(a);
    i++;}
  return(makeflt(fs));

bquo:
  if (big_sign(rs)<0) { sign= -1; complement_big(rs);}
  else sign=1;
  while (i<n) {
    a=argv[i];
    if (isflt(a)) {
      fs=big_to_float(rs); goto fquo2;}
    if (!isint(a)) error(E_USER,(pointer)"big div ?");
    is=intval(a);
    if (is<0) { sign = - sign; is= -is;}    
    div_int_big(is, rs);
    i++;
    }
  if (sign<0) complement_big(rs);
  return(normalize_bignum(rs));
  }




pointer SIN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(sin(ckfltval(argv[0]))));}

pointer COS(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(cos(ckfltval(argv[0]))));}

pointer TAN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(tan(ckfltval(argv[0]))));}

pointer ATAN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  if (n==1) return(makeflt(atan(ckfltval(argv[0]))));
  else if (n==2) return(makeflt(atan2(ckfltval(argv[0]),ckfltval(argv[1]))));
  else error(E_MISMATCHARG);}

pointer TANH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(tanh(ckfltval(argv[0]))));}

pointer ATANH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(atanh(ckfltval(argv[0]))));}

pointer SINH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(sinh(ckfltval(argv[0]))));}

pointer ASINH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(asinh(ckfltval(argv[0]))));}

pointer COSH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(cosh(ckfltval(argv[0]))));}

pointer ACOSH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(acosh(ckfltval(argv[0]))));}

pointer SQRT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(sqrt(ckfltval(argv[0]))));}

pointer LOG(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ double a;
  numunion nu;
  a=log(ckfltval(argv[0]));
  if (n==1) return(makeflt(a));
  else if (n==2) return(makeflt(a/log(ckfltval(argv[1]))));
  else error(E_MISMATCHARG);}

pointer EXP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ numunion nu;
  ckarg(1);
  return(makeflt(exp(ckfltval(argv[0]))));}

pointer ABS(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a, b;
  eusfloat_t fa;
  numunion nu;
  ckarg(1);
  a=argv[0];
  if (a==makeint(MINNEGFIXNUM)) return(makebig1(-MINNEGFIXNUM));
  if (isint(a)) return(makeint(abs(intval(a))));
  else if (isflt(a)) return(makeflt(fabs(fltval(a))));
  else if (pisbignum(a)) {
    if (big_sign(a)<0) {
       b=copy_big(a);
       complement_big(b);
       return(b);}
    else return(a);}
  else error(E_NONUMBER);}

pointer ROUND(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a=argv[0];
  eusfloat_t f;
  register eusinteger_t x;
  numunion nu;
  ckarg(1);
  if (isint(a)) return(a);
  else {
    f=ckfltval(a);
    f=(double)rint(f);
    return(eusfloat_to_big(f));}
  }

pointer FLOOR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  eusfloat_t f;
  register eusinteger_t x;
  numunion nu;
  ckarg(1);
  if (isint(a)) return(a);
  else {
    f=floor(ckfltval(a)); return(eusfloat_to_big(f));} }

pointer CEILING(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  eusfloat_t f;
  numunion nu;
  ckarg(1);
  if (isint(a)) return(a);
  else { f=ckfltval(a); f=ceil(f); return(eusfloat_to_big(f));}
  }

pointer TRUNCATE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  eusfloat_t f;
  register eusinteger_t x;
  numunion nu;
  ckarg(1);
  if (isint(a)) return(a);
  else if (isbignum(a)) return(a);
  else { f=ckfltval(a); return(eusfloat_to_big(f));}
  }

pointer FREXP(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ eusfloat_t  f,z;
  int exp;
  pointer p;
  numunion nu;
  extern double frexp(double, int *);
  ckarg(1);
  f=ckfltval(argv[0]);
  z=frexp(f, &exp);
  p=cons(ctx, makeint(exp), NIL);
  return(cons(ctx,makeflt(z),p));
  }

pointer FLOAT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a;
  eusfloat_t f;
  numunion nu;
  ckarg(1);
  a=argv[0];
  if (isflt(a)) return(a);
  else if (isint(a)) { f=ckintval(a); return(makeflt(f));}
  else { f=ckfltval(a); return(makeflt(f));}
  }

pointer DECFLOAT(ctx,n,argv)	/*(decode-float FLOAT) -> int*/
register context *ctx;
int n;
pointer argv[];
{ pointer x;
  eusinteger_t i;
  ckarg(1);
  x=argv[0];
  if (!isflt(x)) error(E_NONUMBER);
  i=intval(x);
  return(makeint(i));}

pointer MAX(ctx,n,argv)
register context *ctx;
register int  n;
pointer argv[];
{ eusfloat_t fs,fm;
  register i=1;
  register eusinteger_t is;
  register pointer a=argv[0];
  numunion nu;
  if (n<1) error(E_MISMATCHARG);
  if (n==1) return(a);
  if (isint(a)) is=(eusinteger_t)a;
  else { fs=fltval(a); goto fmax;}
  while (i<n) {
    a=argv[i];
    if (isflt(a)) { fs=intval(is); goto fmax;}
    if (isint(a)) { if (is<(eusinteger_t)a) is=(eusinteger_t)a;}
    else error(E_NONUMBER);
    i++;}
  return((pointer)is);
fmax:
  while (i<n) {
    fm=ckfltval(argv[i]);
    if (fs<fm) fs=fm;
    i++;}
  return(makeflt(fs));}

pointer MIN(ctx,n,argv)
register context *ctx;
register int  n;
register pointer argv[];
{ eusfloat_t fs,fm;
  register int i=1;
  register eusinteger_t is;
  register pointer a=argv[0];
  numunion nu;
  if (n<1) error(E_MISMATCHARG);
  if (n==1) return(a);
  if (isint(a)) is=(eusinteger_t)a;
  else { fs=fltval(a); goto fmin;}
  while (i<n) {
    a=argv[i];
    if (isflt(a)) { fs=intval(is); goto fmin;}
    if (isint(a)) { if (is>(eusinteger_t)a) is=(eusinteger_t)a;}
    else error(E_NONUMBER);
    i++;}
  return((pointer)is);
fmin:
  while (i<n) {
    fm=ckfltval(argv[i]);
    if (fs>fm) fs=fm;
    i++;}
  return(makeflt(fs));}

/****************************************************************/
/* bit wise logical operations
/****************************************************************/
pointer LOGAND(context *ctx, int n, pointer argv[])
{ int i=1,j,k,rsize,psize;
  eusinteger_t *rbv, *bbv, *pbv;
  pointer b,p,r=argv[0];

  if (isbignum(r)) {
    r=copy_big(r); rsize=bigsize(r); rbv=bigvec(r);
    p=argv[i++];
    goto bigand;}

  k=intval(r);
  while (i<n) {
    p=argv[i++];
    if (isint(p)) k &=intval(p);
    else if (isbignum(p)) {
      b=copy_big(p);
      p=makeint(r);
      r=b; rsize=bigsize(r); rbv=bigvec(r);
      goto bigand;}
    else error(E_NOINT);}
  return(makeint(k));

  while (i<n) {
    p=argv[i++];
bigand:
    /* r is bignum */
    if (isint(p)) {
      rbv[0] &= intval(p);
      if (intval(p)>=0) for (j=1; j<rsize; j++) rbv[j]=0; }
    else if (isbignum(p)) {
      psize=bigsize(p);
      if (rsize>=psize) {
        for (j=0; j<psize; j++)  rbv[j] &= p->c.bgnm.bv->c.ivec.iv[j];
        if (rsize>psize) {
	  if (big_sign(p)>0)  for (j=psize; j<rsize; j++) rbv[j]=0;}
	}
      else if (big_sign(r)<0) {
	r=extend_big(r,psize);
	rsize=psize; rbv=bigvec(r);
        for (j=0; j<psize; j++)  rbv[j] &= p->c.bgnm.bv->c.ivec.iv[j];
	}
      else 
        for (j=0; j<rsize; j++)  rbv[j] &= p->c.bgnm.bv->c.ivec.iv[j]; 
      }
    else  error(E_NOINT);}
  return(normalize_bignum(r));}

pointer LOGIOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t result=0;
  register int i=0;
  pointer p;
  while (i<n) {
    p=argv[i];
    if (!isint(p)) {
      if (isbignum(p)) result |= bigintval(p);
      else error(E_NOINT);}
    else  result |= intval(p);
    i++; }
  return(mkbigint(result));}

pointer LOGXOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t result=0;
  register int i=0;
  while (i<n) 
    if (!isint(argv[i])) error(E_NOINT);
    else result ^= intval(argv[i++]);
  return(makeint(result));}

pointer LOGEQV(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t result=0;
  register int i=0;
  while (n>0) {
    if (!isint(argv[--n])) error(E_NOINT);
    result ^= intval(argv[n]); }
  return(makeint(~result));}

pointer LOGNAND(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t result= ~0;
  register int i=0;
  while (i<n) 
    if (!isint(argv[i])) error(E_NOINT);
    else result &= intval(argv[i++]);
  return(makeint(~result));}

pointer LOGNOR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t result=0;
  register int i=0;
  while (i<n) 
    if (!isint(argv[i])) error(E_NOINT);
    else result |= intval(argv[i++]);
  return(makeint(~result));}

pointer LOGNOT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ eusinteger_t i;
  ckarg(1);
  if (!isint(argv[0])) error(E_NOINT);
  else {
    i=intval(argv[0]);
    return(makeint(~i));}}

pointer LOGTEST(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (!isint(argv[0])) error(E_NOINT);
  if (!isint(argv[1])) error(E_NOINT);
  if ((eusinteger_t)argv[0] & (eusinteger_t)argv[1] & (eusinteger_t)~3) return(T);
  else return(NIL);}

pointer LOGBITP(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t index,val;
  ckarg(2);
  index=ckintval(argv[0]);
  val=ckintval(argv[1]);
  if (index<0) error(E_NOINT);
  if ((val>>index) & 1) return(T); else return(NIL);}

pointer ASH(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t count,val;
  register int firstone;
  register eusinteger_t sign;
  pointer a,b;
  ckarg(2);
  count=ckintval(argv[1]);
  if (isint(argv[0])) {
    val=intval(argv[0]);
    if (count<=0) return(makeint(val>>(-count)));
    if (val<=0) { return(makeint(val<<count));}
    firstone=ffs(val);
    if ((firstone + count)<WORD_SIZE-2) {
      sign=(val>=0)?1:(-1);
      val=val<<count;
      if (sign>0) return(makeint(val));
      else return(makeint(~val)); }
    /*extend to big*/
    a=makebig1(val);}
  else if (isbignum(argv[0])) { a=argv[0]; sign=big_sign(a);}
  else error(E_NOINT);

  /*shift b by count bits*/
  { int size=bigsize(a);
    int i, j, k;
    eusinteger_t x, *av, *bv;
    pointer b=makebig(size+(count+(WORD_SIZE-1))/(WORD_SIZE-1));
    vpush(b);
    av=bigvec(a); bv=bigvec(b);    
    if (count>=0) {
      j= count/(WORD_SIZE-1); k=count % (WORD_SIZE-1);
      for (i=0; i<size; i++) {
        x=av[i];
        bv[i+j] |= (x << k);
        bv[i+j+1] = (x>>((WORD_SIZE-1)-k)); } }
    else {  /* count <0 ; shift right */
      count = -count;
      j=count/(WORD_SIZE-1); k=count % (WORD_SIZE-1);
      for (i=0; i<size-j-1; i++) {
	bv[i]=(av[j+i]>>k) | ((av[j+i+1]<<((WORD_SIZE-1)-k)) & MASK); }
      bv[size-j-1]=av[size-1]>>k;
      }
    b=normalize_bignum(b);
    vpop();
    return(b); }
  }

pointer LDB(ctx,n,argv)	/*(LDB 'val 'pos 'width)*/
register context *ctx;
register int n;			/*no byte specifier in euslisp*/
register pointer argv[];
{ register eusinteger_t pos,width=8;
#if (WORD_SIZE == 64)
  register unsigned long val;
#else
  register unsigned int val;
#endif
  ckarg2(2,3);
  val=ckintval(argv[0]);  pos=ckintval(argv[1]);
  if (n==3) width=ckintval(argv[2]);
  val=(val<<(WORD_SIZE-pos-width))>>(WORD_SIZE-width);
  return(makeint(val));}

pointer DPB(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register eusinteger_t pos,width=8;
#if (WORD_SIZE == 64)
  register unsigned long val,target,mask=~0;
#else
  register unsigned int val,target,mask=~0;
#endif
  ckarg(4);
  val=ckintval(argv[0]);
  target=ckintval(argv[1]);
  pos=ckintval(argv[2]);
  width=ckintval(argv[3]);
  mask=mask<<(WORD_SIZE-(pos+width));
  mask=mask>>(WORD_SIZE-width); 
  val &= mask;
  mask <<= pos;
  target=(target & ~mask) | (val<<pos);
  return(makeint(target));}

pointer RANDOM(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer a=argv[0],state;
  eusinteger_t imax,irandval;
  eusfloat_t fmax,frandval;
  double randval;
  double erand48();
#if news || sanyo
  long random();
#endif
  numunion nu;

  ckarg2(1,2);
  if (n==2) {
    state=argv[1];
    if (!isintvector(state) && !isstring(state)) error(E_NOVECTOR);
    if (vecsize(state)<2) error(E_VECSIZE);}
  else {
    state=Spevalof(RANDSTATE);
    if (state==UNBOUND) state=speval(RANDSTATE);}
#if news || sanyo
  randval=random();
#else
#if alpha
  randval=erand48((unsigned short *)state->c.ivec.iv);
#else
  randval=erand48(state->c.ivec.iv);
#endif
#endif
  if (isint(a)) {
    imax=intval(a);
    irandval=randval*imax;
    return(makeint(irandval));}
  else if (isflt(a)) {
    fmax=fltval(a);
    frandval=randval*fmax;
    return(makeflt(frandval));}
  else error(E_NONUMBER);
  }


arith(ctx,mod)
register context *ctx;
pointer mod;
{
  defun(ctx,"=",mod,NUMEQUAL,NULL);
  defun(ctx,">",mod,GREATERP,NULL);
  defun(ctx,"<",mod,LESSP,NULL);
  defun(ctx,">=",mod,GREQP,NULL);
  defun(ctx,"<=",mod,LSEQP,NULL);
  defun(ctx,"MOD",mod,MOD,NULL);
  defun(ctx,"1-",mod,SUB1,NULL);
  defun(ctx,"1+",mod,ADD1,NULL);
  defun(ctx,"+",mod,PLUS,NULL);
  defun(ctx,"-",mod,MINUS,NULL);
  defun(ctx,"*",mod,TIMES,NULL);
  defun(ctx,"/",mod,QUOTIENT,NULL);
  defun(ctx,"SIN",mod,SIN,NULL);
  defun(ctx,"COS",mod,COS,NULL);
  defun(ctx,"TAN",mod,TAN,NULL);
  defun(ctx,"ATAN",mod,ATAN,NULL);
  defun(ctx,"TANH",mod,TANH,NULL);
  defun(ctx,"ATANH",mod,ATANH,NULL);
  defun(ctx,"SINH",mod,SINH,NULL);
  defun(ctx,"ASINH",mod,ASINH,NULL);
  defun(ctx,"COSH",mod,COSH,NULL);
  defun(ctx,"ACOSH",mod,ACOSH,NULL);
  defun(ctx,"SQRT",mod,SQRT,NULL);
  defun(ctx,"LOG",mod,LOG,NULL);
  defun(ctx,"EXP",mod,EXP,NULL);
  defun(ctx,"ABS",mod,ABS,NULL);
  defun(ctx,"ROUND",mod,ROUND,NULL);
  defun(ctx,"FLOOR",mod,FLOOR,NULL);
  defun(ctx,"CEILING",mod,CEILING,NULL);
  defun(ctx,"TRUNCATE",mod,TRUNCATE,NULL);
  defun(ctx,"FLOAT",mod,FLOAT,NULL);
  defun(ctx,"DECODE-FLOAT",mod,DECFLOAT,NULL);
  defun(ctx,"MAX",mod,MAX,NULL);
  defun(ctx,"MIN",mod,MIN,NULL);
  defun(ctx,"LOGAND",mod,LOGAND,NULL);
  defun(ctx,"LOGIOR",mod,LOGIOR,NULL);
  defun(ctx,"LOGXOR",mod,LOGXOR,NULL);
  defun(ctx,"LOGEQV",mod,LOGEQV,NULL);
  defun(ctx,"LOGNAND",mod,LOGNAND,NULL);
  defun(ctx,"LOGNOR",mod,LOGNOR,NULL);
  defun(ctx,"LOGNOT",mod,LOGNOT,NULL);
  defun(ctx,"LOGTEST",mod,LOGTEST,NULL);
  defun(ctx,"LOGBITP",mod,LOGBITP,NULL);
  defun(ctx,"ASH",mod,ASH,NULL);
  defun(ctx,"LDB",mod,LDB,NULL);
  defun(ctx,"DPB",mod,DPB,NULL);
  defun(ctx,"RANDOM",mod,RANDOM,NULL);
  defun(ctx,"FREXP",mod,FREXP,NULL);
}
