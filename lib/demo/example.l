;(send *viewing* :look #f(150 50 100))
;(send *viewing* :hither 50)
;(send *viewsurface* :background 1)


(defun simple1 ()
   (setq s1 (make-cube 50 40 30))
   (send s1 :- 
 	    (send  (make-cube 40 30 30) :locate #f(0 0 10) :world))
   (setq s2 (make-cube 40 30 50))
   (setq s3 (make-cube 30 25 30))
   (send s3 :translate #f(0 0 30))
   (send s2 :+ s3)
   (send s1 :color 4)
   (send s2 :color 5)
)
;;


(defun simple2 ()
   (setq a (make-cube 400 400 300 :name "A")
	 b (make-cylinder 180 300 :name "B")
	 c (body+ a b)
	 d (make-cube 180 180 200 :name "D"))
   (send c :name "C")
   (send d :translate #f(0 0 300))
   (setq e (body- c d))
   (send e :name "E")
   (send e :translate #f(0 0 200))
   (setq f (make-cylinder 360 200 :name "F"))
   (setq g (body+ f e)))

(defun simple3 ()
   (setq base (make-cube 100 100 40 :name 'base :color 5))
   (setq tower (make-cube 30 30 100 :name 'tower :color 6))
   (setq branch (make-cube 20 20 50 :name 'branch :color 7))
   (send branch :rotate #d90 :x)
   (send branch :translate #f(0 25 30) :world)
   (send tower :+ branch)
   (send tower :translate #f(0 0 60))
   (send base  :+ tower)) 


