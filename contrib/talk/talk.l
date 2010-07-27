(defvar *db*)
(defvar *line*)

(defun freq (str)
   (let ((freqv (make-array 27 :element-type :integer)))
      (setq str (string-downcase str))
      (dotimes (i (length str))
         (let ((c (char str i)))
	    (cond ((member c '(#\space #\tab))
		   (incf (aref freqv 0)))
		  ((alpha-char-p c)
		   (incf (aref freqv (- c #\a -1)))))))
      freqv))

(defun hamming (v1 v2)
   (let ((s 0))
    (dotimes (i 27)
	%(s = s + abs(v1[i] - v2[i]))
;;	(incf s (abs (- (aref v1 i) (aref v2 i))))
        )
    s))


(defun write-database (&optional (fname "talk-db") (a *db*))
   (with-open-file (f fname :direction :output)
      (print (length a) f)
      (dolist (x a)
         (print x f))))


(defun read-database (&optional (fname "talk-db"))
   (let (a x (eof (cons () ())) leng)
     (with-open-file (f fname)
	(setq leng (read f))
	(dotimes (i leng)
	    (push (read f) a))
	)
     (nreverse a)) )

(defun answer (frq)
  (let  ((s 1000000) s1 candidates)
     (dolist (d *db*)
        (setq s1 (hamming frq (car d)))
	(cond ((< s1  s)
		(setq s s1 candidates (list d)))
	      ((= s1 s)
		(push d candidates))))
     (elt candidates (random (length candidates)))
     ))

(defun remember (q a)
   (let ((q-freq (freq q)))
	(push (list q-freq q a) *db*)))

(defun talk ()
   (setq *db* (read-database))
   (format t "Welcome to eus talk. Type bye to finish.~%")
   (let ((count 0) ans (mytalk "Hello"))
      (loop
	 (format t "--> ~a~%<-- " mytalk)
         (finish-output t)
	 (setq *line* (read-line))
	 (if (string-equal *line* "bye") (return count))
	 (remember mytalk *line*)
	 (setq ans (answer (freq *line*)))
	 (setq mytalk (third ans))
	 (incf count))
      )
   (write-database)
)

;;

(eval-when (load eval)
  (if   (y-or-n-p "start talk? ")
	(talk)
	nil))



