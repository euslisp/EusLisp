(load "/usr/local/eus/lib/llib/httpfcgi.l")
(defvar *count* 0)
(fcgi-loop
   (setq cookie (get-cookie))
   (setq newcookie
	 (make-cookie 'eus-fcgi-demo (random-cookie)
			:domain "matsui.jpn.ph"
			:expires (* 5 24 3600)))
   (if (null cookie)
       (http-header :cookie (list newcookie))
	(http-header))
   (html-header)
   (incf *count*)
   ;; (format *error-output* "fcgi-eus connection accepted~%")
   ;; (finish-output *error-output*)
   (format *standard-output* "~%<body><h1>Hello World ~d</h1>~%<pre>~%" *count*)
   (gen "cookie=~s~%newcookie=~s~%~%" cookie newcookie)
   (dolist (ue (unix:environ))  (gen "    ~a<br>" ue))
   (format *standard-output* "<h2>Good-bye</h2></body>~%")
   )
