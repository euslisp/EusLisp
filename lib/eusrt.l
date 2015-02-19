;;
;; common eus has been built
;;

(setq *toplevel* (symbol-function 'eustop))

;;
;; initialize help system
;;
(in-package "LISP")

#|
(defmethod symbol
 (:global (v &optional doc)
    (setq vtype 2
	  value v)
    (if doc (putprop self doc :variable-documentation))
    v)
 )
|#

#+:Solaris2
(sys::exec-module-init "cyclic")

(make-package "HELP")
(in-package "HELP")
(sys::exec-module-init "helpsub" nil)
(sys::exec-module-init "eushelp" "llib/eushelp.l")

;;
;; load xwindow interface and libraries
;;
(alloc 30000)

;; (push :X.V11R3 *features*)
(push :X.V11R4 *features*)

(unless (find-package "IMAGE")
	(make-package "IMAGE" :nicknames '("IMG" "IP")) )

(in-package "IMAGE")
(use-package "GEOMETRY") 

(in-package "X")
;; (shadow 'gc)
;; initilize Xlib interface
(when (and 
       (or (substringp "sx" (pathname-name *program-name*)) (substringp "gl" (pathname-name *program-name*)))
	(sys::exec-module-init "xforeign" "xwindow/loadx.l")
#+(and :thread :x11r6.1)
	(InitThreads)
	)
      (unless (find-symbol "*XLIB*") ; for SunOS4 with .so bug
	      (sys::exec-module-init "Xdecl")
	      (sys::exec-module-init "Xgraphics")
	      (sys::exec-module-init "Xcolor")
	      (sys::exec-module-init "Xeus")
	      (sys::exec-module-init "Xevent")
	      (sys::exec-module-init "Xpanel")
	      (sys::exec-module-init "Xitem")
	      (sys::exec-module-init "Xtext")
	      (sys::exec-module-init "Xmenu")
	      (sys::exec-module-init "Xscroll")
	      (sys::exec-module-init "Xcanvas")
	      (sys::exec-module-init "Xtop")
	      (sys::exec-module-init "Xapplwin")
	      )
	(defun xflush () (x::flush x::*display*))
	(import '(x::xobject x::gcontext x::xdrawable x::xpixmap x::xwindow
		  x::colormap))
	(push :xwindow *features*)
	(push :Xlib    *features*)
        (if (unix:isatty 0) (terpri *error-output*))
        (when (unix:getenv "DISPLAY")
	    (x::init-xwindow)
	    (when  (and (unix:getenv "USE_FILEPANEL")
			(eq (read-from-string (unix:getenv "USE_FILEPANEL")) T))
	      (setq fp (instance x::filepanel :create))
#+(and :thread :x11r6.1)
	      (progn
		  (system:make-thread 4)
		  (x::window-main-thread))
	    )
	)
;; pixel-image 
;;
	(unless (find-symbol "*XLIB*") ; for SunOS4 with .so bug
		(in-package "IMAGE")
		(sys::exec-module-init "pixword")
		(sys::exec-module-init "RGBHLS")
		(sys::exec-module-init "convolve")
		(sys::exec-module-init "piximage")
		(sys::exec-module-init "pbmfile")
		(sys::exec-module-init "image_correlation")
;;
;	        (sys::exec-module-init "eusedge" nil)
;	        (sys::exec-module-init  "edgeobj" nil)
;	        (if (fboundp 'init-step2) (init-step2 line-edge-segment curved-edge-segment boundary region))
		)
	   (in-package "USER")
	   (use-package "IMAGE")
   )

;; opengl or Mesa
;;
(when   (substringp "gl" (pathname-name *program-name*))
   (load (format nil "~a/lib/eusglrt.l" *eusdir*)))

(in-package "USER")
(sys::exec-module-init "fstringdouble")
(import 'x::xflush)
(pushnew (format nil "~a/~a/lib/" *EUSDIR* 
		   (cond ((member :solaris2 *features*) "SunOS5")
			 ((member :IRIX *features*) "IRIX")
			 ((member :Linux *features*)
                          (if (member :x86_64 *features*)
                              "Linux64" "Linux"))
			 ((member :Cygwin *features*) "Cygwin")))
	 *load-path* 
	 :test #'equal )

(setq *load-verbose* nil)
(defparameter *user* (unix:getenv "USER"))

(if (probe-file (format nil "~A/lib/irtext.l" *eusdir*))
    (load (format nil "~A/lib/irtext.l" *eusdir*)))
(if (probe-file (format nil "~A/lib/eusext.l" *eusdir*))
    (load (format nil "~A/lib/eusext.l" *eusdir*)))

;;
t
