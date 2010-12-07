#|
/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

/* This program was requested by Patrick Earl; hopefully someone else
   will write the equivalent Direct3D immediate mode program. */
|#

;; porting to euslisp by Kei Okada <k-okada@jsk.t.u-tokyo.ac.jp>

(in-package "GL")
(load "glut.l")

(setq light_diffuse #f(1.0 0.0 0.0 1.0))  ;; Red diffuse light.
(setq light_position #f(1.0 1.0 1.0 0.0)) ;; Infinite light location.
(setq n (make-matrix 6 3
		     (list (list -1 0 0) (list 0 1 0) (list 1 0 0)
			   (list 0 -1 0) (list 0 0 1) (list 0 0 -1))))
(setq faces (make-matrix 6 4
			 (list (list 0 1 2 3) (list 3 2 6 7) (list 7 6 5 4)
			       (list 4 5 1 0) (list 5 6 2 1) (list 7 4 0 3))))
(setq v (make-matrix 8 3))

(defun drawBox nil
  (dotimes (i 6)
    (glBegin GL_QUADS)
    (glNormal3fv (matrix-row n i))
    (glVertex3fv (matrix-row v (round (aref faces i 0))))
    (glVertex3fv (matrix-row v (round (aref faces i 1))))
    (glVertex3fv (matrix-row v (round (aref faces i 2))))
    (glVertex3fv (matrix-row v (round (aref faces i 3))))
    (glEnd)
    ))

(defun-c-callable display () :integer
  (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))
  (drawBox)
  (glutSwapBuffers)
  )

(defun init nil
  ;; Setup cube vertex data. 
  (setf (aref v 0 0) -1 (aref v 1 0) -1 (aref v 2 0) -1 (aref v 3 0) -1)
  (setf (aref v 4 0)  1 (aref v 5 0)  1 (aref v 6 0)  1 (aref v 7 0)  1)
  (setf (aref v 0 1) -1 (aref v 1 1) -1 (aref v 4 1) -1 (aref v 5 1) -1)
  (setf (aref v 2 1)  1 (aref v 3 1)  1 (aref v 6 1)  1 (aref v 7 1)  1)
  (setf (aref v 0 2)  1 (aref v 3 2)  1 (aref v 4 2)  1 (aref v 7 2)  1)
  (setf (aref v 1 2) -1 (aref v 2 2) -1 (aref v 5 2) -1 (aref v 6 2) -1)

  ;; Enable a single OpenGL light.
  (glLightfv GL_LIGHT0 GL_DIFFUSE light_diffuse)
  (glLightfv GL_LIGHT0 GL_POSITION light_position)
  (glEnable GL_LIGHT0)
  (glEnable GL_LIGHTING)

  ;; Use depth buffering for hidden surface elimination.
  (glEnable GL_DEPTH_TEST)

  ;; Setup the view of the cube.
  (glMatrixMode GL_PROJECTION)
  (gluPerspective 40.0 ;; field of view in degree
		      1.0  ;; aspect ratio
		      1.0  ;; Z near
		      10.0 ;;Z far
		      )
  (glMatrixMode GL_MODELVIEW)
  (gluLookAt 0.0 0.0 5.0 ;; eye is at (0,0,5)
		 0.0 0.0 0.0 ;; center is at (0,0,0)
		 0.0 1.0 0.0);; up is in positive Y direction

  ;; Adjust cube position to be asthetic angle.
  (glTranslatefv #f(0.0 0.0 -1.0))
  (glRotatefv #f(60.0 1.0 0.0 0.0))
  (glRotatefv #f(-20.0 0.0 0.0 1.0))
  )

(defun main nil
  (let ((argc "0")
	(argv "0") (argv0 (unix::malloc lisp::sizeof-*)) argv1
	(str "red 3D lighted cube"))
    (sys::poke 1 argc 0 :integer)
    (setq argv1 (make-foreign-string argv0 lisp::sizeof-*))
    (setf (elt argv1 0) 0)
    (sys::poke argv0 argv 0 :integer)
    (glutInit argc argv)
    (glutInitDisplayMode (logior GLUT_DOUBLE GLUT_RGB GLUT_DEPTH))
    (glutCreateWindow (+ (sys:address str) (* lisp::sizeof-* 2)))
    (glutDisplayFunc (pod-address 'display))
    (init)
    (glutMainLoop)
    ))


(in-package "USER")

(gl::main)
