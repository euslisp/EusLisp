; [10] Portable Prolog

; Portable-PROLOG originally written by H. Nakashima
; transferred to ECL on   Monday, 9 November 1981

; This program may be modified in order to speed up its performance.

(SETQ BASE 10 IBASE 10)

(DECLARE (SPECIAL FILE OLD-SUBST CUE NEW-SUBST UNDO-LIST *SUBST*))

(DEFUN PROLOG FEXPR (&optional (FILE t))
  (PROG (RESULT)
         (COND ((EQ FILE T)
                (PRINT '(PORTABLE PROLOG ON LISP))
                (TERPRI))
	       (t (SETQ FILE (OPEN FILE))))
   LOOP (COND ((EQ FILE T) (PRINT 'PRL>)))
        (COND((EQ (SETQ RESULT (READ-EXEC)) 'EPILOG)
              (RETURN 'EPILOG))
             ((EQ RESULT 'SYNTAX-ERROR) NIL)
             ((EQ FILE T) (PRINT (COND (RESULT RESULT)
                                       (T '*FAILURE*)))))
        (GO LOOP)))

(DEFUN READ-EXEC ()
  (PROG (SIGN)
    (SETQ SIGN (READ FILE))
    (RETURN (COND ((EQ SIGN '\+)(DEFINE-CLAUSE (READ-REST)))
                  ((EQ SIGN '\-)(REFUTE-CLAUSE (READ-REST)))
                  ((MEMQ SIGN '(END OK STOP EPILOG)) 'EPILOG)
                  (T (READ-ERROR SIGN))))))

(DEFUN READ-REST ()
  (PROG (FORM REST)
    (SETQ FORM (READ FILE))
    (RETURN (COND ((ATOM FORM)(READ-ERROR FORM))
                  ((EQ (SETQ REST (READ-SIGN)) 'SYNTAX-ERROR)
                   'SYNTAX-ERROR)
                  (T (CONS FORM REST))))))

(DEFUN READ-SIGN ()
  (PROG (SIGN)
    (SETQ SIGN (READ FILE))
    (RETURN (COND((EQ SIGN '\-)(READ-REST))
                 ((EQ SIGN ':) NIL)
                 (T (READ-ERROR SIGN))))))

(DEFUN READ-ERROR (OBJ)
  (PRINT (LIST 'SYNTAX 'ERROR OBJ)) 'SYNTAX-ERROR)

;(DEFUN FIRST MACRO (X) (CONS 'CAR (CDR X)))
;(DEFUN SECOND MACRO (X) (CONS 'CADR (CDR X)))
;(DEFUN THIRD MACRO (X) (CONS 'CADDR (CDR X)))
(DEFUN FIRST mexpr (X) (list 'CAR X))
(DEFUN SECOND mexpr (X) (list 'CADR X))
(DEFUN THIRD mexpr (X) (list 'CADDR X))

(DEFUN DEFINE-CLAUSE (CLAUSE)
  (COND ((EQ CLAUSE 'SYNTAX-ERROR) 'SYNTAX-ERROR)
        (T (PROG (DEFINITION)
             (SETQ DEFINITION (GET (CAAR CLAUSE) 'PROLOG))
             (COND ((NULL DEFINITION)
                    (PUTPROP (CAAR CLAUSE)
                             (CONS CLAUSE NIL) 'PROLOG))
                   (T (NCONC DEFINITION (CONS CLAUSE NIL))))
             (RETURN 'DEFINED)))))

(DEFUN REFUTE-CLAUSE (CLAUSE)
  (COND ((EQ CLAUSE 'SYNTAX-ERROR) 'SYNTAX-ERROR)
        (T (REFUTES CLAUSE (CONS NIL NIL) (CONS NIL NIL) NIL))))

(DEFUN REFUTES (CLAUSE NEW-SUBST OLD-SUBST CUE)
  (COND ((NULL CLAUSE)
        (COND ((NULL CUE) '*PROVED*)
              (T (REFUTES (CAR (FIRST CUE)) (CONS NIL NIL)
                          (CDR (FIRST CUE)) (CDR CUE)))))
        (T (REFUTE CLAUSE))))

(DEFUN REFUTE (CLAUSE)
  (PROG (DEFINITION UNDO-LIST RESULT)
    (SETQ DEFINITION (GET (CAAR CLAUSE) 'PROLOG))
   REFUTELOOP
    (OR DEFINITION
        (RETURN
         (COND ((AND
                 (SETQ RESULT (TRY-SYS (CAR CLAUSE) OLD-SUBST))
                 (REFUTES (CDR CLAUSE) (CONS NIL NIL) OLD-SUBST CUE))
                RESULT)
               (T (UNDO) NIL))))
    (COND ((AND (UNIFY (CAR CLAUSE) OLD-SUBST
                       (CAAR DEFINITION) NEW-SUBST)
                (REFUTES (CDR (FIRST DEFINITION)) (CONS NIL NIL)
                         NEW-SUBST
                         (CONS (CONS (CDR CLAUSE) OLD-SUBST) CUE)))
           (RETURN '*PROVED*))
          (T (UNDO)))
    (SETQ DEFINITION (CDR DEFINITION))
    (GO REFUTELOOP)))

(DEFUN UNDO()
  (PROG()
   LOOP (COND ((NULL UNDO-LIST) (RETURN NIL))
              (T (RPLACD (CAR UNDO-LIST) (CDDAR UNDO-LIST))
                 (SETQ UNDO-LIST (CDR UNDO-LIST))
                 (GO LOOP)))))

(DEFUN TRY-SYS (FORM SUBST)
  (COND ((EQ (CAR FORM) 'CALL)
         (APPLY (FETCH-VALUE (SECOND FORM) SUBST)
                (MAPCAR '(LAMBDA (X) (FETCH-VALUE X SUBST))
                        (CDDR FORM)))
         '*PROVED*)
        ((EQ (CAR FORM) 'EVAL)
         (COND ((UNIFY
                 (APPLY (FETCH-VALUE (CAR (SECOND FORM)) SUBST)
                        (MAPCAR '(LAMBDA (X) (FETCH-VALUE X SUBST))
                                (CDR (SECOND FORM))))
                 SUBST (THIRD FORM) SUBST)
                '*PROVED*)
               (T NIL)))
        ((EQ (CAR FORM) 'END) 'EPILOG)
        ((EQ (CAR FORM) 'DELETE)
         (MAPCAR '(LAMBDA (X) (REMPROP (FETCH-VALUE X SUBST) 'PROLOG))
                 (CDR FORM))
         'DELETED)
        (T NIL)))

(DEFUN UNIFY (X X-SUBST Y Y-SUBST)
  (COND ((VAR? X)
         (COND ((ASSIGNED? X X-SUBST)
                (UNIFY (FETCH X X-SUBST) *SUBST* Y Y-SUBST))
               (T (LINK X X-SUBST Y Y-SUBST))))
        ((VAR? Y) (UNIFY Y Y-SUBST X X-SUBST))
        ((ATOM X) (EQ X Y))
        ((ATOM Y) NIL)
        ((UNIFY (CAR X) X-SUBST (CAR Y) Y-SUBST)
         (UNIFY (CDR X) X-SUBST (CDR Y) Y-SUBST))
        (T NIL)))

(DEFUN VAR? (X) (AND (SYMBOLP X) (EQ (CHARACTER X) '*)))

(DEFUN ASSIGNED? (X SUBST) (ASSOC X (CDR SUBST)))

(DEFUN FETCH (X SUBST)
  (SETQ *SUBST* SUBST)
  (COND ((VAR? X)
         (PROG (V)
           (SETQ V (ASSOC X (CDR SUBST)))
           (COND ((NULL V) (RETURN X)))
           (SETQ *SUBST* (CDDR V))
           (RETURN (FETCH (SECOND V) (CDDR V)))))
        (T X)))

(DEFUN FETCH-VALUE (X SUBST)
  (COND ((VAR? X)
         (PROG (V)
           (SETQ V (ASSOC X (CDR SUBST)))
           (COND ((NULL V) (RETURN X))
                 (T (RETURN (FETCH-VALUE (SECOND V) (CDDR V))))))
        ((ATOM X) X)
        (T (CONS (FETCH-VALUE (CAR X) SUBST)
                 (FETCH-VALUE (CDR X) SUBST)))))

(DEFUN LINK (X X-SUBST Y Y-SUBST)
  (SETQ UNDO-LIST
        (CONS (RPLACD X-SUBST
                      (CONS (CONS X (CONS (FETCH Y Y-SUBST)
                                          *SUBST*))
                            (CDR X-SUBST)))
              UNDO-LIST)))

(DEFUN CHARACTER (X) (COND ((NULL X) NIL)
                           (T (CAR (EXPLODE X)))))

; HOW TO USE Portable-PROLOG
;       (prolog {file-name})
;               (prolog)        input from terminal
;               (prolog {(directory)} file-name {extension})
;                       A file must be terminated by "stop".
;
; The Syntax of Portable-Prolog
;       +(f1 {p1}...):                                  asserts a fact
;       +(f1 {p1}...)-(f2 {p2}...) ... -(fn {pn}...):   asserts a theorem 
;       -(f1 {p1}...) ... -(fn {pn}...):                        query
;       -(end):, stop, end, epilog, or nd              end of prolog session
;
; Convensions
;       *variable               represents a variable
;       -(call function parameter...)   apply a function to parameters
;                                       with a success of unification
;       -(eval form clause)     unifies the value of form with clause

; ---- Now Enter the Portable-Prolog ----

(PROLOG)

; Problem 1. Naive reverse

+(NREVERSE (*X . *L0) *L)-(NREVERSE *L0 *L1)-(CONCAT *L1 (*X) *L):
+(NREVERSE () ()):

+(CONCAT (*A . *X) *Y (*A . *Z))-(CONCAT *X *Y *Z):
+(CONCAT () *Y *Y):

; [10-1:] Reverse 30 element.

+(REV15 *X)-(NREVERSE ( 1  2  3  4  5  6  7  8  9 10
                       11 12 13 14 15 ) *X):

+(BENCH101)
-(EVAL (SSTATUS GCTIME 0) *GC1) -(EVAL (RUNTIME) *TIME1)
-(REV15 *X)
-(EVAL (RUNTIME) *TIME2) -(EVAL (STATUS GCTIME) *GC2)
-(EVAL (DIFFERENCE *TIME2 *TIME1) *TOTALTIME)
-(EVAL (DIFFERENCE *TIME2 *TIME1 *GC2) *RUNTIME)
-(CALL PRINT
       (Total = *TOTALTIME usec, Runtime = *RUNTIME usec and Gc = *GC2 usec)):

; Problem 2. Quicksort.

+(QSORT (*X . *L) *R *R0)
      -(PARTITION *L *X *L1 *L2)
      -(QSORT *L2 *R1 *R0)
      -(QSORT *L1 *R (*X . *R1)):
+(QSORT () *R *R):

+(PARTITION (*X . *L) *Y (*X . *L1) *L2)
      -(EVAL (LESSP *X *Y) T)
      -(PARTITION *L *Y *L1 *L2):
+(PARTITION (*X . *L) *Y *L1 (*X . *L2))
      -(PARTITION *L *Y *L1 *L2):
+(PARTITION () *A () ()):

; [10-2:] Sort 20 element.

+(SORT20 *X)-(QSORT (27. 74. 17. 33. 94. 18. 46. 83. 65.  2.
                    32. 53. 28. 85. 99. 47. 28. 82.  6. 11. ) *X ()):

+(BENCH102)
-(EVAL (SSTATUS GCTIME 0) *GC1) -(EVAL (RUNTIME) *TIME1)
-(SORT20 *X)
-(EVAL (RUNTIME) *TIME2) -(EVAL (STATUS GCTIME) *GC2)
-(EVAL (DIFFERENCE *TIME2 *TIME1) *TOTALTIME)
-(EVAL (DIFFERENCE *TIME2 *TIME1 *GC2) *RUNTIME)
-(CALL PRINT
       (Total = *TOTALTIME usec, Runtime = *RUNTIME usec and Gc = *GC2 usec)):

; Now measure the benchmarks.

; -(BENCH101):
; -(BENCH102):
OK
