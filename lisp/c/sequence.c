/****************************************************************/
/* sequence.c
/*
/*	Copyright Toshihiro MATSUI, ETL, Umezono, Sakura-mura
/*	1986-Aug
/*	1987-Apr
/*	1987-July	RPLACA and RPLACD are added
/*	1988-July	REPLACE,REMOVE,POSITION,FIND,DELETE
/*			are made compatible with CommonLisp
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "eus.h"
#include <math.h> /* for round in coerceintval */

#if (WORD_SIZE == 64)
#define bitref(vec,index) (((vec)->c.ivec.iv[(index)/64] >> ((index)%64)) & 1L)
#define bitset(vec,index,val) \
	(val?((vec)->c.ivec.iv[(index)/64] |= (1L<<((index)%64))): \
	     ((vec)->c.ivec.iv[(index)/64] &= ~(1L<<((index)%64))))
#define MAX_SEQUENCE_COUNT 100000000
#else
#define bitref(vec,index) (((vec)->c.ivec.iv[(index)/32] >> ((index)%32)) & 1)
#define bitset(vec,index,val) \
	(val?((vec)->c.ivec.iv[(index)/32] |= (1<<((index)%32))): \
	     ((vec)->c.ivec.iv[(index)/32] &= ~(1<<((index)%32))))
#define MAX_SEQUENCE_COUNT 1000000
#endif

extern pointer QEQ;
pointer QIDENTITY;
static pointer pushrest;

extern int     pushsequence(context *,pointer,int,int);
extern pointer makesequence(context *, int,pointer);

pointer call1(ctx,func,arg)
register context *ctx;
pointer func,arg;
{ vpush(arg);
  arg=ufuncall(ctx,func,func,(pointer)(ctx->vsp-1),NULL,1);
  ctx->vsp-=1;
  return(arg);}

pointer call2(ctx,func,arg1,arg2)
register context *ctx;
pointer func,arg1,arg2;
{ vpush(arg1); vpush(arg2);
  arg1=ufuncall(ctx,func,func,(pointer)(ctx->vsp-2),NULL,2);
  ctx->vsp-=2;
  return(arg1);}

/* type-independent vector access primitives */

eusinteger_t coerceintval(x)
register pointer x;
{ numunion nu;
  int y;
  if (isflt(x)) return((eusinteger_t)round(fltval(x)));
  else return((eusinteger_t)bigintval(x));
  }

pointer fastvref(vec,index)
register pointer vec;
register int index;
{ register byte *p=vec->c.str.chars;
  eusinteger_t *pl=vec->c.ivec.iv;
  long ival;
  numunion nu;

  switch(elmtypeof(vec)) {
      case ELM_FOREIGN: p=vec->c.foreign.chars;
      case ELM_CHAR: case ELM_BYTE: return(makeint(p[index]));
      case ELM_INT:  ival=vec->c.ivec.iv[index];
		     return(mkbigint(ival));
      case ELM_FLOAT: return(makeflt(vec->c.fvec.fv[index]));
#if (WORD_SIZE == 64)
      case ELM_BIT:   return(makeint((pl[index/64] & (1L<<((eusinteger_t)index%64)))?1L:0L));
#else
      case ELM_BIT:   return(makeint((pl[index/32] & (1<<((eusinteger_t)index%32)))?1:0));
#endif
      case ELM_POINTER: return(vec->c.vec.v[index]);} }

void fastvset(vec,index,val)
register pointer vec,val;
register int index;
{ register byte *p;
  numunion nu;
  switch(elmtypeof(vec)) {
    case ELM_INT:   vec->c.ivec.iv[index]=coerceintval(val); return;
    case ELM_FLOAT: vec->c.fvec.fv[index]=ckfltval(val);  return;
    case ELM_POINTER: pointer_update(vec->c.vec.v[index],val);  return;
    case ELM_CHAR: case ELM_BYTE:
		    vec->c.str.chars[index]=coerceintval(val); return;
#if (WORD_SIZE == 64)
    case ELM_BIT:   if (coerceintval(val) & 1L) 
			vec->c.ivec.iv[index/64] |= 1L << (index%64);
		    else vec->c.ivec.iv[index/64] &= ~(1L<<index%64);
#else
    case ELM_BIT:   if (coerceintval(val) & 1) 
			vec->c.ivec.iv[index/32] |= 1 << (index%32);
		    else vec->c.ivec.iv[index/32] &= ~(1<<index%32);
#endif
		    return;
    case ELM_FOREIGN: p=vec->c.foreign.chars;
		      p[index]=coerceintval(val); return;} }

/*************************************************/

pointer IDENTITY(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  return(argv[0]);}

pointer SUBSEQ(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0],r;
  register eusinteger_t s,e,i=0,count;
  pointer fastvref();
  void fastvset();
  ckarg2(2,3);
  s=ckintval(argv[1]);
  if (n==3) {
    e=ckintval(argv[2]);
    if (e<s) error(E_STARTEND);}
  if (a==NIL)return(NIL);
  else if (islist(a)) {
    while (islist(a) && i++<s) a=ccdr(a);
    if (!islist(a)) error(E_STARTEND);
    i=0;
    if (n==3) {
      while (s<e) { 
        if (!islist(a)) break;
        ckpush(ccar(a)); a=ccdr(a); i++; s++;}}
    else while (islist(a)) { ckpush(ccar(a)); a=ccdr(a); i++;}
    return((pointer)stacknlist(ctx,i));}
  else if (isarray(a)) {
    s+=intval(a->c.ary.offset);
    e+=intval(a->c.ary.offset);
    a=a->c.ary.entity;}
  if (isvector(a)) {
    count=vecsize(a);
    if (n==3) e=min(e,count);
    else e=count;
    count=e-s;
    switch(elmtypeof(a)) {
      case ELM_BIT:
	 r=makevector(classof(a), count);
	 while (count-->0) fastvset(r,i++,fastvref(a,s++));
	 return(r);
      case ELM_BYTE: case ELM_CHAR: 
	r=makevector(classof(a), count);
	memcpy(&r->c.str.chars[i], &a->c.str.chars[s], count);
	return(r);
      case ELM_FOREIGN:
	{ byte *p;
	  r=makevector(C_STRING, count); 
	  p=a->c.foreign.chars;
	  memcpy(&r->c.str.chars[i], &p[s], count);
	  return(r);}
      default:
	r=makevector(classof(a), count);
	memcpy(&r->c.vec.v[i], &a->c.vec.v[s], count*sizeof(pointer));
	return(r);
      }
    }
  else error(E_NOSEQ);}

