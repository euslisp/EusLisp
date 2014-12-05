/****************************************************************/
/* unixcall.c
/*	1986-Jul-6	original for Ustation
/*	1986-Dec	process id's, file changes, syserrlist
/*	1987-Feb	dup,isatty
/*	1987-Apr	getwd,stat,time
/*	1988-Jan,Feb	socket, select
/*	1988-Dec	ioctl		
/*	1990-Mar	VxWorks
/*	Copyright(c) 1988 MATSUI Toshihiro, Electrotechnical Laboratory.
/****************************************************************/

static char *rcsid="@(#)$Id$";

/* SunOS's gettimeofday used to accept only one argument.
#ifdef Solaris2
#define _SVID_GETTOD
#endif
*/

#include "eus.h"

#if vxworks
#define NSIG NUM_SIGNALS
#define SIG_DFL 0
#include <sigLib.h>
#include <socket.h>
#include <in.h>
#else
#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/mman.h>
#include <string.h>
#endif

/*SONY/news doesn't have message queu ipc facilities*/
#if !vxworks
#include <sys/ipc.h>
#include <sys/msg.h>
#endif

#if SunOS4_1 || (mips && !IRIX && !IRIX6)
/* Sun likes to change ioccom constants frequently. */
#define IOC_VOID   _IOC_VOID
#define IOC_IN     _IOC_IN
#define IOC_OUT    _IOC_OUT
#define IOC_INOUT  _IOC_INOUT
#endif

#if Linux
#define IOC_VOID 0
#endif

#if Solaris2 || Linux || alpha
#include <errno.h>
#include <dirent.h>
#else
extern int errno;
#endif

#if Linux
#define IOC_VOID 0
#endif


#if alpha
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#endif

#if system5 || Linux
#include <sys/utsname.h>
#endif

extern int sys_nerr;
/*extern char *sys_errlist[];*/
extern char *tzname[2];
extern time_t timezone, altzone;	/*long*/
extern int daylight;

extern pointer eussigvec[NSIG];

extern int coerceintval(pointer);


/***************** times and status *****************/

#if !vxworks
pointer PTIMES(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ struct tms buffer;
  register pointer t;
  long et;
  ckarg(0);
  et=times(&buffer);
  t=cons(ctx,makeint(buffer.tms_cstime),NIL);
  t=cons(ctx,makeint(buffer.tms_cutime),t);
  t=cons(ctx,makeint(buffer.tms_stime),t);
  t=cons(ctx,makeint(buffer.tms_utime),t);
  t=cons(ctx,mkbigint(et),t);
  return(t);}

pointer RUNTIME(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ struct tms buffer;
  ckarg(0);
  times(&buffer);
  return(makeint(buffer.tms_utime+buffer.tms_stime));}

pointer LOCALTIME(ctx,n,argv)
register context *ctx;
pointer argv[];
{ long clock;
  struct tm *tms;
  pointer timevec;
  pointer *tv;
  pointer tz0, tz1, tz;

  if (n==1) clock=coerceintval(argv[0]);
  else clock=time(0);
  tms=localtime((time_t *)&clock);
  timevec=makevector(C_VECTOR,10);
  vpush(timevec);
  tz0=makestring(tzname[0],strlen(tzname[0]));
  vpush(tz0);
  tz1=makestring(tzname[1],strlen(tzname[1]));
  vpush(tz1);
  tz=cons(ctx, tz1, NIL);
  tz=cons(ctx, tz0, tz);
  tv=timevec->c.vec.v;
  tv[0]=makeint(tms->tm_sec); 
  tv[1]=makeint(tms->tm_min);
  tv[2]=makeint(tms->tm_hour);
  tv[3]=makeint(tms->tm_mday);
  tv[4]=makeint(tms->tm_mon); 
  tv[5]=makeint(tms->tm_year);
  tv[6]=makeint(tms->tm_wday);
  tv[7]=makeint(tms->tm_yday);
  tv[8]=(tms->tm_isdst>0)?T:NIL;
  tv[9]=tz;
  vpop(); vpop(); vpop();
  return(timevec);}

pointer ASCTIME(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register char *at;
  struct tm tms1, *tms;
  pointer a=argv[0];
  int i;

  ckarg(1);
  if (isintvector(argv[0])) tms=(struct tm *)a->c.ivec.iv;
  else if (isvector(a)) {
    tms1.tm_sec=ckintval(a->c.vec.v[0]);
    tms1.tm_min=ckintval(a->c.vec.v[1]);
    tms1.tm_hour=ckintval(a->c.vec.v[2]);
    tms1.tm_mday=ckintval(a->c.vec.v[3]);
    tms1.tm_mon=ckintval(a->c.vec.v[4]);
    tms1.tm_year=ckintval(a->c.vec.v[5]);
    tms1.tm_wday=ckintval(a->c.vec.v[6]);
    /* tms1.tm_yday=ckintval(a->c.vec.v[7]); */
    tms1.tm_isdst=(a->c.vec.v[8]==NIL)?0:1;
    tms= &tms1; }
  else error(E_NOINTVECTOR);
  at=asctime(tms);
  return(makestring(at,strlen(at)));}

#if !Solaris2
pointer GETRUSAGE(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ register int who,i;
  long rusage[18];
  float utime,stime;
  register pointer r=NIL;
  numunion nu;

  ckarg(1); who=ckintval(argv[0]);
  getrusage(who,rusage);
  utime=rusage[0]+rusage[1]*1.0e-6;
  stime=rusage[2]+rusage[3]*1.0e-6;
  for (i=17; i>=4; i--) r=cons(ctx,makeint(rusage[i]),r);
  r=cons(ctx,makeflt(stime),r); r=cons(ctx,makeflt(utime),r);
  /*(utime stime maxrss ixrss idrss isrss page-reclaims page-faults swap
	inblock outblock msgsnd msgrcv nsignals
	voluntary-context-switch involuntary-context-switch) */
  return(r);}

pointer GETPAGESIZE(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ ckarg(0);
  return(makeint(getpagesize())); }

#endif

pointer GETTIMEOFDAY(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ struct timeval /*{long tv_sec, tv_usec;}*/ tm;
  float ftime;
  pointer p;

  /* (sec usec timezone daylight) */
  /* timezone is seconds west to the GMT */
  gettimeofday(&tm, 0);
  p=cons(ctx, makeint(daylight), NIL);
  p=cons(ctx, makeint(timezone),p);
  p=cons(ctx, mkbigint(tm.tv_usec), p);
  p=cons(ctx, mkbigint(tm.tv_sec), p);
  return(p);}

pointer GETITIMER(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int stat;
  struct itimerval tmval;
  float interval,value;
  numunion nu;
  ckarg(1);
  stat=getitimer(ckintval(argv[0]), &tmval);
  if (stat<0) return(NIL);
  interval=tmval.it_interval.tv_sec + ( tmval.it_interval.tv_usec*1.0E-6);
  value=tmval.it_value.tv_sec + (tmval.it_value.tv_usec*1.0E-6);
  return(cons(ctx,makeflt(value),
	 cons(ctx,makeflt(interval),NIL)));}

pointer SETITIMER(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int stat;
  pointer result=NIL;
  struct itimerval tmval,oldtmval;
  float interval,value;
  numunion nu;

  ckarg(3);
  value=ckfltval(argv[1]); interval=ckfltval(argv[2]);
  tmval.it_value.tv_sec=value;
  tmval.it_value.tv_usec=(value-tmval.it_value.tv_sec)*1.0E6;
  tmval.it_interval.tv_sec=interval;
  tmval.it_interval.tv_usec=(interval-tmval.it_interval.tv_sec)*1.0E6;
  stat=setitimer(ckintval(argv[0]), &tmval, &oldtmval);
  if (stat<0) return(result);
  interval=oldtmval.it_interval.tv_sec + (oldtmval.it_interval.tv_usec*1.0E-6);
  value=oldtmval.it_value.tv_sec + (oldtmval.it_value.tv_usec*1.0E-6);
  return(cons(ctx,makeflt(interval),
	 cons(ctx,makeflt(value),result)));}
