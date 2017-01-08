;;;;
;;;; Xwindow interface for euslisp
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1988
;;;;
;;;; colormap, graphic context, image
;;;; version info at the bottom

(require :xdecl   "Xdecl.l")

(in-package "X")

(export '(*color-map*
	  create-ximage
	  gcval alloc-color
	  find-visual	))
#|
/*****************************************************************
 * GRAPHICS DEFINITIONS
 *****************************************************************/

/* graphics functions, as in GC.alu */

#define	GXclear			0x0		/* 0 */
#define GXand			0x1		/* src AND dst */
#define GXandReverse		0x2		/* src AND NOT dst */
#define GXcopy			0x3		/* src */
#define GXandInverted		0x4		/* NOT src AND dst */
#define	GXnoop			0x5		/* dst */
#define GXxor			0x6		/* src XOR dst */
#define GXor			0x7		/* src OR dst */
#define GXnor			0x8		/* NOT src AND NOT dst */
#define GXequiv			0x9		/* NOT src XOR dst */
#define GXinvert		0xa		/* NOT dst */
#define GXorReverse		0xb		/* src OR NOT dst */
#define GXcopyInverted		0xc		/* NOT src */
#define GXorInverted		0xd		/* NOT src OR dst */
#define GXnand			0xe		/* NOT src OR NOT dst */
#define GXset			0xf		/* 1 */

/* LineStyle */

#define LineSolid		0
#define LineOnOffDash		1
#define LineDoubleDash		2

/* capStyle */

#define CapNotLast		0
#define CapButt			1
#define CapRound		2
#define CapProjecting		3

/* joinStyle */

#define JoinMiter		0
#define JoinRound		1
#define JoinBevel		2

/* fillStyle */

#define FillSolid		0
#define FillTiled		1
#define FillStippled		2
#define FillOpaqueStippled	3

/* fillRule */

#define EvenOddRule		0
#define WindingRule		1

/* subwindow mode */

#define ClipByChildren		0
#define IncludeInferiors	1

/* SetClipRectangles ordering */

#define Unsorted		0
#define YSorted			1
#define YXSorted		2
#define YXBanded		3

/* CoordinateMode for drawing routines */

#define CoordModeOrigin		0	/* relative to the origin */
#define CoordModePrevious       1	/* relative to previous point */

/* Polygon shapes */

#define Complex			0	/* paths may intersect */
#define Nonconvex		1	/* no paths intersect, but not convex */
#define Convex			2	/* wholly convex */

/* Arc modes for PolyFillArc */

#define ArcChord		0	/* join endpoints of arc */
#define ArcPieSlice		1	/* join endpoints to center of arc */

/* GC components: masks used in CreateGC, CopyGC, ChangeGC, OR'ed into
   GC.stateChanges */

#define GCFunction              (1L<<0)
#define GCPlaneMask             (1L<<1)
#define GCForeground            (1L<<2)
#define GCBackground            (1L<<3)
#define GCLineWidth             (1L<<4)
#define GCLineStyle             (1L<<5)
#define GCCapStyle              (1L<<6)
#define GCJoinStyle		(1L<<7)
#define GCFillStyle		(1L<<8)
#define GCFillRule		(1L<<9) 
#define GCTile			(1L<<10)
#define GCStipple		(1L<<11)
#define GCTileStipXOrigin	(1L<<12)
#define GCTileStipYOrigin	(1L<<13)
#define GCFont 			(1L<<14)
#define GCSubwindowMode		(1L<<15)
#define GCGraphicsExposures     (1L<<16)
#define GCClipXOrigin		(1L<<17)
#define GCClipYOrigin		(1L<<18)
#define GCClipMask		(1L<<19)
#define GCDashOffset		(1L<<20)
#define GCDashList		(1L<<21)
#define GCArcMode		(1L<<22)

|#

(defconstant LSBFirst 0)
(defconstant MSBFirst 1)
(defparameter Endian nil)
        
