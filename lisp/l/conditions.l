(eval-when(load eval)

(in-package "LISP")

(export '(install-handler remove-handler signals euserror
          handler-bind handler-case next-handler))

(defmethod condition
  (:init (&rest init-args &key &allow-other-keys)
    (while init-args
      (let* ((name (pop init-args))
             (value (pop init-args)))
        (setf (get self name) value)))
    self))

(defun install-handler (label handler)
  (assert (and (classp label) (derivedp (instantiate label) condition))
          "condition class expected")
  (assert (functionp handler) "function expected")
  (push (cons label handler) *condition-handler*))

(defun remove-handler (label &optional handler)
  (setq *condition-handler*
        (if handler
            (remove (cons label handler) *condition-handler* :test #'equal :count 1)
            (remove label *condition-handler* :key #'car :count 1))))

(defmacro handler-bind (bindings &rest forms)
  `(let ((*condition-handler* (copy-list *condition-handler*)))
     ,@(mapcar #'(lambda (bind) `(install-handler ,@bind)) (reverse bindings))
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
  (assert (derivedp obj condition) "condition class expected")
  (block signals
    (dolist (handle *condition-handler*)
      (when (derivedp obj (car handle))
        (catch :next-handler
          (return-from signals (funcall (cdr handle) obj)))))))

(defun print-callstack (stack &optional max (os *error-output*))
  (let ((tms (if max
                 (min max (length stack))
                 (length stack))))
    (when (plusp tms)
      (format os "Call Stack~A:~%" (if max (format nil " (max depth ~A)" max) ""))
      (dotimes (i tms)
        (format os "~3D: at ~A~%" i (nth i stack))))))

(defun print-error-msg (err &optional (os *error-output*))
  (when (get err :msg)
      (format os "~C[1;3~Cm~A~C[0m: ~A"
              #x1b (+ 1 48) (string-upcase (metaclass-name (class err))) #x1b (get err :msg))
      (if (get err :form) (format os " in ~S" (get err :form)))
      (terpri os)))

(defun euserror (err)
  (print-callstack (get err :callstack) *max-callstack-depth*)
  (print-error-msg err)
  (let ((*replevel* (1+ *replevel*))
        (*reptype* "E"))
    ;; do not carry handlers through the error stack
    ;; i.e. restore previous global `*condition-handler*'
    (let ((old (assoc '*condition-handler* (sys:list-all-special-bindings))))
      (if old (setq *condition-handler* (cdr old))))
    (while (catch *replevel* (reploop #'toplevel-prompt))))
  (throw *replevel* t))

(defun next-handler () (throw :next-handler nil))
(install-handler error #'euserror)
)
