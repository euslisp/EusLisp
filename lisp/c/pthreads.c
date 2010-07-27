/*
   POSIX thread functions -> Solaris mthread functions.
	 writtten by I.Hara
*/

#include "eus.h"
#include <errno.h>

/* thread function for POSIX added by I.Hara */
pthread_t thread_table[MAXTHREAD][2];

int thr_self()
{
  int i;
  pthread_t thr_t;
  thr_t = pthread_self();
  for(i=0;(i<MAXTHREAD)&&(thread_table[i][0] != thr_t);i++);
  return(i);
}

int thr_getprio(int tid, int *prio)
{
  if (thread_table[tid][1])
    *prio = thread_table[tid][0]->attr.prio;
    return(0);
  else
    return (-1);
}

int thr_setprio(int tid, int prio)
{
  int stat;

  if (!thread_table[tid][1]) return(-1);
  else{
    if ((piro >= PTHREAD_MIN_PRIORITY) &&
        (piro =< PTHREAD_MAX_PRIORITY)) 
       thread_table[tid][0]->attr.prio = prio;
       return(0);
    else return(EINVAL); }
}

int thr_create(void *base, size_t size, void (*func)(), 
			void *args, long flags, int *tid)
{ int i, stat;
  pthread_attrt th_attr;
  for(i=0;(i<MAXTHREAD) && thread_table[i][1] ;i++);
  thread_table[i][0] = 1;
  pthread_attr_init(&th_attr);
  if (flag != 0) 
  	fprintf(stderr, "Warning in thr_create(): flags doesn't support!\n");
  if (size >= PTHREAD_STACK_MIN) pthread_attr_setstacksize(&th_attr, size);
  stat = pthread_create( &thread_table[i], th_attr, func, args);
  *tid = i;
  return(stat);
}

int thr_continue(int tid)
{
  fprintf(stderr, "Error in thr_continue: POSIX thread doesn't supported.\n");
  return(-1);
}

int thr_suspend(int tid)
{
  fprintf(stderr, "Error in thr_suspend: POSIX thread doesn't supported.\n");
  return(-1);
}

int thr_kill(int tid, int sig)
{
  return(pthread_kill(thread_table[tid][0], sig));
}

int thr_join(int tid, int *depature, void **status)
{
  if ( *depature  != NULL){
    fprintf(stderr,"Warrning in thr_join: argument 'depature' must be NULL.\n");
     *depature == -1;
    }
    return(pthread_join(thread_table[tid][0], status));
}

/* mutex functions with POSIX thread, added by I.Hara 
     int mutex_init(mutex_t *mp, int type, void * arg);
     int mutex_destroy(mutex_t *mp);
     int mutex_lock(mutex_t *mp);
     int mutex_trylock(mutex_t *mp);
     int mutex_unlock(mutex_t *mp);                                   
*/
/* condition variable functions with POSIX thread, added by I.Hara 
     int cond_init(cond_t *cvp, int type, int arg);
     int cond_destroy(cond_t *cvp);
     int cond_wait(cond_t *cvp, mutex_t *mp);
     int cond_timedwait(cond_t *cvp, mutex_t *mp, timestruc_t *abstime);
     int cond_signal(cond_t *cvp);
     int cond_broadcast(cond_t *cvp);                                          
*/

/* semaphore functions with POSIX thread, added by I.Hara 
typedef pthread_mutex_t mutex_t;
typedef pthread_cond_t cond_t;

typedef struct _sema {
        unsigned int count;
        mutex_t      lock;
        cond_t       cond;
      } sema_t;

*/
int sema_init(sema_t *sem, unsigned int c, int d, void *e)
{
  pthread_mutex_init(&(sem->lock), NULL);
  pthread_cond_init(&(sem->cond), NULL);
  sem->count = c;
}

int sema_destroy(sema_t *sem)
{
  pthread_mutex_destroy(&(sem->lock));
  pthread_cond_destroy(&(sem->cond));
}

int sema_wait(sema_t *sem)
{
  pthread_mutex_lock(&(sem->lock));
  while (sem->count == 0){
    pthread_cond_wait(&(sem->cond), &(sem->lock));}
  sem->count--;
  pthread_mutex_unlock(&(sem->lock));
}

int sema_trywait(sema_t *sem)
{
  int ret,stat;
  stat = pthread_mutex_trylock(&(sem->lock));
  if (stat != 0) return (stat);
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
  pthread_cond_signal(&(sem->cond));
  pthread_mutex_unlock(&(sem->lock));
}

/* readers/writer lock function for Linux added by I.Hara 
typedef struct _rwlock {
        unsigned int readers;
        mutex_t      lock;
        cond_t       r_cond;
        cond_t       w_cond;
      } rwlock_t;
*/
int rwlock_init(rwlock_t *rw, int c, void *d)
{
  mutex_init(&(rw->lock), 0, 0);
  cond_init(&(rw->r_cond), &(rw->lock),0);
  cond_init(&(rw->w_cond), &(rw->lock),0);
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

