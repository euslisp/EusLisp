;;;;
;;;; Xwindow scroll-bar window
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1993
;;;;

(in-package "X")
(require :xdecl   "Xdecl.l")

;;(defclass Xscroll-bar :super xwindow
;;	:slots (arrow-length handle-pos handle-length
;;		verticalp
;;		handle-grabbed))

(defmethod Xscroll-bar
 (:create (&rest args
	   &key
		parent
		((:height h))
		handle
	   &allow-other-keys)
   (if (null h)
       (setq h  (if parent (- (send parent :height) 15) 150)))
   (send-super* :create :border-width 1 :event-mask #xf0f
	 :parent parent :height h args)
;;   (send self :background-pixmap *gray25-pixmap*)
   (setq width (send self :width)
	 height (send self :height)
	 arrow-length (/ (* 3 (min width height)) 4)
	 handle-pos arrow-length
	 handle-length arrow-length)
   (setq verticalp (> height width))
   (if parent
	(send self :move
		(if verticalp
	    	    (- (send parent :width) width 2)
		    0)
		(if verticalp
		    0
	    	    (- (send parent :height) height 2)) ))
   (send self :draw-pattern)
   (send self :move-handle 0.0 0.1)
   self)
 (:draw-pattern ()
    (let ((width/2 (/ width 2)))
      (send self :line width/2 0 0 (1- arrow-length))
      (send self :line 0 (1- arrow-length) width (1- arrow-length))
      (send self :line width (1- arrow-length) width/2 0)
    ;;(send self :fill-rectangle 0 0 width arrow-length *gray50-gc*)
      (send self :line width/2 height 0 (- height arrow-length))
      (send self :line 0 (- height arrow-length) width (- height arrow-length))
      (send self :line width (- height arrow-length) width/2 height)
    ;;(send self :fill-rectangle 0 (- height arrow-length)
    ;;			width arrow-length *gray50-gc*)
    ) )
 (:resize (w h)
    (send-super :resize w h)
    (send self :flush)
    (setq width w height h)
    (send self :draw-pattern))
 (:move-handle (&optional (newpos 0.0) (handle-size 0.1))
    (declare (float newpos handle-size))
    (if verticalp 
	(send self :clear-area :y handle-pos :height handle-length)
	(send self :clear-area :x handle-pos :width handle-length))
    (let ((movable (- (if verticalp height width) (* 2 arrow-length))))
	(setq handle-length (round (* movable handle-size)))
	(setq movable (- movable handle-size))
	(setq handle-pos (+ arrow-length 
			    (round (* movable newpos))) )
	(if verticalp
	    (send self :fill-rectangle 0 handle-pos
			width handle-length *gray75-gc*)
            (send self :fill-rectangle handle-pos 0
			handle-length height *gray75-gc*) )
	(xflush)
        )))

(defmethod Xscroll-bar
 (:hit-region (event)
     (let* ((x (event-x event)) (y (event-y event)) yy vheight)
	(if verticalp (setq yy y vheight height) (setq yy x vheight width))
	(cond
	   ((or (< x 0) (< width x) (< y 0) (< height y)) :outside)
	   ((< yy arrow-length) :up-arrow)
	   ((< yy handle-pos) :up-screen)
	   ((< yy (+ handle-pos handle-length)) :handle)
	   ((< yy (- vheight arrow-length)) :down-screen)
	   ((< yy vheight) :down-arrow)
	   (t nil))))
 (:buttonPress (event)
    (send self :draw-pattern)
    (case (send self :hit-region event)
	(:handle (setq handle-grabbed (event-y event)))
	(:up-arrow (send parent :scroll -1))
	(:down-arrow (send parent :scroll 1))
	(:up-screen (send parent :scroll (- (send parent :win-row-max))))
	(:down-screen (send parent :scroll (send parent :win-row-max)))
	(t nil)) )
 (:motionNotify (event)
    (if handle-grabbed
	(let* ((x (event-x event)) (y (event-y event))
		(fy (/ (float (- y handle-grabbed))
		       (- height (* 2 arrow-length)) )))
	   (when (>= (abs fy) (send parent :scroll-fraction))
		(send parent :scroll fy)
		(setq handle-grabbed y)))
	))
 (:buttonRelease (event)
    (setq handle-grabbed nil) )
)



;(defclass Xhorizontal-scroll-bar :super xscroll-bar)

(defmethod Xhorizontal-scroll-bar
 (:create (&rest args
	   &key
		(parent)
		((:width w))
	   &allow-other-keys)
    (if (null w)
	(setq w (if parent (- (send parent :width) 15) 100)))
    (send-super* :create :width w args)
    self)
 (:draw-pattern ()
    (let ((height/2 (/ height 2)))
      (send self :line 0 height/2 (1- arrow-length) 0)
      (send self :line (1- arrow-length) 0 (1- arrow-length) height)
      (send self :line (1- arrow-length) height 0 height/2)
      ;; (send self :fill-rectangle 0 0 arrow-length height *gray50-gc*)
      (send self :line width height/2 (- width arrow-length) 0)
      (send self :line (- width arrow-length) 0 (- width arrow-length) height)
      (send self :line (- width arrow-length) height width height/2)
      ;;(send self :fill-rectangle (- width arrow-length) 0
      ;;		arrow-length height *gray50-gc*)
      (send self :flush)
    ) )
  )

(defmethod Xhorizontal-scroll-bar
 (:buttonPress (event)
    (send self :draw-pattern)
    (case (send self :hit-region event)
	(:handle (setq handle-grabbed (event-x event)))
	(:up-arrow (send parent :horizontal-scroll -1))
	(:down-arrow (send parent :horizontal-scroll 1))
	(:up-screen (send parent :horizontal-scroll (- (send parent :win-col-max))))
	(:down-screen (send parent :horizontal-scroll (send parent :win-col-max)))
	(t nil)) )
 (:motionNotify (event)
    (if handle-grabbed
	(let* ((x (event-x event)) (y (event-y event))
		(fx (/ (float (- x handle-grabbed))
		       (- width (* 2 arrow-length)) )))
	   (when (>= (abs fx) (send parent :horizontal-scroll-fraction))
		(send parent :horizontal-scroll fx)
		(setq handle-grabbed x)))
	))
)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(provide :Xscroll "@(#)$Id: Xscroll.l,v 1.1.1.1 2003/11/20 07:46:35 eus Exp $")

