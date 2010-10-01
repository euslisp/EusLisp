;****************************************************************
;* class  V I E W I N G  &  P R O J E C T I O N
;;	Copyright (1988) Toshihiro MATSUI
;;
;*   VIEWING defines the viewing-coordinates whose origin is at
;*   "viewpoint" and looking to (w-axis is oriented to) "target".
;*   PROJECTION performs projective mapping.
;*   cascoords <-- viewing <-- projection <-+- parallel-viewing
;*                 		            +- perspective-viewing
;*                 		            +- viewing2d
;*	May/1996	merging with draw in OpenGL
;;
;****************************************************************

(in-package "GEOMETRY")
;; nothing to export except classes

(eval-when (compile)  (load "geoclasses.l"))

(defmethod viewing
  (:update ()
    ;; worldcoords has been already computed here
    ;; make inverse in viewcoords
    (send-super :update)
    (transpose (coordinates-rot worldcoords) (coordinates-rot viewcoords))
    (when (= (length pos) 3)
       (m* #2f((1.0 0.0 0.0) (0.0 1.0 0.0) (0.0 0.0 -1.0))
	   (coordinates-rot viewcoords)
	   (coordinates-rot viewcoords)))
    (scale -1.0 
	   (transform (coordinates-rot viewcoords) (coordinates-pos worldcoords))
	   (coordinates-pos viewcoords)) 
    viewcoords    )
 (:changed ()
    (send-super :changed)
    (send self :worldcoords))
  )

