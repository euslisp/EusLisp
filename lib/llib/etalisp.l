(defmacro fix (x) 		`(truncate ,x))
(defmacro $* (&rest l)		`(* . ,l))
(defmacro $+ (&rest l)		`(+ . ,l))
(defun add1 (n) (1+ n))
(defun add1 (n) (1- n))
(defmacro mref (a i j)		`(aref ,a ,i ,j))
(defmacro mset (a i j v)	`(aset ,a ,i ,j ,v)) 
(defmacro m*   (&rest l)	`(m** . ,l))
(defmacro vref (v i)		`(aref ,v ,i))
(defmacro vset (v i val)	`(aset ,v ,i ,val))
(defmacro sv*  (s v)		`(scale ,s ,v))
(defmacro $sla (d n)		`(ash ,d ,n))
(defmacro $and (&rest l)	`(logand . ,l))
(defmacro $or  (&rest l)	`(logior . ,l))

(defun read-matrix (strm n ch)
     (apply #'matrix (read strm)) )
(set-dispatch-macro-character #\# #\M 'read-matrix)

(defun explode (sym)
  (mapcar #'intern
	(mapcar #'(lambda (x) (make-array 1 :element-type :char
					    :initial-element x))
		(coerce (symbol-name sym) cons))))

(defun implode (list)
   (intern (apply #'concatenate string (mapcar #'symbol-name list))))

