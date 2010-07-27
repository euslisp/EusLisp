;;;; tss96.l
;;;  demonstration program for Tsukuba Software Symposium '96
;;;  which exhibits EusLisp's solid modeling, graphics and GUI facilities.
;;;  (c) 1996, Toshihiro Matsui, Electrotechnical Laboratory
;;;

(require :shadow  "lisp/geo/shadow")
(require :render  "lisp/geo/render")
(require :bodyrel  "lisp/geo/bodyrel")
(require :kdraw "lib/llib/kdraw")
(require :pictdraw "lib/llib/pictdraw")


(if (y-or-n-p "load motion constraint modules? ")
    (progn
	(in-package "GEO")
	(require :model2const "contrib/contact/model2constRobust")
	(require :inequalities "contrib/contact/inequalities")
	(require :drawconst "contrib/contact/drawconst")
        (require :projection "contrib/contact/projection")
	(in-package "USER")
    ))


(defvar *check-motion-constraint* nil)
(defvar *check-interference* nil)

;;(send (send *viewsurface* :gc) :line-width 3)


;;;;;;;;;
;; colors for double buffering
;;

(defvar *tss-cmap*)
(defvar *tss-pixels*)

(defvar *tss-color-planes*)
(defvar *tss-base-pixel*)
(defvar *tss-bg* "#e0f4ff")

(defvar *bisque-color*)
(defvar *black-color*)
(defvar *red-color*)
(defvar *blue-color*)

(defvar *clear-gc*)
(defvar *black-gc*)
(defvar *red-gc*)
(defvar *blue-gc*)
(defvar *red-pixel*)
(defvar *green-pixel*)
(defvar *blue-pixel*)
(defvar *bg-pixel*)


(defun set-tss-cmap ()
  (if  (and (null (member :irix *features*))
	    (setq *tss-pixels*
		  (send x:*color-map* :allocate-private-colors 1 4)))
       (setq *tss-cmap* x:*color-map*)
       (progn
	  (setq *tss-cmap* (instance x:colormap :create))
	  (send *tss-cmap* :name '*tss-cmap*)
	  (send *tss-cmap* :copy-colors x:*color-map* 0 60)
	  (setq *tss-pixels* (send *tss-cmap* :allocate-private-colors 1 4))
	  ) )
  (setq *tss-color-planes* (x::colormap-planes *tss-cmap*))
  (setq *tss-base-pixel* (aref (x::colormap-pixels *tss-cmap*) 0))
  (setq *bisque-color*	(instance x:xcolor :init 0 #xff00 #xe400 #xc400))
  (setq *black-color*	(instance x:xcolor :init 0 0 0 0))
  (setq *red-color*	(instance x:xcolor :init 0 #xffff #x1000 #x1000))
  (setq *blue-color*	(instance x:xcolor :init 0 #x1000 #x1000 #xffff))
  ;;
  ;; graphic contexts of differnt colors
  ;;
  (setq *clear-gc*
	(instance x:gcontext :create
		:foreground (logior *tss-base-pixel*)
		:function :copy))

  (setq *black-gc*
	(instance x:gcontext :create
		:foreground (logior *tss-base-pixel* 
				    (aref *tss-color-planes* 0)
				    (aref *tss-color-planes* 2))
		:function :copy))
  (setq *red-gc*
	(instance x:gcontext :create
		:foreground (logior *tss-base-pixel* 
				    (aref *tss-color-planes* 1)
				    (aref *tss-color-planes* 3))
		:function :copy))
  (setq *blue-gc*
	(instance x:gcontext :create
		:foreground (logior *tss-base-pixel* 
				    (aref *tss-color-planes* 0)
				    (aref *tss-color-planes* 1)
				    (aref *tss-color-planes* 2)
				    (aref *tss-color-planes* 3))
		:function :copy))
  (setq *red-pixel* (send *tss-cmap* :alloc "red"))
  (setq *green-pixel* (send *tss-cmap* :alloc "green"))
  (setq *blue-pixel* (send *tss-cmap* :alloc "blue"))
  (setq *bg-pixel* (send *tss-cmap* :alloc x::*bisque1*)) 
)


(defun set-clear-gc (mode)
   (let ((base-pixel-mask
	   (lognot (logior
		(aref *tss-color-planes* 0) (aref *tss-color-planes* 1)
		(aref *tss-color-planes* 2) (aref *tss-color-planes* 3)))) )
   (cond ((evenp mode)
	  (send *clear-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 2)
			 (aref *tss-color-planes* 3))) )
	 ((oddp mode)
	  (send *clear-gc* :planemask
		 (logior base-pixel-mask 
			(aref *tss-color-planes* 0)
			(aref *tss-color-planes* 1))) )
    )) )

(defun set-color-gc (mode)
   (let ((base-pixel-mask
	   (lognot (logior
		(aref *tss-color-planes* 0) (aref *tss-color-planes* 1)
		(aref *tss-color-planes* 2) (aref *tss-color-planes* 3)))) )
   (cond ((evenp mode)
	  (send *black-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 2)
			 (aref *tss-color-planes* 3))) 
	  (send *red-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 2)
			 (aref *tss-color-planes* 3)) )
	  (send *blue-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 2)
			 (aref *tss-color-planes* 3)))  )
	 ((oddp mode)
	  (send *black-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 0)
			 (aref *tss-color-planes* 1)))
	  (send *red-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 0)
			 (aref *tss-color-planes* 1)))
	  (send *blue-gc* :planemask
		 (logior base-pixel-mask
			 (aref *tss-color-planes* 0)
			 (aref *tss-color-planes* 1))) )
	))
  )

