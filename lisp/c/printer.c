/****************************************************************/
/* printer.c --- euslisp printer
/* Copyright(c) 1986, Toshihiro MATSUI, Electrotechnical Laboratory
/*
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include <ctype.h>
#include "eus.h"

#define g_marked(p) (bpointerof(p)->h.mark)
#define s_marked(p) (bpointerof(p)->h.smark)
#define p_marked(p) (bpointerof(p)->h.pmark)
#define g_mark_on(p) (bpointerof(p)->h.mark=1)
#define s_mark_on(p) (bpointerof(p)->h.smark=1)
#define p_mark_on(p) (bpointerof(p)->h.pmark=1)
#define g_mark_off(p) (bpointerof(p)->h.mark=0)
#define s_mark_off(p) (bpointerof(p)->h.smark=0)
#define p_mark_off(p) (bpointerof(p)->h.pmark=0)
#define to_upper(c) (islower(c) ? ((c)-'a'+'A') : (c))
#define to_lower(c) (isupper(c) ? ((c)-'A'+'a') : (c))

extern pointer PRCIRCLE,PROBJECT,PRSTRUCTURE,PRCASE,PRLENGTH,PRLEVEL,PRINTBASE;
extern pointer QREADTABLE;
extern pointer K_PRIN1;
static void prin1(context *, pointer, pointer, int);

static pointer *ixvec;
static int ix;
static char ixbuf[16];
extern enum ch_type chartype[256];
extern enum ch_attr charattr[256];

static void print_symbol_prefix(ctx,f,pkg,colon)
context *ctx;
register pointer f,pkg;
char *colon;
{ register pointer pkgname;
  register int l;
  byte *s, c;
  pkgname=ccar(pkg->c.pkg.names);
  l=strlength(pkgname);
  s=pkgname->c.str.chars;
  if (Spevalof(PRCASE)==K_DOWNCASE) 
    while (l-->0) { c= *s++; writech(f,to_lower(c));}
  else while (l-->0) { writech(f,*s++);}
  writestr(f,(byte *)colon,strlen(colon));}


static void symprefix(sym,f)
register pointer sym,f;
{ register int l,c;
  register byte *s;
  register pointer pkg,pkgname,pkgs,pnam;
  register pointer cursym;
  int hash;
  context *ctx=euscontexts[thr_self()];
  pointer curpkg;

  curpkg=Spevalof(PACKAGE);
  pkg=sym->c.sym.homepkg;
  pnam=sym->c.sym.pname;
  if (pkg==curpkg) return;
  if (pkg==NIL) { writestr(f,(byte *)"#:",2); return;}
  if (pkg==keywordpkg) { writech(f,':'); return; }
  else if ((cursym=findsymbol(pnam->c.str.chars, strlength(pnam),
			curpkg->c.pkg.intsymvector, &hash))==NULL) {
    pkgs=curpkg->c.pkg.use;
    while (islist(pkgs)) 
      if (pkg==ccar(pkgs)) 	/*the home pkg is in use-list*/
	if (sym==findsymbol(pnam->c.str.chars, strlength(pnam),
			ccar(pkgs)->c.pkg.symvector, &hash))
	  return; /*found in external symbols*/
	else { print_symbol_prefix(ctx,f,ccar(pkgs),"::"); return;}
      else pkgs=ccdr(pkgs); }
  else if (sym==cursym) return;
  /* the home package is not used by the current *PACKAGE* */
  if (findsymbol(pnam->c.str.chars, strlength(pnam), pkg->c.pkg.symvector, &hash)) 
	/* external symbol in the home package?*/
    print_symbol_prefix(ctx,f,pkg,":");
  else print_symbol_prefix(ctx,f,pkg,"::"); }
        
