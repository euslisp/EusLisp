/* 
 * 2003-
 * rgc_utils.c : R.Hanai
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "rgc_utils.h"

int debug_printf(char *fmt, ...)
{
  va_list args;
  char buf[128];

  va_start(args, fmt);
  vsprintf(buf, fmt, args);
  va_end(args);
  fprintf(stderr, "[ %s ]\n", buf);

  return 0;
}

/* a dummy function for break points */
void hoge(){}

#define __USE_RDTSC
#ifdef __USE_RDTSC
#define CPU_CLOCK 1700 /* 1.7GHz -> microsec */

static int cpu_clock;

int read_cpuinfo()
{
#define BUF_SIZE 100
  FILE *fp;
  char buf[BUF_SIZE];
  int i;
  if ((fp = fopen("/proc/cpuinfo", "r")) == NULL) {
    fprintf(stderr, "Can't open /proc/cpuinfo\n");
    return -1;
  }
  while(fgets(buf, BUF_SIZE, fp) != NULL) {
    if (strncmp(buf, "cpu MHz", 7) )
      continue;
    for (i = 0; i < BUF_SIZE; i++) {
      if (buf[i] == ':') break;
    }
    if (i != BUF_SIZE) {
      sscanf(&buf[i+1], "%d", &cpu_clock);
      if (cpu_clock <= 0)
        return -1;
      else
        fprintf(stderr, "CPU CLOCK is %d\n", cpu_clock);
    }
  }
  return cpu_clock;
}

typedef union {
  unsigned long long val;
  struct {
    unsigned long eax;
    unsigned long edx;
  } reg;
} time_stamp_t;

#define rdtsc(tsc)\
__asm__ __volatile__("rdtsc"\
                    : "=a" (tsc.reg.eax), "=d" (tsc.reg.edx)\
                    )
//                    : /* no input */\
//                    : "eax", "edx") // <-- Is this O.K.?

static time_stamp_t now, start;

static void reset_utime(){
    start.val = 0ULL;
}

unsigned current_utime(void){
    rdtsc(now);
    return (now.val - start.val)/cpu_clock;
}

#else /* __USE_RDTSC */

unsigned current_utime(void){
	struct timeval t;
	if(gettimeofday( &t, 0 ) == -1)
		return 0;
	return (t.tv_sec * 1000000 + t.tv_usec);
}

#endif /* __USE_RDTSC */

#ifdef __PAPI
/*
 * Compile command is as follows.
 * gcc -I/usr/local/papi/include papitest.c /usr/local/papi/lib/libpapi.a
 */

#include <papi.h>

/* event name: See "papiStdEventDefs.h" */
static int Events[2] = { PAPI_L2_TCH, PAPI_L2_TCA};

static long_long values[2]; /* "long_long" is defined as "long long" */

static void handle_error(int code) {
    fprintf(stderr, "PAPI: an error occurred.\n");
    exit(code);
}

void papi_init() {
  int num_hwcntrs = 0;
  num_hwcntrs = PAPI_num_counters();

  /* The installation does not support PAPI */
  if (num_hwcntrs < 0 ) 
    handle_error(1);

  /* The installation supports PAPI, but has no counters */
  if (num_hwcntrs == 0) 
    fprintf(stderr, "Info: This machine does not provide hardware counters." );

  if (num_hwcntrs > 2)
    num_hwcntrs = 2;

  /* Start counting events */
  if (PAPI_start_counters(Events, num_hwcntrs) != PAPI_OK)
    handle_error(3);
}

void papi_print_counters(){
  PAPI_read_counters(values, 2);
  //  PAPI_accum_counters(values, 2);
  fprintf(stderr, "PAPI: %lf, %lf\n", (double)values[0], (double)values[1]);

#endif

void init_utils()
{
  if (read_cpuinfo() < 0) {
    cpu_clock = CPU_CLOCK;
  }
  reset_utime();

#ifdef __PAPI
  papi_init();
#endif
}

/*
 * live object maps for debbuging
 */

