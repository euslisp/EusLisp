;;;; kanji code converter
;;
;;	Copyright (c) 1989-Jul, Toshihiro MATSUI, Electrotechnical Laboratory
;;
;; jis2euc	JIS kanji are converted into EUC (8bit) representation
;;
(defun jis2euc (jstr)
   (let ((estr (make-string (length jstr))) (e 0) jch kanji
	 (escape 0) (esc1 0) (esc2 0))
     (flet ((put-estr (ch) (setf (char estr e) ch) (incf e)))
       (dotimes (j (length jstr))
	 (setq jch (char jstr j))
	 (case escape
	  (0 (if (= jch #x1b)
		 (setq escape 1)
		 (put-estr (logior (if kanji #x80 0) jch))))
	  (1 (setq esc1 jch)
	     (if (= jch #\$)
		 (setq escape 2)
		 (if (= jch #\()	;)
		     (setq escape 4)
		     (progn
			   (put-estr #x1b) (put-estr jch)))))
	  (2 (setq esc2 jch)
	     (if (member jch '(#\B #\@))
		 (progn (setq escape 0) (setq kanji t))
		 (progn (put-estr #x1b) (put-estr esc1) (put-estr jch))))
	  (4 (setq esc2 jch)
	     (if (= jch #\J)
		 (progn (setq escape 0) (setq kanji nil))
		 (progn (put-estr #x1b) (put-estr esc1) (put-estr jch))))))
	(subseq estr 0 e))))

(defun read-kanji-string (strm ch n)
   (jis2euc (read strm)))

(set-dispatch-macro-character #\# #\k 'read-kanji-string)

