(defun fact (n)
   (if (<= n 1) 1 (* (fact (1- n)) n)))

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

(defvar fibm (make-array 1000))

(defun mfib (n)
   (if (aref fibm n)
	(aref fibm n)
	(if (< n 2) 
	    (setf (aref fibm n) 1)
	    (setf (aref fibm n) (+ (mfib (1- n)) (mfib (- n 2)))))))

	
(defvar fiblist nil)

(defun afib (n)
   (if (assoc n fiblist)
	(second (assoc n fiblist))
	(if (< n 2) 
	    1
	    (progn
		(push  (list n (+ (afib (1- n)) (afib (- n 2)))) fiblist)
		(cadar fiblist)) ) ) )

(defun etafib (n)
   (if (< n 2)
       n
       (+ (etafib (sub1 n)) (etafib (- n 2)))))


(defun gcd (a b)
    (if (= b 0)
	a
	(gcd b (mod a b))))

(defun factor (x &optional (y 2))
   (if (<= x y)
       (list x)
       (if (= (mod x y) 0)
	   (cons y (factor (/ x y) y) )
	   (factor x (1+ y) ) ) ) )

(defun power (a n)
   (if (= n 0)
       1
       (let ((b (power a (/ n 2))))
	  (setq b (* b b))
	  (if (= (mod n 2) 1) (setq b (* b a)))
	  b)))



