;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; hid.l
;;;	hidden-line-eliminated drawings in EUSLISP
;;;	Copyright (1988) Toshihiro MATSUI, Electrotechnical Laboratory
;;;	First, possibly-visible faces are picked up by back face culling.
;;;	For all visible edges, edge-image structures are made and face-
;;;	images are constructed to speed-up interference test.
;;;	Two dimensional intersection computation routine is coded in C.
;;;	Every visible edge is categorized into contour or non-contour edge.
;;;	Visibility changes only at the intersecting point with a contour-
;;;	edge.
;;;	A body of 552 edges and 192 faces could be drawn within 10 seconds
;;;	on sun4.
;;;	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; intersection in 2D space
;;

(in-package "GEOMETRY")
(export '(*visible-faces* *visible-face-images* *visible-edges*
	*contour-edge-images* *hid* *projected-edges*
	*non-contour-edge-images* *invisible-edges*
	*invisible-faces* check-visibility
	*ignore-approximated-edges* 
	hid2))

(eval-when (compile)   (load "geoclasses.l"))

#| Class is defined in "geoclasses.l".
 (defclass edge-image
  :super object
  :slots
  ((edge3 :type edge)
   (homo-pvert :type float-vector)
   (homo-nvert :type float-vector) ;projected vertices
   (pvert2 :type float-vector)
   (nvert2 :type float-vector)	;normal coords representation
   segments
   (contourp)
   ))

(defclass face-image :super object
	:slots (box edge-images face3d distance))

|#

(defvar *visible-faces*)
(defvar *visible-face-images*)
(defvar *visible-edges*)
(defvar *contour-edge-images*)
(defvar *hid*)
(defvar *projected-edges*)
(defvar *non-contour-edge-images*)
(defvar *invisible-edges*)
(defvar *invisible-faces*)

(deflocal *ignore-approximated-edges* t)

(defun check-visibility (pface nface point3d point2d viewpoint)
"args= pface nface  point3d point2d viewpoint
determines visibility of point3d."
    (let (fac (*epsilon* 0.0))
	(dolist (fimg *visible-face-images*)
	    (setq fac (face-image-face3d fimg))
	    (when
	        (and (null (eq fac pface))
		     (null (eq fac nface))
		     (send fimg :possibly-hiding point2d)
		     (send fac :intersect-line point3d viewpoint))
		(return-from check-visibility nil)))
        t))

