;;
;;	peg in a hole with 6 contact points
;;		file name = example5.l
(in-package "GEOMETRY")
(load "view")
;(send *viewer* :resize 800)

(load "model2constRobust.l")
(load "inequalities.o")
(load "drawconst.l")
;;(send (send *viewsurface* :gc) :line-width 3)

(setq *contact-threshold* 5.0)

(setq x (make-prism '(#f(50 50 0) #f(50 -50 0) #f(-50 -50 0) #f(-50 50 0))
		    #f(0 0 200)))
(setq x1 (copy-object x))
(send x1 :translate #f(0 0 -100))
(send x1 :worldcoords)

(setq a1 (make-prism '(#f(100 100 -150) #f(100 -100 -150)
		       #f(-100 -100 -150) #f(-100 100 -150))
		     #f(0 0 150)))
(setq ana (body- a1 x1))

(send x :translate #f(0 -18.30127 -18.30127))
(send x :rotate -0.523599 :x)
(send x :worldcoords)

(setq c (list (send x :constraint ana)))
(setq m (constrained-motion c))
(setq f (constrained-force m))

(hidd x ana)
(draw-constraint c)

;(send-all c :draw-constraint *viewer* c)

