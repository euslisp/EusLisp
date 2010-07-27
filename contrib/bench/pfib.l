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

;;; parallel fibonacci

(setq *fork-n* 20)

(defun parfib (n)
   (cond ((< n 2) n)
	 ((< n *fork-n*) (+ (parfib (- n 2)) (parfib (1- n))))
	 (t (let (a b)
		(setq a (thread 'parfib (- n 2))
		      b (thread 'parfib (1- n)))
	        (+ (sys:wait-thread a) (sys:wait-thread b))))))

(defun parfib-test (n)
  (thr-setconcurrency 10)
  (let (start end sec usec r)
     (setq *fork-n* (1+ n))
     (setq start (unix::gettimeofday))
     (setq r (parfib n))
     (setq end (unix::gettimeofday))
     (setq sec (- (car end) (car start))
	   usec (- (cadr end) (cadr start)))
     (format t "cpu=1   ~s sec~%"     (/ (+ (* sec 1000000) usec) 1000000.0))
     (setq *fork-n* (- n 5))
     (setq start (unix::gettimeofday))
     (setq r (parfib n))
     (setq end (unix::gettimeofday))
     (setq sec (- (car end) (car start))
	   usec (- (cadr end) (cadr start)))
     (format t "cpu=4   ~s sec~%"     (/ (+ (* sec 1000000) usec) 1000000.0))
     )
)

;;;
(defun fact (n)
   (if (<= n 1)
       1
       (* n (fact (1- n)))))

