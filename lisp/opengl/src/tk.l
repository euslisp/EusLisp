;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/tk.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;; tk.l

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(load "tkconst.l")

(setq TK (load-foreign "../lib/libtk.so"))

(load "tkforeign.l")