#endif /* ! vxworks */

/****************************************************************/
/* signal handling
/****************************************************************/

#ifdef SIGADDSET
#undef SIGADDSET
#endif
#ifdef SIGDELSET
#undef SIGDELSET
#endif

pointer SIGADDSET(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int signum;
  sigset_t *set;
  ckarg(2);
  signum=ckintval(argv[1]);
  if (isvector(argv[0]) &&
	((elmtypeof(argv[0])==ELM_INT) || (elmtypeof(argv[0])==ELM_BIT))) {
    set=(sigset_t *)argv[0]->c.ivec.iv;
    sigaddset(set, signum);
    return(argv[0]);}
  else error(E_USER,(pointer)"integer/bit vector expected for sigaddset");
  }

pointer SIGDELSET(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int signum;
  sigset_t *set;
  ckarg(2);
  signum=ckintval(argv[1]);
  if (isvector(argv[0]) &&
	((elmtypeof(argv[0])==ELM_INT) || (elmtypeof(argv[0])==ELM_BIT))) {
    set=(sigset_t *)argv[0]->c.ivec.iv;
    sigdelset(set, signum);
    return(argv[0]);}
  else error(E_USER,(pointer)"integer/bit vector expected for sigaddset");
  }

pointer SIGPROCMASK(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ sigset_t *set, *oset;
  int how, stat;
  ckarg2(2,3);
  how=ckintval(argv[0]);
  if (isvector(argv[1]) &&
	((elmtypeof(argv[1])==ELM_INT) || (elmtypeof(argv[1])==ELM_BIT))) {
    set=(sigset_t *)argv[1]->c.ivec.iv;
    if (isvector(argv[2]) &&
	((elmtypeof(argv[2])==ELM_INT) || (elmtypeof(argv[2])==ELM_BIT))) 
      oset=(sigset_t *)argv[2]->c.ivec.iv;
    else oset=(sigset_t *)0;
    stat=sigprocmask(how, set, oset);
    if (stat==0) return(T); else return(makeint(-errno));
    }
  else error(E_USER,(pointer)"integer/bit vector expected for sigprocmask");
  }

pointer KILL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  return(makeint(kill(ckintval(argv[0]),ckintval(argv[1]))));}

#if Solaris2 || Linux || IRIX || IRIX6
pointer SIGNAL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int s,i;eusinteger_t f;
  struct sigaction sv;
  register pointer a=argv[1],oldval;
  extern void eusint();	

  ckarg2(1,3);
  s=min(ckintval(argv[0]),NSIG-1);
  oldval=eussigvec[s];
  if (n==1) return(oldval);
  if (isint(a)) { f=max(1,intval(a)); eussigvec[s]=NIL;}
  else { f=(eusinteger_t)eusint; eussigvec[s]=a;}
  sv.sa_handler= (void (*)())f;
#if Linux 

#if LIB6
  for (i=0; i< _SIGSET_NWORDS; i++)   sv.sa_mask.__val[i]=0; 
#else
  /* old type sigmask */
  sv.sa_mask=0;
#endif 
/*LIB6*/

#elif (IRIX || IRIX6) && !IRIX6_2
  for (i=0; i<4; i++)   sv.sa_mask.sigbits[i]=0;
#else
  for (i=0; i<4; i++)   sv.sa_mask.__sigbits[i]=0;
#endif

  if (n==3) sv.sa_flags= ckintval(argv[2]);
  else sv.sa_flags=0;
  /* printf("signal %d flag=%d\n", s, sv.sa_flags); */
  s=sigaction(s,&sv,0);
  if (s== -1) return(makeint(-errno)); else return(oldval);
  }

#else
pointer SIGNAL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int s;eusinteger_t f;
  struct sigvec sv;
  register pointer a=argv[1],oldval;
  extern void eusint();

  ckarg2(1,3);
  s=min(ckintval(argv[0]),NSIG-1);
  oldval=eussigvec[s];
  if (n==1) return(oldval);
  if (isint(a)) { f=max(1,intval(a)); eussigvec[s]=NIL;}
  else { f=(eusinteger_t)eusint; eussigvec[s]=a;}/* ???? */
  sv.sv_handler=(void (*)())f;
  sv.sv_mask=0;	/*sigmask(s)???;*/
/*news doesn't have system5 compatible signal handling option*/
#if sun3 || sun4  || mips || alpha
  if (n==3) sv.sv_flags=ckintval(argv[2]);
  else sv.sv_flags=0;
#endif
  s=sigvec(s,&sv,0);
  if (s== -1) return(makeint(-errno)); else return(oldval);
  }

#endif

#if !vxworks

pointer WAIT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int completion=0, stat;
  stat = wait(&completion);
  return(cons(ctx,makeint(stat),
	 cons(ctx,makeint(completion),NIL)));}

pointer ALARM(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ ckarg(1);
  return(makeint(alarm(ckintval(argv[0]))));}


#if sun3 || sun4 || news || sanyo  || alpha
#if !Solaris2
pointer UALARM(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ ckarg(2);
  return(makeint(ualarm(ckintval(argv[0]), ckintval(argv[1]))));}
#endif
#endif

#endif /*!vxworks*/

/**********************************************/
/* process, user, and group identification 
/**********************************************/

