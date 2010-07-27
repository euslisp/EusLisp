;;;; html-readtable.l
;;;; (c) Toshihiro Matsui, AIST, Japan
;;;; May 7, 2003

(defvar *html-readtable* (copy-readtable))

(set-syntax-from-char #\> #\) *html-readtable*)
(set-syntax-from-char #\= #\space *html-readtable*)
;;  #rrggbb notation can fool the Lisp reader.
(set-syntax-from-char #\# #\A *html-readtable*)
(set-macro-character #\{ 'read-brace-form nil *html-readtable*)
(set-syntax-from-char #\} #\rparen *html-readtable*)
(set-syntax-from-char #\; #\space *html-readtable*)


(set-syntax-from-char #\: #\space *html-readtable*)

(set-macro-character #\% nil nil *html-readtable*)
(set-macro-character #\[ nil nil *html-readtable*)

(defun read-brace-form (strm char)
   (prog1 (eval (read strm)) (read strm)))


(provide :html-readtable)

