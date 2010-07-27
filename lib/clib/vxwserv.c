/* vxwserv.c
/* spawned from server
/* This program is supposed to run on any vxworks machines, not Lisp.
*/

#include "vxWorks.h"
#include "stdioLib.h"
#include "socket.h"
#include "in.h"
#include "sigLib.h"
#include "taskLib.h"

#include "vxw_proto.h"

#define SERVER_NUM 2200
#define ARGUMENT_BUFFER_SIZE 16384

extern char *sysSymTbl;

static int error_code;

/****************************************************************/

void protocol_error(x)
int x;
{ printf("VxWs protocol error %d\n",x);
  error_code=x; }

static getint(type, s)
enum argument_type type;
register FILE *s;
{ register int ival=0;
  switch(type) {
  A_LONG:  ival=(getc(s)<<24)+(getc(s)<<16);
  A_SHORT: ival+=(getc(s)<<8);
  A_CHAR:  return(ival+getc(s));}
  }

static double getfloat(type, s)
enum argument_type type;
register FILE *s;
{ double dval=0.0;
  number_union nu;
  switch(type) {
  case A_FLOAT: nu.i.ival1=getw(s); return(nu.f.fval1);
  case A_DOUBLE: nu.i.ival1=getw(s); nu.i.ival2=getw(s); return(nu.dval);
  }}

static getlength(s)
FILE *s;
{ int len;
  len=getc(s);
  if (len & 0x80) {
    if (len & 0x40) /*32bit length*/
      return(((len & 0x3f)<<24) + (getc(s)<<16) + (getc(s)<<8) + getc(s));
    else return(((len & 0x7f)<<8) + getc(s)); }
  else return(len);}

static int getvector(s,vmem,index,bufsize)
register FILE *s;
register unsigned char *vmem;
register int index;
int bufsize;
{ register int i,length;
  length=getlength(s);
  if (index+length >= bufsize-100) {
    protocol_error(3);	/* vector buffer overflow*/
    for (i=0; i<length; i++) getc(s);	/*skip vector elements*/
    return(index);}
  for (i=0; i<length; i++) vmem[index++]=getc(s);
  i=4-(length % 4);
  while (i-- >0) vmem[index++] =0;	/*align to long word boundary */
  return(index);}

int findsymbol(s)
char *s;
{ int stat, entry, entry_type;
  if (symFindByName(sysSymTbl, s, &entry, &entry_type) == OK) return(entry);
  else return(ERROR);}

static int getsymbol(s)
register FILE *s;
{ char symstr[256];
  register int i,len;
  int stat, entry, entry_type;
  
  len=getlength(s);
  for (i=0; i<len; i++) symstr[i+1]=getc(s);
  symstr[len+1]=0;
  stat=symFindByName(sysSymTbl, &symstr[1], &entry, &entry_type);
  if (stat==ERROR) {
    symstr[0]='_';
    stat=symFindByName(sysSymTbl, symstr, &entry, &entry_type);
    if (stat==ERROR) return(ERROR);}
  return(entry);}

