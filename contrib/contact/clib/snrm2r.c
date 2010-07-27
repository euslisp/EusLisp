/* Euclidean norm of the n-vector stored in sx()
   with storage -- row vector version
   Ver.1.0, July,1,1988.                         */

#include "arith.h"

REAL snrm2r(n,sx,isx,jsx,incx)
int n,isx,jsx,incx;
MATRIX sx;
{
    int i;
    REAL sum,enorm;

    if(n <=0)
	return(0.0);

    sum=0.0e0;

    for(i=0; i<n; i += incx){
	sum += sx[isx][jsx+i]*sx[isx][jsx+i];
    }

    enorm= sqrt(fabs(sum));

    if(enorm < EPS)
	enorm= 0.0e0;

    return(enorm);
}
