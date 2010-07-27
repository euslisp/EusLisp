/****************************************************************/
/* sockstd.c
/*   TCP socket <---> stdio bridge
/*   % sockstd port <debug>
/*   Sockstd waits for a TCP connection at 'port`.
/*   After the connection is established, incoming data at the port
/*   are copied to sockstd's stdout.
/*   Input to sockstd's stdin (usually key inputs) are transferred to
/*   the port.
/*   Thus, pipe oriented programs, such as 'wc', 'cat', etc., will be
/*   able to work on socket connection using the sockstd.
/*
/*   (c) 1995, Toshihiro Matsui, Electrotechnical Laboraotory
/****************************************************************

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <time.h>

#define bitset(v,i) ((v) | (1<<(i)))
#define bitclr(v,i) ((v) & ~(1<<(i)))
#define bittest(v,i) (v & (1<<(i)))


extern int make_socket_port();
extern void exit();
extern int errno;

long transaction_count=0;
long debug=0;

struct sockaddr_in *make_socket_address(port_no)
int port_no;
{ int stat;
  struct sockaddr_in  *serverAddr;     /* server's address */

  serverAddr=(struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
  /*bzero (serverAddr, sizeof (*serverAddr)); */
  memset(serverAddr, 0, sizeof (*serverAddr));
  serverAddr->sin_family = AF_INET;
  serverAddr->sin_port   = htons(port_no);
  serverAddr->sin_addr.s_addr = htonl(INADDR_ANY);
  return(serverAddr);
  }
  
int make_socket_port(port)
int port;
{ struct sockaddr_in *serverAddr;
  int serverSock, stat;

  serverAddr= make_socket_address(port);
  serverSock = socket (AF_INET, SOCK_STREAM, 0);
  if (serverSock < 0) {
      fprintf(stderr, "can't create socket\n"); exit (1);}
  stat=bind (serverSock, serverAddr, sizeof(struct sockaddr_in));
  if (stat<0){
      printf ("bind failed, errno = %d\n", errno);
      exit(1);}
  if (listen (serverSock, 2) <0 ) {
      printf ("listen failed\n");
      close (serverSock);
      exit (1);}
  printf("listening on port= %d sock=%d\n", port, serverSock);
  return(serverSock);}


main (argc,argv)
int argc;
char *argv[];
{ struct sigaction	sigabort;
  struct sockaddr_in  *server_addr, client_addr;
  int 	server_port;
  int   port_no;
  long  ports, exceptions, sockbits;
  struct timeval time_out;
  char buf[65536];
  int snew=0;
  int i;
  int stat;
  long client_len;

  if (argc>1) sscanf(argv[1],"%d",&port_no);
  else port_no=5000;
  if (argc>2)  sscanf(argv[2],"%d",&debug);
    
  signal(SIGINT, exit);
  signal(SIGPIPE, SIG_IGN);

  /* Listen, for clients to connect to us. */
  server_port=make_socket_port(port_no);


  sockbits=bitset(1, server_port);
  time_out.tv_sec=10;
  time_out.tv_usec=0;

  while (1) {
      select_again:
      ports=sockbits; exceptions=sockbits;
      stat=select(32, &ports,0, &exceptions, &time_out);
      if (stat>0) {
	transaction_count++;
	if (debug>2) 
	  fprintf(stderr, "select: %d count=%d ready=%x excpt=%x \n",
		 transaction_count, stat, ports, exceptions);
	if (exceptions) {
	  /*assumes exception is delivered because of pipe_broken */
	  i=0;
	  while (i<32) {
	    if (bittest(exceptions,i)) {
	      fprintf(stderr, "exception from %d\n", i);
	      sockbits=bitclr(sockbits,i);}
	    i++; }
	  goto select_again;} 
	if (bittest(ports,server_port)) { /*new connection request*/
	  client_len = sizeof (struct sockaddr_in);
	  snew = accept (server_port, &client_addr, &client_len);
	  if (snew>0) sockbits=bitset(sockbits, snew);
	  ports=bitclr(ports,server_port);
	  fprintf(stderr, "new connection %d is accepted \n", snew);
	  /* if (connection_request) (*connection_request)(snew); */
	  stat--;}
	if (bittest(ports, 0)) { /* stdin*/
	    int size;
	    size=read(0,buf,65536);
	    if (snew) write(snew,buf,size);}
	if (bittest(ports, snew)) {
	    int size;
	    size=read(snew,buf,65536);
	    if (snew) write(1,buf,size);}
	}
      }
  }
