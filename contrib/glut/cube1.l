;; porting to euslisp by Kei Okada <k-okada@jsk.t.u-tokyo.ac.jp>

(in-package "GL")
(load "cube.l")

(defun drawBox1 nil
  (let (b)
    (setq b (make-cube 2 2 2))
    (dolist (f (send b :faces))
      (glBegin GL_QUADS)
      (glNormal3fv (send f :normal))
      (dolist (v (cdr (send f :vertices)))
	(glVertex3fv v))
      (glEnd)
      )
    ))

(defun-c-callable display1 () :integer
  (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))
  (drawBox)
  (glutSwapBuffers)
  )

(in-package "USER")
(setq argc "0"
      (argv "0") (argv0 (unix::malloc lisp::sizeof-*)) argv1
      (str "red 3D lighted cube"))
(sys::poke 1 argc 0 :integer)
(setq argv1 (make-foreign-string argv0 lisp::sizeof-*))
(setf (elt argv1 0) 0)
(sys::poke argv0 argv 0 :integer)
(gl::glutInit argc argv)
(gl::glutInitDisplayMode (logior GLUT_DOUBLE GLUT_RGB GLUT_DEPTH))
(gl::glutCreateWindow (+ (sys:address str) (* lisp::sizeof-* 2)))
(gl::glutDisplayFunc (pod-address 'gl::display1))
(gl::init)
(glutMainLoop)
