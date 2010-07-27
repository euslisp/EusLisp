/* amax1 gives the maximum value of floating point numbers

                                    Ver1.0    Apr.12,1988. */

#include "arith.h"

REAL amax1(va_alist)
va_dcl
{
    va_list ap;
    int i,n;
    double max,x;

    va_start(ap);

    n=va_arg(ap, int);
    max=va_arg(ap, double);

    for(i=0; i<n-1; i++){
	x=va_arg(ap, double);
	if(x>max)
	    max=x;
    }

    return(max);

    va_end(ap);
}








