/* Xeus.c :  entry=Xeus */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xeus.h"
#pragma init (register_Xeus)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xeus();
extern pointer build_quote_vector();
static register_Xeus()
  { add_module_initializer("___Xeus", ___Xeus);}

static pointer F321();
static pointer F322();
static pointer F323();
static pointer F324();
static pointer F325();
static pointer F326();
static pointer F327();
static pointer F328();
static pointer F329();
static pointer F330();
static pointer F331();
static pointer F332();
static pointer F333();
static pointer F334();
static pointer F335();
static pointer F336();
static pointer F337();
static pointer F338();
static pointer F339();
static pointer F340();
static pointer F341();
static pointer F342();
static pointer F343();
static pointer F344();
static pointer F345();
static pointer F346();
static pointer F347();
static pointer F348();
static pointer F349();
static pointer F350();
static pointer F351();
static pointer F352();
static pointer F353();
static pointer F354();
static pointer F355();
static pointer F356();
static pointer F357();
static pointer F358();
static pointer F359();
static pointer F360();
static pointer F361();
static pointer F362();
static pointer F363();
static pointer F364();
static pointer F365();
static pointer F366();
static pointer F367();
static pointer F368();
static pointer F369();
static pointer F370();
static pointer F371();
static pointer F372();
static pointer F373();
static pointer F374();
static pointer F375();
static pointer F376();
static pointer F377();
static pointer F378();
static pointer F379();
static pointer F380();
static pointer F381();
static pointer F382();
static pointer F383();
static pointer F384();
static pointer F385();
static pointer F386();
static pointer F387();
static pointer F388();
static pointer F389();
static pointer F390();
static pointer F391();
static pointer F392();
static pointer F393();
static pointer F394();
static pointer F395();
static pointer F396();
static pointer F397();
static pointer F398();
static pointer F399();
static pointer F400();
static pointer F401();
static pointer F402();
static pointer F403();
static pointer F404();
static pointer F405();

