;;;;	mathtran.l
;;;;	convert C-like arithmethic expressions into lisp notation.
;;;;	1987-Sep
;;;;	Copyright (c) 1987,
;;;;	Toshihiro MATSUI, Electrotechnical Laboratory
;;;;	Tsukuba-city, Ibaraki, 305 JAPAN

(in-package "LISP")

#+:kcl
(defmacro while (cond &rest body)
   `(do ()
        ((not ,cond))
	. ,body))
#+:kcl
(defun memq (x l) (member x l :test #'eq))

(defun expression (exp &optional (lhs nil) &aux result letvar-alist)
  (labels
     (
      (letvar (form)
	   (let ((v (assoc form letvar-alist :test #'equal)))
		(cond (v (incf (third v)) (second v))
		      (t (setf v (gensym))
			 (push (list form v 1) letvar-alist)
			 v))))
      (factor1 (exp)
	(let* ((sy (pop exp)) (arglist) form)
	   (cond
	     ((consp sy)
		(multiple-value-setq (sy form) (expr sy))
		(if form (error "illegal math expression for % macro"))
		(values sy exp))
	     ((consp (first exp))	;function call or array ref.
		(setf arglist (pop exp))
		(cond ((eq (first arglist) 'aref)
		        (setf arglist (expr-list (rest arglist)))
			(setf form (cons 'aref (cons sy arglist)))
			(unless lhs (setf form (letvar form)))
			(values form exp))
		      (t
			(values (letvar (cons sy (expr-list arglist))) exp) )) )
	     (t (values sy exp)))))
      (factor (exp)
	(let* ((left) (right) (form))
	   (multiple-value-setq (left exp) (factor1 exp))
	   (cond
	      ((eq (first exp) '**)
		(multiple-value-setq (right exp) (factor1 (rest exp)))
		(cond
		   ((and (integerp right) (< right 10))
		    (setf form (list '*))
		    (cond ((atom left) 
			    (dotimes (i right) (nconc form (list left)))
			    (values (letvar form) exp))
			  (t 
			   (dotimes (i right) (nconc form (list 'temp)))
			    (values `(let ((temp ,left)) ,form) exp))))
	  	   (t	(values (list 'expt left right) exp))))
	      ((numberp left) (values left exp))
	      (t (values left exp) ))) )
      (term (exp)
	  (let* ((left) (op) (right))
	    (multiple-value-setq (left exp) (factor exp))
	    (setf op (first exp))
	    (cond
		((memq op '(* /))
		 (while (memq op '(* /))
		    (setf left (list op left))
		    (while (eq (first exp) op)
		       (multiple-value-setq (right exp) (factor (rest exp)))
		       (nconc left (list right))   )
		    (setf op (first exp)))
		 (values left exp))
		(t (values left exp)))))
      (expr (exp)
	  (let* ((op (first exp)) (left) (right))
	    (if (memq op '(+ -))	;+- as unary operator
		(setf  exp (rest  exp)))
	    (multiple-value-setq (left exp) (term exp))
	    (if (eq op '-)
		(setf left (list op  left)))
	    (when (memq (first exp) '(+ -))
		 (setf left (list '+ left))
	         (while (memq (setf op (first exp)) '(+ -))
		     (multiple-value-setq (right exp) (term (rest exp)))
		     (if (eq op '-) (setf right (list '- right)))
		     (nconc left (list right))))
	     (values left exp)))
      (expr-list (exp)
	  (let (temp result)
	    (while exp
		(multiple-value-setq (temp exp) (expr exp))
		(push temp result))
	    (nreverse result)))
      (rel-expr (exp)
	  (let ((left) (op) (right))
	    (multiple-value-setq (left exp) (expr exp))
	    (setf op (pop exp))
	    (when (memq op '(== != /= < >  <= >=))
		(multiple-value-setq (right exp) (expr exp))
	        (setf left
		    (list (second (assoc op '((== =) (!= /=) (/= /=) (< <)
					      (<= <=) (> >) (>= >=))))
		          left right)))
	    (values left exp)))	
      (reconstruct-form (exp)
        (setf exp (list exp))
	(let ((letpairs))
	   (dolist (lv  letvar-alist)
	      (if (> (third lv) 1)	;referenced more than once
		  (push (list (second lv) (first lv)) letpairs)
		  (nsubst (first lv) (second lv) exp)))
	   (if letpairs
	       `(let* ,letpairs  . ,exp)
	       (first exp)))))
   (multiple-value-setq (result exp) (rel-expr exp))
   (if exp (error "illegal expression in % macro"))
   (reconstruct-form result) ))

(defun infix2prefix (file &optional char)
  (let ((exp (read file)))
     (cond
	((symbolp exp)	;probably a left-hand-side array ref.
	 (expression (list exp (read file)) t))
	((eq (second exp) '=)
	 (list 'setq (car exp) (expression (cddr exp) nil)))
	((eq (third exp) '=)
	 (list 'setf (expression (list (first exp) (second exp)) t)
		     (expression (cdddr exp) nil)))
        (t  (expression exp nil)))) ) )

(defun read-aref (file &optional char)
   (cons 'aref (read-delimited-list #\] file)))

(set-macro-character #\% 'infix2prefix)
(set-macro-character #\[ 'read-aref)
(set-syntax-from-char #\] #\))

(provide :mathtran "@(#)$Id: mathtran.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")

