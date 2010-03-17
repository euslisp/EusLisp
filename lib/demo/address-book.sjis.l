;;;; address-book.l
;;;; rsj committee member list management system
;;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;; Note that this program should be encoded in sjis.
;;;
;;;  This programs retrieves address book data from the database,
;;;  displays the list, provides search, and allows user's change and insert.
;;;  This program uses postgreSQL as the database server via libpq.so.
;;;  PostgreSQL tables are assumed to have the following fields (columns)
;;; +------------------+-------------+-------+
;;; |      Field       |      Type   | Length|
;;; +------------------+-------------+-------+
;;; | id               | int4        |     4 |
;;; | title            | text        |   var |
;;; | name             | text        |   var |
;;; | kana             | text        |   var |
;;; | office           | text        |   var |
;;; | office_phone     | text        |   var |
;;; | office_phone2    | text        |   var |
;;; | office_fax       | text        |   var |
;;; | email            | text        |   var |
;;; | office_address   | text        |   var |
;;; | home_address     | text        |   var |
;;; | home_phone       | text        |   var |
;;; | update_date      | date        |     4 |
;;; | remarks          | text        |   var |
;;; +------------------+-------------+-------+
;;;  
;;; There several screens:
;;;   list -- displays a list of members and buttons for mail, insert, etc.
;;;   detail- displays detail information of a particular member
;;;   change- changes the detail info
;;;   insert- create a new record
;;;   search- inputs fields for search, results are shown in the list screen
;;;   mail--- sends Email to all/selected members
;;;   download - sends csv file for selected/all members
;;;

(defun euserror (code msg1 form &optional (msg2))
  (format *error-output*
	"eus error ~s ~s ~s ~s~%" code msg1 form msg2)
  (unix::exit 1))

