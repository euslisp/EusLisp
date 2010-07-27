;;;
;;;	draw.l
;;;	Simple boot tools of grapchis
;;;		By M.Inaba 1988.10.29
;;;		(hid-sanmenzu abody | list-of-bodies)
;;;		(draw-sanmenzu abody | list-of-bodies)
(defclass image-loop
  :super object
  :slots (edges		; list of 2dlnseg
	  spos		; float-vector (2D)
	  epos		; float-vector (2D)
	  vertices	; list of float-vector (2D)
	  para		; number of parallel edge pair
	  neighbors	; list of image-loop
	  area		; number
	  )
  )
(defconstant nilcoord (instance coordinates :init))
(defparameter *screen-x* 250)
(defparameter *screen-y* 250)

(defparameter *viewsurface-direction* 1)
#+sunview
(defparameter *viewsurface-direction* -1)
#+x68k
(defparameter *viewsurface-direction* -1)
#+xwindow
(defparameter *viewsurface-direction* -1)

#+sunview
(defparameter *viewsurface-width* 450)
#+sunview
(defparameter *viewsurface-height* 450)
#+xwindow
(defparameter *viewsurface-width* 450)
#+xwindow
(defparameter *viewsurface-height* 450)
#-sunview
(defparameter *viewsurface-width* 380)
#-sunview
(defparameter *viewsurface-height* 380)
;;;
(defparameter *port-width* (/ *viewsurface-width* 2))
(defparameter *port-height* (* *viewsurface-direction* *port-width*))
(defparameter *port-width1* (/ *port-width* 2))
(defparameter *port-height1* (/ *port-height* 2))

(defparameter *port-center-x* (+ *port-width* 200))
#+sunview
(defparameter *port-center-x* *port-width*)
#+xwindow
(defparameter *port-center-x* *port-width*)

(defparameter *port-center-y* *port-width*)

(defparameter *port-x1* (- *port-center-x* *port-width1*))
(defparameter *port-y1* (- *port-center-y* *port-width1*))
(defparameter *port-x2* (+ *port-center-x* *port-width1*))
(defparameter *port-y2* (+ *port-center-y* *port-width1*))

(defun set-viewing-scale (x y)
  (send *para-viewing* :screen x y)
  (send *x-viewing* :screen x y)
  (send *y-viewing* :screen x y)
  (send *z-viewing* :screen x y)
  )
(defun enlarge (scale)
  (let
      ((s (/ (car (send *para-viewing* :screen)) scale)))
    (set-viewing-scale s s)))
