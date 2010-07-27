#include <stdio.h>
#include <unistd.h>

main()
{
  int stat;
  long a;

  a=sysconf(_SC_ARG_MAX);
  printf("max combined size of argv[]= %d\n", a);

  a=sysconf(_SC_CLK_TCK);
  printf("clock tick per second= %d\n", a);

  a=sysconf(_SC_CHILD_MAX);
  printf("max processes allowed to any UID= %d\n", a);

  a=sysconf(_SC_OPEN_MAX);
  printf("max open files per process= %d\n", a);

  a=sysconf(_SC_PAGESIZE);
  printf("system memory page size= %d\n", a);

  a=sysconf(_SC_NPROCESSORS_CONF);
  printf("number of processors configured= %d\n", a);

  a=sysconf(_SC_NPROCESSORS_ONLN);
  printf("number of processors online= %d\n", a);

  a=sysconf(_SC_PHYS_PAGES);
  printf("total number of pages of physical memory= %d\n", a);

  a=sysconf(_SC_AVPHYS_PAGES);
  printf("number of pages of physical memory not in use= %d\n", a);

  a=sysconf(_SC_SEM_NSEMS_MAX);
  printf("maximum number of semaphores that a process may have= %d\n", a);

  a=sysconf(_SC_SEM_VALUE_MAX);
  printf("maximum value that a semaphore may have= %d\n", a);

  a=sysconf(_SC_SIGQUEUE_MAX);
  printf("maximum number of queued signals pending at receiver= %d\n", a);

  a=sysconf(_SC_TIMER_MAX);
  printf("maximum number of timers per process= %d\n", a);

  a=sysconf(_SC_SHARED_MEMORY_OBJECTS);
  printf("supports shared memory objects= %d\n", a);
}


