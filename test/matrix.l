(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest rotation-matrix
  (let (rot axis angle rot-angle)
    (setq rot (make-coords :rpy #f(-1.220e-08 -5.195e-09 1.333e-09)))
    (setq axis (cadr (rotation-angle (send rot :rot))))
    (print axis *error-output*)
    (assert (null axis) "small rotatoin-angle")

    (setq rot (make-coords :rpy #f(-1.220e-08 -5.195e-09 -1.333e-09)))
    (setq axis (cadr (rotation-angle (send rot :rot))))
    (print axis *error-output*)
    (assert (null axis) "small rotatoin-angle")

    (setq angle 0.5 axis #f(1.0 0.0 0.0))
    (setq rot (make-coords :axis axis :angle angle))
    (print (send rot :rot) *error-output*)
    (setq rot-angle (rotation-angle (send rot :rot)))
    (print (list rot-angle (list angle axis) (norm axis) (v. (cadr rot-angle) axis)) *error-output*)
    (assert (eps= (car rot-angle) angle) "check angle of rotation-angle")
    (assert (eps-v= (cadr rot-angle) axis) "check axis rotatoin-angle")
    (assert (not (c-isnan (norm (cadr rot-angle)))) "check nan is not contained in axis of rotation-angle"))

    (setq angle 0.00141 axis #f(-0.684209 0.536652 0.493825))
    (setq rot (make-coords :axis axis :angle angle))
    (print (send rot :rot) *error-output*)
    (setq rot-angle (rotation-angle (send rot :rot)))
    (print (list rot-angle (list angle axis) (norm axis) (v. (cadr rot-angle) axis)) *error-output*)
    (assert (eps= (car rot-angle) angle) "check angle of rotation-angle")
    (assert (eps-v= (cadr rot-angle) axis) "check axis rotatoin-angle"))

    (dotimes (i 1000)
      (setq axis (normalize-vector (random-vector 1.0)))
      (setq angle (- (random 2pi) pi))
      (setq rot (make-coords :axis axis :angle angle))
      (setq rot-angle (rotation-angle (send rot :rot)))
      (print (list rot-angle (list angle axis)) *error-output*)
      (cond ((and (< angle 1e-4) (null rot-angle))
             (assert (null rot-angle) "check angle of rotation-angle"))
            ((> (v. (cadr rot-angle) axis) 0)
             (assert (eps= (car rot-angle) angle) "check angle of rotation-angle")
             (assert (eps-v= (cadr rot-angle) axis) "check axis rotatoin-angle"))
            (t
             (assert (eps= (car rot-angle) (- angle)) "check angle of rotation-angle")
             (assert (eps-v= (cadr rot-angle) (v- axis)) "check axis rotatoin-angle"))
        ))
    ))

;;;;;;;;;;;;;;;;
;; Test functions for matrix concatenation
;;;;;;;;;;;;;;;;
(defun make-random-matrix
  (row-dim column-dim &key (random-range 1e10))
  "Make matrix with given row dimension and column dimension.
   Component of matrix is random value."
  (make-matrix row-dim column-dim
               (mapcar #'(lambda (row)
                           (mapcar #'(lambda (column) (random random-range)) (make-list column-dim)))
                       (make-list row-dim))))

(defun make-random-matrix-list
  (length
   &key (same-row-p nil) (same-column-p nil)
        (random-max-dim 100))
  "Make matrix list with given length.
   Component of matrix is random value and dimensions are random.
   random-max-dim is max dimensions to be checked."
  (let ((row-dim (if same-row-p (1+ (random random-max-dim))))
        (col-dim (if same-column-p (1+ (random random-max-dim)))))
    (mapcar
     #'(lambda (x)
         (make-random-matrix
          (if same-row-p row-dim (1+ (random random-max-dim)))
          (if same-column-p col-dim (1+ (random random-max-dim)))))
     (make-list length))))

;; Naive implementation of concatenate matrix for comparing values.
(defun concatenate-matrix-column-naive-impl
  (&rest args)
  (if (> (length args) 2)
      (concatenate-matrix-column-naive-impl
       (car args)
       (apply #'concatenate-matrix-column-naive-impl (cdr args)))
    (let* ((mat0 (car args)) (mat1 (cadr args))
           (mat0-row-dim (array-dimension mat0 0))
           (mat1-row-dim (array-dimension mat1 0))
           (col-dim (array-dimension mat0 1))
           (con-mat1 (make-matrix (+ mat0-row-dim mat1-row-dim) col-dim)))
      (dotimes (row-index0 mat0-row-dim)
        (dotimes (column-index col-dim)
          (setf (aref con-mat1 row-index0 column-index) (aref mat0 row-index0 column-index))))
      (dotimes (row-index1 mat1-row-dim)
        (dotimes (column-index col-dim)
          (setf (aref con-mat1 (+ mat0-row-dim row-index1) column-index) (aref mat1 row-index1 column-index))))
      con-mat1)))

(defun concatenate-matrix-row-naive-impl
  (&rest args)
  (if (> (length args) 2)
      (concatenate-matrix-row-naive-impl
       (car args)
       (apply #'concatenate-matrix-row-naive-impl (cdr args)))
    (let* ((mat0 (car args)) (mat1 (cadr args))
           (mat0-col-dim (array-dimension mat0 1))
           (mat1-col-dim (array-dimension mat1 1))
           (row-dim (array-dimension mat0 0))
           (con-mat1 (make-matrix row-dim (+ mat0-col-dim mat1-col-dim))))
      (dotimes (row-index row-dim)
        (dotimes (column-index mat0-col-dim)
          (setf (aref con-mat1 row-index column-index) (aref mat0 row-index column-index))))
      (dotimes (row-index row-dim)
        (dotimes (column-index mat1-col-dim)
          (setf (aref con-mat1 row-index (+ mat0-col-dim column-index)) (aref mat1 row-index column-index))))
      con-mat1)))

(defun concatenate-matrix-diagonal-naive-impl
  (&rest args)
  (if (> (length args) 2)
      (concatenate-matrix-diagonal-naive-impl
       (car args)
       (apply #'concatenate-matrix-diagonal-naive-impl(cdr args)))
    (let* ((mat0 (car args)) (mat1 (cadr args))
           (mat0-row-dim (array-dimension mat0 0))
           (mat0-col-dim (array-dimension mat0 1))
           (mat1-row-dim (array-dimension mat1 0))
           (mat1-col-dim (array-dimension mat1 1))
           (con-mat1 (make-matrix (+ mat0-row-dim mat1-row-dim) (+ mat0-col-dim mat1-col-dim))))
      (dotimes (row-index mat0-row-dim)
        (dotimes (column-index mat0-col-dim)
          (setf (aref con-mat1 row-index column-index) (aref mat0 row-index column-index))))
      (dotimes (row-index mat1-row-dim)
        (dotimes (column-index mat1-col-dim)
          (setf (aref con-mat1 (+ mat0-row-dim row-index) (+ mat0-col-dim column-index)) (aref mat1 row-index column-index))))
      con-mat1)))

;; this should be defined in somewhere else
(defun m= (m1 m2)
  (v= (array-entity m1) (array-entity m2)))
(defun eps-m= (m1 m2 &optional (eps *epsilon*))
  (eps-v= (array-entity m1) (array-entity m2) eps))

;; Test functions
(deftest test-matrix-concatenate-noargs ;; concatinate without args should return null
  (assert (null (concatenate-matrix-column)))
  (assert (null (concatenate-matrix-row)))
  (assert (null (concatenate-matrix-diagonal))))

(deftest test-matrix-concatenate-single-matrix ;; concatenate with one args should retun input
  (dotimes (i 10)
    (let* ((random-max-dim 100)
           (mat-row-dim (1+ (random random-max-dim)))
           (mat-column-dim (1+ (random random-max-dim)))
           (mat (make-random-matrix mat-row-dim mat-column-dim)))
      (assert (m= mat (concatenate-matrix-column mat)))
      (assert (m= mat (concatenate-matrix-row mat)))
      (assert (m= mat (concatenate-matrix-diagonal mat))))
    ))

(deftest test-matrix-concatenate-multiple-matrices ;; concatenate test
  (dotimes (i 10)
    (let* ((matrix-list-length (+ 2 (random 5)))
           (mats (make-random-matrix-list matrix-list-length)))
      (assert (m= (apply #'concatenate-matrix-diagonal mats)
                  (apply #'concatenate-matrix-diagonal-naive-impl mats))))
    (let* ((matrix-list-length (+ 2 (random 5)))
           (mats (make-random-matrix-list matrix-list-length :same-row-p t)))
      (assert (m= (apply #'concatenate-matrix-row mats)
                  (apply #'concatenate-matrix-row-naive-impl mats))))
    (let* ((matrix-list-length (+ 2 (random 5)))
           (mats (make-random-matrix-list matrix-list-length :same-column-p t)))
      (assert (m= (apply #'concatenate-matrix-column mats)
                  (apply #'concatenate-matrix-column-naive-impl mats))))
    ))

(run-all-tests)
(exit)
