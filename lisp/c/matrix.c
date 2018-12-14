/***************************************************/
/* float vector and matrix operations
/*	Copyright(c) Toshihiro Matsui
/*      Electrotechnical Laboratory
/*
/*	1986-Nov
/*	1987-Feb	complete floatvector
/*	1987-Mar	modify rotation 
/*	1987-Nov	simultaneous equations
/*	1988-Jan	matrix is represented by 2D array,
/*			not by an vector of vectors
/**************************************************************/
static char *rcsid="@(#)$Id$";

#include "math.h"
#include "eus.h"

extern double sin(), cos(), sqrt(), atan2();
extern pointer makefvector(),defkeyword();
extern pointer makematrix();

static pointer K_X,K_Y,K_Z,MK_X,MK_Y,MK_Z;

/* #define PI 3.1415926536 */

#define ckvsize(a,b) ((a->c.vec.size==b->c.vec.size)?vecsize(a):(int)(eusinteger_t)error(E_VECINDEX))

pointer VPLUS(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register int i,s;
  register pointer result;
  register int isf,isi,iss;

  ckarg2(2,3);
  if (!((isf=isfltvector(argv[0])) && isfltvector(argv[1])) &&
      !((isi=isintvector(argv[0])) && isintvector(argv[1])) &&
      !((iss=isstring(argv[0]))    && isstring(argv[1])))
    error(E_TYPEMISMATCH);
  s=ckvsize(argv[0],argv[1]);
  if (n==3) {
    result=argv[2];
    if (s!=vecsize(result)) error(E_FLOATVECTOR);}
  else result=makevector(classof(argv[0]), s);
  if (isf) {
    register eusfloat_t *a,*b,*r;
    if (!isfltvector(result))  error(E_FLOATVECTOR);
    a=argv[0]->c.fvec.fv; b=argv[1]->c.fvec.fv;
    r=result->c.fvec.fv;
    for(i=0; i<s; i++) r[i]= a[i] + b[i];
    return(result);}
  else if (isi) {
    register eusinteger_t *ia, *ib, *ir;
    if (!isintvector(result))  error(E_NOINTVECTOR);
    ia=argv[0]->c.ivec.iv; ib=argv[1]->c.ivec.iv;
    ir=result->c.ivec.iv;
    for(i=0; i<s; i++) ir[i]= ia[i] + ib[i];
    return(result);}
  else if (iss) {
    register unsigned char *ba, *bb, *br;
    ba=argv[0]->c.str.chars;
    bb=argv[1]->c.str.chars;
    br=result->c.str.chars;
    for(i=0; i<s; i++) br[i]=ba[i] + bb[i];
    return(result);}
  else error(E_NOSEQ);
  }

pointer VPLUSPLUS(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register int i,s;
  register pointer p,result;
  eusfloat_t *a,*r;

  if (n==1) return(argv[0]);
  if (!isfltvector(argv[0])) error(E_FLOATVECTOR);
  s=vecsize(argv[0]);
  result=makefvector(s);
  r=result->c.fvec.fv;   a=argv[0]->c.fvec.fv;
  for (i=0; i<s; i++) r[i]=a[i];
  while (--n>0) {
    p=argv[n];
    if (!isfltvector(p)) error(E_FLOATVECTOR);
    if (vecsize(p) != s) error(E_VECINDEX);
    a=p->c.fvec.fv;
    for (i=0; i<s; i++) r[i]+=a[i];}
  return(result);}

pointer VMINUS(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register int i,s;
  register eusinteger_t *ia, *ib, *ir;
  register pointer result;
  register eusfloat_t *a,*b,*r;
  register int isi,isf,iss;

  ckarg2(1,3);  
  isi=isintvector(argv[0]);
  isf=isfltvector(argv[0]);
  iss=isstring   (argv[0]);
  if (!isi && !isf && !iss)
    error(E_NOVECTOR);
  s=vecsize(argv[0]);
  if (n==1) {	/*negate float vector*/
    result=makevector(classof(argv[0]),s);
    if (isi) {
      ia=argv[0]->c.ivec.iv;
      for (i=0; i<s; i++) result->c.ivec.iv[i]= -ia[i];
      return(result);}
    else if (isf) {
      a=argv[0]->c.fvec.fv;
      for (i=0; i<s; i++) result->c.fvec.fv[i]= -a[i];
      return(result);}
    else error(E_NOVECTOR);}

  /* argc>=2 */
  if (!(isintvector(argv[1])&&isi) &&
      !(isfltvector(argv[1])&&isf) &&
      !(isstring(argv[1])   &&iss))
    error(E_TYPEMISMATCH);
  s=ckvsize(argv[0],argv[1]);
  if (n==3) {
    result=argv[2];
    if (!(isf&&isfltvector(result)) && !(isi&&isintvector(result)) &&
	!(iss&&isstring(result)) )
	 error(E_TYPEMISMATCH);
    if (vecsize(result)!=s) error(E_VECINDEX);}
  else  result=makevector(classof(argv[0]),s);

  if (isf) {
    a=argv[0]->c.fvec.fv;
    b=argv[1]->c.fvec.fv;
    r=result->c.fvec.fv;
    for(i=0; i<s; i++) r[i]=a[i]-b[i];
    return(result);}
  else if (isi) {
    ia=argv[0]->c.ivec.iv;
    ib=argv[1]->c.ivec.iv;
    ir=result->c.ivec.iv;
    for(i=0; i<s; i++) ir[i]=ia[i]-ib[i];
    return(result);}
  else if (iss) {
    register unsigned char *ba, *bb, *br;
    ba=argv[0]->c.str.chars;
    bb=argv[1]->c.str.chars;
    br=result->c.str.chars;
    for(i=0; i<s; i++) br[i]=ba[i]-bb[i];
    return(result);}
  else error(E_NOSEQ);}

pointer VMINUS_ABS(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register int i,s;
  register eusinteger_t *ia, *ib, *ir;
  register pointer result;
  register eusfloat_t *a,*b,*r;
  register eusfloat_t x;
  register int isi,isf,iss;

  register int ix;

  ckarg2(2,3);  
  if (!(isi=isintvector(argv[0])) && !(isf=isfltvector(argv[0])) &&
      !(iss=isstring   (argv[0])))
    error(E_NOVECTOR);
  s=vecsize(argv[0]);

  /* argc>=2 */
  if (!(isintvector(argv[1])&&isi) &&
      !(isfltvector(argv[1])&&isf) &&
      !(isstring(argv[1])   &&iss))
    error(E_TYPEMISMATCH);
  s=ckvsize(argv[0],argv[1]);
  if (n==3) {
    result=argv[2];
    if (!(isf&&isfltvector(result)) && !(isi&&isintvector(result)) &&
	!(iss&&isstring(result)) )
	 error(E_TYPEMISMATCH);
    if (vecsize(result)!=s) error(E_VECINDEX);}
  else  result=makevector(classof(argv[0]),s);

  if (isf) {
    a=argv[0]->c.fvec.fv;
    b=argv[1]->c.fvec.fv;
    r=result->c.fvec.fv;
    for(i=0; i<s; i++) {
       x=a[i]-b[i];
       if (x<0) x= -x;
       r[i]=x;}
    return(result);}
  else if (isi) {
    ia=argv[0]->c.ivec.iv;
    ib=argv[1]->c.ivec.iv;
    ir=result->c.ivec.iv;
    for(i=0; i<s; i++) {
      ix=ia[i]-ib[i];
      if (ix<0) ix= -ix;
      ir[i]=ix;}
    return(result);}
  else if (iss) {
    register unsigned char *ba, *bb, *br;
    ba=argv[0]->c.str.chars;
    bb=argv[1]->c.str.chars;
    br=result->c.str.chars;
    for(i=0; i<s; i++) {
      ix=ba[i]-bb[i];
      if (ix<0) ix= -ix;
      br[i]=ix;}
    return(result);}
  else error(E_NOSEQ);}

