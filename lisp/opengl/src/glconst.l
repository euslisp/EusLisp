;;; -*- lisp -*-
;;; $Header$
;;; glconst.l -- constant definitions (derived from /usr/include/GL/gl.h)

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

;;; typedef unsigned int GLenum;
;;; typedef unsigned char GLboolean;
;;; typedef unsigned int GLbitfield;
;;; typedef signed char GLbyte;
;;; typedef short GLshort;
;;; typedef int GLint;
;;; typedef int GLsizei;
;;; typedef unsigned char GLubyte;
;;; typedef unsigned short GLushort;
;;; typedef unsigned int GLuint;
;;; typedef float GLfloat;
;;; typedef float GLclampf;
;;; typedef double GLdouble;
;;; typedef double GLclampd;
;;; typedef void GLvoid;

(export '(GL_ACCUM
	  GL_LOAD
	  GL_RETURN
	  GL_MULT
	  GL_ADD
	  GL_NEVER
	  GL_LESS
	  GL_EQUAL
	  GL_LEQUAL
	  GL_GREATER
	  GL_NOTEQUAL
	  GL_GEQUAL
	  GL_ALWAYS
	  GL_CURRENT_BIT
	  GL_POINT_BIT
	  GL_LINE_BIT
	  GL_POLYGON_BIT
	  GL_POLYGON_STIPPLE_BIT
	  GL_PIXEL_MODE_BIT
	  GL_LIGHTING_BIT
	  GL_FOG_BIT
	  GL_DEPTH_BUFFER_BIT
	  GL_ACCUM_BUFFER_BIT
	  GL_STENCIL_BUFFER_BIT
	  GL_VIEWPORT_BIT
	  GL_TRANSFORM_BIT
	  GL_ENABLE_BIT
	  GL_COLOR_BUFFER_BIT
	  GL_HINT_BIT
	  GL_EVAL_BIT
	  GL_LIST_BIT
	  GL_TEXTURE_BIT
	  GL_SCISSOR_BIT
	  GL_ALL_ATTRIB_BITS
	  GL_POINTS
	  GL_LINES
	  GL_LINE_LOOP
	  GL_LINE_STRIP
	  GL_TRIANGLES
	  GL_TRIANGLE_STRIP
	  GL_TRIANGLE_FAN
	  GL_QUADS
	  GL_QUAD_STRIP
	  GL_POLYGON
	  GL_ZERO
	  GL_ONE
	  GL_SRC_COLOR
	  GL_ONE_MINUS_SRC_COLOR
	  GL_SRC_ALPHA
	  GL_ONE_MINUS_SRC_ALPHA
	  GL_DST_ALPHA
	  GL_ONE_MINUS_DST_ALPHA
	  GL_DST_COLOR
	  GL_ONE_MINUS_DST_COLOR
	  GL_SRC_ALPHA_SATURATE
	  GL_TRUE
	  GL_FALSE
	  GL_CLIP_PLANE0
	  GL_CLIP_PLANE1
	  GL_CLIP_PLANE2
	  GL_CLIP_PLANE3
	  GL_CLIP_PLANE4
	  GL_CLIP_PLANE5
	  GL_NONE
	  GL_FRONT_LEFT
	  GL_FRONT_RIGHT
	  GL_BACK_LEFT
	  GL_BACK_RIGHT
	  GL_FRONT
	  GL_BACK
	  GL_LEFT
	  GL_RIGHT
	  GL_FRONT_AND_BACK
	  GL_AUX0
	  GL_AUX1
	  GL_AUX2
	  GL_AUX3
	  GL_NO_ERROR
	  GL_INVALID_ENUM
	  GL_INVALID_VALUE
	  GL_INVALID_OPERATION
	  GL_STACK_OVERFLOW
	  GL_STACK_UNDERFLOW
	  GL_OUT_OF_MEMORY
	  GL_2D
	  GL_3D
	  GL_3D_COLOR
	  GL_3D_COLOR_TEXTURE
	  GL_4D_COLOR_TEXTURE
	  GL_PASS_THROUGH_TOKEN
	  GL_POINT_TOKEN
	  GL_LINE_TOKEN
	  GL_POLYGON_TOKEN
	  GL_BITMAP_TOKEN
	  GL_DRAW_PIXEL_TOKEN
	  GL_COPY_PIXEL_TOKEN
	  GL_LINE_RESET_TOKEN
	  GL_EXP
	  GL_EXP2
	  GL_CW
	  GL_CCW
	  GL_COEFF
	  GL_ORDER
	  GL_DOMAIN
	  GL_CURRENT_COLOR
	  GL_CURRENT_INDEX
	  GL_CURRENT_NORMAL
	  GL_CURRENT_TEXTURE_COORDS
	  GL_CURRENT_RASTER_COLOR
	  GL_CURRENT_RASTER_INDEX
	  GL_CURRENT_RASTER_TEXTURE_COORDS
	  GL_CURRENT_RASTER_POSITION
	  GL_CURRENT_RASTER_POSITION_VALID
	  GL_CURRENT_RASTER_DISTANCE
	  GL_POINT_SMOOTH
	  GL_POINT_SIZE
	  GL_POINT_SIZE_RANGE
	  GL_POINT_SIZE_GRANULARITY
	  GL_LINE_SMOOTH
	  GL_LINE_WIDTH
	  GL_LINE_WIDTH_RANGE
	  GL_LINE_WIDTH_GRANULARITY
	  GL_LINE_STIPPLE
	  GL_LINE_STIPPLE_PATTERN
	  GL_LINE_STIPPLE_REPEAT
	  GL_LIST_MODE
	  GL_MAX_LIST_NESTING
	  GL_LIST_BASE
	  GL_LIST_INDEX
	  GL_POLYGON_MODE
	  GL_POLYGON_SMOOTH
	  GL_POLYGON_STIPPLE
	  GL_EDGE_FLAG
	  GL_CULL_FACE
	  GL_CULL_FACE_MODE
	  GL_FRONT_FACE
	  GL_LIGHTING
	  GL_LIGHT_MODEL_LOCAL_VIEWER
	  GL_LIGHT_MODEL_TWO_SIDE
	  GL_LIGHT_MODEL_AMBIENT
	  GL_SHADE_MODEL
	  GL_COLOR_MATERIAL_FACE
	  GL_COLOR_MATERIAL_PARAMETER
	  GL_COLOR_MATERIAL
	  GL_FOG
	  GL_FOG_INDEX
	  GL_FOG_DENSITY
	  GL_FOG_START
	  GL_FOG_END
	  GL_FOG_MODE
	  GL_FOG_COLOR
	  GL_DEPTH_RANGE
	  GL_DEPTH_TEST
	  GL_DEPTH_WRITEMASK
	  GL_DEPTH_CLEAR_VALUE
	  GL_DEPTH_FUNC
	  GL_ACCUM_CLEAR_VALUE
	  GL_STENCIL_TEST
	  GL_STENCIL_CLEAR_VALUE
	  GL_STENCIL_FUNC
	  GL_STENCIL_VALUE_MASK
	  GL_STENCIL_FAIL
	  GL_STENCIL_PASS_DEPTH_FAIL
	  GL_STENCIL_PASS_DEPTH_PASS
	  GL_STENCIL_REF
	  GL_STENCIL_WRITEMASK
	  GL_MATRIX_MODE
	  GL_NORMALIZE
	  GL_VIEWPORT
	  GL_MODELVIEW_STACK_DEPTH
	  GL_PROJECTION_STACK_DEPTH
	  GL_TEXTURE_STACK_DEPTH
	  GL_MODELVIEW_MATRIX
	  GL_PROJECTION_MATRIX
	  GL_TEXTURE_MATRIX
	  GL_ATTRIB_STACK_DEPTH
	  GL_ALPHA_TEST
	  GL_ALPHA_TEST_FUNC
	  GL_ALPHA_TEST_REF
	  GL_DITHER
	  GL_BLEND_DST
	  GL_BLEND_SRC
	  GL_BLEND
	  GL_LOGIC_OP_MODE
	  GL_LOGIC_OP
	  GL_AUX_BUFFERS
	  GL_DRAW_BUFFER
	  GL_READ_BUFFER
	  GL_SCISSOR_BOX
	  GL_SCISSOR_TEST
	  GL_INDEX_CLEAR_VALUE
	  GL_INDEX_WRITEMASK
	  GL_COLOR_CLEAR_VALUE
	  GL_COLOR_WRITEMASK
	  GL_INDEX_MODE
	  GL_RGBA_MODE
	  GL_DOUBLEBUFFER
	  GL_STEREO
	  GL_RENDER_MODE
	  GL_PERSPECTIVE_CORRECTION_HINT
	  GL_POINT_SMOOTH_HINT
	  GL_LINE_SMOOTH_HINT
	  GL_POLYGON_SMOOTH_HINT
	  GL_FOG_HINT
	  GL_TEXTURE_GEN_S
	  GL_TEXTURE_GEN_T
	  GL_TEXTURE_GEN_R
	  GL_TEXTURE_GEN_Q
	  GL_PIXEL_MAP_I_TO_I
	  GL_PIXEL_MAP_S_TO_S
	  GL_PIXEL_MAP_I_TO_R
	  GL_PIXEL_MAP_I_TO_G
	  GL_PIXEL_MAP_I_TO_B
	  GL_PIXEL_MAP_I_TO_A
	  GL_PIXEL_MAP_R_TO_R
	  GL_PIXEL_MAP_G_TO_G
	  GL_PIXEL_MAP_B_TO_B
	  GL_PIXEL_MAP_A_TO_A
	  GL_PIXEL_MAP_I_TO_I_SIZE
	  GL_PIXEL_MAP_S_TO_S_SIZE
	  GL_PIXEL_MAP_I_TO_R_SIZE
	  GL_PIXEL_MAP_I_TO_G_SIZE
	  GL_PIXEL_MAP_I_TO_B_SIZE
	  GL_PIXEL_MAP_I_TO_A_SIZE
	  GL_PIXEL_MAP_R_TO_R_SIZE
	  GL_PIXEL_MAP_G_TO_G_SIZE
	  GL_PIXEL_MAP_B_TO_B_SIZE
	  GL_PIXEL_MAP_A_TO_A_SIZE
	  GL_UNPACK_SWAP_BYTES
	  GL_UNPACK_LSB_FIRST
	  GL_UNPACK_ROW_LENGTH
	  GL_UNPACK_SKIP_ROWS
	  GL_UNPACK_SKIP_PIXELS
	  GL_UNPACK_ALIGNMENT
	  GL_PACK_SWAP_BYTES
	  GL_PACK_LSB_FIRST
	  GL_PACK_ROW_LENGTH
	  GL_PACK_SKIP_ROWS
	  GL_PACK_SKIP_PIXELS
	  GL_PACK_ALIGNMENT
	  GL_MAP_COLOR
	  GL_MAP_STENCIL
	  GL_INDEX_SHIFT
	  GL_INDEX_OFFSET
	  GL_RED_SCALE
	  GL_RED_BIAS
	  GL_ZOOM_X
	  GL_ZOOM_Y
	  GL_GREEN_SCALE
	  GL_GREEN_BIAS
	  GL_BLUE_SCALE
	  GL_BLUE_BIAS
	  GL_ALPHA_SCALE
	  GL_ALPHA_BIAS
	  GL_DEPTH_SCALE
	  GL_DEPTH_BIAS
	  GL_MAX_EVAL_ORDER
	  GL_MAX_LIGHTS
	  GL_MAX_CLIP_PLANES
	  GL_MAX_TEXTURE_SIZE
	  GL_MAX_PIXEL_MAP_TABLE
	  GL_MAX_ATTRIB_STACK_DEPTH
	  GL_MAX_MODELVIEW_STACK_DEPTH
	  GL_MAX_NAME_STACK_DEPTH
	  GL_MAX_PROJECTION_STACK_DEPTH
	  GL_MAX_TEXTURE_STACK_DEPTH
	  GL_MAX_VIEWPORT_DIMS
	  GL_SUBPIXEL_BITS
	  GL_INDEX_BITS
	  GL_RED_BITS
	  GL_GREEN_BITS
	  GL_BLUE_BITS
	  GL_ALPHA_BITS
	  GL_DEPTH_BITS
	  GL_STENCIL_BITS
	  GL_ACCUM_RED_BITS
	  GL_ACCUM_GREEN_BITS
	  GL_ACCUM_BLUE_BITS
	  GL_ACCUM_ALPHA_BITS
	  GL_NAME_STACK_DEPTH
	  GL_AUTO_NORMAL
	  GL_MAP1_COLOR_4
	  GL_MAP1_INDEX
	  GL_MAP1_NORMAL
	  GL_MAP1_TEXTURE_COORD_1
	  GL_MAP1_TEXTURE_COORD_2
	  GL_MAP1_TEXTURE_COORD_3
	  GL_MAP1_TEXTURE_COORD_4
	  GL_MAP1_VERTEX_3
	  GL_MAP1_VERTEX_4
	  GL_MAP2_COLOR_4
	  GL_MAP2_INDEX
	  GL_MAP2_NORMAL
	  GL_MAP2_TEXTURE_COORD_1
	  GL_MAP2_TEXTURE_COORD_2
	  GL_MAP2_TEXTURE_COORD_3
	  GL_MAP2_TEXTURE_COORD_4
	  GL_MAP2_VERTEX_3
	  GL_MAP2_VERTEX_4
	  GL_MAP1_GRID_DOMAIN
	  GL_MAP1_GRID_SEGMENTS
	  GL_MAP2_GRID_DOMAIN
	  GL_MAP2_GRID_SEGMENTS
	  GL_TEXTURE_1D
	  GL_TEXTURE_2D
	  GL_TEXTURE_WIDTH
	  GL_TEXTURE_HEIGHT
	  GL_TEXTURE_COMPONENTS
	  GL_TEXTURE_BORDER_COLOR
	  GL_TEXTURE_BORDER
	  GL_DONT_CARE
	  GL_FASTEST
	  GL_NICEST
	  GL_LIGHT0
	  GL_LIGHT1
	  GL_LIGHT2
	  GL_LIGHT3
	  GL_LIGHT4
	  GL_LIGHT5
	  GL_LIGHT6
	  GL_LIGHT7
	  GL_AMBIENT
	  GL_DIFFUSE
	  GL_SPECULAR
	  GL_POSITION
	  GL_SPOT_DIRECTION
	  GL_SPOT_EXPONENT
	  GL_SPOT_CUTOFF
	  GL_CONSTANT_ATTENUATION
	  GL_LINEAR_ATTENUATION
	  GL_QUADRATIC_ATTENUATION
	  GL_COMPILE
	  GL_COMPILE_AND_EXECUTE
	  GL_BYTE
	  GL_UNSIGNED_BYTE
	  GL_SHORT
	  GL_UNSIGNED_SHORT
	  GL_INT
	  GL_UNSIGNED_INT
	  GL_FLOAT
	  GL_2_BYTES
	  GL_3_BYTES
	  GL_4_BYTES
	  GL_CLEAR
	  GL_AND
	  GL_AND_REVERSE
	  GL_COPY
	  GL_AND_INVERTED
	  GL_NOOP
	  GL_XOR
	  GL_OR
	  GL_NOR
	  GL_EQUIV
	  GL_INVERT
	  GL_OR_REVERSE
	  GL_COPY_INVERTED
	  GL_OR_INVERTED
	  GL_NAND
	  GL_SET
	  GL_EMISSION
	  GL_SHININESS
	  GL_AMBIENT_AND_DIFFUSE
	  GL_COLOR_INDEXES
	  GL_MODELVIEW
	  GL_PROJECTION
	  GL_TEXTURE
	  GL_COLOR
	  GL_DEPTH
	  GL_STENCIL
	  GL_COLOR_INDEX
	  GL_STENCIL_INDEX
	  GL_DEPTH_COMPONENT
	  GL_RED
	  GL_GREEN
	  GL_BLUE
	  GL_ALPHA
	  GL_RGB
	  GL_RGBA
	  GL_LUMINANCE
	  GL_LUMINANCE_ALPHA
	  GL_BITMAP
	  GL_POINT
	  GL_LINE
	  GL_FILL
	  GL_RENDER
	  GL_FEEDBACK
	  GL_SELECT
	  GL_FLAT
	  GL_SMOOTH
	  GL_KEEP
	  GL_REPLACE
	  GL_INCR
	  GL_DECR
	  GL_VENDOR
	  GL_RENDERER
	  GL_VERSION
	  GL_EXTENSIONS
	  GL_S
	  GL_T
	  GL_R
	  GL_Q
	  GL_MODULATE
	  GL_DECAL
	  GL_TEXTURE_ENV_MODE
	  GL_TEXTURE_ENV_COLOR
	  GL_TEXTURE_ENV
	  GL_EYE_LINEAR
	  GL_OBJECT_LINEAR
	  GL_SPHERE_MAP
	  GL_TEXTURE_GEN_MODE
	  GL_OBJECT_PLANE
	  GL_EYE_PLANE
	  GL_NEAREST
	  GL_LINEAR
	  GL_NEAREST_MIPMAP_NEAREST
	  GL_LINEAR_MIPMAP_NEAREST
	  GL_NEAREST_MIPMAP_LINEAR
	  GL_LINEAR_MIPMAP_LINEAR
	  GL_TEXTURE_MAG_FILTER
	  GL_TEXTURE_MIN_FILTER
	  GL_TEXTURE_WRAP_S
	  GL_TEXTURE_WRAP_T
	  GL_CLAMP
	  GL_REPEAT
	  GL_COLOR_ATTACHMENT0
	  GL_COLOR_ATTACHMENT1
	  GL_COLOR_ATTACHMENT2
	  GL_COLOR_ATTACHMENT3
	  GL_COLOR_ATTACHMENT4
	  GL_COLOR_ATTACHMENT5
	  GL_COLOR_ATTACHMENT6
	  GL_COLOR_ATTACHMENT7
	  GL_COLOR_ATTACHMENT8
	  GL_COLOR_ATTACHMENT9
	  GL_COLOR_ATTACHMENT10
	  GL_COLOR_ATTACHMENT11
	  GL_COLOR_ATTACHMENT12
	  GL_COLOR_ATTACHMENT13
	  GL_COLOR_ATTACHMENT14
	  GL_COLOR_ATTACHMENT15
	  GL_COLOR_ATTACHMENT16
	  GL_COLOR_ATTACHMENT17
	  GL_COLOR_ATTACHMENT18
	  GL_COLOR_ATTACHMENT19
	  GL_COLOR_ATTACHMENT20
	  GL_COLOR_ATTACHMENT21
	  GL_COLOR_ATTACHMENT22
	  GL_COLOR_ATTACHMENT23
	  GL_COLOR_ATTACHMENT24
	  GL_COLOR_ATTACHMENT25
	  GL_COLOR_ATTACHMENT26
	  GL_COLOR_ATTACHMENT27
	  GL_COLOR_ATTACHMENT28
	  GL_COLOR_ATTACHMENT29
	  GL_COLOR_ATTACHMENT30
	  GL_COLOR_ATTACHMENT31
	  GL_DEPTH_ATTACHMENT
	  GL_STENCIL_ATTACHMENT
	  ))

