/* charconv.c 
/* (c) 2003, Toshihiro Matsui, Digital Human Research Lab, AIST
Character code conversion using iconv library.

% cc -c -fpic -Di486 -DLinux charconv.c -I/usr/local/eus/include
% ld  -o charconv.so -shared charconv.o
eus$ (load "charconv.so")
eus$ (iconv "euc-jp" "Shift-jis" "松井")

*/

#include <stdlib.h>
#include <iconv.h>
#include <errno.h>

#include "eus.h"

static pointer cconv(context *ctx, int n, pointer *argv)
{
  iconv_t cd;
  size_t inbytesleft, outbytesleft;
  char *outbufp1, *outbufp2, *instrp;
  size_t ret;
  pointer instr=argv[2], outstr;
  size_t len=vecsize(instr); 

  inbytesleft=len;
  outbytesleft=len*2;
  outbufp1= outbufp2= malloc(outbytesleft);
  instrp= &(instr->c.str.chars[0]);

  /* get acceptable codings by 'iconv --list' */
  /* cd=iconv_open(to_code, from_code); */
  /* cd=iconv_open("Shift_JIS", "EUC-JP"); */
  cd=iconv_open(argv[1]->c.str.chars, argv[0]->c.str.chars);
  if (cd == (iconv_t)-1) { outstr= (pointer)makeint(errno); goto conv_end;}

  ret=iconv(cd, &instrp, &inbytesleft, &outbufp2, &outbytesleft);
  if (ret == -1) { outstr=makeint(-errno); goto conv_end;}
  else  outstr=makestring(outbufp1, len*2-outbytesleft);

  conv_end: 
  iconv_close(cd);
  cfree(outbufp1);
  return(outstr);
  }

pointer ICONVOPEN(context *ctx, int n, pointer *argv)
{ int cd;
  ckarg(2);
  if (!isstring(argv[0])) error (E_NOSTRING, argv[0]);
  if (!isstring(argv[1])) error (E_NOSTRING, argv[1]);
  cd=iconv_open(argv[0]->c.str.chars, argv[1]->c.str.chars);
  return(mkbigint(cd));}

pointer ICONVCLOSE(context *ctx, int n, pointer *argv)
{ int cd, ret;
  ckarg(1);
  cd=bigintval(argv[0]);
  ret=iconv_close(cd);
  return(makeint(ret));
  }

pointer ICONV(context *ctx, int n, pointer *argv)
{ int cd, ret, malloced=NULL;
  char *srcstrp, *deststrp, *deststrpv, deststr[1024];
  size_t srcstrlen, deststrlen;
  pointer dest;

  ckarg(2);
  cd=bigintval(argv[0]);
  if (!isstring(argv[1])) error(E_NOSTRING);
  srcstrp=argv[1]->c.str.chars;
  srcstrlen=strlength(argv[1]);
  deststrlen=2*srcstrlen;
  if (deststrlen>=1024) {
    deststrp=malloc(deststrlen);
    malloced=1;}
  else deststrp=deststr;
  deststrpv=deststrp;
  ret=iconv(cd, &srcstrp, &srcstrlen, &deststrpv, &deststrlen);
  if (ret== -1) { dest=NIL; goto iconvend;}
  dest=makestring(deststrp, 2*strlength(argv[1])-deststrlen);
  iconvend:
  if (malloced) cfree(deststrp);
  return(dest);
  }

charconv(context *ctx, int n, pointer argv[])
{ pointer mod=argv[0];
  defun(ctx,"CHARCONV",mod,cconv,NULL);
  defun(ctx,"ICONV-OPEN", mod, ICONVOPEN,NULL);
  defun(ctx,"ICONV-CLOSE", mod, ICONVCLOSE,NULL);
  defun(ctx, "ICONV", mod, ICONV,NULL);
  }


