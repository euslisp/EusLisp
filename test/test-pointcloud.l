(require :unittest "lib/llib/unittest.l")

#-(or :x86_64 :aarch64)
(setq *temp-eps* 1e-2) ;; 5 significant figure of 1000mm

#+(or :x86_64 :aarch64)
(setq *temp-eps* 1e-9) ;; 12 significant figure of 1000mm

(init-unit-test)

(defun points-size-check (make-element-func &key (size 10))
  (let ((pt-p (instance pointcloud :init
                        :points (funcall make-element-func)))
        (pt-pc (instance pointcloud :init
                         :points (funcall make-element-func)
                         :colors (funcall make-element-func)))
        (pt-pn (instance pointcloud :init
                         :points  (funcall make-element-func)
                         :normals (funcall make-element-func)))
        (pt-pcn (instance pointcloud :init
                          :points  (funcall make-element-func)
                          :colors  (funcall make-element-func)
                          :normals (funcall make-element-func))))
    (points-size-check-impl pt-p pt-pc pt-pn pt-pcn :size size)
    ))

(defun points-size-check-impl (pt-p pt-pc pt-pn pt-pcn &key (size 10))
  (assert (= (send pt-p :size) size))
  (assert (equal (array-dimensions (send pt-p :points)) (list size 3)))
  (assert (null (send pt-p :colors)))
  (assert (null (send pt-p :normals)))

  (assert (= (send pt-pc :size) size))
  (assert (equal (array-dimensions (send pt-pc :points)) (list size 3)))
  (assert (equal (array-dimensions (send pt-pc :colors)) (list size 3)))
  (assert (null (send pt-pc :normals)))

  (assert (= (send pt-pn :size) size))
  (assert (equal (array-dimensions (send pt-pn :points)) (list size 3)))
  (assert (null (send pt-pn :colors)))
  (assert (equal (array-dimensions (send pt-pn :normals)) (list size 3)))

  (assert (= (send pt-pcn :size) size))
  (assert (equal (array-dimensions (send pt-pcn :points)) (list size 3)))
  (assert (equal (array-dimensions (send pt-pcn :colors)) (list size 3)))
  (assert (equal (array-dimensions (send pt-pcn :normals)) (list size 3)))

  (let ((plist (send pt-p :point-list)))
    (assert (and (= (length plist) size)
                 (listp plist))))
  (let ((clist (send pt-p :color-list)))
    (assert (null clist)))
  (let ((nlist (send pt-p :normal-list)))
    (assert (null nlist)))

  (let ((plist (send pt-pc :point-list)))
    (assert (and (= (length plist) size)
                 (listp plist))))
  (let ((clist (send pt-pc :color-list)))
    (assert (and (= (length clist) size)
                 (listp clist))))
  (let ((nlist (send pt-pc :normal-list)))
    (assert (null nlist)))

  (let ((plist (send pt-pn :point-list)))
    (assert (and (= (length plist) size)
                 (listp plist))))
  (let ((clist (send pt-pn :color-list)))
    (assert (null clist)))
  (let ((nlist (send pt-pn :normal-list)))
    (assert (and (= (length nlist) size)
                 (listp nlist))))

  (let ((plist (send pt-pcn :point-list)))
    (assert (and (= (length plist) size)
                 (listp plist))))
  (let ((clist (send pt-pcn :color-list)))
    (assert (and (= (length clist) size)
                 (listp clist))))
  (let ((nlist (send pt-pcn :normal-list)))
    (assert (and (= (length nlist) size)
                 (listp nlist))))
  )