pointer COPYSEQ(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer a,r;
  register int i=0,s,k;
  register byte *p;
  ckarg(1);
  a=argv[0];
  if (a==NIL) return(NIL);
  else if (islist(a)) {
    while (islist(a)) { ckpush(ccar(a)); a=ccdr(a); i++;}
    r=NIL;
    while (i-->0) r=cons(ctx,vpop(),r);
    return(r);}
  else if (isarray(a)) {
    if (a->c.ary.rank>makeint(1)) error(E_NOSEQ);
    k=intval(a->c.ary.dim[0]);
    s=intval(a->c.ary.offset);
    a=a->c.ary.entity;}
  if (isvector(a)) { k=vecsize(a); s=0;}
  else error(E_NOSEQ);
  p=a->c.str.chars;
  switch(elmtypeof(a)) {
      case ELM_BIT:
	r=makevector(classof(a), k);
	for (i=0; i<k; s++, i++) bitset(r,i,bitref(a,s));
	break;
      case ELM_FOREIGN:
	r=makevector(C_STRING, k); 
	p=a->c.foreign.chars;
	memcpy(r->c.str.chars, &p[s] ,k);
	break;
      case ELM_BYTE: case ELM_CHAR: 
	r=makevector(classof(a), k);
	memcpy(r->c.str.chars, &p[s], k);
	break;
      default:
	r=makevector(classof(a), k);
	memcpy(r->c.vec.v, &a->c.vec.v[s], k*sizeof(pointer));
	break;
      }
  return(r);}

pointer REVERSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0],r=NIL;
  register byte *p;
  register eusinteger_t i,k,s,e;
  ckarg(1);
  if (a==NIL) return(NIL);
  else if (islist(a)) {
    while (islist(a)) { r=cons(ctx,ccar(a),r); a=ccdr(a);}
    return(r);}
  else if (isarray(a)) {
    if (a->c.ary.rank>makeint(1)) error(E_NOSEQ);
    s=intval(a->c.ary.offset);
    k=intval(a->c.ary.dim[0]);
    a=a->c.ary.entity;}
  else if (isvector(a)) { k=vecsize(a); s=0;}
  else error(E_NOSEQ);
  r=makevector(classof(a),k);
  p=a->c.str.chars;
  switch(elmtypeof(a)) {
      case ELM_BIT: for (i=0; i<k; s++,i++) bitset(r,k-i-1,bitref(a,s));
		    break;
      case ELM_FOREIGN: r=makevector(C_STRING, k); p=a->c.foreign.chars;
      case ELM_CHAR: case ELM_BYTE:
	    for (i=0; i<k; s++,i++) r->c.str.chars[k-i-1]=p[s];
	    break;
      default: for (i=0; i<k; s++,i++) pointer_update(r->c.vec.v[k-i-1],a->c.vec.v[s]);
	       break;}
  return(r);}
   
pointer NREVERSE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0],r=NIL, *vp;
  register eusinteger_t i,k,s,kk,x,y;
  register byte *cp;
  ckarg(1);
  if (a==NIL) return(NIL);
  else if (islist(a)) {
    i=0; r=a;
    while (islist(r)) { ckpush(ccar(r)); r=ccdr(r); i++;}
    r=a;
    while (i>0) { pointer_update(ccar(r),vpop()); r=ccdr(r); i--;}
    return(a);}
  else if (isarray(a)) {
    if (a->c.ary.rank>makeint(1)) error(E_NOSEQ);
    s=intval(a->c.ary.offset);
    k=intval(a->c.ary.dim[0]);
    a=a->c.ary.entity;}
  else if (isvector(a)) { k=vecsize(a); s=0;}
  else error(E_NOSEQ);
  kk=k/2; vp=a->c.vec.v;
  cp=a->c.str.chars;
  switch(elmtypeof(a)) {
    case ELM_BIT:
	for(i=0; i<kk; i++, s++) {
	  x=bitref(a,s);
	  y=bitref(a,k-i-1);
#if (WORD_SIZE == 64)
          if (y) a->c.ivec.iv[s/64] |= (1L<<(s%64));
	  else a->c.ivec.iv[s/64] &= ~(1L<<(s%64));
          if (x) a->c.ivec.iv[(k-i-1)/64] |= (1L<<((k-i-1)%64));
	  else a->c.ivec.iv[(k-i-1)/64] &= ~(1L<<((k-i-1)%64));
#else
          if (y) a->c.ivec.iv[s/32] |= (1<<(s%32));
	  else a->c.ivec.iv[s/32] &= ~(1<<(s%32));
          if (x) a->c.ivec.iv[(k-i-1)/32] |= (1<<((k-i-1)%32));
	  else a->c.ivec.iv[(k-i-1)/32] &= ~(1<<((k-i-1)%32));
#endif
        }
	break;
    case ELM_FOREIGN: cp=a->c.foreign.chars;
    case ELM_CHAR: case ELM_BYTE:
	for(i=0; i<kk; i++, s++) {
	   x=cp[s]; cp[s]=cp[k-i-1]; cp[k-i-1]=x;}
        break;
    default:
	vp=a->c.vec.v;
	for(i=0; i<kk; i++, s++) {
	   r=vp[s]; pointer_update(vp[s],vp[k-i-1]); vp[k-i-1]=r;} 
        break; }
    return(a);}
    
