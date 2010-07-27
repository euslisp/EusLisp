;;;;
;;;; animation.l
;;;;	make continuous motion pictures (on xwindow)
;;;;	1989/Apr/7
;;;;	Copyright (c) 1989, Toshihiro MATSUI, ETL
;;;;

;; draw pictures in a list of pixmaps successively

(defvar *animation-count* 0)

(provide :animation)

;; pixmap-animation repeats evaluating user-provided drawing forms.
;; When each drawing finishes, the content of current viewsurface
;; is copied to a newly created pixmap. pixmap-animation returns
;; a list of pixmaps which can be played back by playback-pixmaps.
;; When the X server's memory is tight, creation of a new pixmap
;; may fail, which will lead the euslisp to die.

(defmacro pixmap-animation (count &rest forms)
   (let* ((w (send *viewsurface* :width))
	  (h (send *viewsurface* :height))
	  (gc (send *viewsurface* :gc)))
     `(let ((pixmaps) (pm))
         (dotimes (*animation-count* ,count)
	    (cls)
	    (progn . ,forms)
	    (setq pm (instance x:Xpixmap :create :width ,w :height ,h :gc ,gc))
	    (push pm pixmaps)
	    (send pm :copy-from *viewsurface*))
         (nreverse pixmaps)) ))

(defun playback-pixmaps (pixmaps &optional (win *viewsurface*))
   (dolist (p pixmaps) 
      (send win :copy-from p)))

;; reapeat hid and return accumulate visible line segments
;; forms should include calls to 'hid'

(defmacro hid-lines-animation (count &rest forms)
     `(let ((lines))
         (dotimes (*animation-count* ,count)
	    (cls)
	    (progn . ,forms)
	    (push (list-visible-segments *hid*) lines))
         (nreverse lines)) )

(defun draw-hid-lines (lines &optional (view *viewer*))
    (dolist (l lines)
         (send view :draw-line-ndc (first l) (second l) nil)) )

(defun playback-hid-lines (lines &optional (view *viewer*))
;;
;; Make smooth-animation using double-buffering technique
;; A series of pictures are drawn in a pixmap which cannot be seen
;; on screen, and the pixmaps are then copied to xwindow surface.
;;
   (send view :adjust-viewport)
   (let* ((win (send view :viewsurface))
	  (pix (instance x:xpixmap :create
			 :width (send win :width)
			 :height (send win :height))) )
        (setf (viewer-surface view) pix)
	(unwind-protect
	   (dolist (ln lines)
	      (send pix :clear)
	      (draw-hid-lines ln)
	      (send win :copy-from pix)
	      (xflush))
	   (setf (viewer-surface view) win)
	   (send pix :destroy))))

;;
;; extract visible line segments out of edge-image structures
;;
(defun list-visible-segments (&optional (hid *hid*))
   (apply #'append (send-all hid :visible-segments)))



#|

;; a simple demonstration

(setq a (make-cylinder 50 100) b (make-cube 300 400 200))
(send a :translate #f(0 0 150))

(defun test ()
      (send a :rotate 0.2 :x) (send b :rotate -0.2 :y)
      (hid a b))

(setq pmaps (pixmap-animation 10 (test)))
(playback-pixmaps pmaps)

(setq hlines (hid-lines-animation 20 (test)))
(playback-hid-lines hlines)

|#



