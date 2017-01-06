;;; -*- lisp -*-
;;; $Header$
;;; glxforeign.l

(provide :glxforeign)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(export '(glXChooseVisual
	  glXCopyContext
	  glXCreateContext
	  glXCreateGLXPixmap
	  glXDestroyContext
	  glXDestroyGLXPixmap
	  glXGetConfig
	  glXGetCurrentContext
	  glXGetCurrentDrawable
	  glXIsDirect
	  glXMakeCurrent
	  glXQueryExtension
	  glXQueryVersion
	  glXSwapBuffers
	  glXUseXFont
	  glXWaitGL
	  glXWaitX))
#+(or :x86_64 :aarch64)
(eval-when (load)
  (setf (symbol-function 'glxchoosevisual-for-wrap)
        (symbol-function 'glxchoosevisual))
  (defun glxchoosevisual (display screen attr)
    (funcall #'glxchoosevisual-for-wrap
             display screen (user::lvector2integer-bytestring attr)))
  )
#|
(defforeign glXChooseVisual GLX "glXChooseVisual" (:string :integer :string) :integer)
(defforeign glXCopyContext GLX "glXCopyContext" (:string :string :string :integer) :integer)
(defforeign glXCreateContext GLX "glXCreateContext" (:string :string :string :integer) :integer)
(defforeign glXCreateGLXPixmap GLX "glXCreateGLXPixmap" (:string :string :integer) :integer)
(defforeign glXDestroyContext GLX "glXDestroyContext" (:string :string) :integer)
(defforeign glXDestroyGLXPixmap GLX "glXDestroyGLXPixmap" (:string :integer) :integer)
(defforeign glXGetConfig GLX "glXGetConfig" (:string :string :integer :string) :integer)
(defforeign glXGetCurrentContext GLX "glXGetCurrentContext" () :integer)
(defforeign glXGetCurrentDrawable GLX "glXGetCurrentDrawable" () :integer)
(defforeign glXIsDirect GLX "glXIsDirect" (:string :string) :integer)
(defforeign glXMakeCurrent GLX "glXMakeCurrent" (:string :integer :integer) :integer)
(defforeign glXQueryExtension GLX "glXQueryExtension" (:string :string :string) :integer)
(defforeign glXQueryVersion GLX "glXQueryVersion" (:string :string :string) :integer)
(defforeign glXSwapBuffers GLX "glXSwapBuffers" (:integer :integer) :integer)
(defforeign glXUseXFont GLX "glXUseXFont" (:integer :integer :integer :integer) :integer)
(defforeign glXWaitGL GLX "glXWaitGL" () :integer)
(defforeign glXWaitX GLX "glXWaitX" () :integer)
|#
