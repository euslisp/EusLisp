
(setq bod1  
    (make-solid-of-revolution
        (list #f(50 0 200) #f(100 0 150) #f(150 0 100)
              #f(150 0 50) #f(150 0 0)) :segments 8)))

(draw bod1)
(unix:sleep 1)
(cls)

(print 'kill-edge)

(possible-kill-edges bod1)

(draw bod1)
(unix:sleep 1)
(draw (bod1 . vertices))
(unix:sleep 1)
(cls)
 
(print 'kill-vertices)

(possible-kill-vertices bod1)

(draw bod1)
(unix:sleep 1)
(draw (bod1 . vertices))
(unix:sleep 1)
(cls)

(hid bod1)
