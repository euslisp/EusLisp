;;;;****************************************************************
;;;; D D A (Digital Differential Analyzer)
;;;; (c) 1998, Toshihiro Matsui, Electrotechnical Laboratory
;;;; line, ellipse (circle) generator
;;;

(export '(dda line-dda ellipse-dda circle-dda draw-ellipse
	  ellipse-dda dda-line))

(defclass DDA :super propertied-object :slots ((count :integer)))

(defclass line-DDA :super DDA
  :slots ((x :integer) (y :integer)
	  (dx :integer) (dy :integer)
	  (err :integer) (errinc :integer) (errdec :integer)
	  (xyinc :integer) (length :integer)
	  (update-method))
  )

(defclass ellipse-DDA :super DDA
	:slots (finished xcenter ycenter
		(a :float) (b :float)
		(m  :float) (eps :float)
		(ix :integer) (iy :integer) (x :float) (y :float)
		(ix1 :integer) (iy1 :integer) (x1 :float) (y1 :float)))
(defclass circle-DDA :super ellipse-DDA)

(defmethod DDA
 (:init ()
   (setq count 0)
   self)
 )
 
(defmethod line-DDA
 (:init (x0 y0 x1 y1)
    (send-super :init)
    (let (adx ady)
       (setq dx (- x1 x0)
	     dy (- y1 y0)
	     adx (abs dx)
	     ady (abs dy)
	     err 0
  	     errdec (* 2 (abs (- ady adx)))
	     errinc (* 2 (if (> adx ady) ady adx))
	     x x0
	     y y0
             length (1+ (max adx ady)))
    (cond ((> adx ady)
	   (setq err (- (* 2 ady) adx))
	   (setq xyinc (if (> dy 0) 1 -1))
	   (setq update-method :update-x-major) )
	  (t ; y is major
	   (setq err (- (* 2 adx) ady))
	   (setq xyinc (if (> dx 0) 1 -1))
	   (setq update-method :update-y-major) )
	) )
    self)
 (:update-x-major ()
     (cond ((> err 0)
	    (incf y xyinc)
	    (decf err errdec))
	   (t (incf err errinc)))
     (incf x (if (> dx 0) 1 -1)) )
 (:update-y-major ()
     (cond ((> err 0)
	    (incf x xyinc)
	    (decf err errdec))
	   (t (incf err errinc)))
     (incf y (if (> dy 0) 1 -1)) )
 (:next ()	; composed only by integer additions and subtractions
    (if (> (incf count) length) (return-from :next nil))
    (prog1 (list x y) (send self update-method))
	;; call either :update-x-major or :update-y-major
  )
 )

;;****************************************************************

(defun dda-line (x0 y0 x1 y1)
   (let ((ddax (instance line-dda :init x0 y0 x1 y1))
	 (p)
	 (points))
     (while (setq p (send ddax :next)) (push p points))
     (nreverse points)) )

;;****************************************************************


(defmethod ellipse-dda
 (:init (param-a param-b &optional (x-center 0) (y-center 0))
    (send-super :init)
    (setq finished nil)
    (setq xcenter x-center ycenter y-center)
    (setq a (float param-a) b (float param-b))
    (setq m (/ (* a a) (* b b)))
    (setq eps (expt 2 (- (ceiling (/ (log b) (log 2))))))
    (setq x1 (float a) y1 0.0)
    (setq ix1 (round x1) iy1 (round y1))
    (setq ix ix1 iy iy1 y 0)
    self)
 (:next ()
        (incf count)
	(when (and (< y 0) (>= y1 0.0))
	    (setq finished t)
	    (return-from :next nil))
	(setq x x1 y y1)
	(setq x1 (- x (* eps m y)))
	(setq y1 (+ y (* eps   x1)))
	(setq ix1 (round x1) iy1 (round y1))
	;; (print (list ix1 iy1))
	(cond ((or (/= ix ix1) (/= iy iy1))
		    (setq ix ix1 iy iy1)
		    (list (+ xcenter ix) (+ ycenter iy)))
	      (t (send self :next))    )
	)
  )

(defun dda-ellipse (a b)
    (let (x y x1 y1 ix iy ix1 iy1 eps m one/m (r)) 
	(setq a (float a) b (float b))
	(setq m (/ (* b b) (* a a))
	      one/m (/ 1.0 m))
	(setq eps (expt 2 (- (ceiling (/ (log b) (log 2))))))
	(print (list eps m))
	(setq x1 (float a) y1 0.0)
	(setq ix1 (round x1) iy1 (round y1))
	(setq ix ix1 iy iy1)
	(tagbody 
		loop
		(setq x x1 y y1)
		(setq x1 (- x (* eps one/m y)))
		(setq y1 (+ y (* eps #|m|# x1)))
		(setq ix1 (round x1) iy1 (round y1))
		;; (print (list ix1 iy1))
		(when (or (/= ix ix1) (/= iy iy1))
		    (setq ix ix1 iy iy1)
		    (push (list ix iy) r)
		    (print (list ix iy))
		    )
		(if (not (and (< y 0) (>= y1 0))) (go loop)))
	t))


(defun draw-ellipse (xc yc a b &optional (win *viewsurface*))
   (let ((dda (instance ellipse-dda :init a b xc yc)) xy )
      (while (setq xy (send dda :next))
	(send win :point (car xy) (second xy)))
      (send win :flush)
))

(provide :DDA "@(#)$Id: dda.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $")
