;;
;; utility routines to draw on  tektronix terminals
;;

(setq *viewsurface* (instance tektro-viewsurface :init))
(setq *viewport* (instance viewport :init
				:xcenter 500  :ycenter 400
				:width 250 :height 250))
(setq *viewing*
      (instance perspective-viewing :init
		:pos #f(1000 1000 500)
		:target #f(0 0 0)
		:viewdistance 5.0
		:hither 100.0  :yon 5000.0
		:screen-x 1.0  :screen-y 1.0))

(setq *viewer* (instance viewer :init   :viewing *viewing*
					:viewsurface *viewsurface*
					:viewport *viewport*))

