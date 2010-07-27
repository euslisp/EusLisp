;; 
;; Example of body composition (1988).
;; it takes about 21 seconds to execute this function on sparc/330.
;;

(defun make-part1 ()
    (let (base top pole1 pole2 pole3 pole4 pln r1 part1)
	(setq base (make-cube 50 50 6))
	(setq top  (make-cube 48 48 6))
	(send top :translate #f(0 0 10))
	(setq pole1 (make-cylinder 4 15 :segments 22))
	(setq pole2 (copy-object pole1))
	(setq pole3 (copy-object pole1))
	(setq pole4 (copy-object pole1))
	(send pole1 :translate #f(15 15 2))
	(send pole2 :translate #f(-15 15 2))
	(send pole3 :translate #f(-15 -15 2))
	(send pole4 :translate #f(15 -15 2))
	(setq r1 (body+ base pole1 pole2 pole3 pole4 top))
	(setq pln (make-plane :normal (normalize-vector #f(1 2 8))
			      :point #f(0 0 8)))
	(setq part1 (body/ r1 pln))
	(send part1 :magnify 10.0))
    )




