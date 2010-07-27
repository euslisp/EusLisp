;;; add 1988.8.15 m.i
(defmethod plane
;;; crossing
  (:cross-with-3dline   (l)
   (let*
       ((o (send l :ori))
	(p (send l :pos))
	(a (send self :project-3dvector p)))
     (v+ p (scale (/ (v. normal (v- a p)) (v. normal o)) o))))
  (:cross-with-plane   (pl)
   (let
       ((ori (v* (send self :normal) (send pl :normal))))
     (instance
      ori
      (send self :cross-with-planes pl
	    (make-plane :normal ori :point (float-vector 0 0 0))))
     ))
  (:new-from-3-3dvector (p1 p2 p3)
	(send self :init
	      p2
	      (normalize-vector (v* (v- p3 p2)
				    (v- p1 p2)))
	      ))
  (:new-from-3dline-3dvector   (3dl 3dv)
   (let ((p0 (send 3dl :pos)))
     (send self :init
	   (v* (send 3dl :ori) (v- 3dv p0))
	   p0)     ))
  (:ori () normal)
;;; projection
  (:project (obj)
    (cond
     ((derivedp obj float-vector) (send self :project-3dvector obj))
     ((derivedp obj 3dlnseg) (send self :project-3dlnseg obj))
     ((derivedp obj 3dline) (send self :project-3dline obj))))
  (:project-3dvector   (&optional (pos (float-vector 0 0 0)))
   (v- (v- pos (scale distance normal))
       (scale (v. pos normal) normal)))
  (:project-3dlnseg (3dls)
    (make-3dlnseg
	     (send self :project-3dvector (3dlnseg-spos 3dls))
	     (send self :project-3dvector (3dlnseg-epos 3dls))))
  (:project-3dline   (l)
   (let*
       ((h (send self :cross-with-3dline l))
	(p (send self :project-3dvector (send l :pos))))
     (instance 3dline :init (v- h p) p)))
  )
;;; end of UTYO extension

;;
;; UTYO extension
;;
(defmethod face
  (:center-coordinates   ()
   (let* ((z normal)
	  (x (if (< (abs (- 1 (abs (v. z #f(1 0 0))))) 0.0001)
		 #f(0 1 0)
		 #f(1 0 0)))
	  (y (v* z x))
	  )
     (setq x (v* y z))
     (instance coordinates :init
	       :rot (transpose (matrix x y z))
	       :pos (vector-mean (cdr vertices))))   )  )



;; UTYO extension

(defmethod body
  (:center-coordinates   ()
   (instance coordinates :init :rot rot :pos (vector-mean vertices))
   ; centroid would be more preferable
   )  )

