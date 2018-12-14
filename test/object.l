(require :unittest "lib/llib/unittest.l")

;(setq sys::*gc-hook* #'(lambda (a b) (format t "GC! free:~A  total:~A~%" a b)))

(init-unit-test)

(deftest test-copy-object-body
  (let (vmrss vmrss-orig a b)
    (setq vmrss-orig (elt (unix::getrusage 0) 2))
    (dotimes (j 10)
      (dotimes (i 1000)
        (setq a (make-cube 100 100 100))
        (setq b (copy-object a))
        (unless (equal (send a :vertices) (send b :vertices))
          (assert nil (format nil "(equal ~A ~A)~%" a b))))
      (format *error-output* "copy-object ~A ~A" a b)
      (print (sys::gc) *error-output*)

      (setq vmrss (elt (unix::getrusage 0) 2))
      (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
      (if (>= vmrss (* 2 vmrss-orig))
          (warning-message 1 "~A copy-object body ~A -> ~A~%" (sys::thread-self) vmrss-orig vmrss))
      )
    (assert (< vmrss (* 10 vmrss-orig)) "copy-object body")))

#|
(deftest test-copy-object-thread
  (let (vmrss vmrss-orig a b)
    (need-thread 2)
    (setq vmrss-orig (elt (unix::getrusage 0) 2))

    (setq a (sys::thread #'test-copy-object-body))
    (setq b (sys::thread #'test-copy-object-body))
    (sys:wait-thread a)
    (sys:wait-thread b)

    (print (sys::gc) *error-output*)
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "gc:~A, vmrss:~A -> ~A~%" (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 10 vmrss-orig)) "copy-object body thread")
    ))
|#

;;;

(setq i-max 200000)

(deftest test-copy-object-integer
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
  (dotimes (j 5)
    (dotimes (i i-max)
      (setq a 10)
      (setq b (copy-object a))
      (unless (equal a b)
        (assert nil (format nil "(equal ~A ~A)" a b))))
    (print (sys::gc) *error-output*)
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 10 vmrss-orig)) "copy-object integer")))

(deftest test-copy-object-list
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
   (dotimes (j 10)
    (dotimes (i i-max)
      (setq a (list 10 20 30 40 50 60 70 80 90 100))
      (setq b (copy-object a))
      (unless (equal a b)
        (assert nil (format nil "(equal ~A ~A)" a b))))
    (print (sys::gc) *error-output*)
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 20 vmrss-orig)) "copy-object list")))

(deftest test-copy-object-vector
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
  (dotimes (j 5)
    (dotimes (i i-max)
      (setq a (float-vector 1 2 3 4 5 6 7 8 9 10))
      (setq b (copy-object a))
      (unless (equal a b)
        (assert nil (format nil "(equal ~A ~A)" a b))))
    (print (sys::gc) *error-output*)
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 10 vmrss-orig)) "copy-object vector")))

(deftest test-copy-object-matrix
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
  (dotimes (j 5)
    (dotimes (i i-max)
      (setq a (unit-matrix 10))
      ;;(setq b (copy-object a))
      (setq b (copy-matrix a))
      (unless (equal a b)
        (assert nil (format nil "(equal ~A ~A)" a b))))
    (print (sys::gc) *error-output*)
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 10 vmrss-orig)) "copy-object matrix")))

(eval-when (load eval)
  (run-all-tests)
  (exit))
