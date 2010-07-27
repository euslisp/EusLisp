;****************************************************************
;;; regular expression
;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;; calls regcomp and regexec in libc for regular expression matching.
;;;
;;; (regmatch "pattern" "target-string")
;;; pattern, which is a regular expression, is searched for in the
;;; terget-string.  If found, the position (starting index and the ending index)
;;; of the found pattern is returned.
;;; example;
;;; (regmatch "ca[ad]+r" "any string ...") will look for cadr, caar, cadadr ...
;;; in the second argument.
;;; (regmatch ".*=.*" "matsui=penguin")
;;; 
;;; Note: Manuals of Turbolinux 4.x tell different stories about
;;; regexp and regexec.  The following code is based on the
;;; descriptions of 'regexec'.

(let ((mm (load "/lib/libc.so.6")))
(defforeign regcomp mm "regcomp"
	(:string	; preg
	 :string	; regular expression string
	 :integer)	; cflags
	:integer)
(defforeign regexec mm "regexec"
	(:string	; preg (compiled regex pattern about 32byte)
	 :integer	; string for which the pattern is searched
	 :integer	; number of rex-matches returnable
	 :string	; rex-matches (pair of longs)
	 :integer)	; eflag
	:integer)
(defforeign regerror mm "regerror"
	(:integer	; error code
	 :string	; preg (compiled regex pattern)
	 :string	; errbuf
	 :integer)	; size of errbuf
	:integer)
(defforeign regfree mm "regfree" (:string) :integer)
)

(defconstant reg_extended 1)
(defconstant reg_icase    2)
(defconstant reg_newline  4)
(defconstant reg_nosub    8)

;; #define REG_NOTBOL 1
;; #define REG_NOTEOL (1 << 1)

;; returns nil if there is no match
(defun regmatch (pattern target
		 &key (start 0) (extended t) (icase t) (newline t) (nosub nil))
   (let ((preg (make-string 40)) (cflags) (stat)
	 (rex-matches (make-array 8 :element-type :integer))
	 (tstart (+ (sys:address target) 8 start)) )
     (setq cflags
	   (logior (if extended 1 0)
		   (if icase 2 0)
		   (if newline reg_newline 0)
		   (if nosub reg_nosub 0)))
     (setq stat  (regcomp preg pattern cflags))
     (unless (zerop stat)
	(warn "regmatch: regular expression compilation error ~s" pattern)
	(return-from regmatch nil)) 
     (setq stat 
	(regexec preg tstart 6 rex-matches 0))
     (regfree preg)
     (cond ((zerop stat)
	    (list (+ start (aref rex-matches 0))
		  (+ start (aref rex-matches 1))
		  (+ start (aref rex-matches 2))
		  (+ start (aref rex-matches 3))
		  (+ start (aref rex-matches 4))
		  (+ start (aref rex-matches 5))
		  ))
	   (t (return-from regmatch nil)))
    )
   )

(provide :regexp)

