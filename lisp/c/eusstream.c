/****************************************************************/
/* eusstream.c
/* euLisp stream i/o routines
/*	(c)T.Matsui
/*	1986-Mar
/*	1987-Mar	extension of string output stream
/*	1987-May	filestream, socketstream,...
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#if system5
#include <sys/ipc.h>
#include <sys/msg.h>
#endif
#include "eus.h"
#include <sys/msg.h>

extern int errno;
int ch[MAXTHREAD];		/*current character*/
int written_count[MAXTHREAD];

/****************************************************************/
/* open and close stream primitives
/****************************************************************/

pointer openfile(ctx,fname,dir,acsmode,size)
register context *ctx;
char *fname;
int dir,acsmode,size;
{ int fd,flag;
  pointer s,si,so,fnamep;
  extern pointer mkiostream();
  fd=open(fname, dir, acsmode);
  if (fd<0) return(NULL);
  fnamep=makestring(fname,strlen(fname));
  vpush(fnamep);
  if (dir & O_RDWR) {
    si=mkfilestream(ctx,K_IN,makebuffer(size),fd,fnamep);
    vpush(si);
    so=mkfilestream(ctx,K_OUT,makebuffer(size),fd,fnamep);
    s=mkiostream(ctx,vpop(),so);}
  else if ((dir & 3)==0) {
    s=mkfilestream(ctx,K_IN,makebuffer(size),fd,fnamep);}
  else if (dir & O_WRONLY) {
    s=mkfilestream(ctx,K_OUT,makebuffer(size),fd,fnamep);}
  vpop();	/*fnamep*/
  return(s);}

int closestream(s)
pointer s;
{ int fd,stat;
  if (s->c.stream.direction==K_OUT) flushstream(s);
  else if (!isstream(s)) error(E_STREAM);
  if (pisfilestream(s) && !isint(s->c.fstream.fname)) {	/*message queu?*/
    fd=intval(s->c.fstream.fd);
    if (fd>=0) stat=close(fd);
    else stat= -1;
/*    if (debug) fprintf(stderr,"closestream fd=%d stat=%d\n",fd,(stat?errno:0)); */
    pointer_update(s->c.stream.direction,NIL);
    return(stat);}
  return(0);}

/****************************************************************/
/* read primitive
/****************************************************************/

static int fillstream(s)
register pointer s;
{ register int c;
  pointer lsave;
  register byte *strbuf;
  context *ctx=euscontexts[thr_self()];

  strbuf=(s->c.stream.buffer)->c.str.chars;
  if (pisfilestream(s)) {
    if (isint(s->c.fstream.fname)) {	/*message queue*/
      lsave=s->c.stream.buffer->c.str.length;
      tryqread:
/* news doesnot have message queu, what a bsd machine!*/
#if !news
      c=msgrcv(intval(s->c.fstream.fd),		/*qid*/
		strbuf-4,intval(lsave),0,0);
#endif
#if system5 || Solaris2
      if (c<0) { breakck; goto tryqread;}
#endif
#if sun3 || sun4 || vax || apollo || news || sanyo || mips || i386 || alpha || x86_64 || ARM
      breakck;
#endif
      s->c.stream.buffer->c.str.length=lsave;
      if (c==0) return(EOF);
      else return(0);}
    else {
      tryfread:
      GC_REGION(c=read(intval(s->c.fstream.fd), strbuf,
	     intval((s->c.stream.buffer)->c.str.length)););
      if (debug) {
	printf(";; read; stat=%d errno=%d, intsig=%d\n", c, errno, ctx->intsig);}
      breakck;
#if !Cygwin /* if (c<0) goto tryfread; */
      if (c<0) goto tryfread;
#endif
      if (c<=0) return(EOF);
      s->c.stream.tail=makeint(c);
      return(0);} } 
  else if (s->cix==streamcp.cix) return(EOF);  /*string streams cannot fill*/
  else if (csend(euscontexts[thr_self()], s, K_FILL, 0)==NIL) return(EOF);
  else return(0);}

int readch(s)
register pointer s;
{ register pointer b;
  register byte *strbuf;
  register int c;
/*  if (s->c.stream.direction!=K_IN) return(ch=EOF); */
  b=s->c.stream.buffer;
  if (elmtypeof(b)==ELM_FOREIGN) strbuf=(byte *)(b->c.ivec.iv[0]);
  else strbuf=b->c.str.chars;
  c=intval(s->c.stream.count);
  if (c>=intval(s->c.stream.tail)) {
    if (fillstream(s)==EOF){
#if 0
	fprintf(stderr, "EOF "); 
#endif
	return(ch[thr_self()]=EOF);}
    c=0;}
  ch[thr_self()]=strbuf[c++];
  s->c.stream.count=makeint(c);
#if 0
  fprintf(stderr, "%x",ch[thr_self()]);
#endif
  return(ch[thr_self()]);}