static pointer printsym(ctx,sym,f)
context *ctx;
register pointer sym;
register pointer f;
{ register unsigned char *s;
  pointer pnm;
  register int i,l,c,down,escape=0,alldigits=1;
  int base=intval(Spevalof(PRINTBASE));
  byte b[256];

  symprefix(sym,f);
  pnm=sym->c.sym.pname;
  if (!isstring(pnm)) {
    printf("printsym: illegal pname %p\n",pnm);
    return(sym);}
  l=vecsize(pnm);
  s=pnm->c.str.chars;
  down=(Spevalof(PRCASE)==K_DOWNCASE);
  if (!ctx->slashflag) {
    for (i=0; i<l; i++) {
      c=s[i];
      if (chartype[c]!=ch_constituent || islower(c)) { escape=1; break;}
      else if (charattr[c]==package_marker || c=='`') {escape=1; break;}
      else if (Spevalof(QREADTABLE)->c.rdtab.macro->c.vec.v[c] != NIL) 
	{escape=1; break;};
      if (!is_digit(c,base)) alldigits=0;}
    if ((escape=(escape | alldigits))) writech(f,'|');}
  while (l>0) {
    i=0;
    if (!ctx->slashflag) {
      while (i<l && i<256) {
	c= *s++;
	if (chartype[c]==ch_multiescape) b[i++]='\\';
	b[i++]=((!escape && down)?to_lower(c):c);
        l--;}
      writestr(f,b,i);}
    else 
      if (down) { /*convert to lower*/
        while (i<l && i<256) { c= *s++; b[i++]=to_lower(c);}
        writestr(f,b,i);
        l-=i;}
      else { writestr(f,s,l); l=0;}
    }
  if (escape) writech(f,'|');
  return(sym);}

static void printstr(ctx,leng,str,f)
context *ctx;
register int leng;
register byte *str;
register pointer f;
{ if (!ctx->slashflag) {
    writech(f,'"');
    while (leng-->0) {
      if (*str=='"' || *str=='\\') writech(f,'\\'); /*escape char*/
      writech(f,*str++);}
    writech(f,'"');}
  else writestr(f,str,leng);}

/****************************************************************
/* printing numbers
/* num ----+-->  fixnum
/*	   +-->  float
/*         +-->  big
/*         +-->  ratio
/****************************************************************/

void printint(ctx,num,f,base, field1, field2)	/*print fixnum*/
context *ctx;
register eusinteger_t num;
register pointer f;
int base, field1, field2;
{ char work[65];	/*enough for 64 binary digits + sign*/
  register int i=65,digit,sign,j;
  int downcase;

  downcase= (Spevalof(PRCASE)==K_DOWNCASE);
  if (num<0) { sign= -1; num= -num;} else sign=0;
  do {
#if (WORD_SIZE == 64)
    digit= (unsigned long)num % base;
    num=(unsigned long)num / base;
#else
    digit= (unsigned)num % base;
    num=(unsigned)num / base;
#endif
    if (base<=10 || digit<10) work[--i]='0'+digit;
    else if (downcase) work[--i]='a'+digit-10;
    else work[--i]='A'+digit-10;}
    while (num);
  if (sign) {
    if (field2> 65-i+1) j=field1-field2; else j=field1-(65-i+1);}
  else {
    if (field2> 65-i) j=field1-field2; else j=field1-(65-i);}
  while (j-- >0) writech(f,' ');
  if (sign) writech(f, '-');
  j=field2-(65-i);
  if (sign) j--;
  while (j-- >0) writech(f,'0');
  writestr(f,(byte *)&work[i],65-i);
  }

static pointer printflt(num,f)
double num;
pointer f;
{ char work[20];
  double absnum,fraction;
  register int i,len,intpart;
  extern double fabs();

  if (num==0.0) writestr(f,(byte *)"0.0",3);
  else {
    absnum=fabs(num);
    if ((absnum<0.0001) || (absnum>1.0e+05)) {
      sprintf(work,"%1.6e",num); len=strlen(work);}
    else {
      intpart=absnum;	/*truncate*/
      fraction=absnum-intpart;
      if (intpart<1) i=6;
      else if (intpart<10) i=5;
      else if (intpart<100) i=4;
      else if (intpart<1000) i=3;
      else if (intpart<10000) i=2;
      else i=1;
      sprintf(work,"%1.*f",i,num);
      len=strlen(work);
      while (len>2 && work[len-1]=='0' && work[len-2]!='.') len--;} 
    writestr(f,(byte *)work,len); }}

