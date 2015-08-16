;; time.l
;;    sec min hour day month year week
;;     0   1     2  3    4      5   6     7 8
;; #i(45  23    10  1    5     98   1     0 0)

;; note that there are four representations of time and date.
;; 1. abs-time  (number of seconds since Jan 1, 1970 UST)
;; 2. calendar-time #i(sec min hour day month year week)
;; 3. obj-time object of (micro sec min hour day month year week day-of-year)
;; 4. string-time "Wed, 25 Dec 1998 10:59:33 +0900"
;; We use the third obj-time mostly. Other formats can be obtained from the object.
;; 
;; The time class is intended to represent date and time for daily life,
;; and not for physics or archeology.  For example the time span is
;; never meant to represent longer than 4 years.

;; This modules should be read in the Lisp-package.

(IN-PACKAGE :LISP)

(export '(leap-year-p
		secs-since-1970
		seconds
		sec-to-date
		make-time
		now
		parse-time-string
		read-ISO-date read-ISO-time read-ISO-datetime
		parse-ISO-time-string
		*time-readtable*
		interval-time
		calendar-time
		*month-names*
		))

(defparameter TZ (read-from-string (car (elt (unix:localtime) 9))))

(defconstant *day-seconds* (* 24 3600))
(defparameter *month-days*  #(31 28 31 30 31 30 31 31 30 31 30 31))
(defparameter *month-names*
        '((Jan 0) (feb 1) (mar 2) (apr 3) (may 4) (jun 5)
          (jul 6) (aug 7) (sep 8) (oct 9) (nov 10) (dec 11)
          (January 0) (February 1) (March 2) (April 3) (June 5)
          (July 6) (August 7) (September 8) (October 9)
          (November 10) (December 11)) )

(defparameter *weekday-names*
      '((Sun 0) (Sunday 0) (Mon 1) (Monday 1) (Tue 2) (Tuesday 2)
        (Wed 3) (Wednesday 3) (Thr 4) (Thursday 4) (Thur 4) (thu 4)
        (Fri 5) (Friday 5) (Sat 6) (Saturday 6)))

(defun year-day (month day &optional (year (aref (unix:localtime) 5)))
   ;; returns the number of days since January 1st of this year.
   ;; January 1st is zero.
   ;; January 30th is twenty-nine.
   (let ((days 0))
     (setf (aref *month-days* 1)
           (if (= (mod year 4) 0) 29 28))
     (while (> month 0)
        (decf month)
        (incf days (aref *month-days* month)))
     (+ days (1- day))))



(defun leap-year-p (year)
   (declare (integer year))
   (or 
       (and (= (mod year 4) 0)
	    (/= (mod year 100) 0))
       (= (mod year 400) 0)))
     

(defun secs-since-1970 (&key year month day
                         (hour 0) (minute 0) (second 0))
   ;; year=0..99  month=0..11  day=1..31
   (if (> year 1900) (setq year (- year 1900)))
   (let ((years) (leaps) (days 0))
     (setq years (- year 70))
     (setq leaps (/ (+ years 1) 4))
     (setq days (year-day month day))
     (+ second
        (* 60 (+ minute
                 (* 60 (+ hour (* 24 (+ (* years 365) leaps days)))))))
     )
   )


