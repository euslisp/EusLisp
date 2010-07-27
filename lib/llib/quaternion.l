;;; Hamilton's quaternion
;;;	1989-Jan-13	(c) T.Matsui,ETL
;;;	1098-Mar-27

;; In this implementation, rotation angle is restricted to be positive, 
;; i.e., 0<theta<2pi
;;

(defclass quaternion :slots (s		; cos(theta/2)
			     a))	; sin(theta/2)* unit-axis-vector


(defmethod quaternion
 (:newquat (ss aa) (setq s ss a aa ) self)
 (:init (ss aa)	;aa need not to be normalized
    (send self :newquat
		ss   (scale (sqrt (- 1.0 (* ss ss))) (normalize-vector aa))))
 (:norm () (sqrt (+ (* s s) (v. a a))))
 (:conjugate () (instance quaternion :newquat s (v- a)))
 (:inverse-quaternion ()
    (let ((norm (send self :norm)))
	(instance quaternion :newquat (/ s norm) (scale (/ 1.0 norm) (v- a)))))
 (:rotation (theta axis)
    (send self :init (cos (/ theta 2.0))  axis))
 (:inverse-transform-vector (v)
    (v+ (v- (scale (- (* 2.0 s s) 1.0) v)
	    (scale (* 2.0 s) (v* a v)))
	(scale (* 2.0 (v. a v)) a)))
 (:transform-vector (r)
    (v++ (scale (- (* 2.0 s s) 1.0) r)
	 (scale (* 2.0 (v. a r)) a)
	 (scale (* 2.0 s) (v* a r))))
 (:angle () (* 2.0 (atan (norm a) s)))
 (:axis () (normalize-vector a))
 (:concat (q)
    (declare (quaternion q))
    (let ((s2 (quaternion-s q)) (a2 (quaternion-a q)))
        (send self :newquat %(s * s2 - v.(a a2))
			 (v+ (v+ (scale s a2) (scale s2 a))
			     (v* a a2) ))))
 (:prin1 (strm)
    (format strm "#<~A axis=~s angle=~s>" (metaclass-name (class self))
					  (send self :axis) (send self :angle)))
 )		

(defun q* (q1 q2)
   (declare (quaternion q1 q2))
   (let ((s1 (quaternion-s q1)) (s2 (quaternion-s q2))
	 (a1 (quaternion-a q1)) (a2 (quaternion-a q2)))
     (instance quaternion :newquat %(s1 * s2 - v.(a1 a2))
				(v+  (v+ (scale s1 a2)
					 (scale s2 a1))
				     (v* a1 a2)))))