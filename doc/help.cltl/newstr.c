#include "/tmp_mnt/net/etlic2/usr/local/eus/c/eus.h"
#include "newstr.h"
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;


/*newstr1*/
static pointer F50(n,argv,env)
register int n; register pointer argv[]; pointer env;
{ register pointer *local=vsp, w, *fqv=qv;
	if (n!=1) maerror();
	local[0]= argv[0];
	vsp=local+1;
	w=(pointer)LENGTH(1,local+0); /*length*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= local[0];
	vsp=local+4;
	w=fcall(1,local+3,fqv[0]); /*make-string*/
	local[3]= w;
whl52:
	local[4]= local[1];
	local[5]= (pointer)((int)(local[0])-4);
	vsp=local+6;
	w=(pointer)LESSP(2,local+4); /*<*/
	if (w==NIL) goto whx53;
	local[4]= makeint(94);
	local[5]= argv[0];
	{ register int i=intval(local[1]);
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	vsp=local+6;
	w=(pointer)NUMEQUAL(2,local+4); /*=*/
	if (w==NIL) goto con56;
	local[4]= makeint(73);
	local[5]= argv[0];
	{ register int i=intval((pointer)((int)(local[1])+4));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	vsp=local+6;
	w=(pointer)NUMEQUAL(2,local+4); /*=*/
	if (w==NIL) goto con56;
	local[4]= local[3];
	local[5]= local[2];
	w = makeint(9);
	{ register int i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[1] = (pointer)((int)(local[1])+4);
	local[4]= local[1];
	goto con55;
con56:
	local[4]= local[3];
	local[5]= local[2];
	local[6]= argv[0];
	{ register int i=intval(local[1]);
	  w=makeint(local[6]->c.str.chars[i]);}
	{ register int i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[4]= w;
	goto con55;
con57:
	local[4]= NIL;
con55:
	local[1] = (pointer)((int)(local[1])+4);
	local[2] = (pointer)((int)(local[2])+4);
	goto whl52;
whx53:
	local[4]= NIL;
blk54:
	local[4]= local[3];
	local[5]= makeint(0);
	local[6]= local[2];
	vsp=local+7;
	w=(pointer)SUBSEQ(3,local+4); /*subseq*/
	local[0]= w;
blk51:
	vsp=local; return(local[0]);}

/*newstr*/
static pointer F58(n,argv,env)
register int n; register pointer argv[]; pointer env;
{ register pointer *local=vsp, w, *fqv=qv;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto if60;
	local[0]= argv[0];
	vsp=local+1;
	w=(pointer)F50(1,local+0); /*newstr1*/
	local[0]= w;
	goto if61;
if60:
	w = argv[0];
	if (!iscons(w)) goto if62;
	local[0]= xcar(argv[0]);
	vsp=local+1;
	w=(pointer)F58(1,local+0); /*newstr*/
	local[0]= w;
	local[1]= xcdr(argv[0]);
	vsp=local+2;
	w=(pointer)F58(1,local+1); /*newstr*/
	vsp=local+1;
	local[0]= cons(local[0],w);
	goto if63;
if62:
	local[0]= argv[0];
if63:
if61:
	w = local[0];
	local[0]= w;
blk59:
	vsp=local; return(local[0]);}

/*newstrfile*/
static pointer F64(n,argv,env)
register int n; register pointer argv[]; pointer env;
{ register pointer *local=vsp, w, *fqv=qv;
	if (n!=2) maerror();
	local[0]= NIL;
	vsp=local+1;
	w=(pointer)GENSYM(0,local+1); /*gensym*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[1];
	local[4]= fqv[2];
	vsp=local+5;
	w=fcall(3,local+2,fqv[3]); /*open*/
	local[2]= w;
	vsp=local+3;
	w = makeclosure(codevec,quotevec,uwp66,argv,local);
	local[3]=(pointer)(protfp); local[4]=w; protfp=(struct protectframe *)(local+3);
	local[5]= argv[0];
	vsp=local+6;
	w=fcall(1,local+5,fqv[3]); /*open*/
	local[5]= w;
	vsp=local+6;
	w = makeclosure(codevec,quotevec,uwp67,argv,local);
	local[6]=(pointer)(protfp); local[7]=w; protfp=(struct protectframe *)(local+6);
tag70:
	local[8]= local[5];
	local[9]= NIL;
	local[10]= local[1];
	vsp=local+11;
	w=(pointer)READ(3,local+8); /*read*/
	local[0] = w;
	local[8]= local[0];
	if (local[1]!=local[8]) goto if71;
	w = NIL;
	vsp=local+8;
	unwind(local+0);
	local[0]=w;
	goto blk65;
	goto if72;
if71:
	local[8]= NIL;
if72:
	local[8]= local[0];
	vsp=local+9;
	w=(pointer)F58(1,local+8); /*newstr*/
	local[8]= w;
	local[9]= local[2];
	vsp=local+10;
	w=(pointer)PRINT(2,local+8); /*print*/
	vsp=local+8;
	goto tag70;
	local[8]= NIL;
blk69:
	w = local[8];
	vsp=local+8;
	uwp67(0,local+8,protfp->cleaner);
	protfp=protfp->protlink;
	vsp=local+5;
	uwp66(0,local+5,protfp->cleaner);
	protfp=protfp->protlink;
	local[0]= w;
blk65:
	vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer uwp66(n,argv,env)
register int n; register pointer argv[]; pointer env;
{ register pointer *local=vsp, w, *fqv=qv;
	local[0]= env->c.clo.env2[2];
	vsp=local+1;
	w=(pointer)CLOSE(1,local+0); /*close*/
	local[0]= w;
	vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer uwp67(n,argv,env)
register int n; register pointer argv[]; pointer env;
{ register pointer *local=vsp, w, *fqv=qv;
	local[0]= env->c.clo.env2[5];
	vsp=local+1;
	w=(pointer)CLOSE(1,local+0); /*close*/
	local[0]= w;
	vsp=local; return(local[0]);}

/*allnewstrfile*/
static pointer F73(n,argv,env)
register int n; register pointer argv[]; pointer env;
{ register pointer *local=vsp, w, *fqv=qv;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	vsp=local+2;
	w=fcall(1,local+1,fqv[4]); /*directory*/
	local[1]= w;
whl76:
	if (local[1]==NIL) goto whx77;
	local[2]= xcar(local[1]);
	local[1] = xcdr(local[1]);
	w = local[2];
	local[0] = w;
	local[2]= fqv[5];
	local[3]= local[0];
	vsp=local+4;
	w=fcall(2,local+2,fqv[6]); /*substringp*/
	if (w==NIL) goto if80;
	local[2]= fqv[7];
	vsp=local+3;
	w=(pointer)UNLINK(1,local+2); /*unix:unlink*/
	local[2]= local[0];
	local[3]= fqv[8];
	vsp=local+4;
	w=(pointer)F64(2,local+2); /*newstrfile*/
	local[2]= local[0];
	vsp=local+3;
	w=(pointer)UNLINK(1,local+2); /*unix:unlink*/
	local[2]= NIL;
	local[3]= fqv[9];
	local[4]= local[0];
	vsp=local+5;
	w=(pointer)XFORMAT(3,local+2); /*format*/
	local[2]= w;
	vsp=local+3;
	w=(pointer)SYSTEM(1,local+2); /*unix:system*/
	local[2]= w;
	goto if81;
if80:
	local[2]= NIL;
if81:
	goto whl76;
whx77:
	local[2]= NIL;
blk78:
	w = NIL;
	local[0]= w;
blk74:
	vsp=local; return(local[0]);}

/* initializers*/
pointer eusmain(mod)
pointer mod;
{ register pointer *local=vsp, w, *fqv; pointer *argv;
  module=mod; quotevec=mod->c.code.quotevec;
  codevec=mod->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
	vsp=local+0;
	compfun(fqv[10],mod,F50,fqv[11]);
	vsp=local+0;
	compfun(fqv[12],mod,F58,fqv[11]);
	vsp=local+0;
	compfun(fqv[13],mod,F64,fqv[11]);
	vsp=local+0;
	compfun(fqv[14],mod,F73,fqv[11]);
	local[0]= NIL;
	vsp=local; return(local[0]);}
