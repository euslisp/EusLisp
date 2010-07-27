;-------------------
; file name is gosper.l
;-------------------

(defun sh (i)
  (format t "signal ~d~%" i)
  (if (not (= i 2)) #|sigint|#  (setq *signal-handler* 'sh))
  )

(setq *signal-handler* 'sh)

(defun register_function (f) (pod-address f))
(defun get_canvas_pixwin (c) (canvas_pixwin c))

(load "notify.l")

;;; Copyright 1986 Sun Microsystems

;;; dragon curves of the type described by bill gosper

;(in-package 'gosper)
;(eval-when (compile load eval) 
;   (require :sunview) 
;   (require :foreign)
;   (require :notify))
;(use-package '(lisp excl sunview ff))
;(export '(gosper-curves abort-gosper-curve))
;(import '(gosper-curves abort-gosper-curve) 'user)

(defvar bw-only t)
;(if* (and (not bw-only)
;	  (not (fboundp 'use-rainbow-color-map)))
;    then (load "rainbow.o")
;     (defforeign 'use-rainbow-color-map :entry-point
;       "_rainbow"))
;(if* (and (boundp 'bw-only) bw-only)
;   then (defun use-rainbow-color-map (x) nil))


(defconstant *pi-div-4* (/ pi 4.0))
(defconstant *sqrt-2* (sqrt 2.0))
(defvar *old-x*)
(defvar *old-y*)
(defvar *canvas*)
(defvar *min-length* 2)
(defvar *curve-type* 'c-curve)
(defvar *alldone* nil)

;; command strategy
;; button: 
;;   start drawing 	- *notify-command* to :draw
;;   stop  drawing	- *notify-command* to :exit
;;   exit  program	- *notify-command* to :exit
;;
;; command	select	     	 dispatch
;; :draw     begin drawing 
;; :exit     throw to exit loop  throw to stop drawing
;;

(defun select-command-handler (command value)
   (case command
      (:draw (draw-the-gosper-curve))
      (:exit (throw 'exit t))))

(defun dispatch-command-handler (command value)
   (case command
      (:exit (throw 'draw t))))


(defun-c-callable CURVE-SELECT
  ((i :integer) (k :integer)) :integer
  (setq *curve-type*
	(if (zerop k) 'c-curve 'dragon-curve))
  0)
(defun-c-callable ABORT-GOSPER-DEMO () :integer
   (setq *notify-command* :exit)
   (notify_stop)
   0)
(defun-c-callable DRAW-GOSPER-CURVE () :integer
  (setq *x_old* 140)
  (setq *y_old* 150)
  (gosper_clear_canvas *canvas*)
  (setq *notify-command* :draw)
  (notify_stop)
  0)
(defun-c-callable GOSPER-SET-RESOLUTION
  ((item :integer)(v :integer) (event :integer)) :integer
  (setq *min-length* v))

(defun gosper_curves ()
  (let* ((base (window_create_frame 0
				    frame_label "gosper curves"
				    win_height 512
				    win_width 512
				    0))
	 (cntl (window_create_panel base
		                   win_rows 5
				   0))
	 (cnvs (window_create_canvas base
				     0)))
    (panel_create_choice
     cntl
     panel_item_x    (attr_col 0)
     panel_item_y    (attr_row 0)
     panel_label_string "type of curve:"
     panel_choice_strings "c-curve" "dragon-curve" 0
     panel_notify_proc (register_function 'curve-select)
     0)
    (panel_create_slider
     cntl
     panel_item_x         (attr_col 0)
     panel_item_y        (attr_row 2)
     panel_label_string   "minimum line length in pixels"
     panel_value          3
     panel_min_value      2
     panel_max_value      8
     panel_show_range     0
     panel_show_value     1
     panel_notify_proc    (register_function 'gosper-set-resolution)
     0)
    (setq *start_drawing_item*
    (panel_create_button
     cntl
     panel_item_x         (attr_col 0)
     panel_item_y         (attr_row 4)
     panel_label_image    (panel_button_image
			   cntl "start drawing" 15 0)
     panel_notify_proc    (register_function 'draw-gosper-curve)
     0))
    (setq *panel_exit_item*
	  (panel_create_button
	   cntl
	   panel_label_image 
	   (setq *exit_pgm_image* 
		 (panel_button_image cntl "exit program" 15 0))
	   panel_notify_proc   
	   (register_function 'abort-gosper-demo) 0))
    (setq *exit_draw_image*
	  (panel_button_image cntl "stop drawing" 15 0))
    (window_set base frame_no_confirm 1 0)
    (setq *canvas* (get_canvas_pixwin cnvs))
;    (use_rainbow_color_map *canvas*)
    (setq *curve-type* 'c-curve)
    (setq *min-length* 3)
    (setq *alldone* nil)
    (window_set base win_show 1 0)
    (unwind-protect
	(catch 'exit (notify-start-loop 'select-command-handler))
      (progn (window_destroy base)
	     (notify_dispatch)
	     0))))

(defun command_loop ()
  (do ()
	 (nil)
      (setq *notify-command* nil)
      (notify_start)
      (case *notify-command*
	 (:exit (return))
	 (:draw (draw-the-gosper-curve)))))
	 
	 
      
					    
(defun gosper_clear_canvas (canvas)
  (pw_write *canvas* 0 0 512 512 pix_src 0 0 0))


(defun draw-the-gosper-curve ()
  (panel_set *panel_exit_item* panel_label_image *exit_draw_image* 0)
  (panel_set *start_drawing_item* panel_show_item 0 0)
  (catch 'draw
    (funcall *curve-type* *canvas*  200 0 1))
  (panel_set *panel_exit_item* panel_label_image *exit_pgm_image* 0)
  (panel_set *start_drawing_item* panel_show_item 1 0)
  )

(defun abort-gosper-curve () (throw 'stop 0))


(defun gosper_plot_line (canvas length angle)
  (connect-line
   canvas
   (+ *x_old* (* length (cos angle)))
   (+ *y_old* (* length (sin angle)))))

(defun connect-line (canvas x_new y_new)
  (pw_vector canvas (truncate *x_old*)
	     (truncate *y_old*)
	     (truncate x_new)
	     (truncate y_new)
	     pix_src (1+ (random 6)))
  (setq *x_old* x_new
	*y_old* y_new))

(defun dragon-curve (canvas length angle sign)
  (notify-dispatch-step 'dispatch-command-handler 10)
  (let ((length-div-sqrt-2 (/ length *sqrt-2*))
	(sign-times-pi-div-4 (* sign *pi-div-4*)))
    (cond (*alldone* nil)
	  ((< length *min-length*) (gosper_plot_line canvas length angle))
	  (t (dragon-curve canvas
			   length-div-sqrt-2
			   (+ angle sign-times-pi-div-4)
			   1.0)
	     (dragon-curve canvas
			   length-div-sqrt-2
			   (- angle sign-times-pi-div-4)
			   -1.0)))))

(defun c-curve (canvas length angle sign)
  (notify-dispatch-step 'dispatch-command-handler 10)
  (let ((length-div-sqrt-2 (/ length *sqrt-2*))
	(sign-times-pi-div-4 (* sign *pi-div-4*)))
    (cond (*alldone* nil)
	  ((< length *min-length*)
	   (gosper_plot_line canvas length angle))
	  (t (c-curve canvas
		      length-div-sqrt-2
		      (+ angle *pi-div-4*)
		      1.0)
	     (c-curve canvas
		      length-div-sqrt-2
		      (- angle *pi-div-4*)
		      -1.0)))))
    
(format t "~%;;; this demo draws curves of the type first decribed by bill gosper~%")
(format t ";;; run gosper_curves to start the demo~%~%")


;------ end of gosper.l ------------
