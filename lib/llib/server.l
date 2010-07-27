;;;;
;;;;	Eusserver
;;;;	executes eus remotely
;;;;	1989-May
;;;;	T.Matsui, ETL

(defparameter *host* nil)
(defparameter *connection-count* 0)
(defparameter *connections* nil)
(defvar *server-connection* nil)

(defun server-signal (sig code)
   (throw 'new-connection nil))

(defun new-connection ()
    (warning-message 3 "new connection request arrived~%")
    (push (make-server-socket-stream *server-connection*) *connections*)
    (warning-message 4 "connection established ~d~%" (inc *connection-count*)))
    

;;;
;;; % rsh host eusserver port-no
;;;

(defun server (&optional argv)
   (warning-message 6 "Internet EusLisp Server  vers.1")
   (alloc 50000)
   (setq *host* (read-line (sys:piped-fork "hostname")))
   (let ((port-no) (saddr) (requests))
      (setq port-no
	    (if (> (length argv) 1)
		(read-from-string (aref argv 1))
		2011))
      (warning-message 5 " host=~A  port=~D~%" *host* port-no)
      (setq saddr (make-socket-address :domain af_inet
				       :host *host*
				       :port port-no))
      (setq *server-connection* (make-socket-port saddr))
      (push *server-connection* *connections*)
      (unix:signal unix:sigpipe 'server-signal)
      (while t 
	 (setq requests (select-stream *connections*))
	 (cond
	     ((eq (first requests) *server-connection*)
	      (new-connection))
	     (t
	      (dolist (s requests)
		 (print (eval (read s)) s)))))
      ))
 
(defun connect-eusserver (host &optional (port-no 2011))
   (setq *eusserver*
         (make-client-socket-stream
	      (make-socket-address :domain af_inet
				   :host host
				   :port port-no))))

(defun submit-execution (file &optional ch)
    `(progn (print ',(read file) *eusserver*)
	    (read *eusserver*)))

(set-macro-character #\! 'submit-execution)