int pushsequence(ctx,a,offset,count)
register context *ctx;
register pointer a;
register int offset,count;
{ long i,len=0, x;
  byte *p;
  numunion nu;

  if (a==NIL) return(0);
  else if (iscons(a)) {
    while (offset-->0) { a=cdrof(a,E_SEQINDEX);}
    while (count-->0 && iscons(a)) { ckpush(ccar(a)); a=ccdr(a); len++;}
    pushrest=a;
    return(len);}
  else {
    if (isarray(a)) {
      if (a->c.ary.rank!=makeint(1)) error(E_NOSEQ);
      offset+=intval(a->c.ary.offset); a=a->c.ary.entity;}
    if (!isvector(a)) error(E_NOSEQ);
    i=0; len=vecsize(a)-offset; len=min(len,count);
    p=a->c.str.chars;
    switch(elmtypeof(a)) {
      case ELM_FOREIGN: p=a->c.foreign.chars; /* no break*/
      case ELM_CHAR: case ELM_BYTE: while (i<len) ckpush(makeint(p[offset+i++]));
				    return(len);
      case ELM_INT:  while (i<len) {
                      x=a->c.ivec.iv[offset+i++];
                      ckpush(makeint(x)); }
		     return(len); 
      case ELM_FLOAT: while (i<len) ckpush(makeflt(a->c.fvec.fv[offset+i++]));
		      return(len);
      case ELM_BIT: { eusinteger_t m, b;
		      while (i<len) {
#if (WORD_SIZE == 64)
			m= 1L<<((offset+i)%64);
			b=a->c.ivec.iv[(offset+i)/64] & m;
#else
			m= 1<<((offset+i)%32);
			b=a->c.ivec.iv[(offset+i)/32] & m;
#endif
			ckpush(makeint(b?1:0));
			i++;}
		      return(len);}
      case ELM_POINTER: while (i<len) ckpush(a->c.vec.v[offset+i++]);
			return(len);} }}

pointer makesequence(ctx,n,resulttype)
register context *ctx;
register int n;
pointer resulttype;
{ register pointer x,r;
  register int cid=intval(resulttype->c.cls.cix);
  numunion nu;
  if (cid==conscp.cix) return((pointer)stacknlist(ctx,n));
  else if (cid<=conscp.sub) {
    r=NIL;
    while (n-- > 0) {
      vpush(r);
      x=(pointer)makeobject(resulttype);
      r=vpop();
      pointer_update(x->c.cons.car,vpop());
      pointer_update(x->c.cons.cdr,r);
      r=x;}
    return(r);}
  else {
    r=makevector(resulttype,n);
    switch(elmtypeof(r)) {
      case ELM_INT:	while (--n>=0) r->c.ivec.iv[n]=coerceintval(vpop());
		      	return(r);
      case ELM_FLOAT:	while (--n>=0) {
			  x=vpop();
			  r->c.fvec.fv[n]=ckfltval(x);}
		        return(r);
      case ELM_POINTER: while (--n>=0) pointer_update(r->c.vec.v[n],vpop());
		        return(r);
      case ELM_CHAR: case ELM_BYTE:
			while (--n>=0) r->c.str.chars[n]=coerceintval(vpop());
		        return(r);
      case ELM_BIT:	while (--n>=0)
#if (WORD_SIZE == 64)
			  r->c.ivec.iv[n/64]|=(coerceintval(vpop()) & 1L)<<(n%64);
#else
			  r->c.ivec.iv[n/32]|=(coerceintval(vpop()) & 1)<<(n%32);
#endif
		        return(r);
      case ELM_FOREIGN: error(E_USER,(pointer)"cannot coerce to foreign string"); } } } 

pointer CONCATENATE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register int i,argc=1,resultlen=0;
  if (n<=1) return(NIL);
  if (!isclass(argv[0])) error(E_NOCLASS,argv[0]);
  while (argc<n) resultlen+=pushsequence(ctx,argv[argc++],0,MAX_SEQUENCE_COUNT);
  return(makesequence(ctx,resultlen,argv[0]));}

pointer COERCE(ctx,n,argv)
register context *ctx;
register int n;
register pointer argv[];
{ register eusinteger_t offset,count,len,i;
  register pointer a=argv[0];
  ckarg(2);
  if (!isclass(argv[1])) error(E_NOCLASS,argv[1]);
  if (isarray(a)) {
    if (a->c.ary.rank!=makeint(1)) error(E_NOSEQ,a);
    offset=intval(a->c.ary.offset);
    count=intval(a->c.ary.dim[0]);
    a=a->c.ary.entity;}
  else { offset=0; count=MAX_SEQUENCE_COUNT;}
  len=pushsequence(ctx,a,offset,count);
  return(makesequence(ctx,len,argv[1])); }
  
