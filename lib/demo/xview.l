
(defun add-default-keys (args &rest key-defaults)
   (let (key val pos)
     (while key-defaults
	(setq key (pop key-defaults) val (pop key-defaults))
        (unless (find key args)
	   (setq args (cons key (cons val args) )) )
	)
     args))

(defclass xviewer :super sunview-frame
  :slots (textsw panel input canvas
	  bodies
	  canviewer
	  slider-panel
	  angle-slider 
	  current-wrt
	  x-slider y-slider z-slider
	  zoom-slider
	  WRT-choice
	  axis-choice
	  current-axis)
  )

(defmethod xviewer
  (:slide (&rest args) (print args))
  (:list-bodies (&rest args)
     (send textsw :set-contents
	(format nil"~s~%" (send-all bodies :name))))
  (:add-body (&rest args)
     (let (form)
	(setq form (read-from-string (send input :value)))
	(when (and (symbolp form) (boundp form))
	   (setq bodies (adjoin (symbol-value form) bodies))))
     (send self :list-bodies))
  (:xyz-value ()
     (float-vector (send x-slider :value)
		 (send y-slider :value)
		 (send z-slider :value)))
  (:angle-value ()
     (deg2rad (send angle-slider :value)) )
  (:read-input ()
	(read-from-string (send input :value)))
;; model manipulation
  (:translate (&rest args)
      (let ((b (send self :read-input))
	    (xyz (send self :xyz-value)))
	 (when (and (symbolp b) (boundp b)
		    (find-method (symbol-value b) :translate))
	    (send (symbol-value b) :translate xyz current-wrt))
	 (send self :draw-bodies)))
  (:rotate (&rest args)
      (let ((b (send self :read-input))
	    (ang (send self :angle-value)))
	 (when (and (symbolp b) (boundp b)
		    (find-method (symbol-value b) :rotate))
	    (send (symbol-value b) :rotate ang current-axis current-wrt))
	 (send self :draw-bodies)))
  (:change-wrt (value &rest args) (setq current-wrt value))
  (:change-axis (value &rest args) (setq current-axis value))
;; drawing
  (:draw-bodies (&rest args)
     (let ((*viewer* canviewer) )
	  (draw bodies)) )
  (:hid-bodies (&rest args)
     (let ((*viewer* canviewer) )
	  (hid bodies)) )
;; viewing manipulation
  (:zoom (&rest args)
     (send canviewer :viewing :zoom (* 0.01 (send zoom-slider :value)))
     (send self :draw-bodies))
  (:lookaround (&rest args)
     (send canviewer :viewing
	 :lookaround (deg2rad (send angle-slider :value)) 0.0)
     (send self :draw-bodies))
  (:tilt (&rest args)
     (send canviewer :viewing
	 :lookaround 0.0 (deg2rad (send angle-slider :value)) )
     (send self :draw-bodies))
  (:translate-viewing (&rest args)
     (send canviewer :viewing :translate (send self :xyz-value) current-wrt)
     (send self :draw-bodies))
;; picking
 (:pick-object (win button1 button2 pos &rest args)
     (let* ((ndc-pos (send canviewer :viewport :screen-point-to-ndc
				(float-vector (aref pos 0) (aref pos 1) 0)))
	    (direction (send canviewer :viewing
				:ray (aref ndc-pos 0) (aref ndc-pos 1)))
	    picked-bodies)
	(dolist (b bodies)
	  (setq ints 
		(send b :faces-intersect-with-point-vector
		        (send canviewer :viewing :viewpoint)
			direction))
	  (if ints (push b picked-bodies)))
	(send input :value (format nil "~s" (send-all picked-bodies :name)))
))
;;
  (:window-title   ()
	(send self :name))
  (:clear-canvas (&rest args) (send canvas :clear))
;; create and initialize the window
  (:init  (&optional (par nil) &rest args)
   (send-super-lexpr :init par 
	(add-default-keys args :title "VIEW" :width 800 :height 1
			 :scrollbar nil))
   ;; panel
   (setq panel (send self :create-subwindow sunview-panel))
   (setq panel (instance sunview-panel :init self
			 :col-max 3 :row-max 2
			 :width 800  :height 120
			 :scrollbar nil
			 :item-size 20
			 :font "lucidasans-bold-12"))
   (send panel :create-button :zoom :title "Zoom" )
   (send panel :create-button :clear-canvas :title "Clear")
   (send panel :create-button :draw-bodies :title "Draw")
   (send panel :create-button :hid-bodies :title "Hid")
   (send panel :create-button :lookaround :title "LookAround")
   (send panel :create-button :tilt :title "tilt")
   (send panel :create-button :translate-viewing :title "MoveView")
   (send panel :create-button :translate :title "Translate")
   (send panel :create-button :rotate :title "Rotate")
   (send panel :create-button :add-body :title "AddBody")
   ;;
   (send panel :create-choice :change-wrt :title "WRT"
		:choices #(:Local :World))
   (send panel :create-choice :change-axis :title "Axis"
		:choices #(:X :Y :Z))
   (setq current-wrt :local
	 current-axis :x)
   ;;
   (setq slider-panel (instance sunview-panel :init self
			 :col-max 0 :row-max 5
			 :width 320	
			  :height 350
			 :scrollbar nil
			 :item-size 40
			 :font "lucidasans-bold-12"
   			 :below panel))
   (setq input (send slider-panel :create-text :add-body
		    :title "Form:" :value "x"  :width 400))
   (setq zoom-slider
	 (send slider-panel :create-slider :slide :title "Zoom"
			:min 0 :max 200))
   (setq angle-slider
	 (send slider-panel :create-slider :slide :title "Ang"
			:min -180 :max 180))
   (setq X-slider
	 (send slider-panel :create-slider :slide :title "X"
			:min -100 :max 100))
   (setq Y-slider
	 (send slider-panel :create-slider :slide :title "Y"
			:min -100 :max 100))
   (setq Z-slider
	 (send slider-panel :create-slider :slide :title "Z"
			:min -100 :max 100))
   ;; text
   (setq textsw (instance sunview-textsw :init self
			  :width 300 :height 120
			  :below slider-panel
			  :x 0
			  ))
   ;; canvas
   (setq canvas (instance sunview-canvas :init self
			:width 500 :height 500
			:below panel
			  :right-of slider-panel
			:clicked-proc :pick-object
			:moving-proc :pick-object
			))
   (setq canviewer
	 (instance viewer :init
		:viewsurface (instance canvas-viewsurface :init
				 :width 500 :height 500 :canvas canvas	 ) 
		:viewport (instance viewport :init :width 500 :height -500
				:xcenter 250 :ycenter 250)
		:viewing (instance perspective-viewing :init
				:pos #f(1000 1000 1000)
				:target #f(0 0 0)) ) )
   (send panel :fit-height) 
;   (send slider-panel :fit-height) 
   (send self :show t)
   self)
  )

(defun win () (setq a (instance xviewer :init)))
