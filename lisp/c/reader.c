/****************************************************************/
/* euslisp reader
/*	Copyright (c) T.Matsui, Electrotechnical Laboratory
/*	1986-
/*	1987-Jan	dispatch macros
/*	1987-May	labeled expression #n= and #n#
/*	1988-July	multiple escape |...|
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include "eus.h"

#if !alpha
#define FALSE (0)
#define TRUE (1)
#endif

#define MAXTOKENLENGTH	1024
#define MAXSTRINGLENGTH 16384
#define to_upper(c) (islower(c) ? ((c)-'a'+'A') : (c))
#define to_lower(c) (isupper(c) ? ((c)-'A'+'a') : (c))

#define syntaxtype(ch) ((enum ch_type)(current_syntax[thr_self()][ch]))

extern pointer FEATURES,READBASE,QREADTABLE;
extern pointer QNOT, QAND, QOR;	/*eval_read_cond, Jan/1995*/

static pointer read1(context *, pointer);
static pointer read2(context *, pointer, int, int, int, char*, int);
extern pointer makelabref();

extern void mul_int_big();
extern pointer normalize_bignum();

/* the following two global variables are hazardous to multi-threads */
/* These should be eliminated in the next release. */
byte *current_syntax[MAXTHREAD];
pointer oblabels[MAXTHREAD];	/*keep labeled-objects in read*/

/****************************************************************/
/* character type table
/****************************************************************/

/*exported*/
enum ch_type chartype[256]={
	ch_illegal,	ch_illegal,	ch_illegal,	ch_illegal, /*0-3*/
	ch_illegal,	ch_illegal,	ch_illegal,	ch_illegal, /*4-7*/
	ch_constituent,	ch_white,	ch_white,	ch_illegal, /*8-b*/
	ch_white,	ch_white,	ch_illegal,	ch_illegal, /*c-f*/
	ch_illegal,	ch_illegal,	ch_illegal,	ch_illegal, /*10-13*/
	ch_illegal,	ch_illegal,	ch_illegal,	ch_illegal, /*14-17*/
	ch_illegal,	ch_illegal,	ch_illegal,	ch_illegal, /*18-1b*/
	ch_illegal,	ch_illegal,	ch_illegal,	ch_illegal, /*1c-1f*/
	ch_white,	ch_constituent,	ch_termmacro,	ch_nontermacro,   /*20-23*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_termmacro,   /*24-27*/
	ch_termmacro,	ch_termmacro,	ch_constituent,	ch_constituent, /*28-2b*/
	ch_termmacro,	ch_constituent,	ch_constituent,	ch_constituent, /*2c-2f*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*30-33*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*34-37*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_termmacro,    /*38-3b*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*3c-3f*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*40-43*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*44-47*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*48-4b*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*4c-4f*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*50-53*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*54-57*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*58-5b*/
	ch_sglescape,	ch_constituent,	ch_constituent,	ch_constituent, /*5c-5f*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*60-63*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*64-67*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*68-6b*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*6c-6f*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*70-73*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*74-77*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*78-7b*/
	ch_multiescape,	ch_constituent,	ch_constituent,	ch_constituent, /*7c-7f*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*80*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*90*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*a0*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*b0*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*c0*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*d0*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*e0*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, /*f0*/
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent, 
	ch_constituent,	ch_constituent,	ch_constituent,	ch_constituent};

enum ch_attr charattr[256]={
	illegal,	illegal,	illegal,	illegal,	/*0*/
	illegal,	illegal,	illegal,	illegal,
	illegal,	illegal,	illegal,	illegal,
	illegal,	illegal,	illegal,	illegal,
	illegal,	illegal,	illegal,	illegal,	/*10*/
	illegal,	illegal,	illegal,	illegal,
	illegal,	illegal,	illegal,	illegal,
	illegal,	illegal,	illegal,	illegal,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*20*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphadigit,	alphadigit,	alphadigit,	alphadigit,	/*30*/
	alphadigit,	alphadigit,	alphadigit,	alphadigit,
	alphadigit,	alphadigit,	package_marker,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*40*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*50*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*60*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*70*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*80*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*90*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*a0*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*b0*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*c0*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*d0*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*e0*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,	/*f0*/
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic,
	alphabetic,	alphabetic,	alphabetic,	alphabetic
        };

/****************************************************************/
/* euLisp READER						*/
/****************************************************************/
/*
/* reader primitives
*/
#if IRIX || Linux_ppc
#define Char int
#else
#if ARM
#define Char signed char
#else
#define Char char
#endif
#endif

