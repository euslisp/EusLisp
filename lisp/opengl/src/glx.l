;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/glx.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;; glx.l

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;; on SGI, libGLX is contained in libGL.
;; (defvar libGLX (load-foreign libglx-file)) 

(setq GLX GL)

(load "glxconst.l")
(load "glxforeign.l")
