;;; euslisp demo
;; open a window

(load "demo/view.l")

;; draw a line
(send *viewsurface* :line 10 20 100 400)

;; draw an arc, x, y, width, height, ang1, ang2
(send *viewsurface* :arc 100 100 100 100 0 2pi)
(send *viewsurface* :fill-rectangle 200 200 50 100)

(xflush)

(cls)

;; make a cube and a cylinder, and combine them
(setq cub1 (make-cube 500 400 300))
(setq cyl1 (make-cylinder 100 100))
(send cyl1 :translate #f(0 0 150))
(setq com1 (body+ cub1 cyl1))
(draw com1)
(send com1 :color 9)
(hid com1)

;;
(load "llib/animation")
#|(setq anim1
   (hid-lines-animation 30
       (send com1 :translate #f(10 0 0))
       (send com1 :rotate -0.1 :x)
       (hid com1)))
(playback-hid-lines anim1)
|#

;; try to build a more complicated solid model

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

(setq part1 (make-part1))
(draw part1)

;;
;; load and display the eta3 manipulator model

(load "robot/eta3/eta3build")
(cls)
(send *viewing* :look #f(2000 1500 1000) #f(400 0 200))
(send-all (manipulator-components eta3) :color 1)
(send eta3 :park)
(send eta3 :locate #f(600 0 300) :world)
(send eta3 :orient 0 :y :world)
(send eta3 :locate #f(700 -100 100) :world)
(hid eta3)

;;;
;;; ray tracing
;;;

(if (y-or-n-p "render? ")
    (load "demo/renderdemo.l")
    (format t "rendering skipped~%") )

;;
;; edge vision
;; 
; switch to the "IMAGE" package
(in-package "IMAGE")
(load-library "vision/libeusimg.so")
;; set up color palette
(make-colors  t)
(send *viewsurface* :resize 512 480)
(setq block0img (read-pnm-file "vision/images/block0.pgm"))
(setq *red-gc* (x::make-color-gc "red"))
(setq *green-gc* (x::make-color-gc "green"))
(setq *blue-gc* (x::make-color-gc "blue"))
(setq *yellow-gc* (x::make-color-gc "yellow"))
(setq *cyan-gc* (x::make-color-gc "cyan"))

(send block0img :xpicture)
(send block0img :display)

;; extract regions, boundaries, segments; draw segments
(init-step2 line-edge-segment curved-edge-segment boundary region)
(setq rbs (edge12 block0img) s (third rbs))
(draw-segments s)

;;
;; GUI window
;; button-driven help window
;;

(in-package "X")
(load "xwindow/Xhelp.l")
(setq hp (instance HelpPanel :create))
(window-main-loop)


