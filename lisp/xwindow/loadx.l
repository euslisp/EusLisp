;;; -*- lisp -*-
;;; $Header$

(defparameter *xlib*   "/usr/lib/X11/libX11.so.4.10")
(setq XLIB (load-foreign *xlib*))
(load (format nil "~a/lisp/xwindow/Xforeign" *eusdir*))

(load-library (format nil "~a/SunOS4/lib/libeusx.so.0.0" *eusdir*)
	      (list "Xdecl" "Xeus" "Xevent" "Xgraphics" "Xpanel" 
		    "Xitem" "Xtext" "Xmenu" "Xscroll" "Xcanvas" "Xtop" 
		    "Xapplwin"))
(setq LIBEUSX (car *loaded-modules*))

(in-package "IMAGE")
(let* ((modinits (system::list-module-initializers
		  X::LIBEUSX (list "convolve" "piximage" "pbmfile")))
       (modnames))
  (dolist (m modinits)
    (format t ";~a " (first m))
    (finish-output *standard-output*)
    (funcall (second m) (second m))
    (push (first m) modnames))
  (nreverse modnames))

(in-package "X")


