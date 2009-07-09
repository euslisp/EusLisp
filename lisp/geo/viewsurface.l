;;; viewsurface.l
;;;	author M.Inaba, UTOYO
;;;
;; 
;; color model transformation
;;	Copyright 1989 (c) Toshihiro MATSUI, ETL
;;
;;  HLS(hue,lightness,saturation) to RGB(255,255,255)
;;	hue:  color of rainbow from 0 to 360
;;		0--red brown yellow green blue mazenta--360
;;	lightness: 0.0(black) to 1.0(white)
;;	saturation: 0.0(black and white) to 1.0 (vivid colors)
;;

(in-package "GEOMETRY")
(export '(hls2rgb rgb2hls 
	viewsurface tektro-viewsurface
	*tektro-port*
	tektro-showline
	tektro-clear
	tektro))


(defun hls2rgb (hue lightness saturation &optional (rgb 255))
"hls2rgb hue lightness saturation
hue: 0..360, lightness 0..1, saturation 0..1"
  (flet  ((hlsvalue (n1 n2 hue)
		  (setq hue (round hue))
		  (if (> hue 360) (decf hue 360))
		  (if (< hue 0) (incf hue 360))
		  (case (/ hue 60)
		     ((0) %(n1 + ((n2 - n1) * hue / 60.0)))
		     ((1 2) n2)
		     ((3) %(n1 + (((n2 - n1) * (240 - hue)) / 60.0)))
		     ((4 5 6) n1)))  )
    (let ((m1 0) (m2 0))
      (if %(lightness < 0.5)
          %(m2 = lightness * (1 + saturation))
          %(m2 = lightness + saturation - (lightness *  saturation)))
      %(m1 = 2 * lightness - m2)
      (cond ((= saturation 0.0)
             (if (null hue) (list lightness lightness lightness)))
            (t
             (list (round (* rgb (hlsvalue m1 m2 (+ hue 120))))
                   (round (* rgb (hlsvalue m1 m2 hue)))
                   (round (* rgb (hlsvalue m1 m2 (- hue 120))))))))) )

(defun rgb2hls (red green blue &optional (rgb 255.0))
   (declare (float red green blue))
   (setf red (/ (float red) rgb)		;normalize
	 green (/ (float green) rgb)
	 blue (/ (float blue) rgb))
   (let (hue lightness saturation V m r2 g2 b2 vm)
      (declare (float hue lightness saturation v m r2 g2 b2 vm))
      (setq V (max red green blue)
	    m (min red green blue))
      (setf lightness (/ (+ m V) 2.0))
      (if (< lightness 0.0) (return-from rgb2hls (list 0.0 0.0 0.0)))
      (setf vm (- V m)
	    saturation vm)
      (if (<= saturation 0.0)
	  (return-from rgb2hls (list 0.0 lightness 0.0)))
      (setq saturation
	    (/ saturation 
	       (if (< lightness 0.5)
		   (+ v m)
		   (- 2.0 v m))))
      %(r2 = (v - red) / vm)
      %(g2 = (v - green) / vm)
      %(b2 = (v - blue) / vm)
      (cond ((= red v)
	     (setq hue (if (= green m) (+ 5.0 b2) (- 1.0 g2)) ) )
	    ((= green v)
	     (setq hue (if (= blue m) (+ 1.0 r2) (- 3.0 b2)) ) )
	    (t
	     (setq hue (if (= red m) (+ 3.0 g2) (- 5.0 r2)) ) ) )
      (setq hue (/ hue 6.0))
      (list (* 360.0 hue) lightness saturation)))

;; class viewsurface
;; viewsurface is an abstract class.

(defclass viewsurface :super propertied-object)

(defmethod viewsurface
  (:drawline-primitive (x1 y1 x2 y2 &optional color)
     (format t ";; line: ~s ~s --> ~s ~s~%" x1 y2 x2 y2))
  (:draw-line (v1 v2 &optional color)
     (send self :drawline-primitive
	    (aref v1 0) (aref v1 1)
	    (aref v2 0) (aref v2 1) color)) 
  (:line-style (x)
     (case x
	(0 "solid line")
	(1 "dashed line")))
  (:line-width (x)
     (format t ";; line-width= ~d~%" x))
  (:nomethod (&rest msg)
     (warn "unrecognized message ~s sent to ~S~%" msg self))
  (:set-erase-mode ())
  (:set-show-mode ())
  (:flush () t)
  (:init (&rest l &key	&allow-other-keys) self)
  )

;*****************************************************************
;* tektronics 4010 type viewsurface
;*****************************************************************

(defclass tektro-viewsurface
  :super viewsurface
  :slots (width height color)  )

(defmethod tektro-viewsurface
  (:init (&rest args
		&key ((:color c) 0)
		     ((:width w) 768)
		     ((:height h) 512)
		&allow-other-keys)
	 (setq color c)
	 (setq height h width h)
	 self)
  (:clear () (tektro-clear))
  (:width (&optional x) (if (numberp x) (setq width x)) width)
  (:height (&optional x) (if (numberp x) (setq height x)) height)
  (:resize (w h)
	(send self :width w)
	(send self :height h))
  (:drawline-primitive (x0 y0 x1 y1 &optional color)
       (tektro-showline	(round x0) (round y0) (round x1) (round y1))))

(defvar *tektro-plot-buffer* "          ")
(setf (aref *tektro-plot-buffer* 0) 29)
(setf (aref *tektro-plot-buffer* 9) 31)

(defvar *tektro-port* t)

(defun tektro-showline (x1 y1 x2 y2)	;arguments must be type fixnum
  (declare (type fixnum x1 y1 x2 y2))
  ;	(warn "(~s ~s) (~s ~s)~%" x1 y1 x2 y2)
  ;      (setq x1 (round x1)
  ;            y1 (round y1)
  ;            x2 (round x2)
  ;            y2 (round y2))
  (if *debug* (format t ";; tektro-showline: ~s ~s ~s ~s~%" x1 y1 x2 y2))
  (setf (aref *tektro-plot-buffer* 1) (+ 32 (/ y1 32)))
  (setf (aref *tektro-plot-buffer* 2) (+ 96 (mod y1 32)))
  (setf (aref *tektro-plot-buffer* 3) (+ 32 (/ x1 32)))
  (setf (aref *tektro-plot-buffer* 4) (+ 64 (mod x1 32)))
  (setf (aref *tektro-plot-buffer* 5) (+ 32 (/ y2 32)))
  (setf (aref *tektro-plot-buffer* 6) (+ 96 (mod y2 32)))
  (setf (aref *tektro-plot-buffer* 7) (+ 32 (/ x2 32)))
  (setf (aref *tektro-plot-buffer* 8) (+ 64 (mod x2 32)))
  (princ *tektro-plot-buffer* *tektro-port*) t)

(defun tektro-clear (&optional (port *tektro-port*))
   (write-byte  (list #x1b #xc) port))

(defmacro tektro (file &rest forms)
   `(with-open-file (*tektro-port* ,file  :direction :output)
	,@forms))

(defun default-viewsurface (&rest args)
   (send-lexpr (instantiate tektro-viewsurface) :init args))

(provide :viewsurface "@(#)$Id$")
