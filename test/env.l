(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(eval-when (compile) ;; this does not work on compiled code
 (when nil

;;(defun make-c (a) (let ((x 0)) #'(lambda () (list a x))))
;;(defun make-c () (let ((x 0)) #'(lambda () (list x))))
(defun make-c0 () #'(lambda () (list 0)))

(compile 'make-c0)
(setq f0 (make-c0))

(deftest f0
  (format t ";; funcall make-c0 ~A~%" (funcall f0))
  (assert (equal (funcall f0) '(0))))

(defun make-c1 () (let () #'(lambda (x) (list x))))

(compile 'make-c1)
(setq f1 (make-c1))

(deftest f1
  (format t ";; funcall make-c1 ~A~%" (funcall f1 1))
  (assert (equal (funcall f1 1) '(1))))

(defun make-c2 () (let ((x 0)) #'(lambda () (list x))))

(compile 'make-c2)
(setq f2 (make-c2))

(deftest f2
  (format t ";; funcall make-c2 ~A~%" (funcall f2))
  (assert (equal (funcall f2) '(0))))

(setq *x* 2) (defun make-c3 () #'(lambda () (list *x*)))

(compile 'make-c3)
(setq f3 (make-c3))

(deftest f3
  (format t ";; funcall make-c3 ~A~%" (funcall f3))
  (assert (equal (funcall f3) '(2))))

(defun make-c4 () #'(lambda (x) (list x)))

(compile 'make-c4)
(setq f4 (make-c4))

(deftest f4
  (format t ";; funcall make-c4 ~A~%" (funcall f4 1))
  (assert (equal (funcall f4 1) '(1))))

)) ;; eval-when (compile) (when nil

(deftest lambda-in-lambda
  (let (r)
    (setq r
	  (mapcar #'(lambda (x)
		      (mapcar #'(lambda (y) 1)
			      '(nil nil nil nil nil nil nil nil nil nil nil nil nil
				    nil nil nil nil nil nil nil nil nil nil nil nil nil)))
		  '(nil nil nil nil nil nil nil nil nil nil nil nil nil
			nil nil nil nil nil nil nil nil nil nil nil nil nil)))
    (print r)
    (assert (equal
	     (make-list 26 :initial-element (make-list 26 :initial-element 1))
	     r))
    ))

(eval-when (load eval)
  (run-all-tests)
  (exit))
