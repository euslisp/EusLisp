;;; mesa version of loadgl

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

(defconstant *mesa* t)

(defvar *top* (unix:getenv "HOME"))

#| -- should be like this... |#
(defvar *libgl* (format nil "~a/src/Mesa/lib/libMesaGL.so" *top*))

(defvar *libglu* (format nil "~a/src/Mesa/lib/libMesaGLU.so" *top*))

(defvar *libaux* (format nil "~a/src/Mesa/lib/libMesaaux.so" *top*))

(defvar *libtk* (format nil "~a/src/Mesa/lib/libMesatk.so" *top*))

#|
(defvar *libgl* (format nil "~a/src/Mesa/lib/libMesaall.so" *top*))

(defvar *libglu* (format nil "~a/src/Mesa/lib/libMesaall.so" *top*))

(defvar *libaux* (format nil "~a/src/Mesa/lib/libMesaall.so" *top*))

(defvar *libtk* (format nil "~a/src/Mesa/lib/libMesaall.so" *top*))
|#

(load "loadgl")
