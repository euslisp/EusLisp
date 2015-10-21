;; Every symbol is still internal.
;;        (system::srcload "l/exports.l")

;; export symbols


(lisp::progn
	(lisp::setq lisp::*package* (lisp::find-package "LISP"))
	lisp::nil)

(defun in-package (x) (setq *package* (find-package x)) t)

(export 'in-package)

(in-package "LISP")

;; eus.c
  (export '(nil t))
  (export '(&optional &rest &key &aux &allow-other-keys
		lambda macro lambda-closure compiled-closure
		declare special))
  (export '(compile eval load))		;eval-when indicators
  ;; type specifiers
  (export '(integer float fixnum number))
  (export '(*print-case* *print-circle* *print-object* *print-structure*
		*print-length* *print-level*
		*readtable* *toplevel* *read-base* *print-base*
		*error-handler* *evalhook* *debug* *exit-on-fatal-error*
		*unbound* *random-state* *features*
		*package*
		*standard-input* *standard-output*
		*error-output* *terminal-io*
		*program-name*
		*unbound*))
  ;; LEO
  (export '(self class))
  ;; classnames, variable names are exported by 'basicclass'
  (export '(string float-vector interger-vector bit-vector))
  ;; feature constants
  (export '(vax sun apollo mips sun3 sun4 news sanyo bsd4_2 sunos4
		sunos4.1 system5 coff alpha thread))
;; specials.c
  (export '(quote eval apply funcall progn prog1 function))
  (export '(mapc mapcar mapcan setq if when cond while let let* 
		unwind-protect catch throw flet labels block return-from
		return reset go tagbody evalhook macroexpand2 eval-when
		the and or proclaim declare symbol-value symbol-function
		makunbound defun defmacro find-symbol intern gensym
		list-all-packages find-package 
		sxhash get export putprop))
;; makepackage ??
;; setfunc is internal

;; arith.c
  (export '(  =  >  <  >=  <=  MOD  1-  1+  +  -  *  /
	  SIN  COS  TAN  ATAN  TANH  ATANH  SINH  ASINH  COSH  ACOSH
	  SQRT  LOG  EXP  ABS  ROUND  FLOOR  CEILING  TRUNCATE  FLOAT  DECODE-FLOAT
	  MAX  MIN  LOGAND  LOGIOR  LOGXOR  LOGEQV  LOGNAND  LOGNOR  LOGNOT  LOGTEST
	  LOGBITP  ASH  LDB  DPB  MAKE-RANDOM-STATE  RANDOM))
;;
;; charstring.c
  (export '(  CHAR  SCHAR  SETCHAR  ALPHA-CHAR-P
	  UPPER-CASE-P  LOWER-CASE-P  DIGIT-CHAR-P  ALPHANUMERICP  CHAR-UPCASE
	  CHAR-DOWNCASE  STRINGEQ  STRINGEQUAL  STRING<  STRING<=  STRING=
	  STRING>  STRING>=))
  
;; leo.c
  (export '(  CLASS
	  ENTER-CLASS  DEFMETHOD  SEND  SEND-MSG  SEND-IF-FOUND
	  SEND-MESSAGE   INSTANTIATE  CLASSP  SUBCLASSP
	  DERIVEDP  CLONE  SLOT  SETSLOT  FIND-METHOD
	  COPY-OBJECT  BECOME  REPLACE-OBJECT  ))

;;
;; lispio.c
;;
  (export '(
	  CLOSE  READ  READ-DELIMITED-LIST  READ-LINE  READ-CHAR
	  UNREAD-CHAR  PEEK-CHAR  PRINT  PRIN1  PRINC  TERPRI
	  PRINT-SIZE  FINISH-OUTPUT  WRITE-BYTE  WRITE-WORD
	  WRITE-LONG  SET-MACRO-CHARACTER  GET-MACRO-CHARACTER
	  SET-DISPATCH-MACRO-CHARACTER  GET-DISPATCH-MACRO-CHARACTER
	  FORMAT  ERROR))

