/****************************************************************/
/* predicates.c
/*	1986-Jul 6, Copyright(C), T.Matsui
*****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"

extern pointer call1(context *, pointer, pointer);
extern pointer call2(context *, pointer, pointer, pointer);

pointer ATOM(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ ckarg(1);
  return(islist(argv[0])?NIL:T);}

pointer EQ(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ ckarg(2);
  return(argv[0]==argv[1]?T:NIL);}

pointer NILP(ctx,n,argv)
register context *ctx;
register int n;
register pointer *argv;
{ ckarg(1);
  return(argv[0]==NIL?T:NIL);}

pointer SYMBOLP(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ ckarg(1);
  return(issymbol(*argv)?T:NIL);}

pointer STRINGP(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ ckarg(1);
  return(isstring(*argv)?T:NIL);}

pointer LISTP(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer a=argv[0];
  ckarg(1);
  if (islist(a)) return(T);
  else if (a==NIL) return(T); 
  else return(NIL);}

pointer CONSP(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ ckarg(1);
  return(islist(argv[0])?T:NIL);}

pointer ENDP(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  if (argv[0]==NIL) return(T);
  else if (islist(argv[0])) return(NIL);
  else error(E_NOLIST);}

pointer NUMBERP(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ ckarg(1);
  if (isnum(argv[0]) || pisextnum(argv[0])) return(T);
  else return(NIL);}

pointer INTEGERP(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ ckarg(1);
  return(isint(argv[0])?T:NIL);}

pointer FLOATP(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ ckarg(1);
  return(isflt(argv[0])?T:NIL);}

pointer BOUNDP(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a=argv[0], vtp;
  ckarg(1);
  if (!issymbol(a)) error(E_NOSYMBOL);
  vtp=a->c.sym.vtype;
  if (SPEVALOF(a)==UNBOUND) return(NIL);
  else return(T);}

pointer FBOUNDP(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register pointer a=argv[0];
  ckarg(1);
  if (!issymbol(a)) error(E_NOSYMBOL);
  if (a->c.sym.spefunc==UNBOUND) return(NIL); else return(T);}

pointer STREAMP(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s=argv[0];
  ckarg(1);
  if (isstream(s) || isiostream(s)) return(T);
  else return(NIL);}

pointer superequal(x,y)	/* mutex_lock before call */
register pointer x,y;
{ register int i,n,xe;
  register eusinteger_t *cx,*cy;
  bpointer bx,by;
  pointer result;
  if (x==y) return(T);
  if (isnum(x) || isnum(y)) return(NIL);
  if (x->cix != y->cix) return(NIL);	/*different class*/
  if (pissymbol(x)) return(NIL);
    bx=bpointerof(x);
    by=bpointerof(y);
    if (bx->h.mark || by->h.mark) return(UNBOUND);	/*circular list*/
    xe=bx->h.elmtype;
    if (xe!=by->h.elmtype) return(NIL);	/*element type mismatch*/
    if (xe==ELM_FIXED || xe==ELM_POINTER) {
      bx->h.mark=by->h.mark=1;
      if (xe==ELM_POINTER) n=vecsize(x)+1;
      else n=objsize(x);
      for (i=0; i<n; i++) {
	result=superequal(x->c.obj.iv[i],y->c.obj.iv[i]);
	if (result!=T) {
	  bx->h.mark=by->h.mark=0;
	  return(result);} } 
      /*all elements matched*/
      bx->h.mark=by->h.mark=0;
      return(T);}
    else {
      n=vecsize(x);
      if (n!=vecsize(y)) return(NIL);	/*length mismatch*/
      cx=x->c.ivec.iv; cy=y->c.ivec.iv;
      switch(xe) {
	case ELM_BIT: n=(n+WORD_SIZE-1)/WORD_SIZE; break;
	case ELM_CHAR: case ELM_BYTE: n=(n+sizeof(eusinteger_t)-1)/sizeof(eusinteger_t); break;
	case ELM_FOREIGN: cx=(eusinteger_t *)(cx[0]); cy=(eusinteger_t *)(cy[0]); break;}
      for (i=0; i<n; i++) if (cx[i]!=cy[i]) return(NIL);
      return(T);}  }

pointer equal(x,y)
register pointer x,y;
{ register int i,n,xe;
  register eusinteger_t *cx,*cy;
  if (x==y) return(T);
  if (isnum(x) || isnum(y)) return(NIL);
  if (x->cix != y->cix) return(NIL);	/*different class*/
  if (pissymbol(x)) return(NIL);
  xe=elmtypeof(x);
  if (xe!=elmtypeof(y)) return(NIL);	/*element type mismatch*/
  /* foreign string is always not equal to normal string */
  if (xe==ELM_FIXED || xe==ELM_POINTER) {
    if (xe==ELM_POINTER) n=vecsize(x)+1;
    else n=objsize(x);
    for (i=0; i<n; i++)
      if (equal(x->c.obj.iv[i],y->c.obj.iv[i])!=T) return(NIL);
    return(T);}
  else {
    n=vecsize(x);
    if (n!=vecsize(y)) return(NIL);	/*length mismatch*/
    cx=x->c.ivec.iv; cy=y->c.ivec.iv;
    switch(xe) {
      case ELM_BIT: n=(n+WORD_SIZE-1)/WORD_SIZE; break;
      case ELM_CHAR: case ELM_BYTE: n=(n+sizeof(eusinteger_t)-1)/sizeof(eusinteger_t); break;
      case ELM_FOREIGN: cx=(eusinteger_t *)(cx[0]); cy=(eusinteger_t *)(cy[0]); break;}
    for (i=0; i<n; i++) if (cx[i]!=cy[i]) return(NIL);
    return(T);}  }

pointer EQUAL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  return(equal(argv[0],argv[1]));}

pointer SUPEREQUAL(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer result;
  ckarg(2);
#if THREADED
  mutex_lock(&mark_lock);
  mark_locking="SUPEREQUAL";
  result=superequal(argv[0],argv[1]);
  mutex_unlock(&mark_lock);
#else
  result=superequal(argv[0],argv[1]);
#endif
  if (result==UNBOUND) error(E_CIRCULAR);
  else return(result);}

void predicates(ctx,mod)
register context *ctx;
register pointer mod;
{ /* preds*/
  defun(ctx,"ATOM",mod,ATOM,NULL);
  QEQ=defun(ctx,"EQ",mod,EQ,NULL);
  QEQ=QEQ->c.sym.spefunc;
  defun(ctx,"EQL",mod,EQ,NULL);
  defun(ctx,"NULL",mod,NILP,NULL);
  QNOT=defun(ctx,"NOT",mod,NILP,NULL);
  QEQUAL=defun(ctx,"EQUAL",mod,EQUAL,NULL);
  defun(ctx,"SUPEREQUAL",mod,SUPEREQUAL,NULL);
  defun(ctx,"SYMBOLP",mod,SYMBOLP,NULL);
  defun(ctx,"STRINGP",mod,STRINGP,NULL);
  defun(ctx,"LISTP",mod,LISTP,NULL);
  defun(ctx,"CONSP",mod,CONSP,NULL);
  defun(ctx,"ENDP",mod,ENDP,NULL);
  defun(ctx,"NUMBERP",mod,NUMBERP,NULL);
  defun(ctx,"INTEGERP",mod,INTEGERP,NULL);
  defun(ctx,"FLOATP",mod,FLOATP,NULL);
  defun(ctx,"BOUNDP",mod,BOUNDP,NULL);
  defun(ctx,"FBOUNDP",mod,FBOUNDP,NULL);
  defun(ctx,"STREAMP",mod,STREAMP,NULL); }
