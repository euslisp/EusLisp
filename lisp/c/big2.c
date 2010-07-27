pointer 
big_quotient_remainder_auxiliary(x, y, i)
pointer x, y;
int i;
{ pointer q, qq;
  int xsize, ysize, *xv, *yv, j, k;
  xsize=bigsize(x); ysize=bigsize(y);

  if (i < 0)	return(NULL);
  if (i == 0) {
	i = div_big_big(y, x);
	if (i == 0) return(NULL);
	else {
		qq = makebig(1);
		bigvec(qq)[0] = i;
		return(qq);
	}
    }

  qq=makebig(i);

  for (k=i-1; k>=0; i--) {
    j=div_big_big

  q = big_quotient_remainder_auxiliary(x->big_cdr, y, i-1);
  i = div_big_big(y, x);
  vpush(((object)q));
  qq = (struct bignum *)alloc_object(t_bignum);
  
  qq->big_car = i;
  qq->big_cdr = q;
  return(qq);}

/*
	Big_quotient_remainder(x0, y0, qp, rp)
	sets the quotient and the remainder of the division of x0 by y0
	to *qp and *rp respectively.
	X0 should be a positive bignum.
	Y0 should be a non-negative bignum.
*/
big_quotient_remainder(x0, y0, qp, rp)
pointer x0, y0, *qp, *rp;
{
	context *ctx=euscontexts[thr_self()];
	pointer x, y;
	int i, l, m;

	x = copy_big(x0);
	vpush(x);
	y = y0;
	i = get_standardizing_factor_and_normalize(y);
	mul_int_big(i, x);
	mul_int_big(i, y);
	l = bigxize(x);
	m = bigsize(y);
	*qp = big_quotient_remainder_auxiliary(x, y, l - m);
	if (*qp == NULL) {
		*qp = makebig(1);
		(*qp)->c.bgnm.bv->c.ivec.iv[0] = 0;
	}
	div_int_big(i, x);
	div_int_big(i, y);
	vpop();
	*rp = x;
}
