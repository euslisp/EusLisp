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

    (warning-message 1 "the part of rotation-matrix is not  working on eusgl ...
-- undefined function c-isnan, exitting...~%")
    ;; (assert (not (c-isnan (norm (cadr rot-angle)))) "check nan is not contained in axis of rotation-angle"))

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
      (if (= (mod i 100) 0) (print (list rot-angle (list angle axis)) *error-output*))
      (cond ((and (< angle 1e-4) (null rot-angle))
             (assert (null rot-angle) "check angle of rotation-angle ~A ~A" rot-angle (list angle axis)))
            ((> (v. (cadr rot-angle) axis) 0)
             (assert (eps= (car rot-angle) angle) "check angle of rotation-angle ~A ~A" rot-angle (list angle axis))
             (assert (eps-v= (cadr rot-angle) axis) "check axis rotatoin-angle ~A ~A" rot-angle (list angle axis)))
            (t
             (assert (eps= (car rot-angle) (- angle)) "check angle of rotation-angle ~A ~A" rot-angle (list angle axis))
             (assert (eps-v= (cadr rot-angle) (v- axis)) "check axis rotatoin-angle ~A ~A" rot-angle (list angle axis)))
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

;; this should be defined in somewhere else
(defun m= (m1 m2)
  (v= (array-entity m1) (array-entity m2)))
(defun eps-m= (m1 m2 &optional (eps *epsilon*))
  (eps-v= (array-entity m1) (array-entity m2) eps))

(warning-message 1 "test-matrix-concatenate-noargs, test-matrix-concatenate-single-matrix, test-matrix-concatenate-multiple-matrices are not working on eusgl ...
-- undefined function concatenate-matrix , exitting...
-- See jskeus/irteus/matrix.l~%")


(eval-when (load eval)
  (run-all-tests)
  (exit))
