(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest test-defforeign
  (defvar *testforeign-lib*
    (load-foreign (format nil "~a/test/libtestdefforeign.so" (unix:getenv "EUSDIR"))))

  (defforeign test1
    *testforeign-lib*
    "test1"
    (:integer :float)
    :float
    )

  (defforeign test2
    *testforeign-lib*
    "test2"
    (:string)
    :float
    )

  (setq test1-result (test1 1 2.5))
  (format t "test1: ~a~%" test1-result)
  (assert (= test1-result 3.5))

  (setq test2-result (test2 (float-vector 1.0 2.5)))
  (format t "test2: ~a~%" test2-result)
  (assert (= test2-result  3.5))
  )

(eval-when
 (load eval)
 (run-all-tests)
 (exit))
