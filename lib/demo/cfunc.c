/* Example for EusLisp foreign language interface
/* last maintained: 2004-Dec-16 by Toshihiro Matsui, DHRC, AIST
/* C program named cfunc.c
/*
/* Compile this program with the following command line on Linux
/* % cc -c -falign-functions=4 cfunc.c; ld -o cfunc.so -shared cfunc.o
*/

static int (*g)();      /* variable to store Lisp function entry */
static double (*gf)();

double sync(x)
double x;
{ extern double sin();
  return(sin(x)/x);}

char *upperstring(s)
char *s;
{ char *ss=s;
  while (*s) { if (islower(*s)) *s=toupper(*s); s++;}
  return(ss);}

int setlfunc(f)      /* remember the argument in g just to see */
int (*f)();          /* how Lisp function can be called from C */
{ g=f;}

int setlffunc(f)     /* remember the argument in g just to see */
double (*f)();          /* how Lisp function can be called from C */
{ gf=f;}

int callfunc(x)      /* apply the Lisp function saved in g to the arg.*/
int x;
{ return((*g)(x));}

double callfltfunc(double dx)
{ return((*gf)(dx)); }


/*************************
;;;; Example program for EusLisp's foreign language interface
;;;; make foreign-module
(setq m (load-foreign "cfunc.so"))

;; define foreign functions so that they can be callable from lisp
(defforeign sync m "sync" (:float) :float)
(defforeign toupper m "upperstring" (:string) :string)
(defforeign setlfunc m "setlfunc" (:integer) :integer)
(defforeign setlffunc m "setlffunc" (:integer) :integer)	
(defforeign callfunc m "callfunc" (:integer) :integer)
(defforeign callfltfunc m "callfltfunc" (:float) :float)

;; call them
(sync 1.0)     ;; --> 0.841471
(print (toupper "abc123"))  ;;--> "ABC123"

;; define a test function which is callable from C.
(defun-c-callable LISP-INTFUNC ((a :integer)) :integer
      (format t "LISP-INTFUNC is called, arg=~s~%" a)
      (* a a))    ;; return the square of the arg
(defun-c-callable LISP-FLTFUNC ((f :float)) :float
      (format t "LISP-FLTFUNC is called, arg=~s~%" f)
      (sqrt f))    ;; return the square root of the arg

;;  call it from C
;;setlfunc remembers the entry address of Lisp TEST function.
(setlfunc (pod-address 'LISP-INTFUNC))
(callfunc 12)  ;; --> 144
(setlffunc (pod-address 'LISP-FLTFUNC))
(callfltfunc 2.0) 
********************************/

