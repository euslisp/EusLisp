/****************************************************************/
/* lisp I/O functions
/*	Copyright Toshihiro MATSUI, ETL, 1987 
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"
#include <ctype.h>

#if vxworks
#undef READ
#else
#include <fcntl.h>
#endif

extern int errno;
extern enum ch_type chartype[256];
extern pointer QREADTABLE,QTERMIO, oblabels;
extern byte *current_syntax[MAXTHREAD];
extern int written_count[MAXTHREAD];
extern pointer read_delimited_list(context*,pointer,int,char *);

pointer OPENFILE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer s;
  extern pointer openfile();
  s=openfile(ctx,(char*)get_string(argv[0]), ckintval(argv[1]),
	     ckintval(argv[2]),ckintval(argv[3]));
  if (s==0) return(makeint(errno));
  return(s);}

pointer CLOSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer s=argv[0];
  if (n!=1) error(E_MISMATCHARG);
  if (isiostream(s)) {
    if (closestream(s->c.iostream.in)<0) return(NIL);
    if (closestream(s->c.iostream.out)<0) return(NIL);
    return(T);}
  else if (isfilestream(s)) {
    if (closestream(s)<0) return(NIL);
    return(T);}
  else error(E_USER,(pointer)"file stream expected");}

pointer getoutstream(ctx,n,strm)
context *ctx;
int n;
register pointer strm;
{ if (n==1 || strm==NIL)  strm=Spevalof(QSTDOUT);
  if (strm==T) strm=Spevalof(QTERMIO);
  if (isiostream(strm)) strm=strm->c.iostream.out;
  if (!isstream(strm)) error(E_STREAM);
  if (strm->c.stream.direction!=K_OUT) error(E_IODIRECTION);
  return(strm);}

pointer getinstream(ctx,n,strm)
context *ctx;
int n;
register pointer strm;
{ if (n<1 || strm==NIL) strm=Spevalof(QSTDIN);
  if (strm==T) strm=Spevalof(QTERMIO);
  if (isiostream(strm)) strm=strm->c.iostream.in;
  if (!isstream(strm)) error(E_STREAM);
  if (strm->c.stream.direction!=K_IN) error(E_IODIRECTION);
  return(strm);}

/****************************************************************/

pointer PRINT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer s;
  int osf;
  ckarg2(1,2);
  osf=ctx->slashflag;
  ctx->slashflag=0;
  prinx(ctx,argv[0],s=getoutstream(ctx,n,argv[1])); terpri(s);
  ctx->slashflag=osf;
  return(argv[0]);}

pointer PRIN1(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ ckarg2(1,2);
  int osf;
  osf=ctx->slashflag;
  ctx->slashflag=0;
  prinx(ctx,argv[0],getoutstream(ctx,n,argv[1]));
  ctx->slashflag=osf;
  return(argv[0]);}

pointer PRINC(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int osf;
  ckarg2(1,2);
  osf=ctx->slashflag;
  ctx->slashflag=1;
  prinx(ctx,argv[0],getoutstream(ctx,n,argv[1]));
  ctx->slashflag=osf;
  return(argv[0]);}

pointer TERPRI(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer strm;
  ckarg2(0,1);
  strm=getoutstream(ctx,n+1,argv[0]);
  terpri(strm);
  return(NIL);}

static int prsize[MAXTHREAD];

void prntsize(s,lim)
register pointer s;
int lim;
{ char buf[16];
  register int i,n,etype;
  numunion nu;
  if (prsize[thr_self()]>=lim) return;
  else if (isint(s)) { sprintf(buf,"%ld",intval(s)); prsize[thr_self()]+=strlen(buf);}
  else if (isflt(s)) prsize[thr_self()]+=7;
  else if (piscons(s)) {
    if (ccar(s)==QUOTE && islist(ccdr(s)) && ccdr(ccdr(s))==NIL) {
      prsize[thr_self()]++; prntsize(ccar(ccdr(s)),lim);}  /* ???? */
    else {
      prsize[thr_self()]+=2;
      while (islist(s)) {
        prntsize(ccar(s),lim);
        if (prsize[thr_self()]>lim) return;
        s=ccdr(s);
        if (s!=NIL) prsize[thr_self()]++;}
      if (s!=NIL) { prntsize(s,lim); prsize[thr_self()]+=2;}}}
  else if (pisstring(s)) prsize[thr_self()]+=strlength(s);
  else if (pissymbol(s)) prsize[thr_self()]+=strlength(s->c.sym.pname);
  else if (pisvector(s)) {
    n=vecsize(s); i=0; etype=elmtypeof(s);
    switch(etype) {
      case ELM_BIT: case ELM_CHAR: case ELM_FOREIGN: prsize[thr_self()]+=2+n; break;
      case ELM_BYTE: prsize[thr_self()]+=20; break;	/*detarame*/
      case ELM_FLOAT: case ELM_INT: prsize[thr_self()]++;
      case ELM_POINTER:
	    prsize[thr_self()]+=3;
	    while (i<n) {
	      if (etype==ELM_FLOAT) prntsize(makeflt(s->c.fvec.fv[i]),lim);
	      else if (etype==ELM_INT) prntsize(makeint(s->c.ivec.iv[i]),lim);
	      else prntsize(s->c.vec.v[i],lim);
	      if (prsize[thr_self()]>lim) return;
	      prsize[thr_self()]++; i++;}
	    break;} }
  else prsize[thr_self()]+=strlength(classof(s)->c.cls.name->c.sym.pname)+12;}