pointer GETPID(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;	/* unused argument */
{ ckarg(0);
  return(makeint(getpid()));}

#if !vxworks
pointer GETPPID(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(0);
  return(makeint(getppid()));}

pointer GETPGRP(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
#if system5 | Linux
{ ckarg(0);
  return(makeint(getpgrp()));}
#else
{ int pid;
  if (n==1) pid=ckintval(argv[0]);
  else pid=getpid();
  return(makeint(getpgrp(pid)));}
#endif

pointer SETPGRP(context *ctx, int n, pointer *argv)
#if system5 | Linux
{ ckarg(0);
  return(makeint(setpgrp()));}
#else
{ int pid;
  ckarg(2);
  return(makeint(setpgrp(ckintval(argv[0]),ckintval(argv[1]))));}
#endif

pointer GETUID(context *ctx, int n, pointer *argv)
{ ckarg(0);
  return(makeint(getuid()));}

pointer GETEUID(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(0);
  return(makeint(geteuid()));}

pointer GETGID(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(0);
  return(makeint(getgid()));}

pointer GETEGID(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(0);
  return(makeint(getegid()));}

pointer SETUID(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(1);
  n=setuid(ckintval(argv[0]));
  if (n<0) return(makeint(errno)); else return(T);}

pointer SETGID(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(1);
  n=setgid(ckintval(argv[0]));
  if (n<0) return(makeint(errno)); else return(T);}

#endif /*!vxworks*/

#if system5 || Linux
pointer UNAME(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ struct utsname u;
  pointer s;
  ckarg(0);
  uname(&u);
  vpush(makestring(u.sysname,strlen(u.sysname)));
  vpush(makestring(u.nodename,strlen(u.nodename)));
  vpush(makestring(u.release,strlen(u.release)));
  vpush(makestring(u.version,strlen(u.version)));
  vpush(makestring(u.machine,strlen(u.machine)));
  s=stacknlist(ctx,5);
  return(s);}
#endif

/****************************************************************/
/* process creation and deletion 
/****************************************************************/
#if !vxworks
pointer FORK(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(0);
  return(makeint(fork()));
  }

#if Solaris2
pointer FORK1(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(0);
  return(makeint(fork1()));
  }
#endif

#if sun3 || sun4 || vax || news || sanyo || (mips && !IRIX && !IRIX6) || i386 || alpha
pointer VFORK(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(0);
  return(makeint(vfork()));} 
#endif

pointer EXEC(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ byte *exeargv[512];
  int i=0,stat;
  if (n>512) error(E_MISMATCHARG);
  while (i<n) {
    exeargv[i]=Getstring(argv[i])->c.str.chars;
    i++;}
  exeargv[i]=0;
  stat=execvp(exeargv[0],(char **)exeargv);
  return(makeint(-errno));}	  

#if !Solaris2
static pointer SETPRIORITY(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
/* (SETPRIORITY which who priority)
	which 0:process,  1:process-group,  2:user
	who   0:self, others pid, pgrp-id user-id */ 
{ ckarg(3);
  return(makeint(setpriority(ckintval(argv[0]),
			     ckintval(argv[1]),
			     ckintval(argv[2]))));}

static pointer GETPRIORITY(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
/* (GETPRIORITY which who) */
{ ckarg(2);
  return(makeint(getpriority(ckintval(argv[0]), ckintval(argv[1]))));}
#endif	/*!Solaris2*/
#endif	/*!vxworks*/

pointer EXIT(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer exithook=speval(QEXITHOOK);
/*
  Exit function can not finish threads which create in Euslisp 
on SunOS 4.1. So we use thr_exit function on SunOS 4.1.
*/
#if SunOS4_1 /* changed by H.Nakagaki at 28-Jun-1995 */
  if (n==0) thr_exit(0);
  else thr_exit(ckintval(argv[0]));
#else
    if (exithook != NIL) {
      ufuncall(ctx,exithook,exithook,(pointer)(ctx->vsp),0,0);}
  if (n==0) exit(0);
  else exit(ckintval(argv[0]));
#endif
}


/****************************************************************/
/* unix raw I/O and file systems
/****************************************************************/

pointer UNIXREAD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
/* (unix:read stream [length]) */
/* (unix:read fd buffer [length [offset]]) */
#if (WORD_SIZE == 64)
{ register int fd,offset=0;
  register long int size;
#else
{ register int fd,size,offset=0;
#endif
  register pointer strm,buf,count;
  byte *bufp;
  
  ckarg2(1,4);
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.in;
  if (isfilestream(strm)) {
    if (strm->c.stream.direction!=K_IN) error(E_IODIRECTION);
    if (isint(strm->c.fstream.fname)) error(E_STREAM);
    buf=strm->c.fstream.buffer;
    bufp=buf->c.str.chars;
    fd=intval(strm->c.fstream.fd);
    if (n==2) size=min(strlength(buf),ckintval(argv[1]));
    else size=strlength(buf);}
  else if (isint(strm)) {
    fd=intval(strm);
    buf=argv[1];
    if (isvector(buf) && (elmtypeof(buf)==ELM_FOREIGN)) 
      bufp=buf->c.foreign.chars;
    else if (isstring(buf)) bufp=buf->c.str.chars;
    else error(E_NOSTRING);
    if (n>=3) size=min(strlength(buf),ckintval(argv[2]));
    else size=strlength(buf);
    if (n==4) offset=ckintval(argv[3]);}
  else error(E_STREAM);
  size=read(fd, &bufp[offset],size);
  count=makeint(size);
  if (isstream(strm)) {
    strm->c.stream.count=0; strm->c.stream.tail=count;}
  if (size<0) return(makeint(-errno));
  else return(count);}

pointer UNIXWRITE(ctx,n,argv)
register context *ctx;
register int n;
pointer *argv;
/* (unix:write fd string [count]) 
   (unix:write stream string [count]) */
{ register pointer strm,buf;
  register int size,fd;
  byte *bufp;
  ckarg2(2,3);
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)) {
    if (strm->c.stream.direction!=K_OUT) error(E_IODIRECTION);
    if (isint(strm->c.fstream.fname)) error(E_STREAM);
    fd=intval(strm->c.fstream.fd);}
  else if (isint(strm)) fd=intval(strm);
  else error(E_STREAM);
  buf=argv[1];
  if (isvector(buf) && (elmtypeof(buf)==ELM_FOREIGN)) 
    bufp=buf->c.foreign.chars;
  else if (isstring(buf)) bufp=buf->c.str.chars;
  else error(E_NOSTRING);
  size=strlength(buf);
  if (n==3) size=min(size,ckintval(argv[2])); 
  size=write(fd,bufp,size);
  return(makeint(size));}


pointer UNIXCLOSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(1);
  if (close(ckintval(argv[0]))==0) return(T); else return(makeint(errno));}


pointer LOCKF(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  int fd,func,size,result;
  ckarg2(2,3);
  if (isiostream(a)) a=a->c.iostream.out;
  if (isfilestream(a)) fd=intval(a->c.fstream.fd);
  else if (isint(argv[0])) fd=intval(argv[0]);
  else error(E_STREAM);
  func= ckintval(argv[1]);
  if (n==3) size=ckintval(argv[2]);
  else size=0;
  result=lockf(fd,func,size);
  return(makeint(result));}

pointer FCNTL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0]; int fd,result;
  ckarg(3);
  if (isiostream(a)) a=a->c.iostream.in;
  if (isfilestream(a)) fd=intval(a->c.fstream.fd);
  else if (isint(argv[0])) fd=intval(argv[0]);
  else error(E_STREAM);
  result=fcntl(fd,ckintval(argv[1]),ckintval(argv[2]));
  return(makeint(result));}


pointer IOCTL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer strm;
  eusinteger_t ctlarg;
  int request;
  int fd;
  ckarg(3);
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)) {
    fd=intval(strm->c.fstream.fd);
    if (isint(strm->c.fstream.fname)) error(E_STREAM);}
  else fd=ckintval(argv[0]);
  if (isint(argv[1]))  request=ckintval(argv[1]);
  else if (isflt(argv[1])) error(E_NOINT);
  else request=argv[1]->c.ivec.iv[0];
  if (isstring(argv[2])) ctlarg=(eusinteger_t)(argv[2]->c.str.chars);/* ???? */
  else ctlarg=ckintval(argv[2]);
  return(makeint(ioctl(fd,request,ctlarg)));
  }


#if !vxworks && !Solaris2
int bytesize(p)
pointer p;
{ register int s=vecsize(p);
  switch (elmtypeof(p)) {
    case ELM_BIT: return((s+7)/8);
    case ELM_BYTE: case ELM_CHAR: case ELM_FOREIGN: return(s);
    case ELM_FLOAT: return(s*sizeof(float));
    case ELM_INT: return(s*sizeof(int));
    default: return(s*sizeof(pointer));}}

#if Linux_ppc
#define IOC_IN	 _IOC_READ
#define IOC_OUT  _IOC_WRITE
#define IOC_INOUT  (IOC_IN | IOC_OUT)
#endif


pointer IOCTL_(ctx,n,argv)
register context *ctx;
/* (UNIX:IOCTL_ stream command1 command2) */
/* equivalent to C's ioctl(dev, _IO(command1, command2), addr) */
int n;
register pointer argv[];
{ register pointer strm;
  int size=0,x,y,fd;
  eusinteger_t addr;
  ckarg(3);
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)) fd=intval(strm->c.fstream.fd);
  else fd=ckintval(strm);
  if (isint(strm->c.fstream.fname)) error(E_STREAM);
  x=ckintval(argv[1]); y=ckintval(argv[2]);
#if alpha || Linux_ppc
  if (ioctl(fd,_IO(x, y), addr))
#else
  if (ioctl(fd,IOC_VOID | (size<<16) | (x<<8) | y, addr))
#endif
     return(makeint(-errno));
  else return(T);  }

pointer IOCTL_R(ctx,n,argv)
register context *ctx;
/* (UNIX:IOCTL_R stream x y buffer [size]) */
/* equivalent to C's ioctl(dev, _IORN(size, x, y), addr) */
int n;
register pointer argv[];
{ register pointer strm;
  int size,x,y,fd;
  eusinteger_t addr;
  ckarg2(4,5);
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)) fd=intval(strm->c.fstream.fd);
  else fd=ckintval(strm);
  if (isint(strm->c.fstream.fname)) error(E_STREAM);
  x=ckintval(argv[1]); y=ckintval(argv[2]);
  if (isstring(argv[3]) || isintvector(argv[3]))
	addr=(eusinteger_t)(argv[3]->c.str.chars);/* ???? */
  else error(E_NOSTRING);
  if (n==5) size=ckintval(argv[4]);
  else size=bytesize(argv[3]);
#if alpha
  if (ioctl(fd,_IOC(IOC_OUT, x, y, size), addr))