pointer FILL(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ /* (Fill seq item :start :end) */
  register pointer seq=argv[0], item=argv[1];
  register eusinteger_t i=0,start,end, val, count;
  eusfloat_t fval;
  byte *bp;
  numunion nu;

  ckarg(4);
  start=ckintval(argv[2]); end=ckintval(argv[3]);
  if (islist(seq)) {
    while (i++<start && islist(seq)) seq=ccdr(seq);
    while (start<end) {
      if (!iscons(seq)) break;
      pointer_update(ccar(seq),item); seq=ccdr(seq);
      start++;}
    return(argv[0]); }
  else if (isvector(seq)) end=min(end,vecsize(seq));
  else if (isarray(seq)) {
    if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
    end=min(end,intval(seq->c.ary.dim[0]))+intval(seq->c.ary.offset);
    start+=intval(seq->c.ary.offset);
    seq=seq->c.ary.entity;}
  else error(E_NOSEQ);
  switch (elmtypeof(seq)) {
    case ELM_INT: val=coerceintval(item);
		  while (start<end) seq->c.ivec.iv[start++]=val;
		  break;
    case ELM_FLOAT: fval=ckfltval(item);
		    while (start<end) seq->c.fvec.fv[start++]=fval;
		    break;
    case ELM_POINTER: while (start<end) seq->c.vec.v[start++]=item; break;
    case ELM_CHAR: case ELM_BYTE: 
		val = coerceintval(item);
		bp=seq->c.str.chars;
		while (start<end) bp[start++]=val;
		break;
    case ELM_BIT:
#if (WORD_SIZE == 64)
		while (((start % 64) != 0) && (start<end))
		  fastvset(seq,start++,item);
		count = (end-start)/64;
		val= (coerceintval(item)==0L)?0L:~0L;
		for (i=0; i<count; i++) 
		  seq->c.ivec.iv[start/64+i]=val;	/*all zero or all one*/
		start = start + count*64;
#else
		while (((start % 32) != 0) && (start<end))
		  fastvset(seq,start++,item);
		count = (end-start)/32;
		val= (coerceintval(item)==0)?0:~0;
		for (i=0; i<count; i++) 
		  seq->c.ivec.iv[start/32+i]=val;	/*all zero or all one*/
		start = start + count*32;
#endif
		while (start<end) fastvset(seq, start++, item);
		break;
    case ELM_FOREIGN:
		bp=seq->c.foreign.chars;
		val=coerceintval(item);
		while (start<end) bp[start++]=val;
		break;
    } 
  return(argv[0]);}

pointer MAP(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ /* (MAP result-type function &rest seq) */
  register pointer func=argv[1], argseq,r;
  register eusinteger_t argc,rcount=0,offset;

  if (n<3) error(E_MISMATCHARG);
  while (1) {
    argc=0;
    /*collect args*/
    while (argc+2<n) {
      argseq=argv[argc+2];
      if (iscons(argseq)) {
	ckpush(ccar(argseq)); 
	argv[argc+2]=ccdr(argseq);}
      else {
	if (isarray(argseq)) {
	  if (argseq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
	  offset=intval(argseq->c.ary.offset);
	  argseq=argseq->c.ary.entity;}
	else offset=0;
        if (isvector(argseq) && vecsize(argseq)>rcount+offset)
	  ckpush(fastvref(argseq,rcount+offset));
        else { ctx->vsp-=argc; goto makeresult;} }
      argc++;}
    r=ufuncall(ctx,ctx->callfp->form,func,(pointer)(ctx->vsp-argc),NULL,argc);
    ctx->vsp-=argc;
    vpush(r);
    rcount++;}
makeresult:
  if (isclass(argv[0])) return(makesequence(ctx,rcount,argv[0]));
  else { ctx->vsp-=rcount; return(NIL);}}
  
pointer POSITION(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register pointer item=argv[0],seq=argv[1],element;
  pointer test=argv[2],testnot=argv[3],key=argv[4];
  pointer iftest=argv[5],ifnottest=argv[6];
  register eusinteger_t start,end,count,i=0;
  
  ckarg(10);
  start=ckintval(argv[7]); end=ckintval(argv[8]); count=ckintval(argv[9]);

  if (seq==NIL) return(NIL);
  else if (islist(seq)) {
    while (i++<start && islist(seq)) seq=ccdr(seq);
    if (!islist(seq)) return(NIL);}
  else if (isvector(seq)) end=min(end,vecsize(seq));
  else if (isarray(seq)) {
    if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
    seq=seq->c.ary.entity; end=min(end,vecsize(seq));}
  else error(E_NOSEQ);
  while (start<end) {
    /* elt */
    if (seq==NIL) return(NIL);
    else if (iscons(seq)) { element=ccar(seq); seq=ccdr(seq);}
    else element=fastvref(seq,start);
    if (key!=QIDENTITY) element=call1(ctx,key,element);
    if (ifnottest!=NIL) {
      if (call1(ctx,ifnottest,element)==NIL&&--count<=0) return(makeint(start));}
    else if (iftest!=NIL) {
      if (call1(ctx,iftest,element)!=NIL&&--count<=0) return(makeint(start));}
    else if (testnot!=NIL) {
      if (call2(ctx,testnot,item,element)==NIL&&--count<=0) return(makeint(start));}
    else if (test!=QEQ) {
      if (call2(ctx,test,item,element)!=NIL&&--count<=0) return(makeint(start));}
    else if (item==element&&--count<=0) return(makeint(start));
    start++;}
  return(NIL);}

pointer FIND(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register pointer item=argv[0],seq=argv[1],element,testelement;
  pointer test=argv[2],testnot=argv[3],key=argv[4];
  pointer iftest=argv[5],ifnottest=argv[6];
  register eusinteger_t start,end,i=0;
  
  ckarg(9);
  start=ckintval(argv[7]); end=ckintval(argv[8]);

  if (seq==NIL) return(NIL);
  else if (islist(seq)) {
    while (i++<start && islist(seq)) seq=ccdr(seq);
    if (!islist(seq)) return(NIL);}
  else {
    if (isarray(seq)) {
      if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
      seq=seq->c.ary.entity;}
    if (isvector(seq)) end=min(end,vecsize(seq));
    else error(E_NOSEQ);}
  while (start<end) {
    /* elt */
    if (seq==NIL) return(NIL);
    else if (iscons(seq)) { element=ccar(seq); seq=ccdr(seq);}
    else element=fastvref(seq,start);
    if (key!=QIDENTITY) testelement=call1(ctx,key,element);
    else testelement=element;
    if (ifnottest!=NIL) {
      if (call1(ctx,ifnottest,testelement)==NIL) return(element);}
    else if (iftest!=NIL) {
      if (call1(ctx,iftest,testelement)!=NIL) return(element);}
    else if (testnot!=NIL) {
      if (call2(ctx,testnot,item,testelement)==NIL) return(element);}
    else if (test!=QEQ) {
      if (call2(ctx,test,item,testelement)!=NIL) return(element);}
    else if (item==testelement) return(element);
    start++;}
  return(NIL);}

pointer COUNT(ctx,n,argv)
register context *ctx;
int n;
register pointer *argv;
{ register pointer item=argv[0],seq=argv[1],element,testelement;
  pointer test=argv[2],testnot=argv[3],key=argv[4];
  pointer iftest=argv[5],ifnottest=argv[6];
  register eusinteger_t start,end,i=0;
  
  ckarg(9);
  start=ckintval(argv[7]); end=ckintval(argv[8]);

  if (seq==NIL) return(makeint(0));
  else if (islist(seq)) {
    while (i++<start && islist(seq)) seq=ccdr(seq);
    if (!islist(seq)) return(NIL);}
  else {
    if (isarray(seq)) {
      if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
      seq=seq->c.ary.entity;}
    if (isvector(seq)) end=min(end,vecsize(seq));
    else error(E_NOSEQ);}
  i=0;
  while (start<end) {
    /* elt */
    if (seq==NIL) return(makeint(i));
    else if (iscons(seq)) { element=ccar(seq); seq=ccdr(seq);}
    else element=fastvref(seq,start);
    if (key!=QIDENTITY) testelement=call1(ctx,key,element); else testelement=element;
    if (ifnottest!=NIL) {
      if (call1(ctx,ifnottest,testelement)==NIL) i++;}
    else if (iftest!=NIL) {
      if (call1(ctx,iftest,testelement)!=NIL) i++;}
    else if (testnot!=NIL) {
      if (call2(ctx,testnot,item,testelement)==NIL) i++;}
    else if (test!=QEQ) {
      if (call2(ctx,test,item,testelement)!=NIL) i++;}
    else if (item==testelement) i++;
    start++;}
  return(makeint(i));}

pointer UNIREMOVE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer item=argv[0],seq=argv[1],test=argv[2],testnot=argv[3],key=argv[4];
  pointer iftest=argv[5],ifnottest=argv[6];
  register pointer element,testelement;
  eusinteger_t start,end,count,i,testresult,pushcount;

  ckarg(10);
  start=ckintval(argv[7]); end=ckintval(argv[8]); count=ckintval(argv[9]);
  if (seq==NIL) return(NIL);
  else {
    if (isarray(seq)) {
      if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
      seq=seq->c.ary.entity;}
    if (isvector(seq)) end=min(end,vecsize(seq));
    else if (!iscons(seq)) error(E_NOSEQ);}
  pushcount=pushsequence(ctx,seq,0,start);
  if (iscons(seq)) seq=pushrest;
  while (start<end && count>0) {
    if (iscons(seq)) { element=ccar(seq);  seq=ccdr(seq);}
    else if (isvector(seq)) element=fastvref(seq,start);
    else error(E_SEQINDEX);	/*list exhausted*/
    start++;
    if (key!=QIDENTITY) testelement=call1(ctx,key,element); else testelement=element;
    if (ifnottest!=NIL) testresult=(call1(ctx,ifnottest,testelement)==NIL);
    else if (iftest!=NIL) testresult=(call1(ctx,iftest,testelement)!=NIL);
    else if (testnot!=NIL) testresult=(call2(ctx,testnot,item,testelement)==NIL);
    else if (test!=QEQ) testresult=(call2(ctx,test,item,testelement)!=NIL);
    else testresult=(item==testelement);
    if (testresult) { count--;}
    else { ckpush(element); pushcount++;}}
  if (iscons(argv[1])) {
    while (pushcount-->0) seq=cons(ctx,vpop(),seq);
    return(seq);}
  else {
    pushcount+=pushsequence(ctx,seq,end,MAX_SEQUENCE_COUNT);
    return(makesequence(ctx,pushcount,classof(seq)));}}

