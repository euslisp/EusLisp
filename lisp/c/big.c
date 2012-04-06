/*
	big.c

	bignum routines for EusLisp
	1995 (c) Toshihiro Matsui, Electrotechnical Laboraotory
 Skeltal codes are borrowed from KCL's big.c and earith.c.

 EusLisp's bignum is represented by an integer-vector.
 A value is placed in a vector from LSB to MSB.
 Sign bit is not used in the first to (MSB -1)th words.
 Sign is held in the sign bit of the MSB word. 
 example: #x1122334455667788 
  bv[0]= #x55667788
  bv[1]= #x22446688

*/

static char *rcsid="@(#)$Id$";
#include "eus.h"

#define	ltz(x)	((x)<0)
#define	gez(x)	((x)>=0)

extern pointer makebig();

#if (WORD_SIZE == 64)

void extended_mul(d, q, r, hp, lp)
eusinteger_t d, q, r;
eusinteger_t *hp, *lp;
{
	eusinteger_t ld, hd, lq, hq, m, lm, hm, lr;
        eusinteger_t hz, lz;


	ld = (d  & 0x00000000ffffffff);
	hd = (d >> 32);
	hd = (hd & 0x000000007fffffff);
	lq = (q  & 0x00000000ffffffff);
	hq = (q >> 32);
	hq = (hq & 0x000000007fffffff);
        lr = r;

	m  = ld * lq;
	hm = (m  & 0x8000000000000000);
	hm = (hm >> 32);
	hm = (hm & 0x0000000080000000);
	m  = (m  & 0x7fffffffffffffff);

	m  = m + lr;

	lz = (m  & 0x00000000ffffffff);

	m  = (m >> 32);
	m  = (m  & 0x00000000ffffffff);
	m  = m + hm;
	m  = m + (lq * hd);
	hm = (m  & 0x8000000000000000);
	hm = (hm >> 31);
	hm = (hm & 0x00000001ffffffff);
	m  = (m  & 0x7fffffffffffffff);
	
	m = m + (hq * ld);

	lm = (m  & 0x000000007fffffff);
 	
	lz = lz + (lm << 32);
	
	m  = (m >> 31);
	m  = (m  & 0x00000001ffffffff);
	m  = m + hm;

	hz = m + (hq * hd * 2);


	*hp = hz;
	*lp = lz;

}

void extended_div(d, h, l, qp, rp)
eusinteger_t d, h, l;
eusinteger_t *qp, *rp;
{
	eusinteger_t lh, ld, ll, ans;
	int i;

	ld = d;
	lh = h;
	ll = l;


	ans = 0;
	for(i=63;i>0;i--) {	
		ans = (ans << 1);
		lh = (lh << 1);
		ll = (ll << 1);
		if (ll < 0)	lh += 1;
		if (lh >= d) {
			lh -= ld;
			ans += 1;
		}
		if (lh < 0) {
			lh = (0x7fffffffffffffff - ld) +
			     (lh & 0x7fffffffffffffff) + 1;
			ans += 1;
		}
	}


	*qp = ans;
	*rp = lh;
}

#else   /* WORD_SIZE==32 */
#if (!Solaris2 || !sun4)

void extended_mul(d, q, r, hp, lp)
eusinteger_t d, q, r;
eusinteger_t *hp, *lp;/* ???? */
{
	long int  ld, hd, lq, hq, m, lm, hm, lr;
        int hz, lz;


	ld = (d & 0x0000ffff);
	hd = (d >> 16);
	hd = (hd & 0x00007fff);
	lq = (q & 0x0000ffff);
	hq = (q >> 16);
	hq = (hq & 0x00007fff);
        lr = r;

	m = ld * lq;
	hm = (m & 0x80000000);
	hm = (hm >> 16);
	hm = (hm & 0x00008000);
	m = (m & 0x7fffffff);

	m = m + lr;

	lz = (m & 0x0000ffff);

	m = (m >> 16);
	m = (m & 0x0000ffff);
	m = m + hm;
	m = m + (lq * hd);
	hm = (m & 0x80000000);
	hm = (hm >> 15);
	hm = (hm & 0x0001ffff);
	m = (m & 0x7fffffff);
	
	m = m + (hq * ld);

	lm = (m & 0x00007fff);
 	
	lz = lz + (lm << 16);
	
	m = (m >> 15);
	m = (m & 0x0001ffff);
	m = m + hm;

	hz = m + (hq * hd * 2);


	*hp = hz;
	*lp = lz;

}

