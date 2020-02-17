;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/gluconst.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $
;;; gluconst.l -- constant definitions for GLU

(provide :gluconst)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;;
;;; SGI FREE SOFTWARE LICENSE B (Version 2.0, Sept. 18, 2008)
;;; Copyright (C) 1991-2000 Silicon Graphics, Inc. All Rights Reserved.
;;;
;;; Permission is hereby granted, free of charge, to any person obtaining a
;;; copy of this software and associated documentation files (the "Software"),
;;; to deal in the Software without restriction, including without limitation
;;; the rights to use, copy, modify, merge, publish, distribute, sublicense,
;;; and/or sell copies of the Software, and to permit persons to whom the
;;; Software is furnished to do so, subject to the following conditions:
;;;
;;; The above copyright notice including the dates of first publication and
;;; either this permission notice or a reference to
;;; http://oss.sgi.com/projects/FreeB/
;;; shall be included in all copies or substantial portions of the Software.
;;;
;;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
;;; OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;;; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
;;; SILICON GRAPHICS, INC. BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
;;; WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
;;; OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;;; SOFTWARE.
;;;
;;; Except as contained in this notice, the name of Silicon Graphics, Inc.
;;; shall not be used in advertising or otherwise to promote the sale, use or
;;; other dealings in this Software without prior written authorization from
;;; Silicon Graphics, Inc.
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

;; Extensions
(defconstant GLU_EXT_object_space_tess          1)
(defconstant GLU_EXT_nurbs_tessellator          1)

;; Boolean
(defconstant GLU_FALSE                          0)
(defconstant GLU_TRUE                           1)

;; Version
(defconstant GLU_VERSION_1_1                    1)
(defconstant GLU_VERSION_1_2                    1)
(defconstant GLU_VERSION_1_3                    1)

;; StringName
(defconstant GLU_VERSION                        100800)
(defconstant GLU_EXTENSIONS                     100801)

;; ErrorCode
(defconstant GLU_INVALID_ENUM                   100900)
(defconstant GLU_INVALID_VALUE                  100901)
(defconstant GLU_OUT_OF_MEMORY                  100902)
(defconstant GLU_INCOMPATIBLE_GL_VERSION        100903)
(defconstant GLU_INVALID_OPERATION              100904)

;; NurbsDisplay
;;      GLU_FILL
(defconstant GLU_OUTLINE_POLYGON                100240)
(defconstant GLU_OUTLINE_PATCH                  100241)

;; NurbsCallback
(defconstant GLU_NURBS_ERROR                    100103)
(defconstant GLU_ERROR                          100103)
(defconstant GLU_NURBS_BEGIN                    100164)
(defconstant GLU_NURBS_BEGIN_EXT                100164)
(defconstant GLU_NURBS_VERTEX                   100165)
(defconstant GLU_NURBS_VERTEX_EXT               100165)
(defconstant GLU_NURBS_NORMAL                   100166)
(defconstant GLU_NURBS_NORMAL_EXT               100166)
(defconstant GLU_NURBS_COLOR                    100167)
(defconstant GLU_NURBS_COLOR_EXT                100167)
(defconstant GLU_NURBS_TEXTURE_COORD            100168)
(defconstant GLU_NURBS_TEX_COORD_EXT            100168)
(defconstant GLU_NURBS_END                      100169)
(defconstant GLU_NURBS_END_EXT                  100169)
(defconstant GLU_NURBS_BEGIN_DATA               100170)
(defconstant GLU_NURBS_BEGIN_DATA_EXT           100170)
(defconstant GLU_NURBS_VERTEX_DATA              100171)
(defconstant GLU_NURBS_VERTEX_DATA_EXT          100171)
(defconstant GLU_NURBS_NORMAL_DATA              100172)
(defconstant GLU_NURBS_NORMAL_DATA_EXT          100172)
(defconstant GLU_NURBS_COLOR_DATA               100173)
(defconstant GLU_NURBS_COLOR_DATA_EXT           100173)
(defconstant GLU_NURBS_TEXTURE_COORD_DATA       100174)
(defconstant GLU_NURBS_TEX_COORD_DATA_EXT       100174)
(defconstant GLU_NURBS_END_DATA                 100175)
(defconstant GLU_NURBS_END_DATA_EXT             100175)

