#|
/* Copyright (c) Mark J. Kilgard, 1994. */

/**
 * (c) Copyright 1993, 1994, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED 
 * Permission to use, copy, modify, and distribute this software for 
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that 
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. 
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * US Government Users Restricted Rights 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(TM) is a trademark of Silicon Graphics, Inc.
 */

/*
 * 1992 David G Yu -- Silicon Graphics Computer Systems
 */
|#

;; porting to euslisp by Kei Okada <k-okada@jsk.t.u-tokyo.ac.jp>

(in-package "GL")
(load "glut.l")

(defvar useRGB	t)
(defvar useLighting t)
(defvar useFog	nil)
(defvar useDB	t)
(defvar useLogo nil)
(defvar useQuads t)

(defvar tick	-1)
(defvar moving	t)

(defconstant GREY	0)
(defconstant RED	1)
(defconstant GREEN	2)
(defconstant BLUE	3)
(defconstant CYAN	4)
(defconstant MAGENTA	5)
(defconstant YELLOW	6)
(defconstant BLACK	7)

(setq materialColor
  (make-matrix 8 4
	       (list (list 0.8 0.8 0.8 1.0)
		     (list 0.8 0.0 0.0 1.0)
		     (list 0.0 0.8 0.0 1.0)
		     (list 0.0 0.0 0.8 1.0)
		     (list 0.0 0.8 0.8 1.0)
		     (list 0.8 0.0 0.8 1.0)
		     (list 0.8 0.8 0.0 1.0)
		     (list 0.0 0.0 0.0 0.6)
		     )))

