;;; -*- Mode: LISP; Syntax: Common-lisp; Base: 10.; Package: DFSYS -*-
;;; Yet Another Sort Of General System Facility and friends.
;;;
;;; The entry points are defsystem and operate-on-system.  defsystem is used
;;; to define a new system and the files with their load/compile constraints.
;;; Operate-on-system is used to operate on a system defined that has been
;;; defined by defsystem.  For example:

(in-package 'dfsys)
(provide :dfsys)
(export '(*check-subsystems* ld-system operate-on-system defsystem))


#||

(defsystem my-very-own-system
	   "/usr/myname/lisp/"
  ((classes   (precom)           ()                ())
   (methods   (precom classes)   (classes)         ())
   (precom    ()                 (classes methods) (classes methods))))

This defsystem should be read as follows:

* Define a system named MY-VERY-OWN-SYSTEM, the sources and binaries
  should be in the directory "/usr/me/lisp/".  There are three files
  in the system, there are named classes, methods and precom.  (The
  extension the filenames have depends on the lisp you are running in.)
  
* For the first file, classes, the (precom) in the line means that
  the file precom should be loaded before this file is loaded.  The
  first () means that no other files need to be loaded before this
  file is compiled.  The second () means that changes in other files
  don't force this file to be recompiled.

* For the second file, methods, the (precom classes) means that both
  of the files precom and classes must be loaded before this file
  can be loaded.  The (classes) means that the file classes must be
  loaded before this file can be compiled.  The () means that changes
  in other files don't force this file to be recompiled.

* For the third file, precom, the first () means that no other files
  need to be loaded before this file is loaded.  The first use of
  (classes methods)  means that both classes and methods must be
  loaded before this file can be compiled.  The second use of (classes
  methods) mean that whenever either classes or methods changes precom
  must be recompiled.

Then you can compile your system with:

 (operate-on-system 'my-very-own-system :compile)

and load your system with:

 (operate-on-system 'my-very-own-system :load)

||#

(defvar *check-subsystem* t)   
(defun ld-system (system &optional (check-sub *check-subsystem*)
                           (module-name (symbol-name system)))
  "compile and load this system. Don't do it if flag nil and it is already loaded 
   (but possibly the source was modified)"
  (unless (and (member module-name *modules* :test #'string=)
               (not check-sub))
    (operate-on-system system :compile)
    (operate-on-system system :load)))

;;; 
(defvar *system-directory*)

;;;
;;; *port* is a list of symbols  which represent the
;;; Common Lisp in which we are now running.  Many of the facilities in
;;; defsys use the value of *port* rather than #+ and #- to conditionalize
;;; the way they work.
;;; 
(defvar *port*
        '(#+Genera               Genera
          #+Genera-Release-6     Rel-6
          #+Genera-Release-7-1   Rel-7
          #+Genera-Release-7-2   Rel-7
	  #+Genera-Release-7-3   Rel-7
          #+Genera-Release-7-1   Rel-7-1
          #+Genera-Release-7-2   Rel-7-2
	  #+Genera-Release-7-3   Rel-7-2	;OK for now
          #+Lucid                Lucid
          #+Xerox                Xerox
	  #+Xerox-Lyric          Xerox-Lyric
	  #+Xerox-Medley         Xerox-Medley
          #+TI                   TI
          #+(and dec vax common) Vaxlisp
          #+KCL                  KCL
          #+IBCL                 IBCL
          #+excl                 excl
          #+:CMU                 CMU
          #+HP-HPLabs            HP-HPLabs
          #+:gclisp              gclisp
          #+pyramid              pyramid
          #+:coral               coral))

;;;
;;; When you get a copy of Successor (by tape or by FTP), the sources files will
;;; have extensions of ".lisp" in particular, this file will be defsys.lisp.
;;; The preferred way to install Successor is to rename these files to have the
;;; extension which your lisp likes to use for its files.  Alternately, it
;;; is possible not to rename the files.  If the files are not renamed to
;;; the proper convention, the second line of the following defvar should
;;; be changed to:
;;;     (let ((files-renamed-p nil)
;;;
;;; Note: Something people installing Successor on a machine running Unix
;;;       might find useful.  If you want to change the extensions
;;;       of the source files from ".lisp" to ".lsp", *all* you have
;;;       to do is the following:
;;;
;;;       % foreach i (*.lisp)
;;;       ? mv $i $i:r.lsp
;;;       ? end
;;;       %
;;;
;;;       I am sure that a lot of people already know that, and some
;;;       Unix hackers may say, "jeez who doesn't know that".  Those
;;;       same Unix hackers are invited to fix mv so that I can type
;;;       "mv *.lisp *.lsp".
;;;
(defvar *pathname-extensions*
  (let ((files-renamed-p t)
        (proper-extensions
          (car
           '(#+Genera                         ("lisp"  . "bin")
             #+(and dec common vax (not ultrix)) ("LSP"   . "FAS")
             #+(and dec common vax ultrix)       ("lsp"   . "fas")
             #+KCL                               ("lsp"   . "o")
             #+IBCL                              ("lsp"   . "o")
             #+Xerox                             ("lisp"  . "dfasl")
             #+(and Lucid MC68000)               ("lisp"  . "lbin")
             #+(and Lucid VAX)                   ("lisp"  . "vbin")
             #+(and Lucid Prime)                 ("lisp"  . "pbin")
	     #+(and Lucid SUNRise)               ("lisp"  . "sbin")
	     #+(and Lucid SPARC)                 ("lisp"  . "sbin")
             #+(and Lucid IBM-RT-PC)             ("lisp"  . "bbin")
	     #+excl                              ("cl"    . "fasl")
             #+:CMU                              ("slisp" . "sfasl")
             #+HP                                ("l"     . "b")
;             #+TI ("lisp" . #.(string (si::local-binary-file-type)))
             #+:gclisp                           ("LSP"   . "F2S")
             #+pyramid                           ("clisp" . "o")
             #+:coral                            ("lisp"  . "fasl")
	     #+eus				 ("l" . "o")
             ))))
    (cond ((null proper-extensions) '("l" . "lbin"))
          ((null files-renamed-p) (cons "lisp" (cdr proper-extensions)))
          (t proper-extensions))))

(eval-when (compile load eval)

(defun get-system (name)
  (get name 'system-definition))

(defun set-system (name new-value)
  (setf (get name 'system-definition) new-value))

(defmacro defsystem (name directory files)
  `(set-system ',name (list #'(lambda () ,directory)
			    (make-modules ',files)
			    ',(mapcar #'car files))))

)


;;;
;;; The internal datastructure used when operating on a system.
;;; 
(defstruct module (:constructor make-module (name))
                   (:print-function
                     (lambda (m s d)
                       (declare (ignore d))
                       (format s "#<Module ~A>" (module-name m))))
  name
  load-env
  comp-env
  recomp-reasons)

(defun make-modules (system-description)
  (let ((modules ()))
    (labels ((get-module (name)
               (or (find name modules :key #'module-name)
                   (progn (setq modules (cons (make-module name) modules))
                          (car modules))))
             (parse-spec (spec)
               (if (eq spec 't)
                   (reverse (cdr modules))                   
                   (mapcar #'get-module spec))))
      (dolist (file system-description)
        (let* ((name (car file))
               (port (car (cddddr file)))
               (module nil))
          (when (or (null port)
                    (member port *port*))
            (setq module (get-module name))
            (setf (module-load-env module) (parse-spec (cadr file))
                  (module-comp-env module) (parse-spec (caddr file))
                  (module-recomp-reasons module) (parse-spec
                                                   (cadddr file))))))
      (let ((filenames (mapcar #'car system-description)))
	(sort modules #'(lambda (name1 name2)
			  (member name2 (member name1 filenames)))
	      :key #'module-name)))))


(defun make-transformations (modules filter make-transform)
  (let ((transforms (list nil)))
    (dolist (m modules)
      (when (funcall filter m transforms)
        (funcall make-transform m transforms)))
    (reverse (cdr transforms))))

(defun make-compile-transformation (module transforms)
  (unless (dolist (trans transforms)
            (and (eq (car trans) ':compile)
                 (eq (cadr trans) module)
                 (return trans)))    
    (dolist (c (module-comp-env module))
      (make-load-transformation c transforms))
    #+genera-release-6 (make-load-transformation module transforms)
    (push `(:compile ,module) (cdr transforms)))
  transforms)

(defun make-load-transformation (module transforms)
  (unless (dolist (trans transforms)
            (when (eq (cadr trans) module)
              (cond ((eq (car trans) ':compile) (return nil))
                    ((eq (car trans) ':load)   (return trans)))))
    (dolist (l (module-load-env module))
      (make-load-transformation l transforms))
    (push `(:load ,module) (cdr transforms)))
  transforms)

(defun make-load-without-dependencies-transformation (module transforms)
  (unless (dolist (trans transforms)
            (and (eq (car trans) ':load)
                 (eq (cadr trans) module)
                 (return trans)))
    (push `(:load ,module) (cdr transforms)))
  transforms)

(defun compile-filter (module transforms)
  (or (dolist (r (module-recomp-reasons module))
        (when (dolist (transform transforms)
                (when (and (eq (car transform) ':compile)
                           (eq (cadr transform) r))
                  (return t)))
          (return t)))
      (null (probe-file (make-binary-pathname (module-name module))))
      (> (file-write-date (make-source-pathname (module-name module)))
         (file-write-date (make-binary-pathname (module-name module))))))

(defun operate-on-system (name mode &optional arg print-only)
  (let ((system (get-system name)))
    (unless system (error "Can't find system with name ~S." name))
    (let ((*system-directory* (funcall (car system)))
	  (modules (cadr system))
	  (transformations ()))
      (labels ((load-source (name pathname)
		 (format t "~&Loading source of ~A..." name)
		 (or print-only (load pathname)))
	       (load-binary (name pathname)
		 (format t "~&Loading binary of ~A..." name)
		 (or print-only (load pathname)))
	       
	       (load-module (m)
		 (let* ((name (module-name m))
			(*load-verbose* nil)
			(source (make-source-pathname name))
			(binary (make-binary-pathname name)))
		   (if (dolist (trans transformations)
			 (and (eq (car trans) :compile)
			      (eq (cadr trans) m)
			      (return trans)))
		       (cond ((null (probe-file binary))
			      (load-source name source))
			     ((null (probe-file source))
			      (load-binary name binary))
			     ((not
				(yes-or-no-p
				  "The definition of this system requires ~
                                   that the module ~A be loaded now even~%~
                                   though it will later be compiled.  Should ~
                                   the existing binary version be loaded ~%~
                                   instead of the source?"
				  name))
			      (load-source name source))
			     (t
			      (load-binary name binary)))
		       (load-binary name binary))))
	       
	       (compile-module (m)
		 (format t "~&Compiling ~A..." (module-name m))
		 (unless print-only
		   (let  ((name (module-name m)))
		     (compile-file (make-source-pathname name)
				   :output-file
				   (make-pathname :defaults
						  (make-binary-pathname name)
						  :version :newest)))))
	       
	       (true (&rest ignore) (declare (ignore ignore)) 't))
	
	(setq transformations
	      (ecase mode
		(:compile
		  ;; Compile any files that have changed and any other files
		  ;; that require recompilation when another file has been
		  ;; recompiled.
		  (make-transformations
		    modules
		    #'compile-filter
		    #'make-compile-transformation))
		(:recompile
		  ;; Force recompilation of all files.
		  (make-transformations
		    modules
		    #'true
		    #'make-compile-transformation))
		(:recompile-some
		  ;; Force recompilation of some files.  Also compile the
		  ;; files that require recompilation when another file has
		  ;; been recompiled.
		  (make-transformations
		    modules
		    #'(lambda (m transforms)
			(or (member (module-name m) arg)
			    (compile-filter m transforms)))
		    #'make-compile-transformation))
		(:query-compile
		  ;; Ask the user which files to compile.  Compile those
		  ;; and any other files which must be recompiled when
		  ;; another file has been recompiled.
		  (make-transformations
		    modules
		    #'(lambda (m transforms)
			(or (compile-filter m transforms)
			    (y-or-n-p "Compile ~A?"
				      (module-name m))))
		    #'make-compile-transformation))
		(:confirm-compile
		  ;; Offer the user a chance to prevent a file from being
		  ;; recompiled.
		  (make-transformations
		    modules
		    #'(lambda (m transforms)
			(and (compile-filter m transforms)
			     (y-or-n-p "Go ahead and compile ~A?"
				       (module-name m))))
		    #'make-compile-transformation))
		(:load
		  ;; Load the whole system.
		  (make-transformations
		    modules
		    #'true
		    #'make-load-transformation))
		(:query-load
		  ;; Load only those files the user says to load.
		  (make-transformations
		    modules
		    #'(lambda (m transforms)
			(declare (ignore transforms))
			(y-or-n-p "Load ~A?" (module-name m)))
		    #'make-load-without-dependencies-transformation))))
	
	(#+Genera
	 compiler:compiler-warnings-context-bind
	 #+TI
	 COMPILER:COMPILER-WARNINGS-CONTEXT-BIND
;	 #+:LCL3.0
;	 lucid-common-lisp:with-deferred-warnings
	 #-(or Genera TI :LCL3.0)
	 progn
	 (loop (when (null transformations) (return t))
	       (let ((transform (pop transformations)))
		 (ecase (car transform)
		   (:compile (compile-module (cadr transform)))
		   (:load (load-module (cadr transform)))))))))))


(defun make-source-pathname (name) (make-pathname-internal name :source))
(defun make-binary-pathname (name) (make-pathname-internal name :binary))

(defun make-pathname-internal (name type)
  (let* ((extension (ecase type
                      (:source (car *pathname-extensions*))
                      (:binary (cdr *pathname-extensions*))))
         (directory (pathname
		      (etypecase *system-directory*
			(string *system-directory*)
			(pathname *system-directory*)
			(cons (ecase type
				(:source (car *system-directory*))
				(:binary (cdr *system-directory*)))))))
         (pathname
           (make-pathname
             :name (string-downcase (string name))
             :type extension
             :defaults directory)))

;    #+Genera
;    (setq pathname (zl:send pathname :new-raw-name (pathname-name pathname))
;          pathname (zl:send pathname :new-raw-type (pathname-type pathname)))

    pathname))