/*setwindowattributes-pixmap*/
static pointer F321(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK406:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-pixmap*/
static pointer F322(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK407:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-background_pixel*/
static pointer F323(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK408:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-background_pixel*/
static pointer F324(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(4);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK409:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-border_pixmap*/
static pointer F325(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(8);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK410:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-border_pixmap*/
static pointer F326(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(8);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK411:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-border_pixel*/
static pointer F327(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(12);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK412:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-border_pixel*/
static pointer F328(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(12);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK413:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-bit_gravity*/
static pointer F329(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(16);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK414:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-bit_gravity*/
static pointer F330(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(16);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK415:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-win_gravity*/
static pointer F331(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(20);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK416:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-win_gravity*/
static pointer F332(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(20);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK417:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-backing_store*/
static pointer F333(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(24);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK418:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-backing_store*/
static pointer F334(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(24);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK419:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-backing_planes*/
static pointer F335(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(28);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK420:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-backing_planes*/
static pointer F336(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(28);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK421:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-backing_pixel*/
static pointer F337(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(32);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK422:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-backing_pixel*/
static pointer F338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(32);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK423:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-save_under*/
static pointer F339(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(36);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK424:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-save_under*/
static pointer F340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(36);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK425:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-event_mask*/
static pointer F341(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(40);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK426:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-event_mask*/
static pointer F342(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(40);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK427:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-do_not_propagate_mask*/
static pointer F343(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(44);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK428:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-do_not_propagate_mask*/
static pointer F344(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(44);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK429:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-override_redirect*/
static pointer F345(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(48);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK430:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-override_redirect*/
static pointer F346(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(48);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK431:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-colormap*/
static pointer F347(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(52);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK432:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-colormap*/
static pointer F348(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(52);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK433:
	ctx->vsp=local; return(local[0]);}

/*setwindowattributes-cursor*/
static pointer F349(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(56);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK434:
	ctx->vsp=local; return(local[0]);}

/*set-setwindowattributes-cursor*/
static pointer F350(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(56);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK435:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-x*/
static pointer F351(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK436:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-x*/
static pointer F352(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK437:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-y*/
static pointer F353(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK438:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-y*/
static pointer F354(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(4);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK439:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-width*/
static pointer F355(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(8);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK440:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-width*/
static pointer F356(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(8);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK441:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-height*/
static pointer F357(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(12);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK442:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-height*/
static pointer F358(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(12);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK443:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-border_width*/
static pointer F359(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(16);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK444:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-border_width*/
static pointer F360(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(16);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK445:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-depth*/
static pointer F361(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(20);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK446:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-depth*/
static pointer F362(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(20);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK447:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-visual*/
static pointer F363(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(24);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK448:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-visual*/
static pointer F364(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(24);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK449:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-root*/
static pointer F365(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(28);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK450:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-root*/
static pointer F366(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(28);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK451:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-class*/
static pointer F367(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(32);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK452:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-class*/
static pointer F368(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(32);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK453:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-bit_gravity*/
static pointer F369(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(36);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK454:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-bit_gravity*/
static pointer F370(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(36);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK455:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-win_gravity*/
static pointer F371(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(40);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK456:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-win_gravity*/
static pointer F372(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(40);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK457:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-backing_store*/
static pointer F373(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(44);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK458:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-backing_store*/
static pointer F374(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(44);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK459:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-backing_planes*/
static pointer F375(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(48);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK460:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-backing_planes*/
static pointer F376(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(48);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK461:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-backing_pixel*/
static pointer F377(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(52);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK462:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-backing_pixel*/
static pointer F378(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(52);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK463:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-save_under*/
static pointer F379(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(56);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK464:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-save_under*/
static pointer F380(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(56);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK465:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-colormap*/
static pointer F381(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(60);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK466:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-colormap*/
static pointer F382(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(60);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK467:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-map_installed*/
static pointer F383(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(64);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK468:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-map_installed*/
static pointer F384(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(64);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK469:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-map_state*/
static pointer F385(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(68);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK470:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-map_state*/
static pointer F386(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(68);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK471:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-all_event_masks*/
static pointer F387(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(72);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK472:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-all_event_masks*/
static pointer F388(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(72);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK473:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-your_event_mask*/
static pointer F389(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(76);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK474:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-your_event_mask*/
static pointer F390(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(76);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK475:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-do_not_propagate_mask*/
static pointer F391(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(80);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK476:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-do_not_propagate_mask*/
static pointer F392(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(80);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK477:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-override_redirect*/
static pointer F393(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(84);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK478:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-override_redirect*/
static pointer F394(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(84);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK479:
	ctx->vsp=local; return(local[0]);}

/*windowattributes-screen*/
static pointer F395(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(88);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK480:
	ctx->vsp=local; return(local[0]);}

/*set-windowattributes-screen*/
static pointer F396(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(88);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK481:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M482(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT487;}
	local[0]= NIL;
ENT487:
	if (n>=5) { local[1]=(argv[4]); goto ENT486;}
	local[1]= NIL;
ENT486:
	if (n>=6) { local[2]=(argv[5]); goto ENT485;}
	local[2]= NIL;
ENT485:
ENT484:
	if (n>6) maerror();
	if (local[2]==NIL) goto CON489;
	local[3]= local[2];
	goto CON488;
CON489:
	if (argv[2]==NIL) goto CON490;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= fqv[4];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto CON488;
CON490:
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto CON488;
CON492:
	local[3]= NIL;
CON488:
	argv[0]->c.obj.iv[3] = local[3];
	argv[0]->c.obj.iv[2] = argv[2];
	if (local[0]==NIL) goto IF494;
	argv[0]->c.obj.iv[5] = local[0];
	local[3]= argv[0]->c.obj.iv[5];
	goto IF495;
IF494:
	local[3]= NIL;
IF495:
	if (local[1]==NIL) goto IF496;
	argv[0]->c.obj.iv[6] = local[1];
	local[3]= argv[0]->c.obj.iv[6];
	goto IF497;
IF496:
	local[3]= NIL;
IF497:
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= loadglobal(fqv[5]);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,3,local+3,&ftab[0],fqv[6]); /*sethash*/
	w = argv[0];
	local[0]= w;
BLK483:
	ctx->vsp=local; return(local[0]);}

/*:drawable*/
static pointer M498(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK499:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M500(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= w;
BLK501:
	ctx->vsp=local; return(local[0]);}

/*:geometry*/
static pointer M502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[9]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= loadglobal(fqv[10]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= loadglobal(fqv[10]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= loadglobal(fqv[10]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= loadglobal(fqv[10]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= loadglobal(fqv[10]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= loadglobal(fqv[10]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= loadglobal(fqv[7]);
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= local[0];
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[3];
	local[13]= local[4];
	local[14]= local[5];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(*ftab[2])(ctx,9,local+7,&ftab[2],fqv[11]); /*getgeometry*/
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[9]); /*c-long*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,1,local+8,&ftab[4],fqv[10]); /*c-int*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[10]); /*c-int*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,1,local+10,&ftab[4],fqv[10]); /*c-int*/
	local[10]= w;
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(*ftab[4])(ctx,1,local+11,&ftab[4],fqv[10]); /*c-int*/
	local[11]= w;
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[10]); /*c-int*/
	local[12]= w;
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[4])(ctx,1,local+13,&ftab[4],fqv[10]); /*c-int*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,7,local+7); /*list*/
	local[0]= w;
BLK503:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M504(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
BLK505:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M506(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
BLK507:
	ctx->vsp=local; return(local[0]);}

/*:pos*/
static pointer M508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= loadglobal(fqv[13]);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[14]); /*getwindowattributes*/
	local[0]= loadglobal(fqv[13]);
	local[1]= fqv[15];
	local[2]= fqv[16];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[13]);
	local[2]= fqv[15];
	local[3]= fqv[17];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK509:
	ctx->vsp=local; return(local[0]);}

/*:x*/
static pointer M510(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= loadglobal(fqv[13]);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[14]); /*getwindowattributes*/
	local[0]= loadglobal(fqv[13]);
	local[1]= fqv[15];
	local[2]= fqv[16];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK511:
	ctx->vsp=local; return(local[0]);}

/*:y*/
static pointer M512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= loadglobal(fqv[13]);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[14]); /*getwindowattributes*/
	local[0]= loadglobal(fqv[13]);
	local[1]= fqv[15];
	local[2]= fqv[17];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK513:
	ctx->vsp=local; return(local[0]);}

/*:gc*/
static pointer M514(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST516:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto CON518;
	local[1]= argv[0]->c.obj.iv[3];
	goto CON517;
CON518:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= loadglobal(fqv[2]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON519;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.car;
	local[1]= argv[0]->c.obj.iv[3];
	goto CON517;
CON519:
	local[1]= (pointer)get_sym_func(fqv[18]);
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto CON517;
CON520:
	local[1]= NIL;
CON517:
	w = local[1];
	local[0]= w;
BLK515:
	ctx->vsp=local; return(local[0]);}

/*:gcid*/
static pointer M521(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[19];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK522:
	ctx->vsp=local; return(local[0]);}

/*:line-width*/
static pointer M523(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT526;}
	local[0]= NIL;
ENT526:
ENT525:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK524:
	ctx->vsp=local; return(local[0]);}

/*:line-style*/
static pointer M527(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT530;}
	local[0]= NIL;
ENT530:
ENT529:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK528:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M531(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT534;}
	local[0]= NIL;
ENT534:
ENT533:
	if (n>3) maerror();
	w = local[0];
	if (isnum(w)) goto OR537;
	w = local[0];
	if (isstring(w)) goto OR537;
	w = local[0];
	if (issymbol(w)) goto OR537;
	goto CON536;
OR537:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[22];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[3];
	goto CON535;
CON536:
	local[1]= local[0];
	local[2]= loadglobal(fqv[2]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON538;
	argv[0]->c.obj.iv[3] = local[0];
	local[1]= argv[0]->c.obj.iv[3];
	goto CON535;
CON538:
	local[1]= argv[0]->c.obj.iv[3];
	goto CON535;
CON539:
	local[1]= NIL;
CON535:
	w = local[1];
	local[0]= w;
BLK532:
	ctx->vsp=local; return(local[0]);}

/*:copy-from*/
static pointer M540(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[23], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY542;
	local[0] = NIL;
KEY542:
	if (n & (1<<1)) goto KEY543;
	local[1] = NIL;
KEY543:
	if (n & (1<<2)) goto KEY544;
	local[2] = makeint(0);
KEY544:
	if (n & (1<<3)) goto KEY545;
	local[3] = makeint(0);
KEY545:
	if (n & (1<<4)) goto KEY546;
	local[4] = makeint(0);
KEY546:
	if (n & (1<<5)) goto KEY547;
	local[5] = makeint(0);
KEY547:
	if (local[0]!=NIL) goto IF548;
	if (local[1]!=NIL) goto IF548;
	local[6]= argv[0];
	local[7]= fqv[12];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[0] = w;
	local[7]= local[6];
	local[8]= makeint(4);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[1] = w;
	w = local[1];
	local[6]= w;
	goto IF549;
IF548:
	local[6]= NIL;
IF549:
	local[6]= loadglobal(fqv[7]);
	local[7]= argv[2];
	local[8]= fqv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[4];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(*ftab[6])(ctx,10,local+6,&ftab[6],fqv[24]); /*copyarea*/
	local[0]= w;
BLK541:
	ctx->vsp=local; return(local[0]);}

/*:shift*/
static pointer M550(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT553;}
	local[0]= makeint(0);
ENT553:
ENT552:
	if (n>4) maerror();
	w = argv[2];
	if (!isflt(w)) goto IF554;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	argv[2] = w;
	local[1]= argv[2];
	goto IF555;
IF554:
	local[1]= NIL;
IF555:
	w = local[0];
	if (!isflt(w)) goto IF556;
	local[1]= argv[0];
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0] = w;
	local[1]= local[0];
	goto IF557;
IF556:
	local[1]= NIL;
IF557:
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= argv[0];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[26];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,10,local+1,&ftab[6],fqv[24]); /*copyarea*/
	local[0]= w;
BLK551:
	ctx->vsp=local; return(local[0]);}

/*:point*/
static pointer M558(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT561;}
	local[0]= argv[0]->c.obj.iv[3];
ENT561:
ENT560:
	if (n>5) maerror();
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,5,local+1,&ftab[7],fqv[27]); /*drawpoint*/
	local[0]= w;
BLK559:
	ctx->vsp=local; return(local[0]);}

/*:line*/
static pointer M562(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT565;}
	local[0]= argv[0]->c.obj.iv[3];
ENT565:
ENT564:
	if (n>7) maerror();
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= argv[4];
	local[7]= argv[5];
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,7,local+1,&ftab[8],fqv[28]); /*drawline*/
	local[0]= w;
BLK563:
	ctx->vsp=local; return(local[0]);}

/*:rectangle*/
static pointer M566(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT569;}
	local[0]= argv[0]->c.obj.iv[3];
ENT569:
ENT568:
	if (n>7) maerror();
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= argv[4];
	local[7]= argv[5];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,7,local+1,&ftab[9],fqv[29]); /*drawrectangle*/
	local[0]= w;
BLK567:
	ctx->vsp=local; return(local[0]);}

/*:arc*/
static pointer M570(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT576;}
	local[0]= argv[4];
ENT576:
	if (n>=7) { local[1]=(argv[6]); goto ENT575;}
	local[1]= makeflt(0.00000000e+00);
ENT575:
	if (n>=8) { local[2]=(argv[7]); goto ENT574;}
	local[2]= makeflt(6.28318405e+00);
ENT574:
	if (n>=9) { local[3]=(argv[8]); goto ENT573;}
	local[3]= argv[0]->c.obj.iv[3];
ENT573:
ENT572:
	if (n>9) maerror();
	local[4]= loadglobal(fqv[7]);
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[3]->c.obj.iv[2];
	local[7]= argv[2];
	local[8]= argv[3];
	local[9]= argv[4];
	local[10]= local[0];
	local[11]= makeint(64);
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(*ftab[10])(ctx,1,local+12,&ftab[10],fqv[30]); /*rad2deg*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ROUND(ctx,1,local+11); /*round*/
	local[11]= w;
	local[12]= makeint(64);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(*ftab[10])(ctx,1,local+13,&ftab[10],fqv[30]); /*rad2deg*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[11])(ctx,9,local+4,&ftab[11],fqv[31]); /*drawarc*/
	local[0]= w;
BLK571:
	ctx->vsp=local; return(local[0]);}

/*:fill-rectangle*/
static pointer M577(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT580;}
	local[0]= argv[0]->c.obj.iv[3];
ENT580:
ENT579:
	if (n>7) maerror();
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[5];
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[12])(ctx,7,local+1,&ftab[12],fqv[32]); /*fillrectangle*/
	local[0]= w;
BLK578:
	ctx->vsp=local; return(local[0]);}

/*:fill-arc*/
static pointer M581(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT587;}
	local[0]= argv[4];
ENT587:
	if (n>=7) { local[1]=(argv[6]); goto ENT586;}
	local[1]= makeflt(0.00000000e+00);
ENT586:
	if (n>=8) { local[2]=(argv[7]); goto ENT585;}
	local[2]= makeflt(6.28318405e+00);
ENT585:
	if (n>=9) { local[3]=(argv[8]); goto ENT584;}
	local[3]= argv[0]->c.obj.iv[3];
ENT584:
ENT583:
	if (n>9) maerror();
	local[4]= loadglobal(fqv[7]);
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[3]->c.obj.iv[2];
	local[7]= argv[2];
	local[8]= argv[3];
	local[9]= argv[4];
	local[10]= local[0];
	local[11]= makeint(64);
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(*ftab[10])(ctx,1,local+12,&ftab[10],fqv[30]); /*rad2deg*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ROUND(ctx,1,local+11); /*round*/
	local[11]= w;
	local[12]= makeint(64);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(*ftab[10])(ctx,1,local+13,&ftab[10],fqv[30]); /*rad2deg*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[13])(ctx,9,local+4,&ftab[13],fqv[33]); /*fillarc*/
	local[0]= w;
BLK582:
	ctx->vsp=local; return(local[0]);}

/*:string*/
static pointer M588(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT593;}
	local[0]= makeint(0);
ENT593:
	if (n>=7) { local[1]=(argv[6]); goto ENT592;}
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
ENT592:
	if (n>=8) { local[2]=(argv[7]); goto ENT591;}
	local[2]= argv[0]->c.obj.iv[3];
ENT591:
ENT590:
	if (n>8) maerror();
	local[3]= loadglobal(fqv[7]);
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= local[2]->c.obj.iv[2];
	local[6]= argv[2];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)ADDRESS(ctx,1,local+8); /*system:address*/
	local[8]= w;
	local[9]= makeint(4);
	{ integer_t i,j;
		j=intval(makeint(2)); i=intval(local[9]);
		local[9]=(makeint(i * j));}
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,3,local+8); /*+*/
	local[8]= w;
	local[9]= local[1];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,7,local+3,&ftab[14],fqv[34]); /*drawstring*/
	local[0]= w;
BLK589:
	ctx->vsp=local; return(local[0]);}

/*:image-string*/
static pointer M594(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT599;}
	local[0]= makeint(0);
ENT599:
	if (n>=7) { local[1]=(argv[6]); goto ENT598;}
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
ENT598:
	if (n>=8) { local[2]=(argv[7]); goto ENT597;}
	local[2]= argv[0]->c.obj.iv[3];
ENT597:
ENT596:
	if (n>8) maerror();
	local[3]= loadglobal(fqv[7]);
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= local[2]->c.obj.iv[2];
	local[6]= argv[2];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)ADDRESS(ctx,1,local+8); /*system:address*/
	local[8]= w;
	local[9]= makeint(4);
	{ integer_t i,j;
		j=intval(makeint(2)); i=intval(local[9]);
		local[9]=(makeint(i * j));}
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,3,local+8); /*+*/
	local[8]= w;
	local[9]= local[1];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[15])(ctx,7,local+3,&ftab[15],fqv[35]); /*drawimagestring*/
	local[0]= w;
BLK595:
	ctx->vsp=local; return(local[0]);}

/*:getimage*/
static pointer M600(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[36], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY602;
	local[0] = NIL;
KEY602:
	if (n & (1<<1)) goto KEY603;
	local[1] = makeint(0);
KEY603:
	if (n & (1<<2)) goto KEY604;
	local[2] = makeint(0);
KEY604:
	if (n & (1<<3)) goto KEY605;
	local[7]= argv[0];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[3] = w;
KEY605:
	if (n & (1<<4)) goto KEY606;
	local[7]= argv[0];
	local[8]= fqv[26];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[4] = w;
KEY606:
	if (n & (1<<5)) goto KEY607;
	local[5] = fqv[37];
KEY607:
	if (n & (1<<6)) goto KEY608;
	local[6] = makeint(2);
KEY608:
	if (local[0]==NIL) goto IF609;
	local[7]= local[0];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[1] = w;
	local[7]= local[0];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[2] = w;
	local[7]= local[2];
	goto IF610;
IF609:
	local[7]= NIL;
IF610:
	local[7]= loadglobal(fqv[7]);
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= local[4];
	local[13]= local[5];
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(*ftab[16])(ctx,8,local+7,&ftab[16],fqv[38]); /*getimage*/
	local[7]= w;
	local[8]= local[7];
	local[9]= makeint(44);
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= fqv[1];
	ctx->vsp=local+10;
	w=(pointer)PEEK(ctx,2,local+8); /*system:peek*/
	local[8]= w;
	local[9]= makeint(8);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= local[7];
	local[10]= makeint(40);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= fqv[1];
	ctx->vsp=local+11;
	w=(pointer)PEEK(ctx,2,local+9); /*system:peek*/
	local[9]= w;
	local[10]= local[7];
	local[11]= makeint(8);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= fqv[1];
	ctx->vsp=local+12;
	w=(pointer)PEEK(ctx,2,local+10); /*system:peek*/
	local[10]= w;
	local[11]= local[7];
	local[12]= makeint(16);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)PEEK(ctx,2,local+11); /*system:peek*/
	local[11]= w;
	local[12]= local[3];
	local[13]= local[4];
	local[14]= local[8];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,3,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[17])(ctx,1,local+12,&ftab[17],fqv[39]); /*make-string*/
	local[12]= w;
	local[13]= makeint(0);
	local[14]= local[4];
WHL612:
	local[15]= local[13];
	w = local[14];
	if ((integer_t)local[15] >= (integer_t)w) goto WHX613;
	local[15]= local[12];
	local[16]= local[11];
	local[17]= local[13];
	local[18]= local[9];
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(pointer)TIMES(ctx,3,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)PLUS(ctx,2,local+16); /*+*/
	local[16]= w;
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(*ftab[18])(ctx,2,local+16,&ftab[18],fqv[40]); /*make-foreign-string*/
	local[16]= w;
	local[17]= fqv[41];
	local[18]= local[13];
	local[19]= local[3];
	local[20]= local[8];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,3,local+18); /***/
	local[18]= w;
	local[19]= fqv[42];
	local[20]= (pointer)((integer_t)(local[13])+4);
	local[21]= local[3];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,3,local+20); /***/
	local[20]= w;
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,6,local+15,&ftab[19],fqv[43]); /*replace*/
	local[13] = (pointer)((integer_t)(local[13])+4);
	goto WHL612;
WHX613:
	local[15]= NIL;
BLK614:
	w = NIL;
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[20])(ctx,1,local+13,&ftab[20],fqv[44]); /*destroyimage*/
	w = local[12];
	local[0]= w;
BLK601:
	ctx->vsp=local; return(local[0]);}

/*:putimage*/
static pointer M615(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[45], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY617;
	local[0] = NIL;
KEY617:
	if (n & (1<<1)) goto KEY618;
	local[1] = makeint(0);
KEY618:
	if (n & (1<<2)) goto KEY619;
	local[2] = makeint(0);
KEY619:
	if (n & (1<<3)) goto KEY620;
	local[3] = NIL;
KEY620:
	if (n & (1<<4)) goto KEY621;
	local[4] = makeint(0);
KEY621:
	if (n & (1<<5)) goto KEY622;
	local[5] = makeint(0);
KEY622:
	if (n & (1<<6)) goto KEY623;
	local[6] = NIL;
KEY623:
	if (n & (1<<7)) goto KEY624;
	local[7] = NIL;
KEY624:
	if (n & (1<<8)) goto KEY625;
	local[8] = argv[0]->c.obj.iv[3];
KEY625:
	if (n & (1<<9)) goto KEY626;
	local[13]= argv[0];
	local[14]= fqv[46];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[9] = w;
KEY626:
	if (n & (1<<10)) goto KEY627;
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(*ftab[21])(ctx,1,local+13,&ftab[21],fqv[47]); /*visual-depth*/
	local[10] = w;
KEY627:
	if (n & (1<<11)) goto KEY628;
	local[11] = local[10];
KEY628:
	if (n & (1<<12)) goto KEY629;
	local[12] = loadglobal(fqv[48]);
KEY629:
	if (local[0]==NIL) goto IF630;
	local[13]= local[0];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[1] = w;
	local[13]= local[0];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[2] = w;
	local[13]= local[2];
	goto IF631;
IF630:
	local[13]= NIL;
IF631:
	if (local[3]==NIL) goto IF632;
	local[13]= local[3];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[4] = w;
	local[13]= local[3];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[5] = w;
	local[13]= local[5];
	goto IF633;
IF632:
	local[13]= NIL;
IF633:
	local[13]= argv[2];
	local[14]= loadglobal(fqv[49]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto CON635;
	if (local[6]!=NIL) goto IF636;
	local[13]= argv[2];
	local[14]= fqv[25];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[6] = w;
	local[13]= local[6];
	goto IF637;
IF636:
	local[13]= NIL;
IF637:
	if (local[7]!=NIL) goto IF638;
	local[13]= argv[2];
	local[14]= fqv[26];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[7] = w;
	local[13]= local[7];
	goto IF639;
IF638:
	local[13]= NIL;
IF639:
	argv[2] = argv[2]->c.obj.iv[1];
	local[13]= argv[2];
	goto CON634;
CON635:
	if (local[6]!=NIL) goto IF641;
	local[13]= argv[0];
	local[14]= fqv[25];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[6] = w;
	local[13]= local[6];
	goto IF642;
IF641:
	local[13]= NIL;
IF642:
	if (local[7]!=NIL) goto IF643;
	local[13]= argv[0];
	local[14]= fqv[26];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[7] = w;
	local[13]= local[7];
	goto IF644;
IF643:
	local[13]= NIL;
IF644:
	goto CON634;
CON640:
	local[13]= NIL;
CON634:
	local[13]= local[12];
	local[14]= argv[2];
	local[15]= local[6];
	local[16]= local[7];
	local[17]= local[9];
	local[18]= local[10];
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(*ftab[22])(ctx,7,local+13,&ftab[22],fqv[50]); /*set-ximage*/
	local[13]= loadglobal(fqv[7]);
	local[14]= argv[0]->c.obj.iv[2];
	local[15]= local[8]->c.obj.iv[2];
	local[16]= local[12];
	local[17]= local[1];
	local[18]= local[2];
	local[19]= local[4];
	local[20]= local[5];
	local[21]= local[6];
	local[22]= local[7];
	ctx->vsp=local+23;
	w=(*ftab[23])(ctx,10,local+13,&ftab[23],fqv[51]); /*putimage*/
	local[0]= w;
BLK616:
	ctx->vsp=local; return(local[0]);}

/*:putimage8to24*/
static pointer M645(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[52], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY647;
	local[0] = NIL;
KEY647:
	if (n & (1<<1)) goto KEY648;
	local[1] = makeint(0);
KEY648:
	if (n & (1<<2)) goto KEY649;
	local[2] = makeint(0);
KEY649:
	if (n & (1<<3)) goto KEY650;
	local[3] = NIL;
KEY650:
	if (n & (1<<4)) goto KEY651;
	local[4] = makeint(0);
KEY651:
	if (n & (1<<5)) goto KEY652;
	local[5] = makeint(0);
KEY652:
	if (n & (1<<6)) goto KEY653;
	local[12]= argv[0];
	local[13]= fqv[25];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[6] = w;
KEY653:
	if (n & (1<<7)) goto KEY654;
	local[12]= argv[0];
	local[13]= fqv[26];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[7] = w;
KEY654:
	if (n & (1<<8)) goto KEY655;
	local[8] = argv[0]->c.obj.iv[3];
KEY655:
	if (n & (1<<9)) goto KEY656;
	local[9] = NIL;
KEY656:
	if (n & (1<<10)) goto KEY657;
	local[10] = NIL;
KEY657:
	if (n & (1<<11)) goto KEY658;
	local[11] = NIL;
KEY658:
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	if (local[0]==NIL) goto IF659;
	local[15]= local[0];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[1] = w;
	local[15]= local[0];
	local[16]= makeint(1);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[2] = w;
	local[15]= local[2];
	goto IF660;
IF659:
	local[15]= NIL;
IF660:
	if (local[3]==NIL) goto IF661;
	local[15]= local[3];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[4] = w;
	local[15]= local[3];
	local[16]= makeint(1);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[5] = w;
	local[15]= local[5];
	goto IF662;
IF661:
	local[15]= NIL;
IF662:
	local[15]= local[6];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= fqv[53];
	local[17]= fqv[1];
	ctx->vsp=local+18;
	w=(*ftab[24])(ctx,3,local+15,&ftab[24],fqv[54]); /*make-array*/
	local[13] = w;
	local[15]= makeint(0);
	local[16]= local[6];
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
WHL664:
	local[17]= local[15];
	w = local[16];
	if ((integer_t)local[17] >= (integer_t)w) goto WHX665;
	local[17]= argv[2];
	local[18]= local[15];
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[14] = w;
	local[17]= local[13];
	local[18]= local[15];
	local[19]= local[14];
	local[20]= local[14];
	local[21]= makeint(8);
	ctx->vsp=local+22;
	w=(pointer)ASH(ctx,2,local+20); /*ash*/
	local[20]= w;
	local[21]= local[14];
	local[22]= makeint(16);
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LOGIOR(ctx,3,local+19); /*logior*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)ASET(ctx,3,local+17); /*aset*/
	local[15] = (pointer)((integer_t)(local[15])+4);
	goto WHL664;
WHX665:
	local[17]= NIL;
BLK666:
	w = NIL;
	local[15]= loadglobal(fqv[7]);
	local[16]= argv[0]->c.obj.iv[2];
	local[17]= local[8]->c.obj.iv[2];
	local[18]= local[13];
	local[19]= local[1];
	local[20]= local[2];
	local[21]= local[4];
	local[22]= local[5];
	local[23]= local[6];
	local[24]= local[7];
	ctx->vsp=local+25;
	w=(*ftab[23])(ctx,10,local+15,&ftab[23],fqv[51]); /*putimage*/
	local[0]= w;
BLK646:
	ctx->vsp=local; return(local[0]);}

/*:draw-point*/
static pointer M667(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT670;}
	local[0]= argv[0]->c.obj.iv[3];
ENT670:
ENT669:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[55];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK668:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M671(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT674;}
	local[0]= argv[0]->c.obj.iv[3];
ENT674:
ENT673:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= fqv[56];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[3];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK672:
	ctx->vsp=local; return(local[0]);}

/*:draw-string*/
static pointer M675(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT680;}
	local[0]= makeint(0);
ENT680:
	if (n>=6) { local[1]=(argv[5]); goto ENT679;}
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
ENT679:
	if (n>=7) { local[2]=(argv[6]); goto ENT678;}
	local[2]= argv[0]->c.obj.iv[3];
ENT678:
ENT677:
	if (n>7) maerror();
	local[3]= argv[0];
	local[4]= fqv[57];
	local[5]= argv[2];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[3];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	local[0]= w;
BLK676:
	ctx->vsp=local; return(local[0]);}

/*:draw-image-string*/
static pointer M681(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT686;}
	local[0]= makeint(0);
ENT686:
	if (n>=6) { local[1]=(argv[5]); goto ENT685;}
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
ENT685:
	if (n>=7) { local[2]=(argv[6]); goto ENT684;}
	local[2]= argv[0]->c.obj.iv[3];
ENT684:
ENT683:
	if (n>7) maerror();
	local[3]= argv[0];
	local[4]= fqv[58];
	local[5]= argv[2];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[3];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	local[0]= w;
BLK682:
	ctx->vsp=local; return(local[0]);}

/*:draw-rectangle*/
static pointer M687(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT690;}
	local[0]= argv[0]->c.obj.iv[3];
ENT690:
ENT689:
	if (n>6) maerror();
	local[1]= argv[0];
	local[2]= fqv[59];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK688:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-rectangle*/
static pointer M691(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT694;}
	local[0]= argv[0]->c.obj.iv[3];
ENT694:
ENT693:
	if (n>6) maerror();
	local[1]= local[0];
	local[2]= loadglobal(fqv[2]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w!=NIL) goto IF695;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[22];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = argv[0]->c.obj.iv[3];
	local[1]= local[0];
	goto IF696;
IF695:
	local[1]= NIL;
IF696:
	local[1]= argv[0];
	local[2]= fqv[60];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK692:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc*/
static pointer M697(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT703;}
	local[0]= argv[3];
ENT703:
	if (n>=6) { local[1]=(argv[5]); goto ENT702;}
	local[1]= makeflt(0.00000000e+00);
ENT702:
	if (n>=7) { local[2]=(argv[6]); goto ENT701;}
	local[2]= makeflt(6.28318405e+00);
ENT701:
	if (n>=8) { local[3]=(argv[7]); goto ENT700;}
	local[3]= argv[0]->c.obj.iv[3];
ENT700:
ENT699:
	if (n>8) maerror();
	local[4]= argv[0];
	local[5]= fqv[61];
	local[6]= argv[2];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)ROUND(ctx,1,local+9); /*round*/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,9,local+4); /*send*/
	local[0]= w;
BLK698:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc*/
static pointer M704(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT710;}
	local[0]= argv[3];
ENT710:
	if (n>=6) { local[1]=(argv[5]); goto ENT709;}
	local[1]= makeflt(0.00000000e+00);
ENT709:
	if (n>=7) { local[2]=(argv[6]); goto ENT708;}
	local[2]= makeflt(6.28318405e+00);
ENT708:
	if (n>=8) { local[3]=(argv[7]); goto ENT707;}
	local[3]= argv[0]->c.obj.iv[3];
ENT707:
ENT706:
	if (n>8) maerror();
	local[4]= argv[0];
	local[5]= fqv[62];
	local[6]= argv[2];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)ROUND(ctx,1,local+9); /*round*/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,9,local+4); /*send*/
	local[0]= w;
BLK705:
	ctx->vsp=local; return(local[0]);}

/*:drawline-primitive*/
static pointer M711(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[56];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= argv[5];
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK712:
	ctx->vsp=local; return(local[0]);}

/*:set-show-mode*/
static pointer M713(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[63];
	local[2]= fqv[64];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK714:
	ctx->vsp=local; return(local[0]);}

/*:set-erase-mode*/
static pointer M715(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[63];
	local[2]= fqv[65];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK716:
	ctx->vsp=local; return(local[0]);}

/*:set-xor-mode*/
static pointer M717(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[63];
	local[2]= fqv[66];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK718:
	ctx->vsp=local; return(local[0]);}

/*:clear-area*/
static pointer M719(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[67], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY721;
	local[0] = makeint(0);
KEY721:
	if (n & (1<<1)) goto KEY722;
	local[1] = makeint(0);
KEY722:
	if (n & (1<<2)) goto KEY723;
	local[5]= argv[0];
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[2] = w;
KEY723:
	if (n & (1<<3)) goto KEY724;
	local[5]= argv[0];
	local[6]= fqv[26];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[3] = w;
KEY724:
	if (n & (1<<4)) goto KEY725;
	local[4] = argv[0]->c.obj.iv[3];
KEY725:
	local[5]= local[4];
	local[6]= fqv[63];
	local[7]= fqv[65];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[7]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= local[4]->c.obj.iv[2];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[12])(ctx,7,local+5,&ftab[12],fqv[32]); /*fillrectangle*/
	local[5]= local[4];
	local[6]= fqv[63];
	local[7]= fqv[64];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK720:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M726(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[68];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK727:
	ctx->vsp=local; return(local[0]);}

/*:graph*/
static pointer M728(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[69], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY730;
	local[0] = NIL;
KEY730:
	if (n & (1<<1)) goto KEY731;
	local[1] = NIL;
KEY731:
	if (n & (1<<2)) goto KEY732;
	local[2] = NIL;
KEY732:
	if (n & (1<<3)) goto KEY733;
	local[3] = argv[0]->c.obj.iv[3];
KEY733:
	if (n & (1<<4)) goto KEY734;
	local[4] = NIL;
KEY734:
	if (n & (1<<5)) goto KEY735;
	local[5] = NIL;
KEY735:
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	if (local[4]==NIL) goto IF736;
	local[14]= argv[0];
	local[15]= fqv[65];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	goto IF737;
IF736:
	local[14]= NIL;
IF737:
	if (local[1]!=NIL) goto IF738;
	w = argv[2];
	if (iscons(w)) goto IF740;
	local[14]= argv[2];
	local[15]= loadglobal(fqv[70]);
	ctx->vsp=local+16;
	w=(pointer)COERCE(ctx,2,local+14); /*coerce*/
	argv[2] = w;
	local[14]= argv[2];
	goto IF741;
IF740:
	local[14]= NIL;
IF741:
	local[14]= (pointer)get_sym_func(fqv[71]);
	local[15]= argv[2];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,2,local+14); /*apply*/
	local[1] = w;
	local[14]= local[1];
	goto IF739;
IF738:
	local[14]= NIL;
IF739:
	if (local[2]!=NIL) goto IF742;
	w = argv[2];
	if (iscons(w)) goto IF744;
	local[14]= argv[2];
	local[15]= loadglobal(fqv[70]);
	ctx->vsp=local+16;
	w=(pointer)COERCE(ctx,2,local+14); /*coerce*/
	argv[2] = w;
	local[14]= argv[2];
	goto IF745;
IF744:
	local[14]= NIL;
IF745:
	local[14]= (pointer)get_sym_func(fqv[72]);
	local[15]= argv[2];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,2,local+14); /*apply*/
	local[2] = w;
	local[14]= local[2];
	goto IF743;
IF742:
	local[14]= NIL;
IF743:
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)EUSFLOAT(ctx,1,local+14); /*float*/
	local[1] = w;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)EUSFLOAT(ctx,1,local+14); /*float*/
	local[2] = w;
	if (local[0]==NIL) goto IF746;
	local[14]= argv[0];
	local[15]= fqv[22];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	goto IF747;
IF746:
	local[14]= NIL;
IF747:
	local[14]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+15;
	w=(pointer)EUSFLOAT(ctx,1,local+14); /*float*/
	local[14]= w;
	local[15]= local[1];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,2,local+15); /*-*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[13] = w;
	if (local[5]!=NIL) goto IF748;
	local[14]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+15;
	w=(pointer)EUSFLOAT(ctx,1,local+14); /*float*/
	local[14]= w;
	local[15]= (pointer)((integer_t)(local[6])-4);
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[5] = w;
	local[14]= local[5];
	goto IF749;
IF748:
	local[14]= NIL;
IF749:
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,FLET750,env,argv,local);
	local[15]= argv[2];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	w = local[14];
	ctx->vsp=local+16;
	w=FLET750(ctx,1,local+15,w);
	local[11] = w;
	local[15]= makeint(0);
	local[16]= (pointer)((integer_t)(local[6])-4);
WHL752:
	local[17]= local[15];
	w = local[16];
	if ((integer_t)local[17] >= (integer_t)w) goto WHX753;
	local[17]= (pointer)((integer_t)(local[15])+4);
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)ROUND(ctx,1,local+17); /*round*/
	local[10] = w;
	local[17]= argv[2];
	local[18]= (pointer)((integer_t)(local[15])+4);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	w = local[14];
	ctx->vsp=local+18;
	w=FLET750(ctx,1,local+17,w);
	local[12] = w;
	local[17]= argv[0];
	local[18]= fqv[56];
	local[19]= local[9];
	local[20]= local[11];
	local[21]= local[10];
	local[22]= local[12];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,7,local+17); /*send*/
	local[9] = local[10];
	local[11] = local[12];
	local[15] = (pointer)((integer_t)(local[15])+4);
	goto WHL752;
WHX753:
	local[17]= NIL;
BLK754:
	w = NIL;
	local[0]= w;
BLK729:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET750(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[6];
	local[1]= env->c.clo.env2[13];
	local[2]= argv[0];
	local[3]= env->c.clo.env2[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:3d-fill-rectangle*/
static pointer M755(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<11) maerror();
	if (n>=12) { local[0]=(argv[11]); goto ENT758;}
	local[0]= fqv[73];
ENT758:
ENT757:
	if (n>12) maerror();
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[22];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[4];
	if (fqv[74]!=local[5]) goto IF760;
	local[2] = argv[7];
	local[3] = argv[8];
	local[5]= local[3];
	goto IF761;
IF760:
	local[5]= local[4];
	if (fqv[75]!=local[5]) goto IF762;
	local[2] = argv[8];
	local[3] = argv[7];
	local[5]= local[3];
	goto IF763;
IF762:
	if (T==NIL) goto IF764;
	local[2] = argv[9];
	local[3] = argv[9];
	local[5]= local[3];
	goto IF765;
IF764:
	local[5]= NIL;
IF765:
IF763:
IF761:
	w = local[5];
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[22];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[60];
	local[6]= argv[2];
	local[7]= argv[3];
	local[8]= argv[4];
	local[9]= argv[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[22];
	local[6]= argv[9];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[60];
	local[6]= argv[2];
	local[7]= argv[6];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= argv[3];
	local[8]= argv[6];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= argv[4];
	local[9]= argv[6];
	local[10]= argv[6];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,3,local+8); /*-*/
	local[8]= w;
	local[9]= argv[5];
	local[10]= argv[6];
	local[11]= argv[6];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,3,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[22];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[10];
	local[7]= makeint(1);
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[22];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK756:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M766(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[77], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY768;
	local[0] = makeint(256);
KEY768:
	if (n & (1<<1)) goto KEY769;
	local[1] = local[0];
KEY769:
	if (n & (1<<2)) goto KEY770;
	local[2] = local[1];
KEY770:
	if (n & (1<<3)) goto KEY771;
	local[5]= loadglobal(fqv[7]);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,2,local+5,&ftab[25],fqv[78]); /*defaultdepth*/
	local[3] = w;
KEY771:
	if (n & (1<<4)) goto KEY772;
	local[4] = loadglobal(fqv[79]);
KEY772:
	local[5]= loadglobal(fqv[7]);
	local[6]= loadglobal(fqv[7]);
	ctx->vsp=local+7;
	w=(*ftab[26])(ctx,1,local+6,&ftab[26],fqv[80]); /*defaultrootwindow*/
	local[6]= w;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[27])(ctx,5,local+5,&ftab[27],fqv[81]); /*createpixmap*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0];
	local[6]= fqv[82];
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,6,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK767:
	ctx->vsp=local; return(local[0]);}

/*:create-from-bitmap-file*/
static pointer M773(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[83]));
	local[2]= fqv[82];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= loadglobal(fqv[10]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= loadglobal(fqv[10]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= loadglobal(fqv[9]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= loadglobal(fqv[10]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= loadglobal(fqv[10]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= loadglobal(fqv[7]);
	local[6]= loadglobal(fqv[7]);
	ctx->vsp=local+7;
	w=(*ftab[26])(ctx,1,local+6,&ftab[26],fqv[80]); /*defaultrootwindow*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,8,local+5,&ftab[28],fqv[84]); /*readbitmapfile*/
	local[5]= loadglobal(fqv[7]);
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,1,local+5,&ftab[1],fqv[8]); /*flush*/
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,1,local+5,&ftab[3],fqv[9]); /*c-long*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0];
	local[0]= w;
BLK774:
	ctx->vsp=local; return(local[0]);}

/*:write-to-bitmap-file*/
static pointer M775(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(*ftab[29])(ctx,7,local+0,&ftab[29],fqv[85]); /*writebitmapfile*/
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= w;
BLK776:
	ctx->vsp=local; return(local[0]);}

/*:destroy*/
static pointer M777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[86]); /*freepixmap*/
	argv[0]->c.obj.iv[2] = NIL;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK778:
	ctx->vsp=local; return(local[0]);}

/*make-pixmaps*/
static pointer F397(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[87], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY780;
	local[0] = makeint(500);
KEY780:
	if (n & (1<<1)) goto KEY781;
	local[1] = local[0];
KEY781:
	if (n & (1<<2)) goto KEY782;
	local[2] = local[1];
KEY782:
	if (n & (1<<3)) goto KEY783;
	local[3] = loadglobal(fqv[88]);
KEY783:
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= argv[0];
WHL785:
	local[7]= local[5];
	w = local[6];
	if ((integer_t)local[7] >= (integer_t)w) goto WHX786;
	local[7]= loadglobal(fqv[89]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[3];
	local[10]= fqv[25];
	local[11]= local[1];
	local[12]= fqv[26];
	local[13]= local[2];
	local[14]= fqv[19];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,8,local+8); /*send*/
	w = local[7];
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[19];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[5] = (pointer)((integer_t)(local[5])+4);
	goto WHL785;
WHX786:
	local[7]= NIL;
BLK787:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK779:
	ctx->vsp=local; return(local[0]);}

/*make-gray-pixmap*/
static pointer F398(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[90], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY790;
	local[0] = loadglobal(fqv[91]);
KEY790:
	if (n & (1<<1)) goto KEY791;
	local[1] = loadglobal(fqv[92]);
KEY791:
	if (n & (1<<2)) goto KEY792;
	local[3]= loadglobal(fqv[7]);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[25])(ctx,2,local+3,&ftab[25],fqv[78]); /*defaultdepth*/
	local[2] = w;
KEY792:
	local[3]= argv[0];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FLOOR(ctx,1,local+3); /*floor*/
	local[3]= w;
	local[4]= loadglobal(fqv[93]);
	local[5]= makeint(32);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= local[3];
WHL794:
	local[8]= local[6];
	w = local[7];
	if ((integer_t)local[8] >= (integer_t)w) goto WHX795;
	local[8]= local[4];
	local[9]= fqv[94];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[6] = (pointer)((integer_t)(local[6])+4);
	goto WHL794;
WHX795:
	local[8]= NIL;
BLK796:
	w = NIL;
	local[6]= loadglobal(fqv[89]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[3];
	local[9]= fqv[25];
	local[10]= makeint(8);
	local[11]= fqv[26];
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	w = local[6];
	local[5] = w;
	local[6]= loadglobal(fqv[7]);
	local[7]= loadglobal(fqv[95]);
	local[8]= fqv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[4];
	local[9]= makeint(8);
	local[10]= makeint(4);
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(*ftab[31])(ctx,8,local+6,&ftab[31],fqv[96]); /*createpixmapfrombitmapdata*/
	local[4] = w;
	local[6]= local[4];
	local[7]= local[6];
	w = local[5];
	w->c.obj.iv[2] = local[7];
	w = local[5];
	local[0]= w;
BLK789:
	ctx->vsp=local; return(local[0]);}

/*make-gray-gc*/
static pointer F399(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[97], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY799;
	local[0] = loadglobal(fqv[91]);
KEY799:
	if (n & (1<<1)) goto KEY800;
	local[1] = loadglobal(fqv[92]);
KEY800:
	if (n & (1<<2)) goto KEY801;
	local[3]= loadglobal(fqv[7]);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[25])(ctx,2,local+3,&ftab[25],fqv[78]); /*defaultdepth*/
	local[2] = w;
KEY801:
	local[3]= argv[0];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FLOOR(ctx,1,local+3); /*floor*/
	local[3]= w;
	local[4]= loadglobal(fqv[93]);
	local[5]= makeint(32);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= loadglobal(fqv[2]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	w = local[7];
	local[6] = w;
	local[7]= local[6];
	local[8]= fqv[98];
	local[9]= fqv[99];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[22];
	local[9]= local[0];
	local[10]= fqv[100];
	local[11]= local[1];
	local[12]= fqv[101];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F398(ctx,7,local+7); /*make-gray-pixmap*/
	local[5] = w;
	local[7]= local[6];
	local[8]= fqv[102];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	w = local[6];
	local[0]= w;
BLK798:
	ctx->vsp=local; return(local[0]);}

/*make-cleared-pixmap*/
static pointer F400(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT806;}
	local[0]= argv[0];
ENT806:
	if (n>=3) { local[1]=(argv[2]); goto ENT805;}
	local[1]= loadglobal(fqv[92]);
ENT805:
ENT804:
	if (n>3) maerror();
	local[2]= loadglobal(fqv[89]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[3];
	local[5]= fqv[25];
	local[6]= argv[0];
	local[7]= fqv[26];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	local[4]= local[2];
	local[5]= fqv[19];
	local[6]= fqv[22];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[19];
	local[6]= fqv[22];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= local[2];
	local[5]= fqv[60];
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[0];
	local[9]= local[0];
	local[10]= local[2];
	local[11]= fqv[19];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,7,local+4); /*send*/
	local[4]= local[2];
	local[5]= fqv[19];
	local[6]= fqv[22];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[2];
	local[0]= w;
BLK803:
	ctx->vsp=local; return(local[0]);}

/*eventmask-to-value*/
static pointer F401(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto CON810;
	local[0]= argv[0];
	goto CON809;
CON810:
	local[0]= makeint(0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
WHL813:
	if (local[3]==NIL) goto WHX814;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[103];
	ctx->vsp=local+6;
	w=(*ftab[32])(ctx,2,local+4,&ftab[32],fqv[104]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	if (local[1]==NIL) goto IF817;
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LOGIOR(ctx,2,local+4); /*logior*/
	local[0] = w;
	local[4]= local[0];
	goto IF818;
IF817:
	local[4]= fqv[105];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[33])(ctx,2,local+4,&ftab[33],fqv[106]); /*warn*/
	local[4]= w;
IF818:
	goto WHL813;
WHX814:
	local[4]= NIL;
BLK815:
	w = NIL;
	w = local[0];
	local[0]= w;
	goto CON809;
CON811:
	local[0]= NIL;
CON809:
	w = local[0];
	local[0]= w;
BLK808:
	ctx->vsp=local; return(local[0]);}

/*gravity-to-value*/
static pointer F402(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF820;
	local[0]= argv[0];
	local[1]= fqv[107];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[104]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[0]= argv[0];
	goto IF821;
IF820:
	local[0]= NIL;
IF821:
	w = argv[0];
	if (isint(w)) goto IF822;
	local[0]= fqv[108];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF823;
IF822:
	local[0]= NIL;
IF823:
	w = argv[0];
	local[0]= w;
BLK819:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M824(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[109], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY826;
	local[0] = loadglobal(fqv[95]);
KEY826:
	if (n & (1<<1)) goto KEY827;
	local[1] = makeint(0);
KEY827:
	if (n & (1<<2)) goto KEY828;
	local[2] = makeint(0);
KEY828:
	if (n & (1<<3)) goto KEY829;
	local[3] = makeint(256);
KEY829:
	if (n & (1<<4)) goto KEY830;
	local[4] = local[3];
KEY830:
	if (n & (1<<5)) goto KEY831;
	local[5] = local[4];
KEY831:
	if (n & (1<<6)) goto KEY832;
	local[6] = makeint(2);
KEY832:
	if (n & (1<<7)) goto KEY833;
	local[7] = loadglobal(fqv[91]);
KEY833:
	if (n & (1<<8)) goto KEY834;
	local[8] = NIL;
KEY834:
	if (n & (1<<9)) goto KEY835;
	local[9] = fqv[110];
KEY835:
	if (n & (1<<10)) goto KEY836;
	local[10] = NIL;
KEY836:
	if (n & (1<<11)) goto KEY837;
	local[11] = NIL;
KEY837:
	if (n & (1<<12)) goto KEY838;
	local[12] = NIL;
KEY838:
	if (n & (1<<13)) goto KEY839;
	local[24]= fqv[111];
	ctx->vsp=local+25;
	w=(pointer)GENSYM(ctx,1,local+24); /*gensym*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(*ftab[34])(ctx,1,local+24,&ftab[34],fqv[112]); /*string*/
	local[13] = w;
KEY839:
	if (n & (1<<14)) goto KEY840;
	local[14] = makeint(139279);
KEY840:
	if (n & (1<<15)) goto KEY841;
	local[15] = NIL;
KEY841:
	if (n & (1<<16)) goto KEY842;
	local[16] = NIL;
KEY842:
	if (n & (1<<17)) goto KEY843;
	local[17] = NIL;
KEY843:
	if (n & (1<<18)) goto KEY844;
	local[18] = T;
KEY844:
	if (n & (1<<19)) goto KEY845;
	local[19] = loadglobal(fqv[113]);
KEY845:
	if (n & (1<<20)) goto KEY846;
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(*ftab[21])(ctx,1,local+24,&ftab[21],fqv[47]); /*visual-depth*/
	local[20] = w;
KEY846:
	if (n & (1<<21)) goto KEY847;
	local[21] = NIL;
KEY847:
	if (n & (1<<22)) goto KEY848;
	local[22] = NIL;
KEY848:
	if (n & (1<<23)) goto KEY849;
	local[23] = fqv[114];
KEY849:
	if (local[0]!=NIL) goto IF850;
	local[0] = loadglobal(fqv[95]);
	local[24]= local[0];
	goto IF851;
IF850:
	local[24]= NIL;
IF851:
	argv[0]->c.obj.iv[7] = local[0];
	argv[0]->c.obj.iv[9] = local[19];
	w = local[8];
	if (!isnum(w)) goto CON853;
	local[24]= local[8];
	goto CON852;
CON853:
	local[24]= local[8];
	if (T!=local[24]) goto CON854;
	local[24]= makeint(1);
	goto CON852;
CON854:
	if (loadglobal(fqv[115])==NIL) goto CON855;
	local[24]= makeint(1);
	goto CON852;
CON855:
	local[24]= makeint(0);
	goto CON852;
CON856:
	local[24]= NIL;
CON852:
	local[8] = local[24];
	w = local[9];
	if (!isnum(w)) goto CON858;
	local[24]= local[9];
	goto CON857;
CON858:
	if (loadglobal(fqv[115])!=NIL) goto CON859;
	local[24]= makeint(0);
	goto CON857;
CON859:
	local[24]= local[9];
	local[25]= fqv[116];
	ctx->vsp=local+26;
	w=(*ftab[32])(ctx,2,local+24,&ftab[32],fqv[104]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	goto CON857;
CON860:
	local[24]= NIL;
CON857:
	local[9] = local[24];
	local[24]= local[14];
	ctx->vsp=local+25;
	w=(pointer)F401(ctx,1,local+24); /*eventmask-to-value*/
	local[14] = w;
	local[24]= local[8];
	local[25]= makeint(0);
	ctx->vsp=local+26;
	w=(pointer)NUMEQUAL(ctx,2,local+24); /*=*/
	if (w==NIL) goto IF861;
	local[24]= local[14];
	local[25]= fqv[117];
	ctx->vsp=local+26;
	w=(pointer)F401(ctx,1,local+25); /*eventmask-to-value*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)LOGIOR(ctx,2,local+24); /*logior*/
	local[14] = w;
	local[24]= local[14];
	goto IF862;
IF861:
	local[24]= NIL;
IF862:
	local[24]= loadglobal(fqv[118]);
	local[25]= local[8];
	ctx->vsp=local+26;
	w=(pointer)F340(ctx,2,local+24); /*set-setwindowattributes-save_under*/
	local[24]= loadglobal(fqv[118]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(pointer)F334(ctx,2,local+24); /*set-setwindowattributes-backing_store*/
	local[24]= loadglobal(fqv[118]);
	local[25]= local[7];
	ctx->vsp=local+26;
	w=(pointer)F328(ctx,2,local+24); /*set-setwindowattributes-border_pixel*/
	local[24]= loadglobal(fqv[118]);
	local[25]= makeint(-1);
	ctx->vsp=local+26;
	w=(pointer)F336(ctx,2,local+24); /*set-setwindowattributes-backing_planes*/
	local[24]= loadglobal(fqv[118]);
	local[25]= makeint(0);
	ctx->vsp=local+26;
	w=(pointer)F338(ctx,2,local+24); /*set-setwindowattributes-backing_pixel*/
	local[24]= loadglobal(fqv[118]);
	local[25]= local[14];
	ctx->vsp=local+26;
	w=(pointer)F342(ctx,2,local+24); /*set-setwindowattributes-event_mask*/
	local[24]= loadglobal(fqv[118]);
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)F402(ctx,1,local+25); /*gravity-to-value*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)F332(ctx,2,local+24); /*set-setwindowattributes-win_gravity*/
	if (local[21]!=NIL) goto IF863;
	local[24]= local[19];
	local[25]= loadglobal(fqv[113]);
	ctx->vsp=local+26;
	w=(pointer)NUMEQUAL(ctx,2,local+24); /*=*/
	if (w==NIL) goto CON866;
	local[24]= argv[0]->c.obj.iv[7];
	local[25]= fqv[119];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[21] = w;
	local[24]= local[21];
	local[25]= loadglobal(fqv[120]);
	ctx->vsp=local+26;
	w=(pointer)DERIVEDP(ctx,2,local+24); /*derivedp*/
	if (w!=NIL) goto IF867;
	local[24]= makeint(2);
	local[25]= fqv[121];
	local[26]= argv[0];
	local[27]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+28;
	w=(*ftab[35])(ctx,4,local+24,&ftab[35],fqv[122]); /*warning-message*/
	local[21] = loadglobal(fqv[123]);
	local[24]= local[21];
	goto IF868;
IF867:
	local[24]= NIL;
IF868:
	goto CON865;
CON866:
	local[24]= loadglobal(fqv[120]);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,1,local+24); /*instantiate*/
	local[24]= w;
	local[25]= local[24];
	local[26]= fqv[3];
	local[27]= fqv[46];
	local[28]= local[19];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,4,local+25); /*send*/
	w = local[24];
	local[21] = w;
	local[24]= local[21];
	local[25]= fqv[124];
	local[26]= loadglobal(fqv[123]);
	local[27]= makeint(0);
	local[28]= makeint(32);
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,5,local+24); /*send*/
	local[24]= w;
	goto CON865;
CON869:
	local[24]= NIL;
CON865:
	goto IF864;
IF863:
	local[24]= NIL;
IF864:
	local[24]= loadglobal(fqv[118]);
	local[25]= local[21];
	local[26]= fqv[125];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,2,local+25); /*send*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)F348(ctx,2,local+24); /*set-setwindowattributes-colormap*/
	local[24]= loadglobal(fqv[118]);
	if (local[22]==NIL) goto IF871;
	local[25]= makeint(1);
	goto IF872;
IF871:
	local[25]= makeint(0);
IF872:
	ctx->vsp=local+26;
	w=(pointer)F346(ctx,2,local+24); /*set-setwindowattributes-override_redirect*/
	local[24]= loadglobal(fqv[7]);
	local[25]= argv[0]->c.obj.iv[7];
	local[26]= fqv[4];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,2,local+25); /*send*/
	local[25]= w;
	local[26]= local[1];
	local[27]= local[2];
	local[28]= local[4];
	local[29]= local[5];
	local[30]= local[6];
	local[31]= local[20];
	local[32]= makeint(0);
	local[33]= local[19];
	local[34]= makeint(12264);
	local[35]= loadglobal(fqv[118]);
	ctx->vsp=local+36;
	w=(*ftab[36])(ctx,12,local+24,&ftab[36],fqv[126]); /*createwindow*/
	argv[0]->c.obj.iv[2] = w;
	local[24]= loadglobal(fqv[7]);
	local[25]= argv[0]->c.obj.iv[2];
	local[26]= local[13];
	ctx->vsp=local+27;
	w=(*ftab[37])(ctx,3,local+24,&ftab[37],fqv[127]); /*storename*/
	local[24]= argv[0];
	local[25]= fqv[82];
	local[26]= argv[0]->c.obj.iv[2];
	local[27]= local[4];
	local[28]= local[5];
	local[29]= local[15];
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,6,local+24); /*send*/
	local[24]= local[12];
	if (local[12]!=NIL) goto IF873;
	if (argv[0]->c.obj.iv[7]==NIL) goto IF875;
	local[25]= argv[0]->c.obj.iv[7];
	local[26]= loadglobal(fqv[95]);
	ctx->vsp=local+27;
	w=(pointer)EQ(ctx,2,local+25); /*eql*/
	if (w!=NIL) goto IF875;
	local[25]= argv[0]->c.obj.iv[7];
	local[26]= fqv[19];
	local[27]= fqv[100];
	local[28]= NIL;
	local[29]= local[21];
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,5,local+25); /*send*/
	local[25]= w;
	goto IF876;
IF875:
	local[25]= loadglobal(fqv[92]);
IF876:
	local[12] = local[25];
	local[25]= local[12];
	goto IF874;
IF873:
	local[25]= NIL;
IF874:
	local[25]= local[21];
	local[26]= fqv[128];
	local[27]= local[12];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[12] = w;
	w = local[12];
	if (isnum(w)) goto IF877;
	local[25]= fqv[129];
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(*ftab[33])(ctx,2,local+25,&ftab[33],fqv[106]); /*warn*/
	local[12] = loadglobal(fqv[92]);
	local[25]= local[12];
	goto IF878;
IF877:
	local[25]= NIL;
IF878:
	w = local[25];
	local[24]= argv[0]->c.obj.iv[3];
	local[25]= fqv[22];
	local[26]= local[11];
	if (local[26]!=NIL) goto CON879;
CON880:
	if (argv[0]->c.obj.iv[7]==NIL) goto CON881;
	local[26]= argv[0]->c.obj.iv[7];
	local[27]= fqv[22];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	goto CON879;
CON881:
	local[26]= loadglobal(fqv[91]);
	goto CON879;
CON882:
	local[26]= NIL;
CON879:
	local[27]= local[21];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,4,local+24); /*send*/
	argv[0]->c.obj.iv[4] = local[12];
	local[24]= loadglobal(fqv[7]);
	local[25]= argv[0]->c.obj.iv[2];
	local[26]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+27;
	w=(*ftab[38])(ctx,3,local+24,&ftab[38],fqv[130]); /*setwindowbackground*/
	if (local[10]==NIL) goto IF883;
	local[24]= loadglobal(fqv[89]);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,1,local+24); /*instantiate*/
	local[24]= w;
	local[25]= local[24];
	local[26]= fqv[3];
	local[27]= fqv[25];
	local[28]= local[4];
	local[29]= fqv[26];
	local[30]= local[5];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,6,local+25); /*send*/
	w = local[24];
	argv[0]->c.obj.iv[10] = w;
	local[24]= argv[0]->c.obj.iv[10];
	goto IF884;
IF883:
	local[24]= NIL;
IF884:
	local[24]= loadglobal(fqv[7]);
	local[25]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+26;
	w=(*ftab[39])(ctx,2,local+24,&ftab[39],fqv[131]); /*clearwindow*/
	if (local[18]==NIL) goto IF886;
	local[24]= loadglobal(fqv[7]);
	local[25]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,2,local+24,&ftab[40],fqv[132]); /*mapwindow*/
	local[24]= w;
	goto IF887;
IF886:
	local[24]= NIL;
IF887:
	if (argv[0]->c.obj.iv[7]==NIL) goto IF888;
	local[24]= argv[0]->c.obj.iv[7];
	local[25]= fqv[133];
	local[26]= argv[0];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
	goto IF889;
IF888:
	local[24]= NIL;
IF889:
	local[24]= argv[0];
	w = loadglobal(fqv[134]);
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	storeglobal(fqv[134],local[24]);
	if (local[16]==NIL) goto CON891;
	local[24]= argv[0]->c.obj.iv[3];
	local[25]= fqv[135];
	local[26]= local[16];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
	goto CON890;
CON891:
	if (argv[0]->c.obj.iv[7]==NIL) goto CON892;
	local[24]= argv[0]->c.obj.iv[3];
	local[25]= fqv[135];
	local[26]= argv[0]->c.obj.iv[7];
	local[27]= fqv[19];
	local[28]= fqv[135];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,3,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
	goto CON890;
CON892:
	local[24]= NIL;
CON890:
	if (local[17]==NIL) goto IF893;
	local[24]= argv[0];
	local[25]= fqv[136];
	local[26]= local[17];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
	goto IF894;
IF893:
	local[24]= argv[0];
	local[25]= fqv[136];
	local[26]= local[13];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
IF894:
	local[24]= argv[0]->c.obj.iv[3];
	local[25]= fqv[100];
	local[26]= argv[0]->c.obj.iv[4];
	local[27]= local[21];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,4,local+24); /*send*/
	local[24]= loadglobal(fqv[7]);
	ctx->vsp=local+25;
	w=(*ftab[1])(ctx,1,local+24,&ftab[1],fqv[8]); /*flush*/
	w = argv[0];
	local[0]= w;
BLK825:
	ctx->vsp=local; return(local[0]);}

/*:subwindows*/
static pointer M895(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT898;}
	local[0]= NIL;
ENT898:
ENT897:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF899;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	local[1]= w;
	goto IF900;
IF899:
	local[1]= argv[0]->c.obj.iv[8];
IF900:
	w = local[1];
	local[0]= w;
BLK896:
	ctx->vsp=local; return(local[0]);}

/*:map*/
static pointer M901(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[137];
	ctx->vsp=local+2;
	w=(*ftab[41])(ctx,2,local+0,&ftab[41],fqv[138]); /*send-all*/
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[132]); /*mapwindow*/
	local[0]= w;
BLK902:
	ctx->vsp=local; return(local[0]);}

/*:unmap*/
static pointer M903(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[139];
	ctx->vsp=local+2;
	w=(*ftab[41])(ctx,2,local+0,&ftab[41],fqv[138]); /*send-all*/
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[140]); /*unmapwindow*/
	local[0]= w;
BLK904:
	ctx->vsp=local; return(local[0]);}

/*:remap*/
static pointer M905(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[139];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= argv[0];
	local[1]= fqv[137];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= w;
BLK906:
	ctx->vsp=local; return(local[0]);}

/*:parent*/
static pointer M907(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK908:
	ctx->vsp=local; return(local[0]);}

/*:associate*/
static pointer M909(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[141];
	local[3]= NIL;
	local[4]= fqv[142];
	local[5]= NIL;
	local[6]= fqv[143];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(*ftab[43])(ctx,8,local+0,&ftab[43],fqv[144]); /*member*/
	if (w!=NIL) goto IF911;
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[8] = cons(ctx,local[0],w);
	local[0]= argv[0]->c.obj.iv[8];
	goto IF912;
IF911:
	local[0]= NIL;
IF912:
	w = NIL;
	local[0]= w;
BLK910:
	ctx->vsp=local; return(local[0]);}

/*:dissociate*/
static pointer M913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[44])(ctx,2,local+0,&ftab[44],fqv[145]); /*delete*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK914:
	ctx->vsp=local; return(local[0]);}

/*:reparent*/
static pointer M915(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT919;}
	local[0]= makeint(0);
ENT919:
	if (n>=5) { local[1]=(argv[4]); goto ENT918;}
	local[1]= makeint(0);
ENT918:
ENT917:
	if (n>5) maerror();
	w = argv[2];
	if (isint(w)) goto IF920;
	local[2]= argv[2];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	argv[2] = w;
	local[2]= argv[2];
	goto IF921;
IF920:
	local[2]= NIL;
IF921:
	local[2]= loadglobal(fqv[7]);
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[45])(ctx,5,local+2,&ftab[45],fqv[146]); /*reparentwindow*/
	argv[0]->c.obj.iv[7] = argv[2];
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK916:
	ctx->vsp=local; return(local[0]);}

/*:destroy*/
static pointer M922(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(*ftab[41])(ctx,2,local+0,&ftab[41],fqv[138]); /*send-all*/
	if (argv[0]->c.obj.iv[2]==NIL) goto IF924;
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	argv[0]->c.obj.iv[2] = NIL;
	w = local[1];
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[46])(ctx,2,local+0,&ftab[46],fqv[148]); /*destroywindow*/
	local[0]= w;
	goto IF925;
IF924:
	local[0]= NIL;
IF925:
	if (argv[0]->c.obj.iv[7]==NIL) goto IF927;
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= fqv[149];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= argv[0]->c.obj.iv[7];
	goto IF928;
IF927:
	local[0]= NIL;
IF928:
	local[0]= argv[0];
	local[1]= loadglobal(fqv[134]);
	ctx->vsp=local+2;
	w=(*ftab[44])(ctx,2,local+0,&ftab[44],fqv[145]); /*delete*/
	local[0]= w;
	storeglobal(fqv[134],w);
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(*ftab[47])(ctx,2,local+0,&ftab[47],fqv[150]); /*remhash*/
	local[0]= w;
BLK923:
	ctx->vsp=local; return(local[0]);}

/*:attributes*/
static pointer M929(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= loadglobal(fqv[151]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[1] = w;
	local[2]= loadglobal(fqv[7]);
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,3,local+2,&ftab[5],fqv[14]); /*getwindowattributes*/
	w = local[1];
	local[0]= w;
BLK930:
	ctx->vsp=local; return(local[0]);}

/*:event-mask*/
static pointer M931(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[152];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[15];
	local[2]= fqv[153];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK932:
	ctx->vsp=local; return(local[0]);}

/*:selectinput*/
static pointer M933(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F401(ctx,1,local+2); /*eventmask-to-value*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[48])(ctx,3,local+0,&ftab[48],fqv[154]); /*selectinput*/
	local[0]= w;
BLK934:
	ctx->vsp=local; return(local[0]);}

/*:visual*/
static pointer M935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[9]==NIL) goto IF937;
	local[0]= argv[0]->c.obj.iv[9];
	goto IF938;
IF937:
	local[0]= argv[0];
	local[1]= fqv[152];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[15];
	local[2]= fqv[155];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF938:
	w = local[0];
	local[0]= w;
BLK936:
	ctx->vsp=local; return(local[0]);}

/*:location*/
static pointer M939(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[152];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[15];
	local[4]= fqv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[15];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKINTVECTOR(ctx,2,local+2); /*integer-vector*/
	local[0]= w;
BLK940:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M941(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[152];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[15];
	local[4]= fqv[156];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[15];
	local[5]= fqv[157];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKINTVECTOR(ctx,2,local+2); /*integer-vector*/
	local[0]= w;
BLK942:
	ctx->vsp=local; return(local[0]);}

/*:depth*/
static pointer M943(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[152];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[15];
	local[2]= fqv[158];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK944:
	ctx->vsp=local; return(local[0]);}

/*:screen*/
static pointer M945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[152];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[15];
	local[2]= fqv[159];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK946:
	ctx->vsp=local; return(local[0]);}

/*:colormap*/
static pointer M947(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[152];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[15];
	local[2]= fqv[120];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(*ftab[49])(ctx,2,local+0,&ftab[49],fqv[160]); /*gethash*/
	local[0]= w;
BLK948:
	ctx->vsp=local; return(local[0]);}

/*:root*/
static pointer M949(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[152];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[15];
	local[2]= fqv[161];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK950:
	ctx->vsp=local; return(local[0]);}

/*:title*/
static pointer M951(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[37])(ctx,3,local+0,&ftab[37],fqv[127]); /*storename*/
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= w;
BLK952:
	ctx->vsp=local; return(local[0]);}

/*:background*/
static pointer M953(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT956;}
	local[0]= NIL;
ENT956:
ENT955:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF957;
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[38])(ctx,3,local+1,&ftab[38],fqv[130]); /*setwindowbackground*/
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0];
	local[2]= fqv[65];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF958;
IF957:
	local[1]= NIL;
IF958:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK954:
	ctx->vsp=local; return(local[0]);}

/*:background-pixmap*/
static pointer M959(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[50])(ctx,3,local+0,&ftab[50],fqv[162]); /*setwindowbackgroundpixmap*/
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK960:
	ctx->vsp=local; return(local[0]);}

/*:border*/
static pointer M961(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[51])(ctx,3,local+0,&ftab[51],fqv[163]); /*setwindowborder*/
	local[0]= w;
BLK962:
	ctx->vsp=local; return(local[0]);}

/*:save*/
static pointer M963(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[164];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= w;
BLK964:
	ctx->vsp=local; return(local[0]);}

/*:refresh*/
static pointer M965(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[83]));
	local[2]= fqv[164];
	local[3]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= loadglobal(fqv[7]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*flush*/
	local[0]= w;
BLK966:
	ctx->vsp=local; return(local[0]);}

/*:move*/
static pointer M967(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(*ftab[52])(ctx,4,local+0,&ftab[52],fqv[165]); /*movewindow*/
	local[0]= w;
BLK968:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M969(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(*ftab[53])(ctx,4,local+0,&ftab[53],fqv[166]); /*resizewindow*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK970:
	ctx->vsp=local; return(local[0]);}

/*:raise*/
static pointer M971(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[54])(ctx,2,local+0,&ftab[54],fqv[167]); /*raisewindow*/
	local[0]= w;
BLK972:
	ctx->vsp=local; return(local[0]);}

/*:lower*/
static pointer M973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[55])(ctx,2,local+0,&ftab[55],fqv[168]); /*lowerwindow*/
	local[0]= w;
BLK974:
	ctx->vsp=local; return(local[0]);}

