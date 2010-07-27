;;;
;;;	hello-world	; show text and lines on canvas
;;;	icon-disp	; show hellow_world.icon
;;;	byebye-world	; show quit-button
;;;	icon-browser1	; show listing and selection
;;;	icon-browser2	; show image and name of icons
;;;	show-event	; show event name
;;;							M.I. 1989.5.27
(format t "type (demo)~%")
(defun demo nil
  (hello-world) (icon-disp) (byebye-world)
  (icon-browser1) (icon-browser2) (show-event))
(defun print-size (&optional mes)
  (format t "~s~%" mes)
  (format t "frame (~s,~s)~%"
	  (window_get *frame* win_width) (window_get *frame* win_height))
  (format t "canvas (~s,~s)~%"
	  (window_get *canvas* win_width) (window_get *canvas* win_height))
  (format t "pixwin (~s,~s)~%"
	  (window_get *pixwin* win_width) (window_get *pixwin* win_height))
  )
(defun set-size (&key (s 300) (x 750) (y 400))
  (window_set *frame* win_width s)
  (window_set *frame* win_height s)
  (window_set *canvas* win_width s)
  (window_set *canvas* win_height s)
  (window_set *pixwin* win_width s)
  (window_set *pixwin* win_height s)
  (window_fit *pixwin*)
  (window_fit *canvas*)
  (window_set *frame* win_x x)
  (window_set *frame* win_y y)
  (window_fit *frame*)
  (print-size))
(defun hello-world nil
  (setq *frame* (window_create_frame 0 frame_label "Hello world."
				     win_x 0 win_y 0
				     win_width 400 win_height 400
				     win_dynamic_visual 1
				     0))
  (setq *canvas* (window_create_canvas
		  *frame* win_width 300 win_height 300
		  win_dynamic_visual 1))
  (setq *pixwin* (canvas_pixwin *canvas*))
  (window_set *frame* win_width 300)
  (window_set *frame* win_height 300)
  (window_set *canvas* win_width 300)
  (window_set *canvas* win_height 300)
  (window_set *pixwin* canvas_width 300)
  (window_set *pixwin* canvas_height 300)
  (window_fit *pixwin*)
  (window_fit *canvas*)
  (window_fit *frame*)
  (window_set *frame* win_show 1)
  (pw_vector *pixwin* 100 100 200 100 PIX_SRC 1)
  (pw_vector *pixwin* 100 200 200 200 PIX_SRC 1)
  (pw_vector *pixwin* 100 100 100 200 PIX_SRC 1)
  (pw_vector *pixwin* 200 100 200 200 PIX_SRC 1)
  (pw_text *pixwin* 125 150 PIX_SRC 0 "Hello World!")
  (notify_do_dispatch)
  )
(defun icon-disp nil
  (notify_no_dispatch)
  #+sunview
  (setq hpixrect (icon_load_image
		  "/usr/include/images/hello_world.icon"))
  #+xview
  (setq hpixrect (icon_load_image
		  "/usr/local/include/X11/images/hello_world.icon"))
  (setq hicon (icon_create icon_image hpixrect 0))
  (setq *frame* (window_create_frame 0 frame_label "ICON"))
  (setq *canvas* (window_create_canvas *frame*
				       win_height 64
				       win_width 64
				       0))
  (setq *pixwin* (canvas_pixwin *canvas*))
  (pw_rop *pixwin* 0 0 64 64 pix_src hpixrect 0 0)
  (window_fit *frame*)
  (window_set *frame* win_show 1 0)
  (notify_do_dispatch)
  )

(defun-c-callable quit-proc
  ((p :integer) (e :integer)) :integer
  (format t "in quit-proc *frame* = ~S~%" *frame*)
  (window_destroy *frame*)
  (setq *quit* t))

