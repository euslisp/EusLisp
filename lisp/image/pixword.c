/*
pixword.c
(c)1995, Toshihiro Matsui, Electrotechnical Laboratory
*/
static char *rcsid= "@(#)$Id: pixword.c,v 1.1.1.1 2003/11/20 07:46:30 eus Exp $";

#include "../c/eus.h"

#pragma init (init_object_module)
pointer pixword();

static void init_object_module()
  { add_module_initializer("pixword", pixword);}

pointer SPLIT_RGB(ctx,n,argv)
context *ctx;
int n;
pointer *argv;
{ register int size3, size1, s1, s3, offset;
  byte *rgb, *r, *g, *b;
  pointer rgbp, rp, gp, bp;

  /* a vector each of which element represents RGB colors is
     split into three vectors for R, G, and B */

  ckarg2(4,6);
  if (!isstring(argv[0])) error(E_NOSTRING);
  if (!isstring(argv[1])) error(E_NOSTRING);
  if (!isstring(argv[2])) error(E_NOSTRING);
  if (!isstring(argv[3])) error(E_NOSTRING);

  if (n>=5) offset=ckintval(argv[4]); else offset=0;

  rgbp=argv[0];  rp=argv[1];  gp=argv[2];  bp=argv[3];
  r=rp->c.str.chars; g=gp->c.str.chars; b=bp->c.str.chars; 
  rgb=rgbp->c.str.chars;
  if (n==6)   size3=ckintval(argv[5]);
  else size3=vecsize(rgbp);

  size1=size3/3;
  for (s1=0, s3=0; s1<size1; s1++)  {
    r[offset+s1]=rgb[s3++];
    g[offset+s1]=rgb[s3++];
    b[offset+s1]=rgb[s3++];}
  return(makeint(size3));}

pointer MERGE_RGB(ctx,n,argv)
context *ctx;
int n;
pointer *argv;
{ register int size3, size1, s1, s3, offset;
  byte *rgb, *r, *g, *b;

  /* three R,G, and B vectors are merged into one RGB vector */
  /* (merge-rgb rgbvec red green blue) */
  ckarg(5);
  if (!isstring(argv[0])) error(E_NOSTRING);
  if (!isstring(argv[1])) error(E_NOSTRING);
  if (!isstring(argv[2])) error(E_NOSTRING);
  if (!isstring(argv[3])) error(E_NOSTRING);
  size1=vecsize(argv[0]);
  rgb=argv[0]->c.str.chars;
  r=argv[1]->c.str.chars;
  g=argv[2]->c.str.chars;
  b=argv[3]->c.str.chars; 
  offset=ckintval(argv[4]);
  size3=vecsize(argv[0]);
  for (s1=0, s3=0; s3<size3; s1++)  {
    rgb[s3++]=r[s1+offset];
    rgb[s3++]=g[s1+offset];
    rgb[s3++]=b[s1+offset];}
  return(argv[0]);}

pointer pixword(ctx,n,argv)
  context *ctx;
  int n;
  pointer argv[];
{ pointer mod=argv[0];
  defun(ctx,"SPLIT-RGB",mod,SPLIT_RGB,NULL);
  defun(ctx,"MERGE-RGB",mod,MERGE_RGB,NULL);
  }

