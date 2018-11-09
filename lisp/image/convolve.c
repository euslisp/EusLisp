/* cc -c -Bstatic -Dsun4 -I../c convolve.c */

#include "../c/eus.h"

#pragma init (init_object_module)
pointer convolve();
static void init_object_module()
  { add_module_initializer("convolve", convolve);}

#define is2Dstring(a) (isarray(a) && \
			((a)->c.ary.rank==makeint(2)) && \
			isstring((a)->c.ary.entity))
pointer CONVOLVE3(ctx,n,argv)
/* (convolve3 convolution_mask divisor image result) */
context *ctx;
int n;
pointer argv[];
{
  pointer convp, imgp, resultp;
  char *conv;
  unsigned char *img, *result, *g;
  register int x,y,width,height, v, diviser;

  ckarg(4);
  convp= argv[0]; imgp=argv[2]; resultp= argv[3];
  diviser=ckintval(argv[1]);
  if (!is2Dstring(convp) || !is2Dstring(imgp) || !is2Dstring(resultp)) 
    error(E_NOARRAY);
  conv=(char *)(convp->c.ary.entity->c.str.chars);
  img=imgp->c.ary.entity->c.str.chars;
  result=resultp->c.ary.entity->c.str.chars;
  width=intval(imgp->c.ary.dim[1]); height=intval(imgp->c.ary.dim[0]);

  for (y=1; y<=height-1; y++) {
    for (x=1; x<=width-1; x++) {
      g= &img[width*y+x];
      v= g[-width-1]*conv[0] + g[-width]* conv[1] + g[-width+1]*conv[2] +
	 g[-1]*conv[3] + g[0]* conv[4] + g[1]*conv[5] +
	 g[width-1]*conv[6] + g[width]* conv[7] + g[width+1]*conv[8];
      result[width*y+x]=v/diviser;}
    }
  return(resultp);}

pointer LOOK_UP(ctx,n,argv)
/* foreach element indexed i, result[i]=table[src[i]] */
context *ctx;
int n;
pointer argv[];
{ pointer imgp, tablep, resultp;
  register unsigned char *img, *ctable, *result;
  register long size, i;
  register eusinteger_t *itable;

  ckarg(3);
  imgp=argv[0];  resultp= argv[1]; tablep=argv[2];
  if (!isstring(imgp) || !isvector(tablep) || !isstring(resultp))
	error(E_NOSTRING);
  if (elmtypeof(imgp)==ELM_FOREIGN)
    img=(unsigned char *)imgp->c.ivec.iv[0];
  else  img=imgp->c.str.chars;
  if (elmtypeof(resultp)==ELM_FOREIGN)
    result=(unsigned char *)resultp->c.ivec.iv[0];
  else  result=resultp->c.str.chars;
  size=vecsize(imgp);
  if (elmtypeof(tablep)==ELM_INT) {
    itable=tablep->c.ivec.iv;
    for (i=0; i<size; i++) result[i]=itable[img[i]];}
  else if (elmtypeof(tablep)==ELM_CHAR || elmtypeof(tablep)==ELM_BYTE) {
    ctable=tablep->c.str.chars;
    for (i=0; i<size; i++) result[i]=ctable[img[i]];}
  return(resultp);}

pointer HALVE_IMAGE(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer imgp, half_imgp;
  register unsigned char *img, *half_img;
  register int i, j, base, half_base;
  int          width, height;
  register int half_width, half_height;

  ckarg(2);
  imgp=argv[0]; half_imgp=argv[1];
  if (!is2Dstring(imgp) || !is2Dstring(half_imgp)) error(E_NOARRAY);
  width=intval(imgp->c.ary.dim[1]);
  height=intval(imgp->c.ary.dim[0]);
  half_width=width/2; half_height=height/2;

  img= imgp->c.ary.entity->c.str.chars;
  half_img= half_imgp->c.ary.entity->c.str.chars;

  for (j=0; j<half_height; j++) {
    base= width*j*2; half_base=half_width*j;
    for (i=0; i<half_width; i++) 
      half_img[half_base+i]=
       (unsigned long)(img[base+i*2]+img[base+i*2+1]+
	img[base+width+i*2]+img[base+i*2+width+1])/4; }
  return(half_imgp);}