pointer VINNERPRODUCT(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register eusfloat_t *a,*b;
  register long i,s;
  register eusinteger_t *ia, *ib; register long isum=0;
  eusfloat_t sum=0.0;
  register int isf,isi;
  numunion nu;
  ckarg(2);
  if (!((isf=isfltvector(argv[0])) && isfltvector(argv[1])) &&
      !((isi=isintvector(argv[0])) && isintvector(argv[1])))
    error(E_TYPEMISMATCH);
  s=ckvsize(argv[0],argv[1]);
  if (isf) {
    a= (argv[0]->c.fvec.fv); b= (argv[1]->c.fvec.fv);
    for (i=0; i<s; i++) sum+= a[i] * b[i];
    return(makeflt(sum));}
  if (isi) {
    ia= (argv[0]->c.ivec.iv); ib= (argv[1]->c.ivec.iv);
    for (i=0; i<s; i++) isum+= ia[i] * ib[i];
    return(makeint(isum));}
  else error(E_NOSEQ);}

pointer VNORM(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register int i,s;
  register eusfloat_t *a,sum=0.0;
  numunion nu;
  ckarg(1);
  if (!isvector(argv[0])) error(E_NOVECTOR);
  s=vecsize(argv[0]);
  if (elmtypeof(argv[0])==ELM_FLOAT) {
    a=argv[0]->c.fvec.fv;
    for (i=0; i<s; i++) sum+=a[i]*a[i];
    sum=sqrt(sum);
    return(makeflt(sum));}
  else if (elmtypeof(argv[0])==ELM_INT) {
    eusinteger_t *ia;
    ia=argv[0]->c.ivec.iv;
    for (i=0; i<s; i++) sum+=ia[i]*ia[i];
    sum=sqrt(sum);
    return(makeflt(sum));}
  else error(E_FLOATVECTOR);
  }

pointer VNORM2(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register int i,s;
  register eusfloat_t *a,sum=0.0;
  numunion nu;
  ckarg(1);
  if (!isvector(argv[0])) error(E_NOVECTOR);
  s=vecsize(argv[0]);
  if (elmtypeof(argv[0])==ELM_FLOAT) {
    a=argv[0]->c.fvec.fv;
    for (i=0; i<s; i++) sum+=a[i]*a[i];
    /* sum=sqrt(sum); no square root */
    return(makeflt(sum));}
  else if (elmtypeof(argv[0])==ELM_INT) {
    eusinteger_t *ia;
    ia=argv[0]->c.ivec.iv;
    for (i=0; i<s; i++) sum+=ia[i]*ia[i];
    return(makeflt(sum));}
  else error(E_FLOATVECTOR);}

pointer VNORMALIZE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer result;
  register eusfloat_t *a,*r,sum=0.0;
  register int i,s;

  ckarg2(1,2);
  if (!isfltvector(argv[0])) error(E_FLOATVECTOR);
  s=vecsize(argv[0]);
  if (n==2) { 
    result=argv[1];
    if (!isfltvector(result)) error(E_FLOATVECTOR);
    if (s!=vecsize(result)) error(E_VECINDEX);}
  else result=makefvector(s);
  a=argv[0]->c.fvec.fv;
  r=result->c.fvec.fv;
  for (i=0; i<s; i++) sum+= a[i]*a[i];
  sum=sqrt(sum);
  for (i=0; i<s; i++) r[i]=a[i]/sum;
  return(result);}
  
pointer VDISTANCE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  register eusfloat_t *a, *b;
  register int s;
  eusfloat_t d,dist=0.0;
  register int isf,isi;
  numunion nu;
  ckarg(2);
  if (!((isf=isfltvector(argv[0])) && isfltvector(argv[1])) &&
      !((isi=isintvector(argv[0])) && isintvector(argv[1])))
    error(E_TYPEMISMATCH);
  s=ckvsize(argv[0],argv[1]);
  if (isf) {
    a=argv[0]->c.fvec.fv; b=argv[1]->c.fvec.fv;
    while (--s>=0) { d=a[s]-b[s]; dist+= d*d;}
    return(makeflt(sqrt(dist)));}
  else if (isi) {
    register eusinteger_t *ia, *ib;
    register long id, idist=0;
    ia=argv[0]->c.ivec.iv; ib=argv[1]->c.ivec.iv;
    while (--s>=0) { id= ia[s]-ib[s]; idist+= id * id;}
    dist=idist;
    return(makeflt(sqrt(dist)));}
  else error(E_FLOATVECTOR);}

pointer VDISTANCE2(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  register eusfloat_t *a, *b;
  register int s;
  eusfloat_t d,dist=0.0;
  register int isf,isi;
  numunion nu;
  ckarg(2);
  if (!((isf=isfltvector(argv[0])) && isfltvector(argv[1])) &&
      !((isi=isintvector(argv[0])) && isintvector(argv[1])))
    error(E_TYPEMISMATCH);
  s=ckvsize(argv[0],argv[1]);
  if (isf) {
    a=argv[0]->c.fvec.fv; b=argv[1]->c.fvec.fv;
    while (--s>=0) { d=a[s]-b[s]; dist+= d*d;}
    return(makeflt(dist));}
  else if (isi) {
    register eusinteger_t *ia, *ib;
    register long id, idist=0;
    ia=argv[0]->c.ivec.iv; ib=argv[1]->c.ivec.iv;
    while (--s>=0) { id= ia[s]-ib[s]; idist+= id * id;}
    dist=idist;
    return(makeflt(dist));}
  else error(E_FLOATVECTOR);}

pointer VDIRECTION(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  register eusfloat_t *a, *b, *r;
  register int i,s;
  pointer result;
  eusfloat_t norm=0.0;
  ckarg2(2,3);
  if (!isfltvector(argv[0]) || !isfltvector(argv[1])) error(E_FLOATVECTOR);
  s=ckvsize(argv[0],argv[1]);
  if (n==3) {
    result=argv[2]; 
    if (!isfltvector(result)) error(E_FLOATVECTOR);
    if (vecsize(result)!=s) error(E_VECINDEX);
    }
  else result=makefvector(s);
  r=result->c.fvec.fv;  a=argv[0]->c.fvec.fv; b=argv[1]->c.fvec.fv;
  for (i=0; i<s; i++) { r[i]=b[i]-a[i]; norm+= r[i]*r[i];}
  norm=sqrt(norm);
  for (i=0; i<s; i++)  { r[i]=r[i]/norm;}
  return(result);}

