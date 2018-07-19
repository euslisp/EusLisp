/****************************************************************/
/* eus.h	Etl, Umezono, Sakura-mura Lisp
/*	@(#)$Id$
/*	Copyright(c)1988, Toshihiro Matsui, Electrotechnical Laboratory,
/*	all rights reserved, all wrongs left.
/*	created on:	1986-May
/*	needed to be included by all euslisp kernel (.c) files and
/*	user functions compiled by euscomp.
/****************************************************************/


#if (alpha || IRIX6 || x86_64 || aarch64)
#define WORD_SIZE 64
#else
#define WORD_SIZE 32
#endif

#if (WORD_SIZE == 64)
typedef long eusinteger_t;
typedef double eusfloat_t;
#define WORDSHIFT 3
#else
typedef int eusinteger_t;
typedef float eusfloat_t;
#define WORDSHIFT 2
#endif
#define wordsizeof(type) (sizeof(type)>>WORDSHIFT)

#if GCC || Solaris2 || IRIX || Linux || IRIX6
#define USE_STDARG
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#endif

#if alpha
#include <stdlib.h>
#include <unistd.h>
#include <values.h>
#define	USE_STDARG
#endif

#if defined(Darwin) || defined(Linux) || defined(Linux64)
#define cfree free
#endif

#ifdef USE_STDARG
#include <stdarg.h>
#else
#include <varargs.h>
#endif

#if Cygwin
#define T	LISPT
#define READ	LISPREAD
#define cfree	free
#endif

#if vxworks
#include <vxWorks.h>
#include <stdioLib.h>
#define errno errnoGet()
#else
#include <stdio.h>
#ifndef __cplusplus
#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x<y)?y:x)
#endif
#endif

#if (WORD_SIZE == 64)
extern eusinteger_t setjmp_val;
#define eussetjmp(buf) (_setjmp(buf)?setjmp_val:(eusinteger_t)0)
#define euslongjmp(buf,val) (setjmp_val=(eusinteger_t)(val),_longjmp(buf,1))
#else
#if (Solaris2 || vxworks)
#define eussetjmp(buf) (eusinteger_t)setjmp(buf)
#define euslongjmp(buf,val) longjmp(buf,(int)(val))
#include <synch.h>
#else
#define eussetjmp(buf) (eusinteger_t)_setjmp(buf)
#define euslongjmp(buf,val) _longjmp(buf,(int)(val))
#endif
#endif

#include <setjmp.h>
#include <string.h>

#define ERR (-1)
#define	STOPPER	((pointer)0L)	/*impossible pointer object*/
#define	UNBOUND	((pointer)0L)

/* dynamic value type */
#define V_CONSTANT	((pointer)((0<<2)+2)) // makeint(0)
#define V_VARIABLE	((pointer)((1<<2)+2)) // makeint(1)
#define V_GLOBAL	((pointer)((2<<2)+2)) // makeint(2)
#define V_SPECIAL	((pointer)((3<<2)+2)) // makeint(3)

/* function types*/
#define SUBR_FUNCTION	((pointer)((0<<2)+2)) // makeint(0)
#define SUBR_MACRO	((pointer)((1<<2)+2)) // makeint(1)
#define SUBR_SPECIAL	((pointer)((2<<2)+2)) // makeint(2)
#define SUBR_ENTRY	((pointer)((3<<2)+2)) // makeint(3)

/* stack frame types (lots more)*/
#define BLOCKFRAME	((pointer)((0<<2)+2)) // makeint(0)
#define TAGBODYFRAME	((pointer)((1<<2)+2)) // makeint(1)

/*vector element types*/
#define ELM_FIXED	0
#define ELM_BIT		1
#define ELM_CHAR	2
#define ELM_BYTE	3
#define ELM_INT		4
#define ELM_FLOAT	5
#define ELM_FOREIGN	6
#define ELM_POINTER	7

/* machine architecture dependent constants*/
/* MASK & long removes the MSB (sign bit) */

#if (WORD_SIZE == 64)
#define MASK 0x7fffffffffffffff
#define	MSB  0x8000000000000000
#else
#define MASK 0x7fffffff
#define MSB  0x80000000
#endif

/****************************************************************/
/* configuration constants					*/
/****************************************************************/

#define DEFAULTCHUNKINDEX	16	/*fib2(12)=754*/
#define MAXBUDDY	40	/*fib(30) is big enough*/
	/*MAXBUDDY must be smaller than 2^bix, where bix is 6bit, 
	 63 at most.
	 fib(29) nealy equals to 2.4M,
	 fib(30) to 4M words*/
#define MAXTHRBUDDY	6	/*small free cells cached thread-locally*/
#define MAXSTACK	8388608	/* patched: default stack size 16bit -> 23bit, can be expanded by sys:newstack*/
#define SYMBOLHASH	60	/*initial obvector size in package*/
#define MAXCLASS	4096	/* by M.Inaba from 64 */
#define KEYWORDPARAMETERLIMIT 128	/* patched: default keyword size 32->128 */
#define ARRAYRANKLIMIT	7	/*minimal requirement for CommonLisp*/
#define MAXTHREAD	64	/*maximum number of threads*/
#define MAX_SPECIALS	512	/*maximum number of special variables*/
#if (WORD_SIZE == 64)
#define MAXPOSFIXNUM (0x1fffffffffffffff)
#define MINNEGFIXNUM (0xe000000000000000)
#else
#define MAXPOSFIXNUM (0x1fffffff)
#define MINNEGFIXNUM (0xe0000000)
#endif

