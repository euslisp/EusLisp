#include "arith.h"

REAL fugo_calc(f,linetab,i,en,r)
MATRIX f;
LINE linetab[MAXEDGE];
int i,en,r;
{
   REAL fugo;
   register int j;

   fugo=0.0;
   for(j=0; j<r; j++)
      fugo += f[i][j] * linetab[en].s[j];

   return(fugo);
}