pointer PRNTSIZE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int lim;
  prsize[thr_self()]=0;
  ckarg2(1,2);
  if (n==2) lim=ckintval(argv[1]); else lim=256;
  prntsize(argv[0],lim);
  return(makeint(prsize[thr_self()]));}

pointer READ(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer strm,eoferrorp=T,eofvalue=NIL,result,recursivep=NIL;
  ckarg2(0,4);
  strm=getinstream(ctx,n,argv[0]);
  if (n>=2) eoferrorp=argv[1];
  if (n>=3) eofvalue=argv[2];
  if (n==4) recursivep=argv[3];
  result=reader(ctx,strm,recursivep);
  if (result==(pointer)EOF)
    if (eoferrorp==NIL) return(eofvalue);
    else error(E_EOF);
  return(result);}

pointer READ_DELIMITED_LIST(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer strm,result,recursivep=NIL;
  int delim_char;
  char token[1024];

  ckarg2(1,3);
  delim_char=ckintval(argv[0]);
  strm=getinstream(ctx,n-1,argv[1]);
  if (n==3) recursivep=argv[2];

  current_syntax[thr_self()]=Spevalof(QREADTABLE)->c.rdtab.syntax->c.str.chars;
  if (recursivep==NIL) {
    pointer_update(oblabels->c.lab.next,NIL);
    result=read_delimited_list(ctx,strm,delim_char,token);
    pointer_update(oblabels->c.lab.next,NIL);}
  else result=read_delimited_list(ctx,strm,delim_char,token); /*preserve #n= scope*/
  return(result);}

#define READLINE_BUF_LENGTH 8192
pointer READLINE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer strm;
  pointer eoferrorp=T,eofvalue=NIL,ret=NIL;
  byte *cb = (byte *) malloc(READLINE_BUF_LENGTH);
  register int i=0,ch,buflength=READLINE_BUF_LENGTH;
  ckarg2(0,3);
  strm=getinstream(ctx,n,argv[0]);
  if (n>=2) eoferrorp=argv[1];
  if (n==3) eofvalue=argv[2];
  while (1) {
    ch=readch(strm);
    if (ch=='\n') break;
    else if (ch==EOF) {
      if (i>0) break;
      free(cb);
      if (eoferrorp==NIL) return(eofvalue);
      else error(E_EOF);}
    cb[i++]=ch;
    if (i >= buflength) {
      byte *newcb = malloc(buflength+READLINE_BUF_LENGTH);
      if (newcb == NULL) {
        free(cb);
        error(E_USER, (pointer)"Memory allocation error by read-line");
        break;
      }
      memcpy(newcb, cb, buflength);
      buflength += READLINE_BUF_LENGTH;
      free(cb);
      cb = newcb;
    }
  }
  if ((i>=1) && cb[i-1]=='\r') i=i-1;
  ret = makestring((char *)cb,i);
  free(cb);
  return(ret);}

pointer READCH(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ pointer strm,eoferrorp=T,eofvalue=NIL;
  register eusinteger_t result;
  ckarg2(0,3);
  strm=getinstream(ctx,n,argv[0]);
  if (n>=2) eoferrorp=argv[1];
  if (n==3) eofvalue=argv[2];
  result=readch(strm);
  if (result==EOF)
    if (eoferrorp==NIL) return(eofvalue);
    else error(E_EOF);
  return(makeint(result));}

