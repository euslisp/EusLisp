(defclass keyed-object-list  :slots (object-list klass try))

(defmethod keyed-object-list
 (:get (&optional key)
   (if key 
	(find key object-list :key #'(lambda (x) (send x :key)))
        (if (< (length object-list) 1)
	    nil
            (prog1 (nth try object-list)
	           (inc try)
	           (if (>= try (length object-list)) (setq try 0))))))
 (:new (key)
   (let ((g (find key object-list :key #'(lambda (x) (send x :key)))))
     (if g
	 g
         (progn
            (setq g (instantiate klass))
	    (send g :key key)
	    (setq object-list (nconc object-list (list g)))
	    g))))
 (:add (obj)
   (let ((key (send obj :key)))
     (if (find key object-list :key #'(lambda (x) (send x :key)))
	 nil
	 (setq object-list (nconc object-list (list obj))))))
 (:keys ()
   (mapcar #'(lambda (x) (send x :key)) object-list))
 (:remove (key)
   (setq object-list
	 (delete (send self :get key) object-list))
   (if (>= try (length object-list)) (setq try 0)))
 (:reset-try (&optional (n 0)) (setq try n))
 (:init (c)
   (setq object-list nil try 0 klass c)
   self))