pointer REMOVE_DUPLICATES(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer seq=argv[0],test=argv[1],testnot=argv[2],key=argv[3];
  register pointer element,testelement,seq2,element2;
  register eusinteger_t i,start,end,testresult,pushcount;

  ckarg(6);
  start=ckintval(argv[4]); end=ckintval(argv[5]);
  if (seq==NIL) return(NIL);
  if (isvector(seq)) end=min(end,vecsize(seq));
  else if (!iscons(seq)) error(E_NOSEQ);
  pushcount=pushsequence(ctx,seq,0,start);
  if (iscons(seq)) seq=pushrest;
  while (start<end) {
    if (seq==NIL) break;
    if (iscons(seq)) { element=ccar(seq);  seq=ccdr(seq);}
    else if (isvector(seq)) element=fastvref(seq,start);
    else error(E_SEQINDEX);	/*list exhausted*/
    start++;
    if (key!=QIDENTITY) testelement=call1(ctx,key,element); else testelement=element;
    i=start; seq2=seq; testresult=0;
    while (i<end) {
      if (seq2==NIL) break;
      else if (iscons(seq2)) { element2=ccar(seq2);  seq2=ccdr(seq2); }
      else if (isvector(seq2)) element2=fastvref(seq2,i);
      else error(E_SEQINDEX);	/*list exhausted*/
      i++;
      if (key!=QIDENTITY) element2=call1(ctx,key,element2);
      if (testnot!=NIL) testresult=(call2(ctx,testnot,testelement,element2)==NIL);
      else if (test!=QEQ) testresult=(call2(ctx,test,testelement,element2)!=NIL);
      else testresult=(testelement==element2);
      if (testresult) /*duplicated!*/ break;}
    if (!testresult) {ckpush(element); pushcount++;} }
  if (iscons(argv[0])) {
    while (pushcount-->0) seq=cons(ctx,vpop(),seq);
    return(seq);}
  else {
    pushcount+=pushsequence(ctx,seq,end,MAX_SEQUENCE_COUNT);
    return(makesequence(ctx,pushcount,classof(seq)));}}

