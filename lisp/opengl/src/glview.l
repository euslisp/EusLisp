;;; -*- lisp -*-
;;; $Header$
;;; glview.l -- openGL eus

(unless (find-package "GL")
    (make-package "GL")
 )

(in-package "GL")

(require :geoclasses "lisp/geo/geoclasses.l")
(require :gldecl "lisp/opengl/src/gldecl.l")
;; (require :auxconst "lisp/opengl/src/auxconst.l")
;; (require :auxforeign "lisp/opengl/src/auxforeign.l")
(require :glforeign "lisp/opengl/src/glforeign.l")
(require :glconst "lisp/opengl/src/glconst.l")
;(require :glprim "lisp/opengl/src/glprim.l")
(require :gluforeign "lisp/opengl/src/gluforeign.l")
(require :glutil "lisp/opengl/src/glutil.l")
(require :gluconst "lisp/opengl/src/gluconst.l")
(require :eglforeign "lisp/opengl/src/eglforeign.l")

;; (use-package "GEO")
(export '(gldraw glviewsurface colormaterial lightsource
		*light0* *light1* *light2*))

;; (defvar *fovy* 45.0)			;Field of view angle,	in degrees, in the y direction.
(defvar *perspective-far* 30000.0)
(defvar *perspective-near* 200.0)
(defvar *light0*)
(defvar *light1*)
(defvar *light2*)
(defvar *attributelist*
   (integer-vector glx_rgba glx_red_size 1 glx_green_size 1
                   glx_blue_size 1 glx_doublebuffer glx_depth_size 1 0))


