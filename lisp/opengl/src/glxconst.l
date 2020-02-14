;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/glxconst.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;; glxconst.l

(provide :glxconst)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;;
;;; Mesa 3-D graphics library
;;;
;;; Copyright (C) 1999-2006  Brian Paul   All Rights Reserved.
;;;
;;; Permission is hereby granted, free of charge, to any person obtaining a
;;; copy of this software and associated documentation files (the "Software"),
;;; to deal in the Software without restriction, including without limitation
;;; the rights to use, copy, modify, merge, publish, distribute, sublicense,
;;; and/or sell copies of the Software, and to permit persons to whom the
;;; Software is furnished to do so, subject to the following conditions:
;;;
;;; The above copyright notice and this permission notice shall be included
;;; in all copies or substantial portions of the Software.
;;;
;;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
;;; OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;;; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
;;; THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
;;; OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
;;; ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
;;; OTHER DEALINGS IN THE SOFTWARE.
;;;

(export '(GLX_USE_GL
	  GLX_BUFFER_SIZE
	  GLX_LEVEL
	  GLX_RGBA
	  GLX_DOUBLEBUFFER
	  GLX_STEREO
	  GLX_AUX_BUFFERS
	  GLX_RED_SIZE
	  GLX_GREEN_SIZE
	  GLX_BLUE_SIZE
	  GLX_ALPHA_SIZE
	  GLX_DEPTH_SIZE
	  GLX_STENCIL_SIZE
	  GLX_ACCUM_RED_SIZE
	  GLX_ACCUM_GREEN_SIZE
	  GLX_ACCUM_BLUE_SIZE
	  GLX_ACCUM_ALPHA_SIZE
	  GLX_BAD_SCREEN
	  GLX_BAD_ATTRIBUTE
	  GLX_NO_EXTENSION
	  GLX_BAD_VISUAL
	  GLXBadContext
	  GLXBadContextState
	  GLXBadDrawable
	  GLXBadPixmap
	  GLXBadContextTag
	  GLXBadCurrentWindow
	  GLXBadRenderRequest
	  GLXBadLargeRequest
	  GLXUnsupportedPrivateRequest
	  ))

;;;
;;; Tokens for glXChooseVisual and glXGetConfig:
;;;
(defconstant GLX_USE_GL		1)
(defconstant GLX_BUFFER_SIZE		2)
(defconstant GLX_LEVEL		3)
(defconstant GLX_RGBA		4)
(defconstant GLX_DOUBLEBUFFER	5)
(defconstant GLX_STEREO		6)
(defconstant GLX_AUX_BUFFERS		7)
(defconstant GLX_RED_SIZE		8)
(defconstant GLX_GREEN_SIZE		9)
(defconstant GLX_BLUE_SIZE		10)
(defconstant GLX_ALPHA_SIZE		11)
(defconstant GLX_DEPTH_SIZE		12)
(defconstant GLX_STENCIL_SIZE	13)
(defconstant GLX_ACCUM_RED_SIZE	14)
(defconstant GLX_ACCUM_GREEN_SIZE	15)
(defconstant GLX_ACCUM_BLUE_SIZE	16)
(defconstant GLX_ACCUM_ALPHA_SIZE	17)


;;;
;;; Error codes returned by glXGetConfig:
;;;
(defconstant GLX_BAD_SCREEN		1)
(defconstant GLX_BAD_ATTRIBUTE	2)
(defconstant GLX_NO_EXTENSION	3)
(defconstant GLX_BAD_VISUAL		4)
(defconstant GLX_BAD_CONTEXT		5)
(defconstant GLX_BAD_VALUE       	6)
(defconstant GLX_BAD_ENUM		7)


;;;
;;; GLX 1.1 and later:
;;;
(defconstant GLX_VENDOR		1)
(defconstant GLX_VERSION		2)
(defconstant GLX_EXTENSIONS 		3)


