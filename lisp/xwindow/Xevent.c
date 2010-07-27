/* Xevent.c :  entry=Xevent */
/* compiled by EusLisp 8.26 for Linux  created on 2005年 12月 12日 月曜日 12:31:29 JST */
#include "eus.h"
#include "Xevent.h"
#pragma init (register_Xevent)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xevent();
extern pointer build_quote_vector();
static register_Xevent()
  { add_module_initializer("___Xevent", ___Xevent);}

static pointer F1760();
static pointer F1761();
static pointer F1762();
static pointer F1763();
static pointer F1764();
static pointer F1765();
static pointer F1766();
static pointer F1767();
static pointer F1768();
static pointer F1769();
static pointer F1770();
static pointer F1771();
static pointer F1772();
static pointer F1773();
static pointer F1774();
static pointer F1775();
static pointer F1776();
static pointer F1777();
static pointer F1778();
static pointer F1779();
static pointer F1780();
static pointer F1781();
static pointer F1782();
static pointer F1783();
static pointer F1784();
static pointer F1785();
static pointer F1786();
static pointer F1787();
static pointer F1788();
static pointer F1789();
static pointer F1790();
static pointer F1791();
static pointer F1792();
static pointer F1793();
static pointer F1794();
static pointer F1795();
static pointer F1796();
static pointer F1797();
static pointer F1798();
static pointer F1799();
static pointer F1800();
static pointer F1801();
static pointer F1802();
static pointer F1803();
static pointer F1804();
static pointer F1805();
static pointer F1806();
static pointer F1807();
static pointer F1808();
static pointer F1809();
static pointer F1810();
static pointer F1811();
static pointer F1812();
static pointer F1813();
static pointer F1814();
static pointer F1815();
static pointer F1816();
static pointer F1817();
static pointer F1818();
static pointer F1819();
static pointer F1820();
static pointer F1821();
static pointer F1822();
static pointer F1823();
static pointer F1824();

/*xevent-type*/
static pointer F1760(ctx,n,argv,env)
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
BLK1825:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-type*/
static pointer F1761(ctx,n,argv,env)
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
BLK1826:
	ctx->vsp=local; return(local[0]);}

/*xevent-serial*/
static pointer F1762(ctx,n,argv,env)
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
BLK1827:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-serial*/
static pointer F1763(ctx,n,argv,env)
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
BLK1828:
	ctx->vsp=local; return(local[0]);}

/*xevent-send-event*/
static pointer F1764(ctx,n,argv,env)
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
BLK1829:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-send-event*/
static pointer F1765(ctx,n,argv,env)
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
BLK1830:
	ctx->vsp=local; return(local[0]);}

/*xevent-display*/
static pointer F1766(ctx,n,argv,env)
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
BLK1831:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-display*/
static pointer F1767(ctx,n,argv,env)
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
BLK1832:
	ctx->vsp=local; return(local[0]);}

/*xevent-window*/
static pointer F1768(ctx,n,argv,env)
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
BLK1833:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-window*/
static pointer F1769(ctx,n,argv,env)
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
BLK1834:
	ctx->vsp=local; return(local[0]);}

/*xevent-root*/
static pointer F1770(ctx,n,argv,env)
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
BLK1835:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-root*/
static pointer F1771(ctx,n,argv,env)
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
BLK1836:
	ctx->vsp=local; return(local[0]);}

/*xevent-subwindow*/
static pointer F1772(ctx,n,argv,env)
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
BLK1837:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-subwindow*/
static pointer F1773(ctx,n,argv,env)
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
BLK1838:
	ctx->vsp=local; return(local[0]);}

/*xevent-time*/
static pointer F1774(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(28);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1839:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-time*/
static pointer F1775(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(28);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1840:
	ctx->vsp=local; return(local[0]);}

/*xevent-x*/
static pointer F1776(ctx,n,argv,env)
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
BLK1841:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-x*/
static pointer F1777(ctx,n,argv,env)
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
BLK1842:
	ctx->vsp=local; return(local[0]);}

