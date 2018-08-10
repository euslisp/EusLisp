(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(unless (boundp '*irtview*)
  (setq *irtview0* (make-irtviewer)))
(unless (boundp '*irtview1*)
  (setq *irtview1* (make-irtviewer)))

(defun make-cubes (num)
  (let (c ret)
    (dotimes (i num)
      (setq c (make-cube 100 100 100))
      (setf (get c :face-color) #f(1 0 0))
      (push c ret))
    ret))

;;memory_leak_transparent
(deftest memory-leak-transparent
  (let (vmrss-orig vmrss)
    (setq *cubes* (make-cubes 5000))
    (send *irtview0* :objects *cubes*)
    (send *irtview1* :objects *cubes*)
    (print "start")
    (setq vmrss-orig (elt (unix::getrusage 0) 2))
    (dotimes (i 30)
      (mapcar #'(lambda (a) (gl::transparent a (/ i 30.0))) *cubes*)
      (send *irtview0* :draw-objects)
      (send *irtview1* :draw-objects)
      ;;(print (get (car *cubes*) :GL-DISPLAYLIST-ID))
      (setq vmrss (elt (unix::getrusage 0) 2))
      (format *error-output* "~A gc:~A, vmrss:~A(~A)~%" i (sys::gc) vmrss vmrss-orig)
      (assert (< vmrss (* 4 vmrss-orig)) "check memory leak")
      )))

(run-all-tests)
(exit)
