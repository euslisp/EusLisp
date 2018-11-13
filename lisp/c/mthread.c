/****************************************************************/
/* Multi-Thread support functions
/*	June 8,1994 (c) Toshihiro Matsui, Electrotechnical Laboratory
/*      added SunOS 4.1.x routine by H.Nakagaki at 29-Jun-1995
/*****************************************************************/
static char *rcsid="@(#)$Id$";
#if THREADED

#include "eus.h"

sema_t free_thread_sem;
pointer free_threads;
mutex_t free_thread_lock;
mutex_t qthread_lock;

/* from memory.c */
mutex_t alloc_lock;
rwlock_t gc_lock;

/* from sequence.c */
mutex_t qsort_lock;

/* from eus.c */
/* mutex locks*/
mutex_t mark_lock;
char *mark_locking;
int mark_lock_thread;


pointer get_free_thread()
{ register pointer port;
  GC_REGION(sema_wait(&free_thread_sem););
  mutex_lock(&free_thread_lock);
    port=ccar(free_threads);
    free_threads=ccdr(free_threads);
  mutex_unlock(&free_thread_lock);
  return(port);}

extern int next_special_index;

void thread_main(port)
pointer port;
{ pointer val, *spsave, argp;
  jmp_buf thjmp;
  context *ctx;
  unsigned int tid, argc;
  int i;
  pointer myspecs, reqspecs;

  tid=thr_self();

  if (tid>=MAXTHREAD) thr_exit(0); 
  ctx=(context *)((eusinteger_t)port->c.thrp.contex & ~2L);
  euscontexts[tid]=ctx;
/*  fprintf(stderr, "new thread %d port=%x ctx=%x\n", tid, port, ctx); */
  mkcatchframe(ctx, makeint(0),&thjmp);
  mutex_lock(&free_thread_lock);
    free_threads=cons(ctx,port, free_threads);
  mutex_unlock(&free_thread_lock);

thread_loop:
  sema_post(&free_thread_sem);
  port->c.thrp.idle=T;
  GC_REGION(sema_wait((sema_t *)(port->c.thrp.reqsem->c.ivec.iv)););
  port->c.thrp.idle=NIL;
  /*copy special bindings from the requester*/
  myspecs= ctx->specials;
  reqspecs= euscontexts[intval(port->c.thrp.requester)]->specials;
  for (i=0; i<next_special_index; i++) 
    myspecs->c.vec.v[i]= reqspecs->c.vec.v[i];
  sema_post((sema_t *)port->c.thrp.runsem->c.ivec.iv);

  /* funcall */
  if ((val=(pointer)eussetjmp(thjmp))==0) {
    spsave=ctx->vsp;
    argp=port->c.thrp.args;
    argc=0;
    while (argp!=NIL) {
      ckpush(ccar(argp)); argp=ccdr(argp); argc++;}
/*    fprintf(stderr, "ctx=%x port=%x func=%x arg=%x argc=%d\n",
		ctx,port,port->c.thrp.func,spsave,argc); */
    val=(pointer)ufuncall(ctx, port,
			port->c.thrp.func,(pointer)spsave,NULL,argc);
  }
  else if (val==(pointer)1) {
    val=makeint(0);	/*longjmp cannot return 0*/
    fprintf(stderr, "thread %d reset\n", tid);}
  port->c.thrp.result=val;
  if (port->c.thrp.wait!=NIL) {
    sema_post((sema_t *)port->c.thrp.donesem->c.ivec.iv);
    GC_REGION(sema_wait((sema_t *)port->c.thrp.reqsem->c.ivec.iv););
	/*wait for result-transfer ack*/
    }
  /* chain self in the free_thread list */
  mutex_lock(&free_thread_lock);
    free_threads=cons(ctx, port, free_threads);
  mutex_unlock(&free_thread_lock);
  goto thread_loop;
  /*never reaches here*/
  deletecontext(tid,ctx);
  }

