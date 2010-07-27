(defun long-to-4byte-string (v)
  (let ((str (make-string 4)))
    (dotimes (i 4 str)
	     (setf (aref str (- 3 i)) (logand v #xff))
	     (setq v (ash v -4)))))
(defun itimer-string (usec)
  (let
      ((str 
	(concatenate
	 string
	 (long-to-4byte-string (floor (/ usec 1000000)))
	 (long-to-4byte-string (floor (mod usec 1000000))))))
    (print str)
    (concatenate string str str)))

(defun-c-callable quit-proc (i e)
  (window_destroy Ex1-F))
(setq *last-time* 0)
(setq *set* nil)
(defun show-msg (window-cadr event msg)
  (when (not *set*) (event_set_time event 100)
	(setq *set* t))
  (cond
   ((equal window-cadr ex1-c)
    (let ((we (canvas_window_event ex1-c event)))
      (pw_text (canvas_pixwin ex1-c) 10 30 pix_src 0
	       (format nil "time:~a      " (event_time we)))
      (format t "time:~a~%" (event_time we))
      ;;      (format t "time difference:~a~%" (- last-time (event_time we)))
      (setq last-time (event_time we))
      ;;      (format t "event=~s,we=~s~%" event we)
      ;;      (format t "x=~s,y=~s~%" (event_x event) (event_y event))
      ;;      (format t "wx=~s,wy=~s~%" (event_x we) (event_y we))
      (pw_text (canvas_pixwin ex1-c) 10 50 pix_src 0
	       (setq msg (format nil "c:~a at ~s ~s~a    " msg
				 (event_x we) (event_y we)
				 (if
				     (event_is_button event)
				     (cond
				      ((event_is_up we) " up.")
				      ((event_is_down we) " down.")
				      (t "."))
				   "."))))
      ;;      (format t "~a~%" msg)
      ))
   ((equal window-cadr ex1-p)
    (let ((we (panel_window_event ex1-p event)))
      (pw_text (canvas_pixwin ex1-c) 10 40 pix_src 0
	       (format nil "p:~a at ~s ~s,~s.    " msg
		       (event_x we) (event_y we)
		       (when
			(event_is_button we)
			(cond
			 ((event_is_up we) 'up)
			 ((event_is_down we) 'down)
			 (t "")))))))
   ((equal window-cadr ex1-f)
    (pw_text (canvas_pixwin ex1-c) 10 30 pix_src 0
	     (format nil "~a on frame.    " msg)))
   ))
(defun-c-callable ex1-window-handler (window-cadr event)
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
(defun ex1 nil
  (notify_do_dispatch)
  (setq count 0)
  (setq Ex1-F
	(window_create_frame
	 null frame_label "Eusview ex1 By M.I 1988" win_x 800 win_y 30
	 win_event_proc (pod-address 'ex1-window-handler)
	 frame_icon
	 (icon_create icon_image
		      (icon_load_mpr
		       "/usr/include/images/hello_world.icon"
		       (setq errbuf (make-string 32))))))
  (setq ex1-p
	(window_create_panel
	 Ex1-F
	 win_event_proc (pod-address 'ex1-window-handler)
	 win_font 
	 (pf_open "/usr/lib/fonts/fixedwidthfonts/screen.b.12")))
  (panel_create_message
   ex1-p panel_label_string "Hit button to quit.")
  (panel_create_button
   ex1-p panel_label_image (panel_button_image ex1-p "quit" 5)
   panel_notify_proc (pod-address 'quit-proc))
  (window_fit ex1-p)
  (setq ex1-c (window_create_canvas
	       Ex1-F win_width 300 win_height 70 win_x 0 win_below ex1-p
	       win_ignore_pick_event loc_still
	       win_consume_pick_event loc_drag
	       win_consume_pick_event win_in_transit_events
	       win_consume_pick_event win_mouse_buttons
	       win_event_proc (pod-address 'ex1-window-handler)))
  (setq ex1-pw (canvas_pixwin ex1-c))
  (pw_polygon_2 ex1-pw 0 0 1 #(3) #(10 10 100 10 50 50) pix_set 0 0 0)
  (pw_polyline ex1-pw 0 0 3
	       (list #f(50 10) #f(150 10) #f(100 50)) 0 0 0 pix_set)
  (pw_polypoint ex1-pw 0 0 3 '(10 20 200 20 150 50) pix_set)
  (window_fit Ex1-F)
  (window_set Ex1-F win_show true)
  )
