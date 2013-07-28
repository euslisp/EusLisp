;;;
;;;  
;;;
(setq user::*NOWDIR* (unix:getenv "PWD"))
(setq compiler::*kernel* t)

;;; change directory to "xwindow"
(unix:chdir *EUSDIR*)
(unix:chdir "lisp/xwindow")

(in-package "X")

(setq *objdir*
      (cond ((member :solaris2 *features*)  "../../SunOS5/obj/")
	    ((member :irix *features*) "../../IRIX/obj/")
	    ((member :irix6 *features*) "../../IRIX6/obj/")
	    ((member :darwin *features*) "../../Darwin/obj/")
            ((member :linux *features*)
             (cond
              ((member :x86_64 *features*)
               "../../Linux64/obj/")
              ((member :arm *features*)
               "../../LinuxARM/obj/")
              (t "../../Linux/obj/")))
	    ((member :SunOS4.1 *features*) "../../SunOS4/obj/")
	    ((member :Windows *features*) "../../Windows/obj/")
	    ((member :Windows95 *features*) "../../Win95/obj/")
	    ((member :WindowsNT *features*) "../../WinNT/obj/")
	    ((member :alpha *features*) "../../Alpha/obj/")
	    ((member :cygwin *features*) "../../Cygwin/obj/")
	))

(load "Xdecl.l")
(progn
	(comp:compile-file-if-src-newer "Xdecl.l" *objdir*)
	(comp:compile-file-if-src-newer "Xeus.l" *objdir*)
	(comp:compile-file-if-src-newer "Xgraphics.l" *objdir*)
	(comp:compile-file-if-src-newer "Xcolor.l" *objdir*)
	(comp:compile-file-if-src-newer "Xevent.l" *objdir*)
	(comp:compile-file-if-src-newer "Xpanel.l" *objdir*)
	(comp:compile-file-if-src-newer "Xitem.l" *objdir*)
	(comp:compile-file-if-src-newer "Xtext.l" *objdir*)
	(comp:compile-file-if-src-newer "Xcanvas.l" *objdir*)
	(comp:compile-file-if-src-newer "Xmenu.l" *objdir*)
	(comp:compile-file-if-src-newer "Xscroll.l" *objdir*)
	(comp:compile-file-if-src-newer "Xtop.l" *objdir*)
	(comp:compile-file-if-src-newer "Xapplwin.l" *objdir*)
)

(unix:chdir user::*NOWDIR*)
(exit 0)
