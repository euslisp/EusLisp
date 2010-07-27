;;;; misc.l

;; 
;; redirect *standard-output* to a file and evaluate forms
;;
(defmacro file (file &rest forms)
   `(with-open-file (*standard-output* ,file :direction :output)
        . ,forms))


(defun make-polygon (verts)
   (instance polygon :init :vertices verts))

