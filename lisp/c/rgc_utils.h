/* 
 * 2003-
 * rgc_utils.h : R.Hanai
 */

/* for debugging */
#ifndef __DEBUG_PRINT
#define __DEBUG_PRINT

#ifdef __DEBUG
#define DPRINT1(a1) debug_printf(a1)
#define DPRINT2(a1,a2) debug_printf(a1,a2)
#define DPRINT3(a1,a2,a3) debug_printf(a1,a2,a3)
#define DPRINT4(a1,a2,a3,a4) debug_printf(a1,a2,a3,a4)
#define DPRINT5(a1,a2,a3,a4,a5) debug_printf(a1,a2,a3,a4,a5)
#else 
#define DPRINT1(a1)
#define DPRINT2(a1,a2)
#define DPRINT3(a1,a2,a3)
#define DPRINT4(a1,a2,a3,a4)
#define DPRINT5(a1,a2,a3,a4,a5)
#endif

/* functions used only for performance evaluation */

#ifdef __USE_RDTSC
void reset_utime();
#endif

unsigned current_utime();

#ifdef __PAPI
void papi_init();
void papi_print_counters();
#endif


#endif
