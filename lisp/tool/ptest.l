(defun localtime2second (time)
   %(time[2] * 3600 + time[1] * 60 + time[0]))

(defun classid ()
  (dolist (c (sys:list-all-classes))
    (format t ";~s ~d~%" (send c :name) (send c :cid))))

(defmacro ptest (concurrency try_count func &rest args)
   (let ((gtime (gensym)) (gtime1 (gensym)) (gtime2 (gensym))
	 (gcount (gensym)) (gcount1 (gensym)) (gcount2 (gensym))
	 (rtime (gensym)) (rtime1 (gensym)) (rtime2 (gensym))
	 (etime (gensym)) (etime1 (gensym)) (etime2 (gensym))
	 (threads (gensym)) (newgc (gensym)))
   `(dotimes (con ,concurrency)
      (let ((,gtime 0) ,gtime1 ,gtime2
	    (,gcount 0) ,gcount1 ,gcount2
	    (,rtime 0) ,rtime1 ,rtime2
	    (,etime 0.0) ,etime1 ,etime2 ,threads)
        (thr-setconcurrency (+ 2 con))
	(dotimes (try ,try_count)
          (setq ,gtime1 (sys:gctime)
	        ,rtime1 (runtime)
	        ,etime1 (unix::gettimeofday))
	  (setq ,threads nil)
	  (dotimes (i (1+ con))  (push (thread ,func . ,args) ,threads))
;	  (warn "fork done ~d ~s ~s~%" (1+ con) try ,threads)
          (dolist (thr ,threads) (sys:wait-thread thr))
          (setq ,gtime2 (sys:gctime))
	  (incf ,gtime (+ (- (second ,gtime2) (second ,gtime1))
			  (- (third ,gtime2) (third ,gtime1))))
	  (incf ,gcount (- (first ,gtime2) (first ,gtime1)))
	  (setq ,etime2 (unix::gettimeofday))
	  (incf ,etime (+ (- (first ,etime2) (first ,etime1))
			(* 0.000001 (- (second ,etime2) (second ,etime1)))))
	  (setq ,rtime2 (runtime))
	  (incf ,rtime (- ,rtime2 ,rtime1))
	  )
        (format t ";~d ~d ~f ~f ~f ~f~%"
	   (1+ con) (thr-getconcurrency)
	   (/ ,etime ,try_count)
	   (* 0.01 (/ (float ,rtime) ,try_count))
	   (/ (float ,gcount) ,try_count)
	   (* 0.01 (/ (float ,gtime) ,try_count)))))))



(unless system::*threads* (sys:make-thread 18))

(setq a1 (make-cylinder 50 200))
(setq a2 (make-cylinder 100 100))
(setq a (body- a2 a1))
(setq b (make-cube 20 30 10))

(defun test (n) (dotimes (i n) (body-interference a b)))

(setq x1 (make-list 100))
(setq x2 (make-list 100))
(setq x3 (make-list 100))
(defun testx (n x) (dotimes (i n) (copy-seq x)))

(setq v1 (make-array 100 :element-type :float))
(dotimes (i 100) (setf (aref v1 i) i))
(setq v2 (copy-seq v1))
(setq v3 (copy-seq v1))
(defun testv (n v1 v2) (dotimes (i n) (v. v1 v2)))

(setq c1 (make-list 1000) c2 (make-list 1000))
(defun testc (n c1 c2) (dotimes (i n) (replace c1 c2)))

#|
(setq g (make-icosahedron 100))
(setq g1 (make-gdome g))
(setq g2 (make-gdome g1))
(setq g3 (make-gdome g2))
|#

