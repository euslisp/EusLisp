/****************************************************************/
/* eus.c:
/*	Toplevel, exception(error, signal) handler and initializers
/*	Copyright(c)1988, Toshihiro MATSUI, Electrotechnical Laboratory
/*	1986 April:	created 
/*	1994 June:	multi thread
/*	1996 January:	handles SIGSEGV, SIGBUS
/****************************************************************/
static char *rcsid="@(#) $Id$";

#include "eus.h"

#include <signal.h>
#include <dlfcn.h>
#include <fcntl.h>

#if Solaris2
#include <synch.h>
#include <thread.h>
#elif SunOS4_1
#include <lwp/stackdep.h>
#endif

#if !THREADED
unsigned int thr_self() { return(1);}
#endif


#if Linux && !OLD_LINUX && !Darwin
#include <malloc.h> // define mallopt, M_MMAP_MAX
#endif
#if Darwin
int _end;
#endif

/*variables*/
/* process id and program name*/
eusinteger_t mypid;
char *progname;
#if (WORD_SIZE == 64)
eusinteger_t setjmp_val;
#endif

/* heap management */
/* every free cell is linked to this structure*/
struct buddyfree  buddy[MAXBUDDY+1];
extern pointer *gcstack, *gcsp, *gcsplimit;
#define DEFAULT_MAX_GCSTACK 16384


/* System internal objects are connected to sysobj list
/* to protect from being garbage-collected */

pointer sysobj;

/* context */
context *mainctx;
pointer mainport;
#if Solaris2
  thread_t maintid;
#endif


/****************************************************************/
/* system defined (built-in) class index
/*	modified to accept  dynamic type extension (1987-Jan)
/****************************************************************/

cixpair objectcp;
cixpair conscp;
cixpair propobjcp;
cixpair symbolcp;
cixpair packagecp;
cixpair streamcp;
cixpair filestreamcp;
cixpair iostreamcp;
cixpair metaclasscp;
cixpair vecclasscp;
cixpair codecp;
cixpair fcodecp;
/*cixpair modulecp; */
cixpair ldmodulecp;
cixpair closurecp;
cixpair labrefcp;
cixpair threadcp;
cixpair arraycp;
cixpair readtablecp;
cixpair vectorcp;
cixpair fltvectorcp;
cixpair intvectorcp;
cixpair stringcp;
cixpair bitvectorcp;
/* extended numbers */
cixpair extnumcp;
cixpair ratiocp;
cixpair complexcp;
cixpair bignumcp;


struct built_in_cid  builtinclass[64];
int nextbclass;

long buddysize[MAXBUDDY+1];
struct buddyfree buddy[MAXBUDDY+1];
context *euscontexts[MAXTHREAD];


/*symbol management*/
pointer pkglist,lisppkg,keywordpkg,userpkg,syspkg,unixpkg,xpkg;
pointer NIL,PACKAGE,T,QUOTE;
pointer FUNCTION;
pointer QDECLARE,QSPECIAL;
#if SunOS4_1 /* SELF is already used on SunOS 4.1.x. */
pointer QSELF;
#else
pointer SELF;
#endif
pointer CLASS;
pointer STDIN,STDOUT,ERROUT,QSTDIN,QSTDOUT,QERROUT;
pointer QINTEGER,QFIXNUM,QFLOAT,QNUMBER;
pointer TOPLEVEL,QEVALHOOK,ERRHANDLER,FATALERROR;
pointer QGCHOOK, QEXITHOOK;
pointer QUNBOUND,QDEBUG;
pointer QTHREADS;	/* system:*threads* */
pointer QPARAGC;
pointer QVERSION;
pointer QEQ,QEQUAL,QNOT, QAND, QOR;

/* keywords */
pointer K_IN,K_OUT,K_IO;	/*direction keyword*/
pointer K_FLUSH,K_FILL,K_FILE,K_STRING;
pointer K_NOMETHOD,K_BIT,K_BYTE,K_CHAR,K_SHORT,K_LONG,K_INTEGER,K_POINTER;
pointer K_FLOAT32,K_FLOAT,K_DOUBLE,K_FOREIGN, K_FOREIGN_STRING;
pointer K_DOWNCASE,K_UPCASE, K_PRESERVE, K_INVERT, K_CAPITALIZE;
pointer K_DISPOSE;

/*class management*/
struct class_desc  classtab[MAXCLASS];
int nextcix;

/*class cells*/
pointer C_CONS, C_OBJECT, C_SYMBOL, C_PACKAGE;
pointer C_STREAM, C_FILESTREAM, C_IOSTREAM, C_CODE, C_FCODE, C_LDMOD;
pointer C_VECTOR, C_METACLASS, C_CLOSURE, C_LABREF;
pointer C_THREAD;
pointer C_VCLASS, C_FLTVECTOR, C_INTVECTOR, C_STRING, C_BITVECTOR;
pointer C_FOREIGNCODE,C_ARRAY,C_READTABLE;
pointer C_EXTNUM, C_RATIO, C_BIGNUM, C_COMPLEX;

/*class names*/
pointer QCONS,STRING,STREAM,FILESTREAM,IOSTREAM,SYMBOL,	
	CODE,FCODE, LDMODULE, PKGCLASS,METACLASS,CLOSURE,LABREF;
pointer THREAD;
pointer VECTOR,VECCLASS,FLTVECTOR,INTVECTOR,OBJECT,READTABLE;
pointer FOREIGNCODE,ARRAY,BITVECTOR;
pointer EXTNUM, RATIO, COMPLEX, BIGNUM;

/*toplevel & evaluation control*/
int intsig,intcode;
int ehbypass;

/*reader variables*/
pointer charmacro[256];
pointer sharpmacro[256];

extern pointer defvector();
static pointer reploop(context *, char *);

pointer ALLOWOTHERKEYS,K_ALLOWOTHERKEYS;
pointer OPTIONAL,REST,KEY,AUX,MACRO,LAMBDA,LAMCLOSURE,COMCLOSURE;
pointer PRCIRCLE,PROBJECT,PRSTRUCTURE,PRCASE,PRLENGTH,PRLEVEL;
pointer RANDSTATE,FEATURES,READBASE,PRINTBASE,QREADTABLE,QTERMIO;
pointer GCMERGE,GCMARGIN, QLDENT;
pointer K_PRIN1;
pointer K_FUNCTION_DOCUMENTATION, K_VARIABLE_DOCUMENTATION,
	K_CLASS_DOCUMENTATION, K_METHOD_DOCUMENTATION, K_CLASS;
pointer QLOADED_MODULES;
pointer MAXCALLSTACKDEPTH;

static pointer PROPOBJ,C_PROPOBJ;

pointer eussigvec[NSIG];

pointer sysmod;
jmp_buf topjbuf;

/****************************************************************/
/* error handler
*/