static void printhex(val,f)
int val;
pointer f;
{ char work[20];
  sprintf(work,"#x%x",val);
  writestr(f,(byte *)work,strlen(work));}

static void printratio(ctx,rat,f, base)
context *ctx;
pointer rat,f;
int base;
{ printnum(ctx,rat->c.ratio.numerator,f,base,0,0);
  writech(f,'/');
  printnum(ctx,rat->c.ratio.denominator,f,base,0,0);
  }

extern pointer big_minus(), copy_big();

static void printbig(ctx, big, f, base, field1,field2)
context *ctx;
pointer big,f;
int base, field1,field2;
{ pointer bv,p;
  eusinteger_t *b, d, sign; long digits=0;
  int i, x;
  int downcase;
  extern eusinteger_t big_sign(), div_int_big();

  downcase=(Spevalof(PRCASE)==K_DOWNCASE);
  sign=big_sign(big);
  if (sign<0) big=big_minus(big);
  else big=copy_big(big);
  vpush(big);

  bv=big->c.bgnm.bv;  
  b=bv->c.ivec.iv;

  while (!big_zerop(big)) {
    d=div_int_big(base,big);
    p=makeint(d);
    ckpush(p);
    digits++;}
  
  if (field2<digits) i=field1-digits; else i=field1-field2;
  if (sign<0) i--;
  while (i-- > 0) writech(f, ' ');
  if (sign<0) writech(f, '-');
  i=field2-digits;
  if (sign<0) i--;
  while (i-- > 0) writech(f,'0');

  while (digits-- > 0) {
    p=vpop();
    x=intval(p);
    if (x>=10) {
      if (downcase) x=x+'a'-10;
      else x=x+'A'-10;}
    else x=x+'0';
    writech(f,x);}
  vpop();
  }

void printnum(ctx, nump, strm, base, field1, field2)
context *ctx;
pointer nump, strm;
int base;
int field1, field2;
{ numunion nu;

  if (isint(nump)) printint(ctx,intval(nump), strm, base, field1, field2);
  else if (isflt(nump)) printflt(fltval(nump),strm);
  else if (pisbignum(nump)) printbig(ctx,nump, strm, base, field1, field2);
  else if (pisratio(nump)) printratio(ctx, nump, strm, base);
  else error(E_NONUMBER);}

/****************************************************************/
/* print object
/****************************************************************/

static void printobj(ctx,obj,f)
register pointer obj,f;
context *ctx;
{ pointer class;
  class=classtab[obj->cix].def;
  writestr(f,(byte *)"#<",2);
  printsym(ctx,class->c.cls.name,f);
  writech(f,' ');
  printhex(obj,f);
  writech(f,'>');}

static void printpkg(p,f)
register pointer p,f;
{ pointer nm;
  writestr(f,(byte *)"#<package ",10);
  nm=ccar(p->c.pkg.names);
  writestr(f,nm->c.str.chars,vecsize(nm));
  writech(f,'>');}

static void printmark(ctx,p)
register context *ctx;
register pointer p;
{ register int i,s;

  if (isnum(p) || (pissymbol(p) && p->c.sym.homepkg != NIL) ) return;
  if (!p_marked(p)) {
    p_mark_on(p);
    if (pissymbol(p)) return;
    if (pisvector(p)) {
      if (elmtypeof(p)<ELM_POINTER) return;
      s=vecsize(p);
      for (i=0; i<s; i++) printmark(ctx,p->c.vec.v[i]); }
    else {
      s=objsize(p);
      for (i=0; i<s; i++) printmark(ctx,p->c.obj.iv[i]);}
    }
  else if (s_marked(p)) return;
  else {	/*already p_marked ->shared object*/
    s_mark_on(p);
    ckpush(p->c.obj.iv[0]);	/*save first element*/
    pointer_update(p->c.obj.iv[0],makeint(++ix));
    } }
  
static int getprlength(ctx)
context *ctx;
{ register pointer x;
  x=Spevalof(PRLENGTH);
  if (isint(x)) return(intval(x));
  else return(65536);}

