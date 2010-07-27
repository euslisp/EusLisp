;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/loadgl.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $

(unless (find-package "GL") (make-package "GL"))
(in-package "GL")
(use-package "GEOMETRY")

(defparameter *libgl*   (format nil "~a/SunOS4/lib/libGL.so.1.2.6"  *eusdir*))
(defparameter *libglu*  (format nil "~a/SunOS4/lib/libGLU.so.1.2.6" *eusdir*))
;(defparameter *libaux*  (format nil "~a/SunOS4/lib/libaux.so.1.2.6" *eusdir*))
(defparameter *libtk*   (format nil "~a/SunOS4/lib/libtk.so.1.2.6" *eusdir*))
(defparameter *xextlib*   "/usr/lib/X11/libXext.so.4.10")

(setq GL  (load-foreign *libgl*))
(setq GLU (load-foreign *libglu*))
;(setq AUX (load-foreign *libaux*))
(setq TK  (load-foreign *libtk*))
(setq XextLIB (load-foreign *xextlib*))
(setq GLX GL)

(load-library (format nil "~a/SunOS4/lib/libeusgl.so.0.0" *eusdir*)
	      (list "gldecl" "glconst" "glforeign"
		    "gluconst" "gluforeign" "glxconst" "glxforeign" 
		    "eglforeign" "eglfunc" 
		    "glutil" "gltexture" "glprim" "gleus" "glview")))
(setq LIBUTIL (car lisp::*loaded-modules*))

(load (format nil "~a/lisp/opengl/src/OGLforeign.l" *eusdir*))

