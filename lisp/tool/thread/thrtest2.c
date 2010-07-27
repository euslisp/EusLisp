#include <thread.h>
#include <synch.h>
#include <math.h>
#include <sys/times.h>
#include <limits.h>

mutex_t test_lock;

int count=0;

test1()
{   mutex_lock(&test_lock); 
    printf("test1: %x mutex_locked\n", &test_lock);
    sleep(3600/4);	/* 15 minutes*/
    mutex_unlock(&test_lock); 
    printf("test1: %x mutex_unlocked\n", &test_lock);
  }


test2(n)
int n;
{ printf("test2: want mutex_lock\n");
  mutex_lock(&test_lock);
  printf("test2: %x mutex_locked\n", &test_lock);
  sleep(15);	/* 15 seconds*/
  mutex_unlock(&test_lock); 
  printf("test2: %x mutex_unlocked\n", &test_lock);
  }

main(argc,argv)
int argc;
char *argv[];
{
  thread_t thrid[10];
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
  stat=thr_create(0,0,test1,&exitstat,THR_BOUND,&thrid[1]);
  printf("test1 thread %d created\n", thrid[1]);
  stat=thr_create(0,0,test2,&exitstat,THR_BOUND,&thrid[2]);
  printf("test2 thread %d created\n", thrid[2]);

  thr_join(thrid[1], 0, 0);
  thr_join(thrid[2], 0, 0);

  printf("joined\n");
  }

