;;;
;;;	packsym.l	package and symbol manipulating functions
;;;	1987-Apr
;;;	T.Matsui
;
; extension of class symbol and package
;

(list "@(#)$Id: packsym.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")

(in-package "LISP")

(export '(symbol-plist remprop set  symbol-package symbol-name make-symbol 
	documentation gentemp
	packagep package-name package-nicknames 
	package-use-list package-used-by-list use-package unuse-package 
	make-package in-package rename-package shadow import
	symbol-string unintern
	package-stats))

(defun metaclass-name (x) (x . name))

(defmethod symbol
 (:home-package () homepkg)
 (:pname () pname)
 (:func () function)
 (:value (val)
    (if (= vtype 0) (error 11 self))
    (setq value val))
 (:constant (c &optional (doc nil))
    (when (= vtype 0)
       (eval-when (eval load)
	    (format *error-output*
		"multiple defconstant for ~s: ~s --> ~s~%" self value c))
       (eval-when (compile)
            (unless (equal value c)
                 (format *error-output*
		    "multiple defconstant for ~s: ~s --> ~s~%" self value c))))
    (if doc (putprop self doc :variable-documentation))
    (setq vtype 0
	  value c)
    self)
 (:special (v &optional (doc nil))	;thread local special var
    (if (= vtype 0) (error 11 self))
    (if doc (putprop self doc :variable-documentation))
    (setq vtype (system::next-special-index))	; originally, 2
    (set self v)	;(setq value v) is wrong
    self )
 (:global (v &optional doc)
    (setq vtype 2)
    (setq value v)
    (if doc (putprop self doc :variable-documentation))
    v)
 (:vtype (&optional set)
    (if set (setq  vtype set))
    vtype)
 (:init (pn &optional (vt 1))
    (setq pname pn vtype vt)
    self)
   ) 

(eval-when (load eval)
;(defun rplaca (s a) (send s :car a))
;(defun rplacd (s d) (send s :cdr d))
;(defun get (sym attribute) (send sym :get attribute))
;(defun putprop (sym val attribute) (send sym :put attribute val))
(defun symbol-plist (sym) (send sym :plist))
(defun remprop (sym attr) (send sym :remprop attr))
;(defun set (var val)
;  (if (symbolp var) (send var :value val) (error 11 var)))
(defun symbol-package (sym) (send sym :home-package))
(defun symbol-name (sym) (declare (symbol sym))
   (if (symbolp sym) (sym . pname) (error "not a symbol")))
(defun make-symbol (str &optional(pkg *package*))
   (if (not (stringp str)) (error "no string"))
   (let ((sym (instantiate symbol)))
	(declare (type symbol sym))
	(setq (sym . pname) str
	      (sym . vtype) 1
	      (sym . homepkg) pkg)
	(makunbound sym)
	sym))
(defun documentation (sym &optional type)
  (case type
    ((function :function) (get sym :function-documentation))
    ((variable :variable) (get sym :variable-documentation))
    ((class :class) (get sym :class-documentation))
    ((method :method) (get sym :method-documentation)) 
    (t
	  (cond 
	    ((get sym :function-documentation))
	    ((get sym :method-documentation))
	    ((get sym :class-documentation))
	    ((get sym :variable-documentation)))
	))    )

;; generate temporary symbols
(setq *gentemp-index* 0)
(defun gentemp (&optional (prefix "T") (pkg *package*))
   (let (s)
      (while (find-symbol
		   (setq s (concatenate string prefix (string *gentemp-index*)))
		   pkg)
	(setq *gentemp-index* (1+ *gentemp-index*)))
      (intern s pkg)))
)