pointer DOUBLE_IMAGE(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer imgp, double_imgp;
  register unsigned char *img, *double_img;
  register int i, j, base, double_base;
  int          width, height;
  register int double_width, double_height;

  ckarg(2);
  imgp=argv[0]; double_imgp=argv[1];
  if (!is2Dstring(imgp) || !is2Dstring(double_imgp)) error(E_NOARRAY);
  width=intval(imgp->c.ary.dim[1]);
  height=intval(imgp->c.ary.dim[0]);
  double_width=width*2; double_height=height*2;

  img= imgp->c.ary.entity->c.str.chars;
  double_img= double_imgp->c.ary.entity->c.str.chars;

  for (j=0; j<height; j++) {
    base= width*j; double_base=double_width*j*2;
    for (i=0; i<width; i++) 
      double_img[double_base+i*2]=
      double_img[double_base+i*2+1]=
      double_img[double_base+double_width+i*2]=
      double_img[double_base+double_width+i*2+1]=
	(unsigned long)(img[base+i]);
	 }
  return(double_imgp);}

/* (median img1 grid scale imgr) */
static int median_img(img, width, height, x, y, size)
unsigned char *img;
register int width, height, x, y, size;
{ register int med, p, q, r;
  register int i, j, k, v, cindex;
  unsigned char seq[100], up[100], down[100];

  cindex=size*size/2;
  k=0;
  for (j=0; j<size; j++) 
    for (i=0; i<size; i++) 
      seq[k++]= img[(j+y)*width+(x+i)];

  find_med:

  med=seq[0];
  p=q=r=0;

  for (i=0; i<k; i++)
    v=seq[i];
    if (v==med) r++;
    else if (v>med) up[p++]=v;
    else down[q++]=v;

  if (q<=cindex) 
    if (q+r>=cindex) return(med);
    else { /* find (p-cindex)th in up */
      for (i=0; i<p; i++) seq[i]=up[i];
      cindex=cindex-(q+r); k=p;
      goto find_med; }
  else {
    for (i=0; i<q; i++) seq[i]=down[i];
    k=q;
    goto find_med; }
  }

pointer MEDIAN_IMAGE(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer img1, img2;
  register unsigned char *img1p, *img2p;
  register int i,j;
  int          width, height, swidth, sheight;
  int	hgrid, grid_size, hscale, scale;

  ckarg2(2,4);
  img1=argv[0];
  width=intval(img1->c.ary.dim[1]);
  height=intval(img1->c.ary.dim[0]);
  grid_size=ckintval(argv[1]);
  scale = ckintval(argv[2]);
  hgrid=grid_size/2;
  hscale=scale/2;
  img2=argv[3];
  if (!is2Dstring(img1) || !is2Dstring(img2)) error(E_NOARRAY);
  img1p=img1->c.ary.entity->c.str.chars;
  img2p=img2->c.ary.entity->c.str.chars;
  swidth=width/scale;
  sheight=height/scale;
  for (j=0; j<sheight-1; j++) {
    for (i=0; i<swidth-1; i++) {
      img2p[j*swidth+i]=
	median_img(img1p, width, height, scale*i, scale*j, grid_size);
      }}
  return(img2);}

pointer convolve(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];

/*  printf("convolve is being initialized. mod=%x\n",mod); */
  defun(ctx,"CONVOLVE3",mod,CONVOLVE3,NULL);
  defun(ctx,"LOOK-UP",mod,LOOK_UP,NULL);
  defun(ctx,"HALVE-IMAGE",mod,HALVE_IMAGE,NULL);
  defun(ctx,"DOUBLE-IMAGE",mod,DOUBLE_IMAGE,NULL);
  defun(ctx,"MEDIAN-IMAGE",mod,MEDIAN_IMAGE,NULL);
}

