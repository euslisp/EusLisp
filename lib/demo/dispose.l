(defclass dispose :slots (a b c))

(defmethod dispose
 (:dispose ()
    (format t "~s is being disposed~%" self))
 (:init ()
    (sys::dispose-hook self t)
    (setq a (gensym "DISP"))
    self))


;(print (instance dispose :init))

;(print (instance dispose :init))

(dotimes (i 10) (print (instance dispose :init)))

(cons nil nil)