void extended_div(d, h, l, qp, rp)
eusinteger_t d, h, l;
eusinteger_t *qp, *rp;
{
	long int lh, ld, ll;
	int i,ans;

	ld = d;
	lh = h;
	ll = l;


	ans = 0;
	for(i=31;i>0;i--) {	
		ans = (ans << 1);
		lh = (lh << 1);
		ll = (ll << 1);
		if (ll < 0)	lh += 1;
		if (lh >= d) {
			lh -= ld;
			ans += 1;
		}
		if (lh < 0) {
			lh = (0x7fffffff - ld) + (lh & 0x7fffffff) + 1;
			ans += 1;
		}
	}


	*qp = ans;
	*rp = lh;
}

#else /* !(sun4 && Solaris2) */

/* Compile with -O option */
#define u_int unsigned int

#define DEBUG
#undef DEBUG
#ifdef DEBUG
extended_mul(d,q,r,hp,lp)
 u_int d,q,r,*hp,*lp;
 {
        printf("ext.mul (%x %x %x)",d,q,r);fflush(stdout);
        low_extended_mul(d,q,r,hp,lp);
        printf(" =%x:%08x\n",*hp,*lp);fflush(stdout);
 }
static low_extended_mul(d, q, r, hp, lp)
#else
extended_mul(d,q,r,hp,lp)
#endif
register u_int d, q, r;
register u_int *hp, *lp;
{
	asm("	save	%sp, -0x60, %sp");
        asm("   mov     %i0,%o0");      /* d*q+r */
        asm("   call    .umul,2");      /* delayed inst. */
        asm("   mov     %i1,%o1"); 
        asm("   addcc   %o0,%i2,%o0");
        asm("   addx    %o1,  0,%o1");

        asm("   sll     %o1,  2,%o1");  /* ((H<<1) & 0x3fffffff) */
        asm("   srl     %o1,  1,%o1");
        asm("   srl     %o0, 31,%i2");  /*      | (L>>31)  -> %o1 */
        asm("   or      %o1,%i2,%o1");

        asm("   sll     %o0,  1,%o0");  /* L & 0x7ffffffff */
        asm("   srl     %o0,  1,%o0");

        asm("   st      %o0,[%i4]");
        asm("   st      %o1,[%i3]");
	asm("	ret");
	asm("	restore");
}

extended_div(d, h, l, qp, rp)
register u_int d, h, l;
u_int *qp, *rp;
{
        register u_int q,one;
#ifdef DEBUG
printf("ext.div (%x %x:%x)",d,h,l);fflush(stdout);
#endif
                        l=l<<1; one=1<<31; q=0;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;

                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;

                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;

                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;
                          if (h>=d) { q+= one;h-=d; }
                          h<<=1; h|=l>>31; l<<=1; one>>=1;

                        *qp=q;
                        *rp=h>>1;

/*                      l=l<<1; one=1<<31;
                        for(q=0;one;one>>=1)
                          { 
                            if (h>=d) { q+= one;h-=d; }
                            h<<=1; 
                            h|=l>>31;
                            l<<=1;
                          }
                        *qp=q;
                        *rp=h>>1;
*/
#ifdef DEBUG
printf(" =%x:%x\n",*qp,*rp);fflush(stdout);
#endif
}

#endif /* !Solaris2 */
#endif



/****************************************************************/
/* stretch_big(x, i)
/*  'x' is a bignum and 'i' is integer.
/*  Allocate bigvector whose size is one word bigger than x,
/*  and put 'i' in the MSB word.
*/

