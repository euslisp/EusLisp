;;;
;;;	Example Program for eusview users	1989.5.27 M.I.
;;;
;;;	ex1 : not use of user frame class
;;;         : example of drawing
;;;	ex2 : define a user frame
;;;	    : example for usage of itimer function
;;;	ex3 : define user panel, user canvas
;;;	    : example for color manipulation
;;;
(defun ex1 (&rest msgs)
  (let ((Ex1 (instantiate sunview-frame)) p1 p2 b1 b2)
    (send-lexpr ex1 :init msgs)
    (setq P1 (instance sunview-panel :init Ex1
;;;		       :font "/usr/lib/fonts/fixedwidthfonts/screen.b.12"
		       ))
    (setq B1 (instance
	      panel-text-item :init P1 :title "Text item:"
	      :nproc
	      '(lambda (value item event)
		 (send *C1* :drawtext value 10 20))))
    (send P1 :fit-height)
    (setq P2 (instance sunview-panel :init Ex1))
    (setq B2 (instance
	      panel-choice-item :init P2 :title "Choice" :choices
	      '(src clr xor set) :nproc
	      '(lambda (value &optional item event)
		 (case value
		       (set (setq *ex1-op* Pix_set))
		       (xor (setq *ex1-op* (logxor pix_src pix_dst)))
		       (src (setq *ex1-op* pix_src))
		       (clr (setq *ex1-op* pix_clr))))))
    (send P2 :fit-height)
    (setq *ex1-op* pix_src)
    (setq *C1* (instance
		sunview-canvas :init Ex1 :x 0
		:width (send ex1 :width) :height (send ex1 :height)
		:clicked-proc
		'(lambda (window movement button pos time) (send *c1* :clear))
		:drag-started-proc
		'(lambda (window movement button pos time)
		 (setq *start* pos))
	      :dragging-proc
	      '(lambda (window movement button pos time)
		 (send *C1* :drawline (vector-x *start*) (vector-y *start*)
		       (vector-x pos) (vector-y pos) :color 1
		       :op *ex1-op*))))
    (send *C1* :fit)
    (send Ex1 :show)
    ex1))
;;;
(defclass ex2
  :super sunview-frame
  :slots (P B C last-pos title period))