static pointer printvector(ctx,vec,f,leng,prlevel)
register context *ctx;
register pointer vec,f,leng;
int prlevel;
{ register eusinteger_t n,i=0,eltype,x,prlength=getprlength(ctx);
  pointer sizesave;

  eltype=elmtypeof(vec);
  n=intval(leng);
  switch(eltype) {
    case ELM_BIT:
	  writestr(f,(byte *)"#*",2);
	  x=1;
	  while (i<n) {
	    writech(f,(vec->c.ivec.iv[i/WORD_SIZE] & x)?'1':'0');
	    i++;
	    x= x<<1;
	    if (i % WORD_SIZE==0) x=1;}
	  break;
    case ELM_BYTE:
	  writestr(f,(byte *)"#<bytecode ",11);
	  printhex(vec,f);
	  writech(f,'>');
	  break;
    case ELM_CHAR:
	  printstr(ctx,n,vec->c.str.chars,f);  break;
    case ELM_INT:
	  writestr(f,(byte *)"#i(",3);
	  while (i<n && prlength>0) {
	    printint(ctx,vec->c.ivec.iv[i++],f,intval(Spevalof(PRINTBASE)),
			0,0);
	    if(i<n) writech(f,' ');
	    prlength--; }
	  if (i<n) writestr(f,(byte *)"... ",4);
          writech(f,')');
	  break;
    case ELM_FLOAT:
	  writestr(f,(byte *)"#f(",3);
	  while (i<n && prlength>0) {
	    printflt(vec->c.fvec.fv[i++],f);
	    if(i<n) writech(f,' ');
	    prlength--; }
	  if (i<n) writestr(f,(byte *)"... ",4);
          writech(f,')');
	  break;
    case ELM_FOREIGN:
	  writestr(f,(byte *)"#u",2);
	  printstr(ctx,vecsize(vec),vec->c.ivec.iv[0],f);
	  break;
    default:
	  if (classof(vec)==C_VECTOR)  writestr(f,(byte *)"#(",2);
	  else {
	    writestr(f,(byte *)"#v(",3);
	    printsym(ctx,classof(vec)->c.cls.name,f);
	    writech(f,' ');
	    printint(ctx,(eusinteger_t)vec->c.vec.size,f,intval(Spevalof(PRINTBASE)),0,0);
	    writech(f,' ');}
	  while (i<n && prlength>0) {
	    prin1(ctx,vec->c.vec.v[i++],f,prlevel);
	    if (i<n) writech(f,' '); }
	  if (i<n) writestr(f,(byte *)"... ",4);
	  writech(f,')');}
  return(vec);}

static void prinelm(ctx,f,prlevel,vec,index)
register context *ctx;
register pointer f,vec;
int prlevel,index;
{ switch(elmtypeof(vec)) {
    case ELM_BIT:
	  { eusinteger_t bitmask;
#if (WORD_SIZE == 64)
      	    bitmask=1L << (index % 64);
	    writech(f,(vec->c.ivec.iv[index/64] & bitmask)?'1':'0');
#else
	    bitmask=1 << (index % 32);
	    writech(f,(vec->c.str.chars[index/32] & bitmask)?'1':'0');
#endif
          }
	  break;
    case ELM_BYTE: case ELM_CHAR:
	  printint(ctx,vec->c.str.chars[index],f,intval(Spevalof(PRINTBASE)),
			0,0);
	  break;
    case ELM_INT:
	  printint(ctx,vec->c.ivec.iv[index],f,intval(Spevalof(PRINTBASE)),
			0,0);
	  break;
    case ELM_FLOAT:
	  printflt(vec->c.fvec.fv[index],f); break;
    default:
	  prin1(ctx,vec->c.vec.v[index],f,prlevel);
    }}

