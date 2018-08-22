/* intersection.c
   finds an intersection point of two lines
   (c)1987, MATSUI T., ETL
   
   1998--
   Since this file is compiled and linked in the libeusgeo.so library,
   this must be compiled with the -fpic (position independent) option.

*/

#include "../c/eus.h"
#pragma init (init_object_module)
extern pointer intersection();

static void init_object_module()
  { add_module_initializer("intersection", intersection);}

pointer LINEINTERSECTION(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{
  eusfloat_t cz,u,v;
  eusfloat_t a1x,a1y,b1x,b1y;
  register eusfloat_t ax,ay,bx,by,abx,aby;
  int range_check;
  pointer up,vp;  
  numunion nu;

  ckarg2(4,5);
  if (!isfltvector(argv[0])) error(E_FLOATVECTOR,NULL);
  if (!isfltvector(argv[1])) error(E_FLOATVECTOR,NULL);
  if (!isfltvector(argv[2])) error(E_FLOATVECTOR,NULL);
  if (!isfltvector(argv[3])) error(E_FLOATVECTOR,NULL);
  if (n>4 && (argv[4]!=NIL)) range_check=1; else range_check=0;
  a1x=argv[0]->c.fvec.fv[0]; a1y=argv[0]->c.fvec.fv[1];
  b1x=argv[2]->c.fvec.fv[0]; b1y=argv[2]->c.fvec.fv[1];
  ax=argv[1]->c.fvec.fv[0]-a1x; ay=argv[1]->c.fvec.fv[1]-a1y;
  bx=argv[3]->c.fvec.fv[0]-b1x; by=argv[3]->c.fvec.fv[1]-b1y;
  abx=b1x-a1x; aby=b1y-a1y;
  cz=ax*by-ay*bx;
  if (cz==0) return(NIL);	/* parallel  Nov.1991*/
  u=(abx*by-aby*bx)/cz;
  v=(abx*ay-aby*ax)/cz;
  if (range_check && 
	(u<0.0 || 1.0<u || v<0.0 || 1.0<v)) return(NIL);
  else {
    up=makeflt(u); vp=makeflt(v);
    /* printf("%f %f\n",u,v); */
    return(cons(ctx,up,cons(ctx,vp,NIL))); }  }

/* (defun det3 (a b c)
/*  %(a[0] * b[1] * c[2] - a[2] * b[1] * c[0] +
/*    a[1] * b[2] * c[0] - a[1] * b[0] * c[2] +
/*    a[2] * b[0] * c[1] - a[0] * b[2] * c[1]))
/*
/* (defun line-intersection3 (a1 a2 b1 b2 &optional tol)
/*   (let* ((p1 a1) (v1 (normalize-vector (v- a2 a1)))
/*	  (p2 b1) (v2 (normalize-vector (v- b2 b1))) 
/*	  (p2-p1 (v- p2 p1))
/*	  (cross (v* v1 v2))
/*	  (cross2 (v. cross cross))
/*	  t1 t2)
/*      (cond ((< cross2 0.001)  nil)
/*	    (t (list (/ (det3 p2-p1 v2 cross) cross2)
/*		     (/ (det3 p2-p1 v1 cross) cross2))))) )
*/



static eusfloat_t determinant3(a,b,c)
eusfloat_t *a, *b, *c;
{ return(a[0] * b[1] * c[2] - a[2] * b[1] * c[0] +
	 a[1] * b[2] * c[0] - a[1] * b[0] * c[2] +
	 a[2] * b[0] * c[1] - a[0] * b[2] * c[1]);}

static eusfloat_t *crossproduct(a,b,r)
register eusfloat_t *a, *b, *r;
{ r[0]=a[1] * b[2] - a[2] * b[1];
  r[1]=a[2] * b[0] - a[0] * b[2];
  r[2]=a[0] * b[1] - a[1] * b[0];
  return(r);}


pointer LINEINTERSECTION3(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register eusfloat_t *fv;
  eusfloat_t tolerance;
  eusfloat_t cz,u,v;
  eusfloat_t *p1, v1[3], *p2, v2[3], p2p1[3];
  eusfloat_t cross[3], cross2;
  numunion nu;

  ckarg2(4,5);
  if (!isfltvector(argv[0])) error(E_FLOATVECTOR,NULL);
  if (!isfltvector(argv[1])) error(E_FLOATVECTOR,NULL);
  if (!isfltvector(argv[2])) error(E_FLOATVECTOR,NULL);
  if (!isfltvector(argv[3])) error(E_FLOATVECTOR,NULL);
  if (n==5) tolerance=ckfltval(argv[4]); else tolerance=0.0;
  
  p1=argv[0]->c.fvec.fv;
  fv=argv[1]->c.fvec.fv;
	v1[0]=fv[0]-p1[0]; v1[1]=fv[1]-p1[1]; v1[2]=fv[2]-p1[2];

  p2=argv[2]->c.fvec.fv;
  fv=argv[3]->c.fvec.fv;
	v2[0]=fv[0]-p2[0]; v2[1]=fv[1]-p2[1]; v2[2]=fv[2]-p2[2];

  p2p1[0]=p2[0]-p1[0];  p2p1[1]=p2[1]-p1[1];  p2p1[2]=p2[2]-p1[2];
  crossproduct(v1,v2,cross);
  cross2=cross[0]*cross[0] + cross[1]*cross[1] + cross[2]*cross[2];
  if (cross2<tolerance) return(NIL);

  u=determinant3(p2p1,v2,cross)/cross2;
  v=determinant3(p2p1,v1,cross)/cross2;
  return(cons(ctx,makeflt(u),cons(ctx,makeflt(v),NIL))); }


/*
/*	viewport clipping functions
/*	VPCLIP is for normal coordinate system
/*	HOMO_VPCLIP is for homogeneous coordinate system
/*
/*	rewritten in 1987-Jun
/*	Copyright(1986) Toshihiro MATSUI
*/

extern pointer makefvector();

#define clipcode(x,y,z)  (((x)<-(z))?1:(((x)>(z))?2:0))\
                         + (((y)<-(z))?4:(((y)>(z))?8:0))
pointer VPCLIP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  pointer v1, v2;
  pointer work;
  eusfloat_t x1,y1,z1, x2,y2,z2, x,y,z, temp;
  int c1, c2, c;
  numunion nu;

  ckarg(2);
  v1=argv[0]; v2=argv[1];
  if (!isfltvector(v1) || !isfltvector(v2)) error(E_FLOATVECTOR,NULL);
  x1=v1->c.fvec.fv[0]; y1=v1->c.fvec.fv[1]; z1=v1->c.fvec.fv[2];
  x2=v2->c.fvec.fv[0]; y2=v2->c.fvec.fv[1]; z2=v2->c.fvec.fv[2];
  c1 = clipcode(x1,y1,z1); c2 = clipcode(x2,y2,z2);
  while (c1 || c2 ) {
    if (c1 & c2) return(NIL);
    c = c1?c1:c2;
    if (c & 1) {
      temp = (z1+x1)/((x1-x2)-(z2-z1));
      z = temp*(z2-z1)+z1; x = -z; y = temp*(y2-y1) + y1;}
    else if (c & 2) {
      temp = (z1 - x1) / ((x2-x1) - (z2-z1));
      z = temp*(z2-z1) + z1; x = z; y = temp*(y2-y1) + y1;}
    else if (c & 4) {
      temp = (z1+y1) / ((y1-y2) - (z2-z1));
      z = temp*(z2-z1) + z1; x = temp*(x2-x1) + x1; y = -z;}
    else if (c & 8) {
      temp = (z1-y1) / ((y2 - y1) - (z2-z1));
      z = temp*(z2-z1) + z1; x = temp*(x2-x1) + x1; y = z;}
    if (c == c1) {
      x1 = x; y1 = y; z1 = z; c1 = clipcode(x,y,z);}
    else {
      x2 = x; y2 = y; z2 = z; c2 = clipcode(x,y,z);}
    }
  v1 = makefvector(3);
  v1->c.fvec.fv[0]=x1; v1->c.fvec.fv[1]=y1; v1->c.fvec.fv[2]=z1;
  vpush(v1);
  v2 = makefvector(3);
  v2->c.fvec.fv[0]=x2; v2->c.fvec.fv[1]=y2; v2->c.fvec.fv[2]=z2;
  work = cons(ctx,v2, NIL);
  work = cons(ctx,vpop(), work);
  return(work);
}