pointer MAKE_THREAD(ctx, n, argv)
context *ctx;
int n;
pointer argv[];
{ int stack_size, c_stack_size;
  context *newctx;
  pointer newport, thrlist=NIL;
  int i,count;
  unsigned int tid;

  ckarg2(1,3);
  count=ckintval(argv[0]);
  if (n>=2) stack_size=ckintval(argv[1]);
  else stack_size=32*1024;	/* default stack=32K word */
  if (n==3) c_stack_size=ckintval(argv[2]);
  else c_stack_size=stack_size*sizeof(pointer);
  for (i=0; i<count; i++) {
    newctx=(context *)makelispcontext(stack_size);
    newport=(pointer)makethreadport(newctx);
    ckpush(newport);
    GC_REGION(mutex_lock(&qthread_lock););
#ifdef RGC
    active_mutator_num++;
#endif
    speval(QTHREADS)=cons(ctx, newport, speval(QTHREADS));
    mutex_unlock(&qthread_lock);
#if alpha || PTHREAD
    if( thr_create(0, c_stack_size, thread_main, newport, 0, &tid ) != 0 ) {
      deletecontext(tid, ctx);
      error(E_USER,(pointer)"Number of threads reached limit (64)");
      }
    newport->c.thrp.id=makeint(tid);	/* ???? critical region problem */
#else
    thr_create(0, c_stack_size, (void *(*)(void *))thread_main,
		newport, THR_SUSPENDED, &tid);
    if (tid>=MAXTHREAD) {
      deletecontext(tid, ctx);
      error(E_USER,(pointer)"Number of threads reached limit (64)");
      }
    newport->c.thrp.id=makeint(tid);
    thr_continue(tid);
#endif
    }
  thrlist=stacknlist(ctx,count);
  return(thrlist);}

pointer AFUNCALL(ctx, n, argv)
context *ctx;
int n;
pointer argv[];
{ register pointer port, args;
  register int i;
  port=get_free_thread();
  port->c.thrp.requester=makeint(thr_self());
  port->c.thrp.func=argv[0];
  args=NIL;
  for (i=1; i<n; i++) {  args=cons(ctx,argv[n-i],args);}
  port->c.thrp.args=args;
  port->c.thrp.wait=T;

  /*resume target thread*/
  sema_post((sema_t *)port->c.thrp.reqsem->c.ivec.iv);

  /*wait for the target start running*/
  /*the requester should wait for the copying thread-local special variables
    to be copied*/
  GC_REGION(sema_wait((sema_t *)port->c.thrp.runsem->c.ivec.iv););
  return(port);}

pointer AFUNCALL_NO_WAIT(ctx, n, argv)
context *ctx;
int n;
pointer argv[];
{ register pointer port, args;
  register int i;
  port=get_free_thread();
  port->c.thrp.requester=makeint(thr_self());
  port->c.thrp.func=argv[0];
  args=NIL;
  for (i=1; i<n; i++) {  args=cons(ctx,argv[n-i],args);}
  port->c.thrp.args=args;
  port->c.thrp.wait=NIL;
  sema_post((sema_t *)port->c.thrp.reqsem->c.ivec.iv);
  /*wait for the target start running*/
  /*the requester should wait for the copying thread-local special variables
    to be copied*/
  GC_REGION(sema_wait((sema_t *)port->c.thrp.runsem->c.ivec.iv););
  return(port);}

pointer WAIT_AFUNCALL(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ register pointer port, result;
  ckarg(1);
  port=argv[0];
  if (port->c.thrp.wait!=NIL &&
	(/* port->c.thrp.idle==NIL */ 1 || 
	 port->c.thrp.reqsem->c.ivec.iv[0]>0)) {
    GC_REGION(sema_wait((sema_t *)port->c.thrp.donesem->c.ivec.iv););
    result=port->c.thrp.result;
    sema_post((sema_t *)port->c.thrp.reqsem->c.ivec.iv);	/*ack result transfer*/
    return(result);}
  else error(E_USER,(pointer)"wait thread for idle thread");}

pointer FREE_THREADS(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ return(free_threads);}

/* mutex lock */

#if Linux && !Darwin 
#define PTHREAD_MUTEX_NORMAL PTHREAD_MUTEX_ADAPTIVE_NP 
#define PTHREAD_MUTEX_RECURSIVE PTHREAD_MUTEX_RECURSIVE_NP 
#define PTHREAD_MUTEX_ERRORCHECK PTHREAD_MUTEX_ERRORCHECK_NP 
#endif

