;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/geo/loadgeo.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $

(when (member :sunos4.1 *features*)
  (defparameter *GEOLIB* (format nil "~a/SunOS4/lib/libeusgeo.so.0.0" *eusdir*))
  (load-library *GEOLIB*
	      (list "intersection" "geoclasses" "geopack" "geobody"
		    "primt" "compose" "polygon"  "viewing" "viewport"
		    "viewsurface" "hid"
		    "shadow" "bodyrel"	;added Jun/2/96
		    ))
  (setq LIBGEO (car *loaded-modules*))
)


