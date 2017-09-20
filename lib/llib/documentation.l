;;
;;

(defun escape-string (str)
  (let ((ret ""))
    (dotimes (i (length str))
      (cond ((eq (schar str i) #\")
             (setq ret (concatenate string ret "\'\'")))
            ((eq (schar str i) #\*)
             (setq ret (concatenate string ret "\\textasteriskcentered ")))
            ((eq (schar str i) #\<)
             (setq ret (concatenate string ret "\\textless ")))
            ((eq (schar str i) #\>)
             (setq ret (concatenate string ret "\\textgreater ")))
            ((eq (schar str i) #\\)
	     (setq ret (concatenate string ret (format nil "~c" (schar str i))))(incf i)
	     (setq ret (concatenate string ret (format nil "~c" (schar str i)))))
            (t
             (if (memq (schar str i) '(#\& #\# #\* #\_)) (setq ret (concatenate string ret "\\")))
             (setq ret (concatenate string ret (format nil "~c" (schar str i)))))))
    ret))

(defun make-doc-string (doc)
  (let ((ret ""))
    (if (= (length doc) 0) (setq doc nil))
    (case *output-format*
	  (:html
	   (cond ((null doc)
		  doc)
		 (t
		  (dotimes (i (length doc))
		    (cond ((eq (schar doc i) #\newline)
			   (setq ret (concatenate string ret (format nil "\\\\~%"))))
			  (t
			   (setq ret (concatenate string ret (format nil "~c" (schar doc i)))))))
		  ret)))
	  (:md
	   (cond ((null doc)
		  doc)
		 (t
                  (let ((s (make-string-input-stream doc)) l pre)
                    (while (setq l (read-line s nil nil))
                      (cond ((and (> (length l) 0) (= (elt l 0) #\tab))
                             (if (null pre) (setq ret (concatenate string ret (format nil "~%"))))
                             (setq ret (concatenate string ret (format nil "        ~A~%" (subseq l 1)))) ;; 8 space is code block
                             (setq pre t))
                            (t
                             (setq ret (concatenate string ret (format nil "~A <br>~%" l)) pre nil)))))
		  ret))))
    ))

(defun make-arg-string (doc args type)
  (let (arg has-key (args-str ""))
    (setq *has-key* nil)
    (case *output-format*
	  (:html
	   (dotimes (i (length args))
	     (setq arg (elt args i))
	     (if has-key (setq args-str (format nil "~A\\\\~%\\> " args-str)))
	     (setq args-str (concatenate string args-str (format nil "~A "  arg)))
	     (when (and doc (eq arg '&key) (> (- (length args) i) 2))
	       (setq args-str (format nil "~A\\= " args-str) has-key t)
	       (incf i)
	       (setq arg (elt args i))
	       (setq args-str (concatenate string args-str (format nil "~A \\` [~A]" arg type)))))
	   )
	  (:md
	   (cond ((null doc)
		  (dolist (arg args)
		    (setq args-str (concatenate string args-str (format nil "*~A* " arg)))))
		 (t
		  (if args (setq args-str "&nbsp;&nbsp;&nbsp;"))
		  (dotimes (i (length args))
		    (setq arg (elt args i))
		    (if has-key (setq args-str (format nil "~A<br>&nbsp;&nbsp;&nbsp;" args-str)))
		    (setq args-str (concatenate string args-str (format nil "*~A* "  arg)))
		    (when (and doc (eq arg '&key) (> (- (length args) i) 2))
		      (setq has-key t)
		      (incf i)
		      (setq arg (elt args i))
		      (setq args-str (concatenate string args-str (format nil "*~A* " arg))))))
		 )
	   ))
    (setq *has-key* has-key)
    args-str))

(defun write-classdesc (cls &optional (super (send cls :super)) (slots (cdr (coerce (send cls :slots) cons))))
             (let (slots-str (doc-str ""))
               (dolist (slot slots)
                 (setq slots-str (concatenate string slots-str (format nil "~A " slot))))
               (if (documentation cls)
                   (setq doc-str (make-doc-string (documentation cls))))
               (case *output-format*
                     (:html
                      (format t "~A" (escape-string (format nil "\\classdesc{~A}{~A}{~A}{~A}~%" (send cls :name) (send super :name) slots-str doc-str))))
                     (:md
                      (format t "### ~A~%- :super **~A**~%- :slots ~A~%~%~A~%~%" (send cls :name) (send super :name) slots-str doc-str)))
               ))
           

(defun make-method-document (cls methods)
  (labels ((write-methoddesc (method args doc)
             (let (args-str)
	       (setq doc (make-doc-string doc))
	       (setq args-str (make-arg-string doc args "method"))
               (case *output-format*
                     (:html
		      (cond ((null doc)
			     (format t "~A" (escape-string (format nil "\\metdesc{~A}{~A}{}~%" method args-str))))
			    (*has-key*
			     (format t "~A" (escape-string (format nil "\\longdescription{~A}{~A}{~A}~%" method args-str doc))))
			    (t
			     (format t "~A" (escape-string (format nil "\\methoddesc{~A}{~A}{~A}~%" method args-str doc))))))
                     (:md
                      (cond ((null doc)
			     (format t "~A ~A~%~%" method args-str))
			    (t
			     (format t "#### ~A~%~A~%~%- ~A~%~%" method args-str doc))
			    )));; case
               )));; label
           (let ((method-with-document) (method-without-document))
             (dolist (method methods)
               (cond ((stringp (third method))
                      (push method method-with-document))
                     ((listp (second method))
                      (push method method-without-document))
                     (t
                      (warning-message 1 ";; re-defined method? ~A in ~A~%" (car method) (send cls :name))
                      )))
             (dolist (method method-with-document)
               (write-methoddesc (first method) (second method) (third method)))
             (case *output-format*
                   (:html
                    (format t "{\\footnotesize ~%"))
                   (:md
                    ))
             (dolist (method method-without-document)
               (write-methoddesc (first method) (second method) ""))
             (case *output-format*
                   (:html
                    (format t "\\vspace*{-5mm}~%"))
                   (:md
                    ))
             (case *output-format*
                   (:html
                    (format t "}~%"))
                   (:md
                    ))
             )
           (format t "~%")
           ))


(defun make-class-document (cls super slots)
  (let ()
    (cond ((eq (class cls) metaclass)
           (write-classdesc cls super slots)
           (make-method-document cls (reverse (send cls :methods)))
           ))
  ))

(defun make-function-document (funcname args)
  (let (args-str doc has-key)
    (if (stringp (documentation funcname)) (setq doc (documentation funcname)))
    (if (null doc)
        (case *output-format*
              (:html
               (format t "{\\footnotesize~%"))
              (:md
               )))
    (setq args-str (make-arg-string doc args "function"))
    (setq doc (make-doc-string doc))
    (case *output-format*
          (:html
	   (cond ((null doc)
		  (format t "~A" (escape-string (format nil "\\fundesc{~A}{~A}~%" funcname args-str))))
		 (*has-key*
		  (format t "~A" (escape-string (format nil "\\longdescription{~A}{~A}{~A}~%" funcname args-str doc))))
		 (t
		  (format t "~A" (escape-string (format nil "\\funcdesc{~A}{~A}{~A}~%" funcname args-str doc))))
		 ))
	  (:md
	    (cond ((null doc)
		   (format t "~A ~A~%" funcname args-str))
		  (t
		   (format t "### ~A ###~%~A~%~%" funcname args-str)
		   (format t "- ~A~%" doc)))
            (format t "~%" )))
    (if (null doc) 
        (case *output-format*
              (:html
               (format t "\\vspace*{-5mm}~%}~%"))
              (:md
               )))
    ))

(defun make-document (file &optional output-filename pkg)
  (defvar *classdoc* nil)
  (defvar *funcdoc-public* nil)
  (defvar *funcdoc-private* nil)

  (format *error-output* ";; Writing ~A document to ~A ..." file output-filename)(finish-output *error-output*)
  (cond ((equal (pathname-type output-filename) "md")
         (defvar *output-format* :md))
        (t
         (defvar *output-format* :html)))

  (unless (fboundp 'defclass-org)
    (setf (symbol-function 'defclass-org) (symbol-function 'defclass)))
  (unless (fboundp 'defmethod-org)
    (setf (symbol-function 'defmethod-org) (symbol-function 'defmethod)))
  (unless (fboundp 'defun-org)
    (setf (symbol-function 'defun-org) (symbol-function 'defun)))
  (defmacro require (&rest args) (format *error-output* ";; skip require ~A ..." args))
  (defmacro defclass (cls &rest args &key element-type super slots documentation (doc documentation) &allow-other-keys)
    `(progn
       (defclass-org ,cls :super ,super :slots ,slots ,@args :doc ,doc)
       (push '(make-class-document ,cls ,super '(,@slots)) *classdoc*)))
  (defmacro defmethod (cls &rest methods)
    `(progn
       (defmethod-org ,cls ,@methods)
       (unless (member ,cls *classdoc* :test #'(lambda (a b) (and (equal (car b) 'make-class-document) (equal (send a :name) (cadr b))))) ;; if defclass is already loaded
         (push '(write-classdesc ,cls)  *classdoc*))
       (push '(make-method-document ,cls '(,@methods)) *classdoc*)))
  (defmacro defun (symbol args &rest body)
    `(progn
       (defun-org ,symbol ,args ,@body)
       (if (stringp (car ',body))
           (push '(make-function-document ',symbol ',args) *funcdoc-public*)
         (push '(make-function-document ',symbol ',args) *funcdoc-private*))
       ))
  (if (and pkg (find-package pkg))
      (do-symbols (v (find-package pkg))
         (if (and (documentation v) (derivedp (send v :func) compiled-code))
             (push `(make-function-document ',v nil) *funcdoc-public*))))

  (load file)
  (if output-filename
      (setq *standard-output* (open output-filename :direction :output)))
  (case *output-format*
        (:html
         (format t "\\begin{refdesc}~%"))
        (:md
         ))
  (dolist (e (reverse *classdoc*)) (eval e))
  (dolist (e (reverse *funcdoc-public*)) (eval e))
  (dolist (e (reverse *funcdoc-private*)) (eval e))
  (case *output-format*
        (:html
         (format t "\\end{refdesc}~%"))
        (:md
         ))
  (setq *standard-output* t)
  (format *error-output* "Done~%")
  )
