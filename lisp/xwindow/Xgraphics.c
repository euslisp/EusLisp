/* Xgraphics.c :  entry=Xgraphics */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xgraphics.h"
#pragma init (register_Xgraphics)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xgraphics();
extern pointer build_quote_vector();
static register_Xgraphics()
  { add_module_initializer("___Xgraphics", ___Xgraphics);}

static pointer F1045();
static pointer F1046();
static pointer F1047();
static pointer F1048();
static pointer F1049();
static pointer F1050();
static pointer F1051();
static pointer F1052();
static pointer F1053();
static pointer F1054();
static pointer F1055();
static pointer F1056();
static pointer F1057();
static pointer F1058();
static pointer F1059();
static pointer F1060();
static pointer F1061();
static pointer F1062();
static pointer F1063();
static pointer F1064();
static pointer F1065();
static pointer F1066();
static pointer F1067();
static pointer F1068();
static pointer F1069();
static pointer F1070();
static pointer F1071();
static pointer F1072();
static pointer F1073();
static pointer F1074();
static pointer F1075();
static pointer F1076();
static pointer F1077();
static pointer F1078();
static pointer F1079();
static pointer F1080();
static pointer F1081();
static pointer F1082();
static pointer F1083();
static pointer F1084();
static pointer F1085();
static pointer F1086();
static pointer F1087();
static pointer F1088();
static pointer F1089();
static pointer F1090();
static pointer F1115();
static pointer F1120();
static pointer F1121();
static pointer F1122();
static pointer F1123();
static pointer F1124();
static pointer F1125();