(defun month-index (mname)
   ;; convert month names (January, February ...) to 0, 1, 2...
   (cond ((symbolp mname)
          (cadr (assoc mname *month-names*)))
         ((stringp mname)
          (cadr (assoc mname *month-names*
                        :test #'string-equal)))
         ((integerp mname)
          ;(if (or (<= mname 0) (> mname 12))
          ;    (error "month name <0 or >=12")
          ;    (1- mname))
	   (1- mname))
         (t (error "month name"))
         ))


(defun weekday-index (wdname)
   ;; convert weekday names (Monday, Sun ...) to 0, 1, 2...
   (cond ((symbolp wdname)
          (cadr (assoc wdname *weekday-names*)))
         ((stringp wdname)
          (cadr (assoc wdname *weekday-names*
                        :test #'string-equal)))
         ((integerp wdname)
          (if (or (< wdname 0) (> wdname 11))
              (error "weekday name <0 or >=7")
              wdname))
         (t (error "weekday name"))
         ))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass interval-time :super propertied-object
	:slots (total-seconds 
		seconds	micros	
		days
		(hours :type :integer)
		(minutes :type :integer) ))

;; :init takes "seconds" as the argument,
;; whereas :make takes "month", "day", "hour" ... etc.

(defmethod interval-time
 (:init (secs) (send self :make :second secs))
 (:make (&key (year 0) (month 0) (day 0) (hour 0) (minute 0)
		(second 0) (micro 0))
     (setq micros micro)
     (setq total-seconds
	   (+ second (* 60 (+ minute
		(* 60 (+ hour (* 24 (+ day
			 (* 30 (+ month (* 12 year)))))))))))
     (setq minutes (/ total-seconds 60)
	   seconds (- total-seconds (* minutes  60))
	   hours (/ minutes 60)
	   minutes (- minutes (* hours 60))
	   days (/ hours 60)
	   hours (mod hours 60) )
     self)
 (:string ()
    (concatenate string
	(if (minusp total-seconds) "-")
	(if (zerop days)
	    ""
	    (format nil "~a days " days))
	(format nil "~a:~a:~a"
		(digits-string (abs hours) 2)
		(digits-string (abs minutes) 2)
		(digits-string (abs seconds) 2))
	(if (zerop micros) ""
	    (format nil ".~a"
                 (abs (/ micros 1000))))
    ) )
 (:prin1 (strm &rest mesg)
    ;; bug--negative time is not properly printed
    (send-super* :prin1 strm (send self :string)  mesg))
 (:micro () micros)
 (:total-seconds () total-seconds)
 (:seconds () seconds)
 (:total-minutes () (/ total-seconds 60.0))
 (:minutes () minutes)
 (:total-hours () (/ total-seconds 3600.0))
 (:hours () hours)
 (:days ()    days)
 (:total-days () (/ total-seconds 60.0 60.0 24.0))
 (:add (tint)
  (let ((raw-micros (+ micros (send tint :micro))))
    (instance (class self) :init
     (+ total-seconds (send tint :total-seconds) (/ raw-micros 1000000))
     (mod raw-micros 1000000))))
 (:subtract (tint)
  (let ((raw-micros (- micros (send tint :micro)))
        (raw-total-seconds (- total-seconds (send tint :total-seconds))))
    (when (minusp raw-micros)
      (dec raw-total-seconds (1+ (/ raw-micros -1000000)))
      (setq raw-micros (+ 1000000 (mod raw-micros 1000000))))
    (instance (class self) :init
     raw-total-seconds raw-micros)))
 )
  
(defmethod interval-time
 (:ISO-time-string ()
     (format nil "~a:~a:~a"
	(digits-string hours 2) (digits-string minutes 2)
	(digits-string seconds 2)))
 (:ISO-string () (send self :iso-time-string))
 )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; datestyle= ISO	"2000-03-01 10:30:00+09"
;; datestyle= SQL	"03/01/2000 10:30:00.00 JST"
;; datestyle= Postgres	"Wed Mar 01 10:30:00 2000 JST"
;; datestyle= European	"Wed 01 Mar 10:30:00 2000 JST"
;; datestyle= NonEuropean	"Wed Mar 01 10:30:00 2000 JST"
;; datestyle= German	"01.03.2000 10:30:00.00 JST"
;; datestyle= US	"01.03.2000 10:30:00.00 JST" ???
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(defvar *time-readtable* (copy-readtable))
(proclaim '(special *time-readtable*))
(set-syntax-from-char #\: #\space *time-readtable*)
(set-syntax-from-char #\, #\space *time-readtable*)
(set-syntax-from-char #\- #\space *time-readtable*)
(set-syntax-from-char #\+ #\space *time-readtable*)

(defun parse-time-string (time-string)
   ;; "Mon Dec 28 11:43:17 1998"	ANSI C asctime()
   ;; "Sat, 03 Jun 2000 00:26:15 GMT"  (RFC 822, RFC 1123)
   (let ((r) (time-stream (make-string-input-stream time-string))
	 (year) (month) (week) (day) (hour) (minute) (second) (tzone)
	 (*readtable* *time-readtable*))
	(setq week (weekday-index (read time-stream)))
	(setq month (read time-stream))
	(cond ((integerp month)	;; RFC 1123
		(setf day month)
		(setf month (month-index (read time-stream)))
		(setf year (read time-stream))
		(setq hour (read time-stream))
		(setq minute (read time-stream))
		(setq second (read time-stream))
		(setq tzone (read time-stream)))
	      (t 	;ANSI C format		
		(setq month (month-index month))
		(setq day (read time-stream))
		(setq hour (read time-stream))
		(setq minute (read time-stream))
		(setq second (read time-stream))
		(setq tzone (read time-stream))
		(if (numberp tzone)
		    (setq year tzone tzone 'JST)
		    (setq year (read time-stream)))
		;; (if (> year 1900) (setq year (- year 1900)))
		))
        (setq r 
	      (vector second minute hour day month year week Tzone ))
        ))


(defun read-ISO-date (datestr)
   (let ((*readtable* *time-readtable*)
	 (year) (month) (day))
      (if (stringp datestr)
	  (setq datestr (make-string-input-stream datestr)))
      (setq year (read datestr nil 0)
      	    month (read datestr nil 1)
	    day (read datestr nil 0))
      (instance calendar-time :make :year year :month  month :day day))
    )

(defun read-ISO-time (timestr)
   (let ((*readtable* *time-readtable*)
	 (hour) (minute) (sec))
     (if (stringp timestr)
	 (setq timestr (make-string-input-stream timestr))) 
     (setq hour (read timestr nil 0)
      	   minute (read timestr nil 0)
	   sec (read timestr nil 0))
     (instance interval-time :make :hour hour :minute minute :second sec))
   )


(defun read-ISO-datetime (datetimestr)
     (if (stringp datetimestr)
	 (setq datetimestr (make-string-input-stream datetimestr))) 
     (let ((date (read-ISO-date datetimestr))
	   (time (read-ISO-time datetimestr)))
	(if (and date time)
	    (send  date :add time)
	    (or date time))))


(defun parse-ISO-time-string (datetimestr)
   (if (stringp datetimestr)
	(setq datetimestr (make-string-input-stream datetimestr))) 
   (let ((r)  (year) (month) (week) (day) (hour) (minute) (second) (tzone)
	 (*readtable* *time-readtable*))
	(setq year (read datetimestr))
	(setq month (month-index (read datetimestr)))
	(setq day (read datetimestr))
	(setq hour (read datetimestr))
	(setq minute (read datetimestr))
	(setq second (read datetimestr))
	(setq tzone (read datetimestr))
        (setq r 
	      (vector second minute hour day month year week tzone ))
	))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass calendar-time :super interval-time
	:slots (weekday months years 
		timezone dst ))

(defun now () (instance calendar-time :now))

(defmethod calendar-time
 (:init (&optional (secs 0) (micro 0) (tzone 0) (daylight 0))
   ;; secs is seconds from 1970.1.1
   ;; Dec, 2003: negative day is generated at the end of a year.
   ;; Dec 28, 2003 was displayed as Jan -3, 2004 !
   ;; use of (unix::gmtime (gettimeofday)) is suggested.
   ;; correction by tzone is needed.
   ;; (declare (integer secs micro) )
   (setq timezone tzone
	 dst daylight)
   (decf secs timezone)
   (let ((leaps 0))
      (declare (integer leaps))
      (setq micros	micro
	    total-seconds secs
	    seconds 	secs 	;(+ (float secs) (* 0.000001 micros))
	    days    	(/ secs *day-seconds*)
	    seconds 	(- secs (* days *day-seconds*))
	    hours	(/ seconds 3600)
	    weekday	(mod (+ days 4) 7)
	    leaps	(/ days (+ 365 365 365 366)) 
	    years	(*  4 leaps)
	    months 	0)
;;       (print (list years months days hours))
       (setq  days (- days (* leaps (+ 365 365 365 366))) )
       (when (>= days 365)  (decf days 365) (incf years))
       (when (>= days 365)  (decf days 365) (incf years))
       (when (>= days 366)  (decf days 366) (incf years))
       (setq seconds (- seconds (* hours 3600))
	     minutes (/ seconds 60)
	     seconds (- seconds (* minutes 60))) 
       (setq years (+ years 1970))
;;       (print (list years months days hours))
       (setf (aref *month-days* 1)
	     (if (leap-year-p years) 29 28))
       (incf days)	;; day begins from one
       (while (> days (aref *month-days* months))
	  (decf days (aref *month-days* months))
	  (incf months))
       )
     ;; (integer-vector secs mins hours days month year weekday 0 0)
     self)
 (:make (&key (year 0) (month 0) (day 0) (hour 0) (minute 0)
		(second 0) (micro 0)) 
    (setf years 	year
          months 	(month-index month)
          days   	day
          hours  	hour
          minutes  	minute
          seconds 	second
          micros 	micro)
    (setq total-seconds (send self :compute-seconds))
    (if weekday
        (setf  (calendar-time-weekday self) (weekday-index weekday))
        (let* ((secs (secs-since-1970 :year year :month month :day day
                        :hour hour :minute minute :second second))
               (wd (mod (+ 4 (/ secs *day-seconds*)) 7)))
           (setf (calendar-time-weekday self)  wd))
        )
    self)
 (:make-localtime (ltime)
    (send self :make :second (aref ltime 0)
		:minute (aref ltime 1)
		:hour (aref ltime 2)
		:day (aref ltime 3)
		:month (1+ (aref ltime 4))
		:year (+ 1900 (aref ltime 5))))
 (:now (&optional (secs (unix:gettimeofday)))
   ;; secs = (sec usec timezone daylight)
   (send self :init (car secs) (second secs) (third secs) (fourth secs))
   self)
 (:noon ()
    (instance calendar-time :make :year years :month (1+ months) :day days :hour 12))
 (:midnight ()
    (instance calendar-time :make :year years :month (1+ months) :day days :hour 0))
 (:today ()  (send self :midnight))
 (:offset-day (offset)
    ;; tomorrow = (send (now) :offset-day 1)
    (send (send self :today) :add (instance interval-time :make :day offset)))
 (:offset-hour (offset)
    ;; tomorrow = (send (now) :offset-day 1)
    (send (send self :today) :add (instance interval-time :make :hour offset)))
 (:year-day () (year-day months days))
 (:compute-seconds ()
   (let ((leaps) (days 0))
     (setq leaps (/ (+ (- years 1970) 1) 4))
     (setq days (send self :year-day))
     (+ seconds
        (* 60 (+ minutes
                 (* 60 (+ hours (* 24 (+ (* (- years 1970) 365) leaps days)))))))
     )
   )
 (:asctime ()
    (if (> years 1900)
	(let ((asc 
		   (unix:asctime
			(vector seconds minutes hours days months (- years 1900) weekday))))
	   (subseq asc 0 (1- (length asc))))
	(send-super :string))     )
 (:string (&rest elements)
      "combination of :year, :month, :day, :hour, :minute, and :second"  
      ;; Wdy, DD-Mon-YYYY HH:MM:SS GMT
    (cond 
	((null elements)  (send self :iso-string)) 
	((member :full elements)
	    (format nil "~a, ~a GMT"
		(send self :weekday-string)
		(send self :iso-string)))
	(elements
	      (format nil "~a~a~a~a~a~a"
		  (if (member :year elements) (digits-string years 4) "")
		  (if (member :month elements) (digits-string (1+ months) 2) "")
		  (if (member :day elements) (digits-string days 2) "")
		  (if (member :hour elements) (digits-string hours 2) "")
		  (if (member :minute elements) (digits-string minutes 2) "")
		  (if (member :second elements) (digits-string seconds 2) "")))
	))
 (:parse-string (s)
    (let ((r (parse-time-string s)))
	(setq micros 0
	      seconds (aref r 0)
	      minutes (aref r 1)
	      hours (aref r 2)
	      days (aref r 3)
	      months (aref r 4)
	      years (aref r 5)
	      weekday (aref r 6)
	      ))
     (setq total-seconds (send self :compute-seconds))
     self)
 (:ISO-string ()
     (format nil "~d-~a-~a ~a:~a:~a"
        years (digits-string (1+ months) 2) (digits-string days 2)
	(digits-string hours 2) (digits-string minutes 2)
	(digits-string seconds 2)))
 (:ISO-date-string ()
     (format nil "~d-~a-~a"
        years (digits-string (1+ months) 2) (digits-string days 2) ))
 (:ISO-time-string ()
     (format nil "~a:~a:~a"
	(digits-string hours 2) (digits-string minutes 2)
	(digits-string seconds 2)))
 (:weekday-string (&optional (lang :english) (long nil))
    (let (weekday-name)
       (setq weekday-name (nth weekday
		'(( "Sunday" "Sun" "日曜" "日") ("Monday" "Mon" "月曜" "月")
		  ("Tuesday" "Tue" "火曜" "火") ("Wednesday" "Wed" "水曜" "水")
		  ("Thursday" "Thu" "木曜" "木") ("Friday" "Fri" "金曜" "金")
		  ("Saturday" "Sat" "土曜" "土")) ))
       (case lang
	 ((japanese :japanese :jp jp)
	  (if long (third weekday-name) (fourth weekday-name)))
	 (t ; (english :english)
	  (if long (first weekday-name) (second weekday-name))) )
       ))
 (:parse-ISO-string (s)
    (let ((r (parse-ISO-time-string s)))
	(setq micros 0
	      seconds (aref r 0)
	      minutes (aref r 1)
	      hours (aref r 2)
	      days (aref r 3)
	      months  (aref r 4)
	      years (aref r 5)
	      ;; weekday (aref r 6)
	      timezone (* 3600 (aref r 7))
	      ))
     (setq total-seconds (send self :compute-seconds))
     self)
 )

(defmethod calendar-time
 (:micro () micros)
 (:second () seconds)
 (:minute () minutes)
 (:hour () hours)
 (:day () days)
 (:weekday () weekday)
 (:month () (1+ months))
 (:year () years)
 (:day-seconds () (+ seconds (* 60 (+ minutes (* 60 hours)))))
  )


;----------------------------------------------------------------

(provide :time "@(#)$Id$")

