;;;; correlation.l
;;;  motion tracking window based on image correlation
;;; (C)1994, Toshihiro Matsui, Electrotechnical Laboratory
;;;

;; (in-package "IMAGE")

(export '(tracking-window))

;; C-coded image correlation is called.
;; (image::image-correlation ref search x y size threshold)
;; Image-correlation computes correlation value of 'ref' image in 'search'
;; image. Correlation value becomes the least when two images match most
;; greatly. Image-correlation return the correlation value and the location
;; of the most-matching window. The search area is a square window designated
;;  by x,y and extending size dots both in x and y direction.

(defmethod pixel-image
 (:grab (x y &optional (sampling 2))
    (grabber::window self x y sampling))
  )

(defclass tracking-window :super pixel-image
	:slots (x-pos y-pos	; position of the track window in *whole-image
		x-vel y-vel	; velocity
		pattern-size	; the size of this window
		window-size	; search area size, twice as big as the pattern
		x-win y-win	; the position of the search area
		window		; pixel image of the search area
		window-margin	; offset of topleft from pattern to search window
		update threshold	; shrinked pattern window
		half-pattern
		correlation
        ))

(defmethod tracking-window
 (:grab (&optional (x x-pos) (y y-pos) (sampling 2))
	(send-super :grab x y sampling))
 (:window-rectangle (val)
    (grabber:rectangle x-win y-win
	(+ x-win window-size) (+ y-win window-size) val))
 (:rectangle (val)
    (grabber:rectangle x-pos y-pos
	(+ x-pos pattern-size) (+ y-pos pattern-size) val))
 )

(defmethod tracking-window 
 (:correlation () correlation)
 (:move (newx newy)
    (send self :rectangle 0)
    (setq x-pos newx y-pos newy x-vel 0 y-vel 0)
    (send self :rectangle 2)
    (send self :grab)
    self)
 (:track (display-window &optional (th))
    (if display-window (send self :window-rectangle 0))
    (setq th  (if th (* th pattern-size pattern-size) threshold))
    (setq x-win (min (- 320 window-size)
		     (max 0 (+ x-pos window-margin  x-vel ))))
    (setq y-win (min (- 240 window-size)
		     (max 0 (+ y-pos window-margin y-vel))))
    (send window :grab x-win y-win)
    (let ((cor (image::image-correlation window self
			0 0	; offset in the window
			(/ window-size 2)
			th))
	  newx newy)
      (if *debug* (print (car cor)))
      (cond (cor
		(send self :rectangle 0)	;erase
		(setq newx (+ x-win (second cor))
		      newy (+ y-win (third cor)))
		(setq x-vel (- newx x-pos) y-vel (- newy y-pos))
		(setq x-pos newx y-pos newy)
		;; update the pattern
		(if update (send self :grab x-pos y-pos))
		(if display-window
		    (send window :display display-window nil x-win y-win))
		(send display-window :rectangle x-pos y-pos pattern-size pattern-size)
		(send self :rectangle 2)
		(if display-window (send self :window-rectangle 7))
		(setq correlation (car cor)))
	   (t (format t ";lost-1 ~A ~%" self)	;; track failed
	      ;; do not update pattern if track failed.
	      ;; (if update (send self :grab x-pos y-pos))
	      nil))
	))
 (:search (display-window &optional th)
    (if display-window (send self :window-rectangle 0))
    (setq th  (if th (/ (* th pattern-size pattern-size) 3) (/ threshold 3)))
    (setq x-win (min (- 320 window-size)
		     (max 0 (+ x-pos window-margin x-vel (- pattern-size) ))))
    (setq y-win (min (- 240 window-size)
		     (max 0 (+ y-pos window-margin y-vel (- pattern-size)))))
    (send window :grab x-win y-win 4)
    (send self :halve half-pattern)
    (let ((cor (image::image-correlation window half-pattern
			0 0	; offset in the window
			(/ window-size 2)
			th))
	  newx newy)
      (if *debug* (print (car cor)))
      (cond (cor
		(send self :rectangle 0)	;erase
		(setq newx (+ x-win (* (second cor) 2))
		      newy (+ y-win (* (third cor) 2)))
		(setq x-vel (- newx x-pos) y-vel (- newy y-pos))
		(setq x-pos newx y-pos newy)
		;; update the pattern
		(if update (send self :grab x-pos y-pos))
		;;(if display
		;; (send window :display *viewsurface* nil x-win y-win))
		;(send *viewsurface* :rectangle x y pattern-size pattern-size)
		(send self :rectangle 2)
	        (setq x-win (min (- 320 window-size)
			     (max 0 (+ x-pos window-margin))))
	        (setq y-win (min (- 240 window-size)
			     (max 0 (+ y-pos window-margin ))))
		(if display-window (send self :window-rectangle 7))
		(car cor))
	   (t (format t ";lost-2 ~A ~%" self)
	      nil)
	)
    ) )
 (:track-and-search (flag &optional th)
    (unless (send self :track flag th)
	(send self :search flag th)))
 )

(defmethod tracking-window
 (:x () x-pos)
 (:y () y-pos)
 (:pos () (integer-vector x-pos y-pos))
 (:vel () (integer-vector x-vel y-vel))
 (:insidep (pos &aux (x (aref pos 0)) (y (aref pos 1)))
    (and (<= x-pos x) (<= y-pos y)
	 (<= x (+ x-pos pattern-size)) (<= y (+ y-pos pattern-size))))
 (:update (&optional (flag :get))
    (if (eq flag :get)
	update
	(setq update flag)))
 (:prin1 (strm &rest mesg)
    (send-super* :prin1 strm
	(format nil "at (~d,~d) ~s ~d" x-pos y-pos update threshold) mesg))
 (:init (x y size win-size)	;separate size into width and height
    (setq x-vel 0 y-vel 0 x-pos x y-pos y)
    (setq pattern-size size)
    (send-super :init size size)
    (setq window-size win-size)
    (setq window (instance pixel-image :init window-size window-size))
    (send window :xpicture)
    (setq half-pattern (instance pixel-image :init (/ size 2) (/ size 2)))
    (setq window-margin (/ (- size window-size) 2))
    (setq x-win x-pos y-win y-pos)
    (setq update t)
    (setq threshold (* size size 20))
    (send self :move x-pos y-pos)
    self)
 )

(defun track-one (display threshold tracking-windows)
      (snap)
      (send-all tracking-windows :track display threshold))

(defun search (win)
    (send win :search t))

(defun cor (display threshold &rest tracking)
   (grabber::clear-overlay)
   (while t (track-one display threshold tracking)) )



(defun rotate-pattern (pat ang)
   (let* ((width (send pat :width)) (height (send pat :height))
	  (width/2 (/ width 2))  (height/2 (/ height 2))
	  (rotpat (send pat :duplicate))
	  (i (- width/2)) (j (- height/2))
	  (rotmat (rotation-matrix ang))
	  )
      ()))