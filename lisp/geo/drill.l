(list "@(#)$Id: drill.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $")
(defun drill-hole (part center radius depth
			  &rest args)
   (let (onface (mindist 1e10) d screwhole z-axis x-axis y-axis rot)
      (dolist (f (send part :faces))
	 (setq d (abs (send f :plane-distance center))) 
	 (if (and (> mindist d) (eql (send f :insidep center) :inside))
	     (setq onface f mindist d)))
      (setq z-axis (send onface :normal))
      (setq x-axis (send (car (send onface :edges)) :direction onface))
      (setq y-axis (v* z-axis x-axis))
      (setq rot (transpose (matrix x-axis y-axis z-axis)))
      (setq center (v- center (scale depth z-axis)))
      (setq screwhole
	    (apply #'make-cylinder
			radius depth
			:circumscribed t
			:rot rot :pos center
			args))
      (send part :- screwhole)
      part))

(defun drill-screw-hole (part center radius depth
			  &rest args
			  &key properties &allow-other-keys)
   (apply #'drill-hole
	  part center radius depth
	  :properties (append properties '(((:threaded t)))
	  args)) )