inline pointer stretch_big(x, i)
pointer x;
eusinteger_t i;
{ pointer bn=x->c.bgnm.bv;
  int vlen=vecsize(bn);
  pointer newv, oldv;
  register int j;

  newv=makevector(C_INTVECTOR, vlen+1);
  for (j=0; j<vlen; j++) newv->c.ivec.iv[j]=bn->c.ivec.iv[j];
  newv->c.ivec.iv[vlen]=i;
  pointer_update(x->c.bgnm.bv, newv);
  return(newv);
  }

pointer copy_big(x)
pointer x;
{ pointer y;
  register int size, i;
  register eusinteger_t *xv, *yv;

  size=bigsize(x);
  y=makebig(size);
  xv=bigvec(x);
  yv=bigvec(y);
  for (i=0; i<size; i++) yv[i]=xv[i];
#ifdef SAFETY
  take_care(y);
#endif
  return(y);
  }

/* extend_big(b,newsize) allocates a new bignum which has the same value
   as 'b' in the 'newsize' word. Sign is copied in the upper extra words.
   Newsize should be greater than the original size of b.
*/
pointer extend_big(pointer b, int newsize)
{ pointer nb;
  eusinteger_t *bv, *nbv;
  int i,bsize;
  nb=makebig(newsize);
  bv=bigvec(b); nbv=bigvec(nb); bsize=bigsize(b);
  for (i=0; i<bsize; i++) nbv[i]=bv[i];
  if (big_sign(b)<0) {
    for (i=bsize; i<newsize; i++) nbv[i]= MASK;
    nbv[newsize-1] = -1;}
  return(nb); }
  
/*
	Big_zerop(x) answers if bignum x is zero or not.
	X may be any bignum.
*/
eusinteger_t big_zerop(x)
pointer x;
{ register eusinteger_t *xv;
  register int i, size;
  xv=bigvec(x); size=bigsize(x);
  for (i=0; i<size; i++)  if (xv[i] != 0) return(0);
  return(1);
}

/*
	Big_sign(x) returns 
		something < 0	if x < -1
		something >= 0	if x > 0.
	X may be any bignum.
*/
eusinteger_t big_sign(x)
pointer x;
{ pointer y;
  y=x->c.bgnm.bv;
  return(y->c.ivec.iv[vecsize(y)-1]);
  }

/*  Big_compare(x, y) returns
		-1	if x < y
		0	if x = y
		1	if x > y.
    X and y may be any bignum.
*/

int big_compare(x, y)
register pointer x, y;
{ register eusinteger_t *xv, *yv;
  register int xsize,ysize,i,j=0;
  eusinteger_t xsign, ysign;
  xv=bigvec(x); yv=bigvec(y);
  xsize=bigsize(x); ysize=bigsize(y);

  xsign=xv[xsize-1]; ysign=yv[ysize-1];
  if (xsign<0 && ysign>=0) return(-1);
  else if (xsign>=0 && ysign<0) return(1);
  if (xsign<0) { /* ysign is also negative*/
    /*assume both x and y are normalized*/
    if (xsize>ysize) return(-1);
    else if (xsize<ysize) return(1);
    else { /* xsize=ysize*/
      if (xv[xsize-1] < yv[xsize-1]) return(-1);
      else if (xv[xsize-1]>yv[xsize-1]) return(1);
      for (i=xsize-2; i>=0; i--) {
	if (xv[i] < yv[i])  return(1);
	else if (xv[i] > yv[i]) return(-1); }
      return(0);} }
  else {  /* both x and y are positive */
    if (xsize>ysize) return(1);
    else if (xsize<ysize) return(-1);
    else { /* xsize=ysize*/
      for (i=xsize-1; i>=0; i--) {
	if (xv[i] > yv[i])  return(1);
	else if (xv[i] < yv[i]) return(-1); }
      return(0);} }
}


