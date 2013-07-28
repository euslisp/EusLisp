;;;
;;;  
;;;
(setq user::*NOWDIR* (unix:getenv "PWD"))
(setq compiler::*kernel* t)

;;; change directory to "xwindow"
(unix:chdir *EUSDIR*)
(unix:chdir "lisp/image")

(unless (find-package "IMAGE")
	(make-package "IMAGE" :nicknames '("IMG" "IP"))
	(in-package "IMAGE")
	(use-package "GEOMETRY")  )

(in-package "IMAGE")

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

(progn
	(comp:compile-file-if-src-newer "pbmfile.l" *objdir*)
	(comp:compile-file-if-src-newer "piximage.l" *objdir*)
)

(unix:chdir user::*NOWDIR*)
(exit 0)
