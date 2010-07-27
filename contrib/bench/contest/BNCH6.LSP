; [6] Property list

; **** Generate sequence ****

(SETQ BASE 10 IBASE 10)

(DEFUN SEQUENCE (N)
  (COND ((GET 'SEQ-TABLE N) (GET 'SEQ-TABLE N))
        (T (PUTPROP 'SEQ-TABLE
              (- (SEQUENCE (SUB1 N)) (SEQUENCE (- N 2)))
              N )
           (GET 'SEQ-TABLE (GET 'SEQ-TABLE N)) )))

; ---- Initialization of property list of sequence ----

(SETPLIST 'SEQ-TABLE '(-1 1 0 1 1  1))

; [6-1:] Calculate 100th number

(DEFUN BENCH61 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (SETPLIST 'SEQ-TABLE '(-1 1 0 1 1  1))
        (SEQUENCE 100)
	(COND ((GREATERP (SETQ N (SUB1 N)) 0) (GO L1)))
	(SETQ TIME2 (RUNTIME))
	(SETQ N ITER)
   L2   (SETPLIST 'SEQ-TABLE '(-1 1 0 1 1  1))
        (COND ((GREATERP (SETQ N (SUB1 N)) 0) (GO L2)))
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

; Now measure the benchmark.
; (BENCH61 1. )


