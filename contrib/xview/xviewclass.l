;;;
;;;	Xview Class package for euslisp
;;;		Using xview.c
;;;		      xviewconst.l
;;;		1989.11.10  version 1
;;;		Masayuki Inaba
;;;
;;;		The University of Tokyo
;;;	        Faculty of Engineering
;;;	        Department of Mechanical Engineering
;;;		Information System Engineering Laboratory
;;;		Tel. 03-812-2111  ext. 6345(office)
;;;				       7416(laboratory)
;;;
;;;
(eval-when
 (compile)
 (load "/usr/local/eus/geo/geoclasses.l")
 (load "/usr/local/eus/xview/xviewclasses.l")
 (load "/usr/local/eus/xview/xviewconst.l")
 )

(defvar xview-directory)


(defvar *font-directories* '("/usr/share/lib/X11/fonts"
			     "/usr/share/lib/X11/fonts/misc" 
			     "/usr/share/lib/X11/fonts/75dpi"
			     "/usr/share/lib/X11/fonts/100dpi"))

(defvar *icon-directories* '("/usr/share/include/X11/Xview/images"))

(defun string-body-address (str) (+ 8 (system:address str)))

(defun window-cadr-to-object (c)
  (cdr (assoc c xview-directory)))
(defun item-cadr-to-object (cadr)
  (let*
      ((panel-cadr (panel_get cadr panel_parent_panel))
       (panel (window-cadr-to-object panel-cadr)))
    (if panel
	(cdr (assq cadr (panel . item-object-list))))))

(defun hardcopy (&optional (fname (format nil "temp.ps"))
			   &key (scale 2) (direction t)
			   (x 1) (y 1) (wx 1150) (wy 876)
			   (offset #f(1.0 1.0)))   ;;; inches
  (unix:system
   (format nil "sdump -s ~A ~A -r ~S,~S,~S,~S -o ~S,~S > ~A"
	   scale (if direction "-d" "")
	   (1- x) (1- y) (+ x wx) (+ y wy)
	   (vector-x offset) (vector-y offset)
	   fname)))

(defun find-file (dir-list name)
  (cond
   ((probe-file name) name)
   ((null dir-list)
    (if (probe-file name) name ""))
   ((atom dir-list)
    (find-file (list (string dir-list)) name))
   (t
    (find-file (cdr dir-list)
	       (concatenate string
			    (string (car dir-list))
			    "/" name)))))
;;;
(defun mouse-status (window e)
  (when
   window
   (let* ((id (event_id e))
	  (we (send window :window_event e)))
     ;; button: left, middle, right, nil
     ;; movement: move, up, down, drag, still,
     ;;           winenter, winexit, rgnenter, rgnexit, nil
     (cond
      ((equal id loc_move)
       (send (window . mouse) :current-movement 'move)
       (send (window . mouse) :current-button nil))
      ((equal id ms_left) (send (window . mouse) :current-button 'left))
      ((equal id ms_middle) (send (window . mouse) :current-button 'middle))
      ((equal id ms_right) (send (window . mouse) :current-button 'right))
      ((equal id loc_drag)
       (send (window . mouse) :current-button
	     (send (window . mouse) :last-button))
       (send (window . mouse) :current-movement 'drag))
      ((equal id loc_winenter)
       (send (window . mouse) :current-movement 'winenter))
      ((equal id loc_winexit)
       (send (window . mouse) :current-movement 'winexit))
      )
     (when
      (event_is_button we)
      (cond
       ((event_is_up we) (send (window . mouse) :current-movement 'up))
       ((event_is_down we)
	(send (window . mouse) :last-button
	      (send (window . mouse) :current-button))
	(send (window . mouse) :current-movement 'down))))
     (prog1
	 (send (window . mouse) :status)
       (send (window . mouse) :last-movement
	     (send (window . mouse) :current-movement)))
     )))

(defun return-event nil (throw 'c-callable-proc nil))

(defmacro defwindow (name &key slots
			   (super 'object)
			   (size -1)
			   ((:metaclass metaklass) nil)
			   element-type  )
   (let ((methods
	  (append
	   (mapcar #'(lambda (x)
		       (list
			(read-from-string (format nil ":~a" x))
			'(&rest args)
			`(if args
			     (apply #'send (cons ,x args))
			   ,x)))
		   slots)
	   (mapcar #'(lambda (x)
		       (list
			(read-from-string (format nil ":set-~a" x))
			'(v)
			`(setq ,x v)))
		   slots)))
	 )
     `(progn
	(make-class ',name
		    :super ,super
		    :slots ',slots
		    :metaclass ,metaklass
		    :element-type ,element-type
		    :size ,size)
	(defmethod ,name
	  ,@methods)
	)
     ))

(eval-when
 (compile load eval)
 (defun _2- (str)
   (nsubstitute #\- #\_ str))
 (defmacro def-sunview-set-method (class
				   attr
				   &optional (head "WIN_"))
   (let ((selector (intern (_2- (string attr)) 'keyword))
	 (attr-key (intern
		    (concatenate string (string head) (string attr))))
	 (setfunc
	  (intern
	   (if (equal head "WIN_") "WINDOW_SET" "PANEL_SET")))
	 )
     `(defmethod ,class
	(,selector
	 (val)
	 (,setfunc system-cadr ,attr-key val)))
     ))
;;;
 (defmacro sunview-set-get-method (class
				       attr
				       &optional (head "WIN_"))
   (let* ((selector (intern (_2- (string attr)) 'keyword))
	  (attr-key (intern
		     (concatenate string head (string attr))))
	  (setfunc
	   (intern
	    (if (equal head "WIN_") "WINDOW_SET" "PANEL_SET")))
	  (getfunc
	   (intern
	    (if (equal head "WIN_") "WINDOW_GET" "PANEL_GET")))
	  )
     `(defmethod ,class
	(,selector
	 (&optional val)
	 (cond
	  (val
	   (,setfunc system-cadr ,attr-key val))
	  (t (,getfunc system-cadr ,attr-key)))))
     ))

 )

;;;
(eval-when
 (compile load eval)
 (defun make-c-callable-function (args)
   (cond 
    ((listp args)
     (if (eq (car args) 'lisp:lambda-closure)
	 (setq args (cddr args))
       (setq args (cdr args))
       ))
    ((derivedp args closure)  (setq args (cddr (args . code)))))
   (let* ((param (car args))
	  (bod (cdr args))
	  (paramspecs (mapcar #'(lambda (x) :integer) param))
	  (paramsyms (mapcar #'(lambda (x) (if (atom x) x (car x)))
			     param))
	  (sym (gensym)))
     (unintern sym)
     (send (let ((symbol foreign-pod))
		(intern (string sym) *package* ))
	   :init paramspecs
	   :integer
	   `(lambda ,paramsyms
	      (catch 'c-callable-proc . ,bod)))
     ))
;;;
 (defun make-panel-notify-function ()
   (make-c-callable-function
    '(lambda (item-cadr event-or-value event)
       (throw
	'c-callable-proc
	(let*
	    ((panel-cadr (panel_get item-cadr panel_parent_panel))
	     (panel (window-cadr-to-object panel-cadr))
	     (item (cdr (assq item-cadr (panel . item-object-list))))
	     (handler (item . notify-handler)))
	  (cond
	   ((null handler))
	   ((keywordp handler)
	    (classcase
	     item
	     (panel-button-item
	      (funcall #'send-window panel handler item event))
	     ((panel-choice-item panel-cycle-item panel-toggle-item)
	      (send-window
	       panel handler
	       (send item :choice (panel_get item-cadr panel_value))
	       item event))
	     (panel-slider-item
	      (send-window panel handler event-or-value item event))
	     (panel-text-item
	      (send-window panel handler
			    (adr_to_string (panel_get item-cadr panel_value))
			    item event))))
	   (t
	    (classcase
	     item
	     (panel-button-item (funcall handler item event))
	     ((panel-choice-item panel-cycle-item panel-toggle-item)
	      (funcall handler
		       (send item :choice (panel_get item-cadr panel_value))
		       item event))
	     (panel-slider-item (funcall handler event-or-value item event))
	     (panel-text-item
	      (funcall handler
		       (adr_to_string (panel_get item-cadr panel_value))
		       item event)))))
	  ))))
   )
 (defun send-window (window
		      method
		      &rest args)
   (cond
    ((null window) (warn "~s not defined" method))
    ((find-method window method)
     (apply #'send (cons window (cons method args))))
    (t
     (apply #'send-window
	    (cons
	     (send window :parent)
	     (cons method args))))))
;;;
 (defun widget-event-function (widget event args)
   (throw
    'c-callable-proc
    (when
     widget
     (let*
	 ((mouse-status (mouse-status widget event))
	  (we (send widget :window_event event))
	  (element
	   (assq mouse-status (widget . event-handler-list)))
	  handler)
       (cond
	((and
	  (widget . menu)
	  (equal (event_id event) ms_right)
	  (event_is_down event))
	 (send-window
	  widget 
	  (cdr (assq 'menu (widget . event-handler-list)))
	  (send-window widget :menu-show event)))
	((keywordp (setq handler (cdr element)))
	 (send-window
	  widget handler
	  widget				;; widget
	  (car element)			;; movement
	  (send (widget . mouse) :current-button)		;; button
	  (float-vector (event_x we) (event_y we)) ;; pos
	  (event_time we)))		;; time
	(handler
	 (funcall handler
		  widget			;; widget
		  (car element)		;; movement
		  (send (widget . mouse) :current-button) ;; button
		  (float-vector (event_x we) (event_y we)) ;;pos
		  (event_time we)         ;; time
		  ))  
	((derivedp widget panel-item)
	 (panel_default_handle_event (widget . system-cadr) event))
	))
     )))
 (defparameter *window-event-function*
   (make-c-callable-function
    '(lambda (cadr event args)
       (widget-event-function (window-cadr-to-object cadr) event args))))
 (defparameter *item-event-function*
   (make-c-callable-function
    '(lambda (cadr event args)
       (widget-event-function (item-cadr-to-object cadr) event args))))
 (defparameter *panel-notify-function* (make-panel-notify-function))
 (defparameter *window-itimer-function*
   (make-c-callable-function
    '(lambda (client type)
       (throw 'c-callable-proc
	      (let* ((window (window-cadr-to-object client)))
		(when
		 window
		 (let ((itimer-handler (send window :itimer)))
		   (cond
		    ((null itimer-handler))
		    ((keywordp itimer-handler)
		     (send window itimer-handler window type))
		    (t (funcall itimer-handler window type))))))))))
 (defparameter *canvas-repaint-function*
   (make-c-callable-function
    '(lambda (client pixwin repaint-area)
       (throw 'c-callable-proc
	      (let* ((window (window-cadr-to-object client)))
		(when
		 window
		 (let ((repaint-handler (window . repaint-handler)))
		   (cond
		    ((null repaint-handler))
		    ((keywordp repaint-handler)
		     (send-window window repaint-handler
				   window pixwin repaint-area))
		    (t (funcall repaint-handler window
				pixwin repaint-area))))))))))
 (defparameter *canvas-resize-function*
   (make-c-callable-function
    '(lambda (client width height)
       (throw 'c-callable-proc
	      (let* ((window (window-cadr-to-object client)))
		(when
		 window
		 (let ((resize-handler (window . resize-handler)))
		   (cond
		    ((null resize-handler))
		    ((keywordp resize-handler)
		     (send-window window resize-handler
				   window width height))
		    (t (funcall resize-handler window width height))))))))))
 (defparameter *item-itimer-function*
   (make-c-callable-function
    '(lambda (client type)
       (let* ((item (item-cadr-to-object client)))
	 (when
	  item
	  (let ((itimer-handler (send item :itimer)))
	    (cond
	     ((null itimer-handler))
	     ((keywordp itimer-handler)
	      (send item itimer-handler item type))
	     (t (funcall itimer-handler item type)))))))))
 )
;;;
(defun 4byte-string-to-long (str) (sys:peek str 0 :long)
#|  (let ((v 0))
    (dotimes (i 4 v)
	     (setq v (+ (* 256 v) (elt str i))))    ) |#
  )
(defun long-to-4byte-string (v)
  (sys:poke v (make-string 4) 0 :long)
#|  (let ((str (make-string 4)))
    (dotimes (i 4 str)
	     (setf (aref str (- 3 i)) (logand v #xff))
	     (setq v (ash v -8)))
    ) |#
  )
(defun itimer-string (sec)
  (let
      ((str 
	(concatenate
	 string
	 (long-to-4byte-string (floor sec))
	 (long-to-4byte-string (floor (* (- sec (floor sec))
					 1000000))))))
    (concatenate string str str)))
(defun icon-image (name)
  (setq name (find-file *icon-directories* name))
  (icon_load_mpr name (make-string 100)))

(defmethod sunview-mouse
  (:current-button   (&optional v)
    (if v (setq current-button v) current-button))
  (:current-movement (&optional v)
    (if v (setq current-movement v) current-movement))
  (:last-button  (&optional v)
    (if v (setq last-button v) last-button))
  (:last-movement  (&optional v)
    (if v (setq last-movement v) last-movement))
  (:status ()
   (case
    last-movement
    (up
     (case current-movement
	   (move 'moving)
	   (down 'pressed-again)))
    (down
     (case current-movement
	   (up 'clicked)
	   ((drag still move down) 'drag-started)))
    (drag
     (case current-movement
	   (up 'drag-finished)
	   ((drag still move) 'dragging)))
    (move
     (case current-movement
	   ((move still) 'moving)
	   (down 'moving)))
    (still
     (case current-movement
	   (move 'moving)
	   (drag 'dragging)
	   (up 'drag-finished)
	   (down 'moving)))
    ))
  (:init (&key
	  ((:current-movement cm))
	  ((:current-button cb)))
	 (setq current-movement cm current-button cb)
	 (setq last-movement nil last-button nil)
	 self))

(defmethod sunview-object
  (:cadr (&optional adr)
     (if adr
	 (setq system-cadr adr)
	 system-cadr))
  (:init (&rest l &key ((:system-cadr s)) &allow-other-keys)
      (if s (setq system-cadr s))
      self) )

(defmethod sunview-widget
  (:parent (&optional v)
	   (if v (setq parent v) parent))
  (:ancestor  ()
   (cond
    ((null (send self :parent)) self)
    (t (send (send self :parent) :ancestor))))
;;;  (:name (v) (send self :title v))
  (:show (&optional (f t))
	 (send self :fit)
	 (send self :show f))
  (:menu (&optional v)
	 (cond
	  (v
	   (setq menu v))
	  (menu menu)
	  (t (setq menu (instance sunview-menu :init self))))
	 menu)
;;;
  (:clicked-proc (method)
    (send self :enter-handler 'clicked method))
  (:moving-proc  (method)
    (send self :enter-handler 'moving method))
  (:dragging-proc  (method)
    (send self :enter-handler 'dragging method))
  (:drag-started-proc (method)
    (send self :enter-handler 'drag-started method))
  (:drag-finished-proc (method)
    (send self :enter-handler 'drag-finished method))
  ;; sunview-widget
  (:init (&rest l &key ((:menu m))
		((:font f))
		clicked-proc moving-proc
		dragging-proc drag-started-proc
		drag-finished-proc
		eproc
		&allow-other-keys)
	 (apply #'send-message self (class . super) :init l)
	 (if m (send self :menu m))
	 (send self :font f)
	 (setq mouse (instance sunview-mouse :init))
	 (if eproc (send self :set-eproc (make-c-callable-function eproc)))
	 (send self :enter-handler 'clicked clicked-proc)
	 (send self :enter-handler 'moving moving-proc)
	 (send self :enter-handler 'dragging dragging-proc)
	 (send self :enter-handler 'drag-finished drag-finished-proc)
	 (send self :enter-handler 'drag-started drag-started-proc)
	 self)
  )
;;;
(defmethod sunview-window
  (:hardcopy
   (&optional
    (value (format nil "window~A.ps" system-cadr))
    &key (scale 3) (direction nil)
    (offset #f(1.0 1.0)))   ;;; inches
   (hardcopy value :scale scale :direction direction
	     :offset offset
	     :x (send self :x) :y (send self :y)
	     :wx (send self :wx) :wy (send self :wy)))
  (:itimer () itimer-handler)
  (:set-itimer-period
   (v) (send self :set-itimer itimer-handler :period v))
  (:set-itimer (func &key (type itimer_real)
		     (period 0.1))   ;; sec
	       (setq itimer-handler func)
	       (notify_set_itimer_func
		system-cadr (send *window-itimer-function* :pod-address)
		type
		(itimer-string period)
		0))		
  (:stop-itimer (&optional (type itimer_real))
		(notify_set_itimer_func
		 system-cadr (send *window-itimer-function* :pod-address)
		 type 0 0))
  (:menu-show   (event)
   (let ((k 0))
     (if (derivedp menu sunview-menu)
	 (setq k (menu_show (menu . system-cadr)
			    system-cadr
			    event)))
     (if (eq k 0) nil
       (send menu :choice (1- k)))))
  (:clear ()
	  (pr_rop (send self :pixwin)
		  0 0
		  (send self :width) (send self :height)
		  pix_clr 0 0 0))
  (:drawpolygon (points &key (op pix_set)
			(x 0) (y 0)
			(pixwin (send self :pixwin))
			(rect 0) (sx 0) (sy 0))
		(pw_polygon_2 pixwin x y
			      1
			      (vector (length points))
			      points op rect sx sy))
  (:drawpolyline (points &key (op pix_set)
			 (pixwin (send self :pixwin))
			 (x 0) (y 0)
			 (mvlist 0) (brush 0) (texture 0))
		 (pw_polyline pixwin x y
			      (length points)
			      points mvlist
			      brush texture op))
  (:drawimage (imagestring
		&key (x 0) (y 0) (size 256) (width size) (height size)
		     (depth 8) (op pix_src)
		     (pixwin (send self :pixwin))
		     (pixrect (if (equal "" imagestring)
				  0
			          (mem_point width height depth imagestring)))
		     (pixrect-x 0) (pixrect-y 0))
    (pw_rop pixwin x y width height op pixrect pixrect-x pixrect-y))
  (:drawtext
    (textstring x0 y0 &key (font 0) (op pix_src)
	       (pixwin (send self :pixwin)))
    (pw_text pixwin x0 y0 op font
	       (string-body-address textstring)))
  (:drawttext
   (textstring x0 y0 &key (font 0) (op pix_src)
	       (pixwin (send self :pixwin)))
   (pw_ttext pixwin x0 y0 op font
	     (string-body-address textstring)))
  (:drawline
   (x0 y0 x1 y1 &key (op pix_src) (color 1) (pixwin (send self :pixwin)))
   (pw_vector pixwin x0 y0 x1 y1 op color))
  (:imagemove (&key (from (float-vector 0 0))
		    (to (float-vector 0 0))
		    (pixwin (send self :pixwin))
		    (op pix_src))
	      (let ((width (send self :width))
		    (height (send self :height)))
		(pw_copy pixwin to width height op pixwin from)
		))
  (:cmssize ()
	    (length (car (send self :get-colormap))))
  (:cmsname
   (&optional v)
   (if v (pw_setcmsname (send self :pixwin) v)
     (pw_getcmsname (send self :pixwin))))
  (:put-colormap
   (&optional (r (coerce '(0 255) string))
	      (g (coerce '(0 255) string))
	      (b (coerce '(0 255) string))
	      (index 0)
	      (count 2))
   (pw_putcolormap (send self :pixwin) index count r g b)
   )
  (:get-colormap ()
	(pw_getcolormap (send self :pixwin)) )
  (:pixwin () (window_get system-cadr win_pixwin))
  (:enter-handler    (mouse-status method)
   ;; method , function
   (when  method
      (push (cons mouse-status method) event-handler-list)
      (send self :set-eproc *window-event-function*))   )
  (:set-eproc (proc)
	(window_set
	       system-cadr win_event_proc (send proc :pod-address)))
  (:font (&optional (f t))
	 (cond
	  ((numberp f)
	   (window_set system-cadr win_font (setq font f)))
	  ((stringp f)
	   (window_set system-cadr win_font (setq font (pf_open f))))
	  ((eq f t))
	  (t (setq font 0)))
	 font)
  (:set (&rest l) (window_set system-cadr l))
  (:fit ()
	(if subwindows (send (car subwindows) :fit))
	(send self :fit-height)
	(send self :fit-width)
	)
  (:fit-height ()
	       (send self :height (send self :height))
	       (window_fit_height system-cadr))
  (:fit-width ()
	      (send self :width (send self :width))
	      (window_fit_width system-cadr))
  (:destroy () (window_destroy system-cadr))
  (:show (&optional (flag t))
	 (cond
	  (flag (setq flag true)
		(send self :fit))
	  (t (setq flag null)))
	 (window_set system-cadr win_show flag)
	 (notify_do_dispatch)
	 )
;;;
  (:create-subwindow
   (cls &rest args &key &allow-other-keys)
   (if subwindows (send (car subwindows) :fit))
   (push
    (apply #'send (instantiate cls) :init self args)
    subwindows)
   (car subwindows))
;;;
  (:create-item
   (cls &rest args)
   (let*
       ((window (or (car subwindows) self))
	(item (apply #'send (instantiate cls) :init window args)))
     (send window :item-row
	   (+ (send window :item-row) (send item :row-offset)))
     (send item :row)
     item))
  (:create-item-with-method
   (cls method &rest args)
   (apply #'send self :create-item cls (cons :nproc (cons method args))))
  (:create-slider
   (method &rest args)
   (apply #'send self :create-item-with-method panel-slider-item method args))
  (:create-text
   (method &rest args)
   (apply #'send self :create-item-with-method panel-text-item method args))
  (:create-choice
   (method &rest args)
   (apply #'send self :create-item-with-method panel-choice-item method args))
  (:create-cycle
   (method &rest args)
   (apply #'send self :create-item-with-method panel-cycle-item method args))
  (:create-toggle
   (method &rest args)
   (apply #'send self :create-item-with-method panel-toggle-item method args))
  (:create-message
   (&rest args)
   (apply #'send self :create-item panel-message-item args))
  (:create-button
   (method &rest args)
   (apply #'send self :create-item-with-method panel-button-item method args))
  (:below (w)
	  (window_set system-cadr win_below (w . system-cadr)))
  (:right-of (w)
	     (window_set system-cadr win_right_of (w . system-cadr)))
;;; sunview-window
  (:init (&rest l &key 
		((:title nam))
		x y width height below right-of
		&allow-other-keys)
	 (push (cons system-cadr self) xview-directory)
	 (if x (send self :x x))
	 (if y (send self :y y))
	 (if width (send self :width width))
	 (if height (send self :height height))
	 (if below (send self :below below))
	 (if right-of (send self :right-of right-of))
	 (apply #'send-message self (class . super) :init l)
	 self
	 )
  )
;;;
(defmethod sunview-frame
  (:window_event (e) e)
  (:title (&optional v)
	  (if v
	      (window_set system-cadr frame_label (setq name v))
	    name))
  (:icon (&optional v)
	 (cond
	  ((and v (setq v (find-file *icon-directories* v)))
	   (window_set system-cadr frame_icon
		       (icon_create icon_image (icon-image (setq icon v)) 0)))
	  (t icon)
	  ))
;;; sunview-frame
  (:init (&optional (par nil)
		    &rest args
		    &key
		    ((:title nam) "")
		    ((:icon v))
		    &allow-other-keys)
	 (notify_no_dispatch)
	 (cond
	  ((derivedp par sunview-window)
	   (cond
	    ((numberp (par . system-cadr))
	     (setq parent par)
	     (setq system-cadr (par . system-cadr)))
	    (t (setq parent par)
	       (setq system-cadr (window_create_frame 0))
	       (setq (par . system-cadr) system-cadr))
	    ))
	  ((numberp par)
	   (setq system-cadr (window_create_frame par))
	   (setq parent (window-cadr-to-object par)))
	  (t (setq parent nil)
	     (setq system-cadr (window_create_frame 0))))
	 (apply #'send-message self (class . super) :init args)
	 (send self :title nam)
	 (send self :icon v)
;;;	 (notify_do_dispatch)
	 self)
  )
;;;
(defmethod sunview-panel
  (:push-item-object-list (cadr object)
			  (push (cons cadr object) item-object-list))
  (:event (e) (panel_event system-cadr e))
  (:window_event (e) (panel_window_event system-cadr e))
  (:item-size (&optional v) (if v (setq item-size v) item-size))
  (:col-max (&optional v) (if v (setq col-max v) col-max))
  (:col-num (&optional v) (if v (setq col-max (1- v)) (1+ col-max)))
  (:layout   (&optional v)
   (cond
    (v (window_set system-cadr panel_layout v))
    (t (window_get system-cadr panel_layout))))
  (:horizontal   (&optional (flag 0))
   (cond
    ((eq flag 0)
     (equal (send self :layout) panel_horizontal))
    ((null flag)
     (send self :layout panel_vertical))
    (t (send self :layout panel_horizontal))))   
  (:vertical   (&optional (flag 0))
   (cond
    ((eq flag 0)
     (equal (send self :layout) panel_vertical))
    ((null flag)
     (send self :layout panel_horizontal))
    (t (send self :layout panel_vertical))))   
  (:item-col (&optional v)
	 (cond
	      ((numberp v)
	       (setq item-col v)
	       (if (= v 0) (setq item-row (1+ item-row))))
	      (t (setq item-col (1+ item-col))))
	     (if
		 (> item-col col-max)
		 (setq item-col 0 item-row (1+ item-row)))
	     item-col)
  (:item-row (&optional v)
	     (if (numberp v) (setq item-row v) item-row))
  ;; panel
  (:init (&optional par
		    &rest args &key
		    vertical horizontal
		    (scrollbar t)
		    ((:item-size is) 20)
		    ((:col-num cs) 1)
		    ((:col-max cm) 0)
		    &allow-other-keys)
	 (setq item-col -1 item-row 0)
	 (setq item-size is col-max cm)
	 (when (null par)
	       (setq par (instantiate sunview-frame))
	       (apply #'send (cons par (cons :init args))))
	 (send self :parent par)
	 (setq system-cadr (window_create_panel (send parent :cadr)))
	 
	 (if (memq scrollbar '(t vertical v))
	     (panel_set system-cadr
			win_vertical_scrollbar
			(scrollbar_create 0)))
	 (if (memq scrollbar '(t horizontal h))
	     (panel_set system-cadr
			win_horizontal_scrollbar
			(scrollbar_create 0)))
	 (if scrollbar (panel_update_scrolling_size system-cadr))
	 (if vertical
	     (panel_set system-cadr panel_layout panel_vertical))
	 (if horizontal
	     (panel_set system-cadr panel_layout panel_horizontal))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
;;;

 (defmethod sunview-canvas
  (:clear   ()
   (let ((width (send self :width)) (height (send self :height))
	 (pixwindow (send self :pixwin)))
     (pw_writebackground pixwindow 0 0 width height pix_clr)))
  (:set-eproc (proc)
	(window_set
	       (canvas_paint_window system-cadr)
	       win_event_proc (send proc :pod-address)))
  (:repaint-proc   (method)
   (when
    method
    (setq repaint-handler method)
    (window_set (canvas_paint_window system-cadr) canvas_repaint_proc
		(send *canvas-repaint-function* :pod-address))))
  (:resize-proc  (method)
   (when
    method
    (setq resize-handler method)
    (window_set (canvas_paint_window system-cadr) canvas_resize_proc
		(send *canvas-resize-function* :pod-address))))
  (:pixwin () (canvas_pixwin system-cadr))
  (:event (e) (canvas_event (canvas_paint_window system-cadr) e))
  (:window_event (e)
		 (canvas_window_event
		  (canvas_paint_window system-cadr)
		  e))
  (:set-half-color
   ()
   (let
       ((r (make-string 256))
	(g (make-string 256))
	(b (make-string 256)))
     (send self :gpal r g b  0.01 0 50 0.2 0.7 1 8 16)
     (send self :gpal r g b  0.2 30 40  0.3 0.7 1 16 24)
     (send self :gpal r g b  0.27 50 60 0.3 0.7 1 24 32)
     (send self :gpal r g b  0.25 70 80 0.3 0.7 1 32 40)
     (send self :gpal r g b  0.2 110 120 0.3 0.7 1 40 48)
     (send self :gpal r g b  0.2 160 170 0.3 0.7 1 48 56)
     (send self :gpal r g b  0.2 190 200 0.3 0.7 1 56 64)
     (send self :gpal r g b  0.2 220 230 0.3 0.7 1 64 72)
     (send self :put-colormap r g b 8 (- 72 8))
     ))
  (:set-vivid-color
   ()
   (let
       ((r (make-string 256))
	(g (make-string 256))
	(b (make-string 256)))
     (send self :gpal r g b  0.75 0 10 0.4 0.8 1 72 80)
     (send self :gpal r g b  0.75 30 40 0.2 0.8 1 80 88 )
     (send self :gpal r g b  0.75 90 100 0.4 0.8 1 88 96)
     (send self :gpal r g b  0.75 180 190 0.2 0.6 1 96 104)
     (send self :gpal r g b  0.75 270 280 0.4 0.8 1 104 112)
     (send self :gpal r g b  0.75 320 340 0.3 0.7 1 112 120)
     (send self :put-colormap r g b 0 (- 120 72)))
   )
  (:gpal
   (red-cmap green-cmap blue-cmap
	     sat h1 h2 dark bright &optional (group 1) (s 3) (e 64))
   (let ((hinc (/ (- h2 h1) (- e s)))
	 (linc (/ (- bright dark) (/ (- e s) group)))
	 (hls 0) (l dark) )
     (while (< s e)
       (setq hls (hls2rgb h1 l sat))
       (setf (aref red-cmap s) (car hls))
       (setf (aref green-cmap s) (cadr hls))
       (setf (aref blue-cmap s) (caddr hls))
       (inc s)
       (setq h1 (+ h1 hinc))
       (setq l (+ l linc))
       (cond ((or (> l bright) (< l dark)) (setq linc (- linc))))
       )
     ))
  (:set-gray-color
   (&optional (offset 128) (scale 0.5))
   (let ((cmap (make-string 256)))
     (do ((i 0 (1+ i)))
	 ((>= i 256))
	 (setf (aref cmap i)
	       (round (+ offset (* i scale)))))
     (send self :put-colormap cmap cmap cmap 0 256)))
  (:set-mono-tone
   ()
   (let ((cmap (coerce '(255 0) string)))
     (send self :put-colormap cmap cmap cmap 0 2)
     ))
  (:set-cmap-type
   (type)
   (case
    type
    ((:gray :gray-cmap :gray-color) (send self :set-gray-color))
    ((:vivid :vivid-cmap :vivid-color) (send self :set-vivid-color))
    ((:half :half-tone :half-color) (send self :set-half-color))
    ((:mono :mono-tone :monochrome) (send self :set-mono-tone))))
  ;; canvas
  (:line-width (wid) nil)
  (:line-style (dash) nil)
  (:init (&optional par
		    &rest args &key
		    resize-proc
		    repaint-proc
		    &allow-other-keys)
	 (when (null par)
	       (setq par (instantiate sunview-frame))
	       (apply #'send (cons par (cons :init args))))
	 (send self :parent par)
	 (setq system-cadr
	       (window_create_canvas (send parent :cadr)
				     win_dynamic_visual true))
	 (apply #'send-message self (class . super) :init args)
	 (push (cons (canvas_paint_window system-cadr) self)
	       xview-directory)
	 (window_set (canvas_paint_window system-cadr)
		     win_consume_pick_event win_up_events
		     win_consume_pick_event win_mouse_buttons
		     win_consume_pick_event loc_drag
;;;		     win_consume_pick_event loc_move
		     )
	 (send self :repaint-proc repaint-proc)
	 (send self :resize-proc resize-proc)
	 self)
  )

;;;
(defmethod sunview-textsw
  (:set-selection
   (first last &optional (type 1)) ;;; 1:primary 2:secondary 17:pending
   (textsw_set_selection system-cadr first last type))
  (:find-bytes-forward (buf index) (send self :find-bytes buf index 0))
  (:find-bytes-backward (buf index) (send self :find-bytes buf index 1))
  (:find-bytes
   (buf index &optional (direction 0))
   (let ((first 
	  (long-to-4byte-string index))
	 (last (long-to-4byte-string 0)))
     (textsw_find_bytes system-cadr first last buf (length buf) direction)
     (list (4byte-string-to-long first)
	   (4byte-string-to-long last))
     ))
  (:match-bytes-forward
   (start-sym end-sym index)
   (send self :match-bytes start-sym end-sym index textsw_delimiter_forward))
  (:match-bytes-backward
   (start-sym end-sym index)
   (send self :match-bytes start-sym end-sym index textsw_delimiter_backward))
  (:match-bytes-enclose
   (start-sym end-sym index)
   (send self :match-bytes start-sym end-sym index))
  (:match-bytes
   (start-sym end-sym index &optional (direction textsw_delimiter_enclose))
   (let ((first 
	  (long-to-4byte-string index))
	 (last (long-to-4byte-string 0)))
     (textsw_match_bytes system-cadr
			 first last
			 start-sym (length start-sym)
			 end-sym (length end-sym)
			 direction)
     (list (4byte-string-to-long first)
	   (4byte-string-to-long last))
     ))
  (:first-line (&optional v)
	       (if v (window_set system-cadr textsw_first_line v)
		 (window_get system-cadr textsw_first_line)))
  (:first (&optional v)
	  (if v (window_set system-cadr textsw_first v)
	    (window_get system-cadr textsw_first)))
  (:index-for-file-line (line-no)
			(textsw_index_for_file_line system-cadr line-no))
  (:normalize-view (charp)
		   (textsw_normalize_view system-cadr charp))
  (:possibly-normalize (charp)
		       (textsw_possibly_normalize system-cadr charp))
  (:last-point   ()
   (window_set system-cadr textsw_insertion_point textsw_infinity)
   (send self :insertion-point))
  (:set-file-contents
   (fname &optional (pos 0))
   (window_set system-cadr textsw_file_contents fname
	       textsw_first pos))
  (:set-contents (str &optional (pos 0))
		 (window_set system-cadr textsw_contents str
			     textsw_first pos))
  (:get-contents   (&optional (start 0) (end (send self :length)))
   (let* ((len (- end start)) (buf (make-string len)))
     (window_get system-cadr textsw_contents start buf len)
     buf))
  (:insertion-point   (&optional v)
   (if v (window_set system-cadr textsw_insertion_point v))
   (window_get system-cadr textsw_insertion_point))
  (:insert (buf &optional (len (length buf)))
	   (textsw_insert system-cadr buf len))
  (:delete (first len)
	   (textsw_delete system-cadr first (+ first len)))
  (:erase (first len)
	  (textsw_erase system-cadr first (+ first len)))
  (:replace (first len buf &optional (blen (length buf)))
	    (textsw_replace_bytes system-cadr first (+ first len)
				  buf blen))
  (:flush () (send self :insert "
"))
  (:scroll (count) (textsw_scroll_lines system-cadr count))
  (:screen-lines () (textsw_screen_line_count system-cadr))
  (:load (file-name &optional (position 0))
	 (window_set system-cadr textsw_file file-name
		     textsw_first position))
  (:save (&optional (x 0) (y 0))
	 (textsw_save system-cadr x y))
  (:store (file-name &optional (x 0) (y 0))
	  (textsw_store_file system-cadr file-name x y))
  (:reset (&optional (x 0) (y 0))
	  (textsw_reset system-cadr x y))
  (:length ()
	   (window_get system-cadr textsw_length))
  ;; textsw
  (:init (&optional par
		    &rest args &key &allow-other-keys)
	 (when (null par)
	       (setq par (instantiate sunview-frame))
	       (apply #'send (cons par (cons :init args))))
	 (send self :parent par)
	 (setq system-cadr (window_create_textsw
			    (send parent :cadr)
			    ))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
;;;
(defmethod sunview-tty
  (:input (buf &optional len)
	  (if (null len) (setq len (length (string buf))))
	  (ttysw_input system-cadr buf len))
  (:output (buf &optional len)
	   (if (null len) (setq len (length (string buf))))
	   (ttysw_output system-cadr buf len))
  (:flush () (send self :input ""))
  (:bell () (send self :output "^G" 1))
  ;; tty
  (:init (&optional par &rest args &key &allow-other-keys)
	 (when (null par)
	       (setq par (instantiate sunview-frame))
	       (apply #'send (cons par (cons :init args))))
	 (send self :parent par)
	 (setq system-cadr (window_create_tty (send par :cadr)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )

;;;;
(defmethod panel-item
  (:row-offset () 0)
  (:display-level (&optional v) nil)
  (:font (&optional (f t))
	 (cond
	  ((numberp f)
	   (panel_set system-cadr win_font (setq font f)))
	  ((stringp f)
	   (panel_set system-cadr win_font (setq font (pf_open f))))
	  ((eq f t))
	  (t (setq font 0)))
	 font)
  (:window_event (e) e)
  (:menu-show   (event)
   (let ((k 0))
     (if (derivedp menu sunview-menu)
	 (setq k (menu_show (menu . system-cadr)
			    ((send self :parent) . system-cadr)
			    event)))
     (if (eq k 0) nil
       (send menu :choice (1- k)))))
  (:layout   (&optional v)
   (cond
    (v (panel_set system-cadr panel_layout v))
    (t (panel_get system-cadr panel_layout))))
  (:horizontal   (&optional (flag 0))
   (cond
    ((eq flag 0)
     (equal (send self :layout) panel_horizontal))
    ((null flag)
     (send self :layout panel_vertical))
    (t (send self :layout panel_horizontal))))   
  (:vertical   (&optional (flag 0))
   (cond
    ((eq flag 0)
     (equal (send self :layout) panel_vertical))
    ((null flag)
     (send self :layout panel_horizontal))
    (t (send self :layout panel_vertical))))   
  (:enter-handler
   ;; method , function
   (mouse-status method)
   (when
    method
    (push (cons mouse-status method) event-handler-list)
    (send self :set-eproc *item-event-function*))
   )
  (:set-eproc (proc)
	      (panel_set
	       system-cadr panel_event_proc (send proc :pod-address)))
  (:enter-notify-handler   (method)
   (cond
    ((null method))
    (t
     (setq notify-handler method)
     (send self :set-nproc *panel-notify-function*)
     )))
  (:set-nproc (proc)
	      (panel_set
	       system-cadr panel_notify_proc (send proc :pod-address)))
  (:col (&optional (v col))
	(if v
	    (panel_set system-cadr panel_item_x
		       (xv_col (parent . system-cadr) (setq col v))))
	col)
  (:row (&optional (v row))
	(if v (panel_set system-cadr panel_item_y
			 (xv_row (parent . system-cadr) (setq row v))))
	row)
  (:item-col (&optional v)
	     (send self :col (* (parent . item-size) v))
	     (round (/ col (parent . item-size))))
  (:item-row (&optional (v row))
	     (send self :row v)
	     row)
  (:set (&rest l) (panel_set system-cadr l))
  (:title
   (&optional str)
   (if str
       (setq name
	     (let* ((len (length str))
		    (s (make-string len)))
	       (dotimes (i len s)
			(if (< i len)
			    (setf (aref s i) (aref str i))
			  (setf (aref s i) #\ ))))))
   (panel_set system-cadr panel_label_string name)
   name)
  (:show (&optional (flag t))
	 (if flag (setq flag true) (setq flag null))
	 (panel_set system-cadr panel_show flag)
	 )
  (:notify-level
   (&optional v)
   (case
    v
    (all (setq v panel_all))
    (current (setq v panel_done))
    (none (setq v panel_none))
    (specified (setq v panel_specified))
    (non-printable (setq v panel_non_printable))
    )
   (cond
    ((null v)
     (setq v (panel_get system-cadr panel_notify_level))
     (cond
      ((equal v panel_all) 'all)
      ((equal v panel_none) 'none)
      ((equal v panel_done) 'done)
      ((equal v panel_specified) 'specified)
      ((equal v panel_non_printable) 'non-printable)
      )
     )
    (t (panel_set system-cadr panel_notify_level v))))
  (:label-image (&optional image)
		(if image
		    (panel_set  panel_label_image image 0)
		  (panel_get system-cadr panel_label_image)))
  ;; panel-item
  (:init (&rest l &key
		title item-col item-row
		vertical
		horizontal
		nproc notify-level
		&allow-other-keys)
	 (if title (send self :title title))
	 (send self :item-col (send parent :item-col item-col))
	 (send self :item-row (send parent :item-row item-row))
	 (send self :enter-notify-handler nproc)
	 (if notify-level (send self :notify-level notify-level))
	 (if vertical (send self :vertical vertical))
	 (if horizontal (send self :horizontal horizontal))
	 (apply #'send-message self (class . super) :init l)
	 (send parent :push-item-object-list system-cadr self)
	 self)
  )
;;;
;;; button
;;;
(defmethod panel-button-item
  (:init (panel &rest args &key
		((:title nam) "")
		&allow-other-keys
		)
	 (send self :parent panel)
	 (setq name nam)
	 (setq system-cadr
	       (panel_create_button (panel . system-cadr)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
;;;
(defmethod panel-text-item
  (:row-offset () (if (send parent :vertical) 1 0))
  (:length (&optional v)
	   (if v
	       (panel_set system-cadr panel_value_display_length v)
	     (panel_get system-cadr panel_value_display_length)))
  (:value (&optional v)
	  (if v
	      (panel_set system-cadr panel_value (string v)))
	  (adr_to_string (panel_get system-cadr panel_value)))
  (:init (panel &rest args &key
		((:title nam) "")
		length
		value
		&allow-other-keys
		)
	 (send self :parent panel) (setq name nam)
	 (setq system-cadr
	       (panel_create_text (panel . system-cadr)))
	 (apply #'send-message self (class . super) :init args)
	 (if value (send self :value value))
	 (if length (send self :length length)
	   (send self :length (send panel :item-size)))
	 self)
  )

;;;
;;; choice , cycle , toggle
;;;
(defmethod panel-selectable-item
  (:row-offset   ()
   (cond
    ((send self :vertical)
     (case
      (send self :display-level)
      (none 0)
      (current 1)
      (t (1+ (length choices)))))
    (t 0)))
  (:strings   (&optional (v -1))
   (cond
    ((null v)
     (if strings
	 strings
       (setq strings
	     (mapcar #'string (coerce choices cons))))
     (if strings (panel_set system-cadr panel_choice_strings strings 0)))
    ((eq v -1) strings)
    (t
     (setq strings (mapcar #'string (coerce v cons)))
     (if strings (panel_set system-cadr panel_choice_strings strings 0))))
   strings)
  (:display-level   (&optional v)
   (case v
	 (all (setq v panel_all))
	 (current (setq v panel_current))
	 (none (setq v panel_none)))
   (cond
    ((null v)
     (setq v (panel_get system-cadr panel_display_level))
     (cond
      ((equal v panel_all) 'all)
      ((equal v panel_none) 'none)
      ((equal v panel_current) 'current)))
    (t (panel_set system-cadr panel_display_level v))))
  (:choices (&optional vec)
	    (if vec (setq choices (coerce vec vector)))
	    choices)
  (:value (&optional v)
	  (send self :choice (position v choices)))
  (:choice (&optional k)
	   (cond
	    ((and (numberp k) (< -1 k (length choices)))
	     (panel_set system-cadr panel_value k) (aref choices k))
	    (t (aref choices (panel_get system-cadr panel_value)))))
;;; Panel-selectable-item
  (:init (&rest args &key
		((:title nam) "")
		((:choices c) #(""))
		((:strings strs))
		(display-level 'all)
		(value nil)
		&allow-other-keys)
	 (setq choices (coerce c vector))
	 (if (null strs) (setq strings (mapcar #'string choices)))
	 (apply #'send-message self (class . super) :init args)
	 (send self :display-level display-level)
	 (if value (send self :value value))
	 (send self :strings strs)
	 self)
  )
;;;
(defmethod panel-choice-item
  (:init (panel &rest args &key
		((:title nam) "")
		(display-level 'all)
		&allow-other-keys)
	 (send self :parent panel) (setq name nam)
	 (setq system-cadr (panel_create_choice (panel . system-cadr)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
;;;
(defmethod panel-cycle-item
  (:init (panel &rest args &key
		((:title nam) "")
		(display-level 'current)
		&allow-other-keys)
	 (send self :parent panel) (setq name nam)
	 (setq system-cadr
	       (panel_create_cycle (panel . system-cadr)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )

;;;
(defmethod panel-toggle-item
  (:value (&optional (v 0))
	  (if (eq v t) (setq v choices))
	  (cond
	   ((eq v 0) (send self :choice))
	   (t (let ((ws 0))
		(mapc #'(lambda (x)
			  (if (setq x (position x choices))
			      (setq ws (logior (ash 1 x) ws))))
		      (coerce v cons))
		(send self :choice ws)))))
  (:choice (&optional (k (panel_get system-cadr panel_value)))
	   (let (ws)
	     (panel_set system-cadr panel_value k)
	     (dotimes (i (length choices) (reverse ws))
		      (if (eq 1 (logand 1 k))
			  (setq ws (cons (aref choices i) ws)))
		      (setq k (ash k -1)))
	     ))
  (:init (panel &rest args &key
		((:title nam) "")
		&allow-other-keys)
	 (send self :parent panel) (setq name nam)
	 (setq system-cadr
	       (panel_create_toggle (panel . system-cadr)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
;;;
;;; slider
;;;
(defmethod panel-slider-item
  (:value (&optional v)
	  (if v (panel_set system-cadr panel_value v)
	    (panel_get system-cadr panel_value)))
  (:min (&optional v)
	  (if v (panel_set system-cadr panel_min_value v)
	    (panel_get system-cadr panel_min_value)))
  (:max (&optional v)
	  (if v (panel_set system-cadr panel_max_value v)
	    (panel_get system-cadr panel_max_value)))
  (:row-offset () (if (send self :vertical) 1 0))
  (:length (&optional v)
	   (if v
	       (panel_set system-cadr panel_slider_width v)
	     (panel_get system-cadr panel_slider_width)))
  (:init (panel &rest l &key
		((:title nam) "")
		((:length len) 100)
		((:min min-v) 0)
		value
		((:max max-v) 100)
		&allow-other-keys)
	 (send self :parent panel) (setq name nam)
	 (setq system-cadr
	       (panel_create_slider
		(panel . system-cadr)
		panel_show_value true
		panel_min_value min-v
		panel_max_value max-v))
	 (apply #'send-message self (class . super) :init l)
	 (send self :value value)
	 (send self :length len)
	 self)
  )
;;;
;;; message
;;;
(defmethod panel-message-item
  (:init (panel &rest args &key
		((:title nam) "")
		&allow-other-keys
		)
	 (send self :parent panel) (setq name nam)
	 (setq system-cadr
	       (panel_create_message (panel . system-cadr)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
;;;
;;; Menu
;;;
(defmethod sunview-menu
  (:choice (k) (elt choices k))
  (:strings
   (&optional v)
   (setq strings (mapcar #'string (coerce v cons)))
   (menu_set system-cadr menu_strings strings 0)
   )
  (:ncols (&optional v)
	  (if v (menu_set system-cadr menu_ncols v)
	    (menu_get system-cadr menu_ncols)))
  (:nrows (&optional v)
	  (if v (menu_set system-cadr menu_nrows v)
	    (menu_get system-cadr menu_nrows)))
;;;  (:boxed (&optional v)
;;;	  (not (zerop
;;;		(if v (menu_set system-cadr menu_boxed v)
;;;		  (menu_get system-cadr menu_boxed)))))
  (:find (str)
	 (menu_find system-cadr menu_string (string str)))
  (:set (&rest l) (menu_set l))
  (:insert (nth v)
	   (menu_set system-cadr menu_insert nth v))
  (:string-item (str i)
		(menu_set system-cadr menu_string_item
			  (string str) i))
  (:init (&rest args &key
		frame
		((:strings strs))
		((:choices cs))
		ncols nrows
		&allow-other-keys)
	 (setq choices cs)
	 (cond
	  (strs (setq strings (mapcar #'string (coerce strs cons)))
		(if (null cs) (setq choices (coerce strs cons))))
	  (t (setq strings (mapcar #'string (coerce choices cons)))))
	 (cond
	  (frame
	   (setq system-cadr (window_get (frame . system-cadr)
					 win_menu)))
	  (t (setq system-cadr (menu_create menu_strings strings 0))))
	 (apply #'send-message self (class . super) :init args)
	 (if ncols (send self :ncols ncols))
	 (if nrows (send self :nrows nrows))
	 self)
  )
;;;
#|
(defclass menu-item
  :super sunview-object
  :slots (name))

(defmethod menu-item
  (:set-eproc (proc)
	      (menu_set
	       system-cadr menu_gen_proc (send proc :pod-address)))
  (:set (&rest l) (menu_set l))
  (:insert (nth v)
	   (menu_item_set system-cadr menu_insert nth v))
  (:init (&rest args &key
		((:name nam) "")
		cadr
		&allow-other-keys)
	 (setq name nam)
	 (if cadr
	     (setq system-cadr cadr)
	   (setq system-cadr (menu_create_item MENU_STRING name)))
	 (apply #'send-message self (class . super) :init args)
	 self)
  )
|#

(sunview-set-get-method sunview-window x)
(sunview-set-get-method sunview-window y)
(sunview-set-get-method sunview-window width)
(sunview-set-get-method sunview-window height)
(sunview-set-get-method sunview-window columns)
(sunview-set-get-method sunview-window cursor)

(sunview-set-get-method sunview-window column_width)
(sunview-set-get-method sunview-window column_gap)
(sunview-set-get-method sunview-window row_height)
(sunview-set-get-method sunview-window row_gap)
(sunview-set-get-method sunview-window top_margin)
(sunview-set-get-method sunview-window bottom_margin)
(sunview-set-get-method sunview-window left_margin)
(sunview-set-get-method sunview-window right_margin)
;;;;
(defmethod canvas-viewsurface
  (:canvas (&rest args)
	   (if args
	       (apply #'send (cons canvas args))
	     canvas))
  (:frame (&rest args)
	  (if args
	      (apply #'send (cons frame args))
	    frame))
  (:pixwin () pixwindow)
  (:color (&optional v) (if v (setq color v) color))
  (:init  (&key
	    ((:canvas c) nil)
	    (parent null)
	    (size 300)
	    (width size)
	    (height size)
	    (cmap-type :mono)
	    (x 0) (y 0)
	    (title " ")
	    ((:buffer-mode bm) nil)
	    &allow-other-keys    )
   (setq buffer-mode bm)
   (cond
    ((numberp c)
     (setq frame (instantiate sunview-frame))
     (setq (frame . system-cadr) (window_get c win_owner))
     (setq canvas (instantiate sunview-canvas))
     (setq (canvas . system-cadr) c)
     (send canvas :parent frame))
    ((derivedp c sunview-canvas)
     (setq frame (c . parent) canvas c))
    (t
     (setq frame (instance sunview-frame :init nil :x x :y y
			   :title title))
     (setq canvas (instance sunview-canvas :init frame
			    :width width :height height))
     (send frame :show)
     ))
   (send canvas :cmsname (format nil "viewsurface~s" (unix:getpid)))
;   (send self :set-cmap-type cmap-type)
   (setq pixwindow (send canvas :pixwin))
   (setq rasterop pix_src color 255)
   (setq back-pixwindow pixwindow)
   self)
  (:rasterop (&optional v)
	     (if v (setq rasterop v) rasterop))
  (:close () (send frame :destroy))
  (:set-erase-mode ()
		   (setq rasterop pix_clr)
		   )
  (:set-show-mode () (setq rasterop pix_src))
  (:buffer-mode (&optional (v buffer-mode)) (setq buffer-mode v))
  (:clear
   ()
   (let ((width (send self :width)) (height (send self :height))
	 (pixwin (if buffer-mode back-pixwindow pixwindow)))
     (pw_writebackground pixwindow 0 0 width height pix_clr)
;;;     (pr_rop pixwin 0 0 width height pix_src 0 0 0)
     ))
  ;;(pw_writebackground pixwindow 0 0 width height pix_clr)
  ;;(pw_write (canvas_pixwin canvas) 0 0 width height pix_src 0 0 0)
  (:flush
   ()
   (when buffer-mode
	 (pw_rop pixwindow 0 0 (send self :width) (send self :height)
		 pix_src back-pixwindow 0 0)
	 (pw_batch_off pixwindow)
	 )
   t)
  (:drawline-primitive
   (x0 y0 x1 y1 &optional (c color)) ;; x0 y0 x1 y1
   (if (null c) (setq c color))
   (if buffer-mode
       (pr_vector back-pixwindow x0 y0 x1 y1 rasterop c)
     (pw_vector pixwindow x0 y0 x1 y1 rasterop c)))
  (:draw-line (p1 p2 &optional color)
     (send self :drawline-primitive
		(round (aref p1 0)) (round (aref p1 1))
		(round (aref p2 0)) (round (aref p2 1)) color))
  (:drawtext-primitive
   (textstring x0 y0 &key (font 0) (op rasterop)
	       (pixwin (if buffer-mode back-pixwindow pixwindow)))
   (pr_text pixwin x0 y0 rasterop font
	    (string-body-address textstring)))
  (:drawpolygon-primitive
   (points &key (op pix_set)
	   (x 0) (y 0)
	   (pixwin (if buffer-mode back-pixwindow pixwindow))
	   (rect 0) (sx 0) (sy 0))
   (pw_polygon_2 pixwin x y 1 (vector (length points))
		 points op rect sx sy))
  (:drawpolyline-primitive
   (points &key (op pix_set)
	   (pixwin (if buffer-mode back-pixwindow pixwindow))
	   (x 0) (y 0)
	   (mvlist 0) (brush 0) (texture 0))
   (pw_polyline pixwin x y
		(length points) points mvlist brush texture op))
  )

(defun geometry::default-viewsurface (&rest args)
    (send-lexpr (instantiate canvas-viewsurface) :init
		args))
