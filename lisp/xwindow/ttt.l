(in-package "X")

(defclass windowframe :super xwindow
	 :slots (panelw canvasw textw texts menuw))

(defmethod windowframe
 (:create (&rest args)
    (send-super* :create args)
    (setq panelw (instance* panel :create
			:parent self :x 0 :y 0
			:width 512 :height 100
    			:item-width 80 :item-height 30
			:font font-lucidasans-bold-12 args))
    (setq canvasw (instance canvas :create :background 0
			:parent self
			:x 0 :y 100
			:width 512 :height 512))
;;  textwindow
    (setq textw (instance ScrollTextWindow :create
			:notify self
			:background 0
			:parent self
			:x 0 :y 620
			:font font-courb12
			:width 100 :height 125
			:show-cursor nil
			:scroll-bar t
			:horizontal-scroll-bar t))
    (send textw :display-strings (directory))
    (send textw :echo t)
    (setq texts (make-text-window-stream textw))
;;
    (send panelw :create-item button-item "scroll-down" self :scroll-down)
    (send panelw :create-item button-item "scroll-up" self :scroll-up
			:background *lightblue2*)
    (send panelw :create-item button-item "refresh" self :refresh)
    (send panelw :create-item button-item "line" self :linex)
    (send panelw :create-item button-item "ez" self :ez)
    (send panelw :create-item button-item "quit" self :quit)
#|
    (send panelw :create-item joystick-item "joy" self :quit)
|#
    (send panelw :create-item text-item  "file: " self :file
			:font font-courb12)
    (send panelw :create-item slider-item "slider" self nil
		:min-label "0.0" :max-label "1.0"
		:font font-courb12)
    (send panelw :create-item choice-item "choice" self nil
		:choices '("  0  " "  1  " " abort ")
		:font font-courb12)
    (setq menuw (instance menu-panel :create :font font-courb14))
    (send panelw :create-item menu-button-item "clear" nil nil :menu menuw)
    (send menuw  :create-item button-item "text" self :clear-text)
    (send menuw  :create-item button-item "canvas" self :clear-canvas)
    (send menuw  :create-item button-item "panel" self :clear-all)
    (send menuw  :create-item button-item "all" self :clear-all)
    self)
  )

(defmethod windowframe
 (:quit (event) (throw  :window-main-loop t))
 (:ez (&rest a) (ez))
 (:clear-canvas (event) (send canvasw :clear))
 (:clear-text (event) (send textw :clear))
 (:nop (event) (print event))
 (:hex-dump (item)
    (let ((w (- (aref (canvas-bottomright canvasw) 0)
		(aref (canvas-topleft canvasw) 0)) )
	  (h (- (aref (canvas-bottomright canvasw) 1)
		(aref (canvas-topleft canvasw) 1)) ) )
      (dump-string (make-foreign-string 8192 256) texts)) 
 )
 (:linex (item)
    (send canvasw :draw-line (canvas-bottomright canvasw)
			     (canvas-topleft canvasw)))
 (:scroll-up (event) (send textw :scroll 1))
 (:scroll-down (event) (send textw :scroll -1))
 (:refresh (event) (send textw :refresh))
 )

(setq frm (instance windowframe :create :width 512 :height 800))
(setq vv (instance textviewpanel :create "Xdecl.l"))
(setq jj (instance joystick-item :create "joy" nil nil :return t))
;(setq ff (instance fileopendialog :create :background "#f8e8d0"))
(xflush)


;(window-main-loop)


