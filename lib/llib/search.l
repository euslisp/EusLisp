;;;;
;;;; search.l
;;;;	search functions library
;;;	Copyright (c) 1989, Toshihiro MATSUI, ETL
;;;	depth-first, breadth-first receive three arguments,
;;;	namely start-node, finish-node and the node extension function.
;;;	best-first, hill-climb, branch-and-bound require a cost evaluating
;;;	function as its third argument.

(defmethod edge 
 (:all-wings () (list (send self :nwing)
		      (send self :pwing)
		      (send self :ncwing)
		      (send self :pcwing))))

;; given a list of node, extend the first node and return the list of subnodes.
(defun extend-wing (path)
   (mapcar #'(lambda (new-node) (cons new-node path))
	   (remove-if #'(lambda (neighbor) (member neighbor path))
		      (send (first path) :all-wings))))

(defun depth-first (start finish extend &optional (queue (list (list start))))
   (cond ((endp queue) nil)
	 ((eq finish (first (first queue)))
	  (nreverse (first queue)))
	 (t (depth-first start finish extend
			 (append (funcall extend (first queue)) (rest queue))))))

(defun breadth-first (start finish extend &optional (queue (list (list start))))
   (cond ((endp queue) nil)
	 ((eq finish (first (first queue)))
	  (nreverse (first queue)))
	 (t (breadth-first start finish extend
			 (append  (rest queue) (funcall extend (first queue)))))))

(defun edge-distance-eval (e1 e2)
;    (format t "~s ~s~%" e1 e2)
   (cond ((null e1) nil)
	 ((null e2) t)
	 (t
           (let ((p0 (send (car (last e1)) :point 0.5))
		 p1 p2 d1 d2)
	     (setq p1 (send (car e1) :point 0.5))
	     (setq d1 (distance p0 p1))
	     (setq p1 (send (car e2) :point 0.5))
	     (setq d2 (distance p0 p1))
	     (format t "~s ~s~%" d1 d2)
	     (if (>= d1 d2) t nil) )
     ) ))

(defun best-first (start finish extend evaluator
			 &optional (queue (list (list start))))
   (cond ((endp queue) nil)
	 ((eq finish (first (first queue)))
	  (nreverse (first queue)))
	 (t (best-first start finish extend evaluator 
			 (merge cons
				(sort (funcall extend (first queue)) evaluator)
				(rest queue)
				evaluator)))))

(defun hill-climb (start finish extend evaluator &optional (queue (list (list start))))
   (cond ((endp queue) nil)
	 ((eq finish (first (first queue)))
	  (nreverse (first queue)))
	 (t (hill-climb start finish extend evaluator
			(append  (sort (funcall extend (first queue))
				       evaluator)
				 (rest queue))))))

(defun branch-and-bound (start finish extend evaluator
				      &optional (queue (list (list start))))
   (cond ((endp queue) nil)
	 ((eq finish (first (first queue)))
	  (nreverse (first queue)))
	 (t (branch-and-bound start finish extend evaluator
			(sort (append (funcall extend (first queue))
				      (rest queue))
			      evaluator)))))

;;; example
;;; make a complex body, and search a path from an edge to another.
;;; each face should not have any hole.

(defun make-ex ()
   (let (a b c d)
      (setq a (make-cube 200 200 100)
	    b (make-cylinder 50 200))
      (send b :rotate (/ pi -4) :x)
      (send b :rotate (/ pi -4) :y)
      (send b :translate #f(0 0 80))
      (setq c (body+ a b))
      (setq d (make-cube 50 60 80))
      (send d :translate #f(-170 170 160))
      (setq bod (body+ c d))) )

(make-ex)
(setq e1 (send bod :edge 0)
      e2 (car (last (send bod :edges))))

;; (setq x (breadth-first e1 e2 #'extend-wing))	;infinite loop