(defun make-viewings
  ()
  (setq *para-viewing* (instance parallel-viewing :init
				 :pos #f(500 400 120)
				 :target #f(0 0 0)
				 :screen-x *screen-x*
				 :screen-y *screen-y*
				 ))
  (setq *para-viewing* (instance perspective-viewing :init
				 :yon 10000 :hither 100
				 :pos #f(2500 1500 1000)
				 :target #f(0 0 0)
				 :viewdistance
				 (norm #f(2500 1500 1000))
				 :screen-x *screen-x*
				 :screen-y *screen-y*
				 ))
  (setq *viewing* *para-viewing*)
  (setq *x-viewing* (instance parallel-viewing :init
			      :pos #f(500 0 0) 
			      :target #f(0 0 0)
			      :screen-x *screen-x*
			      :screen-y *screen-y*
			      ))
  (setq *y-viewing* (instance parallel-viewing :init
			      :pos #f(0 500 0) 
			      :target #f(0 0 0)
			      :screen-x *screen-x*
			      :screen-y *screen-y*
			      :view-up #f(0 0 1)
			      ))
  (setq *z-viewing* (instance parallel-viewing :init
			      :pos #f(0 0 500) 
			      :target #f(0 0 0)
			      :screen-x *screen-x*
			      :screen-y *screen-y*
			      :view-up #f(-1 0 0)
			      ))
  )
;;;
;;; Viewsurface
;;;
(defun make-viewsurface nil
  (cond
   ((memq 'sunview *features*)
    (setq *viewsurface*
	  (instance canvas-viewsurface :init
		    :title
		    "Canvas Viewsurface"
		    :y 400
		    :width *viewsurface-width*
		    :height *viewsurface-height*
		    :buffer-mode nil)))
   ((memq 'x68k *features*)
    (setq *viewsurface*  (instance x68k-viewsurface :init)))
   ((memq 'egr98 *features*)
    (setq *viewsurface*  (instance egr98-viewsurface :init)))
   ((memq 'xwindow *features*)
    (setq *viewsurface*  (instance xwindow-viewsurface
				   :init
				   :title
				   "X window viewsurface"
				   :x 100
				   :y 100
				   :width *viewsurface-width*
				   :height *viewsurface-height*
				   :backing_store 1)))
   (t
    (setq *viewsurface*  (instance tektro-viewsurface :init)))
   ))
(defun draw-step (xs &optional clear-each-time)
    (dolist (x xs)
        (if clear-each-time (cls))
        (print x) (draw x) (read-char)))
(defun draw  (thing &optional (erase nil))
  (if  erase (send *viewer* :clear))
  (cond
   ((null thing))
   ((derivedp thing face-image)
    (send *viewer* :draw (face-image-edge-images thing)))
   ((derivedp thing image-loop)
    (send *viewer* :draw (thing . edges)))
   ((atom thing)
    (send *viewer* :draw thing nil))
   (t (draw (car thing) erase) (draw (cdr thing) erase)))
  )

(defun hid-draw (body-data &optional (erase nil))
  (if erase
      (send *viewer* :clear))
  (send *viewer* :hid body-data)
  )
(defun hid-draw (body-data &optional (erase nil))
  (if erase (send *viewer* :clear))
  (if (atom body-data)
      (hid2 (list body-data) *para-viewing*)
    (hid2 body-data *para-viewing*))
  (send *viewer* :draw *hid*)
  )

(defun draw-axis (&optional (size 100))
  (send *viewer* :draw-axis nilcoord size))

(defun screen-size (x y)
  (send *viewer* :screen x y))

(defun rotate (body-data deg &optional (axis :z))
  (send body-data :rotate-with-matrix
	(rotation-matrix (deg2rad deg) axis) 'local))

(defun trans (body-data vector &optional (count 1))
  (dotimes (i count)
	   (send body-data :transform
		 (instance coordinates :init (unit-matrix 3) vector)
		 'local)
	   ))

(defun locate (body-data x y z &optional (wrt 'local))
  (send body-data :move-in-world (float-vector x y z) wrt)
  )

(defmethod viewer
  (:2dlnsegs
   (&optional bod)
   (send self :edge-images bod eye)
   (mapcan #'(lambda (l) (send l :2dlnsegs)) edge-images))
  )
  
(defun hid-sanmenzu (bod &optional erase)
  (if erase (send *viewer* :clear))
  (send *viewer1* :pane)
  (send *viewer2* :pane)
  (send *viewer3* :pane)
  (send *viewer4* :pane)
  (send *viewer1* :hid bod)
  (send *viewer2* :hid bod)
  (send *viewer3* :hid bod)
  (send *viewer4* :hid bod)
  (send *viewer1* :draw-axis (instance coordinates :init) 100)
  (send *viewer2* :draw-axis (instance coordinates :init) 100)
  (send *viewer3* :draw-axis (instance coordinates :init) 100)
  (send *viewer4* :draw-axis (instance coordinates :init) 100)
  )
(defun draw-sanmenzu (bod &optional erase)
  (if erase (send *viewer* :clear))
  (send *viewer1* :pane)
  (send *viewer2* :pane)
  (send *viewer3* :pane)
  (send *viewer4* :pane)
  (send *viewer1* :draw bod)
  (send *viewer2* :draw bod)
  (send *viewer3* :draw bod)
  (send *viewer4* :draw bod)
  (send *viewer1* :draw-axis (instance coordinates :init) 100)
  (send *viewer2* :draw-axis (instance coordinates :init) 100)
  (send *viewer3* :draw-axis (instance coordinates :init) 100)
  (send *viewer4* :draw-axis (instance coordinates :init) 100)
  )
;;;;
;;;;  new viewport
;;;;
(defun make-viewer-list (count
			 &optional
			 (viewing *viewing*)
			 (viewsurface *viewsurface*))
  (let
      ((width (/ *port-width* count))
       (height (/ *port-height* count))
       (center (float-vector *port-center-x*
			    *port-center-y*))
       (pos)
       (cnt (1- count))
       )
    (setq *viewer-list* nil)
    (do
     ((i (- cnt) (+ 2 i)))
     ((> i cnt))
     (do
      ((j (- cnt) (+ 2 j)))
      ((> j cnt))
      (setq pos (v+ center
		    (float-vector
		     (* j width)
		     (* i height))))
      (push
       (instance viewer :init
		 :viewing viewing
		 :viewsurface viewsurface
		 :viewport
		 (instance viewport
			   :init
			   :width width :height height
			   :xcenter (vector-x pos)
			   :ycenter (vector-y pos)))
       *viewer-list*)
      ))
    (setq *viewer-list* (reverse *viewer-list*))))
(defun anime (n &optional (thing b+))
  (make-viewer-list n)
  (dolist (v *viewer-list*) (send v :pane))
  (rotate-anime thing 10 :x t)
  )
(defun rotate-anime (body-data deg &optional (axis :z)
			       (hid nil))
  (dolist
   (v *viewer-list*)
   (rotate body-data deg axis)
   (send v :pane)
   (if hid
       (send v :hid body-data)
     (send v :draw body-data)))
  )
(defun make-viewports ()      
  (setq *viewport* (instance viewport
			     :init
			     :width *port-width*
			     :height *port-height*
			     :xcenter *port-center-x*
			     :ycenter *port-center-y*))
  (setq *viewport1* (instance viewport
			      :init
			      :width *port-width1*
			      :height *port-height1*
			      :xcenter *port-x1*
			      :ycenter *port-y1*))
  (setq *viewport2* (instance viewport
			      :init
			      :width *port-width1*
			      :height *port-height1*
			      :xcenter *port-x2*
			      :ycenter *port-y1*))
  (setq *viewport3* (instance viewport
			      :init
			      :width *port-width1*
			      :height *port-height1*
			      :xcenter *port-x1*
			      :ycenter *port-y2*))
  (setq *viewport4* (instance viewport
			      :init
			      :width *port-width1*
			      :height *port-height1*
			      :xcenter *port-x2*
			      :ycenter *port-y2*))
  )
(defun make-viewers ()
  (setq *viewer*
	(instance viewer :init
		  :viewing *para-viewing*
		  :viewport *viewport*
		  :viewsurface *viewsurface*))
  (setq *viewer1*
	(instance viewer :init
		  :viewing *z-viewing*
		  :viewport *viewport1*
		  :viewsurface *viewsurface*))
  (setq *viewer2*
	(instance viewer :init
		  :viewing *para-viewing*
		  :viewport *viewport2*
		  :viewsurface *viewsurface*))
  (setq *viewer3*
	(instance viewer :init
		  :viewing *x-viewing*
		  :viewport *viewport3*
		  :viewsurface *viewsurface*))
  (setq *viewer4*
	(instance viewer :init
		  :viewing *y-viewing*
		  :viewport *viewport4*
		  :viewsurface *viewsurface*))
  )

(make-viewsurface)
(make-viewings)
(make-viewports)   ;;; new viewport
(make-viewers)     ;;; new viewport
(make-viewer-list 4)

(defun draw-test nil
  (setq c1 (make-cube 100 100 50))
  (setq c2 (make-cube 50 50 100))
  (setq b+ (body+ c1 c2))
  (setq b- (body- c1 c2))
  (setq b* (body* c1 c2))
  (setq pl1+ (instance plane :init
		       (float-vector 0 1 0.4) (float-vector 0 0 0)))
  (setq pl1- (instance plane :init
		       (float-vector 0 -1 -0.4) (float-vector 0 0 0)))
  (setq pl2+ (instance plane :init
		       (float-vector 1 0 0.4) (float-vector 0 0 0)))  
  (setq pl2- (instance plane :init
		       (float-vector -1 0 -0.4) (float-vector 0 0 0)))  
#|
  (setq b+1+ (body/ b+ pl1+))
  (setq b-1+ (body/ b- pl1+))
  (setq b+1- (body/ b+ pl1-))
  (setq b-1- (body/ b- pl1-))
  (setq b+2+ (body/ b+ pl2+))
  (setq b-2+ (body/ b- pl2+))
  (setq b+2- (body/ b+ pl2-))
  (setq b-2- (body/ b- pl2-))
|#
  )
;(draw-test)

(defun debug-hid nil
  (hid b+)
  (setq ei7 (elt *hid* 6))
  (setq e7 (edge-image-edge3 ei7))
  (setq e7pf (edge-pface e7))
  (setq e7nf (edge-nface e7))
  ;;
  (setq ei8 (elt *hid* 7))
  (setq e8 (edge-image-edge3 ei8))
  (setq e8pf (edge-pface e8))
  (setq e8nf (edge-nface e8))
  ;;
  (setq ei13 (elt *hid* 12))
  (setq e13 (edge-image-edge3 ei13))
  (setq e13pf (edge-pface e13))
  (setq e13nf (edge-nface e13))
  ;;
  (setq eis *contour-edge-images*)
  (setq ll
	(list
	 (elt eis 0)
	 (elt eis 1)
	 (elt eis 2)
	 (elt eis 3)
	 (elt eis 6)
	 (elt eis 7)
	 
	 (elt eis 4)
	 (elt eis 5)
	 (elt eis 11)
	 (elt eis 12)
	 (elt eis 16)
	 (elt eis 17)
	 
	 (elt eis 8)
	 (elt eis 9)
	 (elt eis 10)
	 (elt eis 13)
	 (elt eis 14)
	 (elt eis 15)
	 ))
  (setq vfis (mapcar #'(lambda (x)
			(face-image-edge-images x))
		    *visible-face-images*))
  (setq vfs (mapcar #'(lambda (x)
			(face-image-face3d x))
		    *visible-face-images*))
  (setq vfi6 (elt *visible-face-images* 5))
  (setq vfie6 (elt vfis 5))
  (setq vf6 (elt vfs 5))
  
  )
(defun load-koma nil
  (load "/usr/local/eus/koma/koma.body")
  (send-all (*koma* . edges)
	    :set-angle)
  (dolist (e (*koma* . edges))
	  (setf (edge-flags e) 0))
  (send-all (*koma* . edges)
	    :set-approximated-flag)
  
  )
