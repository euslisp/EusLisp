/* max0 gives the maximum value of integers

                                    Ver1.0    Apr.12,1988. */

#include "arith.h"

int max0(va_alist)
va_dcl
{
    va_list ap;
    int i,n;
    int max,x;

    va_start(ap);

    n=va_arg(ap, int);
    max=va_arg(ap, int);

    for(i=0; i<n-1; i++){
	x=va_arg(ap, int);
	if(x>max)
	    max=x;
    }

    return(max);

    va_end(ap);
}








