;;;                                                   ;;;
;;;      VIEWSUFACE for the X68k computer           ;;;
;;;            written by J.Naito     1988 10 12      ;;;
;;;                                                   ;;;

(eval-when
 (compile eval)
 (load "/usr/local/eus/llib/geoclasses.l")
 )
;;;
(unless (member 'x68k *features*) (push 'x68k *features*))
(defun crtmode(i)
  (format t "~C!cr ~S ~%"  27 i )t)

(defun vpage (i)
  (format t "~C!v ~S ~%" 27 i ) t)

(defun apage (i)
  (format t "~C!a ~S ~%"  27 i ) t)

(defun x68k-circle (x y r &optional (pallet 11) (start 0) (end  360) (ratio 256))
  (format t "~C!ci ~S ~S ~S ~S ~S ~S ~S ~%"
	  27  x	  y r pallet start end ratio) t)

(defun x68k-showline (x1 y1 x2 y2 &optional (pallet 11) (line_style 65535))
  (format t "~C!l ~S ~S ~S ~S ~S ~S ~%"
          27 (round x1) (round y1) (round x2) (round y2) pallet line_style)
  t)

(defun wipe nil
  (format t "~C!w ~%"  27 ) t)

(defun fill (x1 y1 x2 y2 pallet)
  (format t "~C!f ~S ~S ~S ~S ~S ~%"
	  27	  x1	  y1	  x2	  y2	  pallet) t)
	  
(defun paint (x y pallet)
  (format t "~C!pa ~S ~S ~S ~%" 27 x y pallet) t)

(defun box (x1 y1 x2 y2 pallet &optional (line_style 65535))
  (format t "~C!b ~S ~S ~S ~S ~S ~S ~%" 27 x1 y1 x2 y2 pallet line_style) t)

(defun symbol
  (x1 y1 str &key (mag-x 1) (mag-y 1) (color 13) (font-type 1) (angle 0))
  (x68k-drawtext x1 y1 str :mag-x mag-x :mag-y mag-y :color color
		 :font-type font-type :angle angle))
