;; Xdecl.l
;; Class and constant declarations for Xwindow interface
;; formerly, Xclasses.l and Xconst.l
;; Copyright 1993, Toshihiro Matsui, Electrotechnical Laboratory
;;
;; May 1994, Solaris2
;;

(eval-when (compile eval)
   (unless (find-package "X")
	(make-package "X") ) )

(in-package "X")

(export '(xobject xcolor colormap gcontext xdrawable xpixmap xwindow))

(export '(panel-item 
	  button-item menu-button-item slider-item joystick-item
	  text-item choice-item))

(export '(Xscroll-bar Xhorizontal-scroll-bar))

(export '(canvas graph-canvas
	  characterWindow textwindow textwindowstream
	  bufferTextWindow ScrollTextWindow))

(export '(panel menu-panel))

(export  '(FileDialog FilePanel TextViewPanel ConfirmPanel eustop-win))

;;;;;; Hara extention
(export '(menubar-panel bitmap-button-item)) 

(export '(
	*display* *xwindows* *xwindows-hash-tab*
	*visual* *visuals*
	*visual-pseudo-8* *visual-true-8* *visual-direct-8*
	*visual-true-15* *visual-direct-15*
	*visual-true-16* *visual-direct-16*
	*visual-true-24* *visual-direct-24*
	*root* *screen* *screen-no* *depth*
       *blackpixel* *whitepixel* *fg-pixel* *bg-pixel*
       *whitegc* *blackgc* *defaultGC*
       *gray25-pixmap* *gray50-pixmap* *gray75-pixmap* 
       *gray25-bitmap* *gray50-bitmap* *gray75-bitmap*
       *gray25-gc* *gray50-gc* *gray75-gc* 
	*eustop-win* *shell-window*
       ;; funcs
         init-xwindow  make-pixmaps make-cleared-pixmap
       make-default-cmap
       make-color-gc
       make-xwindow find-xwindow
       ))

(export '(
	font-cour8	font-cour10	font-cour12 
	font-cour14 	font-cour18
 	font-courb12 	font-courb14 	font-courb18	font-courb24
	font-timesb12	font-timesb14	font-timesb18	font-timesb24
	font-times10    font-times12
	font-lucidasans-bold-12 font-lucidasans-bold-14
	font-helvetica-bold-12 font-helvetica-12 font-a14))

(defvar  *display*)
(defvar  *visual*)
(defvar *visual-pseudo-8*)
(defvar *visual-true-8*)
(defvar *visual-direct-8*)
(defvar *visual-true-15*)
(defvar *visual-direct-15*)
(defvar *visual-true-16*)
(defvar *visual-direct-16*)
(defvar *visual-true-24*)
(defvar *visual-direct-24*)

(defvar  *root*)
(defvar  *screen*)
(defvar  *screen-no*)
(defvar  *blackpixel*)
(defvar  *whitepixel*)
(defvar  *whitegc*)
(defvar  *blackgc*)
(defvar  *defaultGC*)
(defvar  *fg-pixel*)
(defvar  *bg-pixel*)
(defvar  *gray25-pixmap*)
(defvar  *gray50-pixmap*)
(defvar  *gray75-pixmap*)
(defvar  *gray25-gc*)
(defvar  *gray50-gc*)
(defvar  *gray75-gc*)
(defvar  *color-map*)

(defparameter *xwindows* nil)
(defparameter *xwindows-hash-tab* (make-hash-table :size 20))
(defparameter *visuals* nil)

(defvar	font-cour8)
(defvar	font-cour10)
(defvar	font-cour12)
(defvar font-cour14)
(defvar	font-cour18)
(defvar	font-courb12)
(defvar	font-courb14)
(defvar	font-courb18)
(defvar	font-courb24)
(defvar font-lucidasans-bold-12)
(defvar font-lucidasans-bold-14)
(defvar font-helvetica-bold-12)
(defvar font-helvetica-12)
(defvar font-a14)
(defvar font-times10)
(defvar font-times12)
(defvar font-timesb12)
(defvar font-timesb14)
(defvar font-timesb18)
(defvar font-timesb24)

(defvar *save-under*)
(defvar *depth*)
(defvar *default-ximage*)
(defvar *gray-gc*)
(defvar *gray-pixmap*)
(defvar *whitegc* nil)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; propertied-object
;;   +-- colormap
;;   +-- geo:viewsurface
;;	   +-- Xobject
;;		+-- gcontext
;;		+-- Xdrawable
;;			+--- Xpixmap
;;			+--- Xwindow
;;				+--- panel
;;				|	+--- menubar-panel
;;				|       +--- menu-panel
;;				+--- canvas
;;				+--- panel-item
;;				|	+--- text-item
;;				|	+--- slider-item	
;;				|	+--- choice-item
;;				|	+--- joystick-item
;;				|	+--- button-item
;;				|		+-- menu-button-item
;;				|		+-- bitmap-button-item
;;				+--- Xscroll-bar
;;				|         +--- Xhorizontal-scroll-bar
;;				+--- CharacterWindow
;;					+--TextWindow
;;					      +-- BufferTextWindow
;;						      +-- ScrollTextWindow
;;


(defclass Xobject :super geometry:viewsurface
		  :slots (display))

(defclass colormap :super propertied-object
	  :slots (cmapid planes pixels LUT-list))

(defclass gcontext :super Xobject :slots (gcid GCValues))

(defclass Xdrawable :super Xobject
	    :slots (drawable	; X's drawable resource ID
		    (gcon :forward t)
		    bg-color
		    width height))

(defclass Xpixmap :super Xdrawable)

(defclass Xwindow :super Xdrawable
		:slots
		    (parent subwindows visual 
		     backing-pixmap event-forward))

;; Xpanel.l

(defclass panel :super xwindow
	 :slots (pos items fontid
		 rows columns	;total number of rows and columns
		 next-x next-y
		 item-width item-height
		 dark-edge-color light-edge-color
		 topleft-edge-polygon
		 active-menu
))

;; Xcanvas.l

(defclass canvas :super xwindow
		 :slots (topleft bottomright buttonActive
			 menu))

;; panel items

(defclass panel-item :super xwindow
	:slots (pos
		notify-object notify-method
		fontid label labeldots
		buttonPressed))

(defclass button-item :super panel-item
	:slots (submenu
		activeColor 3D-State
		dark-edge-color light-edge-color
		topleft-edge-polygon
		))

(defclass text-item :super panel-item
	:slots (textwin) )
  )

