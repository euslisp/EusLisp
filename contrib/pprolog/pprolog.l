; Portable-PROLOG originally written by H. Nakashima

#+kcl
(defmacro putprop (sym val ind) `(setf (get ,sym ,ind) ,val))
#+kcl
(defmacro while (cond &rest body)
   `(do ()
        ((not ,cond))
	. ,body))
#+kcl
(defun memq (x l) (member x l :test #'eq))
#+kcl
(defun assq (x l) (assoc x l :test #'eq))


(proclaim '(SPECIAL *OLD-SUBST* *CUE* *NEW-SUBST* *UNDO-LIST* *SUBST*))
(defvar *prolog-debug* nil)
(defvar *prolog-predicates* nil)

(defun init-prolog ()
    (dolist (p *prolog-predicates*)
	(remprop p 'prolog))
    (setq *prolog-predicates* nil))

(defmacro newsubst () '(cons nil nil))

#+:eus
(DEFUN VAR? (X)
   (declare (type symbol x))
   (AND (SYMBOLP X) (EQ (char (the string (x . pname)) 0) #\*)))

#+kcl
(DEFUN VAR? (X)
   (AND (SYMBOLP X) (EQ (aref (symbol-name x ) 0) #\*)))

(DEFUN ASSIGNED? (X SUBST) (ASSq X (CDR SUBST)))

(DEFUN LINK (X X-SUBST Y Y-SUBST)
  (push (RPLACD X-SUBST
                (CONS (CONS X (CONS (FETCH Y Y-SUBST)
                                    *SUBST*))
                      (CDR X-SUBST)))
        *UNDO-LIST*))

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

(DEFUN FETCH (X SUBST)
  (SETQ *SUBST* SUBST)
  (COND ((VAR? X)
         (let ((V nil))
           (SETQ V (assigned? X SUBST))
           (COND ((NULL V)  X)
		 (t (FETCH (SECOND V) (CDDR V))))))
        (T X)))

(DEFUN FETCH-VALUE (X SUBST)
  (COND ((VAR? X)
         (let ((V nil))
           (SETQ V (ASSigned? X  SUBST))
           (COND ((NULL V) X)
                 (T (FETCH-VALUE (SECOND V) (CDDR V))))))
        ((ATOM X) X)
        (T (CONS (FETCH-VALUE (CAR X) SUBST)
                 (FETCH-VALUE (CDR X) SUBST)))))

#|
(defun fetch-value (x subst)
   (let (y)
     (format t "fetch-value: ~s --> ~s~%" x (setq y (fetch-value1 x subst)))
     y) )
|#

(DEFUN UNDO()
  (while *undo-list*
         (RPLACD (CAR *UNDO-LIST*) (CDDAR *UNDO-LIST*))
         (SETQ *UNDO-LIST* (CDR *UNDO-LIST*))))

(DEFUN TRY-SYS (form SUBST)
   (let ((builtin-func (get (car form) 'prolog_builtin)))
      (if builtin-func
	  (funcall builtin-func (cdr form) subst)
	  nil)))

(DEFUN REFUTES (CLAUSE &optional
			 (*NEW-SUBST* (newsubst))
			 (*OLD-SUBST* (newsubst))
			 (*CUE* nil))
  ;;(format t "refutes: ~s~%" clause)
  (if  clause
       (refute clause)
       (if *cue*
           (REFUTES (CAR (FIRST *CUE*)) (CONS NIL NIL)
                    (CDR (FIRST *CUE*)) (CDR *CUE*))
	   '*proved*)))

(defun refuten (clause definition)
  (and (UNIFY (CAR CLAUSE) *OLD-SUBST* (CAR DEFINITION) *NEW-SUBST*)
       (REFUTES (CDR DEFINITION) (CONS NIL NIL)  *NEW-SUBST*
                (CONS (CONS (CDR CLAUSE) *OLD-SUBST*) *CUE*))))

(DEFUN REFUTE (CLAUSE)
  (let (DEFINITION *UNDO-LIST* RESULT)
    (when *prolog-debug*
	  (print (fetch-value (car clause) *old-subst*))
	  (read-char))
    (when (var? (car clause))
	(setq clause (list (fetch (car clause) *old-subst*))))
    (SETQ DEFINITION (GET (CAAR CLAUSE) 'PROLOG))
    (while definition	;try all the alternatives
        (if (refuten clause (pop definition))
            (return-from refute '*PROVED*)
	    (undo)))
    ;all user defined clauses failed, try system built-in pred.
    (if (and (SETQ RESULT (TRY-SYS (CAR CLAUSE) *OLD-SUBST*))
             (REFUTES (CDR CLAUSE) (CONS NIL NIL) *OLD-SUBST* *CUE*))
        RESULT
        (UNDO))))

;;;
;;; main
;;;

(DEFUN DEFINE-CLAUSE (CLAUSE)
  (let* ((pred-name (caar clause))
	 (DEFINITION (GET pred-name 'PROLOG)))
      (pushnew pred-name *prolog-predicates*)
      (if (null (member clause definition :test #'equal))
          (if definition
              (NCONC DEFINITION (CONS CLAUSE NIL))
              (PUTPROP (CAAR CLAUSE) (CONS CLAUSE NIL) 'PROLOG)))))

(defun read-clauses (file)
  (let (clauses (sign '-))
    (while (eq sign '-)
      (push (read file) clauses)
      (setq sign (read file)))
    (when (null (eq sign '\.))
	(format t ". expected, but ~s is encountered~%" sign)
        (throw 'prolog nil))
    (reverse clauses)))

(DEFUN PROLOG (&optional (FILE t) (init nil))
  (let (sign $form RESULT $newsubst $oldsubst)
     (if init (init-prolog))
     (if (eq file t)
         (format t "portable prolog  EusLisp~%")
	 (setq file (open file)))
     (while t
	 (when (EQ FILE T) (format t "~%PRL> ") (finish-output t))
	 (catch 'prolog
             (case (setq sign (read file nil 'ok))
		(+ (DEFINE-CLAUSE (READ-clauses file))
		   (print '*defined*))
                (- (setq $newsubst (newsubst)
			 $oldsubst (newsubst)
			 $form (read-clauses file))
		   (setq result (REFUTES $form $newsubst $oldsubst NIL))
		   (if result
		       (print (fetch-value $form $oldsubst))
		       (print '*false*)))
                ((END exit quit ok STOP EPILOG)  (return-from prolog 'EPILOG))
		(t (print (eval sign)))
		)))))

;;;****************************************************************
;;; extended builtin predicates
;;;  by T.Matsui 1988-May
;;;****************************************************************
(defmacro defsyspred (name arglist &rest body)
   (let ((fname (intern (concatenate #+kcl 'string string "P_" (string name)))))
     `(progn
	 (defun ,fname ,arglist . ,body)
	 (putprop ',name ',fname 'prolog_builtin))))

(defsyspred call (args subst)
   (apply (fetch-value (first args) subst)
	  (mapcar #'(lambda (x) (fetch-value x subst)) (cdr args)))
   '*proved*)

(defsyspred eval (args subst)
   (if (UNIFY (apply (FETCH-VALUE (CAaR args) SUBST)
                     (MAPCAR #'(LAMBDA (X) (FETCH-VALUE X SUBST))
                             (CDaR args)))
              SUBST (second args) SUBST)
        '*PROVED*
        NIL))

(defsyspred purge (args subst)
   (MAPCAR #'(LAMBDA (X) (REMPROP (FETCH-VALUE X SUBST) 'PROLOG))   args)
   'DELETED)
(defsyspred load (args subst)
   (prolog (car args)) t)

(defsyspred print (args subst)
   (print (fetch-value (car args) subst))
   '*proved*)

(defsyspred false (args subst) nil)
(defsyspred not (args subst)
   (let (*cue*)  (not (refute args))))
(defsyspred assert (args subst)
   (define-clause (fetch-value args subst))
   t)

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
;       -(end):, stop, end, epilog, or end              end of prolog session
;
; Convensions
;       *variable               represents a variable
;       -(call function parameter...)   apply a function to parameters
;                                       with a success of unification
;       -(eval form clause)     unifies the value of form with clause

; ---- Now Enter the Portable-Prolog ----

