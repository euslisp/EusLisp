;;;; geo/shadow.l
;;;; (c) 1992  Toshihiro MATSUI, Electrotechnical Laboratory
;;;

(in-package "GEO")

(export '(do-combination project-shadow project-shadow1
	  shadow-intersection closest-shadow))

;;;;;;

(defmacro do-combination (combi &rest forms)
    (let ((var1 (first combi)) (var2 (second combi))
	  (combivar (gensym "COMBI")))
	`(let ((,combivar ,(third combi)))
	   (while (rest ,combivar)
	     (let ((,var1 (pop ,combivar)))
	       (dolist (,var2  ,combivar)  . ,forms))))))

(defun polygon-in-contact-p (poly1 poly2)
   (let* ((edges1 (send poly1 :all-edges))
	  (edges2 (send poly2 :all-edges)))
      (dolist (e1 edges1)
	 (dolist (e2 edges2)
	    (if (and (send e1 :colinear-line e2)
		     (send e1 :colinear-line-intersection e2))
		(return-from polygon-in-contact-p t))))
      nil))

(defun make-edges-from-vertices (verts &aux lines)
   (while (cdr verts)
     (push (instance edge :init :pvertex (pop verts) :nvertex (car verts))
	   lines))
   (nreverse lines))

(defun orthogonally-visible-faces (abody vnormal &aux Vfaces Ifaces)
   (dolist (f (send abody :faces))
	(if (eps< (v. vnormal (plane-normal f)) 0.0 )
	    (push f Vfaces)
	    (push f Ifaces)))
   (values Vfaces Ifaces))

(defun make-polygon (&rest points)
   (instance polygon :init :vertices points))


(defun make-face-from-edge-loop (edges)
   (let ((f (instantiate face)))
     (dolist (e edges) (setf (edge-pface e) f))
     (send f :init :edges edges)))

(defun change-to-hole (aface)
   (let ((h (instantiate hole)))
      (send h :init :vertices (cdr (send aface :vertices)))))

#|
(defun det3 (a b c)
  %(a[0] * b[1] * c[2] - a[2] * b[1] * c[0] +
    a[1] * b[2] * c[0] - a[1] * b[0] * c[2] +
    a[2] * b[0] * c[1] - a[0] * b[2] * c[1]))

(defun line-intersection2 (a1 a2 b1 b2 &optional tol)
   (let* ((p1 a1)
	  (v1  (v- a2 a1))
	  (p2 b1)
	  (v2  (v- b2 b1))
	  (p2-p1 (v- p2 p1))
	  (cross (v* v1 v2))
	  (cross2 (v. cross cross)))
      (cond ((< cross2 0.001)  nil)
	    (t (list (/ (det3 p2-p1 v2 cross) cross2)
		     (/ (det3 p2-p1 v1 cross) cross2))))) )
|#

;;; project-shadow1 makes a projection of a body onto a plane
;;; First, all visible faces of the body are found.
;;; Edges of each visible face are projected onto the plane,
;;; and a face structure is formed.
;;; Union of all such projected faces is computed by using face+ many
;;; times.
;;; project-shadow1 is not very robust for it is fooled by
;;; small side facets of a cylinder

(defun project-shadow1 (bod pln)
  (let* (Vfaces Ifaces (Afaces (send bod :faces)) projection
	 projected-faces
	 (vnormal (send pln :normal)) 	(-vnormal (v- vnormal))
	 x y loop shadow-polygon shadow-polygons)
      ;; separate visible faces and invisible faces
      (dolist (f Afaces)
	  (if (eps< (v. vnormal (plane-normal f)) 0.0 )
	      (push f Vfaces)
	      (push f Ifaces)))
      ;; project visible faces onto the 'pln'
      (dolist (Vf Vfaces)
	 (let (profile-vertices loop hole-vertices holes profile)
	    (dolist (v (cdr (send vf :vertices)))
	        (push (send pln :project v) profile-vertices))
	    (setq profile-vertices (nreverse profile-vertices))
	    (dolist (h (send vf :holes))
		(dolist (v (cdr (send h :vertices)))
	           (push (send pln :project v) loop))
		(push (nreverse loop) hole-vertices))
	    (setq hole-vertices (nreverse hole-vertices))
	    ;; projection computed; create a face with holes
	    (dolist (ph hole-vertices)
		(push (instance hole :init :vertices ph) holes) )
	    (push (instance face :init 
	    			 :vertices profile-vertices
				 :holes holes)
		  projected-faces)
	    ))
     (sort projected-faces #'>= #'(lambda (x) (send x :area)))
     ;; compute union of all the projected-faces
     (let (faces f1 f2 face-union result)
	(while (cdr projected-faces)	;merge into one face
	  (setq f1 (pop projected-faces) faces nil)
	  ;; find a face which intersects with f1 (at least there is one)
	  (block find-intersection
	     (while projected-faces
	        (setq f2 (pop projected-faces))
		(setq *f1* f1 *f2* f2)
	        (setq face-union (face+ f1 f2))
		(if (member-if #'(lambda (x) (derivedp x line)) face-union)
		    (break "line?: ")
		    (setq face-union (collect-instances polygon face-union)) )
	        (cond ((null (cdr face-union))	;yes, there is intersection
		       (push (car face-union) faces)
		       (nconc faces projected-faces)
		       (return-from find-intersection nil))
		      (t (push f2 faces)) ))
	     (error "project-shadow: can't find intersection of loops~%"))
	  (setq projected-faces faces)) )
     (car projected-faces))
)



;;; project-shadow is a more reliable version.
;;; After finding visible and invisible faces, contour-edges are
;;; extracted. Each contour-edge forms a loop not only in the original
;;; body but also in the projection.
;;; When double loops are found, they are removed.
;;; The loops are classified into profiles and holes by comparing
;;; their normal vector with the plane's normal.
;;; For a hole, an outer circuit is searched for, and the hole
;;; becomes a hole of the face.
;;; Resulted faces some of which may have holes are merged by face+.
;;; Since number of loops taken into account is much smaller than
;;; the number of visible faces, project-shadow is more robust
;;; than project-shadow1.

(defun remove-inner-loop (edge-loop vnormal)
   (let (intersections intersecting-edges )
      ;; enumerate all intersections
      (do-combination (e1 e2 edge-loop)
	 (if (or (not (eql e1 (car (member e1 edge-loop))))
		 (not (and (eql e1 (car edge-loop))
			   (eql e2 (car (last edge-loop))))) )
	  (let* ((intersection
		     (line-intersection3 (edge-pvert e1) (edge-nvert e1)
					 (edge-pvert e2) (edge-nvert e2)
					 0.001))
		 (param1 (first intersection))
		 (param2 (second intersection)))
	    (when (and intersection
		        (eps< 0.0 param1) (eps< param1 1.0)
			(eps< 0.0 param2) (eps< param2 1.0))
		  (push (list e1 e2 (send e1 :point param1) param1 param2)
			 intersections)
		  (push e1 intersecting-edges)
		  (push e2 intersecting-edges)))) )
      ;; delete inner edges
      (dolist (int intersections)
	 (let* ((edge1 (first int)) (edge2 (second int))
		 (dir1 (v- (edge-nvert edge1) (edge-pvert edge1)))
		 (dir2 (v- (edge-nvert edge2) (edge-pvert edge2)))
		 (point (third int)) next-edges)
	    (if (< (v.* vnormal dir1 dir2) 0)
		(psetq edge1 edge2 edge2 edge1))
	    (setq next-edges (cdr (member edge1 edge-loop)))
	    (unless next-edges (setq next-edges edge-loop))
	    (while (not (eq (car next-edges) edge2))
		(if (member (car next-edges) intersecting-edges)
		    (error "loop intermingled"))
		(setq edge-loop (delete (car next-edges) edge-loop :count 1))
		(setq next-edges (cdr next-edges))
		(unless next-edges (setq next-edges edge-loop)))
	    (setf (edge-nvert edge1) point
		  (edge-pvert edge2) point))
	)
   edge-loop))



(defun project-shadow (bod pln)
  (let* (Vfaces Ifaces (Afaces (send bod :faces))
	 Contour-edges contour-edge-loops Contour-vertices
	 (vnormal (send pln :normal)) 	(-vnormal (v- vnormal))
	 projected-edges contour-edge-loops2 shadow-faces
	 x y loop shadow-holes shadow-profiles)
      ;; find visible and invisible edges
      (dolist (f Afaces)
	  (if (eps< (v. vnormal (plane-normal f)) 0.0 )
	      (push f Vfaces)
	      (push f Ifaces)))
      ;; find contour-edges
      (dolist (e (send bod :edges))
	 (let* ((pf (edge-pface e)) (nf (edge-nface e))
		(pvf (car (member pf Vfaces))) 
		(nvf (car (member nf Vfaces))) vf)
	    (cond ((and pvf (null nvf)) (setq vf pvf))
		  ((and (null pvf) nvf) (setq vf nvf))
		  (t (setq vf nil)))
	    (if vf  (push (list e vf) contour-edges))) )
      ;; project vertices of contour-edges
      (dolist (e contour-edges)
	 (let ((pv (send (car e) :pvertex (second e)))
	       (nv (send (car e) :nvertex (second e))))
	    (unless (assoc pv contour-vertices)
		(push (list pv (send pln :project pv)) contour-vertices))
	    (unless (assoc nv contour-vertices)
		(push (list nv (send pln :project nv)) contour-vertices))) )
      ;; create edge objects for projected vertices
      (dolist (e contour-edges)
	 (let ((pv (send (car e) :pvertex (second e)))
	       (nv (send (car e) :nvertex (second e))))
	    (push (instance edge :init
			:pvertex (cadr (assoc pv contour-vertices))
			:nvertex (cadr (assoc nv contour-vertices)))
		  projected-edges) ))
      ;; find closed loops
      (while projected-edges
	 (setq loop nil)
	 (setq x (pop projected-edges))
         (push x loop)
         (setq x (edge-nvert x))
	 (while (setq y (find-if 
		  	    #'(lambda (pe) (eq (edge-pvert pe) x))
			    projected-edges))
	     (setq  projected-edges (delete y projected-edges :count 1))
	     (setq x (edge-nvert y))
	     (push y loop))
	 (push (nreverse loop) contour-edge-loops))
      (setq contour-edge-loops (nreverse contour-edge-loops))
 	;;    (setq loops contour-edge-loops)
      ;; find intersections between edges in a loop,
      ;; and remove inner loops
      ; (format t "remove inner loops for ~d contour edge loops~%"
      ;	(length contour-edge-loops))
      (dolist (edge-loop contour-edge-loops)
	 ; (draw 3 edge-loop)
	 (push (remove-inner-loop edge-loop vnormal) contour-edge-loops2))
      (setq contour-edge-loops contour-edge-loops2)
      (setq loops contour-edge-loops)
      ;; 
      (setq shadow-holes nil shadow-profiles nil)
      (dolist (loop contour-edge-loops)
	 (let ((aface (make-face-from-edge-loop loop)))
	    (if (< (v. vnormal (send aface :normal)) 0.0)
		(push aface shadow-profiles)
		(push (change-to-hole aface) shadow-holes))))
      ;;; for every hole, find an outer loop and put the hole in the face
      (dolist (h shadow-holes)
	 (block enter-hole
	   (dolist (prof shadow-profiles)
	     (when (every #'(lambda (hv) (eql (send prof :insidep hv) :inside))
		        (send h :vertices))
		 (send prof :enter-hole h)
		 (send h :face prof)
		 (return-from enter-hole nil)))))
	;;
     (setq shadow-faces shadow-profiles)
      (setq shadow (copy-seq shadow-faces))
     ;; (break "shadow: ")
     (let (faces f1 f2 face-union result)
	(while (cdr shadow-faces)	;merge into one face
	  (setq f1 (pop shadow-faces) faces nil)
	  ;; find a face which intersects with f1 (at least there is one)
	  (block find-intersection
	     (while shadow-faces
	        (setq f2 (pop shadow-faces))
		(setq *f1* f1 *f2* f2)
	        (setq face-union (face+ f1 f2))
		(if (member-if #'(lambda (x) (derivedp x line)) face-union)
		    (break "line?: ")
		    (setq face-union (collect-instances polygon face-union)) )
	        (cond ((null (cdr face-union))	;yes, there is intersection
		       (push (car face-union) faces)
		       (nconc faces shadow-faces)
		       (return-from find-intersection nil))
		      (t (push f2 faces)) ))
	     (error "project-shadow: can't find intersection of loops~%"))
	  (setq shadow-faces faces)) )
     (car shadow-faces))
  )



;;

(defun shadow-intersection (body1 body2 pln)
    (face* (project-shadow body1 pln)
	   (project-shadow body2 pln)))

(defun closest-shadow (abody shadow)
   (let* ((sbox (send shadow :box)) p 
	  (vnormal (send shadow :normal))
	  (-vnormal (v- vnormal))
	  (mindist nil) newdist minpoint
	  (inner-point (send shadow :one-inner-point))
	  (inner-point-distance ()
      (dolist (v (send abody :vertices))
	 (setq p (send shadow :project v))
	 (if (and (send sbox :inner p)
		  (eql (send shadow :insidep p) :inside)
		  (setq newdist (send shadow :distance v))
		  (or (null mindist)
		      (< mindist newdist)))
	     (setq mindist newdist minpoint v)))
#|
      (when (null mindist)	; no vertex is found in the Common Shadow
	 (dolist (v (send shadow :all-vertices))
	    (send abody :distance v)))
|#
      (list mindist minpoint)))

))

(provide :shadow "@(#)$Id: shadow.l,v 1.1.1.1 2003/11/20 07:46:29 eus Exp $")

)