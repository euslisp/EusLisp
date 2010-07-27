/*     When an edge is outside a new hyperplane,             */
/*     delete it from the edge table and update the pointers */

#include "arith.h"

int update_edge(linetab,en,start)
LINE linetab[MAXEDGE];
int en,start;
{
   linetab[en].index= FALSE;

   if(en == start){
      start= linetab[start].next;
   }
   else{
      linetab[linetab[en].last].next=linetab[en].next;
      linetab[linetab[en].next].last=linetab[en].last;
   }
   return(start);
}

