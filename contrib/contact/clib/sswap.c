/* interchanges two vectors
   uses unrolled loops for increments equal to 1.
   Ver.1.0, May,26,1988.                         */

#include "arith.h"

sswap(n,sx,isx,jsx,incx,sy,isy,jsy,incy)
int n,isx,jsx,incx,isy,jsy,incy;
MATRIX sx,sy;
{
    REAL stemp;
    int i,ix,iy,m;

    if(n <= 0)
	return;

    /* code for both increments equal to 1 */

    /* clean-up loop */

    m=n%3;
    if(m != 0){
	for(i=0; i<m; i++){
	    stemp=sx[isx+i][jsx];
	    sx[isx+i][jsx]=sy[isy+i][jsy];
	    sy[isy+i][jsy]=stemp;
	}
	if(n < 3)
	    return;
    }

    for(i=m; i<n; i += 3){
	    stemp=sx[isx+i][jsx];
	    sx[isx+i][jsx]=sy[isy+i][jsy];
	    sy[isy+i][jsy]=stemp;
	    stemp=sx[isx+i+1][jsx];
	    sx[isx+i+1][jsx]=sy[isy+i+1][jsy];
	    sy[isy+i+1][jsy]=stemp;
	    stemp=sx[isx+i+2][jsx];
	    sx[isx+i+2][jsx]=sy[isy+i+2][jsy];
	    sy[isy+i+2][jsy]=stemp;
	}
}