/*
	Complement_big(x) destructively takes
	the 2's complement of bignum x.
	X may be any bignum.
*/
void complement_big(x)
pointer x;
{
  int size, i=0;
  eusinteger_t *xv;
  size=bigsize(x); xv=bigvec(x);

  while (i != size-1) {
    if (xv[i] != 0) {
	xv[i] = (-xv[i]) & MASK;
	goto ONE;}
    i++;}
  if (xv[i] == ~MASK) {
    xv[i] = 0;
    stretch_big(x, 1);
    xv=bigvec(x); /*reload*/ }
  else	xv[i] = -(xv[i]);
  return;

ONE:
  for (;;) {
    i++;
    if (i==size-1) break;
    xv[i] = (~xv[i]) & MASK;}
  xv[i] = ~xv[i];
  return;
}

/*
	big_minus(x) returns the 2's complement of bignum x.
	X may be any bignum.
*/
pointer big_minus(x)
pointer x;
{ int size, i;
  eusinteger_t *xv, *yv;
  pointer y;

  size=bigsize(x); xv=bigvec(x);
  y = makebig(size);
  yv=bigvec(y);
  i=0;
  while (i<size-1) {
    if (xv[i] != 0) {
      yv[i]= (-xv[i]) & MASK;	goto ONE;}
    i++;}
  if (xv[i] == MSB) { /* 0x80000000 */
    yv[i]= 0;
    stretch_big(y, 1);
    yv=bigvec(y);
    }
  else	yv[i] = -(xv[i]);
#ifdef SAFETY
  take_care(y);
#endif
  return(y);

ONE:
  for (;;) {
	i++;
	if (i==size-1)		break;
	yv[i] = (~xv[i]) & MASK;
	}
  yv[i] = ~xv[i];
#ifdef SAFETY
  take_care(y);
#endif
  return(y);
}


/*
	Add_int_big(c, x) destructively adds non-negative int c
	to bignum x.
	I should be non-negative.
	X may be any bignum.
*/
void add_int_big(c, x)
eusinteger_t c;
pointer x;
{ register int size, i=0;
  register eusinteger_t *xv;

  size=bigsize(x); xv=bigvec(x);
  while (i<size-1) {
    xv[i] += c;
    if (xv[i] < 0) { /*  carry  */
      c = 1;
      xv[i] &= MASK;
      i++; }
    else return;}	/* no carry propagation to upper bits */

  if (xv[i] >= 0) {	/* MSB */
    xv[i] += c;
    if (xv[i] < 0) {		/*  overflow  */
	xv[i] &= MASK;
	stretch_big(x, 1);
	xv=bigvec(x);}	 }
  else xv[i] += c;
  return; }

/*
	Sub_int_big(c, x) destructively subtracts non-negative int c
	from bignum x.
	c should be non-negative.
	X may be any bignum.
*/
void sub_int_big(c, x)
eusinteger_t c;
pointer x;
{ register int size, i=0;
  register eusinteger_t *xv;
  size=bigsize(x); xv=bigvec(x);
  while (i<size-1) {
    xv[i] -= c;
    if (xv[i] < 0) {		/*  borrow  */
	c = 1; xv[i] &= MASK; i++;}
    else return;}
  if (xv[i] < 0) {	/* MSB */
    xv[i] -= c;
    if (xv[i] >= 0) { /*  if sign changes, underflow  */
      xv[i] &= MASK;
      stretch_big(x, -2); } }
  else xv[i] -= c;
  return;}

/*
	Mul_int_big(i, x) destructively multiplies non-negative bignum x
	by non-negative int i.
	I should be non-negative.
	X should be non-negative.
*/
void mul_int_big(c, x)
eusinteger_t c;
pointer x;
{ int size, i=0;
  eusinteger_t *xv, h=0;

  size=bigsize(x); xv=bigvec(x);
  while (i<size) {
    extended_mul(c, xv[i], h, &h, &xv[i]);
    i++;}
  if (h > 0) stretch_big(x, h);
  return;}

