(defun fib (n)
   (if (< n 2)
       n
       (+ (fib (1- n)) (fib (- n 2)))))


(defun ifib (n)
   (declare (fixnum n))
   (if (< n 2)
	n
       (+ (the integer (ifib (1- n))) (the integer (ifib (- n 2))))))

(defun ffib (n)
   (declare (fixnum n))
   (if (< n 2)
	n
       (+ (the fixnum (ffib (1- n))) (the fixnum (ffib (- n 2))))))

(defun xfib (n0 n1 end)
   (let ((a (make-array (1+ end) :initial-element 0)))
      (setf (aref a 0) n0)
      (setf (aref a 1) n1)
      (do ((i 2 (1+ i)))
	  ((> i end))
	(setf (aref a i) (+ (aref a (1- i)) (aref a (- i 2)))))
      a))


(defun etafib (n)
   (if (< n 2)
       n
       (+ (etafib (sub1 n)) (etafib (- n 2)))))