/*:write-to-bitmap-file*/
static pointer M975(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[169];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK976:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M977(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[39])(ctx,2,local+0,&ftab[39],fqv[131]); /*clearwindow*/
	local[0]= w;
BLK978:
	ctx->vsp=local; return(local[0]);}

/*:clear-area*/
static pointer M979(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[170], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY981;
	local[0] = makeint(0);
KEY981:
	if (n & (1<<1)) goto KEY982;
	local[1] = makeint(0);
KEY982:
	if (n & (1<<2)) goto KEY983;
	local[2] = makeint(0);
KEY983:
	if (n & (1<<3)) goto KEY984;
	local[3] = makeint(0);
KEY984:
	local[4]= loadglobal(fqv[7]);
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(*ftab[56])(ctx,7,local+4,&ftab[56],fqv[171]); /*cleararea*/
	local[0]= w;
BLK980:
	ctx->vsp=local; return(local[0]);}

/*:set-colormap*/
static pointer M985(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= *(ovafptr(argv[2],fqv[172]));
	ctx->vsp=local+3;
	w=(*ftab[57])(ctx,3,local+0,&ftab[57],fqv[173]); /*setwindowcolormap*/
	local[0]= w;
BLK986:
	ctx->vsp=local; return(local[0]);}

/*:copy*/
static pointer M987(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST989:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[18]);
	local[3]= local[1];
	local[4]= fqv[3];
	local[5]= fqv[25];
	local[6]= argv[0];
	local[7]= fqv[25];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[26];
	local[8]= argv[0];
	local[9]= fqv[26];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,8,local+2); /*apply*/
	w = local[1];
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[164];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK988:
	ctx->vsp=local; return(local[0]);}

