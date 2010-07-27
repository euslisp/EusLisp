#if Solaris2
static pmark(p)
register pointer p;
{ pointer gcstack[32768];
/*  fprintf(stderr, "pmark: th=%d p=%x\n", thr_self(), p); */
  mark(p,gcstack);}

static pmarkcontext(ctx)
register context *ctx;
{ register pointer *p;
  pointer gcstack[32768];
  for (p=ctx->stack; p<ctx->vsp; p++)
    if (ispointer(*p) && 
	    ((ctx->stack> (pointer *)*p) || ((pointer *)*p>ctx->stacklimit)))
	{  mark(*p,gcstack); } ;
  mark(ctx->lastalloc,gcstack);}

static pmarkall()
{ register pointer p;
  register int i=0,j=0;
  register context *ctx;
  thread_t tid[512];
  thr_create(0, 150*1024, pmark, sysobj, THR_BOUND, &tid[j++]);
/*  p=pkglist;
  while (p!=NIL) {
    thr_create(0, 150*1024, pmark, ccar(p), THR_BOUND, &tid[j++]);
    p=ccdr(p);} */
  thr_create(0, 150*1024, pmark, pkglist, THR_BOUND, &tid[j++]);
  for (i=0; i<MAXTHREAD; i++) {
    if (ctx=euscontexts[i]) 
      thr_create(0, 150*1024, pmarkcontext, ctx, THR_BOUND, &tid[j++]);
    }
  for (i=0; i<MAXCLASS; i++) {
    p=classtab[i].def;
    if (p && ispointer(p)) pmark(p); }
  /* pmark(pkglist); */
  if (debug) fprintf(stderr, ";; gc-threads=%d\n", j);
  for (i=0; i<j; i++) thr_join(tid[i], 0, 0);
  }
#endif


/*#if Solaris2
  if (spevalof(QPARAGC)==NIL)  markall();
  else pmarkall();
  #else
  #endif */


