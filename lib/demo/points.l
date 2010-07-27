;; make primitive bodies
;;

;; SOLID-OF-REVOLUTION

(setq cup-points '(#f(0.0 0.0 0.30000) #f(3.00000 0.0 0.330000)
		 #f(3.50000 0.0 0.40000) #f(3.70000 0.0 2.00000)
		 #f(3.90000 0.0 4.00000) #f(4.00000 0.0 5.00000)
		 #f(4.20000 0.0 5.00000) #f(4.30000 0.0 4.80000)
		 #f(4.340000 0.0 4.00000) #f(4.20000 0.0 2.50000)
		 #f(4.00000 0.0 0.500000) #f(3.70000 0.0 0.200000)
		 #f(3.50000 0.0 0.0)))

(setq cup (make-solid-of-revolution cup-points))

;; TORUS

(setq torus-points
	'(#f(4 0 0) #f(4.5 0 0.85) #f(5.0 0 1.0) #f(5.5 0 0.85)
	  #f(6.0 0 0) #f(5.5 0 -0.85) #f(5.0 0 -1.0) #f(4.5 0 -0.85)))

(setq torus-points2
	'(#f(3 0 0) #f(4 0 1.75) #f(5.0 0 2.0) #f(6 0 1.75)
	  #f(7 0 0) #f(6 0 -1.8) #f(5.0 0 -2.0) #f(4 0 -1.85)))

(setq torus (make-torus torus-points2))

;; PRISM

(setq prism-points (list #f(0 0 0) #f(-50 120 0) #f(60 220 0) #f(300 120 0)
			 #f(180 0 0)))
(setq prism (make-prism prism-points #f(100 100 300)) )

;; CONE

(setq cone-points
      (list #f(0 0 0) #f(-50 120 0) #f(60 220 0) #f(300 120 0)
			 #f(180 0 0)))
(setq cone1 (make-cone #f(20 30 300) cone-points))
(setq cone2 (make-cone #f(0 0 500) 100.0))