/*gcvalues-function*/
static pointer F1045(ctx,n,argv,env)
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
BLK1126:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-function*/
static pointer F1046(ctx,n,argv,env)
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
BLK1127:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-plane-mask*/
static pointer F1047(ctx,n,argv,env)
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
BLK1128:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-plane-mask*/
static pointer F1048(ctx,n,argv,env)
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
BLK1129:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-foreground*/
static pointer F1049(ctx,n,argv,env)
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
BLK1130:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-foreground*/
static pointer F1050(ctx,n,argv,env)
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
BLK1131:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-background*/
static pointer F1051(ctx,n,argv,env)
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
BLK1132:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-background*/
static pointer F1052(ctx,n,argv,env)
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
BLK1133:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-line-width*/
static pointer F1053(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(16);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1134:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-line-width*/
static pointer F1054(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(16);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1135:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-line-style*/
static pointer F1055(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(20);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1136:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-line-style*/
static pointer F1056(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(20);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1137:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-cap-style*/
static pointer F1057(ctx,n,argv,env)
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
BLK1138:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-cap-style*/
static pointer F1058(ctx,n,argv,env)
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
BLK1139:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-join-style*/
static pointer F1059(ctx,n,argv,env)
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
BLK1140:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-join-style*/
static pointer F1060(ctx,n,argv,env)
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
BLK1141:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-fill-style*/
static pointer F1061(ctx,n,argv,env)
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
BLK1142:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-fill-style*/
static pointer F1062(ctx,n,argv,env)
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
BLK1143:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-fill-rule*/
static pointer F1063(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(36);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1144:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-fill-rule*/
static pointer F1064(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(36);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1145:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-arc-mode*/
static pointer F1065(ctx,n,argv,env)
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
BLK1146:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-arc-mode*/
static pointer F1066(ctx,n,argv,env)
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
BLK1147:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-tile*/
static pointer F1067(ctx,n,argv,env)
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
BLK1148:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-tile*/
static pointer F1068(ctx,n,argv,env)
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
BLK1149:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-stipple*/
static pointer F1069(ctx,n,argv,env)
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
BLK1150:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-stipple*/
static pointer F1070(ctx,n,argv,env)
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
BLK1151:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-ts-x-origin*/
static pointer F1071(ctx,n,argv,env)
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
BLK1152:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-ts-x-origin*/
static pointer F1072(ctx,n,argv,env)
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
BLK1153:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-ts-y-origin*/
static pointer F1073(ctx,n,argv,env)
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
BLK1154:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-ts-y-origin*/
static pointer F1074(ctx,n,argv,env)
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
BLK1155:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-font*/
static pointer F1075(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(60);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1156:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-font*/
static pointer F1076(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(60);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1157:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-subwindow-mode*/
static pointer F1077(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(64);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1158:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-subwindow-mode*/
static pointer F1078(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(64);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1159:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-graphics-exposures*/
static pointer F1079(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(68);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1160:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-graphics-exposures*/
static pointer F1080(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(68);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1161:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-clip-x-origin*/
static pointer F1081(ctx,n,argv,env)
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
BLK1162:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-clip-x-origin*/
static pointer F1082(ctx,n,argv,env)
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
BLK1163:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-clip-y-origin*/
static pointer F1083(ctx,n,argv,env)
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
BLK1164:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-clip-y-origin*/
static pointer F1084(ctx,n,argv,env)
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
BLK1165:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-clip-mask*/
static pointer F1085(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(80);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1166:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-clip-mask*/
static pointer F1086(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(80);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1167:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-dash-offset*/
static pointer F1087(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(84);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1168:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-dash-offset*/
static pointer F1088(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(84);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1169:
	ctx->vsp=local; return(local[0]);}

/*gcvalues-dashes*/
static pointer F1089(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(88);
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1170:
	ctx->vsp=local; return(local[0]);}

/*set-gcvalues-dashes*/
static pointer F1090(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(88);
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1171:
	ctx->vsp=local; return(local[0]);}

/*font-id*/
static pointer F1115(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	w = argv[0];
	if (!isint(w)) goto CON1198;
	local[2]= argv[0];
	goto CON1197;
CON1198:
	w = argv[0];
	if (!isstring(w)) goto CON1199;
	local[2]= loadglobal(fqv[3]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[4]); /*loadqueryfont*/
	local[1] = w;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1200;
	local[2]= makeint(0);
	local[3]= fqv[5];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[6]); /*warn*/
	w = local[2];
	local[2]= w;
	goto IF1201;
IF1200:
	local[2]= local[1];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)PEEK(ctx,2,local+2); /*system:peek*/
	local[2]= w;
IF1201:
	goto CON1197;
CON1199:
	local[2]= NIL;
CON1197:
	w = local[2];
	local[0]= w;
BLK1196:
	ctx->vsp=local; return(local[0]);}

/*textdots*/
static pointer F1120(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1209;}
	local[0]= loadglobal(fqv[7]);
ENT1209:
ENT1208:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= loadglobal(fqv[9]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= makeint(16);
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[10]); /*make-string*/
	local[4]= w;
	local[5]= loadglobal(fqv[3]);
	local[6]= local[0];
	local[7]= argv[0];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[3])(ctx,8,local+5,&ftab[3],fqv[11]); /*querytextextents*/
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[9]); /*c-int*/
	local[5]= w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,1,local+6,&ftab[4],fqv[9]); /*c-int*/
	local[6]= w;
	local[7]= local[4];
	local[8]= makeint(5);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= makeint(256);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[4];
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKINTVECTOR(ctx,3,local+5); /*integer-vector*/
	local[0]= w;
BLK1207:
	ctx->vsp=local; return(local[0]);}

/*create-ximage*/
static pointer F1121(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[12], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY1211;
	local[0] = makeint(0);
KEY1211:
	if (n & (1<<1)) goto KEY1212;
	local[1] = makeint(0);
KEY1212:
	if (n & (1<<2)) goto KEY1213;
	local[2] = loadglobal(fqv[13]);
KEY1213:
	if (n & (1<<3)) goto KEY1214;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,1,local+6,&ftab[5],fqv[14]); /*visual-depth*/
	local[3] = w;
KEY1214:
	if (n & (1<<4)) goto KEY1215;
	local[4] = makeint(2);
KEY1215:
	if (n & (1<<5)) goto KEY1216;
	local[5] = makeint(0);
KEY1216:
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= local[8];
	if (fqv[15]!=local[9]) goto IF1218;
	local[9]= makeint(8);
	goto IF1219;
IF1218:
	local[9]= local[8];
	if (fqv[16]!=local[9]) goto IF1220;
	local[9]= makeint(16);
	goto IF1221;
IF1220:
	local[9]= local[8];
	if (fqv[17]!=local[9]) goto IF1222;
	local[9]= makeint(16);
	goto IF1223;
IF1222:
	if (T==NIL) goto IF1224;
	local[9]= makeint(32);
	goto IF1225;
IF1224:
	local[9]= NIL;
IF1225:
IF1223:
IF1221:
IF1219:
	w = local[9];
	local[6] = w;
	local[8]= loadglobal(fqv[3]);
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	local[12]= local[5];
	local[13]= argv[0];
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[6];
	local[17]= local[0];
	local[18]= local[6];
	local[19]= makeint(8);
	ctx->vsp=local+20;
	w=(pointer)QUOTIENT(ctx,2,local+18); /*/*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[6])(ctx,10,local+8,&ftab[6],fqv[18]); /*createimage*/
	local[7] = w;
	local[8]= local[7];
	local[9]= makeint(64);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[19]); /*make-foreign-string*/
	local[0]= w;
BLK1210:
	ctx->vsp=local; return(local[0]);}

/*set-ximage*/
static pointer F1122(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1230;}
	local[0]= loadglobal(fqv[13]);
ENT1230:
	if (n>=6) { local[1]=(argv[5]); goto ENT1229;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[14]); /*visual-depth*/
	local[1]= w;
ENT1229:
	if (n>=7) { local[2]=(argv[6]); goto ENT1228;}
	local[2]= local[1];
ENT1228:
ENT1227:
	if (n>7) maerror();
	local[3]= argv[2];
	local[4]= argv[0];
	local[5]= makeint(0);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= argv[3];
	local[4]= argv[0];
	local[5]= makeint(4);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= makeint(2);
	local[4]= argv[0];
	local[5]= makeint(12);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= makeint(16);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= loadglobal(fqv[20]);
	local[4]= argv[0];
	local[5]= makeint(20);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= makeint(24);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= loadglobal(fqv[20]);
	local[4]= argv[0];
	local[5]= makeint(28);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= makeint(32);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= local[1];
	local[4]= argv[0];
	local[5]= makeint(36);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= argv[2];
	local[4]= local[2];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[0];
	local[5]= makeint(40);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= local[1];
	local[4]= argv[0];
	local[5]= makeint(44);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= loadglobal(fqv[21]);
	local[4]= argv[0];
	local[5]= makeint(48);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= loadglobal(fqv[22]);
	local[4]= argv[0];
	local[5]= makeint(48);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= loadglobal(fqv[23]);
	local[4]= argv[0];
	local[5]= makeint(48);
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	w = argv[0];
	local[0]= w;
BLK1226:
	ctx->vsp=local; return(local[0]);}

/*gc-attribute-to-mask*/
static pointer F1123(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[25]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto IF1232;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	goto IF1233;
IF1232:
	local[1]= makeint(0);
IF1233:
	w = local[1];
	local[0]= w;
BLK1231:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1234(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[2] = argv[2];
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= loadglobal(fqv[26]);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,3,local+0,&ftab[9],fqv[27]); /*sethash*/
	w = argv[0];
	local[0]= w;
BLK1235:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M1236(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1238:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[28], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1239;
	local[5]= loadglobal(fqv[3]);
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[29]); /*defaultrootwindow*/
	local[1] = w;
KEY1239:
	if (n & (1<<1)) goto KEY1240;
	local[2] = loadglobal(fqv[30]);
KEY1240:
	if (n & (1<<2)) goto KEY1241;
	local[3] = loadglobal(fqv[31]);
KEY1241:
	if (n & (1<<3)) goto KEY1242;
	local[4] = NIL;
KEY1242:
	local[5]= argv[0];
	local[6]= fqv[32];
	local[7]= loadglobal(fqv[3]);
	local[8]= local[1];
	local[9]= makeint(0);
	local[10]= loadglobal(fqv[33]);
	ctx->vsp=local+11;
	w=(*ftab[11])(ctx,4,local+7,&ftab[11],fqv[34]); /*creategc*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (local[4]==NIL) goto IF1243;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[35]));
	local[7]= fqv[36];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,4,local+5); /*send-message*/
	local[5]= w;
	goto IF1244;
IF1243:
	local[5]= NIL;
IF1244:
	local[5]= (pointer)get_sym_func(fqv[37]);
	local[6]= argv[0];
	local[7]= fqv[38];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,4,local+5); /*apply*/
	w = argv[0];
	local[0]= w;
BLK1237:
	ctx->vsp=local; return(local[0]);}

/*:free*/
static pointer M1245(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[3]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[39]); /*freegc*/
	local[0]= w;
BLK1246:
	ctx->vsp=local; return(local[0]);}

/*:gc*/
static pointer M1247(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK1248:
	ctx->vsp=local; return(local[0]);}

/*:copy*/
static pointer M1249(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[40]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= loadglobal(fqv[3]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[42];
	local[4]= local[0];
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,4,local+1,&ftab[13],fqv[44]); /*copygc*/
	w = local[0];
	local[0]= w;
BLK1250:
	ctx->vsp=local; return(local[0]);}

/*:function-to-value*/
static pointer M1252(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF1254;
	local[0]= argv[2];
	local[1]= fqv[45];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[25]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[0]= argv[2];
	goto IF1255;
IF1254:
	local[0]= NIL;
IF1255:
	w = argv[2];
	if (isint(w)) goto IF1256;
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF1257;
IF1256:
	local[0]= NIL;
IF1257:
	w = argv[2];
	local[0]= w;
BLK1253:
	ctx->vsp=local; return(local[0]);}

/*:function*/
static pointer M1258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[3]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,3,local+0,&ftab[14],fqv[48]); /*setfunction*/
	local[0]= w;
BLK1259:
	ctx->vsp=local; return(local[0]);}

/*:foreground*/
static pointer M1260(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1264;}
	local[0]= NIL;
ENT1264:
	if (n>=4) { local[1]=(argv[3]); goto ENT1263;}
	local[1]= loadglobal(fqv[49]);
ENT1263:
ENT1262:
	if (n>4) maerror();
	w = local[0];
	if (!isstring(w)) goto IF1265;
	local[2]= local[1];
	local[3]= fqv[50];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[0];
	goto IF1266;
IF1265:
	local[2]= NIL;
IF1266:
	if (local[0]==NIL) goto IF1267;
	local[2]= loadglobal(fqv[3]);
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,3,local+2,&ftab[15],fqv[51]); /*setforeground*/
	local[2]= w;
	goto IF1268;
IF1267:
	local[2]= argv[0];
	local[3]= fqv[52];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF1268:
	w = local[2];
	local[0]= w;
BLK1261:
	ctx->vsp=local; return(local[0]);}

