(defclass bcons :super cons :slots (bp))
(defun bcons (element forward &optional backward)
    (let* ((cons bcons)
	   (c (instantiate cons)))
	(setf (bcons-car c) element
	      (bcons-cdr c) forward
	      (bcons-bp c)  backward)
	c))


(defun blist (&rest list)
   (let (blist b)
     (setq blist (coerce list bcons))
     (setq b blist)
     (while (rest blist)
       (setf (bcons-bp (cdr blist))  blist)
       (pop blist))
     b))
   
(defun back-pointer (b) (bcons-bp b))

