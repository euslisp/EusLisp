/* linux_lowio.c */
/* -O optimization flag is needed */
/* % gcc -c -Di386 -DLinux -DGCC -fpic -O linux_lowio.c -I/usr/local/eus/include
/* % ld -shared -o linux_lowio.so linux_lowio.o

*/

#include "eus.h"
#include <asm/io.h>


pointer IOPERM(context *ctx, int n, pointer argv[])
{ int val, stat;
  val= intval(argv[0]);
  stat= ioperm(0, 0x3ff, val);
  if (stat<0) {
    error("IOPERM failed because of insufficient priviledge");}
  return(T); }

pointer OUTB(context *ctx, int n, pointer argv[])
{ int port, val;
  port=intval(argv[0]);
  val=intval(argv[1]);
  outb(val, port);
  return(argv[1]);
  }

pointer INB(context *ctx, int n, pointer argv[])
{ int port, val;
  port=intval(argv[0]);
  val=inb(port);
  return(makeint(val));
  }

pointer linux_lowio(context *ctx, int n, pointer argv[], pointer env)
{ pointer p=Spevalof(PACKAGE);
  pointer mod;

  mod = argv[0];

  /* Spevalof(PACKAGE)=unixpkg; */

  printf("ioperm, outb, inb\n");

  defun(ctx,"IOPERM", mod, IOPERM,NULL);
  defun(ctx,"OUTB", mod, OUTB,NULL);
  defun(ctx,"INB", mod, INB,NULL);

  printf("linux low level IO functions defined.\n");

  return(NIL);
  }



