;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Main-Functions-of-Glueing-Operations     ;;;
;;;       1988.11.10   written by M.Adachi   ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(eval-when (compile eval)
	   (load "/usr/local/eus/llib/geoclasses.l"))

(defvar *maxangle* 0.001)

(defvar *maxdistance* 0.001)

(defmethod closed-region 
   (:set-edge (elist)
      (setq edges elist)))

(defmethod edge
   (:set-pface (pf)
      (setq pface pf))
   (:set-nface (nf)
      (setq nface nf)))

(defun zep (x)
  (< (abs x) 0.00001))

;;
;;
(defun uniq (l)
   (cond 
      ((atom (cdr l)) l)
      ((memq (car l) (cdr l)) (uniq (cdr l)))
      (t (cons (car l) (uniq (cdr l))))))

;;
;;   (glue body1 body2)
;;
(defun xor (a b) (and (or a b) (not (and a b))))

(defun glue (bod1 bod2 &optional (edge-kill? t))
   (let* ((b1 (copy-object bod1))
          (b2 (copy-object bod2))
          (con-faces (find-contact-face b1 b2))  
          (face1)
          (face2)
          (coord (bod1 . worldcoords))
          (int-flag1)
          (int-flag2)
          (new-body))
     (if (equal 1 (length con-faces))       
         nil
         (return-from glue con-faces)) 
     (setq face1 (caar con-faces)
           face2 (cadar con-faces))
     (setq int-flag1 (test-face-intersection face1 face2))
     (setq int-flag2 (test-face-intersection face2 face1))
     (print int-flag1)
     (print int-flag2)
     (if  
       (and (eq int-flag1 'inside) (eq int-flag2 'outside))
       (setq new-body (glue1 b2 b1 face2 face1))
       (if (and (eq int-flag1 'outside) (eq int-flag2 'inside))
           (setq new-body (glue1 b1 b2 face1 face2))
           (if (or (eq int-flag1 'intersect) (eq int-flag2 'intersect))
               (setq new-body (glue3 b1 b2 face1 face2))
               (print error)
           )))
  (send new-body :reset-model-vertices)
  (send new-body :replace-coords coord)
  (if edge-kill? (possible-kill new-body))
  new-body))
            
;;
;;

(defun find-contact-face (bod1 bod2)
   (let* ((face1 (bod1 . faces))
          (face2 (bod2 . faces))
          (result))
   (dolist (f1 face1)
     (dolist (f2 face2)
       (if
         (and (< (abs (+ (v. (f1 . normal) (f2 . normal)) 1.0)) *maxangle*)
              (< (abs (send f1 :distance (car (f2 . vertices)))) *maxdistance*))
           (push (list f1 f2) result)
           nil)
          ))
    result))

;;
;;