/*
	Div_int_big(c, x) destructively divides non-negative bignum x
	by positive int c.
	X will hold the remainder of the division.
	Div_int_big(c, x) returns the remainder of the division.
	c should be positive.
	X should be non-negative.
*/
eusinteger_t div_int_big(c, x)
eusinteger_t c;
pointer x;
{ int i, size;
  eusinteger_t *xv, r;
  if (c == 0) error(E_USER,(pointer)"divide by zero in bignum div");
  size=bigsize(x); xv=bigvec(x);
  /* divide from MSB */ 
  r = xv[size-1] % c;
  xv[size-1] /= c;
  i=size-2;
  while (i>=0) {
	   extended_div(c, r, xv[i], &(xv[i]), &r);
    i--;}
	return(r); }

/*
	Big_plus(x, y) returns the sum of bignum x and bignum y.
	X and y may be any bignum.
*/
pointer big_plus(x, y)
pointer x, y;
{ pointer z;
  int i, xsize, ysize;
  eusinteger_t c, zlast, *xv, *yv, *zv;

  xsize=bigsize(x); ysize=bigsize(y);
  if (xsize<ysize) { /*exchange x and y so that x is bigger than y */
    z=x; x=y; y=z;
    i=xsize; xsize=ysize; ysize=i;}

  /*fprintf(stderr, "big_plus xsize=%d ysize=%d\n", xsize,ysize);*/

  xv=bigvec(x); yv=bigvec(y);
  z=copy_big(x); zv=bigvec(z);
  c=0;
  for (i=0; i<ysize; i++) {
    zv[i]=zlast=zv[i]+yv[i]+c;
    if (zlast<0) { c=1; zv[i] &= MASK;}
    else c=0;}
  i= ysize - 1; 
  if (ysize==xsize) {
    if (xv[i]>=0 && yv[i]>=0 && zlast<0)  stretch_big(z, 1);
    else if (xv[i]<0 && yv[i]<0 && zlast>=0) {
      stretch_big(z, -2);}
    else if (zlast<0) zv[i] |= MSB;
    return(z);}
  else {  /* xsize>ysize */
    if (yv[ysize-1]>=0) c=1; else c= -1;
    while (i<xsize-1) {
      if (zlast<0) zv[i] &= MASK;
      else return(z);
      i++;
      zv[i] += c;
      zlast=zv[i];}
    if (c>=0 && xv[i]>=0 && zv[i]<0) {
      zv[i] &= MASK; stretch_big(z, 1);}
    else if (c<0 && xv[i]<0 && zv[i]>=0) {
      stretch_big(z, -2);}
    return(z); }
  }  

/*
	Big_times(x0, y0) returns the product
	of non-negative bignum x0 and non-negative bignum y0.
	X0 and y0 should be non-negative.
*/
pointer big_times(x, y)
pointer x, y;
{ int xsize, ysize, zsize;
  eusinteger_t *xv, *yv, *zv;
  int i, j, k, m;
  pointer z;
  eusinteger_t hi, lo;
  
  xsize=bigsize(x); ysize=bigsize(y);
  zsize=xsize+ysize;
  z=makebig(zsize);
  xv=bigvec(x); yv=bigvec(y); zv=bigvec(z);

  zv[0]=0;

  for (i=0; i<xsize; i++) {
    m=xv[i];
    hi=0;
    for (j=0; j<ysize; j++) {
      k=i+j;
      extended_mul(m, yv[j], hi, &hi, &lo);
      zv[k]+=lo;
      if (zv[k] & MSB) { zv[k] &= MASK; hi++; }
      if (j==ysize-1) {
        while (hi>0) {
          k++;
          if (k>=xsize+ysize) error(E_USER,(pointer)"bignum mult overflow");
          zv[k] += hi;
	  if (zv[k] & MSB) { zv[k] &= MASK; hi=1; }
          else hi=0;}
        }
      }
    }
#ifdef SAFETY
  take_care(z);
#endif
  return(z);}

/*
	Sub_int_big_big(c, x, y) destructively subtracts c*x from y.
	C should be a non-negative int.
	X should be a normalized non-negative bignum.
	Y should be non-negative bignum and should be such that
		y <= c*x.
*/

