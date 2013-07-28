;;;
;;;  
;;;
(setq user::*NOWDIR* (unix:getenv "PWD"))
(setq compiler::*kernel* t)

;;; change directory to "geo"
(unix:chdir *EUSDIR*)
(unix:chdir "lisp/geo")

(in-package "GEO")

(setq *objdir*
      (cond ((member :solaris2 *features*)  "../../SunOS5/obj/")
	    ((member :irix *features*) "../../IRIX/obj/")
	    ((member :irix6 *features*) "../../IRIX6/obj/")
	    ((member :darwin *features*) "../../Darwin/obj/")
	    ((member :sh4 *features*) "../../LinuxSH4/obj/")
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

(comp::compile-file-if-src-newer "geoclasses.l" *objdir*)
(comp::compile-file-if-src-newer "geopack.l" *objdir*)
(comp::compile-file-if-src-newer "geobody.l" *objdir*)
(comp::compile-file-if-src-newer "primt.l" *objdir*)
(comp::compile-file-if-src-newer "compose.l" *objdir*)
(comp::compile-file-if-src-newer "polygon.l" *objdir*)
(comp::compile-file-if-src-newer "hid.l" *objdir*)
(comp::compile-file-if-src-newer "viewing.l" *objdir*)
(comp::compile-file-if-src-newer "viewsurface.l" *objdir*)
(comp::compile-file-if-src-newer "viewport.l" *objdir*)
(comp::compile-file-if-src-newer "shadow.l" *objdir*)
(comp::compile-file-if-src-newer "bodyrel.l" *objdir*)
(comp::compile-file-if-src-newer "dda.l" *objdir*)

(unix:chdir user::*NOWDIR*)
(exit)
