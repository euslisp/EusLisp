(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(setq sys::*gc-hook* #'(lambda (a b) (format *error-output* "GC! free:~A  tota:~A~%" a b)))

;(setq lisp::*error-handler*
;      #'(lambda (&rest args) (warning-message 1 "~A~%" args) (exit 1)))

#+:jsk
(pickview)
#-:jsk
(make-irtviewer)
(setq *box* (make-cube 100 100 100))
(objects (list *box*))

(deftest read-img
  (let ((dir (format nil "~A/img/" *eusdir*)))
    (dolist (file (and (lisp::directory-p dir) (directory dir)))
      (let ((fname (format nil "~A/img/~A" *eusdir* file)) img)
	(format *error-output* "loading ~A~%" fname)
	#+:jsk
	(if (substringp ".jpg" file) (setq img (image::read-jpg-file fname)))
	#-:jsk
	(setq img (read-image-file fname))
	(when img
	  (format t "w:~d, h:~d, d:~d~%" (send img :width) (send img :height) (send img :depth))
	  (send img :to16)
	  (send *box* :paste-texture-to-face
		(find :top (send *box* :faces) :key #'(lambda (x) (cadr (send x :face-id))))
		:image img)
	  (objects (list *box*))
	  )
	))
    ))

(run-all-tests)
(exit)