pointer VCROSSPRODUCT(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{
  register eusfloat_t *fv1,*fv2,*rfv;
  register pointer result;
  register int s;

  ckarg2(2,3);
  if (!isfltvector(argv[0]) || !isfltvector(argv[1])) error(E_FLOATVECTOR);
  s=ckvsize(argv[0],argv[1]);
  if (s!=3) error(E_VECINDEX);
  if (n==3) {
    result=argv[2]; 
    if (!isfltvector(result)) error(E_FLOATVECTOR);
    if (vecsize(result)!=3) error(E_VECINDEX);
    }
  else result=makefvector(3);
  rfv=result->c.fvec.fv;
  fv1= argv[0]->c.fvec.fv; fv2= argv[1]->c.fvec.fv;
  rfv[0]=fv1[1] * fv2[2] - fv1[2] * fv2[1];
  rfv[1]=fv1[2] * fv2[0] - fv1[0] * fv2[2];
  rfv[2]=fv1[0] * fv2[1] - fv1[1] * fv2[0];
  return(result);}

pointer SCA3PROD(ctx,n,argv)	/*scalar tripple product [A,B,C] */
register context *ctx;
int n;
pointer argv[];
{
  register eusfloat_t *va,*vb,*vc;
  eusfloat_t val;
  numunion nu;
  ckarg(3);
  if (!isfltvector(argv[0]) || !isfltvector(argv[1]) || !isfltvector(argv[2]))
    	 error(E_FLOATVECTOR);
  if (vecsize(argv[0])!=3 || vecsize(argv[1])!=3 || vecsize(argv[2])!=3) error(E_VECINDEX);
  va=argv[0]->c.fvec.fv; vb=argv[1]->c.fvec.fv; vc=argv[2]->c.fvec.fv;
  val =va[0] * vb[1] * vc[2];
  val+=va[2] * vb[0] * vc[1];
  val+=va[1] * vb[2] * vc[0];
  val-=va[2] * vb[1] * vc[0];
  val-=va[0] * vb[2] * vc[1];
  val-=va[1] * vb[0] * vc[2];
  return(makeflt(val));}
  
pointer SCALEVEC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  eusfloat_t scale;
  pointer result;
  register eusfloat_t *a,*r;
  register int s,i;
  register int isf,isi;
  numunion nu;

  ckarg2(2,3);
  scale=ckfltval(argv[0]);
  if (!(isf=isfltvector(argv[1])) && !(isi=isintvector(argv[1])))
    error(E_FLOATVECTOR);
  s=vecsize(argv[1]);
  if (n==3) {
    result=argv[2];
    if (!isvector(result)) error(E_NOVECTOR);
    if (elmtypeof(result)!=elmtypeof(argv[1])) error(E_TYPEMISMATCH);
    if (s!=vecsize(result)) error(E_VECINDEX);}
  else result=makevector(classof(argv[1]), s);
  if (isf) {
    a=argv[1]->c.fvec.fv;
    r=result->c.fvec.fv;
    for (i=0; i<s; i++) r[i]=scale*(a[i]);
    return(result);}
  else if (isi) {
    register eusinteger_t *ia, *ir;
    ia=argv[1]->c.ivec.iv;
    ir=result->c.ivec.iv;
    for (i=0; i<s; i++) ir[i]=scale*(ia[i]);
    return(result);}
  else error(E_NOSEQ);}

pointer MIDPOINT(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int i,vsize;
  double ratio, ratio2;
  pointer p1,p2,result;
  register int isf,isi;
  numunion nu;

  ckarg2(3,4);
  ratio=ckfltval(argv[0]); ratio2=1.0-ratio;
  p1=argv[1]; p2=argv[2];
  if (!((isf=isfltvector(p1))&&isfltvector(p2)) &&
      !((isi=isintvector(p1))&&isintvector(p2)))
    error(E_TYPEMISMATCH);
  vsize=ckvsize(p1,p2);  
  if (n==4) {
    result=argv[3];
    if (!(isf&&isfltvector(result))&&!(isi&&isintvector(result)))
      error(E_TYPEMISMATCH);
    if (vsize!=vecsize(result)) error(E_VECINDEX);}
  else result=makevector(classof(p1), vsize);
  if (isf) {
    register eusfloat_t *r,*pp1,*pp2;
    r=result->c.fvec.fv; pp1=p1->c.fvec.fv; pp2=p2->c.fvec.fv;
    for (i=0; i<vsize; i++) 
      r[i]=pp1[i]*ratio2 + pp2[i]*ratio;
    return(result);}
  else if (isi) {
    register eusinteger_t *r,*pp1,*pp2;
    r=result->c.ivec.iv; pp1=p1->c.ivec.iv; pp2=p2->c.ivec.iv;
    for (i=0; i<vsize; i++) 
      r[i]=pp1[i]*ratio2 + pp2[i]*ratio;
    return(result);}
  else error(E_FLOATVECTOR);}

/*
pointer TRIANGLE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register float *v1,*v2,*v3,tr;
  ckarg(3);
  if (!isfltvector(argv[0])) error(E_FLOATVECTOR);
  if (!isfltvector(argv[1])) error(E_FLOATVECTOR);
  if (!isfltvector(argv[2])) error(E_FLOATVECTOR);
  v1=argv[0]->c.fvec.fv;
  v2=argv[1]->c.fvec.fv;
  v3=argv[2]->c.fvec.fv;
  tr=v1[0]*v2[1] + v2[0]*v3[1] + v3[0]*v1[1] 
     - v3[0]*v2[1] - v2[0]*v1[1] - v1[0]*v3[1];
  return(makeflt(tr));}
*/

pointer MKFLTVEC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer r;
  register int i;
  register eusfloat_t *fv;
  numunion nu;
  r=makefvector(n);
  fv=r->c.fvec.fv;
  for (i=0; i<n; i++) {
    //fv[i]=ckfltval(argv[i]);
    if ( isflt(argv[i]) ) fv[i] = fltval(argv[i]);
    else if ( isint(argv[i]) ) fv[i] = intval(argv[i]);
    else if ( pisbignum(argv[i]) ) fv[i] = big_to_float(argv[i]);
    else if ( pisratio(argv[i]) ) fv[i] = ratio2flt(argv[i]);
    else if ( issymbol(argv[i]) ) {
        char *sym = get_string(argv[i]);
        if ( strcmp(sym, "NAN") == 0 ) fv[i] = NAN;
        else if ( strcmp(sym, "-NAN") == 0 ) fv[i] = -NAN;
        else if ( strcmp(sym,  "INF") == 0 ) fv[i] = INFINITY;
        else if ( strcmp(sym, "-INF") == 0 ) fv[i] = -INFINITY;
        else { (eusinteger_t)error(E_NONUMBER); }
    }
    else { (eusinteger_t)error(E_NONUMBER); }
  }

  return(r);
  }

/* comparation of vectors */