static int prinary(ctx,f,prlevel,a,rank,axis,index)
register context *ctx;
register pointer f;	/*stream*/
register pointer a;	/*array object*/
int prlevel,rank,axis,index;
{ register int i,n,next;
  n=intval(a->c.ary.dim[axis]);
  writech(f,'(');
  if (axis<rank-1) {
    for (i=0; i<n; i++) {
      next=prinary(ctx,f,prlevel,a,rank,axis+1,index);
      if (i<n-1) writech(f,' ');
      index+=next;}
   n=next*n;}
  else {
    if (rank==1 && isint(a->c.ary.fillpointer)) n=intval(a->c.ary.fillpointer);
    for (i=0; i<n; i++) {
      prinelm(ctx,f,prlevel-1,a->c.ary.entity,index+i);
      if (i<n-1) writech(f,' ');} }
  writech(f,')');
  return(n);}

static void printarray(ctx,a,f,prlevel)
register context *ctx;
register pointer a,f;
register int prlevel;
{ char buf[16];
  register int i,j,rank,etype,size=1,index;
  register pointer p,v;
  rank=intval(a->c.ary.rank);
  etype=elmtypeof(a->c.ary.entity);
  sprintf(buf,"#%d%c",rank,(etype==ELM_FLOAT)?'f':
			   (etype==ELM_INT)?'i':'a');
  writestr(f,(byte *)buf,strlen(buf));
  if (isint(a->c.ary.offset)) index=intval(a->c.ary.offset); else index=0;
  prinary(ctx,f,prlevel,a,rank,0,index);
  }

static void printlist(ctx,x,f,fobj,prlevel)
register context *ctx;
register pointer x,f;
register pointer fobj;
register int prlevel;
{ register pointer rest=ccdr(x);
  register int prlength=getprlength(ctx),shareix;

  if (fobj==QUOTE && islist(rest) && ccdr(rest)==NIL) {
    writech(f,'\'');
    prin1(ctx,ccar(rest),f,prlevel-1);
    return;}
  else if (fobj==FUNCTION && islist(rest) && ccdr(rest)==NIL) {
    writestr(f,(byte *)"#\'",2);
    prin1(ctx,ccar(rest),f,prlevel-1);
    return;}
  writech(f,'(');
  prin1(ctx,fobj,f,prlevel);
  x=rest;
  while (islist(x) && !s_marked(x)) {
    if (--prlength<=0) { 
      writestr(f,(byte *)" ...",4);
      x=NIL;   break;}
    else {
      writech(f,' ');
      prin1(ctx,ccar(x),f,prlevel);
      x=ccdr(x);} }
  if (x!=NIL) { writestr(f,(byte *)" . ",3); prin1(ctx,x,f,prlevel);}
  writech(f,')'); }

static void printstructure(ctx,x,f,fobj,prlevel)
register context *ctx;
register pointer x,f;
register pointer fobj;
int prlevel;
{ pointer klass, *varvec;
  register int i=0,s;
  int prlength=getprlength(ctx);
  
  writestr(f,(byte *)"#s(",3);
  klass=classof(x);
  printsym(ctx,klass->c.cls.name,f);
  s=objsize(x); varvec=klass->c.cls.vars->c.vec.v;
  prlength--;
  while (i<s && prlength>0) {
    writech(f,' ');
    printsym(ctx,varvec[i],f);
    writech(f,' ');
    if (i==0) prin1(ctx,fobj,f,prlevel);
    else prin1(ctx,x->c.obj.iv[i],f,prlevel);
    i++; prlength-=2;}
  if (i<s) writestr(f,(byte *)" ...",4);
  writech(f,')');
  }

static void prinxobj(ctx,x,f,fobj,prlevel)
register context *ctx;
register pointer x,f;
pointer fobj;
int prlevel;
{ pointer klass;
  register int i=0,s;
  int prlength=getprlength(ctx);
  writestr(f,(byte *)"#J(",3);
  klass=classof(x);
  printsym(ctx,klass->c.cls.name,f);
  s=objsize(x);
  while (i<s && prlength-->0) {
    writech(f,' ');
    if (i==0) prin1(ctx,fobj,f,prlevel);
    else prin1(ctx,x->c.obj.iv[i],f,prlevel);
    i++;}
  writech(f,')');
  }

