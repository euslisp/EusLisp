#include "arith.h"

mat_copy(x,y,n,p)
MATRIX x,y;
int n,p;
{
    int i,j;

    for(i=0; i<n; i++){
	for(j=0; j<p; j++){
	    y[i][j] = x[i][j];
	}
    }
}
