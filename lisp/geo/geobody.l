;;;
;;; geobody.l
;;;	geometric computation package for EUSLISP
;;;	Copyright (1988) Toshihiro MATSUI,Electrotechnical Laboratory
;;;
;;;	revision history
;;;	1990 
;;;	Sep/27	split from geopack.l

(in-package "GEOMETRY")

(export '(add-wings))

(require :geoclasses "geoclasses.l")

(defvar *edge-class*)
(defvar *face-class*)
(defvar *body-class*)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; FaceSet

;; basic accessors

(defmethod FaceSet
 (:update ()
    (if *debug* (format *error-output* "updating body ~A~%" (send self :name)))
    (send self :reset-vertices)
    (dolist (f faces) (send f :reset-normal))	;update surface normals
    (remprop self :visible-edges)
    self)
 (:vertices () vertices)
 (:faces (&rest x)
    (cond (x (send* self :get-face x))
	  (t faces)))
 (:face (n) (nth n faces))
 (:all-edges () edges)
 (:edges () edges)
 (:edge (n) (nth n edges))
 (:vertex (n) (nth n vertices))
 (:box () box) 
 (:color (&optional new)
    (if new
	(setf (get self :color) new)
	(get self :color)))
 (:reflectance (&optional new &aux ref)
    (if new
	(setf (get self :reflectance) new)
	(if (setq ref (get self :reflectance)) ref 0.5)))
 (:diffusion (&optional new &aux dif)
    (if new
	(setf (get self :diffusion) new)
	(if (setq dif (get self :diffusion)) dif 0.5)))
 (:holes () (apply #'append (send-all faces :holes)))
 (:visible-faces (vp)
    (if (derivedp vp viewing) (setq vp (send vp :viewpoint)))
    (mapcan #'(lambda (f) (if (send f :visible vp) (list f))) faces))
 (:visible-edges (vp &aux visible-faces r)
    (if (derivedp vp viewing) (setq vp (send vp :viewpoint)))
    (if (equal (car (setq r (get self :visible-edges))) vp)
	(cdr r)
        (let ((htab (make-hash-table :size (round (* 1.5 (length edges)))
				 :hash #'sys:address))  )
	     (dolist (f (send self :visible-faces vp))
		 (dolist (e (send f :all-edges))   (setf (gethash e htab) e)) )
	      (setq r (send htab :list-values))
	      (setf (get self :visible-edges) (cons vp r))
	      (sys:reclaim (hash-table-key htab))
	      (sys:reclaim (hash-table-value htab))
	      r )) )
 (:contour-edges (vp &aux (visible-faces (send self :visible-faces vp)) r)
     (dolist (e edges)
	(cond ((member (edge-pface e) visible-faces)
		(if (not (member (edge-nface e) visible-faces))
		    (push e r)))
	      ((member (edge-nface e) visible-faces)
		(if (not (member (edge-pface e) visible-faces))
		    (push e r))) ) )
     r)
 (:non-contour-edges (vp &aux (visible-faces (send self :visible-faces vp)) r)
     (dolist (e edges)
	(if (and (member (edge-pface e) visible-faces)
		 (member (edge-nface e) visible-faces))
		    (push e r)))
     r)
 (:common-box (b &optional (tolerance))	; common minimal box between two bodies
    (declare (type body b))
    (send box :intersection (send b :box) tolerance))
 (:Newbox (&optional (tolerance *contact-threshold*))
    (setq box (make-bounding-box vertices tolerance)))
)

;; shape modification methods
;; These methods destructively changes `model-vertices'.
;; The history of modification is recorded in the csg list so that the
;; shape change can be played back again.

(defmethod FaceSet
 (:reset-vertices ()
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
 (:translate-vertices (trans)
	;move all vertices with respect to the coordinates,
	;without moving coordinates.
    (dolist (v model-vertices) (v+ v trans v))
    (send self :update)
    ;(send-all (send self :primitive-bodies) :translate-vertices trans self)
    self)
 (:rotate-vertices (rad axis)
	;move all vertices with respect to this coordinates
	;without moving coordinates.
    (let (rotmat)
	(if (float-vector-p axis) (setq rotmat (rotation rad axis)))
        (dolist (v model-vertices)
	   (if (float-vector-p axis)
	       (transform rotmat v v)
	       (rotate-vector v rad axis v))))
    (send self :update)
;    (send-all (send self :primitive-bodies) :rotate-vertices rad axis self)
    self)
 (:magnify (scale &optional (axis))
    (cond (axis
	   (setq axis (cond ((eql axis :x) #f(1 0 0))
			    ((eql axis :y) #f(0 1 0))
			    ((eql axis :z) #f(0 0 1))
			    (t (normalize-vector axis))))
	   (dolist (v model-vertices) 
	      (v+ (scale (* (- scale 1.0) (v. v axis)) axis) v v) )
	   )
	  (t (dolist (v model-vertices) (scale scale v v)) ))
    (send self :update)
    self) )

(defmethod FaceSet
 (:faces-intersect-with-point-vector (point vector)
  "args=(point vector)
checks intersection with a line which extends from POINT toward VECTOR direction."
    (let (result  intersect)
       (dolist (f faces)
	 (setq intersect (send f :intersect-point-vector point vector))
         (if (eq (car intersect) ':inside)
	     (push (list f (cadr intersect)) result )))
       result))
 (:distance (target)
    (let ((closest-distance) (closest nil) d)
       (cond ((derivedp target float-vector)
	      (setq closest-distance 1.0e30)
	      (dolist (f faces)
		(setq d (send f :distance target))
		(when (< (abs d)  (abs closest-distance))
		   (setq closest-distance d
			 closest f))))
	    ((derivedp target plane)
	     (setq closest-distance (send target :distance (car vertices))
		   closest (car vertices))
	     (dolist (v (rest vertices))
		(setq d (send target :distance v))
		(when (< d closest-distance)
		   (setq closest-distance d
			 closest v))) )  )
      (values closest-distance closest))
   )
 )

(defmethod FaceSet
 (:init (&rest initargs
	  &key ((:faces f)) ((:edges e)) ((:vertices v)) 
	       (color nil) (reflectance) (diffusion)
	  &allow-other-keys)
    (when f
	(setq  faces f)
	(if (null e)
	    (setq edges (remove-duplicates (apply #'append (send-all f :all-edges)))))
	(if (null v)
	    (setq vertices (remove-duplicates (apply #'append (send-all f :all-vertices)))))
	)
    (send-super* :init initargs)
    (when e (setq edges e))
    (when v (setq vertices v))
    (setq box (instance bounding-box :init vertices *contact-threshold*))
    (if (null model-vertices))
        (setq model-vertices (mapcar #'copy-seq vertices))
    (if color (setf (get self :color) color))
    (if reflectance (setf (get self :reflectance) reflectance))
    (if diffusion (setf (get self :diffusion) diffusion))
    self)
  )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;; body (Brep)
;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod body
 (:translate-vertices (trans)
    (send-super :translate-vertices trans)
    (nconc csg (list (list :translate-vertices trans)))
    self)
 (:rotate-vertices (rad axis)
    (send-super :rotate-vertices rad axis)
    (nconc csg (list (list :rotate-vertices rad axis)))
    self)
 (:magnify (scale &optional (axis))
    (send-super :magnify scale axis)
    (nconc csg (list (list :magnify (float scale) axis)))
    self)
 )

;; mass properties
(defmethod body
 (:euler () ":euler returns the number of rings (passes)"
    (let ((v (length vertices)) (e (length edges)) (f (length faces))
          (L (length (send self :holes)) ) )
	;pass(ring) is unknown
        (declare (integer v e f L))
        %((e - f - v + 2 + L) / 2)    ) )
 (:perimeter () (apply #'+ (send-all edges :length)))
 (:volume (&optional (point #f(0 0 0)))
    (apply #'+ (send-all faces :volume point)))
 (:centroid (&optional (point (float-vector 0 0 0)))
    (let* ((cents (send-all faces :centroid point))
	   (total-area (apply #'+ (mapcar #'car cents)))
	   (glist (mapcar #'(lambda (c) (apply #'scale c)) cents))
	   (centroid (float-vector 0 0 0)))
	(dolist (g glist)  (v+ g centroid centroid))
	(scale (/ 1.0 total-area) centroid centroid)
;	(setf (get self :centroid) centroid)
	centroid))
 (:world-centroid ()
    (send (send self :worldcoords) :transform-vector (get self :centroid)))
 (:area () (apply #'+ (send-all faces :area)))
 (:extream-point (vec)
":extream-point (vec) finds the farthest point along vec in vertices."
     (let* ((p (first vertices)) (m (v. vec p)) m2)
	(declare (float m m2))
	(dolist (v (rest vertices))
	   (setq m2 (v. vec v))
	   (if (> m2 m) (setq m m2  p v)))
	p))
 (:length (vec)
   "length in vec direction"
   (-  (v. vec (send self :extream-point vec))
       (v. vec (send self :extream-point (scale -1.0 vec)))) ) 
 (:supporting-faces (&optional (gravity (floatvector 0.0 0.0 -1.0)))
    (send self :faces-intersect-with-point-vector
  	       (send self :centroid) gravity))
 )

;; intersection

(defmethod body
 (:possibly-interfering-faces (cbox)
    (mapcan #'(lambda (f) (if (send f :boxtest cbox) (list f))) faces))
 (:possibly-interfering-edges (cbox)
    (mapcan #'(lambda (e) (if (send e :boxtest cbox) (list e))) edges))
 (:intersect-face (f) ;bug 90Sep
    (dolist (aface faces)
	(if (or (send aface :intersect-face f)
	        (send f :intersect-face aface))
	    (return-from :intersect-face T)))
    nil)
 (:intersectp (b)	;check intersection with another body
    (declare (type body b))
    (let* ((cbox (send box :intersection (send b :box)))
	   myfaces hisfaces)
       (when cbox			;boxes interfer?
	  (setq myfaces (send self :possibly-interfering-faces cbox))
	  (setq hisfaces (send b :possibly-interfering-faces cbox))
 	  (dolist (f1 myfaces)
	     (dolist (f2 hisfaces)
		(setq cbox (send (send f1 :box) :intersection (send f2 :box)))
		(if (or (send f1 :intersect-face f2 cbox)
			(send f2 :intersect-face f1 cbox))
		     (return-from :intersectp t))
		;; (sys:reclaim-tree cbox) ;; segfaults if GC occured
                )))))
(:intersectp2 (body2 &optional (tolerance *epsilon*))
   (let* ((cbox (send self :common-box body2))
	  faces1 faces2 edges1  edges2 p point flag inside-flag)
      (when cbox
	  (setq faces1 (send self :possibly-interfering-faces cbox))
	  (setq faces2 (send body2 :possibly-interfering-faces cbox))
	  (setq edges1 (send self :possibly-interfering-edges cbox))
	  (setq edges2 (send body2 :possibly-interfering-edges cbox))
	  (dolist (f1 faces1)
	    (dolist (e2 edges2)
	       (cond ((send f1 :coplanar-line e2)
			(when (null flag)
			  (dolist (e1 (send f1 :all-edges))
			     (if (consp (send e1 :intersect-line e2))
				 (let ((n (send f1 :normal)))
				    (if (or (eps= 1.0 (v. n (send (edge-pface e2) :normal)))
					    (eps= 1.0 (v. n (send (edge-nface e2) :normal))))
					(return-from :intersectp2 :intersect)
			                (return (setq flag :contact))))))
	                  (if (send f1 :insidep (line-pvert e2))
			      (let ((n (send f1 :normal)))
				    (if (or (eps= 1.0 (v. n (send (edge-pface e2) :normal)))
					    (eps= 1.0 (v. n (send (edge-nface e2) :normal))))
					(return-from :intersectp2 :intersect)
			                (setq flag :contact)))) ))
		     (t			
		       (setq p (send f1 :intersection (line-pvert e2)
						      (line-nvert e2)))
		       (when (and (not (eq p *nan*))
				  (eps-in-range 0.0 p 1.0 tolerance))
			  (setq point (send e2 :point p))
			  (setq inside-flag (send f1 :insidep point))
			  (cond ((and (or (eps= p 0.0 tolerance)
				          (eps= p 1.0 tolerance))
				      (member inside-flag '(:inside :border)))
				  (setq flag :contact))
				(t 
				 (case inside-flag
				   (:inside
					(return-from :intersectp2 :intersect))
				   (:border
					(setq flag :contact)))))) ))))
	  (dolist (f1 faces2)
	    (dolist (e2 edges2)
	       (cond ((send f1 :coplanar-line e2)
			(when (null flag)
			  (dolist (e1 (send f1 :all-edges))
			     (if (consp (send e1 :intersect-line e2))
				 (let ((n (send f1 :normal)))
				    (if (or (eps= 1.0 (v. n (send (edge-pface e2) :normal)))
					    (eps= 1.0 (v. n (send (edge-nface e2) :normal))))
					(return-from :intersectp2 :intersect)
			                (return (setq flag :contact))))))
	                  (if (send f1 :insidep (line-pvert e2))
			      (let ((n (send f1 :normal)))
				    (if (or (eps= 1.0 (v. n (send (edge-pface e2) :normal)))
					    (eps= 1.0 (v. n (send (edge-nface e2) :normal))))
					(return-from :intersectp2 :intersect)
			                (setq flag :contact)))) ))
		     (t			
		       (setq p (send f1 :intersection (line-pvert e2)
						      (line-nvert e2)))
		       (when (and (not (eq p *nan*))
				  (eps-in-range 0.0 p 1.0 tolerance))
			  (setq point (send e2 :point p))
			  (setq inside-flag (send f1 :insidep point))
			  (cond ((and (or (eps= p 0.0 tolerance)
				          (eps= p 1.0 tolerance))
				      (member inside-flag '(:inside :border)))
				  (setq flag :contact))
				(t 
				 (case inside-flag
				   (:inside
					(return-from :intersectp2 :intersect))
				   (:border
					(setq flag :contact)))))) ))))
       flag)) )
 (:insidep (point &optional (tolerance *coplanar-threshold*))
   ;;does point lie in this body?
   (if (and (null evertedp)
	    (null (send box :inner point)))
       (return-from :insidep ':outside))
   (let (d random-vnorm flag intersect-count)
    (cond
	(convexp
	   (dolist (f faces)
	      (setq d (send f :plane-distance point))
              (cond ((< (abs d) tolerance)
		     (setq flag (send f :insidep point))
		     (if (eq flag ':outside)
			 (return-from :insidep ':outside)
			 (return-from :insidep ':border)))
		    ((> d 0.0)  (return-from :insidep ':outside))))
	   ':inside)
	(t 
	  (setq flag nil)
	  (while (null flag)
	     (setq random-vnorm (random-normalized-vector)
		   intersect-count 0)
	     (dolist (f faces)
		(if (and (<  (abs (send f :plane-distance point)) tolerance)
			 (null (eq (send f :insidep point) ':outside)))
		    (return-from :insidep ':border))
		(setq flag
		      (send f :intersect-point-vector point random-vnorm))
		(case (car flag)
		  (:inside (inc intersect-count))
		  (:outside )	;do nothing
		  (t (setq flag nil) (return nil)))))
	  (if (null evertedp)
	      (if (oddp intersect-count) ':inside ':outside)
	      (if (oddp intersect-count) ':outside ':inside))))))
 (:evert ()
    (send-all faces :invert)
    (send-all edges :invert)
    (setq evertedp (null evertedp))
    (cond (evertedp
	   (setq box (instance bounding-box :init2
			(float-vector -1.e10 -1.e10 -1.e10)
		        (float-vector 1.e10 1.e10 1.e10)))
	   (setq convexp nil))
	  (t (send self :newbox)
	     (send self :set-convexp)))
    evertedp)
 (:set-convexp ()
    (if (every #'(lambda (x) (>= x 0.0)) (send-all edges :angle)) (setq  convexp t))
    (send-all faces :set-convexp)
    self)
)

;;;
;;; csg management
;;;

(defmethod body
 (:get-face (&optional b f id)
     (let (r rr rrr ftype)
	(cond ((bodyp b)
	       (dolist (f faces)
		 (if (eq (send f :primitive-body) b)  (push f r))))
	      ((keywordp b)
	       (dolist (f faces)
		  (if (eq (car (send f :primitive-body-type)) b)
		      (push f r))))
	      (t (setq r (copy-seq faces))))
	(cond ((facep f)
	       (dolist (fx r)
		  (if (eq (send fx :primitive-face) f) (push fx rr)))  )
	      ((keywordp f)
	       (dolist (fx r)
		  (setq ftype (car (send fx :id)))
		  (if (or (eq ftype f)
			  (and (eq f :end) (member ftype '(:top :bottom))))
		      (push fx rr)))  )
	      (t (setq rr r)))
	(cond (id
	        (dolist (fx rr)
		  (if (eq (second (send fx :id)) id) (push fx rrr)))  
		rrr)
	      (t rr))))
 (:primitive-body-p () (and (consp (car csg)) (keywordp (caar csg))))
 (:primitive-bodies (&optional +/-  btype)
    "collects primitive bodies that defines this body in a list"
    (labels
	((getprimt (x)
	    (cond ((primitive-body-p x) (list x))
		  ((listp x)
		   (mapcan #'getprimt
			   (cond ((listp (cadr x))  (cadr x))
				 (t (third x)))))
		  (t (mapcan #'getprimt (cadr (send x :csg)))) )) )
      (let (pbodies)
	 (case +/-
	    (:+ (setq pbodies (first  (send self :primitive-groups))))
	    (:- (setq pbodies (second (send self :primitive-groups))))
	    (t  (setq pbodies (getprimt self)) ) )
	 (cond (btype
		(collect-if
			#'(lambda (pb &aux (bt (car (send pb :body-type))))
				(if (consp btype)
				    (member bt btype)
				    (eql btype bt)))
			pbodies))
	       (t pbodies)))))
 (:csg (&optional newcsg)
    (if newcsg (setq csg newcsg) csg) )
 (:copy-csg ()
   (labels
       ((copy-csg (csg)
	   (cond ((listp csg)
		  (list (car csg)
			(mapcar #'(lambda (x) (copy-csg x))
					  (cadr csg))))
		 ((bodyp csg)
		  (let ((csgb) (par) (dec))
		     (send csg :worldcoords)
		     ;; dissociate csg body from the inheritance tree
		     ;; to keep consisntency after copying
		     (setq par (send csg :parent))
		     (if par (send par :dissoc csg))
		     (setq dec (send csg :descendants))
		     (send csg :clear-assoc)
		     ;; copy the body
		     (setq csgb (copy-object csg))
		     ;; restore the inheritance tree
		     (if par (send par :assoc csg))
		     (dolist (d dec) (send csg :assoc d))
		     (send csgb :worldcoords)
		     (dolist (f (body-faces csgb))
			(send f :primitive-face f))
		     (setf (get csgb :copied-primitive) csg)
		     csgb) ))) )
	(if (send self :primitive-body-p)
	    (copy-csg self)
	    (copy-csg csg ))
	))
 (:body-type ()
    (if (member (car csg) '(+ - * /))
	(list :complex (car csg))
	(car csg)))
 (:creation-form ()
"returns eus program that re-creates this body."
   (labels ((cr-form (csg)
		(cond
		  ((listp csg)
		   (cond ((eq (car csg) '+)
			  (list* 'body+ (mapcar #'cr-form (cadr csg))) )
			 ((eq (car csg) '-)
			  (list* 'body- (mapcar #'cr-form (cadr csg))) ) ))
		  ((bodyp csg)
		   (let ((creation (car (send csg :csg))))
		      (setq creation
			    (case (car creation)
				(:cube (cons 'make-cube (cdr creation)))
				(:cylinder (list* 'make-cylinder
						  (cadr creation)
						  (caddr creation)
						  :segments  (cdddr creation)))
				(t (error "don't know how to create ~a" creation))) )
		       (append creation (list :name (send csg :name)))
	 	       `(send ,creation
			      :move-to ,(send csg :worldcoords) :world) ) ))))
         (if (send self :primitive-body-p)
             (cr-form self)
             (cr-form csg))) )
 (:prin1 (strm)    (send-super :prin1 strm (send self :body-type)))
 (:init  (&rest initargs
	  &key (approximated nil)
	       (primitive nil) ((:csg csgform) nil)
	  &allow-other-keys)
    (send-super* :init initargs)
    (send-all edges :set-angle)
    (if approximated (send-all edges :set-approximated-flag))
    (if (every #'plusp (send-all edges :angle)) (setq  convexp t))
    (if (and vertices faces)
	(setf (get self :centroid #f(0 0 0)) (send self :centroid)
	      (get self :volume) (send self :volume)))
    (when primitive
        (send-all faces :body self)
	(setq csg  (list primitive)))
;;    (setq *bodies* (adjoin self *bodies*))
    self) )

(defmethod body 
 (:replace-shape (newbody)
     (dolist (p descendants)
	(if (get p :copied-primitive) (send self :dissoc p)))
     (setq faces (body-faces newbody)
	   edges (body-edges newbody)
	   vertices (body-vertices newbody)
	   model-vertices (geo::body-model-vertices newbody)
	   box (body-box newbody)
	   convexp (geo::body-convexp newbody)
	   csg (body-csg newbody))
     (setf (get self :visible-edges) nil)
     (let ((w-inv (send (send self :worldcoords) :inverse-transformation))
	   (mv model-vertices))
	(while mv
	   (setf (car mv) (send w-inv :transform-vector (car mv)))
	   (setq mv (cdr mv))
	   ))
     (send-all faces :body self)
     (dolist (p (send self :primitive-bodies)) (send self :assoc p))
     self)
 (:+ (&rest bodies)
    (send self :replace-shape (apply #'body+  self bodies)))
 (:- (&rest bodies)
    (send self :replace-shape (apply #'body-  self bodies)))
 (:* (&rest bodies)
    (send self :replace-shape (apply #'body*  self bodies)))
 (:primitive-groups ()
    (labels
       ((p-primitives (csg)
	     (cond ((listp csg)
		  (cond ((eq (car csg) '+)
			  (mapcan #'P-primitives (cadr csg)))
			((eq (car csg) '-)
			  (nconc (P-primitives (caadr csg))
				 (mapcan #'n-primitives (cdadr  csg))) ) )) 
		 ((primitive-body-p csg) (list csg) ) )) 
       (n-primitives (csg)
	     (if (listp csg)
	         (cond ((eq (car csg) '+) (mapcan #'n-primitives (cadr csg)))
		       ((eq (car csg) '-) 
			(nconc  (n-primitives (caadr csg))
				(mapcan #'P-primitives (cdadr csg))) )  )))
	)
     (if (send self :primitive-body-p)
	 (list (list self) nil)
	 (list (p-primitives csg) (n-primitives csg)))) )
  )


(defmethod body 	;Hirukawa
 (:constraint (b)	; get body(b)'s constraint to body(self)
    (declare (type body b))
    (let (mycontact hiscontact)
       (when (send box :intersection (send b :box))		;boxes contact?
	  (setq mycontact (nconc (send self :contact-vertices b)
				 (send self :contact-edges b)))
	  (setq hiscontact (nconc (send b :contact-vertices self)
				  (send b :contact-edges self)))
          (instance constraint-relation :init
            :constrained-body self
            :constraining-body b
            :constraints (contact-to-constraint mycontact hiscontact)))))
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
				  :position v :hisface f)
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
	     foot conp op)
	 (dolist (e myedges)
	   (dolist (f hisfaces)
	     (setq foot (send f :contact-edge e))
	     (if (and foot
		      (null (find foot conp
				 :test #'(lambda (a b)
					   (eps-v= a
						(constrained-point-position
							b)
						*contact-threshold*)))))
		 (if (plusp (edge-angle e))
		     (push (instance constrained-point :init 
				     :position foot :hisface f
				     :myneighborhood (list (list e)))
			   conp)
		   (push (instance constrained-point :init
				   :position foot :hisface f
				   :myneighborhood (list (list (edge-pface e))
							 (list (edge-nface e))))
			 conp)))))
		   ; and-edge conp=((vertex hisface ((edge))) ...)
                   ; or-edge  conp=((vertex hisface ((face1) (face2))) ...)
	 conp))))
 (:possibly-contacting-vertices (cbox)
    (mapcan #'(lambda (v) (if (send cbox :inner v) (list v))) vertices))
 (:possibly-contacting-edges(cbox)
    (mapcan #'(lambda (e)
		 (if (send e :boxtest cbox *contact-threshold*) (list e)))
	    edges))
 (:possibly-contacting-faces (cbox)
    (mapcan #'(lambda (f)
		 (if (send f :boxtest cbox *contact-threshold*)  (list f)))
	    faces)))



;;;
;;;
(defmethod sphere 
 (:radius (&optional r)
    (if r (setq radius r))
    radius)
 (:inner (point)
    (< (distance point pos) radius))
 (:volume () %(4.0 * pi * radius * radius * radius / 3))
 (:intersect-line (p1 p2)
    (let* ((lu p1)
	   (lv (v- p1 p2))
	   (center (send self :worldpos))
	   (g (v- lu center))
	   (a (v. lv lv))
	   (b (v. lv g))
	   (c (- (v. g g) (* radius radius)))
	   (d %(b * b - a * c)))
       (if (< d 0.0)
	   nil
	   (list (midpoint %(( b + sqrt(d)) / a) p1 p2)
		 (midpoint %(( b - sqrt(d)) / a) p1 p2)))) )
 (:closest-point (point)
    (v+ (send self :worldpos)
	(scale radius (normalize-vector (v- point (send self :worldpos))))))
 (:intersect-with-body (bod)
    (dolist (v (send bod :vertices))
	(if  (< (distance v pos) radius) (return-from :intersect-with-body t)))
    nil)
 (:init (&key (center (float-vector 0 0 0)) ((:radius r) 1.0))
    (send-super :init)
    (setq pos center  radius r)
    self))




(defun add-wings (bod)
  (let (edgering edge-pairs oldedge newedge)
    (dolist (e (body-edges bod))
	(setq newedge (instance winged-edge :init
				:pface (edge-pface e)
				:nface (edge-nface e)
				:pvertex (edge-pvert e)
				:nvertex (edge-nvert e)
				:angle (edge-angle e)
				:pwing (send e :pwing)
				:pcwing (send e :pcwing)
				:nwing (send e :nwing)
				:ncwing (send e :ncwing)))
	(setq edge-pairs (acons e newedge edge-pairs)))
    (dolist (ep edge-pairs)
	(setq oldedge (car ep)  newedge (cdr ep))
	(send newedge :init
		:pwing (cdr (assq (winged-edge-pwing newedge) edge-pairs))
	        :nwing (cdr (assq (winged-edge-nwing newedge) edge-pairs))
		:pcwing (cdr (assq (winged-edge-pcwing newedge) edge-pairs))
		:ncwing (cdr (assq (winged-edge-ncwing newedge) edge-pairs))))
    (dolist (f (send bod :faces))
	(setq edgering nil)
	(dolist (e (send f :edges))
	   (push (cdr (assq e edge-pairs)) edgering))
	(setf (face-edges f) edgering)
	(dolist (h (send f :holes))
	    (setq edgering nil)
	    (dolist (e (send h :edges))
		(push (cdr (assq e edge-pairs)) edgering))
	    (setf (hole-edges h) edgering)) )
    (setf (body-edges bod) (mapcar #'cdr edge-pairs))
    bod))

(provide :geobody "@(#)$Id: geobody.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $")

