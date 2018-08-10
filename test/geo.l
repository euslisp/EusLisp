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

(deftest test-body+
  (let (bottom-frame
        b
        c1 c2 c3 c4 
        d1 d2 d3 d4
        )
    ;; tekitou
    ;;     (setq bottom-frame (make-cube 600 480 250))
    (setq c1 (make-cube 650 20.4 20)
          c2 (make-cube 150 20.5 20)
          c3 (make-cube 600 20.4 20)
          c4 (make-cube 320 20.2 20)
          b (make-cube 300 480 250)
          )

    (send c1 :rotate (deg2rad -39) :y)
    (send c2 :rotate (deg2rad 36) :y)
    (send c3 :rotate (deg2rad -54) :y)
    (send c4 :rotate (deg2rad 31) :y)
    (send b :rotate (deg2rad -45) :y)


    (send c1 :translate #f(-49.0 0 86) :world)
    (send c2 :translate #f(250.0 0 248) :world)
    (send c3 :translate #f(129.0 0 -35.0) :world)
    (send c4 :translate #f(-175.0 0 -200.0) :world)
    (send b :translate #f(-50.0 0 -50.0) :world)
    (setq d1 (copy-object c1)
          d2 (copy-object c2)
          d3 (copy-object c3)
          d4 (copy-object c4))

    (send-all (list c1 c2 c3 c4) :translate #f(0 225 0) :world)
    (send-all (list d1 d2 d3 d4) :translate #f(0 -225 0) :world)
    (setq bottom-frame (body+ c1 b d1 c2 d2 c3 d3 c4 d4)) ;; <= here, body+ fails
    (setf (get bottom-frame :face-color) :dimgray)
    (setf (get bottom-frame :weight) 100)
    bottom-frame
    ))

(deftest test-vector-angle
  (assert (and (eps= (vector-angle (float-vector 0 0 1) (float-vector 0 0 1)) 0.0)
               (not (c-isnan (vector-angle (float-vector 0 0 1) (float-vector 0 0 1))))))
  (assert (and (eps= (vector-angle (float-vector 0 0 1) (float-vector 0 0 -1)) pi)
               (not (c-isnan (vector-angle (float-vector 0 0 1) (float-vector 0 0 -1))))))
  (assert (eps=
           (vector-angle (float-vector 0 0 1)
                         (send (make-coords :rpy (list 0 -0.2 0)) :rotate-vector (float-vector 0 0 1)))
           0.2))
  (assert (eps=
           (vector-angle (float-vector 0 0 1)
                         (send (make-coords :rpy (list 0 -0.2 0)) :rotate-vector (float-vector 0 0 1))
                         (float-vector 0 1 0))
           -0.2))
  )

(deftest test-face-distance
  (let* ((f
          (instance face :init :vertices
                    '(#f(100 100 0) #f(-100 100 0) #f(-100 -100 0) #f(100 -100 0))))
         )
    (assert (eps= (send f :distance (float-vector 0 0 100)) 100.0))
    (assert (eps= (send f :distance (float-vector 200 0 0)) 100.0))
    (assert (eps= (send f :distance (float-vector 200 0 100)) (norm #f(100 100))))
    ))

(run-all-tests)
(exit)

