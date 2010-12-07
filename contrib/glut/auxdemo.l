;; http://msdn.microsoft.com/library/default.asp?url=/library/en-us/opengl/oglport_0b71.asp

;;
;; Example of an X Window System OpenGL program.   
;; OpenGL code is taken from auxdemo.c in the Platform SDK 
;; 
 
(in-package "GL")

;; X globals, defines, and prototypes 
(setq attributes
 (integer-vector GLX_RGBA GLX_RED_SIZE 8 GLX_GREEN_SIZE 8
  GLX_BLUE_SIZE 8 GLX_DOUBLEBUFFER GLX_DEPTH_SIZE 1 0))

(defun SWAPBUFFERS nil (glxSwapBuffers dpy glwin))
(setq BLACK_INDEX     0)
(setq RED_INDEX       1)
(setq GREEN_INDEX     2)
(setq BLUE_INDEX      4)
(setq WIDTH           300)
(setq HEIGHT          200)
 
;; OpenGL globals, defines, and prototypes 
(setq *latitude* 0 *longitude* 0 *latinc* 0 *longinc* 0 *radius* 0)
(setq GLOBE    1)
(setq CYLINDER 2)
(setq CONE     3)
 
(defun WaitForMapNotify (d e arg)
  (if (and (eq (event-type e) :MapNotify)
	   (eq (event-window arg)))
      GL_TRUE GL_FALSE))
 
