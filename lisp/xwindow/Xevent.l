;;;;
;;;; Xwindow event handling
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1993
;;;;
;;; @(#)Xevent.l	1.2 25 Jan 1995

(in-package "X")

(require :Xdecl "Xdecl.l")

(export '(font-id
	  next-event
	  event event-type event-pos event-window event-state
	  event-time event-root-pos event-key event-button
	  event-x-root event-y-root
	  event-x event-y event-width event-height
	  event-shift event-control event-meta
	  event-left event-middle event-right event-pressed
	  display-events window-main-loop window-main-thread wml
	  *buttonRelease-wanted*
	  *xevent-debug*))


(defparameter *xevent-debug* nil)

;;/* Input Event Masks. Used as event-mask window attribute and as arguments
;;   to Grab requests.  Not to be confused with event names.  */

;; 
;; /* Event names.  Used in "type" field in XEvent structures.  Not to be
;; confused with event masks above.  They start from 2 because 0 and 1
;; are reserved in the protocol for errors and replies. */
;; 
;; #define KeyPress		2
;; #define KeyRelease		3
;; #define ButtonPress		4
;; #define ButtonRelease		5
;; #define MotionNotify		6
;; #define EnterNotify		7
;; #define LeaveNotify		8
;; #define FocusIn			9
;; #define FocusOut		10
;; #define KeymapNotify		11
;; #define Expose			12
;; #define GraphicsExpose		13
;; #define NoExpose		14
;; #define VisibilityNotify	15
;; #define CreateNotify		16
;; #define DestroyNotify		17
;; #define UnmapNotify		18
;; #define MapNotify		19
;; #define MapRequest		20
;; #define ReparentNotify		21
;; #define ConfigureNotify		22
;; #define ConfigureRequest	23
;; #define GravityNotify		24
;; #define ResizeRequest		25
;; #define CirculateNotify		26
;; #define CirculateRequest	27
;; #define PropertyNotify		28
;; #define SelectionClear		29
;; #define SelectionRequest	30
;; #define SelectionNotify		31
;; #define ColormapNotify		32
;; #define ClientMessage		33
;; #define MappingNotify		34
;; #define LASTEvent		35	/* must be bigger than any event # */
;; 
;; typedef struct {
;; 	int type;		/* of event */
;; 	unsigned long serial;	/* # of last request processed by server */
;; 	Bool send_event;	/* true if this came from a SendEvent request */
;; 	Display *display;	/* Display the event was read from */
;; 	Window window;	        /* "event" window reported relative to */
;; 	Window root;	        /* root window that the event occured on */
;; 	Window subwindow;	/* child window */
;; 	Time time;		/* milliseconds */
;; 	int x, y;		/* pointer x, y coordinates in event window */
;; 	int x_root, y_root;	/* coordinates relative to root */
;; 	unsigned int state;	/* key or button mask */
;; 	char is_hint;		/* detail */
;; 	Bool same_screen;	/* same screen flag */
;; } XMotionEvent;


;;; event processing

(defcstruct XEvent
    (type		:integer)	;0
    (serial		:long)		;1
    (send-event		:integer)	;2
    (display		:long)		;3
    (window		:long)		;4
    (root		:long)		;5
    (subwindow		:long)		;6
#-:alpha
    (time		:long)		;7
#+:alpha
    (time		:integer)	;7
    (x			:integer)	;8
    (y			:integer)	;9
    (x-root		:integer)	;10
    (y-root		:integer)	;11
    (state		:integer)	;12
    (detail		:integer)		;13
    (same-screen	:integer)	;14
    (focus		:integer)	;15
    (alt-state		:integer)	;16
#-(or :alpha :irix6 :x86_64 :aarch64)
    (pad		:char 28)	;xevent is required to hold 24 longs
#+:irix6
    (pad		:char 84)
#+:alpha
    (pad		:char 88)
#+(or :x86_64 :aarch64)
    (pad		:char 92)      ;xevent is required to hold xx longs at x86-64
)

(defparameter event (instantiate XEvent))
(defparameter event2 (instantiate XEvent))

(defun next-event ()
  (cond ((> (Pending *display*) 0) (NextEvent *display* event) event)))

