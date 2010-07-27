;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/gl.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; gl.l -- libGL loader file

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(load "glconst.l")

#+:irix
(defvar *libgl* "/usr/lib/libGL.so")
#+:solaris2
(defvar *libgl* "/usr/users/kkonaka/src/TGS-OpenGL/lib/libGL.so")

(setq GL (load-foreign *libgl*))

(load "glforeign.l")
