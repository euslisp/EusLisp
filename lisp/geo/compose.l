;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; body composition -- boolean operation between bodies
;;;	Copyright (1988) Toshihiro MATSUI, Electrotechnical Laboratory
;;;	1988-Feb
;;;	Union, intersection, subtraction and cut of bodies
;;;	All operations are unstable when elements of bodies are touching.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;	Nov/1991 (one week)
;;;		Modification to allow bodies to touch on thier faces
;;;

(in-package "GEOMETRY")
(export '(cut-body compose-body 
	body+ body* body- body-interference semi-space body/))

(export '(contacting-faces aligned-faces))

(eval-when (compile) (load "geoclasses.l") )

(defvar  *body*)
(defvar  *bodies*)
(defvar  *faces*)
(defvar  *edges*)
(defvar  *edge-class*)
(defvar  *face-class*)
(defvar  *hole-class*)
(defvar  *body-class*)

;;;
;;;  cut body by plane
;;;

(defun intersecting-edges (pln edges)
   (let ((ie) (p))
      (declare (type float p))
      (dolist (e edges)
	 (setq p (send pln :intersect-edge e))
	 (if (and p (<= 0.0 (car p) 1.0)) (push (cons e p) ie)))
      ie))

(defun cut-body (bod cutting-plane)
  (let ((fac-intersects) (edg-intersects)
        (sort-index) (sort-dir)
	(created-edges) 
	(aface)  (face-list) )
    (setq edg-intersects (intersecting-edges cutting-plane (send bod :edges)))
    (setq fac-intersects (sort-edges-by-face edg-intersects))
    (dolist (fint fac-intersects)
	(when (oddp (length (cdr fint)))   (error "odd intersects"))
	(setq aface (car fint)
	      edg-intersects (cdr fint))
	(setq sort-dir (v* (send aface :normal) (send cutting-plane :normal))
	      sort-index (maxindex sort-dir)
	      edg-intersects  (sort edg-intersects
				   (if (> (aref sort-dir sort-index) 0.0)
					#'> #'<)
				   #'(lambda (e) (aref (caddr e) sort-index))))
	(while edg-intersects
	    (push (instance *edge-class* :init
			 :pvertex (caddr (car edg-intersects))
			 :nvertex (caddr (cadr edg-intersects))
			 :pface   cutting-plane
			 :nface   aface)
		  created-edges)
	    (setq edg-intersects (cddr edg-intersects))) )
    (construct-faces (cons cutting-plane  created-edges)) ))


(defun insert-intersections (intlists faces common-box)
  (flet ((put-face (e int f)
	    (if (null (cddr int))
		(nconc int (list f))
		(let ((edir (send e :direction)))
		   (if  (> (abs (v. edir (send f :normal)))
			   (abs (v. edir (send (caddr int) :normal))))
			(rplaca (cddr int) f) )))))
   (let (p param pplist)
     (dolist (aface faces)
	(if (send (send aface :box 0.01) :intersection-p common-box)
	    (dolist (ie intlists intlists)
		(setq p (send aface :intersect-edge (car ie)))
		(when  (and  (consp p)
			     (null (send aface :coplanar-line (car ie))))
		   (setq param (car p)
		   	 pplist (cdr ie))
		   (while pplist 
		     (cond ((eps= (caar pplist) param)
			    (put-face (car ie) (car pplist) aface)
			    (return nil))
			   ((< (caar pplist) param)
			    (if (eps= (caar pplist) 1.0)
				(progn 
				   (put-face (car ie) (car pplist) aface)
				   (return nil))
			        (pop pplist)))
			   ((> (caar pplist) param)
			    (rplacd pplist (cons (car pplist) (cdr pplist)))
			    (rplaca pplist (nconc p (list aface)) ) 
			    (return nil)) ))
		) ) )
   )) ) )

(defun make-edge-segments (intersects target-body side)
   (let ((created-edges) (new-edge)
	 (mid (float-vector 0 0 0))
	 p1 p2  flag original-edge
	 cutting-face1 cutting-face2)
      (dolist (intlist intersects)
	 ;intlist=(edge (param1 point1 ..) (param2 point2 ...))
	;; (rplacd intlist (sort (cdr intlist) #'< #'car))
	 (setq original-edge (pop intlist))
	 (while (cdr intlist)
	    (setq p1 (pop intlist) p2  (car intlist))
	    (midpoint 0.5 (cadr p1) (cadr p2) mid)
	    (setq flag (send target-body :insidep mid))
	    (setq cutting-face1 (third p1)
		  cutting-face2 (third p2))
	    (when (or (eq flag side) (eq flag ':border))
		(setq new-edge
 		      (instance *edge-class* :init
			      :pvertex (cadr p1)
			      :nvertex (cadr p2)
			      :pface (edge-pface original-edge)
			      :nface (edge-nface original-edge)
			      :flags (edge-flags original-edge)) )
		(push (list original-edge	;1
			    new-edge		;2
			    (caddr p1)		;3 segmenting face
			    (caddr p2)		;4 on both ends
			    flag		;5
			    (car p1)		;6
			    (car p2))		;7
		      created-edges)
		)
	))
      created-edges))


(defun intersecting-segments (segments)
   ;collect segments which have intersections with other faces
   (mapcan
      #'(lambda (s)
	   (if (and (or (third s) (fourth s))
		    (not (eq (fifth s) ':border)))
		(list s))) segments))

(defun sort-edges-by-face (intlist)
    (let* (flist fentry aface e)
      (dolist (int intlist)
	 (setq e (car int)	;original edge
	       fentry (assq (edge-pface e) flist))
	 (if (null fentry)
	     (push (list (edge-pface e) int) flist)
	     (nconc fentry (list int)))
	 (setq fentry (assq (edge-nface e) flist))
	 (if (null fentry)
	     (push (list (edge-nface e) int) flist)
	     (nconc fentry (list int))))
     flist))

(defun make-crossing-edges (intfaces1 intfaces2 first side)
   (let* (f1 f2s ints1 ints2  ex v sort-index sort-func
	  vlist vlist1 vlist2 pv nv f1normal
	  created-edges crossing-edges1 crossing-edges2)
      (dolist (ifac intfaces1)
	(unless (consp ifac) (error "ifac not list ~s" ifac))
	(setq f1 (car ifac)
	      ints1 (cdr ifac)
	      f1normal (send f1 :normal))
        (setq f2s nil)
	(dolist (ix ints1)	;collect faces with which f1 intersects
	   (unless (consp ix) (error "ifac not list ~s" ix))
	   (if (and (third ix)
		    (null (member (third ix) f2s)))
	       (push (third ix) f2s))
	   (if (and (fourth ix)
		    (null (member (fourth ix) f2s)) )
	       (push (fourth ix) f2s)))
	;; edges of f1 intersect with faces in f2s
	(dolist (f2 f2s)
	   (setq vlist1 nil
	         vlist2 nil)
	   (dolist (i1 ints1)
		;find points where edges of f1 intersects with f2
		(setq ex (cadr i1))	;car is the original edge
		(cond ((and (eq (third i1) f2)
;			    (not (send f2 :on-vertex (line-pvert ex)))
			    (eps<> (sixth i1) 0.0))
			(push (line-pvert ex) vlist1))
		      ((and (eq (fourth i1) f2)
;			    (not (send f2 :on-vertex (line-nvert ex)))
			    (eps<>  (seventh i1) 1.0))
			 (push (line-nvert ex) vlist1)) ))
	   (dolist (i2 (cdr (assq f2 intfaces2)))
		;find points where edges of f2 intersects with f1
		(setq ex (cadr i2))
		(cond ((and (eq (third i2) f1)
;			    (not (send f1 :on-vertex (line-pvert ex)))
			    (eps<> (sixth i2) 0.0))
			(push (line-pvert ex) vlist2))
		      ((and (eq (fourth i2) f1)
;			    (not (send f1 :on-vertex (line-nvert ex)))
			    (eps<>  (seventh i2) 1.0))
			(push (line-nvert ex) vlist2)))) 
  	   ; all vertices have been collected for f1 and f2
	   ; sort them along the intersection line
	   (setq v (v* (f2 . normal) (f1 . normal))
		 sort-index  (maxindex v)
		 sort-func   (if (eq side ':outside)
				 (if (< (aref v sort-index) 0.0) #'>= #'<=)
				 (if (< (aref v sort-index) 0.0) #'<= #'>=)))
	   (setq vlist (sort (append vlist1 vlist2)
			     sort-func
			     #'(lambda (vv) (elt vv sort-index))))
	  (setq vlist (remove-duplicates vlist :test #'eps-v=))
	;;  (break "vlist: ")
	;;;	SIMPLER
	;;;	   (setq vlist
	;;;		 (sort (append vlist1 vlist2)
	;;;		       #'<=
	;;;		       #'(lambda (vv)(v. vv v))) )
	   ; create and collect intersecting edges
	   (setq created-edges nil)
	   (while vlist
	      (setq pv (pop vlist)  nv (pop vlist))
	      (when (and pv nv
			;;  (not (eps-v= pv nv))
			 (not (send f1 :on-edge (midpoint 0.5 pv nv)))
			 (not (send f2 :on-edge (midpoint 0.5 pv nv)))
			 (or first (and (memq pv vlist1) (memq nv vlist1))))
	         (setq ex (instance *edge-class* :init :pvertex pv
					   :nvertex nv
					   :pface f1
					   :nface f2
					   :approximated nil))
		 (push ex created-edges)))
	   (when created-edges
	       (push (cons f1 created-edges) crossing-edges1)
	       (push (cons f2 (copy-seq created-edges)) crossing-edges2))
	   )	;for all intersections with body2
	)	;for all intersecting faces of body1
      (list crossing-edges1 crossing-edges2)))

(defun add-alist (key val alist)
   (let ((s (assq key alist)))
      (if (null s)
	  (acons key val alist)
	  (progn (nconc s val) alist))))

(defun merge-segments (segments s2 s3)
   (dolist (seg segments)  (rplacd seg (mapcar #'cadr (cdr seg))))
   (dolist (s s2) (setq segments (add-alist (car s) (cdr s) segments)))
   (dolist (s s3) (setq segments (add-alist (car s) (cdr s) segments)))
   segments)

(defun find-connecting-edge (vert edges &optional (test #'eq))
   (if (eq test #'eq)
	(find-if
		#'(lambda (e) (or (eq (edge-pvert e) vert) (eq (edge-nvert e) vert)))
		edges)
	(find-if #'(lambda (e) (or (funcall test (edge-pvert e) vert)
				   (funcall (edge-nvert e) vert)))
		edges)) )

(defun construct-faces (fac-edges)
   (setq *bug-edges* (copy-seq fac-edges))
   (let*  ( newfaces holes ahole
	   (oldface (car fac-edges))
	   (edges (cdr fac-edges))
	   )
      (while edges
	(let* ( (xedge (pop edges))
        	(fvertex (send xedge :pvertex oldface))
		(pvertex fvertex) (nvertex)  (circuit)
		(newface (instantiate *face-class*))
		primt-face)
           (while xedge
	      (setq nvertex (send xedge :nvertex oldface))
	      (send xedge :set-face pvertex nvertex newface)
	      (push xedge circuit)
	      (setq edges (delete xedge edges :count 1))
	      (setq xedge (find-connecting-edge nvertex edges)
	      	    pvertex nvertex))
	   (setq circuit (nreverse circuit))
	   (if (find-method oldface :primitive-face)
		(setq primt-face (send oldface :primitive-face)))
	   (send newface :init
			:edges circuit
			:primitive-face primt-face
			:body (if primt-face (send primt-face :body))
			:id (send oldface :id))
	   (cond
	      ((< (v. (send oldface :normal) (send newface :normal)) 0.0)
	       (push (cons newface circuit) holes))
	      (t (push newface newfaces) ) )))
      (when holes
	 (if *debug*
	     (format t ";; faces=~s~%holes=~s~%" newfaces holes))
	 (dolist (circuit holes)
	    (block enter-hole
	       (dolist (f newfaces)
	          (when (eq (send f :insidep ((cadr circuit) . pvert)) ':inside)
		     (dolist (c (cdr circuit))
			  (send c :set-face (send c :pvertex (car circuit))
					    (send c :nvertex (car circuit))
					    f))
		     (setq ahole (instance *hole-class* :init
						:edges (cdr circuit) :face f))
		     (send f :enter-hole ahole)
		     (return-from enter-hole nil)))
	       (setq *bug* (list newfaces holes))
	       (error "outer circuit not found~%"))))
      newfaces))

(defun initial-intersection-list (edges htab &aux res)
    (dolist (e edges res)
     (push 
	(list e
	      (list 0.0 (car (gethash (edge-pvert e) htab)))
	      (list 1.0 (car (gethash (edge-nvert e) htab))))
	res)))

;;
;; make a hashtable for retrieving edges by a vertex
;;

(defun make-vertex-edge-htab (bodfacs)	;body or list of faces
   (let* (edges vertices htab pv nv)
      (cond ((bodyp bodfacs)
		(setq vertices (body-vertices bodfacs)
		      edges (body-edges bodfacs)))
	    (t
	        (setq vertices (remove-duplicates
				  (apply #'append
					 (send-all bodfacs :all-vertices)))
		      edges (remove-duplicates
				  (apply #'append
					 (send-all bodfacs :all-edges))))))
      (setq htab (make-hash-table :size (1+ (* 2 (length vertices)))))
      (dolist (e edges)
	 (setq pv (edge-pvert e)
	       nv (edge-nvert e))
	 (setf (gethash pv htab) (cons e (gethash pv htab)))
	 (setf (gethash nv htab) (cons e (gethash nv htab))))
      htab))

(defun copy-add-vertex (htab)
   (maphash #'(lambda (k v) (setf (gethash k htab) (cons (copy-seq k) v)))
	   htab))
   
;;
;; Find contacting faces

(defun find-colinear-int (conint)
   (let (colinears)
      (dolist (con conint)
	 (dolist (c (cdr con))
	   (if (eql (cadr c) 'colinear)
		(push (list* (car con) c) colinears))))
      colinears))

(defun contacting-faces (body1 body2)
   (let* ((faces1 body1)
          (faces2 body2)
	  (con) (con2) (colinear-int)
          (result)
	  (edges1) (edges2))
      (if (derivedp body1 body)
	  (setq faces1 (body-faces body1)) )
      (if (derivedp body2 body)
	  (setq faces2 (body-faces body2)) )
    (dolist (f1 faces1)
      (dolist (f2 faces2)
        (when (setq con (send f1 :contactp  f2))
	  (setq edges1 (mapcar #'car con))
	  (setq edges2
		 (remove-duplicates
			(mapcar #'car (apply #'append (mapcar #'cdr con)))))
	  (cond ((memq con '(:included :including))
		  (push (list f1 f2 con) result))
		 ((or (= (length edges1) 1)     (= (length edges2) 1))
		  (setq colinear-int (find-colinear-int con))
		  (if (= (length colinear-int) 1)
		      (progn
			(format t ";; testing edge-edge contact~%")
			(setq colinear-int (car colinear-int))
		        (cond ((and (eps= (first (fourth colinear-int)) 0.0)
			            (eps= (second (fourth colinear-int)) 1.0)
				    (eql (send f2 :insidep
					       (send (first colinear-int)
						     :next-vertex f1))
					 ':inside) )
			        (push (list* f1 f2 con) result)	)
			       ((and (eps= (first (fifth colinear-int)) 0.0)
				     (eps= (second (fifth colinear-int)) 1.0)
				     (eql  (send f1 :insidep
					        (send (second colinear-int)
							:next-vertex f2))
					  ':inside))
			        (push (list* f1 f2 con) result)	)
				)) ;progn
			(push (list* f1 f2 con) result)) ;if
			)
		(t (push (list* f1 f2 con) result)) )
          ) ;when 
    ))	; dolist, dolist
    result))

(defun aligned-faces (body1 body2)
   (let* ((faces1 body1)
          (faces2 body2)
	  (algn) (algn2) (result)
	  (edges1) (edges2))
      (if (derivedp body1 body)
	  (setq faces1 (body-faces body1)) )
      (if (derivedp body2 body)
	  (setq faces2 (body-faces body2)))
      (dolist (f1 faces1)
        (dolist (f2 faces2)
	   (setq algn (send f1 :aligned-plane f2))
	   (if algn (push (list f1 f2) result))))
      result))


(defun find-equivalent-edge (e1 edges2)
   (dolist (e2 edges2)
      (if (or (and (eps-v= (line-pvert e1) (line-pvert e2))
		   (eps-v= (line-nvert e1) (line-nvert e2)))
	      (and (eps-v= (line-pvert e1) (line-nvert e2))
		   (eps-v= (line-nvert e1) (line-pvert e2))))
	  (return-from find-equivalent-edge e2)  )))

(defun unify-vertex (edges)
  (let ((vertices
	 (remove-duplicates
	    (apply #'append (mapcar #'(lambda (ln) (send ln :vertices)) edges))
	    :test #'eps-v=)))
     (dolist (e edges)
        (setf (line-pvert e)
	      (car (member (line-pvert e) vertices :test #'eps-v=)))
        (setf (line-nvert e)
	      (car (member (line-nvert e) vertices :test #'eps-v=))))))

(defun merge-edges-if-colinear (e1 e2 seg1 seg2)
   (when (and e1 e2 (send e1 :colinear-line e2))
      ;; delete e2 and replace e2's in seg2 with e1 whose vertex is extended
      ;; to cover e2.
      ;; (format t "merging colinear lines~%     ~s~%     ~s~%" e1 e2)
      (cond ((eps-v= (line-pvert e2) (line-pvert e1))
	     (setf (line-pvert e1)  (line-nvert e2)) )
	    ((eps-v= (line-pvert e2) (line-nvert e1))
	     (setf (line-nvert e1)  (line-nvert e2)) )
	    ((eps-v= (line-nvert e2) (line-pvert e1))
	     (setf (line-pvert e1)  (line-pvert e2)) )
	    ((eps-v= (line-nvert e2) (line-nvert e1))
	     (setf (line-nvert e1)  (line-pvert e2)) ) 
	    (t (return-from merge-edges-if-colinear nil) ) )
      (dolist (s seg2) (delete e2 s))
      e2 ) )

(defun merge-contacting-faces (face1 face2 seg1 seg2)
  ;; face2 circuit is deleted and  merged into face1
   (let* ((face1edges (assoc face1 seg1))
	  (face2edges (assoc face2 seg2)) 
	  e1 fx1 fx2 fxs1 fxs2 fxs)
     (dolist (e2 (cdr face2edges))
	(setq e1 (find-equivalent-edge e2 (cdr face1edges)))
        ;; (break "mcf: ")
	(cond (e1 	;duplicated edge found
		; (format t "duplicated edges ~s ~s~%" e1 e2)
		(setq fx1 (send e1 :another-face face1))	;old face
		(setq fx2 (send e2 :another-face face2))	;old face
		(cond ((eps-v= (send fx1 :normal) (send fx2 :normal))
			;; kill both edges
			(setq fxs1 (assoc fx1 seg1)
			      fxs2 (assoc fx2 seg2))
			(delete e1 face1edges)
			(delete e2 face2edges)
			(delete e1 fxs1)
			(delete e2 fxs2)
			;; Are there any singularities happening at the
			;; end-points of e2 and e1?
			(let ((ce2p (find-connecting-edge
					 (line-pvert e2) (cdr fxs2)))
			      (ce2n (find-connecting-edge
					 (line-nvert e2) (cdr fxs2))) 
			      (ce1p (find-connecting-edge
					 (line-pvert e1) (cdr fxs1)))
			      (ce1n (find-connecting-edge
					 (line-nvert e1) (cdr fxs1))) 	)
			   (merge-edges-if-colinear ce1p ce2p seg1 seg2)
			   (merge-edges-if-colinear ce1p ce2n seg1 seg2)
			   (merge-edges-if-colinear ce1n ce2p seg1 seg2)
			   (merge-edges-if-colinear ce1n ce2n seg1 seg2) )
			;; for each edge of fx2, replace fx2 with fx1
			(dolist (e (cdr  fxs2))
			   (if (or (eql (edge-pface e) fx2)
				   (eql (edge-nface e) fx2) )
			       (send e :replace-face fx2 fx1))
			   )
			(nconc fxs1 (cdr fxs2))
			(setq seg2 (delete fxs2 seg2))
			;; fxs2 has disappeared
			(push fxs1 fxs)
			;; (unify-vertex (cdr fxs1))
			)
		      (t 
			;; duplicated edges found, but two adjacent faces
			;; are not coplanar like a cone on a cylinder.
			(delete e2 face2edges)
			(delete e1 face1edges)
			(send e1 :replace-face face1 fx2)
			;; (unify-vertex (cdr face1edges))
			)))
	      ((eql (send face1 :insidep (send e2 :point 0.5))
		    ':outside)
		; do nothing
		)
	      ((null (member e2 face1edges))
		;; (format t ";; no duplicated edges ~s~%" e2)
		(delete e2 face2edges)
		(nconc face1edges (list e2))
		(send e2 :replace-face face2 face1)
		;;(unify-vertex (cdr face1edges))
	        )
	      (t (warn "unknow contacting edge state ~s ~s~%" face1 e2))
	))
    (dolist (e1 (cdr face1edges))
	(cond  ((eql (send face2 :insidep (send e1 :point 0.5))
		    ':inside)
		;;(warn "contacting edge ~s is inside of ~s~%" e1 face2)
		(delete e1 face1edges)
		(nconc face2edges (list e1))
		(send e1 :replace-face face1 face2)
		(push (assoc (send e1 :another-face face2) seg1) fxs)
		;; (unify-vertex (cdr fxs1))
		))
	;; (unify-vertex (cdr face2edges))
	)
    (unify-vertex (apply #'append
			 (cdr face2edges)
			 (cdr face1edges)
			 (mapcar #'cdr fxs)))
    seg2  ))



(defun merge-aligned-faces (face1 face2 seg1 seg2)
   (let* ((face1edges (assoc face1 seg1))
	  (face2edges (assoc face2 seg2)) 
	  e1  f1edges fx fxs)
     (setq f1e face1edges f2e face2edges)
     (if *debug* (break "aln1: "))
     (dolist (e2 (cdr face2edges))
	(setq e1 (find-equivalent-edge e2 (cdr face1edges)))
	(cond (e1 	;duplicated edge found
		(delete e2 face2edges)
		(delete e2
			(assoc (send e2 :another-face face2) seg2))
;		(delete e1 face1edges)
;		(delete e1
;			(assoc (send e1 :another-face face1) seg1) )
		)
	      ((eql (send face1 :insidep (send e2 :point 0.5)) ':inside)
		(delete e2 face2edges)
		(delete e2
			(assoc (send e2 :another-face face2) seg2))
		)
              (t 
		(delete e2 face2edges)
		(nconc face1edges (list e2))
		(send e2 :replace-face face2 face1))) )
     (dolist (e1 (cdr face1edges))
	(cond ((eql (send face2 :insidep (send e1 :point 0.5)) ':inside)
		(delete e1 face1edges)
		(delete e1
			(assoc (send e1 :another-face face1) seg1)) )) )
     (if (cdr face2edges)	;face2 should disappear
	 (error "face2edges left"))
     ;; find colinear edges in face1edges and link them  together
     (setq f1edges (cdr face1edges))
     (setq fx f1edges)
     ;; (break "aln2: ")
     (while (cdr f1edges)
          (setq e1 (pop f1edges))
	  (prog (e2 f2edges)
	    find-colinear
	      (setq f2edges f1edges)
	    find-colinear2
	      (setq e2 (pop f2edges))
	      (cond ((null e2) (return nil))
		    ((merge-edges-if-colinear e1 e2 seg1 seg2)
		     ;(delete e2 face1edges)
		     (setq f1edges (delete e2 f1edges))
		     (dolist (s seg1) (delete e2 s))
		     (go find-colinear) )
		    (t (go find-colinear2)))))
     (dolist (e (cdr face1edges))
	(setq fx (send e :another-face face1))
	(if (setq fx (assoc fx seg1))
	    (push (cdr fx) fxs)
	    (if (setq fx (assoc fx seg2))
	        (push (cdr fx) fxs))))
     (unify-vertex (remove-duplicates
			(apply #'append (cdr face1edges) fxs))     )
     (if *debug* (break "aln3: ") ))
   seg2)


(defun compose-body (body1 body2 side)
   (send body1 :worldcoords)
   (if (find-method body2 :worldcoords) (send body2 :worldcoords))
   (let* ((vertex-edge-htab1 (make-vertex-edge-htab body1))
	  (vertex-edge-htab2 (make-vertex-edge-htab body2))
	  (faces1 (send body1 :faces))
	  (faces2 (send body2 :faces))
	  (edges1 (send body1 :edges))
	  (edges2 (send body2 :edges))
	  (intersects1)
	  (intersects2)
	  (common-box  (send body1 :common-box body2 0.01))
	  (segments1) (segments2) (segments)
	  (crossing-edges1) (crossing-edges2)
	  contacts aligneds
	  ctime0 ctime1 ctime2 ctime3 ctime4 ctime5 ctime6 ctime7
	 )
     (setq ctime0 (runtime))
     (copy-add-vertex vertex-edge-htab1)
     (copy-add-vertex vertex-edge-htab2)
     (setq ctime1 (runtime))
     (setq intersects1 (initial-intersection-list edges1 vertex-edge-htab1))
     (setq intersects2 (initial-intersection-list edges2 vertex-edge-htab2))
     (setq ctime2 (runtime))
     (insert-intersections intersects1 faces2 common-box)
     (insert-intersections intersects2 faces1 common-box)
     (setq ctime3 (runtime))

     (setq i1 intersects1 i2 intersects2)
;;;      (format t ";; intersections in i1 and i2~%")     (break "1: ")

     ;; make-edge-segments is the most time consuming function
     (setq segments1 (make-edge-segments intersects1 body2 side))
     (setq segments2 (make-edge-segments intersects2 body1 side))
     ;; segments is a list of
     ;;  (org-edge new-edge segmenting-face1 segmenting-face2)
     (setq ctime4 (runtime))

     ;;(format t ";; make-edge-segments finished~%")    (break "2: ")

     (setq intersects1 (sort-edges-by-face (intersecting-segments segments1))
	   intersects2 (sort-edges-by-face (intersecting-segments segments2)))
     (setq ctime5 (runtime))
     (setq segments1 (sort-edges-by-face  segments1)
	   segments2 (sort-edges-by-face  segments2))
     (setq ctime6 (runtime))

     (setq crossing-edges1 (make-crossing-edges intersects1 segments2 t side)
 	   crossing-edges2 (make-crossing-edges intersects2 segments1 nil side))
     (setq *seg1* segments1
	   *seg2* segments2)
     (setq *se1* crossing-edges1
	   *se2* crossing-edges2)
     (when *debug* (format t ";; crossing edges~%")    (break "3: "))

     (setq segments1
	   (merge-segments segments1 (car crossing-edges1) (cadr crossing-edges2))
	   segments2
	   (merge-segments segments2 (car crossing-edges2) (cadr crossing-edges1)))
     (setq *seg1* segments1
	   *seg2* segments2)

     (if (derivedp body2 body)
	 (setq contacts (contacting-faces body1 body2)) )
     (when contacts
       (format *error-output* ";;~d face-to-face contact(s) found.~%" (length contacts))
       (if *debug* (break "con: "))
       (dolist (con contacts)
	 (setq segments2 (merge-contacting-faces
			  (car con) (cadr con) segments1 segments2)) )	
	)

     (setq segments1 (delete-if-not #'cdr segments1))
     (setq segments2 (delete-if-not #'cdr segments2))
     (setq *seg1* segments1
	   *seg2* segments2)
     (setq aligneds (aligned-faces (mapcar #'car segments1)
				   (mapcar #'car segments2)))
     (when aligneds
	(format *error-output* ";;~d face-to-face alignment(s) found.~%" (length aligneds))
	(dolist (algn aligneds)
	   (merge-aligned-faces
		(car algn) (cadr algn) segments1 segments2))
	)

     (setq *faces* nil)
     (when *debug*
	(format t ";; merging finished, start constructing faces~%")
	(break "5: ") )
    
     (dolist (s segments1)
	(if *debug* (format t ";; ~d " (length *faces*)))
        (push (construct-faces s) *faces*) )

     (dolist (s segments2)
	(if *debug* (format t ";; ~d " (length *faces*)))
        (push (construct-faces s) *faces*))

     (setq *faces* (flatten (nreverse *faces*)))

     (setq ctime7 (runtime))
     (if *debug*
	(format t ";; ~f ~f ~f ~f ~f ~f ~f~%"
		(* 0.0167 (- ctime1 ctime0))
		(* 0.0167 (- ctime2 ctime1))
		(* 0.0167 (- ctime3 ctime2))
		(* 0.0167 (- ctime4 ctime3))
		(* 0.0167 (- ctime5 ctime4))
		(* 0.0167 (- ctime6 ctime5))
		(* 0.0167 (- ctime7 ctime6))))
     (instance *body-class* :init :faces *faces*)
))

;;
;; toplevel functions for body composition
;;

(defun set-original-face (newbody)
   (let* ((csg-list (send newbody :csg))
	  (new-primitives (send newbody :primitive-bodies))
	  (original-primitives
	    (mapcar #'(lambda (x) (get x :copied-primitive)) new-primitives))
	  (fbody nil) (p nil))
      (dolist (f (send newbody :faces))
	 (setq fbody (send f :body))
	 (cond ((primitive-body-p fbody) 
		   (if (setq p (position fbody original-primitives))
		       (send f :primitive-face
			       (nth (position (send f :primitive-face)
					      (send fbody :faces))
				    (send (nth p new-primitives) :faces)))))
		(t (warn "not a primitive ~A" fbody)))
	 (send f :body newbody) )
      (dolist (p new-primitives)
	 (setf (get p :copied-primitive) t)
	;; (send p :manager newbody)
	 (send newbody :assoc p))
      new-primitives))

(defun body+ (&rest bodies)
   (let* ((rbody (first bodies))
	  (csg-list (list (send rbody :copy-csg))))
      (dolist (bbody (rest bodies))
	  (setq rbody (compose-body rbody bbody ':outside))
	  (push (send bbody :copy-csg)
		csg-list) )
      (send rbody :csg (cons '+ (list (nreverse csg-list))))
      (set-original-face rbody)
      rbody) )

(defun body* (&rest bodies)
   (let* ((abody (pop bodies)) (csg-list (list (send abody :copy-csg))))
      (while bodies
	  (setq abody (compose-body abody (car bodies) ':inside)) 
	  (push (send (pop bodies) :copy-csg) csg-list) )
      (send abody :csg (cons '* (list (nreverse csg-list))))
      (set-original-face abody)
      abody) )

(defun body- (body1 &rest bodies)	;body1 - body2 = -((- body) + body2)
   (let ((newbody body1) (csg-list))
      (send body1 :evert)
      (unwind-protect
	      (while bodies
		 (push (send (car bodies) :copy-csg) csg-list)
	         (setq newbody (compose-body newbody (pop bodies) ':outside))
		 (setq (newbody . evertedp) t) )
	      (send body1 :evert))
      (send newbody :evert)
      (send newbody :init)
      (send newbody :csg
		(cons '- (list (cons (send body1 :copy-csg)
				     (nreverse csg-list)))))
      (set-original-face newbody)
      newbody))

;(defun body-interference (body1 body2)
;    (send body1 :worldcoords)
;    (send body2 :worldcoords)
;    (send body1 :intersectp body2))

;;
;; check body interference for every combination of bodies
;; and return a list of interfering bodies
;;

(defun body-interference (&rest bodies)
   (send-all bodies :worldcoords)
   (let (b1 b2 interference-list)
     (while (rest bodies)
        (setq b1 (pop bodies))
        (dolist (b bodies)
	  (if (send b1 :intersectp b)
	      (push (list b b1) interference-list))) )
     interference-list))

(defmethod plane 
 (:box () (instance bounding-box :init
			 (float-vector -1.0e30 -1.0e30 -1.0e30)
			 (float-vector 1.0e30 1.0e30 1.0e30))))

(defclass semi-space :super plane :slots ())

(defmethod semi-space
 (:edges () nil)
 (:faces () (list self))
 (:box (&optional (tolerance 0.0)) (instance bounding-box :init2
			 (float-vector -1.0e30 -1.0e30 -1.0e30)
			 (float-vector 1.0e30 1.0e30 1.0e30)))
 (:insidep (pnt)
   (if  (< (send self :distance pnt) 0.0) ':inside ':outside))
 (:primitive-face (&optional x) self)
 (:body (&optional x) nil)
 (:id (&optional x) nil)
 (:on-edge (point &optional tol) nil)
)


(defun body/ (body1 pln)
   (let* ((body2 (instance semi-space :init (pln . normal) (pln . distance))))
      (compose-body body1 body2 ':inside)))
 
(provide :compose "@(#)$Id$")