/*:background*/
static pointer M1269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1273;}
	local[0]= NIL;
ENT1273:
	if (n>=4) { local[1]=(argv[3]); goto ENT1272;}
	local[1]= loadglobal(fqv[49]);
ENT1272:
ENT1271:
	if (n>4) maerror();
	w = local[0];
	if (!isstring(w)) goto IF1274;
	local[2]= local[1];
	local[3]= fqv[50];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[0];
	goto IF1275;
IF1274:
	local[2]= NIL;
IF1275:
	if (local[0]==NIL) goto IF1276;
	local[2]= loadglobal(fqv[3]);
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,3,local+2,&ftab[16],fqv[54]); /*setbackground*/
	local[2]= w;
	goto IF1277;
IF1276:
	local[2]= argv[0];
	local[3]= fqv[52];
	local[4]= fqv[55];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF1277:
	w = local[2];
	local[0]= w;
BLK1270:
	ctx->vsp=local; return(local[0]);}

/*:foreback*/
static pointer M1278(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1282;}
	local[0]= NIL;
ENT1282:
	if (n>=4) { local[1]=(argv[3]); goto ENT1281;}
	local[1]= NIL;
ENT1281:
ENT1280:
	if (n>4) maerror();
	local[2]= argv[0];
	local[3]= fqv[56];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[57];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK1279:
	ctx->vsp=local; return(local[0]);}

