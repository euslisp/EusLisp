/*
 * external_markbits.c: R.Hanai
 */

#include <stdio.h>
#include "external_markbits.h"
#include "rgc_utils.h"

/* for debugging */
void hoge(){}

#define bit_table_error(str)

static unsigned int mingcheap, maxgcheap;
unsigned int hmin, hmax;
static char *bit_table;

void set_heap_range(unsigned int min, unsigned int max)
{
  if(mingcheap == 0 || min < mingcheap) mingcheap = min; 
  if(maxgcheap == 0 || max > maxgcheap) maxgcheap = max;
}

void allocate_bit_table()
{
  int size;
  if(mingcheap == maxgcheap){
    DPRINT1("heap range is not set correctly");
    exit(1);
  }
  size = (maxgcheap-mingcheap+3)>>2;
  //size *= 2;
  hmin = mingcheap;
  hmax = mingcheap + (size<<2);
  //DPRINT3("allocate bit table [%x, %x)", hmin, hmax);
  bit_table = (char *)malloc(size);
  if(!bit_table){
    DPRINT1("failed to allocate an external bit table");
    exit(1);
  }
}

__inline__ void set_bit(unsigned int addr)
{
  if(hmax <= addr){
    DPRINT4("set: over the heap [%x;%x), addr=%x", hmin, hmax, addr);
    return;
  }
  if(addr < hmin){
    DPRINT4("set: under the heap. [%x;%x], addr=%x", hmin, hmax, addr);
    return;
  }
/*
  if(addr & 0x3){
    DPRINT2("set: addr not word aligned, addr=%x", addr);
    exit(1);
  }
  */
  bit_table[(addr - hmin) >> 2] = 1;
}

__inline__ char read_bit(unsigned int addr)
{
  if(hmax <= addr){
    DPRINT4("read: over the heap [%x;%x), addr=%x", hmin, hmax, addr);
    return 1;
  }
  if(addr < hmin){
    DPRINT4("read: under the heap [%x;%x), addr=%x", hmin, hmax, addr);
    return 1;
  }/* copyobj in leo.c:619 < leo.c:632 */
/*
  if(addr & 0x3){
    DPRINT2("read: addr is not word aligned, addr=%x", addr);
    exit(1);
  }*/
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
