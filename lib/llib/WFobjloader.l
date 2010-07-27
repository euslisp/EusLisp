;;;; WFobjloader.l
;;;; Wavefront object file loader
;;;; (c) 2003 Toshihiro Matsui, AIST, Japan
;;;

(setq *obj-readtable* (copy-readtable))
(set-macro-character #\# nil nil *obj-readtable*)
(set-syntax-from-char #\# #\a *obj-readtable*)

;; array of vertices
;; element=(#f(x y z) #<edge ...> #<edge ...> )
(defvar obj-vertices)
(defvar obj-faces)

(defun matching-edge (edges p1 p2)
   (dolist (e edges)
      (let ((pv (geo::edge-pvert e)) (nv (geo::edge-nvert e)))
	(if (or (and (eql p1 pv) (eql p2 nv))
		(and (eql p2 pv) (eql p1 nv)))
	    (return-from matching-edge e)))))

(defun find-or-create-edge (p1 p2 newface)
   (let ((v1 (aref obj-vertices p1)) (v2 (aref obj-vertices p2))
	 (theEdge))
      (setq theEdge (matching-edge (rest v1) (first v1) (first v2)))
      (unless theEdge
	(setq theEdge (instance geo:edge :init
				:pvertex (first v1) :nvertex (first v2)))
	(setf (aref obj-vertices p1)
		 (list* (first v1) theEdge (rest v1)))
	(setf (aref obj-vertices p2)
		 (list* (first v2) theEdge (rest v2))) )
      (send theEdge :set-face (first v1) (first v2) newface)
      theEdge))

(defun read-vertex (file)
   (let (x y z)
     (setq x (read file) y (read file) z (read file))
     (vector-push-extend (list (float-vector x y z)) obj-vertices)
     ;; (format t "vertex ~d~%" (array-fill-pointer obj-vertices))
     )
   )

(defun read-face (file)
   (let ((p) (points) (points-x) (p1) (p2) (e) (edges) (newface))
	;;
      (while (not (eql (setq p (read file nil nil)) nil))
	(push p points))
      (setq points (cons (car points) (nreverse points)))
      (setq points-x points)	
      (setq newface (instantiate face))
      (while (cdr points-x)
	(setq p1 (pop points-x) p2 (car points-x))
	;; find edge
	(setq e (find-or-create-edge p1 p2 newface))
	(push e edges))
      (send newface :init :edges (nreverse edges))
      (vector-push-extend newface obj-faces)
      (format t "face ~d~%" (array-fill-pointer obj-faces))
      )	
  ) 

(defun read-group-name (file)
   (format t "group=~s~%" (read file)))
 
(defun read-comment (file) nil)

;;;


(defun obj-loader (file)
  (setq obj-vertices (make-array '(1) :fill-pointer 1))
  (setq obj-faces (make-array '(1) :fill-pointer 1))
  (with-open-file (objfile file)
      (let ((line) (token) (eof (cons nil nil))
	    (f (make-string-input-stream ""))
	    (running t) 
	    (*readtable* *obj-readtable*))
	(while running
	 (setq line (read-line objfile nil eof))
;;	 (print line)
	 (if (eql line eof) (return-from obj-loader nil))
	 (send f :init :input line)
         (setq token (read f nil eof))
	 (case token
	   (v	(read-vertex f))
	   ((vt vn vp) (read-special-vertex token f))
	   ((deg) (read-degree f))
	   (bmat (read-basis-matrix f))
	   (step (read-step-size f))
	   (cstype (read-curve-surface-type f))
	   (p (read-point f))
	   (L (read-obj-line f))
	   (curv (read-curve f))
	   (curv2 (read-2d-curve f))
	   (surf (read-surface f))
	   (f	(read-face f))
	   (parm (read-parameter-values f))
	   (trim (read-outer-trimming-loop f))
	   (hole (read-innter-trimming-loop f))
	   (scrv (read-special-curve f))
	   (sp (read-special-point f))
	   (end (setq running nil))
	   (|#| (read-comment f))
	   (con (read-connect f))
	   (g (read-group-name f))
	   (s (read-smoothing-group f))
	   (mg (read-merging-group f))
	   (o (read-object-name f))
	   (bevel (read-bevel-interpolation f))
	   (c_interp (read-color-interpolatoin f))
	   (d_interp (read-dissolve-interpolation f))
	   (lod (read-level-of-detail f))
	   (usemtl (read-material-name f))
	   (mtllib (read-material-library f))
	   (shadow_obj (read-shadow-casting f))
	   (trace_obj (read-ray-tracing f))
	   (ctech (read-curve-approx-technique f))
	   (stech (read-surface-approx-technique f))
	   (eof (warn "eof hit in WF obj file") (setq running nil))
	   (default (error "unknown obj data")) )
;;
	(sys:reclaim line)
        ) ;while
      )
   ) )

;;;
;; utility functions

(defun obj-statistics ()
   (format t "number of vertices: ~d~%" (length obj-vertices))
   (format t "number of faces: ~d~%" (length obj-faces))
   (format t "average edges at a vertex: ~f~%"
	(/ (apply #'+ (mapcar #'length (map cons #'rest obj-vertices)))
	   (length obj-vertices))
	))