(export '(*perspective-far* *perspective-near*))

(defmethod colormaterial
 (:create (&key ((:name nm))
		((:color color) (float-vector 0.3 0.5 0.7 1)) 
		((:ambient amb) (scale 0.1 color))
		((:diffuse dif) ;; normally, diffuse and ambient are the same.
		    (scale 1.0 color))
		((:specular spec) (scale 0.2 dif))
		((:emission emit)  ;; in case there is no lighting around
		    (scale 0.1 dif))
		((:shininess shi) 20.0)
		((:transparency trans) 0.0))
    "&key (color #f(0.5 0.7 0.9 1.0)) ambient diffuse specular emssion shininess transparency"
     (if nm (send self :name nm))
     (setf ambient (copy-seq amb)
	   diffuse (copy-seq dif)
	   specular (copy-seq spec)
	   emission (copy-seq emit)
	   shininess shi
	   transparency trans)
     self)
 (:ambient (&optional amb (amb2 amb) (amb3 amb) (amb4 1))
     (cond ((null amb) ambient)
	   ((numberp amb) (setq ambient (float-vector amb amb2 amb3 amb4)))
	   ((float-vector-p amb) (setq ambient (copy-seq amb)))
	   (t (error
		 "number of float-vector expcted for colormaterial :ambient"))))
 (:diffuse (&optional dif (dif2 dif) (dif3 dif) (dif4 1))
     (cond ((null dif) diffuse)
	   ((numberp dif) (setq diffuse (float-vector dif dif2 dif3 dif4)))
	   ((float-vector-p dif) (setq diffuse (copy-seq dif)))
	   (t (error
		 "number of float-vector expcted for colormaterial :diffuse"))))
 (:specular (&optional spec (spec2 spec) (spec3 spec) (spec4 1))
     (cond ((null spec) specular)
	   ((numberp spec) (setq specular (float-vector spec spec2 spec3 spec4)))
	   ((float-vector-p spec) (setq specular (copy-seq spec)))
	   (t (error
		 "number of float-vector expcted for colormaterial :specular"))))
 (:emission (&optional emit (emit2 emit) (emit3 emit) (emit4 1))
     (cond ((null emit) emission)
	   ((numberp emit) (setq emission (float-vector emit emit2 emit3 emit4)))
	   ((float-vector-p emit) (setq emission (copy-seq emit)))
	   (t (error
		 "number of float-vector expcted for colormaterial :emission"))))
 (:shininess (&optional shi)
      (cond ((null shi)  shininess)
	    ((numberp shi) (setq shininess shi))
	    (t (error "number expected for colormaterial :shininess"))))
 (:transparency (&optional trans)
      (cond ((null trans)  transparency)
	    ((numberp trans) (setq transparency trans))
	    (t (error "number expected for colormaterial :transparency"))))
 (:opengl ()
      (glMaterialfv GL_FRONT_AND_BACK GL_AMBIENT ambient)
      (glMaterialfv GL_FRONT_AND_BACK GL_DIFFUSE diffuse)
      (glMaterialfv GL_FRONT_AND_BACK GL_SPECULAR specular)
      (glMaterialfv GL_FRONT_AND_BACK GL_EMISSION emission)
      (glMaterialfv GL_FRONT_AND_BACK GL_SHININESS (float-vector shininess))
      )
 )

	  
(defmethod lightsource
 (:create (index &key ((:ambient amb) (float-vector 0.5 0.5 0.5 1.0))
			((:diffuse dif) (float-vector 0.8 0.8 0.8 0.8))
			((:specular spec) (float-vector 0.7 0.7 0.7 1.0))
			((:position pos) (float-vector 1000.0 2000.0 100000.0 0.0)))
     (setq id index)
     (setq ambient amb
	   diffuse dif
	   specular spec
	   position pos)
     self)
 (:light-id () (+ GL_LIGHT0 id))
 (:ambient (&optional amb (amb2 amb) (amb3 amb) (amb4 1))
     (cond ((null amb) ambient)
	   ((numberp amb) (setq ambient (float-vector amb amb2 amb3 amb4)))
	   ((float-vector-p amb) (setq ambient (copy-seq amb)))
	   (t (error
		 "number of float-vector expcted for lightsource :ambient"))))
 (:diffuse (&optional dif (dif2 dif) (dif3 dif) (dif4 1))
     (cond ((null dif) diffuse)
	   ((numberp dif) (setq diffuse (float-vector dif dif2 dif3 dif4)))
	   ((float-vector-p dif) (setq diffuse (copy-seq dif)))
	   (t (error
		 "number of float-vector expcted for lightsource :diffuse"))))
 (:specular (&optional spec (spec2 spec) (spec3 spec) (spec4 1))
     (cond ((null spec) specular)
	   ((numberp spec) (setq specular (float-vector spec spec2 spec3 spec4)))
	   ((float-vector-p spec) (setq specular (copy-seq spec)))
	   (t (error
		 "number of float-vector expcted for lightsource :specular"))))
 (:position (&optional p)
     (cond ((null p) position)
	   ((float-vector-p p) (setq position p))))
 (:move (v) (v+ position v position))
 (:enable () (glEnable (send self :light-id)))
 (:disable () (glDisable (send self :light-id)))
 (:opengl ()
    (let ((light-id (+ GL_LIGHT0 id)))
	 (glLightfv light-id GL_AMBIENT ambient)
	 (glLightfv light-id GL_DIFFUSE diffuse)
	 (glLightfv light-id GL_SPECULAR specular)
	 (glLightfv light-id GL_POSITION position)
	 (glEnable  light-id)
	)
    id)
  )


;;;
;;; glviewsurface -- globject
;;;

(defmethod glviewsurface
  (:create (&rest args
	    &key (x 0) (y 0) (size 256) ((:width w) size) ((:height h) size)
		 ((:glcon shared-glcon) 0) (title (string (gensym "GL")))
		 &allow-other-keys)
	   ;; (format t "x y w h -> ~a ~a ~a ~a~%" x y w h)
	   ;; (if posx (setf x posx))
	   ;; (if posy (setf y posy))
	   (send self :x x)
	   (send self :y y)
	   (send self :width w)
	   (send self :height h)
	   ;;(format t "glviewsurface: create ~a ~a ~a ~a~%" x y x::width x::height)
	   (setq visualinfo
              (glXChooseVisual x::*display* (x::DefaultScreen x::*display*)
                                *attributelist*))
           (setq glcon (glXCreateContext x::*display* visualinfo shared-glcon GL_TRUE))
#-(or :x86_64 :aarch64)
	   (send-super* :create
                        :depth (sys:peek (+ visualinfo 12) :long)
                        :visual (sys:peek visualinfo :long)
                        :title title args)
#+(or :x86_64 :aarch64)
	   (send-super* :create
                        :depth (sys:peek (+ visualinfo 20) :integer)
                        :visual (sys:peek visualinfo :long)
                        :title title args)

           (glXMakeCurrent x::*display* x::drawable glcon)

	   (send self :3d-mode)
	   
	   ;; (glClearColorfv (float-vector 0.0 0.0 0.0 0.0))
	   ;; (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))
	   ;; (glColor3fv (float-vector 1.0 1.0 1.0))

	   ;; The default light is directional along Z
	   (setq *light0* (instance lightsource :create 0
			:ambient (float-vector 0.2 0.2 0.2 0.0)
			:diffuse (float-vector 0.5 0.5 0.5 0.0)
			:specular (float-vector 0.3 0.3 0.3 0.0)
			:position (float-vector 0.0 0.0 1.0 0.0)))
	   (setq  *light1* (instance lightsource :create 1
			:ambient (float-vector 0.3 0.3 0.3 1.0)
			:diffuse (float-vector 0.6 0.1 0.1 0.8)
			:specular (float-vector 0.3 0.3 0.3 1.0)
			:position (float-vector 5000.0 1000.0 7000.0 1.0)))
	   (setq  *light2*  (instance lightsource :create 2
			:ambient (float-vector 0.3 0.3 0.3 1.0)
			:diffuse (float-vector 0.1 0.1 0.7 0.0)
			:specular (float-vector 0.3 0.3 0.3 1.0)
			:position (float-vector -15000.0 0.0 2000.0 1.0)))
	   (glEnable GL_LIGHTING)
	   (send *light0* :opengl)
	   (send *light1* :opengl)
	   (send *light2* :opengl)
	     
	   (glFrontFace GL_CW)
	   (glEnable GL_AUTO_NORMAL)
	   (glEnable GL_NORMALIZE)
	   (glDepthFunc GL_LESS)
	   (glEnable GL_DEPTH_TEST)
	   (glShadeModel GL_SMOOTH)
	   ;; (glEnable GL_COLOR_MATERIAL) ; not needed

	   ;; texturemap stuff...
	   (glPixelStorei GL_UNPACK_ALIGNMENT 1)
	   (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_WRAP_S GL_REPEAT)
	   (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_WRAP_T GL_REPEAT)
	   
	   (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_MAG_FILTER GL_NEAREST)
	   (glTexParameteri GL_TEXTURE_2D GL_TEXTURE_MIN_FILTER GL_NEAREST)
	   (glTexEnvi GL_TEXTURE_ENV GL_TEXTURE_ENV_MODE GL_MODULATE)
	   ;;(glTexEnvi GL_TEXTURE_ENV GL_TEXTURE_ENV_MODE GL_DECAL)

	   ;; initialize window contents
	   (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))
	   (glxSwapbuffers x::*display* x::drawable)
	   (glClear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))
	   (glxSwapbuffers x::*display* x::drawable)

	   ;; Tesslation support

	   (setf *tess-obj* (gluNewTess))
	   (gluTessCallbackl *tess-obj* GLU_BEGIN (#'glBegin . entry) (#'glBegin . entry2))
	   ;;(gluTessCallbackl *tess-obj* GLU_VERTEX (#'glVertex3dv . entry) (#'glVertex3dv . entry2))
	   (gluTessCallbackl *tess-obj* GLU_VERTEX (#'tess_vertex_cb . entry) (#'tess_vertex_cb . entry2))
	   (gluTessCallbackl *tess-obj* GLU_END (#'glEnd . entry) (#'glEnd . entry2))

	   ; (setf window (auxxwindow))
	   ;(setf x::drawable (auxxwindow))
	   self)
  (:material (ambient &optional diffuse specular emission shininess)
      (when (null diffuse)
	  (setq diffuse (colormaterial-diffuse ambient)
		specular (colormaterial-specular ambient)
		emission (colormaterial-emission ambient)
		shininess (colormaterial-shininess ambient)
		ambient (colormaterial-ambient ambient)))
      (glMaterialfv GL_FRONT_AND_BACK GL_AMBIENT ambient)
      (glMaterialfv GL_FRONT_AND_BACK GL_DIFFUSE diffuse)
      (glMaterialfv GL_FRONT_AND_BACK GL_SPECULAR specular)
      (glMaterialfv GL_FRONT_AND_BACK GL_EMISSION emission)
      (glMaterialfv GL_FRONT_AND_BACK GL_SHININESS (float-vector shininess))
      )
  (:color (color-vector)
	(if (derivedp color-vector linecolor)
	    (setf color-vector (linecolor-color color-vector)))
	  (case (length color-vector)
		(3
		 (glcolor3fv color-vector))
		(4
		 (glcolor4fv color-vector))
		(t
		 (error ":color"))))
  (:window ()
	   x::drawable #|window|# )
  (:3d-mode ()
	    (if (> x::width x::height)
		(glViewport 0 (- (/ (- x::width x::height) 2)) (- x::width 1)
					 (- x::width 1))
	      (glViewport (- (/ (- x::height x::width) 2)) 0 (- x::height 1)
					 (- x::height 1)))
	    (glMatrixMode GL_PROJECTION)
	    (glLoadIdentity)
	    ;; folowing lines are unnecessary since resetperspective is always
	    ;; called to set projection each time 3d objects are drawn
	    #|
	    (gluPerspectivefv (float-vector *fovy* 
				(/ (float x::width) (float x::height)) 
				    *perspective-near* *perspective-far*))
	    (gluLookAtfv (float-vector 1000.0 500.0 1500.0
					  0.0 0.0 500.0
					  0.0 0.0 1.0))
	    |#
	    (glEnable GL_DEPTH_TEST)
	    (glEnable GL_LIGHTING)
	    (glMatrixMode GL_MODELVIEW)
	    (glLoadIdentity))
  (:2d-mode (&key ((:push apush) nil))
	    (glViewport 0 0 x::width x::height)
	    (glMatrixMode GL_PROJECTION)
	    (if apush (glPushMatrix))
	    (glLoadIdentity)
	    (glorthofv (float-vector 0 x::width 0 x::height -1.0 1.0))
	    (glDisable GL_DEPTH_TEST)
	    (glDisable GL_LIGHTING)
	    (glMatrixMode GL_MODELVIEW)
	    (if apush (glPushMatrix))
	    (glLoadIdentity))
   (:pop-mode ()
	      (glMatrixMode GL_PROJECTION)
	      (glPopMatrix)
	      (glMatrixMode GL_MODELVIEW)
	      (glPopMatrix))

;  (:clear (mask &key (color))
;	  (if color
;	      (glClearColorfv color))
;	  (glClear mask))
;  (:init (&key &allow-other-keys)
;	 self)
  (:height (&optional h)
	   (when h
		 (setf x::height h))
	   x::height)
  (:width (&optional w)
	  (when w
	       (setf x::width w))
	  x::width)
  (:pos ()
	(integer-vector x y))
  (:x (&optional nx)
      (when nx
	    (setf x nx))
      x)
  (:y (&optional ny)
      (when ny
	    (setf y ny))
      y)
  (:clear () (glclear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT)))
  (:glflush ()
        (glflush)
        (glxSwapbuffers x::*display* x::drawable))
  )

(defmethod glviewsurface
  (:point (x y)
	  (send self :2d-mode :push t)
	  (glBegin GL_POINTS)
	  (glVertex2fv (float-vector x (- x::height y)))
	  (glEnd)
	  (send self :3d-mode)
	  (send self :pop-mode))
  (:line (x1 y1 x2 y2)
	 (send self :2d-mode :push t)
	 (glBegin GL_LINES)
	 (glvertex2fv (float-vector x1 (- x::height y1)))
	 (glVertex2fv (float-vector x2 (- x::height y2)))
	 (glEnd)
	 (send self :3d-mode)
	 (send self :pop-mode))
  (:3d-point (pos)
	    (glDisable GL_DEPTH_TEST)
	    (glDisable GL_LIGHTING)
	    (glBegin GL_POINTS)
	    (glVertex3fv pos)
	    (glEnd)
	    (glEnable GL_DEPTH_TEST)
	    (glEnable GL_LIGHTING))
  (:3d-line (start end)
	    ;;(glDisable GL_DEPTH_TEST)
	    (glDisable GL_LIGHTING)
	    (glBegin GL_LINES)
	    (glVertex3fv start)
	    (glVertex3fv end)
	    (glEnd)
	    ;;(glEnable GL_DEPTH_TEST)
	    (glEnable GL_LIGHTING))
  (:draw-faces (faces)
	       (mapc #'(lambda (f)
			 (draw-face f nil nil))
		     faces))
  (:rectangle (x y w h)
	      (send self :2d-mode :push t)
	      (glBegin GL_POLYGON)
	      (glVertex2fv (float-vector x y))
	      (glVertex2fv (float-vector x (+ y h)))
	      (glVertex2fv (float-vector (+ x w) (+ y h)))
	      (glVertex2fv (float-vector (+ x w) y))
	      (glEnd)
	      (send self :3d-mode)
	      (send self :pop-mode))
  )

(defun geo::default-viewsurface (&rest args)
  (send-lexpr (instantiate glviewsurface) :create args))

(defmethod glviewsurface
  (:draw-point (p)
	       (send self :point (elt p 0) (elt p 1)))
  (:draw-line (from to)
	      (send self :line (aref from 0) (aref from 1)
		    (aref to 0) (aref to 1)))
  (:draw-rectangle (point width height)
	   (send self :rectangle (elt point 0) (elt point 1) width height))
  )

;; overwrite :draw-one and :draw-faces method of class viewer

(defmethod geo:viewer
   (:draw-one   (thing info)
    (cond
     ((numberp thing) nil)
     ((listp thing)
      (cond ((float-vector-p (car thing)) 
	     (case (length (car thing))
		   (2 (send geo::surface :line 
			    (elt (car thing) 0) (elt (car thing) 1)
			    (elt (second thing) 0) (elt (second thing) 1)))
		   (3 (send geo::surface :3d-line     (car thing) (second thing)))
		   (t (error "draw vector?"))))
	    (t (dolist (x thing)  (send self :draw-one x info)))))

     ((find-method thing :draw)
	(send thing :draw self))

     ((find-method thing :drawners)
        (if (find-method thing :worldcoords)
	    (send thing :worldcoords))
	(send self :draw-one (send thing :drawners) info))

     ((derivedp thing colormaterial)
	(send thing :opengl))

     ((derivedp thing linecolor)
      (send geo::surface   :color    (linecolor-color thing)))

     ((derivedp thing geo::line) (send self :draw-edge thing))

     ((derivedp thing geo::edge-image)  (send self :draw-edge-image thing))

     ((derivedp thing lightsource)
	(print 'lightsource) (send thing :opengl))

     ;; body
     ((derivedp thing geo::body)
      (send thing :worldcoords)
      (if (derivedp geo::surface glviewsurface)
	  (draw-body self thing)
	  (let ((color (send thing :color)))
	     (dolist (e (send thing :visible-edges geo::eye))
	        (send self :draw-edge e color)) ) )
      )
     ((derivedp thing geo::faceset)
      (send thing :worldcoords)
      (if (derivedp geo::surface glviewsurface)
	  (draw-body self thing)
	  (let ((color (send thing :color)))
	     (dolist (e (send thing :edges))
	        (send self :draw-edge e color)) ) )
      )

     ((derivedp thing geo::face) (send self :draw-faces (list thing)))
     ((derivedp thing geo::polygon)
	(dolist (e (send thing :edges))   (send self :draw-edge e)))
     ((float-vector-p thing) (send self :draw-star thing) info)
     ((coordinates-p thing) (send self :draw-axis (send thing :worldcoords) info))
     ((and (boundp '2dlnseg) (derivedp thing 2dlnseg))	; UTYO
	 (send self :draw-2dlnseg thing))
     ))

   (:draw-faces (flist &optional (normal-clip nil) color)
		(mapc #'(lambda (f) (draw-face f nil nil)) flist))
   )

(defun resetperspective (view surface)
  "(viewing surface) set viewing/viewport parameter to GL"
  (glMatrixMode GL_PROJECTION)
  (glLoadIdentity)
  (let* ((viewpoint (send view :viewpoint))
	 (view-scale (max 10 (norm viewpoint)))
	 (view-direction (v+ (scale view-scale (send view :view-direction)) viewpoint))
	 (view-up (send view :view-up)))
    ;; the following should get aspect ration from viewport
    (gluPerspectivefv (float-vector (rad2deg (send view :fovy))
				    #|(/ (float (send surface :width))
					      (float (send surface :height)))|#
				   1.0
				    *perspective-near* *perspective-far*))
    (gluLookAtfv (concatenate vector viewpoint view-direction view-up)))
  (glMatrixMode GL_MODELVIEW))

(defun gldraw (&rest things)
  (let ((vwr  (if (derivedp (car things) geo:viewer)
		  (car things)
		  geo:*viewer*)) )
    (resetperspective (send vwr :viewing) (send vwr :viewsurface))
    (cls vwr)
    (apply #'geo::draw things)
    (swapb (geo::viewer-surface vwr))) )

(defun swapb (&optional (vsurf *viewsurface*))
#|
  (glflush)
  (auxSwapBuffers)	; (glxSwapbuffers (auxxdisplay) (auxxwindow))
|#
  (send vsurf :glflush)
  )

;(defun cls ()
;  (glclear (logior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT)))

(defun position-light (light x y z)
  (case light
	(0
	 (glLightfv GL_LIGHT0 GL_POSITION (float-vector x y z 0.0)))
	(1
	 (glLightfv GL_LIGHT1 GL_POSITION (float-vector x y z 0.0)))
	(2
	 (glLightfv GL_LIGHT2 GL_POSITION (float-vector x y z 0.0)))
	(3
	 (glLightfv GL_LIGHT3 GL_POSITION (float-vector x y z 0.0)))
	(4
	 (glLightfv GL_LIGHT4 GL_POSITION (float-vector x y z 0.0)))
	(5
	 (glLightfv GL_LIGHT5 GL_POSITION (float-vector x y z 0.0)))
	(6
	 (glLightfv GL_LIGHT6 GL_POSITION (float-vector x y z 0.0)))
	(7
	 (glLightfv GL_LIGHT7 GL_POSITION (float-vector x y z 0.0)))
	(t
	 (error (format nil "unkown light number ~a" light)))))



(provide :glview "@(#)$Id$")
