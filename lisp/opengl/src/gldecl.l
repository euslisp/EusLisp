;;; $Header: /home/cvs/euslisp/opengl/src/gldecl.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; gldecl.l -- glviewsurface definition

(unless (find-package "GL")
    (make-package "GL") )

(in-package "GL")


(eval-when (compile eval)
   (require :glconst "lisp/opengl/src/glconst.l")
   (require :glforeign "lisp/opengl/src/glforeign.l")
   (require :gluconst "lisp/opengl/src/gluconst.l")
   (require :gluforeign "lisp/opengl/src/gluforeign.l")
   (require :glxconst   "lisp/opengl/src/glxconst.l")
   (require :glxforeign   "lisp/opengl/src/glxforeign.l")
   (require :tkconst   "lisp/opengl/src/tkconst.l")
   (require :tkforeign   "lisp/opengl/src/tkforeign.l")
;;   (require :auxconst "lisp/opengl/src/auxconst.l")
;;   (require :auxforeign "lisp/opengl/src/auxforeign.l")

   (require :glutil "lisp/opengl/src/glutil.l")
   (require :gluconst "lisp/opengl/src/gluconst.l") )


(export '(glviewsurface))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass glviewsurface :super x:xwindow #|geometry:viewsurface|#
  :slots (x y visualinfo glcon	;width height window
	))

;; class colormaterial
;; when passed to draw/glviewsurface, changes current material color.

(defclass colormaterial :super propertied-object
	:slots (name ambient  diffuse  specular
		emission  shininess transparency))

(defclass lightsource :super propertied-object
	:slots (id ambient diffuse specular
		position	;(x, y, z, w)  if w==0, the light is directional
		spot-direction spot-exponent spot-cutoff
		attenuation0	; constant-attenuation
		attenuation1	; linear-attenuation
		attenuation2	; quadratic-attenuation
		))

(defstruct linecolor
  color)

(defvar *tess-obj* nil)
(defvar *temp-matrix* (make-matrix 4 4))
(defvar *save-matrix* t)

(export '(*tess-obj*
	  draw-face
	  draw-body))


(provide :gldecl "@(#)$Id: gldecl.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $")

