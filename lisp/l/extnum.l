(defmethod ratio
 (:init (num denom)
  (setq numerator num
        denominator denom)
  self))

(defmethod complex
 (:init (re im)
  (setq real re
        imaginary im)
  self))
