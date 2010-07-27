(defun normal-random (&optional (k 6))
   (let ((u 0.0)) 
      (dotimes (i k) (incf u (- (random 1.0) 0.5) ))
      %(sqrt(12.0 / k) * u))
