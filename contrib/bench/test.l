;; bench mark test for type discrimination and memory allocation speed
;;
;;	T.Matsui

(defmethod cons (:test () ))

#+eus
(defun gbc (x) (gc))

(defun prtime (func tm1 tm2)
  (format t "func ~A~%" (* 0.0167 (- tm2 tm1))))

(defun bench (m n)
     (declare (integer m n))
   (let (tm1 tm2 overhead1 overhead2 dummy)
     (setq tm1 (runtime))
     (dotimes (i m) )
     (setq tm2 (runtime))
     (setq overhead1 (- tm2 tm1))
     (setq tm1 (runtime))
     (dotimes (i n) )
     (setq tm2 (runtime))
     (setq overhead2 (- tm2 tm1))
;;
     (setq tm1 (runtime))
     (dotimes (i m)  (setq dummy (symbolp 'a)))
     (setq tm2 (runtime))
     (format t "symbolp ~a microsec.~%"  (* 1e6 (/ (* 0.0167 (- tm2 tm1 overhead1)) m)))
     (setq tm1 (runtime))
     (dotimes (i m)  (setq dummy (consp 'a)))
     (setq tm2 (runtime))
     (format t "consp ~a microsec.~%" (* 1e6  (/ (* 0.0167 (- tm2 tm1 overhead1)) m)))
#+eus
     (progn
	     (setq tm1 (runtime))
	     (dotimes (i m)  (derivedp 'a symbol))
	     (setq tm2 (runtime))
	     (format t "derivedp ~a microsec ~%"  (* 1e6 (/ (* 0.0167 (- tm2 tm1 overhead1)) m))))
#+eus
     (progn
	     (setq tm1 (runtime))
	     (dotimes (i m)  (send '(a) :test))
	     (setq tm2 (runtime))
	     (format t "send ~a microsec~%" 
			(* 1e6 (/  (* 0.0167 (- tm2 tm1 overhead1)) m))))
     (gbc t)
     (setq tm1 (runtime))
     (dotimes (i n)  (setq dummy (cons nil nil)))
     (setq tm2 (runtime))
     (format t "cons ~a microsec~%" (* 1e6 (/ (* 0.0167 (- tm2 tm1 overhead2)) n)))
     (gbc t)
     (setq tm1 (runtime))
     (dotimes (i n)  (make-string 10))
     (setq tm2 (runtime))
     (format t "make-string ~a microsec~%"  (/ (* 1e6 0.0167 (- tm2 tm1 overhead2)) n))
     (gbc t)
     (setq tm1 (runtime))
     (dotimes (i n)  (vector 1 2 3))
     (setq tm2 (runtime))
     (format t "3dvector ~a microsec ~%"  (/ (* 1e6 0.0167 (- tm2 tm1 overhead2)) n))
     (gbc t)
     (setq tm1 (runtime))
     (dotimes (i n)  (vector 1 2 3 4 5 6 7 8 9 10))
     (setq tm2 (runtime))
     (format t "10dvector ~a microsec ~%"  (/ (* 1e6 0.0167 (- tm2 tm1 overhead2)) n))
     (gbc t)
     (setq tm1 (runtime))
     (dotimes (i n) 
	 (vector 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
		 21 22 23 24 25 26 27 28 29 30))
     (setq tm2 (runtime))
     (format t "30dvector ~a microsec~%" 
	 (/ (* 1e6 0.0167 (- tm2 tm1 overhead2)) n))))
     

     