/*xevent-y*/
static pointer F1778(ctx,n,argv,env)
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
BLK1843:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-y*/
static pointer F1779(ctx,n,argv,env)
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
BLK1844:
	ctx->vsp=local; return(local[0]);}

/*xevent-x-root*/
static pointer F1780(ctx,n,argv,env)
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
BLK1845:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-x-root*/
static pointer F1781(ctx,n,argv,env)
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
BLK1846:
	ctx->vsp=local; return(local[0]);}

/*xevent-y-root*/
static pointer F1782(ctx,n,argv,env)
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
BLK1847:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-y-root*/
static pointer F1783(ctx,n,argv,env)
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
BLK1848:
	ctx->vsp=local; return(local[0]);}

/*xevent-state*/
static pointer F1784(ctx,n,argv,env)
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
BLK1849:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-state*/
static pointer F1785(ctx,n,argv,env)
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
BLK1850:
	ctx->vsp=local; return(local[0]);}

/*xevent-detail*/
static pointer F1786(ctx,n,argv,env)
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
BLK1851:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-detail*/
static pointer F1787(ctx,n,argv,env)
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
BLK1852:
	ctx->vsp=local; return(local[0]);}

/*xevent-same-screen*/
static pointer F1788(ctx,n,argv,env)
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
BLK1853:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-same-screen*/
static pointer F1789(ctx,n,argv,env)
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
BLK1854:
	ctx->vsp=local; return(local[0]);}

/*xevent-focus*/
static pointer F1790(ctx,n,argv,env)
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
BLK1855:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-focus*/
static pointer F1791(ctx,n,argv,env)
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
BLK1856:
	ctx->vsp=local; return(local[0]);}

/*xevent-alt-state*/
static pointer F1792(ctx,n,argv,env)
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
BLK1857:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-alt-state*/
static pointer F1793(ctx,n,argv,env)
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
BLK1858:
	ctx->vsp=local; return(local[0]);}

/*xevent-pad*/
static pointer F1794(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1861;}
	local[0]= NIL;
ENT1861:
ENT1860:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF1862;
	local[1]= argv[0];
	local[2]= makeint(68);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)PEEK(ctx,3,local+1); /*system:peek*/
	local[1]= w;
	goto IF1863;
IF1862:
	local[1]= argv[0];
	local[2]= makeint(68);
	local[3]= makeint(68);
	w = makeint(28);
#if sun4 || vax || mips || i386 || alpha
	w=(pointer)((integer_t)w-2);
#endif
	local[3]= (pointer)((integer_t)local[3] + (integer_t)w);
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
IF1863:
	w = local[1];
	local[0]= w;
BLK1859:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-pad*/
static pointer F1795(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1865:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF1866;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= makeint(68);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,3,local+1); /*system:poke*/
	local[1]= w;
	goto IF1867;
IF1866:
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[3];
	local[4]= makeint(68);
	local[5]= fqv[4];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,6,local+1,&ftab[0],fqv[5]); /*replace*/
	local[1]= w;
IF1867:
	w = local[1];
	local[0]= w;
BLK1864:
	ctx->vsp=local; return(local[0]);}

/*next-event*/
static pointer F1796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[6]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[7]); /*pending*/
	local[0]= w;
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON1870;
	local[0]= loadglobal(fqv[6]);
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[9]); /*nextevent*/
	local[0]= loadglobal(fqv[8]);
	goto CON1869;
CON1870:
	local[0]= NIL;
CON1869:
	w = local[0];
	local[0]= w;
BLK1868:
	ctx->vsp=local; return(local[0]);}

/*event-type*/
static pointer F1797(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[10];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1760(ctx,1,local+1); /*xevent-type*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
BLK1871:
	ctx->vsp=local; return(local[0]);}

/*event-x*/
static pointer F1798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1776(ctx,1,local+0); /*xevent-x*/
	local[0]= w;
BLK1872:
	ctx->vsp=local; return(local[0]);}

/*event-y*/
static pointer F1799(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1778(ctx,1,local+0); /*xevent-y*/
	local[0]= w;
BLK1873:
	ctx->vsp=local; return(local[0]);}

