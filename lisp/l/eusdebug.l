;********************************************************************
;*  debugging functions
;*	1987-Apr
;*	(c)T.Matsui
;********************************************************************
;
; describe object variables
;

(eval-when (load eval)

(in-package "LISP")
(export '(assert warning-message *break-on-warning* warn describe
	describe-list apropos apropos-list dump-string
	break setbreak unbreak
	timing
	btrace *tracelevel* eval-dynamic step-hook step 
	*traced-functions* trace untrace inspect *timed-functions*
	time-func time untime help list-symbols functions variables
	special-variables global-variables
	constants methods method-list more y-or-n-p yes-or-no-p
	bell check-methods pfuncs class-hierarchy classdefs 
	*remote-port*
	remote-error reval *server-streams* remote-port))

(defmacro assert (pred &optional (message "") &rest args)
    `(while (not ,pred)
	(format *error-output* ,message ,@args)
        (finish-output *error-output*)
	(reploop "ass: " )))

(defun warning-message (color format &rest mesg)
   (format *error-output* "~C[3~Cm" #x1b (+ color 48))
   (apply #'format *error-output* format mesg)
   (format *error-output* "~C[0m" #x1b)
   (finish-output *error-output*))

(defvar *break-on-warning* nil)

(defun warn (format &rest mesg)
   (apply #'format *error-output* format mesg)
   (finish-output *error-output*)
   (if *break-on-warning* (reploop "warn: ")) )

(defun describe (obj &optional (strm *standard-output*) 
			(*print-level* nil) (*print-length* nil))
  (when (numberp obj)  (print obj strm) (return-from describe nil))
  (let ((c (class obj)) varvec (size 0) (n 0))
    (setq varvec (slot c metaclass 'vars))
    (setq size (length varvec))
    (if (vectorp obj) 
	(pprint obj strm)
        (dotimes (i size)
	   (format strm "~A=" (svref varvec  i))
           (setq n (print-size (svref varvec i)))
	   (when (> n 20) (setq n 5) (terpri strm))
	   (if *print-level*
	       (print (slot obj c i))
	       (pprint (slot obj c i) strm (1+ n) 78) )
	   ))
    (finish-output strm)) )

(defun describe-list (objects &optional (file *standard-output*))
  (let ((dstream file))
    (labels ((describe-list-aux (xx)
	     (cond ((listp xx)
		  (dolist (x xx) (describe-list-aux x)))
		 (t 
		  (format dstream "~s -----------------~%" xx)
		  (describe xx dstream)
		  (terpri dstream)  (terpri dstream)))) )
    (if (not (streamp file))
	(setq dstream
	      (open file :direction :output
			 :if-exists :append
			 :if-does-not-exist :create)))
    (describe-list-aux objects)
    (if (not (streamp file)) (close dstream)) ) )
   )   
)
;;;
;;; A P R O P O S
;;;

(eval-when (load eval)

(defun apropos (strng &optional pack)
  (setq strng (string strng))
  (flet ((print-symbol-apropos (sym)
	  (format t ";; ~S~A~A~A~%"
		sym
		(if (fboundp sym)
		    (if (special-form-p sym)
		        "  Special form"
			(if (macro-function sym)
			    "  Macro"
			    "  Function"))
		    "")
	  (if  (boundp sym)
		(case (send sym :vtype)
		  (0  "  Constant=")
		  (1  "  Global=")
		  (2  "  Global Special=")
		  (t  "  Thread Special="))
	       "")
	  (if (boundp sym)  (symbol-bound-value sym) ""))))
     (cond (pack
            (do-symbols (sym pack)
              (when (substringp strng (string sym))
                    (print-symbol-apropos sym))))
           (t
            (do-all-symbols (sym)
              (when (substringp strng (string sym))
                   (print-symbol-apropos sym)))))
     nil))

(defun apropos-list (strng &optional pack)
  (let  (list)
     (setq strng (string strng))
     (cond (pack
         (do-symbols (sym pack)
           (when (substringp strng (string sym))
                 (setq list (cons sym list)))) )
        (t
         (do-all-symbols (sym)
           (when (substringp strng (string sym))
                 (setq list (cons sym list))))))
  list) )
)

;; inspection & stores in a string

(eval-when (load compile eval)
(defun dump-string (s &optional (file *standard-output*)
				(word :byte)
				(width 16))
   (let ((i 0) (slen (length s)) (increment))
      (setq increment
	(second (assoc word
		'(((:long long 4) 4)
		  ((:word :short word short 2) 2)
		  ((:byte :char :character byte char character 1) 1))
		:test #'member) ) )
      (while (< i slen)
         (if (= (mod i width) 0) (format file "~6,6x " i))
	 (case increment
	    (1 (format file "~2,2x " (elt s i)) )
	    (2 (format file "~4,4x " (logand #xffff (sys:peek s i :short))))
	    (4 (format file "~8,8x " (sys:peek s i :long))) )
	 (incf i increment)
	 (if (= (mod i width) 0) (terpri file)))))

#|
(defun store-bytes (str pos &rest bytes)
  (while bytes
     (setchar str pos (pop bytes))
     (inc pos))
  str)
|#
)

;
; break
;
(eval-when (load eval)

(defun break (&optional (prompt (format nil "brk~d: " (1+ *replevel*))))
   (let ((*replevel* (1+ *replevel*)))
      (catch *replevel* (reploop prompt)	 )))

(defun setbreak (func)
   (unless (fboundp func) (error "no func def. for setbreak"))
   (when (not (get func 'broken-function))
      (setf (get func 'broken-function) (symbol-function func)
    	    (symbol-function func)
		 `(lambda (&rest args)
		     	(step-hook (cons (get ',func 'broken-function) args) 0)))
      func))