/*:reverse*/
static pointer M1283(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[58];
	local[5]= fqv[53];
	local[6]= fqv[55];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F1049(ctx,1,local+3); /*gcvalues-foreground*/
	local[1] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F1051(ctx,1,local+3); /*gcvalues-background*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[38];
	local[5]= fqv[56];
	local[6]= local[2];
	local[7]= fqv[57];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK1284:
	ctx->vsp=local; return(local[0]);}

/*:planemask*/
static pointer M1285(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1288;}
	local[0]= NIL;
ENT1288:
ENT1287:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1289;
	local[1]= loadglobal(fqv[3]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,3,local+1,&ftab[17],fqv[59]); /*setplanemask*/
	local[1]= w;
	goto IF1290;
IF1289:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[60];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1290:
	w = local[1];
	local[0]= w;
BLK1286:
	ctx->vsp=local; return(local[0]);}

/*:line-width*/
static pointer M1291(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1294;}
	local[0]= NIL;
ENT1294:
ENT1293:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1295;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= fqv[61];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1296;
IF1295:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1296:
	w = local[1];
	local[0]= w;
BLK1292:
	ctx->vsp=local; return(local[0]);}

/*:line-style*/
static pointer M1297(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1300;}
	local[0]= NIL;
ENT1300:
ENT1299:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1301;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= fqv[63];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1302;
IF1301:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1302:
	w = local[1];
	local[0]= w;
BLK1298:
	ctx->vsp=local; return(local[0]);}

/*:cap-style*/
static pointer M1303(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1306;}
	local[0]= NIL;
ENT1306:
ENT1305:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1307;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= fqv[65];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1308;
IF1307:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[66];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1308:
	w = local[1];
	local[0]= w;
BLK1304:
	ctx->vsp=local; return(local[0]);}

/*:join-style*/
static pointer M1309(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1312;}
	local[0]= NIL;
ENT1312:
ENT1311:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1313;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= fqv[67];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1314;
IF1313:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[68];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1314:
	w = local[1];
	local[0]= w;
