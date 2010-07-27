
(load "/usr/local/eus/lib/llib/httpfcgi.l")
(defvar *count* 0)
(fcgi-loop
   ;; get-cookie has been done.
   (incf *count*)
   (setq con (fcgi-connection 'eusid))
   (set-cookie 'eusid (send con :cookie))
   (html-header)
   (gen "~%~%")
   (gen (html *cookies* con))
   (gen (html "~%<body><h1>Hello World " *count* "</h1>~%" ))
   (gen (html (unix:environ)))
   (gen (html "<pre>~%"))
   (gen (html (send-all *fcgi-connections* :cookie)))
   (gen (html "</pre>~%"))
   (gen "<h2>Good-bye</h2>~%")
   (gen "</body> </html>~%")
   )






