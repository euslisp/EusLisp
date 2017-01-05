;;
;;	common lisp variables and constants
;;

(in-package "LISP")
(list "@(#)$Id$")
(export '(short-float-epsilon single-float-epsilon long-float-epsilon
	*keyword-package* *system-package* *user-package* *lisp-package*
	pi pi/2 2pi -pi -pi/2 -2pi
	*random-state* *terminal-io*
	internal-time-units-per-second
	*default-readtable*
	array-rank-limit array-dimension-limit
	most-positive-fixnum most-negative-fixnum
	most-positive-float
	most-negative-float 
	least-positive-float
	least-negative-float
	quit bye
        ))
(export '(af_unix af_inet sock_stream sock_dgram))

;; (export '(unix eus common ieee-floating-point sparc m68020))

(nconc *features* '(:unix :eus :common))
#+(or :sun :mips :linux :cygwin)
(nconc *features* '(:ieee-floating-point))
#+:sun4
(nconc *features* '(:sparc))
#+:sun3
(nconc *features* '(:m68020))
;

#+(or :alpha :irix6 :x86_64 :aarch64)
(progn
  (defconstant sizeof-* 8)
  (defconstant sizeof-long 8)
  (defconstant sizeof-int 4)
  (defconstant sizeof-short 2)
  (defconstant sizeof-char 1)
  (defconstant sizeof-float 4)
  (defconstant sizeof-double 8)
  (defconstant sizeof-header-offset 16)
  (defconstant most-positive-fixnum    #x1fffffffffffffff)
  (defconstant most-negative-fixnum (- #x2000000000000000))
  (defconstant most-positive-float 1.7976931348623151e+308)
  (defconstant most-negative-float -1.7976931348623151e+308)
  (defconstant least-positive-float 1.9762625833649862e-323)
  (defconstant least-negative-float -1.9762625833649862e-323)
  (defconstant pi 3.14159265358979323846)
  (defconstant pi/2 1.57079632679489661923)
  )
#-(or :alpha :irix6 :x86_64 :aarch64)
(progn
  (defconstant sizeof-* 4)
  (defconstant sizeof-long 4)
  (defconstant sizeof-int 4)
  (defconstant sizeof-short 2)
  (defconstant sizeof-char 1)
  (defconstant sizeof-float 4)
  (defconstant sizeof-double 8)
  (defconstant sizeof-header-offset 8)
  (defconstant most-positive-fixnum    #x1fffffff)
  (defconstant most-negative-fixnum (- #x20000000))
  (defconstant most-positive-float 3.4028235677e38)
  (defconstant most-negative-float -3.4028235677e38)
  (defconstant least-positive-float 5.605194e-45)
  (defconstant least-negative-float -5.605194e-45)
  (defconstant pi 3.14159265)
  (defconstant pi/2 (/ pi 2))
  )

(defconstant array-rank-limit 7)
(defconstant array-dimension-limit #x1fffffff)

(defconstant float-epsilon  (expt 2 -21))
(defconstant short-float-epsilon  (expt 2 -21))
(defconstant single-float-epsilon  (expt 2 -21))
(defconstant long-float-epsilon  (expt 2 -21))
(defconstant *keyword-package* (find-package "KEYWORD"))
(defconstant *system-package* (find-package "SYSTEM"))
(defconstant *user-package* (find-package "USER"))
(defconstant *lisp-package* (find-package "LISP"))
(defconstant *unix-package* (find-package "UNIX"))

(defconstant 2pi (* pi 2))
(defconstant -pi (- pi))
(defconstant -pi/2 (- pi/2))
(defconstant -2pi (- 2pi))
(setq *random-state* #i(123456 789012))
(setq *terminal-io* (instantiate io-stream))
(let ((tio *terminal-io*))
  (setq (tio . instream) *standard-input*)
  (setq (tio . outstream) *standard-output*))

(send *system-package* :nicknames '("SI" "SYS"))


#+:ustation
(defconstant internal-time-units-per-second 50)
#+:sun
#-:Solaris2
(defconstant internal-time-units-per-second 60)
#+:Solaris2
(defconstant internal-time-units-per-second 100)
#+:linux
(defconstant internal-time-units-per-second 100)
#+:irix
(defconstant internal-time-units-per-second 100)
#+:irix6
(defconstant internal-time-units-per-second 100)
#+:cygwin
(defconstant internal-time-units-per-second 1000)


(defconstant unix::sighup 1)
(defconstant unix::sigint 2)
(defconstant unix::sigquit 3)
(defconstant unix::sigill 4)
(defconstant unix::sigtrap 5)
(defconstant unix::sigiot 6)

#-:linux
(defconstant unix::sigbus 10)
#+:linux
(defconstant unix::sigbus 7)

(defconstant unix::sigsegv 11)
(defconstant unix::sigpipe 13)
(defconstant unix::sigalrm 14)
(defconstant unix::sigterm 15)

#-(or :linux :Solaris2)
(progn
  (defconstant unix::sigurg 16)
  (defconstant unix::sigstop 17)
  (defconstant unix::sigtstp 18)
  (defconstant unix::sigcont 19)
  (defconstant unix::sigchld 20)
  (defconstant unix::sigttin 21)
  (defconstant unix::sigttou 22)
  (defconstant unix::sigio   23)
  (defconstant unix::sigxcpu 24)
  (defconstant unix::sigxfsz 25)
  (defconstant unix::sigvtalrm 26)
  (defconstant unix::sigprof 27)
  (defconstant unix::sigwinch 28)
  (defconstant unix::siglost 29)
  (defconstant unix::sigusr1 30)
  (defconstant unix::sigusr2 31)
)
#+:linux
(progn
  (defconstant unix::sigurg 23)
  (defconstant unix::sigstop 19)
  (defconstant unix::sigtstp 20)
  (defconstant unix::sigcont 18)
  (defconstant unix::sigchld 17)
  (defconstant unix::sigttin 21)
  (defconstant unix::sigttou 22)
  (defconstant unix::sigio   29)
  (defconstant unix::sigxcpu 24)
  (defconstant unix::sigxfsz 25)
  (defconstant unix::sigvtalrm 26)
  (defconstant unix::sigprof 27)
  (defconstant unix::sigwinch 28)
  (defconstant unix::siglost 29)
  (defconstant unix::sigusr1 10)
  (defconstant unix::sigusr2 12)
)

#+:Solaris2
(progn
  (defconstant unix::sigurg 21)
  (defconstant unix::sigstop 23)
  (defconstant unix::sigtstp 24)
  (defconstant unix::sigcont 25)
  (defconstant unix::sigchld 18)
  (defconstant unix::sigttin 26)
  (defconstant unix::sigttou 27)
  (defconstant unix::sigio   22)
  (defconstant unix::sigxcpu 30)
  (defconstant unix::sigxfsz 31)
  (defconstant unix::sigvtalrm 28)
  (defconstant unix::sigprof 29)
  (defconstant unix::sigwinch 20)
;  (defconstant unix::siglost 29)
  (defconstant unix::sigusr1 30)
  (defconstant unix::sigusr2 31)
)

;; constants for sigprocmask
(progn
   (defconstant unix::SIG_BLOCK		1)
   (defconstant unix::SIG_UNBLOCK	2)
   (defconstant unix::SIG_SETMASK	3))

;; open flag
(defconstant unix::O_RDONLY 0)
(defconstant unix::O_WRONLY 1)
(defconstant unix::O_RDWR 2)
#-(and :linux (not :darwin))
(defconstant unix::O_APPEND #x8)
#+(and :linux (not :darwin))
(defconstant unix::O_APPEND #o2000)

#-(or :Solaris2 :linux :irix :irix6)
(progn
   (defconstant unix::O_CREAT #o1000)
   (defconstant unix::O_TRUNC #o2000)
   (defconstant unix::O_EXCL #o4000))
#+(or :Solaris2 :irix :irix6)
(progn
   (defconstant unix::O_CREAT #x100)
   (defconstant unix::O_TRUNC #x200)
   (defconstant unix::O_EXCL  #x400) )
#+(and :linux (not :darwin))
(progn
   (defconstant unix::O_CREAT #o100)
   (defconstant unix::O_TRUNC #o1000)
   (defconstant unix::O_EXCL  #o200) )
#+:darwin
(progn
   (defconstant unix::O_CREAT #x0200)
   (defconstant unix::O_TRUNC #x0400)
   (defconstant unix::O_EXCL  #x0800) )

(defconstant AF_UNIX  1)
(defconstant AF_INET 2)
;;; address family constants
#-(or :Solaris2 :IRIX :IRIX6)
(progn  (defconstant SOCK_STREAM  1)
	(defconstant SOCK_DGRAM   2))
#+(or :IRIX :Solaris2 :IRIX6)
(progn  (defconstant SOCK_STREAM  2)
	(defconstant SOCK_DGRAM   1))


;;;; SETF definitions.

(defsetf car (x) (y) `(rplaca2 ,x ,y))
(defsetf cdr (x) (y) `(rplacd2 ,x ,y))
(defsetf caar (x) (y) `(rplaca2 (car ,x) ,y))
(defsetf cdar (x) (y) `(rplacd2 (car ,x) ,y))
(defsetf cadr (x) (y) `(rplaca2 (cdr ,x) ,y))
(defsetf cddr (x) (y) `(rplacd2 (cdr ,x) ,y))
(defsetf caaar (x) (y) `(rplaca2 (caar ,x) ,y))
(defsetf cdaar (x) (y) `(rplacd2 (caar ,x) ,y))
(defsetf cadar (x) (y) `(rplaca2 (cdar ,x) ,y))
(defsetf cddar (x) (y) `(rplacd2 (cdar ,x) ,y))
(defsetf caadr (x) (y) `(rplaca2 (cadr ,x) ,y))
(defsetf cdadr (x) (y) `(rplacd2 (cadr ,x) ,y))
(defsetf caddr (x) (y) `(rplaca2 (cddr ,x) ,y))
(defsetf cdddr (x) (y) `(rplacd2 (cddr ,x) ,y))
(defsetf caaaar (x) (y) `(rplaca2 (caaar ,x) ,y))
(defsetf cdaaar (x) (y) `(rplacd2 (caaar ,x) ,y))
(defsetf cadaar (x) (y) `(rplaca2 (cdaar ,x) ,y))
(defsetf cddaar (x) (y) `(rplacd2 (cdaar ,x) ,y))
(defsetf caadar (x) (y) `(rplaca2 (cadar ,x) ,y))
(defsetf cdadar (x) (y) `(rplacd2 (cadar ,x) ,y))
(defsetf caddar (x) (y) `(rplaca2 (cddar ,x) ,y))
(defsetf cdddar (x) (y) `(rplacd2 (cddar ,x) ,y))
(defsetf caaadr (x) (y) `(rplaca2 (caadr ,x) ,y))
(defsetf cdaadr (x) (y) `(rplacd2 (caadr ,x) ,y))
(defsetf cadadr (x) (y) `(rplaca2 (cdadr ,x) ,y))
(defsetf cddadr (x) (y) `(rplacd2 (cdadr ,x) ,y))
(defsetf caaddr (x) (y) `(rplaca2 (caddr ,x) ,y))
(defsetf cdaddr (x) (y) `(rplacd2 (caddr ,x) ,y))
(defsetf cadddr (x) (y) `(rplaca2 (cdddr ,x) ,y))
(defsetf cddddr (x) (y) `(rplacd2 (cdddr ,x) ,y))
(defsetf first (x) (y) `(rplaca2 ,x ,y))
(defsetf second (x) (y) `(rplaca2 (cdr ,x) ,y))
(defsetf third (x) (y) `(rplaca2 (cddr ,x) ,y))
(defsetf fourth (x) (y) `(rplaca2 (cdddr ,x) ,y))
(defsetf fifth (x) (y) `(rplaca2 (cddddr ,x) ,y))
(defsetf sixth (x) (y) `(rplaca2 (nthcdr 5 ,x) ,y))
(defsetf seventh (x) (y) `(rplaca2 (nthcdr 6 ,x) ,y))
(defsetf eighth (x) (y) `(rplaca2 (nthcdr 7 ,x) ,y))
(defsetf ninth (x) (y) `(rplaca2 (nthcdr 8 ,x) ,y))
(defsetf tenth (x) (y) `(rplaca2 (nthcdr 9 ,x) ,y))
(defsetf rest (x) (y) `(rplacd2 ,x ,y))
(defsetf svref (vec n) (val) `(svset ,vec ,n ,val))
(defsetf slot setslot)
(defsetf elt setelt)
(defsetf symbol-value (x) (y) `(setslot ,x symbol 'value ,y))
(defsetf symbol-function setfunc)
(defsetf macro-function (s) (v)
   `(progn (setfunc ,s (cons 'macro ,v)) ,v))
(defsetf aref aset)
(defsetf get (s p &optional d) (v) `(putprop ,s ,v ,p))
(defsetf nth (n l) (v) `(rplaca2 (nthcdr ,n ,l) ,v))
(defsetf char setchar)
(defsetf schar setchar)
(defsetf bit setbit)
(defsetf sbit setbit)
(defsetf fill-pointer (a) (new)
  `(setf (array-fill-pointer ,a) ,new))
(defsetf symbol-plist (sym) (prop) `(setq (,sym . plist) ,prop))
(defsetf gethash (k h &optional d) (v) `(sethash ,k ,h ,v))
;(defsetf documentation (s d) (v)
;  `(case ,d
;     (variable (si::putprop ,s ,v 'variable-documentation))
;     (function (si::putprop ,s ,v 'function-documentation))
;     (structure (si::putprop ,s ,v 'structure-documentation))
;     (type (si::putprop ,s ,v 'type-documentation))
;     (setf (si::putprop ,s ,v 'setf-documentation))
;     (t (error "~S is an illegal documentation type." ,d))))

(defsetf matrix-row (x y) (val) `(set-matrix-row ,x ,y ,val))
(defsetf matrix-column (x y) (val) `(set-matrix-column ,x ,y ,val))

;(import 'unix::uexit)
(import 'unix:runtime)
(import '(system:room system:gc system:alloc system:save))
;;;
;;; define slot access macros for all built-in classes
;;;

(let ((vvec) (var) (accessor) (count 0))
   (dolist (c (sys:list-all-classes))
      (setq vvec (c . vars))
      (dotimes (i (length vvec))
	 (setq var (svref vvec i))
 	 (setq accessor
	       (intern (concatenate string (symbol-name (c . name))
					   "-"
					   (symbol-name var))
			 *lisp-package*))
	 (when (null (fboundp accessor))
	     (export accessor)
	     (setf (symbol-function accessor)
	           `(macro (obj) (list 'slot obj ',(c . name) ,i)))
	     (incf count))))
    count)

;;; make default read table

(defconstant *default-readtable* (copy-readtable))

(setf (symbol-function 'char=) (symbol-function '=))
(setf (symbol-function 'char<) (symbol-function '<))
(setf (symbol-function 'char>) (symbol-function '>))
(setf (symbol-function 'char<=) (symbol-function '<=))
(setf (symbol-function 'char>=) (symbol-function '>=))
(setf (symbol-function 'char/=) (symbol-function '/=))

(setf (symbol-function 'quit) (symbol-function 'unix::exit))
(setf (symbol-function 'bye) (symbol-function 'unix::exit))


