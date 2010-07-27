;;;;
;;;; render.l
;;;; surface rendering of bodies
;;;; (c)1990 Aug, MATSUI Toshihiro, Electrotechnical Laboratory
;;;;
;;;	1. make a xwindow viewer on eusx
;;;	  (setq *viewer* (view))	; or, simply (load "view")
;;;	2. create a colormap and store colors that have continuous brightness
;;;	  (init-colormap)
;;;	   An instance of colormap is created in *colormap*.
;;;	   To change the colormap entries, 
;;;	   (send *colormap* :store-hls-group 0 32 40 0.3 0.7 0.4)
	   ; refer to Xeus.l
;;;       
;;;	3. make bodies 
;;;	(setq a (make-cube 500 400 300)) (send a :locate #f(100 100 -100))
;;;	(setq b (make-cylinder 100 200)) (send b :locate #f(-200 -100 0))
;;;	run renderer!
;;;	(render *viewer* a b)

;(unless (find-package "X") (make-package "X"))
;(eval-when (load eval)
;   (unless (boundp 'x:disp)
;       (error "First, connect to Xserver"))  )
(list "@(#)$Id: render.l,v 1.1.1.1 2003/11/20 07:46:29 eus Exp $")

(defvar *render-colormap* nil)
(defvar *render-brightness-levels* 16)

(defclass scan-face :super propertied-object
		:slots (face3d vertices edges color))
(defclass scan-edge :super propertied-object
		:slots (edge3d nvert pvert))
(defclass scan-vertex :super propertied-object
		:slots (vert3d ndcv))
(defclass scan-body :super propertied-object)

(defmethod scan-face 
 (:vertices () vertices)
 (:edges () edges)
 (:color () color)
 (:face () face3d)
 )

(defmethod scan-vertex
 (:depth () (aref ndcv 2))
 (:height () (aref ndcv 1))
 (:ndcv () ndcv) )

(defmethod scan-edge
 (:set-vertices (pv nv) (setq pvert pv nvert nv))
 (:scan-line-intersection (vx)
    (let ((vp (send pvert :height)) (vn (send nvert :height)))
      (declare (float vp vn))
      (if (or (<  vp vx vn) (< vn vx vp))
	  (let ((p %((vx - vn) / (vp - vn))))
	     (declare (float p))
	     (v+  (scale p (send pvert :ndcv))
		  (scale (- 1.0 p) (send nvert :ndcv))))
	) ))
 )

(defun make-scan-faces (faces3d view)
   (let ((vhash (make-hash-table :test #'eq :hash #'sys:address))
	 (ehash (make-hash-table :test #'eq :hash #'sys:address))
	 (scan-faces) )
   (dolist (face3 faces3d)
      (let ((vlist nil) (elist nil) (se))
	(dolist (v (send face3 :all-vertices))
	   (if (null (gethash v vhash))
	       (setf (gethash v vhash)
		     (make-instance scan-vertex :vert3d v
				:ndcv (homo2normal (send view :view v)))) )
	   (push (gethash v vhash) vlist)) 
	(dolist (e (send face3 :all-edges))
	   (if (null (gethash e ehash))
	       (setf (gethash e ehash)
		     (make-instance scan-edge :edge3d e	 )))
	   (setq se (gethash e ehash))
	   (send se :set-vertices (gethash (edge-pvert e) vhash)
				  (gethash (edge-nvert e) vhash))
	   (push se elist))
	(push (make-instance scan-face :face3d face3
			:edges elist  :vertices vlist)
	      scan-faces)
        ) )
   (nreverse  scan-faces))) 



(defclass light-source
		:super cascaded-coords
		:slots (type intensity colors
			illuminated-faces
			obscuring-face))

(defmethod light-source
 (:intensity (&optional new)
    (if new (setq intensity (float new)) intensity))
 (:magnify-intensity (m) 
    (setq intensity (* m intensity)))
 (:default-intensity ()
    (setq intensity
	  (/ (v. (send self :worldpos)  (send self :worldpos)) 3.0)))
 (:add-illuminated-face (new)
    (if (send new :visible (send self :worldpos))
	(push new illuminated-faces)))
 (:set-illuminated-faces (faces)
    (setq illuminated-faces nil  obscuring-face nil)
    (let ((p (send self :worldpos)))
       (dolist (f faces)
          (let ((d (send f :distance p)))
	     (if (>= d 0.0) (push (list d f) illuminated-faces))))
       (setq illuminated-faces
	     (mapcar #'cadr (sort illuminated-faces #'>= #'car)))))
 (:illuminated-faces () illuminated-faces)
 (:illuminated-face-p (f) (member f illuminated-faces))
 (:illuminance (point &aux (dist (distance point (send self :worldpos))))
	(/ intensity dist dist))
 (:illuminated-p (point the-face)
   "is point obscured by faces?"
   (let ((faces (member the-face illuminated-faces)) L)
      (cond (faces
	     (setq L (send self :worldpos))
	     (if (and obscuring-face
	              (null (eq the-face obscuring-face))
		      (send obscuring-face :intersect-line point L))
	         (return-from :illuminated-p nil))
             (dolist (f (cdr faces))
	        (when (send f :intersect-line point L)
	            (setq obscuring-face f)
	            (return-from :illuminated-p nil)))
	     (setq obscuring-face nil)
             t)
	    (t nil))) )
 (:init (&rest args &key ((:intensity it) nil) &allow-other-keys)
    (send-super-lexpr :init args)
    (if it (setq intensity (float it)) (send self :default-intensity))
    self))

(defun make-light-source (pos &optional (intensity) &aux alight)
   (setq alight (instance light-source :init :pos pos))
   (if  intensity 
	(send alight :magnify-intensity intensity))
   alight)

(defvar *light-sources*
	(list (make-light-source #f(1000 2000 3000) 2.0)))


(defun reflection-ray (normal light)
     (normalize-vector
	(v-  (scale (* 2.0 (v. normal light)) normal)
		light) )) 

(defvar *render-shadow* t)

(defun ray-intersection (normal distance point vnorm)
    (let ((dnm (v. normal vnorm)) p)
      (declare (float dnm p))
      (cond ((< (abs dnm) *parallel-threshold*) :parallel)
            (t (setq p (/ (- 0.0 (v. normal point) distance) dnm))
               (if (< p 0.0)
		   :outside
                   (v+ point (scale p vnorm)) )))))

(defun render-raster (raster vwr lights colormap)
   (let* (v face3 color-lut
	  (view (send vwr :viewing))
	  (vp (send view :viewpoint))
	  (xinc (/ 2.0 (send vwr :viewsurface :width)))
	  x xend y point
	  (lighting #f(0 0 0))
	  (normal) 
	  (normal-lighting #f(0 0 0))
	  (normal-view #f(0 0 0))
	  (pixel #f(0 0 0))
	  ray bodycolor brightness diffusal-reflectance 
	  income ambient diffusion reflectance reflection)
     (declare (float xinc  x xend y
		  brightness income ambient diffusion reflection reflectance)
	      (float-vector v vp lighting point pixel
			    normal normal-lighting normal-view ray) )
     (unless lights (setq lights *light-sources*))
     (dolist (r raster)
	(setq face3 (send (car r) :face))
	(setq color-lut (send colormap :lut (send face3 :color))
	      reflectance (send face3 :reflectance)
	      diffusal-reflectance (send face3 :diffusion)
	      normal (send face3 :normal))
        (setq v (second r))
	(setq x (aref v 0)
	      y (aref v 1)
	      xend (aref (third r) 0))
	(setf (aref pixel 1) y
	      (aref pixel 2) (aref v 2))
	(while (< x xend)
	   (setq ray (send view :ray x y))
	   (setq point
		 (ray-intersection normal (face-distance face3) vp ray))
	   (when (float-vector-p point)
	      (v- vp point normal-view)
	      (setq brightness (* 0.1 reflectance))	;ambient
	      (normalize-vector normal-view normal-view)
	      (dolist (light lights)
		(when (or (null *render-shadow*)
			  (send light :illuminated-p point face3))
		   (v- (send light :worldpos) point lighting)
		   (normalize-vector lighting normal-lighting)
	           (setq income (/ (send light :intensity)
				   (v. lighting lighting)) )
		   (setq diffusion
		         (max 0.0 (* (v. normal normal-lighting)
			             income diffusal-reflectance) ))
		   (setq reflection
		         (v. (reflection-ray normal lighting) normal-view))
		   (setq reflection
		         (if (> reflection 0.0)
		             (* income reflectance
			        reflection reflection reflection reflection )
			     0.0))
		   (incf brightness (+ reflection diffusion)) ) )
	      (setq brightness
		    (min (1- *render-brightness-levels*)
			 (max 0 (round 
				  (* brightness
				     *render-brightness-levels*)) )))
	      (setf (aref pixel 0) x)
	      (send vwr :draw-point-ndc pixel (aref color-lut brightness)))
	   (incf x xinc)) )
     (send vwr :flush)))


(defun quick-render-raster (raster vwr)
   (let ((color) v1 v2)
     (dolist (r raster)
       (setq color (send  (pop r) :color))
       (send vwr :viewsurface :color (send *render-colormap* :pixel color))
       (setq v1 (pop r) v2 (pop r))
       (send vwr :draw-line-ndc v1 v2)) 
       )
     (send vwr :flush)))

(defvar *nan*  0.0)
(setq *nan* (/ *nan* 0.0))

(defun segment-entered (point segments)
   (find point segments :key #'second))

(defun depth-at-x (x segment)
   (let* ((v1 (second segment)) (v2 (third segment))
	  (v1x (aref v1 0)) (v2x (aref v2 0))
	  (p %((x - v2x) / (v1x - v2x)))
	  (z %(p * v1[2] + (1.0 - p)* v2[2])))
     (declare (float v1x v2x p))
     (if (equal z *nan*)	;; trick: eq cannot be used.
	 (aref v1 2)
	 z)) )

(defun point-closer (point nextpoint segment1 segment2)
   (let ((x %((point[0] + nextpoint[0])/ 2.0)))
      %(depth-at-x(x segment1) < depth-at-x(x segment2))) )
     
(defun point-at-x (x segment)
   (float-vector x (aref (second segment) 1) (depth-at-x x segment)))

(defun order-segments (scan-segments)
   (let ((points) (vsegments) (visible) (entering)
	 (end-point) (end-visible) (newpoint) (p))
     (setq vsegments
	   (sort (copy-seq scan-segments)
		 #'<= 
		 #'(lambda (x) (aref (second x) 0))))
     (setq points
	   (sort (mapcan #'(lambda (x) (list (second x) (third x)))
			 vsegments)
		 #'<= #'(lambda (x) (aref x 0))))
     (while points
	(setq p (car points))
	(cond ((null visible)
		(setq visible (segment-entered p vsegments))
		(if (null visible) (error "no visible?")))
	      ((setq entering (segment-entered p vsegments))
		(setq end-visible (third visible))
		(setq end-point (third entering))
		(cond ((point-closer p (cadr points) entering visible)
			(cond (%(end-visible[0] <= end-point[0])
			       (setf (third visible)
				     (point-at-x (aref p 0) visible))
			       (setq end-visible 
				       (delete end-visible points :count 1))
				;(format t "ok~%")
				)
			      (t
			       (setf (third visible)
				     (point-at-x (aref p 0) visible))
			       (setq newpoint
				     (point-at-x (aref end-point 0) visible))
			       (push (list (car visible) newpoint end-visible)
				     vsegments)
			       (list-insert newpoint
					    (1+ (position end-point points))
					    points))	      )
			(setq visible entering))
		      (%(end-point[0] <= end-visible[0])
			(delete end-point points :count 1)
			(setq vsegments (delete entering vsegments :count 1)))
		      (t
			(setq newpoint
			      (point-at-x (aref end-visible 0) entering))
			(setf (second entering) newpoint)
			(list-insert newpoint
				     (1+ (position end-visible points))
				     points) ) )  )
	      ((eq (third visible) p) (setq visible nil))
	      (t (warn "exiting segment?  ~a" p)))
	(setq points (cdr points)))
    vsegments)   )

;;
;; set hls colors in *render-colormap*
;;
(defun init-colormap (&optional (cm x:*color-map*))
   (setq *render-colormap* cm)
   (send *render-colormap* :define-hls-lut
	 'red
	 *render-brightness-levels*
	 0		; color-degree  0--360
	 0.3 0.9	; brightness 0.0 -- 1.0
	 0.5)		; saturation
   (send *render-colormap* :define-hls-lut
	 'red-yellow
	 *render-brightness-levels*
	 30
	 0.2 0.9
	 0.7)
   (send *render-colormap* :define-hls-lut
	 'yellow
	 *render-brightness-levels*
	 70
	 0.3 0.9
	 0.5)
   (send *render-colormap* :define-hls-lut
	 'yellow2
	 *render-brightness-levels*
	 100
	 0.3 0.9
	 0.6)
   (send *render-colormap* :define-hls-lut
	 'green
	 *render-brightness-levels*
	 135
	 0.2 0.9
	 0.7)
   (send *render-colormap* :define-hls-lut
	 'blue
	 *render-brightness-levels*
	 230
	 0.3 0.8
	 0.5)
   (send *render-colormap* :define-hls-lut
	 'gray
	 *render-brightness-levels*
	 230
	 0.2 0.9
	 0.01)
   (send *render-colormap* :define-hls-lut
	 'violet
	 *render-brightness-levels*
	 340
	 0.2 0.9
	 0.3)
 )

;;

(defun clip-segments (segments)
   (while (< (aref (third (first segments)) 0) -1.0) (pop segments))
   (when segments 
      (if (< (aref (second (first segments)) 0) -1.0)
	  (setf (aref (second (first segments)) 0) -1.0))
      (setq segments (nreverse segments))
      (while (> (aref (second (first segments)) 0) 1.0)  (pop segments))
      (when segments 
	 (if (> (aref (third (first segments)) 0) 1.0)
	     (setf (aref (third (first segments)) 0) 1.0)))
      (nreverse segments)))

(defvar *quick-render* nil)

(defun render2 (vwr faces lights colormap &optional (y 1.0))
   (declare (float y))	;1.0 .. -1.0 in NDC
   (let* ((size (send vwr :viewsurface :size))
	  (xsize (elt size 0))  (ysize (elt size 1))
	  (xinc (/ 2.0 xsize))  (yinc (/ 2.0 ysize))
	  (view (send vwr :viewing))
	  (viewpoint (send view :viewpoint))
	  (visible-faces)
	  (scan-faces)
	  (segments) )
      (declare (float xsize ysize xinc yinc))
;
      (dolist (f faces)
	(when (send f :visible viewpoint)  (push f visible-faces)))
      (setq scan-faces (make-scan-faces visible-faces view)) 
      (dolist (l lights)
	(send l :set-illuminated-faces faces))
      (dotimes (j ysize)
	 (setq segments nil)
	 (dolist (s scan-faces)
	   (let (ints int)
	    (dolist (he (send s :edges))
	       (setq int (send he :scan-line-intersection y))
	       (when int (push int ints)) )
	    (when ints
		(setq ints  (sort ints #'<= #'(lambda (x) (aref x 0))))
		(while ints
		   (push (list s (pop ints) (pop ints)) segments)) )
	    )) ; all faces scanned
         (when segments 
	    (setq segments (order-segments segments))
	    (setq segments (clip-segments segments))
	    (render-raster segments  vwr lights colormap) )
	 (decf y yinc)
	 ;(print j)
	)
  ))

(defun render (	&key (bodies)
		     (faces)
		     (lights *light-sources*)
		     ((:viewer vw) *viewer*)
		     (colormap *render-colormap*)
		     (y 1.0))
     (dolist (b bodies)
	(unless (send b :color)
	    (warn "no color is set to ~a... defaulted to 'red~%" b)
	    (send b :color 'red))	;default color
	 (setq faces (append (send b :faces) faces)))
     (render2 vw faces lights colormap (float y))))

(provide :render)
