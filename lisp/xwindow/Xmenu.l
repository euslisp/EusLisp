;;;;
;;; Xmenu.l
;;; (c) 1995 Toshihiro Matsui, Electrotechnical Laboratory

(list "@(#)$Id: Xmenu.l,v 1.1.1.1 2003/11/20 07:46:35 eus Exp $")
(in-package "X")
(require :Xdecl "Xdecl")

(defmethod menu-panel
 (:create (&rest args
           &key (font font-cour12)
		(border-width 2)
                (width 100)
                (color *bisque1*)  ;  Hara extention
           &allow-other-keys)
    (send-super* :create
	:font font :color color
	:height 100 :border-width border-width  :map nil 
	:override-redirect t :event-mask '(:enterleave :configure) args)
    (setq next-x 2
	  next-y 2
	  menu-buttons nil) ; I thought all menu-buttons should be listed
			    ; in this menu-buttons slot, but will substitute
			    ; with subwindows for a while.
    self )
 (:find-button (label)
    (dolist (sw subwindows sw)
	(if (string-equal label (send sw :label))
	    (return sw))))
 (:newsize ()
    (setf width
          (+ 4 (apply #'max (mapcar #'(lambda (x) (send x :width)) items))))
    (setf height  
	(+ 4 (apply #'+ (mapcar #'(lambda (x) (send x :height)) items))))
    (send self :resize width height)
    (mapcar #'(lambda (x) (send x :resize (- width 4) (send x :height))) items)
    self )
 (:create-item (klass label receiver method
			&rest args
			&key (font fontid) (active-Color)
			&allow-other-keys)
     (let  (item)
	(setq item 
	      (instance* klass :create label receiver method
			:state :flat
			:background bg-color
			:font font
			:parent self
		        :event-mask '(:button :enterleave)
			args))
        (send item :active-color
		(get-redish-pixel (xwindow-bg-color item)
				  1.2
				  (send item :colormap)))
	(send self :locate-item item next-x next-y)
	(send self :newsize)
	(setq next-y (- (send self :height) 2) next-x 2)
	item) )
;;  (:menu-button (button)   (setq menu-button button) )
 (:draw-panel ()
    (mapcar #'(lambda (x) (send x :draw-label :flat)) items) )
 (:popup (x y &optional (offset 20))
    (send self :raise)
    (send self :move x y)
    (setq height-offset offset)
    (send self :map)
    (send self :3d-fill-rectangle 0 0 width height 2
		light-edge-color dark-edge-color bg-color
		topleft-edge-polygon :up)
    (mapcar #'(lambda (x) (send x :draw-label :flat)) items)     )
 (:ButtonRelease (event)
	(if (eql *buttonrelease-wanted* self)
	    (setq *buttonrelease-wanted* nil))
;;	(send menu-button :draw-label :flat)
	(send self :unmap) )
 (:MapNotify (event) nil )
)