pointer DELETE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer item=argv[0],seq=argv[1],test=argv[2],testnot=argv[3],key=argv[4];
  pointer iftest=argv[5],ifnottest=argv[6];
  register pointer element,testelement,result=seq,lastseq;
  eusinteger_t start,end,count,i,testresult,first,lastindex;

  ckarg(10);
  start=ckintval(argv[7]); end=ckintval(argv[8]); count=ckintval(argv[9]);
  lastindex=start;
  if (seq==NIL) return(NIL);
  if (isarray(seq)) {
    if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
    seq=seq->c.ary.entity;}
  if (isvector(seq)) end=min(end,vecsize(seq));
  else if (!iscons(seq)) error(E_NOSEQ);

  if (iscons(seq)) {
    first=(start==0);
    for (i=0; i<start; i++) if (iscons(seq)) seq=ccdr(seq); else error(E_SEQINDEX);
    lastseq=seq;}
  while (start<end && count>0) {
    if (iscons(seq)) element=ccar(seq);
    else if (isvector(seq)) element=fastvref(seq,start);
    else error(E_SEQINDEX);	/*list exhausted*/
    if (key!=QIDENTITY) testelement=call1(ctx,key,element); else testelement=element;
    if (ifnottest!=NIL) testresult=(call1(ctx,ifnottest,testelement)==NIL);
    else if (iftest!=NIL) testresult=(call1(ctx,iftest,testelement)!=NIL);
    else if (testnot!=NIL) testresult=(call2(ctx,testnot,item,testelement)==NIL);
    else if (test!=QEQ) testresult=(call2(ctx,test,item,testelement)!=NIL);
    else testresult=(item==testelement);
    if (iscons(result)) {
      if (testresult) {
        count--;
        if (first) { result=ccdr(seq);}
        else { ccdr(lastseq)=ccdr(seq); first=0;}}
      else { lastseq = seq; first=0;}
      seq = ccdr(seq);}
    else if (isvector(seq)) {
      if (testresult) { count--;}
      else {
        if (start!=lastindex) fastvset(seq,lastindex,element);
	lastindex++;} }
    else error(E_SEQINDEX);
    start++; }
  if (isvector(result)) result->c.vec.size=makeint(lastindex);
  return(result);}

pointer SUBSTITUTE(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ pointer newitem=argv[0], olditem=argv[1], seq=argv[2];
  pointer test=argv[3],testnot=argv[4],key=argv[5];
  pointer iftest=argv[6],ifnottest=argv[7];
  register pointer element,testelement;
  register eusinteger_t i,start,end,count,testresult,pushcount;

  ckarg(11);
  start=ckintval(argv[8]); end=ckintval(argv[9]); count=ckintval(argv[10]);
  if (seq==NIL) return(NIL);
  if (isarray(seq)) {
    if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
    seq=seq->c.ary.entity;}
  if (isvector(seq)) end=min(end,vecsize(seq));
  else if (!iscons(seq)) error(E_NOSEQ);
  pushcount=pushsequence(ctx,seq,0,start);
  if (iscons(seq)) seq=pushrest;
  while (start<end && count>0) {
    if (iscons(seq)) { element=ccar(seq);  seq=ccdr(seq);}
    else if (isvector(seq)) element=fastvref(seq,start);
    else error(E_SEQINDEX);	/*list exhausted*/
    start++;
    if (key!=QIDENTITY) testelement=call1(ctx,key,element); else testelement=element;
    if (ifnottest!=NIL) testresult=(call1(ctx,ifnottest,testelement)==NIL);
    else if (iftest!=NIL) testresult=(call1(ctx,iftest,testelement)!=NIL);
    else if (testnot!=NIL) testresult=(call2(ctx,testnot,olditem,testelement)==NIL);
    else if (test!=QEQ) testresult=(call2(ctx,test,olditem,testelement)!=NIL);
    else testresult=(olditem==testelement);
    /**/
    if (testresult) { count--; ckpush(newitem);}
    else { ckpush(element);}
    pushcount++;}
  if (iscons(argv[2])) {
    while (pushcount-->0) seq=cons(ctx,vpop(),seq);
    return(seq);}
  else {
    pushcount+=pushsequence(ctx,seq,end,MAX_SEQUENCE_COUNT);
    return(makesequence(ctx,pushcount,classof(seq)));}}

pointer NSUBSTITUTE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer newitem=argv[0], olditem=argv[1], seq=argv[2];
  pointer test=argv[3],testnot=argv[4],key=argv[5];
  pointer iftest=argv[6],ifnottest=argv[7];
  register pointer element,testelement;
  register eusinteger_t i,start,end,count,testresult;

  ckarg(11);
  start=ckintval(argv[8]); end=ckintval(argv[9]); count=ckintval(argv[10]);
  if (seq==NIL) return(NIL);
  if (isarray(seq)) {
    if (seq->c.ary.rank!=makeint(1)) error(E_NOSEQ);
    seq=seq->c.ary.entity;}
  if (isvector(seq)) end=min(end,vecsize(seq));
  else if (!iscons(seq)) error(E_NOSEQ);

  if (iscons(seq))
    for (i=0; i<start; i++) if (iscons(seq)) seq=ccdr(seq); else error(E_SEQINDEX);
  while (start<end && count>0) {
    if (iscons(seq)) element=ccar(seq);
    else if (isvector(seq)) element=fastvref(seq,start);
    else error(E_SEQINDEX);	/*list exhausted*/
    if (key!=QIDENTITY) testelement=call1(ctx,key,element); else testelement=element;
    if (ifnottest!=NIL) testresult=(call1(ctx,ifnottest,testelement)==NIL);
    else if (iftest!=NIL) testresult=(call1(ctx,iftest,testelement)!=NIL);
    else if (testnot!=NIL) testresult=(call2(ctx,testnot,olditem,testelement)==NIL);
    else if (test!=QEQ) testresult=(call2(ctx,test,olditem,testelement)!=NIL);
    else testresult=(olditem==testelement);
    if (testresult) {
      count--;
      if (iscons(seq)) {pointer_update(ccar(seq),newitem);}
      else if (isvector(seq)) fastvset(seq,start,newitem);
      else error(E_SEQINDEX); }
    if (iscons(seq)) seq=ccdr(seq);
    start++;}
  return(argv[2]);}