pointer UNREADCH(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer strm;
  byte ch;
  ckarg2(1,2);
  strm=getinstream(ctx,n-1,argv[1]);
  ch=ckintval(argv[0]);
  unreadch(strm,ch);
  return(argv[0]);}

pointer PEEKCH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer strm,eoferrorp=T,eofvalue=NIL;
  eusinteger_t result;
  ckarg2(0,3);
  strm=getinstream(ctx,n,argv[0]);
  if (n>=2) eoferrorp=argv[1];
  if (n==3) eofvalue=argv[2];
  result=readch(strm);
  if (result==EOF)
    if (eoferrorp==NIL) return(eofvalue);
    else error(E_EOF);
  unreadch(strm,result);
  return(makeint(result));}

pointer FINOUT(ctx,n,argv)	/*finish-output*/
register context *ctx;
int n;
pointer argv[];
{ pointer strm;
  strm=getoutstream(ctx,n+1,argv[0]);
  flushstream(strm);
  return(NIL);}

pointer WRTBYTE(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer bytes,strm;
  ckarg(2);
  strm=getoutstream(ctx,n,argv[1]);
  bytes=argv[0];
  if (islist(bytes)) 
    while (islist(bytes)) {
      writech(strm,ckintval(ccar(bytes)));
      bytes=ccdr(bytes);}
  else writech(strm,ckintval(bytes));
  return(argv[0]);}      

pointer WRTWORD(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer bytes,strm;
  union {
    short s;
    char b[2];} buf;
  ckarg(2);
  strm=getoutstream(ctx,n,argv[1]);
  bytes=argv[0];
  if (islist(bytes)) 
    while (islist(bytes)) {
      buf.s=ckintval(ccar(bytes));
      writestr(strm,(byte *)buf.b,2);
      bytes=ccdr(bytes);}
  else {
    buf.s=ckintval(bytes);
    writestr(strm,(byte *)buf.b,2);}
  return(argv[0]);}

pointer WRTLONG(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer bytes,strm;
  union {
    int i;
    byte b[4];} buf;
  ckarg(2);
  strm=getoutstream(ctx,n,argv[1]);
  bytes=argv[0];
  if (islist(bytes)) 
    while (islist(bytes)) {
      buf.i=bigintval(ccar(bytes));
      writestr(strm,buf.b,4);
      bytes=ccdr(bytes);}
  else {
    buf.i=bigintval(bytes);
    writestr(strm,buf.b,4);}
  return(argv[0]);}

pointer SETMACROCH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int ch;
  pointer nontermp=NIL,rdtable;
  ckarg2(2,4);
  if (isstring(argv[0])) ch=argv[0]->c.str.chars[0];
  else ch=ckintval(argv[0]);
  if (ch<0 || 256<ch) error(E_CHARRANGE);
  if (n>=3) nontermp=argv[2];
  if (n==4) rdtable=argv[3];
  else rdtable=Spevalof(QREADTABLE);
  if (!isreadtable(rdtable)) error(E_USER,(pointer)"readtable expected");
  pointer_update(rdtable->c.rdtab.macro->c.vec.v[ch],argv[1]);
  if (argv[1]==NIL) rdtable->c.rdtab.syntax->c.str.chars[ch]=(byte)chartype[ch];
  else if (nontermp==NIL) rdtable->c.rdtab.syntax->c.str.chars[ch]=(int)ch_termmacro;
  else rdtable->c.rdtab.syntax->c.str.chars[ch]=(int)ch_nontermacro;
  return(T);}  

pointer GETMACROCH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer rdtable;
  ckarg2(1,2);
  if (n==2) rdtable=argv[1];
  else rdtable=Spevalof(QREADTABLE);
  if (!isreadtable(rdtable)) error(E_USER,(pointer)"readtable expected");
  return(rdtable->c.rdtab.macro->c.vec.v[max(0,min(255,ckintval(argv[0])))]);}

pointer SETDISPMACRO(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ int ch;
  pointer rdtable,func;
  ckarg2(3,4);
  if (isstring(argv[1])) ch=argv[1]->c.str.chars[0];
  else ch=ckintval(argv[1]);
  if (ch<0 || 256<ch) error(E_CHARRANGE);
  if (n==4) rdtable=argv[3];
  else rdtable=Spevalof(QREADTABLE);
  if (!isreadtable(rdtable)) error(E_USER,(pointer)"readtable expected");
  pointer_update(rdtable->c.rdtab.dispatch->c.vec.v[ch],/*(pointer (*)())*/argv[2]);
  return(T);}