char *errmsg[100]={
	"",				/*0*/
	"stack overflow",		/*1 errcode=1..10 are fatal errors*/
	"allocation",			/*2*/
	"",				/*3*/
	"",				/*4*/
	"",				/*5*/
	"",				/*6*/
	"",				/*7*/
	"",				/*8*/
	"",				/*9*/
	"",				/*10	end of fatal error*/
	"attempt to set to constant",	/*11 E_SETCONST */
	"unbound variable",		/*12 E_UNBOUND  */
	"undefined function",		/*13 E_UNDEF    */
	"mismatch argument",		/*14 E_MISMATCHARG */
	"illegal function",		/*15 E_ILLFUNC */
	"illegal character",		/*16 E_ILLCH */
	"illegal delimiter",		/*17 E_READ */
	"write?",			/*18 E_WRITE*/
	"too long string",		/*19 E_LONGSTRING */
	"symbol expected",
	"list expected",
	"illegal lambda form",
        "illegal lambda parameter syntax",
	"no catcher found",
	"no such block",
	"stream expected",
	"illegal stream direction keyword",
	"integer expected",
	"string expected",
	"error in open file",
	"EOF hit",
	"number expected",
	"class table overflow",
	"class expected",
	"vector expected",
	"array size must be positive",
	"duplicated object variable name",
	"cannot make instance",
	"array index out of range",		/*  E_ARRAYINDEX */
	"cannot find method",
	"circular list",
	"unknown sharp macro",
	"list expected for an element of an alist",
	"macro expected",
	"no such package",
	"package name",
	"invalid lisp object form",
	"no such object variable",
	"sequence expected",
	"illegal start/end index",
	"no super class",
	"invalid format string",
	"float vector expected",
	"char code out of range",
	"vector dimension mismatch",
	"object expected",
	"type mismatch",
	"declaration is not allowed here",
	"illegal declaration form",
	"cannot be used for a variable",
	"illegal rotation axis",
	"multiple variable declaration",
	"illegal #n= or #n= label",
	"illegal #f( expression",
	"illegal #v or #j expression", 
	"invalid socket address",
	"array expected",
	"array dimension mismatch",
	"keyword expected for arguments",
	"no such keyword",
	"integer vector expected",
	"sequence index out of range",
	"not a bit vector",
	"no such external symbol",
	"symbol conflict",
	"",
	"E_END",
	};

static pointer brkloop();

void unwind(ctx,p)
register context *ctx;
register pointer *p;
{ pointer cleanup;
  while (ctx->protfp>=(struct protectframe *)p) {	/*clean-up unwind-protect form*/
    cleanup=ctx->protfp->cleaner;
    ctx->protfp=ctx->protfp->protlink;
	/*first, update protfp to avoid endless 
	  evaluation of cleanup form because of an error*/
    ufuncall(ctx,cleanup,cleanup,NULL,NULL,0);}
	/*an error may occur if catch, throw or return-from or access to
	  special variables are taken in clean up forms*/
	/*unwind specially bound variables*/
  unbindspecial(ctx,(struct specialbindframe *)p);
  /*unwind block frames*/
  while (ctx->blkfp>(struct blockframe *)p) ctx->blkfp=ctx->blkfp->dynklink;
  /*unwind catch frames*/
  while (ctx->catchfp>(struct catchframe *)p) ctx->catchfp=ctx->catchfp->nextcatch;
  /*unwind flet frames*/
  while (ctx->fletfp>(struct fletframe *)p) ctx->fletfp=ctx->fletfp->dynlink;
  }

#ifdef USE_STDARG
pointer error(enum errorcode ec, ...)
#else
pointer error(va_alist)
va_dcl
#endif
{ 
  va_list args;
  pointer errhandler;
  register char *errstr;
  register int argc;
  register context *ctx;
  register struct callframe *vf;
  pointer msg;
  int i, n;

#ifdef USE_STDARG
  va_start(args,ec);
#else
  enum errorcode ec;

  va_start(args);
  ec = va_arg(args, enum errorcode);
#endif

  ctx=euscontexts[thr_self()];

  /* print call stack */
  n=intval(Spevalof(MAXCALLSTACKDEPTH));
  if (n > 0) {
    fprintf( stderr, "Call Stack (max depth: %d):\n", n );
    vf=(struct callframe *)(ctx->callfp);
    for (i = 0; vf->vlink != NULL && i < n; ++i, vf = vf->vlink) {
      fprintf( stderr, "  %d: at ", i );
      prinx(ctx, vf->form, ERROUT);
      flushstream(ERROUT);
      fprintf( stderr, "\n" ); }
    if (vf->vlink != NULL) {
      fprintf (stderr, "  And more...\n"); }}

  /* error(errstr) must be error(E_USER,errstr) */
  if ((int)ec < E_END) errstr=errmsg[(int)ec];
  else {
      fprintf( stderr, "Internal warning: error: ec will be string.(%lx)\n",
	      (long)ec );
      errstr=(char *)ec;
  }

  /*fatal error?  allocation failed or stack overflow? */
  if ((unsigned int)ec<=E_FATAL) {
    fprintf(stderr,"%s fatal error: th=%d %s\n",progname,thr_self(),errstr);
    if (speval(FATALERROR) != NIL) {
	fprintf(stderr, "exiting\n"); exit(ec);}
    else throw(ctx,makeint(0),NIL);}

  /* get extra message */
    switch((unsigned int)ec) {
      case E_UNBOUND: case E_UNDEF: case E_NOCLASS: case E_PKGNAME:
      case E_NOOBJ: case E_NOOBJVAR: case E_NOPACKAGE: case E_NOMETHOD:
      case E_NOKEYPARAM: case E_READLABEL: case E_ILLCH: case E_NOCATCHER:
      case E_NOVARIABLE: case E_EXTSYMBOL: case E_SYMBOLCONFLICT:
      case E_USER:
	msg = va_arg(args,pointer);	break;
    }

  /* call user's error handler function */
  errhandler=ctx->errhandler;
  if (errhandler==NIL || errhandler==NULL)  errhandler=Spevalof(ERRHANDLER);
  Spevalof(QEVALHOOK)=NIL;	/* reset eval hook */
  if (errhandler!=NIL) {
    vpush(makeint((unsigned int)ec));
    vpush(makestring(errstr,strlen(errstr)));
    if (ctx->callfp) vpush(ctx->callfp->form); else vpush(NIL);
    switch((unsigned int)ec) {
      case E_UNBOUND: case E_UNDEF: case E_NOCLASS: case E_PKGNAME:
      case E_NOOBJ: case E_NOOBJVAR: case E_NOPACKAGE: case E_NOMETHOD:
      case E_NOKEYPARAM: case E_READLABEL: case E_ILLCH: case E_NOCATCHER:
      case E_NOVARIABLE: case E_EXTSYMBOL: case E_SYMBOLCONFLICT:
	vpush(msg); argc=4; break;
      case E_USER:
	vpush(makestring((char*)msg,strlen((char*)msg))); argc=4; break;
    default: argc=3; break;}
    ufuncall(ctx,errhandler,errhandler,(pointer)(ctx->vsp-argc),ctx->bindfp,argc);
    ctx->vsp-=argc;
    }

  /*default error handler*/
  flushstream(ERROUT);
  fprintf(stderr,"%s: ERROR th=%d %s ",progname,thr_self(),errstr);
  switch((int)ec) {
      case E_UNBOUND: case E_UNDEF: case E_NOCLASS: case E_PKGNAME:
      case E_NOOBJ: case E_NOOBJVAR: case E_NOPACKAGE: case E_NOMETHOD:
      case E_NOKEYPARAM: case E_READLABEL: case E_ILLCH: case E_NOCATCHER:
      case E_NOVARIABLE: case E_EXTSYMBOL: case E_SYMBOLCONFLICT:
	prinx(ctx,msg,ERROUT); flushstream(ERROUT); break;
    }
  if( ec == E_USER ) {
      fprintf( stderr,"%p",msg ); flushstream(ERROUT); }
  else if (ispointer(msg)) {prinx(ctx,msg,ERROUT); flushstream(ERROUT); }
  if (ctx->callfp) {
    fprintf(stderr," in ");
    prinx(ctx,ctx->callfp->form,ERROUT);
    flushstream(ERROUT);}
  /*enter break loop*/
  brkloop(ctx,"E: ");
  throw(ctx,makeint(0),T);	/*throw to toplevel*/
  }

