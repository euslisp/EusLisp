(defun cids ()
  (dolist (x (sys:list-all-classes))
      (format t "~s ~d~%" (send x :name)
      (send x :cid))))

(sys:make-thread 8)
;(load "l/par.l")
(thr-setconcurrency 8)

(defun cubes (n)
   (dotimes (i n)
	   (let ((c (make-cube 500 400 300)))
;	       (send c :rotate 0.1 :x)
;	       (send c :translate #f(10 20 30))
       c)))

(setq c1 (make-cube 500 400 300))
(setq c2 (make-cylinder 100 100))
(send c2 :translate #f(200 150 100))
(defun intck (n ) (dotimes (i n) (send c1 :intersectp c2)))

 (setq *debug* t)

(defun itest (con)
   (let ((gtime (sys:gctime)) (rtime (runtime)) threads newgc)
      (dotimes (i con) (push (afuncall 'cubes 100) threads))
	(warn "fork done ~d ~s~%" con threads)
      (dolist (thr threads) (wait-afuncall thr))
      (setq newgc (sys:gctime))
      (format t "concurrency=~d runtime=~s sec gc=~d ~d ~%"
	 con (- (runtime) rtime) (- (car newgc) (car gtime))
	 (+ (- (cadr newgc) (cadr gtime)) (- (caddr newgc) (caddr gtime))))))


(setq *fork-n* 20)

(defun parfib (n)
   (cond ((< n 2) n)
	 ((< n *fork-n*) (+ (parfib (- n 2)) (parfib (1- n))))
	 (t (let (a b)
		(setq a (thread 'parfib (- n 2))
		      b (thread 'parfib (1- n)))
	        (+ (sys:wait-thread a) (sys:wait-thread b))))))

(defun parfib-test (n)
  (let (start end sec usec r)
     (setq start (unix::gettimeofday))
     (setq r (parfib n))
     (setq end (unix::gettimeofday))
     (setq sec (- (car end) (car start))
	   usec (- (cadr end) (cadr start)))
     (print r)
     (/ (+ (* sec 1000000) usec) 1000.0)))
