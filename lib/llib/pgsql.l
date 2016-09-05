;;;;****************************************************************
;;;; pgsql.l -- Postgres relational database interface
;;;;Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;
;;; Loading this file creates the PQ package, which defines foreign
;;; functions into libpq.so and the pgsql class.  "libpq.so" is assumed
;;; under "/usr/local/pgsql/lib/".
;;;
;;; General notes on the use of Postgres:
;;; You must be registered as a valid postgres user. Use 'createuser' command.
;;; You must have at least one accessible database. Use 'createdb'command.
;;; To get libpq to behave as expected, several environment variables should be
;;; set properly.  They are, PGROOT, PGLIB, PGPORT, PGDATABASE, PGUSER,
;;; PGPASSWORD, PGDATESTYLE, etc.
;;;
;;; Connecting to the Postgres database:
;;;	Instantiate pq:pgsql with proper arguments.  In most cases,
;;;	you just want to specify the database name and the user name.
;;;	If you don't know, just trust the defaults, namely
;;;	(instance pq:pgsql :init) might be ok to make a connection.
;;; Synchronous data transfer:
;;;	There are the synchronous and asynchronous interface in libpq.so.
;;;	Synchronous transfer is easier.  You just send SQL commands by
;;;	:exec method of the pgsql object, and a result is returned.
;;;	(send db :exec "select typname,oid from pg_type order by oid")
;;;	will give you a list of all data types defined in your database.
;;; Asynchronouse database access:
;;;	For the asynchronouse interface, you have to define a function or
;;;	method to receive the query result as the first argument. Let's 
;;;	assume the receiver function is 'print'.  Then a query should be
;;;	issued by the :sendQuery method with the receiver function name
;;;	as the second argument.
;;;	(send db :sendQuery "select oid from pg_type" 'print)
;;; Type conversion
;;;	Postgres database stores data in a variety of forms internally,
;;;	but every data item transferred between the database and the client
;;;	is always converted to the string format. Thus, integer 1234 is "1234",
;;;	and a symbol 'SYMBOL is "symbol".  But, of course, since we want to
;;;	access a database to store lisp data, they should be handled as
;;;	lisp integers and lisp symbols.
;;;	I found the datatype information is stored in the pg_type table.
;;;	When we get data from a table, we can also retrieve the oid (object id)
;;;	attributed to each field.  By looking up pg_type table with the oid,
;;;	we can know the datatype name, such as integer, character, date, etc.
;;;	But postgresql has no symbols!  We can use the 'name' type instead, 
;;;	but still there is incoherency to use it as lisp symbol type, since
;;;	there is no escapes (vertical bar and backslash) and lower-case to
;;;	upcase conversion.  I mean if we use the 'intern' function to
;;;	change the 'name' object to symbol, it becomes a symbol with the
;;;	lower case print-name.  Do we call string-upcase before interning?
;;;	Usually it works, but not always, because escapes are ignored.
;;;	So I defined input and output function for Postgres in 'symbol_io.c'.
;;;	There is also a Makefile for it.  Make symbol_io.so and copy it
;;;	to /usr/local/pgsql/lib.  Invoke psql, and type "\i symbol_io.sql",
;;;	which makes postgres to load the lisp_symbol_io functions, and
;;;	and define the symbol type.
;;;	Call make-type-hashtab function once before any other database retrieval
;;;	for the faster type look-up.
;;;	Then, every data transfered from the database is converted properly.
;;;	Currently, symbol, int, float, char (string), date, time, datetime
;;;	are coerced to corresponding lisp objects. Other unknown type data
;;;	are represented by strings.

;; The following codes put in another file will load this database module,
;; creates the *type-hashtab*, and reads the type list.
;;
;;(load "pgsql")
;;(in-package "USER")
;;(unless (boundp 'db)
;;   (setq db (instance pq:pgsql :init) ))
;;(send db :exec "select * from family")
;;(pq:make-type-hashtab db)
;;(setq types (send db :exec "select typname,oid from pg_type order by oid"))
;;

;; time package is needed.
(let ((*package* (find-package "LISP")))
   (require :time "time")	;;required for date, time and datetime types.
   )

(unless (find-package "PQ") (make-package "PQ"))
(in-package "PQ")

(export '(pgsql query escape-quote table-fields table-attributes
	table-pkey
	tables
	select update-record insert-record insert-record2
	delimit-list delete-record
	record-count))

;****************************************************************
; libpq.so foreign functions
;****************************************************************

#+:linux
(setq *libpq* (cond
               ((probe-file "/usr/lib/libpq.so") (load "/usr/lib/libpq.so"))
               ((probe-file "/usr/lib/x86_64-linux-gnu/libpq.so") (load "/usr/lib/x86_64-linux-gnu/libpq.so"))
               ((probe-file "/usr/lib/i386-linux-gnu/libpq.so") (load "/usr/lib/i386-linux-gnu/libpq.so"))
               (t nil)))
#+:cygwin
(setq *libpq* (cond
               ((probe-file "/usr/bin/cygpq.dll") (load "/usr/bin/cygpq.dll"))
               (t nil)))

(when *libpq*
(defforeign setdbLogin *libpq* "PQsetdbLogin"
	() (:foreign-string 4436))
;; sizeof(PGconn)=4436
;; sizeof(PGresult)=92

(defforeign finish *libpq* "PQfinish" (:string) :integer)
(defforeign pqreset *libpq* "PQreset" (:string) :integer)
(defforeign pqdb *libpq* "PQdb" (:string) (:foreign-string))
(defforeign pquser *libpq* "PQuser" (:string) (:foreign-string))
(defforeign pqpass *libpq* "PQpass" (:string) (:foreign-string))
(defforeign pqhost *libpq* "PQhost" (:string) (:foreign-string))
(defforeign pqport *libpq* "PQport" (:string) (:foreign-string))
(defforeign pqtty *libpq* "PQtty" (:string) (:foreign-string))
(defforeign pqoptions *libpq* "PQoptions" (:string) (:foreign-string))
(defforeign pqstatus *libpq* "PQstatus" (:string) :integer)
(defforeign errorMessage *libpq* "PQerrorMessage" (:string) (:foreign-string))
(defforeign backendPID *libpq* "PQbackendPID" (:string) :integer)
(defforeign pqexec *libpq* "PQexec" (:string :string) :integer)
(defforeign resultStatus *libpq* "PQresultStatus" () :integer)
(defforeign resultErrorMessage *libpq* "PQresultErrorMessage" (:string)
  (:foreign-string))
(defforeign ntuples *libpq* "PQntuples" (:string) :integer)
(defforeign nfields *libpq* "PQnfields" (:string) :integer)
(defforeign binarytuples *libpq* "PQbinaryTuples" (:string) :integer)
(defforeign fname *libpq* "PQfname" (:string :integer) (:foreign-string))
(defforeign fnumber *libpq* "PQfnumber" (:string :string) :integer)
;; ftype returns the field type associated with the given field index.
;; The integer returned is an internal coding of the type. 
;; Field indices start at 0.
(defforeign ftype *libpq* "PQftype" (:string :integer) :integer)
(defforeign fsize *libpq* "PQfsize" (:string :integer) :integer)
(defforeign fmod *libpq* "PQfmod" (:string :integer) :integer)
(defforeign getvalue *libpq* "PQgetvalue" (:string :integer :integer)
		(:foreign-string))
(defforeign getlength *libpq* "PQgetlength" (:string :integer :integer)
		:integer)
(defforeign cmdStatus *libpq* "PQcmdStatus" (:string) (:foreign-string))
(defforeign oidStatus *libpq* "PQoidStatus" () (:foreign-string))
(defforeign clear *libpq* "PQclear" () :integer)

;; Asynchronous interface
(defforeign sendQuery *libpq* "PQsendQuery" (:string :string) :integer)
(defforeign getResult *libpq* "PQgetResult" (:string) :integer)
						;; (:foreign-string 92))
(defforeign consumeInput *libpq* "PQconsumeInput" (:string) :integer)
(defforeign isBusy *libpq* "PQisBusy" (:string) :integer)
(defforeign socket *libpq* "PQsocket" (:string) :integer)


;; Large objects
;; Oid lo_creat(PGconn *conn, int mode)
;; Oid lo_import(PGconn *conn, text *filename)
;; Oid lo_export(PGconn *conn, Oid lobjID, text *filename)
;; int lo_open(PGconn *conn, Oid lobjId, int mode, ...)
;; int lo_write(PGconn *conn, int fd, char  *buf, int len)
;; int lo_lseek(PGconn *conn, int fd, int offset, int whence)
;; int lo_close(PGconn *conn, int fd)
(defforeign lo_creat *libpq* "lo_creat" (:string :integer) :integer)
(defforeign lo_import *libpq* "lo_import" (:string :string) :integer)
(defforeign lo_export *libpq* "lo_export" (:string :integer :string) :integer)
(defforeign lo_open *libpq* "lo_open" (:string :integer :integer) :integer)
(defforeign lo_write *libpq* "lo_write" (:string :integer :string :integer) :integer)
(defforeign lo_read *libpq* "lo_read" (:string :integer :string :integer) :integer)
(defforeign lo_lseek *libpq* "lo_lseek" (:string :integer :integer :integer) :integer)
(defforeign lo_close *libpq* "lo_close" (:string :integer) :integer)
(defforeign lo_unlink *libpq* "lo_unlink" (:string :integer) :integer)
) ;; when *libpq*
;; mode bits for lo_creat, lo_open
;; #define INV_WRITE               0x00020000
;; #define INV_READ                0x00040000
(defconstant INV_WRITE   #x00020000)
(defconstant INV_READ    #x00040000)

(defconstant SEEK_SET 0)
(defconstant SEEK_CUR 1)
(defconstant SEEK_END 2)

(defparameter *pgsql-readtable* (copy-readtable))
;;
;; postgreSQL represents array by enclosing elements with curly braces
;; and by delimiting with commas. Eus reads an array as a list.
;; You might want to coerce the list into a vector.
;;
(set-syntax-from-char #\{ #\lparen *pgsql-readtable*)
(set-syntax-from-char #\} #\rparen *pgsql-readtable*)
(set-syntax-from-char #\, #\space *pgsql-readtable*)

(defvar *pgsql-debug* nil)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; datestyle= ISO	"2000-03-01 10:30:00+09"
;; datestyle= SQL	"03/01/2000 10:30:00.00 JST"
;; datestyle= Postgres	"Wed Mar 01 10:30:00 2000 JST"
;; datestyle= European	"Wed 01 Mar 10:30:00 2000 JST"
;; datestyle= NonEuropean	"Wed Mar 01 10:30:00 2000 JST"
;; datestyle= German	"01.03.2000 10:30:00.00 JST"
;; datestyle= US	"01.03.2000 10:30:00.00 JST" ???
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(defun pq-handler (db)
  (format t  "pq-handler db=~s~%" db)
  (send db :consume))

(defun pgsql-field (str)
   (let ((*readtable* *pgsql-readtable*))
      (read-from-string str nil nil)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; pg_type typically catalogs the following types
;; (oid typname typelem typlen)
;; Note that if typelem==0, then it is a basic (primitive) type,
;; otherwise it is an array type.
;;

#|
((16 "bool" 0 1)
 (17 "bytea" 0 -1)
 (18 "char" 0 1)
 (19 "name" 18 32)
 (20 "int8" 0 8)
 (21 "int2" 0 2)
 (22 "int2vector" 21 32)
 (23 "int4" 0 4)
 (24 "regproc" 0 4)
 (25 "text" 0 -1)
 (26 "oid" 0 4)
 (27 "tid" 0 6)
 (28 "xid" 0 4)
 (29 "cid" 0 4)
 (30 "oidvector" 26 64)
 (32 "SET" 0 -1)
 (210 "smgr" 0 2)
 (600 "point" 701 16)
 (601 "lseg" 600 32)
 (602 "path" 0 -1)
 (603 "box" 600 32)
 (604 "polygon" 0 -1)
 (628 "line" 701 32)
 (629 "_line" 628 -1)
 (700 "float4" 0 4)
 (701 "float8" 0 8)
 (702 "abstime" 0 4)
 (703 "reltime" 0 4)
 (704 "tinterval" 0 12)
 (705 "unknown" 0 -1)
 (718 "circle" 0 24)
 (719 "_circle" 718 -1)
 (790 "money" 0 4)
 (791 "_money" 790 -1)
 (829 "macaddr" 0 6)
 (869 "inet" 0 -1)
 (650 "cidr" 0 -1)
 (1000 "_bool" 16 -1)
 (1001 "_bytea" 17 -1)
 (1002 "_char" 18 -1)
 (1003 "_name" 19 -1)
 (1005 "_int2" 21 -1)
 (1006 "_int2vector" 22 -1)
 (1007 "_int4" 23 -1)
 (1008 "_regproc" 24 -1)
 (1009 "_text" 25 -1)
 (1028 "_oid" 26 -1)
 (1010 "_tid" 27 -1)
 (1011 "_xid" 28 -1)
 (1012 "_cid" 29 -1)
 (1013 "_oidvector" 30 -1)
 (1014 "_bpchar" 1042 -1)
 (1015 "_varchar" 1043 -1)
 (1016 "_int8" 20 -1)
 (1017 "_point" 600 -1)
 (1018 "_lseg" 601 -1)
 (1019 "_path" 602 -1)
 (1020 "_box" 603 -1)
 (1021 "_float4" 700 -1)
 (1022 "_float8" 701 -1)
 (1023 "_abstime" 702 -1)
 (1024 "_reltime" 703 -1)
 (1025 "_tinterval" 704 -1)
 (1027 "_polygon" 604 -1)
 (1033 "aclitem" 0 8)
 (1034 "_aclitem" 1033 -1)
 (1040 "_macaddr" 829 -1)
 (1041 "_inet" 869 -1)
 (651 "_cidr" 650 -1)
 (1042 "bpchar" 0 -1)
 (1043 "varchar" 0 -1)
 (1082 "date" 0 4)
 (1083 "time" 0 8)
 (1182 "_date" 1082 -1)
 (1183 "_time" 1083 -1)
 (1184 "timestamp" 0 8)
 (1185 "_timestamp" 1184 -1)
 (1186 "interval" 0 12)
 (1187 "_interval" 1186 -1)
 (1231 "_numeric" 1700 -1)
 (1266 "timetz" 0 12)
 (1270 "_timetz" 1266 -1)
 (1560 "bit" 0 -1)
 (1561 "_bit" 1560 -1)
 (1562 "varbit" 0 -1)
 (1563 "_varbit" 1562 -1)
 (1700 "numeric" 0 -1)
 (18722 "symbol" 0 -1)
 (18725 "_symbol" 18722 -1))
|#


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defclass pgsql :super propertied-object
	:slots (connection socket-fd
		fields records notify types
		ntuples nfields	;number of tuples and fields
		type-hashtab
		type-conversion
		oid
		))

(defmethod pgsql
 (:init (&key (host "localhost") (port 0) (options 0) (tty 0)
		(dbname (cond ((unix:getenv "PGDATABASE"))
			      (t (unix:getenv "USER"))))
		(user (cond ((unix:getenv "PGUSER"))
			    (t (unix:getenv "USER"))))
		(pass 0))
    (setq connection
	  (setdblogin host port options tty dbname user pass))
    (cond ((zerop (pqstatus connection))
	   (if *debug*
	       (warning-message 4
		 ";; Postgres connection to ~a:~a dbname=~a user=~a~%"
		 (pqhost connection) (pqport connection)
		 (pqdb connection) (pquser connection))  ))
	  (t (error ";; Postgres connection failed due to ~a~%"
		(errorMessage connection))
	     (return-from :init nil))
	  )
    (send self :name (pqdb connection))
    (setq *db* connection)
    (setq type-hashtab (instance hash-table :init :size 100))
    (send self :make-type-hashtab)
    ;; (print connection)
    (setq socket-fd (socket connection)) 
    (send *top-selector* :add-port socket-fd 'pq-handler self)
    (send self :exec "set datestyle to 'ISO'")
    (setq type-conversion t)
    self)
 (:finish ()
    (finish connection)
    (send *top-selector* :remove-port socket-fd)
    (setq connection nil))
 (:dbname () (pqdb connection))
 (:user () (pquser connection))
 (:host () (pqhost connection))
 (:port () (pqport connection))
 (:password () (pqpass connection))
 (:type-conversion (flag) (setq type-conversion flag))
 (:types () types)
 (:oid () oid)
 (:make-type-hashtab ()
   (send type-hashtab :clear)
   (let ((type-list))
      (dolist (tp (send self :exec
	   "select oid,typname,typelem,typlen from pg_type where typtype='b'  order by oid"))
	  ;; typtype='b' means a basic type.
	  ;; typelen= -1 if array size is variable.
	  (let ((*package* *keyword-package*))
		 (push (mapcar #'read-from-string tp) type-list)))
      (dolist (tp (nreverse type-list))
	 (setf (gethash (car tp) type-hashtab) (cdr tp)))
      ))
 (:type-name (id)
   (let ((tp  (gethash id type-hashtab)))
      (cond ((null tp) ':char)
	    ((zerop (second tp))  (first tp))
	    ;; ((equal id 19) ':symbol)	;name
	    ;; I don't think it is a good idea to return the element type
	    ;; for an array type, but what else to do now?
	    ;; (t   (send self :type-name (second tp)))
	    (t  :array)
	    )
   ) )
 (:records () records)
 (:fields () fields)
 (:clear () (setq records nil))
 (:notify (&rest x) (setq notify x))
 (:sendquery (query &rest x)
    (setq records nil)
    (setq notify x)
    (sendquery connection query))
 (:consume ()
    ;; result data is available
    (consumeinput connection)
    (unless (zerop (isbusy connection))
	(error "db ~s is still busy after consumeInput" self))
    (send self :process-result (getResult connection))
    ;; data records are prepared
    (let ((func (car notify)) (args (cdr notify)))
       (if (functionp func)
	   (apply func records args)
	   (send* func (car args) records (cdr args))) )
    )
 (:getfields (result)
    (setq fields nil)
    (dotimes (i (nfields result)) (push (fname result i) fields))
    (nreverse fields))
 (:ntuples () ntuples)
 (:nfields () nfields)
 (:getvalues (result)
    (let ((fields) (r) (rec))
       (setq records nil)
       (setq ntuples (ntuples result))
       (setq nfields (nfields result))
       (setq types (instantiate vector nfields))
       (dotimes (i nfields)
	    (setf (aref types i)  (send self :type-name  (ftype result i))))
	;; (format t "tuples=~d fields=~d~%" ntuples nfields)
	;; (print types)
       (dotimes (j ntuples)
	  (setq rec nil)
	  (dotimes (i nfields)
		(setq r (getvalue result j i))
		(setq r
		    (if type-conversion
		        (case (aref types i)
			 ((:text :char)	;copy is necessary
				;because the result passed from postgress
				;is taken in libpq's memory.
				     (copy-seq r))
			 (:date (read-ISO-date r))
			 (:time (read-ISO-time r))
			 ((:datetime :timespan :timespan)
				     (read-ISO-datetime  r))
			 (:array (pgsql-field r)) ;; an array is read as a list
			 (t (pgsql-field  r)))
			(copy-seq r))
			 )
		(push r rec))
	  (push (nreverse rec) records))
       (send self :getfields result)
       (clear result)
       (setq result nil)	;result is still a foreign string
       (nreverse records))
       )
 (:process-result (stat)
    (case (resultstatus stat)
	(0  (warning-message 4 ";; empty query~%") nil)
	(1  
	    (if *debug* (warning-message 4 ";; pgsql OK~%"))
	    (setq oid (read-from-string 
		(oidStatus stat #|(make-foreign-string stat 92)|# )
		nil nil))
	    (clear stat)
	    oid )
	(2  (send self :getvalues (make-foreign-string stat 92)))
	((3 4) (warning-message 5 ";; copy in/out started~%") nil)
	(5 (warning-message 5 ";; db bad response~%") nil)
	(6 (error  ";; db non fatal error") )
	(7 (error  ";; db fatal error"))
	))
 (:exec (query) (send self :process-result (pqexec connection query)))
 )

;; large object
;; The following piece of code will make a copy of "file-1".
;; (setq oid (send db :lo-import "file-1"))
;; (send db :lo-export oid "file-2"))
;;
(defmethod pgsql
 (:lo-creat (&optional (mode (logior INV_READ INV_WRITE)))
     (lo_creat connection mode))
 (:lo-import (fname)
    (let ((loid))
        (pqexec connection "begin")
        (setq loid (lo_import connection fname))
        (pqexec connection "end")
 	loid))
 (:lo-export (loid fname)
        (pqexec connection "begin")
        (setq loid (lo_export connection loid fname))
        (pqexec connection "end")
 	loid)
 (:lo-open (oid &optional (mode (logior INV_READ INV_WRITE)))
     (lo_open connection oid mode))	;; returns 'fd'
 (:lo-write (fd bytes &optional (len (length bytes)))
     (lo_write connection fd bytes len))
 (:lo-read (fd buf len)
     (lo_read connection fd buf len))
 (:lo-lseek (fd offset &optional (whence SEEK_SET))
     (lo_lseek connection fd offset whence))
 (:lo-close (fd) (lo_close connection fd))
 (:lo-unlink (loid) (lo_unlink connection loid))
 (:lo-test (loid &optional (mode (logior INV_READ INV_WRITE)) &aux f)
     (pqexec connection "begin")
     (unwind-protect
	(setq f (>= (lo_open connection loid mode) 0))
	(pqexec connection "end"))
     f)
 ;;;;;;
 (:lo-put (datum &optional (oid nil))
    (let ((loid) (lofd))
       (pqexec connection "begin")
       (unwind-protect
	   (progn
	       (if (integerp oid)
		   (setq loid oid)
		   (setq loid (lo_creat connection INV_WRITE)))
	;;	(format t "loid=~d~%" loid)
	       (setq lofd (lo_open connection loid INV_WRITE))
	;;	(format t "open fd=~d~%" lofd)
	;;       (if (= lofd 0) (error "cannot open a large object"))
	       (lo_write connection lofd datum (length datum))
	       (lo_close connection lofd))
          (pqexec connection "end"))
       loid))
 (:lo-get (loid)
    (let ((lofd) (buff) (buffs) (rlen 4096))
       (pqexec connection "begin")
       (unwind-protect
	   (progn
	       (setq lofd (lo_open connection loid INV_READ))
	;;       (if (= lofd 0) (error "cannot open a large object"))
	;;	(format t "open fd=~d~%" lofd)
	       (while (= rlen 4096)
		  (setf buff (make-string 4096))
		  (setq rlen (lo_read connection lofd buff 4096))
	;;	(format t "lo_read: rlen=~d datum=~s~%" rlen buff)
		  (if (/= rlen 4096) (setf buff (subseq buff 0 rlen)))
		  (push buff buffs))
	       (lo_close connection lofd))
	  (pqexec connection "end"))
       (apply #'concatenate string (nreverse buffs))))
 )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; (table-fields db table) returns a list of descriptions of fields
;; of the table.  Each description consists of filed-number (1,2,3,...),
;; filed-name and datatype.
(defun table-fields (db table)
   (query db nil
	"select attnum, att.attname, typ.typname
	 from pg_attribute att,  pg_type typ
	 where att.attrelid=(
		select typrelid from pg_type where typname='~a') 
	 and typ.oid=att.atttypid  and attnum>0 order by attnum"
	table)
  )

;; (table-attributes db table) returns a list of table attributes, i.e.,
;; table-name, owner-user,
;; relation-kind, 
;;	'r' = ordinary table,
;;	'i' = index,
;;	'S' = sequence,
;;	'v' = view,
;;	's' = special,
;;	't' = secondary TOAST table 
;; number of fields,
;; flag whether the table has index,
;; flag whether the table has the primary key,
;; and access-list.

(defun table-attributes (db table)
   (car 
   (query db nil
	"select cls.relname, usr.usename, cls.relkind,
		cls.relnatts, cls.relhasindex, cls.relhaspkey, relacl
	 from pg_class cls, pg_user usr
	 where cls.relname='~a' and usr.usesysid=cls.relowner"
	table ))
  )

(defun table-pkey (db table)
  (caar
   (query db nil
	"select attname
	 from pg_attribute
	 where attrelid=(
		select typrelid from pg_type where typname='~a') 
	 and attnum=1
	 order by attnum"
	table)
  ))

;;;;;;;;;;;;;;;;;

(defun escape-quote (str)
   (with-output-to-string (out)
        (dotimes (i (length str))
           (if (eql (char str i) #\') (write-byte #\\ out))
           (write-byte (char str i) out))
        (get-output-stream-string out) ) )


(defun query (db handler &rest sql)
   (setq sql (apply #'format nil sql))
   (if *pgsql-debug* (print sql))
   (if handler
       (send db :sendQuery sql handler)
       (send db :exec sql)))

(defun tables (db)
   (mapcar #'car (query db nil "select * from pg_tables")))

(defun delimit-list (xlist delimiter &optional quotep)
   (let (rlist)
      (dolist (item xlist)
         (push (if quotep
		   (format nil "'~a'" item)
		   (format nil "~a" item))
		rlist)
         (push delimiter rlist))
      (apply #'concatenate string (nreverse (cdr rlist)))))

(defun where (expression)
   (cond ((stringp expression) (format nil "'~a'" expression))
	 ((atom expression) (format nil "~a" expression))
	 ((consp expression)
	  (format nil "(~a)"
	      (delimit-list (mapcar #'where (cdr expression))
		  (format nil " ~a " (first expression)))))
	))


(defun select (db fields table &key where limit limit-offset order-by)
   (query db nil
	"select ~a from ~a ~a ~a ~a"
	(if (consp fields) (delimit-list fields ",") fields)
	(if (consp table) (delimit-list table ",") table)
	(if (and where  (plusp (length where)))
	    (format nil "where ~a " 
		(if (consp where) (where where) where))
	    "")
	(if order-by
	    (format nil "order by ~a" order-by)
	    "")
	(if limit
	    (if limit-offset
		(format nil "limit ~a,~a" limit limit-offset)
		(format nil "limit ~a" limit))
	    "")
   )    )

;; UPDATE table SET column = expression [, ...]
;;     [ FROM fromlist ]
;;     [ WHERE condition ]

(defun update-record (db table field-values &key where)
   (let ((rlist))
      (setq rlist
	(delimit-list
	   (mapcar #'(lambda (fv)
		 (format nil "~a=~a" (car fv)
		     (if (stringp (second fv))
			 (format nil "'~a'" (second fv))
			 (second fv))) )
		 field-values)
	   ", "))
;;      (format t "update ~a set ~a where ~a" table rlist
;;		(where where))
      (send db :exec 
	(if where
	    (format nil "update ~a set ~a where ~a" table rlist
		(where where))
	    (format nil "update ~a set ~a" table rlist)))
      ))


;; INSERT INTO table [ ( column [, ...] ) ]
;;     { VALUES ( expression [, ...] ) | SELECT query }

(defun insert-record (db table field-values)
  (send db :exec (format nil 
	"INSERT INTO ~a (~a) VALUES (~a)"
	table
	(delimit-list (mapcar #'first field-values) ", ")
	(delimit-list (mapcar #'second field-values) ", " t)) )
   )

(defun insert-record2 (db table fields values)
  (send db :exec (format nil 
	"INSERT INTO ~a (~a) VALUES (~a)"
	table
	(delimit-list fields ", ")
	(delimit-list values ", " t)) )
   )


;; DELETE FROM table [ WHERE condition ]

(defun delete-record (db table &key where)
   (send db :exec
      (if where
	  (format nil
		"DELETE FROM ~a where ~a" table (where where))
	  (format nil "DELETE FROM ~a" ))))

;; (record-count db table) returns the number of rows (records)
;; in a table, i.e., the table size.

(defun record-count (db table)
  (caar (select db "count(*)" table)))

(provide :pgsql "@(#)$Id$")

