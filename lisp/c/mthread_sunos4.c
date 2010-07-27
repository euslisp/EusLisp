#if SunOS4_1

#include "eus.h"

/* thread function for SunOS 4.1.x added by H.Nakagaki */
thread_t thread_table[MAXTHREAD];

int thr_self()
{
  int i;
  thread_t tid;
  lwp_self(&tid);
  for(i=0;(i<MAXTHREAD)&&(thread_table[i].thread_key != tid.thread_key);i++);
  return(i);
}

int thr_getprio(int tid, int *prio)
{
  int stat;
  statvec_t prio_vec;
  stat=lwp_getstate(thread_table[tid], &prio_vec);
  *prio = prio_vec.stat_prio;
  return(stat);
}

int thr_setprio(int tid, int prio)
{
  return( lwp_setpri(thread_table[tid], prio));
}

int thr_create(void *base, size_t size, void (*func)(), void *args, long flags, int *tid)
{ int i, stat;
  for(i=0;(i<MAXTHREAD)&&(thread_table[i].thread_key >=0 );i++);
/*  lwp_setstkcache(size, 1);*/
  stat = lwp_create( &thread_table[i], func, MINPRIO, flags, lwp_newstk(), 1, args);
  *tid = i;
  return(stat);
}

int thr_continue(int tid)
{
  return( lwp_resume(thread_table[tid]) );
}

int thr_suspend(int tid)
{
  return( lwp_suspend(thread_table[tid] ));
}

int thr_kill(int tid, int sig)
{
  int stat;
  stat = lwp_destroy(thread_table[tid]);
  thread_table[tid].thread_key = -1;
  return(stat);
  
}

/* readers/writer lock function for SunOS 4.1.x added by H.Nakagaki */
int rwlock_init(rwlock_t *rw, int c, void *d)
{
  mutex_init(&(rw->lock), 0, 0);
  cond_init(&(rw->r_cond), &(rw->lock));
  cond_init(&(rw->w_cond), &(rw->lock));
  rw->readers = 0;
}

int rwlock_destroy(rwlock_t *rw)
{
  mutex_destroy(&(rw->lock));
  cond_destroy(&(rw->r_cond));
  cond_destroy(&(rw->w_cond));
}

int rw_rdlock(rwlock_t *rw)
{
  mutex_lock(&(rw->lock));
  while (rw->readers == -1)
    cond_wait(&(rw->r_cond), 0);
  rw->readers++;
  mutex_unlock(&(rw->lock));
}

int rw_wrlock(rwlock_t *rw)
{
  mutex_lock(&(rw->lock));
  while (rw->readers != 0)
    cond_wait(&(rw->w_cond), 0);
  rw->readers=-1;
  mutex_unlock(&(rw->lock));
}

int rw_unlock(rwlock_t *rw)
{
  mutex_lock(&(rw->lock));
  if (rw->readers == -1)
    rw->readers = 0;
  else
    rw->readers--;
  cond_broadcast(&(rw->w_cond));
  cond_broadcast(&(rw->r_cond));
  mutex_unlock(&(rw->lock));
}

/* semaphore function for SunOS 4.1.x added by H.Nakagaki */
int sema_init(sema_t *sem, unsigned int c, int d, void *e)
{
  mutex_init(&(sem->lock), 0, 0 );
  cond_init(&(sem->cond), &(sem->lock));
  sem->count = c;
}

int sema_destroy(sema_t *sem)
{
  mutex_destroy(&(sem->lock));
  cond_destroy(&(sem->cond));
}

int sema_wait(sema_t *sem)
{
  mutex_lock(&(sem->lock));
  while (sem->count == 0){
    cond_wait(&(sem->cond), &(sem->lock));}
  sem->count--;
  mutex_unlock(&(sem->lock));
}

int sema_trywait(sema_t *sem)
{
  int ret;
  mutex_lock(&(sem->lock));
  if (sem->count == 0)
    ret = EBUSY;
  else{
    sem->count--;
    ret = 0;
  }
  mutex_unlock(&(sem->lock));
  return (ret);
}
  
int sema_post(sema_t *sem)
{
  mutex_lock(&(sem->lock));
  sem->count++;
  cond_broadcast(&(sem->cond));
  mutex_unlock(&(sem->lock));
}

/* Multi thread scheduler for SunOS 4.1.x. */
void scheduler()
{
  struct timeval quantum;
  quantum.tv_sec = 0;
  quantum.tv_usec = 10000;
  for(;;){
    lwp_sleep(&quantum);
    lwp_resched(MINPRIO);
  }
}

void mthread_init( context *mainctx )
{
    int i;

    for(i=0;i<MAXTHREAD;i++)
      thread_table[i].thread_key = -1;
    lwp_self(&thread_table[0]);
    mutex_init(&mark_lock, USYNC_THREAD, 0);
    mutex_init(&p_mark_lock, USYNC_THREAD, 0);
    mutex_init(&alloc_lock, USYNC_THREAD, 0);
    mutex_init(&free_thread_lock, USYNC_THREAD, 0);
    mutex_init(&qthread_lock, USYNC_THREAD, 0);
    mutex_init(&qsort_lock, USYNC_THREAD, 0);
    sema_init(&free_thread_sem, 0, USYNC_THREAD, 0);
    rwlock_init(&gc_lock, USYNC_THREAD, 0);
    pod_setmaxpri(2);
    lwp_setstkcache(32*1024*4, MAXTHREAD);
    lwp_create((thread_t *)0, scheduler, 2, 0, lwp_newstk(), 0);
    lwp_setpri(SELF,MINPRIO);
}
  
#endif	/* SunOS4_1 */
