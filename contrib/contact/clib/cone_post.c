/* Oct 12, 1990.  Bug fix.  substitute V2 to w based on the rank(C) */

#include "arith.h"

cone_post(s,v,r,n,linetab,start,m,w)
MATRIX s;
MATRIX v;
int r[MAX],n;
LINE linetab[MAXEDGE];
int start,m;
REAL w[MAXRANK][MAXEDGE];
{
   TABLE hashtab;
   int i,j,k,en,hash;

    for(i=0; i<HASHNO; i++)
	hashtab[i]= EMPTY;

    en=0;
    for(k=start; k<m; k=linetab[k].next){
	for(i=0; i<MAXRANK; i++){
	    w[i][en]=0.0e0;
	    for(j=0; j<r[n]; j++){
		w[i][en] += v[i][j] * linetab[k].s[j];
	    }
	}
	hash=same(w,en,hashtab);
	if(hash != COLLISION){
	    hashtab[hash]=en;
	    en += 1;
	}
    }

/*   printf("edge number = %d\n",en); */

    for(j=r[n]; j<MAXRANK; j++){
      for(i=0; i<MAXRANK; i++){
	w[i][en]= v[i][j];
	w[i][en+1]= -v[i][j];
      }
      en += 2;
    }

    return(en);
}
