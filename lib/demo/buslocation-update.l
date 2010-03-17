;;;; 
;;;; BUS LOCATION DATABASE
;;;;
;;;	January, 2003 (c) Toshihiro Matsui
;;;
;;;	reads Tsukuba-bus riding time from the bus-location web site,
;;;	and stores the data in a postgresql table.
;;;
  
(require :http "http")
(require :time "time")
(require :webnews "webnews")
(require :pgsql "pgsql")

;;
;; "約1時間27分" という文字列表現を87という整数にする。
;;
(defun minutes-from-japanese-timestring (time-string)
 (let ((match) (start) (end) (hour) (minute))
   (format *error-output* "time-string=~s~%" time-string)
   (setq match (regmatch hour-pattern time-string))
   (setq start (car match) end (second match))
   (setq hour (read-from-string
		 (subseq time-string (+ 2 start) (- end 4))))
   (setq match (regmatch minute-pattern time-string))
   (setq start (first match) end (second match))
   (setq minute (read-from-string
		(subseq time-string (+ 4 start) (- end 2))))
   (+ (* 60 hour) minute)
   ))

;;
;; SQL to create tsukuba_bus table;
;; Don't forget to grant read permission to public (nobody) for
;; web access.  Insert privilege is also needed for the user of the
;; update process invoked periodically (by root?)

#|
drop table tsukuba_bus;
drop sequence tsukuba_bus_id_seq;
create table tsukuba_bus (
	id serial,
	recdate date,
	rectime time,
	weekday int4,
	up_time_string text,
	up_minutes int4
	down_time_string text,
	down_minutes int4);
;; NOTICE:  CREATE TABLE will create implicit sequence 'tsukuba_bus_id_seq' for SERIAL column 'tsukuba_bus.id'
;; NOTICE:  CREATE TABLE / UNIQUE will create implicit index 'tsukuba_bus_id_key' for table 'tsukuba_bus'
|#


(defun update-bus-location ()
  (let (now db)
	(setq hour-pattern "約.*時間")
	(setq minute-pattern "時間.*分")

	(setq bus-location-html (read-http *ibaraki-bus-location-url*))
	(setq bus-location-body (cadr bus-location-html))

	(setq work (nthcdr 100 bus-location-body))

	;;(defun html-marked-items (html-list &optional (mark "■") (mark-end 'br)
	;;				(end '/table)) ... )

	(setq up (html-marked-items work "つくば線　上り" '/tr '/body))
	(setq down (html-marked-items work "つくば線　下り" '/tr '/body))

	(setq uptime-string (nth 2 (caar up)))
	(setq downtime-string (nth 2 (caar down)))

	(setq uptime (minutes-from-japanese-timestring uptime-string)
	      downtime (minutes-from-japanese-timestring downtime-string))

	;;;
	;;; insert into the buslocation table
	;;;
	;;
	;; prepare a dababase connection
	;;
	(setq now (instance calendar-time :now))
	(setq db (instance pq:pgsql :init :dbname "t.matsui"))
	;;
	#|
	(format *error-output* "insert into tsukuba_bus
		(recdate, rectime, weekday,
		 up_time_string, up_minutes,
		 down_time_string, down_minutes)
		values ('~a', '~a', ~d, '~a', ~d, '~a', ~d )"
		(send now :iso-date-string)
		(send now :iso-time-string)
		(send now :weekday)
		uptime-string uptime downtime-string downtime)
	|#
	(send db :exec
	 (format nil "insert into tsukuba_bus
		(recdate, rectime, weekday,
		 up_time_string, up_minutes,
		 down_time_string, down_minutes)
		values ('~a', '~a', ~d, '~a', ~d, '~a', ~d )"
		(send now :iso-date-string)
		(send now :iso-time-string)
		(send now :weekday)
		uptime-string uptime downtime-string downtime)
	  )
        )
	))



