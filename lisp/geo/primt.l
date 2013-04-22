;;; llib/primt.l
;;; create primitive bodies
;;;	Copyright (1988) Toshihiro MATSUI, Electrotechnical Laboratory
;;;
;;;
;;;	1988-Feb  2D-convex-hull using quick-hull algorithm
;;;	1988-Sep  Generation of general prism and solid-of-revolution
;;;	1988-Sep  Icosahedron and Gdome
;;;	1989	  Dodecahedron
;;;	1991-Sep  find-initial-hull is changed to meet with mips floating point
;;;		  arithmethic op.
;;;
;;	convex-hull-3d	body
;;	make-cube	a b c
;;	make-cylinder	radius height
;;	make-icosahedron	radius
;;	make-prism	bottom sweep
;;	make-gdome (hedron)
;;	make-torus (points)
;;	make-solid-of-revolution (points)
;;	make-cone (top bottoms)
;;

(in-package "GEOMETRY")

(export '(find-extream leftmost-point rightmost-point left-points right-points
	quickhull-left quickhull-right quickhull
	find-coplanar-vertices colinear-p find-colinear-points
	remove-colinears-from-circuit coplanar-p
	*-inf* *inf* *nan*
	gift-wrapping make-face-from-vertices make-face-from-coplanar-vertices
	convex-hull-3d
	make-prism make-cone make-solid-of-revolution
	make-torus make-cylinder make-cube
	make-icosahedron make-dodecahedron
	make-gdome make-body-from-vertices ))