/*event-x-root*/
static pointer F1800(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1780(ctx,1,local+0); /*xevent-x-root*/
	local[0]= w;
BLK1874:
	ctx->vsp=local; return(local[0]);}

/*event-y-root*/
static pointer F1801(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1782(ctx,1,local+0); /*xevent-y-root*/
	local[0]= w;
BLK1875:
	ctx->vsp=local; return(local[0]);}

/*event-pos*/
static pointer F1802(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1776(ctx,1,local+0); /*xevent-x*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1778(ctx,1,local+1); /*xevent-y*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK1876:
	ctx->vsp=local; return(local[0]);}

/*event-key*/
static pointer F1803(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1786(ctx,1,local+0); /*xevent-detail*/
	local[0]= w;
BLK1877:
	ctx->vsp=local; return(local[0]);}

/*event-root-pos*/
static pointer F1804(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1780(ctx,1,local+0); /*xevent-x-root*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1782(ctx,1,local+1); /*xevent-y-root*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK1878:
	ctx->vsp=local; return(local[0]);}

/*event-width*/
static pointer F1805(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1776(ctx,1,local+0); /*xevent-x*/
	local[0]= w;
BLK1879:
	ctx->vsp=local; return(local[0]);}

/*event-height*/
static pointer F1806(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1778(ctx,1,local+0); /*xevent-y*/
	local[0]= w;
BLK1880:
	ctx->vsp=local; return(local[0]);}

/*event-time*/
static pointer F1807(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1774(ctx,1,local+0); /*xevent-time*/
	local[0]= w;
BLK1881:
	ctx->vsp=local; return(local[0]);}

/*event-window*/
static pointer F1808(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1768(ctx,1,local+0); /*xevent-window*/
	local[0]= w;
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[12]); /*gethash*/
	local[0]= w;
BLK1882:
	ctx->vsp=local; return(local[0]);}

/*event-button*/
static pointer F1809(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1786(ctx,1,local+0); /*xevent-detail*/
	local[0]= w;
BLK1883:
	ctx->vsp=local; return(local[0]);}

/*event-state*/
static pointer F1810(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1885;
	local[2]= fqv[13];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1886;
IF1885:
	local[2]= NIL;
IF1886:
	local[2]= local[0];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1887;
	local[2]= fqv[14];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1888;
IF1887:
	local[2]= NIL;
IF1888:
	local[2]= local[0];
	local[3]= makeint(8);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1889;
	local[2]= fqv[15];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1890;
IF1889:
	local[2]= NIL;
IF1890:
	local[2]= local[0];
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1891;
	local[2]= fqv[16];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1892;
IF1891:
	local[2]= NIL;
IF1892:
	local[2]= local[0];
	local[3]= makeint(512);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1893;
	local[2]= fqv[17];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1894;
IF1893:
	local[2]= NIL;
IF1894:
	local[2]= local[0];
	local[3]= makeint(1024);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1895;
	local[2]= fqv[18];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1896;
IF1895:
	local[2]= NIL;
IF1896:
	w = local[1];
	local[0]= w;
BLK1884:
	ctx->vsp=local; return(local[0]);}

/*event-shift*/
static pointer F1811(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1897:
	ctx->vsp=local; return(local[0]);}

/*event-control*/
static pointer F1812(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1898:
	ctx->vsp=local; return(local[0]);}

/*event-meta*/
static pointer F1813(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1899:
	ctx->vsp=local; return(local[0]);}

/*event-left*/
static pointer F1814(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(256);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1900:
	ctx->vsp=local; return(local[0]);}

/*event-middle*/
static pointer F1815(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(512);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1901:
	ctx->vsp=local; return(local[0]);}

/*event-right*/
static pointer F1816(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(1024);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1902:
	ctx->vsp=local; return(local[0]);}

/*event-pressed*/
static pointer F1817(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1905;}
	local[0]= NIL;
ENT1905:
ENT1904:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF1906;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1792(ctx,1,local+1); /*xevent-alt-state*/
	local[1]= w;
	goto IF1907;
IF1906:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1784(ctx,1,local+1); /*xevent-state*/
	local[1]= w;
IF1907:
	local[2]= makeint(1792);
	ctx->vsp=local+3;
	w=(pointer)LOGTEST(ctx,2,local+1); /*logtest*/
	local[0]= w;
BLK1903:
	ctx->vsp=local; return(local[0]);}

