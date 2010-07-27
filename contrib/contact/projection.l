;;;; projection.l
;;;;
;;                            Programmed by Hirohisa HIRUKAWA
;;
;;                                      Intelligent Machine Behavior Section
;;                                      Electrotechnical Laboratory
;;                                      1-1-4 Umezono, Tsukuba 305, JAPAN
;;                                      E-mail: hirukawa@etl.go.jp

(eval-when (load eval compile) (in-package "GEOMETRY"))
(require :geoclasses "geoclasses.l")

(format t ";;;; projection v1.00 Sep.13,1996.~%")

(export '(eqmotion norm-difv make-jacobian-world-pos make-jacobian-world
	  make-inequalities find-projection possible-motion
	  projection projection-module))

(defparameter *maxrank* 6)
(defparameter *maxcp* 100)
(defparameter *motion-threshold* 0.1)
(defparameter *scale-rotation* 0.001)

(defun eqmotion (x y)
  (< (norm (v- x y)) *motion-threshold*))

;;
;;    Normalizing the differential vector
;;

(defun norm-difv (v)
  (let ((nor 0.0) (wr 20000.0) (wp 20.0))
    (dotimes (i 3) (setq nor (+ nor (* (elt v i) (elt v i)))))
    (dotimes (i 3) (setq nor (+ nor (* wr (elt v (+ i 3)) (elt v (+ i 3))))))
    (setq nor (sqrt nor))
    (setq nor (/ 1 nor))
    (scale (* nor wp) v)))


;;
;;    Calculating 3x6 Jacobian matrix from the position of constraining point
;;    represented in the world coordinate

(defun make-jacobian-world-pos (pos)
  (let ((rot (unit-matrix 3)) (jacobian (unit-matrix 6)) (s *scale-rotation*))
    (dotimes (i 3)
      (replace (jacobian . entity) (scale s (v* pos (matrix-column rot i)))
	       :start1 (+ (* i 6) 3) :end1 (+ (* i 6) 6)))
    (matrix (matrix-row jacobian 0)
	    (matrix-row jacobian 1)
	    (matrix-row jacobian 2))))

;;
;;    Calculating 6x6 Jacobian matrix from the position of constraining point
;;    represented in the world coordinate

(defun make-jacobian-world (pos)
  (let ((rot (unit-matrix 3)) (jacobian (unit-matrix 6)))
    (dotimes (i 3)
      (replace (jacobian . entity) (v* pos (matrix-column rot i))
	       :start1 (+ (* i 6) 3) :end1 (+ (* i 6) 6)))
    jacobian))

;;
;;    Making a linear inequalities from constraint condition
;;

(defun make-inequalities (clists)
  (let (inequalities or-inequalities)
   (dolist (clist clists)
    (dolist (c (constraint-relation-constraints clist))
     (dolist (and-c (constrained-point-condition c))
      (dolist (or-c and-c)
       (if or-c
	   (push
	    (array-entity
	     (m* (matrix or-c)
		 (make-jacobian-world-pos 
		  (constrained-point-position c))))
	    or-inequalities)
	 (return-from make-inequalities nil)))
      (push or-inequalities inequalities)
      (setq or-inequalities nil))))
   inequalities))


;;
;;    Solving a linear inequalities
;;

#-(or :solaris2 :irix)
(defparameter projection-module
	(load-foreign "projection/projectionref.o"
		       :ld-option "-Lclib -lprojection -lm"
		       :symbol-output "projection"
		       :symbol-file "projection"))

#+(or :solaris2 :irix)
(defparameter projection-module
	(load-foreign "clib3/libprojection.so"))

#-(or :solaris2 :irix)
(defforeign  projection projection-module "_projection_inter" () :integer)

#+(or :solaris2 :irix)
(defforeign  projection projection-module "projection_inter" () :integer)

(defun find-projection (motion-in inequalities)
  (let (n ineq wlist wl (motion-out (instantiate float-vector *maxrank*)))
    (when (null inequalities)
	  ; (print 'no-constraints-found)
	  (return-from find-projection motion-in))
    (setq n (length inequalities))
    (when (> n 32)
	  (print 'too-many-constraints-found-to-solve)
	  (return-from find-projection (float-vector 0 0 0 0 0 0)))
    (dotimes (i n)
      (when (> (length (elt inequalities i)) 1)
	(setq ineq (copy-seq inequalities)) 
	(setf (elt inequalities i) (list (car (elt inequalities i))))
	(setf (elt ineq i) (cdr (elt ineq i)))
	(return-from find-projection
	 (append (find-projection motion-in inequalities)
		(find-projection motion-in ineq)))))
    (setq inequalities (mapcar #'car inequalities))
    (setq inequalities (apply #'matrix inequalities))
    (projection (inequalities . entity) n motion-in motion-out)
    ; (format t "motion-in: ~s~%" motion-in)
    ; (format t "motion-out: ~s~%" motion-out)
    (list motion-out)))

(defun possible-motion (motion-in clist)
  (let (projs (proj (float-vector 0 0 0 0 0 0)))
    (setq projs (find-projection motion-in (make-inequalities clist)))
    (dolist (p projs) (if (< (norm proj) (norm p)) (setq proj p)))
    proj))


