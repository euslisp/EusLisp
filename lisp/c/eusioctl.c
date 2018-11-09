/****************************************************************/
/* ioctl.c
/*   ioctl interface for euslisp
/*   1988Mar23
/*   Copyright(c)1988 Toshihiro MATSUI, Electrotechnical Laboratory
/****************************************************************/
static char *rcsid="@(#)$Id$";
#include <ctype.h>
#include <sys/termios.h>
#ifndef Darwin
#include <termio.h>
#endif
/*  #include <sgtty.h>  */

#undef MAX
#undef MIN
#undef VMIN
#undef VMAX
#include "eus.h"

extern int errno;

static int getfd(x)
pointer x;
{ if (isint(x)) return(intval(x));
  else if (isflt(x)) error(E_NOINT);
  else if (pisiostream(x)) x=x->c.iostream.in;
  else if (!pisfilestream(x)) error(E_STREAM);
  return(intval(x->c.fstream.fd));}

static pointer getbuf(n,x,bufsize)
int n,bufsize;
pointer x;
{ if (n<=1) x=makebuffer(bufsize);
  else if (!isstring(x)) error(E_NOSTRING);
  else if (strlength(x)<bufsize) error(E_VECINDEX);
  return(x);}

static pointer ioctl_struct(n,argv,ctlcode,bufsize)
int n,bufsize;
unsigned long  ctlcode;
pointer argv[];
{ int fd,stat;
  pointer buf;
  if (n==0 || n>2) error(E_MISMATCHARG);
  fd=getfd(argv[0]);
  buf=getbuf(n,argv[1],bufsize);
  stat=ioctl(fd,ctlcode,buf->c.str.chars);
  if (stat<0) return(makeint( (-errno)));
  else return(buf);}

static pointer ioctl_int(n,argv,ctlcode)
int n;
unsigned long  ctlcode;
pointer argv[];
{ int fd,stat,intarg;
  pointer buf;
  ckarg(2);
  fd=getfd(argv[0]);
  intarg=ckintval(argv[1]);
  stat=ioctl(fd,ctlcode, &intarg);
  if (stat<0) return(makeint(-errno));
  else return(makeint(intarg));}

/********************************  obsolete interfaces

pointer IOCTL_TIOCGETP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TIOCGETP,sizeof(struct sgttyb)));}

pointer IOCTL_TIOCSETP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(2);
  return(ioctl_struct(n,argv,TIOCSETP,sizeof(struct sgttyb)));}

pointer IOCTL_TIOCSETN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(2);
  return(ioctl_struct(n,argv,TIOCSETN,sizeof(struct sgttyb)));}

pointer IOCTL_TIOCGETD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCGETD));}

pointer IOCTL_TIOCSETD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCSETD));}

pointer IOCTL_TIOCFLUSH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCFLUSH));}

pointer IOCTL_TIOCGPGRP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCGPGRP));}

pointer IOCTL_TIOCSPGRP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCSPGRP));}

pointer IOCTL_TIOCOUTQ(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCOUTQ));}

pointer IOCTL_TIOCLBIS(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCLBIS));}

pointer IOCTL_TIOCLBIC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCLBIC));}

pointer IOCTL_TIOCLSET(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCLSET));}

pointer IOCTL_TIOCLGET(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,TIOCLGET));}


**********************************************/

/****************************************
#if !Solaris2
pointer IOCTL_FIONREAD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_int(n,argv,FIONREAD));}

pointer IOCTL_TIOCGETC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TIOCGETC,sizeof(struct tchars)));}

pointer IOCTL_TIOCSETC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(2);
  return(ioctl_struct(n,argv,TIOCSETC,sizeof(struct tchars)));}
#endif
********************************************/


#if !Darwin
#if sun3 || sun4 || Linux || alpha || IRIX || Solaris2

pointer IOCTL_TCGETS(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCGETS,sizeof(struct termios)));}

pointer IOCTL_TCSETS(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCSETS,sizeof(struct termios)));}

pointer IOCTL_TCSETSW(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCSETSW,sizeof(struct termios)));}

pointer IOCTL_TCSETSF(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCSETSF,sizeof(struct termios)));}
#endif

pointer IOCTL_TCGETA(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCGETA,sizeof(struct termio)));}

