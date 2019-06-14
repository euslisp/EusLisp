(eval-when(load eval)

(in-package "LISP")

(export '(condition error fatal-error handler-bind handler-case signals))

(defclass condition :super propertied-object)
(defclass error :super condition)
(defclass fatal-error :super error)

(defvar *condition-handlers* nil)

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
  (push (cons label callback) *condition-handlers*))

(defmacro handler-bind (bindings &rest forms)
  `(let ((*condition-handlers* (copy-list *condition-handlers*)))
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

(defun signals (class &rest init-args)
  (let* ((inst (instantiate class))
         (handle (assoc inst *condition-handlers* :test #'derivedp)))
    (if handle (funcall (cdr handle) (send* inst :init init-args)))))
)
