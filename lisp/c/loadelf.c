/****************************************************************/
/* loadsave.sol.c
/*	load an euslisp source code file
/*	load a binary object file
/*	save current running image to a file
/*
/*	(c) T.Matsui, 1986
/****************************************************************/
static char *rcsid="@(#)$Id$";

#include <signal.h>
#include <ctype.h>
#include <sys/file.h>
#include <fcntl.h>
#include <dlfcn.h>
#if i86pc
#include <link.h>
#endif

#if alpha
#undef MAX
#undef MIN
#undef VMAX
#undef VMIN
#endif
#include "../c/eus.h"

extern int errno;
extern pointer openfile();
extern pointer makemodule(context *, int);

/****************************************************************/
/* load eus source
/*	Caution!!!
/*	This function does not ensure closing the input file,
/*	if an error occurs during load.
/*	So, this function should be used only for bootstrapping.
/*	Safer loader using with-open-file is defined in loader.l.
/****************************************************************/

pointer SRCLOAD(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer in,form;
  ckarg(1);
  in=openfile(ctx,(char *)argv[0]->c.str.chars,O_RDONLY,0,256);
  vpush(in);
  if (in==0) error(E_OPENFILE);
  form=reader(ctx,in,NIL);
  while (form!=(pointer)EOF){
    /* prinx(ctx,form,ERROUT); flushstream(ERROUT); terpri(ERROUT);*/
    /*fprintf(stderr, "%x\n", form);*/
    eval(ctx,form);
    form=reader(ctx,in,NIL);
    }
  closestream(in);
  vpop();
  return(NIL);}

/****************************************************************/
/* binload
/*	dynamic shared object loader for EusLisp on Solaris
/*	1986-Jun-22
/*	1986-Oct-15	modified to accept compiled code
/*	May/17/1994	reimplemetation using 'dl'
/****************************************************************
/* object module loader for Solaris 2.3
/* (system:binload
/*	"object.o" "quote.q" "_entry")
/*	1987-April	for sun3
/*	1987-December	for vax ultrix
/*	1988-Nov	nothing special for sony news
/*	1993-Jan	Solaris 2.0 Elf... failed
/*	1994-May	Solaris 2.3 dynamic linker (dl)
/****************************************************************/

#define MAX_SYSTEM_MODULES 100
int module_count=0;
struct {
    pointer (*entry_func)();
    char *module_name;}
  module_initializers[MAX_SYSTEM_MODULES];


void add_module_initializer(name, entry)
char *name;
pointer (*entry)();
{ 
  /* printf("%s %x is added in the module_initializer list\n", name, entry); */
  if (module_count>=MAX_SYSTEM_MODULES)  error(E_USER,(pointer)"too many system modules");
  module_initializers[module_count].module_name= name;
  module_initializers[module_count].entry_func=  entry;
  module_count++;}

/* exec_module_initializers is no longer called */
void exec_module_initializers(ctx)
register context *ctx;
{ eusinteger_t i, addr;
  pointer (*initfunc)(context *, int, pointer *);
  pointer mod;
  for (i=0; i< module_count; i++) {
    printf("executing init: %s at %p...",
	 module_initializers[i].module_name,
	 module_initializers[i].entry_func);
    fflush(stdout);
    initfunc=module_initializers[i].entry_func;
    mod=makemodule(ctx,0);
    vpush(mod);
    breakck;
    if (initfunc) { 
      addr = (eusinteger_t)initfunc;
      addr= addr>>2;
      mod->c.ldmod.entry=makeint(addr);
#if ARM
      mod->c.ldmod.entry2=makeint((eusinteger_t)initfunc);
#endif
      mod->c.ldmod.subrtype=SUBR_ENTRY;
      (*initfunc)(ctx,1, &mod); }
    vpop();
    printf(" ok\n");}
  module_count=0;}