#ifdef USE_STDARG
pointer basicclass(char *name, ...)
#else
pointer basicclass(va_alist)
va_dcl
#endif
{
  va_list ap;
  byte *vname;
  pointer super;
  cixpair *cixp;
  pointer classsym,class,varvector,superv,typevector,forwardvector;
  int n,i,svcount;
  context *ctx=mainctx;

#ifdef USE_STDARG
  va_start(ap, name);
#else
  char *name;

  va_start(ap);  
  name=va_arg(ap,byte *);
#endif
  super=va_arg(ap,pointer);
  cixp=va_arg(ap,cixpair *); n=va_arg(ap,int);
  
  /*class name symbols are defined in lisp package*/
  classsym=intern(ctx,(char *)name,strlen(name),lisppkg);
  export(classsym,lisppkg);
  /* printf("name=%s NIL=%x super=%x\n",name,NIL,super); */
  if (super!=NIL) {
    superv= super->c.cls.vars;
    svcount=vecsize(superv);}
  else svcount=0;
  /* printf("name=%s super's_vcount=%d own_vcount=%d\n", name, svcount, n);*/
  varvector=makevector(C_VECTOR,svcount+n);  vpush(varvector);
  typevector=makevector(C_VECTOR,svcount+n);  vpush(typevector);
  forwardvector=makevector(C_VECTOR,svcount+n);  vpush(forwardvector);
  for (i=0; i<svcount; i++) {
    varvector->c.vec.v[i]=superv->c.vec.v[i];
    typevector->c.vec.v[i]=super->c.cls.types->c.vec.v[i];
    forwardvector->c.vec.v[i]=super->c.cls.forwards->c.vec.v[i];}
  for (i=0; i<n; i++) {
    vname=va_arg(ap,byte *);
    varvector->c.vec.v[i+svcount]=intern(ctx,(char *)vname,strlen((char *)vname),lisppkg);
    export(varvector->c.vec.v[i+svcount], lisppkg);  
    typevector->c.vec.v[i+svcount]=T;
    forwardvector->c.vec.v[i+svcount]=NIL;}
  class=makeclass(ctx,classsym,super,varvector,typevector,forwardvector,ELM_FIXED,0);
  builtinclass[nextbclass].cls=class;
  builtinclass[nextbclass].cp=cixp;
  nextbclass++;
  cixp->cix=intval(class->c.cls.cix);
  cixp->sub=classtab[cixp->cix].subcix;
  ctx->vsp-=3;
  va_end(ap);
  return(classsym);}


/****************************************************************/
/* initialization
/****************************************************************/
static void initmemory()
{ register int i;
  buddysize[0]=3; buddy[0].count=0; buddy[0].bp=0;
  buddysize[1]=3; buddy[1].count=0; buddy[1].bp=0;
  for (i=2; i<MAXBUDDY; i++) {
    buddy[i].count=0;
    buddysize[i]=buddysize[i-2]+buddysize[i-1];	/*fibonacci*/
    buddy[i].bp=0;}		/*no cells are connected*/
  buddy[MAXBUDDY].bp=(bpointer)(-1);	/*sentinel for alloc*/
#if (WORD_SIZE == 64)
  buddysize[MAXBUDDY]= 0x7fffffffffffffff;	/*cell size limit*/
#else
  buddysize[MAXBUDDY]= 0x7fffffff;	/*cell size limit*/
#endif

  /*allocate enough memory for initialization*/
  newchunk(20);
  newchunk(18);
  gcstack=(pointer *)malloc(DEFAULT_MAX_GCSTACK * sizeof(pointer));
  gcsp=gcstack;
  gcsplimit= &gcstack[DEFAULT_MAX_GCSTACK -10];
  }

#ifdef RGC
void initmemory_rgc()
{ register int i;
  buddysize[0]=3; buddy[0].count=0; buddy[0].bp=0;
  buddysize[1]=3; buddy[1].count=0; buddy[1].bp=0;
  for (i=2; i<MAXBUDDY; i++) {
    buddy[i].count=0;
    buddysize[i]=buddysize[i-2]+buddysize[i-1];	/*fibonacci*/
    buddy[i].bp=0;}		/*no cells are connected*/
  buddy[MAXBUDDY].bp=(bpointer)(-1);	/*sentinel for alloc*/
#if (WORD_SIZE == 64)
  buddysize[MAXBUDDY]= 0x7fffffffffffffff;	/*cell size limit*/
#else
  buddysize[MAXBUDDY]= 0x7fffffff;	/*cell size limit*/
#endif

  {
    unsigned int tmp;
    tmp = allocate_heap();
    fprintf(stderr, "allocate_heap: %d bytes\n", tmp*4);
  }

  gcstack=(pointer *)malloc(DEFAULT_MAX_GCSTACK * sizeof(pointer));
  gcsp=gcstack;
  gcsplimit= &gcstack[DEFAULT_MAX_GCSTACK -10];

}
#endif

static void initclassid()
{ 
  /* built-in class id's*/
  nextcix=0;
  objectcp.cix=0; objectcp.sub=0;
  conscp.cix=1; conscp.sub=1;
  propobjcp.cix=2; propobjcp.sub=12;
    symbolcp.cix=3; symbolcp.sub=3;
    packagecp.cix=4; packagecp.sub=4;
    streamcp.cix=5; streamcp.sub=6;
      filestreamcp.cix=6; filestreamcp.sub=6;
    iostreamcp.cix=7; iostreamcp.sub=7;
    metaclasscp.cix=8; metaclasscp.sub=9;
      vecclasscp.cix=9; vecclasscp.sub=9;
    readtablecp.cix=10; readtablecp.sub=10;
    arraycp.cix=11; arraycp.sub=11;
    threadcp.cix=12; threadcp.sub=12;

  codecp.cix=13; codecp.sub=16;
    fcodecp.cix=14; fcodecp.sub=14;
    closurecp.cix=15; closurecp.sub=15;
    ldmodulecp.cix=16; ldmodulecp.sub=16;

  labrefcp.cix=17; labrefcp.sub=17;

  vectorcp.cix=18; vectorcp.sub=21;
  fltvectorcp.cix=19; fltvectorcp.sub=19;
  intvectorcp.cix=20; intvectorcp.sub=20;
  stringcp.cix=21; stringcp.sub=21;
}