(defun set-colors (mode) ;; mode=0 or 1
  (when *tss-pixels*
  (cond ((evenp mode)
	  (send *tss-cmap* :store (elt *tss-pixels* 0) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 4) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 8) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 12) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 1) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 5) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 9) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 13) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 2) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 6) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 10) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 14) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 3) *blue-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 7) *blue-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 11) *blue-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 15) *blue-color*))
        ((oddp mode)
	  (send *tss-cmap* :store (elt *tss-pixels* 0) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 1) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 2) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 3) *bisque-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 4) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 5) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 6) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 7) *black-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 8) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 9) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 10) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 11) *red-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 12) *blue-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 13) *blue-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 14) *blue-color*)
	  (send *tss-cmap* :store (elt *tss-pixels* 15) *blue-color*))
      ) ) )


#+:gl
(progn
  (defvar *num-colors* 8)
  (defvar *red-material*
	  (instance colormaterial :create :name 'red	:diffuse #f(0.9 0.4 0.4)))
  (defvar *yellow-material*
	  (instance colormaterial :create :name 'yellow	:diffuse #f(0.7 0.7 0.4)))
  (defvar *yellow2-material*
	  (instance colormaterial :create :name 'yellow2 :diffuse #f(0.7 0.8 0.4)))
  (defvar *red-yellow-material*
	  (instance colormaterial :create :name 'red-yellow :diffuse #f(0.8 0.7 0.3)))
  (defvar *green-material*
	  (instance colormaterial :create :name 'green	:diffuse #f(0.5 0.9 0.4)))
  (defvar *blue-material*
	  (instance colormaterial :create :name 'blue	:diffuse #f(0.4 0.6 0.95)))
  (defvar *violet-material*
	  (instance colormaterial :create :name 'violet	:diffuse #f(0.8 0.4 0.8)))
  (defvar *gray-material*
	  (instance colormaterial :create :name 'gray	:diffuse #f(0.7 0.7 0.7)))
  )

(defvar *color-names*	;these color-names must match with ones defined by
			;init-colormap in render.l.
	(list  'green 'blue 'red  'yellow 'yellow2 
		'gray 'violet 'red-yellow))
#+:gl
(defvar *color-materials*
	(list *green-material* *blue-material* *red-material*
		*yellow-material* *yellow2-material* *gray-material*
		*violet-material* *red-yellow-material*))

;;;;;

(defun clear-drawable (pm)
   (x::fillrectangle x:*display*
	(send pm :drawable)
	(send *clear-gc* :gc)
	0 0 (x::xdrawable-width pm) (x::xdrawable-height pm)))

;;;;;;;;;;;;;;;;;;;;;;;;;;
;; canvas extention
;;;;;;;;;;;;;;;;;;;;;;;;;;

(defclass 3d-canvas :super x:canvas
	:slots (cmap moving prevpos motion))

(defmethod 3d-canvas
  (:create (&rest args)
     (send-super* :create args)
     (setq cmap (gethash (send self :colormap) x:*xwindows-hash-tab*))
     (setq prevpos #i(0 0))
     self)
  (:buttonpress (evnt)
     (setq x::topleft (x:event-pos evnt)
	   x::bottomright (copy-seq x::topleft))
     (send x::parent :select-model
	 (aref x::topleft 0) (aref x::topleft 1) (x:event-state evnt))
     (setq prevpos x::topleft)
     )
  (:motionNotify (evnt)
 ;;    (send-super :motionNotify evnt) ; don't draw selection rectangle
     (setq moving t)
     (setq x::bottomright (x:event-pos evnt))
     (setq motion (v- x::bottomright prevpos))
     (setq prevpos  x::bottomright)
     (send x::parent
	   (cond ((x:event-left evnt) :move-xy)
		 ((x:event-middle evnt) :move-zz)
		 ((x:event-right evnt) :move-rot) )
	   (elt motion 0) (- (elt motion 1)) )
     )
  (:buttonrelease (evnt)
     (send-super :buttonrelease evnt)
     (setq moving nil)
;     (send x::parent :select-model (aref x::topleft 0) (aref x::topleft 1)
;		(x:event-state evnt))
  )
 (:enterNotify (evnt)   ;;  (send cmap :install)
	)
 (:leaveNotify (evnt)   ;;  (send cmap :uninstall)
	) )

(when (boundp 'glviewsurface)
   (load "lib/demo/tss96gl.l"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TSS main window
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defclass tss-main :super x:panel
	:slots (tss-canvas tss-panel tss-menubar drawpanel
		;; sliders
		slider-x slider-y slider-z arg-x arg-y arg-z
		trans-x trans-y trans-z trans-value
		rot-x rot-y rot-z rot-value
		constraint-tolerance
		;; menu
		file-menu edit-menu opt-menu 
		body-menu coords-menu color-menu
		view-menu draw-menu window-menu
		;;
		models selected-models
		tss-viewer gl-mapped
		world-axes alt-surface gl-surface
		;; mode/state
		draw-mode panel-size body-index
		coords-mode coords-move redraw-count))

(defmethod tss-main
 (:create (&rest args)
    (send-super* :create :width 640 :height 460
	 :event-mask  '(:configure)  
	 :color-map *tss-cmap*
	 :foreground "black"
	 :background *tss-bg* ;"bisque1"
	 ;; :override-redirect t
	 args)
    ;; create menu bar, menu panels and menu items
    (setq tss-menubar
	  (send-super :create-menubar :height 26 :width 640
		:x 1  :y 1
		:color-map *tss-cmap*  :background *tss-bg*))
    ;; file-menu
    (setq file-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
      (send file-menu :create-item x:button-item "load" 
		self :load)
      (send file-menu :create-item x:button-item "save Brep"
		self :save-Brep)
      (send file-menu :create-item x:button-item "save epsf"
		self :save-epsf)
      (send file-menu :create-item x:button-item "save pict"
		self :save-pict)
      (send file-menu :create-item x:button-item "save VRML"
		self :save-VRML)
      (send file-menu :create-item x:button-item "quit"
		self :quit)
      (send tss-menubar :create-item x:menu-button-item
		"File" self  nil :menu file-menu)
    ;; edit-menu
    (setq edit-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
      (send edit-menu :create-item x:button-item "select-all" 
		self :select-all)
      (send edit-menu :create-item x:button-item "delete"
		self :delete-models)
      (send edit-menu :create-item x:button-item "copy"
		self :copy-models)
      (send tss-menubar :create-item x:menu-button-item
		"Edit" self  nil :menu edit-menu)
    ;; opt-menu
    (setq opt-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
      (send opt-menu :create-item x:button-item "print-selection" 
		self :print-selection)
      (send opt-menu :create-item x:button-item "describe"
		self :describe)
      (send opt-menu :create-item x:button-item "constraint on"
		self :toggle-motion-constraint-check)
      (send opt-menu :create-item x:button-item "interference on"
		self :toggle-interference-check)
      (send tss-menubar :create-item x:menu-button-item
		"Option" self  nil :menu opt-menu)
    ;; body-menu
    (setq body-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg* :name 'body-menu))
      (send body-menu :create-item x:button-item "Cube" 
		self :make-cube)
      (send body-menu :create-item x:button-item "Cylinder"
		self :make-cylinder)
      (send body-menu :create-item x:button-item "Cone"
		self :make-cone)
      (send body-menu :create-item x:button-item "Prism"
		self :make-prism)
      (send body-menu :create-item x:button-item "Revolution"
		self :make-revolution)
      (send body-menu :create-item x:button-item "Torus"
		self :make-torus)
      (send body-menu :create-item x:button-item "Union +" 
		self :model-union)
      (send body-menu :create-item x:button-item "Diff -"
		self :model-difference)
      (send body-menu :create-item x:button-item "Intersection *"
		self :model-intersection)
      (send tss-menubar :create-item x:menu-button-item
		"Bodies" self  nil :menu body-menu)
    ;; draw-menu
    (setq draw-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg* :name 'draw-menu))
      (send draw-menu :create-item x:button-item "Draw" self :draw)
      (send draw-menu :create-item x:button-item "Hid" self :hid)
      (send draw-menu :create-item x:button-item "Hid2" self :hid2)
      (send draw-menu :create-item x:button-item "Hidd" self :hidd)
      (send draw-menu :create-item x:button-item "GLdraw" self :gldraw)
      (send draw-menu :create-item x:button-item "RayTrace" self :render)
      (send draw-menu :create-item x:button-item "Clear" self :clear-canvas)
      (send draw-menu :create-item x:button-item "Shadow" self :shadow)
      (send tss-menubar :create-item x:menu-button-item
		"Draw" self  nil :menu draw-menu)
    ;; coords-menu
    (setq coords-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
      (send coords-menu :create-item x:button-item "obj local"
		self (list :coordinates-mode :object :local))
      (send coords-menu :create-item x:button-item "obj world"
		self (list :coordinates-mode :object :world))
      (send coords-menu :create-item x:button-item "obj viewing"
		self (list :coordinates-mode :object :viewing))
      (send coords-menu :create-item x:button-item "eye local"
		self (list :coordinates-mode :viewing :local))
      (send coords-menu :create-item x:button-item "eye world"
		self (list :coordinates-mode :viewing :world))
      (send coords-menu :create-item x:button-item "eye viewing"
		self (list :coordinates-mode :viewing :viewing))
      (send tss-menubar :create-item x:menu-button-item 
		"Coords" self  nil :menu coords-menu)
      (setq coords-move :object
	    coords-mode :viewing)
    ;; color-menu
    (setq color-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
      (send color-menu :create-item x:button-item "red" 
		self (list :model-color "red"))
      (send color-menu :create-item x:button-item "orange"
		self (list :model-color "orange"))
      (send color-menu :create-item x:button-item "yellow"
		self (list :model-color "yellow"))
      (send color-menu :create-item x:button-item "lime" 
		self (list :model-color "lime"))
      (send color-menu :create-item x:button-item "green"
		self (list :model-color "green"))
      (send color-menu :create-item x:button-item "cyan"
		self (list :model-color "cyan"))
      (send color-menu :create-item x:button-item "blue"
		self (list :model-color "blue"))
      (send color-menu :create-item x:button-item "violet"
		self (list :model-color "violet"))
      (send color-menu :create-item x:button-item "mazenta"
		self (list :model-color "mazenta"))
      (send tss-menubar :create-item x:menu-button-item 
		"Color" self  nil :menu color-menu)
    ;; view menu
    (setq view-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
      (send view-menu :create-item x:button-item "wider 25%" 
		self (list :zoom-view 0.75))
      (send view-menu :create-item x:button-item "wider 10%" 
		self (list :zoom-view 0.9))
      (send view-menu :create-item x:button-item "narrower 10%"
		self (list :zoom-view 1.1))
      (send view-menu :create-item x:button-item "narrower 25%"
		self (list :zoom-view 1.25))
      (send view-menu :create-item x:button-item "reset-viewing"
		self :reset-viewing)
      (send tss-menubar :create-item x:menu-button-item 
		"Viewing" self  nil :menu view-menu)
    ;; window menu
    (setq window-menu (instance x:menu-panel :create :color-map *tss-cmap*
			:background *tss-bg*))
	(send window-menu :create-item x:button-item "2D-draw"
		self :2d-draw)
      (send tss-menubar :create-item x:menu-button-item 
		"Window" self  nil :menu window-menu)
    ;;
    ;; make panel and viewsurfaces
    ;;
    (setq tss-panel (instance x:panel :create
		 :width 200 :height 430 :x 1 :y 30 :parent self
		 :background *tss-bg*
		 :color-map *tss-cmap*))
    (setq tss-canvas
	  (instance 3d-canvas :create
		:width 430  :height 430
		:parent self :x 204 :y 30
		:color-map *tss-cmap*
	        :event-mask '(:button :motion :enterleave)
		;; :override-redirect t
		))
    (setq panel-size
	  (list  (send tss-panel :width)
		 (send tss-panel :height)))
;    (setq alt-surface
;	 (instance x:xpixmap :create :width 430 :height 440))
    (when (boundp 'glviewsurface)
	(setq gl-surface
	      (if (member :irix *features*)
		  ;; IRIX (SGI) does not allow to associate colormap to gl-viewsurface
	      (instance gl-canvas :create
			:width 430 :height 430
			:parent self :x 204 :y 30
			:event-mask '(:button :motion :enterleave))
	      (instance gl-canvas :create
			:width 430 :height 430
			:parent self :x 204 :y 30
			:color-map *tss-cmap*
			:event-mask '(:button :motion :enterleave))
		))
	(send gl-surface :unmap))
;    (send tss-canvas :line-width 2)
;    (send alt-surface :line-width 2)
    (setq world-axes (instance coordinates-axes :init 1000))
    (setq trans-value (float-vector 0 0 0))
    (setq rot-value (float-vector 0 0 0))
    (setq tss-viewer
	  (view :viewsurface tss-canvas
		:width 430  :height 430
		:screen-x 1.0
		:screen-y (/ 430.0 430.0)
		:viewpoint #f(2000 1200 900)
		:target #f(0 0 0)
		:hither 100.0
		:yon 10000.0
		:screen 1.0
		:viewdistance 3.0
		:name 'TSS96))
    ;;
    ;; make buttons
;;    (setq quit-button (send tss-panel :create-item x:button-item
;;				"quit" self :quit)
;	  draw-mode-choice 
;		(send tss-panel :create-item x:choice-item
;			"draw-mode" self :draw-mode
;			:choices (list "wire " " hid " " hidd " " gl " " render ")
;			:button-size 10 :border-width 1))
   (setq
	  slider-x 
		(send tss-panel :create-item x:slider-item
			"x " self :arg-x
			:max 1000.0 :max-label "1000 " :min-label "0"
			:value-format "~3,0f"
			:initial-value (setq arg-x 300.0)
			:font x:font-cour10)
	  slider-y
		(send tss-panel :create-item x:slider-item
			"y " self :arg-y
			:max 1000.0 :max-label "1000 " :min-label "0"
			:value-format "~3,0f"
			:initial-value (setq arg-y 300.0)
			:font x:font-cour10)
	  slider-z
		(send tss-panel :create-item x:slider-item
			"z " self :arg-z
			:max 1000.0 :max-label "1000 " :min-label "0"
			:value-format "~3,0f"
			:initial-value (setq arg-z 300.0) 
			:font x:font-cour10) )
;; (warning-message 1 "creating trans-xyz~%")
    (setq
	  trans-x (send tss-panel :create-item x:slider-item
			"Tx " self :trans-x
			:max 1000.0 :min -1000.0 :span 80
			:value-format "~3,0f"
			:initial-value 0.0
			:font x:font-cour10)
	  trans-y (send tss-panel :create-item x:slider-item
			"Ty " self :trans-y
			:max 1000.0 :min -1000.0  :span 80
			:value-format "~3,0f"
			:initial-value 0.0
			:font x:font-cour10)
	  trans-z (send tss-panel :create-item x:slider-item
			"Tz " self :trans-z
			:max 1000.0 :min -1000.0 :span 80
			:value-format "~3,0f"
			:initial-value 0.0
			:font x:font-cour10) )
;; (warning-message 1 "creating rot-xyz~%")
    (setq
	  rot-x (send tss-panel :create-item x:slider-item
			"Rx " self :rot-x
			:max pi :min -pi  :min-label "-pi"
			:value-format "~4,2f" :span 80
			:initial-value 0.0
			:font x:font-cour10)
	  rot-y	(send tss-panel :create-item x:slider-item
			"Ry " self :rot-y
			:max pi :min -pi  :min-label "-pi"
			:value-format "~4,2f"  :span 80
			:initial-value 0.0
			:font x:font-cour10)
	  rot-z	(send tss-panel :create-item x:slider-item
			"Rz " self :rot-z
			:max pi :min -pi :min-label "-pi"
			:value-format "~4,2f" :span 80
			:initial-value 0.0
			:font x:font-cour10) )
    (setq constraint-tolerance
	  (send tss-panel :create-item x:slider-item
			"tol " self :constraint-tolerance
			:max 100.0 :min 0  :min-label "0"
			:value-format "~4,2f"
			:initial-value 10.0
			:font x:font-cour10) )
    (setq body-index 0
	  redraw-count 0)
    self)
 (:configureNotify (event)
   (let ((newwidth (send self :width)) 
	 (newheight (send self :height)))
	(when (or (/= newwidth x::width) (/= newheight x::height))
	 ;; (format t
	 ;; "(~d ~d) --> (~d ~d)~%" x::width x::height newwidth newheight)
	  (send self :resize newwidth newheight))) )
 (:resize (newwidth newheight)
    (setq newwidth (- newwidth (first panel-size)))
    (send tss-viewer :resize newwidth newheight)
    (send tss-canvas :resize newwidth newheight)
;    (send alt-surface :destroy)
;    (setq alt-surface 
;	  (instance  x::xpixmap :create
;		 :width newwidth :height newheight))
;    (send alt-surface :line-width 2)
    ;; resize gl-surface
    (when gl-surface
       (send gl-surface :width newwidth)
       (send gl-surface :height newheight)
       (send gl-surface :3d-mode))
    (send self :redraw))
 )

(defmethod tss-main	;drawing methods
 (:clear-canvas (e)
     (send tss-canvas :clear)
;     (send tss-canvas :foreground *blue-pixel*)
     (draw tss-viewer world-axes))
 (:redraw () 
    (cond (gl-mapped (gldraw tss-viewer models))
	  (t 	     
	      (set-clear-gc redraw-count)
	      (clear-drawable tss-canvas)
	      (set-color-gc redraw-count)
	      (case draw-mode
		(draw (draw tss-viewer models))
		(wire (dolist (m models) 
		          (draw tss-viewer (send m :all-edges))))
		(hid (hid tss-viewer models))
		(hidd (hidd tss-viewer models))
		(hid2 (dolist (m models) (hid tss-viewer m)))
		(t (draw tss-viewer models)))
	      (incf redraw-count)
	      (set-colors  redraw-count)
	    )
	)) 
 (:unmap-gl () 
    (when gl-mapped
	(send gl-surface :unmap)
	(send tss-canvas :map) 
	(setq gl-mapped nil)
	(setf (geo::viewer-surface tss-viewer) tss-canvas)
	))
 (:map-gl () 
    (unless gl-mapped
	(send tss-canvas :unmap) 
	(send gl-surface :map)
	(setq gl-mapped t)
	(setf (geo::viewer-surface tss-viewer) gl-surface)
	))
 (:draw (event)
     (send self :unmap-gl)
     (setq draw-mode 'draw)
     (send self :redraw))
 (:hid (event)
     (send self :unmap-gl)
     (setq draw-mode 'hid)
     (send self :redraw))
 (:hid2 (event)
     (send self :unmap-gl)
     (setq draw-mode 'hid2)
     (send self :redraw))
 (:hidd (event)
     (send self :unmap-gl)
     (setq draw-mode 'hidd)
     (send self :redraw))
 (:gldraw (event)
     (send self :map-gl)
     (gldraw tss-viewer models))
 (:render (event)
    (let ((pid (unix:fork)))
       (cond ((< pid 0) (error "cannot fork render"))
	     ((= pid 0) (return-from :render t))
	     (t ;; child's execution begins
		(x::init-xwindow)	; x connection cannot be shared
		(close *standard-output*)
	        (setq *standard-output* (open "/dev/null" :direction :output))
		(setf (io-stream-outstream *terminal-io*) *standard-output*)
		(instance render-panel :create models)
		(x:window-main-loop)
		(exit 0)) )) ))

(defmethod tss-main	;;mode/state
 (:coordinates-mode (c mode)	;wrt = :local, :world or :viewing
    (setq coords-move c)
    (setq coords-mode mode))
 (:toggle-motion-constraint-check (item)
    (send item :label (format nil "constraint ~a"
				(if *check-motion-constraint* "on" "off")))
    (setq *check-motion-constraint* (null *check-motion-constraint*)))
 (:toggle-interference-check (item)
    (send item :label (format nil "interference ~a"
				(if *check-motion-constraint* "on" "off")))
    (setq *check-interference* (null *check-interference*)))
 )

(defmethod tss-main	; parameters 
 (:arg-x (item val) (setq arg-x val))
 (:arg-y (item val) (setq arg-y val))
 (:arg-z (item val) (setq arg-z val))
 (:trans-models () (send-all selected-models :locate trans-value :world)
	(send self :redraw))
 (:trans-x (item val) (setf (aref trans-value 0) val) (send self :trans-models))
 (:trans-y (item val) (setf (aref trans-value 1) val) (send self :trans-models))
 (:trans-Z (item val) (setf (aref trans-value 2) val) (send self :trans-models))
 (:rot-redraw ()
	(send-all selected-models :rpy
		(elt rot-value 0) (elt rot-value 1) (elt rot-value 2))
	(send self :redraw))
 (:rot-x (item val)
     (setf (elt rot-value 2) val)
     (send self :rot-redraw))
 (:rot-y (item val)
     (setf (elt rot-value 1) val)
     (send self :rot-redraw))
 (:rot-Z (item val)
     (setf (elt rot-value 0) val)
     (send self :rot-redraw))
 (:constraint-tolerance (item val)
     )
 (:scale-by-viewing (fv)
     (let* ((vc (send tss-viewer :viewing))
	    (m (first selected-models))
	    (dist  (distance (send vc :viewpoint) (car (geo::faceset-vertices m))))
	    (screen (geo::perspective-viewing-screenx vc))
	    (vdist  (send vc :viewdistance))
	    (cansize (x::xwindow-width tss-canvas))
	    scaler)
	(setq scaler %((2.0 *  dist * screen) / (vdist * cansize)))
	(scale scaler fv fv))
	)
 (:move-xy (x y) 
     (cond ((eql coords-move :object) (send self :move-model-xy x y))
	   ((eql coords-move :viewing) (send self :move-viewing-xy x y))))
 (:move-zz (x y)
     (cond ((eql coords-move :object) (send self :move-model-zz x y))
	   ((eql coords-move :viewing) (send self :move-viewing-zz x y))))
 (:move-rot (x y)
     (cond ((eql coords-move :object) (send self :move-model-rot x y))
	   ((eql coords-move :viewing) (send self :move-viewing-rot x y))))
 (:move-model (disp rots wrt)
     (if disp (send-all selected-models :translate disp wrt))
     (dolist (r rots)
        (send-all selected-models :rotate (first r) (second r) wrt))
     ;;
     ;; check motion constraints
     (cond ((and *check-motion-constraint* selected-models)
          (let* ((motion-6d (make-array 6 :element-type float-vector))
                 motion-6dp const-1 ccc
                 (geo:*contact-threshold* (send constraint-tolerance :value))
                  constraints c (m1 (car selected-models)) m)
            (replace motion-6d (v- (send wrt :transform-vector disp)
				   (send wrt :transform-vector #f(0 0 0))))
            ;;(format t "motion-6d=~s~%" motion-6d)
            (dolist (m2 models)
              (unless (eql m1 m2)
	        (if (setq const-1 (send m1 :constraint m2))
	            (push const-1 c))
                ;;(setq f (geo::constrained-force m))
                ))
            (when c (setq m (geo::constrained-motion  c)))
            (cond ((and c m)
	              ;; (format t "constraint: ~s ~s~%" c m)
		      (format t "disp: ~s ~s~%" disp motion-6d)
	              (setq mm motion-6d cc c)
	              (setq motion-6dp (possible-motion motion-6d  c))
	              (format t "possible-motion: ~s ~%" motion-6dp)
	              (setq motion-6d (v- motion-6dp motion-6d))
	              (if disp
			  (send-all selected-models :translate 
	                            (subseq motion-6d 0 3) wrt))
	              (send self :redraw)
	              (dolist (cc c)
			 (setq ccc (geo::constraint-relation-constraints  cc))
	                 (send-all ccc :draw-constraint tss-viewer 50 *blue-gc*)
			))
                  (t (send self :redraw)))
                   )  )
	   (t  (send self :redraw))) )
 (:move-model-xy (x y)
    (when selected-models
      (let* ((wrt coords-mode)
	    (displacement
		(send self :scale-by-viewing (float-vector x y 0))) )
	(if  (eql coords-mode :viewing)
	     (setq wrt (send tss-viewer :viewing))  )
	(send self :move-model displacement nil wrt))))
 (:move-model-zz (rotz z)
    (when selected-models
      (let ((wrt coords-mode) 
	    (displacement 
		(send self :scale-by-viewing (float-vector 0 0 (- z)))) )
	(if (eql coords-mode :viewing)
	    (setq wrt (send tss-viewer :viewing)))
	(send self :move-model displacement
				(list (list (/ rotz 60.0) :z)) wrt)
    )	) )
 (:move-model-rot (rotx roty)
    (when selected-models
      (let ((wrt coords-mode) )
	(if (eql coords-mode :viewing)
	    (setq wrt (send tss-viewer :viewing)))
	(send self :move-model nil
		 (list (list (/ rotx 60.0) :x) (list (/ roty 60.0) :y))  wrt)
    )	) )
 (:move-viewing-xy (x y)
    (let* ((wrt coords-mode) (vc (send tss-viewer :viewing))
	   (displacement
		; (send self :scale-by-viewing (float-vector x y 0))
		(scale 2.0 (float-vector x y 0)) ) )
	(if  (eql coords-mode :viewing)
	     (setq wrt vc))
	(send vc :translate displacement wrt)
	(send self :redraw)
	) )
 (:move-viewing-zz (rotz z)
    (let* ((wrt coords-mode) (vc (send tss-viewer :viewing))
	     (displacement
		;(send self :scale-by-viewing (float-vector 0 0 z))
		(scale 2.0 (float-vector 0 0 z))) )
	(if  (eql coords-mode :viewing)
	     (setq wrt vc))
	(send vc :translate displacement wrt)
	(send vc :rotate (/ rotz 60.0) :z wrt)
	(send self :redraw)
	) )
 (:move-viewing-rot (rotx roty)
    (let* ((wrt coords-mode) (vc (send tss-viewer :viewing)))
	(if  (eql coords-mode :viewing)
	     (setq wrt vc))
	(send vc :rotate (/ rotx 60.0) :x wrt)
	(send vc :rotate (/ roty 60.0) :y wrt)
	(send self :redraw)
	) )
 )

(defmethod tss-main	;viewing transformation
 (:zoom-view (ratio)
    (send tss-viewer :viewing :zoom ratio)
    (send self :redraw))
 (:reset-viewing (arg)
    (send tss-viewer :viewing :look (float-vector 2000 1200 900)
				    (float-vector 0 0 0))
    (send tss-viewer :screen 1.0 (/ (send tss-canvas :width)
				    (send tss-canvas :height)))
    (send tss-viewer :viewdistance 3.0)
    (send self :redraw))
)

(defmethod tss-main	;primitive creation
 (:model (&optional (n))
    (cond ((numberp n) (elt models n))
	  ((null n) models)
	  ((consp n) (setq models n))) )
 (:add-new-model (m)
    (let (c)
	(send self :unselect-models)
	(setq selected-models (list m))
	(push m models) 
	(incf body-index)
	;; assign a symbolic name
	  (cond ((derivedp m body)
		 (send m :name
		   (format nil "~a~d"
			(symbol-name (car (send m :body-type)))
			body-index) ) 
		 (setq c (instance coordinates-axes :init 100))
		 (send m :assoc c) )
		 )
        ;; assign color sequentially
;	(send m :color (elt *color-names* (mod (1- body-index) *num-colors*)))
#+:gl
	(setf (get m :gl-material)
	      (elt *color-materials* (mod (1- body-index) *num-colors*)))
	(send m :color *red-gc*)
	(send self :redraw)) )
 (:delete-models (e)
     (setq models (set-difference models selected-models))
     (setq selected-models nil)
     (send self :clear-canvas e)
     (draw tss-viewer models))
 (:copy-models (e) nil)
 (:make-cube (e)
    (send self :add-new-model (make-cube arg-x arg-y arg-z)))
 (:make-cylinder (e)
    (send self :add-new-model (make-cylinder arg-x arg-z)))
 (:make-cone (e)
    (send self :add-new-model (make-cone (float-vector 0 0 arg-z) arg-x)))
 (:make-prism (e)
    (let ((m (car selected-models)))
      (when (and m (= 1 (length (send m :faces))))
	(let ((fac (copy-object (send m :face 0))) newmodel)
	   (if (> (v. #f(0 0 1) (send fac :normal)) 0.0)
	       (send fac :invert))
	   (setq  newmodel 
		  (make-prism (cdr (send fac :vertices)) arg-z))
	   (send self :unselect-models)
	   (send self :add-new-model newmodel))) )
 )
 (:make-revolution (e) )
 (:make-torus (e) )
)

(defmethod tss-main	;model composition +/-/*
 (:model-union (e) 
    (let (new-model)
       (setq new-model (apply #'body+ selected-models))
       (send self :delete-models e)
       (send self :add-new-model new-model) ) )
 (:model-difference (e)
    (let (new-model)
       (setq new-model (apply #'body- selected-models))
       (send self :delete-models e)
       (send self :add-new-model new-model) ) )
 (:model-intersection (e)
    (let (new-model)
       (setq new-model (apply #'body* selected-models))
       (send self :delete-models e)
       (send self :add-new-model new-model) ) )
)

(defmethod tss-main	;options
 (:shadow (evnt)
    (let (shadow)
       (setq shadow (project-shadow (car selected-models) *hit-face*))
	(print shadow)
	(dolist (e (send shadow :edges))
	     (send tss-viewer :draw-edge e)) ) )
 (:unselect-models ()
    (send-all selected-models :color *black-gc*)
    (setq selected-models nil))
 (:copy-models (e)
    (dolist (m selected-models)
	(let ((copy (copy-object m)))
	  (send copy :translate #f(100 100 0) :world)
	  (send self :add-new-model copy))))
 (:print-selection (e)
    (let ((sout (make-string-output-stream)) tview)
        (pprint selected-models sout)
	(setq tview (instance x:textviewpanel :create
			:width 330 :height 200 :font x::font-cour10))
	(send (x::textviewpanel-view-window tview)
		 :display-line-string (get-output-stream-string sout))))
 (:describe (e)
    (let ((sout (make-string-output-stream)) tview)
        (describe-list selected-models sout)
	(setq tview (instance x:textviewpanel :create
			:width 330 :height 250 :font x::font-cour10))
	(send (x::textviewpanel-view-window tview)
		 :display-line-string (get-output-stream-string sout))))
 (:select-all (e)
    (setq selected-models (copy-seq models))
    (send-all selected-models :color *red-gc*)
    (send self :redraw))
 (:select-model (x y state)
    (let* ((3d-vertices) (old-selection (copy-seq selected-models))
	   (min-corner) (max-corner)
	   (points) pos rot new-selection)
	(setq new-selection (models-hit-by-ray tss-viewer x y models))
        (if (member :shift state)
	     (dolist (m (nreverse new-selection))
		(unless (member m selected-models)
		    (setq selected-models (nconc selected-models (list m)))))
	    (setq selected-models new-selection))
	(print (send-all selected-models :name))
	(when selected-models
		(setq trans-value (send (car selected-models) :worldpos))
		(setq rot-value (car (send (car selected-models) :rpy-angle)))
		(send trans-x :value (aref trans-value 0))
		(send trans-y :value (aref trans-value 1))
		(send trans-z :value (aref trans-value 2))
		(send rot-x :value (elt rot-value 0))
		(send rot-y :value (elt rot-value 1))
		(send rot-z :value (elt rot-value 2)))
	(dolist (m models)
	   (if (member m selected-models)
		(send m :color *red-gc*)
		(send m :color *black-gc*)))
	(if (set-exclusive-or selected-models old-selection)
	    (send self :redraw))
  ))
)

(defmethod tss-main	;file handling
 (:load-ok (fname mode)
    (when fname
      (case mode 
	(:load-Brep
	    (let (sexp m (eof (cons nil nil)))
	        (with-open-file (f fname)
		   (while (not (eql (setq sexp (read f nil eof)) eof))
			(setq m (eval (third sexp)))
			(if (and (derivedp m faceset)
				 (null (send (send m :face 0) :body)) )
			    (send-all (send m :faces) :body m))
			(send self :add-new-model m)))))
	)
      (send self :redraw) ) )
 (:load (event)
    (instance x:fileDialog :create
	:ok-notify (list self :load-ok :load-Brep)) )
 (:save-ok (fname mode)
    (when fname
      (case mode 
	(:save-Brep
	        (with-open-file (f fname :direction :output)
	          (let ((*print-object* t) (*print-circle* t)
			(*print-level* nil) (*print-length* nil))
		    (dolist (m models)
			(print `(setq ,(send m :name) ',m) f)))))
	(:save-pict
		(print "save in pict format~%")
		(with-pict-viewsurface (tss-viewer fname)
			(send self :redraw) ))
	(:save-epsf
		(print "save in epsf format~%")
		(kdraw fname ))
	(:save-VRML
		(print "save in VRML format~%")
		(toiv fname ))
    )))
 (:save-Brep (event)
    (instance x:fileDialog :create
	:ok-notify (list self :save-ok :save-Brep))
    )
 (:save-pict (event)
    (instance x:fileDialog :create
	:ok-notify (list self :save-ok :save-pict))
    )
 (:save-epsf (event)
    (instance x:fileDialog :create
	:ok-notify (list self :save-ok :save-epsf))
    )
 (:save-VRML (event)
    (instance x:fileDialog :create
	:ok-notify (list self :save-ok :save-VRML))
    )
 )

(defmethod tss-main	;file handling
 (:2d-draw-ok (pgon)
    (when pgon
      (setq pgon (copy-object (first pgon)))
      (send self :unselect-models)
      (send self :add-new-model pgon) )
    )
 (:2d-draw (event)
     (require :eusdraw "eusdraw.l")
     (cond (drawpanel (send drawpanel :raise) (send drawpanel :map))
	   (t (setq drawpanel
		    (instance draw-panel :create
			 :ok-notify (list self :2d-draw-ok)))) )
     )
  )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; rendering by ray-tracing
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defclass render-panel :super x:panel
	:slots (models selected-models 
		render-viewer render-canvas render-cmap)
	)
(defmethod render-panel
 (:create (m &rest args)
    (send-super* :create  :width 400 :height 340
	 :event-mask  '(:configure) args)
    (setq render-canvas
	  (instance 3d-canvas :create :width 400 :height 300
		:x 5 :y 38 :parent self) )
    (setq render-viewer
	  (view :viewsurface render-canvas
		:width 400  :height 300
		:screen-x 1.0  :screen-y (/ 300.0 400.0)
		:viewpoint #f(2000 1200 900)
		:target #f(0 0 0)
		:hither 100.0
		:yon 10000.0
		:screen 1.0
		:viewdistance 3.0
		:name 'TSS96-RENDER))
    (setq render-cmap (instance x:colormap :create))
    (send render-cmap :copy-colors x:*color-map* 0 32)
    (init-colormap render-cmap) ;; allocate colors for rendering
    (send render-canvas :set-colormap render-cmap)
    (send self :set-colormap render-cmap)
    (setq models (reverse m))
    ;; assign colors
    (dotimes (i (length models))
	(send (elt models i) :color (elt *color-names* (mod i *num-colors*))) )
#+:gl
    (dolist (model models)	;match with gl color
	(send model :color (send (get model :gl-material) :name)))
    (send self :create-item x:button-item "quit" self :quit)
    (send self :create-item x:button-item "redraw" self :redraw)
    (send self :create-item x:button-item "change-color" self :change-color)
    ;; window set-up finished
    (send self :redraw t)
    self)
 (:change-color (e)
    (dolist (m models)
	(let ((cname (send m :color)) next-color)
	   (setq next-color (cadr (member cname *color-names*)))
	   (unless next-color (setq next-color (car *color-names*)))
	   (send m :color next-color) ))
    (send self :redraw e)) 
 (:redraw (e)
    (cls render-viewer)
    (render :bodies models :viewer render-viewer))
 (:configureNotify (event)
   (let ((newwidth (send self :width)) 
	 (newheight (send self :height)))
	(when (or (/= newwidth x::width) (/= newheight x::height))
	 ;; (format t "(~d ~d) --> (~d ~d)~%" x::width x::height newwidth newheight)
	  (send self :resize newwidth newheight))) )
 (:resize (newwidth newheight)
    (setq newheight (- newheight 40))
    (send render-viewer :resize newwidth newheight)
    (send self :redraw t))
 (:select-model (x y state)
    nil ; do nothing in render-panel
    )    
 )


(defun models-hit-by-ray (vwr x y models)
   (let (ndc u v  ray r hit-faces (vp (send vwr :viewing :viewpoint)) f
	 (hit-dist -100000000.0))
      (setq ndc (send vwr :viewport :screen-point-to-ndc (float-vector x y 0)))
      (setq u (aref ndc 0) v (aref ndc 1))
      (setq ray (send vwr :viewing :ray u v))
      (dolist (m models)
	 (dolist (f (if (derivedp m faceset) (send m :faces) (list  m)))
	    (when (eql (car (send f :intersect-point-vector vp ray))
		     :inside)
		(pushnew m r)
		(push f hit-faces)
		))
	 ) ;first dolist
       (dolist (f hit-faces)
	  (when (> (send f :distance vp) hit-dist)
	      (setq *hit-face* f)
	      (setq hit-dist (send f :distance vp))))
       r)
)


#|
(setq x (make-prism '(#f(50 50 0) #f(50 -50 0) #f(-50 -50 0) #f(-50 50 0))
		    #f(0 0 200)))
(setq x1 (copy-object x))
(send x1 :translate #f(0 0 -100))
(send x1 :worldcoords)

(setq a1 (make-prism '(#f(100 100 -150) #f(100 -100 -150)
		       #f(-100 -100 -150) #f(-100 100 -150))
		     #f(0 0 150)))
(setq ana (body- a1 x1))

(send x :translate #f(0 -18.30127 -18.30127))
(send x :rotate -0.523599 :x)
(send x :worldcoords)

|#

#|
(setq c (list (send x :constraint ana)))
(setq m (constrained-motion c))
(setq f (constrained-force m))

(hidd x ana)

(dolist (cc (geo::constraint-relation-constraints (car c)))
   (send cc :draw-constraint (tss . tss-viewer) 30))
;(send-all c :draw-constraint *viewer* c)
|#




(defvar tss)

(defun tss ()
   (set-tss-cmap)
   (setq tss (instance tss-main :create)))

(defun demo ()
   (x:window-main-loop))

(defun demo (n)
   (let ((can (tss . tss-canvas)))
      (dotimes (i n)
	 (send can :background i) (xflush)
	 (if (= (mod i 100) 0) (print i)))))


;(progn (tss) (demo))