(setq *error-handler* 'euserror)


(load "/usr/local/eus/lib/llib/pgsql.l")
(load "/usr/local/eus/lib/llib/httpcgi.l")
(load "/usr/local/eus/lib/llib/kana_euc")
;; pgsql loads "time" automatically.

(defvar db)

(defun jtable-name (tname)
   (case tname 
	(trustees "理事")
        (techaward "実用化技術賞選考委員会")
	;; add more if you have more address tables
	))

(defun delimit-list (xlist delimiter)
   (let (rlist)
      (while xlist
	 (push (string (pop xlist)) rlist)
	 (if xlist (push delimiter rlist)))
      (apply #'concatenate string (nreverse rlist))))

;; select fields (id name phone ...) where id=1 or id=2 ...
;; if ids=t, all are selected.
(defun rsj-select-by-id (table fields ids)
    (pq:query db nil
	 "select ~a from ~a ~a ~a order by id"
	 (delimit-list fields ",")
	 table
	 (if (consp ids) "where" "")
	 (if (consp ids)
	     (delimit-list 
		 (mapcar #'(lambda (x) (format nil "id=~d"  x))	ids)
		 " or ")
	     "") )
   )

;; collect receiver=1&receiver=2 ... or ids="(1 2)" from the query string
(defun collect-selection (forms)
    (if (assoc 'receiver forms)
	(mapcar #'(lambda (x) (read-from-string (second x)))
		(collect-if #'(lambda (x) (eq (car x) 'receiver)) forms))
	(if (assoc 'ids forms)
	    (read-from-string (qval 'ids forms)))) )

(defun qval (arg query) (sjis2euc (cadr (assoc arg query))))

;;****************************************************************
;; list display
;;****************************************************************

(defun rsj-list (table &optional (ids))
   ;; entry to the member list
   (let ((rsj-list) (delimited-ids ""))
	(if (consp ids)
	    (setq delimited-ids
		(delimit-list
		    (mapcar
			#'(lambda (x) (format nil "id=~a" x)) ids) " or ")))
 	(gen "<h1>RSJ~a名簿 (一覧) </h1><br>~%" (jtable-name table))
	(gen "個人の詳細データを見たり、データを更新・削除するには、各行の
		先頭の数字(id)をクリックして下さい。<br>~%")
	(gen
"<form action=\"address-book.cgi\" method=post>
<table>
<tr><td><input type=submit name=command value=create> 新規レコード作成</td>
<td><input type=submit name=command value=list>全リスト</td></tr>
<tr><td><input type=submit name=command value=mail> 選択した人たちにEmail送信</td>
<td><input type=submit name=command value=mail-all> 全員にEmail送信</td></tr>
</table><br>
<input type=hidden name=table value=~a>~%" table)
	(when ids
	    (setq rsj-list
	       (rsj-select-by-id table
		  '(id title name office email office_phone update_date)
		  ids))
	    (gen "<input type=hidden name=ids value=\"~s\">~%" ids))
	(format *cgi-out* "~s~%" (mapcar #'car rsj-list))
	(setq rsj-list
	   (mapcar #'(lambda (x) (list
	        (format nil 
		  "<input type=checkbox name=receiver value=~d>" (car x))
	        (first x) (second x)  (third x) (fourth x)
	        (format nil "<a href=\"mailto:~a\">~a</a>" (fifth x) (fifth x))
	        (sixth x) (seventh x)))
	      rsj-list))
	(format *cgi-out* "~a<br>~%"
	   (html-table rsj-list :table-option "border=1"
		:href "address-book.cgi"
		:table table
		:command 'detail
		:href-column 2
		:heading '(select id "Title" "Name" "Office" "Email"
				"Office Phone" update)))
	;;(format *cgi-out* "</form>~%")
	;;
	;; <p><form action=\"address-book.cgi\" method=post>
	(format *cgi-out* "<hr>
<input type=hidden name=table value=~a>
<input type=submit name=command value=download>
<input type=submit name=command value=search><br></form>~%" table)    ))


;;****************************************************************
;; detail display
;;****************************************************************
(defun rsj-detail (table n)
   ;; ID button in the entire list brings here.
   (let ((detail (car
	    (pq:query db nil
		"select id, title, name, kana, office, email,
			office_phone, office_fax, office_address,
			home_phone, home_address, update_date, remarks
			from ~a where id=~s" table n))))
      (format *cgi-out*
"<h2>RSJ~aメンバーの詳細情報 </h2><br>
内容を変更するときはchange buttonを押して下さい。
このレコードを削除するにはdelete buttonを押して下さい。<br>
<form action=\"address-book.cgi\" method=post>
<table><tr>
<td><input type=submit name=command value=change></td>
<td><input type=submit name=command value=delete></td>
<td><input type=submit name=command value=list></td></tr></table>
<input type=HIDDEN name=arg value=~a> 
<input type=hidden name=table value=~a> </form>" (jtable-name table) n table)
      ;;
      (format *cgi-out* "~a~%" 
	    (html-table 
		(transpose-list 
			(list '(id title name kana office email
				office_phone office_fax office_address
				home_phone home_address update_date remarks)
			        detail))
		:table table
		:table-option "border=1"
		))
   ) )

;;****************************************************************
;; edit record 
;;****************************************************************

(defun rsj-input-form (table fields initial)
   ;; table form of inputs for fields
   ;; common form for change, create and search
   (gen "<table border=1>~%")
   (let ((detail))
      (setq detail
	   (if initial
	       (car
		  (pq:query db nil
			"select ~a from ~a where id=~s"
			(delimit-list fields ",") table initial))
		(fill (make-list (length fields)) "")    ) )
      (dolist (x (transpose-list (list fields detail)))
         (gen "<tr><td>~a</td>
	<td><input type=TEXT size=60 name=\"~a\" value=\"~a\"></td></tr><br>~%"
		(car x)	(car x) (euc2sjis (cadr x)) ))
        (gen "</table>~%")
	(gen "<input type=HIDDEN name=arg value=~a>~%" initial))
     )

(defun rsj-change (table n)
  ;; provide input forms for n-th record
  ;; [change] button in the detail display brings here.
  ;; 
  (format *cgi-out* "<h2>RSJ~aメンバーレコードの変更</h2><br>
正しいデータを入力し、updateボタンを押して下さい。</h2>~%"
	(jtable-name table))
  (let ((detail (car
	    (pq:query db nil
		"select title, name, kana, office, email,
			office_phone, office_fax, office_address,
			home_phone, home_address, remarks
			from ~a where id=~s" table n))))
     (gen
"<form action=\"address-book.cgi\" method=post>
<input type=hidden name=table value=~a>
<input type=submit name=command value=update>
<input type=reset name=clear  value=\"reset to original\">
<input type=submit name=command value=list>~%<hr>~%" table)
     (rsj-input-form table '("title" "name" "kana" "office" "email"
		"office_phone" "office_fax" "office_address"
		"home_phone" "home_address" "remarks")
	  n)
     (gen "</form>~%")
    ))
      ;;

(defun rsj-update (table id args)
   ;; rsj-change finishes, and the update button brings here.
   ;; encoding should be changed from sjis to euc to put in the database. 
   (pq:query db nil
	(format nil "update ~a set
		title='~a', name='~a',  kana='~a', office='~a', email='~a',
		office_phone='~a', office_fax='~a', office_address='~a',
		home_phone='~a', home_address='~a', remarks='~a',
		update_date='~a' where id='~a'"
		table
		(qval 'title args) (qval 'name args) 
		(qval 'kana args) (qval 'office args) (qval 'email args)
		(qval 'office_phone args) (qval 'office_fax args)
		(qval 'office_address args) (qval 'home_phone args)
		(qval 'home_address args) (qval 'remarks args)
		(send (now) :iso-date-string)
		id ) )
   (rsj-detail table id)	;; display the detail again
   (gen "The member record of Id=~a has been updated.<br>~%" id)
   )


;;****************************************************************
;; create/insert a new record
;;****************************************************************

(defun rsj-create (table)
  ;; provide input forms for n-th record
  ;; create button in the list window brings here.
  ;;
  (gen "<h1>RSJ~a新規メンバー登録</h1><br>
データを入力し、insertボタンを押して下さい。
半角カナは使わないようにお願いします。IDは自動的に割り当てられます。</h2>~%"
	(jtable-name table))
  (let ()
     (gen
"<form action=\"address-book.cgi\" method=post>
<input type=submit name=command value=insert>登録<br>
<input type=reset name=command  value=clear>
<input type=hidden name=table  value=~a>
~%<hr>~%" table)
     (rsj-input-form table  '("title" "name" "kana" "office" "email"
			"office_phone" "office_fax" "office_address"
			"home_phone" "home_address" "remarks")
		nil)
     (gen "</form>~%") 
   )  )

(defun rsj-insert (table args)
  ;; Data for a new record are ready.  Put them in the database.
  (let ((id (caar (pq:query db nil "select max(id) from trustees"))))
     (incf id)
#|     (format *cgi-out* "new id=~a<br>~%" id) |#
     (pq:query db nil
        (format nil "insert into ~a
		(id, title, name, kana, office, email,
		 office_phone, office_fax, office_address,
		 home_phone, home_address, remarks, update_date)
		values ('~a', '~a', '~a', '~a', '~a', '~a',
			 '~a', '~a', '~a', '~a', '~a', '~a', '~a')~%"
		table id
		(qval 'title args) (qval 'name args)
		(qval 'kana args) (qval 'office args) (qval 'email args)
		(qval 'office_phone args) (qval 'office_fax args)
		(qval 'office_address args) (qval 'home_phone args)
		(qval 'home_address args) (qval 'remarks args)
		(send (now) :iso-date-string)
		))
     (gen "<h2>新規memberを登録しました。id=~s</h2>~%" id)
     (rsj-detail table id)
   ))

;;****************************************************************
;; delete
;;****************************************************************

(defun rsj-delete (table id)
   (let ((name (caar
	   (pq:query db nil "select name from ~a where id=~a" table id))))
     (gen
	 "<h1>~aの名簿から~aさん(id=~a)の
レコードを削除してよろしいですか?<br></h1>" (jtable-name table) name id)
     (gen "<form action=\"address-book.cgi\" method=GET>
	<input type=submit name=command value=do-delete>
	<input type=HIDDEN name=arg value=~a> 
	<input type=hidden name=table value=~a> 
	</form><br>~%"  id table)
    ))

(defun rsj-do-delete (table id)
   (let ((name (caar
	   (pq:query db nil "select name from ~a where id=~a" table id))))
     (pq:query db nil "delete from trustees where id='~a'" id )
     (rsj-list table t)
     (format *cgi-out* "~a さんのレコード(id=~a)を削除しました。<br>~%"
	name id))
    )

;;****************************************************************
;; search
;;****************************************************************

(defun rsj-search (table)
   (gen "Input search string for names
	<form action=\"address-book.cgi\" method=GET>~%")
   (rsj-input-form table '("id" "title" "name" "kana" "office" "email") nil)
   (gen "<input type=submit name=command value=\"do-search\"> 
	<input type=reset name=clear value=clear>
	<input type=hidden name=table value=~a>
	</form>~%" table)
 )

(defun rsj-do-search (table args)
   ;; (gen "do-search ~a<br>~%" args)
   (let ((name-to-search (qval 'name args))
	 (title-to-search (qval 'title args))
	 (id-to-search (qval 'id args))
	 (kana-to-search (qval 'kana args))
	 (email-to-search (qval 'email args))
	 (office-to-search (qval 'office args)))
#|      (gen "id=~s~%<br>~%" id-to-search)
      (gen "name=~s~%<br>~%" name-to-search)
      (gen "title=~s~%<br>~%" name-to-search)
      (gen "kana=~s~%<br>~%" kana-to-search)
      (gen "email=~s~%<br>~%" email-to-search)
      (gen "office=~s~%<br>~%" office-to-search) |#
      (if (not (zerop (length id-to-search)))
	  ;; search for the specified ID
	  (progn
	     (setq ids (pq:query db nil
		 "select id from ~a where id=~a" table id-to-search) ))
	  (progn
	     (setq ids (pq:query db nil
		"select id from ~a where name like '%~a%' and
			title like '%~a%' and kana  like '%~a%' and
			email like '%~a%' and office like '%~a%'"
		table name-to-search title-to-search kana-to-search
		email-to-search office-to-search))) )
      ;; (gen "~s~%" ids)
      (rsj-list table (mapcar #'car ids))
      ))

;;****************************************************************
;; download
;;****************************************************************

(defun rsj-download (table ids) 
   (let ((all) (b) (fname (format nil "/home/httpd/html/rsj/rsj-~a.csv" table)))
     (setq all
	(rsj-select-by-id table
		'(id title name kana office email office_phone office_fax
		 office_address home_phone home_address remarks update_date)
		ids))
     (with-open-file (out fname :direction :output)
	(dolist (a all)
	   (while a
	      (setq b (pop a))
	      (format out "~a~a"
		   (cond ((derivedp b interval-time) (send b :iso-date-string))
			 ((stringp b) (euc2sjis b))
			 (t b))
		   (if b "," "")))
	   (terpri out)))
     (unix:system (format nil "tar cf - ~a | gzip >~a.tar.gz" fname fname))
     (gen "<h1>ＲＳＪ~a名簿のダウンロード</h1><br>
<a href=\"http://lys.matsui.jp/rsj/rsj-~a.csv.tar.gz\"> <li>download csv.tar.gz</a><br>
<a href=\"http://lys.matsui.jp/rsj/rsj-~a.csv\"> <li>download .csv</a><br>
~%"	(jtable-name table) table table) )
  )

(defun rsj-mail (table receivers)
   ;; (gen "rsj-mail ~s~%" receivers)
   (let ((ids) (email-name) (email-addresses) (names))
      (setq email-name
	    (rsj-select-by-id table '(email name) receivers))
      (setq names (mapcar #'second email-name))
      (setq email-addresses (mapcar #'car email-name))
      (setq email-addresses  (delimit-list email-addresses ", "))
      (gen
	 "<h1>Email送信</h1><br>下の行をクリックすると、~a さんにEmailを送信します。<br>~%"
	 (euc2sjis (delimit-list names ", ")))
      (gen "<a href=\"mailto:~a\"> ~a</a><br>~%"
	 email-addresses email-addresses)))


;;;****************************************************************
;;; main
;;;
(let ((query) (forms) (ids) (command) (table)
	(host (unix:getenv "DATABASE_HOST")))
	(html-header)
	(setq query (get-cgi-query))
	(if (and query (plusp (length query)))
	    (setq forms (parse-http-query query)) )
 	(setq db (instance pq:pgsql :init 
		:host host
		:dbname "t.matsui"
		:user "t.matsui"))
	(setq command (cadr (assoc 'command forms)))
	(if command (setq command (read-from-string command)))
        (setq table (cadr (assoc 'table forms)))
	(setq table (if table (read-from-string table) "trustees"))
	(gen "<head><title>~a</title></head>" table)	
	(gen "<body bgcolor=\"#ffe0c0\">~%")
	;; debug output
	(gen "<!--~%")
	;; (gen "query_string=~s~%" query) 
	(gen "forms=~s~%" forms) 
	(gen "command=~s table=~s -->~%" command table)
	;;
	(if (null command) (setq command 'list))
	(case command
	   ((list) (rsj-list table t))
	   (detail (rsj-detail
		table
		(read-from-string (cadr (assoc 'arg forms)))	 ))
	   (change
		(rsj-change table (read-from-string (cadr (assoc 'arg forms))))	 )
	   (update (rsj-update table (read-from-string (cadr (assoc 'arg forms)))
			 forms)	)
	   (insert (rsj-insert table forms))
	   (create (rsj-create table))
	   (delete (rsj-delete table (read-from-string (cadr (assoc 'arg forms)))))
	   (do-delete (rsj-do-delete table
		 (read-from-string (cadr (assoc 'arg forms)))))
	   (search (rsj-search table))
	   (do-search (rsj-do-search table forms))
	   (download 
		 (rsj-download table (or (collect-selection forms) t)))
	   (mail (rsj-mail table (or (collect-selection forms) t)))
	   (mail-all (rsj-mail table (or (collect-selection forms) t)))
	   (t (format *cgi-out* "no command<br>~%")
		 (gen "~s<br>~%" (unix:environ))
		 (gen "~s<br>~%" forms)
		 (rsj-list "trustees" t)))
	)