int unreadch(s,ch)
register pointer s;
int ch;
{ register pointer b;
  register byte *sb;
  register int c;
  if (ch==EOF) return(ch);
  c=intval(s->c.stream.count);
  if (c) {
    b=s->c.stream.buffer;
    if (elmtypeof(b)==ELM_FOREIGN) sb=(byte *)(b->c.ivec.iv[0]);
    else sb=b->c.str.chars;
    sb[--c]=ch;
    s->c.stream.count=makeint(c);}
  }


/****************************************************************/
/* output primitives
/****************************************************************/

int flushstream(s)
register pointer s;
{ register int fno,stat,cnt,blen;
  register pointer lsave,bstr,extstr;
  context *ctx=euscontexts[thr_self()];

//   fno=intval(s->c.fstream.fd);	// only when isfilestream(s). moved to inside of if(pisfilestream(s))
  bstr=s->c.stream.buffer;
  cnt=intval(s->c.stream.count);
  blen=intval(bstr->c.str.length);
  if (cnt<=0) return(0);	/*no buffer: cannot write*/
  if (pisfilestream(s)) {
    fno=intval(s->c.fstream.fd); // moved by ikuo
    if (isint(s->c.fstream.fname)) {
      lsave=bstr->c.str.length;
      bstr->c.str.length=(pointer)mypid;
#if !news
      stat=msgsnd(fno,bstr->c.str.chars-4,cnt,0);
#endif
      breakck;
      bstr->c.str.length=lsave;}
    else {
      tryfwrite:
      stat=write(fno,bstr->c.str.chars,cnt);
#if system5
      if (stat<0) { breakck; goto tryfwrite;}
#endif
#if sun3 || sun4 || apollo || vax || news || sanyo || mips || alpha
      breakck;
#endif
      }
    if (stat>=0) { s->c.stream.count=makeint(0); return(0);}
    else return(-1);}
  else if (s->cix==streamcp.cix) {
    if (blen==cnt) {	/*extend string output stream*/
      if (blen>=1000000) error(E_LONGSTRING);
      extstr=makebuffer(cnt*2);
      memcpy(extstr->c.str.chars, bstr->c.str.chars, cnt);
      /* substituted bcopy(bstr->c.str.chars,extstr->c.str.chars,cnt);*/
      pointer_update(s->c.stream.buffer,extstr);
      s->c.stream.tail=makeint(cnt*2-1);}
    return(0); }
  else if (csend(euscontexts[thr_self()], s,K_FLUSH,0)==NIL) return(-1); else return(0);
  }

int writech(s,ch)
register pointer s;
register byte ch;
{ register int c,slen;
  register byte *strbuf;
  c=intval(s->c.stream.count);
  strbuf=(s->c.stream.buffer)->c.str.chars;
  slen=intval((s->c.stream.buffer)->c.str.length);
  if (c>=slen) {
    if (flushstream(s)<0) return(-1);
    c=intval(s->c.stream.count);
    strbuf=(s->c.stream.buffer)->c.str.chars;} 
  strbuf[c++]=ch; s->c.stream.count=makeint(c); written_count[thr_self()]++; }
    
int writestr(s,mes,len)    /* write string */
register pointer s;	/*stream*/
register byte *mes;
register int len;
{ register int bcount,bsize,i=0,count;
  register byte *strbuf;

  bcount=intval(s->c.stream.count);
  strbuf=(s->c.stream.buffer)->c.str.chars;
  bsize=intval((s->c.stream.buffer)->c.str.length);
  while (len>0) {
    if (bcount>=bsize) {
      if (flushstream(s)<0) return(-1);
      bsize=intval((s->c.stream.buffer)->c.str.length);
      bcount=intval(s->c.stream.count);
      strbuf=(s->c.stream.buffer)->c.str.chars;}
    count=min(len,bsize-bcount);
    memcpy(&strbuf[bcount], &mes[i], count);
    /* substituted bcopy(&mes[i],&strbuf[bcount],count); */
    i+=count; len-=count; bcount+=count;
    s->c.stream.count=makeint(bcount);}
  written_count[thr_self()]+=i;
  }

