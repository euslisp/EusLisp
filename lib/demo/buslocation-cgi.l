;;; buslocation-cgi.l
;;; Feb 3, 2003 by Toshihiro Matsui

(load "buslocation.l")

(setq *action* "/cgi-bin/bus.cgi")
(setq *table* "tsukuba_bus")	;(xqval 'table *forms* 'table_policy)
(setq db (instance pq:pgsql :init :dbname "t.matsui"))

(buslocation-top)

(unix::exit)

