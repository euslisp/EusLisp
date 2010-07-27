/* scales a vector by a constant.
   uses unrolled loops for increment equal to 1
   Ver.1.0, May,26,1988.                       */

#include "arith.h"

sscal(n,sa,sx,isx,jsx,incx)
int n,isx,jsx,incx;
REAL sa;
MATRIX sx;
{
    int i,m,nincx;

    if(n <= 0)
	return;

    if(incx != 1){

	/* code for increment not equal to 1 */

	nincx= n*incx;
	for(i=0; i<nincx; i += incx)
	    sx[isx+i][jsx]= sa*sx[isx+i][jsx];
    }

    else{

	/* code for increment equal to 1 */

	/* clean-up loop */

	m=n%5;
	if(m != 0){
	    for(i=0; i<m; i++)
		sx[isx+i][jsx]= sa*sx[isx+i][jsx];
	    if(n < 5)
		return;
	}

	for(i=m; i<n; i += 5){
	    sx[isx+i][jsx] = sa*sx[isx+i][jsx];
	    sx[isx+i+1][jsx] = sa*sx[isx+i+1][jsx];
	    sx[isx+i+2][jsx] = sa*sx[isx+i+2][jsx];
	    sx[isx+i+3][jsx] = sa*sx[isx+i+3][jsx];
	    sx[isx+i+4][jsx] = sa*sx[isx+i+4][jsx];
	}
    }
}
