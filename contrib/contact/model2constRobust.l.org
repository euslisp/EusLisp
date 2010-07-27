;;
;;
;;     from Geometric Model to Constraints
;;
;;
;;                       Programed by Hirohisa HIRUKAWA
;;
;;                                      Intelligent Machine Behavior Section
;;                                      Electrotechnical Laboratory
;;                                      1-1-4 Umezono, Tsukuba 305, JAPAN
;;                                      E-mail: hirukawa@etl.go.jp
;;
;;
;;  Version 1.00   May  1, 1990.  file name= constraint.l
;;  Version 1.01   May 11, 1990.  file name= model2const.l
;;  Version 1.02   Jun  5, 1990.  Bug fix. face:contact-edge
;;                                         body:contact-edges
;;  Version 1.03   Jun  6, 1990.  Refine.  constrained-point:analyse-contact
;;  Version 1.04   Jun 14, 1990.  Bug fix. edge:neighborpoints
;;                                         plane:separation
;;                                         constrained-point:analyse-contact
;;                                         function:edge-vertex-contact
;;  Version 1.05   Jun 15, 1990.  Define.  *contact-threshold*
;;  Version 1.06   Jun 19, 1990.  Bug fix. closed-region:contactp
;;  Version 1.07   Jun 22, 1990.  Add.     constrained-point:slot condition
;;                                         c-body:slot constraint
;;                                Modify.  body:constraint
;;                                         constrained-point:analyse-contact
;;                                         function:contact-to-constraint
;;  Version 1.08   Jul. 4, 1990.  Add.     body:slot motion
;;                                         body:solve-constraint
;;                                         body:draw-motion
;;  Version 1.09   Sep. 1, 1990.  Add.     face:contactp
;;                                Bug fix. function:edge-edge-contact
;;                                         function:eq-or-cond
;;  Version 1.10   Sep.11, 1990.  Add.     c-body:contact
;;                                Modify.  c-body:constraint
;;                                         c-body:draw-constraint
;;  Version 1.11   Oct.11, 1990.  Add.     c-body:slot force
;;  Version 1.12   Jul.29, 1991.  Bug fix. *contact-threshold*
;;                                Add.     *vertex-neighborhood-threshold*
;;                                Add.     function:eqvector
;;  Version 1.20   Aug.25, 1994.  Bug fix. constrained-point:dividen
;;                                Bug fix. eq-or-cond
;;  Version 1.21   Aug.26, 1994.  Bug fix. vertex-vertex-contact
;;                                Bug fix. constrained-point:analyse-contact
;;  Version 2.00   Apr.10, 1996   Filename model2const-robust.l
;;                                         A robust version of model2const.l
;;                                         *contact-threshold*
;;                                         *penetration-threshold*


