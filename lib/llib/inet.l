(defconstant ipaddr-readtable (copy-readtable))
(set-syntax-from-char #\. #\space ipaddr-readtable)
(set-syntax-from-char #\[ #\( ipaddr-readtable)
(set-syntax-from-char #\] #\) ipaddr-readtable)
(set-macro-character #\[ (get-macro-character #\() nil ipaddr-readtable)
(set-macro-character #\] (get-macro-character #\)) nil ipaddr-readtable)
(set-syntax-from-char #\: #\space ipaddr-readtable)
(set-syntax-from-char #\/ #\space ipaddr-readtable)


(defun read-ip-address (&optional (strm t))
   (let ((*readtable* ipaddr-readtable)  (result)
	 b1 b2 b3 b4 delim)
      (setq b1 (read strm))
      (setq delim (read-char strm))
      (if (/= delim #\.) (error "not an ip-address" delim))
      (setq b2 (read strm))
      (setq delim (read-char strm))
      (if (/= delim #\.) (error "not an ip-address" delim))
      (setq b3 (read strm))
      (setq delim (read-char strm))
      (if (/= delim #\.) (error "not an ip-address" delim))
      (setq b4 (read strm))
      ;;
      (setq result (list b1 b2 b3 b4))
      (if (every #'(lambda (x) (and (integerp x) (<= 0 x 255))) result)
	  result
	  (error "non integer in ip-addr"))
      ))

#|
log format
 %h -- remote host
 %l -- remote log
 %u -- auth user name
 %t -- time in CLF format [15/Dec/2003:13:13:23 +0900] 
 %r -- the first line of a request
 %s -- the last status
 %b -- byte count except the header
|#

(defun read-clf-time (strm)
   (let ((*readtable* ipaddr-readtable) (timedesc)
	 day month year hour minute second tzone)
      (setq timedesc (read strm))
      timedesc))
;; [15/Dec/2003:13:13:23 +0900] 

(defun read-httpd-log (&optional (logfile "/usr/local/apache2/logs/access_log"))
   (with-open-file (log logfile)   
      (with-input-from-string (line (read-line log))
	 (let ((rhost) (rlog) (user) (time) (request) (stat) (bytes))
	    (setq rhost (read-ip-address line))
	    (setq rlog  (read line))
	    (setq user (read line))
	    (setq time (read-clf-time line))
	    (setq request (read line))  ; double quoted string
	    (setq stat (read line))
	    (setq bytes (read line))
	    (list rhost request bytes)))))