static Char skip(ctx, f, ch)
context *ctx;
register pointer f;
Char ch;
{ skipblank:
  while (syntaxtype((char)ch)==ch_white) {
    ch=readch(f);
    if (ch==EOF) return(EOF);}
  if (ch == ';' && (Spevalof(QREADTABLE)->c.rdtab.macro->c.vec.v[ch]
		== charmacro[';'])) {
    /*syntax type for comment should be checked*/
    do {
      ch=readch(f);
      if (ch==EOF) return(EOF); }
      while(ch!='\n');
    goto skipblank;}  return(ch); }

static int nextch(ctx, f)
context *ctx;
register pointer f;
{ 
  Char ch;
  ch=readch(f); ch=skip(ctx, f,ch); return(ch);}


/****************************************************************/
/*  labeled expression (#n=, #n#)
/****************************************************************/

static pointer findlabel(labx)
eusinteger_t labx;
{ register pointer obj,labid;
  labid=makeint(labx);
  obj=oblabels[thr_self()]->c.lab.next;
  while (obj!=NIL) {
    if (obj->c.lab.label==labid) return(obj);
    else obj=obj->c.lab.next; }
  return(NIL);}

static pointer readlabdef(ctx,f,labx)
context *ctx;
pointer f;	/*stream*/
eusinteger_t labx;
{ pointer  unsol, *unsolp, result,newlab;

  if (findlabel(labx)!=NIL)  error(E_READLABEL,makeint(labx));	/*already defined*/
  newlab=(pointer)makelabref(makeint(labx),UNBOUND,oblabels[thr_self()]->c.lab.next);
  pointer_update(oblabels[thr_self()]->c.lab.next,newlab);
  result=read1(ctx,f);

  /*solve references*/
  pointer_update(newlab->c.lab.value,result);
  unsol=newlab->c.lab.unsolved;
  while (unsol!=NIL) {
#if sun3 || (!alpha && system5) || sanyo
    unsolp=(pointer *)unsol;
#endif
#if sun4 || vax || news || mips || alpha || i386
    unsolp=(pointer *)((eusinteger_t)unsol & ~3);/*???? */
#elif (WORD_SIZE == 64)
    unsolp=(pointer *)((eusinteger_t)unsol & ~3L);/*???? */
#endif
    unsol= *unsolp;
    pointer_update(*unsolp,result); }
  return(result);}

static void addunsolved(labp,addr)
pointer labp;
pointer *addr;
{ pointer_update(*addr,labp->c.lab.unsolved);
#if sun3 ||( !alpha && system5 ) || sanyo
  labp->c.lab.unsolved=(pointer)addr;
#endif
#if sun4 || vax || news || mips || alpha || i386 || x86_64 || ARM
  { eusinteger_t i;
    i=(((eusinteger_t)addr)>>2);
    labp->c.lab.unsolved=makeint(i);}
#endif
}

static pointer readlabref(ctx,f,val,subchar)
register context *ctx;
pointer f;
eusinteger_t val;
int subchar;
{ register pointer obj,element;
  obj=findlabel(val);
  if (obj==NIL) error(E_READLABEL,makeint(val));	/*undefined label*/
  if ((element=obj->c.lab.value)==UNBOUND) return(obj);
  else return(element);}


/****************************************************************/
/* read vector and object
/* #(, #v(, #f(, #i(, #j(
/****************************************************************/
static pointer readvector(ctx,f,size)
register context *ctx;
register pointer f;
register int size;
{ register pointer result,element;
  register int i=0;
  Char ch;
  ch=nextch(ctx,f);
  if (size>0) {
    result=makevector(C_VECTOR,size);
    vpush(result);
    while ((ch!=')') && (ch!=EOF) && (i<size)) {
      unreadch(f,ch);
      element=read1(ctx,f);
      if (islabref(element)) {	/*refer to undefined labeled obj*/
	addunsolved(element,&result->c.vec.v[i]); }
      else pointer_update(result->c.vec.v[i],element);
      i++;
      ch=nextch(ctx,f);}
    if (ch==')') 
      while (i<size) {pointer_update(result->c.vec.v[i],element);i++;}
    else {
      while (ch!=')' && ch!=EOF) ch=nextch(ctx,f);
      error(E_READ); }
    return(result);}
  else {
    while ((ch!=')') && (ch!=EOF)) {
      unreadch(f,ch);
      element=read1(ctx,f);
      ckpush(element);
      i++;
      ch=nextch(ctx,f);}
    result=makevector(C_VECTOR,i);
    while (i>0) {
      i--;
      element=vpop();
      if (islabref(element)) addunsolved(element,&result->c.vec.v[i]);
      else pointer_update(result->c.vec.v[i],element); }
    return(result); } }