pointer IOCTL_TCSETA(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCSETA,sizeof(struct termio)));}

pointer IOCTL_TCSETAF(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCSETAF,sizeof(struct termio)));}

pointer IOCTL_TCSETAW(n,argv)
int n;
pointer argv[];
{ return(ioctl_struct(n,argv,TCSETAW,sizeof(struct termio)));}
#endif

pointer TCGETATTR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stat;
  pointer buf;
  ckarg2(1,2);
  buf=getbuf(n,argv[1],sizeof(struct termios));
  stat=tcgetattr(getfd(argv[0]),(struct termios *)buf->c.str.chars);
  if (stat<0) return(makeint(-errno)); else return(buf);}

pointer TCSETATTR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stat,optact=0;
  pointer buf;
  ckarg2(1,3);
  buf=getbuf(n,argv[2],sizeof(struct termios));
  if (n>=2) optact=ckintval(argv[1]);
  stat=tcsetattr(getfd(argv[0]),optact,(struct termios *)buf->c.str.chars);
  if (stat<0) return(makeint(-errno)); else return(buf);}

void eusioctl(ctx,mod)
register context *ctx;
register pointer mod;
{
/*********************** obsolete
  defunpkg(ctx,"TIOCGETP",mod,IOCTL_TIOCGETP,unixpkg);
  defunpkg(ctx,"TIOCSETP",mod,IOCTL_TIOCSETP,unixpkg);
  defunpkg(ctx,"TIOCSETN",mod,IOCTL_TIOCSETN,unixpkg);
  defunpkg(ctx,"TIOCGETD",mod,IOCTL_TIOCGETD,unixpkg);
  defunpkg(ctx,"TIOCFLUSH",mod,IOCTL_TIOCFLUSH,unixpkg);
  defunpkg(ctx,"TIOCGPGRP",mod,IOCTL_TIOCGPGRP,unixpkg);
  defunpkg(ctx,"TIOCSPGRP",mod,IOCTL_TIOCSPGRP,unixpkg);
  defunpkg(ctx,"TIOCOUTQ",mod,IOCTL_TIOCOUTQ,unixpkg);
  defunpkg(ctx,"TIOCLBIS",mod,IOCTL_TIOCLBIS,unixpkg);
  defunpkg(ctx,"TIOCLBIC",mod,IOCTL_TIOCLBIC,unixpkg);
  defunpkg(ctx,"TIOCLSET",mod,IOCTL_TIOCLSET,unixpkg);
  defunpkg(ctx,"TIOCLGET",mod,IOCTL_TIOCLGET,unixpkg);
*************************************/

/*********************************** obsolete
#if !Solaris2
  defunpkg(ctx,"FIONREAD",mod,IOCTL_FIONREAD,unixpkg);
  defunpkg(ctx,"TIOCGETC",mod,IOCTL_TIOCGETC,unixpkg);
  defunpkg(ctx,"TIOCSETC",mod,IOCTL_TIOCSETC,unixpkg);
#endif
*********************************************/

#if !Darwin
#if sun3 || sun4 || Linux || alpha || IRIX || Solaris2
  defunpkg(ctx,"TCGETS",mod,IOCTL_TCGETS,unixpkg);
  defunpkg(ctx,"TCSETS",mod,IOCTL_TCSETS,unixpkg);
  defunpkg(ctx,"TCSETSW",mod,IOCTL_TCSETSW,unixpkg);
  defunpkg(ctx,"TCSETSF",mod,IOCTL_TCSETSF,unixpkg);
#endif
  defunpkg(ctx,"TCGETA",mod,IOCTL_TCGETA,unixpkg);
  defunpkg(ctx,"TCSETA",mod,IOCTL_TCSETA,unixpkg);
  defunpkg(ctx,"TCSETAW",mod,IOCTL_TCSETAW,unixpkg);
  defunpkg(ctx,"TCSETAF",mod,IOCTL_TCSETAF,unixpkg);
#endif
  defunpkg(ctx,"TCGETATTR",mod,TCGETATTR,unixpkg);
  defunpkg(ctx,"TCSETATTR",mod,TCSETATTR,unixpkg);
/*  printf("eusioctl: TCGETS=%x\n", TCGETS); */
  }
