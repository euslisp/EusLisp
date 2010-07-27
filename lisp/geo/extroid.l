;; find the minimal circle for 2d-points
;;	(c)1990, MATSUI,T., ETL

;; generate 2d random vectors for test
;;
(defun 2d-random-vector (&optional (range 1.0) &aux (range/2 (/ range 2.0)))
     (float-vector (- (random range) range/2)
		   (- (random range) range/2)) )


(defun 2d-random-normalized-vector ()
   (normalize-vector (float-vector (random 1.0) (random 1.0))))

(defun 2d-random-vectors (n r)
  (if (< n 1)
      nil
      (cons (2d-random-vector r) (2d-random-vectors (1- n) r))))

;; extroid of triangle

(defun extroid (A B C)
  (let* (m v)
    (setq m (matrix (v- a b) (v- b c)))
    (setq v (float-vector (* 0.5 (v. (v+ a b) (v- a b)))
			  (* 0.5 (v. (v+ b c) (v- b c)))))
    (simultaneous-equation m v)))

(defun extroid3 (A B C)
  (let* (m v tn dist)
    (setq tn (triangle-normal a b c))
    (setq dist (v. tn a))
    (setq m (matrix (v- a b) (v- b c) tn))
    (setq v (float-vector (* 0.5 (v. (v+ a b) (v- a b)))
			  (* 0.5 (v. (v+ b c) (v- b c)))
			  dist))	
    (simultaneous-equation m v)))

(defun minimal-circle (points)
  (let* ((ab (farthest-pair points)) (a (first ab)) (b (second ab))
	 (center (scale 0.5 (v+ a b))) (radius  (/ (distance a b) 2.0))
	 (m 0.0) x)
     (if *debug* (print (list center radius)))
     (dolist (p points)
	(when (> (distance p center) radius)
	   (if *debug* (print p))
	   (let ((x1 (distance a p)) (x2 (distance b p)) )
	      (when (> %((x1 / x2) + (x2 / x1)) m)
	         (setq m %((x1 / x2) + (x2 / x1))
		       x p)))  )  )
    (cond (x (setq x (extroid a b x))
	     (list x (distance x a)))
	  (t (list center radius)))
    ))

(defun plot-points (points &optional (view *viewer*))
   (dolist (p points)
      (send view :draw-star-ndc p 0.02)))

(defun draw-circle (center radius &optional (view *viewer*))
   (send view :draw-arc-ndc
	 (homogenize (v+ center (float-vector (- radius) radius)))
	 (* 2.0 radius) (* 2.0 radius) 0.0 2pi))

(defun aho (n &aux a)
   (setq p (2d-random-vectors n 0.7))
   (cls)
   (plot-points p)
   (xflush)
   (setq a (minimal-circle p))
   (draw-circle (car a) (cadr a))
   (xflush))