static pointer readivector(ctx,s)
register context *ctx;
register pointer s;
{ register int i=0;
  register eusinteger_t x;
  register pointer elm;
  register pointer rvec;
  Char ch;
  ch=nextch(ctx,s);
  if (ch!='(') error(E_READFVECTOR);
  ch=nextch(ctx,s);
  while (ch!=')' && ch!=EOF) {
    unreadch(s,ch);
    elm=read1(ctx,s);
    x=ckintval(elm);
    ch=nextch(ctx,s);
    vpush(elm);
    i++;}
  rvec=makevector(C_INTVECTOR,i);
  while (i>0) {
    elm=vpop();
    x=bigintval(elm);
    rvec->c.ivec.iv[--i]=x;}
  return(rvec);}

static pointer readfvector(ctx,s)
register context *ctx;
register pointer s;
{ register int i=0,x;
  register pointer elm;
  eusfloat_t f;
  Char ch;
  numunion nu;

  ch=nextch(ctx,s);
  if (ch!='(') error(E_READFVECTOR);
  ch=nextch(ctx,s);
  while (ch!=')' && ch!=EOF) {
    unreadch(s,ch);
    elm=read1(ctx,s);
    if (!isnum(elm)) error(E_READFVECTOR);
    if (isint(elm)) { f=intval(elm); elm=makeflt(f);}
    ckpush(elm);
    i++;
    ch=nextch(ctx,s);}
  elm=makevector(C_FLTVECTOR,i);
  while (i>0) elm->c.fvec.fv[--i]=fltval(vpop());
  return(elm);}

static pointer readobject(ctx,s)
register context *ctx;
register pointer s;	/*input stream*/
{
  register pointer name, klass, elem, result;
  register eusinteger_t sz;
  register int i;
  Char ch;

  ch=nextch(ctx,s);
  if (ch!='(') error(E_READOBJECT);
  name=read1(ctx,s);
  if (!issymbol(name)) error(E_READOBJECT);
  klass=speval(name);
  if (klass==UNBOUND) error(E_NOCLASS,name);
  if (!isclass(klass)) error(E_READOBJECT);
  if (isvecclass(klass)) {
    elem=read1(ctx,s);
    if (!isint(elem)) error(E_READOBJECT);	/*vector size*/
    sz=intval(elem);
    result=makevector(klass,sz);
    i=1;}
  else if (isclass(klass)) {
    result=(pointer)makeobject(klass);
    i=0;}
  else error(E_NOCLASS,name);
  vpush(result);
  ch=nextch(ctx,s);
  while (ch!=')' && ch!=EOF) {
    unreadch(s,ch);
    elem=read1(ctx,s);
    if (islabref(elem)) {	/*refer to undefined labeled obj*/
	addunsolved(elem,&result->c.obj.iv[i++]); }
    else result->c.obj.iv[i++]=elem;
    ch=nextch(ctx,s);
    }
  vpop();
  return(result); }

static pointer readstructure(ctx,s)
register context *ctx;
register pointer s;	/*input stream*/
{ register pointer name, klass, slot, elem, result, varvec, *slotp;
  Char ch;

  ch=nextch(ctx,s);
  if (ch!='(') error(E_READOBJECT);
  name=read1(ctx,s);
  if (!issymbol(name)) error(E_READOBJECT);
  klass=speval(name);
  if (klass==UNBOUND) error(E_NOCLASS,name);
  if (!isclass(klass)) error(E_READOBJECT);
  if (isvecclass(klass)) { error(E_NOCLASS,name);}
  else if (isclass(klass)) result=(pointer)makeobject(klass);
  else error(E_NOCLASS,name);
  vpush(result);
  ch=nextch(ctx,s);
  while (ch!=')' && ch!=EOF) {
    unreadch(s,ch);
    slot=read1(ctx,s);
    if (!issymbol(slot)) error(E_NOSYMBOL);
    elem=read1(ctx,s);
    slotp=(pointer *)getobjv(slot,klass->c.cls.vars,result);
    if (slotp!=NULL) {
      if (islabref(elem)) {	/*refer to undefined labeled obj*/
	addunsolved(elem,slotp); }
      else pointer_update(*slotp,elem); }
    ch=nextch(ctx,s);
    }
  vpop();
  return(result); }

/****************************************************************/
/* read dispatch macro expression
/****************************************************************/
static pointer read_sharp_char(ctx,f,val,subchar)	/* #\ */
register context *ctx;
register pointer f;
eusinteger_t val;
int subchar;
{ char ch;
  ch=readch(f); return(makeint(ch));}

static pointer read_sharp_comment(ctx,f,val,subchar)	/* #| ... |# */
register context *ctx;
register pointer f;
register eusinteger_t val;
register int subchar;
{ Char ch;
  val=0;
  ch=readch(f);
 morecomments:
  while (ch!=subchar && ch!='#' && ch!=EOF) ch=readch(f);
  if (ch==EOF) return((pointer)EOF);
  if (ch==subchar) {
    ch=readch(f);
    if (ch=='#') { if (--val<0) return(UNBOUND);}
    goto morecomments;}
  ch=readch(f);
  if (ch==subchar)  { ch=readch(f); val++;}
  goto morecomments;}