pointer VLESSP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int i,s;
  register pointer a,b;
  register int isf,isi;
  ckarg(2);
  a=argv[0]; b=argv[1];
  if (!((isf=isfltvector(a))&&isfltvector(b)) &&
      !((isi=isintvector(a))&&isintvector(b))) error(E_FLOATVECTOR);
  s=ckvsize(a,b);
  if (isf) {
    register eusfloat_t *av=a->c.fvec.fv, *bv=b->c.fvec.fv;
    for (i=0; i<s; i++) if (av[i] > bv[i]) return(NIL);
    return(T);}
  else if (isi) {
    register eusinteger_t *av=a->c.ivec.iv, *bv=b->c.ivec.iv;
    for (i=0; i<s; i++) if (av[i] > bv[i]) return(NIL);
    return(T);}
  else  error(E_FLOATVECTOR);}

pointer VGREATERP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
/*every element of argv[0] is greater than corresponding elem of arg[1]*/
{ register int i,s;
  register pointer a,b;
  register int isf,isi;
  ckarg(2);	
  a=argv[0]; b=argv[1];
  if (!((isf=isfltvector(a))&&isfltvector(b)) &&
      !((isi=isintvector(a))&&isintvector(b))) error(E_FLOATVECTOR);
  s=ckvsize(a,b);
  if (isf) {
    register eusfloat_t *av=a->c.fvec.fv, *bv=b->c.fvec.fv;
    for (i=0; i<s; i++) if (av[i] < bv[i]) return(NIL);
    return(T);}
  else if (isi) {
    register eusinteger_t *av=a->c.ivec.iv, *bv=b->c.ivec.iv;
    for (i=0; i<s; i++) if (av[i] < bv[i]) return(NIL);
    return(T);}
  else  error(E_FLOATVECTOR);}

pointer MINIMALBOX(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  eusfloat_t dx,dy,dz,err=0.0,diameter;
  register int i;
  register pointer a;
  pointer v;
  register eusfloat_t *f;
  register pointer vmin,vmax;
  numunion nu;

  ckarg2(3,4);
  a=argv[0];
  if (!islist(a)) error(E_NOLIST);
  v=ccar(a); a=ccdr(a);
  vmin=argv[1];
  if (!isfltvector(vmin)) error(E_FLOATVECTOR); 
  vmax=argv[2];
  if (!isfltvector(vmax)) error(E_FLOATVECTOR); 
  if (n==4) err=ckfltval(argv[3]);
  for (i=0; i<3; i++) vmin->c.fvec.fv[i]=vmax->c.fvec.fv[i]=v->c.fvec.fv[i];
  while (islist(a)) {
    v=ccar(a); a=ccdr(a);
    if (!isfltvector(v)) error(E_FLOATVECTOR);
    f=v->c.fvec.fv;
    if (f[0]<vmin->c.fvec.fv[0]) vmin->c.fvec.fv[0]=f[0];
    else if (f[0]>vmax->c.fvec.fv[0]) vmax->c.fvec.fv[0]=f[0];
    if (f[1]<vmin->c.fvec.fv[1]) vmin->c.fvec.fv[1]=f[1];
    else if (f[1]>vmax->c.fvec.fv[1]) vmax->c.fvec.fv[1]=f[1];
    if (f[2]<vmin->c.fvec.fv[2]) vmin->c.fvec.fv[2]=f[2];
    else if (f[2]>vmax->c.fvec.fv[2]) vmax->c.fvec.fv[2]=f[2];}
  dx= vmax->c.fvec.fv[0] - vmin->c.fvec.fv[0];
  dy= vmax->c.fvec.fv[1] - vmin->c.fvec.fv[1];
  dz= vmax->c.fvec.fv[2] - vmin->c.fvec.fv[2];
  diameter=sqrt(dx*dx + dy*dy + dz*dz);
  if (err!=0.0) {
    vmin->c.fvec.fv[0]-= diameter*err;
    vmin->c.fvec.fv[1]-= diameter*err;
    vmin->c.fvec.fv[2]-= diameter*err;
    vmax->c.fvec.fv[0]+= diameter*err;
    vmax->c.fvec.fv[1]+= diameter*err;
    vmax->c.fvec.fv[2]+= diameter*err; }
  return(makeflt(diameter));}

pointer VMIN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int i,j,s;
  pointer r;
  register pointer v;
  register eusfloat_t *vf,*rf;
  register eusinteger_t *irf, *ivf;
  register int isf,isi;

  v=argv[0];
  if (!(isf=isfltvector(v)) && !(isi=isintvector(v))) error(E_FLOATVECTOR);
  s=vecsize(v);
  r=makevector(classof(v),s);
  rf=r->c.fvec.fv;
  for (i=0; i<s; i++) r->c.fvec.fv[i]=v->c.fvec.fv[i];
  if (isf) {
    for (i=1; i<n; i++) {
      v=argv[i];
      if (!isfltvector(v)) error(E_FLOATVECTOR);
      if (vecsize(v)!=s) error(E_VECINDEX);
      vf=v->c.fvec.fv;
      for (j=0; j<s; j++) if (vf[j]<rf[j]) rf[j]=vf[j]; } }
  else if (isi) {
    irf=r->c.ivec.iv;
    for (i=1; i<n; i++) {
      v=argv[i];
      if (!isintvector(v)) error(E_NOINTVECTOR);
      if (vecsize(v)!=s) error(E_VECINDEX);
      ivf=v->c.ivec.iv;
      for (j=0; j<s; j++) if (ivf[j]<irf[j]) irf[j]=ivf[j]; } }
  else error(E_NOSEQ);
  return(r);}

pointer VMAX(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int i,j,s;
  pointer r;
  register pointer v;
  register eusfloat_t *vf,*rf;
  register eusinteger_t *irf, *ivf;
  register int isf,isi;

  v=argv[0];
  if (!(isf=isfltvector(v)) && !(isi=isintvector(v))) error(E_FLOATVECTOR);
  s=vecsize(v);
  r=makevector(classof(v),s);
  rf=r->c.fvec.fv;
  for (i=0; i<s; i++) r->c.fvec.fv[i]=v->c.fvec.fv[i];
  if (isf) {
    for (i=1; i<n; i++) {
      v=argv[i];
      if (!isfltvector(v)) error(E_FLOATVECTOR);
      if (vecsize(v)!=s) error(E_VECINDEX);
      vf=v->c.fvec.fv;
      for (j=0; j<s; j++) if (vf[j]>rf[j]) rf[j]=vf[j]; } }
  else if (isi) {
    irf=r->c.ivec.iv;
    for (i=1; i<n; i++) {
      v=argv[i];
      if (!isintvector(v)) error(E_NOINTVECTOR);
      if (vecsize(v)!=s) error(E_VECINDEX);
      ivf=v->c.ivec.iv;
      for (j=0; j<s; j++) if (ivf[j]>irf[j]) irf[j]=ivf[j]; } }
  else error(E_NOSEQ);
  return(r);}


/****************************************************************/
/*	(m* m1 m2 [result])
/*	(transform mat vector [result])	; mat*vec
/*	(transform vector mat [result])	; vec*mat
/****************************************************************/

#define ismatrix(p) ((isarray(p) && \
		      p->c.ary.rank==makeint(2) && \
		      elmtypeof(p->c.ary.entity)==ELM_FLOAT))
#define rowsize(p) (intval(p->c.ary.dim[0]))
#define colsize(p) (intval(p->c.ary.dim[1]))

