(unless (find-package "LOG")
  (make-package "LOG"))
(in-package "LOG")

(export '(set-logger-level log-debug log-info log-warn log-error log-fatal))

;; Condition instance for logger messages
(defcondition logger-message :slots (lvl args))

;; Logger level related
(defconstant logger-table
  '((:debug . 1) (:info . 2) (:warn . 3) (:error . 4) (:fatal . 5)))

(defun get-level (lvl)
  (cond
    ((cdr (assoc lvl logger-table)))
    (t (error value-error "no such level ~A" lvl))))

(defun get-level-name (lvl)
  (cond
    ((car (rassoc lvl logger-table)))
    (t (error value-error "no such level ~A" lvl))))

(defvar *logger-level* (get-level :info))

(defun set-logger-level (lvl)
  (setq *logger-level* (get-level lvl)))


;; Utility
(defmacro level-belongs (lvl &rest options)
  `(or ,@(mapcar #'(lambda (val) `(= ,lvl (get-level ,val))) options)))

(defmacro with-slots (slots instance &rest body)
  (let ((inst-val (gensym)))
    `(let* ((,inst-val ,instance) ;; evaluate instance only once
            ,@(mapcar #'(lambda (s)
                          (if (consp s)
                              `(,(car s) (send ,inst-val :get-val ',(cadr s)))
                              `(,s (send ,inst-val :get-val ',s))))
                      slots))
       ,@body)))

(defun format-log-message (log)
  (with-slots (msg lvl args) log
    (format nil "[~A] ~A"
            (symbol-pname (get-level-name lvl))
            (apply #'format nil msg args))))


;; Loggers signalers
(defun log-debug (msg &rest format-args)
  (signals logger-message :msg msg :lvl (get-level :debug) :args format-args))
(defun log-info (msg &rest format-args)
  (signals logger-message :msg msg :lvl (get-level :info) :args format-args))
(defun log-warn (msg &rest format-args)
  (signals logger-message :msg msg :lvl (get-level :warn) :args format-args))
(defun log-error (msg &rest format-args)
  (signals logger-message :msg msg :lvl (get-level :error) :args format-args))
(defun log-fatal (msg &rest format-args)
  (signals logger-message :msg msg :lvl (get-level :fatal) :args format-args))


;; Printing callback
(defun logger-callback (log)
  (when (>= (send log :get-val 'lvl) *logger-level*)
    (let ((lvl (send log :get-val 'lvl))
          (msg (format-log-message log)))
      (cond
        ((level-belongs lvl :debug :info)
         (princ msg *standard-output*)
         (terpri *standard-output*))
        ((level-belongs lvl :warn)
         (warning-message 3 msg)
         (terpri *error-output*))
        ((level-belongs lvl :error :fatal)
         (warning-message 1 msg)
         (terpri *error-output*))))))

(unless (assoc logger-message lisp::*condition-handler*)
  (install-handler logger-message #'logger-callback))
