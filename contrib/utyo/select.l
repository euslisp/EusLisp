(defun read-no-hang (&optional (fd *standard-input*)
			       &key (timeout 10))
  (let ((readfds (make-array 32 :element-type bit-vector))
        (writefds (make-array 32 :element-type bit-vector))
        (exceptionfds (make-array 32 :element-type bit-vector))
;       (dir (*standard-input* . direction))
        v)
    (svset readfds 27 1)
    (setq v (unix:select readfds writefds exceptionfds timeout))
    (cond
      ((< v 0) 'error)
      ((zerop v) nil)
      (t (read fd)))))

(defun getch-no-hang (&optional (fd carm:*in-port*)
				&key (timeout 4))
  (let ((readfds (make-array 32 :element-type bit-vector))
        (writefds (make-array 32 :element-type bit-vector))
        (exceptionfds (make-array 32 :element-type bit-vector))
	;;       (dir (*standard-input* . direction))
        v)
    (svset readfds 27 1)
    (do ((stream-st (unix:select readfds writefds exceptionfds timeout)
                    (unix:select readfds writefds exceptionfds timeout)))
        ((<= stream-st 0) nil)
      (write-byte (read-char carm:*in-port*) *standard-output*)
    )
  )
)
;;;
;;;	stream.l
;;;	file, message queu, string streams
;;;	1987-Apr
;;;	(c)T.Matsui
;;;
;;
;;	I/O
;;
(eval-when (load eval)
(defmethod io-stream 
 (:instream (&optional in)
    (if (input-stream-p in) (setq instream in))
    instream)
 (:outstream (&optional out)
    (if (output-stream-p out) (setq  outstream out))
    outstream)
 (:init (in out)
    (setq instream in outstream out)
    self))

(defun reset-stream (s) (setq (s . count) 0))
)

;
; message queu stream
;
(eval-when (load eval)
(defmethod stream
  (:reset () (setq count 0 tail 0) self)
  (:init (dir buf)	;buf is either string or a size of a string buffer
      (send self :reset)
      (setq direction dir
	    buffer (if (stringp buf) buf (instantiate string buf)))
      self))

(defmethod file-stream
  (:init (f name dir &optional (size 128))
      (send-super :init dir size)
      (setq fd f  fname name)
      self))

(defun make-two-way-stream (in out)
   (instance io-stream :init in out))

(defun make-msgq-input-stream (k &optional (size 128))
   (instance file-stream :init (unix:msgget k) k :input size))

(defun make-msgq-output-stream (k &optional (size 128))
   (instance file-stream :init (unix:msgget k) k :output size))

)

;
; string stream
;
(eval-when (load eval)
(defun make-string-input-stream (s)
    (if (null (stringp s)) (error "non string"))
    (setq s (instance stream :init :input s))
    (setq (s . tail) (length (s . buffer)))
    s)

(defun make-string-output-stream (s)
    (setq s (instance stream :init :output s))
    (setq (s . tail) (length (s . buffer)))
    s)

(defun read-from-string (s &optional (eof-error-p t) (eof-value nil))
   (read (make-string-input-stream s) eof-error-p eof-value))

(defun princ-to-string (x &optional (l 16))
  (let ((s (make-string-output-stream l)))
;    (declare (type stream s))
    (princ x s)
    (subseq (s . buffer) 0 (s . count))))

(defun prin1-to-string (x &optional (l 16))
  (let ((s (make-string-output-stream l)))
;    (declare (type stream s))
    (prin1 x s)
    (subseq (s . buffer) 0 (s . count))))
)

;;;;
;;;;	ipc.l
;;;;	interprocess communication functions using sockets.
;;;	1987-Nov unix domain test
;;;	1988-Jan internet communication
;;;	Copyright Toshihiro MATSUI
;;;

(eval-when (load eval)

;   (sys:binload "clib/ipc.o" "" "_eusmain" "" "a.out"
;	     "-lc")

;;; address family constants
(defconstant AF_UNIX  1)
(defconstant AF_INET 2)
)
;;;
;;; socket address creation
;;;
;;; Sockaddr is currently represented as a string
;;; However, it should be redefined using defcstruct in the future.
;;;
;;; (make-socket-address :domain af_unix
;;;			 :pathname "/usr/users/matsui/xxx")
;;;	--- host local address.  :pathname cannot be symbolically linked to
;;;	--- a file system on a different machine.
;;; (make-socket-address :domain af_inet
;;;			 :host "etlcom"		<--mapped by "gethostbyname"
;;;			 :port 3000		<--less than 1024 if root priv.
;;;			 :service "modelserver"		<--optional
;;;			 :protocol "tcp")		<--optional
;;;	--- internet communication socket address
;;;

(defclass socket-address :super string :element-type :char)
(defmethod socket-address
 (:domain () (system:peek self 0 :short)))

(defun make-socket-address (&key domain
				 ((:pathname path))
				 port host service protocol)
  (cond ((eq domain AF_UNIX)
	 (let ((sockaddr_un (instantiate socket-address
					 (max 16 (+ 2 (length path))))))
	    (replace sockaddr_un path :start1 2)
	    (system:poke domain sockaddr_un 0 :short)
	    sockaddr_un))
	((eq domain AF_INET)
	 (let ((sockaddr_in (instantiate socket-address 16)))
	    (system:poke domain sockaddr_in 0 :short)
	    (when host
		(setq host (unix:gethostbyname host))
		(if (numberp host)
		    (return-from make-socket-address
				 (unix:syserrlist (- host))))
		(replace sockaddr_in (car host) :start1 4))
	    (when service
		 (setq service (unix:getservbyname service protocol))
		 (if (numberp service)
		     (return-from make-socket-address
				 (unix:syserrlist (- service))))
		 (system:poke (car service) sockaddr_in 2 :short))
	    (when port (system:poke port sockaddr_in 2 :short))
	    sockaddr_in))))
;;;
;;; class SOCKET-PORT
;;;	socket-port defines called-sap from which a responding-sap
;;;	is instantiated by an :accept operation.
;;;	socket-port concerns only a server's stream,
;;;	and a client has not to create socket-port;
;;;	it can simply create a socket stream from a sockaddr.
;;;

(defclass socket-port :super object :slots (socket-id address))
(defmethod socket-port
 (:domain () (system:peek address 0 :short))
 (:address () address)
 (:socket-id () socket-id)
 (:listen (&optional (backlog 3)) (unix:listen socket-id backlog))
 (:accept () (unix:accept socket-id))
 (:init (addr)	;create a socket and bind addr to it
   (setq address addr)
   (let (stat)
       (setq socket-id (unix:socket (send self :domain) 1 0))
       (if (< socket-id 0)
	   (return-from :init socket-id))
       (setq stat (unix:bind socket-id address))
       (if (< stat 0)
	   (return-from :init stat))
       self)))

(defun make-socket-port (addr) (instance socket-port :init addr))

;;;
;;; class SOCKET-STREAM
;;;

(defclass socket-stream :super io-stream :slots (address))
(defmethod socket-stream
 (:domain () (system:peek address 0 :short))
 (:init (sockid addr &optional (size 128))
    (setq instream (instance file-stream :init sockid "" :input size)
	  outstream (instance file-stream :init sockid "" :output size))
    (setq address address)
    self))
    
(defun make-server-socket-stream (sockport &optional (size 512))
  (let* (ns)
    (if (= (send sockport :listen) 0) (setq ns (send sockport :accept)))
    (if (and (numberp ns) (< ns 0))
	(return-from make-server-socket-stream (- ns)))
    (instance socket-stream :init (car ns) (send sockport :address) size))
  )

(defun make-client-socket-stream (address &optional (size 512))
  (let* (sock)
    (setq sock (unix:socket (send address :domain) 1 0))
    (if (< sock 0)
	(return-from make-client-socket-stream (- sock)))
    (if (< (unix:connect sock address) 0)
	(return-from make-client-socket-stream (- sock)))
    (instance socket-stream :init sock address size))
  )

(defun make-stream-fd-bit-vector (&rest streams)
   (let ((iv (instantiate intvector 1)) afd)
      (dolist (s streams)
	 (if (io-stream-p s) (setq s (s . instream)))
	 (setq afd (s . fd))
	 (setf (aref iv  0) (logior (aref iv 0) (ash 1 afd))))
      iv))
;;;
;;;;
;;;;	euslisp toplevel loop and error/signal handler
;;;;
;;;;	1987-Oct
;;;;	Copyright Toshihiro MATSUI
;;;

(eval-when (load eval)

(defvar - nil)
(defvar * nil)
(defvar ** nil)
(defvar *** nil)
(defvar + nil)
(defvar ++ nil)
(defvar +++ nil)
(defvar *replevel* 0)
(defvar *input-line*)
(defvar *prompt-string* "eus$ ")
(defparameter *try-unix* t)

(defun skip-blank (s &optional (eof (gensym)))
   (let ((ch (read-char s nil eof)))
      (if (eq ch eof) (return-from skip-blank eof))
      (while (position ch " 	") (setq ch (read-char s)))
      (unread-char ch s)
      ch))
)

;;
;; read-list-from-line returns eof if eof hit
;; if a list is entered, its list is returned
;; otherwise, a list of all input items in a line is returned
;;

(eval-when (load eval)
(defun read-list-from-line (&optional (s *standard-input*) (eof (gensym)))
   (let* ((ch) (instream) (sexp) (listed-sexp))
      (setq ch (skip-blank s eof) *input-line* nil)
      (cond
	 ((eq ch eof) eof)
	 ((eq ch #\() 		;)
	  (setq sexp (read s nil eof))
	  (read-char s)
	  sexp)
         ((eq ch #\,) 
	  (read-char s)
	  (setq sexp (read s))
	  (read-char s)
	  sexp)
         (t
	  (setq *input-line* (read-line s nil eof))
	  (if (eq *input-line* eof) (return-from read-list-from-line eof))
	  (make-string-input-stream *input-line*)))))

(defun sigint-handler (sig code)
   (warning-message 5 "interrupt")
   (let* ((*replevel* (1+ *replevel*)))
      (catch t  (reploop (format nil "B~d-~A" *replevel* *prompt-string*)))))

(defun eussig (sig code)
   (warning-message 5 "signal ~s ~s~%" sig code)
   (let* ((*replevel* (1+ *replevel*)))
      (catch t  (reploop (format nil "B-~d~A" *replevel* *prompt-string*)))))

(defun reploop (prompt)		;read-eval-print loop
  (let* ((result)
	 (ttyp (unix:isatty *terminal-io*))
	 (*error-handler* 'euserror)
	 (eof (gensym))
	 (command) (input)
	 (arg) (arglist) (local-bindings) (special-bindings))
     (if (> *replevel* 0)
	 (setq  local-bindings (sys:list-all-bindings)
		special-bindings (sys:list-all-special-bindings)))
     (while t
       (catch 'reploop
          (when ttyp
	     (if (not (eq *package* *user-package*))
		 (format *terminal-io* "~A:" (package-name *package*))) 
             (format *terminal-io* "~A" prompt)
             (finish-output *terminal-io*))
          (setq input (read-list-from-line *terminal-io* eof))
	  (if (eq input eof) (return-from reploop nil))
	  (cond
		((null input) nil)
		((symbolp input)
		 (cond
		    ((> *replevel* 0)
		     (setq result (eval-dynamic input local-bindings)))
		    (t (setq result nil)))
		 (print result *terminal-io*))
		((or (null (streamp input)) (listp input))
		 (print (setq result (eval input))  *terminal-io*))
		((streamp input)
		  (setq command (read input nil eof))
		  (cond
			((eq command eof) )
			((and (symbolp command) (fboundp command))
			 (setq arglist nil)
			 (while (not (eq (setq arg (read input nil eof)) eof))
				(push arg arglist))
			 (setq - (cons command (nreverse arglist)))
			 (print (setq result (eval -)) *terminal-io*))
			((or (numberp command)
			     (listp command)
			     (null (symbolp command))
			     (boundp command))
			 (print (setq result (eval command)) *terminal-io*))
			((and *try-unix* (eq (unix:system *input-line*) 0)))
			(t (warning-message 5 "command unrecognized")
			   (terpri *terminal-io*) ))))
             (setq +++ ++ ++ + + -)
	     (setq *** ** ** * * result)))))
    
(defun euserror (code msg1 form &optional (msg2))
   (format *error-output* "~A error: ~A" *program-name* msg1)
   (if msg2 (format *error-output* " ~A" msg2))
   (if form (format *error-output* " in ~s" form))
   (terpri *error-output*)
   (let ((*replevel* (1+ *replevel*)))
      (catch *replevel*
	(reploop (format nil "E~D-~A" *replevel* *prompt-string* ))))
   (throw *replevel* nil))

(defun eustop (&optional argv)
   (when (unix:isatty *standard-input*)
     (warning-message 3 "~A" (lisp-implementation-version))
     (terpri) )
   (unix:signal unix:sigint 'sigint-handler 2)
   (unix:signal unix:sigpipe 'eussig)
;;   (let ((rcfile (concatenate string (unix:getenv "HOME") "/.eusrc")) (i 0))
;;      (when (probe-file rcfile) (load rcfile)))
   (let (exp)
      (dotimes (i (1- (length argv)))
	 (setq exp (aref argv (1+ i)))
	 (cond ((eq (aref exp 0) #\()	;)
		(eval (read-from-string exp)))
	       (t (load exp)))))
   (catch 'eusexit
       (while t
	  (catch 0
	      (setq *replevel* 0)
	      (reploop *prompt-string*)
	      (throw 'eusexit nil)))))

(defun reset () (throw 0 nil))
)
