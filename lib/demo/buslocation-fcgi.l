(load "/usr/local/eus/lib/llib/httpfcgi.l")
(load "buslocation.l")
(defvar *count* 0)
(setq *action* "/fcgi/bus.fcgi")

(fcgi-loop
   (incf *count*)
   ;; (format *error-output* "fcgi-eus connection accepted~%")
   ;; (finish-output *error-output*)

   ;;(format *standard-output* "~%<body><h1>Hello World ~d</h1>~%" *count*)
   ;; (gen (html (unix:environ)))
   ;; (gen "~%<br>user=~A<br>~%" (unix:getenv "USER"))

   (setq db (instance pq:pgsql :init :dbname "t.matsui"  :user "t.matsui"))

   (buslocation-top)
   ;; (format *standard-output* "<h2>Good-bye</h2></body>~%")
   )

