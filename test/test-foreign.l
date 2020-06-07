(eval-when (load eval) (load "test-foreign.module_l"))
(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defun check-func (f)
  (warning-message 3 "~A [paramtypes] ~A, [result] ~A~%"
		   (send f :pname)
		   (cdr (assoc 'paramtypes (send (send f :func) :slots)))
		   (cdr (assoc 'resulttype (send (send f :func) :slots)))))

(defun assert-read-line-eps= (s ret)
  (let (l)
    (setq l (read-line s))
    (warning-message 2 "check read-line ~A -> ~A = ~A~%" l  (subseq l 2) ret)
    (assert (eps= (read-from-string (subseq l 2)) ret))))

(defun assert-read-line-string= (s ret &optional (f #'identity))
  (let (l)
    (setq l (read-line s))
    (warning-message 2 "check read-line ~A -> ~A = ~A~%" l l ret)
    (assert (string= l ret))))

(defun assert-read-funcall= (f ret)
  (let ()
    (warning-message 2 "check ~A -> ~A = ~A~%" f (eval f) ret)
    (assert (eps= (eval f) ret))))

(deftest test-pointer-size
  (format t "~%;;;; pointer size check ;;;;~%")

  (format t "pointer size ~D ~D~%"
	  lisp::sizeof-* (get-size-pointer))
  (assert (= lisp::sizeof-* (get-size-pointer)))

  (format t "double size ~D ~D~%"
	  lisp::sizeof-double (get-size-double))
  (assert (= lisp::sizeof-double (get-size-double)))

  (format t "long integer size ~D ~D~%"
	  (cadr (assoc :long lisp::sizeof-types))
	  (get-size-long))
  (assert (= (cadr (assoc :long lisp::sizeof-types)) (get-size-long)))

  (format t "integer size ~D ~D~%"
	  lisp::sizeof-int (get-size-int))
  (assert (= lisp::sizeof-int (get-size-int)))

  (format t "float size ~D ~D~%"
	  lisp::sizeof-float (get-size-float32))
  (assert (= lisp::sizeof-float (get-size-float32)))

  (format t "eusinteger size ~D ~D~%"
	  lisp::sizeof-* (get-size-eusfloat))
  (assert (= lisp::sizeof-* (get-size-eusfloat)))

  (format t "eusfloat size ~D ~D~%"
	  lisp::sizeof-* (get-size-eusinteger))
  (assert (= lisp::sizeof-* (get-size-eusinteger)))
  )

(deftest test-multiple-arguments-passing
  (format t "~%multiple arguments passing~%")
  (format t "expected result~%")
  (format t "100 101 102
103 104 105
1000.000000 1010.000000 1020.000000 1030.000000
1040.000000 1050.000000 1060.000000 1070.000000
2080.000000 2090.000000
206 207
test-testd = 1.23456
~%")
  (format t "exec in eus~%")
  (format t "test-testd = ~A~%"
        (setq ret (test-testd 100 101 102
            103 104 105
            1000.0 1010.0 1020.0 1030.0
            1040.0 1050.0 1060.0 1070.0
            2080.0 2090.0
            206 207)))
  (when (not (and (memq :word-size=32 *features*) (memq :arm *features*)))
  (assert (eps= 1.23456 ret))
  )

  ;;
  (check-func 'test-testd)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (test-testd 100 101 102 103 104 105 1000.000000 1010.000000 1020.000000 1030.000000 1040.000000 1050.000000 1060.000000 1070.000000 2080.000000 2090.000000 206 207)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "100 101 102")
  (assert-read-line-string= f "103 104 105")
  (assert-read-line-string= f "1000.000000 1010.000000 1020.000000 1030.000000")
  (assert-read-line-string= f "1040.000000 1050.000000 1060.000000 1070.000000")
  (assert-read-line-string= f "2080.000000 2090.000000")
  (assert-read-line-string= f "206 207")

  (format t "exec in eus~%")
  (format t "test-testf = ~A~%"
        (setq ret (test-testf 100 101 102
            103 104 105
            1000.0 1010.0 1020.0 1030.0
            1040.0 1050.0 1060.0 1070.0
            2080.0 2090.0
            206 207)))
  (assert (eps= 1.23456 ret))
  ;;
  (check-func 'test-testf)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (test-testf 100 101 102 103 104 105 1000.000000 1010.000000 1020.000000 1030.000000 1040.000000 1050.000000 1060.000000 1070.000000 2080.000000 2090.000000 206 207)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "100 101 102")
  (assert-read-line-string= f "103 104 105")
  (assert-read-line-string= f "1000.000000 1010.000000 1020.000000 1030.000000")
  (assert-read-line-string= f "1040.000000 1050.000000 1060.000000 1070.000000")
  (assert-read-line-string= f "2080.000000 2090.000000")
  (assert-read-line-string= f "206 207")

  (format t "exec in eus~%")
  (format t "test-testfd = ~A~%"
        (setq ret (test-testfd 100 101 102
            103 104 105
            1000.0 1010.0 1020.0 1030.0
            1040.0 1050.0 1060.0 1070.0
            2080.0 2090.0 2100.0 2110.0
            206 207)))
  (assert (= 123456 ret))
  ;;
  (when (not (eq (read (unix::piped-fork "gcc -dumpmachine") nil 'arm-linux-gnueabi) 'arm-linux-gnueabi))
  (check-func 'test-testfd)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (test-testfd 100 101 102 103 104 105 1000.000000 1010.000000 1020.000000 1030.000000 1040.000000 1050.000000 1060.000000 1070.000000 2080.000000 2090.000000  2100.000000 2110.000000 206 207)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "100 101 102")
  (assert-read-line-string= f "103 104 105")
  (assert-read-line-string= f "1000.000000 1010.000000 1020.000000 1030.000000")
  (assert-read-line-string= f "1040.000000 1050.000000 1060.000000 1070.000000")
  (assert-read-line-string= f "2080.000000 2090.000000 2100.000000 2110.000000")
  (assert-read-line-string= f "206 207")
  )
  )

(deftest test-int-test
  (format t "~%~%int-test~%")
  (format t "expected result~%")
  (format t "0:        1 1~%")
  (format t "0:        2 2~%")
  (format t "0:        3 3~%")
  (format t "0:        4 4~%")
  (format t "~%int-test(success, exec in eus)~%")
  (check-func 'int-test)
  (int-test 0 1 2 3 4)
  ;;
  (check-func 'int-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (int-test 0 1 2 3 4)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "0:        1 1")
  (assert-read-line-string= f "0:        2 2")
  (assert-read-line-string= f "0:        3 3")
  (assert-read-line-string= f "0:        4 4")
  )

(deftest test-long-test
  (format t "~%~%long-test~%")
  (format t "expected result~%")
  (format t "0:        1 1~%")
  (format t "0:        2 2~%")
  (format t "0:        3 3~%")
  (format t "0:        4 4~%")
  (format t "~%long-test(success, exec in eus)~%")
  (check-func 'long-test)
  (long-test 0 1 2 3 4)
  ;;
  (check-func 'long-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (long-test 0 1 2 3 4)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "0:        1 1")
  (assert-read-line-string= f "0:        2 2")
  (assert-read-line-string= f "0:        3 3")
  (assert-read-line-string= f "0:        4 4")
  )

(deftest test-eusinteger-test
  (format t "~%~%eusinteger-test~%")
  (format t "expected result~%")
  (format t "0:        1 1~%")
  (format t "0:        2 2~%")
  (format t "0:        3 3~%")
  (format t "0:        4 4~%")
  (format t "~%eusinteger-test(success, exec in eus)~%")
  (check-func 'eusinteger-test)
  (eusinteger-test 0 1 2 3 4)
  ;;
  (check-func 'eusinteger-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (eusinteger-test 0 1 2 3 4)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "0:        1 1")
  (assert-read-line-string= f "0:        2 2")
  (assert-read-line-string= f "0:        3 3")
  (assert-read-line-string= f "0:        4 4")
  )

(deftest test-float-test
  (format t "~%~%float-test~%")
  (format t "expected result~%")
  (format t "0: 1.000000e-01 ..~%")
  (format t "0: 2.000000e-01 ..~%")
  (format t "0: 3.000000e-01 ..~%")
  (format t "0: 4.000000e-01 ..~%")
  (format t "~%float-test(success, exec in eus)~%")
  (check-func 'float-test)
  (float-test 0 0.1 0.2 0.3 0.4)
  (format t "~%float1-test(success, exec in eus)~%")
  (check-func 'float1-test)
  (float1-test 0 0.1 0.2 0.3 0.4)
  (format t "~%float2-test(fail, exec in eus)~%")
  (check-func 'float2-test)
  (float2-test 0 0.1 0.2 0.3 0.4)
  (format t "~%float3-test(depend on architecture, exec in eus)~%")
  (check-func 'float3-test)
  (float3-test 0 0.1 0.2 0.3 0.4)

  ;;
  (check-func 'float-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (float-test 0 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
  (assert-read-line-eps= f 0.1)
  (assert-read-line-eps= f 0.2)
  (assert-read-line-eps= f 0.3)
  (assert-read-line-eps= f 0.4)

  (when (memq :word-size=32 *features*)
    (check-func 'float1-test)
    (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (float1-test 0 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
    (assert-read-line-eps= f 0.1)
    (assert-read-line-eps= f 0.2)
    (assert-read-line-eps= f 0.3)
    (assert-read-line-eps= f 0.4))
  )

(deftest test-double-test
  (format t "~%~%double-test~%")
  (format t "expected result~%")
  (format t "1: 1.000000e-01 ..~%")
  (format t "1: 2.000000e-01 ..~%")
  (format t "1: 3.000000e-01 ..~%")
  (format t "1: 4.000000e-01 ..~%")
  (format t "~%double-test(success, exec in eus)~%")
  (check-func 'double-test)
  (double-test 1 0.1 0.2 0.3 0.4)
  (format t "~%double1-test(fail, exec in eus)~%")
  (check-func 'double1-test)
  (double1-test 1 0.1 0.2 0.3 0.4)
  (format t "~%double2-test(fail, exec in eus)~%")
  (check-func 'double2-test)
  (double2-test 1 0.1 0.2 0.3 0.4)
  (format t "~%double3-test(depend on architecture, exec in eus)~%")
  (check-func 'double3-test)
  (double3-test 1 0.1 0.2 0.3 0.4)

  ;;
  (when (not (eq (read (unix::piped-fork "gcc -dumpmachine") nil 'arm-linux-gnueabi) 'arm-linux-gnueabi))
  (check-func 'double-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (double-test 1 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
  (assert-read-line-eps= f 0.1)
  (assert-read-line-eps= f 0.2)
  (assert-read-line-eps= f 0.3)
  (assert-read-line-eps= f 0.4)
  )
  (when (not (and (memq :word-size=32 *features*) (memq :arm *features*)))
  (check-func 'double3-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (double3-test 1 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
  (assert-read-line-eps= f 0.1)
  (assert-read-line-eps= f 0.2)
  (assert-read-line-eps= f 0.3)
  (assert-read-line-eps= f 0.4)
  )
  )

(deftest test-eusfloat-test
  (format t "~%~%eusfloat-test~%")
  (format t "expected result~%")
  (format t "0: 1.000000e-01 ..~%")
  (format t "0: 2.000000e-01 ..~%")
  (format t "0: 3.000000e-01 ..~%")
  (format t "0: 4.000000e-01 ..~%")
  (format t "~%eusfloat-test(fail, exec in eus)~%")
  (check-func 'eusfloat-test)
  (eusfloat-test 0 0.1 0.2 0.3 0.4)
  (format t "~%eusfloat1-test(success, exec in eus)~%")
  (check-func 'eusfloat1-test)
  (eusfloat1-test 0 0.1 0.2 0.3 0.4)
  (format t "~%eusfloat2-test(success, exec in eus)~%")
  (check-func 'eusfloat2-test)
  (eusfloat2-test 0 0.1 0.2 0.3 0.4)
  (format t "~%eusfloat3-test(success, exec in eus)~%")
  (check-func 'eusfloat3-test)
  (eusfloat3-test 0 0.1 0.2 0.3 0.4)

  ;;
  (when (memq :word-size=32 *features*)
    (check-func 'eusfloat-test)
    (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (eusfloat-test 0 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
    (assert-read-line-eps= f 0.1)
    (assert-read-line-eps= f 0.2)
    (assert-read-line-eps= f 0.3)
    (assert-read-line-eps= f 0.4))

  (check-func 'eusfloat1-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (eusfloat1-test 0 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
  (assert-read-line-eps= f 0.1)
  (assert-read-line-eps= f 0.2)
  (assert-read-line-eps= f 0.3)
  (assert-read-line-eps= f 0.4)

  (when (memq :word-size=64 *features*)
    (check-func 'eusfloat2-test)
    (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (eusfloat2-test 0 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
    (assert-read-line-eps= f 0.1)
    (assert-read-line-eps= f 0.2)
    (assert-read-line-eps= f 0.3)
    (assert-read-line-eps= f 0.4)

    (check-func 'eusfloat3-test)
    (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (eusfloat3-test 0 0.1 0.2 0.3 0.4)(exit 0))'" *eusdir*)))
    (assert-read-line-eps= f 0.1)
    (assert-read-line-eps= f 0.2)
    (assert-read-line-eps= f 0.3)
    (assert-read-line-eps= f 0.4))

  )

(deftest test-integer-vector
  (setq iv (integer-vector 0 100 10000 1000000 100000000 10000000000))

  (format t "~%iv-test~%")
  (format t "size = 6
0: 0 0
1: 100 64
2: 10000 2710
3: 1000000 F4240
4: 100000000 5F5E100
5: 10000000000 2540BE400~%")
  (format t "~%iv-test(fail, exec in eus)~%")
  (check-func 'iv-test)
  (iv-test (length iv) iv)

  (format t "~%lv-test~%")
  (format t "size = 6
0: 0 0
1: 100 64
2: 10000 2710
3: 1000000 F4240
4: 100000000 5F5E100
5: 10000000000 2540BE400~%")
  (format t "~%lv-test(exec in eus)~%")
  (check-func 'lv-test)
  (lv-test (length iv) iv)

  ;;
  (check-func 'lv-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (setq iv (integer-vector 0 100 10000 1000000 100000000 10000000000))(lv-test (length iv) iv)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "size = 6")
  (assert-read-line-string= f "0: 0 0")
  (assert-read-line-string= f "1: 100 64")
  (assert-read-line-string= f "2: 10000 2710")
  (assert-read-line-string= f "3: 1000000 F4240")
  (assert-read-line-string= f "4: 100000000 5F5E100")
  (when (memq :word-size=64 *features*)
    (assert-read-line-string= f "5: 10000000000 2540BE400"))

  (format t "~%eiv-test~%")
  (format t "size = 6
0: 0 0
1: 100 64
2: 10000 2710
3: 1000000 F4240
4: 100000000 5F5E100
5: 10000000000 2540BE400~%")
  (format t "~%lv-test(exec in eus)~%")
  (check-func 'eiv-test)
  (eiv-test (length iv) iv)

  ;;
  (check-func 'eiv-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (setq iv (integer-vector 0 100 10000 1000000 100000000 10000000000))(eiv-test (length iv) iv)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f "size = 6")
  (assert-read-line-string= f "0: 0 0")
  (assert-read-line-string= f "1: 100 64")
  (assert-read-line-string= f "2: 10000 2710")
  (assert-read-line-string= f "3: 1000000 F4240")
  (assert-read-line-string= f "4: 100000000 5F5E100")
  (when (memq :word-size=64 *features*)
    (assert-read-line-string= f "5: 10000000000 2540BE400"))
  )

(deftest test-float-vector
  (setq fv (float-vector 0.1 0.2 0.3 0.5 0.7))

  (format t "~%fv-test~%")
  (format t "size = 5
0: 1.000000e-01 3FB9999999999998
1: 2.000000e-01 3FC9999999999998
2: 3.000000e-01 3FD3333333333330
3: 5.000000e-01 3FE0000000000000
4: 7.000000e-01 3FE6666666666664~%")
  (format t "~%fv-test(exec in eus)~%")
  (check-func 'fv-test)
  (fv-test (length fv) fv)

  (format t "~%dv-test~%")
  (format t "size = 5
0: 1.000000e-01 3FB9999999999998
1: 2.000000e-01 3FC9999999999998
2: 3.000000e-01 3FD3333333333330
3: 5.000000e-01 3FE0000000000000
4: 7.000000e-01 3FE6666666666664~%")
  (format t "~%dv-test(exec in eus)~%")
  (check-func 'dv-test)
  (dv-test (length fv) fv)

  ;;
  (when (memq :word-size=64 *features*)
    (check-func 'dv-test)
    (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (setq fv (float-vector 0.1 0.2 0.3 0.5 0.7))(dv-test (length fv) fv)(exit 0))'" *eusdir*)))
    (assert-read-line-string= f "size = 5")
    (assert-read-line-string= f "0: 1.000000e-01 3FB9999999999998")
    (assert-read-line-string= f "1: 2.000000e-01 3FC9999999999998")
    (assert-read-line-string= f "2: 3.000000e-01 3FD3333333333330")
    (assert-read-line-string= f "3: 5.000000e-01 3FE0000000000000")
    (assert-read-line-string= f "4: 7.000000e-01 3FE6666666666664"))

  ;;
  (format t "~%efv-test~%")
  (format t "size = 5
0: 1.000000e-01 3FB9999999999998
1: 2.000000e-01 3FC9999999999998
2: 3.000000e-01 3FD3333333333330
3: 5.000000e-01 3FE0000000000000
4: 7.000000e-01 3FE6666666666664~%")
  (format t "~%efv-test(exec in eus)~%")
  (check-func 'efv-test)
  (efv-test (length fv) fv)

  ;;
  (check-func 'efv-test)
  (when (memq :word-size=64 *features*)
    (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (setq fv (float-vector 0.1 0.2 0.3 0.5 0.7))(efv-test (length fv) fv)(exit 0))'" *eusdir*)))
    (assert-read-line-string= f "size = 5")
    (assert-read-line-string= f "0: 1.000000e-01 3FB9999999999998")
    (assert-read-line-string= f "1: 2.000000e-01 3FC9999999999998")
    (assert-read-line-string= f "2: 3.000000e-01 3FD3333333333330")
    (assert-read-line-string= f "3: 5.000000e-01 3FE0000000000000")
    (assert-read-line-string= f "4: 7.000000e-01 3FE6666666666664"))
  )

(deftest test-string-test
  (setq str "input : test64 string")
  (format t "~%str-test~%")
  ;;(format t "expected result~%")
  (format t "input string : ~S~%" str)
  (format t "~%str-test(exec in eus)~%")
  (check-func 'str-test)
  (str-test (length str) str)
  ;;
  (check-func 'str-test)
  (setq f (piped-fork (format nil "eusg ~A/test/test-foreign.module_l '(progn (setq str \"input : test64 string\")(str-test (length str) str)(exit 0))'" *eusdir*)))
  (assert-read-line-string= f (format nil "size = ~d" (length str)))
  (dotimes (i (length str))
    (assert-read-line-string= f (format nil "~d: ~c ~x" i (elt str i) (elt str i)))
    )
  )

(deftest test-return-float
  (format t "~%return float test~%")
  (format t "expected result~%")
  (format t "  ret-float ~8,8e~%" (+ 0.55555 133.0))
  (format t "~%ret-float(exec in eus)~%")
  (format t "  ret-float ~8,8e~%" (ret-float 0.55555 133.0))
  ;;
  (check-func 'ret-float)
  (assert-read-funcall= '(ret-float 0.55555 133.0) (+ 0.55555 133.0))
  (assert (eps= (ret-float 0.55555 133.0) (+ 0.55555 133.0)))
  )

(deftest test-return-double
  (format t "~%return double test~%")
  (format t "expected result~%")
  (format t "  ret-double ~8,8e~%" (+ 0.55555 133.0))
  (format t "~%ret-double(exec in eus)~%")
  (format t "  ret-double ~8,8e~%" (ret-double 0.55555 133.0))
  ;;
  (when (not (and (memq :word-size=32 *features*) (memq :arm *features*)))
  (check-func 'ret-double)
  (assert-read-funcall= '(ret-double 0.55555 133.0) (+ 0.55555 133.0))
  (assert (eps= (ret-double 0.55555 133.0) (+ 0.55555 133.0)))
  )
  )

(deftest test-return-eusfloat
  (format t "~%return eusfloat test~%")
  (format t "expected result~%")
  (format t "  ret-eusfloat ~8,8e~%" (+ 0.55555 133.0))
  (format t "~%ret-eusfloat(exec in eus)~%")
  (format t "  ret-eusfloat ~8,8e~%" (ret-eusfloat 0.55555 133.0))
  ;;
  (check-func 'ret-eusfloat)
  (assert-read-funcall= '(ret-eusfloat 0.55555 133.0) (+ 0.55555 133.0))
  (assert (eps= (ret-eusfloat 0.55555 133.0) (+ 0.55555 133.0)))
  )

(deftest test-return-int
  (format t "~%return int test~%")
  (format t "expected result~%")
  (format t "  ret-int ~D~%" (+ 123 645000))
  (format t "~%ret-int(exec in eus)~%")
  (format t "  ret-int ~D~%" (ret-int 123 645000))

  (check-func 'ret-int)
  (assert (= (ret-int 123 645000) (+ 123 645000)))
  )

(deftest test-return-long
  (format t "~%return long test~%")
  (format t "expected result~%")
  (format t "  ret-long ~D~%" (+ 123 645000))
  (format t "~%ret-long(exec in eus)~%")
  (format t "  ret-long ~D~%" (ret-long 123 645000))

  (check-func 'ret-long)
  (assert (= (ret-long 123 645000) (+ 123 645000)))
  )

(deftest test-return-eusinteger
  (format t "~%return eusinteger test~%")
  (format t "expected result~%")
  (format t "  ret-eusinteger ~D~%" (+ 123 645000))
  (format t "~%ret-eusinteger(exec in eus)~%")
  (format t "  ret-eusinteger ~D~%" (ret-eusinteger 123 645000))

  (check-func 'ret-eusinteger)
  (assert (= (ret-eusinteger 123 645000) (+ 123 645000)))
  )

#|
;; ret-int
;; ret-short
;; ret-char

;; callback function
(defun-c-callable LISP-IFUNC () :integer
  (format t "LISP-INTFUNC is called, return ~D~%" 1234)
  1234)
;;
(format t "~%callback function test(integer)~%")
(format t "  callback function is set~%")
(set-ifunc (pod-address 'LISP-IFUNC))
(format t "  expected result: LISP-INTFUNC is called, return 1234~%")
(format t "  call-ifunc = ~A~%" (call-ifunc))

(defun-c-callable LISP-FFUNC ((i0 :integer) (i1 :integer) (i2 :integer)
                              (i3 :integer) (i4 :integer) (i5 :integer)
                              (f0 :float) (f1 :float) (f2 :float) (f3 :float)
                              (f4 :float) (f5 :float) (f6 :float) (f7 :float)
                              (f8 :float) (f9 :float)
                              (i6 :integer) (i7 :integer)) :float
  (format t "LISP-FFUNC is called~%")
  (format t "~A ~A ~A~%" i0 i1 i2)
  (format t "~A ~A ~A~%" i3 i4 i5)
  (format t "~A ~A ~A ~A~%" f0 f1 f2 f3)
  (format t "~A ~A ~A ~A~%" f4 f5 f6 f7)
  (format t "~A ~A~%" f8 f9)
  (format t "~A ~A~%" i6 i7)
  (format t "return ~A~%" 0.12345)
  0.12345)
(format t "~%callback function test(float)~%")
(format t "  callback function is set~%")
(set-ffunc (pod-address 'LISP-FFUNC))
(format t "  expected result: LISP-FFUNC is called
  100 101 102
  103 104 105
  1000.0 1010.0 1020.0 1030.0
  1040.0 1050.0 1060.0 1070.0
  2080.0 2090.0
  206 207
  return 0.12345~%")
(format t "call-ffunc = ~A~%" (call-ffunc))
|#

(eval-when (load eval)
  (run-all-tests)
  (exit))
