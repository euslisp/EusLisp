;;;
;;;	hello-world	; show text and lines on canvas
;;;	icon-disp	; show hellow_world.icon
;;;	byebye-world	; show quit-button
;;;	icon-browser1	; show listing and selection
;;;	icon-browser2	; show image and name of icons
;;;	show-event	; show event name
;;;							M.I. 1989.5.27
(defun demo nil
  (hello-world) (icon-disp) (byebye-world)
  (icon-browser1) (icon-browser2) (show-event))
(defun hello-world nil
  (setq *frame* (window_create_frame 0 frame_label "Hello world."))
  (setq *canvas* (window_create_canvas *frame* win_width 300 win_height 300 0))
  (setq *pixwin* (canvas_pixwin *canvas*))
  (pw_vector *pixwin* 100 100 200 100 PIX_SRC 1)
  (pw_vector *pixwin* 100 200 200 200 PIX_SRC 1)
  (pw_vector *pixwin* 100 100 100 200 PIX_SRC 1)
  (pw_vector *pixwin* 200 100 200 200 PIX_SRC 1)
  (pw_text *pixwin* 125 150 PIX_SRC 0 "Hello World!")
  (window_fit *canvas*)
  (window_fit *frame*)
  (window_set *frame* win_show 1 0)
  )
(defun icon-disp nil
  (notify_do_dispatch)
  (setq hpixrect (icon_load_image
		  "/usr/include/images/hello_world.icon"))
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
  )

(defun-c-callable quit-proc
  ((p :integer) (e :integer)) :integer
  (format t "in quit-proc *frame* = ~S~%" *frame*)
  (window_destroy *frame*)
  (setq *quit* t))

