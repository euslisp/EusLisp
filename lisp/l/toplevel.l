;;;;
;;;;	euslisp toplevel loop and error/signal handler
;;;;
;;;;	Copyright 1987,1991, Toshihiro MATSUI, Electrotechnical Laboratory
;;;	1987-Oct
;;;	1988		execute unix command
;;;	1989		reset alarm signal
;;;	1991-Aug	History
;;;	1991-Nov	prompt
;;;	1996-May	*eustop-hook* to intercept control at start-up.

(in-package "LISP")

(export '(- * ** *** + ++ +++ *replevel* *reptype*
	*input-line*
	*prompt*
	*prompt-string*
	*history* *try-unix*
	skip-blank read-list-from-line sigint-handler *signal-handlers*
	*eustop-hook*
	*toplevel-hook*
	*top-selector*
	*timer-job*
	*top-selector-interval*
	evaluate-stream  reploop
	euserror
	eustop reset
	toplevel-prompt
	))

(defvar - nil)
(defvar * nil)
(defvar ** nil)
(defvar *** nil)
(defvar + nil)
(defvar ++ nil)
(defvar +++ nil)
(defvar toplevel-streams (list *standard-input*))
(defvar toplevel-streams-bitvec)
(defvar *eustop-hook* nil)
(defvar *prompt*)
(defvar	*toplevel-hook*)

