(defun tmain-end (&rest args)
   (format t ";signal ~s~%" args)
   (throw :end 1))

(defun tmain (n)
   (print n)
   (unix:signal 2 'tmain-end)
   (catch :end
      (while (> n 0)
         (unix:sleep 3)
	 (print (decf n))))
   )