(defmethod ex2
  (:moving-speed
   (v &optional item event)
   (setq period (/ v 100000.0))
   (send self :set-itimer-period period))
  (:move-me
   (&optional item event)
   (send self :set-itimer
	 '(lambda (w type)
	    (inc cnt)
	    (let ((x (mod (round (+ (vector-x (w . last-pos)) 10)) 300))
		  (y (vector-y (w . last-pos))))
	      (send w :move-text w nil nil (floatvector x y) nil)))
	 :period period))
  (:stop-me (&optional item event) (send self :stop-itimer))
  (:move-text (window movement button pos time)
	      (send C :drawtext title
		    (vector-x last-pos) (vector-y last-pos) :op pix_clr)
	      (send C :drawtext title
		    (vector-x pos) (vector-y pos) :op pix_src)
	      (setq last-pos pos))
  (:notify-function0 (&optional item event) (format t "item=~S~%" item))
  (:notify-function1 (value &optional item event)
		     (setq title (format nil "Move me(~s)." value)))
  (:click (window movement button pos time)
	  (format t "movement=~s,button=~s,pos=~s,time=~s~%"
		  movement button pos time))
  (:init
   (&rest args)
   (send-super-lexpr :init args)
   (setq P (send self :create-subwindow sunview-panel
;;;		 :font "/usr/lib/fonts/fixedwidthfonts/screen.b.12"
		 ))
;;;   (setq B (send self :create-button :move-me :title "Move me"))
   (setq B (instance panel-button-item :init P
		     :nproc :move-me :title "Move me"))
   (setq B (send self :create-button :stop-me :title "Stop me"))
   (setq B (send self :create-choice :notify-function1
		 :title "Choice item" :choices '(1 2 3)
		 :value 1))
   (setq B (send self :create-cycle :notify-function1
		 :title "Cycle item" :choices '(a b c)))
   (setq B (send self :create-toggle :notify-function1
		 :title "Toggle item" :choices '("=" "+" "-")))
   (setq B (send self :create-slider :notify-function1
		 :title "Slider item" :min 0.2 :max 120.5
		 :value 10 :length 60))
   (setq period 0.00001)
   (setq B (send self :create-slider :moving-speed
		 :title "Speed" :min 1 :max 100000
		 :value 1 :length 60 :notify-level 'all))
   (setq C (send self :create-subwindow sunview-canvas
		 :x 0 :width (send self :width)
		 :height (send self :height) :below P
		 :clicked-proc :click :dragging-proc :move-text
		 :resize-proc :print-size
		 :repaint-proc :print-repaint))
   (setq last-pos #f(50 50))
   (setq title "Move me.")
   (send c :drawtext title 50 50)
   (setq cnt 0)
   (send self :show)
   self)
  (:print-repaint (&optional w p a)
	       (format t "w=~s,p=~s,a=~s~%" w p a))
  (:print-size (&optional c w h)
	       (format t "c=~s,w=~s,h=~s~%" c w h)))
;;;
(defclass ex3-frame
  :super sunview-frame
  :slots
  (panel canvas)
  )
(defmethod ex3-frame
  (:draw-triangle
   (window movement button pos time)
   (let ((op
	  (case
	   button
	   (left (logior pix_src (pix_color 1)))
	   (middle (logior pix_src (pix_color 2)))
	   (right (logior pix_src (pix_color 3))))))
     (send canvas :drawpolygon '(#f(20 10) #f(40 30) #f(20 50))
	   :op op)))
  (:size-show-color-boxes
   (&optional c width height)
   (do ((counter 1 (1+ counter)))
       ((eq counter 4))
       (send canvas :drawimage
	     "" (* counter (/ width 5)) 10 (/ width 10) (/ height 2)
	     :op (logior pix_src (pix_color counter)))
       (send canvas :drawtext
	     (string counter) (+ (* counter (/ width 5)) 10) (/ height 2)
	     :op (logxor pix_src pix_dst)))
   (setq cur-color 0))
  (:show-color-boxes
   (&optional a b c)
   (send self :size-show-color-boxes a
	 (send canvas :width) (send canvas :height)))
  (:init
   (&rest args)
   (send-super-lexpr :init args)
   (setq panel (send self :create-subwindow ex3-panel :vertical nil))
   (setq canvas (send self :create-subwindow ex3-canvas
		      :x 0 :below panel :height 60
		      :width (send panel :width)
		      ))
   (send self :show)
   (setq (panel . canvas) canvas)
   (send canvas :cmsname (format nil "canvas~s" (unix:getpid)))
   (send panel :set-colors 4)
   (send canvas :show-color-boxes)
   self)
  )
(defclass ex3-panel
  :super sunview-panel
  :slots (
	  color-item
	  red-item green-item blue-item
	  cur-color
	  red green blue canvas
	  )
  )
(defmethod ex3-panel
  (:set-color
   (value &optional item event)
   (send red-item :value (elt red value))
   (send green-item :value (elt green value))
   (send blue-item :value (elt blue value))
   (setq cur-color value))
  (:set-colors
   (&optional (size (send canvas :cmssize)))
   (send canvas :put-colormap red green blue 0 size))
  (:set-red (value &optional item event)
	    (setf (aref red cur-color) value)
	    (send self :set-colors))
  (:set-green (value &optional item event)
	      (setf (aref green cur-color) value)
	      (send self :set-colors))
  (:set-blue (value &optional item event)
	     (setf (aref blue cur-color) value)
	     (send self :set-colors))
  (:init
   (&rest args)
   (send-super-lexpr :init args)
   (setq color-item
	 (send self :create-choice :set-color :title "color index:"
	       :choices '(0 1 2 3)))
   (setq red-item
	 (send self :create-slider :set-red :title "red:"
	       :min 0 :max 255 :length 60 :notify-level 'all))
   (setq green-item
	 (send self :create-slider :set-green :title "green:"
	       :min 0 :max 255 :length 60 :notify-level 'all))
   (setq blue-item
	 (send self :create-slider :set-blue :title "blue:"
	       :min 0 :max 255 :length 60 :notify-level 'all))
   (setq red (concatenate string nil '(0 0 255 255)))
   (setq green (concatenate string nil '(0 255 0 192)))
   (setq blue (concatenate string nil '(255 0 0 192)))
   (setq cur-color 0)
   self)
  )
;;;
(defclass ex3-canvas
  :super sunview-canvas
  :slots
  ()
  )
(defmethod ex3-canvas
  (:draw-triangle
   (window movement button pos time)
   (let ((op
	  (case
	   button
	   (left (logior pix_src (pix_color 1)))
	   (middle (logior pix_src (pix_color 2)))
	   (right (logior pix_src (pix_color 3))))))
     (send self :drawpolygon '(#f(20 10) #f(40 30) #f(20 50))
	   :op op)))
  (:size-show-color-boxes
   (&optional c width height)
   (do ((counter 1 (1+ counter)))
       ((eq counter 4))
       (send self :drawimage
	     "" (* counter (/ width 5)) 10 (/ width 10) (/ height 2)
	     :op (logior pix_src (pix_color counter)))
       (send self :drawtext
	     (string counter) (+ (* counter (/ width 5)) 10) (/ height 2)
	     :op (logxor pix_src pix_dst)))
   (setq cur-color 0))
  (:show-color-boxes
   (&optional a b c)
   (send self :size-show-color-boxes a
	 (send self :width) (send self :height)))
  (:init
   (&rest args)
   (send-super-lexpr :init args)
   (send self :clicked-proc :draw-triangle)
   (send self :resize-proc :resize-show-color-boxes)
   (send self :repaint-proc :show-color-boxes)
   self))
(defun ex nil
  (setq *ex1* (ex1 nil :title "Ex1 : example for drawing"
		   :x 200 :y 100 :width 500 :height 300))
  (setq *ex2* (instance ex2 :init nil :title "Ex2 : Example for itimer"
			:y (send *ex1* :y) :right-of *ex1*
			:width 300 :height 300))
  (setq *ex3* (instance ex3-frame :init nil :title "Ex3 : example for color"
			:x (send *ex1* :x) :width (send *ex1* :width)
			:below *ex1*))
;;;  (setq *ex4* (instance ex3-frame :init nil :title "Ex4 : example for color"
;;;			:x (send *ex2* :x) :width (send *ex2* :width)
;;;			:below *ex2*))
  )
(format t "type (ex)~%")
