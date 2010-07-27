;; tty control functions
;; Aug/10/1991, (c) Toshihiro MATSUI

;; (in-package "LISP")
(export '(tty-raw tty-cooked
	backspace cursor-up cursor-down cursor-backward cursor-forward
	cursor-return cursor-pos erase-eol))

;; (defvar *tc* ) 	; <-- (tcgets 0)

;; #+(or :sun :linux :alpha)
(defun tty-raw (&optional (port 0))
   ;; (print 'tty-raw)
   (let ((b (copy-seq lisp::*tc*)))
      (setf (aref b 7) 0)     ;output
      (setf (aref b 12) 0)
      (setf (aref b 13) 0)
      (setf (aref b 14) 0)
      (setf (aref b 15) 0)
#-:mips
      (setf (aref b 21) 1    ;eof MIN
      	    (aref b 22) 0) ;eol TIME
#+:mips
      (setf (aref b 28) 1
	    (aref b 29) 0)
      (unix:tcsets port b)) )

(defun tty-cooked (&optional (port 0))
   ;; (print 'tty-cooked)
   (unix:tcsets port lisp::*tc*))

;; backspace
(defun backspace (&optional (n 1))
  (dotimes (i n) (write-byte 8 *terminal-io*))
  (finish-output *terminal-io*))

;; cursor-up
(defun cursor-up (&optional (n 1))
  (format *terminal-io* "~c~c~dA" #x1b #\[ n ) 
  (finish-output *terminal-io*))

;; cursor-down
(defun cursor-down (&optional (n 1))
  (format *terminal-io* "~c~c~dB" #x1b #\[ n ) 
  (finish-output *terminal-io*))

;; cursor-forward
(defun cursor-forward (&optional (n 1))
  (format *terminal-io* "~c~c~dC" #x1b #\[ n ) 
  (finish-output *terminal-io*))

(defun cursor-backward (&optional (n 1))
  (format *terminal-io* "~c~c~dD" #x1b #\[ n ) 
  (finish-output *terminal-io*))

(defun cursor-return ()
  (format *terminal-io* "~c" 13) 
  (finish-output *terminal-io*))

(defun cursor-pos (x)
  (if (= x 0)
	(cursor-return)
	(format *terminal-io* "~c~c~c~DC" 13 #x1b #\[  x)  )
  (finish-output *terminal-io*))

(defun erase-eol ()
  (format *terminal-io* "~c~cK" #x1b #\[  ) 
  (finish-output *terminal-io*))

(provide :tty "@(#)$Id: tty.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")

