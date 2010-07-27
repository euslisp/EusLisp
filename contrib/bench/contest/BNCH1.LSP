
; [1] function call/return

; **** Tarai ****
;      where number-manipulations may be replaced
;      by those restricted to integer if available

(SETQ BASE 10 IBASE 10)

(DEFUN TARAI (X Y Z)
  (COND ((GREATERP X Y)
	 (TARAI (TARAI (SUB1 X) Y Z)
		(TARAI (SUB1 Y) Z X)
		(TARAI (SUB1 Z) X Y) ))
	(T Y) ))

(DEFUN TAK (X Y Z)
  (COND ((NOT (LESSP Y X)) Z)
	(T (TAK (TAK (SUB1 X) Y Z)
		(TAK (SUB1 Y) Z X)
		(TAK (SUB1 Z) X Y) ))))

; To speed up, generic arithmetic operations are replaced 
; by integer arithmetic operations:
;
'("*** For MacLisp user, kill this line and last line
       to replace the definition. ***"

(DEFUN TARAI (X Y Z)
   (COND ((> X Y)
          (TARAI (TARAI (1- X) Y Z)
                 (TARAI (1- Y) Z X)
                 (TARAI (1- Z) X Y) ))
         (T Y) ))

(DEFUN TAK (X Y Z)
   (COND ((NOT (< Y X)) Z)
        (T (TAK (TAK (1- X) Y Z)
                (TAK (1- Y) Z X)
                (TAK (1- Z) X Y) ))))

"*** Please kill this line. ***" )

; Measure the following forms:
; [1-1:]
; (TARAI 8 4 0)       ; tarai is called 12605 times.
                      ;    with 9453 sub1's and 9454 else parts.

; [1-2:]
; (TARAI 10 5 0)      ; tarai is called 343073 times.
                      ;    with 257304 sub1's.

; [1-3:]     **** Try only the compiled code! ****
; (TARAI 12 6 0)      ; tarai is called 12604861 times.
                      ;    with 9453645 sub1's.

; [1-4:]
; (TAK 18 12 6)       ; tak is called 63609 times.
                      ;    in honor of USA Lisp comunity

(DEFMACRO BENCHMARK (N &REST BODY)
  `(LET ((TIME1 nil) (TIME2 nil) (TIME3 nil) (GC nil) (RUN nil))
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

(DEFUN BENCH11 (ITER) (BENCHMARK ITER (TARAI 8 4 0)))
(DEFUN BENCH12 (ITER) (BENCHMARK ITER (TARAI 10 5 0)))
(DEFUN BENCH13 (ITER) (BENCHMARK 1 (TARAI 12 6 0)))
(DEFUN BENCH14 (ITER) (BENCHMARK ITER (TAK 18 12 6)))

; If macro is not avaiable, use instead the followings:

'("*** Please this line and the last line. ***"

(DEFUN BENCH11 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (TARAI 8 4 0)
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
        (PRINC "us, Runtime = ")
	(PRINC (DIFFERENCE RUN GC))
	(PRINC "us, GC = ")
	(PRINC GC)
	(PRINC "us, for ")
	(PRINC ITER)
	(PRINC " iterations.")
	(TERPRI)
        ))

(DEFUN BENCH12 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (TARAI 10 5 0)
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
        (PRINC "us, Runtime = ")
	(PRINC (DIFFERENCE RUN GC))
	(PRINC "us, GC = ")
	(PRINC GC)
	(PRINC "us, for ")
	(PRINC ITER)
	(PRINC " iterations.")
	(TERPRI)
	))

(DEFUN BENCH13 ()
  (PROG (TIME1 TIME2 GC RUN)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(TARAI 12 6 0)
	(SETQ TIME2 (RUNTIME))
	(SETQ GC (STATUS GCTIME))
	(SETQ RUN (DIFFERENCE TIME2 TIME1))
	(TERPRI)
        (PRINC "Total = ")
        (PRINC RUN)
	(PRINC "us, Runtime = ")
	(PRINC (DIFFERENCE RUN GC))
	(PRINC "us, GC = ")
	(PRINC GC)
	(PRINC "us.")
	(TERPRI)
       ))

"*** Please kill this line if macro is not available. ***")

; (BENCH11 10)
; (BENCH12 1)
; (BENCH13)
; (BENCH14 1)
