/****************************************************************
/* CHARACTER and STRING functions
/*	1987-Dec-17
/*	Copyright(c) Toshihiro MATSUI, ETL, 1988.
/****************************************************************/
static char *rcsid="@(#)$Id: charstring.old.c,v 1.1.1.1 2003/11/20 07:46:26 eus Exp $";
#include <ctype.h>
#include "eus.h"

extern byte *get_string();

pointer CHAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  ckarg(2);
  n=ckintval(argv[1]);
  if (!isstring(a)) error(E_NOSTRING);
  if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
/* This code should be eliminated, because the compiler cannot know if
   this object is a normal string or a foreign string, thus no optimization.
  if (elmtypeof(a)==ELM_FOREIGN) 
    return(makeint((a->c.foreign.chars)[n]));
  else */
  return(makeint(a->c.str.chars[n]));}

pointer SETCHAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  register int newval=ckintval(argv[2]);
  ckarg(3);
  n=ckintval(argv[1]);
  if (!isstring(a)) error(E_NOSTRING);
  if (n<0 || vecsize(a)<=n) error(E_ARRAYINDEX);
/*  if (elmtypeof(a)==ELM_FOREIGN) 
    ((byte *)(a->c.ivec.iv[0]))[n]=newval;
  else */
  a->c.str.chars[n]=newval;
  return(argv[2]);}

pointer UPCASEP(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ ckarg(1);  n=ckintval(argv[0]);
  return((isupper(n))?T:NIL);}

pointer LOWCASEP(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ ckarg(1);  n=ckintval(argv[0]);
  return((islower(n))?T:NIL);}

pointer ALPHAP(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ ckarg(1);  n=ckintval(argv[0]);
  return((isalpha(n))?T:NIL);}

pointer DIGITP(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ ckarg(1);  n=ckintval(argv[0]);
  return((isdigit(n))?T:NIL);}

pointer ALNUMP(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ ckarg(1);  n=ckintval(argv[0]);
  return((isalnum(n))?T:NIL);}

pointer CHUPCASE(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ ckarg(1); n=ckintval(argv[0]);
  return((islower(n))?(makeint(toupper(n))):argv[0]);}

pointer CHDOWNCASE(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ ckarg(1);  n=ckintval(argv[0]);
  return((isupper(n))?(makeint(tolower(n))):argv[0]);}

pointer STRINGEQ(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register byte *str1, *str2;
  int start1,end1,start2,end2;
  register int len;
  pointer s1=Getstring(argv[0]), s2=Getstring(argv[1]);
  ckarg(6);
  start1=ckintval(argv[2]); end1=ckintval(argv[3]);
  end1=min(end1,vecsize(s1));
  start2=ckintval(argv[4]); end2=ckintval(argv[5]);
  end2=min(end2,vecsize(s2));
  len=end1-start1;
  if (len!=end2-start2) return(NIL);
  str1= &s1->c.str.chars[start1]; str2= &s2->c.str.chars[start2];
  while (len-->0)  if (*str1++ != *str2++) return(NIL);
  return(T);}

pointer STRINGEQUAL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register byte *str1, *str2;
  int start1,end1,start2,end2,ch1,ch2;
  pointer s1=Getstring(argv[0]),s2=Getstring(argv[1]);
  register int len;
  ckarg(6);
  start1=ckintval(argv[2]); end1=ckintval(argv[3]); end1=min(end1,vecsize(s1));
  start2=ckintval(argv[4]); end2=ckintval(argv[5]); end2=min(end2,vecsize(s2));
  len=end1-start1;
  if (len!=end2-start2) return(NIL);
  str1= &s1->c.str.chars[start1]; str2= &s2->c.str.chars[start2];
  while (len-->0) {
    ch1= *str1++; ch2= *str2++;
    if (islower(ch1)) ch1=toupper(ch1);
    if (islower(ch2)) ch2=toupper(ch2);
    if (ch1!=ch2) return(NIL);}
  return(T);}

/****************************************************************/
/* S T R I N G  compare
/****************************************************************/

pointer STR_LT(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (strcmp(get_string(argv[0]),get_string(argv[1]))<0) return(T);
  else return(NIL);}

pointer STR_LE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (strcmp(get_string(argv[0]),get_string(argv[1]))<=0) return(T);
  else return(NIL);}

pointer STR_EQ(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (strcmp(get_string(argv[0]),get_string(argv[1]))==0) return(T); 
  else return(NIL);}

pointer STR_GT(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (strcmp(get_string(argv[0]),get_string(argv[1]))>0) return(T);
  else return(NIL);}

pointer STR_GE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (strcmp(get_string(argv[0]),get_string(argv[1]))>=0) return(T);
  else return(NIL);}

/* initializers */

charstring(ctx,mod)
register context *ctx;
register pointer mod;
{
  defun(ctx,"CHAR",mod,CHAR,NULL);
  defun(ctx,"SCHAR",mod,CHAR,NULL);
  defun(ctx,"SETCHAR",mod,SETCHAR,NULL);
  defun(ctx,"ALPHA-CHAR-P",mod,ALPHAP,NULL);
  defun(ctx,"UPPER-CASE-P",mod,UPCASEP,NULL);
  defun(ctx,"LOWER-CASE-P",mod,LOWCASEP,NULL);
  defun(ctx,"DIGIT-CHAR-P",mod,DIGITP,NULL);
  defun(ctx,"ALPHANUMERICP",mod,ALNUMP,NULL);
  defun(ctx,"CHAR-UPCASE",mod,CHUPCASE,NULL);
  defun(ctx,"CHAR-DOWNCASE",mod,CHDOWNCASE,NULL);
  defun(ctx,"STRINGEQ",mod,STRINGEQ,NULL);
  defun(ctx,"STRINGEQUAL",mod,STRINGEQUAL,NULL);
  defun(ctx,"STRING<",mod,STR_LT,NULL);
  defun(ctx,"STRING<=",mod,STR_LE,NULL);
  defun(ctx,"STRING=",mod,STR_EQ,NULL);
  defun(ctx,"STRING>",mod,STR_GT,NULL);
  defun(ctx,"STRING>=",mod,STR_GE,NULL);
  
  }

