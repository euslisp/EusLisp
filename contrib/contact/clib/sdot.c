/* forms the dot product of two vectors
   uses unrolled loops for increments equal to one
   Ver.1.0, May,23,1988                            */

#include "arith.h"

REAL sdot(n,sx,isx,jsx,incx,sy,isy,jsy,incy)
int n,incx,incy,isx,jsx,isy,jsy;
MATRIX sx,sy;
{
    REAL stemp;
    int i,ix,iy,m;

    stemp=0.0;

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
	    stemp= stemp+sx[ix][1]*sy[iy][1];
	    ix= ix+incx;
	    iy= iy+incy;
	}

	return(stemp);
*/
    }

    /* code for both increments equal to 1 */

    /* clean-up loop */

    m=n%5;
    if(m != 0){
	for(i=0; i<m; i++)
	    stemp= stemp+sx[isx+i][jsx]*sy[isy+i][jsy];
    }
    if((m == 0) || (n >= 5)){
	for(i=m; i<n; i += 5)
	    stemp= stemp+sx[isx+i][jsx]*sy[isy+i][jsy]
		        +sx[isx+i+1][jsx]*sy[isy+i+1][jsy]
			+sx[isx+i+2][jsx]*sy[isy+i+2][jsy]
			+sx[isx+i+3][jsx]*sy[isy+i+3][jsy]
			+sx[isx+i+4][jsx]*sy[isy+i+4][jsy];
    }

    return(stemp);
}





