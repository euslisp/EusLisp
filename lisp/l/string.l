;;;
;;;	string.l
;;;	1987-Apr
;;;	(c)T.Matsui
;;
;; 	character types
;;
(list "@(#)$Id$")

(in-package "LISP")
(export '(true-string string make-string string-left-trim
	string-right-trim string-trim nstring-downcase
	nstring-upcase string-upcase string-downcase string= string-equal
	substringp pathname pathnamep pathname namestring pathname-directory
	pathname-name pathname-type directory-namestring make-pathname
	parse-namestring *default-pathname-defaults* null-string-p
	merge-pathnames concatenate-pathnames truename
	url-pathname parse-url escape-url escaped-url-string-from-namestring unescape-url unescaped-url-string-from-namestring
	sequential-file-name dated-file-name timed-file-name digits-string
	))


;(defun digit-char-p (ch) (position ch "0123456789"))
;(defun alpha-char-p (ch)
;  (position ch "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"))
;(defun upper-case-p (ch)  (position ch "ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
;(defun lower-case-p (ch)  (position ch "abcdefghijklmnopqrstuvwxyz"))
;(defun alphanumericp (ch) (or (alpha-char-p ch) (digit-char-p ch)))
;

(defun read_sharp_backslash (strm char num)
   (let (ch mnemonic code)
      (setq ch (read-char strm))
      (cond ((alpha-char-p ch)
	     (unread-char ch strm)
	     (setq mnemonic (read strm))
	     (setq code (assoc (mnemonic . pname) 
		       '(("space" 32) ("rubout" 127) ("delete" 127)
			 ("newline" 10) ("linefeed" 10) 
			 ("page" 12) ("formfeed" 12)  ("backspace" 8)
			 ("return" 13) ("esc" #x1b) ("escape" #x1b)
			 ("bell" 7) ("tab" 9)
			 ("null" 0)
			 ("soh" 1) ("stx" 2) ("etx" 3)
			 ("left-paren" #\( ) ("right-paren" #\) )
			 ("lparen" #\( ) ("rparen" #\) )
			)
				:test #'string-equal))
	     (if code
		 (cadr code)
		 (if (= (length (mnemonic . pname)) 1)
		     ch
		     (error "unknown #\ code"))))
	    (t ch))))

(set-dispatch-macro-character #\# #\\ 'read_sharp_backslash)




;string functions
;
(eval-when (load eval)
(defun true-string (s)
   (if (symbolp s) (symbol-pname s) s))

(defun string (x)
  (cond ((stringp x) x)
	((symbolp x) (copy-seq (symbol-pname x)))
	((numberp x) (princ-to-string x))
	(t (error "cannot coerce to string " x))))

(defun make-string (size) (instantiate string size))

(defun string-left-trim (bag str)
   (declare  (string str))
   (let ((n 0))
	(declare (type integer n))
	(setq str (true-string str))
	(while (position (char str n) bag) (inc n))
	(subseq str n (length str))))

(defun string-right-trim (bag str)
   (declare  (string str))
   (let ((leng (length str)))
	(setq str (true-string str))
	(while (position (char str (1- leng)) bag) (dec leng))
	(subseq str 0 leng)))

(defun string-trim (bag str)
   (string-left-trim bag (string-right-trim bag str)))

(defun nstring-downcase (str &key (start 0) (end (length str)))
   (declare (type integer start end) (string str))
   (if (not (stringp str)) (error "no string"))
   (while (< start end)
	(setchar str start (char-downcase (char str start)))
	(inc start))
   str)

(defun nstring-upcase (str &key (start 0) (end (length str)))
   (declare (type integer start end))
   (if (not (stringp str)) (error "no string"))
   (while (< start end)
	(setchar str start (char-upcase (char str start)))
	(inc start))
   str)

(defun string-upcase (str &key (start 0) (end))
   (let ((coerced-string (copy-seq (true-string str))))
      (nstring-upcase coerced-string :start start
		:end (if end end (length coerced-string)) )))
(defun string-downcase (str &key (start 0) (end))
   (let ((coerced-string (copy-seq (true-string str))))
      (nstring-downcase coerced-string :start start
		:end (if end end (length coerced-string)) )))

(defun string= (str1 str2 &key (start1 0) (end1 100000000)
		     (start2 0) (end2 100000000))
  (stringeq str1 str2 start1 end1 start2 end2))

(defun string-equal (str1 str2 &key (start1 0) (end1 100000000)
			  (start2 0) (end2 100000000))
  (stringequal str1 str2 start1 end1 start2 end2))
(defun substringp (sub str)
  (do ((i (- (length str) (length sub)))
       (l (length sub))
       (j 0 (1+ j)))
      ((> j i) nil)
    (when (string-equal sub str :start2 j  :end2 (+ j l))
          (return-from substringp t))))

(defmethod string
  (:get (pos type) (sys:peek self pos type) )
  (:set (val pos type)
     (if (numberp val)
	 (sys:poke val self pos type)
	 (let ((offset (cdr (assoc type
#-(or :alpha :irix6 :x86_64 :aarch64)
		 '((:short . 2) (:long . 4) (:byte . 1) (:char . 1)
		   (:int . 4) (:integer . 4) (:float . 4) (:double . 8))
#+(or :alpha :irix6 :x86_64 :aarch64)
		 '((:short . 2) (:long . 8) (:byte . 1) (:char . 1)
		   (:int . 4) (:integer . 4) (:float . 4) (:double . 8))
		 ))))
	    (dolist (v (flatten val))
		(cond ((numberp v) 
			(sys:poke (round v) self pos type)
			(incf pos offset))
		      (t (dotimes (i (length v))
	                    (sys:poke (round (elt v i)) self pos type)
		            (incf pos offset) ) ) ) ) ) ) )
  )



) ;eval-when

;;;;*************************************************************
;;;; P A T H N A M E S
;;;;*************************************************************

(eval-when (load eval)

(defclass pathname :super object
		   :slots (host device directory name type version))
(export '(pathname-host pathname-device pathname-directory
	pathname-name pathname-type pathname-version))

(defun explode-directory-names (dirnames)
   (let ((dirstr) (dirlist) (slash 0) s)
	(while (setq s (position #\/ dirnames :start slash))
	    (setq dirstr (subseq dirnames slash s))
	    (if (> (length dirstr) 0) (push  dirstr dirlist))
	    (setq slash (1+ s) )
	    )
	(setq dirstr (subseq dirnames slash))
	(if (> (length dirstr) 0) (push dirstr dirlist))
	dirlist))

(defmethod pathname
  (:parse-namestring (pn)
      (let* ((colon 0)
	     (slash 0)
	     (period 0)
	     (dirstr) (namestr)
	     i
	     s)
	(setq directory nil)
	(when (zerop (length pn))
	    (setq host "" device "")
	    (return-from :parse-namestring self))
	(when (setq s (position #\: pn))
	    (setq colon s host (subseq pn 0 colon) colon (1+ colon)))
	(setq slash colon)
	(cond ((eql (elt pn slash) #\/) (push :root directory) (incf slash))
	      ((eql (elt pn slash) #\~)
		 (setq directory
			(explode-directory-names
				 	(unix:getenv "HOME")))
		 (setq directory (nconc directory (list :root)))
		 (incf slash)))
	(while (setq s (position #\/ pn :start slash))
	    (setq dirstr (subseq pn slash s))
	    (if (> (length dirstr) 0) (push  dirstr directory))
	    (setq slash (1+ s) period slash))
	(setq directory (nreverse directory))
;
	(setq namestr (subseq pn slash))
	(cond ((equal namestr "..")
		(setq name namestr type nil))
	      (t
		(setq period (position #\. pn :start slash))
		(cond ((null period)
			(if (> (length pn) slash) (setq name (subseq pn slash))))
		      (t
		       (setq period (1+ period))
		       (while (setq s (position #\. pn :start period))
			   (setq period (1+ s)))
		       (setq name (subseq pn slash (1- period))
			     type (subseq pn period))
		       (if (null-string-p name) (setq name nil))))))
	self))
 (:directory-string ()
    (let (ds (dir directory))
	(when (eql (car directory) :root) (pop dir) (push "/" ds)) 
	(dolist (d dir)   (push d ds) (push "/" ds))
	(setq ds (nreverse ds))
        (apply #'concatenate string ds)))
 (:namestring ()
    (let ((fdir (send self :directory-string))
	  (ftype (if type (concatenate string "." type))))
       (if name
           (concatenate string host device fdir name ftype)
	   (concatenate string host device fdir ftype))))
 (:host (&optional h)
    (if h (setq host h) host))
 (:device (&optional d)
    (if d (setq device d) device))
 (:directory (&optional d)
    (if d (setq directory d)  directory))
 (:name (&optional n) 
    (if n (setq name n) name))
 (:type (&optional tp)
    (if tp (setq type tp) type))
 (:set-type (tp) (setq type tp))
 (:version (&optional v)
    (if v (setq version v) version))
 (:merge (defaults)
    (if (null host) (setq host (defaults . host)))
    (if (null device) (setq device (defaults . device)))
    (if (null directory) (setq directory (defaults . directory)))
    (if (null name) (setq name (defaults . name)))
    (if (null type) (setq type (defaults . type)))
    (if (null version) (setq version (defaults . version)))
    self)
 (:add-directory (d)	; d is a list of directory names
    (setq directory (nconc directory (mapcar #'string d))))
 (:prin1 (&optional (strm t))
    (format strm "#P~S" (send self :namestring)))
 (:init (&key ((:host hst)) ((:device dev)) ((:directory dir))
	      ((:name nm)) ((:type tp)) ((:version vers)))
    (if hst (setq host hst))
    (if dev (setq device dev))
    (if dir (setq directory dir))
    (if nm (setq name nm))
    (if tp (setq type tp))
    (if vers (setq version vers))
    self)
)

(defun pathnamep (p) (derivedp p pathname))
(defun pathname (p)
  (if (derivedp p pathname)
      p
      (if p
	  (instance pathname :parse-namestring (string p))
	  (instantiate pathname))) )
(defun namestring (p)
   (cond ((symbolp p) (string p))
	 ((stringp p) p)
	 ((pathnamep p) (send p :namestring))
	 (t (error "not a pathname ~s" p))))

(defun pathname-directory (s) ((pathname s) . directory))
(defun pathname-name (s) ((pathname s) . name))
(defun pathname-type (s) ((pathname s) . type))
(defun directory-namestring (s)  (send (pathname s) :directory-string))

(defun make-pathname (&key host device directory name type version defaults)
  (send (instance pathname :init
				:host 	host
				:device device
				:directory directory
				:name 	name
				:type 	type
				:version version)
	:merge (pathname defaults)))

(defun parse-namestring (pn) (pathname pn))

(defparameter *default-pathname-defaults*
	(list "" "" "" "l"))

(defun null-string-p (s) (equal s ""))

(defun merge-pathnames (pathnam
			 &optional (defaults *default-pathname-defaults*))
   (setq pathnam 
	 (if (pathnamep pathnam)
	     (copy-object pathnam)
       	     (pathname pathnam)))
   (send pathnam :merge (pathname defaults)))

(defun concatenate-pathnames (&rest paths)
   (pathname (apply #'concatenate string
		    (mapcar #'namestring paths))))

(defun truename (pathnam)
"BUG: (truename \"/a/\") returns #P\"/a/NIL\""
   (setq pathnam (pathname pathnam))
   (let* ((current-dir (unix:getwd)) 
	  (pathdir (send pathnam :directory-string))
	  (target-dir t))
      (if pathdir (setq target-dir (unix:chdir pathdir)))
      (cond ((eq target-dir t)
		(setq target-dir (unix:getwd))
		(if (> (length target-dir) 1)
		    (setq target-dir (concatenate string target-dir "/")))
		(unix:chdir current-dir)
		(make-pathname :name (pathname-name pathnam)
				:type (pathname-type pathnam)
				:directory (pathname-directory target-dir))
;		(merge-pathnames
;			 (pathname-name pathnam) target-dir)
		)
	    (t (error "cannot locate the file"))))  )

)

;****************************************************************
; URL
;****************************************************************
(defclass url-pathname :super pathname
	:slots (protocol server port))

(defmethod url-pathname
  (:prin1 (strm)
     (format strm "#<~a #x~x \"~a\">"
	(send class :name)
	(sys:address self)
	(send self :string)))
  (:string ()
     (format nil "~a://~a:~a~a"
	protocol server port (namestring self) ))
  (:string2 ()
     (format nil "~a://~a~a"
	protocol server  (namestring self) ))
  (:port (&optional p) (if p (setq port p)) port)
  (:server (&optional s) (if s (setq server s)) server)
  (:connect (&optional (time-out 5))
     (connect-server server port time-out))
  (:host (&optional s) (if s (setq server s)) server)
  (:protocol (&optional proto) (if proto (setq protocol proto)) protocol)
  (:parse-namestring (url-string)
     (let ((index 0) (port-index) (dir-index))
	(if (setq index (position #\: url-string))
	    (setq protocol (subseq url-string 0 index)
		  index  (1+ index))
	    (setq protocol "http" index 0))
        (cond ((and (eql (aref url-string index) #\/)
		    (eql (aref url-string (1+ index)) #\/))
	    (setq dir-index 
		  (position #\/ url-string :start (+ 3 index)))
	    (unless dir-index (setq dir-index (length url-string)))
	    (setq server
		  (subseq url-string (+ 2 index) dir-index))
	    (if (setq port-index (position #\: server))
		(setq port (read-from-string (subseq server (1+ port-index)))
		      server (subseq server 0 port-index))
		(setq port 80))
	    (send-super :parse-namestring  (subseq url-string dir-index))
	    (setq directory 
		  (append '(:root ) (rest directory)))
	    self)
	      (t (error "cannot parse url ~a" url-string)) )) 
      )
  (:percent-escape (&key (queryp t) (revert nil))
   (send self :parse-namestring
    (if revert
        (unescaped-url-string-from-namestring
         (send self :string) queryp)
        (escaped-url-string-from-namestring
         (send self :string) queryp)))))

(defun url-pathname (p)
  (if (derivedp p url-pathname)
      p
      (if p
	  (instance url-pathname :parse-namestring (string p))
	  (instantiate url-pathname))) )

(defun parse-url (url-string)
   (let ( (protocol "http") (server) (file) (port 80)
	 (index 0) (port-index))
	(if (setq index (position #\: url-string))
	    (setq protocol (subseq url-string 0 index)
		  index  (1+ index))
	    (setq index 0))
        (cond ((and (eql (aref url-string index) #\/)
		    (eql (aref url-string (1+ index)) #\/))
	    (setq server
		  (subseq url-string (+ 2 index)
			(setq index 
			      (position #\/ url-string :start (+ 3 index)))))
	    (if (setq port-index (position #\: server))
		(setq port (read-from-string (subseq server (1+ port-index)))
		      server (subseq server 0 port-index))
		(setq port 80))
	    (setq file (pathname (subseq url-string index)))
	    (send file :directory (append '(:root #| "usr" "www" "data" |#)
				  (rest (send file :directory))))
	    (list protocol server port file))
	      (t (error "cannot parse url ~a" url-string)) )) 
  )  

(defvar *url-escape-unreserved-characters* "-_.~:/=?&")

(defun escape-url (str &optional (ss *standard-output*) (queryp t))
  "Return percent-escaped url string stream. If given with queryp to t, Space is escaped as '+'."
  (labels ((url-escape-unreserved-char-p (c)
             (or (<= #\A c #\Z)
                 (<= #\a c #\z)
                 (<= #\0 c #\9)
                 (find c *url-escape-unreserved-characters*
                       :test #'lisp::char=)))
           (zero-padding (s desired-str-len)
             (with-output-to-string (o)
               (dotimes (i (- desired-str-len (length s)))
                 (write-byte #\0 o))
               (format o s)
               (get-output-stream-string o))))
    (dolist (c (coerce str cons))
      (cond
        ((url-escape-unreserved-char-p c)
         (write-byte c ss))
        ((lisp::char= c #\Return)
         (write-byte #\Newline ss))
        ((and queryp (lisp::char= c #\Space))
         (write-byte #\+ ss))
        (t
         (format ss "%~A" (zero-padding
                           (format nil "~X" c) 2)))))))

(defun escaped-url-string-from-namestring (url-string &optional (queryp t))
  (with-output-to-string (ss)
    (escape-url url-string ss queryp)
    (get-output-stream-string ss)))

(defun unescape-url (str &optional (ss *standard-output*) (queryp t))
  (with-input-from-string (is str)
    (while (peek-char is nil)
     (case (peek-char is)
       (#\%
        (read-char is) ;; skip #\%
        (write-byte (read-from-string
                     (coerce
                      (list #\# #\x
                            (read-char is)
                            (read-char is))
                      string))
                    ss))
       (#\+
        (if queryp
            (progn
              (read-char is) ;; skip #\+
              (write-byte #\Space ss))
            (write-byte (read-char is) ss)))
       (t
        (write-byte (read-char is) ss))))))

(defun unescaped-url-string-from-namestring (url-string &optional (queryp t))
  (with-output-to-string (ss)
    (unescape-url url-string ss queryp)
    (get-output-stream-string ss)))

;****************************************************************
; file name generation
;****************************************************************

(defun digits-string (n digits &optional (base 10))
   (if  (<= digits 1)
	(format nil "~d" (- n (* (/ n base) base)))
	(concatenate string
		     (digits-string (/ n base) (1- digits))
		     (digits-string n 1)) )
  )

(defun timed-file-name (head extension &optional (dt (unix:localtime)))
    (format nil "~a~2a~2a~2a.~a"
	head
	(digits-string (aref dt 2) 2)
	(digits-string (aref dt 1) 2)
	(digits-string (aref dt 0) 2)
	extension))

(defun dated-file-name (head extension &optional (dt (unix:localtime)))
    (format nil "~a~2a~3A~2a.~a"
	head 
	(digits-string (aref dt 5) 2)
	(second (assoc (aref dt 4)
			'((0 "Jan") (1 "Feb") (2 "Mar") (3 "Apr")
			  (4 "May") (5 "Jun") (6 "Jul") (7 "Aug")
			  (8 "Sep") (9 "Oct") (10 "Nov") (11 "Dec"))
			))
	(digits-string (aref dt 3) 2)
	extension))

(defun sequential-file-name (head num extension &optional (digits 4))
   (format nil "~a~a.~a" head (digits-string num digits) extension))

