;;;; polygon.l
;;;; 2 dimensional polygons
;;;  created in 1991 at Stanford
;;;  built-in euslisp in 1996
;;;  (c) 1996, Toshihiro Matsui, Electrotechnical Laboratory

(export '(polygon2d make-rectangle make-polygon2d
	  fill-polygon2d))

(defclass polygon2d :super cascaded-coords
	    :slots
		(model-vertices 
		 vertices
		 lines
		 convexp
		 box))

(defmethod polygon2d
 (:vertices () (cdr vertices))
 (:lines () lines)
 (:edges ()
    (let (r (v vertices))
      (while (cdr v)
        (push (list (pop v) (car v)) r))
      r))
 (:drawners () (send self :edges))
 (:box () box)
 (:boxtest (b)
    (unless (derivedp b bounding-box) (setq b (send b :box)))
    (send box :intersection-p b))
 (:update ()
    (let* ((mv model-vertices)
	   (v vertices)
	   (wrot (coordinates-rot worldcoords))
	   (wpos (coordinates-pos worldcoords)))
	(while mv
	   (transform wrot (car mv) (car v))
	   (v+ wpos (car v) (car v))
           (pop v) (pop mv))
        (send box :init vertices *contact-threshold*)	;update minimal box
	)
    self)
 (:set-convexp ()
    (let ((verts (append vertices (list (cadr vertices)))))
       (setq verts (mapcar #'homogenize verts))
       (setq convexp t)
       (while (cddr verts)
	  (when (< (triangle (pop verts) (car verts) (cadr verts)) 0.0)
	      (setq convexp nil verts nil))))
    convexp)
 (:init (vlist)
    (send-super :init :dimension 2)
    (setq vertices (append vlist (list (car vlist))))
    (setq model-vertices (mapcar #'copy-seq vertices))
    (setq box (make-bounding-box vertices 0.01))
    (let ((v vertices))
	(setq lines nil)
	(while (cdr v)
	   (push (make-line (pop v) (car v)) lines)))
    (send self :set-convexp)
    self))

(defmethod polygon2d
 (:intersect-line (p1 &optional p2)
    (unless p2 (setq p2 (line-nvert p1) p1 (line-pvert p1)))
    (let (ip ip1 ip2 ints)
       (declare (type float ip1 ip2))
       (dolist (l lines)
	  (setq ip (line-intersection (line-pvert l) (line-nvert l)
				      p1 p2))
	  (when ip
	     (setq ip1 (car ip) ip2 (second ip))
	     (if (and (<= 0.0 ip1 1.0) (<= 0.0 ip2 1.0))
		 (push (list ip1 l) ints))))
       ints) )
 (:on-edge (p &optional (tolerance *contact-threshold*) &aux res)
    (dolist (e lines)
	(if (send e :on-line-point p tolerance)
	    (push e res)))
    res)
 (:insidep (point)
   (if (send self :on-edge point)
       :border
       (null (evenp (length (send self :intersect-line
				point 
				(float-vector (random 1e10) (random 1e10))))))) )
 (:intersect-polygon2d (pg) ; returns nil, :border, or t.
   (if (send self :boxtest pg)
       (let ((lines2 (send pg :lines)) p1 p2 p)
	  (dolist (l1 lines)
	     (setq p1 (line-pvert l1) p2 (line-nvert l1))
	     (dolist (l2 lines2)
		(setq p (line-intersection
				p1 p2 (line-pvert l2) (line-nvert l2)))
		(when p
		   (cond ((and (eps-in-range 0.0 (first p) 1.0 -0.001)
			       (eps-in-range 0.0 (second p) 1.0 -0.001))
			  (return-from :intersect-polygon2d t)) )))) 
          ;; there is no intersection, or intersecting at vertices
	  (let (s (count-in 0) (count-out 0) (count-border 0))
	     (dolist (v (cdr vertices))	;test inclusion of each vertex 
	        (setq s (send pg :insidep v))
		(cond ((eq s t) (return-from :intersect-polygon2d t))
		      ((eq s nil) (incf count-out))
		      ((eq s :border) (incf count-border)) ) )
	     (dolist (v (cdr (send pg :vertices)))
	        (setq s (send self :insidep v))
		(cond ((eq s t) (return-from :intersect-polygon2d t))
		      ((eq s nil) (incf count-out))
		      ((eq s :border) (incf count-border)) ) ) 
	     (if (> count-border 0) :border nil)) )
     nil)
 )  )

(defmethod polygon2d
 (:distance-point (pnt)
    (apply #'min (send-all lines :distance pnt)))
 (:distance (pnt)
    (let ((dist (send self :distance-point pnt)))
	(cond ((< dist *contact-threshold*) :border)
	      ((send self :insidep pnt) :inside)
	      (t dist))))
 (:3d (&optional (z 0.0) (klass polygon))
    (instance klass :init
		 :vertices 
		 (mapcar #'(lambda (v) (float-vector (aref v 0) (aref v 1) z))
			 (butlast vertices)) )
   )
)



(defclass circle2d
		:super cascaded-coords
		:slots (radius))
(defmethod circle2d
 (:radius () radius)
 (:draw (v)
    (send v :draw-arc (send self :worldpos) radius radius))
 (:init (r &rest args)
    (setq radius (float r))
    (send-super* :init :dimension 2 args)
    self))



(defun make-polygon2d (&rest vertices)
   (instance polygon2d :init vertices))

(defun make-rectangle (xsize ysize)
   (let ((x (/ xsize 2.0)) (y (/ ysize 2.0)))
      (instance polygon2d :init
		(list (float-vector (- x) (- y))
		      (float-vector x (- y))
		      (float-vector x y)
		      (float-vector (- x) y)))))

(defun make-circle (rad &rest args)
  (send* (instantiate circle2d) :init rad args))

(defmethod polygon2d
 (:draw (xwin &optional color)
   (if color (send xwin :foreground color))
    (send xwin :draw-polygon (cdr vertices)))
 (:draw-fill (xwin &optional color)
   (if color (send xwin :foreground color))
   (send xwin :fill-polygon (cdr vertices)))
)

(provide :polygon "@(#)$Id: polygon.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $")
