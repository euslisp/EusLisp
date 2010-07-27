;;;; rms.l
;;;; Reason Maintenance System
;;;; from "Artificial Intelligence Programming" by Charniak.
;;;; translated to EusLisp by MATSUI.T May1990.
;;;;

(defclass ddclause :super propertied-object
		   :slots (id links))
(defclass ddnode   :super propertied-object
		   :slots (id label clauses))

(defvar *rms-debug* t)

;;
;; DDNODE
;;

(defmethod ddnode
 (:id () id)
 (:clauses () clauses)
 (:show-change (newlabel)
    (if *rms-debug*
	(format t "~s ~s -> ~s~%" id label newlabel)))
 (:label (&optional (newlabel :not-given))
    (when (and (not (eq label newlabel))
	     (not (eq newlabel :not-given) ))
	 (send self :show-change newlabel) 
	 (setq label newlabel))
    label)
 (:IN? () (member label '(T NIL)))
 (:OUT? () (eq label :out))
 (:attach (ddc)
    (pushnew ddc clauses))
 (:detach (ddc)
    (setq clauses (delete ddc clauses)))
 (:justifications (&aux r)
    (dolist (ddc clauses)
	(when (eq (send ddc :active-node) self)
	   (push ddc r)))
    r)
 (:justificands (&aux r ddn2)
    (dolist (ddc clauses)
	(setq ddn2 (send ddc :active-node))
	(unless (eq self ddn2) (push ddn2 r)))
    r)
 (:delabel (&aux r)
    (cond ((eq label :out) nil)
	  (t 
	   (let ((going-out (send self :justificands)))
	      (send self :label :out)
	      (dolist (ddn going-out)
		 (setq r (nconc r (send ddn :delabel))) )
	      (nconc r (send self :justifications))))))
 (:init (i)
    (setq id i
	  label :out)
    self)
 )

;;
;; DDCLAUSE
;;

(defun misaligned-p (label node)
  (eq (not label) (send node :label)))

(defmethod ddclause 
 (:premise? () (and links (null (rest links))))
 (:contradict? ()
    (dolist (l links)
	(unless (misaligned-p (car l) (cdr l)) 
	    (return-from :contradict? nil)) )
    t)
 (:attach ()
    (dolist (ddl links)
       (send (cdr ddl) :attach self))
    )
 (:detach ()
    (dolist (ddl links)
       (send (cdr ddl) :detach self)))
 (:assert ()
   (send self :show-change
	(format nil "Asserting ~a for " id))
   (send self :attach)
   (send self :propagate)
   self)
 (:retract ()
   (send self :show-change "Retracting ")
   (send self :detach)
   (send self :propagate-out-labels)
   )
 (:non-misaligned-links ()
    (let (r)
       (dolist (l links)
          (unless (misaligned-p (car l) (cdr l))  (push l r)))
       r))
 (:misaligned-links (if-all if-all-but-one)
    (let ((non-misaligned-links (send self :non-misaligned-links)) )
	(cond ((null non-misaligned-links)	;all misaligned
		(funcall if-all self))
	      ((null (cdr non-misaligned-links))
		(funcall if-all-but-one self (car non-misaligned-links)) )
	      (t nil))))	;more than one
 (:active-node ()
   (send self :misaligned-links  #'return-nil
	#'(lambda (ddc ddl) (cdr ddl)) ) )
 (:propagate ()
    (send self :misaligned-links
	#'contradict
	#'align-ddlink))
 (:propagate-out-labels ()
    (send self :misaligned-links
	#'uncontradict
	#'(lambda (ddc1 ddl)
	     (dolist (ddc2 (send (cdr ddl) :delabel) )
		(send ddc2 :propagate)
		(prune-contradictions)))))
 (:show-change (message)
    (format t "~A" message)
    (when links
	(show-ddlink (car links))
	(dolist (ddl (cdr links))
	   (princ " or ")
	   (show-ddlink ddl)))
    (terpri t))
 (:init (i l)
   (setq id i links l)
   self)
 )

(defun show-ddlink (ddl)
   (format t "~s~s"
	(case (car ddl)
	   ((t) '+)
	   ((nil) '-)
	   (otherwise '?))
        (send (cdr ddl) :id)))
;;

(defun get-link (label dn) (cons label dn))

;;

(defun contradict (ddc)
  (pushnew ddc *contradictions*))
(defun uncontradict (ddc)
  (if (member ddc *contradictions*)
      (remove ddc *contradictions*)) )
(defun prune-contradictions ()
  (setq *contradictions*
	(delete-if-not #'contradicted-p *contradictions*)))
(defun init-rms (&optional (debug t))
  (setq *contradictions* nil)
  (setq *rms-debug* debug))

(defun premise-p (ddc)  (send ddc :premise?))
(defun return-t (x &optional y) t)
(defun return-nil (x &optional y) nil)

;;
;; Initial Network Creation

(defun make-ddlink (id node)
   (unless (member id '(t nil))
	(error "illegal id for ddlink" id))
   (unless (derivedp node ddnode)
	(error "not a node for ddlink" node))
   (cons id node))
(defun make-ddnode (id)
   (instance ddnode :init id))
(defun make-ddclause (id &rest links)
   (instance ddclause :init id links))


;; assertion
;;

(defun assert-ddlinks (id &rest ddlinks)
   (send (instance ddclause :init id ddlinks) :assert))
(defun assert-premise (id label ddn)
   (assert-ddlinks id (make-ddlink label ddn)))
(defun assert-at-least-one (id ddnodes)
   (let (r)
      (dolist (ddn ddnodes)
	 (push (make-ddlink t ddn) r) )
      (apply #'assert-ddlinks id r)))
(defun assert-at-most-one (id ddnodes)
   (dolist (ddn1 ddnodes)
      (dolist (ddn2 (cdr (member ddn1 ddnodes)))
	 (assert-ddlinks id (make-ddlink nil ddn1)
			    (make-ddlink nil ddn2))
      )))

;;
;; show contradictions
;;

(defun show-contradictions ()
   (when *contradictions*
	(format t "There are contradictions.~%~s~%"
		*contradictions*)
	(dolist (ddc *contradictions*)
	    (format t "~s caused by ~s~%" ddc 
		    (contradiction-causes ddc)))))


;;

(defun align-ddlink (ddc1 ddl &aux (ddn (cdr ddl)) )
    (cond ((send ddn :in?) nil)
	  (t
	    (send ddn :label (car ddl))
	    (dolist (ddc2 (send ddn :clauses))
		(unless (eq ddc1 ddc2)   (send ddc2 :propagate)) ))))


;; example
(defun test1 () 
   (setq a (make-ddnode 'a))
   (setq b (make-ddnode 'b))
   (setq c1 (make-ddclause 'c1
		(make-ddlink t a)
		(make-ddlink nil b)))
   (setq c2 (make-ddclause 'c2
		(make-ddlink nil a)
		(make-ddlink t b)))
   (send c1 :assert)
   (send c2 :assert))