pointer MAKE_MUTEX_LOCK(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ register pointer m;
  m=makevector(C_INTVECTOR, (sizeof(mutex_t)+sizeof(eusinteger_t)-1)/sizeof(eusinteger_t));
#if alpha 
  pthread_mutex_init((mutex_t *)m->c.ivec.iv,pthread_mutexattr_default);
#elif  PTHREAD
  {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    if (n==1 && isint(argv[0])) {
      pthread_mutexattr_settype(&attr, intval(argv[0]));
    }else{
      pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
    }
    pthread_mutex_init((mutex_t *)m->c.ivec.iv, &attr);
  }
#else
  mutex_init((mutex_t *)m->c.ivec.iv,USYNC_THREAD,0);
#endif
  return(m);}

pointer MUTEX_LOCK(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  if (!isintvector(argv[0])) error(E_NOINTVECTOR);
  mutex_lock((mutex_t *)argv[0]->c.ivec.iv);
  return(T);}

pointer MUTEX_TRYLOCK(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  if (!isintvector(argv[0])) error(E_NOINTVECTOR);
#if SunOS4_1
  if (mutex_trylock((mutex_t *)argv[0]->c.ivec.iv)==-1) return(NIL);
#else /* for Solaris2 */
  if (mutex_trylock((mutex_t *)argv[0]->c.ivec.iv)==EBUSY) return(NIL);
#endif
  return(T);}

pointer MUTEX_UNLOCK(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ ckarg(1);
  if (!isintvector(argv[0])) error(E_NOINTVECTOR);
  mutex_unlock((mutex_t *)argv[0]->c.ivec.iv);
  return(T);}

/* condition variable */

pointer MAKE_COND(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ register pointer m;
#if SunOS4_1
  ckarg(1);
#endif
  m=makevector(C_INTVECTOR, (sizeof(cond_t)+sizeof(eusinteger_t)-1)/sizeof(eusinteger_t));
#if alpha 
  pthread_cond_init((cond_t*)m->c.ivec.iv, pthread_condattr_default);
#elif PTHREAD
  pthread_cond_init((cond_t*)m->c.ivec.iv, NULL);
#else
#if SunOS4_1
  cond_init((cond_t *)m->c.ivec.iv, (mutex_t *)argv[0]->c.ivec.iv);
#else /* For Solaris2 */
  cond_init((cond_t *)m->c.ivec.iv,USYNC_THREAD,0);
#endif
#endif
  return(m);}

pointer COND_WAIT(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ ckarg(2);
  if (!isintvector(argv[0]) || !isintvector(argv[0])) error(E_NOINTVECTOR);
  cond_wait((cond_t *)argv[0]->c.ivec.iv, (mutex_t *)argv[1]->c.ivec.iv);
  return(T);}

pointer COND_SIGNAL(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ ckarg2(1,2);
  if (!isintvector(argv[0])) error(E_NOINTVECTOR);
  if (n==2 && argv[1]!=NIL) cond_broadcast((cond_t *)argv[0]->c.ivec.iv);
  else cond_signal((cond_t *)argv[0]->c.ivec.iv);
  return(T);}

/* semaphore */

pointer MAKE_SEMAPHORE(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer s;
  s=makevector(C_INTVECTOR, (sizeof(sema_t)+sizeof(eusinteger_t)-1)/sizeof(eusinteger_t));
  sema_init((sema_t *)s->c.ivec.iv, 0, USYNC_THREAD, 0);
  return(s);}

pointer SEMA_POST(ctx,n,argv)
context *ctx;
int n;
register pointer argv[];
{ if (!isintvector(argv[0])) error(E_NOINTVECTOR);
  sema_post((sema_t *)argv[0]->c.ivec.iv);
  return(T);}

pointer SEMA_WAIT(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ if (!isintvector(argv[0])) error(E_NOINTVECTOR);
  GC_REGION(sema_wait((sema_t *)argv[0]->c.ivec.iv););
  return(T);}

