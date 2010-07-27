;;
;;

(require :httpfcgi "/usr/local/eus/lib/llib/httpfcgi")
(require :web-counter "web-counter")

(defvar *count* 0)
(setq *action* "/fcgi/euscounter.fcgi")

;; (setq db (instance pq:pgsql :init :dbname "t.matsui"  :user "t.matsui"))

(fcgi-loop
   (incf *count*)
   ;; (format *error-output* "fcgi-eus connection accepted~%")
   (webcounter-top nil)
   )

