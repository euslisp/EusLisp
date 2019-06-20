(eval-when(load eval)

(in-package "LISP")

(export '(handler-bind handler-case signals continue next-handler))

(defmethod condition
  (:init (&rest init-args &key &allow-other-keys)
    (while init-args
      (let* ((name (pop init-args))
             (value (pop init-args)))
        (setf (get self name) value)))
    self))

(defun add-handler (label callback)
  (assert (and (classp label) (derivedp (instantiate label) condition))
          "Condition class expected!")
  (assert (functionp callback) "Function expected!")
  (push (cons label callback) *condition-handler*))

(defmacro handler-bind (bindings &rest forms)
  `(let ((*condition-handler* (copy-list *condition-handler*)))
     ,@(mapcar #'(lambda (bind) `(add-handler ,@bind)) (reverse bindings))
     ,@forms))

(defmacro handler-case (form &rest cases)
  (flet ((expand-case (tag arglst &rest body)
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
  (assert (derivedp obj condition) "Condition class expected!")
  (block signals
    (dolist (handle *condition-handler*)
      (when (derivedp obj (car handle))
        (catch :next-handler
          (return-from signals (funcall (cdr handle) obj)))))))

(defun myerror (err)
  (when (and (plusp *max-callstack-depth*) (get err :callstack))
    (format *error-output* "Call Stack (most recent call last):~%")
    (let ((i 0))
      (dolist (form
                (nthcdr (max 0 (- (length (get err :callstack)) *max-callstack-depth*))
                        (get err :callstack)))
        (format *error-output* "~3D: at ~A~%" (incf i) form))))

  (if (get err :msg)
      (format *error-output* "~C[1;3~Cm~A~C[0m: ~A~%"
              #x1b (+ 1 48) (string-upcase (metaclass-name (class err))) #x1b (get err :msg))
      (format *error-output* "~C[1;3~Cm~A~C[0m~%"
              #x1b (+ 1 48) (string-upcase (metaclass-name (class err))) #x1b))
  (catch (- (1+ *replevel*))
    (let ((*replevel* (1+ *replevel*))
          (*reptype* "E"))
      ;; do not carry handlers through the error stack
      ;; i.e. restore previous global `*condition-handler*'
      (let ((old (assoc '*condition-handler* (sys:list-all-special-bindings))))
        (if old (setq *condition-handler* (cdr old))))
      (while (catch *replevel* (reploop #'toplevel-prompt))))
    (throw *replevel* t)))

(defun continue (val) (throw (- *replevel*) val))
(defun next-handler () (throw :next-handler nil))

(add-handler error #'myerror)
)
