;;; weather_clearer.l
;;; 2004/3/21 Toshihiro Matsui
;;; delete old records in the weather_picture table.
;;; Note that large objects representing gif and jpeg pictures are
;;; explicitely unlinked.
;;;
;;; (weather-cleaner "2003-10-15") deletes all records older than 2003-10-15.

(require :pgsql)

(defun weather-cleaner (date)	;; data older than date are removed
   (let ((db (instance pq:pgsql :init)) (records) (loids) (id))
      (setq records
	      (pq:select db 
		'(id amedas_temp_gif amedas_precip_gif amedas_wind_gif
		 amedas_sunshine_gif radar_gif
		 himawari_gmsball_jpg himawari_gmsasia_jpg  himawari_gmsvapor_jpg)
		'weather_pictures
		:where `(<= recdate ,date)))
     (dolist (rec records)
        (setq id (pop rec))	;the first field is id
        (dolist (loid rec)   (send db :lo-unlink loid))
        (pq:delete-record db 'weather_pictures :where `(= id ,id))
	)))


