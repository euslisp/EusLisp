/* 
 * 2003-
 * rgc_utils.h : R.Hanai
 */

#ifndef __RGC_UTILS
#define __RGC_UTILS

/*
 * debugging tools
 */
#ifdef __DEBUG
#define DPRINT debug_printf
#else 
#define DPRINT
#endif

//#define NDEBUG
#include <assert.h>
//#define ASSERT 
//#define ASSERT(condition) assert(condition) /* C standart assertion */

#define ASSERT(condition) \
{ \
  if (!(condition)) { hoge(); } \
} 
/* with this, we can set break-points where ASSERTs are inserted */


/* performance evaluation tools */
#ifdef __USE_RDTSC
void reset_utime();
#endif

unsigned current_utime();

#ifdef __PAPI
void papi_init();
void papi_print_counters();
#endif


#endif
