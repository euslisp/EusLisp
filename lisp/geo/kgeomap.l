;;; geo.l
;;;	ugeomap rpc interface
;;;	1987-Feb,Mar	by T.Matsui
;;;

(defvar *geomap-pipe* nil)
(defvar *geomap-id* 0)
(defun kgeomap (&optional (gt "/dev/tty"))
  (let (version)
    (warn "creating ugeomap process ")
    (setq *geomap-pipe* (sys:piped-fork "ugeomap" gt))
    (setq version (read *geomap-pipe*))
    (command "cinit 9600")
    version))

(defun sendwords (words)
   (dolist (w words)
	(princ w *geomap-pipe*) (princ " " *geomap-pipe*)))

(defun command (&rest c)
   (while c
      (princ (pop c) *geomap-pipe*)
      (princ " " *geomap-pipe*))
   (terpri *geomap-pipe*)
   (read *geomap-pipe*))
;;
;; control functions
;;

(defun cinit (&optional (baud 9600)) (command "cinit" baud))
(defun cterm () (command "cterm"))
(defun clist () (command "clist"))

;;
;; file operation
;;
(defun fsave (file-no) (command "fsave" file-no))
(defun fload (file-no) (command "fload" file-no))

;;
;; primitive/body creation and copy/delete
;;

(defun pcube (name a b c &key (center (float-vector 0 0 0)))
   (command
	"pcube" (elt center 0) (elt center 1) (elt center 2)
		 a b c name (inc *geomap-id*)))

