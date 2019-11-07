(eval-when (load eval)

(in-package "LISP")

(export '(defcondition install-handler remove-handler signals euserror
          sigint-handler interruption handler-bind handler-case))

(defvar *current-condition*)

(defmethod condition
  (:init (&rest init-args &key message &allow-other-keys)
    ;; Initialize slots
    (do* ((key (pop init-args) (pop init-args))
          (val (pop init-args) (pop init-args)))
         ((null key))
      (send self :set-val (symbol-pname key) val))
    self)
  (:message (&optional (val nil supplied-p)) (if supplied-p (setq message val) message)))

(defmethod error
  (:callstack (&optional val) (if val (setq callstack val) callstack))
  (:form (&optional val) (if val (setq form val) form)))

(defmacro defcondition (name &key slots (super 'condition))
  `(progn
     (defclass ,name :slots ,slots :super ,super)
     (defmethod ,name
         (:init (&rest init-args) (send-super* :init init-args))
         ,@(mapcar #'(lambda (s) `(,(intern (send s :pname) *keyword-package*) (&optional (val nil supplied-p))
                                    (if supplied-p (send self :set-val ',s val) ,s)))
                   slots))))

(defun install-handler (label handler)
  ;; ensure condition class
  (unless (and (classp label) (derivedp (instantiate label) condition))
    (error type-error "condition class expected"))
  ;; ensure function
  (unless (functionp handler)
    (error type-error "function expected"))
  ;; ensure global scope
  (when (and (consp handler) (eql (car handler) 'lambda-closure))
    (setq handler `(lambda-closure ,(second handler) 0 0 ,@(nthcdr 4 handler))))
  (unless (functionp handler) type-error "function expected")
  (push (cons label handler) *condition-handler*)
  t)

(defun remove-handler (label &optional handler)
  (setq *condition-handler*
        (if handler
            (remove (cons label handler) *condition-handler* :test #'equal :count 1)
            (remove label *condition-handler* :key #'car :count 1))))

(defmacro handler-bind (bindings &rest forms)
  `(let ((*condition-handler* (copy-list *condition-handler*)))
     ,@(mapcar #'(lambda (bind) `(install-handler ,@bind)) bindings)
     ,@forms))

(defmacro handler-case (form &rest cases)
  (flet ((expand-case (tag arglst &rest body)
           (unless (or (null arglst) (and (consp arglst) (null (cdr arglst))))
             (error argument-error "expected single parameter list"))
           `(,tag #'(lambda ,(if arglst arglst (list (gensym)))
                      ;; ignore?
                      (throw :handler-case
                        (progn ,@body))))))
    `(catch :handler-case
       (handler-bind
           ,(mapcar #'(lambda (cs) (apply #'expand-case cs)) cases)
         ,form))))

(defun signals (obj &rest init-args)
  (if (classp obj) (setq obj (instantiate obj)))
  (if init-args (send* obj :init init-args))
  (unless (derivedp obj condition) (error type-error "condition class expected"))
  (dolist (handle *condition-handler*)
    (when (derivedp obj (car handle))
      ;; remove ongoing handler to avoid nested evaluation
      (let ((*current-condition* obj)
            (*condition-handler* (remove handle *condition-handler* :test #'equal :count 1)))
        (return-from signals (funcall (cdr handle) obj))))))

(defun print-callstack (&optional (stack (sys:list-callstack)) max (os *error-output*))
  (let ((tms (if max
                 (min max (length stack))
                 (length stack))))
    (when (plusp tms)
      (format os "Call Stack~A:~%" (if max (format nil " (max depth ~A)" max) ""))
      (dotimes (i tms)
        (format os "~3D: at ~S~%" i (nth i stack))))))

(defun print-error-message (err &optional (os *error-output*))
  (unless (derivedp err condition) (error type-error "condition class expected"))
  (when (send err :message)
      (format os "~C[1;3~Cm~A~C[0m: ~A"
              #x1b (+ 1 48) (string-upcase (metaclass-name (class err))) #x1b (send err :message))
      (if (and (derivedp err error) (send err :form))
          (format os " in ~S" (send err :form)))
      (terpri os)))


;;;
;;; error handling
;;;

(defun euserror (err)
  (when (send err :callstack)
    (print-callstack (send err :callstack) *max-callstack-depth*))
  (print-error-message err)
  (let ((*replevel* (1+ *replevel*))
        (*reptype* "E"))
    ;; do not carry handlers through the error stack
    ;; i.e. restore previous global `*condition-handler*'
    (let ((old (assoc '*condition-handler* (sys:list-all-special-bindings))))
      (if old (setq *condition-handler* (cdr old))))
    (while (catch *replevel* (reploop #'toplevel-prompt))))
  (throw *replevel* t))


;;;
;;; unix:signal handling
;;;

(defcondition unix::signal-received)
(defmacro unix::install-signal-handler (sig obj &rest init-args)
  (let ((fname (intern (format nil "~A-SIGNALIZE-CONDITION" (symbol-pname sig)) *unix-package*)))
    `(progn
       (unless (boundp ',obj)
         (defcondition ,obj :super unix::signal-received))
       (defun ,fname (sig code) (signals ,obj ,@init-args))
       (unix:signal ,sig ',fname))))

(defmacro unix::with-alarm-interrupt (&rest body)
  (let ((interval (gensym)) (value (gensym)))
    `(multiple-value-bind ,(list interval value) (unix:setitimer 0 0 0)
       ,@body
       (unix:setitimer 0 ,value ,interval))))

(defcondition interruption)
(defun sigint-handler (c)
  (unix::with-alarm-interrupt
    (signals interruption :message "keyboard interrupt")))

(defun interruption-handler (c)
  (print-error-message c)
  (let* ((*replevel* (1+ *replevel*))
         (*reptype* "B"))
    (while (catch *replevel* (reploop #'toplevel-prompt)))))

(install-handler interruption 'interruption-handler)

;; install handlers
(unix:install-signal-handler unix::sigint unix::sigint-received)
(unix:install-signal-handler unix::sigcont unix::sigcont-received))
(install-handler error #'euserror)
(install-handler unix::sigint-received 'sigint-handler)
(install-handler unix::sigcont-received
  '(lambda-closure nil 0 0 (c)
     (when (memq *replevel* (sys::list-all-catchers))
       (reset *replevel*))))
;; in order to remain in the same stack, reset command must not be compiled
;; TODO: find out why this happens
)
