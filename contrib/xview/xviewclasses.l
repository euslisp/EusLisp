;;;
;;;	Classes for eusview
;;;						1988.11.13 M.Inaba
;;;   propertied-object
;;;     sunview-mouse
;;;	sunview-object
;;;	  sunview-widget
;;;         sunview-window
;;;	      sunview-frame
;;;	      sunview-canvas
;;;	      sunview-panel
;;;	      sunview-textsw
;;;	      sunview-tty
;;;         panel-item
;;;	      panel-button-item
;;;	      panel-text-item
;;;           panel-slider-item
;;;	      panel-selectable-item
;;;	         panel-choice-item
;;;	         panel-cycle-item
;;;	         panel-toggle-item
;;;	      panel-message-item
;;;	  sunview-menu
;;;
(defclass sunview-mouse
  :super object
  :slots
  (current-button    ;;; left, middle, right, nil
   current-movement  ;;; move, up, down, drag, still,
                     ;;; winenter, winexit, rgnenter, rgnexit, nil
   last-button
   last-movement))
(defclass sunview-object
  :super propertied-object
  :slots
  (system-cadr))
(defclass sunview-widget
  :super sunview-object
  :slots
  (parent
   font
   menu
   mouse
   event-handler-list		;; (mouse-status . handler)
   ))
(defclass sunview-window
  :super sunview-widget
  :slots
  (subwindows
   itimer-handler
   ))
(defclass sunview-frame
  :super sunview-window
  :slots
  (name
   icon))
(defclass sunview-panel
  :super sunview-window
  :slots
  (item-object-list  	;; (item-cadr . item-object)
   item-size
   col-max
   item-col
   item-row
   ))
(defclass sunview-canvas
  :super sunview-window
  :slots
  (resize-handler
   repaint-handler
   ))
(defclass sunview-textsw
  :super sunview-window
  :slots ())
(defclass sunview-tty
  :super sunview-window
  :slots ())
(defclass panel-item
  :super sunview-widget
  :slots
  (name
   col row
   notify-handler  ;;	function or method
   ))
(defclass panel-button-item
  :super panel-item
  :slots ())
(defclass panel-text-item
  :super panel-item
  :slots ())
(defclass panel-slider-item
  :super panel-item
  :slots ())
(defclass panel-selectable-item
  :super panel-item
  :slots (choices strings))
(defclass panel-choice-item
  :super panel-selectable-item
  :slots ())
(defclass panel-cycle-item
  :super panel-selectable-item
  :slots ())
(defclass panel-toggle-item
  :super panel-selectable-item
  :slots ())
(defclass panel-message-item
  :super panel-item
  :slots ())
(defclass sunview-menu
  :super sunview-object
  :slots
  (choices
   strings))
;;;
(defclass canvas-viewsurface
  :super viewsurface
  :slots
  (color
   frame
   (canvas :forward (:cmsname
		     :set-cmap-type
		     :put-colormap :get-colormap
		     :drawline  :drawimage :drawtext :imagemove
		     :pixwin :width :height
		     ))
   pixwindow
   rasterop
   back-pixwindow
   buffer-mode))
