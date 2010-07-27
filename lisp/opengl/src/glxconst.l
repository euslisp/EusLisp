;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/glxconst.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;; glxconst.l

(provide :glxconst)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;; Copyright 1991-1993, Silicon Graphics, Inc.
;;; All Rights Reserved.
;;;
;;; This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
;;; the contents of this file may not be disclosed to third parties, copied or
;;; duplicated in any form, in whole or in part, without the prior written
;;; permission of Silicon Graphics, Inc.
;;;
;;; RESTRICTED RIGHTS LEGEND:
;;; Use, duplication or disclosure by the Government is subject to restrictions
;;; as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
;;; and Computer Software clause at DFARS 252.227-7013, and/or in similar or
;;; successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
;;; rights reserved under the Copyright Laws of the United States.

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
;;; GLX resources.
;;;
;;;typedef XID GLXContextID;
;;;typedef XID GLXPixmap;
;;;typedef XID GLXDrawable;

;;;
;;; GLXContext is a pointer to opaque data
;;;
;;;typedef struct __GLXcontextRec *GLXContext;

;;;
;;; Names for attributes to glXGetConfig.
;;;
(defconstant GLX_USE_GL               1) ; support GLX rendering 
(defconstant GLX_BUFFER_SIZE          2) ; depth of the color buffer 
(defconstant GLX_LEVEL                3) ; level in plane stacking 
(defconstant GLX_RGBA                 4) ; true if RGBA mode 
(defconstant GLX_DOUBLEBUFFER         5) ; double buffering supported 
(defconstant GLX_STEREO               6) ; stereo buffering supported 
(defconstant GLX_AUX_BUFFERS          7) ; number of aux buffers 
(defconstant GLX_RED_SIZE             8) ; number of red component bits 
(defconstant GLX_GREEN_SIZE           9) ; number of green component bits 
(defconstant GLX_BLUE_SIZE            10) ; number of blue component bits 
(defconstant GLX_ALPHA_SIZE           11) ; number of alpha component bits 
(defconstant GLX_DEPTH_SIZE           12) ; number of depth bits 
(defconstant GLX_STENCIL_SIZE         13) ; number of stencil bits 
(defconstant GLX_ACCUM_RED_SIZE       14) ; number of red accum bits 
(defconstant GLX_ACCUM_GREEN_SIZE     15) ; number of green accum bits 
(defconstant GLX_ACCUM_BLUE_SIZE      16) ; number of blue accum bits 
(defconstant GLX_ACCUM_ALPHA_SIZE     17) ; number of alpha accum bits 

;;;
;;; Error return values from glXGetConfig.  Success is indicated by
;;; a value of 0.
;;;
(defconstant GLX_BAD_SCREEN           1) ; screen # is bad 
(defconstant GLX_BAD_ATTRIBUTE        2) ; attribute to get is bad 
(defconstant GLX_NO_EXTENSION         3) ; no glx extension on server 
(defconstant GLX_BAD_VISUAL           4) ; visual # not known by GLX 

;;;
;;; GLX protocol error codes.
;;;
(defconstant GLXBadContext                    0)
(defconstant GLXBadContextState               1)
(defconstant GLXBadDrawable                   2)
(defconstant GLXBadPixmap                     3)
(defconstant GLXBadContextTag                 4)
(defconstant GLXBadCurrentWindow              5)
(defconstant GLXBadRenderRequest              6)
(defconstant GLXBadLargeRequest               7)
(defconstant GLXUnsupportedPrivateRequest     8)

