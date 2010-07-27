;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/tkforeign.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;;
;;; Prototypes for libtk
;;;

(provide :tkforeign)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(export '(tkInitDisplay
	  tkInitDisplayMode
	  tkInitDisplayModePolicy
	  tkInitDisplayModeID
	  tkInitPosition
	  tkInitWindow
	  tkCloseWindow
	  tkQuit
	  
	  tkSetWindowLevel
	  tkSwapBuffers
	  
	  tkExec
	  tkExposeFunc
	  tkReshapeFunc
	  tkDisplayFunc
	  tkKeyDownFunc
	  tkMouseDownFunc
	  tkMouseUpFunc
	  tkMouseMoveFunc
	  tkIdleFunc
	  
	  tkGetColorMapSize
	  tkGetMouseLoc
	  tkGetSystem
	  tkGetDisplayModePolicy
	  tkGetDisplayModeID
	  tkGetDisplayMode
	  tkGetContext
	  
	  tkSetOneColor
	  tkSetFogRamp
	  tkSetGreyRamp
	  tkSetRGBMap
	  tkSetOverlayMap
	  
	  tkNewCursor
	  tkSetCursor
	  
	  tkRGBImageLoad
	  
	  tkCreateStrokeFont
	  tkCreateOutlineFont
	  tkCreateFilledFont
	  tkCreateBitmapFont
	  tkDrawStr
	  
	  tkWireSphere
	  tkSolidSphere
	  tkWireCube
	  tkSolidCube
	  tkWireBox
	  tkSolidBox
	  tkWireTorus
	  tkSolidTorus
	  tkWireCylinder
	  tkSolidCylinder
	  tkWireCone
	  tkSolidCone
	  
	  ))

#|
(defforeign tkInitDisplay TK "tkInitDisplay" () :integer)
(defforeign tkInitDisplayMode TK "tkInitDisplayMode" (:integer) :integer)
(defforeign tkInitDisplayModePolicy TK "tkInitDisplayModePolicy" (:integer) :integer)
(defforeign tkInitDisplayModeID TK "tkInitDisplayModeID" (:integer) :integer)
(defforeign tkInitPosition TK "tkInitPosition" (:integer :integer :integer :integer) :integer)
(defforeign tkInitWindow TK "tkInitWindow" (:string) :integer)
(defforeign tkCloseWindow TK "tkCloseWindow" () :integer)
(defforeign tkQuit TK "tkQuit" () :integer)

(defforeign tkSetWindowLevel TK "tkSetWindowLevel" (:integer) :integer)
(defforeign tkSwapBuffers TK "tkSwapBuffers" () :integer)

(defforeign tkExec TK "tkExec" () :integer)
(defforeign tkExposeFunc TK "tkExposeFunc" (:string)) :integer)
(defforeign tkReshapeFunc TK "tkReshapeFunc" (:string)) :integer)
(defforeign tkDisplayFunc TK "tkDisplayFunc" (:string)) :integer)
(defforeign tkKeyDownFunc TK "tkKeyDownFunc" (:string)) :integer)
(defforeign tkMouseDownFunc TK "tkMouseDownFunc" (:string)) :integer)
(defforeign tkMouseUpFunc TK "tkMouseUpFunc" (:string)) :integer)
(defforeign tkMouseMoveFunc TK "tkMouseMoveFunc" (:string)) :integer)
(defforeign tkIdleFunc TK "tkIdleFunc" (:string)) :integer)

(defforeign tkGetColorMapSize TK "tkGetColorMapSize" () :integer)
(defforeign tkGetMouseLoc TK "tkGetMouseLoc" (:string :string) :integer)
(defforeign tkGetSystem TK "tkGetSystem" (:integer :string) :integer)
(defforeign tkGetDisplayModePolicy TK "tkGetDisplayModePolicy" () :integer)
(defforeign tkGetDisplayModeID TK "tkGetDisplayModeID" () :integer)
(defforeign tkGetDisplayMode TK "tkGetDisplayMode" () :integer)
(defforeign tkGetContext TK "tkGetContext" () :integer)

(defforeign tkSetOneColor TK "tkSetOneColor" (:integer :float :float :float) :integer)
(defforeign tkSetFogRamp TK "tkSetFogRamp" (:integer :integer) :integer)
(defforeign tkSetGreyRamp TK "tkSetGreyRamp" () :integer)
(defforeign tkSetRGBMap TK "tkSetRGBMap" (:integer :string) :integer)
(defforeign tkSetOverlayMap TK "tkSetOverlayMap" (:integer :string) :integer)

(defforeign tkNewCursor TK "tkNewCursor" (:integer :string :string :integer :integer :integer :integer) :integer)
(defforeign tkSetCursor TK "tkSetCursor" (:integer) :integer)

(defforeign tkRGBImageLoad TK "tkRGBImageLoad" (:string) :integer)

(defforeign tkCreateStrokeFont TK "tkCreateStrokeFont" (:integer) :integer)
(defforeign tkCreateOutlineFont TK "tkCreateOutlineFont" (:integer) :integer)
(defforeign tkCreateFilledFont TK "tkCreateFilledFont" (:integer) :integer)
(defforeign tkCreateBitmapFont TK "tkCreateBitmapFont" (:integer) :integer)
(defforeign tkDrawStr TK "tkDrawStr" (:integer :string) :integer)

(defforeign tkWireSphere TK "tkWireSphere" (:integer :float) :integer)
(defforeign tkSolidSphere TK "tkSolidSphere" (:integer :float) :integer)
(defforeign tkWireCube TK "tkWireCube" (:integer :float) :integer)
(defforeign tkSolidCube TK "tkSolidCube" (:integer :float) :integer)
(defforeign tkWireBox TK "tkWireBox" (:integer :float :float :float) :integer)
(defforeign tkSolidBox TK "tkSolidBox" (:integer :float :float :float) :integer)
(defforeign tkWireTorus TK "tkWireTorus" (:integer :float :float) :integer)
(defforeign tkSolidTorus TK "tkSolidTorus" (:integer :float :float) :integer)
(defforeign tkWireCylinder TK "tkWireCylinder" (:integer :float :float) :integer)
(defforeign tkSolidCylinder TK "tkSolidCylinder" (:integer :float :float) :integer)
(defforeign tkWireCone TK "tkWireCone" (:integer :float :float) :integer)
(defforeign tkSolidCone TK "tkSolidCone" (:integer :float :float) :integer)
|#
