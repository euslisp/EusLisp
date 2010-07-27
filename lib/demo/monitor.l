
;I wrote a generic Common LISP monitoring package a long time ago.  It
;has a couple of features that I have not seen in any other package.
;
;--It handles closures stored in data structures.
;
;--It handles nested calls properly.
;
;--It is portable and easy to use.
;
;Enjoy!
;
;;; -*- Mode: LISP; Package: monitor; Syntax: Common-lisp; Base: 10.;  -*- 
;
;;;----------------------------------------------------------------------------
;;;
;;; Monitor
;;;
;;; Author: Chris McConnell, ccm@cs.cmu.edu
;;;
;;; Package for monitoring functions in a generic Common LISP
;;; implementation.  I made the package as mistake proof as I could
;;; without redefining defun.  One of its features is that functions
;;; that are stored away in data structures can also be monitored.
;;;
;;; The easy way to use this package is to load it and execute
;;; (mon:monitor-form your-form) this will report on the execution
;;; times of all symbols in the current package.  Other variants can
;;; be constructed from the monitoring primitives.
;;;
;;; Any place that has a setf method can be monitored.  This includes
;;; monitoring a closure stored in a data structure.  For example, to
;;; monitor the closure stored in the 0th element of the 1d array
;;; *array*, you would call (mon:monitor `(aref *array* 0)).
;;;
;;; If your times vary widely, possible causes are:
;;;
;;; --Garbage collection.  Try turning it off, then running your code.
;;; Be warned that monitoring code will probably cons when it does
;;; (get-internal-run-time). 
;;;
;;; --Swapping.  If you have enough memory, execute your form, then
;;; monitor it, otherwise, get a bigger machine!
;;;
;;; --Resolution of internal-time-units-per-second.  If this value is
;;; too low, then the timings become wild.  You can try executing more
;;; of whatever your test is, but that will only work if some of your
;;; paths do not match the timer resolution.  
;;;
(provide "monitor")
(in-package 'monitor :nicknames '(mon))
(export '(monitor monitor-all unmonitor 
	  start-monitoring
	  monitor-time monitor-calls
	  report-monitoring
	  monitor-form))

;;;
(defvar *MONITOR-ORIGINAL* (make-hash-table :test #'equal)
  "Mapping from function names to the original function.")
(defvar *MONITOR* (make-hash-table :test #'equal)
  "Mapping from function names to the monitor for the function.")
(defvar *MONITOR-TIME* (make-hash-table :test #'eq)
  "Mapping from function names to the resident execution time.")
(defvar *MONITOR-CALLS* (make-hash-table :test #'eq)
  "Mapping from function names to the number of function calls.")
(defvar *MONITOR-OVERHEAD* nil
  "The amount of time an empty monitored function costs.")
(defvar *TOTAL-TIME* 0
  "Total amount of time monitored so far.")
(defvar *MONITORED* nil
  "List of monitored symbols.")

;;;
(defun PLACE-FUNCTION (function-place)
  "Return the function found at FUNCTION-PLACE."
  (if (symbolp function-place)
      (symbol-function function-place)
      (eval function-place)))

;;;
(defun SET-PLACE-FUNCTION (function-place function)
  "Set the function in FUNCTION-PLACE to FUNCTION."
  (if (symbolp function-place)
      (setf (symbol-function function-place) function)
      (eval `(setf ,function-place ',function))))
(defsetf PLACE-FUNCTION (function-place) (function)
  `(set-place-function ,function-place ,function))

;;;
(defun PLACE-FBOUNDP (function-place)
  "Test to see if FUNCTION-PLACE is a function."
  (if (symbolp function-place)
      (fboundp function-place)
      (functionp (place-function function-place))))

;;;
(defun PLACE-MACROP (function-place)
  "Test to see if FUNCTION-PLACE is a macro."
  (when (symbolp function-place)
    (macro-function function-place)))
  
;;;
(defun PLACE-ORIGINAL (function-place)
  "Return the original function for FUNCTION-PLACE."
  (gethash function-place *monitor-original*))
(defsetf PLACE-ORIGINAL (function-place) (function)
  `(setf (gethash ,function-place *monitor-original*) ,function))

;;;
(defun PLACE-MONITOR (function-place)
  "Return the monitor function for FUNCTION-PLACE."
  (gethash function-place *monitor*))
(defsetf PLACE-MONITOR (function-place) (function)
  `(setf (gethash ,function-place *monitor*) ,function))

;;;
(defun MONITOR-CALLS (function-place)
  "Return the number of times FUNCTION-PLACE was called."
  (gethash function-place *monitor-calls*))
  
;;;
(defun MONITOR-TIME (function-place)
  "Return the total amount of unmonitored time spent executing
FUNCTION-PLACE."
  (when (gethash function-place *monitor-time*)
    (- (gethash function-place *monitor-time*)
       (* (monitor-calls function-place) *monitor-overhead*))))

;;;
(defun MONITORED (function-place)
  "Test to see if a FUNCTION-PLACE is monitored."
  (and (place-fboundp function-place)
       (eq (place-function function-place)
	   (place-monitor function-place))))

;;;
(defun MONITOR (&optional (function-place nil))
  "Monitor the function bound to FUNCTION-PLACE and return the currently
monitored functions."
  (unless (or (not (place-fboundp function-place))
	      (monitored function-place)
	      (place-macrop function-place))
    (let* ((function (place-function function-place))
	   (monitor
	    #'(lambda (&rest args)
		(let ((previous-total *total-time*)
		      (start (get-internal-run-time)))
		  (unwind-protect
		       (apply function args)
		    (let ((total (+ previous-total 
				    (- (get-internal-run-time) start))))
		      (incf (gethash function-place *monitor-time*)
			    (- total *total-time*))
		      (incf (gethash function-place *monitor-calls*))
		      (setq *total-time* total)))))))
      (setf (place-original function-place) function
	    (place-monitor function-place) monitor
	    ;; Make sure function can be called
	    (gethash function-place *monitor-time*) 0
	    (gethash function-place *monitor-calls*) 0
	    (place-function function-place) monitor)
      (push function-place *monitored*)))
  *monitored*)
		 
;;;
(defun MONITOR-ALL (&optional (package *package*))
  "Monitor all functions in the specified package."
  (let ((package (if (symbolp package)
		     (find-package package)
		     package)))
    (do-symbols (symbol package)
      (when (eq (symbol-package symbol) package)
	(monitor symbol)))))

;;;
(defun UNMONITOR (&optional (function-place nil))
  "Remove the monitoring on FUNCTION-PLACE, or all places if not specified."
  (if function-place
      (when (monitored function-place)
	(setf (place-function function-place) (place-original function-place))
	(remhash function-place *monitor-original*)
	(remhash function-place *monitor*)
	(remhash function-place *monitor-calls*)
	(remhash function-place *monitor-time*)
	(setq *monitored* (delete function-place *monitored* :test #'equal)))
      (dolist (function-place *monitored*)
	(unmonitor function-place))))

;;;
(defun START-MONITORING ()
  "Start monitoring functions."
  (setq *total-time* 0)
  (dolist (symbol *monitored*)
    (if (monitored symbol)
	(setf (gethash symbol *monitor-time*) 0
	      (gethash symbol *monitor-calls*) 0)
	(progn
	  (remhash symbol *monitor-time*)
	  (remhash symbol *monitor-calls*)
	  (format *trace-output* 
		  "~&Warning: ~S is no longer monitored." symbol)
	  (setq *monitored* (remove symbol *monitored*))))))

;;;
(defun STUB-FUNCTION ()
  )

;;;
(defun SET-MONITOR-OVERHEAD ()
  (setq *monitor-overhead* 0)
  (monitor 'stub-function)
  (start-monitoring)
  (dotimes (x 100)
    (stub-function))
  (setq *monitor-overhead* 
	(/ (monitor-time 'stub-function) 100.0)))
(set-monitor-overhead)

;;;
(defun REPORT-MONITORING (&optional (threshold 0.01))
  "Report the current monitoring state.
The percentage of the total time spent executing unmonitored code
in each function will be printed together with the number of calls and
the unmonitored time per call.  Functions that have been executed
below THRESHOLD % of the time will not be reported."
  (let ((total-time 0))
    (maphash 
     #'(lambda (symbol time)
	 (declare (ignore symbol))
	 (incf total-time time))
     *monitor-time*)
    (if (zerop total-time)
	(format *trace-output* "Not enough execution time to monitor.")
	(let ((results nil)
	      (max-length 8))			;Function header size
	  (maphash
	   #'(lambda (symbol value)
	       (declare (ignore value))
	       (let ((time (float (monitor-time symbol)))
		     (calls (monitor-calls symbol)))
		 (when (and (not (zerop time))
			    (or (zerop threshold)
				(> (/ time total-time) threshold)))
		   (push (list (format nil "~S" symbol)
			       (/ time total-time)
			       calls
			       (/ (/ time calls) 
				  internal-time-units-per-second))
			 results))))
	   *monitor-time*)
	  (setq results (sort results #'> :key #'second))
	  (dolist (result results)
	    (setq max-length (max max-length (length (first result)))))
	  (incf max-length 2)
	  (format *trace-output* "~&Function~VTPercent    Calls    Seconds"
		  max-length)
	  (dolist (result results)
	    (let* ((function (first result))
		   (total (second result))
		   (calls (third result))
		   (time (fourth result)))
	      (format *trace-output* "~&~A: ~VT   ~,2F ~8D    ~7F"
		      function max-length total calls time)))))))

;;;
(defmacro MONITOR-FORM (form &optional (threshold 0.01))
  "Monitor the execution of all functions in the current package
during the execution of FORM.  All functions that are executed above
THRESHOLD % will be reported."
  `(unwind-protect
	(progn
	  (monitor-all)
	  (start-monitoring)
	  (time ,form)
	  (report-monitoring ,threshold))
     (unmonitor)))
  

;--
;Chris McConnell
;
;Festina Lente.  (Make haste slowly.) --Julius Caesar
;