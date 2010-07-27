/* Euclidean norm of the n-vector stored in sx()
   with storage -- Simplified Version
   Ver.1.0, May,26,1988.                         */

#include "arith.h"
#define CUTLO 4.441e-16
#define CUTHI 1.304e19
#define ZERO 0.0e0
#define ONE 1.0e0
#define SXI sx[isx+i][jsx]

REAL snrm2(n,sx,isx,jsx,incx)
int n,isx,jsx,incx;
MATRIX sx;
{
    int i,j,next,nn;
    REAL hitest,sum,xmax,snrm;

    if(n <=0)
	return(0.0);

    next=30;
    sum= ZERO;
    nn= n*incx;

    i=0;

  label20:
    switch(next){
      case 30:
	goto label30;
	break;

      case 50:
	goto label50;
	break;

      case 70:
	goto label70;
	break;

      case 110:
	goto label110;
	break;
    }

  label30:
    if(fabs(SXI) > CUTLO)
	goto label85;
    next=50;
    xmax=ZERO;

    /* phase 1. sum is zero */

  label50:
    if(SXI == ZERO)
	goto label200;
    if(fabs(SXI) > CUTLO)
	goto label85;

    /* prepare for pahse 2. */

    next=70;
    goto label105;

    /* prepare for phase 4. */

  label100:
    i=j;
    next=110;
    sum=(sum/SXI)/SXI;

  label105:
    xmax=fabs(SXI);
    goto label115;

    /* phase 2. sum is small.
                scale to avoid destructive underflow. */

  label70:
    if(fabs(SXI) > CUTLO)
	goto label75;

    /* common code for phases 2 and 4.
       in phase 4 sum is large.  scale to avoid overflow. */

  label110:
    if(fabs(SXI) <= xmax)
	goto label115;
    sum= ONE + sum*(xmax/SXI)*(xmax/SXI);
    xmax=fabs(SXI);
    goto label200;

  label115:
    sum= sum+(SXI/xmax)*(SXI/xmax);
    goto label200;

    /* prepare for phase 3. */

  label75:
    sum= (sum*xmax)*xmax;

    /* for real or D.P. set hitest= CUTHI/n */

  label85:
    hitest= CUTHI/(double)n;

    /* phase 3. sum is mid-range. no scaling. */

    for(j=i; j<nn; j += incx){
	if(fabs(SXI) >= hitest)
	    goto label100;
	sum= sum+ sx[isx+j][jsx]*sx[isx+j][jsx];
    }

    snrm= sqrt(sum);
    return(snrm);

  label200:
    i= i+incx;
    if(i < nn)
	goto label20;

    /* end of main loop
       computer square root and adjust for scaling. */

    snrm= xmax*sqrt(sum);
    return(snrm);
}
