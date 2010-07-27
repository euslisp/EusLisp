(defun make-dizzar-pattern (levels &optional (size (truncate (sqrt levels))))
   (let ((a (make-array levels)) x y  (p) (half (/ levels 2))
	 (q (/ levels (* size size))))
     (dotimes (i levels)
	(print i)
        (setq p  (make-array (list size size) :element-type :bit))
	(cond
	  ((> i half)
	   (fill (array-entity p) 1)
	   (dotimes (j (- levels i) )
	      (setq x (random size)  y (random size))
	      (while (= (aref p x y) 0) 
		  (setq x (random size)  y (random size)))
	      (setf (aref p x y) 0)))
	  (t
	   (dotimes (j i)
	     (setq x (random size)  y (random size))
	     (while (= (aref p x y) 1) 
		  (setq x (random size)  y (random size)))
	     (setf (aref p x y) 1))))
        (setf (aref a i) p))
     a))

(defun make-dizzar-pattern2 (diz)
   (dotimes (i (length diz))
	(let ((p (aref diz i)))
           (become (p . entity) string)
	   (setf (aref diz i) (p . entity)))))

(defun raster8 (file string-array dizpat)
  (with-open-file (f file :direction :output)
    (let* ((header (make-string 32))
	   (svec (array-entity string-array))
	   (rowsize (array-dimension string-array 0))
	   (colsize (array-dimension string-array 1))
	   (rasvec (make-array (list (* rowsize 8) colsize)
			       :element-type :char))
	   val)
      ; make rasfile header
      (setf (char header 0) #x59	;ras magic 
	    (char header 1) #xa6
	    (char header 2) #x6a
	    (char header 3) #x95)
      (sys:poke (* rowsize 8) header 4 :long)	;width
      (sys:poke (* colsize 8) header 8 :long)   ;height
      (sys:poke 1 header 12 :long)		;monochrome
      (sys:poke (length rasvec) header 16 :long)	;total length
      (sys:poke 1 header 20 :long)		;rastype
      (unix:write f header 32)
      ; put dizzar patterns
      (dotimes (i (array-dimension string-array 0))
	 (dotimes (j (array-dimension string-array 1))
	    (setf val (aref string-array i j))
	    (put-raster rasvec  i j (aref dizpat (/ val 4)))
	    )
         (print i))
      (setq *ras* rasvec)
      (unix:write f (rasvec . entity)))))

(defun put-raster (vec i j pat)
    (setq i (* i 8))
    (dotimes (k 8)
       (setf (aref vec (+ i k) j) (char pat k))))


(defun read-face-data (file &optional (size 4096))
  (with-open-file (f file :buffer-size size)
    (unix:read f size)
    (let ((a (make-array (list (truncate (sqrt size))
			       (truncate (sqrt size)))
			 :element-type :char))
	  (v (f . buffer)))
        (dotimes (i size)
	   (setf (aref v i) (- 256 (aref v i))))
	(setq (a . entity) (f . buffer))
        a)))

