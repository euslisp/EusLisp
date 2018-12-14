;;;; image processing classes
;;;
;;;	Sep/15/1992
;;;	(c) Toshihiro Matsui, Electrotechnical Laboratory
;;;

(eval-when (eval)
   (unless (find-package "IMAGE")
     (make-package "IMAGE" :nicknames '("IMG")))
   (in-package "IMAGE"))

(in-package "IMAGE")

; (require :image-convolution "convolve")

(eval-when (load eval)
  (export '(
	image-2d
	single-channel-image bitmap-image grayscale-image index-color-image
	multi-channel-image split-color-image color-image
	color-image16 color-image24 color-image32
	make-colors
	make-ximage overlay-edge
	look-up look-up* look-up2
	concatenate-lut make-equilevel-lut
	pseudo2true
	*image-colormap* *color-viewer*
	swap-rgb
	color-32to24
	color-24to32
	color-32to8
	color-32to8x3
	color-24to8
	color-24to16
	color-24to8x3
	))
;; exports from RGBHLS.c and image_correlation.c
  (export '(
	RGB-TO-HLS	;from RGBHLS.c
	image-correlation image-correlation1 circular-correlation
	)))

; (import '(geometry:*viewsurface*))
(use-package "GEOMETRY")

(defvar *gray16*)
(defvar *gray32*)
(defvar *thermo16*)
(defvar *red16*)
(defvar *green16*)
(defvar *blue16*)
(defvar *rainbow16*)
(defvar *rainbow32*)
(defvar *x-gray8-lut* )
(defvar *x-gray16-lut*)
(defvar *x-gray32-lut* )
(defvar *x-rainbow16-lut*)
(defvar *X-rainbow32-lut*)
(defvar *x-red16-lut*)
(defvar *x-green16-lut*)
(defvar *x-blue16-lut*)
(defvar *x-color-lut*)
(defvar *256to8*)
(defvar *256to16*)
(defvar *256to32*)
(defvar *image-colormap*)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; look-up table
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun make-equilevel-lut (levels &optional (size 256))
   (let ((lut (instantiate integer-vector 256))
	 (row (/ size levels))
	 (index 0))
      (dotimes (i levels)
	 (dotimes (j row)
	     (setf (aref lut index) i)
	     (incf index)))
      lut))

#|
;; coded in convolve.c (Nov/1992)

(defun look-up (src dest lut)
   (unless dest (setq dest (make-sequence (class src) (length src))))
   (dotimes (i (length src))
	(setf (char dest i) (aref lut (char src i))))
   dest)
|#

(defun look-up2 (src dest lut1 lut2)
   (unless dest (setq dest (make-sequence (class src) (length src))))
   (dotimes (i (length src))
	(setf (aref dest i) (aref lut2 (aref lut1 (aref src i)))))
   dest)

(defun look-up* (src dest luts &aux p)
   (unless dest (setq dest (make-sequence (class src) (length src))))
   (dotimes (i (length src))
	(setq p (aref src i))
	(dolist (lut luts)
	   (setq p (aref lut p)))
	(setf (aref dest i) p))
   dest)

(defun concatenate-lut (lut1 lut2 &optional (size 256))
   (let ((lutx (make-sequence integer-vector size)))
      (dotimes (i 256)
	 (setf (aref lutx i) (aref lut2 (aref lut1 i))))
      lutx))
     
;; convolution

