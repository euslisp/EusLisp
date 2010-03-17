;;;; rsj-list.l
;;;; rsj committee member list management system
;;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;; Note that this program should be encoded in sjis.


(defun euserror (code msg1 form &optional (msg2))
  (format *error-output*
	"eus error ~s ~s ~s~%" code msg1 msg2)
  (format t "Content-type: text/html~%~% eus cgi error ~s ~s~%" code msg1)
  (unix::exit 1))

(setq *error-handler* 'euserror)


(load "/usr/local/eus/lib/llib/pgsql.l")
(load "/usr/local/eus/lib/llib/httpcgi.l")
(load "/usr/local/eus/lib/llib/kana_euc")
(load "/usr/local/eus/lib/llib/time")

;; should be invoked with "GET" method
;; <FORM ACTION="cgi-bin/eus.cgi" METHOD="GET" ENCTYPE="application/x-www-urlencoded">
;; <INPUT TYPE="TEXT" NAME="form" size="52">
;; <INPUT TYPE="SUBMIT" NAME="Submit" value="Eval"> </FORM>

(defvar db)

(defun jtable-name (tname)
   (case tname 
	(trustees "理事")
        (techaward "実用化技術賞選考委員会")
	;; add more depending on tables
	))


;;****************************************************************
;; list display
;;****************************************************************

(defun rsj-list (table)
   ;; entry to the member list
   (let ((rsj-list))
 	(format *cgi-out* "<h1>RSJ~a名簿 ( 一覧 ) </h1><br>~%"
		 (jtable-name table))
	(format *cgi-out*
		"個人の詳細データを見たり、データを更新・削除するには、各行の
		先頭の数字(ID)をクリックして下さい。<br><p>~%")
	(format *cgi-out*
"<form action=\"rsj-list.cgi\" method=get>
<input type=submit name=command value=create> 新規レコード作成<br>
<input type=submit name=command value=mail> 選択した人たちにEmail送信<br>
<input type=submit name=command value=mail-all> 全員にEmail送信<br>
<input type=hidden name=table value=~a>
~%" table)
	(setq rsj-list
	   (pq:query db nil
		"select id, title, name, office, email, office_phone, update_date
			from ~a order by id" table))
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
		:href "rsj-list.cgi"
		:table table
		:command 'detail
		:href-column 2
		:heading '(select id "Title" "Name" "Office" "Email" "Office Phone" update)))
	(format *cgi-out* "</form>~%")
	;;
	(format *cgi-out* "<hr><p><form action=\"rsj-list.cgi\" method=GET>
<input type=hidden name=table value=~a>
<input type=submit name=command value=download>
<input type=submit name=command value=search>
not yet implemented<br> 
</form>~%" table)
    ))


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
<form action=\"rsj-list.cgi\" method=GET>
<input type=submit name=command value=change>
<input type=submit name=command value=delete>
<input type=submit name=command value=list> 
<input type=HIDDEN name=arg value=~a> 
<input type=hidden name=table value=~a </form>" (jtable-name table) n table)
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
     (format *cgi-out*
"<form action=\"rsj-list.cgi\" method=GET>
<input type=hidden name=table value=~a>
<input type=submit name=command value=update>
<input type=reset name=clear  value=\"reset to original\">
<input type=submit name=command value=list>~%<hr>~%" table)
     (format *cgi-out* "<table border=1>~%")
     (dolist (x (transpose-list (list
			'(title name kana office email
				office_phone office_fax office_address
				home_phone home_address remarks)
			 detail)))
         (format *cgi-out*
"<tr><td>~a</td>
<td><input type=TEXT size=60 name=\"~a\" value=\"~a\"></td></tr><br>~%"
	(car x)	(car x) (euc2sjis (cadr x)) ))
     (format *cgi-out*
"</table>
<input type=HIDDEN name=arg value=~a>
</form>~%" n)))
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
   (format *cgi-out* "<h2>新規memberを登録しました。id=~s</h2>~%" id)
   (rsj-detail table id)	;; display the detail again
   )


;;****************************************************************
;; create/insert a new record
;;****************************************************************

(defun qval (arg query) (sjis2euc (cadr (assoc arg query))))

(defun rsj-create (table)
  ;; provide input forms for n-th record
  ;; create button in the list window brings here.
  ;;
  (format *cgi-out* "<h1>RSJ~a新規メンバー登録</h1><br>
データを入力し、insertボタンを押して下さい。
半角カナは使わないようにお願いします。IDは自動的に割り当てられます。</h2>~%"
	(jtable-name table))
  (let ()
     (format *cgi-out*
"<form action=\"rsj-list.cgi\" method=GET>
<input type=submit name=command value=insert>登録<br>
<input type=reset name=command  value=clear>
<input type=hidden name=table  value=~a>
~%<hr>~%" table)
     (format *cgi-out* "<table border=1>~%")
     (dolist (x (transpose-list (list
			'(title name kana  office email
				office_phone office_fax office_address
				home_phone home_address remarks)
			'("" "" "" "" "" "" "" "" "" "" ""))))
         (format *cgi-out*
"<tr><td>~a</td>
<td><input type=TEXT size=60 name=\"~a\" value=\"~a\"></td></tr><br>~%"
	(car x)	(car x) (cadr x)) )
     (format *cgi-out*  "</table> </form>~%") 
	)
  )

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
     (rsj-detail table id)
   ))

;;****************************************************************
;; delete
;;****************************************************************

(defun rsj-delete (table id)
   (let ((name (caar
	   (pq:query db nil "select name from ~a where id=~a" table id))))
     (pq:query db nil "delete from trustees where id='~a'" id )
     (rsj-list table)
     (format *cgi-out* "~a さんのレコード(id=~a)を削除しました。<br>~%"
	name id))
    )

;;****************************************************************
;; search
;;****************************************************************

(defun rsj-search (table) )

;;****************************************************************
;; download
;;****************************************************************

(defun rsj-download (table ) 
   (let ((all) (b) (fname (format nil "/home/httpd/html/rsj/rsj-~a.csv" table)))
     (setq all
        (pq:query db nil
	   "select id,title,name,kana,office,email,office_phone,office_fax,
		office_address,home_phone,home_address,remarks,update_date
	    from ~a" table))
     (with-open-file (out fname :direction :output)
	(dolist (a all)
	   (while a
	      (setq b (pop a))
	      (format out "~a~a"
		 (if (derivedp b interval-time)
		     (send b :iso-date-string)
		     b)
		 (if b "," "")))
	   (terpri out)))
     (unix:system (format nil "tar cf - ~a | gzip >~a.tar.gz" fname fname))
     (format *cgi-out* "ＲＳＪ~a名簿のダウンロード<br>
<a href=\"http://choku2.etl.go.jp/rsj/rsj-~a.csv.tar.gz\"> download csv.tar.gz</a><br>
<a href=\"http://choku2.etl.go.jp/rsj/rsj-~a.csv\"> download .csv</a><br>
~%"	(jtable-name table) table table) )
  )

(defun delimit-list (xlist delimiter)
   (let (rlist)
      (while xlist
	 (push (pop xlist) rlist)
	 (if xlist (push delimiter rlist)))
      (apply #'concatenate string (nreverse rlist))))

(defun rsj-mail (table receivers)
   (let ((ids) (email-addresses))
      (cond ((consp receivers)
	      (setq ids (delimit-list 
		 (mapcar #'(lambda (x)
			(format nil "id=~d" (read-from-string x)))
			receivers)
		 " or ")) 
	      (setq email-addresses
	         (mapcar #'car 
		   (pq:query db nil "select email from ~a where ~a order by id"
			 table ids))))
	    (t (setq email-addresses
	         (mapcar #'car 
		   (pq:query db nil "select email from ~a order by id" table ids))))
	    )
      (setq email-addresses 
	    (delimit-list email-addresses ", "))
      (format *cgi-out* "<a href=\"mailto:~a\"> mailto ~a</a><br>~%"
	 email-addresses email-addresses)))


;;;****************************************************************
;;; main
;;;
(let ((query) (forms) (result) (command) (table))
	(html-header)
	(format *cgi-out* "<body bgcolor=\"#ffe0c0\">~%")
	;;(format *cgi-out* "<FONT COLOR=#ff0000> ~a</FONT><BR>~%"
	;;    (UNIX:asctime (unix:localtime)))
	;; (format *cgi-out* "http_user_agent=~s<br>~%" (unix:getenv "HTTP_USER_AGENT"))
	;; (pprint (unix::environ))
	(setq query  (unix:getenv "QUERY_STRING"))
	(if (and query (plusp (length query)))
	    (setq forms (parse-http-query query)) )
 	(setq db (instance pq:pgsql :init :host "kenji2.etl.go.jp"
		:dbname "rsj" :user "matsui"))
	(setq command (cadr (assoc 'command forms)))
	(if command (setq command (read-from-string command)))
        (setq table (cadr (assoc 'table forms)))
	(setq table (if table (read-from-string table) "trustees"))
	;; debug output
	(format *cgi-out* "<!--~%")
	(format *cgi-out* "query_string=~s~%" query) 
	(format *cgi-out* "forms=~s~%" forms) 
	(format *cgi-out* "command=~s table=~s -->~%" command table)
	;;
	(case command
	   (list (rsj-list table))
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
	   (search (rsj-search table))
	   (download (rsj-download table))
	   (mail (rsj-mail table (mapcar #'second (collect-if
		   #'(lambda (x) (eq (car x) 'receiver)) forms))))
	   (mail-all (rsj-mail table t))
	   (t (format *cgi-out* "no command<br>~%")
		 (format *cgi-out* "~s<br>~%" (unix:environ))
		 (format *cgi-out* "~s<br>~%" forms)
		 (rsj-list "trustees")))
	)

