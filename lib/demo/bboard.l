(unless (unix:isatty 0)
   (defun euserror (code msg1 form &optional (msg2))
	  (format *error-output*
		"eus error ~s ~s ~s ~s~%" code msg1 form msg2)
	  (unix::exit 1))
   (setq *error-handler* 'euserror)
   )

(require :http "http")
(require :time "time")
(require :webnews "webnews")
(require :pgsql "pgsql")
(require :httpcgi)

(defvar *action* "/cgi-bin/bus.cgi")	;;override this for fast-cgi

#|
drop table bboard_matsui;
drop sequence bboard_matsui_id_seq;
create table bboard_matsui (
	id serial,
	recdate date,
	rectime date,
	del_key text,
	poster  text,
	poster_email	text,
	title	text,
	message	text);
|#
 

(defun bboard-list ()
   (let ((data))
      (setq data (send db :exec (format nil
	"select recdate, rectime, poster, poster_email, title, message
		from bboard_matsui
		where recdate = ~a
		order by recdate and rectime desc
		limit 100")))



(defun bboard ()
   (let (db)
      (setq db (instance pq:pgsql :init :db-name "t.matsui"))
      )
   )
	
