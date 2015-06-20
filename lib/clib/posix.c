/****************************************************************/
/* posix.c
/*      1995-Jul        nanosleep by S.Kagami.
/****************************************************************/


#include "eus.h"

#if Solaris2
typedef struct {
    long        tv_sec; /* seconds */
    long        tv_nsec;/* and nanoseconds */
} timespec;

pointer NANOSLEEP(context *ctx, int n, pointer *argv)
{
    timespec rqtp, rmtp;

    ckarg(2);
    rqtp.tv_sec = ckintval(argv[0]);
    rqtp.tv_nsec = ckintval(argv[1]);

    nanosleep(&rqtp, &rmtp);
    return(T);
}
#endif

/* initialization of posix functions*/
posix(context *ctx, int n, pointer argv[])
{
  pointer mod=argv[0];

    pointer p=spevalof(PACKAGE);

    spevalof(PACKAGE)=unixpkg;

#if Solaris2
    defun(ctx,"NANOSLEEP",mod,NANOSLEEP,NULL);
#endif

/* restore package*/  spevalof(PACKAGE)=p;
}
