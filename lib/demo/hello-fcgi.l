;;
;;

(require :httpfcgi "/usr/local/eus/lib/llib/httpfcgi")
(require :web-counter "web-counter")

(defvar *count* 0)
(setq *action* "/fcgi/hello.fcgi")

(setq db (instance pq:pgsql :init :dbname "t.matsui"  :user "t.matsui"))

(fcgi-loop
   (incf *count*)
   ;; (format *error-output* "fcgi-eus connection accepted~%")
   (http-header)
   (html-header :charset :euc)

   (gen "<h1>Hello World</h1>~%")
   (gen "<h2>Hello World</h2>~%")
   (gen "</body> </html>~%")
   )

;;



