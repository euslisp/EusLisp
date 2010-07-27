;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/glutil.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;;
;;; glutil.l -- utility routing for eusgl

(provide :glutil)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;

#|
(setq libutil (load-foreign "util.so"))
|#

(export '(glClearColorfv
	  glOrtho6f
	  glOrthofv
	  glRotatefv
	  glTranslatefv
	  auxSolidTeapotfv
	  glClipPlanef
	  auxSolidSpherefv
	  auxWireSpherefv
	  auxSolidCylinderfv
	  auxSolidConefv
	  auxSolidBoxfv
	  gluPerspectivefv
	  gluLookAtfv
	  gluTessCallbackl
	  auxSolidTorusfv
	  auxSolidCubefv
	  auxSolidOctahedronfv
	  glAccumfv
	  glClearAccumfv
	  gluDiskfv
	  gluPartialDiskfv
	  auxWireIcosahedronfv
	  glScalefv
	  gluNurbsProperty
	  glBitmapfv
	  glMap2fv
	  auxSetOneColorfv
	  glAccumfv
	  glFrustumfv
	  gluOrtho2Dfv
	  glPointSizefv
	  glClearIndexfv
	  glPolygonOffsetExtfv))

;;

#|
(defforeign glClearColorfv libutil "glClearColorfv" (:string) :integer)
(defforeign glOrtho6f libutil "glOrtho6f" (:float :float :float :float :float :float) :integer)
(defforeign glOrthofv libutil "glOrthofv" (:string) :integer)
(defforeign glRotatefv libutil "glRotatefv" (:string) :integer)
(defforeign glTranslatefv libutil "glTranslatefv" (:string) :integer)
(defforeign auxSolidTeapotfv libutil "auxSolidTeapotfv" (:string) :integer)
(defforeign glClipPlanef libutil "glClipPlanef" (:integer :string) :integer)
(defforeign auxSolidSpherefv libutil "auxSolidSpherefv" (:string) :integer)
(defforeign auxWireSpherefv libutil "auxWireSpherefv" (:string) :integer)
(defforeign auxSolidCylinderfv libutil "auxSolidCylinderfv" (:string) :integer)
(defforeign auxSolidConefv libutil "auxSolidConefv" (:string) :integer)
(defforeign auxSolidBoxfv libutil "auxSolidBoxfv" (:string) :integer)
(defforeign gluPerspectivefv libutil "gluPerspectivefv" (:string) :integer)
(defforeign gluLookAtfv libutil "gluLookAtfv" (:string) :integer)
(defforeign gluTessCallbackl libutil "gluTessCallbackl" () :integer)
(defforeign auxSolidTorusfv libutil "auxSolidTorusfv" (:string) :integer)
(defforeign auxSolidCubefv libutil "auxSolidCubefv" (:string) :integer)
(defforeign auxSolidOctahedronfv libutil "auxSolidOctahedronfv" (:string) :integer)
(defforeign glClearAccumfv libutil "glClearAccumfv" (:string) :integer)
(defforeign glAccumfv libutil "glAccumfv" (:integer :string) :integer)
(defforeign gluDiskfv libutil "gluDiskfv" (:integer :string) :integer)
(defforeign gluPartialDiskfv libutil "gluPartialDiskfv" (:integer :string) :integer)
(defforeign auxWireIcosahedronfv libutil "auxWireIcosahedronfv" (:string) :integer)
(defforeign glScalefv libutil "glScalefv" (:string) :integer)
(defforeign gluNurbsPropertyfv libutil "gluNurbsPropertyfv" (:integer :integer :string) :integer)
(defforeign glMapGrid2fv libutil "glMapGrid2fv" (:string) :integer)
(defforeign glBitmapfv libutil "glBitmapfv" (:integer :integer :string :string) :integer)
(defforeign glMap1fv libutil "glMap1fv" (:integer :string :string) :integer)
(defforeign glMap2fv libutil "glMap2fv" (:integer :string :string) :integer)
(defforeign auxSetOneColorfv libutil "auxSetOneColorfv" (:integer :string) :integer)
(defforeign glFrustumfv libutil "glFrustumfv" (:string) :integer)
(defforeign gluOrtho2Dfv libutil "gluOrtho2Dfv" (:string) :integer)
(defforeign glPointSizefv libutil "glPointSizefv" (:string) :integer)
(defforeign glClearIndexfv libutil "glClearIndexfv" (:string) :integer)
|#
