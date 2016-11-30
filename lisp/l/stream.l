;;;
;;;	stream.l
;;;	file, message queu, string streams
;;;	1987-Apr
;;;	(c) 1987 Toshihiro Matsui, Electrotechnical Laboratory 
;;;

(eval-when (load eval)

(in-package "LISP")
(export '(reset-stream make-two-way-stream make-msgq-input-stream
	make-msgq-output-stream make-string-input-stream
	make-string-output-stream with-input-from-string
	with-output-to-string get-output-stream-string
	read-from-string princ-to-string prin1-to-string
	socket-address make-socket-address #|address|# destinations
	socket-port make-socket-port socket-stream 
	make-server-socket-stream make-client-socket-stream
	make-dgram-socket *select-stream-vector*
	connect-server open-server
	select-stream *asynchronous-streams* *asynchronous-stream-functions*
	sigio-handler def-async broadcast-stream make-broadcast-stream
	read-buffer write-buffer))


(defmethod io-stream 
 (:instream (&optional in)
    (if (input-stream-p in) (setq instream in))
    instream)
 (:outstream (&optional out)
    (if (output-stream-p out) (setq  outstream out))
    outstream)
 (:infd () (send instream :infd))
 (:outfd () (send outstream :outfd))
 (:in (&rest mesg) (send* instream mesg))
 (:out (&rest mesg) (send* outstream mesg))
 (:flag () (send instream :flag))
 (:async (flag) (send instream :async flag))
 (:fname () (send instream :fname))
 (:init (in out)
    (setq instream in outstream out)
    self))
)

