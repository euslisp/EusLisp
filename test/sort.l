(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(defmacro swap (a b)
  `(let ((temp ,a))
     (setf ,a ,b)
     (setf ,b temp)))

(deftest test-soft
  (let ((l0 '(a b c d e f g h i j k l m n o p q r s t u v w x y z))
        l1 n0 n1)
    (dotimes (i 10)
      (setq l1 (copy-list l0))
      (dotimes (j (length l1))
        (setq n0  (random (length l1)) n1 (random (length l1)))
        (swap (elt l1 n0) (elt l1 n1)))
      (format *error-output* "before sort ~A~%" l1)
      (sort l1 #'string<= #'(lambda(x)(let ((v (instantiate vector 1000)) (r (gc))) (format nil "~A" x) x)))
      (format *error-output* " after sort ~A~%" l1)
      (assert (equal l0 l1) "sort ~A" l0)
      )
    ))

(eval-when (load eval)
  (run-all-tests)
  (exit))
