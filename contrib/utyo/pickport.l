;;;
;;;	pick-port classes
;;;		model-pick-port
;;;		image-pick-port
;;;			1988.10.29	M.Inaba & M.Fujii
;;;
;;;
(eval-when
 (compile eval)
 (load "/usr/local/eus/llib/geoclasses.l")
 )
;;;
(defun 2dvector-to-3dvector (v)
  (float-vector (vector-x v) (vector-y v) 0))
(defmethod edge-image
  (:draw (vp)
    (let ((p1 (car segments)) hp1 hp2 line)
       (dolist (p2 (cdr segments))
	  (when (= (caddr p1) 0)
	      (setq hp1 (send self :projected-homo-point (cadr p1))
		    hp2 (send self :projected-homo-point (cadr p2)))
	      (setq line (homo-viewport-clip hp1 hp2))
	;  (print line)
	    (if line
	        (send vp :draw
		      (homo2normal (car line))
		      (homo2normal (cadr line))
		      )
	      ))
	  (setq p1 p2))) ) 
  (:2dlnsegs
   ()
   (let* ((segments (send self :visible-segments))
	  result)
     (dolist (s segments result)
	     (setq result
		   (cons
		    (instance
		     2dlnseg :init :spos
		     (homo2normal (car s))
		     :epos
		     (homo2normal (cadr s)))
		    result)))
     ))
  )
(defmethod edge
  (:project
   (p)
   (let ((l (instance 3dline :init (v- nvert pvert))))
     (send l :project-3dvector p)))
  (:distance
   (p)
   (let* ((pp (send self :project p))
	  (par (send self :parameter pp))
	  )
     (cond
      ((> par 1) (distance nvert p))
      ((< par 0) (distance pvert p))
      (t (distance pp p))))
   )
  )
