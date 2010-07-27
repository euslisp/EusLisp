;;;; http.l
;;;;
;;;  Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;

(require "kana_euc.l")
(require :html-readtable)

(defun read-string-upto (end-char strm)
   (let ((char) (r))
      (while (eq (setq char (read-char strm)) #\space) )
      (while (not (eql char end-char))
	 (push char r)
	 (setq char (read-char strm)))
      (if r (coerce (nreverse r) string))) )

(defun split-tag-args (s)
   (let ((*readtable* *html-readtable*) (p) (result)
	 (eof (cons nil nil)) (strm (make-string-input-stream s)))
 ;;      (print s *error-output*) 
      (while (not (eql (setq p (read strm nil eof)) eof))
	 (if (stringp p) (setq p (sjis2euc p)))
	 (push p result))
      (nreverse result)))
      
#| HTTP header for a gif document
	("HTTP/1.1 200 OK"
	 "Date: Tue, 28 Jan 2003 12:44:05 GMT"
	 "Server: A p a c h e/FSV20021004 B e n - S S L/FSV20021004 (Unix)"
	 "Last-Modified: Tue, 28 Jan 2003 12:04:21 GMT"
	 "ETag: \"2ded05-3e5d-3e3671c5\""
	 "Accept-Ranges: bytes"
	 "Content-Length: 15965"
	 "Connection: close"
	 "Content-Type: image/gif"
	 "")

Set-Cookie: sampler=1044752154;DOMAIN=.aol.com:2080;PATH=/;EXPIRES=Sat, 31 Jan 2004 00:55:54 GMT
P3P: CP="NOI OUR PSA DEV PSD STA COM CUR"
Location: http://wp.netscape.com/http:/netscape.com
MIME-Version: 1.0
Date: Sun, 09 Feb 2003 00:55:54 GMT
Server: AOLserver/3.5.1
Content-Type: text/html
Content-Length: 330
Connection: close

request-http returns a following list for an html document
	((http/1.1 200 ok)
	 (date "Tue, 28 Jan 2003 13:38:29 GMT")
	 (server "Apache/1.3.20 (TurboLinux) mod_throttle/3.1.2 PHP/3.0.18")
	 (last-modified "Tue, 28 Jan 2003 12:30:46 GMT")
	 (etag "\"12c01a-17a8-3e3677f6\"")
	 (accept-ranges bytes)
	 (content-length 6056)
	 (content-type text/html))

|#

(defun request-http (url &key (timeout 10) (retry 5))
   ;; send an http request and returns a socket stream to read the reply 
   (let ((s))
      (setq url (url-pathname url))
      (while (and (not (streamp (setq s  (send url :connect timeout))))
		(> (decf retry) 0)) )
      (if (not (streamp s)) (return-from request-http nil))
      ;; connction established
      ;; send an http request command
      (format s "GET ~a HTTP/1.1~cHOST: ~a~c~c"
			(namestring url) 
			#\newline 
			(unix:getenv "HOST")
			#\newline 
			#\newline 	; one more CRLF at the end of a request
			)
      (finish-output s)
      s))	;; this stream must be closed by the caller

(defun read-http-header (strm)
   (let ((eof (cons nil nil)) (line) (lines)
	 (directive) (value)
	 (*readtable* *html-readtable*))
	;; "HTTP/1.1 200 OK"
      (push (list (read strm) (read strm) (read strm)) lines)
      (read-line strm)
      (while (and (not (eql (setq line (read-line strm nil eof)) eof))
		  (> (length line) 0))
	  (with-input-from-string (s line)
	     (setq directive (read s))
	     (case directive	
		((Set-Cookie P3P Location date server last-modified etag)
		 (read-char s) (skip-blank s)
		 (setq value (send s :tail-string)))
		(t (setq value (read s))) ) )
	  (push (list directive value) lines) )
      (nreverse lines)))


(defun read-html (&optional (strm t))	;; read the html body
  ;; (setq http-stream strm)
  (let ((result) (directive) (directive-string)
	(word) (eof (cons nil nil))
	(tag) (ch) (line)
	(*readtable* *html-readtable*) (tag-arg) )
    (labels ((terminate-string () 
		(when word
		    (push (sjis2euc (coerce (nreverse word) string)) result)
		    (setq word nil)))
	     (skip (strm &rest skip-chars)
	      (let ((skip-list skip-chars) (eof (cons nil nil)))
	         (while (and skip-list
			     (not (eq  (setq ch (read-char strm nil eof)) eof)))
		    (cond ((eql ch (car skip-list)) (pop skip-list) )
		          (t (setq skip-list skip-chars))))
		      ))
	      )
	;;
	;; html body
	;;
      (while (not (eql (setq ch (read-char strm nil eof)) eof))
	 (cond
	    ((eq ch #\<) 
		(terminate-string)
		;(setq ch (peek-char strm))
		(setq directive (read strm nil eof))
		(setq directive-string (symbol-pname directive))
		(cond ((equal (subseq (symbol-pname directive)
					0 (min 3 (length directive-string)))
			      "!--") 	; (member directive '(!-- !--//))
			(skip strm #\- #\- #\>) ) 
		      ;; ((eq ch #\!)  (skip strm #\- #\- #\>) ) ;; <!-- -->
		      (t
			;; (setq directive (read-delimited-list #\> strm))
			;; (setq directive (read strm))
			(setq tag-arg (read-string-upto '#\> strm))
			(if (stringp tag-arg)
			    (setq tag-arg (split-tag-args tag-arg)))
			(cond ((eql directive '/HTML)
				(return-from read-html
					(nreverse result)))
			      ((eql directive '/body)
				(push (list directive) result)
				(return-from read-html (nreverse result)))	
			      (t (push (cons directive tag-arg) result))))
			 )) 
	    ((eq ch #\&) t)	;escape
	    ((member ch '(#\return #\newline))
		(terminate-string))
	    (t (push ch word))
 	    )
        )  )
    (nreverse result) ))

;; returns a list of the header and the HTML body
(defun read-http (url &key (timeout 10) (retry 5))	;;url-pathname
   (let ((s) (header) (body) (conlen))	;timeout=10s, longer than usual
      (setq s (request-http url :timeout timeout :retry retry))
      (cond ((streamp s)	;; connection established, ready to read
	     (setq header (read-http-header s))
	     ;; check HTTP/1.1 200 OK
	     ;; (if (not (eql (third (car header)) 'ok)) (error "HTTP")) 
	     (case (second (assoc 'content-type header))
		(text/html  (setq body (read-html s)))
		(t	;otherwise, a binary data
		    (unless (setq conlen (second (assoc 'content-length header)))
			(setq conlen
			      (let ((*read-base* 16))
				 (read-from-string (read-line s)))))
		    ;; (format *error-output* "read-http: content length=~s~%" conlen)
		    (setq body (send s :in :read-bytes conlen))
		    ))
	     (close s)
	     (list header body))
	    (t (close s) nil))
   ) )

(defun read-http-raw (url &key (timeout 10) (retry 5) (lines nil))
   ;;url-pathname
   (let ((s)	;timeout=10s, longer than usual
	 (html) (lines))
      (setq url (url-pathname url))
      (while (and (not (streamp s))  (> (decf retry) 0))
	 (setq s  (send url :connect timeout)))
      (if (not (streamp s)) (return-from read-http-raw nil))
      ;; connction established
      (unwind-protect 
	 (progn
            (format s "GET ~a HTTP/1.1~cHOST: ~a~c~c"
			(namestring url) 
			#\newline 
			(unix:getenv "HOST")
			#\newline 
			#\newline 	; one more CRLF to indicat NULL line
			 )
            (finish-output s)
	    (let ((eof 'eof) (line) (lines) (header))
	      (setq header (read-http-header s))
	      (while (not (eq (setq line (read-line s nil eof)) eof))
		    ;; (format t "~a~%" line)
		    (push line lines))
	      (list header (nreverse lines))
	      ;; (read-lines-till-eof s)
	      ;; (read-html s)
	      ))
	 (close s) )
   ) )

;; (setq a (url-pathname "http://tenki.or.jp/YOHOU/40.html"))
;; (read-http a)



(defun extract-html (tag html-list)
   ;; returns a list of strings (and tags) sandwitched by tag and /tag.
   (let ((end-tag (intern (concatenate string "/" (symbol-pname tag))))
	 (result) (res) (extract))
      (dolist (h html-list)
	  (cond ((and (consp h) (eql (car h) tag)) (setq extract t))
		((and (consp h) (eql (car h) end-tag))
		 (setq extract nil)
		 (push (nreverse res) result)
		 (setq res nil))
		(extract (push h res))))
      (nreverse result))
  )

(defun remove-html-tags (html-list)
   (remove-if #'consp html-list))

   

;;----------------------------------------------------------------

(provide :http "@(#)$Id: http.l,v 1.1.1.1 2003/11/20 07:53:25 eus Exp $")

