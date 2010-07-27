/****************************************************************/
/* stripsh.c
/*	strip off section headers from a.out
/*
/*	(c) T.Matsui, 1986
/****************************************************************/

#include <signal.h>
#include <ctype.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <libelf.h>

#define min(a,b) (a<b)?a:b

main(argc,argv)
int argc;
char *argv[];
{ int infd, outfd;
  int count, size, sh_off;
  int zero=0;
  char buf[8192];

  infd=open(argv[1], O_RDONLY);
  outfd=open(argv[2], O_WRONLY | O_CREAT,0755);
  read(infd, buf, 0x20);
  write(outfd,buf,0x20);
  read(infd, &count, 4);
  write(outfd, &zero, 4);
  count=count-0x24;
  printf("%x\n", count);
  while (count>0) {
    size=read(infd,buf,min(8192,count));
    count-=size;
    write(outfd, buf, size);}
  close(infd); close(outfd);
  }


