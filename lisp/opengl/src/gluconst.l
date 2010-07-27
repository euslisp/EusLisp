;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/gluconst.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; gluconst.l -- constant definitions for GLU

(provide :gluconst)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;;
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
;;;

(export '(GLU_INVALID_ENUM
	  GLU_INVALID_VALUE
	  GLU_OUT_OF_MEMORY
	  GLU_TRUE
	  GLU_FALSE
	  GLU_SMOOTH
	  GLU_FLAT
	  GLU_NONE
	  GLU_POINT
	  GLU_LINE
	  GLU_FILL
	  GLU_SILHOUETTE
	  GLU_OUTSIDE
	  GLU_INSIDE
	  GLU_BEGIN
	  GLU_VERTEX
	  GLU_END
	  GLU_ERROR
	  GLU_EDGE_FLAG
	  GLU_CW
	  GLU_CCW
	  GLU_INTERIOR
	  GLU_EXTERIOR
	  GLU_UNKNOWN
	  GLU_TESS_ERROR1
	  GLU_TESS_ERROR2
	  GLU_TESS_ERROR3
	  GLU_TESS_ERROR4
	  GLU_TESS_ERROR5
	  GLU_TESS_ERROR6
	  GLU_TESS_ERROR7
	  GLU_TESS_ERROR8
	  GLU_AUTO_LOAD_MATRIX
	  GLU_CULLING
	  GLU_SAMPLING_TOLERANCE
	  GLU_DISPLAY_MODE
	  GLU_MAP1_TRIM_2
	  GLU_MAP1_TRIM_3
	  GLU_OUTLINE_POLYGON
	  GLU_OUTLINE_PATCH
	  GLU_NURBS_ERROR1
	  GLU_NURBS_ERROR2
	  GLU_NURBS_ERROR3
	  GLU_NURBS_ERROR4
	  GLU_NURBS_ERROR5
	  GLU_NURBS_ERROR6
	  GLU_NURBS_ERROR7
	  GLU_NURBS_ERROR8
	  GLU_NURBS_ERROR9
	  GLU_NURBS_ERROR10
	  GLU_NURBS_ERROR11
	  GLU_NURBS_ERROR12
	  GLU_NURBS_ERROR13
	  GLU_NURBS_ERROR14
	  GLU_NURBS_ERROR15
	  GLU_NURBS_ERROR16
	  GLU_NURBS_ERROR17
	  GLU_NURBS_ERROR18
	  GLU_NURBS_ERROR19
	  GLU_NURBS_ERROR20
	  GLU_NURBS_ERROR21
	  GLU_NURBS_ERROR22
	  GLU_NURBS_ERROR23
	  GLU_NURBS_ERROR24
	  GLU_NURBS_ERROR25
	  GLU_NURBS_ERROR26
	  GLU_NURBS_ERROR27
	  GLU_NURBS_ERROR28
	  GLU_NURBS_ERROR29
	  GLU_NURBS_ERROR30
	  GLU_NURBS_ERROR31
	  GLU_NURBS_ERROR32
	  GLU_NURBS_ERROR33
	  GLU_NURBS_ERROR34
	  GLU_NURBS_ERROR35
	  GLU_NURBS_ERROR36
	  GLU_NURBS_ERROR37
	  ))

;;; Generic constants

;;; Errors: (return value 0 = no error)
(defconstant GLU_INVALID_ENUM         100900)
(defconstant GLU_INVALID_VALUE        100901)
(defconstant GLU_OUT_OF_MEMORY        100902)

;;; For laughs:
(defconstant GLU_TRUE                 GL_TRUE)
(defconstant GLU_FALSE                GL_FALSE)


;;; Quadric constants

;;; Types of normals:
(defconstant GLU_SMOOTH               100000)
(defconstant GLU_FLAT                 100001)
(defconstant GLU_NONE                 100002)

;;; DrawStyle types:
(defconstant GLU_POINT                100010)
(defconstant GLU_LINE                 100011)
(defconstant GLU_FILL                 100012)
(defconstant GLU_SILHOUETTE           100013)

;;; Orientation types:
(defconstant GLU_OUTSIDE              100020)
(defconstant GLU_INSIDE               100021)

