;; body-body, face-face relation
;; Jan/1992
;; Toshihiro Matsui

;;; make intersecting polygons from two coplanar polygons
;;; Jan/15/1992
;;; (C) Toshihiro Matsui

;; enumerate face-edge intersections

(in-package "GEOMETRY")

(export '(face+ face* ff-relation bb-relation))

(defun coplanar-fe-intersection (face1 edge2 
				 &optional (side :inside)
				 	   (tolerance *coplanar-threshold*))
"(face1 edge2 &opt side tol) edge2 is coplanar with face1.
coplanar-fe-intersection finds all the line-to-line intersection between
edge2 and all the edges forming face1"
   (let ((pv (copy-seq (line-pvert edge2)))
	 (nv (copy-seq (line-nvert edge2)))
	 ints p p1 p2 colinears intersects
	 (tolerance2 (sqrt tolerance)))
      ;; (setq tolerance2 0.0)
      (dolist (e1 (send face1 :all-edges))
	 (setq p (send e1 :intersect-line edge2 tolerance2))
	 (if (consp p)
	     (if (eql (car p) :colinear)
		 (push (cons e1 (third p)) ints)	;remember edge1
		 (push (third p) ints))))
      (when (null ints)	;no intersection, no colinear
	 (setq p (send face1 :insidep (line-pvert edge2)))
	 (return-from coplanar-fe-intersection 
		(list nil	;colinears
		     (if (eq p side)
			 (list (list nil pv nv))	;flag no intersection
			 nil)) ))
      (setq ints (sort ints
			#'<= 
			#'(lambda (x)
			    (if (numberp x)
				x
				(/ (+ (second x) (third x)) 2.0)))) )
      (nconc ints (cons 1.0 nil))
      (setq p1 0.0)
      (dolist (px ints)
	 (setq p2 (if (consp px) (second px) px))
	 (when (eps< p1 p2 tolerance)
	    (setq p (send face1 :insidep (send edge2 :point (/ (+ p1 p2) 2.0))))
	    (if (eq p side)
	        (push (list 
			 t	;yes, this is an intersection
                	 (send edge2 :point p1)
		         (send edge2 :point p2)) intersects))
	    (setq p1 p2))
	 (when (consp px)	;colinear portion
	     ;; px = (edge1 param1 param2)
	     (setq p2 (third px))
	     (if (eps<> p1 p2 tolerance)
		 (push (list (first px)	; edge1
				edge2
				(send edge2 :point p1)
				(send edge2 :point p2)) colinears))
	    (setq p1 p2))
	 )
    (list colinears intersects)))

(defun find-next-segment (nv segs tol)
  (let ((mindist 1.0e20) (closest-segment))
     (dolist (s segs)
        (let* ((d1 (distance nv (first s)))
	       (d2 (distance nv (second s)))
	       (d (min d1 d2)))
           (if (< d mindist) (setq closest-segment s mindist d))))
     (if (< mindist tol)
         closest-segment
         nil)) )