(defun unbreak (func)
   (when (get func 'broken-function)
	(setf (symbol-function func) (get func 'broken-function)
	      (get func 'broken-function) nil)))

(defmacro timing (count &rest form)
   `(let
      ((c1 ,count) (c2 ,count) (start (unix:runtime)) (overhead 0) (nettime 0))
      (while (> c1 0) (setq c1 (1-  c1)) . ,form)
      (setq nettime (unix:runtime))
      (while (> c2 0) (setq  c2 (1- c2)))
      (setq overhead (- (unix:runtime) nettime))
      (format t ";; ~7,3f milisec~%" 
	(/ (* (/ 1000.0 internal-time-units-per-second)
	      (- nettime start overhead)) ,count)
            )))

(defun btrace (&optional (n 10))
  (mapc #'print (cdr (si::bktrace n)))
  t)
)
;;
;;	stepper
;;
(defvar *tracelevel* 0)

(eval-when (load eval)

(defun eval-dynamic (sym &optional (env (sys:list-all-bindings)))
   (let (index)
     (dolist (binding env)
        (if (eq sym (car binding))
	    (return-from eval-dynamic (cdr binding))
	    (if (and (vectorp (car binding))
		     (setq index (position sym (car binding))))
	        (return-from eval-dynamic
			     (slot (cdr binding)
				   (class (cdr binding))
				   index))
		)))
     (if (boundp sym)
	 (symbol-value sym)
	 '*unbound*)))

(defun step-hook (form env)
  (let ((input nil) (val nil) (stay t) (*print-length* 10) (*print-level* 5))
     (inc *tracelevel*) 
;	(format t "env=~s~%" env)
     (spaces *tracelevel*)
     (print form)
     (while stay
       (format t ";; s~s: " *tracelevel*) (finish-output)
       (setq input (let ((*package* *keyword-package*)) (read)))
       (case input
	  ((:pp :pprint) (pprint form))
	  ((:p)  (print form))
	  ((:go :g)
	      (setq val (eval form env))
	      (print form)
	      (format t ";; ==> ~S~%" val)
	      (setq stay nil))
	  ((:s :step)
	      (setq val (evalhook form #'step-hook env))
	      (format t ";; ~S ==> ~S~%" form val)
	      (setq stay nil))
	  ((:q :quit) (throw 'step-exit 'quit))
	  ((:?)
	      (format t ";; s   -- single step~%")
	      (format t ";; g   -- execute this form without stepping~%")
	      (format t ";; p,pp-- print current form~%")
	      (format t ";; q   -- quit stepping~%")
	      (format t ";; e form-- evaluate form~%"))
	  (:e   (setq input (read))
	        (cond ((symbolp input) (print (eval-dynamic input)))
		    (t 
		      (catch 'step-error
			(let ((*error-handler*
				'(lambda (&rest x)
				    (format *error-output*
					 "step evaluation error ~A~%" x)
				    (throw 'step-error nil))))
	                    (print (eval input)))))))
	  (t (format t ";; e?"))))
     (dec *tracelevel*)
     val))

(defmacro step (form)
  `(progn (setq *tracelevel* 0)
	  (catch 'step-exit
	    (evalhook ',form (symbol-function 'step-hook))))
	)
)
;;;
;;;	tracer
;;;
(defvar  *traced-functions* nil)
(eval-when (load eval)
(defun tracex (name arglist)
   (let (result evaluated-arguments (*tracelevel* (1+ *tracelevel*)))
     (format t ";; ~%~d: --> ~s ~s"
	       *tracelevel* name arglist)
     (setq result
	 (apply (get name 'traced-function) arglist))
     (format t ";; ~%~d: ~s <-- ~s"    *tracelevel* result name)
     (and (equal *tracelevel* 1) (terpri))
     result))

(defun trace1 (name)
  (let* ((funcdef (symbol-function name)))
    (if (null (functionp funcdef)) (return-from trace1 nil))
    (putprop name funcdef 'traced-function)
    (setf (symbol-function name)
		(list 'lambda '(&rest paramlist)
		      `(tracex ',name paramlist)))
    (return-from trace1 name)))

(defmacro trace (&rest functions)
   `(dolist (f ',functions *traced-functions*)
	(cond ((member f *traced-functions*) nil)
	      ((null (fboundp f))
		(warn "Function ~s does not exist" f))
	      (t (trace1 f)
		 (push f *traced-functions*))))
  )

(defmacro untrace (&rest functions)
   (unless functions (setq functions *traced-functions*))
   `(dolist (f ',functions *traced-functions*)
	(cond ((member f *traced-functions*)
		(setf (symbol-function f) (get f 'traced-function))
		(setq *traced-functions* (delete f *traced-functions*))))))
)
;;
;; inspect
;;
(eval-when (load eval)

(defun inspect1 (obj &optional prompt)
 (flet
     ((read-command (prompt)
	   (format t ";; ~a* " prompt)
	   (finish-output t)
	   (read *standard-input* nil 'q)))
   (do* ((command (read-command prompt) (read-command prompt))
         (varnames ((class obj) . vars))
	 (temp nil nil))
       nil
    (case (if (symbolp command)
	      (char-upcase (char (symbol-pname command) 0))
	      command)
	(#\P (describe obj *terminal-io* 2 3))
	(#\V (pprint varnames))
	(#\I (setq command (read))
	   (setq temp (concatenate string (string prompt) "." (string command)))
	   (if (or (find command varnames)
		   (and (integerp command)
			(or (arrayp obj) (consp obj))
			(< command (length obj))))
	       (inspect1
		     (if (integerp command)
			 (elt obj command)
			 (slot obj (class obj) command))
		     temp)
	       (warning-message 4 "no such variable")))
	(#\U (return-from inspect1 nil))
	(#\Q (throw 'inspect nil))
	(#\S (setq command (read)  temp (read))
	   (if (and (integerp command)
		    (or (arrayp obj) (consp obj))
		    (< command (length obj)))
	       (setf (elt obj command) temp)
	       (if (find command varnames)
		   (setf (slot obj (class obj) command) temp))))
	((#\h #\?)
	   (format t
";;	p  --describe object
;;	v  --print variable names
;;	i <var> --inspect var
;;	s <var> <value> -- set value to var
;;	<var> --describe var
;;	u  --back to parent object
;;	q  --quit inspection~%"
))
        (t (cond
	     ((find command varnames)
	       (describe (slot obj (class obj) command)))
	     ((and (integerp command)
		   (or (arrayp obj) (consp obj))
		   (< command (length obj)))
	      (print (elt obj command)))
	     (t
	       (catch 'inspect-eval
		   (let ((*error-handler*
				'(lambda (ec form &optional msg1 msg2)
				     (warn "error ~s ~s ~s" form msg1 msg2)
				     (throw 'inspect-eval t))))
		     (print (eval command)))))))))))

(defmacro inspect (obj)
   `(catch 'inspect (inspect1 ,obj (format nil "~a" ',obj)))) 
)

;;;
;;; time
;;;

(defvar *timed-functions*)

(defun time-func (func)
   `(lambda (&rest args &aux time1 result)
	(incf (get ',func :call-count))
	(setq time1 (get-internal-run-time)
	      result (apply (get ',func :timed-function) args)  )
	(incf (get ',func :elapsed-time)
	      (- (get-internal-run-time) time1))
	result))

(defmacro time (func &optional clear)
   `(progn
	(cond
	   ((get ',func :timed-function)
	    (prog1
		(list ',func 'is 'called (get ',func :call-count) 'times
			'and 'elapsed (* 0.0167 (get ',func :elapsed-time))
			'seconds)
	        (if ,clear
		    (setf (get ',func :call-count) 0 
		          (get ',func :elapsed-time) 0))))
	   ((or (not (fboundp ',func)) (macro-function ',func))
	    (error "not a function"))
	   (t
	    (let ((fdef (symbol-function ',func)) )
		(setf (get ',func :call-count) 0 
		      (get ',func :elapsed-time) 0
		      (get ',func :timed-function) fdef )
		(setfunc ',func	(time-func ',func))
		(push ',func *timed-functions*)
		(list ',func 'is 'being 'timed))))))


(defmacro untime (func)
  `(progn
	(when (get ',func :timed-function)
	   (setq *timed-functions* (delete ',func *timed-functions*))
	   (setfunc ',func (get ',func :timed-function))
	   ',func)))

;;;
;;;  'help' types online documents
;;;	1988-May  By T.Matsui
;;;  help documents are split into groups and stored under helpdoc
;;;  directory.  Help first hashes item name, and finds files where
;;;  the documents are stored.
;;;

#|
(eval-when (load eval)

(defmacro help (item)
   (if (consp item) (setq item (eval item)))
   (let* ((help-file-name
	    (format nil "~AHELP~d"  *eus-help-directory*
				     (sxhash item 50)))
	 (notes) (note)) 
     (with-open-file (help help-file-name)
	(while (null (eq (setq note (read help nil 'EOF)) 'EOF))
	   (if (or (eq (car note) item) (memq (car note) item))
		(push note notes))))
     (nreverse notes)
     (dolist (note notes)
	(format t ";; ~A:~A~%" (cadr note) (caddr note)))
   nil))
)
|#


;;;
;;; From local common   (by M.Inaba)
;;; Refined by MATSUI.T 1990Jun

(defun list-symbols (pred pkgs)
   (let (symbols)
     (dolist (p pkgs)
       (do-symbols (s p)
	  (if (funcall pred s) (push s symbols))))
     (sort symbols #'string<=)))

(defun functions (&optional (name "") &rest pkgs)
"(functions [name] [package ...])
list up symbols which have global function definition"
  (setq name (string name))
  (list-symbols #'(lambda (s) (and (fboundp s) (substringp name (string s))))
		(if pkgs pkgs (list-all-packages))))

(defun special-variables (&optional (name "") &rest pkgs)
"(special-variables [name] [pkgs ...])
collects symbols declared as special"
  (setq name (string name))
  (list-symbols 
	#'(lambda (s) (and (boundp s)
		           (>= (send s :vtype) 3)
		           (substringp name (string s)) ))
		(if pkgs pkgs (list-all-packages))))

(defun global-variables (&optional (name "") &rest pkgs)
"(special-variables [name] [pkgs ...])
collects symbols declared as special"
  (setq name (string name))
  (list-symbols 
	#'(lambda (s) (and (boundp s)
		           (= (send s :vtype) 2)
		           (substringp name (string s)) ))
		(if pkgs pkgs (list-all-packages))))

(defun variables (&optional (name "") &rest pkgs)
"(variables [name] [pkgs ...])
collects symbols with a global value assigned"
  (setq name (string name))
  (list-symbols #'(lambda (s) (and (boundp s)
			           (not (constantp s))
			           (substringp name (string s)) ))
		(if pkgs pkgs (list-all-packages))))

(defun constants (&optional (name "") &rest pkgs)
  (list-symbols #'(lambda (s) (and (constantp s)
			           (substringp name (string s)) ))
		(if pkgs pkgs (list-all-packages))))

(defun methods (&optional (name "") (pkg (find-package "KEYWORD")))
"args=&optional name
finds method-class pair which include name as substring of the method name"
  (mapcar 
     #'(lambda (s) (cons s (send-all (get s :class) :name)))
     (list-symbols #'(lambda (s) (and (substringp name (string s))
				      (get s :class)))
	  (list pkg))))

(defun method-list (&optional (file t) (verbose nil) &rest classes)
   (unless classes (setq classes (nreverse (sys:list-all-classes))))
   (dolist (c classes)
      (let ((doc) (methods))
        (format file "~S~%" (metaclass-name c))
	(setq methods (mapcar #'car (metaclass-methods c)))
	(dolist (m (sort methods #'string<= ))
	      (setq doc (cdr (assoc c (documentation m :method))))
	      ;; (print doc)
	      (when (and doc (equal (aref doc 0) #\()) ;)
		 (setq doc (read-from-string doc))
		 (when (consp doc) 
		    (if (eq (car doc) 'self) (pop doc))
		    (if (eq (car doc) 'class) (pop doc))))
	      (format file "~c~20S ~a~%" #\tab  m
		    (if (and verbose doc) doc ""))
	      )
	(terpri file))
   ))

(defmacro more (form)
  (let* ((fname (format nil "/tmp/eus~A" (unix:getpid)))
	 (command (format nil "more ~A" fname)))
    `(unwind-protect
	(progn
	       (with-open-file (*standard-output* ,fname :direction :output)
		  ,form)
	       (unix:system ,command))
	(unix:unlink ,fname))))

(defun y-or-n-p (&optional format-string &rest args &aux response)
   (tagbody 
	retry
	(when format-string (apply #'format t format-string args))
	(format t "(Y or N): ")
	(finish-output t)
	(setq response (read-line t))
	(if (= (length response) 0) (go retry))
	(case (char-upcase (aref response 0))
	  (#\Y (return-from y-or-n-p t))
	  (#\N (return-from y-or-n-p nil))
	  (t (go retry))) ))

(defun yes-or-no-p (&optional format-string &rest args &aux response)
   (tagbody 
	retry
	(when format-string (apply #'format t format-string args))
	(format t "(YES or NO): ")
	(finish-output t)
	(setq response (string-upcase (read-line t)))
	(cond
	  ((string= response "YES") (return-from yes-or-no-p t))
	  ((string= response "NO")  (return-from yes-or-no-p nil))
	  (t (go retry))) ))

(defun bell (n &optional (strm t))
   (dotimes (i n) (format strm ""))
   (finish-output strm))

(defmethod compiled-code 
 (:type ()
    (case type
	(0 'function)
	(1 'macro)
	(2 'special)
	(3 'module))))

;;;;
(defun check-methods ()
  (let* ((classes (sys:list-all-classes))
	 (methods-list (apply #'append (send-all classes :methods)))
	 (methods-bodies (mapcar #'cadr methods-list))
	 (methods (mapcar #'car methods-list))
	 (unique-methods (remove-duplicates methods)))
    (format t "
;;	~d methods defined in ~D classes
;;	~d unique method names
;;	~d compiled, ~d not compiled~%"
	(length methods-list) (length classes)
	(length unique-methods)
	(count-if #'compiled-function-p methods-bodies)
	(count-if-not #'compiled-function-p methods-bodies))))

(defun pfuncs (file &optional  (funcs (functions)) (verbose nil))
   (with-open-file (f file :direction :output)
     (let (pkg)
       (dolist (fun funcs)
	  (when (or (compiled-function-p (symbol-function fun))
		    (not (macro-function fun)))
	     (format f "~A" (string-downcase (symbol-name fun)))
	     (spaces (- 40 (print-size fun)) f)
	     (setq pkg (symbol-package fun))
	     (format f "~8a ~8a ~a~%" 
		(if (send pkg :find-external fun)
		    (string-downcase (package-name pkg))
		    (string-upcase (package-name pkg)))
		(if (compiled-function-p (symbol-function fun))
		    "compiled" "lambda  ")
	        (if (macro-function fun) "macro" "func"))
	    (if (and verbose (documentation fun))
	        (format f "        ~a~%" (documentation fun)))
	    )
	))
  ))

(defun class-hierarchy (&optional (klass object) (strm t) (verbose nil))
    (labels
	((print-hierarchy (h depth)
	    (let ((k (car h)))
	      (setq h (cdr h))
	      (spaces depth strm)
	      (format strm "~a " (string-downcase (send k :name) ))
	      (if verbose
		 (let* ((super (metaclass-super k))
			(slots (coerce (metaclass-vars k) cons))
			(super-slots
			   (if super (coerce (metaclass-vars super) cons))))
		    (setq slots (set-difference slots super-slots))
		    (setq slots (mapcar #'string-downcase slots))
		    (format strm " ~a~%" (if slots slots "()")))
		  (terpri strm))
		)
	      (dolist (s  h)
		  (print-hierarchy s (+ depth 3)))))
	(print-hierarchy (send klass :hierarchy) 0) ))

(defun classdef (c)
  (let ((s (send c :super)) sname svars)
     `(defclass ,(send c :name)
	:super ,(if s (send s :name) nil)
	:slots ,(set-difference (coerce (send c :slots) cons)
				(coerce (if s (send s :slots) nil) cons)))))


(defun classdefs (&optional (klass object) (strm t))
   (pprint (classdef klass) strm)
   (dolist (k (send klass :subclasses)) (classdefs k strm)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; remote inspector
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defvar *remote-port*)

(defun remote-error (code msg1 form &optional (msg2))
      (format *error-output* "~A remote error: ~A" *program-name* msg1)
      (if msg2 (format *error-output* " ~A" msg2))
      (if form (format *error-output* " in ~s" form))
      (terpri *error-output*)
      (throw 'reval nil))

(defun reval (s)	;remote eval
      (let* ((*standard-input* (send s :instream))
	     (*standard-output* (send s :outstream))
	     (*error-output* *standard-output*)
	     (*error-handler* 'remote-error))
        (catch 'reval
	   (print (eval (read s)) s))))

(defvar *server-streams* nil)

(defun install-remote-function (s)
   (format t ";; installing remote function ~s~%" s)
   (format t ";; remote-function= ~s~%" *remote-function*)
   (let ((ns (make-server-socket-stream s)))
        (push ns *server-streams*)
        (def-async ns *remote-function*))) 
 
(defun open-server (&optional (port 2048) (remote-func #'reval))
  (let* ((sock-addr (make-socket-address
                        :domain af_inet 
                        :host (unix:gethostname)
                        :port port)) )
    (setq *remote-port* (make-socket-port  sock-addr))
    (cond ((derivedp *remote-port* socket-port)
                (warn "listening on ~s:~d~%" (unix:gethostname) port))
          (t (return-from open-server (unix:syserrlist (- *remote-port*)))))
    ;; *remote-port* has been established for accepting connection requests
    ;; install the asynchronous connection accepting function
    (setq *remote-function* remote-func)
    (def-async *remote-port*  'lisp::install-remote-function)
    ))

#|
(defun remote-port ()
  (let* ((port 2048) (sp)
	 (sa (make-socket-address
			:domain af_inet 
			:host (unix:gethostname)
			:port port)) )
    (setq *remote-port* nil)
    (dotimes (i 1024)
	(setq sp (make-socket-port sa))
	(when (derivedp sp socket-port)
	   (warn "listening on ~d~%" (send sa :port))
	   (setq *remote-port* sp)
	   (return t))
	(send sa :next-port)
	(send sa :port))
    (unless *remote-port*  (warn "all ports engaged"))
    (eval (macroexpand '(def-async *remote-port* (s)
	 (let ((ns (make-server-socket-stream s)))
	     (push ns *server-streams*)
	     (def-async ns reval))) ))
))
|#


(provide :eusdebug "@(#)$Id$")
