;;;;
;;;;   help for Euslisp command 
;;;;
;;;;   02-Oct-1994	Programmed by H.Nakagaki
;;;;   May-1995		port to Solaris by T.Matsui
;;;;

(eval-when (compile eval)
  (unless (find-package "HELP")
	  (make-package "HELP" :nicknames '("HLP"))))

(in-package "HELP")

;; helpsub.o is needed
;;(load "clib/helpsub")

(export '(help help-method load-help))

(defconstant *type-CLASS*  0)
(defconstant *type-METHOD* 1)
(defconstant *type-FUNC*   2)
(defconstant *type-MACRO*  3)
(defconstant *type-CONST*  4)
(defconstant *type-VAR*    5)
(defconstant *type-SPEC*   6)

(defvar *help-hash* nil)
(defvar *method-hash-list*)
(defparameter *eus-tex-dir* (format nil "~a/doc/~a/" *eusdir*
	(if (or (substringp "JA" (unix:getenv "LANG"))
	        (substringp "JP" (unix:getenv "LANG")))
	    "jlatex" "latex")
	))
(defvar *method-list*)

(defclass help-item
  :slots (type fname seek count clas mhash))

(defmethod help-item
  (:init (typ fna see n &optional (c nil))
     (setf type typ)
     (setf fname fna)
     (setf seek see)
     (setf count n)
     (if (eq typ *type-METHOD*)
	 (setf clas c))
     (if (eq typ *type-CLASS*)
	 (progn (setf mhash (make-hash-table :test #'string-equal :rehash-size 1.4))
		(setq *method-list* (cons mhash *method-list*))))
     )

  (:read-help()
     (let ((fp (open (make-pathname
			:directory (pathname-directory (pathname *eus-tex-dir*))
                        :name fname :type "tex") :direction :input))
	   (param1 "")
	   (param2 "")
	   (param3 ""))

       (setf param1 (read-tex fp seek))
       (if (> count 2) (setf param2 (read-tex fp -1)))
       (if (> count 3) (setf param3 (read-tex fp -1)))
       (close fp)
       (list param1 param2 param3)))

  )

(defun help (&optional (cmd nil)(class nil) (hs t)) ;hs=help stream
  (unless *help-hash*
     (setq *help-hash*
	 (make-hash-table :test #'string-equal :size 1000 :rehash-size 1.6))
     (load-help (format nil "~a/euslisp.hlp" *eus-tex-dir*)))
  (let (param-list item citem)
    (setf cmd (format nil "~a" cmd))
    (if (or (string-equal cmd "nil") (string-equal cmd "help"))
	(help-usage hs)
        (if (eq class nil)
	    (if (eq (aref cmd 0) #\:)
		(help-method-list cmd)
	        (if (eq (setf item (gethash cmd *help-hash*)) nil)
		    (progn (format hs "~a command not found.  Commands alike are:~%" cmd)
			   (pprint (apropos-list cmd) hs))
		    (progn (format hs "NAME~%     ~a~%TYPE~%     " cmd)
			   (setf param-list (send item :read-help))
			   (case (help-item-type item)
				 (0 ;*type-CLASS*
				  (format hs "class~%")
				  (print-class item param-list hs))
				 (2 ;*type-FUNC*
				  (format hs "function~%")
				  (print-item cmd item param-list hs))
				 (3 ;*type-MACRO*
				  (format hs "macro~%")
				  (print-item cmd item param-list hs))
				 (4 ;*type-CONST*
				  (format hs "constant~%")
				  (print-item2 cmd item param-list))
				 (5 ;*type-VAR*
				  (format hs "variable~%")
				  (print-item2 cmd item param-list hs))
				 (6 ;*type-SPEC*
				  (format hs "special~%")
				  (print-item cmd item param-list hs))))))
		     
	    (if (eq (setf citem (gethash (format nil "~a" class) *help-hash*)) nil)
		(format hs "~a class is not found!" class)
	        (if (eq (setf item (gethash cmd (help-item-mhash citem))) nil)
		    (format hs  "~a method is not found in this class, but super-class may have.~%" cmd)
		    (progn (format hs "NAME~%     ~a~%TYPE~%     " cmd)
			   (format hs "method~%CLASS~%     ~a ~%" class)
			   (setf param-list (send item :read-help))
			   (print-item cmd item param-list hs))))))))

(defun print-item(cmd item param-list hs)
  (format hs "SYNOPSIS~%     ~a ~a ~%" cmd (first param-list))
  (format hs "DESCRIPTION~%     ~a ~%" (second param-list)))

(defun print-item2(cmd item param-list hs)
  (format hs "DESCRIPTION~%     ~a ~%" (first param-list)))

(defun print-class( item param-list hs)
  (format hs "SUPER-CLASS~%     ~a ~%" (first param-list))
  (format hs "SLOTS~%     ~a ~%" (second param-list))
  (format hs "DESCRIPTION~%     ~a ~%" (third param-list)))

(defun help-method(class hs)
  (let (param-list citem method-list name n max)
    (if (eq (setf citem (gethash (format nil "~a" class) *help-hash*)) nil)
	(format hs "~a class is not found~%" class)
        (if (eq (help-item-type citem) *type-CLASS*)
	    (progn (format hs "CLASS NAME  : ~a ~%METHOD-LIST : " class)
		   (setf method-list (hash-table-key (help-item-mhash citem)))
		   (dotimes(i (length method-list))
			   (setf name (aref method-list i))
			   (if (stringp name)
			       (format t ";~a~%              " name))))
	    (format hs "~a is not class.~%" class)))))

(defun help-usage(hs)
  (format hs "Usage : help &optional cmd class~%~%")
  (format hs "  cmd is a string that you wan to search. if you want to search method, you must specify class. but if you do not specify class, prints list of class that includes this method.~%"))

(defun help-method-list(cmd hs)
  (let (item)
    (format hs "This method is defined in classes as follows.~%" )
    (dotimes (i (length *method-list*))
	     (if (not (eq (setq item (gethash cmd (nth i *method-list*))) nil))
		 (format hs "~a ~a~%" (help-item-clas item) cmd))))))

(defun load-help(helpfile)
  (let (fp name type fname seek args class)
    (unless *help-hash*
       (setq *help-hash*
	   (make-hash-table :test #'string-equal :size 1000 :rehash-size 1.6)))
;    (dotimes(i (length lisp::*load-path*))
;	    (setq fname (concatenate string (elt lisp::*load-path* i) helpfile))
;	    (if (probe-file fname) (return)))
    (setq fp (open helpfile))
;    (setq *eus-tex-dir* (read fp)) *eus-tex-dir* is set by eusrt.l
    (read fp)                      ; 1 read 
    (loop (setq name  (read fp nil))
          (if (eq name nil) (return))
          (setq type  (read fp))
          (setq fname (read fp))
          (setq seek  (read fp))
          (setq args  (read fp))
          (if (eq type *type-CLASS*) (setq class name))
          (if (eq type *type-METHOD*)
              (sethash name (help-item-mhash (gethash class *help-hash*)) (instance help-item :init type fname seek args class))
	      (sethash name *help-hash* (instance help-item :init type fname seek args)))
	  )))

(in-package "USER")
(use-package "HELP")

(provide :eushelp "@(#)$Id$")
