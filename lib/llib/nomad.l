;;;;
;;;; nomad.l	I/O test program for the use of nomad dial and mouse.
;;;;	To use nomad, tty line 15 (/dev/tty0e) must be stty'ed as
;;;;	9600bps and raw mode.
;;;;	To use mouse, turn /dev/tty0f line to raw mode and 1200 bps.
;;;;
;;;;	1988-Apr
;;;;	T.Matsui, ETL

(defparameter *mouse-device* nil)
(defparameter *host* "etlic2")

(defun init-mouse (&optional (dev "/dev/tty0f"))
   (setq *mouse-device* (open dev :direction :io)) )

(defun init-nomad (&optional (dev "/dev/tty0e"))
  (let (p)
    (setq *nomad-device* (open dev :direction :io))
    (setq p (tiocgetp *nomad-device*))
    (setf (aref p 5) #xc3)
    (tiocsetp *nomad-device* p)))

(defparameter *nomad* (make-array 9))

(defun mouse-value (v)
  (if (> v 127) (- v 256) v))

(defun get-mouse ()
  (let ((ch 0) switch xvalue yvalue)
    (while (not (eq (logand ch #xf8) #x80)) (setq ch (read-char *mouse-device*))) ;escape
    (setq switch (logand ch #x7))
    (setq xvalue (mouse-value (read-char *mouse-device*)))
    (setq yvalue (mouse-value (read-char *mouse-device*)))
    (inc xvalue  (mouse-value (read-char *mouse-device*)))
    (inc yvalue  (mouse-value (read-char *mouse-device*)))
    (list switch xvalue yvalue)))


(defun get-nomad ()
  (let ((ch 0) (sign 1) chan value)
    (while (not (eq ch 27)) (setq ch (read-char *nomad-device*))) ;escape
    (setq chan (- (read-char *nomad-device*) 48))
    (setq sign (read-char *nomad-device*))
    (setq value (+ (* 100 (- (read-char *nomad-device*) #\0))
                   (* 10 (- (read-char *nomad-device*) #\0))
                   (- (read-char *nomad-device*) #\0)))
    (if (eq sign #\-) (setq value (- value)))
    (list chan value)))

(defun read-nomad ()
   (let ((nomad (get-nomad)))
      (setf (aref *nomad* (car nomad))
	    (+ (aref *nomad* (car nomad)) (cadr nomad)))
      *nomad*))

(defun reset-nomad () 
   (dotimes (i 9) (setf (aref *nomad* i) 0)))


(defun nomad-signal (sig code)
   (throw 'new-connection nil))

(defun nomad2 ()
    (warning-message 3 "waiting for a nomad connection~%")
    (setq *nomad-stream* (make-server-socket-stream *nomad-connection*))
    (warning-message 4 "connection established ~d~%" (inc *connection-count*))
    (while t (print (get-nomad) *nomad-stream*)))


(defun nomad (&optional argv)
   (warning-message 6 "Internet Nomad Dial Server  vers.1")
   (alloc 50000)
   (setq *connection-count* 0)
   (init-nomad)
   (let ((port-no) (saddr))
      (setq port-no
	    (if (> (length argv) 1)
		(read-from-string (aref argv 1))
		2010))
      (warning-message 5 " host=~A  port=~D~%" *host* port-no)
      (setq saddr (make-socket-address :domain af_inet
				       :host *host*
				       :port port-no))
      (setq *nomad-connection* (make-socket-port saddr))
      (unix:signal unix:sigpipe 'nomad-signal)
      (while t 
	(catch 'new-connection (nomad2)))))
 

(setq *nomad-address* (make-socket-address :domain af_inet
					   :host "etlic2"
					   :port 2010))
(setq *nomad-stream* (make-client-socket-stream *nomad-address*))

(defun read-nomad () (read *nomad-stream*))
