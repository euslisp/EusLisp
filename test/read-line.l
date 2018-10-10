(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defun test-read-line (max-char &optional llength)
  "max-char: length of string, llength: length of line"
  (let ((str (make-string max-char)))
    (dotimes (i max-char)
      (setf (elt str i) #\a))
    (if (and llength (< llength max-char))
        (setf (elt str llength) 10))
    (length (read-line (make-string-input-stream str)))
    ))

(deftest test-read-line-all
  (format *error-output* " read-line test~%")
  (assert (= (test-read-line 8191) 8191) "read-line with ~A char" 8191)
  (assert (= (test-read-line 8192) 8192) "read-line with ~A char" 8192) ;; exceeds READLINE_BUF_LENGTH https://github.com/euslisp/EusLisp/pull/247/files
  (assert (= (test-read-line 100000 8192) 8192) "read-line with ~A char (from 100000 char)" 8192)
  (assert (= (test-read-line (- 1000000 8192)) (- 1000000 8192)) "read-line with ~A char" (- 1000000 8192))
  (assert (= (test-read-line 100000 100000) 100000) "read-line with ~A char (from 100000 char)" 100000)
  )

(deftest test-read-gensym
  (let ((g (gensym))
        (*print-circle* t))
    (assert
     (apply #'eq (read-from-string (format nil "~S" (list g g))))
     "Unable to read uninterned symbol")))

(eval-when (load eval)
  (run-all-tests)
  (exit))
