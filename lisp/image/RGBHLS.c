/****************************************************************
/* RGBHLS.c
/* (c)1995, Toshihiro Matsui, Electrotechnical Laboratory
/****************************************************************/

static char *rcsid= "@(#)$Id: RGBHLS.c,v 1.1.1.1 2003/11/20 07:46:30 eus Exp $";

#include <math.h>
#include "../c/eus.h"

#pragma init (init_object_module)
pointer RGBHLS();

static void init_object_module()
  { add_module_initializer("RGBHLS", RGBHLS);}

void rgb_to_hls(r,g,b,h,l,s)
int r,g,b;	/* inputs 0..255*/
int *h, *l, *s;
{ 
  int v,m,vm,r2,g2,b2;
  float f;

  v = max(r,g); v=max(v,b);
  m = min(r,g); m=min(m,b);

  if ((*l = (m + v) / 2) <= 0) {*h= *s=0; return;}
  if ((*s = vm = v-m) > 0)  
    if (*l <=128) {
	f=(float)(*s)/(float)(v+m);
        *s = 255*f;}
    else {
	f=(float)(*s)/(float)(511-v-m);
	*s= 255 * f;}
  else {*h = 0; return;}

  r2= 255 * (v-r) / vm;
  g2= 255 * (v-g) / vm;
  b2= 255 * (v-b) / vm;

  if (r==v)
    *h = (g==m ? 5*255+b2 : 255-g2);
  else if (g==v)
    *h= (b==m ? 255+r2 : 3*255-b2);
  else *h = (r==m ? 3*255 + g2 : 5*255 - r2);
  *h /= 6;}


void hls_to_rgb(h,l,s,r,g,b)
int h,l,s;
int *r, *g, *b;
{ float v; }

pointer RGB_TO_HLS(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ int h,l,s,v;
  ckarg(3);
  rgb_to_hls(ckintval(argv[0]), ckintval(argv[1]), ckintval(argv[2]),
		&h, &l, &s);
  h=min(h,255); l=min(l,255); s=min(s,255);
  /*  printf("h=%d l=%d s=%d\n",h,l,s); */
  v= (h << 16) | (l << 8) | s;
  return(makeint(v));}

pointer RGBHLS(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
  defun(ctx,"RGB-TO-HLS", mod, RGB_TO_HLS,NULL);
  return(T);
  }