;
; message queu stream
;
(eval-when (load eval)
(defmethod stream
 (:reset (&optional set)
    (setq count 0
	  tail (if set (length buffer) 0))
    self)
 (:discard (&optional (n 1))
	(setq count (max tail (+ count n))))
 (:count () count)
 (:tail (&optional set) (if set (setq tail (length buffer))) tail)
 (:chars-left () (- tail count))
 (:tail-string () (subseq buffer count tail))
 (:buffer (&optional start size)
     (cond (size (subseq buffer start size))
	   ((stringp start) (setq buffer start))
	   ((integerp start) (setq buffer (make-string start)))
	   (t buffer)))
 (:init (dir buf &optional start end)
    ; dir is either :input or :output, nil for closed
    ; buf is either string or a size of a string buffer
    (setq direction dir
	  buffer (if (stringp buf) buf (instantiate string buf))
	  count (if (integerp start) start 0)
	  tail  (if (integerp end) end (length buffer)) )
    self))

(defun reset-stream (s) (send s :reset))

#+(or :Solaris2 :irix :irix6)
(progn	(defconstant FASYNC #x1000)
	(defconstant F_GETFL 3)
	(defconstant F_SETFL 4)
	(defconstant F_SETOWN 24)
	(defconstant O_NONBLOCK #x80)
	(defconstant I_SETSIG #x5309)
	(defconstant S_INPUT 1)
	(defconstant S_HIPRI 2))
#+:linux
(progn  (defconstant FASYNC #o20000)
        (defconstant F_GETFL 3)
        (defconstant F_SETFL 4)
        (defconstant F_SETOWN 8))

#+:alpha
(progn	(defconstant FASYNC #o100)
	(defconstant F_GETFL 3)
	(defconstant F_SETFL 4)
	(defconstant F_SETOWN 6)
	(defconstant O_NONBLOCK #o4))

#-(or :Solaris2 :linux :irix :irix6 :alpha)
(progn	(defconstant FASYNC #x40)
	(defconstant F_GETFL 3)
	(defconstant F_SETFL 4)
	(defconstant F_SETOWN 6))

(defmethod file-stream
  (:fd () fd)
  (:instream () (if (eq direction :input) self nil))
  (:outstream () (if (eq direction :output) self nil))
  (:infd () (if (eq direction :input) fd nil))
  (:outfd () (if (eq direction :output) fd nil))
  (:fname () fname)
  (:flag () (unix:fcntl fd F_GETFL 0))	; F_GETFL
#|
#define _FOPEN          (-1)    /* from sys/file.h, kernel use only */
#define _FREAD          0x0001  /* read enabled */
#define _FWRITE         0x0002  /* write enabled */
#define _FNDELAY        0x0004  /* non blocking I/O (4.2 style) */
#define _FAPPEND        0x0008  /* append (writes guaranteed at the end) */
#define _FMARK          0x0010  /* internal; mark during gc() */
#define _FDEFER         0x0020  /* internal; defer for next gc pass */
#define _FASYNC         0x0040  /* signal pgrp when data ready */
#define _FSHLOCK        0x0080  /* BSD flock() shared lock present */
#define _FEXLOCK        0x0100  /* BSD flock() exclusive lock present */
#define _FCREAT         0x0200  /* open with file create */
#define _FTRUNC         0x0400  /* open with truncation */
#define _FEXCL          0x0800  /* error on open if file exists */
#define _FNBIO          0x1000  /* non blocking I/O (sys5 style) */
#define _FSYNC          0x2000  /* do all writes synchronously */
#define _FNONBLOCK      0x4000  /* non blocking I/O (POSIX style) */
#define _FNOCTTY        0x8000  /* don't assign a ctty on this open */
|#
  (:async (flag)
      (cond (flag
		(unix:fcntl fd F_SETFL (logior (send self :flag) FASYNC)) 
		(unix:fcntl fd F_SETOWN (unix:getpid)))
	    (t (unix:fcntl fd F_SETFL (logand (send self :flag)
						   (lognot FASYNC))))))
  (:nonblock (flag)
      (cond (flag
		(unix:fcntl fd F_SETFL (logior (send self :flag) O_NONBLOCK))
		(unix:fcntl fd F_SETOWN (unix:getpid)))
	    (t (unix:fcntl fd F_SETFL (logand (send self :flag)
						   (lognot O_NONBLOCK))))))
  (:prin1 (&optional (strm t) &rest msgs)
      (send-super-lexpr :prin1 strm
	  (format nil "~s ~s ~d" fname direction (length buffer)) msgs))
  (:init (f name dir &optional (size 128))
      (send-super :init dir size)
      (setq fd f  fname name)
      (setq tail 0)	;no initial data in the buffer
      self))

(defmethod file-stream
  (:read-bytes (n-bytes &optional (buf (make-string n-bytes)) 
				  (offset 0))
   (let* (uread-length)
	(if (and (not (stringp buf)) (< (length buf) n-bytes))
	    (error "buffer string is too short for :read-bytes"))
        (when (plusp (setq uread-length (send self :chars-left)))
	   (replace buf (send self :tail-string) :end1 n-bytes)
	   (setq uread-length (min n-bytes uread-length))
	   (incf count uread-length)
	   (incf offset uread-length))
	(while (< offset n-bytes)
	   (setq uread-length
		(unix:uread fd buf (- n-bytes offset) offset) )
	   (if (<= uread-length 0) (error "EOF hit"))
	   (incf offset uread-length)	   )
	buf
	))
  (:read-bytes-eof ()
   (let* (bufs uread-length)
        (when (plusp (setq uread-length (send self :chars-left)))
	   (setq bufs (list (send self :tail-string)))
	   (send self :discard))
	(while (plusp (setq uread-length (unix:uread fd buffer)))
	   (push (subseq buffer 0 uread-length) bufs))
	(apply #'concatenate string (nreverse bufs))
	))
   )
 
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
(defun make-string-input-stream (s &optional start end)
    (if (null (stringp s)) (error "non string"))
    (setq s (instance stream :init :input s start end))
    s)

(defun make-string-output-stream (&optional (s 64) start end)
    (setq s (instance stream :init :output s start end))
    s)

(defmacro with-input-from-string (vstring &rest forms)
  `(let ((,(car vstring) 
	  (make-string-input-stream ,(cadr vstring)
		(if (member :start ',vstring)
		    (cadr (member :start ',vstring)) nil)
		(if (member :end ',vstring)
		    (cadr (member :end ',vstring)) nil)) 
	 )  )
	. ,forms))

(defmacro with-output-to-string (vstring &rest forms)
  `(let ((,(car vstring) (make-string-output-stream . ,(cdr vstring))))
     ,@forms
     (get-output-stream-string ,(car vstring))))

(defun get-output-stream-string (s)
   (subseq (stream-buffer s) 0 (stream-count s)))

(defun read-from-string (s &optional (eof-error-p t) (eof-value nil))
   (read (make-string-input-stream s) eof-error-p eof-value))

(defun princ-to-string (x &optional (l 16))
  (let ((s (make-string-output-stream l)))
    (princ x s)
    (get-output-stream-string s)))

(defun prin1-to-string (x &optional (l 16))
  (let ((s (make-string-output-stream l)))
;    (declare (type stream s))
    (prin1 x s)
    (get-output-stream-string s)))
)

;;;;
;;;;	ipc.l
;;;;	interprocess communication functions using sockets.
;;;	1987-Nov unix domain test
;;;	1988-Jan internet communication
;;;	Copyright Toshihiro MATSUI
;;;

(eval-when (load eval)

;;;
;;; socket address creation
;;;
;;; Bug: Sockaddr, which is currently represented as a string,
;;; should be defined by defcstruct.
;;;
;;; (make-socket-address :domain af_unix
;;;			 :pathname "/usr/users/matsui/xxx")
;;;	--- intrahost communication.  :pathname cannot be a symbolic link to
;;;	--- a file on a different machine.
;;; (make-socket-address :domain af_inet
;;;			 :host "etlcom"		<--mapped by "gethostbyname"
;;;			 :port 3000		<--less than 1024 if root priv.
;;;			 :service "modelserver"		<--optional
;;;			 :protocol "tcp")		<--optional
;;;	--- internet communication socket address
;;;

(defclass socket-address :super string :element-type :byte)

(defmethod socket-address
 (:domain () (system:peek self 0 :short))
 (:port () (unix::ntohs (system:peek self 2 :short)))
 (:host () (subseq self 4 8))
 (:next-port () (system:poke (unix::htons (1+ (send self :port))) self 2 :short))
 (:prin1 (&optional (strm t))
	(send-super :prin1 strm
		(format nil "~d.~d.~d.~d ~d"
			(char self 4) (char self 5) (char self 6) (char self 7)
			(send self :port))) )
 )

(defun make-socket-address (&key (domain af_inet)
				 ((:pathname path))
				 (service "echo")
				 (port (unix:getservbyname service))
				 (host (unix:getenv "HOST"))
				 protocol)
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
		(if (eq host :local)
		    (setq host (list (integer-vector 0 0 0 0)))
		    (setq host (unix:gethostbyname host)) )
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
	    (when port
		(if (stringp port) (setq port (unix:getservbyname port)))
		(if (and (integerp port) (>= port 0)) 
		    (system:poke (unix::htons port) sockaddr_in 2 :short)))
	    sockaddr_in))))

;;;
;;; class SOCKET-PORT
;;;	socket-port defines called-sap from which a responding-sap
;;;	is instantiated by an :accept operation.
;;;	socket-port concerns only a server's stream,
;;;	and a client has not to create socket-port;
;;;	a client can simply create a socket stream from a sockaddr.
;;;

(defclass socket-port :super object :slots (id address))
(export '(socket-port-id socket-port-address))

(defmethod socket-port
 (:domain () (system:peek address 0 :short))
 (:address () address)
 (:id () id)
 (:fd () id)
 (:infd () id)
 (:listen (&optional (backlog 3)) (unix:listen id backlog))
 (:accept () (unix:accept id))
 (:flag () (unix:fcntl id F_GETFL 0))
 (:async (on)
      (cond (on
		(progn
		   (unix:fcntl id F_SETFL (logior (send self :flag) FASYNC))
					;F_SETFL
		   )
		(unix:fcntl id F_SETOWN (unix:getpid)))	;F_SETOWN
	    (t 	; turn off asynch mode
		(unix:fcntl id F_SETFL (logand (send self :flag)
						   (lognot FASYNC))))))
 (:init (addr)	;create a socket and bind addr to it
   (setq address addr)
   (let (stat)
       (setq id (unix:socket (send self :domain) unix::SOCK_STREAM 0))
       (if (< id 0)
	   (return-from :init id))
       (setq stat (unix:bind id address))
       (cond ((< stat 0) (unix:perror "bind") stat)
	     (t (setq stat (send self :listen))
		(if (= stat 0) self stat)))
       )) )

(defun make-socket-port (addr)
    (send  (instantiate socket-port) :init addr))


;;;
;;; class SOCKET-STREAM
;;;

(defclass socket-stream :super io-stream :slots (address fd))
(defmethod socket-stream
 (:domain () (system:peek address 0 :short))
 (:init (sockid addr &optional (size 128))
    (setq fd sockid)
    (setq instream (instance file-stream :init sockid "" :input size)
	  outstream (instance file-stream :init sockid "" :output size))
    (setq address addr)
    self))
    
(defun make-server-socket-stream (sockport &optional (size 512))
  (let* (ns)
    ;; (if (= (send sockport :listen) 0))
    (setq ns (send sockport :accept))
    (if (and (numberp ns) (< ns 0))
	(return-from make-server-socket-stream  ns))
    (instance socket-stream :init (car ns) (send sockport :address) size))
  )

(defvar old-sigalarm-handler nil)

(defun connect-sigalarm-handler (s x)
   (warn
	 "~a: make-client-socket-stream: connect timeout~%" *program-name*)
;;   (unix:signal unix::sigalrm old-sigalarm-handler)
   )

(defun make-client-socket-stream (address &optional (timeout 5) (size 512))
  (let* (sock conn)
    (setq sock (unix:socket (send address :domain) unix::sock_stream 0))
    (when (< sock 0)
	(unix::uclose sock)
	(return-from make-client-socket-stream  sock))
    (setq old-sigalarm-handler 
          (unix:signal unix::sigalrm 'connect-sigalarm-handler))
    (unix:alarm timeout)
    (unwind-protect
       (setq conn (unix:connect sock address))
       (progn
	   (unix:alarm 0)
	   (unix:signal unix::sigalrm old-sigalarm-handler)
	   ))
    (when (< conn 0)
	(unix::uclose sock)
	(return-from make-client-socket-stream conn))
    (instance socket-stream :init sock address size))
  )

(defun make-dgram-socket (addr)
  (let (s)
    (setq s (unix:socket (send addr :domain) unix::sock_dgram 0))
    (unix:bind s addr)
    s))

(defun connect-server (host port &optional (timeout 5))
   (make-client-socket-stream 
        (make-socket-address :domain af_inet
                         :host host :port port)
	timeout)
	)


;;;; read_async.l
;;;; Asynchronous Input Operation library
;;;; call a function when reading is possible on a stream
;;;;
;;;; 1990 (c) MATSUI Toshihiro, Electrotechnical Laboratory, JAPAN
;;;;
;;;; DEF-ASYNC takes a stream and function definition (lambda form)
;;;; When data come to the stream and reading becomes available on this stream,
;;;; the function is evaluated with the stream as an argument.
;;;  EXAMPLE:
;;;  Following forms make a socket-port on which connection requests are
;;;  listened. A function that creates a server-socket-stream is defined
;;;  to be invoked asynchronously when a connection request arrives on the 
;;;  port. The server-socket-streams are also defined as asynchronous 
;;;  streams, and when data arrives on the port, the ECHO function,
;;;  which reads and prints the incoming data, is called.
#|
   (setq sa (make-socket-address :host "etlmmd" :domain af_inet :port 5000))
   (setq sp (make-socket-port sa))
   (defun echo (s) (print (read s)))
   (defvar *server-streams* nil)
   (def-async sp (s)
	 (let ((ns (make-server-socket-stream s)))
	     (push ns *server-streams*)
	     (def-async ns echo)))
|#   
#| ;; another example
   (setq tty (open "/dev/ttya" :direction :output))
   (defun remote-error (code msg1 form &optional (msg2))
      (format *error-output* "~A error: ~A" *program-name* msg1)
      (if msg2 (format *error-output* " ~A" msg2))
      (if form (format *error-output* " in ~s" form))
      (terpri *error-output*)
      (throw 'reval nil))
   (defun reval (s)	;remote eval
      (let ((*standard-input* (send s :instream))
	    (*standard-output* (send s :outstream))
	    (*error-output* *standard-output*)
	    (*error-handler* 'remote-error))
        (catch 'reval
	   (print (eval (read s)) s))))
   (def-async tty reval)
|#


(defvar *select-stream-vector* (instantiate vector 32))

(defun select-stream (stream-list &optional (timeout 0.0))
"SELECT-STREAM stream-list [timeout 0.0]" 
   (let ((fd 0) (selected-streams) (shiftcount 0) (sifd))
      (dolist (s stream-list)
	 (setq sifd  (cond ((integerp s) s)
			   (t (send s :infd)) ))
	 (setq fd (dpb 1 fd sifd 1))
	 (svset *select-stream-vector* sifd s))
      (setq fd (unix:select-read-fd fd timeout))
      (while (> fd 0)
	 (if (logtest fd 1)
	     (push (svref *select-stream-vector* shiftcount) selected-streams))
	 (setq fd (ash fd -1))
	 (inc shiftcount))
      selected-streams))


(defvar *asynchronous-streams* nil)
(defvar *asynchronous-stream-functions* (instantiate vector 32))

(defun sigio-handler (sig code)
    (dolist (s (select-stream *asynchronous-streams*))
	(funcall (svref *asynchronous-stream-functions*
			(if (integerp s) s (send s :infd)))
		 s)
	)) 

(defmacro def-async (strm &rest func &aux fname)
"DEF-ASYNC stream lambda-list . forms"
  (cond ((cdr func)
	 (setq fname (gensym))
	 (setq func `(defun ,fname . ,func)))
	(t
	 (setq fname (car func))
	 (setq func nil)))
  `(progn
     (pushnew ,strm *asynchronous-streams*)
     (unix:signal
	unix::sigio
	;; 23 on BSD, 22 (SIGPOLL) on Solaris
	;; 29 Linux, signal (7) tells sigio=23, but 29 in signal.h
	'sigio-handler)	; 2
     (if (integerp ,strm)
	 (progn
	    (unix:fcntl ,strm F_SETFL
			 (logior (unix:fcntl ,strm F_GETFL 0) FASYNC))
	    (unix:fcntl ,strm F_SETOWN (unix:getpid)))
	 (send ,strm :async T))
     (setf (aref *asynchronous-stream-functions*
		 (if (integerp ,strm) ,strm (send ,strm :infd)))
	   ,fname)))


#|
;;;
;;;	more-stream
;;;	1989-Feb
;;;

(defclass more-stream :super stream  :slots (destination lines page-size))
(defmethod more-stream 
 (:destination (d) (if (streamp d) (setq destination d)))
 (:page-size (ps)  (setq page-size ps))
 (:init (dest &optional (ps 24))
   (send-super :init :output 256)
   (setq destination dest)
   (setq lines 0)
   (setq page-size ps)
   self)
 (:flush ()
;   (print self destination)
   (let (ch more-ch)
    (dotimes (i count)
      (setq ch (char buffer i))
      (write-byte ch destination)
      (when %(ch == 10)
	%(lines = lines + 1))
        (when %(lines >= page-size)
	   (format destination "more?")
	   (finish-output destination)
	   (setq more-ch (read-char))
	   (princ "M[1K^M" destination)
	   (case more-ch
		(32     %(lines = 0))
		(10	%(lines = lines - 1))
		((#\d #\D) %(lines = page-size / 2))))
	)
    %(count = 0))))

(defmacro more (&rest forms)
   (let ((ms (gensym)))
      `(let* ((,ms (instance more-stream :init *standard-output*))
	      (*standard-output* ,ms))
	 . ,forms)))
|#

(defclass broadcast-stream :super stream  :slots (destinations))

(defmethod broadcast-stream 
 (:destinations (&optional d)
     (if d (push d destinations))
     destinations)
 (:init (dests)
   (send-super :init :output 256)
   (setq destinations dests)
   self)
 (:flush (&aux buf)
   (if (< count (length buffer))
       (setq buf (subseq buffer 0 count))
       (setq buf buffer))
   (setq count 0)
   (dolist (d destinations)
	(princ buf d)
	(finish-output d))
   t)
 (:close ()
   (dolist (d destinations) (close d)))
  )

(defun make-broadcast-stream (&rest streams &aux dests)
  (dolist (s streams)
     (if (streamp s) (push s dests) (push (open s :direction :output) dests)))
  (instance broadcast-stream :init dests))

;; read/write a long string to/from a file most efficiently

(defun read-buffer (fname buf &optional (len (length buf)))
   (with-open-file (f fname :direction :input)
      (let ((offset 0))
	 (while (< offset len)
	    (incf offset
		  (unix:uread (send f :fd) buf (- len offset) offset))))
      buf))

(defun write-buffer (fname buf &optional (len (length buf)))
   (with-open-file (f fname :direction :output)
      (unix:write f buf len)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;
;;; port-selector
;;;

(defparameter *max-port-fd* 64)

(export '(port-selector))

(defclass port-selector
	:super propertied-object
	:slots (port-bits streams ready-bits)
	)

(defmethod port-selector
 (:init (&rest port-handlers)
    (setq port-bits (make-array *max-port-fd* :element-type :bit)
	  ready-bits (make-array *max-port-fd* :element-type :bit)
	  streams (make-array *max-port-fd*)
	  )
    (dolist (ph port-handlers)
	(send* self :add-port (first ph) (second ph) (cddr ph))
        )
    self)
 (:get-stream-fd (strm)
    (let ((fd))
      (setq fd
	     (cond ((streamp strm) (send strm :infd))
		   ((numberp strm) strm)
		   ((find-method strm :fd) (send strm :fd))
		   (t (error "stream or fd expected for select port")) ))
       (if (>= fd *max-port-fd*) (error "too many streams for selection"))
      fd))
 (:add-port (strm handler &rest arglist)
    (let ((fd (send self :get-stream-fd strm)))
       (setf (aref streams fd) (list* strm handler arglist)    )
       (setf (aref port-bits fd) 1) )
    )
 (:remove-port (strm)
    (let ((fd (send self :get-stream-fd strm)))
       (setf (aref streams fd) nil  )
       (setf (aref port-bits fd) 0))
    )
 (:streams ()
    (let (s)
      (dotimes (i *max-port-fd*) (if (aref streams i) (push (aref streams i) s)))
      (nreverse s)))
 (:fds ()
    (let (s)
      (dotimes (i *max-port-fd*) (if (= 1 (aref port-bits i)) (push i s)))
      (nreverse s)))
 (:select (&optional (timeout 0.1))
    (let (stat fun arg)
       (replace ready-bits port-bits)
       (setq stat (unix:select ready-bits nil nil timeout))
       (if (> stat 0) 
	  (dotimes (j *max-port-fd* t)
	     (when (= (aref ready-bits j) 1)
		 (setq fun (aref streams j)
		       arg (cddr fun)
		       fun (cadr fun))
		 (if (functionp fun)
		     (apply fun arg)
		     (send* fun arg))))
	   nil)
	  
      ))
 (:select-loop  (&optional (timeout 0.1) (idle-func) &rest idle-args)
    (catch :select-loop
	(while t
	   (send self :select timeout)
	   (if idle-func
	       (apply idle-func idle-args))))
    )
 )

;; provide is not yet defined here.
;; (provide :stream "@(#)$Id$")