BLK1310:
	ctx->vsp=local; return(local[0]);}

/*:dash*/
static pointer M1315(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1317:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	local[2]= loadglobal(fqv[69]);
	ctx->vsp=local+3;
	w=(pointer)COERCE(ctx,2,local+1); /*coerce*/
	local[0] = w;
	local[1]= loadglobal(fqv[3]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,5,local+1,&ftab[18],fqv[70]); /*setdashes*/
	local[0]= w;
BLK1316:
	ctx->vsp=local; return(local[0]);}

/*:fill-style*/
static pointer M1318(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1321;}
	local[0]= NIL;
ENT1321:
ENT1320:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1322;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= fqv[71];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1323;
IF1322:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[72];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1323:
	w = local[1];
	local[0]= w;
BLK1319:
	ctx->vsp=local; return(local[0]);}

/*:fill-rule*/
static pointer M1324(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1327;}
	local[0]= NIL;
ENT1327:
ENT1326:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1328;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= fqv[73];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1329;
IF1328:
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= fqv[74];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF1329:
	w = local[1];
	local[0]= w;
BLK1325:
	ctx->vsp=local; return(local[0]);}

/*:change-attributes*/
static pointer M1330(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1332:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[75], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1333;
	local[1] = NIL;
KEY1333:
	if (n & (1<<1)) goto KEY1334;
	local[2] = NIL;
KEY1334:
	if (n & (1<<2)) goto KEY1335;
	local[3] = NIL;
KEY1335:
	if (n & (1<<3)) goto KEY1336;
	local[4] = NIL;
KEY1336:
	if (n & (1<<4)) goto KEY1337;
	local[5] = NIL;
KEY1337:
	if (n & (1<<5)) goto KEY1338;
	local[6] = NIL;
KEY1338:
	if (n & (1<<6)) goto KEY1339;
	local[7] = NIL;
KEY1339:
	if (n & (1<<7)) goto KEY1340;
	local[8] = NIL;
KEY1340:
	if (n & (1<<8)) goto KEY1341;
	local[9] = NIL;
KEY1341:
	if (n & (1<<9)) goto KEY1342;
	local[10] = NIL;
KEY1342:
	if (n & (1<<10)) goto KEY1343;
	local[11] = NIL;
KEY1343:
	if (n & (1<<11)) goto KEY1344;
	local[12] = loadglobal(fqv[49]);
KEY1344:
	if (n & (1<<12)) goto KEY1345;
	local[13] = NIL;
KEY1345:
	if (n & (1<<13)) goto KEY1346;
	local[14] = NIL;
KEY1346:
	if (n & (1<<14)) goto KEY1347;
	local[15] = makeint(0);
KEY1347:
	if (n & (1<<15)) goto KEY1348;
	local[16] = NIL;
KEY1348:
	if (n & (1<<16)) goto KEY1349;
	local[17] = NIL;
KEY1349:
	local[18]= NIL;
	local[19]= makeint(0);
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
WHL1350:
	if (local[0]==NIL) goto WHX1351;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[23];
	local[22] = w;
	local[23]= local[21];
	local[24]= local[23];
	if (fqv[76]!=local[24]) goto IF1356;
	local[24]= local[22];
	ctx->vsp=local+25;
	w=(pointer)F1115(ctx,1,local+24); /*font-id*/
	local[22] = w;
	local[24]= local[22];
	goto IF1357;
IF1356:
	local[24]= local[23];
	if (fqv[77]!=local[24]) goto IF1358;
	local[24]= argv[0];
	local[25]= fqv[47];
	local[26]= local[22];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[22] = w;
	local[24]= local[22];
	goto IF1359;
IF1358:
	local[24]= local[23];
	if (fqv[56]!=local[24]) goto IF1360;
	local[24]= local[12];
	local[25]= fqv[50];
	local[26]= local[22];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[22] = w;
	local[24]= local[22];
	goto IF1361;
IF1360:
	local[24]= local[23];
	if (fqv[57]!=local[24]) goto IF1362;
	local[24]= local[12];
	local[25]= fqv[50];
	local[26]= local[22];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[22] = w;
	local[24]= local[22];
	goto IF1363;
IF1362:
	local[24]= NIL;
IF1363:
IF1361:
IF1359:
IF1357:
	w = local[24];
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(pointer)F1123(ctx,1,local+23); /*gc-attribute-to-mask*/
	local[20] = w;
	local[23]= local[20];
	local[24]= makeint(0);
	ctx->vsp=local+25;
	w=(*ftab[19])(ctx,2,local+23,&ftab[19],fqv[78]); /*/=*/
	if (w==NIL) goto IF1364;
	local[23]= local[19];
	local[24]= local[20];
	ctx->vsp=local+25;
	w=(pointer)LOGIOR(ctx,2,local+23); /*logior*/
	local[19] = w;
	local[23]= loadglobal(fqv[33]);
	local[24]= fqv[79];
	local[25]= local[22];
	local[26]= local[21];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,4,local+23); /*send*/
	local[23]= w;
	goto IF1365;
