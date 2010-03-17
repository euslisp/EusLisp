;;;; 
;;;; Produce HTML document describing BUS LOCATION DATABASE.
;;;;
;;;	January, 2003 (c) Toshihiro Matsui
;;;
;;;
  
(unless (unix:isatty 0)
   (defun euserror (code msg1 form &optional (msg2))
	  (format *error-output*
		"eus error ~s ~s ~s ~s~%" code msg1 form msg2)
	  (unix::exit 1))
   (setq *error-handler* 'euserror)
   )

(require :http "http")
(require :time "time")
(require :webnews "webnews")
(require :pgsql "pgsql")
(require :httpcgi)
(require :web-counter "web-counter")

(defvar *action* "/cgi-bin/bus.cgi")	;;override this for fast-cgi

(defparameter 30min-list
	'(	;; "06:00" "06:30"
		"07:00" "07:30" "08:00" "08:30" "09:00" "09:30"
		"10:00" "10:30" "11:00" "11:30" "12:00" "12:30"
		"13:00" "13:30" "14:00" "14:30" "15:00" "15:30"
		"16:00" "16:30" "17:00" "17:30" "18:00" "18:30"
		"19:00" "19:30" "20:00" "20:30" "21:00" "21:30"
		"22:00" "22:30" "23:00" "23:30")
	)

;; (defun select (db fields table &key where limit limit-offset order-by))
;;
;; extract data between time1 and time2
;;
(defun time-segmented-record (date hour min1 min2)
   (let (db-result)
      (setq db-result (select db
	'(recdate rectime up_minutes down_minutes)
	"tsukuba_bus"
	:where (format nil 
	  "recdate = date '~a' and rectime >= time '~a:~a'
		 and rectime < time '~a:~a'"
	  (send date :iso-date-string)
	  hour min1 hour min2))
	  )
      db-result))

(defun dated-record (date)
  (let (res)
     (dolist (hour '(7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23))
	(push (time-segmented-record date hour 0 30) res)
	(push (time-segmented-record date hour 30 59) res))
     (nreverse res)) )

;; recdate, rectime, weekday,
;; up_time_string, up_minutes,
;; down_time_string, down_minutes
;;
;; extract records between hour:min1 till hour:min2
;; from the given one-day records

(defun collect-timed-records (records hour min1 min2)
   (mapcan #'(lambda (r)
		(let ((h (send (second r) :hours))
			(m (send (second r) :minutes))) 
		   (if (and (= h hour) (>= m min1) (< m min2))
			(list r))))
	   records))

(defun min-to-hourmin-string (min)
   (cond ((not (numberp min)) "")
	 ((< min 60) (format nil "~a分" min))
	 ((not (integerp min)) "N/A")
	 (t (format nil "~d時間~d分" (/ min 60) (mod min 60)))) )