/*geometry::default-viewsurface*/
static pointer F403(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST992:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[18]);
	local[2]= loadglobal(fqv[174]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK991:
	ctx->vsp=local; return(local[0]);}

/*:draw-lines*/
static pointer M993(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT997;}
	local[0]= makeint(0);
ENT997:
	if (n>=5) { local[1]=(argv[4]); goto ENT996;}
	local[1]= argv[0]->c.obj.iv[3];
ENT996:
ENT995:
	if (n>5) maerror();
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= loadglobal(fqv[112]);
	local[4]= local[2];
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[175];
	local[6]= argv[2];
	local[7]= makeint(0);
	local[8]= fqv[176];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= loadglobal(fqv[7]);
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[1]->c.obj.iv[2];
	local[7]= local[3];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[58])(ctx,6,local+4,&ftab[58],fqv[177]); /*drawlines*/
	local[0]= w;
BLK994:
	ctx->vsp=local; return(local[0]);}

/*:draw-polygon*/
static pointer M998(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1001;}
	local[0]= argv[0]->c.obj.iv[3];
ENT1001:
ENT1000:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[178];
	local[3]= argv[2];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK999:
	ctx->vsp=local; return(local[0]);}

/*:fill-polygon*/
static pointer M1002(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1007;}
	local[0]= makeint(0);
