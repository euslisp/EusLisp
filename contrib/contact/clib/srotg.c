/* construct givens plane rotation
   Ver.1.0 May 20,1988            */

#include "arith.h"

srotg(psa,psb,pc,ps)
REAL *psa,*psb,*pc,*ps;
{
    REAL sa,sb,c,s;
    REAL roe,scale,r,z;

    sa= *psa;
    sb= *psb;
    c= *pc;
    s= *ps;

    roe=sb;
    if(fabs(sa) > fabs(sb))
	roe=sa;
    scale=fabs(sa)+fabs(sb);

    if(scale == 0.0){
	c=1.0;
	s=0.0;
	r=0.0;
    }
    else{
	r=scale*sqrt((sa/scale)*(sa/scale)+(sb/scale)*(sb/scale));
	r=copysign(1.0,roe)*r;
	c=sa/r;
	s=sb/r;
    }
    z=1.0;
    if(fabs(sa)>fabs(sb))
	z=s;
    if((fabs(sb) >= fabs(sa)) && (c != 0.0e0))
	z=1.0/c;
    sa=r;
    sb=z;

    *psa= sa;
    *psb= sb;
    *pc= c;
    *ps= s;
}
