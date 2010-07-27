/* applies a plane rotation
   May,23,1988             */

#include "arith.h"

srot(n,sx,isx,jsx,incx,sy,isy,jsy,incy,c,s)
MATRIX sx,sy;
REAL c,s;
int n,incx,incy,isx,jsx,isy,jsy;
{
    REAL stemp;
    int i,ix,iy;

    if(n <= 0)
	return;

    if((incx != 1) || (incy != 1)){

	/* code for unequal increments or equal increments
	   not equal to 1 */
/*
	ix=1;
	iy=1;
	if(incx < 0)
	    ix= (-n+1)*incx+1;
	if(incy < 0)
	    iy= (-n+1)*incy+1;
	for(i=1; i<=n; i++){
	    stemp= c*sx[ix]+s*sy[iy];
	    sy[iy]= c*sy[iy]-s*sx[ix];
	    sx[ix]= stemp;
	    ix= ix+incx;
	    iy= iy+incy;
	}
*/
	return;
    }

/* code for both increments equal to 1 */

    for(i=0; i<n; i++){
	stemp= c*sx[isx+i][jsx]+s*sy[isy+i][jsy];
	sy[isy+i][jsy]= c*sy[isy+i][jsy]-s*sx[isx+i][jsx];
	sx[isx+i][jsx]=stemp;
    }

    return;
}



