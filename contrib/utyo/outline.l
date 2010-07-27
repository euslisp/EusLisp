;;;
;;;		Outline extractor
;;;					Programmed by Iida.
;;;      (outline arg)
;;;		arg = list of 2dlnseg
;;;		returns list of 2dlnseg
;;;
(defun start-pos (lines)    
  (let*
      ((m-x 
	(minx-list (minx (lines-to-pos lines))
		   (lines-to-poses lines))))
    (miny-pos (miny (poses-to-pos m-x)) m-x)))

(defun minx-list (x-min points)
  (cond
   ((null points) nil)
   ((equal x-min (send (car points) :min-x))
    (cons (car points) (minx-list x-min (cdr points))))
   (t (minx-list x-min (cdr points)))))

(defun miny-pos (y-min points)
  (cond
   ((equal y-min (send (car points) :min-y)) 
    (car points))
   (t (miny-pos y-min (cdr points)))))

(defun minx (points)
  (send points :min-x))

(defun miny (points)
  (send points :min-y))

(defun start-candidate (pos lines)
  (cond
   ((null lines) nil)
   ((or (pos-equal pos (make-2dpoints (list (send (car lines) :spos))))
	(pos-equal pos (make-2dpoints (list (send (car lines) :epos)))))
    (cons (car lines) (start-candidate pos (cdr lines))))
   (t (start-candidate pos (cdr lines)))))

(defun next-or-not-next (pos lines)
  (let
      ((next nil))
    (dolist (line lines next)
	    (cond
	     ((or (pos-equal
		   pos (make-2dpoints (list (send  line :spos))))
		  (pos-equal
		   pos (make-2dpoints (list (send  line :epos)))))
	      (setq next (cons (line-check pos line) next)))
	     (t (setq *rest* (cons line *rest*)))))))

(defun line-check (spos line)
  (let*	((l-spos (make-2dpoints (list (send line :spos)))))
    (cond
     ((pos-equal spos  l-spos) line)
      (t (s-e-pos-change line)))))

(defun data-lines (lines)
  (cond
   ((null lines) nil)
   (t (cons (send (car lines) :poslist) (data-lines (cdr lines))))))

(defun ldifference (in out)
  (cond
   ((null in) nil)
   ((line-equal (car in) out)
    (ldifference (cdr in) out))
   (t (cons (car in) (ldifference (cdr in) out)))))

(defun lines-to-pos (lines)
  (poses-to-pos (lines-to-poses lines)))

(defun poses-to-pos (points)
  (make-2dpoints (p-list points)))

(defun p-list (points)
  (cond
   ((null points) nil)
   (t (append (send (car points) :poslist) (p-list (cdr points))))))

(defun lines-to-poses (lines)
  (cond
   ((null lines) nil)
   (t (append (line-to-poses (car lines)) (lines-to-poses (cdr lines))))))

(defun line-to-poses (line)
  (list (make-2dpoints (list (send line :spos)))
	(make-2dpoints (list (send line :epos)))))

(defun line-equal (line1 line2)
  (let*
      ((l1-s (make-2dpoints (list (send line1 :spos))))
       (l1-e (make-2dpoints (list (send line1 :epos))))
       (l2-s (make-2dpoints (list (send line2 :spos))))
       (l2-e (make-2dpoints (list (send line2 :epos)))))
    (cond
     ((or (and (pos-equal l1-s l2-s) (pos-equal l1-e l2-e))
	  (and (pos-equal l1-s l2-e) (pos-equal l1-e l2-s))) t))))

(defun pos-equal (pos1 pos2)
  (cond
   ((and (< (abs (- (send pos1 :min-x) (send pos2 :min-x))) 0.00001)
	 (< (abs (- (send pos1 :min-y) (send pos2 :min-y))) 0.00001))
    t)))

(defun s-e-pos-change (line)
  (instance 2dlnseg :init :spos (send line :epos)
	    :epos (send line :spos)))

(defun dy/dx (line)
  (cond
   ((= 0.0 (send line :dx))  10000)
   (t (send line :gradient))))

(defun start-line (lines)
  (let*
      ((s-list
	(start-candidate 
	 (make-2dpoints (list (send (start-pos lines) :spos))) lines))
       (s-line     (car s-list))
       (s-pos  (start-pos lines))
       (s-l-data (dy/dx s-line))
       data)
    (dolist (line (cdr s-list) s-line)
	    (setq data (dy/dx line))
	    (when	(> s-l-data  data)
			(setq s-l-data data)
			(setq s-line line)))
    (line-check s-pos s-line)))

(defun angle (line1 line2)
  (cond
   ((> (send line1 :angle2) (send line2 :angle2))
    (+ 360 (- (send line2 :angle2) (send line1 :angle2))))
   (t (- (send line2 :angle2) (send line1 :angle2)))))

(defun next-line (before lines)
  (let*
      ((n-line     (car lines))
       (n-l-data (angle before (car lines)))	 
       data)
    (cond
     ((null (cdr lines)) n-line)
     (t (dolist ( line (cdr lines) n-line)
		(setq data (angle before line))
		(when (> n-l-data data)
		      (setq s-l-data data)
		      (setq n-line line)))))))
(defun outline (lines)
  (let*
      ((pos  nil)
       (last nil)
       (startline (start-line lines)))
    (setq  *select-line* startline)
    (setq  last  (make-2dpoints (list (send startline :epos))))
    (setq  pos   (make-2dpoints (list (send *select-line* :spos))))
    (cons startline
	  (next-line-list pos  last (ldifference lines startline)))))

(defun next-line-list (start-p last-p lines)
  (let*
      ((next-can nil)
       (before (s-e-pos-change *select-line*)))
    (cond
     ((pos-equal  start-p last-p) nil)
     (t 
      (setq *rest* nil)
      (setq next-can (next-or-not-next last-p lines)) 
      (setq *select-line* (next-line before next-can))
      (setq last (make-2dpoints (list (send *select-line* :epos))))
      (cons *select-line* (next-line-list start-p last *rest*)))))
 