IF1364:
	local[23]= NIL;
IF1365:
	goto WHL1350;
WHX1351:
	local[23]= NIL;
BLK1352:
	local[23]= loadglobal(fqv[3]);
	local[24]= argv[0]->c.obj.iv[2];
	local[25]= local[19];
	local[26]= loadglobal(fqv[33]);
	ctx->vsp=local+27;
	w=(*ftab[20])(ctx,4,local+23,&ftab[20],fqv[80]); /*changegc*/
	w = local[19];
	local[0]= w;
BLK1331:
	ctx->vsp=local; return(local[0]);}

/*:get-attributes*/
static pointer M1366(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1368:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= local[0];
WHL1370:
	if (local[3]==NIL) goto WHX1371;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	w = local[2];
	if (!isint(w)) goto CON1375;
	local[4]= local[2];
	goto CON1374;
CON1375:
	w = local[2];
	if (!issymbol(w)) goto CON1376;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)F1123(ctx,1,local+4); /*gc-attribute-to-mask*/
	local[4]= w;
	goto CON1374;
CON1376:
	local[4]= NIL;
CON1374:
	ctx->vsp=local+5;
	w=(pointer)LOGIOR(ctx,1,local+4); /*logior*/
	local[1] = w;
	goto WHL1370;
WHX1371:
	local[4]= NIL;
BLK1372:
	w = NIL;
	local[2]= loadglobal(fqv[3]);
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	local[5]= loadglobal(fqv[33]);
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,4,local+2,&ftab[21],fqv[81]); /*getgcvalues*/
	w = loadglobal(fqv[33]);
	local[0]= w;
BLK1367:
	ctx->vsp=local; return(local[0]);}

/*:get-attribute*/
static pointer M1377(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[82];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1378:
	ctx->vsp=local; return(local[0]);}

/*:font*/
static pointer M1379(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1382;}
	local[0]= NIL;
ENT1382:
ENT1381:
	if (n>3) maerror();
	local[1]= NIL;
	w = local[0];
	if (!isstring(w)) goto CON1384;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F1115(ctx,1,local+2); /*font-id*/
	local[1] = w;
	local[2]= local[1];
	goto CON1383;
CON1384:
	w = local[0];
	if (!isint(w)) goto CON1385;
	local[1] = local[0];
	local[2]= local[1];
	goto CON1383;
CON1385:
	if (local[0]!=NIL) goto CON1386;
	local[2]= argv[0];
	local[3]= fqv[52];
	local[4]= fqv[83];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1380;
	goto CON1383;
CON1386:
	local[2]= local[0];
	local[3]= fqv[76];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= local[1];
	goto CON1383;
CON1387:
	local[2]= NIL;
CON1383:
	local[2]= loadglobal(fqv[3]);
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[22])(ctx,3,local+2,&ftab[22],fqv[84]); /*setfont*/
	w = local[1];
	local[0]= w;
BLK1380:
	ctx->vsp=local; return(local[0]);}

/*:tile*/
static pointer M1388(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[3]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,3,local+0,&ftab[23],fqv[86]); /*settile*/
	local[0]= w;
BLK1389:
	ctx->vsp=local; return(local[0]);}

/*:stipple*/
static pointer M1390(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[3]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[24])(ctx,3,local+0,&ftab[24],fqv[87]); /*setstipple*/
	local[0]= w;
BLK1391:
	ctx->vsp=local; return(local[0]);}

/*make-gc-from-pixmap*/
static pointer F1124(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[40]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
	storeglobal(fqv[88],w);
	local[0]= loadglobal(fqv[88]);
	local[1]= fqv[38];
	local[2]= fqv[71];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[88]);
	local[1]= fqv[89];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = loadglobal(fqv[88]);
	local[0]= w;
BLK1392:
	ctx->vsp=local; return(local[0]);}

/*make-color-gc*/
static pointer F1125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1397;}
	local[0]= NIL;
ENT1397:
	if (n>=3) { local[1]=(argv[2]); goto ENT1396;}
	local[1]= loadglobal(fqv[49]);