static pointer read_sharp_hex(ctx,f,val,subchar)
register context *ctx;
register pointer f;
eusinteger_t val;
int subchar;
{ register int i=0,j,c,p,q;
  pointer b;
  eusinteger_t *bv,x;
  char ch, buf[WORD_SIZE];

  ch=readch(f);
  while (i<WORD_SIZE && isxdigit(ch)) { buf[i++] = ch; ch=readch(f);}
  unreadch(f,ch); buf[i]=0;
  j = i*4 - (buf[0]<'2' ? 3 :
             buf[0]<'4' ? 2 :
             buf[0]<'8' ? 1 : 0); /* alphabet is bigger than '9'*/
  if (j<WORD_SIZE-2) { sscanf(buf,"%lx",&val);  return(makeint(val));}
  else {
    b= (pointer)makebig((j+WORD_SIZE-2)/(WORD_SIZE-1));
    bv=bigvec(b);
    p=0;q=0;
    for (j=i-1; j>=0; j--) {
      c=toupper(buf[j]);
      x=(c<='9')?(c-'0'):(c-'A'+10);
      bv[p/(WORD_SIZE-1)] |= ((x << q) & MASK);
      if (q>=(WORD_SIZE-4) && (x>>(WORD_SIZE-1-q)))
        bv[p/(WORD_SIZE-1) + 1] = x>>(WORD_SIZE-1-q);
      p +=4; q = (q+4) % (WORD_SIZE-1);
      }
    b=(pointer)normalize_bignum(b);
    return(b);}
  }

static pointer read_sharp_octal(ctx,f,val,subchar)
register context *ctx;
pointer f;
eusinteger_t val;
int subchar;
{ register int i=0;
  char buf[WORD_SIZE/2], ch;
  ch=readch(f); val=0;
  while (i<WORD_SIZE/2 && ch>='0' && ch<'8') { buf[i++] = ch; ch=readch(f);}
  unreadch(f,ch); buf[i]=0;
  sscanf(buf,"%lo",&val);
  return(makeint(val));}

static pointer read_sharp_function(ctx,f,val,subchar)	/* #' */
register context *ctx;
pointer f;
eusinteger_t val;
int subchar;
{ return(cons(ctx,FUNCTION,cons(ctx,read1(ctx,f),NIL)));}

static pointer read_uninterned_symbol(ctx,f,val,subchar,token)	/* #: */
context *ctx;
pointer f;
eusinteger_t val;
int subchar;
char token[];
{ register int i=0;
  char ch;
  ch=readch(f);
  while (syntaxtype(ch)==ch_constituent) {
    token[i++]=to_upper(ch); ch=readch(f);}
  token[i]=0; unreadch(f,ch);
  return(makesymbol(ctx,(char *)token,i,NIL));}

static pointer read_sharp_eval(ctx,f)
register context *ctx;
pointer f;
{ pointer p;
  p=read1(ctx,f);
/*  if (debug) prinx(ctx,p,Spevalof(QSTDOUT)); */
  return(eval(ctx,p));}

static pointer eval_read_cond(ctx,expr)
context *ctx;
pointer expr;
{ pointer r;
  if (issymbol(expr)) return(memq(expr,speval(FEATURES)));
  if (iscons(expr)) {
    if (ccar(expr)==QNOT) {
      r=eval_read_cond(ctx,ccar(ccdr(expr)));
      return((r==NIL)?T:NIL);}
    else if (ccar(expr)==QAND) {
      expr=ccdr(expr);
      while (iscons(expr)) {
        r=eval_read_cond(ctx,ccar(expr));
	if (r==NIL) return(NIL);
        else expr=ccdr(expr);}
      return(T);}
    else if (ccar(expr)==QOR) {
      expr=ccdr(expr);
      while (iscons(expr)) {
        r=eval_read_cond(ctx,ccar(expr));
	if (r!=NIL) return(T);
        else expr=ccdr(expr);}
      return(NIL);}}
  error(E_USER,(pointer)"AND/OR/NOT expected in #+ or #-", expr);}

static pointer read_cond_plus(ctx,f)	/* #+ */
register context *ctx;
register pointer f;
{ register pointer flag,result;
  flag=read1(ctx,f);
  vpush(flag);
  result=read1(ctx,f);
  if (eval_read_cond(ctx,flag)==NIL) result=(pointer)UNBOUND;
  vpop();
  return(result);}

static pointer read_cond_minus(ctx,f)	/* #- */
register context *ctx;
register pointer f;
{ register pointer flag,result;
  flag=read1(ctx,f);
  vpush(flag);
  result=read1(ctx,f);
  if (eval_read_cond(ctx,flag)!=NIL) result=(pointer)UNBOUND;
  vpop();
  return(result);}