(defmethod face
  (:crossp-with-3dline
   (l)
   (let ((p (send self :cross-with-3dline l)))
     (if (eq 'inside (send self :insidep p)) p)))
  (:nearest-edge-from-3dline
   (l)
   (send self :nearest-edge-from-3dvector
	 (send self :cross-with-3dline l)))
  (:nearest-edge-from-3dvector
   (p)
   (let* ((edges (send self :edges))
	  (mine (car edges))
	  (mind (send mine :distance p))
	  d)
     (dolist
      (e (cdr edges))
      (setq d (send e :distance p))
      (when (< d mind)
	    (setq mind d mine e)))
     mine)
   )
  )
;;;
(defmethod viewer
  (:pick-vector
   (pos &optional (ori (float-vector 1 0 0))
	(3dpos (float-vector 0 0 0)))
   (let*
       ((p3 (2dvector-to-3dvector pos))
	(p (send self :viewport :screen-point-to-ndc p3))
	(vline (send self :viewing :view-line p))
	(cplane (instance plane :init ori 3dpos)))
     (send cplane :cross-with-3dline vline)))
  (:clear () (send surface :clear))
  (:flush () (send surface :flush))
  (:draw-box-cursor
   (v &optional (base (instance coordinates :init
				(unit-matrix 3) (float-vector 0 0 0))))
   (let* ((o (base . pos))
	  (dv (v- v o))
	  (dx (vector-x dv))
	  (dy (vector-y dv))
	  (dz (vector-z dv))
	  (b (make-prism
	      (list
	       (send base :transform-vector (float-vector 0 dy 0))
	       (send base :transform-vector (float-vector dx dy 0))
	       (send base :transform-vector (float-vector dx 0 0))
	       (send base :transform-vector (float-vector 0 0 0)))
	      (send base :transform-vector (float-vector 0 0 dz)))
	     ))
     (send b :transform base 'local)
     (send self :draw-body b nil))
   )
  (:erase-mark
   (p &optional (len 10.0))
   (send self :viewsurface :set-erase-mode)
   (send self :draw-mark p len)
   (send self :viewsurface :set-show-mode))
  (:draw-mark
   (p &optional (len 10.0))
   (cond
    ((float-vector-p p)
     (if (= (length p) 2)
	 (send self :draw-star-ndc (2dvector-to-3dvector p)
	       0.05)
       (send self :draw-star p 0.05))
     )
    ((derivedp p face)
     (send self :draw-axis
	   (send p :center-coordinates) len))
    ((derivedp p edge)
     (send self :draw-axis
	   (send p :center-coordinates) len))
    ((derivedp p body)
     (send self :draw-axis (send p :center-coordinates) len))
    ((derivedp p coordinates)
     (send self :draw-axis p len))
    ((derivedp p edge-image)
     (send self :draw-star (send (p . edge3) :point 0.0) 0.05)
     (send self :draw-star (send (p . edge3) :point 1.0) 0.05)
     )
    ((derivedp p 2dlnseg)
     (send self :draw-star-ndc (2dvector-to-3dvector (p . spos))
	   0.05)
     (send self :draw-star-ndc (2dvector-to-3dvector (p . epos))
	   0.05)
     )
    ))
  (:project-to-screen
   (v)
   (send port :ndc-point-to-screen (homo2normal (send eye :view v)))
   )
  (:hid
   (bodies)
   (cond
    ((or
      (consp bodies)      
      (derivedp bodies body))
     (setq bodies (flatten bodies))
     (hid2 (flatten bodies) eye)
     (dolist (ei *hid*) (send self :draw ei))
     )
    (t (send self :draw bodies))))
  (:clear () (send surface :clear))
  (:set-viewsurface (vs) (setq surface vs))
  (:setup-by-camera-coord
   (camera &key
	   (width (send self :viewport :width))
	   (height (send self :viewport :height))
	   )
   (setq eye (send camera
		   :viewing
		   :width width :height height))
   (send self :viewport :size (float-vector width height))
;;   (describe ( self . port))
   (send self :viewport :newcoords
	 (send self :viewport :rot)
	 (2dvector-to-3dvector (send camera :uv0)))
   camera)
  )
(defmethod model-pickport
  (:init (&rest
	  args
	  &key
	  ((:objects obj))
	  &allow-other-keys
	  )
	 (setq objects obj)
	 (apply #'send-message self (class . super) :init args)
	 self)
  (:objects (&optional v)
	    (if v (setq objects v) objects))
  (:erase-objects (&optional (o objects)) (send-super :erase o))
  (:draw-objects (&optional (o objects)) (send-super :draw o))
  (:hid-objects (&optional (o objects))
		(send self :hid o)
		(setq edge-images *hid*))
  (:erase-hid-objects
   (&optional o)
   (if o
       (send-super :erase o)
     (send-super :erase edge-images)))
  (:2dlnsegs
   (&optional bod)
   (send self :edge-images bod)
   (mapcan #'(lambda (l) (send l :2dlnsegs)) edge-images))
  (:edge-images
   (&optional bodies)
   (cond
    ((null bodies))
    (t (hid2 (flatten bodies) eye)
       (setq edge-images *hid*)))
   edge-images)
  (:draw-edge-images (&optional (es edge-images))
		     (send-super :draw es))
  (:pick-coordinates (p) (pick-coordinates objects p self))
  (:pick-object (p) (pick-object objects p self))
  (:pick-face (p) (pick-object-face objects p self))
  (:pick-edge (p) ((send self :pick-edge-image p) . edge3))
  (:pick-edge-image (p) (pick-edge-image edge-images p self))
  (:pick-2dlnseg (p) (car (pick-edge-image-aux edge-images p self)))
  (:pick-junction
   (screen-pos)
   (let*
       ((p (2dvector-to-3dvector screen-pos))
	(p3 (send self :viewport :screen-point-to-ndc p))
	(p2 (float-vector (vector-x p3) (vector-y p3)))
	(e (send self :pick-2dlnseg screen-pos))
	(sd (distance (e . spos) p2))
	(ed (distance (e . epos) p2))
	)
     (if (< sd ed) (e . spos) (e . epos)))
   )
  (:pick-edge-aux (p) (pick-edge-image edge-images p self))
  (:pick-vertex
   (screen-pos)
   (let*
       ((p (2dvector-to-3dvector screen-pos))
	(e (send self :pick-edge screen-pos))
	(sd (distance
	     (send self :project-to-screen (e . pvert))
	     p))
	(ed (distance
	     (send self :project-to-screen (e . nvert))
	     p))
	)
     (if (< sd ed) (e . pvert) (e . nvert)))
   )
  )
;;;
(defmethod image-pickport
  (:init (&rest
	  args
	  &key
	  ((:polylines lines))
	  &allow-other-keys
	  )
	 (setq polylines lines)
	 (apply #'send-message self (class . super) :init args)
	 self)
  (:polylines (&optional v)
	      (if v (setq polylines v) polylines))
  (:nearest-segment-aux
   (pos)
   (let*
       ((l-d (send (car polylines) :nearest-lnseg-aux pos))
	(d (cadr l-d))
	(l (car l-d)))
     (dolist
      (pl (cdr polylines))
      (setq l-d (send pl :nearest-lnseg-aux pos))
      (when (> d (cadr l-d))
	    (setq d (cadr l-d))
	    (setq l (car l-d)))
      )
     (list l d)))
  (:nearest-segment
   (pos)
   (car (send self :nearest-segment-aux pos)))
  (:nearest-polyline
   (p)
   (let
       ((min-dist 100000)
	dist nearest-line)
     (dolist (ll polylines)
	     (setq dist (send ll :distance-from-2dvector p))
	     (if (< dist min-dist)
		 (setq min-dist dist nearest-line ll)))
     nearest-line)
   )
  (:dividing-polylines
   (&optional (par *linearity-thd*))
   (mapcar #'(lambda (pl) (send pl :dividing-polyline par))
	   polylines))
  (:dividing-segments
   (&optional (par *linearity-thd*))
   (mapcan #'(lambda (pl) (send pl :dividing-2dlnsegs par))
	   polylines))
  (:divide-polylines
   (&optional (par *linearity-thd*))
   (setq polylines (send self :dividing-polylines par)))
  (:longest-line
   ()
   (let ((max 0) maxline dist)
     (dolist (l polylines)
	     (setq dist (send l :length))
	     (if (> dist max)
		 (setq maxline l max dist)))
     maxline))
  (:longer-line
   (thd)
   (let (result)
     (dolist (l polylines)
	     (if (> (send l :length) thd)
		 (setq result (cons l result))))
     result))
  (:sort-polylines
   (&key (lines polylines) (func :length))
   (sort lines #'>= #'(lambda (x) (send x :length))))
  (:segments
   ()
   (mapcan #'(lambda (l) (send l :2dlnsegs)) polylines))
  (:sort-segments
   (&key (lines (send self :segments)) (key :length))
   (sort lines #'>= #'(lambda (x) (send x key))))
  )

;;;
(defun pick-object (objects screen-pos &optional (aviewer *viewer*))
  (caddr (pick-object-aux objects screen-pos aviewer)))
(defun pick-object-point (objects screen-pos &optional (aviewer *viewer*))
  (car (pick-object-aux objects screen-pos aviewer)))
(defun pick-object-face (objects screen-pos &optional (aviewer *viewer*))
  (cadr (pick-object-aux objects screen-pos aviewer)))
(defun pick-object-edge (objects screen-pos &optional (aviewer *viewer*))
  (pick-edge
   (mapcan #'(lambda (o) (send o :edges)) objects)
   screen-pos aviewer))
(defun pick-object-edge-image (objects screen-pos &optional (aviewer *viewer*))
  (hid2 objects (send aviewer :viewing))
  (pick-edge-image *hid* screen-pos aviewer))
;;;   
;;;
(defun pick-object-aux (objects screen-pos &optional (aviewer *viewer*))
  ;; --> (ndc-pos face object)
  (let*
      ((p (2dvector-to-3dvector screen-pos))
       (pline (send aviewer :viewing :view-line
		    (send aviewer :viewport :screen-point-to-ndc p)))
       (vpos (send pline :pos))
       (dist-min 1000000.0) picked-face cp d)
    (dolist
     (o objects)
     (dolist
      (f (send o :faces))
      (when
       (> (send f :distance vpos) 0.0)
       (setq cp (send f :cross-with-3dline pline))
       (when
	(eq 'inside (send f :insidep cp))
	(setq d (distance cp vpos))
	(if (< d dist-min)
	    (setq dist-min d picked-face (list cp f o)))))
      ))
    picked-face))
;;;
(defun pick-face (faces screen-pos &optional (aviewer *viewer*))
  (let*
      ((p (2dvector-to-3dvector screen-pos))
       (pline (send aviewer :viewing :view-line
		    (send aviewer :viewport :screen-point-to-ndc p)))
       (vpos (send pline :pos))
       (dist-min 1000000.0)
       picked-face
       cp d)
    (dolist
     (f faces)
     (when
      (> (send f :distance vpos) 0.0)
      (setq cp (send f :cross-with-3dline pline))
      (when
       (eq 'inside (send f :insidep cp))
       (setq d (distance cp vpos))
       (if (< d dist-min)
	   (setq dist-min d picked-face f)))))
    picked-face))
;;;
(defun pick-edge-image (edge-images screen-pos &optional (aviewer *viewer*))
  (cadr (pick-edge-image-aux edge-images screen-pos aviewer)))
(defun pick-edge-image-aux (edge-images screen-pos &optional (aviewer *viewer*))
  ;; -> (2dlnseg edge-image)
  (let*
      ((p0 (2dvector-to-3dvector screen-pos))
       (p (send aviewer :viewport :screen-point-to-ndc p0))
       (dist-min 10000.0)
       picked d)
    (dolist
     (ei edge-images)
     (dolist
      (l (send ei :2dlnsegs))
      (setq d (send l :distance-from-nearest-point
		    (float-vector (vector-x p) (vector-y p))))
      (if (< d dist-min)
	  (setq dist-min d picked (list l ei)))))
    picked)
  )
;;;
(defun pick-2dlnseg (2dlns screen-pos &optional (aviewer *viewer*))
  (let*
      ((p0 (2dvector-to-3dvector screen-pos))
       (p (send aviewer :viewport :screen-point-to-ndc p0))
       (dist-min 10000.0)
       picked d)
    (dolist
     (l 2dlns)
     (setq d (send l :distance-from-nearest-point
		   (float-vector (vector-x p) (vector-y p))))
     (if (< d dist-min)
	 (setq dist-min d picked l)))
    picked)
  )
;;;
(defun pick-edge (edges screen-pos &optional (aviewer *viewer*))
  (let*
      ((p (2dvector-to-3dvector screen-pos))
       (pline (send aviewer :viewing :view-line
		    (send aviewer :viewport :screen-point-to-ndc p)))
       (dist-min 10000.0)
       picked d)
    (dolist
     (e edges)
     (setq d (send
	      (instance 3dline :init
			(v- (e . pvert) (e . nvert)) (e . pvert))
	      :distance-from-line pline))
     (if (< d dist-min) (setq dist-min d picked e)))
    picked)
  )
;;;
(defun pick-coordinates (coordlist screen-pos &optional (aviewer *viewer*))
  (let*
      ((p (2dvector-to-3dvector screen-pos))
       (pline (send aviewer :viewing :view-line
		    (send aviewer :viewport :screen-point-to-ndc p)))
       (dist-min 10000.0)
       picked d)
    (dolist
     (c coordlist)
     (setq d (send pline :distance-from-3dvector (send c :worldpos)))
     (if (< d dist-min)
	 (setq dist-min d picked c)))
    picked)
  )
;;;
(defun pick-vector (vlist screen-pos &optional (aviewer *viewer*))
  (let*
      ((p (2dvector-to-3dvector screen-pos))
       (pline (send aviewer :viewing :view-line
		    (send aviewer :viewport :screen-point-to-ndc p)))
       (dist-min 10000.0)
       picked d)
    (dolist
     (v vlist)
     (setq d (send pline :distance-from-3dvector v))
     (if (< d dist-min) (setq dist-min d picked v)))
    picked)
  )

