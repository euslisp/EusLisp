;;;;
;;;; Xwindow pixmap functions
;;;;	
;;;;	Copyright(c) Isao Hara, ETL, 1993
;;;;


(in-package "X")
(require :Xdecl	"Xdecl.l")

(export '(*shell-window* *eustop-window* eustop-win))
(defvar *shell-window*)
(defvar *eustop-window*)

(defparameter *gray* "#b0b0b0")
(defparameter *bisque1* "#ffe4c4")
(defparameter *bisque2* "#eed5b7")
(defparameter *bisque3* "#cdb79e")
(defparameter *lightblue2* "#b2dfee")
(defparameter *lightpink1* "#ffaeb9")
(defparameter *maroon* "#b03060")
(defparameter *max-intensity* 65535)



;;
;; *EUSTOP-WINDOW*
;; (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory

(defclass eustop-history-window :super x:textwindow)

(defmethod eustop-history-window
 (:ButtonPress (event)
    (send self :cursor :off))
 (:ButtonRelease (event)
    (let ((row (send self :event-row event))
	  (col (send self :event-col event))
	  (button (event-button event)))	; left=1, middle=2, right=3
       (send parent :select row button)))
 )


(defclass eustop-win :super x:panel
		:slots (euspan	gcpan 	contained  attach-button
			history-win last-history history-list
			result-history-win tick))
(defmethod eustop-win
 (:create (&rest args) 
    (let ((shell-w (send *shell-window* :width))
	  (shell-h (send *shell-window* :height)))
       (setq last-history 0
	     history-list nil
	     tick 0)
       (send-super* :create :width shell-w :height 200
		:event-mask '(:configure)
		:font x:font-cour10
		:title (format nil "eustop ~d" (unix:getpid)) args)
       (setq euspan (instance x:panel :create
		:width (- width 300) :height 143
		:parent self :x 0 :y 0
		:font x:font-courb12 ))
       (setq result-history-win (instance textwindow :create
		:parent self
		:width (- width 300) :height 34
		:x 0  :y 145))	
       (setq gcpan (instance x:textwindow :create :parent self
		:width (- width 300) :height 16
		:x 0 :y 181))
       (setq history-win (instance eustop-history-window :create
		:parent self
		:width 300 :height 197
		:x (- width 300)   :y 0))
       (setq attach-button
          (send euspan :create-item x:button-item "attach" self :attach))
       (send euspan :create-item x:button-item "FilePanel" self :filepanel)
       (send euspan :create-item x:button-item "history" self :refresh-history)
       (send euspan :create-item x:button-item "exit" self :exit)
       (send euspan :create-item x:button-item "alloc" self :alloc)
       (send euspan :create-item x:slider-item "interval" self :interval
		:min 0.1 :max 5
		:value-format "~3,1f")
       ;; (send euspan :create-item x:button-item "detach" self :detach)
       )
    self)
 (:attach (e)
    (if contained
	(send self :detach e)
        (let ((shell-w (send *shell-window* :width))
	      (shell-h (send *shell-window* :height)))
       	   (send self :resize (+ shell-w 2) (+ shell-h 200))
           (send *shell-window* :reparent self 0 200)
	   (send attach-button :label "detach")
	   (setq contained t)	)) )
 (:detach (e)
    (send *shell-window* :reparent  x:*root* 100 100)
    (send self :resize 400 200)
    (send attach-button :label "attach")
    (setq contained nil)
    (xflush))
 (:filepanel (e) (instance x:filepanel :create))
 (:refresh-history (e)
   (let ((h)
	 (rows (send history-win :win-row-max))
	 (cols (send history-win :win-col-max)))
     (send history-win :clear)
     (dolist (x history-list)
	(when (consp x)
	    (send history-win :put-line (decf rows) 0
		  (subseq (format nil "~2d: ~A~%" (car x) (cadr x))
		  	  0 cols))
	    ))
     (xflush)
     )
   )
 (:update-history ()
   (let ((h (elt *history* *history-index*))
 	 (cols (send history-win :win-col-max))
	 (rows (send history-win :win-row-max)))
      (when (and (consp h) (not (eq last-history (car h))))
	  (setq last-history (car h))
	  (push h history-list)
	  (setq history-list (subseq history-list 0 rows))
	  (send history-win :scroll)
	  (send history-win :put-line 
		(1- rows) 0
		(subseq (format nil "~2d: ~A~%" (car h) (cadr h))
		  	  0 cols))
	   )
       (send result-history-win :clear)	
       (send result-history-win :put-line 0 0
	     (subseq (format nil "****=~s" ***) 0 cols))
       (send result-history-win :put-line 1 0
	     (subseq (format nil "*** =~s" **) 0 cols))
       (send result-history-win :put-line 2 0
	     (subseq (format nil "**  =~s" *) 0 cols))
       (xflush))
       ;; (send (send history-stream :outstream) :flush)	
   )
 (:update-gc (free total)
    (let ((gctime (sys:gctime)))
	(send gcpan :clear-lines 0 0)
	(send gcpan :put-line 0 1
	   (format nil
		"GC ~4d: (~s+~s)/~ss, ~sKB/~sKB"
		(car gctime) (/ (second gctime) 100.0) (/ (third gctime) 100.0)
		(/ (unix:runtime) 100.0)
		(/ free 256) (/ total 256)))
	(xflush)
	))
 (:configurenotify (event)
   (let ((newwidth (send self :width)) 
	 (newheight (send self :height)))
	(when (and contained (or (/= newwidth width) (/= newheight height)))
	  (send *shell-window* :resize (- newwidth 2) (- newheight 201)))
	  ) )
 (:select (n button) 
   (let* ((rows (send history-win :win-row-max))
	  (history-string (get-history (car (nth (- rows n 1) history-list))))
	  (edited-string history-string))
      (case button
	(1  (setq edited-string (line-edit history-string)))
	    (terpri))
      (cond (edited-string
		     (add-history  edited-string)
		     (send self :update-history)
		     (print
		        (evaluate-stream
			   (make-string-input-stream edited-string)) ))
		   (t nil)) )
      )
 )

(defmethod eustop-win
 (:alloc (x) (sys:alloc 16384) (sys::gc))
 (:exit (x) (unix::exit))
 (:interval (x interval)
    (setq *top-selector-interval* interval)
    ;; (print *top-selector-interval*)
    )
 (:time-tick (&rest x)
    ;; (print tick)
    (incf tick)
    (if (oddp tick)
	(send gcpan :image-string 1 10 "*")
	(send gcpan :image-string 1 10 " "))
    (xflush))
 )
    

(defun eustop-win-time-tick () (send *eustop-window* :time-tick))
(defun eustop-update-history () (send *eustop-window* :update-history))
(defun eustop-update-gc (free total)
   (send *eustop-window* :update-gc free total))
(defun eustop-exit ()
   (send *eustop-window* :detach nil))
(defun eustop-win ()
   (setq *eustop-window* (instance eustop-win :create))
   (setq *toplevel-hook* 'eustop-update-history)
   (setq sys::*gc-hook* 'eustop-update-gc)
   (setq sys::*exit-hook* 'eustop-exit)
   (send *eustop-window* :update-gc 0 0)
   (pushnew 'eustop-win-time-tick *timer-job*)
   *eustop-window*)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun init-xwindow (&optional (display (unix:getenv "DISPLAY")))
 (cond ((not (zerop (setq *display* (OpenDisplay display))))
	(if (unix:isatty *standard-input*)
	    (warn "connected to Xserver DISPLAY=~A~%"
	    	 (unix:getenv "DISPLAY")))
	;; load default fonts
	(setq font-cour8   (font-id "*-courier-medium-r-*-8-*"))
	(setq font-cour10  (font-id "*-courier-medium-r-*-10-*"))
	(setq font-cour12  (font-id "*-courier-medium-r-*-12-*"))
	(setq font-cour14  (font-id "*-courier-medium-r-*-14-*"))
	(setq font-cour18  (font-id "*-courier-medium-r-*-18-*"))
	(setq font-courb12 (font-id "*-courier-bold-r-*-12-*"))
	(setq font-courb14 (font-id "*-courier-bold-r-*-14-*"))
	(setq font-courb18 (font-id "*-courier-bold-r-*-18-*"))
	(setq font-courb24 (font-id "*-courier-bold-r-*-24-*"))
	(setq font-times10 (font-id "*-times-medium-r-*-10-*"))
	(setq font-times12 (font-id "*-times-medium-r-*-12-*"))
	(setq font-timesb12 (font-id "*-times-bold-r-*-12-*"))
	(setq font-timesb14 (font-id "*-times-bold-r-*-14-*"))
	(setq font-timesb18 (font-id "*-times-bold-r-*-18-*"))
	(setq font-timesb24 (font-id "*-times-bold-r-*-24-*"))
	(setq font-lucidasans-bold-12 (font-id "lucidasans-bold-12"))
	(setq font-lucidasans-bold-14 (font-id "lucidasans-bold-14"))
	(setq font-helvetica-bold-12 (font-id "*-Helvetica-Bold-R-Normal-*-12-*"))
	(setq font-helvetica-12 (font-id "*-Helvetica-Medium-R-Normal-*-12-*"))
	(setq font-a14 (font-id "*-fixed-medium-r-normal-*-14-*"))

	(when (zerop font-cour12)  ;; this is default gc
	  (setq *display* 0)
	  (warning-message 1 "~%Xserver connection failed due to missing font server, please try after computer restarts~%")
	  (return-from init-xwindow))

	(setq *screen-no* (defaultscreen *display*))
	(setq *screen* (defaultscreenofdisplay *display*))
	(setq *visual* (defaultvisualofscreen *screen*))
	(let ((visinfo (make-string 64)) vis)
	   ;; visual types
		;; 0 staticGray (readonly)
		;; 1 GrayScale (read-writeable)
		;; 2 StaticColor (readOnly)
		;; 3 PseudoColor (readWrite)
		;; 4 TrueColor (readOnly)
		;; 5 DirectColor (readWrite)
	   (if (not (eql (matchVisualInfo *display* *screen-no* 8 3 visinfo) 0))
		(push (list
			(setq *visual-pseudo-8* (sys:peek visinfo 0 :long))
			8) *visuals*))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 8 4 visinfo) 0))
		(push (list
			 (setq *visual-true-8* (sys:peek visinfo 0 :long))
			 8) *visuals*))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 8 5 visinfo) 0))
		(push (list
			 (setq *visual-direct-8* (sys:peek visinfo 0 :long))
			  8) *visuals*))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 15 4 visinfo) 0))
		(push (list 
			(setq *visual-true-15* (sys:peek visinfo 0 :long))
			15) *visuals*))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 15 5 visinfo) 0))
		(push (list
			(setq *visual-direct-15* (sys:peek visinfo 0 :long))
			15) *visuals*))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 16 4 visinfo) 0))
		(push (list
			(setq *visual-true-16* (sys:peek visinfo 0 :long))
			16) *visuals* ))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 16 5 visinfo) 0))
		(push (list
			(setq *visual-direct-16* (sys:peek visinfo 0 :long))
			16) *visuals* ))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 24 4 visinfo) 0))
		(push (list
			(setq *visual-true-24* (sys:peek visinfo 0 :long))
			24) *visuals*))
	   (if (not (eql (matchVisualInfo *display* *screen-no* 24 5 visinfo) 0))
		(push (list
			(setq *visual-direct-24* (sys:peek visinfo 0 :long))
			24) *visuals*)) 
	   )

        (setq *save-under* (/= (doessaveunders *screen*) 0))
	(setq *depth* (defaultdepth *display* 0))
	(setq *whitepixel*
		 (whitepixel *display* (defaultscreen *display*)))
	(setq *blackpixel*
		      (blackpixel *display* (defaultscreen *display*)))
	(setq *fg-pixel* *blackpixel*)
	(setq *bg-pixel* *whitepixel*)
	(setq *defaultGC*
		(instance gcontext :create :font font-cour12
		))
	(send *defaultGC* :foreground *fg-pixel*)
        (send *defaultGC* :background *bg-pixel*)
	(setq *Root* (instance Xwindow :init 
				(defaultrootwindow *display*)
				nil nil *defaultGC*))
	(if (unix:getenv "WINDOWID")
	    (setq *shell-window*
		(instance Xwindow :init 
			(read-from-string (unix:getenv "WINDOWID"))
				nil nil *defaultGC*))	    )
	(setf (xwindow-bg-color *root*) *bg-pixel*)
	(setq *whitegc* (instance gcontext :create))
	(send *whitegc* :foreback *whitepixel* *blackpixel*)
	(setq *blackgc* (instance gcontext :create))
	(send *blackgc* :foreback *blackpixel* *whitepixel*)
	   ;; create default color map
	(setq *color-map*
		 (instance colormap :init
	             (defaultcolormap *display* (defaultscreen *display*))))
	(send *color-map* :name '*color-map*)
	(send *root* :set-colormap *color-map*)
	;;
	;; Ximage
	   (setq *default-ximage* (create-ximage "" :depth *depth*))
	;;
	;; gray gc
	(setq *gray-gc* (make-gray-gc 0.5))
	(setq *gray-pixmap* (make-gray-pixmap 0.5))
	(setq *gray25-pixmap* (make-gray-pixmap 0.25))
	(setq *gray50-pixmap* (make-gray-pixmap 0.50))
	(setq *gray75-pixmap* (make-gray-pixmap 0.75))
	(setq *gray25-gc* (make-gc-from-pixmap  *gray25-pixmap*))
	(setq *gray50-gc* (make-gc-from-pixmap  *gray50-pixmap*))
	(setq *gray75-gc* (make-gc-from-pixmap  *gray75-pixmap*))

	;; initialization finished
	(when lisp::*use-top-selector*
	   (send *top-selector* :add-port (display-fd) #'window-main-one)
	   (if (unix:isatty *standard-input*)
	       (warn "X events are being asynchronously monitored.~%")))
	)
       (t (warning-message 1 "Xserver connection failed"))))


