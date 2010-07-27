/*								*/	
/*	Arithmetic Calculation Header				*/
/*								*/
/*	Ver.1.0, Apr. 5,1988.  for ssvdc()			*/
/*	Ver.1.1, Jul.16,1988.  for cone()               	*/
/*      Ver.1.2, Jul.22,1988.  for cone() with face pointer     */

#include <stdio.h>
#include <math.h>
#include <varargs.h>

#define MAX 50
#define MAXRANK 6
#define MAXEDGE 2000
#define EPS 1.0e-4
/* NSPACE is used for the threshold under which the singular value is zero. */
#define NSPACE 1.0e-4
#define UNIT 1.0e-4
#define TRUE 1
#define FALSE 0
#define EMPTY -1
#define COLLISION -2
#define HASHNO 15625

typedef double REAL;
typedef REAL VECTOR[MAX];
typedef VECTOR MATRIX[MAX];

typedef int TABLE[HASHNO];

typedef int LOGICAL;

typedef struct line {
    int index;
    int next;
    int last;
    int face[MAXRANK];
    unsigned int plane;
    REAL s[MAXRANK];
} LINE;





