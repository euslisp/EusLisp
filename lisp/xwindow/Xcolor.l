;;;; Xcolor.l
;;; (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory

(export '(list-visuals 
	visual-id visual-class
	visual-red-mask visual-blue-mask visual-green-mask visual-masks
	visual-bits-per-rgb visual-depth
	best-visual))
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; visual
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun list-visuals (&optional (screen 0))
   (let (vistype (visinfo (make-string 64)) stat vis visid)
     (dolist (d '(8 15 16 24 32))
	(dotimes (i 3)
	   (setq vistype (+ i 3))
	   (setq stat
		   (x::matchVisualInfo x:*display* screen d vistype visinfo))
	   (format t "; ~d bit ~a " d
		 (case vistype (3 'pseudo) (4 'true) (5 'direct)))
	   (cond ((eql stat 0) (format t "; No~%"))
		 (t
		      (setq vis (sys:peek visinfo 0 :long)
			    visid (sys:peek visinfo 4 :long))
		      (format t "; visual=0x~x visual_id=~d ~a~%" vis visid
			(if (eql vis x:*visual*) 'default "")) 
		 ))))
  ))

(defun visual-type (name)
    (cond ((integerp name) name)
	  ((symbolp name)
	   (cdr (assoc name 
		'((:staticGray . 0)
		  (:GrayScale . 1)
		  (:StaticColor . 2)
		  (:static . 2)
		  (:PseudoColor . 3)
		  (:pseudo . 3)
		  (:TrueColor . 4)
		  (:true . 4)
		  (:DirectColor . 5)
		  (:direct . 5)))) ))
     )

(defun find-visual (type depth &optional (screen 0))
    (setq type (visual-type type))
    (unless (integerp type) (error "illegal visual type ~A" type))
    (let ((vinfo (make-array 16 :element-type :integer)))
	(if (= (MatchVisualInfo *display* screen depth type vinfo) 0)
	    nil		; specified visual not found
	    %vinfo[0])))

(defun visual-id (vis) (sys:peek (+ vis 4) :long))
(defun visual-class (vis) (sys:peek (+ vis 8) :long))
(defun visual-red-mask (vis) (sys:peek (+ vis 12) :long))
(defun visual-green-mask (vis) (sys:peek (+ vis 16) :long))
(defun visual-blue-mask (vis) (sys:peek (+ vis 20) :long))
(defun visual-masks (vis)
   (list (sys:peek (+ vis 12) :long) 
	 (sys:peek (+ vis 16) :long)
	 (sys:peek (+ vis 20) :long)))
(defun visual-bits-per-rgb (vis) (sys:peek (+ vis 24) :long))
(defun visual-depth (vis) 
   (let ((depth  (cadr (assoc vis *visuals* :test #'=))) )
	(if depth
	    depth 
	    (error ";; visual-depth: no such visual ~s registered." vis)))) 

;;    (round (/ (log (sys:peek (+ vis 28) :long)) (log 2)))

(defun best-visual (&optional
			(class-preference '(5 4 3))
			(depth-preference '(32 24 16 15 8))
			(screen 0))
   ;; choose 32, 24, 16 and 8bit visual in this order
   (let (vis (visinfo (make-string 64)) stat vis visid)
     (setq class-preference
	   (mapcar #'visual-type class-preference))
     (dolist (d depth-preference)
	(dolist (vistype class-preference)	;; direct, true, or pseudo
	   (setq stat
                 (/= (x::matchVisualInfo x:*display* screen d vistype visinfo)
		     0))
	   (when stat
		;;(format t "~d bit ~a visual is chosen for *ceremon-visual*~%"
		;;   d (case vistype (3 ':pseudo) (4 ':true) (5 ':direct)))
		(setq vis (sys:peek visinfo 0 :long))
		(return-from best-visual
		    (list vis d
			 (case vistype (3 :pseudo) (4 :true) (5 :direct))))
		)))))

;;
;; COLOR MAP and PIXEL
;;

(defcstruct XColor
  (pixel	:long)
  (red		:short)
  (green	:short)
  (blue		:short)
  (flags	:byte)
  (pad		:byte))

(defmethod XColor
 (:pixel () (xcolor-pixel self))
 (:red (&aux v)
    (setq v (XColor-red self))
    (if (< v 0) (+ 65536 v) v))
 (:green (&aux v)
    (setq v (XColor-green self))
    (if (< v 0) (+ 65536 v) v))
 (:blue (&aux v)
    (setq v (XColor-blue self))
    (if (< v 0) (+ 65536 v) v))
 (:rgb ()
    (list (send self :red) (send self :green) (send self :blue)))
 (:init (pix R G B &optional (f 7))
    (setf (XColor-pixel self) pix)
    (setf (XColor-red self) r)
    (setf (XColor-green self) g)
    (setf (XColor-blue self) b)
    (setf (XColor-flags self) f)
    self))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; COLORMAP

(defmethod colormap
 (:id () cmapid)
 (:query (pix &aux color)	;inquires RGB of a specified colormap entry
    (setq color (instance xcolor :init pix 0 0 0))
    (QueryColor *display* cmapid color)
    (send color :rgb)
    )
 (:set-window (win)
    (SetWindowColormap *display* (send win :drawable) cmapid))
 (:destroy () 
    (FreeColormap *display* cmapid))
 (:alloc (r &optional g b)
    "allocate a color in the colormap. Argument may either be a color name string
or a list of three short (not byte) integers representing red, green and blue."
    (send self :store nil r g b))
 (:store (pix r &optional g b &aux exactdef colordef status)
    (cond 
	  ((derivedp r xcolor)	(setq colordef r))
	  ((or (symbolp r) (stringp r))
	   (setq colordef (instance Xcolor :init 0 0 0 0 7)
	         exactdef (instance Xcolor :init 0 0 0 0 7))
	   (setq status (LookUpColor *display* cmapid (string r)
				 colordef exactdef))
	   (if (= status 0) (return-from :store nil))	;color not found
	   )
	  ((and (integerp r) (integerp g) (integerp b))
	   (setq colordef (instance Xcolor :init 0 r g b)))
	  (t (error "invalid color specification")))
    ;; RGB description is obtained in colordef
    (cond ((null pix)	;pixel is not specified --> allocate color cell
	   (AllocColor *display* cmapid colordef)
	   (send colordef :get 'pixel)
	   ;; colordef
	   )
	  ((integerp pix)
	   (setf (xcolor-pixel colordef) pix)
	   (if (= 0 (StoreColor *display* cmapid colordef))
	       nil
	       pix))
	  (t (error "invalid pixel"))))
 (:store-hls (pix hue lightness saturation)
    (let ((rgb (geo:hls2rgb hue lightness saturation 65536)))
	(send self :store pix (first rgb) (second rgb) (third rgb))
        )) 
  )

(defmethod colormap
 (:LUT-list () lut-list)
 (:LUT-names () (mapcar #'car lut-list))
 (:LUT (LUT) (rest (assoc LUT LUT-list)))
 (:pixel (LUT n) (aref (rest (assoc LUT LUT-list)) n))
 (:size (LUT) (length (send self :LUT LUT)))
 (:planes () planes)
 (:plane-bits () 
    (let ((p 0))
       (dotimes (i (length planes))
	  (setq p (logior p (aref planes i))))
       p))
 (:plane-shifts () 
    (let ((shifts 0))
       (while (null (logbitp shifts (aref planes 0)))
	  (incf shifts))
       shifts) )
 (:free (&optional (pix nil))
    (cond ((integerp pix)
	   (FreeColors *display* cmapid (integer-vector pix) 1
					     (integer-vector 0)) )
	  ((assoc pix LUT-list)
	   (setq pix (assoc pix LUT-list))
	   (FreeColors *display* cmapid (cdr pix) 
				 (length (cdr pix))
				 (integer-vector 0))
	   (setq lut-list (delete pix lut-list)))
	  ((or (consp pix) (vectorp pix))
	   (dotimes (i (length pix))
		(FreeColors *display* cmapid (integer-vector (elt pix i))
					     (integer-vector 0)) ))
	  ((eq pix t)	;free all read/write entries
	   (FreeColors *display* cmapid pix (length pix) 
					    (send self :plane-bits)) ) ) )
 (:allocate-private-colors (npixels &optional (nplanes 0))
    ;allocate private read/write color cells
    (setq pixels (make-array npixels  :element-type :integer))
    (setq planes (make-array nplanes  :element-type :integer))
    (let (r k kk)
       (if (= 0 (AllocColorCells *display* cmapid
			0			; non-contiguous
			planes	nplanes	pixels	npixels))
	   (progn 
		(warn "cannot allocate private colors in cmapid=~d" cmapid)
		nil)
	   (dolist (pix (concatenate cons pixels)
			(nreverse (coerce r vector)))
	      (dotimes (i (expt 2 nplanes))
		 (setq k i) (setq kk 0)
		 (dotimes (j nplanes)
		    (if (= (logand k 1) 1) (incf kk (aref planes j)))
		    (setq k (ash k -1)))
		 ;; (print kk)
		 (push (logior pix kk) r)
		 ))
	    ;; (list planes pixels)
	    )))
 (:allocate-colors (rgb-list &optional (private nil) (nplanes 0))
    (let ((lut)  (index 0) (size (length rgb-list)) (pix))
	(cond (private
		(setq lut (second (send self :allocate-private-colors size)))
		(unless lut (return-from :allocate-colors nil)))
	      (t 
		(setq lut (make-array size :element-type :integer))))
	(dolist (rgb rgb-list)
	   (cond (private
		  (if (consp rgb)
		      (send self :store (aref lut index)
			 (first rgb) (second rgb) (third rgb))
		      (send self :store (aref lut index) rgb)))
		 (t (setf pix
			  (if (consp rgb)
			      (send self :store nil
			 	  (first rgb) (second rgb) (third rgb))
			      (send self :store nil rgb)))
		    (when (null pix)
			(send self :free (subseq lut 0 index))
			(error "color allocation"))
		    (setf (aref lut index) pix))
		    )
	   (incf index))
	 lut))
 (:define-LUT (LUT-name rgb-list &optional (private nil))
    (let ((lut (assoc LUT-name LUT-list)) (new-lut))
       (cond ((null lut)
	      (setq new-lut (send self :allocate-colors rgb-list private))
	      (if (null new-lut) (error "colorcells allocation failure"))
	      (setq LUT-list  (cons (cons LUT-name new-lut) LUT-list))
	      new-lut)
	     ((= (length rgb-list) (length (cdr lut)))  (cdr lut))
		;already created
	     (t  (error "size mismatch with the LUT already created")))
    ))
 (:define-gray-scale-LUT (LUT-name levels &optional (private nil))
    (let* ((pixels)
	   (delta (/ 65536 levels))
	   (gray (1- delta)))
       (dotimes (i levels)
	 (push (list gray gray gray) pixels)
	 (incf gray delta))
       (send self :define-LUT LUT-name (nreverse pixels) private)) )
 (:define-RGB-LUT (LUT-name red &optional (green red) (blue green) private)
   (let* ((numbits (+ red green blue))
	  (numentry (expt 2 numbits))
	  (pixels)
	  (index 0))
      (setq red (expt 2 red)
	    green (expt 2 green)
	    blue (expt 2 blue))
      (dotimes (r red)
	(dotimes (g green)
	   (dotimes (b  blue)
	      (push (list
			    (round (* 65535 (/ (1+ r) (float red))))
			    (round (* 65535 (/ (1+ g) (float green))))
			    (round (* 65535 (/ (1+ b) (float blue)))))
		    pixels)
	      (incf index)) ) )
      (send self :define-LUT lut-name (nreverse pixels) private)))
 (:define-HLS-LUT (color-name count
		   hue low-lightness high-lightness saturation
		   &optional private)
    ":define-HLS-LUT name count hue low high saturation"
    (let* (rgb
	   (pixels)
	   (lightness low-lightness)
	   (linc (/ (- high-lightness low-lightness) (float count))))
      (dotimes (i count)
	(setq rgb (geo:hls2rgb hue lightness saturation 65535))
	(push rgb pixels)
	(incf lightness linc))
      (send self :define-LUT color-name (nreverse pixels) private) ) )
 (:define-RAINBOW-LUT (LUT-name 
			 &optional
			 (count 32)
			 (hue-start 0) (hue-end 360) (lightness 0.5)
			 (saturation 1.0)
			 (private nil))
    ":define-RAINBOW-LUT name (count 32) (hue1 0) (hue2 360) (lightness 0.5) (saturation 1.0)"
    (let* (rgb
	   (pixels) (hue hue-start)
	   (hinc (/ (- hue-end hue-start) (float count))))
      (dotimes (i count)
	(setq rgb (geo:hls2rgb hue lightness saturation 65535))
	(push rgb pixels)
	(incf hue hinc))
      (send self :define-LUT lut-name (nreverse pixels) private) ) )
  )


(defmethod colormap
 (:install () (installcolormap *display* cmapid))
 (:uninstall () (uninstallcolormap *display* cmapid))
 (:init (&optional id)
    (setq cmapid id
    	  LUT-list nil)
    (setf (gethash cmapid *xwindows-hash-tab*) self)
    self)
 (:create (&key (nplanes 0) (ncolors 1)
		(visual *visual*)
		(contiguous nil))
    (send self :init
	  (createcolormap *display*
		 (send *root* :drawable) visual 0))  ; AllocNone
;;    (setq planes (instantiate integer-vector nplanes))
;;    (setq pixels (instantiate integer-vector ncolors))
;;    (if (= 0 (alloccolorcells *display* cmapid (if contiguous 1 0)
;;		 planes nplanes pixels ncolors))
;;        nil	;allocation failed
;;        self)
    self)
  )

(defmethod colormap
 (:get-pixel (name)
        (if (numberp name) name (send self :alloc name)))
 (:copy-colors (cmap start &optional (end (1+ start)))
    (let (colors)
       (dotimes (i (- end start))
	  (push (send* self :alloc (send cmap :query (+ start i))) colors))
       (nreverse colors)))
 )

#|
(defun  get-light-dark-rgb (r g b)
  (list
   (list (min (* 14 (/ r 10)) *max-intensity*)
	 (min (* 14 (/ g 10)) *max-intensity*)
	 (min (* 14 (/ b 10)) *max-intensity*))
   (list (* 60 (/ r 100)) (* 60 (/ g 100)) (* 60 (/ b 100)) )
 )
)
|#

(defun  get-lighter-pixel (pix &optional (rate 1.4) (cmap *color-map*) 
				&aux rgb)
   (setq rgb (send cmap :query pix))
   (send cmap :alloc (min (round (* rate (elt rgb 0))) *max-intensity*)
		     (min (round (* rate (elt rgb 1))) *max-intensity*)
		     (min (round (* rate (elt rgb 2))) *max-intensity*))
   )

(defun  get-redish-pixel (pix &optional (rate 1.1) (cmap *color-map*) 
				&aux rgb)
   (setq rgb (send cmap :query pix))
   (send cmap :alloc (min (round (* rate (elt rgb 0))) *max-intensity*)
		     (min (round (/ (elt rgb 1) rate)) *max-intensity*)
		     (min (round (/ (elt rgb 2) rate)) *max-intensity*))
   )


(provide :Xcolor)

