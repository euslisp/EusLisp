/* 
 * 2003-
 * rgc_utils.h : R.Hanai
 */

#ifndef __RGC_UTILS
#define __RGC_UTILS

/*
 * debugging tools
 */
#if (__DBG_LV == 1)
#define DPRINT1 debug_printf
#define DPRINT2 debug_printf
#elif (__DBG_LV == 2)
#define DPRINT1 
#define DPRINT2 debug_printf
#else
#define DPRINT1 
#define DPRINT2
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
void init_utils();
unsigned current_utime();

#ifdef __PAPI
void papi_init();
void papi_print_counters();
#endif


#endif