(defmethod edge-image 
 (:edge3 () edge3)
 (:vertices () (list pvert2 nvert2))
 (:color () (send edge3 :color))
 (:homo2real (p)
    (declare (float p))
    (let ((pw (* p (aref homo-pvert 3))))
       (declare (type float pw))
       (/ pw (+ pw (* (aref homo-nvert 3) (- 1.0 p))))))
 (:add-segment (p &optional info)
    (declare (type float p))
    (let ( (pw (* p (aref homo-pvert 3))) )
       (declare (type float pw))
       (setq pw %(pw /  (pw +  homo-nvert[3] *  (1.0 - p))))
       (if (and (>= pw 0.0) (<= pw 1.0))
           (push (list p ;parameter in homogeneous projection space
		   pw    ;parameter in real space
        	   t 	 ;visibility is temporarily t
		   info)
	     segments)) ) )
 (:projected-point (p)
    (declare (type float p))
    (v+ (scale (- 1.0 p) pvert2) (scale p nvert2)))
 (:projected-homo-point (p)
    (declare (type float p))
    (v+ (scale (- 1.0 p) homo-pvert) (scale p homo-nvert)))
 (:intersecting-point (ex)	;intersecting point in real space
   (declare (type edge-image ex))
   (let* ((uv (line-intersection
			 pvert2 nvert2 (ex . pvert2) (ex . nvert2)
			 t)))
     (when uv (send edge3 :point (send self :homo2real (car uv))))))
 (:projected-intersection (ex mutual)
   (declare (type edge-image ex))
   (let* ((uv (line-intersection
		 pvert2 nvert2 (ex . pvert2) (ex . nvert2)  t) ) )
       (when uv
	 (send self :add-segment (car uv) ex)
	 (if mutual (send ex :add-segment (cadr uv) self))))) 
 (:sort-segments ()  (setq segments (sort segments #'<= #'car)))
 (:box () (instance bounding-box :init2 pvert2 nvert2))
 (:contourp () contourp)
 (:mark-visible-segments (viewpoint)
	;This method is very much computation time effective.
    (let* ((last (car segments))
	   (point3d) (face3d) (point2d)
	   (pfac (edge-pface edge3))
	   (nfac (edge-nface edge3)))
       (dolist (ip (cdr segments))		
	  (setq point2d (send self :projected-point 
				   (/ (+ (the float (car ip))
					 (the float (car last))) 2.0)))
	  (setq point3d
		(send edge3 :point
			(/ (+ (the float (cadr ip)) (the float (cadr last)))
			   2.0)))
          (setf (caddr last)
		(check-visibility pfac nfac point3d point2d viewpoint))
	  (setq last ip)  )))
 (:visible-face (viewpoint)
    (let ((pf (edge-pface edge3)) (nf (edge-nface edge3)))
	(if (memq pf *visible-faces*) pf nf)))
 (:collect-segments (flag)
    (let (vis (p1 (car segments)) hp1 hp2 lineseg)
       (dolist (p2 (cdr segments))
	  (when (eq (caddr p1) flag)
	      (setq hp1 (send self :projected-homo-point (cadr p1))
		    hp2 (send self :projected-homo-point (cadr p2)))
	      (setq lineseg (homo-viewport-clip hp1 hp2))
	      (if lineseg (push lineseg vis)))
	  (setq p1 p2))
	vis) )
 (:visible-segments ()	;returns clipped visible segments defined in NDC
    (send self :collect-segments t))
 (:invisible-segments () ;returns clipped invisible segments defined in NDC
    (send self :collect-segments nil))
 (:project (edge3d view &optional (viewpoint (send view :viewpoint)))
    (declare (type edge edge3d))
    (setq edge3 edge3d
	  homo-pvert (send view :view (edge-pvert edge3d))
	  homo-nvert (send view :view (edge-nvert edge3d))
	  pvert2 (homo2normal homo-pvert)
	  nvert2 (homo2normal homo-nvert)
	  segments (list (list 0.0 0.0 t) (list 1.0 1.0 t))
	  contourp (send edge3d :contourp viewpoint)) 
    self)
 (:init (&key   ((:edge3 e)) ((:homo-pvert hp)) ((:homo-nvert hn))
		((:pvert2 p2)) ((:nvert2 n2)))
      (if e (setq edge3 e))
      (if hp (setq homo-pvert hp))
      (if hn (setq homo-nvert hn))
      (if p2 (setq pvert2 p2))
      (if n2 (setq nvert2 n2))
      self))

(defmethod face-image 
 (:face3d () face3d)
 (:possibly-hiding (point) (send box :inner point))
 (:boxtest (b) (send box :intersection-p b))
 (:init (f3d elist viewpoint)
    (let (vlist)
	(dolist (e elist)
	   (if e (push (send e :vertices) vlist)))
	(setq vlist (flatten vlist))
        (setq face3d f3d
	      edge-images elist
	      box (instance bounding-box :init vlist))
	(send box :grow 0.01)
        (setf (aref (bounding-box-maxpoint box) 2) 1.0e20)
	)
    self) )

(defun make-face-image (f edge-images-htab viewpoint)
  (instance face-image :init
	 f
	 (mapcar 
	     #'(lambda (e3d) (gethash e3d edge-images-htab))
	     (send f :edges))
         viewpoint))

(defun set-contour-intersections (contour-images)
    (while contour-images
      (let* ((eimg1 (pop contour-images))
	     (edge1 (edge-image-edge3 eimg1))
	     (pface (edge-pface edge1))
	     (nface (edge-nface edge1))
	     (pedges (if pface (face-edges pface)))
	     (nedges (if nface (face-edges nface))))
         (dolist (eimg2 contour-images)
	    (declare (type edge-image eimg2))
	    (if (and (not (memq (edge-image-edge3 eimg2) pedges))
		     (not (memq (edge-image-edge3 eimg2) nedges)))
		;don't try the edge coplanar to edge1
	        (send eimg1 :projected-intersection eimg2 t))))))

(defun set-non-contour-intersections (non-contour-images contour-images)
    (dolist (pe1 non-contour-images)
	(declare (type edge-image pe1))
	(let* ((e3 (edge-image-edge3 pe1))
	       (e3pface (edge-pface e3))
	       (e3nface (edge-nface e3))
	       (e3pedges (if e3pface (face-edges e3pface)))
	       (e3nedges (if e3nface (face-edges e3nface))))
	   (declare (type edge e3))
	   (dolist (pe2 contour-images)
		(declare (type edge-image pe2))
	        (if (and (not (memq (edge-image-edge3 pe2) e3pedges))
		         (not (memq (edge-image-edge3 pe2) e3nedges)))
		;don't try the edge coplanar to pe1
	        (send pe1 :projected-intersection pe2 nil))))))

(defun curved-edge-image-p (eimg)
    (and *ignore-approximated-edges*
         (send (edge-image-edge3 eimg) :approximated-p)) )

(defun hid2 (bodies view &optional (vp))
   (let* ((projected-edge-htab
		(make-hash-table :size 100 :hash #'sys:address :test #'eq))
	  (viewpoint (send view :viewpoint))
	  (ctime0 (unix:runtime))
	  (viewport-edges)
	  ctime1 ctime2 ctime3)
      (setq *visible-faces* nil
	    *visible-face-images* nil
	    *visible-edges* nil
	    *invisible-edges* nil
	    *invisible-faces* nil
	    *contour-edge-images* nil
	    *non-contour-edge-images* nil
	    *projected-edges* nil)
      ;accumulate all the possibly-visible faces and edges
      (dolist (abody bodies)
	(let ((faces) (edges))
	  (if (derivedp abody faceset) (send abody :worldcoords))
	  (dolist (f (if (derivedp abody faceset)
			 (send abody :faces)
			 (list abody)))	;assume this is a face
	      (if (> (send f :plane-distance viewpoint) 0.0)
		  (push f faces)))
	  (setq edges (remove-duplicates 
			 (apply #'append (send-all faces :all-edges)))
	  	*invisible-edges*
		   (nconc *invisible-edges*
		       (set-difference 	(send abody :all-edges) edges))
	  	*visible-edges*	 (nconc edges *visible-edges*)
          	*visible-faces* (nconc faces *visible-faces*))))
      ;;
      ;;
      (dolist (e *visible-edges*)
	(let ((eimg (instance edge-image :project e view viewpoint)))
	  (if (send eimg :contourp)
	      (push eimg *contour-edge-images*)
	      (if (not (curved-edge-image-p eimg)) 
		  (push eimg *non-contour-edge-images*)))
	  (setf (gethash e projected-edge-htab) eimg)) )
    (setq ctime1 (unix:runtime))
      (setq *visible-face-images*
	    (mapcar #'(lambda (f)
			 (make-face-image f projected-edge-htab viewpoint))
		    *visible-faces*))
      (set-contour-intersections *contour-edge-images*)
      (set-non-contour-intersections *non-contour-edge-images* 
				     *contour-edge-images*)
     ;; intersection with viewport-edges
      (push (instance edge-image :init :pvert2 #f(-0.9999 -0.9999 0.99)
			:nvert2 #f(-0.9999 0.9999 0.99))
	    viewport-edges)
      (push (instance edge-image :init :pvert2 #f(-0.9999 0.9999 0.99)
			 :nvert2 #f(0.9999 0.9999 0.99))
	    viewport-edges)
      (push (instance edge-image :init :pvert2 #f(0.9999 0.9999 0.99)
			 :nvert2 #f(0.9999 -0.9999 0.99))
	    viewport-edges)
      (push (instance edge-image :init :pvert2 #f(0.9999 -0.9999 0.99)
			 :nvert2 #f(-0.9999 -0.9999 0.99))
	    viewport-edges)
;	(print viewport-edges)
      (dolist (vedge viewport-edges)
        (dolist (ceimg *contour-edge-images*)
	    (send ceimg :projected-intersection vedge nil))
        (dolist (nceimg *non-contour-edge-images*)
	    (send nceimg :projected-intersection vedge nil)))
    (setq ctime2 (unix:runtime))
      (setq *hid* (append  *contour-edge-images* *non-contour-edge-images*))
      (send-all *hid* :sort-segments)
      (send-all *hid* :mark-visible-segments viewpoint)
    (setq ctime3 (unix:runtime))
    (print (list (- ctime1 ctime0) (- ctime2 ctime1) (- ctime3 ctime2)))
;    *hid*
   ))

(provide :hid "@(#)$Id: hid.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $")