/* type definitions:
	bix is buddy index,
	and cix is class index, which is sometimes refered as cid */

typedef unsigned char byte;
typedef unsigned short word;	/*seldom used*/
typedef struct cell *pointer;

#ifdef RGC
#include "external_markbits.h"
#include "time.h"
#include "collector.h"
#else
#define GC_POINT
#define GC_REGION(cmp_statement) cmp_statement
#endif

struct cellheader {
  unsigned mark:1;	/* GC mark*/
  unsigned b:1;		/* buddy: indicates the side in which its buddy should be found */
  unsigned m:1;		/* memory: records b or m of parent cell when it's split*/
  unsigned smark:1;	/* shared mark*/
  unsigned pmark:1;	/* print mark*/
  unsigned elmtype:3;
  unsigned nodispose:1;
#ifdef RGC
  unsigned bix:7;
#else
  unsigned extra:1;
  unsigned bix:6;		/*5 bits are enough*/
#endif
  short	   cix;};	/*8 bits may be enough*/

/****************************************************************/
/* struct definition for lisp object cell
/****************************************************************/
struct cons {
    pointer car,	/*cons is made of a car and a cdr*/
	    cdr;};	/*what a familiar structure!*/

struct propertied_object {
    pointer plist;};

struct symbol {
    pointer plist,	/*inherited from prop_obj*/
	    speval,
	    vtype,	/*const,var,special*/
	    spefunc,
	    pname,
	    homepkg;};

struct string {		/*resembles with vector*/
    pointer length;	/*boxed*/
    byte chars[1];};	/*long word aligned*/

struct foreign {
    pointer length;
    byte *chars; };

struct package {
    pointer plist;
    pointer names;	/*package name at car, nicknames in cdr*/
    pointer use;	/*spreaded use-package list*/
    pointer symvector;	/*hashed obvector*/
    pointer symcount;	/*number of interned symbols in this package*/
    pointer intsymvector;
    pointer intsymcount;
    pointer shadows;
    pointer used_by;
    };

struct code {
    pointer codevec;
    pointer quotevec;
    pointer subrtype;	/*function,macro,special*/
    pointer entry;	/*offset from beginning of codevector*/
#if ARM
    pointer entry2;     /* some archtecture did not set code on 4 byte alignment */
#endif
    };

struct fcode {		/*foreign function code*/
    pointer codevec;
    pointer quotevec;
    pointer subrtype;
    pointer entry;
  pointer entry2;    /* kanehiro's patch 2000.12.13 */
    pointer paramtypes;
    pointer resulttype;};

struct ldmodule {	/*foreign language object module*/
    pointer codevec;
    pointer quotevec;
    pointer subrtype;	/*function,macro,special*/
    pointer entry;
#if ARM
    pointer entry2;     /* some archtecture did not set code on 4 byte alignment */
#endif
    pointer symtab;
    pointer objname;
    pointer handle;};	/* dl's handle */

struct closure {
    pointer codevec;
    pointer quotevec;
    pointer subrtype;	/*function,macro,special*/
    pointer entry;	/*offset from beginning of codevector*/
#if ARM
    pointer entry2;     /* some archtecture did not set code on 4 byte alignment */
#endif
    pointer env0;	/*upper closure link*/
    pointer *env1;	/*argument pointer:	argv*/
    pointer *env2;};	/*local variable frame:	local*/

struct stream {
    pointer plist;
    pointer direction;
    pointer buffer;
    pointer count;
    pointer tail;};

struct filestream {
    pointer plist;
    pointer direction;
    pointer buffer;
    pointer count;
    pointer tail;
    pointer fd;
    pointer fname;};

struct iostream {
    pointer plist;
    pointer in,out;};

struct labref {		/*used for reading labeled forms: #n#,#n=*/
    pointer label;
    pointer value;
    pointer unsolved;
    pointer next; };

struct vector {
    pointer size;
    pointer v[1];};

struct intvector {
    pointer length;
    eusinteger_t iv[1];};

struct floatvector {
    pointer length;
    eusfloat_t fv[1];};

struct arrayheader {
  pointer plist;
  pointer entity,
	  rank,
	  fillpointer,
	  offset,
	  dim[ARRAYRANKLIMIT];};

/* structs for object oriented programming */
struct object {
  pointer iv[2];};	/*instance variables*/

struct _class {
  pointer plist;
  pointer name;		/*class name symbol*/
  pointer super;	/*super class*/
  pointer cix;
  pointer vars;		/*var names including inherited ones*/
  pointer types;
  pointer forwards;
  pointer methods;	/*method list*/
  };

struct vecclass {	/*vector class*/
  pointer plist;
  pointer name;
  pointer super;
  pointer cix;
  pointer vars;
  pointer types;
  pointer forwards;
  pointer methods;
  pointer elmtype;
  pointer size;};

struct readtable {
  pointer plist;
  pointer syntax;
  pointer macro;
  pointer dispatch;
  pointer readcase;};

