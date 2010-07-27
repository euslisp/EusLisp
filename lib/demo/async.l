(defparameter sa (make-socket-address :domain af_inet :port 4095))

(cond ((y-or-n-p "server?")
       (setq sp (make-socket-port sa))
       (setq s (make-server-socket-stream sp)))
      (t
       (setq s (make-client-socket-stream sa)))
      )

(defun remote-rep (s)
   (print (read s) *standard-output*))

