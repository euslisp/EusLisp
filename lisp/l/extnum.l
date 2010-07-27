(defmethod ratio
 (:prin1 (&optional (strm t))
    (format strm "~d/~d" numerator denominator))
)