#if Solaris2 && !GCC
pointer list_module_initializers(ctx,initnames)
context *ctx;
pointer initnames;
{ int i, addr;
  pointer (*initfunc)(int, pointer *);
  pointer mod, modname, p;
  for (i=0; i<module_count; i++) {
    initfunc=module_initializers[i].entry_func;
    modname=makestring(module_initializers[i].module_name,
			strlen(module_initializers[i].module_name));
    vpush(modname);
    addr= (int)initfunc; addr >>=2;
    mod=makemodule(ctx,0);
    mod->c.ldmod.codevec=makeint(0);
    mod->c.ldmod.entry=makeint(addr);
    mod->c.ldmod.subrtype=SUBR_FUNCTION;
    if (debug)  
      printf("collecting init: %s at %x module at %x\n",
	 module_initializers[i].module_name,
	 module_initializers[i].entry_func, mod);
    p=cons(ctx,mod, NIL);
    p=cons(ctx,vpop(), p);	/* (list modname mod) */
    vpush(p);}
  p=(pointer)stacknlist(ctx,module_count);
  module_count=0;
  return(p);}

#else
pointer list_module_initializers(ctx, initnames)
context *ctx;
pointer initnames;
{ int i;
  eusinteger_t addr;
  pointer (*initfunc)(int, pointer *);
  pointer mod, modname, p;
  void *dlhandle;
  char namebuf[256];

  dlhandle=dlopen(0,RTLD_LAZY);
  if (dlhandle==NULL) { 
    fprintf(stderr, "cannot dlopen self\n"); exit(2);}
  module_count=0;
  while (iscons(initnames)) {
    /* printf("%s ", ccar(initnames)->c.str.chars); */
    initfunc= dlsym(dlhandle, (char *)ccar(initnames)->c.str.chars);
    if (initfunc==NULL) {
      sprintf(namebuf,"___%s",ccar(initnames)->c.str.chars);
      initfunc=dlsym(dlhandle, namebuf);}

    if (initfunc) {
      /* printf(" ok\n"); */
      modname=ccar(initnames);
      vpush(modname);
      addr= (eusinteger_t)initfunc; addr >>=2;/* ???? */
      mod=makemodule(ctx,0);
      mod->c.ldmod.codevec=makeint(0);
      mod->c.ldmod.entry=makeint(addr);
#if ARM
      mod->c.ldmod.entry2=makeint((eusinteger_t)initfunc);
#endif
      mod->c.ldmod.subrtype=SUBR_FUNCTION;
      p=cons(ctx,mod, NIL);
      p=cons(ctx,vpop(), p);	/* (list modname mod) */
      vpush(p); module_count++;
    }
/*    else {
     printf("%s not loaded\n", ccar(initnames)->c.str.chars);}*/
    initnames=ccdr(initnames); }
  p=(pointer)stacknlist(ctx,module_count);
  module_count=0;
  return(p);}

pointer list_module_initializers2(ctx, n, argv)
register context *ctx;
int n;
pointer *argv;
{ int i;
  eusinteger_t addr;
  pointer (*initfunc)(int, pointer *);
  pointer mod, modname, initnames, p;
  void *dlhandle;
  char namebuf[256];

  ckarg(2);
  if (!isldmod(argv[0])) error(E_USER,(pointer)"not a LOAD-MODULE");
  if (!iscons(argv[1])) error(E_NOLIST);
#if (WORD_SIZE == 64)
  dlhandle=(void *)((eusinteger_t)(argv[0]->c.ldmod.handle) & ~3L);
#else
  dlhandle=(void *)((eusinteger_t)(argv[0]->c.ldmod.handle) & ~3);
#endif
  initnames=argv[1];
  module_count=0;
  if (dlhandle==NULL) error(E_USER,(pointer)"This module was not loaded");

  while (iscons(initnames)) {
    initfunc= dlsym(dlhandle, (char *)ccar(initnames)->c.str.chars);
    if (initfunc==NULL) {
      sprintf(namebuf,"___%s",ccar(initnames)->c.str.chars);
      initfunc=dlsym(dlhandle, namebuf);}

    if (initfunc) {
      modname=ccar(initnames);
      vpush(modname);
      addr= (eusinteger_t)initfunc; addr >>=2;/* ???? */
      mod=makemodule(ctx,0);
      mod->c.ldmod.codevec=makeint(0);
      mod->c.ldmod.entry=makeint(addr);
#if ARM
      mod->c.ldmod.entry2=makeint((eusinteger_t)initfunc);
#endif
      mod->c.ldmod.subrtype=SUBR_FUNCTION;
      p=cons(ctx,mod, NIL);
      p=cons(ctx,vpop(), p);	/* (list modname mod) */
      vpush(p); module_count++;}
    else {
     printf("%s not loaded\n", ccar(initnames)->c.str.chars); }
    initnames=ccdr(initnames); }
  p=(pointer)stacknlist(ctx,module_count);
  module_count=0;
  return(p);}
