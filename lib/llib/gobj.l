;;;; graphics-object
;;;; (c)1995 June, Toshihiro Matsui, Electrotechnical Laboratory
;;;

(defparameter *drag-gc* (instance x:gcontext :create :function :xor))
(send *drag-gc* :foreground "black")
(defparameter *draw-gc* (instance x:gcontext :create))
(send *draw-gc* :foreground "black")
(defparameter *clear-gc* (instance x:gcontext :create :function :clear))

(defmacro intvec (&rest x) `(integer-vector . ,x))



(defclass graphics-object :super propertied-object
	:slots (point0 point1 width height color pattern
		drag-save highlighted dragging scaling))

(defclass gline :super graphics-object
)

(defclass garc :super graphics-object
	:slots (ang1 ang2))

(defclass grect :super graphics-object)

(defclass gtext :super graphics-object
	:slots (text-string font))

(defmethod graphics-object
 (:init (&rest args)
    (setq dragging nil)
    self)
 (:draw (vs &rest args)
     (format *error-output* "~a: ~a is subclass's responsibility~%"
	     (send self :name) selector)
      nil)
 (:area ()
   (let ((v (v- point0 point1)))
	%(v[0] * v[1])))
 (:color (&optional x)
    (if x (setq color x))
    color)
 (:pattern (&optional x)
    (if x (setq pattern x))
    pattern)
 (:finish-drag (vs)
    (when dragging
	(send self :highlight vs nil)
	(send self :draw vs *clear-gc* #| *drag-gc* |# )
	(send self :erase-previous-drag vs)
	(setf point0 (first dragging)
	      point1 (second dragging))
	(send self :draw vs)
	(send self :highlight vs t)
	(setq dragging nil) )
    )
 (:insidep (x y)
    (let ((v (intvec x y)))
	(or (and (v< point0 v) (v< v point1))
	    (and (v< point1 v) (v< v point0)))))
 (:highlight (vs &optional (switch t))
    (let ((v0 (v- point0 #i(2 2)))
	  (v1 (integer-vector (- (aref point0 0)2) (- (aref point1 1) 2)))
	  (v2 (integer-vector (- (aref point1 0)2) (- (aref point0 1) 2)))
	  (v3 (v- point1 #i(2 2)))
	  )
       (cond ((and switch (null highlighted))
	       (setq highlighted
		  (list (send vs :g-getimage 
				:xy v0	:width 5 :height 5)
			(send vs :g-getimage 
				:xy v1	:width 5 :height 5)
			(send vs :g-getimage 
				:xy v2	:width 5 :height 5)
			(send vs :g-getimage 
				:xy v3	:width 5 :height 5)))
	        (send vs :g-fill-rectangle v0 5 5)
	        (send vs :g-fill-rectangle v1 5 5)
	        (send vs :g-fill-rectangle v2 5 5)
	        (send vs :g-fill-rectangle v3 5 5)
		)
	     ((and (null switch) highlighted) ;erase rects at end points
		(send vs :g-putimage (first highlighted)
			:dst v0 :width 5 :height 5 :gc *draw-gc*)
		(send vs :g-putimage (second highlighted)
			:dst v1 :width 5 :height 5 :gc *draw-gc*)
		(send vs :g-putimage (third highlighted)
			:dst v2 :width 5 :height 5 :gc *draw-gc*)
		(send vs :g-putimage (fourth highlighted)
			:dst v3 :width 5 :height 5 :gc *draw-gc*)
		(setq highlighted nil)
		) )
	)  )
 (:included-in-rect (topleft bottomright)
   (let (v0 v1)
     (if (or (<= (aref point0 0) (aref point1 0))
	     (<= (aref point0 1) (aref point1 1)))
	 (setf v0 point0 v1 point1)
	 (setf v0 point1 v1 point0))
     (and (v< topleft v0) (v< v1 bottomright))))
 (:hit-corner (vs x y)
    (let ((v (integer-vector x y)))
       (cond ((< (distance v point0) 5) :topleft)
	     ((< (distance v (intvec %(point0[0]) %(point1[1]))) 5)
		 :bottomleft)
	     ((< (distance v (integer-vector (aref point1 0) (aref point0 1)))
			   5) :topright)
	     ((< (distance v point1) 5) :bottomright)
	     (t nil)))
	)
 (:begin-scale (vs x y)
    (let ((hit-corner (send self :hit-corner vs x y)))
	(case hit-corner
	   (:topleft (setq scaling	;point1 is pivot
			   (list point1 point0)))
	   (:bottomright (setq scaling	;point0 is pivot
			   (list point0 point1)))
	   (:topright (setq scaling
			(list (intvec (aref point0 0) (aref point1 1))
			      (intvec (aref point1 0) (aref point0 1)))))
	   (:bottomleft (setq scaling
			(list (intvec (aref point1 0) (aref point0 1))
			      (intvec (aref point0 0) (aref point1 1)))))
	   (t (setq scaling nil)))
	;; scaling is a list of four elements
	;; (hit-corner pivot origin-for-mouse moving-corner)
	(when scaling	
	    (setq scaling (list hit-corner (first scaling) (second scaling)
				(copy-seq (second scaling)))))
		))
 (:topleft-width-height (p0 p1)
    (let ((x0 %(min(p0[0] p1[0])))
	  (y0 %(min(p0[1] p1[1])))
	  (w  %(abs(p0[0] - p1[0])))
	  (h  %(abs(p0[1] - p1[1]))) )
      (list (intvec x0 y0) w h)))
 (:scale (vs dx dy)
    (when scaling
      (let ((v (integer-vector dx dy)) v2
	    (tlwh (send self :topleft-width-height
			(second scaling) (fourth scaling))))
	(send vs :g-rectangle (first tlwh) (second tlwh) (third tlwh)
				 *drag-gc*)
	(setq v2 (v+ (third scaling) v))
	;; corners might have changed
	(setq tlwh (send self :topleft-width-height (second scaling) v2))
;;	(print (list (second scaling) v2 tlwh))
	(send vs :g-rectangle (first tlwh) (second tlwh) (third tlwh) *drag-gc*)
	(setf ;(second scaling) (first tlwh)
	      (fourth scaling) v2))
	) ) 
 (:finish-scale (vs)
    (when scaling
	(send self :highlight vs nil)
	(send self :draw vs *clear-gc*)
	(setf point0 (second scaling) point1 (fourth scaling))
	(print (list point0 point1))
	(let ((tlwh (send self :topleft-width-height point0 point1)))
	   (setq point0 (first tlwh))
	   (setf width (second tlwh) height (third tlwh))
	   (setf point1 (v+ (first tlwh) (intvec width height))))
	(send self :draw vs)
	(send self :highlight vs t)
	(setq scaling nil)))
 )


(defmethod gline
 (:draw (vs &optional (g *draw-gc*))
    (if color (send g :foreground color))
    (send vs :g-line point0 point1 g))
 (:area () (distance point0 point1))
 (:point (p)
    (declare (float p))
    (midpoint p point0 point1)    )
 (:foot (point &aux (a (v- point0 point1)))
    (declare (type integer-vector point a))
    (/ (float (v. a (v- point0 point)))
       (v. a a)))
 (:distance (point)
    (let ((f (send self :foot point)))
	(cond ((< f 0.0) (distance point0 point))
	      ((> f 1.0) (distance point1 point))
	      (t (distance (send self :point f) point)))) )
 (:init (xs ys xe ye)
    (setq point0 (integer-vector xs ys)
	  point1 (integer-vector xe ye))
    self)
 (:hit (x y &optional (tolerance 3))
    (if (< (send self :distance (integer-vector x y)) tolerance)
	t
	nil))
 (:hit-corner (vs x y)
    (let ((v (integer-vector x y)))
       (cond ((< (distance v point0) 3) :topleft)
	     ((< (distance v point1) 3) :bottomright)
	     (t nil))))
 (:highlight (vs &optional (switch t))
    (let ((v0 (v- point0 #i(2 2)))
	  (v1 (v- point1 #i(2 2))))
       (cond ((and switch (null highlighted))
	       (setq highlighted
		  (list (send vs :g-getimage 
				:xy v0 :width 5 :height 5)
			(send vs :getimage 
				:xy v1 :width 5 :height 5)))
	       (send vs :g-fill-rectangle v0 5 5)
	       (send vs :g-fill-rectangle v1 5 5))
	     ((and (null switch) highlighted) ;erase rects at end points
		(send vs :g-putimage (first highlighted)
			:dst v0 :width 5 :height 5 :gc *draw-gc*)
		(send vs :g-putimage (second highlighted)
			:dst v1 :width 5 :height 5 :gc *draw-gc*)
		(setq highlighted nil)
		))
	)
  )
 (:erase-previous-drag (vs)
     (send vs :g-line (first dragging) (second dragging) *drag-gc*))
 (:drag (vs dx dy)
     (if dragging	;erase previous drag trace
	 (send self :erase-previous-drag vs))
     (let ((d (integer-vector dx dy)))
        (setq dragging (list (v+ point0 d) (v+ point1 d)))
        (send vs :g-line (first dragging) (second dragging)  *drag-gc*)))
 (:end-point (vs x y)
    (send self :draw vs *drag-gc*)
    (setq point1 (v+ point0 (integer-vector x y)))
    (send self :draw vs *drag-gc*)
    )
 (:begin-scale (vs x y)
    (let ((hit-corner (send self :hit-corner vs x y)))
	(case hit-corner
	   (:topleft (setq scaling	;point1 is pivot
			   (list hit-corner point1 point0 (copy-seq point0))))
	   (:bottomright (setq scaling	;point0 is pivot
			   (list hit-corner point0 point1 (copy-seq point1))))
	   (t (setq scaling nil)))))
 (:scale (vs dx dy)
    (when scaling
      (let ((v (integer-vector dx dy)))
	(send vs :g-line (second scaling) (fourth scaling) *drag-gc*)
	(v+ (third scaling) v (fourth scaling))
	(send vs :g-line (second scaling) (fourth scaling) *drag-gc*))) )
 (:finish-scale (vs)
    (when scaling
	(send self :highlight vs nil)
	(send self :draw vs *clear-gc*)
	(case (car scaling)
	  (:topleft (setq point0 (fourth scaling)))
	  (:bottomright (setq point1 (fourth scaling))))
	(send self :draw vs)
	(send self :highlight vs t)
	(setq scaling nil)))
 )

(defmethod grect
 (:draw (vs &optional (g *draw-gc*))
    (if color (send g :foreground color))
    (send vs :g-rectangle point0 width height g))
 (:init (x y w h)
    (setq point0 (integer-vector x y) width w height h
	  point1 (v+ point0 (integer-vector width height)))
    self)
 (:hit (x y)
    (send self :insidep x y))
 (:erase-previous-drag (vs)
    (send vs :g-rectangle (first dragging) width height *drag-gc*))
 (:drag (vs dx dy)
     (if dragging	;erase previous drag trace
	 (send self :erase-previous-drag vs))
     (let* ((d (integer-vector dx dy))
	    (np0 (v+ point0 d))
	    (np1 (v+ point1 d)))
        (setq dragging (list np0 np1))
	(send vs :g-rectangle np0 width height *drag-gc*)
	)	
  )
 (:end-point (vs x y)
    (send self :draw vs *drag-gc*)
    (setq width x height y)
    (setq point1 (v+ point0 (integer-vector x y)))
    (send self :draw vs *drag-gc*)
    )
)


(defmethod garc
 (:draw (vs &optional (g *draw-gc*))
    (if color (send g :foreground color))
    (send vs :g-arc point0 width height 0.0 2pi  g))
 (:init (x y w h)
    (setq point0 (integer-vector x y) width w height h
	  point1 (v+ point0 (integer-vector width height)))
    self)
#|
 (:insidep (x y)
    (<= (distance
	     (integer-vector x y)
	     (v+ (integer-vector (/ width 2) (/ height 2))  point0))
	(/ (min width height) 2)))
|#
 (:hit (x y)   (send self :insidep x y))
 (:erase-previous-drag (vs)
    (send vs :g-arc (first dragging) width height 0.0 2pi *drag-gc*) )
 (:drag (vs dx dy)
     (if dragging	;erase previous drag trace
	 (send self :erase-previous-drag vs))
     (let* ((d (integer-vector dx dy))
	    (np0 (v+ point0 d))
	    (np1 (v+ point1 d)))
        (setq dragging (list np0 np1))
	(send vs :g-arc np0 width height 0.0 2pi *drag-gc*)
	)
  )
 (:end-point (vs x y)
    (send self :draw vs *drag-gc*)
    (setq width x height y)
    (setq point1 (v+ point0 (integer-vector x y)))
    (send self :draw vs *drag-gc*)
    )
)


(defclass draw-canvas :super x:canvas
	:slots (gobjects vwidth vheight org
		mode	;(:select :scale :line :rect :circle)
		mouse-x mouse-y mouse-ox mouse-oy
		selected-items
		embryo))

(defmethod draw-canvas 	;creation
 (:create (&rest args
	   &key (virtual-width 512) (virtual-height 512)
		(origin-x 0) (origin-y 0)
	   &allow-other-keys)
    (send-super* :create args)
    (setq vwidth virtual-width
	  vheight virtual-height
	  org (integer-vector origin-x origin-y)
	  mode :select)
    self))

(defmethod draw-canvas		;coordinates transformation
 (:x (vx) (- vx (aref org 0)))	;virtual to window coords
 (:y (vy) (- vy (aref org 1)))
 (:xy (xy)  (v- xy org))
 (:vx (px) (+ px (aref org 0))) ;physical to virtual coords
 (:vy (py) (+ py (aref org 1)))
 (:translate (v) (v- v org))
 (:locate (x &optional y)
    (setq org
	  (if (integer-vector-p x)
	      x
	      (integer-vector x y)))
    self)
 (:move (x &optional y)
    (send self :locate (v+ org (if (integer-vector-p x) x (integer-vector x y))))
    self)
 (:g-line (start end &optional (g x::gcon))
     (send self :draw-line (v- start org) (v- end org) g))
 (:g-rectangle (pos width height &optional (g x::gcon))
     (send self :draw-rectangle (v- pos org) width height g))
 (:g-fill-rectangle (p width height &optional (g x::gcon))
     (send self :draw-fill-rectangle (v- p org) width height g))
 (:g-arc (pos width height ang1 ang2 &optional (g x::gcon))
     (send self :draw-arc (v- pos org) width height ang1 ang2 g))
 (:g-fill-arc (pos width height &optional (ang1 0.0) (ang2 2pi) (g x::gcon))
     (send self :draw-fill-arc (v- pos org) width height ang1 ang2 g))
 (:g-getimage (&rest args &key xy &allow-other-keys)
     (send* self :getimage :xy (v- xy org) args))
 (:g-putimage (img &rest args &key dst &allow-other-keys)
     (send* self :putimage img :dst (v- dst org) args))
)

(defmethod draw-canvas	; graphics object management
 (:add (item)
     (push item gobjects)
     item)
 (:remove (item)
     (setq gobjects (delete item gobjects))
     nil)
 (:remove-all () (setq gobjects nil))
 (:redraw (&rest args)
    (send self :clear)
    (send-all selected-items :highlight self nil)
    (send-all gobjects :draw self)
    (send-all selected-items :highlight self t))
)

;;
;; interaction & xevent handling
;;

(defmethod draw-canvas
 (:hit (x y)
    )
 (:buttonPress (event)
    (setf mouse-ox (x:event-x event)
	  mouse-oy (x:event-y event))
    (let ((x  (send self :vx mouse-ox))
	  (y  (send self :vy mouse-oy)) )
      (case mode
	(:select
	    (let ((hit))
	       (dolist (g gobjects)
		  (if (send g :hit mouse-ox mouse-oy) (push g hit)))
	       (cond
		  ((member :shift (x:event-state event))
		   (setq selected-items (append hit selected-items))
		   (send-all hit :highlight self t))
		  ((and hit (intersection hit selected-items))
		   (when (some #'(lambda (x)
				   (send x :hit-corner self mouse-ox mouse-oy))
			     (union hit selected-items))
		       (setq mode :scale)
			(send-all selected-items :begin-scale
				 self mouse-ox mouse-oy)) )
		  (hit
		   (send-all selected-items :highlight self nil)
	     	   (setq selected-items hit) 
		   (send-all selected-items :highlight self t))
		  (t 
		   (send-all selected-items :highlight self nil)
		   (setq selected-items nil)
		   (send-super :buttonPress event))
		)))
	(:line  (setq embryo
		      (instance gline :init x y x y))) 
	(:rect  (setq embryo
		      (instance grect :init x y 0 0))) 
	(:circle (setq embryo
		      (instance garc :init x y 0 0))) 
	  ) )
    )
 (:motionnotify (event)
     (setq mouse-x (- (x:event-x event) mouse-ox)
	   mouse-y (- (x:event-y event) mouse-oy))
     (case mode
	(:select
	    (if selected-items
		(send-all selected-items :drag self mouse-x mouse-y)
		(send-super :motionnotify event)))
	(:scale (send-all selected-items :scale self mouse-x mouse-y))
	(:line (send embryo :end-point self mouse-x mouse-y))
	(:rect (send embryo :end-point self mouse-x mouse-y))
	(:circle (send embryo :end-point self mouse-x mouse-y))
	))
 (:buttonRelease (event)
    (case mode
	(:select
	    (if selected-items
		(progn
		    (send-all selected-items :finish-drag self))
		(progn 
		    (send-super :buttonRelease event)
		    (dolist (g gobjects)
			(if (send g :included-in-rect x::topleft x::bottomright)
			    (push g selected-items)))
		    (send-all selected-items :highlight self t)
		)))
	(:scale (send-all selected-items :finish-scale self)
		(setq mode :select))
	((:line :rect :circle)
	    (if (> (send embryo :area) 4)
	        (send self :add embryo))
	    (setq embryo nil))
	  )
    )
 (:draw-mode (m)
    (when (and (eq mode :select) (not (eq m :select)))
	(send-all selected-items :highlight self nil)
	(setq selected-items nil))
    (setq mode (print m)))
 (:select-all (event)
    (setq selected-items (copy-seq gobjects))
    (send-all selected-items :highlight self t))
 (:delete (event)
    (send-all selected-items :highlight self nil)
    (send-all selected-items :draw self *clear-gc*)
    (dolist (d selected-items) (send self :remove d))
    (setq selected-items nil))
 )


(defclass draw-panel :super x:panel
	:slots (gobj-panel attr-panel draw-can))

(defmethod draw-panel
 (:create (&rest args)
    (send-super* :create :width 362 :height 332 args)
    (setq gobj-panel (instance x:panel :create :parent self
			:x 0 :y 0 :width 40 :height 330
			:border-width 0))
    (setq attr-panel (instance x:panel :create :parent self
			:x 41 :y 0 :width 300 :height 30
			:border-width 0))
    (setq draw-can (instance draw-canvas :create :parent self
			:x 41 :y 31 :width 320 :height 300
			:background "white"))
    (send gobj-panel :create-item
	   x:bitmap-button-item "xwindow/bitmaps/selectarrow.xbm"
		 draw-can (list :draw-mode :select))
    (send gobj-panel :create-item
	   x:bitmap-button-item "xwindow/bitmaps/line.xbm"
		 draw-can (list :draw-mode :line))
    (send gobj-panel :create-item
	   x:bitmap-button-item "xwindow/bitmaps/rectangle.xbm"
		 draw-can (list :draw-mode :rect))
    (send gobj-panel :create-item
	   x:bitmap-button-item "xwindow/bitmaps/circle.xbm"
		 draw-can (list :draw-mode :circle))
    (send gobj-panel :create-item
	   x:button-item "Del" draw-can :delete)
    (send gobj-panel :create-item
	   x:button-item "R" draw-can :redraw)
    (send gobj-panel :create-item
	   x:button-item "A" draw-can :select-all)
    (send gobj-panel :create-item
	   x:button-item "Q" self :quit)
    self))

(eval-when (load eval)
	(setq dp (instance draw-panel :create))
	(setq dc (dp . draw-can))
	(defun wml () (x:window-main-loop))
	(wml) )