/*
float scaprod(v1,v2,s)
pointer v1,v2;
registerint s;
{ float sum=0;
  register int i;
  for (i=0; i<s; i++) sum+= v1->c.fvec.fv[i] * v2->c.fvec.fv[i];
  return(sum);}

float vtrans(mat,n,vec,s)
pointer mat,vec;
int n,s;
{ pointer m;
  register int i;
  float f=0.0;
  for (i=0; i<s; i++) 
    f+ = mat->c.vec.v[i]->c.fvec.fv[n] * vec->c.fvec.fv[i];
  return(f);}
*/

pointer MATTIMES(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer rm;
  register int k,i,j,ii,jj,row1,column1,row2,column2;
  register eusfloat_t *fm1,*fm2,*fm;
  eusfloat_t *fv,x,fvv[256];
  fv = fvv;

  ckarg2(2,3);
  if (!ismatrix(argv[0]) || !ismatrix(argv[1])) error(E_NOVECTOR);
  fm1=argv[0]->c.ary.entity->c.fvec.fv;
  fm2=argv[1]->c.ary.entity->c.fvec.fv;
  row1=rowsize(argv[0]);	row2=rowsize(argv[1]);
  column1=colsize(argv[0]); 	column2=colsize(argv[1]);
  if (column1!=row2) error(E_VECINDEX);
  if (n==3) {
    rm=argv[2];
    if (!ismatrix(rm)) error(E_NOVECTOR);
    if (row1!=rowsize(rm) || column2!=colsize(rm)) error(E_VECINDEX);
    }
  else rm=makematrix(ctx,row1,column2);
  if (row1>256 || column2>256){
    fv = (eusfloat_t *)malloc(sizeof(eusfloat_t) * ((row1>column2)?row1:column2));
    //error(E_VECINDEX);
  }
  fm=rm->c.ary.entity->c.fvec.fv;
  if (fm2!=fm) 
    for (i=0; i<row1; i++) {
      ii=i*column1;
      for (j=0; j<column2; j++) {
        x=0.0; jj=j;
        for (k=0; k<column1; k++) {
          x += fm1[ii+k] * fm2[jj];
          jj+=column2;}
        fv[j]=x;}
      ii=i*column2;
      for (j=0; j<column2; j++) fm[ii+j]=fv[j];}
  else 
    for (i=0; i<column2; i++) {
      for (j=0; j<row1; j++) {
        x=0.0; jj=j*column1; ii=0;
        for (k=0; k<column1; k++) {
          x += fm1[jj+k] * fm2[i+ii];
          ii+=column2;}
        fv[j]=x;}
      jj=0;
      for (j=0; j<row1; j++, jj+=column2) fm[i+jj]=fv[j];}
  if (fv!=fvv) free(fv);
  return(rm);}

pointer TRANSFORM(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer result;
  register eusfloat_t *m,*v,x;
  eusfloat_t *fv,fvv[256];
  register int i,j,ii,s,s2;
  fv = fvv;

  ckarg2(2,3);
  if (ismatrix(argv[0]) && isfltvector(argv[1])) {
    m=argv[0]->c.ary.entity->c.fvec.fv;
    v=argv[1]->c.fvec.fv;
    s=colsize(argv[0]); s2=rowsize(argv[0]);
    if (s!=vecsize(argv[1])) error(E_VECINDEX); }
  else if (isfltvector(argv[0]) && ismatrix(argv[1])) {
    v=argv[0]->c.fvec.fv;
    m=argv[1]->c.ary.entity->c.fvec.fv;
    s2=colsize(argv[1]); s=rowsize(argv[1]);
    if (s!=vecsize(argv[0])) error(E_VECINDEX); }
  else error(E_NOVECTOR);

  if (n==3) {
    result=argv[2];
    if (!isfltvector(result)) error(E_NOVECTOR);
    if (s2!=vecsize(result)) error(E_VECINDEX);}
  else result=makefvector(s2);
  if (s2>256){
    fv = (eusfloat_t *)malloc(sizeof(eusfloat_t) * s2);
    // error(E_VECINDEX);
  }

  if (isfltvector(argv[0])) {	/* vec*mat */
    for (i=0; i<s2; i++) {
      x=0.0; ii=i;
      for (j=0; j<s; j++) { x+= m[ii] * v[j]; ii+=s2;}
      fv[i]=x;}}
  else {	/* mat*vec */ 
    for (i=0; i<s2; i++) {
      x=0.0; ii=i*s;
      for (j=0; j<s; j++) x+=m[ii+j]*v[j];
      fv[i]=x;} }
  for (i=0; i<s2; i++) result->c.fvec.fv[i]=fv[i];
  if (s2>256) free(fv);
  return(result);
  }

/****************************************************************/
/*	rotate vector
/*	(rotate-vector fltvec theta :axis [result])
/*	theta : radian
/*	axis : one of :x,:y or :z or 0,1,2
/****************************************************************/

pointer ROTVEC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer vec,result,a;
  double theta,c,s1,s2;
  eusfloat_t f1,f2;
  register int k1,k2,k3,size;
  numunion nu;

  ckarg2(3,4);
  vec=argv[0];
  if (!isfltvector(vec)) error(E_FLOATVECTOR);
  size=vecsize(vec);
  theta=ckfltval(argv[1]);
  c=cos(theta); s1=sin(theta);
  a=argv[2];
  if (a==K_X || a==makeint(0)) {  k1=1; k2=2; k3=0; s2=s1; s1= -s1;}
  else if (a==K_Y || a==makeint(1)) { k1=0; k2=2; k3=1; s2= -s1;}
  else if (a==K_Z || a==makeint(2)) { k1=0; k2=1; k3=2; s2=s1; s1= -s1;}
  else if (a==NIL) { k1=0; k2=1; s2=s1; s1= -s1;}
  else error(E_ROTAXIS);
  if (n==4) {
    result=argv[3];
    if (!isfltvector(result)) error(E_FLOATVECTOR); }
  else result=makefvector(size);
  f1=vec->c.fvec.fv[k1];
  f2=vec->c.fvec.fv[k2];
  result->c.fvec.fv[k1]=c*f1+s1*f2;
  result->c.fvec.fv[k2]=s2*f1+c*f2;
  if (a!=NIL) result->c.fvec.fv[k3]=vec->c.fvec.fv[k3];
  return(result);}

/****************************************************************/
/*	rotate matrix
/*	(rotate-matrix mat theta :axis [worldp] [result])
/*		theta : radian
/*		axis : one of :x,:y or :z or 0,1,2
/*		worldp: nil--local(mult rot mat from the right)
/*			t----world(mult rot mat from the left)
/****************************************************************/
static void copymat(dest,src,size)
pointer dest,src;
register int size;
{ register int i;
  register eusfloat_t *rv=dest->c.ary.entity->c.fvec.fv;
  register eusfloat_t *mv=src->c.ary.entity->c.fvec.fv;
  size=size*size;
  for (i=0; i<size; i++) rv[i]=mv[i]; }

