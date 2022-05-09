;************************************************************************
;; E U S  compiler
;;   vers 1.0
;;   1986-SEP-15
;;   1986-Oct-27 compilation of functions and special forms
;;   1987-Mar-18 optimization for integer functions and conditional branch
;;   1987-Mar-31 compilation of special binding variables
;;   1987-Oct-19 keyword parameters
;;   1994-Apr    Solaris-2
;;
;;   author:  T.MATSUI, automatic control division, Electrotechnical Lab.
;************************************************************************


(in-package "COMPILER")

(eval-when (load eval)
	(export '(compile compile-file comfile identifier
		  compile-file-if-src-newer))
	(export '(*safety* *space* *verbose* *optimize* *speed* *cc*)) )

(defun compiled-code-p (x) (derivedp x compiled-code))

(eval-when (load eval)

(defparameter *coptflags* "")
(defparameter *cflags* "")
(defparameter *defun-list* nil)
(defparameter *verbose* nil)
(defparameter *optimize* 2)
(defparameter *safety* 1)
(defparameter *space* 0)
(defparameter *do-cc* t)
(defparameter *pic* t)
(defparameter *kernel* nil)
;(defparameter *cc* (if (member :gcc *features*) "gcc" "cc"))
(defparameter *cc* 
  (cond ((member :sh4 *features*)
	 "sh4-linux-gcc -g")
	((member :ia32 *features*) 
	 "gcc -g -m32")
	((member :gcc *features*)
	   "gcc -g")
	((member :alpha *features*) "cc -ieee_with_inexact" )
	(t "cc")))

(defvar comp nil "$Id$")
(defvar trans)
(defvar *multipass-optimize* t)


(defun ovafp (form) (and (cdr form) (symbolp (cdr form))))

(defun class-symbolp (x)
   (and (symbolp x) (boundp x) (classp (symbol-value x))))

(defun quoted-symbolp (x)
   (and (consp x) (eq (car x) 'quote) (symbolp (cadr x))))

(defun proclaimed-special-p (var)
   (declare (type symbol var))
   (or  (>= (var . vtype) 3)
	; (and (boundp var) (classp (symbol-value var)))
	 )
   )
(defun proclaimed-global-p (var)
   (declare (type symbol var))
   (= (var . vtype) 2)
   )

(defun proclaimed-constant-p (var)
  (declare (type symbol var))
  (= (var . vtype) 0)
  )

(defun object-variable-names (klass-name)
   (let (klass varvec i r)
     (if (symbolp klass-name)
	 (setq klass (symbol-value klass-name))
	 (setq klass klass-name))
     (when (classp klass)
       (setq varvec (klass . vars)
    	     i (length varvec))
       (while (>= (dec i) 0)
	  (setq r (cons (svref varvec i) r))) )
       r))

(defun object-variable-type (klass var)
   (when (not (classp klass))
	 (if  (class-symbolp klass)
	      (setq klass (symbol-value klass))
	      (error type-error "class expected for type check")))
   (if (numberp var)
       (setq var (svref (klass . types) var))
       (let ((index (position var (klass . vars))))
          (if (null index) 
	      (send comp :error "no such obj var" var)
	      (setq var (svref (klass . types) index)))))
   (if (consp var) (car var) var))

(defun coerce-type (tp)
   (cond ((memq tp  '(integer :integer fixnum :fixnum))    'integer)
	 ((memq tp  '(float :float)) 'float)   
	 (t tp)))

(defun check-arg (req n &optional (fn "car/cdr"))
   (if (null (= req n))
       (error "mismatch arg for ~A" fn)))

(defun def-function-type (type funcs)
   (dolist (f funcs) (putprop f type 'function-result-type)))

(def-function-type 'integer
		   '(ash logand logior logxor 1+ 1- 
		     length
		     floor ceiling truncate round))

(def-function-type 'float
		   '(sin cos tan asin acos atan
		     sqrt exp log v. v.* norm distance))

(def-function-type float-vector
		   '(scale v+ v- v* transform))
)	;eval-when

;;
;;	identifier management
;;
;	identifier descriptor
;
(eval-when (load compile eval)
(defclass identifier :super object
		     :slots (name type binding level offset bindframe))
)
;; binding = (constant, local, global, special)

(eval-when (load eval)
(defmethod identifier
 (:type (&optional (tp type))   (setq type (coerce-type tp)))
 (:offset (&optional (off offset)) (setq offset off))
 (:binding (&optional (bin binding)) (setq binding bin))
 (:init (sym bin lev off)
    (setq name sym
	  type t
	  binding bin
	  level lev
	  offset off)
     self))
)

;	identifier table
;
(eval-when (load compile eval)
(defclass identifier-table :super object
			   :slots (frames level maxlevel))
)

(eval-when (load eval)
(defmethod identifier-table
 (:find (id &optional (lev level))	;search only in the scope
    (cdr (assq id (svref frames lev))))
 (:get (id &optional (lev level))	;search in nested scopes
    (let (r)
	(while (>= lev 0)
	   (setq r (assq id (svref frames lev)))
	   (if r (return-from :get (cdr r)) (dec lev)))))
 (:enter (id &optional (lev level))
    (svset frames lev (cons (cons (id . name) id) (svref frames lev)))
    id)
 (:enter-special (id) (send self :enter id 0))
 (:create-frame () (inc level))
 (:pop-frame () (svset frames level nil) (dec level))
 (:clear-frame () (svset frames level nil))
 (:level (&optional (lvl level)) (setq level lvl))	;ask or set cur level
 (:frame (&optional (n level)) (svref frames n))
 (:init-frames ()
    (dotimes (n maxlevel) (svset frames n nil))
    (setq level 0)
    self)
 (:init (&optional (maxlev 20))
    (setq maxlevel maxlev
	  frames (make-array maxlevel)
	  level 0)
    self)
 )
)

(eval-when (load compile eval)
(defclass stack-frame :super object
		      :slots
                      (type	; 'arg, 'local, or 'flet
                       level	; closure level of the frame
                       offset	; offset of the frame on the local stack
                       specials	; number of special variables on the stack
                       locals))	; number of local variables on the stack
)

(eval-when (load eval)
(defmethod stack-frame
 (:level (&optional (lvl nil)) (if lvl (setq level lvl)) level)
 (:offset (&optional (off nil)) (if off (setq offset off)) offset)
 (:special (&optional (i 0)) (setq specials (+ specials i)))
 (:local (&optional (i 0)) (setq locals (+ locals i)))
 (:init (tp) (setq type tp specials 0 locals 0) self))
)


;****************************************************************
;* EusLisp compiler class
;****************************************************************

(eval-when (load compile eval)
(defclass compiler :super object 
	   :slots
	   (idtable		;identifier-table
	    closure-level	;current closure level
	    closure-vars	;closure variable counter
	    scope		;current variable scope (for sequential let)
	    frames		;list of the number of special bindings
	    fletframes		;list of function frames
	    argframes		;list of argument frames
	    blocks		;block labels
	    tags		;tagbody go labels
	    function-closures	; (function ...) list
	    initcodes		;initialize codes in "eusmain"
	    flets		;list of flet frames
	    unwind-frames	;frames need to unwound when jumps
	    avant-mode		;pre-evaluation mode flag
	    symstr
	    )))
(defvar *compiler-symid* 0)

(eval-when (load eval)
(defmethod compiler
 (:genlabel (head &optional (suffix ""))
   (format nil "~A~A~A~A" symstr head (incf *compiler-symid*) suffix))
 (:gencname-tail 
  (&rest lnames)
  ;; NOTE: Deprecated. Use lisp::gencname-tail instead. (2017/10/19 furushchev)
  (apply #'lisp::gencname-tail lnames))
 (:progn (bodies)
    (if bodies
      (while bodies
	 (send self :eval (pop bodies))
	 (and bodies (send trans :discard 1)))
      (send trans :load-nil)))
 (:eval (form)
    (if (and (symbolp form) (constantp form))
	(let ((s (symbol-value form)))
	  (cond
	    ((numberp s) (setq form s))
	    ((memq s '(nil t)) (setq form s))
	    ((symbolp s) (setq form (list 'quote s)))
	    ((stringp s) (setq form s)))))
    (cond ((eq form t) (send trans :load-t) 'symbol)
	  ((eq form nil) (send trans :load-nil) nil)
	  ((keywordp form) (send trans :load-quote form) 'symbol)
          ((symbolp form) (send self :load-var form))
	  ((integerp form) (send trans :load-int form) 'integer)
	  ((floatp form) (send trans :load-float form) 'float)
	  ((atom form) (send trans :load-quote form) t)
	  ((ovafp form) (send self :load-ovaf (car form) (cdr form)))
	  ((listp (car form))
	      (send self :eval `(apply (function ,(car form)) ,(cdr form))))
	  (t
	    (let* ((fdef (send self :get-function (car form)))
	           (ftype (second fdef)))
	      (case ftype
		(lambda  (send self :funcall (car form) (cdr form)))
		(special (send self :special-form (car form) (cdr form)))
		(macro   (send self :eval (macroexpand form)))
		(macrolet (send self :eval (eval `(,(third fdef) ,@(cdr form)))))
		(closure (send self :call-closure fdef (cdr form)))
		(t (send self :error "unknown func type" form))) ))))
 (:get-function (fn)
   (if (not (symbolp fn)) (send self :error "symbol expected for a func. name"))
   (let ((fdef (assq fn flets)))
      (if fdef
	  fdef
	  (cond ((fboundp fn)
		 (setq fdef (symbol-function fn))
		 (if (compiled-function-p fdef)
		     (list fn (cdr (assq (compiled-code-type fdef)
				         '((0 . lambda) (1 . macro) (2 . special))))
			   fdef)
		     (cons fn fdef)))
		(t (list fn 'lambda))))))
 (:call-closure (fdef args)
   (if *debug*   (print (list :call-closure fdef args)))
   (dolist (a args) (send self :eval a))
   (send trans :load-local (third fdef) (- closure-level (fourth fdef)) (sixth fdef))
   (send trans :call-closure (fifth fdef) (length args)))
 (:variable (var)	;var must be a symbol, ovaf is not allowed here.
   (let ((result (send idtable :get var scope)))
        (if result (return-from :variable result))
	(setq result (instance identifier :init var 'special 0 0))
        (cond
	  ((proclaimed-special-p  var)
	   (send idtable :enter-special result) )
	  ((proclaimed-global-p var)
	   (send idtable :enter-special result))	;Jan, 96
          ((proclaimed-constant-p var)
           (send idtable :enter result))
	  (t
	   (format *error-output* "; ~C[34;7m~S~C[0;34m is assumed to be global~C[0m~%"
			#x1b var #x1b #x1b)
	   (send idtable :enter result)) )
	result))
 (:var-binding (var)
   (if  (consp var)
	'ovaf
	(send (send self :variable var) :binding)))
 (:var-bindframe (var)
   (if (or (var . bindframe) (= closure-level (var . level)))
       (var . bindframe)
       (labels ((find-frame (frame-list)
                  (find-if #'(lambda (frame) (= (frame . level) (var . level))) frame-list))
                (find-offset (frame-list)
                  (let ((fr (find-frame frame-list)))
                    (if fr (fr . offset)))))
         (case (var . binding)
           ((local let)
            (find-offset frames))
           ((param arg object lambda)
            (find-offset argframes))))))
 (:special-variable-p (id)
    (let ((v (send idtable :find id)))
	(if (null v)
	    (or (proclaimed-special-p id) (proclaimed-global-p id))
	    (eq (send v :binding) 'special))))
 (:enter-variable (id)	
   ;make id descripter and enter it in idtable
   (let ((v (send idtable :find id)))	;found in current scope?
      (when (null v)
	 (setq v (instance identifier :init
				      id 'unknown closure-level nil))
	 (send idtable :enter v)
         (when (or (proclaimed-special-p id) (proclaimed-global-p id))
	    (if (constantp id) (send self :error "not variable" id))
            (send v :binding 'special)
	    ))
      v))
 (:bind (id frame binding offset &key store keyvarp)
    (unless (symbolp id)
	(error type-error "symbol expected for function argument" id))
    (let ((v (send self :enter-variable id)))
        (declare (type identifier v))
	(cond
	  ((eq (v . binding) 'special)
	   (send frame :special 1)
	   (case binding
	     (local (if keyvarp (send frame :local 1)))
	     (arg (send trans :load-arg offset 0)))
	   (push offset unwind-frames)
	   (send trans :bind-special id))
	  (t
	     (if (eq binding 'local) (send frame :local 1))
	     (setq (v . binding) binding
		   (v . offset) offset)
             (when store
               (setq (v . bindframe) (frame . offset))
               (send self :store-var v))))
     v))
 (:create-frame (type &optional size comment)
    (let ((frame (instance stack-frame :init type)))
      (setq (frame . level) closure-level)
      (when (and size (> size 0))
        (setq (frame . offset) (send trans :create-frame size comment))
        (send frame :local 1))
      (case type
        (arg
         (push frame argframes))
        (local
         (push frame frames))
        (flet
         (push frame fletframes))
        ;; (t (send self :error "unknow frame type" type))
        )
      (case type
        ((arg local)
         (send idtable :create-frame)
         (setq scope (send idtable :level))))
      frame))
 (:delete-frame (type flag)
    (let* ((f
            (case type
              (arg (pop argframes))
              (local (pop frames))
              (flet (pop fletframes))
              (t (send self :error "unknown frame type" type))))
           (nospecials (f . specials)))
       (declare (type stack-frame f))
       (if (> nospecials 0)
           (if flag
	       (send trans :unbind-special (f . specials))
	       (send self :error "no special object variables allowed")))
       (if flag (send trans :del-frame (f . specials) (f . locals)))
       (case type
         ((arg local)
          (send idtable :pop-frame)
          (setq scope (send idtable :level))))))
 (:load-ovaf (form var)
    (let ((form-type (send self :eval form)) (index 0))
       (if (null (memq form-type '(integer fixnum float number t nil)))
	   (setq form-type (symbol-value form-type)))	;class object
       (cond
	  ((classp form-type)
	   (setq index (position var (object-variable-names form-type)))
	   (if (numberp index)
	       (send trans :load-indexed-ov index)
	       (send self  :error "no such object variable" form var))
	   (object-variable-type form-type index))
	  (t (send trans :load-ovaf var)
	     t)) ))
 (:load-var (var)		;returns type
   (when (consp var)
	(send self :load-ovaf (car var) (cdr var))
	(return-from :load-var t))
   (unless (derivedp var identifier)
     (setq var (send self :variable var)))
   (case (var . binding)
    ((special) (send trans :load-global (var . name)))
    ((local let lambda)
	(if (and avant-mode (not (var . bindframe)) (> closure-level (var . level)))
            (setq (var . bindframe) t))
	(send trans :load-local (var . offset) (- closure-level (var . level))
              (send self :var-bindframe var)))
    ((param arg)
	(send trans :load-arg (var . offset) (- closure-level (var . level))
              (send self :var-bindframe var)))
    ((object)
	(send trans :load-obj (var . offset) (- closure-level (var . level))
              (send self :var-bindframe var)))
    (unknown 
	(send self :error "declared but unknown variable" (var . name)))
    )
   (send var :type))
 (:store-ovaf (form varname)
   (let ((form-type (send self :eval form)))
       (if (null (memq form-type '(integer fixnum float number t nil)))
	   (setq form-type (symbol-value form-type)))
       (if (classp form-type)
	   (progn
		(send trans :store-indexed-ov
			    (position varname
				      (object-variable-names form-type)))
		t)
	   (send trans :store-ovaf varname))))
 (:store-var (var)
   (unless (derivedp var identifier)
     (setq var (send self :variable var)))
   (case (var . binding)
    ((special) (send trans :store-global (var . name)))
    ((local let lambda)
     (send trans :store-local (var . offset) (- closure-level (var . level))
           (send self :var-bindframe var)))
    ((param arg)
     (send trans :store-arg (var . offset) (- closure-level (var . level))
           (send self :var-bindframe var)))
    ((object)
     (send trans :store-obj (var . offset) (- closure-level (var . level))
           (send self :var-bindframe var)))))
 ) ; defmethod
) ;eval-when

(eval-when (load eval)
(defmethod compiler
 (:funcall (sym args)
    (let ((argcount (length args)) (arg-type-list nil) (entry))
	(declare (type integer argcount))
	(if (null (memq sym '(slot setslot)))
	    (setq arg-type-list
		 (mapcar #'(lambda (x) (send self :eval x)) args)))
	(case sym
	    ((null not) (check-arg 1 argcount 'null)
			(send trans :nullx) 'symbol)
	    ((eq) (check-arg 2 argcount 'eq) (send trans :eqx) 'symbol)
	    ((memq) (check-arg 2 argcount 'memq) (send trans :memqx) t)
	    ((1+) (check-arg 1 argcount '1+)
             (cond ((integerp (car args))
                    (send trans :1+) 'integer)
                   ((floatp (car args))
                    (send trans :call sym argcount) 'float)
                   (t
                    (send trans :call sym argcount) 'symbol)))
	    ((1-) (check-arg 1 argcount '1-)
             (cond ((integerp (car args))
                    (send trans :1-) 'integer)
                   ((floatp (car args))
                    (send trans :call sym argcount) 'float)
                   (t
                    (send trans :call sym argcount) 'symbol)))
	    ((car first) (check-arg 1 argcount sym) (send trans :car) t)
	    ((cdr rest) (check-arg 1 argcount sym) (send trans :cdr) t)
	    ((cadr second) (check-arg 1 argcount sym) (send trans :cadr) t)
	    ((caar) (check-arg 1 argcount sym) (send trans :caar) t)
	    ((cdar) (check-arg 1 argcount sym) (send trans :cdar) t)
	    ((cddr) (check-arg 1 argcount sym) (send trans :cddr) t)
	    ((caddr third) (check-arg 1 argcount sym) (send trans :caddr) t)
	    ((cons) (check-arg 2 argcount 'cons) (send trans :cons) t)
	    ((symbolp consp stringp integerp numberp floatp)
		(check-arg 1 argcount sym)
		(send trans :type-check-predicate sym) t)
	    ((svref) (check-arg 2 argcount 'svref) (send trans :svref) t)
	    ((svset) (check-arg 3 argcount 'svset) (send trans :svset) t)
	    ((char schar) (check-arg 2 argcount sym) (send trans :char))
	    ((setchar) (check-arg 3 argcount sym) (send trans :setchar))
	    ((bit sbit) (check-arg 2 argcount sym) (send trans :bit))
	    ((setbit) (check-arg 3 argcount sym) (send trans :setbit))
	    ((aref aset)
		 (if (> argcount (cdr (assq sym '((aref . 2) (aset . 3)))))
		     (send trans :call sym argcount)
		     (send self :vector-op sym argcount arg-type-list)))
	    ((+ logand logior * -)
		    (send self :arithmetic sym argcount arg-type-list))
	    ((slot) (check-arg 3 argcount 'slot)
		    (send self :slot (first args) (second args) (third args)))
	    ((setslot) (check-arg 4 argcount 'setslot)
		    (send self :setslot (first args) (second args)
					(third args) (fourth args)))
	    ((abs) (check-arg 1 argcount 'abs)
		  (cond ((eql (coerce-type (car arg-type-list)) 'integer)
		         (send trans :int-abs)
			 'integer)
			((eql (coerce-type (car arg-type-list)) 'float)
			 (send trans :flt-abs)
			 'float)
			(t (send trans :call sym 1) t)) )
	    (t 
		(send trans :call sym argcount)
		(if (symbolp sym) (get sym 'function-result-type) t))
	    )))
 )	; defmethod
)	; eval-when

(eval-when (load eval)
(defmethod compiler
 (:vector-op (func argcount arg-type-list)
    (let ((vectype  (car arg-type-list))
	  (meth (cdr (assq func '((aref . :vref) (aset . :vset)) ))))
	 (if (and (symbolp vectype)
		  (boundp vectype)
		  (classp (setq vectype (symbol-value vectype))))
	      (cond
		    ((subclassp vectype integer-vector)
		     (send trans meth 'integer)
		     'integer)
		    ((subclassp vectype string)
		     (send trans meth 'character)
		     'integer)
		    ((subclassp vectype float-vector)
		     (send trans meth 'float)
		     'float)
		    ((subclassp vectype bit-vector)
		     (send trans :call func argcount)
		     'integer)
		    ((subclassp vectype vector)
		     (send trans meth 'pointer)
		     t)
		    (t (send trans :call func argcount) t))
	      (send trans :call func argcount)))  )
 (:slot (obj klass index)
   (let (i)
     (send self :eval obj)
     (when (and (null (numberp index))
		(class-symbolp klass)
		(quoted-symbolp index)
		(setq i (position (cadr index) ((symbol-value klass) . vars))))
	 (setq index i))
     (cond ((numberp index)
	    (send trans :load-indexed-ov index)
	    (object-variable-type klass index))
	   (t (send self :eval klass)
	      (send self :eval index)
	      (send trans :call 'slot 3)
	      t))))
 (:setslot (obj klass index newval)
   (let (i)
     (when (and (null (numberp index))
		(class-symbolp klass)
		(quoted-symbolp index)
		(setq i (position (cadr index) ((symbol-value klass) . vars))))
	 (setq index i))
     (cond ((numberp index)
	     (send self :eval newval)
	     (send trans :dupe)
	     (send self :eval obj)
	     (send trans :store-indexed-ov index)
	     (object-variable-type klass index))
	   (t
	     (send self :eval obj)
	     (send self :eval klass)
	     (send self :eval index)
	     (send self :eval newval)
	     (send trans :call 'setslot 4)
	     t))))
  ) ;defmethod
)   ;eval-when

(eval-when (load eval)
(defmethod compiler
 (:arithmetic (op argcount arg-type-list)
   (if (>= *safety* 2)
       (progn (send trans :call op argcount) t)
       (cond ((eq op '-)
	  (cond
	   ((every #'(lambda (x) (memq x '(:integer integer fixnum :fixnum)))
		   arg-type-list)
	    (case argcount 
	      ((1) (send trans :int-neg))
	      ((2) (send trans :int-op2 '-))
	      (t (while (> (dec argcount) 1) (send trans :int-op2 '+))
		   (send trans :int-neg)
		   (send trans :int-op2 '+)))
	    'integer)
	   ((every #'(lambda (x) (memq x '(:float float))) arg-type-list)
	    (case argcount 
	      ((1) (send trans :flt-neg))
	      ((2) (send trans :flt-op2 '-))
	      (t (while (> (dec argcount) 1) (send trans :flt-op2 '+))
		   (send trans :flt-neg)
		   (send trans :flt-op2 '+)))
	    'float)
	   (t (send trans :call '- argcount) t)))
	(t
	  (cond
	   ((every #'(lambda (x) (memq x '(:integer integer fixnum :fixnum)))
		   arg-type-list)
	    (while (> (dec argcount) 0) (send trans :int-op2 op))
	    'integer)
	   ((every #'(lambda (x) (memq x '(:float float))) arg-type-list)
	    (while (> (dec argcount) 0) (send trans :flt-op2 op))
	    'float)
	   (t (send trans :call op argcount) t))) )  ) )
   ) ; defmethod
)    ; eval-when

(eval-when (load eval)
(defmethod compiler
 (:special-form (fn args)
    (case fn
	((quote) (send trans :load-quote (car args)) t)
	((setq) (send self :setq args))
	((if) (send self :if args) t)
	((let) (send self :let args) t)
	((let*) (send self :let* args) t)
	((cond) (send self :cond args) t)
	((while) (send self :while args) t)
	((and) (send self :and args) t)
	((or) (send self :or args) t)
	((block) (send self :block (car args) (cdr args)) t)
	((return-from) (send self :return-from (car args) (cadr args)) t)
	((catch) (send self :catch (car args) (cdr args)) t)
	((throw) (send self :throw (car args) (cadr args)) t)
	((tagbody) (send self :tagbody args) t)
	((go) (send self :go (car args)) t)
	((flet) (send self :flet (car args) (cdr args) nil) t)
	((labels) (send self :flet (car args) (cdr args) t) t)
	((macrolet) (send self :macrolet (car args) (cdr args)) t)
	((unwind-protect)
		(send self :unwind-protect (car args) (cdr args)) t)
	((progn) (send self :progn args) t)
	((function) (send self :function (car args)) t)
	((the) (send self :eval (cadr args)) (coerce-type (car args)))
	((defun) (send self :warning "defun must be at toplevel") t)
	((defmacro) (send self :warning "defmacro must be at toplevel") t)
	((defmethod) (send self :warning "defmethod must be at toplevel") t)
	((eval-when) (send self :warning
			  "eval-when must appear at toplevel, ignored") t)
	(t (send self :error "Compiling method is not yet implemented." fn))))
   )	;defmethod
)	;eval-when

(eval-when (load eval)
(defmethod compiler
 (:conditional-jump (t-label nil-label)
   (if nil-label
	(send trans :if-nil nil-label)
	(send trans :if-t t-label)))
 (:evcon (condition t-label nil-label)
   (let* (op args arg-types optype (label nil-label))
     (if (listp condition)  (setq op (car condition) args (cdr condition)))
     (cond ((or (atom condition) (<= (length condition) 1))
	    (send self :eval condition)
	    (send self :conditional-jump t-label nil-label))
	   ((eq op 'eq)
	    (check-arg 2 (length args) op)
	    (send self :eval (car args))
	    (send self :eval (cadr args))
	    (if nil-label
		(send trans :if-neq nil-label)
		(send trans :if-eq  t-label)))
	   ((memq op '(null not))
	    (check-arg 1 (length args) op)
	    (send self :evcon (car args) nil-label t-label))
	   ((eq op 'and)
	    (if (null nil-label)
		(setq label (send self :genlabel "AND")))
	    (while args
		(send self :evcon (pop args) nil label))
	    (when (null nil-label)
		(send trans :jump t-label)
		(send trans :label label)))
	   ((eq op 'or)
	    (if (null t-label)
		(setq label (send self :genlabel "OR"))
		(setq label t-label))
	    (while args
		(send self :evcon (pop args) label nil))
	    (when (null t-label)
		(send trans :jump nil-label)
		(send trans :label label)))
	   ((memq op '(symbolp numberp integerp floatp atom consp stringp))
	    (check-arg 1 (length args) op)
	    (send self :eval (car args))
	    (if nil-label
		(send trans :if-not-type op nil-label)
		(send trans :if-type op t-label)))
	   ((and (= (length args) 2)  (memq op '(< > = <= >=)))
	    (setq arg-types (mapcar #'(lambda (x) (send self :eval x)) args))
	    (cond
		((and (member (car arg-types) '(integer fixnum float))
 		      (eql (car arg-types) (cadr arg-types)))
		 (setq optype
		       (cdr (assq (car arg-types)
			          '((integer . int) (fixnum . int) (float . float)))))
		 (cond
		    (t-label  (setq label t-label))
		    (t (setq op (cdr (assq op
				 	'((< . >=) (> . <=) (<= . >)
					  (>= . <) (= . <>) (<> . =)))))))
		 (send trans :compare optype op label))
		(t	;2 args, types unknown or mixed
	           (send trans :call op (length args))
		   (send self :conditional-jump t-label nil-label)) ) )
	   (t
	    (send self :eval condition)
	    (send self :conditional-jump t-label nil-label))) ))
   ) ;defmethod
 )   ;eval-when

(eval-when (load eval)
(defmethod compiler
 (:if (forms)
    (let ((elselab (send self :genlabel "IF"))
	  (exitlab (send self :genlabel "IF")))
       (send self :evcon (car forms) nil elselab)
       (send self :eval (cadr forms))
       (send trans :jump exitlab)
       (send trans :adjust 1)
       (send trans :label elselab)
       (send self :eval (caddr forms))
       (send trans :label exitlab)))
 (:setq (var-val)
    (unless var-val
	(send trans :load-nil)
	(return-from :setq t))
    (let ((var nil) (val nil) (duped nil) (result-type))
	(while var-val
      	      (setq var (car var-val)
		    val (cadr var-val)
	      	    var-val (cddr var-val)
		    duped nil)
	      (setq result-type (send self :eval val))
	      (when 
		(and (null var-val)		;last setq pair
		     (memq (send self :var-binding var) '(special ovaf)))
		(setq duped t)
		(send trans :dupe))
	      (if (symbolp var)
		  (send self :store-var var)
		  (progn	;ovaf?
		     (if (not (symbolp (cdr var)))
			 (send self :error "illegal ovaf" var))
		     (send self :store-ovaf (car var) (cdr var))))
	      (and (null var-val) (null duped) (send self :load-var var)))
     result-type))
 (:let* (bodies)	;sequential let
   (let ((local-list (pop bodies)) (unwind-save unwind-frames)
          bindframe)
	(setq bindframe (send self :create-frame 'local))
        ;; handle declarations
        (while (and bodies (consp (car bodies)) (eq (caar bodies) 'declare))
          (send self :declare (cdr (pop bodies))))
        ;; eval & bind
	(dolist (init-form local-list)
          (let ((var (if (listp init-form) (car init-form) init-form))
                offset)
            (send self :eval (if (listp init-form) (cadr init-form) nil))
            (setq offset (1- (send trans :offset-from-fp)))
            (send self :bind var bindframe 'local offset)))
        ;; eval body
	(send self :progn bodies)
	;; unwind/restore
	(setq unwind-frames unwind-save)
	(send self :delete-frame 'local t)))
 (:let (bodies)	;parallel let
   (let ((local-list (pop bodies)) (unwind-save unwind-frames) (closure-save closure-vars)
          bindframe special-list vlist)
	(setq bindframe (send self :create-frame 'local))
        ;; handle declarations
        (while (and bodies (consp (car bodies)) (eq (caar bodies) 'declare))
	   (send self :declare (cdr (pop bodies))))
        ;; eval to locals
	(dolist (init-form local-list)
          (let (var offset)
            (setq scope (1- (send idtable :level)))
            (setq var (if (listp init-form) (car init-form) init-form))
            (send self :eval (if (listp init-form) (cadr init-form) nil))
            (setq offset (1- (send trans :offset-from-fp)))
            (if (send self :special-variable-p var)
                  (push (list var offset) vlist)
                (push (send self :bind var bindframe 'local offset) vlist))))
        (setq vlist (nreverse vlist))
        ;; collect specials
        (dolist (v vlist)
          (unless (derivedp v identifier)
            (send bindframe :local 1)	;a trick
            (push v special-list)))
        ;; all the evaluation have finished, bind specials
	(dolist (spe special-list)
          (let ((offset (send trans :offset-from-fp)))
            (send trans :load-local (cadr spe) 0)
            (send self :bind (car spe) bindframe 'local offset)))
	(setq scope (send idtable :level))
        ;; pre-evaluate body
        (let ((cfile (trans . cfile))
              (push (trans . push))
              (pushcount (trans . pushcount)))
          (setq avant-mode t)
          (setq (trans . cfile) nil)
          (send self :progn bodies)
          (setq (trans . cfile) cfile)
          (setq (trans . push) push)
          (setq (trans . pushcount) pushcount)
          (setq avant-mode nil))
        ;; bind frame vector
        (setq vlist
          (remove-if-not #'(lambda (v) (and (derivedp v identifier) (v . bindframe))) vlist))
        (when vlist
          (send trans :reset-vsp)
          (setq (bindframe . offset) (send trans :create-frame (length vlist) "parlet"))
          (send bindframe :local 1))
        (dolist (v vlist)
          (send self :load-var v)
          (send trans :clearpush-frame (bindframe . offset) closure-vars)
          (setq (v . bindframe) (bindframe . offset)
                (v . offset) closure-vars)
          (inc closure-vars))
        ;; eval body
	(send self :progn bodies)
        ;; unwind/restore
	(setq unwind-frames unwind-save)
        (setq closure-vars closure-save)
	(send self :delete-frame 'local t)))
 (:cond (clauses)
    (let (clause pred next t-found  (exit (send self :genlabel "CON")))
	(while clauses
	    (setq clause (pop clauses)
	  	  pred (car clause)
	      	  next (send self :genlabel "CON"))
	    (cond
		((null (cdr clause))
		 (send self :eval pred)
		 (send trans :dupe)
		 (send trans :if-t exit)
		 (send trans :discard 1))
		((eq pred t) (setq t-found t))
		(t  (send self :evcon pred nil next)))
	    (when (cdr clause)
		(send self :progn (cdr clause))
		(send trans :jump exit)
		(send trans :adjust 1))
	    (send trans :label next))
	 ;(if t-found (send trans :adjust -1)  
	 (send trans :load-nil) ;)
	 (send trans :label exit)))
 (:while (bodies)
   (let ((cond (car bodies)) (bodies (cdr bodies))
         (whilent (send self :genlabel "WHL"))
	 (whilexit (send self :genlabel "WHX"))
	 (whileblock (send self :enter-block nil)))
      (send trans :label whilent)
      (send self :evcon cond nil whilexit)		;evaluate condition
      (send self :progn bodies)
      (send trans :discard 1)
      (send trans :jump whilent)
      (send trans :label whilexit)
      (send trans :load-nil)	;result=NIL
      (send trans :label whileblock)
      (send self :leave-block)
      ))
 (:and (bodies)
   (let ((andexit (send self :genlabel "AND")))
      (while (cdr bodies)
         (send self :eval (pop bodies))
         (send trans :dupe)
         (send trans :if-nil andexit)
         (send trans :discard 1)
	 )
      (send self :eval (car bodies))
      (send trans :label andexit)))
 (:or (bodies)
   (let ((orexit (send self :genlabel "OR")))
      (while (cdr bodies)
         (send self :eval (pop bodies))
         (send trans :dupe)
         (send trans :if-t orexit)
         (send trans :discard 1))
      (send self :eval (car bodies))
      (send trans :label orexit)))
 (:catch (label bodies)
    (let ((exlab (send self :genlabel "CAT")))
	(push (send trans :offset-from-fp) unwind-frames)
	(send self :eval label)
        (send trans :entercatch exlab)
	(send self :progn bodies)
	(pop unwind-frames)
	(send trans :exitcatch exlab)))
 (:throw (lab val)
    (send self :eval lab)
    (send self :eval val)
    (send trans :throw))
 (:closure (form &optional comment)
    (let* ((fn #'(lambda (f) (and (f . offset) (= (f . level) closure-level))))
           (bindframes (remove-if-not fn frames))
           (argframes (remove-if-not fn argframes))
           (fletframes (remove-if-not fn fletframes))
           frame)
      (when (or argframes bindframes fletframes)
        ;; create a new vector which holds every and each of the
        ;; argument, bind and flet frames
        (let ((size (max (if argframes ((car argframes) . offset) 0)
                         (if bindframes ((car bindframes) . offset) 0)
                         (if fletframes ((car fletframes) . offset) 0))))

          (setq frame (send self :create-frame nil (1+ size) comment))
          (dolist (framelist (list argframes bindframes fletframes))
            (dolist (f framelist)
              (send trans :load-local (f . offset) 0)
              (send trans :store-local (f . offset) 0 (frame . offset))))))

      ;; makeclosure
      (send trans :closure form (plusp closure-level) (not (not frame)))))
 (:unwind-protect (prot cleanup)
    (let ((cleaner (send self :genlabel "UWP"))
	  (newcomp))
      (push (send trans :offset-from-fp) unwind-frames)
      (send self :closure cleaner "unwind protect")	;make cleanup closure
	 (setq newcomp (send self :copy-compiler))
	 (send self :add-closure
		    (list cleaner 
			  (cons 'lambda	(cons nil cleanup))
			  newcomp))
      (send trans :bind-cleaner)
      (send self :eval prot)
      (send trans :call-cleaner cleaner)
      (pop unwind-frames)
    ))
  ) ;defmethod
)   ;eval-when

(eval-when (load eval)
(defmethod compiler 
 (:enter-block (lab)
   (let ((spsave (send trans :offset-from-fp))
	 (blklab (send self :genlabel "BLK")))
      (if (null (symbolp lab)) (send self :error "no symbolic block label"))
      (push (list lab blklab closure-level spsave) blocks)
      blklab))
 (:leave-block () (setq blocks (cdr blocks)))
 (:block (lab bodies)
      (setq lab (send self :enter-block lab))
      (send self :progn bodies)
      (send trans :label lab)
      (send self :leave-block))
 (:return-from (lab val)
   (let ((blklab (assq lab blocks)) (need-unwind) (offset))
      (if (null blklab) (send self :error "no such block" lab))
      (send self :eval val)
      (if (> closure-level (third blklab))
	  (send self :error "return-from in a closure cannot be compiled"))
      (setq offset (fourth blklab))
      (setq need-unwind (and unwind-frames (>= (first unwind-frames) offset)))
      (send trans :return-from offset need-unwind)
      (send trans :jump (cadr blklab))))
 (:tagbody (bodies)
    (let ((oldtags tags) 
	  (fp (send trans :offset-from-fp)) (p bodies) golab clab form)
      (while p
        (when (atom (setq golab (car p)))
	   (push (list golab (send self :genlabel "TAG") fp) tags))
        (setq p (cdr p)))
      (while bodies
	(setq form (pop bodies))
	(cond ((atom form)
	       (send trans :label (cadr (assq form tags))))
	      (t (send self :eval form)
		 (send trans :discard 1))))	;only the side effect is needed
      (send trans :load-nil)	;result is nil
      (setq tags oldtags)))
 (:go (lab)
   (let ((tag (assq lab tags)) (offset) (need-unwind))
      (if (null tag) (send self :error "no such tag to go" lab))
      (setq offset (third  tag))
      (setq need-unwind (and unwind-frames (>= (first unwind-frames) offset)))
      (send trans :go-tag offset need-unwind)
      (send trans :jump (elt tag 1))))
 (:function (fn)
   (if (symbolp fn)		; #'FUNC
       (let ((flet-def (send self :get-function fn)))
	   (if (eq (second flet-def) 'closure)
	       (send trans :load-local (third flet-def)
					(- closure-level (fourth flet-def))
                                        (sixth flet-def))
	       (send trans :getfunc fn)))
       (let (entry newcomp)  ; #'(lambda (...) ...)
         (if avant-mode
             (progn
               (when avant-mode
                 (setq newcomp (send self :copy-compiler))
                 (setq (newcomp . idtable) idtable)
                 (send newcomp :lambda (cadr fn) (cddr fn))
                 (send trans :discard 1)))
             (progn
               (setq entry (send self :genlabel "CLO"))
               (send self :closure entry "lambda-closure")
               (setq newcomp (send self :copy-compiler))
               (send self :add-closure (list entry fn newcomp)))))))
 (:flet (funcs bodies recursive-scope)
     ;recursive-scope==T for labels, NIL for flet
     (let (entry newcomp newcomps flets-exchange fletframe)
       (setq fletframe (send self :create-frame 'flet))
       (if (not recursive-scope)	; copy compiler before binding the functions
           (setq newcomp (send self :copy-compiler)))
        (dolist (fn funcs)
	    (setq entry (send self :genlabel "FLET"))
	    (send self :closure entry "flet env")
	    (push (list
	           (car fn)	;func name
	           'closure	;func bind type
	           (1- (send trans :offset-from-fp))	;offset
	           closure-level
	           entry
	           nil)		;fletframe
	          flets)
	    (send fletframe :local 1)
	    (when recursive-scope
              (setq newcomp (send self :copy-compiler))
              (push newcomp newcomps))
	    (send self :add-closure (list entry (cons 'lambda (cdr fn))
				    newcomp)))

        (if recursive-scope
	    (send-all newcomps :change-flets flets))

        (send self :progn bodies)
        (setq flets (nthcdr (length funcs) flets))
        (send self :delete-frame 'flet nil)
        (send trans :del-frame (fletframe . specials) (fletframe . locals))))
 (:macrolet (funcs bodies)
   (dolist (fn funcs)
     (push (list (car fn) 'macrolet `(lambda ,@(cdr fn)))
           flets))
   (send self :progn bodies)
   (setq flets (nthcdr (length funcs) flets)))
 (:change-flets (newflets) (setq flets newflets))
 (:declare (args)
    ;; bind statements and return type declared variables
    (let (v acc)
      (declare (type identifier v))
      (dolist (decl args)
        (case (car decl)
	  (special 
	     (dolist (id (cdr decl))
		(setq v (send self :enter-variable id))
		(setq (v . binding) 'special)))
	  (type 
	     (dolist (id (cddr decl))
		(setq v (send self :enter-variable id))
		(send v :type (cadr decl))
		(push id acc)))
	  (ftype
	     (def-function-type (cadr decl) (cddr decl)))
	  ((integer :integer fixnum :fixnum :float float)
	     (dolist (id (cdr decl))
		(setq v (send self :enter-variable id))
		(send v :type (car decl))
		(push id acc)))
	  (optimize (setq *optimize* (cadr decl)))
	  (safety (setq *safety* (cadr decl)))
	  (space (setq *space* (cadr decl)))
	  (inline )
	  (not-inline)
	  (t (cond ((class-symbolp (car decl))
		     (dolist (id (cdr decl))
			(setq v (send self :enter-variable id))
			(send v :type (car decl))
			(push id acc)))
		   (t  (send self :error "unknown declaration" decl))))))
      (nreverse acc)))
 (:lambda (param forms)
   (let ((labels nil)
	 (i 0)
	 (reqn 0)
	 (optn 0)
	 (keyn 0)
	 (auxn 0)
         (svar-base 0)
         (opt-supplied-vars)
         (opt-vars (memq '&optional param))
         (rest-var (memq '&rest param))
	 (key-forms (memq '&key param))
	 (aux-vars (memq '&aux param))
	 (key-vars)
	 (key-supplied-vars)
         (req-vars nil)
	 (opt-forms nil)
	 (key-names nil)
	 (key-inits nil)
	 (key-base 0)
	 (decl-vars nil)
	 (specially-bound nil)
	 (allowotherkeys (memq '&allow-other-keys param))
	 (unwind-save unwind-frames)
         argframe)
     (setq req-vars
           (reverse 
		  (nthcdr (length (cond (opt-vars)
				        (rest-var)
					(key-forms)
					(aux-vars)))
			  (reverse param))))
     (setq opt-vars (cdr (reverse (nthcdr (length (cond (rest-var)
							(key-forms)
							(aux-vars)))
					  (reverse opt-vars))))
           rest-var	(cond (rest-var (cadr rest-var)))
           reqn		(length req-vars)
           optn		(length opt-vars)
           opt-forms    (mapcar #'(lambda (x) (if (listp x) (cadr x)))
				opt-vars)
	   key-forms	(cdr key-forms)
	   keyn		(length key-forms))
     (when key-forms
       (cond
         (allowotherkeys
          (setq key-forms (subseq key-forms 0 (dec keyn (length allowotherkeys)))))
         (aux-vars
          (setq key-forms (subseq key-forms 0 (dec keyn (length aux-vars)))))))
     (setq aux-vars (cdr aux-vars)
           auxn (length aux-vars))
;; prepare labels for the init-forms of optional variables
     (if opt-vars
	(while (<= i optn)	;optn+1 labels
           (push (send self :genlabel "ENT") labels)
   	   (inc i))
	(if rest-var (setq labels (list (send self :genlabel "RST")))))
;; extract optional supplied-p variables
     (dolist (opt opt-vars)
       (let (svar)
         (when (and (listp opt) (cddr opt))
           (setq svar (caddr opt))
           (unless (and (symbolp (caddr opt)) (not (constantp svar)))
             (send self :error "optional supplied variable")))
         (push svar opt-supplied-vars)))
     (setq opt-supplied-vars (nreverse opt-supplied-vars))
;; extract optional variable names
     (setq opt-vars (mapcar #'(lambda (x) (if (listp x) (car x) x)) opt-vars))
;; parse keyword variables
     (if key-forms
	 (let (init key var svar)
            (dolist (k key-forms)
		(cond ((listp k)
			;; key-supplied-vars
			(when (cddr k)
                          (setq svar (caddr k))
                          (unless (and (symbolp svar) (not (constantp svar)))
                            (send self :error "keyword supplied variable")))
			;; key-inits / key-names
			(setq init (cadr k) k (car k))
			(cond ((listp k)
			       (setq key (car k) var (cadr k))
			       (if (not (keywordp key))
				   (send self :error "keyword parameter"))
			       (if (not (and var (symbolp var)))
				   (send self :error "keyword variable")))
			      (t (setq var k
				       key (intern (symbol-name var) 
						   *keyword-package*))) ))
		      (t (setq init nil
			       var k
			       svar nil
			       key (intern (symbol-name var)
					   *keyword-package*))))
	  (setq key-names (cons key key-names)
		key-vars  (cons var key-vars)
		key-supplied-vars  (cons svar key-supplied-vars)
		key-inits (cons init key-inits)))   ;end dolist
	(setq key-names (nreverse key-names))
	(setq key-vars (nreverse key-vars))
	(setq key-inits (nreverse key-inits))
	(setq key-supplied-vars (nreverse key-supplied-vars))
	;(format t ";key-names length=~d ~s~%" (length key-names)  key-names)
	(if (>= (length key-names) 128) ;; KEYWORDPARAMETERLIMIT
	    (send self :error "Too many keyword parameters>128 ~s" key-names))
        ) )
;; declaration
     (while (and forms (consp (car forms)) (eq (caar forms) 'declare))
	(setq decl-vars (append decl-vars (send self :declare (cdr (pop forms))))))
;; (print "declaration")
     (send trans :check-req-arg  reqn (+ optn
					 (if rest-var 1
					     (if key-forms keyn 0))))
;; create argument frame
     (setq argframe (send self :create-frame 'arg))
;; (print "bind")
     (setq i 0)
     (dolist (v req-vars)		;for all required arguments
	(send trans :load-arg i 0)
        (if (send self :special-variable-p v)
            (let ((offset (1- (send trans :offset-from-fp))))
              (send self :bind v argframe 'local offset))
            (send self :bind v argframe 'arg i :store t))
	(inc i))
     (while (cdr labels)
       (let ((var (pop opt-vars))
             (svar (pop opt-supplied-vars))
             var-spebase svar-spebase)
         (when svar	; initialize supplied-p to t
           (send trans :load-t)
           (if (send self :special-variable-p svar)
               (progn
                 (setq svar-spebase (1- (send trans :offset-from-fp)))
                 (send argframe :local 1))
               (setq svar (send self :bind svar argframe 'lambda (+ i svar-base) :store t)))
           (inc svar-base))
         (if (send self :special-variable-p var)
             (let ((offset (send trans :offset-from-fp)))
               (send trans :load-local offset 0)
               (setq var-spebase offset)
               (send argframe :local 1))
             (progn
               (setq var (send self :bind var argframe 'lambda (+ i svar-base)))
               (setq (var . bindframe) (argframe . offset))
               (send self :load-var var)))
         (send trans :check-opt-arg i (car labels))
         (when svar	; set supplied-p to nil
           (send trans :load-nil)
           (if svar-spebase
               (send trans :store-local svar-base 0)
               (send self :store-var svar)))
         ;; set init value
         (send self :eval (pop opt-forms))
         (if (derivedp var identifier) (send self :store-var var))
         (send trans :label (pop labels))
         (when var-spebase
           (send trans :load-local var-spebase 0)
           (send self :bind var argframe 'local var-spebase))
         (when svar-spebase
           (send trans :load-local svar-spebase 0)
           (send self :bind svar argframe 'local svar-spebase))
         (inc i)))
     (when labels
        (send trans :label (pop labels)))
     (cond 
     	(rest-var
	 (send trans :rest (+ reqn optn))
         (send self :bind rest-var argframe 'lambda (+ i svar-base) :store t)
         (inc i))
	((and (> optn 0) (null key-forms)) (send trans :check-rest-arg i)))
     (when key-forms
       (let ((key-base (+ i svar-base))
             svar-spebase)
         (send trans :reset-vsp)
         ;; bind given arguments
         (send trans :parse-key-params (coerce key-names vector)
               (+ reqn optn)
               (argframe . offset) (+ i svar-base) allowotherkeys)
         (inc i keyn)
         ;; bind defaults / supplied arguments
         (dotimes (j keyn)
           (let ((var (pop key-vars))
                 (svar (pop key-supplied-vars)))
	   (setq labels (send self :genlabel "KEY"))
           (when svar	; set supplied-p variables to t
             (send trans :load-t)
             (if (send self :special-variable-p svar)
                 (progn
                   (setq svar-spebase (1- (send trans :offset-from-fp)))
                   (send argframe :local 1))
                 (setq svar (send self :bind svar argframe 'lambda (+ i svar-base) :store t)))
             (inc svar-base))
	   (send trans :check-key-arg j labels)
	   (when svar	; set supplied-p variables to nil
             (send trans :load-nil)
             (if svar-spebase
                 (send trans :store-local svar-base 0)
                 (send self :store-var svar)))
	   ;; set default values
	   (send self :eval (pop key-inits))
	   (cond ((send self :special-variable-p var)
                  (send trans :store-local (+ key-base j) 0 (argframe . offset))
		  (send trans :label labels)
	          (send trans :load-local (+ key-base j) 0 (argframe . offset))
		  (send self :bind var argframe 'local (+ key-base j)))
	         (t	;non-special
		  (send self :bind var argframe 'lambda (+ key-base j) :store t)
		  (send trans :label labels)))
           (when svar-spebase
             (send trans :load-local svar-spebase 0)
             (send self :bind svar argframe 'local svar-spebase))))
	)   )
;;; bind aux variables
     (dolist (av aux-vars)
	(if (consp av) (send self :eval (cadr av)) (send trans :load-nil))
	(send self :bind (if (listp av) (car av) av) argframe 'lambda
              (+ i svar-base)
              :store t)
        (inc i))
;;; type check declaration variables
     (dolist (id decl-vars)
       (let ((v (send self :variable id)))
         (unless (eql (v . binding) 'unknown)
           (send self :load-var id)
           (send trans :type-check-declare (v . type)))))
;;; evaluate lambda body
     (send self :progn forms)
     (setq unwind-frames unwind-save)
     (send self :delete-frame 'arg t)
  ))
 (:lambda-block (name arglist bodies cname)
   (let ((ctime (unix:runtime))
	 blklabel)
     (if *verbose*   (format t ";~C[7;35m~S~C[0m" #x1b	name #x1b))
     (finish-output)
     (setq blklabel (send self :enter-block name))
     (send trans :enter cname name)
     (send self :lambda arglist bodies)
     (send trans :label blklabel)
     (send trans :return)
     (send self :leave-block)
     (if *verbose* (format t "; ~3,3F sec~%" (* 0.01667 (- (unix:runtime) ctime))))
     cname ))
   )   ;defmethod
) 	;eval-when

(eval-when (load eval)
(defmethod compiler
 (:def-user-entry (form)
   (if (eq (car form) 'defun)
     (let* ((name (cadr form))
            (cname (send self :genlabel "F"
                         (lisp::gencname-tail name)
                        )))
       (putprop name cname 'user-function-entry)
       (push name *defun-list*))))
 (:defun (fun-macro name arglist bodies)
    (let ((cname (get name 'user-function-entry))
	  doc)
       (if (not cname) (setq cname (send self :genlabel "F")))
       (when (> *optimize* 1)
          (putprop name cname 'user-function-entry)
          (push name *defun-list*))
       (setq doc 
	     (if (and (stringp (car bodies))  (cdr bodies))
		 (pop bodies)
		 (format nil "~s" arglist)))
       (send self :lambda-block name arglist bodies cname)
       (send self :add-initcode (list fun-macro cname name doc))))
 (:defmethod (methods) 
   (let*
	(method selector param bodies entry next
	 (myclass (car methods))
	 (objvars (object-variable-names myclass))
	 (i 0) (v nil) doc)
      (setq methods (cdr methods))
      (send self :create-frame 'local)	;enter object variables
      (dolist (ovar objvars)
	 (setq v (send self :enter-variable ovar)
	 	 (v . binding) 'object
	 	 (v . offset) i
	 	 (v . level) closure-level
		 (v . type) (object-variable-type (symbol-value myclass) ovar))
	 (inc i) )
      (while methods
	 (setq method (pop methods)
	       selector (car method)
	       param (cons 'self (cons 'class (cadr method)))
	       bodies (cddr method) )
         (setq entry (send self :genlabel "M"
                           (lisp::gencname-tail myclass selector)))
	 (setq doc 
	       (if (and (stringp (car bodies))  (cdr bodies))
		   (pop bodies)
		   (format nil "~s" param)))
	 (send self :lambda-block selector param bodies entry)
         (send self :add-initcode
		 (list 'defmethod myclass selector entry doc) ))
      (setq myclass nil)
      (send self :delete-frame 'local nil)
      ))
   ) ;defmethod
)    ;eval-when

(eval-when (load eval)
(defmethod compiler
 (:add-initcode (form) (setq initcodes (cons form initcodes)))
 (:add-closure (clo) (setq function-closures (cons clo function-closures)))
 (:closure-level (increment)  (inc closure-level increment))
 (:compile-a-closure (entry def)
   (if *debug* (format t ";closure: ~s~%" def))
   (let* ((param (cadr def)) (bodies (cddr def)))
      (setq function-closures nil)
      (send trans :declare-forward-function entry)
      (send trans :enter entry "closure or cleaner")
;      (send trans :pushenv)
      (send self :lambda param bodies)
      (send trans :return)
      (send self :compile-closures)
     )
   )
 (:compile-closures ()
   (dolist (aclosure (reverse function-closures))
      (send (caddr aclosure) :compile-a-closure (car aclosure) (cadr aclosure)))
   (setq function-closures nil))
 (:toplevel-eval (form)
   (setq function-closures nil)
   (let* ((fn (car form)))
     (case fn
	((defun defmacro)
	 (send self :defun fn (cadr form) (caddr form) (cdddr form))
	 (send self :compile-closures))
	((defmethod)
	 (send self :defmethod (cdr form))
	 (send self :compile-closures))
	((function quote return-from) nil)
	(t (send self :add-initcode form)))))
 (:toplevel (form compiler-eval &optional pass)
   (if (not pass) (send trans :init))
   (if (atom form) (return-from :toplevel nil))
   (if (macro-function (car form)) (setq form (macroexpand form)))
   (cond
         ((eq (car form) 'eval-when)
	  (let ((situation (cadr form)))
	    (dolist (f (cddr form))
	      (when (memq 'compile situation)  (eval f))
	      (when (memq 'load situation) (send self :toplevel f nil pass)))))
	 ((eq (car form) 'progn)
	  (pop form)
	  (while form (send self :toplevel (pop form) compiler-eval pass)))
	 (t
	  (if compiler-eval (eval form)) ;evaluate in compiler's environment
	  (if pass
	    (send self :def-user-entry form)
	    (send self :toplevel-eval form)))))
 (:toplevel-execution (form)	;init codes
   (let* ((fn (car form)))
      (case fn
	(defun
	   (send trans :defun (caddr form) (cadr form) (fourth form)))
	(defmacro
	   (send trans :defmacro (caddr form) (cadr form) (fourth form)))
	(defmethod (send trans :defmethod (cadr form) (caddr form)
				 (fourth form) (fifth form)))
	(t (send self :eval form) (send trans :discard 1)))))
 (:compile-file (file &key
		 (cc-option "")
		 (optimize *optimize*)
		 (c-optimize 2)
		 (safety *safety*)
		 (cc *do-cc*)	;nil skips c-compilation
		 (pic *pic*)	;t forces position independent code 
		 (verbose *verbose*)
		 (entry (lisp::gencname-tail (pathname-name file)))
		 (o))
   (setq symstr (subseq entry 0 8))
   (if (and (integerp c-optimize)
	    (> c-optimize 0)
	    ;; (not (member :gcc *features*))
	    )
	(setq *coptflags* (format nil " -O~A" c-optimize))
	(setq *coptflags* ""))
   (setq *optimize* optimize
	 *safety* safety
	 *verbose* verbose)
   (unless (send (pathname file) :directory)
     (setq file (namestring (merge-pathnames "./" file))))
   (when o
	   (setq o (pathname o))
	   (setq o (merge-pathnames o file))
	   (setq o (merge-pathnames ".o" o)))
   (unwind-protect
     (let ((name nil) (c nil) (form nil)
           (ins) (cccom)
           (file.c (merge-pathnames ".c" file))
           (file.h (merge-pathnames ".h" file))
           (file.o (if o o (merge-pathnames ".o" file)))
           (file.so (if o (merge-pathnames ".so" o)
                  (merge-pathnames ".so" file)))
           (file.dll (if o (merge-pathnames ".dll" o)
                       (merge-pathnames ".dll" file)))
           (cpack *package*))
        (unless (eq (unix:access (send (pathname file) :directory-string) unix::O_RDWR) t) ;; source directory is not writable
          (warn ";; ~A is write protected, use temporary compile directory to ~A~%" file (send o :directory-string))
          (setq file.c (merge-pathnames ".c" o)
                file.h (merge-pathnames ".h" o)))
        (when (null (probe-file file))
           (setq file (merge-pathnames ".l" file))
           (if (null (probe-file  file))
               (error io-error "file ~A not found~%" file)))
        (warn "compiling file: ~A~%" (namestring file))
        (setq ins (open file))
        (setq *defun-list* nil)
        (when *multipass-optimize*
          (while t
            (setq form (read ins nil '$eof$))
            (if (eq form '$eof$) (return nil))
            (send self :toplevel form t t))
          (unix:lseek ins 0))
        (nreverse *defun-list*)
        (send trans :init-file file file.c file.h entry)
        (send idtable :init-frames)
        (setq frames nil
              scope 0
              blocks nil
              initcodes nil)
        (while t
           (setq form (read ins nil '$eof$))
           (if (eq form '$eof$) (return nil))
           (send self :toplevel form t))
        (setq initcodes (reverse initcodes))
        (send trans :eusmain entry)
        (dolist (form initcodes) (send self :toplevel-execution form))
        (send trans :load-nil)
        (send trans :return)
        (send self :compile-closures)
        (send trans :declare-ftab)
        (send trans :ftab-initializer)
        (let ((symvec (cpack . symvector)) (symcnt (cpack . symcount)))
          (setq (cpack . symvector) (make-array 0)
                (cpack . symcount) 1)
          ;; write every symbol in this package as internal symbols
          ;; (warn "writing quote vector file in ~s~%" *package*)
          (send trans :write-quote-vector)
          (setq (cpack . symvector) symvec
                (cpack . symcount) symcnt))
        (send trans :close)
        (close ins)
        (setq cccom
           (concatenate
                 string
                 *cc*
                 " -c"
                 (if o (concatenate string " -o " (namestring o)))
                 (cond ((memq :sun3 *features*) " -Dsun3 -w")
                      ((memq :sun4 *features*) " -Dsun4 -w")
;                     ((memq :mips *features*) " -Dmips -G 0 -w")
;                     ((memq :irix *features*) " -Dmips -DIRIX -signed -w")
                      ((memq :irix *features*) " -Dmips -DIRIX -w ")
                      ((memq :irix6 *features*) " -Dmips -DIRIX6 -woff all")
                      ((memq :vax *features*)  " -Dvax -J")
                      ((memq :news *features*)  " -Dnews")
                      ((memq :sanyo *features*)  " -Dsanyo")
                      ((memq :darwin *features*)
                    (if (memq :x86_64 *features*)
                        " -DDarwin -Dx86_64 -DLinux -w -falign-functions=8 "
                      " -DDarwin -Di386 -DLinux -w -falign-functions=4 "))
                      ((and (memq :linux *features*)  (memq :gcc3 *features*))
                    (cond
                             ((memq :x86_64 *features*)
                              " -Dx86_64 -DLinux -Wimplicit -falign-functions=8 -DGCC3 ")
                             ((memq :aarch64 *features*)
                              " -Daarch64 -fPIC -Darmv8 -DARM -DLinux -Wimplicit -falign-functions=8 -DGCC3 ")
                             ((memq :arm *features*)
                              " -DARM -DLinux -Wimplicit -falign-functions=4 -DGCC3 ")
                             ((memq :word-size=64 *features*)
                              " -DLinux -Wimplicit -falign-functions=8 -DGCC3 ")
                             (t " -Di386 -DLinux -Wimplicit -falign-functions=4 -fno-stack-protector -DGCC3 ")))
                      ((memq :linux *features*)
                    (if (memq :x86_64 *features*)
                      " -Dx86_64 -DLinux -Wimplicit -malign-functions=8 "
                      " -Di386 -DLinux -Wimplicit -malign-functions=4 "))
                   ((memq :alpha *features*) " -Dalpha -Dsystem5 -D_REENTRANT -w")
                   ((memq :cygwin *features*) " -DCygwin -D_REENTRANT -DX_V11R6_1 -falign-functions=4")
                   ((memq :i386  *features*) " -Di386")
                   (t (warn "cpu type is not properly set")))
                 (cond ((memq :sunos4 *features*) " -DSunOS4 -Bstatic")
                   ((memq :sunos4.1 *features*) " -DSunOS4_1")
                   ((memq :Solaris2 *features*) " -DSolaris2")
                   (t ""))
                 (if (memq :gcc *features*) " -DGCC -fsigned-char " )
                 (if (memq :thread *features*) " -DTHREADED" )
                 (if (memq :pthread *features*) " -DPTHREAD" )
                 (if (memq :rgc *features*) " -DRGC -D__USE_POLLING -D__HEAP_EXPANDABLE -D__GC_SEPARATE_THREAD" )
                 (if pic
                     (cond ((memq :SunOS4.1 *features*) " -fpic")
                       ((memq :cygwin *features*) "")
                       ((memq :Gcc *features*) " -fpic ")
                       ((memq :Solaris2 *features*) " -K pic")
                       ((memq :linux *features*) " -fpic")
                       ((memq :irix *features*) " -KPIC")
                       ((memq :irix6 *features*) " -KPIC")
                       ((memq :alpha *features*) " -fpic")
                       (t " -pic"))
                     )
                 cc-option
                 " -I" (namestring *eusdir*) "include"
                 *coptflags* *cflags*
                 " "     (namestring file.c)
                 (if (and (memq :sunos4.1 *features*)  pic)
                  (concatenate string
                      "; ld -o "
                      (namestring file.so)
                      " "
                      (namestring file.o))
                  )
                 (if (and (or (memq :irix *features*)
                      (memq :irix6 *features*)) pic)
                  (concatenate string
                      "; ld -shared -o "
                      (namestring file.so)
                      " "
                      (namestring file.o))
                  )
                 (if (and (memq :linux *features*)  pic)
                  (concatenate string
                           (cond
                            ((memq :darwin *features*)
                             "; gcc -dynamiclib -flat_namespace -undefined suppress -o ")
                            ((memq :sh4 *features*)
                             "; sh4-linux-gcc -shared -o ")
                            ((memq :ia32 *features*)
                             "; ld -melf_i386 -shared -build-id -o ")
                            ((memq :i386 *features*)
                             "; gcc -shared -Xlinker -build-id -o ")
                            (t
                             "; ld -shared -build-id -o "))
                      (namestring file.so)
                      " "
                      (namestring file.o))
                  "")
                 (if (and (memq :alpha *features*)  pic)
                  (concatenate string
                      "; ld -shared -update_registry so_locations -expect_unresolved '*' -g0 -O1 -o "
                      (namestring file.so)
                      " "
                      (namestring file.o))
                  "")
                 (if (and (memq :cygwin *features*)
                      (not *kernel*))
                  (concatenate string
                      "; gcc -shared -g -falign-functions=4 -Wl,--export-all-symbols -Wl,--unresolved-symbols=ignore-all -Wl,--enable-runtime-pseudo-reloc -o "
                      (namestring file.dll) " "
                      (namestring file.o) " "
                      *eusdir* (unix:getenv "ARCHDIR")
                      "/bin/"
                      "eusgl.a "
                      "-lm -lpthread "
                      ))
              ))
        (when cc
           (warn "~A" cccom)
           (unix:system cccom))
        (dolist (f *defun-list*) (remprop f 'user-function-entry))
        (terpri *error-output*)
       )
     (send trans :clear-external-functions)))
 (:specials () (mapcar 'car (send idtable :frame 0)))
 (:copy-compiler ()
    (let ((newcomp) (initcode-save initcodes) (closure-save function-closures))
       (setq initcodes nil
	     function-closures nil)
       (setq newcomp (copy-object self))
       (send newcomp :closure-level 1)
       (setq initcodes initcode-save
	     function-closures closure-save)
       newcomp))
  (:init () 
  (setq trans (instantiate  translator)
	idtable (instance identifier-table :init)
        scope 0
	closure-level 0
	closure-vars 0
	symstr "")
  self)
   ) ; defmethod
)    ; eval-when

(eval-when (load eval)
(setq comp (instantiate compiler))
(send comp :init)
)
;*******************************************************************
;* use following functions to compile function and files.
;*******************************************************************

(eval-when (load eval)

(defun dump-function (file &rest names)
   (with-open-file (f file :direction :output)
      (dolist (funmac names)
	 (let ((def (symbol-function funmac)) dump)
	   (setq dump
	    (case (car def)
		(lambda `(defun ,funmac . ,(cdr def)))
		(macro  `(defun ,funmac . ,(cdr def)))))
	  (pprint dump f) ))) )

(defun comfile (&rest files) (dolist (f files) (send comp :compile-file f)))
(defun compile-file (file &rest keys)
    (send* comp :compile-file file keys))

(defun compile (&rest funcs)
    (let ((fname (format nil "eus~d~A.l" (unix:getpid)
			(symbol-name (gensym "C")))) (pname))
      (apply #'dump-function fname funcs)
      (compile-file fname)
      (unix:unlink fname)
      (setq pname (make-pathname :defaults fname :type "c"))
      (unix:unlink (namestring pname))
      (setq pname (make-pathname :defaults fname :type "h"))
      (unix:unlink (namestring pname))
      (setq pname (make-pathname :defaults fname :type
        #-(or :linux :cygwin) "o"
        #+:cygwin       "dll"
	#+:linux	"so"
	))
      (load pname)
      (unix:unlink (namestring pname))
      #+(or :linux :cygwin)
      (unix:unlink (namestring (make-pathname :defaults fname :type "o")))
      funcs
      ))

(defun compile-file-if-src-newer (srcfile &optional (objdir "./")
					  &rest args)
   (let ((src (merge-pathnames srcfile ".l"))
	 (obj (merge-pathnames objdir (pathname srcfile)))
	 (obj. (merge-pathnames ".o" (pathname srcfile))) )
     (send obj :type  "o")
     (when (or (null (probe-file obj)) (file-newer src obj))
	(apply #'compile-file srcfile :o obj args) 
	)
     srcfile  ))
	 

(defun comp-file-toplevel (&rest argv)
   (warn "EusLisp compiler version 1.54   June/1986 ... May/1996")
   (terpri *error-output*)
   (sys:alloc 60000)
   (setq lisp::*prompt-string* "euscomp$ ")
   (let ((i 1) (l (length argv)) (arg) (flag))
      (cond ((< l 1) (apply #'eustop argv))
	    ((< l 2)
	      (format t
	";euscomp [-c] [-V] [-O] [-On] [-Sn] [-X form] [-P pkg] [-D feature] file1 file2 ...~%")
	      (exit 1) )
	    (t
	      (while (< i l)
		(catch 0
		 (setq arg (elt argv i))
        	 (setq flag (string-upcase arg))
		 (incf i)
		 (cond ((equal flag "-O")
			 (if (not (memq :vax *features*)) 
				(setq *coptflags* " -O")))
		       ((equal flag "-O1")
			 (setq *optimize* 1))
		       ((equal flag "-O2")
			 (setq *optimize* 2))
		       ((equal flag "-O3")
			 (setq *optimize* 3))
		       ((equal flag "-V")
			 (setq *verbose* t))
		       ((equal flag "-S0") (setq *safety* 0))
		       ((equal flag "-S1") (setq *safety* 1))
		       ((equal flag "-S2") (setq *safety* 2))
		       ((equal flag "-S3") (setq *safety* 3))
		       ((equal flag "-X")
			 (eval (read-from-string (elt argv i)))
			 (inc i))
		       ((equal flag "-c")
			 (setq *do-cc* nil))
		       ((equal flag "-D")
			 (push (read-from-string (elt argv i)) *features*)
			 (inc i))
		       ((equal flag "-P")
			 (let ((pkg (read-from-string (elt argv i))))
			    (unless (find-package pkg)	(make-package pkg))
			    (in-package pkg))
			 (inc i))
		       ((equal flag "-pic")   (setq *pic* t))
		       ((string-equal flag "-npic") (setq *pic* nil))
		       (t (send comp :compile-file arg)	)))))
	      )
	    (exit 0)))
)

(provide :comp "@(#)$Id$")
