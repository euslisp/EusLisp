;;;
;;;	PICTdraw 
;;;              (c) 1994, Toshihiro Matsui, Electrotechnical Laboratory
;;;

;; dda-line returns new point location after 'count'-dots advance

(defun dda-line (x0 y0 x1 y1)
  (declare (integer x0 y0 x1 y1 val))
  (flet ((line_x2y(x0 y0 dx dy)
	  (declare (integer x0 y0 dx dy))
	  (let (y (sgn (signum dx)) result k)
	    (declare (integer y sgn))
	    (setq k (* sgn (/ (float dy) (float dx))))
	    (dotimes (i (abs dx))
		(incf x0 sgn)
		(setq y (round (+ (* k i) y0)))
		(push (list x0 y) result) )
	    (nreverse result) )  )
	(line_y2x(x0 y0 dx dy)
	  (declare (integer x0 y0 dx dy))
	  (let (x (sgn (signum dy)) result k)
	    (declare (integer x i sgn))
	    %(k = sgn * float(dx) / float(dy))
	    (dotimes (i (abs dy))
		(incf y0 sgn)
		(setq x (round (+ (* k i) x0)))
	        (push (list x y0) result))
	    (nreverse result))) )
    (let ((dx (- x1 x0)) (dy (- y1 y0)))
       (cond ((and (= dx 0) (= dy 0)) (list (list x1 y1)))
             ((>= (abs dx) (abs dy))  (line_x2y x0 y0 dx dy))
	     (t (line_y2x x0 y0 dx dy))) ) ))

(defclass pictdraw-viewsurface
  :super viewsurface
  :slots (color strm fname
	  linestyle	;0=solid, 1=dashed
	  linewidth	;1=thin  2,5= thick
	  dash-length
	  )  )

(defmethod pictdraw-viewsurface
  (:init (&rest args
		&key ((:color c) 0)
		((:fname f) "pict")
		&allow-other-keys)
	 (setq fname f)
	 (setq color c
	       linewidth 1
	       linestyle 0
	       dash-length 2)
	 (send self :open fname)
	 self)
  (:open (&optional (f fname))
    (setq strm (open fname :direction :output))
    (setq *picdraw* strm)
    (let ((header (make-string 512)))
	(replace header
	   (list
		#x44 #x52 #x57 #x47 #x44 #x32 #x00 #x06
		#x00 #x03 #x00 #x00 #x00 #x48 #x00 #x48
		#x00 #x00 #x00 #x00 #x03 #x0D #x02 #x1A
		#xFF #xE2 #xFF #xE4 #x03 #x2B #x02 #x36
		#x03 #x67 #x05 #x7B #x03 #xDE #x00 #x02
		#x00 #x00 #x00 #x48 #x00 #x48 #x00 #x00
		#x00 #x00 #x03 #x0D #x02 #x1A #x00 #x01
		#x00 #x00 #x00 #x64 #x00 #x00 #x00 #x01
		#x00 #x01 #x01 #x01 #x00 #x02 #x00 #x01
		#x27 #x0F #x00 #x01 #x00 #x01 #x00 #x00
		#x00 #x00 #x00 #x00 #x00 #x00 #x00 #x00
		#x00 #x00 #x00 #x0A #x00 #x19 #x01 #x90
		#x00 #x00 #x00 #x00 #x00 #xC0 #x00 #x00
		#x00 #x00 #x00 #x00 #x00 #x00 #x00 #x01
		#x00 #x00 #x00 #x00 #x00 #x00 #x00 #x00
		#x00 #x48 #x00 #x00 #x00 #x48 #x00 #x00
		#x00 #x00 #x01 #x00 #x02 #x03 #x02 #x00
		#x03 #x00 #x00 #x01 #x03 #x01 #x01 #x00
		#x00 #x01 #x01 #x00 #x01 #x00 #x03 #x0E
		#x02 #x18 #x03 #x0E #x02 #x18 #x03 #x0E
		#x02 #x18 #x00 #x00 #x00 #x00 #x00 #x01
		#x01 #x01 #x06 #x00 #x01 #x00 #x00 #x00))
	(unix:write strm header)
	(write-word 0 strm)	; picSize
	(write-word 0 strm)	; bounding-box
	(write-word 0 strm)
	(write-word 512 strm)
	(write-word 512 strm)
	(write-word #x0011 strm)	; version opcode
	(write-word #x02FF strm)	; PICT2 version
	(write-word #x0c00 strm)	; Header op
	(dotimes (i 12) (write-word #xffff strm))	;size, fBBox
	))
  (:close ()
    (write-word #x00ff strm)
    (close strm))
  (:set-erase-mode ())
  (:set-show-mode ())
  (:clear ()
	  (send self :close)
	  (send self :open fname))
  (:flush () t)
  (:line-width (width) (setq linewidth width))
  (:line-style (dash) 
     (setq linestyle  dash))
  (:color (c) (setq color c))
  (:drawline-primitive  (x0 y0 x1 y1 &optional color)
     (setq x0 (round x0) y0 (round y0) x1 (round x1) y1 (round y1))
     (cond ((eq linestyle 0)	;solid
		(write-word  #x0020 strm)	; Line opcode
		(write-word y0 strm)
		(write-word x0 strm)
		(write-word y1 strm)
		(write-word x1 strm))
	   (t	;draw dashed line
	     (let* ((dda-list (dda-line x0 y0 x1 y1))
		    new (newx x0) (newy y0))
		(while dda-list
		    (setq dda-list (nthcdr dash-length dda-list))
		    (setq new (first dda-list))
		    (when new
			(setq newx (first new) newy (second new))
			(write-word #x0022 strm)	; short line
			(write-word y0 strm)
			(write-word x0 strm)
			(write-byte (- newx x0) strm)
			(write-byte (- newy y0) strm)
			(setq dda-list (nthcdr dash-length dda-list))
			(setq new (first dda-list))
			(if new
			    (setq x0 (first new) y0 (second new)))))))
  )))

;;;

(defmacro pictdraw (fname  &rest forms)
  (let ((vr *viewer*))
    `(let ((*viewer*
	      (instance viewer :init 
		  :viewing (send ,vr :viewing)
		  :viewport 
			(instance viewport  :init 
			    :width 600 :height -600	;512*1/72" 
			    :xcenter 300 :ycenter 300)
		  :viewsurface
			(instance pictdraw-viewsurface :init :fname ,fname))))
	(progn . ,forms)
	(send *viewer* :viewsurface :close))
     ))