(deflocal *replevel* 0)
(deflocal *reptype* "")
(deflocal *input-line*)
(defvar *prompt-string* "eus")
(defvar *history*)
(defvar *tc*)
(defvar *eustop-argument*)
(defvar *top-selector* (instance port-selector :init))
(defvar *timer-job* (list 'count-up-timer))
(defvar *timer-job-count* 0)
(defvar *top-selector-interval* 10.0)
(defvar *use-top-selector* (not (unix:getenv "NO_TOP_SELECTOR")))
(defparameter *try-unix* t)

(eval-when (load eval)

(defun count-up-timer () (incf *timer-job-count*))

(defun skip-blank (s &optional (eof (gensym)))
   (let ((ch (read-char s nil eof)))
      (if (eq ch eof) (return-from skip-blank eof))
      (while (position ch " 	") (setq ch (read-char s)))
      (unread-char ch s)
      ch))
)

;;
;; read-list-from-line returns eof if eof hit
;; if a list is entered, its list is returned
;; otherwise, a list of all input items in a line is returned
;;

(eval-when (load eval)
(defun read-list-from-line (&optional (s *standard-input*) (eof (gensym)))
   (let* ((ch) (instream) (sexp) (listed-sexp))
      (setq ch (skip-blank s eof) *input-line* nil)
      (cond
	 ((eq ch eof) eof)
	 ((eq ch #\() 		;)
	  (setq sexp (read s nil eof))
	  (setq ch (read-char s))
	  (unless (eql ch #\newline) (unread-char ch s)) 
	  sexp)
         ((eq ch #\,) 
	  (read-char s)
	  (setq sexp (read s))
	  (read-char s)
	  sexp)
         (t
	  (setq *input-line*
		(read-line s nil eof)
		)
	  (if (eq *input-line* eof) (return-from read-list-from-line eof))
	  (make-string-input-stream *input-line*)))))


(defun sigint-handler (sig code)
   (warning-message 1 "interrupt")
   (if (fboundp 'unix:ualarm)
       (unix:ualarm 0 0)
       (unix:alarm 0))
   (let* ((*replevel* (1+ *replevel*))
	  (*reptype* "B"))
      (catch *replevel* (reploop #'toplevel-prompt))))

(defvar *signal-handlers* (make-sequence vector 32))

(defun eussig (sig &rest code &aux (handler (aref *signal-handlers* sig)))
   (cond (handler (funcall handler sig code))
	 (t 
	   (if (fboundp 'unix:ualarm)
	       (unix:ualarm 0 0)
	       (unix:alarm 0))
	  (warning-message 1 "signal ~s ~s~%" sig code)
	  (let* ((*replevel* (1+ *replevel*))
		 (*reptype* "S"))
	      (catch *replevel*
		  (reploop #'toplevel-prompt))))))

(defun evaluate-stream (input)
  (let* ((eof (cons nil nil))
	 (command (read input nil eof))
	 (arglist) (arg) result)
  (cond	((eq command eof) )
	((symbolp command)
;;	 (if *history* (add-history (input . buffer)))
	 (cond ((fboundp command)
		(setq arglist nil)
		(while (not (eq (setq arg (read input nil eof)) eof))
		    (push arg arglist))
		(setq - (cons command (nreverse arglist)))
		(setq result (eval -)))
	       ((and (boundp command)
		     (eq (read input nil eof) eof))
		(setq - command)
		(setq result (eval command)))
	       ((find-package (string command)) (in-package (string command)))
	       (*try-unix*
		(setq - (list 'unix:system (input . buffer)))
		(setq result (unix:system (input . buffer)) ) )
	       (t (warn "?~%")) ))
   	(t
;;	 (if *history* (add-history (input . buffer)))
	 (setq - command)
	 (setq result (eval command)) ))
   result))

(defun toplevel-prompt (strm)
  (if *history*
      (format strm "~d." (1+ *history-sequence*)))
  (if (> *replevel* 0)
     (format strm "~A~D-" *reptype* *replevel*))
  (if (not (eql *package* *user-package*))
     (format strm "~A:" (package-name *package*)))
  (format strm "~a$ " *prompt-string*))


;;
;; Read-Eval-Print-1
;;
(defun rep1 (repstream eof local-bindings &optional (ttyp t))
   (let ((input (read-list-from-line repstream eof)) result)
      (if (eq input eof) (return-from rep1 eof))
      (when (and input (or (not (streamp input))
			   (> (length (send input :buffer)) 0)))
	 (when *history*
	    (add-history 
	       (cond ((consp input) (format nil "~s" input))
		     ((streamp input) (send input :buffer))
		     (t (string input)))) )
	 ;; if something is going to be put in the history buffer,
	 ;; it certainly has some value to be processed by the hook.
	 (if *toplevel-hook* (funcall *toplevel-hook*))
	 )
      (cond
	((null input) nil)
	((symbolp input)
;;	 (if *history*	 (add-history (string input)))
	 (setq - input
	       result
	       (cond
		   ((> *replevel* 0)
			(eval-dynamic input local-bindings))
		   ((boundp input) (eval input))
		   (t '*unbound*)))
;;	 (if ttyp (print result repstream))
	 (print result repstream)
         )
	((or (null (streamp input)) (listp input))
;;	 (if *history* (add-history (format nil "~s" input)))
	 (setq - input)
	 (setq result (eval input))
	 ;;(if ttyp (print result  repstream)))
         (print result  repstream))
	((streamp input)
	 (setq result (evaluate-stream input) )
	 ;;(if ttyp  (print result repstream ))
         (print result repstream ))
        (t (print "?" repstream)))
      (setq +++ ++ ++ + + -)
     (setq *** ** ** * * result)))


;; prompt should be passed to repsel or to any toplevel reader
;; as a special variable.  If it is a local argument, it is stored
;; in the *topselector* and calls to reploop by the break or by
;; any other functions destructively change the argument, which
;; cannot be recovered unless another invocation of reploop is made
;; with the old prompt argument.

(defun prompt (strm)
	(cond ((stringp *prompt*)
		    (princ *prompt* strm ))
		   ((functionp *prompt*)
		    (funcall *prompt* strm))
		   (t 
		    (format strm "~a" *prompt-string*)) )
        (finish-output strm)
  )


(defun reploop-non-select (&optional (repstream *terminal-io*)
			 (ttyp (unix:isatty repstream)))
;read-eval-print loop
  (let* ((*error-handler* 'euserror)
	 (eof (gensym))
	 (input) (local-bindings) (special-bindings))
     (if (> *replevel* 0)
	 (setq  local-bindings (sys:list-all-bindings)
		;special-bindings (sys:list-all-special-bindings)
		))
     (while t
       (catch :reploop
	  (if ttyp (prompt repstream))
	  (if (eql (rep1 repstream eof local-bindings ttyp) eof)
	      (return-from reploop-non-select nil))
	))))

(defun repsel (repstream eof ttyp local-bindings)
   (if (eql (rep1 repstream eof local-bindings ttyp) eof)
       (throw :reploop-select nil))
   (if ttyp (prompt repstream) ))


(defun reploop-select (&optional (repstream *terminal-io*)
			 (ttyp (unix:isatty repstream))) 
  (let* ((*error-handler* 'euserror)
	 (eof (gensym))
	 (input) (local-bindings) (special-bindings))
     (if ttyp (prompt repstream))
     (if (> *replevel* 0)
	 (setq  local-bindings (sys:list-all-bindings)
 		;special-bindings (sys:list-all-special-bindings)
		))
  ;; let #'repsel be invoked when any input comes to the repstream
  (send *top-selector* :add-port repstream 'repsel
	repstream eof ttyp local-bindings)
  (catch :reploop-select
    (while t
       (unless 
	   (send *top-selector* :select *top-selector-interval*)
           (if (functionp *timer-job*)
		(funcall *timer-job*)
		(dolist (tj *timer-job*)
		   (if (functionp tj) (funcall tj)) )   )
	   )
       ))
 )  )

(defun reploop (prompt &optional (repstream *terminal-io*)
			 (ttyp (unix:isatty repstream)))
   (let ((*prompt* prompt))
      (if *use-top-selector*
          (reploop-select repstream ttyp)
          (reploop-non-select repstream ttyp))) )
    

(defun euserror (code msg1 form &optional (msg2))
#+(or :solaris2 :SunOS4.1 :thread)
   (format *error-output* "~C[1;3~Cm~A ~d error: ~A"
		#x1b (+ 1 48) *program-name*
		(unix::thr-self) msg1)	; thr-self is in unix pkg
#-(or :solaris2 :SunOS4.1 :thread)
   (format *error-output* "~C[1;3~Cm~A error: ~A"
		#x1b (+ 1 48)   *program-name* msg1)
   (if msg2 (format *error-output* " ~A" msg2))
   (if form (format *error-output* " in ~s" form))
   (format *error-output* "~C[0m~%"  #x1b)
   (let ((*replevel* (1+ *replevel*))
	 (*reptype* "E"))
      (catch *replevel* (reploop #'toplevel-prompt)))
   (throw *replevel* nil))

;;;
;;; default toplevel
;;;

(defun eustop (&rest argv)
   (when (unix:isatty *standard-input*)
      (warning-message 4 "~%~A" (lisp-implementation-version))
      (terpri *error-output*) 
      (unix:signal unix::sigint 'sigint-handler
				2)	; not restart
      (unix:signal unix::sigpipe 'eussig)
      ; setup for history
#+(or :sun :linux :alpha :solaris2 :mips)
      (when (fboundp 'unix:tcgets)
	(setq *tc* (unix:tcgets *standard-input*)) 
        (new-history *history-max*))
      )
   (if argv (setq *symbol-input* (find-executable (elt argv 0))))
   (setq *user* (unix:getenv "USER"))
   (setq *eustop-argument* argv)
   (setq *prompt-string* (pathname-name *program-name*))
   ;; load .eusrc file from the home directory
   (let ((rcfile  (unix:getenv "EUSRC")))
      (unless rcfile
	 (setq rcfile (concatenate string (unix:getenv "HOME") "/.eusrc")))
      (if (probe-file rcfile)
	  (load rcfile :verbose nil)))
   ;; load .eusrc from the current directory
   (when (probe-file ".eusrc") (load ".eusrc" :verbose nil))
   (when (and argv
	      (equal (pathname-name *program-name*) "euscomp")
	      (>= (length argv) 2))
	(apply #'compiler::comp-file-toplevel argv)
	(exit 1))
   ;; load files given in arguments
;   (format t "argv=~a~%" argv)
   (if *eustop-hook* (funcall *eustop-hook* *eustop-argument*))
   (let (exp)
      (dotimes (i (1- (length *eustop-argument*)))
	 (setq exp (elt *eustop-argument* (1+ i)))
;	 (print exp)
	 (cond ((eq (elt exp 0) #\()	;)	
		;; if exp is enclosed by parens, evaluate it.
		(eval (read-from-string exp)))
	       ((eq (elt exp 0) #\-)
		;; if arg is prefixed by a dash, ignore.
		)
	       (t (load exp)))))
   ;; enter read-eval-loop session
   (catch :eusexit
       (while t
	  (catch 0
	      (let ((*replevel* 0) (*reptype* ""))
		 (reploop #'toplevel-prompt) )
	      (throw :eusexit nil)))))

(defun reset (&optional (n 0)) (throw n nil))
)

(provide :toplevel "@(#)$Id$")

