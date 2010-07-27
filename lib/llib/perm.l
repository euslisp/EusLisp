;;;; Permutation and Combination
;; It is a bad idea to generate permutations recursively, since stack over-
;; flows soon.  Use of permutation generator class is recommended.
;;
;; Aug/16/1991 (c) Toshihiro MATSUI, Electrotechnical Laboratory
;;

   

(defun list-permutation (x)
 (labels ((perm2 (a bb cc dd)
	   (cond ((null cc) (cons  (append bb (list a)) dd))
		 (t (perm2 a (append bb (list (car cc)))
			     (cdr cc) 
			     (cons (append bb (list a) cc) dd) )
		     ))) )
    (cond ((null x) nil)
	  ((null (cdr x)) (list x))
	  (t 
	     (mapcan
		#'(lambda (y) (perm2 (car x) nil y nil))
		(list-permutation (cdr x)))))) )


;; permutaion generator
;; sending :next returns a new permutaion of a list in turn
;;
(defclass permutation :super propertied-object
		      :slots (mlist sub-permutation a b c count))

(defmethod permutation
 (:next ()
    (if (null c)
        (if sub-permutation
	    (if (null b)
	        (setq c (send sub-permutation :next))
	        (return-from :next
		   (prog1 (nconc b (list a)) (setq b nil count (1+ count)))) )
	    (return-from :next
		   (if (null b)
			(setq count (1+ count) b mlist)
			 nil ))  ) )
    (if (null c)
	nil
	(prog1 (append b (cons a nil) c)
	       (setq b (nconc b (list (car c)))
		     c (rest c)
		     count (1+ count)))) )
 (:all (&aux x r)
    (while (setq x (send self :next))
	(push x r))
    r)
 (:reset ()
    (if sub-permutation (send sub-permutation :reset))
    (setq a (car mlist)
	  b nil
	  c nil
	  count 0))
 (:init (l)
    (setq mlist l)
    (when (cdr l)
	(setq sub-permutation (instance permutation :init (cdr mlist))))
    (send self :reset)
    self))

;;****************************************************************
;; combination
;;
;; (combi list r) generates all the combination list which is composed of
;; r-elements in the list.
;; (combi2 list) is a spcecial case of the combination and equivalent to
;; (combi list 2), but more efficient.

(defun combi (lst r)
   (cond ((= r 1) (mapcar #'list lst))
	 (t  (mapcon
		#'(lambda (y)
			(mapcar #'(lambda (z) (cons (car y) z))
				(combi (cdr y) (1- r))))
		lst))))

(defun combi2 (lst)
    (mapcon 
	#'(lambda (x)
		(mapcar #'(lambda (y) (list (car x) y))
			(cdr x)))
	 lst))

(defmacro docombi (A B &rest forms)
   `(dolist ,A
	(dolist ,B . ,forms)))


