/* 
 * collector.h:	R.Hanai
 * concurrent snapshot collector with return barrier for eulisp
 */

#ifndef __COLLECTOR_H
#define __COLLECTOR_H

#if PTHREAD // the same as those in eus_thr.h 
typedef	pthread_t thread_t;
typedef	pthread_mutex_t	mutex_t;
typedef	pthread_cond_t cond_t;
#define thr_exit(x) pthread_exit(x)
#define thr_join(x,y,z)	pthread_join(x,z)
#define	mutex_lock pthread_mutex_lock
#define	mutex_trylock pthread_mutex_trylock
#define	mutex_unlock pthread_mutex_unlock
#define	cond_wait pthread_cond_wait
#define	cond_signal pthread_cond_signal
#define	cond_broadcast pthread_cond_broadcast
#define mutex_init(x,y) pthread_mutex_init(x,y)
#define mutex_destroy pthread_mutex_destroy
#define cond_init(x,y) pthread_cond_init(x,y)
#define cond_destroy pthread_cond_destroy
#endif

#define DEFAULT_GC_THRESHOLD 0.2

#define PHASE_NOGC 0
#define PHASE_MARK 4
#define PHASE_SWEEP 5
//#define PHASE_GC_EPILOGUE 6

#ifdef __RETURN_BARRIER
typedef struct {
  pointer *pointer;
  mutex_t lock;
} rbar_t;

#define check_return_barrier(ctx) \
{ \
  if((ctx)->rbar.pointer){\
    register pointer *p, *newbase; \
    if((ctx)->callfp) newbase = (pointer *)((ctx)->callfp); \
    else newbase = (ctx)->stack; \
    if(newbase < (ctx)->rbar.pointer){ \
      mutex_lock(&(ctx)->rbar.lock); \
      if(newbase < (ctx)->rbar.pointer){ \
        /* printf("thread ID inserting root \n"); */\
        for(p = (ctx)->rbar.pointer - 1; p >= newbase; p--) \
          if((!((int)(*p) & 3)) && (((ctx)->stack > (pointer *)*p) || \
              ((pointer *)*p > (ctx)->stacklimit))) \
              pgcpush(*p);\
          if(newbase == (ctx)->stack) \
            (ctx)->rbar.pointer = NULL; \
          else \
            (ctx)->rbar.pointer = newbase; \
      } \
      mutex_unlock(&(ctx)->rbar.lock); \
    }\
  }\
}\

/* old version code */
/*
#define check_return_barrier(ctx) \
{ \
  int id = thr_self(); \
  if(rbar[id].pointer){\
    register pointer *p, *newbase = (ctx)->stack;\
    if((ctx)->callfp) newbase = (pointer *)((ctx)->callfp); \
    if(newbase < rbar[id].pointer){ \
      mutex_lock(&rbar[id].lock); \
      if(newbase < rbar[id].pointer){ \
        printf("thread %d inserting root \n",id); \
        for(p = rbar[id].pointer - 1; p >= newbase; p--) \
          if((((int)(*p) & 3)==0) && (((ctx)->stack > (pointer *)*p) || \
              ((pointer *)*p > (ctx)->stacklimit))) \
              pgcpush(*p);\
          if(newbase == (ctx)->stack) \
            rbar[id].pointer = NULL; \
          else \
            rbar[id].pointer = newbase; \
      } \
      mutex_unlock(&rbar[id].lock); \
    }\
  }\
}\
*/
#endif /* __RETURN_BARRIER */

#define TAGMASK  0x1f
#define FREETAG  0x20
#define GRAYTAG  0x20
#define BLACKTAG 0x40
#define COLORTAG 0x60

#ifndef __USE_MARK_BITMAP
#define colored_map(p) colored_hd(p)
#define blacked_map(p) blacked_hd(p)
#define markon_map(p) markon_hd(p)
#define markoff_map(p) markoff_hd(p)
#define marked_map(p) marked_hd(p)
#endif
#define colored_hd(p) (p->h.bix & COLORTAG)
#define blacked_hd(p) (p->h.bix & BLACKTAG)
#define markon_hd(p) (p->h.bix |= BLACKTAG)
#define markoff_hd(p) (p->h.bix &= TAGMASK)
#define marked_hd(p) (p->h.bix & BLACKTAG)

