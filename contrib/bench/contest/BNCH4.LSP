; [4] Number consing

; **** Tarai with number ****

(SETQ BASE 10 IBASE 10)

(DEFUN FLO-TARAI (X Y Z)
  (COND ((GREATERP X Y)
         (FLO-TARAI (FLO-TARAI (DIFFERENCE X 0.11) Y Z)
                    (FLO-TARAI (DIFFERENCE Y 0.11) Z X)
                    (FLO-TARAI (DIFFERENCE Z 0.11) X Y) ))
        (T Y) ))

(DEFUN TARAI (X Y Z)
  (COND ((GREATERP X Y)
	 (TARAI (TARAI (SUB1 X) Y Z)
		(TARAI (SUB1 Y) Z X)
		(TARAI (SUB1 Z) X Y) ))
	(T Y) ))

; To speed up, generic arithmetic operations are replaced 
; by floating point arithmetic operations:
;
'("*** For MacLisp user, kill this line and last line
       to replace the definition. ***"

(DEFUN FLO-TARAI (X Y Z)
   (COND ((> X Y)
          (FLO-TARAI (FLO-TARAI (-$ X 0.11) Y Z)
		     (FLO-TARAI (-$ Y 0.11) Z X)
		     (FLO-TARAI (-$ Z 0.11) X Y) ))
         (T Y) ))

"*** Please kill this line. ***" )

; [4-1:] Flonum
; (FLO-TARAI 3.8 3.4 3.0)
     ; This complexity is equivalent to that of tarai-4.
     ; Confirm that flo-tarai is called 12605 times.
     ; If not, change the decrement (0.11) to an appropriate value.
     ; Number-manipulations may be replaced
     ; by those restricted to flonum if available

; [4-2:] Bignum
; (TARAI BIG-X BIG-Y BIG-Z)
     ; This complexity is equivalent to that of tarai-4.
     ; where big-z should be greater than the least positive
     ; bignum, big-x = big-z + 8, and big-y = big-z + 4.

(DEFMACRO BENCHMARK (N &REST BODY)
  `(LET ((TIME1 nil) (TIME2 nil) (TIME3 nil) (GC nil)(RUN nil))
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

(DEFUN BENCH41 (ITER) (BENCHMARK ITER (FLO-TARAI 3.8 3.4 3.0)))
(DEFUN BENCH42 (ITER)
  (BENCHMARK ITER (TARAI 35000000008. 35000000004. 35000000000. )) )

; If macro is not avaiable, use instead the followings:

'("*** Please this line and the last line. ***"

(DEFUN BENCH31 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
        (GC)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (FLO-TARAI 3.8 3.4 3.0)
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

(DEFUN BENCH42 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
        (GC)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (TARAI 35000000008. 35000000004. 35000000000. )
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

; Now measure the benchmarks.
; (BENCH41 1)
; (BENCH42 1)
