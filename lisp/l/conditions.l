(eval-when (load eval)

(in-package "LISP")

(export '(defcondition install-handler remove-handler invoke-next-handler signals
          euserror sigint-handler interruption handler-bind handler-case))

(deflocal *condition-handler*)
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
  (:init (&rest init-args &key (message "") (callstack (sys:list-callstack)) &allow-other-keys)
    (send-super* :init :message message :callstack callstack init-args))
  (:callstack (&optional val) (if val (setq callstack val) callstack))
  (:form (&optional val) (if val (setq form val) form)))

(defclass condition-handler :slots (fn recursive) :super propertied-object)
(defmethod condition-handler
  (:init (fn &key recursive)
    (unless (functionp fn) (error type-error "function expected"))
    ;; set slots
    (send self :set-val "FN" fn)
    (send self :set-val "RECURSIVE" recursive)
    ;; set name
    (let ((name
           (cond
             ((symbolp fn) fn)
             ((compiled-function-p fn) (get fn :name))
             ((listp fn) (second fn)))))
      (if name (setf (get self :name) name)))
    self)
  (:function (&optional val) (if val (setq fn val) fn))
  (:recursive (&optional (val nil supplied-p)) (if supplied-p (setq recursive val) recursive)))

(defmacro defcondition (name &key slots (super 'condition))
  `(progn
     (defclass ,name :slots ,slots :super ,super)
     (defmethod ,name
         (:init (&rest init-args) (send-super* :init init-args))
         ,@(mapcar #'(lambda (s) `(,(intern (send s :pname) *keyword-package*) (&optional (val nil supplied-p))
                                    (if supplied-p (send self :set-val ',s val) ,s)))
                   slots))))

(defun install-handler-raw (label handler &key recursive)
  ;; ensure condition class
  (unless (and (classp label) (derivedp (instantiate label) condition))
    (error type-error "condition class expected"))
  (push (cons label (instance condition-handler :init handler :recursive recursive))
        *condition-handler*)
  t)

(defun install-handler (label handler &key (recursive t))
  ;; ensure global scope
  (when (and (consp handler) (eql (car handler) 'lambda-closure))
    (setq handler `(lambda-closure ,(second handler) 0 0 ,@(nthcdr 4 handler))))
  (install-handler-raw label handler :recursive recursive))

(defun remove-handler (label &optional handler)
  (let ((item
         (if handler
             (find-if #'(lambda (val) (and (eql (car val) label)
                                           (derivedp (cdr val) condition-handler)
                                           (eql (send (cdr val) :function) handler)))
                      *condition-handler*)
             (find label *condition-handler* :key #'car))))
    (when item
      (setq *condition-handler*
            (remove item *condition-handler* :test #'equal :count 1))
      t)))

(defmacro handler-bind (bindings &rest forms)
  `(let ((*condition-handler* (copy-list *condition-handler*)))
     ,@(mapcar #'(lambda (bind) `(install-handler-raw ,@bind :recursive nil)) bindings)
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

(defun invoke-next-handler (obj &optional (skip 0))
  (unless (derivedp obj condition)
    (error type-error "condition class expected"))
  (unless (and (integerp skip) (not (minusp skip)))
    (error type-error "positive integer expected"))
  (dolist (handle *condition-handler*)
    (when (derivedp obj (car handle))
      (if (<= skip 0)
          ;; call handler
          (let ((*current-condition* obj)
                (*condition-handler* (copy-list *condition-handler*)))
            (if (send (cdr handle) :recursive)
                ;; recursive
                (return-from invoke-next-handler (funcall (send (cdr handle) :function) obj))
                ;; non-recursive: remove ongoing handler to avoid nested evaluation
                (let ((*condition-handler* (remove handle *condition-handler* :test #'equal :count 1)))
                  (return-from invoke-next-handler (funcall (send (cdr handle) :function) obj)))))
          ;; decrease skip count
          (decf skip)))))

(defun signals (obj &rest init-args)
  (when (classp obj)
    (setq obj (instantiate obj))
    (send* obj :init init-args))
  ;; init-args is not used if instantiated objects are given
  (unless (derivedp obj condition) (error type-error "condition class expected"))
  (invoke-next-handler obj))

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


;; install handlers
(install-handler error #'euserror)
(install-handler interruption 'interruption-handler)
(unix:install-signal-handler unix::sigint unix::sigint-received)
(unix:install-signal-handler unix::sigcont unix::sigcont-received))
(install-handler unix::sigint-received 'sigint-handler)
(install-handler unix::sigcont-received
  '(lambda-closure nil 0 0 (c)
     (when (memq *replevel* (sys::list-all-catchers))
       (reset *replevel*))))
;; in order to remain in the same stack, reset command must not be compiled
;; TODO: find out why this happens
)
