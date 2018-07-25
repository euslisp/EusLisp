/****************************************************************/
/* LIST functions
/*	1988-July-7
/*	Copyright(C) Toshihiro Matsui, Electrotechnical Laboratory
/*	all rights reserved.
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"

extern pointer equal();
extern pointer call1(context *, pointer, pointer);
extern pointer call2(context *, pointer, pointer, pointer);

/* CAR/CDR combinations*/

pointer CAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ register pointer a=argv[0];
  ckarg(1);
  if (iscons(a)) return(ccar(a));
  if (a==NIL) return(NIL);
  error(E_NOLIST);}

pointer CDR(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ register pointer a=argv[0];
  ckarg(1);
  if (iscons(a)) return(ccdr(a));
  if (a==NIL) return(NIL);
  error(E_NOLIST);}

pointer CADR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer p=argv[0];
  ckarg(1);
  if (iscons(p)) p=ccdr(p);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (iscons(p)) return(ccar(p));
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer CDDR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer p=argv[0];
  ckarg(1);
  if (iscons(p)) p=ccdr(p);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (iscons(p)) return(ccdr(p));
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer CDAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer p=argv[0];
  ckarg(1);
  if (iscons(p)) p=ccar(p);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (iscons(p)) return(ccdr(p));
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer CAAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer p=argv[0];
  ckarg(1);
  if (iscons(p)) p=ccar(p);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (iscons(p)) return(ccar(p));
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer CADDR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer p=argv[0];
  ckarg(1);
  if (iscons(p)) p=ccdr(p);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (iscons(p)) p=ccdr(p);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (iscons(p)) return(ccar(p));
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer NTH(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ register int i;
  register pointer a=argv[1];
  ckarg(2);
  i=ckintval(argv[0]);
  if (i<0) error(E_NOINT);
  while (i-->0 && islist(a)) a=ccdr(a);
  if (islist(a)) return(ccar(a));
  else if (a==NIL) return(NIL);
  else error(E_NOLIST);}

pointer NTHCDR(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ register int i;
  register pointer a;
  ckarg(2);
  i=ckintval(argv[0]);
  a=argv[1];
  if (i<0) error(E_NOINT);
  if (a==NIL) return(NIL);
  else if (!islist(a)) error(E_NOLIST);
  while (i-->0 && islist(a)) a=ccdr(a);
  return(a);}

pointer CONS(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ ckarg(2);
  return(cons(ctx,argv[0],argv[1]));}

pointer RPLACA(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  ckarg(2);
  if (islist(a)) {pointer_update(ccar(a),argv[1]);}
  else error(E_NOLIST);
  return(a);}

pointer RPLACA2(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  ckarg(2);
  if (islist(a)) {pointer_update(ccar(a),argv[1]);}
  else error(E_NOLIST);
  return(argv[1]);}

pointer RPLACD(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  ckarg(2);
  if (islist(a)) {pointer_update(ccdr(a),argv[1]);}
  else error(E_NOLIST);
  return(a);}

pointer RPLACD2(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a=argv[0];
  ckarg(2);
  if (islist(a)) {pointer_update(ccdr(a),argv[1]);}
  else error(E_NOLIST);
  return(argv[1]);}

pointer LIST(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer result=NIL;
  while (n>0) result=cons(ctx,argv[--n],result);
  return(result);}

pointer LIST_STAR(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer result=argv[--n];
  while (n>0) result=cons(ctx,argv[--n],result);
  return(result);}

pointer APPEND(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a,r;
  register int i;
  if (n==0) return(NIL);
  r=argv[--n];
  while (n>0) {
    a=argv[--n];
    if (!islist(a) && a != NIL) error(E_NOLIST);
    i=0;
    while (islist(a)) { ckpush(ccar(a)); a=ccdr(a); i++;}
    while (i-->0) r=cons(ctx,vpop(),r);}
  return(r);}

