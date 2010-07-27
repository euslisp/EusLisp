;
;   help for Euslisp command ver 0.1
;
;   02-Oct-1994    Programed by H.Nakagaki
;
(eval-when (compile eval)
  (unless (find-package "HELP")
	  (make-package "HELP" :nicknames '("HLP"))))

(in-package "HELP")

(export '(help help-method))

(defconstant *type-CLASS*  0)
(defconstant *type-METHOD* 1)
(defconstant *type-FUNC*   2)
(defconstant *type-MACRO*  3)
(defconstant *type-CONST*  4)
(defconstant *type-VAR*    5)
(defconstant *type-SPEC*   6)

(defvar *help-hash*)
(defvar *method-hash-list*)
(defvar *help-file* "euslisp.hlp")
;(defvar *eus-tex-dir* (list "/usr/local/eus/doc/latex/"))
;(defvar *eus-tex-dir* (list "/net/etlfs/usr/local/eus/doc/latex/"))
(defparameter *eus-tex-dir* (format nil "~a/doc/latex/" *eusdir*))
(defvar *method-list*)

(load "helpsub")

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

(defun help (&optional (cmd nil)(class nil))
  (let (param-list item citem)
    (setf cmd (format nil "~a" cmd))
    (if (or (string-equal cmd "nil") (string-equal cmd "help"))
	(usage)
        (if (eq class nil)
	    (if (eq (aref cmd 0) #\:)
		(method-list cmd)
	        (if (eq (setf item (gethash cmd *help-hash*)) nil)
		    (progn (format t "~a command is not found!~% You maybe mistake as follows.~%" cmd)
			   (apropos cmd))
		    (progn (format t "NAME~%     ~a~%TYPE~%     " cmd)
			   (setf param-list (send item :read-help))
			   (case (help-item-type item)
				 (0 ;*type-CLASS*
				  (format t "class~%")
				  (print-class item param-list))
				 (2 ;*type-FUNC*
				  (format t "function~%")
				  (print-item cmd item param-list))
				 (3 ;*type-MACRO*
				  (format t "macro~%")
				  (print-item cmd item param-list))
				 (4 ;*type-CONST*
				  (format t "constant~%")
				  (print-item2 cmd item param-list))
				 (5 ;*type-VAR*
				  (format t "variable~%")
				  (print-item2 cmd item param-list))
				 (6 ;*type-SPEC*
				  (format t "special~%")
				  (print-item cmd item param-list))))))
		     
	    (if (eq (setf citem (gethash (format nil "~a" class) *help-hash*)) nil)
		(format t "~a class is not found!" class)
	        (if (eq (setf item (gethash cmd (help-item-mhash citem))) nil)
		    (format t  "~a method is not found in this class, but super-class may have.!!~%" cmd)
		    (progn (format t "NAME~%     ~a~%TYPE~%     " cmd)
			   (format t "method~%CLASS~%     ~a ~%" class)
			   (setf param-list (send item :read-help))
			   (print-item cmd item param-list))))))))

(defun print-item(cmd item param-list)
  (format t "SYNOPSIS~%     ~a ~a ~%" cmd (first param-list))
  (format t "DESCRIPTION~%     ~a ~%" (second param-list)))

(defun print-item2(cmd item param-list)
  (format t "DESCRIPTION~%     ~a ~%" (first param-list)))

(defun print-class( item param-list)
  (format t "SUPER-CLASS~%     ~a ~%" (first param-list))
  (format t "SLOTS~%     ~a ~%" (second param-list))
  (format t "DESCRIPTION~%     ~a ~%" (third param-list)))

(defun help-method(class)
  (let (param-list citem method-list name n max)
    (if (eq (setf citem (gethash (format nil "~a" class) *help-hash*)) nil)
	(format t  "~a class is not found!!~%" class)
        (if (eq (help-item-type citem) *type-CLASS*)
	    (progn (format t "CLASS NAME  : ~a ~%METHOD-LIST : " class)
		   (setf method-list (hash-table-key (help-item-mhash citem)))
		   (dotimes(i (length method-list))
			   (setf name (aref method-list i))
			   (if (stringp name)
			       (format t "~a~%              " name))))
	    (format t "~a is not class!~%" class)))))

(defun usage()
  (format t "Usage : help &optional cmd class~%~%")
  (format t "  cmd is a string that you wan to search. if you want to search method, you must specify class. but if you do not specify class, prints list of class that includes this method.~%"))

(defun method-list(cmd)
  (let (item)
    (format t "This method is defined in classes as follows.~%" )
    (dotimes (i (length *method-list*))
	     (if (not (eq (setq item (gethash cmd (nth i *method-list*))) nil))
		 (format t "~a ~a~%" (help-item-clas item) cmd))))))

(defun load-help(&optional (helpfile *help-file*))
  (let (fp name type fname seek args class)
    (dotimes(i (length lisp::*load-path*))
	    (setq fname (concatenate string (elt lisp::*load-path* i) helpfile))
	    (if (probe-file fname) (return)))
    (setq fp (open fname :direction :input))
    (setq *eus-tex-dir* (read fp))
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

(setq *help-hash* (make-hash-table :test #'string-equal :size 1000 :rehash-size 1.2))
(load-help)

(in-package "USER")
(use-package "HELP")