pointer ROTMAT(ctx,n,argv)
register context *ctx;
int n;			/* rot theata axis worldp result */
pointer argv[];
{ register pointer mat,result,a;
  double theta,c,s1,s2;
  eusfloat_t *m1,*m2,f1,f2;
  register eusfloat_t *rm,*m;
  register int i,size,k1,k2,worldp=0,ss;
  numunion nu;

  ckarg2(3,5);
  mat=argv[0];
  if (!ismatrix(mat)) error(E_NOVECTOR);
  size=colsize(mat);
  theta=ckfltval(argv[1]);
  c=cos(theta); s1=sin(theta);

  a=argv[2];
  if (n>=4) worldp=(argv[3]!=NIL);	/*0:local 1:world*/

  if (n==5) {
    result=argv[4];
    if (!ismatrix(result)) error(E_NOVECTOR); }
  else result=makematrix(ctx,size,size);
  rm=result->c.ary.entity->c.fvec.fv;
  m=mat->c.ary.entity->c.fvec.fv;

  if (a==K_X || a==makeint(0)) {
    k1=1; k2=2;
    if (worldp) { s2=s1; s1= -s1;}
    else s2= -s1;}
  else if (a==MK_X) {
    k1=1; k2=2;
    if (worldp) s2= -s1;
    else { s2=s1; s1= -s1;}}
  else if (a==K_Y || a==makeint(1)) {
    k1=0; k2=2;
    if (worldp) s2= -s1;
    else { s2=s1; s1= -s1;}}
  else if (a==MK_Y) {
    k1=0; k2=2;
    if (worldp) { s2=s1; s1= -s1;}
    else s2= -s1;}
  else if (a==K_Z || a==makeint(2)) {
    k1=0; k2=1;
    if (worldp) { s2=s1; s1= -s1;}
    else s2= -s1;}
  else if (a==MK_Z) {
    k1=0; k2=1;
    if (worldp) s2= -s1;
    else { s2=s1; s1= -s1;}}
  else if (a==NIL) { /* 2dimensional m.i */
    eusfloat_t m0,m1,m2,m3;
    m0=c*m[0]-s1*m[2];  m1=c*m[1]-s1*m[3];
    m2=s1*m[0]+c*m[2];  m3=s1*m[1]+c*m[3];
    rm[0]=m0; rm[1]=m1; rm[2]=m2; rm[3]=m3;
    return(result);   }
  else error(E_ROTAXIS);

  ss=size*size;
  if (mat!=result) for (i=0; i<ss; i++) rm[i]=m[i];
  for (i=0; i<size; i++) {
    if (worldp) {
      m1= &rm[k1*size+i];
      m2= &rm[k2*size+i];}
    else {
      m1= &rm[i*size+k1];
      m2= &rm[i*size+k2];}
    f1= (*m1)*c + (*m2)*s1;
    f2= (*m1)*s2 + (*m2)*c;
    *m1=f1; *m2=f2;}
  return(result);}

/*	(rotation theta floatvector [result])
/*	make rotation matrix along arbitrary axis
/*	Axis is given by floatvector, it need not to be normalized.
*/
pointer ROTATION_MATRIX(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer a,result;
  register eusfloat_t *rm;
  register int size;
  double x, y, z, s;
  double cs, sn, vers, xv, yv,zv, xyv, yzv, zxv, xs, ys, zs, norm;
  numunion nu;

  ckarg2(1,3);
  s=ckfltval(argv[0]);
  cs = cos(s); sn = sin(s); vers = 1.0 - cs;
  a=argv[1];
  if (n==1 || (n==2 && ismatrix(a))) {	/*2D rot. matrix*/
    if (n==2) result=a;
    else result=makematrix(ctx,2,2);
    rm=result->c.ary.entity->c.fvec.fv;
    rm[0]=rm[3]=cs; rm[1]=-sn; rm[2]=sn;
    return(result);}
  if (a==NIL) size=2; else size=3;
  if (n==3) { result=argv[2]; if (!ismatrix(result)) error(E_NOVECTOR);}
  else result=makematrix(ctx,size,size);
  rm=result->c.ary.entity->c.fvec.fv;
  if (isfltvector(a)) {
    if (size<=2) error(E_VECINDEX);
    x=a->c.fvec.fv[0]; y=a->c.fvec.fv[1]; z=a->c.fvec.fv[2];
    norm = sqrt(x*x + y*y + z*z);
    if (fabs(norm)<0.00001) return(NIL); /*error(E_USER,(pointer)"too small axis vector");*/
    x = x/norm; y = y/norm; z= z/norm;
    xv = x*x*vers; yv = y*y*vers; zv = z*z*vers;
    xyv = x*y*vers; yzv = y*z*vers; zxv = z*x*vers;
    xs = x*sn; ys = y*sn; zs = z*sn;
    rm[0] = xv + cs;
    rm[1] = xyv - zs;
    rm[2] = zxv + ys;
    rm[size] = xyv + zs;
    rm[size+1] = yv + cs;
    rm[size+2] = yzv - xs;
    rm[size+size] = zxv - ys;
    rm[size+size+1] = yzv + xs;
    rm[size+size+2] = zv + cs;
    return(result);}
  else {
    if (size==2) {
      rm[0]=rm[3]=cs; rm[1]=-sn; rm[2]=sn;
      return(result);}
    for (size=0; size<9; size++) rm[size]=0.0;
    if (a==makeint(0) || a==K_X) {
      rm[0]=1.0; rm[4]=cs; rm[5]= -sn; rm[7]=sn; rm[8]=cs;}
    else if (a==MK_X) {
      rm[0]=1.0; rm[4]=cs; rm[5]= sn; rm[7]=-sn; rm[8]=cs;}
    else if (a==makeint(1) || a==K_Y) {
      rm[0]=cs; rm[2]=sn; rm[4]=1.0; rm[6]= -sn; rm[8]=cs;}
    else if (a==MK_Y) {
      rm[0]=cs; rm[2]=-sn; rm[4]=1.0; rm[6]= sn; rm[8]=cs;}
    else if (a==makeint(2) || a==K_Z) {
      rm[0]=cs; rm[1]= -sn; rm[3]=sn; rm[4]=cs; rm[8]=1.0;}
    else if (a==MK_Z) {
      rm[0]=cs; rm[1]= sn; rm[3]=-sn; rm[4]=cs; rm[8]=1.0;}
    else error(E_NOVECTOR);
    return(result);} }

