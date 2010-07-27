;;;; VRML parser 
;;;  version 1.0 Nov/96/3
;;;  (c) 1996, Toshihiro Matsui, Electrotechnical Laboratory
;;;

(unless (find-package :VRML)
    (make-package :vrml))

(in-package :VRML)
(defparameter *VRML-package* *package*)

(export '(load-wrl *vrml-bodies* *vrml-nodes* *vrml-node-counts* read-vrml-1))

(require :vrml-node-spec "vrmlNodeSpec.l")

(defvar *vrml-readtable* (copy-readtable))
(defvar *vrml-source*)
(defvar *vrml-token*)
(defparameter *nodeNames* nil)

(defvar *fields*  (make-array '(0) :fill-pointer t))

;(defvar *eventIns* (make-array '(0) :fill-pointer t))
;(defvar *eventOuts* (make-array '(0) :fill-pointer t))
;(defvar *inProto* nil)

(defvar *vrml-nodes* nil)
(defvar *vrml-node-counts* 
   (mapcar #'(lambda (x) (list x 0)) *nodeTypes*))
(defvar *vrml-bodies* nil)
(defparameter *vrml-eof* (gentemp "EOF"))

(proclaim '(special *vrml-eof*))

;;;;;

;;;;
(defun load-wrl (file)
   (with-open-file (in file)
      (setq *vrml-source* in)
      (setq *vrml-nodes* nil)
      (setq *vrml-bodies* nil)
      (setq *nodeNames* nil)
      (setq *vrml-node-counts*
	    (mapcar #'(lambda (x) (list x 0)) *nodeTypes*))
      (vrmlscene)))

(defun load-wrl-from-url (url)
   (load-wrl (namestring (url-pathname url))))

(defun read-vrml-1 (&optional (strm t) (*vrml-eof* *vrml-eof*))
   (let ((*package* *VRML-package*))
   (setq *vrml-source* strm)
   (read-vrml-token)
   (if (eql *vrml-eof* *vrml-token*)
       *vrml-eof*
       (declaration)))
   )


;****************************************************************

(defun vrmlScene ()
   (let (results val)
      (read-vrml-token)
      (while (not (eql *vrml-token* *vrml-eof*))
	 (setq val (Declaration)) 
	 (if val (push val results))
	 ;; read the next token
	 (read-vrml-token) )
      (nreverse results)))

(defun declaration ()
   (cond ((eql *vrml-token* 'PROTO) (protoDeclaration ))
	 ((eql *vrml-token* 'ROUTE) (routeDeclaration ))
	 ((eql *vrml-token* 'NULL) nil)
	 (t (nodeDeclaration))
   ))

(defun reference-id (id table)
   (cadr (assoc id table)))

(defun nodeDeclaration ()
  (cond ((eql *vrml-token* 'DEF)
	 (let* ((id (read-vrml-token))
	        (node (node (read-vrml-token)))
		)
	    (warning-message 6 "; nodedecl DEF ~s ~s~%" id node)
	    (push (list id node) *nodeNames*)
	    ;; (print node)
            (if (consp node)
		(dolist (n node)
		   (if (and n (derivedp n propertied-object))
			(setf (get n :name) id)))
	        (if (and node (derivedp node propertied-object))
			(setf (get node :name) id))
		)
	    node))
	((eql *vrml-token* 'USE)
	 (let ((id (read-vrml-token)) (ref))
	    (setq ref (reference-id id *nodeNames*))
	    ;; (format t "; nodedecl USE ~s~%" ref)
	    ;; (read-vrml-token)
	    ;(list 'USE id)
	    ref
	    ))
	((member *vrml-token* *nodeTypes*)
	 (node *vrml-token*))
	((eql *vrml-token* *vrml-eof*) *vrml-eof*)
	(t (error ";; illegal nodeDeclaration ~s " *vrml-token*))
        )
   )

(defun braced-expression (fun target &rest args)
  (let (expressions)
    (read-vrml-token)
    (unless (eql *vrml-token* '|{|)
        (error "vrml: '{' expected for a ~s, but ~s appeared."
		*vrml-token* target)
	(return-from braced-expression nil))
    (read-vrml-token)
    (while (not (eql *vrml-token* '|}|))
	;; (format t "; braced-expression token=~s~%" *vrml-token*)
        (push (apply fun args) expressions)
	)
    ;** (read-vrml-token)
    (nreverse expressions))
)

(defun skip-braced-expression ()
  (let ((brace-count 1))
    (read-vrml-token)	;; `{'
    (while (> brace-count 0)
 	(cond ((eql *vrml-token* '|{|)	(incf brace-count) (read-vrml-token))
	      ((eql *vrml-token* '|}|)  (decf brace-count))
	      (t (read-vrml-token)))
    )) )
   
(defun node (&optional (type (read-vrml-token)))
   (cond ((eql *vrml-token* 'Script)
	  ;; (list 'script (braced-expression #'scriptGut 'scriptGut )) 
	  ;; ignore script
	  (read-vrml-token)
	  (skip-braced-expression)
	  nil ) 
	 ((member type *nodetypes*)
	  (let ((nodeFunc (get type :vrml-node-func))
	        (nodeSpec (get type :vrml-node-spec))
	        (nodeGuts) (node-obj (make-vrml-node type)))
	    (incf (cadr (assoc type *vrml-node-counts*)))
            (setq nodeGuts
		 (braced-expression 'nodeGut 'nodeGut
			 node-obj
			 (cdr (assoc 'field nodeSpec))
	 		 (cdr (assoc 'eventIn nodeSpec))
	 		 (cdr (assoc 'eventOut nodeSpec)) ))
	    (if nodeFunc
		(setq node-obj (funcall nodeFunc node-obj)))
	    (push node-obj *vrml-nodes*)
	    node-obj ))
	 (t (warning-message 6  ";; nodeId expected, but ~s~%" type)
	    (read-vrml-token)  ;; ??? unnecessary ???
	    (skip-braced-expression)
	    ))
   )

(defun nodeGut (nodeobj Fields EventIns EventOuts)
  (let* ((id *vrml-token*) (val) (token) (tokens) value-spec)
     (cond ((setq value-spec (cdr (assoc id Fields)))
		(read-vrml-token)
		(if (eql *vrml-token* 'IS)
		    (list 'is (read-vrml-token))
		    (let ((val (funcall (car value-spec))))	;fieldtype dependent func
			(send nodeobj :set-field id val))))
	   ((setq value-spec (cdr (assoc id eventIns)))
		(read-vrml-token)
		(if (not (eql *vrml-token*  'IS))
		    (error "IS expected for EventIn nodeGut, but ~s" val)
		    (let ((val (funcall (car value-spec))))	;fieldtype dependent func
			(send nodeobj :set-field id val))
		))
	   ((setq value-spec (cdr (assoc id eventOuts)))
		(read-vrml-token)
		(if (not (eql *vrml-token*  'IS))
		    (error "IS expected for EventOut nodeGut, but ~s" val)
		    (let ((val (funcall (car value-spec))))	;fieldtype dependent func
			(send nodeobj :set-field id val))
		))
	   ((eql id 'ROUTE) (routedeclaraton))
	   ((eql id 'PROTO) (protoDeclaration))
	   (t (warning-message 4 ";; illegal field id ~s~%" id)
	      ;; (skip-braced-expression)
	      (read-vrml-token))
     ))
  )

;;

(defun routeDeclaration ()
   (let (tokens)
	(push 'route tokens)
	(push (read-vrml-token) tokens)
	(push (read-vrml-token) tokens)
	(if (not (eql (first tokens) 'TO))
	    (error "to expected for route, but ~s" (first tokens)))
	(push (read-vrml-token) tokens)
	;; (read-vrml-token)
	(print (nreverse tokens))
	nil))
  
(defun protoDeclaration ()
   (warning-message 3 "PROTO declaration is not yet implemented.~%")
   (read-vrml-token))

;;; fields
;;  names of the following functions have to match the field type ids.
;;  All these function assumes the first element in a field is in *vrml-token*,
;;  and leave *vrml-token* updated when processing finishes.

;; single value field

(defun sfbool ()
   (case (prog1 *vrml-token* (read-vrml-token))
     (TRUE  t)
     (FALSE nil)
     (t (error "TRUE or FALSE expected for sfbool, but ~s" *vrml-token*))))

(defun sfcolor ()
   (prog1 (float-vector *vrml-token* (read-vrml-token) (read-vrml-token))
	  (read-vrml-token)))

(defun sffloat () (prog1  (float *vrml-token*) (read-vrml-token)))
(defun sfimage ()
   (let (floats)
      (while (numberp *vrml-token*)
	 (push *vrml-token* floats)
	 (read-vrml-token))
      (nreverse floats)))
(defun sfint32 () (prog1 *vrml-token* (read-vrml-token)))

(defun sfnode () 
   (if (eql *vrml-token* 'NULL)
	nil
	(prog1 (nodeDeclaration) (read-vrml-token))))

(defun sfrotation ()
   (prog1 (list (float-vector *vrml-token* (read-vrml-token) (read-vrml-token))
		(read-vrml-token))
	  (read-vrml-token)))
(defun sfstring ()
   (if (not (stringp *vrml-token*))
	(error "string expected for sfstring, but ~s" *vrml-token*))
   (prog1 *vrml-token* (read-vrml-token)))
(defun sftime ()
   (prog1 *vrml-token* (read-vrml-token)))	;double float
(defun sfvec2f ()
   (prog1 (float-vector *vrml-token* (read-vrml-token))
	  (read-vrml-token)))
(defun sfvec3f ()
   (prog1 (float-vector *vrml-token* (read-vrml-token) (read-vrml-token))
	  (read-vrml-token)))

;; multiple value fields

(defun multiple-fields (single-func)
   (cond ((eql *vrml-token* '|[|)
	   (let (values v)
	      (read-vrml-token)
	      (while (not (eql *vrml-token* '|]|))
		 (push (funcall single-func) values)
		 ;; (read-vrml-token)
		 )
	      ;; here, *vrml-token* is '|]|
	      (read-vrml-token)
	      (nreverse values)))
	 (t (list (funcall single-func)))))

(defun mfcolor () (multiple-fields #'sfcolor))
(defun mffloat () (multiple-fields #'sffloat))
(defun mfint32 () (multiple-fields #'sfint32))
(defun mfnode () (multiple-fields #'sfnode))
(defun mfrotation () (multiple-fields #'sfrotation))
(defun mfstring () (multiple-fields #'sfstring))
(defun mfvec2f () (multiple-fields #'sfvec2f))
(defun mfvec3f () (multiple-fields #'sfvec3f))


;;;
;;; token reader
;;;

(defun read-vrml-token (&optional (strm *vrml-source*) (eof *vrml-eof*))
   (let ((*readtable* *vrml-readtable*) (*package* *vrml-package*))
     (setq *vrml-token* (read strm nil eof))
     (if (and (symbolp *vrml-token*)
	      (eql (aref (symbol-pname *vrml-token*) 0) #\0)
	      (member (aref (symbol-pname *vrml-token*) 1) '(#\X #\x)))
         (let ((*read-base* 16))
	    (setq *vrml-token* 
		  (read (make-string-input-stream (subseq (symbol-pname 2))))))
         ))
    ;; (print *vrml-token*)
    *vrml-token*))

(defun read-vrml (&optional (strm t) (eof nil))
   (let ((*readtable* *vrml-readtable*) (nodename) (body) )
      (read strm nil eof)))

(defun read-vrml-file (wrl)
   (let ((vrml) (tablet) (eof (cons 1 1)))
      (with-open-file (in wrl)
         (while (not (eql (setq tablet (read-vrml in eof)) eof))
	     (if tablet (push tablet vrml))
	))
      (nreverse vrml)))

(defun read-vrml-tokens (wrl)
   (let ((vrml) (token) (eof (cons 1 1)))
      (with-open-file (in wrl)
         (while (not (eql (setq token (read-vrml-token in eof)) eof))
	     (if token (push token vrml))
	))
      (nreverse vrml)))


;;;;
;;;; read macros
;;;;

(defun read-braced-list (strm char)
   (let (p r)
     (while (not (eql (setq p (read-vrml-token strm)) '}))
	(push p r))
     (nreverse r)))

(defun read-bracketed-vector (strm char)
   (let (p r)
     (while (not (eql (setq p (read strm)) '|]|))
	(push p r))
     (coerce (nreverse r) 
	 (if (every #'numberp r) float-vector vector)) )
  )

(defun read-negative-vrml-number (strm char)    (- (read-vrml-token strm)))

(defun read-vrml-comma (strm char) (read-vrml-token strm))
(defun read-vrml-comment (strm char)
   (read-line strm nil *vrml-eof*)
   (read-vrml-token strm))

(defun terminate-braced-list (strm char)   '|}|  )
(defun terminate-bracketed-vector (strm char)   '|]|  )

(defun read-left-brace (strm char) '|{|)
(defun read-right-brace (strm char) '|}|)
(defun read-left-bracket (strm char) '|[|)
(defun read-right-bracket (strm char) '|]|)

;(set-macro-character #\{ #'read-braced-list nil *vrml-readtable*)
;(set-macro-character #\} #'terminate-braced-list nil *vrml-readtable*)
;(set-macro-character #\[ #'read-bracketed-vector nil *vrml-readtable*)
;(set-macro-character #\] #'terminate-bracketed-vector nil *vrml-readtable*)
(set-macro-character #\{ #'read-left-brace nil *vrml-readtable*)
(set-macro-character #\} #'read-right-brace nil *vrml-readtable*)
(set-macro-character #\[ #'read-left-bracket nil *vrml-readtable*)
(set-macro-character #\] #'read-right-bracket nil *vrml-readtable*)

;;(set-syntax-from-char #\- #\# *vrml-readtable*)
(set-macro-character #\- #'read-negative-vrml-number nil *vrml-readtable*)
(setf (aref (readtable-syntax *vrml-readtable*) #\-) 8)
(set-macro-character #\, #'read-vrml-comma nil *vrml-readtable*)

(set-macro-character #\# #'read-vrml-comment nil *vrml-readtable*)

(provide :vrmlParser)

