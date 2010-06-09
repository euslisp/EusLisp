;; eus.init.l
;; When euslisp boots up, it calls 'sys:exec-module-init to initialize
;; modules. We assume the kernel of euslisp does not know what modules are
;; linked in the kernel or in the libraries.
;; On Solaris, this information is given by #pragma init, whereas,
;; on other systems, cc (or gcc) does not recognize such compiler directive.
;; So, this file provides the names of initilization entries of all the
;; modules linked.  This file is read at the boot time and substitute the
;; system::*load-entries*, which is looked up in the eusrt.l.
;; 
;; Oct/1997  RGBHLS, pixword, Xcolor are added.
;;

(	"readmacro" "object" "packsym" "common"
	"constants"
	"stream" "string" "loader" "pprint" "process"
	"hashtab" "array" "mathtran" "eusdebug" "eusforeign"
	"par" 
	;; TOPLEVEL
	"tty" "history" "toplevel"
	;; C O M P I L E R
	"builtins"
	"trans"
	"comp"
	;; G E O M E T R I C  funs
	"coordinates"
	"intersection" "geoclasses" "geopack" "geobody"
	"primt" "compose" "polygon"  "viewing" "viewport"
	"viewsurface" "hid"
	"shadow" "bodyrel"	;added Jun/2/96
	"dda"			;added Feb/25/98
	;; X W I N D O W
	"xforeign" "Xdecl" "Xeus" "Xevent"
	"Xgraphics"
	"Xpanel"
	"Xitem"
	"Xtext"
	"Xmenu"
	"Xscroll"
        "Xcanvas"
	"Xtop"
	"Xcolor"	; add Oct/28/97
	"Xapplwin"	; added by T.Matsui, May/30/96
	"eushelp" "helpsub" "cyclic"
	;;  I M A G E	
	"pixword"
	"RGBHLS"
	"convolve"
	"pbmfile"
	"piximage"
	"image_correlation"
	;; O P E N   G L
	"oglforeign" "gldecl" 
	"glconst"  "glforeign" 
	"gluconst" "gluforeign"
	"glxconst" "glxforeign"
;	"auxconst" "auxforeign"
	"eglforeign" "eglfunc" 
	"glutil" "gltexture" "glprim" "gleus" "glview" "fstringdouble")
