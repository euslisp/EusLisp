/*
   Singular value decomposition 
   interfacing with linpack
*/

#include "eus.h"

#define ismatrix(p) ((isarray(p) && \
		      p->c.ary.rank==makeint(2) && \
		      elmtypeof(p->c.ary.entity)==ELM_FLOAT))
#define rowsize(p) (intval(p->c.ary.dim[0]))
#define colsize(p) (intval(p->c.ary.dim[1]))


/* int r_sign; */

pointer SSVDC(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ pointer a=argv[0];
  float *amat,e[10],work[10];
  int col,row,ucol,urow,vcol,vrow,flag=11,info;
  pointer s,u,v;
  numunion nu;

  ckarg(4);
  if (!ismatrix(a)) error(E_NOARRAY);
  amat=a->c.ary.entity->c.fvec.fv;
  col=colsize(a); row=rowsize(a);

  if (debug) printf("ssvdc: row=%d col=%d\n",row,col);

  s=argv[1];
  if (!isfltvector(s)) error(E_FLOATVECTOR);
  if (vecsize(s)<col) error(E_VECINDEX);

  u=argv[2];
  if (!ismatrix(u)) error(E_NOARRAY);
  ucol=colsize(u); urow=rowsize(u);
  if (ucol!=col || urow!=col) error(E_VECINDEX);

  v=argv[3];
  if (!ismatrix(v)) error(E_NOARRAY);
  vcol=colsize(v); vrow=rowsize(v);
  if (vcol!=row || vrow!=row) error(E_VECINDEX);

  ssvdc_(amat, &col, &col, &row, s->c.fvec.fv,
				 e,
				 u->c.ary.entity->c.fvec.fv,
			 	 &col,
				 v->c.ary.entity->c.fvec.fv,
				 &row,
				 work,
				 &flag, &info);
  return(makeint(info));
  }

ssvdc(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{
  defun(ctx,"SSVDC",argv[0],SSVDC,NULL);}
	
