/* Oct.16, 1990.                                                     */
/* 123456.789 was changed to 12345.6789 because hash is too sensible */

#include "arith.h"

hash5(w)
VECTOR w;
{
    REAL x,d[MAXRANK];
    int i,hash;

    for(i=0; i<MAXRANK; i++){
	d[i]= (w[i]+1)*1.5;
    }

    x = d[0]*1.23+d[1]*3.21+d[2]*2.35+d[3]*16.35+d[4]*23.57+d[5]*15.63;
    hash= (int)(12345.6789 * x) % HASHNO;
    return(hash);
}