struct threadport {
  pointer plist;
  pointer id;
  pointer requester;
  pointer reqsem;
  pointer runsem;
  pointer donesem;
  pointer func;
  pointer args;
  pointer result;
  pointer contex;
  pointer idle;
  pointer wait;};

/* extended numbers */
struct ratio {
  pointer numerator;
  pointer denominator;};

struct complex {
  pointer real;
  pointer imaginary;};

struct bignum {
  pointer size;
  pointer bv;}; /*bignum vector*/

/****************************************************************/
typedef 
  struct cell {
#if vax || sun4 || news || mips || i386 || i486 || i586 || alpha || x86_64 || ARM
    unsigned mark:1;
    unsigned b:1;
    unsigned m:1;
    unsigned smark:1;
    unsigned pmark:1;
    unsigned elmtype:3;
    unsigned nodispose:1;
#ifdef RGC
    unsigned bix:7;
#else
    unsigned extra:1;
    unsigned bix:6;
#endif
#endif
    short cix;
    union cellunion {
      struct cons cons;
      struct symbol sym;
      struct string str;
      struct foreign foreign;
      struct package pkg;
      struct stream stream;
      struct filestream fstream;
      struct iostream iostream;
      struct code code;
      struct fcode fcode;
      struct ldmodule ldmod;
      struct closure clo;
      struct labref lab;
      struct arrayheader ary;
      struct vector vec;
      struct floatvector fvec;
      struct intvector ivec;
      struct object obj;
      struct _class cls;
      struct vecclass vcls;
      struct readtable rdtab;
      struct threadport thrp;
      struct ratio ratio;
      struct complex cmplx;
      struct bignum  bgnm;
      } c;
    } cell;

typedef 
  union numunion {
    eusfloat_t   fval;
    eusinteger_t ival;
#if vax
    struct {short low,high;} sval;
#endif
/*    struct { signed sival:30; unsigned tag:2;} tval; */
    } numunion;

/* buddy cell */
struct bcell {
    struct cellheader h;
    union {
      struct bcell *nextbcell;
      struct cell  *c[2];} b;} /* bcell */;

typedef struct bcell *bpointer;

struct chunk {
  struct chunk *nextchunk;
  int chunkbix;
  struct bcell rootcell;};

typedef struct {
	short cix;
	short sub;} cixpair;

enum ch_type {
	ch_illegal,
	ch_white,
	ch_comment,
	ch_macro,
	ch_constituent,
	ch_sglescape,
	ch_multiescape,
	ch_termmacro,
	ch_nontermacro};

enum ch_attr {
	alphabetic,package_marker,illegal,alphadigit};


/****************************************************************/
/* stack frames and context
/****************************************************************/
struct callframe {
  struct  callframe *vlink;
  pointer form;
  };

struct bindframe {	/*to achieve lexical binding in the interpreter*/
  struct  bindframe *dynblink, *lexblink;	/*links to upper level*/
  pointer sym;		/*symbol*/
  pointer val;};	/*bound value*/

struct specialbindframe {	/*special value binding frame*/
  struct  specialbindframe *sblink;
  pointer sym;		/*pointer to the symbol word(dynval or dynfunc)*/
  pointer oldval;};

struct blockframe {
  pointer kind;
  struct  blockframe *dynklink,*lexklink;
  pointer name;
  jmp_buf *jbp;};

struct catchframe {
  struct  catchframe *nextcatch;
  pointer label;
  struct  bindframe *bf;	/*bind frame save*/
  struct  callframe *cf;	/*call frame save*/
  struct  fletframe *ff;
  jmp_buf *jbp;
  };

struct protectframe {
  struct protectframe *protlink;
  pointer cleaner;	/*cleanup form closure*/
  };

struct  fletframe {
  pointer name;
  pointer fclosure;
  struct  fletframe *scope;
  struct  fletframe *lexlink;
  struct  fletframe *dynlink;};

#define MAXMETHCACHE 256 /*must be power to 2*/

struct methdef {
  pointer selector,class,ownerclass,method;
  } /*methcache[MAXMETHCACHE]*/; 

/* thread context */

typedef struct {
	pointer	*stack, *vsp,*stacklimit;
#ifdef RGC
    pointer *gcstack, *gsp, *gcstacklimit;
#endif
	struct	callframe	*callfp;
	struct	catchframe	*catchfp;
	struct	bindframe	*bindfp;
	struct	specialbindframe *sbindfp;
	struct	blockframe	*blkfp;
	struct	protectframe	*protfp;
	struct  fletframe	*fletfp, *newfletfp;
	pointer lastalloc;
	pointer errhandler;
	pointer threadobj;
	struct  methdef		*methcache;
	struct  buddyfree	*thr_buddy;
	int	alloc_big_count;
	int	alloc_small_count;
	int	special_bind_count;
	int	slashflag;
	pointer specials;
        int     intsig;
#ifdef __RETURN_BARRIER
    rbar_t rbar;  /* some extra words are needed? */
#else
	long	extra[10];	/* 32 long words */
#endif
#ifdef __GC_ALLOC_DRIVEN
    int my_gc_pri;
#endif
        }
	context;

/****************************************************************
/* memory and class management structures
/****************************************************************/
extern long buddysize[MAXBUDDY+1];

extern struct buddyfree {
  int count;	/*number of free cells*/
  bpointer bp;}  buddy[MAXBUDDY+1];