;;
;; lists.c
;;
  (export '( CAR  CDR  REST  CADR  CDDR  CDAR  CAAR  CADDR
	  NTH  NTHCDR  CONS  RPLACA  RPLACA2  RPLACD  RPLACD2
	  APPEND  NCONC  SUBST  NSUBST
	  ATOM  EQ  EQL  NULL  NOT  LIST  LIST*  EQUAL  SUPEREQUAL
	  MEMQ  MEMBER  SUPERMEMBER  ASSQ  ASSOC  SUPERASSOC
	  BUTLAST  NBUTLAST  SYMBOLP  STRINGP  LISTP  CONSP
	  ENDP  NUMBERP  INTEGERP  FLOATP  BOUNDP  FBOUNDP  STREAMP))

;;
;; matrix.c
;;
  (export '(  V+  V++  V- V-ABS  V.  V*  V.*  V<  V>  VMIN  VMAX
	  MINIMAL-BOX  SCALE  NORM   NORM2  NORMALIZE-VECTOR  DISTANCE
	  DISTANCE2  MIDPOINT  FLOATVECTOR  FLOAT-VECTOR  TRANSFORM
	  M*  ROTATE-VECTOR  ROTATE-MATRIX  ROTATION-MATRIX  ROTATION-ANGLE
	  TRANSPOSE  RPY-ANGLE  EULER-ANGLE  LU-DECOMPOSE  LU-SOLVE
	  LU-DETERMINANT))
;;
;; sequence.c
  (export '(IDENTITY  SUBSEQ  COPY-SEQ  REVERSE  NREVERSE
	  CONCATENATE  COERCE  MAP  SORT  LENGTH  ELT  SETELT  ))

  (export '(  AREF
	  ASET  VECTOR-POP  VECTOR-PUSH  VECTOR-PUSH-EXTEND  ARRAYP
	  SVREF  SVSET  VECTOR  VECTORP  INTEGER-VECTOR  BIT  SBIT
	  SETBIT  BIT-AND  BIT-IOR  BIT-XOR  BIT-EQV  BIT-NAND  BIT-NOR
	  BIT-NOT))


;;
;; unixcall.c
;;
  (export '(exit))	;export exit before comp::exit is made.
  (setq *package* (find-package "UNIX"))
  (lisp:setq (lisp:*package* . lisp:use)
		(lisp:list (lisp:find-package "LISP")))
  (export '(
	  SIGADDSET SIGDELSET SIGPROCMASK
	  KILL  SIGNAL  #| EXIT |# GETPID 
	  UREAD  WRITE  UCLOSE
	  IOCTL  LSEEK  MALLOC  FREE  SOCKET  BIND  CONNECT  LISTEN
	  ACCEPT  SENDTO  RECVFROM  GETPEERNAME))

