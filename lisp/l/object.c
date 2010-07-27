/* object.c :  entry=object */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "object.h"
#pragma init (register_object)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___object();
extern pointer build_quote_vector();
static register_object()
  { add_module_initializer("___object", ___object);}

static pointer F48880();
static pointer F48882();

/*metaclass-name*/
static pointer F48880(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[0]));
	local[0]= w;
BLK48910:
	ctx->vsp=local; return(local[0]);}

/*metaclass-vars*/
static pointer F48882(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[1]));
	local[0]= w;
BLK48925:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M48943(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT48947;}
	local[0]= T;
ENT48947:
ENT48946:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= local[0];
	local[3]= fqv[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F48880(ctx,1,local+4); /*metaclass-name*/
	local[4]= w;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)ADDRESS(ctx,1,local+5); /*system:address*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= NIL;
	local[3]= local[1];
WHL48993:
	if (local[3]==NIL) goto WHX48994;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[0];
	local[5]= fqv[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	goto WHL48993;
WHX48994:
	local[4]= NIL;
BLK48995:
	w = NIL;
	local[2]= fqv[4];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	w = argv[0];
	local[0]= w;
BLK48944:
	ctx->vsp=local; return(local[0]);}

/*:warning*/
static pointer M49056(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST49059:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[5]);
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK49057:
	ctx->vsp=local; return(local[0]);}

/*:error*/
static pointer M49080(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST49083:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[6]);
	local[2]= argv[0];
	local[3]= fqv[7];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[9]); /*reploop*/
	local[0]= w;
BLK49081:
	ctx->vsp=local; return(local[0]);}

/*:slots*/
static pointer M49109(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F48882(ctx,1,local+0); /*metaclass-vars*/
	local[0]= w;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL49165:
	local[4]= local[2];
	w = local[3];
	if ((integer_t)local[4] >= (integer_t)w) goto WHX49166;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)GETCLASS(ctx,1,local+6); /*class*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SLOT(ctx,3,local+5); /*slot*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[2] = (pointer)((integer_t)(local[2])+4);
	goto WHL49165;
WHX49166:
	local[4]= NIL;
BLK49167:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK49110:
	ctx->vsp=local; return(local[0]);}

/*:methods*/
static pointer M49215(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[10]);
	local[1]= (pointer)get_sym_func(fqv[11]);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK49216:
	ctx->vsp=local; return(local[0]);}

/*:super*/
static pointer M49243(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK49244:
	ctx->vsp=local; return(local[0]);}

/*:get-val*/
static pointer M49263(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SLOT(ctx,3,local+0); /*slot*/
	local[0]= w;
BLK49264:
	ctx->vsp=local; return(local[0]);}

/*:set-val*/
static pointer M49285(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SETSLOT(ctx,4,local+0); /*setslot*/
	local[0]= w;
BLK49286:
	ctx->vsp=local; return(local[0]);}

/*:plist*/
static pointer M49318(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49322;}
	local[0]= NIL;
ENT49322:
ENT49321:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF49338;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF49339;
IF49338:
	local[1]= argv[0]->c.obj.iv[0];
IF49339:
	w = local[1];
	local[0]= w;
BLK49319:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M49351(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK49352:
	ctx->vsp=local; return(local[0]);}

/*:put*/
static pointer M49375(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF49406;
	local[1]= local[0];
	local[2]= fqv[14];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF49407;
IF49406:
	local[1]= argv[2];
	w = argv[3];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w = argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[0] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[0];
IF49407:
	w = argv[3];
	local[0]= w;
BLK49376:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M49439(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49443;}
	local[0]= NIL;
ENT49443:
ENT49442:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF49459;
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[16];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF49460;
IF49459:
	local[1]= argv[0];
	local[2]= fqv[17];
	local[3]= fqv[16];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF49460:
	w = local[1];
	local[0]= w;
BLK49440:
	ctx->vsp=local; return(local[0]);}

/*:remprop*/
static pointer M49480(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF49509;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[18]); /*delete*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	goto IF49510;
IF49509:
	local[1]= NIL;
IF49510:
	w = local[1];
	local[0]= w;
BLK49481:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M49526(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49530;}
	local[0]= T;
ENT49530:
ENT49529:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF49556;
	local[4]= (pointer)get_sym_func(fqv[19]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[20]));
	local[7]= fqv[21];
	local[8]= local[0];
	local[9]= local[3];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	local[4]= w;
	goto IF49557;
IF49556:
	local[4]= (pointer)get_sym_func(fqv[19]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[20]));
	local[7]= fqv[21];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,6,local+4); /*apply*/
	local[4]= w;
IF49557:
	w = local[4];
	local[0]= w;
BLK49527:
	ctx->vsp=local; return(local[0]);}

/*:new*/
static pointer M49609(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
BLK49610:
	ctx->vsp=local; return(local[0]);}

