;;;
;;;	process.l
;;;	unix process handling functions
;;;	1987-Apr
;;;	(c) Toshihiro Matsui, Electrotechnical Laboratory
;;;

(eval-when (load eval)
(in-package "LISP")
(export '(cd pwd ez piped-fork popen xfork dir directory rusage))

(defmacro cd (&optional (dir (unix:getenv "HOME")))
    (if (symbolp dir) (setq dir (string-downcase (string dir))))
    `(unix:chdir ,dir))
(defun pwd () (unix:getwd))
(defun ez (&optional (key (read-from-string (unix:getenv "LOGINPID") )))
   (let ((msg1 (unix:msgget (+ key #x50000)))
	 (msg2 (unix:msgget (+ key #x60000)))
	 (buf (instantiate string 256))
	 (inputs nil) (msg nil))
      (unix:msgsnd msg1 "" 0 2)	;start ez
      (while (not (equal (car (setq msg (unix:msgrcv msg2 buf 0))) 99))
	  (setq inputs (nconc inputs (list (subseq buf 0 (cadr msg))))))
      (if (null inputs) (return-from ez nil))
      (setq inputs (make-string-input-stream
			 (apply 'concatenate string inputs)))
      (while (null (equal (setq msg (read inputs nil :eof)) :eof))
         (print (eval msg)))))


;;; fork a new euslisp and connect it through pipes
;;; First, forked process set up pipes after closing old standard io's.
;;; Then, if exec is given, child process issues exec call to start off
;;; a new program.
;;; If no exec is given, it enters read-eval-print loop through the pipes.
;;; Piped-fork returns an io-stream whose components are two pipes to
;;; the parent process.
;;;
;;;	modified on 1987-Nov-21 to comform to the new toplevel by T.Matsui
;;;	December, 1999; unix:system is used instead of exec.
;;;
;;; Note that although standard-io is switched to pipes, the tty remains
;;; as the control terminal and signals raised from the keyboard (^C) are 
;;; sent to the child euslisp.


(defun piped-fork (&optional (exec) &rest args)
  (let ((p1 (unix:pipe)) (p2 (unix:pipe)) (pid (unix:fork)) ifd ofd is os ts tty)
    (unless (streamp p2)
	(error (unix:syserrlist (- p2))))
    (if (= pid 0)
	(progn	;; child
	     (close *standard-input*)
	     (close *standard-output*)
	     (close (p1 . outstream))
	     (close (p2 . instream))
	     (setq ifd (unix:dup (send p1 :infd))    ;fd=0
	    	   ofd (unix:dup (send p2 :outfd)))  ;fd=1
	     ; (setq tty (open "/dev/tty" :direction :io))
	     ; (format tty "stdin=~d stdout=~d~%" ifd ofd)
	     (unix:signal 2 1)	;; SIGINT = SIG_IGN
	     (setq *standard-input*
			 (instance file-stream :init ifd "pipe" :input)
		   *standard-output*
			 (instance file-stream :init ofd "pipe" :output)
		   *terminal-io*
			 (make-two-way-stream *standard-input*
					      *standard-output*))
	     (cond ((stringp exec)
		     (if (position #\space exec)
			 (unix:system exec)
			 (apply #'unix:exec exec args)))
		   ((functionp exec)
		     (apply exec args)
		     (throw :eusexit t))
		   (t  (while t 
			  (catch 0
			      (setq *replevel* 0)
			      (reploop "")
			      (throw :eusexit nil)) )  )
		  )
	;; Matsui is not very sure whether the child process should exit here.
        ;; Okada suppose we should use _exit not exit.
	(unix::_exit 1))
    (let ((io (instantiate io-stream)) in out)
      (if *debug* (format t ";; child_pid=~D~%" pid))
      (setf (get io :pid) pid)
      (setq in (p2 . instream)
	    out (p1 . outstream))
      (setq (io . instream) in
	    (io . outstream) out)
      (setf (get in :pid) pid)
      (close (p1 . instream))
      (close (p2 . outstream))
      io)
    ))
  )

(defun popen (exec &rest args)
  (let ((p1 (unix:pipe)) (p2 (unix:pipe))
        pid)
    ;; the next call used to be unix::fork1 that was available only on  Solaris
    (if (= (setq pid (unix::fork)) 0)
      (progn
        (close *standard-input*)
        (close *standard-output*)
        (close (p1 . outstream))
        (close (p2 . instream))
        (unix:dup (send p1 :infd))      ;fd=0
        (unix:dup (send p2 :outfd))     ;fd=1
	(if (position #\space exec)
	    (unix:system exec)
	    (apply #'unix:exec exec args)) )
      (let ((io (instantiate io-stream)) in out)
        (if *debug* (format t ";; child_pid=~D~%" pid))
        (setf (get io :pid) pid)
        (setq in (p2 . instream)
              out (p1 . outstream))
        (setq (io . instream) in
              (io . outstream) out)
        (setf (get in :pid) pid)
        (close (p1 . instream))
        (close (p2 . outstream))
        io))
    ))


(defun xfork (exec &key (stdin  *standard-input*)
			(stdout *standard-output*)
			(stderr *error-output*)
			(args nil))
   (let ((pid (unix:fork)) (ios))
      (cond ((= pid 0)  ;child proc
	     (unless (= (send stdin :infd) 0)
		(unix:dup2 (send stdin :infd) 0))
	     (unless (= (send stdout :outfd) 1)
		(unix:dup2 (send stdout :outfd) 1))
	     (unless (= (send stderr :outfd) 2)
		(unix:dup2 (send stderr :outfd) 2))
	     (if (position #\space exec)
		 (unix:system exec)
		 (apply #'unix:exec exec args))
	     (error "exec") (exit 1))
            (t (if *debug* (format t ";; child_pid=~D~%" pid))))
      (setq ios (instance io-stream :init
			(send stdout :instream) (send stdin :outstream)))
;      (if (io-stream-p stdin) (close (send stdin :instream)))
;      (if (io-stream-p stdout) (close (send stdout :outstream)))
      ios)
    )
;;
;; slower but more complete "directory"
;;

#+(or :linux :solaris2 :cygwin :alpha)
   (setf (symbol-function 'directory) (symbol-function 'unix::readdir))
#-(or :linux :solaris2 :cygwin :alpha)
 (defun directory (&optional (dir "."))
   (let ((fnlist) (ls) (eof (cons nil nil)) (fn))
      (setq ls (piped-fork "ls" "-a" dir))
      (while (not (eq (setq fn (read-line ls nil eof)) eof))
	 (push fn fnlist))
      (nreverse fnlist))) 

(defun dir (&optional (dir "."))
   (let ((dirs (sort (directory dir) #'string<)))
     (tprint dirs
	     (max 16 (1+ (apply #'max (mapcar #'length dirs))))
             0 80 )))

(defun rusage (&optional (who 0) (s t))
  (let ((r (unix:getrusage who))
	(psize (/ (unix:getpagesize) 1024)))
     (format s "user time ~f sec~%system time ~f sec~%" (pop r) (pop r))
     (format s "max resident core ~d Kb~%" (* (pop r) psize))
     (pop r)	;ru_ixrss
     (format s "integral resident   ~d Kb~%" (* (pop r) psize))
     (pop r)	; ru_isrss
     (format s "page faults without I/O ~d ~%" (pop r))
     (format s "page faults with I/O   ~d ~%" (pop r))
     (format s "swaps         ~d ~%" (pop r))
     (format s "input op.     ~d ~%" (pop r))
     (format s "output op.    ~d ~%" (pop r))
     (format s "message sent  ~d ~%" (pop r))
     (format s "message rcvd  ~d ~%" (pop r))
     (format s "signals       ~d ~%" (pop r))
     (format s "volutary sw.  ~d ~%" (pop r))
     (format s "involutary sw.~d ~%" (pop r))))


(defun xterm-window (&optional (cmnd "xterm") (port))
  (let ((ptyname) (c #\p) (n 0) (ptystream) (fd) (pipe))
    (while (null ptystream)
	(setq ptyname (format nil "/dev/pty~c~1,1x" c n) )
	;; (print ptyname)
	(setq ptystream
	      (open ptyname :if-does-not-exist nil  :direction :io ))
	(unless ptystream
	   (incf n)
	   (when (= n 16)
	      (incf c)   (setq n 0)
	      (if (= c #\z) (return-from xterm-window nil))) )
	)
    (when (> (setq fd (send ptystream :infd)) 9)
	(close ptystream) (return-from xterm-window nil))
    (send ptystream :name ptyname)
    (setq pipe (piped-fork cmnd (format nil "-S~c~1,1x~1d" c n 0)) )
    (list   ptystream pipe)))


(provide :process "@(#)$Id$")