;;; ***********************************************************

;;;  AccumOp 
(defconstant GL_ACCUM                             #x0100)
(defconstant GL_LOAD                              #x0101)
(defconstant GL_RETURN                            #x0102)
(defconstant GL_MULT                              #x0103)
(defconstant GL_ADD                               #x0104)

;;;  AlphaFunction 
(defconstant GL_NEVER                             #x0200)
(defconstant GL_LESS                              #x0201)
(defconstant GL_EQUAL                             #x0202)
(defconstant GL_LEQUAL                            #x0203)
(defconstant GL_GREATER                           #x0204)
(defconstant GL_NOTEQUAL                          #x0205)
(defconstant GL_GEQUAL                            #x0206)
(defconstant GL_ALWAYS                            #x0207)

;;;  AttribMask 
(defconstant GL_CURRENT_BIT                       #x00000001)
(defconstant GL_POINT_BIT                         #x00000002)
(defconstant GL_LINE_BIT                          #x00000004)
(defconstant GL_POLYGON_BIT                       #x00000008)
(defconstant GL_POLYGON_STIPPLE_BIT               #x00000010)
(defconstant GL_PIXEL_MODE_BIT                    #x00000020)
(defconstant GL_LIGHTING_BIT                      #x00000040)
(defconstant GL_FOG_BIT                           #x00000080)
(defconstant GL_DEPTH_BUFFER_BIT                  #x00000100)
(defconstant GL_ACCUM_BUFFER_BIT                  #x00000200)
(defconstant GL_STENCIL_BUFFER_BIT                #x00000400)
(defconstant GL_VIEWPORT_BIT                      #x00000800)
(defconstant GL_TRANSFORM_BIT                     #x00001000)
(defconstant GL_ENABLE_BIT                        #x00002000)
(defconstant GL_COLOR_BUFFER_BIT                  #x00004000)
(defconstant GL_HINT_BIT                          #x00008000)
(defconstant GL_EVAL_BIT                          #x00010000)
(defconstant GL_LIST_BIT                          #x00020000)
(defconstant GL_TEXTURE_BIT                       #x00040000)
(defconstant GL_SCISSOR_BIT                       #x00080000)
(defconstant GL_ALL_ATTRIB_BITS                   #x000fffff)

;;;  BeginMode 
(defconstant GL_POINTS                            #x0000)
(defconstant GL_LINES                             #x0001)
(defconstant GL_LINE_LOOP                         #x0002)
(defconstant GL_LINE_STRIP                        #x0003)
(defconstant GL_TRIANGLES                         #x0004)
(defconstant GL_TRIANGLE_STRIP                    #x0005)
(defconstant GL_TRIANGLE_FAN                      #x0006)
(defconstant GL_QUADS                             #x0007)
(defconstant GL_QUAD_STRIP                        #x0008)
(defconstant GL_POLYGON                           #x0009)

;;;  BlendingFactorDest 
(defconstant GL_ZERO                              0)
(defconstant GL_ONE                               1)
(defconstant GL_SRC_COLOR                         #x0300)
(defconstant GL_ONE_MINUS_SRC_COLOR               #x0301)
(defconstant GL_SRC_ALPHA                         #x0302)
(defconstant GL_ONE_MINUS_SRC_ALPHA               #x0303)
(defconstant GL_DST_ALPHA                         #x0304)
(defconstant GL_ONE_MINUS_DST_ALPHA               #x0305)

;;;  BlendingFactorSrc 
;;;       GL_ZERO 
;;;       GL_ONE 
(defconstant GL_DST_COLOR                         #x0306)
(defconstant GL_ONE_MINUS_DST_COLOR               #x0307)
(defconstant GL_SRC_ALPHA_SATURATE                #x0308)
;;;       GL_SRC_ALPHA 
;;;       GL_ONE_MINUS_SRC_ALPHA 
;;;       GL_DST_ALPHA 
;;;       GL_ONE_MINUS_DST_ALPHA 

;;;  Boolean 
(defconstant GL_TRUE                              1)
(defconstant GL_FALSE                             0)

;;;  ClearBufferMask 
;;;       GL_COLOR_BUFFER_BIT 
;;;       GL_ACCUM_BUFFER_BIT 
;;;       GL_STENCIL_BUFFER_BIT 
;;;       GL_DEPTH_BUFFER_BIT 

;;;  ClipPlaneName 
(defconstant GL_CLIP_PLANE0                       #x3000)
(defconstant GL_CLIP_PLANE1                       #x3001)
(defconstant GL_CLIP_PLANE2                       #x3002)
(defconstant GL_CLIP_PLANE3                       #x3003)
(defconstant GL_CLIP_PLANE4                       #x3004)
(defconstant GL_CLIP_PLANE5                       #x3005)

;;;  ColorMaterialFace 
;;;       GL_FRONT 
;;;       GL_BACK 
;;;       GL_FRONT_AND_BACK 

;;;  ColorMaterialParameter 
;;;       GL_AMBIENT 
;;;       GL_DIFFUSE 
;;;       GL_SPECULAR 
;;;       GL_EMISSION 
;;;       GL_AMBIENT_AND_DIFFUSE 

;;;  CullFaceMode 
;;;       GL_FRONT 
;;;       GL_BACK 
;;;       GL_FRONT_AND_BACK 

;;;  DepthFunction 
;;;       GL_NEVER 
;;;       GL_LESS 
;;;       GL_EQUAL 
;;;       GL_LEQUAL 
;;;       GL_GREATER 
;;;       GL_NOTEQUAL 
;;;       GL_GEQUAL 
;;;       GL_ALWAYS 

;;;  DrawBufferMode 
(defconstant GL_NONE                              0)
(defconstant GL_FRONT_LEFT                        #x0400)
(defconstant GL_FRONT_RIGHT                       #x0401)
(defconstant GL_BACK_LEFT                         #x0402)
(defconstant GL_BACK_RIGHT                        #x0403)
(defconstant GL_FRONT                             #x0404)
(defconstant GL_BACK                              #x0405)
(defconstant GL_LEFT                              #x0406)
(defconstant GL_RIGHT                             #x0407)
(defconstant GL_FRONT_AND_BACK                    #x0408)
(defconstant GL_AUX0                              #x0409)
(defconstant GL_AUX1                              #x040A)
(defconstant GL_AUX2                              #x040B)
(defconstant GL_AUX3                              #x040C)

;;;  Enable 
;;;       GL_FOG 
;;;       GL_LIGHTING 
;;;       GL_TEXTURE_1D 
;;;       GL_TEXTURE_2D 
;;;       GL_LINE_STIPPLE 
;;;       GL_POLYGON_STIPPLE 
;;;       GL_CULL_FACE 
;;;       GL_ALPHA_TEST 
;;;       GL_BLEND 
;;;       GL_LOGIC_OP 
;;;       GL_DITHER 
;;;       GL_STENCIL_TEST 
;;;       GL_DEPTH_TEST 
;;;       GL_CLIP_PLANE0 
;;;       GL_CLIP_PLANE1 
;;;       GL_CLIP_PLANE2 
;;;       GL_CLIP_PLANE3 
;;;       GL_CLIP_PLANE4 
;;;       GL_CLIP_PLANE5 
;;;       GL_LIGHT0 
;;;       GL_LIGHT1 
;;;       GL_LIGHT2 
;;;       GL_LIGHT3 
;;;       GL_LIGHT4 
;;;       GL_LIGHT5 
;;;       GL_LIGHT6 
;;;       GL_LIGHT7 
;;;       GL_TEXTURE_GEN_S 
;;;       GL_TEXTURE_GEN_T 
;;;       GL_TEXTURE_GEN_R 
;;;       GL_TEXTURE_GEN_Q 
;;;       GL_MAP1_VERTEX_3 
;;;       GL_MAP1_VERTEX_4 
;;;       GL_MAP1_COLOR_4 
;;;       GL_MAP1_INDEX 
;;;       GL_MAP1_NORMAL 
;;;       GL_MAP1_TEXTURE_COORD_1 
;;;       GL_MAP1_TEXTURE_COORD_2 
;;;       GL_MAP1_TEXTURE_COORD_3 
;;;       GL_MAP1_TEXTURE_COORD_4 
;;;       GL_MAP2_VERTEX_3 
;;;       GL_MAP2_VERTEX_4 
;;;       GL_MAP2_COLOR_4 
;;;       GL_MAP2_INDEX 
;;;       GL_MAP2_NORMAL 
;;;       GL_MAP2_TEXTURE_COORD_1 
;;;       GL_MAP2_TEXTURE_COORD_2 
;;;       GL_MAP2_TEXTURE_COORD_3 
;;;       GL_MAP2_TEXTURE_COORD_4 
;;;       GL_POINT_SMOOTH 
;;;       GL_LINE_SMOOTH 
;;;       GL_POLYGON_SMOOTH 
;;;       GL_SCISSOR_TEST 
;;;       GL_COLOR_MATERIAL 
;;;       GL_NORMALIZE 
;;;       GL_AUTO_NORMAL 

;;;  ErrorCode 
(defconstant GL_NO_ERROR                          0)
(defconstant GL_INVALID_ENUM                      #x0500)
(defconstant GL_INVALID_VALUE                     #x0501)
(defconstant GL_INVALID_OPERATION                 #x0502)
(defconstant GL_STACK_OVERFLOW                    #x0503)
(defconstant GL_STACK_UNDERFLOW                   #x0504)
(defconstant GL_OUT_OF_MEMORY                     #x0505)

;;;  FeedBackMode 
(defconstant GL_2D                                #x0600)
(defconstant GL_3D                                #x0601)
(defconstant GL_3D_COLOR                          #x0602)
(defconstant GL_3D_COLOR_TEXTURE                  #x0603)
(defconstant GL_4D_COLOR_TEXTURE                  #x0604)

;;;  FeedBackToken 
(defconstant GL_PASS_THROUGH_TOKEN                #x0700)
(defconstant GL_POINT_TOKEN                       #x0701)
(defconstant GL_LINE_TOKEN                        #x0702)
(defconstant GL_POLYGON_TOKEN                     #x0703)
(defconstant GL_BITMAP_TOKEN                      #x0704)
(defconstant GL_DRAW_PIXEL_TOKEN                  #x0705)
(defconstant GL_COPY_PIXEL_TOKEN                  #x0706)
(defconstant GL_LINE_RESET_TOKEN                  #x0707)

;;;  FogMode 
;;;       GL_LINEAR 
(defconstant GL_EXP                               #x0800)
(defconstant GL_EXP2                              #x0801)

;;;  FogParameter 
;;;       GL_FOG_COLOR 
;;;       GL_FOG_DENSITY 
;;;       GL_FOG_END 
;;;       GL_FOG_INDEX 
;;;       GL_FOG_MODE 
;;;       GL_FOG_START 

;;;  FrontFaceDirection 
(defconstant GL_CW                                #x0900)
(defconstant GL_CCW                               #x0901)

;;;  GetMapTarget 
(defconstant GL_COEFF                             #x0A00)
(defconstant GL_ORDER                             #x0A01)
(defconstant GL_DOMAIN                            #x0A02)

;;;  GetPixelMap 
;;;       GL_PIXEL_MAP_I_TO_I 
;;;       GL_PIXEL_MAP_S_TO_S 
;;;       GL_PIXEL_MAP_I_TO_R 
;;;       GL_PIXEL_MAP_I_TO_G 
;;;       GL_PIXEL_MAP_I_TO_B 
;;;       GL_PIXEL_MAP_I_TO_A 
;;;       GL_PIXEL_MAP_R_TO_R 
;;;       GL_PIXEL_MAP_G_TO_G 
;;;       GL_PIXEL_MAP_B_TO_B 
;;;       GL_PIXEL_MAP_A_TO_A 

;;;  GetTarget 
(defconstant GL_CURRENT_COLOR                     #x0B00)
(defconstant GL_CURRENT_INDEX                     #x0B01)
(defconstant GL_CURRENT_NORMAL                    #x0B02)
(defconstant GL_CURRENT_TEXTURE_COORDS            #x0B03)
(defconstant GL_CURRENT_RASTER_COLOR              #x0B04)
(defconstant GL_CURRENT_RASTER_INDEX              #x0B05)
(defconstant GL_CURRENT_RASTER_TEXTURE_COORDS     #x0B06)
(defconstant GL_CURRENT_RASTER_POSITION           #x0B07)
(defconstant GL_CURRENT_RASTER_POSITION_VALID     #x0B08)
(defconstant GL_CURRENT_RASTER_DISTANCE           #x0B09)
(defconstant GL_POINT_SMOOTH                      #x0B10)
(defconstant GL_POINT_SIZE                        #x0B11)
(defconstant GL_POINT_SIZE_RANGE                  #x0B12)
(defconstant GL_POINT_SIZE_GRANULARITY            #x0B13)
(defconstant GL_LINE_SMOOTH                       #x0B20)
(defconstant GL_LINE_WIDTH                        #x0B21)
(defconstant GL_LINE_WIDTH_RANGE                  #x0B22)
(defconstant GL_LINE_WIDTH_GRANULARITY            #x0B23)
(defconstant GL_LINE_STIPPLE                      #x0B24)
(defconstant GL_LINE_STIPPLE_PATTERN              #x0B25)
(defconstant GL_LINE_STIPPLE_REPEAT               #x0B26)
(defconstant GL_LIST_MODE                         #x0B30)
(defconstant GL_MAX_LIST_NESTING                  #x0B31)
(defconstant GL_LIST_BASE                         #x0B32)
(defconstant GL_LIST_INDEX                        #x0B33)
(defconstant GL_POLYGON_MODE                      #x0B40)
(defconstant GL_POLYGON_SMOOTH                    #x0B41)
(defconstant GL_POLYGON_STIPPLE                   #x0B42)
(defconstant GL_EDGE_FLAG                         #x0B43)
(defconstant GL_CULL_FACE                         #x0B44)
(defconstant GL_CULL_FACE_MODE                    #x0B45)
(defconstant GL_FRONT_FACE                        #x0B46)
(defconstant GL_LIGHTING                          #x0B50)
(defconstant GL_LIGHT_MODEL_LOCAL_VIEWER          #x0B51)
(defconstant GL_LIGHT_MODEL_TWO_SIDE              #x0B52)
(defconstant GL_LIGHT_MODEL_AMBIENT               #x0B53)
(defconstant GL_SHADE_MODEL                       #x0B54)
(defconstant GL_COLOR_MATERIAL_FACE               #x0B55)
(defconstant GL_COLOR_MATERIAL_PARAMETER          #x0B56)
(defconstant GL_COLOR_MATERIAL                    #x0B57)
(defconstant GL_FOG                               #x0B60)
(defconstant GL_FOG_INDEX                         #x0B61)
(defconstant GL_FOG_DENSITY                       #x0B62)
(defconstant GL_FOG_START                         #x0B63)
(defconstant GL_FOG_END                           #x0B64)
(defconstant GL_FOG_MODE                          #x0B65)
(defconstant GL_FOG_COLOR                         #x0B66)
(defconstant GL_DEPTH_RANGE                       #x0B70)
(defconstant GL_DEPTH_TEST                        #x0B71)
(defconstant GL_DEPTH_WRITEMASK                   #x0B72)
(defconstant GL_DEPTH_CLEAR_VALUE                 #x0B73)
(defconstant GL_DEPTH_FUNC                        #x0B74)
(defconstant GL_ACCUM_CLEAR_VALUE                 #x0B80)
(defconstant GL_STENCIL_TEST                      #x0B90)
(defconstant GL_STENCIL_CLEAR_VALUE               #x0B91)
(defconstant GL_STENCIL_FUNC                      #x0B92)
(defconstant GL_STENCIL_VALUE_MASK                #x0B93)
(defconstant GL_STENCIL_FAIL                      #x0B94)
(defconstant GL_STENCIL_PASS_DEPTH_FAIL           #x0B95)
(defconstant GL_STENCIL_PASS_DEPTH_PASS           #x0B96)
(defconstant GL_STENCIL_REF                       #x0B97)
(defconstant GL_STENCIL_WRITEMASK                 #x0B98)
(defconstant GL_MATRIX_MODE                       #x0BA0)
(defconstant GL_NORMALIZE                         #x0BA1)
(defconstant GL_VIEWPORT                          #x0BA2)
(defconstant GL_MODELVIEW_STACK_DEPTH             #x0BA3)
(defconstant GL_PROJECTION_STACK_DEPTH            #x0BA4)
(defconstant GL_TEXTURE_STACK_DEPTH               #x0BA5)
(defconstant GL_MODELVIEW_MATRIX                  #x0BA6)
(defconstant GL_PROJECTION_MATRIX                 #x0BA7)
(defconstant GL_TEXTURE_MATRIX                    #x0BA8)
(defconstant GL_ATTRIB_STACK_DEPTH                #x0BB0)
(defconstant GL_ALPHA_TEST                        #x0BC0)
(defconstant GL_ALPHA_TEST_FUNC                   #x0BC1)
(defconstant GL_ALPHA_TEST_REF                    #x0BC2)
(defconstant GL_DITHER                            #x0BD0)
(defconstant GL_BLEND_DST                         #x0BE0)
(defconstant GL_BLEND_SRC                         #x0BE1)
(defconstant GL_BLEND                             #x0BE2)
(defconstant GL_LOGIC_OP_MODE                     #x0BF0)
(defconstant GL_LOGIC_OP                          #x0BF1)
(defconstant GL_AUX_BUFFERS                       #x0C00)
(defconstant GL_DRAW_BUFFER                       #x0C01)
(defconstant GL_READ_BUFFER                       #x0C02)
(defconstant GL_SCISSOR_BOX                       #x0C10)
(defconstant GL_SCISSOR_TEST                      #x0C11)
(defconstant GL_INDEX_CLEAR_VALUE                 #x0C20)
(defconstant GL_INDEX_WRITEMASK                   #x0C21)
(defconstant GL_COLOR_CLEAR_VALUE                 #x0C22)
(defconstant GL_COLOR_WRITEMASK                   #x0C23)
(defconstant GL_INDEX_MODE                        #x0C30)
(defconstant GL_RGBA_MODE                         #x0C31)
(defconstant GL_DOUBLEBUFFER                      #x0C32)
(defconstant GL_STEREO                            #x0C33)
(defconstant GL_RENDER_MODE                       #x0C40)
(defconstant GL_PERSPECTIVE_CORRECTION_HINT       #x0C50)
(defconstant GL_POINT_SMOOTH_HINT                 #x0C51)
(defconstant GL_LINE_SMOOTH_HINT                  #x0C52)
(defconstant GL_POLYGON_SMOOTH_HINT               #x0C53)
(defconstant GL_FOG_HINT                          #x0C54)
(defconstant GL_TEXTURE_GEN_S                     #x0C60)
(defconstant GL_TEXTURE_GEN_T                     #x0C61)
(defconstant GL_TEXTURE_GEN_R                     #x0C62)
(defconstant GL_TEXTURE_GEN_Q                     #x0C63)
(defconstant GL_PIXEL_MAP_I_TO_I                  #x0C70)
(defconstant GL_PIXEL_MAP_S_TO_S                  #x0C71)
(defconstant GL_PIXEL_MAP_I_TO_R                  #x0C72)
(defconstant GL_PIXEL_MAP_I_TO_G                  #x0C73)
(defconstant GL_PIXEL_MAP_I_TO_B                  #x0C74)
(defconstant GL_PIXEL_MAP_I_TO_A                  #x0C75)
(defconstant GL_PIXEL_MAP_R_TO_R                  #x0C76)
(defconstant GL_PIXEL_MAP_G_TO_G                  #x0C77)
(defconstant GL_PIXEL_MAP_B_TO_B                  #x0C78)
(defconstant GL_PIXEL_MAP_A_TO_A                  #x0C79)
(defconstant GL_PIXEL_MAP_I_TO_I_SIZE             #x0CB0)
(defconstant GL_PIXEL_MAP_S_TO_S_SIZE             #x0CB1)
(defconstant GL_PIXEL_MAP_I_TO_R_SIZE             #x0CB2)
(defconstant GL_PIXEL_MAP_I_TO_G_SIZE             #x0CB3)
(defconstant GL_PIXEL_MAP_I_TO_B_SIZE             #x0CB4)
(defconstant GL_PIXEL_MAP_I_TO_A_SIZE             #x0CB5)
(defconstant GL_PIXEL_MAP_R_TO_R_SIZE             #x0CB6)
(defconstant GL_PIXEL_MAP_G_TO_G_SIZE             #x0CB7)
(defconstant GL_PIXEL_MAP_B_TO_B_SIZE             #x0CB8)
(defconstant GL_PIXEL_MAP_A_TO_A_SIZE             #x0CB9)
(defconstant GL_UNPACK_SWAP_BYTES                 #x0CF0)
(defconstant GL_UNPACK_LSB_FIRST                  #x0CF1)
(defconstant GL_UNPACK_ROW_LENGTH                 #x0CF2)
(defconstant GL_UNPACK_SKIP_ROWS                  #x0CF3)
(defconstant GL_UNPACK_SKIP_PIXELS                #x0CF4)
(defconstant GL_UNPACK_ALIGNMENT                  #x0CF5)
(defconstant GL_PACK_SWAP_BYTES                   #x0D00)
(defconstant GL_PACK_LSB_FIRST                    #x0D01)
(defconstant GL_PACK_ROW_LENGTH                   #x0D02)
(defconstant GL_PACK_SKIP_ROWS                    #x0D03)
(defconstant GL_PACK_SKIP_PIXELS                  #x0D04)
(defconstant GL_PACK_ALIGNMENT                    #x0D05)
(defconstant GL_MAP_COLOR                         #x0D10)
(defconstant GL_MAP_STENCIL                       #x0D11)
(defconstant GL_INDEX_SHIFT                       #x0D12)
(defconstant GL_INDEX_OFFSET                      #x0D13)
(defconstant GL_RED_SCALE                         #x0D14)
(defconstant GL_RED_BIAS                          #x0D15)
(defconstant GL_ZOOM_X                            #x0D16)
(defconstant GL_ZOOM_Y                            #x0D17)
(defconstant GL_GREEN_SCALE                       #x0D18)
(defconstant GL_GREEN_BIAS                        #x0D19)
(defconstant GL_BLUE_SCALE                        #x0D1A)
(defconstant GL_BLUE_BIAS                         #x0D1B)
(defconstant GL_ALPHA_SCALE                       #x0D1C)
(defconstant GL_ALPHA_BIAS                        #x0D1D)
(defconstant GL_DEPTH_SCALE                       #x0D1E)
(defconstant GL_DEPTH_BIAS                        #x0D1F)
(defconstant GL_MAX_EVAL_ORDER                    #x0D30)
(defconstant GL_MAX_LIGHTS                        #x0D31)
(defconstant GL_MAX_CLIP_PLANES                   #x0D32)
(defconstant GL_MAX_TEXTURE_SIZE                  #x0D33)
(defconstant GL_MAX_PIXEL_MAP_TABLE               #x0D34)
(defconstant GL_MAX_ATTRIB_STACK_DEPTH            #x0D35)
(defconstant GL_MAX_MODELVIEW_STACK_DEPTH         #x0D36)
(defconstant GL_MAX_NAME_STACK_DEPTH              #x0D37)
(defconstant GL_MAX_PROJECTION_STACK_DEPTH        #x0D38)
(defconstant GL_MAX_TEXTURE_STACK_DEPTH           #x0D39)
(defconstant GL_MAX_VIEWPORT_DIMS                 #x0D3A)
(defconstant GL_SUBPIXEL_BITS                     #x0D50)
(defconstant GL_INDEX_BITS                        #x0D51)
(defconstant GL_RED_BITS                          #x0D52)
(defconstant GL_GREEN_BITS                        #x0D53)
(defconstant GL_BLUE_BITS                         #x0D54)
(defconstant GL_ALPHA_BITS                        #x0D55)
(defconstant GL_DEPTH_BITS                        #x0D56)
(defconstant GL_STENCIL_BITS                      #x0D57)
(defconstant GL_ACCUM_RED_BITS                    #x0D58)
(defconstant GL_ACCUM_GREEN_BITS                  #x0D59)
(defconstant GL_ACCUM_BLUE_BITS                   #x0D5A)
(defconstant GL_ACCUM_ALPHA_BITS                  #x0D5B)
(defconstant GL_NAME_STACK_DEPTH                  #x0D70)
(defconstant GL_AUTO_NORMAL                       #x0D80)
(defconstant GL_MAP1_COLOR_4                      #x0D90)
(defconstant GL_MAP1_INDEX                        #x0D91)
(defconstant GL_MAP1_NORMAL                       #x0D92)
(defconstant GL_MAP1_TEXTURE_COORD_1              #x0D93)
(defconstant GL_MAP1_TEXTURE_COORD_2              #x0D94)
(defconstant GL_MAP1_TEXTURE_COORD_3              #x0D95)
(defconstant GL_MAP1_TEXTURE_COORD_4              #x0D96)
(defconstant GL_MAP1_VERTEX_3                     #x0D97)
(defconstant GL_MAP1_VERTEX_4                     #x0D98)
(defconstant GL_MAP2_COLOR_4                      #x0DB0)
(defconstant GL_MAP2_INDEX                        #x0DB1)
(defconstant GL_MAP2_NORMAL                       #x0DB2)
(defconstant GL_MAP2_TEXTURE_COORD_1              #x0DB3)
(defconstant GL_MAP2_TEXTURE_COORD_2              #x0DB4)
(defconstant GL_MAP2_TEXTURE_COORD_3              #x0DB5)
(defconstant GL_MAP2_TEXTURE_COORD_4              #x0DB6)
(defconstant GL_MAP2_VERTEX_3                     #x0DB7)
(defconstant GL_MAP2_VERTEX_4                     #x0DB8)
(defconstant GL_MAP1_GRID_DOMAIN                  #x0DD0)
(defconstant GL_MAP1_GRID_SEGMENTS                #x0DD1)
(defconstant GL_MAP2_GRID_DOMAIN                  #x0DD2)
(defconstant GL_MAP2_GRID_SEGMENTS                #x0DD3)
(defconstant GL_TEXTURE_1D                        #x0DE0)
(defconstant GL_TEXTURE_2D                        #x0DE1)

;;;  GetTextureParameter 
;;;       GL_TEXTURE_MAG_FILTER 
;;;       GL_TEXTURE_MIN_FILTER 
;;;       GL_TEXTURE_WRAP_S 
;;;       GL_TEXTURE_WRAP_T 
(defconstant GL_TEXTURE_WIDTH                     #x1000)
(defconstant GL_TEXTURE_HEIGHT                    #x1001)
(defconstant GL_TEXTURE_COMPONENTS                #x1003)
(defconstant GL_TEXTURE_BORDER_COLOR              #x1004)
(defconstant GL_TEXTURE_BORDER                    #x1005)

;;;  HintMode 
(defconstant GL_DONT_CARE                         #x1100)
(defconstant GL_FASTEST                           #x1101)
(defconstant GL_NICEST                            #x1102)

;;;  HintTarget 
;;;       GL_PERSPECTIVE_CORRECTION_HINT 
;;;       GL_POINT_SMOOTH_HINT 
;;;       GL_LINE_SMOOTH_HINT 
;;;       GL_POLYGON_SMOOTH_HINT 
;;;       GL_FOG_HINT 

;;;  LightModelParameter 
;;;       GL_LIGHT_MODEL_AMBIENT 
;;;       GL_LIGHT_MODEL_LOCAL_VIEWER 
;;;       GL_LIGHT_MODEL_TWO_SIDE 

;;;  LightName 
(defconstant GL_LIGHT0                            #x4000)
(defconstant GL_LIGHT1                            #x4001)
(defconstant GL_LIGHT2                            #x4002)
(defconstant GL_LIGHT3                            #x4003)
(defconstant GL_LIGHT4                            #x4004)
(defconstant GL_LIGHT5                            #x4005)
(defconstant GL_LIGHT6                            #x4006)
(defconstant GL_LIGHT7                            #x4007)

;;;  LightParameter 
(defconstant GL_AMBIENT                           #x1200)
(defconstant GL_DIFFUSE                           #x1201)
(defconstant GL_SPECULAR                          #x1202)
(defconstant GL_POSITION                          #x1203)
(defconstant GL_SPOT_DIRECTION                    #x1204)
(defconstant GL_SPOT_EXPONENT                     #x1205)
(defconstant GL_SPOT_CUTOFF                       #x1206)
(defconstant GL_CONSTANT_ATTENUATION              #x1207)
(defconstant GL_LINEAR_ATTENUATION                #x1208)
(defconstant GL_QUADRATIC_ATTENUATION             #x1209)

;;;  ListMode 
(defconstant GL_COMPILE                           #x1300)
(defconstant GL_COMPILE_AND_EXECUTE               #x1301)

;;;  ListNameType 
(defconstant GL_BYTE                              #x1400)
(defconstant GL_UNSIGNED_BYTE                     #x1401)
(defconstant GL_SHORT                             #x1402)
(defconstant GL_UNSIGNED_SHORT                    #x1403)
(defconstant GL_INT                               #x1404)
(defconstant GL_UNSIGNED_INT                      #x1405)
(defconstant GL_FLOAT                             #x1406)
(defconstant GL_2_BYTES                           #x1407)
(defconstant GL_3_BYTES                           #x1408)
(defconstant GL_4_BYTES                           #x1409)
(defconstant GL_DOUBLE                            #x140A)

;;;  LogicOp 
(defconstant GL_CLEAR                             #x1500)
(defconstant GL_AND                               #x1501)
(defconstant GL_AND_REVERSE                       #x1502)
(defconstant GL_COPY                              #x1503)
(defconstant GL_AND_INVERTED                      #x1504)
(defconstant GL_NOOP                              #x1505)
(defconstant GL_XOR                               #x1506)
(defconstant GL_OR                                #x1507)
(defconstant GL_NOR                               #x1508)
(defconstant GL_EQUIV                             #x1509)
(defconstant GL_INVERT                            #x150A)
(defconstant GL_OR_REVERSE                        #x150B)
(defconstant GL_COPY_INVERTED                     #x150C)
(defconstant GL_OR_INVERTED                       #x150D)
(defconstant GL_NAND                              #x150E)
(defconstant GL_SET                               #x150F)

;;;  MapTarget 
;;;       GL_MAP1_COLOR_4 
;;;       GL_MAP1_INDEX 
;;;       GL_MAP1_NORMAL 
;;;       GL_MAP1_TEXTURE_COORD_1 
;;;       GL_MAP1_TEXTURE_COORD_2 
;;;       GL_MAP1_TEXTURE_COORD_3 
;;;       GL_MAP1_TEXTURE_COORD_4 
;;;       GL_MAP1_VERTEX_3 
;;;       GL_MAP1_VERTEX_4 
;;;       GL_MAP2_COLOR_4 
;;;       GL_MAP2_INDEX 
;;;       GL_MAP2_NORMAL 
;;;       GL_MAP2_TEXTURE_COORD_1 
;;;       GL_MAP2_TEXTURE_COORD_2 
;;;       GL_MAP2_TEXTURE_COORD_3 
;;;       GL_MAP2_TEXTURE_COORD_4 
;;;       GL_MAP2_VERTEX_3 
;;;       GL_MAP2_VERTEX_4 

;;;  MaterialFace 
;;;       GL_FRONT 
;;;       GL_BACK 
;;;       GL_FRONT_AND_BACK 

;;;  MaterialParameter 
(defconstant GL_EMISSION                          #x1600)
(defconstant GL_SHININESS                         #x1601)
(defconstant GL_AMBIENT_AND_DIFFUSE               #x1602)
(defconstant GL_COLOR_INDEXES                     #x1603)
;;;       GL_AMBIENT 
;;;       GL_DIFFUSE 
;;;       GL_SPECULAR 

;;;  MatrixMode 
(defconstant GL_MODELVIEW                         #x1700)
(defconstant GL_PROJECTION                        #x1701)
(defconstant GL_TEXTURE                           #x1702)

;;;  MeshMode1 
;;;       GL_POINT 
;;;       GL_LINE 

;;;  MeshMode2 
;;;       GL_POINT 
;;;       GL_LINE 
;;;       GL_FILL 

;;;  PixelCopyType 
(defconstant GL_COLOR                             #x1800)
(defconstant GL_DEPTH                             #x1801)
(defconstant GL_STENCIL                           #x1802)

;;;  PixelFormat 
(defconstant GL_COLOR_INDEX                       #x1900)
(defconstant GL_STENCIL_INDEX                     #x1901)
(defconstant GL_DEPTH_COMPONENT                   #x1902)
(defconstant GL_RED                               #x1903)
(defconstant GL_GREEN                             #x1904)
(defconstant GL_BLUE                              #x1905)
(defconstant GL_ALPHA                             #x1906)
(defconstant GL_RGB                               #x1907)
(defconstant GL_RGBA                              #x1908)
(defconstant GL_LUMINANCE                         #x1909)
(defconstant GL_LUMINANCE_ALPHA                   #x190A)

;;;  PixelMap 
;;;       GL_PIXEL_MAP_I_TO_I 
;;;       GL_PIXEL_MAP_S_TO_S 
;;;       GL_PIXEL_MAP_I_TO_R 
;;;       GL_PIXEL_MAP_I_TO_G 
;;;       GL_PIXEL_MAP_I_TO_B 
;;;       GL_PIXEL_MAP_I_TO_A 
;;;       GL_PIXEL_MAP_R_TO_R 
;;;       GL_PIXEL_MAP_G_TO_G 
;;;       GL_PIXEL_MAP_B_TO_B 
;;;       GL_PIXEL_MAP_A_TO_A 

;;;  PixelStore 
;;;       GL_UNPACK_SWAP_BYTES 
;;;       GL_UNPACK_LSB_FIRST 
;;;       GL_UNPACK_ROW_LENGTH 
;;;       GL_UNPACK_SKIP_ROWS 
;;;       GL_UNPACK_SKIP_PIXELS 
;;;       GL_UNPACK_ALIGNMENT 
;;;       GL_PACK_SWAP_BYTES 
;;;       GL_PACK_LSB_FIRST 
;;;       GL_PACK_ROW_LENGTH 
;;;       GL_PACK_SKIP_ROWS 
;;;       GL_PACK_SKIP_PIXELS 
;;;       GL_PACK_ALIGNMENT 

;;;  PixelTransfer 
;;;       GL_MAP_COLOR 
;;;       GL_MAP_STENCIL 
;;;       GL_INDEX_SHIFT 
;;;       GL_INDEX_OFFSET 
;;;       GL_RED_SCALE 
;;;       GL_RED_BIAS 
;;;       GL_GREEN_SCALE 
;;;       GL_GREEN_BIAS 
;;;       GL_BLUE_SCALE 
;;;       GL_BLUE_BIAS 
;;;       GL_ALPHA_SCALE 
;;;       GL_ALPHA_BIAS 
;;;       GL_DEPTH_SCALE 
;;;       GL_DEPTH_BIAS 

;;;  PixelType 
(defconstant GL_BITMAP                            #x1A00)
;;;       GL_BYTE 
;;;       GL_UNSIGNED_BYTE 
;;;       GL_SHORT 
;;;       GL_UNSIGNED_SHORT 
;;;       GL_INT 
;;;       GL_UNSIGNED_INT 
;;;       GL_FLOAT 

;;;  PolygonMode 
(defconstant GL_POINT                             #x1B00)
(defconstant GL_LINE                              #x1B01)
(defconstant GL_FILL                              #x1B02)

;;;  ReadBufferMode 
;;;       GL_FRONT_LEFT 
;;;       GL_FRONT_RIGHT 
;;;       GL_BACK_LEFT 
;;;       GL_BACK_RIGHT 
;;;       GL_FRONT 
;;;       GL_BACK 
;;;       GL_LEFT 
;;;       GL_RIGHT 
;;;       GL_AUX0 
;;;       GL_AUX1 
;;;       GL_AUX2 
;;;       GL_AUX3 

;;;  RenderingMode 
(defconstant GL_RENDER                            #x1C00)
(defconstant GL_FEEDBACK                          #x1C01)
(defconstant GL_SELECT                            #x1C02)

;;;  ShadingModel 
(defconstant GL_FLAT                              #x1D00)
(defconstant GL_SMOOTH                            #x1D01)

;;;  StencilFunction 
;;;       GL_NEVER 
;;;       GL_LESS 
;;;       GL_EQUAL 
;;;       GL_LEQUAL 
;;;       GL_GREATER 
;;;       GL_NOTEQUAL 
;;;       GL_GEQUAL 
;;;       GL_ALWAYS 

;;;  StencilOp 
;;;       GL_ZERO 
(defconstant GL_KEEP                              #x1E00)
(defconstant GL_REPLACE                           #x1E01)
(defconstant GL_INCR                              #x1E02)
(defconstant GL_DECR                              #x1E03)
;;;       GL_INVERT 

;;;  StringName 
(defconstant GL_VENDOR                            #x1F00)
(defconstant GL_RENDERER                          #x1F01)
(defconstant GL_VERSION                           #x1F02)
(defconstant GL_EXTENSIONS                        #x1F03)

;;;  TextureCoordName 
(defconstant GL_S                                 #x2000)
(defconstant GL_T                                 #x2001)
(defconstant GL_R                                 #x2002)
(defconstant GL_Q                                 #x2003)

;;;  TextureEnvMode 
(defconstant GL_MODULATE                          #x2100)
(defconstant GL_DECAL                             #x2101)
;;;       GL_BLEND 

;;;  TextureEnvParameter 
(defconstant GL_TEXTURE_ENV_MODE                  #x2200)
(defconstant GL_TEXTURE_ENV_COLOR                 #x2201)

;;;  TextureEnvTarget 
(defconstant GL_TEXTURE_ENV                       #x2300)

;;;  TextureGenMode 
(defconstant GL_EYE_LINEAR                        #x2400)
(defconstant GL_OBJECT_LINEAR                     #x2401)
(defconstant GL_SPHERE_MAP                        #x2402)

;;;  TextureGenParameter 
(defconstant GL_TEXTURE_GEN_MODE                  #x2500)
(defconstant GL_OBJECT_PLANE                      #x2501)
(defconstant GL_EYE_PLANE                         #x2502)

;;;  TextureMagFilter 
(defconstant GL_NEAREST                           #x2600)
(defconstant GL_LINEAR                            #x2601)

;;;  TextureMinFilter 
;;;       GL_NEAREST 
;;;       GL_LINEAR 
(defconstant GL_NEAREST_MIPMAP_NEAREST            #x2700)
(defconstant GL_LINEAR_MIPMAP_NEAREST             #x2701)
(defconstant GL_NEAREST_MIPMAP_LINEAR             #x2702)
(defconstant GL_LINEAR_MIPMAP_LINEAR              #x2703)

;;;  TextureParameterName 
(defconstant GL_TEXTURE_MAG_FILTER                #x2800)
(defconstant GL_TEXTURE_MIN_FILTER                #x2801)
(defconstant GL_TEXTURE_WRAP_S                    #x2802)
(defconstant GL_TEXTURE_WRAP_T                    #x2803)

;;;  TextureTarget 
;;;       GL_TEXTURE_1D 
;;;       GL_TEXTURE_2D 

;;;  TextureWrapMode 
(defconstant GL_CLAMP                             #x2900)
(defconstant GL_REPEAT                            #x2901)

;;;  Attachment
(defconstant GL_COLOR_ATTACHMENT0              #x8CE0)
(defconstant GL_COLOR_ATTACHMENT1              #x8CE1)
(defconstant GL_COLOR_ATTACHMENT2              #x8CE2)
(defconstant GL_COLOR_ATTACHMENT3              #x8CE3)
(defconstant GL_COLOR_ATTACHMENT4              #x8CE4)
(defconstant GL_COLOR_ATTACHMENT5              #x8CE5)
(defconstant GL_COLOR_ATTACHMENT6              #x8CE6)
(defconstant GL_COLOR_ATTACHMENT7              #x8CE7)
(defconstant GL_COLOR_ATTACHMENT8              #x8CE8)
(defconstant GL_COLOR_ATTACHMENT9              #x8CE9)
(defconstant GL_COLOR_ATTACHMENT10             #x8CEA)
(defconstant GL_COLOR_ATTACHMENT11             #x8CEB)
(defconstant GL_COLOR_ATTACHMENT12             #x8CEC)
(defconstant GL_COLOR_ATTACHMENT13             #x8CED)
(defconstant GL_COLOR_ATTACHMENT14             #x8CEE)
(defconstant GL_COLOR_ATTACHMENT15             #x8CEF)
(defconstant GL_COLOR_ATTACHMENT16             #x8CF0)
(defconstant GL_COLOR_ATTACHMENT17             #x8CF1)
(defconstant GL_COLOR_ATTACHMENT18             #x8CF2)
(defconstant GL_COLOR_ATTACHMENT19             #x8CF3)
(defconstant GL_COLOR_ATTACHMENT20             #x8CF4)
(defconstant GL_COLOR_ATTACHMENT21             #x8CF5)
(defconstant GL_COLOR_ATTACHMENT22             #x8CF6)
(defconstant GL_COLOR_ATTACHMENT23             #x8CF7)
(defconstant GL_COLOR_ATTACHMENT24             #x8CF8)
(defconstant GL_COLOR_ATTACHMENT25             #x8CF9)
(defconstant GL_COLOR_ATTACHMENT26             #x8CFA)
(defconstant GL_COLOR_ATTACHMENT27             #x8CFB)
(defconstant GL_COLOR_ATTACHMENT28             #x8CFC)
(defconstant GL_COLOR_ATTACHMENT29             #x8CFD)
(defconstant GL_COLOR_ATTACHMENT30             #x8CFE)
(defconstant GL_COLOR_ATTACHMENT31             #x8CFF)
(defconstant GL_DEPTH_ATTACHMENT               #x8D00)
(defconstant GL_STENCIL_ATTACHMENT             #x8D20)

;;;;;;;;;;;;;;;;;;;;;;

(provide :glconst "@(#)$Id$")