pointer SEMA_TRYWAIT(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ if (!isintvector(argv[0])) error(E_NOINTVECTOR);
  if (sema_trywait((sema_t *)argv[0]->c.ivec.iv)==0) return(T);
  else  return(NIL);}


pointer THR_SELF(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ 
  return(makeint(thr_self()));}

pointer THREAD_SELF(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ 
  return(euscontexts[thr_self()]->threadobj);}

pointer THR_SETPRIO(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stat;
  ckarg(2);
  stat=thr_setprio(ckintval(argv[0]),ckintval(argv[1]));
  if (stat) return(makeint(-errno));
  else return(T);}

pointer THR_GETPRIO(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stat,prio;
  ckarg(1);
  stat=thr_getprio(ckintval(argv[0]), &prio);
  if (stat) return(makeint(-errno));
  else return(makeint(prio));}

pointer THR_SETCONCURRENCY(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stat;
  ckarg(1);
#if SunOS4_1 || alpha || PTHREAD
  fprintf(stderr, "thr_setconcurrency is not supprted!\n");
  stat = 0;
#else
  stat=thr_setconcurrency(ckintval(argv[0]));
#endif
  if (stat) return(makeint(stat));
  else return(T);}

pointer THR_GETCONCURRENCY(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int concurrency;
  ckarg(0);
#if SunOS4_1 || alpha || PTHREAD
  fprintf(stderr, "thr_getconcurrency is not supprted!\n");
  concurrency = 0;
#else
  concurrency=thr_getconcurrency();
#endif
  return(makeint(concurrency));}

void newthread(ta)
struct thread_arg *ta;
{ int tid;
  pointer func,argv[1],result,val;
  jmp_buf thjmp;

  tid=thr_self();
  euscontexts[tid]=ta->newctx;
  fprintf(stderr,"new thread_id=%d\n",tid);
  mkcatchframe(ta->newctx, makeint(0),&thjmp);
  if ((val=(pointer)eussetjmp(thjmp))==0) {
    argv[0]=ta->arg;
    result=ufuncall(ta->newctx, ta->form, ta->func,(pointer)argv,NULL,1);}
  else if (val==(pointer)1) val=makeint(0);	/*longjmp cannot return 0*/
  fprintf(stderr, "thread %d terminated\n", tid);
  deletecontext(tid,ta->newctx);
  cfree(ta);
  }

pointer THR_CREATE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int stack_size,stat;
  context *newctx;
  unsigned int thread_id;
  pointer result;
  struct thread_arg *ta;
  pointer func=argv[0], arg=argv[1];

  ckarg2(2,3);
  if (n==3) stack_size=ckintval(argv[2]);
  else stack_size=1024*64;

  newctx=(context *)makelispcontext(stack_size);
  fprintf(stderr,"creater newcontext=%p\n", newctx);
  ta=(struct thread_arg *)malloc(sizeof(struct thread_arg));
  ta->form=ctx->callfp->form;
  ta->newctx=newctx;
  ta->func=func;
  ta->arg=arg;
  stat=thr_create(0, stack_size, (void (*)(void *))newthread,
		  ta,0,&thread_id);
  if (stat) result=makeint(-errno);
  else 
    result=makeint(thread_id);
  return(result);
  }

pointer THR_KILL(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int tid;
  int sig;
  ckarg(2);
  tid=ckintval(argv[0]);
  sig=ckintval(argv[1]);
  if (euscontexts[tid]) { thr_kill(tid,sig); return(T);}
  else return(NIL);}

pointer THR_SUSPEND(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int tid;
  ckarg(1);
#if alpha
  fprintf(stderr,"thr_suspend is not implemented.\n" );
  return(NIL);
#else
  tid=ckintval(argv[0]);
  if (euscontexts[tid]) {
    if (thr_suspend(tid)==0) return(T);
    else return(makeint(-errno));}
  else return(NIL);
#endif
}

pointer THR_CONTINUE(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int tid;
  ckarg(1);
#if alpha
  fprintf(stderr,"thr_continue is not implemented.\n");
  return(NIL);
#else
  tid=ckintval(argv[0]);
  if (euscontexts[tid]) {
    if (thr_continue(tid)==0) return(T);
    else return(makeint(-errno));}
  else return(NIL);
#endif
}

