;;;; vxweus.l
;;;;	interface between eus and vxwserv
;;;;	1990/Apr/5
;;;;	(c)1990 MATSUI Toshihiro, Electrotechnical Laboratory


(provide 'vxweus)

(eval-when (load eval)
  (unless (fboundp 'vxw)
      (load "contrib/vxworks/vxwcom" :verbose t)))

(defconstant A_CHAR 0)
(defconstant A_SHORT 1)
(defconstant A_LONG 2)
(defconstant A_FLOAT 3)
(defconstant A_DOUBLE 4)
(defconstant A_SYMBOL 5)
(defconstant A_VECTOR 6) 
(defconstant A_STRUCT 7)
(defconstant A_END 8)

(defvar *vxw-socket-address*)
(defvar *vxw-stream*)

(defun connect-vxw (&key (host "asvx0") (port 2200) (buffer-size 16384)
			 (priority 128) (option (logior 4 8 #x10)))
   (setq  *vxw-socket-address*
	  (make-socket-address :domain af_inet
			       :host   host
			       :port   port))
   (setq *vxw-stream* (make-client-socket-stream *vxw-socket-address*))
   (unless (streamp *vxw-stream*)
	(error "cannot connect to ~A:~A" host port))
   (write-byte 0 *vxw-stream*)	;special byte
   (write-byte priority *vxw-stream*)
   (write-byte option *vxw-stream*)
   (write-byte (ldb buffer-size 24 8) *vxw-stream*)
   (write-byte (ldb buffer-size 16 8) *vxw-stream*)
   (write-byte (ldb buffer-size 8 8) *vxw-stream*)
   (write-byte (ldb buffer-size 0 8) *vxw-stream*)
   (finish-output *vxw-stream*)
   *vxw-stream*)


(defun vxw-address (symstr)
   (vxw *vxw-stream* "_findsymbol" :integer (string symstr)))

;; 

(defun vxw-entry (name entry)
   (cond ((get name :vxw-entry))
	 (t (setq entry (vxw *vxw-stream* "_findsymbol" :integer entry))
	    (if (< entry 0) (error "no such vxw entry ~a" entry))
	    (setf (get name :vxw-entry) entry))))

(defmacro defvxw (name entry args &optional (result :integer))
   "(defvxw eus-func-name vxw-entry argument-list result-type)
"
   (let ((entry-address (vxw *vxw-stream* "_findsymbol" :integer entry))
	 (lisp-args args)
	 (result-container))
      (if (< entry-address 0)
	  (error "no such symbol ~A defined on VxW" entry))
      (when (consp result)
	  (setq result (cons 'instantiate result)) )
      `(defun ,name ,args (vxw *vxw-stream* ,entry-address ,result . ,args)))
    )

;(defvxw vadd "_vadd" (v1 v2) (float-vector 3))

