/*								*/	
/*	Matrix Multiplication with an entory point              */
/*								*/
/*			Ver.1.0, Jun,30,1988.			*/
/*								*/

#include "arith.h"

mat_mult2(n,m,l,amat,ai,aj,bmat,bi,bj,pmat)
int n,m,l,ai,aj,bi,bj;
MATRIX amat,bmat,pmat;
{
	int i,j,k;

	for(i=0; i<n; i++){
	  for(k=0; k<l; k++){
	    pmat[i][k]=0;
	    for(j=0; j<m; j++){
	      pmat[i][k] += amat[ai+i][aj+j] * bmat[bi+j][bj+k];
	    }
	  }
	}
}
