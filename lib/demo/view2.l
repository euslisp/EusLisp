(defvar *viewers* nil)

(setq *viewer* (view :dimension 2
		     :size 450
		     :title (format nil "2D-viewer~d" (length *viewers*))
		     :x 100 :y 100
		     :screen 100) )
(setq *viewsurface* (send *viewer* :viewsurface))
(setq *viewport* (send *viewer* :viewport))
(setq *viewing* (send *viewer* :viewing))