ENT1007:
	if (n>=5) { local[1]=(argv[4]); goto ENT1006;}
	local[1]= makeint(0);
ENT1006:
	if (n>=6) { local[2]=(argv[5]); goto ENT1005;}
	local[2]= argv[0]->c.obj.iv[3];
ENT1005:
ENT1004:
	if (n>6) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)VECTORP(ctx,1,local+5); /*vectorp*/
	if (w==NIL) goto CON1009;
	local[4] = argv[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[3] = w;
	local[5]= local[3];
	goto CON1008;
CON1009:
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[3] = w;
	local[5]= loadglobal(fqv[112]);
	local[6]= makeint(4);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[4] = w;
	local[5]= local[4];
	local[6]= fqv[175];
	local[7]= argv[2];
	local[8]= makeint(0);
	local[9]= fqv[176];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON1008;
CON1010:
	local[5]= NIL;
CON1008:
	local[5]= loadglobal(fqv[7]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= local[2]->c.obj.iv[2];
	local[8]= local[4];
	local[9]= local[3];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[59])(ctx,7,local+5,&ftab[59],fqv[179]); /*fillpolygon*/
	local[0]= w;
BLK1003:
	ctx->vsp=local; return(local[0]);}

/*:override_redirect*/
static pointer M1011(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1014;}
	local[0]= makeint(1);
