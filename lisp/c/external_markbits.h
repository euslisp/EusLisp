/*
 * external_markbits.h: R.Hanai
 */

#ifndef __EXTERNAL_MARKBITS_H
#define __EXTERNAL_MARKBITS_H

#ifdef __USE_MARK_BITMAP
#define colored(p) colored_ex(p)
#define blacked(p) blacked_ex(p)
#define marked(p) marked_ex(p)
#define markon(p) markon_ex(p)
#define markoff(p) markoff_ex(p)
#endif 

#define colored_ex(p) read_bit((unsigned int)p)
#define blacked_ex(p) read_bit((unsigned int)p)
#define marked_ex(p) read_bit((unsigned int)p)
#define markon_ex(p) set_bit((unsigned int)p)
#define markoff_ex(p) /* we do nothing. */

//#define set_bit(p) (bit_table[(p - hmin)>>2] = 1)
//#define read_bit(p) (bit_table[(p - hmin)>>2])

extern unsigned int mingcheap, maxgcheap;
extern unsigned int hmin, hmax;
void set_heap_range(unsigned int max, unsigned int min);
void allocate_bit_table();
__inline__ void set_bit(unsigned int addr);
__inline__ char read_bit(unsigned int addr);
void clear_bit_table();

#endif
