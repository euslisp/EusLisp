#include "arith.h"

cone(x,n,p,w)
MATRIX x;
int n,p;
REAL w[MAXRANK][MAXEDGE];
{
   MATRIX u,s,v,f;
   REAL fugo,fugo_calc();
   LINE linetab[MAXEDGE];
   register int i,j,en,ii,mi,m,mm,det,start,nn;
   register unsigned int planetab,planework;
   int ssvdc(),r[MAX];

   /* pre process, f= U1Drr */
   planetab=cone_pre(x,n,p,u,s,v,r,f);

   /* ask the edges of the initial cone */
   m=0;
   for(i=0; m<r[n]; i++){
     if((planetab & (1<<i)) != 0){
       planework=planetab & ~(1<<i);
       det=edge(f,n,planetab,planework,r[n],linetab,m);
       face_init(linetab,m,r[n]);
       m += 1;
     }
   }

   /* cut the initial cone by the remaining hyperplane */
   start=0;  mi=m;  mm=m;
   for(i=0; i<n; i++){
     /* check if hyperplane(i) is not used for the initial cone */
     if((planetab & (1<<i)) == 0){
       planetab= planetab | (1<<i);
       for(en=start; en<m; en=linetab[en].next){
	 fugo= fugo_calc(f,linetab,i,en,r[n]);
	 /* when edge(en) is outside the hyperplane(i), create new edges */
	 if(fugo < -EPS){
	   /* delete edge(en) from the edge table and update the pointers */
	   start= update_edge(linetab,en,start);
	   for(ii=0; linetab[en].face[ii] != EMPTY; ii++){
	     /* nn is the edge number sharing a common face with edge(en) */
	     nn=linetab[en].face[ii];
	     /* when edge(nn) is not outside the cone, the index is TRUE */
	     if(linetab[nn].index == TRUE){
	       fugo= fugo_calc(f,linetab,i,nn,r[n]);
	       /* when edge(nn) is not outside the cone, create a new edge */
	       /* next test is (fugo >= 0.0) if no numerical error exists  */  
	       if(fugo > -EPS){
		 /* planework is the common hyperplane between en and nn, */
		 /* and the new hyperplane(i)                             */
		 planework = linetab[en].plane & linetab[nn].plane;
		 planework = planework | (1<<i);
		 det=edge(f,n,planetab,planework,r[n],linetab,mm);
		 if(det == TRUE){ /* det is always TRUE in this case */
		   /* update the pointers between edge(nn) and the new edge */
		   for(j=0; linetab[nn].face[j] != en; j++)
		       ;
		   linetab[nn].face[j]=mm;
		   linetab[mm].face[0]=nn;
		   mm += 1;
		 }
	       }
	     }
	   }
	 }
       }
       m=mm;
       /* update the face pointers among new edges on the new hyperplane(i) */
       face(linetab,mi,m,r[n],n);
     }
     mi=m;
   }

   /* post process */
   en=cone_post(s,v,r,n,linetab,start,m,w);
   return(en);
}
