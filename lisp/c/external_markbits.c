/*
 * external_markbits.c: R.Hanai
 */

#include <stdio.h>
#include "external_markbits.h"
#include "rgc_utils.h"

#define bit_table_error(str)

unsigned int hmin, hmax;
static char *bit_table;
unsigned int mingcheap, maxgcheap;

void set_heap_range(unsigned int min, unsigned int max)
{
  if(mingcheap == 0 || min < mingcheap) mingcheap = min; 
  if(maxgcheap == 0 || max > maxgcheap) maxgcheap = max;
}

void allocate_bit_table()
{
  int size;

  ASSERT(mingcheap != maxgcheap);

  size = (maxgcheap-mingcheap+3)>>2;
  //size *= 2;
  hmin = mingcheap;
  hmax = mingcheap + (size<<2);
  //DPRINT2("allocate bit table [%x, %x)", hmin, hmax);
  bit_table = (char *)malloc(size);

  ASSERT(bit_table); // "failed to allocate an external bit table")
}

__inline__ void set_bit(unsigned int addr)
{
  ASSERT(hmin <= addr && addr < hmax);
//    DPRINT3("set: over the heap [%x;%x), addr=%x", hmin, hmax, addr);
//    DPRINT3("set: under the heap. [%x;%x], addr=%x", hmin, hmax, addr);

//  ASSERT(!(addr & 0x3));
//    DPRINT3("set: addr not word aligned, addr=%x", addr);
  
  bit_table[(addr - hmin) >> 2] = 1;
}

__inline__ char read_bit(unsigned int addr)
{
  ASSERT(hmin <= addr && addr < hmax);
//    DPRINT3("read: over the heap [%x;%x), addr=%x", hmin, hmax, addr);
//    DPRINT3("read: under the heap [%x;%x), addr=%x", hmin, hmax, addr);
  /* copyobj in leo.c:619 < leo.c:632 */

//  ASSERT(!(addr & 0x3));
//    DPRINT3("set: addr not word aligned, addr=%x", addr);
  
  return bit_table[(addr - hmin) >> 2];
}

/* 
 * copyobj in leo.c:619 < leo.c:632
 * SORT in sequence.c 978 
 * */

void clear_bit_table()
{
  memset(&bit_table[0], 0, (hmax-hmin+3)>>2);
}

void print_bit_table()
{
  int i, size, prod;
  size = (hmax-hmin+3)>>2;
  prod = 0;
  DPRINT2("bit-table size=%d", size);
  for(i = 0; i < size; i++){
    if(!(i&0xff)){
      fprintf(stderr, "%d", prod);
      prod = 0;
    }
    prod |= bit_table[i];
    if(!(i%(80*256))) fprintf(stderr, "\n");
  }
}
