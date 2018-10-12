/****************************************************************/
/* EUSLISP foreign function interface
/*
/*	c --> lisp
/*	calleus(foreign-symbol,cargv)
/*
/*	lisp --> c
/*	After loading by using load-foreign func,
/*	(call-foreign address param-spec result-spec . args)
/*
/*	Since arguments are pushed on stack interpretedly at 
/*	runtime referring to parameter specification list,
/*	foreign function calls are not very fast.
/*	Euslisp's foreign function interface facility is provided
/*	for the purpose to link a huge library like suncore or sunview
/*	without much modification to those libraries,
/*	and not intending speeding up of execution.  
/*
/*	Copyright 1988, Toshihiro MATSUI, ETL,
/*		  hinted and urged by M.INABA, UTOYO.
/*
/*	1987-Sep-24
/*	1988-MAR-12 removed restriction on the number of args and types
/*		    implementation on SUN4
/****************************************************************/
static char *rcsid="@(#)$Id$";
#include "eus.h"

struct foreignpod {
#if vax || sun4 || news || mips || i386 || alpha || x86_64 || ARM
    unsigned mark:1;
    unsigned b:1;
    unsigned m:1;
    unsigned smark:1;
    unsigned pmark:1;
    unsigned elmtype:3;
    unsigned noexpose:1;
    unsigned extra:1;
    unsigned bix:6;
#endif
    short   cix;
    pointer speval,
	    vtype,		/*const,var*/
	    spefunc,
	    pname,
	    plist,
	    homepkg,
	    podcode,
	    paramtypes,
	    resulttype;};

cixpair foreignpodcp;

#define pisforeignpod(p) (foreignpodcp.cix<=((p)->cix) && \
			    		  ((p)->cix)<=foreignpodcp.sub)
#define isforeignpod(p) (ispointer(p) && pisforeignpod(p))

#if (defined x86_64) || (defined aarch64)
// Linux, x64
/* development version of euscall written by Y.Kakiuchi */
union NUMCONVBUF {
  eusfloat_t fval;
  eusinteger_t ival;
  int i32val;
  float f32val;
};