(defun find-loop (segments normal &optional (tol *contact-threshold*))
   (let (loop seg pv pv1 nv next-seg (newface (instantiate face)) r)
      (setq seg (pop segments)
	    pv1 (first seg)
	    nv (second seg)
	    loop (list (list pv1 nv)))
      (while  (setq next-seg  (find-next-segment nv segments tol))
	  (setq segments (delete next-seg segments :count 1))
	  (setq pv nv)
	  (if (eps-v= nv (cadr next-seg))
	      (setq nv (car next-seg))
	      (setq nv (cadr next-seg)))
	  (push (list pv nv) loop) )
      (setq loop (nreverse loop))
      (cond ((not (eps-v= pv1 nv))
	     ;; loop does not close, they must be isolated edges
	     ;; make instances of line
	     (dolist (lp loop)	(push (make-line (car lp) (second lp)) r))
	     (list r segments))
	    (t 	;loop closed
	      (setq loop (mapcar #'car loop))
	      (when (< (v. (face-normal-vector loop) normal) 0.0)
		  ;(format t "loop reversed~%")
		  (setq loop (nreverse loop)))
	      (setq newface (instance face :init :vertices  loop))
	      (list (list newface) segments)))) ) 

(defun punch-hole (profile hole-polygon)
   (let* ((hole-vertices (reverse (rest (send hole-polygon :vertices))))
	  (xhole (instantiate hole)))
     (send xhole :init :vertices hole-vertices :face profile) 
     ;; (format t "hole normal= ~a~%" (send xhole :normal))
     ;; (break "punch-hole: ")
     (send profile :enter-hole xhole) ))


(defun construct-polygon (segments normal &optional (tol *contact-threshold*))
   (let (polygons lines seg x xhole profile)
      (while segments
	 (setq x (find-loop segments normal))
	 (dolist (face-or-line (car x))
	    (if (derivedp face-or-line line)
		(push face-or-line lines)
	        (push face-or-line polygons)))
	 (setq segments (cadr x)))
      ;; (break "cons-polygons: ")
      (let (p1 (pg polygons))
	 (while (cdr pg)
	     (setq p1 (pop pg))
	     (dolist (p2 pg)
		(cond ((eql (send p1 :insidep (send p2 :vertex 0))  :inside)
		       (punch-hole p1 p2)
		       (setq polygons (delete p2 polygons :count 1)))
		      ((eql (send p2 :insidep (send p1 :vertex 0))  :inside)
		       (punch-hole p2 p1)
	   	       (setq polygons (delete p1 polygons :count 1))))
	        )))  
      (nconc polygons lines)))

(defun remove-non-overlapping-border (face1 face2 colinears)
  (let ((normal1 (send face1 :normal)) (normal2 (send face2 :normal))
	 result )
     (dolist (col colinears)
	(let ((e1 (first col)) (e2 (second col)))
	  (if (> (v. (v* (send e1 :direction face1) normal1)
		     (v* (send e2 :direction face2) normal2))
		 0.0)
	      (push (cddr col) result))))
     result))

(defun coplanar-ff-intersection (face1 face2
				 &optional (side :inside)
					   (tol *coplanar-threshold*))
  ;; returns list of faces
  (let (segments colinears colinears1 colinears2 p colinear-found)
     (dolist (e1 (send face1 :all-edges))
	(setq p (coplanar-fe-intersection face2 e1 side tol) )
	(if (car p)  (setq colinears1 (nconc (car p) colinears1)))
	(if (cadr p) (setq segments  (nconc (cadr p) segments)) ))
     (if colinears1 (setq colinear-found t))
     (if t; (eql side :outside)
	 (setq colinears1 (remove-non-overlapping-border
				face2 face1 colinears1))
	 (setq colinears1 (mapcar #'cddr colinears1)))
     (dolist (e2 (send face2 :all-edges))
	(setq p (coplanar-fe-intersection face1 e2 side tol) )
	(if (car p)  (setq colinears2 (nconc (car p) colinears2)))
	(if (cadr p) (setq segments  (nconc (cadr p) segments)) ))
     (if colinears2 (setq colinear-found t))
     (if t ; (eql side :outside)
	 (setq colinears2 (remove-non-overlapping-border
				face1 face2 colinears2))
	 (setq colinears2 (mapcar #'cddr colinears2)))
;
     (setq colinears (nconc colinears1 colinears2))
     (setq colinears
	   (remove-duplicates colinears
		:test #'(lambda (x y)
			    (or (and (eps-v= (first x) (first y) tol)
				     (eps-v= (second x) (second y) tol))
				(and (eps-v= (second x) (first y) tol)
				     (eps-v= (first x) (second y) tol))))
		))
     ;(format t "colinears=~s~% segments=~s~%" colinears segments)
     (cond ((and (null colinear-found)
	         (every #'(lambda (x) (null (car x))) segments))
	    ;; there is no intersection or overlapped edge
	    (let ((flag1 (send face1 :insidep (send face2 :vertex 0) 0.001))
		  (flag2 (send face2 :insidep (send face1 :vertex 0) 0.001)))
	      (cond ((eql side :inside)	;faces are disjoint
		     (cond ((eql flag1 :inside)  face2)
			   ((eql flag2 :inside)  face1)
			   (t nil)))			; disjoint faces
		    ((eql side :outside)
			;; (format t "flags=~s ~s~%" flag1 flag2)
		     (cond ((eql flag1 :inside)  (list face1))
			   ((eql flag2 :inside)  (list face2))
			   (t (list face1 face2))))	; disjoint faces
		    )))
	   (t 
	     (construct-polygon 
		 (nconc (mapcar #'rest segments) colinears)
		 (send face1 :normal)) ))
	))


(defun face* (f1 f2 &optional (tolerance *coplanar-threshold*))   
  (coplanar-ff-intersection f1 f2 :inside tolerance))

(defun face+ (f1 f2 &optional (tolerance *coplanar-threshold*))   
  (coplanar-ff-intersection f1 f2 :outside tolerance))



(defun non-coplanar-fe-relation (face1 edge2
				 &optional (tolerance *coplanar-threshold*))
   (let* ((ip (send face1 :intersection (line-pvert edge2) (line-nvert edge2)))
	  (point (send edge2 :point ip))
	  flag)
      (cond ((or (eps= ip 0.0 tolerance) (eps= ip 1.0 tolerance))
	     (setq flag (send face1 :insidep point))
	     (cdr (assoc flag
			  '((:border . :contact)	;point-edge contact
			    (:inside . :contact)
			    (:outside . nil))) ))
	    ((< 0.0 ip 1.0)
	     (setq flag (send face1 :insidep point))
	     (case flag
		(:inside
		   (if (and (send face1 :on-plane-p (line-pvert edge2))
			    (send face1 :on-plane-p (line-pvert edge2)) )
			:contact	;edge-plane contact
			:intersect))
		(:border :contact)	;point-edge contact
		(:outside nil)))
	    (t nil))))

(defun ff-relation (face1 face2 &optional (tolerance *coplanar-threshold*))
 (let ((n1 (plane-normal face1)) (n2 (plane-normal face2))
	(d1 (plane-distance face1)) (d2 (plane-distance face2))
	(edges1 (face-edges face1)) (edges2 (face-edges face2))
	intersects1 intersects2
	flag1 flag2
	p int)
  (cond ((eps= (v. n1 n2) 1.0 tolerance)
	 (if (eps= d1 d2)
	     (setq flag1 (list :coplanar :equidirection))
	     (return-from ff-relation  nil #| :parallel|# )))
        ((eps= (v. n1 n2) -1.0)
	 (if (eps= d1 (- d2) tolerance)
	     (setq flag1 (list :coplanar :opposing))
	     (return-from ff-relation nil #|:parallel|#))))
  ;; :parallel && apart is excluded
  ;; flag1 = nil | (:coplanar :opposing) | (:coplanar | :equidirection)
  (when flag1	;coplanar
     ;; find common (contact) area between two faces
     (setq flag2 (face* face1 face2 tolerance))
     (cond ((derivedp flag2 face)
	    (return-from ff-relation   (append flag1 (list flag2))))
	   ((some #'(lambda (f) (derivedp f face)) flag2)
	    (return-from ff-relation   (append flag1 flag2)))
	   ((every #'(lambda (f) (derivedp f line)) flag2)
	    (return-from ff-relation  (list :aligned (cadr flag1))))))
  (dolist (e1 edges1)
     (setq p (non-coplanar-fe-relation face2 e1 tolerance))
     (when (eq p :intersect)
	(format t ";; ~s and ~s intersected~%" face2 e1)
	(return-from ff-relation (list :intersect)))
     (if p (push p flag2)))
  (dolist (e2 edges2)
     (setq p (non-coplanar-fe-relation face1 e2 tolerance))
     (when (eq p :intersect)
	(format t ";; ~s and ~s intersected~%" face1 e2)
	(return-from ff-relation (list :intersect)))
     (if p (push p flag2)))
  (cond ((every #'(lambda (x) (eq x :contact)) flag2)
	  (list :point/edge-contact)
	  ; nil
	  )
	(t flag2))
  ))

;;
;; BUG: special care should be taken for ff-relation between two side
;;	faces of cylinders 
;;
(defun bb-relation (body1 body2 &optional (tolerance *epsilon*))
   (let* ((cbox (send body1 :common-box body2))
	  faces1 faces2 edges1 edges2 result flag
	  (curved-faces1 (send body1 :curved-faces))
	  (curved-faces2 (send body2 :curved-faces))
	  (count 0) fbbox)
      (when cbox
	  (setq faces1 (send body1 :possibly-interfering-faces cbox))
	  (setq faces2 (send body2 :possibly-interfering-faces cbox))
	  (setq curved-faces1 (intersection curved-faces1 faces1)
		curved-faces2 (intersection curved-faces2 faces2))
	  (setq edges1 (send body1 :possibly-interfering-edges cbox))
	  (setq edges2 (send body2 :possibly-interfering-edges cbox))
	  (dolist (f1 faces1)
	    (setq fbbox (send f1 :box tolerance))
	    (send fbbox :grow tolerance t)
	    (dolist (f2 faces2)
		(if (or ;; (and (member f1 curved-faces1)
			;;      (member f2 curved-faces2))
		         (null (send (send f2 :box tolerance)
				     :intersection-p fbbox)))
		    (setq flag nil)
		    (setq flag (ff-relation f1 f2 tolerance)))
		;; (format t "f1=~s f2=~s flag=~s~%" f1 f2 flag)
		(cond ((null flag) nil)
		      ((eq (car flag) :point/edge-contact)
			nil)
		      ((and (eq (car flag) :coplanar)
			    (eq (cadr flag) :opposing))
		       (push (list* :planar-contact f1 f2 (cddr flag))
			     result))
		      ((and (eq (car flag) :aligned)
			    (eq (cadr flag) :equidirection))
		       (push (list :aligned f1 f2) result))
		      ((and (eq (car flag) :coplanar)
			    (eq (cadr flag) :equidirection)
			    (derivedp (third flag) face))
			(return-from bb-relation :intersect)) 
		      ((eq (car flag) :intersect) 
			(return-from bb-relation :intersect))
		      (t (push (list* f1 f2 flag) result)))
		))
    result
     ) ))

;(defun lprint (x &optional (*print-level* 5) (*print-length* t))
;   (print x) t)


#| ; test of face composition
(setq a1 (make-polygon #f(0 0 0) #f(40 0 0) #f(40 20 0) #f(0 20 0)))
(setq a2 (make-polygon #f(0 0 0) #f(10 0 0) #f(10 20 0) #f(0 20 0)))
|#

(defun make-lines (point-pairs)
  (mapcar #'(lambda (x) (apply #'make-line x)) point-pairs))

(defun copy-face (f)
   (labels ((copy-vertices (f &aux vs)
	     (dolist (v (rest (send f :vertices)) vs)
		(push (copy-seq v) vs))) )
     (instance *face-class* :init
		:vertices (copy-vertices f)
		:holes (mapcar
			    #'(lambda (hv)
				    (instance hole :init :vertices hv))
			    (mapcar #'copy-vertices (send f :holes))))
))

(provide :bodyrel "@(#)$Id$")

