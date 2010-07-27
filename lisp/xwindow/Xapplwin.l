;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  Xapplwin.l
;;;;    application window for euslisp
;;;
;;;	(c)1995, Toshihiro Matsui, Electrotechnical Laboratory
;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(require :Xdecl "Xdecl.l")

;; FilePanel

(export '(FileDialog FilePanel))

(defclass FileDialog :super panel
	:slots (current-dir
		cd-button 
                cdir-text fname-text
                file-win file-win-offset
		ok-button cancel-button view-button goup-button
		okNotify cancelNotify)
	)

(defmethod FileDialog
 (:create-buttons ()
    (setq ok-button
	  (send self :create-item button-item "ok" self :ok))
    (setq cancel-button
	  (send self :create-item button-item "cancel" self :cancel))
    (setq cd-button
	  (send self :create-item button-item "cd" self :open))
    (setq goup-button
	  (send self :create-item button-item "go-up" self :go-up))
    (setq view-button
	  (send self :create-item button-item "view" self :view))
    (setq fname-text
	  (send self :create-item text-item "file:" self :open
		:columns 23 :font font-courb12))
    (setq cdir-text
	  (send self :create-item text-item "cwd:" self :open
		:columns 46 :font font-courb12))
    )
 (:create-fileview (directory)
    (setq file-win
	  (instance ScrollTextWindow :create
		:parent self
		:width (- width 15) :height (- height next-y 40)
		:font (send self :font)
		:scroll-bar t
		:horizontal-scroll-bar t
		:map nil
		:notify-object self
		:notify-method :file-selected))
    (setq current-dir (truename directory))
    (send file-win :display-strings (ls-l directory))
    (setq file-win-offset next-y)
    (send self :locate-item file-win)
    (send cdir-text :value (namestring current-dir))
    )
 (:create (&rest args
	   &key (font font-courb12)
		(directory (concatenate string (pwd) "/"))
		(ok-notify) (cancel-notify ok-notify)
	   &allow-other-keys)
    (send-super* :create :width 380 :height 330 :font font
		 :event-mask '(:configure)
		 args)
    (send self :create-buttons)
    (send self :create-fileview directory)
    (setq okNotify ok-notify
	  cancelNotify cancel-Notify)
    self)
)


(defmethod FileDialog
 (:cwd () (send cdir-text :value))
 (:file-selected (line)
    (let ((line (send file-win :selection)) delim fname)
	(setq delim (position #\space line))
	(when delim
	    (setq fname (subseq line 0 delim))
	    (send fname-text :value fname)
            fname)))
 (:selected-fname ()
    (let ((fname (send fname-text :value)))
       (if (> (length fname) 0)
	   (truename (merge-pathnames
		 (send fname-text :value)
		 (send self :cwd)))
	   (truename (send self :cwd)))))
 (:view (event)
    (if (probe-file (send self :selected-fname))
	(instance TextViewPanel :create
			:file (send self :selected-fname)
			:width 500 :height 500	)))
 (:ok (event)
    (send self :destroy)
    (if okNotify
	(send* (first okNotify) (second okNotify)
	       (send self :selected-fname) (cddr okNotify))))
 (:cancel (event)
    (send self :destroy)
    (if cancelNotify
	(send (first cancelNotify) (second cancelNotify)
	      nil (cddr cancelNotify))) )
 (:open (event)
    (let ((sel (send self :selected-fname)))
	(when (lisp::directory-p (setq sel (namestring sel)))
	   (setq current-dir (concatenate string sel "/"))
	   (send fname-text :value "")
	   (send file-win :clear)
	   (send file-win :display-strings (ls-l sel))
	   (send cdir-text :value (namestring current-dir)))
    ))
 (:go-up (event)
    (let* ((cdir (truename (send self :cwd)))
	   (pdir (make-pathname :directory (butlast (pathname-directory cdir)))))
	(setq pdir  (namestring pdir) )
	(setq current-dir pdir)
	(send cdir-text :value (namestring current-dir))
	(send file-win :clear)
	(send file-win :display-strings (ls-l pdir))
	(send fname-text :value ""))
    )
)

(defmethod FileDialog
 (:resize (w h)
    (setq width w height h)
    (send file-win :resize (- w 15) (- h file-win-offset 40)))
 (:configureNotify (event)
   (let ((newwidth (send self :width)) 
	 (newheight (send self :height)))
	(when (or (/= newwidth width) (/= newheight height))
	  (send self :resize newwidth newheight)))
  )
 )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass FilePanel :super FileDialog
        :slots (print-button remove-button find-button load-button
		compile-button
		eval-text
                confirm-win file-being-removed))

(defmethod FilePanel
 (:create-buttons ()
    (send-super :create-buttons)
    (setq load-button
	  (send self :create-item button-item "load" self :load))
    (setq remove-button
	  (send self :create-item button-item "remove" self :remove))
    (setq print-button
	  (send self :create-item button-item "print" self :print))
    (setq compile-button
	  (send self :create-item button-item "compile" self :compile))
    (setq eval-text
	  (send self :create-item text-item "eval:" self :eval
		:columns 47 :font font-courb12)) )
 (:create (&rest args)
    (send-super* :create args)
    (setq confirm-win (instance confirmPanel :create :map nil))
    self)
)

(defmethod FilePanel
 (:load (event)
    (load (send self :selected-fname)))
 (:eval (event)
    (print (eval (read-from-string (send eval-text :value)))))
 (:print (event)
    (let ((fname (send self :selected-fname)))
       (if fname (unix:system (format nil "a2ps ~a | lpr " (namestring fname))))))
 (:compile (event)
    (let ((fname (send self :selected-fname)))
       (if fname (comp:compile-file (namestring fname)))))
 (:remove (event)
    (setq file-being-removed (namestring (send self :selected-fname)))
    (send confirm-win :ask self :remove-confirm
                "Do you really want to delete"
                (concatenate string file-being-removed " ?"))     )
 (:remove-confirm (answer)
    (when (eq answer :yes)
        (print file-being-removed)
        (unix:unlink file-being-removed)
        (send file-win :clear)
        (send file-win :display-strings (ls-l (send self :cwd))) )
    (setq file-being-removed nil))
))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TextViewPanel
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass TextViewPanel :super panel
        :slots (quit-button find-button print-button file-name
                finish-button find-text 
                view-window))

