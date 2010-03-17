;;;; 
;;;; Produce HTML document describing BUS LOCATION DATABASE.
;;;;
;;;	January, 2003 (c) Toshihiro Matsui
;;;
;;;
  
(require :pgsql "pgsql")
(require :httpcgi)

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
   ;; (format *error-output* "minute-list=~s~%date=~s30minlist=~s~%" minute-list date 30min-list)
   (mapcar #'(lambda (display time)
	;; (format *error-output* "display=~s~%time=~s~%" display time)
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
     (gen "iso date: ~a~%" (send date :iso-date-string))
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

(defun generate-timing-table (from-time till-time)
  (let ((days (send (send till-time :subtract from-time) :day))
	 (timings) (minute-list))
     (dotimes (d days)
	(setq minute-list (mapcar #'first (30min-times (get-db-day-data from-time t))))
	(setq minute-list (add-detail-href
		minute-list from-time))
	(push (cons (send from-time :iso-date-string) minute-list)
	      timings)
	(setq from-time (send from-time :offset-day 1)) 	)
     (setq timings (transpose-list
			(append (list 30min-list)
				(nreverse timings))))
     (gen "~a~%"
	 (html-table timings :border 1)) )
     )

(defun generate-week-timing-table ()
   (let ((today) (weekago))
     (setq today (now))
     (setq weekago (send today :offset-day -7))
     (generate-timing-table weekago today)))


;;
;; 今日 昨日 一昨日 １週間前 ２週間前 一月前 月平均 年平均
;;

(defun generate-minutes-table ()
  (let (trip-today trip-yesterday trip-the-day-before
	trip-week-ago trip-two-weeks-ago trip-month-ago
	minutes-today minutes-yesterday minutes-the-day-before
	minutes-week-ago minutes-two-weeks-ago minutes-month-ago
	weather-list)
 
   (gen "<!-- counter --> <img src=/fcgi/euscounter.fcgi?id=bus&gif=gif2>~%")
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
		(input-form 'submit 'command 'traffic  80 "トラフィック" ))
	    (list
		"一週間の上り所要時間"
		(input-form 'submit 'command 'week-time  80 "week-time" ))
	)))
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

(defun monthrep-top ()
  (let ()
   (setq *charset* :euc)
   (setq now (instance calendar-time :now))
   ;;
   (setq *forms* (parse-http-query (get-cgi-query)))
   (setq *db-command* (xqval 'command *forms* 'debug))
   ;;
   (http-header :accept-ranges "bytes")
   (html-header :title "Tsukuba bus trip time"
		:charset :euc
		:stylesheet "http://matsui.jpn.ph/matsui.css"
		:keywords "EusLisp, 月例報告"
		)
   ;;
   ;; (gen "<br>command=~a<br>~%" *db-command*)

   (gen "<center><h1>月例報告</a></h1>" )
   (gen (send now :iso-string))
   ;;
   (case *db-command*
	(login (monthrep-login))
	(detail (generate-detail ))
	(traffic (generate-traffic-page now))
	((average)  (generate-minutes-table))
	(weather (generate-weather-page))
	(amedas (generate-weather-picture-page))
	(week-time (generate-week-timing-table ))
	(t  (generate-minutes-table))
	)
   (gen "</center> </body>")
   (finish-output *cgi-out*)
  ))