static int windowcoords(x,y,z,w,wc)
eusfloat_t x,y,z,w,wc[];
{ register int i,c,code;
  wc[0]=w+x; wc[1]=w-x; wc[2]=w+y; wc[3]=w-y; wc[4]=z; wc[5]=w-z;
  code=0; c=1; i=0;
  while (i<6) {
    if (wc[i++]<0) code += c;
    c <<= 1;}
  return(code);}

pointer HOMO_VPCLIP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer v1,v2,work;
  eusfloat_t v[4];
  eusfloat_t x1,y1,z1,w1, x2,y2,z2,w2, dx,dy,dz,dw, t1,t2,tt;
  register int i,c1,c2;
  eusfloat_t wc1[6],wc2[6];

  ckarg(2);
  v1=argv[0]; v2=argv[1];
  if (!isfltvector(v1) || !isfltvector(v2)) error(E_FLOATVECTOR,NULL);
  x1=v1->c.fvec.fv[0]; y1=v1->c.fvec.fv[1]; z1=v1->c.fvec.fv[2];
  if (vecsize(v1)>=4) w1=v1->c.fvec.fv[3]; else w1=1.0;
  x2=v2->c.fvec.fv[0]; y2=v2->c.fvec.fv[1]; z2=v2->c.fvec.fv[2];
  if (vecsize(v2)>=4) w2=v2->c.fvec.fv[3]; else w2=1.0;

  c1 = windowcoords(x1,y1,z1,w1,wc1); c2 = windowcoords(x2,y2,z2,w2,wc2);
  if ((c1 & c2)>0) return(NIL);
  t1=0.0; t2=1.0;
  for (i=0; i<6; i++)
    if ((wc1[i]<0) || (wc2[i]<0)) {
      tt = wc1[i] / (wc1[i]-wc2[i]);
      if (wc1[i]<0) {if (tt>t1) t1=tt;}
      else {if (tt<t2) t2=tt;}}
  if (t2 >= t1) {
    dx = x2-x1; dy = y2-y1; dz = z2-z1; dw = w2-w1;
    if (t2 != 1.0) {
      x2 = x1+t2*dx; y2 = y1+t2*dy; z2 = z1+t2*dz; w2 = w1+t2*dw;}
    if (t1 != 0.0) {
      x1 = x1+t1*dx; y1 = y1+t1*dy; z1 = z1+t1*dz; w1 = w1+t1*dw;}

    v1 = makefvector(4);
    v1->c.fvec.fv[0]=x1; v1->c.fvec.fv[1]=y1; v1->c.fvec.fv[2]=z1;
					      v1->c.fvec.fv[3]=w1;
    vpush(v1);
    v2 = makefvector(4);
    v2->c.fvec.fv[0]=x2; v2->c.fvec.fv[1]=y2; v2->c.fvec.fv[2]=z2;
					      v2->c.fvec.fv[3]=w2;
    work = cons(ctx,v2, NIL);
    work = cons(ctx,vpop(), work);
    return(work);    }
  else return(NIL);}

