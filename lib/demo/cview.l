(defun menu-test ()
  (setq w (window_create_frame 0 frame_label "simple" 0))
  (setq on_off_menu (menu_create MENU_STRINGS "On" "Off" 0 0))
  (menu_show on_off_menu w (make-string 100) 0)
  (window_main_loop w)
  )

(defun getentry (f)     ;f is a symbol
  (declare (type symbol f))
  (let* ((codeobj (symbol-function f))
	 (moduleaddr
	  (sys:address ((codeobj . module) . codevector)))
	 )
    (+ moduleaddr (codeobj . entry))))

(defun-c-callable QUIT-PROC
  ((p :integer) (e :integer)) :integer
  (format t "in quit-proc w = ~S~%" w)
  (window_destroy w)
  (setq *quit* t)
  )

(defun test nil
  (notify_do_dispatch)
  (setq w (window_create_frame 0 frame_label "simple" 0))
  (setq p (window_create_panel w 0))
  (panel_create_message p
			panel_label_string "Hit button to quit."
			0)
  (panel_create_button p
		       panel_label_image
		       (panel_button_image p "quit" 5 0)
		       panel_notify_proc
		       (pod-address 'quit-proc)
		       0)
  (window_fit p)
  (window_fit w)
  (window_set w win_show 1 0)
  #|
  (setq *quit* nil)
  (while (not *quit*) (notify_dispatch))
  (notify_dispatch)
|#
  )
(defun test2 nil
  (let* (
	 (w (window_create_frame 0))
	 (c (window_create_canvas w 0))
	 (pw (canvas_pixwin c))
	 )
    (pw_vector pw 100 100 200 100 PIX_SRC 1)
    (pw_vector pw 100 200 200 200 PIX_SRC 1)
    (pw_vector pw 100 100 100 200 PIX_SRC 1)
    (pw_vector pw 200 100 200 200 PIX_SRC 1)
    (pw_text pw 125 150 PIX_SRC 0 "Hello World!")
    (window_set w win_show 1 0)
    (setq *quit* nil)
    (while (not *quit*) (notify_dispatch))
    (notify_dispatch)
    )
  )

(defun simple nil
  (setq bold (pf_open "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
  (if (= bold 0) (return-from simple nil))
;  (setq hello (read-icon "/usr/include/images/hello_world.icon"))
;  (setq hpixrect (mem_point 64 64 1 hello))
  (setq hpixrect (icon_load_mpr "/usr/include/images/hello_world.icon"
				"no file"))
  (setq hicon (icon_create icon_image hpixrect 0))
  (setq w (window_create_frame 0 frame_label "simple"
			       frame_icon hicon
			       0))
  (setq p (window_create_panel w win_font bold 0))
  (panel_create_message p
			panel_label_string "Hit button to quit."
			0)
  (panel_create_button p
		       panel_label_image
		       (panel_button_image p "quit" 5 0)
		       panel_notify_proc
		       (pod-address 'quit-proc)
		       0)
  (window_fit p)
  (window_fit w)
;  (window_main_loop w)
  (window_set w win_show 1 0)
  (setq *quit* nil)
  (while (not *quit*) (notify_dispatch))
  (notify_dispatch)
  )

(defun-c-callable LS-PROC
  ((p :integer) (e :integer)) :integer
  (setq str (concatenate string "ls "
			 (adr_to_string
			  (panel_get dir_item panel_value))
			 "^J"))
  (ttysw_input tty str (length str))
  )

(defun lister nil
  (setq w (window_create_frame 0
			       frame_label "lister" 0))
  (setq p (window_create_panel w 0))
  (setq dir_item (panel_create_text
		  p
		  panel_label_string "File: "
		  panel_value_display_length 55
		  0))
  (panel_create_button p
		       panel_label_image
		       (panel_button_image p "List" 5 0)
		       panel_notify_proc
		       (pod-address 'ls-proc)
		       0)
  (panel_create_button p
		       panel_label_image
		       (panel_button_image p "Quit" 5 0)
		       panel_notify_proc
		       (pod-address 'quit-proc)
		       0)
  (window_fit_height p)
  (setq tty (window_create_tty w 0))
  (window_main_loop w)
  )

#|
(defun-c-callable TOGGLE_PROC
  ((mi :integer) (op :integer)) :integer
  (format t "toggle_proc~%")
  (case
   op
   (menu_display
    (if toggle
	(menu_set mi menu_string "Redisplay has been seen" 0)
      (menu_set mi menu_string "Redisplay" 0))
    (setq toggle (not toggle))
    (format t "menu display~%")
    )
   (menu_display_done)
   (menu_notify)
   (menu_notify_done)
   )
  mi
  )
(defun menu nil
  (setq w (window_create_frame 0))
  (setq m (window_get w win_menu))
  (setq i (menu_find m menu_string "Redisplay" 0))
  (setq toggle nil)
  (menu_set i menu_gen_proc
	    (pod-address 'toggle_proc)
	    0)
  (window_set w win_show 1 0)
  (setq *quit* nil)
  (while (not *quit*) (notify_dispatch))
  (notify_dispatch)
  )

(defun icon-disp nil
  (setq hpixrect (icon_load_image
		  "/usr/include/images/hello_world.icon"))
  (setq hicon (icon_create icon_image hpixrect 0))
  (setq w (window_create_frame 0))
  (setq c (window_create_canvas w
				win_height 64
				win_width 64
				0))
  (setq pw (canvas_pixwin c))
  (pw_rop pw 0 0 64 64 pix_src hpixrect 0 0)
  (window_fit w)
; (window_main_loop w)
  (window_set w win_show 1 0)
  (setq *quit* nil)
  (while (not *quit*) (notify_dispatch))
  (notify_dispatch)
  )
(defun make-str (n v)
  (do ((i 0 (1+ i))
       (str (make-string n)))
      ((>= i n)
       str)
      (svset str i v))
  )

(defun-c-callable SHOW-PROC
  ((p :integer) (e :integer)) :integer
  (panel_set image_item
	     panel_item_x (attr_col 5)
	     panel_item_y (attr_row 4)
	     panel_label_image
	     (icon_load_image (get_selection))
	     0)
  )
(defun icon-browser1 nil
  (setq w (window_create_frame 0 frame_label "icon_browser1" 0))
  (setq tty (window_create_tty w win_columns 30
			       win_rows 20
			       0))
  (setq control_panel (window_create_panel w 0))
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
  (window_fit w)
  (setq display_panel (window_create_panel w
					   win_below control_panel
					   win_right_of tty
					   0))
  (setq image_item (panel_create_message display_panel 0))
  
; (window_main_loop w)
  (window_set w win_show 1 0)
  (setq *quit* nil)
  (while (not *quit*) (notify_dispatch))
  (notify_dispatch)
  )

(defun icon_load_image (fname)
;  (mem_point 64 64 1
;	     (read-icon fname))
  (icon_load_mpr fname (make-string 100))
  )
(defun face_load_image (fname)
  (mem_point 64 64 8
	     (read-face fname)))

(defun-c-callable SHOW-FACE-PROC
  ((p :integer) (e :integer)) :integer
  (setq pw (canvas_pixwin c))
  (setq fpixrect (face_load_image (get_selection)))
  (pw_setcmsname pw "showcolor")
  (pw_putcolormap pw 0 256
		  (make-gray-cms 256)
		  (make-gray-cms 256)
		  (make-gray-cms 256))
  
  (pw_rop pw 0 0 64 64
	  pix_src
	  fpixrect 0 0)
  )
(defun face-browser nil
  (setq w (window_create_frame 0 frame_label "face_browser" 0))
  (setq tty (window_create_tty w win_columns 30
			       win_rows 20
			       0))
  (setq control_panel (window_create_panel w 0))
  (setq dir_item (panel_create_text
		  control_panel
		  panel_value_display_length 30
		  panel_label_string "Dir: "
		  panel_value (unix:getwd)
		  0))
  (setq fname_item (panel_create_text
		    control_panel
		    panel_item_x (attr_col 0)
		    panel_item_y (attr_row 1)
		    panel_value_display_length 30
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
		       panel_notify_proc (pod-address 'show-face-proc)
		       0)
  (panel_create_button control_panel
		       panel_label_image (panel_button_image
					  control_panel "Quit" 0 0)
		       panel_notify_proc (pod-address 'quit-proc)
		       0)
  (window_fit control_panel)
  (window_fit w)
  (setq c (window_create_canvas w
				win_below control_panel
				win_right_of tty
				win_height 64
				win_width 64
				0))
  ; (window_main_loop w)
  (window_set w win_show 1 0)
  (setq *quit* nil)
  (while (not *quit*) (notify_dispatch))
  (notify_dispatch)
  )

(defun face-disp nil
  (setq w (window_create_frame 0))
  (setq pw (canvas_pixwin
	    (window_create_canvas w
				  win_height 64
				  win_width 64
				  0)))
  (pw_setcmsname pw "showcolor")
  (pw_putcolormap pw 0 256
		  (make-gray-cms 256)
		  (make-gray-cms 256)
		  (make-gray-cms 256))
  
  (pw_rop pw 0 0 64 64
	  pix_src
	  (face_load_image "Mrs.matsui.face1")
	  0 0)
  (window_fit w)
  (window_main_loop w)
  )

(defun read-face (fname)
  (let ((face (make-string 4096)))
    (when
     (and (probe-file fname)
	  (not (string= fname "")))
     (with-open-file 
      (f fname)
      (do ((i 0 (1+ i)))
	  ((>= i 4096)
	   face)
	  (svset face i (read-char f)))))
    face))

(defun make-gray-cms (n)
  (do ((i 0 (1+ i))
       (str (make-string n)))
      ((>= i n)
       str)
      (svset str i i)))

(defun showcolor nil
  (let ((cms_size 256)
	(can_height 10))
    (setq w (window_create_frame 0))
    (setq c (window_create_canvas w
				  win_height can_height
				  win_width (* 2 cms_size)
				  0))
    (window_fit w)
    (setq pw (canvas_pixwin c))
    (pw_setcmsname pw "showcolor")
    (pw_putcolormap pw 0 cms_size
		    (make-gray-cms cms_size)
		    (make-gray-cms cms_size)
		    (make-gray-cms cms_size))
    (do ((i 0 (1+ i)))
	((>= i cms_size))
	(pw_rop pw (* 2 i) 0 2 can_height
		(logior pix_src (pix_color i))
		0 0 0)
	)
    (window_main_loop w)
    ))

(setq image_count 0)
(setq previous_image_count 0)
(setq previous_dir "")

(defun-c-callable BROWSE-PROC
  ((a :integer) (b :integer)) :integer
  (setq current_dir (adr_to_string (panel_get_value dir_item)))
  (when (not (string= current_dir previous_dir))
	(cd current_dir)
	(setq previous_dir (concatenate string current_dir "")))
  (setq name_list (expand_name
		   (adr_to_string (panel_get fname_item panel_value))))
  (setq file_count (length name_list))
  (do ((ip (panel_get display_panel panel_first_item)
	   next)
       )
      ((zerop ip))
      (setq next (panel_get ip panel_next_item))
      (pr_destroy (panel_get ip panel_label_image))
      (panel_free ip)
      )
  (setq previous_image_count image_count)
  (do ((row 0 (1+ row))
       (image_count 0)
       )
      ((>= image_count file_count)
       )
      (do ((col 0 (1+ col)))
	  ((or
	    (>= col 4)
	    (>= image_count file_count))
	   )
	  (setq image
		(icon_load_image
		 (svref name_list image_count)))
	  (if
	      (not (zerop image))
	      (panel_create_message display_panel
				    panel_item_y (attr_row row)
				    panel_item_x (attr_col col)
				    panel_label_image image
				    0))
	  (inc image_count)
	  )
      (if (<= image_count previous_image_count)
	  (panel_update_scrolling_size display_panel)
	)
      (panel_paint display_panel panel_clear)
      )
  )

(defun icon-browser2 nil
  (setq w (window_create_frame 0 frame_label "icon_browser_2" 0))
  (init_control_panel 'browse-proc)
  (init_display_panel)
  (window_set control_panel
	      win_width (window_get display_panel win_width)
	      0)
  (window_fit w)
  (window_main_loop w)
  )

(defun init_control_panel (proc)
  (setq control_panel (window_create_panel w 0))
  (setq dir_item (panel_create_text
		  control_panel
		  panel_label_x (attr_col 0)
		  panel_label_y (attr_row 0)
		  panel_value_display_length 23
		  panel_value (unix:getwd)
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
  (setq width (scrollbar_get sb scroll_thickness))
  (setq display_panel
	(window_create_panel w
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

(defun-c-callable FACE-BROWSE-PROC
  ((a :integer) (b :integer)) :integer
  
  (setq current_dir (adr_to_string (panel_get_value dir_item)))
  (when (not (string= current_dir previous_dir))
	(cd current_dir)
	(setq previous_dir (concatenate string current_dir "")))
  (setq name_list (expand_name
		   (adr_to_string (panel_get fname_item panel_value))))
  (setq file_count (length name_list))
  (do ((ip (panel_get display_panel panel_first_item)
	   next)
       )
      ((zerop ip))
      (setq next (panel_get ip panel_next_item))
      (pr_destroy (panel_get ip panel_label_image))
      (panel_free ip)
      )
  (setq previous_image_count image_count)
  (do ((row 0 (1+ row))
       (image_count 0))
      ((>= image_count file_count))
      (do ((col 0 (1+ col)))
	  ((or (>= col 4)
	       (>= image_count file_count)))
	  (setq image
		(face_load_image
		 (svref name_list image_count)))
	  (when
	   (not (zerop image))
	   (setq c (window_create_canvas w
					 win_height 64
					 win_width 64
					 0))
	   (setq pw (canvas_pixwin c))
	   (pw_setcmsname pw "showcolor")
	   (pw_putcolormap pw 0 256
			   (make-gray-cms 256)
			   (make-gray-cms 256)
			   (make-gray-cms 256))
	   
	   (pw_rop pw 0 0 64 64 pix_src image 0 0)
	   (inc image_count)
	  )
      (if (<= image_count previous_image_count)
	  (panel_update_scrolling_size display_panel)
	)
      (panel_paint display_panel panel_clear)
      )
      ))

(defun face-browser2 nil
  (setq w (window_create_frame 0 frame_label "icon_browser_2" 0))
  (init_control_panel 'face-browse-proc)
  (init_display_panel)
  (window_set control_panel
	      win_width (window_get display_panel win_width)
	      0)
  (window_fit w)
  (window_main_loop w)
  )

(defun sh (i)
  (format t "signal ~d~%" i)
  (if (not (= i 2)) #|sigint|#  (setq *signal-handler* 'sh))
  )

(setq *signal-handler* 'sh)
|#
