(defun prime (n)
    (let ((primes (make-array n))
	  i j r (end (ceiling (sqrt n))))
       (declare (vector primes) (integer i j r))
       (fill  primes t)
       (setf (aref primes 2) t
	     (aref primes 3) t)
       (setq i 2)
       (while (< i end)
          (when (aref primes i)
            (setq j (+ i i))
            (while (< j n)
	      (setf (aref primes j) nil)
	      (incf j i)))
	  (incf i ))
       (setq i 2)
       (while (< i n) 
	  (if (aref primes i)
	      (push i r) )
          (incf i))
       r
       ))

	     