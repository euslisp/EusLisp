(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defun eps-matrix= (m1 m2 &optional (eps *epsilon*))
   (eps= (distance (array-entity m1) (array-entity m2)) 0.0 eps))

(deftest mathtest
  (let (m1 m2 m3 m4 m5 m6 m7 r u s v val vec)
    ;;
    (assert (eps-matrix= (inverse-matrix #2f((2 5)(1 3))) #2f((3 -5) (-1 2))) "invere matrix")
    (assert (eps-matrix= (diagonal #f(1 2)) #2f((1 0) (0 2))) "check diagonal")

    (assert (eps-matrix= (minor-matrix #2f((1 2 3)(4 5 6)(7 8 9)) 2 3) #2f((1.0 2.0) (4.0 5.0))) "minor matrix")

    (assert (eps= (atan2 1 0) pi/2) "atan2 0 1")
    (assert (eps= (atan2 0 1)    0) "atan2 1 0")
    (assert (eps= (atan2 1 1) (/ pi 4)) "atan2 1 1")

    ;;
    (assert (null (<= 0 (+ -0.2 0.1))) "(<= 0 (+ -0.2 0.1))")
    (assert (<= 0 (+ -0.2 0.3)) "(<= 0 (+ -0.2 0.3))")
    (assert (null (<  0 (+ -0.2 0.1))) "(< 0 (+ -0.2 0.1))")
    (assert (<  0 (+ -0.2 0.3)) "(< 0 (+ -0.2 0.3))")
    (assert (null (>= 0  (- 0.2 0.1))) "(>= 0 (- 0.2 0.1))")
    (assert (>= 0  (- 0.2 0.3)) "(>= 0 (- 0.2 0.3))")
    (assert (null (>  0  (- 0.2 0.1))) "(> 0 (- 0.2 0.1))")
    (assert (>  0  (- 0.2 0.3)) "(> 0 (- 0.2 0.3))")

    ;; see section 14 of jmanual.pdf
    ;; eps<= num1 num2 tolerance -> num1 < num2+torelance
    (assert (null (eps<= 0 -0.2 0.1)) "(eps<= 0 -0.2 0.1)")
    (assert (eps<= 0 -0.2 0.3) "(eps<= 0 -0.2 0.3)")
    ;; eps< num1 num2 tolerance -> num1 < num2-torelance
    (assert (null (eps<  0 0.2 0.3)) "(eps< 0 0.2 0.3)")
    (assert (eps<  0 0.2 0.1) "(eps< 0 0.2 0.1)")
    ;; eps>= num1 num2 tolerance -> num1 > num2-torelance
    (assert (null (eps>= 0  0.2 0.1)) "(eps>= 0 0.2 0.1)")
    (assert (eps>= 0  0.2 0.3) "(eps>= 0 0.2 0.3)")
    ;; eps> num1 num2 tolerance -> num1 > num2+torelance
    (assert (null (eps>  0  -0.2 0.3)) "(eps> 0 -0.2 0.3)")
    (assert (eps>  0  -0.2 0.1) "(eps> 0 0.2 0.1)")
    ;; eps<>
    (assert (eps<> 0 0.2 0.1) "(eps<> 0 0.2 0.1)")
    (assert (null (eps<> 0 0.2 0.3)) "(eps<> 0 0.2 0.3)")
    ;; eps==
    (assert (eps= 0 0.2 0.3) "(eps= 0 0.2 0.3)")
    (assert (null (eps= 0 0.2 0.1)) "(eps= 0 0.2 0.1)")

    (assert (outer-product-matrix #f(1 2 3)) #2f((0.0 -3.0 2.0) (3.0 0.0 -1.0) (-2.0 1.0 0.0)) "outer product matrix")

    ;; quaternion
    (assert (eps-matrix= (quaternion2matrix #f(7 9 5 1)) #2f((104.0 76.0 88.0) (104.0 -8.0 -116.0) (-52.0 136.0 -56.0))) "quaternion2matrix") ;;  the norm is not 1 warning is ok
    ;; http://www.wolframalpha.com/input/?i=quaternion++-1j%2B3i%2B4-3k
    (assert (eps-v= (scale (/ 1.0 0.169031) (matrix2quaternion #2f((0.428571 0.514286 -0.742857) (-0.857143 -0.028571 -0.514286) (-0.285714 0.857143 0.428571)))) #f(4 3 -1 -3)) "matrix2quaternion")

    (setq m1 (rotate-matrix (rotate-matrix (rotate-matrix (unit-matrix 3) 0.2 :x) 0.4 :y) 0.6 :z))
    (assert (eps-v= (matrix2quaternion m1) #f(0.925754 0.151891 0.159933 0.307131)) "matrix2quaternion")
    (assert (eps-matrix= (quaternion2matrix #f(0.925754 0.151891 0.159933 0.307131)) m1) "quaternion2matrix")
    (assert (eps-matrix= (quaternion2matrix (matrix2quaternion m1)) m1) "matrix <-> quaternion")

    ;; matrix log
    (assert (eps-matrix= (matrix-exponent (matrix-log m1)) m1) "matrix log/exponent")

    ;; pseudo-inverse
    (setq m2 #2f((1 1 1 1)(5 7 7 9))) ;; http://help.matheass.eu/en/Pseudoinverse.html
    (assert (eps-matrix= (m* m2 (pseudo-inverse m2)) (unit-matrix 2)) "psesudo-inverse")

    ;; sr inverse
    (assert (eps-matrix= (m* m1 (sr-inverse m1)) (scale-matrix 0.5 (unit-matrix 3))) "sr-inverse")
    (assert (not (eps-matrix= (m* m2 (sr-inverse m2)) (unit-matrix 2))) "sr-inverse")
    
    ;; matrix-determinant
    (assert (eps= (manipulability m1) 1.0) "manipulability")

    ;; random
    (assert (v= #i(123456 789012) *random-state*) "initial *random-state*")
    (progn
      (assert (= 0 (random 10)) "random 10 (1)")
      (assert (= 3 (random 10)) "random 10 (2)")
      (assert (= 7 (random 10)) "random 10 (3)")
      (assert (= 2 (random 10)) "random 10 (4)")
      (assert (= 7 (random 10)) "random 10 (5)"))

    (setq *random-state* #i(123456 789012))
    (progn
      (assert (eps= 0.593532 (random 10.0) 0.01) "random 10.0 (1)")
      (assert (eps= 3.59535 (random 10.0) 0.01) "random 10.0 (2)")
      (assert (eps= 7.68644 (random 10.0) 0.01) "random 10.0 (3)")
      (assert (eps= 2.44015 (random 10.0) 0.01) "random 10.0 (4)")
      (assert (eps= 7.26136 (random 10.0) 0.01) "random 10.0 (5)"))

    (setq *random-state* #i(123456 789012))
    (assert (v= (make-random-state) #i(123456 789012)) "(make-random-state)")
    (assert (v= (make-random-state nil) #i(123456 789012)) "(make-random-state nil)")
    (assert (v= (make-random-state #i(11111 22222)) #i(11111 22222)) "(make-random-state #i(11111 22222))")
    (assert (not (v= (make-random-state t) #i(123456 789012))) "(make-random-state t)")
    (assert (= 0 (random 10 (make-random-state #i(123456 789012)))) "(random 10 (make-random-state #i(123456 789012)))")

    ;; eigen decompose
    ;; http://en.wikipedia.org/wiki/Eigendecomposition_of_a_matrix#Example
    (setq m3 #2f((1 0)( 1 3)))
    (setq val (car (eigen-decompose m3)) vec (cadr (eigen-decompose m3)))
    (assert (eps-matrix= (m* m3 vec) (m* vec (diagonal val))) "eigen-decompose")
    (setq m3 #2f((9.656790e+06 -2.024883e+05 5.475222e+05 -73324.1) ;;Sent: Tuesday, June 27, 2006 9:56 PM Subject: Re: 特異値と固有値
                 (-2.024883e+05 9.210039e+06 -3.152789e+05 -1.061633e+05)
                 (5.475222e+05 -3.152789e+05 1.053183e+07 11188.9)
                 (-73324.1 -1.061633e+05 11188.9 1.115641e+07)))
    (setq val (car (eigen-decompose m3)) vec (cadr (eigen-decompose m3)))
    (assert (eps-matrix= (m* m3 vec) (m* vec (diagonal val))) "eigen-decompose large")

    ;; normalize-vector
    (assert (eps-v= (normalize-vector #f(1 2 3)) #f(0.267261 0.534522 0.801784)) "normalize-vector")
    (assert (eps-v= (normalize-vector #f(0 0 0)) #f(0 0 0)) "normalize-vector #f(0 0 0)")

    ;; sv-solve
    ;; sv-dcompose http://en.wikipedia.org/wiki/Singular_value_decomposition#Example
    (setq m4 #2f((1 0 0 0 2)(0 0 3 0 0)(0 0 0 0 0)(0 4 0 0 0)))
    (setq r (sv-decompose m4))
    (setq u (elt r 0) s (elt r 1) v (elt r 2))
    (assert (eps-matrix= m4 (m* (m* u (diagonal s)) (transpose v))) "sv-decompose")
    
    ;; memory error check?
    (dotimes (i 10000) (sv-decompose #2f((1 2 3) (4 5 6)(7 8 9))))
    (dotimes (i 10000) (ql-decompose #2f((1 2 3) (4 5 6)(7 8 9))))
    ;; lu-solve?

    ;; http://pythonhosted.org/ad/linalg.html
    (setq m5 #2f((1 2 1)(4 6 3)(9 8 2)))
    (assert (eps-v= (lu-solve m5 (lu-decompose m5) #f( 3 2 1)) #f(-7 11 -12)) "lu-solve") ;; this changes m5
    (setq m5 #2f((1 2 1)(4 6 3)(9 8 2)))
    (assert (eps-v= (lu-solve2 m5 (lu-decompose2 m5) #f( 3 2 1)) #f(-7 11 -12)) "lu-solve2") ;; this changes m5
    (setq m5 #2f((1 2 1)(4 6 3)(9 8 2)))
    (assert (eps-v= (sv-solve m5 #f( 3 2 1)) #f(-7 11 -12)) "sv-solve")

    ;; matrix-determinant http://en.wikipedia.org/wiki/Determinant
    (assert (eps= (matrix-determinant #2f((-2  2 -3)(-1 1 3)(2 0 -1))) 18.0) "matrix-determinant")

    ;; qr-decompose (car) is eigenvalue , what is cdr?
    (assert (eps-v= #f(3 1 2) (car (qr-decompose #2f((2 0 1)(0 2 0)(1 0 2))))) "qr-decompose")
    ;; ql-decompose
    (setq m6 #2f((2 0 1)(0 2 0)(1 0 2))) 
    (setq val (car (ql-decompose m6)) vec (cadr (ql-decompose m6)))
    (assert (eps-matrix= (m* m6 vec) (m* vec (diagonal val))) "ql-decompose")
    ))

(run-all-tests)
(exit)