(defun filter-check (pt &key (keyword :key) func)
  (let ((org-size (send pt :size))
        (filtered-pt (send pt :filter keyword func :create t)))
    (assert (= (send pt :size) org-size))
    (warn ";; filtered ~D points~%" (- org-size (send filtered-pt :size)))
    (case keyword
      (:key
       (dolist (p (send filtered-pt :point-list))
         (assert (funcall func p))))
      (:ckey
       (dolist (c (send filtered-pt :color-list))
         (assert (funcall func c))))
      (:nkey
       (dolist (n (send filtered-pt :normal-list))
         (assert (funcall func n))))
      (:pckey
       (mapc #'(lambda (p c)
                 (assert (funcall func p c)))
             (send filtered-pt :point-list)
             (send filtered-pt :color-list)))
      (:pnkey
       (mapc #'(lambda (p n)
                 (assert (funcall func p n)))
             (send filtered-pt :point-list)
             (send filtered-pt :normal-list)))
      (:pcnkey
       (mapc #'(lambda (p c n)
                 (assert (funcall func p c n)))
             (send filtered-pt :point-list)
             (send filtered-pt :color-list)
             (send filtered-pt :normal-list)))
      (t
       (warn ";; unknown keyword ~A~%" keyword)
       (assert nil)))
    ))

