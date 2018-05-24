;;;; object.l
;;;; Copyright 1990/Sep MATSUI, T., ETL
;;;; split from packsym.l

(list "@(#)$Id: object.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")

(eval-when (load eval)
(in-package "LISP")
(export '(metaclass-name metaclass-vars))

(defun metaclass-name (x) (x . name))
(defun metaclass-vars (x) (x . vars))

(defmethod object 
 (:prin1 (&optional (strm t) &rest msgs)
    (format strm "#<~A #X~x"
	    (metaclass-name (class self)) (system:address self))
    (dolist (s msgs) (format strm " ~A" s))
    (princ ">" strm)
    self)
 (:warning (format &rest mesgs)
	(apply #'warn format mesgs))
 (:error (&rest mesgs) (send* self :warning mesgs) (reploop "err: "))
 (:slots ()
    (let ((vars (metaclass-vars (class self))) (slots nil))
	(dotimes (i (length vars))
	   (push (cons (elt vars i) (slot self (class self) i)) slots))
	(nreverse slots)))
 (:methods (&optional (pattern ""))
    "(self class &optional (pattern \"\"))
Returns the list of all methods callable by the object. If pattern is given, returns only methods with names that include pattern."
    (mapcan #'cadr (send (class self) :all-method-names pattern)))
;; (:all-methods () (send (class self) :all-method-names))
 (:super () (send (class self) :super))
 (:get-val (s) (slot self (class self) s))
 (:set-val (s v) (setslot self (class self) s v))
)

(defmethod propertied-object
 (:plist (&optional p) (if p (setq plist p) plist))
 (:get (tag) (cdr (assq tag plist)))
 (:put (tag val)
    (let ((p (assq tag plist)))
       (if p (send p :cdr val)
	   (progn (setq plist (cons (cons tag val) plist))))
       val))
 (:name (&optional n)
    (if n (send self :put :name n) (send self :get :name)))
 (:remprop (attr)
    (let ((x (assq attr plist)))
	(if x
	    (setq plist (delete x plist))
	    nil)))
 (:prin1 (&optional (strm t) &rest msg &aux (name (send self :name)))
    (if name (send-super-lexpr :prin1 strm name msg)
	     (send-super-lexpr :prin1 strm msg)))
 )

(defmethod metaclass 
 (:new () (instantiate self))
 (:super () super)
 (:methods () methods)
 (:method (selector) (assoc selector methods))
 (:method-names (&optional (pat ""))
    (setq pat (string-upcase (string pat)))
    (mapcan #'(lambda (meth)
		 (setq meth (car meth))
		 (if (substringp pat (symbol-name meth))
		     (cons meth nil)
		     nil))
	 methods))
 (:all-methods ()
    (if super (append methods (send super :all-methods) ) methods))
 (:all-method-names (&optional (pattern ""))
    (let ((mself (list name (send self :method-names pattern)))
	  (msuper (if super (send super :all-method-names pattern) nil)))
	(cons mself msuper)))
 (:slots () vars)
 (:name () name)
 (:cid () cix)
 (:cix () cix)
 (:sub ()
    (let (r)
       (dolist (a (system:list-all-classes))
	  (if (eql (send a :super) self) (push a r)) )
       r))
 (:subclasses () (send self :sub))
 (:hierarchy ()  ;list all descendant classes
    (let (h)
	(dolist (s (send self :sub))
	   (push (send s :hierarchy) h))
        (cons self (nreverse h))))
 (:superclasses ()
    (let (r (s (send self :super)))
       (while  s
	  (push s r)
	  (setq s (send s :super)))
       (nreverse r)))
  )

(defmethod load-module
  (:prin1 (&optional (strm t) &rest msgs)
    (send-super-lexpr :prin1 strm
	(concatenate string "\"" object-file "\"")
        msgs)))
) ; eval-when