(defun byebye-world nil
  (notify_no_dispatch)
  #+sunview
  (setq bold (pf_open "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
  #+xview
  (setq bold (pf_open "lucidasans-bold-12"))
  
  (if (= bold 0) (return-from simple nil))
  ;;  (setq hello (read-icon "/usr/include/images/hello_world.icon"))
  ;;  (setq hpixrect (mem_point 64 64 1 hello))
  #+sunview
  (setq hpixrect (icon_load_mpr "/usr/include/images/hello_world.icon"
				"no file"))
  #+xview
  (setq hpixrect
	(icon_load_mpr
	 "/usr/local/include/X11/images/hello_world.icon"
	 "no file"))
  (setq hicon (icon_create icon_image hpixrect 0))
  (setq *frame* 
	(window_create_frame 0 frame_label "byebye-world"
			     frame_icon hicon
			     0))
  (setq *panel* (window_create_panel *frame*))
  (window_set *panel* win_font bold 0)
  
  (panel_create_message
   *panel*
   panel_label_string "Hit button to quit."
   0)
  (panel_create_button
   *panel*
   #+sunview
   panel_label_image
   #+xview
   panel_label_string
   #+sunview
   (panel_button_image *panel* "bye bye" 5 0)
   #+xview
   "bye bye"
   panel_notify_proc
   (pod-address 'quit-proc)
   0)
  (window_fit *panel*)
  (window_fit *frame*)
  (window_set *frame* win_show 1 0)
  (notify_do_dispatch)
  )

(defun-c-callable ls-proc
  ((p :integer) (e :integer)) :integer
  (setq str (concatenate string "ls "
			 (adr_to_string
			  (panel_get *dir-item* panel_value))
			 "^J"))
  (ttysw_input *tty* str (length str))
  )

(defun-c-callable SHOW-PROC
  ((p :integer) (e :integer)) :integer
  (panel_set image_item
	     panel_item_x (xv_col p 5)
	     panel_item_y (xv_row p 4)
	     panel_item_x 5
	     panel_item_y 4
	     panel_label_image
	     (icon_load_image
	      (concatenate string
			   (adr_to_string (panel_get_value *dir-item*))
			   "/"
			   (get_selection))
	      )
	     0)
  )
(defun icon-browser1 nil
  (notify_no_dispatch)
  (setq *frame* (window_create_frame 0 frame_label "icon_browser1" 0))
  (setq *tty* (window_create_tty *frame* win_columns 80
			       win_rows 20
			       0))
  (setq *control-panel* (window_create_panel *frame* 0))
  (format t "a~%")
  (setq *dir-item* (panel_create_text
		  *control-panel*
		  panel_value_display_length 13
		  panel_label_string "Dir: "
		  panel_value (unix:getwd)
		  0))
  (format t "a~%")
  (setq *fname-item* (panel_create_text
		    *control-panel*
		    panel_item_x (xv_col *control-panel* 0)
		    panel_item_y (xv_row *control-panel* 1)
		    panel_value_display_length 13
		    panel_label_string "File:"
		    0))
  (format t "a~%")
  (panel_create_button *control-panel*
		       panel_item_x (xv_col *control-panel* 0)
		       panel_item_y (xv_row *control-panel* 2)
		       #+xview
		       panel_label_string
		       #+xview
		       "List"
		       #+sunview
		       panel_label_image
		       #+sunview
		       (panel_button_image *control-panel* "List" 0 0)
		       panel_notify_proc (pod-address 'ls-proc)
		       0)
  (format t "a~%")
  (panel_create_button *control-panel*
		       #+xview
		       panel_label_string
		       #+xview
		       "Show"
		       #+sunview
		       panel_label_image
		       #+sunview
		       (panel_button_image *control-panel* "Show" 0 0)
		       panel_notify_proc (pod-address 'show-proc)
		       0)
  (format t "a~%")
  (panel_create_button *control-panel*
		       #+xview
		       panel_label_string
		       #+xview
		       "List"
		       #+sunview
		       panel_label_image
		       #+sunview
		       (panel_button_image *control-panel* "Quit" 0 0)
		       panel_notify_proc (pod-address 'quit-proc)
		       0)
  (format t "a~%")
  (window_fit *control-panel*)
  (window_fit *frame*)
  (setq *display-panel* (window_create_panel *frame*
					   win_below *control-panel*
					   win_right_of *tty*
					   0))
  (setq image_item (panel_create_message *display-panel* 0))
  
  (window_set *frame* win_show 1 0)
  (notify_do_dispatch)
  )

(defun icon_load_image (fname)
;  (mem_point 64 64 8
;	     (read-face fname)))
;  (mem_point 64 64 1
;	     (read-icon fname))
  (icon_load_mpr fname (make-string 100))
  )

(setq image_count 0)
(setq previous_image_count 0)

(defun-c-callable BROWSE-PROC
  ((a :integer) (b :integer)) :integer
  (setq current_dir (adr_to_string (panel_get_value *dir-item*)))
  (setq name_list (expand_name
		   (concatenate
		    string
		    current_dir "/"
		    (adr_to_string (panel_get *fname-item* panel_value)))))
  (setq file_count (length name_list))
  (do ((ip (panel_get *display-panel* panel_first_item)
	   (panel_get ip panel_next_item)))
      ((zerop ip))
      (pr_destroy (panel_get ip panel_label_image))
      (panel_free ip))
  (setq previous_image_count image_count)
  (setq image_count 0)
  (dotimes
   (row file_count)
   (when
    (not (zerop
	  (setq image
		(icon_load_image
		 (aref name_list image_count)))))
    (panel_create_message *display-panel*
			  panel_item_y (xv_row *display-panel* (* 2 row))
			  panel_item_x (xv_col *display-panel* 0)
			  panel_label_image image
			  0)
    (panel_create_message *display-panel*
			  panel_item_y (xv_row *display-panel* (1+ (* 2 row)))
			  panel_item_x (xv_col *display-panel* 0)
			  #+xview
			  panel_label_string
			  #+xview
			  (aref name_list image_count)
			  #+sunview
			  panel_label_image
			  #+sunview
			  (panel_button_image
			   *display-panel*
			   (aref name_list image_count) 0 0)
			  0)
    )
   (inc image_count)
   )
  (if (<= image_count previous_image_count)
      (panel_update_scrolling_size *display-panel*))
  (panel_paint *display-panel* panel_clear)
  )

(defun icon-browser2 nil
  (notify_no_dispatch)
  (setq *frame* (window_create_frame 0 frame_label "icon_browser_2" 0))
  (init_control_panel 'browse-proc)
  (init_display_panel)
  (window_set *control-panel*
	      win_width (window_get *display-panel* win_width)
	      0)
  (window_fit *frame*)
  (window_set *frame* win_show 1 0)
  (notify_do_dispatch)
  )

(defun init_control_panel (proc)
  (setq *control-panel* (window_create_panel *frame* 0))
  (setq *dir-item* (panel_create_text
		    *control-panel*
		    panel_label_x (xv_col *control-panel* 0)
		    panel_label_y (xv_row *control-panel* 0)
		    panel_value_display_length 23
		    panel_value
		    #+sunview
		    "/usr/include/images"
		    #+xview
		    "/usr/local/include/X11/images"
		    panel_label_string "Dir: "
		    0))
  
  (panel_create_button *control-panel*
		       #+xview
		       panel_label_string
		       #+xview
		       "Browse"
		       #+sunview
		       panel_label_image
		       #+sunview
		       (panel_button_image *control-panel* "Browse" 0 0)
		       panel_notify_proc (pod-address proc)
		       0)
  (setq *fname-item* (panel_create_text
		    *control-panel*
		    panel_item_x (xv_col *control-panel* 0)
		    panel_item_y (xv_row *control-panel* 1)
		    panel_value_display_length 23
		    panel_value "writedoc.icon"
		    panel_label_string "File:"
		    0))
  (panel_create_button *control-panel*
		       #+xview
		       panel_label_string
		       #+xview
		       "Quit"
		       #+sunview
		       panel_label_image
		       #+sunview
		       (panel_button_image *control-panel* "Quit" 6 0)
		       panel_notify_proc (pod-address 'quit-proc)
		       0)
  (window_fit_height *control-panel*)
  (window_set *control-panel* panel_caret_item *fname-item* 0)
  )

(defun init_display_panel nil
  (setq sb (scrollbar_create 0))
;;  (setq width (window_get sb scroll_thickness))
  (setq width 8)
  (setq *display-panel*
	(window_create_panel *frame*
			     win_below *control-panel*
			     win_x 0
			     win_vertical_scrollbar sb
			     0))
  (window_set *display-panel*
	      win_row_height 100
	      win_column_width 100
	      win_row_gap 10
	      win_column_gap 10
	      0)
  (window_set *display-panel*
	      win_left_margin (+ width 10)
	      win_top_margin 10
	      win_rows 4
	      win_columns 4
	      0)
  (window_set *display-panel* win_left_margin 10 0)
  )

(defun show-msg (window-cadr event msg)
  (cond
   ((equal window-cadr *paint*)
    (let ((we (canvas_window_event *paint* event)))
      (pw_text *pixwin* 50 120 pix_src 0
	       (format nil " *paint* time:~a      " (event_time we)))
      (setq last-time (event_time we))
      (pw_text *pixwin* 50 140 pix_src 0
	       (setq msg (format nil "*paint* c:~a at ~s ~s~a    " msg
				 (event_x we) (event_y we)
				 (if
				     (event_is_button event)
				     (cond
				      ((event_is_up we) " up.")
				      ((event_is_down we) " down.")
				      (t "."))
				   "."))))
      ))
   ((equal window-cadr *canvas*)
    (let ((we (canvas_window_event *canvas* event)))
      (pw_text (canvas_pixwin *canvas*) 50 120 pix_src 0
	       (format nil "time:~a      " (event_time we)))
      (setq last-time (event_time we))
      (pw_text (canvas_pixwin *canvas*) 50 140 pix_src 0
	       (setq msg (format nil "c:~a at ~s ~s~a    " msg
				 (event_x we) (event_y we)
				 (if
				     (event_is_button event)
				     (cond
				      ((event_is_up we) " up.")
				      ((event_is_down we) " down.")
				      (t "."))
				   "."))))
      ))
   ((equal window-cadr *panel*)
    (let ((we (panel_window_event *panel* event)))
      (pw_text (canvas_pixwin *canvas*) 50 160 pix_src 0
	       (format nil "p:~a at ~s ~s,~s.    " msg
		       (event_x we) (event_y we)
		       (when
			(event_is_button we)
			(cond
			 ((event_is_up we) 'up)
			 ((event_is_down we) 'down)
			 (t "")))))))
   ((equal window-cadr *frame*)
    (pw_text (canvas_pixwin *canvas*) 50 180 pix_src 0
	     (format nil "~a on frame.    " msg)))
   )
  (format t "~a ~%" window-cadr)
  )
(defun-c-callable eventer-window-handler (window-cadr event)
  (let ((id (event_id event)))
    (cond
     ((equal id loc_drag) (show-msg window-cadr event "dragging"))
     ((equal id loc_move) (show-msg window-cadr event "moving"))
;;;     ((equal id loc_still) (show-msg window-cadr event "still"))
     ((equal id ms_left) (show-msg window-cadr event "left"))
     ((equal id ms_right) (show-msg window-cadr event "right"))
     ((equal id ms_middle) (show-msg window-cadr event "middle"))
     ((equal id loc_winenter) (show-msg window-cadr event "winenter"))
     ((equal id loc_winexit)  (show-msg window-cadr event "winexit"))
;;;     ((equal id loc_rgnenter)  (show-msg window-cadr event "rgnenter"))
;;;     ((equal id loc_rgnexit)  (show-msg window-cadr event "rgnexit"))
     )
    (format t "window=~a ,event=~a~%" window-cadr event)
    ))
(defun show-event nil
  (setq count 0)
  (setq *Frame*
	(window_create_frame
	 null frame_label "Show event" win_x 700 win_y 30
	 win_event_proc (pod-address 'eventer-window-handler)
	 frame_icon
	 (icon_create icon_image
		      (icon_load_mpr
		       #+sunview
		       "/usr/include/images/hello_world.icon"
		       #+xview
		       "/usr/local/include/X11/images/hello_world.icon"
		       (setq errbuf (make-string 32))))
	 ))
  (setq *panel*
	(window_create_panel
	 *Frame*
	 win_event_proc (pod-address 'eventer-window-handler)
	 win_font 
	 #+sunview
	 (pf_open "/usr/lib/fonts/fixedwidthfonts/screen.b.12")
	 #+xview
	 (pf_open "lucidasans-bold-12")
	 ))
  (panel_create_message
   *panel* panel_label_string "Hit button to quit.")
  (panel_create_button
   *panel*
   #+xview
   panel_label_string
   #+xview
   "quit"
   #+sunview
   panel_label_image
   #+sunview
   (panel_button_image *panel* "quit" 5)
   panel_notify_proc (pod-address 'quit-proc))
  (window_fit *panel*)
  (setq *canvas*
	(window_create_canvas
	 *Frame* win_width 300 win_height 200
	 win_x 0 win_below *panel*
	 ))
  (setq *paint* (canvas_paint_window *canvas*))
  (window_set *paint*
;;;	 win_ignore_pick_event loc_still
	 win_consume_pick_event loc_drag
	 win_consume_pick_event loc_move
	 win_consume_pick_event loc_winenter
	 win_consume_pick_event loc_winexit
	 win_consume_pick_event win_in_transit_events
	 win_consume_pick_event win_mouse_buttons
	 win_event_proc (pod-address 'eventer-window-handler))
  (setq *pixwin* (canvas_pixwin *canvas*))
  (pw_polygon_2 *pixwin* 0 0 1 #(3) #(10 10 100 10 50 50) pix_set 0 0 0)
  (pw_polyline *pixwin* 0 0 3
	       (list #f(50 10) #f(150 10) #f(100 50)) 0 0 0 pix_set)
  (pw_polypoint *pixwin* 0 0 3 '(10 20 200 20 150 50) pix_set)
  (pw_text (canvas_pixwin *canvas*) 50 180 pix_src 0 "test desuyo")
  (window_fit *Frame*)
  (window_set *Frame* win_show true)
  (notify_do_dispatch)
  )
