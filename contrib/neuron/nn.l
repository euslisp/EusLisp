;;; -*- Mode: lisp -*-
;;EusLisp
;;Header:
;;Title: Neual Network Library
;;Author: NODA Itsuki
;;Date: 1996/07/02
;;EndHeader:

;;History:
;; 1996/07/02 [I.Noda] Creates this file.
;;EndHistory:

;;======================================================================
;;Section: Package
;;----------------------------------------------------------------------
(in-package 'nn)

;;======================================================================
;;Section: Misc
;;----------------------------------------------------------------------
(defvar *alpha* 0.5)
(defvar *eta* 0.01) 

(defmacro sigmoid (x th)
  `(/ 1.0 
      (+ 1.0
	 (exp (/ (- ,x) ,th)))))


;;======================================================================
;;Section: Macros
;;----------------------------------------------------------------------
(defmacro v=m*v (fltvec0 fltmat fltvec1)
  `(transform ,fltmat ,fltvec1 ,fltvec0))

(defmacro v=v*m (fltvec0 fltvec1 fltmat)
  `(transform ,fltvec1 ,fltmat ,fltvec0))

(defmacro v=v+v (fltvec0 fltvec1 fltvec2)
  `(v+ ,fltvec1 ,fltvec2 ,fltvec0))

(defmacro v=v-v (fltvec0 fltvec1 fltvec2)
  `(v- ,fltvec1 ,fltvec2 ,fltvec0))

(defmacro v*=s (fltvec0 scalar)
  `(scale ,fltvec0 ,scalar ,fltvec0))

;;======================================================================
;;Section: Layer & Link
;;----------------------------------------------------------------------
(defclass layer
  :slots ((name :type string)
	  (size :type :integer)
	  (bias :type float-vector)
	  (input :type float-vector)
	  (output :type float-vector)
	  (delta  :type float-vector)
	  (dbias :type float-vector)
	  (temperature :type :float)
	  (from)
	  (to)))

(defclass link 
  :slots ((from :type layer)
	  (to :type layer)
	  (n :type :integer)
	  (m :type :integer)
	  (weight)
	  (dweight)))

(defun create-layer (name size &key (temperature 1.0))
  (let ((ly (make-instance layer)))
    (setf (layer-name ly) name)
    (setf (layer-size ly) size)
    (setf (layer-bias ly) (make-array size :element-type :float))
    (setf (layer-input ly) (make-array size :element-type :float))
    (setf (layer-output ly) (make-array size :element-type :float))
    (setf (layer-delta   ly) (make-array size :element-type :float))
    (setf (layer-dbias   ly) (make-array size :element-type :float))
    (setf (layer-temperature ly) temperature)
    (setf (layer-from ly) nil)
    (setf (layer-to ly) nil)
    ly))

(defun init-layer (ly &optional (min -1.0) (max 1.0))
  (v=noise (layer-bias ly) min max))

(defun create-link (from to)
  (let ((ln (make-instance link))
	(n (layer-size to))
	(m (layer-size from)))
    (setf (link-from ln) from)
    (setf (link-to ln) to)
    (setf (link-n ln) n)
    (setf (link-m ln) m)
    (setf (link-weight ln) 
	  (make-array (list n m) :element-type :float))
    (setf (link-dweight ln) 
	  (make-array (list n m) :element-type :float))
    (push ln (layer-to from))
    (push ln (layer-from to))
    ln))

(defun init-link (ln &optional (min -1.0) (max 1.0))
  (m=noise (link-weight ln) min max)) 

;;======================================================================
;;Section: Load&Save layer&link
;;----------------------------------------------------------------------
(defmacro save-layer-array (ly array-name strm tab)
  `(progn 
     (spaces ,tab ,strm)
     (format ,strm " (~a . " ',array-name)
     (prin1 (slot ,ly (class ,ly) ',array-name)
	     strm)
     (format ,strm " )~%")))

(defun save-layer (ly &optional (strm t) (tab 0) (detailp nil))
  (spaces tab strm)
  (format strm "(layer ~a" (layer-name ly))
  (format strm " (size . ~a)" (layer-size ly))
  (format strm " (temperature . ~a)" (layer-temperature ly))
  (format strm "~%")
  (save-layer-array ly bias strm tab)
  (if detailp
      (progn 
	(save-layer-array ly input strm tab)
	(save-layer-array ly output strm tab)
	(save-layer-array ly delta strm tab)
	(save-layer-array ly dbias strm tab)
	(spaces tab strm)
	(format strm " (from . ~a)~%" (layer-from ly))
	(spaces tab strm)
	(format strm " (to . ~a)~%" (layer-to ly))))
  (spaces tab strm)
  (format strm ")~%")
  ly)

(defun load-layer (&optional (strm t))
  (construct-layer0 (read strm)))

(defmacro construct-layer-array (dt arrayname size)
  `(or (cdr (assoc ',arrayname ,dt))
       (make-array ,size :element-type :float)))

(defun construct-layer (dt &optional (layer-table t))
  (let ((ly (construct-layer0 dt)))
    (cond ((consp layer-table)
	   (nconc layer-table 
		  (list (cons (layer-name ly) ly))))
	  ((hash-table-p layer-table)
	   (setf (gethash (layer-name ly) layer-table)
		 ly))
	  ((eql t layer-table)
	   (setf (symbol-value (layer-name ly)) ly))
	  (t
	   nil))
    ly))
		 
(defun construct-layer0 (dt)
  (if (eql (car dt) 'layer)
      (let* ((ly (make-instance layer))
	     (size (or (cdr (assoc 'size (cddr dt)))
		       1))
	     (dtc (cddr dt)))
	(setf (layer-name ly) (cadr dt))
	(setf (layer-size ly) size)
	(setf (layer-temperature ly) 
	      (or (cdr (assoc 'temperature dtc))
		  1.0))
	(setf (layer-bias ly) (construct-layer-array dtc bias size))  
	(setf (layer-input ly) (construct-layer-array dtc input size))  
	(setf (layer-output ly) (construct-layer-array dtc output size))  
	(setf (layer-delta   ly) (construct-layer-array dtc delta size))  
	(setf (layer-dbias   ly) (construct-layer-array dtc dbias size))  
	(setf (layer-from ly) nil)
	(setf (layer-to ly) nil)
	ly)
    (error "Illegal Layer Format:~a" dt)))

(defmacro save-link-matrix (ln matrix-name strm tab)
  `(progn 
     (spaces ,tab ,strm)
     (format ,strm " (~a . ~%" ',matrix-name)
     (spaces (+ ,tab 2) ,strm)
     (pprint (slot ,ln (class ,ln) ',matrix-name)
	     strm (+ tab 2))
     (format ,strm " )~%")))

(defun save-link (ln &optional (strm t) (tab 0) (detailp nil))
  (spaces tab strm)
  (format strm "(link (~a ~a) (~a ~a)~%" 
	  (layer-name (link-from ln))
	  (layer-name (link-to ln))
	  (link-n ln)
	  (link-m ln))
  (save-link-matrix ln weight strm tab)
  (if detailp 
      (progn 
	(save-link-matrix ln dweight strm tab)))
  (spaces tab strm)
  (format strm ")~%")
  ln)

(defun load-link (&optional (strm t))
  (construct-link0 (read strm)))

(defmacro construct-link-matrix (dt matrixname rowsize colsize)
  `(or (cdr (assoc ',matrixname ,dt))
       (make-array (list ,rowsize ,colsize) :element-type :float)))

(defun construct-link0 (dt)
  (if (eql (car dt) 'link)
      (let* ((ln (make-instance link))
	     (from-to (second dt))
	     (from-layer (first from-to))
	     (to-layer (second from-to))
	     (size (third dt))
	     (rowsize (first size))
	     (colsize (second size))
	     (dtc (cdddr dt)))
	(setf (link-from ln) from-layer)
	(setf (link-to ln) to-layer)
	(setf (link-n ln) rowsize)
	(setf (link-m ln) colsize)
	(setf (link-weight ln) 
	      (construct-link-matrix dtc weight rowsize colsize))
	(setf (link-dweight ln) 
	      (construct-link-matrix dtc dweight rowsize colsize))
	ln)
    (error "Illegal Link Format: ~a" dt)))

(defun wire-link (ln layer-table)
  (let* ((from (link-from ln))
	 (to (link-to ln))
	 (getfunc 
	  (cond ((consp layer-table)
		 #'(lambda (key layer-table)
		     (or (cdr (assoc key layer-table))
			 key)))
		((hash-table-p layer-table)
		 #'(lambda (key layer-table)
		     (or (gethash key layer-table)
			 key)))
		((eql layer-table t)
		 #'(lambda (key layer-table)
		     (symbol-value key)))
		(t
		 #'(lambda (key layer-table) key)))))
    (setq from 
	  (setf (link-from ln)
		(funcall getfunc from layer-table)))
    (setq to
	  (setf (link-to ln)
		(funcall getfunc to layer-table)))
    (push ln (layer-to from))
    (push ln (layer-from to))
    ln))

(defun construct-link (dt &optional (layer-table t))
  (let ((ln (construct-link0 dt)))
    (wire-link ln layer-table)))

;;======================================================================
;;Section: Propagate-forward
;;----------------------------------------------------------------------
(defun f-propagate-link (ln)
  (let ((from-layer-output (layer-output (link-from ln)))
	(to-layer-input (layer-input (link-to ln))))
    (v+=m*v to-layer-input (link-weight ln) from-layer-output)))
    
(defun f-propagate-sigmoid-layer (ly)
  (v= (layer-input ly) (layer-bias ly))
  (dolist (from-link (layer-from ly))
    (f-propagate-link from-link))
  (v=sigmoid (layer-output ly) (layer-input ly) 
	     (layer-temperature ly)))

(defun f-propagate-liner-layer (ly)
  (v= (layer-input ly) (layer-bias ly))
  (dolist (from-link (layer-from ly))
    (f-propagate-link from-link))
  (scale (layer-temperature ly) (layer-input ly) (layer-output ly)))

;;======================================================================
;;Section: Propagate-backward
;;----------------------------------------------------------------------
(defun b-propagate-link (ln)
  (let ((current-delta (layer-delta (link-from ln)))
	(next-delta (layer-delta (link-to ln)))
	(weight (link-weight ln)))
    (v+=v*m current-delta next-delta weight)))

(defun b-propagate-sigmoid-output-layer (ly target)
  (v- target (layer-output ly) (layer-delta ly))
  (v*=dsigdx_o (layer-delta ly) (layer-output ly) (layer-temperature ly)))

(defun b-propagate-liner-output-layer (ly target)
  (v- target (layer-output ly) (layer-delta ly))
  (scale (layer-temperature ly) (layer-delta ly) (layer-delta ly)))

(defun b-propagate-sigmoid-hidden-layer (ly)
  (let ((delta (layer-delta ly)))
    (v=s delta 0.0)
    (dolist (to-link (layer-to ly))
      (b-propagate-link to-link))
    (v*=dsigdx_o delta (layer-output ly) (layer-temperature ly))))

(defun b-propagate-liner-hidden-layer (ly)
  (let ((delta (layer-delta ly)))
    (v=s delta 0.0)
    (dolist (to-link (layer-to ly))
      (b-propagate-link to-link))
    (scale (layer-temperature ly) delta delta)))

;;======================================================================
;;Section: Learn parameters
;;----------------------------------------------------------------------
(defun learn-layer (ly alpha eta)
  (v=a*v+e*v (layer-dbias ly) alpha eta (layer-delta ly))
  (v+= (layer-bias ly) (layer-dbias ly)))

(defun learn-link (ln alpha eta)
  (m=a*m+e*v**v (link-dweight ln)
		alpha 
		eta
		(layer-delta (link-to ln))
		(layer-output (link-from ln)))
  (m+= (link-weight ln) (link-dweight ln)))

;;======================================================================
;;Section: network
;;----------------------------------------------------------------------
(defclass layered-network
  :slots ((name)
	  (layer-table)
	  (link-table)
	  (parameter-table) 
	  (temperature :type :float)
	  (alpha :type :float)
	  (eta :type :float)
	  ))

(defun get-layer-by-name (name lnet)
  (cdr (assoc name (layered-network-layer-table lnet))))

(defun get-link-by-name (name lnet)
  (cdr (assoc name (layered-network-link-table lnet)
	      :test 'equal)))

;;(layered-network NAME
;;  (parameters (temperature 1.0)
;;	    (alpha 0.9)
;;	    (eta 0.1)
;;	    &rest)
;;  (layers 
;;	  (Layer1 UNum1 &key (temperature NIL))
;;        | (@ layer ...) 
;;	  (Layer2 Unum2 &key (temperature NIL))
;;	  ...)
;;  (links ((From1 To1) &key)
;;	  | (@ link ...)
;;	   ((From2 To2) &key)
;;	 ...))

(defun construct-layered-network-parameters (lnet param-list)
  (dolist (var-val-pair param-list)
    (case (first var-val-pair)
	  (temperature 
	   (setf (layered-network-temperature lnet)
		 (second var-val-pair)))
	  (alpha 
	   (setf (layered-network-alpha lnet)
		 (second var-val-pair)))
	  (eta 
	   (setf (layered-network-eta lnet)
		 (second var-val-pair)))
	  (t 
	   (push (cons (first var-val-pair)
		       (second var-val-pair))
		 (cdr (layered-network-parameter-table lnet)))))))

(defun construct-layered-network-layers (lnet layer-list)
  (dolist (ldt layer-list)
    (case (first ldt)
	  (@ 
	   (construct-layer (rest ldt) 
			    (layered-network-layer-table lnet)))
	  (t
	   (let ((ln (create-layer (first ldt)
				   (second ldt)
				   :temperature
				   (or (cdr (assoc :temperature
						   (cddr ldt)))
				       (layered-network-temperature lnet)))))
	     (nconc (layered-network-layer-table lnet)
		    (list (cons (first ldt) ln))))))))

(defun construct-layered-network-links (lnet link-list)
  (dolist (ldt link-list)
    (case (first ldt)
	  (@
	   (let ((ln (construct-link (rest ldt)
				     (layered-network-layer-table lnet))))
	     (nconc (layered-network-link-table lnet)
		    (list (cons (list
				 (layer-name (link-from ln))
				 (layer-name (link-to ln)))
				ln)))))
	  (t
	   (let* ((from-to (first ldt))
		  (from (get-layer-by-name (first from-to) lnet))
		  (to (get-layer-by-name (second from-to) lnet))
		  (ln (create-link from to)))
	     (nconc (layered-network-link-table lnet)
		    (list (cons (list
				 (layer-name (link-from ln))
				 (layer-name (link-to ln)))
				ln))))))
    ))


(defun construct-layered-network (dt)
  (if (not (eql (first dt) 'layered-network))
      (error "Illegal layered-network form: ~a" dt))  
  (let* ((lnet (make-instance layered-network)))
    (setf (layered-network-name lnet) (second dt))
    (setf (layered-network-layer-table lnet) (list nil))
    (setf (layered-network-link-table lnet) (list nil))
    (setf (layered-network-parameter-table lnet) (list nil))
    (setf (layered-network-temperature lnet) 0.0)
    (setf (layered-network-alpha lnet) 0.0)
    (setf (layered-network-eta lnet) 0.0)
    (dolist (arg (cddr dt))
      (case (first arg)
	    (parameters 
	     (construct-layered-network-parameters lnet (rest arg)))
	    (layers
	     (construct-layered-network-layers lnet (rest arg)))
	    (links
	     (construct-layered-network-links lnet (rest arg)))
	    (t (error "Illeval layered-network form: ~a" dt))))
    lnet))
    

(defmacro layered-network (&rest body)
  `(construct-layered-network '(layered-network . ,body)))

(defun save-layered-network-parameters (lnet &optional 
					     (strm t) (tab 0) (detailp nil))
  (spaces tab strm)
  (format strm "(parameters~%")
  (spaces (+ tab 2) strm)
  (format strm "(temperature ~a)~%" (layered-network-temperature lnet))
  (spaces (+ tab 2) strm)
  (format strm "(alpha ~a)~%" (layered-network-alpha lnet))
  (spaces (+ tab 2) strm)
  (format strm "(eta ~a)" (layered-network-eta lnet))
  (dolist (param-val (cdr (layered-network-parameter-table lnet)))
    (format strm "~%")
    (spaces (+ tab 2) strm)
    (format strm "(~a ~a)" (car param-val) (cdr (param-val))))
  (format strm ")~%"))

(defun save-layered-network-layers (lnet &optional 
					 (strm t) (tab 0) (detailp nil))
  (spaces tab strm)
  (format strm "(layers")
  (dolist (name-layer (cdr (layered-network-layer-table lnet)))
    (format strm "~%")
    (spaces (+ tab 2))
    (format strm "(@ . ")
    (save-layer (cdr name-layer) strm (+ tab 2) detailp)
    (spaces (+ tab 2))
    (format strm ")"))
  (format strm ")~%"))

(defun save-layered-network-links (lnet &optional 
					(strm t) (tab 0) (detailp nil))
  (spaces tab strm)
  (format strm "(links")
  (dolist (name-link (cdr (layered-network-link-table lnet)))
    (format strm "~%")
    (spaces (+ tab 2))
    (format strm "(@ . ")
    (save-link (cdr name-link) strm (+ tab 2) detailp)
    (spaces (+ tab 2)) 
    (format strm ")"))
  (format strm ")"))

(defun save-layered-network (lnet &optional (strm t) (tab 0) (detailp nil))
  (spaces tab strm)
  (format strm "(layered-network ~a~%" (layered-network-name lnet))
  (save-layered-network-parameters lnet strm (+ 2 tab) detailp)
  (save-layered-network-layers lnet strm (+ 2 tab) detailp)
  (save-layered-network-links lnet strm (+ 2 tab) detailp)
  (spaces tab strm)
  (format strm ")~%"))

(defun match (a b)
  (match-sub a b (list nil)))

(defun match-sub (a b blist)
  (cond ((eql a b)
	 blist)
	((and (consp a)
	      (equal (first a)
		     :var))
	 (let ((bindp (assoc a blist :test 'equal)))
	   (if bindp 
	       (match-sub (cdr bindp) b blist)
	     (progn
	       (push (cons a b)
		     (cdr blist))
	       blist))))
	((and (consp b)
	      (equal (first b)
		     :var))
	 (let ((bindp (assoc b blist :test 'equal)))
	   (if bindp 
	       (match-sub a (cdr bindp) blist)
	     (progn
	       (push (cons b a)
		     (cdr blist))
	       blist))))
	((and (consp a) (consp b))
	 (and (match-sub (car a) (car b) blist)
	      (match-sub (cdr a) (cdr b) blist)))))

(defun subst-multi (tree subst-table)
  (let ((equal-p (assoc tree subst-table :test 'equal)))
    (if equal-p
	(cdr equal-p)
      (if (consp tree)
	  (cons (subst-multi (car tree) subst-table)
		(subst-multi (cdr tree) subst-table))
	tree))))

(defun assoc-by-match (key subst-table)
  (if (null subst-table) 
      nil
    (let* ((entry (first subst-table))
	   (match-p (match key (car entry))))
      (if match-p 
	  (cons (car entry) (subst-multi (cdr entry) match-p))
	(assoc-by-match key (rest subst-table))))))

(defun subst-multi-by-match (tree subst-table)
  (let ((equal-p (assoc-by-match tree subst-table)))
    (if equal-p
	(cdr equal-p)
      (if (consp tree)
	  (cons (subst-multi-by-match (car tree) subst-table)
		(subst-multi-by-match (cdr tree) subst-table))
	tree))))

(defmacro with-layered-network (var-lnet &rest body)
  (let* ((var (first var-lnet))
	 (lnet (second var-lnet)))
    (cons 'progn 
    (subst-multi-by-match 
     body 
     `(((,var name) 
	. (layered-network-name ,lnet))
       ((,var temperature) 
	. (layered-network-temperature ,lnet))
       ((,var alpha) 
	. (layered-network-alpha ,lnet))
       ((,var eta) 
	. (layered-network-eta ,lnet))
       ((,var layer (:var name))
	. (get-layer-by-name '(:var name) ,lnet))
       ((,var layer (:var name) (:var slot))
	. (slot (get-layer-by-name '(:var name) ,lnet) layer
		'(:var slot)))
       ((,var link (:var name))
	. (get-link-by-name '(:var name) ,lnet))
       ((,var link (:var name) (:var slot))
	. (slot (get-link-by-name '(:var name) ,lnet) link
		'(:var slot))))))))

;;(with-layered-network (LNET ID) ...)
;;	(ID name) -> 
;;	(ID temperature) -> (layered-network-temperature LNET)
;;	(ID alpha) -> (layered-network-alpha LNET)
;;	(ID eta) -> (layered-network-eta LNET)
;;	(ID layer LAYER-NAME) -> (get-layer LNET LAYER-NAME)
;;	(ID link (FROM TO)) -> (get-link LNET (FROM TO))



