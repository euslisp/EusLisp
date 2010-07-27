; [3] String manipulation

; **** Tarai with string ****

(SETQ BASE 10 IBASE 10)

(DEFUN STRING-TARAI (X Y Z)
  (COND ((STRING-LESSP
	  (SUBSTRING X 0 1) (SUBSTRING Y 0 1))
         (STRING-TARAI (STRING-TARAI (SUBSTRING X 1) Y Z)
                       (STRING-TARAI (SUBSTRING Y 1) Z X)
                       (STRING-TARAI (SUBSTRING Z 1) X Y) ))
        (T Y) ))

; where SUBSTRING must create new string header and body.
;    (SUBSTRING string 0 1) = (SHEAD string)
;    (SUBSTRING string 1)   = (STAIL string).

; [3-1:]
; (STRING-TARAI "ABCDEFGHIJ" "EFGHIJ" "IJ")
                ; where string-tarai is called 12605 times.
                ; stail is called 9453 times.

(DEFMACRO BENCHMARK (N &REST BODY)
  `(LET ((TIME1 nil)(TIME2 nil)(TIME3 nil)(GC nil)(RUN nil))
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

(DEFUN BENCH31 (ITER)
  (BENCHMARK ITER (STRING-TARAI "ABCDEFGHIJ" "EFGHIJ" "IJ")) )

; If macro is not avaiable, use instead the followings:

'("*** Please this line and the last line. ***"

(DEFUN BENCH31 (ITER)
  (PROG (TIME1 TIME2 TIME3 GC RUN N)
        (GC)
	(SSTATUS GCTIME 0)
	(SETQ TIME1 (RUNTIME))
	(SETQ N ITER)
   L1   (STRING-TARAI "ABCDEFGHIJ" "EFGHIJ" "IJ")
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
