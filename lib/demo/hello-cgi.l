;;
;;

(require :httpcgi)
(setq *action* "/cgi-bin/eushello.cgi")

(http-header)
(html-header :charset :euc)

(gen "<h1>Hello World</h1>~%")
(gen "<h2>Hello World</h2>~%")
(gen "</body> </html>~%")
(close *cgi-out*)

(unix::exit)
)
