;;;
;;;		Graphic example with Sunviewclass.l
;;;			1988.8.16	by M.Inaba
;;;			1988.10.29	use new viewport.l
;;;			(coordmenu)
;;;
(eval-when (compile)
	   (load "/usr/local/eus/llib/geoclasses.l")
	   (load "/usr/local/eus/sunlib/sunviewclasses.l")
	   )
;;;
;;;
;(load "../../llib/pickport.l")
;(load "/usr/local/eus/sunlib/sunviewclass.l")
;;;
(defun make-rotation-with-rpy (x y z)
  (m*
   (m*
    (rotation-matrix x :x)
    (rotation-matrix y :y))
   (rotation-matrix z :z))
  )
(defclass coordmenu
  :super sunview-frame
  :slots
  (
   aviewsurface
   apickport
   aviewport
   aviewing
   coordpanel1 coordpanel2 coordpanel3 coordcanvas
   translate-x translate-y translate-z
   translate-wrt translate-to
   rotate-x rotate-y rotate-z
   rotate-wrt rotate-to
   transform-x transform-y transform-z
   transform-r-x transform-r-y transform-r-z
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
   transform-wrt canvas-width
   )
  )
(defmethod coordmenu
  (:select-coord
   (movement button pos time)
   (send self :select-coordinates pos)
   (case
    button
    (left (send self :reset-all))
    (middle (send self :reset-all))
    (right (send self :reset-all)))
   ;; (send aviewsurface :refresh) change by Y.K. 9/27/89
   (send aviewsurface :clear)
   )
  (:select-coordinates
   (pos)
   (setq selected-coord (pick-coordinates (list coord wrt) pos apickport)))
  (:show-coord-position
   (&optional item event)
   (send coord-x-message
	 :title (format nil " X:~7F WX:~7F"
			(vector-x (coord . pos))
			(vector-x (send coord :worldpos))))
   (send coord-y-message
	 :title (format nil " Y:~7F WY:~7F"
			(vector-y (coord . pos))
			(vector-y (send coord :worldpos))))
   (send coord-z-message
	 :title (format nil " Z:~7F WZ:~7F"
			(vector-z (coord . pos))
			(vector-z (send coord :worldpos))))
   )
  (:show-coord-rotation
   (&optional item event)
   (let ((rpy (roll-pitch-yaw (coord . rot))))
     (send coord-roll-slider :value (rad2deg (elt rpy 0)))
     (send coord-pitch-slider :value (rad2deg (elt rpy 1)))
     (send coord-yaw-slider :value (rad2deg (elt rpy 2)))
     )
   )
  (:show-wrt-rotation
   (&optional item event)
   (let ((rpy (roll-pitch-yaw (wrt . rot))))
     (send wrt-roll-slider :value (rad2deg (elt rpy 0)))
     (send wrt-pitch-slider :value (rad2deg (elt rpy 1)))
     (send wrt-yaw-slider :value (rad2deg (elt rpy 2)))
     )
   )
  (:show-wrt-position
   (&optional item event)
   (send wrt-x-message
	 :title (format nil " X:~7F WX:~7F"
			(vector-x (wrt . pos))
			(vector-x (send wrt :worldpos))))
   (send wrt-y-message
	 :title (format nil " Y:~7F WY:~7F"
			(vector-y (wrt . pos))
			(vector-y (send wrt :worldpos))))
   (send wrt-z-message
	 :title (format nil " Z:~7F WZ:~7F"
			(vector-z (wrt . pos))
			(vector-z (send wrt :worldpos))))
   )
  (:refresh-all
   (&optional item event)
   (send apickport :clear)
   ;; change by Y.K. 9/27/89
   ;; (send apickport :viewsurface :set-show-mode)
   (send self :show-all)
   ;; (send apickport :refresh)
   )
  (:draw-box
   (&optional item event)
   (send apickport :draw-box-cursor (coord . pos))
   (send apickport :draw-box-cursor (wrt . pos))
   (send self :show-coord-position)
   (send self :show-wrt-position)
   )
  (:set-start-point
   (movement button pos time)
   (let*
       ((p3 (2dvector-to-3dvector pos))
	(p (send apickport :viewport :screen-point-to-ndc p3))
	(vline (send apickport :viewing :view-line p))
	)
     (send self :select-coordinates pos)
     (send self :refresh-all)
     ))
  (:move-coord
   (movement button pos time)
   (let*
       ((3dpos (send apickport :pick-vector pos
		     (case
		      button
		      (left (floatvector 1 0 0))
		      (middle (floatvector 0 1 0))
		      (right (floatvector 0 0 1)))
		     (send selected-coord :worldpos))))
     (send self :erase-all)
     (if (equal selected-coord coord)
	 (setq coord-pos 3dpos) (setq wrt-pos 3dpos))
     (send self :set-wrt)
     (send self :set-coord)
     (send self :refresh-all)
     )
   )
  (:assoc (&optional item event)
	  (send wrt :assoc coord)
	  (send self :refresh-all)
	  )
  (:dissoc (&optional item event)
	   (send wrt :dissoc coord)
	   (send self :refresh-all)
	   )
  (:obey (&optional item event)
	 (send coord :obey wrt)
	 (send self :refresh-all)
	 )
  (:disobey (&optional item event)
	    (send coord :disobey wrt)
	    (send self :refresh-all)
	    )
  (:buffer-mode
   (value &optional item event)
   (send apickport :clear)
   ;; (send apickport :buffer-mode value) change by Y.K. 9/27/89
   (send self :refresh-all)
   )
  (:init-panel1
   (&optional item event)
   (setq left-right-angle 0)
   (setq up-down-angle 0)
   (setq axis-length 30)
   (setq coordpanel1
	 (send self :create-subwindow sunview-panel :vertical nil :col-num 1 :item-size 20))
   (send self :create-button :refresh-all :title "show-all")
   (send self :create-button :clear-port :title "clear-port")
   (send self :create-button :reset-all :title "reset-all")
   (send self :create-button :refresh :title "refresh")
   (send self :create-choice :buffer-mode
	 :title "buffer mode:" :value 0
	 :vertical nil
	 :choices (vector t nil)
	 :display_level panel_current)
   (when (equal
	  *coordinates* cascaded-coords)
	 (send self :create-button :assoc   :title "Assoc to wrt")
	 (send self :create-button :dissoc :title "Dissoc from wrt")
	 (send self :create-button :obey :title "Obey to wrt")
	 (send self :create-button :disobey :title "Disobey from wrt")
	 )
   
   (send self :create-slider :axis-length :title "Axis length"
	 :min_value 5 :max_value 100 :value axis-length
	 :notify_level panel_all :vertical t)
   (send self :create-slider :left-right :title "lookaround-left-right:"
	 :min_value -180 :max_value 180 :value 0
	 :notify_level panel_all :vertical t)
   (send self :create-slider :up-down :title "lookaround-up-down:"
	 :min_value -180 :max_value 180 :value 0
	 :notify_level panel_all :vertical t)
   (send self :create-message :title "Coordinates:")
   (setq coord-x-message
	 (send self :create-message
	       :title (concatenate
		       string " X :"
		       (string (vector-x (coord . pos))))))
   (setq coord-y-message
	 (send self :create-message
	       :title (concatenate
		       string " Y :"
		       (string (vector-y (coord . pos))))))
   (setq coord-z-message
	 (send self :create-message
	       :title (concatenate
		       string " Z :"
		       (string (vector-z (coord . pos))))))
   (send self :create-message :title "Wrt:")
   (setq wrt-x-message
	 (send self :create-message
	       :title (concatenate
		       string " X :"
		       (string (vector-x (wrt . pos))))))
   (setq wrt-y-message
	 (send self :create-message
	       :title (concatenate
		       string " Y :"
		       (string (vector-y (wrt . pos))))))
   (setq wrt-z-message
	 (send self :create-message
	       :title (concatenate
		       string " Z :"
		       (string (vector-z (wrt . pos))))))
   )
  (:init-panel2
   (&optional item event)
   (setq coordpanel2
	 (send self :create-subwindow sunview-panel :vertical nil :item-size 20))
   (send self :create-message :title "    <<Wrt>>")
   (setq wrt-roll-slider
	 (send self :create-slider :set-wrt-roll
	       :title "r-x:" :min_value 0 :value wrt-roll
	       :max_value 360
	       :notify_level panel_all :vertical nil))
   (setq wrt-pitch-slider
	 (send self :create-slider :set-wrt-pitch
	       :title "r-y:" :min_value 0 :value wrt-pitch
	       :max_value 360
	       :notify_level panel_all :vertical nil))
   (setq wrt-yaw-slider
	 (send self :create-slider :set-wrt-yaw
	       :title "r-z:" :min_value 0 :value wrt-yaw
	       :max_value 360
	       :notify_level panel_all :vertical nil))
;;;
   (send self :create-message :title "    <<Coordinate>>")
   (setq coord-roll-slider
	 (send self :create-slider :set-coord-roll
	       :title "r-x:" :min_value 0 :value coord-roll
	       :max_value 360
	       :notify_level panel_all :vertical nil))
   (setq coord-pitch-slider
	 (send self :create-slider :set-coord-pitch
	       :title "r-y:" :min_value 0 :value coord-pitch
	       :max_value 360
	       :notify_level panel_all :vertical nil))
   (setq coord-yaw-slider
	 (send self :create-slider :set-coord-yaw
	       :title "r-z:" :min_value 0 :value coord-yaw
	       :max_value 360
	       :notify_level panel_all :vertical nil))
   (send self :create-message :title " ")
   (send self :create-message :title "<<Button usage on canvas>>")
   (send self :create-message :title "<<Left button  : on yz-plane>>")
   (send self :create-message :title "<<Middle button: on zx-plane>>")
   (send self :create-message :title "<<Right button : on xy-plane>>")
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
   (send self :create-button :translate :title "translate")
   (send self :create-button :move-in-world :title "move-in-world")
   (send self :create-button :move-locally :title "move-locally")
   (send self :create-choice :set-translate-wrt
	 :title "Translate-wrt:"
	 :display_level panel_current
	 :horizontal t
	 :choices (list 'local 'world 'wrt))
   (send self :create-choice :set-translate-to
	 :title "Translate-to:" :display_level panel_current
	 :vertical nil
	 :choices (list 'local 'world 'wrt))
   (send self :create-slider :set-translate-x
	 :title "x:" :min_value -200 :max_value 200
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-translate-y
	 :title "y:" :min_value -200 :max_value 200
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-translate-z
	 :title "z:" :min_value -200 :max_value 200
	 :notify_level panel_all :vertical nil)
;;;
   (send self :create-message :title "     <<Rotation>>")
   (send self :create-button :rotate-in-world :title "rotate-in-world")
   (send self :create-button :rotate-locally :title "rotate-locally")
   (send self :create-button :rotate :title "rotate")
   (send self :create-choice :set-rotate-wrt
	 :title "Rotate-wrt:" :display_level panel_current
	 :vertical nil
	 :choices (list 'local 'world 'wrt))
   (send self :create-choice :set-rotate-to
	 :title "Rotate-to:" :display_level panel_current
	 :vertical nil
	 :choices (list 'local 'world 'wrt))
   (send self :create-slider :set-rotate-x
	 :title "x:" :min_value -180 :max_value 180
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-rotate-y
	 :title "y:" :min_value -180 :max_value 180
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-rotate-z
	 :title "z:" :min_value -180 :max_value 180
	 :notify_level panel_all :vertical nil)
;;;
   (setq transform-x 0 transform-y 0 transform-z 0
	 transform-r-x 0 transform-r-y 0 transform-r-z 0
	 transform-wrt 'local)
   (send self :create-message :title "     <<Transformation>>")
   (send self :create-button :transform :title "transform")
   (send self :create-choice :set-transform-wrt
	 :title "Transform-wrt:" :display_level panel_current
	 :vertical nil
	 :choices (list 'local 'world 'parent 'wrt))
   (send self :create-slider :set-transform-x
	 :title "v-x:" :min_value -200 :max_value 200
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-transform-y
	 :title "v-y:" :min_value -200 :max_value 200
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-transform-z
	 :title "v-z:" :min_value -200 :max_value 200
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-transform-r-x
	 :title "r-x:" :min_value -180 :max_value 180
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-transform-r-y
	 :title "r-y:" :min_value -180 :max_value 180
	 :notify_level panel_all :vertical nil)
   (send self :create-slider :set-transform-r-z
	 :title "r-z:" :min_value -180 :max_value 180
	 :notify_level panel_all :vertical nil)
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
	       :clicked-proc :select-coord
	       :drag-started-proc :set-start-point
	       :dragging-proc :move-coord))
   (send self :show t)
   (setq aviewsurface
	 (instance canvas-viewsurface :init
		   :canvas coordcanvas
		   :cmap-type :mono
		   :buffer-mode nil)) ;;change by Y.K. 9/27/89
   (setq aviewing (instance perspective-viewing :init
			    :screen-x 10
			    :screen-y 10
			    :viewdistance 40
			    :pos #f(700 500 250)
			    :target #f(0 0 0)
			    ))
   (setq aviewport (instance viewport
			     :init
			     :width (/ canvas-width 2)
			     :height (/ canvas-width -2)
			     :xcenter (/ canvas-width 2)
			     :ycenter (/ canvas-width 2)))
   (setq apickport (instance viewer :init
			     :viewing aviewing
			     :viewsurface aviewsurface
			     :viewport aviewport))
   (send self :refresh-all)
   )
  (:init
   (&optional parent
	      &key
	      coords)
;;;
   (setq base (instance *coordinates* :init :rot (unit-matrix 3)
			:pos (float-vector 0 0 0)))
  (setq coord-pos (floatvector 100 200 100))
  (setq coord-roll 0 coord-yaw 180 coord-pitch 90)
  (setq coord (instance *coordinates* :init
			:rot 
			(make-rotation-with-rpy
			 (deg2rad coord-roll)
			 (deg2rad coord-pitch)
			 (deg2rad coord-yaw)
			 )
			:pos
			coord-pos))
;;;
   (setq wrt-pos (floatvector 150 -50 50))
   (setq wrt-roll 0 wrt-yaw 90 wrt-pitch 0)
   (setq wrt (instance *coordinates* :init
		       :rot
		       (make-rotation-with-rpy
			(deg2rad wrt-roll)
			(deg2rad wrt-pitch)
			(deg2rad wrt-yaw)
			)
		       :pos
		       wrt-pos))
;;;
   (setq selected-coord coord)
;;;
   (send-super :init parent :title
	       (format nil "~a ~a ~a"
		       " << Coordinates View by M.Inaba >>"
		       "Information System Engineering Laboratory"
		       "of UTOKYO (C) 1988"
		       :x 310 :y 20))
   (send self :init-panel1)
   (send self :init-panel2)
   (send self :init-panel3)
   (send self :init-canvas)
   (send coordpanel1 :height
	 (+ 7 (send coordcanvas :height)
	    (send coordpanel2 :height)))
   (send coordpanel3 :height
	 (+ 7 (send coordcanvas :height)
	    (send coordpanel2 :height)))
   self)
  (:clear-port (&optional item event)
	       (send aviewsurface :clear)
	       (send apickport :clear)
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
  (:set-wrt
   (&optional item event)
   (send wrt :newcoords
	 (make-rotation-with-rpy
	  (deg2rad wrt-roll)
	  (deg2rad wrt-pitch) (deg2rad wrt-yaw))
	 (copy-object wrt-pos)))
  (:set-coord
   (&optional item event)
   (send coord :newcoords
	 (make-rotation-with-rpy
	  (deg2rad coord-roll)
	  (deg2rad coord-pitch)
	  (deg2rad coord-yaw))
	 (copy-object coord-pos)))
  (:reset-all
   (&optional item event)
   (send self :erase-all)
   (send self :set-coord)
   (send self :set-wrt)
   (send self :refresh-all)
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
  (:move-in-world
   (&optional item event)
   (send self :erase-all)
   (send coord :move-in-world
	 (floatvector translate-x translate-y translate-z)
	 translate-wrt)
   (send self :refresh-all)
   )
  (:move-locally
   (&optional item event)
   (send self :erase-all)
   (send coord :move-locally
	 (floatvector translate-x translate-y translate-z)
	 translate-wrt)
   (send self :refresh-all)
   )
  (:translate
   (&optional item event)
   (send self :erase-all)
   (send coord :move-with-vector ;;; this means old :translate
	 (floatvector translate-x translate-y translate-z)
	 translate-wrt translate-to)
   (send self :refresh-all)
   )
  (:rotate-in-world
   (&optional item event)
   (send self :erase-all)
   (if (not (zerop rotate-x))
       (send coord :rotate-in-world (deg2rad rotate-x) :x rotate-wrt))
   (if (not (zerop rotate-y))
       (send coord :rotate-in-world (deg2rad rotate-y) :y rotate-wrt))
   (if (not (zerop rotate-z))
       (send coord :rotate-in-world (deg2rad rotate-z) :z rotate-wrt))
   (send self :refresh-all)
   )
  (:rotate-locally
   (&optional item event)
   (send self :erase-all)
   (if (not (zerop rotate-x))
       (send coord :rotate-locally (deg2rad rotate-x) :x rotate-wrt))
   (if (not (zerop rotate-y))
       (send coord :rotate-locally (deg2rad rotate-y) :y rotate-wrt))
   (if (not (zerop rotate-z))
       (send coord :rotate-locally (deg2rad rotate-z) :z rotate-wrt))
   (send self :refresh-all)
   )
;;;
  (:set-translate-wrt
   (value &optional item event) (setq translate-wrt value)
   (if (eq value 'wrt) (setq translate-wrt wrt)))
  (:set-translate-to
   (value &optional item event) (setq translate-to value)
   (if (eq value 'wrt) (setq translate-to wrt)))
  (:set-translate-x (value &optional item event) (setq translate-x value))
  (:set-translate-y (value &optional item event) (setq translate-y value))
  (:set-translate-z (value &optional item event) (setq translate-z value))
;;;
  (:rotate (&optional item event)
	   (send self :erase-all)
	   (send coord :rotate-with-rotation
		 (make-rotation-with-rpy
		  (deg2rad rotate-x)
		  (deg2rad rotate-y)
		  (deg2rad rotate-z))
		 rotate-wrt rotate-to)
	   (send self :refresh-all))
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
		   :rot
		   (make-rotation-with-rpy
		    (deg2rad transform-r-x)
		    (deg2rad transform-r-y)
		    (deg2rad transform-r-z))
		   :pos
		   (floatvector
		    transform-x transform-y transform-z))
	 transform-wrt)
   (send self :refresh-all))
  (:set-transform-wrt
   (value &optional item event) (setq transform-wrt value)
   (if (eq value 'wrt) (setq transform-wrt wrt)))
  (:set-transform-x (value &optional item event) (setq transform-x value))
  (:set-transform-y (value &optional item event) (setq transform-y value))
  (:set-transform-z (value &optional item event) (setq transform-z value))
  (:set-transform-r-x (value &optional item event) (setq transform-r-x value))
  (:set-transform-r-y (value &optional item event) (setq transform-r-y value))
  (:set-transform-r-z (value &optional item event) (setq transform-r-z value))
;;;
  (:axis-length (value &optional item event)
		(send self :erase-all)
		(setq axis-length value)
		(send self :refresh-all)
		)
  (:left-right
   (value &optional item event)
   (send self :erase-all)
   (send apickport :viewing :lookaround
	 (deg2rad (- left-right-angle value))
	 0)
   (send self :refresh-all)
   (setq left-right-angle value)
   )
  (:up-down
   (value &optional item event)
   (send self :erase-all)
   (send apickport :viewing :lookaround 0
	 (deg2rad (- up-down-angle value)))
   (send self :refresh-all)
   (setq up-down-angle value)
   )
  )
(defun coordmenu (&optional (type cascaded-coords))
  (if (eq type t)
      (setq *coordinates* coordinates)
    (setq *coordinates* type))
;;;
  (setq *coordmenu* (instance coordmenu :init))
  )
(defun coordmenu (&optional (type cascaded-coords))
  (if (eq type t)
      (setq *coordinates* coordinates)
    (setq *coordinates* type))
  (setq *coordmenu* (instance coordmenu :init))
  )
(format t "(coordmenu) ;; main of coordview.l~%")