ENT1014:
ENT1013:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[118]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F346(ctx,2,local+1); /*set-setwindowattributes-override_redirect*/
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(1);
	local[4]= makeint(9);
	ctx->vsp=local+5;
	w=(pointer)ASH(ctx,2,local+3); /*ash*/
	local[3]= w;
	local[4]= loadglobal(fqv[118]);
	ctx->vsp=local+5;
	w=(*ftab[60])(ctx,4,local+1,&ftab[60],fqv[180]); /*changewindowattributes*/
	local[0]= w;
BLK1012:
	ctx->vsp=local; return(local[0]);}

/*:save_under*/
static pointer M1015(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1018;}
	local[0]= makeint(1);
ENT1018:
ENT1017:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[118]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F340(ctx,2,local+1); /*set-setwindowattributes-save_under*/
	local[1]= loadglobal(fqv[7]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(1);
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)ASH(ctx,2,local+3); /*ash*/
	local[3]= w;
	local[4]= loadglobal(fqv[118]);
	ctx->vsp=local+5;
	w=(*ftab[60])(ctx,4,local+1,&ftab[60],fqv[180]); /*changewindowattributes*/
	local[0]= w;
BLK1016:
	ctx->vsp=local; return(local[0]);}

/*:settransientforhint*/
static pointer M1019(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[61])(ctx,3,local+0,&ftab[61],fqv[181]); /*settransientforhint*/
	local[0]= w;