#endif

pointer build_quote_vector(ctx,size, strings)
register context *ctx;
int size;
char *strings[];
{ pointer qvec, p, qstring, qstream;
  int i, k;
  qvec=makevector(C_VECTOR,size);
  vpush(qvec);
  qstream=(pointer)mkstream(ctx,K_IN,makestring("",0));
  vpush(qstream);
  for (i=0; i<size; i++) {
    k=strlen((char *)strings[i]);
    qstring=makestring(strings[i], k);
    /*prinx(ctx,qstring, STDOUT); terpri(STDOUT); */
    pointer_update(qstream->c.stream.buffer,qstring);
    qstream->c.stream.count=makeint(0);
    qstream->c.stream.tail=makeint(k);
    pointer_update(qvec->c.vec.v[i],reader(ctx,qstream, NIL));}
  vpop();
  vpop();
  /* prinx(ctx,qvec, STDOUT); */
#ifdef SAFETY
  take_care(qvec);
#endif
  return(qvec);}

pointer eval_c_strings(ctx,size, strings)
register context *ctx;
int size;
const char *strings[];
{ pointer p, qstream, qstring;
  int i, k, total_length;
  char *s;
  byte *d;

  total_length=size;
  for (i=0; i<size; i++) { total_length += strlen(strings[i]); }
  qstring = makebuffer(total_length);
  vpush(qstring);
  d=qstring->c.str.chars;
  for (i=0; i<size; i++) {
    s=(char *)strings[i];
    while (*s) *d++ = *s++;
    *d++= '\n';}	/* newline is needed to ensure the reader
			   to stop ignoring comments */
  qstream=(pointer)mkstream(ctx,K_IN, qstring);
  vpush(qstream);
  qstream->c.stream.tail=makeint(total_length);
  while ((p=reader(ctx,qstream, NIL))!= (pointer)(-1))  {
     if (debug) { prinx(ctx,p,STDOUT); terpri(STDOUT);  }
     p=eval(ctx,p);}
  vpop();
  vpop();
  return(p);}

pointer FIND_ENTRY(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer entry, mod;
  char *entry_string;
  extern pointer sysmod;

  ckarg2(1,2);
  if (n==2) mod=argv[1];
  else mod=sysmod;
  if (!isldmod(mod)) error(E_USER,(pointer)"not a LOAD-MODULE");
  entry_string=(char *)get_string(argv[0]);
#if (WORD_SIZE == 64)
  entry=(pointer)dlsym((void *)((eusinteger_t)(mod->c.ldmod.handle) & ~3L), entry_string);
#else
  entry=(pointer)dlsym((void *)((eusinteger_t)(mod->c.ldmod.handle) & ~3), entry_string);
#endif
  if (entry==NULL) return(NIL);
  else return(makeint((eusinteger_t)entry>>2));}

pointer FIND_ENTRY2(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ pointer entry, mod, e=NIL;
  char *entry_string;
  extern pointer sysmod;

  ckarg2(1,2);
  if (n==2) mod=argv[1];
  else mod=sysmod;
  if (!isldmod(mod)) error(E_USER,(pointer)"not a LOAD-MODULE");
  entry_string=(char *)get_string(argv[0]);
#if (WORD_SIZE == 64)
  entry=(pointer)dlsym((void *)((eusinteger_t)(mod->c.ldmod.handle) & ~3L), entry_string);
#else
  entry=(pointer)dlsym((void *)((eusinteger_t)(mod->c.ldmod.handle) & ~3), entry_string);
#endif
  if (entry==NULL) return(NIL);
  else {
    e=cons(ctx,makeint((eusinteger_t)entry),e);
    e=cons(ctx,makeint((eusinteger_t)entry>>2),e);
    return(e);}}