(defun test-face-intersection (face1 face2)
   (let* ((verts (face1 . vertices))
          (result (send face2 :insidep (pop verts))))
     (if (eq result 'border) 
         (return-from test-face-intersection 'intersect)
         nil)
     (dolist (v verts)
        (if (eq result (send face2 :insidep v))
            nil 
            (return-from test-face-intersection 'intersect))
          )
     result))
              
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Glue-operations         ;;;; 
;;;    written by M.adachi  ;;;;
;;;    1988.10.17           ;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod hole 
   (:set-edges (e) (setq edges e))
   (:set-vertices (v) (setq vertices v))
 )

(defun glue1 (bod1 bod2 face1 face2)    ;;;face2 is included by face1 
   (let* ((edges (face2 . edges)) 
          (vert (face2 . vertices))
          (new-faces 
                 (append (bod1 . faces) (bod2 . faces)))
          (hol (instance hole)) 
          (holes (append (face1 . holes) (face2 . holes)))
          (h-faces)
         )
    (progn 
       (send hol :set-edge edges)
       (send hol :set-vertices vert)
       (send hol :reset-normal)
       (send face1 :enter-hole hol)
       (send hol :enter-face face1)

       (dolist (h holes)
          (let* ((ed (h . edges))
                 (ve (h . vertices))
                 (fa (instance face)))
            (send fa :set-edge ed)
            (send fa :set-vertices ve)
            (send fa :reset-normal)
            (dolist (e ed)
               (send e :replace-face (h . myface) fa))
            (push fa h-faces)))

       (setq new-faces (append h-faces new-faces))

       (setq new-faces (remove face2 new-faces))
       (dolist (e edges)
          (send e :replace-face face2 face1)) 
       (setq *new-body*
              (instance *body-class*
                            :init :faces new-faces))
    )
  ))


;;
;;

(defun glue2 (bod1 bod2 face1 face2)   ;;;equal face1 face2
   (let* ((newface1 (remove face1 (bod1 . faces)))
          (newface2 (remove face2 (bod2 . faces)))
          (edges1 (face1 . edges))
          (edges2 (face2 . edges))
          (new-faces)
          )
     (dolist (edg edges1)
        (let* ((fac (find-face edg newface2))
               (edg1 (find-edge2 (edg . pvert) (fac . edges)))
               (edg2 (find-edge2 (edg . nvert) (fac . edges)))
               )
            (send edg :replace-face face1 fac)
            (dolist (e edg1)
               (send e :replace-vert (edg . pvert)))
            (dolist (e edg2)
               (send e :replace-vert (edg . nvert)))
            (send fac :replace-edge edg)
            (send fac :replace-vert (edg . pvert))
            (send fac :replace-vert (edg . nvert))
           ))
     (setq new-faces 
            (append newface1 newface2))
     (setq *new-body*
            (instance *body-class* :init :faces new-faces))
    )
  )

;;
;;

(defun glue3 (bod1 bod2 face1 face2)
   (let* ((vlist)
          (edge1)
          (edge2)
          (new-edge1)
          (new-edge2)
          (inner-edge1)
          (inner-edge2)
          (outer-edge1)
          (outer-edge2)
          (border-edge1)
          (border-edge2)
          (bod2-faces)          
          (new-faces)
          (new-faces1)
          (new-faces2)
          (hol (instance hole)) 
          (holes (append (face1 . holes) (face2 . holes)))
          (h-faces)
           ) 
     (equalize-vert bod1 bod2 face1 face2)
     (setq vlist (uniq (flatten (intersect-point-by-2faces face1 face2))))
     (make-vert bod1 (uniq (append vlist (cdr (face2 . vertices)))))
     (make-vert bod2 (uniq (append vlist (cdr (face1 . vertices)))))
     (equalize-vert bod1 bod2 face1 face2)
     (setq edge1 (face1 . edges))
     (setq edge2 (face2 . edges))
     (setq new-edge1 (find-inner-edge face2 edge1))
     (setq new-edge2 (find-inner-edge face1 edge2))
     (setq inner-edge1 (car new-edge2))
     (setq inner-edge2 (car new-edge1))
     (setq outer-edge1 (cadr new-edge1))
     (setq outer-edge2 (cadr new-edge2))
     (setq border-edge1 (caddr new-edge1))
     (setq border-edge2 (caddr new-edge2))

     (setq bb1 (copy-object bod1)
           bb2 (copy-object bod2) 
           e1 new-edge1 e2 new-edge2)

     (dolist (ed inner-edge1)
        (send ed :replace-face face2 face1))
     (dolist (ed inner-edge2)
        (send ed :replace-face face1 face2))
     (setq bod2-faces (remove face2 (bod2 . faces)))
     (dolist (edg border-edge1)
        (let* ((fac (find-face edg bod2-faces)))
            (send edg :replace-face face1 fac)
            (send fac :replace-edge edg)
           ))

     (setq new-edge1 (append inner-edge1 outer-edge1))
     (setq new-edge2 (append inner-edge2 outer-edge2))
     (send face1 :set-edges new-edge1)
     (send face2 :set-edges new-edge2)
     (dolist (edg (sort-edge-by-loop new-edge1 face1 face2))
        (send face1 :set-edges edg)
        (push (make-correct-face-by-edges face1 edg) new-faces1))
     (dolist (edg (sort-edge-by-loop new-edge2 face1 face2))
        (send face2 :set-edges edg)
        (push (make-correct-face-by-edges face2 edg) new-faces2))
     (setq new-faces 
            (flatten
              (append
                 (subst new-faces1 face1 (bod1 . faces))
                 (subst new-faces2 face2 (bod2 . faces))))
                )

       (dolist (h holes)
          (let* ((ed (h . edges))
                 (ve (h . vertices))
                 (fa (instance face)))
            (send fa :set-edge ed)
            (send fa :set-vertices ve)
            (send fa :reset-normal)
            (dolist (e ed)
               (send e :replace-face (h . myface) fa))
            (push fa h-faces)))

       (setq new-faces (append h-faces new-faces))

     (setq *body* 
        (instance *body-class* :init :faces new-faces))
     ))

;;
;;

(defun make-correct-face-by-edges (fac elist)
   (let* ((new-edges)
          (new-face (instance face))
          (new-vertices))
    (if elist
      (progn
        (dolist (e elist)
          (cond 
            ((not (eq fac (e . pface))) (send e :inverse))
            (t nil)
          ))
        (setq new-edges (list (pop elist)))
        (dotimes (i (length elist))
           (push (send (car new-edges) :pwing) new-edges))
        (setq new-vertices (send (car new-edges) :pvertex fac))
        (dolist (e new-edges)
           (push (send e :nvertex fac) new-vertices))
        (send new-face :set-edges new-edges)
        (send new-face :set-vertices (cons (car new-vertices) 
                                              (reverse new-vertices)))
        (send new-face :reset-normal)
        (dolist (e new-edges)
           (send e :replace-face fac new-face))
        )
     (setq new-face nil))
    new-face))
  
;;
;;


(defun find-intersect-point (edg elist)
   (let* ((find-point))
      (dolist (ed elist)
         (push 
            (cadr (send edg :intersect ed))
            find-point))
   find-point))

;;
;;

(defun intersect-2edge (ed1 ed2 norm)  
   (let* ((p1 (ed1 . pvert))
          (n1 (ed1 . nvert))
          (p2 (ed2 . pvert))
          (n2 (ed2 . nvert))
          (tr1 (triangle p1 n1 p2 norm))
          (tr2 (triangle p1 n1 n2 norm))
          (tr3 (triangle p2 n2 p1 norm))
          (tr4 (triangle p2 n2 n1 norm)))
    (cond 
         ((and 
          ;  (or
               (xor (plusp tr1) (plusp tr2))
          ;    (and (zerop tr1) (not (zerop tr2)))
          ;    (and (not (zerop tr1)) (zerop tr2))
          ;   )
          ;  (or
               (xor (plusp tr3) (plusp tr4))
          ;    (and (zerop tr3) (not (zerop tr4)))
          ;    (and (not (zerop tr3)) (zerop tr4))
          ;   )
            )
           (return-from intersect-2edge t))
         (t
          (return-from intersect-2edge nil))
     ))) 
 
;;
;;

(defun find-intersect-edge (ed elist norm)
   (let ((find-list))  
      (dolist (e elist)
         (cond ((intersect-2edge e ed norm) (push e find-list))
               (t nil)
             ))
    find-list  ))

;;
;;

(defun intersect-point-by-2faces (face1 face2)  ;;
   (let* ((edge1 (face1 . edges))
          (edge2 (face2 . edges))
          (vlist))
     (dolist (ed edge1)
        (let* ((int-elist (find-intersect-edge ed edge2 (face1 . normal))))
           (cond 
              (int-elist 
                  (setq vlist
                     (cons (find-intersect-point ed int-elist) vlist)))
              (t nil)
           )
         ))
      vlist))
         
;;
;;

(defun find-inner-edge (fac elist)     
   (let ((inner-edges)
         (outer-edges)
         (border-edges))
      (dolist (edg elist)
         (cond                        
             ((find-eq-edge edg (fac . edges)) (push edg border-edges)) 
             ((or    ;;; honnrainara hitotumeno joukenndakede yoihazudaga ????
                (eq (send fac :insidep
                   (scale 0.5 (v+ (edg . pvert) (edg . nvert)))) 'inside)
                (eq (send fac :insidep (edg . pvert)) 'inside)
                (eq (send fac :insidep (edg . nvert)) 'inside)
               )
                 (push edg inner-edges)
                )
             ((and
                (eq (send fac :insidep (edg . pvert)) 'border)
                (eq (send fac :insidep (edg . nvert)) 'border)
               )
                 (push edg border-edges)
                )
             (t  (push edg outer-edges))
            ))
    (list inner-edges outer-edges border-edges) ))

;;
;;

(defun find-eq-edge (edg elist)
  (let ((result))
   (dolist (e elist) 
    (if
     (or (and (eq (edg . pvert) (e . pvert)) (eq (edg . nvert) (e . nvert)))  
         (and (eq (edg . pvert) (e . nvert)) (eq (edg . nvert) (e . pvert))))  
     (push e result) nil))
   result))

;;
;;

(defun sort-vertices (v vlist)    ;;v (v1 v2 v3 v4 .....)
  (let* ((sorted-vlist)
         (v1)(v2)(index)(vec))
  (setq vec (v- (car vlist) (cadr vlist)))
  (if (zep (aref vec 0))
    (if (zep (aref vec 1))
      (if (zep (aref vec 2)) nil 
      (setq index 2))
    (setq index 1))
  (setq index 0))
  (setq vec (aref v index))
  (setq vlist 
      (mapcar #'(lambda (p) (list p (aref p index) vec)) vlist))
  (setq sorted-vlist
      (sort vlist #'secondless))
  (setq sorted-vlist
      (mapcar #'car sorted-vlist))))

;;
;;

(defun secondless (x y)
   (< (abs (- (cadr x) (caddr x)))
      (abs (- (cadr y) (caddr y))))) 

;;
;;


(defun vector-length (vect)
   (let ((x (aref vect 0))
         (y (aref vect 1))
         (z (aref vect 2)))
     (sqrt (+ (* x x) (* y y) (* z z)))))

;; 
;;

(defun neary-vector-equal (vect1 vect2 &optional (dis *maxdistance*))
   (let ((len (vector-length (v- vect1 vect2))))
      (< len dis)))
 
;;
;;

(defun find-con-edge (v edg elist face1 face2)
   (let* ((con-edges (mapcar #'car (find-neary-connect-edge v edg elist)))
          (my-fac) (other-fac))
     (cond 
       ((or (eq (edg . pface) face1) (eq (edg . nface) face1))
        (setq my-fac face1 other-fac face2))
       ((or (eq (edg . pface) face2) (eq (edg . nface) face2))
        (setq my-fac face2 other-fac face1))
      )

     (cond 
       ((eq (length con-edges) 1) 
                (setq con-edges (car con-edges)))
       ((eq (length con-edges) 3) 
                (if (or (eq ((car con-edges) . pface) my-fac)
                        (eq ((car con-edges) . nface) my-fac))
                      (setq con-edges (caddr con-edges))
                      (setq con-edges (car con-edges))))
       (t (setq con-edges nil)))

 con-edges)))



(defun find-neary-connect-edge (v edg elist)
  (let* ((v1 (normalize-vector (v- (edg . pvert) (edg . nvert))))
         (result))
   (dolist (e elist)
      (cond ((or (equal v (e . pvert)) 
                 (equal v (e . nvert)))
              (push e result))
            (t result))
           )
   (if result
        (sort-edge-clockwize edg result) nil)))

;;
;;

(defun cadr-less (x y)
  (< (cadr x) (cadr y))) 

;;
;;

(defun find-connect-edges (v elist)
  (let ((result))
   (dolist (e elist)
      (cond ((or (equal v (e . pvert)) 
                 (equal v (e . nvert)))
                (push e result))
            (t nil)
    ))result))

;;
;;

(defun sort-edge-by-loop (elist face1 face2)
  (if elist
   (let* ((new-elist (list (list (pop elist)))))
      (while elist
        (let* ((e (caar new-elist))
               (edg))
          (if
            (setq edg (find-con-edge (e . pvert) e elist face1 face2))
            (progn 
              (setq elist (remove edg elist))
              (setq new-elist  
                 (subst (cons edg (car new-elist)) 
                          (car new-elist) new-elist))
              )
            (if
              (setq edg (find-con-edge (e . nvert) e elist face1 face2))
              (progn 
                (setq elist (remove edg elist))
                (setq new-elist  
                   (subst (cons edg (car new-elist)) 
                            (car new-elist) new-elist))
                )
              (setq new-elist (cons (list (pop elist)) new-elist))
             )
            )
          ))
     new-elist)
     nil))

         

;;
;;

(defun equalize-vert (bod1 bod2 face1 face2)
   (let ((vert1 (cdr (face1 . vertices)))
         (vert2 (cdr (face2 . vertices))))
     (dolist (v1 vert1)
       (dolist (v2 vert2)
          (cond 
            ((and (neary-vector-equal v1 v2) (not (eq v1 v2)))
               (send bod2 :equalize-vert v1)))
       ))
      (send face1 :reset-normal)
      (send face2 :reset-normal)
   )) 
         

;;
;;

(defun angle-of-edges (edge1 edge2 norm) ;;; clockwise 
   (let* ((int-point)
          (p1) (p2)
          (ang) (triang) (result))
     (cond 
       ((equal (edge1 . pvert) (edge2 . pvert))
           (setq int-point (edge1 . pvert) 
                 p1        (edge1 . nvert) 
                 p2        (edge2 . nvert)))
       ((equal (edge1 . pvert) (edge2 . nvert))
           (setq int-point (edge1 . pvert) 
                 p1        (edge1 . nvert) 
                 p2        (edge2 . pvert)))
       ((equal (edge1 . nvert) (edge2 . pvert))
           (setq int-point (edge1 . nvert) 
                 p1        (edge1 . pvert) 
                 p2        (edge2 . nvert)))
       ((equal (edge1 . nvert) (edge2 . nvert))
           (setq int-point (edge1 . nvert) 
                 p1        (edge1 . pvert) 
                 p2        (edge2 . pvert)))
       (t (return-from angle-of-edges 'not-intersect))
        )
     (setq ang (vector-angle (normalize-vector (v- p1 int-point))
                             (normalize-vector (v- p2 int-point))))
     (setq triang (triangle p1 int-point p2 norm))
     (cond 
       ((minusp triang) (setq ang (- (* 2 pi) ang)))
       (t nil))
     ang))

;;
;;

(defun sort-edge-clockwize (edg elist)
   (let* ((ang)
          (norm)
          (result))
    (setq norm 
       (normalize-vector 
                    (v* (v- (edg . pvert) (edg . nvert))
                        (v- ((car elist) . pvert) ((car elist) . nvert)))))
    (if (zerop (vector-length norm))
       (setq norm 
          (normalize-vector 
                       (v* (v- (edg . pvert) (edg . nvert))
                           (v- ((cadr elist) . pvert) ((cadr elist) . nvert)))))
    (dolist (e elist)
	    (push (list e (angle-of-edges edg e norm)) result)))
    (setq result (sort result #'cadr-less))
    result))


             