#else
  if (ioctl(fd,IOC_OUT | (size<<16) | (x<<8) | y, addr))
#endif
    return(makeint(-errno));
  else return(T);  }

pointer IOCTL_W(ctx,n,argv)
register context *ctx;
/* (UNIX:IOCTL_W stream x y buffer [size]) */
/* equivalent to C's ioctl(dev, _IOWN(size, x, y), addr) */
int n;
register pointer argv[];
{ register pointer strm;
  int size,x,y,fd;
  eusinteger_t addr;
  ckarg2(4,5);
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)) fd=intval(strm->c.fstream.fd);
  else fd=ckintval(strm);
  if (isint(strm->c.fstream.fname)) error(E_STREAM);
  x=ckintval(argv[1]); y=ckintval(argv[2]);
  if (isstring(argv[3]) || isintvector(argv[3]))
	addr=(eusinteger_t)(argv[3]->c.str.chars);/* ???? */
  else error(E_NOSTRING);
  if (n==5) size=ckintval(argv[4]);
  else size=bytesize(argv[3]);
#if alpha || Linux_ppc
  if (ioctl(fd,_IOC(IOC_IN, x, y, size), addr))
#else
  if (ioctl(fd,IOC_IN | (size<<16) | (x<<8) | y, addr))
#endif
    return(makeint(-errno));
  else return(T);  }

pointer IOCTL_WR(ctx,n,argv)
register context *ctx;
/* (UNIX:IOCTL_WR stream x y buffer [size]) */
/* equivalent to C's ioctl(dev, _IOWRN(size, x, y), addr) */
int n;
register pointer argv[];
{ register pointer strm=argv[0];
  int size,x,y,fd;
  eusinteger_t addr;

  ckarg2(4,5);
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)) fd=intval(strm->c.fstream.fd);
  else fd=ckintval(strm);
  if (isint(strm->c.fstream.fname)) error(E_STREAM);
  x=ckintval(argv[1]); y=ckintval(argv[2]);
  if (isstring(argv[3]) || isintvector(argv[3]))
	addr=(eusinteger_t)(argv[3]->c.str.chars);
  else error(E_NOSTRING);
  if (n==5) size=ckintval(argv[4]);
  else size=bytesize(argv[3]);
#if alpha || Linux_ppc
  if (ioctl(fd,_IOC(IOC_INOUT, x, y, size), addr))
#else
  if (ioctl(fd,IOC_INOUT | (size <<16) | (x<<8) | y, addr))
#endif
    return(makeint(-errno)) ;
  else return(T);  }

#endif /*vxworks*/

/* DUP and DUP2 work only for numeric fd, not for stream obj.*/
#if !vxworks

pointer DUP(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ int newfd,oldfd;
  ckarg(1);
  oldfd=ckintval(argv[0]);
  newfd=dup(oldfd);
  return(makeint(newfd));}

pointer DUP2(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ int newfd,oldfd,stat;
  ckarg(2);
  newfd=ckintval(argv[0]);
  oldfd=ckintval(argv[1]);
  stat=dup2(newfd,oldfd);
  return(makeint(stat));}

pointer MKNOD(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ int stat;
  ckarg(2);
  stat=mknod((char *)Getstring(argv[0])->c.str.chars,ckintval(argv[1]),0);
  if (stat<0) return(makeint(-errno));
  else return(T);}

pointer MKDIR(ctx, n, argv)
register context *ctx;
int n;
pointer *argv;
{ int stat, mode;
  ckarg2(1,2);
  if (n==2) mode=ckintval(argv[1]); else mode=0775;
  stat=mkdir((char *)Getstring(argv[0])->c.str.chars,mode);
  if (stat<0) return(makeint(-errno));
  else return(T);}

pointer LINK(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stat;
  ckarg(2);
  stat=link(Getstring(argv[0])->c.str.chars,Getstring(argv[1])->c.str.chars);
  if (stat<0) return(makeint(-errno)); else return(T);}

pointer UNLINK(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer s;
  int stat;
  ckarg(1);
  s=Getstring(argv[0]);
  stat=unlink(s->c.str.chars);
  if (stat<0) return(makeint(-errno));
  else return(T);}

pointer RMDIR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer s;
  int stat;
  ckarg(1);
  s=Getstring(argv[0]);
  stat=rmdir(s->c.str.chars);
  if (stat<0) return(makeint(-errno));
  else return(T);}

pointer RENAME(ctx,n,argv)	/*(rename from to)*/
register context *ctx;
int n;
register pointer argv[];
{ byte *from, *to;
  int stat;
  ckarg(2);
  from =(byte *)get_string(argv[0]);
  to =(byte *)get_string(argv[1]);
  stat=rename((char *)from,(char *) to);
  if (stat<0) return(makeint(-errno));
  else return(T);}

pointer ACCESS(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer path;
  int mode,stat;
  ckarg2(1,2);
  path=Getstring(argv[0]);
  if (n==2) mode=ckintval(argv[1]); else mode=0;
  stat=access(path->c.str.chars,mode);
  if (stat==0) return(T); else return(makeint(-errno));}

/*
pointer FLOCK(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int fd=ckintval(argv[0]), op=ckintval(argv[1]), stat;
  ckarg(2);
  stat=flock(fd,op);
  if (stat==0) return(T); else return(makeint(-errno));}
*/

pointer STAT(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer a;
  struct stat s;
  ckarg(1);
  if (stat((char *)Getstring(argv[0])->c.str.chars, &s)<0) return(makeint(-errno));
  a=cons(ctx,mkbigint(s.st_ctime),NIL);
  a=cons(ctx,mkbigint(s.st_mtime),a);
  a=cons(ctx,mkbigint(s.st_atime),a);
  a=cons(ctx,makeint(s.st_size),a);
  a=cons(ctx,makeint(s.st_gid),a);
  a=cons(ctx,makeint(s.st_uid),a);
  a=cons(ctx,makeint(s.st_nlink),a);
  a=cons(ctx,makeint(s.st_rdev),a);
  a=cons(ctx,makeint(s.st_dev),a);
  a=cons(ctx,makeint(s.st_ino),a);
  a=cons(ctx,makeint(s.st_mode),a);
  return(a);}
#endif /* !vxworks*/

#if Solaris2 || linux || alpha
/*
  Usage: (unix::directory "directory_name")
  Return: a reverse list of file names in "directory_name" dir.
*/

pointer DIRECTORY(ctx, n, argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a;
  register char *str;
  byte *s;
  DIR *dirp;
  struct dirent *direntp;
  int flag=0;

  ckarg2(0,1);
  if (n==1)  s=get_string(argv[0]); else s=(byte *)".";
  dirp = opendir((char *)s);
  while ( (direntp = readdir( dirp )) != NULL ){
     str=direntp->d_name; 
     if(flag) a=cons(ctx,makestring(str,strlen(str)),a);
     else { a=cons(ctx,makestring(str,strlen(str)),NIL); flag++;}
   }
   closedir(dirp);
   return (a);
}
#else
pointer DIRECTORY(ctx, n, argv)
register context *ctx;
int n;
pointer argv[];
{
   printf("Not Implemented!");
   return (NIL);
}
#endif

pointer LSEEK(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer strm,fd;
  int whence;
  ckarg2(2,3);
  if (n==3) whence=ckintval(argv[2]); else whence=0;
  strm=argv[0];
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (isfilestream(strm)){
     fd=strm->c.fstream.fd;
     if (isint(strm->c.fstream.fname)) error(E_STREAM);}
  else fd=strm;
  if (!isint(fd)) error(E_STREAM);
  return(makeint(lseek(intval(fd),ckintval(argv[1]),whence)));  }

#if !vxworks
/*change current working directory*/
pointer CHDIR(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int stat;
  ckarg(1);
  stat=chdir(Getstring(argv[0])->c.str.chars);
  if (stat<0) return(makeint(-errno)); else return(T);}

/*change file access mode*/
pointer CHMOD(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ byte *path;
  int mode,stat;
  ckarg(2);
  path=Getstring(argv[0])->c.str.chars;
  mode=ckintval(argv[1]);
  stat=chmod((char *)path,mode);
  if (stat==0) return(T); else return(makeint(errno));}

