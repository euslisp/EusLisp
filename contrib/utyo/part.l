;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;  BUBUN-HENNKEI-Operations  1988.10.20~	;;;
;;;                Written by M.Adachi		;;;
;;;   methods of body				;;;
;;;   :make-vertex v				;;;
;;;   :make-edge   e				;;;
;;;   :kill-vertex v				;;;
;;;   :kill-edge   e				;;;
;;;						;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(eval-when
 (compile eval)
 (load "/usr/local/eus/llib/geoclasses.l")
 )

(defvar *maxarea* 0.01)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Test-and-Repair-Operations        ;;;
;;; check body consistency	      ;;;
;;; (test-body body)		      ;;;
;;;             Written-by-M.Adachi   ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(defun test-body-f (bod)  ;;; planar-check
  (let ((result))
    (dolist (f (send bod :faces))
     (setq result (chkface f))
     (if (numberp result)  
         (return-from test-body-f (list 'not-planar result))
         t))
    (print "face check ok!") nil ))
;;
;;

(defun test-body-n (bod)  ;;; normal-direction-check
  (let* ((edg (send bod :edges))
         (p-vert)(n-vert)(p)(n))
  (dolist (e edg)
    (setq p-vert (send (send e :pface) :vertices))
    (setq n-vert (send (send e :nface) :vertices))
    (setq p (car (send e :vertices)) 
          n (cadr (send e :vertices))) 
    (if (xor (equal p (cadr (member n p-vert))) 
             (equal p (cadr (member n n-vert))))
         t
         (return-from test-body-n 'incorrect-normal)))
    (print "norm check ok!") nil))
 
;;
;;

(defun xor (x y)
  (and (or x y)
       (not (and x y))))

;;
;;

(defun test-body-e (bod)    ;;; Winged-edge-check
  (let* ((edg (send bod :edges))
         (p-face)    
         (n-face))
  (dolist (e edg nil)
     (setq p-face (send e :pface)
           n-face (send e :nface))
     (cond ((not (and p-face n-face)) 
              (return-from test-body-e 'non-face-data))
           ((or (eq p-face n-face)
                (not (and (memq e (send p-face :all-edges))
                          (memq e (send n-face :all-edges)))))
              (return-from test-body-e 'wrong-face-data))
           (t))))
  (print "winged-edge ok!") nil) 
 
;;
;;

(defun test-body-v (bod)     ;;; Number-of-vert-check
  (let* ((fac (send bod :faces))
         (v1 (send bod :vertices))
         (v2))
  (dolist (f fac v2)
    (setq v2 
          (uniq (append v2 (send f :vertices)))))
  (dolist (v v1)
    (if (member v v2)      
          (setq v2 (remove v v2))
          (return-from test-body-v 'too-many-vert)))
  (if v2 'too-few-vert 
         (progn (print "vertices check ok!") nil))))) 
       
;;
;;

(defun test-body (bod)
  (cond ((test-body-e bod))
        ((test-body-v bod))
        ((test-body-f bod))
      ; ((test-body-n bod))
        (t 'correct)))

;;
;;

(defun chkface (fac &optional (max-error 0.0001))  ;;; planar-check
  (let* ((vert (send fac :vertices))
         (pln  (instance plane :init (send fac :normal) (pop vert)))
         (error-list)
         (result))
    (dolist (v vert)
       (push (send pln :distance v) error-list))
    (setq result (- (eval (cons 'max error-list))
                    (eval (cons 'min error-list))))
    (if (< result max-error)
        t result)))

;;
;;

(defun find-not-planar-face (bod &optional (max-error 0.0001))     
   (let* ((fac (bod . faces))
          (result))
     (dolist (f fac)   
        (if (numberp (chkface f max-error)) (push f result) nil))
     result))

;;
;;

(defun repair-planar-body (bod &optional (max-error 0.0001))
   (let* ((error-faces (find-not-planar-face bod max-error)))
      (dolist (f error-faces)
         (repair-planar-face f (bod . edges)))
    )) 

;;
;;

(defun repair-vertice (vert direction pln) 
;;; move vertice parallel to direction

   (let* ((3dl (instance 3dline :init direction vert))
          (cross-point (send pln :cross-with-3dline 3dl)))
     (replace vert cross-point))) 

;;
;;

(defun repair-planar-face (fac edg)
   (let* ((verts (send fac :all-vertices))
          (pln (instance plane :init (fac . normal) (pop verts))))
     (dolist (v verts)
       (let* ((con-edges (list- (find-connect-edge v edg) (fac . edges))))
        (cond 
           ((equal (length con-edges) 1) 
              (repair-vertice v (v- ((car con-edges) . pvert) 
                                    ((car con-edges) . nvert)) pln))
           ((equal con-edges nil)
              (repair-vertice v (fac . normal) pln))
           (t (return-from repair-planar-face (list con-edges "give up")))
          ))
       )))    

;;
;;

(defun find-connect-edge (vert elist)
   (let ((result))
     (dolist (e elist)
        (if (or (eq (e . pvert) vert) (eq (e . nvert) vert))
            (push e result)
            nil))
    result))

;;
;;

(defun wing-test (edge-list)
   (dolist (e edge-list)
      (cls)
      (draw e)
      (draw (e . pface))
      (draw (e . nface))
      (unix:sleep 1)))
       


;;
;;
(defun box-eq (box1 box2) ;;surrouding-box equal   ;;10.13
   (cond 
      ((and 
         (equal (box1 . minpoint) (box2 . minpoint))
         (equal (box1 . maxpoint) (box2 . maxpoint)))
        (return-from box-eq t))
      (t nil)
    )
  )

(defun make-vert (bod vlist) 
   (dolist (v vlist)
      (send bod :make-vertex  v )))

;;
;;

(defun nsubst (v ov vlist)  ;;; v , ov is string!! 
  (dolist (ve vlist)
    (if (equal ve ov) (replace ve  v) nil))) 

;;
;;

(defun find-on-edge (vert elist)
  (let ((result))
   (dolist (edg elist)
      (let* ((para (send edg :parameter vert))
             (point (send edg :point para)))
        (cond
            ((and (<= 0.0 para 1.0) 
                  (neary-vector-equal vert point *maxdistance*))
               (push edg result))
            (t result)
         )))
     result ))    
             

;;
;;

(defun possible-kill-edges (bod)
   (let ((elist (bod . edges)))
      (dolist (edg elist)
        (send bod :kill-edge edg)
        )
      ))

;;
;;

(defun possible-kill-vertices (bod)
   (let ((vlist (bod . vertices)))
      (dolist (vert vlist)
        (send bod :kill-vertex vert)
        )
      (send bod :reset-model-vertices)
      ))

;;
;;

(defun possible-kill (bod)
   (possible-kill-edges bod)
   (dolist (f (bod . faces))
      (send f :reset-normal))
   (possible-kill-vertices bod))

;;
;;

(defun linerp (fac edg)
   (let ((b1 (send edg :box))
         (b2 (send fac :box)))
     (and (box-eq b1 b2) (< (send fac :area) *maxarea*))))

;;
;;

(defmethod edge 
   (:inverse ()
       (let ((temp))
          (setq temp pface pface nface nface temp)
          (setq temp pvert pvert nvert nvert temp)
        ))
   (:replace-face (old-face new-face)
       (cond ((eq pface old-face)
                   (setq pface new-face))
             ((eq nface old-face)
                   (setq nface new-face))
             (t 'inconsist-face-setting))  
    )
   (:replace-vertex (old-vert new-vert)
       (cond ((eq pvert old-vert)
                   (setq pvert new-vert))
             ((eq nvert old-vert)
                   (setq nvert new-vert))
             (t 'cannot-find-vertex))
    )
   (:replace-vert (vert)
       (cond ((neary-vector-equal pvert vert)
                   (setq pvert vert))
             ((neary-vector-equal nvert vert)
                   (setq nvert vert))
             (t 'cannot-find-vertex))
    )
  )

;;
;;

(defmethod closed-region   
   (:set-edges (e)
       (setq edges e))
   (:set-vertices (v)
       (setq vertices v))
   (:set-normal (n)
       (setq normal n))
   (:set-distance (d)
       (setq distance d)) 
   )

;;
;;

(defmethod face
   (:remove-edge (e)
     (setq edges (remove e edges))
     (dolist (h holes) (send h :remove-edge e)))
   (:remove-vertex (v)
     (setq vertices (remove v (cdr vertices)))
     (setq vertices (cons (car (last vertices)) vertices))
     (dolist (h holes) (send h :remove-vertex v)))
   (:replace-edge (e)
     (dolist (edg edges)
      (cond 
        ((edge-equal e edg)
            (setq edges (subst e edg edges)))
        (t nil)
        )) 
     (dolist (h holes) (send h :replace-edge e)))
   (:replace-vert (v)
     (let ((vlist (cdr vertices)))
       (dolist (vert vlist)
         (cond 
           ((neary-vector-equal v vert)
               (setq vertices (subst v vert vlist)))
           (t nil)))
       (setq vertices (cons (car (last vertices)) vertices))
       (dolist (h holes) (send h :replace-vert v))
     ))
   )

;;
;;

(defmethod hole
   (:remove-edge (e)
       (setq edges 
               (remove e edges)))
   (:remove-vertex (v)
       (setq vertices (remove v (cdr vertices)))
       (setq vertices (cons (car (last vertices)) vertices)))
   (:replace-edge (e)
       (let ((elist (self . edges)))
          (dolist (edg elist)
             (cond 
                 ((edge-equal e edg)
                     (setq edges (subst e edg elist)))
                 (t nil)
                ))))
   (:replace-vert (v)
       (let ((vlist (cdr vertices)))
          (dolist (vert vlist)
             (cond 
                 ((neary-vector-equal v vert)
                     (setq vertices (subst v vert vlist)))
                 (t nil)))
          (setq vertices (cons (car (last vertices)) vertices))
     ))
   )

;;
;;
(defmethod body
   (:reset-model-vertices ()
       (setq model-vertices (mapcar #'copy-seq vertices)))
   (:change-vert (v ov)
       (replace ov v))
   (:equalize-vert (v)   ;;; eq,equal de hamaranaitameni hituyoudesu
       (let ((con-edge)
             (con-face)
             (v1 (memq v vertices))
             (v2))
         (dolist (vert vertices)
           (if (neary-vector-equal v vert) (push vert v2) nil))
         (if 
           v1   
             'eq
          (if 
             v2
              (progn 
                (setq con-edge (find-connect-edges (car v2) edges))
                (setq con-face  
                    (flatten (mapcar #'(lambda (e) (send e :faces)) con-edge)))
                (dolist (edg con-edge)
                   (send edg :replace-vert v))
                (dolist (fac con-face)
                   (send fac :replace-vert v))
                (setq vertices (subst v (car v2) vertices)) ;;okasii! BUG da!!
               )
             'not-vertices)
            )
         ))                  

   (:set-faces (f)
       (setq faces f))
   (:set-edges (e)
       (setq edges e))
   (:kill-edge (edg)
       (let* ((new-faces faces)
              (new-face)
              (new-vertices)
              (new-edges)
              (p-face (edg . pface))
              (n-face (edg . nface))
              (p-vertices (cdr (p-face . vertices)))
              (n-vertices (cdr (n-face . vertices)))
              (p-edges (p-face . edges))
              (n-edges (n-face . edges))
               )
         (cond 
           ((eq p-face n-face)
               (print '*+=~))
           ((< (abs (- (v. (p-face . normal) (n-face . normal)) 1)) *maxangle* ) 
              (progn
                  (setq new-faces (remove p-face new-faces))
                  (setq new-faces (remove n-face new-faces))
                  (setq new-face (instance *face-class*))
                  (setq new-vertices 
                               (append
                                 (cdr (rotate-list1 p-vertices (edg . nvert)))
                                 (cdr (rotate-list1 n-vertices (edg . pvert))))
                       )
                  (setq new-vertices         
                               (cons (car (last new-vertices)) new-vertices))
                  (setq new-edges
                               (append
                                 (cdr (rotate-list1 p-edges edg))
                                 (cdr (rotate-list1 n-edges edg)))
                       )
                  (send new-face :set-edges new-edges)
                  (send new-face :set-vertices new-vertices)
                  (send new-face :set-normal (p-face . normal))
                  (send new-face :set-distance (p-face . distance))
                  (dolist (e p-edges)
                     (send e :replace-face p-face new-face))
                  (dolist (e n-edges)
                     (send e :replace-face n-face new-face))
                  (setq new-faces (push new-face new-faces))
                  (send self :init :faces new-faces)
                  t))
           ((or (linerp p-face edg) (linerp n-face edg)) 
               (progn
                  (setq new-faces (remove p-face new-faces))
                  (setq new-faces (remove n-face new-faces))
                  (setq new-face (instance *face-class*))
                  (setq new-vertices 
                               (append
                                 (cdr (rotate-list1 p-vertices (edg . nvert)))
                                 (cdr (rotate-list1 n-vertices (edg . pvert))))
                       )
                  (setq new-vertices         
                               (cons (car (last new-vertices)) new-vertices))
                  (setq new-edges
                               (append
                                 (cdr (rotate-list1 p-edges edg))
                                 (cdr (rotate-list1 n-edges edg)))
                       )
                  (send new-face :set-edges new-edges)
                  (send new-face :set-vertices new-vertices)
                  (send new-face :set-normal (p-face . normal))
                  (send new-face :set-distance (p-face . distance))
                  (dolist (e p-edges)
                     (send e :replace-face p-face new-face))
                  (dolist (e n-edges)
                     (send e :replace-face n-face new-face))
                  (setq new-faces (push new-face new-faces))
                  (send self :init :faces new-faces)
                  t))
           (t nil)
             )
         ))
   (:make-vertex (v) 
     (let* ((elist (find-on-edge v edges))
            (edg (car elist)))
        (cond 
          ((equal 1 (length elist))
            (let* ((new-faces faces)
                   (p-face (send edg :pface))
                   (n-face (send edg :nface))
                   (p-vert (send edg :pvertex p-face))
                   (n-vert (send edg :nvertex p-face))
                   (copy-edge (instance edge :init))
                   (temp)
                   (new-edges))

          (send copy-edge :set-pvert v)
          (send copy-edge :set-nvert n-vert)
          (send copy-edge :set-pface p-face)
          (send copy-edge :set-nface n-face)
          (send edg :set-nvert v)
          (setq new-edges (list edg copy-edge)) 
          (if (memq edg (p-face . edges))
              (progn
                (send p-face                
                    :set-edges     
                      (flatten (subst new-edges edg (p-face . edges))))
                (setq temp  
                  (flatten 
                     (subst 
                       (list p-vert v) p-vert (cdr (p-face . vertices)))))
                (send p-face 
                    :set-vertices (cons (car (last temp)) temp)))

                (let ((hol))  
                  (dolist (h (p-face . holes))
                    (if (memq edg (h . edges)) (push h hol) nil))
                  (if (cadr hol) (print 'warning) 
                    (progn
                      (send (car hol)                
                        :set-edges     
                          (flatten 
                             (subst new-edges edg ((car hol) . edges))))
                      (setq temp  
                       (flatten (subst
                         (list p-vert v) p-vert (cdr ((car hol) . vertices)))))
                      (send (car hol) 
                         :set-vertices (cons (car (last temp)) temp)))
                      )))

          (if (memq edg (n-face . edges))
              (progn
                (send n-face                
                    :set-edges     
                      (flatten (subst new-edges edg (n-face . edges))))
                (setq temp  
                  (flatten 
                     (subst 
                       (list n-vert v) n-vert (cdr (n-face . vertices)))))
                (send n-face 
                    :set-vertices (cons (car (last temp)) temp)))

                (let ((hol))  
                  (dolist (h (n-face . holes))
                    (if (memq edg (h . edges)) (push h hol) nil))
                  (if (cadr hol) (print 'warning) 
                    (progn
                      (send (car hol)                
                        :set-edges     
                          (flatten 
                             (subst new-edges edg ((car hol) . edges))))
                      (setq temp  
                       (flatten (subst
                         (list n-vert v) n-vert (cdr ((car hol) . vertices)))))
                      (send (car hol) 
                         :set-vertices (cons (car (last temp)) temp)))
                      )))

                  (send self :init :faces (self . faces))
                  ))
             ((cadr elist) 'it-is-vertex-of-body)
             (t 'not-on-edge)
           ))
       )

   (:kill-vertex (v) 
       (let* ((new-edges (self . edges))
              (elist (find-edge2 v new-edges))
              (edge1 (pop elist))
              (edge2 (pop elist)))
         (if (eq v (edge1 . pvert))
             (send edge1 :inverse) nil)
         (if (eq v (edge2 . nvert))
             (send edge2 :inverse) nil)
         (cond 
           ((not (eq nil elist)) nil) 
           ((or 
               (and (eq (edge1 . pface) (edge2 . pface))
                    (eq (edge1 . nface) (edge2 . nface)))
               (and (eq (edge1 . pface) (edge2 . nface))
                    (eq (edge1 . nface) (edge2 . pface))))
               (progn
                  (send edge1 :replace-vertex v (edge2 . nvert))
                  (send (edge1 . pface)
                              :remove-edge edge2)
                  (send (edge1 . pface)
                              :remove-vertex v)
                  (send (edge1 . nface)
                              :remove-edge edge2)
                  (send (edge1 . nface)
                              :remove-vertex v)
                  (send self :init :faces (self . faces))
                ))
           (t (push (list edge1 edge2) bug))
          )
      )
   ))


;;
;;

(defmethod body 
   (:make-edge (vert1 vert2)
     (let* ((fac)
            (new-face1)
            (new-face2)
            (new-faces)
            (new-edges1)
            (new-edges2)
            (new-edge (instance edge :init))
            (new-verts1)
            (new-verts2)
            (verts))
        (dolist (f faces)
            (if (and (memq vert1 (f . vertices)) 
                     (memq vert2 (f . vertices)))
                (setq fac f)
                nil))
            (if fac 
                (progn
                   (setq verts (cdr (fac . vertices)))
                   (setq verts (rotate-list1 verts vert1))
                   (setq new-verts1 (memq vert2 verts))
                   (setq new-verts2 (list- verts new-verts1))
                   (setq new-verts1 (append (list vert1) 
                                            new-verts1 
                                            (list vert1)))
                   (setq new-verts2 (append (list vert2) 
                                            new-verts2 
                                            (list vert2)))
                   (dolist (edg (fac . edges))
                      (cond ((and (memq (edg . pvert) new-verts1)
                                  (memq (edg . nvert) new-verts1))
                               (push edg new-edges1))
                            ((and (memq (edg . pvert) new-verts2)
                                  (memq (edg . nvert) new-verts2))
                               (push edg new-edges2))
                            (t (print 'error)) 
                        ))
                   (send new-edge :set-pvert vert1)
                   (send new-edge :set-nvert vert2)
                   (push new-edge new-edges1)
                   (push new-edge new-edges2)
                   (setq new-edges1 (uniq (flatten new-edges1))) 
                   (setq new-edges2 (uniq (flatten new-edges2))) 

                   (setq new-face1 (instance face :init           
                                                  :normal (fac . normal)
                                                  :edges new-edges1
                                                  :vertices new-verts1))
                   (setq new-face2 (instance face :init           
                                                  :normal (fac . normal)
                                                  :edges new-edges2
                                                  :vertices new-verts2))

        ;;;; face :init ni bug ga aruyouda . koreha sono nigemiti ;;;;;

                   (send new-face1 :set-vertices new-verts1)  
                   (send new-face2 :set-vertices new-verts2)
                   (send new-face1 :reset-normal)
                   (send new-face2 :reset-normal)

                   (dolist (e new-edges1)
                      (send e :replace-face fac new-face1))
                   (dolist (e new-edges2)
                      (send e :replace-face fac new-face2))
                   (send new-edge :set-pface new-face1)
                   (send new-edge :set-nface new-face2)
                   
                   (setq new-faces 
                           (flatten  
                                (subst (list new-face1 new-face2) fac faces)))
                   (send self :init :faces new-faces)
               ) nil ))))

;;
;;

(defun list- (list1 list2) ;; list1-list2         
   (let ((result list1))
     (dolist (elm list2)
        (setq result (remove elm result)))
   result)) 
;;
;;

(defun edge-equal (edg1 edg2)
   (cond 
      ((and (equal (edg1 . pvert) (edg2 . pvert))
            (equal (edg1 . nvert) (edg2 . nvert)))
              (return-from edge-equal t))
      ((and (equal (edg1 . pvert) (edg2 . nvert))
            (equal (edg1 . nvert) (edg2 . pvert)))
              (return-from edge-equal t))
      (t nil)
    ))

;;
;;

(defun find-face (edg flist)
   (dolist (f flist)
      (dolist (e (f . edges))
         (cond 
             ((edge-equal edg e)
                 (return-from find-face f))
             (t nil)
           ))))

;;
;;

(defun rotate-list1 (l elm)
   (let* ((list1 (memq elm l))
          (list2 (list- l list1)))
     (append list1 list2)))

;;
;;

(defun rotate-list2 (l elm)
   (let* ((list1 (member elm l))
          (list2 (list- l list1)))
     (append list1 list2)))

;;
;;

(defun find-edge (v elist)
   (let* ((new-elist))
      (dolist (e elist new-elist)
         (cond 
            ((or (eq v (e . pvert))
                 (eq v (e . nvert)))
                        (push e new-elist))
             (t nil))
        )
    )
   ) 

;;
;;

(defun find-edge2 (v elist)
   (let* ((new-elist))
      (dolist (e elist new-elist)
         (cond 
            ((or (equal v (e . pvert))
                 (equal v (e . nvert)))
                        (push e new-elist))
             (t nil))
        )
    )
   ) 

;;
;;

(defmethod edge 
  (:intersect (ed)
     (let* ((v1 (v- pvert nvert))
            (v2 (v- (ed . pvert) (ed . nvert)))
            (norm (normalize-vector 
                     (v* v1 (v* v1 v2))))
            (pln (instance plane :init norm pvert))
            (int-list (send pln :intersect-edge ed))
            )
       (cond 
          ((cadr int-list) 
                 int-list)
          ((zerop
               (triangle pvert nvert (ed . pvert)))
                 (list 1.0 (ed . pvert)))
          ((zerop
               (triangle pvert nvert (ed . nvert)))
                 (list 1.0 (ed . nvert)))
          ((zerop
               (triangle (ed . pvert) (ed . nvert) pvert))
                 (list 1.0  pvert))
          ((zerop
               (triangle (ed . pvert) (ed . nvert) nvert))
                 (list 1.0  nvert))
          (t nil)
         )
        ))
  (:set-pvert (v) (setq pvert v))
  (:set-nvert (v) (setq nvert v))
  )
  )
                                        
;;
;;

(defun separate-edge (ed vlist) ;;v mast be on ed , vlist must be sorted
   (let* ((copy-edge (instance *edge-class*))
          (v)
          (new-edges))
     (send copy-edge :set-pvert (ed . pvert))
     (send copy-edge :set-nvert (ed . nvert))
     (send copy-edge :set-pface (ed . pface))
     (send copy-edge :set-pface (ed . pface))
     (cond (vlist 
             (progn
                (setq v (pop vlist))
                (send ed :set-nvert v)
                (send copy-edge :set-pvert v)
                (cons ed 
                   (separate-edge copy-edge vlist))
               ))
            (t (list ed)))
   ))  
                

;;
;;