(defun byebye-world nil
  (setq bold (pf_open "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
  (if (= bold 0) (return-from simple nil))
;  (setq hello (read-icon "/usr/include/images/hello_world.icon"))
;  (setq hpixrect (mem_point 64 64 1 hello))
  (setq hpixrect (icon_load_mpr "/usr/include/images/hello_world.icon"
				"no file"))
  (setq hicon (icon_create icon_image hpixrect 0))
  (setq *frame* (window_create_frame 0 frame_label "byebye-world"
				     frame_icon hicon
				     0))
  (setq *panel* (window_create_panel *frame* win_font bold 0))
  (panel_create_message *panel*
			panel_label_string "Hit button to quit."
			0)
  (panel_create_button *panel*
		       panel_label_image
		       (panel_button_image *panel* "byebye" 5 0)
		       panel_notify_proc
		       (pod-address 'quit-proc)
		       0)
  (window_fit *panel*)
  (window_fit *frame*)
  (window_set *frame* win_show 1 0)
  )

(defun-c-callable ls-proc
  ((p :integer) (e :integer)) :integer
  (setq str (concatenate string "ls "
			 (adr_to_string
			  (panel_get dir_item panel_value))
			 "^J"))
  (ttysw_input *tty* str (length str))
  )

(defun-c-callable SHOW-PROC
  ((p :integer) (e :integer)) :integer
  (panel_set image_item
	     panel_item_x (attr_col 5)
	     panel_item_y (attr_row 4)
	     panel_label_image
	     (icon_load_image
	      (concatenate string
			   (adr_to_string (panel_get_value dir_item))
			   "/"
			   (get_selection))
	      )
	     0)
  )
(defun icon-browser1 nil
  (notify_do_dispatch)
  (setq *frame* (window_create_frame 0 frame_label "icon_browser1" 0))
  (setq *tty* (window_create_tty *frame* win_columns 80
			       win_rows 20
			       0))
  (setq control_panel (window_create_panel *frame* 0))
  (setq dir_item (panel_create_text
		  control_panel
		  panel_value_display_length 13
		  panel_label_string "Dir: "
		  panel_value (unix:getwd)
		  0))
  (setq fname_item (panel_create_text
		    control_panel
		    panel_item_x (attr_col 0)
		    panel_item_y (attr_row 1)
		    panel_value_display_length 13
		    panel_label_string "File:"
		    0))
  (panel_create_button control_panel
		       panel_item_x (attr_col 0)
		       panel_item_y (attr_row 2)
		       panel_label_image (panel_button_image
					  control_panel "List" 0 0)
		       panel_notify_proc (pod-address 'ls-proc)
		       0)
  (panel_create_button control_panel
		       panel_label_image (panel_button_image
					  control_panel "Show" 0 0)
		       panel_notify_proc (pod-address 'show-proc)
		       0)
  (panel_create_button control_panel
		       panel_label_image (panel_button_image
					  control_panel "Quit" 0 0)
		       panel_notify_proc (pod-address 'quit-proc)
		       0)
  (window_fit control_panel)
  (window_fit *frame*)
  (setq display_panel (window_create_panel *frame*
					   win_below control_panel
					   win_right_of *tty*
					   0))
  (setq image_item (panel_create_message display_panel 0))
  
  (window_set *frame* win_show 1 0)
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
  (setq current_dir (adr_to_string (panel_get_value dir_item)))
  (setq name_list (expand_name
		   (concatenate
		    string
		    current_dir "/"
		    (adr_to_string (panel_get fname_item panel_value)))))
  (setq file_count (length name_list))
  (do ((ip (panel_get display_panel panel_first_item)
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
		 (svref name_list image_count)))))
    (panel_create_message display_panel
			  panel_item_y (attr_row (* 2 row))
			  panel_item_x (attr_col 0)
			  panel_label_image image
			  0)
    (panel_create_message display_panel
			  panel_item_y (attr_row (1+ (* 2 row)))
			  panel_item_x (attr_col 0)
			  panel_label_image
			  (panel_button_image
			   display_panel
			   (svref name_list image_count) 0 0)
			  0)
    )
   (inc image_count)
   )
  (if (<= image_count previous_image_count)
      (panel_update_scrolling_size display_panel))
  (panel_paint display_panel panel_clear)
  )

(defun icon-browser2 nil
  (notify_do_dispatch)
  (setq *frame* (window_create_frame 0 frame_label "icon_browser_2" 0))
  (init_control_panel 'browse-proc)
  (init_display_panel)
  (window_set control_panel
	      win_width (window_get display_panel win_width)
	      0)
  (window_fit *frame*)
  (window_set *frame* win_show 1 0)
  )

(defun init_control_panel (proc)
  (setq control_panel (window_create_panel *frame* 0))
  (setq dir_item (panel_create_text
		  control_panel
		  panel_label_x (attr_col 0)
		  panel_label_y (attr_row 0)
		  panel_value_display_length 23
;;		  panel_value (unix:getwd)
		  panel_value "/usr/include/images"
		  panel_label_string "Dir: "
		  0))
  
  (panel_create_button control_panel
		       panel_label_image
		       (panel_button_image control_panel "Browse" 0 0)
		       panel_notify_proc (pod-address proc)
		       0)
  (setq fname_item (panel_create_text
		    control_panel
		    panel_item_x (attr_col 0)
		    panel_item_y (attr_row 1)
		    panel_value_display_length 23
		    panel_value "*"
		    panel_label_string "File:"
		    0))
  (panel_create_button control_panel
		       panel_label_image (panel_button_image
					  control_panel "Quit" 6 0)
		       panel_notify_proc (pod-address 'quit-proc)
		       0)
  (window_fit_height control_panel)
  (window_set control_panel panel_caret_item fname_item 0)
  )

(defun init_display_panel nil
  (setq sb (scrollbar_create scroll_margin 10 0))
;;  (setq width (scrollbar_get sb scroll_thickness))
  (setq width 8)
  (setq display_panel
	(window_create_panel *frame*
			     win_below control_panel
			     win_x 0
			     win_vertical_scrollbar sb
			     0))
  (window_set display_panel
	      win_row_height 100
	      win_column_width 100
	      win_row_gap 10
	      win_column_gap 10
	      0)
  (window_set display_panel
	      win_left_margin (+ width 10)
	      win_top_margin 10
	      win_rows 4
	      win_columns 4
	      0)
  (window_set display_panel win_left_margin 10 0)
  )

(defun show-msg (window-cadr event msg)
  (cond
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
   ))
(defun-c-callable eventer-window-handler (window-cadr event)
  (let ((id (event_id event)))
    (cond
     ((equal id loc_drag) (show-msg window-cadr event "dragging"))
     ((equal id loc_move) (show-msg window-cadr event "moving"))
     ((equal id loc_still) (show-msg window-cadr event "still"))
     ((equal id ms_left) (show-msg window-cadr event "left"))
     ((equal id ms_right) (show-msg window-cadr event "right"))
     ((equal id ms_middle) (show-msg window-cadr event "middle"))
     ((equal id loc_winenter) (show-msg window-cadr event "winenter"))
     ((equal id loc_winexit)  (show-msg window-cadr event "winexit"))
     ((equal id loc_rgnenter)  (show-msg window-cadr event "rgnenter"))
     ((equal id loc_rgnexit)  (show-msg window-cadr event "rgnexit"))
     )
    ))
(defun show-event nil
  (notify_do_dispatch)
  (setq count 0)
  (setq *Frame*
	(window_create_frame
	 null frame_label "Show event" win_x 700 win_y 30
	 win_event_proc (pod-address 'eventer-window-handler)
	 frame_icon
	 (icon_create icon_image
		      (icon_load_mpr
		       "/usr/include/images/hello_world.icon"
		       (setq errbuf (make-string 32))))))
  (setq *panel*
	(window_create_panel
	 *Frame*
	 win_event_proc (pod-address 'eventer-window-handler)
	 win_font 
	 (pf_open "/usr/lib/fonts/fixedwidthfonts/screen.b.12")))
  (panel_create_message
   *panel* panel_label_string "Hit button to quit.")
  (panel_create_button
   *panel* panel_label_image (panel_button_image *panel* "quit" 5)
   panel_notify_proc (pod-address 'quit-proc))
  (window_fit *panel*)
  (setq *canvas*
	(window_create_canvas
	 *Frame* win_width 300 win_height 200
	 win_x 0 win_below *panel*
	 win_ignore_pick_event loc_still
	 win_consume_pick_event loc_drag
	 win_consume_pick_event win_in_transit_events
	 win_consume_pick_event win_mouse_buttons
	 win_event_proc (pod-address 'eventer-window-handler)))
  (setq *pixwin* (canvas_pixwin *canvas*))
  (pw_polygon_2 *pixwin* 0 0 1 #(3) #(10 10 100 10 50 50) pix_set 0 0 0)
  (pw_polyline *pixwin* 0 0 3
	       (list #f(50 10) #f(150 10) #f(100 50)) 0 0 0 pix_set)
  (pw_polypoint *pixwin* 0 0 3 '(10 20 200 20 150 50) pix_set)
  (window_fit *Frame*)
  (window_set *Frame* win_show true)
  )