/*replace vector elements in the first argument with the second argument*/
/* Bug: offset is ignored if vector is displaced to another array */

pointer VECREPLACE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register int i,count;
  register pointer src,dest;
  register byte *p, *p2;
  int srcelmt,destelmt;
  eusinteger_t ss,ds,se,de;
  numunion nu;

  ckarg2(2,6);
  dest=argv[0]; if (isarray(dest)) dest=dest->c.ary.entity;
  src=argv[1];  if (isarray(src)) src=src->c.ary.entity;
  if (!isvector(src) || !isvector(dest)) error(E_NOVECTOR);
  ds=(n==2)?0:ckintval(argv[2]);
  de=(n<=3)?vecsize(dest):ckintval(argv[3]);
  ss=(n<=4)?0:ckintval(argv[4]);
  se=(n<=5)?vecsize(src):ckintval(argv[5]);
  
  count=min(de-ds,se-ss);
  de=ds+count;
  srcelmt=elmtypeof(src);
  destelmt=elmtypeof(dest);
  if (srcelmt==ELM_BIT) {
#if (WORD_SIZE == 64)
    if (destelmt==ELM_BIT && ss==0 && ds==0 && ((count%64) == 0)) {
      /*copy word by word*/
      for (i=0; i<count/64; i++) dest->c.ivec.iv[i] = src->c.ivec.iv[i]; 
      return(argv[0]);}
#else
    if (destelmt==ELM_BIT && ss==0 && ds==0 && ((count%32) == 0)) {
      /*copy word by word*/
      for (i=0; i<count/32; i++) dest->c.ivec.iv[i] = src->c.ivec.iv[i]; 
      return(argv[0]);}
#endif
    else goto general_replace;}
  if (srcelmt==destelmt ||
      (srcelmt==ELM_BYTE || srcelmt==ELM_CHAR || srcelmt==ELM_FOREIGN) &&
      (destelmt==ELM_BYTE || destelmt==ELM_CHAR || destelmt==ELM_FOREIGN)) {
    /*speed up for  simple cases:  calculate byte count*/
    if (srcelmt!=ELM_BYTE && srcelmt!=ELM_CHAR && srcelmt!=ELM_FOREIGN)
  	{ count*=sizeof(eusinteger_t); ss*=sizeof(eusinteger_t); ds*=sizeof(eusinteger_t);}
    if (srcelmt==ELM_FOREIGN) p=src->c.foreign.chars + ss;
    else p= &(src->c.str.chars[ss]);
    if (destelmt==ELM_FOREIGN) p2=dest->c.foreign.chars + ds;
    else p2= &(dest->c.str.chars[ds]);
    if (srcelmt==ELM_FOREIGN || destelmt==ELM_FOREIGN) /*copy byte by byte*/
	for (i=0; i<count; i++) *p2++ = *p++;
    else memcpy((void *)p2, (void *)p, (size_t)count);
    return(argv[0]);}

general_replace:
  /*coercion is required*/
  /* extract src elements and place them on stack*/
  pushsequence(ctx,src,ss,count);
  if (destelmt==ELM_FOREIGN) p=dest->c.foreign.chars;
  else p=dest->c.str.chars;
  switch(destelmt) {
    case ELM_INT:	while (count-->0)
			  dest->c.ivec.iv[--de]=coerceintval(vpop());
		        break;
    case ELM_FLOAT:	while (count-->0) {
			  src=vpop();
			  dest->c.fvec.fv[--de]=ckfltval(src);}
			break;
    case ELM_POINTER: while (count-->0) {--de;pointer_update(dest->c.vec.v[de],vpop());}
			break;
    case ELM_CHAR: case ELM_BYTE: case ELM_FOREIGN:
			while (count-->0) p[--de]=coerceintval(vpop());
			break;
    case ELM_BIT:	while (count-->0) {
			  de--;
#if (WORD_SIZE == 64)
			  if (coerceintval(vpop()) & 1L)
			    dest->c.ivec.iv[de/64] |= 1L << (de%64);
			  else dest->c.ivec.iv[de/64] &= ~(1L << (de%64));
#else
			  if (coerceintval(vpop()) & 1)
			    dest->c.ivec.iv[de/32] |= 1 << (de%32);
			  else dest->c.ivec.iv[de/32] &= ~(1 << (de%32));
#endif
                        }
		        break; }
  return(argv[0]);}

    
/****************************************************************/
/* SORT --- quicker sort
/****************************************************************/

static pointer	COMPAR,COMPKEY;
static int 	COMPTYPE;
context *qsortctx;

int compar(x,y)
pointer *x, *y;
{ pointer xx,yy,result;
  eusfloat_t *fx,*fy;
  numunion nu;

  switch (COMPTYPE) {
    case ELM_CHAR: case ELM_BYTE:
		xx= makeint(*(char *)x); yy= makeint(*(char *)y); break;
    case ELM_INT: xx=makeint((eusinteger_t)(*x)); yy=makeint((eusinteger_t)(*y)); break;
    case ELM_FLOAT:
		fx=(eusfloat_t *)x; fy=(eusfloat_t *)y;
		xx=makeflt(*fx); yy=makeflt(*fy); break;
    default: xx= *x; yy= *y;}
  if (COMPKEY) {
    xx=call1(qsortctx,COMPKEY,xx);
    (*qsortctx->vsp++=((pointer)xx)); // vpush
    yy=call1(qsortctx,COMPKEY,yy);
    (*qsortctx->vsp++=((pointer)yy)); // vpush
  }
  result=call2(qsortctx,COMPAR,xx,yy);
  if (COMPKEY) {
    (*(--(qsortctx->vsp))); // vpop
    (*(--(qsortctx->vsp))); // vpop
  }
  if (result==NIL) return(1); else return(-1);}

