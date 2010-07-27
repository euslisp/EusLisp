(unix:system "xterm -e /usr/local/eus/SunOS5/bin/sockstd 4283 &")
(setq sa (make-socket-address :port 4283))
(unix::sleep 3)
(setq s (make-client-socket-stream sa))

