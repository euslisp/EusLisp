(defclass histogram :super propertied-object
	  :slots (min max freq granule))

(defmethod histogram
 (:init (mn mx segments)
   (setq min mn max mx
	 granule (/ (- max min) segments)
	 freq (make-array segments :element-type :integer))
   self)
 (:put (x &aux index)
    (setq index %((x - min) / granule))
    (incf (aref freq (truncate index)))
    )
 (:print (&optional (start 0) (end (length freq)))
     (dotimes (i (- end start))
	(format t "~5,2f: ~d~%" (+ min (* i granule)) (aref freq i)))) 
 (:graph (view)
  ))

(defun char-code-histogram (file)
   (let ((his (instance histogram :init 0 256 256)) ch)
        (with-open-file (f file)
	    (while (setq ch (read-char f nil nil))
		(send his :put ch)) )
    (send his :print)
   his) )

