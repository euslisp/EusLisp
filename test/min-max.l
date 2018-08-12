(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defmacro check-min-max (op ans &rest args)
  `(let (ret tret)
     (format *error-output* "check: (apply ~A ~A)~%" ,op ',args)
     (lisp::install-error-handler #'(lambda (&rest args) (throw :min-max-test :min-max-error)))
     (setq tret (catch :min-max-test
                  (setq ret (funcall ,op ,@args))))
     (lisp::install-error-handler 'unittest-error) ;; revert error-handler
     (assert (equal ,ans tret)
     )))

(deftest test-max
  (check-min-max 'max 3   1 2 3) ;; integer
  (check-min-max 'max 3   3 2 1) ;; integer

  (check-min-max 'max 2.5   1 2 2.5) ;; float
  (check-min-max 'max 2.5   2.5 2 1) ;; float

  (check-min-max 'max (/ 10 3.0)   10/3 1 2) ;; ratio
  (check-min-max 'max (/ 10 3.0)    1 2 10/3);; ratio

  (check-min-max 'max (float 3000000000000000000) 3000000000000000000 1 2) ;; bignum
  (check-min-max 'max (float 3000000000000000000) 1 2 3000000000000000000) ;; bignum

  (check-min-max 'max :min-max-error  :test  1 2) ;; not number
  (check-min-max 'max :min-max-error  "test" 1 2) ;; not number
  (check-min-max 'max :min-max-error  1 2 :test)  ;; not number
  (check-min-max 'max :min-max-error  1 2 "test") ;; not number

  (print 'max-test-done)
  )

(deftest test-min
  (check-min-max 'min 1   1 2 3) ;; integer
  (check-min-max 'min 1   3 2 1) ;; integer

  (check-min-max 'min 0.5   1 2 0.5) ;; float
  (check-min-max 'min 0.5   0.5 2 1) ;; float

  (check-min-max 'min (/ 1 3.0)   1/3 1 2) ;; ratio
  (check-min-max 'min (/ 1 3.0)   1 2 1/3);; ratio

  (check-min-max 'min (float -3000000000000000000) -3000000000000000000 1 2) ;; bignum
  (check-min-max 'min (float -3000000000000000000) 1 2 -3000000000000000000) ;; bignum

  (check-min-max 'min :min-max-error  :test  1 2) ;; not number
  (check-min-max 'min :min-max-error  "test" 1 2) ;; not number
  (check-min-max 'min :min-max-error  1 2 :test)  ;; not number
  (check-min-max 'min :min-max-error  1 2 "test") ;; not number

  (print 'min-test-done)
  )

(eval-when (load eval)
  (run-all-tests)
  (exit))
