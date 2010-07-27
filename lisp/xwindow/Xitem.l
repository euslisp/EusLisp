;;;;
;;;; Xwindow panel-items
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1993
;;;;

(in-package "X")
(require :xdecl   "Xdecl.l")
(export '(*buttonRelease-wanted*))
(defvar *buttonRelease-wanted* nil)

;; panel-item
;;   button-item
;;     menu-button-item
;;     bitmap-button-item
;;   text-item
;;   slider-item
;;   choice-item

(defun clump (minval val maxval)   (max minval (min val maxval)))

(defun replace-key-arg (key val args)
   (let ((p))
      (while args
	 (if (eql key (first args))
	     (setq args (cddr args))
	     (progn (push (pop args) p) (push (pop args) p))))
      (list* key val (nreverse p))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; panel-items
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod panel-item
 (:create (name receiver method
 	   &rest args
	   &key ((:size s) 100)
		((:width w) s) ((:height h) w) (font font-courb12)
	   &allow-other-keys)
    (setf  width w
	   height h
	   fontid font
	   label name
	   notify-method method
 	   notify-object (if receiver receiver parent))
    (send-super* :create :name name :width w :height h :font font args)
    (send self :name name)
    (setf labeldots (textdots name font))
    )
 (:draw-label (x y)
    (send gcon :function :copy)
    (send self :image-string x (+ y (aref labeldots 0)) label)
    label)
 (:notify (&rest args)
    (if (and notify-object notify-method)
       (if (listp notify-method)
           (send* notify-object (car notify-method) (cdr notify-method)
		self args)
           (send* notify-object notify-method self args)))
  )
 (:KeyPress (pos) nil)
 (:KeyRelease (pos) nil)
 (:ButtonPress (pos) nil)
;; donot override xwindow's default :buttonrelease (:ButtonRelease (pos) nil)
 (:MotionNotify (pos) nil)
 (:EnterNotify (event) nil)
 (:LeaveNotify (pos) nil))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; button-item
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun make-topleft-edge-polygon (x y w h b)
   (let ((vertex-array (instantiate string (* 2 2 6)))) ;xy*short*6word
      (send vertex-array :set 
	 (list	x y 
		w 0
		(- b) b
		(+ (- w) b b) 0
		0 (- h b b)
		(- b) b)
	  0 :short)
      vertex-array))


(defmethod button-item
 (:create (label receiver method	;;should have alternate labels
		 &rest args
		 &key ((:width wid)) ((:height hei)) 
		      (parent *root*)
		      (event-mask '(:button))
		      (font font-lucidasans-bold-12)
		      (foreground *blackpixel*)
;		      ((:background  bg) nil)
		      (border-width 0)
		      (state (if (derivedp parent menu-panel) :flat :up))
		      (active-color nil)
		      (submenu nil)
		 &allow-other-keys)
    (let* (xsize ysize)
      (setf labeldots (textdots label font))
      (setq xsize
	     (if wid wid (+ (aref labeldots 2) 10)))
      (setq ysize
	 (if hei hei (+ (aref labeldots 0) (aref labeldots 1) 6)))
;      (unless bg
;	 (setq bg (send parent :gc :background)))
      (send-super* :create label receiver method
			:width xsize :height ysize :border-width border-width 
			:parent parent
			:foreground foreground
			;;  :background bg
			:event-mask event-mask
			args)
      (setf light-edge-color (get-lighter-pixel bg-color 1.4 (send self :colormap))
	    dark-edge-color  (get-lighter-pixel bg-color 0.6 (send self :colormap))
	    topleft-edge-polygon
		(make-topleft-edge-polygon 0 0 width height 2) )
      (setf 3D-state state)
      (setf activeColor active-color)
      (send gcon :font font)
      (setf (button-item-label self) label)
      (send self :draw-label state)
      )
    (setf (button-item-submenu self) submenu)
    (send gcon :function :copy)
    self)
 (:submenu (&optional sm) 
    (if sm (setq submenu sm))
    submenu)
 (:active-color (&optional pix)
    (if pix (setq activecolor pix))
    activeColor)
 (:resize (w h)
    (send-super :resize w h)
    (setq topleft-edge-polygon
		(make-topleft-edge-polygon 0 0 w h 2) )
    (send self :draw-label 3D-state)
    )
 (:label (&optional (newlab) (min-width 10))
    (when newlab
      (let* (xsize ysize)
        (setf labeldots (textdots newlab fontid))
        (setq xsize (max min-width (+ (aref labeldots 2) 10)))
        (setq ysize (+ (aref labeldots 0) (aref labeldots 1) 6))
        (setf label newlab)
        (send self :resize xsize ysize)))
    label)
 )

(defmethod button-item
 (:draw-label (&optional (state :up) (color bg-color) (border 2) (offset))
      (send self :3d-fill-rectangle  0 0 width height border
		light-edge-color dark-edge-color bg-color
		topleft-edge-polygon state)
      (unless offset
	 (setq offset
		 (cdr (assoc state '((:up . 0) (:down . 2) (:flat . 1))))))
      (unless offset (setq offset 0))
      (send self :string 
		(+ ;4
		   (/ width 2)
		   (- (/ (aref labeldots 2) 2))
		   offset)			;x
		(+ ;; (aref labeldots 0) 2 
		   (/ height 2) (aref labeldots 0)
		   (- (/ (+ (aref labeldots 0) (aref labeldots 1)) 2))
		   offset)	;y
		label)
      (send self :flush)
       )
 (:redraw ()
    (send self :draw-label 3d-state))
 )

(defmethod button-item	;; event handlers
 (:KeyPress (event) nil )
 (:KeyRelease (event) nil)
 (:ButtonPress (event)
    (send self :draw-label :down)
    (setq buttonPressed T)
    nil)      
 (:ButtonRelease (event)
    (let ((x (event-x event)) (y (event-y event)))
        (send self :draw-label 3D-state)
        (when (and (or buttonPressed (derivedp parent menu-panel))
		   (< 0 x width) (< 0 y height))
	    (setq buttonPressed nil)
	    (if submenu
		(send submenu :popup (event-x-root event) (event-y-root event))
 	        (send self :notify)))
	    )
    (if parent (send parent :buttonRelease event)  ))
 (:EnterNotify (event)
    (if activeColor (send self :draw-label :up activeColor))  )
 (:LeaveNotify (event)
    (if activeColor (send self :draw-label 3D-State)))
)


;****************************************************************
;; menu-button-item
;;   When a menu-button is pressed, pop-up or pull-down menu
;;   associated to the button appears.
;;   Entries in each menu should be created as normal button-items.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod menu-button-item
 (:create (label receiver method
		&rest args
		&key (menu nil)
		     (items)
		     (state :flat)
		&allow-other-keys)
    (send-super* :create label receiver method :state state
			:event-mask '(:button :ownergrabbutton :enterLeave)
			args)
					;  Tcl/Tk like menu button
    (setf menu-window menu)
;;     (send menu :menu-button self)
    self)
 (:label (&optional (newlab))
    (when newlab
      (let ((prev-width width))
         (send-super :label newlab)
	 (if (/= prev-width width) (send parent :newsize))))
    label)
 (:popup-menu ()
    (send self :draw-label :up bg-color 2) ; Tcl/Tk like menu button action
    (let ((pos (send self :global-pos)))
       (send menu-window :popup (aref pos 0) 
			(+ (aref pos 1) (send self :height))
			(send self :height)) ) )
 (:unmap-menu ()
    (send self :draw-label :flat)
    (send menu-window :unmap))
 (:buttonPress (event)
    (setq *ButtonRelease-wanted* self)
    (send parent :active-menu self)
    (send self :popup-menu)
    )
 (:buttonRelease (event)
    (if (eq *buttonRelease-wanted* self)
	(progn (setq *buttonRelease-wanted* nil)
	    (send self :unmap-menu)
	    (send self :notify) )
	(send-super :buttonRelease event))
    )
 (:enterNotify (event)
   (if (event-pressed event t)
       (send parent :active-menu self))
   )
 )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; TEXT-item
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defmethod text-item
 (:create (label receiver method
		 &rest args
		 &key (font font-courb12)
		      (columns 20)
		      (initial-value )
		      (border-width 0)
		 &allow-other-keys)
      (setq labeldots (textdots label font))
      (let* ((chardots (textdots "x" font))
 	     (charheight (+ (aref chardots 0) (aref chardots 1))) 
	     (charwidth (aref chardots 2))
	     (textwidth (* columns charwidth)))
	(send-super* :create label receiver method
		:width  (+ (aref labeldots 2) 8 textwidth 4)
		:height (+ charheight 6)
		args)
	(setq args (replace-key-arg :parent self args))
	(setq args (replace-key-arg :border-width 1 args))
        (setq textwin (instance* buffertextwindow :create
			:parent self
			:show-cursor t
			:font font
			:columns columns
			:rows 1
			:event-mask '(:button :enterleave :key)
			:notify-object receiver
			:notify-method method
			args))
	(send textwin :move (+ (aref labeldots 2) 4) 0)
	(send textwin :cursor :off)
	(if initial-value (send self :value initial-value))
	(send self :redraw)
	)
    self)
 (:redraw ()
    (send self :draw-label 1 4)
    (send textwin :redraw)    )
 (:getstring ()  (send textwin :line 0))
 (:value (&optional newval invocation &aux ln)
     (if (stringp newval)
	 (progn (send textwin :clear)
		(send textwin :insert-string newval)))
     (setq ln (send textwin :line 0))
     (if invocation (send self :notify ln))
     ln)
 (:LeaveNotify (event)   (send textwin :LeaveNotify event))
 (:EnterNotify (event)   (send textwin :EnterNotify event))
)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; slider-item
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defmethod slider-item
 (:create (label receiver method
	   &rest args
	   &key (min 0.0) (max 1.0) (parent)
		(min-label ) (max-label ) (value-format "~4,2f")
		(font font-courb12)
		(span 100)
		(border-width 0)
		(initial-value min)
		(continuous-update t)
	   &allow-other-keys) 
     (setf value initial-value
	   valueformat value-format
	   nob-moving nil)
     (send self :new-range min min-label max max-label)
     (setq labeldots (textdots label font)
           valuedots (textdots (format nil value-format value)))
     (setq charwidth (textdots "x" font))
     (setq charwidth  (aref charwidth 2))
     (send-super* :create label receiver method
	   :border-width border-width
	   :width (+ (aref labeldots 2)
		     (* charwidth
			(+ (length minlabel) (length maxlabel)))
		     (aref valuedots 2)
                     span 60)
	   :height (+ 10 (aref labeldots 0) (aref labeldots 1)) 
	   :font font
	   args)
     (setq bar-x (+ (aref labeldots 2) (aref valuedots 2)
		    (* charwidth (length minlabel))
		    17)
	   bar-y (+ 3 (/ (+ (aref labeldots 0) (aref labeldots 1)) 2) )
	   bar-width span
	   bar-height 3
	   nob-x (send self :nob-x))
     (setq label-base (+ 5 (aref labeldots 0)))
     (send self :continuous-notify continuous-update)
     (send self :redraw)
     self )
 (:new-range (min min-label max max-label)
     (setf min-value min
	   max-value max)
     (if (null (stringp min-label))
	 (setq min-label (format nil valueformat min)))
     (setq minlabel min-label)
     (if (null (stringp max-label))
	 (setq max-label (format nil valueformat max)))
     (setq maxlabel max-label)
     )
 (:continuous-notify (flag)
     (prog1 continuous-notify (setq continuous-notify flag)))
 (:redraw ()
     (send self :draw-bar-rectangle)
     (send self :draw-nob-rectangle)
     (send self :image-string 3 label-base label) 
     (send self :image-string (+ 13 (aref labeldots 2) (aref valuedots 2))
			label-base minlabel)
     (send self :image-string (+ 23 (aref labeldots 2) (aref valuedots 2)
			      (* charwidth (length minlabel))  bar-width)
			label-base maxlabel)
     (send self :display-value value))
 (:display-value (&optional (newval value))
     (setq newval (float (max min-value (min max-value newval))))
     (if (integerp max-value) (setq newval (round newval)))
     (send self :image-string (+ 7 (aref labeldots 2)) label-base
			(format nil valueformat newval)) )
 (:value (&optional (newval) (invocation))
     (when newval
           (send self :display-value newval)
	   (send self :draw-nob-rectangle nob-x (send self :nob-x newval))
           (setq nob-x (send self :nob-x newval))
	   (setq value newval))
     (if invocation (send-super :notify value))
     value)
 (:nob-x (&optional (v value))
	%(bar-x + ((v - min-value) * bar-width / (max-value - min-value))) )
 (:inside-nob-p (pos)
     (and (<= nob-x (aref pos 0) (+ nob-x 7))
	  (<=  (- bar-y 5) (aref pos 1) (+ bar-y 5))))
 (:draw-bar-rectangle ()
     (send self :rectangle bar-x bar-y (+ 5 bar-width) bar-height))
 (:draw-nob-rectangle (&optional (oldx nob-x) (newx nob-x))
     (send gcon :foreground bg-color)
     (send self :fill-rectangle oldx (- bar-y 5) 7 13)
     (send gcon :foreground *fg-pixel*)
     (send self :draw-bar-rectangle)
     (send self :fill-rectangle newx (- bar-y 5) 7 13))
 (:buttonPress (event)
    (let ((pos (event-pos event)))
	(if (send self :inside-nob-p pos)
	    (setq nob-moving (event-pos event)))))
 (:compute-value (event)
     (let* ((dx (float (- (aref (event-pos event) 0) bar-x 3)))
	    (newval (clump min-value
			 %(min-value +
			   (dx / bar-width ) * (max-value - min-value))
			max-value)) )
	   newval) )
 (:MotionNotify (event)
    (when nob-moving
	   (send self :value (send self :compute-value event)
			     continuous-notify)))
 (:buttonRelease (event)
    (if nob-moving 
	(progn
	   (setf nob-moving nil)
	   (send self :value (send self :compute-value event) t))
	(send-super :buttonRelease event)))
  )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; panel choice
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod choice-item
 (:create (label receiver method
	   &rest args
	   &key (parent *root*)
		(choices '("0" "1"))
		(font)
		(initial-choice 0)
		(button-size 13)	;width and height of a button
		(border-width 0)
		(event-mask nil)
	   &allow-other-keys
	   &aux choice-y choice-dots)
     (setf choice-list	(mapcar #'list choices)
	   active-choice initial-choice
	   (choice-item-button-size self) button-size)
     (unless font
	 (setq font (send parent :gc :font)))
     (setq labeldots (textdots label font))
     (dolist (c choices) (push (aref (textdots c font) 2) choice-dots))
     (nreverse choice-dots)
     (send-super* :create label receiver method
	   :parent parent
	   :border-width border-width
	   :width (+ (aref labeldots 2)
		     (apply #'+ choice-dots)
		     (* (length choices) 5)
                     20)
	   :height (+ 10 button-size (aref labeldots 0) (aref labeldots 1)) 
	   :font font
	   :event-mask (union event-mask '(:button))
	   args)
     ;;
     (setq choice-y (+ (aref labeldots 0) (aref labeldots 1) (/ button-size 2)))
     (let ((p (+ 5 (aref labeldots 2))) cwidth)
	(dolist (c choice-list)
	   (nconc c (list  p (+ (aref labeldots 0) 3)))	;string pos
	   (setq cwidth (+ 4 (pop choice-dots)))
	   (nconc c (list (integer-vector %((cwidth / 2) + p - (button-size / 2))
				 choice-y)))	;arc pos
	   (incf p  cwidth)))
     (send self :redraw)
     ;;
     (send self :draw-active-button )
     self
   )
 (:draw-label (&optional (lab (get self :name)))
     (send self :string 3 (/ (send self :height) 2) lab))
 (:redraw ()
    (send self :draw-label)
    (dolist (c choice-list)
	(send self :string (second c) (third c) (car c) )
	(send self :draw-arc (fourth c) button-size) )
    (send self :draw-active-button )
    )
 (:value (&optional (new-choice) invocation)
    (when new-choice
	(send self :draw-active-button active-choice new-choice)
        (setq active-choice new-choice))
    (if invocation
	(send-super :notify active-choice))
    active-choice)
 (:draw-active-button (&optional
			(old-choice active-choice) (new-choice active-choice))
    (send gcon :foreground bg-color)
    (send self :draw-fill-arc (v+ (fourth (elt choice-list old-choice))
				  #i(1 1)) (- button-size 2))
    (send gcon :foreground *fg-pixel*)
    (send self :draw-fill-arc (v+ (fourth (elt choice-list new-choice))
				  #i(1 1))
		 (- button-size 2))
    new-choice)
 (:choice (event)
    (let ((x (event-x event)) (y (event-y event))
	  (choicepos choice-list) (i 0))
      (while choicepos
	 (if (< (abs (- x (aref (fourth (car choicepos)) 0)))
		 button-size )
	     (return-from :choice i))
	 (incf i)
	 (pop choicepos))
      nil))
 (:buttonPress (event)
     (setq transient-choice (send self :Choice event)))
 (:buttonRelease (event)
     (let ((choice-at-release (send self :choice event)))
	(if (and choice-at-release 
		 (eq choice-at-release transient-choice))
	    (progn
		 (send self :value transient-choice t)
		 (setq transient-choice nil))
	    (send-super :buttonRelease event) ) ) )
) 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; joystick-item
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod joystick-item
 (:create (name receiver method
	   &rest args
	   &key (stick-size 5) (return nil) (follow-move t)
		(min-x -1.0) (max-x 1.0)
		(min-y -1.0) (max-y 1.0)
	   &allow-other-keys)
  (send-super* :create name receiver method
		;; :background *bg-pixel*
		args)
  (setq center-x (/ width 2) center-y (/ height 2))
  (setq stick-x center-x stick-y center-y)
  (setq stick-return return)
  (setf (joystick-item-min-x self) min-x)
  (setf (joystick-item-min-y self) min-y)
  (setf (joystick-item-max-x self) max-x)
  (setf (joystick-item-max-y self) max-y)
  (setf (joystick-item-stick-size self) stick-size)
  (setf (joystick-item-follow-move self) follow-move)
  (setq value-x (/ (+ min-x max-x) 2.0)
	value-y (/ (+ min-y max-y) 2.0))
  (setq fraction-x (/ (- max-x min-x) (float width))
	fraction-y (/ (- max-y min-y) (float height)))
  (setq stick-grabbed nil)
  (send self :redraw)
  self)
 (:redraw () 
  (send self :draw-circles)
  (send self :draw-stick value-x value-y nil)
  )
 (:draw-circles ()
    (let ((w/8 (/ width 8)) (h/8 (/ height 8) ))
      (send gcon :function :copy)
      (send self :arc 0 0 width height 0 2pi)
      (send self :arc w/8 h/8 (round (* width 0.75)) (round (* height 0.75))
			0 2pi)
      (send self :arc (* 2 w/8) (* 2 h/8)
			(ceiling (* width 0.52)) (ceiling (* height 0.52))
			0 2pi)
      (send self :arc (* 3 w/8) (* 3 h/8)
			(ceiling (* width 0.27)) (ceiling (* height 0.27))
			0 2pi)
      (send self :line 0 (/ height 2) width (/ height 2))
      (send self :line (/ width 2) 0 (/ width 2) height )
      (send self :line 0 height width 0)
      (send self :line 0 0 width height)
      self))
 (:xy (&optional (x value-x) (y value-y))
      (setq stick-x (round (* width (/ (- x min-x) (- max-x min-x))))
	    stick-y (round (- height (* height (/ (- y min-y) (- max-y min-y))))) ))
 (:draw-stick (&optional (x value-x) (y value-y) (erase t))
      #|
      (send gcon :function :xorreverse)
      (when erase
	  (send self :xy)
	  (send self :fill-arc (- stick-x stick-size) (- stick-y stick-size)
			(* stick-size 2) (* stick-size 2) 0 2pi)
	) |#
      (send self :clear)
      (send self :draw-circles)
      (send self :xy x y)
      (send self :fill-arc (- stick-x stick-size) (- stick-y stick-size)
			(* stick-size 2) (* stick-size 2) 0 2pi)
      (setq value-x x value-y y))
 (:value (&optional (newx) (newy) invocation)
    (when (and newx newy)
	(setq newx (max min-x (min max-x newx))
	      newy (max min-y (min max-y newy)))
	(send self :draw-stick newx newy))
    (if invocation (send-super :notify newx newy))
    (list value-x value-y))
)

(defmethod joystick-item
 (:buttonPress (event)
    (let* ((x (event-x event)) (y (event-y event))
	   (dx (- x stick-x)) (dy (- y stick-y)))
	(if %(sqrt(dx * dx + dy * dy) < stick-size) 
	    (setq stick-grabbed t))))
 (:value-from-event (event &optional (invocation follow-move))
    (let* ((x (event-x event)) (y (event-y event))
	   (dx (- x stick-x)) (dy (- stick-y y)) newx newy)
	(setq newx (+ value-x (* dx fraction-x))
	      newy (+ value-y (* dy fraction-y)))
	(send self :value newx newy invocation)))
 (:motionNotify (event)
    (when stick-grabbed (send self :value-from-event event)))
 (:buttonRelease (event)
    (if stick-grabbed
	(progn
	    (setq stick-grabbed nil)
	    (cond (stick-return
		   (send self :value
			%((min-x + max-x) / 2.0) %((min-y + max-y) / 2.0)
			t))
		  ((null follow-move)
		   (send self :value-from-event event t)))
	     )
	(send-super :buttonRelease event)))
) 


;;;;;;;;;;;;;;;;;;;;; Hara Hara

(defmethod bitmap-button-item
  (:create-bitmap-from-file (fname)
     (let ((width (instantiate c-int))
	   (height (instantiate c-int))
	   (bitmap (instantiate c-long))
	   (x_hot (instantiate c-int))
	   (y_hot (instantiate c-int)))
	(unless (probe-file fname)
	    (setq fname (format nil "~A/lib/bitmaps/~A" *eusdir* fname))
	    (if (null (probe-file fname))
		(error "bitmap file ~S not found." fname)))
        (ReadBitmapFile *display* (defaultrootwindow *display*)
                 fname width height bitmap x_hot y_hot)
        (setq bitmap-width (c-int width))
        (setq bitmap-height (c-int height))
        (setq pixmap-id (c-long bitmap))
       )
  )
 (:redraw () (send self :draw-label))
 (:draw-label (&optional (state :flat) (color bg-color) (border 2))
    (send self :3d-fill-rectangle  0 0 width height border
		light-edge-color dark-edge-color bg-color
		topleft-edge-polygon state)
    (CopyPlane *display* pixmap-id drawable (gcontext-gcid gcon)
		0 0 bitmap-width  bitmap-height
		2 2 1)
  )
 (:create (fname reciever method  &rest args
                 &key width height
                 &allow-other-keys)
    (let* (opos xsize ysize)
      (send self :create-bitmap-from-file fname)
      (setq xsize
            (if (null width) (+ bitmap-width 4) width))
      (setq ysize
         (if (null height) (+ bitmap-height 4) height))
      (send-super* :create fname reciever method 
		:width xsize :height ysize args)
      (setf (bitmap-button-item-label self) fname)
      )
    self)
)

(provide :Xitem "@(#)$Id: Xitem.l,v 1.1.1.1 2003/11/20 07:46:35 eus Exp $")


