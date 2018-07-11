;;;
;;; geopack.l
;;;	geometric computation package for EUSLISP
;;;	Copyright (1988) Toshihiro MATSUI,Electrotechnical Laboratory
;;;
;;;	revision history
;;;	1988
;;;	 Feb-1	2D convex-hull
;;;	 Feb-5	3D convex-hull
;;;	 Feb-6	cut-body
;;;	 Feb-8	hidden-line eliminated display
;;;	 Feb-14	edge wings removed since they are redundant
;;;	 Aug-12	winged edge is optional	
;;;	 Oct-7	approximated flag for curvatures is added to edge
;;;	1989
;;;	 Oct	MMD Demonstration
;;;	1990
;;;	 Jul--Sep  CSG record
;;;	1991
;;;	 Oct-Nov Allow tolerance for the geometric state discrimination
;;;		 and enable body composition of bodies in contact.
;;;

(eval-when (load eval compile) (in-package "GEOMETRY"))

(require :geoclasses "geoclasses.l")

(export '(*bodies* *parallel-threshold* *coplanar-threshold*
	*epsilon* *contact-threshold* *vertex-neighborhood-threshold*
	*norm-threshold*
	 vplus vector-mean direction-vector
	triangle triangle-normal vector-angle face-normal-vector
	farthest farthest-pair maxindex random-vector 
	random-normalized-vector random-vectors
	edgep facep bodyp primitive-body-p
	n^2 eps= eps< eps> eps<= eps>= eps<> eps-zero
	#| eps-pos  eps-neg eps-nonpos eps-nonneg|#
	eps-in-range eps-v= eps-coords=
	make-bounding-box make-big-bounding-box bounding-box-intersection
	bounding-box-union edgep make-line winged-edge-p
	*edge-class* *face-class* *hole-class* *body-class*
	make-plane *xy-plane* *yz-plane* *zx-plane*
	make-polygon))

;; (export '(inside outside border parallel included))

(defvar  *edge-class*)
(defvar  *face-class*)
(defvar  *body-class*)

(defvar *bodies* nil)

(deflocal *parallel-threshold* 0.01)
(deflocal *coplanar-threshold* 0.01)
(deflocal *epsilon* 0.005)

;; Hirukawa parameters
(deflocal *contact-threshold* 0.008)
(deflocal *vertex-neighborhood-threshold* 0.001)
(deflocal *norm-threshold* 0.1)

(proclaim '(float *parallel-threshold* 
		  *coplanar-threshold*
		  *epsilon*
		  *contact-threshold*))


(defun vplus (vertices)
  "returns a newly created float-vector that is the sum of all the elements of vector-list. The difference from v+ is that vplus computes the sum of more than two arguments and no result vector can be specified"
   (let ((rv (instantiate float-vector  (length (car vertices)))))
      (dolist (v vertices) (v+ v rv rv))
      rv))

(defun vector-mean (vertices)
  "returns the mean vector of vector-list."
   (scale (/ 1.0 (length vertices)) (vplus vertices)))

(defun direction-vector (org dest)
  "(org dest) returns a normalized vector from org to dest"
  (normalize-vector (v- dest org)))

(defparameter triangle-temp1 (float-vector 0 0 0))
(defparameter triangle-temp2 (float-vector 0 0 0))