;; not supported by vxworks
  (export '(  PTIMES  RUNTIME  LOCALTIME  ASCTIME GMTIME
	  GETITIMER  SETITIMER  GETRUSAGE  GETPAGESIZE ALARM))

  (export '(  WAIT  FORK  GETPPID  GETPGRP  SETPGRP  GETUID
	  GETEUID  GETGID  GETEGID  SETUID  SETGID  MKNOD  FCNTL
	  MKDIR RMDIR
	  IOCTL_  IOCTL_R  IOCTL_W  IOCTL_WR  DUP  DUP2 #|DIRECTORY|#
	  SYSTEM  GETWD  GETENV  SLEEP  ERRNO PERROR SYSERRLIST  PAUSE  ISATTY
	  ENVIRON
	  LINK  UNLINK  RENAME  ACCESS  FLOCK  STAT  CHDIR  CHMOD  CHOWN
	  PIPE  SELECT  SELECT-READ-FD  GETHOSTNAME  GETHOSTBYNAME
	  GETHOSTBYADDR  GETNETBYNAME  GETPROTOBYNAME  GETSERVBYNAME))

  (export '( VFORK  EXEC  GETPRIORITY  SETPRIORITY
		  PUTENV   USLEEP  UALARM
		  gettimeofday))

  (export '(  MSGGET  MSGSND  MSGRCV  MSGCTL))

  (export '(  VALLOC  MMAP  MUNMAP  VADVISE))
  (export '(  UNAME))
  (export '(  DBM-OPEN  DBM-CLOSE  DBM-FETCH  DBM-STORE	 DBM-DELETE
	  DBM-FIRSTKEY  DBM-NEXTKEY  DBM-ERROR  DBM-CLEARERR))

;; clib/ioctl.c

  (export '( TIOCGETP   TIOCSETP   TIOCSETN   TIOCGETD   TIOCFLUSH 
	  TIOCGPGRP   TIOCSPGRP   TIOCOUTQ   FIONREAD   TIOCSETC 
	  TIOCLBIS   TIOCLBIC   TIOCLSET   TIOCLGET   TCGETS   TCSETS
	  TCSETSW   TCSETSF   TCGETA   TCSETA   TCSETAW   TCSETAF 
	  TCGETATTR   TCSETATTR ))

;; system functions in the system package
  (setq *package* (find-package "SYSTEM"))
  (lisp:setq (*package* . lisp:use)
	     (lisp:list (lisp:find-package "LISP")))
  (export '(OPENFILE		;; internal???
		SRCLOAD BINLOAD SAVE
		RESET-READTABLE     ))

  (export '( GC  GCTIME RGCCOUNT RGCTIME RGCALLOCATED
	  *GC-MERGE* *GC-MARGIN*
	  *GC-HOOK* *EXIT-HOOK*
	  ALLOC  NEWSTACK  RECLAIM  RECLAIM-TREE
	  OBJECT-SIZE  MEMORY-REPORT  CLEAR-MEMORY-REPORT
	  ROOM  LIST-ALL-CHUNKS  LIST-ALL-INSTANCES  ADDRESS  PEEK  POKE
	  LIST-ALL-REFERENCES  LIST-ALL-CATCHERS  LIST-ALL-BINDINGS
	  LIST-ALL-SPECIAL-BINDINGS  LIST-ALL-CLASSES))

  (export '*threads*)

(in-package "LISP")
(export '(*machine* *os-version* *eusdir*
		  *unix-package* *lisp-package* *system-package*
		  *user-package* *keyword-package*
		  *symbol-input* *symbol-output*))

;(progn
;   (proclaim
;	'(special
;		lisp:*machine* 
;		lisp:*os-version*
;		lisp:*eusdir*
;		lisp:*package*)))