static pointer read_sharp_object(ctx,f)	/* #< */
register context *ctx;
register pointer f;
{ register pointer element,result,obj;
  register eusinteger_t val;
  Char ch;
  element=read1(ctx,f);
  if (!issymbol(element)) error(E_NOSYMBOL);  /*class name*/
  element=speval(element);
  if (element==UNBOUND || !isclass(element)) error(E_NOCLASS,element);
  obj=read1(ctx,f); val=ckintval(obj);
  result=makepointer(val);
  if (classof(result)!=element)
     error(E_TYPEMISMATCH, (pointer)"read #<> class mismatch");   /* ???? */
  ch=readch(f);
  while (ch!='>' && ch!=EOF) ch=readch(f);
  return(result);}

static pointer readsharp(ctx,f,ch,token)
register context *ctx;
register pointer f;
Char ch;
char token[];
{ register eusinteger_t val=0;
  register int i=0,subchar;
  pointer macrofunc,result;
  pointer (*intmac)();

  ch=readch(f);
  if (ch==EOF) return(UNBOUND);
  while (isdigit(ch)) { 
    val=val*10+ch-'0'; ch=nextch(ctx,f);
    if (ch==EOF) return(UNBOUND);}
  subchar=to_upper(ch);
  macrofunc=Spevalof(QREADTABLE)->c.rdtab.dispatch->c.vec.v[subchar];
  if (macrofunc==NIL) error(E_USER,(pointer)"no # macro defined");
  if (isint(macrofunc)) {	/*internal macro*/
    intmac=(pointer (*)())(intval(macrofunc));
    result=(*intmac)(ctx,f,val,subchar,token);}
  else {
    vpush(f); vpush(makeint(subchar)); vpush(makeint(val));
    result=ufuncall(ctx,macrofunc,macrofunc,(pointer)(ctx->vsp-3),NULL,3);
    ctx->vsp-=3;}
  return(result);}

static pointer readstring(ctx,f,terminator)
register context *ctx;
pointer f;
int terminator;
{ int tleng = 0, lengmax=MAXSTRINGLENGTH;      /* '"' is ignored */
  byte buf[MAXSTRINGLENGTH], *token, *newtoken;
  int ch, malloced=FALSE;
  pointer p;

  ch=readch(f);
  token=buf;
  while ((ch!=terminator) && (ch!=EOF)) {
    if (syntaxtype(ch) == ch_sglescape) ch=readch(f);     /*read escaped char*/
    token[tleng++]=ch;
    if (tleng >= lengmax) { /*allocate bigger string buffer*/
			    /*and copy the accumulated characters so far*/
      newtoken=(byte *)malloc(lengmax*2);
      memcpy(newtoken,token,tleng);
      if (malloced==TRUE) cfree(token);
      malloced=TRUE;
      token=newtoken; lengmax=lengmax*2;
      }
    ch=readch(f);}
  token[tleng] = '\0';
  p=makestring((char *)token,tleng);
  if (malloced==TRUE) cfree(token);
  return(p);
  }

static pointer readsymbol(ctx,leng,colon, token)
register context *ctx;
register int leng,colon;
char token[];
{ register pointer pkg;
  pointer pkgstr,sym;
  register int doublecolon=1;
  int hash;
  if (colon==0) pkg=keywordpkg;
  else if (colon>0) {
    if (charattr[token[colon-1]]==package_marker) {
      pkg=(pointer)searchpkg((byte *)token,colon-1);}
    else {
      doublecolon=0;
      pkg=(pointer)searchpkg((byte *)token,colon);}
    if (pkg==(pointer)NULL) {
      if (doublecolon) colon--;
      pkgstr=makestring(token,colon);
      vpush(pkgstr);
      error(E_NOPACKAGE,pkgstr);} }
  else pkg=Spevalof(PACKAGE);	/*use current package for symbol search*/
  colon++;  /*colon-th character starts symbol name string*/
  if (doublecolon) return(intern(ctx,&token[colon],leng-colon,pkg));
  else {
    sym=findsymbol((byte *)&token[colon],leng-colon, pkg->c.pkg.symvector, &hash);
/*    sym=findsymbol((char *)&token[colon],leng-colon, pkg->c.pkg.symvector, &hash);*/
    if (sym) return(sym);
    else {
      pkgstr=makestring(token,leng);
	fprintf(stderr,"%s ",token);
      vpush(pkgstr);
      error(E_EXTSYMBOL,pkgstr);}
  } }