void sub_int_big_big(c, x, y)
eusinteger_t c;
pointer x, y;
{ int i, j;
  int xsize, ysize;
  eusinteger_t *xv, *yv;
  eusinteger_t hi, lo;

  xsize=bigsize(x); ysize=bigsize(y);
  xv=bigvec(x); yv=bigvec(y);

  hi = 0;
  for (i=0;i<xsize;i++) {
    extended_mul(c, xv[i], hi, &hi, &lo);
    yv[i] -= lo;
    if (yv[i] & MSB) {
	yv[i] &= MASK;
	hi++;
    }
    if (i==xsize-1) {
	while (hi > 0) {
	    i++;
	    yv[i] -= hi;
	    if (yv[i] & MSB) {
		yv[i] &= MASK;
		hi = 1;}
	    else	break;}
	break;}
  }
  y=normalize_big(y);
}

/*
	Get_standardizing_factor_and_normalize(x)
	returns the standardizing factor of x.
	As a side-effect, x will be normalized.
	X should be a positive bignum.
	If x is multiplied by the standardizing factor,
	the most significant digit of x will be not less than 2**30,
	i.e. the most significant bit of that digit will be set.
*/

inline eusinteger_t get_standardizing_factor_and_normalize(x)
pointer x;
{ int size, s, newsize;
  eusinteger_t *xv, i, j;

  size=bigsize(x); xv=bigvec(x);
  s=size-1;
  newsize=size;
  while (xv[newsize-1]==0 && newsize>=0) newsize--;
  x->c.bgnm.bv->c.ivec.length=makeint(newsize);
  if (newsize==0) return(-1);
  for (j = 1, i = xv[newsize-1];  (i <<= 1) >= 0;  j <<= 1) ;
  return(j);
  }

/*
	Div_big_big(x0, y0) divides y0 by x0
	and destructively places the remainder in y0.
	X0 should be a normalized positive bignum,
	whose most significant digit is not less than 2**30.
	Y0 should be a non-negative bignum,
	whose length must be equal to the length of x0
	or one bigger than that.
	Div_big_big(x0, y0) returns the quotient of the division,
	which must be less than 2**31.
*/
eusinteger_t div_big_big(x, y)
pointer  x, y;
{ int xsize, ysize, zsize;
  eusinteger_t *xv, *yv, *zv;
  eusinteger_t  q,r; /*quotient, remainder*/

 
  xsize=bigsize(x); ysize=bigsize(y);
  xv=bigvec(x); yv=bigvec(y);

  if (xsize != ysize) {
    if (yv[xsize] >= xv[xsize-1])
        q = MASK-1;
	/*  This is the most critical point.  */
	/*  The long division will fail,  */
	/*  if the quotient can't lie in 31 bits.  */
    else {
	extended_div(xv[xsize-1], yv[xsize], yv[xsize-1], &q, &r);
	q -= 2;
		/*  You have to prove that 2 is enough,  */
		/*  by doing elementary arithmetic,  */
		/*  or refer to Knuth's dictionary.  */
	} }
  else
	q = yv[xsize-1] / xv[xsize-1] - 2;
  if (q <= 0)	q = 0;
  else	sub_int_big_big(q, x, y);
  while (big_compare(x, y) <= 0) {
    q++;
    sub_int_big_big(1, x, y); }
  return(q); }

inline pointer big_quotient_remainder_auxiliary(x, y, i)
pointer x, y;
int i;
{ pointer q, qq;
  int xsize, ysize;
  eusinteger_t *xv, *yv;

  xsize=bigsize(x); ysize=bigsize(y);

  if (i < 0)	return(NULL);
  if (i == 0) { /* x and y are of the same size */
	i = div_big_big(y, x);
	if (i == 0) return(NULL);
	else {
		qq = makebig(1);
		bigvec(qq)[0] = i;
#ifdef SAFETY
        take_care(qq);
#endif
		return(qq);
	}
    }

  qq=makebig(i);

  /********************????????????????????????**************/
#ifdef SAFETY
  take_care(qq);
#endif
  
  return(qq);}