#ifdef __USE_POLLING
struct _mut_stat_table {
  unsigned int stat;
  /* 
     from lower bit
     1:(may be) blocked
     2:need to be scanned
     3:being scanned
     (4:standby)
  */
  mutex_t lock;
};
#endif

struct _gc_data {
  pointer *collector_stack;
  pointer *collector_sp;
  pointer *collector_stacklimit;
  int gc_phase;
  int active_mutator_num;
  int gc_counter;
  int gc_point_sync;
  int gc_region_sync;
  int ri_core_phase;
#ifdef __USE_POLLING
  volatile int gc_request_flag;
  struct _mut_stat_table mut_stat_table[MAXTHREAD];
#endif
  mutex_t gc_state_lock;
  mutex_t collector_lock;
  mutex_t ri_end_lock;
  cond_t ri_end_cv;
  cond_t gc_wakeup_cv;
  int gc_wakeup_cnt;
  int gc_cmp_cnt;

};

extern struct _gc_data gc_data;

#define collector_stack gc_data.collector_stack
#define collector_sp gc_data.collector_sp
#define collector_stacklimit gc_data.collector_stacklimit
#define gc_phase gc_data.gc_phase
#define active_mutator_num gc_data.active_mutator_num
#define gc_counter gc_data.gc_counter
#define gc_point_sync gc_data.gc_point_sync
#define gc_region_sync gc_data.gc_region_sync
#define ri_core_phase gc_data.ri_core_phase

#ifdef __USE_POLLING
#define gc_request_flag gc_data.gc_request_flag
#define mut_stat_table gc_data.mut_stat_table
#endif
#define gc_state_lock gc_data.gc_state_lock
#define collector_lock gc_data.collector_lock
#define ri_end_lock gc_data.ri_end_lock
#define ri_end_cv gc_data.ri_end_cv
#define gc_wakeup_cv gc_data.gc_wakeup_cv
#define gc_wakeup_cnt gc_data.gc_wakeup_cnt
#define gc_cmp_cnt gc_data.gc_cmp_cnt

#define lock_collector mutex_lock(&collector_lock)
#define unlock_collector mutex_unlock(&collector_lock)

extern mutex_t pstack_lock;
extern mutex_t gcstate_lock;
extern pointer pstack[];
extern volatile pointer *psp;
extern volatile pointer *oldpsp;
extern pointer *pstacklimit;

#ifdef __PROFILE_GC
extern int allocd_words;
#endif


#ifdef __USE_POLLING

#define GC_POINT _check_gc_request()
#define _check_gc_request() {if(gc_request_flag) scan_roots();}
/* <= memory barrier instructions may be needed */
#define ENTER_GC_SAFE_REGION(id) enter_gc_region(id)
#define EXIT_GC_SAFE_REGION(id) exit_gc_region(id)
#define GC_REGION(comp_statement) \
  { \
    int _tmp_id = thr_self(); \
    ENTER_GC_SAFE_REGION(_tmp_id); \
    comp_statement \
    EXIT_GC_SAFE_REGION(_tmp_id); \
  }

#else /* __USE_SIGNAL */

#define GC_POINT
#define GC_REGION(cmp_statement) cmp_statement

#endif


typedef struct barrier_struct {
  pthread_mutex_t lock;
  int n_clients;
  int n_waiting;
  int phase;
  pthread_cond_t wait_cv;
} *barrier_t;

barrier_t barrier_init(int);
void barrier_reset(barrier_t, int);
void barrier_wait(barrier_t);
extern barrier_t startup_barrier;   

#ifdef __USE_SIGNAL
void sighandler(int);
#endif

unsigned int allocate_heap(unsigned int);
extern volatile long sweepheap, newheap, pastfree;

/*
 * collector interface
 */
void notify_gc();
void wait_end_gc();

#endif /* __COLLECTOR_H */