/*print-event*/
static pointer F1818(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= T;
	local[4]= fqv[19];
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)F1762(ctx,1,local+5); /*xevent-serial*/
	local[5]= w;
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)F1797(ctx,1,local+6); /*event-type*/
	local[6]= w;
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1808(ctx,1,local+7); /*event-window*/
	local[7]= w;
	local[8]= fqv[20];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(pointer)F1802(ctx,1,local+8); /*event-pos*/
	local[8]= w;
	local[9]= loadglobal(fqv[8]);
	ctx->vsp=local+10;
	w=(pointer)F1810(ctx,1,local+9); /*event-state*/
	local[9]= w;
	local[10]= loadglobal(fqv[8]);
	ctx->vsp=local+11;
	w=(pointer)F1784(ctx,1,local+10); /*xevent-state*/
	local[10]= w;
	local[11]= loadglobal(fqv[8]);
	ctx->vsp=local+12;
	w=(pointer)F1803(ctx,1,local+11); /*event-key*/
	local[11]= w;
	local[12]= loadglobal(fqv[8]);
	ctx->vsp=local+13;
	w=(pointer)F1774(ctx,1,local+12); /*xevent-time*/
	local[12]= w;
	local[13]= makeflt(1.00000000e+03);
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,10,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1908:
	ctx->vsp=local; return(local[0]);}

/*display-events*/
static pointer F1819(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[6]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[21]); /*sync*/
WHL1910:
	if (T==NIL) goto WHX1911;
	local[0]= loadglobal(fqv[6]);
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[9]); /*nextevent*/
	local[0]= loadglobal(fqv[8]);
	ctx->vsp=local+1;
	w=(pointer)F1818(ctx,1,local+0); /*print-event*/
	local[0]= loadglobal(fqv[8]);
	ctx->vsp=local+1;
	w=(pointer)F1797(ctx,1,local+0); /*event-type*/
	local[0]= w;
	local[1]= fqv[22];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1913;
	local[0]= loadglobal(fqv[8]);
	ctx->vsp=local+1;
	w=(pointer)F1803(ctx,1,local+0); /*event-key*/
	local[0]= w;
	local[1]= makeint(103);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1913;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK1909;
	goto IF1914;
IF1913:
	local[0]= NIL;
IF1914:
	goto WHL1910;
WHX1911:
	local[0]= NIL;
BLK1912:
	w = local[0];
	local[0]= w;
BLK1909:
	ctx->vsp=local; return(local[0]);}

/*:event-notify-print*/
static pointer M1915(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= T;
	local[4]= fqv[23];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1916:
	ctx->vsp=local; return(local[0]);}

/*:event-notify-dispatch*/
static pointer M1917(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= argv[0];
	local[4]= argv[2];
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1918:
	ctx->vsp=local; return(local[0]);}

