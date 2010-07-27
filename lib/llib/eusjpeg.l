;;;; eusjpeg.l
;;; (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory
;;; 
;;; links libjpeg.so library and makes entries to jpeg_compress and
;;; jpeg_decompress.  Support routines defined in jmemcd.c handles
;;; stream I/O with image data stored in core.
;;; jpegmemcd.so, which needs /usr/local/lib/libjpeg.so, must be
;;; generated first.
;;;
;;; Aug 1999 allocation of memory for decompressing is optimized.
;;; Aug 1999 decompressed image is always returnd as a color-image24.

(in-package "IMAGE")

(export '(jpeg-compress jpeg-decompress 
	  read-jpeg-file write-jpeg-file))

(let ((m (load-foreign "jpegmemcd.so")))
  (defforeign jpeg_header m "JPEG_header" () :integer)
  (defforeign jpeg_decompress m "JPEG_decompress" () :integer)
  (defforeign jpeg_compress m "JPEG_compress" () :integer))


(defun jpeg-compress (rgb-image &optional (quality 50) (jpeg-buffer) )
   (let* ((w (send rgb-image :width))
	  (h (send rgb-image :height))
	  jpeg-size
	  )
      (setq rgb-image (send rgb-image :to24))
      (if (not (derivedp rgb-image color-image24))
	  (error "jpeg-compress expected 24-bit color-image, but ~s~%"
		 rgb-image))
      ;; We cannot predict exact size of the compressed file.
      ;; So, prepare a buffer for no compression.
      (if (null jpeg-buffer)
	  (setq jpeg-buffer (make-string (* w h 3))))
      (setq jpeg-size 
	    (jpeg_compress (send rgb-image :entity)  w h
	   	jpeg-buffer (length jpeg-buffer) quality))
      (list jpeg-buffer jpeg-size)
      )   )

(defun write-jpeg-file (fname rgb-image &optional (quality 80))
	;; rgb-image is either a long-pixel-image or deep-pixel-image
	;; 
    (let (r)
       (setq r (jpeg-compress rgb-image))
       (setq fname (merge-pathnames fname ".jpg"))
       (with-open-file (f fname :direction :output)
	   (unix:write f (car r) (second r)))
       fname))

;****************************************************************
;; jpeg-decompress and read-jpeg-file
;; return a color-image24 object.
;;

(defun jpeg-decompress (jpeg-image #| byte vector (string) |# )
   ;; returns a list of rgb-image, width, and height.
   ;; rgp-image might be supplied as the second argument to this function 
   (let ((width-return (integer-vector 0))
	 (height-return (integer-vector 0))
	 (components-return (integer-vector 0))
	 (image-return (integer-vector 0))
	 decomp-image-address decomp-image-string
	 total-size)
      ;; identify the jpeg output image size
      (setq total-size
	    (jpeg_header jpeg-image (length jpeg-image)
		width-return height-return components-return))
      (if (zerop total-size)
	  (return-from jpeg-decompress nil))
      ;; allocate output image memory
      (setq result-image (make-string total-size))
      (jpeg_decompress jpeg-image (length jpeg-image)
			result-image
		       width-return height-return)
      ;;
      (setq width (aref width-return 0) height (aref height-return 0))
      (instance img:color-image24 :init width height result-image)
     )   )

(defun read-jpeg-file (fname)
   (setq fname  (merge-pathnames fname ".jpg"))
   (if (probe-file fname)
	(let ((decomp-image (jpeg-decompress (read-binary-file fname))))
	   ;; put the file name in the name attribute
	   (send decomp-image :name (namestring fname))
	   decomp-image)
	nil)
    )

(defun catalog-jpeg-files (&optional (dir "."))
   (let ((xwins) (pictures) (pic) (xx))
     (dolist (f (directory dir))
	(setq pic (read-jpeg-file f))
	(when pic
		(setq xx (instance x:xwindow :create :width (send pic :width)
						:height (send pic :height)))
		(setq pic (send pic :to24))
		(swap-rgb pic)
		(send xx :putimage (pic . entity))
		(push pic pictures)
		(push xx xwins)) )
      (list xwins pictures)     )
   )

(provide :jpeg "#(@)$Id: eusjpeg.l,v 1.1.1.1 2003/11/20 07:53:25 eus Exp $")