pointer ROTANGLE(ctx,n,argv)	/*equivalent rotation axis and angle*/
register context *ctx;
int n;
pointer argv[];
{ pointer r=argv[0];
  int size;
  eusfloat_t *m,*krv,kx,ky,kz;
  eusfloat_t th,t1,t2,t3;
  eusfloat_t cs,cs2,vers,sn2,norm;
  pointer kr;
  numunion nu;

  ckarg(1);
  if (!ismatrix(r)) error(E_NOVECTOR);
  size=colsize(r);
  m=r->c.ary.entity->c.fvec.fv;

  if (size==2) {	/*2D rotation*/
    th=atan2(m[2],m[0]);
    return(makeflt(th));}

  kr=makefvector(3);	/*axis vector*/
  krv=kr->c.fvec.fv;
  t1=m[size+size+1]-m[size+2];
  t2=m[2]	   -m[size+size];
  t3=m[size]	   -m[1];
  cs2=m[0]+m[size+1]+m[size+size+2]-1.0;
  cs=cs2/2;
  vers=1-cs;
  sn2=sqrt(t1*t1 + t2*t2 + t3*t3);
  th=atan2(sn2,cs2);
  if (th<1e-10||vers<1e-10) return(NIL);
  else if (th<2.6) {
    kx=(m[size+size+1]-m[size+2])/sn2;
    ky=(m[2]-m[size+size])/sn2;
    kz=(m[size]-m[1])/sn2;
    }
  else {
    kx=sqrt((m[0]-cs)/vers);
    if (m[size+size+1]-m[size+2]<0) kx= -kx;
    ky=sqrt((m[size+1]-cs)/vers);
    if (m[2]-m[size+size]<0) ky= -ky;
    kz=sqrt((m[size+size+2]-cs)/vers);
    if (m[size]-m[1]<0) kz= -kz;
    }
  /**/
  if (debug) 
    printf("rotation-angle1: %f %f %f\n",kx,ky,kz);
  if ((fabs(kx) > fabs(ky)) && (fabs(kx) > fabs(kz))) {
    ky=(m[size]+m[1])/(2*kx*vers); kz=(m[2]+m[size+size])/(2*kx*vers);
    norm=sqrt((ky*ky+kz*kz)/(1.0-kx*kx)); if (!isnan(norm)) {ky/=norm; kz/=norm;}}
  else if ((fabs(ky) > fabs(kx)) && (fabs(ky) > fabs(kz))) {
    kx=(m[size]+m[1])/(2*ky*vers); kz=(m[size+2]+m[size+size+1])/(2*ky*vers);
    norm=sqrt((kx*kx+kz*kz)/(1.0-ky*ky)); if (!isnan(norm)) {kx/=norm; kz/=norm;}}
  else {
    kx=(m[2]+m[size+size])/(2*kz*vers);
    ky=(m[size+2]+m[size+size+1])/(2*kz*vers);
    norm=sqrt((kx*kx+ky*ky)/(1.0-kz*kz)); if (!isnan(norm)) {kx/=norm; ky/=norm;}}
  /**/
  norm=sqrt(kx*kx + ky*ky + kz*kz);
  if (debug) 
    printf("rotation-angle2: %f %f %f norm=%f\n",kx,ky,kz,norm);
  krv[0]=kx/norm; krv[1]=ky/norm; krv[2]=kz/norm;
  kx=kx/norm; ky=ky/norm; kz=kz/norm;
  norm=sqrt(kx*kx + ky*ky + kz*kz);
  return(cons(ctx,makeflt(th),cons(ctx,kr,NIL)));}

	      
/*	(transpose mat [result])
*/
pointer TRANSPOSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register eusfloat_t *rm,*m,x;
  pointer mat,result;
  register int i,j,row,column;

  ckarg2(1,2);
  mat=argv[0];
  if (!ismatrix(mat)) error(E_NOVECTOR);
  column=colsize(mat); row=rowsize(mat);
  if (n==2) {
    result=argv[1];
    if (!ismatrix(result)) error(E_NOVECTOR);
    if (rowsize(result)!=column || colsize(result)!=row) error(E_VECINDEX);}
  else result=makematrix(ctx,column,row);
  rm=result->c.ary.entity->c.fvec.fv;
  m=mat->c.ary.entity->c.fvec.fv;
  if (result==mat) /*square matrix*/
    for (i=0; i<row; i++) 
      for (j=0; j<=i; j++) {
	x=m[j*column+i];
        rm[j*column+i]=m[column*i+j];
        rm[column*i+j]=x;}
  else 
    for (i=0; i<row; i++) 
      for (j=0; j<column; j++) rm[j*row+i]=m[i*column+j];
  return(result);}

/* get roll, pitch yaw angles out of rotation matrix*/
pointer INV_RPY(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer mat;
  eusfloat_t a, b, c, sa, ca;
  register eusfloat_t *mv;
  pointer result,result2;
  numunion nu;

  ckarg(1);
  mat=argv[0];
  if (!ismatrix(mat)) error(E_NOVECTOR);
  if (colsize(mat)!=3) error(E_VECINDEX);
  mv=mat->c.ary.entity->c.fvec.fv;
  a = atan2(mv[3],mv[0]);
  sa = sin(a); ca = cos(a);
  b = atan2(-mv[6], ca*mv[0] + sa*mv[3]);
  c = atan2(sa*mv[2] - ca*mv[5], -sa*mv[1] + ca*mv[4]);
  result = cons(ctx,makeflt(c), NIL);
  result = cons(ctx,makeflt(b), result);
  result = cons(ctx,makeflt(a), result);
  a=a + M_PI;
  sa = sin(a); ca = cos(a);
  b = atan2(-mv[6], ca*mv[0] + sa*mv[3]);
  c = atan2(sa*mv[2] - ca*mv[5], -sa*mv[1] + ca*mv[4]);
  result2 = cons(ctx,makeflt(c), NIL);
  result2 = cons(ctx,makeflt(b), result2);
  result2 = cons(ctx,makeflt(a), result2);
  result2 = cons(ctx,result2,NIL);
  return(cons(ctx,result,result2));}

pointer INV_EULER(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer mat;
  eusfloat_t a, b, c, sa, ca;
  register eusfloat_t *mv;
  pointer result,result2;
  numunion nu;

  ckarg(1);
  mat=argv[0];
  if (!ismatrix(mat)) error(E_NOVECTOR);
  if (colsize(mat)!=3) error(E_VECINDEX);
  mv=mat->c.ary.entity->c.fvec.fv;
  if (-0.00001<mv[5] && mv[5]<0.00001 && -0.00001<mv[2] && mv[2]<0.00001) a=0.0;
  else a = atan2(mv[5],mv[2]);
  sa = sin(a); ca = cos(a);
  b = atan2(ca*mv[2]+sa*mv[5],mv[8]);
  c = atan2(-sa*mv[0]+ca*mv[3], -sa*mv[1] + ca*mv[4]);
  result = cons(ctx,makeflt(c), NIL);
  result = cons(ctx,makeflt(b), result);
  result = cons(ctx,makeflt(a), result);
  a=a + M_PI;
  sa = sin(a); ca = cos(a);
  b = atan2(ca*mv[2]+sa*mv[5],mv[8]);
  c = atan2(-sa*mv[0]+ca*mv[3], -sa*mv[1] + ca*mv[4]);
  result2 = cons(ctx,makeflt(c), NIL);
  result2 = cons(ctx,makeflt(b), result2);
  result2 = cons(ctx,makeflt(a), result2);
  result2 = cons(ctx,result2,NIL);
  return(cons(ctx,result,result2));}

/****************************************************************/
/*
/* simultaneous equation solver by LU decomposition method
/* 
/*	1987-July-1
/*	Copyright Toshihiro MATSUI
/*
/****************************************************************/

#define elm(a,i,j) (a->c.vec.v[j]->c.fvec.fv[i])
#define EPS (1.0E-10)

