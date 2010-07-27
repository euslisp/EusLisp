/*   07/13/95 Bug fix.  rr[i] is introduced instead of r[i],
                        because r[n] happens to be overwritten
			when i=n in the last loop.                          */

#include "arith.h"

cone_pre(x,n,p,u,s,v,r,f)
MATRIX x;
int n,p;
MATRIX u,s,v;
int r[MAX];
MATRIX f;
{
    MATRIX e,work;
    int job,info, rr[MAX];
    int i,j;
    int ssvdc();

    MATRIX ss,uu,vv;
    unsigned int planetab;

    /* singular value decomposition of the matrix C */

    job=11;

    info=ssvdc(x,n,n,p,s,e,u,n,v,p,work,job);

    /* determine the rank of C */
    
    r[n]=rank(n,p,s);

    /* substitute U1Drr to F */

    mat_mult(n,r[n],r[n],u,s,f);

    /* select r independent hyperplane */

    rr[0]=0;
    planetab=0;
    for(i=1; i<=n; i++){
	info=ssvdc(f,i,i,r[n],ss,e,uu,i,vv,r[n],work,job);
	rr[i]=rank(i,r[n],ss);
	if(rr[i] == rr[i-1]+1)
	    planetab= planetab | (1<<(i-1));
	if(rr[i] == r[n])
	    break;
    }
    return(planetab);
}