/* news does not have strtol routine! */
#if news || sanyo
int strtol(str,ptr,base)
register char *str,**ptr;
register int base;
{ long val=0,sign=1;
  char ch;
  while (isspace(*str)) str++;
  ch= *str;
  if (ch=='+') str++; else if (ch=='-') { str++; sign= -1;}
  if (base<=10) {
    while ('0'<= *str && *str<('0'+base)) val=val*base+(*str++)-'0';
    return(sign*val);}
  else {
    while (1) {
      if ('0'<= *str && *str<='9') val=val*base+(*str++ -'0');
      else if ('A'<= *str && *str<('A'+base-10)) val=val*base+(*str++ - 'A'+10);
      else if ('a'<= *str && *str<('a'+base-10)) val=val*base+(*str++ - 'a'+10);
      else break;
      continue;}
    return(sign*val);}}
#endif

static pointer readint(ctx,token,len)
context *ctx;
char *token;
int len;
{ eusinteger_t base=intval(Spevalof(READBASE));
  int head,i,sign=1, k;
  pointer b;

  if (len<8) {
    i=strtol(token,NULL,base);
    return(makeint(i));}
  else {
    if (token[0]=='+') { head=1;}
    else if (token[0]=='-') {head=1; sign= -1;}
    else head=0;
    b=(pointer)makebig1(0);
    vpush(b);
    for (i=head; i<len; i++) {
      k= (int) token[i];
      if (k>='0' && k<='9') k= k-'0';
      else if (k>='A' && k<='Z') k=k-'A'+10;
      else if (k>='a' && k<='z') k=k-'a'+10;
      else if (k=='.') continue;
      else error(E_USER,(pointer)"illegal integer consituent char");
      mul_int_big(base,b);
      add_int_big(k,b);  }
    if (sign<0) complement_big(b);
    b=(pointer)normalize_bignum(b);
    }
  ctx->lastalloc= vpop();
  return(b);}

int is_digit(ch,base)
register int ch,base;
{ if (ch<'0') return(FALSE);
  if (base<=10)
    if (ch<'0'+base) return(TRUE);
    else return(FALSE);
  else if (ch<='9') return(TRUE);
  else if ('A'<=ch && ch<'A'+base-10) return(TRUE);
  else return(FALSE);}

pointer read_delimited_list(ctx,f,delim_char,token)
register context *ctx;
pointer f;
int delim_char;
char token[];
{ pointer result=NIL;
  pointer temp,element;
  Char ch;
  ch=nextch(ctx,f);
  vpush(STOPPER);	/*marker*/
  while (ch!=delim_char && ch!=EOF) {
    if (ch=='.') {
      ch=readch(f); unreadch(f,ch);
      if (syntaxtype(ch)==ch_constituent) {
	token[0]='.';
	element=read2(ctx,f,0,0,1,token, -1);}
      else if (syntaxtype(ch)==ch_white) {
	result=read1(ctx,f);
	ch=nextch(ctx,f);
	if (ch!=delim_char) error(E_READ);
	break;}
      else error(E_READ);}
    else { unreadch(f,ch);  element=read1(ctx,f);}
    if (element!=UNBOUND && element!=(pointer)EOF) ckpush(element);
    ch=nextch(ctx,f);}
  while ((element=vpop())!=STOPPER) {
    temp=cons(ctx,element,result);
    if (islabref(element)) addunsolved(element,&temp->c.cons.car);
    if (islabref(result)) addunsolved(result,&temp->c.cons.cdr);
    result=temp;}
  return(result); }

static pointer readlist(ctx,f,ch,token)
register context *ctx;
pointer f;
char ch, token[];
{ return(read_delimited_list(ctx,f,')',token));}

static pointer readquote(ctx,f)
register context *ctx;
pointer f;
{ pointer q;
  q=read1(ctx,f);
  if (q==(pointer)EOF) return((pointer)EOF);
  return(cons(ctx,QUOTE,cons(ctx,q,NIL)));}

static pointer readcomment(ctx,f)
register context *ctx;
pointer f;
{ register Char ch;
  do { ch=readch(f);} while (ch!='\n' && ch!=EOF);
  return(UNBOUND);}

static pointer readrparen(ctx,f)
register context *ctx;
pointer f;
{ return(UNBOUND);}



int gcd(u,v)
register int u,v;
{ register int t;
  if(u<0) u = -u;
  if(v<0) v = -v;
  if(u<v) {t=u; u=v; v=t;}
  while(v!=0){t=u % v; u=v; v=t;}
  return(u);}

static pointer readratio(ctx,token,slash)
context *ctx;
char *token;
int slash;
{ int num, denom, g;
  extern pointer makeratio();
  num=strtol(token,NULL,intval(Spevalof(READBASE)));
  denom=strtol(&token[slash+1],NULL,intval(Spevalof(READBASE)));
  g=gcd(num, denom);
  if (g!=0) { num /= g; denom /= g;}
  else return(makeint(0));
  if (denom==1) return(makeint(num));
  return(makeratio(num, denom));}


