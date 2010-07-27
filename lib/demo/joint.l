;; example program to define linked objects.
;;
;;	1990 (c) MATSUI, Toshihiro, The Electrotechnical Laboratory

(setq base (make-cube 400 400 40))
(send base :translate #f(0 0 20))

(setq a (make-prism 
	(reverse( list
		#f(0 0 -30) #f(400 0 -30) #f(440 7 -30)
		#f(460 20 -30) #f(480 38 -30) #f(495 66 -30)
		#f(500 100 -30) #f(495 134 -30) #f(480 162 -30)
		#f(460 180 -30) #f(440 193 -30) #f(400 200 -30)
		#f(0 200 -30)) )
	 60.0
	 :name "BEAM"))

(setq h (make-cylinder 30.0 100))
(send h :translate #f(400 100 -40))
(setq a0 (body- a h))
(send a0 :translate-vertices #f(0 -100 0))
(send a0 :rotate-vertices #d-90 :y)

(setq a1 (copy-object a0))
(send a0 :translate #f(100 0 41))
(send a1 :translate #f(-100 0 41))

(setq b (make-cube 99 100 500 :name "B"))
(setq h (make-cylinder 110 60))
(send h :rotate #d90 :y)
(send h :translate #f(-30 0 250) :world)
(setq b (body- b h))
(setq h (make-cylinder 20 100))
(send h :rotate #d90 :y)
(send h :translate #f(-50 0 200) :world)
(setq b (body- b h))
(send b :rotate #d-65 :x)
(send b :translate #f(0 0 441) :world)
(send b :translate #f(0 0 150))

(setq c (make-cube 59 60 400 :name "C"))
(send c :translate-vertices #f(0 0 120))
(send c :translate #f(0 #,(* (cos #d20) 360) #,(+ (* (sin #d20) 380) 400)))
(send c :rotate #d-130 :x)
(send c :translate #f(0 0 20) :world) ;????

(send *viewing* :look #f(1300 800 1100) #f(0 100 300))

(cls)
(hid base a0 a1 b) ; c)
(defpart a0 :shape a0 :color 4)
(defpart a1 :shape a1 :color 4)
(defpart b  :shape b :color 5)
(defpart base :shape base :color 6)
(defpart c :shape c :color 7)