;; Multi-Thread EusLisp
;; mthread.c
(in-package "SYSTEM")
(export '(make-thread thread wait-thread thread-no-wait thread-self))
(export '(make-mutex-lock mutex-lock mutex-trylock mutex-unlock))
(export '(make-semaphore sema-post sema-wait))
#+(or :Solaris2 :thread)
(export '(sema-trywait))
(export '(make-cond cond-wait cond-signal))

(in-package "UNIX")
(export '(thr-setconcurrency thr-getconcurrency thr-self thr-setprio
	  thr-getprio thr-create
	  thr-continue thr-kill thr-suspend
	  thr-sigsetmask))

;;;;;;;;;;
;;;;;;;;;	end of export.l
;;;;;;;;;

(in-package "USER")

(in-package (find-package "LISP"))
; setup error handler
;	(defun system::error-handler (&rest mes)
;	   (format t "~s~%error occured during boot strapping, bye!~%" mes)
;	   (unix::uexit 1))
(progn
;	   (setq lisp:*error-handler* 'system::error-handler)
	   (setq ((find-package "SYSTEM") . use) (list (find-package "LISP")))
	   (setq ((find-package "UNIX") . use) (list (find-package "LISP")))
	   (setq ((find-package "USER") . use) (list (find-package "LISP")))
	   t)
;(setq *debug* t)
;
; set configuration parameters from environment variables
(setq *EUSDIR*
	(if (unix:getenv "EUSDIR")
	    (unix:getenv "EUSDIR")
	     "/usr/local/eus/"))
(if (not (eql (elt *eusdir* (1- (length *eusdir*))) #\/))
	(setq *eusdir* (concatenate string *eusdir* "/")))
(setq *MACHINE* "sun4")
#+:Solaris2
  (setq *OS-VERSION* "Solaris2")
#+:SunOS4.1
  (setq *OS-VERSION* "SunOS 4.1")
#+:linux
  (setq *OS-VERSION* "Linux")
#+(and :linux :x86_64)
  (setq *OS-VERSION* "Linux64")
#+:irix
  (setq *OS-VERSION* "IRIX")
#+:irix6
  (setq *OS-VERSION* "IRIX6")
#+:alpha
  (setq *OS-VERSION* "alpha")
#+:cygwin
  (setq *OS-VERSION* "Cygwin")
#+:darwin
  (setq *OS-VERSION* "Darwin")

; llib objects
(system:alloc 80000)
(defmethod object
 (:prin1 (&optional (f t)) (format f "cannot prin1")))

(if (unix::isatty 0)
(defun system::exec-module-init (name &optional (file))
   (let ((func (cadr (superassoc name system::*load-entries* nil #'equal nil))))
      (if (null func)
	  (setq func (cadr (superassoc (concatenate string "___" name)
				system::*load-entries* nil #'equal nil))))
      (cond (func
	      (format *error-output* ";; ~a " name)
	      (finish-output *error-output*)
	      (funcall func func)
	      t)
	    ((and file 
		(eq (unix::access (concatenate string *eusdir* "lisp/" file)) T))
		(format *error-output* ";; ~A " file)
		(finish-output *error-output*)
		(system::srcload (concatenate string *eusdir* "lisp/" file))
	        t)
	    (t (format *error-output* ";; ~a-undefined " name) nil))))
(defun system::exec-module-init (name &optional (file))
   (let ((func (cadr (superassoc name system::*load-entries* nil #'equal nil))))
      (if (null func)
	  (setq func (cadr (superassoc (concatenate string "___" name)
				system::*load-entries* nil #'equal nil))))
      (cond (func
	      (funcall func func)
	      t)
	    ((and file 
		(eq (unix::access (concatenate string *eusdir* "lisp/" file)) T))
		(system::srcload (concatenate string *eusdir* "lisp/" file))
	        t) )
	)) )

(system::exec-module-init "readmacro" "l/readmacro.l")
(system::exec-module-init "object" "l/object.l")
(system::exec-module-init "packsym" "l/packsym.l")
(system::exec-module-init "common" "l/common.l")
(system::exec-module-init "constants" "l/constants.l")
  ;; (format t "lisp-package=~A~%" *lisp-package*)
  (send *lisp-package* :used-by (find-package "UNIX"))
  (send *lisp-package* :used-by (find-package "SYSTEM"))
  (send *lisp-package* :used-by (find-package "X"))
(system::exec-module-init "stream" "l/stream.l")
(system::exec-module-init "string" "l/string.l")
(system::exec-module-init "loader" "l/loader.l")
;; provide is defined in loader
(system::exec-module-init "pprint" "l/pprint.l")
(system::exec-module-init "process" "l/process.l")
(system::exec-module-init "hashtab" "l/hashtab.l")
(system::exec-module-init "array" "l/array.l")
(system::exec-module-init "mathtran" "l/mathtran.l")
(system::exec-module-init "eusdebug" "l/eusdebug.l")
(system::exec-module-init "eusforeign" "l/eusforeign.l")
(unless (find-package "GEOMETRY")
	(make-package "GEOMETRY" :nicknames '("GEO"))
	(in-package "GEOMETRY"))
(system::exec-module-init "coordinates" "l/coordinates.l")

(in-package "LISP")
(setf (symbol-function 'get-internal-run-time)
	(symbol-function 'unix::runtime))
;; toplevel needs the compiler package
;;	(format t ";;; Loading compiler modules.~%")
	(make-package "COMPILER" :nicknames '("COMP"))
;;
	(system::exec-module-init "tty" "l/tty.l")
	(system::exec-module-init "history" "l/history.l")
	(system::exec-module-init "toplevel" "l/toplevel.l")
	;; (print "toplevel.l ok")
;;
;; initialize the compiler
	(in-package "COMPILER")
	(system::exec-module-init "trans" "comp/trans.l")
	(system::exec-module-init "comp" "comp/comp.l")
	(system::exec-module-init "builtins" "comp/builtins.l")
	(in-package "LISP")
	(import '(comp:comfile
		  comp:compile-file
		  comp:compile-file-if-src-newer
		  sys:gc
		  sys:alloc
		 ;; unix::exit
		  ))
	)
	(export '(compile comfile compile-file gc alloc runtime))
	(setf (symbol-function 'exit) (symbol-function 'unix::exit))    
;;
;(when (substringp "P" (string-upcase *program-name*))
	(in-package "SYSTEM")
	(system::exec-module-init "par" "l/par.l")
;;

	(in-package "USER")
#+(or :Solaris2 :SunOS4.1 :thread)
	(import '(unix:thr-setconcurrency unix:thr-getconcurrency
		  unix:thr-self unix:thr-setprio unix:thr-getprio unix:thr-create
		  unix:thr-continue unix:thr-kill unix:thr-suspend
		  unix:thr-sigsetmask))
;	) ;; eusp

(setq *debug* nil)

;;
;; load geometric package
;;

(when (or (substringp "G" (string-upcase *program-name*))
	  (substringp "X" (string-upcase *program-name*))
	  (substringp "COMP" (string-upcase *program-name*)))
;;	(format t "Loading geometry modules.~%")
	(sys:alloc 80000)
	(sys:alloc 50000)
	(in-package "GEOMETRY")
#-:SunOS4.1
	(sys::exec-module-init "intersection" nil)
#+:SunOS4.1
	(unless (sys::exec-module-init "intersection" nil)
	  (let ((libeusgeo (concatenate string *eusdir* 
					"SunOS4/lib/libeusgeo.so.0.0")))
	    (when (eq (unix::access libeusgeo) t)
	      (let ((libmod (load libeusgeo :entry nil))
		    (modules `("intersection" "geoclasses" "geopack" "geobody"
			       "primt" "compose" "polygon" "viewing" "viewport"
			       "viewsurface" "hid" "shadow" "bodyrel"
				"dda")))
;		(format t "Buggy SunOS 4.1.x~%")
		(nconc sys::*load-entries*
		       (sys::list-module-initializers libmod modules))
		(sys::exec-module-init "intersection" nil)))))
	(export '(LINE-INTERSECTION  LINE-INTERSECTION3
		 VIEWPORTCLIP  HOMO-VIEWPORT-CLIP HOMO2NORMAL
		 HOMOGENIZE))

        (unless (boundp '*GEOLIB*) ; for SunOS4 with .so bug
	;;(sys::export-all-symbols t)
	)
	(sys::exec-module-init "geoclasses" "geo/geoclasses.l")
	(sys::exec-module-init "geopack" "geo/geopack.l")
	(sys::exec-module-init "geobody" "geo/geobody.l")
	(sys::exec-module-init "primt" "geo/primt.l")
	(sys::exec-module-init "compose" "geo/compose.l")
	(sys::exec-module-init "polygon" "geo/polygon.l")
	(sys::exec-module-init "viewing" "geo/viewing.l")
	(sys::exec-module-init "viewport" "geo/viewport.l")
	(sys::exec-module-init "viewsurface" "geo/viewsurface.l")
	(sys::exec-module-init "hid" "geo/hid.l")
	(sys::exec-module-init "shadow" "geo/shadow.l")
	(sys::exec-module-init "bodyrel" "geo/bodyrel.l")
	(sys::exec-module-init "dda" "geo/dda.l")
;;
;; temporarily prohibit the following import and export, 2000.4.15
;;	(import '(geo::*viewer* geo::*viewing* geo::*viewport*
;;		  geo::*viewsurface* geo::*viewers*))
;;	(export '(*viewer* *viewing* *viewport*
;;		 *viewsurface* *viewers*))
	) ;; eusg

;
;; change package add features
	(in-package "USER")
	(use-package "GEOMETRY")
	(push :geometry *features*)


