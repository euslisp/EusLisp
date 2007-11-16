;;;;
;;;; Xwindow text and  key facilities
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1993
;;;;
(list "@(#)$Id$")

(in-package "X")
(require :xdecl   "Xdecl.l")
(eval-when (compile eval) (require :xtop    "Xtop"))

(export '(make-textwindow-stream))

(defclass textEdit :super textwindow
	:slots (total-lines lines))

(defmethod CharacterWindow
 (:create (&rest args
	   &key (width 256) (height 256) (font) rows columns
		(event-mask '(:key :button :enterleave))
		(parent *root*)
	   &allow-other-keys)
    (setq fontid
	  (cond ((stringp font) (font-id font))
		((numberp font) font)
		((and (not (eql parent *root*))
		      (derivedp parent xwindow))
		 (send parent :font))
		(t font-courb12))) 
    (let ((dots (textdots "X" fontid)))
       (setq charheight (+ (elt dots 0) (elt dots 1))
	     charwidth (elt dots 2)
	     charascent (elt dots 0)))
    (cond (columns  (setf width (+ 4 (* charwidth columns)) ))
	  (width    (setq columns (/ (- width 4) charwidth))))
    (cond (rows     (setf height (+ 4 (* charheight rows))) )
	  (height   (setq rows (/ (- height 4) charheight))))
    (setf win-row-max rows
	  win-col-max columns)
    (send-super* :create
		 :width width	:height height
		 :event-mask event-mask
		 :font font
		 :parent parent
		 args)
    (send gcon :font fontid)
    self)
 (:xy (&optional (r 0) (c 0))
    (setq x (+ 2 (* c charwidth))
	  y (+ 2 (* r charheight) charascent)))
 (:clear-lines (start count)
    (send self :clear-area :x 0 :y (+ 2 (* start charheight))
		:width width :height (* charheight count))
    count)
 (:put-line (row col str)
    (send self :xy row col)
    (send self :string x y str))
 )


(defmethod textWindow
 (:create (&rest args
	   &key width height rows columns
		(event-mask '(:key :button :enterleave))
		(show-cursor nil)
		(notify-object nil) (notify-method nil)
	   &allow-other-keys)
    (send-super* :create :event-mask event-mask args)
    (setq  charbuf (make-string 1))
    (send self :set-notify notify-object notify-method)
    (send self :show-cursor show-cursor)
    (setq cursor-on nil)
    (send gcon :font fontid)
    (send self :clear)
    (send self :cursor :on)
    self)
 (:set-notify (receiver method) 
    (setq notify-object receiver notify-method method) self)
 (:show-cursor (flag)
    (setq show-cursor flag)
    (send self :cursor (if cursor-on :on :off)))
 (:cursor (&optional (switch :toggle))
    (when (and show-cursor
		(or (eq switch :toggle)
		      (and (eq switch :on) (null cursor-on))
		      (and (eq switch :off) cursor-on)))
	(send gcon :function :xorreverse)
	;; (send gcon :function :copy)
	(send self :xy)
	(fillRectangle *display* drawable (gcontext-gcid gcon)
		 x (- y charascent)
		 2  charheight)
	(setq cursor-on (null cursor-on))
	(send gcon :function :copy)))
 (:win-row () win-row)
 (:win-col () win-col)
 (:win-row-max () win-row-max)
 (:win-col-max () win-col-max)
 )

;; internal screen control functions
;; cursor-display is not controlled

(defmethod textWindow
 (:xy (&optional (r win-row) (c win-col))
    (setq x (+ 2 (* c charwidth))
	  y (+ 2 (* r charheight) charascent)))
 (:goto (r c &optional (cursor :on))
    (send self :cursor :off)
    (setf win-row (min (1- win-row-max) (max r 0))
	  win-col (min (1- win-col-max) (max c 0)))
    (send self :cursor cursor))
 (:goback (&optional (csr :on))
    (send self :goto win-row (max 0 (1- win-col)) csr))
 (:advance (&optional (n 1))
    (incf win-col n)
    (incf win-row (/ win-col win-col-max))
    (setq win-col (mod win-col win-col-max))
    ;(if (>= win-row win-row-max) (setq win-row (1- win-row-max)))
    )
 (:scroll (&optional (n 1) &aux srcy desty erasey)
    (cond ((= n 0) (return-from :scroll nil))
	  ((> n 0) (setq srcy n desty 0 erasey (- win-row-max n)))
	  (t (setq srcy 0 desty (abs n) erasey 0)))
    (setq n (min win-row-max (abs n)))
    (CopyArea *display* drawable drawable (gcontext-gcid gcon)
                2 (+ 2 (* srcy charheight))	;source-x source-y
		width (* (- win-row-max n) charheight)
		2 (+ 2 (* desty charheight))	; dest-x dest-y
		)
    (ClearArea  *display* drawable
		2 (+ 2 (* erasey charheight))		; x, y
		width (* n charheight) 0)
    )
 (:horizontal-scroll (&optional (n 1) &aux srcx destx erasex)
    (cond ((= n 0) (return-from :horizontal-scroll nil))
	  ((> n 0) (setq srcx n destx 0 erasex (- win-col-max n)))
	  (t (setq srcx 0 destx (abs n) erasex 0)))
    (setq n (min win-col-max (abs n)))
    (CopyArea *display* drawable drawable (gcontext-gcid gcon)
                (+ 2 (* srcx charwidth)) 2	;source-x source-y
		(* (- win-col-max n) charwidth) height
		(+ 2 (* destx charwidth)) 2	; dest-x dest-y
		)
    (ClearArea  *display* drawable
		(+ 2 (* erasex charwidth)) 2		; x, y
		(* n charwidth) height 0)
    )
 (:newline ()
    (setq win-col 0  win-row (1+ win-row))
    (when (>= win-row win-row-max)
	(send self :scroll 1)
	(decf win-row))
    ))

;; external method of textWindow

(defmethod textWindow
 (:clear ()
    (send self :cursor :off)
    (send-super :clear)
    (setq win-row 0 win-col 0)
    (send self :cursor :on)
    self)
 (:clear-eol (&optional (r win-row) (c win-col) (csr :on))
    (send self :cursor :off)
    (send self :clear-area :x (+ 2 (* c charwidth)) :y (+ 2(* r charheight))
		:width (* charwidth (- win-col-max c)) :height charheight)
    (send self :cursor csr))
 (:clear-lines (lines &optional (r win-row))
    (send self :cursor :off)
    (send self :clear-area :x 0 :y (+ 2 (* r charheight))
		:width width :height (* charheight lines))
    (send self :cursor :on))
 (:clear-eos (&optional (r win-row) (c win-col))
    (send self :cursor :off)
    (send self :clear-eol r c)
    (send self :clear-area :x 0 :y (+ 2 (* (1+ r) charheight))
		:width width :height (* charheight (- win-row-max r 1)))
    (send self :cursor :on))
 (:clear-in-line (row scol ecol)
    (send self :clear-area 
		:x %(2 + charwidth * scol)  :y %(2 + charheight * row)
		:width %(charwidth * (ecol - scol)) :height charheight))
 (:clear-text-area (startrow startcol endrow endcol)
    (if  (= startrow endrow)
	 (send self :clear-in-line startrow startcol endcol)
	 (send self :clear-in-line startrow startcol win-col-max))
    (if  (< startrow (1- endrow))
	 (send self :clear-lines (- endrow startrow 1) (1+ startrow)))
    (if  (> endrow startrow)
	 (send self :clear-in-line endrow 0 endcol)))
 (:putch (ch)
    (send self :cursor :off)
    (case ch
	(#\newline (send self :newline))
	(#\tab (send self :goto win-row %(((win-col + 8) / 8)* 8)))
	(t
	   ;; (format t ":putch ~d~%" ch)
	    (send self :xy)
	    (setf (char charbuf 0) ch)
	    (send self :image-string x y charbuf)
	    (send self :advance 1)
	    (when (>= win-row win-row-max)
		(send self :scroll 1)
		(decf win-row))
	    ch) )
    (send self :cursor :on))
 (:putstring (str &optional (e (length str)))
    (declare (integer e))
    (let (col-left nl (s 0) ss ch)
       (declare (integer s ch col-left))
       (send self :cursor :off)
       (while (< s e)
	  (setq col-left (- win-col-max win-col)
		nl (position #\newline str :start s))
	  (setq ss (min (- win-col-max win-col) (if nl nl e)))
	  (send self :clear-eol win-row win-col :off)
	  (send self :xy)
	  (send self :string x y str s ss)
	  (send self :advance (- ss s))
	  (when nl (incf ss) (send self :newline))
	  (setq s ss))
        (send self :cursor :on)))
 (:insert (ch) (send self :putch ch))	; for self's :keyEnter
 )
   
(defmethod textwindow
 (:event-row (event) (/ (- (event-y event) 2) charheight))
 (:event-col (event) (/ (- (event-x event) 2) charwidth))
 (:ButtonPress (event)
    (send self :cursor :off))
 (:ButtonRelease (event)
    (send self :goto (send self :event-row event) (send self :event-col event)))
 (:resize (w h)
    (send-super :resize w h)
    (setq width w height h)
    (setq win-col-max (/ (- width 4) charwidth)
	  win-row-max (/ (- height 4) charheight) )
    (send self :goto win-row win-col))
 (:ConfigureNotify (event)
    (let ((newwidth (send self :width)) (newheight (send self :height)))
	(when (or (/= newwidth width) (/= newheight height))
	;;    (format t "~s newsize: ~s ~s~%"
	;;	self  (send self :width)  (send self :height))
	   (send self :resize newwidth newheight)
	))
  )
 )

;; event handlers and keyinput functions

(defmethod TextWindow
 (:echo (flag) (setq echo flag))
 (:getstring ()
    (prog1 (subseq keybuf 0 keycount) (setq keycount 0)))
 (:enterNotify (event)
    (when drawable 
       (SetInputFocus *display* drawable 1 0)
       (send self :cursor :on)))
 (:LeaveNotify (event)  (send self :cursor :off))
 (:keyrelease (event)    ;; (setinputfocus *display* drawable 1 0)
    )
 (:LineEnter (line &optional (len (length line)))
    (unless (eq line keybuf) (replace keybuf line :end2 len)))
 (:KeyEnter (ch &optional event)
    (send self :insert ch)
    (if (and (eql ch #\newline) notify-object notify-method)
        (send notify-object notify-method event)))
  )
 )

    
;; X:TextWindowStream

(defmethod textWindowStream
 (:fill () (send textwin :getstring))
 (:flush ()
   (dotimes (i count) (send textwin :putch (char buffer i)))
    ; (send textwin :putstring buffer count)
    (xflush)
    (setq count 0))
 (:init (xtext direction)
    (send-super :init direction 256)
    (setq textwin xtext)
    self))

(defun make-textWindow-stream (xwin)
  (make-two-way-stream (instance textwindowstream :init xwin :input)
			(instance textwindowstream :init xwin :output)))

;;; BufferTextWindow

(defun expand-tab (src &optional (offset 0))
   (declare (string src) (integer offset))
   (let ((tabcount (count #\tab src)) c (p 0) (q 0) dest)
      (declare (integer p q))
      (if (= tabcount 0)
	  src
	  (progn
	      (setq dest (make-string (+ (length src) (* tabcount 8))))
	      (dotimes (i (length src))
		 (setq c (char src i))
		 (cond ((eql c #\tab)
			(setq q (- 8 (mod (+ offset p) 8)))
			(fill dest #\space :start p :end (+ p q ))
			(incf p q))
		       (t (setf (char dest p) c) (incf p))))
	      (subseq dest 0 p)	))
))

(defmethod BufferTextWindow
 (:create (&rest args)
    (send-super* :create :event-mask '(:key :button :motion :enterLeave) args)
    self)
 (:redraw () (send self :refresh))
 (:clear ()
    (send-super :clear)
    (setq linebuf (make-array (list win-row-max) :fill-pointer t))
    (setq expbuf (make-array (list win-row-max) :fill-pointer t))
    self)
 (:refresh-line (&optional (r win-row) (c win-col))
    (send self :clear-eol r c :off)
    (send self :xy r c)
    (send self :image-string x y (aref expbuf r) c))
 (:refresh (&optional (start 0))
    (let ((rowsave win-row) (colsave win-col))
       (dotimes (i (- (length linebuf) start))
          (send self :refresh-line (+ i start) 0))
       (setq win-row rowsave win-col colsave)))
 (:refresh-in-line (row scol ecol)
    (unless (< row (length expbuf)) (return-from :refresh-in-line nil))
    (send self :xy row scol)
    (let ((line (aref expbuf row)))
       (setq ecol (min ecol (length line)))
       (send self :image-string x y line scol ecol)))
 (:refresh-lines (lines srow)
    (dotimes (i lines)
        (unless (< (+ srow i) (length expbuf)) (return))
	(send self :xy (+ srow i) 0)
        (send self :image-string x y (aref expbuf (+ srow i)))))
 (:refresh-area (startrow startcol endrow endcol)
    (if (or (> startrow endrow) (and (= startrow endrow) (> startcol endcol)))
	(psetq startrow endrow
	       startcol endcol
	       endrow startrow
	       endcol startcol))
    ; (send self :clear-text-area startrow startcol endrow endcol)
    (if  (= startrow endrow)
	 (send self :refresh-in-line startrow startcol endcol)
	 (send self :refresh-in-line startrow startcol win-col-max))
    (if  (< startrow (1- endrow))
	 (send self :refresh-lines (- endrow startrow 1) (1+ startrow)))
    (if  (> endrow startrow)
	 (send self :refresh-in-line endrow 0 endcol)))
 (:highlight (flag srow scol erow ecol)	;reverse draw the region
    (if flag (send gcon :reverse))
    (send self :refresh-area srow scol erow ecol)
    (if flag (send gcon :reverse)))
)

(defmethod BufferTextWindow
 (:goto (r c &optional (csr :on))
    (setq c 
	  (if (> (length linebuf) r)
	      (min (length (aref linebuf r))  c)
	      0))
    (send-super :goto r c csr))
 (:line (n) (if (< n (length linebuf)) (aref linebuf n) nil))
 (:lines () linebuf)
 (:nlines () (length linebuf))
 (:all-lines () linebuf)
 (:max-line-length ()
   (setq max-line-length (apply #'max 0 (map cons #'length expbuf))))
 (:read-file (fname)
    (with-open-file (f fname)
	(do* ((i 0 (1+ i))
	      (eof (cons nil nil))
	      (ln (read-line f nil eof) (read-line f nil eof)))
	     ((eq ln eof))
	  (vector-push-extend ln linebuf)
	  (vector-push-extend (expand-tab ln) expbuf)
	  ))
    (send self :max-line-length)
    (send self :refresh)
    t)
 (:display-line-string (string)
    (let (lines p (s 0) (running t))
      (while running
	 (setq p (position #\newline string :start s))
	 (cond ((null p) (push (subseq string s) lines) (setq running nil))
	       (t (push (subseq string s p) lines) (setq s (1+ p)))))
      (nreverse lines)
      (setq linebuf
	  (make-array (list (length lines))
		:initial-contents lines :fill-pointer t))
      (setq expbuf
	  (make-array (list (length lines))
		:initial-contents lines :fill-pointer t))
      (setq selected-pos nil)
      (send self :max-line-length)
      (send self :refresh))
    t)
 (:display-strings (strings)
    (setq linebuf
	  (make-array (list (length strings))
		:initial-contents strings :fill-pointer t))
    (setq expbuf
	  (make-array (list (length strings))
		:initial-contents strings :fill-pointer t))
    (dotimes (i (length strings))
	(setf (aref expbuf i) (expand-tab (aref expbuf i))))
    (setq selected-pos nil)
    (send self :max-line-length)
    (send self :refresh)
    linebuf)
 (:insert-string (str &optional (end (length str)))
    (let* ((line (aref linebuf win-row)) (len (length line))
	   (newline (make-string (+ len end))))
        (send self :cursor :off)
	(replace newline line :end2 win-col)
	(replace newline str :start1 win-col)
	(replace newline line
		     :start1 (+ win-col end)
		     :start2 win-col :end2 len)
        (setf (aref linebuf win-row) newline
	      (aref expbuf win-row) (expand-tab newline))
	(send self :refresh-line win-row win-col)
	(send self :advance end)
	(send self :cursor :on) ) )
 (:insert (ch)
    (let* ((line (aref linebuf win-row)) (len (length line))
	   (newline (make-string (1+ len))))
        (send self :cursor :off)
	(replace newline line :end2 win-col)
	(setf (aref newline win-col) ch)
	(replace newline line
		     :start1 (1+ win-col) :start2 win-col :end2 len)
        (setf (aref linebuf win-row) newline
	      (aref expbuf win-row) (expand-tab newline))
	(send self :advance 1)
	(send self :refresh-line win-row (1- win-col))
	(send self :cursor :on) ) )
 (:delete (n)
    (when (>= win-col n)
	(let ((line (aref linebuf win-row)) )
	   (send self :cursor :off)
           (replace line line :start1 (- win-col n) :start2 win-col)
	   (setq line (subseq line 0 (- (length line) n)))
	   (setf (aref linebuf win-row) line)
	   (setf (aref expbuf win-row) (expand-tab line))
	   (decf win-col n)
	   (send self :refresh-line win-row win-col)
	   (send self :cursor :on)) )
    )
  )
 
;; event handlers for BufferTextWindow

(defmethod BufferTextWindow
 (:keyEnter (ch &optional event) 
    (case ch
      ((#\backspace 2) (send self :goback))
      (#\rubout (send self :delete 1))
      (12 (send self :refresh))
      (3 (send self :cursor :off) (throw :window-main-loop nil))
      ((4 11)
	 (cond ((< win-col (length (aref linebuf win-row)))
		  (send self :advance 1) (send self :delete 1))))
      (6 (send self :cursor :off) (send self :advance 1)
	 (send self :cursor :on))
      ((#\newline #\return)
         (if (and notify-object notify-method)
             (send notify-object notify-method event)))
      (t (if (>= ch #\space) (send self :insert ch)))))
 (:buttonPress (event)
    (if (and buttonActive selected-pos)
	(send self :highlight nil (elt buttonActive 0) (elt buttonActive 1)
			(elt selected-pos 0) (elt selected-pos 1)))
    (let ((newrow (send self :event-row event))
	  (newcol (send self :event-col event)) )
       (setq buttonActive (integer-vector newrow newcol)) ;selection start
       (setq selected-pos buttonActive)
       )
    )
 (:region-direction (origin current-row current-col)
    (cond ((< (elt origin 0) current-row) :down)
	  ((> (elt origin 0) current-row) :up)
	  ((< (elt origin 1) current-col) :down)
	  (t :up)))
 (:motionNotify (event)
    (let* ((newrow (send self :event-row event))
	   (newcol (send self :event-col event))
	   (dir (send self :region-direction selected-pos newrow newcol))
	   (hdir (send self :region-direction selected-pos newrow newcol))) 
	(send self :highlight nil (elt buttonActive 0) (elt buttonActive 1)
		(elt selected-pos 0) (elt selected-pos 1))
	(send self :highlight t (elt buttonActive 0) (elt buttonActive 1)
		newrow newcol)
	(setq selected-pos (integer-vector newrow newcol)))
  )
 (:ButtonRelease (event)
    (let ((newrow (send self :event-row event))
	  (newcol (send self :event-col event)) )
       (send self :goto newrow newcol)
       (send self :cursor :on)))
 (:selection ()
    (when (and buttonActive selected-pos)
	(let (lines (srow (elt buttonActive 0)) (scol (elt buttonActive 1))
		    (erow (elt selected-pos 0)) (ecol (elt selected-pos 1)))
	    (if (or (> srow erow) (and (= srow erow) (> scol ecol)))
		(psetq srow erow
		       scol ecol
		       erow srow
		       ecol scol))
	    (if  (= srow erow)
		 (push (subseq (aref linebuf srow) scol ecol) lines)
		 (push (subseq (aref linebuf srow) scol) lines))
	    (if  (< srow (1- erow))
		 (dotimes (i (- erow srow 1))
			(push (aref linebuf (+ srow i 1)) lines)))
	    (if  (> erow srow)
		 (push (subseq (aref linebuf erow) 0 ecol) lines) )
	    (nreverse lines))))
     )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ScrollTextWindow
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(defmethod ScrollTextWindow
 (:create (&rest args
	   &key (scroll-bar nil)
		(horizontal-scroll-bar nil)
	   &allow-other-keys)
    (send-super* :create args)
    (when scroll-bar
	(setq scroll-bar-window
		(instance Xscroll-bar :create
			:width 12 :height (1- height)
			:parent self
			:gravity :northeast)))
    (when horizontal-scroll-bar
	(setq horizontal-scroll-bar-window
		(instance Xhorizontal-scroll-bar :create
			:width (if scroll-bar 
				   (- width
				      (send scroll-bar-window :width) 4)
				   width)
			:height 12
			:parent self
			:gravity :southwest)))
    (send self :locate-scroll-bar )
    self)
 (:locate-scroll-bar ()
    (when scroll-bar-window
	(send scroll-bar-window :resize 12 (- height 2))
	(send scroll-bar-window :move
		(- width (send scroll-bar-window :width) 2) 0)
	(setq win-col-max (/ (- width (send scroll-bar-window :width) 4)
			     charwidth)) )
    (when horizontal-scroll-bar-window
	(send horizontal-scroll-bar-window :resize 
		(if scroll-bar-window
		   (- width (send scroll-bar-window :width) 4)
		   width)
		12)
	(send horizontal-scroll-bar-window :move
		0
		(- height
		   (send horizontal-scroll-bar-window :height) 1))
	(setq win-row-max
		(/ (- height
		      (send horizontal-scroll-bar-window :height) 2)
		     charheight)) ) )
)

(defmethod ScrollTextWindow
 (:goto (r c &optional (csr :on))
    (send-super :goto r c csr)
    (setq row (+ win-row top-row) col (+ win-col top-col)))
 (:clear ()
    (send-super :clear)
    (setq top-row 0 top-col 0)
    (setq row 0 col 0)
    (setq linebuf (make-array '(0) :fill-pointer t)
	  expbuf (make-array  '(0) :fill-pointer t))
    (setq selected-line nil)
    (send self :max-line-length)
    self)
 (:lines () linebuf)
 (:refresh (&optional (offset 0) (lines (- win-row-max offset)))
   (let ((rowsave win-row) (colsave win-col))
      (send self :goto offset 0)
      (send-super :clear-lines lines)
      (send self :cursor :off)
      (dotimes (i (min (- (length linebuf) offset top-row) lines win-row-max))
	(send self :xy (+ offset i) 0)
	(send self :string x y (aref expbuf (+ offset i top-row))
			top-col) )
      (setq win-row rowsave win-col colsave)
      (send self :xy)
      (send self :cursor :on)
      (if selected-line (send self :refresh-line selected-line t))
      (if scroll-bar-window
	  (send scroll-bar-window :move-handle
		(/  (float top-row) (length linebuf))
		(min 1.0 (/ (float win-row-max) (length linebuf)))))
      (if horizontal-scroll-bar-window
	  (send horizontal-scroll-bar-window :move-handle
		(/  (float top-col) max-line-length)
		(min 1.0 (/ (float win-col-max) max-line-length))))
     ))
 (:line-in-window-p (ln) (<= top-row ln (+ top-row win-row-max -1)))
 (:refresh-line (ln &optional (highlight nil) &aux fg-save bg-save)
    (when (send self :line-in-window-p ln)
	(send self :goto (- ln top-row) 0)
	(send self :clear-eol)
	(send self :xy)
	(cond (highlight
		(setq fg-save (send gcon :foreground))
		(setq bg-save (send gcon :background))
		(send gcon :foreground bg-save)
		(send gcon :background fg-save)
		(send self :image-string x y (aref expbuf ln) top-col)
		(send gcon :foreground fg-save)
		(send gcon :background bg-save))
	       (t (send self :image-string x y (aref expbuf ln) top-col))))
    )
 (:locate (n)
    (when (<= 0 n (1- (length linebuf)))
       (setq top-row n)
       (send self :refresh)))
 (:display-selection (selection)
    (if selected-line
	(send self :refresh-line selected-line nil))
    (if selection (send self :refresh-line selection t))
    (setq selected-line selection))
 (:selection ()
    (if selected-line (aref linebuf selected-line)))
 (:scroll-fraction () (/ 1.0 (length linebuf)))
 (:horizontal-scroll-fraction () (/ 1.0 max-line-length))
 (:scroll (n)
    (send self :cursor :off)
    (if (floatp n) (setq n (round (* (length linebuf) n))))
    (setq n
	  (if (< n 0)
	      (- (min top-row (abs n)))
	      (max 0 (min (- (length linebuf) top-row win-row-max)  n))))
    (send-super :scroll n)
    (incf top-row n)
    (cond ((< n 0) (send self :refresh 0 (abs n)))
	  ((> n 0) (send self :refresh (- win-row-max n) n)))
    (send self :cursor :on)
;    (when scroll-bar-window
;	(send scroll-bar-window :move-handle
;		(/  (float top-row)(length linebuf))
;		(/ (float win-row-max) (length linebuf)))
;	)
    )
 (:horizontal-scroll (n)
    (send self :cursor :off)
    (if (floatp n) (setq n (round (* max-line-length n))))
    (setq n
	  (if (< n 0)
	      (- (min top-col (abs n)))
	      (max 0 (min (- max-line-length top-col win-col-max) n) )))
    (send-super :horizontal-scroll n)
    (incf top-col n)
    (send self :refresh)	;; refresh all; should be optimized
#|    (cond ((< n 0) (send self :horizontal-refresh 0 (abs n)))
	  ((> n 0) (send self :horizontal-refresh (- win-col-max n) n)))
|#
    (send self :cursor :on)
    )
 )

(defmethod ScrollTextWindow
 (:insert-char (c &optional (refresh t))
    (let* ((line (aref linebuf row)) (len (length line))
	   (buf (make-string 1)))
	(setf (char buf 0) c)
	(setq line
		(concatenate string
			(subseq line 0 col)
			buf
			(subseq line col)))
        (setf (aref linebuf row) line
	      (aref expbuf row) (expand-tab line))
	(when refresh   (send self :refresh-line row))
	(send self :advance 1)
	(if refresh (send self :cursor :on) ))
  )
 (:insert-newline (&optional (refresh t))
    (let* ()
        (send self :clear-eol)
	()))
 (:insert (thing &optional (refresh t))
    (cond ((member thing '(#\newline #\return))
	   (send self :insert-newline))
	  ((numberp thing) (send self :insert-char thing refresh))
	  ((stringp thing)
	   (dotimes (i (length thing)) (send self :insert (char thing i))))))
 )

(defmethod ScrollTextWindow 
 (:buttonPress (event)
    (send-super :buttonPress event)
    (let ((r (+ top-row (send self :event-row event)))
	  (c (+ top-col (send self :event-col event))))
	(setq row (min (1- (length linebuf)) r)
	      col (min (length (aref linebuf row)) c))
       (send self :display-selection 
	     (if (< row (length linebuf)) row nil))))
 (:buttonRelease (event)
    (let ((r (+ top-row (send self :event-row event)))
	  (c (+ top-col (send self :event-col event))))
	(if (and (eql selected-line r) notify-object notify-method)
	    (send notify-object notify-method (send self :selection)))))
 (:resize (w h)
    (send-super :resize w h)
    (send self :locate-scroll-bar)
    (send self :refresh))
 (:ConfigureNotify (event)
    (let ((newwidth (send self :width)) (newheight (send self :height)))
	(when (or (/= newwidth width) (/= newheight height))
	    (send self :resize newwidth newheight))))
 )



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TextEdit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