/*:super*/
static pointer M49625(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK49626:
	ctx->vsp=local; return(local[0]);}

/*:methods*/
static pointer M49640(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK49641:
	ctx->vsp=local; return(local[0]);}

/*:method*/
static pointer M49655(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[22]); /*assoc*/
	local[0]= w;
BLK49656:
	ctx->vsp=local; return(local[0]);}

/*:method-names*/
static pointer M49675(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49679;}
	local[0]= fqv[23];
ENT49679:
ENT49678:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[24]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[25]); /*string-upcase*/
	local[0] = w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO49709,env,argv,local);
	local[2]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[0]= w;
BLK49676:
	ctx->vsp=local; return(local[0]);}

/*:all-methods*/
static pointer M49714(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF49727;
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	goto IF49728;
IF49727:
	local[0]= argv[0]->c.obj.iv[7];
IF49728:
	w = local[0];
	local[0]= w;
BLK49715:
	ctx->vsp=local; return(local[0]);}

/*:all-method-names*/
static pointer M49742(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49746;}
	local[0]= fqv[27];
ENT49746:
ENT49745:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0];
	local[3]= fqv[28];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	if (argv[0]->c.obj.iv[2]==NIL) goto IF49781;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF49782;
IF49781:
	local[2]= NIL;
IF49782:
	local[3]= local[1];
	w = local[2];
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK49743:
	ctx->vsp=local; return(local[0]);}

/*:slots*/
static pointer M49803(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK49804:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M49818(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK49819:
	ctx->vsp=local; return(local[0]);}

/*:cid*/
static pointer M49833(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK49834:
	ctx->vsp=local; return(local[0]);}

/*:cix*/
static pointer M49848(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK49849:
	ctx->vsp=local; return(local[0]);}

/*:sub*/
static pointer M49863(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LISTALLCLASSES(ctx,0,local+2); /*system:list-all-classes*/
	local[2]= w;
WHL49903:
	if (local[2]==NIL) goto WHX49904;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[13];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF49952;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF49953;
IF49952:
	local[3]= NIL;
IF49953:
	goto WHL49903;
WHX49904:
	local[3]= NIL;
BLK49905:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK49864:
	ctx->vsp=local; return(local[0]);}

/*:subclasses*/
static pointer M49983(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK49984:
	ctx->vsp=local; return(local[0]);}

/*:hierarchy*/
static pointer M50001(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL50044:
	if (local[2]==NIL) goto WHX50045;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL50044;
WHX50045:
	local[3]= NIL;
BLK50046:
	w = NIL;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK50002:
	ctx->vsp=local; return(local[0]);}

/*:superclasses*/
static pointer M50120(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL50150:
	if (local[1]==NIL) goto WHX50151;
	local[2]= local[1];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= local[1];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	goto WHL50150;
WHX50151:
	local[2]= NIL;
BLK50152:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK50121:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO49709(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[31]); /*symbol-name*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[32]); /*substringp*/
	if (w==NIL) goto IF50207;
	local[0]= argv[0];
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF50208;
IF50207:
	local[0]= NIL;
IF50208:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M50243(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT50247;}
	local[0]= T;
ENT50247:
ENT50246:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[19]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[20]));
	local[5]= fqv[21];
	local[6]= local[0];
	local[7]= loadglobal(fqv[24]);
	local[8]= fqv[33];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= fqv[34];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,4,local+7); /*concatenate*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK50244:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___object(ctx,n,argv,env)
register context *ctx; int n; pointer *argv; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;
  module=argv[0];
  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[36];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF50291;
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[38],w);
	goto IF50292;
IF50291:
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF50292:
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F48880,fqv[42]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[43],module,F48882,fqv[44]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M48943,fqv[21],fqv[45],fqv[46]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49056,fqv[7],fqv[45],fqv[47]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49080,fqv[48],fqv[45],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49109,fqv[50],fqv[45],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49215,fqv[52],fqv[45],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49243,fqv[13],fqv[45],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49263,fqv[55],fqv[45],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49285,fqv[57],fqv[45],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49318,fqv[59],fqv[60],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49351,fqv[17],fqv[60],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49375,fqv[15],fqv[60],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49439,fqv[16],fqv[60],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49480,fqv[65],fqv[60],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49526,fqv[21],fqv[60],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49609,fqv[68],fqv[69],fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49625,fqv[13],fqv[69],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49640,fqv[52],fqv[69],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49655,fqv[73],fqv[69],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49675,fqv[28],fqv[69],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49714,fqv[26],fqv[69],fqv[76]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49742,fqv[12],fqv[69],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49803,fqv[50],fqv[69],fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49818,fqv[16],fqv[69],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49833,fqv[80],fqv[69],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49848,fqv[82],fqv[69],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49863,fqv[29],fqv[69],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49983,fqv[85],fqv[69],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50001,fqv[30],fqv[69],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50120,fqv[88],fqv[69],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50243,fqv[21],fqv[90],fqv[91]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