int call_vxw(fd)
int fd;
{ FILE *s, *ws;
  int bufsize, running=1, callee, tid, result_type;
  int nextfree, i, j, len;	/*argument counter*/
  int (*ifunc)();
  double (*ffunc)();
  double f;
  enum argument_type type;
  long cargv[32];
  number_union nu;
  unsigned char *ip, *vmem;

  if ((s=fdopen(fd,"r"))==NULL) { printf("cannot fdopen read\n"); exit(2);}
  if ((ws=fdopen(fd,"w"))==NULL) { printf("cannot fdopen write\n"); exit(2);}

  tid=taskIdSelf();
  taskVarAdd(tid, &error_code);
  bufsize=getw(s);
  vmem = malloc(bufsize);
  if (malloc==NULL) { protocol_error(7); return(7);}

  printf("VxWserv v1.0 started with %d byte buffer\n", bufsize);

  while (running) {
    nextfree=i=j=0; error_code=0;
    type=getc(s);
    if (type==EOF) { protocol_error(5); break;}
    if (type==A_SYMBOL) { 
      callee=getsymbol(s);
      if (callee==ERROR) protocol_error(1); }
    else if (type==A_LONG) callee=getw(s);
    else protocol_error(2);

/*    printf("entry=0x%x\n", callee); */

    type=getc(s);
    while (type!=A_END) { 
      if (j>=32) protocol_error(5);
      switch(type) {
        case A_CHAR:  cargv[i++]=getc(s); break;
        case A_SHORT: cargv[i++]=(getc(s)<<8) + getc(s); break;
        case A_LONG:  cargv[i++]=getw(s); break;
        case A_FLOAT: len=getw(s); nu.i.ival1=len;
			nu.dval=nu.f.fval1;
		      cargv[i++]=nu.i.ival1; cargv[i++]=nu.i.ival2;
		      break;
	case A_SYMBOL: cargv[i++]=getsymbol(s); break;
	case A_VECTOR: cargv[i++]= &vmem[nextfree];
		       nextfree=getvector(s,vmem,nextfree,bufsize);
		       break;
	default: protocol_error(4); break; }
      j++;
      type=getc(s); /*next arg type*/
      if (type==EOF) protocol_error(6);
      }	/*end of reading arguments*/

    result_type=getc(s);

    /* protocol analysis finished, return the status*/
    putc(error_code, ws);
    if (error_code==5) break;	/*communication broke down*/

    if (error_code!=0) { /*error occurred, abort invokation*/ }
    else if (result_type==A_FLOAT || result_type==A_DOUBLE) {
      ffunc=callee;
      if (j<=8) 
        f=(*ffunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	           cargv[4],cargv[5],cargv[6],cargv[7]);
        else if (j<=32)
        f=(*ffunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	           cargv[4],cargv[5],cargv[6],cargv[7],
		   cargv[8],cargv[9],cargv[10],cargv[11],
	           cargv[12],cargv[13],cargv[14],cargv[15],
		   cargv[16],cargv[17],cargv[18],cargv[19],
	           cargv[20],cargv[21],cargv[22],cargv[23],
		   cargv[24],cargv[25],cargv[26],cargv[27],
	           cargv[28],cargv[29],cargv[30],cargv[31]);
/*      printf("result=%lf\n",f); */
      nu.f.fval1=f;	/*coerce double to float*/
      putw(nu.i.ival1, ws);}
    else {
      ifunc=callee;
      if (j<8) 
        i=(*ifunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	           cargv[4],cargv[5],cargv[6],cargv[7]);
      else if (j<=32)
        i=(*ifunc)(cargv[0],cargv[1],cargv[2],cargv[3],
	           cargv[4],cargv[5],cargv[6],cargv[7],
		   cargv[8],cargv[9],cargv[10],cargv[11],
	           cargv[12],cargv[13],cargv[14],cargv[15],
		   cargv[16],cargv[17],cargv[18],cargv[19],
	           cargv[20],cargv[21],cargv[22],cargv[23],
		   cargv[24],cargv[25],cargv[26],cargv[27],
	           cargv[28],cargv[29],cargv[30],cargv[31]);
/*      printf("result=%d\n",i); */
      if (result_type==A_CHAR || result_type==A_SHORT || result_type==A_LONG)
        putw(i,ws);
      else if (result_type==A_VECTOR) {
	len=getlength(s); ip=(unsigned char *) i;
	for (j=0; j<len; j++) { putc(*ip, ws); ip++;} 
        }
      }
    fflush(ws);}  /*running*/

  fclose(s);  free(vmem);
  printf("connection closed\n"); }

/* spawn a new server */


static int sock;	/* socket fd's */

int spawn_vxw(fd)
int fd;
{ char taskname[16];
  int stat,entry,entry_type;
  static int task_id=1;
  unsigned char option,priority;

  read(fd, &priority,1);
  read(fd, &option, 1); 
  sprintf(taskname,"VxWs_%d",task_id++);
  stat=taskSpawn(taskname, priority, option, 3000,call_vxw,fd);
  if (stat==ERROR) {  printf("cannot spawn\n"); return(ERROR); }
  else return(OK);}

static void abort(sig)
int sig;
{ printf("vxwserv aborting\n");
  close(sock);
  exit(sig);}

vxwserv ()
 {  int snew;
    struct sockaddr_in	serverAddr;	/* server's address */
    struct sockaddr_in 	clientAddr;	/* client's address */
    int			client_len;	/* length of clientAddr */
    int			connection_count=0;
    unsigned char special;
    SIGVEC      sigabort;

    sigabort.sv_handler = abort;
    sigabort.sv_mask = !SIGMASK(SIGINT);
    sigabort.sv_flags= 0;
    sigvec(SIGINT, &sigabort, 0);

    /* Zero out the sock_addr structures.
     * This MUST be done before the socket calls.     */

    bzero (&serverAddr, sizeof (serverAddr));
    bzero (&clientAddr, sizeof (clientAddr));

    sock = socket (AF_INET, SOCK_STREAM, 0);
    if (sock == ERROR) exit (1);
    else printf("listening on socket %d\n",sock);
    /* Set up our internet address, and bind it so the client can connect. */

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port   = SERVER_NUM;

    while (bind (sock, (SOCKADDR *)&serverAddr, sizeof(serverAddr))==ERROR) {
	printf ("bind failed, errno = %d\n", errnoGet());
        serverAddr.sin_port++; }
    printf ("port %d is bound.\n", serverAddr.sin_port);
    /* Listen, for the client to connect to us. */
    if (listen (sock, 2) == ERROR) {
	printf ("listen failed\n");
	close (sock);
	exit (1);}

    /* accept-fork loop */
    while (1) {
      client_len = sizeof (clientAddr);
      snew = accept (sock, (SOCKADDR *)&clientAddr, &client_len);
      if (snew==ERROR) { printf("accept failed\n"); close(sock); break;}
      printf("CLIENT accepted: sock=%d port=%d  family=%d  addr=%lx\n", 
	    snew,
	    clientAddr.sin_port, clientAddr.sin_family, 
	    clientAddr.sin_addr.s_addr);
      connection_count++ ;
      read(snew, &special, 1);	/*ignore first byte*/
      if (spawn_vxw(snew)==ERROR)
	 { printf("spawn failed\n"); } ;
      }
    printf ("totally %d connections established\n",connection_count);
    close (sock); }
