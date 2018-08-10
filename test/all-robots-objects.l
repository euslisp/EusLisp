(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(unless (boundp '*image-build-dir*)
  ;; (setq *image-build-dir* (format nil "/tmp/tmp.~A" (string (gensym))))
  (setq *image-build-dir* (car (piped-fork-returns-list "mktemp -d"))))

(mapcar
 #'(lambda (model-type-name model-func-name)
     (eval
      `(deftest ,(read-from-string (format nil "test-~A" model-func-name))
         (load (format nil "models/irt-all-~A.l" ,model-type-name))
         (unless x::*root* (defun ,model-func-name ())) ;; do not create viwer
         (setq model-viewers (,model-func-name))
         (let (fname (fname-list ""))
           (dolist (viewer model-viewers)
             (send viewer :draw-objects)
             (setq fname (format nil "~A/irt_~A_~A.png" *image-build-dir* ,model-type-name (send viewer :name)))
             (setq fname-list (format nil "~A ~A" fname-list fname))
             (send viewer :viewer :viewsurface :write-to-image-file fname)
             )
           (unix::system (format nil "montage -geometry 100x100+1+1 ~A ~A/irt_all_~A.png"
                                 fname-list *image-build-dir* ,model-type-name))
           ))))
 '("robots" "objects" "scenes")
 '(make-all-robots make-all-objects make-all-scenes))

(run-all-tests)
(exit)
