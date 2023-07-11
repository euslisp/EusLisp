;;;; Most tests are derived from Common Lisp ANSI compliance test suite
;;;; at https://common-lisp.net/project/ansi-test
;;;; 
;;;; Tests with features that are still not supported but hopefully eventually
;;;; will be are commented out
;;;;
;;;; 2020 by Guilherme de Campos Affonso
;;;;

;; TODO: add tests for `install-handler', `invoke-next-handler', and other eus-only functions


(require :unittest "lib/llib/unittest.l")

(init-unit-test :exit-on-error nil)

(defmacro define-ansi-test (name clause &rest res)
  `(deftest ,name
       (assert  ,(if (and (consp res) (not (cdr res))) ;; single element list
		     `(equal ,clause ',@res)
		     `(equal ,clause ',res)))))


(deftest defcondition.1
  (defcondition _condition.1)
  (let ((c (instantiate _condition.1)))
    (assert (derivedp c condition))
    (assert (derivedp c _condition.1))
    (assert (not (derivedp (instantiate condition) _condition.1)))
    (assert (eq (class c) _condition.1))))

(deftest defcondition.2
  (defcondition _condition.2 :slots (a b c))
  (let ((c (instantiate _condition.2)))
    (assert (memq :a (send c :methods)))
    (assert (memq :b (send c :methods)))
    (assert (memq :c (send c :methods)))
    (assert (memq 'a (coerce (send _condition.2 :slots) cons)))
    (assert (memq 'b (coerce (send _condition.2 :slots) cons)))
    (assert (memq 'c (coerce (send _condition.2 :slots) cons)))
    (assert (null (send c :get-val 'a)))
    (assert (null (send c :get-val 'b)))
    (assert (null (send c :get-val 'c)))))

(deftest defcondition.3
  (defcondition _condition.3.a :slots (a))
  (defcondition _condition.3.b :slots (b) :super _condition.3.a)
  (let ((ca (instantiate _condition.3.a))
        (cb (instantiate _condition.3.b)))
    (assert (derivedp cb _condition.3.a))
    (assert (not (derivedp ca _condition.3.b)))
    (assert (memq :a (send cb :methods)))
    (assert (memq :b (send cb :methods)))
    (assert (memq 'a (coerce (send _condition.3.b :slots) cons)))
    (assert (memq 'b (coerce (send _condition.3.b :slots) cons)))))

(deftest signals.1
  (assert (null (signals condition))))

(deftest signals.2
  (defcondition _condition.signals.2)
  (let ((c (instance _condition.signals.2 :init)))
    (assert (eq c
                (handler-case (signals c)
                  (_condition.signals.2 (c1) c1))))))

(deftest signals.3
  (defcondition _condition.signals.3)
  (assert (eql :ok
              (handler-case (signals _condition.signals.3)
                (_condition.signals.3 () :ok)))))

(deftest signals.4
  (defcondition _condition.signals.4 :slots (test))
  (assert (eql 'good
               (handler-case (signals _condition.signals.4 :test 'good)
                 (_condition.signals.4 (c) (send c :test))))))

(deftest signals.5
  (defcondition _condition.signals.5 :slots (val))
  (assert (eql :ok
               (handler-case
                   (handler-case
                     (signals _condition.signals.5 :val 3)
                     (_condition.signals.5 (c)
                       (decf (_condition.signals.5-val c))
                       (if (> (send c :val) 0)
                           (signals c)
                           :ok)))
                 (_condition.signals.5 (c) :not-ok)))))

(deftest invoke-next-handler.1
  (defcondition _condition.invoke-next-handler.1)
  (assert (null
           (handler-case (signals _condition.invoke-next-handler.1)
             (_condition.invoke-next-handler.1 (c)
               (invoke-next-handler c))))))

(deftest invoke-next-handler.2
  (defcondition _condition.invoke-next-handler.2)
  (assert (eql :ok
               (handler-bind ((_condition.invoke-next-handler.2 #'(lambda (c) :ok)))
                 (handler-case (signals _condition.invoke-next-handler.2)
                   (_condition.invoke-next-handler.2 (c)
                     (invoke-next-handler c)))))))

(deftest invoke-next-handler.3
  (defcondition _condition.invoke-next-handler.3)
  (assert (null (invoke-next-handler (instance _condition.invoke-next-handler.3))))
  (install-handler _condition.invoke-next-handler.3 #'(lambda (c) :ok))
  (assert (eql :ok (invoke-next-handler (instance _condition.invoke-next-handler.3))))
  (assert (remove-handler _condition.invoke-next-handler.3)))

(deftest install-handler.1
  (defcondition _condition.install-handler.1)
  (install-handler _condition.install-handler.1 #'(lambda (c) :ok))
  (assert (eql :ok (signals _condition.install-handler.1)))
  (assert (remove-handler _condition.install-handler.1)))

(deftest install-handler.2
  (defcondition _condition.install-handler.2)
  (install-handler _condition.install-handler.2 #'identity)
  (let ((c (instance _condition.install-handler.2 :init)))
    (assert (eq c (signals c))))
  (assert (remove-handler _condition.install-handler.2)))

(deftest install-handler.3
  (defcondition _condition.install-handler.3)
  (handler-bind ((_condition.install-handler.3 #'(lambda (c) :not-ok)))
    (assert (eql :not-ok (signals _condition.install-handler.3)))
    (install-handler _condition.install-handler.3 #'(lambda (c) :ok))
    (assert (eql :ok (signals _condition.install-handler.3))))
  (assert (remove-handler _condition.install-handler.3)))

(deftest remove-handler.1
  (defcondition _condition.remove-handler.1)
  (assert (not (remove-handler _condition.remove-handler.1))))

(deftest remove-handler.2
  (defcondition _condition.remove-handler.2)
  (install-handler _condition.remove-handler.2 #'identity)
  (assert (remove-handler _condition.remove-handler.2 #'identity))
  (assert (not (remove-handler _condition.remove-handler.2))))

(deftest remove-handler.3
  (defcondition _condition.remove-handler.3)
  (handler-bind ((_condition.remove-handler.3 #'identity))
      (assert (not (remove-handler _condition.remove-handler.3))))
  (assert (not (remove-handler _condition.remove-handler.3))))

(deftest remove-handler.4
  (defcondition _condition.remove-handler.4)
  (install-handler _condition.remove-handler.4 #'(lambda (c) (list 1 2 3)))
  (handler-bind ((_condition.remove-handler.4
                  #'(lambda (c) (cons 0 (invoke-next-handler c)))))
    (assert (equal (list 0 1 2 3) (signals _condition.remove-handler.4)))
    (assert (remove-handler _condition.remove-handler.4))
    (assert (equal (list 0) (signals _condition.remove-handler.4))))
  (assert (not (remove-handler _condition.remove-handler.4))))

;;;; adapted from ansi-test/tests/conditions/error.lsp
(defun frob-simple-condition (c expected-fmt &rest expected-args)
  "Check that condition message matches the expected formatting"
  (and (derivedp c condition)
       (string= (send c :message)
                (apply #'format nil expected-fmt expected-args))))

(defun frob-simple-error (c expected-fmt &rest expected-args)
  (and (derivedp c error)
       (apply #'frob-simple-condition c expected-fmt expected-args)))


(define-ansi-test error.1
  (let ((fmt "Error"))
    (handler-case
     (error fmt)
     (error (c) (frob-simple-error c fmt))))
  t)

(define-ansi-test error.2
  (let* ((fmt "Error")
         (cnd (instance error :init :message fmt)))
    (handler-case
     (signals cnd)
     (error (c) (frob-simple-error c fmt))))
  t)

(define-ansi-test error.3
  (let ((fmt "Error"))
    (handler-case
     (signals error :message fmt)
     (error (c) (frob-simple-error c fmt))))
  t)

(define-ansi-test error.4
  (let ((fmt "Error: ~A"))
    (handler-case
     (error fmt 10)
     (error (c) (frob-simple-error c fmt 10))))
  t)

(define-ansi-test error.6
  (handler-case
   (signals condition)
   (error (c) :wrong)
   (condition (c) :right))
  :right)


;;;; adapted from ansi-test/tests/conditions/handler-bind.lsp
(define-ansi-test handler-bind.1
  (handler-bind ())
  nil)

(define-ansi-test handler-bind.2
  (handler-bind () (values)))

(define-ansi-test handler-bind.3
  (handler-bind () (values 1 2 3))
  1 2 3)

(define-ansi-test handler-bind.4
  (let ((x 0))
    (values
     (handler-bind () (incf x) (+ x 10))
     x))
  11 1)

(define-ansi-test handler-bind.5
  (catch :foo
    (handler-bind ((error #'(lambda (c) (throw :foo 'good))))
                  (error "an error")))
  good)

;; (define-ansi-test handler-bind.5.b
;;   (block foo
;;     (handler-bind ((error #'(lambda (c) (return-from foo 'good))))
;;                   (error "an error")))
;;   good)

;; INVERSE ORDER FROM COMMON LISP!!!
(define-ansi-test handler-bind.6
  (catch :foo
    (handler-bind
     ((error #'(lambda (c) (throw :foo 'bad))))
     (handler-bind ((error #'(lambda (c) (error c)))
                    (error #'(lambda (c) (throw :foo 'good))))
                   (error "an error"))))
  good)

(defun handler-bind.7-handler-fn (c)
  (declare (ignore c))
  (throw 'foo 'good))

(define-ansi-test handler-bind.7
  (catch 'foo
    (handler-bind ((error #'handler-bind.7-handler-fn))
                  (error "an error")))
  good)

(define-ansi-test handler-bind.8
  (catch 'foo
    (handler-bind ((error 'handler-bind.7-handler-fn))
                  (error "an error")))
  good)

;; (define-ansi-test handler-bind.9
;;   (catch 'foo
;;     (handler-bind ((error #.(symbol-function
;;                                     'handler-bind.7-handler-fn)))
;;                   (error "an error")))
;;   good)

(define-ansi-test handler-bind.10
  (catch :done
    (flet ((foo () (signals condition))
           (succeed (c) (declare (ignore c)) (throw :done 'good))
           (fail (c) (declare (ignore c)) (throw :done 'bad)))
      (handler-bind
       ((error #'fail)
        (condition #'succeed))
       (foo))))
  good)

(define-ansi-test handler-bind.11
  (catch :done
    (handler-bind
     ((error #'(lambda (c) c))
      (error #'(lambda (c) (declare (ignore c)) (throw :done 'good))))
     (error "an error")))
  good)

;; INVERSE ORDER FROM COMMON LISP!!!
(define-ansi-test handler-bind.12
  (catch :done
    (handler-bind
     ((error #'(lambda (c) c)))
     (handler-bind
      ((error #'(lambda (c) (declare (ignore c)) (throw :done 'good))))
      (error "an error"))))
  good)

(define-ansi-test handler-bind.13
  (handler-bind
   ((error #'(lambda (c) (declare (ignore c))
               (throw 'done 'good))))
   (catch 'done
     (error "an error")))
  good)

(define-ansi-test handler-bind.17
  (catch 'done
    (handler-bind
     ((error
         #'(lambda (c) (declare (ignore c))
             (throw 'done 'good))))
     (error "an error")))
  good)


;;;; adapted from ansi-test/tests/conditions/handler-case.lsp
(define-ansi-test handler-case.1
  (handler-case
   (error "an error")
   (error () t))
  t)

(define-ansi-test handler-case.2
  (handler-case
   (error "an error")
   (type-error () nil)
   (error () t))
  t)

(define-ansi-test handler-case.3
  (handler-case
   (error "an error")
   (error (c) (and (derivedp c error) t))
   (error () 'bad)
   (condition () 'bad2))
  t)

(define-ansi-test handler-case.4
  (handler-case
   (error "an error")
   (type-error (c) c)
   (error (c) (and (derivedp c error) t))
   (error () 'bad)
   (condition () 'bad2))
  t)

(define-ansi-test handler-case.5
  (handler-case
   (error "an error")
   (error (c) (and (derivedp c error) t))
   (error () 'bad))
  t)

(define-ansi-test handler-case.6
  (handler-case (values)
                (error () nil)))

(define-ansi-test handler-case.7
  (handler-case 'foo (condition () 'bar))
  foo)

(define-ansi-test handler-case.8
 (handler-case 'foo (t () 'bar))
 foo)

(define-ansi-test handler-case.9
  (handler-case (values 1 2 3 4 5 6 7 8) (condition () nil))
  1 2 3 4 5 6 7 8)

(define-ansi-test handler-case.10
 (handler-case
  (error "foo")
  (condition () 'good))
 good)

(define-ansi-test handler-case.12
  (handler-case (error "foo")
                (nil () nil)
                (error (c) (not (not (derivedp c error)))))
  t)

(define-ansi-test handler-case.13
  (handler-case (error "foo")
                (error (c) (values))))

(define-ansi-test handler-case.14
  (handler-case (error "foo")
                (error (c)
                       (values 1 2 3 4 5 6 7 8)))
  1 2 3 4 5 6 7 8)

(define-ansi-test handler-case.15
  (handler-case
   (handler-case (error "foo")
                 (warning () 'bad))
   (error () 'good))
  good)

(define-ansi-test handler-case.16
  (handler-case
   (handler-case (error "foo")
                 (error () 'good))
   (error () 'bad))
  good)

;; in euslisp `invoke-next-handler' is used for re-raising
;; (define-ansi-test handler-case.17
;;   (let ((i 0))
;;     (values
;;      (handler-case
;;       (handler-case (error "foo")
;;                     (error () (incf i) (error "bar")))
;;       (error () 'good))
;;      i))
;;   good 1)

;; (define-ansi-test handler-case.18
;;   (let ((i 0))
;;     (values
;;      (handler-case
;;       (handler-case (error "foo")
;;                     (error (c) (incf i) (error c)))
;;       (error () 'good))
;;      i))
;;   good 1)

;; (define-ansi-test handler-case.20
;;   (handler-case
;;    10
;;    (:no-error (x) (+ x 3)))
;;   13)

(define-ansi-test handler-case.27
  (handler-case (error "foo") (error ()))
  nil)

(run-all-tests)
(exit 0)