BLK1020:
	ctx->vsp=local; return(local[0]);}

/*:querypointer*/
static pointer M1021(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[9]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= loadglobal(fqv[10]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= loadglobal(fqv[10]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= loadglobal(fqv[10]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= loadglobal(fqv[10]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= loadglobal(fqv[10]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= loadglobal(fqv[7]);
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= local[0];
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[3];
	local[13]= local[4];
	local[14]= local[5];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(*ftab[62])(ctx,9,local+7,&ftab[62],fqv[182]); /*querypointer*/
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[9]); /*c-long*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[9]); /*c-long*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[10]); /*c-int*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,1,local+10,&ftab[4],fqv[10]); /*c-int*/
	local[10]= w;
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(*ftab[4])(ctx,1,local+11,&ftab[4],fqv[10]); /*c-int*/
	local[11]= w;
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[10]); /*c-int*/
	local[12]= w;
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[4])(ctx,1,local+13,&ftab[4],fqv[10]); /*c-int*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,7,local+7); /*list*/
	local[0]= w;
BLK1022:
	ctx->vsp=local; return(local[0]);}

/*:global-pos*/
static pointer M1023(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[183];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint(5);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKINTVECTOR(ctx,2,local+1); /*integer-vector*/
	local[0]= w;
BLK1024:
	ctx->vsp=local; return(local[0]);}

/*make-xwindow*/
static pointer F404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST1026:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[18]);
	local[2]= loadglobal(fqv[174]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK1025:
	ctx->vsp=local; return(local[0]);}

/*find-xwindow*/
static pointer F405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1028,env,argv,local);
	local[1]= loadglobal(fqv[134]);
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1027:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1028(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[136];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,1,local+1,&ftab[34],fqv[112]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[63])(ctx,2,local+0,&ftab[63],fqv[184]); /*substringp*/
	if (w==NIL) goto IF1029;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1030;
IF1029:
	local[0]= NIL;
IF1030:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xeus(ctx,n,argv,env)
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
	local[0]= fqv[185];
	local[1]= fqv[186];
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,2,local+0,&ftab[64],fqv[187]); /*require*/
	local[0]= fqv[188];
	local[1]= fqv[189];
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,2,local+0,&ftab[64],fqv[187]); /*require*/
	local[0]= fqv[190];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1031;
	local[0]= fqv[191];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[192],w);
	goto IF1032;
IF1031:
	local[0]= fqv[193];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1032:
	local[0]= fqv[115];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1033;
	local[0]= fqv[115];
	local[1]= fqv[194];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[115];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1035;
	local[0]= fqv[115];
	local[1]= fqv[195];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1036;
IF1035:
	local[0]= NIL;
IF1036:
	local[0]= fqv[115];
	goto IF1034;
IF1033:
	local[0]= NIL;
