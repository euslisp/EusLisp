;;;; traffic-update.l
;;;; obtains traffic status infomation of the metropolitan-highway
;;;; and stores the html document in a postgresql table.

(require :http "http")
(require :time "time")
(require :webnews "webnews")
(require :pgsql "pgsql")

(defparameter *jartic-metro-highway-url*
	(url-pathname
	   "http://www.jartic.or.jp/traffic/highway/kousoku/rhm0001.html"))
(defparameter *jartic-ibaraki-highway-url*
	(url-pathname
	   "http://www.jartic.or.jp/traffic/highway/kousoku/rhm0005.html"))
(defparameter *jartic-tokyo-highway-url*
	(url-pathname
	   "http://www.jartic.or.jp/traffic/highway/kousoku/rhm0006.html"))

;; SQL to create weather table;
;;

#| 
drop table traffic_status;
drop sequence traffic_status_id_seq;

create table traffic_status (
	id serial,
	recdate date,
	rectime time,
	weekday int4,
	road symbol,
	traffic_status text
	);
|#

(defun update-traffic-status ()
  (let (now db split-html
	route6-pattern route-coast-pattern
	)
	(setq route6-pattern "６号")
	(setq route-coast-pattern "高速湾岸線")
	(setq route-joban-pattern "常磐道")
	(setq regulation-pattern "●主な規制情報")
	(setq triptime-pattern "●主な旅行時間")
	(setq closed-entry-pattern "●入口閉鎖")
	;
	;;
	;
	(setq metro-highway-body (cadr 
		(read-http *jartic-metro-highway-url*)))
	(setq ibaraki-highway-body (cadr
		(read-http *jartic-ibaraki-highway-url*)))
	(setq tokyo-highway-body (cadr
		(read-http *jartic-tokyo-highway-url*)))
	;;
	;; highway status information is composed of regulation, trip-time
	;; and closed-entry, in this order. 
	;;
	(setq metro-regulation-body (caar
		(html-marked-items metro-highway-body
			regulation-pattern '/table '/body)))
	(setq metro-triptime-body (caar
		(html-marked-items metro-highway-body
			triptime-pattern '/table '/body)))
	(setq metro-closed-entry-body (caar
		(html-marked-items metro-highway-body
			closed-entry-pattern '/table '/body)))
	;;
	(setq tokyo-regulation-body (car
		(html-marked-items tokyo-highway-body
			regulation-pattern '/table '/body)))
	(setq tokyo-triptime-body (car
		(html-marked-items tokyo-highway-body
			triptime-pattern '/table '/body)))
	;;
	(setq ibaraki-regulation-body (caar
		(html-marked-items ibaraki-highway-body
			regulation-pattern '/table '/body)))
	(setq ibaraki-triptime-body (car
		(html-marked-items ibaraki-highway-body
			triptime-pattern '/table '/body)))
	;;
	;; 首都高速６号線(向島,三郷) 
	;;
        (setq route6-regulation-info
		(concatenate-strings (car 
			(html-marked-items metro-regulation-body
				route6-pattern '/tr '/body t))))
	(setq route6-triptime-info
		(concatenate-strings (car 
			(html-marked-items metro-triptime-body
				route6-pattern '/tr '/body t))))
	(setq route6-closed-entry-info
		(concatenate-strings (car 
			(html-marked-items metro-closed-entry-body
				route6-pattern '/tr '/body t))))
	;;
	;; 首都高速湾岸線
	(setq coast-regulation-info
		(concatenate-strings (car 
			(html-marked-items metro-regulation-body
				route-coast-pattern '/tr '/body t))))
	(setq coast-triptime-info
		(concatenate-strings (car 
			(html-marked-items metro-triptime-body
				route-coast-pattern '/tr '/body t))))
	(setq coast-closed-entry-info
		(concatenate-strings (car 
			(html-marked-items metro-closed-entry-body
				route-coast-pattern '/tr '/body t))))
	;; 高速常盤道,茨城部
	(setq ibaraki-regulation-info
		(concatenate-strings (car 
			(html-marked-items ibaraki-regulation-body
				route-joban-pattern '/tr '/body t))))
	(setq ibaraki-triptime-info
		(concatenate-strings (car 
			(html-marked-items ibaraki-triptime-body
				route-joban-pattern '/tr '/body t))))
	;; 高速常盤道,東京部
	(setq tokyo-regulation-info
		(concatenate-strings (car 
			(html-marked-items tokyo-regulation-body
				route-joban-pattern '/tr '/body t))))
	(setq tokyo-triptime-info
		(concatenate-strings (car 
			(html-marked-items tokyo-triptime-body
				route-joban-pattern '/tr '/body t))))

	;;
	;; Insert the info into the database table
	;;
	(setq now (instance calendar-time :now))
	(setq db (instance pq:pgsql :init :dbname "t.matsui"))
	;;
	;; 首都高速６号ミサとせん
	(dolist (info route6-regulation-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'metro-route6
			'regulation
			info)) )
	(dolist (info route6-triptime-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'metro-route6
			'triptime
			info)) )
	(dolist (info route6-closed-entry-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'metro-route6
			'closed-entry
			info)) )
	;;;;; 湾岸線
	;;
	(dolist (info coast-regulation-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'metro-coast
			'regulation
			info)) )
	(dolist (info coast-triptime-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'metro-coast
			'triptime
			info)) )
	(dolist (info coast-closed-entry-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'metro-coast
			'closed-entry
			info)) )
	;;;;; JOUBANN IBARAKI
	;;
	(dolist (info IBARAKI-regulation-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'joban-ibaraki
			'regulation
			info)) )
	(dolist (info IBARAKI-triptime-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'joban-ibaraki
			'triptime
			info)) )
	;;;;; JOUBANN TOKYO
	;;
	(dolist (info tokyo-regulation-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'joban-tokyo
			'regulation
			info)) )
	(dolist (info tokyo-triptime-info)
	    (pq:insert-record2 db 'traffic_status
		'(recdate rectime weekday road infotype traffic_status)
		(list (send now :iso-date-string)
			(send now :iso-time-string)
			(send now :weekday)
			'joban-tokyo
			'triptime
			info))	)
	))

























