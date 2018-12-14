(require :unittest "lib/llib/unittest.l")

;;(setq sys::*gc-hook* #'(lambda (a b) (format t "GC! free:~A  total:~A~%" a b)))

(init-unit-test)

(setq i-max 100000)

(deftest test-makecoords-rpy
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
  (dotimes (j 10)
    (dotimes (i i-max)
      (setq ret #f(0 0 0))
      (make-cascoords :pos (float-vector 0 0 0)
                      :rpy (float-vector 0 0 0)))
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 2 vmrss-orig)) "make-coords pos/rpy")))

(deftest test-makecoords-rot-1
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
  (dotimes (j 10)
    (dotimes (i i-max)
      (setq ret #f(0 0 0))
      (make-cascoords :pos (float-vector 0 0 0)
                      :rot (unit-matrix 3)))
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 2 vmrss-orig)) "make-coords pos/rot (unit-matrix)")))

(deftest test-makecoords-rot-2
  (setq vmrss-orig (elt (unix::getrusage 0) 2))
  (dotimes (j 10)
    (dotimes (i i-max)
      (setq ret #f(0 0 0))
      (make-cascoords :pos (float-vector 0 0 0)
                      :rot (rpy-matrix 0 0 0)))
    ;;
    (setq vmrss (elt (unix::getrusage 0) 2))
    (format *error-output* "~A gc:~A, vmrss:~A -> ~A~%" j (sys::gc) vmrss-orig vmrss)
    (assert (< vmrss (* 2 vmrss-orig)) "make-coords pos/rot (rpy-matrix)")))

(warning-message 1 "test-makecoords-quaternion is not working on eusgl ...
-- undefined function quaternion2matrix , exitting...
-- See jskeus/irteus/coords.l~%")


(eval-when (load eval)
  (run-all-tests)
  (exit))
