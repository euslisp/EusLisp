;;
;;

(require :httpfcgi "/usr/local/eus/lib/llib/httpcgi")
(require :web-counter "web-counter")
(require :gifcat)

(setq *action* "/cgi-bin/euscounter.cgi")

;; uncomment the following line to store access data in postgresql
;; (setq db (instance pq:pgsql :init :dbname "t.matsui"  :user "t.matsui"))

;; call with T, if database is used
(webcounter-top nil)

(unix::exit)
)

