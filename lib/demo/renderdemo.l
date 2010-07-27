;; renderdemo.l
;; (c) 1992, Toshihiro Matsui and Electrotechnical Laboratory

;; load this file from eusx.
;; 8-bit pseudo color visual is required.

;; create a xwindow

(load "demo/view")
(send *viewer* :resize 512 512)

;; render should have been compiled

(load "geo/render")

;; define objects to be drawn

(setq a (make-cube 500 300 250 :pos #f(0 0 150.)))
(send a :color 'red)

(setq b (make-cylinder 80 400 :pos #f(100 250 0)))
(send b :color 'yellow)

(setq c (make-cube 1000 1000 20 :pos #f(0 0 -10)))
(send c :color 'green)

(setq d (make-cube 100 100 50))
(setq d2 (make-cube 40 100 50))
(send d2 :translate #f(0 0 50))
(send d :+ d2)
(send d :rotate #d70 :z)
(send d :locate #f(300 300 25) :world)
(send d :color 'blue)

(send-all (list a b c d) :worldcoords)

;; define colors in *render-colormap*

(setq *render-brightness-levels* 32)

(send x:*color-map* :define-hls-lut
		'red
		*render-brightness-levels*	;levels
		0	;hue 
	        0.4	;dark
		0.9	;bright
		0.6	;saturation
		nil)	;shared

(send x:*color-map* :define-hls-lut
		'yellow
		*render-brightness-levels*	;levels
		50	;hue 
	        0.3	;dark
		0.9	;bright
		0.7	;saturation
		nil)	;shared

(send x:*color-map* :define-hls-lut
		'green
		*render-brightness-levels*	;levels
		150	;hue 
	        0.3	;dark
		0.9	;bright
		0.6	;saturation
		nil)	;shared

(send x:*color-map* :define-hls-lut
		'blue
		*render-brightness-levels*	;levels
		230	;hue 
	        0.3	;dark
		0.9	;bright
		0.6	;saturation
		nil)	;shared

(setq *light-sources* 
      (list (make-light-source #f(600 200 1000) 1.8)
	    (make-light-source #f(-400 1000 700) 2.0)))

;; do rendering

(render :bodies (list a b c d)
	:viewer *viewer*
	:colormap x:*color-map*
	:lights *light-sources*)

