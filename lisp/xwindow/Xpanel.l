;;;;
;;;; Xwindow panel
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1993
;;;;

(in-package "X")
(require :xdecl   "Xdecl.l")
(eval-when (compile eval) (require :Xtop "Xtop"))

(export '())

;;;;;;;;;;;;;;;;;;;;
;; P A N E L
;;;;;;;;;;;;;;;;;;;;

(defmethod panel
 (:create (&rest args
	   &key ((:item-height iheight) 28)
		((:item-width iwidth) 50)
		(font font-lucidasans-bold-12)
		((:background color))
		(parent)
		(event-mask nil)
	   &allow-other-keys)
    (unless color
	(setq color
		(if parent (send self :background) *bisque1*)))
    (send-super* :create :border-width 1 :background color
		 :parent parent
		 :event-mask event-mask args)
    (setq fontid (if (numberp font) font (font-id font)))
    (send gcon :font fontid)
    (setf item-width iwidth
	  item-height iheight)
    (setq rows (/ (send self :height) item-height)
	  columns (/ (send self :width) item-width))
    (setq items nil
	  next-x 0
	  next-y 0)
    (setf light-edge-color (get-lighter-pixel bg-color 1.4 (send self :colormap))
	  dark-edge-color  (get-lighter-pixel bg-color 0.6 (send self :colormap))
	  topleft-edge-polygon
		(make-topleft-edge-polygon 0 0 width height 2) )
    (send self :flush)
    self)
 (:expose (event)
    (send self :redraw)
    ;(send-all subwindows :expose event)
     )
 (:redraw () )
 (:resize (w h)
    (send-super :resize w h)
    (setq topleft-edge-polygon
		(make-topleft-edge-polygon 0 0 w h 2) )
    self)
 (:items () items)
 (:locate-item (item &optional x y)
    (let ((width-left (- (send self :width) next-x 10)))
      (send self :associate item)
      (when (< width-left (send item :width))
	(setq next-x 0)
	(setq next-y
	     (max (+ next-y  item-height)
		  (apply #'max 0
			 (mapcar
			    #'(lambda (item) (+ (send item :height)
						(send item :y)))
			    items)))) )
      ;; when :x/:y is not given, provide default item position
      (unless x (setq x (+ next-x 5)))
      (unless y (setq y (+ next-y 5)))
      (send item :move x y)
      (setq next-x (+ next-x (max item-width (+ (send item :width) 5)))
	    next-y (- (send item :y) 5))
     (send item :map)
     (push item items)
     item) )
 (:create-item (klass label receiver method 
		&rest args
		&key (x) (y) (font fontid)
		&allow-other-keys)
      (send self :locate-item
	     (instance* klass :create label receiver method
		:font font
		:parent self
		:map nil
		args)
	     x y) )
 (:create-menubar ( &rest args
		&key (x 0) (y 0) (font fontid)
		&allow-other-keys)
    (let (menubar)
	(setq menubar (instance* menubar-panel :create
		:font font
		:parent self
		:map nil
		args)) 
       (setq next-y (send menubar :height))
       (send self :locate-item menubar x y)
    )
  )
 (:active-menu (w)
    (if (and active-menu (not (eql w active-menu)))
	(send active-menu :unmap-menu))
    (setq active-menu w)
    (send active-menu :popup-menu))
 (:delete-items ()
    (setq next-x 0  next-y 0)
    (send-all items :destroy)
    (setq items nil))
 )
;; notifiers
;; applications can override following methods
;; but what should happen when a button is pressed inside the panel?

(defmethod panel
 (:quit (&rest a) (throw :window-main-loop nil))
 (:KeyEnter (pos) nil)
; (:KeyRelease (pos) nil)
 (:ButtonPress (pos) nil)
 (:ButtonRelease (pos) nil)
 (:MotionNotify (pos) nil)
 (:EnterNotify (event) 
     ;; (if drawable (setinputfocus *display* drawable 1 0))
    ;; BadMatch error occurs when the window is unmapped
     )
 (:LeaveNotify (pos) nil))


;;;;;;;;;;;;;;;;;;;;
;; MenuBar
;;;;;;;;;;;;;;;;;;;;

(defmethod menubar-panel
 (:create (&rest args
	   &key (font font-lucidasans-bold-12)
		width height
	   &allow-other-keys)
    (let* (xsize ysize labeldots)
      (setf labeldots (textdots "x" font))
      (setq xsize
             (if (null width) 60 width))
      (setq ysize
         (if height
	     height
	     (+ (aref labeldots 0) (aref labeldots 1) 6)))
      (send-super* :create :width xsize :height ysize :border-width 0 args)
      (send self :3d-fill-rectangle 0 0 width height 2
		  light-edge-color dark-edge-color bg-color
		  topleft-edge-polygon)
      (setq next-x 3 next-y 2)
      (send self :flush)
      self)
   )
 (:locate-item (item &optional x y)
    (let ((width-left (- (send self :width) next-x 10)))
      (when (< width-left (send item :width))
	(setq next-x 3)
	(setq next-y (+ next-y item-height)))
      ;; when :x/:y is not given, provide default item position
      (send item :move next-x next-y )
      (setq next-x (+ (send item :x) (send item :width))
	    next-y  (send item :y) )
     (send item :map)
     (push item items)
     item) )
 (:popup-all-menus ()     (send-all items :popup-menu))
 (:unmap-all-menus ()     (send-all items :unmap-menu))
 )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(provide :xpanel "@(#)$Id: Xpanel.l,v 1.1.1.1 2003/11/20 07:46:35 eus Exp $")

