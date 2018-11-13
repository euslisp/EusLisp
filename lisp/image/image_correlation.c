/****************************************************************/
/* image_correlation.c
/* rectangular window match: image-correlation pattern window ...
/* linear match: circular-correlation pattern target num_components
/* gcc -c -Di386 -DLinux -w -DGCC  -fpic  -I../c -O image_correlation.c;
   ld -shared -o image_correlation.so image_correlation.o
/* cc -c -O -Dsun4 -Bstatic -I../../c cor.c
*****************************************************************/

#include "eus.h"
#include "pix.h"
#define abs(x) ((x)<0?-(x):x)
#define imgvec(img,x,y) (&((img)->imgary[(y)*(img)->twidth + x]))

#pragma init (init_object_module)
pointer image_correlation();

static void init_object_module()
  { add_module_initializer("image_correlation", image_correlation);}



static void set_pixparams(piximg, eusary)
pixel_image *piximg;
pointer eusary;
{ pointer imgp;
  imgp=eusary->c.ary.entity;
/*  printf("imgp=%x\n", imgp); */
  piximg->imgary=
	(elmtypeof(imgp)==ELM_FOREIGN)?
		((unsigned char *)imgp->c.ivec.iv[0]) :
		(imgp->c.str.chars);
/*  printf("imgary=%x\n", piximg->imgary); */
  piximg->depth=8;
  piximg->twidth=intval(eusary->c.ary.dim[1]);
  piximg->theight=intval(eusary->c.ary.dim[0]);
  piximg->tsize=piximg->twidth*piximg->theight;
  piximg->width=intval(eusary->c.ary.dim[1]);
  piximg->height=intval(eusary->c.ary.dim[0]);
  piximg->wsize=piximg->width * piximg->height; }

static int img_correlation1(image,pattern,x,y)
register pixel_image *image, *pattern;
register int x, y;
{ register unsigned char *img=image->imgary, *pat=pattern->imgary;
  register int i, j;
  register int ww=pattern->width;
  register long cor, corsum=0;
  int tiw=image->twidth, piw=pattern->twidth;
  int wh=pattern->height;

  img=imgvec(image, x, y);
  pat=imgvec(pattern, 0, 0);
  for (j=0; j<wh; j++) {
    for (i=0; i<ww; i++) {
      cor=img[i]-pat[i];
      corsum+= abs(cor);}
    img+=tiw; pat+=piw;
    }
  return(corsum);}

struct corinfo {
  long corval;
  long x,y;
  };

static int img_correlation(image,pattern,x0,y0,size,threshold,result)
pixel_image *image, *pattern;
register int size;
register int threshold;
int x0, y0;
struct corinfo *result;
{ register unsigned char *img=image->imgary, *pat=pattern->imgary;
  register int i, j;
  register int x, y;
  register int tiw=image->twidth, piw=pattern->twidth;
  register int ww=pattern->width;
  register long cor, corsum;
  register int  wh=pattern->height;
  int  found=0;

  for (y=y0; y<y0+size; y++) {
    for (x=x0; x<x0+size; x++) {
      /* compute correlation for a particular window */
      corsum=0;
      img=imgvec(image, x, y);
      pat=imgvec(pattern, 0, 0);
      for (j=0; j<wh; j++) {
        for (i=0; i<ww; i++) {
          cor=img[i]-pat[i];
	  if (cor>0) corsum+=cor;
	  else corsum-=cor;}
        if (corsum>threshold) goto nextwindow;
        img+=tiw; pat+=piw;  }

      /* correlation factor for a window is obtained in corsum */
      if (corsum<threshold) {
	if (debug) printf("cor=%ld (%d, %d)\n", corsum, x, y);
        found=1;
	threshold=corsum;
	result->corval=corsum;
	result->x=x; result->y=y;};
      /* try a next window */
      nextwindow: continue;
      } }
  return(found);}

static pointer IMAGE_CORRELATION1(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer arg0, arg1;
  pixel_image img,pat;
  int x,y, cor;
  ckarg(4);
  set_pixparams(&img, argv[0]);
  set_pixparams(&pat, argv[1]);
  x=ckintval(argv[2]); y=ckintval(argv[3]);
  cor=img_correlation1(&img, &pat, x, y);
  return(makeint(cor));}


/* (IMAGE-CORRELATION image pattern x y size threshold) */

static pointer IMAGE_CORRELATION(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer arg0, arg1;
  pixel_image img,pat;
  int x,y, cor, size, threshold;
  struct { long corval, x, y;} result;
  ckarg(6);
  set_pixparams(&img, argv[0]);
  set_pixparams(&pat, argv[1]);
  x=ckintval(argv[2]); y=ckintval(argv[3]);
  size=ckintval(argv[4]);  threshold=ckintval(argv[5]); 
  cor=img_correlation(&img, &pat, x, y, size, threshold, &result);
  if (cor) {
    vpush(makeint(result.corval));
    vpush(makeint(result.x));
    vpush(makeint(result.y));
    return((pointer)stacknlist(ctx,3));}
  else return(NIL);}


static pointer CIRCULAR_CORRELATION(ctx,n,argv)
/* Actually, this is a linear correlation. */
context *ctx;
int n;
pointer argv[];
{ unsigned char *pat1, *pat2, pat2x[1024*4];
  int len, num_components, total_len, i, j, k, x, y;
  int c, cor, min_cor, min_pos, max_cor, avecor, total_cor;
  float fcor, flen;
  pointer fcorvec, r;
  numunion nu;

  ckarg(3);
  num_components=ckintval(argv[2]);
  pat1=get_string(argv[0]);
  pat2=get_string(argv[1]);
  total_len=vecsize(argv[0]);
  if (total_len != vecsize(argv[1])) error(E_VECSIZE);
  if (total_len >=1024*3) error(E_ARRAYINDEX);
  memcpy(&pat2x[0], pat2, total_len);
  memcpy(&pat2x[total_len], pat2, total_len);
  len=total_len/num_components;
  flen=len;
  fcorvec=makevector(C_FLTVECTOR, len);
  vpush(fcorvec);

  min_pos = -1; min_cor=0x3fffffff; max_cor=0; total_cor=0;

  for (i=0; i<len; i++) {
    cor=0; x=i*num_components;
    for (j=0; j<len; j++) {
      c=0; y=j*num_components;
      for (k=0; k<num_components; k++) c += abs(pat2x[x+j+k]-pat1[j+k]);
      cor += c/num_components; }
    if (cor < min_cor) { min_cor=cor; min_pos=i; }
    else if (cor>max_cor) max_cor=cor;
    total_cor += cor;
    fcorvec->c.fvec.fv[i]=(float)cor/total_len;
    }
  vpush(makeint(min_pos));
  vpush(makeflt(min_cor/(flen*num_components)));
  vpush(makeflt(total_cor/(flen*num_components*flen)));
  vpush(makeflt(max_cor/(len*num_components)));
  vpush(fcorvec);
  r=stacknlist(ctx,5);
  vpop();
  return(r);}

pointer image_correlation(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
  defun(ctx,"IMAGE-CORRELATION1",mod,IMAGE_CORRELATION1,NULL);
  defun(ctx,"IMAGE-CORRELATION",mod,IMAGE_CORRELATION,NULL);
  defun(ctx,"CIRCULAR-CORRELATION",mod,CIRCULAR_CORRELATION,NULL);
  return(NIL);
  }
