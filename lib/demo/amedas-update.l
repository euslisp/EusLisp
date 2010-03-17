(require :http "http")
(require :time "time")
(require :webnews "webnews")
(require :pgsql "pgsql")

(setq now (now))
(setq now-string (send now :string :year :month :day :hour))

#|
(defparameter *imoc-precip-gif-url*
	 "http://www.imoc.co.jp/amds/am0_ej.gif")
(defparameter *imoc-wind-gif-url* 
	"http://www.imoc.co.jp/amds/am1_ej.gif")
(defparameter *imoc-temp-gif-url* 
	"http://www.imoc.co.jp/amds/am2_ej.gif")
(defparameter *imoc-sunshine-gif-url* 
	"http://www.imoc.co.jp/amds/am3_ej.gif")
|#


(defparameter *jma-amedas-precip-gif-url*  (format nil
	"http://www.jma.go.jp/JMA_HP/jp/amedas/japan/record/~a_Kousui.gif"
	now-string))
(defparameter *jma-amedas-wind-gif-url* (format nil
	"http://www.jma.go.jp/JMA_HP/jp/amedas/japan/record/~a_Kaze.gif"
	now-string))
(defparameter *jma-amedas-temp-gif-url* (format nil
	"http://www.jma.go.jp/JMA_HP/jp/amedas/japan/record/~a_Kion.gif"
	now-string))
(defparameter *jma-amedas-sunshine-gif-url* (format nil
	"http://www.jma.go.jp/JMA_HP/jp/amedas/japan/record/~a_Nissho.gif"
	now-string))

(defparameter *jma-radar-gif-url* (format nil	
	"http://www.jma.go.jp/JMA_HP/jp/radar/color/japan/record/radar-~a00.gif"
	now-string))

;; ひまわり全球赤外
(defparameter *jma-gmsball-jpg-url* (format nil
	"http://www.jma.go.jp/JMA_HP/jp/gms/ball/record/gmsball-~a.jpg"
	now-string)
;; ひまわり日本赤外
(defparameter *jma-gmsasia-jpg-url* (format nil
	"http://www.jma.go.jp/JMA_HP/jp/gms/asia/record/gmsasia-~a.jpg"
	now-string)
;; ひまわり日本水蒸気
(defparameter *jma-gmsvapor-jpg-url* (format nil
	"http://www.jma.go.jp/JMA_HP/jp/gms/vapor/record/gmsvapor-~a.jpg"
	now-string)

#| SQL code to define weather_pictures

drop table weather_pictures;
drop sequence weather_pictures_id_seq;

create table weather_pictures (
	id		serial,
	recdate		date,
	rectime		time,
	weekday		int4,
	location	text,

	amedas_temp_gif		oid,
	amedas_precip_gif	oid,
	amedas_wind_gif		oid,
	amedas_sunshine_gif	oid,

	radar_gif		oid,

	himawari_gmsball_jpg	oid,
	himawari_gmsasia_jpg	oid,
	himawari_gmsvapor_jpg	oid
	);
|#

(defun update-weather-pictures ()
  (let (db bin-picture oid
	amedas_temp_gif_oid
	amedas_precip_gif_oid
	amedas_wind_gif_oid
	amedas_sunshine_gif_oid
	radar_gif_oid
	himarari_gmsball_jpg_oid
	himawari_gmsasia_jpg_oid
	himawari_gmsvapor_jpg_oid)
	;;
	;
	(setq now (instance calendar-time :now))
	(setq db (instance pq:pgsql :init :dbname "t.matsui"))
	;;
	(setq amedas_temp_gif_oid (send db :lo-put
		(second (read-http *jma-amedas-temp-gif-url*))))
	(setq amedas_precip_gif_oid (send db :lo-put
		(second (read-http *jma-amedas-precip-gif-url*))))
	(setq amedas_wind_gif_oid (send db :lo-put
		(second (read-http *jma-amedas-wind-gif-url*))))
	(setq amedas_sunshine_gif_oid (send db :lo-put
		(second (read-http *jma-amedas-sunshine-gif-url*))))
	(setq radar_gif_oid (send db :lo-put
		(second (read-http *jma-radar-gif-url*))))
	(setq himarari_gmsball_jpg_oid (send db :lo-put
		(second (read-http *jma-gmsball-jpg-url*))))
	(setq himarari_gmsasia_jpg_oid (send db :lo-put
		(second (read-http *jma-gmsasia-jpg-url*))))
	(setq himarari_gmsvapor_jpg_oid (send db :lo-put
		(second (read-http *jma-gmsvapor-jpg-url*))))
	;;
	(format *error-output* "~a: ~a ~%" (send now :iso-string)
	 (format nil "insert into weather_pictures
		(recdate,  rectime, weekday, location,
		 amedas_temp_gif, amedas_precip_gif, amedas_wind_gif, 
		amedas_sunshine_gif, radar_gif,
		himawari_gmsball_jpg, himawari_gmsasia_jpg,
		himawari_gmsvapor_jpg)
		values ('~a', '~a', ~d, '~a', 
		~d, ~d, ~d, ~d, ~d, ~d, ~d, ~d)"
		(send now :iso-date-string)
		(send now :iso-time-string)
		(send now :weekday)
		"Japan"
		amedas_temp_gif_oid
		amedas_precip_gif_oid
		amedas_wind_gif_oid 
		amedas_sunshine_gif_oid
		radar_gif_oid
		himarari_gmsball_jpg_oid
		himarari_gmsasia_jpg_oid
		himarari_gmsvapor_jpg_oid )	  )
	;
	(send db :exec
	 (format nil "insert into weather_pictures
		(recdate,  rectime, weekday, location,
		 amedas_temp_gif, amedas_precip_gif, amedas_wind_gif, 
		amedas_sunshine_gif, radar_gif,
		himawari_gmsball_jpg, himawari_gmsasia_jpg,
		himawari_gmsvapor_jpg)
		values ('~a', '~a', ~d, '~a', 
		~d, ~d, ~d, ~d, ~d, ~d, ~d, ~d)"
		(send now :iso-date-string)
		(send now :iso-time-string)
		(send now :weekday)
		"Japan"
		amedas_temp_gif_oid
		amedas_precip_gif_oid
		amedas_wind_gif_oid 
		amedas_sunshine_gif_oid
		radar_gif_oid
		himarari_gmsball_jpg_oid
		himarari_gmsasia_jpg_oid
		himarari_gmsvapor_jpg_oid )	  )
        )
   )



