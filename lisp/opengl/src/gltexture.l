;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/gltexture.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; gltexture.l -- texturefile handling support

(in-package "GL")

(export '(load-texture-file append-image make-cube-with-texture))
(eval-when (compile) (load "glconst"))

(defun transpose-rows (img)
  (let* ((ow (send img :width))
	(oh (send img :height))
	(od (send img :depth))
	(ob (send img :entity))
	(b (make-string (* ow oh od))))
    (when (not (= od 3))
	  (error "not supported depth"))
    (dotimes (x ow)
	     (dotimes (y oh)
		      (dotimes (z od)
			       (setf (elt b (+ (* (- oh y 1) ow od) (* x od) z))
				     (elt ob (+ (* y ow od) (* x od) z))))))
    (instance img:color-image24 :init ow oh b)))

(defun load-texture-file (file)
  (let* ((img (transpose-rows (image:color-to-deep (image:read-pnm-file file))))
	 (ow (send img :width))
	 (oh (send img :height))
	 (od (send img :depth))
	 (tw (ash 1 (ceiling (log ow 2))))
	 (th (ash 1 (ceiling (log oh 2))))
	 (td od))
    (when (not (= od 3))
	  (error "not supported depth"))
    (cond ((not (and (= ow tw) (= oh th)))
	   ;; rescale to boundary
	   (let ((b (make-string (* tw th td))))
	     (gluScaleImage GL_RGB ow oh GL_UNSIGNED_BYTE (send img :entity)
			    tw th GL_UNSIGNED_BYTE b)
	     (instance img:color-image24 :init tw th b)))
	  (t
	   img))))

;; concatenate color-image24 vertically
(defun append-image (&rest images)
  (when images
	(let* ((w (apply #'max (mapcar #'(lambda (img) (send img :width)) images)))
	       (h (apply #'+ (mapcar #'(lambda (img) (send img :height)) images)))
	       (d 3)			;depth, currently fixed to 3.
	       (data (make-string (* w h d)))
	       (curr-h 0))
	  ;; copy images from top to to bottom
	  (dolist (image images)
	    (let ((w1 (send image :width))
		  (h1 (send image :height))
		  (data1 (send image :entity)))
	      (dotimes (x w1)
		       (dotimes (y h1)
				(dotimes (z d)
					 (setf (elt data  (+ (* (+ y curr-h) w d) (* x d) z))
					       (elt data1 (+ (* y w1 d) (* x d) z))))))
	      (incf curr-h h1)))
	  (instance img:color-image24 :init w h data))))

(export '(make-cube-with-texture))

;;; make a cube with texture spec for each of its surfaces
(defun make-cube-with-texture (xsize ysize zsize 
				     &rest args
				     &key top bottom side0 side1 side2 side3 texture-width texture-height
				     &allow-other-keys)
  (when (or (and texture-width
		 (not (= texture-width (ash 1 (ceiling (log texture-width 2))))))
	    (and texture-height
		 (not (= texture-height (ash 1 (ceiling (log texture-height 2)))))))
	(error "make-cube-with-texture: argument error"))

  (let* ((c (apply #'user::make-cube (append (list xsize ysize zsize) args)))
	 (faces (list (car (send c :get-face nil :top))
		      (car (send c :get-face nil :bottom))
		      (car (send c :get-face nil :side 0))
		      (car (send c :get-face nil :side 1))
		      (car (send c :get-face nil :side 2))
		      (car (send c :get-face nil :side 3))))
	 (images (mapcar #'(lambda (arg)
			     (if arg
				 (gl::load-texture-file arg)
			       nil))
			 (list top bottom side0 side1 side2 side3)))
	 (image-mag-scale-w 1.0)
	 (image-mag-scale-h 1.0)
	 the-image 
	 img-coords 
	 texture2-tbl)

    (unless (remove-if #'null images)
	    (return-from make-cube-with-texture c))

    (setf the-image (apply #'gl:append-image (remove-if #'null images)))

    ;; rescale the combined texture image to 'power of 2' bounderies, if necessary
    (let* ((width (send the-image :width))
	   (height (send the-image :height))
	   (depth (send the-image :depth))
	   (data (send the-image :entity))
	   (owidth (if texture-width texture-width (ash 1 (ceiling (log width 2)))))
	   (oheight (if texture-height texture-height (ash 1 (ceiling (log height 2)))))
	   (odepth depth)
	   (odata data))

      (when (or (not (= height oheight)) (not (= width owidth)))
	    (warn ";; rescaling image to ~ax~a (original: ~ax~a)~%" owidth oheight width height)
	    (setf odata (make-string (* owidth oheight depth)))
	    (setf image-mag-scale-w (/ (float owidth) (float width)))
	    (setf image-mag-scale-h (/ (float oheight) (float height)))
	    (let ((fmt (if (= depth 3) gl:GL_RGB gl:GL_LUMINANCE)))
	      (gluScaleImage fmt width height gl:GL_UNSIGNED_BYTE data
				owidth oheight gl:GL_UNSIGNED_BYTE odata))
	    (setf the-image (instance img::color-image24 :init owidth oheight odata)))

    (setf img-coords
	  (let ((line-h 0)
		(width (send the-image :width))
		(height (send the-image :height)))
	    (mapcar #'(lambda (imgd)
			(when imgd
			      (let ((w (* image-mag-scale-w (send imgd :width)))
				    (h (* image-mag-scale-h (send imgd :height))))
				(prog1 (list 
					(float-vector (/ (float 0) width) 
						      (/ (float (+ line-h 0)) height))
					(float-vector (/ (float w) width) 
						      (/ (float (+ line-h 0)) height)) 
					(float-vector (/ (float w) width) 
						      (/ (float (+ line-h h)) height))
					(float-vector (/ (float 0) width) 
						      (/ (float (+ line-h h)) height))
					)
				  (incf line-h h)))))
		    images)))

    (setf texture2-tbl (make-hash-table :test #'equal))

    (dotimes (i 6)
	     (let* ((face (elt faces i))
		    (coordlis (elt img-coords i))
		    (vertices (cdr (send face :vertices))))
	       (when coordlis
		     (dotimes (vn 4)
			      (setf (gethash (list (elt vertices vn) vertices) texture2-tbl)
				    (elt coordlis vn))))))

    (setf (get c :gl-texture2) (symbol-string (gensym "make-cube-with-texture-")))
    (setf (get c :gl-texture-image-w) (send the-image :width))
    (setf (get c :gl-texture-image-h) (send the-image :height))
    (setf (get c :gl-texture-image-d) (send the-image :depth))
    (setf (get c :gl-texture-image) (send the-image :entity))
    (setf (get c :gl-texturecoordinate2) texture2-tbl)
    c)))

(provide :gltexture "@(#)$Id: gltexture.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $")


