#if PTHREAD
#include "eus.h"
#define ESUCCESS 0

/*
 * Most functions in thread library of Solaris2 return Zero on success.
 */

/* thread function for POSIX Thread */
struct {
    int using;
    thread_t tid;
} thread_table[MAXTHREAD];

unsigned int thr_self()
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
    int policy,err;
    struct  sched_param param;
    err = pthread_getschedparam( thread_table[tid].tid, &policy, &param );
    if (err == 0){
      *prio = param.sched_priority;
      return ESUCCESS;
    }else
      return errno;
}

int thr_setprio(int tid, int prio)
{
    int err;
    struct  sched_param param;
    param.sched_priority = prio;
    err = pthread_setschedparam( thread_table[tid].tid, SCHED_RR, &param );
    if (err == 0)
      return ESUCCESS;
    else
      return errno;
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

static int thr_create_lock=0;

static void thr_startup( struct thr_arg *arg )
{
    //if (debug) printf( "thr_startup:tid=%d\n", arg->tid ); 
    /* this line causes SEGMENTATION FAULT, but why? R.Hanai */

  pthread_cleanup_push((void(*)(void *))thr_cleanup, arg );
    if( !thread_table[arg->tid].tid ) 
      thread_table[arg->tid].tid = pthread_self(); /* R.Hanai */

/*  Linuxthread is not supported */
#if !Linux && !Cygwin
    pthread_setcancel( CANCEL_ON );
    pthread_setasynccancel( CANCEL_ON );
#endif
    while(thr_create_lock) usleep(1000);
    (arg->func)( arg->args );

    pthread_cleanup_pop( 1 );
}

int thr_create(void *base, size_t size, void (*func)(void *), void *args, long flags, int *tid )
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
    thr_create_lock=1;
    stat = pthread_create( &thread_table[i].tid, NULL, (void*(*)(void *))thr_startup, arg );
    if( stat == 0 )
      thread_table[i].using = 1;
    *tid = i;
    thr_create_lock=0;
    return( stat );
}

#if Linux
#include <signal.h>
/*
   thr_suspend() and thr_continue() are not implemented.
   these routines are only defined to avoid prototype definition error.
 */
pthread_mutex_t susp_the_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t susp_mut = PTHREAD_MUTEX_INITIALIZER;
volatile int susp_sentinel = 0;
pthread_once_t susp_once = PTHREAD_ONCE_INIT;
pthread_t susp_null_pthread = {0};
pthread_t susp_array[MAXTHREAD]; 
int susp_bottom = MAXTHREAD;
int susp_inited = 0;

/*
 * Handle SIGUSR1 in the target thread, to suspend it until
 * receiving SIGUSR2 (resume).
 */
void
suspend_signal_handler (int sig)
{
    sigset_t signal_set;

    /*
     * Block all signals except SIGUSR2 while suspended.
     */
    sigfillset (&signal_set);
    sigdelset (&signal_set, SIGUSR2);
    susp_sentinel = 1;
    sigsuspend (&signal_set);

    /*
     * Once I'm here, I've been resumed, and the resume signal
     * handler has been run to completion.
     */
    return;
}

/*
 * Handle SIGUSR2 in the target thread, to resume it. Note that
 * the signal handler does nothing. It exists only because we need
 * to cause sigsuspend() to return.
 */
void
resume_signal_handler (int sig)
{
    return;
}

/*
 * Dynamically initialize the "suspend package" when first used
 * (called by pthread_once).
 */
void
suspend_init_routine (void)
{
    int status;
    struct sigaction sigusr1, sigusr2;

    /*
     * Allocate the suspended threads array. This array is used
     * to guarentee idempotency
     */
    //susp_bottom = 10;
//    susp_array = (pthread_t*) calloc (susp_bottom, sizeof (pthread_t));

    /*
     * Install the signal handlers for suspend/resume.
     */
    sigusr1.sa_flags = 0;
    sigusr1.sa_handler = suspend_signal_handler;

    sigemptyset (&sigusr1.sa_mask);
    sigusr2.sa_flags = 0;
    sigusr2.sa_handler = resume_signal_handler;
    sigusr2.sa_mask = sigusr1.sa_mask;

    status = sigaction (SIGUSR1, &sigusr1, NULL);
    if (status == -1)
      {fprintf (stderr, "Installing suspend handler: %s\n", strerror(errno)); abort();}
    
    status = sigaction (SIGUSR2, &sigusr2, NULL);
    if (status == -1)
      {fprintf (stderr, "Installing resume handler : %s\n", strerror(errno)); abort(); }
    
    susp_inited = 1;
    return;
}

/*
 * Suspend a thread by sending it a signal (SIGUSR1), which will
 * block the thread until another signal (SIGUSR2) arrives.
 *
 * Multiple calls to thd_suspend for a single thread have no
 * additional effect on the thread -- a single thd_continue
 * call will cause it to resume execution.
 */
