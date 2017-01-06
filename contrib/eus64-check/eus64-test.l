(unless (boundp '*testmod*)
  (setq *testmod* (load-foreign "test_foreign.so"))
  (defforeign float-test *testmod* "float_test" (:integer :float32 :float32 :float32 :float32) :integer)
  (defforeign float2-test *testmod* "float_test" (:integer :double :double :double :double) :integer)
  (defforeign float3-test *testmod* "float_test" () :integer)
  (defforeign double-test *testmod* "double_test" (:integer :double :double :double :double) :integer)
  (defforeign double2-test *testmod* "double_test" (:integer :float32 :float32 :float32 :float32) :integer)
  (defforeign double3-test *testmod* "double_test" () :integer)
  (defforeign iv-test *testmod* "iv_test" () :integer)
  (defforeign lv-test *testmod* "lv_test" () :integer)
  (defforeign fv-test *testmod* "fv_test" () :integer)
  (defforeign dv-test *testmod* "dv_test" () :integer)
  (defforeign str-test *testmod* "str_test" () :integer)
  (defforeign int-test *testmod* "int_test" () :integer)
  (defforeign ret-float *testmod* "ret_float" () :float32)
  (defforeign ret-double *testmod* "ret_double" () :float)
  (defforeign ret-long *testmod* "ret_long" () :integer)
  
  (defforeign set-ifunc *testmod* "set_ifunc" (:integer) :integer)
  (defforeign set-ffunc *testmod* "set_ffunc" (:integer) :integer)

  (defforeign test-testd *testmod* "test_testd" (:integer :integer :integer
                                                          :integer :integer :integer
                                                          :double :double :double :double
                                                          :double :double :double :double
                                                          :double :double
                                                          :integer :integer) :float)
  (defforeign call-ifunc *testmod* "call_ifunc" () :integer)
  (defforeign call-ffunc *testmod* "call_ffunc" () :float)

  (defforeign get-size-pointer *testmod* "get_size_of_pointer" () :integer)
  (defforeign get-size-float32 *testmod* "get_size_of_float32" () :integer)
  (defforeign get-size-double  *testmod* "get_size_of_double" ()  :integer)
  (defforeign get-size-long    *testmod* "get_size_of_long" () :integer)
  (defforeign get-size-int     *testmod* "get_size_of_int" () :integer)
  )

(format t "~%;;;; pointer size check ;;;;~%")

(format t "pointer size ~D ~D~%"
	lisp::sizeof-* (get-size-pointer))
(format t "double size ~D ~D~%"
	lisp::sizeof-double (get-size-double))
(format t "long integer size ~D ~D~%"
	(cadr (assoc :long lisp::sizeof-types))
	(get-size-long))
(format t "integer size ~D ~D~%"
	lisp::sizeof-int (get-size-int))
(format t "float size ~D ~D~%"
	lisp::sizeof-float (get-size-float32))

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
        (test-testd 100 101 102
            103 104 105
            1000.0 1010.0 1020.0 1030.0
            1040.0 1050.0 1060.0 1070.0
            2080.0 2090.0
            206 207))

(format t "~%~%float-test~%")
(format t "expected result~%")
(format t "0: 1.000000e-01 ..~%")
(format t "0: 2.000000e-01 ..~%")
(format t "0: 3.000000e-01 ..~%")
(format t "0: 4.000000e-01 ..~%")
(format t "~%float-test(success, exec in eus)~%")
(float-test 0 0.1 0.2 0.3 0.4)
(format t "~%float2-test(fail, exec in eus)~%")
(float2-test 0 0.1 0.2 0.3 0.4)
(format t "~%float3-test(depend on architecture, exec in eus)~%")
(float3-test 0 0.1 0.2 0.3 0.4)

(format t "~%~%double-test~%")
(format t "expected result~%")
(format t "1: 1.000000e-01 ..~%")
(format t "1: 2.000000e-01 ..~%")
(format t "1: 3.000000e-01 ..~%")
(format t "1: 4.000000e-01 ..~%")
(format t "~%double-test(success, exec in eus)~%")
(double-test 1 0.1 0.2 0.3 0.4)
(format t "~%double2-test(fail, exec in eus)~%")
(double2-test 1 0.1 0.2 0.3 0.4)
(format t "~%double3-test(depend on architecture, exec in eus)~%")
(double3-test 1 0.1 0.2 0.3 0.4)

(setq iv (integer-vector 0 100 10000 1000000 100000000 10000000000))
#|
(format t "~%iv-test~%")
(format t "expected result~%")
(format t "exec in eus64~%")
(iv-test (length iv) iv)
|#
(format t "~%lv-test~%")
(format t "size = 6
0: 0 0
1: 100 64
2: 10000 2710
3: 1000000 F4240
4: 100000000 5F5E100
5: 10000000000 2540BE400~%")
(format t "~%lv-test(exec in eus)~%")
(lv-test (length iv) iv)

(setq fv (float-vector 0.1 0.2 0.3 0.5 0.7))
#|
(format t "~%fv-test~%")
(format t "exec in eus64~%")
(fv-test (length fv) fv)
|#

(format t "~%dv-test~%")
(format t "size = 5
0: 1.000000e-01 3FB9999999999998
1: 2.000000e-01 3FC9999999999998
2: 3.000000e-01 3FD3333333333330
3: 5.000000e-01 3FE0000000000000
4: 7.000000e-01 3FE6666666666664~%")
(format t "~%dv-test(exec in eus)~%")
(dv-test (length fv) fv)


(setq str "input : test64 string")
(format t "~%str-test~%")
;;(format t "expected result~%")
(format t "input string : ~S~%" str)
(format t "~%str-test(exec in eus)~%")
(str-test (length str) str)


(format t "~%return double test~%")
(format t "expected result~%")
(format t "  ret-double ~8,8e~%" (+ 0.55555 133.0))
(format t "~%ret-double(exec in eus)~%")
(format t "  ret-double ~8,8e~%" (ret-double 0.55555 133.0))


(format t "~%return long test~%")
(format t "expected result~%")
(format t "  ret-long ~D~%" (+ 123 645000))
(format t "~%ret-long(exec in eus)~%")
(format t "  ret-long ~D~%" (ret-long 123 645000))

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