(defun main nil
  (let (vi cmap swa cx 
	   (event (instance x::Xevent))
	   (needredraw GL_FALSE)
	   (recalcmodelview GL_TRUE)
	   dummy)

    (setq dpy (x::OpenDisplay 0))
    (if (= dpy 0)
      (warn "could not open display"))
 
    (setq dummy 0)
    (if (= (glXQueryExtension dpy dummy dummy) 0)
        (warn "could not open display"))
 
    ;; find an OpenGL-capable Color Index visual with depth buffer
    (setq vi (glXChooseVisual dpy (x::DefaultScreen dpy) attributes))
    (if (= vi 0)
      (warn "could not get visual"))
 
    ;; create an OpenGL rendering context
    (setq cx (glXCreateContext dpy vi 0 GL_TRUE))
    (if (= cx 0)
      (warn "could not create rendering context\n"))
 
    ;; create an X colormap since probably not using default visual
    (setq vi-visual (sys:peek vi :long))
#-:x86_64
    (setq vi-depth (sys:peek (+ vi 12) :long))
#+:x86_64
    (setq vi-depth (sys:peek (+ vi 20) :integer))
    (setq cmap (x::CreateColormap dpy (x::DefaultRootWindow dpy)
				  vi-visual 0))
    (setq swa (instance x::SetWindowAttributes))
    (setf (x::SetWindowAttributes-colormap swa) cmap)
    (setf (x::SetWindowAttributes-border_pixel swa) 0)
    (setf (x::SetWindowAttributes-event_mask swa)
	  (logior x::ExposureMask x::KeyPressMask x::StructureNotifyMask))

    (setq glwin (x::CreateWindow dpy
				 (x::DefaultRootWindow dpy)
				 0 0 WIDTH HEIGHT 0
				 vi-depth 1 vi-visual
				 #x2808 swa))
;;;    XSetStandardProperties(dpy, glwin, "xogl", "xogl", None, argv,  
;;;                                argc, NULL); 
    ;;(x::SetStandardProperties dpy glwin "xogl" "xogl" 0 0 0 0)
 
    (glXMakeCurrent dpy glwin cx)
 
    (x::MapWindow dpy glwin)
;;;    XIfEvent(dpy,  &event,  WaitForMapNotify,  (char *)glwin); 
     
    (initializeGL WIDTH HEIGHT)
    (resize WIDTH HEIGHT)
    
    ;; Animation loop
    (while t 
      (setq key (make-string 3))
      (while (/= (x::Pending dpy) 0)
        (x::NextEvent dpy event)
	;;(drawScene)
	(print (x::event-type event))
        (case (x::event-type event)
	  (:KeyPress
	   (x::LookupString event 0 0 key 0)
	   (case (sys::peek key 0 :integer)
	     (#xff51	;; XK_Left
	      (setq *longinc* (+ *longinc* 0.5)))
	     (#xff53	;; XK_Right
	      (setq *longinc* (- *longinc* 0.5)))
	     (#xff52	;; XK_Up
	      (setq *latinc* (+ *latinc* 0.5)))
	     (#xff54	;; XK_Down
	      (setq *latinc* (- *latinc* 0.5)))))
	  (:ConfigureNotify
	   (resize (x::event-width event) (x::event-height event)))))
      (drawScene)
      )
    ))
;; for event debug
(defun p-event (ev)
  (dotimes (i (/ (length ev) 4))
    (format t "~8,8X~A"
            (sys::peek (+ (sys::address ev)
#-:x86_64
(+ 8 (* 4 i))
#+:x86_64
(+ 16 (* 4 i))
                          ) :integer)
            (if (= (mod (+ i 1) 8) 0) (format nil "~%") " "))
    ))
 
;; OpenGL code
(defun resize (width height)
  (let (aspect)
    (glViewport 0 0 width height)
    (setq aspect (/ (float width) height))
  
    (glMatrixMode GL_PROJECTION)
    (glLoadIdentity)
    ;;(gluPerspective 45.0 aspect 3.0 7.0 )
    (gluPerspectivefv (float-vector 45.0 aspect 3.0 7.0 ))
    (glMatrixMode GL_MODELVIEW)
    ))
 
(defun createObjects nil
  (let (quadObj)
    (glNewList GLOBE GL_COMPILE)
    (setq quadObj (gluNewQuadric))
    (gluQuadricDrawStyle quadObj GLU_LINE)
    (gluSphere quadObj 1.5 16 16)
    (glEndList)
 
    (glNewList CONE GL_COMPILE)
    (setq quadObj (gluNewQuadric))
    (gluQuadricDrawStyle quadObj GLU_FILL)
    (gluQuadricNormals quadObj GLU_SMOOTH) 
    (gluCylinder quadObj 0.3 0.0 0.6 15 10)
    (glEndList)
 
    (glNewList CYLINDER GL_COMPILE)
    (glPushMatrix)
    (glRotated 90.0 1.0 0.0 0.0)
    (glTranslated 0.0 0.0 -1.0)
    (setq quadObj (gluNewQuadric))
    (gluQuadricDrawStyle quadObj GLU_FILL)
    (gluQuadricNormals quadObj GLU_SMOOTH)
    (gluCylinder quadObj 0.3 0.3 0.6 12 2)
    (glPopMatrix)
    (glEndList)
    ))
 
(defun initializeGL (width height)
  (let (maxObjectSize aspect near_plane far_plane)
    (glClearIndexfv (float-vector BLACK_INDEX))
    (glClearDepth 1.0) 
 
    (glEnable GL_DEPTH_TEST)
 
    (glMatrixMode GL_PROJECTION)
    (setq aspect (/ (float width) height))
    (gluPerspectivefv (float-vector 45.0 aspect 3.0 7.0))
    (glMatrixMode GL_MODELVIEW)
 
    (setq near_plane 3.0
	  far_plane 7.0
	  maxObjectSize 3.0F
	  *radius* (+ near_plane (/ maxObjectSize 2.0)))
 
    (setq *latitude* 0.0
	  *longitude* 0.0
	  *latinc* 6.0
	  *longinc* 2.5)
 
    (createObjects) 
    ))
 
(defun polarView (radius twist latitude longitude) 
  (glTranslated 0.0 0.0 (- radius))
  (glRotated (- twist) 0.0 0.0 1.0)
  (glRotated (- latitude) 1.0 0.0 0.0)
  (glRotated longitude 0.0 0.0 1.0))
 
(defun drawScene () 
  (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))
 
  (glPushMatrix)
 
  (format t "~A > ~A /  ~A > ~A~%" *latitude* *latinc* *longitude* *longinc*)
  (setq *latitude* (+ *latitude* *latinc*))
  (setq *longitude* (+ *longitude* *longinc*))
 
  ;; polarView( radius, 0, latitude, longitude ); 
  (polarView *radius* 0 *latitude* *longitude*)
 
  (glIndexi RED_INDEX)
  (glCallList CONE)
 
  (glIndexi BLUE_INDEX)
  (glCallList GLOBE) 
 
  (glIndexi GREEN_INDEX)
  (glPushMatrix)
  (glTranslated 0.8 -0.65 0.0) 
  (glRotated 30.0 1.0 0.5 1.0)
  (glCallList CYLINDER)
  (glPopMatrix)
 
  (glPopMatrix)
 
  (SWAPBUFFERS))

(in-package "USER")

(gl::main)