pointer HOMO2NORMAL(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ register pointer a=argv[0],r;
  register int size;
  eusfloat_t w;
  ckarg2(1,2);
  if (!isfltvector(a)) error(E_FLOATVECTOR,NULL);
  size=vecsize(a);
  if (n==2) r=argv[1];
  else r=makefvector(size-1);
  w=a->c.fvec.fv[size-1];
  for (n=0; n<size-1; n++) r->c.fvec.fv[n]=a->c.fvec.fv[n]/w;
  if (vecsize(r)>n)  r->c.fvec.fv[size-1]=1.0;
  r->c.fvec.length=makeint(size-1);
  return(r);}

pointer HOMOGENIZE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0],r;
  register int i,size;
  eusfloat_t w;
  numunion nu;

  ckarg2(1,2);
  if (!isfltvector(a)) error(E_FLOATVECTOR,NULL);
  if (n==2) {
    r=argv[1];
    if  (!isfltvector(r)) error(E_FLOATVECTOR,NULL);
    size=vecsize(a);
    if (size != vecsize(r)-1) error(E_ARRAYDIMENSION,NULL);}
  else {
    size=vecsize(a);
    r=makefvector(size+1);}
  for (i=0; i<size; i++) r->c.fvec.fv[i]=a->c.fvec.fv[i];
  r->c.fvec.fv[size]=1.0;
  return(r);}
    
pointer intersection(ctx, n, argv)
register context *ctx;
int n;
pointer argv[];
{
  pointer mod, x;

  mod=argv[0];

/*
  printf("intersection is being initialized %x\n", intersection);
  printf("ctx=%x mod=%x n=%d\n", ctx, mod, n);
  printf("LINEINTERSECTION=%x\n", LINEINTERSECTION);
  printf("defun=%x\n", defun);
  printf("compfun=%x\n", compfun);
*/

  x=defun(ctx,"LINE-INTERSECTION",mod,LINEINTERSECTION,NULL);
  defun(ctx,"LINE-INTERSECTION3",mod,LINEINTERSECTION3,NULL);
  /* clippers*/
  defun(ctx,"VIEWPORTCLIP",mod,VPCLIP,NULL);
  defun(ctx,"HOMO-VIEWPORT-CLIP",mod,HOMO_VPCLIP,NULL);
  defun(ctx,"HOMO2NORMAL",mod,HOMO2NORMAL,NULL);
  defun(ctx,"HOMOGENIZE",mod,HOMOGENIZE,NULL);
  return(T); }