;;;
;;; GLX 1.3 and later:
;;;
(defconstant GLX_CONFIG_CAVEAT		#x20)
(defconstant GLX_DONT_CARE			#xFFFFFFFF)
(defconstant GLX_X_VISUAL_TYPE		#x22)
(defconstant GLX_TRANSPARENT_TYPE		#x23)
(defconstant GLX_TRANSPARENT_INDEX_VALUE	#x24)
(defconstant GLX_TRANSPARENT_RED_VALUE	#x25)
(defconstant GLX_TRANSPARENT_GREEN_VALUE	#x26)
(defconstant GLX_TRANSPARENT_BLUE_VALUE	#x27)
(defconstant GLX_TRANSPARENT_ALPHA_VALUE	#x28)
(defconstant GLX_WINDOW_BIT			#x00000001)
(defconstant GLX_PIXMAP_BIT			#x00000002)
(defconstant GLX_PBUFFER_BIT			#x00000004)
(defconstant GLX_AUX_BUFFERS_BIT		#x00000010)
(defconstant GLX_FRONT_LEFT_BUFFER_BIT	#x00000001)
(defconstant GLX_FRONT_RIGHT_BUFFER_BIT	#x00000002)
(defconstant GLX_BACK_LEFT_BUFFER_BIT	#x00000004)
(defconstant GLX_BACK_RIGHT_BUFFER_BIT	#x00000008)
(defconstant GLX_DEPTH_BUFFER_BIT		#x00000020)
(defconstant GLX_STENCIL_BUFFER_BIT		#x00000040)
(defconstant GLX_ACCUM_BUFFER_BIT		#x00000080)
(defconstant GLX_NONE			#x8000)
(defconstant GLX_SLOW_CONFIG			#x8001)
(defconstant GLX_TRUE_COLOR			#x8002)
(defconstant GLX_DIRECT_COLOR		#x8003)
(defconstant GLX_PSEUDO_COLOR		#x8004)
(defconstant GLX_STATIC_COLOR		#x8005)
(defconstant GLX_GRAY_SCALE			#x8006)
(defconstant GLX_STATIC_GRAY			#x8007)
(defconstant GLX_TRANSPARENT_RGB		#x8008)
(defconstant GLX_TRANSPARENT_INDEX		#x8009)
(defconstant GLX_VISUAL_ID			#x800B)
(defconstant GLX_SCREEN			#x800C)
(defconstant GLX_NON_CONFORMANT_CONFIG	#x800D)
(defconstant GLX_DRAWABLE_TYPE		#x8010)
(defconstant GLX_RENDER_TYPE			#x8011)
(defconstant GLX_X_RENDERABLE		#x8012)
(defconstant GLX_FBCONFIG_ID			#x8013)
(defconstant GLX_RGBA_TYPE			#x8014)
(defconstant GLX_COLOR_INDEX_TYPE		#x8015)
(defconstant GLX_MAX_PBUFFER_WIDTH		#x8016)
(defconstant GLX_MAX_PBUFFER_HEIGHT		#x8017)
(defconstant GLX_MAX_PBUFFER_PIXELS		#x8018)
(defconstant GLX_PRESERVED_CONTENTS		#x801B)
(defconstant GLX_LARGEST_PBUFFER		#x801C)
(defconstant GLX_WIDTH			#x801D)
(defconstant GLX_HEIGHT			#x801E)
(defconstant GLX_EVENT_MASK			#x801F)
(defconstant GLX_DAMAGED			#x8020)
(defconstant GLX_SAVED			#x8021)
(defconstant GLX_WINDOW			#x8022)
(defconstant GLX_PBUFFER			#x8023)
(defconstant GLX_PBUFFER_HEIGHT              #x8040)
(defconstant GLX_PBUFFER_WIDTH               #x8041)
(defconstant GLX_RGBA_BIT			#x00000001)
(defconstant GLX_COLOR_INDEX_BIT		#x00000002)
(defconstant GLX_PBUFFER_CLOBBER_MASK	#x08000000)


;;;
;;; GLX 1.4 and later:
;;;
(defconstant GLX_SAMPLE_BUFFERS              #x186a0) ;; 100000
(defconstant GLX_SAMPLES                     #x186a1) ;; 100001

;;; typedef struct __GLXcontextRec *GLXContext;
;;; typedef XID GLXPixmap;
;;; typedef XID GLXDrawable;
;;; /* GLX 1.3 and later */
;;; typedef struct __GLXFBConfigRec *GLXFBConfig;
;;; typedef XID GLXFBConfigID;
;;; typedef XID GLXContextID;
;;; typedef XID GLXWindow;
;;; typedef XID GLXPbuffer;