static void initpackage()
{ register int i;
  register context *ctx=mainctx;

  /* GENESIS: First, VECTOR must exist!*/
  C_VECTOR=alloc(wordsizeof(struct vecclass),ELM_FIXED,vecclasscp.cix,
		 wordsizeof(struct vecclass));
  for (i=0; i<(wordsizeof(struct vecclass)); i++) C_VECTOR->c.obj.iv[i]=NULL;
  C_VECTOR->c.vcls.cix=makeint(vectorcp.cix);
  C_VECTOR->c.vcls.elmtype=makeint(ELM_POINTER);

  /*Then, NIL can be created*/
  lisppkg=makepkg(ctx,makestring("LISP",4),makeint(0),makeint(0));
  lisppkg->c.pkg.use=makeint(0);	/*prevent islist checking*/
  NIL=defconst(ctx,"NIL",NIL,lisppkg);
  NIL->c.sym.speval=NIL;
  NIL->c.sym.plist=NIL;
  sysobj=NIL;
  pkglist->c.cons.cdr=NIL;
  lisppkg->c.pkg.use=NIL;
  lisppkg->c.pkg.names->c.cons.cdr=NIL;
  lisppkg->c.pkg.plist=NIL;
  lisppkg->c.pkg.shadows=NIL;
  lisppkg->c.pkg.used_by=NIL;
  NIL->c.sym.homepkg=lisppkg;

  /*default packages*/
  keywordpkg=makepkg(ctx,makestring("KEYWORD",7),NIL,NIL);
  userpkg=   makepkg(ctx,makestring("USER",4),NIL,rawcons(ctx,lisppkg,NIL));
  syspkg=    makepkg(ctx,makestring("SYSTEM",6),NIL,rawcons(ctx,lisppkg,NIL));
  unixpkg=   makepkg(ctx,makestring("UNIX",4),NIL,rawcons(ctx,lisppkg,NIL));
  xpkg=      makepkg(ctx,makestring("X",1),NIL,rawcons(ctx,lisppkg,NIL));
  }

static void initsymbols()
{ register int i;
  numunion nu;
  register context *ctx=mainctx;

  export_all=0;

  /* symbols */
  /* Be careful to define symbol pnames in upcase */
  T=defconst(ctx,"T",T,lisppkg);
  T->c.sym.speval=T;
  PACKAGE=deflocal(ctx,"*PACKAGE*",lisppkg,lisppkg);
  OPTIONAL=intern(ctx,"&OPTIONAL",9,lisppkg);
  REST=intern(ctx,"&REST",5,lisppkg);
  KEY=intern(ctx,"&KEY",4,lisppkg);
  AUX=intern(ctx,"&AUX",4,lisppkg);
  ALLOWOTHERKEYS=intern(ctx,"&ALLOW-OTHER-KEYS",17,lisppkg);
  LAMBDA=intern(ctx,"LAMBDA",6,lisppkg);
  MACRO=intern(ctx,"MACRO",5,lisppkg);
  FUNCTION=intern(ctx,"FUNCTION",8,lisppkg);
  LAMCLOSURE=intern(ctx,"LAMBDA-CLOSURE",14,lisppkg);
  COMCLOSURE=intern(ctx,"COMPILED-CLOSURE",16,lisppkg);
  QDECLARE=intern(ctx,"DECLARE",7,lisppkg);
  QSPECIAL=intern(ctx,"SPECIAL",7,lisppkg);
#if SunOS4_1 /* SELF is already used on SunOS 4.1.x. */
  QSELF=intern(ctx,"SELF",4,lisppkg);
#else
  SELF=intern(ctx,"SELF",4,lisppkg);
#endif
  CLASS=intern(ctx,"CLASS",5,lisppkg);
  K_NOMETHOD=defkeyword(ctx,"NOMETHOD");
  K_IN=defkeyword(ctx,"INPUT");
  K_OUT=defkeyword(ctx,"OUTPUT");
  K_IO=defkeyword(ctx,"IO");
  K_FLUSH=defkeyword(ctx,"FLUSH");
  K_FILL=defkeyword(ctx,"FILL");
  K_FILE=defkeyword(ctx,"FILE"); 
  K_STRING=defkeyword(ctx,"STRING"); 
/*  K_MSGQ=defkeyword(ctx,"MSGQ"); */
  K_DOWNCASE=defkeyword(ctx,"DOWNCASE");
  K_UPCASE=defkeyword(ctx,"UPCASE");
  K_PRESERVE=defkeyword(ctx,"PRESERVE");
  K_INVERT=defkeyword(ctx,"INVERT");
  K_CAPITALIZE=defkeyword(ctx,"CAPITALIZE");
  K_BIT=defkeyword(ctx,"BIT");
  K_CHAR=defkeyword(ctx,"CHAR");
  K_BYTE=defkeyword(ctx,"BYTE");
  K_SHORT=defkeyword(ctx,"SHORT");
  K_LONG=defkeyword(ctx,"LONG");
  K_INTEGER=defkeyword(ctx,"INTEGER");
  K_POINTER=defkeyword(ctx,"POINTER");
  K_FLOAT32=defkeyword(ctx,"FLOAT32");  
  K_FLOAT=defkeyword(ctx,"FLOAT");
  K_DOUBLE=defkeyword(ctx,"DOUBLE");
  K_FOREIGN=defkeyword(ctx,"FOREIGN");
  K_FOREIGN_STRING=defkeyword(ctx,"FOREIGN-STRING");
  K_ALLOWOTHERKEYS=defkeyword(ctx,"ALLOW-OTHER-KEYS");
  K_PRIN1=defkeyword(ctx,"PRIN1");
  K_CLASS=defkeyword(ctx,"CLASS");
  K_FUNCTION_DOCUMENTATION=defkeyword(ctx,"FUNCTION-DOCUMENTATION");
  K_CLASS_DOCUMENTATION=defkeyword(ctx,"CLASS-DOCUMENTATION");
  K_VARIABLE_DOCUMENTATION=defkeyword(ctx,"VARIABLE-DOCUMENTATION");
  K_METHOD_DOCUMENTATION=defkeyword(ctx,"METHOD-DOCUMENTATION");
  K_DISPOSE=defkeyword(ctx,"DISPOSE");
  QINTEGER=intern(ctx,"INTEGER",7,lisppkg);
  QFLOAT=intern(ctx,"FLOAT",5,lisppkg);
  QFIXNUM=intern(ctx,"FIXNUM",6,lisppkg);
  QNUMBER=intern(ctx,"NUMBER",6,lisppkg);
  QDEBUG=defvar(ctx,"*DEBUG*",NIL,lisppkg);
/*  speval(QDEBUG)=NIL; */
  PRCASE=deflocal(ctx,"*PRINT-CASE*",K_DOWNCASE,lisppkg);
  PRCIRCLE=deflocal(ctx,"*PRINT-CIRCLE*",NIL,lisppkg);
  PROBJECT=deflocal(ctx,"*PRINT-OBJECT*",NIL,lisppkg);
  PRSTRUCTURE=deflocal(ctx,"*PRINT-STRUCTURE*",NIL,lisppkg);
  PRLENGTH=deflocal(ctx,"*PRINT-LENGTH*",NIL,lisppkg);
  PRLEVEL=deflocal(ctx,"*PRINT-LEVEL*",NIL,lisppkg);
  QREADTABLE=deflocal(ctx,"*READTABLE*",NIL,lisppkg);
  TOPLEVEL=defvar(ctx,"*TOPLEVEL*",NIL,lisppkg);
  ERRHANDLER=deflocal(ctx,"*ERROR-HANDLER*",NIL,lisppkg);
  QEVALHOOK=deflocal(ctx,"*EVALHOOK*",NIL,lisppkg);
  QUNBOUND=intern(ctx,"*UNBOUND*",9,lisppkg);
  RANDSTATE=deflocal(ctx,"*RANDOM-STATE*",UNBOUND,lisppkg);
  FEATURES=defvar(ctx,"*FEATURES*",NIL,lisppkg);
  READBASE=deflocal(ctx,"*READ-BASE*",makeint(10),lisppkg);
  PRINTBASE=deflocal(ctx,"*PRINT-BASE*",makeint(10),lisppkg);
  MAXCALLSTACKDEPTH=deflocal(ctx, "*MAX-CALLSTACK-DEPTH*",makeint(20),lisppkg);
  /*initialize i/o stream*/
  STDIN=mkfilestream(ctx,K_IN,makebuffer(128),0,NIL);
  QSTDIN=deflocal(ctx,"*STANDARD-INPUT*",STDIN,lisppkg);
  STDOUT=mkfilestream(ctx,K_OUT,makebuffer(256),1,NIL);
  QSTDOUT=deflocal(ctx,"*STANDARD-OUTPUT*",STDOUT,lisppkg);
  ERROUT=mkfilestream(ctx,K_OUT,makebuffer(128),2,NIL);
  QERROUT=deflocal(ctx,"*ERROR-OUTPUT*",ERROUT,lisppkg);
  QTERMIO=deflocal(ctx,"*TERMINAL-IO*",NIL,lisppkg);
  GCMERGE=defvar(ctx,"*GC-MERGE*",makeflt(0.2),syspkg);
  GCMARGIN=defvar(ctx,"*GC-MARGIN*",makeflt(0.4),syspkg);
  QLDENT=defvar(ctx,"*LOAD-ENTRIES*", NIL, syspkg);
  QTHREADS=defvar(ctx, "*THREADS*", NIL, syspkg);
  QPARAGC=defvar(ctx, "*PARALLEL-GC*", NIL, syspkg);
  QGCHOOK=defvar(ctx,"*GC-HOOK*",NIL,syspkg);
  QEXITHOOK=defvar(ctx,"*EXIT-HOOK*",NIL,syspkg);
  FATALERROR=defvar(ctx,"*EXIT-ON-FATAL-ERROR*",NIL,lisppkg);

  /*init character macro table*/
  for (i=0; i<256; i++) charmacro[i]=sharpmacro[i]=NIL;

  /*init signal vector*/
  for (i=0; i<NSIG; i++) eussigvec[i]=NIL;
}

