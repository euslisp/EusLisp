;;;;
;;;; Xwindow interface for euslisp
;;;;	
;;;;	Copyright(c) Toshihiro MATSUI, ETL, 1988
;;;;

(require :geoclasses "geo/geoclasses.l")
(require :xdecl   "Xdecl.l")

(in-package "X")

(defvar *save-under* t)
(export '(*save-under*))



(defcstruct SetWindowAttributes
  (pixmap		:long)
  (background_pixel	:long)
  (border_pixmap	:long)
  (border_pixel		:long)
  (bit_gravity		:integer)
  (win_gravity		:integer)
  (backing_store	:integer)
  (backing_planes	:long)
  (backing_pixel	:long)
  (save_under		:integer)
  (event_mask		:long)
  (do_not_propagate_mask :long)
  (override_redirect	:integer)
  (colormap		:long)
  (cursor		:long))

(defcstruct WindowAttributes
  (x			:integer)	;x position
  (y			:integer)	;y position
  (width		:integer)
  (height		:integer)
  (border_width		:integer)
  (depth		:integer)
  (visual		:long)		;pointer to a VISUAL structure
  (root			:long)		;root window
  (class		:integer)	;InputOnly, OutputOnly
  (bit_gravity		:integer)
  (win_gravity		:integer)
  (backing_store	:integer)
  (backing_planes	:long)
  (backing_pixel	:long)
  (save_under		:integer)
  (colormap		:long)
  (map_installed	:integer)
  (map_state		:integer)
  (all_event_masks	:long)
  (your_event_mask	:long)
  (do_not_propagate_mask :long)
  (override_redirect	:integer)
  (screen		:long))

(defvar swa (instantiate SetWindowAttributes))
(defvar wa  (instantiate windowattributes))



;;
;; Xdrawable  --  Xpixmap -- Xwindow
;;

(defmethod Xdrawable
 (:init (id &optional w h gc)
    (setq gcon
	  (cond (gc gc)
		(id (instance gcontext :create :drawable id))
		(t (instance gcontext :create))))
    (setq drawable id)
    (if w (setq width w))
    (if h (setq height h))
    (setf (gethash drawable *xwindows-hash-tab*) self)
    self)
 (:drawable () drawable)
 (:flush () (Flush *display*))
 (:geometry ()
    (let ((root (instantiate c-long))
	  (x (instantiate c-int))
	  (y (instantiate c-int))
	  (width (instantiate c-int))
	  (height (instantiate c-int))
	  (border_width (instantiate c-int))
	  (depth (instantiate c-int)))
      (GetGeometry *display* drawable root x y width height
		   border_width depth)
      (list (c-long root) (c-int x) (c-int y) (c-int width) (c-int height)
	    (c-int border_width) (c-int depth))))
 (:height () (elt (send self :geometry) 4))
 (:width () (elt (send self :geometry) 3))
 (:pos () (GetWindowAttributes *display* drawable wa)
    (integer-vector (send wa :get 'x) (send wa :get 'y)))
 (:x ()
    (GetWindowAttributes *display* drawable wa)
    (send wa :get 'x))
 (:y ()
    (GetWindowAttributes *display* drawable wa)
    (send wa :get 'y))
 (:gc (&rest newgc)
    (cond ((null newgc)  gcon)
	  ((derivedp (car newgc) gcontext)
	   (setq gcon (car newgc)))
	  (t (send* gcon newgc)))) 
 (:gcid () (send gcon :gc))
 )

(defmethod Xdrawable
 (:line-width (&optional dots) (send gcon :line-width dots))
 (:line-style (&optional dash) (send gcon :line-style dash))
 (:color (&optional color)
    (cond ((or (numberp color) (stringp color) (symbolp color))
		(send gcon :foreground color) gcon)
	  ((derivedp color gcontext) (setq gcon color))
	  (t gcon) ))
 )

(defmethod Xdrawable
 (:copy-from (dw &key (width) (height) (source-x 0) (source-y 0) (x 0) (y 0))
    (unless (or width height)
        (let ((g (send self :geometry)))
           (setq width (elt g 3) height (elt g 4))))
    (CopyArea *display* (send dw :drawable) drawable (gcontext-gcid gcon)
                source-x source-y width height x y))
 (:shift (x &optional (y 0))
    (if (floatp x)
	(setq x (* (send self :width) x)))
    (if (floatp y)
	(setq y (* (send self :height) y)))
    (CopyArea *display* drawable drawable (gcontext-gcid gcon)
                0 0 (send self :width) (send self :height) x y)
    )
 (:point (x y &optional (gc gcon) )
    (DrawPoint *display* drawable (gcontext-gcid gc) x y))
 (:line (x1 y1 x2 y2 &optional (gc gcon))
    (DrawLine *display* drawable (gcontext-gcid gc) x1 y1 x2 y2))
 (:rectangle (x y width height &optional (gc gcon))
    (DrawRectangle *display* drawable (gcontext-gcid gc) x y width height))
 (:arc (x y width &optional (height width) (angle1 0.0) (angle2 2pi) (gc gcon))
    (DrawArc *display* drawable (gcontext-gcid gc)
			x y width height 
			(round (* 64 (rad2deg angle1)))
			(round (* 64 (rad2deg angle2)))))
 (:fill-rectangle (x y width height &optional (gc gcon))
    (FillRectangle *display* drawable (gcontext-gcid gc)
		 (round x) (round y)  (round width) (round height)))
 (:fill-arc (x y width &optional (height width) (angle1 0.0) (angle2 2pi) (gc gcon))
    (FillArc *display* drawable (gcontext-gcid gc)
			x y width height 
			(round (* 64 (rad2deg angle1)))
			(round (* 64 (rad2deg angle2)))))
 (:string (x y str &optional (start 0) (end (length str)) (gc gcon))
    (DrawString *display* drawable (gcontext-gcid gc) x y
		(+ (sys:address str) (* lisp::sizeof-* 2)  start)
		(- end start)))
 (:image-string (x y str &optional (start 0) (end (length str)) (gc gcon))
    (DrawImageString *display* drawable (gcontext-gcid gc) x y
		(+ (sys:address str) (* lisp::sizeof-* 2) start)
		(- end start)))
;; XImage can be regarded as a copy of pixmap at client side.
;; a pixmap in the server can be copied to ximage in the client,
;; and vice versa.
;; :getimage returns an address of ximage structure which holds
;; width, height, format, depth, and a pointer to image data, and so on.
;; you can apply x:getpixel, x:putpixel, and x:getsubimage in order to
;; access each pixel or subimage in the image.
 (:GetImage (&key (xy nil) (x 0) (y 0)
		  (width (- (send self :width) x))
		  (height (- (send self :height) y))
#-(or :alpha :irix6 :x86_64 :aarch64)
		  (mask #xffffffff)
#+(or :alpha :irix6 :x86_64 :aarch64)
		  (mask #xfffffffffffffff)
		  (format 2))
	;; #define XYBitmap      0       /* depth 1, XYFormat */
	;; #define XYPixmap      1       /* depth == drawable depth */
	;; #define ZPixmap       2       /* depth == drawable depth */
    (if xy (setq x (aref xy 0) y (aref xy 1)))
    (let* ((ximg (getimage *display* drawable x y width height mask format)) 
#-(or :alpha :irix6 :x86_64 :aarch64)
	   (pixsize (/ (sys:peek (+ ximg #x2c) :integer) 8))
#+(or :alpha :irix6 :x86_64 :aarch64)
	   (pixsize (/ (sys:peek (+ ximg #x30) :integer) 8))
#-(or :alpha :irix6 :x86_64 :aarch64)
	   (rowsize (sys:peek (+ ximg #x28) :integer))
#+(or :alpha :irix6 :x86_64 :aarch64)
	   (rowsize (sys:peek (+ ximg #x2c) :integer))
	   (xoffset (sys:peek (+ ximg 8) :integer))
	   (ximgdata (sys:peek (+ ximg #x10) :long))
	   (imgbuf (make-string (* width height pixsize))))
	;; (print xoffset)
	(dotimes (h height)
	   (replace imgbuf
		(make-foreign-string (+ ximgdata (* h rowsize pixsize)) width)
		:start1 (* h width pixsize)
		:end1 (* (1+ h) width pixsize)) )
       (DestroyImage ximg)
       imgbuf))
 (:putimage (image &key (src nil) (src-x 0) (src-y 0)
			(dst nil) (dst-x 0) (dst-y 0)
			(width) (height)
			((:gc g) gcon)
			(visual (send self :visual))
			(depth (visual-depth visual))
			(bitunit depth)
			; (case depth (8 8) (15 16) (16 16) (24 32) (32 32))
			(ximage *default-ximage*))
    (if src (setq src-x (aref src 0) src-y (aref src 1)))
    (if dst (setq dst-x (aref dst 0) dst-y (aref dst 1)))
    (cond ((derivedp image image::image-2d)
	        (unless width (setq width (send image :width)))
	        (unless height (setq height (send image :height)))
		(setq image (array-entity image)))
	  (t 	(unless width (setq width (- (send self :width) dst-x)))
		(unless height (setq height (- (send self :height) dst-y))) )
	)
    (set-ximage ximage image width height visual depth bitunit)
    (PutImage *display* drawable (gcontext-gcid g)
		ximage src-x src-y dst-x dst-y width height))
 (:putimage8to24 (image &key (src nil) (src-x 0) (src-y 0)
                        (dst nil) (dst-x 0) (dst-y 0)
                        (width (- (send self :width) dst-x))
                        (height (- (send self :height) dst-y))
                        ((:gc g) gcon) 
			&aux image32 pixel8)
    (if src (setq src-x (aref src 0) src-y (aref src 1)))
    (if dst (setq dst-x (aref dst 0) dst-y (aref dst 1)))
    ;; (setq ximage (create-ximage "" 0 0 8))  ;depth=8
    ;; (set-ximage ximage image width height)
    (setq image32 (make-array (* width height) :element-type :integer))
    (dotimes (I (* width height))
        (setq pixel8 (aref image i))
        (setf (aref image32 i) (logior pixel8 (ash pixel8 8) (ash pixel8 16))))
    (PutImage *display* drawable (gcontext-gcid g)
               image32 src-x src-y dst-x dst-y width height))
;;;
 (:draw-point (p &optional (gc gcon))
    (send self :point (round (elt p 0)) (round (elt p 1))  gc))
 (:draw-line (from to &optional (gc gcon))
    (send self :line (round (aref from 0)) (round (aref from 1))
		     (round (aref to 0))   (round (aref to 1))	gc ))
 (:draw-string (point str &optional (start 0) (end (length str)) (gc gcon))	; ?font?
    (send self :string (round (elt point 0)) (round (elt point 1)) str
		start end gc))
 (:draw-image-string (point str &optional (start 0) (end (length str))
				(gc gcon))	; ?font?
    (send self :image-string (round (elt point 0)) (round (elt point 1))
		str start end gc))
 (:draw-rectangle (point width height &optional (gc gcon))
    (send self :rectangle (round (elt point 0)) (round (elt point 1))
		(round width) (round height) gc))
 (:draw-fill-rectangle (point width height &optional (gc gcon))
    (unless (derivedp gc gcontext)
	(send gcon :foreground gc) (setq gc gcon))
    (send self :fill-rectangle (round (elt point 0)) (round (elt point 1))
		(round width) (round height) gc))
 (:draw-arc (point width
		&optional (height width) (angle1 0.0) (angle2 2pi) (gc gcon))
    (send self :arc
	(round (elt point 0)) (round (elt point 1))
	(round width) (round height) angle1 angle2 gc))
 (:draw-fill-arc (point width
		&optional (height width) (angle1 0.0) (angle2 2pi) (gc gcon))
    (send self :fill-arc
	(round (elt point 0)) (round (elt point 1))
	(round width) (round height) angle1 angle2 gc))
 (:drawline-primitive (x1 y1 x2 y2)
    (send self :line (round x1) (round y1) (round x2) (round y2)))
;;
 (:set-show-mode () (send gcon :function :copy))
 (:set-erase-mode () (send gcon  :function :clear))
 (:set-xor-mode () (send gcon :function :Xor)) ;GXxor ;extention.
 (:clear-area (&key (x 0) (y 0)
		(width (send self :width))
		(height (send self :height))
		((:gc g) gcon))
    ;; this method is only for pixmaps, which does not cleared by ClearArea.
    (send g :function :clear)	; this doesn't fill with the background color.
    (FillRectangle *display* drawable (gcontext-gcid g)  x y width height)
    (send g :function :copy))
 (:clear () (send self :clear-area)))

(defmethod Xdrawable
 (:graph (values &key (color) (max) (min) (gc gcon) (clear nil)	(step))
    (let* ((len (length values))
	   (scale)
	   v
	   (x 0) (x2 0) (y ) (y2)
	   (yinc)
	  )
     (if clear (send self :clear))
     (unless max 
	(unless (consp values) (setq values (coerce values cons)))
	(setq max (apply #'max values)))
     (unless min
	(unless (consp values) (setq values (coerce values cons)))
	(setq min (apply #'min values)))
     (setq max (float max) min (float min))
     (if color (send self :foreground color))
     (setq yinc (/ (float height) (- max min)))
     (unless step (setq step (/ (float width) (1- len))))
     ;;
     (flet ((yval (v)
		(round (- height (* yinc (- v min)))))
	    )
	(setq y (yval (elt values 0)))
        (dotimes (i (1- len))
	   (setq x2 (round (* (1+ i) step)))
	   (setq y2 (yval (elt values (1+ i))))
	   (send self :line x y x2 y2 gc)
	   (setq x x2 y y2)
	   )
        )
     ) )
 )

(defmethod Xdrawable
 (:3d-fill-rectangle (x y w h b lightedge darkedge surface
			topleft-edge	&optional (state :flat))
    (let ((org-pixel (send gcon :foreground)) color1 color2)
      (case state
	   (:up (setq color1 lightedge color2 darkedge))
	   (:down (setq color1 darkedge color2 lightedge))
	   (t  (setq color1 surface color2 surface)))
      (send gcon :foreground color2)
      (send self :fill-rectangle x y w h)
      (send gcon :foreground surface)
      (send self :fill-rectangle (+ x b) (+ y b) (- w b b) (- h b b))
      (send gcon :foreground color1)
      (send self :fill-polygon topleft-edge 1 1)
      (send gcon :foreground org-pixel)
      )
  )
)


;;
;; class XPixMap
;;


(defmethod Xpixmap 
  (:create (&key (size 256) (width size) (height width)
	         (depth (DefaultDepth *display* 0))
		 (gc *defaultgc*)
		&allow-other-keys)
     (setq drawable (CreatePixmap *display* (DefaultRootWindow *display*)
				width height depth))
     (send self :init drawable width height gc)	; send-super?
     self)
  (:create-from-bitmap-file (fname)
     (send-super :init 0)
     (let ((width (instantiate c-int))
	   (height (instantiate c-int))
	   (pixmap (instantiate c-long))
	   (x_hot (instantiate c-int))
	   (y_hot (instantiate c-int)))
        (ReadBitmapFile *display* (DefaultRootWindow *display*)
		 fname width height pixmap x_hot y_hot)
	(Flush *display*)
        (setq drawable (c-long pixmap))
	self))
  (:write-to-bitmap-file (fname)
     (WriteBitmapFile *display* fname drawable
			(send self :width) (send self :height)
			0 0)
     (Flush *display*))
  (:destroy ()
     (FreePixmap *display* drawable)
     (setq drawable nil))
;; use xdrawable's :create method to make a new instance
 ; (:init (id &optional w h)
 ;    (setq drawable id)
 ;    (send-super :init id w h)
 ;    self)
)

;; make series of pixmaps

(defun make-pixmaps (n &key (size 500) (width size) (height width)
			    (gc *blackgc*))
   (let ((maps))
     (dotimes (i n)
	(push (instance Xpixmap :create :width width :height height
					:gc gc) maps)
	(send (car maps) :gc gc))
     maps))

;; make dithered gray pixmap

(defun make-gray-pixmap (gray
		 &key (foreground *fg-pixel*)
			(background *bg-pixel*)
			(depth (defaultdepth *display* 0)))
  (let ((index (floor (* gray 32)))
	(bitmap (instantiate bit-vector 32)) pixmap)
     (dotimes (i index)
	(setf (aref bitmap (elt '( 18 22 0 4 2 6 16 20
				   9 13 27 31 25 29 11 15
				   8 12 26 30 24 28 10 14
				   1 5 19 23 17 21 3 7)
				i)) 1))
     (setq pixmap (instance xpixmap :create :width 8 :height 4))
     (setq bitmap (CreatePixmapFromBitmapData *display* (send *root* :drawable)
			bitmap 8 4 foreground background depth))
     (setf (xpixmap-drawable pixmap) bitmap)
     pixmap))


(defun make-gray-gc (gray
		 &key (foreground *fg-pixel*)
			(background *bg-pixel*)
			(depth (defaultdepth *display* 0)))
  (let ((index (floor (* gray 32)))
	(bitmap (instantiate bit-vector 32)) gray-pixmap gc)
     (setq gc (instance gcontext :create))
     (send gc :change-attributes :fill-style 1)
     (setq gray-pixmap
		(make-gray-pixmap gray :foreground foreground 
			:background background :depth depth))
     (send gc :tile gray-pixmap)
     gc))

(defun make-cleared-pixmap (width &optional (height width)
				 (pixel *bg-pixel*))
   (let ((pmap (instance xpixmap :create
			:width width :height height))
	 (fg-save))
      (setq fg-save (send pmap :gc :foreground))
      (send pmap :gc :foreground pixel)
      (send pmap :fill-rectangle 0 0 width height (send pmap :gc))
      (send pmap :gc :foreground fg-save)
      pmap))


;;
;; class Xwindow
;;

(defun eventmask-to-value (events)
   (cond ((numberp events) events)
         (t
	   (let ((mask 0) m)
	     (dolist (e events)
	        (setq m (cadr (assoc e 
		 '((:keypress 1) (:keyrelease 2) 
		   (:key 3) 
		   (:button #xc)
		   (:buttonPress 4) (:buttonRelease 8)
		   (:enterLeave #x30)
		   (:enterwindow #x10) (:leaveWindow #x20)
		   (:pointermotion #x40)
		   (:pointermotionhint #x80)
		   (:buttonMotion #x2000)
		   (:motion #x2000)
		   (:keymapstate #x4000)
		   (:exposure #x8000)
		   (:visibilityChange #x10000)
		   (:configure #x20000)
		   (:structureNotify #x20000)
		   (:resizeRedirect #x40000)
		   (:substructureNotify #x80000)
		   (:substructureRedirect #x100000)
		   (:FocusChange #x200000)
		   (:propertyChage #x400000)
		   (:colormapChage #x800000)
		   (:ownerGrabButton #x1000000)))))
	          (if m
		     (setq mask (logior mask m))
		     (warn "unknown event-mask keyword ~s~%" e)))
	          mask)) ))

(defun gravity-to-value (g)
    (if (symbolp g)
	(setq g (cdr (assoc g
		'((:forget . 0) (:northwest . 1) (:north . 2)
		  (:northeast . 3) (:west . 4) (:center . 5)
		  (:east . 6) (:southwest . 7) (:south . 8)
		  (:southeast . 9) (:static . 10))))) )
    (unless (integerp g) (error "invalid gravity name" g))
    g)


(defmethod Xwindow	;creation
 (:create (&key ((:parent par) *root*)
		(x 0) (y 0) (size 256) (width size) (height width)
		(border-width 2)
		(border *fg-pixel*)
		(save-under NIL)
		(backing-store :always)
		((:backing-pixmap backingpixmap) nil)
		(foreground)
		(background)
		(title (string (gensym  "WINDOW")))
		(event-mask #x2200f)	;button, key, motion, configure-win
		((:gc xgc)) 
		(font)
		(name)		
		(map t)
		((:visual vi) *visual*)
		(depth (visual-depth vi))
		(color-map)
		(override-redirect nil)
		(gravity :northwest)
		&allow-other-keys)
    (unless par (setq par *root*))
    (setq parent par)
    (setq visual vi)
; Sun's xserver X.V11R2 does not support backing store and save unders.
; but X.V11R3 or upper Xsun does support backing store!
    (setq save-under
         (cond  ((numberp save-under) save-under)
		((eq save-under T) 1)
		(*save-under* 1)
		(T 0)))
    (setq backing-store
	  (cond ((numberp backing-store) backing-store)
		((null *save-under*) 0)
		(t (cadr (assoc backing-store 
			'((:notUseful 0) (:whenMapped 1) (:always 2)))))))
    (setf event-mask (eventmask-to-value event-mask))
    (if (= save-under 0)
	(setq event-mask (logior event-mask 
				(eventmask-to-value 
					'(:exposure :visibilityChange)))))
    (setf (SetWindowAttributes-save_under swa)  save-under)
    (setf (SetWindowAttributes-backing_store swa)  backing-store)
    (setf (SetWindowAttributes-border_pixel swa)   border)
    (setf (SetWindowAttributes-backing_planes swa) -1)
    (setf (SetWindowAttributes-backing_pixel swa) 0)
    (setf (SetWindowAttributes-event_mask swa) event-mask)
    (setf (SetWindowAttributes-win_gravity swa)	(gravity-to-value gravity))
    (unless color-map
	(cond ((= vi *visual*)		;use parent's colormap for the default
		(setq color-map  (send parent :colormap)))
	      (t					;make private cmap
		(setq color-map (instance colormap :create :visual vi))
	        (send color-map :copy-colors *color-map* 0 32)) ))
    (setf (SetWindowAttributes-colormap swa) (send color-map :id))
    (setf (SetWindowAttributes-override_redirect swa)
	  (if override-redirect 1 0)	)
;; create
    (setq drawable
	  (CreateWindow *display*
		(send parent :drawable)
		 x y width height border-width depth 0 vi  #x2fe8 swa))
    (StoreName *display* drawable title)
    (send self :init drawable width height xgc)
    ;; gcontext is created and set to gcon.
    (let ((bgname background))
       (unless background
	   (setq background
		(if (and parent (not (eql parent *root*)))
		    (send parent :gc :background nil color-map)
		    *bg-pixel*)))	;assume we are using the default colormap
       (setq background (send color-map :get-pixel background))
       ; (format t "win=~s bg=~s cmap=~s~%" self background color-map)
       (unless (numberp background) 
          (warn "cannot :get-pixel for ~a~%" bgname)
	  (setq background *bg-pixel*)))
    (send gcon :foreground
	(cond (foreground)
	      (parent (send parent :foreground))
	      (t  *fg-pixel*))
	color-map)
    (setq bg-color background)	;bg-color must be a pixel number
    (SetWindowBackGround *display* drawable bg-color)
    (if backingpixmap
	(setq backing-pixmap
	      (instance Xpixmap :create :width width :height height)))
    (ClearWindow *display* drawable)
    (if map (MapWindow   *display* drawable))
    (if parent (send parent :associate self))
    (push self *xwindows*)
    (cond (font (send gcon :font font))
	  (parent (send gcon :font (send parent :gc :font)))
	  )
    (if name
	(send self :name name)
	(send self :name title))
    (send gcon :background bg-color color-map)
    (flush *display*)
    self)
  )

(defmethod xwindow	;relations
 (:subwindows (&optional n)   (if n (nth n subwindows) subwindows))
 (:map () 
    (send-all subwindows :map)
    (MapWindow *display* drawable))
 (:unmap ()
     (send-all subwindows :unmap)
     (UnmapWindow *display* drawable))
 (:remap ()
     (send self :unmap) (flush *display*)
     (send self :map) (flush *display*))
 (:parent () parent)
 (:associate (child)
    (pushnew child subwindows))
 (:dissociate (child)
    (setq subwindows (delete child subwindows)))
 (:reparent (par &optional (x 0) (y 0))
    (unless (integerp par) (setq par (send par :drawable)))
    (ReparentWindow *display* drawable par x y)
    (setq parent par))
 (:destroy ()
    (send-all subwindows :destroy)
    (if drawable
	(DestroyWindow *display* (prog1 drawable (setq drawable nil))))
    (when parent (send parent :dissociate self) (setq parent nil))
    (setq *xwindows* (delete self *xwindows*))
    (remhash drawable *xwindows-hash-tab*))
 )

(defmethod xwindow	;attributes
 (:attributes (&aux attr)
    (setq attr (instantiate WindowAttributes))
    (GetWindowAttributes *display* drawable attr)
    attr)
 (:event-mask () (send (send self :attributes) :get 'your_event_mask))
 (:selectinput (event-mask)
    (selectinput *display* drawable (eventmask-to-value event-mask)))
 (:visual ()
    (if visual visual (send (send self :attributes) :get 'visual)))
 (:location (&aux (attr (send self :attributes)))
    (integer-vector (send attr :get 'x) (send attr :get 'y)))
 (:size (&aux (attr (send self :attributes)))
    (integer-vector (send attr :get 'width) (send attr :get 'height)))
 (:depth () (send (send self :attributes) :get 'depth))
 (:screen () (send (send self :attributes) :get 'screen))
 (:ColorMap () (let ((color-map (gethash (send (send self :attributes) :get 'colormap)
			*xwindows-hash-tab*)))
		(unless (derivedp color-map colormap)
		    (warning-message 2 "~s's parent ~s does not have cmap; root cmap is used.~%"
				self parent)
		    (setq color-map *color-map*))
		color-map))
 (:root () (send (send self :attributes) :get 'root))	;drawable id of the root
 (:title (title)
    ;(send self :unmap)
    (StoreName *display* drawable title)
    ;(send self :map)
    (Flush *display*))
 (:background (&optional color)
    (when color
       (SetWindowBackGround *display* drawable color)
       (setq bg-color color)
       (send self :clear))
    bg-color)
 (:background-pixmap (pixmap)
    ;; (if (numberp pixmap) (setq pixmap (make-gray-pixmap pixmap)))
    (SetWindowBackGroundPixmap *display* drawable (send pixmap :drawable))
    ;; need to :clear to get  the effect to appear on the window
    (send self :clear)    )
 (:border (pixel) (SetWindowBorder *display* drawable pixel)) 
 )

(defmethod xwindow
 (:save () (send backing-pixmap :copy-from self) (flush *display*))
 (:refresh ()
   (send-super :copy-from backing-pixmap) (flush *display*))
 (:move (newx newy) (MoveWindow *display* drawable newx newy))
 (:resize (w h)
    (ResizeWindow *display* drawable w h)
    (setq width w height h))
 (:raise () (RaiseWindow *display* drawable))
 (:lower () (LowerWindow *display* drawable))
 (:write-to-bitmap-file (fname)
    (send backing-pixmap :write-to-bitmap-file fname))
 (:clear ()
    (ClearWindow *display* drawable))
 (:clear-area (&key (x 0) (y 0)	(width 0) (height 0))
    (ClearArea *display* drawable x y width height 0))
 (:set-colormap (cmap)
    (SetWindowColormap *display* drawable (cmap . cmapid)) )
 (:copy (&rest args)
    (let ((copy (instance* class :create :width (send self :width)
				:height (send self :height)
				args)))
	(send copy :copy-from self)
	copy))
 )


(defun geo::default-viewsurface (&rest args)
   (send* (instantiate xwindow)  :create args))

(defmethod Xdrawable
 (:draw-lines (points &optional (mode 0) (gc gcon))
   (let* ((n (length points)) (xp (instantiate string (* n 4))))
      (send xp :set points 0 :short)
      (DrawLines *display* drawable (gcontext-gcid gc) xp n mode)  ) )
 (:draw-polygon (points &optional (gc gcon)) 
      (send self :draw-lines (append points (list (car points))) 0 gc) )
 (:fill-polygon (points &optional(shape 0) (CoordMode 0) (gc gcon))
#| CoordMode	
    #define CoordModeOrigin     0       /* relative to the origin */
    #define CoordModePrevious   1   /* relative to previous point */
|#
     (let* (n xp) 
       (cond ((vectorp points)
		(setq xp points
		      n (/ (length points) 4)))
	     (t (setq n (length points)
		      xp (instantiate string (* 4 n)))
	        (send xp :set points 0 :short)) )
       (FillPolygon *display* drawable (gcontext-gcid gc) xp n shape
			CoordMode))
  )
 )
#|
        XFillPolyigon(display, drawable, gc, points, npoints, shape, mode)
                Display *display;
                Drawable drawable;
                GC gc;
                Xpoints *points;
                int npoints;
                int shape;
                int mode;

shape: Complex(0), Nonconvex(1), Convex(2)
mode:CoordModeOrigin(0), CoordModePrevious(1)

typedef struct {
        short x,y;
} XPint;
|#


;;;;;;; Hara Extension
(defmethod xwindow
  (:override_redirect (&optional (val 1))
	(setf (SetWindowAttributes-override_redirect swa) val)
	(changewindowAttributes *display* drawable (ash 1 9) swa)
  )
  (:save_under (&optional (val 1))
	(setf (SetWindowAttributes-save_under swa) val)
	(ChangeWindowAttributes *display* drawable (ash 1 10) swa)
  )
 (:settransientforhint ()
	(SetTransientForHint *display* drawable (send parent :drawable))
 )
 (:querypointer ()
   (let ((root (instantiate c-long))
	 (child (instantiate c-long))
	 (root_x (instantiate c-int))
	 (root_y (instantiate c-int))
	 (win_x (instantiate c-int))
	 (win_y (instantiate c-int))
	 (mask (instantiate c-int)))
     (QueryPointer *display* drawable root child root_x root_y win_x win_y
		   mask)
     (list (c-long root) (c-long child) (c-int root_x) (c-int root_y)
	   (c-int win_x) (c-int win_y) (c-int mask))
    )
 )
 (:global-pos ()
   (let ((tmp (send self :querypointer)))
      (integer-vector (- (elt tmp 2) (elt tmp 4)) (- (elt tmp 3) (elt tmp 5)))
   )
 )
)

;;;;;;;;;;;;;;;;;;
;; Handy window creation

(defun make-xwindow (&rest args)
  (send* (instantiate xwindow) :create args))

(defun find-xwindow (subname)
  (mapcan #'(lambda (w)
		(if (substringp subname (string (send w :name)))
		    (list w)))
	  *xwindows*))
	

;;;;;
(provide :Xeus "@(#)$Id$")

