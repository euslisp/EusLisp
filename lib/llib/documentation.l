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
            (t
             (if (memq (schar str i) '(#\& #\# #\* #\_)) (setq ret (concatenate string ret "\\")))
             (setq ret (concatenate string ret (format nil "~c" (schar str i)))))))
    ret))

(defun make-class-document (cls super slots)
  (labels ((write-classdesc (cls super slots)
             (let (slots-str (doc-str ""))
               (dolist (slot slots)
                 (setq slots-str (concatenate string slots-str (format nil "~A " slot))))
               (case *output-format*
                     (:html
                      (format t "~A" (escape-string (format nil "\\classdesc{~A}{~A}{~A}{}~%" (send cls :name) (send super :name) slots-str))))
                     (:md
                      (format t "### ~A~%- :super **~A**~%- :slots ~A~%~%" (send cls :name) (send super :name) slots-str)))
               ))
           (write-methoddesc (method args doc)
             (let (args-str)
               (dolist (arg args)
                 (setq args-str (concatenate string args-str (format nil "~A " arg))))
               (case *output-format*
                     (:html
                      (format t "~A" (escape-string (format nil "~A{~A}{~A}{~A}~%" (if doc "\\methoddesc" "\\metdesc") method args-str doc))))
                     (:md
                      (if (not (equal doc ""))
                          (format t "##### **~A** ~A~%- ~A~%~%" method args-str doc)
                        (format t "~A ~A~%~%" method args-str))))
             )))
    (cond ((eq (class cls) metaclass)
           (write-classdesc cls super slots)
           (let ((method-with-document) (method-without-document))
             (dolist (method (reverse (send cls :methods)))
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
  ))

(defun make-function-document (funcname args)
  (let (args-str doc)
    (if (stringp (documentation funcname)) (setq doc (documentation funcname)))
    (if (null doc)
        (case *output-format*
              (:html
               (format t "{\\\footnotesize~%"))
              (:md
               )))
    (dolist (arg args)
      (setq args-str (concatenate string args-str (format nil "~A " arg))))
    (case *output-format*
          (:html
           (format t "~A" (escape-string (format nil "~A{~A}{~A}{~A}~%" (if doc "\\funcdesc" "\\fundesc") funcname args-str doc)))
           (:md
            (format t "##### **~A** ~A~%" funcname args-str)
            (if (null (equal doc "")) (format t "- ~A~%" doc))
            (format t "~%" ))))
    (if (null doc) 
        (case *output-format*
              (:html
               (format t "\\vspace*{-5mm}~%}~%"))
              (:md
               )))
    ))

(defun make-document (file &optional output-filename)
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
  (unless (fboundp 'defun-org)
    (setf (symbol-function 'defun-org) (symbol-function 'defun)))
  (defmacro defclass (cls &key super slots)
    `(progn
       (defclass-org ,cls :super ,super :slots ,slots)
       (push '(make-class-document ,cls ,super '(,@slots)) *classdoc*)))
  (defmacro defun (symbol args &rest body)
    `(progn
       (defun-org ,symbol ,args ,@body)
       (if (stringp (car ',body))
           (push '(make-function-document ',symbol ',args) *funcdoc-public*)
         (push '(make-function-document ',symbol ',args) *funcdoc-private*))
       ))

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
