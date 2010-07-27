;;;; fastcgi.l
;;;  fast-CGI library
;;;  Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;
;;; libfcgi.so is linked and several I/O routines are introduced.
;;; libfcgi.so provides functions to communicate with an apache web server
;;; by a socket channel.   fcgi-devkit-2.1/include/fcgi_stdio.h defines 
;;; stdio macros to redirect references to normal stdin, stdout and stderr
;;; to references to the socket channel.  Note that a simple protocol is
;;; employed in the socket communication to interleave three communication
;;; channels, i.e. stdin, stdout, and stderr in one socket stream.
;;; In order to provide the similar functionality in EusLisp, *standard-input*,
;;; *standard-output*, and *standard-error* streams are redefined with
;;; the fcgi-stream class which uses the libfcgi functions for the low-level
;;; read and write.

(require :httpcgi )

(eval-when (load eval)
 (setq *euslog-file* (format nil "/tmp/eus~d.log" (unix:getpid)))
 (unless (unix:isatty 0)
   (unix:unlink *euslog-file*)
   (setq *euslog* (open *euslog-file* :direction :output))
   (format *euslog* ";; euslisp fcgi started ~s~%"
	(unix:asctime (unix:localtime)))
   )
  )

(defvar *fcgi-stdin*)
(defvar *fcgi-stdout*)
(defvar *fcgi-errout*)

(let ((m (load-foreign "/usr/local/lib/libfcgi.so"))
      (fcgi_sF)   )
   (setq *fcgi-module* m)
   (defforeign fcgi-accept m "FCGI_Accept" () :integer)
   (defforeign fcgi-finish m "FCGI_Finish" () :integer)
   (defforeign fcgi-putchar m "FCGI_putchar" (:integer) :integer)
   (defforeign fcgi-fread m "FCGI_fread"
	 (:string :integer :integer :integer) :integer)
   (defforeign fcgi-fwrite m "FCGI_fwrite"
	 (:string :integer :integer :integer) :integer)
   (setq fcgi_sF (* 4 (send m :find "_fcgi_sF")))
   ;; One fcgi stream is defined as a pair of references to a normal stdio
   ;; and to a fcgx stream.  Therefore, one fcgi stream structure occupies
   ;; 2 pointers, which is 8 bytes on 32-bit word machines.
   (setq *fcgi-stdin* fcgi_sf
	 *fcgi-stdout* (+ fcgi_sf 8)
	 *fcgi-errout* (+ fcgi_sf 16))
   (setq *fcgi-io* (make-foreign-string fcgi_sf 32))
   )


;; fcgi-stream class extends the stream class, defining :flush and :fill
;; with fcgi-fread and fcgi-fwrite.

(defclass fcgi-stream :super stream :slots (port stat))
(defmethod fcgi-stream
 (:init (dir buf p)
   (send-super :init dir buf)
   (setq port p)
   self)
 (:flush ()
    (when (> count 0)
        (setq stat  (fcgi-fwrite buffer 1 count port))
        (setq count 0)) )
 (:fill ()
     (setq tail (fcgi-fread buffer 1 1 port))
     ;; (format *euslog* ":fill tail=~d ch=~d~%" tail (aref buffer  0))
     (setq count 0)  )
 )

(defvar *fcgi-connections*)
(defvar *max-fcgi-connections* 20)

(defclass fcgi-connection :super propertied-object
	:slots (cookie
		http-host
		remote-addr
		remote-port
		access-time
		time-out))

(defmethod fcgi-connection
 (:init (ck &optional (timeout 3600))
    (setf http-host (unix:getenv "HTTP_HOST"))
    (setf remote-addr (unix:getenv "REMOTE_ADDR"))
    (setf remote-port (unix:getenv "REMOTE_PORT"))
    (setq access-time (car (unix:gettimeofday)))
    (setq time-out timeout)
    (setq cookie ck)
    ;; (set-cookie :key "eusid" :value ck)
    self)
 (:set-access-time () (setq access-time (car (unix:gettimeofday))))
 (:cookie () cookie)
 (:find (host ck) 
    (and (equal host http-host) (equal cookie ck)))
 (:delete () 
    (setq *fcgi-connections* (delete self *fcgi-connections*)))
 (:time-out ()
    (if (< (+ time-out access-time) (car (unix:gettimeofday)))
	(send self :delete)))
 )

(defclass fcgi-db-connection :super fcgi-connection
	:slots (db command password))

(defmethod fcgi-db-connection
 (:init (&rest args)
    (setq password nil)
    (send-super* :init args)
    self)
 (:db (&optional newdb)
    (if newdb (setq db newdb))
    db)
 (:delete ()
    (if db (send db :finish))
    (setq db nil)
    (send-super :delete))
 (:password (table &optional (record-id))
    ;; Is the password already authenticated in this connection?
    (member (list table record-id) password :test #'equal))
 (:authenticate-password (pw table &optional (record-id))
    (pushnew (list table record-id) password :test #'equal) )
 )

;; An http session is designated by the value specified by the cookie-key,
;; which can be arbitrarily chosen by an fcgi application.
;; At each http request, fcgi-loop reads a cookie list sent from a client.
;; If there is a value specified by the cooke-key, the *fcgi-connections* list
;; is scanned to find the value in the cookie slot.
;; We assume a particular fcgi application uses a fixed cookie key to
;; represent connections.

(defun fcgi-connection (cookie-key &optional (fcgi-class fcgi-connection))
   ;; scan connections and remove timed out connections
   (dolist (f *fcgi-connections*)
      (send f :time-out))
   (let ((host (unix:getenv "HTTP_HOST"))
	 (cookie (second (assoc cookie-key *cookies*)))
	 (con))
      (setq con (car (member cookie *fcgi-connections*
		 :test #'(lambda (x y) (send y :find host x)))))
      (unless con 
	 (setq con
	    (instance fcgi-class :init (random-cookie) 1200))
	 (pushnew con *fcgi-connections*))
      (send con :set-access-time)
      (setq *fcgi* t)
      con))
	 


(defmacro fcgi-loop (&rest forms)
   `(let ((stat))
	(setq *standard-input*
		(instance fcgi-stream :init :input 64 *fcgi-stdin*))
	(send *standard-input* :reset)
	(setq *standard-output*
		(instance fcgi-stream :init :output 256 *fcgi-stdout*))
	(setq *error-output* 
		(instance fcgi-stream :init :output 256 *fcgi-errout*))
	(setq *terminal-io*
		(instance io-stream :init *standard-input* *standard-output*))
	(setq *cgi-out* *standard-output*)
	;;
	(setq stat (fcgi-accept))
	(while (and (integerp stat) (>= stat  0))
	   (setq *action* (unix:getenv "SCRIPT_NAME"))
	   (with-open-file (pid-file 
			(format nil "/var/run/fcgi/~a.pid"
				(send (pathname (unix:getenv "SCRIPT_NAME")) :name))
			:direction :output)
		(format pid-file "~d~%" (unix:getpid)))
	   (setq *cookies* (get-cookie))
	   ,@forms
	   (fcgi-finish)
	   (setq stat (fcgi-accept))
       t))
   )



