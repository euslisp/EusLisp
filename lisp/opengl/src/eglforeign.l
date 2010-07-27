;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/eglforeign.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; eglforeign.l -- GL functions in euslisp fravour (foreign functions)

(provide :eglforeign)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(require :gldecl "lisp/opengl/src/gldecl.l")

(in-package "GL")

(export '(eglGetString))
