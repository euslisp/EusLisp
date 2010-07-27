/* anal: analyze a.out file
	date:	Dec/24/1985
	author:	T.Matsui
*/

#include <stdio.h>
#include <fcntl.h>
#include <a.out.h>

#define MAXSYMBOLS 1024
#define hexch(x) (char)((x<10)?(x+'0'):(x+'0'+7))
#define min(x,y) ((x<y)?x:y)

extern char *optarg;
extern int optind;

int  infd,outfd;
int  symtabsize;
int  fmask,castabs=0,rmesect=0;

fatal(mes)
{ puts(mes); exit(2);}

readsym(n)
int n;
{ register int ch,i,f;
  struct {
    char flag;
    char dummy;
    long val;
    char id[16];} sym;
  
  while (n>0) {
    fread(&sym,6,1,stdin);	/*read flags*/
    n -= 6;
    i=0;
    do {	/*read symbol id letters*/
      ch=getchar();
      sym.id[i++]=ch;
      n--;}
      while (ch);
    if (sym.flag & 0x20) {	/*external symbol?*/
      if (sym.flag==0x23) f=0x28;
      else if (sym.flag==0x20) f=0x30;
      else f=sym.flag;
      if (castabs) sym.flag=0x21;
      if (rmesect && 
		(strcmp(sym.id,"_etext")==0 || strcmp(sym.id,"_edata")==0 ||
		 strcmp(sym.id,"_end")==0)) /*remove section name*/ f=0;
      if (f & fmask) {
        write(outfd,&sym,6+i);
        symtabsize += 6+i;}}}
  }

main(argc,argv)
int argc;
char *argv[];
{ struct bhdr header,newheader;
  char *progname,c;
  progname=argv[0];
  outfd= -1; fmask=31;
  while ((c=getopt(argc,argv,"o:dtbuaAE")) != EOF)
    switch(c) {
    case 'o': outfd=creat(optarg,0644);
	      if (outfd<0) {
	        fprintf(stderr,"%s: cannot open output file: %s\n",
			progname,optarg);
		exit(1);}
	      break;
    case 'a': fmask&=0x1e; break;
    case 'd': fmask&=0x17; break;
    case 't': fmask&=0x1d; break;
    case 'b': fmask&=0x1b; break;
    case 'u': fmask&=0x0f; break;
    case 'A': castabs=1; break;
    case 'E': rmesect=1; break;
    case '?': fprintf(stderr,"invalid option %s\n",optarg);
	      break;
    default:  break;}

  /*set up input files*/
  if (optind<argc) {
    infd=open(argv[optind],O_RDONLY);
    if (infd<0) {
      fprintf(stderr,"%s: cannot open %s\n",progname,argv[optind]);
      exit(1);}
    close(0); 	/*switch stdin*/
    dup(infd);}	
  if (outfd<0) outfd=creat("a.out",0644);
  if (read(0,&header,sizeof(header))<1) fatal("cannot read");

  newheader=header;
  newheader.tsize=0; newheader.dsize=0; newheader.bsize=0;
  newheader.rtsize=newheader.rdsize=0;
  write(outfd,&newheader,sizeof(newheader));
  
  lseek(0,32+header.tsize+header.dsize,0);	/*seek to symbol table*/
  symtabsize=0;
  readsym(header.ssize);
  lseek(outfd,0,0);		/*move back to the file head*/
/*  fprintf(stderr,"symtabsize=%d\n",symtabsize); */
  newheader.ssize=symtabsize;
  write(outfd,&newheader,sizeof(newheader));
  exit(0);}

