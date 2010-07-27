/* constant times a vector plus a vector.
   uses unrolled loop for increments equal to one.
   Ver.1.0, May,26,1988.                          */

#include "arith.h"

saxpy(n,sa,sx,isx,jsx,incx,sy,isy,jsy,incy)
int n,isx,jsx,incx,isy,jsy,incy;
REAL sa;
MATRIX sx,sy;
{
    int i,m;

    if(n <= 0)
	return;
    if(sa == 0.0e0)
	return;

    /* code for both increments equal to 1 */

    /* clean-up loop */

    m=n%4;
    if(m != 0){
	for(i=0; i<m; i++)
	    sy[isy+i][jsy] += sa*sx[isx+i][jsx];
	if(n < 4)
	    return;
    }

    for(i=m; i<n; i += 4){
	sy[isy+i][jsy] += sa*sx[isx+i][jsx];
	sy[isy+i+1][jsy] += sa*sx[isx+i+1][jsx];
	sy[isy+i+2][jsy] += sa*sx[isx+i+2][jsx];
	sy[isy+i+3][jsy] += sa*sx[isx+i+3][jsx];
    }
}




