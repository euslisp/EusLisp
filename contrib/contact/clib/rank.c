#include "arith.h"

int rank(n,p,s)
int n,p;
MATRIX s;
{
    int i,full,rank,min0();

    full=min0(2,n,p);
    rank=0;

    for(i=0; i<full; i++){
	if(s[i][i]<NSPACE)
	    break;
	else
	    rank += 1;
    }

    return(rank);
}

