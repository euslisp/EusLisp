(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(in-package "GEO")
;; redefined to use normalize-vector defined in irteus(?)
;; this requrie to avoid outer circuit not found in (body+ c1 b d1 c2 d2 c3 d3 c4 d4)
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

;; test intersection3
;; https://github.com/euslisp/jskeus/pull/561
(deftest triangulation-intersection3 ()
  (let ((l0 (make-line (float-vector -120.0 -30.0 0.0) (float-vector 15.0 0.0 0.0)))
	(l1 (make-line (float-vector -15.0 120.0 0.0)  (float-vector -15.0 0.0 0.0)))
        res-p res-n)
    (setq res-p (geo::line-intersection3 (l0 . pvert) (l0 . nvert) (l1 . pvert) (l1 . nvert) 0.00001)) ;; -> (0.777778 1.05556)
    (setq res-n (geo::line-intersection3 (l1 . pvert) (l1 . nvert) (l0 . pvert) (l0 . nvert) 0.00001)) ;; -> (1.05556 0.777778)
    (warn ";;; intersection3 (res-p) ~A~%" res-p)
    (warn ";;; intersection3 (res-n) ~A~%" res-n)

    (assert (eps= (elt res-p 0) (elt res-n 1)))
    (assert (eps= (elt res-p 1) (elt res-n 0)))
    ))

(deftest check-primitive-body ()
  (let (p-body)
    (dolist (b (list (make-cube 100 100 100)
		     (make-cylinder 100 100)
		     (make-icosahedron 100)
		     (make-gdome (make-icosahedron 100))
		     (make-solid-of-revolution (list #f(50  0 100)
						     #f(100 0 100)
						     #f(100 0   0)
						     #f(50  0   0)
						     ))
		     (make-cone #f(0 0 100) 100)
		     (let ((v1 #f(0 0 0))
			   (v2 #f(100 0 0))
			   (v3 #f(0 100 0))
			   (v4 #f(0 0 100)))
		       (make-body-from-vertices (list (list v1 v2 v3)
						      (list v4 v2 v1)
						      (list v4 v3 v2)
						      (list v4 v1 v3))))
		     ))
      (format t "body ~A, csg ~A~%" b (send b :csg))
      ;; check body must be equal to original body
      (setq p-body (remove-duplicates (send-all (send b :faces) :body)))
      (assert (= (length p-body) 1) "length of unique primitive body must be 1")
      (assert (equal (elt p-body 0) b) "primitive body must be identical to body")
      ))
  )

(eval-when (load eval)
  (run-all-tests)
  (exit))
