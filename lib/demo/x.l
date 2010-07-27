;;
;; Draw pictures using Xwindow 
;;
#+xlib
(setq *viewsurface* (instance xwindow :create
				:x 100 :y 100 :width 500 :height 500
				:title "eusx"
				:border-width 3
				:background 0))
#-xlib
(setq *viewsurface* (instance canvas-viewsurface :init
			      :x 100 :y 100 :width 500 :height 500
			      :title "eusx"
				:cmap-type :half
			      ))

(setq *viewport* (instance viewport :init
				:xcenter 250  :ycenter 250
				:width 250 :height -250))

(setq *viewing*
      (instance perspective-viewing :init
		:pos #f(1000 1000 500)
		:target #f(0 0 0)
		:viewdistance 5.0
		:hither 100.0  :yon 4000.0
		:screen-x 1.0  :screen-y 1.0))

(setq *viewer* (instance viewer :init   :viewing *viewing*
					:viewsurface *viewsurface*
					:viewport *viewport*))

;(setq view1 (view :size 300
;		  :viewpoint  #f(1000 -1000 500)
;		  ))
;(setq view2 (view :size 200
;		  :viewpoint #f(-1000 1000 500)
;		  :viewdistance 10.0))

