(defclass table :super body
	:slots (board legs))

(defmethod table
 (:init (width depth height
	 &optional (thickness (/ height 20.0))
		   (leg-width thickness))
    (let* ((leg-length (- height (/ thickness 2.0)))
	   (leg-height (/ leg-length 2.0))
	   (leg-x-offset (/ (- width leg-width 1.0) 2.0))
	   (leg-y-offset (/ (- depth leg-width 1.0) 2.0)))
      (setq board (make-cube width depth thickness))
      (push (make-cube leg-width leg-width leg-length) legs)
      (send (car legs) :translate
	 (floatvector leg-x-offset leg-y-offset leg-height))
      (push (make-cube leg-width leg-width leg-length) legs)
      (send (car legs) :translate
	 (floatvector leg-x-offset (- leg-y-offset) leg-height))
      (push (make-cube leg-width leg-width leg-length) legs)
      (send (car legs) :translate
	 (floatvector (- leg-x-offset) (- leg-y-offset) leg-height))
      (push (make-cube leg-width leg-width leg-length) legs)
      (send (car legs) :translate
	 (floatvector (- leg-x-offset) leg-y-offset leg-height))
      (send board :translate (floatvector 0 0 (- height (/ thickness 2.0))))
      (replace-object self (apply #'body+ board legs))
      self)))