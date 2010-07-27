(defun reval (s)
   (print (read s)))

(defun remote-port ()
  (let* ((port 2048) (sp)
	 (sa (make-socket-address
			:domain af_inet 
			:host (unix:gethostname)
			:port port)) )
    (setq *remote-port* nil)
    (dotimes (i 1024)
	(setq sp (make-socket-port sa))
	(when (derivedp sp socket-port)
	   (warn "listening on ~d~%" (send sa :port))
	   (setq *remote-port* sp)
	   (return t))
	(send sa :next-port)
	(send sa :port))
    (unless *remote-port*  (warn "all ports engaged"))
    (eval (macroexpand '(def-async *remote-port* (s)
	 (let ((ns (make-server-socket-stream s)))
	     (push ns *server-streams*)
	     (def-async ns reval))) ))
))

(defun make-server-port (&optional (port 2051))
  (let* ((sp)
	 (sa (make-socket-address
			:domain af_inet 
			:host (unix:gethostname)	;this host
			:port port)) )
    (setq *server-port* nil)
    (setq *server-streams* nil)
    (dotimes (i 100)
	(setq sp (make-socket-port sa))
	(when (derivedp sp socket-port)
	   (warn "listening on ~d~%" (send sa :port))
	   (setq *server-port* sp)
	   (return t))
	(send sa :next-port)
	(send sa :port))
    (unless *server-port* 
	(warn "all ports engaged")
	(return-from make-server-port nil))
    (def-async *server-port* (s)
	 (let ((ns (make-server-socket-stream s)))
	     (push ns *server-streams*) ))
))

(defun make-client-connection (host port)
    (make-client-socket-stream 
	 (make-socket-address
			:domain af_inet 
			:host host 
			:port port)))


