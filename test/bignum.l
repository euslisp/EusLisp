;(setq sys::*gc-hook* #'(lambda (a b) (format t "GC! free:~A  total:~A~%" a b)))
(setq sys::*gc-hook* #'(lambda (a b) ()))

(require :unittest "lib/llib/unittest.l")

(init-unit-test)
(defmacro check-bignum (op num1 num2 ans)
  `(let (num3)
     (format *error-output* "check (~a #x~x #x~x) -> " (quote ,op) ,num1 ,num2)
     (setq num3 (funcall ,op ,num1 ,num2))
     (if (numberp num3)
	 (format *error-output* "#x~x,  " num3)
       (format *error-output* "~a,  " num3))
     (if (equal num3 ,ans)
         (format *error-output* "passed~%")
       (progn
         (warn "failed!! : answer(~x)~%" ,ans)
         (print (list 'ans (class ,ans)
                      'num3 (class num3)))
         ))
     (assert (equal num3 ,ans))))

(deftest test-bignum
  (dotimes (i 10)
    (print i)
    (check-bignum #'+ 0 0 0)
    (check-bignum #'+ 1 3 4)
    (check-bignum #'+ -1 -3 -4)

    ;; fixnum op fixnum -> bignum
    (check-bignum #'+ #x18000000 #x18000000 #x30000000)
    (check-bignum #'- (- #x18000000) #x18000000 (- #x30000000))
    (check-bignum #'* #x18000000 2 #x30000000)

    ;;(check-bignum #'/ ?? ?? ??)

    ;; bignum op fixnum -> fixnum
    ;;(check-bignum #'+ ?? ?? ??)
    (check-bignum #'- #x20000000 1 #x1fffffff)
    ;;(check-bignum #'* ?? ?? ??)
    (check-bignum #'/ #x20000000 2 #x10000000)

    ;; fixnum op bignum -> fixnum
    ;;(check-bignum #'+ ?? ?? ??)
    (check-bignum #'- 1 #x20000000 (- #x1fffffff))
    ;;(check-bignum #'* ?? ?? ??)
    (check-bignum #'/ 1 #x20000000 0)

    ;; bignum op bignum -> fixnum
    ;;(check-bignum #'+ ?? ?? ??)
    (check-bignum #'- #x20000001 #x20000000 1)
    ;;(check-bignum #'* ?? ?? ??)
    (check-bignum #'/ #x40000000 #x20000000 2)
    (check-bignum #'/ #x40000000 (- #x20000000) -2)
    (check-bignum #'/ (- #x40000000) #x20000000 -2)
    (check-bignum #'mod #x40000001 #x20000000 1)
    (check-bignum #'mod #x100000001 #x20000000 1)

    ;; bignum op bignum -> bignum
    (check-bignum #'+ #x20000000 #x20000000 #x40000000)
    (check-bignum #'- #x40000000 #x20000000 #x20000000)
    (check-bignum #'* #x20000000 #x20000000 #x400000000000000)
    (check-bignum #'/ #x400000000000000 #x20000000 #x20000000)

    (check-bignum #'+ #x1800000000000000 #x1800000000000000 #x3000000000000000)
    (check-bignum #'- #x6000000000000000 #x3000000000000000 #x3000000000000000)
    (check-bignum #'* #x1800000000000000 2 #x3000000000000000)
    (check-bignum #'/ #x6000000000000000 2 #x3000000000000000)

    (check-bignum #'mod #x20000000 #x40000000 #x20000000)
    ;;(check-bignum #'mod #x40000000 #x100000000 #x40000000)

    ;; bignum equal bignum
    (check-bignum #'equal #x20000000 #x20000000 t)
    (check-bignum #'equal #x40000000 #x40000000 t)
    (check-bignum #'equal #x200000000 #x200000000 t)
    (check-bignum #'equal #x200000000 #x200000000 t)
    (check-bignum #'equal #x1FFFFFFFFFFFFFFF #x1FFFFFFFFFFFFFFF t)
    (check-bignum #'equal #x2000000000000000 #x2000000000000000 t)
    (check-bignum #'equal #x20000000 #x20000001 nil)
    (check-bignum #'equal #x40000000 #x40000001 nil)
    (check-bignum #'equal #x200000000 #x200000001 nil)
    (check-bignum #'equal #x200000000 #x200000001 nil)
    (check-bignum #'equal #x1FFFFFFFFFFFFFFF #x1FFFFFFFFFFFFFFE nil)
    (check-bignum #'equal #x1FFFFFFFFFFFFFFF #x2000000000000000 nil)
    (check-bignum #'equal #x2000000000000000 #x2000000000000001 nil)

#+(or :alpha :irix6 :x86_64 :aarch64)
(progn
    ;; bignum devide float / float devide bignum
    (check-bignum #'/ 10000000000000000000 1.0e+19 1.0)
    (check-bignum #'/ -10000000000000000000 1.0e+19 -1.0)
    (check-bignum #'/ 1.0e+19 10000000000000000000 1.0)
    (check-bignum #'/ 1.0e+19 -10000000000000000000 -1.0)

    ;; bignum multiple float / float multiple bignum
    (check-bignum #'* 10000000000000000000 1.0e-19 1.0)
    (check-bignum #'* -10000000000000000000 1.0e-19 -1.0)
    (check-bignum #'* 1.0e-19 10000000000000000000 1.0)
    (check-bignum #'* 1.0e-19 -10000000000000000000 -1.0)
    )

#-(or :alpha :irix6 :x86_64 :aarch64)
(progn
    ;; bignum devide float / float devide bignum
    (check-bignum #'/ 10000000000000000000 1.0e+19 1.0)
    (check-bignum #'/ -10000000000000000000 1.0e+19 -1.0)
    (check-bignum #'/ 1.0e+9 1000000000 1.0)
    (check-bignum #'/ 1.0e+9 -1000000000 -1.0)

    ;; bignum multiple float / float multiple bignum
    (check-bignum #'* 10000000000000000 1.0e-16 1.0)
    (check-bignum #'* -10000000000000000 1.0e-16 -1.0)
    (check-bignum #'* 1.0e-16 10000000000000000 1.0)
    (check-bignum #'* 1.0e-16 -10000000000000000 -1.0)
    )

    ;;
    (check-bignum #'equal (elt #i(536870912) 0) #x20000000 t)
    (check-bignum #'equal (elt (integer-vector 536870912) 0) #x20000000 t)
#+:x86_64
    (progn
      ;;(check-bignum #'equal (elt #i(2305843009213693952) 0) #x2000000000000000 t)
      (check-bignum #'equal (elt (integer-vector 2305843009213693952) 0) #x2000000000000000 t)
      )
    )
  (print 'done)
  )

(eval-when (load eval)
  (run-all-tests)
  (exit))
