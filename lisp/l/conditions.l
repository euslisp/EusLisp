(eval-when (load eval)

(in-package "LISP")

(export '(defcondition install-handler remove-handler invoke-next-handler signals
          assertion-error euserror sigint-handler interruption handler-bind handler-case))

(deflocal *condition-handler*)
(defvar *current-condition-handler*)

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

(defclass condition-handler :slots (fn) :super propertied-object)
(defmethod condition-handler
  (:init (fn)
    (unless (functionp fn) (error type-error "function expected"))
    ;; set slots
    (send self :set-val "FN" fn)
    ;; set name
    (let ((name
           (cond
             ((symbolp fn) fn)
             ((compiled-function-p fn) (get fn :name))
             ((listp fn) (second fn)))))
      (if name (setf (get self :name) name)))
    self)
  (:function (&optional val) (if val (setq fn val) fn)))

(defmacro defcondition (name &key slots (super 'condition))
  `(progn
     (defclass ,name :slots ,slots :super ,super)
     (defmethod ,name
         (:init (&rest init-args) (send-super* :init init-args))
         ,@(mapcar #'(lambda (s) `(,(intern (send s :pname) *keyword-package*) (&optional (val nil supplied-p))
                                    (if supplied-p (send self :set-val ',s val) ,s)))
                   slots))))

(defun install-handler-raw (label handler)
  ;; ensure condition class
  (unless (and (classp label) (derivedp (instantiate label) condition))
    (error type-error "condition class expected"))
  (push (cons label (instance condition-handler :init handler))
        *condition-handler*)
  t)

(defun install-handler (label handler)
  ;; ensure global scope
  (when (and (consp handler) (eql (car handler) 'lambda-closure))
    (setq handler `(lambda-closure ,(second handler) 0 0 ,@(nthcdr 4 handler))))
  (install-handler-raw label handler))

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
     ,@(mapcar #'(lambda (bind) `(install-handler-raw ,@bind)) bindings)
     ,@forms))

(defun get-handler-frame (&optional (name "HANDLER-CASE-"))
  (let ((handler-frame (symbol-pname (gensym name))))
    (while (find-symbol handler-frame *keyword-package*)
      (setq handler-frame (symbol-pname (gensym name))))
    (intern handler-frame *keyword-package*)))

(defmacro handler-case (form &rest cases)
  (let ((handler-frame (get-handler-frame)))
    (flet ((expand-case (tag arglst &rest body)
             (unless (or (null arglst) (and (consp arglst) (null (cdr arglst))))
               (error argument-error "expected single parameter list"))
             `(,tag #'(lambda ,(if arglst arglst (list (gensym)))
                        ;; ignore?
                        (throw ,handler-frame
                          (progn ,@body))))))
      `(prog1
           (catch ,handler-frame
             (handler-bind
                 ,(mapcar #'(lambda (cs) (apply #'expand-case cs)) (reverse cases))
               ,form))
         (send *keyword-package* :unintern ,handler-frame)))))

(defun invoke-next-handler (obj)
  (unless (derivedp obj condition)
    (error type-error "condition class expected"))
  (dolist (handle *current-condition-handler*)
    (when (derivedp obj (car handle))
      ;; call handler
      (let ((*current-condition-handler*
             (remove handle *current-condition-handler* :test #'equal :count 1)))
        (return-from invoke-next-handler (funcall (send (cdr handle) :function) obj))))))

(defun signals (obj &rest init-args)
  (when (classp obj)
    (setq obj (instantiate obj))
    (send* obj :init init-args))
  ;; init-args is not used if instantiated objects are given
  (unless (derivedp obj condition) (error type-error "condition class expected"))
  (dolist (handle *condition-handler*)
    (when (derivedp obj (car handle))
      ;; call handler
      (let ((*current-condition-handler*
             (if *current-condition-handler*
                 (remove handle *current-condition-handler* :test #'equal :count 1)
                 (remove handle (copy-list *condition-handler*) :test #'equal :count 1))))
        (return-from signals (funcall (send (cdr handle) :function) obj))))))

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
;;; assertion error
;;;

(defcondition assertion-error :super error)


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

(defcondition unix::signal-received :slots (sig code))
(defmacro unix::install-signal-handler (sig obj &rest init-args)
  `(progn
     (defcondition ,obj :super unix::signal-received)
     (unix:signal ,sig
       ;; ensure global scope
       ',`(lambda-closure nil 0 0 (sig code) (signals ,obj :sig sig :code code ,@init-args)))))

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
(unix:install-signal-handler unix::sigcont unix::sigcont-received)
(install-handler unix::sigint-received 'sigint-handler)
(install-handler unix::sigcont-received
  '(lambda-closure nil 0 0 (c)
     (when (memq *replevel* (sys::list-all-catchers))
       (reset *replevel*))))
;; in order to remain in the same stack, reset command must not be compiled
;; TODO: find out why this happens
)
