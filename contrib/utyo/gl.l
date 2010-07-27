;; Example bodies for testing set operations for touching bodies
;;	Toshihiro Matsui, Electrotechnical Laboratory
;;
;; 	Oct/15/1991
;;	Dec/27/1991
;;

(setq a (make-cube 400 400 300))	;base body

(setq b (make-cube 400 200 100))	;two edges colinear
(send b :locate #f(0 0 200) :world)
(setq b2 (make-cube 400 200 100))	;two edges colinear
(send b2 :locate #f(0 0 150) :world)
(setq c (make-cube 300 200 100))	;shares a vertex
(send c :translate #f(50 100 200))
(setq d (make-cube 200 200 100))	;isolated
(send d :translate #f(0 0 200))
(setq e (make-cube 600 200 200))
(send e :translate #f(0 0 250))
(setq f (make-cube 400 400 100))
(send f :translate #f(0 0 200))
(setq g (make-cube 300 300 400))
(send g :translate #f(50 0 150))

(send-all (list a b c d e f) :worldcoords)

(setq af (car (send a :get-face nil :top))
      bf (car (send b :get-face nil :bottom))
      cf (car (send c :get-face nil :bottom))
      df (car (send d :get-face nil :bottom))
      ef (car (send e :get-face nil :bottom))
      ff (car (send f :get-face nil :bottom))
      gf (car (send g :get-face nil :top))
      ae (send af :edges)
      be (send bf :edges)
      ce (send cf :edges)
      de (send df :edges)
      ee (send ef :edges)
      fe (send ff :edges)
)


;; Suehiro Block
(setq sue1 (make-cube 400 400 400))
(setq sue2 (make-cube 100 100 600))
(setq sue3 (body- sue1 sue2))
(send sue2 :rotate pi/2 :x)
(setq sue4 (body- sue3 sue2))
(send sue2 :rotate pi/2 :y)
(setq sue5 (body- sue4 sue2))


;; Arch
(setq a (make-cube 600 300 100))
(setq b (make-cube 150 150 200))
(send b :translate #f(-200 0 150))
(setq ab1 (body+ a b))
(setq ab2 (copy-object ab1))
(send ab2 :rotate pi :y)
(send ab2 :locate #f(0 0 300) :world)


;; CROSS
(setq x1 (make-cube 600 200 200))
(setq x2 (make-cube 200 600 200))
(setq x3 (make-cube 199 199 600))
(setq xx (body+ x1 x2))
(setq xxx (body+ xx x3))
(setq x4 (make-cube 200 200 200))
(send x4 :translate #f(0 0 200))
(setq xx2 (body+ xx x4))

;;;

(setq a (make-cube 400 400 300))
(setq b (make-cube 40 200 300))
(send b :locate #f(220 100 100))
(setq ab (body+ a b))


;; Hole + body	-- ok Dec/26/91
(setq a (make-cube 400 400 200))
;;(setq b (make-cube 400 300 300))
;;(send b :locate #f(-50 0 100))
(setq b (make-cube 300 300 300))
(send b :locate #f(0 0 100))
(setq h (make-cube 100 100 200))
(send h :locate #f(100 0 100))
(setq ab (body- a b))
(setq abc (body+ ab h))

;; hole-2 by body-	;; OK
(setq a (make-cube 400 400 300))
(setq h (make-cube 200 200 200))
(send h :translate #f(0 0 50))
(setq ah (body- a h))

;; Cut-off	;; Ok
(setq a (make-cube 400 400 300))
(setq co (make-cube 200 200 200))
(send co :locate #f(100 0 50) :world)
(setq aco (body- a co))

;; Cut-off protrusion	;; FAIL, BUG, BUG, BUG
(setq a (make-cube 400 400 300))
(setq co (make-cube 200 200 200))
(send co :locate #f(100 0 100) :world)
(setq aco (body- a co))

;; Cut-off at corner	;ok!
(setq a (make-cube 400 400 300))
(setq co (make-cube 200 200 200))
(send co :locate #f(100 100 50) :world)
(setq aco (body- a co))


;;

(defun collect (class list)
   (mapcan #'(lambda (x) (if (derivedp x class) (list x))) (flatten list)))

(defun read-question (strm &optional x)
   `(eval-dynamic ',(read strm)))
(set-macro-character #\? 'read-question)

