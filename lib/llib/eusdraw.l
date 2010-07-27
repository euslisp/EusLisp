;;;; graphic-object
;;;; (c)1995 June, Toshihiro Matsui, Electrotechnical Laboratory
;;;

(defparameter *drag-gc* (instance x:gcontext :create :function :xor))
(send *drag-gc* :foreground "black")

(defparameter *draw-gc* (instance x:gcontext :create))
(send *draw-gc* :foreground "black")

(defparameter *fill-gc* (instance x:gcontext :create))
(send *fill-gc* :fill-style 0)	;solid

(defparameter *clear-gc2* (instance x:gcontext :create :function :clear))

;(defparameter *red-gc* (x:make-color-gc "red"))
;(defparameter *green-gc* (x:make-color-gc "green"))
;(defparameter *blue-gc* (x:make-color-gc "blue"))

(defparameter *pattern-pixmaps*
	(list
        	(list :transparent	nil)
		(list :blank      	nil)
		(list :black      	t)
		(list :gray75     	x:*gray75-bitmap*)
		(list :gray50	  	x:*gray50-bitmap*)
		(list :gray25	  	x:*gray25-bitmap*))
      )

(defmacro intvec (&rest x) `(integer-vector . ,x))



(defclass graphic-object :super propertied-object
	:slots (point0 point1 width height
		color		;foreground color pixel
		fill-style	;0-solid, 2-translucent, 3-opaque
		pattern		;fill-pattern if fill-style=2 or 3
		drag-save highlighted dragging scaling))

(defclass gline :super graphic-object
	:slots (arrow arrow-size))

(defclass garc :super graphic-object
	:slots (ang1 ang2))

(defclass grect :super graphic-object)

(defclass gtext :super graphic-object
	:slots (text-string font))

(defmethod graphic-object
 (:init (&rest args)
    (setq dragging nil)
    (setq fill-style nil)	;transparent
    (setq color (send x:*color-map* :get-pixel "black"))
    self)
 (:width (&optional w)
    (when w
	(setq width w)
	%(point1[0] = point0[0] + width))
    width)
 (:height (&optional h)
    (when h
	%(height = h)
	%(point1[1] = point0[1] + height))
    height)
 (:draw (vs &rest args)
     (format *error-output* "~a: ~a is subclass's responsibility~%"
	     (send self :name) selector)
      nil)
 (:area ()
   (let ((v (v- point0 point1)))
	%(v[0] * v[1])))
 (:color (&optional pix)
    (cond ((null pix) color)
	  ((or (stringp pix)(symbolp pix))
	   (setq color (send x:*color-map* :get-pixel pix))
	    color)))
 (:pattern (&optional x)
    (if x (setq pattern x))
    pattern)
 (:fill-style (&optional x)
    (if x
        (setq fill-style
	  (case x
		(:transparent	nil)
		(:solid		0)
		(:translucent   2)
		(:opaque	3))))
    fill-style)
)

(defmethod graphic-object
 (:point0 () point0)
 (:point1 () point1)
 (:change-start-end (xs ys xe ye)
    (setf (aref point0 0) xs
	  (aref point0 1) ys
	  (aref point1 0) xe
	  (aref point1 1) ye)
    self)
 (:insidep (x y)
    (let ((v (intvec x y)))
	(or (and (v< point0 v) (v< v point1))
	    (and (v< point1 v) (v< v point0)))))
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
 (:overlap-p (g)
    (let ((gp0 (send g :point0)) (gp1 (send g :point1)))
	(and (v< point0 gp1) (v< gp0 point1))) )
 )

(defmethod graphic-object
 (:finish-drag (vs)
    (when dragging
	(send self :highlight vs nil)
	(send self :erase-previous-drag vs)
	(send self :draw vs :clear)
	(setf point0 (first dragging)
	      point1 (second dragging))
	(send self :draw vs)
	(send self :highlight vs t)
	(setq dragging nil) )
    )
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
			:dst v0 :width 5 :height 5 :gc *fill-gc*)
		(send vs :g-putimage (second highlighted)
			:dst v1 :width 5 :height 5 :gc *fill-gc*)
		(send vs :g-putimage (third highlighted)
			:dst v2 :width 5 :height 5 :gc *fill-gc*)
		(send vs :g-putimage (fourth highlighted)
			:dst v3 :width 5 :height 5 :gc *fill-gc*)
		(setq highlighted nil)
		) )
	)  )
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
	(send vs :g-rectangle (first tlwh) (second tlwh) (third tlwh)
			 *drag-gc*)
	(setf ;(second scaling) (first tlwh)
	      (fourth scaling) v2))
	) ) 
 (:finish-scale (vs)
    (when scaling
	(send self :highlight vs nil)
	(send self :draw vs :clear)
	(setf point0 (second scaling) point1 (fourth scaling))
;;	(print (list point0 point1))
	(let ((tlwh (send self :topleft-width-height point0 point1)))
	   (setq point0 (first tlwh))
	   (setf width (second tlwh) height (third tlwh))
	   (setf point1 (v+ (first tlwh) (intvec width height))))
	(send self :draw vs)
	(send self :highlight vs t)
	(setq scaling nil)))
 )


(defmethod gline
 (:draw (vs &optional (func :copy))
    (send *draw-gc* :function func)
    (if color (send *draw-gc* :foreground color))
    (cond ((derivedp (cadr pattern) x:xpixmap)
	   (send *draw-gc* :stipple (cadr pattern)) )
	 (t
	  (send *draw-gc* :fill-style 0)	;solid
	  ))
    (if fill-style
	    (send *draw-gc* :fill-style fill-style))
    (send vs :g-line point0 point1 *draw-gc*)
    (when (member :start arrow)
       (let* ((a (coerce (v- point0 point1) float-vector))
	      (b))
	  (setq b (scale arrow-size 
			 (normalize-vector (rotate-vector a 0.5 nil))))
	  (send vs :g-line point0 (v- point0 (coerce b integer-vector))
			*draw-gc*)
	  (setq b (scale arrow-size 
			 (normalize-vector (rotate-vector a -0.5 nil))))
	  (send vs :g-line point0 (v- point0 (coerce b integer-vector))
			*draw-gc*)))
    (when (member :end arrow)
       (let* ((a (coerce (v- point1 point0) float-vector))
	      (b))
	  (setq b (scale arrow-size 
			 (normalize-vector (rotate-vector a 0.5 nil))))
	  (send vs :g-line point1 (v- point1 (coerce b integer-vector))
			*draw-gc*)
	  (setq b (scale arrow-size 
			 (normalize-vector (rotate-vector a -0.5 nil))))
	  (send vs :g-line point1 (v- point1 (coerce b integer-vector))
			*draw-gc*)))
    )
 (:arrow (&optional x sz)
    (when x
	(pushnew x arrow)
	(setq arrow-size (if sz sz 7))))
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
    (send-super :init)
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
			:dst v0 :width 5 :height 5 :gc *fill-gc*)
		(send vs :g-putimage (second highlighted)
			:dst v1 :width 5 :height 5 :gc *fill-gc*)
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
    (send self :draw vs :xor)
    (setq point1 (v+ point0 (integer-vector x y)))
    (send self :draw vs :xor)
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
	(send self :draw vs :clear)
	(case (car scaling)
	  (:topleft (setq point0 (fourth scaling)))
	  (:bottomright (setq point1 (fourth scaling))))
	(send self :draw vs)
	(send self :highlight vs t)
	(setq scaling nil)))
 )

(defmethod grect
 (:draw (vs &optional (func :copy))
    (send *draw-gc* :function func)
    (if color (send *draw-gc* :foreground color))
    (cond ((derivedp (cadr pattern) x:xpixmap)
	   (send *draw-gc* :stipple (cadr pattern)) )
	 (t
	  (send *draw-gc* :fill-style 0)	;solid
	  ))
    (cond (fill-style
	    (send *draw-gc* :fill-style fill-style)
	    (send vs :g-fill-rectangle point0 width height *draw-gc*))
	  (t  
	   (send vs :g-rectangle point0 width height *draw-gc*))))
 (:init (x y w h)
    (send-super :init)
    (setq point0 (integer-vector x y) width w height h
	  point1 (v+ point0 (integer-vector width height)))
    self)
 (:clear (vs)
    (send vs :g-fill-rectangle point0 width height *clear-gc2*))
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
    (send self :draw vs :xor)
    (setq width x height y)
    (setq point1 (v+ point0 (integer-vector x y)))
    (send self :draw vs :xor)
    )
 (:polygon2d ()
    (instance polygon2d :init
	(list (float-vector (aref point0 0) (aref point0 1))
	      (float-vector (aref point1 0) (aref point0 1))
	      (float-vector (aref point1 0) (aref point1 1))
	      (float-vector (aref point0 0) (aref point1 1)))))
)


(defmethod garc
 (:draw (vs &optional (func :copy))
    (send *draw-gc* :function func)
    (if color (send *draw-gc* :foreground color))
    (cond (fill-style
	    (send *draw-gc* :fill-style fill-style)
	    (cond ((derivedp (cadr pattern) x:xpixmap)
		   (send *draw-gc* :stipple (cadr pattern)) )
		 (t
		  (send *draw-gc* :fill-style 0)	;solid
		  ))
	   (send vs :g-fill-arc point0 width height 0.0 2pi *draw-gc*))
	  (t  
	   (send *draw-gc* :fill-style 0)
	   (send vs :g-arc point0 width height 0.0 2pi *draw-gc*))))
 (:init (x y w h)
    (send-super :init)
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
    (send self :draw vs :xor)
    (setq width x height y)
    (setq point1 (v+ point0 (integer-vector x y)))
    (send self :draw vs :xor)
    )
)


(defclass gpolygon :super graphic-object
	:slots (vertices last-point tentative pivot close))

(defmethod gpolygon
 (:init (&rest points)
    (setq vertices points)
    (send self :set-rectangle)
    (setq last-point (car (last vertices)))
    (setq tentative last-point)
    (setq pivot last-point)
    self)
 (:set-rectangle ()
    (setq point0 (apply #'vmin vertices)
	  point1 (apply #'vmax vertices))
    self)
 (:set-pivot (x y) (setq pivot (integer-vector x y)))
 (:add-point (vs)
    (setq vertices (nconc vertices (list tentative)))
    (send self :set-rectangle)
    (setq last-point tentative)
    (print vertices))
 (:erase-last (vs)
    (send vs :g-line last-point tentative *drag-gc*)
    )
 (:next-point (vs x y)
    (send self :erase-last vs)
    (setq tentative (v+ pivot (integer-vector x y)))
    (send vs :g-line last-point tentative *drag-gc*) )
 (:close ()
    (setq vertices (append vertices (list (car vertices)))))
 (:finish-add ()
    (print vertices)
    (if close (send self :close))
    self)
 (:hit (x y)
    (print (list x y))
    nil)
 (:draw (vs &optional (func :copy))
    (send *draw-gc* :function func)
    (if color (send *draw-gc* :foreground color))
    (cond (fill-style
	    (send *draw-gc* :fill-style fill-style)
	    (cond ((derivedp (cadr pattern) x:xpixmap)
		   (send *draw-gc* :stipple (cadr pattern)) )
		 (t
		  (send *draw-gc* :fill-style 0)	;solid
		  ))
	   (let ((verts vertices))
	      (while (cdr verts)
		 (send vs :g-line (car verts) (cadr verts) *draw-gc*)
		 (setq verts (cdr verts)))))
	  (t  
	   (send *draw-gc* :fill-style 0)
	   (let ((verts vertices))
	      (while (cdr verts)
		 (send vs :g-line (car verts) (cadr verts) *draw-gc*)
		 (setq verts (cdr verts)))))
	)   )
 (:polygon2d ()
    (let (v3d)
      (dolist (v vertices)
	 (push (coerce v float-vector) v3d))
      (instance polygon2d :init v3d))
    )
 )

(defun distance-p2l (point0 point1 point2)	; point(p) to line(p1-p2)
   (let* ((a (v- point1 point2))
	  (foot  (/ (float (v. a (v- point1 point0)))
		    (v. a a))))
      (cond ((< foot 0.0) (distance point1 point0))
	    ((> foot 1.0) (distance point2 point0))
	    (t (distance point0 (midpoint foot point1 point2))))
      ))

(defmethod gpolygon
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
 (:hit (x y &optional (tolerance 3))
    (if (< (send self :distance (integer-vector x y)) tolerance)
	t
	nil))

)


(defclass draw-canvas :super x:canvas
	:slots (gobjects vwidth vheight org
		zoom
		mode	;(:select :scale :line :rect :circle)
		mouse-x mouse-y mouse-ox mouse-oy
		selected-items
		click-time
		embryo
		scroll-bar-window horizontal-scroll-bar-window
		))

(defmethod draw-canvas 	;creation
 (:create (&rest args
	   &key (virtual-width 1024) (virtual-height 1024)
		(origin-x 0) (origin-y 0)
	   &allow-other-keys)
    (send-super* :create args)
    (setq vwidth virtual-width
	  vheight virtual-height
	  org (integer-vector origin-x origin-y)
	  mode :select
	  zoom 1.0
	  click-time most-negative-float)
    (setq scroll-bar-window
	  (instance x:Xscroll-bar :create
			:width 13 :height (1- x::height)
			:parent self
			:gravity :northeast))
    (setq horizontal-scroll-bar-window
		(instance x:Xhorizontal-scroll-bar :create
			:width (if scroll-bar-window 
				   (- x::width
				      (send scroll-bar-window :width) 4)
				   x::width)
			:height 12
			:parent self
			:gravity :southwest))
    (send self :locate-scroll-bar )
    self)
 (:locate-scroll-bar ()
    (when scroll-bar-window
	(send scroll-bar-window :resize 13 (1- x::height))
	(send scroll-bar-window :move
		(- x::width (send scroll-bar-window :width) 2) 0)
	;(setq win-col-max (/ (- x::width (send scroll-bar-window :width) 4)
	;		     x::charwidth))
	  )
    (when horizontal-scroll-bar-window
	(send horizontal-scroll-bar-window :resize 
		(if scroll-bar-window
		   (- x::width (send scroll-bar-window :width) 4)
		   x::width)
		12)
	(send horizontal-scroll-bar-window :move
		0
		(- x::height
		   (send horizontal-scroll-bar-window :height) 1))
	;(setq win-row-max
	;	(/ (- x::height
	;	      (send horizontal-scroll-bar-window :height) 2)
	;	     x::charheight))
	) )
 (:win-row-max ()  (send self :height))
 (:win-col-max ()  (send self :width))
 (:scroll-fraction () (/ 1.0 vheight zoom))
 (:horizontal-scroll-fraction () (/ 1.0 vwidth zoom))
 (:scroll (n)
   (if (floatp n) (setq n (* vheight n #|zoom|# )))
   (setq n
	 (if (< n 0)
	     (- (min (aref org 1) (abs n)))
	     (max 0 (min (- vheight (aref org 1) (/ x::height zoom))  n))))
   (setq n (round n))
   (incf (aref org 1) n)
   (if (/= n 0)  (send self :redraw))
    )
 (:horizontal-scroll (n)
   (if (floatp n) (setq n (* vwidth n #|zoom|#)))
   (setq n
	 (if (< n 0)
	     (- (min (aref org 0) (abs n)))
	     (max 0 (min (- vwidth (aref org 0) (/ x::width zoom))  n))))
   (setq n (round n))
   (incf (aref org 0) n)
   (send self :redraw)
    )
)

(defmethod draw-canvas		;coordinates transformation
 (:x (vx) (round (* zoom (- vx (aref org 0)))))	;virtual to physical window coords
 (:y (vy) (round (* zoom (- vy (aref org 1)))))
 (:xy (xy)  (scale zoom (v- xy org)))
 (:vx (px) (round (+ (/ px zoom) (aref org 0)))) ;physical to virtual coords
 (:vy (py) (round (+ (/ py zoom) (aref org 1))))
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
 (:zoom (&optional z) (if (numberp z) (setq zoom z)) zoom)
 (:g-line (start end &optional (g x::gcon))
     (send self :draw-line (scale zoom (v- start org))
			   (scale zoom (v- end org)) g))
 (:g-rectangle (pos width height &optional (g x::gcon))
     (send self :draw-rectangle (scale zoom (v- pos org))
			(round (* zoom width)) (round (* zoom height)) g))
 (:g-fill-rectangle (p width height &optional (g x::gcon))
     (send self :draw-fill-rectangle (scale zoom (v- p org))
			(round (* zoom width)) (round (* zoom height)) g))
 (:g-arc (pos width height ang1 ang2 &optional (g x::gcon))
     (send self :draw-arc (scale zoom (v- pos org))
			(round (* zoom width)) (round (* zoom height)) ang1 ang2 g))
 (:g-fill-arc (pos width height &optional (ang1 0.0) (ang2 2pi) (g x::gcon))
     (send self :draw-fill-arc (scale zoom (v- pos org))
			(round (* zoom width)) (round (* zoom height))
			ang1 ang2 g))
 (:g-string (pos str &optional (start 0) (end (length str)) (g x::gcon))
     (send self :draw-string (scale zoom (v- pos org))
			str start end g))
 (:g-getimage (&rest args &key xy width height &allow-other-keys)
    (let ((xy (scale zoom (v- xy org)))
	  (w (round (* zoom width)))
	  (h (round (* zoom height)))
	  (wh (intvec x::width x::height)))
     (when (and (v> xy #i(0 0)) (v< (v+ xy (intvec w h)) wh))
        (send* self :getimage :xy xy :width w :height h args)) ))
 (:g-putimage (img &rest args &key dst width height &allow-other-keys)
    (let ((xy (scale zoom (v- dst org)))
	  (w (round (* zoom width)))
	  (h (round (* zoom height)))
	  (wh (intvec (x::xwindow-width self) (x::xwindow-height self))) )
     (when (and (v> xy #i(0 0)) (v< (v+ xy (intvec w h)) wh))
       (send* self :putimage img :dst xy  :width w  :height h args))) )
)

(defmethod draw-canvas	; graphics object management
 (:add (item)
     (if (consp item)
	 (dolist (i item) (send self :add i))
	 (pushnew item gobjects))
     item)
 (:remove (item)
     (setq gobjects (delete item gobjects))
     nil)
 (:remove-all () (setq gobjects nil))
 (:redraw (&rest args)
    (send self :clear)
    (if scroll-bar-window
       (send scroll-bar-window :move-handle
		(/  (float (aref org 1)) vheight)
		(min 1.0 (/ x::height zoom vheight))))
    (if horizontal-scroll-bar-window
	(send horizontal-scroll-bar-window :move-handle
		(/  (float (aref org 0)) vwidth)
		(min 1.0 (/  x::width zoom vwidth))))
    (send-all selected-items :highlight self nil)
    (send-all gobjects :draw self)
    (send-all selected-items :highlight self t))
 (:gobjects (&optional x)
    (if x (setq gobjects x))
    gobjects)
 (:selected-items () selected-items)
)

;;
;; interaction & xevent handling
;;

(defmethod draw-canvas
 (:double-click (event)
    (print (list :double-click mode))
    (case mode
	(:polygon (send embryo :finish-add)
	    (send self :add embryo)
	    (setq embryo nil)
	    t)
	(t nil))
    )
 (:buttonPress (event)
    (setf mouse-ox (x:event-x event)
	  mouse-oy (x:event-y event))
    (let ((x  (send self :vx mouse-ox))
	  (y  (send self :vy mouse-oy)) 
	  (ctime (/ (x::event-time event) 1000.0)))
      (if (< (- ctime click-time) 0.4)
	  (progn (setq click-time ctime)
		 (if (print (send self :double-click event))
		     (return-from :buttonPress nil)))
	  (setq click-time ctime))
      (case mode
	(:select
	    (let ((hit))
	       (dolist (g gobjects)
		  (if (send g :hit x y) (progn (push g hit) (return nil))))
	       (cond
		  ((member :shift (x:event-state event))
		   (setq selected-items (append hit selected-items))
		   (send-all hit :highlight self t))
		  ((and hit (intersection hit selected-items))
		   (when (some #'(lambda (g)
				   (send g :hit-corner self x y))
			     (union hit selected-items))
		       (setq mode :scale)
			(send-all selected-items :begin-scale
				 self x y)) )
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
	(:polygon (cond
		     (embryo
			(send embryo :set-pivot x y)
			(send self :motionnotify event))
		     (t
			(setq embryo
		              (instance gpolygon :init (integer-vector x y)))
		  ) )
	 ))
;    (print embryo)
    ))
 (:motionnotify (event)
   (setq mouse-x (- (x:event-x event) mouse-ox)
	 mouse-y (- (x:event-y event) mouse-oy))
   (let ((x  (round (/ mouse-x zoom)))
	 (y  (round (/ mouse-y zoom))) )
     (case mode
	(:select
	    (if selected-items
		(send-all selected-items :drag self x y)
		(send-super :motionnotify event)))
	(:scale (send-all selected-items :scale self x y))
	(:line (send embryo :end-point self x y))
	(:rect (send embryo :end-point self x y))
	(:circle (send embryo :end-point self x y))
	(:polygon (if embryo (send embryo :next-point self x y)))
	)))
 (:buttonRelease (event)
    (case mode
	(:select
	    (if selected-items
		(progn
		    (send-all selected-items :finish-drag self)
		    (send self :redraw))
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
	(:polygon 
	    (if embryo (send embryo :add-point self)))
	  ) 
    ))

(defmethod draw-canvas
 (:draw-mode (m)
    (when (and (eq mode :select) (not (eq m :select)))
	(send-all selected-items :highlight self nil)
	(setq selected-items nil))
    (setq mode  m))
 (:select-all (event)
    (setq selected-items (copy-seq gobjects))
    (send-all selected-items :highlight self t))
 (:delete (event)
    (send-all selected-items :highlight self nil)
    (send-all selected-items :draw self :clear)
    (dolist (d selected-items) (send self :remove d))
    (setq selected-items nil))
 (:Zoom-in (event) (setq zoom (* zoom 2.0)) (send self :redraw))
 (:Zoom-out (event) (setq zoom (* zoom 0.5)) (send self :redraw))
 (:color (k)
    (send-all selected-items :color k)
    (send-all selected-items :draw self))
 (:pattern (k)
    (let (g)
        (setq g (assoc k *pattern-pixmaps*))
	(when g
;;	   (print g)
	   (dolist (s selected-items)
		(if (null (send s :fill-style))
		    (send s :fill-style :opaque))
		(send s :pattern g)
		(send s :draw self)))))
 (:fill-style (k)
    (send-all selected-items :fill-style k)
    ;(send-all selected-items :draw self)
    (send self :redraw))
 (:dupe-selection (event)
    (let ((copy (copy-object selected-items)))
	(send self :add copy)
	(setq selected-items copy)
	copy) )
 (:copy-selection (event)
    (setq gcopy (copy-object selected-items)))
 (:paste-selection (event)
    (send self :add gcopy)
    (setq selected-items gcopy))
 (:print-selection (event)
    (print selected-items)
     )
 (:describe-selection (event)
    (let ((sout (make-string-output-stream)) tview)
        (describe-list selected-items sout)
	(setq tview (instance x:textviewpanel :create
			:width 330 :height 250 :font x::font-cour10))
	(send (x::textviewpanel-view-window tview)
		 :display-line-string (get-output-stream-string sout))))
 )

(defmethod draw-canvas
 (:union (event)
    (let ((r (send (send (first selected-items) :polygon2d) :3d))
	  verts  newpoly)
       (dolist (s (rest selected-items))
	  (setq r (car (face+ r  (send (send s :polygon2d) :3d)))))
       (setq *f* r)
       (dolist  (v3d (cdr (send r :vertices)))
	  (push (integer-vector (round (aref v3d 0)) (round (aref v3d 1))) verts) )
       (setq newpoly (instance* gpolygon :init (nreverse verts)))
       (send newpoly :close)
       (send self :delete event)
       (send self :add newpoly)
       (setq selected-items (list newpoly))
	(send self :redraw) ))
 )


(defclass draw-panel :super x:panel
	:slots (gobj-panel attr-panel draw-can
		menubar filemenu editmenu optmenu modelmenu
		;;;;
		okNotiry cancelNotify))

(defmethod draw-panel	;creation
 (:create (&rest args &key ok-notify (cancel-notify ok-notify)
		      &allow-other-keys)
    (send-super* :create :width 500 :height 450
			:event-mask '(:configure) args)
    (setq okNotify ok-notify
	  cancelNotify cancel-notify)
;; subwindows
;; menu bar
    (setq menubar    (send self :create-menubar :height 30 :width 300))
;; graphics object panel at the left
    (setq gobj-panel (instance x:panel :create :parent self
			:x 0 :y 32
			:width 40 :height (- x::height 2)
			:border-width 0))
;; attribute panel above
    (setq attr-panel (instance x:panel :create :parent self
			:x 41 :y 32
			:width (- x::width 42) :height 30
			:border-width 0))
;; drawing canvas
    (setq draw-can (instance draw-canvas :create :parent self
			:x 41 :y 64
			:width (- x::width 42) :height (- x::height 68)
			:background "white"))
;; menus
    (setq filemenu (instance x:menu-panel :create))
      (send filemenu :create-item x:button-item "Open" self nil)
      (send filemenu :create-item x:button-item "Close" self nil)

    (setq editmenu (instance x:menu-panel :create))
      (send editmenu :create-item x:button-item "Paste" draw-can :paste-selection)
      (send editmenu :create-item x:button-item "Copy" draw-can :copy-selection)
      (send editmenu :create-item x:button-item "Del" draw-can :delete)
      (send editmenu :create-item x:button-item "Dupe" draw-can :dupe-selection)
      (send editmenu :create-item x:button-item "All" draw-can :select-all)

    (setq optmenu (instance x:menu-panel :create))
      (send optmenu :create-item x:button-item "Print Sel" 
		draw-can :print-selection)
      (send optmenu :create-item x:button-item "Describe" 
		draw-can :describe-selection)
      (send optmenu :create-item x:button-item "Redraw" draw-can :redraw)

    (setq modelmenu (instance x:menu-panel :create))
      (send modelmenu :create-item x:button-item "Union" 
		draw-can :union)
      (send modelmenu :create-item x:button-item "Intersection"
		draw-can :intersection)

    (send menubar :create-item x:menu-button-item
		"File" self  nil :menu filemenu)
    (send menubar :create-item x:menu-button-item
		"Edit" self  nil :menu editmenu)
    (send menubar :create-item x:menu-button-item
		"Option" self  nil :menu optmenu)
    (send menubar :create-item x:menu-button-item
		"Model" self  nil :menu modelmenu)
;;
    (send self :create-item x:text-item "name:" self :label
		:y 4
		:columns 15 :font x::font-courb12)
;;
    (send gobj-panel :create-item
	   x:bitmap-button-item "selectarrow.xbm"
		 draw-can (list :draw-mode :select))
    (send gobj-panel :create-item
	   x:bitmap-button-item "line.xbm"
		 draw-can (list :draw-mode :line))
    (send gobj-panel :create-item
	   x:bitmap-button-item "rectangle.xbm"
		 draw-can (list :draw-mode :rect))
    (send gobj-panel :create-item
	   x:bitmap-button-item "circle.xbm"
		 draw-can (list :draw-mode :circle))
    (send gobj-panel :create-item
	   x:bitmap-button-item "polygon.xbm"
		 draw-can (list :draw-mode :polygon))
    (send gobj-panel :create-item
	   x:bitmap-button-item "zoomin.xbm"
	   draw-can :zoom-in)
    (send gobj-panel :create-item
	   x:bitmap-button-item "zoomout.xbm"
	   draw-can :zoom-out)
    (send gobj-panel :create-item
	   x:bitmap-button-item "home.xbm" self :home)
    ;; pattern buttons
    (send attr-panel :create-item
	   x:bitmap-button-item "star.xbm"
		 draw-can (list :fill-style :transparent))
    (send attr-panel :create-item
	   x:bitmap-button-item "translucent.xbm"
		 draw-can (list :fill-style :translucent))
    (send attr-panel :create-item
	   x:bitmap-button-item "opaque.xbm"
		 draw-can (list :fill-style :opaque))
    (send attr-panel :create-item
	   x:bitmap-button-item "fill.xbm"
		 draw-can (list :fill-style :solid))
    (send attr-panel :create-item
	   x:bitmap-button-item "gray50.xbm"
		 draw-can (list :pattern :gray50))
    (send attr-panel :create-item
	   x:bitmap-button-item	"gray25.xbm"
		 draw-can (list :pattern :gray25))
    ;; color buttons
    (send attr-panel :create-item x:bitmap-button-item
		 "fill.xbm" draw-can (list :color :white)
		  :foreground "white")
    (send attr-panel :create-item x:bitmap-button-item
		 "fill.xbm" draw-can (list :color :red)
		  :foreground "red")
    (send attr-panel :create-item x:bitmap-button-item
		 "fill.xbm" draw-can (list :color :green)
		  :foreground "green")
    (send attr-panel :create-item x:bitmap-button-item
		 "fill.xbm" draw-can (list :color :blue)
		  :foreground "blue")	
    (send attr-panel :create-item x:bitmap-button-item
		 "fill.xbm" draw-can (list :color :black)
		  :foreground "black")	
    self)
)


(defmethod draw-panel
 (:canvas () draw-can)
 (:gobjects (&optional x) (send draw-can :gobjects x))
 (:resize (w h)
    (send gobj-panel :resize 42 h)
    (send attr-panel :resize (- w 41) 30)
    (send draw-can :resize (- w 42) (- h 64))
    (send draw-can :locate-scroll-bar)
    (send draw-can :redraw))
 (:ConfigureNotify (event)
    (let ((newwidth (send self :width)) (newheight (send self :height)))
	(when (or (/= newwidth x::width) (/= newheight x::height))
	    (send self :resize newwidth newheight))))
 (:home (event)
    (cond (oknotify
	    (send self :unmap)
	    (let (f facesets)
		(dolist (p (send draw-can :gobjects))
		    ;; convert gpolygon to 3d face
		    (setq f (send (send p :polygon2d) :3d 0.0 face))
		    (push (instance faceset :init :faces (list f)) facesets) )
	        (send* (car oknotify) (cadr oknotify)
			facesets (cddr oknotify))  ) )
	  (t  (send self :quit event)) ) 
   )
 )

#|
(eval-when (load eval)

	(setq dp (instance draw-panel :create) 
	      *eusdraw* dp)
	(setq dc (send dp :canvas))
	(defun wml () (x:window-main-loop))

	; (wml)
	)
|#

(provide :eusdraw "#(@)$Id: eusdraw.l,v 1.1.1.1 2003/11/20 07:53:25 eus Exp $")

