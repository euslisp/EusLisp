(defclass xvwindow :super sunview-frame
		   :slots (xvcanvas xvpanel mark))

(defmethod xvwindow 
 (:drawimage (img &optional wx wy (x 0)  (y 0))
    (send xvcanvas :drawimage img :x x :y y :width wx :height wy))
 (:init  (&key (parent nil) (title "xvwindow")
	       (x 0) (y 0) (size 200) (width size) (height size)
	  &allow-other-keys)
    (send-super :init parent :title title
		:x x  :y y  :width (+ width 4)  :height (+ 4 height))
    (setq xvcanvas (send self
    			 :create-subwindow sunview-canvas
			 :width width :height height))
    (send self :show t)
    self)
	)
 
(defun putimg (win img &aux subimg)
   (dotimes (i 256)
      (setq subimg  (subseq img (* i 256) (* (1+ i) 256)))
      (send win :drawimage subimg 256 1 0 i)
      (print i)  ; (read-char)
	))
