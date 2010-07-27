;;
;;
(setq tb1
     (make-prism (list #f(-200 -200 -100) #f(-200 200 -100)
                       #f(200 200 -100) #f(200 -200 -100)) 100))

(setq tb2
     (make-prism (list #f(-70 -70 0) #f(-70 70 0)
                       #f(70 70 0) #f(70 -70 0)) 100))

(setq tb3
     (make-cone #f(100 100 300)
                 (list #f(20 20 100) #f(20 150 100)
                       #f(150 20 100))))

(setq tb4
     (make-cone #f(100 -100 300)
                (list #f(20 -20 100) #f(150 -20 100)
                      #f(20 -150 100))))

(setq tb5
     (make-cone #f(-100 -100 300)
                (list #f(-20 -20 100) #f(-20 -150 100)
                      #f(-150 -20 100))))

(setq tb6
     (make-cone #f(-100 100 300)
                (list #f(-20 20 100) #f(-150 20 100)
                      #f(-20 150 100))))

(cls) 

(draw (list tb1 tb2 tb3 tb4 tb5 tb6))

(setq g (glue tb6 
           (glue tb5 
              (glue tb4 
                 (glue tb3 (glue tb1 tb2))))))

(cls)
(hid g)

;;
;;

(setq c1 
    (make-prism (list #f(0 0 -100) #f(0 300 -100) #f(300 0 -100)) 100))

(setq c2 
    (make-prism (list #f(-100 -100 0) #f(-100 200 0) #f(200 -100 0)) 100))

(setq gc1 (glue c1 c2))

(setq c3 
    (make-prism (list #f(-100 -100 100) #f(-100 200 100) #f(200 -100 100)) 100))

(setq gc2 (glue gc1 c3))

;;
;;


(defun sanmenzu (bod)
  (send *viewer* :clear)
    (send *viewer1* :pane)
    (send *viewer2* :pane)
    (send *viewer3* :pane)
    (send *viewer4* :pane)
  (send *viewer1* :hid bod)
  (send *viewer2* :hid bod)
  (send *viewer3* :hid bod)
  (send *viewer4* :hid bod)
)