struct class_desc {	/* per- class descripter */
  short cix;
  short subcix;
  pointer def; };

struct built_in_cid {
  pointer cls;
  cixpair *cp; };

#if THREADED
#include "eus_thr.h"	/* thread definition by APT */
#endif


/****************************************************************/
/* global variables for eus
/*	date:	1986-Apr
/*	1987-Apr
/****************************************************************/
/* process id and program name*/
extern eusinteger_t mypid;
extern char *progname;

/* heap management */
/* every free cell is linked to the buddybase structure*/
extern struct buddyfree buddy[MAXBUDDY+1];
extern struct chunk *chunklist;
extern char *maxmemory;
extern long freeheap, totalheap;	/*size of heap left and allocated*/

/* memory management timers for performance evaluation */
extern long gccount,marktime,sweeptime;
extern long alloccount[MAXBUDDY];

/* System internal objects are connected to sysobj list
/* to protect from garbage-collection */
extern pointer sysobj;
extern pointer lastalloc;

/* thread euscontexts */
extern context *euscontexts[MAXTHREAD];

/****************************************************************/
/* system defined (built-in) class index
/*	modified to accept  dynamic type extension (1987-Jan)
/****************************************************************/

extern cixpair objectcp;
extern cixpair conscp;
extern cixpair propobjcp;
extern cixpair lockablecp;
extern cixpair symbolcp;
extern cixpair packagecp;
extern cixpair streamcp;
extern cixpair filestreamcp;
extern cixpair iostreamcp;
extern cixpair metaclasscp;
extern cixpair vecclasscp;
extern cixpair codecp;
extern cixpair fcodecp;
/*cixpair modulecp; */
extern cixpair ldmodulecp;
extern cixpair closurecp;
extern cixpair labrefcp;
extern cixpair threadcp;
extern cixpair arraycp;
extern cixpair readtablecp;
extern cixpair vectorcp;
extern cixpair fltvectorcp;
extern cixpair intvectorcp;
extern cixpair stringcp;
extern cixpair bitvectorcp;
/*extended numbers*/
extern cixpair extnumcp;
extern cixpair ratiocp;
extern cixpair complexcp;
extern cixpair bignumcp;

extern struct built_in_cid  builtinclass[64];
extern int nextbclass;


/*symbol management*/
extern pointer pkglist,lisppkg,keywordpkg,userpkg,syspkg,unixpkg,xpkg;
extern pointer NIL,PACKAGE,T,QUOTE;
extern pointer FUNCTION;
extern pointer QDECLARE,QSPECIAL;
#if SunOS4_1 /* SELF is already used on SunOS 4.1.x. */
extern pointer QSELF;
#else
extern pointer SELF;
#endif
extern pointer CLASS;
extern pointer STDIN,STDOUT,ERROUT,QSTDIN,QSTDOUT,QERROUT;
extern pointer QINTEGER,QFIXNUM,QFLOAT,QNUMBER;
extern pointer TOPLEVEL,QEVALHOOK,ERRHANDLER;
extern pointer QGCHOOK, QEXITHOOK;
extern pointer QUNBOUND,QDEBUG;
extern pointer QTHREADS;
extern pointer QEQ,QEQUAL,QNOT;
extern pointer QAND, QOR, QNOT;

/*memory management parameters*/
extern pointer GCMERGE,GCMARGIN;

/* keywords */
extern pointer K_IN,K_OUT,K_IO;	/*direction keyword*/
extern pointer K_FLUSH,K_FILL,K_FILE,K_STRING;
extern pointer K_NOMETHOD,K_BIT,K_BYTE,K_CHAR,K_SHORT,K_LONG,K_INTEGER,K_POINTER;
extern pointer K_FLOAT32,K_FLOAT,K_DOUBLE,K_FOREIGN, K_FOREIGN_STRING;
extern pointer K_DOWNCASE,K_UPCASE, K_PRESERVE, K_INVERT, K_CAPITALIZE;

/*class management*/
extern struct class_desc classtab[MAXCLASS];
extern int nextcix;

/*class cells*/
extern pointer C_CONS, C_OBJECT, C_SYMBOL, C_PACKAGE;
extern pointer C_STREAM, C_FILESTREAM, C_IOSTREAM, C_CODE, C_FCODE;
extern pointer C_LDMOD;
extern pointer C_VECTOR, C_METACLASS, C_CLOSURE, C_LABREF;
extern pointer C_THREAD;
extern pointer C_VCLASS, C_FLTVECTOR, C_INTVECTOR, C_STRING, C_BITVECTOR;
extern pointer C_FOREIGNCODE,C_ARRAY,C_READTABLE;
extern pointer C_EXTNUM, C_RATIO, C_COMPLEX, C_BIGNUM;

/*class names*/
extern pointer QCONS,STRING,STREAM,FILESTREAM,IOSTREAM,SYMBOL,	
	CODE, FCODE,LDMODULE, PKGCLASS,METACLASS,CLOSURE,LABREF;
extern pointer THREAD;
extern pointer VECTOR,VECCLASS,FLTVECTOR,INTVECTOR,OBJECT,READTABLE;
extern pointer FOREIGNCODE,ARRAY,BITVECTOR;
extern pointer EXTNUM, RATIO, COMPLEX, BIGNUM;

