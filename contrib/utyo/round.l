;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Round-Coner-Operation   1988.11.9 ;;; 
;;;         Written by M.adachi       ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;
;;

(defun cut-peak (bod vert vect depth)
   (let* ((flist (bod . faces))
          (con-faces (find-con-faces vert flist))
          (n-vect (normalize-vector vect))
          (pln (instance plane :init n-vect (v+ vert (scale depth n-vect))))    
          (new-edg-verts
             (mapcar #'(lambda (f) (send pln :intersect-face f)) 
             con-faces))
          (new-verts (flatten new-edg-verts)))
    (dolist (v new-verts)
       (send bod :make-vertex v))
    (dolist (edg-v new-edg-verts)
       (send bod :make-edge (car edg-v) (cadr edg-v)))
    (send bod :change-vert 
                 (v+ vert (scale (* 0.4 depth) n-vect)) vert)
    (dolist (f (bod . faces))
       (send f :reset-normal))
   ))

;;
;;

(defun find-con-faces (vert flist)
   (let ((result))
     (dolist (f flist)
        (if (member vert (f . vertices)) 
            (push f result)
            nil))
      result))
     
;;
;;

(defun find-con-edges (vert elist)
   (let ((result))
     (dolist (e elist)
        (if (or (equal vert (e . pvert)) (equal vert (e . nvert))) 
            (push e result)
            nil))
      result))
     
;;
;;

(defmethod body
   (:round-peak (vert depth)
      (let* ((con-edges (find-con-edges vert edges))
             (nor #f(0 0 -1)))
        (cut-peak self vert nor depth)
        (cut-peak self vert nor (/ depth 2))
        (cut-peak self vert nor (/ depth 4))
       ))
   (:cut-edge (edg depth)
      (let* ((vert1)
             (vert2)
             (norm (normalize-vector
                      (v+ ((edg . pface) . normal) ((edg . nface) . normal))))
             (vect (scale (- depth) norm))
             (apoint (v+ (edg . pvert) vect))
             (pln (instance plane :init norm apoint)))
        (setq con-edge1
           (remove edg (find-con-edges (edg . pvert) ((edg . pface) . edges))))
        (setq con-edge2
           (remove edg (find-con-edges (edg . nvert) ((edg . pface) . edges))))
        (setq vert1 (cadr (send pln :intersect-edge (car con-edge1))))
        (setq vert2 (cadr (send pln :intersect-edge (car con-edge2))))
(setq v1 vert1 v2 vert2 e1 con-edge1 e2 con-edge2)
        (send self :make-vertex vert1)
        (send self :make-vertex vert2)
        (send self :make-edge vert1 vert2)
        (setq con-edge1
           (remove edg (find-con-edges (edg . pvert) ((edg . nface) . edges))))
        (setq con-edge2
           (remove edg (find-con-edges (edg . nvert) ((edg . nface) . edges))))
        (setq vert1 (cadr (send pln :intersect-edge (car con-edge1))))
        (setq vert2 (cadr (send pln :intersect-edge (car con-edge2))))
        (replace (edg . pvert) vert1)
        (replace (edg . nvert) vert2)
     ))

   (:old-cut-coner (edg depth)
      (let* ((con-edges)
             (verts)
             (vert)
             (norm (normalize-vector
                      (v+ ((edg . pface) . normal) ((edg . nface) . normal))))
             (vect (scale (- depth) norm))
             (apoint (v+ (edg . pvert) vect))
             (pln (instance plane :init norm apoint)))
        (setq con-edges 
             (uniq (append
                       (find-con-edges (edg . pvert) edges) 
                       (find-con-edges (edg . nvert) edges))))
        (dolist (e con-edges)
           (push (cadr (send pln :intersect-edge e)) vert))
        (dolist (v (flatten vert))
           (send self :make-vertex v))
        (setq verts (group-vert-by-face vert faces)) 
        (dolist (v verts)
           (send self :make-edge (car v) (cadr v)))
        (send self :change-vert 
                     (send pln :project-3dvector (edg . pvert)) (edg . pvert))
        (send self :change-vert 
                     (send pln :project-3dvector (edg . nvert)) (edg . nvert))
        (dolist (f faces)
           (send f :reset-normal))
     ))

   (:round-coner (edg depth)
      (let* ((con-faces)
             (verts)
             (norm (normalize-vector
                      (v+ ((edg . pface) . normal) ((edg . nface) . normal))))
             (vect (scale depth norm))
             (apoint (v+ (edg . pvert) vect))
             (pln (instance plane :init norm apoint)))
        (setq con-faces (list (edg . pface) (edg . nface)))
        (dolist (f con-faces)
           (push (send pln :intersect-face f) verts))
        (dolist (v (flatten verts))
           (send self :make-vertex v))
        (dolist (v verts)
           (send self :make-edge (car v) (cadr v)))
        (send self :change-vert 
                     (send pln :project-3dvector (edg . pvert)) (edg . pvert))
        (send self :change-vert 
                     (send pln :project-3dvector (edg . nvert)) (edg . nvert))
        (dolist (f faces)
           (send f :reset-normal))
     ))

 )

;;
;;

(defmethod plane 
   (:intersect-face (fac) 
       (let ((edg (fac . edges))
             (int-point)
             (result))
        (dolist (e edg)
           (push (cadr (send self :intersect-edge e)) result))
        (flatten result)))
  )

;;
;;

(defun group-vert-by-face (vlist flist)
  (let ((result))
   (dolist (fac flist)
    (let ((f-verts (fac . vertices))
          (elm))
      (dolist (v vlist)
        (if (memq v f-verts) (push v elm) nil))
      (push (if elm (sort-points elm) nil) result)))
   result
  ))

;;
;;

(defun devide-body (bod pln)
   (let* ((vlist)
          (verts))
     (dolist (e (bod . edges))
        (push (cadr (send pln :intersect-edge e)) verts))
     (nconc verts (find-on-plane-verts (bod . vertices) pln))
     (setq verts (flatten verts))
     (dolist (v verts)
        (send bod :make-vertex v)) 
     (setq vlist (group-vert-by-face verts (bod . faces)))  
     (dolist (vl vlist)
        (if vl 
            (when (cdr vl) (send bod :make-edge (pop vl) (car vl)))
            nil))
   bod))

;;
;;

(defun find-on-plane-verts (vlist pln)
   (let ((result))
     (dolist (v vlist)
        (if (zep (send pln :distance v)) (push v result) nil)) 
   result ))
