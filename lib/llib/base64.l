;;;; base64encode
;;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;
;;; "Aladdin:open sesame" is converted to
;;; "QWxhZGRpbjpvcGVuIHNlc2FtZQ=="

(export '(base64encode base64decode))

(defun bin2base64 (x)
   (cond ((< x 26) (+ x #\A))
	 ((< x 52) (+ x #\a -26))
	 ((< x 62) (+ x #\0 -52))
	 ((= x 62) #\+)
	 ((= x 63) #\/)
	 (t (error "bin2base64 out-of-range"))))

(defun base64tobin (x)
    (cond ((<= #\A x #\Z) (- x #\A))
	  ((<= #\a x #\z) (- x #\a -26))
	  ((<= #\0 x #\9) (- x #\0 -52))
	  ((= x #\+) 62)
	  ((= x #\/) 63)
	  ((= x #\=) 77)
	  (t (error "base64tobin out-of-range ~a" x)) ))

(defun base64encode (binstr)
   (let ((mode 0) (byte1)
	 (len (length binstr)) (j 0) (x) (outcount 0))
     (with-output-to-string (s)
      (while (< j len)
	 (setq byte1 (char binstr j))
	 (case mode
	 (0  (setq x (ash byte1 -2)))
	 (1  (setq x (ash (logand byte1 3) 4))
	     (incf j)
	     (when (< j len)
		(setq byte1 (char binstr j))
		(incf x (ash byte1 -4))))
	 (2  (setq x (ash (logand byte1 #x0f) 2))
	     (incf j)
	     (when (< j len)
		(setq byte1 (char binstr j))
		(incf x  (ash byte1 -6))))
	 (3  (setq x (logand byte1 #x3f))
	     (incf j)))
	 (setq  mode (mod (1+ mode) 4))
         (write-byte (bin2base64 x) s)
	 (if (zerop (mod (incf outcount) 76)) (terpri s))
	 )
      (when (> mode 0)
	 (format s "=")
	 (if (zerop (mod (incf outcount) 76)) (terpri s))
	 (when (< mode 3)
	    (format s "=")
	    (if (zerop (mod (incf outcount) 76)) (terpri s)))
	 )
      (get-output-stream-string s))))

(defun base64decode (ascstr)
   (let ((x) (a) (b) (len (length ascstr)) (j 0) (mode 0))
     (with-output-to-string (s)
      (while (< j len)
	 (setq a (aref ascstr j))
	 (incf j)
	 (when (and (> a 33) (/= a #\=))
	   (setq b (base64tobin a))
	   (case mode
	   (0 (setq x (ash b 2)))
	   (1 (setq x (logior x (ash b -4)))	;previous 2bits +4
	      (write-byte x s)
	      (setq x (ash (logand b #xf) 4)))  ; forward 2bits
	   (2 (setq x (logior x (ash b -2)))	;2+4 bits
	      (write-byte x s)
	      (setq x (ash (logand b 3) 6)))	;next 2bits
	   (3 (setq x (logior x b))
	      (write-byte x s)) )
	   (setq mode (mod (incf mode) 4)))
	 )
     (if (> mode 0) (write-byte x s))
     (get-output-stream-string s))))

#|

(base64decode (print (base64encode "mats")))
(base64decode (print (base64encode "matsu")))
(base64decode (print (base64encode "matsui")))
(base64decode (print (base64encode "matsuit")))
(base64decode (print (base64encode "matsuito")))

|#


