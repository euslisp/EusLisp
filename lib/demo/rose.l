;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;   									     ;;
;;   File:     rose.l							     ;;
;;   Author:   Michel Pasquier						     ;;
;;   Created:  Mon Apr 25 22:44:00 1989	on etlsc6			     ;;
;;   Modified: Wed May  3 20:58:57 1989 on etlsc6			     ;;
;;   Contents: A pretty rose drawing program                                 ;;
;;   									     ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;
;; The first goal of this implementation was to answer the question:
;;       "How fast would that run in <put your favorite language here> 
;;        on a <do the same for a computer> ?" 
;; This version is written for the object-orientated EUSlisp (ETL) and works
;; for the almost standard Xwindow package (MITI), as well as for SUN sunview
;; graphic interface and Tektronix 4010/4014 terminals. It runs impressively
;; fast, being sometimes roughly comparable to the C version!
;;
;; This code could be easily translated to any language on any computer with
;; graphic capabilities, provided some line-drawing function do exist.
;; For this purpose, check the functions listed below 'Graphics'. Also, some
;; nicer interface could be added; check below 'Interface'.
;;
;;   * ROSE *
;;
;; The basic idea for this program comes from an article by P.M.Maurer in
;; American Mathematical Monthly (oct 87) called   "A rose is a rose..."
;; Some other versions should exist here and there, as I.Phillips' sunview
;; C-version, which runs very fast and offers a nice interactive dialog box.
;;
;; For those in a hurry for interesting results, here are some examples of
;; values to start with: (241 359) (226 186) (59 184) (240 101) (358 101) 
;; (103 97) (170 298) (81 191) (2 61) (170 169) (61 148) etc. Enjoy!
;;

(defmacro ROSE () `(main-loop))

;;
;; Skel - main loop function
;;

(defun main-loop ()	   
  (catch 'Main
    (init-graphics)          ; graphic system initialization
    (init-params)            ; misc. parameters initialization
    (loop		     ; real main loop :
     (interactive-get-param) ; >> get seed parameters 
     (draw-graphic-object)   ; >> and draw the rose
     (interactive-quit))))   ; >> then ask for quit

;;
;; Basic - variables and tables
;;
			     ; number of increments in a revolution (this
(defparameter QUANTUM 360)   ; has nothing to do directly with degrees)

(defparameter N 0)           ; the two seeds
(defparameter D 0)	     ; defining the rose

(defvar sinx (make-array QUANTUM)) ; the trig tables
(defvar cosx (make-array QUANTUM)) 
(defun init-params () 
  (if (null (aref sinx (random QUANTUM))) ; and their init. function
      (dotimes (i QUANTUM) 
	 (setf (aref sinx i) (sin (/ (* i 2 PI) QUANTUM))
	       (aref cosx i) (cos (/ (* i 2 PI) QUANTUM))))))

;;
;; Kernel - the algorithm used to draw a rose
;;

(defun draw-graphic-object ( &aux (xoffset (/ XSIZE 2))    ; int
				  (yoffset (/ YSIZE 2))    ; int
				  (xscale (* xoffset 0.9)) ; int or float
				  (yscale (* yoffset 0.9)) ; int or float
				  (x xoffset) (y yoffset)  ; int
				  (newx xoffset)(newy yoffset) ; int
				  (a 0)                    ; int !!!
				  (r 0.0) )                ; float
  (catch 'DRAW		   ; this implements a 'repeat until' loop
    (loop	    
     (setq x newx	   ; everything lies in this binding sequence
	   y newy	   
	   a (/rest (+ a D) QUANTUM)
	   r (aref sinx (/rest (* a N) QUANTUM))
	   newx (+ xoffset (* xscale r (aref sinx a)))
	   newy (+ yoffset (* yscale r (aref cosx a))))
     (draw-vector x y newx newy)
     (if (< a 1) (throw 'DRAW nil))))	; test must be done last
  (flush-display))

(defun /rest ( a b ) (- a (* (/ a b) b))) ; rest of integer division

;;
;; Interface - prompting for answers/parameters
;;

(defun interactive-get-param ()
  (clear-display)
  (setq N (peek-seed "1> N seed [~A-~A]? " 0 QUANTUM))
  (setq D (peek-seed "2> D seed [~A-~A]? " 0 QUANTUM))
  (format t "                             ROSE(~A,~A)~%" N D))

(defun interactive-quit ()
  (format t "Quit? ") (finish-output) (read-char)
  (when (= (read-char) 121) ; type 'y' to quit
	(finish-output) 
	(throw 'Main 'bye)))

(defun peek-seed ( mess min max &aux (c "") )
  (while (not (and (numberp c) (< min c max))) 
    (format t mess min max) (finish-output) (setq c (read)))
  c)

;;
;; Graphics - addressing the window system
;;

(setq   *viewsurface* nil)   ; the graphic window (EUS built-in)
(defvar XSIZE 700)           ; size of the screen
(defvar YSIZE 700)           ; in width (X) and height (Y)

(defun init-graphics ()	     ; create and initialize the window port
  (if (null *viewsurface*)
      (setq *viewsurface* 
	    (cond ((string= *program-name* "eusx") ; EUS & XWINDOW 
		   (instance x:xwindow :create :x 0 :y 0 
			     :background x:*blackpixel*
			     :foreground x:*whitepixel*
			     :title "ROSE" :border-width 2
			     :width XSIZE :height YSIZE))
		  ((string= *program-name* "eusgeo") ; EUS & TEKTRO
		   (instance tektro-viewsurface :init))
		  ((string= *program-name* "eusgeo") ; EUS & SUNVIEW
		   (instance canvas-viewsurface :init))))))

 (defun draw-vector (x y nx ny)
   (send *viewsurface* :draw-line (float-vector x y) (float-vector nx ny)))

 (defun flush-display () (send *viewsurface* :flush))

 (defun clear-display () (send *viewsurface* :clear) (flush-display))

; this method added because of class inconsistency
(eval-when (compile) (defclass tektro-viewsurface))
(defmethod tektro-viewsurface
  (:draw-line (p q) (tektro-showline (round (elt p 0)) (round (elt p 1))
				     (round (elt q 0)) (round (elt q 1)))))
;;
;; End
;;
