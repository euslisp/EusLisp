(eval-when (compile)
	   (load "/usr/local/eus/llib/geoclasses.l")
	   )
;;(defun !sin (x) (sin (deg2rad x)))
;;(defun !cos (x) (cos (deg2rad x)))
;;(defun !atan (x) (* 180 (/ (atan x) pi)))
(defun fzerop (a) (< (abs a) 0.9999990e-05))
;;(defun !atan2 (y x) (rad2deg (atan y x)))
#|
(defun matrix-row (mat row)
   ; extract a row vector from a matrix
   (when (eq (array-rank mat) 2)
	 (subseq (mat . entity) (* (mat . dim1) row) (* (mat . dim1) (1+ row)))))

(defun scale-matrix (s m &optional m1)
  (cond
   (m1 (scale s (m . entity) (m1 . entity))  m1)
   (t (setq m1 (copy-matrix m))
      (scale s (m1 . entity) (m1 . entity)) m1)))
|#
(defun dump-variables
  (file &rest objects)
  (let
      ((*print-structure* t)
       (*print-circle* t))
    (with-open-file
     (f file :direction :output)
     (dolist
      (v objects)
      (format f "(setq ~a ~%" v)
      (pprint (symbol-value v) f)
      (format f ")~%"))
     )))			   

(defmethod viewer
  (:draw-one
   (thing info)
   (cond
    ((derivedp thing edge) (send self :draw-edge thing))
    ((derivedp thing edge-image)  (send self :draw-edge-image thing))
    ((derivedp thing body) (send self :draw-body thing t))
    ((derivedp thing face) (send self :draw-faces (list thing)))
    ((derivedp thing 2dlnseg) (send self :draw-2dlnseg thing))
    ((float-vector-p thing) (send self :draw-star thing) info)
    ((coordinates-p thing) (send self :draw-axis thing info))))
  (:draw
   (thing &optional info)
   (cond
    ((listp thing) (dolist (x thing)  (send self :draw-one x info)))
    (t (send self :draw-one thing info)))
   (send surface :flush)
   t)
  (:draw-2dlnseg
   (l)
   (send self :draw-line-ndc
	 (float-vector
	  (elt (send l :spos) 0)
	  (elt (send l :spos) 1) 0)
	 (float-vector
	  (elt (send l :epos) 0)
	  (elt (send l :epos) 1) 0)
	 )
   )
  )

(defmethod viewing
  (:lookaround (v th)
	       (send self :translate (v- v) 'local 'local)
	       (send self :rotate-locally th :y)
	       (send self :translate v 'local 'local))
  )

(defmethod parallel-viewing
  (:view-line   (&optional (v #f(0 0)))
   (instance 3dline :init
	     (send self :view-orient v)
	     (v+ (send self :viewpoint)
		 (transform rot
			    (float-vector (* (aref v 0) screenx)
					  (* (aref v 1) screeny)
					  0)))))
  (:view-orient
   (&optional (v #f(0 0)))
   (send self :view-direction))
  )

(defmethod perspective-viewing
  (:view-orient   (&optional (v #f(0 0)))
    (declare (float-vector v))
    (transform rot
	       (normalize-vector
	        (float-vector (/ (* (aref v 0) screenx)
			       viewdistance)
			     (/ (* (aref v 1) screeny)
			       viewdistance)
			     1))))
  (:view-line   (&optional (v #f(0 0)))
   (instance 3dline :init
	     (send self :view-orient v)
	     (send self :viewpoint)))
  )
;;;
;;; Coded by M.Inaba1988.12.19
;;;
(defmethod coordinates
  (:new-world-coords
   (r p)
   (send self :newcoords r p)
   )
;;;
;;; Translate self
;;;
  (:displacement-vector
   (v wrt)
   (cond ((eq wrt 'local) (transform (send self :worldrot) v))
	 ((memq wrt '(world parent)) v)
	 ((coordinates-p wrt)
	  (transform (send wrt :worldrot) v))
	 (t (send self :error ":displacement-vector wrt?" wrt))))
  (:move-to
   (v &optional (to 'local))	;; v must be displacement
   (cond
    ((eq to 'local)
     (send self :new-world-coords
	   (send self :worldrot) (v+ (send self :worldpos) v)))
    ((memq to '(world parent))
     (send self :new-world-coords
	   (send self :worldrot) v))
    ((coordinates-p to)
     (send self :new-world-coords
	   (send self :worldrot) (v+ v (send to :worldpos))))
    (t (send self :error ":move-to to?" to))))
  (:move-with-vector
   (v &optional (wrt 'local) (to 'local))
   (send self :move-to (send self :displacement-vector v wrt) to))
;;;
;;; Rotate self
;;;
  (:displacement-rotation
   (r &optional (wrt 'local))
   (if (eq wrt 'local) (setq wrt self))
   (cond
    ((memq wrt '(world parent)) r)
    ((coordinates-p wrt)
     (let* ((w (send wrt :worldrot))
	    (wi (transpose w)))
       (m* r wi wi)
       (m* w wi wi)))
    (t (send self :error ":displacement-rotation wrt?" wrt))))
  (:rotate-to
   (r &optional (to 'local))
   (cond
    ((eq to 'local)
     (send self :new-world-coords
	   (m* r (send self :worldrot))
	   (send self :worldpos)))
    ((memq to '(world parent))
     (send self :new-world-coords
	   (m* r (send self :worldrot))
	   (transform r (send self :worldpos))))
    ((coordinates-p to)
     (let ((tp (send to :worldpos)))
       (send self :new-world-coords
	     (m* r (send self :worldrot))
	     (v+ tp
		 (transform r (v- (send self :worldpos) tp))))))
    (t (send self :error ":rotate-to to?" to))))
  (:rotate-with-rotation
   (r &optional (wrt 'local) (to 'local))
   (send self :rotate-to (send self :displacement-rotation r wrt) to))
  (:rotate-with-theta-axis
   (theta &optional (axis :z) wrt to)
   ;;wrt=coordinates, rotate in wrt coordinates (slower than local or world)
   (send self :rotate-with-rotation
	 (if (float-vector-p axis)
	     (rotation-matrix theta axis)
	   (let ((r (unit-matrix 3)))
	     (rotate-matrix r theta axis t r)))
	 wrt to))
)

(defmethod cascaded-coords
  (:new-world-coords
   (r p)
   (cond
    (parent
     (let ((pwi (send parent :inverse-transformation)))
       (v+ (pwi . pos) (transform (pwi . rot) p) (pwi . pos))
       (send self :newcoords
	     (m* (pwi . rot) r (pwi . rot))
	     (pwi . pos))))
    (t (send self :newcoords r p))))
  )