(defun triangle (a b c &optional (normal #f(0 0 1)))
"(triangle a b c [normal #f(0 0 1)])
a,b,c are floatvectors representing 2 or 3 dimensional points.
Normal is the normal vector of the plane on which a,b and c lie.
Triangle returns 2*area of a triangle constructed by a,b,c.
Triangle is positive if a,b,c turn counter-clockwise.
In other words, if triangle is positive, c locates at the
left hand side of line a-b, and b lies at the right side of ac."
   (v.* (v- b a)	;; triangle-temp1
	(v- c b)	;; triangle-temp2
        normal))

(defun triangle-normal (a b c)
"normal vector for the plane on which three points (a b c) lie."
   (normalize-vector (v* (v- b a) (v- c a))))

(defun vector-angle (v1 v2 &optional (normal (normalize-vector (v* v1 v2))) (parallel-thre 1e-10))
"Compute angle (radian) between two vectors, v1 and v2.
Normal is vertical to both v1 and v2.
v1, v2 and normal must be normalized in advance.
Normal must be given if the sign of the angle is needed."
    (if (< (norm2 (v* v1 v2)) parallel-thre)
        (return-from vector-angle (if (> (v. v1 v2) 0) 0.0 pi)))
    (atan (v.* normal v1 v2) (v. v1 v2)) )

(defun face-normal-vector (vertices)
    (let* ((v1 (first vertices)) (v2) (vlist (rest vertices))
	   (v (float-vector 0 0 0))
	   (normal (float-vector 0 0 0)))
       (while vlist
	 (setq v2 (pop vlist))
	 (v+ (v* v1 v2 v) normal normal)
	 (setq v1 v2))
       (setq v2 (car vertices))
       (v+ (v* v1 v2 v) normal normal)
       (normalize-vector normal normal))      )

(defun farthest (p points)
  ;; in a list of vectors bound to points, find the point farthest from p.
  (let*  ((vv (pop points)) (dist (distance p vv)) (d 0.0))
     (dolist (v points)
	(setq d (distance p v))
	(if (> d dist) (setq vv v dist d)))
     vv))

(defun farthest-pair (points)
  (let* ((v1 (pop points)) (ps points) (v2 (farthest v1 ps))
         (dist (distance v1 v2)) v11 v22 d)
     (while (cdr ps)
	(setq v11 (pop ps))
	(setq v22 (farthest v11 ps))
	(if (> (setq d (distance v11 v22)) dist)
	   (setq v1 v11 v2 v22 dist d)))
     (list v1 v2)))

; select max varing index of a vector
(defun maxindex (fv)
   (declare (type float-vector fv))
   (let ((index 0))
      (if (> (abs (aref fv 1)) (abs (aref fv 0))) (setq index 1)) 
      (if (> (abs (aref fv 2)) (abs (aref fv index))) (setq index 2)) 
      index))

;
; generate 3D floatvector scattered in a box homogeneously about 3 axises.
(defun random-vector (&optional (range 1.0))
   (let ((range/2 (/ range 2)))
     (float-vector (- (random range) range/2)
		   (- (random range) range/2)
		   (- (random range) range/2))))

(defun random-normalized-vector ()
   (normalize-vector (float-vector (random 1.0) (random 1.0) (random 1.0))))

#| Kameyama function
(defun random-normalized-vector2()
  (let ((v1 (- (random 2.0) 1.0))
        (v2 (random 1.0))
        (v3 (- (random 2.0) 1.0)))
    (while (>= (+ (* v1 v1)(* v2 v2)) 1.0)
      (setq v1 (- (* 2.0 (random 1.0)) 1.0)
            v2 (random 1.0)
            v3 (- (* 2.0 (random 1.0)) 1.0)) )
    (float-vector
      %((v1 * v1 - v2 * v2) / (v1 * v1 + v2 * v2) * (sqrt(1.0 - v3 * v3)))
      %((2.0 * v1 * v2) / (v1 * v1 + v2 * v2) * (sqrt(1.0 - v3 * v3)))
      v3) ))
|#

(defun random-vector2 (&optional (s (random 1.0)))
    (scale s
	   (rotate-vector 
		(rotate-vector (float-vector 1 0 0) (random 2pi) :z)
		(random 2pi)
		:y)))


(defun random-vectors (n r)
  (if (< n 1)  nil  (cons (random-vector r) (random-vectors (1- n) r))))

(defun edgep (x) (derivedp x edge))
(defun facep (x) (derivedp x face))
(defun bodyp (x) (derivedp x body))
(defun primitive-body-p (x) (and (bodyp x) (send x :primitive-body-p)))


;;
;; Comparisons with Tolerance
;;

(defun n^2 (n)  (* n n))

(defun eps= (m n &optional (eps *epsilon*))
  (declare (type float m n eps))
  (< (abs (- m n)) eps))

(defun eps< (m n &optional (eps *epsilon*))
  (declare (type float m n eps))
  (< m (- n eps)))

(defun eps> (m n &optional (eps *epsilon*))
  (declare (float m n eps))
  (> m (+ n eps)))

(defun eps<= (m n &optional (eps *epsilon*))
  (declare (float m n eps))
  (< m (+ n eps)))

(defun eps>= (m n &optional (eps *epsilon*))
  (declare (float m n eps))
  (> m (- n eps)))

(defun eps<> (m n &optional (eps *epsilon*))  (not (eps= m n eps)))

(defun eps-zero (n &optional (eps *epsilon*))  (eps= n 0.0 eps))

#|
(defun eps-pos (n &optional (eps *epsilon*))  (eps> n 0.0 eps))


(defun eps-neg (n &optional (eps *epsilon*))  (eps< n 0.0 eps))

(defun eps-nonpos (n &optional (eps *epsilon*))  (eps<= n 0.0 eps))

(defun eps-nonneg (n &optional (eps *epsilon*))  (eps>= n 0.0 eps))
|#

(defun eps-in-range (a b c &optional (eps *epsilon*))
   (declare (float a b c eps))
   (<= (- a eps)
       b
       (+ c eps)))

(defun eps-v= (v1 v2 &optional (eps *epsilon*))
   (eps= (distance v1 v2) 0.0 eps))

(defun eps-coords= (c1 c2 &optional (th1 *epsilon*) (th2 th1)
				      &aux (d (coordinates-distance c1 c2)))
   (and (< (car d) th1)
	(or (null (second d)) (< (second d) th2))))


;;;;    data structures for geometric models
;;;;    1987-June-9    T.Matsui
;;;;	
;;;	edge, face, hole, body are defined by classes
;;;	vertices are represented by floatvectors
;;;
;;;	1988-Feb 	:insidep bug fix
;;;			class plane added
;;;	1991-Oct	speed up of body-interference using more box checks
;;;

(setq surrounding-box bounding-box)
(defmethod bounding-box
  (:box (&optional tol) 
      (if tol (send self :grow tol) self))
  (:minpoint () minpoint)
  (:maxpoint () maxpoint)
  (:center () (midpoint 0.5 minpoint maxpoint))
  (:diagonal () (v- maxpoint minpoint))
  (:prin1 (&optional (strm t))
     (send-super :prin1 strm (format nil "~s/~s" minpoint maxpoint)))
  (:inner (point) (and (v< point maxpoint) (v> point minpoint)))
  (:intersection (box &optional (tolerance))
    ;; returns common minimal box for box and self.
    ;; nil, if no intersection
    (declare (type bounding-box box))
    (let ((v1 (vmax minpoint (bounding-box-minpoint box)))
	  (v2 (vmin maxpoint (bounding-box-maxpoint box))))
       (when tolerance
	  (setq tolerance (float-vector tolerance tolerance tolerance))
	  (v- v1 tolerance v1)
	  (v+ v2 tolerance v2))
       (if (v< v1 v2)
	   (instance bounding-box :init2 v1 v2)
	   nil)))
  (:union (box &optional (tolerance))
    (declare (type bounding-box box))
    (instance bounding-box :init2
	(vmin minpoint (bounding-box-minpoint box))
	(vmax maxpoint (bounding-box-maxpoint box))
	tolerance))
  (:intersection-p (box)	;returns just t or nil
    (declare (type bounding-box box))
    (v< (vmax minpoint (bounding-box-minpoint box))
	(vmin maxpoint (bounding-box-maxpoint box))) )
 (:grow (s &optional (abs nil))
    (setq s 
	  (if abs (float-vector s s s) (scale s (v- maxpoint minpoint))))
    (v- minpoint s minpoint)
    (v+ maxpoint s maxpoint)
    self)
 (:volume ()
    (let ((a (v- maxpoint minpoint)))
       (* (aref a 0) (aref a 1) (aref a 2))))
 (:extream-point (dir)
    (let* ((dim (length minpoint)) (p (instantiate float-vector dim)))
       (dotimes (i dim)
	  (setf (aref p i)
		(aref (if (> (aref dir i) 0.0) maxpoint minpoint)
		      i)) )
       p))
 (:below (box2 &optional (dir #f(0 0 1)))	;is this box below box2?
    (let ((ex1 (send self :extream-point dir))
	  (ex2 (send box2 :extream-point (scale -1.0 dir))))
      (< (v. dir ex1) (v. dir ex2))))
 (:corners ()
    (let (r v (dim (length minpoint)))
      (dotimes (i (expt 2 dim))
	(setq v (instantiate float-vector dim))
	(dotimes (j dim)
	   (setf (aref v j)
		 (if (logbitp j i)
		     (aref maxpoint j)
		     (aref minpoint j))) )
	(push v r) )
     r))
 (:body ()
    (let ((v0 (copy-seq minpoint)) (v1 (copy-seq minpoint))
	  (v2 (copy-seq minpoint)) (v3 (copy-seq minpoint)) )
       (setf (aref v1 1) (aref maxpoint 1)
	     (aref v2 1) (aref maxpoint 1)
	     (aref v2 0) (aref maxpoint 0)
	     (aref v3 0) (aref maxpoint 0))
       (make-prism (list v0 v1 v2 v3) (- (aref maxpoint 2) (aref minpoint 2)))))
 (:init2 (v1 v2 &optional tolerance)	;fast init
    (setq minpoint (vmin v1 v2)
	  maxpoint (vmax v1 v2))
    (if tolerance (send self :grow tolerance))
    self)
 (:init (v &optional (tolerance))	;v is a list of flt vectors
    (setq minpoint (apply #'vmin v)
	  maxpoint (apply #'vmax v))
    (if tolerance (send self :grow tolerance))
    self)
  )

(defun make-bounding-box (vlist &optional (tolerance *contact-threshold*))
   (instance bounding-box :init vlist tolerance))
(defun make-big-bounding-box ()
   (make-bounding-box (list (float-vector -1e20 -1e20 -1e20)
			    (float-vector 1e20 1e20 1e20))) )
(defun bounding-box-intersection
	 (boxes &optional (tolerance *contact-threshold*) &aux newbox)
   (setq newbox (send (pop boxes) :box))
   (dolist (b boxes)
      (setq newbox (send newbox :intersection (send b :box) tolerance))
      (unless newbox (return-from bounding-box-intersection nil)))
   newbox)

(defun bounding-box-union 
	 (boxes &optional (tolerance *contact-threshold*) &aux newbox)
   (setq newbox (send (pop boxes) :box))
   (dolist (b boxes)
      (setq newbox (send newbox :union (send b :box))))
   newbox)

;;;
;;;	LINE and EDGE
;;;
;;;		\     /
;;;	 pcwing	 \   / nwing
;;;		  \ /
;;;		   @ nvert
;;;		   |
;;;	  Pface	   |      Nface
;;;		   |
;;;		   @ pvert
;;;		  / \
;;;	 pwing	 /   \ ncwing
;;;		/     \
;;;
;;;	wings are removed because they can be retrieved by looking for
;;;	in the edges list described in a face
;;;


#|
(defun edgep (x) (derivedp x edge))
|#

(defmethod line
 (:nvertex (&optional f) nvert)
 (:pvertex (&optional f) pvert)
 (:vertices () (list pvert nvert))
 (:eq (ln2)
    (and (eq (line-pvert ln2) pvert)
	 (eq (line-nvert ln2) nvert)))
 (:eql (ln2)
    (or (and (eq (line-pvert ln2) pvert) (eq (line-nvert ln2) nvert))
	(and (eq (line-pvert ln2) nvert) (eq (line-nvert ln2) pvert))) )
 (:equall (ln2)
    (or (and (equal (line-pvert ln2) pvert) (equal (line-nvert ln2) nvert))
	(and (equal (line-pvert ln2) nvert) (equal (line-nvert ln2) pvert))) )
 (:parameter (point)
    (let* ((a (v- nvert pvert)) 
	   (b (v- point pvert)))
	(/ (v. a b) (v. a a))))
 (:point (p)
    (declare (type float p))
    ;For the parametric representation of an edge,
    ;	v = pvert*(1-p) + nvert*p ,  0<p<1
    ;compute the point vector corresponding to the parameter p.
    ;(v+ (scale (- 1.0 p) pvert) (scale p nvert))
    (midpoint p pvert nvert))
 (:box (&optional (tolerance))
    (instance bounding-box :init2 pvert nvert tolerance))
 (:boxtest (box &optional tolerance)
    (let* ((c (send self :box tolerance))
	   (r (send box :intersection-p c)) )
	;;(sys:reclaim-tree c) ;; segfaults if GC occured
	r))
 (:length () (distance pvert nvert))
 (:end-point (v)
    (if (eq pvert v) v (if (eq nvert v) v nil)))
 (:direction () (normalize-vector (v- nvert pvert)))
 (:prin1 (strm)
    (flet ((string-float-vector (fv)
		(let ((s (make-string-output-stream 30)))
		   (princ "#f(" s)
		   (dotimes (i (length fv))
			(format s "~3,2f " (aref fv i)))
		   (setf (stream-count s) (1- (stream-count s)))
		   (princ ")" s)
		   (get-output-stream-string s))))
    (send-super :prin1 strm 
		(string-float-vector pvert)
		(string-float-vector nvert))) )
 (:init (&key ((:pvertex pv)) ((:nvertex nv)) &allow-other-keys)
    (if pv (setq pvert pv))
    (if nv (setq nvert nv))
    self))

;;;
;;;Enhancement by H.Hirukawa
;;;
(defmethod line
 (:foot (point &aux (a (v- pvert nvert)))
    (declare (type float-vector point))
    (/ (v. a (v- pvert point))
       (v. a a)))
 (:common-perpendicular (l)
    (declare (type line l) (type float det c11 c12 c21 c22 a b)
	     (type float-vector v1 v2))
    (let (det c11 c12 c21 c22 a b v1 v2)
      (setq c11 (norm (v- (l . nvert) (l . pvert))))
      %(c11 = - (c11 * c11))
      (setq c12 (v. (v- nvert pvert) (v- (l . nvert) (l . pvert))))
      %(c21 = - c12)
      %(c22 = norm(v-(nvert pvert)))
      %(c22 = c22 * c22)
      %(det = c12 * c12 + c11 * c22)
      (if (< (abs det) *parallel-threshold*)
	  (return-from :common-perpendicular ':parallel)
	  (progn
	    (setq a (v. (v- nvert pvert) (v- (l . pvert) pvert)))
	    (setq b (v. (v- (l . nvert) (l . pvert)) (v- (l . pvert) pvert)))
	    (setq v1 (send self :point %((c11 * a + c12 * b) / det)))
	    (setq v2 (send l :point    %((c21 * a + c22 * b) / det)))
	    (return-from :common-perpendicular (list v1 v2)))))))

(defmethod line
 (:distance-point (p &aux (par (send self :foot p)))
   (declare (float par))
   (cond
      ((> par 1) (distance nvert p))
      ((< par 0) (distance pvert p))
      (t (distance (send self :point par) p))))
 (:distance-line (ln)
  (let* ((B1 (ln . pvert)) (B2 (ln . nvert))
	 ta tb pa pb dist para dab1 dab2 dba1 dba2 xa xb
	 (a (v- nvert pvert))  (b (v- b2 b1))
	 (ab (v. a b)) (aa (v. a a)) (bb (v. b b))
	 (x (v- pvert b1)))
    (declare (float ab aa bb))
    (setq para (- (* ab ab) (* aa bb)))
    (if (> (abs para) 0.0001)
	(progn
	    (setq xa (v. x a)
		  xb (v. x b))
	    (setq ta %((bb * xa - ab * xb) / para))
	    (setq tb %((ab * xa - aa * xb) / para))
	    (if (and (< 0.0 ta 1.0) (< 0.0 tb 1.0))
		(return-from :distance-line
		   (distance  (send self :point ta) (send ln :point tb))))))
    (setq dab1 (send self :distance-point b1)
	  dab2 (send self :distance-point b2)
	  dba1 (send ln :distance-point pvert)
	  dba2 (send ln :distance-point nvert))
    (min dab1 dab2 dba1 dba2)
    ))
 (:distance (point)
    (distance point (send self :point (send self :foot point))))
 (:distance (x)
    (cond ((float-vector-p x) (send self :distance-point x))
	  ((derivedp x line) (send self :distance-line x))))
)

(defmethod line
 (:colinear-point (p &optional (tol *coplanar-threshold*))
    (colinear-p pvert p nvert tol))
 (:on-line-point (pnt  &optional (tol *coplanar-threshold*) &aux param)
   ;; (setq param (colinear-p pvert pnt nvert tol))
   ;; (and param (eps-in-range 0.0 param 1.0))
   ;; chagend Jan/31/1996, T. Matsui
   (eps<= (+ (distance pvert pnt) (distance pnt nvert))
	  (distance pvert nvert)
	  tol)
   )
 (:colinear-line (ln &optional (tol *coplanar-threshold*))
    (let ((p1 (send self :colinear-point (line-pvert ln) tol))
	  (p2 (send self :colinear-point (line-nvert ln) tol)))
      (and p1 p2 t) ))
 (:colinear-line-intersection (ln2)
     ;; ln2 must be colinear with this line.
     ;; find overlapping portion between two lines.
     (let* ((pv2 (line-pvert ln2)) (nv2 (line-nvert ln2))
	    (p2 (send self :parameter pv2)) (n2 (send self :parameter nv2))
	    p1 n1)
	(if (> p2 n2) (psetq n2 p2 p2 n2))
	(cond ((or (< n2 0.0) (> p2 1.0)) nil)	;no overlapping
	      (t
		(setq p1 (max 0.0 p2)
		      n1 (min 1.0 n2) )
		(make-line (send self :point p1) (send self :point n1))))))
 (:coplanar (ln &optional (tolerance *coplanar-threshold*))
    (coplanar-p pvert nvert (line-pvert ln) (line-nvert ln) tolerance))
 (:project (pln)
    (list (send pln :project pvert) (send pln :project nvert)))
 (:intersection (ln)
    (line-intersection3 pvert nvert (line-pvert ln) (line-nvert ln)))
 (:intersect-line (ln &optional (tolerance *parallel-threshold*))
    (declare (line ln))
    ;; ln must be coplanar with this line
    (let* ((p (line-intersection3 pvert nvert (line-pvert ln) (line-nvert ln)
				  tolerance))
	   (p1 (first p)) (p2 (second p)) pnt1 pnt2
	   q1 q2)
	(cond ((null p)		;; colinear or parallel
		(setq p1 (send self :colinear-point (line-pvert ln)) )
		(unless p1	;no intersection
		   (return-from :intersect-line ':parallel)) 
		;; (print (list self ln p1 p2))
		(setq p2 (send self :colinear-point (line-nvert ln)))
		(unless p2	;no intersection
		   (return-from :intersect-line ':parallel)) 
		(if (< p2 p1) (psetq p1 p2 p2 p1))
		(if (or (eps< p2 0.0) (eps> p1 1.0))
		    (return-from :intersect-line ':outside)) 
		;; there must be overlapping segment
		(setq q1 (send ln :colinear-point pvert)
		      q2 (send ln :colinear-point nvert))
		(unless (and q1 q2)	;no intersection
		   (return-from :intersect-line ':parallel)) 
		(if (< q2 q1) (psetq q1 q2 q2 q1))
		(list ':colinear (list (max 0.0 p1) (min 1.0 p2))
				 (list (max 0.0 q1) (min 1.0 q2)) ))
	      ((and (eps-in-range 0.0 p1 1.0) (eps-in-range 0.0 p2 1.0))
                 (list ':intersect p1 p2))
	      (t nil))))
)


(defun make-line (p n) (instance line :init :pvertex p :nvertex n))

(defmethod edge
  (:faces () (list pface nface))
  (:pvertex (f)
    (cond ((eq f pface) pvert)
	  ((eq f nface) nvert)
	  (t (error "bad face"))))
  (:nvertex (f)
    (cond ((eq f pface) nvert)
	  ((eq f nface) pvert)
	  (t (error "bad face"))))
  (:next-edge (f)  (send f :next-edge self))
  (:next-vertex (f) (send (send f :next-edge self) :nvertex f))
  (:direction (&optional (f pface))	;directed edge direction
    (cond ((eq f pface) (normalize-vector (v- nvert pvert)))
	  ((eq f nface) (normalize-vector (v- pvert nvert)))
	  ((facep f)
	   (dolist (h (send f :holes))
		(if (memq self (send h :edges))
		    (return-from :direction (send self :direction h))))
	   (error "hole for :direction"))
	  (t  (error "hole for :direction"))))
  (:next-edge-angle (f)
    (vector-angle
	(send self :direction f)
	(send (send f :next-edge self) :direction f)
	(send f :normal)))
  (:previous-edge-angle (f)
    (vector-angle
	(send self :direction f)
	(send (send f :previous-edge self) :direction f)
	(send f :normal)))
  (:body ()
    (cond (pface (send pface :body))
	  (nface (send nface :body))) )
  (:pface (pv nv)
      (cond ((and (eql pv pvert) (eql nv nvert)) pface)
	    ((and (eql nv pvert) (eql pv nvert)) nface)
	    (t (error "inconsistent pvert and nvert for :pface"))))
  (:nface (pv nv)
      (cond ((and (eql pv pvert) (eql nv nvert)) nface)
	    ((and (eql nv pvert) (eql pv nvert)) pface)
	    (t (error "inconsistent pvert and nvert for :nface"))))
  (:another-face (fac)
     (if (eq fac pface)
	 nface
	 (if (eq fac nface)
	     pface
	     (warn "no such face"))))
  (:binormal (f)
     (normalize-vector (v*  (cond ((eq f pface) (v- nvert pvert))
				  ((eq f nface) (v- pvert nvert))
				  (t (send self :error "bad face")))
			    (send f :normal))))
  (:angle () angle)	;angle between pface and nface
  (:approximated-p () (eq (logand flags 1) 1))
  (:flags () flags)
  (:contourp (viewpoint)
     "is this a contour edge when observed from viewpoint?"
     (if (and pface nface)
	 (let ((pdist (send pface :distance viewpoint))
	       (ndist (send nface :distance viewpoint)))
	  (or (and (< pdist 0.0) (> ndist 0.0))
	      (and (> pdist 0.0) (< ndist 0.0))))
	 t )	;T if this edge does not have two adjacent faces
   )
  (:set-approximated-flag   (&optional (threshold 0.7))
   (if (< (- threshold) angle threshold)
       (setq flags (logior flags 1))
       (setq flags (logand flags (lognot 1)))))
  (:invert ()	;reverse edge direction
   (let (temp)
     (setq temp nface    nface pface    pface temp))
     self)
  (:set-angle   ()
   (setq angle (vector-angle (face-normal pface)
			     (face-normal nface)
			     (normalize-vector (v- nvert pvert)))))
  (:set-face (pv nv f)
     (cond
      ((and (eq pv pvert) (eq nv nvert)) (setq pface f))
      ((and (eq nv pvert) (eq pv nvert)) (setq nface f))
      (t (send self :error "inconsistent face setting"))))
  (:contact (e)	;Hirukawa
    (let ((feet (send self :common-perpendicular e))
	  (clearance *contact-threshold*)
	  (vertex-neighborhood *vertex-neighborhood-threshold*))
      (if (not (eq feet ':parallel))
	  (if (and (< (norm (v- (first feet) (second feet))) clearance)
		   (< vertex-neighborhood
		      (send self :parameter (first feet))
		      (- 1.0 vertex-neighborhood))
		   (< (* -1.0 vertex-neighborhood)
		      (send e :parameter (first feet))
		      (+ 1.0 vertex-neighborhood)))
	      (first feet)))))
  (:neighborpoints (point)	;Hirukawa
     (list (send self :anothervertex point)
	   (v- (scale 2.0 point) (send self :anothervertex point)) 
	   (v+ point (v* (pface . normal) (v- nvert pvert)))
	   (v+ point (v* (nface . normal) (v- pvert nvert)))))
  (:anothervertex (point)	;Hirukawa
     (if (> (abs (norm (v- pvert point))) *norm-threshold*)
	 pvert
         nvert))
  (:color (&optional new)
    (if new (setf (get self :color) new)
	    (if (setq new (get self :color)) new (send pface :color))))
  (:init (&rest args
	  &key ((:pface pf)) ((:nface nf)) ((:angle ang)) (approximated nil)
	  ((:flags f) 0) &allow-other-keys)
   (apply   #'send-message
	    self (class . super)   :init args)
   (if pf (setq pface pf))
   (if nf (setq nface nf))
   (if ang (setq angle ang))
   (setq flags f)
   (if approximated (send self :set-approximated-flag))
   self) )

(defmethod edge
  (:center-coordinates   ()
   (let* ((z (normalize-vector (v- nvert pvert)))
	  (x (if (< (distance z #f(1 0 0)) 0.0001)
		 #f(0 1 0) #f(1 0 0)))
	  (y (v* z x)))
     (setq x (v* y z))
     (instance coordinates :init
	       :rot (transpose (matrix x y z))
	       :pos (scale 0.5 (v+ nvert pvert y))))   )  )

;;
;; methods to find winged edges
;;

(defmethod edge
 (:pwing ()
    (let ((circuit (send pface :all-edges)))
      (dolist (e circuit)
	(declare (edge e))
        (if (and (not (eq e self))
	         (or (eq (e . pvert) pvert) (eq (e . nvert) pvert)))
	     (return-from :pwing e)))
      (error "pwing?")))
 (:pcwing ()
    (let ((circuit (send pface :all-edges)))
      (dolist (e circuit)
	(declare (edge e))
        (if (and (not (eq e self))
	         (or (eq (e . pvert) nvert) (eq (e . nvert) nvert)))
	        (return-from :pcwing e)))
      (error "pcwing?")))
 (:nwing ()
    (let ((circuit (send nface :all-edges)))
      (dolist (e circuit)
	(declare (edge e))
        (if (and (not (eq e self))
	         (or (eq (e . pvert) nvert) (eq (e . nvert) nvert)))
	        (return-from :nwing e)))
      (error "nwing?")))
 (:ncwing ()
    (let ((circuit (send nface :all-edges)))
      (dolist (e circuit)
	(declare (edge e))
        (if (and (not (eq e self))
	         (or (eq (e . pvert) pvert) (eq (e . nvert) pvert)))
	        (return-from :ncwing e)))
      (error "ncwing?")))
 (:connected-vertex (e)
    (declare (edge e))
    (cond ((eq (e . pvert) pvert) pvert)
	  ((eq (e . pvert) nvert) nvert)
	  ((eq (e . nvert) pvert) pvert)
	  ((eq (e . nvert) nvert) nvert)
	  (t (error "not connected"))))
 (:replace-face (f newface)
    (cond ((eql f pface) (setq pface newface))
	  ((eql f nface) (setq nface newface))
	  (t (error "no such face" self f))))
 )

(defun winged-edge-p (x) (derivedp x winged-edge))

(defmethod winged-edge
 (:set-wings ()
    (setq pwing  (send-super :pwing)
	  nwing  (send-super :nwing)
	  pcwing (send-super :pcwing)
	  ncwing (send-super :ncwing) )
    self)
 (:pwing () pwing)
 (:nwing () nwing)
 (:pcwing () pcwing)
 (:ncwing () ncwing)
 (:init (&rest args
	 &key ((:pwing pw)) ((:nwing nw)) ((:pcwing pcw)) ((:ncwing ncw))
	      &allow-other-keys)
    (apply  #'send-message
	    self (class . super)   :init args)
    (if pw (setq pwing pw))
    (if nw (setq nwing nw))
    (if pcw (setq pcwing pcw))
    (if ncw (setq ncwing ncw))
    self))


;;;
;;; planar objects   PLANE, POLYGON, FACE and HOLE
;;;

#|
(defparameter *reformx* 2)
(defun reformx (vi)
  (let ((xi *reformx*))
   (cond ((= vi 0) 0)
         ((< vi 0) (- (exp (* xi (log (- vi))))))
         (t (exp (* xi (log vi)))))))
|#

(defmethod plane
  (:id () nil)
  (:normal () normal)
  (:distance (point) (+ (v. point normal) distance))
  ;; Here, :plane-distance is similarly defined as :distance,
  ;; because :distance may be overridden by subclasses.
  (:plane-distance (point) (+ (v. point normal) distance))
  (:on-plane-p (point &optional (tolerance *epsilon*))
    (eps<= (abs (send self :plane-distance point)) tolerance))
  (:coplanar-point (point &optional (tolerance *coplanar-threshold*))
     (eps=  (+ (v. point normal) distance) 0.0 tolerance))
  (:coplanar-line (ln &optional (tolerance *coplanar-threshold*))
     (and   (eps=  (+ (v. (line-pvert ln) normal) distance) 0.0 tolerance)
	    (eps=  (+ (v. (line-nvert ln) normal) distance) 0.0 tolerance)))
  (:intersection (pv nv)
     ; returns parameter of the intersection point
     (let* ((nn (v. normal nv))
	    (np (v. normal pv))
	    (npnn %(np - nn)))
	   (declare (type float nn np npnn))
#-:ieee-floating-point
	   (if (< (abs npnn) 1.0e-10) (return-from :intersection :parallel))
	   %((distance + np) / npnn)))
  (:intersect-edge (eg)
     (declare (type edge eg))
     (let ((param (send self :intersection (eg . pvert) (eg . nvert))))
	(if (eps-in-range 0.0 param 1.0)
	    (list param (send eg :point param))
	    (if (or (= 0.0 param) (= 1.0 param))
		(format t ";; intersect-border~%" )))))
  (:foot (point)
    ; projection of point onto this plane
    (let ((numerator %(v.(normal point) + distance))  )
	   (declare (float numerator))
	   (v- point (scale numerator normal))) )
  (:original-body () nil)	;for subclass's combatibility
  (:brightness (light-source)
;      (if (> (norm light-source) 2.0)
;	  (setq light-source (normalize-vector
;				 (v- light-source (car vertices)))))	; point light-source
      (+ 1.0 (/ (v. normal light-source) 2.0)))	;parallel lighting
  (:project  (&optional (point (float-vector 0 0 0)))
      (declare (float-vector point))
      (v- point (scale (+ distance (v. point normal)) normal)) )
  (:separation (mypoints hispoints) 	;Hirukawa
    (let (d (sign1 0) (sign2 0))
      ; check if the distances between the separating plane and all points
      ; in each neighborhood have same signs 
      (dolist (p mypoints)
	(setq d (send self :distance p))
	(if (> (abs d) *norm-threshold*)
	    (if (minusp (* d sign1))
		(return-from :separation nil)
	      (if (> (abs d) (abs sign1)) (setq sign1 d)))))
      (dolist (p hispoints)
	(setq d (send self :distance p))
	(if (> (abs d) *norm-threshold*)
	    (if (minusp (* d sign2)) 
		(return-from :separation nil)
	      (if (> (abs d) (abs sign2)) (setq sign2 d)))))
      ; check if both signs are different
      (if (minusp (* sign1 sign2)) (normalize-vector (scale sign1 normal)))))
  (:init (n apoint)
	 ;defines a plane whose normal is n and passes on apoint
	 (setq normal n)
	 (if (float-vector-p apoint)
	     (setq  distance (- (v. normal apoint)))
	     (if (numberp apoint)
		 (setq distance (float apoint))
		 (error "float or float-vector expected")))
	 self)
  )

;;
;; methods for POLYGON
;;
;;(defclass POLYGON  :super  plane
;;  :slots
;;  (convexp	;if convex, t, concave, nil;
;;   edges		;profile edge list
;;   vertices	;profile vertex list
;;   (model-normal :type float-vector) ;surface-normal before transformation
;;   (model-distance :type float)
;;   ))

(defmethod polygon	; topologies
 (:face () self)
 (:edges () edges)
 (:edge (n) (nth n edges))
 (:all-edges () edges)
 (:vertices () vertices)
 (:vertex (n) (nth n vertices))
 (:next-edge (e)
    (setq e (memq e edges))
    (if (cdr e) (cadr e) (car edges)))
 (:previous-edge (e)
    (if (eq (car edges) e)
	(car (last edges))
	(let ((x edges))
	      (while (cdr x)
		(if (eql (cadr x) e) (return-from :previous-edge (car x)))
		(pop x))
	      )) )
 (:adjacent-faces (&aux flist pf nf)	;list all faces connected to self
    (dolist (e edges)
	(setq pf (edge-pface e) nf (edge-nface e))
	(push (if (eq pf self) nf pf) flist))
    flist)
 (:convexp () convexp))
	
(defmethod polygon	;properties
 (:box (&optional tolerance)
    (instance bounding-box :init vertices tolerance))
 (:boxtest (box &optional tolerance)
    (send (send box :box tolerance) :intersection
	  (instance bounding-box :init vertices tolerance)))
 (:vertices-mean ()  (vector-mean (cdr vertices)))
 (:distance (point)
    (let (foot (sign (signum (send self :plane-distance point))))
       (setq foot (send self :foot point))
       (if (= sign 0.0)	;; on the same plane
	   (if (memq (send self :insidep foot) '(:inside :parallel))
	       0.0
	       (apply #'min (send-all edges :distance point)))
	   (* sign 
	      (if (memq (send self :insidep foot) '(:inside :parallel))
	          (distance foot point)
	          (apply #'min (send-all edges :distance point))))) ))
 (:area ()
   (let* ((vs vertices) (c (vector-mean vs)) (s 0.0))
      (while (cdr vs)
	 (inc s (triangle (car vs) (cadr vs) c normal))
	 (pop vs))
      (/ s 2.0)))
 (:perimeter () (apply #'+ (send-all edges :length)))
 (:volume (&optional (point #f(0 0 0)))
    (/ (* (send self :plane-distance point)
	  (send self :area))
       -3.0))
 (:centroid (&optional point)	;returns the center of gravity and area
   (let* ((vs vertices) (a) (b) (c (vector-mean vs))
	  (s 0.0) (total-area 0.0)
	  (g (float-vector 0 0 0)) (temp (float-vector 0 0 0)))
      (while (cdr vs)
	 (setq  a (pop vs)  b (car vs)  s (triangle a b c normal))
	 (inc total-area s)
	 (v+ a b temp) (v+ c temp temp)
	 (v+ g (scale (/ s 3.0) temp) g))
      (setq  g (scale (/ 1.0 total-area) g)
	     total-area (/ total-area 2.0))
      (if point
	  (list (/ (* total-area (send self :plane-distance point)) -3.0)
		(v+ (scale 0.75 g) (scale 0.25 point)))
	  (list total-area g))      ))
 (:color (&optional new)
    (if new (setf (get self :color) new))
    (get self :color))
)

(defmethod polygon	;methods for intersection and point-location
 (:insidep (point &optional (*epsilon* *epsilon*))
   (let (v1 v2 (theta 0.0) param th radials)
     (declare (type float-vector v1 v2)
	      (type float th theta param))
     (cond (convexp
	    (setq v2 (car vertices))
	    (dolist (v1 (cdr vertices))
		(setq th  (triangle v2 v1 point normal))
		(cond ((eps-zero (/ th (distance v2 v1)))
			;; be careful, th might be NaN
		       (setq param 
			     (let ((a (v- v1 v2)) (b (v- point v2)))
				(/ (v. a b) (v. a a))))
			;; if (v1==v2), param might be NaN and
			; eps-in-range is evaluated to be T
		       (if (eps-in-range  0.0 param 1.0)
			   (return-from :insidep ':border)) )
		      ((< th 0.0) (return-from :insidep ':outside)))
		   (setq v2 v1))
		':inside)
	    (t
	     (if (send self :on-vertex point) (return-from :insidep ':border))
	     (setq radials (mapcar #'(lambda (v) (direction-vector point v))
				   vertices))
	     (setq v2 (pop radials))
	     (while radials
		(setq v1 (pop radials))
		(setq th (vector-angle v1 v2 normal))
		(if (eps= (abs th) pi)
		    (return-from :insidep ':border))
		(setq theta (+ theta th))
		(setq v2 v1))
	     ;; (if *debug* (format t ";; theta=~s~%" theta))
	     (if (> (the float (abs theta)) pi) ':inside ':outside) ))))
 (:intersect-point-vector (point vnorm)	;intersection with semi-line
    (declare (float-vector point vnorm))
    (let ((dnm (v. normal vnorm)) p ip)
      (declare (float dnm p) (float-vector ip))
      (if (< (abs dnm) *parallel-threshold*)
	  (return-from :intersect-point-vector '(:parallel)))
      (setq p (/ (- 0.0 (v. normal point) distance) dnm))
      (if (< p 0.0) (return-from :intersect-point-vector '(:outside)))
      (setq ip (v+ point (scale p vnorm)))	;intersection point address
      (list (send self :insidep ip) ip)))
 (:intersect-line (p1 p2)
    (let ((ip (send self :intersection p1 p2)) pnt flag)
      (declare (type float ip))
      (if (and (eps-in-range 0.0 ip 1.0)
	       (memq (send self :insidep (setq pnt (midpoint ip p1 p2)))
		     '(:inside :border)) )
	  (list ip pnt)
	  nil)))
 (:intersect-edge (e)
    (declare (type edge e))
    (send self :intersect-line (e . pvert) (e . nvert)))
 (:intersect-face (f &optional (cbox (send (send self :box) :intersection
				     (send f :box)))  )
    (dolist (e edges)
	(if (and cbox
		 (send cbox :intersection-p (send e :box))
		 (send f :intersect-edge e))
	    (return-from :intersect-face t))) 
    nil) )

(defmethod polygon
 (:visible (vp)	(if (> (send self :plane-distance vp) 0.0) self nil))
 (:transform-normal (c)
    (let ((inv (send c :inverse-transformation)))
       (setq distance (+ distance (v. (coordinates-pos inv) normal))
	     normal (transform normal (coordinates-rot inv))))
    normal)
 (:reset-normal ()
    (setq normal (face-normal-vector (rest vertices))
          distance (- (v. normal (car vertices)))))
 (:set-convexp ()
    (let ((verts (append vertices (list (cadr vertices)))))
       (setq convexp t)
       (while (cddr verts)
	  (when (< (triangle (pop verts) (car verts) (cadr verts) normal) 0.0)
	      (setq convexp nil verts nil))))
    convexp)
 (:invert ()	;inside-out this face
    (setq vertices (nreverse vertices))
    (setq edges (nreverse edges))
    (scale -1.0 normal normal)
    (scale -1.0 model-normal model-normal)
    (setq distance (* -1.0 distance)
	  model-distance (* -1.0 model-distance))
    (send self :set-convexp))
 (:init (&key ((:vertices ver)) ((:edges edg))		;init hole
	      ((:normal nor)) ((:distance dis)))
    ;prepare edges and vertices
    (cond 
	(edg
         (setq edges edg)
	 (cond ((null ver)
	        (dolist (e edg)  (push (send e :nvertex (send self :face)) ver))
		(setq ver (nreverse ver))
		(setq vertices (cons (send (car edg) :pvertex (send self :face))
			          ver)))
	       (t (setq vertices (append (last ver) ver)))))
        (ver	;no edges given; vertices are used to make new edges
	 (setq vertices (append (last ver) ver))
	 (while ver
	   (push (instance *edge-class* :init
				:pvertex (pop ver)
				:nvertex (if ver (car ver) (cadr vertices)) 
				:pface self)
		 edges))
	 (setq edges (nreverse edges))) )
    (if nor (setq normal nor) (send self :reset-normal))
    (if dis (setq distance dis))
    (setq model-normal (copy-seq normal)
	  model-distance distance)
    ; compute convexp
    (send self :set-convexp)
    self)  )

(defmethod polygon
 (:on-vertex (p &optional (*epsilon* *contact-threshold*) &aux res)
    (dolist (v (cdr vertices))
	(if (eps-v= p v)  (push v res)))
    res)
 (:on-edge (p &optional (tolerance *contact-threshold*) &aux res)
    (dolist (e edges)
	(if (send e :on-line-point p tolerance)
	    (push e res)))
    res)
 (:coplanar-distance (pnt)
    (if (member (send self :insidep pnt) '(:inside :parallel))
        :inside
	(apply #'min (send-all edges :distance pnt)))
    )
 (:coplanar-intersections (cr &optional (tolerance *coplanar-threshold*))
    ;; cr is a polygon
    ;; checks edge-by-edge intersections between each pair of edges
    ;; of two coplanar faces
    (let ((b (bounding-box-intersection (list self cr) tolerance))
	      ints)
	(unless b (return-from :coplanar-intersections nil))
	(dolist (edge1 edges)
	     (let (r int)
	        (dolist (edge2 (send cr :edges))
		   (setq int (send edge1 :intersect-line edge2))
		   (if (consp int)
		       (push (cons edge2 int) r)))
		(if r (push (cons edge1 r) ints)) ) )
	  (if ints (return-from :coplanar-intersections (nreverse ints)))
	  (dolist (v (cdr vertices) nil)
	    (if (and (send b :inner v)
		     (memq (send cr :insidep v) '(:inside :border)))
	        (return-from :coplanar-intersections ':included)))
	  (dolist (v (send cr :vertices) nil)
	    (if (and (send b :inner v)
		     (memq (send self :insidep v) '(:inside :border)))
	        (return-from :coplanar-intersections :including))))
	nil)
 (:contact-edge (p &optional (tolerance *contact-threshold*))	;hirukawa
    (let* ((pv (line-pvert p)) (nv (line-nvert p))
	   (d1 (send self :plane-distance pv))
	   (d2 (send self :plane-distance nv)))
       (cond ((or (> (abs d1) tolerance)
		  (> (abs d2) tolerance)
		  (null (send self :boxtest p 0.001)))
	      ':outside)
	     ((or (eql (send self :insidep pv tolerance) ':inside)
		  (eql (send self :insidep nv tolerance)) )
	      t)) ))
 (:contact-plane (f &optional (tolerance *contact-threshold*))
    ;; test face-to-face contact with f
    (if (and (eps= (v. normal (send f :normal)) -1.0)	;opposing
	     (eps= (- distance) (plane-distance f)))	;coplanar
	(send self :coplanar-intersections f tolerance)
	nil))
 (:contact-point (p &optional (tolerance *contact-threshold*))
   ;; polygon vs vertex contact check
   (let ((d (send self :plane-distance p))) 
      (if (< tolerance (abs d))
	  ':outside
          (send self :insidep  (v- p (scale d normal))) ) ))
 (:contactp (p &optional (tolerance *contact-threshold*))
    (cond ((float-vector-p p) (send self :contact-point p tolerance))
	  ((derivedp p line)  (send self :contact-edge p tolerance))
	  ((derivedp p plane) (send self :contact-plane p tolerance)))) )

(defmethod polygon 
 (:aligned-plane (f)
    (if (and (eps= (v. normal (send f :normal)) 1.0)	;similar direction
	     (eps= distance (plane-distance f)))	;coplanar
	(send self :coplanar-intersections f)
	nil))
)


;;;
;;;	methods for FACE
;;;

;;
;; geometric properties
;;
(defmethod face
 (:insidep (point &optional (tol 0.001))
    ; inside -- inside of the profile and outside of holes
    ; border -- point is on an edge
    (let ((result (send-super :insidep point tol)))
	(if (not (eq result ':inside))
	    result
	    (progn
	       (dolist (h holes)
	          (setq result (send h :insidep point tol))
	          (if (eq result ':inside)
		      (return-from :insidep ':outside)
		      (if (eq result ':border)
		          (return-from :insidep ':border)
		          )))
	       ':inside))))
 (:distance (point)
    (let (foot (sign (signum (send self :plane-distance point))))
       (setq foot (send self :foot point))
       (if (= sign 0.0)	;; on the same plane
	   (if (memq (send self :insidep foot) '(:inside :parallel))
	       0.0
	       (apply #'min (send-all (send self :all-edges) :distance point)))
         (* sign
            (if (memq (send self :insidep foot) '(:inside :parallel))
                (distance foot point)
	      (apply #'min (send-all (send self :all-edges)
				     :distance point))))) ))
 (:area ()
    (- (send-super :area) (apply #'+ (send-all holes :area))))
#|
 (:centroid (&optional (point nil))
    (let* ((profile-centroid (send-super :centroid point))
	   (holes-centroid (send-all holes :centroid point))
	   (centroid (apply #'scale profile-centroid))
	   (total-area (+ (car profile-centroid)
			  (apply #'+ (mapcar #'car holes-centroid)))))
      (dolist (hc holes-centroid)
	 (v+ centroid (apply #'scale hc) centroid))
      (list total-area (scale (/ 1.0 total-area) centroid))))
|#
 (:centroid (&optional (point nil))
    (let* ((profile-centroid (send-super :centroid nil))
	   (holes-centroid (send-all holes :centroid nil))
	   (centroid (apply #'scale profile-centroid))
	   (total-area (- (car profile-centroid)
			  (apply #'+ (mapcar #'car holes-centroid))))
	   )
      (dolist (hc holes-centroid)
	 (v- centroid (apply #'scale hc) centroid))
      (if point
	  (list (/ (* total-area (send self :plane-distance point)) -3.0)
		(midpoint 0.25 (scale (/ 1.0 total-area) centroid) point))
	  (list total-area (scale (/ 1.0 total-area) centroid)))) )
 (:on-vertex (p &optional (*epsilon* *contact-threshold*) &aux res)
    (apply #'nconc
	 (send-super :on-vertex p *epsilon*)
	 (send-all holes :on-vertex p *epsilon*)))
 (:on-edge (p &optional (tolerance *contact-threshold*))
    (apply #'nconc
	 (send-super :on-edge p tolerance)
	 (send-all holes :on-edge p tolerance)))
 (:invert ()
    (send-super :invert)
    (send-all holes :invert))
 (:holes () holes)
 (:enter-hole (h) (push h holes))
 (:transform-normal (c)
    (send-super :transform-normal c)
    (send-all holes :transform-normal c))
 (:reset-normal ()
    (send-super :reset-normal)
    (send-all holes :reset-normal)) )

(defmethod face
 (:face () self)
 (:all-edges ()
    (append edges (apply #'append (send-all holes :edges))))
 (:all-vertices ()
    (append vertices (apply #'append (send-all holes :vertices))))
 (:body (&optional bod)
    (if bod (setq mbody bod) mbody))
 (:primitive-face (&optional fac)
    (if fac (setq primitive-face fac))
    primitive-face)
 (:primitive-body () (send primitive-face :body))
 (:id (&optional newid)
    (if newid (setq id newid) id))
 (:face-id () (cons (car (send (send primitive-face :body) :csg)) id))
 (:primitive-body-type () (send (send primitive-face :body) :body-type))
 (:body-type () (send mbody :body-type))
 (:prin1 (strm)
    (send-super-lexpr :prin1 strm
		(if mbody (car (send mbody :body-type)) "")
		id))
 (:copied-primitive-face-p () (get mbody :copied-primitive))
 (:primitive-body () (send primitive-face :body))
 (:init (&key ((:normal nor)) ((:distance d))
	      ((:edges p)) ((:vertices ver)) ((:holes h))
	      ((:id newid) nil)  ((:body bod) nil)
	      ((:primitive-face pface) self))
    (setq holes h)
    (send-all h :face self)
    (if newid (setq id newid))
    (setq primitive-face pface)
    (if bod (setq mbody bod))
    (send-super :init :normal nor :distance d :edges p :vertices ver)
    self))

;; surface attributes
(defmethod face
 (:reflectance (&optional new &aux ref)
    (if new
	(setf (get self :reflectance) new)
	(if (setq ref (get self :reflectance)) ref (send mbody :reflectance))))
 (:diffusion (&optional new &aux dif)
    (if new
	(setf (get self :diffusion) new)
	(if (setq dif (get self :diffusion)) dif (send mbody :diffusion))))
 (:color (&optional newcolor) 
     (if newcolor
	 (setf (get self :color) newcolor)
	 (if (setq newcolor (get self :color))
	     newcolor
	     (if mbody (send mbody :color))) ))
)


(defmethod face		;Hirukawa
 (:contact-edge (e1)   ; edges_of_face vs edge contact check
    (declare (type edge e1))
    (let (foot)
      (if (< (abs (v. (self . normal) (v- (e1 . nvert) (e1 . pvert))))
	     *contact-threshold*)
	  (return-from :contact-edge nil))
      (dolist (e2 (send self :all-edges))
	(setq foot (send e1 :contact e2))
	(if foot (return-from :contact-edge foot)))))
 (:contact-point (p &optional (tolerance *contact-threshold*))  ; face vs vertex contact check
    ; inside -- inside of the profile and outside of holes
    ; border -- p is on an edge
    (let ((result (send-super :contact-point p tolerance)))
	(if (not (eq result ':inside))
	    result
	    (progn
	       (dolist (h holes)
	          (setq result (send h :contact-point p tolerance))
	          (if (eq result ':inside)
		      (return-from :contact-point ':outside)
		      (if (eq result ':border)
		          (return-from :contact-point ':border)
		          )))
	       ':inside)))))


;;
;; HOLE
;;


(defmethod hole 
 (:face (&optional fac)
     (if (facep fac) (setq  myface fac))
     myface)
 (:hollowed-faces ()
    (let (r)
       (dolist (e edges)
	  (let ((pf (edge-pface e)) (nf (edge-nface e)))
	     (unless (eq pf myface) (setq r (adjoin pf r)))
	     (unless (eq nf myface) (setq r (adjoin nf r)))))
       r))
 (:init (&key ((:normal nor)) ((:distance dis))
	      ((:edges edg))  ((:vertices ver)) ((:face fac)))
    (setq myface fac)
    (send-super :init :normal nor :distance dis :edges edg :vertices ver)
    self))


(defparameter *edge-class* edge)
(defparameter *face-class* face)
(defparameter *hole-class* hole)
(defparameter *body-class* body)

(defun make-plane (&key (normal (float-vector 0 0 1))
			(point (float-vector 0 0 0))
		        (distance nil))
  (when (consp point) 
      (setq normal  (face-normal-vector point point))
      (setq point (car point)))
  (setq normal (normalize-vector normal))
  (if distance (setq point (scale (- distance) normal)))
  (instance plane :init  normal point))

(defconstant *xy-plane* (make-plane))
(defconstant *yz-plane* (make-plane :normal #f(1 0 0)))
(defconstant *zx-plane* (make-plane :normal #f(0 1 0)))

(defun make-polygon (&rest points)
   (instance polygon :init :vertices points))

(provide :geopack "@(#)$Id$")