int 
//thd_suspend (pthread_t target_thread)
pthread_suspend (pthread_t target_thread)
{
    int status;
    int i = 0;

    /*
     * The first call to thd_suspend will initialize the
     * package.
     */
    status = pthread_once (&susp_once, suspend_init_routine);
    if (status != 0)
        return status;

    /* 
     * Serialize access to suspend, makes life easier
     */
    status = pthread_mutex_lock (&susp_mut);
    if (status != 0)
        return status;

    /*
     * Threads that are suspended are added to the target_array;
     * a request to suspend a thread already listed in the array
     * is ignored. Sending a second SIGUSR1 would cause the
     * thread to re-suspend itself as soon as it is resumed.
     */
    while (i < susp_bottom) 
        if (susp_array[i++] == target_thread) {
            status = pthread_mutex_unlock (&susp_mut);
            return status;
        }

    /*
     * Ok, we really need to suspend this thread. So, lets find
     * the location in the array that we'll use. If we run off
     * the end, realloc the array for more space.
     */
    i = 0;
    while (susp_array[i] != 0)
        i++;

    if (i == susp_bottom) {
//        susp_array = (pthread_t*) realloc (
//            susp_array, (++susp_bottom * sizeof (pthread_t)));
//        if (susp_array == NULL) {
            pthread_mutex_unlock (&susp_mut);
            return errno;
//        }

//        susp_array[susp_bottom] = susp_null_pthread;   /* Clear new entry */
    }

    /*
     * Clear the sentinel and signal the thread to suspend.
     */
    susp_sentinel = 0;
    status = pthread_kill (target_thread, SIGUSR1);
    if (status != 0) {
        pthread_mutex_unlock (&susp_mut);
        return status;
    }

    /*
     * Wait for the sentinel to change.
     */
    while (susp_sentinel == 0)
        sched_yield ();
    
    susp_array[i] = target_thread;

    status = pthread_mutex_unlock (&susp_mut);
    return status;
}

/*
 * Resume a suspended thread by sending it SIGUSR2 to break
 * it out of the sigsuspend() in which it's waiting. If the
 * target thread isn't suspended, return with success.
 */
int 
//thd_continue (pthread_t target_thread)
pthread_continue (pthread_t target_thread)
{
    int status;
    int i = 0;
    /* 
     * Serialize access to suspend, makes life easier
     */
    status = pthread_mutex_lock (&susp_mut);
    if (status != 0)
        return status;

    /*
     * If we haven't been initialized, then the thread must be "resumed"
     * it couldn't have been suspended!
     */
    if (!susp_inited) {
        status = pthread_mutex_unlock (&susp_mut);
        return status;
    }

    /*
     * Make sure the thread is in the suspend array. If not, it
     * hasn't been suspended (or it has already been resumed) and
     * we can just carry on.
     */
    while (susp_array[i] != target_thread && i < susp_bottom) 
        i++;

    if (i >= susp_bottom) {
        pthread_mutex_unlock (&susp_mut);
        return 0;
    }

    /*
     * Signal the thread to continue, and remove the thread from
     * the suspended array.
     */
    status = pthread_kill (target_thread, SIGUSR2);
    if (status != 0) {
        pthread_mutex_unlock (&susp_mut);
        return status;
    }

    susp_array[i] = 0;               /* Clear array element */
    status = pthread_mutex_unlock (&susp_mut);
    return status;
}
#endif
int thr_suspend( int tid ) { 
  return pthread_suspend ( thread_table[tid].tid );
}

int thr_continue( int tid ) {
  return pthread_continue ( thread_table[tid].tid );
}


int thr_kill( int tid, int sig )
/* sig is not used */
{
    if( pthread_cancel( thread_table[tid].tid ) < 0 )
      return errno;
    else
      return ESUCCESS;
}

/* readers/writer lock functions for PISIX Thread */
int rwlock_init(rwlock_t *rwlp, int type, void *arg)
{
    pthread_mutex_init(&(rwlp->lock), NULL);
    pthread_cond_init(&(rwlp->r_cond), NULL);
    pthread_cond_init(&(rwlp->w_cond), NULL);

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

/* semaphore function for POSIX Thread */
int sema_init(sema_t *sem, unsigned int c, int d, void *e)
/* c is not used */
/* d is not used */
/* e is not used */
{
  pthread_mutex_init(&(sem->lock), NULL);
  pthread_cond_init(&(sem->cond), NULL);
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

    pthread_mutex_init(&mark_lock, NULL);
    pthread_mutex_init(&alloc_lock, NULL);
    pthread_mutex_init(&free_thread_lock, NULL);
    pthread_mutex_init(&qthread_lock, NULL);
    pthread_mutex_init(&qsort_lock, NULL);
    
    sema_init(&free_thread_sem, 0, 0, 0);
    rwlock_init(&gc_lock, 0, 0);
}


#endif
