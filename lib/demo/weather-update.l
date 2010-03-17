;;;; 
;;;; TOKYO-FM ミエルラジオ 天気情報
;;;;
;;;	January, 2003 (c) Toshihiro Matsui
;;;
;;;	＜東京＞（今日） 晴のち曇り [晴→曇]
;;;	＜東京＞（明日） 雨か雪
;;;	＜東京＞ 雨または雪の確率 午後 ０％ 今夜 １０％
;;;	＜東京＞の予想気温（今日） 最高 ８度
;;;
;;;	＜東京＞（今夜） 雨のち晴 [雨→晴]
;;;	＜東京＞（明日） はれ [晴]
;;;	＜東京＞ 雪または雨の確率 今夜 ５０％ 深夜 ０％
;;;	＜東京＞の予想気温（明日） 最低 ３度 最高 ９度  
;;;

(require :http "http")
(require :time "time")
(require :webnews "webnews")
(require :pgsql "pgsql")


;; 天気分布
(defparameter *jma-weather-gif-url*
	"http://www.jma.go.jp/JMA_HP/jp/mesh20/japan-cond-1.gif")
;;
;; 気温分布
(defparameter *jma-temp-gif-url*
	"http://www.jma.go.jp/JMA_HP/jp/mesh20/japan-temp-1.gif")
;;
;; 降水量分布
(defparameter *jma-precip-gif-url*
	"http://www.jma.go.jp/JMA_HP/jp/mesh20/japan-rain-1.gif")
;;
;; 降雪量
(defparameter *jma-snow-gif-url*
	"http://www.jma.go.jp/JMA_HP/jp/mesh20/japan-snow-1.gif")


;; SQL to create weather table;
;;

#| 
drop table weather_report;
drop sequence weather_report_id_seq;

create table weather_report (
	id serial,
	recdate date,
	rectime time,
	weekday int4,
	location text,
	weather text,
	temp    text,
	wet_probability text
	);
|#

(defun update-weather-report ()
  (let (now db
	tokyo-pattern temp-pattern wet-probability-pattern
	weather-html weather-body
	tokyo-weather tokyo-temp wet-probability
	gif weather-oid temp-oid precip-oid snow-oid
	)
	(setq tokyo-pattern "＜東京＞")
	(setq temp-pattern "＜東京＞の予想気温")
	(setq wet-probability-pattern "＜東京＞ 雪または雨の確率 ")
	;;
	;; (setq today-pattern "＜東京＞（今日）  ")
	;; (setq tonight-pattern "＜東京＞（今夜） ")
	;; (setq today-temp-pattern "＜東京＞の予想気温（今日）  ")
	;; (setq tomorrow-temp-pattern "＜東京＞の予想気温（明日） ")
	;
	(setq weather-html (read-http *tokyo-fm-weather-url*))
	(setq weather-body (cadr weather-html))
	;
	;; We expect the weather forecast appears earlier than temp and probability.
	(setq tokyo-weather
		(caaar (html-marked-items weather-body tokyo-pattern 'br '/body t)))
	(setq tokyo-temp
		(caaar (html-marked-items weather-body temp-pattern 'br '/body t)))
	(setq wet-probability
		(caaar (html-marked-items weather-body wet-probability-pattern 'br '/body t)))
	(if (null wet-probability) (setq wet-probability ""))
	;
	;;; We've got three kinds of info:
	;;;   tokyo-weather= today's weather in Tokyo
	;;;   tokyo-temp= today's or tomorrows temperature
	;;;   wet-probability= probability for snow or rain 
	;
	(setq now (instance calendar-time :now))
	(setq db (instance pq:pgsql :init :dbname "t.matsui"))
	;;
	;; read gifs from JMA (気象庁) and insert them into large objects
	(setq gif (read-http *jma-weather-gif-url*))
	(setq weather-oid (send db :lo-put (cadr gif)))
	(setq gif (read-http *jma-temp-gif-url*))
	(setq temp-oid (send db :lo-put (cadr gif)))
	(setq gif (read-http *jma-precip-gif-url*))
	(setq precip-oid (send db :lo-put (cadr gif)))
	(setq gif (read-http *jma-snow-gif-url*))
	(setq snow-oid (send db :lo-put (cadr gif)))
	;;
#|
	(format *error-output* "~a: ~a ~%" (send now :iso-string)
	 (format nil "insert into weather_report
		(recdate,  rectime, weekday,
		 location, weather, temp, wet_probability,
		 weather_gif, temp_gif, precip_gif, snow_gif)
		values ('~a', '~a', ~d, '~a', '~a', '~a', '~a', 
			~d, ~d, ~d, ~d)"
		(send now :iso-date-string)
		(send now :iso-time-string)
		(send now :weekday)
		"Tokyo"
		tokyo-weather tokyo-temp wet-probability
		weather-oid temp-oid precip-oid snow-oid)
	  ) |#
	;
	(send db :exec
	 (format nil "insert into weather_report
		(recdate,  rectime, weekday,
		 location, weather, temp, wet_probability,
		 weather_gif, temp_gif, precip_gif, snow_gif)
		values ('~a', '~a', ~d, '~a', '~a', '~a', '~a', 
			~d, ~d, ~d, ~d)"
		(send now :iso-date-string)
		(send now :iso-time-string)
		(send now :weekday)
		"Tokyo"
		tokyo-weather tokyo-temp wet-probability
		weather-oid temp-oid precip-oid snow-oid)
	  )
        )
	)



