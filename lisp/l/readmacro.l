;;
;; First, some reader functions must be defined to read lisp source file
;;
(list "@(#)$Id: readmacro.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")

(eval-when (load eval)
(in-package "LISP")

;; character names are defined in lisp package
(export  '(newline space rubout
		page  tab backspace
		return linefeed))

;; back quote ` , @


(defun read-backquote (file &optional ch) (conv-bq (read file)))
(defun conv-bq (x)
   (cond ((null x) nil)
         ((atom x) (list 'quote x))
	 ((atom (car x))
	    (cond ((eq (car x) '\,) (cdr x))
		  (t (conscons (list 'quote (car x)) (conv-bq (cdr x))))))
	 ((eq (caar x) '\,)
	    (conscons (cdar x) (conv-bq (cdr x))))
	 ((eq (caar x) '\,\@)
	    (list 'append (cdar x) (conv-bq (cdr x))))
	 (t (conscons (conv-bq (car x)) (conv-bq (cdr x)))) ))

(defun conscons (x y)
  (if (null y)
      (list 'list x)
      (list 'cons x y)))

(defun read-comma (file &optional ch)
  (cond ((eq (peek-char file) #\@)
	   (read-char file) (cons '\,\@ (read file)))
	(t (cons '\, (read file)))))

(set-macro-character #\, 'read-comma)
(set-macro-character #\` 'read-backquote)

;; #B and #* macro

(defun read-binary (f ch n)
  (let ((val 0) )
    (setq ch (read-char f))
    (while (find ch "01")
	(setq val (+ (* val 2) (- ch #\0)))
	(setq ch (read-char f nil nil)))
    (if (integerp ch)  (unread-char ch f))
    val))

(defun read-bit-vector (f ch n)
   (let  ((ba (make-array '(8) :element-type :bit :fill-pointer 0)))
      (setq ch (read-char f))
      (while (find ch "01")
	(vector-push-extend (- ch #\0) ba)
	(setq ch (read-char f nil nil)))
      (if (integerp ch)  (unread-char ch f))
      (subseq (array-entity ba) 0 (fill-pointer ba))))


(set-dispatch-macro-character #\# #\B 'read-binary)
(set-dispatch-macro-character #\# #\* 'read-bit-vector)

;; "#!" is regarded as a comment so that "#! /usr/local/bin/eus ..." can
;; define a legal shell command.
(set-dispatch-macro-character #\# #\! (get-macro-character #\;))

(defun read-pathname (f ch n)
  (pathname (read f)))

(set-dispatch-macro-character #\# #\P 'read-pathname)

;; radian and degree conversion

(defun read-radian (strm char num)
  (deg2rad (read strm)))
(set-dispatch-macro-character #\# #\D 'read-radian)
(defun read-degree (strm char num)
  (rad2deg (read strm)))
(set-dispatch-macro-character #\# #\R 'read-degree)
 )




