;;****************************************************************
;; httpcgi.l
;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory.
;;
;;****************************************************************

(defun euserror-exit (code msg1 form &optional (msg2))
	  (format *error-output*
		"eus error ~s ~s ~s ~s~%" code msg1 form msg2)
	  (unix::exit 1))

(unless (unix:isatty 0)
   (setq *error-handler* 'euserror-exit)
   (setq *exit-on-fatal-error* t)
   )

;; time must be loaded before kana
(require :time "time" :package :LISP)
(require :kana "kana_euc.l")
(require :html-readtable)	;; needed for parsing cookies

(defvar *action* (unix:getenv "SCRIPT_NAME"))

(defvar *fcgi* nil)
(defparameter *cgi-out* *standard-output*)
;(setq *standard-output* *error-output*)
(setq *terminal-io* (make-two-way-stream *standard-input* *error-output*))

(defvar *charset* :EUC)
;;(defvar *charset* :SJIS)
;; (defvar *charset* :JIS)

(setf (get :euc :charset) 'x-euc-jp)
(setf (get :jis :charset) 'iso-2022-jp)
(setf (get :sjis :charset) 'sjis_jp)


(defun esj (str)
  (case *charset*
	(:euc str)
	(:sjis (euc2sjis str))
	(:jis (eus2jis str))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun htag (tag &rest params)
  (gen "<~a " tag)
  (dolist (p params) (format *cgi-out* "~a" p))
  (gen ">~%" tag))

(defun enclosed-html (tag &rest forms)
  (gen "<~a>" tag)
  (dolist (p forms) (format *cgi-out* "~a" p))
  (gen "</~a>~%" tag))

(defun html (&rest forms)
  (with-output-to-string (s)
     (dolist (p forms) (format s "~a" p))
     (format s "~%")
     (get-output-stream-string s)))

(defun gen (fmt &rest args)
   (apply #'format *cgi-out* fmt args))

(defun escape-tilda (s)
   ;; http seems to use '~' (tilda) for escaping
   (when (stringp s)
    (let ((ch))
      (with-output-to-string (so)
        (with-input-from-string (si s)
	   (while (setq ch (read-char si nil nil))
	      (if (eql ch #\~) (write-byte #\~ so))
	      (write-byte ch so)))
	(get-output-stream-string so)))
    )
  )   

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun http-header (&key (type "text/html")
			 (charset *charset*) ;; or EUC, EUC_JP
			 (Accept-Ranges nil)
			 (Length	nil)
			 (Connection nil)
			(cookie )
			 )
    (gen "Content-type: ~a~%" type)
    (if Accept-Ranges  (gen "Accept-Ranges: ~a~%" accept-ranges))
    (if length (gen "Content-Length: ~d~%" length))
    (if Connection (gen "Connection: ~a~%" Connection))
    (if cookie
	(dolist (ck cookie)
	   (gen "Set-Cookie: ~a~%"
		(cond ((consp ck) (apply #'make-cookie ck))
		      ((stringp ck) ck)
		      (t (error "list or string expected for a cookie" ck))) )
   	) )
    (gen "~%")
    )


(defun html-header (&key (title (concatenate string (unix:gethostname)
					" EusLisp CGI"))
			 (type "text/html")
			 (charset *charset*) ;; or EUC, EUC_JP
			 (stylesheet nil)
			 (background "B0F0E0")
			 (keywords)		)
    (gen "<head><title>~a</title>~%" title )
    (gen "<META http-equiv=\"Content-Type\" 
		content=\"~a; charset=~a\">~%"
	 type
	 (if (keywordp charset) (get charset :charset) charset) )
    (if keywords
	(gen "<META name=keywords content=\"~a\">~%" keywords))
    (if stylesheet
	(gen "<link rel=stylesheet href=~a type=text/css>~%" stylesheet))
    (gen "</head>~%<body bgcolor=#~a>~%"  (string background) ))


;;

(defun email-address-p (s)
  (let ((p))
     (and (stringp s)
	  (> (length s) 4)
	  (< (length s) 128)
	  (setq p (position #\@ s))
	  (null (position #\@ s :start (1+ p)))
	  (find #\. s :start (1+ p))
	  t))) 

(defun transpose-list (s)
   (let (r)
     (dotimes (i (length (car s)))
	(push (mapcar #'(lambda (row) (nth i row)) s) r))
     (nreverse r)))
      

(defun html-table (lst &key
			heading 	;; ("name" "address" "phone" ...)
			(table-option "")	;; "border=1"
			bgcolor
			border		;;
			cellspacing
			cellpadding
			width
			rules
			frame
			table		;; SQL table
			href		;; "xxx.cgi"
			command		;; "xxx.cgi?command=yyy
			((:col col-opt) nil)	;; align, valign, span, width
			align
			(href-column 0) ;;	
			)
  (let ((outstr (make-string-output-stream)) (col 0) (column))
     (format outstr "<table~a~a~a~a~a~a~a~a>~%"
		(if border (format nil " border=~a" border) "")
		(if bgcolor (format nil " bgcolor=~a" bgcolor) "")
		(if cellspacing (format nil " cellspacing=~a" cellspacing) "")
		(if cellpadding (format nil " cellpadding=~a" cellpadding) "")
		(if width (format nil " width=~a" width) "")
		(if frame (format nil " frame=~a" frame) "")
		(if rules (format nil " rules=~a" rules) "")
		(if table-option (format nil " ~a" table-option) "" ))
     (when col-opt
	(dolist (c col-opt)   (format outstr "<col ~a>" c))
	(format outstr "~%"))
     (when heading
	(format outstr "<tr>")
	(dolist (h heading)  (format outstr "<th> ~a </th> " h))
	(format outstr "</tr>~%"))
     (when align (format outstr "<tbody align=~a>~%" align))
     (dolist (row lst)
        (format outstr "<tr>")
	(setq column 0)
        (dolist (col  row)
	   (if (= (incf column) href-column)
		(format outstr
		    "<td> <a href=\"~a?table=~a&command=~a&arg=~a\">~a</td>~%"
			href table command col col)
		(format outstr "<td> ~a </td> "
			(cond ((derivedp col interval-time)
				    (send col :iso-string))
			      ((email-address-p col)
				(format nil "<a href=\"mailto:~a\">~a</a>" col col))
			      ((stringp col) (esj col))
			      (t col)) ) )) 
          (format outstr "</tr>~%"))
     (format outstr "</table>~%")
     (get-output-stream-string outstr))
  )

(defun gen-action (&optional (action *action*) (method "POST"))
      (gen (html "<form action=\"" action "\" method=" method ">~%")) )

;;
;; button, checkbox, radio, text, 
;;

(defun input-form (type name &optional (value "") (size 60) (misc ""))
   (format nil "<input type=~a name=~a value='~a' size=~a ~a>~%"
	type name value size misc)) 

(defun text-input-form (name value &optional (default-size 60))
   (setq value 
	(cond ((stringp value) (euc2sjis value))
	      ((derivedp value interval-time)
		(send value :iso-date-string))
	      (t  value)))
   (let* ((slen (length (string value))) (col) (row) (len))
      (cond ((> slen default-size)
		(setq row 
		      (round (* 1.5 (max
			  (/ (float slen) default-size)
			  (count #\newline value)))))
		(html "<textarea cols=" default-size " rows=" row
			" name=" name ">~%"
			value "</textarea>"))
	    (t (input-form 'text name value default-size)))))

(defun goback-button ()
   (gen "~a~%"
      (input-form 'button "go-back" "go-back" 7 "onClick=history.go(-1)")))

(defun menu-form (name values &optional size multiple)
   (if size
	(gen "<select name=~a size=~d ~a>~%"
		name size (if multiple 'multiple ""))
	(gen "<select name=~a>" name))
   (dolist (val values)
	(gen "<option value=~a> ~a </option>~%"
	     (if (consp val) (first val) val)
	     (if (consp val) (second val) val))
	)
   (gen "</select>~%")
   )


;;
;; query value
;; parameters obtained from client browser
;;

(defun get-cgi-query ()
   (let ((query))
    (if (string-equal (unix:getenv "REQUEST_METHOD") "GET")
	(setq query  (unix:getenv "QUERY_STRING"))
	(let ((len (unix:getenv "CONTENT_LENGTH"))
		(EOF (cons nil nil))
		(ch))
	   (when len (setq len (read-from-string len))
	     (setq query (make-string len))
             ;; Uread is not available to fast-cgi
	     ;; Note EOF is not available, either.
             ;; (unix:uread 0 query)  
             (dotimes (i len)
		(setf ch (read-char *standard-input* nil EOF))
		(when (eq ch EOF)
		    (setq query (subseq query 0 i))
		    (return query))
                (setf (char query i) ch)
                )
             )
	))
    query)
 )


(defun qval (arg query)
   (let ((query (cadr (assoc arg query))))
     (if query (sjis2euc query) nil)) )


(defun xqval (arg query &optional (default nil))
   (let ((q (assoc arg query)))
      (if q
	  (read-from-string (sjis2euc (second q)) nil default)
	  default)))

(defun parse-http-query (query-string)
  (labels 
      ((translate-http-query-string (query-string)
         (let ((result) (len (length query-string)) (in 0) (out 0) (ch))
	     (while (< in len)
		(setq ch (char query-string in))
		(incf in)
		(cond ((eql ch #\+) (setq ch #\space))
		      ((eql ch #\%)
			(setq ch
			    (read-from-string (concatenate string
				"#x" (subseq query-string in (+ in 2)))))
			(incf in 2))
		      (t (setq ch ch)))
	        (setf (char query-string out) ch)
		(incf out))
	     (subseq query-string 0 out)))
           )
   ;;
   (let ((res) (p 0) (p2 0) (result))
      (unless (find #\= query-string)
	 (return-from parse-http-query nil))
      (while (setq p2 (position #\& query-string :start p))
	 (push (subseq query-string p p2) res)
	 (setq p (1+ p2)))
      (push (subseq query-string p) res)
      ;;
      (dolist (r res)
	(setq p (position #\= r))
	(push
	   (list 
		 (read-from-string (subseq r 0 p))
	         (translate-http-query-string (subseq r (1+ p))))
	   result)      )
       result) ) )
   ;;


;;;
;;; COOKIES
;;;
;; zdnet sends the following cookies
;; Set-Cookie: PACK=zd2-959169262-7911; path=/; domain=.zdnet.co.jp;
;; expires=Friday, 31-Dec-2010 23:59:59 GMT
;; Set-cookie: NGUserID=d29b8f48-3590-959169262-1;
;; expires=Wednesday, 30-Dec-2037 16:00:00 GMT; path=/
;; 
;; netscape.com sends the following
;; Set-Cookie: UIDC=203.138.1.9:0959170315:526113;domain=.netscape.com;
;; path=/;expires=31-Dec-2010 23:59:59 GMT


(defun random-cookie (&OPTIONAL randomizer)
   (sxhash
	(concatenate string (unix:getenv "HTTP_HOST")
			    (unix:asctime (unix:localtime))
			    randomizer)))

(defun make-cookie (key value
		   &key (path "/")
			(domain (unix:gethostname))
			(expires #| (* 3600 24) |# nil)
		 	(port nil)
			)
   "sends the Set-Cookie statement in a HTTP header"
;; The date string is formatted as: 
;;      Wdy, DD-Mon-YYYY HH:MM:SS GMT
;; This is based on RFC 822, RFC 850, RFC 1036, and RFC 1123, with the variations that the
;; only legal time zone is GMT and the separators between the elements of the date must be
;; dashes. 
;; Expires is an optional attribute. If not specified, the cookie will expires when the user's
;; session ends. 
   (if (numberp expires)
	(setq expires
	      (send (now) :add (instance interval-time :make :second expires))))
   (format port "~a=~a; path=~a; domain=~a; ~a~a"
	key value path domain
	(if expires " expires=" "")
	(if expires
	    (cond ((stringp expires) expires)
		  ((derivedp expires interval-time) ; (send expires :string :full)
			(format nil "~a, ~a-~a-~a ~a:~a:00 GMT"
			    (send expires :weekday-string)
			    (digits-string (send expires :day) 2)
			    (digits-string (send expires :month) 2)
			    (digits-string (send expires :year) 4)
			    (digits-string (send expires :hour) 2)
			    (digits-string (send expires :minute) 2)
			) )
		  ((numberp expires) expires)
		  (t (error "cookie expires is not a string.")))
	     "") )
   )


(defun get-cookie (&optional (cookie-string (unix:getenv "HTTP_COOKIE")) )
   "Extracts cookies from the HTTP_COOKIE environment var."
   (let ((cookies) (key) (val)
	 (*readtable* *html-readtable*))
     (unless cookie-string (return-from get-cookie nil)) 
     (with-input-from-string (s cookie-string)
	   (while (setq key (read s nil nil))
	      (if (eql key 'expires)	;;expiration date is supposed to appear at the end
		  (progn (read-char s)
			 (setq val (send s :tail-string))
			 (send s :discard))
		  (setq val (read s nil nil)))
	      (push (list key val) cookies)))
      (nreverse cookies)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(provide :httpcgi)