/*change file owner*/
pointer CHOWN(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ byte *path;
  int owner,newowner,stat;
  ckarg(3);
  path=Getstring(argv[0])->c.str.chars;
  owner=ckintval(argv[1]);
  newowner=ckintval(argv[2]);
  stat=chown(path,owner,newowner);
  if (stat==0) return(T); else return(makeint(errno));}

/*create two pipes*/
pointer PIPE(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ int pfd[2],stat,size;
  register pointer instream,outstream;

  ckarg2(0,1);
  if (n==1) size=ckintval(argv[0]); else size=128;
  stat=pipe(pfd);
  if (stat<0) return(makeint(-errno));
  instream=mkfilestream(ctx,K_IN,makebuffer(size),pfd[0],NIL); /*no file named*/
  vpush(instream);
  outstream=mkfilestream(ctx,K_OUT,makebuffer(size),pfd[1],NIL);
  return((pointer)mkiostream(ctx,vpop(),outstream));
  }


/* message queu operations */
#if !news
pointer MSGGET(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int key,qid,mode;
  ckarg2(1,2);
  key=ckintval(argv[0]);
  if (n==2) mode=ckintval(argv[1]); else mode=0666;
  qid=msgget(key,IPC_CREAT | (mode & 0777));
  return(makeint(qid));}

pointer MSGRCV(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register int qid,mtype,flag,stat;
  register pointer buf,lsave;
  ckarg2(2,4);
  qid=ckintval(argv[0]);
  buf=argv[1];
  if (!isstring(buf)) error(E_NOSTRING);
  if (n>=3) mtype=ckintval(argv[2]); else mtype=0;
  if (n==4) if (argv[3]==NIL) flag=0; else flag=IPC_NOWAIT;
  else flag=0;
  lsave=buf->c.str.length;
  buf->c.str.length=(pointer)(eusinteger_t)mtype;/* ???? */
  rcv_again:
  stat=msgrcv(qid,&buf->c.str.length,intval(lsave),mtype,flag);
  if (stat<0) { breakck; goto rcv_again;}
  mtype=(int)(eusinteger_t)(buf->c.str.length);/* ???? */
  buf->c.str.length=lsave;
  if (stat<0) return(makeint(-errno));
  else return(cons(ctx,makeint(mtype),cons(ctx,makeint(stat),NIL)));}
  
pointer MSGSND(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register int qid,msize,mtype,flag,stat;
  register pointer buf,lsave;
  ckarg2(2,5);
  qid=ckintval(argv[0]);
  buf=argv[1];
  if (!isstring(buf)) error(E_NOSTRING);
  lsave=buf->c.str.length;
  if (n>=3) {
    msize=ckintval(argv[2]);
    if (msize>intval(lsave) || msize<0) error(E_ARRAYINDEX);}
  else msize=intval(lsave);
  if (n>=4) mtype=ckintval(argv[3]); else mtype=mypid;
  if (n==5) if (argv[4]==NIL) flag=0; else flag=IPC_NOWAIT;
  else flag=0;
  buf->c.str.length=(pointer)(eusinteger_t)mtype;
  stat=msgsnd(qid,(struct msgbuf *)&buf->c.str.length,msize,flag);
  buf->c.str.length=lsave;
  if (stat<0) return(makeint(-errno));
  else return(makeint(stat));}

pointer MSGCTL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int qid,cmnd,stat;
  byte *buf;
  ckarg2(2,3);
  qid=ckintval(argv[0]); cmnd=ckintval(argv[1]);
  if (n==3) buf=get_string(argv[2]);
  else buf=NULL;
  stat=msgctl(qid,cmnd,(struct msqid_ds *)buf);
  if (stat==(int)NULL) return(T); else  return(makeint(-errno));}
#endif
#endif /*!vxworks*/

/****************************************************************/
/* UNIX subroutines
/****************************************************************/

pointer SYSTEM(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int stat;
  eusinteger_t s;
/*  extern int eusint(); */
  extern void eusint();	/* ???? */

  s=(eusinteger_t)signal(SIGCHLD,SIG_DFL);/* ???? */
  if (n==0) stat=system("csh");
  else if (isstring(argv[0])) stat=system((char *)argv[0]->c.str.chars);
  else { signal(SIGCHLD,(void (*)())s); error(E_NOSTRING);}
  signal(SIGCHLD,(void (*)())s);
  return(makeint(stat));}

pointer GETWD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ char buf[256];
  ckarg(0);
#if Solaris2 || Linux
  getcwd(buf,256);
#else
  getwd(buf);
#endif
  return(makestring(buf,strlen(buf)));}

pointer GETENV(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register char *envval;
  ckarg(1);
  envval=(char *)getenv((char *)Getstring(argv[0])->c.str.chars);
  if (envval) return(makestring(envval,strlen(envval)));
  else return(NIL);}

#if sun3 || sun4 || vax || mips || i386 || alpha
pointer PUTENV(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ 
  char *b;
  pointer a=argv[0];
  ckarg(1);
  if (!isstring(a)) error(E_NOSTRING);
  b= (char *)malloc(vecsize(a)+1);
  strcpy(b, (char *)a->c.str.chars);
  putenv(b);
  return(makeint((eusinteger_t)b));}
#endif

pointer ENVIRON(context *ctx, int n, pointer argv[])
{ extern char **environ;
  char  *b;
  int  count=0;
  ckarg(0);
  while (b=environ[count++]) {
    vpush(makestring(b, strlen(b)));}
  return(stacknlist(ctx, count-1)); }

pointer SLEEP(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(1);
  sleep(ckintval(argv[0]));
  return(T);}

#if sun3 || sun4 && !Solaris2 || Linux || alpha
pointer USLEEP(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(1);
  usleep(ckintval(argv[0]));
  return(T);}
#endif

pointer ERRNO(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ 
  return(makeint(errno));
  }

pointer SYSERRLIST(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ char *errstr;
  ckarg(1);
  n=ckintval(argv[0]);
  if (0<=n && n<sys_nerr) {
    errstr=strerror(n);
    /* return(makestring(sys_errlist[n],strlen(sys_errlist[n]))); */
    return(makestring(errstr, strlen(errstr))); }
  else error(E_ARRAYINDEX);}

pointer PAUSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg(0);
  return(makeint(pause()));}

pointer ISATTY(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer a;
  int fd;
  ckarg(1);
  a=argv[0];
  if (isiostream(a)) a=a->c.iostream.in;
  if (isfilestream(a)) fd=intval(a->c.fstream.fd);
  else fd=ckintval(a);
  if (isatty(fd)) return(T); else return(NIL);}


/****************************************************************/
/* functions for  I P C (interprocess communication)
/* using sockets
/*	1988-Jan	socket for internet
/*	1988-Feb	select system call
/****************************************************************/

pointer SOCKET(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int proto,s;
  ckarg2(2,3);
  if (n==3) proto=ckintval(argv[2]);
  else proto=0;
  s=socket(ckintval(argv[0]),ckintval(argv[1]),proto);
  if (s<0) return(makeint(-errno));
  else return(makeint(s)); }

pointer BIND(ctx,n,argv)	/*bind ipc socket to real path name*/
register context *ctx;
int n;
register pointer argv[];
{ int s,l;
  pointer sockname;
  struct sockaddr *sa;

  ckarg(2);
  s=ckintval(argv[0]);	/*socket id*/
  if (!isstring(argv[1])) error(E_USER,(pointer)"socket address expected");
  sa= (struct sockaddr *)(argv[1]->c.str.chars);
  if (sa->sa_family==AF_UNIX) l=strlen(sa->sa_data)+2;
  else l=sizeof(struct sockaddr_in);
  s=(int)bind(s, sa, l);
  if (s) return(makeint(-errno)); else return(makeint(0));}
  