ENT1396:
ENT1395:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto CON1399;
	local[4]= (pointer)get_sym_func(fqv[37]);
	local[5]= local[1];
	local[6]= fqv[90];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto CON1398;
CON1399:
	if (argv[0]==NIL) goto CON1400;
	local[4]= local[1];
	local[5]= fqv[90];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON1398;
CON1400:
	local[4]= loadglobal(fqv[31]);
	goto CON1398;
CON1401:
	local[4]= NIL;
CON1398:
	local[2] = local[4];
	w = local[0];
	if (!iscons(w)) goto CON1403;
	local[4]= (pointer)get_sym_func(fqv[37]);
	local[5]= local[1];
	local[6]= fqv[90];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto CON1402;
CON1403:
	if (local[0]==NIL) goto CON1404;
	local[4]= local[1];
	local[5]= fqv[90];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON1402;
CON1404:
	local[4]= loadglobal(fqv[30]);
	goto CON1402;
CON1405:
	local[4]= NIL;
CON1402:
	local[3] = local[4];
	w = local[2];
	if (!isnum(w)) goto IF1406;
	w = local[3];
	if (!isnum(w)) goto IF1406;
	local[4]= loadglobal(fqv[40]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[41];
	local[7]= fqv[56];
	local[8]= local[2];
	local[9]= fqv[57];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,6,local+5); /*send*/
	w = local[4];
	local[4]= w;
	goto IF1407;
IF1406:
	local[4]= fqv[91];
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,4,local+4,&ftab[1],fqv[6]); /*warn*/
	local[4]= NIL;
IF1407:
	w = local[4];
	local[0]= w;
BLK1394:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xgraphics(ctx,n,argv,env)
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
	local[0]= fqv[92];
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,2,local+0,&ftab[25],fqv[94]); /*require*/
	local[0]= fqv[95];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1409;
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[97],w);
	goto IF1410;
IF1409:
	local[0]= fqv[98];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1410:
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[100];
	local[1]= fqv[101];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[102];
	local[1]= fqv[101];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[20];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint(1);
	local[1]= fqv[104];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,3,local+0,&ftab[26],fqv[105]); /*make-array*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(0);
	local[3]= makeint(19088743);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= local[0];
	local[2]= loadglobal(fqv[69]);
	ctx->vsp=local+3;
	w=(*ftab[27])(ctx,2,local+1,&ftab[27],fqv[106]); /*become*/
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= makeint(103);
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF1411;
	local[1]= makeint(0);
	goto IF1412;
IF1411:
	local[1]= makeint(1);
