/* Oct.12, 1990.  Bug fix. when r==1, skip ssvdc() because r-1 becomes 0 */

#include "arith.h"

edge(f,n,planetab,planework,r,linetab,m)
MATRIX f;
int n;  /* n = the row number of C */
unsigned int planetab;
unsigned int planework;
int r;  /* r = rankC */
LINE linetab[MAXEDGE];
int m;
{
    MATRIX fwork,s,e,u,v,work;
    VECTOR fugo;
    register int positive,negative;
    register int i,ii,j,job,info;

    if(r == 1){
      v[0][0]= f[0][0]/fabs(f[0][0]);
    }
    else{
      ii=0;
      for(i=0; ii<r-1; i++)
	  if((planework & (1<<i)) != 0){
	    for(j=0; j<r; j++)
		fwork[ii][j]= f[i][j];
	    ii += 1;
	  }
      job=11;
      info=ssvdc(fwork,r-1,r-1,r,s,e,u,r-1,v,r,work,job);
    }

/*
    if(s[r-2][r-2] < EPS)
	return(FALSE);
*/

    /* check the new edge is not outside the cone                        */
    /* however it may has no meaning, only sign for the edge is required */

    positive=0;
    negative=0;
    for(i=0; i<n; i++){
	if((planetab & (1<<i)) != 0){
	    fugo[i]=0.0e0;
	    for(j=0; j<r; j++)
		fugo[i] += f[i][j] * v[j][r-1];
	    if(fugo[i]>EPS){
		positive =  1;
	    }
	    if(fugo[i]<-EPS){
		negative = -1;
	    }
	    if((positive * negative) != 0)
		return(FALSE);
	}
    }

    if(negative == -1){
	for(j=0; j<r; j++){
	    v[j][r-1]= -v[j][r-1];
	}
    }

    linetab[m].index=TRUE;
    linetab[m].next=m+1;
    linetab[m].last=m-1;
    linetab[m].plane=planework;
    for(j=0; j<r; j++)
	linetab[m].s[j]= v[j][r-1];
    return(TRUE);
}
