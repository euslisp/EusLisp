;;;;
;;;; web-counter.l
;;;;
;;;  February 5, 2003, (c) Toshihiro Matsui
;;;
 
(require :time "time")
(require :pgsql "pgsql")
(require :httpcgi)
(require :gifcat)

(defvar *counter-data-directory*
	"/home/www/cgi-bin/dream/data/")

;;****************************************************************

#|
drop table web_access;
drop sequence web_access_id_seq;
drop table web_user;
drop sequence web_user_id_seq;

create table web_access (
  id		serial,
  eusid		int4,
  recdate	date,
  rectime	time,
  HTTP_REFERER	text,
  REMOTE_ADDR 	text,
  count		int4,
  repeat	int4,
  page		text,
  request_uri	text
);

create table web_user (
  id		serial,
  eusid		int4 unique,
  handle_name	text,
  remote_addr	text,
  user_agent	text,
  repeat	int4,
  recdate	date
  );  

|#

  

#|
(FCGI_ROLE=RESPONDER
 DOCUMENT_ROOT=/home/www/html
 HTTP_ACCEPT=text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,video/x-mng,image/png,image/jpeg,image/gif;q=0.2,text/css,*/*;q=0.1
 HTTP_ACCEPT_CHARSET=EUC-JP, utf-8;q=0.66, *;q=0.66
 HTTP_ACCEPT_ENCODING=gzip, deflate, compress;q=0.9
 HTTP_ACCEPT_LANGUAGE=ja, en-us;q=0.66, en;q=0.33
 HTTP_CONNECTION=keep-alive
 HTTP_HOST=matsui.jpn.ph
 HTTP_KEEP_ALIVE=300
 HTTP_REFERER=http://matsui.jpn.ph/local/index.html
 HTTP_USER_AGENT=Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.2b) Gecko/20021016
 PATH=/sbin:/usr/sbin:/bin:/usr/bin:/usr/X11R6/bin
 REMOTE_ADDR=218.137.108.172
 REMOTE_PORT=64533
 SCRIPT_FILENAME=/home/www/fcgi/demo.fcgi
 SERVER_ADDR=192.168.78.55
 SERVER_ADMIN=root@matsui.jpn.ph
 SERVER_NAME=matsui.jpn.ph
 SERVER_PORT=80
 SERVER_SIGNATURE=Apache/1.3.20 Server at matsui.jpn.ph Port 80
 SERVER_SOFTWARE=Apache/1.3.20 (TurboLinux) mod_fastcgi/2.4.0 mod_throttle/3.1.2 PHP/3.0.18
 UNIQUE_ID=Pj0OjtqJbKwAACN-E@A
 GATEWAY_INTERFACE=CGI/1.1
 SERVER_PROTOCOL=HTTP/1.1
 REQUEST_METHOD=GET
 QUERY_STRING=
 REQUEST_URI=/fcgi/demo.fcgi
 SCRIPT_NAME=/fcgi/demo.fcgi)
|#

;;;
;;; Fast CGI version
;;;

(defun webcounter-no-db (count)
   (setq now (instance calendar-time :now))
   ;;
   (setq cookies (get-cookie))
   (format *error-output* "cookies=~s~%" cookies)
   (cond ((setq cookie (assoc 'eusid cookies))
	  ;; He has a eusid cookie!
	  (setq cookie (second cookie))
	  (setq update-count t) )
	 (t	;; first user
		;; generate a unique eusid; maybe we can use unique constraint
	      (setq update-count t)
	      (setq cookie (random-cookie)) )	)
    (if update-count (incf count))
   count )


(defun webcounter-db (fname)
  (let (count update-count
	(remaddr)
	(digits) (digit-gifs)
	(cookies) (new-cookie)
	(user-record) (access-record)
	(result-gif-string))
   (setq now (instance calendar-time :now))
   ;;
   (setq count (read-file fname))
   (setq remaddr (unix:getenv 'remote_addr))
   ;;
   (setq cookies (get-cookie))
   (format *error-output* "cookies=~s~%" cookies)
   (cond ((setq cookie (assoc 'eusid cookies))
		;; He has a eusid cookie!
		(setq cookie (second cookie))
		(setq user-record (first (pq:select db
		        '(id recdate remote_addr repeat) 'web_user
			:where `(= eusid ,cookie))))
		;; If there is a record for him, update the repeat count and address.
		;; (format *error-output* "user found id=~d~%"
				(first user-record))
		(if user-record
		    (send db :exec (format nil
			"update web_user set remote_addr='~s', repeat=~d where id=~d"
			(if (member remaddr (third user-record) :test #'equal)
			    (third user-record)
			    (append (third user-record) (list remaddr)) )
			(1+ (fourth user-record))
			(first user-record)) )
		    (send db :exec (format nil		;His cookie is not recorded in our database.
			"insert into web_user (eusid, remote_addr, user_agent, recdate, repeat)
			 values (~d, '~s', '~a', '~a', 1)"
			cookie	(list remaddr)
			(unix:getenv 'http_user_agent)
			(send now :iso-date-string)))
		    )
		;; When did this user access the target page most recently?
		(setq access-record (car (send db :exec (format nil
			"select 
		        id, recdate, rectime, page, count,
			 repeat, eusid, remote_addr
			from web_access
			where page='~a' and eusid=~d and recdate='~a' order by rectime desc"
			id cookie (send now :iso-date-string)))) )
		;; (format *error-output* "access=~s~%" access-record)
		(if (null access-record)
		    (setq update-count t)
		    (let* ((recdate (second access-record))
			   (rectime (third access-record)))
			(setq update-count (not
			      (and (= (send recdate :year)  (send now :year))
				 (= (send recdate :month)  (send now :month))
				 (= (send recdate :day)  (send now :day))
				 (<= 0
				    (- (send now :day-seconds) (send rectime :total-seconds))
				    1800)))) ) )
		)
	   (t	;; first user
		;; generate a unique eusid; maybe we can use unique constraint
	      (setq update-count t)
	      (setq cookie (random-cookie))
	      (while (pq:select db '(eusid) 'web_user :where `(= eusid ,cookie))	
		 (setq cookie (random-cookie (string (random 1000000)))))
	      (send db :exec (format nil
		"insert into web_user (eusid, remote_addr, user_agent, recdate, repeat)
		 values (~d, '~s', '~a', '~a', 1)"
		cookie
		(list remaddr)
		(unix:getenv 'http_user_agent)
		(send now :iso-date-string))) ) )
      ;; update
      (if update-count
	  (with-open-file (of fname	 :direction :output)
	      (format of "~d~%" (incf count))))
      ;;
      (send db :exec (format nil
		"insert into web_access
		 (eusid, page, recdate, rectime, http_host, http_referer, remote_addr, 
		  request_uri, count, repeat) values
		 (~d, '~a', '~a', '~a', '~a', '~a', '~a', '~a', ~d, ~d)"
		 cookie id  (send now :iso-date-string) (send now :iso-time-string)
		 (unix:getenv 'http_host)
		 (unix:getenv 'http_referer) (unix:getenv 'remote_addr)
		 (unix:getenv 'request_uri)
		 count 0))
	#|
        (format *error-output* "euscounter: ~a ~a ~a ~d~%"
		(xqval 'id *forms* nil)
		(send now :iso-date-string) (send now :iso-time-string)
		count) 
	|#
      ;;
      count)
  )

(defun webcounter-top (&optional (db-operation nil))
   (setq *forms* (parse-http-query (get-cgi-query)))
   (setq *db-command* (xqval 'command *forms* 'debug))
   (setq *charset* :euc)
   (finish-output *cgi-out*)
   (let ((fname) (count))
      (setq fname 
	    (format nil "~a/~a.dat" *counter-data-directory* 
			(xqval 'id *forms* 'matsui)) )
      (setq count (read-file fname))
      (setq count (if db-operation
		  	(webcounter-db count)
			(webcounter-no-db count)))
      ;;
      (with-open-file (of fname	 :direction :output)
	      (format of "~d~%" count))
      (setq result-gif-string (number-gif count 6 (xqval 'gif *forms* 'gif1)))
      ;; (format *error-output* "webcounter: eusid=~s~%" cookie)
      ;;
      (http-header
		:accept-ranges "bytes"
		:type "image/gif"
		:length (length result-gif-string)
		:cookie (list (list 'eusid cookie
			    :domain (unix:getenv 'HTTP_HOST) 	;".matsui.jpn.ph"
			    :expires (* 1 365 24 3600)
	)))
      (gen "~a" result-gif-string)
      (finish-output *cgi-out*)
      )
   )

(provide :web-counter)
   
