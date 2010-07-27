/* a C function in "sync.c" */
/* cc -c -fpic sync.c
/* ld -shared -o sync.so sync.o
/* eus$ (setq m (load-foreign "sync.so"))
/* #<load-module #X818f520 "./sync.so">
/* eus$ (defforeign sync m "sync" (:float) :float)
/* #<foreign-code #X818f5e0>
/* eus$ sync 1.0
/* 0.841471
/* eus$ sync 2.0
/* 0.454649
/* eus$ sync 0.01
/* 0.999983
*/


float sync(x) double x;
{ extern double sin();
  return(sin(x)/x);}

int average(x,y)
int x,y;
{ return((x+y)/2);}

