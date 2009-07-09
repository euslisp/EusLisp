;;;;
;;;; CANVAS
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1993
;;;;

(in-package "X")
(require :Xdecl   "Xdecl.l")

(defmethod canvas
 (:create (&rest args)
    (send-super* :create args)
    (setq menu (instance x:menu-panel :create))
    (send menu :create-item x:button-item
		"red" self (list :color-event  
		(send *color-map* :alloc #xffff #x1000 #x1000)))
    (send menu :create-item x:button-item
		"blue" self (list :color-event
		(send  *color-map* :alloc #x1000 #x1000 #xffff)))
    (send menu :create-item x:button-item
		"green" self (list :color-event
		(send  *color-map* :alloc #x1000 #xffff #x1000 )))
    (send menu :create-item x:button-item "clear"
		self :clear-event)
    (send menu :create-item x:button-item
		"white back" self (list :background-event
		(send  *color-map* :alloc #xffff #xffff #xffff )))
    (send menu :create-item x:button-item
		"lightgray back" self (list :background-event 
		(send  *color-map* :alloc #xc000 #xc000 #xc000 )))
    (send menu :create-item x:button-item
		"darkgray back" self (list :background-event
		(send  *color-map* :alloc #x4000 #x4000 #x4000 )))
    (send menu :create-item x:button-item
		"black back" self (list :background-event
		(send  *color-map* :alloc 0 0 0 )))
    self)
 (:selection () (list topleft bottomright))
 (:adjust-corners ()
    (let ((corner1 (integer-vector 
			(min (aref topleft 0) (aref bottomright 0))
			(min (aref topleft 1) (aref bottomright 1))))
	  (corner2 (integer-vector 
			(max (aref topleft 0) (aref bottomright 0))
			(max (aref topleft 1) (aref bottomright 1)))))
        (psetq bottomright corner2
	       topleft corner1 )) )
 (:draw-selection-rectangle ()
    (let ((corner (integer-vector 
			(min (aref topleft 0) (aref bottomright 0))
			(min (aref topleft 1) (aref bottomright 1)))))
       (send self :draw-rectangle corner
	    (abs (- (aref bottomright 0) (aref topleft 0)))
	    (abs (- (aref bottomright 1) (aref topleft 1))))
    ))
 (:buttonpress (event)
    (let ((state (event-button event)))
	(cond ((<= state 2)
	       (send self :function :xor)
	       (send gcon :foreground 127)
	       (setq topleft (event-pos event) bottomright (copy-seq topleft))
	       (send self :draw-selection-rectangle)
	       (setf buttonActive T))
	      ((eql state 3)
		(send menu :popup (event-x-root event) (event-y-root event))
		)
	)))
 (:motionnotify (event)
   (when buttonActive
     (let ((state (event-state event)))
	(cond ((member :left state)
	        (send self :draw-selection-rectangle)
	        (setq bottomright (event-pos event))
	        (send self :draw-selection-rectangle))
	      ((member :right state)
		(send menu :motionnotify event))
	  )
	)
    ))
 (:buttonrelease (event)
    (cond (buttonActive
	    (let ((state (event-state event)))
	      (cond ((and (member :control state) (member :right state))
		     (send self :clear)
		     (send self :function :copy))
		    ((member :right state)
		     (setq *buttonrelease-wanted* menu) )
		    (t 
		       (send self :draw-selection-rectangle)
		       (send self :function :copy)
		       (setq bottomright (event-pos event))
		       (setf buttonActive nil)) )))
	  (t (send-super :buttonrelease event))) )
 (:clear-event (e ) #|e=self|#   (send self :clear))
 (:color-event (color e)
    (send self :foreground (car color)) )
 (:background-event (color e)
    (send self :background (car color))    )
)

(defclass graph-canvas :super canvas
	:slots (pixmap ymax ymin prev-y graph-args xinc yinc gcs count))

(defmethod graph-canvas
 (:create (&rest args 
	    &key (max 1.0) (min -1.0)
		 (background *blackpixel*)
		 (lines 1) (colors) (color *whitegc*)
	    &allow-other-keys)
	(send-super* :create :background background args)
	(send self :new-pixmap)
	(send self :range max min)
	(send self :lines lines)
	(cond (colors (send self :colors colors))
	      (color
		(setq gcs (make-array lines :initial-element
		   (if (derivedp color gcontext)
		       color
		       (make-color-gc color))))	 )
	   )
	(setq count 0)
        (send self :clear)
	self)
 (:new-pixmap (&optional (w width) (h height))
    (setq pixmap (instance xpixmap :create :width w :height h))
;;    (send pixmap :foreground fgcolor)
;;    (send pixmap :background bgcolor)
    self)
 (:range (max &optional (min 0.0)) 
    (setq ymax max ymin min)
    self)
 (:lines (n)
    (setq prev-y (make-array n :initial-element ymin)))
 (:colors (cs)
    (setq gcs (make-array (length prev-y)))
    (let ((color))
       (dotimes (i (length prev-y))
	 (setq color (pop cs))
	 (setf (aref gcs i)
	     (if (derivedp color gcontext)
		 color
		 (make-color-gc color)))))
    )
 (:graph (&rest args)
;;    (send* pixmap :graph args)
    (setq graph-args args)
    (send-super* :graph args)
    (send pixmap :copy-from self)
    self)
 (:incremental-graph (new-values)
    (CopyArea *display* drawable drawable (gcontext-gcid gcon)
                1 0	;source-x source-y
		(1- width) height
		0 0 )	; dest-x dest-y
    (ClearArea  *display* drawable
		(1- width) 0 1  height 0) 	; x, y, width, height 
    ;;
    (let (newval ny py g)
      (dotimes (i (length new-values))
	(setq py (aref prev-y i)
	      newval (aref new-values i)
	      ny (- height (round (* height (/ (float newval) (- ymax ymin)))))
	      g (aref gcs i))
        ;; (send gc :function :copy)
	;; (format *error-output* "py=~s ny=~s~%" py ny)
        (send self :line (- width 2) py width ny g)
        ;; (send self :point (1- width) new-y gc)
        (setf (aref prev-y i) ny))
      (if (zerop (mod (incf count) 10)) 
	  (send pixmap :copy-from self))
      )
    )
 (:clear ()
    (setq graph-args nil)
    (send-super :clear)
    (send pixmap :copy-from self))
 (:resize (x y)
    (send self :new-pixmap x y)
    (send-super :resize x y)
    (send self :flush)
    )
 (:redraw ()
    (if graph-args  (send* self :graph graph-args)))
 )


;;****************************************************************

(export '(pixmap-scroller))

(defclass pixmap-scroller :super panel
		:slots (pixwin vscroll hscroll pixmap
			start-x start-y pix-width pix-height))
(defmethod pixmap-scroller
 (:create (&rest args
	   &key
		pixmap
	   &allow-other-keys)
    (send-super* :create args)
    (print (list width height))
    (setq pixwin (instance xwindow :create :parent self
			:width (- width 15) :height (- height 15))
	  vscroll (instance xscroll-bar :create :parent self
			:width 10)
	  hscroll (instance x:xhorizontal-scroll-bar :create
			:parent self :height 10))
    (send self :reset-subwindows)
    (if pixmap   (send self :set-pixmap pixmap))
    self)
 (:reset-subwindows ()
    (send pixwin :resize (- width 15) (- height 15))
    (send vscroll :move (- width 13) 0)
    (send hscroll :move 0 (- height 13))
    self)
 (:set-pixmap (pmap)
    (setq pixmap pmap
	  start-x 0
	  start-y 0
	  pix-width (send pmap :width)
	  pix-height (send pmap :height)
	)
    (send pixwin :copy-from pixmap)
    pixmap)
 (:scroll (&optional (n 1) &aux srcy desty erasey)
    (cond ((= n 0) (return-from :scroll nil))
	  ((> n 0) (setq srcy n
			 desty 0
			 erasey (- (/ (send self :height) 16)   n)))
	  (t (setq srcy 0 desty (abs n) erasey 0)))
    (setq n (min (/ (send self :height) 16) (abs n)))
    (format t "; :scroll n=~s srcy=~s desty=~s erasey=~s~%"
		n srcy desty erasey)
    (send pixwin :Copy-from  pixwin
		:source-x 2 :source-y (+ 2 (* srcy 12))
		:width width :height (* (- (/ (send self :height) 16) n) 12)
		:x 2  :y(+ 2 (* desty 12))	; dest-x dest-y
		)
    (send pixwin :Clear-Area  
		:x 2 :y (+ 2 (* erasey 12))		; x, y
		:width width :height (* n 12))
    )

 )



(provide :Xcanvas "@(#)$Id$")
