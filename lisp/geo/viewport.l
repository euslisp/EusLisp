;;; viewport.l
;;;	1. NDC to SCREEN mapping by class viewport.
;;;	2. 3 dimensional clipping in NDC space by viewport.
;;;	2. Coordination among viewing, viewport and viewsurface
;;;	   by class viewer.
;;; Make viewing, viewsurface and viewport objects and enter them
;;; in viewer object. Then viewer draw objects defined in world
;;; through viewing transformation, projective mapping, and viewport
;;; transformation. Viewer also forwards messages to its components.
;;;
;;;	Copyright (c) Toshihiro MATSUI, Electrotechnical Laboratory, 1988.
;;;	Methods for 2dlnseg are added by M.INABA, UTOYO.

;	homo2normal is redefined in C (clib/clip.c)
;(defun homo2normal (v)
;  (let ((w (aref v 3)))
;    (float-vector (/ (aref v 0) w) (/ (aref v 1) w) (/ (aref v 2) w))))
;

(in-package "COMPILER")
(labels ((def-builtin-entry (sym lab) ;; copy from comp/builtins.l
          (putprop sym lab 'builtin-function-entry )))
  (def-builtin-entry 'GEO::LINE-INTERSECTION3 "LINEINTERSECTION3")
  (def-builtin-entry 'GEO::LINE-INTERSECTION "LINEINTERSECTION")
  (def-builtin-entry 'GEO::VIEWPORTCLIP "VPCLIP")
  (def-builtin-entry 'GEO::HOMO-VIEWPORT-CLIP "HOMO_VPCLIP")
  (def-builtin-entry 'GEO::HOMO2NORMAL "HOMO2NORMAL")
  (def-builtin-entry 'GEO::HOMOGENIZE "HOMOGENIZE"))

(in-package "GEOMETRY")

(defvar  *viewer*)
(defvar  *viewers*)
(defvar  *viewing*)
(defvar  *viewsurface*)
(defvar  *viewport*)

(export '(*viewer* *viewing* *viewsurface* *viewers* *viewport*
	 draw draw-tree erase draw-axis draw-arrow 
	hid *draw-invisible-edges* hidd cls
	draw-step draw-hid draw-thick draw-thick-step
	find-viewer view with-gc with-viewsurface))

(eval-when (compile)
   (load "geoclasses.l"))

(defparameter tempfv1 (float-vector 0 0 0))
(defparameter tempfv2 (float-vector 0 0 0))

(defclass viewport :super coordinates)

(defmethod viewport
  (:xcenter (&optional v)
	   (if v (setf (aref pos 0) v ))
	   (aref pos 0))
  (:ycenter (&optional v)
	   (if v (setf (aref pos 1) v))
	   (aref pos 1))
  (:center  (&optional x (y x))
	(cond ((numberp x)
		(setf (aref pos 0) x)
		(setf (aref pos 1) y))
	      ((float-vector-p x)
		(setf (aref pos 0) (aref x 0))
		(setf (aref pos 1) (aref x 1)))
	      (t (float-vector (aref pos 0) (aref pos 1)))))
  (:width (&optional v)
	  (if v (setf (aref rot 0 0) (/ v 2.0)))
	  (* (aref rot 0 0) 2.0))
  (:height (&optional v)
	   (if v (setf (aref rot 1 1) (/ v 2.0)))
	   (* (aref rot 1 1) 2.0))
  (:size (&optional w (h w))
	(cond ((numberp w)
		(setf (aref rot 0 0) (/ w 2.0))
		(setf (aref rot 1 1) (/ h 2.0)))
	      ((float-vector-p w)
		(setf (aref rot 0 0) (/ (aref w 0) 2.0))
		(setf (aref rot 1 1) (/ (aref w 1) 2.0)))
	      (t (float-vector (* 2.0 (aref rot 0 0)) (* 2.0 (aref rot 1 1))))))
  (:SCREEN-point-to-NDC   (p)
     (let ((v (copy-seq p)))
        (transform (inverse-matrix rot) (v- p pos v) v)))
  (:NDC-width-to-SCREEN (wid)  (abs  (* (aref rot 0 0)  wid)))
  (:NDC-height-to-SCREEN (hei) (abs  (* (aref rot 1 1)  hei)))
  (:NDC-point-to-SCREEN (p)
     (let ((v  (if (= (length p) 2)
	          (float-vector (aref p 0) (aref p 1) 0.0)
	   	  (copy-seq p))))
	 (v+ (transform rot v v) pos v)))
  (:NDC-line-to-SCREEN  (p1 p2 &optional (do-clip T))
	;p1 and p2 are 3Dfloatvector(either homo or normal) defined in NDC
     (when do-clip
	(setq p1 (homo-viewport-clip p1 p2))
	(if (null p1) (return-from :ndc-line-to-screen nil))
	(setq p2  (cadr p1) p1  (car p1)))
     (if (> (length p1) 3)
	(setq p1 (homo2normal p1) p2 (homo2normal p2)))
     (if (< (length p1) 3)
	(setq p1 (homogenize p1) p2 (homogenize p2)))
     (v+ (transform rot p1 tempfv1) pos tempfv1)
     (v+ (transform rot p2 tempfv2) pos tempfv2)
     (list
	(float-vector (aref tempfv1 0) (aref tempfv1 1))
	(float-vector (aref tempfv2 0) (aref tempfv2 1)))) 
  (:resize (&rest args
		&key  xcenter
		      ycenter
		      width
		      height
		&allow-other-keys)
	(if width (send self :width width))
	(if height (send self :height height))
	(if xcenter (send self :xcenter xcenter))
	(if ycenter (send self :ycenter ycenter))
	(send self :newcoords rot pos)
	self)
  (:init (&rest args
	  &key  (dimension 3)
		(xcenter 100)
		(ycenter 100)
		(width 200)
		(height 200)
		&allow-other-keys)
	 (send-super :init :dimension 3)
	 (send self :width width)
	 (send self :height height)
	 (send self :xcenter xcenter)
	 (send self :ycenter ycenter)
	 (send self :newcoords rot pos)
	 self)
  )

(defclass viewer :super propertied-object
	:slots ((eye :forward
			 (:look :view :viewpoint :view-direction
			  :zoom :translate :locate :viewdistance :screen))
		(port)
		(surface)))

(defmethod viewer
  ;message forwarding
  (:viewing (&rest msg)
	(if msg
	    (send* eye msg)
	    eye))
  (:viewsurface (&rest msg)
	(if msg
	    (send* surface msg)
	    surface))
  (:viewport (&rest msg)
	(if msg
	    (send* port msg)
	    port))
  (:flush () (send surface :flush)))

(defmethod viewer
 (:point-to-screen (p)
    (send port :NDC-point-to-SCREEN (homo2normal (send eye :view p)))))

;;; drawing primitives in NDC

(defmethod viewer
  (:draw-point-NDC (p &optional color)  ; p is a float-vector
    (if color (send surface :color color))
    (setq p (send port :NDC-point-to-SCREEN p))
    (send surface :draw-point p))
;;; :draw-line-NDC is the lowest line drawing primitive which works in NDC.
  (:draw-line-NDC  (p1 p2 &optional (do-clip T) (color nil))
      (if color (send surface :color color))
	;p1 and p2 are 3Dfloatvector(either homo or normal) defined in NDC
;     (if (> (length p1) 3)
;	(setq p1 (homo2normal p1) p2 (homo2normal p2)))
     (setq p1 (send port :NDC-line-to-SCREEN p1 p2 do-clip))
     (if p1 (send surface :draw-line (car p1) (cadr p1)))
     nil)
  (:draw-string-ndc (point string &optional color)
    (if color (send surface :color color))
    (setq point (send port :ndc-point-to-screen point))
    (send surface :draw-string point string) )
  (:draw-image-string-ndc (point string &optional color)
    (if color (send surface :color color))
    (setq point (send port :ndc-point-to-screen point))
    (send surface :draw-image-string point string) )
  (:draw-rectangle-ndc (point width height &optional color)
    (if color (send surface :color color))
    (setq point (send port :ndc-point-to-screen point))
    (setq width (send port :ndc-width-to-screen width))
    (setq height (send port :ndc-height-to-screen width))
    (send surface :draw-rectangle point width height))
  (:draw-fill-rectangle-ndc (point width height &optional color)
    (if color (send surface :color color))
    (setq point (send port :ndc-point-to-screen point))
    (setq width (send port :ndc-width-to-screen width))
    (setq height (send port :ndc-height-to-screen height))
    (send surface :draw-fill-rectangle point width height))
  (:draw-arc-ndc (point width height
		  &optional (angle1 0) (angle2 2pi) color)
    (if color (send surface :color color))
    (setq point (send port :ndc-point-to-screen point))
    (setq width (send port :ndc-width-to-screen width))
    (setq height (send port :ndc-height-to-screen height))
    (send surface :draw-arc point width height angle1 angle2)) 
  (:draw-fill-arc-ndc (point width height angle1 angle2 &optional color)
    (if color (send surface :color color))
    (setq point (send port :ndc-point-to-screen point))
    (setq width (send port :ndc-width-to-screen width))
    (setq height (send port :ndc-height-to-screen height))
    (send surface :draw-fill-arc point width height angle1 angle2))
  (:draw-polyline-NDC (polyline &optional color)
    (let ((p1 (pop polyline)) p2)
      (while polyline
	 (setq p2 (pop polyline))
	 (send self :draw-line-NDC p1 p2 t color)
	 (setq p1 p2))))
  (:draw-box-NDC (lower-left upper-right &optional color)
    (declare (float-vector lower-left upper-right))
    (let ((x1 (aref lower-left 0))   (y1 (aref lower-left 1))
	  (x2 (aref upper-right 0)) (y2 (aref upper-right 1)))
        (send self :draw-polyline-NDC
	   (list 
		   (float-vector x1 y1 0) (float-vector x2 y1 0)
		   (float-vector x2 y2 0) (float-vector x1 y2 0)
		   (float-vector x1 y1 0)) color)))
  (:draw-star-NDC (point &optional (size 0.02) (color nil))
    (send self :draw-line-NDC
	(float-vector (- (aref point 0) size) (aref point 1) 0)
	(float-vector (+ (aref point 0) size) (aref point 1) 0) t color)
    (send self :draw-line-NDC
	(float-vector (aref point 0) (- (aref point 1) size) 0)
	(float-vector (aref point 0) (+ (aref point 1) size) 0) t color)) )

;; drawing primitives which work in world coordinates
;; First, viewing and projective transformations are applied,
;; then xxx-ndc primitives are called.

(defmethod viewer
  (:draw-line (p1 p2 &optional (do-clip t) (color nil))
     (setq p1 (send eye :view p1) p2 (send eye :view p2))
     (send self :draw-line-NDC p1 p2 do-clip color)
     (sys:reclaim p1) (sys:reclaim p2))
  (:draw-box (v &optional (size (/ (send surface :width) 300.0)) color)
    ;draw a small mark at v (defined in world)
    (setq size (float-vector size size 0.0))
    (setq v (homo2normal (send eye :view v)))
    (send self :draw-box-NDC (v- v size) (v+ v size) color))
  (:draw-polyline (vlist &optional color)
    (send self :draw-polyline-ndc
		(mapcar #'(lambda (x) (send eye :view x)) vlist) color))
  (:draw-arc (point width height
		&optional (angle1 0) (angle2 2pi) color
		&aux v)
    (if color (send surface :color color))
    (setq point (send eye :view  point))
    (setq v (send eye :project (float-vector width height)))
    (send self :draw-arc-ndc point (aref v 0) (aref v 1) angle1 angle2 color))
  (:draw-fill-arc (point width height
		&optional (angle1 0) (angle2 2pi) color
		&aux v)
    (if color (send surface :color color))
    (setq point (send eye :view  point))
    (setq v (send eye :project (float-vector width height)))
    (send self :draw-fill-arc-ndc point (aref v 0) (aref v 1) angle1 angle2 color))
  (:draw-arrow (p1 p2 &optional (do-clip t) (color nil) &key (arrow-scale #f(1 1)))
    ;; added by Hirukawa
    (let (p21 pn pa pb)
       (setq p1 (send eye :view p1) p2 (send eye :view p2)) ; world to NDC
       (setq p1 (homo2normal p1) p2 (homo2normal p2))
       (setq p21 (v- p1 p2))
       (scale 0.3 p21 p21)
       (setq pn (float-vector (* (elt arrow-scale 1) (- (elt p21 1))) (* (elt arrow-scale 1) (elt p21 0)) 0))
       (setf (elt p21 2) 0.0)
       (scale (elt arrow-scale 0) p21 p21)
       ; p21 and pn became vectors on Zv plane
       (setq pa (v+ (v+ p2 (scale 0.5 pn)) p21)
	     pb (v+ (v+ p2 (scale -0.5 pn)) p21))
       ;         pa \
       ;             \
       ; p1 ---------- p2       pa and pb are always on Zv plane
       ;             /
       ;         pb /
       (send self :draw-line-NDC p1 p2 do-clip color)
       (send self :draw-line-NDC pa p2 do-clip color)
       (send self :draw-line-NDC pb p2 do-clip color)
       (sys:reclaim p1) (sys:reclaim p2)
       (sys:reclaim pn) (sys:reclaim pa) (sys:reclaim pb)))
  (:pane () (send self :draw-box-NDC #f(-1 -1 0) #f(1 1 0)))
  (:draw-star (v &optional size color)
      (if (null size) (setq size 0.02))
      (send self :draw-star-NDC (homo2normal (send eye :view v)) size color))
  (:draw-2dlnseg   (l)
     (send self :draw-line (send l :spos) (send l :epos))) )

;;
;; Draw objects
;;
(defmethod viewer
  (:draw-edge-image (ei &optional (dashed-invisibles nil)
				  (color (send ei :color)) )
      (dolist (v (send ei  :visible-segments))
	 (send self :draw-line-NDC (car v) (cadr v) nil color)) ;already clipped
      (when dashed-invisibles
         (send surface :line-style 1)
         (dolist (iv (send ei :invisible-segments))
	     (send self :draw-line-NDC (car iv) (cadr iv) nil color)) 
	 (send surface :line-style 0))      )
  (:draw-edge (e &optional color)
     (if color (send surface :color color))
     (send self :draw-line (line-pvert e) (line-nvert e) eye))
;; :draw-face is not defined since face-by-face drawing causes 
;; each edge drawn twice.
  (:draw-faces (flist &optional (normal-clip nil) color)
   (let ((drawn-edges) (viewpoint (send eye :viewpoint)) s c)
     (dolist  (f flist)
        (unless (and normal-clip (< (send f :distance viewpoint) 0.0))
	    (setq c (if color color (send f :color)))
	    (dolist (e (send f :all-edges))
	       (when (null (memq e drawn-edges))
		  (send self :draw-edge e c)
		  (push e drawn-edges)))))
     (while drawn-edges
	(setq s (cdr drawn-edges))
	(sys:reclaim drawn-edges)
	(setq drawn-edges s))))
  (:draw-body (bod &optional (normal-clip t))
     (send bod :worldcoords)
     (send self :draw-faces (send bod :faces) normal-clip (send bod :color)))
  (:draw-axis (coords &optional size)
     (if (null size) (setq size 1.0))
     (let* ((origin (send coords :transform-vector #f(0 0 0)))
	    (arrowsize (* size 0.3))
	    (zaxis (float-vector 0 0 size))
	    (ztop (send coords :transform-vector zaxis)))
        (send self :draw-line
	      origin (send coords :transform-vector (float-vector size 0 0)))
        (send self :draw-line
	      origin (send coords :transform-vector (float-vector 0 size 0)))
        (send self :draw-line origin ztop)
        (send self :draw-line ztop
	      (send coords :transform-vector
		(v+ zaxis
	            (float-vector arrowsize 0 (- arrowsize)  ))))
        (send self :draw-line ztop
	      (send coords :transform-vector
			(v+ zaxis
			    (float-vector 0 arrowsize (- arrowsize)  ))))
        ))
 )

;;; :draw is the general drawing method applicable to body,face,edge,point
;;; and coordinates.

(defmethod viewer
   (:draw-one   (thing info)
    (cond
     ((numberp thing) nil)
     ((listp thing)
        (cond ((float-vector-p (car thing)) 
		(case (length (car thing))
;		  (2 (send surface :draw-line  (car thing) (second thing)))
		  ((2 3) (send self :draw-line     (car thing) (second thing)))
		  (4 (send self :draw-line-NDC (car thing) (second thing)))
		  (t (error "draw vector?"))))
	      (t (dolist (x thing)  (send self :draw-one x info)))) )
     ((find-method thing :draw)
	(send thing :draw self))
     ((find-method thing :drawners)
        (if (find-method thing :worldcoords)
	    (send thing :worldcoords))
	(send self :draw-one (send thing :drawners) info))
     ((derivedp thing line) (send self :draw-edge thing))
     ((derivedp thing edge-image)  (send self :draw-edge-image thing))
     ((derivedp thing body)
        (send thing :worldcoords)
	(let ((color (send thing :color)))
	   (dolist (e (send thing :visible-edges eye))
	      (send self :draw-edge e color)) ) )
     ((derivedp thing faceset)
        (send thing :worldcoords)
	(let ((color (send thing :color)))
	   (dolist (e (send thing :edges))
	      (send self :draw-edge e color)) ) )
     ((derivedp thing face) (send self :draw-faces (list thing)))
     ((derivedp thing polygon)
	(dolist (e (send thing :edges))   (send self :draw-edge e)))
     ((float-vector-p thing) (send self :draw-star thing) info)
     ((coordinates-p thing) (send self :draw-axis (send thing :worldcoords) info))
     ((and (boundp '2dlnseg) (derivedp thing 2dlnseg))	; UTYO
	 (send self :draw-2dlnseg thing))
     ;; opengl extention
     ((and (boundp 'colormaterial) (derivedp thing colormaterial))
        (send surface :material thing))
     ((and (boundp 'linecolor) (derivedp thing linecolor))
	(send surface   :color  thing))
     ))
   (:draw  (thing &optional info)
    (cond
     ((listp thing) (dolist (x thing)  (send self :draw-one x info)))
     (thing (send self :draw-one thing info)))
    (send surface :flush)
    t)
  (:erase (thing)	;draw thing with white dots
	 (send surface :set-erase-mode)
	 (send self :draw thing)
	 (send surface :set-show-mode))
  (:clear () (send surface :clear) (send surface :flush))
  (:init (&key ((:viewing ving)) ((:viewport vport)) ((:viewsurface vsurf))
		alternate
		name)
     (setf (get self :name) name)
     (setq eye ving
	   port vport
	   surface vsurf
	   alt-surface alternate)
     (push self *viewers*)
     self))

(defmethod viewer
 (:adjust-viewport (&optional w h (cx (/ w 2)) (cy (/ h 2)))
    (unless w 
	(setq w (send surface :width)
	      h (send surface :height)))
    (send port :center cx cy)
    (send port :size w (- h)))
 (:resize (width &optional (height width))
    (send surface :resize width height)
    (send surface :flush)
    (send self :adjust-viewport  width height ;(max width height) (max width height)
		(/ width 2) (/ height 2))
    (send eye :aspect (/ (float height) width))
    )
 )
;;;
;;; handy functions
;;;

;; BUG: (draw 1 *viewer* ...) causes stack overflow since :draw is defined
;; in VIEWER.

(defun draw (&rest things &aux vw (thickness))
   (setf vw 
	(if (derivedp (first things) viewer)
	    (pop things)
	    *viewer*)     )
   (when (integerp (car things))
	(setq thickness (pop things))
        (send vw :viewsurface :line-width thickness))
   (dolist (thing things) (send vw :draw thing))
   (when (integerp thickness)
	(send vw :viewsurface :line-width 1)))

(defun draw-tree (&rest ccs)	;cascaded-coords
   (let (cc cc2)
     (while ccs
	(setq cc (pop ccs))
        (if (derivedp cc faceset)
	    (draw cc))
	(setq cc2 (send cc :descendants))
	(dolist (c cc2) (push c ccs)))))

(defun erase (&rest things &aux (vw *viewer*) (thickness))
   (if (derivedp (first things) viewer)
       (setf vw (pop things)))
   (when (integerp (car things))
	(setq thickness (pop things))
	(send vw :viewsurface :line-width thickness))
   (send vw :erase things)
   (when (integerp thickness)
	(send vw :viewsurface :line-width 1)) )

(defun draw-axis (&rest thing &aux (vw *viewer*) (scale 10.0))
   (if (derivedp (first thing) viewer)
	(setq vw (pop thing)))
   (if (numberp (first thing))
	(setq scale (pop thing)))
   (dolist (ax thing)
	(send vw :draw-axis ax scale))
   (send vw :viewsurface :flush))

(defun draw-arrow (p1 p2)
  (send *viewer* :draw-arrow p1 p2)
  (send *viewsurface* :flush))

(defun hid (&rest thing &aux (vw *viewer*) (drawners) (bodies))
   (let ((*ignore-approximated-edges* t)
	 (*coplanar-threshold* 0.0)
	 (*parallel-threshold* 0.0)
	 (*contact-threshold* 0.0)
	 (*epsilon* 0.0))
      (if (derivedp (first thing) viewer)
          (setf vw (pop thing)))
      (dolist (d (flatten thing))
         (if (find-method d :drawners)
	     (setq drawners (append (send d :drawners) drawners))
	     (push d drawners) ) )
      (hid2  drawners (send vw :viewing))
      (send vw :draw *hid*)) )

(defvar *draw-invisible-edges* t)

(defun hidd (&rest thing &aux (vw *viewer*) (drawners) (bodies))
   (if (derivedp (first thing) viewer)
       (setf vw (pop thing)))
   (dolist (d (flatten thing))
      (if (find-method d :drawners)
	  (setq drawners (append (send d :drawners) drawners))
	  (push d drawners) ) )
   (let ((*coplanar-threshold* 0.0)
	 (*parallel-threshold* 0.0)
	 (*contact-threshold* 0.0)
	 (*epsilon* 0.0))
     (hid2  drawners (send vw :viewing)))
   (dolist (h *hid*)  (send vw :draw-edge-image h t))
   (when *draw-invisible-edges*
       (send vw :viewsurface :line-style 1)
       (dolist (e *invisible-edges*)
	  (unless (and *ignore-approximated-edges*
		       (send e :approximated-p))
	       (send vw :draw-edge e (send e :color))))
       (send vw :viewsurface :line-style 0))
   (send vw :viewsurface :flush)   )

(defun cls (&optional (vw *viewer*))
   (send vw :viewsurface :clear)
   (send vw :viewsurface :flush))

(defun draw-hid (segments &optional (v *viewer*))
   (dolist (s segments) (send v :draw-line-NDC (car s) (cadr s) nil))
    (xflush))

(defun draw-step (&rest objs &aux (*viewer* *viewer*) (thickness 3))
  (if (derivedp (first objs) viewer)
      (setf *viewer* (pop objs)))
  (if (integerp (car objs))
      (setq thickness (pop objs)))
  (unwind-protect
     (dolist (x (flatten objs))
        (send *viewer* :viewsurface :line-width thickness)
        (send *viewer* :viewsurface :function 6)
        (print x) (send *viewer* :draw x) 
        (let ((ch (read-char)))
	   (if (eql ch #\q) (return-from draw-step x)))
        (send *viewer* :draw x)     ;; erase
        (send *viewer* :viewsurface :line-width 1)
        (send *viewer* :viewsurface :function 15)
        (draw *viewer* :draw x) )
     (send *viewer* :viewsurface :line-width 1)
     (send *viewer* :viewsurface :function 15))
)

;; view create a viewer instance.

(defun find-viewer (name)
   (find-if #'(lambda (v) (string-equal name (send v :name))) *viewers*))

(defun view (&rest args
	     &key
		  ((:viewport vport))
		  ((:viewsurface vsurface))
		  ((:viewing ving))
		  (dimension 3)
		  (size 500) (width size) (height size)
		  (x 100) (y 100)
		  (title "eusx view")
		  (name title)
		  (parent nil)
		  (border-width 3)
		  (background)
		  (viewpoint (float-vector 300 200 100))
		  (target (float-vector 0 0 0))
		  (viewdistance 5.0)  (hither 100.0) (yon 10000.0)
		  (screen 1.0) (screen-x screen) (screen-y screen)
		  (xcenter (/ width 2.0))
		  (ycenter (/ height 2.0))
		  (backing-store 2)
		  (save-under 0)
		  (alternate nil)
		  &allow-other-keys
		  )
    "view: create a viewer with a viewsurface and a viewing.
Type of viewsurface is determined by *features*.
xview  --> canvas-viewsurface
xlib   --> xwindow
none   --> tektro-viewsurface
Created viewer instance is pushed in the *viewers* list.
To get viewing or viewsurface object in the viewer, send :viewing or
:viewsurface message to the viewer
	keyword parameters:
	:x, :y	--location where the window appears
	:size, :height, :width	--window size
	:title	--window name
	:viewpoint, :target	--viewing coords
	:viewdistance, :hither, :yon, :screen	--projection parameters"
    (let (vs vp vg vw)
       (if vsurface
	   (setq vs vsurface)
	   (setq vs (apply #'default-viewsurface 
			 :x x :y y :width width :height height
			 :title title    :parent parent
			 :border-width border-width
			 :background background
			 :backing-store backing-store
			 :save-under save-under
			 :name name
			 args)))
      (if vport
	  (setq vp vport)
      (setq vp (instance viewport :init
			 :dimension dimension
			 :xcenter xcenter :ycenter ycenter
			 :width width
			 :height (if (or (member :xview *features*)
					 (member :xwindow *features*))
				     (- height)
				     height))))
      (setq vg
	   (if ving
	       ving
	       (if (= dimension 2)
	        (instance* viewing2d :init
				 :parent nil
				 :pos (float-vector (aref viewpoint 0)
						    (aref viewpoint 1))
				 args)
	        (instance* perspective-viewing :init
				 :parent nil
				 :pos viewpoint
				 :target target
				 :viewdistance viewdistance
				 :hither hither  :yon yon
				 :screen-x screen-x  :screen-y screen-y
				 args))) )
      (setq vw (find-viewer name))
      (unless vw (setq vw (instantiate viewer)))
      (if (and (boundp 'x::*display*) (numberp x::*display*)
		alternate (not (derivedp alternate x::xdrawable)))
	 (setq alternate
		(instance x::xpixmap :create :width width :height height))
	  )
      (send vw :init
		:viewing vg
		:viewsurface vs
		:viewport vp
		:name name
		:alternate alternate)
      vw))


(defmacro with-gc (gc &rest forms)
   (let (newgc gccreate gcdestroy)
     (cond ((consp gc)
	    (setq newgc (car gc)
		  gccreate `(instance gcontext :create . ,(cdr gc))
		  gcdestroy `((send ,newgc :free))))
	   (t (setq newgc gc gccreate gc gcdestroy nil)))
   `(let ((gcsave (send *viewer* :viewsurface :gc))
	  (,newgc ,gccreate))
     (unwind-protect
	(progn
	   (send *viewer* :viewsurface :gc ,newgc)
	   . ,forms)
	(send *viewer* :viewsurface :gc gcsave)
	. ,gcdestroy))) )


(defmacro with-viewsurface (vsf &rest forms)
   `(let ((vsfsave (viewer-surface *viewer*)) )
     (unwind-protect
	(progn
	   (setf (viewer-surface *viewer*) ,vsf)
	   . ,forms)
	(setf (viewer-surface *viewer*) vsfsave))
     ))

(provide :viewport "@(#)$Id: viewport.l,v 1.1.1.1 2003/11/20 07:46:30 eus Exp $")
