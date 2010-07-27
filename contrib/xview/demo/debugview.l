;;;
;;;		Debug tool with window
;;;				1988.8.13 by M.Inaba
;;;				1989.11.24 revised for X-window
;;;
(defun define-debug-view-frame (&optional (frame nil))
  (setq *debug-view-frame*
	(instance sunview-frame :init frame
		  :name "Debug tool" :x 500 :y 0))
  )
(defvar *last-form* nil)
(defvar *last-file* "")
(defun define-debug-view-panel nil  
  (setq *debug-view-panel*
	(instance sunview-panel :init *debug-view-frame*
		  :x 0 :height 256
		  :col-num 1 :item-size 20))

  (setq *eval-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Eval"
	 :nproc
	 #'(lambda ()
	     (let ((form (read-from-string (get_selection))))
	       (if form
		   (setq *last-form* form))
	       (eval *last-form*)))
	 ))
  (setq *describe-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Describe"
	 :nproc
	 #'(lambda ()
	     (describe (read-from-string (get_selection)))
	     )))
  (setq *pf-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Pf"
	 :nproc
	 #'(lambda ()
	     (let ((func (read-from-string (get_selection))))
	       (pf func))
	     )))
  (setq *inspect-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Inspect"
	 ))
  (send *inspect-button*
	:nproc
	#'(lambda ()
	    (let ((obj
		   (read (make-string-input-stream (get_selection)) nil nil)))
	      (catch 'inspect
		(inspect1 obj (string obj)))
	      )))
  (setq *break-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Break"
	 :nproc
	 #'(lambda ()
	     (let ((func (read-from-string (get_selection))))
	       (break func))
	     )))
  (setq *trace-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Trace"
	 :nproc
	 #'(lambda ()
	     (let ((func (read-from-string (get_selection))))
	       (trace func))
	     )))
  (setq *step-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Step"
	 :nproc
	 #'(lambda ()
	     (let ((form (read-from-string (get_selection))))
	       (step form))
	     )))
  (setq *ls-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Ls ~A*"
	 ))
  (send *ls-button*
	:nproc
	#'(lambda ()
	    (let ((file (get_selection)))
	      (unix:system (format nil "ls ~A*" file))
	      )))
  (setq *lsl-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Ls -l ~A"
	 ))
  (send *lsl-button*
	:nproc
	#'(lambda ()
	    (let ((file (get_selection)))
	      (unix:system (format nil "ls -l ~A" file))
	      )))
  (setq *load-button*
	(instance
	 panel-button-item :init *debug-view-panel*
	 :name "Load"
	 ))
  (send *load-button*
	:nproc
	#'(lambda ()
	    (let ((file (get_selection)))
	      (if
		  (> (length file) 0)
		  (setq *last-file* file))
	      (if (> (length *last-file*) 0)
		  (load *last-file*)))
	    ))
  )
;;;
;;;
(defun debug-view (&optional (parent nil))
  (notify_do_dispatch)
  (define-debug-view-frame)
;;;
  (define-debug-view-panel)
  (send *debug-view-panel* :fit)
;;;
  (send *debug-view-frame* :show t)
  (send *debug-view-frame* :fit)
  )
;;
(format t "(debug-view) :top-level of debugview.l~%")

;;;;
;;;;
;;;;
(defclass debugmenu
  :super sunview-user-frame
  :slots
  (last-file
   pf-func
   last-form
   inspected-object
   debugpanel
   debugcanvas)
  )
(defmethod debugmenu
  (:eval (event)
	 (let ((form (read-from-string (get_selection) nil nil)))
	   (if form
	       (setq last-form form))
	   (eval last-form)))
  (:describe (event)
	     (describe (read-from-string (get_selection) nil nil))
	     )
  (:pf (event)
       (setq pf-func (read-from-string (get_selection) nil nil))
       (pf pf-func))
  (:inspect (event)
	    (setq inspected-object
		  (read (make-string-input-stream (get_selection)) nil nil))
	    (catch 'inspect
	      (inspect1 inspected-object (string inspected-object)))
	    )
  (:break (event)
	  (setq break-func (read-from-string (get_selection)))
	  (break break-func))
  (:trace (event)
	  (setq trace-func (read-from-string (get_selection)))
	  (trace trace-func))
  (:step (event)
	 (setq step-form (read-from-string (get_selection)))
	 (step step-form))
  (:ls (event)
       (let ((file (get_selection)))
	 (unix:system (format nil "ls ~A*" file))
	 ))
  (:ls-l (event)
	 (let ((file (get_selection)))
	   (unix:system (format nil "ls -l ~A" file))
	   ))
  (:load (event)
	 (let ((file (get_selection)))
	   (if
	       (> (length file) 0)
	       (setq load-file file))
	   (if (> (length load-file) 0)
	       (load load-file)))
	 )
  (:test-choice
   (value event)
  (:click-test
   (click button pos time)
   (format t "click=~A,button=~A, pos=~A,time=~A~%"
	   click button pos time)
   )
  (:init
   nil
   (send-super :init  :title "debug menu")
   (setq debugpanel
	 (send self :open-panel
	       :col-num 1))   ;	       :vertical t
   (send self :create-button :eval :title "Eval" )
   (send self :create-button :describe :title "Describe" )
   (send self :create-button :pf :title "Pf" )
   (send self :create-button :inspect :title "Inspect" )
   (send self :create-button :break :title "Break" )
   (send self :create-button :step :title "Step" )
   (send self :create-button :trace :title "Trace" )
   (send self :create-button :ls :title "Ls" )
   (send self :create-button :ls :title "Ls-L")
   (send self :create-button :load :title "Load" )
   (setq choice-test
	 (send self :create-choice :test-choice
	       :title "Test choice"
	       :display_level panel_current
	       :vertical t
	       :choices
	       #(object face edge 2dlnseg vertex junction)))
   (send self :create-toggle
	 :test-choice :vertical t
	 :title  "Test toggle"
	 :choices #(object face edge 2dlnseg vertex junction))
   (send self :create-slider
	 :test-choice :title "Test slider"
	 :vertical t :notify_level panel_all
	 :min_value -100 :value 0 :max_value 100)
   (send self :create-text :test-choice
	 :title "Test-text" :length 20
	 :vertical t)
   (send debugpanel :fit)
;;;
   (setq debugcanvas
	 (send self :open-canvas
	       :width 300 :height 300))
   (send self :create-clicked-eproc debugcanvas :click-test)
   (send self :create-dragging-eproc debugcanvas :click-test)
   ;   (send self :create-moving-eproc debugcanvas :click-test)
   (send self :create-drag-started-eproc debugcanvas :click-test)
   (send self :create-drag-finished-eproc debugcanvas :click-test)
   (send debugcanvas :fit)
   (send self :fit)
   (send self :show t)
   self
   )
  )
;;;
;;;
(defun demenu (&optional (parent nil))
  (setq *debugmenu* (instance debugmenu :init))
  )
;;
(format t "(debugmenu) :top-level of debugview.l~%")
