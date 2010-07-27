;;;
;;;		Graphic example with Sunview I or Xview Toolkit
;;;			1988.8.16	by M.Inaba
;;;			1988.10.29	use new viewport.l
;;;			1989.11.24	use rpy-matrix and
;;;			(coordmenu)
;;;
(defclass coordmenu
  :super sunview-frame
  :slots
  (
   apickport
   coordpanel1 coordpanel2 coordpanel3 coordcanvas
   translate-x translate-y translate-z translate-wrt translate-to
   rotate-x rotate-y rotate-z  rotate-wrt rotate-to
   transformation
   coord wrt base
   coord-pos wrt-pos
   selected-coord
   coord-x-message coord-y-message coord-z-message
   coord-roll coord-pitch coord-yaw
   coord-roll-slider coord-pitch-slider coord-yaw-slider
   left-right-angle up-down-angle axis-length
   wrt-x-message wrt-y-message wrt-z-message
   wrt-roll-slider wrt-pitch-slider wrt-yaw-slider
   wrt-roll wrt-pitch wrt-yaw
   transform-wrt transform-to
   canvas-width
   )
  )
(defmethod coordmenu
  (:>select-coord
   (window movement button pos time)
   (send self :select-coordinates pos)
   (case
    button
    (left (send self :reset-all))
    (middle (send self :reset-all))
    (right (send self :reset-all)))
   (send apickport :viewsurface :flush)
   )
  (:select-coordinates
   (pos)
   (setq selected-coord (pick-coordinates (list coord wrt) pos apickport)))
  (:show-coord-position
   (&optional item event)
   (send coord-x-message
	 :title (format nil " X:~7F WX:~7F"
			(vector-x (send coord :worldpos))
			(vector-x (send coord :worldpos))))
   (send coord-y-message
	 :title (format nil " Y:~7F WY:~7F"
			(vector-y (send coord :worldpos))
			(vector-y (send coord :worldpos))))
   (send coord-z-message
	 :title (format nil " Z:~7F WZ:~7F"
			(vector-z (send coord :worldpos))
			(vector-z (send coord :worldpos))))
   )
  (:show-coord-rotation
   (&optional item event)
   (let ((rpy (roll-pitch-yaw (send coord :worldrot))))
     (send coord-roll-slider :value (rad2deg (elt rpy 0)))
     (send coord-pitch-slider :value (rad2deg (elt rpy 1)))
     (send coord-yaw-slider :value (rad2deg (elt rpy 2)))
     )
   )
  (:show-wrt-rotation
   (&optional item event)
   (let ((rpy (roll-pitch-yaw (send wrt :worldrot))))
     (send wrt-roll-slider :value (rad2deg (elt rpy 0)))
     (send wrt-pitch-slider :value (rad2deg (elt rpy 1)))
     (send wrt-yaw-slider :value (rad2deg (elt rpy 2)))
     )
   )
  (:show-wrt-position
   (&optional item event)
   (send wrt-x-message
	 :title (format nil " X:~7F WX:~7F"
			(vector-x (send wrt :worldpos))
			(vector-x (send wrt :worldpos))))
   (send wrt-y-message
	 :title (format nil " Y:~7F WY:~7F"
			(vector-y (send wrt :worldpos))
			(vector-y (send wrt :worldpos))))
   (send wrt-z-message
	 :title (format nil " Z:~7F WZ:~7F"
			(vector-z (send wrt :worldpos))
			(vector-z (send wrt :worldpos))))
   )
  (:flush-all
   (&optional item event)
   (send apickport :viewsurface :set-show-mode)
   (send self :show-all)
   (send apickport :flush)
   )
  (:draw-box
   (&optional item event)
   (send apickport :draw-box-cursor (send coord :worldpos))
   (send apickport :draw-box-cursor (send wrt :worldpos))
   (send self :show-coord-position)
   (send self :show-wrt-position)
   )
  (:>set-start-point
   (window movement button pos time)
   (let*
       ((p3 (2dvector-to-3dvector pos))
	(p (send apickport :viewport :screen-point-to-ndc p3))
	(vline (send apickport :viewing :view-line p))
	)
     (send self :select-coordinates pos)
     (send self :flush-all)
     ))
  (:>move-coord
   (window movement button pos time)
   (let*
       ((3dpos (send apickport :pick-vector pos
		     (case
		      button
		      (left (float-vector 1 0 0))
		      (middle (float-vector 0 1 0))
		      (right (float-vector 0 0 1)))
		     (send selected-coord :worldpos))))
     (send self :erase-all)
     (if (equal selected-coord coord)
	 (send coord :new-world-coords
	       (send coord :worldrot)
	       (setq coord-pos 3dpos))
       (send wrt :new-world-coords
	     (send wrt :worldrot)
	     (setq wrt-pos 3dpos)))
     (send self :flush-all)
     )
   )
  (:assoc (&optional item event)
	  (send wrt :assoc coord)
	  (send self :flush-all)
	  )
  (:dissoc (&optional item event)
	   (send wrt :dissoc coord)
	   (send self :flush-all)
	   )
  (:obey (&optional item event)
	 (send coord :obey wrt)
	 (send self :flush-all)
	 )
  (:disobey (&optional item event)
	    (send coord :disobey wrt)
	    (send self :flush-all)
	    )
  (:buffer-mode
   (value &optional item event)
   (send apickport :clear)
   (send apickport :viewsurface :buffer-mode value)
   (send self :flush-all)
   )
  (:init-panel1
   (&optional item event)
   (setq left-right-angle 0)
   (setq up-down-angle 0)
   (setq axis-length 30)
   (setq coordpanel1
	 (send self :create-subwindow
	       sunview-panel :vertical nil :col-num 1 :item-size 20))
   (send self :create-button :flush-all :title "show-all")
   (send self :create-button :clear-port :title "clear-port")
   (send self :create-button :reset-all :title "reset-all")
   (send self :create-button :flush :title "refresh")
   (send self :create-choice :buffer-mode :title "buffer mode:" :value t
	 :vertical nil :choices (vector t nil) :display-level 'current)
   (when (equal
	  *coordinates* cascaded-coords)
	 (send self :create-button :assoc   :title "Assoc to wrt")
	 (send self :create-button :dissoc :title "Dissoc from wrt")
	 (send self :create-button :obey :title "Obey to wrt")
	 (send self :create-button :disobey :title "Disobey from wrt")
	 )
   
   (send self :create-slider :axis-length :title "Axis length"
	 :min 5 :max 100 :value axis-length :notify-level 'all :vertical t)
   (send self :create-slider :left-right :title "lookaround-left-right:"
	 :min -180 :max 180 :value 0 :notify-level 'all :vertical t)
   (send self :create-slider :up-down :title "lookaround-up-down:"
	 :min -180 :max 180 :value 0 :notify-level 'all :vertical t)
   (send self :create-message :title "Coordinates:")
   (setq coord-x-message
	 (send self :create-message
	       :title (concatenate
		       string " X :"
		       (string (vector-x (send coord :worldpos))))))
   (setq coord-y-message
	 (send self :create-message
	       :title (concatenate
		       string " Y :"
		       (string (vector-y (send coord :worldpos))))))
   (setq coord-z-message
	 (send self :create-message
	       :title (concatenate
		       string " Z :"
		       (string (vector-z (send coord :worldpos))))))
   (send self :create-message :title "Wrt:")
   (setq wrt-x-message
	 (send self :create-message
	       :title (concatenate
		       string " X :"
		       (string (vector-x (send wrt :worldpos))))))
   (setq wrt-y-message
	 (send self :create-message
	       :title (concatenate
		       string " Y :"
		       (string (vector-y (send wrt :worldpos))))))
   (setq wrt-z-message
	 (send self :create-message
	       :title (concatenate
		       string " Z :"
		       (string (vector-z (send wrt :worldpos))))))
   )
  (:init-panel2
   (&optional item event)
   (setq coordpanel2
	 (send self :create-subwindow sunview-panel
	       :vertical nil :item-size 20))
   (send self :create-message :title "    <<Wrt>>")
   (setq wrt-roll-slider
	 (send self :create-slider :set-wrt-roll
	       :title "r-x:" :min 0 :value wrt-roll
	       :max 360 :notify-level 'all :vertical nil))
   (setq wrt-pitch-slider
	 (send self :create-slider :set-wrt-pitch
	       :title "r-y:" :min 0 :value wrt-pitch
	       :max 360 :notify-level 'all :vertical nil))
   (setq wrt-yaw-slider
	 (send self :create-slider :set-wrt-yaw
	       :title "r-z:" :min 0 :value wrt-yaw
	       :max 360 :notify-level 'all :vertical nil))
;;;
   (send self :create-message :title "    <<Coordinate>>")
   (setq coord-roll-slider
	 (send self :create-slider :set-coord-roll
	       :title "r-x:" :min 0 :value coord-roll
	       :max 360 :notify-level 'all :vertical nil))
   (setq coord-pitch-slider
	 (send self :create-slider :set-coord-pitch
	       :title "r-y:" :min 0 :value coord-pitch
	       :max 360 :notify-level 'all :vertical nil))
   (setq coord-yaw-slider
	 (send self :create-slider :set-coord-yaw
	       :title "r-z:" :min 0 :value coord-yaw
	       :max 360 :notify-level 'all :vertical nil))
   )
  (:init-panel3
   (&optional item event)
   (setq translate-x 0 translate-y 0 translate-z 0
	 translate-wrt 'local translate-to 'local)
   (setq rotate-x 0 rotate-y 0 rotate-z 0
	 rotate-wrt 'local rotate-to 'local)
   (setq coordpanel3
	 (send self :create-subwindow sunview-panel :item-size 20 :y 0))
   (send self :create-message :title "     <<Translation>>")
   (send self :create-button :locate :title "locate")
   (send self :create-button :move-locally :title "move-locally")
   (send self :create-button :translate :title "translate")
   (send self :create-choice :set-translate-wrt
	 :title "Translate-wrt:" :display-level 'current
	 :horizontal t :choices (list 'local 'world 'wrt))
   (send self :create-choice :set-translate-to
	 :title "Translate-to:" :display-level 'current
	 :vertical nil :choices (list 'local 'world 'wrt))
   (send self :create-slider :set-translate-x
	 :title "x:" :min -200 :max 200 :notify-level 'all :vertical nil)
   (send self :create-slider :set-translate-y
	 :title "y:" :min -200 :max 200 :notify-level 'all :vertical nil)
   (send self :create-slider :set-translate-z
	 :title "z:" :min -200 :max 200 :notify-level 'all :vertical nil)
;;;
   (send self :create-message :title "     <<Rotation>>")
   (send self :create-button :orient :title "rotate-in-world")
   (send self :create-button :rotate :title "rotate-locally")
   (send self :create-button :rotate :title "rotate")
   (send self :create-choice :set-rotate-wrt
	 :title "Rotate-wrt:" :display-level 'current
	 :vertical nil :choices (list 'local 'world 'wrt))
   (send self :create-choice :set-rotate-to
	 :title "Rotate-to:" :display-level 'current
	 :vertical nil :choices (list 'local 'world 'wrt))
   (send self :create-slider :set-rotate-x
	 :title "x:" :min -180 :max 180 :notify-level 'all :vertical nil)
   (send self :create-slider :set-rotate-y
	 :title "y:" :min -180 :max 180 :notify-level 'all :vertical nil)
   (send self :create-slider :set-rotate-z
	 :title "z:" :min -180 :max 180 :notify-level 'all :vertical nil)
;;;
   (setq transform-wrt 'local transform-to 'local)
   (send self :create-message :title "     <<Transformation>>")
   (send self :create-button :transform :title "transform")
   (send self :create-button :transform-with-coordinates
	 :title "transform-coord")
   (send self :create-button :transform-to :title "transform-to")
   (send self :create-choice :set-transform-wrt
	 :title "Transform-wrt:" :display-level 'current
	 :vertical nil
	 :choices (list 'local 'world 'parent 'wrt))
   (send self :create-choice :set-transform-to
	 :title "Transform-to:" :display-level 'current
	 :vertical nil
	 :choices (list 'local 'world 'parent 'wrt))
   )
;;;
  (:init-canvas
   (&optional item event)
   ;;;
   (setq canvas-width (send coordpanel2 :width))
   (setq coordcanvas
	 (send self :create-subwindow sunview-canvas
	       :x (send coordpanel2 :x)
	       :height canvas-width :width canvas-width
	       :below coordpanel2
	       :clicked-proc :>select-coord
	       :drag-started-proc :>set-start-point
	       :dragging-proc :>move-coord))
   (send self :show t)
   (setq apickport
	 (instance viewer :init
		   :viewing
		   (instance perspective-viewing :init
			     :screen-x 10 :screen-y 10
			     :viewdistance 40
			     :pos #f(700 500 250)
			     :target #f(0 0 0))
		   :viewsurface
		   (instance canvas-viewsurface :init
			     :canvas coordcanvas
			     :cmap-type :mono
			     :buffer-mode t)
		   :viewport
		   (instance viewport
			     :init
			     :width (/ canvas-width 2)
			     :height (/ canvas-width -2)
			     :xcenter (/ canvas-width 2)
			     :ycenter (/ canvas-width 2))
		   ))
   (send self :flush-all)
   )
  (:init
   (&optional parent &key coords)
   (setq base (instance *coordinates* :init))
   (setq coord-pos (float-vector 100 200 100))
   (setq coord-roll 180 coord-yaw 90 coord-pitch 0)
   (setq coord (instance *coordinates* :init
			 :rpy (list
			       (deg2rad coord-roll)
			       (deg2rad coord-pitch)
			       (deg2rad coord-yaw)
			       )
			 :pos coord-pos))
;;;
   (setq wrt-pos (float-vector 150 -50 50))
   (setq wrt-roll 90 wrt-pitch 0 wrt-yaw 0)
   (setq wrt (instance *coordinates* :init
		       :rpy (list
			     (deg2rad wrt-roll)
			     (deg2rad wrt-pitch)
			     (deg2rad wrt-yaw))
		       :pos wrt-pos))
   (setq selected-coord coord)
   (send-super :init parent :title
	       " << Coordinates View >>" :x 310 :y 20)
   (send self :init-panel1)
   (send self :init-panel2)
   (send self :init-panel3)
   (send self :init-canvas)
   (send coordpanel1 :height
	 (+ 7 (send coordcanvas :height) (send coordpanel2 :height)))
   (send coordpanel3 :height
	 (+ 7 (send coordcanvas :height)
	    (send coordpanel2 :height)))
   self)
  (:clear-port (&optional item event)
	       (send apickport :clear)
	       (send apickport :viewsurface :flush)
	       )
  (:draw-base-mark
   (&optional item event)
   (send apickport :draw-axis base (* 0.5 axis-length)))
  (:draw-wrt-mark
   (&optional item event)
   (send apickport :draw-axis wrt (* 0.6 axis-length)))
  (:draw-coord-mark
   (&optional item event)
   (send apickport :draw-axis coord axis-length)
   )
  (:erase-all (&optional event)
	      (send apickport :viewsurface :set-erase-mode)
	      (send self :draw-base-mark)
	      (send self :draw-wrt-mark)
	      (send self :draw-coord-mark)
	      (send self :draw-box)
	      )
  (:show-all (&optional item event)
	     (send apickport :viewsurface :set-show-mode)
	     (send self :draw-base-mark)
	     (send self :draw-wrt-mark)
	     (send self :draw-coord-mark)
	     (send self :show-coord-position)
	     (send self :show-wrt-position)
	     (send self :draw-box)
;	     (send self :show-coord-rotation)
;	     (send self :show-wrt-rotation)
	     )
  (:reset-coords
   (&optional item event)
   (send wrt :new-world-coords
	 (rpy-matrix
	  (deg2rad wrt-roll) (deg2rad wrt-pitch) (deg2rad wrt-yaw))
	 (copy-object wrt-pos))
   (send coord :new-world-coords
	 (rpy-matrix
	  (deg2rad coord-roll) (deg2rad coord-pitch) (deg2rad coord-yaw))
	 (copy-object coord-pos)))
  (:reset-all
   (&optional item event)
   (send self :erase-all)
   (send self :reset-coords)
   (send self :flush-all)
   )
  (:set-wrt-roll (value &optional item event) (setq wrt-roll value)
		 (send self :reset-all)
		 )
  (:set-wrt-pitch (value &optional item event)
		  (setq wrt-pitch value)
		  (send self :reset-all)
		  )
  (:set-wrt-yaw (value &optional item event) (setq wrt-yaw value)
		(send self :reset-all)
		)
  (:set-coord-roll (value &optional item event)
		   (setq coord-roll value)
		   (send self :reset-all)
		   )
  (:set-coord-pitch (value &optional item event) (setq coord-pitch value)
		    (send self :reset-all)
		    )
  (:set-coord-yaw (value &optional item event) (setq coord-yaw value)
		  (send self :reset-all)
		  )
  (:locate
   (&optional item event)
   (send self :erase-all)
   (send coord :locate
	 (float-vector translate-x translate-y translate-z)
	 translate-wrt)
   (send self :flush-all)
   )
  (:move-locally
   (&optional item event)
   (send self :erase-all)
   (send coord :translate
	 (float-vector translate-x translate-y translate-z)
	 translate-wrt)
   (send self :flush-all)
   )
  (:translate
   (&optional item event)
   (send self :erase-all)
   (send coord :translate
	 translate-to
	 (send coord :transform-vector
	       (float-vector translate-x translate-y translate-z)
	       translate-wrt))
   (send self :flush-all))
  (:orient
   (&optional item event)
   (send self :erase-erase-all)
   (if (not (zerop rotate-x))
       (send coord :orient (deg2rad rotate-x) :x rotate-wrt))
   (if (not (zerop rotate-y))
       (send coord :orient (deg2rad rotate-y) :y rotate-wrt))
   (if (not (zerop rotate-z))
       (send coord :orient (deg2rad rotate-z) :z rotate-wrt))
   (send self :flush-all)
   )
  (:rotate
   (&optional item event)
   (send self :erase-all)
   (if (not (zerop rotate-x))
       (send coord :rotate (deg2rad rotate-x) :x rotate-wrt))
   (if (not (zerop rotate-y))
       (send coord :rotate (deg2rad rotate-y) :y rotate-wrt))
   (if (not (zerop rotate-z))
       (send coord :rotate (deg2rad rotate-z) :z rotate-wrt))
   (send self :flush-all)
   )
  (:set-translate-wrt
   (value &optional item event) (setq translate-wrt value)
   (if (eq value 'wrt) (setq translate-wrt wrt)))
  (:set-translate-to
   (value &optional item event) (setq translate-to value)
   (if (eq value 'wrt) (setq translate-to wrt)))
  (:set-translate-x (value &optional item event) (setq translate-x value))
  (:set-translate-y (value &optional item event) (setq translate-y value))
  (:set-translate-z (value &optional item event) (setq translate-z value))
  (:rotate (&optional item event)
	   (send self :erase-all)
	   (send coord :rotate-with-rotation
		 (rpy-matrix
		  (deg2rad rotate-z)
		  (deg2rad rotate-y)
		  (deg2rad rotate-x))
		 rotate-wrt rotate-to)
	   (send self :flush-all))
  (:set-rotate-wrt
   (value &optional item event) (setq rotate-wrt value)
   (if (eq value 'wrt) (setq rotate-wrt wrt)))
  (:set-rotate-to
   (value &optional item event) (setq rotate-to value)
   (if (eq value 'wrt) (setq rotate-to wrt)))
  (:set-rotate-x (value &optional item event) (setq rotate-x value))
  (:set-rotate-y (value &optional item event) (setq rotate-y value))
  (:set-rotate-z (value &optional item event) (setq rotate-z value))
;;;
  (:transform
   (&optional item event)
   (send self :erase-all)
   (send coord :transform
	 (instance coordinates :init
		   :rpy (list
			 (deg2rad rotate-z)
			 (deg2rad rotate-y)
			 (deg2rad rotate-x))
		   :pos (float-vector
			 translate-x translate-y translate-z))
	 transform-wrt)
   (send self :flush-all))
  (:transform-with-coordinates
   (&optional item event)
   (send self :erase-all)
   (send coord :transform-with-coordinates
	 (instance coordinates :init
		   :rpy (list
			 (deg2rad rotate-z)
			 (deg2rad rotate-y)
			 (deg2rad rotate-x))
		   :pos (float-vector
			 translate-x translate-y translate-z))
	 transform-wrt
	 transform-to)
   (send self :flush-all))
  (:transform-to
   (&optional item event)
   (send self :erase-all)
   (send coord :transform-to
	 (instance coordinates :init
		   :rpy (list
			 (deg2rad rotate-z)
			 (deg2rad rotate-y)
			 (deg2rad rotate-x))
		   :pos (float-vector
			 translate-x translate-y translate-z))
	 transform-to)
   (send self :flush-all))
  (:set-transform-wrt
   (value &optional item event) (setq transform-wrt value)
   (if (eq value 'wrt) (setq transform-wrt wrt)))
  (:set-transform-to
   (value &optional item event) (setq transform-to value)
   (if (eq value 'wrt) (setq transform-to wrt)))
;;;
  (:axis-length (value &optional item event)
		(send self :erase-all)
		(setq axis-length value)
		(send self :flush-all)
		)
  (:left-right
   (value &optional item event)
   (send self :erase-all)
   (send apickport :viewing :lookaround
	 (deg2rad (- left-right-angle value))
	 0)
   (send self :flush-all)
   (setq left-right-angle value)
   )
  (:up-down
   (value &optional item event)
   (send self :erase-all)
   (send apickport :viewing :lookaround 0
	 (deg2rad (- up-down-angle value)))
   (send self :flush-all)
   (setq up-down-angle value)
   )
  )
(defun coordmenu (&optional (type cascaded-coords))
  (if (eq type t)
      (setq *coordinates* coordinates)
    (setq *coordinates* type))
  (setq *coordmenu* (instance coordmenu :init))
  )
(format t "(coordmenu) ;; main of coordview.l~%")