#if Solaris2
pointer THR_SIGSETMASK(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{ int how, stat;
  eusinteger_t *oset;

  ckarg2(2,3);
  how=ckintval(argv[0]);
  if (n==3) oset=argv[2]->c.ivec.iv;
  else oset=NULL;
  stat=thr_sigsetmask(how, argv[1]->c.ivec.iv, oset);
  if (stat==0) {
    if (n==3) return(argv[2]);
    else return(T);}
  else return(makeint(-errno));
  }
#endif  

int mthread(ctx,mod)
register context *ctx;
pointer mod;
{
  free_threads=NIL;

  defunpkg(ctx,"THR-SELF",mod,THR_SELF,unixpkg);
  defunpkg(ctx,"THR-GETPRIO",mod,THR_GETPRIO,unixpkg);
  defunpkg(ctx,"THR-SETPRIO",mod,THR_SETPRIO,unixpkg);
  defunpkg(ctx,"THR-GETCONCURRENCY",mod,THR_GETCONCURRENCY,unixpkg);
  defunpkg(ctx,"THR-SETCONCURRENCY",mod,THR_SETCONCURRENCY,unixpkg);
  defunpkg(ctx,"THR-CREATE",mod,THR_CREATE,unixpkg);
  defunpkg(ctx,"THR-KILL",mod,THR_KILL,unixpkg);
  defunpkg(ctx,"THR-SUSPEND",mod,THR_SUSPEND,unixpkg);
  defunpkg(ctx,"THR-CONTINUE",mod,THR_CONTINUE,unixpkg);
#if Solaris2
  defunpkg(ctx,"THR-SIGSETMASK",mod,THR_SIGSETMASK,unixpkg);
#endif

  defunpkg(ctx,"THREAD-SELF",mod,THREAD_SELF,syspkg);
  defunpkg(ctx,"MAKE-THREAD",mod,MAKE_THREAD,syspkg);
  defunpkg(ctx,"THREAD",mod,AFUNCALL, syspkg);
  defunpkg(ctx,"THREAD-NO-WAIT",mod,AFUNCALL_NO_WAIT, syspkg);
  defunpkg(ctx,"WAIT-THREAD",mod,WAIT_AFUNCALL,syspkg);
  defunpkg(ctx,"FREE-THREADS",mod,FREE_THREADS,syspkg);

  defunpkg(ctx,"MAKE-MUTEX-LOCK",mod,MAKE_MUTEX_LOCK,syspkg);
  defunpkg(ctx,"MUTEX-LOCK",mod, MUTEX_LOCK,syspkg);
  defunpkg(ctx,"MUTEX-UNLOCK",mod, MUTEX_UNLOCK,syspkg);
  defunpkg(ctx,"MUTEX-TRYLOCK",mod, MUTEX_TRYLOCK,syspkg);
#if PTHREAD
  defvar(ctx,"*PTHREAD-MUTEX-FAST*",makeint(PTHREAD_MUTEX_NORMAL),syspkg);
  defvar(ctx,"*PTHREAD-MUTEX-RECURSIVE*",makeint(PTHREAD_MUTEX_RECURSIVE),syspkg);
  defvar(ctx,"*PTHREAD-MUTEX-ERRORCHECK*",makeint(PTHREAD_MUTEX_ERRORCHECK),syspkg);
#endif

  defunpkg(ctx,"MAKE-COND",mod,MAKE_COND,syspkg);
  defunpkg(ctx,"COND-WAIT",mod, COND_WAIT,syspkg);
  defunpkg(ctx,"COND-SIGNAL",mod, COND_SIGNAL,syspkg);

  defunpkg(ctx,"MAKE-SEMAPHORE",mod,MAKE_SEMAPHORE,syspkg);
  defunpkg(ctx,"SEMA-POST",mod, SEMA_POST,syspkg);
  defunpkg(ctx,"SEMA-WAIT",mod, SEMA_WAIT,syspkg);
  defunpkg(ctx,"SEMA-TRYWAIT",mod, SEMA_TRYWAIT,syspkg);
  }

#endif	/* THREADED */