pointer GETDISPMACRO(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int ch;
  pointer rdtable,func;
  ckarg2(2,3);
  if (isstring(argv[1])) ch=argv[1]->c.str.chars[0];
  else ch=ckintval(argv[1]);
  if (ch<0 || 256<ch) error(E_CHARRANGE);
  if (n==3) rdtable=argv[2];
  else rdtable=Spevalof(QREADTABLE);
  if (!isreadtable(rdtable)) error(E_USER,(pointer)"readtable expected");
  func=rdtable->c.rdtab.dispatch->c.vec.v[ch];
  return(func);}

pointer RESETREADTABLE(ctx,n,argv)
register context *ctx;
int n; /* unused argument */
pointer *argv; /* unused argument */
{ initreader(ctx); return(T);}  /* ???? */

/*****************************************************************/
/*	FORMAT
/*	1986-Nov
/*	T.Matsui
*/

#define nextcch() ((cx>=cmax)?(byte)((eusinteger_t)error(E_FORMATSTRING)):cstr[cx++])

#define nextfarg() ((fargx>=fargc)?(pointer)error(E_MISMATCHARG):fargv[fargx++])

/*extern void printnum(context *, pointer, pointer, int, int, int);*/

pointer XFORMAT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  register pointer dest,a;
  register int i,j,px,l;
  int param[10],par;
  char buf[256];
  eusfloat_t fval;
  byte *cstr,cch;
  int  cx,cmax;
  pointer *fargv, varg;
  int fargc,fargx;
  int wcount, osf;
  numunion nu;
  extern double fabs();

  if (n<2) error(E_MISMATCHARG);
  dest=argv[0]; a=argv[1];
  if (!isstring(a)) error(E_NOSTRING);
  cx=0; cstr=a->c.str.chars; cmax=intval(a->c.str.length);
  fargv=argv; fargc=n; fargx=2;
  
  if (dest==NIL) dest=(pointer)mkstream(ctx,K_OUT,makebuffer(64));
  else {
    if (dest==T) dest=Spevalof(QSTDOUT);
    if (isiostream(dest)) dest=dest->c.iostream.out;
    if (!isstream(dest)) error(E_STREAM);
    if (dest->c.stream.direction!=K_OUT) error(E_IODIRECTION);}
  vpush(dest);

  written_count[thr_self()]=0;
  while (cx<cmax) {
    cch=nextcch();
    if (cch=='~') {     /*tilda*/
      cch=nextcch();
      px=0; param[0]=0; param[1]=1; param[2]=0;
      while (isdigit(cch)) {
	param[px]=0;
	while (isdigit(cch)) {
	  param[px]=param[px]*10+(cch-'0');
          cch=nextcch();}
	px++;
        if (cch==',') cch=nextcch();}
      if (islower(cch)) cch=toupper(cch);
      if (cch=='V') {
	varg=nextfarg();
	param[px++]=ckintval(varg);
	cch=nextcch();
	if (islower(cch)) cch=toupper(cch);}
      switch(cch) {
	case 'A':	/*Ascii*/
	  osf=ctx->slashflag;
	  ctx->slashflag=1;
	  written_count[thr_self()]=0;
	  prinx(ctx,(pointer)nextfarg(),dest);
	  while (param[0]>written_count[thr_self()]) writech(dest,' ');
	  ctx->slashflag=osf;
	  break;
	case 'S':	/*S-expression*/
	  written_count[thr_self()]=0;
	  prinx(ctx,nextfarg(),dest);
	  while (param[0]>written_count[thr_self()]) writech(dest,' ');
	  break;
	case 'D':	/*Decimal*/
	  a=nextfarg();
	  printnum(ctx,a,dest,10,param[0],param[1]);
	  break;
	case 'X':	/*heXadecimal*/
	  a=nextfarg();
	  printnum(ctx,a,dest,16,param[0],param[1]);
	  break;
	case 'O':	/*Octal*/
	  a=nextfarg();
	  printnum(ctx,a,dest,8,param[0],param[1]);
	  break;
	case 'C':	/*Character*/
	  a=nextfarg();
	  writech(dest,ckintval(a)); break;
	case 'F':	/*Fixed-format floating-point*/
	  a=nextfarg();
	  fval=ckfltval(a);
	  sprintf(buf,"%*.*f",param[0],param[1],fval);
	  writestr(dest,(byte *)buf,strlen(buf)); break;
	case 'E':	/*Exponential floating-point*/
	  a=nextfarg();
	  fval=ckfltval(a);
	  sprintf(buf,"%*.*e",param[0],param[1],fval);
	  writestr(dest,(byte *)buf,strlen(buf)); break;
	case 'G':	/*General floating-point*/
	  a=nextfarg();
	  fval=ckfltval(a);
	  if (fval==0.0) writestr(dest,(byte *)"0.0",3);
	  else {
	    if (fabs(fval)<0.0001 || fabs(fval)>1.0e+05) {
	      sprintf(buf,"%*.*e",param[0],param[1],fval); l=strlen(buf);}
	    else {
	      sprintf(buf,"%*.*f",param[0],param[1],fval);
	      l=strlen(buf);
	      while (l>2 && buf[l-1]=='0' && buf[l-2]!='.') l--;} 
	    writestr(dest,(byte *)buf,l); }
	  break;
	case '%': case '&':	/*newline*/
	  for (j=0; j<=param[0]; j++) writech(dest,'\n');
	  if (argv[0]!=NIL) 
	    if (flushstream(dest)!=0) error(E_USER,(pointer)"cannot flush stream");
	  break;
	case '~':	/*tilda*/
	  writech(dest,'~'); break;
	case 'T': 	/*tabulate*/
	  writech(dest,9); break;;
	default:	break;
        }  
      }
    else writech(dest,cch);}
  if (argv[0]==NIL) {
    a=makestring((char *)dest->c.stream.buffer->c.str.chars,
		 intval(dest->c.stream.count));
    vpop();
    return(a);}
  else { vpop(); return(NIL);}
  }

