#include "arith.h"

projection(x,n,motion_in,motion_out)
REAL x[MAX][MAXRANK];
int n;
REAL motion_in[MAXRANK],motion_out[MAXRANK];
{
   register int i,j,k;
   register unsigned int planetab,planework;
   int l[MAXRANK];
   REAL v_norm,distance,max_negative_distance,inner_product;
   REAL q[MAXRANK][MAXRANK],h[MAX][MAXRANK][MAXRANK];

   /* orthogonalize the normal vectors of the hyperplanes. */

   for(i=0; i<n; i++){
     v_norm = 0.0e0;
     for(j=0; j<MAXRANK; j++){
       v_norm += x[i][j] * x[i][j];
     }
     v_norm = sqrt(v_norm);
     for(j=0; j<MAXRANK; j++){
       h[i][j][0] = x[i][j] / v_norm;
     }
   }

   /* return motion_in if it is inside the cone */

   for(i=0; i<n; i++){
     distance = 0.0e0;
     for(j=0; j<MAXRANK; j++){
       distance += x[i][j] * motion_in[j];
     }
     if(distance < -EPS2) break;
   }
   if(distance > -EPS2){
     /* printf("in the cone\n"); */
     for(j=0; j<MAXRANK; j++) motion_out[j] = motion_in[j];
     return;
   }


   /* project the query vector onto the closest hyperplane */
   
   max_negative_distance = 0.0e0;
   for(i=0; i<n; i++){
     distance = 0.0e0;
     for(j=0; j<MAXRANK; j++){
       distance += h[i][j][0] * motion_in[j];
     }
     if(distance < max_negative_distance){
       max_negative_distance = distance;
       l[1] = i;
     }
   }
   for(j=0; j<MAXRANK; j++){
     q[1][j] = motion_in[j] - max_negative_distance * h[l[1]][j][0];
   }

   /* output the projection onto the hyperplane if it is relatively inside. */

   for(i=0; i<n; i++){
     distance = 0.0e0;
     for(j=0; j<MAXRANK; j++){
       distance += h[i][j][0] * q[1][j];
     }
     if(distance < -EPS2) break;
   }
   if(distance > -EPS2){
     /* printf("on the first hyperplane\n"); */
     for(j=0; j<MAXRANK; j++) motion_out[j]=q[1][j];
     return;
   }

   /* start the recursive routine. */

   for(k=1; k<=MAXRANK-2; k++){
     for(i=0; i<n; i++){
       inner_product = 0.0e0;
       for(j=0; j<MAXRANK; j++)
	   inner_product += h[l[k]][j][k-1] * h[i][j][k-1];
       v_norm = 0.0e0;
       for(j=0; j<MAXRANK; j++){
	 h[i][j][k] = h[i][j][k-1] - inner_product * h[l[k]][j][k-1];
	 v_norm += h[i][j][k] * h[i][j][k];
       }
       if(v_norm > EPS){
	 v_norm = sqrt(v_norm);
	 for(j=0; j<MAXRANK; j++) h[i][j][k] = h[i][j][k] / v_norm;
       }
     }

     max_negative_distance = 0.0e0;

     for(i=0; i<n; i++){
       distance = 0.0e0;
       for(j=0; j<MAXRANK; j++){
	 distance += h[i][j][k] * q[k][j];
       }
       if(distance < max_negative_distance){
	 max_negative_distance = distance;
	 l[k+1] = i;
       }
     }
     distance = 0.0e0; inner_product = 0.0e0;
     for(j=0; j<MAXRANK; j++){
       distance += h[l[k+1]][j][0] * q[k][j];
       inner_product += h[l[k+1]][j][0] * h[l[k+1]][j][k];
     }
     for(j=0; j<MAXRANK; j++){
       q[k+1][j] = q[k][j] - distance * h[l[k+1]][j][k] / inner_product;
     }
    
   /* output the projection onto the (d-k) face if it is relatively inside. */

     for(i=0; i<n; i++){
       distance = 0.0e0;
       for(j=0; j<MAXRANK; j++){
	 distance += h[i][j][0] * q[k+1][j];
       }
       if(distance < -EPS2) break;
     }
     if(distance > -EPS2){
       /* printf("on the d-%d face\n",k+1); */
       for(j=0; j<MAXRANK; j++) motion_out[j]=q[k+1][j];
       return;
     }
   }

   /* printf("Error - The projection could not be found.\n"); */

   /* the input is in the dual polyhedral convex cone. */
   for(j=0; j<MAXRANK; j++) motion_out[j]=0.0e0;

   return;
}
