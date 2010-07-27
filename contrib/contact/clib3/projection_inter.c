/* Jan.17,1992.	Bug fix.	Set small coeficient be zero.	*/
#include "arith.h"

projection_inter(x,n,motion_in,motion_out)
float x[MAX][MAXRANK];
int n;
float motion_in[MAXRANK], motion_out[MAXRANK];
{
    int i,j,en;
    REAL dx[MAX][MAXRANK];
    REAL dw[MAXRANK][MAXEDGE], dm_in[MAXRANK], dm_out[MAXRANK];

    for(j=0; j<MAXRANK; j++){
      dm_in[j] = (double)motion_in[j];
    }

    for(i=0; i<n; i++){
	for(j=0; j<MAXRANK; j++){
	    dx[i][j]=(double)x[i][j];
	    /* Set small coecifients be zero */
	    if(fabs(dx[i][j])<EPS)
		dx[i][j]=0;
	}
    }

    projection(dx,n,dm_in,dm_out);

    for(j=0; j<MAXRANK; j++){
      if(fabs(dm_out[j])<EPS)
	  motion_out[j]=(float)0.0;
      else
	  motion_out[j]=(float)dm_out[j];
    }
    
    return;
}

	    
