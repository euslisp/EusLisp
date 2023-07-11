(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest const

  (dotimes (i 100)
    (eval `(defconstant ,(intern (format nil "*CONST~d*" i)) i)))
  (make-package "TEST1")
  (dotimes (i (+ (length ((find-package "TEST1") . intsymvector)) 10))
    (eval `(defconstant ,(intern (format nil "TEST1::*CONST~d*" i)) i)))
  (make-package "TEST2")
  (dotimes (i (+ (length ((find-package "TEST2") . intsymvector)) 10))
    (handler-case
        (progn
          (shadow (intern (format nil "*CONST~d*" i)) (find-package "TEST2"))
          (eval `(defconstant ,(intern (format nil "TEST2::*CONST~d*" i)) i)))
      (name-error (err) (lisp::print-error-message err))))
  (make-package "TEST3")
  (setq num (+ (length ((find-package "TEST3") . intsymvector)) 10))
  (dotimes (i num)
    (intern (format nil "*CONST~d*" i) (find-package "TEST3"))
    (shadow (intern (format nil "*CONST~d*" i)) (find-package "TEST3"))
    (eval `(defconstant ,(intern (format nil "TEST3::*CONST~d*" i)) i)))
  (assert (not (= num (+ (length ((find-package "TEST3") . intsymvector)) 10))) "check if intsymvector is expanded")
  )

(eval-when (load eval)
  (run-all-tests)
  (exit))
