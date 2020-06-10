;;;
;;; based on euslib/jsk/unittest.l by R.Ueda
;;;

(load "lib/llib/time.l")
(defmethod interval-time
  (:elapsed (tint)
     (let ((sub (send self :subtract tint)))
       (+ (float (send sub :second)) (* 0.000001 (send sub :micro))))))

(defvar *unit-test* nil)

(defun escape-xml-string (str1)
  (let* ((str2 (make-string (+ (length str1)
			       (* (count #\< str1) 3)
			       (* (count #\> str1) 3)
			       (* (count #\& str1) 4)))))
    (do ((i1 0 (1+ i1))
	 (i2 0 (1+ i2)))
	((>= i1 (length str1)))
      (cond ((eq (elt str1 i1) #\<)
	     (setf (elt str2 i2) #\&) (incf i2)
	     (setf (elt str2 i2) #\l) (incf i2)
	     (setf (elt str2 i2) #\t) (incf i2)
	     (setf (elt str2 i2) #\;))
	    ((eq (elt str1 i1) #\>)
	     (setf (elt str2 i2) #\&) (incf i2)
	     (setf (elt str2 i2) #\g) (incf i2)
	     (setf (elt str2 i2) #\t) (incf i2)
	     (setf (elt str2 i2) #\;))
	    ((eq (elt str1 i1) #\&)
	     (setf (elt str2 i2) #\&) (incf i2)
	     (setf (elt str2 i2) #\a) (incf i2)
	     (setf (elt str2 i2) #\m) (incf i2)
	     (setf (elt str2 i2) #\p) (incf i2)
	     (setf (elt str2 i2) #\;))
	    ((eq (elt str1 i1) 27)
	     (setf (elt str2 i2) #\^))
	    (t
	     (setf (elt str2 i2) (elt str1 i1))))
      )
    str2))


(defclass unit-test-result
  :super propertied-object
  :slots (name tests failures time))
(defmethod unit-test-result
  (:init (n) (setq name n tests nil failures nil time 0))
  (:tests () tests)
  (:num-tests () (length tests))
  (:num-failures () (if failures 1 0))
  (:num-successes () (- (send self :num-tests) (send self :num-failures)))
  (:time () time)
  (:prin1
   (strm)
   (format strm "RESULT: ~A~%" name)
   (format strm "  TEST-NUM: ~A~%" (send self :num-tests))
   (format strm "    PASSED:   ~A~%" (send self :num-successes))
   (if (> (send self :num-failures) 0)
       (format strm "~C[3~Cm" #x1b 49))
   (format strm "    FAILURE:  ~A" (send self :num-failures))
   (if (> (send self :num-failures) 0)
       (format strm "~C[0m~%" #x1b)
     (format strm "~%"))
   )
  (:prin1-xml
   (strm)
   (format strm "  <testcase name=\"~s\" status=~s time=\"~d\" classname=\"~s\">~%" name "run" time name)
   (dolist (ret failures)
     (let ((type (send (class ret) :name))
           test msg)
     (cond
       ((derivedp ret error)
        (setq test (prin1-to-string (send ret :form)))
        (setq msg (send ret :message)))
       ((derivedp ret unix::signal-received)
        (setq test "")
        (setq msg (format nil "signal-handler ~A" (send ret :sig)))))
     (format strm "   <failure message=~S type=\"~A\">~%"
             (escape-xml-string msg)
             (escape-xml-string (prin1-to-string type)))
     (format strm "Test:~A~%" (escape-xml-string test))
     ;; (format strm "Trace:~A~%" (escape-xml-string (prin1-to-string trace)))
     (format strm "Message:~A~%" (escape-xml-string (prin1-to-string msg)))
     (format strm "   </failure>~%")))
   (format strm "  </testcase>~%")
   )
  )

(defclass unit-test-container
  :super propertied-object
  :slots (result functions log-fname output-mode))

(defmethod unit-test-container
  (:init
   (&key ((:log-fname fname)))
   (setq result nil)
   (setq functions nil)
   (setq log-fname fname)
   (when log-fname
     (warning-message 3 "output to ~A~%" log-fname)
     (setq output-mode :xml))
   self)
  (:functions () (reverse functions))
  (:result () result)
  ;;
  (:add-function (name) (push name functions))
  (:increment-test
   (test)
   (if result (push test (unit-test-result-tests (car result)))))
  (:increment-failure
   (failure)
   (if result (push failure (unit-test-result-failures (car result))))
   (cond
     ((derivedp failure error)
      (format *error-output* "~C[3~Cm[ERROR] test ~A failed" #x1b 49 (send failure :form))
      (format *error-output* " ... (~A)" (send failure :message))
      (format *error-output* ".~C[0m~%" #x1b))
     ((derivedp failure unix::signal-received)
      (format *error-output* "~C[3~Cm[ERROR] test interrupted with signal ~A" #x1b 49
              (send failure :sig))
      (format *error-output* " ... (~A)" (send (class failure) :name))
      (format *error-output* ".~C[0m~%" #x1b))))
  (:abort
   ()
   (warning-message 1 "exitting...~%")
   (send *unit-test* :print-result :if-exists :overwrite)
   (exit 1))
  (:maybe-abort
   ()
   (when lisp::*exit-on-fatal-error* (send self :abort)))
  (:set-time-to-current-result
   (time) ;; msec
   (if result (setf (unit-test-result-time (car result)) (round time))))
  (:init-result
   (func-sym)
   (push (instance unit-test-result :init func-sym) result))
  (:clear-result ()
   (setq result nil)
   ;(send self :init-result 'all-test)
   ;(send self :increment-test 'all-test)
   )
  ;;
  (:print-xml-result
   (&optional (strm t))
   (let ((all-tests (apply #'+ (send-all result :num-tests)))
         (all-failures (apply #'+ (send-all result :num-failures)))
         (all-times (apply #'+ (send-all result :time))))
     (format strm "<testsuite tests=\"~d\" failures=\"~d\" disabled=\"~d\" errors=\"~d\" time=\"~d\" name=\"AllTests\">~%" all-tests all-failures 0 0 all-times)
     (dolist (r (reverse result)) (send r :prin1-xml strm))
     (format strm "</testsuite>~%")
     ))
  (:print-normal-result
   (&optional (strm t))
   (let ((all-tests (apply #'+ (send-all result :num-tests)))
         (all-successes (apply #'+ (send-all result :num-successes)))
         (all-failures (apply #'+ (send-all result :num-failures))))
     (format strm "ALL RESULTS:~%")
     (format strm "  TEST-NUM: ~A~%" all-tests)
     (format strm "    PASSED:   ~A~%" all-successes)
     (if (> all-failures 0)
         (format strm "~C[3~Cm" #x1b 49))
     (format strm "    FAILURE:  ~A~%" all-failures)
     (if (> all-failures 0)
         (format strm "~C[0m" #x1b))
     (dolist (r (reverse result)) (prin1 r strm))
     ))
  (:print-result
   (&key (if-exists :append))
   (send self :print-normal-result)
   (when (and result (eq output-mode :xml))
     (let ((strm (open log-fname :direction :output
		       :if-exists if-exists
		       :if-does-not-exist :create)))
       (send self :print-xml-result strm)
       (close strm))))
  )

(defmacro deftest (name &rest body)
  `(progn
     (defun ,name ()
       (warning-message 2 "start testing [~A]~%" ',name)
       (handler-case
           (progn ,@body)
         (assertion-error (err)
           (send *unit-test* :increment-failure err))
         (error (err)
           (when (send err :callstack)
             (lisp::print-callstack (send err :callstack) lisp::*max-callstack-depth*))
           (lisp::print-error-message err)

           (send *unit-test* :increment-failure err)
           (send *unit-test* :maybe-abort))
         (unix::sigint-received (c)
           (send *unit-test* :increment-failure c)
           (send *unit-test* :abort))
         (unix::sighup-received (c)
           (send *unit-test* :increment-failure c)
           (send *unit-test* :abort))))

     (send *unit-test* :add-function ',name)
     ',name))

(defun run-test (func-sym)
  (let ((func (symbol-function func-sym)) tm)
    ;; initilize result
    (send *unit-test* :init-result func-sym)
    (format t "TEST-NAME: ~A~%" func-sym)
    (format t "  now testing...~%")
    (send *unit-test* :increment-test func-sym)
    (setq tm (now))
    (funcall func)
    (send *unit-test* :set-time-to-current-result (send (now) :elapsed tm))))

(defun run-all-tests ()
  ;; initalize *unit-test-result*
  (send *unit-test* :clear-result)
  (dolist (u (send *unit-test* :functions))
    (run-test u))
  (send *unit-test* :print-result)
  ;; exit with error status (1), if there are any failure in tests.
  (dolist (r (send *unit-test* :result))
    (if (/= (send r :num-failures) 0)
        (exit 1)))
  t)

(defun init-unit-test (&key log-fname trace)
  (let* ((p "--gtest_output=xml:")
         (s (find-if #'(lambda (tmpx) (substringp p tmpx)) lisp::*eustop-argument*))
         (xml-fname (if s (string-left-trim p s))))
    (if xml-fname (setq log-fname xml-fname))

    (setq lisp::*exit-on-fatal-error* t)
    (unix:install-signal-handler unix::sighup unix::sighup-received)

    (setq *unit-test* (instance unit-test-container :init :log-fname log-fname))

    (when trace
      (setf (symbol-function 'defun-org) (symbol-function 'defun))
      (defmacro defun (name args &rest body)
        `(prog1
           (defun-org ,name ,args ,@body)
           (trace ,name))))
    t))

(provide :unittest)
