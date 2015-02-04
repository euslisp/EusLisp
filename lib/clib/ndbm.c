/* ndbm -- ndbm compatibility library in the GNU data base manager, gdbm
	January 2000
	(c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
	cc -c -I/usr/local/eus/include -fpic  ndbm.c ; cc -o ndbm.so -shared ndbm.o
*/

#include <ndbm.h>
#include "eus.h"

pointer DBM_OPEN(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ DBM *dbm;
  ckarg(3);
  dbm=dbm_open(Getstring(argv[0])->c.str.chars,
	       ckintval(argv[1]),
	       ckintval(argv[2]));
  return(makeint(dbm));}

pointer DBM_CLOSE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  dbm_close(ckintval(argv[0]));
  return(T);}

pointer DBM_FETCH(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s;
  datum key,content;
  ckarg(2);
  s=Getstring(argv[1]);
  key.dptr=(char *)(s->c.str.chars);
  key.dsize=strlength(s);
  content=dbm_fetch(ckintval(argv[0]), key);
  if (content.dptr==NULL) return(NIL);
  return(makestring(content.dptr,content.dsize));}

pointer DBM_STORE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s;
  datum key,content;
  ckarg(4);
  s=Getstring(argv[1]);
  key.dptr=(char *)s->c.str.chars;
  key.dsize=strlength(s);
  s=Getstring(argv[2]);
  content.dptr=(char *)s->c.str.chars;
  content.dsize=strlength(s);
  n=dbm_store(ckintval(argv[0]), key, content, ckintval(argv[3]));
  return((n==0)?T:NIL);}

pointer DBM_DELETE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer s;
  datum key;
  ckarg(2);
  s=Getstring(argv[1]);
  key.dptr=(char *)s->c.str.chars;
  key.dsize=strlength(s);
  n=dbm_delete(ckintval(argv[0]), key);
  return((n==0)?T:NIL);}

pointer DBM_FIRSTKEY(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ datum key;
  ckarg(1);
  key=dbm_firstkey(ckintval(argv[0]));
  if (key.dptr==NULL) return(NIL);
  return(makestring(key.dptr,key.dsize));}

pointer DBM_NEXTKEY(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ datum key;
  ckarg(1);
  key=dbm_nextkey(ckintval(argv[0]));
  if (key.dptr==NULL) return(NIL);
  return(makestring(key.dptr,key.dsize));}

pointer DBM_ERROR(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  n=dbm_error((DBM *)ckintval(argv[0]));
  return((n==0)?T:NIL);}

pointer DBM_CLEARERR(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  dbm_clearerr((DBM *)ckintval(argv[0]));
  return(T);}


ndbm(context *ctx, int n, pointer argv[])
{ pointer mod=argv[0];
  defun(ctx,"DBM-OPEN",mod,DBM_OPEN,NULL);
  defun(ctx,"DBM-CLOSE",mod,DBM_CLOSE,NULL);
  defun(ctx,"DBM-FETCH",mod,DBM_FETCH,NULL);
  defun(ctx,"DBM-STORE",mod,DBM_STORE,NULL);
  defun(ctx,"DBM-DELETE",mod,DBM_DELETE,NULL);
  defun(ctx,"DBM-FIRSTKEY",mod,DBM_FIRSTKEY,NULL);
  defun(ctx,"DBM-NEXTKEY",mod,DBM_NEXTKEY,NULL);
  defun(ctx,"DBM-ERROR",mod,DBM_ERROR,NULL);
  defun(ctx,"DBM-CLEARERR",mod,DBM_CLEARERR,NULL);
  }

