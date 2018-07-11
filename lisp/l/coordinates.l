;;;;
;;;; coordinates.l
;;;; classes for representing 3-dimensional coordinate system
;;;; and their hierarchical cascading.
;;;;	Copyright 1987, Toshihiro MATSUI, Electrotechnical Laboratory
;;;;
;;;; timing measurements:
;;;;			sun3/60		sun4/260	Ustation/E20
;;;;  v+		 0.3ms		0.10ms
;;;;  m*		 0.7ms		0.23ms		1.4 ms 
;;;;  transform		 0.45ms		0.15ms
;;;;  rotate-matrix	 0.54ms		0.18ms
;;;;  rotation-matrix	 0.36ms

(eval-when(load eval)
   (unless (find-package "GEOMETRY")
	(make-package "GEOMETRY" :nicknames '("GEO"))
	(in-package "GEOMETRY")
	(use-package "LISP")))

(in-package "GEOMETRY")

(export '(
	#| coordinates cascaded-coords |#	;already exported by geoclasses
	coords cascoords make-cascoords make-coords transform-coords*
	transform-coords 
	coordinates-p))
(export '(*world-coords* *world-coords2*
	 coordinates-distance almost-same-coordinates-p))
(export '(coordinates-pos coordinates-rot))

;; export slot variable names
(export '(rot pos))
(export '(parent descendants worldcoords manager changed))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; class COORDINATES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass coordinates :super propertied-object
  :slots
  ((rot :type array)		;current rotation matrix
   (pos	:type float-vector))	;current position float-vector #v(x y z)
  )

(defun coordinates-p (obj)
  (derivedp obj coordinates))
(defmethod coordinates
  (:dimension () (length pos))
  (:rot () rot)	;inquire rotation matrix
  (:pos () pos)	;inquire positon vector
  (:x-axis () (matrix-row rot 0))
  (:y-axis () (matrix-row rot 1))
  (:z-axis () (matrix-row rot 2))
  (:name (&optional nm)
    (if nm (setf (get self :name) nm))
    (get self :name))
;update of coords is always done through :newcoords
  (:newcoords (c &optional p)
     (if p
	 (setq rot c pos p)
	 (setq rot (coordinates-rot c)   pos (coordinates-pos c)))
      self)
  (:replace-rot (r) (replace-matrix rot r))
  (:replace-pos (p) (replace pos p))
  (:replace-coords (c &optional p)
     (when (coordinates-p c)
	(setq p (coordinates-pos c) c (coordinates-rot c)))
     (replace-matrix rot c)
     (replace pos p)
     self)
  (:copy-rot () (copy-matrix rot))
  (:copy-pos () (copy-seq pos))
  (:copy-coords (&optional (dest (instance coordinates :create (length pos))))
     (replace (coordinates-pos dest) pos)
     (replace-matrix (coordinates-rot dest) rot)
     dest)
  (:coords (&optional (dest (instance coordinates :create (length pos))))
     (replace (coordinates-pos dest) pos)
     (replace-matrix (coordinates-rot dest) rot)
     dest)
  (:worldrot () rot)
  (:worldpos () pos)
  (:worldcoords () self)
  (:copy-worldcoords () (send self :coords))
  (:parentcoords () *world-coords*)
  (:changed () nil)
  (:reset-coords   ()
   (let ((dim (array-dimension rot 0)))
     (setq rot (unit-matrix dim)
	   pos (instantiate float-vector dim))
     (send self :changed)
     self))
  (:move-to (c &optional (wrt :local) &aux cc)
     (unless (coordinates-p c) (error "coordinates expected for :move-to"))
     (cond ((or (memq wrt '(:local local)) (eq wrt self))
	    (setq cc (transform-coords self c))
	    (send self :newcoords cc))
	   ((or (memq wrt '(:parent parent :world world))
		(equal wrt *world-coords*))
	    (send self :newcoords c))
	   ((coordinates-p wrt)
	    (setq cc (transform-coords (send wrt :worldcoords) c))
	    (transform-coords (send (send self :parentcoords)
				    :inverse-transformation) cc cc)
	    (send self :newcoords cc))))
  (:rotate-vector (v) (transform rot v))
  (:transform-vector  (v)
   ;vector v given in the local coords is converted to world representation
   (v+ (transform rot v) pos))
  (:inverse-transform-vector (vec)	;vec in world coordinates->local
    (let ((inv-rot (transpose rot)))
	(v- (transform inv-rot vec) (transform inv-rot pos))))
  (:inverse-transformation
   (&optional (dest (instance coordinates :create (length pos))))
   ;make new coordinates inverse to self
     (transpose rot (coordinates-rot dest))
     (transform (coordinates-rot dest) pos (coordinates-pos dest))
     (scale -1.0 (coordinates-pos dest) (coordinates-pos dest))
     dest)
  (:transformation   (c2 &optional (wrt :local))
   (setq c2 (send c2 :worldcoords)) 
   (let* ((c1 (send self :worldcoords)) 
	  (inv (send c1 :inverse-transformation))
	  xw)
      (cond
         ((or (memq wrt '(:local local)) (eq wrt self))
	   (transform-coords inv c2 inv))
         ((or (memq wrt '(:parent parent :world world))
	      (eq wrt *world-coords*))
	   (transform-coords c2 inv inv))
         ((coordinates-p wrt)
	   (setq xw (send wrt :worldcoords))
	   (transform-coords c2 inv inv)
	   (transform-coords (send xw :inverse-transformation) inv inv)
	   (transform-coords inv xw inv))
         (t (send self :error ":transform wrt?" wrt)))
      inv))
  (:transform  (c &optional (wrt :local))
   (cond
      ((or (memq wrt '(local :local)) (eq wrt self))	;multiply c from the right
	(transform-coords self c self))
      ((or (memq wrt '(parent :parent world :world))
	   (eq wrt *world-coords*))
	(transform-coords c self self))	;;multiply c from the left
      ((coordinates-p wrt)
	(transform-coords (send wrt :inverse-transformation) self self)
	(transform-coords c self self)
	(transform-coords (send wrt :worldcoords) self self))
      (t (send self :error ":transform wrt?" wrt)))
   (send self :newcoords rot pos))
  (:rotate-with-matrix (mat wrt)	;only for internal use
    (cond ((or (memq wrt '(local :local)) (eq wrt self))
	   (m* rot mat rot))
	  ((or (memq wrt '(:parent parent :world world nil))
		(eq wrt *world-coords*))
	   (m* mat rot rot))
	  ((coordinates-p wrt)
	   (let* ((r2 (send wrt :worldrot))
		  (r2t (transpose r2))
		  p2)
	      (m* mat r2t r2t)
	      (m* r2 r2t r2t) 
	      (m* r2t rot rot)))
	  (t (send self :error ":rotate wrt?"))))
  (:rotate (theta &optional axis (wrt :local))
    (cond ((= (length pos) 2)	; 2D
	   (cond ((numberp theta)
	          (rotate-matrix rot theta nil nil rot))
		 ((matrixp theta)
		  (m* theta rot rot))
		 (t (error "illegal rotation"))))
	  ((float-vector-p axis)
	   (send self :rotate-with-matrix (rotation-matrix theta axis) wrt))
	  ((null axis)
	   (send self :rotate-with-matrix theta wrt))
	  (t (cond
		((or (memq wrt '(:local local)) (eq wrt self))
		 (rotate-matrix rot theta axis nil rot))
		((or (memq wrt '(:parent parent :world world))
		     (eq wrt *world-coords*))
		 (rotate-matrix rot theta axis t rot))
		((coordinates-p wrt)	;C1'=C2*R*C2(-1)*C1
		 (send self :rotate-with-matrix
			    (rotation-matrix theta axis) wrt))
		(t  (send self :error ":rotate wrt?" wrt)))))
    (send self :newcoords rot pos) )
  (:orient-with-matrix (mat wrt)	;only for internal use
    (cond ((or (memq wrt '(local :local)) (eq wrt self))
	   (m* rot mat rot))
	  ((or  (memq wrt '(:parent parent world :world))
		(eq wrt *world-coords*))
	   (setf rot mat))
	  ((coordinates-p wrt)
	   (let* ((r2 (send wrt :worldrot))		  )
	      (m* r2 mat rot)))
	  (t (send self :error ":orient wrt?"))))
  (:orient (theta axis &optional (wrt :local))
    (cond ((float-vector-p axis)
	   (send self :orient-with-matrix (rotation-matrix theta axis) wrt))
	  ((matrixp theta)
	   (send self :orient-with-matrix theta wrt))
	  (t (cond
		((or (memq wrt '(local :local)) (eq wrt self))
		 (rotate-matrix rot theta axis nil rot))
		((or (memq wrt '(parent :parent world :world))
		 (eq wrt *world-coords*))
		 (setf rot (rotation-matrix theta axis)))
		((coordinates-p wrt)	;C1'=C2*R*C2(-1)*C1
		 (send self :orient-with-matrix
			    (rotation-matrix theta axis) wrt))
		(t  (send self :error ":orient wrt?" wrt)))))
    (send self :newcoords rot pos) )
  (:parent-vector (v wrt)
   (cond ((or (memq wrt '(:local local)) (eq wrt self))  (send self :transform-vector v))
	 ((or (memq wrt '(:world world :parent parent nil))
	      (eq wrt *world-coords*)) v)
	 ((coordinates-p wrt)
	  (send  wrt  :transform-vector v))
	 (t (send self :error ":parent-vector wrt?" wrt))))
  (:parent-orientation (v wrt)
   (cond ((or (memq wrt '(:local local)) (eq wrt self)) (transform rot v))
	 ((or (memq wrt '(:parent parent :world world nil))
	      (eq wrt *world-coords*)) v)
	 ((coordinates-p wrt)   (transform  (send wrt :worldrot) v))
	 (t (send self :error ":parent-orientation wrt? wrt must be :world, :local, :parent or coordinates instance" wrt))))
  (:translate (vec &optional (wrt :local))
     (send self :newcoords
	   rot (v+ (send self :parent-orientation vec wrt) pos pos)))
  (:locate (vec &optional (wrt :local))
     (send self :newcoords
		rot (replace pos (send self :parent-vector vec wrt))))
  (:scale (&optional s)
     (if s
	 (progn (scale-matrix s rot rot) (send self :newcoords self))
	 (norm (matrix-row rot 0))))
  (:euler (azimuth elevation rotation)	;be carefull with the angle order
	(send self :newcoords
		   (euler-matrix azimuth elevation rotation) pos))
  (:euler-angle () (euler-angle rot))
  (:rpy (r p y)
	(send self :newcoords
		   (rpy-matrix r p y) pos))
  (:rpy-angle () (rpy-angle rot))
  (:rotation-angle () (rotation-angle rot))
  (:4X4 (&optional mat44)
    (cond (mat44	;convert-from-4x4
	     (dotimes (i 3)
		(dotimes (j 3)
		   (setf (aref rot i j) (aref mat44 i j)))
	        (setf (aref pos i) (aref mat44 i 3)))
	     self)
	  (t	;makes 4x4 matrix representation
	    (setq mat44 (make-matrix 4 4))	;all zero elements
	    (setf (aref mat44 3 3) 1.0)
	    (dotimes (i 3)
		(dotimes (j 3)
		   (setf (aref mat44 i j) (aref rot i j)))
		(setf (aref mat44 i 3) (aref pos i)))
	    mat44)) )
 (:prin1 (&optional (strm t) &rest more-args
		&aux (rpy (send self :worldrot))
		     (p (send self :worldpos)))
     (cond ((> (length p) 2)
	    (setq rpy (car (rpy-angle rpy)))
	    (send-super :prin1 strm 
	     (format nil "~A ~1,3G ~1,3g ~1,3g / ~1,3g ~1,3g ~1,3g"
		   (if more-args (car more-args) "")
		   (aref p 0) (aref p 1) (aref p 2)
		   (first rpy) (second rpy) (third rpy))) )
	   ((= (length p) 2)
	    (send-super :prin1 strm 
	     (format nil "~A ~1,3g ~1,3g / ~1,3g"
		   (if more-args (car more-args) "")
		   (aref p 0) (aref p 1)   (rotation-angle rpy))))
	   (t (send-super :prin1 strm more-args))))
  (:create (&optional (dimension 3))
     (setq rot (unit-matrix dimension)
	   pos (instantiate float-vector dimension))
     self)
  (:init  (&key  (dimension 3)
		 ((:pos p) (instantiate float-vector dimension))
		 ((:rot r) (unit-matrix dimension))
		 (euler nil)
		 (rpy   nil)
		 (axis  nil)
		 (angle nil)
		 (at nil)
		 (coords at)
		 (4X4 nil)
		 (wrt :local)
		 ((:name nm))
		 (properties nil)
		 &allow-other-keys)
        (setq rot r)
	(setq pos 
	      (if (coordinates-p wrt)
		  (send wrt :transform-vector p)
		  p))
	(cond   (euler (send self :euler (elt euler 0) (elt euler 1) (elt euler 2)))
		(rpy (send self :rpy (elt rpy 0) (elt rpy 1) (elt rpy 2)))
		(coords  (send self :replace-coords coords))
		((consp angle)
		 (dolist (a angle)  (send self :rotate a (pop axis) wrt)))
		((numberp angle)
		 (send self :rotate angle axis wrt))
		(4X4 (send self :4X4 4X4)))
	(if nm (send self :name nm))
	(dolist (p properties)  (setf (get self (car p)) (cadr p)))
      self))	;coordinates

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; class CASCADED-COORDS
; Child coords inherits parent coords, so child coords is
; determined with respect to the parent.
; Only one parent is allowed for a child.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass cascaded-coords 
	  :super coordinates
	  :slots  (parent descendants worldcoords manager changed))


(defmethod cascaded-coords 
 (:parent () parent)
 (:descendants () descendants)
 (:inheritance ()
    (mapcar
	#'(lambda (child) (cons child (send child :inheritance)))
	descendants))
 (:leaves ()
    (if descendants 
	(flatten (send-all descendants :leaves))
	self))
 (:assoc (child &optional c)
    (unless (memq child descendants) 	;already assoc'ed?
	(unless c 
		(setq c  (send (send self :worldcoords) :transformation
			       (send child :worldcoords))))
	(send child :obey self)
	(send child :newcoords
		    (coordinates-rot c) (coordinates-pos c))
	(push child descendants)
	child))
 (:dissoc (child)
    (when (memq child descendants)
	(let ((c (send (send child :worldcoords) :copy-coords)))
	   (setq descendants (delete child descendants))
	   (send child :disobey self)
	   (send child :newcoords (coordinates-rot c) (coordinates-pos c))
	   child)))
 (:clear-assoc ()	;remove all the association
    (dolist (d descendants) (send self :dissoc d))
    nil)
 (:obey (mother)	;only for internal use
    (if parent (send parent :dissoc self))
    (setf parent mother))
 (:disobey (mother)	;only for internal use
    (if (eq mother parent) (setq parent nil))
    parent)
 (:newcoords  (c &optional p)
    (send-super :newcoords c p)
    (send self :changed)
    self)
 (:changed ()
    (unless changed		;Is this the first change?
	(setf changed t)	;Then, propagate changed signal.
	(send-all descendants :changed)))
 (:worldrot () (coordinates-rot (send self :worldcoords)))
 (:worldpos () (coordinates-pos (send self :worldcoords)))
 (:worldcoords  ()	;calculate rot and pos in the world
   (when changed
      (if parent
	  (transform-coords (send parent :worldcoords) self worldcoords)
	  (send worldcoords :replace-coords self))
      (send self :update)
      (setf changed nil))
   worldcoords)
 (:copy-worldcoords (&optional
			(dest (instance coordinates :create (length pos))))
     (send self :worldcoords)
     (replace (coordinates-pos dest) (coordinates-pos worldcoords))
     (replace-matrix (coordinates-rot dest) (coordinates-rot worldcoords))
     dest)
 (:update () )
 (:parentcoords ()
    (if parent
        (send parent :worldcoords)
	(case (send self :dimension)
	  (3 *world-coords*)
	  (2 *world-coords2*)
	  (t (error "dimension?"))) ))
 (:transform-vector (v)
   (send (send self :worldcoords) :transform-vector v))
 (:rotate-vector (v) 
   (send (send self :worldcoords) :rotate-vector v))
 (:inverse-transform-vector  (v)
  (send (send self :worldcoords) :inverse-transform-vector v))
 (:inverse-transformation  (&optional (dest (instance coordinates :create))) 
  (send (send self :worldcoords) :inverse-transformation dest))
 (:transformation (c2 &optional (wrt :local))
   (let* ((w2 (send c2 :worldcoords))
	  (w1 (send self :worldcoords))
	  (w1inv (send w1 :inverse-transformation))
	  (c1inv) (xw))
      (cond
        ((or (memq wrt '(:local local)) (eq wrt self))
	 (transform-coords w1inv w2 w1inv))
	((or (memq wrt '(:parent parent)) (eq wrt parent))	;nil?
	 (setq c1inv (send-super :inverse-transformation))
	 (transform-coords w2 c1inv c1inv)
	 (transform-coords w1inv c1inv c1inv)
	 (transform-coords self c1inv c1inv))
	((or (memq wrt '(world :world))  (equal wrt *world-coords*))
	 (transform-coords w2 w1inv w1inv))
        ((coordinates-p wrt)
	 (setq xw (send wrt :worldcoords))
	 (transform-coords w1inv xw w1inv)
	 (transform-coords w2 w1inv w1inv)
	 (transform-coords (send xw :inverse-transformation) w1inv w1inv))
      (t (send self :error ":transform wrt?" wrt)))))
 (:transform  (c &optional (wrt :local))
   (cond
    ((or (memq wrt '(:local local)) (eq wrt self))	;multiply c from the right
	(transform-coords self c self))
    ((or (memq wrt '(:parent parent)) (eq wrt parent))	;nil?
	(transform-coords c self self))	;;multiply c from the left
    ((or (memq wrt '(world :world))  (equal wrt *world-coords*))
	(let ((pc (send self :parentcoords)))
	   (transform-coords pc self self)
	   (transform-coords c self self)
	   (transform-coords (send pc :inverse-transformation) self self)))
    ((coordinates-p wrt)
	(let ((pc (send self :parentcoords)))
	   (transform-coords pc self self)
	   (transform-coords (send wrt :inverse-transformation) self self)
	   (transform-coords c self self)
	   (transform-coords (send wrt :worldcoords) self self)
	   (transform-coords (send pc :inverse-transformation) self self)))
    (t (send self :error ":transform wrt?" wrt)))
   (send self :newcoords rot pos))
 (:move-to (c &optional (wrt :local) &aux cc)
     (unless (coordinates-p c) (error "coordinates expected for :move-to"))
     (cond ((or (memq wrt '(:local local)) (eq wrt self))
	    (setq cc (transform-coords self c))
	    (send self :newcoords cc))
	   ((or (memq wrt '(:parent parent)) (eq wrt parent))
	    (send self :newcoords c))
	   ((or (memq wrt '(:world world)) (equal wrt *world-coords*))
	    (setq cc (transform-coords
			(send (send self :parentcoords)
				:inverse-transformation) c))
	    (send self :newcoords cc))
	   ((coordinates-p wrt)
	    (setq cc (transform-coords (send wrt :worldcoords) c))
	    (transform-coords (send (send self :parentcoords)
				    :inverse-transformation) cc cc)
	    (send self :newcoords cc))))
 (:rotate-with-matrix (mat wrt)   ;only for internal use
    (cond ((or (memq wrt '(:local local)) (eq wrt self))
	   (m* rot mat rot)
	   (send self :newcoords rot pos))
	  ((or (memq wrt '(:parent parent)) (eq wrt parent))
	   (m* mat rot rot)
	   (send self :newcoords rot pos))
	  (t
	      (let* ((wrtrot)
		     (pc (send self :parentcoords))
		     (pr (coordinates-rot pc)))
		(when (coordinates-p wrt)
		    (setq wrtrot (send wrt :worldrot))
		    (setq mat (m* wrtrot mat))
		    (m* mat (transpose wrtrot) mat))
	        (m* mat pr mat)
	        (m* (transpose pr) mat mat) 
	        (m* mat rot rot)
		(send self :newcoords rot pos)))))
  (:rotate (theta axis &optional (wrt :local))
    (cond ((= (length pos) 2)
	   (send-super :rotate theta axis))
    	  ((float-vector-p axis)
	   (send self :rotate-with-matrix (rotation-matrix theta axis) wrt))
	  ((matrixp theta)
	   (send self :rotate-with-matrix theta wrt))
	  (t (cond	;axis is given as an axis-symbol like :x, :y and :z
		((or (memq wrt '(local :local)) (eq wrt self))
		 (rotate-matrix rot theta axis nil rot)
		 (send self :newcoords rot pos))
		((or (memq wrt '(parent :parent)) (eq wrt parent))
		 (rotate-matrix rot theta axis t rot)
		 (send self :newcoords rot pos))
		(t
		 (send self :rotate-with-matrix
			    (rotation-matrix theta axis) wrt))))))
 (:orient-with-matrix (mat wrt)   ;only for internal use
    (cond ((or (memq wrt '(:local local)) (eq wrt self))
	   (m* rot mat rot)
	   (send self :newcoords rot pos))
	  ((or (memq wrt '(parent :parent)) (eq wrt parent))
	   (setf rot mat)
	   (send self :newcoords rot pos))
	  (t
	      (let* ((wrtrot)
		     (pc (send self :parentcoords))
		     (pr (coordinates-rot pc)))
		(when (coordinates-p wrt)
		      (setf wrtrot  (send wrt :worldrot))
		      (setf mat (m* wrtrot mat)))
	        (m* (transpose pr) mat rot) 
		(send self :newcoords rot pos)))))
  (:orient (theta axis &optional (wrt :local))
    (cond ((float-vector-p axis)
	   (send self :orient-with-matrix (rotation-matrix theta axis) wrt))
	  ((matrixp theta)
	   (send self :orient-with-matrix theta wrt))
	  (t (cond	;axis is given as an axis-symbol like :x, :y and :z
		((or (memq wrt '(:local local)) (eq wrt self))
		 (rotate-matrix rot theta axis nil rot)
		 (send self :newcoords rot pos))
		((or (memq wrt '(parent :parent)) (eq wrt parent))
		 (setf rot (rotation-matrix theta axis))
		 (send self :newcoords rot pos))
		(t
		 (send self :orient-with-matrix
			    (rotation-matrix theta axis) wrt))))))
 (:parent-vector (v wrt)
   (cond ((or (memq wrt '(:local local)) (eq wrt self)) (send-super :transform-vector v))
	 ((or (memq wrt '(:parent parent)) (eq wrt parent)) v)
	 (t
	  (if (coordinates-p wrt)  (setq v (send wrt :transform-vector v)))
	  (if parent
	      (send parent :inverse-transform-vector v)
	      v))))
 (:parent-orientation (v wrt)
   (cond ((or (memq wrt '(:local local)) (eq wrt self)) (transform rot v))
	 ((or (memq wrt '(:parent parent)) (eq wrt parent)) v)
	 (t
	  (if (coordinates-p wrt)
	      (setq v (transform (send wrt :worldrot) v)))
	  (if parent
	      (transform (transpose (send parent :worldrot)) v)
	      v))))
 (:manager (&optional m)
    (if m (setq manager  m))
    manager)
 (:init (&rest initargs &key ((:parent par)) at &allow-other-keys)
    (send-super* :init initargs)
    (setf manager self
	  changed t	;safer
	  worldcoords	;prepare a world-coordinates holder
          ;; avoid to use copy-object, see https://sourceforge.net/p/jskeus/tickets/28/
	  (instance coordinates :init :rot (copy-matrix rot) ; (copy-object rot)
				      :pos (copy-seq pos)    ; (copy-object pos)
                                      ))
    (if par (send par :assoc self at)) 
    self)
)
;;; Cancatenation of coordinates
;;; C2 is transformed by c1 from the left and the result is stored
;;; in the optional third argument.
;;; Efficiency effective.

(defun transform-coords (c1 c2 &optional
			       (c3 (let ((dim (send c1 :dimension)))
				      (instance coordinates 
					   :newcoords (unit-matrix dim)
						(instantiate float-vector dim)))))
   (if (eq c1 c3)
       (v+ (coordinates-pos c1)
           (transform (coordinates-rot c1) (coordinates-pos c2))
           (coordinates-pos c3))
       (v+ (coordinates-pos c1)
           (transform (coordinates-rot c1) (coordinates-pos c2) (coordinates-pos c3))
           (coordinates-pos c3)))
   (m* (coordinates-rot c1) (coordinates-rot c2) (coordinates-rot c3))
   c3)

(defun transform-coords* (c1 c2 &rest clist &aux cresult)
   (setq cresult (transform-coords c1 c2))
   (dolist (c clist)
        (transform-coords cresult c cresult))
   cresult)

(defun transform-vector (trans vec)
   (declare (coordinates trans))
   (v+ (transform (coordinates-rot trans) vec) (coordinates-pos trans)))

(defun make-coords (&rest initargs)
    (send* (instantiate coordinates) :init initargs))
(defun make-cascoords (&rest initargs)
    (send* (instantiate cascaded-coords) :init initargs))
(defun coords (&rest initargs)
    (send* (instantiate coordinates) :init initargs))
;(defun trans (&rest initargs)
;    (send* (instantiate coordinates) :init initargs))
(defun cascoords (&rest initargs)
    (send* (instantiate cascaded-coords) :init initargs))
(defun wrt (coords vec)
    (send coords :transform-vector vec))
(eval-when (load eval)
  (defconstant *world-coords*
	 (instance coordinates :init :name '*world-coords*))
  (defconstant *world-coords2*
	 (instance coordinates :init :dimension 2 :name '*world-coords2*))
)
(defun coordinates-distance (c1 c2 &aux (c (send c1 :transformation c2)))
     (list (norm (send c :worldpos))
	   (car (rotation-angle (send c :worldrot)))))

(provide :coordinates 
	"@(#)$Id$")
