(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(in-package "GEO")
(defun face-normal-vector (vertices)
  (let* ((v1 (first vertices)) (v2) (vlist (rest vertices))
         (v (float-vector 0 0 0))
         (normal (float-vector 0 0 0)))
    (while vlist
      (setq v2 (pop vlist))
      (v+ (v* v1 v2 v) normal normal)
      (setq v1 v2))
    (setq v2 (car vertices))
    (v+ (v* v1 v2 v) normal normal)
    (normalize-vector normal normal)) )

(defmethod polygon
  (:reset-normal ()
                 (setq normal (face-normal-vector (rest vertices))
                       distance (- (v. normal (car vertices))))))
(in-package "USER")

(warning-message 1 "test-body+ is not working on eusgl ...
-- outer circuit not found in (body+ c1 b d1 c2 d2 c3 d3 c4 d4), exitting...
-- See jskeus/irteus/geo.l~%")
(warning-message 1 "test-vector-angle is not working on eusgl ...
-- undefined function c-isnan in (not (c-isnan (vector-angle (float-vector 0 0 1) (float-vector 0 0 1)))), exitting...
-- See jskeus/irteus/geo.l~%")

(deftest test-face-distance
  (let* ((f
          (instance face :init :vertices
                    '(#f(100 100 0) #f(-100 100 0) #f(-100 -100 0) #f(100 -100 0))))
         )
    (assert (eps= (send f :distance (float-vector 0 0 100)) 100.0))
    (assert (eps= (send f :distance (float-vector 200 0 0)) 100.0))
    (assert (eps= (send f :distance (float-vector 200 0 100)) (norm #f(100 100))))
    ))

(eval-when (load eval)
  (run-all-tests)
  (exit))
