;;; exports.l

(list "@(#)$Id$")

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
  ;; type specifiers
  (export '(integer float fixnum number))
  (export '(*print-case* *print-circle* *print-object* *print-structure*
		*print-length* *print-level*
		*readtable* *toplevel* *read-base* *print-base*
		*error-handler* *evalhook* *debug*
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
	  ENTER-CLASS  DEFMETHOD  SEND  SEND-IF-FOUND
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
  (export '(  V+  V++  V-  V.  V*  V.*  V<  V>  VMIN  VMAX
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
  (setq *package* (find-package "UNIX"))
  (lisp:setq (lisp:*package* . lisp:use)
		(lisp:list (lisp:find-package "LISP")))

  ;; unix::READ  cannot be exported since lisp defines its own READ

  (lisp:export '(  KILL  SIGNAL  #| EXIT |# GETPID 
	  UREAD  WRITE  UCLOSE
	  IOCTL  LSEEK  MALLOC  FREE  SOCKET  BIND  CONNECT  LISTEN
	  ACCEPT  SENDTO  RECVFROM  GETPEERNAME))

;; not supported by vxworks
  (lisp:export '(  PTIMES  RUNTIME  LOCALTIME  ASCTIME  GETITIMER
	  SETITIMER  GETRUSAGE  GETPAGESIZE ALARM))

  (lisp:export '(  WAIT  FORK  GETPPID  GETPGRP  SETPGRP  GETUID
	  GETEUID  GETGID  GETEGID  SETUID  SETGID  MKNOD  FCNTL
	  MKDIR RMDIR
	  IOCTL_  IOCTL_R  IOCTL_W  IOCTL_WR  DUP  DUP2
	  SYSTEM  GETWD  GETENV  SLEEP  SYSERRLIST  PAUSE  ISATTY
	  LINK  UNLINK  RENAME  ACCESS  FLOCK  STAT  CHDIR  CHMOD  CHOWN
	  PIPE  SELECT  SELECT-READ-FD  GETHOSTNAME  GETHOSTBYNAME
	  GETHOSTBYADDR  GETNETBYNAME  GETPROTOBYNAME  GETSERVBYNAME))

  (lisp:export '( VFORK  EXEC  GETPRIORITY  SETPRIORITY
		  PUTENV   USLEEP  UALARM))

  (lisp:export '(  MSGGET  MSGSND  MSGRCV  MSGCTL))

  (lisp:export '(  VALLOC  MMAP  MUNMAP  VADVISE))
  (lisp:export '(  UNAME))
  (lisp:export '(  DBM-OPEN  DBM-CLOSE  DBM-FETCH  DBM-STORE	 DBM-DELETE
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

  (export '( GC  GCTIME
	  *GC-MERGE* *GC-MARGIN*
	  ALLOC  NEWSTACK  RECLAIM  RECLAIM-TREE
	  OBJECT-SIZE  MEMORY-REPORT  CLEAR-MEMORY-REPORT
	  ROOM  LIST-ALL-CHUNKS  LIST-ALL-INSTANCES  ADDRESS  PEEK  POKE
	  LIST-ALL-REFERENCES  LIST-ALL-CATCHERS  LIST-ALL-BINDINGS
	  LIST-ALL-SPECIAL-BINDINGS  LIST-ALL-CLASSES))


#|
  RAW-FILL  RAW-POSITION  RAW-FIND  RAW-COUNT  UNIVERSAL-REMOVE
  RAW-REMOVE-DUPLICATES  RAW-DELETE  RAW-SUBSTITUTE
  RAW-NSUBSTITUTE  VECTOR-REPLACE
|#


(in-package "LISP")
(export '(*machine* *os-version* *eusdir* *eus-help-directory*
		  *unix-package* *lisp-package* *system-package*
		  *user-package* *keyword-package*
		  *symbol-input* *symbol-output*))

(progn
	(proclaim
	    '(special lisp:*machine* 
		      lisp:*os-version*
		      lisp:*eusdir*
		      lisp:*package*
		      lisp:*eus-help-directory*)) )

(in-package "USER")