(defun event-type (e)
   (elt #(0 1		; 0 and 1 for errors and replies
		:KeyPress	;2
		:KeyRelease	;3
		:ButtonPress	;4
		:ButtonRelease	;5
		:MotionNotify	;6
		:EnterNotify	;7
		:LeaveNotify	;8
		:FocusIn	;9
		:FocusOut	;10
		:KeymapNotify	;11
		:Expose		;12
		:GraphicsExpose	;13
		:NoExpose	;14
		:VisibilityNotify	;15
		:CreateNotify	;16
		:DestroyNotify	;17
		:UnmapNotify	;18
		:MapNotify	;19
		:MapRequest	;20
		:ReparentNotify	;21
		:ConfigureNotify	;22
		:ConfigureRequest	;23
		:GravityNotify	;24
		:ResizeRequest	;25
		:CirculateNotify	;26
		:CirculateRequest	;27
		:PropertyNotify	;28
		:SelectionClear	;29
		:SelectionRequest	;30
		:SelectionNotify	;31
		:ColormapNotify	;32
		:ClientMessage	;33
		:MappingNotify	;34
		:LASTEvent	;35
		)
	  (XEvent-type e)))

;(defmacro event-x (e) `(aref ,e 8))
;(defmacro event-y (e) `(aref ,e 9))

(defun event-x (e) (XEvent-x e))
(defun event-y (e) (XEvent-y e))

(defun event-x-root (e) (XEvent-x-root e))
(defun event-y-root (e) (XEvent-y-root e))

(defun event-pos (e)
    (integer-vector (XEvent-x e) (XEvent-y e)))

(defun event-key (e) (XEvent-detail e))

(defun event-root-pos (e)
    (integer-vector (XEvent-x-root e) (XEvent-y-root e)))

#-(or :x86_64 :aarch64)
(defun event-width (e) (XEvent-x e))
#-(or :x86_64 :aarch64)
(defun event-height (e) (XEvent-y e))
#+(or :x86_64 :aarch64)
(defun event-width (e) (sys::peek ;; for width of XConfigureEvent
                        (+ (sys::address e) 16 (* 4 14)) :integer))
#+(or :x86_64 :aarch64)
(defun event-height (e) (sys::peek  ;; for height of XConfigureEvent
                         (+ (sys::address e) 16 (* 4 15)) :integer))

(defun event-time (e) (XEvent-time e))

(defun event-window (e)
   (gethash (XEvent-window e) *xwindows-hash-tab*))

;; Strangely, ButtonPress event does not set the state member,
;; which is set by MotionNotify and ButtonRelease as expected.
;; Instead, ButtonPress sets the detail member with the button
;; number, which does not correspond to the event mask.

(defun event-button (e) (XEvent-detail e)) ; 1-left, 2-middle, 3-right
(defun event-state (e)
   (let ((bits (XEvent-state e)) (r nil))
	(if (logtest bits 3) (push :shift r))
	(if (logtest bits 4) (push :control r))
	(if (logtest bits 8) (push :meta r))
	(if (logtest bits 256) (push :left r))
	(if (logtest bits 512) (push :middle r))
	(if (logtest bits 1024)  (push :right r))
        r))

