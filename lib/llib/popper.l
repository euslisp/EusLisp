;;;; popper.l
;;;; (c) 1998 Toshihiro Matsui, Electrotechnical Laboratory
;;;;
;;;  (popper :host "etlpom.etl.go.jp" :user "someone" :password "pass")
;;;
;;;  will return a list of mail-message objects retrieved from the host.
;;;  A mail-message object holds from-address, subject and content.
;;;  All other message field like "Reply-to:", "Content-type:" are not
;;;  parsed, and are just put in its property-list.
;;;  The content consists of a list of strings, each string representing
;;;  one line in the message bocy.
;;
;;;  (sendmail :host "etlpom" :receiver "euslisp@etl.go.jp" :sender "matsui"
		:message (list "This is"  "a message."))
;;;   will send an Email message in the smtp (sendmail) protocol.
;;;
;;;   last maintained on Nov. 24, 1999


(export '(popper mail-message))

(defvar *popper-readtable* (copy-readtable))
(proclaim '(special *popper-readtable*))
(set-syntax-from-char #\: #\space *popper-readtable*)
(defclass mail-message :super propertied-object
		:slots (id from-address from-name subject content))

(defmethod mail-message
 (:init (&optional (id 0))
    (setf (mail-message-id self) id)
    self)
 (:put (name value)
    ;; (format t ";; mail-message :put ~s ~s~%" name value)
    (case name
      (:from (send self :from (car value)))
      (:subject (send self :subject (car value)))
      (:content (send self :content value))
      (t (setf (get self name) value))
      )
     name)
 (:from (value)
    ;; 1. someone@etl.go.jp
    ;; 2. someone@etl.go.jp (Toshihiro Matsui)
    ;; 3. Toshihiro Matsui <someone@etl.go.jp>
    (let ((pos))
    (cond ((and (setq pos (position #\( value)) (find #\) value))
	   (setq from-address (subseq value 0  pos))
	   (setq from-name (subseq value (1+ pos) (position #\) value)))
	   )
	  ((and (setq pos (position #\< value)) (find #\> value))
	   (setq from-address (subseq value (1+ pos) (position #\> value))) ;
	   (setq from-name 
		 (if (> pos 0)  (subseq value 0  (1- pos)) nil))
	   )
	  (t (setq from-address value from-name nil))
	  )))
 (:from-address () from-address)
 (:from-name () from-name)
 (:subject (&optional (val subject))
    (setq subject val))
 (:content (&optional (val))
    (if val (setq content val))
    content)
 )

(defun get-pop-list (s)
   (format s "list~%")
   (read-line s)
   (let ((ln) (lines) (ss))
     (while (not (eql (aref (setq ln (read-line s)) 0) #\.))
	(setq ss (make-string-input-stream ln))
	(push (list (read ss) (read ss)) lines))
     (nreverse lines))
   )

(defun get-pop-message (s n)
   ;; (format s "top ~d 1000~%" n)
   (format s "RETR ~d~%" n)
   (read-line s)	;skip +OK ack
   (let ((mm (instance mail-message :init n))
	 (ln (read-line s)) (ss) (attr) (field) (fields))
      (while (not (and (eql (length ln) 1) (eql (aref ln 0) #\.)))
	 (cond 
	       ((and (not (eql attr :content)) (eql (length ln) 0))
		;; content begins
		(send mm :put attr (nreverse field))
		;; (push (cons attr (nreverse field)) fields)
		(setq attr :content field nil))
	       ((or (eql attr :content)
		    (eql (aref ln 0) #\tab)
		    (eql (aref ln 0) #\space))
		;; continued line
		;; tab and space at the beginning should be removed
		(let ((i 0) (len (length ln)))
		   (while (and (< i len) (or (eql (char ln i) #\space)
					     (eql (char ln i) #\tab)))
			(incf i))
		   (push (subseq ln i) field)) )
	       (t
		;; new field
		(when attr
		    (send mm :put attr (nreverse field))
		    ;; (push (cons attr (nreverse field)) fields)
		    )
		(setq ss (make-string-input-stream ln))
		(setq attr (let ((*package* *keyword-package*)) (read ss)))
		(setq field
		      (list (subseq ln
				    (+ (send ss :count) 2) (send ss :tail))
			)))
		)
	 (setq ln (read-line s))
	 )
      (when (eql attr :content)
	 (send mm :put attr (nreverse field))
	 ;; (push (cons attr (nreverse field)) fields)
	 )
      ;;(nreverse fields)
      mm
      ))

(defun delete-pop-message (s n)
  (let (input)
    (format s "DELE ~d~%" n)
    (setq input (read-line s))
    (unless (eql (aref input 0) #\+) (warn input))
    )
 )

;;;
;;; (popper :host "etlpom.etl.go.jp" :port 110
;;;		:user "matsui" :password "pass")

(defun popper (&key (host)
			    (port (car (unix:getservbyname "pop")))
			    (user)
			    (password)
			    (delete nil))
    (let* ((sa (make-socket-address :host host :port port))
	   (s (make-client-socket-stream sa))
	   (input) (numbers) (eof (cons nil nil))
	   (*readtable* *popper-readtable*)
	   messages)
      (unwind-protect
	 (progn
	        (setq input (read-line s))
	        (if (eql (aref input 0) #\-) (print input))
	        (format s "user ~a~%" user)
		(setq input (read-line s))
	        (when (eql (aref input 0) #\-)
		   ;; (print input)
		   (error ";; popper cannot login ~a" host))
	        (format s "pass ~a~%" password)
		(setq input (read-line s))
		(when (eql (aref input 0) #\-)
		   (print input) 
		   (error ";; popper rejected service to ~a" user))
		(setq lines (get-pop-list s))
		(dolist (ln lines)
		   (print (car ln))
		   (push (get-pop-message s (car ln)) messages)
		   (if delete (delete-pop-message s (car ln)))
		   ))
          (format s "quit~%")
	  (close s))
	(nreverse messages))
   )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun sendmail (&key (host)
		      (sender  (unix:getenv "USER"))
		      (receiver) (message)
		      (port (car (unix:getservbyname "smtp"))) )
    (let* ((sa (make-socket-address :host host :port port))
	   (s (make-client-socket-stream sa))
	   (client (unix:gethostname))
	   (input) (eof (cons nil nil)) )
      (unwind-protect
	 (progn
	    (format s "helo ~a~%" client)
	    (setq input (read-line s nil eof))
	    (when (not (eql (read s nil eof) 250))
		(warn "smtp connection rejected by ~a~%" host)
		(return-from sendmail nil))
	    (read-line s)	;discard the rest of helo reply
	    ;;
	    ;; specify the sender name
	    ;;
	    (format s "mail from:~a~%" sender)
	    (when (not (eql (read s nil eof) 250))
		(warn "smtp host ~a rejected mail sender name ~a~%" host sender)
		(return-from sendmail nil))
	    (read-line s)	;discard the rest of mail command response
	    ;;
	    ;; specify the receiver address
	    (format s "rcpt to:~a~%" receiver)
	    (when (not (eql (read s nil eof) 250))
		(warn "smtp host ~a rejected rcpt name ~a~%" host receiver)
		(return-from sendmail nil))
	    (read-line s)	;discard the rest of RCPT command response
	    ;;
	    ;; send the message contents
	    ;;
	    (format s "data~%")
	    (read-line s nil eof)	;discard data command response
	    (if (consp message)
		(dolist (m message)  (format s "~A~%" m))
		(format s "~a~%" message))
	    (format s ".~%")
	    (when (not (eql (read s nil eof) 250))
		(warn "smtp host ~a rejected to send message~%" host)
		(return-from sendmail nil))
	    (warning-message 5 "message sent successfully.~%")
	    )
	 (format s "quit~%")
	 (close s)
	 ))
   )

(provide :popper "@(#)$Id: popper.l,v 1.1.1.1 2003/11/20 07:53:26 eus Exp $")
