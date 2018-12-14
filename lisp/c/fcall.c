/****************************************************************/
/* machine dependent compiled code runtime routines
/*	for sun3, sun4 and vax ultrix
/*	1987-Dec-23
/*	Copyright Toshihiro MATSUI
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include "../c/eus.h"

/* 
/* s u n 4 / S P A R C
*/

pointer fcallx(ctx,n,argv,fslot,sym)
register context *ctx;
int n;
pointer *argv,sym;
pointer (**fslot)();
{ eusinteger_t x;
  pointer fn;
  pointer (*subr)();

  fn=getfunc(ctx,sym);

  if (ispointer(fn) && (fn->cix==codecp.cix)) {
#if (WORD_SIZE == 64)
    x= (eusinteger_t)(fn->c.code.entry); x &= ~3L;
#else
    x= (eusinteger_t)(fn->c.code.entry); x &= ~3;
#endif
#if ARM
    if (fn->c.code.entry2 != NIL) {
#if (WORD_SIZE == 64)
      x = x | (intval(fn->c.code.entry2)&0x00000000ffffffff);
#else
      x = x | (intval(fn->c.code.entry2)&0x0000ffff);
#endif
    }
#endif
    subr=(pointer (*)())(x);
    *fslot= subr;
    return((*subr)(ctx,n,argv));
    }
  else return(ufuncall(ctx,sym,sym,(pointer)argv,0,n));}

/*
/*  s u n 3 / M 6 8 0 2 0 
*/

#if sun3 || news || sanyo
pointer fcall(n,argv,sym)
int n;
pointer argv[];
pointer sym;
{ register int *r= &n;
  int x;
  pointer fn,result;
  pointer (*subr)();

  fn=getfunc(sym);

  if (ispointer(fn) && (fn->cix==codecp.cix)) {
    subr=(pointer (*)())
	  ((int)(fn->c.code.codevec)+(intval(fn->c.code.entry)));
    x=r[-1];	/*return addr .i.e. next instruction address to be executed*/
    r=(int *)(x-4);	/*operand for the bsrl inst.*/
    if ((r[-1] & 0x0000ff00) == 0x6100)	*r = (int)subr-x+4; /*bsr.l*/
    else  *r = (int)subr; /*news and SunOS4.0 uses jsr.l instead of bsr.l*/
/* assembler format slightly differs between sun3 and news*/
#if sun3
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
    asm("	cmpl	#0x12345678,d0\n");	/*purge cache*/
#endif
#if news
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
    asm("	cmp.l	#0x12345678,d0");	/*purge cache*/
#endif
#if sanyo
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
    asm("	cmp.l	%d0,&0x12345678");	/*purge cache*/
#endif
    return((*subr)(n,argv)); }
  else return(ufuncall(sym,sym,argv,0,n));}

#endif

/*
/*  V A X
*/

#if vax
pointer fcall(n,argv,sym)
int n;
pointer argv[];
pointer sym;
{ pointer fn;
  pointer (*subr)();
  int *stackframe;
  int *returnaddress;

  fn=getfunc(sym);

  if (ispointer(fn) && (fn->cix==codecp.cix)) {

    subr=(pointer (*)())
	  ((int)(fn->c.code.codevec)
	   +((int)(fn->c.code.entry)>>2));

    stackframe= &n;
    returnaddress=(int *)stackframe[-2];
    returnaddress[-1]=(int)subr-(int)returnaddress;
    fn=(*subr)(n,argv);
    return(fn);    }
  else return(ufuncall(sym,sym,argv,0,n));}

#endif

/*
#if mips && !IRIX
pointer fcall(n,argv,sym)
int n;
register pointer argv[];
register pointer sym;
{ pointer fn;
  pointer (*subr)();

  fn=getfunc(sym);

  if (ispointer(fn) && (fn->cix==codecp.cix)) {

    subr=(pointer (*)())
	  ((int)(fn->c.code.codevec)
	   +((int)(fn->c.code.entry)>>2));

    fn=(*subr)(n,argv);
    return(fn);    }
  else return(ufuncall(sym,sym,argv,0,n));}

#endif
*/