/*:event-notify*/
static pointer M1919(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (argv[0]->c.obj.iv[11]==NIL) goto CON1922;
	local[3]= argv[0]->c.obj.iv[11];
	local[4]= fqv[24];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON1921;
CON1922:
	local[3]= argv[2];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[26]); /*member*/
	if (w==NIL) goto CON1923;
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON1921;
CON1923:
	local[3]= argv[2];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[26]); /*member*/
	if (w==NIL) goto CON1924;
	local[3]= argv[2];
	if (fqv[29]!=local[3]) goto IF1925;
	local[3]= loadglobal(fqv[30]);
	local[4]= loadglobal(fqv[31]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF1925;
	local[3]= loadglobal(fqv[30]);
	local[4]= fqv[29];
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1926;
IF1925:
	local[3]= NIL;
IF1926:
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON1921;
CON1924:
	local[3]= NIL;
CON1921:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1920:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M1927(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1929;
	local[3]= fqv[33];
	local[4]= fqv[22];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1930;
IF1929:
	local[3]= NIL;
IF1930:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1928:
	ctx->vsp=local; return(local[0]);}

/*:keypress*/
static pointer M1931(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= loadglobal(fqv[8]);
	local[4]= loadglobal(fqv[35]);
	local[5]= makeint(1);
	local[6]= makeint(0);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,5,local+3,&ftab[7],fqv[36]); /*lookupstring*/
	local[3]= w;
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF1933;
	local[3]= argv[0];
	local[4]= fqv[37];
	local[5]= loadglobal(fqv[35]);
	{ register integer_t i=intval(makeint(0));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF1934;
IF1933:
	local[3]= NIL;
IF1934:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1932:
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M1935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1938;}
	local[0]= NIL;
ENT1938:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT1937:
	if (n>4) maerror();
	if (loadglobal(fqv[32])==NIL) goto IF1939;
	local[3]= fqv[38];
	local[4]= fqv[37];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1940;
IF1939:
	local[3]= NIL;
IF1940:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1936:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M1941(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1943;
	local[3]= fqv[39];
	local[4]= fqv[40];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= loadglobal(fqv[8]);
	ctx->vsp=local+4;
	w=(pointer)F1810(ctx,1,local+3); /*event-state*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[3]= w;
	goto IF1944;
IF1943:
	local[3]= NIL;
IF1944:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1942:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M1945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1947;
	local[3]= fqv[41];
	local[4]= fqv[29];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1948;
IF1947:
	local[3]= NIL;
IF1948:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1946:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M1949(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1951;
	local[3]= fqv[42];
	local[4]= fqv[43];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1952;
IF1951:
	local[3]= NIL;
IF1952:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1950:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M1953(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1955;
	local[3]= fqv[44];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1956;
IF1955:
	local[3]= NIL;
IF1956:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1954:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M1957(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1959;
	local[3]= fqv[46];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1960;
IF1959:
	local[3]= NIL;
IF1960:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1958:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M1961(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1963;
	local[3]= fqv[48];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1964;
IF1963:
	local[3]= NIL;
IF1964:
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[50];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	if (T==NIL) goto IF1965;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,2,local+5,&ftab[8],fqv[51]); /*/=*/
	local[5]= w;
	if (w!=NIL) goto OR1967;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,2,local+5,&ftab[8],fqv[51]); /*/=*/
	local[5]= w;
OR1967:
	argv[0]->c.obj.iv[5] = local[3];
	argv[0]->c.obj.iv[6] = local[4];
	local[5]= argv[0];
	local[6]= fqv[52];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	goto IF1966;
IF1965:
	local[5]= NIL;
IF1966:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1962:
	ctx->vsp=local; return(local[0]);}

/*:configurerequest*/
static pointer M1968(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= fqv[53];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1969:
	ctx->vsp=local; return(local[0]);}

/*:expose*/
static pointer M1970(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= argv[0];
	local[4]= fqv[52];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1971:
	ctx->vsp=local; return(local[0]);}

/*:visibilitynotify*/
static pointer M1972(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1973:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M1974(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[54];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[34]); /*warn*/
	local[0]= w;
BLK1975:
	ctx->vsp=local; return(local[0]);}

/*process-event*/
static pointer F1820(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= loadglobal(fqv[8]);
	ctx->vsp=local+4;
	w=(pointer)F1808(ctx,1,local+3); /*event-window*/
	local[3]= w;
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)F1797(ctx,1,local+4); /*event-type*/
	local[4]= w;
	if (loadglobal(fqv[32])==NIL) goto IF1977;
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)F1818(ctx,1,local+5); /*print-event*/
	local[5]= w;
	goto IF1978;
IF1977:
	local[5]= NIL;
IF1978:
	local[5]= local[3];
	local[6]= loadglobal(fqv[31]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF1979;
	local[5]= local[3];
	local[6]= fqv[24];
	local[7]= local[4];
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF1980;
IF1979:
	local[5]= NIL;
IF1980:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1976:
	ctx->vsp=local; return(local[0]);}

/*window-main-one*/
static pointer F1821(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT1983;}
	local[0]= NIL;