static pointer read2(ctx,ins,escaped,multiescaped,i,token,colon)
register context *ctx;
register pointer ins;
int escaped,multiescaped,i;
char token[];
int colon;
{ register int j,c;
  register eusinteger_t base;
  int slash;
  enum ch_type ctype;
  /*Char ch;*/
  int ch;
  pointer readcase; 
  numunion nu;
  extern double atof();
  
  readcase=Spevalof(QREADTABLE)->c.rdtab.readcase;

  if (multiescaped) goto step9;
 step8:
    if (i>=MAXTOKENLENGTH) error(E_LONGSTRING);
    ch=readch(ins);
    if (ch==EOF) goto step10;
    if (ch<0) ch &= 0xff;
    ctype=syntaxtype(ch);
    switch(ctype) {
      case ch_constituent: case ch_nontermacro:
	if (charattr[ch]==package_marker) colon=i;
 	if (readcase==K_DOWNCASE) ch=to_lower(ch);
	else if (readcase==K_PRESERVE) ch=ch;
	else  ch=to_upper(ch);
	token[i++]=ch; goto step8;
      case ch_sglescape:
	token[i++]=readch(ins); escaped=1; goto step8;
      case ch_multiescape:
	goto step9;
      case ch_illegal:
	error(E_ILLCH,makeint(ch)); break;
      case ch_termmacro:
	unreadch(ins,ch); goto step10;
      case ch_white:
	unreadch(ins,ch); goto step10;
      default: error(E_USER,(pointer)"unknown char type");}
 step9:
    escaped=1;
    if (i>=MAXTOKENLENGTH) error(E_LONGSTRING);
    ch=readch(ins);
    if (ch==EOF) error(E_EOF);
    ch &= 0xff;
    ctype=syntaxtype(ch);
    switch(ctype) {
      case ch_constituent: case ch_white:
      case ch_nontermacro: case ch_termmacro:
	token[i++]=ch; goto step9;
      case ch_sglescape:
	ch=readch(ins); token[i++]=ch; goto step9;
      case ch_multiescape:
	goto step8;
      default: error(E_ILLCH,makeint(ch));}
 step10:
    /*token is accumulated; analyze syntax*/
    token[i]=0;
    if (escaped) return(readsymbol(ctx,i,colon,token));
    base=intval(Spevalof(READBASE));

    j=0;
    if ((token[j]=='+') || (token[j]=='-')) j++;
    else if (token[j]=='.' && token[j+1]=='\0')
      return(readsymbol(ctx,i,colon,token));
    if (is_digit(token[j],base) || token[j]=='.') {
      while (is_digit(token[j],base)) j++;
      if (token[j] == '.') {	/*float?*/
        if (++j==i) return(readint(ctx,token,i));
        /*float or symbol*/
        while (is_digit(token[j],base)) j++;
        c=to_upper(token[j]);
        if (c=='E' || c=='D' || c=='F' || c=='L') {
	  c=j;  j++;
          if ((token[j]=='+') || (token[j]=='-')) j++;
          while (is_digit(token[j],base)) j++;
          if (j==i) { token[c]='E'; return(makeflt(atof(token)));}
          else return(readsymbol(ctx,i,colon,token));}
        else if (j==i) return(makeflt(atof(token)));
        else return(readsymbol(ctx,i,colon,token));}
      else if (token[j] == '/') {  /* ratio? */
        slash=j;
        if (++j==i) return(readsymbol(ctx,i,colon,token));
        /*ratio or symbol*/
        while (is_digit(token[j],base)) j++;
        if (j==i) return(readratio(ctx,token,slash));
        else return(readsymbol(ctx,i,colon,token));}
      else if (j==i) return(readint(ctx,token,i));
      else {
        c=to_upper(token[j]);
        if (c=='E' || c=='D' || c=='F' || c=='L') {
	  c=j;  j++;
          if ((token[j]=='+') || (token[j]=='-')) j++;
          while (is_digit(token[j],base)) j++;
          if (j==i) {/*all digits*/ token[c]='E'; return(makeflt(atof(token)));}
          else return(readsymbol(ctx,i,colon,token));}
        else if (j==i) return(makeflt(atof(token)));
	else return(readsymbol(ctx,i,colon,token));} }
    else return(readsymbol(ctx,i,colon,token));}