pointer SORT(ctx,n,argv)
register context *ctx;
register int n;
pointer argv[];
{ register pointer seq,work;
  pointer *xsp;
  register int i,width;
  ckarg2(2,3);
  seq=argv[0];
  if (seq==NIL) return(NIL);

#if THREADED
  mutex_lock(&qsort_lock);
#endif
  qsortctx=ctx;
  COMPAR=argv[1];
  if (n==3) COMPKEY=argv[2]; else COMPKEY=0;
  if (islist(seq)) {	/*sort list destructively*/
    n=0;
    work=seq;
    xsp=ctx->vsp;
    while (islist(work)) { ckpush(ccar(work)); work=ccdr(work); n++;}
    COMPTYPE=ELM_FIXED;
    qsort(xsp,n,sizeof(pointer),(int (*)())compar);
    work=seq;
    for (i=0; i<n; i++) { pointer_update(ccar(work),*xsp++); work=ccdr(work);}
    ctx->vsp-=n;}
  else if (isvector(seq)) {
    COMPTYPE=elmtypeof(seq);
    if (COMPTYPE==ELM_CHAR || COMPTYPE==ELM_BYTE) width=1;
    else if (COMPTYPE==ELM_BIT || COMPTYPE==ELM_FOREIGN) error(E_NOVECTOR);
    else width=sizeof(eusinteger_t);
    qsort(seq->c.vec.v,vecsize(seq),width,(int (*)())compar);}
#if THREADED
  mutex_unlock(&qsort_lock);
#endif
  return(seq);}

pointer LENGTH(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  register int l;
  ckarg(1);
  if (isnum(a)) error(E_NOSEQ);
  if (a==NIL) return(makeint(0));
  else if (piscons(a)) {
    l=0;
    while (islist(a)) { l++; a=ccdr(a);}
    return(makeint(l));}
  else if (pisarray(a)) {
    if (a->c.ary.rank!=makeint(1)) error(E_NOSEQ);
    if (a->c.ary.fillpointer==NIL)  return(a->c.ary.dim[0]);
    else return(a->c.ary.fillpointer);}
  else if (elmtypeof(a)) return(a->c.vec.size);
  else error(E_NOSEQ);}

pointer ELT(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ register pointer a=argv[0];
  register eusinteger_t i=ckintval(argv[1]);
  ckarg(2);
  if (islist(a)) {
    if (i<0) error(E_SEQINDEX);
    while (i-->0 && islist(a)) a=ccdr(a);
    if (islist(a)) return(ccar(a));
    else error(E_SEQINDEX);}
  else if (isvector(a)) return((pointer)vref(a,i));
  else if (isarray(a) && a->c.ary.rank==makeint(1))
    return((pointer)vref(a->c.ary.entity, i));
  else error(E_USER,(pointer)"no sequence");}

pointer SETELT(ctx,n,argv)
register context *ctx;
int n;
register pointer argv[];
{ register pointer a=argv[0];		/* (setelt seq index val) */
  register eusinteger_t i=ckintval(argv[1]);
  ckarg(3);
  if (islist(a)) {
    if (i<0) error(E_SEQINDEX);
    while (i-->0 && islist(a)) a=ccdr(a);
    if (islist(a)) {pointer_update(ccar(a),argv[2]);return(argv[2]);}
    else error(E_SEQINDEX);}
  else { vset(a,i,argv[2]); return(argv[2]);}}


void sequence(ctx,mod)
register context *ctx;
pointer mod;
{
  QIDENTITY=defun(ctx,"IDENTITY",mod,IDENTITY,NULL);
  QIDENTITY=QIDENTITY->c.sym.spefunc;
  defun(ctx,"SUBSEQ",mod,SUBSEQ,NULL);
  defun(ctx,"COPY-SEQ",mod,COPYSEQ,NULL);
  defun(ctx,"REVERSE",mod,REVERSE,NULL);
  defun(ctx,"NREVERSE",mod,NREVERSE,NULL);
  defun(ctx,"CONCATENATE",mod,CONCATENATE,NULL);
  defun(ctx,"COERCE",mod,COERCE,NULL);
  defun(ctx,"MAP",mod,MAP,NULL);
  defunpkg(ctx,"RAW-FILL",mod,FILL,syspkg);
  defunpkg(ctx,"RAW-POSITION",mod,POSITION,syspkg);
  defunpkg(ctx,"RAW-FIND",mod,FIND,syspkg);
  defunpkg(ctx,"RAW-COUNT",mod,COUNT,syspkg);
  defunpkg(ctx,"UNIVERSAL-REMOVE",mod,UNIREMOVE,syspkg);
  defunpkg(ctx,"RAW-REMOVE-DUPLICATES",mod,REMOVE_DUPLICATES,syspkg);
  defunpkg(ctx,"RAW-DELETE",mod,DELETE,syspkg);
  defunpkg(ctx,"RAW-SUBSTITUTE",mod,SUBSTITUTE,syspkg);
  defunpkg(ctx,"RAW-NSUBSTITUTE",mod,NSUBSTITUTE,syspkg);
  defunpkg(ctx,"VECTOR-REPLACE",mod,VECREPLACE,syspkg);
  defun(ctx,"SORT",mod,SORT,NULL);
  defun(ctx,"LENGTH",mod,LENGTH,NULL);
  defun(ctx,"ELT",mod,ELT,NULL);
  defun(ctx,"SETELT",mod,SETELT,NULL);
  }
