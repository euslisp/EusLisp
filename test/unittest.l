;; test code for unittest

(eval-when (compile)
  (warning-message 1 "unittest.l can not run on compile mode....")
  (exit 0))

(require :unittest "lib/llib/unittest.l")
(init-unit-test)

(deftest test1
  )

(deftest test2
  (dotimes (i 10)
    (assert t "true"))
  )

(deftest test3
  (dotimes (i 10)
    (assert (null nil) "false"))
  )

(deftest test4
  (dotimes (i 10)
    (assert t "ok"))
  (warning-message 1 "*** This test  fails intentinally ****~%")
  (dotimes (i 10)
    (assert nil "false")
    )
  (dotimes (i 10)
    (assert t "ok"))
  )

;; Prevent from exitting from run-all-tests because we intentinally raise failure of unitteset.
(setf (symbol-function 'org-exit) (symbol-function 'exit))
(setf (symbol-function 'exit) #'(lambda (a) (print a)))
;; Test all cases including intentinal failure.
(eval-when (load eval)
  (run-all-tests)

;; Revert exit function
(setf (symbol-function 'exit) (symbol-function 'org-exit))

(setq ret -1)
(format t "functions = ~A, num-tests =~A, num-failures = ~A, num-successes = ~A~%"
        (length (send *unit-test* :functions))
        (apply #'+ (send-all (send *unit-test* :result) :num-tests))
        (apply #'+ (send-all (send *unit-test* :result) :num-failures))
        (apply #'+ (send-all (send *unit-test* :result) :num-successes)))
(send *unit-test* :result)
(if (and (= (length (send *unit-test* :functions)) 4)
         (= (apply #'+ (send-all (send *unit-test* :result) :num-tests)) 4)
         (= (apply #'+ (send-all (send *unit-test* :result) :num-failures)) 1)
         (= (apply #'+ (send-all (send *unit-test* :result) :num-successes)) 3))
    (setq ret 0))
(format t "return code = ~A~%" ret)
(exit ret)

);; eval-when