static void initclasses()
{ extern pointer oblabels[MAXTHREAD];	/*eusio.c*/
  register context *ctx=mainctx;
  int i;

  /* basic classes */
/*0*/
  OBJECT=basicclass("OBJECT",NIL,&objectcp,0);
  C_OBJECT=speval(OBJECT);
/*1*/
  QCONS=basicclass("CONS",C_OBJECT,&conscp,2,"CAR","CDR");
  C_CONS=speval(QCONS);
/*2*/
  PROPOBJ=basicclass("PROPERTIED-OBJECT",C_OBJECT, &propobjcp,1,"PLIST");
  C_PROPOBJ=speval(PROPOBJ);
/*3*/
  SYMBOL=basicclass("SYMBOL",C_PROPOBJ,&symbolcp,5,
		    "VALUE","VTYPE","FUNCTION","PNAME","HOMEPKG");
  C_SYMBOL=speval(SYMBOL);
/*4*/
  PKGCLASS=basicclass("PACKAGE",C_PROPOBJ,&packagecp,
		      8,"NAMES","USE","SYMVECTOR","SYMCOUNT",
			"INTSYMVECTOR", "INTSYMCOUNT", "SHADOWS", "USED-BY");
  C_PACKAGE=speval(PKGCLASS);
/*5*/
  STREAM=basicclass("STREAM",C_PROPOBJ,&streamcp,
		    4,"DIRECTION","BUFFER","COUNT","TAIL");
  C_STREAM=speval(STREAM);
/*6*/
  FILESTREAM=basicclass("FILE-STREAM",C_STREAM,&filestreamcp,2,"FD","FNAME");
  C_FILESTREAM=speval(FILESTREAM);
/*7*/
  IOSTREAM=basicclass("IO-STREAM",C_PROPOBJ,&iostreamcp,2,"INSTREAM","OUTSTREAM");
  C_IOSTREAM=speval(IOSTREAM);
/*8*/
  METACLASS=basicclass("METACLASS",C_PROPOBJ,&metaclasscp,
			7,"NAME","SUPER","CIX","VARS","TYPES","FORWARDS","METHODS");
  C_METACLASS=speval(METACLASS);
/*9*/
  VECCLASS=basicclass("VECTORCLASS",C_METACLASS,&vecclasscp,
		      2,"ELEMENT-TYPE","SIZE");
  C_VCLASS=speval(VECCLASS);
/*10*/
  READTABLE=basicclass("READTABLE",C_PROPOBJ,&readtablecp,
		       4,"SYNTAX","MACRO","DISPATCH-MACRO","CASE");
  C_READTABLE=speval(READTABLE);
/*11*/
  ARRAY=basicclass("ARRAY",C_PROPOBJ,&arraycp,
	  	     11,"ENTITY","RANK","FILL-POINTER","DISPLACED-INDEX-OFFSET",
		        "DIM0","DIM1","DIM2","DIM3","DIM4","DIM5","DIM6");
  C_ARRAY=speval(ARRAY);
/*12 */
  THREAD=basicclass("THREAD", C_PROPOBJ, &threadcp,
			10, "ID", "REQUESTER", "REQUEST-SEM", "DONE-SEM",
			   "FUNC", "ARGS", "RESULT", "CONTEXT",
			   "IDLE", "WAIT");
  C_THREAD=speval(THREAD);
/*13*/
  CODE=basicclass("COMPILED-CODE",C_OBJECT,&codecp,4,"CODEVECTOR","QUOTEVECTOR",
		  "TYPE","ENTRY");
  C_CODE=speval(CODE);
/*14*/
  FCODE=basicclass("FOREIGN-CODE",C_CODE,&fcodecp,3,"ENTRY2","PARAMTYPES","RESULTTYPE"); /* kanehiro's patch 2000.12.13 */
  C_FCODE=speval(FCODE);
/*15*/
#if (WORD_SIZE == 64)
  CLOSURE=basicclass("CLOSURE",C_CODE,&closurecp,3,"ENV0","ENV1","ENV2");
#else
  CLOSURE=basicclass("CLOSURE",C_CODE,&closurecp,2,"ENV1","ENV2");
#endif
  C_CLOSURE=speval(CLOSURE);
/* 16    ---new for Solaris */
  LDMODULE=basicclass("LOAD-MODULE",C_CODE, &ldmodulecp, 3,
			"SYMBOL-TABLE","OBJECT-FILE", "HANDLE");
  C_LDMOD=speval(LDMODULE);
/*17*/
  LABREF=basicclass("LABEL-REFERENCE",C_OBJECT,&labrefcp,4,
		    "LABEL","VALUE","UNSOLVED","NEXT");
  C_LABREF=speval(LABREF);
/*18*/
  VECTOR=defvector(ctx,"VECTOR",C_OBJECT,ELM_POINTER, 0);   /* alpha */
  C_VECTOR=speval(VECTOR);
  builtinclass[nextbclass].cls=C_VECTOR;
  builtinclass[nextbclass++].cp= &vectorcp;

  FLTVECTOR=defvector(ctx,"FLOAT-VECTOR",C_VECTOR,ELM_FLOAT, 0); /* alpha */
  C_FLTVECTOR=speval(FLTVECTOR);
  builtinclass[nextbclass].cls=C_FLTVECTOR;
  builtinclass[nextbclass++].cp= &fltvectorcp;

  INTVECTOR=defvector(ctx,"INTEGER-VECTOR",C_VECTOR,ELM_INT, 0); /* alpha */
  C_INTVECTOR=speval(INTVECTOR);
  builtinclass[nextbclass].cls=C_INTVECTOR;
  builtinclass[nextbclass++].cp= &intvectorcp;

  STRING=defvector(ctx,"STRING",C_VECTOR,ELM_CHAR, 0); /* alpha */
  C_STRING=speval(STRING);
  builtinclass[nextbclass].cls=C_STRING;
  builtinclass[nextbclass++].cp= &stringcp;

  BITVECTOR=defvector(ctx,"BIT-VECTOR",C_VECTOR,ELM_BIT, 0); /* alpha */
  C_BITVECTOR=speval(BITVECTOR);
  builtinclass[nextbclass].cls=C_BITVECTOR;
  builtinclass[nextbclass++].cp= &bitvectorcp;

/* extended numbers */
  EXTNUM=basicclass("EXTENDED-NUMBER",C_OBJECT,&extnumcp,0);
  C_EXTNUM=speval(EXTNUM);
  RATIO=basicclass("RATIO",C_EXTNUM, &ratiocp,2,"NUMERATOR","DENOMINATOR");
  C_RATIO=speval(RATIO);
  COMPLEX=basicclass("COMPLEX", C_EXTNUM, &complexcp, 2, "REAL", "IMAGINARY");
  C_COMPLEX=speval(COMPLEX);
  BIGNUM=basicclass("BIGNUM", C_EXTNUM, &bignumcp, 2, "SIZE", "BV");
  C_BIGNUM=speval(BIGNUM);

  for (i=0;i<MAXTHREAD;i++) {
    oblabels[i]=(pointer)makelabref(makeint(-1),UNBOUND,NIL);
    sysobj=cons(ctx,oblabels[i],sysobj);
  }
}

