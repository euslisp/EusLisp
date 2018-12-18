/****************************************************************/
/* fast code for compiled execution:
/*	common error routines
/*  	global variable access
/*	car/cdr's
/*	catch/throw
/*	minilist to list up rest arguments
/*	Copyright(c) Toshihiro MATSUI, Electrotechnical Laboratory,1988.
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"

int maerror()
{ error(E_MISMATCHARG);}

pointer loadglobal(s)
register pointer s;
{ register pointer v;
  context *ctx;
  int vt;
  vt=intval(s->c.sym.vtype);
  if (vt>=3) { /*thread special*/
    ctx=euscontexts[thr_self()];
    v=spevalof(s,vt);
    if (v==UNBOUND) {
      v=s->c.sym.speval;
      if (v==UNBOUND)  error(E_UNBOUND,s);
      else return(v);}
    return(v);}
  v=s->c.sym.speval;
  if (v==UNBOUND) error(E_UNBOUND,s);
  else return(v);}

pointer storeglobal(s,v)
register pointer s,v;
{ pointer vt;
  int x;
  context *ctx;
  vt=s->c.sym.vtype;
  if (vt==V_CONSTANT) error(E_SETCONST);
  else if (vt>=V_SPECIAL) {
    ctx=euscontexts[thr_self()];
    x=intval(vt);
    pointer_update(spevalof(s,x), v);}
  else pointer_update(s->c.sym.speval, v);
  return(v);}

pointer xcar(p)
register pointer p;
{ if (iscons(p)) return(p->c.cons.car);
  if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer xcdr(p)
register pointer p;
{ if (islist(p)) return(p->c.cons.cdr);
  if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer xcadr(p)
register pointer p;
{ if (islist(p)) p=p->c.cons.cdr;
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);
  if (islist(p)) return(p->c.cons.car);
  else if (p==NIL) return(NIL);
  else error(E_NOLIST);}

pointer minilist(ctx,p,n)
register context *ctx;
register pointer *p;
register int n;
{ register pointer r=NIL;
  while (n-->0) r=cons(ctx,*--p,r);
  return(r);}

pointer restorecatch(ctx)
register context *ctx;
{ register struct catchframe *cfp=ctx->catchfp;
  ctx->vsp    = (pointer *)cfp;
  ctx->callfp = cfp->cf;
  ctx->bindfp = cfp->bf;
  ctx->catchfp= cfp->nextcatch;}

