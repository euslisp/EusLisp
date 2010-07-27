;;;; vrmlserv.l
;;;  (c) 1996, Toshihiro Matsui, Electrotechnical Laboratory
;;;
;;;; Internet Server for communication with Java/VRML
;;;

(require :vrmlParser "vrmlParser.l")
(require :geotools "geotools.l")

(defun print-vrml-symbol (sym &optional (strm t))
   (format strm "~a " 
	(cdr (assoc sym
		'((transform . "Transform")
		  (:rotation . "rotation")
		  (:translation . "translation")
		  (:children . "children")
		))))  )

(defun print-vrml (form &optional (strm t))
   (let (item field arg)
      (print-vrml-symbol (pop form) strm)
      (format strm "{~%")
      (while form
         (setq item (pop form))
	 (format strm "~t")
         (print-vrml-symbol (setq field (pop item)) strm)
	 (case field
	  (:rotation 
		(setq arg (pop item))
		(format strm "~f ~f ~f ~f ~%"
		      (aref arg 0) (aref arg 1) (aref arg 2) (pop item)) )
	  (:translation 
		(setq arg (pop item))
		(format strm "~f ~f ~f ~%"
		      (aref arg 0) (aref arg 1) (aref arg 2)) )
	  (:children 
		(setq arg (pop item))
		(format strm " [")
		(dolist (a arg) (format strm "~s " a))
		(format strm "]~%"))
	  (t (error "unknown vrml field ~s" field)))
         )
     (format strm "~t}~%~c" 0)
     (finish-output strm)
) )
	

(defun coords2vrml (model)
   (let* ((wc (send model :worldcoords))
	  (ang-axis (send wc :rotation-angle))
	  (axis (second ang-axis))
	  (ang (first ang-axis) )
	  (trans (send wc :pos)))
      (list 'transform
	  ;; (list :children (list (send model :name)))
	  (list :translation trans)
	  (list :rotation
		 (if (and axis (not (eql (aref axis 0) *nan*)))
		     axis 
		     #f(1 0 0))
		 (if axis ang 0)))))


(provide :vrmlserv)


;;;;;;;;;;;;;;;;;;;;;;;;;;
;; socket server

#|
(defun echo-vrml (strm)
   (let ((item) (eof (cons nil nil)))
      (setq item (read-vrml strm eof))
      (cond ((eql item eof)
		(warning-message 5 "; vrml connection ~s is being closed.~%"
			strm)
		(send *top-selector* :remove-port strm)
		(close strm) )
	    (t
		(print-vrml item t)
		(print-vrml item strm)
		))))
|#

#|
(defun accept-vrml-connection (sp)
   (let ((s  (make-server-socket-stream sp)))
      (send s :name (format nil "VRML_~d" (send s :infd)) )
      ;; (send *top-selector* :add-port s 'process-vrml s)
      (send *top-selector* :add-port s 'process-vrml s)
      (warning-message 4
	 "; vrml connection request on ~s; ~s is created~%" sp s)
	))
|#

(defun init-vrml-server (port)
   (let* ((sa (make-socket-address :port port :domain af_inet))
	  (sp (make-socket-port sa)))
      (cond ((derivedp sp socket-port)
	      (send *top-selector* :add-port sp 'accept-vrml-connection sp))
	    (t
	      (warning-message 5 "init-vrml-server failed, because of ~S~%"
		 (unix:syserrlist (- sp))))
	  ))
   )

;****************************************************************


(defvar *mouse-scale* 0.05)

(defun process-vrml (strm)
   (let* ((eof (cons nil nil))
	  (item (vrml:read-vrml-1 strm eof)))
      (print item)
      (cond ((eql item eof)
		(warning-message 5 "; vrml connection ~s is being closed; exit.~%"
			strm)
		(send *top-selector* :remove-port strm)
		(close strm)
		(exit) )
	    ((eql item :test)
		(print item) )
	    ((eql (class item) vrml::LoadWRL)
	     (let (wrl-objects)
	       (format t "loading WRL ~s" (send item :get-field 'vrml::url))
	       (vrml::load-wrl-from-url (send item :get-field 'vrml::url))
	       ;; named vrml nodes are listed in vrml::*nodenames*
	       (dolist (b vrml::*nodeNames*)
		  (if (derivedp (cadr b) cascaded-coords)
		      (progn
			(push (cadr b) wrl-objects)
			(send tss :add-new-model (cadr b))) ))
		)
	     )
	    ((eql (class item) vrml::Transform)
	     (print "Transform"))
	    ((eql (class item) vrml::PointerMotion)
	     (print 'pointermotion)
	     (let ((new-coords   (process-transform item)))
		(print-vrml new-coords strm) ) )
	    (t (print (list (class item) vrml::loadwrl)))
	)))



(defun process-transform (item)
   (setq *vrml-message* item)
   (let* ((children (send item :get-field 'vrml::children))
	       (translation (send item :get-field 'vrml::translation))
	       (rotation    (send item :get-field 'vrml::rotation))
	       rot-mode 
	       model
	       trx try trz
	       rot-x rot-y rot-z
	       new-coords)
	(setq model (send tss :find-model (caar children)))
	(unless model (warn "model ~s not found." children))
	(unless (equal (list model) (send tss :selected-models))
		(send tss :new-selection (list model)))
	(setq trx (round (aref translation 0))
	      try (round (aref translation 1))
	      trz (round (aref translation 2)) )
	(setq rot-mode (second rotation)
	      rotation (first rotation))
	(print (list :pointermotion rot-mode (list trx  try)))
	(send tss :move-xy trx try)
	(print (send model :worldpos))
		;;
		;(setf (car children-root) (cadr children-root)
		;      (cdr children-root) (cddr children-root))
                (print   (setq new-coords (coords2vrml model)))
 	)
  )


(defun accept-vrml-connection (sp)
   (let ((pid (unix:fork)))
      (when (= pid 0)
	   ;; child process
	   (warning-message 5 ";;geotools forked, pid=~d~%" (unix:getpid))
	   (let ((s  (make-server-socket-stream sp)))
	      ;; (x:closedisplay x:*display*)
	      (send *top-selector* :remove-port (x::display-fd))
	      (x:init-xwindow)
	      (tss (format nil "eusx constraint server ~d" (unix::getpid)))
	      (setq *check-motion-constraint* t)
	;      (load "fusuma.l")
	;      (send tss :add-new-model railbottom)
	;      (send tss :add-new-model railtop)
	;      (send tss :add-new-model fusumal)
	;      (send tss :add-new-model fusumar)
	      ;;
	      (send s :name (format nil "VRML_~d" (send s :infd)) )
	      (send *top-selector* :add-port s 'process-vrml s)
	      (warning-message 4
		 ";; vrml connection request on ~s~%;; ~s is created~%" sp s)
              )
	)) )

(defun fusuma-server ()
   (init-vrml-server 5001))