extern pointer sysmod;

pointer SYSMOD()
{ return(sysmod);}

pointer UNBINLOAD(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ register pointer mod=argv[0];
  register int stat;
  ckarg(1);
  if (!isldmod(mod)) error(E_USER,(pointer)"not a compiled-module");
#if (WORD_SIZE == 64)
  stat=dlclose((void *)((eusinteger_t)(mod->c.ldmod.handle) & ~3L));
#else
  stat=dlclose((void *)((eusinteger_t)(mod->c.ldmod.handle) & ~3));
#endif
  if (stat) return(makeint(-errno));
  else return(T);}

pointer BINLOAD(ctx,n,argv)
register context *ctx;
int n;
pointer *argv;
{ char *binfn, *quofn;	/*binary and quote file names*/
  char *entry;
  int binfd,size,newsize,stat,i=0,l,s;
  pointer mod,quostrm,qvec;
  byte *loadaddress;
  pointer (*initfunc)(context *, int, pointer *);
  int data_align=0;
  eusinteger_t dlhandle, addr;

  ckarg2(1,2);
  binfn= (char *)get_string(argv[0]);
  if (n==2) {
    if (argv[1]==NIL) entry=NULL;
    else entry=(char *)get_string(argv[1]);}
  else entry=NULL;

  dlhandle=(eusinteger_t)dlopen(binfn, RTLD_LAZY);/* ???? */
  if (dlhandle == 0) {
    fprintf(stderr,"BINLOAD cannot dlopen: %s\n", dlerror());
    return(NIL);}
  initfunc=NULL;
  if (entry) {
    initfunc=(pointer (*)(context *, int, pointer *))dlsym((void *)dlhandle, entry);
    if (initfunc==NULL)
      initfunc=(pointer (*)(context *, int, pointer *))dlsym((void *)dlhandle, &entry[3]);
/*    if (initfunc==NULL) fprintf(stderr, ";; entry not found\n");*/
  }
  mod=makemodule(ctx,0);
  pointer_update(mod->c.ldmod.objname,argv[0]);
  mod->c.ldmod.handle=makeint(dlhandle>>2);
  vpush(mod);

  /*call initializer*/
  breakck;
  if (initfunc) { 
    addr=(eusinteger_t)initfunc; addr >>=2;/* ???? */
    mod->c.ldmod.codevec=makeint(0);
    mod->c.ldmod.entry=makeint(addr);
#if ARM
    mod->c.ldmod.entry2=makeint((eusinteger_t)initfunc);
#endif
    mod->c.ldmod.subrtype=SUBR_FUNCTION;
    (*initfunc)(ctx, 1, &mod); }
  else if (debug) fprintf(stderr,";; no initializer\n");
  return(vpop());	/* return the module */
  }


pointer SAVE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ error(E_USER,(pointer)"SAVE is not supported on Solaris");}


void loadsave(ctx,mod)
register context *ctx;
pointer mod;
{ pointer p=Spevalof(PACKAGE);
  pointer_update(Spevalof(PACKAGE),syspkg);
  defun(ctx,"SRCLOAD",mod,SRCLOAD,NULL);
#if Solaris2 && !GCC
  defun(ctx,"LIST-MODULE-INITIALIZERS",mod,list_module_initializers,NULL);
#else
  defun(ctx,"LIST-MODULE-INITIALIZERS",mod,list_module_initializers2,NULL);
#endif
  defun(ctx,"FIND-ENTRY", mod, FIND_ENTRY,NULL);
  defun(ctx,"FIND-ENTRY2", mod, FIND_ENTRY2,NULL);
  defun(ctx,"SYSMOD", mod, SYSMOD,NULL);
  defun(ctx,"BINLOAD",mod,BINLOAD,NULL);
  defun(ctx,"UNBINLOAD",mod,UNBINLOAD,NULL);
  defun(ctx,"SAVE",mod,SAVE,NULL);
  pointer_update(Spevalof(PACKAGE),p);}