/*toplevel & evaluation control*/
extern int intsig; /*0:no signal, 1-32:pending, -1:in progress*/
extern int intcode;
extern int ehbypass;

/*reader variables*/
extern pointer charmacro[256];
extern pointer sharpmacro[256];
extern int export_all;

/****************************************************************/
/* macro definition for euslisp
/****************************************************************/

#ifdef RGC
#define carof(p,err) (islist(p)?(p)->c.cons.car:(pointer)error(E_DUMMY5,(pointer)(err)))
#define cdrof(p,err) (islist(p)?(p)->c.cons.cdr:(pointer)error(E_DUMMY5,(pointer)(err)))
#define alloc rgc_alloc
#else
#define carof(p,err) (islist(p)?(p)->c.cons.car:(pointer)error(E_DUMMY3,(pointer)(err)))
#define cdrof(p,err) (islist(p)?(p)->c.cons.cdr:(pointer)error(E_DUMMY3,(pointer)(err)))
#define alloc gc_alloc
#endif
#define ccar(p) ((p)->c.cons.car)
#define ccdr(p) ((p)->c.cons.cdr)
#define cixof(p) ((p)->cix)
#define classof(p) (ispointer(p)?classtab[(p)->cix].def:(pointer)error(E_NOOBJECT))
#define subcixof(p) (classtab[(p)->cix].subcix)
#define speval(p) ((p)->c.sym.speval)
#define spevalof(p,x) (ctx->specials->c.vec.v[x])
#define Spevalof(p) (ctx->specials->c.vec.v[intval((p)->c.sym.vtype)])
#define SPEVALOF(p) (((p)->c.sym.vtype>=V_SPECIAL)? \
	ctx->specials->c.vec.v[intval((p)->c.sym.vtype)]: \
	(p)->c.sym.speval)
#define superof(p) ((p)->c.cls.super)

#if sun3 || apollo || (system5 && !alpha && !mips) || sanyo || vxworks || NEXT
#define makepointer(bp) ((pointer)((eusinteger_t)(bp) | 2))
#define isint(p) (!((eusinteger_t)(p) & 3))
#define isflt(p) (((eusinteger_t)(p) & 3)==1)
#define isnum(p) (((eusinteger_t)(p) & 2)==0)
#define ispointer(p) ((eusinteger_t)(p) & 2)
#define makeint(v) ((pointer)(((eusinteger_t)v)<<2))
#define bpointerof(p) ((bpointer)((eusinteger_t)(p)-2))
#endif

#if vax || sun4 || news || mips || i386 || i486 || i586 || alpha || x86_64 || ARM

#define makepointer(bp) ((pointer)((eusinteger_t)(bp)))
// #define isint(p) (((eusinteger_t)(p) & 3)==2) // org
#define	isint(p)	( (((eusinteger_t)(p)&3)==2) || (((eusinteger_t)(p)&0x3)==0x3) )
#define isflt(p) (((eusinteger_t)(p) & 3)==1)
#define isnum(p) (((eusinteger_t)(p) & 3))
#define ispointer(p) (!((eusinteger_t)(p) & 3))
// #define makeint(v) ((pointer)((((eusinteger_t)(v))<<2)+2)) // org
#ifdef __cplusplus
extern "C" {
#endif
extern pointer makeint(eusinteger_t v);
#ifdef __cplusplus
}
#endif

#define bpointerof(p) ((bpointer)((eusinteger_t)(p)))
#ifdef RGC
#define nextbuddy(p) ((bpointer)((eusinteger_t)(p)+(buddysize[(p->h.bix)&TAGMASK]*sizeof(pointer))))
#else
#define nextbuddy(p) ((bpointer)((eusinteger_t)(p)+(buddysize[p->h.bix]*sizeof(pointer))))
#endif
#ifndef __USE_MARK_BITMAP
#define marked(p)  (p->h.mark)
#define markon(p)  p->h.mark=1
#define markoff(p) p->h.mark=0
#endif
#endif

// #define intval(p) (((eusinteger_t)(p))>>2) // org
#ifdef __cplusplus
extern "C" {
#endif
extern eusinteger_t intval(pointer p);
#ifdef __cplusplus
}
#endif
#define ckintval(p) ((isint(p)||                                        \
		      (isbignum(p)&&                                    \
		       ((vecsize((p)->c.bgnm.bv)==1)||                  \
			((vecsize((p)->c.bgnm.bv)==2)&&((p)->c.bgnm.bv->c.ivec.iv[1]<2))))) \
		     ?intval(p):(eusinteger_t)error(E_NOINT))
#define bigintval(x) (isint(x)?intval(x):\
   (isbignum(x)?\
	((vecsize((x)->c.bgnm.bv)>=2)?\
	 (((x)->c.bgnm.bv->c.ivec.iv[1]<<(WORD_SIZE-1)) | ((x)->c.bgnm.bv->c.ivec.iv[0])): \
         ((x)->c.bgnm.bv->c.ivec.iv[0])):\
	(eusinteger_t)error(E_NOINT)) )
#define mkbigint(y) \
  (pointer)((((y)^((y)>>1))&(eusinteger_t)3<<(WORD_SIZE-3))?makebig1(y):makeint(y))

#define elmtypeof(p) (bpointerof(p)->h.elmtype)
#ifdef RGC
#define bixof(p) (bpointerof(p)->h.bix & TAGMASK)
#else
#define bixof(p) (bpointerof(p)->h.bix)
#endif

