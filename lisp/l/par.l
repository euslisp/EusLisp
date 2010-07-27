;;; (par  form-1 form-2 ... form-n)
;;  ---> expanded to
;;	 (let ((p1 (thread . form-1))
;		 (p2 (thread . form-2))
;		 ...
;		 (pn (thread . form-n)))
;    		(mapcar #'wait-thread (list p1 p2 ... pn)))
(in-package "SYSTEM")

(export '(plist mutex))
(export '(barrier-synch synch-memory-port))

(defmethod thread
 (:id () id)
 (:priority (&optional n)
    (if (integerp n) (unix:thr-setprio id n))
    (unix:thr-getprio id))
)

(defmacro plist (&rest forms)
   (let (thread-list)
      (dolist (f forms)
	 (push `(thread #',(car f) . ,(cdr f)) thread-list))
     `(mapcar #'system:wait-thread
	  (list . ,(nreverse thread-list)))) )

(defmacro mutex (lock &rest forms)
  (let ((lockvar (gensym)))
  `(let ((,lockvar ,lock))
      (mutex-lock ,lockvar)
      (unwind-protect
	  (progn . ,forms)
	  (mutex-unlock ,lockvar)))))

(defclass barrier-synch :super propertied-object
		:slots (threads n-threads count 
			barrier-cond
			threads-lock
			count-lock))

(defmethod barrier-synch
 (:init ()
    (setq count 0
	  n-threads 0
	  threads nil
	  count-lock (make-mutex-lock)
	  threads-lock (make-mutex-lock)
	  barrier-cond 
#+(or :Solaris2 :Alpha)
              (make-cond)
#+:SunOS4.1
              (make-cond count-lock)
	      )
    self)
 (:add (thr)
    (unless (member thr threads)
	(mutex threads-lock
	   (setq threads (nconc threads thr))
	   (incf n-threads)))
    )
 (:remove (thr)
    (mutex threads-lock
       (setq threads (delete thr threads)))
    )
 (:wait ()
    (mutex count-lock
       (incf count)
       (if (= count n-threads)
	   (progn  (cond-signal barrier-cond) (setq count 0))
	   (cond-wait count-lock barrier-cond))))
 )

(defclass synch-memory-port :super propertied-object
	:slots (sema-in sema-out buf empty lock))

(defmethod synch-memory-port
 (:read ()
    (sema-wait sema-in)
    (prog1 buf (sema-post sema-out)))
 (:write (p)
   (sema-wait sema-out)
   (setq buf p)
   (sema-post sema-in))
 (:init ()
    (setq sema-in (make-semaphore)
	  sema-out (make-semaphore)
	  empty t)
    (sema-post sema-out)
    self))

(defun thread-eval (p1 p2)
   (loop
      (send p2 :write (eval (send p1 :read)))))


#|
(defun thrtest ()
  (make-thread 4)
  (setq p1 (instance synch-memory-port :init)
	p2 (instance synch-memory-port :init))
  (thread 'thread-eval p1 p2))
|#




(defun thread-error (code msg1 form &optional (msg2))
   (let* ((thr (system::thread-self))
	  (s (get thr :stdio)))
     (format s "~A ~d error: ~A" *program-name*	(send thr :id) msg1)
     (if msg2 (format s " ~A" msg2))
     (if form (format s " in ~s" form))
     (terpri s)
     (throw :thread-loop-again nil)) )


(defun thread-top (s)
   (let* ((thr (system::thread-self))
	  (id (send thr :id)))
      (setf (get thr :stdio) s)
      (lisp::install-error-handler 'thread-error)
      (catch :thread-loop
	(while t
	   (catch :thread-loop-again
		(lisp::reploop (format nil "thr~d$ " id) s t))) )
      (warn "thread-top ~d finished~%" id)
      ))


(defun repwin (port &optional (host (unix:getenv "HOST")))
   (let* ((sa (make-socket-address :port port :host host :domain af_inet))
	 f (s (make-client-socket-stream sa)))
     (system::thread-no-wait 'thread-top s)
      ))

(provide :par "@(#)$Id: par.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")