(defclass slider-item :super panel-item
	:slots (min-value max-value value
		minlabel maxlabel valueformat
		bar-x bar-y bar-width bar-height valuedots label-base
		nob-x nob-moving 
	        charwidth
		continuous-notify) )

(defclass menu-button-item :super button-item
	:slots (items item-dots item-labels
		charwidth charheight
		menu-window
		window-pos
		high-light))

(defclass choice-item :super panel-item 
	:slots (choice-list active-choice transient-choice
		choice-pos button-size))

(defclass joystick-item :super panel-item
	:slots (stick-size min-x min-y max-x max-y
		center-x center-y stick-x stick-y
		value-x value-y
		stick-return stick-grabbed
		fraction-x fraction-y follow-move))


;; Xmenu.l

(defclass menu-panel :super panel
        :slots (height-offset menu-buttons)
)


;; Xscroll.l

(defclass Xscroll-bar :super xwindow
	:slots (arrow-length handle-pos handle-length
		verticalp
		handle-grabbed))

(defclass Xhorizontal-scroll-bar :super xscroll-bar)


;; Xtext.l

(defclass CharacterWindow :super xwindow
	  :slots (fontid
		  charwidth charheight charascent
		  win-row-max win-col-max
		  x y))

(defclass textWindow :super CharacterWindow
	  :slots (win-row win-col	;physical current position in window
		  charbuf	; for charcode conversion
		  keybuf keycount	;for key input
		  echo
		  show-cursor cursor-on ;boolean
		  ;;;	kill delete	;control character
		  notify-object notify-method
		  buttonActive
		  ))

(defclass BufferTextWindow :super textWindow
	  :slots (linebuf expbuf max-line-length selected-pos))


(defclass ScrollTextWindow :super BufferTextWindow
	  :slots (row col		;logical current position in the buffer
		  top-row top-col 	;display-starting position
		  scroll-bar-window
		  horizontal-scroll-bar-window
		  selected-line
		  ))

(defclass textWindowStream :super stream
		:slots (textwin))


;;;;;;;;;;;;;;;; Hara 

(defclass menubar-panel :super panel
        :slots ()
)

(defclass bitmap-button-item :super button-item
        :slots (pixmap-id bitmap-width bitmap-height)
)

;;;;;;;;;;;;;;;;;;;;;;;;;;
(defconstant	NoEventMask		0)
(defconstant	KeyPressMask		#,(ash 1 0))  
(defconstant	KeyReleaseMask		#,(ash 1 1))  
(defconstant	ButtonPressMask		#,(ash 1 2))
(defconstant	ButtonReleaseMask	#,(ash 1 3))
(defconstant	EnterWindowMask		#,(ash 1 4))
(defconstant	LeaveWindowMask		#,(ash 1 5))
(defconstant	PointerMotionMask	#,(ash 1 6))
(defconstant	PointerMotionHintMask	#,(ash 1 7))
(defconstant	Button1MotionMask	#,(ash 1 8))
(defconstant	Button2MotionMask	#,(ash 1 9))
(defconstant	Button3MotionMask	#,(ash 1 10) )
(defconstant	Button4MotionMask	#,(ash 1 11) )
(defconstant	Button5MotionMask	#,(ash 1 12) )
(defconstant	ButtonMotionMask	#,(ash 1 13) )
(defconstant	KeymapStateMask		#,(ash 1 14))
(defconstant	ExposureMask		#,(ash 1 15) )
(defconstant	VisibilityChangeMask	#,(ash 1 16) )
(defconstant	StructureNotifyMask	#,(ash 1 17) )
(defconstant	ResizeRedirectMask	#,(ash 1 18) )
(defconstant	SubstructureNotifyMask	#,(ash 1 19) )
(defconstant	SubstructureRedirectMask #,(ash 1 20) )
(defconstant	FocusChangeMask		#,(ash 1 21) )
(defconstant	PropertyChangeMask	#,(ash 1 22) )
(defconstant	ColormapChangeMask	#,(ash 1 23) )
(defconstant	OwnerGrabButtonMask	#,(ash 1 24) )

(defcarray c-long :long)
(defcarray c-int :integer)
;;;;;;;

(provide :xdecl "@(#)$Id: Xdecl.l,v 1.1.1.1 2003/11/20 07:46:34 eus Exp $")

