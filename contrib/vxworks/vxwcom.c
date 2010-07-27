#include "eus.h"
#include "vxw_proto.h"

static void putlong(s,i)
pointer s;
long i;
{ register unsigned char *ip= (unsigned char *)&i;
  writech(s,*ip++); writech(s,*ip++); writech(s,*ip++); writech(s,*ip++);}

static unsigned long getlong(con)
pointer con;
{ register unsigned int ival=0;
  ival=readch(con);
  ival=(ival<<8)+readch(con);
  ival=(ival<<8)+readch(con);
  ival=(ival<<8)+readch(con);
/*  printf("result=%d\n",ival); */
  return(ival);}


static putlength(s,len)
pointer s;
unsigned int len;
{ if (len<128) writech(s,len);
  else if (len<16384) {
    writech(s, 0x80 | (len >> 8));
    writech(s, len & 0xff);} 
  else error("argument to large");}

static int putarg(s,p)
pointer s,p;
{ numunion nu;
  register int i,len, elmt;
  register unsigned char *bp;

  if (isint(p)) { 
    writech(s, A_LONG); putlong(s,intval(p));}
  else if (isflt(p)) {
    writech(s, A_FLOAT);   nu.fval=fltval(p);   putlong(s, nu.ival);}
  else {
    if (isarray(p)) p=p->c.ary.entity;
    if (isvector(p)) {
      len=vecsize(p); elmt=elmtypeof(p);
      writech(s, A_VECTOR);
      bp= p->c.str.chars;
      switch(elmt) {
	case ELM_BIT: len=(len+7)/8; break;
        case ELM_FOREIGN: bp=(unsigned char *)p->c.ivec.iv[0]; break;
        case ELM_CHAR: case ELM_BYTE: break;
	case ELM_POINTER: error("binary vector expected"); break;
        case ELM_FLOAT: case ELM_INT: len<<=2; break;}
      putlength(s,len);
      writestr(s,bp,len);   }
    else error("invalid argument for VXW"); } }

pointer CALL_VXW(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ int i=0, j, argc=3, len, stat;
  pointer con=argv[0], entry=argv[1], result=argv[2];
  pointer in,out;
  pointer p,result_vec;
  numunion nu;
    
  if (!isiostream(con)) error(E_STREAM); 
  in=con->c.iostream.in; out=con->c.iostream.out;

  if (issymbol(entry)) entry=Getstring(entry);
  if (isstring(entry)) {
    writech(out, A_SYMBOL);
    writech(out, vecsize(entry));
    writestr(out, entry->c.str.chars, vecsize(entry));}
  else if (isint(entry)) {
    writech(out, A_LONG);
    putlong(out, intval(entry));}

  while (argc<n) {
    if (debug) { prinx(ctx,argv[argc],STDOUT); terpri(STDOUT);}
    putarg(out, argv[argc++]);}

  writech(out, A_END);

  if (result==K_INTEGER) writech(out, A_LONG);
  else if (result==K_FLOAT) writech(out, A_FLOAT);
  else {
    if (isarray(result))  result=result->c.ary.entity;
    if (isvector(result)) {
      writech(out, A_VECTOR);
      len=vecsize(result);
      if ((elmtypeof(result) == ELM_INT) || (elmtypeof(result) == ELM_FLOAT))
	len=len*sizeof(long);
      putlength(out,len);}
    else error(E_NOVECTOR);}
  flushstream(out);

  /*read protocol status*/
  stat=readch(in);
  if (stat!=NULL) return(cons(ctx,makeint(stat),NIL));

  /*read result*/
  if (result==K_INTEGER) 
    return(makeint(getlong(in)));
  else if (result==K_FLOAT) {
    nu.ival=getlong(in);
    return(makeflt(nu.fval));}
  else if (result==K_STRING) { }
  else { /*vector*/
    for (i=0; i<len; i++) result->c.str.chars[i]=readch(in);
    return(argv[2]);}
  }

vxwcom(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
  defun(ctx,"VXW",mod,CALL_VXW);}

