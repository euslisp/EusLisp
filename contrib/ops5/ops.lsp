; GDW 18-JUL-1984 18:43:15 "fast-symeval > symbol-value,
;                          & fixed (set k 2) bug in ops-write"
;
; GDW 17-JUL-1984 22:55:55 """Initial source"" /history"
;
;	VPS2 -- Interpreter for OPS5
;
;	Copyright (C) 1979, 1980, 1981
;	Charles L. Forgy,  Pittsburgh, Pennsylvania
;
;
;  Re-ported to vax/vms lisp GDW
;
;  Spice Lisp mods by Dario Giuse for Common Lisp on a Perq.
;
;  vax/vms common lisp mods by George Wood 
;
;  uses some common lisp mods by Jim Kowalski
; fix ppelm: curpos problem
; clops127.cl: vax/vms common lisp ops5 interpreter with 127 condition ele.
;
; Users of this interpreter are requested to contact
;
;	Charles Forgy
;	Computer Science Department
;	Carnegie-Mellon University
;	Pittsburgh, PA  15213
; or
;	Forgy@CMUA
; 
; so that they can be added to the mailing list for OPS5.  The mailing list
; is needed when new versions of the interpreter or manual are released.
;
;  REPORT BUGS IN THIS VERSION TO:
;	George Wood
;	Computer Science Department
;	Carnegie-Mellon University
;	Pittsburgh, PA  15213
; arpanet : George.Wood@CMU-CS-A
; 


;[ Add this entry to the front of the file ]

; 7/6/84 George Wood
;  - Re-ported to vax/vms lisp
;  - UNINTERN for WRITE, REMOVE conditionalized using SHARPSIGN-MINUS VMS
;       compiler reacts badly to it.
;  - VMS-KEYBOARD-BINDINGS BLOCK INCLUDED IN SHARPSIGN-PLUS VMS CONDITIONAL
;  - started cleaning up old comments
;
; 6/22/84 Dario Giuse
;  - Replacing printline with format
;
; 6/21/84 Dario Giuse
;  - Replaced the system::macro business with a honest-to-god (defmacro).
;  - Rewrote getvector and putvector in sensible Common Lisp.
;
; 6/20/84 Dario Giuse
;  - Completely rewrote ops-acceptline. This is now working properly in Spice
;    Lisp, and since it only uses Common Lisp I believe it will work in any
;    Common Lisp installation. This version does not do any peek-char; it just
;    reads the whole line and works from there.
;  - Removed the now obsolete function span-char.
;
; 6/19/84 Dario Giuse
;  - Uncommented do-write
;  - Changed t to *standard-output* in several places.
;  - Added a force-output to ops-write, since lines without a Newline are not
;    printed by default in Spice Lisp (and many other Common Lisp
;    implementations). This should probably be done only for 
;    *standard-output*, not for all files.
;
; 6/8/84 Jcp
; Changed (setq *refracts* (delete (cons a b) *refracts*)) to
;         (setq *refracts* (spdelete (cons a b) *refracts*))
;
;         Also defined a new function called spdelete to delete things
;         from *refracts* properly. This fixes a bug where going back
;         and then forwards didn't fire the same rules.
;
;changes made by gdw
;
; Tue Jul 17 22:59:52 1984:
; 	calls to fast-symeval replaced by calls to symbol-value 
;;;
; changed macro to system::macro to access buried fn OBSOLETE 
; put stuff to unexport & unintern the fns write & remove from 
;	user: package in clopxtra.cl
;; ADDED SETBREAK, DEFINE-KEYBOARD-AST FOR ^D --> OPS BREAK CHAR feb 8 84
; To make problems easy to find, I have marked comments with:
; ??? = possible problems
; @@@ = changes (kluges ? working modifications)
; ### commented out lines -- temporary hacks?
;
;; VERSION WITH 127 CONDITION ELEMENTS, NOT 64 -- Jan 13, 1984
;
;@@@ dec 8 83: added comma to list of skipped char in acceptline
;
; KNOWN & SUSPECTED PROBLEMS:
; see note-write below: This should be redone using packages, when
;	implemented.
; DECLARE's should be replaced with PROCLAIM's
; ACCEPTLINE doesn't work right in x0.4-0, due to peek-char bug in
;	that version. local kluges either redefine peek-char with
;	read-char & unread char or use XSEL's redefined acceptline, or both.
; possible problems with openfile/write: 
;	lisp sometimes doesn't think its a char output stream
; problems with remove (doesn't select top-level-remove, recognize *)
;	NOTE; this happens when execution is broken while in the rhs
;	of an ops rule -- to correct, (setq *in-rhs* nil)
;
; problem with (pm) ?	(not clear)
;
; CHANGES, MOST RECENT FIRST
; replaced dtpr with consp. (defun didn't work: 13 below)
; re-defined tyi @@@ (kowalski's didn't work)
; replaced "(times " with "(* "        ))
; replaced "(greaterp " with (> " (all had 2 args)))
; defined infile as open input:
; defined outfile as open output:
; kluged do-tabto and do-rjust, to avoid messing with flatc & nwritn/
;	\these kluges are terrible, but should have only cosmetic effects
;	THEY NOW USE (FORMAT ...), WHICH IS BUGGY IN X0.4-0
; commented out (comment function)
; changed ==; clisp didn't seem to like the macro def
; changed "plus" to "+" throughout
; changed quotient to truncate or round;
;		 in ops-compute this may be inappropriate
;
;	@@@	NOTE ON FNS WRITE & REMOVE
;note-write
;since write is a clisp instinsic, I have changed it to write-ops
;until the package feature of common lisp is implemented in declisp--
;at that point this kluge may be removed. Ditto for remove/remove-ops-
;--In this version, I have uninterned the common lisp intrinsic write
;and remove in the separate file clopxtra.cl, to be loaded uncompiled
;after clops127.fas is loaded
;
;
;  Table of changes made by kowalski to bring ops up under common lisp
;  (SOME ARE MODIFIED. GDW)
;  1) Changed "def" to "defun" throughout. (4/11/83)
;  2) Changed "difference" to "-" throughout (2 places). (4/12/83)
;  3) Changed the "defun x macro" forms (of which there were 5)
;     to the macro form of common lisp. (4/20/83)
;  4) Added macro def of "putprop" (4/21/83)
;  5) changed "setsyntax" to appropriate form of "set-macro-character"
;  6) converted fexprs to regular defuns by changing the name of
;     each fexpr to "ops-.....", deleting the "fexpr", and adding
;     a macro for each with the name of the original fexpr.  5/23/83
;  7) Replaced all "]" (superparentheses) with appropriate number of
;     regular ones. (5/23/83)
;  8) Made changes to the individual functions containing the Franz
;     "concat" form (instead of writing a macro). (5 places) (6/26/83)
;  9) Inverted the arguments of the two uses of "catch" so that tag
;     is the first argument as required in CLisp. (6/26/83)
;     I'm really unsure about whether symbolic tags must be quoted in
;     catch forms.
; 10) Changed (member x y ) forms to (member x y :test #'equal) forms
;     and (memq ..) forms to (member ...). (6/26/83)
; 11) Changed the getchar form and index parameter since the first position
;     of a string is 0 in CommonLisp and 1 in Franz.
; 12) Added defmacro for ncons.
; @@@ X 13) Added auxiliary function defining function dtpr  as consp.
; 14) Added auxiliary function defining function fix as floor.
; 15) Added auxiliary function defining function tyipeek as peek-char
; 16) Added auxiliary function defining = as equal.

;;; Definitions

;@@@ added -- bound but not referenced
(proclaim '(special erm *break-character*))

(proclaim
 '(special *matrix* *feature-count* *pcount* *vars* *cur-vars*
	   *curcond* *subnum* *last-node* *last-branch* *first-node*
	   *sendtocall* *flag-part* *alpha-flag-part* *data-part*
	   *alpha-data-part* *ce-vars* *virtual-cnt* *real-cnt*
	   *current-token* *c1* *c2* *c3* *c4* *c5* *c6* *c7* *c8* *c9*
	   *c10* *c11* *c12* *c13* *c14* *c15* *c16* *c17* *c18* *c19*
	   *c20* *c21* *c22* *c23* *c24* *c25* *c26* *c27* *c28* *c29*
	   *c30* *c31* *c32* *c33* *c34* *c35* *c36* *c37* *c38* *c39*
	   *c40* *c41* *c42* *c43* *c44* *c45* *c46* *c47* *c48* *c49*
	   *c50* *c51* *c52* *c53* *c54* *c55* *c56* *c57* *c58* *c59*
	   *c60* *c61* *c62* *c63* *c64* *c65* *c66* *c67* *c68* *c69*
	   *c70* *c71* *c72* *c73* *c74* *c75* *c76* *c77* *c78* *c79*
	   *c80* *c81* *c82* *c83* *c84* *c85* *c86* *c87* *c88* *c89*
	   *c90* *c91* *c92* *c93* *c94* *c95* *c96* *c97* *c98* *c99*
	   *c100* *c101* *c102* *c103* *c104* *c105* *c106* *c107* *c108* *c109*
	   *c110* *c111* *c112* *c113* *c114* *c115* *c116* *c117* *c118* *c119*
	   *c120* *c121* *c122* *c123* *c124* *c125* *c126* *c127* 
	   *record-array* *result-array* 
	   *max-cs* *total-cs* *limit-cs* *cr-temp* *side*
	   *conflict-set* *halt-flag* *phase* *critical*
	   *cycle-count* *total-token* *max-token* *refracts* 
	   *limit-token* *total-wm* *current-wm* *max-wm*
	   *action-count* *wmpart-list* *wm* *data-matched* *p-name*
	   *variable-memory* *ce-variable-memory* *max-index*
	   *next-index* *size-result-array* *rest* *build-trace* *last*
	   *ptrace* *wtrace* *in-rhs* *recording* *accept-file* *trace-file* 
	   *write-file* *record-index* *max-record-index* *old-wm*
	   *record* *filters* *break-flag* *strategy* *remaining-cycles*
	   *wm-filter* *rhs-bound-vars* *rhs-bound-ce-vars* *ppline* 
	   *ce-count* *brkpts* *class-list* *buckets* *action-type*))

#|
(proclaim '(localf ce-gelm gelm peek-sublex sublex
		   eval-nodelist sendto and-left and-right not-left not-right
		   top-levels-eq add-token real-add-token remove-old
		   remove-old-num remove-old-no-num removecs insertcs dsort
		   best-of best-of* conflict-set-compare =alg))
|#



;;; Dario Giuse - July 2, 1984
;;; Two little unpleasant things. These are Common Lisp primitives, and we
;;; need to redefine them here.
;;;

; UNINTERN	COMMENTED OUT OF VAX LISP VERSION, SINCE COMPILER CAN'T
; HANDLE IT

; #-vms (unexport 'remove (find-package 'lisp))                 ;***DG***
; #-vms (unintern 'remove (find-package 'user))                 ;***DG***
; #+vms (shadow 'remove (find-package 'user))                   ;***DG***
        (shadow 'remove (find-package 'user))                   ;***DG***

;;; gdw changed name from 'remove' since DECLISP uses that fname.
(defmacro remove (&rest z)
  `(ops-remove ',z))

; #-vms (unexport 'write (find-package 'lisp))                  ;***DG***
; #-vms (unintern 'write (find-package 'user))                  ;***DG***
; #+vms (shadow 'write (find-package 'user))                    ;***DG***
        (shadow 'write (find-package 'user))                    ;***DG***

(defmacro write (&rest z)
  `(ops-write ',z))



;;; ------------------------------------------------------------


;;; Auxiliary macros added by JGK to convert the fexprs.
;;; Dario Giuse - converted to use regular Common Lisp defmacros.

(defmacro literal (&rest z)
  `(ops-literal ',z))

(defmacro literalize (&rest z)
  `(ops-literalize ',z))

(defmacro vector-attribute (&rest l)
  `(ops-vector-attribute ',l))

(defmacro p (&rest z) 
  `(ops-p ',z))

(defmacro wm (&rest a) 
  `(ops-wm ',a))

(defmacro make (&rest z)
  `(ops-make ',z))

(defmacro modify (&rest z)
  `(ops-modify ',z))

(defmacro bind (&rest z)
  `(ops-bind ',z))

(defmacro cbind (&rest z)
  `(ops-cbind ',z))

(defmacro call (&rest z)
  `(ops-call ',z))

(defmacro build (&rest z)
  `(ops-build ',z))

(defmacro openfile (&rest z)
  `(ops-openfile ',z))

(defmacro closefile (&rest z)
  `(ops-closefile ',z))

(defmacro default (&rest z)
  `(ops-default ',z))

(defmacro accept (&rest z)
  `(ops-accept ',z))

(defmacro acceptline (&rest z)
  `(ops-acceptline ',z))

(defmacro substr (&rest l)
  `(ops-substr ',l))

(defmacro compute (&rest z)
  `(ops-compute ',z))

(defmacro arith (&rest z)
  `(ops-arith ',z))

(defmacro litval (&rest z)
  `(ops-litval ',z))

(defmacro rjust (&rest z)
  `(ops-rjust ',z))

(defmacro crlf (&rest z)
  `(ops-crlf ',z))

(defmacro tabto (&rest z)
  `(ops-tabto ',z))

(defmacro ppwm (&rest avlist)
  `(ops-ppwm ',avlist))

(defmacro pm (&rest z)
  `(ops-pm ',z))

(defmacro matches (&rest rule-list)
  `(ops-matches ',rule-list))

(defmacro excise (&rest z)
  `(ops-excise ',z))

(defmacro run (&rest z)
  `(ops-run ',z))

(defmacro strategy (&rest z)
  `(ops-strategy ',z))

(defmacro cs (&rest z)
  `(ops-cs ',z))

(defmacro watch (&rest z)
  `(ops-watch ',z))

(defmacro external (&rest z) 
  `(ops-external ',z))

(defmacro pbreak (&rest z)
  `(ops-pbreak ',z))


;;; Functions that were revised so that they would compile efficiently

	   
;* The function == is machine dependent!
;* This function compares small integers for equality.  It uses EQ
;* so that it will be fast, and it will consequently not work on all
;* Lisps.  It works in Franz Lisp for integers in [-128, 127]
;(system::macro == (z) `(eq ,(cadr z) ,(caddr z)))
;;;
;;; Dario Giuse - made a macro. This is going to be faster than anything else.
;;;
(defmacro == (x y)
  `(equal ,x ,y))

;;; =ALG returns T if A and B are algebraically equal.
;;; This corresponds to equalp - Dario Giuse
;;;
(defmacro =alg (a b)
  `(equalp ,a ,b))

	   
(defmacro fast-symeval (&rest z)
  `(cond ((eq ,(car z) '*c1*) *c1*)
	 ((eq ,(car z) '*c2*) *c2*)
	 ((eq ,(car z) '*c3*) *c3*)
	 ((eq ,(car z) '*c4*) *c4*)
	 ((eq ,(car z) '*c5*) *c5*)
	 ((eq ,(car z) '*c6*) *c6*)
	 ((eq ,(car z) '*c7*) *c7*)
	 (t (eval ,(car z)))))

; getvector and putvector are fast routines for using ONE-DIMENSIONAL
; arrays.  these routines do no checking; they assume
;	1. the array is a vector with 0 being the index of the first
;	   element
;	2. the vector holds arbitrary list values

; Example call: (putvector array index value)
;;; Dario Giuse - 6/20/84

(defmacro putvector (array index value)
  `(setf (aref ,array ,index) ,value))

;;; Example call: (getvector name index)
;;;
(defmacro getvector (array index)
  `(aref ,array ,index))


;;; Dario Giuse  6/21/84
(defmacro putprop (atom value property)
  `(setf (get ,atom ,property) ,value))


(defun ce-gelm (x k)
; (declare (optimize speed))                                    ;***DG***
  (prog nil
    loop (and (== k 1.) (return (car x)))
    (setq k (1- k))
    (setq x (cdr x))
    (go loop))) 

; The loops in gelm were unwound so that fewer calls on DIFFERENCE
; would be needed

(defun gelm (x k)
  ; (locally) 				;@@@ locally isn't implemented yet
; (declare (optimize speed))                                    ;***DG***
  (prog (ce sub)
    (setq ce (truncate  k 10000.))		;use multiple-value-setq???
    (setq sub (- k (* ce 10000.)))		;@@@ ^
    
    celoop (and (eq ce 0.) (go ph2))
    (setq x (cdr x))
    (and (eq ce 1.) (go ph2))
    (setq x (cdr x))
    (and (eq ce 2.) (go ph2))
    (setq x (cdr x))
    (and (eq ce 3.) (go ph2))
    (setq x (cdr x))
    (and (eq ce 4.) (go ph2))
    (setq ce (- ce 4.))
    (go celoop)
    ph2  (setq x (car x))
    subloop (and (eq sub 0.) (go finis))
    (setq x (cdr x))
    (and (eq sub 1.) (go finis))
    (setq x (cdr x))
    (and (eq sub 2.) (go finis))
    (setq x (cdr x))
    (and (eq sub 3.) (go finis))
    (setq x (cdr x))
    (and (eq sub 4.) (go finis))
    (setq x (cdr x))
    (and (eq sub 5.) (go finis))
    (setq x (cdr x))
    (and (eq sub 6.) (go finis))
    (setq x (cdr x))
    (and (eq sub 7.) (go finis))
    (setq x (cdr x))
    (and (eq sub 8.) (go finis))
    (setq sub (- sub 8.))
    (go subloop)
    finis (return (car x))) ) ;  )  	;end prog,< locally >, defun


;;; Utility functions


	   
;;; intersect two lists using eq for the equality test
(defun interq (x y)
  (cond ((atom x) nil)
	((member (car x) y) (cons (car x) (interq (cdr x) y)))
	(t (interq (cdr x) y)))) 


(eval-when (compile load eval)
  (set-macro-character #\{ #'(lambda (s c)
			       (declare (ignore s c))
			       '\{))   ;5/5/83
  (set-macro-character #\} #'(lambda (s c)
			       (declare (ignore s c))
			       '\}))   ;5/5/83
  (set-macro-character #\^ #'(lambda (s c)
			       (declare (ignore s c))
			       '\^))   ;5/5/83
  )


(defun i-g-v nil
  (prog (x)
    ;	(sstatus translink t)   ;5/24/83
    ;@@@ moved set-macros out
    ;### kluge
    (setq *buckets* 127.)		; regular OPS5 allows 64 named slots
    (setq *accept-file* nil)
    (setq *write-file* nil)
    (setq *trace-file* nil)
    (setq *class-list* nil)
    (setq *brkpts* nil)
    (setq *strategy* 'lex)
    (setq *in-rhs* nil)
    (setq *ptrace* t)
    (setq *wtrace* nil)
    (setq *recording* nil)
    (setq *refracts* nil)
    (setq *real-cnt* (setq *virtual-cnt* 0.))
    (setq *max-cs* (setq *total-cs* 0.))
    (setq *limit-token* 1000000.)
    (setq *limit-cs* 1000000.)
    (setq *critical* nil)
    (setq *build-trace* nil)
    (setq *wmpart-list* nil)
    (setq *size-result-array* 255.)
    ;255 /256 set by gdw
    (setq *result-array* (make-array 256 :initial-element ()));jgk
    (setq *record-array* (make-array 256 :initial-element ()));jgk
    (setq x 0)
    loop	(putvector *result-array* x nil)
    (setq x (1+ x))				;"plus" changed to "+" by gdw
    (and (not (> x *size-result-array*)) (go loop))
    (make-bottom-node)
    (setq *pcount* 0.)
    (initialize-record)
    (setq *cycle-count* (setq *action-count* 0.))
    (setq *total-token*
	  (setq *max-token* (setq *current-token* 0.)))
    (setq *total-cs* (setq *max-cs* 0.))
    (setq *total-wm* (setq *max-wm* (setq *current-wm* 0.)))
    (setq *conflict-set* nil)
    (setq *wmpart-list* nil)
    (setq *p-name* nil)
    (setq *remaining-cycles* 1000000)))

; if the size of result-array changes, change the line in i-g-v which
; sets the value of *size-result-array*

(defun \%warn (what where)
  (prog nil
    (terpri)
    (princ '?)
    (and *p-name* (princ *p-name*))
;   (princ '|..|)
    (princ  "..")                                               ;***DG***
    (princ where)                                               ;***DG***
;   (princ '|..|)                                               ;***DG***
    (princ  "..")                                               ;***DG***
    (princ what)
    (return where))) 

(defun \%error (what where)
  (\%warn what where)
  (throw '!error! '!error!)) 	;jgk quoted arguments

;@@@(defun round (x) (fix (+ 0.5 x))) 		;"plus" changed to "+" by gdw
;@@@ removed; calls converted to native clisp (round)

(defun top-levels-eq (la lb)
  (prog nil
    lx   (cond ((eq la lb) (return t))
	       ((null la) (return nil))
	       ((null lb) (return nil))
	       ((not (eq (car la) (car lb))) (return nil)))
    (setq la (cdr la))
    (setq lb (cdr lb))
    (go lx))) 


;;; LITERAL and LITERALIZE

(defun ops-literal (z)
  (prog (atm val old)
    top  (and (atom z) (return 'bound))
    (or (eq (cadr z) '=) (return (\%warn '|wrong format| z)))
    (setq atm (car z))
    (setq val (caddr z))
    (setq z (cdddr z))
    (cond ((not (numberp val))
	   (\%warn '|can bind only to numbers| val))
	  ((or (not (symbolp atm)) (variablep atm))
	   (\%warn '|can bind only constant atoms| atm))
	  ((and (setq old (literal-binding-of atm)) (not (equal old val)))
	   (\%warn '|attempt to rebind attribute| atm))
	  (t (putprop atm val 'ops-bind)))
    (go top))) 


(defun ops-literalize (l)
  (prog (class-name atts)
    (setq class-name (car l))
    (cond ((have-compiled-production)
	   (\%warn '|literalize called after p| class-name)
	   (return nil))
	  ((get class-name 'att-list)
	   (\%warn '|attempt to redefine class| class-name)
	   (return nil)))
    (setq *class-list* (cons class-name *class-list*))
    (setq atts (remove-duplicates (cdr l)))		; ??? should this
    ; warn of dup atts?
    (test-attribute-names atts)
    (mark-conflicts atts atts)
    (putprop class-name atts 'att-list))) 

(defun ops-vector-attribute (l)
  (cond ((have-compiled-production)
	 (\%warn '|vector-attribute called after p| l))
	(t 
	 (test-attribute-names l)
	 (mapc (function vector-attribute2) l)))) 

(defun vector-attribute2 (att) (putprop att t 'vector-attribute))

(defun is-vector-attribute (att) (get att 'vector-attribute))

(defun test-attribute-names (l)
  (mapc (function test-attribute-names2) l)) 

(defun test-attribute-names2 (atm)
  (cond ((or (not (symbolp atm)) (variablep atm))
	 (\%warn '|can bind only constant atoms| atm)))) 

(defun finish-literalize nil
  (cond ((not (null *class-list*))
	 (mapc (function note-user-assigns) *class-list*)
	 (mapc (function assign-scalars) *class-list*)
	 (mapc (function assign-vectors) *class-list*)
	 (mapc (function put-ppdat) *class-list*)
	 (mapc (function erase-literal-info) *class-list*)
	 (setq *class-list* nil)
	 (setq *buckets* nil)))) 

(defun have-compiled-production nil (not (zerop *pcount*))) 
	   
(defun put-ppdat (class)
  (prog (al att ppdat)
    (setq ppdat nil)
    (setq al (get class 'att-list))
    top  (cond ((not (atom al))
		(setq att (car al))
		(setq al (cdr al))
		(setq ppdat
		      (cons (cons (literal-binding-of att) att)
			    ppdat))
		(go top)))
    (putprop class ppdat 'ppdat))) 

; note-user-assigns and note-user-vector-assigns are needed only when
; literal and literalize are both used in a program.  They make sure that
; the assignments that are made explicitly with literal do not cause problems
; for the literalized classes.

(defun note-user-assigns (class)
  (mapc (function note-user-assigns2) (get class 'att-list)))

(defun note-user-assigns2 (att)
  (prog (num conf buck clash)
    (setq num (literal-binding-of att))
    (and (null num) (return nil))
    (setq conf (get att 'conflicts))
    (setq buck (store-binding att num))
    (setq clash (find-common-atom buck conf))
    (and clash
	 (\%warn '|attributes in a class assigned the same number|
		(cons att clash)))
    (return nil)))

(defun note-user-vector-assigns (att given needed)
  (and (> needed given)
       (\%warn '|vector attribute assigned too small a value in literal| att)))

(defun assign-scalars (class)
  (mapc (function assign-scalars2) (get class 'att-list))) 

(defun assign-scalars2 (att)
  (prog (tlist num bucket conf)
    (and (literal-binding-of att) (return nil))
    (and (is-vector-attribute att) (return nil))
    (setq tlist (buckets))
    (setq conf (get att 'conflicts))
    top  (cond ((atom tlist)
		(\%warn '|could not generate a binding| att)
		(store-binding att -1.)
		(return nil)))
    (setq num (caar tlist))
    (setq bucket (cdar tlist))
    (setq tlist (cdr tlist))
    (cond ((disjoint bucket conf) (store-binding att num))
	  (t (go top))))) 

(defun assign-vectors (class)
  (mapc (function assign-vectors2) (get class 'att-list))) 

(defun assign-vectors2 (att)
  (prog (big conf new old need)
    (and (not (is-vector-attribute att)) (return nil))
    (setq big 1.)
    (setq conf (get att 'conflicts))
    top  (cond ((not (atom conf))
		(setq new (car conf))
		(setq conf (cdr conf))
		(cond ((is-vector-attribute new)
		       (\%warn '|class has two vector attributes|
			      (list att new)))
		      (t (setq big (max (literal-binding-of new) big))))
		(go top)))
    (setq need (1+ big))			;"plus" changed to "+" by gdw
    (setq old (literal-binding-of att))
    (cond (old (note-user-vector-assigns att old need))
	  (t (store-binding att need)))
    (return nil)))

(defun disjoint (la lb) (not (find-common-atom la lb))) 

(defun find-common-atom (la lb)
  (prog nil
    top  (cond ((null la) (return nil))
	       ((member (car la) lb) (return (car la)))
	       (t (setq la (cdr la)) (go top))))) 

(defun mark-conflicts (rem all)
  (cond ((not (null rem))
	 (mark-conflicts2 (car rem) all)
	 (mark-conflicts (cdr rem) all)))) 

(defun mark-conflicts2 (atm lst)
  (prog (l)
    (setq l lst)
    top  (and (atom l) (return nil))
    (conflict atm (car l))
    (setq l (cdr l))
    (go top))) 

(defun conflict (a b)
  (prog (old)
    (setq old (get a 'conflicts))
    (and (not (eq a b))
	 (not (member b old))
	 (putprop a (cons b old) 'conflicts)))) 

;@@@ use intrinsic 
;(defun remove-duplicates  (lst)
   ;  (cond ((atom lst) nil)
	    ;        ((member (car lst) (cdr lst)) (remove-duplicates (cdr lst)))
	    ;        (t (cons (car lst) (remove-duplicates (cdr lst)))))) 

(defun literal-binding-of (name) (get name 'ops-bind)) 

(defun store-binding (name lit)
  (putprop name lit 'ops-bind)
  (add-bucket name lit)) 

(defun add-bucket (name num)
  (prog (buc)
    (setq buc (assoc num (buckets)))
    (and (not (member name buc))
	 (rplacd buc (cons name (cdr buc))))
    (return buc))) 

(defun buckets nil
  (and (atom *buckets*) (setq *buckets* (make-nums *buckets*)))
  *buckets*) 

(defmacro ncons (x) `(cons ,x nil))

(defun make-nums (k)
  (prog (nums)
    (setq nums nil)
    l    (and (< k 2.) (return nums))
    (setq nums (cons (ncons k) nums))
    (setq k (1- k))
    (go l))) 

(defun erase-literal-info (class)
  (mapc (function erase-literal-info2) (get class 'att-list))
  (remprop class 'att-list)) 

(defun erase-literal-info2 (att) (remprop att 'conflicts)) 


;;; LHS Compiler

(defun ops-p (z) 
  (finish-literalize)
  (princ '*) 
  ;(drain) commented out temporarily
  (force-output)			;@@@ clisp drain?
  (compile-production (car z) (cdr z))) 

(defun compile-production (name matrix) ;jgk inverted args to catch 
  (prog (erm)				;and quoted tag
    (setq *p-name* name)
    (setq erm (catch '!error! (cmp-p name matrix)))
    (setq *p-name* nil)))

(defun peek-lex nil (car *matrix*)) 

(defun lex nil
  (prog2 nil (car *matrix*) (setq *matrix* (cdr *matrix*)))) 

(defun end-of-p nil (atom *matrix*)) 

(defun rest-of-p nil *matrix*) 

(defun prepare-lex (prod) (setq *matrix* prod)) 


(defun peek-sublex nil (car *curcond*)) 

(defun sublex nil
  (prog2 nil (car *curcond*) (setq *curcond* (cdr *curcond*)))) 

(defun end-of-ce nil (atom *curcond*)) 

(defun rest-of-ce nil *curcond*) 

(defun prepare-sublex (ce) (setq *curcond* ce)) 

(defun make-bottom-node nil (setq *first-node* (list '&bus nil))) 

(defun cmp-p (name matrix)
  (prog (m bakptrs)
    (cond ((or (null name) (consp  name))	;dtpr\consp gdw
	   (\%error '|illegal production name| name))
	  ((equal (get name 'production) matrix)
	   (return nil)))
    (prepare-lex matrix)
    (excise-p name)
    (setq bakptrs nil)
    (setq *pcount* (1+ *pcount*))		;"plus" changed to "+" by gdw
    (setq *feature-count* 0.)
    (setq *ce-count* 0)
    (setq *vars* nil)
    (setq *ce-vars* nil)
    (setq *rhs-bound-vars* nil)
    (setq *rhs-bound-ce-vars* nil)
    (setq *last-branch* nil)
    (setq m (rest-of-p))
    l1   (and (end-of-p) (\%error '|no '-->' in production| m))
    (cmp-prin)
    (setq bakptrs (cons *last-branch* bakptrs))
    (or (eq '--> (peek-lex)) (go l1))
    (lex)
    (check-rhs (rest-of-p))
    (link-new-node (list '&p
			 *feature-count*
			 name
			 (encode-dope)
			 (encode-ce-dope)
			 (cons 'progn (rest-of-p))))
    (putprop name (cdr (nreverse bakptrs)) 'backpointers)
    (putprop name matrix 'production)
    (putprop name *last-node* 'topnode))) 

(defun rating-part (pnode) (cadr pnode)) 

(defun var-part (pnode) (car (cdddr pnode))) 

(defun ce-var-part (pnode) (cadr (cdddr pnode))) 

(defun rhs-part (pnode) (caddr (cdddr pnode))) 

(defun excise-p (name)
  (cond ((and (symbolp name) (get name 'topnode))
	 (format t "~S is excised~\%" name)
	 (setq *pcount* (1- *pcount*))
	 (remove-from-conflict-set name)
	 (kill-node (get name 'topnode))
	 (remprop name 'production)
	 (remprop name 'backpointers)
	 (remprop name 'topnode)))) 

(defun kill-node (node)
  (prog nil
    top  (and (atom node) (return nil))
    (rplaca node '&old)
    (setq node (cdr node))
    (go top))) 

(defun cmp-prin nil
  (prog nil
    (setq *last-node* *first-node*)
    (cond ((null *last-branch*) (cmp-posce) (cmp-nobeta))
	  ((eq (peek-lex) '-) (cmp-negce) (cmp-not))
	  (t (cmp-posce) (cmp-and))))) 

(defun cmp-negce nil (lex) (cmp-ce)) 

(defun cmp-posce nil
  (setq *ce-count* (1+ *ce-count*))		;"plus" changed to "+" by gdw
  (cond ((eq (peek-lex) '\{) (cmp-ce+cevar))	;"plus" changed to "+" by gdw
	(t (cmp-ce)))) 

(defun cmp-ce+cevar nil
  (prog (z)
    (lex)
    (cond ((atom (peek-lex)) (cmp-cevar) (cmp-ce))
	  (t (cmp-ce) (cmp-cevar)))
    (setq z (lex))
    (or (eq z '\}) (\%error '|missing '}'| z)))) 

(defun new-subnum (k)
  (or (numberp k) (\%error '|tab must be a number| k))
  (setq *subnum* (fix k))) 

(defun incr-subnum nil (setq *subnum* (1+ *subnum*))) 

(defun cmp-ce nil
  (prog (z)
    (new-subnum 0.)
    (setq *cur-vars* nil)
    (setq z (lex))
    (and (atom z)
	 (\%error '|atomic conditions are not allowed| z))
    (prepare-sublex z)
    la   (and (end-of-ce) (return nil))
    (incr-subnum)
    (cmp-element)
    (go la))) 

(defun cmp-element nil
  (and (eq (peek-sublex) '^) (cmp-tab))
  (cond ((eq (peek-sublex) '\{) (cmp-product))
	(t (cmp-atomic-or-any))))

(defun cmp-atomic-or-any nil
  (cond ((eq (peek-sublex) '<<) (cmp-any))
	(t (cmp-atomic))))

(defun cmp-any nil
  (prog (a z)
    (sublex)
    (setq z nil)
    la   (cond ((end-of-ce) (\%error '|missing '>>'| a)))
    (setq a (sublex))
    (cond ((not (eq '>> a)) (setq z (cons a z)) (go la)))
    (link-new-node (list '&any nil (current-field) z)))) 


(defun cmp-tab nil
  (prog (r)
    (sublex)
    (setq r (sublex))
    (setq r ($litbind r))
    (new-subnum r))) 

(defun $litbind (x)
  (prog (r)
    (cond ((and (symbolp x) (setq r (literal-binding-of x)))
	   (return r))
	  (t (return x))))) 

(defun get-bind (x)
  (prog (r)
    (cond ((and (symbolp x) (setq r (literal-binding-of x)))
	   (return r))
	  (t (return nil))))) 

(defun cmp-atomic nil
  (prog (test x)
    (setq x (peek-sublex))
    (cond ((eq x '= ) (setq test 'eq) (sublex))
	  ((eq x '<>) (setq test 'ne) (sublex))
	  ((eq x '<) (setq test 'lt) (sublex))
	  ((eq x '<=) (setq test 'le) (sublex))
	  ((eq x '>) (setq test 'gt) (sublex))
	  ((eq x '>=) (setq test 'ge) (sublex))
	  ((eq x '<=>) (setq test 'xx) (sublex))
	  (t (setq test 'eq)))
    (cmp-symbol test))) 

(defun cmp-product nil
  (prog (save)
    (setq save (rest-of-ce))
    (sublex)
    la   (cond ((end-of-ce)
		(cond ((member '\} save :test #'equal) 
		       (\%error '|wrong contex for '}'| save))
		      (t (\%error '|missing '}'| save))))
	       ((eq (peek-sublex) '\}) (sublex) (return nil)))
    (cmp-atomic-or-any)
    (go la))) 


;here's my kluge to solve symbol-print-name
(defun symbol-print-name (x)
  (symbol-name x))

;(defun variablep (x) (and (symbolp x) ;changed from getchar form
			   ;			  (eq (char (symbol-print-name x) 0.) 
						      ;			      (char (symbol-print-name '<) 0.))))
;@@@ revision suggested by sf/inc. by gdw
(defun variablep (x)
  (and (symbolp x)
       (char= (char (symbol-name x) 0) #\< )))

(defun cmp-symbol (test)
  (prog (flag)
    (setq flag t)
    (cond ((eq (peek-sublex) '//) (sublex) (setq flag nil)))
    (cond ((and flag (variablep (peek-sublex)))
	   (cmp-var test))
	  ((numberp (peek-sublex)) (cmp-number test))
	  ((symbolp (peek-sublex)) (cmp-constant test))
	  (t (\%error '|unrecognized symbol| (sublex)))))) 

(defun cmp-constant (test)   ;jgk inserted concatenate form
  (or (member test '(eq ne xx))
      (\%error '|non-numeric constant after numeric predicate| (sublex)))
  (link-new-node (list (intern (concatenate 'string
					    (symbol-print-name 't)
					    (symbol-print-name  test)
					    (symbol-print-name 'a)))
		       nil
		       (current-field)
		       (sublex)))) 

(defun cmp-number (test)   ;jgk inserted concatenate form
  (link-new-node (list (intern (concatenate 'string
					    (symbol-print-name 't)
					    (symbol-print-name  test)
					    ;@@@ error? reported by laird fix\	    (symbol-print-name 'a)))
		       (symbol-print-name 'n)))
  nil
  (current-field)
  (sublex)))) 

(defun current-field nil (field-name *subnum*)) 

(defun field-name (num)
  (cond ((= num 1.) '*c1*)
	((= num 2.) '*c2*)
	((= num 3.) '*c3*)
	((= num 4.) '*c4*)
	((= num 5.) '*c5*)
	((= num 6.) '*c6*)
	((= num 7.) '*c7*)
	((= num 8.) '*c8*)
	((= num 9.) '*c9*)
	((= num 10.) '*c10*)
	((= num 11.) '*c11*)
	((= num 12.) '*c12*)
	((= num 13.) '*c13*)
	((= num 14.) '*c14*)
	((= num 15.) '*c15*)
	((= num 16.) '*c16*)
	((= num 17.) '*c17*)
	((= num 18.) '*c18*)
	((= num 19.) '*c19*)
	((= num 20.) '*c20*)
	((= num 21.) '*c21*)
	((= num 22.) '*c22*)
	((= num 23.) '*c23*)
	((= num 24.) '*c24*)
	((= num 25.) '*c25*)
	((= num 26.) '*c26*)
	((= num 27.) '*c27*)
	((= num 28.) '*c28*)
	((= num 29.) '*c29*)
	((= num 30.) '*c30*)
	((= num 31.) '*c31*)
	((= num 32.) '*c32*)
	((= num 33.) '*c33*)
	((= num 34.) '*c34*)
	((= num 35.) '*c35*)
	((= num 36.) '*c36*)
	((= num 37.) '*c37*)
	((= num 38.) '*c38*)
	((= num 39.) '*c39*)
	((= num 40.) '*c40*)
	((= num 41.) '*c41*)
	((= num 42.) '*c42*)
	((= num 43.) '*c43*)
	((= num 44.) '*c44*)
	((= num 45.) '*c45*)
	((= num 46.) '*c46*)
	((= num 47.) '*c47*)
	((= num 48.) '*c48*)
	((= num 49.) '*c49*)
	((= num 50.) '*c50*)
	((= num 51.) '*c51*)
	((= num 52.) '*c52*)
	((= num 53.) '*c53*)
	((= num 54.) '*c54*)
	((= num 55.) '*c55*)
	((= num 56.) '*c56*)
	((= num 57.) '*c57*)
	((= num 58.) '*c58*)
	((= num 59.) '*c59*)
	((= num 60.) '*c60*)
	((= num 61.) '*c61*)
	((= num 62.) '*c62*)
	((= num 63.) '*c63*)
	((= num 64.) '*c64*)
	((= num 65.) '*c65* ) 
	((= num 66.) '*c66* ) 
	((= num 67.) '*c67*)
	((= num 68.) '*c68*)
	((= num 69.) '*c69*)
	((= num 70.) '*c70*)
	((= num 71.) '*c71*)
	((= num 72.) '*c72*)
	((= num 73.) '*c73*)
	((= num 74.) '*c74*)
	((= num 75.) '*c75*)
	((= num 76.) '*c76*)
	((= num 77.) '*c77*)
	((= num 78.) '*c78*)
	((= num 79.) '*c79*)
	((= num 80.) '*c80*)
	((= num 81.) '*c81*)
	((= num 82.) '*c82*)
	((= num 83.) '*c83*)
	((= num 84.) '*c84*)
	((= num 85.) '*c85*)
	((= num 86.) '*c86*)
	((= num 87.) '*c87*)
	((= num 88.) '*c88*)
	((= num 89.) '*c89*)
	((= num 90.) '*c90*)
	((= num 91.) '*c91*)
	((= num 92.) '*c92*)
	((= num 93.) '*c93*)
	((= num 94.) '*c94*)
	((= num 95.) '*c95*)
	((= num 96.) '*c96*)
	((= num 97.) '*c97*)
	((= num 98.) '*c98*)
	((= num 99.) '*c99*)
	((= num 100.) '*c100*)
	((= num 101.) '*c101*)
	((= num 102.) '*c102*)
	((= num 103.) '*c103*)
	((= num 104.) '*c104*)
	((= num 105.) '*c105*)
	((= num 106.) '*c106*)
	((= num 107.) '*c107*)
	((= num 108.) '*c108*)
	((= num 109.) '*c109*)
	((= num 110.) '*c110*)
	((= num 111.) '*c111*)
	((= num 112.) '*c112*)
	((= num 113.) '*c113*)
	((= num 114.) '*c114*)
	((= num 115.) '*c115*)
	((= num 116.) '*c116*)
	((= num 117.) '*c117*)
	((= num 118.) '*c118*)
	((= num 119.) '*c119*)
	((= num 120.) '*c120*)
	((= num 121.) '*c121*)
	((= num 122.) '*c122*)
	((= num 123.) '*c123*)
	((= num 124.) '*c124*)
	((= num 125.) '*c125*)
	((= num 126.) '*c126*)
	((= num 127.) '*c127*)
	;	((= num 128.) '*c128*)
	
	(t (\%error '|condition is too long| (rest-of-ce))))) 


;;; Compiling variables
;
;
;
; *cur-vars* are the variables in the condition element currently 
; being compiled.  *vars* are the variables in the earlier condition
; elements.  *ce-vars* are the condition element variables.  note
; that the interpreter will not confuse condition element and regular
; variables even if they have the same name.
;
; *cur-vars* is a list of triples: (name predicate subelement-number)
; eg:		( (<x> eq 3)
		  ;		  (<y> ne 1)
		  ;		  . . . )
;
; *vars* is a list of triples: (name ce-number subelement-number)
; eg:		( (<x> 3 3)
		  ;		  (<y> 1 1)
		  ;		  . . . )
;
; *ce-vars* is a list of pairs: (name ce-number)
; eg:		( (ce1 1)
		  ;		  (<c3> 3)
		  ;		  . . . )
;@@@ defun' assq (should be replaced) ###
(defun assq (i l)(assoc i l))

(defun var-dope (var) (assq var *vars*))

(defun ce-var-dope (var) (assq var *ce-vars*))

(defun cmp-var (test)
  (prog (old name)
    (setq name (sublex))
    (setq old (assq name *cur-vars*))
    (cond ((and old (eq (cadr old) 'eq))
	   (cmp-old-eq-var test old))
	  ((and old (eq test 'eq)) (cmp-new-eq-var name old))
	  (t (cmp-new-var name test))))) 

(defun cmp-new-var (name test)
  (setq *cur-vars* (cons (list name test *subnum*) *cur-vars*))) 

(defun cmp-old-eq-var (test old)  ; jgk inserted concatenate form
  (link-new-node (list (intern (concatenate 'string
					    (symbol-print-name 't)
					    (symbol-print-name  test)
					    (symbol-print-name 's)))
		       nil
		       (current-field)
		       (field-name (caddr old))))) 

;@@@ added defunb of delq
(defun delq (i l)
  (delete i l :test #'eq))

;
; Spdelete "special delete" is a function which deletes every occurence
; of element from list. This function was defined because common lisp's
; delete function only deletes top level elements from a list, not lists
; from lists. 
;
(defun spdelete (element list)
  
  (cond ((null list) nil)
	((equal element (car list)) (spdelete element (cdr list)))
	(t (cons (car list) (spdelete element (cdr list))))))



(defun cmp-new-eq-var (name old)  ;jgk inserted concatenate form
  (prog (pred next)
    (setq *cur-vars* (delq old *cur-vars*))
    (setq next (assq name *cur-vars*))
    (cond (next (cmp-new-eq-var name next))
	  (t (cmp-new-var name 'eq)))
    (setq pred (cadr old))
    (link-new-node (list (intern (concatenate 'string
					      (symbol-print-name 't)
					      (symbol-print-name  pred)
					      (symbol-print-name 's)))
			 nil
			 (field-name (caddr old))
			 (current-field))))) 

(defun cmp-cevar nil
  (prog (name old)
    (setq name (lex))
    (setq old (assq name *ce-vars*))
    (and old
	 (\%error '|condition element variable used twice| name))
    (setq *ce-vars* (cons (list name 0.) *ce-vars*)))) 

(defun cmp-not nil (cmp-beta '&not)) 

(defun cmp-nobeta nil (cmp-beta nil)) 

(defun cmp-and nil (cmp-beta '&and)) 

(defun cmp-beta (kind)
  (prog (tlist vdope vname #|vpred vpos|# old)
    (setq tlist nil)
    la   (and (atom *cur-vars*) (go lb))
    (setq vdope (car *cur-vars*))
    (setq *cur-vars* (cdr *cur-vars*))
    (setq vname (car vdope))
    ;;  (setq vpred (cadr vdope))    Dario - commented out (unused)
    ;;  (setq vpos (caddr vdope))
    (setq old (assq vname *vars*))
    (cond (old (setq tlist (add-test tlist vdope old)))
	  ((not (eq kind '&not)) (promote-var vdope)))
    (go la)
    lb   (and kind (build-beta kind tlist))
    (or (eq kind '&not) (fudge))
    (setq *last-branch* *last-node*))) 

(defun add-test (list new old) ; jgk inserted concatenate form
  (prog (ttype lloc rloc)
    (setq *feature-count* (1+ *feature-count*))
    (setq ttype (intern (concatenate 'string (symbol-print-name 't)
				     (symbol-print-name (cadr new))
				     (symbol-print-name 'b))))
    (setq rloc (encode-singleton (caddr new)))
    (setq lloc (encode-pair (cadr old) (caddr old)))
    (return (cons ttype (cons lloc (cons rloc list)))))) 

; the following two functions encode indices so that gelm can
; decode them as fast as possible

(defun encode-pair (a b) (+ (* 10000. (1- a)) (1- b))) 
;"plus" changed to "+" by gdw

(defun encode-singleton (a) (1- a)) 

(defun promote-var (dope)
  (prog (vname vpred vpos new)
    (setq vname (car dope))
    (setq vpred (cadr dope))
    (setq vpos (caddr dope))
    (or (eq 'eq vpred)
	(\%error '|illegal predicate for first occurrence|
		(list vname vpred)))
    (setq new (list vname 0. vpos))
    (setq *vars* (cons new *vars*)))) 

(defun fudge nil
  (mapc (function fudge*) *vars*)
  (mapc (function fudge*) *ce-vars*)) 

(defun fudge* (z)
  (prog (a) (setq a (cdr z)) (rplaca a (1+ (car a))))) 

(defun build-beta (type tests)
  (prog (rpred lpred lnode lef)
    (link-new-node (list '&mem nil nil (protomem)))
    (setq rpred *last-node*)
    (cond ((eq type '&and)
	   (setq lnode (list '&mem nil nil (protomem))))
	  (t (setq lnode (list '&two nil nil))))
    (setq lpred (link-to-branch lnode))
    (cond ((eq type '&and) (setq lef lpred))
	  (t (setq lef (protomem))))
    (link-new-beta-node (list type nil lef rpred tests)))) 

(defun protomem nil (list nil)) 

(defun memory-part (mem-node) (car (cadddr mem-node))) 

(defun encode-dope nil
  (prog (r all z k)
    (setq r nil)
    (setq all *vars*)
    la   (and (atom all) (return r))
    (setq z (car all))
    (setq all (cdr all))
    (setq k (encode-pair (cadr z) (caddr z)))
    (setq r (cons (car z) (cons k r)))
    (go la))) 

(defun encode-ce-dope nil
  (prog (r all z k)
    (setq r nil)
    (setq all *ce-vars*)
    la   (and (atom all) (return r))
    (setq z (car all))
    (setq all (cdr all))
    (setq k (cadr z))
    (setq r (cons (car z) (cons k r)))
    (go la))) 



;;; Linking the nodes

(defun link-new-node (r)
  (cond ((not (member (car r) '(&p &mem &two &and &not) :test #'equal))
	 (setq *feature-count* (1+ *feature-count*))))
  (setq *virtual-cnt* (1+ *virtual-cnt*))
  (setq *last-node* (link-left *last-node* r))) 

(defun link-to-branch (r)
  (setq *virtual-cnt* (1+ *virtual-cnt*))
  (setq *last-branch* (link-left *last-branch* r))) 

(defun link-new-beta-node (r)
  (setq *virtual-cnt* (1+ *virtual-cnt*))
  (setq *last-node* (link-both *last-branch* *last-node* r))
  (setq *last-branch* *last-node*)) 

(defun link-left (pred succ)
  (prog (a r)
    (setq a (left-outs pred))
    (setq r (find-equiv-node succ a))
    (and r (return r))
    (setq *real-cnt* (1+ *real-cnt*))
    (attach-left pred succ)
    (return succ))) 

(defun link-both (left right succ)
  (prog (a r)
    (setq a (interq (left-outs left) (right-outs right)))
    (setq r (find-equiv-beta-node succ a))
    (and r (return r))
    (setq *real-cnt* (1+ *real-cnt*))
    (attach-left left succ)
    (attach-right right succ)
    (return succ))) 

(defun attach-right (old new)
  (rplaca (cddr old) (cons new (caddr old)))) 

(defun attach-left (old new)
  (rplaca (cdr old) (cons new (cadr old)))) 

(defun right-outs (node) (caddr node)) 

(defun left-outs (node) (cadr node)) 

(defun find-equiv-node (node list)
  (prog (a)
    (setq a list)
    l1   (cond ((atom a) (return nil))
	       ((equiv node (car a)) (return (car a))))
    (setq a (cdr a))
    (go l1))) 

(defun find-equiv-beta-node (node list)
  (prog (a)
    (setq a list)
    l1   (cond ((atom a) (return nil))
	       ((beta-equiv node (car a)) (return (car a))))
    (setq a (cdr a))
    (go l1))) 

; do not look at the predecessor fields of beta nodes; they have to be
; identical because of the way the candidate nodes were found

(defun equiv (a b)
  (and (eq (car a) (car b))
       (or (eq (car a) '&mem)
	   (eq (car a) '&two)
	   (equal (caddr a) (caddr b)))
       (equal (cdddr a) (cdddr b)))) 

(defun beta-equiv (a b)
  (and (eq (car a) (car b))
       (equal (cddddr a) (cddddr b))
       (or (eq (car a) '&and) (equal (caddr a) (caddr b))))) 

; the equivalence tests are set up to consider the contents of
; node memories, so they are ready for the build action

;;; Network interpreter

(defun match (flag wme)
  (sendto flag (list wme) 'left (list *first-node*)))

; note that eval-nodelist is not set up to handle building
; productions.  would have to add something like ops4's build-flag

(defun eval-nodelist (nl)
  (prog nil
    top  (and (not nl) (return nil))
    (setq *sendtocall* nil)
    (setq *last-node* (car nl))
    (apply (caar nl) (cdar nl))
    (setq nl (cdr nl))
    (go top))) 

(defun sendto (flag data side nl)
  (prog nil
    top  (and (not nl) (return nil))
    (setq *side* side)
    (setq *flag-part* flag)
    (setq *data-part* data)
    (setq *sendtocall* t)
    (setq *last-node* (car nl))
    (apply (caar nl) (cdar nl))
    (setq nl (cdr nl))
    (go top))) 

; &bus sets up the registers for the one-input nodes.  note that this
(defun &bus (outs)
  (prog (dp)
    (setq *alpha-flag-part* *flag-part*)
    (setq *alpha-data-part* *data-part*)
    (setq dp (car *data-part*))
    (setq *c1* (car dp))
    (setq dp (cdr dp))
    (setq *c2* (car dp))
    (setq dp (cdr dp))
    (setq *c3* (car dp))
    (setq dp (cdr dp))
    (setq *c4* (car dp))
    (setq dp (cdr dp))
    (setq *c5* (car dp))
    (setq dp (cdr dp))
    (setq *c6* (car dp))
    (setq dp (cdr dp))
    (setq *c7* (car dp))
    (setq dp (cdr dp))
    (setq *c8* (car dp))
    (setq dp (cdr dp))
    (setq *c9* (car dp))
    (setq dp (cdr dp))
    (setq *c10* (car dp))
    (setq dp (cdr dp))
    (setq *c11* (car dp))
    (setq dp (cdr dp))
    (setq *c12* (car dp))
    (setq dp (cdr dp))
    (setq *c13* (car dp))
    (setq dp (cdr dp))
    (setq *c14* (car dp))
    (setq dp (cdr dp))
    (setq *c15* (car dp))
    (setq dp (cdr dp))
    (setq *c16* (car dp))
    (setq dp (cdr dp))
    (setq *c17* (car dp))
    (setq dp (cdr dp))
    (setq *c18* (car dp))
    (setq dp (cdr dp))
    (setq *c19* (car dp))
    (setq dp (cdr dp))
    (setq *c20* (car dp))
    (setq dp (cdr dp))
    (setq *c21* (car dp))
    (setq dp (cdr dp))
    (setq *c22* (car dp))
    (setq dp (cdr dp))
    (setq *c23* (car dp))
    (setq dp (cdr dp))
    (setq *c24* (car dp))
    (setq dp (cdr dp))
    (setq *c25* (car dp))
    (setq dp (cdr dp))
    (setq *c26* (car dp))
    (setq dp (cdr dp))
    (setq *c27* (car dp))
    (setq dp (cdr dp))
    (setq *c28* (car dp))
    (setq dp (cdr dp))
    (setq *c29* (car dp))
    (setq dp (cdr dp))
    (setq *c30* (car dp))
    (setq dp (cdr dp))
    (setq *c31* (car dp))
    (setq dp (cdr dp))
    (setq *c32* (car dp))
    (setq dp (cdr dp))
    (setq *c33* (car dp))
    (setq dp (cdr dp))
    (setq *c34* (car dp))
    (setq dp (cdr dp))
    (setq *c35* (car dp))
    (setq dp (cdr dp))
    (setq *c36* (car dp))
    (setq dp (cdr dp))
    (setq *c37* (car dp))
    (setq dp (cdr dp))
    (setq *c38* (car dp))
    (setq dp (cdr dp))
    (setq *c39* (car dp))
    (setq dp (cdr dp))
    (setq *c40* (car dp))
    (setq dp (cdr dp))
    (setq *c41* (car dp))
    (setq dp (cdr dp))
    (setq *c42* (car dp))
    (setq dp (cdr dp))
    (setq *c43* (car dp))
    (setq dp (cdr dp))
    (setq *c44* (car dp))
    (setq dp (cdr dp))
    (setq *c45* (car dp))
    (setq dp (cdr dp))
    (setq *c46* (car dp))
    (setq dp (cdr dp))
    (setq *c47* (car dp))
    (setq dp (cdr dp))
    (setq *c48* (car dp))
    (setq dp (cdr dp))
    (setq *c49* (car dp))
    (setq dp (cdr dp))
    (setq *c50* (car dp))
    (setq dp (cdr dp))
    (setq *c51* (car dp))
    (setq dp (cdr dp))
    (setq *c52* (car dp))
    (setq dp (cdr dp))
    (setq *c53* (car dp))
    (setq dp (cdr dp))
    (setq *c54* (car dp))
    (setq dp (cdr dp))
    (setq *c55* (car dp))
    (setq dp (cdr dp))
    (setq *c56* (car dp))
    (setq dp (cdr dp))
    (setq *c57* (car dp))
    (setq dp (cdr dp))
    (setq *c58* (car dp))
    (setq dp (cdr dp))
    (setq *c59* (car dp))
    (setq dp (cdr dp))
    (setq *c60* (car dp))
    (setq dp (cdr dp))
    (setq *c61* (car dp))
    (setq dp (cdr dp))
    (setq *c62* (car dp))
    (setq dp (cdr dp))
    (setq *c63* (car dp))
    (setq dp (cdr dp))
    (setq *c64* (car dp))
    ;-------- added for 127 atr
    (setq dp (cdr dp))
    (setq *c65* (car dp))
    (setq dp (cdr dp))
    (setq *c66* (car dp))
    (setq dp (cdr dp))
    (setq *c67* (car dp))
    (setq dp (cdr dp))
    (setq *c68* (car dp))
    (setq dp (cdr dp))
    (setq *c69*(car dp))
    (setq dp (cdr dp))
    (setq *c70* (car dp))
    (setq dp (cdr dp))
    (setq *c71* (car dp))
    (setq dp (cdr dp))
    (setq *c72* (car dp))
    (setq dp (cdr dp))
    (setq *c73* (car dp))
    (setq dp (cdr dp))
    (setq *c74* (car dp))
    (setq dp (cdr dp))
    (setq *c75* (car dp))
    (setq dp (cdr dp))
    (setq *c76* (car dp))
    (setq dp (cdr dp))
    (setq *c77* (car dp))
    (setq dp (cdr dp))
    (setq *c78* (car dp))
    (setq dp (cdr dp))
    (setq *c79*(car dp))
    (setq dp (cdr dp))
    (setq *c80* (car dp))
    (setq dp (cdr dp))
    (setq *c81* (car dp))
    (setq dp (cdr dp))
    (setq *c82* (car dp))
    (setq dp (cdr dp))
    (setq *c83* (car dp))
    (setq dp (cdr dp))
    (setq *c84* (car dp))
    (setq dp (cdr dp))
    (setq *c85* (car dp))
    (setq dp (cdr dp))
    (setq *c86* (car dp))
    (setq dp (cdr dp))
    (setq *c87* (car dp))
    (setq dp (cdr dp))
    (setq *c88* (car dp))
    (setq dp (cdr dp))
    (setq *c89*(car dp))
    (setq dp (cdr dp))
    (setq *c90* (car dp))
    (setq dp (cdr dp))
    (setq *c91* (car dp))
    (setq dp (cdr dp))
    (setq *c92* (car dp))
    (setq dp (cdr dp))
    (setq *c93* (car dp))
    (setq dp (cdr dp))
    (setq *c94* (car dp))
    (setq dp (cdr dp))
    (setq *c95* (car dp))
    (setq dp (cdr dp))
    (setq *c96* (car dp))
    (setq dp (cdr dp))
    (setq *c97* (car dp))
    (setq dp (cdr dp))
    (setq *c98* (car dp))
    (setq dp (cdr dp))
    (setq *c99*(car dp))
    (setq dp (cdr dp))
    (setq *c100* (car dp))
    (setq dp (cdr dp))
    (setq *c101* (car dp))
    (setq dp (cdr dp))
    (setq *c102* (car dp))
    (setq dp (cdr dp))
    (setq *c103* (car dp))
    (setq dp (cdr dp))
    (setq *c104* (car dp))
    (setq dp (cdr dp))
    (setq *c105* (car dp))
    (setq dp (cdr dp))
    (setq *c106* (car dp))
    (setq dp (cdr dp))
    (setq *c107* (car dp))
    (setq dp (cdr dp))
    (setq *c108* (car dp))
    (setq dp (cdr dp))
    (setq *c109*(car dp))
    (setq dp (cdr dp))
    (setq *c110* (car dp))
    (setq dp (cdr dp))
    (setq *c111* (car dp))
    (setq dp (cdr dp))
    (setq *c112* (car dp))
    (setq dp (cdr dp))
    (setq *c113* (car dp))
    (setq dp (cdr dp))
    (setq *c114* (car dp))
    (setq dp (cdr dp))
    (setq *c115* (car dp))
    (setq dp (cdr dp))
    (setq *c116* (car dp))
    (setq dp (cdr dp))
    (setq *c117* (car dp))
    (setq dp (cdr dp))
    (setq *c118* (car dp))
    (setq dp (cdr dp))
    (setq *c119*(car dp))
    (setq dp (cdr dp))
    (setq *c120* (car dp))
    (setq dp (cdr dp))
    (setq *c121* (car dp))
    (setq dp (cdr dp))
    (setq *c122* (car dp))
    (setq dp (cdr dp))
    (setq *c123* (car dp))
    (setq dp (cdr dp))
    (setq *c124* (car dp))
    (setq dp (cdr dp))
    (setq *c125* (car dp))
    (setq dp (cdr dp))
    (setq *c126* (car dp))
    (setq dp (cdr dp))
    (setq *c127* (car dp))
    ;(setq dp (cdr dp))
    ;(setq *c128* (car dp))
    ;--------
    (eval-nodelist outs))) 

(defun &any (outs register const-list)
  (prog (z c)
    (setq z (symbol-value register))
    (cond ((numberp z) (go number)))
    symbol (cond ((null const-list) (return nil))
		 ((eq (car const-list) z) (go ok))
		 (t (setq const-list (cdr const-list)) (go symbol)))
    number (cond ((null const-list) (return nil))
		 ((and (numberp (setq c (car const-list)))
		       (=alg c z))
		  (go ok))
		 (t (setq const-list (cdr const-list)) (go number)))
    ok   (eval-nodelist outs))) 

(defun teqa (outs register constant)
  (and (eq (symbol-value register) constant) (eval-nodelist outs))) 

(defun tnea (outs register constant)
  (and (not (eq (symbol-value register) constant)) (eval-nodelist outs))) 

(defun txxa (outs register constant)
  (declare (ignore constant))
  (and (symbolp (symbol-value register)) (eval-nodelist outs))) 

(defun teqn (outs register constant)
  (prog (z)
    (setq z (symbol-value register))
    (and (numberp z)
	 (=alg z constant)
	 (eval-nodelist outs)))) 

(defun tnen (outs register constant)
  (prog (z)
    (setq z (symbol-value register))
    (and (or (not (numberp z))
	     (not (=alg z constant)))
	 (eval-nodelist outs)))) 

(defun txxn (outs register constant)
  (declare (ignore constant))
  (prog (z)
    (setq z (symbol-value register))
    (and (numberp z) (eval-nodelist outs)))) 

(defun tltn (outs register constant)
  (prog (z)
    (setq z (symbol-value register))
    (and (numberp z)
	 (> constant z)
	 (eval-nodelist outs)))) 

(defun tgtn (outs register constant)
  (prog (z)
    (setq z (symbol-value register))
    (and (numberp z)
	 (> z constant)
	 (eval-nodelist outs)))) 

(defun tgen (outs register constant)
  (prog (z)
    (setq z (symbol-value register))
    (and (numberp z)
	 (not (> constant z))
	 (eval-nodelist outs)))) 

(defun tlen (outs register constant)
  (prog (z)
    (setq z (symbol-value register))
    (and (numberp z)
	 (not (> z constant))
	 (eval-nodelist outs)))) 

(defun teqs (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (cond ((eq a b) (eval-nodelist outs))
	  ((and (numberp a)
		(numberp b)
		(=alg a b))
	   (eval-nodelist outs))))) 

(defun tnes (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (cond ((eq a b) (return nil))
	  ((and (numberp a)
		(numberp b)
		(=alg a b))
	   (return nil))
	  (t (eval-nodelist outs))))) 

(defun txxs (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (cond ((and (numberp a) (numberp b)) (eval-nodelist outs))
	  ((and (not (numberp a)) (not (numberp b)))
	   (eval-nodelist outs))))) 

(defun tlts (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (and (numberp a)
	 (numberp b)
	 (> b a)
	 (eval-nodelist outs)))) 

(defun tgts (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (and (numberp a)
	 (numberp b)
	 (> a b)
	 (eval-nodelist outs)))) 

(defun tges (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (and (numberp a)
	 (numberp b)
	 (not (> b a))
	 (eval-nodelist outs)))) 

(defun tles (outs vara varb)
  (prog (a b)
    (setq a (symbol-value vara))
    (setq b (symbol-value varb))
    (and (numberp a)
	 (numberp b)
	 (not (> a b))
	 (eval-nodelist outs)))) 

(defun &two (left-outs right-outs)
  (prog (fp dp)
    (cond (*sendtocall*
	   (setq fp *flag-part*)
	   (setq dp *data-part*))
	  (t
	   (setq fp *alpha-flag-part*)
	   (setq dp *alpha-data-part*)))
    (sendto fp dp 'left left-outs)
    (sendto fp dp 'right right-outs))) 

(defun &mem (left-outs right-outs memory-list)
  (prog (fp dp)
    (cond (*sendtocall*
	   (setq fp *flag-part*)
	   (setq dp *data-part*))
	  (t
	   (setq fp *alpha-flag-part*)
	   (setq dp *alpha-data-part*)))
    (sendto fp dp 'left left-outs)
    (add-token memory-list fp dp nil)
    (sendto fp dp 'right right-outs))) 

(defun &and (outs lpred rpred tests)
  (prog (mem)
    (cond ((eq *side* 'right) (setq mem (memory-part lpred)))
	  (t (setq mem (memory-part rpred))))
    (cond ((not mem) (return nil))
	  ((eq *side* 'right) (and-right outs mem tests))
	  (t (and-left outs mem tests))))) 

(defun and-left (outs mem tests)
  (prog (fp dp memdp tlist tst lind rind res)
    (setq fp *flag-part*)
    (setq dp *data-part*)
    fail (and (null mem) (return nil))
    (setq memdp (car mem))
    (setq mem (cdr mem))
    (setq tlist tests)
    tloop (and (null tlist) (go succ))
    (setq tst (car tlist))
    (setq tlist (cdr tlist))
    (setq lind (car tlist))
    (setq tlist (cdr tlist))
    (setq rind (car tlist))
    (setq tlist (cdr tlist))
    ;###        (comment the next line differs in and-left & -right)
    (setq res (funcall tst (gelm memdp rind) (gelm dp lind)))
    (cond (res (go tloop))
	  (t (go fail)))
    succ 
    ;###	(comment the next line differs in and-left & -right)
    (sendto fp (cons (car memdp) dp) 'left outs)
    (go fail))) 

(defun and-right (outs mem tests)
  (prog (fp dp memdp tlist tst lind rind res)
    (setq fp *flag-part*)
    (setq dp *data-part*)
    fail (and (null mem) (return nil))
    (setq memdp (car mem))
    (setq mem (cdr mem))
    (setq tlist tests)
    tloop (and (null tlist) (go succ))
    (setq tst (car tlist))
    (setq tlist (cdr tlist))
    (setq lind (car tlist))
    (setq tlist (cdr tlist))
    (setq rind (car tlist))
    (setq tlist (cdr tlist))
    ;###        (comment the next line differs in and-left & -right)
    (setq res (funcall tst (gelm dp rind) (gelm memdp lind)))
    (cond (res (go tloop))
	  (t (go fail)))
    succ 
    ;###        (comment the next line differs in and-left & -right)
    (sendto fp (cons (car dp) memdp) 'right outs)
    (go fail))) 


(defun teqb (new eqvar)
  (cond ((eq new eqvar) t)
	((not (numberp new)) nil)
	((not (numberp eqvar)) nil)
	((=alg new eqvar) t)
	(t nil))) 

(defun tneb (new eqvar)
  (cond ((eq new eqvar) nil)
	((not (numberp new)) t)
	((not (numberp eqvar)) t)
	((=alg new eqvar) nil)
	(t t))) 

(defun tltb (new eqvar)
  (cond ((not (numberp new)) nil)
	((not (numberp eqvar)) nil)
	((> eqvar new) t)
	(t nil))) 

(defun tgtb (new eqvar)
  (cond ((not (numberp new)) nil)
	((not (numberp eqvar)) nil)
	((> new eqvar) t)
	(t nil))) 

(defun tgeb (new eqvar)
  (cond ((not (numberp new)) nil)
	((not (numberp eqvar)) nil)
	((not (> eqvar new)) t)
	(t nil))) 

(defun tleb (new eqvar)
  (cond ((not (numberp new)) nil)
	((not (numberp eqvar)) nil)
	((not (> new eqvar)) t)
	(t nil))) 

(defun txxb (new eqvar)
  (cond ((numberp new)
	 (cond ((numberp eqvar) t)
	       (t nil)))
	(t
	 (cond ((numberp eqvar) nil)
	       (t t))))) 


(defun &p (rating name var-dope ce-var-dope rhs)
  (declare (ignore var-dope ce-var-dope rhs))
  (prog (fp dp)
    (cond (*sendtocall*
	   (setq fp *flag-part*)
	   (setq dp *data-part*))
	  (t
	   (setq fp *alpha-flag-part*)
	   (setq dp *alpha-data-part*)))
    (and (member fp '(nil old)) (removecs name dp))
    (and fp (insertcs name dp rating)))) 

(defun &old (a b c d e)
  (declare (ignore a b c d e))
  nil) 

(defun &not (outs lmem rpred tests)
  (cond ((and (eq *side* 'right) (eq *flag-part* 'old)) nil)
	((eq *side* 'right) (not-right outs (car lmem) tests))
	(t (not-left outs (memory-part rpred) tests lmem)))) 

(defun not-left (outs mem tests own-mem)
  (prog (fp dp memdp tlist tst lind rind res c)
    (setq fp *flag-part*)
    (setq dp *data-part*)
    (setq c 0.)
    fail (and (null mem) (go fin))
    (setq memdp (car mem))
    (setq mem (cdr mem))
    (setq tlist tests)
    tloop (and (null tlist) (setq c (1+ c)) (go fail))
    (setq tst (car tlist))
    (setq tlist (cdr tlist))
    (setq lind (car tlist))
    (setq tlist (cdr tlist))
    (setq rind (car tlist))
    (setq tlist (cdr tlist))
    ;###        (comment the next line differs in not-left & -right)
    (setq res (funcall tst (gelm memdp rind) (gelm dp lind)))
    (cond (res (go tloop))
	  (t (go fail)))
    fin  (add-token own-mem fp dp c)
    (and (== c 0.) (sendto fp dp 'left outs)))) 

(defun not-right (outs mem tests)
  (prog (fp dp memdp tlist tst lind rind res newfp inc newc)
    (setq fp *flag-part*)
    (setq dp *data-part*)
    (cond ((not fp) (setq inc -1.) (setq newfp 'new))
	  ((eq fp 'new) (setq inc 1.) (setq newfp nil))
	  (t (return nil)))
    fail (and (null mem) (return nil))
    (setq memdp (car mem))
    (setq newc (cadr mem))
    (setq tlist tests)
    tloop (and (null tlist) (go succ))
    (setq tst (car tlist))
    (setq tlist (cdr tlist))
    (setq lind (car tlist))
    (setq tlist (cdr tlist))
    (setq rind (car tlist))
    (setq tlist (cdr tlist))
    ;###        (comment the next line differs in not-left & -right)
    (setq res (funcall tst (gelm dp rind) (gelm memdp lind)))
    (cond (res (go tloop))
	  (t (setq mem (cddr mem)) (go fail)))
    succ (setq newc (+ inc newc))		;"plus" changed to "+" by gdw
    (rplaca (cdr mem) newc)
    (cond ((or (and (== inc -1.) (== newc 0.))
	       (and (== inc 1.) (== newc 1.)))
	   (sendto newfp memdp 'right outs)))
    (setq mem (cddr mem))
    (go fail))) 



;;; Node memories


(defun add-token (memlis flag data-part num)
  (prog (was-present)
    (cond ((eq flag 'new)
	   (setq was-present nil)
	   (real-add-token memlis data-part num))
	  ((not flag) 
	   (setq was-present (remove-old memlis data-part num)))
	  ((eq flag 'old) (setq was-present t)))
    (return was-present))) 

(defun real-add-token (lis data-part num)
  (setq *current-token* (1+ *current-token*))
  (cond (num (rplaca lis (cons num (car lis)))))
  (rplaca lis (cons data-part (car lis)))) 

(defun remove-old (lis data num)
  (cond (num (remove-old-num lis data))
	(t (remove-old-no-num lis data)))) 

(defun remove-old-num (lis data)
  (prog (m next last)
    (setq m (car lis))
    (cond ((atom m) (return nil))
	  ((top-levels-eq data (car m))
	   (setq *current-token* (1- *current-token*))
	   (rplaca lis (cddr m))
	   (return (car m))))
    (setq next m)
    loop (setq last next)
    (setq next (cddr next))
    (cond ((atom next) (return nil))
	  ((top-levels-eq data (car next))
	   (rplacd (cdr last) (cddr next))
	   (setq *current-token* (1- *current-token*))
	   (return (car next)))
	  (t (go loop))))) 

(defun remove-old-no-num (lis data)
  (prog (m next last)
    (setq m (car lis))
    (cond ((atom m) (return nil))
	  ((top-levels-eq data (car m))
	   (setq *current-token* (1- *current-token*))
	   (rplaca lis (cdr m))
	   (return (car m))))
    (setq next m)
    loop (setq last next)
    (setq next (cdr next))
    (cond ((atom next) (return nil))
	  ((top-levels-eq data (car next))
	   (rplacd last (cdr next))
	   (setq *current-token* (1- *current-token*))
	   (return (car next)))
	  (t (go loop))))) 



;;; Conflict Resolution
;
;
; each conflict set element is a list of the following form:
; ((p-name . data-part) (sorted wm-recency) special-case-number)

(defun removecs (name data)
  (prog (cr-data inst cs)
    (setq cr-data (cons name data))
    (setq cs *conflict-set*)
    loop	(cond ((null cs) 
		       (record-refract name data)
		       (return nil)))
    (setq inst (car cs))
    (setq cs (cdr cs))
    (and (not (top-levels-eq (car inst) cr-data)) (go loop))
    (setq *conflict-set* (delq inst *conflict-set*))))

(defun insertcs (name data rating)
  (prog (instan)
    (and (refracted name data) (return nil))
    (setq instan (list (cons name data) (order-tags data) rating))
    (and (atom *conflict-set*) (setq *conflict-set* nil))
    (return (setq *conflict-set* (cons instan *conflict-set*))))) 

(defun order-tags (dat)
  (prog (tags)
    (setq tags nil)
    l1p  (and (atom dat) (go l2p))
    (setq tags (cons (creation-time (car dat)) tags))
    (setq dat (cdr dat))
    (go l1p)
    l2p  (cond ((eq *strategy* 'mea)
		(return (cons (car tags) (dsort (cdr tags)))))
	       (t (return (dsort tags)))))) 

; destructively sort x into descending order

(defun dsort (x)
  (prog (sorted cur next cval nval)
    (and (atom (cdr x)) (return x))
    loop (setq sorted t)
    (setq cur x)
    (setq next (cdr x))
    chek (setq cval (car cur))
    (setq nval (car next))
    (cond ((> nval cval)
	   (setq sorted nil)
	   (rplaca cur nval)
	   (rplaca next cval)))
    (setq cur next)
    (setq next (cdr cur))
    (cond ((not (null next)) (go chek))
	  (sorted (return x))
	  (t (go loop))))) 

(defun conflict-resolution nil
  (prog (best len)
    (setq len (length *conflict-set*))
    (cond ((> len *max-cs*) (setq *max-cs* len)))
    (setq *total-cs* (+ *total-cs* len))	;"plus" changed to "+" by gdw
    (cond (*conflict-set*
	   (setq best (best-of *conflict-set*))
	   (setq *conflict-set* (delq best *conflict-set*))
	   (return (pname-instantiation best)))
	  (t (return nil))))) 

(defun best-of (set) (best-of* (car set) (cdr set))) 

(defun best-of* (best rem)
  (cond ((not rem) best)
	((conflict-set-compare best (car rem))
	 (best-of* best (cdr rem)))
	(t (best-of* (car rem) (cdr rem))))) 

(defun remove-from-conflict-set (name)
  (prog (cs entry)
    l1   (setq cs *conflict-set*)
    l2   (cond ((atom cs) (return nil)))
    (setq entry (car cs))
    (setq cs (cdr cs))
    (cond ((eq name (caar entry))
	   (setq *conflict-set* (delq entry *conflict-set*))
	   (go l1))
	  (t (go l2))))) 

(defun pname-instantiation (conflict-elem) (car conflict-elem)) 

(defun order-part (conflict-elem) (cdr conflict-elem)) 

(defun instantiation (conflict-elem)
  (cdr (pname-instantiation conflict-elem))) 


(defun conflict-set-compare (x y)
  (prog (x-order y-order xl yl xv yv)
    (setq x-order (order-part x))
    (setq y-order (order-part y))
    (setq xl (car x-order))
    (setq yl (car y-order))
    data (cond ((and (null xl) (null yl)) (go ps))
	       ((null yl) (return t))
	       ((null xl) (return nil)))
    (setq xv (car xl))
    (setq yv (car yl))
    (cond ((> xv yv) (return t))
	  ((> yv xv) (return nil)))
    (setq xl (cdr xl))
    (setq yl (cdr yl))
    (go data)
    ps   (setq xl (cdr x-order))
    (setq yl (cdr y-order))
    psl  (cond ((null xl) (return t)))
    (setq xv (car xl))
    (setq yv (car yl))
    (cond ((> xv yv) (return t))
	  ((> yv xv) (return nil)))
    (setq xl (cdr xl))
    (setq yl (cdr yl))
    (go psl))) 


(defun conflict-set nil
  (prog (cnts cs p z best)
    (setq cnts nil)
    (setq cs *conflict-set*)
    l1p  (and (atom cs) (go l2p))
    (setq p (caaar cs))
    (setq cs (cdr cs))
    (setq z (assq p cnts))
    (cond ((null z) (setq cnts (cons (cons p 1.) cnts)))
	  (t (rplacd z (1+ (cdr z)))))
    (go l1p)
    l2p  (cond ((atom cnts)
		(setq best (best-of *conflict-set*))
		(terpri)
		(return (list (caar best) 'dominates))))
    (terpri)
    (princ (caar cnts))
    (cond ((> (cdar cnts) 1.)
	   (princ '|	(|)
		  (princ (cdar cnts))
		  (princ '| occurrences)|)))
    (setq cnts (cdr cnts))
    (go l2p))) 



;;; WM maintaining functions
;
; The order of operations in the following two functions is critical.
; add-to-wm order: (1) change wm (2) record change (3) match 
; remove-from-wm order: (1) record change (2) match (3) change wm
; (back will not restore state properly unless wm changes are recorded
	; before the cs changes that they cause)  (match will give errors if 
							 ; the thing matched is not in wm at the time)


(defun add-to-wm (wme override)
  (prog (fa z part timetag port)
    (setq *critical* t)
    (setq *current-wm* (1+ *current-wm*))
    (and (> *current-wm* *max-wm*) (setq *max-wm* *current-wm*))
    (setq *action-count* (1+ *action-count*))
    (setq fa (wm-hash wme))
    (or (member fa *wmpart-list*)
	(setq *wmpart-list* (cons fa *wmpart-list*)))
    (setq part (get fa 'wmpart*))
    (cond (override (setq timetag override))
	  (t (setq timetag *action-count*)))
    (setq z (cons wme timetag))
    (putprop fa (cons z part) 'wmpart*)
    (record-change '=>wm *action-count* wme)
    (match 'new wme)
    (setq *critical* nil)
    (cond ((and *in-rhs* *wtrace*)
	   (setq port (trace-file))
	   (terpri port)
	   (princ '|=>wm: | port)
	   (ppelm wme port))))) 

; remove-from-wm uses eq, not equal to determine if wme is present

(defun remove-from-wm (wme)
  (prog (fa z part timetag port)
    (setq fa (wm-hash wme))
    (setq part (get fa 'wmpart*))
    (setq z (assq wme part))
    (or z (return nil))
    (setq timetag (cdr z))
    (cond ((and *wtrace* *in-rhs*)
	   (setq port (trace-file))
	   (terpri port)
	   (princ '|<=wm: | port)
	   (ppelm wme port)))
    (setq *action-count* (1+ *action-count*))
    (setq *critical* t)
    (setq *current-wm* (1- *current-wm*))
    (record-change '<=wm timetag wme)
    (match nil wme)
    (putprop fa (delq z part) 'wmpart*)
    (setq *critical* nil))) 

; mapwm maps down the elements of wm, applying fn to each element
; each element is of form (datum . creation-time)

(defun mapwm (fn)
  (prog (wmpl part)
    (setq wmpl *wmpart-list*)
    lab1 (cond ((atom wmpl) (return nil)))
    (setq part (get (car wmpl) 'wmpart*))
    (setq wmpl (cdr wmpl))
    (mapc fn part)
    (go lab1))) 

(defun ops-wm (a) 
  (mapc (function (lambda (z) (terpri) (ppelm z *standard-output*))) 
	(get-wm a))
  nil) 

(defun get-wm (z)
  (setq *wm-filter* z)
  (setq *wm* nil)
  (mapwm (function get-wm2))
  (prog2 nil *wm* (setq *wm* nil))) 

(defun get-wm2 (elem) 
  ; (cond ((or (null *wm-filter*) (member (cdr elem) *wm-filter*) :test #'equal)))
  (cond ((or (null *wm-filter*) (member (cdr elem) *wm-filter*)) ;test #'equal)
	(setq *wm* (cons (car elem) *wm*)))))

(defun wm-hash (x)
  (cond ((not x) '<default>)
	((not (car x)) (wm-hash (cdr x)))
	((symbolp (car x)) (car x))
	(t (wm-hash (cdr x))))) 

(defun creation-time (wme)
  (cdr (assq wme (get (wm-hash wme) 'wmpart*)))) 

(defun refresh nil
  (prog nil
    (setq *old-wm* nil)
    (mapwm (function refresh-collect))
    (mapc (function refresh-del) *old-wm*)
    (mapc (function refresh-add) *old-wm*)
    (setq *old-wm* nil))) 

(defun refresh-collect (x) (setq *old-wm* (cons x *old-wm*))) 

(defun refresh-del (x) (remove-from-wm (car x))) 

(defun refresh-add (x) (add-to-wm (car x) (cdr x))) 

(defun trace-file ()
  (prog (port)
    (setq port *standard-output*)
    (cond (*trace-file*
	   (setq port ($ofile *trace-file*))
	   (cond ((null port)
		  (\%warn '|trace: file has been closed| *trace-file*)
		  (setq port *standard-output*)))))
    (return port)))


;;; Basic functions for RHS evaluation

(defun eval-rhs (pname data)
  (prog (node port)
    (cond (*ptrace*
	   (setq port (trace-file))
	   (terpri port)
	   (princ *cycle-count* port)
	   (princ '|. | port)
	   (princ pname port)
	   (time-tag-print data port)))
    (setq *data-matched* data)
    (setq *p-name* pname)
    (setq *last* nil)
    (setq node (get pname 'topnode))
    (init-var-mem (var-part node))
    (init-ce-var-mem (ce-var-part node))
    (begin-record pname data)
    (setq *in-rhs* t)
    (eval (rhs-part node))
    (setq *in-rhs* nil)
    (end-record))) 

(defun time-tag-print (data port)
  (cond ((not (null data))
	 (time-tag-print (cdr data) port)
	 (princ '| | port)
	 (princ (creation-time (car data)) port))))

(defun init-var-mem (vlist)
  (prog (v ind r)
    (setq *variable-memory* nil)
    top  (and (atom vlist) (return nil))
    (setq v (car vlist))
    (setq ind (cadr vlist))
    (setq vlist (cddr vlist))
    (setq r (gelm *data-matched* ind))
    (setq *variable-memory* (cons (cons v r) *variable-memory*))
    (go top))) 

(defun init-ce-var-mem (vlist)
  (prog (v ind r)
    (setq *ce-variable-memory* nil)
    top  (and (atom vlist) (return nil))
    (setq v (car vlist))
    (setq ind (cadr vlist))
    (setq vlist (cddr vlist))
    (setq r (ce-gelm *data-matched* ind))
    (setq *ce-variable-memory*
	  (cons (cons v r) *ce-variable-memory*))
    (go top))) 

(defun make-ce-var-bind (var elem)
  (setq *ce-variable-memory*
	(cons (cons var elem) *ce-variable-memory*))) 

(defun make-var-bind (var elem)
  (setq *variable-memory* (cons (cons var elem) *variable-memory*))) 

(defun $varbind (x)
  (prog (r)
    (and (not *in-rhs*) (return x))
    (setq r (assq x *variable-memory*))
    (cond (r (return (cdr r)))
	  (t (return x))))) 

(defun get-ce-var-bind (x)
  (prog (r)
    (cond ((numberp x) (return (get-num-ce x))))
    (setq r (assq x *ce-variable-memory*))
    (cond (r (return (cdr r)))
	  (t (return nil))))) 

(defun get-num-ce (x)
  (prog (r l d)
    (setq r *data-matched*)
    (setq l (length r))
    (setq d (- l x))
    (and (> 0. d) (return nil))
    la   (cond ((null r) (return nil))
	       ((> 1. d) (return (car r))))
    (setq d (1- d))
    (setq r (cdr r))
    (go la))) 


(defun build-collect (z)
  (prog (r)
    la   (and (atom z) (return nil))
    (setq r (car z))
    (setq z (cdr z))
    (cond ((consp  r)	;dtpr\consp gdw
	   ($value '\()
		   (build-collect r)
		   ($value '\)))
	  ((eq r '\\) ($change (car z)) (setq z (cdr z)))
	  (t ($value r)))
    (go la))) 

(defun unflat (x) (setq *rest* x) (unflat*)) 

(defun unflat* nil
  (prog (c)
    (cond ((atom *rest*) (return nil)))
    (setq c (car *rest*))
    (setq *rest* (cdr *rest*))
    (cond ((eq c '\() (return (cons (unflat*) (unflat*))))
	   ((eq c '\)) (return nil))
	  (t (return (cons c (unflat*))))))) 


(defun $change (x)
  (prog nil
    (cond ((consp  x) (eval-function x))	;dtpr\consp gdw
	  (t ($value ($varbind x)))))) 

(defun eval-args (z)
  (prog (r)
    (rhs-tab 1.)
    la   (and (atom z) (return nil))
    (setq r (car z))
    (setq z (cdr z))
    (cond ((EQ R '^)
	   (RHS-tab (car z))
	   (setq r (cadr z))
	   (setq z (cddr z))))
    (cond ((eq r '//) ($value (car z)) (setq z (cdr z)))
	  (t ($change r)))
    (go la))) 


(defun eval-function (form)
  (cond ((not *in-rhs*)
	 (\%warn '|functions cannot be used at top level| (car form)))
	(t (eval form))))


;;; Functions to manipulate the result array


(defun $reset nil
  (setq *max-index* 0.)
  (setq *next-index* 1.)) 

; rhs-tab implements the tab ('^') function in the rhs.  it has
; four responsibilities:
;	- to move the array pointers
;	- to watch for tabbing off the left end of the array
;	  (ie, to watch for pointers less than 1)
;	- to watch for tabbing off the right end of the array
;	- to write nil in all the slots that are skipped
; the last is necessary if the result array is not to be cleared
; after each use; if rhs-tab did not do this, $reset
; would be much slower.

(defun rhs-tab (z) ($tab ($varbind z)))

(defun $tab (z)
  (prog (edge next)
    (setq next ($litbind z))
    (and (floatp next) (setq next (fix next)))
    (cond ((or (not (numberp next)) 
	       (> next *size-result-array*)
	       (> 1. next))				; ( '| |)
	   (\%warn '|illegal index after ^| next)
	   (return *next-index*)))
    (setq edge (- next 1.))
    (cond ((> *max-index* edge) (go ok)))
    clear (cond ((== *max-index* edge) (go ok)))
    (putvector *result-array* edge nil)
    (setq edge (1- edge))
    (go clear)
    ok   (setq *next-index* next)
    (return next))) 

(defun $value (v)
  (cond ((> *next-index* *size-result-array*)
	 (\%warn '|index too large| *next-index*))
	(t
	 (and (> *next-index* *max-index*)
	      (setq *max-index* *next-index*))
	 (putvector *result-array* *next-index* v)
	 (setq *next-index* (1+ *next-index*))))) 


(defun use-result-array nil
  (prog (k r)
    (setq k *max-index*)
    (setq r nil)
    top  (and (== k 0.) (return r))
    (setq r (cons (getvector *result-array* k) r))
    (setq k (1- k))
    (go top))) 

(defun $assert nil
  (setq *last* (use-result-array))
  (add-to-wm *last* nil))

(defun $parametercount nil *max-index*)

(defun $parameter (k)
  (cond ((or (not (numberp k)) (> k *size-result-array*) (< k 1.))
	 (\%warn '|illegal parameter number | k)
	 nil)
	((> k *max-index*) nil)
	(t (getvector *result-array* k))))


;;; RHS actions

(defun ops-make (z)
  (prog nil
    ($reset)
    (eval-args z)
    ($assert))) 

(defun ops-modify (z)
  (prog (old)
    (cond ((not *in-rhs*)
	   (\%warn '|cannot be called at top level| 'modify)
	   (return nil)))
    (setq old (get-ce-var-bind (car z)))
    (cond ((null old)
	   (\%warn '|modify: first argument must be an element variable|
		  (car z))
	   (return nil)))
    (remove-from-wm old)
    (setq z (cdr z))
    ($reset)
    copy (and (atom old) (go fin))
    ($change (car old))
    (setq old (cdr old))
    (go copy)
    fin  (eval-args z)
    ($assert))) 

(defun ops-bind (z)
  (prog (val)
    (cond ((not *in-rhs*)
	   (\%warn '|cannot be called at top level| 'bind)
	   (return nil)))
    (cond ((< (length z) 1.)
	   (\%warn '|bind: wrong number of arguments to| z)
	   (return nil))
	  ((not (symbolp (car z)))
	   (\%warn '|bind: illegal argument| (car z))
	   (return nil))
	  ((= (length z) 1.) (setq val (gensym)))
	  (t ($reset)
	     (eval-args (cdr z))
	     (setq val ($parameter 1.))))
    (make-var-bind (car z) val))) 

(defun ops-cbind (z)
  (cond ((not *in-rhs*)
	 (\%warn '|cannot be called at top level| 'cbind))
	((not (= (length z) 1.))
	 (\%warn '|cbind: wrong number of arguments| z))
	((not (symbolp (car z)))
	 (\%warn '|cbind: illegal argument| (car z)))
	((null *last*)
	 (\%warn '|cbind: nothing added yet| (car z)))
	(t (make-ce-var-bind (car z) *last*)))) 

(defun ops-remove (z)
  (prog (old)
    (and (not *in-rhs*)(return (top-level-remove z)))
    top  (and (atom z) (return nil))
    (setq old (get-ce-var-bind (car z)))
    (cond ((null old)
	   (\%warn '|remove: argument not an element variable| (car z))
	   (return nil)))
    (remove-from-wm old)
    (setq z (cdr z))
    (go top))) 



(defun ops-call (z)
  (prog (f)
    (setq f (car z))
    ($reset)
    (eval-args (cdr z))
    (funcall f))) 



;;; Dario Giuse - rewrote the (write) function to follow OPS-5 specifications.
;;;
(defmacro append-string (x)
  `(setq wrstring (concatenate 'simple-string wrstring ,x)))

(defun ops-write (z)
  (prog (port max lastcol k x)
    (declare (ignore lastcol))
    (cond ((not *in-rhs*)
	   (\%warn '|cannot be called at top level| 'write)
	   (return nil)))
    ($reset)
    (eval-args z)
    (setq lastcol 0)
    (setq max ($parametercount))
    (cond ((< max 1)
	   (\%warn '|write: nothing to print| z)
	   (return nil)))
    (setq x ($parameter 1))
    (cond ((and (symbolp x) ($ofile x)) 
	   (setq port ($ofile x))
; @@@ bug fix - this was a SET: GDW -- Wed Jul 18 18:36:07 1984
	   (setq k 2))
	  (t
	   (setq port (default-write-file))
	   (setq k 1)))
    ;; Analyze and output all the parameters (write) was passed.
    (do* ((wrstring "")
	  (x ($parameter k) ($parameter k))
	  (field-width))
	 ((> k max)
	  (format port wrstring)
	  (force-output))     ; Dario Giuse - added to force output
      (incf k)
      (case x
;	('|=== C R L F ===|                                           ;***DG***
 	( |=== C R L F ===|                                           ;***DG***
	 (format port "~A
" wrstring)     ; Flush the previous line
	 (setq wrstring ""))
;	('|=== R J U S T ===|                                         ;***DG***
 	( |=== R J U S T ===|                                         ;***DG***
	 (setq field-width ($parameter k))           ; Number following (tabto)
	 (incf k)
	 (setq x (format nil "~A" ($parameter k)))   ; Next field to print
	 (when (<= (length x) field-width)
	   ;; Right-justify field
	   (append-string (format nil "~V@A" field-width x))
	   (incf k)))   ; Skip next field, since we printed it already
;	('|=== T A B T O ===|                                         ;***DG***
 	( |=== T A B T O ===|                                         ;***DG***
	 (setq x ($parameter k))         ; Position to tab to
	 (incf k)
	 (when (< x (length wrstring))
	   ;; Flush line, start a new one
	   (format port "~A
" wrstring)
	   (setq wrstring ""))
	 (append-string (format nil "~V,@T" (- x (length wrstring) 1))))
	(t
	 (append-string (format nil "~A " x)))))))




(defun default-write-file ()
  (prog (port)
    (setq port *standard-output*)
    (cond (*write-file*
	   (setq port ($ofile *write-file*))
	   (cond ((null port) 
		  (\%warn '|write: file has been closed| *write-file*)
		  (setq port *standard-output*)))))
    (return port)))

(defun do-rjust (width value port)
  (prog (size)
    (cond ((eq value '|=== T A B T O ===|)
	   (\%warn '|rjust cannot precede this function| 'tabto)
	   (return nil))
	  ((eq value '|=== C R L F ===|)
	   (\%warn '|rjust cannot precede this function| 'crlf)
	   (return nil))
	  ((eq value '|=== R J U S T ===|)
	   (\%warn '|rjust cannot precede this function| 'rjust)
	   (return nil)))
    ;original->        (setq size (flatc value (1+ width)))
    (setq size (min value (1+ width)))  ;### KLUGE
    (cond ((> size width)
	   (princ '| | port)
	   (princ value port)
	   (return nil)))
    ;###        (do k (- width size) (1- k) (not (> k 0)) (princ '| | port))
    ;^^^KLUGE @@@do
    (princ value port)))

(defun do-tabto (col port)
  (prog (pos)
    ;### KLUGE: FLUSHES STREAM & SETS POS TO 0
    ;OIRGINAL->	(setq pos (1+ (nwritn port)))	;hmm-takes 1 arg @@@ port
    (finish-output port);kluge
    (setq pos 0);kluge
    (cond ((> pos col)
	   (terpri port)
	   (setq pos 1)))
    ;###(do k (- col pos) (1- k) (not (> k 0)) (princ '| | port))
    ;^^^KLUGE @@@do
    (return nil)))


(defun halt nil 
  (cond ((not *in-rhs*)
	 (\%warn '|cannot be called at top level| 'halt))
	(t (setq *halt-flag* t)))) 

(defun ops-build (z)
  (prog (r)
    (cond ((not *in-rhs*)
	   (\%warn '|cannot be called at top level| 'build)
	   (return nil)))
    ($reset)
    (build-collect z)
    (setq r (unflat (use-result-array)))
    (and *build-trace* (funcall *build-trace* r))
    (compile-production (car r) (cdr r)))) 

(defun ops-openfile (z)
  (prog (file mode id)
    ($reset)
    (eval-args z)
    (cond ((not (equal ($parametercount) 3.))
	   (\%warn '|openfile: wrong number of arguments| z)
	   (return nil)))
    (setq id ($parameter 1))
    (setq file ($parameter 2))
    (setq mode ($parameter 3))
    (cond ((not (symbolp id))
	   (\%warn '|openfile: file id must be a symbolic atom| id)
	   (return nil))
	  ((null id)
	   (\%warn '|openfile: 'nil' is reserved for the terminal| nil)
	   (return nil))
	  ((or ($ifile id)($ofile id))
	   (\%warn '|openfile: name already in use| id)
	   (return nil)))
    ;@@@	(cond ((eq mode 'in) (putprop id (infile file) 'inputfile))
		      ;@@@	      ((eq mode 'out) (putprop id (outfile file) 'outputfile))
		      ; dec 7 83 gdw added setq : is putprop needed ? )
    (cond ((eq mode 'in) (putprop id (setq id (infile file)) 'inputfile))
	  ((eq mode 'out) (putprop id (setq id (outfile file)) 'outputfile))
	  (t (\%warn '|openfile: illegal mode| mode)
	     (return nil)))
    (return nil)))

(defun $ifile (x) 
  (cond ((symbolp x) (get x 'inputfile))
	(t nil)))

(defun $ofile (x) 
  (cond ((symbolp x) (get x 'outputfile))
	(t nil)))


(defun ops-closefile (z)
  ($reset)
  (eval-args z)
  (mapc (function closefile2) (use-result-array)))

(defun closefile2 (file)
  (prog (port)
    (cond ((not (symbolp file))
	   (\%warn '|closefile: illegal file identifier| file))
	  ((setq port ($ifile file))
	   (close port)
	   (remprop file 'inputfile))
	  ((setq port ($ofile file))
	   (close port)
	   (remprop file 'outputfile)))
    (return nil)))


(defun ops-default (z)
  (prog (file use)
    ($reset)
    (eval-args z)
    (cond ((not (equal ($parametercount) 2.))
	   (\%warn '|default: wrong number of arguments| z)
	   (return nil)))
    (setq file ($parameter 1))
    (setq use ($parameter 2))
    (cond ((not (symbolp file))
	   (\%warn '|default: illegal file identifier| file)
	   (return nil))
	  ((not (member use '(write accept trace) :test #'equal))
	   (\%warn '|default: illegal use for a file| use)
	   (return nil))
	  ((and (member use '(write trace) :test #'equal)
		(not (null file))
		(not ($ofile file)))
	   (\%warn '|default: file has not been opened for output| file)
	   (return nil))
	  ((and (equal use 'accept) 
		(not (null file))
		(not ($ifile file)))
	   (\%warn '|default: file has not been opened for input| file)
	   (return nil))
	  ((equal use 'write) (setq *write-file* file))
	  ((equal use 'accept) (setq *accept-file* file))
	  ((equal use 'trace) (setq *trace-file* file)))
    (return nil)))



;;; ------------------------------------------------------------ RHS Functions

(defun flat-value (x)
  (cond ((atom x) ($value x))
	(t (mapc (function flat-value) x)))) 


(defun ops-accept (z)
  (prog (port arg)
    (cond ((> (length z) 1.)
	   (\%warn '|accept: wrong number of arguments| z)
	   (return nil)))
    (setq port *standard-input*)
    (cond (*accept-file*
	   (setq port ($ifile *accept-file*))
	   (cond ((null port) 
		  (\%warn '|accept: file has been closed| *accept-file*)
		  (return nil)))))
    (cond ((= (length z) 1)
	   (setq arg ($varbind (car z)))
	   (cond ((not (symbolp arg))
		  (\%warn '|accept: illegal file name| arg)
		  (return nil)))
	   (setq port ($ifile arg))
	   (cond ((null port) 
		  (\%warn '|accept: file not open for input| arg)
		  (return nil)))))
    (cond ((equal (peek-char t port nil "eof" ) "eof" )
	   ($value 'end-of-file)
	   (return nil)))
    (flat-value (read port)))) 



;;; Dario Giuse - completely changed the algorithm. It now uses one read-line
;;; and the read-from-string.
;;;
(defun ops-acceptline (z)
  (let ((port *standard-input*)
	(def z))
    (cond (*accept-file*
	   (setq port ($ifile *accept-file*))
	   (cond ((null port) 
		  (\%warn '|acceptline: file has been closed| 
			 *accept-file*)
		  (return-from ops-acceptline nil)))))
    (cond ((> (length def) 0)
	   (let ((arg ($varbind (car def))))
	     (cond ((and (symbolp arg) ($ifile arg))
		    (setq port ($ifile arg))
		    (setq def (cdr def)))))))
    (let ((line (read-line port nil 'eof)))
      (declare (simple-string line))
      ;; Strip meaningless characters from start and end of string.
      (setq line (string-trim '(#\( #\) #\, #\tab #\space) line))
      (when (equal line "")
	(mapc (function $change) def)
	(return-from ops-acceptline nil))
      (setq line (concatenate 'simple-string "(" line ")"))
      ;; Read all items from the line
      (flat-value (read-from-string line)))))




(defun ops-substr (l)
  (prog (k elm start end)
    (cond ((not (= (length l) 3.))
	   (\%warn '|substr: wrong number of arguments| l)
	   (return nil)))
    (setq elm (get-ce-var-bind (car l)))
    (cond ((null elm)
	   (\%warn '|first argument to substr must be a ce var|
		  l)
	   (return nil)))
    (setq start ($varbind (cadr l)))
    (setq start ($litbind start))
    (cond ((not (numberp start))
	   (\%warn '|second argument to substr must be a number|
		  l)
	   (return nil)))
    ;###	(comment |if a variable is bound to INF, the following|
			 ;	 |will get the binding and treat it as INF is|
			 ;	 |always treated.  that may not be good|)
    (setq end ($varbind (caddr l)))
    (cond ((eq end 'inf) (setq end (length elm))))
    (setq end ($litbind end))
    (cond ((not (numberp end))
	   (\%warn '|third argument to substr must be a number|
		  l)
	   (return nil)))
    ;###	(comment |this loop does not check for the end of elm|
			 ;         |instead it relies on cdr of nil being nil|
			 ;         |this may not work in all versions of lisp|)
    (setq k 1.)
    la   (cond ((> k end) (return nil))
	       ((not (< k start)) ($value (car elm))))
    (setq elm (cdr elm))
    (setq k (1+ k))
    (go la))) 


(defun ops-compute (z) ($value (ari z))) 

; arith is the obsolete form of compute
(defun ops-arith (z) ($value (ari z))) 

(defun ari (x)
  (cond ((atom x)
	 (\%warn '|bad syntax in arithmetic expression | x)
	 0.)
	((atom (cdr x)) (ari-unit (car x)))
	((eq (cadr x) '+)
	 (+ (ari-unit (car x)) (ari (cddr x))))
	;"plus" changed to "+" by gdw
	((eq (cadr x) '-)
	 (- (ari-unit (car x)) (ari (cddr x))))
	((eq (cadr x) '*)
	 (* (ari-unit (car x)) (ari (cddr x))))
	((eq (cadr x) '//)
	 (floor (ari-unit (car x)) (ari (cddr x))))   ;@@@ quotient? /
	;@@@ kluge only works for integers
	;@@@ changed to floor by jcp (from round)
	((eq (cadr x) '\\)
	 (mod (fix (ari-unit (car x))) (fix (ari (cddr x)))))
	(t (\%warn '|bad syntax in arithmetic expression | x) 0.))) 

(defun ari-unit (a)
  (prog (r)
    (cond ((consp  a) (setq r (ari a)))	;dtpr\consp gdw
	  (t (setq r ($varbind a))))
    (cond ((not (numberp r))
	   (\%warn '|bad value in arithmetic expression| a)
	   (return 0.))
	  (t (return r))))) 

(defun genatom nil ($value (gensym))) 

(defun ops-litval (z)
  (prog (r)
    (cond ((not (= (length z) 1.))
	   (\%warn '|litval: wrong number of arguments| z)
	   ($value 0) 
	   (return nil))
	  ((numberp (car z)) ($value (car z)) (return nil)))
    (setq r ($litbind ($varbind (car z))))
    (cond ((numberp r) ($value r) (return nil)))
    (\%warn '|litval: argument has no literal binding| (car z))
    ($value 0)))


(defun ops-rjust (z)
  (prog (val)
    (cond ((not (= (length z) 1.))
	   (\%warn '|rjust: wrong number of arguments| z)
	   (return nil)))
    (setq val ($varbind (car z)))
    (cond ((or (not (numberp val)) (< val 1.) (> val 127.))
	   (\%warn '|rjust: illegal value for field width| val)
	   (return nil)))
    ($value '|=== R J U S T ===|)
    ($value val)))


(defun ops-crlf (z)
  (cond  (z (\%warn '|crlf: does not take arguments| z))
	 (t ($value '|=== C R L F ===|))))


(defun ops-tabto (z)
  (prog (val)
    (cond ((not (= (length z) 1.))
	   (\%warn '|tabto: wrong number of arguments| z)
	   (return nil)))
    (setq val ($varbind (car z)))
    (cond ((or (not (numberp val)) (< val 1.) (> val 127.))
	   (\%warn '|tabto: illegal column number| z)
	   (return nil)))
    ($value '|=== T A B T O ===|)
    ($value val)))



;;; Printing WM

(defun ops-ppwm (avlist)
  (prog (next a)
    (setq *filters* nil)
    (setq next 1.)
    loop   (and (atom avlist) (go print))
    (setq a (car avlist))
    (setq avlist (cdr avlist))
    ;this must be expecting (ppwm class ^ attr ^ attr2 ...) not ^attr
    (cond ((eq a '^)
	   (setq next (car avlist))
	   (setq avlist (cdr avlist))
	   (setq next ($litbind next))
	   (and (floatp next) (setq next (fix next)))
	   (cond ((or (not (numberp next))
		      (> next *size-result-array*)
		      (> 1. next))
		  (\%warn '|illegal index after ^| next)
		  (return nil))))
	  ((variablep a)
	   (\%warn '|ppwm does not take variables| a)
	   (return nil))
	  (t (setq *filters* (cons next (cons a *filters*)))
	     (setq next (1+ next))))
    (go loop)
    print (mapwm (function ppwm2))
    (terpri)
    (return nil))) 

(defun ppwm2 (elm-tag)
  (cond ((filter (car elm-tag))
	 (terpri) (ppelm (car elm-tag) (default-write-file))))) 

(defun filter (elm)
  (prog (fl indx val)
    (setq fl *filters*)
    top  (and (atom fl) (return t))
    (setq indx (car fl))
    (setq val (cadr fl))
    (setq fl (cddr fl))
    (and (ident (nth (1- indx) elm) val) (go top))
    (return nil))) 

(defun ident (x y)
  (cond ((eq x y) t)
	((not (numberp x)) nil)
	((not (numberp y)) nil)
	((=alg x y) t)
	(t nil))) 

; the new ppelm is designed especially to handle literalize format
; however, it will do as well as the old ppelm on other formats

(defun ppelm (elm port)
  (prog (ppdat sep val att mode lastpos)
    (princ (creation-time elm) port)
    (princ '|:  | port)
    (setq mode 'vector)
    (setq ppdat (get (car elm) 'ppdat))
    (and ppdat (setq mode 'a-v))
    (setq sep "(")				; ")" 
    (setq lastpos 0)
    (do ((curpos 1 (1+ curpos)) (vlist elm (cdr vlist)))
	((atom vlist) nil)					; terminate
      (setq val (car vlist))				; tagbody begin
      (setq att (assoc curpos ppdat))	;should ret (curpos attr-name) 
      (cond (att (setq att (cdr att)))	; att = (attr-name) ??
	    (t (setq att curpos)))
      (and (symbolp att) (is-vector-attribute att) (setq mode 'vector))
      (cond ((or (not (null val)) (eq mode 'vector))
	     (princ sep port)
	     (ppval val att lastpos port)
	     (setq sep '|    |)
	     (setq lastpos curpos))))
    (princ '|)| port)))

(defun ppval (val att lastpos port)
  ;  (break "in ppval")		
  (cond ((not (equal att (1+ lastpos)))		; ok, if we got an att 
	 (princ '^ port)
	 (princ att port)
	 (princ '| | port)))
  (princ val port))



;;; printing production memory

(defun ops-pm (z) (mapc (function pprule) z) (terpri) nil)

(defun pprule (name)
  (prog (matrix next lab)
    (and (not (symbolp name)) (return nil))
    (setq matrix (get name 'production))
    (and (null matrix) (return nil))
    (terpri)
    (princ '|(p |)      ;)
    (princ name)
    top	(and (atom matrix) (go fin))
    (setq next (car matrix))
    (setq matrix (cdr matrix))
    (setq lab nil)
    (terpri)
    (cond ((eq next '-)
	   (princ '|  - |)
	   (setq next (car matrix))
	   (setq matrix (cdr matrix)))
	  ((eq next '-->)
	   (princ '|  |))
	  ((and (eq next '{) (atom (car matrix)))
	   (princ '|   {|)
	   (setq lab (car matrix))
	   (setq next (cadr matrix))
	   (setq matrix (cdddr matrix)))
	  ((eq next '{)
	   (princ '|   {|)
	   (setq lab (cadr matrix))
	   (setq next (car matrix))
	   (setq matrix (cdddr matrix)))
	  (t (princ '|    |)))
    (ppline next)
    (cond (lab (princ '| |) (princ lab) (princ '})))
    (go top)
    fin	(princ '|)|)))

(defun ppline (line)
  (prog ()
    (cond ((atom line) (princ line))
	  (t
	   (princ '|(|)      ;)
	   (setq *ppline* line)
	   (ppline2)
	   ;(
	   (princ '|)|)))
    (return nil)))

(defun ppline2 ()
  (prog (needspace)
    (setq needspace nil)
    top  (and (atom *ppline*) (return nil))
    (and needspace (princ '| |))
    (cond ((eq (car *ppline*) '^) (ppattval))
	  (t (pponlyval)))
    (setq needspace t)
    (go top)))

(defun ppattval ()
  (prog (att val)
    (setq att (cadr *ppline*))
    (setq *ppline* (cddr *ppline*))
    (setq val (getval))
    ;###	(cond ((> (+ (nwritn) (flatc att) (flatc val)) 76.)))
    ;@@@ nwritn no arg
    ;						;"plus" changed to "+" by gdw
    ;	       (terpri)
    ;	       (princ '|        |)
    (princ '^)
    (princ att)
    (mapc (function (lambda (z) (princ '| |) (princ z))) val)))

(defun pponlyval ()
  (prog (val needspace)
    (setq val (getval))
    (setq needspace nil)
    ;###	(cond ((> (+ (nwritn) (flatc val)) 76.)))
    ;"plus" changed to "+" by gdw
    ;	       (setq needspace nil)		;^nwritn no arg @@@
    ;	       (terpri)
    ;	       (princ '|        |)
    top	(and (atom val) (return nil))
    (and needspace (princ '| |))
    (setq needspace t)
    (princ (car val))
    (setq val (cdr val))
    (go top)))

(defun getval ()
  (prog (res v1)
    (setq v1 (car *ppline*))
    (setq *ppline* (cdr *ppline*))
    (cond ((member v1 '(= <> < <= => > <=>))
	   (setq res (cons v1 (getval))))
	  ((eq v1 '{)
	   (setq res (cons v1 (getupto '}))))
	  ((eq v1 '<<)
	   (setq res (cons v1 (getupto '>>))))
	  ((eq v1 '//)
	   (setq res (list v1 (car *ppline*)))
	   (setq *ppline* (cdr *ppline*)))
	  (t (setq res (list v1))))
    (return res)))

(defun getupto (end)
  (prog (v)
    (and (atom *ppline*) (return nil))
    (setq v (car *ppline*))
    (setq *ppline* (cdr *ppline*))
    (cond ((eq v end) (return (list v)))
	  (t (return (cons v (getupto end))))))) 






;;; backing up



(defun record-index-plus (k)
  (setq *record-index* (+ k *record-index*))	;"plus" changed to "+" by gdw
  (cond ((< *record-index* 0.)
	 (setq *record-index* *max-record-index*))
	((> *record-index* *max-record-index*)
	 (setq *record-index* 0.)))) 

; the following routine initializes the record.  putting nil in the
; first slot indicates that that the record does not go back further
; than that.  (when the system backs up, it writes nil over the used
		; records so that it will recognize which records it has used.  thus
		; the system is set up anyway never to back over a nil.)

(defun initialize-record nil
  (setq *record-index* 0.)
  (setq *recording* nil)
  (setq *max-record-index* 31.)
  (putvector *record-array* 0. nil)) 

; *max-record-index* holds the maximum legal index for record-array
; so it and the following must be changed at the same time

(defun begin-record (p data)
  (setq *recording* t)
  (setq *record* (list '=>refract p data))) 

(defun end-record nil
  (cond (*recording*
	 (setq *record*
	       (cons *cycle-count* (cons *p-name* *record*)))
	 (record-index-plus 1.)
	 (putvector *record-array* *record-index* *record*)
	 (setq *record* nil)
	 (setq *recording* nil)))) 

(defun record-change (direct time elm)
  (cond (*recording*
	 (setq *record*
	       (cons direct (cons time (cons elm *record*))))))) 

; to maintain refraction information, need keep only one piece of information:
; need to record all unsuccessful attempts to delete things from the conflict
; set.  unsuccessful deletes are caused by attempting to delete refracted
; instantiations.  when backing up, have to avoid putting things back into the
; conflict set if they were not deleted when running forward

(defun record-refract (rule data)
  (and *recording*
       (setq *record* (cons '<=refract (cons rule (cons data *record*))))))

(defun refracted (rule data)
  (prog (z)
    (and (null *refracts*) (return nil))
    (setq z (cons rule data))
    (return (member z *refracts* :test #'equal))))

(defun back (k)
  (prog (r)
    loop   (and (< k 1.) (return nil))
    (setq r (getvector *record-array* *record-index*))	; (('))
    (and (null r) (return '|nothing more stored|))
    (putvector *record-array* *record-index* nil)
    (record-index-plus -1.)
    (undo-record r)
    (setq k (1- k))
    (go loop)))


;; replaced per jcp
;;; Commented out
#|
(defun undo-record (r)
  (prog (save act a b rate)
    ;###	(comment *recording* must be off during back up)
    (setq save *recording*)
    (setq *refracts* nil)
    (setq *recording* nil)
    (and *ptrace* (back-print (list '|undo:| (car r) (cadr r))))
    (setq r (cddr r))
    top  (and (atom r) (go fin))
    (setq act (car r))
    (setq a (cadr r))
    (setq b (caddr r))
    (setq r (cdddr r))
    (and *wtrace* (back-print (list '|undo:| act a)))
    (cond ((eq act '<=wm) (add-to-wm b a))
	  ((eq act '=>wm) (remove-from-wm b))
	  ((eq act '<=refract)
	   (setq *refracts* (cons (cons a b) *refracts*)))
	  ((and (eq act '=>refract) (still-present b))
	   (setq *refracts* (delete (cons a b) *refracts*))
	   (setq rate (rating-part (get a 'topnode)))
	   (removecs a b)
	   (insertcs a b rate))
	  (t (\%warn '|back: cannot undo action| (list act a))))
    (go top)
    fin  (setq *recording* save)
    (setq *refracts* nil)
    (return nil)))
;;; End commented out
|#


(defun undo-record (r)
  (prog (save act a b rate)
    ;###	(comment *recording* must be off during back up)
    (setq save *recording*)
    (setq *refracts* nil)
    (setq *recording* nil)
    (and *ptrace* (back-print (list '|undo:| (car r) (cadr r))))
    (setq r (cddr r))
    top  (and (atom r) (go fin))
    (setq act (car r))
    (setq a (cadr r))
    (setq b (caddr r))
    (setq r (cdddr r))
    (and *wtrace* (back-print (list '|undo:| act a)))
    (cond ((eq act '<=wm) (add-to-wm b a))
	  ((eq act '=>wm) (remove-from-wm b))
	  ((eq act '<=refract)
	   (setq *refracts* (cons (cons a b) *refracts*)))
	  ((and (eq act '=>refract) (still-present b))
	   (setq *refracts* (spdelete (cons a b) *refracts*))
	   (setq rate (rating-part (get a 'topnode)))
	   (removecs a b)
	   (insertcs a b rate))
	  (t (\%warn '|back: cannot undo action| (list act a))))
    (go top)
    fin  (setq *recording* save)
    (setq *refracts* nil)
    (return nil))) 



; still-present makes sure that the user has not deleted something
; from wm which occurs in the instantiation about to be restored; it
; makes the check by determining whether each wme still has a time tag.

(defun still-present (data)
  (prog nil
    loop
    (cond ((atom data) (return t))
	  ((creation-time (car data))
	   (setq data (cdr data))
	   (go loop))
	  (t (return nil))))) 


(defun back-print (x) 
  (prog (port)
    (setq port (trace-file))
    (terpri port)
    (print x port)))




;;; Functions to show how close rules are to firing

(defun ops-matches (rule-list)
  (mapc (function matches2) rule-list)
  (terpri)) 

(defun matches2 (p)
  (cond ((atom p)
	 (terpri)
	 (terpri)
	 (princ p)
	 (matches3 (get p 'backpointers) 2. (ncons 1.))))) 

(defun matches3 (nodes ce part)
  (cond ((not (null nodes))
	 (terpri)
	 (princ '| ** matches for |)
	 (princ part)
	 (princ '| ** |)
	 (mapc (function write-elms) (find-left-mem (car nodes)))
	 (terpri)
	 (princ '| ** matches for |)
	 (princ (ncons ce))
	 (princ '| ** |)
	 (mapc (function write-elms) (find-right-mem (car nodes)))
	 (matches3 (cdr nodes) (1+ ce) (cons ce part))))) 

(defun write-elms (wme-or-count)
  (cond ((consp  wme-or-count)	;dtpr\consp gdw
	 (terpri)
	 (mapc (function write-elms2) wme-or-count)))) 

(defun write-elms2 (x)
  (princ '|  |)
  (princ (creation-time x)))

(defun find-left-mem (node)
  (cond ((eq (car node) '&and) (memory-part (caddr node)))
	(t (car (caddr node))))) 

(defun find-right-mem (node) (memory-part (cadddr node))) 


;;; Check the RHSs of productions 


(defun check-rhs (rhs) (mapc (function check-action) rhs))

(defun check-action (x)
  (prog (a)
    (cond ((atom x)
	   (\%warn '|atomic action| x)
	   (return nil)))
    (setq a (setq *action-type* (car x)))
    (case a
      (bind (check-bind x))
      (cbind (check-cbind x))
      (make (check-make x))
      (modify (check-modify x))
      (remove (check-remove x))
      (write (check-write x))	
      (call (check-call x))		
      (halt (check-halt x))
      (openfile (check-openfile x))
      (closefile (check-closefile x))
      (default (check-default x))
      (build (check-build x))
      (t (\%warn '|undefined rhs action| a)))))


;(defun chg-to-write (x)
;	(setq x (cons 'write (cdr x))))

(defun check-build (z)
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-build-collect (cdr z)))

(defun check-build-collect (args)
  (prog (r)
    top	(and (null args) (return nil))
    (setq r (car args))
    (setq args (cdr args))
    (cond ((consp  r) (check-build-collect r))	;dtpr\consp gdw
	  ((eq r '\\)
	   (and (null args) (\%warn '|nothing to evaluate| r))
	   (check-rhs-value (car args))
	   (setq args (cdr args))))
    (go top)))

(defun check-remove (z) 				;@@@ kluge by gdw
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (mapc (function check-rhs-ce-var) (cdr z))) 

;(defun check-remove (z) 					;original
   ; (and (null (cdr z)) (\%warn '|needs arguments| z))
   ;(mapc (function check-rhs-ce-var) (cdr z))) 

(defun check-make (z)
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-change& (cdr z))) 

(defun check-openfile (z)
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-change& (cdr z))) 

(defun check-closefile (z)
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-change& (cdr z))) 

(defun check-default (z)
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-change& (cdr z))) 

(defun check-modify (z)
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-rhs-ce-var (cadr z))
  (and (null (cddr z)) (\%warn '|no changes to make| z))
  (check-change& (cddr z))) 

(defun check-write (z)				;note this works w/write
  (and (null (cdr z)) (\%warn '|needs arguments| z))
  (check-change& (cdr z))) 

(defun check-call (z)
  (prog (f)
    (and (null (cdr z)) (\%warn '|needs arguments| z))
    (setq f (cadr z))
    (and (variablep f)
	 (\%warn '|function name must be a constant| z))
    (or (symbolp f)
	(\%warn '|function name must be a symbolic atom| f))
    (or (externalp f)
	(\%warn '|function name not declared external| f))
    (check-change& (cddr z)))) 

(defun check-halt (z)
  (or (null (cdr z)) (\%warn '|does not take arguments| z))) 

(defun check-cbind (z)
  (prog (v)
    (or (= (length z) 2.) (\%warn '|takes only one argument| z))
    (setq v (cadr z))
    (or (variablep v) (\%warn '|takes variable as argument| z))
    (note-ce-variable v))) 

(defun check-bind (z)
  (prog (v)
    (or (> (length z) 1.) (\%warn '|needs arguments| z))
    (setq v (cadr z))
    (or (variablep v) (\%warn '|takes variable as argument| z))
    (note-variable v)
    (check-change& (cddr z)))) 


(defun check-change& (z)
  (prog (r tab-flag)
    (setq tab-flag nil)
    la   (and (atom z) (return nil))
    (setq r (car z))
    (setq z (cdr z))
    (cond ((eq r '^)
	   (and tab-flag
		(\%warn '|no value before this tab| (car z)))
	   (setq tab-flag t)
	   (check-tab-index (car z))
	   (setq z (cdr z)))
	  ((eq r '//) (setq tab-flag nil) (setq z (cdr z)))
	  (t (setq tab-flag nil) (check-rhs-value r)))
    (go la))) 

(defun check-rhs-ce-var (v)
  (cond ((and (not (numberp v)) (not (ce-bound? v)))
	 (\%warn '|unbound element variable| v))
	((and (numberp v) (or (< v 1.) (> v *ce-count*)))
	 (\%warn '|numeric element designator out of bounds| v)))) 

(defun check-rhs-value (x)
  (cond ((consp  x) (check-rhs-function x))	;dtpr\consp gdw
	(t (check-rhs-atomic x)))) 

(defun check-rhs-atomic (x)
  (and (variablep x) 
       (not (bound? x)) 
       (\%warn '|unbound variable| x)))

(defun check-rhs-function (x)
  (prog (a)
    (setq a (car x))
    (cond ((eq a 'compute) (check-compute x))
	  ((eq a 'arith) (check-compute x))
	  ((eq a 'substr) (check-substr x))
	  ((eq a 'accept) (check-accept x))
	  ((eq a 'acceptline) (check-acceptline x))
	  ((eq a 'crlf) (check-crlf x))
	  ((eq a 'genatom) (check-genatom x))
	  ((eq a 'litval) (check-litval x))
	  ((eq a 'tabto) (check-tabto x))
	  ((eq a 'rjust) (check-rjust x))
	  ((not (externalp a))
	   (\%warn '"rhs function not declared external" a)))))

(defun check-litval (x) 
  (or (= (length x) 2) (\%warn '|wrong number of arguments| x))
  (check-rhs-atomic (cadr x)))

(defun check-accept (x)
  (cond ((= (length x) 1) nil)
	((= (length x) 2) (check-rhs-atomic (cadr x)))
	(t (\%warn '|too many arguments| x))))

(defun check-acceptline (x)
  (mapc (function check-rhs-atomic) (cdr x)))

(defun check-crlf (x) 
  (check-0-args x)) 

(defun check-genatom (x) (check-0-args x)) 

(defun check-tabto (x)
  (or (= (length x) 2) (\%warn '|wrong number of arguments| x))
  (check-print-control (cadr x)))

(defun check-rjust (x)
  (or (= (length x) 2) (\%warn '|wrong number of arguments| x))
  (check-print-control (cadr x)))

(defun check-0-args (x)
  (or (= (length x) 1.) (\%warn '|should not have arguments| x))) 

(defun check-substr (x)
  (or (= (length x) 4.) (\%warn '|wrong number of arguments| x))
  (check-rhs-ce-var (cadr x))
  (check-substr-index (caddr x))
  (check-last-substr-index (cadddr x))) 

(defun check-compute (x) (check-arithmetic (cdr x))) 

(defun check-arithmetic (l)
  (cond ((atom l)
	 (\%warn '|syntax error in arithmetic expression| l))
	((atom (cdr l)) (check-term (car l)))
	((not (member (cadr l) '(+ - * // \\)))	;"plus" changed to "+" by gdw
	 (\%warn '|unknown operator| l))
	(t (check-term (car l)) (check-arithmetic (cddr l))))) 

(defun check-term (x)
  (cond ((consp  x) (check-arithmetic x))	;dtpr\consp gdw
	(t (check-rhs-atomic x)))) 

(defun check-last-substr-index (x)
  (or (eq x 'inf) (check-substr-index x))) 

(defun check-substr-index (x)
  (prog (v)
    (cond ((bound? x) (return x)))
    (setq v ($litbind x))
    (cond ((not (numberp v))
	   (\%warn '|unbound symbol used as index in substr| x))
	  ((or (< v 1.) (> v 127.))
	   (\%warn '|index out of bounds in tab| x))))) 

(defun check-print-control (x)
  (prog ()
    (cond ((bound? x) (return x)))
    (cond ((or (not (numberp x)) (< x 1.) (> x 127.))
	   (\%warn '|illegal value for printer control| x))))) 

(defun check-tab-index (x)
  (prog (v)
    (cond ((bound? x) (return x)))
    (setq v ($litbind x))
    (cond ((not (numberp v))
	   (\%warn '|unbound symbol occurs after ^| x))
	  ((or (< v 1.) (> v 127.))
	   (\%warn '|index out of bounds after ^| x))))) 

(defun note-variable (var)
  (setq *rhs-bound-vars* (cons var *rhs-bound-vars*)))

(defun bound? (var)
  (or (member var *rhs-bound-vars*)
      (var-dope var)))

(defun note-ce-variable (ce-var)
  (setq *rhs-bound-ce-vars* (cons ce-var *rhs-bound-ce-vars*)))

(defun ce-bound? (ce-var)
  (or (member ce-var *rhs-bound-ce-vars*)
      (ce-var-dope ce-var)))

;;; Top level routines

(defun process-changes (adds dels)
  (prog (x)
    process-deletes (and (atom dels) (go process-adds))
    (setq x (car dels))
    (setq dels (cdr dels))
    (remove-from-wm x)
    (go process-deletes)
    process-adds (and (atom adds) (return nil))
    (setq x (car adds))
    (setq adds (cdr adds))
    (add-to-wm x nil)
    (go process-adds))) 

(defun main nil
; (condition-protect ($console-interrupt$ #'setbreak)    ;***DG*** Break
  (prog (instance r)
    (setq *halt-flag* nil)
    (setq *break-flag* nil)
    (setq instance nil)
    dil  (setq *phase* 'conflict-resolution)
    (cond (*halt-flag*
	   (setq r '|end -- explicit halt|)
	   (go finis))
	  ((zerop *remaining-cycles*)
	   (setq r '***break***)
	   (setq *break-flag* t)
	   (go finis))
	  (*break-flag* (setq r '***break***) (go finis)))
    (setq *remaining-cycles* (1- *remaining-cycles*))
    (setq instance (conflict-resolution))
    (cond ((not instance)
	   (setq r '|end -- no production true|)
	   (go finis)))
    (setq *phase* (car instance))
    (accum-stats)
    (eval-rhs (car instance) (cdr instance))
    (check-limits)
    (and (broken (car instance)) (setq *break-flag* t))
    (go dil)
    finis (setq *p-name* nil)
    (return r)))
;)                                                      ;***DG*** Break
 
(defun do-continue (wmi)
  (cond (*critical*
	 (terpri)
	 (princ '|warning: network may be inconsistent|)))
  (process-changes wmi nil)
  (print-times (main))) 

(defun accum-stats nil
  (setq *cycle-count* (1+ *cycle-count*))
  (setq *total-token* (+ *total-token* *current-token*))
  ;"plus" changed to "+" by gdw
  (cond ((> *current-token* *max-token*)
	 (setq *max-token* *current-token*)))
  (setq *total-wm* (+ *total-wm* *current-wm*))	;"plus" changed to "+" by gdw
  (cond ((> *current-wm* *max-wm*) (setq *max-wm* *current-wm*)))) 




(defun print-times (mess)
  (prog (cc)
    (cond (*break-flag* (terpri) (return mess)))
;   (setq cc (+ (float *cycle-count*) 1.0e-20))                 ;***DG***
    (setq cc (+ (float *cycle-count*) 1.0e-10))                 ;***DG***
    (terpri)
    (princ mess)
    (terpri)
    (format t "~3D productions (~D // ~D nodes)~\%"
	    *pcount* *real-cnt* *virtual-cnt*)
    (format t "~3D firings (~D rhs actions)~\%"
	    *cycle-count* *action-count*)
    (format t "~3D mean working memory size (~D maximum)~\%"
	    (round (float *total-wm*) cc) *max-wm*)
    (format t "~3D mean conflict set size (~D maximum)~\%"
	    (round (float *total-cs*) cc) *max-cs*)
    (format t "~3D mean token memory size (~D maximum)~\%"
	    (round (float *total-token*) cc)
	    *max-token*)))



(defun check-limits nil
  (cond ((> (length *conflict-set*) *limit-cs*)
	 (format t "~\%~\%conflict set size exceeded the limit of ~D after ~D~\%"
		 *limit-cs* *p-name*)
	 (setq *halt-flag* t)))
  (cond ((> *current-token* *limit-token*)
	 (format t "~\%~\%token memory size exceeded the limit of ~D after ~D~\%"
		 *limit-token* *p-name*)
	 (setq *halt-flag* t))))


(defun top-level-remove (z)
  (cond ((equal z '(*)) (process-changes nil (get-wm nil)))
	(t (process-changes nil (get-wm z))))) 

(defun ops-excise (z) (mapc (function excise-p) z))

(defun ops-run (z)
  (cond ((atom z) (setq *remaining-cycles* 1000000.) (do-continue nil))
	((and (atom (cdr z)) (numberp (car z)) (> (car z) 0.))
	 (setq *remaining-cycles* (car z))
	 (do-continue nil))
	(t 'what?))) 

(defun ops-strategy (z)
  (cond ((atom z) *strategy*)
	((equal z '(lex)) (setq *strategy* 'lex))
	((equal z '(mea)) (setq *strategy* 'mea))
	(t 'what?))) 

(defun ops-cs (z)
  (cond ((atom z) (conflict-set))
	(t 'what?))) 

(defun ops-watch (z)
  (cond ((equal z '(0.))
	 (setq *wtrace* nil)
	 (setq *ptrace* nil)
	 0.)
	((equal z '(1.)) (setq *wtrace* nil) (setq *ptrace* t) 1.)
	((equal z '(2.)) (setq *wtrace* t) (setq *ptrace* t) 2.)
	((equal z '(3.))
	 (setq *wtrace* t)
	 (setq *ptrace* t)
	 '(2. -- conflict set trace not supported))
	((and (atom z) (null *ptrace*)) 0.)
	((and (atom z) (null *wtrace*)) 1.)
	((atom z) 2.)
	(t 'what?))) 

(defun ops-external (z) (catch '!error! (external2 z))) ;jgk inverted args
;& quoted tag
(defun external2 (z) (mapc (function external3) z))

(defun external3 (x) 
  (cond ((symbolp x) (putprop x t 'external-routine))
	(t (\%error '|not a legal function name| x))))

(defun externalp (x)
  ;  (cond ((symbolp x) (get x 'external-routine)) 	;) @@@
  ;ok, I'm eliminating this temporarily @@@@
  (cond ((symbolp x) t)
	(t (\%warn '|not a legal function name| x) nil)))

(defun ops-pbreak (z)
  (cond ((atom z) (terpri) *brkpts*)
	(t (mapc (function pbreak2) z) nil)))

(defun pbreak2 (rule)
  (cond ((not (symbolp rule)) (\%warn '|illegal name| rule))
	((not (get rule 'topnode)) (\%warn '|not a production| rule))
	((member rule *brkpts*) (setq *brkpts* (rematm rule *brkpts*)))
	(t (setq *brkpts* (cons rule *brkpts*)))))

(defun rematm (atm list)
  (cond ((atom list) list)
	((eq atm (car list)) (rematm atm (cdr list)))
	(t (cons (car list) (rematm atm (cdr list))))))

(defun broken (rule) (member rule *brkpts*))

;(defun dtpr  (x) (consp x))	;dtpr\consp gdw

(defun fix (x)(floor x))


;@@@   this is a mistake: it must either go before = is called for 
;non-numeric args, or such calls replaced with eq, equal, etc.
;(defun = 
;(x y) (equal x y))


(defun infile (f_name)
  (open f_name :direction :input))

(defun sequencep (x) (typep x 'sequence))

(defun outfile (f_name)
  (open f_name :direction :output :if-exists :new-version))



;;; Added automatic (i-g-v) on load - Dario Giuse
(i-g-v)




;This is unnecessary in Spice Lisp  - Dario Giuse.

; break mechanism:
;#+vms (defun setbreak nil                                      ;***DG***
;	  (terpri)                                                    ;***DG***
;	  (princ #\^G)                                                ;***DG***
;	  (if *break-flag*                                            ;***DG***
;	    (princ " --- *BREAK-FLAG* ALREADY SET ---")               ;***DG***
;	    (princ " --- ^C Acknowledged: *break-flag* set ---"))     ;***DG***
;	  (setq *break-flag* t)                                       ;***DG***
;	  (terpri))                                                   ;***DG***

;#+vms (defun vms-keyboard-bindings nil                         ;***DG***
;	(unbind-keyboard-function #\^C)                               ;***DG***
;	(defun throw-to-previous-command-level nil                    ;***DG***
;	  (throw-to-command-level :previous))                         ;***DG***
;	(bind-keyboard-function #\^Z #'throw-to-previous-command-level);***DG***
;	(SETQ *break-flag* NIL)                                       ;***DG***
;	(setq *break-character* #\^C)                                 ;***DG***
;	(bind-keyboard-function *break-character* #'setbreak)         ;***DG***
;	)                                                             ;***DG***
;#+vms #,(vms-keyboard-bindings)                                ;***DG***

(defun setbreak nil                             ;***DG*** Break for DG Lisp
  (terpri)                                                      ;***DG***
  (if *break-flag*                                              ;***DG***
    (princ " --- *BREAK-FLAG* ALREADY SET ---")                 ;***DG***
    (princ " --- ^C^A Acknowledged: *break-flag* set ---"))     ;***DG***
  (setq *break-flag* t)                                         ;***DG***
  (terpri))                                                     ;***DG***

;(provide 'ops)                                                  ;***DG***

