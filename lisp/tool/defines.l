(defun put-defines (exp out)
   (case (car exp)
	((defun defmacro defvar defparameter defconstant defclass)
	 (print (cadr exp) out))
	((defmethod setq send nil) nil)
	(t (if (listp exp)
		(dolist (x exp) (if (consp x) (put-defines x out)))))))


(defun defines (file &optional (outfile *standard-output*))
  (with-open-file (out outfile :direction :output)
   (with-open-file (f file)
    (let ((eof (cons nil nil)) (exp))
	(while (not (eq (setq exp (read f nil eof)) eof))
	   (case (car exp)
		(eval-when (put-defines (cddr exp) out))
		(progn (put-defines (cdr exp) out))
		(t (put-defines exp out)))))
  )))


