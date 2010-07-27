
#|
All this talk about compilation in Lisp has started me thinking
about the dynamic linking (via the symbol table) that I guess
most Lisp implementations must use.  It would seem to me that
for "simple" functions the symbol-table lookup time (and
associated type and argument count checking) could take a
significant fraction of the time needed to execute the function
call.  Static linking could avoid the need to do this checking
on every function entry, but would be hard to incorporate in
an interactive Lisp (or one where you could redefine functions
at run-time).

However, there is one case where static linking would seem
to be ideal - the LABELS construct.  In most cases (where
the local function definitions are not closed ove) it should
be possible to statically link the local functions and perform
the argument-count checking at compile-time.  Moreover, references
in the local functions to lexical variables in the enclosing
definition should be able to be compiled to stack-offsets, so
there should be no need to close over them.

Thus we would expect using local functions in the LABELS
construct would be much more efficient than an equivalent
program in which these local functions have been replaced
with global definitions.

Unfortunately this is not the case in the Lisp I use, viz.
MACL.  I demonstrate this on two programs that solve the 
nqueens problem that are listed below.

The first one uses the LABELS construct: I regard it as the
neater of the programs.  Unfortunately, it is also
the slower.

  ? (time (and (queens1 8) nil))
  (AND (QUEENS1 8) NIL) took 493 ticks (8.217 seconds) to run.
  NIL

The second function "unpacks" all of the local LABELS functions
into independent functions.  It runs about twice as fast as
the first.  Moreover, adding INLINE declarations speeds up
QUEENS2 more than it speeds up QUEENS1!

  ? (time (and (queens2 8) nil))
  (AND (QUEENS2 8) NIL) took 321 ticks (5.350 seconds) to run.
  NIL

I find this most unfortunate, since it encourages programmers
to use a less elegant programming style for efficiency reasons,
particularly when as far as I can see, the more elegant style
should actually be more efficient!

Mark Johnson
|#

(defun queens1 (n)
  (labels ((find-queens (sofar col safeset)
             (if (> col n)
               (cons safeset sofar)
               (place-queen sofar col n safeset)))
           (place-queen (sofar col row safeset)
             (labels ((safe (rest-safeset)
                        (or (null rest-safeset)
                            (and (/= col (caar rest-safeset))
                                 (/= row (cdar rest-safeset))
                                 (/= (abs (- col (caar rest-safeset)))
                                     (abs (- row (cdar rest-safeset))))
                                 (safe (cdr rest-safeset))))))
               (if (= row 0)
                 sofar
                 (place-queen (if (safe safeset)
                                (find-queens sofar 
                                             (1+ col)
                                             (cons (cons col row)
                                                   safeset))
                                sofar)
                              col
                              (1- row)
                              safeset)))))
    (find-queens '() 1 '())))

(defun find-queens (n sofar col safeset)
  (if (> col n)
    (cons safeset sofar)
    (place-queen n sofar col n safeset)))

(defun safe (rest-safeset row col)
  (or (null rest-safeset)
      (and (/= col (caar rest-safeset))
           (/= row (cdar rest-safeset))
           (/= (abs (- col (caar rest-safeset)))
               (abs (- row (cdar rest-safeset))))
           (safe (cdr rest-safeset) row col))))

(defun place-queen (n sofar col row safeset)
  (if (= row 0)
    sofar
    (place-queen n (if (safe safeset row col)
                     (find-queens n sofar (1+ col) (cons (cons col row) safeset))
                     sofar)
                 col
                 (1- row)
                 safeset)))

(defun queens2 (n)
  (find-queens n '() 1 '()))