(export '(coordinates-axes))

(eval-when (compile)
  (defvar *body-class*)
  (defvar *edge-class*)
  (defvar *face-class*)
  (defvar *coplanar-threshold*))

(defun find-extream (vertices key test)
   (let* ((ext (pop vertices)) (p (funcall key ext)))
      (dolist (v vertices)
	 (when (funcall test (funcall key v) p)
	    (setq ext v
		  p   (funcall key ext))))
       ext))

(defun leftmost-point (vertices p1 p2 normal)
  ;; searches a point left farthest from the line p1 to p2
  (find-extream vertices #'(lambda (x) (triangle x p1 p2 normal)) #'>))

(defun rightmost-point (vertices p1 p2 normal)
  ;; searches a point right farthest from the line p1 to p2
  (find-extream vertices #'(lambda (x) (triangle x p1 p2 normal)) #'<))

(defun left-points (points p1 p2 normal)   ;collect points lying in the left
   (mapcan #'(lambda (p) (if (< (triangle p1 p p2 normal) 0.0) (list p) nil))
	   points))

(defun right-points (points p1 p2 normal)  ;collects points lying in the right
   (mapcan #'(lambda (p) (if (> (triangle p1 p p2 normal) 0.0) (list p) nil))
	   points))

(defun quickhull-left (s l r normal)
   (cond ((null s) (return-from quickhull-left (list l r))))
   (let* ((h (leftmost-point s l r normal))
	  (s1 (left-points s l h normal))
	  (s2 (left-points s h r normal)) 
	  (ss))
      (setq ss (nconc  (quickhull-left s1 l h normal)
	    	       (delete h (quickhull-left s2 h r normal) :count 1)))
      ss))

(defun quickhull-right (s l r normal)
   (cond ((null s) (return-from quickhull-right (list l r))))
   (let* ((h (rightmost-point s l r normal))
	  (s1 (right-points s l h normal))
	  (s2 (right-points s h r normal))
	  (ss))
      (setq ss  (nconc  (delete h (quickhull-right s2 h r normal) :count 1)
			(quickhull-right s1 l h normal)))
      ss))

(defun quickhull (s &optional (normal #f(0 0 1)))
  (declare (type float-vector normal))
  (let (s0 s1 lefthull righthull (extream-index 0))
     (if (> (abs (aref normal 0)) (abs (aref normal 1)))
	 (setq extream-index 1))
     (setq s0 (find-extream s #'(lambda (p) (aref p extream-index)) #'<=)
	   s1 (find-extream s #'(lambda (p) (aref p extream-index)) #'>=))
     (setq lefthull (quickhull-left (left-points s s0 s1 normal) s0 s1 normal))
     (setq righthull (quickhull-right (right-points s s0 s1 normal) s0 s1 normal))
     (setq righthull (delete s0 righthull :count 1))
     (setq righthull (delete s1 righthull :count 1))
     (nreverse (nconc lefthull righthull))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 3-D convexhull
; vertices are represented by a list of a 3D float-vector and
; list of edges connected to the vertex
;	( #f(x y z)  edge1 edge2 ... )
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(setq *coplanar-threshold* 0.001)

(defun find-coplanar-vertices (p1 p2 p3 s)
   ; p1, p2 and p3 are 3D-points constructing a triangle
   ; s is a list of vertices
   (let* ((normal (triangle-normal p1 p2 p3))
	 (distance (- (v. normal p1))))
      (mapcan
	  #'(lambda (apoint)
	       (if (< (abs (+ (v. (car apoint) normal) distance))
		      *coplanar-threshold*)
	           (list apoint)))
	  s)))

(defun colinear-p (p1 p2 p3 &optional (*epsilon* *coplanar-threshold*) )
   (let* ((v12 (v- p2 p1)) (v13 (v- p3 p1))
	  (e (/ (norm (v* v12 v13)) (max (norm v12) (norm v13)))))
      (if (eps= e 0.0)
	  (/ (v. v12 v13) (v. v13 v13))
	  nil)))

(defun find-colinear-points (points)
   (let* (p1 p2 p3 points2 p result)
      (while points
	 (setq p1 (pop points)   points2 points)
	 (while points2
	     (setq p2 (pop points2))
		; is there any point which lies on the line defined by p1,p2?
	     (dolist (p3 points2)
		(when (setq p (colinear-p p1 p2 p3))
		    (push (cond ((< p 0.0) p1)
				((< p 1.0) p2)
				(t p3))
			  result)
			))))
	result))

(defun remove-colinears-from-circuit (circuit)
    (cond ((<= (length circuit) 3) circuit)
	  ((colinear-p (car circuit) (cadr circuit) (caddr circuit))
	   (cons (car circuit)
		 (cdr (remove-colinears-from-circuit (cdr circuit)))))
	  (t (cons (car circuit)
		   (remove-colinears-from-circuit (cdr circuit))))))

(defun coplanar-p (p1 p2 p3 p4 &optional (*epsilon* *coplanar-threshold*))
   (let* ((v1 (v- p2 p1)) (v2 (v- p3 p2)) (v3 (v- p4 p1))
	  (n (normalize-vector (v* v1 v2))))
      (eps= (v. n v3) 0.0)))

#+:ieee-floating-point
(progn (defparameter *-inf* (/ -1.0 0.0))
       (defparameter *inf* (/ 1.0 0.0)
	(defparameter *nan* (/ 0.0 0.0))))
#-:ieee-floating-point
(progn (defparameter *-inf* -1.0e38)
       (defparameter *inf* 1.0e38))

(defun gift-wrapping (f p n a s)
   ;; f is the previous face
   ;; p is one endpoint on the edge
   ;; n is plane normal
   ;; a is normal both to n and the edge
   ;; s is a list of points to be searched
   (let* ((cot) (verts (send f :vertices)) (maxv) (maxcot *-inf*)
	  (v (float-vector 0 0 0)) va vn)
      (declare (type float cot maxcot va vn))
      (dolist (vk s)	;for each element of vertices
	 (when (null (memq (car vk) verts))
	    (v- (car vk) p v)
	    (setq va (v. v a) vn (v. v n))
	    (setq cot  (- (/ va vn)))
;	  (format t ";; cot=~s v=~s vk=~s d=~s/~s~%" cot v (car vk) va vn)
#+:ieee-floating-point
	    (when (eq cot *nan*)
	        (format t ";; cot=~s v=~s vk=~s d=~s/~s~%" cot v (car vk) va vn)
		(return-from gift-wrapping :nan))
	    (when (and ;(not (eql vn 0.0))
		(not (< cot *-inf*)) (>= cot maxcot))
		(setq maxv vk maxcot cot))))
      (setq *maxcot* maxcot)
      maxv))

(defun make-face-from-vertices (vertices)
"ARG = (vertices)
vertices= list of (#f(x y z) edge1 edge2 ...)"
   (let* ((newface (instantiate *face-class*))
	  (edges)
	  (e) (e1) (e2)
	  (v1 (car (last  vertices))))
;      (format t "make-face: vertices=~s~%" vertices)
      (dolist (v2 vertices)
	 (setq e1 (cdr v1) e2 (cdr v2))
	 ; is there any preexistent edge connecting v1 and v2?
	 (setq e (car (intersection e1 e2)))
	 (cond ((null e)
	    	(setq e (instantiate *edge-class*))
	    	(send e :init :pvertex (car v1)
			      :nvertex (car v2)
			      :pface   newface  )
	        (nconc v1 (list e))
	        (nconc v2 (list e)) )
	       (e
		(send e :set-face (car v1) (car v2) newface)))
	 (setq edges (cons e edges))
	 (setq v1 v2))
      (nreverse edges)
      (send newface :init :edges edges)
      newface))

(defun make-face-from-coplanar-vertices (p1 p2 p3 s)
    (let* ((n (triangle-normal (car p1) (car p2) (car p3)))
	   (coplanars (find-coplanar-vertices (car p1) (car p2) (car p3) s))
	   (points)
	   (hull-points)
	   (hull-vertices)
	   (inner-points))
      (cond
	 ((> (length coplanars) 3)
;	  (setq colinears (print (find-colinear-points (mapcar #'car coplanars))))
;	  (if colinears (push colinears *colinears*))
	  (setq points (mapcar #'car coplanars))
	  (setq hull-points (quickhull points n))
	  (setq hull-points (append hull-points
				    (list (car hull-points) (cadr hull-points))))
	  (setq hull-points (remove-colinears-from-circuit hull-points))
	  (setq hull-points (cddr hull-points))
	  (dolist (p coplanars)
	     (if (null(memq (car p) hull-points))
		 (setq inner-points (cons p inner-points))))
	  (when inner-points
		(dolist (ip inner-points)
		   (format t ";; inner points ~s found~%" ip)
		   (push (car ip) *bad-vertices*)
		   (when (null (cdr ip))	; check for colinearity is needed
                      (setq *vertices* (delete ip *vertices* :count 1))	)))
	  ; find corresponding vertices
	  (setq hull-vertices
		(mapcan #'(lambda (p) (list (assq p coplanars))) hull-points)))
	 (t (setq hull-vertices (list p1 p2 p3))))
;	 (format t ";; hull-verts=~s~%" (mapcar #'car hull-vertices))
      (make-face-from-vertices hull-vertices)
	))

(defun tangent-foot (p1 p2 p3)
  ;;;  calculate foot (p3) of a perpendicular line (p1, p2)
  (let* ((p12 (v- p1 p2))
         (p32 (v- p3 p2))
         (2np12 (norm2 p12))
         (k (/ (v. p12 p32) 2np12))
         )
    (v+ p2 (scale k p12))))

(defun calc-p2-of-lowest-hull (p1 s)
  "ARGS=(p1 s)"
  (let (result (minangle pi/2) angle fvec vec)
    (dolist
     (v s)
     (setq vec (v- (car p1) (car v)))
     (when (and (not (equal (car v) (car p1)))
                (> (norm vec) 0.1)
                (not (and (= 0.0 (elt vec 0))
                          (= 0.0 (elt vec 1))))
                )
           (setq fvec (copy-object vec))
           (setf (elt fvec 2) 0)
           (if (= 0.0 (elt vec 2)) (setq angle 0.0)
             (setq angle
                   (vector-angle (normalize-vector vec)
                                 (normalize-vector fvec)
                                 (normalize-vector (v* vec fvec))
                                 )))
           (when (< angle minangle)
                 (setq result v minangle angle)))
     )
    result))

(defun calc-p3-of-lowest-hull (p1 p2 s)
  "ARGS=(p1 p2 s)"
  (let ((foot) result (minangle pi) angle vec n)
    (dolist
     (v s)
     (when (and (not (equal (car v) (car p1)))
                (not (equal (car v) (car p2))))
           (setq foot (tangent-foot (car p1) (car p2) (car v)))
           (setq vec (v- foot (car v)))
           (when (> (norm vec) 0.2)
                 (setq n (triangle-normal (car p1) (car p2) (car v)))
                 (if (< (elt n 2) 0) (setq n (scale -1 n)))
                 (if (eps= (norm (v- #f(0 0 1) n)) 0.0)
                     (setq angle 0.0)
                   (setq angle
                         (vector-angle #f(0 0 1)
                                       (normalize-vector n)
                                       (normalize-vector (v* #f(0 0 1) n))
                                       )))
                 (if (< angle minangle)
                     (setq result v minangle angle))))
     )
    result))


(defun find-initial-hull (s)
  ;;;  "ARGS=s, s=((vertex1)(vertex2)....(vertexn))
  ;;; retunrs hull that contians most smallest z-coordintes as one of its vertex
  (let* ((p1 (find-extream s #'(lambda (p) (aref (car p) 2)) #'<=))
         (p2) (p3) v)
    (setq p2 (calc-p2-of-lowest-hull p1 s))
    (setq p3 (calc-p3-of-lowest-hull  p1 p2 s))
    (if (null p3) (return-from find-initial-hull nil) )
    (when (< (triangle (car p1) (car p2) (car p3)) 0.0)
          (setq v p2 p2 p3 p3 v))
    (while (< (length (remove-colinears-from-circuit
                       (mapcar #'car (list p2 p1 p3 p2 p1)))) 5)
      (setq s (remove p3 s))
      (setq p3 (calc-p3-of-lowest-hull  p1 p2 s))
      (when (< (triangle (car p1) (car p2) (car p3)) 0.0)
            (setq v p2 p2 p3 p3 v))
      )
    (make-face-from-coplanar-vertices p1 p3 p2 s)
    ))
;;
;; convexhull using gift-wrapping algorithm
;;

(defun enclosed-vertexp (v)  ;; v=(#f() #<edge..> #<edge..>...)
  (let ((result t))
    (dolist (e (cdr v))
      (setq result (and (e . pface)(e . nface) result))
      )
    (and (cdr v) result)))

(defun convex-hull-3d (vertices)
"ARGS = (vertices)
Create a body of convex-hull from a list of vertices"
   (let ((aface) (faces) (edges)
	 (n) (a) (e)
	 (p1) (p2) (p3) (temp)
	 (newedges)
	 (newface)
	 (newbody)
	 (faceq)
	 (edgeq)
	 (searched-edgeq)
	 (searched-v)
	 )
      (setq *points* vertices
	    *vertices* (mapcar #'list vertices)
	    *colinears* nil
	    *bad-vertices* nil
	    aface (find-initial-hull *vertices*)
            *faces* (list aface)
      	    edgeq (copy-seq (send aface :edges))
	    faceq (list aface))
      (dolist (p *points*)
	 (when (> (send aface :distance P) 0.0001)
	     (format *error-output* "bad point ~A deleted, distance=~A~%"
			p (send aface :distance P))
	     (setq *points* (remove p *points* :count 1)) ))
       (while faceq
	 (setq aface (pop faceq))
	 (dolist (e (send aface :edges))
	    (cond ((memq e edgeq)
		   (setq p1 (assq (send e :pvertex aface) *vertices*)
			 p2 (assq (send e :nvertex aface) *vertices*))
		   (when (or (null p1) (null p2))
		      (setq *e* e *f* aface)
		      (error "bad edge"))
		   (setq p3 (gift-wrapping
					   aface
					   (car p1)
					   (send aface :normal)
					   (send e :binormal aface)
					   *vertices*))
;		   (format t ";; p1=~s~%p2=~s~%p3=~s~%" p1 p2 p3)
		   (if (< (v. (v* (send aface :normal)
				   (triangle-normal (car p1) (car p2) (car p3)))
			       (v- (car p2) (car p1)))
			   0.0)
		       (setq temp p2 p2 p3 p3 temp))
		   (setq searched-v
			 (send (if (e . pface)
				   (e . pface) (e . nface)) :vertices))
		   (setq searched-v
			 (mapcar #'list (set-difference searched-v
							(send e :vertices))))
		   (setq newface (make-face-from-coplanar-vertices
					 p1 p2 p3 (set-difference *vertices* searched-v :key #'car)))
		   (setq newedges (send newface :edges))
		   (dolist (ne newedges)
                     (cond ((memq ne edgeq)
                            (setq edgeq (delete ne edgeq))
                            (setq searched-edgeq (cons ne searched-edgeq))
                            (let ((ver))
                              (dolist (v (send ne :vertices))
                                (setq ver (find v *vertices* :key #'car))
                                (if (enclosed-vertexp ver)
                                    (setq *vertices* (delete ver *vertices* :count 1)))
                                ))
                            )
                           ((memq ne searched-edgeq)
                            (format *error-output* "~%re-searched edge:~A~%" ne)
                            (let ((*coplanar-threshold*
                                   (/ *coplanar-threshold* 2)))
                              (format *error-output*
                                      "thd:~A->~A~%" (* 2 *coplanar-threshold*)
                                      *coplanar-threshold*)
                              (if (< *coplanar-threshold* 0.00001)
                                  (error "edgeq error!!")
                                (return-from convex-hull-3d
                                  (convex-hull-3d vertices)))))
                           (t
                            (setq edgeq (append edgeq (list ne))))))
		   (setq faceq (cons newface faceq))
		   (nconc *faces* (list newface))
		   (if *debug* (print (length *faces* )))
		 ))
	))
   (setq *edges* (remove-duplicates (apply #'append (send-all *faces* :edges))))
   (setq *vertices* (remove-duplicates (apply #'append (send-all *faces* :vertices))))
   (setq *body* (instance *body-class* :init
			:faces *faces*
			:edges *edges*
			:vertices *vertices*
			:primitive (list :convex-hull *vertices* )))
   ))


;;;
;;; PRISM, CONE, CYLINDER, CUBE, TORUS, SOLID-OF-REVOLUTION
;;;

(defun rotate-vertices (vertex count angle axis)
   (let* ((vertices (list vertex)) (th (/ angle count)) (theta th))
      (dotimes (c (1- count))
	 (push (list (rotate-vector (car vertex) theta axis)) vertices)
	 (setq theta (+ theta th)))
      (nreverse vertices)))

(defun make-side-faces (tops bottoms &optional index)
   (let ((top-first (first tops)) (bottom-first (first bottoms))
	 faces v1 v2 v3 v4 newface (index2 0))
      (while bottoms
	 (setq  v1 (pop bottoms)
		v2 (if bottoms (car bottoms) bottom-first)
		v4 (pop tops)
		v3 (if tops (car tops) top-first))
	 (setq newface (make-face-from-vertices (list v1 v2 v3 v4)) )
	 (send newface :id
			(if index
			    (list :side index index2)
			    (list :side index2)) )
	 (incf index2)
	 (push newface faces))
      faces))

(defun make-prism (bottom-points sweep-vector
		   &rest args
	   	   &key (primitive (list ':prism bottom-points sweep-vector))
			&allow-other-keys)
"ARGS = (bottom-points sweep-vector 
	&key color name primitive)"
   (if (numberp sweep-vector) (setq sweep-vector (float-vector 0 0 sweep-vector)))
   (let ((bottom-verts (mapcar #'list bottom-points))
	 (top-verts (mapcar #'(lambda (v) (list (v+ v sweep-vector)))
			    bottom-points))
	 faces)
      (push (make-face-from-vertices (nreverse top-verts)) faces)
      (send (first faces) :id (list :top))
      (nconc faces (make-side-faces top-verts (reverse bottom-verts)))
      (push (make-face-from-vertices  bottom-verts) faces)
      (send (first faces) :id (list :bottom))
      (send-lexpr (instantiate *body-class*) :init
			:faces faces
			:approximated t
			:primitive primitive
			args) ) )

(defun make-conic-side-faces (top-vertex bottom-vertices &optional index)
   (let (faces (first (first bottom-vertices)) (index2 0))
      (while bottom-vertices
	 (push (make-face-from-vertices
		     (list (pop bottom-vertices)
			   top-vertex
			   (if bottom-vertices (car bottom-vertices) first)))
		faces)
	  (send (car faces) :id
				(if index (list :side index index2)
					  (list :side index2)))
	  (incf index2))
      faces))

(defun make-cone (top bottoms &rest args
			      &key (segments 16)
				&allow-other-keys
			      &aux bottom-face)
"make-cone (top bottoms &key segments color name)"
   ;bottoms is a list of vectors which lie on xy plane, counter-clock-wise
   (if (numberp bottoms)
       (setq bottoms (nreverse (rotate-vertices
				      (list (float-vector bottoms 0 0))
				      segments 2pi :z)))
       (setq bottoms (mapcar #'list bottoms)))
   (setq bottom-face (make-face-from-vertices bottoms))
   (send bottom-face :id (list :bottom))
   (send-lexpr (instantiate *body-class*) :init 
	     :faces (cons bottom-face
			  (make-conic-side-faces (list top) bottoms))
	     :approximated t
	     :primitive (list ':cone :top (mapcar #'car bottoms))
	     args)) 
      
(defmacro on-z-axis-p (v) `(< (abs (aref ,v 0)) 0.001))

(defun make-solid-of-revolution (points &rest args
					&key (segments 16)
					&allow-other-keys)
"ARGS = (points &key segments color name)"
   (let* ((vertices (mapcar #'list points))
	  (vlist1 (pop vertices)) vlist2 faces (index 0))
      (unless (on-z-axis-p (car vlist1))
	  (setq vlist1 (rotate-vertices vlist1 segments 2pi :z))
	  (setq faces (make-face-from-vertices vlist1))
	  (send faces :id (list :bottom)))
      (while vertices
	 (setq vlist2 (pop vertices))
	 (unless (on-z-axis-p (car vlist2))
	     (setq vlist2 (rotate-vertices vlist2 segments 2pi :z)))
	 (cond ((null (cdr vlist2))
		(if (null (cdr vlist1)) (error "illegal contour"))
		(push (make-conic-side-faces vlist2 vlist1 index)
		      faces))
	       ((null (cdr vlist1))
		(push (make-conic-side-faces vlist1 (reverse vlist2) index)
		      faces))
	       (t (push (make-side-faces vlist1 vlist2 index) faces)))
	 (incf index)
	 (setq vlist1 vlist2))
      (if (and (cdr vlist2) (listp  (cadr vlist2)))
	  (push (make-face-from-vertices (reverse vlist2)) faces))
      (send-lexpr (instantiate *body-class*) :init
			   :faces (flatten faces)
			   :approximated t
			   :primitive (list ':revolution points segments)
			   args)))

(defun make-torus (points &rest args &key (segments 16) &allow-other-keys)
"ARGS = points &key segments color name"
   (let* (faces 
	  (vertices (mapcar #'list points))
	  (first-vertices (rotate-vertices (pop vertices) segments 2pi :z))
	  vlist1 vlist2 (index 0))
      (setq vlist1 first-vertices)
      (while vertices
	 (setq vlist2 (rotate-vertices (pop vertices) segments 2pi :z))
	 (setq faces (nconc faces (make-side-faces vlist1 vlist2 index) ))
	 (incf index)
	 (setq vlist1 vlist2))
      (nconc faces (make-side-faces vlist2 first-vertices index))
      (send-lexpr (instantiate *body-class*) :init
		 :faces faces
		 :primitive (list ':torus points segments)
		  args)))

(defun make-cylinder (radius height &rest args
				&key (segments 12) (circumscribed nil)
					
				&allow-other-keys)
"MAKE-CYLINDER radius height (:segments 12) (:circumscribed nil) :color :name"
   (setq radius (float radius) height (float height))
   (let* ((theta (/ 2pi segments))
	  (radius (if circumscribed (/ radius (cos (/ theta 2.0))) radius))
	  (p (float-vector radius 0 0))
	  (base (list p))
	  cyl)
      (dotimes (i (1- segments))
	 (push (rotate-vector (car base) theta :z) base))
      (setq cyl
	    (apply #'make-prism base height
		  :primitive  (list ':cylinder radius height segments)
		  args))
      (setf (get cyl :center-axis) (make-line (float-vector 0 0 0)
					     (float-vector 0 0 height)))
      cyl))

(defun make-cube (xsize ysize zsize &rest args)
"MAKE-CUBE x y z &key color name"
   (setq xsize (float xsize) ysize (float ysize) zsize (float zsize))
   (let ((xsize/2 %(xsize / 2.0))
	 (ysize/2 %(ysize / 2.0))
	 (zsize/2 %(- zsize / 2.0))
	 v1 v2 v3 v4 b)
      (setq v1 (float-vector xsize/2 ysize/2 zsize/2)
	    v2 (float-vector xsize/2 (- ysize/2)  zsize/2)
	    v3 (float-vector (- xsize/2) (- ysize/2) zsize/2)
	    v4 (float-vector (- xsize/2) ysize/2 zsize/2))
      (setq b (apply #'make-prism (list v1 v2 v3 v4) zsize
			:primitive (list ':cube xsize ysize zsize)
			args))
      (dolist (f (send b :get-face nil :side))
	 (send f :id (append (send f :id) (list  (nth (nth 1 (send f :id))
						      '(:-x :-y :x :y))))))
      b))

;;;
;;; Geodetic Dome, Icosahedron and Dodecahedron
;;;
;;;	First, an icosahedron should be made by make-icosahedron which
;;;	generates twenty triangles by extending convex-hull.
;;;	Then, make-gdome can be called recursively.

(defun icosahedron-points (&optional (radius 1.0))
   (let* ((tt (/ (+ 1.0 (sqrt 5.0)) 2.0))
	  (a (* radius (/ (sqrt tt) (sqrt (sqrt 5.0)))))
	  (b (* radius (/ 1.0 (* (sqrt tt) (sqrt (sqrt 5.0)))))))
     (list
	 (float-vector 0   a   b)
	 (float-vector 0 (- a) b)
	 (float-vector 0 a (- b))
	 (float-vector 0 (- a)(- b))
	 (float-vector b 0 a)    
	 (float-vector b 0 (- a))
	 (float-vector (- b) 0 a)
	 (float-vector (- b) 0 (- a))
	 (float-vector a b 0)    
	 (float-vector a (- b) 0)
	 (float-vector (- a) b 0)
	 (float-vector (- a)(- b) 0)))	)

(defun make-icosahedron (&optional (radius 1.0) &aux ico)
"MAKE-ICOSAHEDRON &optional (radius 1.0)"
   (setq ico (convex-hull-3d (icosahedron-points radius)) )
   (send ico :csg (list (list :icosahedron radius)))
   ico)

(defun subdivide-facet (normal oldverts newverts)
   (let (f facets vlist)	;divide a facet into four sub-facets
      (setq vlist (list (car oldverts) (car newverts) (caddr newverts)))
      (if (< (v. (apply #'triangle-normal (mapcar #'car vlist)) normal) 0.0)
	  (setq vlist (list (car oldverts) (caddr newverts) (cadr newverts))))
      (push (make-face-from-vertices vlist) facets)
      (setq vlist (list (cadr oldverts) (cadr newverts) (car newverts)))
      (if (< (v. (apply #'triangle-normal (mapcar #'car vlist)) normal) 0.0)
	  (setq vlist (list (cadr oldverts) (car newverts) (cadr newverts))))
      (push (make-face-from-vertices vlist) facets)
      (setq vlist (list (caddr oldverts) (caddr newverts) (cadr newverts)))
      (if (< (v. (apply #'triangle-normal (mapcar #'car vlist)) normal) 0.0)
	  (setq vlist (list (caddr oldverts) (cadr newverts) (caddr newverts))))
      (push (make-face-from-vertices vlist) facets)
      (setq vlist (list (car newverts) (cadr newverts) (caddr newverts)))
      (if (< (v. (apply #'triangle-normal (mapcar #'car vlist)) normal) 0.0)
	  (setq vlist (list (car newverts) (caddr newverts) (cadr newverts))))
      (push (make-face-from-vertices vlist) facets)
      facets))

(defun make-dodecahedron (&optional (radius 1.0))
   (let ((icosahedron (make-icosahedron ))
	 p (points) dodeca)
      (dolist (f (body-faces icosahedron))
	 (setq p (vector-mean (cdr (face-vertices f))))
	 (scale (/ radius (norm p)) p p)
	 (push p  points))
      (setq *dodeca-points* points)
      (setq dodeca (convex-hull-3d points))
      (send dodeca :csg (list (list :dodecahedron radius)))
      dodeca))

(defun make-gdome (hedron)
"MAKE-GDOME hedron
hedron is an icosahedron or a gdome of lower level"
   (let ((oldverts (make-hash-table :test #'equal))
	 (newverts (make-hash-table :test #'equal))
	 (vlist1) (vlist2) v e faces
	 (radius (norm (car (hedron . vertices)))) gdome)
      (dolist (v (hedron . vertices))
	 (setf (gethash v oldverts) (list (copy-object v))))
      (dolist (e (hedron . edges))
	 (setq v (scale radius (normalize-vector (v+ (e . pvert) (e . nvert)))))
	 (setf (gethash e newverts) (cons e (list v))))
      (dolist (fac (hedron . faces))
	 (setq v (fac . vertices) e (fac . edges))
	 (setq vlist1  (list (gethash (car v) oldverts)
		     	     (gethash (cadr v) oldverts)
			     (gethash (caddr v) oldverts)))
	 (setq vlist2  (list (cdr (gethash (car e) newverts))
		     	     (cdr (gethash (cadr e) newverts))
			     (cdr (gethash (caddr e) newverts))))
	 (push (subdivide-facet (fac . normal) vlist1 vlist2) faces))
      (setq gdome (instance *body-class* :init :faces (flatten faces)))
      (send gdome :csg (list (list :gdome hedron)))
      gdome ) )

;;


(defun make-body-from-vertices (face-vertices &optional (klass *body-class*))
   ; face-vertices=(list #f(x1 y1 z1) #f(x2 y2 z2) ...) ...
   #|(setq a
	 (let ((v1 #f(0 0 0))
   	   (v2 #f(1 0 0))
	   (v3 #f(0 1 0))
	   (v4 #f(0 0 1)))
        (make-body-from-vertices (list (list v1 v2 v3)
				       (list v4 v2 v1)
				       (list v4 v3 v2)
				       (list v4 v1 v3)))))
   |#
   (let* ((vlist (mapcar #'list
                         (remove-duplicates
                                 (apply #'append face-vertices)
                                 :test #'equal)))
          faces bod)
     (dolist (fverts face-vertices)
        (let ((fvlist))
           (dolist (fv fverts)
              ;; (push (assoc fv vlist) fvlist)
		(push (assoc fv vlist :test #'equal) fvlist)		)
           (push (make-face-from-vertices (nreverse fvlist)) faces)) )
     (setq bod (instance *body-class* :init :faces (nreverse faces)))
     (send bod :csg (list (cons :body-from-vertices face-vertices)))
     bod) )




;;;
;;; coordinates-axes class
;;	x-y-z and an arrow at the tip of z
;;	coordiantes-axes is moveable via any of coordinates' methods
;;	and associateable. If assoced to the origin of a body,
;;	its coordinates axes can be displayed.
;;	Feb/1992

(defclass coordinates-axes :super cascaded-coords
	   :slots (size model-points points lines))

(defmethod coordinates-axes
  (:update ()
     (setq changed nil)
     (dotimes (i (length points))
	 (replace (nth i points) 
		  (send self :transform-vector (nth i model-points)))
      ))
  (:magnify (r)
      (dotimes (i (length model-points))
	 (scale r (nth i model-points) (nth i model-points)))
      (send self :update)
      self)
  (:drawners () lines)
  (:init (sz &rest args)
      (setq points nil lines nil size sz)
      (push (float-vector 0 0 0) points)
      (push (float-vector sz 0 0) points)
      (push (float-vector 0 sz 0) points)
      (push (float-vector 0 0 sz) points)
      (push (float-vector (/ sz 5.0) 0 (* sz 0.8)) points)
      (push (float-vector 0 (/ sz 5.0) (* sz 0.8)) points)
      (setq points (nreverse points))
      (setq model-points (copy-object points))
      (push (make-line (first points) (second points)) lines)
      (push (make-line (first points) (third points)) lines)
      (push (make-line (first points) (fourth points)) lines)
      (push (make-line (fourth points) (fifth points)) lines)
      (push (make-line (fourth points) (sixth points)) lines)
      (send-super-lexpr :init args)
      self))

(defun assoc-coordinates-axes (casc &optional (size 1) (where (coords)))
    (let ((ca  (instance coordinates-axes :init size)))
       (send casc :assoc ca  where)
       ca))

(provide :primt "@(#)$Id$")
