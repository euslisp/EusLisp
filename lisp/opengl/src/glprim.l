;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/glprim.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;;
;;; glprim.l -- drawing primitives.

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(eval-when (compile eval)
	   (require :gldecl "gldecl.l"))

(defvar *guard-teximage2d* t)

(defvar *tess-obj* nil)

(defvar *temp-matrix* (make-array '(4 4) :element-type :float))

(export '(*tess-obj*
	  draw-face
	  draw-body))

;; draw one face in immediate mode. -- with texture
(defun draw-face (face texture2-tbl normal-tbl)
  (let* ((vertices (cdr (send face :vertices)))
	 (normal (send face :normal))
	 (vert-list (mapcar #'(lambda (vert)
				(list vert
				      (when texture2-tbl
					    (gethash (list vert vertices) texture2-tbl))
				      (when normal-tbl
					    (gethash (list vert vertices) normal-tbl))))
			    vertices)))
    (cond ((and (send face :convexp) (not (send face :holes)))
	   (glbegin GL_POLYGON)
	   (glnormal3fv normal)
	   (mapc #'(lambda (elt)
		     (when (cadr elt)
			   (glTexCoord2fv (cadr elt)))
		     (when (caddr elt)
			   (glNormal3fv (caddr elt)))
		     (glvertex3fv (car elt)))
		 vert-list)
	   (glend))
	  (t
	   (flet ((mk-tessinfo (entry)
			       (cond ((and (cadr entry) (caddr entry))
				      (alloctessinfo (car entry) 1 (cadr entry) 1 (caddr entry)))
				     ((cadr entry)
				      (alloctessinfo (car entry) 1 (cadr entry) 0 (caddr entry)))
				     ((caddr entry)
				      (alloctessinfo (car entry) 0 (cadr entry) 1 (caddr entry)))
				     (t
				      (alloctessinfo (car entry) 0 (cadr entry) 0 (caddr entry))))))
		 (let ((holes (send face :holes))
		       (l-tessinfo (mapcar #'mk-tessinfo vert-list)))
		   (gluBeginPolygon *tess-obj*)
		   (gluNextContour *tess-obj* GLU_EXTERIOR)
		   (glNormal3fv normal)
		   (mapc #'(lambda (i) (gluTessVertex *tess-obj* i i)) l-tessinfo)
		   ;; holes
		   (when holes
			 (dolist (hole holes)
			   (let* ((h-vertices (cdr (send hole :vertices)))
				  (h-vert-list (mapcar #'(lambda (vert)
							   (list vert
								 (when texture2-tbl
								       (gethash (list vert vertices) texture2-tbl))
								 (when normal-tbl
								       (gethash (list vert vertices) normal-tbl))))
						       h-vertices))
				  (h-l-tessinfo (mapcar #'mk-tessinfo h-vert-list)))
			     (gluNextContour *tess-obj* GLU_INTERIOR)
			     (mapc #'(lambda (i) (gluTessVertex *tess-obj* i i)) h-l-tessinfo)
			     (nconc l-tessinfo h-l-tessinfo) ;hook it, to deallocated later.
			     )))
		   (gluEndPolygon *tess-obj*)
		   (mapc #'unix:free l-tessinfo) ;deallocate
		   ))))
    ))

;; function to draw body.
;; 
;; first checks if display-list is already defined for this body,
;; if found, execute the list.
;; otherwise it defines and execute the list, storing it in property list of the body
;; for later use.
(defun draw-body (vwr abody)
  (let ((lis (get abody :GL-DISPLAYLIST-ID))	
	(texture (get abody :gl-texture2))
	(normal-tbl (get abody :gl-normal))
	(material (get abody :gl-material))
	(color (get abody :color)))
    (cond ((derivedp material colormaterial) (send material :opengl))
	  ((derivedp color colormaterial) (send color :opengl))
	  ((float-vector-p color)
	      (glMaterialfv GL_FRONT_AND_BACK GL_AMBIENT color)
	      (glMaterialfv GL_FRONT_AND_BACK GL_DIFFUSE color)
	      (glMaterialfv GL_FRONT_AND_BACK GL_SPECULAR color) ))
    (cond (lis
	   ;;(warn (format nil "draw-body (display-list) ~a~%" abody))
	   ;; display list already present
	   (let ((mat (send (send abody :worldcoords) :4x4)))
	     (glpushmatrix)
	     ;; apply geometric transformation
	     (glmultmatrixf (array-entity (transpose mat *temp-matrix*)))
	     (glcalllist lis)
	     (glpopmatrix)))
	  (texture			;texture, displaylist not yet defined.
	   ;;(warn (format nil "draw-body (def display-list) ~a~%" abody))
	   (let ((newlis (glgenlists 1))
		 (w-trans (send (send abody :worldcoords) :copy-coords))
		 (texture2-tbl (get abody :gl-texturecoordinate2))
		 (do-env-map (eq (get abody :gl-texture-mapping-scheme) :environment))
		 (texobj (when (probe-extension 'gl_ext_texture_object)
				(let ((a (make-array 1 :element-type :integer)))
				 (glGenTexturesEXT 1 a)
				 (aref a 0)))))
	     ;;(warn (format nil "texobj -> ~a~%" texobj))
	     ;;(if (probe-extension 'gl_ext_texture_object)
	     ;; (format t "using extension~%")
	     ;; (format t "extension not used~%"))
	     (if (probe-extension 'gl_ext_texture_object)
		 (glBindTextureEXT GL_TEXTURE_2D texobj))
	     (glPixelStorei GL_UNPACK_ALIGNMENT 1)
	     (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_WRAP_S GL_REPEAT)
	     (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_WRAP_T GL_REPEAT)
	     (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_MAG_FILTER GL_NEAREST)
	     (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_MIN_FILTER GL_NEAREST)
	     (glTexEnvi GL_TEXTURE_ENV GL_TEXTURE_ENV_MODE GL_MODULATE)
	     ;;(glTexEnvi GL_TEXTURE_ENV GL_TEXTURE_ENV_MODE GL_DECAL)
	     (let ((image (get abody :gl-texture-image))
		   (name (get abody :gl-texture2))
		   (image-w (get abody :gl-texture-image-w))
		   (image-h (get abody :gl-texture-image-h))
		   (image-d (get abody :gl-texture-image-d)))
	       (when (not image)
		     (warn (format nil ";; loading texture image ~a~%" name))
		     (let ((img (load-texture-file name)))
		       ;;(warn (format nil ";; loaded: width: ~a height: ~a depth:~a~%"
		       ;; (car l) (cadr l) (caddr l)))
		       (setf (get abody :gl-texture-image-w) (send img :width))
		       (setf (get abody :gl-texture-image-h) (send img :height))
		       (setf (get abody :gl-texture-image-d) (send img :depth))
		       (setf (get abody :gl-texture-image) (send img :entity))
		       (setf image-w (send img :width))
		       (setf image-h (send img :height))
		       (setf image-d (send img :depth))
		       (setf image (send img :entity))))
	       (glTexImage2D GL_TEXTURE_2D 
			     0 
			     image-d
			     image-w
			     image-h
			     0 
			     (if (= image-d 3) GL_RGB GL_LUMINANCE)
			     GL_UNSIGNED_BYTE
			     image))
	     ;; bring this object to origin
	     (send abody :transform (send w-trans :inverse-transformation))
	     ;; define display list
	     (send abody :worldcoords)
	     (glnewlist newlis gl_compile)
	     (if (probe-extension 'gl_ext_texture_object)
		 (glBindTextureEXT GL_TEXTURE_2D texobj)
	       (glTexImage2D GL_TEXTURE_2D 
			     0 
			     (get abody :gl-texture-image-d)
			     (get abody :gl-texture-image-w)
			     (get abody :gl-texture-image-h)
			     0 
			     (if (=  (get abody :gl-texture-image-d) 3) GL_RGB GL_LUMINANCE)
			     GL_UNSIGNED_BYTE
			     (get abody :gl-texture-image)))
	     (glEnable GL_TEXTURE_2D)
	     ;; may turn on automatic texture coordinate generation
	     ;; xxx_f[v] series of routines won't work here (bug of eus?)
	     (cond (do-env-map
		    (glTexGeni GL_S GL_TEXTURE_GEN_MODE GL_SPHERE_MAP)
		    (glTexGeni GL_T GL_TEXTURE_GEN_MODE GL_SPHERE_MAP)
		    (glEnable GL_TEXTURE_GEN_S)
		    (glEnable GL_TEXTURE_GEN_T))
		   ((null (get abody :gl-texturecoordinate2))
		    ;; default texture mapping (projection)
		    (let* ((box (send abody :box))
			   (minp (send box :minpoint))
			   (maxp (send box :maxpoint))
			   (hstart (elt minp 0))
			   (hend (elt maxp 0))
			   (vstart (elt minp 1))
			   (vend (elt maxp 1))
			   (hspan (- hend hstart))
			   (vspan (- vend vstart)))
		      (glTexGeni GL_S GL_TEXTURE_GEN_MODE GL_OBJECT_LINEAR)
		      (glTexGeni GL_T GL_TEXTURE_GEN_MODE GL_OBJECT_LINEAR)
		      (glTexGenfv GL_S GL_OBJECT_PLANE (float-vector (/ 1.0 hspan) 0 0 (/ hstart hspan)))
		      (glTexGenfv GL_T GL_OBJECT_PLANE (float-vector 0 (/ 1.0 vspan) 0 (/ vstart vspan)))
		      (glEnable GL_TEXTURE_GEN_S)
		      (glEnable GL_TEXTURE_GEN_T)))
		   )
	     (mapc #'(lambda (face)
		       (draw-face face (unless do-env-map texture2-tbl) normal-tbl))
		   (send abody :faces))
	     (when (or do-env-map (null texture2-tbl)) ; BUG!!
		   (glDisable GL_TEXTURE_GEN_S)
		   (glDisable GL_TEXTURE_GEN_T))
	     (glDisable GL_TEXTURE_2D)
	     (glendlist)
	     ;; put back to original position
	     (send abody :transform w-trans)
	     (send abody :worldcoords)
	     (setf (get abody :GL-DISPLAYLIST-ID) newlis)
	     (draw-body vwr abody)))
	  (t				;notexture, displaylist not yet defined.
	   (let ((newlis (glgenlists 1))
		 (w-trans (send (send abody :worldcoords) :copy-coords)))
	     ;; bring this object to origin
	     (send abody :transform (send w-trans :inverse-transformation))
	     ;; define display list
	     (send abody :worldcoords)
	     (glnewlist newlis gl_compile)
	     ;;(mapc #'draw-face (send abody :faces))
	     (mapc #'(lambda (face)
		       (draw-face face nil normal-tbl))
		   (send abody :faces))
	     (glendlist)
	     ;; put back to original position
	     (send abody :transform w-trans)
	     (send abody :worldcoords)
	     (setf (get abody :GL-DISPLAYLIST-ID) newlis))
	   (draw-body vwr abody))
	  )))

(provide :glprim "@(#)$Id: glprim.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $")


