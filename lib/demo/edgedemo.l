;; edgedemo.l
;; load this file from *eusdir*
;; (c) 1992, Toshihiro Matsui, ETL

(load-files
	"vision/piximage"
	"vision/pbmfile"
	"vision/pixword"
	"vision/edge/edge"
	"view")
(load "vision/edge/eusedge"
      :ld-option "vision/edge/step1/step1yx.o vision/edge/step2/step2r.o -lm")

(send *viewsurface* :resize 512 480)
(xflush)

(defun edgedemo (img)
   (labels ((inquire (s)
		   (format t "~A: " s)
		   (finish-output t)
		   (read)) )
      (let ((imgx (make-ximage img)) method th1 th2 run eimg)
         (while t
	    (setq method (inquire "method (1,2,3)"))
	    (if (eql method 'q) (return-from edgedemo nil))
	    (setq th1 (inquire "intensity (10..50)"))
	    (setq th2 (inquire "weak edge (5..20)"))
	    (setq run (inquire "length (1..30)"))
            (setq eimg (edge1  img  method th1 th2 run))
	    (overlay-edge imgx eimg)
	    (send *viewsurface* :image-string 3 10
		(format nil "~a edge=~a weak=~a length=~a"
		    (cdr (assoc method
				'((0 . grad3) (1 . grad3) (2 . prewitt)  (3 . sobel))))
		    th1 th2 run))
	    (xflush)))) )




(setq *red-gc* (x::make-color-gc "red"))
(setq *green-gc* (x::make-color-gc "green"))
(setq *blue-gc* (x::make-color-gc "blue"))
(setq *yellow-gc* (x::make-color-gc "yellow"))

(setq img1 (read-pnm "vision/images/scene1.pgm"))
(setq img1x (make-ximage img1))

(send img1x :display)
(setq img1e (edge1 img1 1 20 10 10))
(overlay-edge img1x img1e)
(edgedemo img1)


