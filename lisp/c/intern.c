/****************************************************************/
/* EusLisp: intern.c
/*    intern a symbol in a package
/*    Copyright (c) 1989, Toshihiro MATSUI, Electrotechnical Laboratory
/*
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"

int export_all;

int rehash(str)
register pointer str;	/*string object*/
{ register int i,l,hash;
  register byte *id;
  id=str->c.str.chars;
  l=vecsize(str);
  hash=l;
  for (i=0; i<l; i++) hash+=(hash<<2)+id[i];
  return(hash & 0x1fffffff);}

pointer findsymbol(id,l,symvec,hashval)
byte *id;
int l,*hashval;
register pointer symvec;
{ register pointer sym,pnam;
  register int i,size,hash=l,flag=0;
  for (i=0; i<l; i++) hash+=(hash<<2)+id[i];
  hash&=0x1fffffff;
  size=vecsize(symvec);
  if (size==0) return(NULL);
  hash=hash % size;
  do {
    sym = symvec->c.vec.v[hash];
    if (issymbol(sym)) {
      pnam=sym->c.sym.pname;
      if (strlength(pnam)==l &&
	  !memcmp((char *)pnam->c.str.chars, (char *)id, l)) {
        *hashval=hash; return(sym);}}
    if (sym==makeint(0)) {
      if (flag==0) *hashval=hash;
      return(NULL);}
    if (sym==makeint(1) && flag==0) { flag=1; *hashval=hash;} 
    if (++hash>=size) hash=0;}
    while (1);}

static pointer extendsymvec(symvec)
pointer symvec;
{ register pointer newsymvec,sym;
  bpointer bp;
  register int i,newsize,size,hash;
    size=vecsize(symvec);
    bp=bpointerof(symvec);
#ifdef RGC
    newsize=buddysize[(bp->h.bix & TAGMASK)+1]-2;
#else
    newsize=buddysize[bp->h.bix+1]-2;
#endif
    newsymvec=makevector(C_VECTOR,newsize);
    for (i=0; i<newsize; i++) newsymvec->c.vec.v[i]=makeint(0); /*empty mark*/
    for (i=0; i<size; i++) {	/*rehash all symbols*/
      sym=symvec->c.vec.v[i];
      if (issymbol(sym)) {
        hash=rehash(sym->c.sym.pname) % newsize;
        while (newsymvec->c.vec.v[hash]!=makeint(0)) {	/*find an empty slot*/
          if (++hash>=newsize) hash=0;}
        pointer_update(newsymvec->c.vec.v[hash],sym);}}
#ifdef SAFETY
    take_care(newsymvec);
#endif
    return(newsymvec);}

pointer export(sym,pkg)
pointer sym,pkg;
{ register pointer symvec=pkg->c.pkg.symvector;	/*external symbol table*/
  register int size, newsymcount;
  int  hash;
  pointer usedby,usedbylist=pkg->c.pkg.used_by;
  pointer pnam,s;

  pnam=sym->c.sym.pname;
  usedby = (T);
  /*check symbol conflict in each of used-by packages*/
  while (usedby && iscons(usedbylist)) {
    usedby=ccar(usedbylist);
    usedbylist=ccdr(usedbylist);
    s=findsymbol(pnam->c.str.chars, strlength(pnam),
		 usedby->c.pkg.intsymvector, &hash);
    if (s && s!=sym)  error(E_SYMBOLCONFLICT,sym);}
  size=vecsize(symvec);
  hash=rehash(pnam) % size;
  while (1) {
    if (symvec->c.vec.v[hash]==sym) return(sym);
    if (isint(symvec->c.vec.v[hash])) {
      pointer_update(symvec->c.vec.v[hash],sym);
      newsymcount=intval(pkg->c.pkg.symcount)+1;
      pkg->c.pkg.symcount=makeint(newsymcount);
      if (newsymcount > (size / 2)) 
          pointer_update(pkg->c.pkg.symvector, extendsymvec(symvec));
      return(sym);}
    else if (++hash>=size) hash=0;}
  }

pointer intern(ctx,id,l,pkg)
register context *ctx;
char *id;	/*pointer to a string*/
int l;		/*l=strlen(id)*/
pointer pkg;	/*destination package*/
{ register pointer sym,symvec,newsym,uselist,use;
  register int i,size;
  int hash,newhash;

  if ((sym=findsymbol((byte *)id,l,pkg->c.pkg.intsymvector,&hash))) return(sym);
  uselist=pkg->c.pkg.use;
  while (islist(uselist)) { /*search in external symbols in inherited packages*/
    use=ccar(uselist);
    uselist=ccdr(uselist);
    if ((sym=findsymbol((byte *)id,l,use->c.pkg.symvector,&newhash))) return(sym);}
  /*create the symbol and insert it in the package*/
  symvec=pkg->c.pkg.intsymvector;
  size=vecsize(symvec);
  newsym=makesymbol(ctx,id,l,pkg);
  /*put it in the package*/
  while (issymbol(symvec->c.vec.v[hash]))  if (++hash>=size) hash=0;
  pointer_update(symvec->c.vec.v[hash],newsym);
  if (pkg==keywordpkg) {
    newsym->c.sym.vtype=V_CONSTANT;
    pointer_update(newsym->c.sym.speval,newsym);
    export(newsym,pkg);}
  l=intval(pkg->c.pkg.intsymcount)+1;
  pkg->c.pkg.intsymcount=makeint(l);
  if (l>(size/2)) { /*extend hash table*/
    vpush(newsym);
    pointer_update(pkg->c.pkg.intsymvector,extendsymvec(symvec));
    vpop();}
  /* export all the symbols to avoid incompatibility with old EusLisp*/
  if (export_all) export(newsym, pkg);
#ifdef SAFETY
  take_care(newsym);
#endif
  return(newsym); }