pointer CONNECT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int s,l;
  struct sockaddr *sa;
  ckarg(2);
  s=ckintval(argv[0]);		/*socket id*/
  if (!isstring(argv[1])) error(E_USER,(pointer)"socket address expected");
  sa= (struct sockaddr *)(argv[1]->c.str.chars);
  if (sa->sa_family==AF_UNIX) l=strlen(sa->sa_data)+2;
  else l=sizeof(struct sockaddr_in);
  s=(int)connect(s, sa, l);
  breakck;
  if (s) return(makeint(-errno)); else return(makeint(0));
}

pointer LISTEN(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int backlog,stat;
  ckarg2(1,2);
  if (n==2) backlog=ckintval(argv[1]);
  else backlog=3;
  stat=listen(ckintval(argv[0]),backlog);
  if (stat<0) return(makeint(-errno)); else return(makeint(0));}

pointer ACCEPT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int ns,len,s;
  pointer sockname;
#if vxworks
  struct sockaddr sockun;
#else 
  struct sockaddr_un sockun;
#endif

  ckarg(1);
  len=sizeof(sockun);
  s=ckintval(argv[0]);
  ns=accept(s, (struct sockaddr *)&sockun, &len);
  if (ns<0) return(makeint(-errno));
  sockname=makestring((char *)&sockun,len);
  return(cons(ctx,makeint(ns),cons(ctx,sockname,NIL)));}

/* non-connected (datagram) socket communication */
/* Address must be bound to a socket at the receiver side. */
/* Sender specifies the address when it calls SENDTO. */
pointer SENDTO(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
/* unix: sendto(sock,msg,len,flags,to,tolen) */
/* eus:  (SENDTO sock addr msg [len [flags]]) */
{ int len, sock, flags, stat;
  pointer msg, addr;
  ckarg2(3,5);
  sock=ckintval(argv[0]);
  addr=(pointer)Getstring(argv[1]);
  msg=(pointer)Getstring(argv[2]);
  if (n>=4) len=ckintval(argv[3]); else len=vecsize(msg);
  if (n>=5) flags=ckintval(argv[4]); else flags=0;
  stat=sendto(sock, (char *)msg->c.str.chars, len, flags,
		(struct sockaddr *)addr->c.str.chars, vecsize(addr));
  if (stat<0) stat= -errno;
  /* returns the number of bytes actually sent*/
  return(makeint(stat));}

pointer RECVFROM(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
/* unix: recvfrom(s,buf,len,flags,from,fromlen) */
/* eus:  (RECVFROM sock [msg [from [flags]]])
         no address is required since it has already bound to
         the socket */
{ int len=2000, sock, flags, stat, addrlen;
  unsigned char buf[2000], *bufp=buf, *addrp=NULL;
  pointer msg, addr;
  ckarg2(1,4);
  sock=ckintval(argv[0]);
  if (n>=2) {
    msg=argv[1];
    if (isstring(msg))  msg=(pointer)Getstring(argv[1]); /*message buffer*/
    else msg=makebuffer(ckintval(argv[1]));
    bufp=msg->c.str.chars;
    len=vecsize(msg);}
  if (n>=3) {
    addr=Getstring(argv[2]);
    addrlen=vecsize(addr);
    addrp=addr->c.str.chars;}
  if (n>=4) flags=ckintval(argv[3]); else flags=0;
  stat=recvfrom(sock, (char *)bufp, len, flags, (struct sockaddr *)addrp, &addrlen);
  if (stat<0) return(makeint(-errno));
  /* if the result is negative, it indicates error number,
     otherwise, the actual length of the message is returned. */
  if (n<2) return(makestring((char *)bufp,stat));
  else return(makeint(stat));}

#if !Solaris2
pointer GETPEERNAME(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ char name[128];
  int namelen, stat;
  ckarg(1);
  stat=getpeername(ckintval(argv[0]), (struct sockaddr *)name, &namelen);
  if (stat<0) return(makeint(-errno));
  else return(makestring(name,namelen));}
#endif /*!Solaris2*/

#if !vxworks 

eusinteger_t *checkbitvec(pointer a, long *size)
{ if (a==NIL) { *size=0; return(0);}
  if (!isvector(a)) error(E_NOVECTOR);
  switch(elmtypeof(a)) {
  case ELM_BIT: *size=vecsize(a); return(a->c.ivec.iv);
  case ELM_INT: *size=vecsize(a) * WORD_SIZE; return(a->c.ivec.iv);
  case ELM_BYTE: case ELM_CHAR:
		*size=vecsize(a) * 8; return(a->c.ivec.iv);
  case ELM_FOREIGN: *size=vecsize(a) * 8; return((eusinteger_t *)a->c.foreign.chars);
  default: error(E_USER,(pointer)"bit-vector expected");
  }
}

pointer SELECT(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a=argv[0];
  long i, maxwidth, width,size0, size1, size2;
  fd_set *readfds, *writefds, *exceptfds;
  float timeout;
  struct timeval to;
  numunion nu;

  ckarg(4);
  readfds=(fd_set *)checkbitvec(argv[0], &size0);
  writefds=(fd_set *)checkbitvec(argv[1], &size1);
  exceptfds=(fd_set *)checkbitvec(argv[2], &size2);
  maxwidth=min(256, max(max(size0, size1), size2)); 

/*  printf("SELECT: readfds=%x\n", readfds);
  printf("SELECT: writefds=%x\n", writefds);
  printf("SELECT: exceptfds=%x\n", exceptfds); */

  /* find the highest numbered fd */
  width=0;
  for (i=0; i<maxwidth; i++) {
    if (readfds && FD_ISSET(i, readfds)) width=i;
    if (writefds && FD_ISSET(i, writefds)) width=i;
    if (exceptfds && FD_ISSET(i, exceptfds)) width=i;}
  width = width + 1;

  timeout=ckfltval(argv[3]);
  if (timeout==0.0)
    i=select(width, readfds, writefds, exceptfds,0);
  else {
    to.tv_sec=timeout;
    timeout=timeout-to.tv_sec;
    timeout=timeout*1000000;
    to.tv_usec=timeout;
    i=select(width, readfds, writefds, exceptfds,&to);}
  if (i<0) return(makeint(-errno));
  else return(makeint(i)); }

pointer SELECT_READ(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ struct timeval to;
  float timeout;
  long i, size, width, fds;
  fd_set *fdvec;
  numunion nu;

  ckarg(2);
  if (isint(argv[0])) {
    fds=intval(argv[0]);
    fdvec=(fd_set *)&fds;
    size=30;	}
  else fdvec=(fd_set *)checkbitvec(argv[0], &size);
  size=min(256,size);
  for (i=0; i<size; i++) if (FD_ISSET(i, fdvec)) width=i;
  width = width+1;
     
  timeout=ckfltval(argv[1]);
  if (timeout==0.0) n=select(width, fdvec, 0, 0, 0);
  else {
    to.tv_sec=timeout;
    timeout=timeout-to.tv_sec;
    timeout=timeout*1000000;
    to.tv_usec=timeout;
    n=select(width, fdvec, 0, 0, &to);}
  if (n<0) return(makeint(-errno));
  if (isint(argv[0])) {
    /*fds=fdvec-> __fds_bits[0];*/
    /* fds_bits should be __fds_bits on some operating systems */
    return(makeint(fds)); }
  else return(argv[0]); }

#endif /* !vxworks */


/****************************************************************/
/* physical memory allocator
/*	1988-Jul
/****************************************************************/
pointer SBRK(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ return(makeint(sbrk(ckintval(argv[0]))));}

pointer MALLOC(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ return(makeint(malloc(ckintval(argv[0]))));}

pointer FREE(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ free((void *)ckintval(argv[0]));
  return(makeint(1));}

#if sun3 || sun4 || news || alpha
pointer VALLOC(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ return(makeint(valloc(ckintval(argv[0]))));}
#endif

#if sun3 || sun4 || news || alpha || Linux

pointer MMAP(ctx,n,argv)
register context *ctx;
int n; register pointer argv[];
{ int fd;
  eusinteger_t offset,result,len;
  pointer strm;
  ckarg(6);
  strm=argv[4];
  if (isiostream(strm)) strm=strm->c.iostream.in;
  if (isfilestream(strm)) fd=intval(strm->c.fstream.fd);
  else fd=ckintval(strm);
  len=ckintval(argv[1]);
  if (isintvector(argv[5])) 
    offset=((argv[5]->c.ivec.iv[0])<<16) + argv[5]->c.ivec.iv[1];
  else offset=ckintval(argv[5]);
  result=(eusinteger_t)mmap((caddr_t)ckintval(argv[0]), len,
		ckintval(argv[2]), ckintval(argv[3]), fd, offset);
  if (result== -1) return(makeint(-errno));
  else return((pointer)make_foreign_string(result, len));}

pointer MUNMAP(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ return(makeint(munmap((caddr_t)ckintval(argv[0]),ckintval(argv[1]))));}

/*
pointer VADVISE(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ n=vadvise(ckintval(argv[0]));
  if (n==0) return(T); else return(makeint(errno));}
*/

#endif

/****************************************************************/
/* network library routines
/****************************************************************/
#if !vxworks

pointer GETHOSTNAME(ctx,n,argv)
register context *ctx;
int n; pointer argv[];
{ char buf[32]; int stat;
  stat=gethostname(buf,32);
  if (stat==0) return(makestring(buf,strlen(buf)));
  else return(makeint(errno));}

pointer GETHOSTBYNAME(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register struct hostent *hp;
  register pointer s;

  ckarg(1);
  hp=gethostbyname((char *)Getstring(argv[0])->c.str.chars);
  if (hp==NULL) return(makeint(-errno));
  s=cons(ctx,makeint(hp->h_addrtype),NIL);
  s=cons(ctx,makestring(hp->h_addr,hp->h_length),s);
  return(s);}	/*list of 32bit address and address type*/
  
pointer GETHOSTBYADDR(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ pointer addr;
  struct hostent *host;
  ckarg(1);
  addr=Getstring(argv[0]);
  host=gethostbyaddr((char *)addr->c.str.chars, vecsize(addr), 2);
  if (host==NULL) return(makeint(-errno));
  else return(makestring(host->h_name, strlen(host->h_name)));}

pointer GETNETBYNAME(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ struct netent *np;
  ckarg(1);
  np=getnetbyname((char *)Getstring(argv[0])->c.str.chars);
  if (np==NULL) return(makeint(-errno));
  return(cons(ctx,makeint(np->n_net),
	      cons(ctx,makeint(np->n_addrtype),NIL)));}
  
pointer GETPROTOBYNAME(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ struct protoent *pp;
  ckarg(1);
  pp=getprotobyname((char *)Getstring(argv[0])->c.str.chars);
  if (pp==NULL) return(makeint(-errno));
  return(makeint(pp->p_proto));}

pointer GETSERVBYNAME(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ struct servent *sp;
  pointer s;
  byte *p;
  long int port;
  
  ckarg2(1,2);
  if (n==2 && argv[1]!=NIL)  p=Getstring(argv[1])->c.str.chars;
  else p=NULL;
  sp=getservbyname((char *)Getstring(argv[0])->c.str.chars,(char *)p);
  if (sp==NULL) return(makeint(-errno));
  s=makestring(sp->s_proto,strlen(sp->s_proto));
  vpush(s);
  port = ntohs(sp->s_port);
  s=cons(ctx,makeint(port),cons(ctx,s,NIL));
  vpop();
  return(s);}

/* Append by I.Hara for IPC */
/* htons -- convert values between host and network byte order */
pointer H2NS(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ int hostshort;
  unsigned short netshort;
  ckarg(1);
  hostshort=ckintval(argv[0]);
  netshort=htons((short)hostshort);
  return(makeint(netshort));}

pointer N2HS(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ int hostshort;
  unsigned short netshort;
  ckarg(1);
  netshort=ckintval(argv[0]);
  hostshort=ntohs((short)netshort);
  return(makeint(hostshort));}

#endif




#ifdef DBM
/* ndbm --- data base 
	1988-May
	(c) T.Matsui
*/

#if sun3 || sun4

#include <ndbm.h>

pointer DBM_OPEN(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ DBM *dbm;
  ckarg(3);
  dbm=dbm_open(Getstring(argv[0])->c.str.chars,
	       ckintval(argv[1]),
	       ckintval(argv[2]));
  return(makeint(dbm));}

pointer DBM_CLOSE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  dbm_close(ckintval(argv[0]));
  return(T);}

pointer DBM_FETCH(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s;
  datum key,content;
  ckarg(2);
  s=Getstring(argv[1]);
  key.dptr=(char *)(s->c.str.chars);
  key.dsize=strlength(s);
  content=dbm_fetch(ckintval(argv[0]), key);
  if (content.dptr==NULL) return(NIL);
  return(makestring(content.dptr,content.dsize));}

pointer DBM_STORE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s;
  datum key,content;
  ckarg(4);
  s=Getstring(argv[1]);
  key.dptr=(char *)s->c.str.chars;
  key.dsize=strlength(s);
  s=Getstring(argv[2]);
  content.dptr=(char *)s->c.str.chars;
  content.dsize=strlength(s);
  n=dbm_store(ckintval(argv[0]), key, content, ckintval(argv[3]));
  return((n==0)?T:NIL);}

