;;;; httpdb.l
;;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;; Invoked as a CGI program and provides interface
;;;; to PostgreSQL database.


(unless (unix:isatty 0)
   (defun euserror (code msg1 form &optional (msg2))
	  (format *error-output*
		"eus error ~s ~s ~s ~s~%" code msg1 form msg2)
	  (unix::exit 1))

   (setq *error-handler* 'euserror)
   )


(require :pgsql "/usr/local/eus/lib/llib/pgsql.l")
(require :httpcgi "/usr/local/eus/lib/llib/httpcgi.l")
(require :httpfcgi "/usr/local/eus/lib/llib/httpfcgi.l")
(require :crypt "/usr/local/eus/lib/llib/crypt.l")

(defvar db)
(defvar *forms*)
(defvar update-time)
(defvar *table-password*)
(defvar *connection*)
(defvar primary-key)

(defparameter *action* ;; "/fcgi/eusdb.fcgi"
	(escape-tilda (unix:getenv "SCRIPT_NAME")))

(defun collect-arg (forms &optional (f 'field))
    (if (assoc f forms)
	(mapcar #'(lambda (x) (read-from-string (second x)))
		(collect-if #'(lambda (x) (eq (car x) f)) forms))))

(defun escape-string (s)
  (with-output-to-string (out)
    (with-input-from-string (in (format nil "~s" s))
      (let ((ch))
 	(while (not (eql (setq ch (read-char in nil 'eof)) 'eof))
	   (if (eql ch #\") (format out "\\\"") (format out "~c" ch)))
	))
    (get-output-stream-string out)))

;; routines to get definitions in the table_policy

(defun http-db-title (table screen)
  (let ((ttl (caar (pq:select db 'title 'table_policy
		:where (format nil "tablename='~a' and screen='~a'"
			table screen)))  ))
   (if (plusp (length ttl)) (gen (html "<h2>" ttl "</h2>")) )
  ))


(defun http-db-fields (table screen)
  (let ((fields (caar (pq:select db 'fields 'table_policy
		:where (format nil "tablename='~a' and screen='~a'"
			table screen)))  ))
    (cond ((plusp (length fields)) (read-from-string fields))
	  ((setq fields (collect-arg *forms* 'field)) fields)
	  (t  (mapcar #'second (pq:table-fields db table)))))
   )

(defun http-db-links (table screen)
  (let ((links (caar (pq:select db 'links 'table_policy
		:where (format nil "tablename='~a' and screen='~a'"
			table screen)))  ))
    (if (plusp (length links))
	(read-from-string links)
	nil)
     ))

;; create buttons that link to other pages.
;; definition is obtained by http-db-links.

(defun create-buttons (table screen &rest args)
   (let ((links (http-db-links table screen)) (val) (label))
     ;; (format *error-output* "~a~%" links)
     (gen (html (hidden-args table)))
     (dolist (a args)
	(gen (html "<input type=hidden name=" (first a)
		" value=" (second a) ">~%")) )
     (gen "<table border=0>~%")
     (dolist (b links)
	(if (consp b)
	    (setq label (first b) val (second b))
	    (setq val b label ""))
        (gen (html "<tr><td>" label "</td><td>"
		"<input type=submit name=command value='"
		val "'></td></tr>"))
       )
     (gen (html "</table>~%" ))
    )
)


;;;****************************************************************

(defun hidden-args (table)
  (html "<input type=hidden name=database value=" (send db :name) ">~%"
	"<input type=hidden name=user value=" (send db :user) ">~%"
	"<input type=hidden name=host value=" (send db :host) ">~%"
	"<input type=hidden name=port value=" (send db :port) ">~%"
	"<input type=hidden name=table value=" table ">~%"))

(defun db-input-form (table screen initial submit)
   ;; table form of inputs for fields, common form for change, create and search
   (let ((fields  (http-db-fields table screen))
	 (detail))
      ;; (gen "db-input-form table=~s fields=~s id=~s~%"
      ;;		table fields initial)
      (gen-action *action* 'post)
      (gen "<table border=1>~%")
      (setq detail
	   (if initial
	       (car
		  (pq:query db nil
			"select ~a from ~a where ~a='~a'"
			(pq:delimit-list fields ",") table 
			primary-key initial))
		(fill (make-list (length fields)) "")    ) )
      (dolist (x (transpose-list (list fields detail)))
	;; (gen "~s~%" x)
	(gen (html "<tr><td>" (car x) "</td>"
		"<td>"
		(text-input-form (first x) (second x) 54)
		"</td></tr>~%"
		 )) )
      (gen "</table>~%")
      (goback-button)
      (gen (html (input-form 'reset 'clear 'reset)
		(input-form 'submit 'command submit)
		(input-form 'hidden 'record initial)
		(hidden-args table)) )
      (gen "</form>~%")
     ) )


;;****************************************************************

;; table is locked by a password.

(defun authenticated-execute (func &optional (screen 'top))
  (let ((fields (pq:table-fields db *table*))
	(pass (second (assoc 'table-password *forms*)))
	(action-password
	   (caar (pq:select db
		'password "table_policy"
		:where
		   (format nil "tablename='~a' and screen='~a'~%" *table* screen)) )))
     (if (and action-password (plusp (length action-password) ))
	 (cond (pass  ;; pass is given in the command args.
		(cond ((compcrypt pass action-password)
		        (when *connection*
			   (send *connection* :authenticate-password
				pass *table* screen))
			(funcall func))
		      (t
			(password-fail action-password pass))))
	      (*connection*
		 (cond ((send *connection* :password *table* screen)
	                     (funcall func))
		       (t  (db-ask-password 'table-password)) )
		 )
	      (t 
		(db-ask-password 'table-password))
	        ;; (gen (html "<h1>Invalid password to access " *table* "</h1><br>~%"))
		)
	 (funcall func))
	)
  )

(defun authenticated-record-execute (func recid &optional (screen))
  (let ((fields (mapcar #'second (pq:table-fields db *table*)))
	(pass (second (assoc 'record-password *forms*)))
	(scr-pass-name (intern (string-upcase
				(format nil "~a-password" screen))))
	(scr-pass)
	(record-password) (screen-password))
       ;;(gen (html "authenticated record execute, recid=" recid "<br>~%"
       ;;	"fields=" fields "<br>~%"))
	(if (and (member 'password fields)
		(setq record-password (caar
		   (pq:select db 'password *table*
			:where (format nil "~a='~a'" primary-key recid))))
		(> (length record-password) 0) ) ;; ignore null password
	    ;; password is needed
	    (cond (pass  ;; pass is given in the command args.
		(cond ((compcrypt pass record-password)
		        (if *connection*
			   (send *connection* :authenticate-password
				pass *table* recid))
			(funcall func))
		      (t (password-fail record-password pass))))
	        (*connection*
		 (cond ((send *connection* :password *table* recid)
			     ;; Is the password for the record yet authenticated?
	                (funcall func))
		       (t  (db-ask-password 'record-password recid)) )
			 )
	        (t  (db-ask-password 'record-password recid)) )
	    ;; password is not needed
	    ;; Then, is the operation entirely locked by the screen password?
	    (if (and screen
		     (setq screen-password (caar
			   (pq:select db 'password 'table_policy
				:where
				 (format nil "tablename='~a' and screen='~a'"
					*table* screen ))))
		     (> (length screen-password) 0))
		;; screen password is needed
		(cond
		   ((setq scr-pass
			 (second (assoc scr-pass-name *forms*)))
		    (cond
		      ((compcrypt scr-pass screen-password)
			(if *connection*
			   (send *connection* :authenticate-password
				scr-pass *table* scr-pass-name))
			(funcall func))
        	      (t (password-fail screen-password scr-pass))) )
		   (*connection*
		    (cond ((send *connection* :password *table* scr-pass-name)
				(funcall func))
			  (t (db-ask-password scr-pass-name))))
		   (t (db-ask-password scr-pass-name)))
		;; no screen password is needed
	 	(funcall func))

	    )
	)
  )

(defun db-detail (table id &optional (next nil))
  ;;(gen "<h2>detail of the record id=~a of table=~s</h2>~%"  id table)
  (let* ((fields (http-db-fields table 'detail))
	 (ids 
	    (pq:select db primary-key table 
		:where 	(format nil "~a>='~a'" primary-key id)
		:order-by primary-key
		:limit 3) )
	 (record))
    (when (and next (rest ids))
	(setq id (car (second ids)))
	(http-db-title *table* 'detail)
        )
    ;; (gen (html "detail id=" id "/" ids "<br>~%"))
    (setq record
	  (car (pq:select db fields table 
		:where 	(format nil "~a='~a'" primary-key id))))
    (gen (html-table 
		(transpose-list (list fields record))
		:table-option "border=1"))
    (gen-action *action*)
    (create-buttons table 'detail (list 'record id))
    (gen "</form>~%")
    ))


(defun db-change2 ()
  ;;
  (db-input-form 
	*table* 'change *record-id*  'update )
  (gen-action *action* 'post)
  (create-buttons table 'change)
  (gen "</form>~%")
  )


(defun db-change (table id)
  (setq *record-id* id)
  (authenticated-record-execute #'db-change2 *record-id* 'change)
  )

(defun db-update (table id args)
  (let ((fields (mapcar #'cadr (pq:table-fields db table))) (sets)
	(update-query))
    (gen "<h2>update record </h2>~%")
    (setq *record-id* id)
    (setq fields (set-difference fields (list primary-key update-time)))
    (dolist (f fields)
       (if (assoc f args)
	   (push (format nil "~a='~a'" f (qval f args)) sets)))
    (if update-time
        (push (format nil "~a='~a'" update-time (send (now) :iso-string)) sets))
    (setq sets  (pq:delimit-list (nreverse sets) ", "))
    (setq update-query 	(format nil "update ~a set ~a where ~a='~a'"
		table sets primary-key id))
    (format *error-output* "~a~%" update-query)
    (pq:query db nil update-query)
   (gen (html "The record of " primary-key "=" id " has been updated.<br>~%"))
   (db-detail table id)
  ))

;;
;; Insert requires the table-password authentication.
;;

(defun db-insert ()
   (authenticated-execute #'db-insert2 'insert))

(defun db-insert2 ()
   (gen (html "<h2>Click on the do-insert button when data are ready.</h2>~%"))
   (db-input-form *table* 'insert nil 'do-insert) )

(defun db-do-insert (table args)
  (let ((fields (mapcar #'cadr (pq:table-fields db table)))
	(set-fields) (values) (oid) (id) (a) )
    ;; (gen (html "Insert~%" table fields "~%"))
    (dolist (f fields)
       (setq a (assoc f args))
       (when (and a (plusp (length (cadr a))))
	   (push f set-fields)
	   (push (format nil "'~a'" (qval f args)) values)) )
    (setq set-fields  (pq:delimit-list (nreverse set-fields) ", "))
    (setq values (pq:delimit-list (nreverse values) ", "))
    ;; 	(format *cgi-out*
    ;;	    "insert into ~a (~a) values (~a) ~%" table set-fields values)
    (setq oid 
	    (pq:query db nil
		(format nil "insert into ~a (~a) values (~a)"
			*table* set-fields values)))
   (setq id (caar (pq:query db nil
	(format nil "select ~a from ~a where oid=~a"
		primary-key table oid))))
   (db-detail *table* id)
  ))

(defun db-delete2 ()
  (let ((id (qval 'record *forms*)))
     (pq:query db nil
	(format nil "delete from ~a where ~a='~a'"
		*table* primary-key id))
     (terpri *cgi-out*)
     (db-list *table*)
  ) )

(defun db-delete ()
   (setq *record-id*  (xqval 'record *forms* nil))
   (authenticated-execute #'db-delete2 'delete)
  )


;;****************************************************************
;; search and list search results
;;****************************************************************

(defun db-search (table)
   (let ((fields (http-db-fields table 'search)))
      (gen (html "Use '%' for the wildcard letter.<br><p>~%"))
      (db-input-form table 'search nil 'do-search)
      (gen-action *action*)
      (create-buttons table 'search)
      (gen "</form>~%")
    )
 )

(defun db-do-search (table args)
   ;; (format *error-output* "db-do-search~%")
   (gen (html "<h2>" table " search result</h2>~%"))
   (let ((fields (http-db-fields table 'search))
	 (g) (conditions))
      (dolist (f fields)
	(setq g (assoc f args))
	(if (and g (plusp (length (cadr g))))
	    (push (format nil "~a like '~a' " f (sjis2euc (second g)))
		conditions)))
      ;; (gen (html conditions))
      (setq ids (mapcar #'car (pq:query db nil
		"select ~a from ~a where ~a"
		primary-key table (pq:delimit-list conditions " and "))))
      ;; (gen (html "selected id=" ids "<br>~%" ))
      (setq conditions
	    (pq:delimit-list
		(mapcar #'(lambda (x) (format nil "~a='~a'" primary-key x))
			ids)
		" or "))
      (db-list table :condition conditions)
      ))

(defun href (label &rest args)
   (let ((href-args))
     (dolist (a args)
	(push (format nil "&~a=~a" (first a) (second a)) href-args))
     (setq href-args (apply #'concatenate string (nreverse href-args)))
     (html
		"<a href="
		*action*
		"?table=" *table*
		"&database=" (send db :dbname)
		"&host=" (send db :host) 
		"&port=" (send db :port) 
		"&user=" (send db :user)
		href-args
		">" label "</a>")
     ))

(defun sorting-href (fields start)
   (let ((result))
      (dolist (f fields)
         (push (href f '(command list) (list 'sort f)
			(list 'list start) '(count 100))
		result))
      (nreverse result)))

(defun db-list (table
		&key (condition t) (start 0) (count 100) (sort primary-key))
  ;; (gen (html "db-list start=" start " count=" count "<br>~%"))
  (let ((fields (http-db-fields table 'list)) 
	(selection) (rows) (nrows))
;;     (gen (html "condition= " condition  "<br>~%primary-key= " primary-key " ~%"
;;		"sort=" sort "<br>~%"))
     (gen (html "Click on " primary-key " to see the detail, to change or to delete the record.~%<br>"
	"Click on a list header for sorting.<br><p>~%"))
;;     (gen "list: condition=~s sort=~s count=~s start=~s fields=~s table=~s~%"
;;		condition sort count start fields table)
     (setq selection
	(cond ((eq condition t)
		    (pq:select db fields table
			:order-by sort
			:limit count
			:limit-offset start))
	      ((null condition) nil)
	      (t  (pq:select db fields table
			:where  condition
			:order-by sort
			:limit count
			:limit-offset start)) )
	 )
;;     (gen (html "selection= " selection "~%"))
;;     (gen (html "condition=" condition "<br>selection=" selection "<br>~%"))
;;     (gen (html "List of " table "~%<br>condition=" condition "<br>~%"))
     (setq nrows (send db :ntuples))
     (gen "~s records are selected out of total ~s records<br>~%" nrows 
		(pq:record-count db table))
     (gen-action *action*)
     (create-buttons table 'list
		(list 'sort sort)
		(list 'list start)
		(list 'list-next (+ start count))
		(list 'list-previous (max 0 (- start count)))
		(list 'count count) ) 
     (dolist (sel selection)
	(push (list*
		   (format nil
			   "<input type=checkbox name=selection value=~a>~%"
			   (car sel))
		   (href (car sel) '(command detail) (list 'record (car sel)) )
		   (cdr sel))
	      rows ))
     (gen  (html-table (nreverse rows)
		:table-option "border=1"
		:heading (cons "select" (sorting-href fields start))))
     (goback-button)
     (menu-form 'menu '((item1 matsui) (item2 ruriko) (item3 toshihiro)))
     (gen "</form>~%")
     (terpri *cgi-out*)
     )
)



;;****************************************************************
;; download
;;****************************************************************

(defun db-download (table &optional (condition t) )
   (let ((selection) (b) 
	 (fname (format nil "~a~d.csv" table (unix::getpid)))
	 (fields (http-db-fields table 'download))
	 (http-host (unix:getenv "HTTP_HOST")))
     (setq selection
	(cond ((eq condition t)
		    (pq:select db fields table
			:order-by primary-key))
	      ((null condition) nil)
	      (t  (pq:select db fields table
			:where  condition
			:order-by primary-key)) )
	 )
     (with-open-file (out (merge-pathnames 
				"/home/httpd/html/download/"  fname)
			:direction :output)
	(dolist (a selection)
	   (while a
	      (setq b (pop a))
	      (format out "~a~a"
		   (cond ((derivedp b interval-time) (send b :iso-date-string))
			 ((stringp b) (euc2sjis b))
			 (t b))
		   (if a "," "")))
	   (terpri out)))
     ;; (unix:system (format nil "tar cf - ~a | gzip >~a.tar.gz" fname fname))
     (gen (html "<h1>Download " table "</h1><br>"
	"<a href=\"http://" http-host "/download/" fname "\">~% "
	"<li>download " fname "</a><br>~%"
	) )
  ) )

;;****************************************************************
;; E-mail
;;****************************************************************

(defun db-mail (table receivers)
   ;; (gen (html "mail<br> " receivers "<br>~%"))
   (let ((ids) (email-name) (email-addresses) (names))
      (cond ((eql receivers 'all)
		(setq email-name
		     (pq:select db '(email name) table)))
	    (t
	      (setq ids (collect-arg receivers 'selection))
	      ;; (gen (html wcondition "<br>~%"))
	      (setq email-name
		    (pq:select db '(email name) table
			:where   (pq:delimit-list
				(mapcar #'(lambda (x) (format nil "id=~a " x)) ids)
				" or ")))))
      (setq names (mapcar #'second email-name))
      (setq email-addresses (mapcar #'car email-name))
      (setq email-addresses  (pq:delimit-list email-addresses ", "))
      (gen
	 "<h1>Email transmission</h1><br>Clicking the following line will send Email to ~a <br>~%"
	 (euc2sjis (pq:delimit-list names ", ")))
      (gen "<a href=\"mailto:~a\"> ~a</a><br>~%"
	 email-addresses email-addresses)))


;;****************************************************************
;; db-login
;;	input dbname, host name, user name, etc., and connect to the db.
;;	the next screen is selection of a table in the database.
;;****************************************************************

;;****************************************************************
;; db-top
;;****************************************************************

(defun db-top (table)
   (gen-action *action* 'post)
   (create-buttons table  'top)
   (gen "</form>~%"))

(defun db-login ()
   (gen-action *action* 'post)
   (gen (html "<h1>Login PostgreSQL database</h1>~%"))
   (gen  (html-table
	(list
	   (list "host computer"
		 (input-form 'text 'host (unix:getenv "HTTP_HOST") 50))
	   (list "port"
		 (input-form 'text 'port 5432 16))
	   (list "database"
		 (input-form 'text 'database "" 50))
	   (list "user"
		 (input-form 'text 'user "" 50))
	   (list "password"
		 (input-form 'password 'db-password "" 50)))
	 ))
   ;; (create-buttons 'table_policy 'login) cannot apply, since database
   ;; is not yet connected at this stage.
   (gen (html
		"<input type=hidden name=table value=table_policy><br>~%"
		"<input type=submit name=command value=table><br>~%"
		"<input type=submit name=command value=list><br>~%"
		"<input type=reset name=clear value=reset>"
		"</form>~%"))

   )


;;****************************************************************
;; table assistant
;;****************************************************************

(defun db-table ()
  (let ((tables) (x) (attr))
    (gen "<h1>Tables and fields</h1>~%")
    (setq tables
	(pq:select db '(typname typrelid) 'pg_type
	    :where "typname in (select tablename from pg_tables) and typrelid>100000"))
    ;; (gen "tables=~a~%" tables)
    (dolist (tab tables)
	(setq attr (pq:table-attributes db (first tab)))
	(setq *table* (first tab))
	(push (list
	   (href (first tab) '(command table-detail))
	   (second attr)	;owner
	   (fifth attr)
	   (sixth attr)		;pkey
	   (mapcar #'second (pq:table-fields db (car tab)))
	   (seventh attr))	;acl
	   x)
	)
    (gen
	(html-table x
	   :table-option "border=1"
	   :heading '("table" "owner" "index" "primary" "fields" "permissions"))))
    (gen-action *action*)
    (gen (html 
	   "<input type=submit name=command value=create-table>~%"
	   (hidden-args nil)
	   "</form>~%"))
  )


(defun db-table-detail (table)
   ;; list columns of a table
   (let ((fields (pq:table-fields db table))
	 (attr (pq:table-attributes db table)))
      (gen (html "<h2>Attributes of table " table "</h2>~%"
	"Choose fields you want see, put where, limit, or order by 
	clauses in the text box, and go(list)!<br>~%"))
      (gen-action *action*  'post)
      (gen (html (hidden-args table) "~%"))
      ;; (gen (html "Access permissions:" (seventh attr) "~%"))
      (setq fields
	   (mapcar #'(lambda (x) (list
	        (format nil 
		  "<input type=checkbox name=field value=~a>" (second x))
	        (first x) (second x)  (third x)))
	      fields))
      (gen 
	(html-table fields
		:table-option "border=1"
		:heading '(select id field-name type)) )
      (gen (html "condition <input type=text name=condition size=60><br>"
		"<input type=submit name=command value=list>"
		"<input type=reset name=clear value=clear><br>~%"
		"</form>~%"))
   ) )


(defun db-create-table ()
   (let ((fields (collect-arg *forms* 'field)))
     (gen (html "<h1>create table</h1>~%" ))
     (gen-action *action*  'post)
     (gen (html
	(html-table
	  (list* (list 'tablename
		   (input-form 'text 'tablename (qval 'tablename *forms*)))
		(list 'primary-key (input-form 'text 'primary-key))
		(mapcar #'(lambda (x) (list 'field (input-form 'text x x)))
			fields) )
		)
	(input-form 'reset  'reset 'reset)
	(input-form 'submit 'command 'create-field)
	(input-form 'submit 'command 'create-tablex)  ))
      (dolist (f fields)
        (gen (html (input-form 'hidden 'field  f))))
      (gen  "</form>~%" )
   ) )


(defun db-create-field ()
  (let ((tablename (qval 'tablename *forms*))
	(fields (collect-arg *forms* 'field)))
     (gen (html "tablename=" tablename "<br>~%"))
     (gen (html "<h1>create a field</h1>~%" ))
     (gen-action *action*  'post)
     (gen (html
	(html-table
	  (list
	     (list 'fieldname (input-form 'text 'field))
	     (list 'type (input-form 'text 'type))
	     (list 'null (input-form 'checkbox 'null))
	     (list 'unique (input-form 'checkbox 'unique))
	     (list 'constraint (input-form 'text 'constraint))
	     (list 'default (input-form 'text 'default)))
	  :table-option "border=1")
	;; (input-form 'submit 'command 'do-create-field)
	(input-form 'reset 'reset 'reset)
	(input-form 'submit 'command 'create-table)
	(input-form 'hidden 'tablename tablename))
	)
     (dolist (f fields)
       (gen (html (input-form 'hidden 'field  f))))
     (gen (html "</form>"))
     )
   )


;;****************************************************************
;; PASSWORD handling
;; A table can have a password for the operations of insert and delete.
;; Each record may have a password for changing.
;;****************************************************************
;; 
(defun password-fail (def input)
   (gen (html "<h1>Password is wrong.</h1>~%"
		"The correct password is " " *** "	;; def
		", but you entered " "**** "		;; input
		".<br>~%"))
   )

(defun db-ask-password (kind &optional (record-id))
   (gen (html
	"<h2>Enter password to access "
	(if (eql kind 'record-password)
	    (html "the record of " primary-key "=" record-id)
	    (html *table* " table"))
	"</h2><p>~%"))
   (gen-action *action*  'POST) 
   (dolist (f *forms*)
	(gen (html (input-form 'hidden (first f) (second f)))))
   (gen (html
	(html-table
	    (list
		(list "password"
			(input-form 'password kind)))
	    )
	(input-form 'reset 'reset 'reset)
	;; (input-form 'submit 'command 'authenticate)
	(input-form 'hidden 'table *table*)
	(input-form 'hidden 'record record-id)))
    (gen "</form>~%"))

(defun db-change-password ()
     (gen (html "<h1>Change password</h1><p>~%" ))
     (gen-action *action*  'post)
     (gen (html
	(html-table
	    (list
		(list "current password"
			(input-form 'password 'current-password))
		(list "new password"
			(input-form 'password 'new-password))
		(list "retype new pass"
			(input-form 'password 'retype-new-password)) )
	    )
	(input-form 'reset 'reset 'reset)
	(input-form 'submit 'command 'update-password)
	(hidden-args *table*)
	(input-form 'hidden 'record (qval 'record *forms*))
	"</form>~%")))

(defun db-update-password ()
   (gen (html
	"<h1>Update password</h1><p>~%" ))
   (let ((curpass (qval 'current-password *forms*))
	 (newpass (qval 'new-password *forms*))
	 (retypepass (qval 'retype-new-password *forms*))
	 (recpass))
     (setq *record-id* (xqval 'record *forms* nil))
     (setq recpass (caar (pq:select db 'password *table*
		:where (format nil "~a='~a'" primary-key *record-id*))))
     #|
     (gen (html "*table*=" *table*
		"<br>record-id=" *record-id*
		"<br>recpass=" recpass " " (length recpass) (send (class recpass) :name) 
		"<br>current password=" curpass " " (length curpass) (send (class curpass) :name)
		"<br>~%new password=" newpass
		"<br>recpass==curpass? = " (equal recpass curpass)
		"<br>~%"))
     (gen "<br><p>~%") |#
     (cond ((or (and (> (length recpass) 2) (compcrypt curpass recpass))
		(equal recpass curpass))
	     (gen "You entered the correct password. <br>~%")
	     (cond ((equal newpass retypepass)
		    (pq:query db nil
			(format nil
			"update ~a set password='~a' where ~a='~a'"
			*table* (rcrypt newpass) primary-key *record-id*))
		    (gen (html "Password has been changed.<br>~%"))
		    (db-detail *table* *record-id*)
		    )
		   (t
		    (gen (html "New password inputs are not equal<br>~%"))
		    (db-change-password)) ) 
	     )
	   (t
		(gen (html "Current password is wrong. <br>~%"))
		(db-change-password)) )
	)
)



;;****************************************************************
;; main
;;****************************************************************
;; The following httpdb function should be called inside
;; an fcgi-loop.


(defun set-db-parameters ()
        (when (assoc 'database *forms*)
           (setq host
                    (cond ((assoc 'host *forms*) (qval 'host *forms*))
                          ((unix:getenv "DATABASE_HOST"))
                          ("localhost")))
	   (if *debug*
	       (format *error-output* 
                "pgsql connecting to ~s ~s ~s by name of ~s~%"
                        host
			(qval 'database *forms*)
                        (qval 'port *forms*)
                        (qval 'user *forms*)))
            (setq db (instance pq:pgsql :init
                :host host
                :dbname (qval 'database *forms*)
                :user (qval 'user *forms*)))
	    (format *error-output* "db=~s~%" db)
        )   )

(defun httpdb (&optional (con))
   (let ((policy) (host) (query))
     (setq db nil)
     (setq *connection* con)
     (setq *table-password* nil)
     (setq *forms* (parse-http-query (get-cgi-query)))
     (setq *db-command* (xqval 'command *forms* 'debug))
     (setq *table* (xqval 'table *forms* 'table_policy))
     (setq query (xqval 'query *forms* 'command))
     (http-header)
     (html-header :title *db-command*)
     (cond 
     	   ((null *fcgi*) (set-db-parameters))
	   ((and con (send con :db))
		(setq db (send con :db))
		)
	   (con
		(set-db-parameters)
		(send con :db db))
	   (t nil))
     ;; (gen (html db *table* *db-command* "<br>~%"))
     (when (and db *table* *db-command*)
	(setq policy (pq:select db  
		'* 'table_policy
		:where 
		   (format nil "tablename='~a' and screen='~a'~%"
				*table* *db-command*) ))
	(let ((fields (http-db-fields *table* 'top)) (pw) (title))
	   (setq primary-key  (first fields)
		 update-time  (second fields)) 
	   (setq *table-password* (caar (pq:select db
		'password "table_policy"
		:where
		   (format nil "tablename='~a' and screen='top'~%" *table*)) ))
	   (http-db-title *table* *db-command*)
	   )
	)
        ;;
     (setq *action* ;; "/fcgi/eusdb.fcgi"
	    (escape-tilda (unix:getenv "SCRIPT_NAME")))
     (case *db-command*
	  (debug 
		; (pprint (unix::environ) *cgi-out*)
		(gen (html "<br>table=" *table* " command=" *db-command* "<br>~%"))
		(gen (html "QUERY=" query "<br>~%"))
		(gen (html "*action*=" *action* "  " (unix:getenv "SCRIPT_NAME") "<br>~%"))
		(gen "forms=~s~%<br>~%" *forms*) 
		)
	  (top   (db-top *table*))	;; select db
	  (table (db-table))
	  (table-detail (db-table-detail *table*))
	  (create-table (db-create-table))
	  (create-field (db-create-field))
	  (field (db-field *table*))
	  ((list list-next list-previous)
		;; (gen "db-list" *forms* "<br>~%")
                (db-list *table*
			:condition (or (qval 'condition *forms*) t)
			:start (xqval *db-command* *forms* 0)
			:count (xqval 'count *forms* 100)
			:sort (xqval 'sort *forms* primary-key))
		 )
	  (detail (db-detail *table* (qval 'record *forms*)))
	  (next-record (db-detail *table* (qval 'record *forms*) 1))
	  (insert (db-insert ))
	  (do-insert (db-do-insert *table* *forms*))
	  (change (db-change *table* (xqval 'record *forms* nil)))
	  (update (db-update *table* (xqval 'record *forms* nil) *forms*))
	  (search (db-search *table*))
	  (do-search (db-do-search *table* *forms*))
	  (delete (db-delete ))
	  (download (db-download *table* (or (qval 'condition *forms*) t)))
	  ((mail email) (db-mail *table* *forms*))
	  ((mail-all email-all) (db-mail *table* 'all))
	  (login (db-login))
	  (change-password (db-change-password))
	  (update-password (db-update-password))
	  (authenticate (db-authenticate-password))
	  (cookies 
		(describe-list *fcgi-connections*))
	  (t (db-login )))
      (format *cgi-out* "~%</body></html>~%")

    )
   )

(setf (aref *random-state* 1) (elt (unix:gettimeofday) 0))
(provide :httpdb)

