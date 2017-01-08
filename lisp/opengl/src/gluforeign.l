;;; -*- lisp -*-
;;; $Header$
;;; gluforeign.l -- libGLU foreign code definitions

(provide :gluforeign)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;;
;;; Return the error string associated with a particular error code.
;;; This will return 0 for an invalid error code.
;;;

;;; typedef struct GLUquadricObj GLUquadricObj;
;;; typedef struct GLUtriangulatorObj GLUtriangulatorObj;
;;; typedef struct GLUnurbsObj GLUnurbsObj;

(export '(gluErrorString
          
          gluOrtho2D
          gluPerspective
          gluPickMatrix
          gluLookAt
          gluProject
          gluUnProject
          
          gluScaleImage
          
          gluBuild1DMipmaps
          gluBuild2DMipmaps
          
          gluNewQuadric
          gluDeleteQuadric
          gluQuadricNormals
          gluQuadricTexture
          gluQuadricOrientation
          gluQuadricDrawStyle
          gluCylinder
          gluDisk
          gluPartialDisk
          gluSphere
          gluQuadricCallback
          
          gluNewTess
          gluTessCallback
          gluDeleteTess
          gluBeginPolygon
          gluEndPolygon
          gluNextContour
          gluTessVertex
          
          gluNewNurbsRenderer
          gluDeleteNurbsRenderer
          gluBeginSurface
          gluBeginCurve
          gluEndCurve
          gluEndSurface
          gluBeginTrim
          gluEndTrim
          gluPwlCurve
          gluNurbsCurve
          gluNurbsSurface
          gluLoadSamplingMatrices
          gluNurbsProperty
          gluGetNurbsProperty
          gluNurbsCallback
          ))
