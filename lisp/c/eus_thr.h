/*
 * EusLisp multithread support
 *
 *	EusLisp is written using Solaris2's thread library.
 *	This file is provided to emulate the library in other environment.
 *
 *	alpha porting team (APT)		Jan.1996
 */

#include <errno.h>

#if Solaris2
#include <synch.h>
#include <thread.h>
#endif

#if SunOS4_1
#include <lwp/lwp.h>
#include <lwp/lwpmachdep.h>
#include <lwp/stackdep.h>
#define	USYNC_THREAD	0
#endif

#if alpha || PTHREAD
#include <pthread.h>
#undef CATCH
#define	USYNC_THREAD	0
#endif

struct thread_arg {
  context *newctx;
  pointer form;
  pointer func;
  pointer arg;};


/*
 *  MT-library specific parts
 */

#ifdef __cplusplus
extern "C" {
#endif
/* SunOS4.1.x specific part */

#if SunOS4_1
/* mthread type for SunOS 4.1.x added by H.Nakagaki */
typedef mon_t mutex_t;
typedef cv_t  cond_t;

/* lwp functions are redefined to mthread functions by H.Nakagaki */
#define USYNC_THREAD       0
#define THR_SUSPENDED      LWPSUSPEND
#define thr_exit(x)        pod_exit(x)
#define thr_join(x,y,z)    lwp_join(x)
#define mutex_init(x,y,z)  mon_create(x)
#define mutex_destroy(x)   mon_destroy(*(x))
#define mutex_lock(x)      mon_enter(*(x))
#define mutex_unlock(x)    mon_exit(*(x))
#define mutex_trylock(x)   mon_cond_enter(*(x))
#define cond_init(x,y)     cv_create(x,*(y))
#define cond_destroy(x)    cv_destroy(*(x))
#define cond_wait(x,y)     cv_wait(*(x))
#define cond_signal(x)     cv_notify(*(x))
#define cond_broadcast(x)  cv_broadcast(*(x))
#endif	/* SunOS4_1 */


/* Alpha specific part */

#if alpha || PTHREAD
#ifndef __COLLECTOR_H /* R.Hanai */
typedef	pthread_t	thread_t;
typedef	pthread_mutex_t	mutex_t;
typedef	pthread_cond_t	cond_t;
#define thr_exit(x)	pthread_exit(x)
#define thr_join(x,y,z)	pthread_join(x,z)
#define	mutex_init(x,y,z)	pthread_mutex_init(x,y)
#define	mutex_lock	pthread_mutex_lock
#define	mutex_trylock	pthread_mutex_trylock
#define	mutex_unlock	pthread_mutex_unlock
#define	cond_wait	pthread_cond_wait
#define	cond_signal	pthread_cond_signal
#define	cond_broadcast	pthread_cond_broadcast
#endif
#endif	/* alpha */


/*
 * common part (for environment other than Solaris2)
 */

#if !Solaris2

/* type definition */
typedef struct _sema {
        unsigned int count;
	mutex_t      lock;
	cond_t       cond;
      } sema_t;
typedef struct _rwlock {
        unsigned int readers;
	mutex_t      lock;
	cond_t       r_cond;
	cond_t       w_cond;
      } rwlock_t;

/* function prototype */
/* lwp functions are redefined to mthread functions by H.Nakagaki */
extern unsigned int thr_self();
extern int thr_getprio(int tid, int *prio);
extern int thr_create(void *, size_t, void (*)(), void *, long, int *);
extern int thr_setprio(int, int);
extern int thr_continue(int);
extern int thr_suspend(int);
extern int thr_kill(int, int);

/* readers/writer lock function definition added by H.Nakagaki */
extern int rwlock_init(rwlock_t *, int, void *);
extern int rwlock_destroy(rwlock_t *);
extern int rw_rdlock(rwlock_t *);
extern int rw_wrlock(rwlock_t *);
extern int rw_unlock(rwlock_t *);

/* semaphore function defined at mthread.c added by H.Nakagaki */
extern int sema_init(sema_t *, unsigned int, int, void *);
extern int sema_destroy(sema_t *);
extern int sema_port(sema_t *);
extern int sema_wait(sema_t *);
extern int sema_trywait(sema_t *);

extern int mthread(context *ctx, pointer mod);
#endif	/* !Solaris2 */
#if PTHREAD
extern int sema_post(sema_t *sem);
extern void mthread_init( context *mainctx );
#endif

/*
 * EusLisp variables
 */

/* mutex locks*/
extern mutex_t  mark_lock;
extern char     *mark_locking;
extern int      mark_lock_thread;
//extern mutex_t  p_mark_lock;
extern rwlock_t gc_lock;

extern mutex_t  alloc_lock;
extern mutex_t  free_thread_lock;
extern mutex_t  qthread_lock;
extern mutex_t  qsort_lock;
extern sema_t   free_thread_sem;
#ifdef __cplusplus
}
#endif