static void prin1(ctx,x,f,prlevel)
register context *ctx;
register pointer x;
register pointer f;
register int prlevel;
{ register pointer fobj;
  register int shareix=0;
  numunion nu;

  if (prlevel<=0) { writech(f,'#'); return;}
  if (isnum(x)) { printnum(ctx,x,f,intval(Spevalof(PRINTBASE)),0,0); return;}
  else if (x==UNBOUND) { writestr(f,(byte *)"***UNBOUND***",13); return;}
  /*pointed object*/
#if vax || sun4 || news || mips || i386 || alpha || x86_64  || ARM
  if ((x<(pointer)(ctx->stack)) && ((pointer)(ctx->stacklimit)<x)){
	printint(ctx,(eusinteger_t)x,f,intval(Spevalof(PRINTBASE)),0,0); return;}
#endif
  if (pisratio(x)) {
    printnum(ctx,x,f,intval(Spevalof(PRINTBASE)),0,0); return;}
  else if (pisbignum(x)) {
    printnum(ctx,x,f,intval(Spevalof(PRINTBASE)),0,0);
    return;}
  else {	/*use #n= and #n# for shared objects*/
    if (s_marked(x))
      if (p_marked (x)) {	/*first seen this shared obj. --> #n= */
        p_mark_off(x);
        shareix=intval(x->c.obj.iv[0]);
        sprintf(ixbuf,"#%d=",shareix);
        writestr(f,(byte *)ixbuf,strlen(ixbuf));
        fobj=ixvec[shareix]; }
      else {			/*use #n# expression for labeled obj*/
        sprintf(ixbuf,"#%ld#",intval(x->c.obj.iv[0]));
        writestr(f,(byte *)ixbuf,strlen(ixbuf));
        return; }
    else fobj=x->c.obj.iv[0];
    if (classof(x)==C_CONS) printlist(ctx,x,f,fobj,prlevel-1);
    else if (pissymbol(x)) { printsym(ctx,x,f); return;}
    else if (pisvector(x))  printvector(ctx,x,f,fobj,prlevel-1);
    else if (Spevalof(PROBJECT)!=NIL)    prinxobj(ctx,x,f,fobj,prlevel-1);
    else if (pisarray(x) && (classof(x)==C_ARRAY))  printarray(ctx,x,f,prlevel-1);
    else if (Spevalof(PRSTRUCTURE)!=NIL) printstructure(ctx,x,f,fobj,prlevel-1);
    else csend(ctx,x,K_PRIN1,1,f);
    }    }

static void printunmark(p)
register pointer p;
{ register int i,s;
  if (isnum(p)) return;
  if (!s_marked(p) && !p_marked(p)) return;
  if (s_marked(p))
    if (p_marked(p)) fprintf(stderr,"smarked?\n");
    else pointer_update(p->c.obj.iv[0],ixvec[intval(p->c.obj.iv[0])]);
  s_mark_off(p); p_mark_off(p);
  if (pissymbol(p)) return;
  else if (pisvector(p)) {
    if (elmtypeof(p)<ELM_POINTER) return;
    s=vecsize(p);
    for (i=0; i<s; i++) printunmark(p->c.vec.v[i]); }
  else {
    s=objsize(p);
    for (i=0; i<s; i++) printunmark(p->c.obj.iv[i]); }
  }

pointer prinx(ctx,obj,stream)
register context *ctx;
register pointer obj,stream;
{ pointer *spsave=ctx->vsp;
  pointer prlevel;
  int iprlevel;

  prlevel=Spevalof(PRLEVEL);
  if (isint(prlevel)) iprlevel=intval(prlevel); else iprlevel=65536;
  if (Spevalof(PRCIRCLE)!=NIL) {
    ixvec=ctx->vsp; ix=0; vpush(0);
#if THREADED
    mutex_lock(&mark_lock);
    mark_locking="prinx";
#endif
    printmark(ctx,obj);
    prin1(ctx,obj,stream,iprlevel);
    printunmark(obj);
#if THREADED
    mutex_unlock(&mark_lock);
#endif
    }
  else prin1(ctx,obj,stream,iprlevel);
  ctx->vsp=spsave;
  return(obj);}

void terpri(f)
register pointer f;
{ writech(f,'\n');  flushstream(f); }

