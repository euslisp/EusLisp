;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/toiv.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;;
;;; toiv.l -- eus model (body) -> Inventor file translator
;;;
;;; sample:
;;; (with-open-file (*standard-output* "a.iv" :direction :output) (toiv (make-cube 100 100 100)))
;;; then, ``ivview a.iv''.

(require :geoclasses "lisp/geo/geoclasses.l")
(require :gldecl "lisp/opengl/src/gldecl.l")

(defvar *scale* 1.0)

#|
(defstruct colormaterial
  ambient
  diffuse
  specular
  emission
  shininess)
|#


(defun toiv (file &rest bodies)
  (format file "#Inventor V1.0 ascii~%")
  (format file "Separator {~%~%")
  (format file " ShapeHints {~%")
  (format file "    hints (SURFACE | ORDERED)~%")
  (format file " }~%~%")
  (dolist (abody bodies)
    (labels ((faces (thing)
		    (cond ((listp thing)
			   (apply #'append (mapcar #'faces thing)))
			  ((find-method thing :drawners)
			   (when (find-method thing :worldcoords)
				 (send thing :worldcoords))
			   (apply #'append (mapcar #'faces (send thing :drawners))))
			  (t
			   (when (find-method thing :worldcoords)
				 (send thing :worldcoords))
			   (send thing :faces)))))
	    (let* ((faces (faces abody))
		   (vertices-l (mapcar #'(lambda (f) (cdr (send f :vertices))) faces))
		   (normals (mapcar #'(lambda (f) (send f :normal)) faces))
		   material)
	      (format file "  Group {~%")
	      (when (and (derivedp abody body)
			 (setf material (get abody :gl-material)))
		    (let ((ambient (colormaterial-ambient material))
			  (diffuse (colormaterial-diffuse material))
			  (specular (colormaterial-specular material))
			  (emission (colormaterial-emission material))
			  (shininess (colormaterial-shininess material)))
		      (format file "  Material {~%")
		      (format file "    ambientColor ~a ~a ~a~%" (aref ambient 0) (aref ambient 1) (aref ambient 2))
		      (format file "    diffuseColor ~a ~a ~a~%" (aref diffuse 0) (aref diffuse 1) (aref diffuse 2))
		      (format file "    specularColor ~a ~a ~a~%" (aref specular 0) (aref specular 1) (aref specular 2))
		      (format file "    emissiveColor ~a ~a ~a~%" (aref emission 0) (aref emission 1) (aref emission 2))
		      (format file "    shininess ~a~%" shininess)
		      (format file "    transparency ~a~%" 0)
		      (format file "  }~%")))
	      (format file "    Coordinate3 {~%")
	      (format file "         point [~%")
	      (dolist (vl vertices-l)
		(dolist (v vl)
		  (format file "            ~a ~a ~a,~%"
			  (* (elt v 0) *scale*)
			  (* (elt v 1) *scale*)
			  (* (elt v 2) *scale*))))
	      (format file "        ]~%")
	      (format file "    }~%")
	      (format file "    Normal {~%")
	      (format file "      vector [~%")
	      (dolist (n normals)
		(format file "            ~a ~a ~a,~%"
			(elt n 0)
			(elt n 1)
			(elt n 2)))
	      (format file "       ]~%")
	      (format file "    }~%")
	      (format file "   NormalBinding {~%")
	      (format file "      value PER_FACE~%")
	      (format file "   }~%")
	      (format file "IndexedFaceSet {~%")
	      (format file "   coordIndex [~%")
	      (let ((ind 0))
		(dolist (vl vertices-l)
		  (dolist (v vl)
		    (format file "~a, " ind)
		    (incf ind))
		  (format file "~a,~%" -1)))
	      (format file "   ]~%")
	      (format file "  }~%")
	      (format file " }~%")
	      )))
  (format file "}~%")
  )

(provide :toiv)
