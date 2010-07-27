;;;
;;; X window viewsurface
;;;
(defun left-button-p (e) (eq (elt e 13) 1))
(defun middle-button-p (e) (eq (elt e 13) 2))
(defun right-button-p (e) (eq (elt e 13) 3))
;;
(defun press-button-p (e) (eq (elt e 0) 4))
(defun release-button-p (e) (eq (elt e 0) 5))
(defun drag-button-p (e) (eq (elt e 0) 6))
;;
(defclass xwindow-viewsurface
  :super xwindow
  :slots (
	  mouse-pos
	  color
	  input-event
	  ))

(defmethod xwindow-viewsurface
  (:mouse-pos () (copy-seq mouse-pos))
  (:wait-event  (&optional (event-types '(2 3 4 5 6)))
		(catch 'wait-event
		  (while t
		    (and
		     (setq input-event (evnt))
		     (memq (elt input-event 0) event-types)
;;;		     (eq drawable (elt input-event 4))
		     (throw 'wait-event input-event))))
		)
  (:wait-button ()
		(setq input-event (send self :wait-event '(4 5 6)))
		(setf (aref mouse-pos 0) (elt input-event 8))
		(setf (aref mouse-pos 1) (elt input-event 9))
		input-event)
  (:which-button ()
		 (let ((button (send self :wait-button)))
		   (setq button (send self :wait-button))
		   (cond
		    ((left-button-p button) 'left)
		    ((right-button-p button) 'right)
		    ((middle-button-p button) 'middle)))
		 )
  (:wait-press (type)
	       (if (symbolp type)
		   (setq type (case type (middle 2) (right 3) (t 1))))
	       (while 
		   (not (and (setq input-event (send self :wait-button))
			     (press-button-p input-event)
			     (eq type (elt input-event 13)))))
	       input-event)
  (:wait-release (type)
		 (if (symbolp type)
		     (setq type (case type (middle 2) (right 3) (t 1))))
		 (while
		     (not (and (setq input-event (send self :wait-button))
			       (release-button-p input-event)
			       (eq type (elt input-event 13)))))
		 input-event)
  (:set-erase-mode () (setq color 0))
  (:set-show-mode () (setq color 11))
  (:color (&optional v)  (if v (setq color v) color))
  (:drawline-primitive (x0 y0 x1 y1)
		       (send-super :line x0 y0 x1 y1))
  (:drawtext-primitive (str x y
			    &key (mag-x 1) (mag-y 1)
			    (color 13) (font-type 1) (angle 0))
		       (send self :image-string (round x) (round y) str)
		       (xflush))
  (:init (&rest args
		&key
		((:color c) 11)
		(width 768)
		(height 512)
		&allow-other-keys)
	 (setq input-event (instantiate integer-vector 25))
	 (setq mouse-pos (float-vector 0 0))
	 (apply #'send-message self (class . super) :create args)
	 self)
  )

(setq *viewsurface-class* xwindow-viewsurface)

(defun mouse-curgt (&optional (vs *viewsurface*))
;;; return (x y)
  (let ((p (vs . mouse-pos)))
    (setq *mx* (elt p 0) *my* (elt p 1))))

(defun mouse-getdt (&optional (vs *viewsurface*))
;;; return (left-stat right-stat) ; left-stat,right-stat: t or nil
  (list (left-button-p (vs . input-event))
	(right-button-p (vs . input-event))))

(defun mouse-get-r (&optional (vs *viewsurface*))
;;; return t or nil
  (and (right-button-p (vs . input-event))
       (press-button-p (vs . input-event))))

(defun mouse-get-l (&optional (vs *viewsurface*))
;;; return t or nil
  (and (left-button-p (vs . input-event))
       (press-button-p (vs . input-event))))