(defun x68k-drawtext
  (x1 y1 str &key (mag-x 1) (mag-y 1) (color 13) (font-type 1) (angle 0))
  (setq str (copy-seq (string str)))
  (dotimes (i (length str))
	   (if (eq (aref str i) #\ )
	       (setf (aref str i) #\_)))
  (format t "~C!s ~S ~S ~a ~S ~S ~S ~S ~S ~%"
	  27 (round x1)
	  (- (round y1) 12) str mag-x mag-y color font-type angle) t)

(defun console (start-x start-y keta-x keta-y)
  (format t "~C!co ~S ~S ~S ~S ~%"
	  27 start-x start-y keta-x keta-y
	  )t)
(defun text-clear ()
  (format t "~C!cl ~%" 27)t)

(defun change-prompt()
  (setq *prompt-string* '>)
  (reset))

(defun locate (x y)
  (format t "~C!1 ~S ~S ~%"
	  27
	  x
	  y) t)
(defun tvctrl
  (code)
  (format t "~C!tv ~S ~%" 27 code))

(defun super-impose (&optional (flag t))
  (cond (flag (tvctrl 30))
	(t (tvctrl 29))))

(defun show-page (l)
  (let ((n 0))
    (dolist (x l n)
	    (case x
		  (0 (setq n (+ n 1)))
		  (1 (setq n (+ n 2)))
		  (2 (setq n (+ n 4)))
		  (3 (setq n (+ n 8)))))
    (vpage n)))

(defun tcolor (n)
  (format t "~C!2 ~S ~%" 27 n)
  t)

(defun text-color (n)
  (format t "~C!4 ~S ~%" 27 n)
  t)

(defun tpalet2 (paletno colorcode)
  (format t "~C!3 ~S ~S ~%"
	  27
	  paletno
	  colorcode)
  t)

(defun cls () (wipe))
(defun clear () (text-clear))


;;;                                                   ;;;
;;;      VIEWSUFACE for the X68000 computer           ;;;
;;;            written by J.Naito     1988 10 12      ;;;
;;;                                                   ;;;

(defclass x68k-viewsurface
  :super viewsurface
  :slots (
	  color
	  activepage
	  viewpage
	  crtmode
	  width height
	  mouse-pos
	  input-event)
  )

(defmethod x68k-viewsurface
  (:wait-press (&optional (button 'left))
	       (while
		   (not (and
			 (eq 'press (car (setq input-event (x68k-wait-button))))
			 (eq 'on (elt input-event (if (eq button 'right) 2 1))))))
	       (setf (aref mouse-pos 0) (elt input-event 3))
	       (setf (aref mouse-pos 1) (elt input-event 4))
	       input-event)
  (:wait-release (&optional (button 'right))
	       (while
		   (not (and
			 (eq 'release (car (setq input-event (x68k-wait-button))))
			 (eq 'off (elt input-event (if (eq button 'right) 2 1))))))
	       (setf (aref mouse-pos 0) (elt input-event 3))
	       (setf (aref mouse-pos 1) (elt input-event 4))
	       input-event)
  (:flush ())
  (:width (&optional (w width)) (setq width w))
  (:height (&optional (w height)) (setq height w))
  (:mouse-pos () (copy-seq mouse-pos))
  (:init (&rest args
		&key
		((:color c) 11)
		((:activepage ap) 0)
		((:viewpage vp) 1)
		((:crtmode cm) 4)
		((:width w) 768)
		((:height h) 512)
		&allow-other-keys
		)
	 (setq color c)
	 (setq crtmode cm)
	 (setq viewpage vp)
	 (setq activepage ap)
	 (setq width w height h)
	 (setq mouse-pos (float-vector 0 0))
	 self)
  
  (:set-erase-mode ()
		   (setq color 0))
  (:set-show-mode ()
		  (setq color 11))
  (:color (&optional v)
	  (if v (setq color v) color))
  (:clear () (wipe))

  (:drawtext-primitive  (str x0 y0 &key ((:color c) color) (angle 0))
			(x68k-drawtext x0 y0 str :color color))
  (:drawline-primitive (x0 y0 x1 y1)
		       (x68k-showline
			(round x0)
			(round y0)
			(round x1)
			(round y1)
			color
			))
  (:line (x0 y0 x1 y1)
	 (line
	  (round x0)
	  (round y0)
	  (round x1)
	  (round y1)
	  color
	  ))
  (:paint (x y)
	  (paint
	   (round x)
	   (round y)
	   color
	   ))
 
  (:viewpage (&optional page)
	     (cond ((numberp page)
		    (vpage page)
		    (setq viewpage page))
		   (t viewpage)))
  (:circle (pos radius)
	   (x68k-circle (round (vector-x pos))
			(round (vector-y pos))
			radius))
  (:activepage (&optional page)
	       (cond ((numberp page)
		      (apage page)
		      (setq activepage page))
		     (t activepage)))
  
  (:crtmode (&optional i)
	    (cond (i
		   (crtmode i)
		   (setq crtmode i))
		  (t crtmode)))
		  
  
  (:fill (x1 y1 x2 y2) 
	 (fill
	  (round x1)
	  (round y1)
	  (round x2)
	  (round y2)
	  color
	  ))
  (:graphic-erase ()
		  (wipe))
  (:box (x1 y1 x2 y2 )
	(box
	 (round x1)
	 (round y1)
	 (round x2)
	 (round y2)
	 color
	 ))
  (:symbol (x1 y1 string &key (mag-x 1) (mag-y 1) (font-type 1) (angle 0))
	   (symbol
	    (round x1)
	    (round y1)
	    string
            :mag-x   mag-x
            :mag-y   mag-y
	    :color color
	    :font-type font-type
	    :angle angle
	    ))
  (:text-clear ()
	       (text-clear))
  (:show-text (p str)
	      (let ((l (/ (* 6 (+ (length (or str " ")) 2)) 2)))
		(send self :drawtext-primitive
		      str (- (vector-x p) l -5) (vector-y p))))
  (:show-circle (pos radius)
		(x68k-circle (vector-x pos) (vector-y pos) radius))
;;;
  (:wait-button () (x68k-wait-button))
  )

(setq *viewsurface-class* x68k-viewsurface)

;;;
;;; mouse handling
;;; 

(defun x68k-mouse-curgt()
;;; return (x y)
  (format t "~C&cg ~%" 27 ) (read))

(defun x68k-mouse-getdt()
;;; return (left-stat right-stat) ; left-stat,right-stat: t or nil
  (format t "~C&g ~%" 27 ) (read))

(defun x68k-mouse-get-r()
;;; return t or nil
  (format t "~C&r ~%" 27)
  (read))

(defun x68k-mouse-get-l()
;;; return t or nil
  (format t "~C&l ~%" 27)
  (read))

(defun x68k-mouse-offtm(maxtime mode)
;;; wait until button is release
;;; if mode is 0, left button check
;;; if mode is -1, right button check
;;; if maxtime is 0, it means wait forever
;;; return : 
;;;	0 : if moved
;;;	1 : if not yet pressed
;;;	-1 : over the maxtime
;;;	otherwise : waiting time
;;;
  (format t "~C&of ~S ~S ~%" 27 maxtime mode) (read))

(defun x68k-mouse-ontm(maxtime mode)
;;; wait until button is pressed
;;;
  (format t "~C&on ~S ~S ~%"
	  27
	  maxtime
	  mode
	  )
  (read)
  )

(defun x68k-mouse-curst(x y)
;;; set mosue position (x y)
  (format t "~C&st ~S ~S ~%"
	  27
	  (round x)
	  (round y)
	 
	  )t)

(defun x68k-mouse-curof()
;;; erase mouse cursor
  (format t "~C&cof ~%"
	  27  ) t)

(defun x68k-mouse-curon()
;;; show mouse cursor
  (format t "~C&con ~%"
	  27 ) t)

(defun x68k-mouse-limit(x1 y1 x2 y2)
;;; set the range for mouse
  (format t "~C&7 ~S ~S ~S ~S ~%"
	  27
	  (round x1)
	  (round y1)
	  (round x2)
	  (round y2)
	  
	  )t)

(defun x68k-mouse-stat()
;;; return t : if cursor is displayed, nil : otherwise
  (format t "~C&s ~%"  27)
  (read))

(defun double-clicked(&key (button 'left ))         ;;; return mouse position
  (cond ((eq button 'left)
	 (format t "~C&1 ~%" 27)
	 (read))
	((eq button 'right)
	 (format t "~C&6 ~%" 27)
	 (read))
	(t 'error)
	))

(defun single-clicked(&key (button 'left))
  (cond ((eq button 'left)
	 (format t "~C&3 ~%" 27)
	 (read))
	((eq button 'right)
	 (format t "~C&2 ~%" 27)
	 (read))
	(t 'error)
	))

(defun x68k-mouse-clickedp(&key (button 'left))
  (cond ((eq button 'left)
	 (format t "~C&5 ~%" 27)
	 (read))
	((eq button 'right)
	 (format t "~C&4 ~%" 27)
	 (read))
	(t 'error)
	))

(defun x68k-wait-button ()
;;;
;;; (status left right x y)
;;; status : move, press, release
;;; left,right : on | off
;;; x, y: integer
;;;  
  (format t "~C&w ~%" 27 ) (read))