(defun average-time-records (records)
   (list
     (round (/ (float (apply #'+ (mapcar #'fifth records))) (length records)))
     (round (/ (float (apply #'+ (mapcar #'seventh records))) (length records)))))

#|
(defun 30min-times (records)
   (let (result)
      (dolist (hour '(7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23))
         (push  (mapcar #'min-to-hourmin-string (average-time-records
			(collect-timed-records records hour 0 30)))
		result)
         (push  (mapcar #'min-to-hourmin-string (average-time-records
			(collect-timed-records records hour 30 59)))
		result)
	 )
	(nreverse result)) )
|#

(defun 30min-times (records)
   (let (result)
      (dolist (hour '(7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23))
         (push  (average-time-records
			(collect-timed-records records hour 0 30))
		result)
         (push  (average-time-records
			(collect-timed-records records hour 30 59))
		result)
	 )
	(nreverse result)) )

(defun get-db-day-data (offset &optional (abs nil))
     (send db :exec (format nil 
		"select recdate, rectime, weekday,
			up_time_string, up_minutes,
			down_time_string, down_minutes
		 from tsukuba_bus
		 where recdate = date '~a'"
	  (if abs 
 	      (send offset :iso-date-string)
	      (send (send now :offset-day offset) :iso-date-string))))
     )

(defun generate-weather-page ()
   (let (weather-data
	 (year (xqval 'year *forms*))
	 (month (xqval 'month *forms*))
	 (day (xqval 'day *forms*))
	 date sdate)
     ;; (gen "~a<br>~%" *forms*)
     (setq date
	   (if month
	       (instance calendar-time :make :year year :month month :day day)
	       now))
     (setq sdate (send date :offset-day -7))	;; one week 
     (setq weather-data
	(pq:select db '(recdate rectime weather temp wet_probability)
		'weather_report
		:where
		 (format nil "recdate> date '~a' and recdate<= date '~a'"
		(send sdate :iso-date-string)
		(send date :iso-date-string))))
     (goback-button)
     (gen "~a~%"
	(html-table
	  (mapcar #'(lambda (x)
		(cons (send (car x) :iso-date-string)    (cdr x)))
		weather-data)
	  :border 1))
))	


(defun generate-raw-table ()
   (let (trip-data
	 (year (xqval 'year *forms*))
	 (month (xqval 'month *forms*))
	 (day (xqval 'day *forms*)))

     (gen "<h2>昨日、本日の生のデータ</h2>")
     ;; (gen "~a~%" *forms*)
     (gen-action *action* 'post)
     (gen "~a~%"
	(html-table (list
	   (list "本日、昨日の30分平均"
		(input-form 'submit 'command 'average 50 ))
	   (list "年" (input-form 'label 'year  (string (send now :year))  5))
	   (list "月" (input-form 'label 'month (string (send now :month))  5))
	   (list "日" (input-form 'label 'day  (string (send now :day))  5))
	   (list "生データ表示" (input-form 'submit 'command 'raw 50 )) 	
	   (list "週間天気表示" (input-form 'submit 'command 'weather 50 )) 	
	   )))
     (gen "</form>")

     (cond ((null day)
	     (setq trip-data (append (get-db-day-data -1) (get-db-day-data 0)))
	     (gen  (html-table 
		(mapcar #'(lambda (r) (list 
				(send (first r) :iso-date-string) 
				(format nil "~2a:~2a"
				    (digits-string (send (second r) :hours) 2)
				    (digits-string (send (second r) :minutes) 2))
				(fourth r) (fifth r) (sixth r) (seventh r))) 
			trip-data)
		:heading '(date time 上り 分 下り 分)
		:table-option "border=1"))      )
	(t (setq date (instance calendar-time :make
		:year (send now :year)
		:month month
		:day day))
	   (gen "date=~a~%" (send date :iso-date-string))
	   (setq trip-data (get-db-day-data date t))	;absolute date
	   (gen  (html-table 
		(append
		  (list (list "天気" "" (get-weather date)))
		  (mapcar #'(lambda (r) (list 
				(send (first r) :iso-date-string) 
				(format nil "~2a:~2a"
				    (digits-string (send (second r) :hours) 2)
				    (digits-string (send (second r) :minutes) 2))
				(fourth r) (fifth r) (sixth r) (seventh r))) 
			trip-data))
		:heading '(date time 上り 分 下り 分)
		:table-option "border=1"))      )
   )))

(defun add-detail-href (minute-list date)
   (mapcar #'(lambda (display time)
	(format nil
	    "<a href=~a?command=detail&date=~a&hour=~a&min=~a>~a</a>"
	    *action*
	    (send date :iso-date-string)
	    (subseq time 0 2) (subseq time 3 4)
	    display))
	minute-list
	30min-list
	)
      )

(defun get-weather (date)
   (let (r wether temp wet time
	 (date-string (send date :iso-date-string)))
      (setq r
         (send db :exec (format nil
	   "select recdate,weather,temp,wet_probability from weather_report
	   where recdate=date '~a' and rectime<time '11:30'
	   order by rectime desc"
	   date-string)))
      (setq r (first r))
      (if r		
	  (format nil
	 "<a href=~a?command=amedas&date=~a&hour=~a>~a<br>~a<br>~a<br></a>"
	*action*
	date-string 12
	(second r) (third r) (fourth r))
	  "No data" ))
      )
   
(defun generate-detail ()
  (let ((date (xqval 'date *forms*))
	(hour (xqval 'hour *forms*))
	(min (xqval 'min *forms*)))
     ;; (gen "date=~s, hour=~s, minutes=~s<br>~%" date hour min)
     (setq highway-info	
           (send db :exec (format nil
		"select rectime,traffic_status from traffic_status
		 where road='metro-route6' and 
			recdate = date '~a' and rectime>= time '~a:~a' and
			rectime<= time '~a:~a'"
		date (- hour 2) 0 hour 59 ))  )
     (if highway-info
	(gen "~a~%"
	     (html-table
		(mapcar #'(lambda (x) (list
				(send (car x) :iso-time-string)
			 	(second x)))
			highway-info)
		:border 1))
	(gen "<font size=+3 color=red>No data<br></font>~%") )
    (gen "<p>~%")
    (goback-button)
    )
  )

(defun generate-traffic-page (date)
   (let (tradata)
     (gen-action *action* 'post)
     ;; (defun input-form (type name &optional (value "") (size 60) (misc "")))
     (gen "~a~%"
	(html-table (list 
	    (list
		"10分おきの所要時間生データ"
		(input-form 'submit 'command 'raw  80 "生データ" ))
	    (list
		"30分ごとの到着所要時間"
		(input-form 'submit 'command 'average  80 "トラフィック" ))
	    (list
		"一週間の天気"
		(input-form 'submit 'command 'weather  80 "天気" ))
	    )))
     (gen "</form>")
     ;;
     (setq tradata (send db :exec (format nil
	"select rectime,road,traffic_status from traffic_status
		where recdate=date '~a' and road='metro-route6'
		order by rectime"
	(send date :iso-date-string)) ))
     (gen "<h3>首都高速6号</h3>")	
     (gen "~a~%" (html-table tradata :border 1))
     ;;
     (setq tradata (send db :exec (format nil
	"select rectime,road,traffic_status from traffic_status
		where recdate=date '~a' and road='metro-coast'
		order by rectime"
	(send date :iso-date-string)) ))
     (gen "<h3>首都高速湾岸線</h3>")
     (gen "~a~%" (html-table tradata :border 1))
     ;;
     (setq tradata (send db :exec (format nil
	"select rectime,road,traffic_status from traffic_status
		where recdate=date '~a' and road='joban-tokyo'
		order by rectime"
	(send date :iso-date-string)) ))
     (gen "<h3>常盤道東京部分</h3>")
     (gen "~a~%" (html-table tradata :border 1)) 
     ;;
     (setq tradata (send db :exec (format nil
	"select rectime,road,traffic_status from traffic_status
		where recdate=date '~a' and road='joban-ibaraki'
		order by rectime"
	(send date :iso-date-string)) ))
     (gen "<h3>常盤道茨城県部分</h3>")
     (gen "~a~%" (html-table tradata :border 1)) 
    ))

;;
;; 今日 昨日 一昨日 １週間前 ２週間前 一月前 月平均 年平均
;;

(defun generate-minutes-table ()
  (let (trip-today trip-yesterday trip-the-day-before
	trip-week-ago trip-two-weeks-ago trip-month-ago
	minutes-today minutes-yesterday minutes-the-day-before
	minutes-week-ago minutes-two-weeks-ago minutes-month-ago
	weather-list)
 
   ;; (gen "<!-- counter --> <img src=/cgi-bin/dream/dream.cgi?id=bus>~%")
   (count-up-display "bus")
   (gen "<p>")

    (gen "~a~%" (html-table (list
	(list	"<a href=/gallery/Bus/TsukubaBus-Megaliner.jpg>
		<img src=/gallery/Bus/TsukubaBus-Megaliner-small.jpg> </a>"
		"<a href=/gallery/Bus/TsukubaBus-boarding.jpg>
		<img src=/gallery/Bus/TsukubaBus-boarding-small.jpg> </a>")
	)
	:border 0))

     (gen-action *action* 'post)
     ;; (defun input-form (type name &optional (value "") (size 60) (misc "")))
     (gen "~a~%"
	(html-table (list 
	    (list
		"10分おきの所要時間生データ"
		(input-form 'submit 'command 'raw  80 "生データ" ))
	    (list
		"今日の関連交通情報"
		(input-form 'submit 'command 'traffic  80 "トラフィック" )))))
     (gen "</form>")
     ;;
     (setq trip-today (get-db-day-data 0))
     (setq trip-yesterday (get-db-day-data -1))
     (setq trip-the-day-before (get-db-day-data -2))
     (setq trip-week-ago (get-db-day-data -7))
     ;;
     ;;
     (setq minutes-today (30min-times trip-today))
     (setq minutes-yesterday (30min-times trip-yesterday))
     (setq minutes-the-day-before (30min-times trip-the-day-before))
     (setq minutes-week-ago (30min-times trip-week-ago))
 
     (setq weather-list
	(list	(get-weather now)
		(get-weather yesterday)
		(get-weather the-day-before)
		(get-weather week-ago)))

     (setq up-minutes
	(cons weather-list
	   (mapcar #'list
		(add-detail-href (mapcar #'first minutes-today) now)
		(add-detail-href (mapcar #'first minutes-yesterday) yesterday)
		(add-detail-href (mapcar #'first minutes-the-day-before)
			the-day-before)
		(add-detail-href (mapcar #'first minutes-week-ago)
			week-ago)
		))
	   )
     (setq down-minutes
	(mapcar #'list (mapcar #'second minutes-today)
			(mapcar #'second minutes-yesterday)
			(mapcar #'second minutes-the-day-before)
			(mapcar #'second minutes-week-ago)))
     ;;
     ;;
     (gen "<h2>上り (つくば→東京)</h2>
データ(数字)をクリックするとそのときの首都高６号線の交通情報がわかります.<br>単位：分<br>~%")
     (gen (html-table
		(mapcar #'cons
		    (append '("天気<br>気温<br>降水確率") 30min-list)
		     up-minutes)	
		:heading 
		   (list "到着時刻" 
			(format nil "~d日(~a)"
			   (send now :day)
			   (send now :weekday-string :jp))
			(format nil "~d日(~a)" 
			   (send yesterday :day)
			   (send yesterday :weekday-string :jp))
			(format nil "~d日(~a)" 
			   (send the-day-before :day)
			   (send the-day-before :weekday-string :jp))
                        (format nil "一週前 ~d日(~a)"
			   (send (send now :offset-day -7) :day)
			   (send (send now :offset-day -7) :weekday-string :jp))
			)
		:border 1
		:align 'center 
;;		:col '("align=\"center\"" "align=\"right\"" "align=right")
		))

     (gen "~%<hr>~%")
     (gen "<h2>下り (東京→つくば)</h2>~%")
     (gen (html-table
		(mapcar #'cons 30min-list down-minutes)	
		:heading
		   (list "到着時刻" 
			(format nil "~d日(~a)"
			   (send now :day) (send now :weekday-string :jp))
			(format nil "~d日(~a)" 
			   (send yesterday :day)
			   (send yesterday :weekday-string :jp))
			(format nil "~d日(~a)" 
			   (send the-day-before :day)
			   (send the-day-before :weekday-string :jp))
	                (format nil "一週前 ~d日(~a)"
			   (send (send now :offset-day -7) :day)
			   (send (send now :offset-day -7) :weekday-string :jp))
			)
		:border 1
		:align 'center 
		))
  ))
;;
;;

(defun generate-weather-picture-page ()
  (let ((date (xqval 'date *forms*))
	(hour (xqval 'hour *forms*)) 
	(loids)	;large object id's
	(loid-lists) 
	(base-name) (file-name)
	(fnames)
	(amedas-oid-lists))

     (setq loid-lists (send db :exec (format nil
	"select weather_gif, temp_gif, precip_gif, snow_gif
		from weather_report
		where recdate= date '~a' and
			rectime < '16:00'
		order by rectime desc"
	date ) ) )

     (setq loids (first loid-lists))	;; check non nil
     ;; (gen "~a<br>~%" loids)
     (goback-button)
     (dolist (name-oid (mapcar #'list
		'(weather temp precip snow)
		'("天気分布" "気温分布" "降水量分布" "積雪量分布")
		loids))
	(setq oid (third name-oid))
	(setq base-name
		(format nil "~a~d.gif" (first name-oid) oid))
	(if (null (probe-file
		      (setq file-name
			    (format nil "/home/www/html/bus/~a" base-name))))
	    (send db :lo-export oid file-name))
        (gen "~%<h3>~a</h3>~%<img src=~a><br><p></p>~%"
		(second name-oid)
		(format nil "/bus/~a" base-name)))
     ;;
     (setq amedas-oid-lists (send db :exec (format nil
	"select amedas_temp_gif, amedas_precip_gif, amedas_wind_gif,
		amedas_sunshine_gif, radar_gif,
		himawari_gmsball_jpg, himawari_gmsasia_jpg,
		himawari_gmsvapor_jpg from weather_pictures
		where recdate=date '~a'  and
		rectime< time '~d:00' and rectime > time '~d:00'
		order by rectime"
	date (+ hour 3) (- hour 3)) ) )
      ;;
      ) )


;; main (toplevel) programs are defined by
;; demo/buslocation-cgi.l and demo/buslocation-fcgi.l

(defun buslocation-top ()
  (let ()
   (setq *charset* :euc)
   (setq now (instance calendar-time :now))
   (setq yesterday (send now :offset-day -1))
   (setq the-day-before (send now :offset-day -2))
   (setq week-ago (send now :offset-day -7))
   ;;
   (setq *forms* (parse-http-query (get-cgi-query)))
   (setq *db-command* (xqval 'command *forms* 'debug))
   ;;
   (html-header :title "Tsukuba bus trip time"  :charset :euc)
   ;;
   ;; (gen "<br>command=~a<br>~%" *db-command*)

   (gen "<center><h1>
	<a href=/bus/tsukubago.html>高速つくば号 所要時間
<font size=2>使い方</font></a></h1>" )
   (gen (send now :iso-string))
   (case *db-command*
	(raw (generate-raw-table))
	(detail (generate-detail ))
	(traffic (generate-traffic-page now))
	((average)  (generate-minutes-table))
	(weather (generate-weather-page))
	(amedas (generate-weather-picture-page))
	(t  (generate-minutes-table))
	)
   (gen "</center> </body>")
   (finish-output *cgi-out*)
  ))


