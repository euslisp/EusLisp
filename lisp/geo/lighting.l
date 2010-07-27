(defclass light-source
		:super cascaded-coords
		:slots (type intensity colors ambient))

(defclass point-light-source :super light-source)

(defun reflection-ray (f point light)
"face point-on-the-face normal-vector-to-light"
   (let ((normal (send f :normal)))
     ; (setq light (v- light point))
     (normalize-vector
	%(v-(scale((2.0 * v.(normal light)) normal) light)))))
