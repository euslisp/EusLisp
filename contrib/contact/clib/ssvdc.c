/*  ssvdc is a function to compute the singular value decomposition
    of a matrix.

    Ver.1.00, Jun,3,1988.  
    Ver.1.01, Jul.14,1988.  remove the side effect to the matrix X   
    Ver.1.02, Jul.15,1988.  debug the matrix base shift routine     */

#include "arith.h"
#define MAXIT 30  /* the maximum number of iteratons */

ssvdc(xarg,ldx,n,p,s,e,u,ldu,v,ldv,work,job)
int n,p,ldx,ldu,ldv,job;
MATRIX xarg,s,e,u,v,work;
{
    int i,iter,j,jobu,k,kase,kk,l,ll,lls,lm1,lp1,ls,lu,m,maxit,info;
    int mm,mm1,mp1,nct,nctp1,ncu,nrt,nrtp1;
    int ii,jj;

    int max0(),min0();

    REAL t,r;
    REAL b,c,cs,el,emm1,f,g,scale,shift,sl,sm,sn,smm1,t1,test;
    REAL ztest;
    MATRIX x;

    REAL amax1(),sdot(),snrm2();

    LOGICAL wantu,wantv;

    /* shift the matrix base from 0 to 1 */

    for(ii=n-1; ii>=0; ii--)
	for(jj=p-1; jj>=0; jj--)
	    x[ii+1][jj+1]=xarg[ii][jj];

    /*  set the maximum number of iterations */

    maxit=MAXIT;

    /* determine what is to be computed */

    wantu=FALSE;
    wantv=FALSE;
    jobu=(job%100)/10;
    ncu=n;

    if(jobu > 1) ncu=min0(2,n,p);
    if(jobu != 0) wantu=TRUE;
    if((job%10) != 0) wantv=TRUE;

    /* reduce x to bidiagonal form,
       storing the diagonal elements in s and
       the super-diagonal elements in e */

    info=0;
    nct=min0(2,n-1,p);
    nrt=max0(2,0,min0(2,p-2,n));

    lu=max0(2,nct,nrt);

    if(lu >= 1){
	for(l=1; l<=lu; l++){
	    lp1=l+1;
	    if(l <= nct){

		/* compute the transformation for the l-th column and
		   place the l-th diagonal in s[l][1] */

		s[l][1]=snrm2(n-l+1,x,l,l,1);

		if(s[l][1] != 0.0e0){
		    if(x[l][l] != 0.0e0)
			s[l][1]=copysign(s[l][1],x[l][l]);
		    sscal(n-l+1,1.0e0/s[l][1],x,l,l,1);
		    x[l][l]=1.0e0+x[l][l];
		}
		s[l][1]= -s[l][1];
	    }
	    if(p >= lp1){
		for(j=lp1; j<=p; j++){
		    if(l <= nct)
			if(s[l][1] != 0.0e0){

			    /* apply the transformation */

			    t= -sdot(n-l+1,x,l,l,1,x,l,j,1)/x[l][l];
			    saxpy(n-l+1,t,x,l,l,1,x,l,j,1);
			}

		    /* place the l-th row of x into e for the subsequent
		       calculation of the row transformation */

		    e[j][1]=x[l][j];
		}
	    }
	    if(wantu && (l <= nct))

		/* place the transformation in u for subsequent 
		   back multiplication */

		for(i=l;i<=n;i++)
		    u[i][l]=x[i][l];
	    if(l <= nrt){

		/* compute the l-th row transformation and
		   place the l-th super-diagonal in e[l][1] */

		e[l][1]=snrm2(p-l,e,lp1,1,1);
		if(e[l][1] != 0.0e0){
		    if(e[lp1][1] != 0.0e0)
			e[l][1]=copysign(e[l][1],e[lp1][1]);
		    sscal(p-l,1.0e0/e[l][1],e,lp1,1,1);
		    e[lp1][1]=1.0e0+e[lp1][1];
		}
		e[l][1]= -e[l][1];
		if((lp1 <= n) && (e[l][1] != 0.0e0)){

		    /* apply the transformation */

		    for(i=lp1; i<=n; i++)
			work[i][1]=0.0e0;
		    for(j=lp1; j<=p; j++)
			saxpy(n-l,e[j][1],x,lp1,j,1,work,lp1,1,1);
		    for(j=lp1; j<=p; j++)
			saxpy(n-l,-e[j][1]/e[lp1][1],work,lp1,1,1,x,lp1,j,1);
		}
		if(wantv)

		    /* place the transformation in v for subsequent
		       back multiplication */

		    for(i=lp1; i<=p; i++)
			v[i][l]=e[i][1];
	    }
	}
    }

    /* set up the final bidiagonal matrix or order m. */

    m=min0(2,p,n+1);

    nctp1=nct+1;
    nrtp1=nrt+1;
    if(nct < p)
	s[nctp1][1]=x[nctp1][nctp1];
    if(n < m)
	s[m][1]=0.0e0;
    if(nrtp1 < m)
	e[nrtp1][1]=x[nrtp1][m];
    e[m][1]=0.0e0;

    /* if required, generate u. */

    if(wantu){
	if(ncu >= nctp1){
	    for(j=nctp1; j<=ncu; j++){
		for(i=1; i<=n; i++)
		    u[i][j]=0.0e0;
		u[j][j]=1.0e0;
	    }
	}
	if(nct >= 1){
	    for(ll=1; ll<=nct; ll++){
		l=nct-ll+1;
		if(s[l][1] != 0.0e0){
		    lp1=l+1;
		    if(ncu >= lp1){
			for(j=lp1; j<=ncu; j++){
			    t= -sdot(n-l+1,u,l,l,1,u,l,j,1)/u[l][l];
			    saxpy(n-l+1,t,u,l,l,1,u,l,j,1);
			}
		    }
		    sscal(n-l+1,-1.0e0,u,l,l,1);
		    u[l][l]=1.0e0+u[l][l];
		    lm1=l-1;
		    if(lm1 >= 1)
			for(i=1; i<=lm1; i++)
			    u[i][l]=0.0e0;
		}
		else{
		    for(i=1; i<=n; i++)
			u[i][l]=0.0e0;
		    u[l][l]=1.0e0;
		}
	    }
	}
    }

    /* if it is required, generate v. */

    if(wantv){
	for(ll=1; ll<=p; ll++){
	    l=p-ll+1;
	    lp1=l+1;
	    if(l <= nrt)
		if(e[l][1] != 0.0e0){
		    for(j=lp1; j<=p; j++){
			t= -sdot(p-l,v,lp1,l,1,v,lp1,j,1)/v[lp1][l];
			saxpy(p-l,t,v,lp1,l,1,v,lp1,j,1);
		    }
		}
	    for(i=1; i<=p; i++)
		v[i][l]=0.0e0;
	    v[l][l]=1.0e0;
	}
    }

    /* main iteration loop for the singular values */

    mm=m;
    iter=0;

    /* quit if all the singular values have been found. */

    while(m != 0){

	if(iter >= maxit){
	    info=m;
	    break;
	}

	/* this section of the program inspects for 
	   negligible elements in the s and e arrays. on
	   completion the variables kase and l are set as follows

	   kase=1	if s(m) and e(l-1) are negligible and l<m
	   kase=2	if s(l) is negligible and l<m
	   kase=3	if e(l-1) is negligible, l<m, and
	                s(l), ..., s(m) are not negligible (QR step).
	   kase=4	if e(m-1) is negligible (convergence).
								*/

	for(ll=1; ll<=m; ll++){
	    l=m-ll;
	    if(l == 0)
		break;
	    test=fabs(s[l][1])+fabs(s[l+1][1]);
	    ztest=test+fabs(e[l][1]);
	    if(ztest == test){
		e[l][1]=0.0e0;
		break;
	    }
	}

	if(l == (m-1))
	    kase=4;
	else{
	    lp1=l+1;
	    mp1=m+1;
	    for(lls=lp1; lls<=mp1; lls++){
		ls=m-lls+lp1;
		if(ls == l)
		    break;
		test=0.0e0;
		if(ls != m)
		    test += fabs(e[ls][1]);
		if(ls != (l+1))
		    test += fabs(e[ls-1][1]);
		ztest=test+fabs(s[ls][1]);
		if(ztest == test){
		    s[ls][1]=0.0e0;
		    break;
		}
	    }
	    
	    if(ls == l)
		kase=3;
	    else if(ls == m)
		kase=1;
	    else{
		kase=2;
		l=ls;
	    }
	}
	l=l+1;

	/* perform the task indicated by kase */

	switch(kase){

	    /* deflate neglegible s[m] */

	  case 1:
	    mm1=m-1;
	    f=e[m-1][1];
	    e[m-1][1]=0.0e0;
	    for(kk=l; kk<=mm1; kk++){
		k=mm1-kk+l;
		t1=s[k][1];
		srotg(&t1,&f,&cs,&sn);
		s[k][1]=t1;
		if(k != l){
		    f= -sn*e[k-1][1];
		    e[k-1][1]=cs*e[k-1][1];
		}
		if(wantv)
		    srot(p,v,1,k,1,v,1,m,1,cs,sn);
	    }
	    break;

	    /* split at negligible s[l] */

	  case 2:
	    f=e[l-1][1];
	    e[l-1][1]=0.0e0;
	    for(k=l; k<=m; k++){
		t1=s[k][1];
		srotg(&t1,&f,&cs,&sn);
		s[k][1]=t1;
		f= -sn*e[k][1];
		e[k][1]=cs*e[k][1];
		if(wantu)
		    srot(n,u,1,k,1,u,1,l-1,1,cs,sn);
	    }
	    break;

	    /* perform one QR step */

	  case 3:

	    /* calculate the shift */

	    scale=amax1(5,fabs(s[m][1]),fabs(s[m-1][1]),fabs(e[m-1][1]),
			 fabs(s[l][1]),fabs(e[l][1]));
	    sm=s[m][1]/scale;
	    smm1=s[m-1][1]/scale;
	    emm1=e[m-1][1]/scale;
	    sl=s[l][1]/scale;
	    el=e[l][1]/scale;
	    b=((smm1+sm)*(smm1-sm)+emm1*emm1)/2.0e0;
	    c=(sm*emm1)*(sm*emm1);
	    shift=0.0e0;
	    if((b != 0.0e0) || (c != 0.0e0)){
		shift=sqrt(b*b+c);
		if(b < 0.0e0)
		    shift= -shift;
		shift=c/(b+shift);
	    }
	    f=(sl+sm)*(sl-sm)-shift;
	    g=sl*el;

	    /* chase zeros. */

	    mm1=m-1;
	    for(k=l; k<=mm1; k++){
		srotg(&f,&g,&cs,&sn);
		if(k != l)
		    e[k-1][1]=f;
		f=cs*s[k][1]+sn*e[k][1];
		e[k][1]=cs*e[k][1]-sn*s[k][1];
		g=sn*s[k+1][1];
		s[k+1][1]=cs*s[k+1][1];
		if(wantv)
		    srot(p,v,1,k,1,v,1,k+1,1,cs,sn);
		srotg(&f,&g,&cs,&sn);
		s[k][1]=f;
		f=cs*e[k][1]+sn*s[k+1][1];
		s[k+1][1]= -sn*e[k][1]+cs*s[k+1][1];
		g=sn*e[k+1][1];
		e[k+1][1]=cs*e[k+1][1];
		if(wantu && (k < n)){
		    srot(n,u,1,k,1,u,1,k+1,1,cs,sn);
		}
	    }
	    e[m-1][1]=f;
	    iter=iter+1;
	    break;

	    /* convergence */

	  case 4:

	    /* make the singular value positive */

	    if(s[l][1] < 0.0e0){
		s[l][1]= -s[l][1];
		if(wantv)
		    sscal(p,-1.0e0,v,1,l,1);
	    }

	    /* order the singular value */

	    while(l != mm){
		if(s[l][1] >= s[l+1][1])
		    break;

		t=s[l][1];
		s[l][1]=s[l+1][1];
		s[l+1][1]=t;
		if(wantv && (l < p))
		    sswap(p,v,1,l,1,v,1,l+1,1);
		if(wantu && (l < n))
		    sswap(n,u,1,l,1,u,1,l+1,1);
		l=l+1;
	    }
	    iter=0;
	    m=m-1;
	    break;
	}
    }
    /* shift the matrix base from 1 to 0 */
    /* move the singular values from the 1st column to diagonal position */

    for(ii=0; ii<n; ii++)
	for(jj=0; jj<n; jj++)
	    u[ii][jj]=u[ii+1][jj+1];

    for(ii=0; ii<n; ii++){
	s[ii][ii]=s[ii+1][1];
	for(jj=0; jj<p; jj++)
	    if(ii != jj)
		s[ii][jj]=0.0e0;
    }

    for(ii=0; ii<p; ii++)
	for(jj=0; jj<p; jj++)
	    v[ii][jj]=v[ii+1][jj+1];

    return(info);
}
