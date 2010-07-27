(defclass asynchronous-object-class
  :super metaclass
  :slots (async-methods))

(defclass asynchronous-object
  :super object
  :slots (main-thread sub-threads entrance-lock lock-of-slots)
  :metaclass asynchronous-object-class)

(remprop 'send 'compiler::builtin-function-entry)
(defun send (object selector &rest args)
  (let ((class (class object)))
    (if (subclassp (class class) asynchronous-object-class)
      (if (send-msg class :asyncp selector)
	(let ((lock-of-slots (object . lock-of-slots)))
	  (sys:mutex-lock lock-of-slots)
	  (let ((result (not (object . main-thread))))
	    (if result
	      (sys:thread-no-wait #'apply #'send-msg object selector args))
	    (sys:mutex-unlock lock-of-slots)
	    result))
	(let (result)
	  (send-msg object :enter)
	  (setq result (apply #'send-msg object selector args))
	  (send-msg object :exit)
	  result))
      (apply #'send-msg object selector args))))

(defmethod asynchronous-object-class
  (:asyncp (selector)
    (member selector async-methods))

  (:add-async-method (selector)
    (if (not (member selector async-methods))
      (setq async-methods (cons selector async-methods)))))

(defmethod asynchronous-object
  (:init ()
    (setq entrance-lock (sys:make-mutex-lock))
    (setq lock-of-slots (sys:make-mutex-lock)))

  (:enter ()
    (let ((thr (unix:thr-self)))
      (unless (or (null main-thread) (eql thr main-thread))
	(sys:mutex-lock lock-of-slots)
	(unless (member thr sub-threads)
	  (sys:mutex-lock entrance-lock)
	  (push thr sub-threads)
	  (sys:mutex-unlock entrance-lock))
	(sys:mutex-unlock lock-of-slots))))

  (:exit ()
    (let ((thr (unix:thr-self)))
      (unless (or (null main-thread) (eql thr main-thread))
	(sys:mutex-lock lock-of-slots)
	(setq sub-threads (remove thr sub-threads :count 1))
	(sys:mutex-unlock lock-of-slots))))

  (:lock-slots ()
    (if (not (eql (unix:thr-self) main-thread))
      (error "not the main thread"))
    (sys:mutex-lock lock-of-slots)
    (when (sys:mutex-trylock entrance-lock)
      (dolist (thr sub-threads)
	(unix:thr-suspend thr)))
    (sys:mutex-unlock lock-of-slots))

  (:unlock-slots ()
    (if (not (eql (unix:thr-self) main-thread))
      (error "not the main thread"))
    (sys:mutex-lock lock-of-slots)
    (dolist (thr sub-threads)
      (unix:thr-continue thr))
    (sys:mutex-unlock entrance-lock)
    (sys:mutex-unlock lock-of-slots)))

(defmacro def-async-method (class-name &rest methods)
  (let ((class (symbol-value class-name)))
    (if (not (subclassp class asynchronous-object))
      (error "not a class of asynchronous object"))
    (dolist (method methods)
      (send-msg class :add-async-method (car method)))
    `(defmethod ,class-name
      ,@(mapcar #'(lambda (method)
        (let ((selector (car method))
	      (args (cadr method))
	      (body (cddr method)))
	  `(,selector ,args
	    (sys:mutex-lock lock-of-slots)
	    (setq main-thread (unix:thr-self))
	    (sys:mutex-lock entrance-lock)
	    (sys:mutex-unlock lock-of-slots)
	    ,@body
	    (sys:mutex-lock lock-of-slots)
	    (setq main-thread nil)
	    (sys:mutex-unlock entrance-lock)
	    (sys:mutex-unlock lock-of-slots))))
        `,methods))))

(defmacro lock-slots ()
  '(send-msg self :lock-slots))

(defmacro unlock-slots ()
  '(send-msg self :unlock-slots))


