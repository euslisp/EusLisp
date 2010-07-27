#include <thread.h>
#include <synch.h>
#include <math.h>
#include <sys/times.h>
#include <limits.h>

mutex_t test_lock;
mutex_t count_lock;
sema_t  gosem,retsem;

int count=0;
float sinx=0.0;

dofunc(n)
int n;
{ int i;
  thread_t self;
  self=thr_self();
  for (i=0; i<n; i++) {
    mutex_lock(&count_lock); 
    count++; sinx += sin(i % 6);
    mutex_unlock(&count_lock); 
/*    thr_yield(); */
    }
  printf("id=%d count=%d sinx=%f\n", self, count, sinx);
  }


semtest(n)
int n;
{ register int i;
  for (i=0; i<n; i++) {
    sema_wait(&gosem);
    sema_post(&retsem);}
  printf("sematest exit\n");}
  

float ustime(t1, t2)	/*returns time in milli second*/
struct tms *t1, *t2;
{ return((1000.0/CLK_TCK) *
	  ((t2->tms_utime-t1->tms_utime) + (t2->tms_stime-t1->tms_stime)));}

main(argc,argv)
int argc;
char *argv[];
{
  thread_t thrid[10001];
  int stat, *statp, stat2, s=1, exitstat, N;
  struct tms t1,t2,t3,t4,t5,t6;
  register int i;
  int concurrency;

  stat=thr_self();
  stat2=thr_min_stack();
  if (argc>=2) sscanf(argv[1],"%d", &concurrency);
  else concurrency=4;
  if (argc>=3) sscanf(argv[2], "%d", &N);
  else N=1000;

  thr_setconcurrency(concurrency);
  printf("self=%d  minstack=%x concurrency=%d CLK_TCK=%d\n\n",
	stat, stat2, thr_getconcurrency(), CLK_TCK);

  times(&t1);
  for (i=0; i<N; i++) {
    stat=thr_create(0,0,thr_exit,&exitstat,THR_BOUND,&thrid[i]);
    if (i % 100 ==0) {printf("%d stat=%d\n", i, stat);}}
  times(&t2);
  printf("creation time=%f max_thrid=%d\n", ustime(&t1, &t2)/(float)N,thrid[N-1]);
  times(&t2);
  for(i=0; i<N; i++) { thr_join(thrid[i], 0, 0);}
  times(&t3);
  printf("join time=%f\n", ustime(&t2, &t3)/(float)N);
  
  sema_init(&gosem, 0, USYNC_THREAD, 0);
  sema_init(&retsem, 0, USYNC_THREAD, 0);
  stat=thr_create(0,0,semtest,N,0,&thrid[0]);
  times(&t3);
  for (i=0; i<N; i++) {
    sema_post(&gosem);
    sema_wait(&retsem);}
  times(&t4);
  printf("sema switch time=%f\n", ustime(&t3, &t4)/(float)N);

  for (i=0; i<N; i++) {
    mutex_lock(&test_lock);
    mutex_unlock(&test_lock);
    mutex_lock(&test_lock);
    mutex_unlock(&test_lock);
    mutex_lock(&test_lock);
    mutex_unlock(&test_lock);
    mutex_lock(&test_lock);
    mutex_unlock(&test_lock);
    mutex_lock(&test_lock);
    mutex_unlock(&test_lock);}
  times(&t5);
  printf("mutex_lock & unlock time=%f\n", ustime(&t4, &t5)/((float)N*5.0));


  for (s=0; s<5; s++) {
    stat=thr_create(0,0, dofunc, 10000, 0, &thrid[s]);
/*    printf("stat=%x thrid=%x\n", stat, thrid[s]); */
    if (stat!=0) exit(1);}
  statp=&stat;
  for (s=0; s<5; s++) 
    stat2=thr_join(thrid[s], 0, &statp);
  printf("stat2=%x stat=%x concurrency=%d\n", stat2, stat, thr_getconcurrency());}

