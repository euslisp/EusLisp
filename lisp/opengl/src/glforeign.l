;;; -*- lisp -*-
;;; $Header$
;;; glforeign.l -- gl foreign function declarations (derived from /usr/include/GL/gl.h)

(provide :glforeign)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(export '(glAccum
          glAlphaFunc
          glBegin
          glBitmap
          glBlendFunc
          glCallList
          glCallLists
          glClear
          glClearAccum
          glClearColor
          glClearDepth
          glClearIndex
          glClearStencil
          glClipPlane
          glColor3b
          glColor3bv
          glColor3d
          glColor3dv
          glColor3f
          glColor3fv
          glColor3i
          glColor3iv
          glColor3s
          glColor3sv
          glColor3ub
          glColor3ubv
          glColor3ui
          glColor3uiv
          glColor3us
          glColor3usv
          glColor4b
          glColor4bv
          glColor4d
          glColor4dv
          glColor4f
          glColor4fv
          glColor4i
          glColor4iv
          glColor4s
          glColor4sv
          glColor4ub
          glColor4ubv
          glColor4ui
          glColor4uiv
          glColor4us
          glColor4usv
          glColorMask
          glColorMaterial
          glCopyPixels
          glCullFace
          glDeleteLists
          glDepthFunc
          glDepthMask
          glDepthRange
          glDisable
          glDrawBuffer
          glDrawPixels
          glEdgeFlag
          glEdgeFlagv
          glEnable
          glEnd
          glEndList
          glEvalCoord1d
          glEvalCoord1dv
          glEvalCoord1f
          glEvalCoord1fv
          glEvalCoord2d
          glEvalCoord2dv
          glEvalCoord2f
          glEvalCoord2fv
          glEvalMesh1
          glEvalMesh2
          glEvalPoint1
          glEvalPoint2
          glFeedbackBuffer
          glFinish
          glFlush
          glFogf
          glFogfv
          glFogi
          glFogiv
          glFrontFace
          glFrustum
          glGenLists
          glGetBooleanv
          glGetClipPlane
          glGetDoublev
          glGetError
          glGetFloatv
          glGetIntegerv
          glGetLightfv
          glGetLightiv
          glGetMapdv
          glGetMapfv
          glGetMapiv
          glGetMaterialfv
          glGetMaterialiv
          glGetPixelMapfv
          glGetPixelMapuiv
          glGetPixelMapusv
          glGetPolygonStipple
          glGetString
          glGetTexEnvfv
          glGetTexEnviv
          glGetTexGendv
          glGetTexGenfv
          glGetTexGeniv
          glGetTexImage
          glGetTexLevelParameterfv
          glGetTexLevelParameteriv
          glGetTexParameterfv
          glGetTexParameteriv
          glHint
          glIndexMask
          glIndexd
          glIndexdv
          glIndexf
          glIndexfv
          glIndexi
          glIndexiv
          glIndexs
          glIndexsv
          glInitNames
          glIsEnabled
          glIsList
          glLightModelf
          glLightModelfv
          glLightModeli
          glLightModeliv
          glLightf
          glLightfv
          glLighti
          glLightiv
          glLineStipple
          glLineWidth
          glListBase
          glLoadIdentity
          glLoadMatrixd
          glLoadMatrixf
          glLoadName
          glLogicOp
          glMap1d
          glMap1f
          glMap2d
          glMap2f
          glMapGrid1d
          glMapGrid1f
          glMapGrid2d
          glMapGrid2f
          glMaterialf
          glMaterialfv
          glMateriali
          glMaterialiv
          glMatrixMode
          glMultMatrixd
          glMultMatrixf
          glNewList
          glNormal3b
          glNormal3bv
          glNormal3d
          glNormal3dv
          glNormal3f
          glNormal3fv
          glNormal3i
          glNormal3iv
          glNormal3s
          glNormal3sv
          glOrtho
          glPassThrough
          glPixelMapfv
          glPixelMapuiv
          glPixelMapusv
          glPixelStoref
          glPixelStorei
          glPixelTransferf
          glPixelTransferi
          glPixelZoom
          glPointSize
          glPolygonMode
          glPolygonStipple
          glPopAttrib
          glPopMatrix
          glPopName
          glPushAttrib
          glPushMatrix
          glPushName
          glRasterPos2d
          glRasterPos2dv
          glRasterPos2f
          glRasterPos2fv
          glRasterPos2i
          glRasterPos2iv
          glRasterPos2s
          glRasterPos2sv
          glRasterPos3d
          glRasterPos3dv
          glRasterPos3f
          glRasterPos3fv
          glRasterPos3i
          glRasterPos3iv
          glRasterPos3s
          glRasterPos3sv
          glRasterPos4d
          glRasterPos4dv
          glRasterPos4f
          glRasterPos4fv
          glRasterPos4i
          glRasterPos4iv
          glRasterPos4s
          glRasterPos4sv
          glReadBuffer
          glReadPixels
          glRectd
          glRectdv
          glRectf
          glRectfv
          glRecti
          glRectiv
          glRects
          glRectsv
          glRenderMode
          glRotated
          glRotatef
          glScaled
          glScalef
          glScissor
          glSelectBuffer
          glShadeModel
          glStencilFunc
          glStencilMask
          glStencilOp
          glTexCoord1d
          glTexCoord1dv
          glTexCoord1f
          glTexCoord1fv
          glTexCoord1i
          glTexCoord1iv
          glTexCoord1s
          glTexCoord1sv
          glTexCoord2d
          glTexCoord2dv
          glTexCoord2f
          glTexCoord2fv
          glTexCoord2i
          glTexCoord2iv
          glTexCoord2s
          glTexCoord2sv
          glTexCoord3d
          glTexCoord3dv
          glTexCoord3f
          glTexCoord3fv
          glTexCoord3i
          glTexCoord3iv
          glTexCoord3s
          glTexCoord3sv
          glTexCoord4d
          glTexCoord4dv
          glTexCoord4f
          glTexCoord4fv
          glTexCoord4i
          glTexCoord4iv
          glTexCoord4s
          glTexCoord4sv
          glTexEnvf
          glTexEnvfv
          glTexEnvi
          glTexEnviv
          glTexGend
          glTexGendv
          glTexGenf
          glTexGenfv
          glTexGeni
          glTexGeniv
          glTexImage1D
          glTexImage2D
          glTexParameterf
          glTexParameterfv
          glTexParameteri
          glTexParameteriv
          glTranslated
          glTranslatef
          glVertex2d
          glVertex2dv
          glVertex2f
          glVertex2fv
          glVertex2i
          glVertex2iv
          glVertex2s
          glVertex2sv
          glVertex3d
          glVertex3dv
          glVertex3f
          glVertex3fv
          glVertex3i
          glVertex3iv
          glVertex3s
          glVertex3sv
          glVertex4d
          glVertex4dv
          glVertex4f
          glVertex4fv
          glVertex4i
          glVertex4iv
          glVertex4s
          glVertex4sv
          glViewport))