;; NurbsError
(defconstant GLU_NURBS_ERROR1                   100251)
(defconstant GLU_NURBS_ERROR2                   100252)
(defconstant GLU_NURBS_ERROR3                   100253)
(defconstant GLU_NURBS_ERROR4                   100254)
(defconstant GLU_NURBS_ERROR5                   100255)
(defconstant GLU_NURBS_ERROR6                   100256)
(defconstant GLU_NURBS_ERROR7                   100257)
(defconstant GLU_NURBS_ERROR8                   100258)
(defconstant GLU_NURBS_ERROR9                   100259)
(defconstant GLU_NURBS_ERROR10                  100260)
(defconstant GLU_NURBS_ERROR11                  100261)
(defconstant GLU_NURBS_ERROR12                  100262)
(defconstant GLU_NURBS_ERROR13                  100263)
(defconstant GLU_NURBS_ERROR14                  100264)
(defconstant GLU_NURBS_ERROR15                  100265)
(defconstant GLU_NURBS_ERROR16                  100266)
(defconstant GLU_NURBS_ERROR17                  100267)
(defconstant GLU_NURBS_ERROR18                  100268)
(defconstant GLU_NURBS_ERROR19                  100269)
(defconstant GLU_NURBS_ERROR20                  100270)
(defconstant GLU_NURBS_ERROR21                  100271)
(defconstant GLU_NURBS_ERROR22                  100272)
(defconstant GLU_NURBS_ERROR23                  100273)
(defconstant GLU_NURBS_ERROR24                  100274)
(defconstant GLU_NURBS_ERROR25                  100275)
(defconstant GLU_NURBS_ERROR26                  100276)
(defconstant GLU_NURBS_ERROR27                  100277)
(defconstant GLU_NURBS_ERROR28                  100278)
(defconstant GLU_NURBS_ERROR29                  100279)
(defconstant GLU_NURBS_ERROR30                  100280)
(defconstant GLU_NURBS_ERROR31                  100281)
(defconstant GLU_NURBS_ERROR32                  100282)
(defconstant GLU_NURBS_ERROR33                  100283)
(defconstant GLU_NURBS_ERROR34                  100284)
(defconstant GLU_NURBS_ERROR35                  100285)
(defconstant GLU_NURBS_ERROR36                  100286)
(defconstant GLU_NURBS_ERROR37                  100287)

;; NurbsProperty
(defconstant GLU_AUTO_LOAD_MATRIX               100200)
(defconstant GLU_CULLING                        100201)
(defconstant GLU_SAMPLING_TOLERANCE             100203)
(defconstant GLU_DISPLAY_MODE                   100204)
(defconstant GLU_PARAMETRIC_TOLERANCE           100202)
(defconstant GLU_SAMPLING_METHOD                100205)
(defconstant GLU_U_STEP                         100206)
(defconstant GLU_V_STEP                         100207)
(defconstant GLU_NURBS_MODE                     100160)
(defconstant GLU_NURBS_MODE_EXT                 100160)
(defconstant GLU_NURBS_TESSELLATOR              100161)
(defconstant GLU_NURBS_TESSELLATOR_EXT          100161)
(defconstant GLU_NURBS_RENDERER                 100162)
(defconstant GLU_NURBS_RENDERER_EXT             100162)

