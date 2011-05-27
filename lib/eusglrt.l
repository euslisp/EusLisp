;; OpenGL interface and libraries
;;
;; SunOS&Mesa
;;(unless (find-package "GL") (make-package "GL"))
;;(in-package "GL")
;;(when (and 
;;       (substringp "gl" (pathname-name *program-name*))
;;       (push :GL *features*)
;;       (use-package "GEOMETRY")
;;       (sys::exec-module-init "oglforeign")
;;       (sys::exec-module-init "gldecl" "openGL/loadgl.l")
;;       )
;;      (unless (find-symbol "*LIBGL*")
;;	      (sys::exec-module-init "glprim")
;;	      (sys::exec-module-init "glview")
;;	      )
;;      (in-package "USER")
;;      (sys::exec-module-init "floatdouble")
;;      (import '(gl::glviewsurface gl::resetperspective gl::gldraw
;;		gl::swapb gl::glcls gl::colormaterial gl::linecolor
;;		gl::position-light))
;;      )
;; irix
   (push :GL *features*)
   (sys::exec-module-init "oglforeign" "opengl/src/loadgl.l")
   (in-package "GL")
   (use-package "GEOMETRY")
   (unless (find-symbol "*LIBGL*") ; for SunOS4 with .so bug
	   (sys::exec-module-init "gldecl" "opengl/src/gldecl.l")
	   (sys::exec-module-init "glconst" "opengl/src/glconst.l")
;;	   (sys::exec-module-init "auxconst" "lisp/opengl/src/auxconst.l")
	   (sys::exec-module-init "glforeign" "opengl/src/glforeign.l")
	   (sys::exec-module-init "gluconst" "opengl/src/gluconst.l")
	   (sys::exec-module-init "gluforeign" "opengl/src/gluforeign.l")
	   (sys::exec-module-init "glxconst" "opengl/src/glxconst.l")
	   (sys::exec-module-init "glxforeign" "opengl/src/glxforeign.l")
;;	   (sys::exec-module-init "auxforeign" "opengl/src/auxforeign.l")
	   (sys::exec-module-init "eglforeign" "opengl/src/eglforeign.l")
	   (sys::exec-module-init "eglfunc")
	   (sys::exec-module-init "glutil" "opengl/src/glutil.l")
	   (sys::exec-module-init "gltexture" "opengl/src/gltexture.l")
	   (sys::exec-module-init "glprim" "opengl/src/glprim.l")
	   (sys::exec-module-init "gleus" "opengl/src/gleus.l")
	   (sys::exec-module-init "glview" "lisp/opengl/src/glview.l")
           (sys::exec-module-init "toiv" "lisp/opengl/src/toiv.l")
           )
   (in-package "USER")
   (import '(gl::glviewsurface 
	  gl::resetperspective 
          gl::gldraw
	  gl::swapb 
	  gl::glcls 
	  gl::colormaterial 
	  gl::colormaterial-ambient 
	  gl::colormaterial-diffuse
	  gl::colormaterial-specular
	  gl::colormaterial-emission
	  gl::colormaterial-shininess
	  gl::linecolor
	  gl::linecolor-color
	  gl::position-light))
   
   (in-package "USER")
   (import '(gl:glviewsurface gl::resetperspective gl:gldraw
        	gl::swapb gl::glcls gl:colormaterial gl::linecolor
   		gl::position-light))


