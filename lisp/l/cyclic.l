;; cyclic.l
;; cyclic task dispatcher using the interval timer
;; 1995 (c), Toshihiro Matsui, Electrotechnical Laboratory
;;
;; This file should be loaded into the system package.
;;

(list "@(#)$Id$")
(export '(itimer start-timer stop-timer deftimer behavior real-time
	  *itimers* *itimer-tick* *itimer-count* ))


(defconstant *itimer-tick* 0.1	"minimum timer interval")
(defparameter *itimers* nil)
(defparameter *itimer-running* t)
(defparameter *itimer-sem* (sys:make-semaphore))
(defparameter *itimer-count* 0)


(defclass itimer :super propertied-object
	:slots (interval current timer-sem func args
		real-time running run-count missed thr deleted))

(defmethod itimer
 (:init (int &optional f)
   (send self :interval int)
   (setq run-count 0
	 current   interval
	 running t
	 func f
	 missed 0
	 deleted nil
	 )
   (unless timer-sem (setq timer-sem (sys:make-semaphore)))
   (unless thr 
        (sys:make-thread 1)
	(setq thr (sys:thread 'timer-func self)))
   (unless args (setq args (list self)))
   self)
 (:delete ()
    (setq *itimers* (delete self *itimers*))
    (setq deleted t)
    (sys:sema-post timer-sem)
    (sys:wait-thread thr)
    )
 (:priority (&optional n) (send thr :priority n))
 (:running () running)
 (:tick ()
    (when (and running (zerop (decf current)))
	(setq current interval)
	(incf run-count)
	(setq real-time (* run-count *itimer-tick* interval))
	(sys:sema-post timer-sem)))
 (:func (&optional f)
    (if f (setq func f))
    func)
 (:args (&rest a) (setq args a) args)
 (:count () run-count)
 (:stop () (setq running nil))
 (:start () (setq running t))
 (:interval (&optional i)
    (if i 
	(setq interval  (round (/ i *itimer-tick*))))
    (* interval *itimer-tick*) )
 (:run ()
    (incf missed (aref timer-sem 0))
    (setf (aref timer-sem 0) 0)
    (if func (apply func args)))
 (:thread-waiting ()
    (while (not deleted)
	(sys:sema-wait timer-sem)
	(send self :run)))
 )


(defclass behavior :super itimer
	:slots (event-sem state))

(defmethod behavior
 (:init (&rest args)
   (send-super* :init args)
   (setq running nil)
   (setq event-sem (sys:make-semaphore))
   self)
 (:delete () (setq deleted t) (sys:sema-post event-sem)
    (send-super :delete))
 (:initiate ()
    (cond (running nil)
	  (t  (sys:sema-post event-sem) t)))
 (:starting () 
    (setq running t
	  run-count 0)   )
 (:thread-waiting ()
    (while (not deleted)
	(sys:sema-wait event-sem)
	(when (not deleted)
           (send self :starting)
	   (while running
	      (sys:sema-wait timer-sem)
	      (send self :run)))))
   )


(defun timer-func (timer)
   (send timer :thread-waiting)
   (format t ";timer-func finished ~s~%" timer) )
      

(defun itimer-handler ()	;run by an independent thread
   (while t
      (sys:sema-wait *itimer-sem*)
      (incf *itimer-count*)
      (when *itimer-running*
	 (dolist (it *itimers*)
	    (send it :tick)))))

(defun find-itimer (name)
   (find-if #'(lambda (it) (eql (send it :name) name)) *itimers*))

(defmacro deftimer (name  klass interval &rest init-args)
   `(let ((it (find-itimer ',name)) (func))
	(if (null it) 
	    (setq it 
	    (if (and (boundp ',klass) (subclassp ,klass itimer))
		(instantiate ,klass)
		(progn (setq func ',klass) (instantiate itimer)))))
        (pushnew (setq ,name (send* it :init ,interval func ,init-args))
		 *itimers*)
	(send  it :name ',name))
)


(defun init-cyclic ()
   (sys:make-thread 3)
   (sys:thread-no-wait 'itimer-handler)
   (unix:signal unix::sigalrm *itimer-sem* 20)
	; 4 for restart 16 for nodefer
   )

(defun start-timer ()
;   (dolist (it *itimers*)
;         (setf (itimer-running it ) t))
   (unix:setitimer 0 1 *itimer-tick*))

(defun stop-timer ()
   (unix:setitimer 0 0 0)
;   (dolist (it *itimers*)
;    (setf (itimer-running it ) nil))
)