;; NurbsSampling
(defconstant GLU_OBJECT_PARAMETRIC_ERROR        100208)
(defconstant GLU_OBJECT_PARAMETRIC_ERROR_EXT    100208)
(defconstant GLU_OBJECT_PATH_LENGTH             100209)
(defconstant GLU_OBJECT_PATH_LENGTH_EXT         100209)
(defconstant GLU_PATH_LENGTH                    100215)
(defconstant GLU_PARAMETRIC_ERROR               100216)
(defconstant GLU_DOMAIN_DISTANCE                100217)

;; NurbsTrim
(defconstant GLU_MAP1_TRIM_2                    100210)
(defconstant GLU_MAP1_TRIM_3                    100211)

;; QuadricDrawStyle
(defconstant GLU_POINT                          100010)
(defconstant GLU_LINE                           100011)
(defconstant GLU_FILL                           100012)
(defconstant GLU_SILHOUETTE                     100013)

;; QuadricCallback
;;      GLU_ERROR

;; QuadricNormal
(defconstant GLU_SMOOTH                         100000)
(defconstant GLU_FLAT                           100001)
(defconstant GLU_NONE                           100002)

;; QuadricOrientation
(defconstant GLU_OUTSIDE                        100020)
(defconstant GLU_INSIDE                         100021)

;; TessCallback
(defconstant GLU_TESS_BEGIN                     100100)
(defconstant GLU_BEGIN                          100100)
(defconstant GLU_TESS_VERTEX                    100101)
(defconstant GLU_VERTEX                         100101)
(defconstant GLU_TESS_END                       100102)
(defconstant GLU_END                            100102)
(defconstant GLU_TESS_ERROR                     100103)
(defconstant GLU_TESS_EDGE_FLAG                 100104)
(defconstant GLU_EDGE_FLAG                      100104)
(defconstant GLU_TESS_COMBINE                   100105)
(defconstant GLU_TESS_BEGIN_DATA                100106)
(defconstant GLU_TESS_VERTEX_DATA               100107)
(defconstant GLU_TESS_END_DATA                  100108)
(defconstant GLU_TESS_ERROR_DATA                100109)
(defconstant GLU_TESS_EDGE_FLAG_DATA            100110)
(defconstant GLU_TESS_COMBINE_DATA              100111)

;; TessContour
(defconstant GLU_CW                             100120)
(defconstant GLU_CCW                            100121)
(defconstant GLU_INTERIOR                       100122)
(defconstant GLU_EXTERIOR                       100123)
(defconstant GLU_UNKNOWN                        100124)

;; TessProperty
(defconstant GLU_TESS_WINDING_RULE              100140)
(defconstant GLU_TESS_BOUNDARY_ONLY             100141)
(defconstant GLU_TESS_TOLERANCE                 100142)

;; TessError
(defconstant GLU_TESS_ERROR1                    100151)
(defconstant GLU_TESS_ERROR2                    100152)
(defconstant GLU_TESS_ERROR3                    100153)
(defconstant GLU_TESS_ERROR4                    100154)
(defconstant GLU_TESS_ERROR5                    100155)
(defconstant GLU_TESS_ERROR6                    100156)
(defconstant GLU_TESS_ERROR7                    100157)
(defconstant GLU_TESS_ERROR8                    100158)
(defconstant GLU_TESS_MISSING_BEGIN_POLYGON     100151)
(defconstant GLU_TESS_MISSING_BEGIN_CONTOUR     100152)
(defconstant GLU_TESS_MISSING_END_POLYGON       100153)
(defconstant GLU_TESS_MISSING_END_CONTOUR       100154)
(defconstant GLU_TESS_COORD_TOO_LARGE           100155)
(defconstant GLU_TESS_NEED_COMBINE_CALLBACK     100156)

;; TessWinding
(defconstant GLU_TESS_WINDING_ODD               100130)
(defconstant GLU_TESS_WINDING_NONZERO           100131)
(defconstant GLU_TESS_WINDING_POSITIVE          100132)
(defconstant GLU_TESS_WINDING_NEGATIVE          100133)
(defconstant GLU_TESS_WINDING_ABS_GEQ_TWO       100134)
