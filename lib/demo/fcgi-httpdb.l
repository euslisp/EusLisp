(load "lib/demo/httpdb.l")
(fcgi-loop
   ;; get-cookie has been done.
   (setq con (fcgi-connection 'eusid fcgi-db-connection))
   ;;
   (set-cookie 'eusid (send con :cookie))
   (httpdb con)
   )