#+(or :x86_64 :aarch64)
(eval-when (load)
  ;; define wrapped functions later
  (setf (symbol-function 'gluNurbsProperty-org)
        (symbol-function 'gluNurbsProperty))
  (setf (symbol-function 'gluNurbsProperty)
        (symbol-function 'gluNurbsPropertyd))
  ;;
  (setf (symbol-function 'gluNurbsCurve-org)
        (symbol-function 'gluNurbsCurve))
  ;;
  (setf (symbol-function 'gluNurbsSurface-org)
        (symbol-function 'gluNurbsSurface))
  )
#+(or :x86_64 :aarch64)
(defun gluNurbsCurve (nobj nknots knot stride ctlarray order type)
  (let ((fknot (user::dvector2float-bytestring knot))
        (fctlarray (user::dvector2float-bytestring ctlarray)))
    (gluNurbsCurve-org nobj nknots fknot stride fctlarray order type)
    ))
#+(or :x86_64 :aarch64)
(defun gluNurbsSurface (nurb sknotcount sknots tknotCount tknots
                             sstride tstride control sorder torder type)
  (let ((fsknots (user::dvector2float-bytestring sknots))
        (ftknots (user::dvector2float-bytestring tknots))
        (fcontrol (user::dvector2float-bytestring control)))
    (gluNurbsSurface-org nurb sknotcount fsknots tknotCount ftknots
                         sstride tstride fcontrol sorder torder type)
    ))
#|
(defforeign gluErrorString GLU "gluErrorString" (:integer) :integer)

(defforeign gluOrtho2D GLU "gluOrtho2D" (:float :float :float :float) :integer)
(defforeign gluPerspective GLU "gluPerspective" (:float :float :float :float) :integer)
(defforeign gluPickMatrix GLU "gluPickMatrix" (:float :float :float :float :string) :integer)
(defforeign gluLookAt GLU "gluLookAt" (:float :float :float :float :float :float :float :float :float) :integer)
(defforeign gluProject GLU "gluProject" (:float :float :float :string :string :string :string :string :string) :integer)
(defforeign gluUnProject GLU "gluUnProject" (:float :float :float :string :string :string :string :string :string) :integer)

(defforeign gluScaleImage GLU "gluScaleImage" (:integer :integer :integer :integer :string :integer :integer :integer :string) :integer)

(defforeign gluBuild1DMipmaps GLU "gluBuild1DMipmaps" (:integer :integer :integer :integer :integer :string) :integer)
(defforeign gluBuild2DMipmaps GLU "gluBuild2DMipmaps" (:integer :integer :integer :integer :integer :integer :string) :integer)

(defforeign gluNewQuadric GLU "gluNewQuadric" () :integer)
(defforeign gluDeleteQuadric GLU "gluDeleteQuadric" (:integer) :integer)
(defforeign gluQuadricNormals GLU "gluQuadricNormals" (:integer :integer) :integer)
(defforeign gluQuadricTexture GLU "gluQuadricTexture" (:integer :integer) :integer)
(defforeign gluQuadricOrientation GLU "gluQuadricOrientation" (:integer :integer) :integer)
(defforeign gluQuadricDrawStyle GLU "gluQuadricDrawStyle" (:integer :integer) :integer)
(defforeign gluCylinder GLU "gluCylinder" (:integer :float  :float  :float  :integer  :integer) :integer)
(defforeign gluDisk GLU "gluDisk" (:integer :float  :float  :integer  :integer) :integer)
(defforeign gluPartialDisk GLU "gluPartialDisk" (:integer :float  :float  :integer  :integer  :float  :float) :integer)
(defforeign gluSphere GLU "gluSphere" (:integer :float  :integer  :integer) :integer)
(defforeign gluQuadricCallback GLU "gluQuadricCallback" (:integer :integer  :string) :integer)

(defforeign gluNewTess GLU "gluNewTess" () :integer)
(defforeign gluTessCallback GLU "gluTessCallback" (:integer :integer  :string) :integer)
(defforeign gluDeleteTess GLU "gluDeleteTess" (:integer) :integer)
(defforeign gluBeginPolygon GLU "gluBeginPolygon" (:integer) :integer)
(defforeign gluEndPolygon GLU "gluEndPolygon" (:integer) :integer)
(defforeign gluNextContour GLU "gluNextContour" (:integer :integer) :integer)
(defforeign gluTessVertex GLU "gluTessVertex" (:integer :string :string) :integer)

(defforeign gluNewNurbsRenderer GLU "gluNewNurbsRenderer" () :integer)
(defforeign gluDeleteNurbsRenderer GLU "gluDeleteNurbsRenderer" (:integer) :integer)
(defforeign gluBeginSurface GLU "gluBeginSurface" (:integer) :integer)
(defforeign gluBeginCurve GLU "gluBeginCurve" (:integer) :integer)
(defforeign gluEndCurve GLU "gluEndCurve" (:integer) :integer)
(defforeign gluEndSurface GLU "gluEndSurface" (:integer) :integer)
(defforeign gluBeginTrim GLU "gluBeginTrim" (:integer) :integer)
(defforeign gluEndTrim GLU "gluEndTrim" (:integer) :integer)
(defforeign gluPwlCurve GLU "gluPwlCurve" (:integer :integer  :string :integer  :integer) :integer)
(defforeign gluNurbsCurve GLU "gluNurbsCurve" (:integer :integer  :string :integer  :string :integer  :integer) :integer)
(defforeign gluNurbsSurface GLU "gluNurbsSurface" (:integer :integer :string :integer :string :integer :integer :string :integer  :integer  :integer) :integer)
(defforeign gluLoadSamplingMatrices GLU "gluLoadSamplingMatrices" (:integer :string :string :string) :integer)
(defforeign gluNurbsProperty GLU "gluNurbsProperty" (:integer :integer  :float) :integer)
(defforeign gluGetNurbsProperty GLU "gluGetNurbsProperty" (:integer :integer  :string) :integer)
(defforeign gluNurbsCallback GLU "gluNurbsCallback" (:integer :integer  :string) :integer)
|#
