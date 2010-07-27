; [11] Differentiation by data-driven programming

; Main routine

(SETQ BASE 10 IBASE 10)

(DEFUN DIFF (EXP X)
  (COND ((EQ EXP X) 1)
        ((ATOM EXP) 0)
        ((ATOM (CAR EXP))
         ((LAMBDA (FN)
            (COND ((AND FN (= (LENGTH EXP) 3))
                   (APPLY FN (LIST (CDR EXP) X)) )
                  (T 'ERROR) ))
          (GET (CAR EXP) 'DIFF-FN) ))))

; Define how to differentiate to each operator

(PUTPROP '+ 'PLUS-DIFF 'DIFF-FN)
(PUTPROP '- 'DIFFERENCE-DIFF 'DIFF-FN)
(PUTPROP '* 'TIMES-DIFF 'DIFF-FN)
(PUTPROP '/ 'QUOTIENT-DIFF 'DIFF-FN)
(PUTPROP '** 'EXPT-DIFF 'DIFF-FN)

(DEFUN PLUS-DIFF (SEXP X)
  (SIMP-PLUS (DIFF (CAR SEXP) X) (DIFF (CADR SEXP) X)) )

(DEFUN SIMP-PLUS (ARG1 ARG2)
  (COND ((AND (NUMBERP ARG1) (NUMBERP ARG2))
         (PLUS ARG1 ARG2) )
        ((EQ ARG1 0) ARG2)
        ((EQ ARG2 0) ARG1)
        (T (LIST '+ ARG1 ARG2)) ))

(DEFUN DIFFERENCE-DIFF (SEXP X)
  (SIMP-DIFFERENCE (DIFF (CAR SEXP) X) (DIFF (CADR SEXP) X)) )

(DEFUN SIMP-DIFFERENCE (ARG1 ARG2)
  (COND ((AND (NUMBERP ARG1) (NUMBERP ARG2))
         (DIFFERENCE ARG1 ARG2) )
        ((EQ ARG1 0) (LIST '* ARG2 -1))
        ((EQ ARG2 0) ARG1)
        ((NUMBERP ARG2) (LIST '+ ARG1 (TIMES ARG2 -1)))
        (T (LIST '- ARG1 ARG2)) ))

(DEFUN TIMES-DIFF (SEXP X)
  (SIMP-PLUS (SIMP-TIMES  (DIFF (CAR SEXP) X) (CADR SEXP))
             (SIMP-TIMES (CAR SEXP) (DIFF (CADR SEXP) X)) ))

(DEFUN SIMP-TIMES (ARG1 ARG2)
  (COND ((AND (NUMBERP ARG1) (NUMBERP ARG2))
         (TIMES ARG1 ARG2) )
        ((OR (EQ ARG1 0) (EQ ARG2 0)) 0)
        ((EQ ARG1 1) ARG2)
        ((EQ ARG2 1) ARG1)
        (T (LIST '* ARG1 ARG2)) ))

(DEFUN QUOTIENT (SEXP X)
  (DIFF (LIST '* (CAR SEXP) (LIST '** (CADR SEXP) -1)) X) )

(DEFUN EXPT-DIFF (SEXP X)
  (COND ((= (CADR SEXP) 0) 0)
        ((= (CADR SEXP) 1) (DIFF (CAR SEXP) X))
        (T (DIFF (LIST '* (CAR SEXP)
                       (SIMP-EXPT (CAR SEXP) (SUB1 (CADR SEXP))) )
                 X ))))

(DEFUN SIMP-EXPT (ARG EXP)
  (COND ((ZEROP EXP) 1)
        ((= EXP 1) ARG)
        (T (LIST '** ARG EXP)) ))

(DEFMACRO BENCHMARK (N &REST BODY)
  `(LET ((TIME1 nil) (TIME2 nil) (TIME3 nil) (GC nil) (RUN nil))
     (PRINT ',BODY)
     (GC)
     (SSTATUS GCTIME 0)
     (SETQ TIME1 (RUNTIME))
     (DO ((I 1 (1+ I)))
	 ((> I ,N))
       ,@BODY )
     (SETQ TIME2 (RUNTIME))
     (DO ((I 1 (1+ I))) ((> I ,N)))
     (SETQ TIME3 (RUNTIME))
     (SETQ GC (STATUS GCTIME))
     (SETQ RUN (DIFFERENCE (PLUS TIME2 TIME2) TIME1 TIME3))
     (TERPRI)
     (PRINC1 "Total = ")
     (PRINC1 RUN)
     (PRINC1 "us,  Runtime = ")
     (PRINC1 (DIFFERENCE RUN GC))
     (PRINC1 "us, GC = ")
     (PRINC1 GC)
     (PRINC1 "us, for ")
     (PRINC1 ,N)
     (PRINC1 " iterations.")
     (TERPRI)
     ))

; [11-1:]
(DEFUN BENCH111 (ITER)
  (BENCHMARK ITER
	     (DIFF (DIFF
		    '(+ (+ (+ (** X 3) (* 3 (** X 2))) (* 3 X)) 1) 'X) 'X)
	     ))

; This must return (+ (+ (+ X X) (+ (+ X X) (* X 2))) 6) .

; [11-2:] d(6) (x - 1)**6/dx
;      This must result in 720.

(DEFUN BENCH112 (ITER)
  (BENCHMARK ITER
	     (DIFF (DIFF (DIFF (DIFF (DIFF (DIFF
                          '(** (- X 1) 6) 'X) 'X) 'X) 'X) 'X) 'X)
	     ))

; If macro is not avaiable, use instead the followings:

'("*** Please this line and the last line. ***"

(DEFUN BENCH111 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
        (GC)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (DIFF (DIFF
	       '(+ (+ (+ (** X 3) (* 3 (** X 2))) (* 3 X)) 1) 'X) 'X)
	(COND ((GREATERP (SETQ N (SUB1 N)) 0) (GO L1)))
	(SETQ TIME2 (RUNTIME))
	(SETQ N ITER)
   L2   (COND ((GREATERP (SETQ N (SUB1 N)) 0) (GO L2)))
	(SETQ TIME3 (RUNTIME))
	(SETQ GC (STATUS GCTIME))
	(SETQ RUN (DIFFERENCE (PLUS TIME2 TIME2) TIME1 TIME3))
	(TERPRI)
	(PRINC "Total = ")
	(PRINC RUN)
	(PRINC "us,  Runtime = ")
	(PRINC (DIFFERENCE RUN GC))
	(PRINC "us, GC = ")
	(PRINC GC)
	(PRINC "us, for ")
	(PRINC ITER)
	(PRINC " iterations.")
	(TERPRI)
        ))

(DEFUN BENCH112 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
        (GC)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (DIFF (DIFF (DIFF (DIFF (DIFF (DIFF
                          '(** (- X 1) 6) 'X) 'X) 'X) 'X) 'X) 'X)
	(COND ((GREATERP (SETQ N (SUB1 N)) 0) (GO L1)))
	(SETQ TIME2 (RUNTIME))
	(SETQ N ITER)
   L2   (COND ((GREATERP (SETQ N (SUB1 N)) 0) (GO L2)))
	(SETQ TIME3 (RUNTIME))
	(SETQ GC (STATUS GCTIME))
	(SETQ RUN (DIFFERENCE (PLUS TIME2 TIME2) TIME1 TIME3))
	(TERPRI)
	(PRINC "Total = ")
	(PRINC RUN)
	(PRINC "us,  Runtime = ")
	(PRINC (DIFFERENCE RUN GC))
	(PRINC "us, GC = ")
	(PRINC GC)
	(PRINC "us, for ")
	(PRINC ITER)
	(PRINC " iterations.")
	(TERPRI)
        ))

"*** Please kill this line. ***" )

; Now measure the benchmark.
; (BENCH111 10 )
; (BENCH112 1)
