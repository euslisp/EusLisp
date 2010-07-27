#include "arith.h"

face_init(linetab,m,r)
LINE linetab[MAXEDGE];
int m;
int r;
{
    int i,en;

    en=0;
    /* make rC2 face pointers among r edge */
    for(i=0; i<r; i++){
	if(i != m){
	    linetab[m].face[en]=i;
	    en += 1;
	}
    }
    linetab[m].face[en]=EMPTY;
}

