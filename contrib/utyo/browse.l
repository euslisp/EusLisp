;;;
;;;		1989.12.21 Class Browser
;;;					by M.Inaba
;;;		Panel
;;;		Textsw
;;;
;;;	(1)	Make Tag file by eustags program.
;;;		Default tagfile is /usr/local/eus/TAGS which is
;;;			created by 'make eustag' on /usr/local/eus.
;;;	(2)	Type (class-browser)
;;;	(3)	Click a displayed word on the Textsw
;;;	(4)	And push browse button.
;;;		if it is class name, then Class structure described.
;;;		if it is method name, then the definition file is loaded
;;;			on the textsw.
;;;	(5)	If a methods is defined in multiple files,
;;;		then you can browse another defintion by pushing
;;;		the browse button.
;;;
(format t "(class-browser)~%")
;;;
(if (not (find-package 'ifm)) (make-package 'ifm))
(if (not (find-package 'lsf)) (make-package 'lsf))
(if (not (find-package 'mb)) (make-package 'mb))
(if (not (find-package 'mwin)) (make-package 'mwin))
(if (not (find-package 'trans)) (make-package 'trans))
(if (not (find-package 'lin)) (make-package 'lin))
(if (not (find-package 'para)) (make-package 'para))
(if (not (find-package 'dca)) (make-package 'dca))
(defun class-browser (&key (tagfile "/usr/local/eus/TAGS"))
  (setq *cb* (instance class-browser :init nil :tagfile tagfile)))
;;;
(defun read-symbol (str)
  (read-from-string str nil ""))
(defun skip-to-symbol-head (str)
  (let ((i 0))
    (while 
	(or
	 (<= (elt str i) #\ )
	 (memq (elt str i) '(#\,)))
      (setq i (1+ i)))
    (subseq str i)))
(defun get-tag (str)
  (setq str (skip-to-symbol-head (subseq str (1+ (position #\( str)))))
  (if
      (not (equal #\: (elt str 0)))
      (setq str (skip-to-symbol-head (subseq str (1+ (position #\  str))))))
  (let ((i1 (position #\ str)))
    (list
     (read-symbol (subseq str 0 i1))
     (read-symbol (subseq str (1+ i1))))
    ))
(defun make-tag-table (fname)
  (let (line tag tag-file-name
	     (tagtable (make-hash-table :size 3000)))
    (with-open-file
     (f fname :direction :input)
     (while (setq line (read-line f nil nil))
       (cond
	((equal "" line)
	 (setq line (read-line f nil nil))
	 (setq tag-file-name
	       (subseq line 0 (position #\, line))))
	((setq tag (get-tag line))
	 (addhash tagtable
		  (cons tag-file-name (cdr tag))
		  (car tag)))
	))
     tagtable
     )))
(defun addhash (hashtab value key)
  (let ((l (gethash key hashtab)))
    (if (not (member value l))
	(setf (gethash key hashtab) (cons value l))
      l)))
(defun subclass-name-tree (classtable &optional (c object))
  (let ((l (gethash c classtable)))
    (cond
     ((null l) (c . name))
     (t (cons (c . name)
	      (mapcar #'(lambda (x)
			  (subclass-name-tree classtable x))
		      l))))))

(defun make-class-inheritance ()
  (let ((class-hash (make-hash-table :size 255)))
    (dolist (l (system:list-all-classes))
	    (addhash class-hash l (l . super)))
    class-hash))
;;;
(defun class-methods (c)
  (mapcar #'(lambda (x) (car x)) (c . methods)))
;;;
(defclass class-browser :super sunview-frame
  :slots (panel textsw browse-item file-name-item
		apropos-item help-item
		browse-file definition-files
		tagtable)
  )
(defmethod class-browser
  (:selected-symbol
   (&optional (textsw textsw) i)
   (if (null i) (setq i (1- (send textsw :insertion-point))))
   (let ((contents (send textsw :get-contents)))
     (while (>= i 0)
       (if (memq
	    (elt contents i)
	    '(#\  #\( #\	 ))
	   (return-from :selected-symbol
			(read-symbol (subseq contents (1+ i)))))
       (setq i (1- i))))
   nil)
;;;
  (:button-class-tree
   (&optional item event)
   (let ((mes (make-string-output-stream #x2000))
	 (classtree (subclass-name-tree (make-class-inheritance))))
     (pprint classtree mes)
     (send self :insert-textsw (get-output-stream-string mes))))
  (:button-browse
   (&optional item event)
   (send self :browse-symbol))
  (:text-browse
   (&optional value item event)
   (send self :browse-symbol
	 (read-symbol (send browse-item :value))))
  (:button-help
   (&optional item event)
   (setq item (send self :selected-symbol))
   (if (null item)
       (setq item (read-symbol (send help-item :value))))
   (send help-item :value item)
   (send self :text-help item))
  (:text-help
   (&optional value item event)
   (setq item (read-symbol (string value)))
   (let* ((help-file-name
	   (format nil "~AHELP~d"  *eus-help-directory*
		   (sxhash item 50)))
	  (mes (make-string-output-stream #x2000))
	  (notes) (note)) 
     (with-open-file (help help-file-name)
		     (while (null (eq (setq note (read help nil 'EOF)) 'EOF))
		       (if (or (eq (car note) item) (memq (car note) item))
			   (push note notes))))
     (nreverse notes)
     (dolist (note notes)
	     (format mes "~A:~A~%" (cadr note) (caddr note)))
     (send self :insert-textsw (get-output-stream-string mes))))
  (:button-apropos
   (&optional item event)
   (setq item (send self :selected-symbol))
   (if (null item)
       (setq item (read-symbol (send apropos-item :value))))
   (send apropos-item :value item)
   (send self :text-apropos item))
  (:text-apropos
   (&optional value item event)
   (let* ((mes (make-string-output-stream #x2000))
	  (name value))
     (setq list
	   (cons name
		 (mapcar
		  #'(lambda (x)
		      (list x
			    (cond
			     ((fboundp x)
			      (cond ((special-form-p x) "Special form")
				    ((macro-function x) "Macro")
				    (t "Function")))
			     ((boundp x)
			      (format nil "~A ~S"
				      (cond ((constantp x) "Constant=")
					    ((= (send x :vtype) 2) "Special=")
					    (t "Value="))
				      (symbol-value x)))
			     )))
		  (apropos-list name))))
     (pprint list mes)
     (send self :insert-textsw (get-output-stream-string mes))))
  (:browse-symbol
   (&optional (tag (send self :selected-symbol)))
   (if (null tag)
       (setq tag (read-symbol (send browse-item :value))))
   (send browse-item :value tag)
   (send browse-item :value (format nil "~s" tag))
   (cond
    ((and
      (symbolp tag)
      (boundp tag)
      (classp (symbol-value tag)))
     (send self :describe-class tag))
    (tag
     (send self :describe-selection tag))))
  (:describe-class
   (c &optional (text-buffer
		 (make-string-output-stream #x4000)))
   (describe (symbol-value c) text-buffer)
   (send self :insert-textsw (get-output-stream-string text-buffer)))
;;;
  (:describe-selection
   (browse-tag)
   (if (null definition-files)
       (setq definition-files (gethash browse-tag tagtable)))
   (setq browse-file (pop definition-files))
   (send file-name-item :value (format nil "~s" browse-file))
   (send self :insert-textsw "")
   (send textsw :set-file-contents (car browse-file))
   (send textsw :possibly-normalize
	 (send textsw
	       :insertion-point
	       (send textsw :index-for-file-line (cadr browse-file))))
   )
;;;
  (:insert-textsw (mes)
		  (send textsw :delete 0 (send textsw :last-point))
		  (send textsw :insert mes)
		  (send textsw :insertion-point 0)
		  (send textsw :first 0))
;;;
  (:text-hcopy
   (&optional value item event)
   (let ((x (send self :x))
	 (y (send self :y))
	 (wx (send self :width))
	 (wy (send self :height)))
     (unix:system
      (format nil "sdump -s 2 -d -r ~S,~S,~S,~S > ~A"
	      x y (+ x wx) (+ y wy) value))
     ))
  (:init
   (&optional (par nil) &key (tagfile "/usr/local/eus/TAGS"))
   (setq tagtable (make-tag-table tagfile))
   (send-super :init par :title "Window example on eusview"
	       :x 500 :y 0 :width 600)
   #+xview
   (setq panel (instance sunview-panel :init self
			 :width 700 :height 350 :item-size 20
			 :col-max 2
			 :font "lucidasans-bold-12"))
   #+sunview
   (setq panel (send self :create-subwindow sunview-panel
		     :width 700 :item-size 20 :col-max 2
		     :font
		     "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
   (send panel :create-button :button-class-tree :title "Class Tree")
   (send panel :create-text :text-hcopy :title "Hard Copy to a File:"
	 :length 30)
   (send panel :create-button :button-browse :title "Browse" :item-col 0)
   (setq browse-item (send panel :create-text :text-browse :title ":"
			   :length 30))
   (setq file-name-item
	 (instance panel-text-item :init panel :title "File name:" :length 30))
   (send panel :create-button :button-apropos :title "Apropos" :item-col 0)
   (setq apropos-item (send panel :create-text :text-apropos :title ":"
			    :length 30))
   (send panel :create-button :button-help :title "Help" :item-col 0)
   (setq help-item (send panel :create-text :text-help :title ":"
			 :length 30))
   #+xview
   (setq textsw (instance sunview-textsw :init self
			  :below panel :x 0 :height 500 :width 700))
   #+sunview
   (setq textsw (send self :create-subwindow sunview-textsw
		      :below panel :x 0 :height 500 :width 700))
   (send panel :width 700)
   (send self :show t)
   self)
  )