(let ((a (make-array 1 :element-type :integer)))
   (setf (aref a 0) #x01234567)
   (become a string)
   (setq Endian
	 (if (eql (aref a 0) #x67) LSBFirst MSBFirst))
   ;; this should coincide with (x::bitmapbitorder x:*display*)
   )
	

(defcstruct GCValues
	(function :integer)	;/* logical operation */
	(plane-mask :long)	;/* plane mask */
	(foreground :long)	;/* foreground pixel */
	(background :long)	;/* background pixel */
	(line-width :integer)	;/* line width */
	(line-style :integer)	;/* LineSolid, LineOnOffDash, LineDoubleDash */
	(cap-style  :integer)	;/* CapNotLast, CapButt, CapRound, CapProjecting */
	(join-style :integer)	;/* JoinMiter, JoinRound, JoinBevel */
	(fill-style :integer)	;/* FillSolid, FillTiled, 
				;   FillStippled, FillOpaeueStippled */
	(fill-rule :integer)	;/* EvenOddRule, WindingRule */
	(arc-mode  :integer)	;/* ArcChord, ArcPieSlice */
	(tile      :long)	; Pixmap /* tile pixmap for tiling operations */
	(stipple   :long)	;Pixmap/* stipple 1 plane pixmap for stipping */
	(ts-x-origin :integer)	;/* offset for tile or stipple operations */
	(ts-y-origin :integer)	;
	(font        :long)	;/* default text font for text operations */
	(subwindow-mode :integer)	;/* ClipByChildren, IncludeInferiors */
	(graphics-exposures :integer) ;Bool/* boolean, should exposures be generated */
	(clip-x-origin :integer)	;/* origin for clipping */
	(clip-y-origin :integer)	;
	(clip-mask :long)	;Pixmap	/* bitmap clipping; other calls for rects */
	(dash-offset :integer)	;	/* patterned/dashed line information */
	(dashes :char)		; } XGCValues;
  )

(let* ((slots (send gcvalues :slotlist))
	(keyslots))
   (dolist (s slots)
      (push (cons (intern (symbol-pname (car s)) *keyword-package*) (cdr s))
	    keyslots))
   (setq (gcvalues . lisp::slotlist) (append slots (nreverse keyslots))))


(defvar gcval (instantiate gcvalues))
;;
;; F O N T
;;

(defun font-id (font &aux (id font))	;fontstruct/fontname to font-id
   (cond ((integerp font) font)
	 ((stringp font)
	      (setq id (LoadQueryFont *display* font))
	      (if (= id 0)
		  (prog1 0 (warn "can't load font ~S" font))
#-(or :alpha :irix6 :x86_64 :aarch64)
		  (sys:peek (+ id 4) :long)
#+(or :alpha :irix6 :x86_64 :aarch64)
		  (sys:peek (+ id 8) :long)
))))
   
(defun textdots (str &optional (font font-courb12 #|font-id|# ))
  (let ((direction (instantiate c-long))
	(font_ascent (instantiate c-int))
	(font_descent (instantiate c-int))
	(overall (make-string 16)))
  (QueryTextExtents *display* font str (length str)
		    direction font_ascent font_descent overall)
  (integer-vector (c-int font_ascent)
		  (c-int font_descent)
#-(or :i386 :alpha :x86_64 :arm)
		%(overall [ 4 ] * 256 + overall [ 5 ])
#+(or :i386 :alpha :x86_64 :arm)
		%(overall [ 5 ] * 256 + overall [ 4 ])
		)))
	#| return = (ascent descent width) |#

;;
;; image
;;

(defun create-ximage (data &key
			  (width 0)
			  (height 0)
			  (visual x:*visual*)
			  (depth (visual-depth visual))
			  (format 2)	;ZPixmap
			  (offset 0))
  ;; (format t ";; create-ximage visual=~x w=~d h=~d d=~d~%"  visual width height depth)
   (let (bitunit addr)
      (setq bitunit (case depth (8 8) (15 16) (16 16) (t 32)))
      (setq addr
	   (CreateImage *display* visual depth format	
			offset
			data width height
			bitunit 	; bitmap_mad 32?
			(* width (/ bitunit 8)	; bytes_per_line 'width'?
		)))
      #-(or :x86_64 :aarch64)
      (make-foreign-string addr 64)
      #+(or :x86_64 :aarch64)
      (make-foreign-string addr 88)
      ))

;; ximage structure
;; 0	int width, height;	size of image in pixels
;; 8	int xoffset;		num pixels to ignore at the beginning of each row
;; 12	int format;		XYBitmap=0, XYBitmap=1, or ZPixmap=2
;; 16	char *data;		pointer to image data
;; 20	int byte_order;		LSBFirst or MSBFirst
;; 24	int bitmap_unit;	8, 16, or 32
;; 28	int bitmap_bit_order;	LSBFirst or MSBFirst
;; 32	int bitmap_pad;		Scan lines are multiples of these many bits, 8, 16, 32
;; 36	int depth;		depth
;; 40	int bytes_per_line;	bytes between start of two consecutive rows
;; 44	int bits_per_pixel;	bits used for each pixel in ZPixmap (may be greater than depth)
;; 48	unsigned long red_mask;	
;; 52	unsigned long green_mask;
;; 56	unsigned long blue mask;
;; 60	char *obdata;
;; 64   struct funcs ...

(defparameter *red-mask* #x000000ff)
(defparameter *green-mask* #x0000ff00)
(defparameter *blue-mask* #x00ff0000)


#-(or :alpha :irix6 :x86_64 :aarch64)
(defun set-ximage (ximage data width height
		   &optional (visual *visual*)
			 (depth (visual-depth visual))
			 (bitunit depth))
       (sys:poke width ximage 0  :long)
       (sys:poke height ximage 4  :long)
	(sys:poke 2 ximage 12 :long)		;Zpixmap
       (sys:poke (+ (sys:address data) 8) ximage 16  :long)
       (sys:poke Endian ximage 20 :long)	;byte_order
       (sys:poke bitunit ximage 24 :long)	;bitmap_unit
       (sys:poke Endian ximage 28 :long)	;bitmap_bit_order
       (sys:poke bitunit ximage 32 :long)	;bitmap pad
       (sys:poke depth ximage 36 :long)		;depth
       (sys:poke (* width (/ bitunit 8))
		 ximage 40  :long)		;raster length
       (sys:poke depth ximage 44 :long)		;bits_per_pixel
       (sys:poke *red-mask*   ximage 48 :long)
       (sys:poke *green-mask* ximage 48 :long)
       (sys:poke *blue-mask*  ximage 48 :long)
    ximage)

#+(or :x86_64 :aarch64)
(defun set-ximage (ximage data width height
		   &optional (visual *visual*)
			 (depth (visual-depth visual))
			 (bitunit depth))
       (sys:poke width ximage 0  :integer)
       (sys:poke height ximage 4  :integer)
       (sys:poke 2 ximage 12 :integer)       ;Zpixmap
       (sys:poke (+ (sys:address data) lisp::sizeof-header-offset)
                 ximage 16 :long)            ;data
       (sys:poke Endian ximage 24 :integer)  ;byte_order
       (sys:poke bitunit ximage 28 :integer) ;bitmap_unit
       (sys:poke Endian ximage 32 :integer)  ;bitmap_bit_order
       (sys:poke bitunit ximage 36 :integer) ;bitmap_pad
       (sys:poke depth ximage 40 :integer)   ;depth
       (sys:poke (* width (/ bitunit 8))
		 ximage 44 :integer)         ;bytes_per_line
       (sys:poke depth ximage 48 :integer)   ;bits_per_pixel
       (sys:poke *red-mask*   ximage 56 :long)
       (sys:poke *green-mask* ximage 64 :long)
       (sys:poke *blue-mask*  ximage 72 :long)
    ximage)

#+(or :alpha :irix6)
(defun set-ximage (ximage data width height visual)
    (let* ((depth (visual-depth visual))
	   (bitunit (case depth (8 8) (16 16) (15 16) (t 32)))) 
       (sys:poke width ximage  :integer)
       (sys:poke height ximage 4  :integer)
       (sys:poke (+ (sys:address data) 16) ximage 16 :longlong)
       (sys:poke bitunit ximage 28 :integer)
       (sys:poke bitunit ximage 36 :integer)
       (sys:poke depth ximage 40 :integer)
       (sys:poke (* width (/ bitunit 8)) ximage 44 :integer)
       ximage))


;;;
;;; Graphic Context class
;;; 

(defun gc-attribute-to-mask (attribute-name)
   (let ((mask
          (assoc attribute-name
	   '((function . 1) (plane-mask . 2) (foreground . 4)
		(background . 8) (line-width . 16) (line-style . 32)
		(cap-style . 64) (join-style . 128) (fill-style . 256)
		(fill-rule . #,(ash 1 9)) (font . #,(ash 1 14))
		(all #xfffff)
	        (:function . 1) (:plane-mask . 2) (:foreground . 4)
		(:background . 8) (:line-width . 16) (:line-style . 32)
		(:cap-style . 64) (:join-style . 128) (:fill-style . 256)
		(:fill-rule . #,(ash 1 9)) (:font . #,(ash 1 14))
		(:all #xfffff)) )) )
       (if mask (cdr mask) 0)
	) )


(defmethod gcontext
 (:init (id)
    (setq gcid id)
    (setf (gethash gcid *xwindows-hash-tab*) self)
    self)
 (:create (&rest args
	   &key (drawable (DefaultRootWindow *display*))
		(background *bg-pixel*)
		(foreground *fg-pixel*)
		(name)
	   &allow-other-keys)
   ;; (format t "gcontext :create ~s ~%" args) 
   (send self :init (CreateGC *display* drawable 0 gcval))
   (if name (send-super :name name))
   (send* self :change-attributes args)
   self)
 (:free ()
    (freegc *display* gcid))
 (:gc () gcid)
 (:copy ()
   (let ((newgc (instance gcontext :create)))
#-(or :alpha :irix6 :x86_64 :aarch64)
     (CopyGC *display* gcid #xffffffff (send newgc :gc))
#+(or :alpha :irix6 :x86_64 :aarch64)
     (CopyGC *display* gcid #xffffffffffffffff (send newgc :gc))
     newgc))
 (:function-to-value (f)
    (if (symbolp f)
	(setq f (cdr (assoc f '(
			(:Clear . 0)(:And . 1) (:AndReverse . 2) (:Copy . 3)
			(:AndInverted . 4) (:NoOp . 5) (:Xor . 6) (:Or . 7)
			(:Nor . 8) (:Equiv . 9) (:Invert . 10)
			(:XorReverse . 11) (:CopyInverted . 12)
			(:OrInverted . 13) (:Nand . 14)
			(:Set . 15))))))
    (unless (integerp f) (error "not integer or keyword for :function"))
    f)
 (:function (x)
"0=Clear,	1=And,		2=AndReverse,	3=Copy
4=AndInverted,	5=NoOp,		6=Xor,		7=Or,
8=Nor,		9=Equiv,	10=Invert,	11=XorReverse,
12=CopyInverted,13=OrInverted,	14=Nand,	15=Set"
	(SetFunction *display* gcid (send self :function-to-value x)))
 (:foreground (&optional pix (cmap *color-map*))
   (if (stringp pix) (setq pix (send cmap :get-pixel pix)))
   (if  pix
	(SetForeGround *display* gcid pix)
	(send self :get-attribute 'foreground)))
 (:background (&optional pix (cmap *color-map*))
   (if (stringp pix) (setq pix (send cmap :get-pixel pix)))
   (if pix
	(SetBackGround *display* gcid pix)
	(send self :get-attribute 'background)))
 (:foreback (&optional fore back)
    (list (send self :foreground fore)
          (send self :background back)) )
 (:reverse ()	;exchange foreground and backgroud pixel
    (let (g f b)
      (setq g (send self :get-attributes 'foreground 'background))
      (setq f (gcvalues-foreground g)
	    b (gcvalues-background g))
      (send self :change-attributes :foreground b :background f)
      (list b f)))
 (:planemask (&optional plane-mask)
    (if plane-mask
	(SetPlanemask *display* gcid plane-mask)
	(send self :get-attribute 'plane-mask)))
 (:line-width (&optional x)
    (if x
	(send self :change-attributes :line-width x)
	(send self :get-attribute 'line-width)))
 (:line-style (&optional x)
    (if x
	(send self :change-attributes :line-style x)
	(send self :get-attribute 'line-style)))
 (:cap-style (&optional x)
    (if x
	(send self :change-attributes :cap-style x)
	(send self :get-attribute 'cap-style)))
 (:join-style (&optional x)
    (if x
	(send self :change-attributes :join-style x)
	(send self :get-attribute 'join-style)))
 (:dash (&rest x)
    (setq x (coerce x string))
    (SetDashes *display* gcid 0 x (length x)))
 (:fill-style (&optional x)
    (if x
	(send self :change-attributes :fill-style x)
	(send self :get-attribute 'fill-style)))
 (:fill-rule (&optional x)
    (if x
	(send self :change-attributes :fill-rule x)
	(send self :get-attribute 'fill-rule)))
 (:change-attributes (&rest args
			&key function plane-mask foreground background 
			     line-width line-style cap-style join-style
			     fill-style fill-rule font (cmap *color-map*)
			&allow-other-keys
			&aux (mask 0) mask1 attr val)
"&key function planemask foreground background 
 line-width line-style cap-style join-style font"
    (while args
       (setq attr (pop args) val (pop args))
       (case attr 
	  (:font (setq val (font-id val)))
	  (:function (setq val (send self :function-to-value val)))
	  (:foreground (setq val (send cmap :get-pixel val)))
	  (:background (setq val (send cmap :get-pixel val)))
	  )
       (setq mask1 (gc-attribute-to-mask attr))
       (when (/= mask1 0)
          (setq mask (logior mask mask1))
          (send gcval :set val attr))
       )
    (ChangeGC *display* gcid mask gcval)
    mask)
 (:get-attributes (&rest attrs)
    (let ((mask 0))
	(dolist (a attrs)
	   (setq mask (logior
			 (cond ((integerp a) a)
			       ((symbolp a) (gc-attribute-to-mask a))))))
        (GetGCValues *display* gcid mask gcval)
	gcval))
 (:get-attribute (attr)
    (send (send self :get-attributes attr) :get attr))
 (:font (&optional x)	; x should be a font-id
    (let (font)
	(cond ((stringp x) (setq font (font-id x)))
	      ((integerp x) (setq font x))	;font-id
	      ((null x) (return-from :font (send self :get-attribute 'font)))
	      (t (setq font (send x :font))))
	(setFont *display* gcid font)
	font))
 ;; it is necessary to change fill-style attribute to either fillStippled or
 ;; FillOpaqueStippled.
 (:tile (pixmap)	; the depth of pixmap must match with GC
    (SetTile *display* gcid (send pixmap :drawable)))
 (:stipple (pixmap)	; pixmap must be 1-bit deep
    (SetStipple *display* gcid (send pixmap :drawable)))
)

(defun make-gc-from-pixmap (pixmap)
     (setq gc (instance gcontext :create))
     (send gc :change-attributes :fill-style 1)
     (send gc :tile pixmap)
     gc)

(defun make-color-gc (fg-color &optional bg-color (cmap *color-map*))
   "(fg [bg cmap]) fg and bg may be color names such as red.
cmap is defaulted to x:*color-map*."
  (let* (fg-pixel bg-pixel)
    (setq fg-pixel
	  (cond ((consp fg-color)
		 (send* cmap :alloc fg-color))
		(fg-color
		 (send cmap :alloc fg-color))
		(t *fg-pixel*)) )
    (setq bg-pixel
	  (cond ((consp bg-color)
		 (send* cmap :alloc bg-color))
		(bg-color
		 (send cmap :alloc bg-color))
		(t *bg-pixel*)) )
    (if (and (numberp fg-pixel) (numberp bg-pixel))
	(instance gcontext :create
		:foreground fg-pixel :background bg-pixel)
	(progn (warn "color ~a or ~a cannot be allocated in ~a"
		     fg-color bg-color cmap)
		nil) ) )
   )

(provide :Xgraphics  "@(#)$Id$")