static pointer read1(ctx,ins)
register context *ctx;
register pointer ins;
{ register enum ch_type ctype;
  register int firstch;
  register pointer macrofunc,result;
  pointer (*intmac)();
  int colon;
/*  Char ch; */
  int ch;
  char token[MAXTOKENLENGTH];
  pointer readcase;

  colon= -1;
  step1:
    ch=readch(ins);
    if (ch==EOF) return((pointer)EOF);
    ch &= 0xff;
    firstch=ch;
    ctype=syntaxtype(ch);
    switch(ctype) {
      case ch_illegal: error(E_ILLCH,makeint(ch));
      case ch_white: goto step1;
      case ch_termmacro: case ch_nontermacro:
	      macrofunc=Spevalof(QREADTABLE)->c.rdtab.macro->c.vec.v[ch];
	      if (macrofunc==NIL) error(E_USER,(pointer)"no char macro defined");
	      if (isint(macrofunc)) {	/*internal macro*/
		intmac=(pointer (*)())(intval(macrofunc));
	        result=(*intmac)(ctx,ins,ch,token);}
	      else {
	        vpush(ins); vpush(makeint(ch));
	        result=ufuncall(ctx,macrofunc,macrofunc,(pointer)(ctx->vsp-2),NULL,2);
	        ctx->vsp-=2;}
/*	      if (result==UNBOUND && firstch!=')') goto step1;
	      else return(result);*/
	      return(result);
      case ch_sglescape: token[0]=readch(ins);
			 return(read2(ctx,ins,1,0,1,token,colon));
      case ch_multiescape: return(read2(ctx,ins,1,1,0,token,colon));
      case ch_constituent:
	      if (charattr[ch]==package_marker) colon=0;
	      readcase=Spevalof(QREADTABLE)->c.rdtab.readcase;
	      if (readcase==K_DOWNCASE) ch=to_lower(ch);
	      else if (readcase==K_PRESERVE) ch=ch;
	      else  ch=to_upper(ch);
	      token[0]= ch;
	      return(read2(ctx,ins,0,0,1,token,colon));}}

pointer reader(ctx,f,recursivep)
register context *ctx;
register pointer f,recursivep;
{ register pointer val;
  Char ch;
  current_syntax[thr_self()]=Spevalof(QREADTABLE)->c.rdtab.syntax->c.str.chars;
  ch=nextch(ctx,f);
  if (ch==EOF) return((pointer)EOF);
  while (ch==')') ch=nextch(ctx,f);
  unreadch(f,ch);
  if (recursivep==NIL) {
    pointer_update(oblabels[thr_self()]->c.lab.next,NIL);
    val=read1(ctx,f);
    pointer_update(oblabels[thr_self()]->c.lab.next,NIL);}
  else val=read1(ctx,f);	/*if called recursively, keep #n= scope*/
  if (val==UNBOUND) return(NIL);
  return(val);}

void initreader(ctx)
register context *ctx;
{ register pointer rdtable;
  register int i;

  charmacro['(']=makeint((eusinteger_t)readlist);
  charmacro[')']=makeint((eusinteger_t)readrparen);
  charmacro['#']=makeint((eusinteger_t)readsharp);
  charmacro['\'']=makeint((eusinteger_t)readquote);
  charmacro['"']=makeint((eusinteger_t)readstring);
  charmacro[';']=makeint((eusinteger_t)readcomment);

  sharpmacro['\\']=makeint((eusinteger_t)read_sharp_char);
  sharpmacro['\'']=makeint((eusinteger_t)read_sharp_function);
  sharpmacro[':']=makeint((eusinteger_t)read_uninterned_symbol);
  sharpmacro[',']=makeint((eusinteger_t)read_sharp_eval);
  sharpmacro['.']=makeint((eusinteger_t)read_sharp_eval);
  sharpmacro['|']=makeint((eusinteger_t)read_sharp_comment);
  sharpmacro['+']=makeint((eusinteger_t)read_cond_plus);
  sharpmacro['-']=makeint((eusinteger_t)read_cond_minus);
  sharpmacro['#']=makeint((eusinteger_t)readlabref);
  sharpmacro['=']=makeint((eusinteger_t)readlabdef);
  sharpmacro['(']=makeint((eusinteger_t)readvector);
  sharpmacro['<']=makeint((eusinteger_t)read_sharp_object);
  sharpmacro['X']=makeint((eusinteger_t)read_sharp_hex);
  sharpmacro['O']=makeint((eusinteger_t)read_sharp_octal);
  sharpmacro['S']=makeint((eusinteger_t)readstructure);
  sharpmacro['F']=makeint((eusinteger_t)readfvector);
  sharpmacro['I']=makeint((eusinteger_t)readivector);
  sharpmacro['J']=makeint((eusinteger_t)readobject);
  sharpmacro['V']=makeint((eusinteger_t)readobject);

  /* make default readtable */
  rdtable=(pointer)makereadtable(ctx);
  pointer_update(Spevalof(QREADTABLE),rdtable);
  for (i=0; i<256; i++) {
    rdtable->c.rdtab.syntax->c.str.chars[i]=(int)chartype[i];
    rdtable->c.rdtab.macro->c.vec.v[i]=charmacro[i];
    rdtable->c.rdtab.dispatch->c.vec.v[i]=sharpmacro[i];
    rdtable->c.rdtab.readcase=K_UPCASE;
    }
  }