ENT1983:
ENT1982:
	if (n>1) maerror();
	{jmp_buf jb;
	w = fqv[55];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT1984;}
WHL1985:
	local[7]= loadglobal(fqv[6]);
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,2,local+7,&ftab[9],fqv[56]); /*eventsqueued*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto WHX1986;
	local[7]= loadglobal(fqv[6]);
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*nextevent*/
	if (loadglobal(fqv[57])==NIL) goto IF1988;
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1818(ctx,1,local+7); /*print-event*/
	local[7]= w;
	goto IF1989;
IF1988:
	local[7]= NIL;
IF1989:
	if (loadglobal(fqv[58])==NIL) goto IF1990;
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1797(ctx,1,local+7); /*event-type*/
	local[7]= w;
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto IF1990;
WHL1992:
	local[7]= loadglobal(fqv[6]);
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[7]); /*pending*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto WHX1993;
	local[7]= loadglobal(fqv[6]);
	local[8]= loadglobal(fqv[59]);
	ctx->vsp=local+9;
	w=(*ftab[10])(ctx,2,local+7,&ftab[10],fqv[60]); /*peekevent*/
	local[7]= loadglobal(fqv[59]);
	ctx->vsp=local+8;
	w=(pointer)F1797(ctx,1,local+7); /*event-type*/
	local[7]= w;
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto WHX1993;
	local[7]= loadglobal(fqv[6]);
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*nextevent*/
	local[7]= (pointer)((integer_t)(loadglobal(fqv[61]))+4);
	storeglobal(fqv[61],local[7]);
	goto WHL1992;
WHX1993:
	local[7]= NIL;
BLK1994:
	goto IF1991;
IF1990:
	local[7]= NIL;
IF1991:
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1820(ctx,1,local+7); /*process-event*/
	goto WHL1985;
WHX1986:
	local[7]= NIL;
BLK1987:
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,0,local+7,&ftab[11],fqv[62]); /*xflush*/
CAT1984:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK1981:
	ctx->vsp=local; return(local[0]);}

/*window-main-loop*/
static pointer F1995(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST1997:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]!=NIL) goto IF1998;
	local[1]= fqv[63];
	local[2]= fqv[21];
	local[3]= fqv[6];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[65];
	local[4]= fqv[55];
	local[5]= fqv[66];
	local[6]= fqv[67];
	local[7]= fqv[68];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[21];
	local[7]= fqv[6];
	local[8]= fqv[69];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[62];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF1999;
IF1998:
	local[1]= fqv[63];
	local[2]= fqv[21];
	local[3]= fqv[6];
	local[4]= fqv[70];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[65];
	local[4]= fqv[55];
	local[5]= fqv[66];
	local[6]= fqv[67];
	local[7]= fqv[71];
	local[8]= fqv[72];
	local[9]= fqv[7];
	local[10]= fqv[6];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[73];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[9];
	local[10]= fqv[6];
	local[11]= fqv[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[74];
	local[11]= fqv[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[67];
	w = local[0];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[21];
	local[5]= fqv[6];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[62];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF1999:
	w = local[1];
	local[0]= w;
BLK1996:
	ctx->vsp=local; return(local[0]);}

/*wml*/
static pointer F2000(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2002:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[76];
	w = local[0];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK2001:
	ctx->vsp=local; return(local[0]);}

/*wmlerror*/
static pointer F1822(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2005;}
	local[0]= NIL;
ENT2005:
ENT2004:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[77]);
	local[2]= fqv[78];
	local[3]= loadglobal(fqv[79]);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	if (local[0]==NIL) goto IF2006;
	local[1]= loadglobal(fqv[77]);
	local[2]= fqv[80];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF2007;
IF2006:
	local[1]= NIL;
IF2007:
	if (argv[2]==NIL) goto IF2008;
	local[1]= loadglobal(fqv[77]);
	local[2]= fqv[81];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF2009;
IF2008:
	local[1]= NIL;
IF2009:
	local[1]= loadglobal(fqv[77]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= fqv[82];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK2003:
	ctx->vsp=local; return(local[0]);}