static void initfeatures()
{ register pointer p;
  register context *ctx=mainctx;
  extern char *makedate;
  extern char *gitrevision;
  extern char *compilehost;

  p=makestring(VERSION,strlen(VERSION));
  vpush(p);
  p=makestring(compilehost,strlen(compilehost));
  vpush(p);
  p=makestring(makedate,strlen(makedate));
  vpush(p);
  p=makestring(gitrevision,strlen(gitrevision));
  vpush(p);
  p=stacknlist(ctx,4);
  QVERSION=defvar(ctx, "LISP-IMPLEMENTATION-VERSION", p,lisppkg);

  /*make features*/

  p=NIL;
#if vax
  p=cons(ctx,intern(ctx,"VAX",3,keywordpkg),p);
#endif
#if sun
  p=cons(ctx,intern(ctx,"SUN",3,keywordpkg),p);
#endif
#if apollo
  p=cons(ctx,intern(ctx,"APOLLO",6,keywordpkg),p);
#endif
#if mips
  p=cons(ctx,intern(ctx,"MIPS",4,keywordpkg),p);
#endif
#if sun3
  p=cons(ctx,intern(ctx,"SUN3",4,keywordpkg),p);
#endif
#if sun4
  p=cons(ctx,intern(ctx,"SUN4",4,keywordpkg),p);
#endif
#if news
  p=cons(ctx,intern(ctx,"NEWS",4,keywordpkg),p);
#endif
#if sanyo
  p=cons(ctx,intern(ctx,"SANYO",5,keywordpkg),p);
#endif
#if bsd4_2
  p=cons(ctx,intern(ctx,"BSD4_2",6,keywordpkg),p);
#endif
#if SunOS4
  p=cons(ctx,intern(ctx,"SUNOS4",6,keywordpkg),p);
#endif
#if SunOS4_1
  p=cons(ctx,intern(ctx,"SUNOS4.1",8,keywordpkg),p);
#endif
#if system5
  p=cons(ctx,intern(ctx,"SYSTEM5",7,keywordpkg),p);
#endif
#if coff
  p=cons(ctx,intern(ctx,"COFF",4,keywordpkg),p);
#endif
#if Solaris2
  p=cons(ctx,intern(ctx,"SOLARIS2",8,keywordpkg),p);
#endif
#if GCC
  p=cons(ctx,intern(ctx,"GCC",3,keywordpkg),p);
#endif
#if GCC3
  p=cons(ctx,intern(ctx,"GCC3",4,keywordpkg),p);
#endif
#if i386
  p=cons(ctx,intern(ctx,"I386",4,keywordpkg),p);
#endif
#if Linux
  p=cons(ctx,intern(ctx,"LINUX",5,keywordpkg),p);
#endif
#if Linux_ppc
  p=cons(ctx,intern(ctx,"PPC",3,keywordpkg),p);
#endif
#if USE_MULTI_LIB
  p=cons(ctx,intern(ctx,"IA32",4,keywordpkg),p);
#endif
#if ELF
  p=cons(ctx,intern(ctx,"ELF",3,keywordpkg),p);
#endif
#if IRIX
  p=cons(ctx,intern(ctx,"IRIX",4,keywordpkg),p);
#endif
#if IRIX6
  p=cons(ctx,intern(ctx,"IRIX6",5,keywordpkg),p);
#endif
#if alpha
  p=cons(ctx,intern(ctx,"ALPHA",5,keywordpkg),p);
#endif
#if Cygwin
  p=cons(ctx,intern(ctx,"CYGWIN",6,keywordpkg),p);
#endif
#if Darwin
  p=cons(ctx,intern(ctx,"DARWIN",6,keywordpkg),p);
#endif
#if THREADED
  p=cons(ctx,intern(ctx,"THREAD",6,keywordpkg),p);
#endif
#if PTHREAD
  p=cons(ctx,intern(ctx,"PTHREAD",7,keywordpkg),p);
#endif
#if X_V11R6_1
  p=cons(ctx,intern(ctx,"X11R6.1",7,keywordpkg),p);
#endif
#if RGC
  p=cons(ctx,intern(ctx,"RGC",3,keywordpkg),p);
#endif
#if SH4
  p=cons(ctx,intern(ctx,"SH4",3,keywordpkg),p);
#endif
#if x86_64
  p=cons(ctx,intern(ctx,"X86_64",6,keywordpkg),p);
#endif
#if ARM
  p=cons(ctx,intern(ctx,"ARM",3,keywordpkg),p);
#endif
#if aarch64
  p=cons(ctx,intern(ctx,"AARCH64",7,keywordpkg),p);
#endif

  defvar(ctx,"*FEATURES*",p,lisppkg);

  /*system function module*/
  sysmod=makemodule(ctx,0);
  sysmod->c.ldmod.codevec=makeint(0);
  sysmod->c.ldmod.handle=makeint((eusinteger_t)dlopen(0, RTLD_LAZY)>>2);
  sysobj=cons(ctx,sysmod, sysobj);
  }

/****************************************************************/
/* signal handlers
/****************************************************************/

extern long gcing;
#include <sys/wait.h>