pointer NCONC(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register pointer a,c;
  while (--n>=0) if (islist(argv[n])) goto nconc1;
  return(NIL);
nconc1:
  a=argv[n];
  while (--n>=0) {
    c=argv[n];
    if (islist(c)) {
      while (islist(ccdr(c))) { breakck; c=ccdr(c);}
      pointer_update(ccdr(c),a);
      a=argv[n];}
    }
  return(a);}

pointer subst(ctx,x,y,z)
register context *ctx;
register pointer x,y,z;
{ pointer temp;
  if (equal(y,z)==T) return(x);
  if (!islist(z)) return(z);
  temp=subst(ctx,x,y,ccar(z));
  vpush(temp);
  temp = subst(ctx,x,y,ccdr(z));
  return (cons(ctx,vpop(),temp));}

/* (subst new old list) */
pointer SUBST(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{
  ckarg(3);
  return(subst(ctx,argv[0],argv[1],argv[2]));}

pointer nsubst(x,y,z)
register pointer x,y, *z;
{ register pointer zz= *z;
  if (y==zz) pointer_update(*z,x);
  if (iscons(zz)) {
    nsubst(x,y,&(zz->c.cons.car));
    nsubst(x,y,&(zz->c.cons.cdr));} }

pointer NSUBST(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(3);
  nsubst(argv[0],argv[1],&argv[2]);
  return(argv[2]);}

pointer memq(item,list)
register pointer item,list;
{ while (iscons(list)) 
    if (ccar(list)==item) return(list);
    else list=ccdr(list);
  return(NIL);}

pointer MEMQ(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  return(memq(argv[0],argv[1]));}

pointer MEMBER(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer item=argv[0],list=argv[1],result;
  ckarg(2);
  while (islist(list)) {
    result=equal(ccar(list),item);
    if (result==T) return(list);
    else if (result==UNBOUND) error(E_CIRCULAR);
    else list=ccdr(list);}
  return(NIL);}

pointer SUPERMEMBER(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer item=argv[0],list=argv[1];
  pointer key=argv[2],test=argv[3],testnot=argv[4];
  register pointer target;
  eusinteger_t result;
  ckarg(5);
  while (islist(list)) {
    target=ccar(list);
    if (key!=NIL) target=call1(ctx,key,target);
    if (testnot!=NIL)  result=(call2(ctx,testnot,item,target)==NIL);
    else if (test==QEQUAL) {
      target=equal(item,target);
      if (target==UNBOUND) error(E_CIRCULAR);
      else result=(target!=NIL);}
    else if (test!=NIL) result=(call2(ctx,test,item,target)!=NIL);
    else result=(item==target);
    if (result) return(list);
    else list=ccdr(list);}
  return(NIL);}

pointer assq(item,alist)
register pointer item,alist;
{ register pointer temp;
  while (iscons(alist)) {
    temp=ccar(alist); 
    if (iscons(temp)) {
      if (ccar(temp)==item) return(temp);
      else alist=ccdr(alist);}
    else error(E_ALIST);}
  return(NIL);}

pointer ASSQ(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  return(assq(argv[0],argv[1])); }

pointer ASSOC(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer item=argv[0],alist=argv[1],temp,compare;
  ckarg(2);
  while (islist(alist)) {
    temp=ccar(alist);
    if (islist(temp)) {
      compare=equal(item,ccar(temp));
      if (compare==T) return(temp);
      else if (compare==UNBOUND) error(E_CIRCULAR);
      else alist=ccdr(alist);}
    else error(E_ALIST);}
  return(NIL);}

pointer SUPERASSOC(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer item=argv[0],alist=argv[1];
  pointer key=argv[2],test=argv[3],testnot=argv[4];
  register pointer temp,target;
  register eusinteger_t compare;
  ckarg(5);
  while (islist(alist)) {
    target=ccar(alist);
    if (islist(target)) {	/*ignore non-pair elements*/
      if (key==NIL) temp=ccar(target);
      else temp=call1(ctx,key,target);
      if (testnot!=NIL) compare=(call2(ctx,testnot,item,temp)==NIL);
      else if (test==NIL || test==QEQ) compare=(item==temp);
      else if (test==QEQUAL) compare=(equal(item,temp)==T);
      else compare=(call2(ctx,test,item,temp)!=NIL);
      if (compare) return(target);}
    alist=ccdr(alist);}
  return(NIL);}

pointer BUTLAST(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ register pointer a=argv[0];
  register int count=0;
  if (n==2) n=ckintval(argv[1]);
  else n=1;
  if (!iscons(a)) {
    if (a==NIL) return(NIL);
    else error(E_NOLIST); }
  if (n<0) error(E_USER,(pointer)"The second argument must be non-negative number");
  while (iscons(a)) { ckpush(ccar(a)); a=ccdr(a); count++;}
  n=min(count,n);
  ctx->vsp -= n;
  return((pointer)stacknlist(ctx,count-n));}

pointer NBUTLAST(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ register pointer a=argv[0], b;
  register int count=0;
  register pointer *vspsave=ctx->vsp;
  if (n==2) n=ckintval(argv[1]);
  else n=1;
  if (!iscons(a)) {
    if (a==NIL) return(NIL);
    else error(E_NOLIST); }
  if (n<0) error(E_USER,(pointer)"The second argument must be non-negative number");
  while (iscons(a)) { ckpush(a); a=ccdr(a); count++;}
  n=min(count,n);
  b= *(ctx->vsp - n - 1);
  pointer_update(ccdr(b),NIL);
  return(argv[0]);}



void lists(ctx,mod)
register context *ctx;
register pointer mod;
{ defun(ctx,"CAR",mod,CAR,NULL);
  defun(ctx,"CDR",mod,CDR,NULL);
  defun(ctx,"REST",mod,CDR,NULL);
  defun(ctx,"CADR",mod,CADR,NULL);
  defun(ctx,"CDDR",mod,CDDR,NULL);
  defun(ctx,"CDAR",mod,CDAR,NULL);
  defun(ctx,"CAAR",mod,CAAR,NULL);
  defun(ctx,"CADDR",mod,CADDR,NULL);
  defun(ctx,"NTH",mod,NTH,NULL);
  defun(ctx,"NTHCDR",mod,NTHCDR,NULL);
  defun(ctx,"CONS",mod,CONS,NULL);
  defun(ctx,"RPLACA",mod,RPLACA,NULL);
  defun(ctx,"RPLACA2",mod,RPLACA2,NULL);
  defun(ctx,"RPLACD",mod,RPLACD,NULL);
  defun(ctx,"RPLACD2",mod,RPLACD2,NULL);
  defun(ctx,"APPEND",mod,APPEND,NULL);
  defun(ctx,"NCONC",mod,NCONC,NULL);
  defun(ctx,"SUBST",mod,SUBST,NULL);
  defun(ctx,"NSUBST",mod,NSUBST,NULL);
/**/
  defun(ctx,"BUTLAST",mod,BUTLAST,NULL);
  defun(ctx,"NBUTLAST",mod,NBUTLAST,NULL);
  defun(ctx,"LIST",mod,LIST,NULL);
  defun(ctx,"LIST*",mod,LIST_STAR,NULL);
  defun(ctx,"MEMQ",mod,MEMQ,NULL);
  defun(ctx,"MEMBER",mod,MEMBER,NULL);
  defun(ctx,"SUPERMEMBER",mod,SUPERMEMBER,NULL);
  defun(ctx,"ASSQ",mod,ASSQ,NULL);
  defun(ctx,"ASSOC",mod,ASSOC,NULL);
  defun(ctx,"SUPERASSOC",mod,SUPERASSOC,NULL);
  }