/*display-fd*/
static pointer F1823(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2012;}
	local[0]= loadglobal(fqv[6]);
ENT2012:
ENT2011:
	if (n>1) maerror();
	if (local[0]==NIL) goto IF2013;
	local[1]= local[0];
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,2,local+1); /*system:peek*/
	local[1]= w;
	goto IF2014;
IF2013:
	local[1]= NIL;
IF2014:
	w = local[1];
	local[0]= w;
BLK2010:
	ctx->vsp=local; return(local[0]);}

/*repwin*/
static pointer F1824(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F1823(ctx,0,local+0); /*display-fd*/
	local[0]= w;
	local[1]= NIL;
	local[2]= T;
WHL2016:
	if (T==NIL) goto WHX2017;
	if (local[2]==NIL) goto IF2019;
	local[3]= loadglobal(fqv[83]);
	local[4]= fqv[84];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= loadglobal(fqv[83]);
	ctx->vsp=local+4;
	w=(pointer)FINOUT(ctx,1,local+3); /*finish-output*/
	local[3]= w;
	goto IF2020;
IF2019:
	local[3]= NIL;
IF2020:
	local[2] = NIL;
	local[3]= loadglobal(fqv[85]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= makeflt(1.00000000e+01);
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[86]); /*select-stream*/
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= loadglobal(fqv[85]);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON2022;
	local[3]= loadglobal(fqv[85]);
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[2] = T;
	local[3]= local[2];
	goto CON2021;
CON2022:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON2023;
	ctx->vsp=local+3;
	w=(pointer)F1821(ctx,0,local+3); /*window-main-one*/
	local[3]= w;
	goto CON2021;
CON2023:
	local[3]= (pointer)((integer_t)(loadglobal(fqv[87]))+4);
	storeglobal(fqv[87],local[3]);
	goto CON2021;
CON2024:
	local[3]= NIL;
CON2021:
	goto WHL2016;
WHX2017:
	local[3]= NIL;
BLK2018:
	w = local[3];
	local[0]= w;
BLK2015:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xevent(ctx,n,argv,env)
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
	local[0]= fqv[88];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2025;
	local[0]= fqv[89];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[90],w);
	goto IF2026;