#if sun3 || sun4 || system5 || apollo || news || sanyo || vxworks || mips || NEXT || i386 || i486 || i586 || x86_64 || ARM
#if (WORD_SIZE == 64)
#define fltval(p) (nu.ival=((eusinteger_t)(p) & ~3L), nu.fval)
#define makeflt(f) (nu.fval=(eusfloat_t)(f), (pointer)((nu.ival & ~3L) | 1L))
#else
#define fltval(p) (nu.ival=((eusinteger_t)(p) & ~3), nu.fval)
#define makeflt(f) (nu.fval=(eusfloat_t)(f), (pointer)((nu.ival & ~3) | 1))
#endif

/*#if GCC
#define makeflt(f) (nu.fval=(f), (pointer)((nu.ival & (~2)) | 1)) 
#define makeflt(f) (nu.fval=(f),nu.tval.tag=1,(pointer)(nu.ival))
#endif */

#define ckfltval(p) (isflt(p)?fltval(p):\
	(isint(p)?intval(p):\
	(pisbignum(p)?big_to_float(p):\
	(pisratio(p)?ratio2flt(p):\
	(eusinteger_t)error(E_NONUMBER)))))
#endif

/*predicates to test object type*/
#define pislist(p)  (p->cix<=conscp.sub)
#define piscons(p)  (p->cix<=conscp.sub)
#define pispropobj(p) (propobjcp.cix<=(p)->cix && (p)->cix<=propobjcp.sub)
#define ispropobj(p) (ispointer(p) && pispropobj(p))
#define pissymbol(p) (symbolcp.cix<=(p)->cix && (p)->cix<=symbolcp.sub)
#define issymbol(p) (ispointer(p) && pissymbol(p))
#define pisstring(p)  (stringcp.cix<=(p)->cix && (p)->cix<=stringcp.sub)
#define isstring(p) (ispointer(p) && pisstring(p))
#define islist(p) (ispointer(p) && pislist(p))
#define iscons(p) (ispointer(p) && piscons(p))
#define piscode(p) (codecp.cix<=(p)->cix && (p)->cix<=codecp.sub)
#define iscode(p) (ispointer(p) && piscode(p))
#define pisfcode(p) (fcodecp.cix<=(p)->cix && (p)->cix<=fcodecp.sub)
#define isfcode(p) (ispointer(p) && pisfcode(p))
#define pisldmod(p) (ldmodulecp.cix<=(p)->cix && (p)->cix<=ldmodulecp.sub)
#define isldmod(p) (ispointer(p) && pisldmod(p))
#define pisstream(p) (streamcp.cix<=(p)->cix && (p)->cix<=streamcp.sub)
#define isstream(p) (ispointer(p) && pisstream(p))
#define pisfilestream(p) (filestreamcp.cix<=(p)->cix && (p)->cix<=filestreamcp.sub)
#define isfilestream(p) (ispointer(p) && pisfilestream(p))
#define pisiostream(p) (iostreamcp.cix<=(p)->cix && (p)->cix<=iostreamcp.sub)
#define isiostream(p) (ispointer(p) && pisiostream(p))
#define pisreadtable(p) (readtablecp.cix<=((p)->cix) && ((p)->cix)<=readtablecp.sub)
#define isreadtable(p) (ispointer(p) && pisreadtable(p))
#define pisarray(p) (arraycp.cix<=((p)->cix) && ((p)->cix)<=arraycp.sub)
#define isarray(p) (ispointer(p) && pisarray(p))
#define pisvector(p) (elmtypeof(p))
#define isvector(p) (ispointer(p) && pisvector(p))
#define isfltvector(p) (ispointer(p) && (elmtypeof(p)==ELM_FLOAT))
#define isptrvector(p) (ispointer(p) && (elmtypeof(p)==ELM_POINTER))
#define isintvector(p) (ispointer(p) && (elmtypeof(p)==ELM_INT))
#define pisclass(p) (metaclasscp.cix<=(p)->cix && (p)->cix<=metaclasscp.sub)
#define isclass(p) (ispointer(p) && pisclass(p))
#define pisvecclass(p) (vecclasscp.cix<=(p)->cix && (p)->cix<=vecclasscp.sub)
#define isvecclass(p) (ispointer(p) && pisvecclass(p))
#define pispackage(p) (packagecp.cix<=(p)->cix && (p)->cix<=packagecp.sub)
#define ispackage(p) (ispointer(p) && pispackage(p))
#define pisclosure(p) (closurecp.cix<=(p)->cix && (p)->cix<=closurecp.sub)
#define isclosure(p) (ispointer(p) && pisclosure(p))
#define pislabref(p) (labrefcp.cix<=(p)->cix && (p)->cix<=labrefcp.sub)
#define islabref(p) (ispointer(p) && pislabref(p))
/* extended numbers */
#define pisextnum(p) (extnumcp.cix<=(p)->cix && (p)->cix<=extnumcp.sub)
#define isextnum(p) (ispointer(p) && pisextnum(p))
#define pisratio(p) (ratiocp.cix<=(p)->cix && (p)->cix<=ratiocp.sub)
#define isratio(p) (ispointer(p) && pisratio(p))
#define piscomplex(p) (complexcp.cix<=(p)->cix && (p)->cix<=complexcp.sub)
#define iscomplex(p) (ispointer(p) && piscomplex(p))
#define pisbignum(p) (bignumcp.cix<=(p)->cix && (p)->cix<=bignumcp.sub)
#define isbignum(p) (ispointer(p) && pisbignum(p))

