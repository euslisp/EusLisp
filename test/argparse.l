;; test code for argparse

(require :unittest "lib/llib/unittest.l")
(require :argparse "lib/llib/argparse.l")

(init-unit-test)

(defun tmp (name &optional suffix)
  (let ((suffix (and suffix (substitute #\- #\. (string-downcase suffix)))))
    (concatenate string #+:linux "/tmp/" name suffix ".l")))

(defun princ-line (obj &optional (stream *standard-output*))
  (princ obj stream)
  (terpri stream))

(defun write-tmp-file (fname send-lst)
  `(with-open-file (test-file ,fname :direction :output :if-exists :supersede)
     (princ-line "(lisp::install-error-handler #'(lambda (&rest args) (exit 1)))" test-file)
     (princ-line "(require :argparse \"lib/llib/argparse.l\")" test-file)
     (terpri test-file)
     (princ-line "(setq argparse (instantiate argparse:argument-parser))" test-file)
     ,@(mapcar
        #'(lambda (cmd) `(princ-line ,(format nil "~S"`(send argparse ,@cmd)) test-file))
        send-lst)
     (terpri test-file)
     (princ-line "(send argparse :parse-args)" test-file)
     (princ-line "(print (mapcar #'(lambda (lst) (cons (car lst) ((cdr lst) . value))) (send argparse :plist)))" test-file)
     (princ-line "(exit 0)" test-file)))

(defun read-multi-line-char (s c n)
  (let (acc c)
    (while (setq c (read-char s))
      (if (eq c #\")
          (if (eq (read-char s) #\#)
              (return (coerce (nreverse acc) string))
            (unread-char c s))
        (push c acc)))))
(set-dispatch-macro-character #\# #\" #'read-multi-line-char)

(defmacro defargparse-test (name command result &rest send-lst)
  (let ((testf (tmp "tmp-argparse-test-" name))
        (resf (tmp "tmp-argparse-result-" name)))
    `(deftest ,name
       ,(write-tmp-file testf send-lst)
       (assert (= 0 (unix:system ,(format nil "eus ~A ~A 2>/dev/null 1>~A" testf command resf))))
       (let ((alst (read-file ,resf)))
         ,@(mapcar #'(lambda (res)
                       `(assert (and (assoc ,(car res) alst)
                                     (equal (cdr (assoc ,(car res) alst)) ,(cadr res)))))
                   result)))))

(defmacro defargparse-help (name result &rest send-lst)
  (let ((testf (tmp "tmp-argparse-test-" name))
        (resf (tmp "tmp-argparse-result-" name)))
    `(deftest ,name
       ,(write-tmp-file testf send-lst)
       (assert (= 0 (unix:system ,(format nil "eus ~A --help 2>/dev/null 1>~A" testf resf))))
       (let ((str1 ,result)
             (str2 (string-right-trim '(#\Space #\Newline) (read-binary-file ,resf))))
         (assert (string= str1 str2))))))

(defmacro defargparse-error (name command &rest send-lst)
  (let ((testf (tmp "tmp-argparse-test-" name)))
    `(deftest ,name
       ,(write-tmp-file testf send-lst)
       (assert (= 256 (unix:system ,(format nil "eus ~A ~A 2>/dev/null 1>/dev/null" testf command)))))))


;; HELP TESTS

(defargparse-help help-init.1
#"usage: [-h]

optional arguments:
  -h, --help	show this help message and exit"#
  (:init))

(defargparse-help help-init.2
#"usage: [-h]

Program Description

optional arguments:
  -h, --help	show this help message and exit"#
  (:init :description "Program Description"))

(defargparse-help help-init.3
#"usage: [-h]

optional arguments:
  -h, --help	show this help message and exit

Program Epilog"#
  (:init :epilog "Program Epilog"))

(defargparse-help help-init.4
#"usage: help-init.4 [-h]

optional arguments:
  -h, --help	show this help message and exit"#
  (:init :prog "help-init.4"))

(defargparse-help help-init.5
#"usage: help-init.5 [-h]

optional arguments:
  -h, --help	show this help message and exit"#
  (:init :prog 'help-init.5))

(defargparse-help help-init.6
#"usage: help-init.6 [-h]

Program Description

optional arguments:
  -h, --help	show this help message and exit

Program Epilog"#
  (:init :prog "help-init.6" :description "Program Description" :epilog "Program Epilog"))

(defargparse-help help-arg.1
#"usage: [-h] [--arg=ARG]

optional arguments:
  -h, --help	show this help message and exit
  --arg=ARG"#
  (:init)
  (:add-argument "--arg"))

(defargparse-help help-arg.2
#"usage: [-h] [--arg=ARG]

optional arguments:
  -h, --help	show this help message and exit
  --arg=ARG	the arg help"#
  (:init)
  (:add-argument "--arg" :help "the arg help"))

(defargparse-help help-arg.3
#"usage: [-h] [--arg=ARG]

optional arguments:
  -h, --help	show this help message and exit
  --arg=ARG	(default: 10)"#
  (:init)
  (:add-argument "--arg" :default 10))

(defargparse-help help-arg.4
#"usage: [-h] [--arg=ARG]

optional arguments:
  -h, --help	show this help message and exit
  --arg=ARG	the arg help (default: 10)"#
  (:init)
  (:add-argument "--arg" :help "the arg help" :default 10))

(defargparse-help help-arg.5
#"usage: [-h] [-a=ARG]

optional arguments:
  -h, --help	show this help message and exit
  -a=ARG, --arg=ARG"#
  (:init)
  (:add-argument '("--arg" "-a")))

(defargparse-help help-arg.6
#"usage: [-h] [--arg=DEST]

optional arguments:
  -h, --help	show this help message and exit
  --arg=DEST"#
  (:init)
  (:add-argument "--arg" :dest "dest"))

(defargparse-help help-arg.7
#"usage: [-h] [--arg=DEST]

optional arguments:
  -h, --help	show this help message and exit
  --arg=DEST"#
  (:init)
  (:add-argument "--arg" :dest 'dest))

(defargparse-help help-arg.8
#"usage: [-h] [--arg=DEST]

optional arguments:
  -h, --help	show this help message and exit
  --arg=DEST"#
  (:init)
  (:add-argument "--arg" :dest :dest))

(defargparse-help help-arg.9
#"usage: [-h] [--arg=ARG]

optional arguments:
  -h, --help	show this help message and exit
  --arg=ARG"#
  (:init)
  (:add-argument "--arg" :action #'(lambda (obj) obj)))

(defargparse-help help-arg.10
#"usage: [-h] --arg=ARG

required arguments:
  --arg=ARG

optional arguments:
  -h, --help	show this help message and exit"#
  (:init)
  (:add-argument "--arg" :required t))

(defargparse-help help-arg.11
#"usage: [-h] [--arg={1,2,3}]

optional arguments:
  -h, --help	show this help message and exit
  --arg={1,2,3}"#
  (:init)
  (:add-argument "--arg" :choices (list 1 2 3)))

(defargparse-help help-flag.1
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg"#
  (:init)
  (:add-argument "--arg" :action :store-true))

(defargparse-help help-flag.2
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg	the arg help"#
  (:init)
  (:add-argument "--arg" :action :store-true :help "the arg help"))

(defargparse-help help-flag.3
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg	(default: t)"#
  (:init)
  (:add-argument "--arg" :action :store-false))

(defargparse-help help-flag.4
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg	the arg help (default: t)"#
  (:init)
  (:add-argument "--arg" :action :store-false :help "the arg help"))

(defargparse-help help-flag.5
#"usage: [-h] [-a]

optional arguments:
  -h, --help	show this help message and exit
  -a, --arg"#
  (:init)
  (:add-argument '("--arg" "-a") :action :store-true))

(defargparse-help help-flag.6
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg"#
  (:init)
  (:add-argument "--arg" :action :store-true :dest "dest"))

(defargparse-help help-flag.7
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg"#
  (:init)
  (:add-argument "--arg" :action :store-true :dest 'dest))

(defargparse-help help-flag.8
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg"#
  (:init)
  (:add-argument "--arg" :action :store-true :dest :dest))

(defargparse-help help-flag.9
#"usage: [-h] [--arg]

optional arguments:
  -h, --help	show this help message and exit
  --arg"#
  (:init)
  (:add-argument "--arg" :action #'(lambda () 10)))

(defargparse-help help-overall.1
#"usage: test.l [-h] --arg=ARG --req={1,2,3} [--def=DEF] [--dest=REMAP] [-f] [-ff] [-ca=CA] [-cf] [-cc=CC] [-ccf=CCF] [--count] [-a={1,2,3}] [--const]

Program Description

required arguments:
  --arg=ARG	The 'arg' argument
  --req={1,2,3}	The 'req' argument

optional arguments:
  -h, --help	show this help message and exit
  --def=DEF	(default: 10)
  --dest=REMAP
  -f, --flag	The 'flag' argument
  -ff, --flag-false	The 'flag' argument (default: t)
  -ca=CA	Callback with argument
  -cf	Callback without argument
  -cc=CC	Callback with compiled function
  -ccf=CCF	Callback with compiled function
  --count
  -a={1,2,3}, --append={1,2,3}
  --const"#
  (:init :description "Program Description" :prog "test.l")
  (:add-argument "--arg" :help "The 'arg' argument" :required t)
  (:add-argument "--req" :help "The 'req' argument" :required t :read t :choices (list 1 2 3))
  (:add-argument "--def" :default 10 :read t :check #'evenp)
  (:add-argument "--dest" :dest 'remap)
  (:add-argument '("--flag" "-f") :help "The 'flag' argument" :action :store-true)
  (:add-argument '("--flag-false" "-ff") :help "The 'flag' argument" :action :store-false)
  (:add-argument "-ca" :help "Callback with argument"
                 :action #'(lambda (val) (format t "Callback with value ~S~%" val)))
  (:add-argument "-cf" :help "Callback without argument"
                 :action #'(lambda () (format t "Callback!~%")))
  (:add-argument "-cc" :help "Callback with compiled function"
                 :action #'print)
  (:add-argument "-ccf" :help "Callback with compiled function"
                 :action #'lisp-implementation-version)
  (:add-argument "--count" :action :count)
  (:add-argument '("--append" "-a") :action :append :read t :choices (list 1 2 3))
  (:add-argument "--const" :const 10 :action :store-const))


;; PARSING TESTS

(defargparse-test store.1
  ""
  ((:arg nil))
  (:init)
  (:add-argument "--arg"))

(defargparse-test store.2
  ""
  ((:arg 10))
  (:init)
  (:add-argument "--arg" :default 10))

(defargparse-test store.3
  "--arg=1"
  ((:arg "1"))
  (:init)
  (:add-argument "--arg"))

(defargparse-test store.4
  "--arg=1"
  ((:arg 1))
  (:init)
  (:add-argument "--arg" :read t))

(defargparse-test store.5
  "--arg=1"
  ((:destination "1"))
  (:init)
  (:add-argument "--arg" :dest 'destination))

(defargparse-test store.6
  "--arg=1"
  ((:arg 1))
  (:init)
  (:add-argument "--arg" :read t :choices (list 1 2 3)))

(defargparse-test store.7
  "--arg=1"
  ((:arg 1))
  (:init)
  (:add-argument "--arg" :read t :check #'integerp))

(defargparse-test store.8
  "--arg=1"
  ((:arg "1"))
  (:init)
  (:add-argument "--arg" :required t))

(defargparse-test store-true.1
  ""
  ((:arg nil))
  (:init)
  (:add-argument "--arg" :action :store-true))

(defargparse-test store-true.2
  "--arg"
  ((:arg t))
  (:init)
  (:add-argument "--arg" :action :store-true))

(defargparse-test store-false.1
  ""
  ((:arg t))
  (:init)
  (:add-argument "--arg" :action :store-false))

(defargparse-test store-false.2
  "--arg"
  ((:arg nil))
  (:init)
  (:add-argument "--arg" :action :store-false))

(defargparse-test store-const.1
  ""
  ((:arg nil))
  (:init)
  (:add-argument "--arg" :action :store-const :const 10))

(defargparse-test store-const.2
  "--arg"
  ((:arg 10))
  (:init)
  (:add-argument "--arg" :action :store-const :const 10))

(defargparse-test count.0
  ""
  ((:arg nil))
  (:init)
  (:add-argument "--arg" :action :count))

(defargparse-test count.1
  "--arg"
  ((:arg 1))
  (:init)
  (:add-argument "--arg" :action :count))

(defargparse-test count.2
  "--arg --arg"
  ((:arg 2))
  (:init)
  (:add-argument "--arg" :action :count))

(defargparse-test count.3
  "--arg --arg --arg"
  ((:arg 3))
  (:init)
  (:add-argument "--arg" :action :count))

(defargparse-test count.4
  "--arg"
  ((:arg 11))
  (:init)
  (:add-argument "--arg" :action :count :default 10))

(defargparse-test append.0
  ""
  ((:arg nil))
  (:init)
  (:add-argument "--arg" :action :append))

(defargparse-test append.1
  "--arg=a"
  ((:arg '("a")))
  (:init)
  (:add-argument "--arg" :action :append))

(defargparse-test append.2
  "--arg=a --arg=b"
  ((:arg '("a" "b")))
  (:init)
  (:add-argument "--arg" :action :append))

(defargparse-test append.3
  "--arg=a --arg=b --arg=c"
  ((:arg '("a" "b" "c")))
  (:init)
  (:add-argument "--arg" :action :append))

(defargparse-test append.4
  "--arg=b"
  ((:arg '("a" "b")))
  (:init)
  (:add-argument "--arg" :action :append :default (list "a")))

(defargparse-test callback.1
  ""
  ((:arg nil))
  (:init)
  (:add-argument "--arg" :action #'identity))

(defargparse-test callback.2
  "--arg=a"
  ((:arg "a"))
  (:init)
  (:add-argument "--arg" :action #'identity))

(defargparse-test callback.3
  "--arg=1"
  ((:arg 2))
  (:init)
  (:add-argument "--arg" :action #'(lambda (arg) (1+ arg)) :read t))

(defargparse-test callback.4
  "--arg"
  ((:arg 10))
  (:init)
  (:add-argument "--arg" :action #'(lambda () 10)))

(defargparse-test parse-overall.1
  "--arg=1 --req=2"
  ((:arg "1") (:req 2) (:def 10) (:remap nil) (:flag nil) (:flag-false t)
   (:ca nil) (:cf nil) (:cc nil) (:ccf nil) (:count nil) (:append nil) (:const nil))
  (:init :description "Program Description" :prog "test.l")
  (:add-argument "--arg" :help "The 'arg' argument" :required t)
  (:add-argument "--req" :help "The 'req' argument" :required t :read t :choices (list 1 2 3))
  (:add-argument "--def" :default 10 :read t :check #'evenp)
  (:add-argument "--dest" :dest 'remap)
  (:add-argument '("--flag" "-f") :help "The 'flag' argument" :action :store-true)
  (:add-argument '("--flag-false" "-ff") :help "The 'flag' argument" :action :store-false)
  (:add-argument "-ca" :help "Callback with argument"
                 :action #'(lambda (val) (format t "Callback with value ~S~%" val)))
  (:add-argument "-cf" :help "Callback without argument"
                 :action #'(lambda () (format t "Callback!~%")))
  (:add-argument "-cc" :help "Callback with compiled function"
                 :action #'print)
  (:add-argument "-ccf" :help "Callback with compiled function"
                 :action #'lisp-implementation-version)
  (:add-argument "--count" :action :count)
  (:add-argument '("--append" "-a") :action :append :read t :choices (list 1 2 3))
  (:add-argument "--const" :const 10 :action :store-const))

(defargparse-test parse-overall.2
  "--arg=a --req=3 --def=2 -ff --dest=b -ccf --count"
  ((:arg "a") (:req 3) (:def 2) (:remap "b") (:flag nil) (:flag-false nil)
   (:ca nil) (:cf nil) (:cc nil) (:ccf #.(lisp-implementation-version)) (:count 1)
   (:append nil) (:const nil))
  (:init :description "Program Description" :prog "test.l")
  (:add-argument "--arg" :help "The 'arg' argument" :required t)
  (:add-argument "--req" :help "The 'req' argument" :required t :read t :choices (list 1 2 3))
  (:add-argument "--def" :default 10 :read t :check #'evenp)
  (:add-argument "--dest" :dest 'remap)
  (:add-argument '("--flag" "-f") :help "The 'flag' argument" :action :store-true)
  (:add-argument '("--flag-false" "-ff") :help "The 'flag' argument" :action :store-false)
  (:add-argument "-ca" :help "Callback with argument"
                 :action #'(lambda (val) (format t "Callback with value ~S~%" val)))
  (:add-argument "-cf" :help "Callback without argument"
                 :action #'(lambda () (format t "Callback!~%")))
  (:add-argument "-cc" :help "Callback with compiled function"
                 :action #'print)
  (:add-argument "-ccf" :help "Callback with compiled function"
                 :action #'lisp-implementation-version)
  (:add-argument "--count" :action :count)
  (:add-argument '("--append" "-a") :action :append :read t :choices (list 1 2 3))
  (:add-argument "--const" :const 10 :action :store-const))


;; ERROR TESTS

(defargparse-error parse-error.1
  "--help"
  (:init :add-help nil))

(defargparse-error parse-error.2
  "--arg"
  (:init))

(defargparse-error parse-error.3
  "--arg"
  (:init)
  (:add-argument "--arg"))

(defargparse-error parse-error.4
  "--arg=1"
  (:init)
  (:add-argument "--arg" :action :store-true))

(defargparse-error parse-error.5
  "--arg=1"
  (:init)
  (:add-argument "--arg" :action :store-false))

(defargparse-error parse-error.6
  "--arg=1"
  (:init)
  (:add-argument "--arg" :action :count))

(defargparse-error parse-error.7
  "--arg=1"
  (:init)
  (:add-argument "--arg" :action :const 10 :store-const))

(defargparse-error parse-error.8
  ""
  (:init)
  (:add-argument "--arg" :required t))

(defargparse-error parse-error.9
  "--arg=10"
  (:init)
  (:add-argument "--arg" :read t :choices (list 1 2 3)))

(defargparse-error parse-error.10
  "--arg=1"
  (:init)
  (:add-argument "--arg" :read t :check #'evenp))

(defargparse-error instance-error.1
  ""
  (:init)
  (:add-argument '("--arg" "-a"))
  (:add-argument '("--another" "-a")))

(defargparse-error instance-error.2
  ""
  (:init)
  (:add-argument "--arg")
  (:add-argument "--another" :dest 'arg))

(defargparse-error instance-error.3
  ""
  (:init)
  (:add-argument "--arg" :action :none))

(defargparse-error instance-error.4
  ""
  (:init)
  (:add-argument "--arg" :choices t))

(defargparse-error instance-error.5
  ""
  (:init)
  (:add-argument "--arg" :check t))

(defargparse-error instance-error.6
  ""
  (:init)
  (:add-argument "arg"))

(defargparse-error instance-error.7
  ""
  (:init)
  (:add-argument "-invalid=argument"))

(defargparse-error instance-error.8
  ""
  (:init)
  (:add-argument 'arg))


;; RUN TESTS

(run-all-tests)
(exit 0)
