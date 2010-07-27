(load "demo/view")
(load "robot/eta3/eta3build.l")
(require :animation "llib/animation")

(send *viewing* :look #f(3000 2000 1000) #f(200 0 200))
(send *viewing* :view-angle 0.5)

(send eta3 :park)
(send eta3 :locate #f(600 200 500) :world)
(send eta3 :rotate 1.57  :y)

(draw eta3)

(defun move-eta3 (h)
   (send eta3 :translate (float-vector 0 h (- h)))
   (send eta3 :rotate -0.1 :y)
   (cls)
   (hid eta3))

(format t "generating 20 hid images: wait for 300/mips minutes.~%")
(setq eta3anim (hid-lines-animation 20 (move-eta3 15)))
(format t "drawing finished.~%")

(loop 
   (if (y-or-n-p "playback ")
	(playback-hid-lines eta3anim)
	(return nil)))

