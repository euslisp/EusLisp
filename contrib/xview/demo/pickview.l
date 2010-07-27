;;;
;;;		Model interface program
;;;			1988.8.13	by M.Inaba
;;;			1988.10.29 using new viewport.l
;;;			(pickmenu)
;;;
;;;
(defclass pickmenu
  :super sunview-frame
  :slots
  (
   picked-object
   pick-command
   pickpanel pickcanvas
;   apickport
   drag-start-pos
   left-right-angle up-down-angle
   pick-mark
   )
  )

(defmethod pickmenu
  (:objects (&optional (v objects))
	    (send apickport :objects v))
  (:make-cube (&rest args)
	      (push (apply #'make-cube args) objects))
  (:make-cylinder (&rest args)
		  (push (apply #'make-cylinder args) objects))
  (:pickport (&rest msg)
	(if msg
	    (apply #'send (cons apickport msg))
	    apickport))
  (:draw-picked-object-axis
   (&optional (size 10))
   (send apickport :draw-mark picked-object size)
   )
  (:pick-object
   (window click button pos time)
   (case
    button
    (left
     (send apickport :viewsurface :set-erase-mode)
     (send self :draw-picked-object-axis)
     (setq picked-object
	   (case
	    pick-command
	    (object (send apickport :pick-object pos))
	    (face (send apickport :pick-face pos))
	    (edge (send apickport :pick-edge pos))
	    (2dlnseg (send apickport :pick-2dlnseg pos))
	    (vertex (send apickport :pick-vertex pos))
	    (junction (send apickport :pick-junction pos))
	    (edge-image (send apickport :pick-edge-image pos)))
	   )
     (send apickport :viewsurface :set-show-mode)
     (send self :draw-picked-object-axis)
     )
    (middle
     (let ((o))
       (case pick-command
	     (2dlnseg (setq o (send apickport :pick-line pos)))
	     )
       (send apickport :clear)
       (send (send apickport :viewsurface) :draw-one o)))
    (right (send apickport :clear)
	   )
    )
   (send apickport :flush)
   )
  (:zooming
   (window click button pos time)
   (case button
	 (left (send apickport :erase-hid-objects)
	       (send apickport :viewing :zoom 0.8)
	       (send apickport :hid-objects)
	       )
	 (right (send apickport :erase-hid-objects)
		(send apickport :viewing :zoom 1.2)
		(send apickport :hid-objects)
		)
	 (middle (send apickport :hid-objects)
		 )
	 )
   (send apickport :flush)
   )
  (:drag-object
   (window click button pos time)
   (let*
       ((obj (send apickport :pick-coordinates pos)))
     (when
      obj
      (send apickport :draw obj)
      (send apickport :draw-box-cursor (send obj :worldpos))
      (send obj :locate
	    (send apickport :pick-vector pos
		  (case
		   button
		   (left (float-vector 1 0 0))
		   (middle (float-vector 0 1 0))
		   (right (float-vector 0 0 1)))
		  (send obj :worldpos))
	    'world)    ;;;;;<< tra 'world 'world ;;;mer
      (send apickport :draw obj)
;;;      (send apickport :draw-box-cursor (send obj :worldpos))
      (send apickport :flush)
      ))
   )
  (:select-drag-object
   (window click button pos time)
   (send apickport :viewsurface :rasterop (logxor pix_src pix_dst))
   (send apickport :draw-box-cursor
	 (send (send apickport :pick-coordinates pos) :worldpos))
   )
  (:release-drag-object
   (window click button pos time)
   (send apickport :draw-box-cursor
	 (send (send apickport :pick-coordinates pos) :worldpos))
   (send apickport :viewsurface :rasterop pix_src))
  (:drag-viewport
   (window click button pos time)
   (let
       ((p (v- pos drag-start-pos)))
     (send apickport :erase-hid-objects)
     (send apickport :viewport :translate (2dvector-to-3dvector p) 'world)
     (setq drag-start-pos pos)
     (send apickport :draw (model-pickport-edge-images apickport))
     (send apickport :flush)
     ))
  (:drag-start
   (window click button pos time)
   (send apickport :erase-hid-objects)
   (setq drag-start-pos pos)
   (send apickport :draw (model-pickport-edge-images apickport))
   (send apickport :flush)
   )
  (:file-name (value i e) (print value))
  (:init
   (&optional parent
	      &key
	      objects
	      (width 400)
	      (height 400)
	      &allow-other-keys)
   (send-super :init parent
	       :title "Pick View by M.Inaba of UTOKYO 1988"
	       :x 400 :y 0)
   (setq pickpanel (send self :create-subwindow sunview-panel :vertical t
			 :col-num 1 :item-size 20))
   (send self :create-choice :change-event-proc
	 :title "Event proc:"
	 :display-level 'current
	 :choices '(Default zooming drag-object))
   (send self :create-item panel-button-item
	 :nproc :superimpose :title "Superimpose")
   (send self :create-button :hid-objects :title "hid-objects")
   (send self :create-item panel-button-item
	 :nproc :draw-objects :title "draw-objects")
   (send self :create-item panel-button-item
	 :nproc :clear-port :title "clear-port")
   (send self :create-item panel-text-item
	 :nproc :file-name :title "Text item"
	 :value "text" :length 20)
   (send self :create-item panel-slider-item
	 :nproc :left-right :title "lookaround-left-right:"
	 :min -180 :max 180 :value 0
	 :notify-level 'all
	 :item-col 0)
   (send self :create-item panel-slider-item
	 :nproc :up-down :title "lookaround-up-down:"
	 :min -180 :max 180 :value 0
	 :notify-level 'all
	 :item-col 0)
   (send self :create-item panel-choice-item
	 :nproc :buffer-mode :title "buffer mode:" :value nil
	 :choices (vector t nil) :display-level 'current
	 :item-col 0)
   (send self :create-item panel-choice-item
	 :nproc :pick-object-type :title "Pick model:" :value 'object
	 :choices
	 (vector 'object 'face 'edge '2dlnseg 'vertex 'junction 'edge-image)
	 :display-level 'all :item-col 0)
   (setq left-right-angle 0)
   (setq up-down-angle 0)
   (setq pick-command 'pick-object)
;;;
   (setq pickcanvas (send self :create-subwindow sunview-canvas
			  :right-of pickpanel
			  :height height :width width
			  :clicked-proc :pick-object
			  :dragging-proc :drag-viewport
			  :drag-started-proc :drag-start))
;;;
   (setq apickport
	 (instance
	  model-pickport
	  :init
	  :viewsurface
	  (instance canvas-viewsurface :init
		    :canvas pickcanvas :buffer-mode nil :cmap-type :mono)
	  :viewing
	  (instance perspective-viewing :init
		    :screen-x 10 :screen-y 10  :viewdistance 40
		    :pos #f(500 300 150) :target #f(0 0 0))
	  :viewport
	  (instance viewport
		    :init :width 200 :height -200
		    :xcenter 200 :ycenter 200)
	  ))
   (setq pick-mark (float-vector 0 0 0))
   (send self :pickport :objects objects)
   (send self :hid-objects)
   (send self :show t)
   self)   
  (:change-event-proc
   (value &optional item event)
   (case value
	 (default (send pickcanvas :clicked-proc :pick-object))
	 (zooming (send pickcanvas :clicked-proc :zooming))
	 (drag-object
	  (send pickcanvas :drag-started-proc :select-drag-object)
	  (send pickcanvas :dragging-proc :drag-object)
	  (send pickcanvas :drag-finished-proc :release-drag-object)
	  )
	 ))
  (:superimpose
   (&optional item event)
   (send apickport :hid-objects)
   (send apickport :flush)
   )
  (:hid-objects (&optional item event) (send apickport :hid-objects)
		(send apickport :flush))
  (:draw-objects (&optional item event) (send apickport :draw-objects)
		 (send apickport :flush))
  (:clear-port (&optional item event) (send apickport :clear)
	       (send apickport :flush))
  (:left-right
   (value &optional item event)
   (send apickport :erase-hid-objects)
   (send apickport :viewing
	 :lookaround (deg2rad (- left-right-angle value)) 0)
   (send apickport :hid-objects)
   (setq left-right-angle value)
   (send apickport :flush)
   )
  (:up-down
   (value &optional item event)
   (send apickport :erase-hid-objects)
   (send apickport :viewing
	 :lookaround 0 (deg2rad (- up-down-angle value)))
   (send apickport :hid-objects)
   (setq up-down-angle value)
   (send apickport :flush)
   )
  (:pick-object-type
   (value &optional item event)
   (setq pick-command value)
   (send apickport :clear)
   (send apickport :hid-objects)
   (send apickport :flush)
   )
  (:buffer-mode
   (value &optional item event)
   (send apickport :viewsurface :buffer-mode value)
   (send apickport :viewsurface :clear))
  )
(defun pickmenu nil
  (setq cube
	(make-prism
	 (list
	  (float-vector 0 0 0)
	  (float-vector 0 51 0)
	  (float-vector 51 51 0)
	  (float-vector 51 0 0))
	 51))
  (setq wedge
	(make-prism
	 (list
	  (float-vector 0 0 0)
	  (float-vector 0 37 0)
	  (float-vector 37 0 0))
	 37))
  (send wedge :locate #f(0 96 0) 'world)
  (send wedge :worldcoords)
  (setq *pickmenu* (instance pickmenu :init
			     nil
			     :objects (list cube wedge)
			     ))
  )
(format t "(pickmenu) ;; main of pickview.l~%")