#define strlength(p) ((int)intval((p)->c.str.length))
#define vecsize(p) ((int)intval((p)->c.vec.size))
#define objsize(p) ((int)vecsize(classof(p)->c.cls.vars))

/* bignum */
#define bigsize(x) vecsize((x)->c.bgnm.bv)
#define bigvec(x) (x)->c.bgnm.bv->c.ivec.iv

/*stack*/
#define current_ctx (euscontexts[thr_self()])
#ifdef STACK_DEBUG
#define	vpush(v) (*ctx->vsp++=p_print((pointer)(v),ctx))
#define vpop() (printf("vpop:[0x%lx]=0x%lx\n",ctx->vsp-1,(ctx->vsp)[-1]),*(--(ctx->vsp)))
#else
#define vpush(v) (*ctx->vsp++=((pointer)v))
#define vpop() (*(--(ctx->vsp)))
#endif
#define ckpush(v) (ctx->vsp<ctx->stacklimit?vpush(v):(pointer)error(E_STACKOVER))

#define ckarg(req) if (n!=(req)) error(E_MISMATCHARG)
#define ckarg2(req1,req2) if ((n<(req1))||((req2)<n)) error(E_MISMATCHARG)

#define breakck if (ctx->intsig>0) sigbreak()
#define stackck if (ctx->vsp>ctx->stacklimit) error(E_STACKOVER)
#define debug (speval(QDEBUG)!=NIL)

#ifndef RGC
#define pointer_update(l,r) { (l)=(r); }
#define take_care(p)

#endif


/****************************************************************/
/* error code definition
/*	1986-Jun-17
/****************************************************************/

enum errorcode {
/* first 10 codes are fatal errors */
  E_NORMAL,		/*0*/
  E_STACKOVER,		/*stack overflow*/
  E_ALLOCATION,
#ifdef RGC
  E_GCSTACKOVER,
  E_PSTACKOVER,
#else
  E_DUMMY3,
  E_DUMMY4,
#endif
  E_DUMMY5,
  E_DUMMY6,
  E_DUMMY7,
  E_DUMMY8,
  E_DUMMY9,
  E_DUMMY10,
#define E_FATAL 10
/* followings are not fatal errors */
  E_SETCONST,		/*11 attempt to set to constant*/
  E_UNBOUND,
  E_UNDEF,
  E_MISMATCHARG,
  E_ILLFUNC,
  E_ILLCH,
  E_READ,
  E_WRITE,
  E_LONGSTRING,		/*19: string too long*/
  E_NOSYMBOL,		/*20: symbol expected*/
  E_NOLIST,		/*list expected*/
  E_LAMBDA,		/*illegal lambda form*/
  E_PARAMETER,		/*illegal lambda parameter syntax*/  
  E_NOCATCHER,		/*no catch block */
  E_NOBLOCK,		/*no block to return*/
  E_STREAM,		/*stream expected*/
  E_IODIRECTION,	/*io stream direction keyword*/
  E_NOINT,		/*integer value expected*/
  E_NOSTRING,		/*string expected*/
  E_OPENFILE,		/*30: error in open*/
  E_EOF,		/*EOF encountered*/
  E_NONUMBER,		/*number expected*/
  E_CLASSOVER,		/*class table overflow*/
  E_NOCLASS,		/*class expected*/
  E_NOVECTOR,		/*vector expected*/
  E_VECSIZE,		/*error of vector size*/
  E_DUPOBJVAR,		/*duplicated object variable name*/
  E_INSTANTIATE,	/*38: cannot make an instance*/
  E_ARRAYINDEX,
  E_NOMETHOD,		/*40*/
  E_CIRCULAR,
  E_SHARPMACRO,		/*unknown sharp macro*/
  E_ALIST,		/*list expected for an element of an alist*/
  E_NOMACRO,		/*macro expected*/
  E_NOPACKAGE,		/*no such package */
  E_PKGNAME,		/*the package already exists*/
  E_NOOBJ,		/*invalid form*/
  E_NOOBJVAR,		/*48: not an object variable*/
  E_NOSEQ,		/*sequence(list,string,vector) expected*/
  E_STARTEND,		/*illegal subsequence index*/
  E_NOSUPER,		/*no superclass*/
  E_FORMATSTRING,	/*invalid format string character*/
  E_FLOATVECTOR,	/*float vector expected*/
  E_CHARRANGE,		/*0..255*/
  E_VECINDEX,		/*vector index mismatch*/
  E_NOOBJECT,		/*other than numbers expected*/
  E_TYPEMISMATCH,	/*the: type mismatch*/
  E_DECLARE,		/*illegal declaration*/
  E_DECLFORM,		/*invalid declaration form*/
  E_NOVARIABLE,		/*constant is used in let or lambda*/
  E_ROTAXIS,		/*illegal rotation axis spec*/
  E_MULTIDECL,
  E_READLABEL,		/*illegal #n= or #n# label*/
  E_READFVECTOR,	/*error of #f( expression*/
  E_READOBJECT,		/*error in #V or #J format*/
  E_SOCKET,		/*error of socket address*/
  E_NOARRAY,		/*array expected*/
  E_ARRAYDIMENSION,	/*array dimension mismatch*/
  E_KEYPARAM,		/*keyword parameter expected*/
  E_NOKEYPARAM,		/*no such keyword*/
  E_NOINTVECTOR,	/*integer vector expected*/
  E_SEQINDEX,		/*sequence index out of range*/
  E_BITVECTOR,		/*not a bit vector*/
  E_EXTSYMBOL,		/*no such external symbol*/
  E_SYMBOLCONFLICT,	/*symbol conflict in a package*/

/* the following error is added by APT */
    E_USER,

/*  E_END must locate at the end of the error list */
    E_END
  };