;(require 'inequalities "inequalities.l")
(eval-when (load eval compile) (in-package "GEOMETRY"))

(require :geoclasses "geoclasses.l")
(provide :constraint)

(format t "model2constraint V1.21 Aug.26.1994.~%")

; (export '(constrained-point))

(export '(constrained-point-position
	  constrained-point-hisposition
	  constrained-point-hisface
	  constrained-point-myneighborhood
	  constrained-point-condition
	  constraint-relation-constrained-body
	  constraint-relation-constraining-body
	  constraint-relation-constraints
	  contact-to-constraint
	  face-contact edge-edge-contact
	  edge-vertex-contact vertex-vertex-contact))

(export '(*penetration-threshold*))

(setq *contact-threshold* 5.0)
(defvar *penetration-threshold* 5.0)
;(defvar *penetration-threshold* 10.0)

;;
;; Re-definitions of the classes in geoclasses.l
;;

;(defclass constrained-point
;  :super object
;  :slots (position hisposition hisface myneighborhood condition))

;;
;; Re-definitions of the methods in geopack.l for increasing the robustness.
;;

(defmethod edge
  (:contact (e) ;Hirukawa
    (let ((feet (send self :common-perpendicular e))
          (vertex-neighborhood1
	   (/ *contact-threshold* (norm (v- pvert nvert))))
	  (vertex-neighborhood2
	   (/ *contact-threshold* (norm (v- (edge-pvert e) (edge-nvert e))))))
      (if (not (eq feet ':parallel))
          (if (and (< (norm (v- (first feet) (second feet)))
		      *penetration-threshold*)
                   (< vertex-neighborhood1
                      (send self :parameter (first feet))
                      (- 1.0 vertex-neighborhood1))
                   (< (* -1.0 vertex-neighborhood2)
                      (send e :parameter (second feet))
                      (+ 1.0 vertex-neighborhood2)))
              feet)))))

(defmethod plane
 (:separation (hisposition mypoints hispoints) 	;Hirukawa
    (let (d (sign1 0) (sign2 0) nv)
      ; check if the distances between the separating plane and all points
      ; in each neighborhood have same signs. 
      ; check if mypoints have the same sign.
      (dolist (p mypoints)
	(setq d (send self :distance p))
	(if (> (abs d) *penetration-threshold*)
	    (if (minusp (* d sign1))
		(return-from :separation nil)
	      (if (> (abs d) (abs sign1)) (setq sign1 d)))))
      ; check if hispoints have the same sign.
      (dolist (p hispoints)
	(setq d (send self :distance p))
	(if (> (abs d) *penetration-threshold*)
	    (if (minusp (* d sign2)) 
		(return-from :separation nil)
	      (if (> (abs d) (abs sign2)) (setq sign2 d)))))
      ; check if both signs are different
      (when (minusp (* sign1 sign2))
	    (setq sign1 (/ sign1 (abs sign1)))
	    (setq nv (scale sign1 normal) d (* sign1 distance))
	    ; (setq d (send self :distance hisposition))
	    (setq d (+ (v. hisposition nv) d))
	    (if (and (< (* -1.0 *penetration-threshold*) d)
		     (< d *contact-threshold*))
		nv)))))

(defmethod polygon
 (:eps-insidep (point &optional (eps *epsilon*))
   (let (v1 v2 (theta 0.0) param th radials)
     (declare (type float-vector v1 v2)
              (type float th theta param))
     (cond (convexp
            (setq v2 (car vertices))
            (dolist (v1 (cdr vertices))
                (setq th  (triangle v2 v1 point normal))
                (cond ((eps-zero (/ th (distance v2 v1)) eps)
                        ;; be careful, th might be NaN
                       (setq param
                             (let ((a (v- v1 v2)) (b (v- point v2)))
                                (/ (v. a b) (v. a a))))
                        ;; if (v1==v2), param might be NaN and
                        ; eps-in-range is evaluated to be T
                       (if (eps-in-range  0.0 param 1.0 eps)
                           (return-from :eps-insidep ':border)) )
                      ((< (/ th (distance v2 v1)) (* -1.0 *contact-threshold*))
		       (return-from :eps-insidep ':outside)))
                   (setq v2 v1))
                ':inside)
            (t
             (if (send self :on-vertex point)
		 (return-from :eps-insidep ':border))
             (setq radials (mapcar #'(lambda (v) (direction-vector point v))
                                   vertices))
             (setq v2 (pop radials))
             (while radials
                (setq v1 (pop radials))
                (setq th (vector-angle v1 v2 normal))
                (if (eps= (abs th) pi eps)
                    (return-from :eps-insidep ':border))
                (setq theta (+ theta th))
                (setq v2 v1))
             ;; (if *debug* (format t "theta=~s~%" theta))
             (if (> (the float (abs theta))
		    (- pi (/ *contact-threshold* 100.0)))
		 ':inside ':outside) ))))
 (:contact-point (p &optional (tolerance *contact-threshold*))
   ;; polygon vs vertex contact check
   (let ((d (send self :plane-distance p)))
     (if (or (< d (* -1.0 *penetration-threshold*))
	     (< tolerance d))
	 ':outside
       (send self :eps-insidep (v- p (scale d normal)) (/ tolerance 10.0))))))

(defmethod face         ;Hirukawa
 (:contact-edge (e1)   ; edges_of_face vs edge contact check
    (declare (type edge e1))
    (let (feet)
      (if (< (abs (v. (self . normal) (v- (e1 . nvert) (e1 . pvert))))
             *parallel-threshold*)
          (return-from :contact-edge nil))
      (dolist (e2 (send self :all-edges))
        (setq feet (send e1 :contact e2))
        (if feet (return-from :contact-edge feet)))))
 (:eps-insidep (point &optional (eps *epsilon*))
    ; inside -- inside of the profile and outside of holes
    ; border -- point is on an edge
    (let ((result (send-super :eps-insidep point)))
        (if (not (eq result ':inside))
            result
            (progn
               (dolist (h holes)
                  (setq result (send h :eps-insidep point))
                  (if (eq result ':inside)
                      (return-from :eps-insidep ':outside)
                      (if (eq result ':border)
                          (return-from :eps-insidep ':border)
                          )))
               ':inside)))))

(defmethod body
 (:contact-vertices (b)
   (let ((cbox (send box :intersection (send b :box))))
     (when cbox
       (let ((myvertices (send self :possibly-contacting-vertices cbox))
             (hisfaces (send b :possibly-contacting-faces cbox))
             conp e1 ftemp)
         (dolist (v myvertices)  ; select contacting vertices
           (dolist (f hisfaces)
             (if (not (eq (send f :contactp v) ':outside))
                 (return
                  (push (instance constrained-point :init
                                  :position v :hisposition (send f :foot v)
				  :hisface f)
                        conp)))))
         (dolist (p conp)    ; append back pointer to edges
           (dolist (e edges)
             (if (or (equal (constrained-point-position p) (edge-pvert e))
                     (equal (constrained-point-position p) (edge-nvert e)))
                 (setf (constrained-point-myneighborhood p)
                       (cons e (constrained-point-myneighborhood p))))))
                              ; p=(position hisface (myedge1 myedge2 ...))
         (dolist (p conp)
           (send p :to-convex))
         conp))))
 (:contact-edges (b)
   (let ((cbox (send box :intersection (send b :box))))
     (when cbox
       (let ((myedges (send self :possibly-contacting-edges cbox))
             (hisfaces (send b :possibly-contacting-faces cbox))
             feet conp op)
         (dolist (e myedges)
           (dolist (f hisfaces)
             (setq feet (send f :contact-edge e))
             (if (and feet
		      (null (find (first feet) conp
			      :test #'(lambda (a b)
					(eps-v= a
						(constrained-point-position b)
						*contact-threshold*)))))
                 (if (plusp (edge-angle e))
		     (push (instance constrained-point :init
				     :position (first feet)
				     :hisposition (second feet) :hisface f
				     :myneighborhood (list (list e)))
			   conp)
                   (push (instance constrained-point :init
                           :position (first feet)
			   :hisposition (second feet) :hisface f
			   :myneighborhood (list (list (edge-pface e))
						 (list (edge-nface e))))
                         conp)))))
		   ; and-edge conp=((vertex hisface ((edge))) ...)
                   ; or-edge  conp=((vertex hisface ((face1) (face2))) ...)
         conp)))))

;;
;; Hirukawa's constraint motion planning
;;

(defun eq-or-cond (x y)
  (if (and (float-vector-p (first x)) (float-vector-p (first y)))
	   (eps-v= (first x) (first y))
    (print 'error-from-eq-or-cond)))

(defmethod constrained-point
  (:init (&key ((:position v1)) ((:hisposition v2)) ((:hisface f))
	       ((:myneighborhood n)) ((:condition c)))
	 (if v1 (setq position v1))
	 (if v2 (setq hisposition v2))
	 (if f (setq hisface f))
	 (if n (setq myneighborhood n))
	 (if c (setq condition c))
	 self)

  (:to-convex ()
    (let ((count 0) or-edge ip esets)
      (dolist (e myneighborhood)  ; count the number of 'or edge'
	      (when (minusp (edge-angle e))
		    (setq count (1+ count))
		    (setq or-edge e)))  ; set any or-edge to e
      (cond 
       ((= count 0)
	(setf myneighborhood 
	      (list myneighborhood)))
		   ; self=(vertex hisface ((myedge1 myedge2 ...)))
       ((= count 1)
	(send self :divide1 or-edge))
	      ; self=(vertex hisface ((myedge11 ...) (myedge21 ...)))
       ((>= count 2)
	(send self :dividen or-edge)))
               ; conp=((vertex hisface ((myedge11 and myedge12...) or ...))...)
	       ; conp=((vertex hisface ((face11) or ...)) ...)
      ))
)

(defmethod constrained-point
  (:divide1 (or-edge)
     (let ((or-edge-faces (list (edge-pface or-edge) (edge-nface or-edge)))
	   or-edge-face esets ip)
       (while or-edge-faces
	 (setq or-edge-face (first or-edge-faces))
	 (setq or-edge-faces (cdr or-edge-faces))
	 (do
	  ((e or-edge e)
	   (elist (remove or-edge myneighborhood) (remove e elist))
	   (flist (list or-edge-face) flist) ; start from one face of or-edge
	   (eset nil eset)
	   (anotherface nil nil))
	  ((or (< *epsilon* 
		  (send or-edge-face :distance (edge-nvert e)))
	       (< *epsilon*
		  (send or-edge-face :distance (edge-pvert e))))
		      ; when one edge is out of the or-face
	   (setq flist (cdr flist))
	   (setq eset (cdr eset))
	   (when
	    (< 2 (length flist))
	    ; add new edge only when it points different faces from other edges
	    (dolist (ee (face-edges (first flist)))
	      (unless 
	       (or (equal (edge-pvert ee) position)
		   (equal (edge-nvert ee) position))
	       ; search an edge both of whose vertices are NOT self's position
	       (setq ip
		 (send or-edge-face :intersection
		       (edge-pvert ee) (edge-nvert ee)))
	       (when
		(and (< 0.0 ip) (< ip 1.0))
		(return 
		 (if (< *epsilon*    ; this used to be *contact-threshold*
			(send (car (last eset)) :distance (send ee :point ip)))
		     (push (instance edge :init
				     :pvertex position
				     :nvertex (send ee :point ip)
				     :pface (first flist) :nface or-edge-face)
			   eset)))))))
	   (push eset esets))
	  ; body of do
	  (dolist (ee elist) ;trace faces from or-edge to the intersection edge
	    (cond ((equal (first flist) (edge-pface ee))
		   (setq anotherface (edge-nface ee)))
		  ((equal (first flist) (edge-nface ee))
		   (setq anotherface (edge-pface ee))))
	    (when anotherface
		  (push anotherface flist)
		  (push ee eset)
		  (return (setq e ee))))
	  )
	 )
       (setf myneighborhood esets)))
  (:dividen (or-edge)
    (let (esets e n-point sign)
      (do ((elist (remove or-edge myneighborhood) (remove e elist))
	   (flist (list (edge-pface or-edge)) flist)
					; start from one of or-edges
	   (eset nil eset)
	   (anotherface nil nil))
	  ((null elist)
	   (if eset (push eset esets)
	     (push flist esets))
	   esets)
	  ; body of do
	  (dolist (ee elist)
	    (cond ((equal (first flist) (edge-pface ee))
		   (setq anotherface (edge-nface ee)))
		  ((equal (first flist) (edge-nface ee))
		   (setq anotherface (edge-pface ee))))
	    (when anotherface
	      (cond
	       ((plusp (edge-angle ee))
		(push anotherface flist)
		(push ee eset)
		(return (setq e ee)))
	       (t
		(if eset
		  (progn
		    (when (< 2 (length flist))
			  ; add new edge only when it differs from others
		      (setq n-point
			(v+ position (v* (face-normal (first flist))
					 (face-normal (car (last flist))))))
		      ; n-point is on an intersection line of two or-edge-face
		      (dolist (f flist)
			(setq sign (- sign (send f :distance n-point))))
		      ; check if n-point is in my neighborhood or not
		      ; when it is in the neighborhood, distance is negative
		      ; when it is out, distance is positive
		      ; sign has different sign from distance, because it will
		      ; be used for correcting the position of new vertex
		      (push (instance edge :init
			      :pvertex position
			      :nvertex (normalize-vector (scale sign n-point)) 
			      :pface (first flist) :nface (car (last flist)))
			    eset))
		    (push eset esets))
		  (push flist esets))
		(setq eset nil)
		(setq flist (list anotherface))
		(return (setq e ee)))))))
      (setf myneighborhood esets)))

  (:analyse-contact (hispoint)
    (let ((myneighbor myneighborhood)
	  (hisneighbor (constrained-point-myneighborhood hispoint))
	  and-cond f-normal eec evc vvc)
      (dolist (mine myneighbor)   ; divide my neighborhood to convex ones
	(dolist (his hisneighbor) ; divide his neighborhood to convex ones
				  ; the following push = (and)
	  ; classify the contact point by neighbor types
	  (if (facep (first mine))
	      (pushnew (face-contact mine -1.0) and-cond :test #'eq-or-cond)
	    (if (facep (first his))
		(pushnew (face-contact his 1.0) and-cond :test #'eq-or-cond)
	      (if (= (length mine) 1)
		  (if (= (length his) 1)
		      (if (setq eec
			    (edge-edge-contact position hisposition mine his))
			  (pushnew eec and-cond :test #'eq-or-cond))
		    (if (setq evc
			      (edge-vertex-contact 
			       position hisposition mine his 1.0))
			(pushnew evc and-cond :test #'eq-or-cond)))
		(if (= (length his) 1)
		    (if (setq evc (edge-vertex-contact
				   position hisposition his mine -1.0))
			(pushnew evc and-cond :test #'eq-or-cond))
		  (if (setq vvc (vertex-vertex-contact
				 position hisposition mine his))
		      (pushnew vvc and-cond :test #'eq-or-cond))))))))
      (return-from :analyse-contact
		   (instance constrained-point :init
		     :position position :condition and-cond))))
  (:draw-constraint (&optional v (arrow-length 30) c)
    (if v (setq *viewer* v))
    (dolist (and-c condition)
      (dolist (or-c and-c)
	(draw-arrow position (v+ position (scale arrow-length or-c)) t c)))))

(defun draw-arrow (p1 p2 &optional clip color)
  (send *viewer* :draw-arrow p1 p2 clip color))
;  (send *viewsurface* :flush))

(defmethod constraint-relation
  (:init (&key ((:constrained-body m)) ((:constraining-body h))
	       ((:constraints c)))
	 (if m (setq constrained-body m))
	 (if h (setq constraining-body h))
	 (if c (setq constraints c))
	 self)
  (:constrained-body () constrained-body)
  (:constraining-body () constraining-body))


(defun contact-to-constraint (mycontact hiscontact)
  (let (another-point constraints)
    (dolist (point mycontact)
      (setq another-point
	    (find point hiscontact :test #'(lambda (a b)
					     (eps-v= 
					       (constrained-point-position a)
					       (constrained-point-position b)
					       *penetration-threshold*))))
      (if another-point
	(progn (push (send point :analyse-contact another-point) constraints)
	       (setf hiscontact
		(delete another-point hiscontact :test #'(lambda (a b)
					     (eps-v= 
					       (constrained-point-position a)
					       (constrained-point-position b)
					       *penetration-threshold*)))))
     ; point is in one of his faces, constraint= (vertex ((normal_of_hisface)))
	(push (instance constrained-point :init
		:position (constrained-point-position point)
		:condition
		(list (list (face-normal (constrained-point-hisface point)))))
	  ;      (and) (or)
	      constraints)))
    (if hiscontact
      (dolist (point hiscontact)
	(push
	 (instance constrained-point :init
	   :position (constrained-point-position point)
	   :condition
     ; his point is in one of my faces, the normal vector must be reversed.
	   (list (list (scale -1.0
     ;      (and) (or)
			(face-normal (constrained-point-hisface point))))))
	 constraints)))
    constraints))

(defun face-contact (f sign)
  (list (scale sign (face-normal (first f)))))
;  (or)

(defun edge-edge-contact (position hisposition myedge hisedge)
  (let ((e1 (first myedge)) (e2 (first hisedge)) mypoints hispoints s-plane)
    (setq mypoints (send e1 :neighborpoints position))
    (setq hispoints (send e2 :neighborpoints position))
    (if (< (- (* (norm (v- (edge-nvert e1) (edge-pvert e1)))
		 (norm (v- (edge-nvert e2) (edge-pvert e2))))
	      (abs (v. (v- (edge-nvert e1) (edge-pvert e1))
		       (v- (edge-nvert e2) (edge-pvert e2)))))
	   *penetration-threshold*)
	; when e1 and e3 are parallel, exit.
	(return-from edge-edge-contact nil))
    ; s-plane is the plane including myedge and hisedge
    (setq s-plane (make-plane :normal
			      (v* (v- (edge-nvert e1) (edge-pvert e1))
				  (v- (edge-nvert e2) (edge-pvert e2)))
			      :point position))
    (list (send s-plane :separation hisposition mypoints hispoints))))
;    list=(or)

(defun edge-vertex-contact (position hisposition myedge hisvertex sign)
  (let ((e1 (first myedge)) mypoints hispoints c-vector p1 or-cond s-plane)
    (setq mypoints (send e1 :neighborpoints position))
    ; mypoints=(point1_on_myedge point2_on_my_edge
    ;           point_on_pface point_on_nface)
    (setq hispoints
	  (mapcar #'(lambda (e) (send e :anothervertex position)) hisvertex))
    ; check if pface or nface of myedge becomes a separating face or not  
    (setq c-vector
	  (send (edge-pface e1) :separation hisposition mypoints hispoints))
    (if c-vector (push c-vector or-cond))
    (setq c-vector
	  (send (edge-nface e1) :separation hisposition mypoints hispoints))
    (if c-vector (push c-vector or-cond))
    (setq p1 (first mypoints))
    (dolist (p2 hispoints)
      (setq s-plane (make-plane :normal (v* (v- p1 position) (v- p2 position))
				:point position))
      (setq c-vector
	    (send s-plane :separation hisposition mypoints hispoints))
      (if c-vector (pushnew c-vector or-cond :test #'eps-v=)))
    (if (minusp sign) (setq or-cond
			    (mapcar #'(lambda (v) (scale -1.0 v)) or-cond)))
    or-cond))

(defun vertex-vertex-contact (position hisposition myvertex hisvertex)
  (let (mypoints hispoints bothpoints c-vector p1 or-cond s-plane)
    (setq mypoints
	  (mapcar #'(lambda (e) (send e :anothervertex position)) myvertex))
    (setq hispoints
	  (mapcar #'(lambda (e) (send e :anothervertex position)) hisvertex))
    (setq bothpoints hispoints)
    (dolist (p mypoints)
      (unless (find p hispoints :test #'eps-v=) (push p bothpoints)))
    ; check if a plane including any two points of bothpoints becomes
    ;          a separating plane or not
    (while bothpoints
      (setq p1 (first bothpoints))
      (setq bothpoints (cdr bothpoints))
      (dolist (p2 bothpoints)
	(setq s-plane (make-plane :normal (v* (v- p1 position)
					      (v- p2 position))
				  :point position))
	(setq c-vector
	      (send s-plane :separation hisposition mypoints hispoints))
	(if c-vector (pushnew c-vector or-cond :test #'eps-v=))))
    or-cond))