void eusint(s,code,x,addr)
register int s;
int code,x;
eusinteger_t addr;
{ int stat;
  context *ctx;

  ctx = euscontexts[thr_self()];
  if (debug) {
    fprintf(stderr, ";; eusint: sig=%d, %d; thr=%d ctx=%p\n",
		s,code,thr_self(), ctx);}
  if (ctx==NULL) ctx=mainctx;
  ctx->intsig=s;
  intcode=code;
  switch(s) {
  case SIGCHLD:
    wait(&stat);
    if (debug)
      fprintf(stderr,";; child proc terminated; wait=0x%x\n",stat);
    ctx->intsig=0;
    break;
  case SIGFPE:
    fprintf(stderr,";; floating exception\n");
    goto sigfatal;
    break;
  case SIGPIPE:
    fprintf(stderr,";; pipe broken %d %x %lx\n",code,x,(unsigned long)addr);
    throw(mainctx,makeint(0),NIL);	/*nonsense*/
    break;
  case SIGSEGV:
    fprintf(stderr,";; Segmentation Fault.\n");
    goto sigfatal;
  case SIGBUS:
    fprintf(stderr,";; Bus Error.\n");

    sigfatal:

    if (speval(FATALERROR) != NIL) exit(s);
    if (ctx->callfp) {
      fprintf(stderr,";; in ");
      prinx(ctx,ctx->callfp->form,ERROUT);
      flushstream(ERROUT);
      fprintf(stderr,"\n");}
    fprintf(stderr,";; You are still in a signal handler.\n;;Try reset or throw to upper level as soon as possible.\n");
    fprintf(stderr,";; code=%d x=%x addr=%lx\n",code,x,(unsigned long)addr);
    reploop(mainctx, "Fatal: ");
    fprintf(stderr,";; No, you cannot continue the previous evaluation.\n");
    /* goto sigfatal; */
    exit(s);
    break;
  }

#if Solaris2 || system5
  signal(s,(void (*)())eusint);	/*reinstall signal*/
#endif

#if THREADED
    if (isintvector(eussigvec[s])) {
/*      if (s==SIGALRM && gcing) {intsig=0; return;} */
	/*ignore Alarm clock during gc*/
      sema_post((sema_t *)eussigvec[s]->c.ivec.iv);
      ctx->intsig=0;}
#endif
  if (debug) { fprintf(stderr, ";; eusint exit: intsig=%d\n",ctx->intsig);}
}

static pointer brkloop(ctx, prompt)
context *ctx;
char *prompt;
{ jmp_buf brkjmp;
  pointer val;
  int i;
  mkcatchframe(ctx,T,&brkjmp);
  Spevalof(QSTDOUT)=STDOUT;
  Spevalof(QSTDIN)=STDIN;
  Spevalof(QERROUT)=ERROUT;
  if ((val=(pointer)eussetjmp(brkjmp))==0) val=reploop(ctx,prompt);
  else if ((eusinteger_t)val==1) val=makeint(0);	/*longjmp cannot return 0*/
  ctx->callfp=ctx->catchfp->cf;
  ctx->bindfp=ctx->catchfp->bf;
  ctx->vsp=(pointer *)ctx->catchfp;
  ctx->catchfp=(struct catchframe *)*(ctx->vsp);
  return(val);}

void sigbreak()
{ pointer sighandler,*vspsave;
  context *ctx=euscontexts[thr_self()];
  int is;

  is=ctx->intsig;
  if (debug) printf("sigbreak: intsig=%d thr_self=%d\n", is, thr_self());
  sighandler=eussigvec[is];
  if (isintvector(sighandler)) return;
  vspsave=ctx->vsp;
  ctx->intsig=0;
  QEVALHOOK->c.sym.speval=NIL;
  if (sighandler!=NIL) {
    vpush(makeint(is)); vpush(makeint(intcode));
    ufuncall(ctx,sighandler,sighandler,(pointer)(ctx->vsp-2),ctx->bindfp,2);
    ctx->vsp=vspsave;  }
  else {
    fprintf(stderr,"signal=%d to thread %d, \n",is, thr_self());
    /*    brkloop(ctx,"B: "); */
    return; }}
  

/****************************************************************/
/* main and toplevel
/****************************************************************/
static pointer reploop(ctx,prompt)
register context *ctx;
char *prompt;
{ pointer p,q;
  int ttyp;
  ehbypass=0;
  ttyp=isatty(intval(STDIN->c.fstream.fd));
  do {
    if (ttyp) {
      p=Spevalof(PACKAGE);
      if (p!=userpkg) {	/*print pkg name*/
	printf("%s:",ccar(p->c.pkg.names)->c.str.chars);}
      printf("%s",prompt);
      fflush(stdout);}
    p=reader(ctx,STDIN,NIL);
    if (p==(pointer)EOF) return(NIL);
    breakck;
    q=eval(ctx,p);
    if (q!=UNBOUND) { prinx(ctx,q,STDOUT); terpri(STDOUT);}}
  while (1);}

static void toplevel(ctx,argc,argv)
register context *ctx;
int argc;
char *argv[];
{ pointer argvp,topform;
  int i,j;

  /* reset stack pointer and frame pointers*/
  j=(int)eussetjmp(topjbuf);  
  ctx->vsp=ctx->stack;
  ctx->bindfp=NULL;
  ctx->sbindfp=NULL;
  ctx->callfp=NULL;
  ctx->blkfp=NULL;
  ctx->protfp=NULL;
  ctx->catchfp=NULL;
  ctx->fletfp=NULL;
  topform=speval(TOPLEVEL);
  if (topform!=NIL) {
    if (j==0) {
      for (i=0; i<argc; i++) vpush(makestring(argv[i],strlen(argv[i])));
      ufuncall(ctx,topform,topform,(pointer)(ctx->vsp-argc),0,argc);}
    else ufuncall(ctx,topform,topform,(pointer)(ctx->vsp),0,0);}
  else { /*TOPLEVEL not yet defined-- try built-in toplevel*/
    mkcatchframe(ctx,makeint(0),&topjbuf);
    fprintf(stderr, "entering reploop\n");
    reploop(ctx,": ");}
  }

/* load initial configuration file from EUSDIR/eusrt0.l */
static void configure_eus(ctx)
register context *ctx;
{ pointer argv, p, in;
  int i,j;
  char *eusdir, *eusrt;
  char fname[1024];
  extern pointer SRCLOAD();

  /* reset stack pointer and frame pointers*/
  j=(int)eussetjmp(topjbuf);  
  eusdir=(char *)getenv("EUSDIR");
  if (eusdir==NULL) { 
    fprintf(stderr, "EUSDIR is not setenved, assuming /usr/local/eus\n");
    eusdir= "/usr/local/eus/"; }
  sprintf(fname,"%s/lib/eus.init.l", eusdir);

#if !Solaris2 || GCC
  /* read the init-module list from "EUSDIR/lib/eus.init.l" */
  in=(pointer)openfile(ctx,fname,O_RDONLY,0,256);
  if (in==NULL) {
    fprintf(stderr,
	 "$EUSDIR/lib/eus.init.l was not found\nfailed to initialize.\n"
	 "Entering raweus.\n"
	 "To exit, type (unix::exit)\n");
    return;}
  vpush(in);
  p=reader(ctx,in,NIL);
  vpop();
  closestream(in);
  /* prinx(ctx,p,STDOUT);  */
#endif

  vpush(p);
  /*  prinx(ctx,p,STDOUT); terpri(STDOUT); */
  p=(pointer)list_module_initializers(ctx,p);
  vpop();
  speval(QLDENT)=p;

  eusrt=(char *)getenv("EUSRT");
  if (eusrt==NULL)  sprintf(fname,"%s/lib/eusrt.l", eusdir);
  else strcpy(fname, eusrt);
  if (isatty(0)!=0) {
    fprintf(stderr, "configuring by \"%s\"\n", fname); }
  mkcatchframe(ctx,makeint(0),&topjbuf);
  argv=makestring(fname, strlen(fname));
  vpush(argv);
  eusstart(ctx);
  SRCLOAD(ctx, 1, ctx->vsp-1);
  }