pointer SIGERROR(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ register int i;
  pointer  msg;
  pointer *argb=ctx->vsp;
  if (isstring(argv[0])) {
     vpush(NIL);
     for (i=0; i<n; i++) vpush(argv[i]);
     msg=XFORMAT(ctx,n+1,argb);
     error(E_USER,(pointer)(msg->c.str.chars),argv[1]);}
  else error((enum errorcode)(ckintval(argv[0])),argv[1]);}

pointer INSTALL_ERRHANDLER(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ ckarg(1);
  ctx->errhandler=argv[0];
  return(argv[0]);}


void lispio(ctx,mod)
register context *ctx;
pointer mod;
{
  pointer_update(Spevalof(PACKAGE),syspkg);
  defun(ctx,"OPENFILE",mod,OPENFILE,NULL);
  pointer_update(Spevalof(PACKAGE),lisppkg);
/*  defun(ctx,"OPEN",mod,OPEN,NULL); */
  defun(ctx,"CLOSE",mod,CLOSE,NULL);
  defun(ctx,"READ",mod,READ,NULL);
  defun(ctx,"READ-DELIMITED-LIST",mod,READ_DELIMITED_LIST,NULL);
  defun(ctx,"READ-LINE",mod,READLINE,NULL);
  defun(ctx,"READ-CHAR",mod,READCH,NULL);
  defun(ctx,"UNREAD-CHAR",mod,UNREADCH,NULL);
  defun(ctx,"PEEK-CHAR",mod,PEEKCH,NULL);
  defun(ctx,"PRINT",mod,PRINT,NULL);
  defun(ctx,"PRIN1",mod,PRIN1,NULL);
  defun(ctx,"PRINC",mod,PRINC,NULL);
  defun(ctx,"TERPRI",mod,TERPRI,NULL);
  defun(ctx,"PRINT-SIZE",mod,PRNTSIZE,NULL);
  defun(ctx,"FINISH-OUTPUT",mod,FINOUT,NULL);
  defun(ctx,"WRITE-BYTE",mod,WRTBYTE,NULL);
  defun(ctx,"WRITE-WORD",mod,WRTWORD,NULL);
  defun(ctx,"WRITE-LONG",mod,WRTLONG,NULL);
  defun(ctx,"SET-MACRO-CHARACTER",mod,SETMACROCH,NULL);
  defun(ctx,"GET-MACRO-CHARACTER",mod,GETMACROCH,NULL);
  defun(ctx,"SET-DISPATCH-MACRO-CHARACTER",mod,SETDISPMACRO,NULL);
  defun(ctx,"GET-DISPATCH-MACRO-CHARACTER",mod,GETDISPMACRO,NULL);
  defunpkg(ctx,"RESET-READTABLE",mod,RESETREADTABLE,syspkg);
  defun(ctx,"FORMAT",mod,XFORMAT,NULL);
  defun(ctx,"ERROR",mod,SIGERROR,NULL);
  defun(ctx,"INSTALL-ERROR-HANDLER",mod,INSTALL_ERRHANDLER,NULL);
  }

