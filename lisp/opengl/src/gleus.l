;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/gleus.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;;
;;; gleus.l -- opengl euslisp stuff

(provide :gleus)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(eval-when (compile eval)
	   (require :gldecl "gldecl.l"))

(export '(probe-extension))

(defun probe-extension (ext)
  (member (intern (symbol-string ext))
	  (read-from-string (format nil "(~a) " (eglgetstring gl_extensions)))))