IF2025:
	local[0]= fqv[91];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2026:
	local[0]= fqv[92];
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[94]); /*require*/
	local[0]= fqv[95];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[57];
	local[1]= fqv[96];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[97];
	local[1]= fqv[96];
	local[2]= fqv[97];
	local[3]= fqv[98];
	local[4]= loadglobal(fqv[99]);
	local[5]= fqv[100];
	local[6]= fqv[101];
	local[7]= fqv[102];
	local[8]= loadglobal(fqv[103]);
	local[9]= fqv[104];
	local[10]= fqv[2];
	local[11]= fqv[105];
	local[12]= makeint(-1);
	local[13]= fqv[106];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[14])(ctx,13,local+2,&ftab[14],fqv[107]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[97]);
	local[1]= fqv[108];
	local[2]= fqv[109];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[110],module,F1760,fqv[111]);
	local[0]= fqv[110];
	local[1]= fqv[112];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[110];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[110];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[110];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[112],module,F1761,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F1762,fqv[120]);
	local[0]= fqv[119];
	local[1]= fqv[121];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[119];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[119];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[119];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F1763,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F1764,fqv[124]);
	local[0]= fqv[123];
	local[1]= fqv[125];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[123];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[123];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[123];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F1765,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F1766,fqv[128]);
	local[0]= fqv[127];
	local[1]= fqv[129];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[127];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[127];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[127];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F1767,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F1768,fqv[132]);
	local[0]= fqv[131];
	local[1]= fqv[133];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[131];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[131];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[131];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F1769,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F1770,fqv[136]);
	local[0]= fqv[135];
	local[1]= fqv[137];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[135];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[135];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[135];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F1771,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F1772,fqv[140]);
	local[0]= fqv[139];
	local[1]= fqv[141];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[139];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[139];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[139];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F1773,fqv[142]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F1774,fqv[144]);
	local[0]= fqv[143];
	local[1]= fqv[145];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[143];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[143];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[143];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F1775,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F1776,fqv[148]);
	local[0]= fqv[147];
	local[1]= fqv[149];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[147];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[147];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[147];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F1777,fqv[150]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F1778,fqv[152]);
	local[0]= fqv[151];
	local[1]= fqv[153];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[151];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[151];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[151];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F1779,fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F1780,fqv[156]);
	local[0]= fqv[155];
	local[1]= fqv[157];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[155];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[155];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[155];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[157],module,F1781,fqv[158]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F1782,fqv[160]);
	local[0]= fqv[159];
	local[1]= fqv[161];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[159];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[159];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[159];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F1783,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F1784,fqv[164]);
	local[0]= fqv[163];
	local[1]= fqv[165];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[163];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[163];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[163];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F1785,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F1786,fqv[168]);
	local[0]= fqv[167];
	local[1]= fqv[169];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[167];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[167];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[167];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F1787,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F1788,fqv[172]);
	local[0]= fqv[171];
	local[1]= fqv[173];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[171];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[171];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[171];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F1789,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F1790,fqv[176]);
	local[0]= fqv[175];
	local[1]= fqv[177];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[175];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[175];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[175];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F1791,fqv[178]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F1792,fqv[180]);
	local[0]= fqv[179];
	local[1]= fqv[181];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[179];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[179];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[179];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F1793,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F1794,fqv[184]);
	local[0]= fqv[183];
	local[1]= fqv[185];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[183];
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[183];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[115]); /*remprop*/
	local[0]= fqv[183];
	local[1]= NIL;
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F1795,fqv[186]);
	local[0]= fqv[8];
	local[1]= fqv[96];
	local[2]= loadglobal(fqv[97]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[59];
	local[1]= fqv[96];
	local[2]= loadglobal(fqv[97]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F1796,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F1797,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F1798,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F1799,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F1800,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F1801,fqv[198]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F1802,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F1803,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F1804,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F1805,fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F1806,fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F1807,fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F1808,fqv[212]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[213],module,F1809,fqv[214]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F1810,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[217],module,F1811,fqv[218]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F1812,fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F1813,fqv[222]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[223],module,F1814,fqv[224]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[225],module,F1815,fqv[226]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[227],module,F1816,fqv[228]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[229],module,F1817,fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F1818,fqv[232]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F1819,fqv[234]);
	local[0]= fqv[35];
	local[1]= fqv[96];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,1,local+2,&ftab[16],fqv[235]); /*make-string*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1915,fqv[236],fqv[31],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1917,fqv[27],fqv[31],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1919,fqv[24],fqv[31],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1927,fqv[22],fqv[31],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1931,fqv[241],fqv[31],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1935,fqv[37],fqv[31],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1941,fqv[40],fqv[31],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1945,fqv[29],fqv[31],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1949,fqv[43],fqv[31],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1953,fqv[45],fqv[31],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1957,fqv[47],fqv[31],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1961,fqv[249],fqv[31],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1968,fqv[251],fqv[31],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1970,fqv[253],fqv[31],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1972,fqv[255],fqv[31],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1974,fqv[52],fqv[31],fqv[257]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F1820,fqv[258]);
	local[0]= fqv[61];
	local[1]= fqv[96];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[58];
	local[1]= fqv[96];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F1821,fqv[259]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[76],module,F1995,fqv[260]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[261],module,F2000,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F1822,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F1823,fqv[266]);
	local[0]= fqv[87];
	local[1]= fqv[267];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2027;
	local[0]= fqv[87];
	local[1]= fqv[267];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[87];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2029;
	local[0]= fqv[87];
	local[1]= fqv[96];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2030;
IF2029:
	local[0]= NIL;
IF2030:
	local[0]= fqv[87];
	goto IF2028;
IF2027:
	local[0]= NIL;
IF2028:
	ctx->vsp=local+0;
	compfun(ctx,fqv[268],module,F1824,fqv[269]);
	local[0]= fqv[270];
	local[1]= fqv[271];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[272]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<18; i++) ftab[i]=fcallx;
}