(defmethod viewing
  (:viewpoint () (send self :worldpos))
  (:view-direction  ()  (matrix-row (coordinates-rot viewcoords) 2))
  (:view-up  () (matrix-row (coordinates-rot viewcoords) 1))
  (:view-right  () (matrix-row (coordinates-rot viewcoords) 0))
  (:sendviewcoords () 
    (error ":sendviewcoords -- subclass'es responsibility")   )
  (:look   (from &optional (to #f(0 0 0)))
   ; Make viewing coordinates whose origin is at 'from' and -z-axis
   ; is pointing to 'to', and x-axis is parallel to world's xy-plane.
   (setq to (v- from to))
   (send-super :init)
;   (setf (aref rot 2 2) -1.0)
   (send self :rotate
	 (- (atan
	  (elt to 2)
	  (sqrt (+ (* (elt to 0) (elt to 0))
		   (* (elt to 1) (elt to 1))))  ))
	 :x :world)
   (send self :rotate   (- (+ (atan (elt to 0) (elt to 1))  pi))  :y :world)
   (send self :rotate   (- (/ (- pi) 2)) :x :world)
   (send-super :locate  from :world)
   self)
  (:makeviewcoords   (ax ay az p)
     (send-super :reset-coords)
;     (setf (aref rot 2 2) -1.0)
     (send self :rotate pi/2 :x :world)
     (send self :rotate pi/2 :z :world)
     (send self :rotate ax :x :world)
     (send self :rotate ay :y :world)
     (send self :rotate az :z :world)
     (send self :locate p :world))
  (:init (&rest viewargs
	  &key	(dimension 3)
		(target nil)
		(view-direction nil)
		(view-up (float-vector 0.0 0.0 1.0))
		(view-right nil)
		&allow-other-keys)
    (send-super* :init viewargs)
    (setf viewcoords (coords :dimension dimension))
    (when (or target view-direction)
	(if (null view-direction)
	    (setq view-direction (v- target pos)))
	(setq view-direction (normalize-vector view-direction))
	(unless view-right
	    (setq view-right (v* view-direction view-up)))
	(setq view-right (normalize-vector view-right))
	(setq view-up (normalize-vector (v* view-right view-direction)))
	(setq view-direction (scale -1.0 view-direction))
	(setf (array-entity rot)
	     (concatenate float-vector view-right view-up view-direction))
	(transpose rot rot) )
    (send self :worldcoords)
    self)
 )

;;;
(defmethod projection
  (:projection ()  projection-matrix)
  (:newprojection (pmat) (setq projection-matrix pmat))
  (:project  (vec) (transform projection-matrix vec))
  (:project3 (vec3)
    (transform projection-matrix
		;; (replace (float-vector 0 0 0 1) vec3)
		(homogenize vec3)))
  (:view   (point)
    (send self :project3 (send viewcoords :transform-vector point)))
  (:screen   (&optional (sx nil) (sy sx))
    (when sx (setq screenx sx screeny sy) (send self :make-projection))
    (list screenx screeny))
  (:hither   (&optional (h nil))
   (when h (setq hither (float h))
	 (send self :make-projection))
   hither)
  (:yon   (&optional (y nil))
   (when y (setq yon (float y))
	 (send self :make-projection))
   yon)
  (:aspect (&optional (rate nil))
	   (when rate  (setq screeny (* screenx rate))
		 (send self :make-projection))
	   (/ screeny screenx))
  (:viewreference () (float-vector 0 0 (/ (+ hither yon) 2.0)))
  (:make-projection   (&rest args)
   (error ":make-projection   subclass's responsibility"))
  (:init (&rest  viewing-params
	  &key   ((:hither h) 100.0)
		 ((:yon y) 10000.0)
  		 (aspect 1.0)
		 (screen 100.0)
		 (screen-x screen)
		 (screen-y (* aspect screen-x))
		 &allow-other-keys)
	 (setf hither   (float h)
	       yon      (float y)
	       screenx  (float screen-x)
	       screeny  (float screen-y))
	 (send-super* :init viewing-params)
	 (send self :make-projection)
	 self))

;;;;

(defmethod viewing2d
  (:project  (vec) (transform projection-matrix vec))
  (:project2 (vec3)
    (homogenize (transform projection-matrix vec3)))
  (:view   (point)
    (send self :project2 (send viewcoords :transform-vector point)))
 (:make-projection ()
    (setq projection-matrix (make-matrix 2 2))
    (setf (aref projection-matrix 0 0) (/ 2.0 screenx)
	  (aref projection-matrix 1 1) (/ 2.0 screeny))
    projection-matrix)
 (:init (&rest initargs
	 &key  (screen 1.0)
	       (screen-x screen)
	       (screen-y screen-x)
	       &allow-other-keys)
    (send-super* :init :dimension 2 initargs)
    (setq screenx screen-x
	  screeny screen-y)
    (send self :make-projection)
    self))

;;;
(defmethod parallel-viewing
  (:make-projection ()
    (setf projection-matrix (make-matrix 4 4))
    (setf (aref projection-matrix 0 0) (/ 1.0 screenx) )
    (setf (aref projection-matrix 1 1) (/ 1.0 screeny))
    (setf (aref projection-matrix 2 2) (/ 1.0 (- yon hither)))
#|
    (setf (aref projection-matrix 0 3) 0.50)
    (setf (aref projection-matrix 1 3) 0.50)
|#
    (setf (aref projection-matrix 2 3) (- (/ hither (- yon hither))))
    (setf (aref projection-matrix 3 3) 1.0)
    self)
 )

;;;

(defmethod perspective-viewing
  (:ray (u v)	; u,v are normalized: -1<u<1, -1<v<1
     "returns direction vector pointing (u,v) in NDC from the viewpoint"
     (declare (float u v))
     (normalize-vector
	(send self :rotate-vector
		(float-vector (* screenx u) (* screeny v)  (- viewdistance)))))
  (:view-plane (&optional (offset 0.0))
"+offset makes the viewplane closer to the viewpoint,
-offset takes further distance."
      (make-plane :normal (send self :view-direction)
		  :point (send self :transform-vector
				 (float-vector 0.0 0.0
					(- offset viewdistance)))) )
  (:make-projection   ()
   (let*
       ((f (/ (* (- (* 2.0 hither) viewdistance) viewdistance) hither))
	(b (/ (* (- (* 2.0 yon) viewdistance) viewdistance) yon))
	(depth (- b f))
	(p1 nil)
	(p2 nil))
     (setq p1 (unit-matrix 4))
     (setf (aref p1 2 2) 2.0)
     (setf (aref p1 3 2) (/ 1.0 viewdistance))
     (setf (aref p1 2 3) (- viewdistance))
     (setf (aref p1 3 3) 0.0)
     ;
     (setq p2 (make-matrix 4 4))
     (setf (aref p2 0 0) (/ 1.0 screenx))
     (setf (aref p2 1 1) (/ 1.0 screeny))
     (setf (aref p2 2 2) (/ 1.0 depth))
     (setf (aref p2 2 3) (/ (- f) depth))
     (setf (aref p2 3 3) 1.0)
     ;      (format t ":make-projection~% p1=~S~%p2=~S~%" p1 p2)
     (m* p2 p1 projection-matrix)))
  (:viewdistance (&optional (vd nil))
	(when vd
	       (setq viewdistance (float vd))
	       (send self :make-projection))
	viewdistance)
 (:view-angle (&optional ang)
   (if ang
       (let ((aspect (/ screeny screenx))
	     (diag (* viewdistance (tan (/ ang 2.0))))
	     sx)
	  (setq sx %(sqrt(diag * diag /  (1.0 + aspect * aspect))))
	  (send self :screen sx (* sx aspect)) 
	  (send self :make-projection)
	  ang)
       (* 2 (atan %(sqrt(screenx * screenx + screeny * screeny))
		viewdistance) ) ))
 (:fovy ()
     (* 2 (atan screeny	viewdistance) ))
  (:zoom (&optional (s nil))
     (when s
	 (setq screenx (/ screenx s) screeny (/ screeny s))
	 (send self :make-projection))
     (send self :view-angle))
  (:lookaround (alfa beta)
     (let* ((v (float-vector 0 0 (/ (+ yon hither) 2.0))))
	 (send self :locate (v- v) :local)
	 (send self :rotate alfa :z :world)
	 (send self :rotate beta :x :local)
	 (send self :locate v :local ))
	 )
 (:look-body (&rest bodies)
    (setq bodies (flatten bodies))
    (let* ((box (bounding-box-union bodies))
	   v1 v2 ang)
      (send box :grow 0.1)
      (send self :look (send self :viewpoint)  (send box :center))
      (setq box (instance bounding-box :init
	           (mapcar #'(lambda (x) (send viewcoords :transform-vector x))
			   (send box :corners))
		   ))
      (setq v1 (normalize-vector (send box :minpoint))
	    v2 (normalize-vector (send box :maxpoint)))
      (setq ang (acos (v. v1 v2)))
      (send self :hither
	(* 0.5 (aref (send box :extream-point #f(0 0 -1)) 2)))
      (send self :yon
	 (* 2.0 (aref (send box :extream-point #f(0 0 1)) 2)))
      (send self :view-angle ang)
      self))
 (:look-body2 (&rest bodies)
    (setq bodies (flatten bodies))
    (let* ((box (send  (bounding-box-union bodies) :grow 0.1))
	   (diagonal (distance (box . maxpoint) (box . minpoint)))
	   (view-reference (send box :center))
	   (view-dist (distance (send self :viewpoint) view-reference)) 
	   v1 v2 ang)
      (send self :look (send self :viewpoint)  view-reference)
      (setq ang (* 2.0 (atan (/ diagonal 2.0) view-dist   )) )
      (print (list diagonal view-dist ang))
      (send self :hither
	(* 0.5 (aref (send box :extream-point #f(0 0 -1)) 2)))
      (send self :yon
	 (* 2.0 (aref (send box :extream-point #f(0 0 1)) 2)))
      (send self :view-angle ang)
      self))
  (:prin1 (strm &optional msg)
     (send-super :prin1 strm 
	(format nil "~fdeg" (lisp::rad2deg (send self :view-angle)))
	msg) )
  (:init (&rest params
		&key ((:viewdistance vd))
		&allow-other-keys)
     (if vd
	 (setq viewdistance (float vd))
	 (unless viewdistance (setq viewdistance 100.0)))
     (unless projection-matrix (setq projection-matrix (unit-matrix 4)))
     (send-super* :init params)
     self))

;; UTYO local
(defmethod perspective-viewing
  (:view-orient   (&optional (v (float-vector 0 0))) ;;;mer
   (declare (float-vector v))
   (transform (transpose (viewcoords . rot))
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

#| stereo viewing is not well-defined yet

(defmethod stereo-viewing
  (:rightview () rightview)
  (:leftview () leftview)
  (:viewpoint (&optional (vp nil))
	      (cond (vp (send self :init nil vp offset target)))
	      viewpoint)
  (:offset (&optional (off nil))
	   (cond (off (send self :init nil viewpoint off target)))
	   offset)
  (:target (&optional (tgt nil))
	   (cond (tgt (send self :init nil viewpoint offset tgt)))
	   target)
  (:nomethod (&rest mesg) 
	     (list (resend rightview mesg) (resend leftview mesg)))
  (:init (cls vp off tgt)
	 (setq viewpoint vp
	       offset off 
	       target tgt)
	 (let ((viewline (v- target viewpoint)) (theta 0) (dx 0) (dy 0)
	       (rvp nil) (lvp nil)
	       (vpx (elt viewpoint 0))
	       (vpy (elt viewpoint 1))
	       (vpz (elt viewpoint 2)))
	   (setq theta (atan (- (elt viewline 0)) (elt viewline 1)))
	   (setq dx (* offset (cos theta)))
	   (setq dy (* offset (sin theta)))
	   (setq rvp (float-vector (+ vpx dx) (+ vpy dy) vpz))
	   (setq lvp (float-vector (- vpx dx) (- vpy dy) vpz))
	   (cond (cls
		  (setq rightview (instantiate cls))
		  (send rightview :init rvp target)
		  (setq leftview (instantiate cls ))
		  (send leftview :init lvp target))
		 (t (send rightview :look rvp target)
		    (send leftview :look lvp target)))
	   self)))
|#

(provide :viewing "@(#)$Id: viewing.l,v 1.1.1.1 2003/11/20 07:46:30 eus Exp $")
