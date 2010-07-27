;;;;
;;;; calc-distance-all calc-distance etc.
;;;; version.2 1989 2/9
;;;; 

(defun init-distance (collision distance)
  (let ((n (array-dimension collision 0)))
    (dotimes (i n)
	(dotimes (j n)
	    (dotimes (k n)
		(if (aref collision i j k)
		    (setf (aref distance (1+ i) (1+ j) (1+ k)) 0)))))))


(defun calc-distance (collision distance)
  (let ((n (array-dimension collision 0)))
    (dotimes (i n)
	(dotimes (j n)
	    (dotimes (k n)
	       (setf (aref distance (1+ i) (1+ j) (1+ k))
		     (min (aref distance (1+ i) (1+ j) (1+ k))
			  (1+ (calc-distance-6 distance 
					       (1+ i) (1+ j) (1+ k))))) 
			       )	      )     )
    (dotimes (i n)
	(dotimes (j n)
	    (dotimes (k n)
	       (let ((i1 (- n i))
		     (j1 (- n j))
		     (k1 (- n k)) )
		 (setf (aref distance i1 j1 k1)
		       (min (aref distance i1 j1 k1)
			    (1+ (calc-distance-6 distance i1 j1 k1))))
				 )  ) ) ) ))

(defun calc-distance-6 (distance i j k)
  (declare (integer i j k))
  (min (aref distance i j (1- k))
       (aref distance i j (1+ k))
       (aref distance (1- i) j k)
       (aref distance (1+ i) j k)
       (aref distance i (1- j) k)
       (aref distance i (1+ j) k)  ))

(defun calc-distance-all ()
  (let ((n (array-dimension collision 0)))
    (init-distance)
    (calc-distance)
    )
)  

(defun map-distance (bodies bottom top quantum)
   (let ((distance-map (make-array (list quantum quantum quantum)
				   :element-type :float))
	 (object-map   (make-array (list quantum quantum quantum)))
	)
     
(defun map-occupation (bodies bottom top size)
   (let ((occupation-map (make-array (list size size size)))
	 (xsize %(top[0] - bottom[0])) (xquantum (/ xsize size))
	 (ysize %(top[1] - bottom[1])) (yquantum (/ ysize size))
	 (zsize %(top[2] - bottom[2])) (zquantum (/ ysize size))
         (point (copy-seq bottom)))
     (dotimes (i size)
        (dotimes (j size)
	   (dotimes (k size)
	      (v+ bottom (	
	

