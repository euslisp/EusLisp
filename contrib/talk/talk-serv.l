;;;;;;;;;;;;;;;;;;;;;;;;;;
;; socket server

(defvar count 0)
(setq *db* (read-database))
(setq mytalk "hello")

(defun close-talk-connection (strm)
	(warning-message 5 "; talk connection ~s is being closed.~%"
		strm)
	(send *top-selector* :remove-port strm)
	(close strm)
	(write-database)
	 )


(defun talk-top (strm)
   (let ((line) (eof (cons nil nil)) )
      (setq line (read strm nil eof))
      (cond ((eql line eof) (close-talk-connection strm))
	    (t
		(case (car line)
		  (bye  (close-talk-connection strm))
		  (t	(print line)
			(remember mytalk (fourth line))
			(setq ans (answer (freq (fourth line))))
			(setq mytalk (third ans))
			(format strm "(~s ~s ~s ~s)~%"
				(first line) (second line) (third line)
				 mytalk)
			(incf count)) )
	      )
	)) )

(defun accept-talk-connection (sp)
   (let ((s  (make-server-socket-stream sp)))
      (send s :name (format nil "TALK_~d" (send s :infd)) )
      (send *top-selector* :add-port s 'talk-top s)
      (warning-message 4
	 "; talk connection request on ~s; ~s is created~%" sp s)
	))

(defun init-talk-server (&optional (port 7040))
   (let* ((sa (make-socket-address :port port :domain af_inet))
	  (sp (make-socket-port sa)))
      (send *top-selector* :add-port sp 'accept-talk-connection sp))
   )

;;;;;;;;;;;;;;;;;;;;;


