(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defun eps-matrix= (m1 m2 &optional (eps *epsilon*))
   (eps= (distance (array-entity m1) (array-entity m2)) 0.0 eps))


    (warning-message 1 "the part of mathtest is not  working on eusgl ...
-- undefined function diagnoal, minor-matrix, atan2, outer-product-matrix, quaternion, matrix-log, pseudo-inverse, sr-inverse, manipulability, eien decompose, sv/ql solve, lu-solve2, matrix-determinant, qr/ql-decompose
-- See jskeus/irteus/mathtest.l~%")
(deftest mathtest
  (let (m1 m2 m3 m4 m5 m6 m7 r u s v val vec)
    ;;
    (assert (eps-matrix= (inverse-matrix #2f((2 5)(1 3))) #2f((3 -5) (-1 2))) "invere matrix")

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

    ;; random
    (assert (v= #i(123456 789012) *random-state*) "initial *random-state*")
#+(or :alpha :irix6 :x86_64 :aarch64)
    (progn
      (assert (= 0 (random 10)) "random 10 (1)")
      (assert (= 3 (random 10)) "random 10 (2)")
      (assert (= 7 (random 10)) "random 10 (3)")
      (assert (= 2 (random 10)) "random 10 (4)")
      (assert (= 7 (random 10)) "random 10 (5)"))
#-(or :alpha :irix6 :x86_64 :aarch64)
    (progn
      (assert (= 3 (random 10)) "random 10 (1)")
      (assert (= 2 (random 10)) "random 10 (2)")
      (assert (= 2 (random 10)) "random 10 (3)")
      (assert (= 3 (random 10)) "random 10 (4)")
      (assert (= 1 (random 10)) "random 10 (5)"))

    (setq *random-state* #i(123456 789012))
#+(or :alpha :irix6 :x86_64 :aarch64)
    (progn
      (assert (eps= 0.593532 (random 10.0) 0.01) "random 10.0 (1)")
      (assert (eps= 3.59535 (random 10.0) 0.01) "random 10.0 (2)")
      (assert (eps= 7.68644 (random 10.0) 0.01) "random 10.0 (3)")
      (assert (eps= 2.44015 (random 10.0) 0.01) "random 10.0 (4)")
      (assert (eps= 7.26136 (random 10.0) 0.01) "random 10.0 (5)"))
#-(or :alpha :irix6 :x86_64 :aarch64)
    (progn
      (assert (eps= 3.1918 (random 10.0) 0.01) "random 10.0 (1)")
      (assert (eps= 2.74391 (random 10.0) 0.01) "random 10.0 (2)")
      (assert (eps= 2.06693 (random 10.0) 0.01) "random 10.0 (3)")
      (assert (eps= 3.35141 (random 10.0) 0.01) "random 10.0 (4)")
      (assert (eps= 1.27564 (random 10.0) 0.01) "random 10.0 (5)"))

    (setq *random-state* #i(123456 789012))
    (assert (v= (make-random-state) #i(123456 789012)) "(make-random-state)")
    (assert (v= (make-random-state nil) #i(123456 789012)) "(make-random-state nil)")
    (assert (v= (make-random-state #i(11111 22222)) #i(11111 22222)) "(make-random-state #i(11111 22222))")
    (assert (not (v= (make-random-state t) #i(123456 789012))) "(make-random-state t)")
#+(or :alpha :irix6 :x86_64 :aarch64)
    (assert (= 0 (random 10 (make-random-state #i(123456 789012)))) "(random 10 (make-random-state #i(123456 789012)))")
#-(or :alpha :irix6 :x86_64 :aarch64)
    (assert (= 3 (random 10 (make-random-state #i(123456 789012)))) "(random 10 (make-random-state #i(123456 789012)))")

    ;; normalize-vector
    (assert (eps-v= (normalize-vector #f(1 2 3)) #f(0.267261 0.534522 0.801784)) "normalize-vector")
    (assert (eps-v= (normalize-vector #f(0 0 0)) #f(0 0 0)) "normalize-vector #f(0 0 0)")

    ;; http://pythonhosted.org/ad/linalg.html
    (setq m5 #2f((1 2 1)(4 6 3)(9 8 2)))
    (assert (eps-v= (lu-solve m5 (lu-decompose m5) #f( 3 2 1)) #f(-7 11 -12)) "lu-solve") ;; this changes m5
    (setq m5 #2f((1 2 1)(4 6 3)(9 8 2)))

    ;; test for 1+/1-
    ;; https://github.com/euslisp/EusLisp/pull/312
    (labels ((== (a b)
                 (cond ((integerp a)
                        (= a b))
                       ((and (< a 0) (>= a 0)) ;; check if a is nan
                        nil)
                       (t
                        (eps= a (float b)))))
             (1+-test (flag) ;; flag should be 1
                      (assert (== flag 1) (format nil "flag = ~A~%" flag))
                      (assert (== (* (1+ flag) pi/2) 3.14)
                              (format nil "(* (1+ flag) pi/2) -> ~A~%"
                                      (* (1+ flag) pi/2)))
                      (assert (== (1+ flag) 2)
                              (format nil "(1+ flag) -> ~A~%" (1+ flag)))
                      (assert (== (1+ (float flag)) 2)
                              (format nil "(1+ (float flag)) -> ~A~%" (1+ (float flag))))
                      (assert (== (1+ 1.5) 2.5)
                              (format nil "(1+ 1.5) -> ~A~%" (1+ 1.5)))
                      (assert (== (1+ 1) 2)
                              (format nil "(1+ 1) -> ~A~%" (1+ 1)))
                      (assert (== (1+ (float 3)) 4)
                              (format nil "(1+ (float 3)) -> ~A~%" (1+ (float 3))))
                      (assert (== (1+ (floor 4.5)) 5)
                              (format nil "(1+ (floor 4.5)) -> ~A~%" (1+ (floor 4.5))))
                      ;; 1-
                      (assert (== flag 1) (format nil "flag = ~A~%" flag))
                      (assert (== (* (1- (- flag)) pi/2) -3.14)
                              (format nil "(* (1- flag) pi/2) -> ~A~%"
                                      (* (1- (- flag)) pi/2)))
                      (assert (== (1- flag) 0)
                              (format nil "(1- flag) -> ~A~%" (1- flag)))
                      (assert (== (1- (float flag)) 0)
                              (format nil "(1- (float flag)) -> ~A~%" (1- (float flag))))
                      (assert (== (1- 1.5) 0.5)
                              (format nil "(1- 1.5) -> ~A~%" (1- 1.5)))
                      (assert (== (1- 1) 0)
                              (format nil "(1- 1) -> ~A~%" (1- 1)))
                      (assert (== (1- (float 3)) 2)
                              (format nil "(1- (float 3)) -> ~A~%" (1- (float 3))))
                      (assert (== (1- (floor 4.5)) 3)
                              (format nil "(1- (floor 4.5)) -> ~A~%" (1- (floor 4.5))))
                      ))
            (1+-test 1)
            (1+-test 1.0))

    ;; abs https://github.com/euslisp/EusLisp/issues/274
    (assert (= (abs (- 1234)) 1234) "abs")
    (assert (= (abs (- #x30000000)) #x30000000) "abs(#x30000000)")
    (assert (= (abs (- (+ (expt 2 32) 1234))) (+ (expt 2 32) 1234)) "abs(2^32)")
    (assert (= (abs (- (+ (expt 2 48) 1234))) (+ (expt 2 48) 1234)) "abs(2^47)")
    (assert (= (abs (- (+ (expt 2 64) 1234))) (+ (expt 2 64) 1234)) "abs(2^64)")
    (format *error-output* "~A ~A~%" (+ (expt 2 32) 1234) (abs (+ (expt 2 32) 1234)))
    ))

(eval-when (load eval)
  (run-all-tests)
  (exit))
