/* Jan.17,1992.	Bug fix.	Set small coeficient be zero.	*/
#include "arith.h"

cone_inter(x,n,w)
float x[MAX][MAXRANK];
int n;
float w[MAXEDGE][MAXRANK];
{
    int i,j,en;
    MATRIX dx;
    REAL dw[MAXRANK][MAXEDGE];

    for(i=0; i<n; i++){
	for(j=0; j<MAXRANK; j++){
	    dx[i][j]=(double)x[i][j];
/* Set small coecifients be zero */
	    if(fabs(dx[i][j])<EPS)
		dx[i][j]=0;
	}
    }

    en=cone(dx,n,MAXRANK,dw);

    for(i=0; i<en; i++){
	for(j=0; j<MAXRANK; j++){
	    if(fabs(dw[j][i])<0.000001)
		w[i][j]=(float)0.0;
	    else
		w[i][j]=(float)dw[j][i];
	}
    }
    
    return(en);
}

	    