static int decompose(a,s,p)
register eusfloat_t *a;
register int s;
eusinteger_t p[];
{
  register int i,j,k,l;
  eusfloat_t al,bl;

  for (i=0; i<s; i++) p[i]=i;
  for (k=0; k<s; k++) {
    /*select pivot*/
    l=k;
    al=fabs(a[p[l]*s+k]);
    for (i=k+1; i<s; i++) 
      if ((bl=fabs(a[p[i]*s+k])) > al) { l=i; al=bl;}
    if (l!=k) {
      /*change rows*/
      j=p[k]; p[k]=p[l]; p[l]=j; }
    if (al<EPS) return(-1);	/* singular*/
    /* gauss elimination */
    a[p[k]*s+k]= 1.0/a[p[k]*s+k];
    for (i=k+1; i<s; i++) {
      al=a[p[i]*s+k]=a[p[i]*s+k]*a[p[k]*s+k];
      for (j=k+1; j<s; j++) a[p[i]*s+j] -= al*a[p[k]*s+j];
      }
    }
  return(0);
  }

pointer LU_DECOMPOSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
/* (LU-DECOMPOSE mat [result]) */
{ pointer a,result,pv;
  int s,stat;

  ckarg2(1,2);
  a=argv[0];
  if (!ismatrix(a)) error(E_NOVECTOR);
  s=colsize(a);
  if (s!=rowsize(a)) error(E_VECSIZE);
  if (n==1) result=a;
  else {
    result=argv[1];
    if (!ismatrix(result)) error(E_NOVECTOR);
    if (s!=colsize(result)) error(E_VECSIZE);
    copymat(result,a,s); }
  pv=makevector(C_VECTOR,s);
  stat=decompose(result->c.ary.entity->c.fvec.fv,s,(eusinteger_t *)pv->c.vec.v);
  while (--s>=0) pv->c.vec.v[s]=makeint((eusinteger_t)pv->c.vec.v[s]);
  if (stat<0) return(NIL);
  else return(pv);}

static void solve(a,pv,s,b,x)
register eusfloat_t *a;
pointer b,x,pv;
int s;
{ register int i,j;
  eusfloat_t t;
  register pointer *p;
  p=pv->c.vec.v;

  /*forward substitution*/
  for (i=0; i<s; i++) {
    t=b->c.fvec.fv[intval(p[i])];
    for (j=0; j<i; j++) t-= a[intval(p[i])*s+j]*x->c.fvec.fv[j];
    x->c.fvec.fv[i]=t;}
  /*backward substitution*/
  for (i=s-1; i>=0; i--) {
    t=x->c.fvec.fv[i];
    for (j=i+1; j<s; j++) t-= a[intval(p[i])*s+j]*x->c.fvec.fv[j];
    x->c.fvec.fv[i]=t*a[intval(p[i])*s+i];}
}

pointer LU_SOLVE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a,p,b,x;
  int s;

  ckarg2(3,4);
  a=argv[0];  p=argv[1]; b=argv[2];
  if (!ismatrix(a)) error(E_NOVECTOR);
  s=colsize(a);
  if (!isvector(p) || !isfltvector(b)) error(E_NOVECTOR);
  if (s!=vecsize(p) || s!=vecsize(b)) error(E_VECSIZE);
  if (n==4) {
    x=argv[3];
    if (!isvector(x)) error(E_NOVECTOR);
    if (s!=vecsize(x)) error(E_VECSIZE); }
  else  x=(pointer)makefvector(s);
  solve(a->c.ary.entity->c.fvec.fv,p,s,b,x);
  return(x);}

pointer LU_DETERMINANT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a,p;
  register eusfloat_t *av;
  register int i,s;
  eusfloat_t val=1.0;
  numunion nu;
  ckarg(2);
  a=argv[0]; p=argv[1];
  if (!isvector(p) || !ismatrix(a)) error(E_NOVECTOR);
  s=vecsize(p);
  if (colsize(a)!=s || rowsize(a)!=s) error(E_VECSIZE);
  av=a->c.ary.entity->c.fvec.fv;
  for (i=0; i<s; i++) val*=av[intval(p->c.vec.v[i])*s+i];
  return(makeflt(1.0/val));}

void matrix(ctx,mod)
register context *ctx;
register pointer mod;
{
  K_X=defkeyword(ctx,"X");
  K_Y=defkeyword(ctx,"Y");
  K_Z=defkeyword(ctx,"Z");
  MK_X=defkeyword(ctx,"-X");
  MK_Y=defkeyword(ctx,"-Y");
  MK_Z=defkeyword(ctx,"-Z");

  defun(ctx,"V+",mod,VPLUS,NULL);
  defun(ctx,"V++",mod,VPLUSPLUS,NULL);
  defun(ctx,"V-",mod,VMINUS,NULL);
  defun(ctx,"V-ABS",mod,VMINUS_ABS,NULL);
  defun(ctx,"V.",mod,VINNERPRODUCT,NULL);
  defun(ctx,"V*",mod,VCROSSPRODUCT,NULL);
  defun(ctx,"V.*",mod,SCA3PROD,NULL);
  defun(ctx,"V<",mod,VLESSP,NULL);
  defun(ctx,"V>",mod,VGREATERP,NULL);
  defun(ctx,"VMIN",mod,VMIN,NULL);
  defun(ctx,"VMAX",mod,VMAX,NULL);
  defun(ctx,"MINIMAL-BOX",mod,MINIMALBOX,NULL);
  defun(ctx,"SCALE",mod,SCALEVEC,NULL);
  defun(ctx,"NORM",mod,VNORM,NULL);
  defun(ctx,"NORM2",mod,VNORM2,NULL);
  defun(ctx,"NORMALIZE-VECTOR",mod,VNORMALIZE,NULL);
  defun(ctx,"DISTANCE",mod,VDISTANCE,NULL);
  defun(ctx,"DISTANCE2",mod,VDISTANCE2,NULL);
  defun(ctx,"DIRECTION",mod,VDIRECTION,NULL);
  defun(ctx,"MIDPOINT",mod,MIDPOINT,NULL);
/*  defun(ctx,"TRIANGLE",mod,TRIANGLE,NULL); */
  defun(ctx,"FLOATVECTOR",mod,MKFLTVEC,NULL);
  defun(ctx,"FLOAT-VECTOR",mod,MKFLTVEC,NULL);
  defun(ctx,"TRANSFORM",mod,TRANSFORM,NULL);
  defun(ctx,"M*",mod,MATTIMES,NULL);
  defun(ctx,"ROTATE-VECTOR",mod,ROTVEC,NULL);
  defun(ctx,"ROTATE-MATRIX",mod,ROTMAT,NULL);
  defun(ctx,"ROTATION-MATRIX",mod,ROTATION_MATRIX,NULL);
  defun(ctx,"ROTATION-ANGLE",mod,ROTANGLE,NULL);
  defun(ctx,"TRANSPOSE",mod,TRANSPOSE,NULL);
  defun(ctx,"RPY-ANGLE",mod,INV_RPY,NULL);
  defun(ctx,"EULER-ANGLE",mod,INV_EULER,NULL);
  defun(ctx,"LU-DECOMPOSE",mod,LU_DECOMPOSE,NULL);
  defun(ctx,"LU-SOLVE",mod,LU_SOLVE,NULL);
  defun(ctx,"LU-DETERMINANT",mod,LU_DETERMINANT,NULL);}
