/*								*/	
/*	Matrix Multiplication					*/
/*								*/
/*			Ver.1.0, Jan.18,1988.			*/
/*								*/

#include "arith.h"

mat_mult(n,m,l,amat,bmat,pmat)
int n,m,l;
MATRIX amat,bmat,pmat;
{
    int i,j,k;

    for(i=0; i<n; i++){
	for(k=0; k<l; k++){
	    pmat[i][k]=0.0e0;
	    for(j=0; j<m; j++){
		pmat[i][k] += amat[i][j] * bmat[j][k];
	    }
	}
    }
}
