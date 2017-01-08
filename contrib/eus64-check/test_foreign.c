#include <stdio.h>
#include <unistd.h>

int float_test(int n, float f1, float f2, float f3, float f4) {
  unsigned int ui;

  //printf("float_test in c\n");
  ui = *((unsigned int *)(&f1));
  printf("%d: %8.8e %X\n", n, f1, ui);
  ui = *((unsigned int *)(&f2));
  printf("%d: %8.8e %X\n", n, f2, ui);
  ui = *((unsigned int *)(&f3));
  printf("%d: %8.8e %X\n", n, f3, ui);
  ui = *((unsigned int *)(&f4));
  printf("%d: %8.8e %X\n", n, f4, ui);

  return -1;
}

int double_test(long n, double d1, double d2, double d3, double d4) {
  unsigned long ul;

  //printf("double_test in c\n");
  ul = *((unsigned long *)(&d1));
  printf("%ld: %16.16e %lX\n", n, d1, ul);
  ul = *((unsigned long *)(&d2));
  printf("%ld: %16.16e %lX\n", n, d2, ul);
  ul = *((unsigned long *)(&d3));
  printf("%ld: %16.16e %lX\n", n, d3, ul);
  ul = *((unsigned long *)(&d4));
  printf("%ld: %16.16e %lX\n", n, d4, ul);

  return -1;
}

int iv_test(int n, int *src) {
  int i;
  unsigned int *ui;
  printf("size = %d\n", n);
  for(i=0;i<n ;i++){
    ui = (unsigned int *)(&(src[i]));
    printf("%d: %d %X\n", i, src[i], *ui);
  }
  return -1;
}

int lv_test(int n, long *src) {
  int i;
  unsigned long *ul;
  printf("size = %d\n", n);
  for(i=0;i<n ;i++){
    ul = (unsigned long *)(&(src[i]));
    printf("%d: %ld %lX\n", i, src[i], *ul);
  }
  return -1;
}

int fv_test(int n, float *src) {
  int i;
  unsigned int *ui;
  printf("size = %d\n", n);
  for(i=0;i<n ;i++){
    ui = (unsigned int *)(&(src[i]));
    printf("%d: %e %X\n", i, src[i], *ui);
  }
  return -1;
}

int dv_test(int n, double *src) {
  int i;
  unsigned long *ul;
  printf("size = %d\n", n);
  for(i=0;i<n ;i++){
    ul = (unsigned long *)(&(src[i]));
    printf("%d: %e %lX\n", i, src[i], *ul);
  }
  return -1;
}

int str_test(int n, char *src) {
  int i;
  printf("size = %d\n", n);
  for(i=0;i<n ;i++){
    printf("%d: %c %x\n", i, src[i], src[i]);
  }
  return -1;
}

int int_test(long l, int i, short s) {
  printf("long  = %ld(%lX)\n",l,l);
  printf("int   = %d(%X)\n",i,i);
  printf("short = %d(%X)\n",s,s);
  
  return l + i + s;
}

float ret_float(double a, double b) {
  float ret = (float) (a + b);
  unsigned int *ui;
  ui = (unsigned int *)&ret;
  printf("// return %e, %X\n", ret, *ui);
  return ret;
}

double ret_double(double a, double b) {
  double ret = (a + b);
  unsigned long *ul;
  ul = (unsigned long *)&ret;
  printf("// return %e, %lX\n", ret, *ul);
  return ret;
}

long ret_long(long a, long b) {
  long ret = a + b;
  unsigned long *ul;
  ul = (unsigned long *)&ret;
  printf("// return %ld, %lX\n", ret, *ul);
  return ret;
}

double test_testd(long i0, long i1, long i2,
                  long i3, long i4, long i5, 
                  double d0, double d1, double d2, double d3,
                  double d4, double d5, double d6, double d7,
                  double d8, double d9,
                  long i6, long i7) {
  printf("%ld %ld %ld\n", i0, i1, i2);
  printf("%ld %ld %ld\n", i3, i4, i5);
  //printf("%ld %ld %ld %ld\n",
  //(long)d0, (long)d1, (long)d2, (long)d3);
  printf("%lf %lf %lf %lf\n", d0, d1, d2, d3);
  printf("%lf %lf %lf %lf\n", d4, d5, d6, d7);
  printf("%lf %lf\n", d8, d9);
  printf("%ld %ld\n", i6, i7);
  
  //return 0x1234;
  return 1.23456;
}
double test_testd2(long i0, long i1, long i2,
                   long i3, long i4, long i5, 
                   double d0, double d1, double d2, double d3,
                   double d4, double d5, double d6, double d7,
                   double d8, double d9, double d10,
                   long i6, long i7) {
  printf("%ld %ld %ld\n", i0, i1, i2);
  printf("%ld %ld %ld\n", i3, i4, i5);
  //printf("%ld %ld %ld %ld\n",
  //(long)d0, (long)d1, (long)d2, (long)d3);
  printf("%lf %lf %lf %lf\n", d0, d1, d2, d3);
  printf("%lf %lf %lf %lf\n", d4, d5, d6, d7);
  printf("%lf %lf %lf\n", d8, d9, d10);
  printf("%ld %ld\n", i6, i7);
  
  //return 0x1234;
  return 1.23456;
}

static long (*g)();
static double (*gf) (long i0, long i1, long i2,
                     long i3, long i4, long i5, 
                     double d0, double d1, double d2, double d3,
                     double d4, double d5, double d6, double d7,
                     double d8, double d9,
                     long i6, long i7);

long set_ifunc(long (*f) ())
{
  g = f;
  printf("set_ifunc, g = %lX\n", g);
}

long set_ffunc(double (*f) ())
{
  gf = (double (*) (long i0, long i1, long i2,
                    long i3, long i4, long i5, 
                    double d0, double d1, double d2, double d3,
                    double d4, double d5, double d6, double d7,
                    double d8, double d9,
                    long i6, long i7))f;
  printf("set_ffunc, gf = %lX\n", gf);
}

long call_ifunc() {
  printf("call_ifunc, g = %lX\n", g);
  return g();
}

double call_ffunc() {
  printf("call_ffunc, gf = %lX\n", gf);
  return gf(100,101,102,
            103,104,105,
            1000.0, 1010.0, 1020.0, 1030.0,
            1040.0, 1050.0, 1060.0, 1070.0,
            2080.0, 2090.0,
            206, 207);
}

long get_size_of_pointer() {
  return (sizeof(void *));
}

long get_size_of_float32() {
  return (sizeof(float));
}

long get_size_of_double() {
  return (sizeof(double));
}

long get_size_of_long() {
  return (sizeof(long));
}

long get_size_of_int() {
  return (sizeof(int));
}
