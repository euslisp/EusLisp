(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defun test-read-line
  (max-char)
  (length (read-line
           (make-string-input-stream
            (apply #'concatenate string
                   (make-list max-char :initial-element "a")))))
  )

(deftest test-read-line-all
  (format *error-output* " read-line test~%")
  (assert (= (test-read-line 8191) 8191) "read-line with ~A char" 8191)
  ;; (assert (= (test-read-line 8192) 8192) "read-line with ~A char" 8192) ;; tempolarily comment out
  )

(deftest test-read-gensym
  (let ((g (gensym))
        (*print-circle* t))
    (assert
     (apply #'eq (read-from-string (format nil "~S" (list g g))))
     "Unable to read uninterned symbol")))

(run-all-tests)
(exit)
