;-----------------
; file name is sierp.l
;-----------------
(defun sh (i)
  (format t "signal ~d~%" i)
  (if (not (= i 2)) #|sigint|#  (setq *signal-handler* 'sh))
  )

(setq *signal-handler* 'sh)

(defun register-function (f &rest l)
  (pod-address f)
  )
(defun aref (a i) (svref a i))

(load "notify.l")

;; Sierpinski demo
;; written by steve gadol of sun.
;; modified to run under excl with the lower case sensitive option set
;;

;(eval-when (compile load eval) (require :sunview) (require :notify))
;(use-package :sunview)
;(use-package :ff)
;(eval-when (compile) (proclaim '(optimize (speed 3) (safety 0))))

(defun init_plot (pw)
  (setq saved_pw pw)
  )
(defun plot_ (x y)
  (pw_vector saved_pw old_x old_y x y PIX_SRC 1)
  (set_plot_ x y)
  )
(defun set_plot_ (x y)
  (setq old_x x old_y y)
  )
(defun clear_canvas nil
  (pw_write saved_pw 0 0 512 512 PIX_SRC ;NULL
   0  0 0)
  )

;; command strategy
;; button: 
;;   start drawing 	- *notify-command* to :draw
;;   stop  drawing	- *notify-command* to :exit
;;   exit  program	- *notify-command* to :exit
;;
;; command	select	     		dispatch
;; :draw     begin drawing 
;; :exit     throw to exit loop		throw to stop drawing
;;

(defvar *n*)  
(defvar *h0*)

(defvar *sizes*)
(defvar *iterations*)

(defvar *pw*)
(defvar *x*)
(defvar *y*)
(defvar *h*)
(proclaim '(type fixnum *x* *y* *h* *n* *h0*))

(defun set-plot ()
  (set_plot_ *x* *y*))


(defun plot ()
  (plot_ *x* *y*))


(defun-c-callable ITERATION-FUNC
  ((i :integer) (k :integer)) :integer
  (setq *n* (aref *iterations* k))
  0)


(defun-c-callable SIZE-FUNC
  ((i :integer) (k :integer)) :integer
  (setq *h0* (aref *sizes* k))
  0)

(defun-c-callable DRAW-SIERPINSKI-CURVES-CALLBACK () :integer
  (setq *notify-command* :draw)
  (notify_stop)
  0)

(defun-c-callable ABORT-PGM () :integer
  (setq *notify-command* :exit)
  (notify_stop)
  0)

(defun sierpinski ()
  (let* ((base (window_create_frame 0
				    win_columns 80
				    frame_label    "Sierpinski curves"
				    0))
	 (cntl (window_create_panel base
				    win_rows 4
				    0))
	 (cnvs (window_create_canvas base
				     win_columns 66
				     win_rows 32
				     0)))

    (panel_create_choice
     cntl
     panel_item_x         (attr_col 0)
     panel_item_y         (attr_row 0)
     panel_label_string   "number of iterations:"
     panel_choice_strings  "1" "2" "3" "4" "5" "6" 0
     panel_notify_proc   (register-function 'iteration-func 0)
     0)
    
    (panel_create_choice
     cntl
     panel_item_x         (attr_col 0)
     panel_item_y         (attr_row 1)
     panel_label_string   "size to draw:"
     panel_choice_strings "32" "64" "128" "256" "512" 0
     panel_notify_proc (register-function 'size-func 1)
     0)

    (setq *start-drawing-item*
	  (panel_create_button
	   cntl
	   panel_item_x         (attr_col 0)
	   panel_item_y         (attr_row 3)
	   panel_label_image    (panel_button_image
				 cntl "start drawing"
				 15 0)
	   panel_notify_proc
	   (register-function 'draw-sierpinski-curves-callback)
	   0))
    
    (setq *panel-exit-item*
	  (panel_create_button
	   cntl
	   panel_item_x         (attr_col 20)
	   panel_item_y         (attr_row 3)
	   panel_label_image    (setq *exit-pgm-image* 
				      (panel_button_image
				       cntl "exit demo"
				       15 0))
	   panel_notify_proc (register-function 'abort-pgm)
      0))
    
    (setq *exit-draw-image* 
       (panel_button_image
	cntl "stop drawing" 15 0))
    
    (window_fit base)

    (setq *n*  1
	  *h0* 32)

    (setq *sizes* #(32 64 128 256 512))
    (setq *iterations* #(1 2 3 4 5 6))

    (setq *pw* (window_get cnvs canvas_pixwin))
    (init_plot *pw*)

    (window_set base win_show 1 frame_no_confirm 1 0)
    (unwind-protect
     (catch 'exit (notify-start-loop 'handle-select-command))
     (progn (window_destroy base)
	    (notify_dispatch)
	    0))))

(defun handle-select-command (command value)
   (declare (ignore value))
   (case command
      (:draw (draw-the-sierpinski-curve))
      (:exit (throw 'exit t))))

(defun handle-dispatch-command (command value)
   (declare (ignore value))
   (case command
      (:exit (throw 'draw t))))


(defun draw-the-sierpinski-curve ()
  (panel_set *panel-exit-item* panel_label_image *exit-draw-image* 0)
  (panel_set *start-drawing-item* panel_show_item 0 0)
  (catch 'draw (draw-sierpinski-curves))
  (panel_set *panel-exit-item* panel_label_image *exit-pgm-image* 0)
  (panel_set *start-drawing-item* panel_show_item 1 0)
  )

(defun draw-sierpinski-curves ()
  (clear_canvas)
  
  (let ((x0 0)
	(y0 0))
     (declare (type fixnum x0 y0))

    (setq *h*  (/ *h0* 4)
	  x0   (* 2 *h*)
	  y0   (* 3 *h*))

    (do ((i 1 (1+ i)))
        ((or (> i *n*)
	     (< *h* 2)) nil)

      (setq x0  (- x0 *h*)
	    *h* (/ *h* 2)
	    y0  (+ y0 *h*))

      (setq *x* x0
	    *y* y0)
      (set-plot)

      (a i)  (setq *x* (+ *x* *h*))  (setq *y* (- *y* *h*))  (plot)
      (b i)  (setq *x* (- *x* *h*))  (setq *y* (- *y* *h*))  (plot)
      (c i)  (setq *x* (- *x* *h*))  (setq *y* (+ *y* *h*))  (plot)
      (d i)  (setq *x* (+ *x* *h*))  (setq *y* (+ *y* *h*))  (plot)))
  0)

(defun a (i)
   (let ((im1 (1- i)))
      (notify-dispatch-step 'handle-dispatch-command 4)

    (if (> i 0) (progn
	    (a im1)  (setq *x* (+ *x* *h*))  (setq *y* (- *y* *h*))  (plot)
	    (b im1)  (setq *x* (+ *x* (* 2 *h*)))                    (plot)
	    (d im1)  (setq *x* (+ *x* *h*))  (setq *y* (+ *y* *h*))  (plot)
	    (a im1)))))

(defun b (i)
  (let ((im1 (1- i)))

      (notify-dispatch-step 'handle-dispatch-command 4)
    (if (> i 0) (progn
	    (b im1)  (setq *x* (- *x* *h*))  (setq *y* (- *y* *h*))  (plot)
	    (c im1)  (setq *y* (- *y* (* 2 *h*)))                    (plot)
	    (a im1)  (setq *x* (+ *x* *h*))  (setq *y* (- *y* *h*))  (plot)
	    (b im1)))))

(defun c (i)
  (let ((im1 (1- i)))

      (notify-dispatch-step 'handle-dispatch-command 4)
    (if (> i 0) (progn
	    (c im1)  (setq *x* (- *x* *h*))  (setq *y* (+ *y* *h*))  (plot)
	    (d im1)  (setq *x* (- *x* (* 2 *h*)))                    (plot)
	    (b im1)  (setq *x* (- *x* *h*))  (setq *y* (- *y* *h*))  (plot)
	    (c im1)))))

(defun d (i)
  (let ((im1 (1- i)))

      (notify-dispatch-step 'handle-dispatch-command 4)
    (if (> i 0) (progn
	    (d im1)  (setq *x* (+ *x* *h*))  (setq *y* (+ *y* *h*))  (plot)
	    (a im1)  (setq *y* (+ *y* (* 2 *h*)))                    (plot)
	    (c im1)  (setq *x* (- *x* *h*))  (setq *y* (+ *y* *h*))  (plot)
	    (d im1)))))

(format t "type (sierpinski) to start demo~%")

