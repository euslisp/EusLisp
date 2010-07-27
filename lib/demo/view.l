(in-package "GEOMETRY")
(defvar *viewers* nil)

(setq *viewer* (view :size 450
		     :title (format nil "EusViewer~d" (length *viewers*))
		     :x 100 :y 100
		     :viewpoint #f(1200 800 500)
		     :target #f(0 0 0)
		     :hither 100.0
		     :yon 5000.0
		     :screen 1.0
		     :viewdistance 3.0))
(setq *viewsurface* (send *viewer* :viewsurface))
(setq *viewport* (send *viewer* :viewport))
(setq *viewing* (send *viewer* :viewing))