/* function prototypes */

#ifdef __cplusplus
extern "C" {
#endif
/*eval*/
#if alpha || IRIX6 || Solaris2 || Linux || Cygwin
#include "eus_proto.h"
#else
extern pointer eval(context *, pointer);
extern pointer eval2(context *, pointer, pointer);
extern pointer ufuncall(context *, pointer, pointer, pointer,
			 struct bindframe *, int);
extern pointer funlambda(context *, pointer, pointer, pointer, pointer *,
			 struct bindframe *, int);
extern pointer funcode(context *, pointer, pointer, int);
extern pointer progn(context *, pointer);
extern pointer csend(context *, ...);
extern pointer getval(context *, pointer);
extern pointer setval(context *, pointer, pointer);
extern pointer getfunc(context *, pointer);
extern struct  bindframe *declare(context *, pointer, struct bindframe *);
extern struct  bindframe *vbind(context *, pointer, pointer,
				 struct bindframe *, struct bindframe*);
extern struct  bindframe *fastbind(context *, pointer, pointer,
				struct bindframe *);
extern void bindspecial(context *, pointer, pointer);
extern void unbindspecial(context *, struct specialbindframe *);
extern struct bindframe *bindkeyparams(context *, pointer, pointer *,
			int, struct bindframe *, struct bindframe *);

extern pointer Getstring();
extern pointer findpkg();
extern pointer memq();

/*allocater*/
extern pointer alloc(int, int, int, int);
extern pointer makebuffer(int);
extern pointer makevector(pointer, int);
extern pointer makeclass(context *, pointer, pointer, pointer,pointer, pointer,
			int, pointer);
extern pointer makecode(pointer, pointer(*)(), pointer);
extern pointer makematrix(context *, int, int);
extern pointer makeobject(pointer);
extern pointer rawcons(context *, pointer, pointer);
extern pointer cons(context *, pointer, pointer);
extern pointer makestring(char *, int);
extern pointer findsymbol(unsigned char *, int, pointer, int *);
extern pointer makesymbol(context *, char *, int, pointer);
extern pointer intern(context *, char *, int, pointer);
extern pointer makepkg(context *, pointer, pointer, pointer);
extern pointer mkstream(context *, pointer, pointer);
extern pointer mkfilestream(context *, pointer,pointer,int,pointer);
extern pointer mkiostream(context *, pointer,pointer);
extern pointer makemodule(context *, int);
extern pointer makebig1(long);
extern pointer eusfloat_to_big(float);
extern eusfloat_t big_to_float(pointer);
extern pointer defun(context *, char *, pointer, pointer(*)(), char *);
extern pointer defmacro(context *, char *, pointer, pointer(*)());
extern pointer defspecial(context *, char *, pointer, pointer(*)());
extern pointer defunpkg(context *, char *, pointer, pointer(*)(),pointer);
extern void addcmethod(context *, pointer, pointer (*)(),
				 pointer, pointer, pointer);
extern pointer defkeyword(context *, char *);
extern pointer defvar(context *, char *, pointer, pointer);
extern pointer deflocal(context *, char *, pointer, pointer);
extern pointer defconst(context *, char *, pointer, pointer);
extern pointer stacknlist(context *, int);
#endif

#if THREADED
extern pointer makethreadport(context *);
#endif

/*boxing,unboxing*/
#if vax
extern float fltval(),ckfltval(),bit_to_float();
extern pointer makeflt();
#else
#ifndef makeflt
extern pointer makeflt();
#endif
#endif

#if !alpha && !IRIX6
/*io*/
extern pointer reader(context *, pointer, pointer);
extern pointer prinx(context *, pointer, pointer);

/*for compiled code*/
extern pointer makeclosure(pointer,pointer,pointer(*)(),pointer, pointer*, pointer*);
extern pointer fcall();
extern pointer xcar(pointer), xcdr(pointer), xcadr(pointer);
extern pointer *ovafptr(pointer,pointer);
#endif

/* mutex locks*/
#if Solaris2 || SunOS4_1
extern mutex_t  mark_lock;
extern char     *mark_locking;
extern int      mark_lock_thread;
extern mutex_t  p_mark_lock;
extern rwlock_t gc_lock;

extern mutex_t  alloc_lock;
extern mutex_t  free_thread_lock;
extern mutex_t  qthread_lock;
extern mutex_t  qsort_lock;
extern sema_t   free_thread_sem;
#endif
#ifdef __cplusplus
}
#endif

extern eusinteger_t hide_ptr (pointer p);