(defmethod TextViewPanel
 (:create (&rest args &key font file strings (sexp) (width 400)
	   &allow-other-keys)
    (send-super* :create
		:width width :font font
		:event-mask '(:configure) args)
    (setq quit-button
	  (send self :create-item button-item "quit" self :quit
			:font font-courb12))
    (setq print-button
	  (send self :create-item button-item "print" self :print
			:font font-courb12))
    (setq find-button
          (send self :create-item button-item "find" self :find
			:font font-courb12))
    (setq find-text
          (send self :create-item text-item "find: " self :find
			:font font-courb12))
    (setq view-window
	    (send self :locate-item
		(instance ScrollTextWindow :create
		   :width (setq width (- (send self :width) 10))
		   :height (- (setq height (send self :height)) 60)
			;; assume quit, find items are lined up in one line.
		   :scroll-bar t :horizontal-scroll-bar t
		   :map nil :font font
		   :parent self)))
    (cond (file 
		(setq file-name file)
		(send view-window :read-file file))
	  (sexp nil)
	  (strings (send view-window :display-strings strings))
	 )
    self)
 (:quit (event)
    (send self :destroy)
    (send self :flush))
 (:finish (event) (throw :window-main-loop self))
 (:print (event)
    (let ((fn file-name) lines)
      (unless file-name
        (setq lines (send view-window :lines))	;get all lines
	(setq fn (format nil "/tmp/eus.~a.~d" (send self :name) (unix:getpid)))
	(with-open-file (f fn :direction :output)
	   (dotimes (i (length lines)) (format f "~a~%" (elt lines i))))
	)
    (unix:system (format nil "a2ps ~a | lpr " (namestring fn)))) )
 (:find (event)
    (let ((findstr (send find-text :value)) found
          (nlines (send view-window :nlines)))
        (do ((i 0 (1+ i)))
            ((or (>= i nlines) found))
           (if (substringp findstr (send view-window :line i))
               (setq found i)))
        (when found
           (send view-window :display-selection found)
           (send view-window :locate found))))
 (:resize (w h)
    (setq width w height h)
    (send view-window :resize (- w 10) (- h 38)))
 (:configureNotify (event)
   (let ((newwidth (send self :width))
	 (newheight (send self :height)))
	(when (or (/= newwidth width) (/= newheight height))
	  (send self :resize newwidth newheight)))
  )
 )

(defun ls-l (&optional (dir "."))
    (let ((lsproc (piped-fork "ls" "-la" (namestring dir)))
	  (eof (cons nil nil))
	  f flist line spos rline)
       (read-line lsproc nil eof)
       (while (null (eq (setq line (read-line lsproc nil eof)) eof))
          (nreverse line)
          (setq spos (position #\space line))
          (setq f (if spos (nreverse (subseq line 0 spos)) " ") )
          (setq line (if spos (nreverse (subseq line spos)) "??"))
          (push (format nil "~18a ~a" f line) flist))
       (close lsproc)
       (nreverse flist)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;	ConfirmPanel
;;;	  a dialog window just to ask yes/no
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass ConfirmPanel :super panel
        :slots (yes-button no-button answer message
                notify-object notify-method))

(defmethod ConfirmPanel
 (:create (&rest args)
    (send-super* :create :width 400 :height 260 :font font-courb18
                :background "#ff6040" :map nil
		:event-mask nil args)
    (setq yes-button
            (send self :create-item button-item "YES" self :yes
                :font font-courb18))
    (setq no-button
            (send self :create-item button-item "NO" self :no
                :font font-courb18))
    (send yes-button :move 70 200)
    (send no-button :move  270 200)
    self
    )
 (:draw-message ()
    (let ((x 20) (y 50))
        (send self :clear)
        (dolist (str message)
            (send self :image-string x y str)
            (incf y 30))))
 (:ask (rcv meth &rest lines)
    (setq answer nil)
    (setq message lines)
    (send self :draw-message)
    (send self :map)
    (setq notify-object rcv
          notify-method meth)
    self)
 (:yes (event)
     (setq answer :yes)
     (send self :unmap)
     (send notify-object notify-method :yes))
 (:no (event)
     (setq answer :no)
     (send self :unmap)
     (send notify-object notify-method :no))
 (:configureNotify (event)
   (let ((newwidth (event-width event))
         (newheight (event-height event)))
        (when (or (/= newwidth width) (/= newheight height))
           (send self :draw-message))))
 )

;;;;;

(defclass colorPickerPanel :super panel
	:slots (ok-button cancel-button
		ambient-button diffuse-button
		specular-button	emission-button
		slider1 slider2 slider3
		shininess-button transparency-button
		ambient-value diffuse-value specular-value
		emission-value shininess-value transparency-value
		reply-object reply-method
		))

(defmethod colorPickerPanel
 (:create (&rest args)
    (send-super* :create :width 300 :height 300 :font font-courb14 args)
    (setq ok-button (send self :create-item  button-item "OK" self :ok))
    (setq cancel-button
	  (send self :create-item button-item "Cancel" self :cancel))
    (setq ambient-button
	  (send self :create-item button-item "Ambient" self :ambient))
    (setq diffuse-button
	  (send self :create-item button-item "Diffuse" self :diffuse))
    (setq specular-button
	  (send self :create-item button-item "Specular" self :specular))
    (setq emission-button
	  (send self :create-item button-item "Emission" self :emission))
    (setq shininess-button
	  (send self :create-item button-item "Shininess" self :shininess))
    (setq transparency-button
	  (send self :create-item button-item "Transparency" self :transparency))
    (setq slider1
	  (send self :create-item slider-item "value1" self :value1))
    (setq slider2
	  (send self :create-item slider-item "value2" self :value2))
    (setq slider3
	  (send self :create-item slider-item "value3" self :value3))
   (setq ambient-value (float-vector 0.3 0.4 0.5)
	  diffuse-value (float-vector 0.5 0.4 0.3)
	  specular-value (float-vector 0.2 0.2 0.2)
	  emission-value (float-vector 0.1 0.1 0.1)
	  shininess-value 10.0
	  transparency-value 0.0)
   (setq reply-object nil reply-method nil)
   self)
 (:init-value (colmat)	;colormaterial
    (setq ambient-value (send colmat :ambient)
	  diffuse-value (send colmat :diffuse)
	  specular-value (send colmat :specular)
	  emission-value (send colmat :emission)
	  shininess-value (send colmat :shininess)
	  transparency-value (send colmat :transparency) )
    nil)
 (:value1 (item v)   (print v))
 (:value2 (item v)   (print v))
 (:value3 (item v)   (print v))
 (:ambient (event)
    (send slider1 :value (aref ambient-value 0))
    (send slider2 :value (aref ambient-value 1))
    (send slider3 :value (aref ambient-value 2))
 )
 (:diffuse (event)
    (send slider1 :value (aref diffuse-value 0))
    (send slider2 :value (aref diffuse-value 1))
    (send slider3 :value (aref diffuse-value 2))
 )
 (:specular (event)
    (send slider1 :value (aref specular-value 0))
    (send slider2 :value (aref specular-value 1))
    (send slider3 :value (aref specular-value 2))
 )
 (:emission (event)
    (send slider1 :value (aref emission-value 0))
    (send slider2 :value (aref emission-value 1))
    (send slider3 :value (aref emission-value 2))
 )
 (:shininess (event)
    (send slider1 :value  shininess-value))
 (:transparency (event) 
    (send slider1 :value  transparency-value))
)

;    ambientColor 0.3 0.3 0.3
;    diffuseColor 0.8 0.4 0.8
;    specularColor 0.3 0.2 0.1
;    emissiveColor 0.1 0.2 0.3
;    shininess 20.0
;    transparency 0


;;;;****************************************************************
;; object browser
;;;;****************************************************************

(defclass objectBrowser :super panel
	:slots (object-text class-text super-button sub-button
		view-panel msg-win msg-stream
		current-object current-class class-tree
		methods method-names)
   )

(defmethod objectBrowser
 (:create (&rest args &key (width 350) (height 500) &allow-other-keys)
    (send-super* :create :width width :height height args)
    (setq object-text 
          (send self :create-item text-item "obj: " self :set-object
			:font font-courb12)
	  class-text
	  (send self :create-item text-item "class: " self :set-class
			:font font-courb12)
	  sub-button 
          (send self :create-item button-item "sub" self :set-subclass
          	        :font font-courb18)
	  super-button 
          (send self :create-item button-item "super" self :set-superclass
          	        :font font-courb18)
	  view-panel
	  (instance textViewPanel :create :parent self
			:width (send self :width)
			:height (- (send self :height) 120)
			:y 120
			:font font-courb12)
	  msg-win
	  (instance textwindow :create :width width :height 60	:y 60
				:font font-courb12
				:parent self)
          msg-stream
	  (make-textwindow-stream msg-win)
	  )
    self)
  (:update-method-names (&optional (klass current-class))
     (setq method-names (mapcar #'string
		(mapcar #'car (send klass :methods))))
     (setq mmm method-names)
     (send (view-panel . view-window) :display-strings method-names))
  (:set-object (evnt)
     (setq current-object (read-from-string (send object-text :value)))
     (cond ((boundp current-object)
	    (setq current-object (symbol-value current-object))	
	    (send self :set-class 
		(setq current-class (class current-object)))
	    (format msg-stream "~s ~s~%" current-object current-class)	
	    )
	   (t
	    (format msg-stream "object ~s is unbound~%" current-object)))
     )
  (:set-class (evnt)
     (cond ((not (classp evnt))
	    (setq current-class
		  (read-from-string (send class-text :value)))
	     (if (boundp current-class)
	         (setq current-class (symbol-value current-class))
	         (format msg-stream "class ~s is unbound~%" current-class)))
	   ((classp evnt)
	    (setq current-class evnt)
	    (send class-text :value
		(format nil "~a" (send current-class :name))))
	   )
     (send class-text :value (string (send current-class :name)))
     (setq class-tree (cons current-class (send current-class :superclasses)))
     (send self :update-method-names current-class)
 )
  (:set-superclass (item)
    (let ((s (cadr (member current-class class-tree))))
	(when s
	   (setq current-class s)
	   (send class-text :value (string (send current-class :name)))
	   (send self :update-method-names)))
    )
  (:set-subclass (item)
    (let ((s class-tree))
	(while (and (cdr s) (not (eql current-class (cadr s))))
	   (setq s (cdr s)))
	(when (cdr s)
	   (setq current-class (car s))
	   (send class-text :value (string (send current-class :name)))
	   (send self :update-method-names)))
    current-class )
 )


(provide :Xapplwin  "@(#)$Id: Xapplwin.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $") )