#|
;;; JUNK for gray-pixmap handling

(let ((gray25-data
		 '(#x00 #x00 #x22 #x22 #x00 #x00 #x88 #x88
		   #x00 #x00 #x22 #x22 #x00 #x00 #x88 #x88
		   #x00 #x00 #x22 #x22 #x00 #x00 #x88 #x88
		   #x00 #x00 #x22 #x22 #x00 #x00 #x88 #x88))
	(gray50-data
		 '(#x55 #x55 #xaa #xaa #x55 #x55 #xaa #xaa
		   #x55 #x55 #xaa #xaa #x55 #x55 #xaa #xaa
		   #x55 #x55 #xaa #xaa #x55 #x55 #xaa #xaa
	   	   #x55 #x55 #xaa #xaa #x55 #x55 #xaa #xaa)))
	;;
	(setq *gray25-pixmap* 
		(make-pixmap-from-data 16 16 gray25-data))
	(setq *gray50-pixmap*
		(make-pixmap-from-data 16 16 gray50-data))
	(setq *gray75-pixmap*
		(make-pixmap-from-data 16 16 gray25-data
			:foreground *bg-pixel* :background *fg-pixel*))
	(setq *gray25-bitmap*
		(make-pixmap-from-data 16 16 gray25-data :depth 1))
	(setq *gray50-bitmap*
		(make-pixmap-from-data 16 16 gray50-data :depth 1))
	(setq *gray75-bitmap*
		(make-pixmap-from-data 16 16 gray25-data
			:foreground *bg-pixel* :background *fg-pixel*
			:depth 1))

(defun make-pixmap-from-data (width height data
		 &key (foreground *fg-pixel*)
			(background *bg-pixel*)
			(depth (defaultdepth *display* 0)))
  ;; To make bitmap, set depth to 1 
  (let* ((bitmap_bit (instantiate string (length data)))
	 pixmap bitmap gcon)
     (send bitmap_bit :set data 0 :byte)
     (setq pixmap
	 (instance xpixmap :create :width width :height height :depth depth))
     (setq bitmap (CreatePixmapFromBitmapData *display* 
		(DefaultRootWindow *display*) bitmap_bit width height 
		foreground background depth))
     (Flush *display*)
     (setq (pixmap . drawable) bitmap)
   pixmap
  )
)

#|
(defun make-bitmap-from-data (width height data
			 &key (foreground *fg-pixel*) (background *bg-pixel*))
  (let ((bitmap_bit (instantiate string (length data))) pixmap bitmap gcon)
     (send  bitmap_bit  :set data 0 :byte)
     (setq pixmap (instance xpixmap :create :width width :height height
			:depth 1))
     (setq bitmap (CreatePixmapFromBitmapData *display* 
		(DefaultRootWindow *display*) bitmap_bit width height 
		foreground background 1))
     (flush *display*)
     (setq (pixmap . drawable) bitmap)
   pixmap
  )
)
|#

|#


(provide :Xtop "@(#)$Id: Xtop.l,v 1.1.1.1 2003/11/20 07:46:36 eus Exp $")