#|
(defun make-convolution-mask ()
   (make-array '(3 3) :element-type :byte
	:initial-contents '((1 2 1) (2 5 2) (1 2 1))))
|#

;;
;; image classes
;;
;; image-2d --+-- single-channel-image
;;	      |		+----------- bitmap-image
;;	      |		+----------- grayscale-image
;;	      |		+----------- index-color-image
;;	      +-- multi-channel-image
;;			+----------- split-color-image
;;			+----------- color-image -+-- color-image16
;;						  +-- color-image24
;;						  +-- color-image32
;;					    _	
(defclass image-2d :super array	  :slots (depth))
   (defclass single-channel-image :super image-2d	 :slots ())
      (defclass bitmap-image :super single-channel-image)
      (defclass grayscale-image :super single-channel-image)
      (defclass index-color-image  :super single-channel-image)
   (defclass multi-channel-image  :super image-2d :slots (components))
      (defclass split-color-image :super multi-channel-image)
      (defclass color-image :super multi-channel-image
		:slots (pixel-bytes
			redshift redwidth
			greenshift greenwidth
			blueshift bluewidth))
	  (defclass color-image16 :super color-image)
	  (defclass color-image24 :super color-image)
	  (defclass color-image32 :super color-image)

;****************************************************************
;; image-2d
;; note that pixel at (x,y) is accessed by (aref a y x).
;****************************************************************

(defmethod image-2d
 (:entity () entity)
 (:width () dim1)
 (:height () dim0)
 (:size () (length entity))
 (:pixel (x y) (aref self y x))
 (:set-pixel (x y val) (setf (aref self y x) val))
 (:duplicate (&rest args)
    (instance* (class self) :init (send self :width) (send self :height) args))
 (:copy-from (src) (replace entity (array-entity src)) self)
 (:copy () (copy-object self))
 (:hex (&optional (x 0) (y 0) (w 8) (h 8) (strm t))
    (dotimes (j h)
	(format strm "~5,5d " (+ y j))
	(dotimes (i w)
	   (format strm "~a" (send self :pixel-hex-string (+ x i) (+ y j))))
        (format strm "~%")
	))
 (:prin1 (strm &rest msg)
    (send-super* :prin1 strm
	(format nil "~dx~d" (send self :width) (send self :height)) msg)
    )
 (:init (w h &optional imgvec (deepth 8))
    (unless imgvec
	(setq imgvec
	      (make-array (* w h)
		 :element-type
		 (cond ((= deepth 1) :bit)
		       ((<= deepth 8) :byte)
		       ((<= deepth 32) :integer)
		       (t (error "image depth > 32 is not supported"))))))
    (setq rank 2
	  displaced-index-offset 0)
    (setq depth deepth dim1 w dim0 h entity imgvec)
    self)
 )

(defmethod image-2d
 (:fill (val)    (fill entity val)    val)
 (:clear () (send self :fill 0))
 (:transpose (&optional (result (instance (class self) :init
				(send self :height) (send self :width))))
    (dotimes (x dim1)
	(dotimes (y dim0)
	   (send result :set-pixel x y (send self :pixel y x)) )
	)
    result)
 (:map-picture (lut &optional (result (send self :duplicate)))
    (let ((pict2 (array-entity result)))
       (dotimes (i (length entity))
	   (setf (char pict2 i) (aref lut (char entity i)))))
    result)
 (:map (fn &optional (result (send self :duplicate)))
    (let ((pict2 (array-entity result)))
       (dotimes (i (length entity))
	   (setf (char pict2 i) (funcall fn (char entity i)))))
    result)
  )

;;****************************************************************
;; SINGLE-CHANNEL-IMAGE
;;****************************************************************

(defmethod single-channel-image
 (:pixel (x y) (aref entity y x))
 (:set-pixel (x y val) (setf (aref entity y x) val))
 (:pixel-hex-string (x y) (format nil "~2,2x " (send self :pixel x y)))
 (:halve (&optional (simage)) 	;512*512->256x256
    (let* ((swidth (/ (send self :width) 2))
	   (sheight (/ (send self :height) 2)))
	 (if (null simage)
	     (setq simage (instance (class self) :init swidth sheight)))
	(halve-image self simage)
        simage))
 (:double (&optional (simage)) 	;256x256 -> 512*512
    (let* ((swidth (* (send self :width) 2))
	   (sheight (* (send self :height) 2)))
	 (if (null simage)
	     (setq simage (instance (class self) :init swidth sheight)))
	(double-image self simage)
        simage))
 (:patch-in (xs ys img)
    ;; img is stored in this class from (xs, ys)
    ;; x+(send img :width) <= (send self :width)
    (let ((ww (send self :width)) (hh (send self :height))
	  (w (send img :width)) 
	  (imgent (array-entity img))
	  p1 p2)
       (dotimes (y (send img :height))
	   (setq p1 (+ (* (+ ys y) ww) xs))
	   (replace entity imgent :start1 p1 :end1 (+ p1 w)
			:start2 (* y w)))
	))
 ) 

(defmethod single-channel-image
 (:xpicture (&optional lut)
    (unless xpicture
	    (setf xpicture (instance index-color-image :init dim1 dim0)))
    (unless lut (setq lut (send self :display-lut)))
    (look-up entity (array-entity xpicture) lut)
    xpicture)
 (:display-lut (&optional newlut)
    (if (vectorp newlut)
	(send self :xpicture (setf display-lut newlut)))
    (if display-lut display-lut *gray32*))
 (:display (&optional (xw geometry:*viewsurface*) (lut) (x 0) (y 0))
    (let ((bpp (send xw :depth)))
      (case bpp
	(8 (send xw :putimage 
		    (if xpicture
			(array-entity (send self :xpicture lut))
			(array-entity self))
		    :dst-x x :dst-y y :width dim1 :height dim0) )
	(16 (send xw :putimage (send self :to16)))
	(24 (send xw :putimage (send self :to24)))
	(32 (send xw :putimage (send self :to32)))
	(t (warn "can't display with the visual of ~s bit depth" bpp))
	)
    self))
 (:subimage (x y subwidth subheight)
    (let ((si (make-string (* subwidth subheight))))
	(dotimes (j subheight)
	   (replace si entity :start1 (* j subwidth)
			      :end1   (* (1+ j) subwidth)
			      :start2 (+ (* (+ y j) dim1) x)))
	(instance (class self) :init subwidth subheight si)))
  )

(defmethod single-channel-image
 (:patch-in (xs ys img)
    ;; img is stored in this pixel-image from (xs, ys)
    ;; x+(send img :width) <= (send self :width)
    (let ((ww (send self :width)) (hh (send self :height))
	  (w (send img :width)) 
	  (imgent (array-entity img))
	  p1 p2)
       (dotimes (y (send img :height))
	   (setq p1 (+ (* (+ ys y) ww) xs))
	   (replace entity imgent :start1 p1 :end1 (+ p1 w)
			:start2 (* y w)))
	))
 (:brightest-pixel () 
    (let ((maxpixel 0))
      (dotimes (i (length entity))
	  (if (> (char entity i) maxpixel) (setq maxpixel (char entity i))))
      maxpixel))
 (:darkest-pixel () 
    (let ((minpixel 256))
      (dotimes (i (length entity))
	  (if (< (char entity i) minpixel) (setq minpixel (char entity i))))
      minpixel))
 (:average-pixel ()
    (/ (float (reduce #'+ entity)) (length entity)))
 ) 


(defmethod single-channel-image
 (:amplify (rate &optional (result (send self :duplicate))
		 &aux (pict2 (array-entity result)))
    (dotimes (i (length entity))
	(setf (char pict2 i)
	      (min 255 (round (* rate (char entity i))))))
    result)
 (:compress-gray-scale (levels &optional result  &aux pict2)
     (unless result
	 (setq result (send self :duplicate))
	 (send result :name
		(format nil "~a-compressed-gray-scale~d"
			(send self :name) levels)))
     (setq pict2 (array-entity result))
     (setq levels (/ 256 levels))
     (dotimes (i (length entity))
	 (setf (char pict2 i) (/ (char entity i) levels)))
    result)
 (:lut (lut1 &optional (result (send self :duplicate)))
     (look-up entity (array-entity result) lut1)
     result)
 (:lut2 (lut1 lut2 &optional (result (send self :duplicate)))
     (look-up2 entity (array-entity result) lut1 lut2)
     result)
 ;; following methods assume the image is monochrome
 (:to24 ()
     (let ((img24 (make-string (* (send self :size) 3))))
	(dotimes (i (send self :size))
	   (let ((pix (char entity i)) (ii (* i 3)))
	      (setf (char img24 ii) pix
		    (char img24 (1+ ii)) pix
		    (char img24 (+ ii 2)) pix)))
	(instance color-image24
		:init (send self :width) (send self :height) img24)) )
 (:to32 ()
     (send (send self :to24) :to32))
 (:to16 ()
     (send (send self :to24) :to16))
 ) 

(defmethod bitmap-image 
 (:init (w h &optional imgvec) (send-super :init w h imgvec 1))
 (:pixel-hex-string (x y)
     (format nil "~d" (send self :pixel x y)))
 )



;;; color format conversion
;;; 16=rgbrgbrgb... (5bit red, 6bit green, 5bit blue)
;;; 24=RGBRGBRGBRGB...
;;; 32=aRGBaRGBaRGB...
;;;

(defun color-32to24 (img32 w h
			&optional (img24 (make-string (* w h 3)) ))
    (declare (integer w h))
    (let* ((j 0) (k 0)  )
       (declare (type :integer j k))
       (dotimes (i (* w h))
	  (setf (char img24 k) (char img32 (+ j 1))	;red
	  	(char img24 (1+ k))  (char img32 (+ j 2));green
	  	(char img24 (+ k 2)) (char img32 (+ j 3)))	;blue
	  (incf j 4)
	  (incf k 3)
	  )
       ))

(defun color-24to32 (img24 w h 
			&optional (img32 (make-string (* w h 4)) ))
    (declare (integer w h))
    (let* ((j 0) (k 0))
       (declare (type :integer j k))
       (dotimes (i (* w h))
	  (setf (char img32 (+ k 2)) (char img24 (+ j 2)) ;red
	  	(char img32 (+ k 1)) (char img24 (+ j 1)) ;green
	  	(char img32 (+ k 0)) (char img24 (+ j 0)))	;blue
	  (incf j 3)
	  (incf k 4)					;skip alpha
	  )
        img32
       ))



(defun color-24to8 (img24vec w h
			&optional (img8vec (make-string (*w h)))
				  (masks '(#xe0 #x1c #x03)))
   (declare (string img24vec img8vec) (integer w h))
   (let (mask (redshift 0) (greenshift 0) (blueshift 0)
	 redmask greenmask bluemask redmsb greenmsb bluemsb
	 redpix greenpix bluepix j)
	(declare (integer redshift greenshift blueshift
		  redmask greenmask bluemask
		  redmsb greenmsb bluemsb))
      ;; red
      (setq redmask (first masks))
      (while (not (logtest redmask 1))
	 (decf redshift) (setq redmask (ash redmask -1)))
      (setq redmsb (first masks))
      (while (not (logtest redmsb #x80)) (setq redmsb (ash redmsb 1)))
      ;; green
      (setq greenmask (second masks))
      (while (not (logtest greenmask 1))
	 (decf greenshift) (setq greenmask (ash greenmask -1)))
      (setq greenmsb (second masks))
      (while (not (logtest greenmsb #x80)) (setq greenmsb (ash greenmsb 1)))
      ;; blue
      (setq bluemask (third masks))
      (while (not (logtest bluemask 1))
	 (decf blueshift) (setq bluemask (ash bluemask -1)))
      (setq bluemsb (third masks))
      (while (not (logtest bluemsb #x80)) (setq bluemsb (ash bluemsb 1)))
      ;;
      (setq j 0)
      (dotimes (i (length img8vec))
	 (setq redpix (logand redmsb (char img24vec j))
	       greenpix (logand greenmsb (char img24vec (incf j)))
	       bluepix (logand bluemsb (char img24vec (incf j))))
	 (incf j)
	 (setf (char img8vec i)
	       (logior (ash redpix redshift)
			(ash greenpix greenshift)
			(ash bluepix blueshift))))
      img8vec))	

(defun color-24to16 (img24vec w h
			 &optional 
				img16vec 
				(masks '(#xf800 #x07e0 #x001f)))
   (declare (string img24vec img16vec) (integer w h))
   (unless img16vec (setq img16vec (make-string (* 2 w h)))) 
   (let (redmask greenmask bluemask
	(redshift 0) (greenshift 0) (blueshift 0)
	(redwidth 0) (greenwidth 0) (bluewidth 0)
	pix redpix greenpix bluepix j)
	(declare (integer redshift greenshift blueshift
		  redmask greenmask bluemask
		  redwidth greenwidth bluewidth
		  redmsb greenmsb bluemsb))
      ;; red
      (setq redmask (first masks))
      (while (not (logtest redmask 1))
	 (incf redshift) (setq redmask (ash redmask -1)))
      (while (logtest redmask 1)
	 (incf redwidth) (setq redmask (ash redmask -1)))
      ;; green
      (setq greenmask (second masks))
      (while (not (logtest greenmask 1))
	 (incf greenshift) (setq greenmask (ash greenmask -1)))
      (while (logtest greenmask 1)
	 (incf greenwidth) (setq greenmask (ash greenmask -1)))
      ;; blue
      (setq bluemask (third masks))
      (while (not (logtest bluemask 1))
	 (incf blueshift) (setq bluemask (ash bluemask -1)))
      (while (logtest bluemask 1)
	 (incf bluewidth) (setq bluemask (ash bluemask -1)))
      ;;
      ;;
      (setq j 0)
      (setq redwidth (- redwidth 8)
	    greenwidth (- greenwidth 8)
	    bluewidth (- bluewidth 8))
      (dotimes (i (/ (length img16vec) 2))
	 (setq redpix   (ash (char img24vec j) redwidth)
	       greenpix (ash (char img24vec (incf j)) greenwidth)
	       bluepix  (ash (char img24vec (incf j)) bluewidth ))
	 (incf j)
	 (setq pix (logior (ash redpix redshift)
			   (ash greenpix greenshift)
			   (ash bluepix blueshift)))
	 (sys:poke pix img16vec (* i 2) :short)
	 ; (setf (char img16vec (* i 2)) (logand pix #xff)
	 ;      (char img16vec (1+ (* i 2))) (ash pix -8))
	)
      img16vec))


(defun color-32to8 (img32vec w h
			&optional (img8vec (make-string (* w h)))
				  (masks '(#xe0 #x1c #x3)))
   (declare (string img32vec img8vec) (integer w h))
   (let (mask (redshift 0) (greenshift 0) (blueshift 0)
	 redmask greenmask bluemask redmsb greenmsb bluemsb
	 redpix greenpix bluepix
	 j k)
	(declare (integer redshift greenshift blueshift
		  redmask greenmask bluemask
		  redmsb greenmsb bluemsb j k))
      (setq redmask (first masks))
      (setq greenmask (second masks))
      (setq bluemask (third masks))
      (setq redmsb (first masks))
      (setq greenmsb (second masks))
      (setq bluemsb (third masks))
	;;
      (while (not (logtest redmsb #x80)) (setq redmsb (ash redmsb 1)))
      (while (not (logtest greenmsb #x80)) (setq greenmsb (ash greenmsb 1)))
      (while (not (logtest bluemsb #x80)) (setq bluemsb (ash bluemsb 1)))
      (while (not (eql (ash redmsb redshift) redmask)) (decf redshift))
      (while (not (eql (ash greenmsb greenshift) greenmask)) (decf greenshift))
      (while (not (eql (ash bluemsb blueshift) bluemask)) (decf blueshift))
      ;;
	(format t ";red=~d ~d  green=~d ~d  blue=~d ~d~%"
		redshift redmsb greenshift greenmsb blueshift bluemsb)
      (setq j 0)
      (dotimes (i (length img8vec))
	 (incf j 1)
         (setq bluepix  (logand bluemsb (char img32vec j))
	       greenpix  (logand greenmsb (char img32vec (incf j)))
	       redpix (logand redmsb (char img32vec (incf j))))
	 (incf j 1)
	 (setf (char img8vec i)
	       (logior (ash redpix redshift)
			(ash greenpix greenshift)
			(ash bluepix blueshift))))
      img8vec))

(defun color-24to6 (img24 width height
			&optional (img6 (make-string (* width height))))
   ;; (format t ";color-24to6: w=~d h=~d~%" width height)
   (let ((j 0) pix redpix greenpix bluepix)
     (declare (integer j pix redpix greenpix bluepix))
     (dotimes (i (* width height))
        (setq redpix  (aref img24 (+ j 0)) 
	      greenpix (aref img24 (+ j 1))
	      bluepix (aref img24 (+ j 2)) )
	(incf j 3)
        (setq pix
	      (logior (logand (ash redpix -2) #x30)
		      (logand (ash greenpix -4) #x0c)
		      (logand (ash bluepix -6) #x3)))
	(setf (aref img6 i) pix))
    img6))


(defun color-32to8x3 (img32 w h 
		      &optional (redvec (make-string (* w h)))
				(greenvec (make-string (* w h)))
				(bluevec (make-string (* w h))))
    (declare (string img32 redvec greenvec bluevec) (integer w h))
    (let (r g b (j 0))
	(declare (integer r g b))
	(dotimes (i (* w h))
	  (setf r (char img32 j)
		g (char img32 (1+ j))
		b (char img32 (+ j 2)))
	  (setf (char bluevec  i) b)
	  (setf (char greenvec i) g)
	  (setf (char redvec   i) r)
	  (incf j 4)  )
	)       
  )

(defun color-24to8x3 (img24  w h
			&optional (redvec (make-string (* w h)))
				(greenvec (make-string (* w h)))
				(bluevec (make-string (* w h))))
    (declare (string img24 redvec greenvec bluevec) (integer w h))
    (let (r g b (j 0))
	(declare (integer r g b))
	(dotimes (i (* w h))
	  (setf r (char img24 j)
		g (char img24 (1+ j))
		b (char img24 (+ j 2)))
	  (setf (char bluevec  i) b)
	  (setf (char greenvec i) g)
	  (setf (char redvec   i) r)
	  (incf j 3)  )
	)       
  )

(defun swap-rgb (img &optional (step 3))
  ; the highest byte is exchanged with the lowest byte in place.
  (let (img-string size x r g b)
     (declare (string img-string) (integer size x r g b))
     (setq img-string (array-entity img))
     (setq size (/ (length img-string) step))
     (dotimes (i size)
	(setq x (* i step))
        (setq r (aref img-string x)
	      b (aref img-string (+ x 2)))
	(setf (aref img-string (+ x 2)) r
	      (aref img-string x) b))
     img))
 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; color-image
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defmethod multi-channel-image 
 (:components () components))

;; components = number of channels, usually 3, but 4 for 32bpp
;; depth = number of bits per a pixel, 16, 24, or 32.
;; pixel-bytes = number of bytes for representing one pixel, 2, 3, 4

(defmethod color-image
 (:init (w h &optional (colorimg) (deepth 24) (num-components 3))
    (setq depth deepth)
    (setq components num-components)
    (setq pixel-bytes (/ depth 8))
    (if (null colorimg) 
	(setq colorimg (make-array (* w h pixel-bytes)
					:element-type :byte)))
    (send-super :init (* w pixel-bytes) h colorimg depth)
    self)
 (:depth () depth)
 (:byte-depth () pixel-bytes)
 (:width () (/ dim1 pixel-bytes))
 (:pixel (x y)
    (let ((xx (* x pixel-bytes)) (pix 0))
       (dotimes (i components)
	  (setq pix (logior (ash pix 8) (aref self y (+ xx i)))) )
       pix))
 (:pixel-hex-string (x y)
    (format nil "~6,6x " (send self :pixel x y)))
 (:pixel-list (x y)
    (let (r)
       (dotimes (i pixel-bytes)
	  (push (aref self y (+ i (* x pixel-bytes))) r) )
       (nreverse r)))
 (:patch-in (xs ys img)
    ;; img is stored in this color-image24 from (xs, ys)
    ;; x+(send img :width) <= (send self :width)
    (let ((ww (send self :width)) (hh (send self :height))
	  (w (send img :width)) 
	  (imgent (array-entity img))
	  p1 p2)
       (dotimes (y (send img :height))
	   (setq p1 (* depth (+ (* (+ ys y) ww) xs)))
	   (replace entity imgent
			:start1 p1	:end1 (+ p1 (* depth w))
			:start2 (* depth y w)))
	))
 (:subimage (x y subwidth subheight)
    (let ((si (make-string (* subwidth subheight pixel-bytes))))
	(dotimes (j subheight)
	   (replace si entity
		 :start1 (* j subwidth pixel-bytes)
		 :end1   (* (1+ j) subwidth pixel-bytes)
		 :start2 (+ (* (+ y j) dim1) (* pixel-bytes x)))
		)
	(instance (class self) :init subwidth subheight si)))
 ;; :halve and :double do not work for 16bpp image
 ;; these methods should be defined in the image-2d class. 
 (:halve (&optional (simage)) 	;512*512->256x256
    (let* ((swidth (/ (send self :width) 2))
	   (sheight (/ (send self :height) 2)))
	 (if (null simage)
	     (setq simage (instance class :init swidth sheight)))
	 ;;(halve-image self simage pixel-bytes)
	 (halve-image self simage) ;; inaba 2018.11.16
        simage))
 (:double (&optional (simage)) 	;256x256 -> 512*512
    (let* ((swidth (* (send self :width) 2))
	   (sheight (* (send self :height) 2)))
	 (if (null simage)
	     (setq simage (instance (class self) :init swidth sheight)))
	 ;; (double-image self simage pixel-bytes)
	 (double-image self simage) ;;  inaba 2018.11.16
	 simage))
 (:display (&optional (xw geometry:*viewsurface*) (x 0) (y 0))
    (let ((bpp (send xw :depth)))
      (case bpp
	(8 (send xw :putimage 
		    (if xpicture
			(array-entity (send self :xpicture lut))
			(array-entity self))
		    :dst-x x :dst-y y :width dim1 :height dim0) )
	(16 (send xw :putimage (send self :to16)))
	(24 (send xw :putimage (send self :to24)))
	(32 (send xw :putimage (send self :to32)))
	(t (warn "can't display with the visual of ~s bit depth" bpp))
	)
    self))
 (:component (n &optional cimg)
    ;take the nth (=0,1,2) component
    (let* ((cimgbuf) (offset  n)
	   (w (send self :width)) (h (send self :height))  )
      ;; one component image is represented by a grayscale-image object.
      (unless cimg (setq cimg (instance grayscale-image :init w h)))
      (setq cimgbuf (send cimg :entity)) 
      (dotimes (i (* w h))
	 (setf (char cimgbuf i)
		(char entity (+ (* i pixel-bytes) offset))))
      cimg))
 (:red () (send self :component 0))
 (:green () (send self :component 1))
 (:blue () (send self :component 2))
 (:pseudo2true (img8)
    (let ((size (* (send img8 :width) (send img8 :height)))
          (pix8) (entity8 (send img8 :entity)) (entity24 entity) (j 0))
       (declare (type string entity8) (type string entity24))
       (dotimes (i size)
          (setf pix8 (aref entity8 i))
	  (setf j (* i depth))
	  (dotimes (k depth)
             (setf (aref entity24 (+ j k)) pix8) ) )
       self))
 (:monochromize (&optional (mimg))
    ;; this method is valid for 24-bpp and 32-bpp images
    (unless mimg
	(setq mimg (instance grayscale-image :init (send self :width)
					(send self :height))))
    (let ((mimgbuf (send mimg :entity)))
      (dotimes (i (* (send self :width) (send self :height)))
	 (let ((pix 0) (ii (* i pixel-bytes))) (declare (integer pix ii))
	    (dotimes (j pixel-bytes) (incf pix (char entity (+ ii j))))
	    (setf (char mimgbuf i) (/ pix pixel-bytes)) ) )
      mimg))
)

(defmethod color-image16
 (:init (w h &optional img) (send-super :init w h img 16 3))
 (:pixel (x y)
    (sys:peek entity (+ (* x pixel-bytes) (* y dim1)) :short))
 (:set-pixel (x y val)
    (sys:poke val entity ((+ (* x pixel-bytes) (* y dim1)) :short)))
 (:pixel-hex-string (x y)
    (format nil "~4,4x " (send self :pixel x y)))
 (:pixel-list (x y)
    (let ((pix (send self :pixel x y)))
       (list (ldb pix 11 5) (ldb pix 5 6) (ldb pix 0 5))))
 (:to16 () self)
 (:component (n) (error "component of 16bpp image is not yet implemented"))
)

(defmethod color-image24
 (:pixel-list (x y)
    (let ((index (* pixel-bytes (+ x (* y (send self :width))))))
	(declare (integer index))
       (list (char entity index) (char entity (1+ index))
		(char entity (+ index 2)))))
 (:to24 () self)
 (:to16 ()
     (instance color-image16 :init
	 (send self :width) (send self :height)
	 (color-24to16 entity (send self :width) (send self :height))))
 (:from32 (img32)
    (color-32to24 img32 (send self :width) (send self :height) entity)
    self)
 (:to32 (&optional entity32)
    (let ((w (send self :width)) (h (send self :height)) (entity32))
       (setq entity32 (color-24to32 entity  w h))
       (instance color-image32 :init  w h entity32)))
 (:HLS (&optional (hls-image	; RGB --> HLS
			(instance (class self) :init
				(send self :width) (send self :height))))
    (let* ((w (send self :width))
	   (h (send self :height))
	   (hls-entity (send hls-image :entity))
	   pix
	   red green blue
	   hls ;; hue lightness saturation
	   (j 0))
      (dotimes (i (* w h))
	(setf blue (char entity j)
	      green (char entity (1+ j))
	      red  (char entity (+ j 2)))
	(setq hls (rgb-to-hls red green blue))
	(setf (char hls-entity j) (ldb hls 16 8)
	      (char hls-entity (1+ j)) (ldb hls 8 8)
	      (char hls-entity (+ j 2)) (ldb hls 0 8))
	(incf j pixel-bytes))
	hls-image))

)

;; color-image32
;; RGB0RGB0RGB0...

(defmethod color-image32
 (:init (w h &optional imgvec)
    (send-super :init w h imgvec 32 4)
    self)
 (:from24 (img24)
    (color-24to32 img24 (send self :width) (send self :height) entity)
    self)
 (:to24 (&optional entity24)
    (let* ( (w (send self :width)) (h (send self :height)) (entity24))
       (setq entity24 (color-32to24 entity w h))
       (instance color-image24 :init w h entity24)))
 (:to16 () (send (send self :to24) :to16))
 (:to8 (&optional entity8)
    (let* ((w (send self :width)) (h (send self :height)))
	(setq entity8 (color-32to8 entity w h entity8 
			 (x::visual-masks x::*visual-true-8*)))
	(instance grayscale-image :init w h entity8)))
 (:HLS (&optional (hls-image	; RGB --> HLS
			(instance color-image32 :init
				(send self :width) (send self :height))))
    (let* ((w (send self :width))
	   (h (send self :height))
	   (hls-entity (send hls-image :entity))
	   red green blue hls ;; hue lightness saturation
	   (j 0))
      (dotimes (i (* w h))
	(setf blue (char entity j)
	      green (char entity (1+ j))
	      red  (char entity (+ j 2)))
	(setq hls (rgb-to-hls red green blue))
	(setf (char hls-entity j) (ldb hls 16 8)
	      (char hls-entity (1+ j)) (ldb hls 8 8)
	      (char hls-entity (+ j 2)) (ldb hls 0 8))
	(incf j 4))
	hls-image))
 (:component (n 	;nth (=1,2,3) component
	      &optional (cimg (instance grayscale-image :init (send self :width)
					(send self :height))))
    (let ((cimgbuf (send cimg :entity)) (offset  n))
      (dotimes (i (send self :size))
	 (setf (char cimgbuf i) (char entity (+ (* i 4) offset))))
      cimg))
 (:red () (send self :component 3))
 (:green () (send self :component 2))
 (:blue () (send self :component 1))
 (:monochromize (&optional (mimg (instance grayscale-image :init (send self :width)
					(send self :height))))
    (let ((mimgbuf (send mimg :entity)) (j 1))
      (dotimes (i (send self :size))
	 (setf (char mimgbuf i)
		(/ (+ (char entity j)
		      (char entity (1+ j))
		      (char entity (+ j 2)))
		   3))
	 (incf j 4) )
      mimg))
 )


(export 'color-to-deep)
;; needed by gltexture.l

(defun color-to-deep (colpiximg)
   (instance color-image24 :init
                        (send colpiximg :width)
                        (send colpiximg :height)
                        colpiximg)
   )



;;; define look-up tables for gray-scale translation
;;; and vivid colors for displaying overlaied edges.
;;;

(defun copy-color-map (src dest n)
  (dotimes (i n)
    (let ((c (send src :query i)))
       (send dest :store nil (first c) (second c) (third c)))))

(defun make-ximage (rawimg &optional (lut *gray32*))
   (let (pict)
      (setq pict (send rawimg :lut lut))
      (send pict :display)
      pict ))

(defun make-colors (default-color-map)
   (if default-color-map
       (setq *image-colormap* x::*color-map*)
       (progn
	   (setq *image-colormap* 
		 (instance x::colormap :create :ncolors 256))
	   (copy-color-map x::*color-map* *image-colormap* 32)
	))
   (setq *x-gray16-lut*
	 (send *image-colormap* :define-gray-scale-LUT :gray16 16))
   (setq *x-gray32-lut*
	 (send *image-colormap* :define-gray-scale-LUT :gray32 32))
   ;;
   (setq *x-rainbow32-lut*
	 (send *image-colormap* :define-rainbow-LUT :RAINBOW32
		32 0 360 0.5 1.0))
   (setq *x-rainbow16-lut*
	 (send *image-colormap* :define-rainbow-LUT :RAINBOW16
		16 0 360 0.5 1.0))
;   (setq *x-thermo16-lut*
;	 (send *image-colormap* :define-rainbow-LUT :thermo16
;		16 0 240 0.5 1.0))
   ;;
   (setq *x-red16-lut*
	 (send *image-colormap* :define-hls-LUT :red16 16 0 0.1 0.5 1.0))
   (setq *x-green16-lut*
	 (send *image-colormap* :define-hls-LUT :green16 16 120 0.1 0.5 1.0))
   (setq *x-blue16-lut*
	 (send *image-colormap* :define-hls-LUT :blue16 16 240 0.1 0.5 1.0))
   (setq *x-color-lut*
	(send *image-colormap* :define-LUT :VIVID
		(list "black"
			(list 65535 40000 40000)	;red
			"yellow" "green" "blue"
			"orange" "lightblue" "magenta" "white")))
   ;;
   (setq *256to8*  (make-equilevel-lut 8))
   (setq *256to16* (make-equilevel-lut 16))
   (setq *256to32* (make-equilevel-lut 32))
   (setq *gray16* (concatenate-lut *256to16* *x-gray16-lut*))
   (setq *gray32* (concatenate-lut *256to32* *x-gray32-lut*))
   (setq *rainbow16* 
	 (concatenate-lut *256to16* *x-rainbow16-lut*))
   (setq *rainbow32* 
	 (concatenate-lut *256to32* *x-rainbow32-lut*))
   (setq *thermo16*
	 (concatenate-lut (reverse *256to16*)
			  (subseq  *x-rainbow32-lut* 8 24)))
   (setq *red16* (concatenate-lut *256to16* *x-red16-lut*))
   (setq *green16* (concatenate-lut *256to16* *x-green16-lut*))
   (setq *blue16* (concatenate-lut *256to16* *x-blue16-lut*))
   )


;; rubbish
#|
 (:color-pixel-image ()
    (let ((red (make-string (* dim0 dim1)))
	  (green (make-string (* dim0 dim1)))
	  (blue (make-string (* dim0 dim1))))
       (image::split-rgb entity red green blue 0)
       (instance color-pixel-image :init dim1 dim0
		red green blue)))

 (:to8 (&optional entity8)
    (let* ((w (send self :width)) (h (send self :height)))
	(unless entity8
	    (setq entity8 (make-string (* w h))))
	(color-24to8 entity entity8 w h (x::visual-masks x::*visual-true-8*))
	(instance pixel-image :init w h entity8)))
 (:to6 (&optional img6)
    (let* ((w (send self :width)) (h (send self :height)))
	(cond ((null img6) (setq img6 (instance pixel-image :init w h)))
	      ((vectorp img6) (setq img6 (instance pixel-image :init w h img6))))
	(color-24to6 entity (array-entity img6) w h)
        img6))

(defmethod color-image32
#|
 (:display (&optional (xw geometry:*viewsurface*) (lut) (x 0) (y 0))
    (send xw :putimage entity
             :dst-x x :dst-y y :width dim1
             ;; :raster-length (* dim1 4)
	     :height dim0
	     :visual x::*visual-true-24*
	     :ximage (x::create-ximage entity
			     :visual x::*visual-true-24*)))
|#
 (:pseudo2true (img8)
    (let ((w (send img8 :width)) (h (send img8 :height)) (j 0)
	  (pix8) (entity8 (send img8 :entity)) (entity32 entity))
       (declare (type string entity8) (type integer-vector entity32))
       (dotimes (i (* w h))
	  (setf pix8 (aref entity8 i))
	  (setf (char entity32 j) pix8
		(char entity32 (1+ j)) pix8
		(char entity32 (+ j 2)) pix8
		(char entity32 (+ j 3)) pix8)
	  (incf j 4))
       self)       )
  )
|#

;;


(provide :piximage "#(@)$Id$")



