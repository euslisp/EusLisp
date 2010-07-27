/* min0 gives the minimum value of integers

                                    Ver1.0    Apr.12,1988. */

#include "arith.h"

int min0(va_alist)
va_dcl
{
    va_list ap;
    int i,n;
    int min,x;

    va_start(ap);

    n=va_arg(ap, int);
    min=va_arg(ap, int);

    for(i=0; i<n-1; i++){
	x=va_arg(ap, int);
	if(x<min)
	    min=x;
    }

    return(min);

    va_end(ap);
}








