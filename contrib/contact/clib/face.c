/*    make the pointers among new edges on the new hyperplane */

#include "arith.h"

face(linetab,mi,m,r,n)
LINE linetab[MAXEDGE];
int mi,m,r,n;
{
    register int i,j,k,l,count;
    register unsigned int planework;

    /* check all combination of two new edges on hyperplane(i) */
    for(i=mi; i<m; i++){
	l=1;
	for(j=mi; j<m; j++){
	    if(i != j){
		planework= linetab[i].plane & linetab[j].plane;
		count=0;
		for(k=0; k<n; k++){
		    if((planework & (1<<k)) != 0)
			count += 1;
		}
		/* when (r-2) hyperplanes are common, make face pointer */
		if(count == (r-2)){
		    linetab[i].face[l]=j;
		    l += 1;
		}
	    }
	}
	/* make a mark indicating there is no futher face pointer */
	linetab[i].face[l]=EMPTY;
    }
}

