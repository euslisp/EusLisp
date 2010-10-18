;;;; TOPLEVEL INPUT HISTORY
;;;  Aug 1991, (c) Toshihiro MATSUI, Electrotechnical Laboratory
;;

;; line editor

;; (in-package "LISP")

;; need tty module to switch between raw and cooked mode
(require 'tty "tty")

(export '(*line-edit-dispatch* refresh-line line-head line-left
	line-right line-delch line-delch-previous line-tail
	line-refresh line-insert line-null line-abort line-end line-edit
	*history-max* *history* *history-index* *history-sequence*
	new-history add-history print-history h get-history !))

;; line editor command dispatch table
(defvar *line-edit-dispatch* (make-array 128))

(defun refresh-line (str start end)
   (cursor-pos start)
   (erase-eol)
   (dotimes (i (- end start))
	(write-byte (elt str (+ i start)) *terminal-io*)  )
   (cursor-pos start) )

(defun line-head (ch line index end)
   (cursor-pos 0)
   (list line 0 end))
(defun line-left (ch line index end)
   (if (> index 0)  (cursor-backward) )
   (list line (max 0 (1- index)) end)  )
(defun line-right (ch line index end)
   (when (< index end) (cursor-forward) (incf index))
     (list line index end) )
(defun line-delch (ch line index end)
   (when (< index end)
	(setq line (list-delete line index))
	(decf end)
	(refresh-line line index end))
   (list line index end))
(defun line-delch-previous (ch line index end)
   (when (> index 0)
	(decf index)
	(setq line (list-delete line index))
	(decf end)
	(refresh-line line index end))
   (list line index end))
(defun line-tail (ch line index end)
   (cursor-pos end)
   (list line end end))
(defun line-refresh (ch line index end)
   (refresh-line line 0 end)
   (cursor-pos index)
   (list line end end))
(defun line-insert (ch line index end)
    (setq line (list-insert ch index line))
    (incf end)
    (refresh-line line index end)
    (incf index)
    (cursor-forward)   
    (list line index end))
(defun line-clear (ch line index end)
    (cursor-pos 0)
    (erase-eol)
    (list '( ) 0 0)) 
(defun line-null (ch line index end)  (list line index end))
(defun line-abort (ch line index end) (throw 'line-edit nil))
(defun line-end (ch line index end) (throw 'line-edit line))

;; initialize dispatch table
   (dotimes (i 128) 
      (setf (aref *line-edit-dispatch* i) 'line-insert) )
   (dotimes (i 32) 
      (setf (aref *line-edit-dispatch* i) 'line-null) )
   (setf (aref *line-edit-dispatch* 1) 'line-head)	;^A
   (setf (aref *line-edit-dispatch* 2) 'line-left)	;^B
   (setf (aref *line-edit-dispatch* 3) 'line-abort)	;^C
   (setf (aref *line-edit-dispatch* 4) 'line-delch)	;^D
   (setf (aref *line-edit-dispatch* 6) 'line-right)	;^F
   (setf (aref *line-edit-dispatch* 7) 'line-refresh)	;^G
   (setf (aref *line-edit-dispatch* 8) 'line-left)	;^H
   (setf (aref *line-edit-dispatch* 10) 'line-end)	;^J
   (setf (aref *line-edit-dispatch* 11) 'line-right)	;^K
   (setf (aref *line-edit-dispatch* 12) 'line-tail)	;^L
   (setf (aref *line-edit-dispatch* 13) 'line-end)	;^M
   (setf (aref *line-edit-dispatch* 18) 'line-refresh)  ;^R
   (setf (aref *line-edit-dispatch* 21) 'line-clear)  ;^u
   (setf (aref *line-edit-dispatch* 127) 'line-delch-previous)


(defun line-edit (line)
  "line (string) is edited and returned"
  (let* ((linelist (coerce line cons)) result
	 (ch) (end (length line)) (index end) func)
    (format t "; ~%~a" line)
    (tty-raw)
    (cursor-pos end)
    (finish-output)
    (setq ch (read-char))
    (setq result
      (catch 'line-edit
         (while t
	   (setq result 
	     (funcall (aref *line-edit-dispatch* ch)
				ch linelist index end) )   
          (finish-output *terminal-io*)
          (setq linelist (car result)
	        index (cadr result)
	        end (caddr result))
          (setq ch (read-char)) ) ) )
    (tty-cooked)
    (if result (coerce linelist string) ) )
    )

;;; HISTORY
(defvar *HISTORY-MAX* 50)
(defvar *HISTORY*)
(defvar *history-index* 0)
(defvar *history-sequence* 0)

(defun new-history (n)
    (setq *history* (make-array n))
    (setq *history-max* n)
    (setq *history-index* 0)
    (setf (aref *history* 0) (list *history-sequence* nil)))

(defun add-history (h)
   (incf *history-sequence*)
   (incf *history-index*)
   (when (>= *history-index* *history-max*)
	(setf *history-index* (1- *history-max*))
	(replace *History* *history* :start1 0 :start2 1))
   (setf (aref *history* *history-index*) (list *history-sequence* h))
   (if (and (boundp 'x::*eustop-window*)
	    (find-method x::*eustop-window* :update-history))
       (send x::*eustop-window* :update-history))
   *history*)

(defun print-history (&optional (strm *terminal-io*) &aux h)
   (dotimes (i (1+ *history-index*))
	(setq h (elt *history* i))
	(if (consp h)
		(format strm "~2d: ~A~%" (car h) (cadr h))) )
   )

(defun h () "print-history" (print-history))

(defun get-history (n)
   (if (numberp n)
       (if (<= n 0)
           (cadr (elt *history* (+ *history-index*  n -1)) )
           (cadr (elt *history* (min *history-index* 
				     (max 0 (- n (car (aref *history* 1)) -1))))) )
       (do ((i (1- *history-index*) (1- i))
	    (pattern (string n))
	    (his))
	   ((<= i 0) nil)
	 (if (substringp pattern (string (setq his (cadr (aref *history* i)))))
	     (return-from get-history his)))))

(defun ! (&optional (n 0))
   (let* ((history-string (get-history n))
	  (edited-string (line-edit history-string)))
	(terpri)
	(cond (edited-string
		(add-history  edited-string)
		(evaluate-stream (make-string-input-stream edited-string)) )
	      (t nil))))


;(defun toplevel-prompt (strm) 
;   (format strm "~d.~a " (1+ *history-sequence*) *prompt-string*))

(provide :history "@(#)$Id$")
