;
;   make helpfile for eushelp.l
;
;   02-Oct-1994   Programmed by H.Nakagaki
;   May-1995	for Solaris

(defconstant *type-CLASS*  0)
(defconstant *type-METHOD* 1)
(defconstant *type-FUNC*   2)
(defconstant *type-MACRO*  3)
(defconstant *type-CONST*  4)
(defconstant *type-VAR*    5)
(defconstant *type-SPEC*   6)

(defparameter *help-file* "euslisp.hlp")
(defparameter *eus-tex-dir*  (format nil "~adoc/latex/" *eusdir*))
(defparameter *eus-jtex-dir* (format nil "~adoc/jlatex/" *eusdir*))

(defvar *eus-tex-list* (list "intro"
			      "generals"
			      "controls"
			      "objects"
			      "arith"
			      "symbols" 
			      "sequences"
			      "io"
			      "evaluation"
			      "sysfunc"
			      "mthread"
			      "matrix"
			      "geometry"
			      "contact"
			      "voronoi"
			      "graphics"
			      "xwindow"
			      "xtoolkit"
			      "image"
			      "manipulator"
			      "mars-pre"))
(defvar *eus-jtex-list* (list "jintro"
			      "jgenerals"
			      "jcontrols"
			      "jobjects"
			      "jarith"
			      "jsymbols"
			      "jsequences"
			      "jio" 
			      "jevaluation"
			      "jsysfunc"
			      "jmthread"
			      "jvxw"
			      "jmatrix"
			      "jgeometry"
			      "jcontact"
			      "jvoronoi"
			      "jgraphics"
			      "jxwindow"
			      "jxtoolkit"
			      "jimage"
			      "jmanipulator"
			      "jmars-pre"))

(defun addition-to-help(fp2 tex-dir fname)
  (let ((fp (open (make-pathname
			:directory (pathname-directory (pathname tex-dir))
                        :name fname :type "tex") :direction :input))
	buf c name class seek type args)
    (format t "~s file is included in help-file.~%" fname)
    (loop (setf c (peek-char fp nil))
	  (if (eq c nil) (return))
	  (setf seek (+ (- (unix:lseek fp 0 1) (file-stream-tail fp)) (file-stream-count fp)))
	  (setf buf (read-line fp))
	  (setf type -1)
	  (if (eq c #\\)
	      (progn (cond ((string= buf "\\funcdesc" :end1 9)
	                    (setq type *type-FUNC* args 3))
			   ((string= buf "\\fundesc" :end1 8)
			    (setq type *type-FUNC* args 2))
			   ((string= buf "\\macrodesc" :end1 10)
	                    (setq type *type-MACRO* args 3))
			   ((string= buf "\\macdesc" :end1 8)
	                    (setq type *type-MACRO* args 2))
			   ((string= buf "\\specialdesc" :end1 12)
	                    (setq type *type-SPEC* args 3))
			   ((string= buf "\\spedesc" :end1 8)
	                    (setq type *type-SPEC* args 2))
			   ((string= buf "\\methoddesc" :end1 11)
	                    (setq type *type-METHOD* args 3))
			   ((string= buf "\\metdesc" :end1 8)
	                    (setq type *type-METHOD* args 2))
			   ((string= buf "\\vardesc" :end1 8)
	                    (setq type *type-VAR* args 2))
			   ((string= buf "\\constdesc" :end1 10)
	                    (setq type *type-CONST* args 2))
			   ((string= buf "\\longdescription" :end1 16)
			    (if (eq (elt buf (1+ (position #\{ buf))) #\:)
			    	(setq type *type-METHOD*)
			        (setq type *type-FUNC*))
			    (setq args 3))
			   ((string= buf "\\classdesc" :end1 10)
	                    (setq type *type-CLASS* args 4))
			   )
		     (if (not (eq type -1))
			 (progn (setf seek (+ seek (position #\} buf) 1))
				(setf name (subseq buf (1+ (position #\{ buf)) (position #\} buf)))
				(if (eq type *type-CLASS*)
				    (setf class name))
				(format fp2 "~s ~d ~s ~d ~d ~%" name type fname seek args)))
		     )
	    ))
    (close fp)
    ))

(defun make-help-sub(tex-list &optional (helpfile *help-file*)
					(tex-dir *eus-tex-dir*))
  (let* ((file (make-pathname 
			:directory (pathname-directory (pathname tex-dir))
			:name helpfile)))
    (format t "help directory is being written to ~a~%" file)
    (with-open-file (fp file :direction :output)
	(format fp "; This file is help command list for euslisp~%")
	(format fp "~s ; Directory of TeX manual~%;~%" tex-dir )
	(dotimes(i (length tex-list))
	(addition-to-help fp tex-dir (nth i tex-list))))) )

(defun make-help(&optional (helpfile *help-file*))
  (make-help-sub *eus-tex-list* helpfile *eus-tex-dir*))

(defun make-jhelp(&optional (helpfile *help-file*))
  (make-help-sub *eus-jtex-list* helpfile *eus-jtex-dir*))

(format t "This program makes help file for eushelp.~%" )
(format t "That help-file's default name is ~s.~%" *help-file*)
(format t "So, if you run '(make-help)', you get help-file.~%" )
(format t "But, if you want to help-file that has your own name,~%" )
(format t "you must run '(make-help new-file-name).~%") 
(format t "This program assume that euslisp's document locate at ~%" )
(format t "'/usr/local/eus/doc/latex/'.~%")
(format t "Therefore, if your euslisp's document locate different ~%")
(format t "directiory, you set variable *eus-tex-dir* to your euslisp's~%")
(format t "document directory before you run '(make-help)'.~%~%")
(format t "Japanese help file is made by running '(make-jhelp)'.~%~%")
