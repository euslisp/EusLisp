;;;; solve-inequalities.l
;;;;
;;      from Constraints to Motion and Force
;;
;;
;;                            Programmed by Hirohisa HIRUKAWA
;;
;;                                      Intelligent Machine Behavior Section
;;                                      Electrotechnical Laboratory
;;                                      1-1-4 Umezono, Tsukuba 305, JAPAN
;;                                      E-mail: hirukawa@etl.go.jp
;;
;;   Version 1.00   May  1, 1990.
;;   Version 1.01   Sep 14, 1990.     Modify.  c-body:draw-motion
;;   Version 1.02   Oct  2, 1990.     Modify.  c-body:draw-motion
;;                                    Extend.  function:make-inequalities
;;                                             function:solve-inequalities
;;   Version 1.03   Oct 11, 1990.     Add.     c-body:slot force
;;                                             c-body:force
;;                                             c-body:draw-force  
;;                                    Rename.  c-body:solve-constraint 2 motion
;;   Version 1.04   Oct 12, 1990.     Add.     function:norm-difv
;;   Version 1.05   Oct 17, 1990.     Add.     c-body:local-motion
;;                                             c-body:local-force
;;   Version 1.06   Oct 18, 1990.     Add.     c-body:work
;;   Version 1.07   Jan 17, 1992.     Bug fix. clib:cone_inter.c
;;   Version 2.00   Oct 12, 1995.     Port to Solaris2 and IRIX

(provide 'inequalities)

(eval-when (load eval compile) (in-package "GEOMETRY"))
(require :geoclasses "geoclasses.l")

(format t ";;;; solve-inequalities v1.07 Jan.17.1992.~%")

(export '(eqmotion norm-difv make-jacobian-world-pos make-jacobian-world
	  make-inequalities solve-inequalities
	  constrained-motion constrained-force
	  solve-cone convexcone-module))

(defparameter *maxrank* 6)
(defparameter *maxcp* 100)
(defparameter *motion-threshold* 0.1)

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
  (let ((rot (unit-matrix 3)) (jacobian (unit-matrix 6)))
    (dotimes (i 3)
      (replace (jacobian . entity) (v* pos (matrix-column rot i))
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
(defparameter convexcone-module
	(load-foreign "cone/convexconeref.o"
		       :ld-option "-Lclib -lconvexcone -lm"
		       :symbol-output "convexcone"
		       :symbol-file "convexcone"))

#+(or :solaris2 :irix)
(defparameter convexcone-module
	(load-foreign "clib/libconvexcone.so"))

#-(or :solaris2 :irix)
(defforeign  solve-cone convexcone-module "_cone_inter" () :integer)

#+(or :solaris2 :irix)
(defforeign  solve-cone convexcone-module "cone_inter" () :integer)

(defun solve-inequalities (inequalities)
  (let (n ineq (w (instantiate float-vector (* *maxrank* *maxcp*)))
	  en wlist wl)
    (when (null inequalities)
	  (print 'no-constraints-found)
	  (return-from solve-inequalities nil))
    (setq n (length inequalities))
    (when (> n 32)
	  (print 'too-many-constraints-found-to-solve)
	  (return-from solve-inequalities nil))
    (dotimes (i n)
      (when (> (length (elt inequalities i)) 1)
	(setq ineq (copy-seq inequalities)) 
	(setf (elt inequalities i) (list (car (elt inequalities i))))
	(setf (elt ineq i) (cdr (elt ineq i)))
	(return-from solve-inequalities
	 (append (solve-inequalities inequalities)
		 (solve-inequalities ineq)))))
    (setq inequalities (mapcar #'car inequalities))
    (setq inequalities (apply #'matrix inequalities))
    (setq en (solve-cone (inequalities . entity) n w))
    (dotimes (i en (list wl))
      (push (norm-difv (subseq w (* *maxrank* i) (* *maxrank* (+ i 1)))) wl))))

(defun constrained-motion (constraint)
   (solve-inequalities (make-inequalities constraint)))

(defun constrained-force (motion)
   (let (inequalities en n 
	 (w (instantiate float-vector (* *maxrank* *maxcp* ))) wl)
     (when (null motion)
       (print 'error-no-motions-found)
       (return-from constrained-force nil))
     (dolist (mm motion)
       (dolist (m mm)
	 (pushnew (scale -1.0 m) inequalities :test #'eqmotion)))
     (setq n (length inequalities))
     (setq inequalities (apply #'matrix inequalities))
     (setq en (solve-cone (inequalities . entity) n w))
     (dotimes (i en (list wl))
       (push (norm-difv (subseq w (* *maxrank* i) (* *maxrank* (1+ i)))) wl))
     (list wl)))



