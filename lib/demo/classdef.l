(defun classdef (c)
  (let ((s (send c :super)) sname svars)
     `(defclass ,(send c :name)
	:super ,(if s (send s :name) nil)
	:slots ,(set-difference (coerce (send c :slots) cons)
				(coerce (if s (send s :slots) nil) cons)))
))

(defun classdef-file (file)
   (with-open-file (f file :direction :output)
	(dolist (c (reverse (sys:list-all-classes)))
	   (pprint (lisp::classdef c) f)
	   (pprint (send c :method-names) f)
	   (terpri f))))