int mainargc;
char *mainargv[32];


void mainthread(ctx)
register context *ctx;
{ 
  euscontexts[thr_self()]=ctx;

  /*initialize system*/
#ifndef RGC
  initmemory();
#endif
  initclassid();

  {
    int i;
    pointer specialtab;
    specialtab=alloc(MAX_SPECIALS+1,ELM_POINTER,vectorcp.cix,MAX_SPECIALS+1);
    specialtab->c.vec.size=makeint(MAX_SPECIALS);
    for (i=0; i<MAX_SPECIALS; i++)     specialtab->c.vec.v[i]=NIL;
    ctx->specials=specialtab;    }

  initpackage();
  initsymbols();
  initclasses();
  initfeatures();

  ctx->threadobj=NIL;


  /* define built-in functions */
  lists(ctx,sysmod);	/*list functions and predicates*/
  predicates(ctx,sysmod); /*predicates*/
  sequence(ctx,sysmod);	/*sequence functions*/
  specials(ctx,sysmod);	/*control forms, special forms*/
  lispio(ctx,sysmod);	/*lisp i/o*/
  loadsave(ctx,sysmod);	/*loader and saver*/
  leo(ctx,sysmod);	/*object oriented programming*/
  arith(ctx,sysmod);	/*arithmetic functions*/
  matrix(ctx,sysmod);	/*floatvector, matrix operation*/
  unixcall(ctx,sysmod);	/*unix system binding*/
  foreign(ctx,sysmod);	/*foreign function interface*/
  vectorarray(ctx,sysmod);	/*vector and array functions*/
  charstring(ctx,sysmod);
#if THREADED
  mthread(ctx,sysmod);
#if Solaris2
  mainport=makethreadport(mainctx);
  speval(QTHREADS)=cons(ctx, mainport, speval(QTHREADS));
  mainport->c.thrp.id=makeint((int)maintid);
#endif
#endif

  initreader(ctx);
  sysfunc(ctx,sysmod);
#ifdef RGC
  rgcfunc(ctx,sysmod);
#endif
  eusioctl(ctx,sysmod);
  Spevalof(PACKAGE)=userpkg; 

  defvar(ctx,"*PROGRAM-NAME*",makestring(progname,strlen(progname)),lisppkg);

  /* exec_module_initializers(); */
  ctx->vsp=ctx->stack;
  configure_eus(ctx); 

  signal(SIGCHLD, (void (*)())eusint);
  signal(SIGFPE,  (void (*)())eusint);
  signal(SIGPIPE, (void (*)())eusint);
#ifdef RGC
//  signal(SIGSEGV, (void (*)())eusint); /* for debugging. R.Hanai */
#else
  signal(SIGSEGV, (void (*)())eusint);
#endif
  signal(SIGBUS,  (void (*)())eusint);

  toplevel(ctx,mainargc,mainargv);

  { pointer exithook=speval(QEXITHOOK);
    if (exithook != NIL) {
      ufuncall(ctx,exithook,exithook,(pointer)(ctx->vsp),0,0);}
    }

#if THREADED
#if SunOS4_1
  thr_exit(0);
#else
  exit(0);
#endif
#endif
  }

int main(argc,argv)
int argc;
char *argv[];
{ int i, stat=0;
  unsigned char *m;

#ifdef Darwin
  _end = sbrk(0);
#endif

  mypid=getpid();
  mainargc=argc;
  for (i=0; i<argc; i++) mainargv[i]=argv[i];

  tzset();

#if Linux && !OLD_LINUX && !Darwin
  mallopt(M_MMAP_MAX,0);
#endif

  /* following two lines are just to speed up frequent sbreak at the beginning
     of the execution. These lines may be deleted without any harm.*/
  m=(unsigned char *)malloc(4*1024*1024);
  cfree(m);

#if vxworks
  progname=taskName(mypid);
#else
  progname=argv[0];
#endif
  /* get stack area and initialize stack/frame pointers */
  for (i=0; i<MAXTHREAD; i++) euscontexts[i]=0;
  mainctx=(context *)makelispcontext(MAXSTACK);
#if THREADED
#if Solaris2
  mutex_init(&mark_lock, USYNC_THREAD, 0);
  mutex_init(&p_mark_lock, USYNC_THREAD, 0);
  thr_create(0, 2*1024*1024,mainthread, mainctx, 0, &maintid);
  { sigset_t mainsig, omainsig;
    sigemptyset(&mainsig);
    sigaddset(&mainsig, SIGINT);
    /* printf("mainthread=%d\n", thr_self()); */	 
    thr_sigsetmask(SIG_BLOCK, &mainsig, &omainsig);
    }
  thr_join(maintid, 0, (void *)&stat);
#else
#if SunOS4_1 || alpha || PTHREAD
  mthread_init( mainctx );
#ifdef RGC
  init_rgc();
#endif
#endif
  mainthread(mainctx);
#endif	/* Solaris2 */
#else
  mainthread(mainctx);
#endif
  
  { pointer exithook=speval(QEXITHOOK);
    if (exithook != NIL) {
      ufuncall(mainctx,exithook,exithook,(pointer)(mainctx->vsp),0,0);}
    }

  exit(stat);
  }

#if (WORD_SIZE == 64)
pointer makeint(eusinteger_t v) {
  if (v>(eusinteger_t)MAXPOSFIXNUM || v<(eusinteger_t)MINNEGFIXNUM) {
    if (v&0x7L) {
      return(mkbigint(v));
    }
    return ((pointer)(v|0x3L)); }
  else return((pointer)((v<<2)+2));
}
eusinteger_t intval(pointer p) {
  eusinteger_t i=(eusinteger_t)p;
  if (p==NULL) {
    fprintf(stderr,"p=null\n");
    raise(SIGSEGV);
    return 0;}
  else if ((i&0x3L)==0x3L) {
    return (i&~0x3L); }
  else if (isbignum(p)) {
    return (bigintval(p)); }
  else if ((i&0x7)==0x0L) {
    fprintf(stderr,";p=pointer?(%p)\n", p);
    return (i); }
  else return (((eusinteger_t)i)>>2);
}
#else
pointer makeint(eusinteger_t v) {
  if (v>(int)MAXPOSFIXNUM || v<(int)MINNEGFIXNUM) {
    //    fprintf(stderr, "makeint(%x)\n", v);
    if (v&0x3) {
      //      fprintf(stderr, "v=%x(bignum)\n", v);
      return(mkbigint(v));
    }
    return ((pointer)(v|0x3)); }
  else return((pointer)((v<<2)+2));
}
eusinteger_t intval(pointer p) {
  eusinteger_t i=(eusinteger_t)p;
  if (p==NULL) {
    fprintf(stderr,"p=null\n");
    return 0;}
  else if ((i&0x3)==0x3) {
    return (i&~0x3); }
  else if (isbignum(p)) {
    return (bigintval(p)); }
  else if ((i&0x3)==0x0) {
    fprintf(stderr,";p=pointer?(%p)\n", p);
    return (i); }
  else return (((eusinteger_t)i)>>2);
}
#endif

eusinteger_t hide_ptr (pointer p) { return (eusinteger_t)p; }