/*
	Big_quotient_remainder(x0, y0, qp, rp)
	sets the quotient and the remainder of the division of x0 by y0
	to *qp and *rp respectively.
	qp and rp should be place holders on the value stack to protect
	from GC.
	X0 should be a positive bignum.
	Y0 should be a non-negative bignum.
*/
void big_quotient_remainder(x0, y0, qp, rp)
pointer x0, y0, *qp, *rp;
{
	context *ctx=euscontexts[thr_self()];
	pointer x, y;
	eusinteger_t i;
	int l, m;

	x = copy_big(x0);
	vpush(x);
	y = y0;
	i = get_standardizing_factor_and_normalize(y);
	mul_int_big(i, x);
	mul_int_big(i, y);
	l = bigsize(x);
	m = bigsize(y);
	*qp = big_quotient_remainder_auxiliary(x, y, l - m);
	if (*qp == NULL) {
		*qp = makebig1(0);
		}
	div_int_big(i, x);
	div_int_big(i, y);
	vpop();
	*rp = x;
}



int big_length(x)
pointer x;
{
	return(bigsize(x));
}

pointer normalize_big(pointer x)
{ int  size, i, newsize, positive;
  eusinteger_t  *xv;

  size=bigsize(x); xv=bigvec(x);
  newsize=size;
  positive = gez(xv[size-1]);
  for (i=size-1; i>=0; i--) {
    if (positive && xv[i]==0) newsize--;
    else if (!positive && xv[i]==-1 && size!=1) newsize--;
    else break;}
  if (newsize != size) {
    x->c.bgnm.bv->c.ivec.length=makeint(newsize);
    x->c.bgnm.size=makeint(newsize);
    if (!positive) xv[newsize-1] |= MSB;}
  return(x);
  }

pointer normalize_bignum(x)
pointer x;
{ eusinteger_t y, msb3;
  int bs;

  if (!isbignum(x)) return(x);
  normalize_big(x);

  bs=bigsize(x);
  if (bs==0) return(makeint(0));
  else if (bs==1) {
    y=x->c.bgnm.bv->c.ivec.iv[0];
    msb3= (y >> (WORD_SIZE-3)) & 0x7;
    if (msb3==0 || msb3==7)    return(makeint(y));}
  return(x);}

eusfloat_t big_to_float(pointer x)
{ int size, i;
  eusinteger_t *xv;
  double d, e;
  size=bigsize(x); xv=bigvec(x);

  for (i=0, d = 0.0, e = 1.0; i<size-1; i++) {
    d += e * (double)(xv[i]);
    e *= (double)((unsigned long)1 << (WORD_SIZE-1));
    }
  d += e * (double)(xv[size-1]);
  return(d);
}

pointer eusfloat_to_big(float f)
{ int i, j, exp, bsize, iz;
  pointer b;
  eusinteger_t *bv;
  double sign, z;
  extern double frexp(double, int *);
  extern double ldexp(double, int);

  if (f<0.0) {
    f= -f;
    if (f<=MAXPOSFIXNUM+1) {
      i=f;
      return(makeint(-i)); }
    else sign= -1;}
  else if (f<=MAXPOSFIXNUM) { /* 0x1fffffff on 32bit machines */
    i=f;
    return(makeint(i));}
  else sign= 1;

  /* here, f>MAXPOSFIXNUM */
  z=frexp(f, &exp);   /* f=z * 2^exp; 0.5<z<=1.0; exp>=30 */
		      /* z has at most 22bit or 52bit precision */
  z= ldexp(z, 24);
  bsize=(exp + WORD_SIZE - 2)/(WORD_SIZE - 1);
  b=makebig(bsize);
  exp -= 24;
  iz=z;
  bv=b->c.bgnm.bv->c.ivec.iv;
  i=exp / (WORD_SIZE -1);  
  j=exp % (WORD_SIZE -1);
  bv[i]= (iz << j) & MASK;
  if (j+24 > 31) bv[i+1]= (iz >> (WORD_SIZE -1 - j)) & MASK;
  if (sign<0) complement_big(b);
  return(b);
  }