IF1412:
	storeglobal(fqv[20],local[1]);
	w = local[1];
	local[0]= fqv[107];
	local[1]= fqv[103];
	local[2]= fqv[107];
	local[3]= fqv[108];
	local[4]= loadglobal(fqv[109]);
	local[5]= fqv[110];
	local[6]= fqv[111];
	local[7]= fqv[112];
	local[8]= loadglobal(fqv[113]);
	local[9]= fqv[104];
	local[10]= fqv[114];
	local[11]= fqv[115];
	local[12]= makeint(-1);
	local[13]= fqv[116];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[28])(ctx,13,local+2,&ftab[28],fqv[117]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[107]);
	local[1]= fqv[118];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[120],module,F1045,fqv[121]);
	local[0]= fqv[120];
	local[1]= fqv[122];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[120];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[120];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[120];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[122],module,F1046,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F1047,fqv[130]);
	local[0]= fqv[129];
	local[1]= fqv[131];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[129];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[129];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[129];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F1048,fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F1049,fqv[134]);
	local[0]= fqv[133];
	local[1]= fqv[135];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[133];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[133];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[133];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F1050,fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F1051,fqv[138]);
	local[0]= fqv[137];
	local[1]= fqv[139];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[137];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[137];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[137];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F1052,fqv[140]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F1053,fqv[142]);
	local[0]= fqv[141];
	local[1]= fqv[143];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[141];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[141];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[141];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F1054,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F1055,fqv[146]);
	local[0]= fqv[145];
	local[1]= fqv[147];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[145];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[145];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[145];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F1056,fqv[148]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F1057,fqv[150]);
	local[0]= fqv[149];
	local[1]= fqv[151];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[149];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[149];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[149];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F1058,fqv[152]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F1059,fqv[154]);
	local[0]= fqv[153];
	local[1]= fqv[155];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[153];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[153];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[153];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F1060,fqv[156]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[157],module,F1061,fqv[158]);
	local[0]= fqv[157];
	local[1]= fqv[159];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[157];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[157];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[157];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F1062,fqv[160]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F1063,fqv[162]);
	local[0]= fqv[161];
	local[1]= fqv[163];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[161];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[161];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[161];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F1064,fqv[164]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F1065,fqv[166]);
	local[0]= fqv[165];
	local[1]= fqv[167];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[165];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[165];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[165];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F1066,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F1067,fqv[170]);
	local[0]= fqv[169];
	local[1]= fqv[171];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[169];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[169];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[169];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F1068,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F1069,fqv[174]);
	local[0]= fqv[173];
	local[1]= fqv[175];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[173];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[173];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[173];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F1070,fqv[176]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F1071,fqv[178]);
	local[0]= fqv[177];
	local[1]= fqv[179];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[177];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[177];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[177];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F1072,fqv[180]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F1073,fqv[182]);
	local[0]= fqv[181];
	local[1]= fqv[183];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[181];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[181];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[181];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F1074,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F1075,fqv[186]);
	local[0]= fqv[185];
	local[1]= fqv[187];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[185];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[185];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[185];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F1076,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F1077,fqv[190]);
	local[0]= fqv[189];
	local[1]= fqv[191];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[189];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[189];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[189];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F1078,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F1079,fqv[194]);
	local[0]= fqv[193];
	local[1]= fqv[195];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[193];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[193];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[193];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F1080,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F1081,fqv[198]);
	local[0]= fqv[197];
	local[1]= fqv[199];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[197];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[197];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[197];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F1082,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F1083,fqv[202]);
	local[0]= fqv[201];
	local[1]= fqv[203];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[201];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[201];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[201];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F1084,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F1085,fqv[206]);
	local[0]= fqv[205];
	local[1]= fqv[207];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[205];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[205];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[205];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F1086,fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F1087,fqv[210]);
	local[0]= fqv[209];
	local[1]= fqv[211];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[209];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[209];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[209];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F1088,fqv[212]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[213],module,F1089,fqv[214]);
	local[0]= fqv[213];
	local[1]= fqv[215];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[213];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[213];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[125]); /*remprop*/
	local[0]= fqv[213];
	local[1]= NIL;
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F1090,fqv[216]);
	local[0]= loadglobal(fqv[107]);
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL1414:
	if (local[3]==NIL) goto WHX1415;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car->c.obj.iv[4];
	local[5]= loadglobal(fqv[217]);
	ctx->vsp=local+6;
	w=(pointer)INTERN(ctx,2,local+4); /*intern*/
	local[4]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL1414;
WHX1415:
	local[4]= NIL;
BLK1416:
	w = NIL;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	local[3]= w;
	*(ovafptr(loadglobal(fqv[107]),fqv[218])) = local[3];
	w = local[2];
	local[0]= fqv[33];
	local[1]= fqv[219];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1418;
	local[0]= fqv[33];
	local[1]= fqv[219];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1420;
	local[0]= fqv[33];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[107]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1421;
IF1420:
	local[0]= NIL;
IF1421:
	local[0]= fqv[33];
	goto IF1419;
IF1418:
	local[0]= NIL;
IF1419:
	ctx->vsp=local+0;
	compfun(ctx,fqv[220],module,F1115,fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F1120,fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F1121,fqv[225]);
	local[0]= fqv[21];
	local[1]= fqv[103];
	local[2]= makeint(255);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[22];
	local[1]= fqv[103];
	local[2]= makeint(65280);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[23];
	local[1]= fqv[103];
	local[2]= makeint(16711680);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F1122,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F1123,fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1234,fqv[32],fqv[40],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1236,fqv[41],fqv[40],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1245,fqv[232],fqv[40],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1247,fqv[43],fqv[40],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1249,fqv[235],fqv[40],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1252,fqv[47],fqv[40],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1258,fqv[77],fqv[40],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1260,fqv[56],fqv[40],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1269,fqv[57],fqv[40],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1278,fqv[241],fqv[40],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1283,fqv[243],fqv[40],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1285,fqv[245],fqv[40],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1291,fqv[61],fqv[40],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1297,fqv[63],fqv[40],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1303,fqv[65],fqv[40],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1309,fqv[67],fqv[40],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1315,fqv[251],fqv[40],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1318,fqv[71],fqv[40],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1324,fqv[73],fqv[40],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1330,fqv[38],fqv[40],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1366,fqv[58],fqv[40],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1377,fqv[52],fqv[40],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1379,fqv[76],fqv[40],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1388,fqv[89],fqv[40],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1390,fqv[260],fqv[40],fqv[261]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[262],module,F1124,fqv[263]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[264],module,F1125,fqv[265]);
	local[0]= fqv[266];
	local[1]= fqv[267];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[268]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