IF1034:
	local[0]= fqv[196];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[197];
	local[1]= fqv[195];
	local[2]= fqv[197];
	local[3]= fqv[198];
	local[4]= loadglobal(fqv[199]);
	local[5]= fqv[200];
	local[6]= fqv[201];
	local[7]= fqv[202];
	local[8]= loadglobal(fqv[203]);
	local[9]= fqv[53];
	local[10]= fqv[204];
	local[11]= fqv[205];
	local[12]= makeint(-1);
	local[13]= fqv[206];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[65])(ctx,13,local+2,&ftab[65],fqv[207]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[197]);
	local[1]= fqv[208];
	local[2]= fqv[209];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F321,fqv[211]);
	local[0]= fqv[210];
	local[1]= fqv[212];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[210];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[210];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[210];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F322,fqv[218]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F323,fqv[220]);
	local[0]= fqv[219];
	local[1]= fqv[221];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[219];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[219];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[219];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F324,fqv[222]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[223],module,F325,fqv[224]);
	local[0]= fqv[223];
	local[1]= fqv[225];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[223];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[223];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[223];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[225],module,F326,fqv[226]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[227],module,F327,fqv[228]);
	local[0]= fqv[227];
	local[1]= fqv[229];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[227];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[227];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[227];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[229],module,F328,fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F329,fqv[232]);
	local[0]= fqv[231];
	local[1]= fqv[233];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[231];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[231];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[231];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F330,fqv[234]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[235],module,F331,fqv[236]);
	local[0]= fqv[235];
	local[1]= fqv[237];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[235];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[235];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[235];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[237],module,F332,fqv[238]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[239],module,F333,fqv[240]);
	local[0]= fqv[239];
	local[1]= fqv[241];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[239];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[239];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[239];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[241],module,F334,fqv[242]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[243],module,F335,fqv[244]);
	local[0]= fqv[243];
	local[1]= fqv[245];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[243];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[243];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[243];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[245],module,F336,fqv[246]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[247],module,F337,fqv[248]);
	local[0]= fqv[247];
	local[1]= fqv[249];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[247];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[247];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[247];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[249],module,F338,fqv[250]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[251],module,F339,fqv[252]);
	local[0]= fqv[251];
	local[1]= fqv[253];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[251];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[251];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[251];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[253],module,F340,fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F341,fqv[256]);
	local[0]= fqv[255];
	local[1]= fqv[257];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[255];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[255];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[255];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F342,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F343,fqv[260]);
	local[0]= fqv[259];
	local[1]= fqv[261];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[259];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[259];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[259];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F344,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F345,fqv[264]);
	local[0]= fqv[263];
	local[1]= fqv[265];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[263];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[263];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[263];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F346,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F347,fqv[268]);
	local[0]= fqv[267];
	local[1]= fqv[269];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[267];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[267];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[267];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F348,fqv[270]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[271],module,F349,fqv[272]);
	local[0]= fqv[271];
	local[1]= fqv[273];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[271];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[271];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[271];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[273],module,F350,fqv[274]);
	local[0]= fqv[151];
	local[1]= fqv[195];
	local[2]= fqv[151];
	local[3]= fqv[198];
	local[4]= loadglobal(fqv[199]);
	local[5]= fqv[200];
	local[6]= fqv[201];
	local[7]= fqv[202];
	local[8]= loadglobal(fqv[203]);
	local[9]= fqv[53];
	local[10]= fqv[204];
	local[11]= fqv[205];
	local[12]= makeint(-1);
	local[13]= fqv[206];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[65])(ctx,13,local+2,&ftab[65],fqv[207]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[151]);
	local[1]= fqv[208];
	local[2]= fqv[275];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[276],module,F351,fqv[277]);
	local[0]= fqv[276];
	local[1]= fqv[278];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[276];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[276];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[276];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[278],module,F352,fqv[279]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[280],module,F353,fqv[281]);
	local[0]= fqv[280];
	local[1]= fqv[282];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[280];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[280];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[280];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F354,fqv[283]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[284],module,F355,fqv[285]);
	local[0]= fqv[284];
	local[1]= fqv[286];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[284];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[284];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[284];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[286],module,F356,fqv[287]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[288],module,F357,fqv[289]);
	local[0]= fqv[288];
	local[1]= fqv[290];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[288];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[288];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[288];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[290],module,F358,fqv[291]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[292],module,F359,fqv[293]);
	local[0]= fqv[292];
	local[1]= fqv[294];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[292];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[292];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[292];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[294],module,F360,fqv[295]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[296],module,F361,fqv[297]);
	local[0]= fqv[296];
	local[1]= fqv[298];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[296];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[296];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[296];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[298],module,F362,fqv[299]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[300],module,F363,fqv[301]);
	local[0]= fqv[300];
	local[1]= fqv[302];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[300];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[300];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[300];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[302],module,F364,fqv[303]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[304],module,F365,fqv[305]);
	local[0]= fqv[304];
	local[1]= fqv[306];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[304];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[304];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[304];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[306],module,F366,fqv[307]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[308],module,F367,fqv[309]);
	local[0]= fqv[308];
	local[1]= fqv[310];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[308];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[308];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[308];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[310],module,F368,fqv[311]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[312],module,F369,fqv[313]);
	local[0]= fqv[312];
	local[1]= fqv[314];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[312];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[312];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[312];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[314],module,F370,fqv[315]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[316],module,F371,fqv[317]);
	local[0]= fqv[316];
	local[1]= fqv[318];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[316];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[316];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[316];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[318],module,F372,fqv[319]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[320],module,F373,fqv[321]);
	local[0]= fqv[320];
	local[1]= fqv[322];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[320];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[320];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[320];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[322],module,F374,fqv[323]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[324],module,F375,fqv[325]);
	local[0]= fqv[324];
	local[1]= fqv[326];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[324];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[324];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[324];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[326],module,F376,fqv[327]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[328],module,F377,fqv[329]);
	local[0]= fqv[328];
	local[1]= fqv[330];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[328];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[328];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[328];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[330],module,F378,fqv[331]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[332],module,F379,fqv[333]);
	local[0]= fqv[332];
	local[1]= fqv[334];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[332];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[332];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[332];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[334],module,F380,fqv[335]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[336],module,F381,fqv[337]);
	local[0]= fqv[336];
	local[1]= fqv[338];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[336];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[336];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[336];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[338],module,F382,fqv[339]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[340],module,F383,fqv[341]);
	local[0]= fqv[340];
	local[1]= fqv[342];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[340];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[340];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[340];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[342],module,F384,fqv[343]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[344],module,F385,fqv[345]);
	local[0]= fqv[344];
	local[1]= fqv[346];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[344];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[344];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[344];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[346],module,F386,fqv[347]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[348],module,F387,fqv[349]);
	local[0]= fqv[348];
	local[1]= fqv[350];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[348];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[348];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[348];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[350],module,F388,fqv[351]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[352],module,F389,fqv[353]);
	local[0]= fqv[352];
	local[1]= fqv[354];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[352];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[352];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[352];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[354],module,F390,fqv[355]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[356],module,F391,fqv[357]);
	local[0]= fqv[356];
	local[1]= fqv[358];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[356];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[356];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[356];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[358],module,F392,fqv[359]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[360],module,F393,fqv[361]);
	local[0]= fqv[360];
	local[1]= fqv[362];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[360];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[360];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[360];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[362],module,F394,fqv[363]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F395,fqv[365]);
	local[0]= fqv[364];
	local[1]= fqv[366];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[364];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[364];
	local[1]= fqv[216];
	ctx->vsp=local+2;
	w=(*ftab[66])(ctx,2,local+0,&ftab[66],fqv[215]); /*remprop*/
	local[0]= fqv[364];
	local[1]= NIL;
	local[2]= fqv[217];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[366],module,F396,fqv[367]);
	local[0]= fqv[118];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1037;
	local[0]= fqv[118];
	local[1]= fqv[194];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[118];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1039;
	local[0]= fqv[118];
	local[1]= fqv[195];
	local[2]= loadglobal(fqv[197]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1040;
IF1039:
	local[0]= NIL;
IF1040:
	local[0]= fqv[118];
	goto IF1038;
IF1037:
	local[0]= NIL;
IF1038:
	local[0]= fqv[13];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1041;
	local[0]= fqv[13];
	local[1]= fqv[194];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1043;
	local[0]= fqv[13];
	local[1]= fqv[195];
	local[2]= loadglobal(fqv[151]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1044;
IF1043:
	local[0]= NIL;
IF1044:
	local[0]= fqv[13];
	goto IF1042;
IF1041:
	local[0]= NIL;
IF1042:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M482,fqv[82],fqv[368],fqv[369]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M498,fqv[4],fqv[368],fqv[370]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M500,fqv[371],fqv[368],fqv[372]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M502,fqv[12],fqv[368],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M504,fqv[26],fqv[368],fqv[374]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M506,fqv[25],fqv[368],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M508,fqv[376],fqv[368],fqv[377]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M510,fqv[378],fqv[368],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M512,fqv[380],fqv[368],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M514,fqv[19],fqv[368],fqv[382]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M521,fqv[383],fqv[368],fqv[384]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M523,fqv[20],fqv[368],fqv[385]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M527,fqv[21],fqv[368],fqv[386]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M531,fqv[387],fqv[368],fqv[388]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M540,fqv[164],fqv[368],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M550,fqv[390],fqv[368],fqv[391]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M558,fqv[55],fqv[368],fqv[392]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M562,fqv[56],fqv[368],fqv[393]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M566,fqv[59],fqv[368],fqv[394]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M570,fqv[61],fqv[368],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M577,fqv[60],fqv[368],fqv[396]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M581,fqv[62],fqv[368],fqv[397]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M588,fqv[57],fqv[368],fqv[398]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M594,fqv[58],fqv[368],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M600,fqv[400],fqv[368],fqv[401]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M615,fqv[402],fqv[368],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M645,fqv[404],fqv[368],fqv[405]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M667,fqv[406],fqv[368],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M671,fqv[408],fqv[368],fqv[409]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M675,fqv[410],fqv[368],fqv[411]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M681,fqv[412],fqv[368],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M687,fqv[414],fqv[368],fqv[415]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M691,fqv[416],fqv[368],fqv[417]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M697,fqv[418],fqv[368],fqv[419]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M704,fqv[420],fqv[368],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M711,fqv[422],fqv[368],fqv[423]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M713,fqv[424],fqv[368],fqv[425]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M715,fqv[426],fqv[368],fqv[427]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M717,fqv[428],fqv[368],fqv[429]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M719,fqv[68],fqv[368],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M726,fqv[65],fqv[368],fqv[431]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M728,fqv[432],fqv[368],fqv[433]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M755,fqv[434],fqv[368],fqv[435]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M766,fqv[3],fqv[89],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M773,fqv[437],fqv[89],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M775,fqv[169],fqv[89],fqv[439]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M777,fqv[147],fqv[89],fqv[440]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[441],module,F397,fqv[442]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[443],module,F398,fqv[444]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[445],module,F399,fqv[446]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[447],module,F400,fqv[448]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[449],module,F401,fqv[450]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[451],module,F402,fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M824,fqv[3],fqv[174],fqv[453]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M895,fqv[454],fqv[174],fqv[455]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M901,fqv[137],fqv[174],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M903,fqv[139],fqv[174],fqv[457]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M905,fqv[458],fqv[174],fqv[459]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M907,fqv[460],fqv[174],fqv[461]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M909,fqv[133],fqv[174],fqv[462]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M913,fqv[149],fqv[174],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M915,fqv[464],fqv[174],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M922,fqv[147],fqv[174],fqv[466]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M929,fqv[152],fqv[174],fqv[467]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M931,fqv[468],fqv[174],fqv[469]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M933,fqv[470],fqv[174],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M935,fqv[46],fqv[174],fqv[472]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M939,fqv[473],fqv[174],fqv[474]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M941,fqv[205],fqv[174],fqv[475]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M943,fqv[101],fqv[174],fqv[476]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M945,fqv[477],fqv[174],fqv[478]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M947,fqv[119],fqv[174],fqv[479]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M949,fqv[480],fqv[174],fqv[481]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M951,fqv[482],fqv[174],fqv[483]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M953,fqv[100],fqv[174],fqv[484]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M959,fqv[485],fqv[174],fqv[486]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M961,fqv[487],fqv[174],fqv[488]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M963,fqv[489],fqv[174],fqv[490]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M965,fqv[491],fqv[174],fqv[492]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M967,fqv[493],fqv[174],fqv[494]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M969,fqv[495],fqv[174],fqv[496]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M971,fqv[497],fqv[174],fqv[498]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M973,fqv[499],fqv[174],fqv[500]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M975,fqv[169],fqv[174],fqv[501]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M977,fqv[65],fqv[174],fqv[502]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M979,fqv[68],fqv[174],fqv[503]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M985,fqv[504],fqv[174],fqv[505]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M987,fqv[64],fqv[174],fqv[506]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[507],module,F403,fqv[508]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M993,fqv[178],fqv[368],fqv[509]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M998,fqv[510],fqv[368],fqv[511]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1002,fqv[76],fqv[368],fqv[512]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1011,fqv[513],fqv[174],fqv[514]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1015,fqv[515],fqv[174],fqv[516]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1019,fqv[517],fqv[174],fqv[518]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1021,fqv[183],fqv[174],fqv[519]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1023,fqv[520],fqv[174],fqv[521]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[522],module,F404,fqv[523]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[524],module,F405,fqv[525]);
	local[0]= fqv[526];
	local[1]= fqv[527];
	ctx->vsp=local+2;
	w=(*ftab[67])(ctx,2,local+0,&ftab[67],fqv[528]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<68; i++) ftab[i]=fcallx;
}