eusinteger_t
calleus(fsym,cargv)
register pointer fsym;	    /*foreign-symbol*/
register eusinteger_t cargv[]; /*arguments vector passed from C function*/
// cargv[0-5] integer, pointer
// cargv[6-13] float, double
// skip cargv[14](stack pointer), cargv[15] (stack alignment)
// cargv[16.. ] integer, pointer, float, double
// using TYPE
// byte, char, short, long, integer, pointer, int32
// float32, float, double,
{ register pointer param,resulttype,p,result;
  eusfloat_t f;
  float f32;
  context *ctx;
  pointer *argv;
  struct foreignpod *fs;
  eusinteger_t c;
  int argc=0 /* ,j */;
  eusinteger_t *iargv = cargv;
  eusinteger_t *fargv = &(cargv[6]);
  eusinteger_t *vargv = &(cargv[16]);
  int icount = 0, fcount = 0, vcount = 0;
  //numunion nu;
  union NUMCONVBUF nu;
  
#if 0
  printf("calleus : fsym.cix = %lX (%lX,%lX)\n", fsym->cix, fsym, &(fsym->cix));
#endif    
  ctx=euscontexts[thr_self()];
  argv=ctx->vsp;
  fs=(struct foreignpod *)fsym;
#if 0
  printf("calleus : fsym.paramtypes = %lX (%lX,%lX)\n",
         fs->paramtypes, (long *)fs, &(fs->paramtypes));
  printf("calleus : fsym.resulttype = %lX (%lX,%lX)\n",
         fs->resulttype, (long *)fs, &(fs->resulttype)); 
#endif
  if (!isforeignpod(fsym)) error(E_USER,(pointer)"not a foreign pod");
  param=fs->paramtypes;
  resulttype=fs->resulttype;
  while (islist(param)) {
    p=ccar(param); param=ccdr(param);
    if (p==K_INTEGER) {
      if(icount < 6)  c = iargv[icount++]; else c = vargv[vcount++];
      vpush(makeint(c));
#if 0
    } else if (p==K_INT32) {
      if(icount < 6)  c = iargv[icount++]; else c = vargv[vcount++];
      vpush(makeint(c & 0x00000000FFFFFFFF));
#endif
    } else if (p==K_FLOAT) {
      if(fcount < 8)  c = fargv[fcount++]; else c = vargv[vcount++];
      nu.ival = c;
      vpush(makeflt(nu.fval));
    } else if (p==K_FLOAT32) {
      if(fcount < 8)  c = fargv[fcount++]; else c = vargv[vcount++];
      nu.ival = c & 0x00000000FFFFFFFF;
      f = nu.f32val;
      vpush(makeflt(f));
    } else if (islist(p)) {
      if (ccar(p)!=K_STRING) error(E_USER,(pointer)":string key expected");
      p=ccdr(p);
      if (p==NIL) {
        if(icount < 6)  c = iargv[icount++]; else c = vargv[vcount++];
	vpush(makestring((char *)c,strlen((char *)c)));
      } else {
	p=ccar(p); //c=ckintval(p);
        if(icount < 6)  c = iargv[icount++]; else c = vargv[vcount++];
        vpush(makestring((char *)c, ckintval(p)));
      }
    } else if (p==K_STRING)  {
      if(icount < 6)  c = iargv[icount++]; else c = vargv[vcount++];
      c -= 2*sizeof(pointer);
      vpush((pointer)c);
    } else error(E_USER,(pointer)"unknown param type spec");
    argc++;
  }
#if 0
  // check argv
  printf("argc = %d\n", argc);
  for(int i=0;i<argc;i++) {
    printf("argv[%d] = %lX\n", argv[i]);
  }
#endif
  result=ufuncall(ctx,fsym,fsym,(pointer)argv,NULL,argc);
  ctx->vsp = argv;
  if (resulttype==K_STRING) return((eusinteger_t)(result->c.str.chars));
  else if (resulttype==K_FLOAT) {
    f=fltval(result);
    nu.fval=f;
    printf("calleus float-result=%f\n",f);
    return(nu.ival); 
  } else if (resulttype==K_FLOAT32) {
    f=fltval(result);
    f32 = f;
    nu.f32val = f32;
    return((eusinteger_t)nu.i32val);
  } else return(intval(result));
}
#else // #if x86_64
eusinteger_t
calleus(fsym,cargv,a2,a3,a4,a5,a6,a7,a8)
register pointer fsym;	/*foreign-symbol*/
register eusinteger_t cargv[];	/*arguments vector passed from C function*/
register int a2, a3, a4, a5, a6, a7, a8;
{ register pointer param,resulttype,p,result;
  double *dp;
  float f;
  context *ctx;
  pointer *argv;
  struct foreignpod *fs;
  eusinteger_t c;
  int i=0,argc=0,j;
  numunion nu;

  ctx=euscontexts[thr_self()];
  argv=ctx->vsp;
  fs=(struct foreignpod *)fsym;
  if (!isforeignpod(fsym)) error(E_USER,(pointer)"not a foreign pod");
  param=fs->paramtypes;
  resulttype=fs->resulttype;
  while (islist(param)) {
    p=ccar(param); param=ccdr(param);
    if (p==K_INTEGER) { vpush(makeint(cargv[i])); i++;}
    else if (p==K_FLOAT)   {
      dp=(double *)&cargv[i];  f= *dp;
      vpush(makeflt(f)); i+=2;}
    else if (islist(p)) {
      if (ccar(p)!=K_STRING) error(E_USER,(pointer)":string key expected");
      p=ccdr(p);
      if (p==NIL) {
	vpush(makestring((char *)cargv[i],strlen((char *)cargv[i]))); i++;} 
      else {
	p=ccar(p);
        c=ckintval(p);
        vpush(makestring((char *)cargv[i++],c));} }
    else if (p==K_STRING)  {
#if sun3 || (!alpha && system5) || apollo || sanyo
	c=cargv[i++]-6;
#else
	c=cargv[i++]-2*sizeof(pointer);
#endif
	vpush((pointer)c);}
    else error(E_USER,(pointer)"unknown param type spec");
    argc++;}
  result=ufuncall(ctx,fsym,fsym,(pointer)argv,NULL,argc);
  ctx->vsp = argv;
  if (resulttype==K_STRING) return((eusinteger_t)(result->c.str.chars));
  else if (resulttype==K_FLOAT) {
    f=fltval(result);
    nu.fval=f;
    printf("calleus float-result=%f\n",f);
    return(nu.ival); }
  else return(intval(result)); }
#endif // x86_64

void foreign(ctx,mod)
register context *ctx;
pointer mod;
{ pointer pkgsave;
  eusinteger_t i;/* ???? */
  pointer FOREIGN,C_FOREIGN;

  pkgsave=Spevalof(PACKAGE);
  pointer_update(Spevalof(PACKAGE), lisppkg);
  FOREIGN=basicclass("FOREIGN-POD",C_SYMBOL,&foreignpodcp,
	  	     3,"PODCODE","PARAMTYPES","RESULTTYPE");
  C_FOREIGN=Spevalof(FOREIGN);
  i=(eusinteger_t)calleus;
  defvar(ctx,"*CALLEUS*",makeint(i),lisppkg);
  pointer_update(Spevalof(PACKAGE), pkgsave);
  }