(defun filter-check-create ()
  (let ((p (make-random-pointcloud :num 20 :with-normal t :with-color t))
        pt ret)
    (setq pt (instance pointcloud :init
                       :points (append (list (float-vector 1000 1000 1000)) (send p :point-list))
                       :colors (append (list (float-vector 1.11 2.22 3.33)) (send p :point-list))
                       :normals (append (list (float-vector 4.44 5.55 6.66)) (send p :point-list))))
    (assert (= (send pt :size) 21))
    (setq ret (send pt :filter :key #'(lambda (p) (equal p #f(1000 1000 1000))) :create t))
    (assert (= (send pt :size) 21))
    (assert (= (send ret :size) 1))
    (let ((cl (send ret :color-list)))
      (assert (= (length cl) 1))
      (equal (car cl) (float-vector 1.11 2.22 3.33)))
    (let ((nl (send ret :normal-list)))
      (assert (= (length nl) 1))
      (equal (car nl) (float-vector 4.44 5.55 6.66)))

    (send pt :filter :key #'(lambda (p) (equal p #f(1000 1000 1000))))
    (setq ret pt)
    (assert (= (send ret :size) 1))
    (let ((cl (send ret :color-list)))
      (assert (= (length cl) 1))
      (equal (car cl) (float-vector 1.11 2.22 3.33)))
    (let ((nl (send ret :normal-list)))
      (assert (= (length nl) 1))
      (equal (car nl) (float-vector 4.44 5.55 6.66)))
    ))

(defun convert-to-world-check ()
   (let* ((*origin-p* (float-vector 500 1000 1500))
          (*point*
           (instance pointcloud :init :points (list *origin-p*) :point-size 10))
          (*bcoords* (make-coords :pos (float-vector 100 200 300) :rpy (list 0.1 0.2 0.3)))
          (*base* (make-cascoords :pos (float-vector 200 -100 -150) :rpy (list 0.2 -0.2 0.1)))
          )
     (send *base* :assoc *point*)
     (let ((p (send *point* :convert-to-world :create t)))
       (assert (eps-v= (car (send *point* :point-list)) *origin-p* *temp-eps*)) ;; original does not move
       (assert (eps-v= (car (send p :point-list)) *origin-p* *temp-eps*))
       )

     (send *base* :transform *bcoords*)
     (let ((p (send *point* :convert-to-world :create t)))
       (assert (eps-v= (car (send *point* :point-list)) *origin-p* *temp-eps*))  ;; original does not move
       (assert (eps-v=
                (car (send p :point-list))
                (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
                *temp-eps*))
       )
     (let ((pt (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))))
       (send *point* :convert-to-world :create nil)
       (assert (eps-v=
                (car (send *point* :point-list))
                (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
                *temp-eps*))
       (assert (eps-v=
                (car (send *point* :point-list)) ;; original moved
                pt
                *temp-eps*))
       (assert (eps-v= (send *point* :worldpos) (float-vector 0 0 0) *temp-eps*))
       (assert (eps-v= (array-entity (send *point* :worldrot))
                       (float-vector 1 0 0 0 1 0 0 0 1) *temp-eps*))
       )
     ))

(defun move-origin-to-check ()
  (let* ((*origin-p* (float-vector 500 1000 1500))
         (*point*
          (instance pointcloud :init :points (list *origin-p*) :point-size 10))
         (*bcoords* (make-coords :pos #f(100 200 300) :rpy (list 0.1 0.2 0.3)))
         (*ccoords* (make-coords :pos #f(0     0 1000) :rpy (list 0.2 -0.2 0.1)))
         )
    (when (member :move-origin-to (send *point* :methods))
      (send *point* :move-origin-to *bcoords*)
      (assert
       (eps-v=
        (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
        *origin-p*
        *temp-eps*))
      (assert
       (eps-v=
        (send *bcoords* :transform-vector (car (send *point* :point-list)))
        (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
        *temp-eps*))

      (send *point* :move-origin-to *ccoords*)
      (assert
       (eps-v=
        (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
        *origin-p*
        *temp-eps*))
      (assert
       (eps-v=
        (send *ccoords* :transform-vector (car (send *point* :point-list)))
        (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
        *temp-eps*))

      (send *point* :move-origin-to (make-coords))
      (assert
       (eps-v=
        (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
        *origin-p*
        *temp-eps*))

      (setq *point*
            (instance pointcloud :init :points (list *origin-p*) :point-size 10))
      (let ((base (make-cascoords :pos (float-vector -300 -200 -100) :rpy (list 0.3 -0.2 0.1))))
        (send base :assoc *point*)
        (send base :transform
              (make-coords :pos (float-vector 400 -800 1200) :rpy (list 0.4 0.3 0.2)))
        (assert
         (eps-v=
          (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
          (float-vector 792.732209445 539.4908242525 2397.9448709116)
          *temp-eps*))

        (send *point* :move-origin-to *ccoords*)
        (assert
         (eps-v=
          (send (send *point* :worldcoords) :transform-vector (car (send *point* :point-list)))
          (float-vector 792.732209445 539.4908242525 2397.9448709116)
          *temp-eps*))
        (assert
         (eps-v= (send *point* :worldpos) (send *ccoords* :pos) *temp-eps*))
        (assert
         (eps-v=
          (array-entity (send *point* :worldrot))
          (array-entity (send *ccoords* :rot)) *temp-eps*))
        )
      )
    ))
#|
(send pt :transform-points cds :create t)
(send pt :append (list ...))
|#

(deftest test-pointcloud-create
  ;;
  (points-size-check #'(lambda () (make-matrix 10 3)))
  ;;
  (points-size-check #'(lambda () (let (l) (dotimes (i 10) (push (float-vector 0 0 0) l)) l)))
  ;;
  (points-size-check-impl
   (make-random-pointcloud :num 100)
   (make-random-pointcloud :num 100 :with-color t)
   (make-random-pointcloud :num 100 :with-normal t)
   (make-random-pointcloud :num 100 :with-color t :with-normal t)
   :size 100)
  )

(deftest test-pointcloud-filter
  ;;
  (filter-check (make-random-pointcloud :num 40)
                :keyword :key :func #'(lambda (p) (> (elt p 0) 0)))
  (filter-check (make-random-pointcloud :num 40 :with-color t)
                :keyword :ckey :func #'(lambda (c) (> (elt c 0) 0)))
  (filter-check (make-random-pointcloud :num 40 :with-normal t)
                :keyword :nkey :func #'(lambda (n) (> (elt n 0) 0)))
  (filter-check (make-random-pointcloud :num 40 :with-color t)
                :keyword :pckey :func #'(lambda (p c) (> (elt c 0) 0)))
  (filter-check (make-random-pointcloud :num 40 :with-normal t)
                :keyword :pnkey :func #'(lambda (p n) (> (elt n 0) 0)))
  (filter-check (make-random-pointcloud :num 40 :with-color t :with-normal t)
                :keyword :pcnkey :func #'(lambda (p c n) (> (elt p 0) 0)))
  ;;
  (filter-check-create)
  )

(deftest test-pointcloud-convert
  ;;
  (convert-to-world-check)
  ;;
  (move-origin-to-check)
  )

(run-all-tests)
(exit)