;;; Callback types:
;;;      GLU_ERROR              100103


;;; Tesselation constants

;;; Callback types:
(defconstant GLU_BEGIN                100100)  ; void (*)(GLenum)
(defconstant GLU_VERTEX               100101)  ; void (*)(void *)
(defconstant GLU_END                  100102)  ; void (*)(void)
(defconstant GLU_ERROR                100103)  ; void (*)(GLint)
(defconstant GLU_EDGE_FLAG            100104)  ; void (*)(GLboolean)

;;; Contours types:
(defconstant GLU_CW                   100120)
(defconstant GLU_CCW                  100121)
(defconstant GLU_INTERIOR             100122)
(defconstant GLU_EXTERIOR             100123)
(defconstant GLU_UNKNOWN              100124)

(defconstant GLU_TESS_ERROR1          100151)
(defconstant GLU_TESS_ERROR2          100152)
(defconstant GLU_TESS_ERROR3          100153)
(defconstant GLU_TESS_ERROR4          100154)
(defconstant GLU_TESS_ERROR5          100155)
(defconstant GLU_TESS_ERROR6          100156)
(defconstant GLU_TESS_ERROR7          100157)
(defconstant GLU_TESS_ERROR8          100158)


;;; NURBS constants

;;; Properties:
(defconstant GLU_AUTO_LOAD_MATRIX     100200)
(defconstant GLU_CULLING              100201)
(defconstant GLU_SAMPLING_TOLERANCE   100203)
(defconstant GLU_DISPLAY_MODE         100204)

;;; Trimming curve types
(defconstant GLU_MAP1_TRIM_2          100210)
(defconstant GLU_MAP1_TRIM_3          100211)

;;; Display modes:
;;;      GLU_FILL               100012
(defconstant GLU_OUTLINE_POLYGON      100240)
(defconstant GLU_OUTLINE_PATCH        100241)

;;; Callbacks:
;;;      GLU_ERROR              100103

;;; Errors:
(defconstant GLU_NURBS_ERROR1         100251)
(defconstant GLU_NURBS_ERROR2         100252)
(defconstant GLU_NURBS_ERROR3         100253)
(defconstant GLU_NURBS_ERROR4         100254)
(defconstant GLU_NURBS_ERROR5         100255)
(defconstant GLU_NURBS_ERROR6         100256)
(defconstant GLU_NURBS_ERROR7         100257)
(defconstant GLU_NURBS_ERROR8         100258)
(defconstant GLU_NURBS_ERROR9         100259)
(defconstant GLU_NURBS_ERROR10        100260)
(defconstant GLU_NURBS_ERROR11        100261)
(defconstant GLU_NURBS_ERROR12        100262)
(defconstant GLU_NURBS_ERROR13        100263)
(defconstant GLU_NURBS_ERROR14        100264)
(defconstant GLU_NURBS_ERROR15        100265)
(defconstant GLU_NURBS_ERROR16        100266)
(defconstant GLU_NURBS_ERROR17        100267)
(defconstant GLU_NURBS_ERROR18        100268)
(defconstant GLU_NURBS_ERROR19        100269)
(defconstant GLU_NURBS_ERROR20        100270)
(defconstant GLU_NURBS_ERROR21        100271)
(defconstant GLU_NURBS_ERROR22        100272)
(defconstant GLU_NURBS_ERROR23        100273)
(defconstant GLU_NURBS_ERROR24        100274)
(defconstant GLU_NURBS_ERROR25        100275)
(defconstant GLU_NURBS_ERROR26        100276)
(defconstant GLU_NURBS_ERROR27        100277)
(defconstant GLU_NURBS_ERROR28        100278)
(defconstant GLU_NURBS_ERROR29        100279)
(defconstant GLU_NURBS_ERROR30        100280)
(defconstant GLU_NURBS_ERROR31        100281)
(defconstant GLU_NURBS_ERROR32        100282)
(defconstant GLU_NURBS_ERROR33        100283)
(defconstant GLU_NURBS_ERROR34        100284)
(defconstant GLU_NURBS_ERROR35        100285)
(defconstant GLU_NURBS_ERROR36        100286)
(defconstant GLU_NURBS_ERROR37        100287)

