;;;;	loader.l
;;;	EusLisp open, with-open-file, load
;;;
;;;	1987-Apr	created
;;;	1988-May-20
;;;	(c) Toshihiro Matsui, Electrotechnical Laboratory

(list "@(#)$Id$")

(eval-when (load eval)

(in-package "LISP")
(export '(file-write-date file-newer
	open with-open-file probe-file object-file-p
	path-list find-executable *load-path*
	*loader-current-directory* *load-verbose*
	load load-files load-library
	read-file read-strings read-lines read-lists read-binary-file
	read-lines-till-eof
	do-file-line do-file-form
	dump-object dump-structure dump-loadable-structure
	file-size map-file *modules* provide require *loaded-modules*))


;;****************************************************************
;; OPEN and other file manipulation functions
;;****************************************************************

(defun file-write-date (file)
   (nth 9 (unix:stat (namestring file))))

(defun file-newer (new old)
   (or  (null (probe-file old)) (null (probe-file new))
	(> (file-write-date new) (file-write-date old))))

(defun open (file &key (direction :input)
			     (if-exists :new-version)
			     (if-does-not-exist 'default)
			     (permission #o0644)
			     (buffer-size 512))
    (let ((mode 0) (strm) (fname))
	(if (streamp file)
	    (if (io-stream-p file)
		(setq fname ((file . instream) . fname))
		(setq fname (file . fname)))
	    (setq fname file))
	(setq fname (namestring fname))
	(case direction
	   (:input
		(setq mode unix::O_RDONLY)
		(if (eq if-does-not-exist 'default)
		    (setq if-does-not-exist :error))
		(if (eq if-does-not-exist :create) (inc mode unix::O_CREAT))
		(setq strm (sys::openfile fname mode permission buffer-size)))
	   ((:output :io)
		(if (eq direction :io)
		    (setq mode unix::O_RDWR)
		    (setq mode unix::O_WRONLY))
		(case if-exists
		   (:append	(inc mode unix::O_APPEND))
		   ((:new-version :supersede :rename)
				(setq  mode (+ mode unix::O_CREAT unix::O_TRUNC)))
		   (:overwrite	(inc mode unix::O_CREAT))
		   ((nil :error)(setq mode (+ mode unix::O_CREAT unix::O_EXCL)))
		   (t (error "unknown if-exist flag")))
		(case if-does-not-exist
		   (:error (setq mode (logand mode (lognot unix::O_CREAT))))
		   (:create (setq mode (logior mode unix::O_CREAT)))
		   (default (if (not (memq if-exists '(:overwrite :append)))
			        (setq mode (logior mode unix::O_CREAT))))
		   (nil)
		   (t (error "unknown if-does-not-exist flag")))
		(setq strm (sys::openfile fname mode permission buffer-size)) )
	   (t (error "unknown stream direction")) )
;     (format t "mode=~d permission=~d buffer-size=~d~%"
;		 mode permission buffer-size)
      (when (numberp strm)
	    (if (null if-does-not-exist)
	        (return-from open nil)
	        (error (concatenate string "cannot open " fname))))
      strm ) )  )

(eval-when (load eval)

(defmacro with-open-file (fspec &rest bod)
   `(let  ((,(car fspec) (open ,@(cdr fspec))))
        (unwind-protect (progn ,@bod) (close ,(car fspec)))))

(defun probe-file (path)
   (let* ((fname (namestring path)) (stat (unix:stat fname)))
    (if (consp stat)
	(case (logand #o170000 (first stat))
	 (#o140000 :socket)
	 (#o120000 :link)
	 (#o100000 :file)	;regular file
	 (#o060000 :block)	;block device
	 (#o040000 :directory)
	 (#o020000 :character)
	 (#o010000 :fifo)))) )


;; Modified by Y. Kuniyoshi (Dec. 20, 1993)
;;; OBJMAGIC: First 4bytes in the header. nil: don't care, list: either one.

(defconstant objmagic
	(cond ((member :vax *features*) (list #x07 #x01))
	      ((member :irix *features*) (list #x7f #\E #\L #\F))
	      ((member :irix6 *features*) (list #x7f #\E #\L #\F))
	      ((member :mips *features*) (list #x62 #x1))
	      ((member :Solaris2 *features*) (list #x7f #\E #\L #\F))
	      ((member :darwin *features*) (list '(#xcf #xca #xce) '(#xfa #xfe #xfa) '(#xed #xba #xed) '(#xfe #x #xbe #xfe)))
	      ((member :linux *features*) (list #x7f #\E #\L #\F))
	      ((member :cygwin *features*) (list #x4d #x5a #x90 #x00))
; alpha is little endian
	      ((member :alpha *features*) (list #x83 #x1 #x1))
	      (t ;  :sunos4 , other sun
		(list nil nil #x01 '(#x0b #x08 #x07)))))

(defun object-file-p (path)
 (flet ((read-header (path)
	   (let ((header (make-string 4)))
	      (with-open-file (s path) (unix:uread (file-stream-fd s) 
						 header 4))
	      header)))
  (let ((hdrstr (read-header path))
	(cmplist OBJMAGIC))
    (do ((hnum (elt hdrstr 0) (elt hdrstr hptr))
	 (hptr 1 (1+ hptr))
	 (hlen (length hdrstr))
	 (cnum (pop cmplist) (pop cmplist))
	 (ans t)
	 (quit nil))
	((or (null cmplist) (>= hptr hlen) quit) ans)
	(if (and cnum (not (eql hnum cnum))
		 (not (memq hnum cnum)))
	    (setq ans nil quit t))
	)
    )))
;;; Y.K. end

(defun path-list (&optional (pstring (unix:getenv "PATH")))
  (let (path (i 0) j p)
     (while (setq j (position #\: pstring :start i))
	(setq p (subseq pstring i j))
	(push (concatenate string p "/") path)
	(setq i (1+ j)))
     (push (concatenate string (subseq pstring i) "/") path)
     (nreverse path)))

(defun find-executable (progname)
  (if (probe-file progname)
      (truename progname)
      (let* ((pathlist (path-list)) path)
        (while pathlist
	    (setq path  (merge-pathnames progname (pop pathlist)))
	    (if (probe-file (namestring path))
		 (return-from find-executable (truename path)))
		;; should check if path has x bits turned on
	    )
        nil)))

;;;
;;; loader
;;;

(defun system::txtload (fname &optional print)
   (let ((eof (gensym)) form value)
	(with-open-file (s fname)
	  (while (null (eq (setq form (read s nil eof)) eof))
	     (setq value (eval form))
	     (if print (print value)) ))))

(defvar *load-path*
	 (list "./"
		*eusdir*
		(format nil "~alib/" *eusdir*)
		(format nil "~alib/llib/" *eusdir*)
		(format nil "~alib/demo/" *eusdir*)) )

(deflocal *loader-current-directory* (list "./"))
(defvar *load-verbose* nil)
(defvar *loaded-modules* nil)
(defun load-module-file-name (lm) (pathname-name (load-module-object-file lm )))

(defun gencname-tail (&rest lnames)
  "Make symbol name C-language safe."
  ;; moved from comp/comp.l (2017/10/19 furushchev)
  (labels ((cchar-p (c) 
             (or (and (<= #\a c) (<= c #\z)) 
                 (and (<= #\A c) (<= c #\Z)) 
                 (and (<= #\0 c) (<= c #\9)) 
                 (= c #\_)))
           (replace-to-cchars 
               (lnames)
             (let ((lnamestr (reduce 
                              #'(lambda (u v) (format nil "~a~a" u v)) 
                              lnames :initial-value "")))
               (coerce 
                (mapcar 
                 #'(lambda (c) (if (cchar-p c) c #\_)) 
                 (coerce lnamestr cons)) string))))
    (replace-to-cchars lnames)))

(defun load (fname  &key (quote-file  nil)
			  (entry (gencname-tail
			          (concatenate string "___"
			                       (pathname-name fname))))
			  (symbol-input)
			  (symbol-output "")
			  (ld-option "")
			  (verbose *load-verbose*)
			  (print nil)
			  ((:package packag) *package*))
    (let* ((*package*  *package*)  (path) (load-result))
      (labels
	((loader-message (x fn)
	     (if verbose
		 (format t ";; ~Aloading ~A into ~s~%"
			x (namestring fn)  *package*)) )  
	 (do-load (fn)
	   (let ((*loader-current-directory*
			(cons (directory-namestring fn)
			      *loader-current-directory*))
		 (old-module)
		 (binload-result))
	     (setq fn (namestring fn))
	     (cond ((object-file-p fn)
		      (when (setq old-module
				(find  (pathname-name fn)
					*loaded-modules*
					:key #'load-module-file-name
					:test #'equal))
			 (sys::unbinload old-module)
			 (format t ";; ~A is unloaded.~%" old-module))
		      (loader-message "bin" fn)
		      (setq binload-result (system:binload fn entry))
		      (when binload-result
			 (push  binload-result *loaded-modules*))
		      binload-result )
		   (t (loader-message "txt" fn)
		      (system::txtload fn print) t))) )
	 (try-load (path)
	    (let ((oname) (lname))
	        (cond ((member (probe-file path)
			  '(:file :character :fifo :socket))
			(do-load path))
		      ((probe-file (setq oname (merge-pathnames ".dll" path)))
		       (do-load oname))
		      ((probe-file (setq oname (merge-pathnames ".dylib" path)))
		       (do-load oname))
		      ((probe-file (setq oname (merge-pathnames ".so" path)))
		       (do-load oname))
		      ((probe-file (setq oname (merge-pathnames ".o" path)))
		       (do-load oname))
		      ((probe-file (setq lname (merge-pathnames ".l" path)))
		       (do-load lname)))  ) )
	 ) ;local func. def.
      (setq fname (pathname fname))
      (setq *package* (find-package packag))
      (if (and  (pathname-directory fname)
		(eql (first (pathname-directory fname))  :root))
	  (if (null (setq load-result (try-load fname)))
	      (error "file ~s not found" fname)
	      load-result)
	  (progn
	     (dolist (p (union *loader-current-directory* *load-path*
			       :test #'string=))
	        (setq path (concatenate-pathnames  p fname))
		(setq load-result (try-load path))
		(if load-result (return-from load load-result)))
	      (error "file ~s not found" fname)))   )) )

(defun load-files (&rest files)
   (dolist (f files)  (load f :verbose t))
   t)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; handy file reader functions
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun read-file (file)
  (with-open-file (in file) (read in)))

(defun read-strings (infile)
  (with-open-file (in infile)
     (let ((line) (eof (cons nil nil)) lines)
       (while (not (eql (setq line (read-line in nil eof)) eof))
	  (push line lines) (push "
" lines))
       (apply #'concatenate string (nreverse lines)))))

(defun read-lines (infile)
  (with-open-file (in infile)
     (let ((line) (eof (cons nil nil)) lines)
       (while (not (eql (setq line (read-line in nil eof)) eof))
	  (push line lines))
       (nreverse lines))))

(defun read-lists (file-name)
   (let ((eof (cons nil nil)) (x) (lists))
      (with-open-file (f file-name)
	 (while (not (eql (setq x (read f nil eof)) eof)) (push x lists))
	 )
      (nreverse lists))
   )

(defun read-binary-file (fname)
   (let* ((size (file-size (namestring fname))) (size2)
	  (buf  (make-string size)))
      (with-open-file (f fname)
	  (setq size2
		(unix:uread (send f :infd) buf size))
	  (if (/= size size2)
	      (error "cannot read binary file"))
	  )
      buf))

(defun read-lines-till-eof (str)
   (let ((lines) (line) (eof (cons nil nil)))
      (while (not (eql (setq line (read-line str nil eof)) eof))
         (push line lines))
      (nreverse lines)))

;;
;; (do-file-line (line-var "filename" :direction :input) (print line-var) ...)
;;
;; repeat forms to each line of a file
;;
(defmacro do-file-line (arg &rest forms)
   (let ((file-stream (gensym)) (eof (gensym)))
     `(with-open-file (,file-stream . ,(cdr arg))
	 (let ((,eof (cons nil nil)) (,(car arg)))
	    (while (not (eql ,eof
			    (setq ,(car arg) (read-line ,file-stream nil ,eof))))
		. ,forms)))
     ))

(defmacro do-file-form (arg &rest forms)
   (let ((file-stream (gensym)) (eof (gensym)))
     `(with-open-file (,file-stream . ,(cdr arg))
	 (let ((,eof (cons nil nil)) (,(car arg)))
	    (while (not (eql ,eof
			    (setq ,(car arg) (read ,file-stream nil ,eof))))
		. ,forms)))
     ))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; load-library
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

#+(and :Solaris2 (not :gcc))

  (defun load-library (file &rest load-args)
    (system::list-module-initializers)
    (let ((libmod (apply #'load file :entry nil load-args))
	  (modinits (sys::list-module-initializers))
	  (modnames))
      (dolist (m modinits)
	(funcall (second m) (second m))
	(push (first m) modnames))
      (nreverse modnames)))

#-(and :Solaris2 (not :gcc))

  (defun load-library (file modules &rest load-args)
    (let* ((libmod (apply #'load file :entry nil load-args))
	   (modinits (system::list-module-initializers libmod modules))
	   (modnames))
      (dolist (m modinits)
	(when (unix:isatty *standard-input*)
	  (format *error-output* "~a " (first m))
	  (finish-output *error-output*))
	(funcall (second m) (second m))
	(push (first m) modnames))
      (nreverse modnames)))


;; write out internal structures to files
;;
(defun dump-object (file &rest objects)
   (let
      ((*print-object* t) (*print-circle* t)
	(*print-level* nil) (*print-length* nil))
      (if (streamp file)
	  (dolist (obj objects) (print obj file))
	  (with-open-file (f file :direction :output)
             (dolist (obj objects) (print obj f))))))

(defun dump-structure (file &rest objects)
   (let
      ((*print-structure* t) (*print-circle* t)
	(*print-level* nil) (*print-length* nil))
      (if (streamp file)
	  (dolist (obj objects) (print obj file))
	  (with-open-file (f file :direction :output)
             (dolist (obj objects) (print obj f))))))

(defmacro dump-loadable-structure (file &rest symbols)
   (let ((objects))
     (dolist (s symbols)
	(push (list 'quote (list 'setq s
				 (list 'quote (symbol-value s))))
	      objects))
     `(dump-structure ,file . ,(reverse objects))))

(defun file-size (f)
    (setq f (namestring f))
    (if (probe-file f)
	(elt (unix:stat (namestring f)) 7)
	(error "file ~s not found" f)
	))

(defun directory-p (f &aux stat)
   (if (consp (setq stat (unix:stat f)))
	(= (logand #x4000 (elt stat 0)) #x4000)) )

(defun map-file (fname &key (direction :input)
			    (offset 0)
			    (length nil)
			    (protection nil)
			    (share t)
			    (private nil)
			    (address 0))
    (let* ((strm)  (flag 0)  (mmap-string))
      (setq strm (open fname :direction direction :if-exists :append)) 
      (unless length (setq length (file-size fname)))
      (unless protection
	 (setq protection
	       (cdr (assq direction '((:input . 1) (:output . 2) (:io . 3))))))
      (if share (setq flag 1))
      (if private (setq flag 2))
      (setq mmap-string
	    (unix:mmap address length protection flag strm offset))
      (close strm)
      mmap-string))

)

(defvar *modules* nil)

(defun provide (module-name &rest version-info)
   (unless (keywordp module-name)
      (setq module-name
	    (intern (string-upcase (string module-name)) *keyword-package*)) )
   (unless (assoc module-name *modules*)
     (setq *modules*
	   (nconc *modules* (list (list* module-name version-info)))))
   module-name)


(defun require (module-name &rest load-arg #|usually a path :package ... |# )
   (unless (keywordp module-name)
      (setq module-name
	    (intern (string-upcase (string module-name)) *keyword-package*)) )
   (unless (assoc module-name *modules*)
	(unless (stringp (car load-arg))
	    (push (string-downcase (string module-name)) load-arg))
	(apply #'load load-arg)
	(provide module-name)))


