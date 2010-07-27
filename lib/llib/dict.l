(defvar *dict-file* "/usr/share/lib/dict/words")
(defvar *dict-htab* (make-hash-table :size 1000))

(defun read-dict (&optional (dict-file *dict-file*))
   (with-open-file (f dict-file)
      (let* ((eof (cons nil nil))(w (read f nil eof)))
         (while (not (eq w eof))
	    (setf (gethash w *dict-htab*) w)
	    (setq w (read f nil eof)))
)))