#+(or :x86_64 :aarch64)
(defmacro set-function-fv-as-dv (funcfv funcdv)
  `(progn
     (setf (symbol-function ',(read-from-string
                              (format nil "~a-org" funcfv)))
           (symbol-function ',funcfv))
     (setf (symbol-function ',funcfv)
           (symbol-function ',funcdv))
     ))
#+(or :x86_64 :aarch64)
(eval-when (load)
  ;; func_fv has to work as func_dv in x86_64
  (set-function-fv-as-dv glColor3fv glColor3dv)
  (set-function-fv-as-dv glcolor3fv glcolor3dv)
  (set-function-fv-as-dv glcolor4fv glcolor4dv)
  (set-function-fv-as-dv glnormal3fv glnormal3dv)
  (set-function-fv-as-dv glvertex2fv glvertex2dv)
  (set-function-fv-as-dv glvertex3fv glvertex3dv)
  (set-function-fv-as-dv gltexcoord2fv gltexcoord2dv)
  (set-function-fv-as-dv gltexgenfv glTexGendv)
  (set-function-fv-as-dv glgetfloatv glGetDoublev)
  (set-function-fv-as-dv glmultmatrixf glMultMatrixd)
  (set-function-fv-as-dv glPointSize glPointSized)
  (set-function-fv-as-dv glLineWidth glLineWidthd)
  ;; define wrapped functions later
  (setf (symbol-function 'glLightfv-org)
        (symbol-function 'glLightfv))
  (setf (symbol-function 'glGetMaterialfv-org)
        (symbol-function 'glGetMaterialfv))
  (setf (symbol-function 'glMaterialfv-org)
        (symbol-function 'glMaterialfv))
  ;; #if GL_EXT_texture_object && !Darwin
  (if (not (fboundp 'glGenTexturesEXT))
      (setf (symbol-function 'glGenTexturesEXT)
	    (symbol-function 'glGenTextures)))
  (if (not (fboundp 'glBindTextureEXT))
      (setf (symbol-function 'glBindTextureEXT)
	    (symbol-function 'glBindTexture)))
  ;; #endif  GL_EXT_texture_object && !Darwin
  (if (fboundp 'glGenTexturesEXT)
      (setf (symbol-function 'glGenTexturesEXT-org)
	    (symbol-function 'glGenTexturesEXT)))
  )
#+(or :x86_64 :aarch64)
(defun glMaterialfv (face pname fv)
  (let ((tmp (user::dvector2float-bytestring fv)))
    (glMaterialfv-org face pname tmp)
    ))
#+(or :x86_64 :aarch64)
(defun glGetMaterialfv (face pname fv)
  (let ((tmp (user::dvector2float-bytestring fv)) ret)
    (setq ret (glGetMaterialfv-org face pname tmp))
    (user::float-bytestring2dvector tmp fv)
    ret))
#+(or :x86_64 :aarch64)
(defun glLightfv (light pname fv)
  (let ((tmp (user::dvector2float-bytestring fv)))
    (glLightfv-org light pname tmp)
    ))
#+(or :x86_64 :aarch64)
(if (fboundp 'glGenTexturesEXT-org)
    (setf (symbol-function 'glGenTexturesEXT)
	  #'(lambda (len iv)
	      (let ((tmp (user::lvector2integer-bytestring iv)) ret)
		(setq ret (glGenTexturesEXT-org len tmp))
		(user::integer-bytestring2lvector tmp iv)
		ret))))
#|
(defforeign glAccum GL "glAccum" (:integer :float) :integer)
(defforeign glAlphaFunc GL "glAlphaFunc" (:integer :float) :integer)
(defforeign glBegin GL "glBegin" (:integer) :integer)
(defforeign glBitmap GL "glBitmap" (:integer :integer :float :float :float :float :string) :integer)
(defforeign glBlendFunc GL "glBlendFunc" (:integer :integer) :integer)
(defforeign glCallList GL "glCallList" (:integer) :integer)
(defforeign glCallLists GL "glCallLists" (:integer :integer :string) :integer)
(defforeign glClear GL "glClear" (:integer) :integer)
(defforeign glClearAccum GL "glClearAccum" (:float :float :float :float) :integer)
(defforeign glClearColor GL "glClearColor" (:float :float :float :float) :integer)
(defforeign glClearDepth GL "glClearDepth" (:float) :integer)
(defforeign glClearIndex GL "glClearIndex" (:float) :integer)
(defforeign glClearStencil GL "glClearStencil" (:integer) :integer)
(defforeign glClipPlane GL "glClipPlane" (:integer :string) :integer)
(defforeign glColor3b GL "glColor3b" (:integer :integer :integer) :integer)
(defforeign glColor3bv GL "glColor3bv" (:string) :integer)
(defforeign glColor3d GL "glColor3d" (:float :float :float) :integer)
(defforeign glColor3dv GL "glColor3dv" (:string) :integer)
(defforeign glColor3f GL "glColor3f" (:float :float :float) :integer)
(defforeign glColor3fv GL "glColor3fv" (:string) :integer)
(defforeign glColor3i GL "glColor3i" (:integer :integer :integer) :integer)
(defforeign glColor3iv GL "glColor3iv" (:string) :integer)
(defforeign glColor3s GL "glColor3s" (:integer :integer :integer) :integer)
(defforeign glColor3sv GL "glColor3sv" (:string) :integer)
(defforeign glColor3ub GL "glColor3ub" (:integer :integer :integer) :integer)
(defforeign glColor3ubv GL "glColor3ubv" (:string) :integer)
(defforeign glColor3ui GL "glColor3ui" (:integer :integer :integer) :integer)
(defforeign glColor3uiv GL "glColor3uiv" (:string) :integer)
(defforeign glColor3us GL "glColor3us" (:integer :integer :integer) :integer)
(defforeign glColor3usv GL "glColor3usv" (:string) :integer)
(defforeign glColor4b GL "glColor4b" (:integer :integer :integer :integer) :integer)
(defforeign glColor4bv GL "glColor4bv" (:string) :integer)
(defforeign glColor4d GL "glColor4d" (:float :float :float :float) :integer)
(defforeign glColor4dv GL "glColor4dv" (:string) :integer)
(defforeign glColor4f GL "glColor4f" (:float :float :float :float) :integer)
(defforeign glColor4fv GL "glColor4fv" (:string) :integer)
(defforeign glColor4i GL "glColor4i" (:integer :integer :integer :integer) :integer)
(defforeign glColor4iv GL "glColor4iv" (:string) :integer)
(defforeign glColor4s GL "glColor4s" (:integer :integer :integer) :integer)
(defforeign glColor4sv GL "glColor4sv" (:string) :integer)
(defforeign glColor4ub GL "glColor4ub" (:integer :integer :integer) :integer)
(defforeign glColor4ubv GL "glColor4ubv" (:string) :integer)
(defforeign glColor4ui GL "glColor4ui" (:integer :integer :integer :integer) :integer)
(defforeign glColor4uiv GL "glColor4uiv" (:string) :integer)
(defforeign glColor4us GL "glColor4us" (:integer :integer :integer :integer) :integer)
(defforeign glColor4usv GL "glColor4usv" (:string) :integer)
(defforeign glColorMask GL "glColorMask" (:integer :integer :integer :integer) :integer)
(defforeign glColorMaterial GL "glColorMaterial" (:integer :integer) :integer)
(defforeign glCopyPixels GL "glCopyPixels" (:integer :integer :integer :integer) :integer)
(defforeign glCullFace GL "glCullFace" (:integer) :integer)
(defforeign glDeleteLists GL "glDeleteLists" (:integer :integer) :integer)
(defforeign glDepthFunc GL "glDepthFunc" (:integer) :integer)
(defforeign glDepthMask GL "glDepthMask" (:integer) :integer)
(defforeign glDepthRange GL "glDepthRange" (:float :float) :integer)
(defforeign glDisable GL "glDisable" (:integer) :integer)
(defforeign glDrawBuffer GL "glDrawBuffer" (:integer) :integer)
(defforeign glDrawPixels GL "glDrawPixels" (:integer :integer :integer :integer :string) :integer)
(defforeign glEdgeFlag GL "glEdgeFlag" (:integer) :integer)
(defforeign glEdgeFlagv GL "glEdgeFlagv" (:string) :integer)
(defforeign glEnable GL "glEnable" (:integer) :integer)
(defforeign glEnd GL "glEnd" () :integer)
(defforeign glEndList GL "glEndList" () :integer)
(defforeign glEvalCoord1d GL "glEvalCoord1d" (:float) :integer)
(defforeign glEvalCoord1dv GL "glEvalCoord1dv" (:string) :integer)
(defforeign glEvalCoord1f GL "glEvalCoord1f" (:float) :integer)
(defforeign glEvalCoord1fv GL "glEvalCoord1fv" (:string) :integer)
(defforeign glEvalCoord2d GL "glEvalCoord2d" (:float :float) :integer)
(defforeign glEvalCoord2dv GL "glEvalCoord2dv" (:string) :integer)
(defforeign glEvalCoord2f GL "glEvalCoord2f" (:float :float) :integer)
(defforeign glEvalCoord2fv GL "glEvalCoord2fv" (:string) :integer)
(defforeign glEvalMesh1 GL "glEvalMesh1" (:integer :integer :integer) :integer)
(defforeign glEvalMesh2 GL "glEvalMesh2" (:integer :integer :integer) :integer)
(defforeign glEvalPoint1 GL "glEvalPoint1" (:integer) :integer)
(defforeign glEvalPoint2 GL "glEvalPoint2" (:integer :integer) :integer)
(defforeign glFeedbackBuffer GL "glFeedbackBuffer" (:integer :integer :string) :integer)
(defforeign glFinish GL "glFinish" () :integer)
(defforeign glFlush GL "glFlush" () :integer)
(defforeign glFogf GL "glFogf" (:integer :float) :integer)
(defforeign glFogfv GL "glFogfv" (:integer :string) :integer)
(defforeign glFogi GL "glFogi" (:integer :integer) :integer)
(defforeign glFogiv GL "glFogiv" (:integer :string) :integer)
(defforeign glFrontFace GL "glFrontFace" (:integer) :integer)
(defforeign glFrustum GL "glFrustum" (:float :float :float :float :float :float) :integer)
(defforeign glGenLists GL "glGenLists" (:integer) :integer)
(defforeign glGetBooleanv GL "glGetBooleanv" (:integer :string) :integer)
(defforeign glGetClipPlane GL "glGetClipPlane" (:integer :string) :integer)
(defforeign glGetDoublev GL "glGetDoublev" (:integer :string) :integer)
(defforeign glGetError GL "glGetError" () :integer)
(defforeign glGetFloatv GL "glGetFloatv" (:integer :string) :integer)
(defforeign glGetIntegerv GL "glGetIntegerv" (:integer :string) :integer)
(defforeign glGetLightfv GL "glGetLightfv" (:integer :integer :string) :integer)
(defforeign glGetLightiv GL "glGetLightiv" (:integer :integer :string) :integer)
(defforeign glGetMapdv GL "glGetMapdv" (:integer :integer :string) :integer)
(defforeign glGetMapfv GL "glGetMapfv" (:integer :integer :string) :integer)
(defforeign glGetMapiv GL "glGetMapiv" (:integer :integer :string) :integer)
(defforeign glGetMaterialfv GL "glGetMaterialfv" (:integer :integer :string) :integer)
(defforeign glGetMaterialiv GL "glGetMaterialiv" (:integer :integer :string) :integer)
(defforeign glGetPixelMapfv GL "glGetPixelMapfv" (:integer :integer :string) :integer)
(defforeign glGetPixelMapuiv GL "glGetPixelMapuiv" (:integer :string) :integer)
(defforeign glGetPixelMapusv GL "glGetPixelMapusv" (:integer :string) :integer)
(defforeign glGetPolygonStipple GL "glGetPolygonStipple" (:string) :integer)
(defforeign glGetString GL "glGetString" (:integer) :integer)
(defforeign glGetTexEnvfv GL "glGetTexEnvfv" (:integer :integer :string) :integer)
(defforeign glGetTexEnviv GL "glGetTexEnviv" (:integer :integer :string) :integer)
(defforeign glGetTexGendv GL "glGetTexGendv" (:integer :integer :string) :integer)
(defforeign glGetTexGenfv GL "glGetTexGenfv" (:integer :integer :string) :integer)
(defforeign glGetTexGeniv GL "glGetTexGeniv" (:integer :integer :string) :integer)
(defforeign glGetTexImage GL "glGetTexImage" (:integer :integer :float :integer :string) :integer)
(defforeign glGetTexLevelParameterfv GL "glGetTexLevelParameterfv" (:integer :integer :integer :string) :integer)
(defforeign glGetTexLevelParameteriv GL "glGetTexLevelParameteriv" (:integer :integer :integer :string) :integer)
(defforeign glGetTexParameterfv GL "glGetTexParameterfv" (:integer :integer :string) :integer)
(defforeign glGetTexParameteriv GL "glGetTexParameteriv" (:integer :integer :string) :integer)
(defforeign glHint GL "glHint" (:integer :integer) :integer)
(defforeign glIndexMask GL "glIndexMask" (:integer) :integer)
(defforeign glIndexd GL "glIndexd" (:float) :integer)
(defforeign glIndexdv GL "glIndexdv" (:string) :integer)
(defforeign glIndexf GL "glIndexf" (:float) :integer)
(defforeign glIndexfv GL "glIndexfv" (:string) :integer)
(defforeign glIndexi GL "glIndexi" (:integer) :integer)
(defforeign glIndexiv GL "glIndexiv" (:string) :integer)
(defforeign glIndexs GL "glIndexs" (:integer) :integer)
(defforeign glIndexsv GL "glIndexsv" (:string) :integer)
(defforeign glInitNames GL "glInitNames" () :integer)
(defforeign glIsEnabled GL "glIsEnabled" (:integer) :integer)
(defforeign glIsList GL "glIsList" (:integer) :integer)
(defforeign glLightModelf GL "glLightModelf" (:integer :float) :integer)
(defforeign glLightModelfv GL "glLightModelfv" (:integer :string) :integer)
(defforeign glLightModeli GL "glLightModeli" (:integer :integer) :integer)
(defforeign glLightModeliv GL "glLightModeliv" (:integer :string) :integer)
(defforeign glLightf GL "glLightf" (:integer :integer :float) :integer)
(defforeign glLightfv GL "glLightfv" (:integer :integer :string) :integer)
(defforeign glLighti GL "glLighti" (:integer :integer :integer) :integer)
(defforeign glLightiv GL "glLightiv" (:integer :integer :string) :integer)
(defforeign glLineStipple GL "glLineStipple" (:integer :integer) :integer)
(defforeign glLineWidth GL "glLineWidth" (:float) :integer)
(defforeign glListBase GL "glListBase" (:integer) :integer)
(defforeign glLoadIdentity GL "glLoadIdentity" () :integer)
(defforeign glLoadMatrixd GL "glLoadMatrixd" (:string) :integer)
(defforeign glLoadMatrixf GL "glLoadMatrixf" (:string) :integer)
(defforeign glLoadName GL "glLoadName" (:integer) :integer)
(defforeign glLogicOp GL "glLogicOp" (:integer) :integer)
(defforeign glMap1d GL "glMap1d" (:integer :float :float :integer :integer :string) :integer)
(defforeign glMap1f GL "glMap1f" (:integer :float :float :integer :integer :string) :integer)
(defforeign glMap2d GL "glMap2d" (:integer :float :float :integer :integer :float :float :integer :integer :string) :integer)
(defforeign glMap2f GL "glMap2f" (:integer :float :float :integer :integer :float :float :integer :integer :string) :integer)
(defforeign glMapGrid1d GL "glMapGrid1d" (:integer :float :float) :integer)
(defforeign glMapGrid1f GL "glMapGrid1f" (:integer :float :float) :integer)
(defforeign glMapGrid2d GL "glMapGrid2d" (:integer :float :float :integer :float :float) :integer)
(defforeign glMapGrid2f GL "glMapGrid2f" (:integer :float :float :integer :float :float) :integer)
(defforeign glMaterialf GL "glMaterialf" (:integer :integer :float) :integer)
(defforeign glMaterialfv GL "glMaterialfv" (:integer :integer :string) :integer)
(defforeign glMateriali GL "glMateriali" (:integer :integer :integer) :integer)
(defforeign glMaterialiv GL "glMaterialiv" (:integer :integer :string) :integer)
(defforeign glMatrixMode GL "glMatrixMode" (:integer) :integer)
(defforeign glMultMatrixd GL "glMultMatrixd" (:string) :integer)
(defforeign glMultMatrixf GL "glMultMatrixf" (:string) :integer)
(defforeign glNewList GL "glNewList" (:integer :integer) :integer)
(defforeign glNormal3b GL "glNormal3b" (:integer :integer :integer) :integer)
(defforeign glNormal3bv GL "glNormal3bv" (:string) :integer)
(defforeign glNormal3d GL "glNormal3d" (:float :float :float) :integer)
(defforeign glNormal3dv GL "glNormal3dv" (:string) :integer)
(defforeign glNormal3f GL "glNormal3f" (:float :float :float) :integer)
(defforeign glNormal3fv GL "glNormal3fv" (:string) :integer)
(defforeign glNormal3i GL "glNormal3i" (:integer :integer :integer) :integer)
(defforeign glNormal3iv GL "glNormal3iv" (:string) :integer)
(defforeign glNormal3s GL "glNormal3s" (:integer :integer :integer) :integer)
(defforeign glNormal3sv GL "glNormal3sv" (:string) :integer)
(defforeign glOrtho GL "glOrtho" (:float :float :float :float :float :float) :integer)
(defforeign glPassThrough GL "glPassThrough" (:integer) :integer)
(defforeign glPixelMapfv GL "glPixelMapfv" (:integer :integer :string) :integer)
(defforeign glPixelMapuiv GL "glPixelMapuiv" (:integer :integer :string) :integer)
(defforeign glPixelMapusv GL "glPixelMapusv" (:integer :integer :string) :integer)
(defforeign glPixelStoref GL "glPixelStoref" (:integer :float) :integer)
(defforeign glPixelStorei GL "glPixelStorei" (:integer :integer) :integer)
(defforeign glPixelTransferf GL "glPixelTransferf" (:integer :float) :integer)
(defforeign glPixelTransferi GL "glPixelTransferi" (:integer :integer) :integer)
(defforeign glPixelZoom GL "glPixelZoom" (:float :float) :integer)
(defforeign glPointSize GL "glPointSize" (:float) :integer)
(defforeign glPolygonMode GL "glPolygonMode" (:integer :integer) :integer)
(defforeign glPolygonStipple GL "glPolygonStipple" (:string) :integer)
(defforeign glPopAttrib GL "glPopAttrib" () :integer)
(defforeign glPopMatrix GL "glPopMatrix" () :integer)
(defforeign glPopName GL "glPopName" () :integer)
(defforeign glPushAttrib GL "glPushAttrib" (:integer) :integer)
(defforeign glPushMatrix GL "glPushMatrix" () :integer)
(defforeign glPushName GL "glPushName" (:integer) :integer)
(defforeign glRasterPos2d GL "glRasterPos2d" (:float :float) :integer)
(defforeign glRasterPos2dv GL "glRasterPos2dv" (:string) :integer)
(defforeign glRasterPos2f GL "glRasterPos2f" (:float :float) :integer)
(defforeign glRasterPos2fv GL "glRasterPos2fv" (:string) :integer)
(defforeign glRasterPos2i GL "glRasterPos2i" (:integer :integer) :integer)
(defforeign glRasterPos2iv GL "glRasterPos2iv" (:string) :integer)
(defforeign glRasterPos2s GL "glRasterPos2s" (:integer :integer) :integer)
(defforeign glRasterPos2sv GL "glRasterPos2sv" (:string) :integer)
(defforeign glRasterPos3d GL "glRasterPos3d" (:float :float :float) :integer)
(defforeign glRasterPos3dv GL "glRasterPos3dv" (:string) :integer)
(defforeign glRasterPos3f GL "glRasterPos3f" (:float :float :float) :integer)
(defforeign glRasterPos3fv GL "glRasterPos3fv" (:string) :integer)
(defforeign glRasterPos3i GL "glRasterPos3i" (:integer :integer :integer) :integer)
(defforeign glRasterPos3iv GL "glRasterPos3iv" (:string) :integer)
(defforeign glRasterPos3s GL "glRasterPos3s" (:integer :integer :integer) :integer)
(defforeign glRasterPos3sv GL "glRasterPos3sv" (:string) :integer)
(defforeign glRasterPos4d GL "glRasterPos4d" (:float :float :float :float) :integer)
(defforeign glRasterPos4dv GL "glRasterPos4dv" (:string) :integer)
(defforeign glRasterPos4f GL "glRasterPos4f" (:float :float :float :float) :integer)
(defforeign glRasterPos4fv GL "glRasterPos4fv" (:string) :integer)
(defforeign glRasterPos4i GL "glRasterPos4i" (:integer :integer :integer :integer) :integer)
(defforeign glRasterPos4iv GL "glRasterPos4iv" (:string) :integer)
(defforeign glRasterPos4s GL "glRasterPos4s" (:integer :integer :integer :integer) :integer)
(defforeign glRasterPos4sv GL "glRasterPos4sv" (:string) :integer)
(defforeign glReadBuffer GL "glReadBuffer" (:integer) :integer)
(defforeign glReadPixels GL "glReadPixels" (:integer :integer :integer :integer :integer :integer :string) :integer)
(defforeign glRectd GL "glRectd" (:float :float :float :float) :integer)
(defforeign glRectdv GL "glRectdv" (:string :string) :integer)
(defforeign glRectf GL "glRectf" (:float :float :float :float) :integer)
(defforeign glRectfv GL "glRectfv" (:string :string) :integer)
(defforeign glRecti GL "glRecti" (:integer :integer :integer :integer) :integer)
(defforeign glRectiv GL "glRectiv" (:string :string) :integer)
(defforeign glRects GL "glRects" (:integer :integer :integer :integer) :integer)
(defforeign glRectsv GL "glRectsv" (:string :string) :integer)
(defforeign glRenderMode GL "glRenderMode" (:integer) :integer)
(defforeign glRotated GL "glRotated" (:float :float :float :float) :integer)
(defforeign glRotatef GL "glRotatef" (:float :float :float :float) :integer)
(defforeign glScaled GL "glScaled" (:float :float :float) :integer)
(defforeign glScalef GL "glScalef" (:float :float :float) :integer)
(defforeign glScissor GL "glScissor" (:integer :integer :integer :integer) :integer)
(defforeign glSelectBuffer GL "glSelectBuffer" (:integer :string) :integer)
(defforeign glShadeModel GL "glShadeModel" (:integer) :integer)
(defforeign glStencilFunc GL "glStencilFunc" (:integer :integer :integer) :integer)
(defforeign glStencilMask GL "glStencilMask" (:integer) :integer)
(defforeign glStencilOp GL "glStencilOp" (:integer :integer :integer) :integer)
(defforeign glTexCoord1d GL "glTexCoord1d" (:float) :integer)
(defforeign glTexCoord1dv GL "glTexCoord1dv" (:string) :integer)
(defforeign glTexCoord1f GL "glTexCoord1f" (:float) :integer)
(defforeign glTexCoord1fv GL "glTexCoord1fv" (:string) :integer)
(defforeign glTexCoord1i GL "glTexCoord1i" (:integer) :integer)
(defforeign glTexCoord1iv GL "glTexCoord1iv" (:string) :integer)
(defforeign glTexCoord1s GL "glTexCoord1s" (:integer) :integer)
(defforeign glTexCoord1sv GL "glTexCoord1sv" (:string) :integer)
(defforeign glTexCoord2d GL "glTexCoord2d" (:float :float) :integer)
(defforeign glTexCoord2dv GL "glTexCoord2dv" (:string) :integer)
(defforeign glTexCoord2f GL "glTexCoord2f" (:float :float) :integer)
(defforeign glTexCoord2fv GL "glTexCoord2fv" (:string) :integer)
(defforeign glTexCoord2i GL "glTexCoord2i" (:integer :integer) :integer)
(defforeign glTexCoord2iv GL "glTexCoord2iv" (:string) :integer)
(defforeign glTexCoord2s GL "glTexCoord2s" (:integer :integer) :integer)
(defforeign glTexCoord2sv GL "glTexCoord2sv" (:string) :integer)
(defforeign glTexCoord3d GL "glTexCoord3d" (:float :float :float) :integer)
(defforeign glTexCoord3dv GL "glTexCoord3dv" (:string) :integer)
(defforeign glTexCoord3f GL "glTexCoord3f" (:float :float :float) :integer)
(defforeign glTexCoord3fv GL "glTexCoord3fv" (:string) :integer)
(defforeign glTexCoord3i GL "glTexCoord3i" (:integer :integer :integer) :integer)
(defforeign glTexCoord3iv GL "glTexCoord3iv" (:string) :integer)
(defforeign glTexCoord3s GL "glTexCoord3s" (:integer :integer :integer) :integer)
(defforeign glTexCoord3sv GL "glTexCoord3sv" (:string) :integer)
(defforeign glTexCoord4d GL "glTexCoord4d" (:float :float :float :float) :integer)
(defforeign glTexCoord4dv GL "glTexCoord4dv" (:string) :integer)
(defforeign glTexCoord4f GL "glTexCoord4f" (:float :float :float :float) :integer)
(defforeign glTexCoord4fv GL "glTexCoord4fv" (:string) :integer)
(defforeign glTexCoord4i GL "glTexCoord4i" (:integer :integer :integer :integer) :integer)
(defforeign glTexCoord4iv GL "glTexCoord4iv" (:string) :integer)
(defforeign glTexCoord4s GL "glTexCoord4s" (:integer :integer :integer :integer) :integer)
(defforeign glTexCoord4sv GL "glTexCoord4sv" (:string) :integer)
(defforeign glTexEnvf GL "glTexEnvf" (:integer :integer :float) :integer)
(defforeign glTexEnvfv GL "glTexEnvfv" (:integer :integer :string) :integer)
(defforeign glTexEnvi GL "glTexEnvi" (:integer :integer :integer) :integer)
(defforeign glTexEnviv GL "glTexEnviv" (:integer :integer :string) :integer)
(defforeign glTexGend GL "glTexGend" (:integer :integer :float) :integer)
(defforeign glTexGendv GL "glTexGendv" (:integer :integer :string) :integer)
(defforeign glTexGenf GL "glTexGenf" (:integer :integer :float) :integer)
(defforeign glTexGenfv GL "glTexGenfv" (:integer :integer :string) :integer)
(defforeign glTexGeni GL "glTexGeni" (:integer :integer :integer) :integer)
(defforeign glTexGeniv GL "glTexGeniv" (:integer :integer :string) :integer)
(defforeign glTexImage1D GL "glTexImage1D" (:integer :integer :integer :integer :integer :integer :integer :string) :integer)
(defforeign glTexImage2D GL "glTexImage2D" (:integer :integer :integer :integer :integer :integer :integer :integer :string) :integer)
(defforeign glTexParameterf GL "glTexParameterf" (:integer :integer :float) :integer)
(defforeign glTexParameterfv GL "glTexParameterfv" (:integer :integer :string) :integer)
(defforeign glTexParameteri GL "glTexParameteri" (:integer :integer :integer) :integer)
(defforeign glTexParameteriv GL "glTexParameteriv" (:integer :integer :string) :integer)
(defforeign glTranslated GL "glTranslated" (:float :float :float) :integer)
(defforeign glTranslatef GL "glTranslatef" (:float :float :float) :integer)
(defforeign glVertex2d GL "glVertex2d" (:float :float) :integer)
(defforeign glVertex2dv GL "glVertex2dv" (:string) :integer)
(defforeign glVertex2f GL "glVertex2f" (:float :float) :integer)
(defforeign glVertex2fv GL "glVertex2fv" (:string) :integer)
(defforeign glVertex2i GL "glVertex2i" (:integer :integer) :integer)
(defforeign glVertex2iv GL "glVertex2iv" (:string) :integer)
(defforeign glVertex2s GL "glVertex2s" (:integer :integer) :integer)
(defforeign glVertex2sv GL "glVertex2sv" (:string) :integer)
(defforeign glVertex3d GL "glVertex3d" (:float :float :float) :integer)
(defforeign glVertex3dv GL "glVertex3dv" (:string) :integer)
(defforeign glVertex3f GL "glVertex3f" (:float :float :float) :integer)
(defforeign glVertex3fv GL "glVertex3fv" (:string) :integer)
(defforeign glVertex3i GL "glVertex3i" (:integer :integer :integer) :integer)
(defforeign glVertex3iv GL "glVertex3iv" (:string) :integer)
(defforeign glVertex3s GL "glVertex3s" (:integer :integer :integer) :integer)
(defforeign glVertex3sv GL "glVertex3sv" (:string) :integer)
(defforeign glVertex4d GL "glVertex4d" (:float :float :float :float) :integer)
(defforeign glVertex4dv GL "glVertex4dv" (:string) :integer)
(defforeign glVertex4f GL "glVertex4f" (:float :float :float :float) :integer)
(defforeign glVertex4fv GL "glVertex4fv" (:string) :integer)
(defforeign glVertex4i GL "glVertex4i" (:integer :integer :integer :integer) :integer)
(defforeign glVertex4iv GL "glVertex4iv" (:string) :integer)
(defforeign glVertex4s GL "glVertex4s" (:integer :integer :integer :integer) :integer)
(defforeign glVertex4sv GL "glVertex4sv" (:string) :integer)
(defforeign glViewport GL "glViewport" (:integer :integer :integer :integer) :integer)
|#
