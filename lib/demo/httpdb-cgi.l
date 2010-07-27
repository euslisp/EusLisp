(load "/usr/local/eus/lib/demo/httpdb.l") 
(setq *charset* :sjis)
(httpdb)
(if db (send db :finish))
(unix::exit)



