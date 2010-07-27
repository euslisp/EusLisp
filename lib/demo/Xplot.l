;; xplot
;; plot points on a xwindow
;; 1990(c) MATSUI T., ETL

(defvar maxcolors 32)

(defvar xv)
(defvar cmap)
(defvar bgcmap)
(defvar point (float-vector 0 0 0))
(defvar pixels)
(defvar rectsize 0.01)

#|
(defun named-color-pixel (color-name 
			  &optional (cmap (x:defaultcolormap x:disp 0)))
   (let ((color1 (instance xcolor :init 0 0 0 0))
	 (color2 (instance xcolor :init 0 0 0 0)))
      (x:allocnamedcolor x:disp cmap color-name color1 color2)
      (send color1 :get-pixel))  )
|#

;; sekiguti coordinates (0 0)..(1 1) to NDC (-1 -1)..(1 1) conversion
(defun sek2ndc (x y v)
    %(v[0] = x)
    %(v[1] = y)
    (v- v #f(0.5 0.5 0.0) v)
    (scale 2.0 v v) )

;; point, text, clear, rect 
;; built-in fuctions for plotting
;; Users can add functions in .Xplotrc as a usual lisp program
;; 
;;
(defun point (&rest args)
    (sek2ndc (first args) (second args) point)
    (send xv :draw-point-ndc point (aref pixels (third args))) )

(defun text (&rest args)
    (sek2ndc (first args) (second args) point)
    (send xv :draw-image-string-ndc point (third args) 0))

(defun clear (&rest args)
    (send xv :viewsurface :clear))

(defun rect (&rest args)
    (sek2ndc (first args) (second args) point)
    (send xv :draw-fill-rectangle-ndc point 
		rectsize rectsize (aref pixels (third args))))

;;
;; iteration of plotting
;;
(defun plot-sek (file xv)
    (let ((in)  (eof (cons nil nil)) (count 0))
	(while (not (eq (setq in (read file nil eof)) eof))
	   (eval in)
	   (when (> (incf count) 20) (xflush) (setq count 0))
	   )
        (xflush)))

(defun init-xlib ()
   (when (unix:getenv "DISPLAY") 
	(cond ((not (zerop (setq x:disp (x:OpenDisplay 0))))
		(setq x:*defaultGC* (instance gcontext :create))
		(setq x:Root (instantiate Xwindow))
		(setq (x:Root . drawable) (x:defaultrootwindow x:disp))
		(setq x:screen (x:defaultscreenofdisplay x:disp))
		(setq x:visual (x:defaultvisualofscreen x:screen))
	        (setq *whitegc* (instance gcontext :create))
		(send *whitegc* :foreback 0 1)
	        (setq *blackgc* (instance gcontext :create))
		(send *blackgc* :foreback 1 0)
;		(warn "connected to Xserver DISPLAY=~A~%"
;			 (unix:getenv "DISPLAY"))
		)
	     (t (warn "failed to connect to Xserver")
		(unix:exit 10)))) )


(defun Xplot (&rest argv)
  (let ((a) (c) (bg "black") (font nil) (saturation 1.0) (lightness 0.5)
	(file *standard-input*) (size 512) (title "Xplot"))
    (init-xlib)
    ;; parse command options
;    (print (list (pop argv) (unix:getpid)))
    (while argv
      (setq a (pop argv))
      (cond 
	((equal "-in" a)
	 (setq file (open (car argv) :if-does-not-exist nil) )
	 (unless file
	     (format *standard-output* "cannot open input file ~a"
			 (car argv))
	     (unix:exit 1))
	 (pop argv))
	((equal "-size" a) (setq size (read-from-string (pop argv))))
	((equal "-title" a) (setq title (pop argv)))
	((equal "-bg" a) (setq bg (pop argv) ) )
	((equal "-font" a) (setq font (pop argv)))
	((equal "-rect" a) (setq rectsize (read-from-string (pop argv))))
	((equal "-sat" a) (setq saturation (read-from-string (pop argv))))
	((equal "-light" a) (setq lightness (read-from-string (pop argv))))
	((equal "-colors" a) (setq maxcolors (read-from-string (pop argv))))
	) )
    ;;
    ;; set up color map
    (unless bgcmap 
	(setq bgcmap (instance colormap :init nil 0 1)) )
    (send bgcmap :store 0 bg)	;store named color
    (setq bg  (send bgcmap :pixel 0)) 
    (unless cmap 
	(setq cmap (instance colormap :init nil 0 maxcolors)) )
    (dotimes (i maxcolors)
       (setq c (hls2rgb		;hue, lightness, saturation to RGB
		  %(360.0 * float(i) / float(maxcolors))
		  lightness saturation 65535))
       (send cmap :store i (first c) (second c) (third c)) )
    (setq pixels (send cmap :pixels))	;logical color --> x color mapping
    ;;
    ;; create a viewer of xwindow
    ;;
    (unless xv (setq xv (view :size size :title title)))
    (send xv :viewsurface :background bg)
    (when font		;change font
	(send (send xv :viewsurface :gc) :font font) )
    (send (send xv :viewsurface :gc) :background bg)
    ;;
    ;; load .Xplotrc if exists
    (let ((rcfile  (unix:getenv "XPLOTRC")))
      (unless rcfile
	 (setq rcfile (concatenate string (unix:getenv "HOME") "/.Xplotrc")))
      (if (probe-file rcfile)
	  (load rcfile)))
    ;; do plotting
    (plot-sek file xv)
    (unix:sleep 3) )
    ) 

