#if alpha
#include "eus.h"

/*
 * Most functions in thread library of Solaris2 return Zero on success.
 */

/* thread function for OSF/1 */
static struct {
    int using;
    thread_t tid;
} thread_table[MAXTHREAD];

int thr_self()
{
    int i;
    thread_t tid;

    tid = pthread_self();
    for( i = 0; i < MAXTHREAD && !pthread_equal(thread_table[i].tid,tid); i++ )
      ;

    return( i );
}

int thr_getprio( int tid, int *prio )
{
    *prio = pthread_getprio( thread_table[tid].tid );
    if( *prio == -1 )
      return errno;
    else
      return ESUCCESS;
}

int thr_setprio(int tid, int prio)
{
    if( pthread_setprio( thread_table[tid].tid, prio ) == -1 )
      return errno;
    else
      return ESUCCESS;
}

struct thr_arg {
    int tid;
    void (*func)();
    void *args;
};

static void thr_cleanup( struct thr_arg *arg )
{
    thread_table[arg->tid].using = 0;

    free(arg);
}

static void thr_startup( struct thr_arg *arg )
{
    printf( "thr_startup:tid=%d\n", arg->tid );

    pthread_cleanup_push( thr_cleanup, arg );

    pthread_setcancel( CANCEL_ON );
    pthread_setasynccancel( CANCEL_ON );

    (arg->func)( arg->args );

    pthread_cleanup_pop( 1 );
}

int thr_create(void *base, size_t size, void (*func)(), void *args, long flags, int *tid )
/* base is not used */
/* size is not implemented */
/* flags is not used */
{
    int i, stat;
    struct thr_arg *arg;

    for( i = 0; i < MAXTHREAD && thread_table[i].using; i++ )
      ;
    if( i >= MAXTHREAD )
      return -1;

    if( (arg = (struct thr_arg *)malloc( sizeof(struct thr_arg) )) == NULL )
      return -1;

    arg->tid = i;
    arg->func = func;
    arg->args = args;
    stat = pthread_create( &thread_table[i].tid, pthread_attr_default, (pthread_startroutine_t)thr_startup, (pthread_addr_t)arg );
    if( stat == 0 )
      thread_table[i].using = 1;
    *tid = i;
    return( stat );
}

/*
   thr_suspend() and thr_continue() are not implemented.
   these routines are only defined to avoid prototype definition error.
 */
int thr_suspend( int tid ) { return -1; }
int thr_continue( int tid ) { return -1; }

int thr_kill( int tid, int sig )
/* sig is not used */
{
    if( pthread_cancel( thread_table[tid].tid ) < 0 )
      return errno;
    else
      return ESUCCESS;
}

/* readers/writer lock functions for OSF/1 */
int rwlock_init(rwlock_t *rwlp, int type, void *arg)
{
    pthread_mutex_init(&(rwlp->lock), pthread_mutexattr_default);
    pthread_cond_init(&(rwlp->r_cond), pthread_condattr_default);
    pthread_cond_init(&(rwlp->w_cond), pthread_condattr_default);

    rwlp->readers = 0;

    return 0;
}

int rwlock_destroy( rwlock_t *rwlp )
{
    pthread_mutex_destroy( &(rwlp->lock) );
    pthread_cond_destroy( &(rwlp->r_cond) );
    pthread_cond_destroy( &(rwlp->w_cond) );

    return 0;
}

int rw_rdlock( rwlock_t *rwlp )
{
    pthread_mutex_lock( &(rwlp->lock) );
    while( rwlp->readers == -1 )
      pthread_cond_wait( &(rwlp->r_cond), &(rwlp->lock) );
    rwlp->readers++;
    pthread_mutex_unlock( &(rwlp->lock) );

    return 0;
}

int rw_wrlock( rwlock_t *rwlp )
{
    pthread_mutex_lock( &(rwlp->lock) );
    while( rwlp->readers != 0 )
      pthread_cond_wait( &(rwlp->w_cond), &(rwlp->lock) );
    rwlp->readers=-1;
    pthread_mutex_unlock( &(rwlp->lock) );

    return 0;
}

int rw_unlock( rwlock_t *rwlp )
{
    pthread_mutex_lock( &(rwlp->lock) );
    if( rwlp->readers == -1 )
      rwlp->readers = 0;
    else
      rwlp->readers--;
    pthread_cond_broadcast( &(rwlp->w_cond) );
    pthread_cond_broadcast( &(rwlp->r_cond) );
    pthread_mutex_unlock( &(rwlp->lock) );

    return 0;
}

/* semaphore function for OSF/1 */
int sema_init(sema_t *sem, unsigned int c, int d, void *e)
/* c is not used */
/* d is not used */
/* e is not used */
{
  pthread_mutex_init(&(sem->lock), pthread_mutexattr_default );
  pthread_cond_init(&(sem->cond), pthread_condattr_default );
  sem->count = 0;

    return 0;
}

int sema_destroy(sema_t *sem)
{
  pthread_mutex_destroy(&(sem->lock));
  pthread_cond_destroy(&(sem->cond));

    return 0;
}

int sema_wait(sema_t *sem)
{
  pthread_mutex_lock(&(sem->lock));
  while (sem->count == 0){
    pthread_cond_wait(&(sem->cond), &(sem->lock));}
  sem->count--;
  pthread_mutex_unlock(&(sem->lock));

    return 0;
}

int sema_trywait(sema_t *sem)
{
  int ret;
  pthread_mutex_lock(&(sem->lock));
  if (sem->count == 0)
    ret = EBUSY;
  else{
    sem->count--;
    ret = 0;
  }
  pthread_mutex_unlock(&(sem->lock));
  return (ret);
}
  
int sema_post(sema_t *sem)
{
  pthread_mutex_lock(&(sem->lock));
  sem->count++;
  pthread_cond_broadcast(&(sem->cond));
  pthread_mutex_unlock(&(sem->lock));

    return 0;
}


void mthread_init( context *mainctx )
{
    int i;
    pthread_t tid;

    for( i = 0; i < MAXTHREAD; i++ )
      thread_table[i].using = 0;

    thread_table[0].tid = pthread_self();
    thread_table[0].using = 1;

    pthread_mutex_init(&p_mark_lock, pthread_mutexattr_default );
    pthread_mutex_init(&alloc_lock, pthread_mutexattr_default );
    pthread_mutex_init(&free_thread_lock, pthread_mutexattr_default );
    pthread_mutex_init(&qthread_lock, pthread_mutexattr_default );
    pthread_mutex_init(&qsort_lock, pthread_mutexattr_default );
    sema_init(&free_thread_sem, 0, 0, 0);
    rwlock_init(&gc_lock, 0, 0);
}


#endif
