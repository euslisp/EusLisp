;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/glu.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; glu.l -- libGLU loader file.

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(load "gluconst.l")

#+:irix
(defvar *libglu* "/usr/lib/libGLU.so")
#+:solaris2
(defvar *libglu* "/usr/users/kkonaka/src/TGS-OpenGL/lib/libGLU.so")

(setq GLU (load-foreign *libglu*))

(load "gluforeign.l")
