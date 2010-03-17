;;;;
;;;; weather.l
;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;; rivised on January 4, 2001 to allow either ( or zenkaku-(.
;; connects to the weather server 
;; and gets kanji texts for weather report
;; for overall japan, or for a specific locations.
;; The reports can also be used to update postgres database.
;;
;; This file should be saved in EUC encoding, since http.l reads
;; http texts in EUC.
;;


(let ((*package* (find-package "LISP")))
   (require :time "time"))

(require :http "http")
(require :kana "kana_euc")

#|
(defparameter *weather-server* "shamal")
(defparameter *weather-port* 7093)
(defun weather-report (&optional (place "gaikyo") (day 0))
  (let* ((sock
	    (make-client-socket-stream
		(make-socket-address :host *weather-server*
				     :port *weather-port*)))
	 (report))
     (if  (equal place  "gaikyo")
	  (format sock "weather gaikyo~%")
	  (format sock "weather place ~a ~d~%" place day))
     (setq report (read-line sock))
     (if (zerop (aref report 0)) (setq report (subseq report 1)))
     (talk report)
     (close sock)
     report))
|#


(defparameter *tenki-url* (url-pathname "http://tenki.or.jp/YOHOU/"))
(defparameter *wni-url* (url-pathname "http://www.wni.co.jp/cww/index.html"))


(defparameter *tenki-fnames*
	'((ibaraki "40.html") (tochigi "41.html") (gunma "42.html")
	  (saitama "43.html") (tokyo "44.html")
	  (hokkaido "11.html") (sendai "34.html")
	  (nagoya "51.html") (osaka "62.html")
	  (hiroshima "67.html") (ko-chi "74.html")
	  (fukuoka "82.html") (okinawa "91.html")))

#| SQL to create wether_report table
create table weather_report
	(id serial, district symbol, url text, time datetime,
	abstract text, today text, tomorrow text,
	max_temp int4, min_temp int4);
create table weather_report_history
	(id serial, district symbol, url text, time datetime,
	abstract text, today text, tomorrow text,
	max_temp int4, min_temp int4);
insert into weather_report (district, url) values
	('hokkaido', 'http://tenki.or.jp/YOHOU/11.html');
insert into weather_report (district, url) values
	('sendai',  'http://tenki.or.jp/YOHOU/34.html');
insert into weather_report (district, url) values
	('ibaraki', 'http://tenki.or.jp/YOHOU/40.html');
insert into weather_report (district, url) values
	('tochigi', 'http://tenki.or.jp/YOHOU/41.html');
insert into weather_report (district, url) values
	('gunma',   'http://tenki.or.jp/YOHOU/42.html');
insert into weather_report (district, url) values
	('saitama', 'http://tenki.or.jp/YOHOU/43.html');
insert into weather_report (district, url) values
	('tokyo',   'http://tenki.or.jp/YOHOU/44.html');
insert into weather_report (district, url) values
	('nagoya',  'http://tenki.or.jp/YOHOU/51.html');
insert into weather_report (district, url) values
	('osaka',   'http://tenki.or.jp/YOHOU/62.html');
insert into weather_report (district, url) values
	('hiroshima', 'http://tenki.or.jp/YOHOU/67.html');
insert into weather_report (district, url) values
	('ko-chi', 'http://tenki.or.jp/YOHOU/74.html');
insert into weather_report (district, url) values
	('fukuoka', 'http://tenki.or.jp/YOHOU/82.html');
insert into weather_report (district, url) values
	('okinawa', 'http://tenki.or.jp/YOHOU/91.html');
UPDATE table SET column = expression [, ...]
    [ FROM fromlist ]
    [ WHERE condition ]
|#

(defun http-weather-report (place)
   (let ((report) (statement) (abstract)
	 (today) (tomorrow) (max-temp) (min-temp) (x))
      (send *tenki-url* :name (cadr (assoc place *tenki-fnames*)))
      (setq report (read-http *tenki-url* :timeout 10 :retry 5))
      (if (null report) (return-from http-weather-report nil))
      (setq report 
	    (mapcar #'remove-html-tags 
			(extract-html 'table (second report))))
      (setq statement
	    (apply #'concatenate string (butlast (cdr (first report)) 2)))
      (setq abstract
	    (apply #'concatenate string
		(string-left-trim '(#\space)  (nthcdr 4 (second report)))))
      (setq abab abstract)
	;; 
      (setq today (string-match "今日" abstract 0))
      (unless today 
	    (setq today (string-match "今夜" abstract 0)) )
      ;; (format t "today=~s~%" today)
      (setq x (string-match "("   abstract today)) ;)
      (unless x (setq x string-match "（" abstract today))
      (setq today
	    (string-trim '(#\space)
	    	(subseq abstract (+ today 4) x)))
	;;
      (setq tomorrow (string-match "明日" abstract x))
      ;; (format t "tomorrow=~s~%" tomorrow)
      (setq x (string-match "(" abstract tomorrow))
      (unless x (setq x string-match "（" abstract tomorrow))
      (setq tomorrow 
		(string-trim '(#\space)
			(subseq abstract (+ tomorrow 4) x)))
	;;
      (setq max-temp (string-match #|"日中の最高"|# "最高" abstract x))
      (setq x (string-match "(" abstract max-temp))
      (unless x (setq x string-match "（" abstract max-temp))
      (setq max-temp
	    (remove #\space (subseq abstract (+ max-temp 10) x) :count 100) )
      (setq max-temp (euc-number (euc-string-trim euc-space max-temp)))
	;;
      (setq min-temp (string-match "朝の最低" abstract 0))
      (when min-temp 
	      (setq x (string-match "(" abstract min-temp))
	      (unless x (setq x string-match "（" abstract min-temp))
	      (setq min-temp
		    (remove #\space (subseq abstract (+ min-temp 8) x)
			 :count 100) )
	      (setq min-temp (euc-number (euc-string-trim euc-space min-temp))))
      (list statement today tomorrow max-temp min-temp)
      )
   )


(defun wni-report ()
   (let ((report (read-http *wni-url*)) (rep))
      (setq report
	    (remove-if-not #'stringp (second report)))
      (while (cddr report)
	 (setq rep (pop report))
	 (if (string-match "概況" rep)
	     (return-from wni-report (third report)))))
  )

(defun update-weather-report (db district)
   (let ((report (http-weather-report district)))
     (when report
	(with-open-file (log "/tmp/weather-log" :direction :output
				:if-exists :append  :if-does-not-exist :create)
	   (format log "~a~%~%" (car report)))
	(send db :exec (format nil  "update weather_report set
		time='~a',
		abstract='~a', today='~a', tomorrow='~a',
		max_temp=~a, min_temp=~a
		where district='~s'"
		(send (now) :iso-string)
		(car report) (second report)
		(third report) (fourth report)
		(if (fifth report) (fifth report) 100) 
		district)) 
	(send db :exec (format nil "insert into weather_report_history
		(district, time, abstract, today, tomorrow, max_temp, min_temp)
		values ('~s', '~a', '~a', '~a', '~a', '~a', '~a')"
		district (send (now) :iso-string)
		(car report) (second report)
		(third report) (fourth report)
		(if (fifth report) (fifth report) 100) )
		)
        )
   ))

(defun update-weather-reports (db)
  (dolist (dis *tenki-fnames*)
    (print (car dis))
    (update-weather-report db (car dis))))

(defun get-weather-report (district &optional (kind 'today))
	;; kind can either be today, tomorrow, max_temp, min_temp
  (caar
   (send db :exec 
	(format nil
		"select ~s from weather_report where district='~s'"
		kind district))))


