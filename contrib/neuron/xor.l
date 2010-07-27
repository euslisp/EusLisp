;;======================================================================
;;Section: XOR-net
;;----------------------------------------------------------------------

(in-package 'nn)

(defvar *xor-net*)
(setq *xor-net*
      (layered-network xor-net
	(parameters
          (temperature 1.0)
	  (alpha 0.8)
	  (eta 0.1))
	(layers
	  (input 2)
	  (hidden 4)
	  (output 1))
	(links
	  ((input hidden))
	  ((hidden output)))))

(defvar *xor-dat*)
(setq *xor-dat*
      '((#f(0 0) #f(0))
	(#f(0 1) #f(1))
	(#f(1 0) #f(1))
	(#f(1 1) #f(0))))

(defun init-xor-net (net)
  (with-layered-network (:net net)
    (init-layer (:net layer hidden) -0.5 0.5)
    (init-layer (:net layer output) -0.5 0.5)
    (init-link (:net link (input hidden)) -1.0 1.0)
    (init-link (:net link (hidden output)) -1.0 1.0)))

(defun fp-xor-net (net inp)
  (with-layered-network (:net net)
    (v= (:net layer input output) inp)
    (f-propagate-sigmoid-layer (:net layer hidden))
    (f-propagate-sigmoid-layer (:net layer output))
    (:net layer output output)))

(defun bp-xor-net (net tgt)
  (with-layered-network (:net net)
    (b-propagate-sigmoid-output-layer (:net layer output) tgt)
    (b-propagate-sigmoid-hidden-layer (:net layer hidden))
    (learn-layer (:net layer hidden) (:net alpha) (:net eta))
    (learn-layer (:net layer output) (:net alpha) (:net eta))
    (learn-link (:net link (hidden output))(:net alpha) (:net eta))
    (learn-link (:net link (input hidden))(:net alpha) (:net eta))))

(defun fbp-xor-net (net inp tgt)
  (fp-xor-net net inp)
  (bp-xor-net net tgt))

(defun cycle-fbp-xor-net (net &optional (silent nil) (tset *xor-dat*))
  (dolist (tpair tset)
    (fbp-xor-net net (first tpair) (second tpair))
    (if (not silent)
	(with-layered-network (:net net) 
	  (format t "~a -> ~a : ~a ~%"
		  (:net layer input output)
		  (:net layer output output)
		  (second tpair))))))

(defun loop-fbp-xor-net (net n &optional (silent nil) (tset *xor-dat*)) 
  (dotimes (i n)
    (cond ((or (null silent)
	       (and (numberp silent)
		    (zerop (mod (1+ i) silent))))
	   (format t "~a:~%" i)
	   (cycle-fbp-xor-net net nil tset))
	  (t 
	   (cycle-fbp-xor-net net t tset)))))

(defun foo (&optional (xor-net *xor-net*) (count 10000))
  (init-xor-net xor-net)
  (loop-fbp-xor-net xor-net 10000 1000))