(setq lightPos	#f(2.0 4.0 2.0 1.0))
;;; (setq lightDir	#f(-2.0 -4.0 -2.0 1.0))
(setq lightAmb	#f(0.2 0.2 0.2 1.0))
(setq lightDiff #f(0.8 0.8 0.8 1.0))
(setq lightSpec #f(0.4 0.4 0.4 1.0))

(setq groundPlane #f(0.0 1.0 0.0 1.499))
(setq backPlane #f(0.0 0.0 1.0 0.899))

(setq fogColor	#f(0.0 0.0 0.0 0.0))
(setq fogIndex	#f(0.0))

(setq shadowPattern
  #i(#xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55  ;; /* 50% Grey */
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   #xaa #xaa #xaa #xaa #x55 #x55 #x55 #x55
	   ))

(setq sgiPattern
  #i(#xff #xff #xff #xff #xff #xff #xff #xff  ;; /* SGI Logo */
	   #xff #xbd #xff #x83 #xff #x5a #xff #xef
	   #xfe #xdb #x7f #xef #xfd #xdb #xbf #xef
	   #xfb #xdb #xdf #xef #xf7 #xdb #xef #xef
	   #xfb #xdb #xdf #xef #xfd #xdb #xbf #x83
	   #xce #xdb #x73 #xff #xb7 #x5a #xed #xff
	   #xbb #xdb #xdd #xc7 #xbd #xdb #xbd #xbb
	   #xbe #xbd #x7d #xbb #xbf #x7e #xfd #xb3
	   #xbe #xe7 #x7d #xbf #xbd #xdb #xbd #xbf
	   #xbb #xbd #xdd #xbb #xb7 #x7e #xed #xc7
	   #xce #xdb #x73 #xff #xfd #xdb #xbf #xff
	   #xfb #xdb #xdf #x87 #xf7 #xdb #xef #xfb
	   #xf7 #xdb #xef #xfb #xfb #xdb #xdf #xfb
	   #xfd #xdb #xbf #xc7 #xfe #xdb #x7f #xbf
	   #xff #x5a #xff #xbf #xff #xbd #xff #xc3
	   #xff #xff #xff #xff #xff #xff #xff #xff
	   ))

(setq cube-vertexes
  (list
      #2f((-1.0 -1.0 -1.0 1.0)
	  (-1.0 -1.0 1.0 1.0)
	  (-1.0 1.0 1.0 1.0)
	  (-1.0 1.0 -1.0 1.0))
      #2f((1.0 1.0 1.0 1.0)
	  (1.0 -1.0 1.0 1.0)
	  (1.0 -1.0 -1.0 1.0)
	  (1.0 1.0 -1.0 1.0))
      #2f((-1.0 -1.0 -1.0 1.0)
	  (1.0 -1.0 -1.0 1.0)
	  (1.0 -1.0 1.0 1.0)
	  (-1.0 -1.0 1.0 1.0))
      #2f((1.0 1.0 1.0 1.0)
	  (1.0 1.0 -1.0 1.0)
	  (-1.0 1.0 -1.0 1.0)
	  (-1.0 1.0 1.0 1.0))
      #2f((-1.0 -1.0 -1.0 1.0)
	  (-1.0 1.0 -1.0 1.0)
	  (1.0 1.0 -1.0 1.0)
	  (1.0 -1.0 -1.0 1.0))
      #2f((1.0 1.0 1.0 1.0)
	  (-1.0 1.0 1.0 1.0)
	  (-1.0 -1.0 1.0 1.0)
	  (1.0 -1.0 1.0 1.0))
      ))

(setq cube-normals
  (make-matrix 6 4
	       (list
		(list -1.0 0.0 0.0 0.0)
		(list 1.0 0.0 0.0 0.0)
		(list 0.0 -1.0 0.0 0.0)
		(list 0.0 1.0 0.0 0.0)
		(list 0.0 0.0 -1.0 0.0)
		(list 0.0 0.0 1.0 0.0))
	       ))

(defun usage
  ()
  (print "")
  (print "usage: scube [options]")
  (print "")
  (print "    display a spinning cube and its shadow")
  (print "")
  (print "  Options:")
  (print "    -geometry  window size and location")
  (print "    -c         toggle color index mode")
  (print "    -l         toggle lighting")
  (print "    -f         toggle fog")
  (print "    -db        toggle double buffering")
  (print "    -logo      toggle sgi logo for the shadow pattern")
  (print "    -quads     toggle use of GL_QUADS to draw the checkerboard")
  (print "")
  (if (not (boundp 'EXIT_FAILURE))
      (setq EXIT_FAILURE 1))
  (exit EXIT_FAILURE)
  )

(defun buildColormap
  ()
  (if useRGB
      (return-from buildColormap nil)
    (progn
      (setq mapSize (ash 1 (glutGet GLUT_WINDOW_BUFFER_SIZE)))
      (setq rampSize (/ mapSize 8.0))

      (dolist (entry mapSize)
	(setq hue (/ entry rampSize))
	(setq val (* (mod entry rampSize) (/ 1.0 (- rampSize 1))))

	(setq red (if (or (= hue 0) (= hue 1) (= hue 5) (= hue 6)) val 0))
	(setq green (if (or (= hue 0) (= hue 2) (= hue 4) (= hue 6)) val  0))
	(setq blue (if (or (hue 0) (= hue 3) (= hue 4) (= hue 5)) val 0))

	(glutSetColor entry red green blue)
	)

      (dotimes (i 8)
	(setf (aref materialColor i 0) (* i (+ rampSize 0.2) (- rampSize 1)))
	(setf (aref materialColor i 1) (* i (+ rampSize 0.8) (- rampSize 1)))
	(setf (aref materialColor i 2) (* i (+ rampSize 1.0) (- rampSize 1)))
	(setf (aref materialColor i 3) 0.0))
      
      (setf (aref fogIndex 0) (* -0.2 (- rampSize 1.0)))
      ))
  )

(defun setColor
  (c)
  (if useLighting
      (if useRGB
	  (glMaterialfv GL_FRONT_AND_BACK
			GL_AMBIENT_AND_DIFFUSE (matrix-row materialColor c))
	(glMaterialfv GL_FRONT_AND_BACK
			GL_COLOR_INDEXES (matrix-row materialColor c)))
    (if useRGB
	(glColor4fv (matrix-row materialColor c))
      (glIndexf (aref materialColor c 1)))
    ))

(defun drawCube
  (color)
  (setColor color)

  (dotimes (i 6)
    (glNormal3fv (matrix-row cube-normals i))
    (glBegin GL_POLYGON)
    (glVertex4fv (matrix-row (elt cube-vertexes i) 0))
    (glVertex4fv (matrix-row (elt cube-vertexes i) 1))
    (glVertex4fv (matrix-row (elt cube-vertexes i) 2))
    (glVertex4fv (matrix-row (elt cube-vertexes i) 3))
    (glEnd)
    ))

(setq initialized  nil
      usedLighting nil
      checklist    nil)

(defun drawCheck
  (w h evenColor oddColor)
  (if (or (null initialized)
	  (not (eq usedLighting useLighting)))
	(progn
	  (setq square-normal #f(0.0 0.0 1.0 0.0))
	  (setq square (make-matrix 4 4))

	  (if (not checklist)
	    (setq checklist (glGenLists 1))
	    )
	  (glNewList checklist GL_COMPILE_AND_EXECUTE)

	  (when useQuads
	    (glNormal3fv square-normal)
	    (glBegin GL_QUADS)
	    )
	  
	  (dotimes (j h)
	    (dotimes (i w)
	      (setf (aref square 0 0) (+ -1.0 (* (/ 2.0 w) i)))
	      (setf (aref square 0 1) (+ -1.0 (* (/ 2.0 w) (+ j 1))))
	      (setf (aref square 0 2) 0.0)
	      (setf (aref square 0 3) 1.0)

	      (setf (aref square 1 0) (+ -1.0 (* (/ 2.0 w) i)))
	      (setf (aref square 1 1) (+ -1.0 (* (/ 2.0 w) j)))
	      (setf (aref square 1 2) 0.0)
	      (setf (aref square 1 3) 1.0)

	      (setf (aref square 2 0) (+ -1.0 (* (/ 2.0 w) (+ i 1))))
	      (setf (aref square 2 1) (+ -1.0 (* (/ 2.0 w) j)))
	      (setf (aref square 2 2) 0.0)
	      (setf (aref square 2 3) 1.0)

	      (setf (aref square 3 0) (+ -1.0 (* (/ 2.0 w) (+ i 1))))
	      (setf (aref square 3 1) (+ -1.0 (* (/ 2.0 w) (+ j 1))))
	      (setf (aref square 3 2) 0.0)
	      (setf (aref square 3 3) 1.0)

	      (if (= (logxor (logand i 1) (logand j 1)) 1)
		  (setColor oddColor)
		(setColor evenColor))
	      
	      (if useQuads
		  (glBegin GL_POLYGON)
		)
	      (glVertex4fv (matrix-row square 0))
	      (glVertex4fv (matrix-row square 1))
	      (glVertex4fv (matrix-row square 2))
	      (glVertex4fv (matrix-row square 3))
	      (if (not useQuads)
		  (glEnd)
		)
	      ))

	  (if useQuads
	      (glEnd))

	  (glEndList)

	  (setq initialized t)
	  (setq usedLighting useLighting)
	  )
      (glCallList checklist)
      )
    )

(defun myShadowMatrix
  (ground light)
  (setq shadowMat (make-matrix 4 4))

  (setq dot (+ (* (elt ground 0) (elt light 0))
	       (* (elt ground 1) (elt light 1))
	       (* (elt ground 2) (elt light 2))
	       (* (elt ground 3) (elt light 3))))

  (setf (aref shadowMat 0 0) (- dot (* (elt light 0) (elt ground 0))))
  (setf (aref shadowMat 1 0) (- 0 (* (elt light 0) (elt ground 1))))
  (setf (aref shadowMat 2 0) (- 0 (* (elt light 0) (elt ground 2))))
  (setf (aref shadowMat 3 0) (- 0 (* (elt light 0) (elt ground 3))))

  (setf (aref shadowMat 0 1) (- 0 (* (elt light 1) (elt ground 0))))
  (setf (aref shadowMat 1 1) (- dot (* (elt light 1) (elt ground 1))))
  (setf (aref shadowMat 2 1) (- 0 (* (elt light 1) (elt ground 2))))
  (setf (aref shadowMat 3 1) (- 0 (* (elt light 1) (elt ground 3))))

  (setf (aref shadowMat 0 2) (- 0 (* (elt light 2) (elt ground 0))))
  (setf (aref shadowMat 1 2) (- 0 (* (elt light 2) (elt ground 1))))
  (setf (aref shadowMat 2 2) (- dot (* (elt light 2) (elt ground 2))))
  (setf (aref shadowMat 3 2) (- 0 (* (elt light 2) (elt ground 3))))

  (setf (aref shadowMat 0 3) (- 0 (* (elt light 3) (elt ground 0))))
  (setf (aref shadowMat 1 3) (- 0 (* (elt light 3) (elt ground 1))))
  (setf (aref shadowMat 2 3) (- 0 (* (elt light 3) (elt ground 2))))
  (setf (aref shadowMat 3 3) (- dot (* (elt light 3) (elt ground 3))))

  (glMultMatrixf (array-entity shadowMat))
  )

(setq windowNameRGBDB "shadow cube (OpenGL RGB DB)")
(setq windowNameRGB   "shadow cube (OpenGL RGB)")
(setq windowNameIndexDB "shadow cube (OpenGL Index DB)")
(setq windowNameIndex   "shadow cube (OpenGL Index)")

(defun-c-callable idle2 () :integer
  (incf tick)
  (if (>= tick 20)
      (setq tick 0)
    )
  (glutPostRedisplay)
  )

(defun-c-callable keyboard (ch x y) :integer
  (case ch
    (27             ;; escape
     (exit 0))
    (#\l
     (setq useLighting (not useLighting))
     (if useLighting
	 (glEnable GL_LIGHTING)
       (glDisable GL_LIGHTING))
     (glutPostRedisplay))
    (#\f
     (setq useFog (not useFog))
     (if useFog
	 (glEnable GL_FOG)
       (glDisable GL_FOG))
     (glutPostRedisplay))
    (#\1
     (glFogf GL_FOG_MODE (float GL_LINEAR))
     (glutPostRedisplay))
    (#\2
     (glFogf GL_FOG_MODE (float GL_EXP))
     (glutPostRedisplay))
    (#\3
     (glFogf GL_FOG_MODE (float GL_EXP2))
     (glutPostRedisplay))
    (#\ 
     (when (not moving)
       (idle2)
       (glutPostRedisplay))
     )
    ))

(defun-c-callable display () :integer
  (setq cubeXform (make-matrix 4 4))

  (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))

  (glPushMatrix)
  (glTranslatefv #f(0.0 -1.5 0.0))
  (glRotatefv #f(-90.0 1 0 0))
  (glScalefv #f(2.0 2.0 2.0))

  (drawCheck 6 6 BLUE YELLOW)	;; draw ground 
  (glPopMatrix)

  (glPushMatrix)
  (glTranslatefv #f(0.0 0.0 -0.9))
  (glScalefv #f(2.0 2.0 2.0))

  (drawCheck 6 6 BLUE YELLOW)	;; draw back
  (glPopMatrix)

  (glPushMatrix)
  (glTranslatefv #f(0.0 0.2 0.0))
  (glScalefv #f(0.3 0.3 0.3))
  (glRotatefv (float-vector (* (/ 360.0 (* 30.0 1)) tick) 1 0 0))
  (glRotatefv (float-vector (* (/ 360.0 (* 30.0 2)) tick) 0 1 0))
  (glRotatefv (float-vector (* (/ 360.0 (* 30.0 3)) tick) 0 0 1))
  (format t "~A~%" (float-vector (* (/ 360.0 (* 30.0 1)) tick) 1 0 0))
  (glScalefv #f(1.0 2.0 1.0))
  (glGetFloatv GL_MODELVIEW_MATRIX (array-entity cubeXform))

  (drawCube RED)        ;; draw cube
  (glPopMatrix)

  (glDepthMask GL_FALSE)
  (if useRGB
      (glEnable GL_BLEND)
    (glEnable GL_POLYGON_STIPPLE)
  )
  (if useFog
      (glDisable GL_FOG)
    )
  (glPushMatrix)
  (myShadowMatrix groundPlane lightPos)
  (glTranslatefv #f(0.0 0.0 2.0))
  (glMultMatrixf (array-entity cubeXform))

  (drawCube BLACK)	;; draw ground shadow 
  (glPopMatrix)

  (glPushMatrix)
  (myShadowMatrix backPlane lightPos)
  (glTranslatefv #f(0.0 0.0 2.0))
  (glMultMatrixf (array-entity cubeXform))

  (drawCube BLACK)	;; draw back shadow
  (glPopMatrix)

  (glDepthMask GL_TRUE)
  (if useRGB
      (glDisable GL_BLEND)
    (glDisable GL_POLYGON_STIPPLE)
    )
  (if useFog
      (glEnable GL_FOG)
    )
  (if useDB
      (glutSwapBuffers)
    (glFlush)
  )
)

(defun-c-callable fog_select (fog) :integer
  (glFogf GL_FOG_MODE fog)
  (glutPostRedisplay)
  )

(defun-c-callable menu_select (mode) :integer
  (case mode
    (1
     (setq moving t)
     (glutIdleFunc (pod-address 'idle2))
     )
    (2
     (setq moving nil)
     (glutIdleFunc 0)
     )
    (3
     (setq useFog (not useFog))
     (if useFog
	 (glEnable GL_FOG)
       (glDisable GL_FOG))
     (glutPostRedisplay)
     )
    (4
     (setq useLighting (not useLighting))
     (if useLighting
	 (glEnable GL_LIGHTING)
       (glDisable GL_LIGHTING))
     (glutPostRedisplay)
     )
    (5
     (exit 0)
     )
  ))

(defun-c-callable visible (state) :integer
  (if (= state GLUT_VISIBLE)
      (if moving (glutIdleFunc (pod-address 'idle2)))
    (if moving (glutIdleFunc 0)))
  )

(defun main nil
  (let ((argc "0")
	(argv "0") (argv0 (unix::malloc lisp::sizeof-*)) argv1
	(width 350) (height 350))
    (glutInitWindowSize width height)

    (sys::poke 1 argc 0 :integer)
    (setq argv1 (make-foreign-string argv0 lisp::sizeof-*))
    (setf (elt argv1 0) 0)
    (sys::poke argv0 argv 0 :integer)
    (glutInit argc argv)

    ;; choose visual
    (if useRGB
	(if useDB
	    (progn
	      (glutInitDisplayMode (logior GLUT_DOUBLE GLUT_RGB GLUT_DEPTH))
	      (setq name windowNameRGBDB))
	  (progn
	    (glutInitDisplayMode (logior GLUT_SINGLE GLUT_RGB GLUT_DEPTH))
	    (setq name windowNameRGB)))
      (if useDB
	  (progn
	    (glutInitDisplayMode (logior GLUT_DOUBLE GLUT_INDEX GLUT_DEPTH))
	    (setq name windowNameIndexDB))
	(progn
	  (glutInitDisplayMode (logior GLUT_SINGLE GLUT_INDEX GLUT_DEPTH))
	  (setq name windowNameIndex)))
      )

    (glutCreateWindow name)

    (buildColormap)

    (glutKeyboardFunc (pod-address 'keyboard))
    (glutDisplayFunc (pod-address 'display))
    (glutVisibilityFunc (pod-address 'visible))

    (setq fog_menu (glutCreateMenu (pod-address 'fog_select)))
    (glutAddMenuEntry "Linear fog" GL_LINEAR)
    (glutAddMenuEntry "Exp fog" GL_EXP)
    (glutAddMenuEntry "Exp^2 fog" GL_EXP2)

    (glutCreateMenu (pod-address 'menu_select))
    (glutAddMenuEntry "Start motion" 1)
    (glutAddMenuEntry "Stop motion" 2)
    (glutAddMenuEntry "Toggle fog" 3)
    (glutAddMenuEntry "Toggle lighting" 4)
    (glutAddSubMenu "Fog type" fog_menu)
    (glutAddMenuEntry "Quit" 5)
    (glutAttachMenu GLUT_RIGHT_BUTTON)

    ;; setup context
    (glMatrixMode GL_PROJECTION)
    (glLoadIdentity)
    (glFrustum -1.0 1.0 -1.0 1.0 1.0 3.0)

    (glMatrixMode GL_MODELVIEW)
    (glLoadIdentity)
    (glTranslatefv #(0.0 0.0 -2.0))

    (glEnable GL_DEPTH_TEST)

    (if useLighting
	(glEnable GL_LIGHTING)
      )
    (glEnable GL_LIGHT0)
    (glLightfv GL_LIGHT0 GL_POSITION lightPos)
    (glLightfv GL_LIGHT0 GL_AMBIENT  lightAmb)
    (glLightfv GL_LIGHT0 GL_DIFFUSE  lightDiff)
    (glLightfv GL_LIGHT0 GL_SPECULAR lightSpec)

;;;    (glLightfv GL_LIGHT0 GL_SPOT_DIRECTION lightDir)
;;;    (glLightf  GL_LIGHT0 GL_SPOT_EXPONENT 80)
;;;    (glLightf  GL_LIGHT0 GL_SPOT_CUTOFF 25)

    (glEnable GL_NORMALIZE)

    (if useFog
	(glEnable GL_FOG)
      )

    (glFogfv GL_FOG_COLOR fogColor)
    (glFogfv GL_FOG_INDEX fogIndex)
    (glFogf GL_FOG_MODE (float GL_EXP))
    (glFogf GL_FOG_DENSITY 0.5)
    (glFogf GL_FOG_START 1.0)
    (glFogf GL_FOG_END 3.0)

    (glEnable GL_CULL_FACE)
    (glCullFace GL_BACK)

    (glShadeModel GL_SMOOTH)

    (glBlendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA)
    (if useLogo
	(glPolygonStipple sgiPattern)
      (glPolygonStipple shadowPattern))

    (glClearColor 0.0 0.0 0.0 1)
    (glClearIndex 0)
;    (glClearDepth 1)

    (glutMainLoop)
    ))

(main)
