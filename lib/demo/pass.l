;; sort passwd according to uid
;;
(defun passwd (infile &optional (out t))
  (let ((eof (cons nil nil)) line name uid gid ins ch users)
    (with-open-file (in infile)
      (while (not (eq  (setq line (read-line in nil eof)) eof))
        (setq line (nsubstitute  #\space  #\: line))
        (setq ins (make-string-input-stream line))
        (setq name (read ins))
        (when (alpha-char-p (elt (string name) 0))
	  (read-char ins)
	  (setq ch (peek-char ins))
	  (when (not (eq ch #\space))	;
	     (read ins)			;passwd
	     (setq uid (read ins))
	     (setq gid (read ins))
	     (push (list uid gid name) users)))))
    (setq users (sort users #'<= #'car))
    (dolist (u users)
       (format out "~A ~A ~A~%" (car u) (cadr u) (caddr u)))
  ))