pointer DBM_DELETE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s;
  datum key;
  ckarg(2);
  s=Getstring(argv[1]);
  key.dptr=(char *)s->c.str.chars;
  key.dsize=strlength(s);
  n=dbm_delete(ckintval(argv[0]), key);
  return((n==0)?T:NIL);}

pointer DBM_FIRSTKEY(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ datum key;
  ckarg(1);
  key=dbm_firstkey(ckintval(argv[0]), key);
  if (key.dptr==NULL) return(NIL);
  return(makestring(key.dptr,key.dsize));}

pointer DBM_NEXTKEY(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ datum key;
  ckarg(1);
  key=dbm_nextkey(ckintval(argv[0]), key);
  if (key.dptr==NULL) return(NIL);
  return(makestring(key.dptr,key.dsize));}

pointer DBM_ERROR(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  n=dbm_error((DBM *)ckintval(argv[0]));
  return((n==0)?T:NIL);}

pointer DBM_CLEARERR(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  dbm_clearerr((DBM *)ckintval(argv[0]));
  return(T);}

#endif  /*sun3 || sun4*/
#endif	/*ifdef DBM*/


/* initialization of unixcall functions*/
unixcall(ctx,mod)
register context *ctx;
pointer mod;
{ pointer p=Spevalof(PACKAGE);

  Spevalof(PACKAGE)=unixpkg;

/* common to unix and to vxworks */
  defun(ctx,"SIGADDSET",mod,SIGADDSET,NULL);
  defun(ctx,"SIGDELSET",mod,SIGDELSET,NULL);
  defun(ctx,"SIGPROCMASK",mod,SIGPROCMASK,NULL);
  defun(ctx,"KILL",mod,KILL,NULL);
  defun(ctx,"SIGNAL",mod,SIGNAL,NULL);
  defun(ctx,"EXIT",mod,EXIT,NULL);
  defun(ctx,"GETPID",mod,GETPID,NULL);
  defun(ctx,"UREAD",mod,UNIXREAD,NULL);
  defun(ctx,"WRITE",mod,UNIXWRITE,NULL);
  defun(ctx,"UCLOSE",mod,UNIXCLOSE,NULL);
  defun(ctx,"IOCTL",mod,IOCTL,NULL);
  defun(ctx,"LSEEK",mod,LSEEK,NULL);
  defun(ctx,"SBRK",mod,SBRK,NULL);
  defun(ctx,"MALLOC",mod,MALLOC,NULL);
  defun(ctx,"FREE",mod,FREE,NULL);

  defun(ctx,"SOCKET",mod,SOCKET,NULL);
  defun(ctx,"BIND",mod,BIND,NULL);
  defun(ctx,"CONNECT",mod,CONNECT,NULL);
  defun(ctx,"LISTEN",mod,LISTEN,NULL);
  defun(ctx,"ACCEPT",mod,ACCEPT,NULL);
  defun(ctx,"SENDTO",mod,SENDTO,NULL);
  defun(ctx,"RECVFROM",mod,RECVFROM,NULL);
#if !Solaris2
  defun(ctx,"GETPEERNAME",mod,GETPEERNAME,NULL);
#endif
/* #endif /*socket*/

/*not supported by vxworks*/
#if !vxworks
  defun(ctx,"PTIMES",mod,PTIMES,NULL);
  defun(ctx,"RUNTIME",mod,RUNTIME,NULL);
  defun(ctx,"LOCALTIME",mod,LOCALTIME,NULL);
  defun(ctx,"ASCTIME",mod,ASCTIME,NULL);
  defun(ctx,"GETITIMER",mod,GETITIMER,NULL);
  defun(ctx,"SETITIMER",mod,SETITIMER,NULL);

#if !Solaris2
  defun(ctx,"GETRUSAGE",mod,GETRUSAGE,NULL);
  defun(ctx,"GETPAGESIZE",mod,GETPAGESIZE,NULL);
#endif

  defun(ctx,"GETTIMEOFDAY",mod,GETTIMEOFDAY,NULL);
  defun(ctx,"ALARM",mod,ALARM,NULL);

#if sun3 || sun4 || news || sanyo || alpha
#if !Solaris2
  defun(ctx,"UALARM",mod,UALARM,NULL);
#endif
#endif

  defun(ctx,"WAIT",mod,WAIT,NULL);
  defun(ctx,"FORK",mod,FORK,NULL);
#if Solaris2
  defun(ctx,"FORK1",mod,FORK1,NULL);
#endif
  defun(ctx,"GETPPID",mod,GETPPID,NULL);
  defun(ctx,"GETPGRP",mod,GETPGRP,NULL);
  defun(ctx,"SETPGRP",mod,SETPGRP,NULL);
  defun(ctx,"GETUID",mod,GETUID,NULL);
  defun(ctx,"GETEUID",mod,GETEUID,NULL);
  defun(ctx,"GETGID",mod,GETGID,NULL);
  defun(ctx,"GETEGID",mod,GETEGID,NULL);
  defun(ctx,"SETUID",mod,SETUID,NULL);
  defun(ctx,"SETGID",mod,SETGID,NULL);
  defun(ctx,"MKNOD",mod,MKNOD,NULL);
  defun(ctx,"MKDIR",mod,MKDIR,NULL);
  defun(ctx,"LOCKF",mod,LOCKF,NULL);
  defun(ctx,"FCNTL",mod,FCNTL,NULL);
#if !Solaris2
  defun(ctx,"IOCTL_",mod,IOCTL_,NULL);
  defun(ctx,"IOCTL_R",mod,IOCTL_R,NULL);
  defun(ctx,"IOCTL_W",mod,IOCTL_W,NULL);
  defun(ctx,"IOCTL_WR",mod,IOCTL_WR,NULL);
#endif
  defun(ctx,"DUP",mod,DUP,NULL);
  defun(ctx,"DUP2",mod,DUP2,NULL);
  defun(ctx,"SYSTEM",mod,SYSTEM,NULL);
  defun(ctx,"GETWD",mod,GETWD,NULL);
  defun(ctx,"GETENV",mod,GETENV,NULL);
  defun(ctx,"ENVIRON",mod,ENVIRON,NULL);
  defun(ctx,"SLEEP",mod,SLEEP,NULL);
  defun(ctx,"ERRNO",mod,ERRNO,NULL);
  defun(ctx,"SYSERRLIST",mod,SYSERRLIST,NULL);
  defun(ctx,"PAUSE",mod,PAUSE,NULL);
  defun(ctx,"ISATTY",mod,ISATTY,NULL);
  defun(ctx,"LINK",mod,LINK,NULL);
  defun(ctx,"UNLINK",mod,UNLINK,NULL);
  defun(ctx,"RMDIR",mod,RMDIR,NULL);
  defun(ctx,"RENAME",mod,RENAME,NULL);
  defun(ctx,"ACCESS",mod,ACCESS,NULL);
/*   defun(ctx,"FLOCK",mod,FLOCK,NULL); */
  defun(ctx,"STAT",mod,STAT,NULL);
  defun(ctx,"CHDIR",mod,CHDIR,NULL);
  defun(ctx,"CHMOD",mod,CHMOD,NULL);
  defun(ctx,"CHOWN",mod,CHOWN,NULL);
  defun(ctx,"PIPE",mod,PIPE,NULL);
  defun(ctx,"SELECT",mod,SELECT,NULL);
  defun(ctx,"SELECT-READ-FD",mod,SELECT_READ,NULL);
  defun(ctx,"READDIR",mod,DIRECTORY,NULL);

#if !vxworks
  defun(ctx,"GETHOSTNAME",mod,GETHOSTNAME,NULL);
  defun(ctx,"GETHOSTBYNAME",mod,GETHOSTBYNAME,NULL);
  defun(ctx,"GETHOSTBYADDR",mod,GETHOSTBYADDR,NULL);
  defun(ctx,"GETNETBYNAME",mod,GETNETBYNAME,NULL);
  defun(ctx,"GETPROTOBYNAME",mod,GETPROTOBYNAME,NULL);
  defun(ctx,"GETSERVBYNAME",mod,GETSERVBYNAME,NULL);
/* Append by I.Hara for IPC */
  defun(ctx,"HTONS",mod,H2NS,NULL);
  defun(ctx,"NTOHS",mod,N2HS,NULL);
#endif

#if sun3 || sun4 || vax || news || sanyo || (mips && !IRIX && !IRIX6) || i386 || alpha
  defun(ctx,"VFORK",mod,VFORK,NULL);
#endif
  defun(ctx,"EXEC",mod,EXEC,NULL);
#if !Solaris2
  defun(ctx,"GETPRIORITY",mod,GETPRIORITY,NULL);
  defun(ctx,"SETPRIORITY",mod,SETPRIORITY,NULL);
#endif

#if sun3 || sun4 || vax || mips || i386 || alpha
  defun(ctx,"PUTENV",mod,PUTENV,NULL);
#endif
#if sun3 || sun4 && !Solaris2 || Linux || alpha
  defun(ctx,"USLEEP",mod,USLEEP,NULL);
#endif

#if !news
  defun(ctx,"MSGGET",mod,MSGGET,NULL);
  defun(ctx,"MSGSND",mod,MSGSND,NULL);
  defun(ctx,"MSGRCV",mod,MSGRCV,NULL);
  defun(ctx,"MSGCTL",mod,MSGCTL,NULL);
#endif

#if sun3 || sun4 || news || alpha
  defun(ctx,"VALLOC",mod,VALLOC,NULL);
#endif
#if sun3 || sun4 || news || alpha || Linux
  defun(ctx,"MMAP",mod,MMAP,NULL);
  defun(ctx,"MUNMAP",mod,MUNMAP,NULL);
/*  defun(ctx,"VADVISE",mod,VADVISE,NULL); */
#endif

#if system5 || Linux
  defun(ctx,"UNAME",mod,UNAME,NULL);
#endif

#endif /*socket*/

/*ndbm libraries*/
#ifdef DBM
#if sun3 || sun4
  defun(ctx,"DBM-OPEN",mod,DBM_OPEN,NULL);
  defun(ctx,"DBM-CLOSE",mod,DBM_CLOSE,NULL);
  defun(ctx,"DBM-FETCH",mod,DBM_FETCH,NULL);
  defun(ctx,"DBM-STORE",mod,DBM_STORE,NULL);
  defun(ctx,"DBM-DELETE",mod,DBM_DELETE,NULL);
  defun(ctx,"DBM-FIRSTKEY",mod,DBM_FIRSTKEY,NULL);
  defun(ctx,"DBM-NEXTKEY",mod,DBM_NEXTKEY,NULL);
  defun(ctx,"DBM-ERROR",mod,DBM_ERROR,NULL);
  defun(ctx,"DBM-CLEARERR",mod,DBM_CLEARERR,NULL);
#endif

#endif
/* restore package*/  Spevalof(PACKAGE)=p;
}