(eval-when (load eval)
(defmethod package
 (:use-list () use)
 (:used-by-list () used-by)
 (:used-by (a) (setq used-by (adjoin a used-by)))
 (:use (pkg) 
   (if (listp pkg)
       (progn 
	 (while pkg
	    (send self :use (car pkg))
	    (setq pkg (cdr pkg)))
	 use)
       (let ((h))
	 (setq pkg (find-package pkg))
	 (when (and (not (eq pkg self)) (packagep pkg))
	    ;; check conflict between pkg's ext. symbols and own int syms.
	    (do-external-symbols (sym pkg)
		(setq h (send self :find sym))
		(if (and h (not (eq (svref intsymvector h) sym)))
		    (error "symbol conflict ~s in ~s" sym self)))
	    (setq use (adjoin pkg use))
	    (send pkg :used-by self))))   )
 (:unuse (pkg)
   (setq pkg (find-package pkg))
   (when (packagep pkg)
       (setq use (delete pkg use))
       (send pkg :unused self)))
 (:unused (pkg)
   (setq used-by (delete pkg used-by)))
 (:name () (car names))
 (:rename (s) (setq names (list (string s))))
 (:nicknames (&optional n)
    (if n (setq names (union names (mapcar #'string n) :test #'equal) ))
    names)
 (:hash (s)
    (setq s (string s))
    (mod (sxhash s) (length intsymvector)))
 (:enter (sym)
    (if (not (symbolp sym)) (return-from :enter nil))
    (let ((hash (mod (sxhash sym) (length intsymvector)))
          (size (length intsymvector)))
      (if (>= intsymcount size)  (error "can not enter ~a into this package, maximum symbol size is ~a" sym size))
      (while (symbolp (svref intsymvector hash))
	(if (>= (setq hash (1+ hash)) size) (setq hash 0)))
      (svset intsymvector hash sym)
      (setq intsymcount (1+ intsymcount))
      sym))
 (:find (s)	;find symbol just in this package
    (declare (symbol s))
    (if (null (symbolp s)) (error "symbol expected"))
    (let* ((size (length intsymvector)) (hash (mod (sxhash s) size)) sym)
      (declare (symbol sym))
      (while t
	(setq sym (svref intsymvector (mod hash size)))
	(cond ((eq sym 0) (return-from :find nil))
	      ((eq sym 1) #|deleted mark -- do nothing|# )
	      ((equal (sym . pname) (s . pname)) (return-from :find (mod hash size))))
	(if (>= (setq hash (1+ hash)) (* 2 size)) (error "can not find ~a in this package" sym)))
      nil))
 (:shadow (sym)
      (when (null (send self :find sym))
	  (send self :enter (make-symbol (string sym) self))))
 (:import (sym)
    (let ((s (send self :find sym)))
       (if (and s (not (eq sym (svref intsymvector s))))
	   (error "~a cannot be imported due to symbol conflict" sym)
	   (send self :enter sym))) )
 (:unintern (sym)
    (let ((pos))
      (if (eq (sym . homepkg) self)
	  (setq (sym . homepkg) nil))
      (setq pos (send self :find sym))
      (when pos
	(svset intsymvector pos 1)		;deleted mark
	(setq intsymcount (1- intsymcount)))
      (setq pos (send self :find-external sym))
      (when pos
	(svset symvector pos 1)		;deleted mark
	(setq symcount (1- symcount)))
    ))
 (:find-external (s)
    (declare (symbol s))
    (if (null (symbolp s)) (error "symbol expected"))
    (let* ((size (length symvector)) (hash (mod (sxhash s) size)) sym)
      (declare (symbol sym))
      (while t
	(setq sym (svref symvector hash))
	(cond ((eq sym 0) (return-from :find-external nil))
	      ((eq sym 1) #|deleted mark -- do nothing|# )
	      ((equal (sym . pname) (s . pname))
		(return-from :find-external hash)) )
	(if (>= (setq hash (1+ hash)) size) (setq hash 0)))
      nil))
;; (:export (sym)
;    (let ((hash (mod (sxhash (symbol-string sym)) (length symvector)))
;	  (size (length symvector)) )
;       (while t
;	  (cond ((eq (svref symvector hash) sym)
;		 (return-from :export sym))
;	  	((symbolp (svref symvector hash))
;	         (incf hash)
;		 (if (>= hash size) (setq hash 0)))
;		(t (svset symvector hash sym)
;		   (incf symcount)
;		   (return-from :export sym)))) ))
  (:unexport (sym)
     (let ((p (send self :find-external sym)))
	(if p (svset symvector p 0))))) 

(defun package-name (pkg)
  (setq pkg (find-package pkg))
  (send pkg :name))
(defun package-nicknames (pkg)
  (send (find-package pkg) :nicknames))
(defun package-use-list (pkg)
  (send (find-package pkg) :use-list))
(defun package-used-by-list (pkg)
  (send (find-package pkg) :used-by-list))
(defun packagep (pkg) (eq (class pkg) package))
(defun use-package (pkg &optional (curpkg *package*))
  (send curpkg :use pkg)
  t)
(defun unuse-package (pkg &optional (curpkg *package*))
  (send (find-package curpkg) :unuse pkg))

(defun make-package (pkgname &key (nicknames) (use (list "LISP")))
   (let ((pkg (system::makepackage pkgname nicknames use)))
      (send pkg :use use)
      pkg))

(defmacro in-package (pkgname)
  `(if (find-package ,pkgname)
	(setq *package* (find-package ,pkgname))
	(error "no such package")))

(defun rename-package (pkg new-name &optional new-nicks)
   (setq pkg (find-package pkg))
   (send pkg :rename new-name)
   (if new-nicks (send pkg :nicknames new-nicks)))
(defun shadow (sym &optional (pkg *package*))
   (if (symbolp sym)
	(send pkg :shadow sym)
	(while sym (send pkg :shadow (car sym)) (setq sym (rest sym)))))
(defun import (x &optional (pkg *package*))
   (if (symbolp x)
       (send  pkg :import x)
       (while x (send pkg :import (car x)) (setq x (rest x))))
   t)
(defun symbol-string (s)
   (if (symbolp s) (s . pname) (error "not a symbol")))
(defun unintern (s &optional (pkg *package*))
   (if (symbolp s) (send pkg :unintern s) (error "no symbol")))
)

(defun package-stats (&optional (s t) &aux use used)
  (dolist (p (list-all-packages))
    (setq use (mapcar #'car (send-all (package-use-list p) :nicknames)))
    (setq used (mapcar #'car (send-all (package-used-by-list p) :nicknames)))
    (format s "~10a ~10a ~5d using=~a used-by=~a~%"
	(car (send p :nicknames)) 
	(if (cdr (send p :nicknames)) (cdr (send p :nicknames)) "")
	(package-symcount p)
	(if use use "")
	(if used used ""))
))