(defun pcyl (name 
		    &key  (radius 1.0)
			  (bottom-radius radius)
			  (top-radius radius)
			  (height 1.0)
			  (center (float-vector 0 0 0))
			  (normal #f(0 0 0))
			  (facets 16))
   (command
	"pcyl" 0 facets bottom-radius top-radius 0 0 0 height
		 (elt normal 0) (elt normal 1) (elt normal 2)
		 (elt center 0) (elt center 1) (elt center 2)
		 name (inc *geomap-id*)))

(defun pgcyl (name 
		     &key (points '((0 0 0) (1 0 0) (1 1 0) (0 1 0)))
			  (height 1.0)
			  (radius 1.0)
	       		  (bottom-radius radius)
			  (top-radius    radius)
			  (center     #f(0 0 0))
			  (top-center center))
   (sendwords (list "pgcyl" (length points) bottom-radius top-radius 0))
   (dolist (v points) (sendwords v))
   (sendwords (list 0 0 height 0 0 0
			   (elt top-center 0) (elt top-center 1) (elt top-center 2)))
   (command name (inc *geomap-id*)))

(defun prvl (name 
		    &key (points '((0 0 0) (1 0 0) (1 1 0) (0 1 0)))
			 (center (float-vector 0 0 0))
			 (facets 16))
   (sendwords (list "prvl" (length points)))
   (dolist (v points) (sendwords v))
   (sendwords (list facets 0 0 0
			   (elt center 0) (elt center 1) (elt center 2)))
   (command name (inc *geomap-id*)))

(defun fcopy (name1 name2)
   (command "fcopy" name1 name2))

(defun fdel (name) (command "fdel" name))

;;
;; camera
;;
(defun dcam (name &key (viewpoint #f(100 100 100))
			      (target #f(0 0 0))
			      (width 0))
   (let ((viewline (v- viewpoint target))
         (k (if (= width 0) 11 15)))
      (command "dcam" k
		      (elt viewpoint 0) (elt viewpoint 1) (elt viewpoint 2)
		      1 (elt viewline 0) (elt viewline 1) (elt viewline 2)
		      width 4000 name)
      (command "dscam" name) )
      )

;;
;; display
;;
(defun hhid (name &optional (camera 0) (image 0) (k 0) (i 1))
    (command "hid" name camera 4 k 0 i 0 image ))

;;
;; set operation
;;

(defun mtst (name1 name2)
    (command "mtst" name1 name2))
(defun mint (name1 name2 name)
    (command "mint" name1 name2 name  (inc *geomap-id*)))
(defun msub (name1 name2 name)
    (command "msub" name1 name2 name  (inc *geomap-id*)))
(defun muni (name1 name2 name)
    (command "muni" name1 name2 name  (inc *geomap-id*)))

;;
;; relation between bodies
;;

(defun eatr (name1 name2) (command "eatr" name1 name2))
(defun edtr (name) (command "edtr" name))
(defun eagr (name1 name2) (command "eagr" name1 name2))
(defun edgr (name1 name2) (command "edgr" name1 name2))

;;
;; modelling transformation
;;

(defun grot (name axis theta
			 &optional (rname 0) (k 0) (itr 0)
				   (v (float-vector 0 0 0)))
      (command "grot" name rname 1
		 (elt axis 0) (elt axis 1) (elt axis 2)	; rotation axis
		 (rad2deg theta)		;rotation angle
		 (elt v 0) (elt v 1) (elt v 2)	; center of rotation
		 k itr))

(defun euler (name alfa beta gamma
			  &optional (rname 0) (k 1) (itr 0)
				    (v (float-vector 0 0 0)))
      (command "grot" name rname 0
		 (rad2deg alfa)		; rotation angle z
		 (rad2deg beta)		; rot angle y
		 (rad2deg gamma)		; rot angle x
		 (elt v 0) (elt v 1) (elt v 2)	; center of rotation
		 k itr))

(defun gtrns (name v &optional (rname 0) (k 1) (m 1))
    (command "gtrns" name rname (elt v 0) (elt v 1) (elt v 2) k m))

(defun gmgnf (name scale &optional (center #f(0 0 0)) (m 1))
    (command "gmgnf" name scale
			    (elt center 0) (elt center 1) (elt center 2)
			    m))

(defun trans-abs-body (name v &optional (tree 1))
    (gtrns name v 0 1 tree))

(defun trans-abs-body-coord (name v &optional (tree 1))
   (gtrns name v 0 0 tree))

(defun rot-abs-euler-body (name ang1 ang2 ang3 &optional (tree 1))
  (euler name ang1 ang2 ang3 0 1 tree)
)

(defun rot-abs-euler-body-coord (name ang1 ang2 ang3 &optional (tree 1))
  (euler name ang1 ang2 ang3 0 0 tree)
)

;;
;; access to geomap cells
;;

(defun cellid (name) (command "cellid" name))
(defun getcell (i) (command "getcell" i))

(defun vertices (vlist)
   (apply #'command "vertices" (length vlist) vlist))


;;;
;;; functions to read data structures from solver process
;;; Objects are first linked from a vector *solver-cells*,
;;; which is then accessed to solve mutual references.
;;;

(defconstant *solver-max-cell* 8192)
(defvar *solver-cells* (make-array *solver-max-cell*))

(defun build-edge (e)
   (let ((gcell (getcell e)))
      (setq e (elt *solver-cells* (/ e 8)))
      (send e :init
		:pface	 (elt *solver-cells* (/ (elt gcell 2) 8))
		:nface   (elt *solver-cells* (/ (elt gcell 3) 8))
		:pvertex (elt *solver-cells* (/ (elt gcell 4) 8))
		:nvertex (elt *solver-cells* (/ (elt gcell 5) 8))
;		:pwing   (elt *solver-cells* (/ (elt gcell 6) 8))
;		:pcwing  (elt *solver-cells* (/ (elt gcell 7) 8))
;		:nwing   (elt *solver-cells* (/ (elt gcell 8) 8))
;		:ncwing  (elt *solver-cells* (/ (elt gcell 9) 8))
		)))

(defun build-face (f)
   (let ((gcell (getcell f)) (edges) (holes) (hole-list) (hole-edges)
	 (normal) (dist))
      (setq f (elt *solver-cells* (/ f 8)))
      (setq normal (float-vector (elt gcell 2) (elt gcell 3) (elt gcell 4)))
      (setq dist (elt gcell 5))
      (setq edges (mapcar #'(lambda (e) (svref *solver-cells* (/ e 8)))
		          (car (elt gcell 6))))
      (setq hole-list (cdr (elt gcell 6)))
      (dolist (h hole-list)
	 (setq hole-edges  (mapcar #'(lambda (e) (svref *solver-cells* (/ e 8)))
				   h))
;	 (setq *h* hole-edges *f* f)
	 (push (instance hole :init
;			 :normal	normal
;			 :distance	dist
			 :edges		hole-edges
			 :face f )
		holes))
       (send f :init :normal normal
		     :distance dist
		     :edges edges
		     :holes holes
		     )))

(defun read-body (bod &optional (init nil))
   (let ((i 0) (abody) faces edges vertices)
      (if init
        (dotimes (i *solver-max-cell*) (svset *solver-cells* i nil)))
      (if (not (numberp bod)) (setq bod (cellid bod)))
      (setq abody (getcell bod))
      (setq faces (nth 3 abody)
	    edges (nth 4 abody)
	    vertices (nth 5 abody))
      (warn "reading vertices~%")
      (dolist (v vertices)
	      (svset *solver-cells* (/ v 8) (caddr (getcell v))))
      (warn "reading edges~%")
      (dolist (e edges)
	      (svset *solver-cells* (/ e 8) (instantiate edge)))
      (warn "reading faces~%")
      (dolist (f faces)
	      (svset *solver-cells* (/ f 8) (instantiate face)))
      ;
      (warn "building edges~%")
      (dolist (e edges) (build-edge e))
      (warn "building faces~%")
      (dolist (f faces) (build-face  f))
      (warn "computing face angles~%")
      (dolist (e edges) (send (svref *solver-cells* (/ e 8)) :set-angle))
; make body 
      (setq abody (instantiate body))
      (send abody :init 
		  :faces (mapcar 
			     #'(lambda (i) (svref *solver-cells* (/ i 8)))
			     faces)
		  :edges (mapcar
			     #'(lambda (i) (svref *solver-cells* (/ i 8)))
			     edges)
		  :vertices (mapcar
			     #'(lambda (i) (svref *solver-cells* (/ i 8)))
			     vertices))
      abody
      ))