(defun event-shift (e)  (logtest (XEvent-state e) 3))
(defun event-control (e)  (logtest (XEvent-state e) 4))
(defun event-meta (e)  (logtest (XEvent-state e) 8))
(defun event-left (e)  (logtest (XEvent-state e) #x100))
(defun event-middle (e)  (logtest (XEvent-state e) #x200))
(defun event-right (e)  (logtest (XEvent-state e) #x400))
(defun event-pressed (e &optional alt)
 "returns T if any key is pressed. In EnterNotify, see the 16th element
instead of 12th of motoinNotify events."
     (logtest (if alt (XEvent-alt-state e) (Xevent-state e)) #x700) )

(defun print-event (event)
    (format t ";#~d ~a ~A ~A stat=~s ~d key=~d time=~6,1f~%"
                (XEvent-serial event)
                (event-type event)
                (send (event-window event) :name)
                (event-pos event)
                (event-state event)
		(XEvent-state event)
                (Event-key event)
		(/ (XEvent-time event) 1000.0)
                ))

(defun display-events ()
    (sync *display* 1)
    (while t 
	(NextEvent *display* event)
	(print-event event)
	(if (and (eql (event-type event) :keyrelease)
		 (eql (event-key event) 103))	;; end key?
	    (return-from display-events nil))
	)
	)

#|
(defun get-rectangle (w)
   (let ((wid (send w :drawable)) press release width height)
      (sync *display* 0)	; ignore pending events
      (send w :selectinput '(:button :motion))
      (windowevent *display* wid 4 event)
      (setq press (event-pos event) release (event-pos event))
      (send w :function :xor)
      (while (progn
		(windowevent *display* wid
			 (logior buttonreleasemask buttonmotionmask)
			 event)
		(eql (event-type event) :motionnotify))
	 (send w :draw-rectangle press
			 (- (aref release 0) (aref press 0))
			 (- (aref release 1) (aref press 1)))
	 (setq release (event-pos event))
	 (send w :draw-rectangle press
			(- (aref release 0) (aref press 0))
			(- (aref release 1) (aref press 1))))
      (setq release (event-pos event))
      ;; (draw-rectangle press release)
      (list press release)) )
|#




(defparameter charbuf (make-string 3))

(defmethod xwindow
 (:event-notify-print (type event) (format t ";event ~s ~s~%" type event))
 (:event-notify-dispatch (type event)    (send self type event))
 (:event-notify (type event)
    (cond (event-forward (send event-forward :event-notify type event))
	  ((member type
		 '(:configureNotify
		   :configureRequest
		   :expose
		   :visibilityNotify))
	       (send self :event-notify-dispatch type event))
	  ((member type '(
			:KeyPress	;2
			:KeyRelease	;3
			:ButtonPress	;4
			:ButtonRelease	;5
			:MotionNotify	;6
			:EnterNotify	;7
			:LeaveNotify	;8
			:ConfigureNotify
			:VisibilityNotify
			:expose
			))
	  ;; the following three lines are needed by menu-button-item
	  ;; to unmap menu-panel even button is released somewhere outside
	  ;; the menu-button-item or menu-panel.
	  ;; this process must proceed the true :event-notify-dispatch
	  ;; to successfully unmap menu panel even "quit" item is selected
	  ;; to terminate window-main-loop.  Otherwise, the menu panel
	  ;; floats without active event-handler.
	  (if (and (eq type :ButtonRelease)
		   (derivedp *ButtonRelease-wanted* xwindow))
	      (send *buttonRelease-wanted* :buttonRelease event))
          (send self :event-notify-dispatch type event)
	   ;; if you want to see all spurious notifications,
	   ;; enable the following line.
	   #| (send self :event-notify-print type event) |#
	  )))
; (:KeyPress (event)
;	 (if *debug* (warn "subclass's responsibility ~s~%" :KeyPress )))
 (:KeyRelease (event)
	(if *debug* (warn "subclass's responsibility ~s~%" :KeyRelease )))
 (:KeyPress (event)
     (if (= (LookupString event charbuf 1 0 0) 1)
	 (send self :keyEnter (char charbuf 0) event)))
 (:KeyEnter (ch &optional event)
	(if *debug* (warn "subclass's responsibility ~s~%" :KeyEnter )))
 (:ButtonPress (event) 
	(when *debug* (warn "subclass's responsibility ~s~%" :ButtonPress )
		(print (event-state event))))
 (:ButtonRelease (event)
        (if *debug* (warn "subclass's responsibility ~s~%" :ButtonRelease )))
 (:MotionNotify (event)
	(if *debug*  (warn "subclass's responsibility ~s~%" :MotionNotify )))
 (:EnterNotify (event)
    (if *debug* (warn "subclass's responsibility ~s~%" :EnterNotify )))
 (:LeaveNotify (event)
    (if *debug* (warn "subclass's responsibility ~s~%" :LeaveNotify )))
 (:configureNotify(event)
   (if *debug* (warn "ConfigureNotify came to ~S~%" self))
   (let ((newwidth (send self :width)) 
	 (newheight (send self :height)))
	(when t (or (/= newwidth width) (/= newheight height))
	  (setq width newwidth height newheight)
	  (send self :redraw))))
 (:configureRequest (event)
	(warn ":configureRequest sent to ~s~%" self))
 (:expose (event)  (send self :redraw))
 (:visibilityNotify (event) nil)	;ignore
 (:redraw () 
	(warn ":redraw is subclass's responsibility ~s~%" self))
 )



;; window-main-loop

(defun process-event (event)
   (let ((win (event-window event))
	 (type (event-type event)))
      (if *debug* (print-event event))
      (when (derivedp win xwindow)
	  (send win :event-notify type event)
	)
   ) 
)

(defparameter *skipped-event-count* 0)
(defparameter *skip-motion-event* T)


;; window-main-one is invoked each time an Xevent is reported via
;; *top-selector*.  This function is registered to *top-selector*
;; when the display connection is made.

(defun window-main-one (&optional fd)
  (catch :window-main-loop
      (while (> (EventsQueued *display* 1) 0)
	   (NextEvent *display* event)
	   (if *xevent-debug* (print-event event)) 
	   (when (and *skip-motion-event*
		     (eql (event-type event) :motionNotify))
		(while
		    (and (> (Pending *display*) 0)
			 (progn (PeekEvent *display* event2)
				(eql (event-type event2) :motionNotify)))
		    ;ignore the previous event
		    (nextEvent *display* event)
		    (incf *skipped-event-count*)) )
	   (process-event event))
	(xflush))
   )

(defmacro window-main-loop (&rest forms)
   (if (null forms)
	`(progn
	   (sync *display* 1)
	   (catch :window-main-loop
		(while t   (window-main-one) )
	   (sync *display* 1)
	   (xflush)))
	`(progn
	   (sync *display* 1)
	   (catch :window-main-loop
		(while t
		   (cond ((> (Pending *display*) 0)	; QueuedAlready
				;;    (eventsqueued *display* 1) ??
			  (NextEvent *display* event)
			   ;;(print event)
			  (process-event event))
			 (t . ,forms))))
	   (sync *display* 1)
	   (xflush)) ))

(defmacro wml (&rest forms) `(window-main-loop . ,forms))

(defun wmlerror (code msg1 form &optional (msg2))
#+(or :solaris2 :SunOS4.1 :pthread)
   (format *error-output* "~A ~d error: ~A" *program-name*
		(unix::thr-self) msg1)	; thr-self is in unix pkg
#-(or :solaris2 :SunOS4.1 :pthread)
   (format *error-output* "~A error: ~A" *program-name* msg1)
   (if msg2 (format *error-output* " ~A" msg2))
   (if form (format *error-output* " in ~s" form))
   (terpri *error-output*)
   (throw :window-main-loop-again nil))

#+(or :Solaris2 :SunOS4.1 :pthread)
(progn
  (defun window-main-thread2 ()
     (let ((num-events 0))
       (lisp::install-error-handler  #'wmlerror)
       (sync *display* 1)
       (catch :window-main-loop
          (while t
            (catch :window-main-loop-again
              (NextEvent *display* event)
              (if *debug* (print-event event))
	      (incf num-events)
              (process-event event))))
       (warn "window-main-loop finished: ~d events caught~%" num-events)
       (sync *display* 1)
       (xflush)))

  (defun window-main-thread ()
     (sys::thread-no-wait #'window-main-thread2)))

#-(or :alpha :irix6 :x86_64 :aarch64)
(defun display-fd (&optional (disp *display*))
   (if disp
       (sys:peek (+ disp 8) :long)))
#+(or :alpha :irix6 :x86_64 :aarch64)
(defun display-fd (&optional (disp *display*))
   (if disp
       (sys:peek (+ disp 16) :integer)))

(defvar repwin-timeout 0)

(defun repwin ()
  (let ((xfd  (display-fd))
	(active-stream)
	(next-prompt t))
     (while t 
	(when next-prompt
	   ;; (toplevel-prompt *standard-output*)
	   (format *standard-output* "> ")
	   (finish-output *standard-output*))
	(setq next-prompt nil)
	(setq active-stream
		(select-stream (list *standard-input* xfd) 10.0) )
	(cond ((eql (car active-stream) *standard-input*)
		(print (eval  (read *standard-input*)))
		(setq next-prompt t))
	      ((eql (car active-stream) xfd)
		(window-main-one))
	      (t (incf repwin-timeout)))
	)) )

(provide :Xevent "@(#)$Id$")

