(defun a nil
  (setq *a* (instance button-example :init)))
(defun b nil
  (setq *b* (instance choice-example :init)))
(defun c nil
  (setq *c* (instance slider-example :init)))
(defun d nil
  (setq *d* (instance toggle-example :init)))
(defun e nil
  (setq *e* (instance item-example :init)))
(defun f nil
  (setq *f* (instance menu-example :init)))
(defun test nil
  (setq a (instance sunview-frame :init nil
		    :title "abc"
		    ))
  )
(defun test nil
  (setq a (instance sunview-frame :init nil
		    :title "abc"
		    ))
  (setq b (send a :create-subwindow sunview-panel
		:title "abc"
		))
  )
(defun test1 nil
  (setq B1 (send b :create-button :print-event :title "print args"))
  )
(defclass button-example
  :super sunview-frame
  :slots (P B1 B2 B3))
(defmethod button-example
  (:print-event
   (item event)
   (format t "item=~s,event=~s~%" item event))
  (:init
   ()
   #+sunview
   (send-super :init nil :title "Button example" :x 800 :y 400
	       :icon "/usr/include/images/hello_world.icon")
   #+xview
   (send-super :init nil :title "Button example" :x 800 :y 400
	       :icon "/usr/local/include/X11/images/hello_world.icon")
   #+sunview
   (setq P (send self :create-subwindow sunview-panel
		 :font "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
   #+xview
   (setq P (send self :create-subwindow sunview-panel
;;;		 :font "lucidasans-bold-12"
		 ))
   (setq B1 (send self :create-button :print-event :title "print args"))
   (setq B2 (instance panel-button-item :init P
		      :nproc :print-event :title "print args"))
   (setq B3 (instance panel-button-item :init P :title "print args"
		      :nproc
		      '(lambda (item event)
			 (format t "item=~s,event=~s~%" item event))))
   (send self :show t)
   self)
  )

(defclass choice-example
  :super sunview-frame
  :slots (P C1 C2 C3))
(defmethod choice-example
  (:print-event
   (value item event)
   (format t "value=~s,item=~s,event=~s~%" value item event))
  (:init
   ()
   #+sunview
   (send-super :init nil :title "Choice example" :x 800 :y 400
	       :icon "/usr/include/images/hello_world.icon")
   #+xview
   (send-super :init nil :title "Choice example" :x 800 :y 400
	       :icon "/usr/local/include/X11/images/hello_world.icon")
   #+sunview
   (setq P (send self :create-subwindow sunview-panel
		 :font "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
   #+xview
   (setq P (send self :create-subwindow sunview-panel
		 ))
   (setq C1 (send self :create-choice :print-event
		  :choices '(a b c) :title "print args"))
   (setq C2 (instance panel-choice-item :init P
		      :choices '(a b c)
		      :nproc :print-event :title "print args"))
   (setq C3 (instance panel-choice-item :init P :title "print args"
		      :choices '(a b c)
		      :nproc
		      '(lambda (value item event)
			 (format t "value=~s,item=~s,event=~s~%"
				 value item event))))
   (send self :show)
   self)
  )

(defclass slider-example
  :super sunview-frame
  :slots (P S1 S2 S3))
(defmethod slider-example
  (:print-event
   (value item event)
   (format t "value=~s,item=~s,event=~s~%" value item event))
  (:init
   ()
   #+sunview
   (send-super :init nil :title "Slider example" :x 800 :y 400
	       :icon "/usr/include/images/hello_world.icon")
   #+xview
   (send-super :init nil :title "Slider example" :x 800 :y 400
	       :icon "/usr/local/include/X11/images/hello_world.icon")
   #+sunview
   (setq P (send self :create-subwindow sunview-panel
		 :font "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
   #+xview
   (setq P (send self :create-subwindow sunview-panel
		 :font "lucidasans-bold-12"
		 ))
   (setq S1 (send self :create-slider :print-event
		  :min -10 :max 20 :title "print args"
		  :value 7 :length 80))
   (setq S2 (instance panel-slider-item :init P
		      :nproc :print-event :title "print args"))
   (setq S3 (instance panel-slider-item :init P :title "print args"
		      :min -10.6 :max 20.6 :value 7 :length 80
		      :vertical t
		      :nproc
		      '(lambda (value item event)
			 (format t "value=~s,item=~s,event=~s~%"
				 value item event))))
   (send self :show)
   self)
  )

(defclass toggle-example
  :super sunview-frame
  :slots (P T1 T2 T3))
(defmethod toggle-example
  (:print-event
   (value item event)
   (format t "value=~s,item=~s,event=~s~%" value item event))
  (:init
   ()
   #+sunview
   (send-super :init nil :title "Toggle example" :x 800 :y 400
	       :icon "/usr/include/images/hello_world.icon")
   #+xview
   (send-super :init nil :title "Toggle example" :x 800 :y 400
	       :icon "/usr/local/include/X11/images/hello_world.icon")
   #+sunview
   (setq P (send self :create-subwindow sunview-panel
		 :font "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
   #+xview
   (setq P (send self :create-subwindow sunview-panel
		 :font "lucidasans-bold-12"))
   (setq T1 (send self :create-toggle :print-event
		  :choices '(a b c) :value '(c)
		  :title "print args"))
   (setq T2 (instance panel-toggle-item :init P
		      :choices '(a b c) :value '(a c)
		      :nproc :print-event :title "print args"))
   (setq T3 (instance panel-toggle-item :init P :title "print args"
		      :choices '(a b c) :value t
		      :nproc
		      '(lambda (value item event)
			 (format t "value=~s,item=~s,event=~s~%"
				 value item event))))
   (send self :show)
   self)
  )


(defclass menu-example
  :super sunview-frame
  :slots (I))
(defmethod menu-example
  (:print-event
   (item event)
   (format t "item=~s,event=~s~%" item event))
  (:init
   ()
   (send-super :init nil :title "Button example" :x 800 :y 400
	       :icon
	       #+sunview
	       "/usr/include/images/hello_world.icon"
	       #+xview
	       "/usr/local/include/X11/images/hello_world.icon")
   (setq P (send self :create-subwindow sunview-panel
		 :font
		 #+sunview "/usr/lib/fonts/fixedwidthfonts/screen.b.12"
		 #+xview "lucidasans-bold-12"
		 ))
   (setq I  (instance panel-text-item :init P
		      :value "Initial text"
		      :menu
		      (instance sunview-menu :init
				:strings '(0 1 2 3))
		      :title "Text:" :length 30
		      :nproc
		      '(lambda (value item event)
			 (format t "value=~s,item=~s,event=~s~%"
				 value item event))
		      :eproc
		      '(lambda (item event)
			 (cond
			  ((and (equal (event_id event) ms_right)
				(event_is_down event))
			   (menu_show item (P . system-cadr) event)
			   (format t "item=~s,event=~s~%"
				   item event))
			  (t
			   (panel_default_handle_event item event)))
			 )))
   (send self :show)
   self))


(defclass item-example
  :super sunview-frame
  :slots (I))
(defmethod item-example
  (:print-event
   (item movement button pos time)
   (format t "item=~s,movement=~s,button=~s,pos=~s,time=~s~%"
	   item movement button pos time))
  (:notify-text-proc (value item event)
		     (format t "value=~s,item=~s,event=~s~%"
			     value item event))
  (:notify-button-proc (item event)
		       (format t "item=~s,event=~s~%" item event))
  (:menu-handler (value)
		 (format t "value=~s~%" value))
  (:init
   ()
   (send-super :init nil :title "Button example" :x 800 :y 400
	       :icon
	       #+sunview
	       "/usr/include/images/hello_world.icon"
	       #+xview
	       "/usr/local/include/X11/images/hello_world.icon")
   (setq P (send self :create-subwindow sunview-panel
		 :font
		 #+sunview
		 "/usr/lib/fonts/fixedwidthfonts/screen.b.12"
		 #+xview
		 "lucidasans-bold-12"))
   (setq I  (instance panel-text-item :init P :value "Initial text"
		      :menu
		      (instance sunview-menu :init
				:choices '(10 11 12)
				:strings '(aa bb cc)
				:ncols 4
				)
		      :title "Text:" :length 30
		      :nproc :notify-text-proc
		      :clicked-proc :print-event
		      ))
   (send I :enter-handler 'menu :menu-handler)
   (setq B  (instance panel-button-item :init P
		      :menu
		      (instance sunview-menu :init
				:choices '(12 13 14 15)
				:strings '(a b c d)
				:ncols 2)
		      :title "Text:"
		      :nproc :notify-button-proc
;		      :clicked-proc :print-event
		      ))
   (send B :enter-handler 'menu :menu-handler)
   (send self :show)
   self))
